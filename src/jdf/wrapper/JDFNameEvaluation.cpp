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
// JDFNameEvaluation.cpp: implementation of the JDFNameEvaluation 
//
//////////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/JDFNameEvaluation.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"
#include "xercesc/util/regx/RegularExpression.hpp"

XERCES_CPP_NAMESPACE_USE
using namespace std;
namespace JDF{
/**
* copy equivalance operator
*/
	JDFNameEvaluation& JDFNameEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFNameEvaluation: "+other.GetNodeName());
		return *this;
	}
	//////////////////////////////////////////////////////////////////////
	
	WString JDFNameEvaluation::ValidNodeNames()const{
		return L"*:,NameEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFNameEvaluation::IsAbstract()const{
		return false;
	}
	/////////////////////////////////////////////////////////////////////////
	WString JDFNameEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",ValueList,RegExp";
	};

	/////////////////////////////////////////////////////////////////////////
	vWString JDFNameEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFEvaluation::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidRegExp(level)) {
			vAtts.push_back(atr_RegExp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValueList(level)) {
			vAtts.push_back(atr_ValueList);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	
	bool JDFNameEvaluation::ValidRegExp(EnumValidationLevel level)const{
		return ValidAttribute(atr_RegExp,AttributeType_regExp,false);
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFNameEvaluation::ValidValueList(EnumValidationLevel level) const {
		return ValidAttribute(atr_ValueList,AttributeType_NMTOKENS,false);
	};
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	void JDFNameEvaluation::SetValueList(const vWString& value){
		SetAttribute(atr_ValueList,value);
	}
	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFNameEvaluation::GetValueList()const{
		return GetAttribute(atr_ValueList);
	}
	/////////////////////////////////////////////////////////////////////////
	
	void JDFNameEvaluation::SetRegExp(const WString& value){
		SetAttribute(atr_RegExp,value);
	}
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFNameEvaluation::GetRegExp() const {
		return GetAttribute(atr_RegExp,WString::emptyStr);
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	bool JDFNameEvaluation::FitsValue(const WString& value) const{
		
		if (!FitsListType(value))
		{
			return false;
		}
		return (FitsValueList(value)&&FitsRegExp(value));
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNameEvaluation::FitsValueList(const WString& value) const{
		
		if (!HasAttribute(atr_ValueList)) {
			return true;
		}

		vWString vs=value.Tokenize();
		vWString list=GetValueList();

		JDFBasicPreflightTest::EnumListType listType = GetListType(); // gets ListType of BasicPreflightTest or State

		if (listType==JDFBasicPreflightTest::ListType_CompleteList){
			return FitsCompleteList(vs,list);
		}
		else if (listType==JDFBasicPreflightTest::ListType_CompleteOrderedList){ 
			return FitsCompleteOrderedList(vs,list);
		}
		else if (listType==JDFBasicPreflightTest::ListType_ContainedList){
			return FitsContainedList(vs,list);
		}

		int v_size=vs.size();
		int l_size = list.size();
		
		for (int i=0; i<v_size; i++) // test every token, that 'value' consists of
		{
			bool bFound = false;
			for (int j=0; j<l_size; j++)
			{
				if (!vs[i].compare(list[j])) {
					bFound=true;  
					break;
				}
			}
			if (!bFound)
				return false; // no such value in the 'list'
		}
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFNameEvaluation::FitsRegExp(const WString& value) const{

		if (!HasAttribute(atr_RegExp)) { 
			return true; // if RegExp is not specified return true 
		}
		
		WString rExp = GetRegExp();
		RegularExpression re(rExp.c_str());

		vWString v =value.Tokenize();
		int size=v.size();

		for (int i=0; i<size; i++) // tests every token, that 'value' consists of
		{
			if (!re.matches(v[i].c_str()))
				return false;
		}
		return true;
	
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFNameEvaluation::FitsListType(const WString& value) const {

		if (!value.isNMTOKENS()) 
			return false;
		
		JDFBasicPreflightTest::EnumListType listtype = GetBasicPreflightTest().GetListType();

		switch (listtype) {
	
			case JDFBasicPreflightTest::ListType_CompleteList:// if it is comlete list or not will be tested in FitsValueList->FitsCompleteList
			case JDFBasicPreflightTest::ListType_CompleteOrderedList: // if it is comlete ordered list or not will be tested in FitsValueList->FitsCompleteOrderedList
			case JDFBasicPreflightTest::ListType_ContainedList: // if it is contained list or not will be tested in FitsValueList->FitsContainedList
			case JDFBasicPreflightTest::ListType_List:
			case JDFBasicPreflightTest::ListType_Span:
			{
				return true;
			}
			case JDFBasicPreflightTest::ListType_UniqueList:
			{
				return (IsUnique(value));
			}
			case JDFBasicPreflightTest::ListType_SingleValue:
			case JDFBasicPreflightTest::ListType_Unknown: // default ListType = SingleValue
			{
				return value.isNMTOKEN();
			}
			case JDFBasicPreflightTest::ListType_OrderedList:
			case JDFBasicPreflightTest::ListType_UniqueOrderedList:
			case JDFBasicPreflightTest::ListType_RangeList:
			case JDFBasicPreflightTest::ListType_OrderedRangeList:
			case JDFBasicPreflightTest::ListType_UniqueRangeList:
			case JDFBasicPreflightTest::ListType_UniqueOrderedRangeList:
			default:
			{
				throw JDFException (L"JDFNameEvaluation::FitsListType illegal ListType attribute"); 
			}
		}
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFNameEvaluation::FitsCompleteList(const vWString& value, const vWString& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}
		if (!IsUnique(value)) {
			return false;
		}

		vWString valueList = value;

		bool bFound;
		for (int i=l_size-1; i>=0; i--)
		{
			bFound=false;
			for (int j=valueList.size()-1; j>=0; j--)
			{
				if (!list[i].compare(valueList[j]))
				{
					valueList.erase(valueList.begin()+j);
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

	bool JDFNameEvaluation::FitsCompleteOrderedList(const vWString& value, const vWString& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		if (v_size!=l_size) {
			return false; 
		}

		if (!IsUnique(value)) {
			return false;
		}
		for (int i=0; i<l_size; i++)
		{
			if ( list[i].compare(value[i]) ) {
				return false;
			}
		}
		return true;		
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNameEvaluation::FitsContainedList(const vWString& value, const vWString& list) const{

		int v_size=value.size();
		int l_size=list.size();
		
		for (int i=0; i<v_size; i++)
		{
			for (int j=0; j<l_size; j++)
			{
				if (!value[i].compare(list[j])) 
					return true;
			}
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNameEvaluation::IsUnique(const vWString& value) const{

		int size=value.size();
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				if ((j!=i)&&(!value[i].compare(value[j]))) 
					return false;
			}
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}; // namespace JDF
