/*
*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  27.01.2004
//
// JDFStringState.cpp: implementation of the JDFStringState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFStringState.h"
#include "JDFValue.h"
#include "xercesc/util/regx/RegularExpression.hpp"

XERCES_CPP_NAMESPACE_USE
using namespace std;
namespace JDF{
	
	
	//////////////////////////////////////////////////////////////////////
	
	JDFStringState& JDFStringState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFStringState: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFStringState::ValidNodeNames()const{
		return L"*:,StringState";
	};
		
	//////////////////////////////////////////////////////////////////////
	
	WString JDFStringState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",Value";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFStringState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFStateBase::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		
		nElem=NumChildElements(elm_Value);
		for(i=0;i<nElem;i++){
			JDFValue child=GetElement(elm_Value,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Value);
				if (++n>=nMax) 
					return vElem;
				break;
			};
		}
		return vElem;
	};
	
	//////////////////////////////////////////////////////////////////////
	WString JDFStringState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedLength,AllowedRegExp,PresentLength,PresentRegExp";
	};
	
	//////////////////////////////////////////////////////////////////////

	vWString JDFStringState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFStateBase::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidAllowedLength(level)) {
			vAtts.push_back(atr_AllowedLength);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedRegExp(level)) {
			vAtts.push_back(atr_AllowedRegExp);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentLength(level)) {
			vAtts.push_back(atr_PresentLength);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentRegExp(level)) {
			vAtts.push_back(atr_PresentRegExp);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFStringState::ValidAllowedLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowedLength,AttributeType_IntegerRange,false);
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFStringState::ValidAllowedRegExp(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowedRegExp,AttributeType_regExp,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFStringState::ValidPresentLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentLength,AttributeType_IntegerRange,false);
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFStringState::ValidPresentRegExp(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentRegExp,AttributeType_regExp,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	bool JDFStringState::FitsValue(const WString& value, EnumFitsValue testlist) const{

		return (FitsLength(value,testlist)&&FitsRegExp(value,testlist)&&FitsValueElem(value,testlist));

	}
	//////////////////////////////////////////////////////////////////////
	bool JDFStringState::FitsLength(const WString& str, EnumFitsValue valuelist) const{

		if (valuelist==FitsValue_Allowed) 
        {
            if(!HasAttribute(atr_AllowedLength))
                return true;
        } 
        else 
        {
            if(!HasAttribute(atr_AllowedLength) &&
               !HasAttribute(atr_PresentLength))
                return true;
        }

		int len=str.length();
		JDFIntegerRange lengthlist;

		if (valuelist==FitsValue_Allowed)
		{
			lengthlist = GetAllowedLength();
		} 
		else {
			lengthlist = GetPresentLength();
		}
		return lengthlist.InRange(len);

	}
	//////////////////////////////////////////////////////////////////////
	bool JDFStringState::FitsRegExp(const WString& str, EnumFitsValue regexp) const{

		WString rExp;

		if (regexp==FitsValue_Allowed) 
		{
			rExp = GetAllowedRegExp();
		} else {
			rExp = GetPresentRegExp();
		}
		if(rExp.size()==0)
			return true; // if AllowedRegExp is not specified return true 

		RegularExpression re(rExp.c_str());

		return re.matches(str.c_str()); 

	}
	//////////////////////////////////////////////////////////////////////

	bool JDFStringState::FitsValueElem(const WString& str, EnumFitsValue valuelist) const{
	
		vElement v=GetChildElementVector(elm_Value);
		int siz=v.size();
		if (siz==0) {
			return true; // State has no Value elements
		}
		for (int i=0; i<siz; i++)
		{
			
			JDFValue elm=v[i];
			if (elm.HasAttribute(atr_ValueUsage))
			{
				EnumFitsValue valueUsage = GetValueValueUsage(i); 
				if ( valuelist==valueUsage) 
				{
					WString value=GetValueAllowedValue(i);
					if (value.compare(str)==0)
						return true; // we have found it
				}				
			}
			else {
				WString value=GetValueAllowedValue(i);
				if (value.compare(str)==0)
					return true; // we have found it
			}
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
		
	/* ******************************************************
	// Attribute Getter/ Setter
	**************************************************************** */	
			
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFStringState::SetAllowedLength(const JDFIntegerRange& value){
		SetAttribute(atr_AllowedLength,value.GetString());
	};
	////////////////////////////////////////////////////////////////////////

	JDFIntegerRange JDFStringState::GetAllowedLength() const {
		return GetAttribute(atr_AllowedLength);
	};
	////////////////////////////////////////////////////////////////////////

	void JDFStringState::SetPresentLength(const JDFIntegerRange& value){
		SetAttribute(atr_PresentLength,value.GetString());
	};
	////////////////////////////////////////////////////////////////////////

	JDFIntegerRange JDFStringState::GetPresentLength() const {
		if (HasAttribute(atr_PresentLength))
			return GetAttribute(atr_PresentLength);
		return GetAllowedLength();
	};
	////////////////////////////////////////////////////////////////////////

	void JDFStringState::SetAllowedRegExp(const WString& value){
		SetAttribute(atr_AllowedRegExp,value);
	};
	////////////////////////////////////////////////////////////////////////	 
	
	WString JDFStringState::GetAllowedRegExp() const {
		return GetAttribute(atr_AllowedRegExp);
	};
	////////////////////////////////////////////////////////////////////////
	
	void JDFStringState::SetPresentRegExp(const WString& value){
		SetAttribute(atr_PresentRegExp,value);
	};
	////////////////////////////////////////////////////////////////////////	 
	
	WString JDFStringState::GetPresentRegExp() const {
		if(HasAttribute(atr_PresentRegExp))
			return GetAttribute(atr_PresentRegExp);
		return GetAllowedRegExp();
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValue JDFStringState::GetValue(int iSkip)const{
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValue JDFStringState::AppendValue(){
		JDFValue e=AppendElement(elm_Value);
		e.init();
		return e;
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Subelement attribute and element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFLoc JDFStringState::GetValueLoc(int iSkip, int jSkip)const{
		JDFValue val=GetElement(elm_Value,WString::emptyStr,iSkip);
		JDFLoc loc=val.GetElement(elm_Loc,WString::emptyStr,jSkip);
		return loc;
	};
	/////////////////////////////////////////////////////////////////////

	JDFLoc JDFStringState::AppendValueLoc(int iSkip){
		JDFValue val=GetElement(elm_Value,WString::emptyStr,iSkip);
		JDFLoc loc=val.AppendElement(elm_Loc);
		loc.init();
		return loc;
	};
	//////////////////////////////////////////////////////////////////////

	void JDFStringState::SetValueAllowedValue(int iSkip, const WString& value){
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		e.SetAllowedValue(value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFStringState::GetValueAllowedValue(int iSkip) const {
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e.GetAllowedValue();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFStringState::SetValueValueUsage(int iSkip, EnumFitsValue value){
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		e.SetValueUsage(value);
	};
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumFitsValue JDFStringState::GetValueValueUsage(int iSkip) const {
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e.GetValueUsage();
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////
}