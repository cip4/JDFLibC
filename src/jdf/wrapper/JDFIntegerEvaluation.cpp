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
// JDFIntegerEvaluation.cpp: implementation of the JDFIntegerEvaluation 
//
//////////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/JDFIntegerEvaluation.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"

namespace JDF{
/**
* copy equivalance operator
*/
	JDFIntegerEvaluation& JDFIntegerEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFIntegerEvaluation: "+other.GetNodeName());
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFIntegerEvaluation::ValidNodeNames()const{
		return L"*:,IntegerEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFIntegerEvaluation::IsAbstract()const{
		return false;
	}
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFIntegerEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",ValueList,ValueMod";
	};

	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFIntegerEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFEvaluation::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
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
	bool JDFIntegerEvaluation::ValidValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueList,AttributeType_IntegerRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFIntegerEvaluation::ValidValueMod(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueMod,AttributeType_XYPair,false);
	}

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	void JDFIntegerEvaluation::SetValueList(const JDFIntegerRangeList& value){
		SetAttribute(atr_ValueList,value);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFIntegerEvaluation::appendValueList(int value)
	{
		JDFIntegerRangeList irl = GetValueList();
		irl.Append(value);
		SetValueList(irl);
	}
	//////////////////////////////////////////////////////////////////////

	JDFIntegerRangeList JDFIntegerEvaluation::GetValueList() const {
		return GetAttribute(atr_ValueList,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFIntegerEvaluation::SetValueMod(const JDFXYPair& value){
		SetAttribute(atr_ValueMod,value);
	};
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFIntegerEvaluation::GetValueMod() const {
		return GetAttribute(atr_ValueMod);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFIntegerEvaluation::FitsValue(const WString& value) const{
				
		if (! FitsListType(value))
		{
			return false;
		}
	
		JDFIntegerRangeList rangelist(value);

		return (FitsValueList(rangelist) && FitsValueMod(rangelist));
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerEvaluation::FitsListType(const WString& value) const {

		JDFIntegerRangeList rangelist;

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
				return value.isInteger();
			}
			default:
			{
				throw JDFException (L"JDFIntegerEvaluation::FitsListType illegal ListType attribute"); 
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerEvaluation::FitsValueList(const JDFIntegerRangeList& rangelist) const{
			
		if (!HasAttribute(atr_ValueList)) {
			return true;
		}

		JDFIntegerRangeList list=GetValueList();
		
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

		int siz=rangelist.size();
		for (int i=0; i<siz; i++)
		{
			if (!list.IsPartOfRange(rangelist.at(i)))
				return false;
		}
		return true;
		
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFIntegerEvaluation::FitsValueMod(const JDFIntegerRangeList& rangelist) const{
		
		if (!HasAttribute(atr_ValueMod))	{
			return true;
		}			
		JDFXYPair mod = GetValueMod();

		int divi = (int) (mod.GetX()+0.5); // X - the Modulo
		int shift = (int) (mod.GetY()+0.5); // Y - offset of the allowed/present value
		
		if (divi==0) {	// ValueMod can't be "0 x"
			return false;
		}
		vint vElem=rangelist.ToVInt();

		int siz=vElem.size();
		for (int i=0; i<siz; i++)
		{
			if ( (((vElem[i] % divi)-shift) % divi) !=0 )
				return false;
		}
		return true;
			
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerEvaluation::FitsCompleteList(const JDFIntegerRangeList& value, const JDFIntegerRangeList& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}
		if (!value.IsUnique()) {
			return false;
		}

		JDFIntegerRangeList valueList= value;

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

	bool JDFIntegerEvaluation::FitsCompleteOrderedList(const JDFIntegerRangeList& value, const JDFIntegerRangeList& list) const{

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

	bool JDFIntegerEvaluation::FitsContainedList(const JDFIntegerRangeList& value, const JDFIntegerRangeList& list) const{

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
}; // namespace JDF
