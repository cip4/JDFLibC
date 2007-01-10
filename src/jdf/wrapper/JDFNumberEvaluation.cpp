/*
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
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  17.03.2004
//
// JDFNumberEvaluation.cpp: implementation of the JDFNumberEvaluation 
//
//////////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/JDFNumberEvaluation.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"
#include <math.h>

namespace JDF{
/**
* copy equivalance operator
*/
	//////////////////////////////////////////////////////////////////////

	const double JDFNumberEvaluation::dt=0.00000001;
	
	//////////////////////////////////////////////////////////////////////

	JDFNumberEvaluation& JDFNumberEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFNumberEvaluation: "+other.GetNodeName());
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFNumberEvaluation::ValidNodeNames()const{
		return L"*:,NumberEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFNumberEvaluation::IsAbstract()const{
		return false;
	}
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFNumberEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",Tolerance,ValueList,ValueMod";
	};

	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFNumberEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFEvaluation::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTolerance(level)) {
			vAtts.push_back(atr_Tolerance);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValueList(level)) {
			vAtts.push_back(atr_ValueList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValueMod(level)) {
			vAtts.push_back(atr_ValueMod);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFNumberEvaluation::ValidValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueList,AttributeType_NumberRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFNumberEvaluation::ValidValueMod(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueMod,AttributeType_XYPair,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFNumberEvaluation::ValidTolerance(EnumValidationLevel level) const {
		return ValidAttribute(atr_Tolerance,AttributeType_XYPair,false);
	}
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	void JDFNumberEvaluation::SetValueList(const JDFNumberRangeList& value){
		SetAttribute(atr_ValueList,value);
	};
	//////////////////////////////////////////////////////////////////////

	JDFNumberRangeList JDFNumberEvaluation::GetValueList() const {
		return GetAttribute(atr_ValueList,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFNumberEvaluation::SetValueMod(const JDFXYPair& value){
		SetAttribute(atr_ValueMod,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFNumberEvaluation::GetValueMod() const {
		return GetAttribute(atr_ValueMod);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFNumberEvaluation::SetTolerance(const JDFXYPair& value){
		SetAttribute(atr_Tolerance,value);
	}
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFNumberEvaluation::GetTolerance() const {
		return GetAttribute(atr_Tolerance,WString::emptyStr,L"0 0");
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFNumberEvaluation::FitsValue(const WString& value) const{
		
		if (!FitsListType(value))
		{
			return false;
		}
		
		JDFNumberRangeList rangelist(value);
		int siz=rangelist.size();
		for (int i=0; i<siz; i++) {
			if (!FitsValueMod(rangelist.at(i)))
				return false;
		}
		return (FitsValueList(rangelist));
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFNumberEvaluation::FitsListType(const WString& value) const {

		JDFNumberRangeList rangelist;

		try {
			 rangelist=value;						
		}catch (IllegalArgumentException e){
			return false;
		}catch (JDFException e){
			return false;
		}

		JDFBasicPreflightTest::EnumListType listtype = GetBasicPreflightTest().GetListType();
		
		switch (listtype) {
	
			case JDFBasicPreflightTest::ListType_CompleteList:
			{
				return rangelist.IsList(); // if it is comlete list or not will be tested in FitsValueList->FitsCompleteList
			}
			case JDFBasicPreflightTest::ListType_CompleteOrderedList:
			{
				return rangelist.IsList();  // if it is comlete ordered list or not will be tested in FitsValueList->FitsCompleteOrderedList
			}
			case JDFBasicPreflightTest::ListType_ContainedList:
			{
				return rangelist.IsList(); // if it is contained list or not will be tested in FitsValueList->FitsContainedList
			}
			case JDFBasicPreflightTest::ListType_List:
			{
				return rangelist.IsList();
			}
			case JDFBasicPreflightTest::ListType_OrderedList:
			{
				return (rangelist.IsList()&&rangelist.IsOrdered());
			}
			case JDFBasicPreflightTest::ListType_UniqueList:
			{
				return (rangelist.IsList()&&rangelist.IsUnique());
			}
			case JDFBasicPreflightTest::ListType_UniqueOrderedList:
			{
				return (rangelist.IsList()&&rangelist.IsUniqueOrdered());
			}
			case JDFBasicPreflightTest::ListType_RangeList:
			case JDFBasicPreflightTest::ListType_Span:
			{
				return true;
			}
			case JDFBasicPreflightTest::ListType_OrderedRangeList:
			{
				return rangelist.IsOrdered();
			}
			case JDFBasicPreflightTest::ListType_UniqueRangeList:
			{
				return rangelist.IsUnique();
			}
			case JDFBasicPreflightTest::ListType_UniqueOrderedRangeList:
			{
				return (rangelist.IsUniqueOrdered());
			}
			case JDFBasicPreflightTest::ListType_SingleValue:
			case JDFBasicPreflightTest::ListType_Unknown: // default ListType = SingleValue
			{
				return value.isNumber();
			}
			default:
			{
				throw JDFException (L"JDFNumberEvaluation::FitsListType illegal ListType attribute"); 
			}
		}
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNumberEvaluation::FitsValueList(const JDFNumberRangeList& rangelist) const{

		if (!HasAttribute(atr_ValueList)) {
			return true;
		}
		
		JDFNumberRangeList list = GetValueList();

		JDFBasicPreflightTest::EnumListType listType = GetListType(); // gets ListType of BasicPreflightTest or State

		if (listType==JDFBasicPreflightTest::ListType_CompleteList){
			return FitsCompleteList(rangelist,list);
		}
		else if (listType==JDFBasicPreflightTest::ListType_CompleteOrderedList){ 
			return FitsCompleteOrderedList(rangelist,list);
		}
		else if (listType==JDFBasicPreflightTest::ListType_ContainedList){
			return FitsContainedList(rangelist,list);
		}

		if (HasAttribute(atr_Tolerance)) {
			list = FitsTolerance(list);
		}	
		return (!list.IsPartOfRange(rangelist));

	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFNumberEvaluation::FitsValueMod(const NumberRange& range) const{
		
		if (!HasAttribute(atr_ValueMod)) {	
			return true;
		}
		double left = range.GetLeft();
		double right = range.GetRight();
		
		if (left!=right) {// if we have a range return false, work only with single value
			return false;
		}
		double elem=left; // single value 
		
		JDFXYPair mod = GetValueMod();
			
		double divi = mod.GetX();// X - the Modulo
		double shift = mod.GetY();// Y - offset

		if (divi==0) { // ValueMod can't be "0 x"
			return false;
		}
		
		double nt; // negative tolerance
		double pt; // positive tolerance
		
		if (HasAttribute(atr_Tolerance)) {
			nt = GetTolerance().GetX(); 
			pt = GetTolerance().GetY();
		} else {
			nt = pt = dt;
		}

		double n = ((elem-divi*(int)(elem/divi))-shift); // n = ( elem % divi - shift )
		if ( fabs(n)<pt || fabs(n)>(divi-nt) ) {
			return true;
		}

		double m = (n-divi*(int)(n/divi)); // m = ( elem % divi - shift ) % divi
		if  ( fabs(m)<pt || fabs(m)>(divi-nt) ) {
			return true;
		}
		return false;

	}

	//////////////////////////////////////////////////////////////////////

	JDFNumberRangeList JDFNumberEvaluation::FitsTolerance(const JDFNumberRangeList& origRangeList) const{
		
		double nt = GetTolerance().GetX(); // negative tolerance
		double pt = GetTolerance().GetY(); // positive tolerance
		
		if ((nt==0)&&(pt==0)) {
			return origRangeList;
		}
		
		// expand our original range into the range +/- Tolerance

		NumberRangeList rangeList = origRangeList;

		NumberRangeList tolRangeList;
		
		int size = rangeList.size();
		for (int i=0; i<size; i++) 
		{
			NumberRange range=rangeList.at(i);
			NumberRange r;
			r.SetLeft(range.GetLeft()-nt);
			r.SetRight(range.GetRight()+pt);
			
			tolRangeList.Append(r);
		}
		
		return tolRangeList;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFNumberEvaluation::FitsCompleteList(const JDFNumberRangeList& value, const JDFNumberRangeList& list) const{

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

	bool JDFNumberEvaluation::FitsCompleteOrderedList(const JDFNumberRangeList& value, const JDFNumberRangeList& list) const{

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

	bool JDFNumberEvaluation::FitsContainedList(const JDFNumberRangeList& value, const JDFNumberRangeList& list) const{

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
}; // namespace JDF
