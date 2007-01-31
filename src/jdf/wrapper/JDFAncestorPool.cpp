/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
* Processes in  Prepress, Press and Postpress (CIP4).  All rights 
* reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer. 
*
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*
* 3. The end-user documentation included with the redistribution,
*    if any, must include the following acknowledgment:  
*       "This product includes software developed by the
*        The International Cooperation for the Integration of 
*        Processes in  Prepress, Press and Postpress (www.cip4.org)"
*    Alternately, this acknowledgment may appear in the software itself,
*    if and wherever such third-party acknowledgments normally appear.
*
* 4. The names "CIP4" and "The International Cooperation for the Integration of 
*    Processes in  Prepress, Press and Postpress" must
*    not be used to endorse or promote products derived from this
*    software without prior written permission. For written 
*    permission, please contact info@cip4.org.
*
* 5. Products derived from this software may not be called "CIP4",
*    nor may "CIP4" appear in their name, without prior written
*    permission of the CIP4 organization
*
* Usage of this software in commercial products is subject to restrictions. For
* details please consult info@cip4.org.
*
* THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESSED OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED.  IN NO EVENT SHALL THE INTERNATIONAL COOPERATION FOR
* THE INTEGRATION OF PROCESSES IN PREPRESS, PRESS AND POSTPRESS OR
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
* USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
* ====================================================================
*
* This software consists of voluntary contributions made by many
* individuals on behalf of the The International Cooperation for the Integration 
* of Processes in Prepress, Press and Postpress and was
* originally based on software 
* copyright (c) 1999-2001, Heidelberger Druckmaschinen AG 
* copyright (c) 1999-2001, Agfa-Gevaert N.V. 
*  
* For more information on The International Cooperation for the 
* Integration of Processes in  Prepress, Press and Postpress , please see
* <http://www.cip4.org/>.
*  
* 
*/

//EndCopyRight
/*
*
*
* COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
*      ALL RIGHTS RESERVED 
*
*  Author: Dr. Rainer Prosi using JDFSchema code generator 
* 
* Warning! very preliminary test version. Interface subject to change without prior notice!
* Revision history:
* created 2001-07-11
*
*/

#include "JDFAncestorPool.h"
#include "JDFAncestor.h"
#include "JDFPart.h"
#include "JDFNode.h"
#include "JDFNodeInfo.h"
#include "JDFCustomerInfo.h"
#include "JDFRefElement.h"
#include "JDFResourcePool.h"

namespace JDF{
	///////////////////////////////////////////////////////////////////////

	JDFAncestorPool &JDFAncestorPool::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFAncestorPool: "+other.GetNodeName()); 
		return *this;
	};

	///////////////////////////////////////////////////////////////////////

	bool JDFAncestorPool::IsPartitioned()const{
		return GetPartMapVector().size()>0;
	}

	//////////////////////////////////////////////////////////////////////


	void JDFAncestorPool::CopyNodeData(const JDFNode& parentNode, bool bCopyNodeInfo, bool bCopyCustomerInfo, bool bCopyComments){
		vElement vAncestors=GetPoolChildren();
		JDFNode node=parentNode;
		JDFNode copyNode=parentNode; // this is a high level hook that will be set dirty. needed to avoid dirtying the lower level nodes

		JDFNode thisParentNode=GetParentJDF();

		int i;
		for(i=vAncestors.size()-1;i>=0;i--){
			JDFAncestor ancestor=vAncestors[i];
			if(node.GetID()!=ancestor.GetNodeID()){
				throw JDFException(L"JDFAncestorPool::CopyNodeData: Invalid pairing");
			}

			// copy any namespace declarations that are defined in the parents
			mAttribute nodeMap=node.GetAttributeMap();
			for(mAttribute::iterator iter=nodeMap.begin();iter!=nodeMap.end();iter++){
				WString key=iter->first();
				if(iter->first().leftStr(5)==atr_xmlns){	
					thisParentNode.AddNameSpace(iter->first().rightStr(-6),iter->second());
				}
			}

			nodeMap.remove(atr_xsiType);
			ancestor.SetAttributes(nodeMap);
			ancestor.RenameAttribute(atr_ID, atr_NodeID);
			// only copy nodeinfo and customerinfo in real parent nodes, not in this of partitioned spawns
			if(thisParentNode.GetID()!=node.GetID()){
				if(bCopyNodeInfo){
					JDFNodeInfo nodeInfo=node.GetNodeInfo();
					if(!nodeInfo.isNull()){
						if(nodeInfo.HasAttribute(atr_ID)){
							// add a low level refelement, the copying takes place inaddspawnedresources
							JDFRefElement re=ancestor.AppendElement(elm_NodeInfo+atr_Ref);
							re.SetrRef(nodeInfo.GetID());
							re.SetPartMap(nodeInfo.GetPartMap());
						}else{
							ancestor.CopyElement(nodeInfo);
						}
					}
				}

				if(bCopyCustomerInfo){
					JDFCustomerInfo customerInfo=node.GetCustomerInfo();
					if(!customerInfo.isNull()){
						if(customerInfo.HasAttribute(atr_ID)){
							// add a low level refelement, the copying takes place inaddspawnedresources
							JDFRefElement re=ancestor.AppendElement(elm_CustomerInfo+atr_Ref);
							re.SetrRef(customerInfo.GetID());
							re.SetPartMap(customerInfo.GetPartMap());
						}else{
							ancestor.CopyElement(customerInfo);
						}
					}
				}

				if(bCopyComments){
					vElement v=node.GetChildElementVector(elm_Comment);
					for(int i=0;i<v.size();i++){
						ancestor.CopyElement(v[i]);
					}
				}
			}

			JDFNode node2=node.GetParentJDFNode();

			// 100602 RP added i--
			if(node2.isNull()){
				i--;
				break;
			}
			node=node2;
		}

		// the original node was already spawned --> also copy the elements of the original nodes Ancestorpool
		if(i>=0){
			vElement parentAncestors=node.GetAncestorPool().GetPoolChildren();
			int parentAncestorSize=parentAncestors.size();
			if(parentAncestorSize<i+1){
				throw JDFException(L"JDFAncestorPool::CopyNodeData: Invalid AncestorPool pairing");
			}

			// now copy the ancestorpool elements that have not yet been added from the original nodes
			for(;i>=0;i--){
				JDFAncestor ancestor=vAncestors[i];
				JDFAncestor parentAncestor=parentAncestors[i];
				ancestor.MergeElement(parentAncestor,false);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	/**
	* searches for the first attribute occurrence in the ancestor elements
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/
	WString JDFAncestorPool::GetAncestorAttribute(const WString & attrib,const WString& nameSpaceURI,const WString & def)const{
		vElement v=GetPoolChildren();
		//the last in list is the direct parent, the first is the original root
		for(int i=v.size()-1;i>=0;i--){
			JDFAncestor ancestor=v[i];
			if(ancestor.HasAttribute(attrib,nameSpaceURI))
				return ancestor.GetAttribute(attrib,nameSpaceURI);
		}
		// not found, return the default
		return def;

	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* true id a non default occurrence in the ancestor elements exists
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/
	bool JDFAncestorPool::HasAncestorAttribute(const WString & attrib,const WString& nameSpaceURI)const{
		return GetAncestorAttribute(attrib,nameSpaceURI,WString::quote).compare(WString::quote)!=0;
	}


	//////////////////////////////////////////////////////////////////////////////////////////////

	JDFElement JDFAncestorPool::GetAncestorElement(const WString & element,const WString& nameSpaceURI)const{
		vElement v=GetPoolChildren();
		//the last in list is the direct parent, the first is the original root
		for(int i=v.size()-1;i>=0;i--){
			const JDFAncestor ancestor=v[i];
			if(ancestor.HasChildElement(element,nameSpaceURI))
				return ancestor.GetElement(element,nameSpaceURI);
		}
		// not found, return an empty element
		return JDFElement();

	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* true id a non default occurrence in the ancestor elements exists
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/
	bool JDFAncestorPool::HasAncestorElement(const WString & attrib,const WString& nameSpaceURI)const{
		return !GetAncestorElement(attrib,nameSpaceURI).isNull();
	}



	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* searches for the first attribute occurrence in the ancestor elements subelements
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return WString: value of attribute found, empty string if not available
	*/

	//////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFAncestorPool::GetAncestorElementAttribute(const WString & element,const WString & attrib,const WString& nameSpaceURI,const WString & def)const{
		vElement v=GetPoolChildren();
		//the last in list is the direct parent, the first is the original root
		for(int i=v.size()-1;i>=0;i--){
			const JDFAncestor ancestor=v[i];
			const KElement e=ancestor.GetElement(element,nameSpaceURI);
			if((!e.isNull())&&(e.HasAttribute(attrib,nameSpaceURI)))
				return e.GetAttribute(attrib,nameSpaceURI);
		}
		return def;
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	/**
	* true if a non default attribute occurrence in the parent nodes and then the ancestor elements subelements of the root ancestorpool exists
	*
	* @param WString attrib: the attribute name
	* @param WString nameSpaceURI: the XML-namespace
	* @param WString def: the default if it does not exist
	* @since 180502 
	* @return bool: true if the attribute exists
	*/
	bool JDFAncestorPool::HasAncestorElementAttribute(const WString & element,const WString & attrib,const WString& nameSpaceURI)const{
		return GetAncestorElementAttribute(element,attrib,nameSpaceURI,WString::quote).compare(WString::quote)!=0;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////

	vElement JDFAncestorPool::GetPoolChildren(const mAttribute&mAttrib)const{
		vElement v=GetPoolChildrenGeneric(elm_Ancestor,mAttrib);
		return v;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	JDFAncestor JDFAncestorPool::GetPoolChild(int i,const mAttribute&mAttrib)const{
		return GetPoolChildGeneric(i,elm_Ancestor,mAttrib);
	}
	//////////////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////

	vmAttribute JDFAncestorPool::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}
	//////////////////////////////////////////////////////////////////////

	void JDFAncestorPool::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFAncestorPool::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFAncestorPool::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFAncestorPool::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFAncestorPool::GetLinkedResources(const mAttribute &mResAtt, bool bFollowRefs)const{
		vElement v=GetPoolChildren();
		vElement vL;
		for(int i=0;i<v.size();i++){
			JDFAncestor a=v[i];
			vL.AppendUnique(a.GetLinkedResources(mResAtt, bFollowRefs));

		}
		return vL;
	}

}; // namespace JDF
