/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
//
// JDFResource.cpp: implementation of the JDFResource class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFResourceLinkPool.h"
#include "JDFResourceLink.h"
#include "JDFResourcePool.h"
#include "JDFResource.h"
#include "JDFSourceResource.h"
#include "JDFPart.h"
#include "JDFDoc.h"
#include "JDFNode.h"
#include "JDFContact.h"
#include "JDFLocation.h"
#include "JDFFactory.h"
#include "JDFRefElement.h"
#include "JDFQualityControlResult.h"
#include "JDFIdentificationField.h"
#include "JDFGeneralID.h"
#include <xercesc/dom/DOMAttr.hpp>
#include <xercesc/dom/DOMElement.hpp>

#include <algorithm>

using namespace std;


namespace JDF{
	//////////////////////////////////////////////////////////////////////

	const JDFResource JDFResource::DefJDFResource=JDFResource();

	//////////////////////////////////////////////////////////////////////

	JDFResource::JDFResource(const KElement & other):JDFElement(){
		*this=other;
	};

	//////////////////////////////////////////////////////////////////////

	JDFResource& JDFResource::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFResource: "+other.GetNodeName()); 
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFResource::IsPhysical()const{
		if(throwNull())
			return false;		
		EnumClass c=GetClass(); 
		if(c!=Class_Unknown){
			return (c==Class_Consumable)||(c==Class_Quantity)||(c==Class_Handling)||(c==Class_Implementation);
		}else{
			return PhysicalResources().HasToken(GetLocalName(),WString::comma);
		}
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFResource::IsParameter()const{
		if(throwNull())
			return false;
		return (GetClass()==Class_Parameter);
	}

	//////////////////////////////////////////////////////////////////////

	const WString& JDFResource::PhysicalResources(){
		static const WString knownPhysicalResources=L"Component,DigitalMedia,ExposedMedia,Ink,Media,Pallet,RollStand,Strap,Tool";
		return knownPhysicalResources;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFResource::IsAvailable(bool bRecurseRefs)const{
		return GetStatus(bRecurseRefs)==Status_Available;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFResource::SetAvailable(bool bAvailable){
		SetStatus(bAvailable?Status_Available:Status_Unavailable);
	};

	//////////////////////////////////////////////////////////////////////
	WString JDFResource::GetResourceType()const{
		return GetNodeName();
	};
	//////////////////////////////////////////////////////////////////////
	WString JDFResource::GetLinkString()const {
		return GetResourceType()+atr_Link;
	}

	//////////////////////////////////////////////////////////////////////
	JDFResource JDFResource::GetResourceRoot()const{
		JDFResource res;
		JDFElement e  = (JDFElement) GetDeepParent(GetLocalName(), WString::pINF);

		if (!e.isNull())
		{
			JDFElement parentNode = e.GetParentNode();
			if (!parentNode.isNull())
			{ 
				WString parentName = parentNode.GetLocalName();

				if (!parentName.empty())
				{
					if (ValidParentNodeNames().HasToken(parentName, WString::comma,0))
					{
						res = (JDFResource) e;
					}
					else 
					{
						while ( !(parentNode.IsResource()) 
							&& !(parentNode.IsJDFNode())
							&& !(parentNode.isJDFJMF()) )
						{
							// find the first resource uptree
							parentNode = parentNode.GetParentNode();
						}

						if ( parentNode.IsResource() )
						{   // e was a resource element --> search root of the parent element
							return ((JDFResource)parentNode).GetResourceRoot();
						}

						if (parentNode.IsJDFNode())
						{ 
							if (e.isJDFNodeInfo() || e.isJDFCustomerInfo())
							{
								res = (JDFResource) e;
							}
							else 
							{
								throw new JDFException("JDFResource.getResourceRoot ran into the JDF node while searching");
							}
						}
						else
						{
							throw JDFException("JDFResource.getResourceRoot ran into the JMF node while searching");
						}
					}
				}
			}
			else // parentNode == null, this is a standalone resource
			{
				res=(JDFResource)e;
			}
		}

		return res;

		// ----- old version -----
		//JDFResource r=GetResourceRootImpl();
		//if(r.isNull())
		//	r=*this;
		//return r;
	}
	//////////////////////////////////////////////////////////////////////
	JDFResource JDFResource::GetResourceRootImpl()const{
		WString localName=GetLocalName();
		JDFElement e=GetDeepParent(localName,99999999);

		WString parentName=e.GetParentNode().GetLocalName();
		if(!parentName.empty()){
			if(ValidParentNodeNames().HasToken(parentName,WString::comma)){
				return e;
			}else if(parentName==elm_JDF&&((localName==elm_NodeInfo)||(localName==elm_CustomerInfo))){
				return e; // nodeinfo or customerinfo elements must be handled separately
			}else if(parentName==elm_JDF){ // snafu
				return JDFResource::DefJDFResource;
			}else if(parentName==elm_JMF){ // snafu #2
				return JDFResource::DefJDFResource;
			}else{
				// e was a resource element --> search root of the parent element
				JDFResource ret=JDFResource(e.GetParentNode()).GetResourceRoot();
				// the parent is a direct child of JDF or JMF, thus it is a resource container
				// and the resource is one below
				if (ret==JDFResource::DefJDFResource)
					ret=e;
				return ret;
			}
		}
		return e; // ran into nothing at all, assume that the document root is the root resource
	};

	//////////////////////////////////////////////////////////////////////

	JDFRefElement JDFResource::MakeRootResource(const WString & id, const JDFElement & parentPool,bool bLinkHere){
		JDFRefElement link;
		// create a RefElement at the same (in front of)  position as this
		JDFElement parentNode=GetParentNode();
		if(parentNode.GetLocalName()==elm_ResourcePool)
			return link;

		link=parentNode.InsertBefore(GetNodeName()+atr_Ref,*this);
		// use the local pool if no other is specified
		JDFResourcePool rp=parentPool;
		if(rp.isNull()){ 
			rp=GetPool();
			if(rp.isNull()){ // not a real resource but maybe a nodeinfo ...
				rp=GetParentJDF().GetCreateResourcePool();
			}
		}

		JDFResource oldRoot=GetResourceRoot();
		JDFResource newRes=rp.AppendResource(*this);

		if(oldRoot.HasAttribute(atr_Status)) {
			newRes.SetStatus(oldRoot.GetStatus());
		}else{
			newRes.SetStatus(Status_Available); // Assume that rootified resources are available by default
		}
		if(oldRoot.HasAttribute(atr_SpawnStatus)) 
			newRes.SetSpawnStatus(oldRoot.GetSpawnStatus());


		if(bLinkHere){
			WString idNew=id;
			if(id.empty()){
				idNew=GetIDPrefix()+UniqueID();
			}
			link.AppendHRef(*this,atr_rRef,idNew);
		}

		// in case class is not yet set, init will do so
		JDFFactory f(*this);
		JDFElement &rFactoryRef=f.GetRef();
		rFactoryRef.init();

		return link;
	}

	//////////////////////////////////////////////////////////////////////
	/// not inlined to avoid circular #includes
	JDFResourcePool JDFResource::GetPool()const{
		return GetResourcePool();
	};

	//////////////////////////////////////////////////////////////////////

	JDFResourcePool JDFResource::GetResourcePool()const
	{
		return GetDeepParent(elm_ResourcePool);
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFResource::init(){
		if(IsResourceRootRoot()) {
			AppendAnchor();
			SetStatus(Status_Unavailable);
			EnumVersion v=GetEnumVersion(true);
			if(v>=Version_1_2)
			{
				SetAgentName(JDFAudit::getStaticAgentName());
				SetAgentVersion(JDFAudit::getStaticAgentVersion());
			}
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFResource::IsQuantity()const{
		EnumClass c=GetClass();
		return (c==Class_Quantity)||(c==Class_Consumable);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFResource::RequiredLevel(EnumValidationLevel level)const{
		level=IncompleteLevel(level);
		return (level==ValidationLevel_Complete)||(level==ValidationLevel_RecursiveComplete);
	};	

	//////////////////////////////////////////////////////////////////////

	KElement::EnumValidationLevel JDFResource::IncompleteLevel(KElement::EnumValidationLevel level, bool bForce)const{
		if(JDFElement::RequiredLevel(level)){
			EnumStatus es=GetStatus();
			if((es==Status_Incomplete)||(IsResourceUpdate())||bForce){
				if(level==ValidationLevel_Complete){
					level=ValidationLevel_Incomplete;
				}else if(level==ValidationLevel_RecursiveComplete){
					level=ValidationLevel_RecursiveIncomplete;
				}
			}			
		}
		return level;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFResource::FixVersion(EnumVersion version){
		bool bRet=true;
		if(!IsResourceRootRoot()){
			RemoveAttribute(atr_Class);
			if(version>=Version_1_2){
				RemoveAttribute(atr_ID);
			}
		}else{
			if(version>=Version_1_3){	 
				if(GetPartUsage()==PartUsage_Sparse){
					SetPartUsage(PartUsage_Implicit);
				}
			}
		}
		return JDFElement::FixVersion(version) && bRet;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFResource::IsValid(EnumValidationLevel level)const{
		if(level<=ValidationLevel_Construct && isNull()) 
			return true;

		// it is supposed to be incomplete -> don't check for completeness
		level=IncompleteLevel(level);

		// no specific details on construct check
		if(level<=ValidationLevel_Construct) {
			return JDFElement::IsValid(level);
		}
		bool bLeaf=IsLeaf();
		if(bLeaf){ 
			if(!JDFElement::IsValid(level)){
				return false;
			}
		}else if(IsResourceUpdate()){	
			JDFResource r=GetResourceRoot();
			if(r.isNull()){
				// tbd details of customerinfo + nodeinfo res elements
				return true;
			}
			if(!r.ValidID(level)) 
				return false;
			if(!r.ValidStatus(level)) 
				return false;
		}else{
			EnumPartUsage partUsage = GetPartUsage();
			bool bForceIncomplete=!(partUsage == PartUsage_Implicit)||(partUsage == PartUsage_Sparse);

			if(GetInvalidAttributes(IncompleteLevel(level,bForceIncomplete),true,1).size()>0)
				return false;

			vElement v=GetLeaves();
			for(int i=0;i<v.size();i++){
				//300402 RP added factory in order to retain the class of the leaves
				try{
					JDFFactory f(v.at(i));
					JDFElement &rFactoryRef=f.GetRef();
					if(!rFactoryRef.IsValid(level)) 
						return false;
				}catch (JDFException e){
					return false;
				}
			}
		}

		if(!IsResourceRootRoot()){	
			if(!ValidID(level))
				return false;
			// PartIDKeys is only valid in the root
			if(KElement::HasAttribute(atr_PartIDKeys))
				return false;
			if(!IsResourceElement()){
				if(KElement::HasAttribute(atr_Class))
					return false;
			}
			// if partusage=implicit, the root must also be complete and valid by itself
		}else if(!bLeaf&&((GetPartUsage()==PartUsage_Implicit)||(GetPartUsage()==PartUsage_Sparse))){
			if(!JDFElement::IsValid(level)){
				return false;
			}
		}

		// heureka!
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetCreator(bool bCreate)const{ 
		// if !bCreate the return value is the consumer ;-)
		// to do: multiple output to same resource!
		vElement v=GetLinks();
		vElement vv;

		for(int i=0;i<v.size();i++){
			// 040201 RP check added
			if(!((JDFElement&)v[i]).IsResourceLink())
				continue;

			JDFResourceLink l=v[i];
			if(!l.IsValid(ValidationLevel_Complete)) 
				continue;

			// if the link is output, the node is the creator
			if(l.GetUsage()==(bCreate ? JDFResourceLink::Usage_Output : JDFResourceLink::Usage_Input)){ 
				// the parent of the resourcelinkpool is the node
				vv.push_back(l.GetPool().GetParentNode());
			}
		}
		return vv;
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetLinks(const WString & linkName, const WString& nameSpaceURI)const{
		mAttribute m;
		m.AddPair(atr_rRef,GetID());
		return GetDocRoot().GetChildrenByTagName(linkName,nameSpaceURI,m,false,false);
	}

	//////////////////////////////////////////////////////////////////////



	// useful e.g. for cloning an identical input resource onto an output resource
	JDFResource JDFResource::MergeCloneResource(JDFResource oldRes){
		// get all preset attributes
		mAttribute m=GetAttributeMap();
		// clone oldRes onto this
		MergeElement(oldRes,false);
		// reset all preset attributes
		SetAttributes(m);
		return *this;
	}	


	////////////////////////////////////////////////////////////////////////

	unsigned int JDFResource::GetMinRefAttribute(const WString & key, const WString& allowedValues,  unsigned int def,const WString & nameSpaceURI)const{
		unsigned int ret=GetEnumAttribute(key,allowedValues,nameSpaceURI,def);
		vElement v=GetvHRefRes();
		for(int i=0;i<v.size();i++){
			if(!ret)
				return ret; // performance
			ret=min(ret,JDFResource(v[i]).GetEnumAttribute(key,allowedValues,nameSpaceURI,def));
		}
		return ret;
	}
	////////////////////////////////////////////////////////////////////////

	unsigned int JDFResource::GetMaxRefAttribute(const WString & key, const WString& allowedValues,  unsigned int def,const WString & nameSpaceURI)const{
		unsigned int ret=GetEnumAttribute(key,allowedValues,nameSpaceURI,def);
		vElement v=GetvHRefRes();
		for(int i=0;i<v.size();i++){
			if(!ret) return ret; // invalid stays invalid
			ret=max(ret,JDFResource(v[i]).GetEnumAttribute(key,allowedValues,nameSpaceURI,def));
		}
		return ret;
	}

	///////////////////////////////////////////////////////////////////////

	vWString JDFResource::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{

		int nElem=0;
		int i=0;
		level=IncompleteLevel(level);

		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			return vElem;

		nElem=NumChildElements(elm_QualityControlResult);
		for(i=0;i<nElem;i++){
			JDFQualityControlResult child=GetElement(elm_QualityControlResult,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_QualityControlResult);
				if (++n>=nMax) 
					return vElem;
				break;
			}
		}

		if(IsPhysical()){
			nElem=NumChildElements(elm_Contact);
			if (nElem>1) {
				vElem.push_back(elm_Contact);
				if (++n>=nMax) 
					return vElem;
			}
			for(i=0;i<nElem;i++){
				JDFContact child=GetElement(elm_Contact,WString::emptyStr,i);
				if (!child.IsValid(level)) {
					vElem.push_back(elm_Contact);
					if (++n>=nMax) 
						return vElem;
				}
			}

			nElem=NumChildElements(elm_IdentificationField);
			for(i=0;i<nElem;i++){
				JDFIdentificationField child=GetElement(elm_IdentificationField,WString::emptyStr,i);
				if (!child.IsValid(level)) {
					vElem.push_back(elm_IdentificationField);
					if (++n>=nMax) 
						return vElem;
					break;
				};
			}

			nElem=NumChildElements(elm_Location);
			if (nElem>1) {
				vElem.push_back(elm_Location);
				if (++n>=nMax) 
					return vElem;
			}
			for(i=0;i<nElem;i++){
				JDFLocation child=GetElement(elm_Location,WString::emptyStr,i);
				if (!child.IsValid(level)) {
					vElem.push_back(elm_Location);
					if (++n>=nMax) 
						return vElem;
				}
			}

			nElem=NumChildElements(elm_Identical);
			if (nElem>1) {
				vElem.push_back(elm_Identical);
				if (++n>=nMax) 
					return vElem;
			}
			for(i=0;i<nElem;i++){
				JDFLocation child=GetElement(elm_Identical,WString::emptyStr,i);
				if (!child.IsValid(level)) {
					vElem.push_back(elm_Identical);
					if (++n>=nMax) 
						return vElem;
				}
			}

		}

		return vElem;
	};

	///////////////////////////////////////////////////////////////////////

	vWString JDFResource::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {

		level=IncompleteLevel(level);

		vWString vAtts=JDFElement::GetInvalidAttributes(level, bIgnorePrivate, nMax);

		int n=vAtts.size();
		if(n>=nMax) 
			return vAtts;

		if(!ValidAgentName(level)) {
			vAtts.push_back(atr_AgentName);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAgentVersion(level)) {
			vAtts.push_back(atr_AgentVersion);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAuthor(level)) {
			vAtts.push_back(atr_Author);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidCatalogID(level)) {
			vAtts.push_back(atr_CatalogID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidCatalogDetails(level)) {
			vAtts.push_back(atr_CatalogDetails);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidLocked(level)) {
			vAtts.push_back(atr_Locked);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPartUsage(level)) {
			vAtts.push_back(atr_PartUsage);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPipeID(level)) {
			vAtts.push_back(atr_PipeID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPipeProtocol(level)) {
			vAtts.push_back(atr_PipeProtocol);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidProductID(level)) {
			vAtts.push_back(atr_ProductID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPipeURL(level)) {
			vAtts.push_back(atr_PipeURL);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidrRefs(level)) {
			vAtts.push_back(atr_rRefs);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidSpawnIDs(level)) {
			vAtts.push_back(atr_SpawnIDs);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidSpawnStatus(level)) {
			vAtts.push_back(atr_SpawnStatus);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidUpdateID(level)) {
			vAtts.push_back(atr_UpdateID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPartIDKeys(level)) {
			vAtts.push_back(atr_PartIDKeys);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPipePartIDKeys(level)) {
			vAtts.push_back(atr_PipePartIDKeys);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidSorting(level)) {
			vAtts.push_back(atr_Sorting);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidSortAmount(level)) {
			vAtts.push_back(atr_SortAmount);
			if(++n>=nMax) 
				return vAtts;
		};

		EnumValidationLevel eLevel=level;
		if (IsResourceElement()){
			eLevel=ValidationLevel_Incomplete;
		};


		EnumValidationLevel rootLevel=IsResourceRootRoot()?eLevel:ValidationLevel_Incomplete;
		if(!ValidClass(rootLevel)) {
			vAtts.push_back(atr_Class);
			if(++n>=nMax) 
				return vAtts;
		}
		if(!ValidStatus(rootLevel)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidID(rootLevel)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax) 
				return vAtts;
		};
		if (IsParameter()) {
			if(!ValidNoOp(level)) {
				vAtts.push_back(atr_NoOp);
				if(++n>=nMax) 
					return vAtts;
			}
		}
		if (IsPhysical()) {
			if(!ValidAlternateBrand(level)) {
				vAtts.push_back(atr_AlternateBrand);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidAmount(level)) {
				vAtts.push_back(atr_Amount);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidAmountProduced(level)) {
				vAtts.push_back(atr_AmountProduced);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidAmountRequired(level)) {
				vAtts.push_back(atr_AmountRequired);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidBatchID(level)) {
				vAtts.push_back(atr_BatchID);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidBrand(level)) {
				vAtts.push_back(atr_Brand);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidManufacturer(level)) {
				vAtts.push_back(atr_Manufacturer);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidResourceWeight(level)) {
				vAtts.push_back(atr_ResourceWeight);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidGrossWeight(level)) {
				vAtts.push_back(atr_ResourceWeight);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidLotControl(level)) {
				vAtts.push_back(atr_LotControl);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidUnit(level)) {
				vAtts.push_back(atr_Unit);
				if(++n>=nMax) 
					return vAtts;
			};
		}		

		// partition keys
		if(!ValidBinderySignatureName(level)) {
			vAtts.push_back(atr_BinderySignatureName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockName(level)) {
			vAtts.push_back(atr_BlockName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBundleItemIndex(level)) {
			vAtts.push_back(atr_BundleItemIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCellIndex(level)) {
			vAtts.push_back(atr_CellIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCondition(level)) {
			vAtts.push_back(atr_Condition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocIndex(level)) {
			vAtts.push_back(atr_DocIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocCopies(level)) {
			vAtts.push_back(atr_DocCopies);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocRunIndex(level)) {
			vAtts.push_back(atr_DocRunIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocSheetIndex(level)) {
			vAtts.push_back(atr_DocSheetIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFountainNumber(level)) {
			vAtts.push_back(atr_FountainNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidItemNames(level)) {
			vAtts.push_back(atr_ItemNames);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayerIDs(level)) {
			vAtts.push_back(atr_LayerIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLocation(level)) {
			vAtts.push_back(atr_Location);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOption(level)) {
			vAtts.push_back(atr_Option);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageNumber(level)) {
			vAtts.push_back(atr_PageNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPartVersion(level)) {
			vAtts.push_back(atr_PartVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreflightRule(level)) {
			vAtts.push_back(atr_PreflightRule);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreviewType(level)) {
			vAtts.push_back(atr_PreviewType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRibbonName(level)) {
			vAtts.push_back(atr_RibbonName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRun(level)) {
			vAtts.push_back(atr_Run);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunIndex(level)) {
			vAtts.push_back(atr_RunIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunTags(level)) {
			vAtts.push_back(atr_RunTags);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunPage(level)) {
			vAtts.push_back(atr_RunPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSectionIndex(level)) {
			vAtts.push_back(atr_SectionIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSeparation(level)) {
			vAtts.push_back(atr_Separation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetDocIndex(level)) {
			vAtts.push_back(atr_SetDocIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetIndex(level)) {
			vAtts.push_back(atr_SetIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetRunIndex(level)) {
			vAtts.push_back(atr_SetRunIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetSheetIndex(level)) {
			vAtts.push_back(atr_SetSheetIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetName(level)) {
			vAtts.push_back(atr_SheetName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetIndex(level)) {
			vAtts.push_back(atr_SheetIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSide(level)) {
			vAtts.push_back(atr_Side);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSignatureName(level)) {
			vAtts.push_back(atr_SignatureName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTileID(level)) {
			vAtts.push_back(atr_TileID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWebName(level)) {
			vAtts.push_back(atr_WebName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWebProduct(level)) {
			vAtts.push_back(atr_WebProduct);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWebSetup(level)) {
			vAtts.push_back(atr_WebSetup);
			if(++n>=nMax)
				return vAtts;
		};

		for(int iDel=0;iDel<10;iDel++)
		{
			if(!validDeliveryUnit(iDel,level)) {
				vAtts.push_back(atr_DeliveryUnit+WString::valueOf(iDel));
				if(++n>=nMax)
					return vAtts;
			};
		}
		// end of partition keys
		// now check whether they are in PartIDKeys

		if(!IsResourceElement())
		{
			JDFResource root=GetResourceRoot();
			vWString partIDKeys=root.GetPartIDKeys();
			for(int i=0;i<partIDKeys.size();i++)
			{
				EnumPartIDKey nxt=GetPartIDKeyEnum(partIDKeys.stringAt(i));
				if (!ConsistentPartIDKeys(nxt))
				{
					vAtts.AppendUnique(partIDKeys.stringAt(i));
					if (++n >= nMax)
					{
						return vAtts;
					}
				}
			}
		}

		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::CreatePartitions(const vmAttribute& vPartMap, const vWString& vPartIDKeys){
		vElement v;
		for(int i=0;i<vPartMap.size();i++){
			vWString tmp;
			JDFAttributeMap map = vPartMap[i];
			for (int j=0;j<vPartIDKeys.size();j++)
			{
				if (map.HasKey(vPartIDKeys[j]))
				{
					tmp.add(vPartIDKeys[j]);
				}
			}
			v.push_back(GetCreatePartition(map,tmp));
		}

		return v;
	}

	///////////////////////////////////////////////////////////////////////////
	JDFResource JDFResource::GetCreatePartition(EnumPartIDKey key, const WString & value, const vWString& vPartIDKeys){
		mAttribute mp;
		mp.AddPair(PartIDKeyString(key),value);
		return GetCreatePartition(mp,vPartIDKeys);
	}


	///////////////////////////////////////////////////////////////////////////

	JDFResource JDFResource::GetCreatePartition(const mAttribute& partMap, const vWString& vPartKeys){
		if(partMap.empty()) 
			return GetResourceRoot();

		mAttribute localPartMap(partMap); // create a copy because it might get modified
		bool appendEnd  = true;
		vWString vPartIDKeys = reorderPartKeys(vPartKeys);

		// check whether we are already ok
		int iMore=0;
		mAttribute::iterator it=localPartMap.begin();
		while(it!=localPartMap.end()) 
		{
			WString key = it.first();
			it++;       
			if (!vPartIDKeys.contains(key))
			{
				iMore++;
			}
		}
		// only heuristically add stuff if needed...
		if(iMore>1){
			vPartIDKeys = expandKeysFromNode(localPartMap,vPartIDKeys);
		}

		mAttribute thisMap = GetPartMap();
		if (!JDFPart::overlapPartMap(thisMap,localPartMap))
		{    
			throw new JDFException("JDFResource.GetCreatePartition: non-matching partitions");
		}

		if(!thisMap.empty())
		{			
			vWString thisKeys = thisMap.GetKeys();
			int siz = (thisKeys.size() < vPartIDKeys.size()) ? thisKeys.size() : vPartIDKeys.size();

			// remove the keys of this
			for (int i = 0; i < siz; i++)
			{
				WString key = vPartIDKeys[0];
				localPartMap.remove(key);
				vPartIDKeys.erase(vPartIDKeys.begin());
			}
		}

		bool allParts = true;
		bool creating = false;
		JDFResource leaf(*this);
		// create all partitions
		for (int k = 0; k < vPartIDKeys.size(); k++)
		{
			WString key = vPartIDKeys.elementAt(k);
			EnumPartIDKey enumKey = GetPartIDKeyEnum(key);
			WString value = localPartMap.GetValue(key);

			if (localPartMap.HasKey(key))
			{
				if (allParts)
				{
					if (!creating)
					{
						JDFResource nextLeaf = leaf.GetPartition(mAttribute(key,value), PartUsage_Explicit);
						if (nextLeaf.isNull())
						{
							creating = true;
						}
						else
						{
							leaf = nextLeaf;
						}                   
					}
					if (creating)
					{
						leaf = leaf.AddPartition(enumKey,value);
					}
					localPartMap.remove(key);
					if(localPartMap.size() == 0)
					{
						break; // nothing left to do
					}
				}
				else
				{
					throw JDFException("GetCreatePartition: attempting to fill non-matching partIDKeys");
				}
			}
			else
			{
				allParts = false;
			}
		}

		// add last partition key
		int partSize = localPartMap.size();
		if (appendEnd && allParts && partSize == 1)// one left and continuous, can add
		{ 
			WString key = localPartMap.GetKeys().elementAt(0);
			leaf = leaf.AddPartition(JDFResource::GetPartIDKeyEnum(key), localPartMap.GetValue(key));
		}
		else if (partSize>0)// either non - continuous or more than one left
		{ 
			throw JDFException("AddPartitionMap: incompatible partmap");
		}
		return leaf; 
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* heuristic guess of the best possible partidkey sequence
	* @param partMap the partmap that we want to create
	* @param vPartIDKeys the known base partidkeys
	* @return the best guess vector of partidkeys
	*/
	vWString JDFResource::expandKeysFromNode(const mAttribute& partMap, const vWString& vPartIDKeys) const {
		JDFNode n=GetParentJDF();
		if(n.isNull()) // something is fishy, just return the input
			return vPartIDKeys;

		vWString nodeKeys=n.GetPartIDKeys(partMap);
		int nodeKeySize = nodeKeys.size();
		int partKeySize = vPartIDKeys.size();
		if(nodeKeySize<=partKeySize) // no expansion is possible
			return vPartIDKeys;

		for(int i=0;i<partKeySize;i++){
			if(!(vPartIDKeys[i]==nodeKeys[i]))
				return vPartIDKeys; // nodekeys and partkeys are incompatible, retuen the input    		
		}

		// all beginning elements are equal but we have more - use these as a best guess
		return nodeKeys;
	}
	//////////////////////////////////////////////////////////////////////
	vint JDFResource::GetImplicitPartitions() const{
		return vint::emptyvint;
	}
	//////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////

	JDFResource JDFResource::GetPartition(EnumPartIDKey key, const WString & value, bool bIncomplete)const{
		mAttribute mp;
		mp.AddPair(PartIDKeyString(key),value);
		return GetPartition(mp,bIncomplete ? PartUsage_Implicit : PartUsage_Explicit);
	}

	//////////////////////////////////////////////////////////////////////

	JDFResource JDFResource::GetPartition(const mAttribute& m, bool bIncomplete)const{
		if(m.empty()) 
			return *this;
		return GetDeepPart(m, bIncomplete ? PartUsage_Implicit : PartUsage_Explicit);
	}
	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetPartitionVector(EnumPartIDKey key, const WString & value,  bool bIncomplete)const{
		mAttribute mp(PartIDKeyString(key),value);
		return GetPartitionVector(mp,bIncomplete ? PartUsage_Implicit : PartUsage_Explicit);
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetPartitionVector(const mAttribute& m,  bool bIncomplete)const{

		return GetDeepPartVector(m,bIncomplete ? PartUsage_Implicit : PartUsage_Explicit,-1);
	}
	//////////////////////////////////////////////////////////////////////

	JDFResource JDFResource::GetPartition(EnumPartIDKey key, const WString & value, EnumPartUsage partUsage)const{
		mAttribute mp;
		mp.AddPair(PartIDKeyString(key),value);
		return GetPartition(mp,partUsage);
	}

	//////////////////////////////////////////////////////////////////////

	JDFResource JDFResource::GetPartition(const mAttribute& m, EnumPartUsage partUsage)const{

		if(m.empty()) 
			return *this;

		return GetDeepPart(m, partUsage);
	}
	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetPartitionVector(EnumPartIDKey key, const WString & value, EnumPartUsage partUsage)const{
		mAttribute mp;
		mp.AddPair(PartIDKeyString(key),value);
		return GetPartitionVector(mp,partUsage);
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetPartitionVector(const mAttribute& m, EnumPartUsage partUsage)const{

		return GetDeepPartVector(m,partUsage,-1);
	}
	//////////////////////////////////////////////////////////////////////

	JDFResource JDFResource::GetDeepPart(const mAttribute &m, EnumPartUsage partUsage)const{
		vElement vElm=GetDeepPartVector(m,partUsage,-1);
		JDFResource returnRes;
		int siz=vElm.size();
		if(siz==0){ // nothing fits at all
			return returnRes;
		}else if(siz==1){ // only one, take it
			returnRes=vElm[0];
		}else{ // multiple, get the closest ancestor
			JDFResource e = vElm[0];
			if(e.IsResourceRoot()){
				return e;	
			}

			e=e.GetParentNode();
			do
			{
				int i;
				for(i=siz-1;i>0;i--){ // e is always an ancestor of vElm[i]; go backwards since the chance of mismatch is greater at the end of the list
					if(!e.IsAncestor(vElm[i])){ // found a misMatch
						e=e.GetParentNode();
						break;
					}
				}
				if(i==0){ // went through the entire loop with no mismatch --> heureka and ciao
					returnRes=e;
					break;
				}
			}
			while(e!=*this);

			if(e.IsResourceRoot()||(e==*this)){
				return e; // the root or the starting point is always ok - no further checks downward
			}
		}

		if (returnRes.isNull())
			return JDFResource();

		// now loop down towards the root (or this) to check if any element that is closer to the root may be equivalent in terms of matching pairs
		int retSize=-1;		
		JDFResource loopRes=returnRes;
		vWString vKeys=m.GetKeys();

		// loop until we hit this or root, whichever is closer
		while(42){
			mAttribute returnMap=loopRes.GetPartMap();
			// only check the keys, not the values since <Identical> elements may screw up the values... 
			returnMap.ReduceKey(vKeys);
			// we lost a key - break one prior to this
			if((int)returnMap.size()<retSize){
				return returnRes; // the child of the tested element
			}else if(retSize==-1){ // first loop initialization
				retSize=returnMap.size();
			}
			// we hit the starting point - nothing left to do
			if((loopRes==*this)||loopRes.IsResourceRoot())
				return loopRes;
			// no check failed - go one closer to the root
			returnRes=loopRes;
			loopRes=loopRes.GetParentNode();
			if(loopRes.isNull())
				throw(JDFException(L"JDFResource::GetDeepPart ran into null element while searching tree"));
		}
		return returnRes; // should never get here but keep the compiler happy
	}

	/////////////////////////////////////////////////////////////////////////////////  
	mAttribute JDFResource::removeImplicitPartions(mAttribute & m)const
	{
		if(m.isEmpty())
			return m;
		JDFFactory f(*this);
		vint v=((JDFResource&)f.GetRef()).GetImplicitPartitions();
		if(v.empty())
			return m;
		for(int i=0;i<v.size();i++)
		{
			m.remove(PartIDKeyString((EnumPartIDKey)v.at(i)));
		}    
		return m;
	}
	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetDeepPartVector(const mAttribute &m_in, EnumPartUsage partUsage, int matchingDepth)const{
		vElement vReturn;
		mAttribute m=m_in;
		m=removeImplicitPartions(m);
		if(partUsage==PartUsage_Unknown){
			partUsage=GetPartUsage();
		}


		const int msiz=m.size();
		if(matchingDepth==-1){ // first call - check validity of the map
			matchingDepth=0;
			mAttribute thisMap=GetPartMap();
			for(int i=0;i<msiz;i++)
			{
				//				GetPartIDKeyEnum(m.GetKeyByPos(i)); // check map and throw exception if bad
				// check whether we are already in a leaf when initially calling
				if(thisMap.GetValue(m.GetKeyByPos(i))==m.GetValueByPos(i)){
					matchingDepth++;
				}
			}
			// check if we are incompatible from the start...
			if(!thisMap.OverlapMap(m))
				return vReturn;
		}

		// if we find an identical element, we must clean up the map and merge in the values of identical
		if(HasChildElement(elm_Identical)){
			mAttribute identityMap=JDFPart(GetElement(elm_Identical).GetElement(elm_Part)).GetPartMap();
			m.MergeMap(identityMap);
			// the identity map is always complete from the root, we therefore can start searching in the root
			return GetResourceRoot().GetDeepPartVector(m,partUsage,-1);
		}

		if(msiz==matchingDepth){
			if(!throwNull()){
				vReturn.push_back(*this);
			}
			return vReturn;
		}

		const WString nodeName=GetNodeName();

		JDFResource p=KElement::GetElement(nodeName);

		if (p.isNull()){ // got a leaf or found no matching children
			// 150802 RP removed different treatment for leaves and no matching elements
			if(partUsage>=PartUsage_Sparse){ // allow incomplete parts if sparse or implicit
				vReturn.push_back(*this);
			}
			return vReturn;
		}


		vElement toAppend; // we stick all recursively found candidates into this vector
		bool hasBadChildren=false;
		// loop over all valid elements and search downward
		bool hasMatchingAttribute=false;

		bool bSearchSame=true; // boolean that controls whether to search the lower children.
		bool bCompleteMatch=false;

		int nChildren=0;
		WString matchingKey,matchingValue;
		int matchingKeyPos=-1;
		while(42){
			bool badChild=false;
			bool bSnafu=false;
			JDFElement resourceElement=p; // used for an explicit (non inherited) attribute check.
			if(matchingKeyPos>=0){ // all other elements except the first may have a predefined matching key
				WString sTmp=resourceElement.GetAttribute(matchingKey,WString::emptyStr,WString::quote);
				if(sTmp!=WString::quote) {// found a matching key;
					if(sTmp==matchingValue){
						hasMatchingAttribute=true;
					}else{
						badChild=true;
						hasBadChildren=true;
					}
				}else{
					bSnafu=true; // should never get here, but in case of a corrupt leaf structure, it could happen and will be handled gracefully
				}
			}
			if((!(nChildren++))||bSnafu){ // must only search the first element, since only one key is allowed and all keys must be in the same sequence;
				// unless, of course, someone wrote crap JDF (bSnafu=true)
				for(int im=0;im<msiz;im++){
					WString strKey = m.GetKeyByPos(im);
					WString strValue = m.GetValue(strKey);

					WString sTmp=resourceElement.GetAttribute(m.GetKeyByPos(im),WString::emptyStr,WString::quote);
					if(sTmp!=WString::quote) {// found a matching key;
						if(JDFPart::matchesPart(strKey,sTmp,strValue)) {
							hasMatchingAttribute=true;
						}else{
							badChild=true;
							hasBadChildren=true;
						}
						matchingKeyPos=im;
						matchingKey=m.GetKeyByPos(matchingKeyPos);
						matchingValue=m.GetValueByPos(im);
						break;
					}
				}
			}
			if(!badChild){
				vElement dpv=p.GetDeepPartVector(m,partUsage,hasMatchingAttribute?matchingDepth+1:matchingDepth);
				if(dpv.size()>0){
					toAppend.insert(toAppend.end(),dpv.begin(),dpv.end());
					bSearchSame=false; // not necessary since we have something deeper
					if(hasMatchingAttribute&&toAppend.size()==1){ // this is a potential complete match - we may just stop
						JDFResource root=GetResourceRoot();
						JDFResource closest=toAppend[0];
						// move to root
						int leafDepth=0;
						while(closest!=root){
							leafDepth++;
							closest=closest.GetParentNode();
						}
						bCompleteMatch=(leafDepth==msiz);
					}
				}
			}
			if(bCompleteMatch){
				break; // nothing at all left to do; jump out of loop
			}
			p=p.GetNextSiblingElement(nodeName,WString::emptyStr);
			if(p.isNull())
				break;
		}

		// nothing complete was found, and we are at the end of the chain
		if(bSearchSame){
			// check whether all sub elements of this are accepted completely
			int appSize=toAppend.size();
			bool bSame=(!hasMatchingAttribute)&&(nChildren==appSize);
			if(bSame){
				p=KElement::GetElement(nodeName);
				for(int n=0;n<appSize;n++){
					if(p!=toAppend[n]){
						bSame=false;
						break;
					}
					p=p.GetNextSiblingElement(nodeName,WString::emptyStr);
					if(p.isNull())
						break;					
				}
			}

			if(!bSame){ // something in the children warrants a closer look and we are at the end
				// none match and this is the last with bad kids and we want incomplete stuff
				if(toAppend.empty() && hasBadChildren && partUsage==PartUsage_Implicit && !hasMatchingAttribute){
					JDFResource root=GetResourceRoot();
					JDFResource closest=*this;
					bool bClosest=false;
					// move to root
					while(closest!=root){
						JDFElement closestElement=closest; // used for an explicit (non inherited) attribute check.
						// check whether any parameters of map were found
						for(int i=0;i<msiz;i++){
							if(closestElement.HasAttribute(m.GetKeyByPos(i))){
								bClosest=true;
								break;
							}
						}
						// found one that has at least one attribute from m --> stop searching
						if(bClosest)
							break;

						// this one is no closer than it's parent --> take the parent and retry
						closest=closest.GetParentNode();
					}

					vReturn.push_back(closest);

				}else{ // this is the standard recursive case with no special handling
					vReturn.insert(vReturn.end(),toAppend.begin(),toAppend.end());
				}
			}else{
				// if all subelements were accepted, I am the correct root
				// note that this may recurse up closer to the root
				vReturn.push_back(*this);
			}
		}else{ // this is the standard recursive case with no special handling
			vReturn.insert(vReturn.end(),toAppend.begin(),toAppend.end());
		}

		return vReturn;
	}

	//////////////////////////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetLeaves(bool bAll)const{
		vElement e;
		if(throwNull())
			return e;

		// want possibly intermediate nodes
		// check the kids use KElement becaus I want the direct leaves and no refElements
		e=KElement::GetChildElementVector(GetNodeName());
		if(e.empty()){
			// got a leaf
			e.push_back(*this);
			return e;
		}else{
			// recurse parts tree and sum up the results
			vElement vv;
			if(bAll){
				vv.push_back(*this);
			}
			for(int i=0;i<e.size();i++){
				vElement v=JDFResource(e.at(i)).GetLeaves(bAll);
				vv.insert(vv.end(),v.begin(),v.end());
			}
			return vv;
		}


		//// want possibly intermediate nodes, check the kids
		//vElement vAllChildren = KElement::GetChildElementVector(GetNodeName(), WString::emptyStr, mAttribute::emptyMap, true, 0, false);

		//if (vAllChildren.empty())
		//{
		//	// got a leaf
		//	vAllChildren.add(*this);
		//}
		//else
		//{
		//	vElement vLeaves;
		//	// recurse parts tree and sum up the results
		//	if (bAll)
		//	{
		//		vLeaves.AppendUnique(*this);
		//	}

		//	for (int i = 0; i < vAllChildren.size(); i++)
		//	{
		//		JDFResource pi = (JDFResource) vAllChildren.elementAt(i);
		//		vElement v = pi.GetLeaves(bAll);
		//		for (int j = 0; j < v.size(); j++)
		//			vLeaves.add(v.elementAt(j));
		//	}

		//	vAllChildren = vLeaves;
		//}

		//return vAllChildren;
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFResource::GetPartValues(EnumPartIDKey key)const{
		vElement v = GetLeaves(false);
		vWString vs;

		for (int i = 0; i < v.size(); i++)
		{
			JDFResource p = (JDFResource) v.elementAt(i);
			WString s = p.GetAttribute(JDFResource::PartIDKeyString(key), WString::emptyStr, WString::emptyStr);

			if (!s.empty())
			{
				bool bOK = true;
				for (int j = 0; j < vs.size() && bOK; j++)
				{

					if (s==vs.elementAt(j))
					{
						bOK = false;
					}
				}

				if (bOK)
				{
					vs.add(s);
				}
			}
		}

		return vs;
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	vWString JDFResource::GetPipePartIDKeys()const{
		if (HasAttribute(atr_PipePartIDKeys))
			return GetResourceRoot().GetAttribute(atr_PipePartIDKeys).Tokenize(WString::blank);
		return GetPartIDKeys();
	}

	//////////////////////////////////////////////////////////////////////

	void JDFResource::AddPipePartIDKey(EnumPartIDKey partType){
		WString s=PartIDKeyString(partType);
		GetResourceRoot().AppendAttribute(atr_PipePartIDKeys,s,WString::emptyStr,WString::blank,true);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	vWString JDFResource::GetPartIDKeys()const{
		return GetResourceRoot().GetAttribute(atr_PartIDKeys).Tokenize(WString::blank);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFResource::AddPartIDKey(EnumPartIDKey partType){
		WString s = PartIDKeyString(partType);
		JDFResource r = GetResourceRoot();

		vint implicitPartitions = GetImplicitPartitions();
		if (!implicitPartitions.empty() && (implicitPartitions.index(partType) >= 0))
		{
			throw JDFException("AddPartIDKey: attempting to add implicit partition: "+s);
		}
		r.AppendAttribute(atr_PartIDKeys, s, WString::emptyStr, WString::blank, true);
	}

	//////////////////////////////////////////////////////////////////////

	mAttribute JDFResource::GetPartMap()const{
		vWString ids=GetPartIDKeys();
		mAttribute m;
		int size = (ids.empty()) ? 0 : ids.size();
		for (int i = 0; i < size; i++)
		{
			WString atr = GetAttribute((WString) ids.elementAt(i), WString::emptyStr, WString::emptyStr);
			if (!atr.empty())
			{
				m.put((WString) ids.elementAt(i), atr);
			}
		}

		return m;
	}

	//////////////////////////////////////////////////////////////////////

	vmAttribute JDFResource::GetPartMapVector(bool bIntermediate)const{
		vElement allNodes=GetLeaves(bIntermediate);
		vmAttribute vReturn;
		vWString ids=GetPartIDKeys();
		for(int j=0;j<allNodes.size();j++){
			mAttribute m;
			JDFResource r=allNodes[j];
			for(int i=0;i<ids.size();i++){
				if (r.HasAttribute(ids[i]))
					m.AddPair(ids[i],r.GetAttribute(ids[i]));
			}
			vReturn.push_back(m);
		}
		return vReturn;
	}


	//////////////////////////////////////////////////////////////////////

	WString JDFResource::GetAttribute(const WString & attrib, const WString & nameSpaceURI, const WString & def)const
	{
		if(throwNull())
			return WString::emptyStr;
		XERCES_CPP_NAMESPACE_QUALIFIER DOMAttr* da = GetDOMAttr(attrib.c_str(),nameSpaceURI.c_str());
		if(da!=0) 
			return da->getValue();

		JDFElement n=*this;

		// not in the leaf, recurse until root is found
		const JDFCh* nodeName=domElement->getNodeName();		
		while(42)
		{

			n=n.GetParentNode();
			if(n.isNull()) 
				break;
			if(wcscmp(n.domElement->getNodeName(),nodeName))
			{ 
				break;
			}
			da = n.GetDOMAttr(attrib.c_str(),nameSpaceURI.c_str());
			if(da!=0) 
				return da->getValue();
		}
		return def;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFResource::HasAttribute(const WString & attrib, const WString & nameSpaceURI,bool bInherit)const{ 
		if(bInherit){
			return GetInheritedAttribute(attrib,nameSpaceURI,WString::quote).compare(WString::quote)!=0;
		}else{
			return GetAttribute(attrib,nameSpaceURI,WString::quote).compare(WString::quote)!=0;
		}
	};


	//////////////////////////////////////////////////////////////////////


	int JDFResource::NumChildElements(const WString & nodeName,const WString & nameSpaceURI)const{
		int nE=JDFElement::NumChildElements(nodeName,nameSpaceURI);
		// elements do not override, i.e. if an element from a group exists, do not look below
		if(nE) 
			return nE;
		JDFResource n=GetParentNode();
		if(n.throwNull()) 
			return false;
		if(n.GetNodeName()!=GetNodeName()) 
			return 0;
		return n.NumChildElements(nodeName,nameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////

	KElement JDFResource::GetElement(const WString& nodeName,const WString & nameSpaceURI, int iSkip)const{
		if(throwNull()) 
			return KElement();

		KElement e=JDFElement::GetElement(nodeName,nameSpaceURI,iSkip);
		if(!e.isNull()) 
			return e;

		// only recurse if no element exists at all at this level
		if(!JDFElement::GetElement(nodeName,nameSpaceURI,0).isNull())
			return e;

		KElement parent=GetParentNode();
		if(parent.GetNodeName()!=GetNodeName())
			return KElement(); // res root

		// recurse 
		JDFResource parentResource=parent;
		return parentResource.GetElement(nodeName,nameSpaceURI,iSkip);

	}

	////////////////////////////////////////////////////////////////////////


	KElement JDFResource::RemoveChild(const WString & node, const WString & nameSpaceURI, unsigned int n){
		vElement v=GetChildElementVector(node,nameSpaceURI);

		if(n>=v.size())
			return KElement();

		// tbd clean up
		GetOwnerDocument().ClearTargets();
		// may NOT call removeChild since JDFResource calls to this routine may actually change the parent
		return v[n].DeleteNode();
	}

	//////////////////////////////////////////////////////////////////////


	void JDFResource::RemoveChildren(const WString&  nodeName,const WString & nameSpaceURI){
		// the loop allows jdf resources to recursively remove all children
		while(42){
			vElement v=GetChildElementVector(nodeName,nameSpaceURI);
			if(v.size()){
				for(int i=0;i<v.size();i++){
					// may NOT call removeChild since JDFResource calls to this routine may actually change the parent
					v[i].DeleteNode();
				}
				GetOwnerDocument().ClearTargets();
			}else{
				return;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////

	KElement JDFResource::GetCreateElement(const WString & nodeName, const WString & nameSpaceURI, int iSkip){

		if(throwNull()) 
			return KElement();

		JDFElement e=JDFElement::GetElement(nodeName,nameSpaceURI,iSkip);
		if(!e.isNull()) 
			return e;

		// 250202 RP changed functionality to append in case the leaf does not have it
		// brand new for partitions!
		return AppendElement(nodeName,nameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////

	vElement JDFResource::AddPartitions(EnumPartIDKey partType, const vWString & values){
		if(IsResourceElement()){
			throw JDFException(L"Attempting to add partition to resource element: "+GetXPath());
		}
		vElement v;
		if(HasPartIDKey(partType)) 
			return v;

		AddPartIDKey(partType);

		vElement vLeaves=GetLeaves();
		for(int i=0;i<vLeaves.size();i++){
			for(int j=0;j<values.size();j++){
				JDFResource p=vLeaves[i].AppendElement(GetNodeName());
				v.push_back(p);
				p.SetPartIDKey(partType,values[j]);
			}
		}
		return v;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFResource::HasPartIDKey(EnumPartIDKey key)const{
		return HasAttribute(PartIDKeyString(key));
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFResource::HasPipePartIDKey(EnumPartIDKey key)const{
		return HasAttribute(PartIDKeyString(key));
	}
	//////////////////////////////////////////////////////////////////////
	void JDFResource::SetPipePartIDKey(EnumPartIDKey key, const WString&value ){
		SetAttribute(PartIDKeyString(key),value);
		AddPipePartIDKey(key);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFResource::SetPartIDKey(EnumPartIDKey key, const WString&value ){
		SetAttribute(PartIDKeyString(key),value);
		AddPartIDKey(key);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFResource::ConsistentPartIDKeys(EnumPartIDKey key)const{
		WString s=PartIDKeyString(key);
		if(IsResourceElement()){
			return !HasAttribute(s);		
		}
		int nDepth=0;
		JDFResource r=*this;
		JDFResource root=GetResourceRoot();
		vWString partIDKeys=root.GetPartIDKeys();
		// the key exists but is not in PartIDKeys, oops
		int index=partIDKeys.index(s);
		if(index<0)
			return !HasAttribute(s);

		while(r!=root){
			nDepth++;
			r=r.GetParentNode();
			if(r.isNull()) // should never happen
				break;
		}
		if(partIDKeys.size()<nDepth)
			return false;

		KElement e=*this;
		// loop down to the resource root, checking whether exactly those attributes required exist
		for(int i=nDepth-1;i>=-1;i--){
			if((i==index)&&!e.HasAttribute(s))
				return false;
			if((i!=index)&&e.HasAttribute(s))
				return false;
			if(i>-1)
				e=e.GetParentNode();
		}
		// all is well
		return true;
	};

	//////////////////////////////////////////////////////////////////////

	JDFResource::EnumPartIDKey JDFResource::GetPartIDKeyEnum(const WString& key){
		int i=PartIDKeyString().PosOfToken(key,WString::comma);
		if(i<0) 
			throw JDFException(L"JDFResource::GetPartIDKeyEnum: illegal key:"+key);

		return (EnumPartIDKey)i;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFResource::ConsistentPipePartIDKeys(EnumPartIDKey key)const{
		WString s=PartIDKeyString(key);
		if(!HasAttribute(s))
			return true;

		// the key exists but is not in PipePartIDKeys, oops
		if(!GetResourceRoot().GetAttribute(atr_PipePartIDKeys).HasToken(s))
			return false;
		// all is well
		return true;
	};

	//////////////////////////////////////////////////////////////////////

	JDFResource::EnumPartIDKey JDFResource::GetPipePartIDKeyEnum(const WString& key){
		int i=PartIDKeyString().PosOfToken(key,WString::comma);
		if(i<0) 
			throw JDFException(L"JDFResource::GetPipePartIDKeyEnum: illegal key:"+key);

		return (EnumPartIDKey)i;
	};

	//////////////////////////////////////////////////////////////////////

	JDFResource JDFResource::AddPartition(EnumPartIDKey partType, const WString & value){
		if(IsResourceElement())
		{
			throw JDFException("Attempting to add partition to resource element");
		}
		if(partType==PartIDKey_Unknown)
		{
			throw JDFException("Attempting to add null partition to resource");            
		}


		vWString vs=GetPartIDKeys();
		int posOfType = vs.empty() ? -1 : vs.index(PartIDKeyString(partType));
		if(posOfType<0)
		{
			if(!IsLeaf())
				throw JDFException("addPartion: adding inconsistent partition - must be a leaf");
		}
		else if(posOfType==0)
		{
			if(!IsResourceRootRoot())
				throw JDFException("addPartion: adding inconsistent partition - must be root");            
		}
		else
		{
			WString parentPart=vs.stringAt(posOfType-1);
			if(!HasAttribute(parentPart,WString::emptyStr,false))
				throw JDFException("addPartion: adding inconsistent partition - parent must have partIDKey: "+parentPart);
		}
		if (!HasAttribute(PartIDKeyString(partType), WString::emptyStr, false))
		{
			AddPartIDKey(partType);
		}
		JDFResource p = (JDFResource) AppendElement(GetNodeName(), WString::emptyStr);

		if (!p.isNull())
		{
			p.SetPartIDKey(partType, value);
		}

		return p;
	}

	//////////////////////////////////////////////////////////////////////

	int JDFResource::NumAttributes()const{
		return GetAttributeVector().size();
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFResource::GetAttributeVector()const{
		vWString v;
		if(throwNull()) 
			return v;
		v=JDFElement::GetAttributeVector();
		// must cast do
		JDFResource n=GetParentNode();
		if(n.GetNodeName()!=GetNodeName()) 
			return v;
		v.AppendUnique(n.GetAttributeVector());
		return v;
	}
	//////////////////////////////////////////////////////////////////////


	JDFResource JDFResource::GetAttributePart(const WString &key)const{
		// tbd check whether this calls the correct virtual function
		if(((JDFElement*)this)->HasAttribute(key)) 
			return *this;
		JDFResource n=GetParentNode();
		if(n.throwNull()) 
			return JDFResource();
		if(n.GetNodeName()!=GetNodeName()) 
			return JDFResource();
		return n.GetAttributePart(key);
	}

	///////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetAttributePartVector(const WString &key)const{
		vElement leaves=GetLeaves();
		vElement v;
		for (int i=0;i<leaves.size();i++){
			JDFResource p=JDFResource(leaves.at(i)).GetAttributePart(key);
			if(p.isNull()) continue;
			v.AppendUnique(p);
		}
		return v;
	}

	///////////////////////////////////////////////////////////////////////

	void JDFResource::RemoveAttribute(const WString & attrib, const WString & nameSpaceURI){
		if(((KElement*)this)->HasAttribute(attrib,nameSpaceURI)){
			KElement::RemoveAttribute(attrib);
		}
	};

	///////////////////////////////////////////////////////////////////////
	void JDFResource::RemoveAttributeFromLeaves(const WString &  attrib, const WString & nameSpaceURI)
	{
		vElement v=GetLeaves(true);
		v.RemoveAttribute(attrib,nameSpaceURI);
	}


	///////////////////////////////////////////////////////////////////////

	void JDFResource::ReducePartitions(const vmAttribute & vValidParts){
		if(vValidParts.empty()) 
			return;
		vWString vPartIDKeys=GetPartIDKeys();
		if (vPartIDKeys.size() <= 0) 
			return;

		bool ciao=false;
		vElement leaves=GetLeaves();
		WString nodeName=GetNodeName();
		// loop over all leaves of this resource
		for(int i=0;i<leaves.size();i++){
			bool bOK=false;
			JDFResource leaf=leaves[i];
			mAttribute leafMap=leaf.GetPartMap();
			for(int j=0;j<vValidParts.size();j++){
				// the partition of this resource is included in the part vector --> keep it
				if (leafMap.OverlapMap(vValidParts[j])) {
					bOK=true;
					break;
				}
			}
			// don't keep this leaf
			if(!bOK){
				leaf.DeleteNode();
				ciao=true;
			}
		}

		// i removed some, lets see if some of the parents were also bad
		if(ciao)
			ReducePartitions(vValidParts);

	}

	///////////////////////////////////////////////////////////////////////

	void JDFResource::Expand(bool bDeleteFromNode){
		if(throwNull())
			return;

		vElement leaves=GetLeaves();
		WString nodeName=GetNodeName();

		vWString parts=GetPartIDKeys();
		parts.push_back(atr_ID);
		parts.push_back(atr_Class);
		parts.push_back(atr_Status);
		parts.push_back(atr_PartIDKeys);

		int leafSize=leaves.size();
		for(int i=0;i<leafSize;i++){
			JDFResource leaf=leaves[i];
			vWString atts=leaf.GetAttributeVector();
			int j;
			for(j=0;j<atts.size();j++){
				WString &aj=atts[j];
				if(parts.hasString(aj)) 
					continue; 
				leaf.SetAttribute(aj,leaf.GetAttribute(aj));
			}

			// expand sub-elements - since 190602
			vElement vElm=leaf.GetChildElementVector();
			JDFElement leafElm=leaf;
			for(j=0;j<vElm.size();j++){
				WString name=vElm[j].GetNodeName();
				// copy non existing element to leaf
				if(!leafElm.HasChildElement(name)){
					vElement vCopy=leaf.GetChildElementVector(name);
					for(int k=0;k<vCopy.size();k++){
						leaf.CopyElement(vCopy[k]);
					}
				}
			}
		}

		if(bDeleteFromNode){
			for(int i=0;i<leafSize;i++){
				JDFElement r=leaves[i].GetParentNode();
				while(42){
					if(r.throwNull()) 
						break;
					if(r.GetNodeName()!=nodeName)
						break;

					vWString atts=r.GetAttributeVector();
					int j;
					for(j=0;j<atts.size();j++){
						WString &aj=atts[j];
						if(parts.hasString(aj)) 
							continue; 
						r.RemoveAttribute(aj);
					}

					// delete all intermediate elements
					vElement vElm=r.GetChildElementVector();
					for(j=0;j<vElm.size();j++){
						if(vElm[j].GetNodeName()==nodeName)
							continue;
						vElm[j].DeleteNode();
					}

					if(r==*this)
						break;
					r=r.GetParentNode();
				}			
			}
		}	
	}

	///////////////////////////////////////////////////////////////////////

	vmAttribute JDFResource::ReducePartVector(const vmAttribute& vParts)const{
		vmAttribute vTest=vParts;

		// reduce vParts internally
		for(int i=0;i<vTest.size();i++){
			mAttribute partMapi=vTest[i];
			for(int j=vTest.size()-1;j>i;j--){
				mAttribute partMapj=vTest[j];
				if(partMapj.SubMap(partMapi)){
					vTest.erase(vTest.begin()+j);
				}else if(partMapi.SubMap(partMapj)){
					vTest.erase(vTest.begin()+i);
					i--; // we erased x(i) and now have to undo i++ of the loop
					break;
				}
			}
		}


		// this loop allows for arbitrary ordering of the incoming maps and handles side effects
		while(42){
			bool bChanged=false;
			// loop over all partitions of the vector
			for(int i=0;i<vTest.size();i++){
				mAttribute partMapi=vTest[i];
				JDFResource r=GetPartition(partMapi,PartUsage_Explicit);

				if(r.isNull()){ // this partition does not exist; remove it
					vTest.erase(vTest.begin()+i);
					i--; // we erased i which moves i+1 to i which has to be checked
					continue;
				}
				// if the root is included, all others are by default also included
				if(r.IsResourceRoot()){
					vTest.clear();
					vTest.push_back(mAttribute());
					return vTest;
				}

				// check whether all children of parent are included in vTest
				JDFElement parentElm=r.GetParentNode();

				// must be element, since the resource version of GetChildElementVector skips partition nodes
				vElement vKids=parentElm.GetChildElementVector(GetNodeName());

				// remember idix of vtmp
				vint vTmp;
				for(int j=0;j<vKids.size();j++){
					mAttribute kidMap=JDFResource(vKids.at(j)).GetPartMap();
					int index=vTest.index(kidMap);
					if(index>=0){
						vTmp.push_back(index);
					}else{
						// we found a child in the resource that is not in vTest, --> we cannot consolidate
						vTmp.clear();
						break;
					}
				}

				// all children are accounted for; replace them with parent
				if(!vTmp.empty()){
					// we have to sort and go backwards; otherwise we invalidate the indices in vTmp
					for(int k=vTmp.size()-1;k>=0;k--){				
						int mymax=-1;
						int posMax=-1;
						for(int kk=0;kk<vTmp.size();kk++){
							if(vTmp[kk]>mymax){
								mymax=vTmp[kk];
								posMax=kk;
							}
						}
						// remove all kids
						vTest.erase(vTest.begin()+mymax);
						vTmp.erase(vTmp.begin()+posMax);
					}
					// add parent
					JDFResource parent=parentElm;
					vTest.push_back(parent.GetPartMap());
					// we modified the vector and should recheck
					bChanged=true;
				}		
			}
			// we found nothing this time; done
			if(!bChanged){
				break;
			}
		}

		return vTest;
	}

	///////////////////////////////////////////////////////////////////////

	void JDFResource::Collapse(bool bCollapseToNode){
		if(throwNull())
			return;
		vElement leaves=GetLeaves();
		vWString parts=GetPartIDKeys();


		for(int i=0;i<leaves.size();i++){

			JDFResource leaf=leaves[i];
			if(leaf.IsResourceRoot()) 
				continue;

			vWString atts=leaf.GetAttributeVector();
			atts.RemoveStrings("ID");
			atts.RemoveStrings("PartIDKeys");
			atts.RemoveStrings(parts);

			JDFResource parent=leaf.GetParentNode();
			while(42){
				JDFElement leafElm=leaf; 
				JDFElement parentElm=parent;

				vElement localLeaves=parentElm.GetChildElementVector(GetNodeName());
				int localSize=localLeaves.size();

				int j;
				for(j=0;j<atts.size();j++){
					WString att=atts[j];

					// reduce lower stuff
					if((!bCollapseToNode)&&(!parentElm.HasAttribute(att))){
						WString attVal=leafElm.GetAttribute(att);
						//Matt-Start
						if(parentElm.GetAttribute(att)!=attVal){
							//Matt-End

							// check all local children and grandchildren
							bool bAllSame=true;
							for(int l=0;l<localSize;l++){
								if(localLeaves[l].GetAttribute(att)!=attVal){
									bAllSame=false;
									break;
								}
							}
							//Matt-Start
							if(bAllSame){
								parentElm.SetAttribute(att,attVal);
								// remove from all leaves...
								for (int l=0;l<localSize;l++){
									localLeaves[l].RemoveAttribute(att);
								}
							}
							//Matt-End
						}
					}

					// remove leaf element attribute if it is defined lower in the tree
					if(leafElm.GetAttribute(att)==parent.GetAttribute(att)) 
						leafElm.RemoveAttribute(att);

				}

				// since 190602 also collapse elements
				vElement vElm=leaf.GetChildElementVector();
				for(j=0;j<vElm.size();j++){
					WString name=vElm[j].GetNodeName();

					vElement vParentElm=parent.GetChildElementVector(name);
					vElement vLocalElm=leafElm.GetChildElementVector(name);

					// vector of elements for the first leaf
					// this is reused for comparison since all leaves must be equal
					vElement localNamedElements0=localLeaves[0].GetChildElementVector(name);
					int elm0Size=localNamedElements0.size();


					// true if all elements of all local leaves are equal and in the correct sequence
					// if elm0size==0 we have nothing to do - leave loop
					bool bElmEqual=elm0Size>0;

					// only collapse if pre-existing elements exist in the nodes
					if(bCollapseToNode&&bElmEqual){
						if(elm0Size==vParentElm.size()){
							// loop over all elements of leaf 0 and compare with the parent leaf
							for(int kk=0;kk<elm0Size;kk++){
								if(!localNamedElements0[kk].IsEqual(vParentElm[kk])){
									bElmEqual=false;
									break;
								}
							}
						}else{
							bElmEqual=false;
						}
					}

					if(bElmEqual){
						// loop over all local leaves except 0 (which is the one we compare to)
						for(int k=1;k<localSize;k++){
							// vector of elements for leaf k.
							vElement localNamedElements=localLeaves[k].GetChildElementVector(name);

							// not equal if a different number of elements exists
							if(localNamedElements.size()!=elm0Size){
								bElmEqual=false;
								break;
							}

							// the number of elements is identical, now compare each one individually
							// note that the sequence is important and thus we don't have to check ordering permutations
							for(int kk=0;kk<elm0Size;kk++){
								if(!localNamedElements0[kk].IsEqual(localNamedElements[kk])){
									bElmEqual=false;
									break;
								}
							}
							// rebreak if not equal
							if(!bElmEqual)
								break;
						}
					}

					// all are identical --> zapp em
					if(bElmEqual){
						// delete all intermediate children before copying
						if(!bCollapseToNode){
							parentElm.RemoveChildren(name);
							for(int k=0;k<elm0Size;k++){
								parent.CopyElement(localNamedElements0[k]);
							}
						}
						for(int kk=0;kk<localSize;kk++)
							localLeaves[kk].RemoveChildren(name);

						// not all children are equal, but maybe this one individual; if so -> ciao 
					}else if(vParentElm.size()==vLocalElm.size()){
						bool bZappEm=(vParentElm.size()>0);
						for(int k=0;k<vParentElm.size();k++){
							if(!vParentElm[k].IsEqual(vLocalElm[k])){
								bZappEm=false;
								break;
							}
						}
						// this leaves elements are all identical and in the same sequence; we can inherit so zapp em
						if(bZappEm)
							leafElm.RemoveChildren(name);

					}
				}
				if(parent.IsResourceRoot()||(parent==*this))
					break;

				leaf=parent;
				parent=parent.GetParentNode();
			}
		}
	}

	///////////////////////////////////////////////////////////////////////

	void JDFResource::MergeSpawnIDs(const JDFResource& resToMerge,const vWString&previousMergeIDs){

		if(GetID()!=resToMerge.GetID()){
			throw JDFException(L"JDFResource::MergeSpawnIDs  merging incompatible resources ID="+GetID()+L" IDMerge="+resToMerge.GetID());
		}
		vElement allNodes=GetLeaves(true);
		for(int i=0;i<allNodes.size();i++){
			JDFResource thisResNode=allNodes[i];
			JDFResource mergeResNode=resToMerge.GetPartition(thisResNode.GetPartMap(),PartUsage_Explicit);
			if(!mergeResNode.isNull()){
				vWString vPartIDKeys=thisResNode.GetSpawnIDs(false);
				int siz=vPartIDKeys.size();
				vPartIDKeys.AppendUnique(mergeResNode.GetSpawnIDs(false));
				vPartIDKeys.RemoveStrings(previousMergeIDs);

				if(vPartIDKeys.empty()){
					thisResNode.RemoveAttribute(atr_SpawnIDs);
					thisResNode.RemoveAttribute(atr_SpawnStatus);
				}else{
					// AppendUnique modified the vector
					if(siz!=vPartIDKeys.size()){
						thisResNode.SetSpawnIDs(vPartIDKeys);
						// one of the spawnstatus elements was rw, must also be valid here
						if(mergeResNode.GetSpawnStatus()==JDFResource::SpawnStatus_SpawnedRW){
							thisResNode.SetSpawnStatus(SpawnStatus_SpawnedRW);
						}else if((mergeResNode.GetSpawnStatus()==JDFResource::SpawnStatus_SpawnedRO) &&
							(thisResNode.GetSpawnStatus()!=JDFResource::SpawnStatus_SpawnedRW) ){
								thisResNode.SetSpawnStatus(SpawnStatus_SpawnedRO);
						}
					}
				}
			}
		}
	}

	///////////////////////////////////////////////////////////////////////

	void JDFResource::UpdateAmounts(double previousAmount){
		vElement resLinks=GetLinks(GetLinkString());
		mAttribute partMap=GetPartMap();
		int linkSize=resLinks.size();
		double deltaAmount=previousAmount;
		if(previousAmount<0)
			deltaAmount=GetAmount();

		double amount=0;
		double amountProduced=0;
		double amountRequired=0;

		// if no output resourcelinks exist, assume that
		bool hasOutputLink=false;
		bool mustWrite=HasAttribute(atr_Amount);
		for(int i=0;i<linkSize;i++){
			JDFResourceLink rl=resLinks[i];
			JDFNode n=rl.GetParentJDF();
			if(n.throwNull())
				continue;
			JDFNode::EnumType typ=n.GetEnumType();
			if(typ==JDFNode::Type_ProcessGroup||typ==JDFNode::Type_Product)
				continue;

			double ca=rl.GetActualAmount(partMap);
			double a=rl.GetAmount(partMap);

			if(rl.GetUsage()==JDFResourceLink::Usage_Input){
				if(ca>0)
					amount-=ca;
				if(a>0)
					amountRequired+=a;
				if((ca>=0)||(a>=0))
					mustWrite=true;
			}else{
				if(ca>=0){
					mustWrite=true;
					amount+=ca;
					amountProduced+=ca;
				}
				hasOutputLink=true;
			}
		}

		// only update the amounts by the previous values if no output creates the resource, e.g. consumables
		if(!hasOutputLink)
			amount+=deltaAmount;

		if(mustWrite){
			if(amount>0)
				SetAmount(amount);
			if(amountProduced>0)
				SetAmountProduced(amountProduced);
			if(amountRequired>0)
				SetAmountRequired(amountRequired);
		}
	}

	///////////////////////////////////////////////////////////////////////

	void JDFResource::MergePartition (const JDFResource& resToMerge, const WString & spawnID, EnumAmountMerge amountPolicy, bool bLocalResource){

		if(GetID()!=resToMerge.GetID()){
			throw JDFException(L"JDFResource::MergePartition  merging incompatible resources ID="+GetID()+L" IDMerge="+resToMerge.GetID());
		}
		/// TBD RP SpawnStatus Handling!!!!
		JDFResource toMerge=resToMerge;
		JDFResource root=GetResourceRoot();

		vWString partIDKeys = root.GetPartIDKeys();
		vWString mergeIDKeys = toMerge.GetPartIDKeys();
		partIDKeys.AppendUnique (mergeIDKeys);
		if(partIDKeys.empty()){
			root.RemoveAttribute(atr_PartIDKeys);
		}else{
			root.SetAttribute(atr_PartIDKeys,partIDKeys);
		}

		vElement allChildren=resToMerge.GetNodesWithSpawnID(spawnID);

		// No spawntargets take all
		if(allChildren.empty()){
			allChildren.push_back(toMerge);
		}

		bool bTargetGone=false;

		for (int i = 0; i < allChildren.size(); i++){
			JDFResource src = allChildren[i];
			mAttribute srcMap = src.GetPartMap();
			JDFResource trg = GetPartition (srcMap, PartUsage_Implicit);
			mAttribute trgMap=trg.GetPartMap();

			// RP 220605 - not puristic, but pragmatic
			// found only a root or high level partition for an rw resource partition
			// try to create the new partition and pray that it will not be subsequently completely overwritten
			// this is still better than throwing an exception or silently ignoring the rw resource
			if((src.GetLocked()==false)&&(trgMap.GetKeys().size()<srcMap.GetKeys().size())){
				trg=GetCreatePartition(srcMap,partIDKeys);
				// fool the algorithm to think that the new partition is rw (which it probably was)
				trg.SetSpawnStatus(JDFResource::SpawnStatus_SpawnedRW);
				trgMap=trg.GetPartMap();
			}

			if (trg.isNull()){
				trg=*this;
			}
			// 131204 RP added check for local resources so that they always get merged
			if (bLocalResource||(trg.GetSpawnStatus() == JDFResource::SpawnStatus_SpawnedRW)){
				if(!bTargetGone){
					if(srcMap==trgMap){
						if(trgMap.empty()){ // we actually replaced the root nothing left to do
							bTargetGone=true;
							ReplaceElement(src);
						}else{
							//						trg.ReplaceElement(trg.GetParentNode().CopyElement(src));
							trg.ReplaceElement(trg.CopyElement(src));
						}
					}else if(srcMap.SubMap(trgMap)){
						// potential check for very deep src
						trg.CopyElement(src);
					}else{ // oops
						throw JDFException("JDFResource::MergePartition attempting to merge incompatible partitions");
					}
				}	
			}

			// update the partitions amounts
			if((amountPolicy!=AmountMerge_None)&&IsPhysical()){
				JDFResource trgKeep = trg;
				trg = root.GetPartition(srcMap, JDFResource::PartUsage_Explicit);
				if (trg.isNull())
				{
					trg = trgKeep;
				}
				vElement vr=trg.GetLeaves(true);
				for(int l=0;l<vr.size();l++){
					double amount=0;
					JDFResource r=vr.at(l);
					if(amountPolicy!=AmountMerge_LinkOnly)
						amount=r.GetAmount();
					r.UpdateAmounts(amount);
				}
			}
		}
		// some crap is left - remove it
		if(!bTargetGone){
			toMerge.DeleteNode();
		}
	}

	///////////////////////////////////////////////////////////////////////

	WString JDFResource::OptionalAttributes()const{
		static const WString optionalAttributes=L",AgentName,AgentVersion,Author,CatalogID,CatalogDetails,Locked,PipeID,PipeProtocol,PipeURL,ProductID,rRefs,Sorting,SortAmount,PartIDKeys,PipePartIDKeys,SpawnStatus,SpawnIDs";
		WString s=JDFElement::OptionalAttributes()+optionalAttributes;
		if(IsPhysical()) {
			static const WString physicalAttributes=L",AlternateBrand,Amount,AmountProduced,AmountRequired,BatchID,Brand,GrossWeight,LotControl,Manufacturer,ResourceWeight,Unit";
			s+=physicalAttributes;
		}else if(IsParameter()){
			static const WString parameterAttributes=L",NoOp";
			s+=parameterAttributes;
		}

		if(!IsResourceRootRoot()){
			if(IsResourceElement()){
				static const WString intermediateAttributes=L",ID,Class";
				s+=intermediateAttributes;
			}else if(IsResourceRoot()){
				static const WString intermediateAttributes=L",ID,Class,Status,PartUsage";
				s+=intermediateAttributes;
			}else{ // partition leaves or nodes
				static const WString resourceElementAttributes=L",Status";
				s+=resourceElementAttributes;
			}
		}else{
			static const WString pu=L",PartUsage";
			s+=pu;
		}
		if(!IsResourceUpdate()){ 
			static const WString updateAttributes=L",UpdateID";
			s+=updateAttributes;
		}

		s+=PartAttributes();
		return s;
	};

	///////////////////////////////////////////////////////////////////////

	WString JDFResource::RequiredAttributes()const{
		WString s=JDFElement::RequiredAttributes();
		// rp 260402 modified
		if(IsResourceUpdate()){ 
			static const WString uid=L",UpdateID";
			s+=uid;
		}
		if(IsResourceRootRoot()){
			static const WString cis=L",Class,ID,Status";
			s+=cis;
		}
		return s;
	};

	///////////////////////////////////////////////////////////////////////

	WString JDFResource::PartAttributes()const{
		vWString vs=GetPartIDKeys();
		if(vs.empty())
			return WString::emptyStr;

		WString s;
		vWString vPartIDKeys=PartIDKeyString().Tokenize(WString::comma);
		for(int i=0;i<vs.size();i++){
			if(vPartIDKeys.hasString(vs[i])){
				s+=WString::comma+vs[i];
			}
		}
		return s;
	}

	///////////////////////////////////////////////////////////////////////
	WString JDFResource::OptionalElements()const{
		// 270302 RP added Resourceupdate handling
		WString s=JDFElement::OptionalElements()+WString::comma+GetUpdateName()+L",QuantityControlResult,SourceResource,GeneralID,Identical";
		if (GetResourceRoot().HasAttribute(atr_PartIDKeys)) 
			s+= WString::comma + GetNodeName();
		if(IsPhysical()) 
			s+=L",Location,Contact,IdentificationField";
		return s;
	};

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidAgentName(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentName,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidAgentVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentVersion,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidAuthor(EnumValidationLevel level) const {
		return ValidAttribute(atr_Author,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidCatalogID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CatalogID,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidCatalogDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_CatalogDetails,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidClass(EnumValidationLevel level) const {
		if(!IsResourceRootRoot()&&!IsResourceElement()&&KElement::HasAttribute(atr_Class))
			return false;
		return ValidEnumAttribute(atr_Class,ClassString(),RequiredLevel(level)&&IsResourceRootRoot());
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidID(EnumValidationLevel level) const {
		//	if(!IsResourceRootRoot()&&KElement::HasAttribute(atr_ID))
		//		return false;
		return ValidAttribute(atr_ID,AttributeType_ID,RequiredLevel(level)&&IsResourceRootRoot());
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidLocked(EnumValidationLevel level) const {
		return ValidAttribute(atr_Locked,AttributeType_boolean,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPipeID(EnumValidationLevel level) const {
		return ValidAttribute(atr_PipeID,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPartUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PartUsage,PartUsageString(),false);
	};
	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidLotControl(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_LotControl,LotControlString(),false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPipeProtocol(EnumValidationLevel level) const {
		return ValidAttribute(atr_PipeProtocol,AttributeType_NMTOKEN,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidProductID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductID,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPipeURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_PipeURL,AttributeType_URL,false);
	};

	////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidrRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRefs,AttributeType_NMTOKENS,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSpawnIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpawnIDs,AttributeType_NMTOKENS,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSpawnStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SpawnStatus,SpawnStatusString(),false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),RequiredLevel(level)&&IsResourceRootRoot());
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidUpdateID(EnumValidationLevel level) const{
		return ValidAttribute(atr_UpdateID,AttributeType_NMTOKEN,false);
	};

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidNoOp(EnumValidationLevel level) const{
		return ValidAttribute(atr_NoOp,AttributeType_boolean,false);
	};

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPartIDKeys(EnumValidationLevel level) const{	
		if(KElement::HasAttribute(atr_PartIDKeys)&&!IsResourceRootRoot())
			return false;
		return ValidEnumerationsAttribute(atr_PartIDKeys,PartIDKeyString(),false);			
	}
	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPipePartIDKeys(EnumValidationLevel level) const{	
		if(KElement::HasAttribute(atr_PipePartIDKeys)&&!IsResourceRootRoot())
			return false;
		return ValidEnumerationsAttribute(atr_PipePartIDKeys,PartIDKeyString(),false);			
	}

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidAlternateBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_AlternateBrand,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Amount,AttributeType_double,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidAmountProduced(EnumValidationLevel level) const {
		return ValidAttribute(atr_AmountProduced,AttributeType_double,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidAmountRequired(EnumValidationLevel level) const {
		return ValidAttribute(atr_AmountRequired,AttributeType_double,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidBatchID(EnumValidationLevel level) const {
		return ValidAttribute(atr_BatchID,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_Brand,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidManufacturer(EnumValidationLevel level) const {
		return ValidAttribute(atr_Manufacturer,AttributeType_string,false);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidResourceWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceWeight,AttributeType_double,false);
	};
	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidGrossWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_GrossWeight,AttributeType_double,false);
	};
	///////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidUnit(EnumValidationLevel level) const {
		return ValidAttribute(atr_Unit,AttributeType_NMTOKEN,false);
	};

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSorting(EnumValidationLevel level) const {
		return ValidAttribute(atr_Sorting,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSortAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_SortAmount,AttributeType_boolean,false);
	};
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidBinderySignatureName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BinderySignatureName,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidBlockName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockName,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidBundleItemIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_BundleItemIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidCellIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_CellIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidCondition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Condition,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidDocCopies(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocCopies,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidDocIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidDocRunIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocRunIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidDocSheetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocSheetIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidFountainNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_FountainNumber,AttributeType_integer,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidItemNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_ItemNames,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidLayerIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayerIDs,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidLocation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Location,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidOption(EnumValidationLevel level) const {
		return ValidAttribute(atr_Option,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPageNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageNumber,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPartVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_PartVersion,AttributeType_NMTOKENS,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPreflightRule(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreflightRule,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidPreviewType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreviewType,((JDFPart*)this)->PreviewTypeString(),false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidRibbonName(EnumValidationLevel level) const {
		return ValidAttribute(atr_RibbonName,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidRun(EnumValidationLevel level) const {
		return ValidAttribute(atr_Run,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidRunIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidRunTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunTags,AttributeType_NMTOKENS,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidRunPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunPage,AttributeType_integer,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSectionIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SectionIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSeparation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Separation,AttributeType_Any,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSetDocIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetDocIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSetRunIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetRunIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSetSheetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetSheetIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSheetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetIndex,AttributeType_IntegerRangeList,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSheetName(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetName,AttributeType_Any,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Side,((JDFPart*)this)->SideString(),false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidSignatureName(EnumValidationLevel level) const {
		return ValidAttribute(atr_SignatureName,AttributeType_Any,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidTileID(EnumValidationLevel level) const {
		return ValidAttribute(atr_TileID,AttributeType_XYPair,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidWebName(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebName,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidWebProduct(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebProduct,AttributeType_NMTOKEN,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFResource::ValidWebSetup(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebSetup,AttributeType_NMTOKEN,false);
	};
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////

	const WString& JDFResource::ValidParentNodeNames(){
		static const WString nodeNames=ValidRootParentNodeNames()+L",Ancestor,DropItemIntent,DropItem,ProductionIntent,CustomerInfo,NodeInfo,DeviceInfo,PhaseTime";
		return nodeNames;
	}

	///////////////////////////////////////////////////////////////////////
	const WString& JDFResource::ValidRootParentNodeNames(){
		static const WString nodeNames=L"ResourcePool,PipeParams,ResourceCmdParams,ResourceInfo";
		return nodeNames;
	}

	///////////////////////////////////////////////////////////////////////
	bool JDFResource::IsResource(bool createFactory)const{
		if(throwNull())
			return false;
		return true;
	}
	///////////////////////////////////////////////////////////////////////

	bool JDFResource::IsResourceRoot()const{
		if(throwNull())
			return false;
		JDFElement parentNode=GetParentNode();
		if(parentNode.isNull())
			return true;

		if(parentNode.GetNodeName()==GetNodeName())
			return false;

		// special handling for NI and CI as resources
		const WString locName = parentNode.GetLocalName();
		if(locName==elm_NodeInfo||locName==elm_CustomerInfo)
		{
			if (!GetResourcePool().isNull())
				return false;
		}

		return ValidParentNodeNames().HasToken(locName,WString::comma);
	};

	///////////////////////////////////////////////////////////////////////

	bool JDFResource::IsResourceRootRoot()const{
		if(throwNull())
			return false;
		JDFElement parentNode=GetParentNode();
		if(parentNode.isNull())
			return true;
		if(parentNode.GetNodeName()==GetNodeName())
			return false;
		return ValidRootParentNodeNames().HasToken(parentNode.GetLocalName(),WString::comma);
	};

	///////////////////////////////////////////////////////////////////////

	bool JDFResource::IsResourceElement()const{
		if(throwNull())
			return false;
		const WString par=GetDeepParentNotName(GetLocalName()).GetLocalName();

		return !ValidRootParentNodeNames().HasToken(par,WString::comma);
	};

	///////////////////////////////////////////////////////////////////////

	bool JDFResource::IsLeaf()const{
		if(throwNull())
			return false;
		return JDFElement::GetElement(GetNodeName()).isNull();
	};	

	///////////////////////////////////////////////////////////////////////

	bool JDFResource::IsRootElement()const{
		if(throwNull())
			return false;
		return GetNodeName()!=GetParentNode().GetNodeName();
	}

	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////

	JDFContact JDFResource::GetCreateContact(){
		JDFContact e=GetCreateElement(elm_Contact,WString::emptyStr);
		e.init();	
		return e;

	};
	/////////////////////////////////////////////////////////////////////
	JDFContact JDFResource::GetContact()const{
		return GetElement(elm_Contact,WString::emptyStr);
	};
	/////////////////////////////////////////////////////////////////////
	JDFContact JDFResource::AppendContact(){
		JDFContact e=AppendElementN(elm_Contact,1);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	JDFSourceResource JDFResource::GetSourceResource(int iSkip)const{
		JDFSourceResource e=GetElement(elm_SourceResource,WString::emptyStr,iSkip);
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFSourceResource JDFResource::GetCreateSourceResource(int iSkip){
		JDFSourceResource e=GetCreateElement(elm_SourceResource,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFSourceResource JDFResource::AppendSourceResource(){
		JDFSourceResource e=AppendElement(elm_SourceResource);
		e.init();
		return e;
	};	/////////////////////////////////////////////////////////////////////

	JDFLocation JDFResource::GetCreateLocationElement(){
		JDFLocation e=GetCreateElement(elm_Location,WString::emptyStr);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	JDFLocation JDFResource::GetLocationElement()const{
		return GetElement(elm_Location,WString::emptyStr);
	};
	/////////////////////////////////////////////////////////////////////

	JDFLocation JDFResource::AppendLocationElement(){
		JDFLocation e=AppendElementN(elm_Location,1);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFIdentificationField JDFResource::GetCreateIdentificationField(int iSkip){
		JDFIdentificationField e=GetCreateElement(elm_IdentificationField,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	JDFIdentificationField JDFResource::GetIdentificationField(int iSkip)const{
		return GetElement(elm_IdentificationField,WString::emptyStr,iSkip);
	};
	/////////////////////////////////////////////////////////////////////

	JDFIdentificationField JDFResource::AppendIdentificationField(){
		JDFIdentificationField e=AppendElement(elm_IdentificationField);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFQualityControlResult JDFResource::GetCreateQualityControlResult(int iSkip){
		JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	JDFQualityControlResult JDFResource::GetQualityControlResult(int iSkip)const{
		return GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	};
	/////////////////////////////////////////////////////////////////////

	JDFQualityControlResult JDFResource::AppendQualityControlResult(){
		JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	WString JDFResource::GetIDPrefix() const {
		static const WString r=L"r";
		return r;
	}


	/** 
	* Get the appropriate ResourceUpdate Element 
	* @param int iSkip number of elements to skip
	* @return JDFUpdate The element
	*/

	JDFResource JDFResource::GetUpdate(int iSkip)const{
		return GetElement(GetUpdateName(),WString::emptyStr,iSkip);
	}

	/**
	* Get the appropriate ResourceUpdate Element 
	* @param WString updateID ; UpdateID of the element to get
	* @return  JDFUpdate The element
	*/

	JDFResource JDFResource::GetUpdate(const WString& updateID)const{
		return GetChildWithAttribute(GetUpdateName(),atr_UpdateID,WString::emptyStr,updateID);
	};
	/**
	* Get the vector of ResourceUpdate Element a
	* @return  vElement The vector of elements
	*/

	vElement JDFResource::GetUpdateVector()const{
		return GetChildElementVector(GetUpdateName(),WString::emptyStr);
	}
	/**
	* Remove element Update
	* @param WString updateID ; UpdateID of the element to remove
	*/

	void JDFResource::RemoveUpdate(const WString & updateID){
		GetUpdate(updateID).DeleteNode();
	};
	/**
	* Remove element Update
	* @param int iSkip number of elements to skip
	*/

	void JDFResource::RemoveUpdate(int iSkip){
		GetUpdate(iSkip).DeleteNode();
	};
	/**
	* Append element Update
	*/

	JDFResource JDFResource::AppendUpdate(const WString& updateID){
		WString uid=updateID;
		JDFResource r;
		if(IsWildcard(updateID.c_str())){
			uid="Up"+UniqueID();
		}else{
			r=GetUpdate(updateID);
			if(!r.isNull()){
				throw JDFException(L"AppendUpdate: update with id="+updateID+L" exists!");
			}
		}
		r=AppendElement(GetUpdateName());
		r.SetUpdateID(uid);
		return r;
	};

	//////////////////////////////////////////////////////////////////////////////////

	int JDFResource::NumUpdates() const{
		return NumChildElements(GetUpdateName());
	};

	//////////////////////////////////////////////////////////////////////////////////

	WString JDFResource::GetUpdateName() const{
		return GetNodeName()+atr_Update;
	};

	//////////////////////////////////////////////////////////////////////////////////


	vElement JDFResource::GetChildElementVector(const WString & element, const WString & nameSpaceURI, const mAttribute &mAttrib, bool bAnd, unsigned int maxSize, bool bResolveTarget)const{
		if(throwNull()) 
			return vElement();

		vElement v= JDFElement::GetChildElementVector(element,nameSpaceURI,mAttrib,bAnd,maxSize,bResolveTarget);
		WString nodeName=GetNodeName();

		// remove partitions
		for(int i=v.size()-1;i>=0;i--){
			if (nodeName==v.at(i).GetNodeName()){
				v.erase(v.begin()+i);
			}
		}
		// 190602 RP added correct wildcard handling
		if((v.size()>0)&&(!IsWildcard(element.c_str())))
			return v;

		// no direct kids, check parents
		JDFElement n=GetParentNode();
		if(n.GetNodeName()!=GetNodeName())
			return v; // res root

		JDFResource r=n;

		// recurse into parents
		VElement v2=r.GetChildElementVector(element,nameSpaceURI,mAttrib,bAnd,maxSize,bResolveTarget);
		VString nodeNames=v.GetElementNameVector(false);
		for(int i=v2.size()-1;i>=0;i--)
		{
			if(nodeNames.contains(v2.item(i).GetLocalName()))
				v2.remove(i);
		}
		v.addAll(v2);
		return v;
	}

	//////////////////////////////////////////////////////////////////////////////////

	const WString& JDFResource::PartIDKeyString(){
		static const WString enums=
			WString(L"Unknown,BinderySignatureName,BlockName,BundleItemIndex,CellIndex,Condition,DocCopies,DocIndex,DocRunIndex,DocSheetIndex,ItemNames,FountainNumber,LayerIDs,Location,Option,PageNumber,PartVersion,PreflightRule,PreviewType,RibbonName")
			+	WString(L",Run,RunIndex,RunTags,RunPage,Separation,SectionIndex,SetDocIndex,SetIndex,SetRunIndex,SetSheetIndex,SheetIndex,SheetName,Side,SignatureName,TileID,WebName")
			+   WString(L",DeliveryUnit0,DeliveryUnit1,DeliveryUnit2,DeliveryUnit3,DeliveryUnit4,DeliveryUnit5,DeliveryUnit6,DeliveryUnit7,DeliveryUnit8,DeliveryUnit9,DocTags,Edition,EditionVersion,PageTags,PlateLayout,RunSet,SetTags,SubRun,WebProduct,WebSetup");

		return enums;
	};

	//////////////////////////////////////////////////////////////////////////////////

	WString JDFResource::PartIDKeyString(EnumPartIDKey value){
		return PartIDKeyString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////////////////

	const WString& JDFResource::PartUsageString(){
		static const WString enums=L"Unknown,Explicit,Sparse,Implicit"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////////////////

	WString JDFResource::PartUsageString(EnumPartUsage value){
		return PartUsageString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////////////////

	const WString& JDFResource::SpawnStatusString(){
		static const WString enums=L"Unknown,NotSpawned,SpawnedRO,SpawnedRW"; 
		return enums;
	};


	/**
	Enumeration string for enum value
	*/
	WString JDFResource::SpawnStatusString(EnumSpawnStatus value){
		return SpawnStatusString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////////////////
	const WString& JDFResource::StatusString(){
		static const WString enums=L"Unknown,Incomplete,Rejected,Unavailable,InUse,Draft,Complete,Available"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////////////////

	WString JDFResource::StatusString(EnumStatus value){
		return StatusString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////////////////

	const WString& JDFResource::ClassString(){
		static const WString enums=L"Unknown,Parameter,Handling,Consumable,Quantity,Implementation,PlaceHolder,Intent";
		return enums;
	};

	/**
	* Enumeration string for enum value
	*/
	WString JDFResource::ClassString(EnumClass value){
		return ClassString().Token(value,WString::comma);
	};
	//////////////////////////////////////////////////////////////////////////////////

	const WString& JDFResource::LotControlString(){
		static const WString enums=L"Unknown,Controlled,NotControlled";
		return enums;
	};

	/**
	* Enumeration string for enum value
	*/
	WString JDFResource::LotControlString(EnumLotControl value){
		return LotControlString().Token(value,WString::comma);
	};

	/**
	* Sets attribute LotControl
	*
	* @param EnumLotControl value: enumeration value of the attribute LotControl to be set
	*/
	void JDFResource::SetLotControl( EnumLotControl value){
		SetEnumAttribute(atr_LotControl,(int)value,LotControlString());
	}

	/**
	* Gets typesafe enumerated value of attribute LotControl; defaults to LotControl_Explicit
	*
	* @return EnumLotControl: attribute enumeration value
	*/
	JDFResource::EnumLotControl JDFResource::GetLotControl() const{
		return (EnumLotControl) GetEnumAttribute(atr_Class,LotControlString());
	}

	//////////////////////////////////////////////////////////////////////////////////

	void JDFResource::SpawnPart(const WString & spawnID, EnumSpawnStatus spawnStatus, const vmAttribute& vParts, bool bStayInMain){

		if(throwNull())
			return;

		if(vParts.size()){
			// lock the spawned root
			if(!bStayInMain){
				SetLocked(true);
			}
			// loop over all part maps to get best matching resource
			for(int j=0;j<vParts.size();j++){
				JDFResource pLeaf=GetPartition(vParts[j],PartUsage_Implicit);
				if(pLeaf!=0){
					// set the lock of the leaf to true if it is RO, else unlock it
					if(bStayInMain){
						pLeaf.SetSpawnStatus(spawnStatus);
						pLeaf.SetLocked(spawnStatus==SpawnStatus_SpawnedRW);
					}else{
						pLeaf.SetLocked(spawnStatus!=SpawnStatus_SpawnedRW);
					}
					pLeaf.AppendSpawnIDs(spawnID);
				}
			}		
		}else{
			if(bStayInMain){
				SetSpawnStatus(spawnStatus);
				SetLocked(spawnStatus==SpawnStatus_SpawnedRW);
			}else{
				SetLocked(spawnStatus!=SpawnStatus_SpawnedRW);
			}
			AppendSpawnIDs(spawnID);
		}
	}

	//////////////////////////////////////////////////////////////////////////////////

	void JDFResource::UnSpawnPart(const WString & spawnID, EnumSpawnStatus spawnStatus){

		if(throwNull())
			return;

		vElement vLeaves=GetNodesWithSpawnID(spawnID);
		for(int i=0;i<vLeaves.size();i++){
			JDFResource leaf=vLeaves[i];

			leaf.RemoveFromSpawnIDs(spawnID);
			if(spawnStatus==SpawnStatus_SpawnedRW){
				leaf.RemoveAttribute(atr_Locked);
			}

			if(!leaf.HasAttribute(atr_SpawnIDs)){
				leaf.RemoveAttribute(atr_SpawnStatus);
			}else if(spawnStatus==SpawnStatus_SpawnedRW){
				// we've removed the one and only rw, it can only be ro if anything is still left
				leaf.SetSpawnStatus(SpawnStatus_SpawnedRO);
			}
		}
	}

	//////////////////////////////////////////////////////////////////////////////////

	vElement JDFResource::GetNodesWithSpawnID(const WString& spawnID)const{
		vElement v=GetChildrenWithAttribute(GetNodeName(), atr_SpawnIDs, WString::emptyStr,WString::star, false);
		v.push_back(*this);
		for(int i=v.size()-1;i>=0;i--){
			JDFElement e=v[i];
			if(!e.IncludesMatchingAttribute(atr_SpawnIDs,spawnID,AttributeType_NMTOKENS)){
				v.erase(v.begin()+i);
			}
		}
		return v;
	}
	//////////////////////////////////////////////////////////////////////////////////

	WString JDFResource::NewModifiedID()const{

		WString id=GetID();
		WString postFix=id.rightStr(8);
		vWString siblingIDs=GetResourcePool().GetResIds();
		WString preFix=id;
		if(postFix.leftStr(5)==L"_old_"){
			preFix=id.leftStr(-8);
		}
		int siz=siblingIDs.size();
		char buf[10];
		for(int i=1;i<1000;i++){
			sprintf(buf,"_old_%.3i",i);
			WString newModifiedID = preFix + (const char*) buf;
			bool bFound=false;
			for(int j=0;j<siz;j++){
				if(newModifiedID==siblingIDs[j]){
					bFound=true;
					break; // j
				}
			}
			if(!bFound){
				return newModifiedID;
			}
		}
		throw JDFException(L" JDFResource::NewModifiedID too many equivalent modified resources! Resource ID="+id);
		return WString::emptyStr;
	}



	//////////////////////////////////////////////////////////////////////////////////
	// Attribute Setters and Getters /////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////

	void JDFResource::SetAgentName(const WString& value){
		if (value.empty())
		{
			if (HasAttribute(atr_AgentName))
				RemoveAttribute(atr_AgentName);
		}
		else
			SetAttribute(atr_AgentName,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetAgentName() const {
		return GetAttribute(atr_AgentName);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetAgentVersion(const WString& value){
		if (value.empty())
		{
			if (HasAttribute(atr_AgentVersion))
				RemoveAttribute(atr_AgentVersion);
		}
		else
			SetAttribute(atr_AgentVersion,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetAgentVersion() const {
		return GetAttribute(atr_AgentVersion);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetAuthor(const WString& value){
		SetAttribute(atr_Author,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetAuthor() const {
		return GetAttribute(atr_Author);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetCatalogID(const WString& value){
		SetAttribute(atr_CatalogID,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetCatalogID() const {
		return GetAttribute(atr_CatalogID);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetCatalogDetails(const WString& value){
		SetAttribute(atr_CatalogDetails,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetCatalogDetails() const {
		return GetAttribute(atr_CatalogDetails);
	};
	//////////////////////////////////////////////////////////////////////////////////

	void JDFResource::SetClass(EnumClass value){
		if(value==Class_Unknown) // what a stupid thing to set it to - Ciao
			throw JDFException("SetClass:: Invalid class value ");

		if(IsResourceRoot() || IsResourceElement()){
			SetEnumAttribute(atr_Class,value,ClassString());
			// now we've set it - call the virtual valid class to check whether that was a good idea
			if (!ValidClass(ValidationLevel_Complete)){
				// snafu -> undo and punt
				RemoveAttribute(atr_Class);
				throw JDFException(L"JDFResource::SetClass: Invalid class value ");
			}
		}
	};

	//////////////////////////////////////////////////////////////////////////////////

	JDFResource::EnumClass JDFResource::GetClass() const {
		return (EnumClass) GetEnumAttribute(atr_Class,ClassString());
	};

	//////////////////////////////////////////////////////////////////////////////////

	void JDFResource::SetLocked(bool value){
		if(KElement::HasAttribute(atr_Locked)){
			if(GetLocked()^!value)
				return; // don't reset to current value - NOP
			RemoveAttribute(atr_Locked); // remove any  value so that we only get a true from an inherited value
		}
		if(value||GetLocked()){ // don't reset the default many times, but add false if true is inherited
			SetAttribute(atr_Locked,value);
		}
	};

	//////////////////////////////////////////////////////////////////////////////////

	bool JDFResource::GetLocked() const {
		return GetBoolAttribute(atr_Locked,WString::emptyStr,false);
	};

	//////////////////////////////////////////////////////////////////////////////////

	void JDFResource::SetPipeID(const WString& value){
		SetAttribute(atr_PipeID,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetPipeID() const {
		return GetAttribute(atr_PipeID);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetPartUsage(EnumPartUsage value){
		SetEnumAttribute(atr_PartUsage,value,PartUsageString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFResource::EnumPartUsage JDFResource::GetPartUsage() const {
		return (EnumPartUsage) GetEnumAttribute(atr_PartUsage,PartUsageString(),WString::emptyStr,PartUsage_Explicit);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetPipeProtocol(const WString& value){
		SetAttribute(atr_PipeProtocol,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetPipeProtocol() const {
		return GetAttribute(atr_PipeProtocol);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetProductID(const WString& value){
		SetAttribute(atr_ProductID,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetProductID() const {
		return GetAttribute(atr_ProductID);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetPipeURL(const WString& value){
		SetAttribute(atr_PipeURL,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetPipeURL() const {
		return GetAttribute(atr_PipeURL);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSpawnIDs(vWString value){
		SetAttribute(atr_SpawnIDs,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::AppendSpawnIDs(const WString& value){
		AppendAttribute(atr_SpawnIDs,value,WString::emptyStr,WString::blank,true);
	};
	//////////////////////////////////////////////////////////////////////////////////
	int JDFResource::RemoveFromSpawnIDs(const WString& value){
		return RemoveFromAttribute(atr_SpawnIDs,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	vWString JDFResource::GetSpawnIDs(bool bInherit) const {
		if(bInherit){
			return GetAttribute(atr_SpawnIDs);
		}else{
			return KElement::GetAttribute(atr_SpawnIDs);
		}
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSpawnStatus( EnumSpawnStatus value){
		SetEnumAttribute(atr_SpawnStatus,value,SpawnStatusString());
	};

	//////////////////////////////////////////////////////////////////////////////////

	JDFResource::EnumSpawnStatus JDFResource::GetSpawnStatus() const {
		return (EnumSpawnStatus) GetEnumAttribute(atr_SpawnStatus,SpawnStatusString(),WString::emptyStr,SpawnStatus_NotSpawned);
	};

	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetStatus( EnumStatus value, bool bCleanLeaves){		
		if (bCleanLeaves) 
		{
			RemoveAttributeFromLeaves(atr_Status);
		}
		SetEnumAttribute(atr_Status,value,StatusString());
	};
	//////////////////////////////////////////////////////////////////////
	JDFResource::EnumStatus JDFResource::GetStatus(bool bRecurseRefs)const{
		if(bRecurseRefs){
			return (EnumStatus) GetMinRefAttribute(atr_Status,StatusString());
		}else{
			return (EnumStatus) GetEnumAttribute(atr_Status,StatusString());
		}
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetUpdateID(const WString& value){
		SetAttribute(atr_UpdateID,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetUpdateID() const {
		return GetAttribute(atr_UpdateID);
	};

	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetNoOp(bool value){
		SetAttribute(atr_NoOp,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	bool JDFResource::GetNoOp() const {
		return GetBoolAttribute(atr_NoOp,WString::emptyStr,false);
	};

	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSortAmount(bool value){
		SetAttribute(atr_SortAmount,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	bool JDFResource::GetSortAmount() const {
		return GetBoolAttribute(atr_SortAmount,WString::emptyStr,false);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSorting(JDFIntegerRangeList value){
		SetAttribute(atr_Sorting,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetSorting() const {
		return GetAttribute(atr_Sorting,WString::emptyStr,false);
	};

	////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetAlternateBrand(const WString& value){
		SetAttribute(atr_AlternateBrand,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetAlternateBrand() const {
		return GetAttribute(atr_AlternateBrand);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetAmount(double value){
		SetAttribute(atr_Amount,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	double JDFResource::GetAmount() const {
		return GetRealAttribute(atr_Amount);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetAmountRequired(double value){
		SetAttribute(atr_AmountRequired,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	double JDFResource::GetAmountRequired() const {
		return GetRealAttribute(atr_AmountRequired);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetAmountProduced(double value){
		SetAttribute(atr_AmountProduced,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	double JDFResource::GetAmountProduced() const {
		return GetRealAttribute(atr_AmountProduced);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetBatchID(const WString& value){
		SetAttribute(atr_BatchID,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetBatchID() const {
		return GetAttribute(atr_BatchID);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetBrand(const WString& value){
		SetAttribute(atr_Brand,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetBrand() const {
		return GetAttribute(atr_Brand);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetManufacturer(const WString& value){
		SetAttribute(atr_Manufacturer,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetManufacturer() const {
		return GetAttribute(atr_Manufacturer);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetResourceWeight(double value){
		SetAttribute(atr_ResourceWeight,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	double JDFResource::GetResourceWeight() const {
		return GetRealAttribute(atr_ResourceWeight);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetGrossWeight(double value){
		SetAttribute(atr_GrossWeight,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	double JDFResource::GetGrossWeight() const {
		return GetRealAttribute(atr_GrossWeight);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetUnit(const WString& value){
		SetAttribute(atr_Unit,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetUnit() const {
		return GetAttribute(atr_Unit);
	};
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetBinderySignatureName(const WString& value){
		SetAttribute(atr_BinderySignatureName,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetBinderySignatureName() const {
		return GetAttribute(atr_BinderySignatureName,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetBlockName(const WString& value){
		SetAttribute(atr_BlockName,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetBlockName() const {
		return GetAttribute(atr_BlockName,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetBundleItemIndex(JDFIntegerRangeList value){
		SetAttribute(atr_BundleItemIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetBundleItemIndex() const {
		return GetAttribute(atr_BundleItemIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetCellIndex(JDFIntegerRangeList value){
		SetAttribute(atr_CellIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetCellIndex() const {
		return GetAttribute(atr_CellIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetCondition(WString value){
		SetAttribute(atr_Condition,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetCondition() const {
		return GetAttribute(atr_Condition,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetDocCopies(JDFIntegerRangeList value){
		SetAttribute(atr_DocCopies,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetDocCopies() const {
		return GetAttribute(atr_DocCopies,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetDocIndex(JDFIntegerRangeList value){
		SetAttribute(atr_DocIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetDocIndex() const {
		return GetAttribute(atr_DocIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetDocRunIndex(JDFIntegerRangeList value){
		SetAttribute(atr_DocRunIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetDocRunIndex() const {
		return GetAttribute(atr_DocRunIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetDocSheetIndex(JDFIntegerRangeList value){
		SetAttribute(atr_DocSheetIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetDocSheetIndex() const {
		return GetAttribute(atr_DocSheetIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetFountainNumber(int value){
		SetAttribute(atr_FountainNumber,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	int JDFResource::GetFountainNumber() const {
		return GetIntAttribute(atr_FountainNumber,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetItemNames(const WString& value){
		SetAttribute(atr_ItemNames,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetItemNames() const {
		return GetAttribute(atr_ItemNames,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetLayerIDs(JDFIntegerRangeList value){
		SetAttribute(atr_LayerIDs,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetLayerIDs() const {
		return GetAttribute(atr_LayerIDs,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetLocation(const WString& value){
		SetAttribute(atr_Location,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetLocation() const {
		return GetAttribute(atr_Location,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetOption(const WString& value){
		SetAttribute(atr_Option,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetOption() const {
		return GetAttribute(atr_Option,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetPageNumber(JDFIntegerRangeList value){
		SetAttribute(atr_PageNumber,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetPageNumber() const {
		return GetAttribute(atr_PageNumber,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetPartVersion(const WString& value){
		SetAttribute(atr_PartVersion,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetPartVersion() const {
		return GetAttribute(atr_PartVersion,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetPreflightRule(const WString& value){
		SetAttribute(atr_PreflightRule,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetPreflightRule() const {
		return GetAttribute(atr_PreflightRule,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetPreviewType( JDFPart::EnumPreviewType value){
		SetEnumAttribute(atr_PreviewType,value,((JDFPart*)this)->PreviewTypeString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFPart::EnumPreviewType JDFResource::GetPreviewType() const {
		return (JDFPart::EnumPreviewType) GetEnumAttribute(atr_PreviewType,((JDFPart*)this)->PreviewTypeString(),WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetRibbonName(const WString& value){
		SetAttribute(atr_RibbonName,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetRibbonName() const {
		return GetAttribute(atr_RibbonName,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetRun(const WString& value){
		SetAttribute(atr_Run,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetRun() const {
		return GetAttribute(atr_Run,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetRunIndex(JDFIntegerRangeList value){
		SetAttribute(atr_RunIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetRunIndex() const {
		return GetAttribute(atr_RunIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetRunTags(const vWString& value){
		SetAttribute(atr_RunTags,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	vWString JDFResource::GetRunTags() const {
		return GetAttribute(atr_RunTags,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetRunPage(int value){
		SetAttribute(atr_RunPage,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	int JDFResource::GetRunPage() const {
		return GetIntAttribute(atr_RunPage,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSectionIndex(JDFIntegerRangeList value){
		SetAttribute(atr_SectionIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetSectionIndex() const {
		return GetAttribute(atr_SectionIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSeparation(const WString& value){
		SetAttribute(atr_Separation,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetSeparation() const {
		return GetAttribute(atr_Separation,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSetDocIndex(JDFIntegerRangeList value){
		SetAttribute(atr_SetDocIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetSetDocIndex() const {
		return GetAttribute(atr_SetDocIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSetIndex(JDFIntegerRangeList value){
		SetAttribute(atr_SetIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetSetIndex() const {
		return GetAttribute(atr_SetIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSetRunIndex(JDFIntegerRangeList value){
		SetAttribute(atr_SetRunIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetSetRunIndex() const {
		return GetAttribute(atr_SetRunIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSetSheetIndex(JDFIntegerRangeList value){
		SetAttribute(atr_SetSheetIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetSetSheetIndex() const {
		return GetAttribute(atr_SetSheetIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSheetIndex(JDFIntegerRangeList value){
		SetAttribute(atr_SheetIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList JDFResource::GetSheetIndex() const {
		return GetAttribute(atr_SheetIndex,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSheetName(const WString& value){
		SetAttribute(atr_SheetName,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetSheetName() const {
		return GetAttribute(atr_SheetName,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSide( JDFPart::EnumSide value){
		SetEnumAttribute(atr_Side,value,((JDFPart*)this)->SideString());
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFPart::EnumSide JDFResource::GetSide() const {
		return (JDFPart::EnumSide) GetEnumAttribute(atr_Side,((JDFPart*)this)->SideString(),WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetSignatureName(const WString& value){
		SetAttribute(atr_SignatureName,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetSignatureName() const {
		return GetAttribute(atr_SignatureName,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetTileID(JDFXYPair value){
		SetAttribute(atr_TileID,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	JDFXYPair JDFResource::GetTileID() const {
		return GetAttribute(atr_TileID,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetWebName(const WString& value){
		SetAttribute(atr_WebName,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetWebProduct(const WString& value){
		SetAttribute(atr_WebProduct,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	void JDFResource::SetWebSetup(const WString& value){
		SetAttribute(atr_WebSetup,value);
	};
	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetWebName() const {
		return GetAttribute(atr_WebName,WString::emptyStr);
	};

	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetWebProduct() const {
		return GetAttribute(atr_WebProduct,WString::emptyStr);
	};

	//////////////////////////////////////////////////////////////////////////////////
	WString JDFResource::GetWebSetup() const {
		return GetAttribute(atr_WebSetup,WString::emptyStr);
	};

	//////////////////////////////////////////////////////////////////////////////////
	/**
	* Sets attribute DeliveryUnit
	* 
	* @param iUnit a value between 0 and 9 to set DeliveryUnit<iUnit>
	* @param value the value to set the attribute to
	*/
	void JDFResource::setDeliveryUnit(int iUnit, const WString& value)
	{
		if(iUnit<0 || iUnit>9)
			throw new JDFException("SetDeliveryUnit: invalid iUnit: "+WString::valueOf(iUnit));

		SetAttribute(atr_DeliveryUnit+WString::valueOf(iUnit), value);
	}

	/**
	* Gets attribute DeliveryUnit
	* 
	* @param iUnit a value between 0 and 9 to set DeliveryUnit<iUnit>
	*
	* @return in the attribute value 
	*/
	WString JDFResource::getDeliveryUnit(int iUnit) const
	{
		if(iUnit<0 || iUnit>9)
			throw new JDFException("getDeliveryUnit: invalid iUnit: "+WString::valueOf(iUnit));
		return GetAttribute(atr_DeliveryUnit+WString::valueOf(iUnit));
	}

	/**
	* Gets attribute DeliveryUnit
	* 
	* @param iUnit a value between 0 and 9 to set DeliveryUnit<iUnit>
	*
	* @return in the attribute value 
	*/
	bool JDFResource::validDeliveryUnit(int iUnit, EnumValidationLevel level) const
	{
		if(iUnit<0 || iUnit>9)
			throw new JDFException("validDeliveryUnit: invalid iUnit: "+WString::valueOf(iUnit));
		return ValidAttribute(atr_DeliveryUnit+WString::valueOf(iUnit),AttributeType_NMTOKEN,false);
	}

	//////////////////////////////////////////////////////////////////////////////////

	bool JDFResource::isSpawnAllowed()
	{
		JDFAttributeMap amPartMap = GetPartMap();
		bool isSpawnAllowed = true;

		if (amPartMap.size() > 0)     // tuning
		{
			// Find first part ID key in amPartMap.
			WString strPartIDKey;
			vWString vsPartKeys  = GetPartIDKeys();
			int nPartKeys = vsPartKeys.size();

			// find a partIDKey, which is in the partMap too (start from the end)
			for (int i=nPartKeys-1; i >= 0 && strPartIDKey.empty(); i--) 
			{
				WString str = vsPartKeys.stringAt(i);

				if (amPartMap.HasKey(str))
				{
					strPartIDKey = str;
				}
			}

			// Check found part ID key.
			if (!strPartIDKey.empty())
			{
				if ((strPartIDKey.equals(WString("DocIndex")))
					|| (strPartIDKey.equals(WString("DocCopies")))
					|| (strPartIDKey.equals(WString("DocRunIndex")))
					|| (strPartIDKey.equals(WString("DocSheetIndex")))
					|| (strPartIDKey.equals(WString("RunIndex")))
					|| (strPartIDKey.equals(WString("SheetIndex")))
					// values not allowed according to JDF 1.2, 3.8.2.4                 
					// || (strPartIDKey.equals (AttributeName.SORTING))
					// || (strPartIDKey.equals (AttributeName.SORTAMOUNT))
					)
				{
					isSpawnAllowed = false;
				}
			}
		}

		return isSpawnAllowed;
	}

	//////////////////////////////////////////////////////////////////////////////////

	void JDFResource::setPartIDKeys(const vWString& partIDKeys)
	{
		GetResourceRoot().SetAttribute(atr_PartIDKeys,partIDKeys.GetString(WString::blank,WString::emptyStr,WString::emptyStr));
	}

	//////////////////////////////////////////////////////////////////////////////////

	bool JDFResource::validResourceClass(KElement::EnumValidationLevel level) const
	{
		bool b=ValidAttribute(atr_Class, JDFElement::AttributeType_Unknown, RequiredLevel(level));
		if(!b)
			return false;
		// don't need to check for completeness - already done in the standard validAttribute call
		if(IsResourceRootRoot())
			return ValidClass();
		return true;
	}

	//////////////////////////////////////////////////////////////////////////////////

	vWString JDFResource::reorderPartKeys(const vWString& vPartKeys)
	{
		if (vPartKeys.empty())
		{
			return GetPartIDKeys();
		}
		vWString vPartIDKeys = vWString(vPartKeys);
		vWString vExistingPartKeys=GetPartIDKeys();
		vWString vTmpPartIDKeys;
		if(!vExistingPartKeys.empty())
		{
			int n=vExistingPartKeys.size();
			if(vPartIDKeys.size()<n)
				n=vPartIDKeys.size();

			for(int i=0;i<n;i++)
			{
				WString partKey = vExistingPartKeys[i];
				if(!vPartIDKeys.contains(partKey)) // allow reordering of the existing partidkeys
				{
					throw JDFException("getCreatePartiton: adding incompatible partitions");
				}
				vTmpPartIDKeys.add(partKey);
				vPartIDKeys.RemoveStrings(vWString(partKey));
			}
			for(int i=0;i<vPartIDKeys.size();i++)
			{
				vTmpPartIDKeys.add(vPartIDKeys[i]);
			}
			vPartIDKeys=vTmpPartIDKeys;                
		}            
		return vPartIDKeys;
	}

	//////////////////////////////////////////////////////////////////////////////////

	void JDFResource::cleanResourceAttributes()
	{
		// clean up resource specific attributes
		RemoveAttribute(atr_ID);
		RemoveAttribute(atr_Class);
		RemoveAttribute(atr_Status);
		RemoveAttribute(atr_PartUsage);
		RemoveAttribute(atr_NoOp);
		vWString v=GetPartIDKeys();
		for(int i=0;i<v.size();i++)
			RemoveAttribute(v[i]);

		RemoveAttribute(atr_Locked);
		RemoveAttribute(atr_PartIDKeys);
		RemoveAttribute(atr_rRefs); 
		RemoveAttribute(atr_SpawnIDs); 
		RemoveAttribute(atr_SpawnStatus); 
	}


	//////////////////////////////////////////////////////////////////////////////////

	/**
	* append an empty GeneralID 
	* 
	* @return the newly created GeneralID
	*/
	JDFGeneralID JDFResource::appendGeneralID()
	{
		return (JDFGeneralID) AppendElement(elm_GeneralID);
	}

	/**
	* append a GeneralID with idValue, duplicate entries are retained
	* 
	* @param idUsage the IDUsage attribute of the generalID
	* @param idValue the IDValue attribute of the generalID
	* @return the newly created GeneralID
	*/
	JDFGeneralID JDFResource::appendGeneralID(const WString& idUsage, const WString& idValue)
	{
		JDFGeneralID gid = AppendElement(elm_GeneralID);
		gid.SetIDValue(idValue);
		gid.SetIDUsage(idUsage);
		return gid;
	}

	/**
	* gets attribute GeneralID
	* @param i get the i'th element that fits
	* @return the attribute value
	*/
	JDFGeneralID JDFResource::getGeneralID(int i)const
	{
		return GetElement(elm_GeneralID,WString::emptyStr,i);
	}

	/**
	* Creates or Updates a GeneralID with the IDUsage idUsage and IDValue=idValue
	* all entries with a duplicate idUsage are removed
	* 
	* @param idUsage usage to set the attribute to
	* @param idValue   value to set the attribute to
	*/
	void JDFResource::setGeneralID(const WString& idUsage, const WString& idValue)
	{
		JDFGeneralID gid;

		VElement v = KElement::GetChildElementVector(elm_GeneralID, WString::emptyStr,JDFAttributeMap(atr_IDUsage, idUsage), true, 0, true);
		if (v.size() == 0)
		{
			gid = AppendElement(elm_GeneralID);
		}
		else if (v.size() >= 1)
		{
			gid = v.elementAt(0);

			for (int i = 1; i < v.size(); i++)
				// remove any duplicates
				v.elementAt(i).DeleteNode();
		}

		if (!gid.isNull())
		{
			gid.SetIDValue(idValue);
			gid.SetIDUsage(idUsage);
		}
	}
	/**
	* removes GeneralID with the IDUsage idUsage
	* 
	* @param idUsage value to set the attribute to
	*/
	void JDFResource::removeGeneralID(const WString& idUsage)
	{
		VElement v=GetChildElementVector(elm_GeneralID,WString::emptyStr,JDFAttributeMap(atr_IDUsage,idUsage),true,0,true);
		for(int i=0;i<v.size();i++)
			v.elementAt(i).DeleteNode();
	}

	/**
	* Gets IDValue of the GeneralID with IDUsage=idUsage
	*
	* @return double the attribute value
	*/
	WString JDFResource::getGeneralID(const WString& idUsage)const
	{
		VElement v=GetChildElementVector(elm_GeneralID,WString::emptyStr,JDFAttributeMap(atr_IDUsage,idUsage),true,0,true);
		if(v.size()==0)
			return WString::emptyStr;
		JDFGeneralID gid=(JDFGeneralID)v.elementAt(0);
		return gid.GetIDValue();
	}

	//////////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////////

	/**
	* Gets the minimum typesafe enumerated value of attribute Status from the value of all leaves 
	*
	* @param bAll if true, also evaluate intermediate partitions, else leaves only
	* @return EnumResStatus - the minimum Status enumeration value
	*
	*/
	JDFResource::EnumStatus JDFResource::getStatusFromLeaves(bool bAll) const
	{
		VElement v=GetLeaves(bAll);
		int siz=v.size();
		EnumStatus minStatus=(EnumStatus)0;
		for(int i=0;i<siz;i++)
		{
			JDFResource r=v.elementAt(i);
			if(minStatus==0)
				minStatus=r.GetStatus(false);
			else
				minStatus=std::min(minStatus, r.GetStatus(false));
		}
		return minStatus;
	}

	///////////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////
} // namespace jdf
