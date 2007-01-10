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
//  Author: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  28.01.2004
//
// JDFPDFPathState.cpp: implementation of the JDFPDFPathState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFPDFPathState.h"

using namespace std;
namespace JDF{
	
	
	//////////////////////////////////////////////////////////////////////
	
	JDFPDFPathState& JDFPDFPathState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFPDFPathState: "+other.GetNodeName()); 
		return *this;
	};

	//////////////////////////////////////////////////////////////////////
	
	WString JDFPDFPathState::ValidNodeNames()const{
		return L"*:,PDFPathState";
	};
	
	//////////////////////////////////////////////////////////////////////

	WString JDFPDFPathState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",Value";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFPDFPathState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
				if (++n>=nMax) return vElem;
				break;
			};
		}
		return vElem;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFPDFPathState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedLength,PresentLength";
	};
	
	//////////////////////////////////////////////////////////////////////

	vWString JDFPDFPathState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFStateBase::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidAllowedLength(level)) {
			vAtts.push_back(atr_AllowedLength);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentLength(level)) {
			vAtts.push_back(atr_PresentLength);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFPDFPathState::ValidAllowedLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowedLength,AttributeType_IntegerRange,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFPDFPathState::ValidPresentLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentLength,AttributeType_IntegerRange,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	bool JDFPDFPathState::FitsValue(const WString& value, EnumFitsValue testlist) const{

		// TBD __Lena__ Ihhalt! Test of 20 symbols

		return (FitsLength(value,testlist)&&FitsValueElem(value,testlist));

	}
	//////////////////////////////////////////////////////////////////////
	bool JDFPDFPathState::FitsLength(const WString& pdfpath, EnumFitsValue valuelist) const{

		int len=pdfpath.length();

		JDFIntegerRange lengthlist;

		if (valuelist==FitsValue_Allowed)
		{
			lengthlist = GetAllowedLength();
		} 
		else {
			lengthlist = GetPresentLength();
		}

		if(lengthlist.NElements()==0)
			return true;
		return lengthlist.InRange(len);

	}
	//////////////////////////////////////////////////////////////////////
	bool JDFPDFPathState::FitsValueElem(const WString& pdfstate, EnumFitsValue valuelist) const{
	
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
					if (!value.compare(pdfstate))
						return true; // we have found it
				}				
			}
			else {
				WString value=GetValueAllowedValue(i);
				if (!value.compare(pdfstate))
					return true; // we have found it
			}
		}
		return false; 
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Attribute Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFPDFPathState::SetAllowedLength(const JDFIntegerRange& value){
		SetAttribute(atr_AllowedLength,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFIntegerRange JDFPDFPathState::GetAllowedLength() const {
		return GetAttribute(atr_AllowedLength);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFPDFPathState::SetPresentLength(const JDFIntegerRange& value){
		SetAttribute(atr_PresentLength,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFIntegerRange JDFPDFPathState::GetPresentLength() const {
		if (HasAttribute(atr_PresentLength))
			return GetAttribute(atr_PresentLength);
		return GetAllowedLength();
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValue JDFPDFPathState::GetValue(int iSkip)const{
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValue JDFPDFPathState::AppendValue(){
		JDFValue e=AppendElement(elm_Value);
		e.init();
		return e;
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Subelement Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFLoc JDFPDFPathState::GetValueLoc(int iSkip, int jSkip)const{
		JDFValue val=GetElement(elm_Value,WString::emptyStr,iSkip);
		JDFLoc loc=val.GetElement(elm_Loc,WString::emptyStr,jSkip);
		return loc;
	};
	/////////////////////////////////////////////////////////////////////

	JDFLoc JDFPDFPathState::AppendValueLoc(int iSkip){
		JDFValue val=GetElement(elm_Value,WString::emptyStr,iSkip);
		JDFLoc loc=val.AppendElement(elm_Loc);
		loc.init();
		return loc;
	};
	//////////////////////////////////////////////////////////////////////

	void JDFPDFPathState::SetValueAllowedValue(int iSkip, const WString& value){
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		e.SetAllowedValue(value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFPDFPathState::GetValueAllowedValue(int iSkip) const {
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e.GetAllowedValue();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFPDFPathState::SetValueValueUsage(int iSkip, EnumFitsValue value){
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		e.SetValueUsage(value);
	};
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumFitsValue JDFPDFPathState::GetValueValueUsage(int iSkip) const {
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e.GetValueUsage();
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

}