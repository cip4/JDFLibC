/*
*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
//
// JDFState.cpp: implementation of the JDFState 
// contains specializations of the JDFState hierarchy
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFDevCaps.h"
#include "JDFDevCap.h"
#include "JDFIntentResource.h"

using namespace std;
namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	
	JDFStateBase& JDFStateBase::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFStateBase: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////

	const WString& JDFStateBase::UserDisplayString(){
		static const WString enums=L"Unknown,Display,Hide,Dependent";
		return enums;
	};
	//////////////////////////////////////////////////////////////////////
	
	const WString JDFStateBase::UserDisplayString(EnumUserDisplay value){
		return UserDisplayString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////
		
	const WString& JDFStateBase::ListTypeString(){
		static const WString enums=WString(L"Unknown,CompleteList,CompleteOrderedList,ContainedList,List,OrderedList")
			+WString(L",OrderedRangeList,RangeList,SingleValue,Span,UniqueList,UniqueRangeList,UniqueOrderedList")
			+WString(L",UniqueOrderedRangeList");
		return enums;
	};
	//////////////////////////////////////////////////////////////////////

	const WString JDFStateBase::ListTypeString(EnumListType value){
		return ListTypeString().Token(value,WString::comma);
	};


	//////////////////////////////////////////////////////////////////////
	
	WString JDFStateBase::GetNamePath(bool onlyNames)const{
		JDFDevCap devCap = GetParentNode();
		if (GetListType()==JDFStateBase::ListType_Span)
			return devCap.GetNamePath(onlyNames) + L"/"+GetName();// Span is an element
		return devCap.GetNamePath(onlyNames) + L"/@"+GetName();
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFStateBase::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Loc";
	};
	//////////////////////////////////////////////////////////////////////
	vWString JDFStateBase::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		
		nElem=NumChildElements(elm_Loc);
		for(i=0;i<nElem;i++){
			JDFLoc child=GetElement(elm_Loc,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Loc);
				if (++n>=nMax) return vElem;
				break;
			};
		}
		return vElem;
	};


	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidCurrentValue(EnumValidationLevel level)const
	{
		return true;
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidDefaultValue(EnumValidationLevel level)const
	{
		return true;
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::FitsValue(const WString& value, EnumFitsValue testlists) const
	{
		return true;
	};

	/**
     * set the default values specified in this in element
     * @param element the element to set the defaults on
     * @return true if successful
     */
	bool JDFStateBase::setDefaultsFromCaps(KElement element)const
    {
        if(GetHasDefault()==false)
            return false;
		WString def=GetAttribute(atr_DefaultValue);
        if(def.empty())
            return false;
        bool theValue=hasMatchingObjectInNode(element);
        if(theValue)
            return false;
        
        WString nam = GetName();
        if(GetListType()==ListType_Span)
        {            
            JDFIntentResource ir=(JDFIntentResource)element;
			JDFSpanBase span=ir.AppendSpan(nam, JDFSpanBase::DataType_Unknown);
			span.SetAttribute(atr_Preferred,def);
        }
        else // some attribute...
        {
            element.SetAttribute(nam,def);
        } 
        return true;
    }
	//////////////////////////////////////////////////////////////////////
   /**
     * gets the matching Attribute value String or AbstractSpan object from the parent, 
     * depending on the type of the state
     * 
     * @param element the parent in which to search
     * @return Object either a String or AbstractSpan
     */
	bool JDFStateBase::hasMatchingObjectInNode(const KElement& element)const
    {
        WString nam = GetName();
        if(GetListType()==ListType_Span)
        {            
			return element.HasChildElement(nam,GetDevNS(),0);            
        }
        
        return HasAttribute(nam,GetDevNS());
    }
	//////////////////////////////////////////////////////////////////////

	WString JDFStateBase::OptionalAttributes()const{
		WString w=JDFElement::OptionalAttributes()+L",Availability,DevNS,HasDefault,ID,MaxOccurs,MinOccurs,Name,Required,ListType,ActionRefs,Editable,MacroRefs,DependentMacroRef,UserDisplay,CurrentValue";
		if (!GetHasDefault()) {
			w+=L",DefaultValue";
		}
		return w;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFStateBase::RequiredAttributes()const{
		WString w=JDFElement::RequiredAttributes();
		if (GetHasDefault()){
			w+=L",DefaultValue";
		}
		return w;
	};

		//////////////////////////////////////////////////////////////////////
	vWString JDFStateBase::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidAvailability(level)) {
			vAtts.push_back(atr_Availability);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidDevNS(level)) {
			vAtts.push_back(atr_DevNS);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidHasDefault(level)) {
			vAtts.push_back(atr_HasDefault);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidMaxOccurs(level)) {
			vAtts.push_back(atr_MaxOccurs);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidMinOccurs(level)) {
			vAtts.push_back(atr_MinOccurs);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRequired(level)) {
			vAtts.push_back(atr_Required);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidListType(level)) {
			vAtts.push_back(atr_ListType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidActionRefs(level)) {
			vAtts.push_back(atr_ActionRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEditable(level)) {
			vAtts.push_back(atr_Editable);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMacroRefs(level)) {
			vAtts.push_back(atr_MacroRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDependentMacroRef(level)) {
			vAtts.push_back(atr_DependentMacroRef);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUserDisplay(level)) {
			vAtts.push_back(atr_UserDisplay);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDefaultValue(level)) {
			vAtts.push_back(atr_DefaultValue);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidCurrentValue(level)) {
			vAtts.push_back(atr_CurrentValue);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidAvailability(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Availability,JDFDevCaps::AvailabilityString(),false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidHasDefault(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasDefault,AttributeType_boolean,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidDevNS(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevNS,AttributeType_URI,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidMaxOccurs(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxOccurs,AttributeType_integer,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidMinOccurs(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinOccurs,AttributeType_integer,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_NMTOKEN,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidRequired(EnumValidationLevel level) const {
		return ValidAttribute(atr_Required,AttributeType_boolean,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidListType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ListType,ListTypeString(),false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidActionRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_ActionRefs,AttributeType_IDREFS,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidEditable(EnumValidationLevel level) const {
		return ValidAttribute(atr_Editable,AttributeType_boolean,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidMacroRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_MacroRefs,AttributeType_IDREFS,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidDependentMacroRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_DependentMacroRef,AttributeType_IDREF,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::ValidUserDisplay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_UserDisplay,UserDisplayString(),false);
	};

	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter/ Setter
	**************************************************************** */	

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	JDFDevCaps::EnumAvailability JDFStateBase::GetAvailability() const {
		JDFDevCaps::EnumAvailability avail=(JDFDevCaps::EnumAvailability) GetEnumAttribute(atr_Availability,JDFDevCaps::AvailabilityString());
			if (avail==JDFDevCaps::Availability_Unknown){
				JDFDevCap par=GetParentNode();
				avail= (JDFDevCaps::EnumAvailability) par.GetAvailability();
			}
		return avail;
	};

	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetAvailability( JDFDevCaps::EnumAvailability value){
		SetEnumAttribute(atr_Availability,value,JDFDevCaps::AvailabilityString());
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetID(const WString& value){
		SetAttribute(atr_ID,value);
	}
	//////////////////////////////////////////////////////////////////////
	WString JDFStateBase::GetID() const {
		return GetAttribute(atr_ID);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetDevNS(WString value){
		SetAttribute(atr_DevNS,value);
	};
	//////////////////////////////////////////////////////////////////////
	WString JDFStateBase::GetDevNS() const {
		return GetAttribute(atr_DevNS,WString::emptyStr,L"http://www.cip4.org/JDFSchema_1_1");
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetHasDefault(bool value){
		SetAttribute(atr_HasDefault,value);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::GetHasDefault() const {
		return GetBoolAttribute(atr_HasDefault,WString::emptyStr,true);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetMaxOccurs(int value){
		SetAttribute(atr_MaxOccurs,value);
	};
	//////////////////////////////////////////////////////////////////////
	int JDFStateBase::GetMaxOccurs() const {
		WString s= GetAttribute(atr_MaxOccurs);
		if (s.equals("unbounded"))
		{
			return WString::pINF;
		}
		else
		{
			return GetIntAttribute(atr_MaxOccurs,WString::emptyStr,1);
		}
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetMinOccurs(int value){
		SetAttribute(atr_MinOccurs,value);
	};
	//////////////////////////////////////////////////////////////////////
	int JDFStateBase::GetMinOccurs() const {

		return GetIntAttribute(atr_MinOccurs,WString::emptyStr,1);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetRequired(bool value){
		SetAttribute(atr_Required,value);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::GetRequired() const {
		return GetBoolAttribute(atr_Required,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetName(const WString& value){
		SetAttribute(atr_Name,value);
	};
	//////////////////////////////////////////////////////////////////////
	WString JDFStateBase::GetName() const {
		return GetAttribute(atr_Name,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////
	JDFStateBase::EnumListType JDFStateBase::GetListType() const {
		return (EnumListType) GetEnumAttribute(atr_ListType,ListTypeString(),WString::emptyStr,ListType_SingleValue);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetListType( EnumListType value){
		SetEnumAttribute(atr_ListType,value,ListTypeString());
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetActionRefs(vWString value){
		SetAttribute(atr_ActionRefs,value);
	};
	////////////////////////////////////////////////////////////////////////	 
	vWString JDFStateBase::GetActionRefs() const {
		return GetAttribute(atr_ActionRefs,WString::emptyStr);
	};
	////////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetEditable(bool value){
		SetAttribute(atr_Editable,value);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFStateBase::GetEditable() const {
		return GetBoolAttribute(atr_Editable,WString::emptyStr,true);
	};
	////////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetMacroRefs(vWString value){
		SetAttribute(atr_MacroRefs,value);
	};
	////////////////////////////////////////////////////////////////////////	 
	vWString JDFStateBase::GetMacroRefs() const {
		return GetAttribute(atr_MacroRefs,WString::emptyStr);
	};
	////////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetDependentMacroRef(const WString& value){
		SetAttribute(atr_DependentMacroRef,value);
	};
	////////////////////////////////////////////////////////////////////////	 
	WString JDFStateBase::GetDependentMacroRef() const {
		return GetAttribute(atr_DependentMacroRef,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////
	JDFStateBase::EnumUserDisplay JDFStateBase::GetUserDisplay() const {
		return (EnumUserDisplay) GetEnumAttribute(atr_UserDisplay,UserDisplayString(),WString::emptyStr,UserDisplay_Display);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFStateBase::SetUserDisplay( EnumUserDisplay value){
		SetEnumAttribute(atr_UserDisplay,value,UserDisplayString());
	};
		
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFLoc JDFStateBase::GetLoc(int iSkip)const{
		JDFLoc e=GetElement(elm_Loc,WString::emptyStr,iSkip);
		return e;
	};
	//////////////////////////////////////////////////////////////////////

	JDFLoc JDFStateBase::GetCreateLoc(int iSkip){
		JDFLoc e=GetCreateElement(elm_Loc,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFLoc JDFStateBase::AppendLoc(){
		JDFLoc e=AppendElement(elm_Loc);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	bool JDFStateBase::FixVersion(JDFElement::EnumVersion version)
	{
		if (GetAttribute(atr_MaxOccurs) == "unbounded")
			SetAttribute(atr_MaxOccurs,WString::pINFstr);
		return JDFElement(*this).FixVersion(version);
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}