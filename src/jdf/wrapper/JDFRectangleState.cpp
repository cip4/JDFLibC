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
// JDFRectangleState.cpp: implementation of the JDFRectangleState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFRectangleState.h"
#include "JDFRangeList.h"

using namespace std;
namespace JDF{

	
	//////////////////////////////////////////////////////////////////////
	
	JDFRectangleState& JDFRectangleState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFRectangleState: "+other.GetNodeName()); 
		return *this;
	};
	//////////////////////////////////////////////////////////////////////
	
	WString JDFRectangleState::ValidNodeNames()const{
		return L"*:,RectangleState";
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFRectangleState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",ValueLoc";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFRectangleState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFRectangleState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedHWRelation,AllowedValueList,PresentHWRelation,PresentValueList";
	};
	
	//////////////////////////////////////////////////////////////////////

	vWString JDFRectangleState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFStateBase::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidAllowedHWRelation(level)) {
			vAtts.push_back(atr_AllowedHWRelation);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedValueList(level)) {
			vAtts.push_back(atr_AllowedValueList);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentHWRelation(level)) {
			vAtts.push_back(atr_PresentHWRelation);
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
	bool JDFRectangleState::ValidAllowedHWRelation(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowedHWRelation,AttributeType_XYRelation,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFRectangleState::ValidPresentHWRelation(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentHWRelation,AttributeType_XYRelation,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFRectangleState::ValidAllowedValueList(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowedValueList,AttributeType_RectangleRangeList,false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFRectangleState::ValidPresentValueList(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentValueList,AttributeType_RectangleRangeList,false);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFRectangleState::FitsValue(const WString& value, EnumFitsValue testlist) const{
		
		if (FitsListType(value))
		{
			JDFRectangleRangeList rrl(value);

			int siz=rrl.size();
			for (int i=0; i<siz; i++) // For every range, that rangelist consists of,
			{						  // we test both of range deliminators - right and left, if they fit HWRelation
									  // In this case test of deliminators is sufficient for evaluation of the whole range
				JDFRectangleRange range=rrl.at(i);
					
				JDFRectangle left = range.GetLeft();
				JDFRectangle right = range.GetRight();
				
				bool bFitsHW;
				if (left==right) {
					bFitsHW = FitsHWRelation(left,testlist);
				} else {
					bFitsHW = FitsHWRelation(left,testlist)&&FitsHWRelation(right,testlist);
				}
				if (!bFitsHW)
					return false;
			}
			return FitsValueList(rrl,testlist); // if we are here bFitsHW is true, test ValueList
		}
		return false; // the value doesn't fit ListType attribute of this State
	}

	//////////////////////////////////////////////////////////////////////
	
	bool JDFRectangleState::FitsListType(const WString& value) const {

		JDFRectangleRangeList rangelist;

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
				try { 
					JDFRectangle r(value);
				}catch (IllegalArgumentException e){
					return false;
				}catch (JDFException e){
					return false;
				}
				return true;
			}
			default:
			{
				throw JDFException (L"JDFRectangleState::FitsListType illegal ListType attribute"); 
			}
		}

	}

	//////////////////////////////////////////////////////////////////////

	bool JDFRectangleState::FitsValueList(const JDFRectangleRangeList& rangelist, EnumFitsValue valuelist) const{

		JDFRectangleRangeList list;

		if (valuelist==FitsValue_Allowed)
		{
			list= GetAllowedValueList();
		} 
		else {
			list= GetPresentValueList();
		}
		if(list.size()==0) {
			return true;
		}
		
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
			JDFRectangleRange range = rangelist.at(i);

			if (list.IsPartOfRange(range)==false)
				return false;
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFRectangleState::FitsHWRelation(const JDFRectangle& rect, EnumFitsValue hwrelation) const{
		
		EnumXYRelation relation;
		
		if (hwrelation==FitsValue_Allowed)
		{
			relation= GetAllowedHWRelation();
		} 
		else {
			relation= GetPresentHWRelation();
		}
		
		if (relation==JDFElement::XYRelation_Unknown) {
			return true;
		}

		double width = rect.GetUrx() - rect.GetLlx();
		double height = rect.GetUry() - rect.GetLly();
		
		return XYRelation(relation,width,height);

	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFRectangleState::FitsCompleteList(const JDFRectangleRangeList& value, const JDFRectangleRangeList& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}

		if (!value.IsUnique()) {
			return false;
		}

		JDFRectangleRangeList valueList= value;

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

	bool JDFRectangleState::FitsCompleteOrderedList(const JDFRectangleRangeList& value, const JDFRectangleRangeList& list) const{

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

	bool JDFRectangleState::FitsContainedList(const JDFRectangleRangeList& value, const JDFRectangleRangeList& list) const{

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
	// Attribute Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFRectangleState::SetAllowedValueList(const JDFRectangleRangeList& value){
		SetAttribute(atr_AllowedValueList,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFRectangleRangeList JDFRectangleState::GetAllowedValueList() const {
		return GetAttribute(atr_AllowedValueList);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFRectangleState::SetPresentValueList(const JDFRectangleRangeList& value){
		SetAttribute(atr_PresentValueList,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////
	
	JDFRectangleRangeList JDFRectangleState::GetPresentValueList() const {
		if (HasAttribute(atr_PresentValueList)) 
			return GetAttribute(atr_PresentValueList);
		return GetAllowedValueList();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFRectangleState::SetAllowedHWRelation( EnumXYRelation value){
		SetEnumAttribute(atr_AllowedHWRelation,value,XYRelationString());
	};
	
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumXYRelation JDFRectangleState::GetAllowedHWRelation() const {
		return (JDFElement::EnumXYRelation) GetEnumAttribute(atr_AllowedHWRelation,XYRelationString());
	};
	
	//////////////////////////////////////////////////////////////////////
	void JDFRectangleState::SetPresentHWRelation(EnumXYRelation value){
		SetEnumAttribute(atr_PresentHWRelation,value,XYRelationString());
	};
	
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumXYRelation JDFRectangleState::GetPresentHWRelation() const {
		JDFElement::EnumXYRelation rel=(JDFElement::EnumXYRelation) GetEnumAttribute(atr_PresentHWRelation,XYRelationString());
			if (rel==JDFElement::XYRelation_Unknown){
				return GetAllowedHWRelation();
			}
		return rel;
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFRectangleState::GetValueLoc(int iSkip)const{
		JDFValueLoc e=GetElement(elm_ValueLoc,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFRectangleState::AppendValueLoc(){
		JDFValueLoc e=AppendElement(elm_ValueLoc);
		e.init();
		return e;
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}