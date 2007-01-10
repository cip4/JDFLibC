/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

  //
  // COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
  //      ALL RIGHTS RESERVED 
  //
  //  Author: Dr. Rainer Prosi using JDFSchema code generator 
  // 
  // Warning! very preliminary test version. Interface subject to change without prior notice!
  // Revision history:
  // created 2001-02-26
  //
*/

#include "JDFRefElement.h"
#include "JDFPart.h"
#include "JDFResource.h"
#include "JDFNode.h"

namespace JDF{
	
	///////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////
	
	JDFRefElement & JDFRefElement::operator =(const KElement& other){
		JDFElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFRefElement: "+other.GetNodeName());
		return *this;
	};
	
	///////////////////////////////////////////////////////////////////////
	
	bool JDFRefElement::IsValid(EnumValidationLevel level)const{
		bool b=JDFElement::IsValid(level);
		if(!b) 
			return false;
		WString nodeName=GetNodeName();
		if(level<=ValidationLevel_Construct) {
			if(level<=ValidationLevel_None) 
				return true;
			
			if(isNull()) 
				return true;
			
			if(nodeName.rightStr(3)!=atr_Ref) 
				return false;
			
			return true;
		}
		
		JDFResource r=GetTarget();
		if(r.isNull()) 
			return false;
		
		if(nodeName!=r.GetRefString()) 
			return false;

		if(!ValidResourcePosition())
			return false;

//		bool bIsInDelivery=(parentNodeName==elm_DropItem)||(parentNodeName==elm_DropItemIntent)||(parentNodeName==elm_ArtDelivery);
//
//		// RunLists and physical resources may be referenced at the root or intermediate nodes
//		if(!bIsInDelivery&&((r.GetPartUsage()!=JDFResource::PartUsage_Implicit)&&!r.IsLeaf()))
//			return false;
		
		return true;
	}
	
	///////////////////////////////////////////////////////////////////////

	bool JDFRefElement::ValidResourcePosition()const
	{	
		return JDFElement::ValidResourcePosition(GetTarget());
	}


	///////////////////////////////////////////////////////////////////////

	JDFResource JDFRefElement::GetLinkRoot()const{

		JDFResource r=JDFElement::GetLinkRoot();

		return r;
	};
	///////////////////////////////////////////////////////////////////////

	JDFElement JDFRefElement::GetTarget()const{
		JDFElement e=GetLinkRoot();
		if(e.isNull())
			return e;

		if(HasAttribute(atr_rSubRef)) {
			e=e.GetChildWithAttribute(GetRefNodeName(),atr_ID,WString::emptyStr,GetrSubRef(),0,false);
		}

		// 260802 RP return a null target for crap targets
		// 291002 RP added isnull check
		if(e.isNull()||(GetNodeName()!=e.GetRefString()) )
			return JDFElement();

		
		// this refElement has a part
		if(HasChildElement(elm_Part)){
			if(e.IsResource()){
				JDFResource r=e;
				mAttribute partMap=GetPart().GetPartMap();
				e=r.GetPartition(partMap);
			}else{
				throw JDFException(L"JDFRefElement::GetTarget: pointing to a partition that is not a Resource!");
			}
		}
		return e;

	}
	
	///////////////////////////////////////////////////////////////////////
	
	WString JDFRefElement::GetRefNodeName()const{
		WString nn=GetNodeName();
		
		if(nn.rightStr(3)==atr_Ref) {
			nn=nn.leftStr(-3);
		}else{
			nn=WString::emptyStr;
		}
		
		return nn;
	};
	///////////////////////////////////////////////////////////////////////
	WString JDFRefElement::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",rRef";
	}
	/**
	* definition of optional attributes in the JDF namespace
	*/
	WString JDFRefElement::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+L",rSubRef";
	};
	/**
	* definition of optional elements in the JDF namespace
	*/
	WString JDFRefElement::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part";
	};
		//////////////////////////////////////////////////////////////////////
	
	vWString JDFRefElement::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		
		int n=vElem.size();
		
		if(n>=nMax) 
			return vElem;

		nElem=NumChildElements(elm_Part);
		if(nElem>1){
			vElem.push_back(elm_Part);
			if (++n>=nMax) 
				return vElem;
		}
		
		for(i=0;i<nElem;i++){
			JDFPart child=GetElement(elm_Part,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Part);
				if (++n>=nMax) 
					return vElem;
			};
		}
		return vElem;
	};
	///////////////////////////////////////////////////////////////////////
	JDFPart JDFRefElement::AppendPart(){
		JDFPart e=GetCreateElement(elm_Part);
		e.init();
		return e;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFPart JDFRefElement::GetCreatePart(){
		JDFPart e=GetCreateElement(elm_Part);
		e.init();
		return e;
	};
	

	///////////////////////////////////////////////////////////////////////

	JDFPart JDFRefElement::GetPart()const{
		return GetElement(elm_Part);
	};

	///////////////////////////////////////////////////////////////////////

	JDFElement JDFRefElement::InlineRef(){
		JDFResource resource=GetTarget();
		if(resource.isNull())
			return JDFElement();

		JDFResource newInline=AppendElement(resource.GetNodeName());
		
		// copy elements and attributes
		newInline.SetAttributes(resource.GetAttributeMap());
		vElement v=resource.GetChildElementVector();
		int i;
		for(i=0;i<v.size();i++){
			newInline.CopyElement(v.at(i));
		}

		newInline.RemoveAttribute(atr_ID);
		newInline.RemoveAttribute(atr_Locked);
		newInline.RemoveAttribute(atr_Status);
		newInline.RemoveAttribute(atr_Class);
		newInline.RemoveAttribute(atr_rRefs);
		newInline.RemoveAttribute(atr_PartIDKeys);

		vWString partNames=resource.GetPartIDKeys();
		
		for(i=0;i<partNames.size();i++){
			newInline.RemoveAttribute(partNames.at(i));
		}
		
		// replace this (the refElement) with newInline. 
		// This effectively repositions newInline from the back to the original position of this
		ReplaceElement(newInline);

		// remove any unlinked resources
		if(resource.GetLinks().empty()) 
			resource.DeleteNode();

		return newInline;
	}
	
	///////////////////////////////////////////////////////////////////////

	JDFElement JDFRefElement::DeleteRef(bool bCheckRefCount){
		JDFElement e=GetTarget();
		bool bHasRefs=false;
		if(bCheckRefCount){
			vElement v=e.GetLinks(); // get all references to e
			v.RemoveElements(*this); // remove this
			bHasRefs=!v.empty(); // no references left
		}
		if(!bHasRefs){
			e.DeleteNode();
		}
		// now zapp myself
		return DeleteNode();
	}
	
	///////////////////////////////////////////////////////////////////////
	bool JDFRefElement::ValidrRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRef,AttributeType_Any,level>=ValidationLevel_Complete);
	};

	///////////////////////////////////////////////////////////////////////
	bool JDFRefElement::ValidrSubRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_rSubRef,AttributeType_Any,false);
	};

	///////////////////////////////////////////////////////////////////////
	
	mAttribute JDFRefElement::GetPartMap()const{
		return GetPart().GetPartMap();
	}
	
	//////////////////////////////////////////////////////////////////////

	
	void JDFRefElement::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}

	//////////////////////////////////////////////////////////////////////
	void JDFRefElement::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFRefElement::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFRefElement::IsAbstract()const{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
}
