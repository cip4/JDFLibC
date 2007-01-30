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
// JDFShapeState.cpp: implementation of the JDFShapeState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFShapeState.h"
#include "JDFRangeList.h"

using namespace std;
namespace JDF{
	

	//////////////////////////////////////////////////////////////////////
	
	JDFShapeState& JDFShapeState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFShapeState: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFShapeState::ValidNodeNames()const{
		return L"*:,ShapeState";
	};
		
	//////////////////////////////////////////////////////////////////////
		
	WString JDFShapeState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",ValueLoc";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFShapeState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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

	WString JDFShapeState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedValueList,AllowedValueMax,AllowedValueMin,AllowedX,AllowedY,AllowedZ,PresentValueList,PresentValueMax,PresentValueMin,PresentX,PresentY,PresentZ";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFShapeState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
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
		if(!ValidAllowedX(level)) {
			vAtts.push_back(atr_AllowedX);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedY(level)) {
			vAtts.push_back(atr_AllowedY);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedZ(level)) {
			vAtts.push_back(atr_AllowedZ);
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
		if(!ValidPresentX(level)) {
			vAtts.push_back(atr_PresentX);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentY(level)) {
			vAtts.push_back(atr_PresentY);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentZ(level)) {
			vAtts.push_back(atr_PresentZ);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidAllowedValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueList,AttributeType_ShapeRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidAllowedValueMax(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueMax,AttributeType_shape,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidAllowedValueMin(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedValueMin,AttributeType_shape,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidAllowedX(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedX,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidAllowedY(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedY,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidAllowedZ(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedZ,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidPresentValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueList,AttributeType_ShapeRangeList,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidPresentValueMax(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueMax,AttributeType_shape,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidPresentValueMin(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentValueMin,AttributeType_shape,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidPresentX(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentX,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidPresentY(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentY,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeState::ValidPresentZ(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentZ,AttributeType_NumberRangeList,false);
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFShapeState::FitsValue(const WString& value, EnumFitsValue testlist) const{
		
		if (FitsListType(value))
		{
			JDFShapeRangeList rangelist(value);
		
			return (FitsValueList(rangelist,testlist)&& FitsXYZ(rangelist,testlist));
		}
		return false; // the value doesn't fit ListType attribute of this State
	}
	//////////////////////////////////////////////////////////////////////		
	
	bool JDFShapeState::FitsListType(const WString& value) const {

		EnumListType listtype=GetListType();

		JDFShapeRangeList rangelist;

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
				try { 
					JDFShape sh(value);
				}catch (IllegalArgumentException e){
					return false;
				}catch (JDFException e){
					return false;
				}
				return true;
			}
			default:
			{
				throw JDFException (L"JDFShapeState::FitsListType illegal ListType attribute"); 
			}

		}
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////		
	
	bool JDFShapeState::FitsValueList(const JDFShapeRangeList& rangelist, EnumFitsValue valuelist) const{

		JDFShapeRangeList list;

		if (valuelist==FitsValue_Allowed)
		{
			list= GetAllowedValueList();
		} else {
			list= GetPresentValueList();
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
			JDFShapeRange range = rangelist.at(i);

			if (list.IsPartOfRange(range)==false)
				return false;
		}
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFShapeState::FitsXYZ(const JDFShapeRangeList& rangelist, EnumFitsValue xyzlist) const{
	
		int siz=rangelist.size();
		for (int i=0; i<siz; i++)
		{	
			JDFShapeRange range = rangelist.at(i);
			
			NumberRangeList x,y,z;

			JDFShape left = range.GetLeft();
			JDFShape right = range.GetRight();

			double leftX = left.GetA();
			double rightX = right.GetA();
			NumberRange rangeX (leftX, rightX);

			double leftY = left.GetB();
			double rightY = right.GetB();
			NumberRange rangeY (leftY, rightY);

			double leftZ = left.GetC();
			double rightZ = right.GetC();
			NumberRange rangeZ (leftZ, rightZ);
				
			if (xyzlist==FitsValue_Allowed)
			{
				x=GetAllowedX();
				y=GetAllowedY();
				z=GetAllowedZ();
			}
			else {
				x=GetPresentX();
				y=GetPresentY();
				z=GetPresentZ();
			}

			bool bFit=true;
			if (x.size()!=0) {
				bFit=x.IsPartOfRange(rangeX);
			}
			if (!bFit)
				return false;

			if (y.size()!=0) {
				bFit=y.IsPartOfRange(rangeY);
			}
			if (!bFit)
				return false;

			if (z.size()!=0) {
				bFit=z.IsPartOfRange(rangeZ);
			}
			if (!bFit)
				return false;
		}
		return true;

	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFShapeState::FitsCompleteList(const JDFShapeRangeList& value, const JDFShapeRangeList& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}

		if (!value.IsUnique()) {
			return false;
		}

		JDFShapeRangeList valueList= value;

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

	bool JDFShapeState::FitsCompleteOrderedList(const JDFShapeRangeList& value, const JDFShapeRangeList& list) const{

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

	bool JDFShapeState::FitsContainedList(const JDFShapeRangeList& value, const JDFShapeRangeList& list) const{

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
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter/ Setter
	**************************************************************** */	
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	void JDFShapeState::SetAllowedValueList(const JDFShapeRangeList& value){
		SetAttribute(atr_AllowedValueList,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFShapeRangeList JDFShapeState::GetAllowedValueList() const {
		return GetAttribute(atr_AllowedValueList);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeState::SetPresentValueList(const JDFShapeRangeList& value){
		SetAttribute(atr_PresentValueList,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////
	
	JDFShapeRangeList JDFShapeState::GetPresentValueList() const {
		if (HasAttribute(atr_PresentValueList)) {
			return GetAttribute(atr_PresentValueList);
		}
		return GetAllowedValueList();
	};
	//////////////////////////////////////////////////////////////////////
	
	void JDFShapeState::SetAllowedX(const NumberRangeList& value){
		SetAttribute(atr_AllowedX,value);
	};
	//////////////////////////////////////////////////////////////////////

	NumberRangeList JDFShapeState::GetAllowedX() const {
		return GetAttribute(atr_AllowedX);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeState::SetPresentX(const NumberRangeList& value){
		SetAttribute(atr_PresentX,value);
	};
	//////////////////////////////////////////////////////////////////////
	
	NumberRangeList JDFShapeState::GetPresentX() const {
		if (HasAttribute(atr_PresentX)) {
			return GetAttribute(atr_PresentX);
		}
		return GetAllowedX();
	};
	//////////////////////////////////////////////////////////////////////
	
	void JDFShapeState::SetAllowedY(const NumberRangeList& value){
		SetAttribute(atr_AllowedY,value);
	};
	//////////////////////////////////////////////////////////////////////

	NumberRangeList JDFShapeState::GetAllowedY() const {
		return GetAttribute(atr_AllowedY);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeState::SetPresentY(const NumberRangeList& value){
		SetAttribute(atr_PresentY,value);
	};
	//////////////////////////////////////////////////////////////////////
	
	NumberRangeList JDFShapeState::GetPresentY() const {
		if (HasAttribute(atr_PresentY)) {
			return GetAttribute(atr_PresentY);
		}
		return GetAllowedY();
	};
	//////////////////////////////////////////////////////////////////////
	
	void JDFShapeState::SetAllowedZ(const NumberRangeList& value){
		SetAttribute(atr_AllowedZ,value);
	};
	//////////////////////////////////////////////////////////////////////

	NumberRangeList JDFShapeState::GetAllowedZ() const {
		return GetAttribute(atr_AllowedZ);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeState::SetPresentZ(const NumberRangeList& value){
		SetAttribute(atr_PresentZ,value);
	};
	//////////////////////////////////////////////////////////////////////
	
	NumberRangeList JDFShapeState::GetPresentZ() const {
		if (HasAttribute(atr_PresentZ)) {
			return GetAttribute(atr_PresentZ);
		}
		return GetAllowedZ();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeState::SetAllowedValueMax(const JDFShape& value){
		SetAttribute(atr_AllowedValueMax,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFShape JDFShapeState::GetAllowedValueMax() const {
		return GetAttribute(atr_AllowedValueMax);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeState::SetPresentValueMax(const JDFShape& value){
		SetAttribute(atr_PresentValueMax,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFShape JDFShapeState::GetPresentValueMax() const {
		if (HasAttribute(atr_PresentValueMax)){
			return GetAttribute(atr_PresentValueMax);
		}
		return GetAllowedValueMax();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeState::SetAllowedValueMin(const JDFShape& value){
		SetAttribute(atr_AllowedValueMin,value);
	};
	///////////////////////////////////////////////////////////////////////
	JDFShape JDFShapeState::GetAllowedValueMin() const {
		return GetAttribute(atr_AllowedValueMin);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeState::SetPresentValueMin(const JDFShape& value){
		SetAttribute(atr_PresentValueMin,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFShape JDFShapeState::GetPresentValueMin() const {
		if (HasAttribute(atr_PresentValueMin)){
			return GetAttribute(atr_PresentValueMin);
		}
		return GetAllowedValueMin();
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFShapeState::GetValueLoc(int iSkip)const{
		JDFValueLoc e=GetElement(elm_ValueLoc,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValueLoc JDFShapeState::AppendValueLoc(){
		JDFValueLoc e=AppendElement(elm_ValueLoc);
		e.init();
		return e;
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

}