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
// created  27.01.04
//
// JDFBooleanState.cpp: implementation of the JDFBooleanState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFBooleanState.h"
#include "JDFState.h"
#include "JDFValueLoc.h"


using namespace std;
namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	
	JDFBooleanState& JDFBooleanState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFBooleanState: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFBooleanState::ValidNodeNames()const{
		return L"*:,BooleanState";
	};
	
	//////////////////////////////////////////////////////////////////////
	
	const WString& JDFBooleanState::AllowedValueListString()const {
		static const WString enums=L"Unknown,false,true";
		return enums;
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFBooleanState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",ValueLoc";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFBooleanState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFStateBase::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		
		nElem=NumChildElements(elm_ValueLoc);
		for(i=0;i<nElem;i++){
			JDFValueLoc child=GetElement(elm_ValueLoc,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_ValueLoc);
				if (++n>=nMax) return vElem;
				break;
			};
		}
		return vElem;
	};
	
	//////////////////////////////////////////////////////////////////////
	WString JDFBooleanState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedValueList,PresentValueList";
	};
	
	//////////////////////////////////////////////////////////////////////

	vWString JDFBooleanState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFStateBase::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidAllowedValueList(level)) {
			vAtts.push_back(atr_AllowedValueList);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentValueList(level)) {
			vAtts.push_back(atr_PresentValueList);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFBooleanState::ValidAllowedValueList(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_AllowedValueList,AllowedValueListString(),false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFBooleanState::ValidPresentValueList(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_PresentValueList,AllowedValueListString(),false);
	};

	//////////////////////////////////////////////////////////////////////
		
	bool JDFBooleanState::FitsValue(const WString& valueStr, EnumFitsValue testlist) const{
		
		if (FitsListType(valueStr))
		{
			vWString value = valueStr.Tokenize();

			for (int i=0; i<value.size(); i++)
			{
				if (!FitsValueList(value[i],testlist))
					return false;
			}
			return true; // if we are here a whole 'valueStr' fits
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFBooleanState::FitsValueList(const WString& value, EnumFitsValue valuelist) const{
		
		vint v;
		if (valuelist==FitsValue_Allowed) {
			v=GetAllowedValueList();
		}else{
			v=GetPresentValueList();
		}
		if(v.empty())
			return true; 
				
		bool myValue=value;
		int size = v.size();
		for (int i=0; i<size; i++) {
			if (myValue==(v[i] != 0))
				return true; // we have found it
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
		
	bool JDFBooleanState::FitsListType(const WString& value) const {
		
		vWString vBool = value.Tokenize();
		for (int i=0; i<vBool.size(); i++)
		{
			if (!vBool[i].isBoolean())
				return false;
		}
				
		EnumListType listtype=GetListType();

		switch (listtype) {
	
			case ListType_List:
			case ListType_Span:
			{
				return true;
			}
			case ListType_UniqueList:
			{
				int sz=vBool.size();
				for (int i=0; i<sz; i++)
				{
					for (int j=0; j<sz; j++)
					{
						if ( (j!=i)&&(!vBool[i].compare(vBool[j])) )
							return false; 
					}
				}
				return true;
			}
			case ListType_SingleValue:
			case ListType_Unknown: // default ListType = SingleValue
			{
				return value.isBoolean();
			}
			case ListType_CompleteList:
			case ListType_CompleteOrderedList:
			case ListType_ContainedList:
			case ListType_OrderedList:
			case ListType_UniqueOrderedList:
			case ListType_RangeList:
			case ListType_OrderedRangeList:
			case ListType_UniqueRangeList:
			case ListType_UniqueOrderedRangeList:
			default:
			{
				throw JDFException (L"JDFBooleanState::FitsListType illegal ListType attribute"); 
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	vint JDFBooleanState::GetAllowedValueList() const {
		vint v= GetEnumerationsAttribute(atr_AllowedValueList,AllowedValueListString());
		for (int i=v.size()-1; i>=0; i--) {
			if (v[i]==0){ // pos "Unknown" in enumeration = 0
				v.erase(v.begin()+i);
			}else{
				v.at(i)=v.at(i)-1; // enum (Unknown,false,true = 0, 1, 2) -> boolean (0, 1)
			}
		}
		return v;
	};

	//////////////////////////////////////////////////////////////////////
	void JDFBooleanState::SetAllowedValueList(const vint& value){
		SetEnumerationsAttribute(atr_AllowedValueList,value,AllowedValueListString());

	};
	//////////////////////////////////////////////////////////////////////
	vint JDFBooleanState::GetPresentValueList() const {
		if(HasAttribute(atr_PresentValueList)) {
			vint v= GetEnumerationsAttribute(atr_PresentValueList,AllowedValueListString());
			for (int i=v.size()-1; i>=0; i--) {
				if (v[i]==0){ // pos "Unknown" in enumeration = 0
					v.erase(v.begin()+i);
				}else{
					v.at(i)=v.at(i)-1; // enum (Unknown,false,true = 0, 1, 2) -> boolean (0, 1)
				}
			}
			return v;
		}
		return GetAllowedValueList();
	};

	//////////////////////////////////////////////////////////////////////
	void JDFBooleanState::SetPresentValueList(const vint& value){
		SetEnumerationsAttribute(atr_PresentValueList,value,AllowedValueListString());

	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	
	JDFValueLoc JDFBooleanState::GetValueLoc(int iSkip)const{
		JDFValueLoc e=GetElement(elm_ValueLoc,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFBooleanState::AppendValueLoc(){
		JDFValueLoc e=AppendElement(elm_ValueLoc);
		e.init();
		return e;
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

}