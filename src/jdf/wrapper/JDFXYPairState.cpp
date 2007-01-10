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
// created  28.01.2004
//
// JDFXYPairState.cpp: implementation of the JDFXYPairState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFXYPairState.h"
#include "JDFValueLoc.h"

using namespace std;
namespace JDF{
	
	
	//////////////////////////////////////////////////////////////////////
	
	JDFXYPairState& JDFXYPairState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFXYPairState: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
			
	WString JDFXYPairState::ValidNodeNames()const{
		return L"*:,XYPairState";
	};
		
	//////////////////////////////////////////////////////////////////////

	WString JDFXYPairState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",ValueLoc";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFXYPairState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFXYPairState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedValueList,AllowedValueMax,AllowedValueMin,AllowedXYRelation,PresentValueList,PresentValueMax,PresentValueMin,PresentXYRelation,UnitType";
	};
	
	//////////////////////////////////////////////////////////////////////

	vWString JDFXYPairState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
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
		if(!ValidAllowedXYRelation(level)) {
			vAtts.push_back(atr_AllowedXYRelation);
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
		if(!ValidPresentXYRelation(level)) {
			vAtts.push_back(atr_PresentXYRelation);
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
	bool JDFXYPairState::ValidAllowedValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueList,AttributeType_XYPairRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairState::ValidAllowedValueMax(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueMax,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairState::ValidAllowedValueMin(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueMin,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairState::ValidAllowedXYRelation(EnumValidationLevel level)const{
		return ValidEnumAttribute(atr_AllowedXYRelation,XYRelationString(),false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairState::ValidPresentValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueList,AttributeType_XYPairRangeList,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairState::ValidPresentValueMax(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueMax,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairState::ValidPresentValueMin(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueMin,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairState::ValidPresentXYRelation(EnumValidationLevel level)const{
		return ValidEnumAttribute(atr_PresentXYRelation,XYRelationString(),false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairState::ValidUnitType(EnumValidationLevel level)const{
		return ValidAttribute(atr_UnitType,AttributeType_NMTOKEN,false);
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFXYPairState::FitsValue(const WString& value, EnumFitsValue testlist) const{
		
		if (FitsListType(value))
		{
			JDFXYPairRangeList rangelist(value);

			int siz=rangelist.size();
			for (int i=0; i<siz; i++) // For every range, that rangelist consists of,
			{						  // we test both of range deliminators - right and left, if they fit XYRelation
									  // In this case test of deliminators is sufficient for evaluation of the whole range
				JDFXYPairRange range=rangelist.at(i);
					
				JDFXYPair left = range.GetLeft();
				JDFXYPair right = range.GetRight();
				
				bool bFitsXY;
				if (left==right) {
					bFitsXY = FitsXYRelation(left,testlist);
				} else {
					bFitsXY = FitsXYRelation(left,testlist)&&FitsXYRelation(right,testlist);
				}
				if (bFitsXY==false)
					return false;
			}
			return FitsValueList(rangelist,testlist); // if we are here bFitsXY is true, test ValueList
		}
		return false; // the value doesn't fit ListType attribute of this State
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFXYPairState::FitsListType(const WString& value) const {
			
		JDFXYPairRangeList rangelist;

		try {
			 rangelist=value;						
		}catch (IllegalArgumentException e){
			return false;
		}catch (JDFException e){
			return false;
		}

		EnumListType listtype=GetListType();

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
				try{
					JDFXYPair xypair(value);
				}catch (JDFException e){
					return false;
				}catch (IllegalArgumentException ie){
					return false;
				}
				return true;
			}
			default:
			{
				throw JDFException (L"JDFXYPairState::FitsListType illegal ListType attribute"); 
			}
		}
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairState::FitsValueList(const JDFXYPairRangeList& rangelist, EnumFitsValue valuelist) const{
		
		JDFXYPairRangeList list;

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
			JDFXYPairRange range = rangelist.at(i);

			if (list.IsPartOfRange(range)==false)
				return false;
		}
		return true;
	}
		
	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairState::FitsXYRelation(const JDFXYPair& xypair, EnumFitsValue xyrelation) const{

		EnumXYRelation relation;
		
		if (xyrelation==FitsValue_Allowed)
		{
			relation = GetAllowedXYRelation();
		} 
		else {
			relation = GetPresentXYRelation();
		}
		
		if (relation==JDFElement::XYRelation_Unknown)
			return true;
	
		double x = xypair.GetX();
		double y = xypair.GetY();
		
		return XYRelation(relation,x,y);

	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairState::FitsCompleteList(const JDFXYPairRangeList& value, const JDFXYPairRangeList& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}

		if (!value.IsUnique()) {
			return false;
		}

		JDFXYPairRangeList valueList= value;

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

	bool JDFXYPairState::FitsCompleteOrderedList(const JDFXYPairRangeList& value, const JDFXYPairRangeList& list) const{

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

	bool JDFXYPairState::FitsContainedList(const JDFXYPairRangeList& value, const JDFXYPairRangeList& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		for (int i=0; i<v_size; i++)
		{
			for (int j=0; j<l_size; j++)
			{
				if (value.at(i)==list.at(j)) 
				{
					return true;
				}
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
	
	void JDFXYPairState::SetAllowedValueList(const JDFXYPairRangeList& value){
		SetAttribute(atr_AllowedValueList,value);
	};
	//////////////////////////////////////////////////////////////////////

	JDFXYPairRangeList JDFXYPairState::GetAllowedValueList() const {
		return GetAttribute(atr_AllowedValueList);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairState::SetPresentValueList(const JDFXYPairRangeList& value){
		SetAttribute(atr_PresentValueList,value);
	};
	//////////////////////////////////////////////////////////////////////
	
	JDFXYPairRangeList JDFXYPairState::GetPresentValueList() const {
		if (HasAttribute(atr_PresentValueList)) {
			return GetAttribute(atr_PresentValueList);
		}
		return GetAllowedValueList();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairState::SetAllowedValueMax(const JDFXYPair& value){
		SetAttribute(atr_AllowedValueMax,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFXYPairState::GetAllowedValueMax() const {
		return GetAttribute(atr_AllowedValueMax);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairState::SetPresentValueMax(const JDFXYPair& value){
		SetAttribute(atr_PresentValueMax,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFXYPairState::GetPresentValueMax() const {
		if (HasAttribute(atr_PresentValueMax)){
			return GetAttribute(atr_PresentValueMax);
		}
		return GetAllowedValueMax();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairState::SetAllowedValueMin(const JDFXYPair& value){
		SetAttribute(atr_AllowedValueMin,value);
	};
	///////////////////////////////////////////////////////////////////////
	JDFXYPair JDFXYPairState::GetAllowedValueMin() const {
		return GetAttribute(atr_AllowedValueMin);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairState::SetPresentValueMin(const JDFXYPair& value){
		SetAttribute(atr_PresentValueMin,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFXYPairState::GetPresentValueMin() const {
		if (HasAttribute(atr_PresentValueMin)){
			return GetAttribute(atr_PresentValueMin);
		}
		return GetAllowedValueMin();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairState::SetAllowedXYRelation( EnumXYRelation value){
		SetEnumAttribute(atr_AllowedXYRelation,value,XYRelationString());
	};
	
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumXYRelation JDFXYPairState::GetAllowedXYRelation() const {
		return (JDFElement::EnumXYRelation) GetEnumAttribute(atr_AllowedXYRelation,XYRelationString());
	};
	
	//////////////////////////////////////////////////////////////////////
	void JDFXYPairState::SetPresentXYRelation(EnumXYRelation value){
		SetEnumAttribute(atr_PresentXYRelation,value,XYRelationString());
	};
	
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumXYRelation JDFXYPairState::GetPresentXYRelation() const {
		JDFElement::EnumXYRelation rel=(JDFElement::EnumXYRelation) GetEnumAttribute(atr_PresentXYRelation,XYRelationString());
			if (rel==JDFElement::XYRelation_Unknown){
				return GetAllowedXYRelation();
			}
		return rel;
	};
	//////////////////////////////////////////////////////////////////////
	
	WString JDFXYPairState::GetUnitType()const{
		return GetAttribute(atr_UnitType);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairState::SetUnitType(const WString& value){
		SetAttribute(atr_UnitType,value);
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFXYPairState::GetValueLoc(int iSkip)const{
		JDFValueLoc e=GetElement(elm_ValueLoc,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFXYPairState::AppendValueLoc(){
		JDFValueLoc e=AppendElement(elm_ValueLoc);
		e.init();
		return e;
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////


}