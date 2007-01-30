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
// JDFNumberState.cpp: implementation of the JDFNumberState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFNumberState.h"
#include "JDFValueLoc.h"
#include <math.h>

using namespace std;
namespace JDF{
	
	//////////////////////////////////////////////////////////////////////

	const double JDFNumberState::dt=0.00000001;

	//////////////////////////////////////////////////////////////////////
	
	JDFNumberState& JDFNumberState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFNumberState: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFNumberState::ValidNodeNames()const{
		return L"*:,NumberState";
	};
	
	//////////////////////////////////////////////////////////////////////
		
	WString JDFNumberState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",ValueLoc";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFNumberState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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

	WString JDFNumberState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedValueList,AllowedValueMax,AllowedValueMin,AllowedValueMod,PresentValueList,PresentValueMax,PresentValueMin,PresentValueMod,UnitType";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFNumberState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFStateBase::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidAllowedValueList(level)) {
			vAtts.push_back(atr_AllowedValueList);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedValueMax(level)) {
			vAtts.push_back(atr_AllowedValueMax);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedValueMin(level)) {
			vAtts.push_back(atr_AllowedValueMin);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedValueMod(level)) {
			vAtts.push_back(atr_AllowedValueMod);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentValueList(level)) {
			vAtts.push_back(atr_PresentValueList);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentValueMax(level)) {
			vAtts.push_back(atr_PresentValueMax);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentValueMin(level)) {
			vAtts.push_back(atr_PresentValueMin);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentValueMod(level)) {
			vAtts.push_back(atr_PresentValueMod);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidUnitType(level)) {
			vAtts.push_back(atr_UnitType);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidAllowedValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueList,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidAllowedValueMax(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueMax,AttributeType_double,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidAllowedValueMin(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueMin,AttributeType_double,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidAllowedValueMod(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueMod,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidPresentValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueList,AttributeType_NumberRangeList,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidPresentValueMax(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueMax,AttributeType_double,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidPresentValueMin(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueMin,AttributeType_double,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidPresentValueMod(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueMod,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNumberState::ValidUnitType(EnumValidationLevel level)const{
		return ValidAttribute(atr_UnitType,AttributeType_NMTOKEN,false);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFNumberState::FitsValue(const WString& value, EnumFitsValue testlist) const{
		
		if (FitsListType(value))
		{
			JDFNumberRangeList rangelist(value);
			
			return (FitsValueList(rangelist,testlist)&&FitsValueMod(rangelist,testlist));
		}
		return false; // the value doesn't fit ListType attribute of this State
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFNumberState::FitsListType(const WString& value) const {

		EnumListType listtype=GetListType();

		JDFNumberRangeList rangelist;

		try {
			 rangelist=value;						
		}catch (IllegalArgumentException e){
			return false;
		}catch (JDFException e){
			return false;
		}

		switch (listtype) {
	
			case ListType_CompleteList:
			{
				return rangelist.IsList(); // if it is comlete list or not will be tested in FitsValueList->FitsCompleteList
			}
			case ListType_CompleteOrderedList:
			{
				return rangelist.IsList();  // if it is comlete ordered list or not will be tested in FitsValueList->FitsCompleteOrderedList
			}
			case ListType_ContainedList:
			{
				return rangelist.IsList(); // if it is contained list or not will be tested in FitsValueList->FitsContainedList
			}
			case ListType_List:
			{
				return rangelist.IsList();
			}
			case ListType_OrderedList:
			{
				return (rangelist.IsList()&&rangelist.IsOrdered());
			}
			case ListType_UniqueList:
			{
				return (rangelist.IsList()&&rangelist.IsUnique());
			}
			case ListType_UniqueOrderedList:
			{
				return (rangelist.IsList()&&rangelist.IsUniqueOrdered());
			}
			case ListType_RangeList:
			case ListType_Span:
			{
				return true;
			}
			case ListType_OrderedRangeList:
			{
				return rangelist.IsOrdered();
			}
			case ListType_UniqueRangeList:
			{
				return rangelist.IsUnique();
			}
			case ListType_UniqueOrderedRangeList:
			{
				return (rangelist.IsUniqueOrdered());
			}
			case ListType_SingleValue:
			case ListType_Unknown: // default ListType = SingleValue
			{
				return value.isNumber();
			}
			default:
			{
				throw JDFException (L"JDFNumberState::FitsListType illegal ListType attribute"); 
			}
		}
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFNumberState::FitsValueList(const NumberRangeList& rangelist, EnumFitsValue valuelist) const{

		NumberRangeList list;

		if (valuelist==FitsValue_Allowed)
		{
			list = GetAllowedValueList();
		} 
		else {
			list = GetPresentValueList();
		}
		if(list.size()==0)
			return true;
		
		if (GetListType()==ListType_CompleteList){
			return FitsCompleteList(rangelist,list);
		}
		else if (GetListType()==ListType_CompleteOrderedList){ 
			return FitsCompleteOrderedList(rangelist,list);
		}
		else if (GetListType()==ListType_ContainedList){
			return FitsContainedList(rangelist,list);
		}

		int siz=rangelist.size();
		for (int i=0; i<siz; i++)
		{
			NumberRange range = rangelist.at(i);

			if (list.IsPartOfRange(range)==false)
				return false;
		}
		return true;
	}
		
	//////////////////////////////////////////////////////////////////////
	
	bool JDFNumberState::FitsValueMod(const NumberRangeList& rangelist, EnumFitsValue valuemod) const{
		
		if (valuemod==FitsValue_Allowed) {
			if(!HasAttribute(atr_AllowedValueMod))
				return true;
		} else {
			if(!HasAttribute(atr_AllowedValueMod)&&!HasAttribute(atr_PresentValueMod))
				return true;
		}
		
		JDFXYPair mod;
		if (valuemod==FitsValue_Allowed) {
			mod = GetAllowedValueMod();
		} else {
			mod = GetPresentValueMod();
		}

		
		int siz=rangelist.size();
		for (int i=0; i<siz; i++)
		{
			NumberRange range = rangelist.at(i);

			double left = range.GetLeft();
			double right = range.GetRight();
			if (left!=right) {// if we have a range return false, check only single value
				return false;
			}
			double elem=left; // single value 
			double divi = mod.GetX(); // X - the Modulo
			double shift = mod.GetY(); // Y - offset of the allowed/present value

			if (divi==0) {
				return false;
			}
			else // if ValueMod is not "0 x"
			{	
				double n = ((elem-divi*(int)(elem/divi))-shift); // n = elem % divi - shift
				if ( fabs(n)<dt*fabs(divi) ) {
					return true;
				}
					
				double m = (n-divi*(int)(n/divi)); // m = ( elem % divi - shift ) % divi
				if  ( fabs(m)<dt*fabs(divi) ) {
					return true;
				}
				return false;
			}
		}
		return true;
	
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFNumberState::FitsCompleteList(const JDFNumberRangeList& value, const JDFNumberRangeList& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}

		if (!value.IsUnique()) {
			return false;
		}

		JDFNumberRangeList valueList= value;

		bool bFound;
		for (int i=l_size-1; i>=0; i--)
		{
			bFound=false;
			for (int j=valueList.size()-1; j>=0; j--)
			{
				if (list.at(i)==valueList.at(j))
				{
					valueList.erase(j);
					bFound=true;
					break;
				}
			}
			if (!bFound) {
				return false;
			}
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNumberState::FitsCompleteOrderedList(const JDFNumberRangeList& value, const JDFNumberRangeList& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}

		if (!value.IsUnique()) {
			return false;
		}
		for (int i=0; i<l_size; i++)
		{
			if (list.at(i)!=value.at(i)) 
			{
				return false;
			}
		}
		return true;		
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNumberState::FitsContainedList(const JDFNumberRangeList& value, const JDFNumberRangeList& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		for (int i=0; i<v_size; i++)
		{
			for (int j=0; j<l_size; j++)
			{
				if (value.at(i)==list.at(j)) 
					return true;
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
	
	void JDFNumberState::SetAllowedValueList(const NumberRangeList& value){
		SetAttribute(atr_AllowedValueList,value);
	};
	//////////////////////////////////////////////////////////////////////

	NumberRangeList JDFNumberState::GetAllowedValueList() const {
		return GetAttribute(atr_AllowedValueList,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberState::SetPresentValueList(const NumberRangeList& value){
		SetAttribute(atr_PresentValueList,value);
	};
	//////////////////////////////////////////////////////////////////////
	
	NumberRangeList JDFNumberState::GetPresentValueList() const {
		if (HasAttribute(atr_PresentValueList)) {
			return GetAttribute(atr_PresentValueList,WString::emptyStr);
		}
		return GetAllowedValueList();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberState::SetAllowedValueMax(double value){
		SetAttribute(atr_AllowedValueMax,value);
	};
	//////////////////////////////////////////////////////////////////////
	double JDFNumberState::GetAllowedValueMax() const {
		return GetRealAttribute(atr_AllowedValueMax);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberState::SetPresentValueMax(double value){
		SetAttribute(atr_PresentValueMax,value);
	};
	//////////////////////////////////////////////////////////////////////
	double JDFNumberState::GetPresentValueMax() const {
		if (HasAttribute(atr_PresentValueMax)){
			return GetRealAttribute(atr_PresentValueMax);
		}
		return GetAllowedValueMax();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberState::SetAllowedValueMin(double value){
		SetAttribute(atr_AllowedValueMin,value);
	};
	///////////////////////////////////////////////////////////////////////
	double JDFNumberState::GetAllowedValueMin() const {
		return GetRealAttribute(atr_AllowedValueMin);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberState::SetPresentValueMin(double value){
		SetAttribute(atr_PresentValueMin,value);
	};
	//////////////////////////////////////////////////////////////////////
	double JDFNumberState::GetPresentValueMin() const {
		if (HasAttribute(atr_PresentValueMin)){
			return GetRealAttribute(atr_PresentValueMin);
		}
		return GetAllowedValueMin();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberState::SetAllowedValueMod(const JDFXYPair& value){
		SetAttribute(atr_AllowedValueMod,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFNumberState::GetAllowedValueMod() const {
		return GetAttribute(atr_AllowedValueMod);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberState::SetPresentValueMod(const JDFXYPair& value){
		SetAttribute(atr_PresentValueMod,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFNumberState::GetPresentValueMod() const {
		if (HasAttribute(atr_PresentValueMod)){
			return GetAttribute(atr_PresentValueMod);
		}
		return GetAllowedValueMod();
	};
	//////////////////////////////////////////////////////////////////////
	
	WString JDFNumberState::GetUnitType()const{
		return GetAttribute(atr_UnitType);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberState::SetUnitType(const WString& value){
		SetAttribute(atr_UnitType,value);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFNumberState::GetValueLoc(int iSkip)const{
		JDFValueLoc e=GetElement(elm_ValueLoc,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFNumberState::AppendValueLoc(){
		JDFValueLoc e=AppendElement(elm_ValueLoc);
		e.init();
		return e;
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

}