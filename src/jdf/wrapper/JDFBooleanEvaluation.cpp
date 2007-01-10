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
// JDFBooleanEvaluation.cpp: implementation of the JDFBooleanEvaluation 
//
//////////////////////////////////////////////////////////////////////


 
#include "jdf/wrapper/JDFBooleanEvaluation.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"

namespace JDF{
/**
* copy equivalance operator
*/
	JDFBooleanEvaluation& JDFBooleanEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFBooleanEvaluation: "+other.GetNodeName());
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFBooleanEvaluation::ValidNodeNames()const{
		return L"*:,BooleanEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFBooleanEvaluation::IsAbstract()const{
		return false;
	}
	//////////////////////////////////////////////////////////////////////
	
	const WString& JDFBooleanEvaluation::ValueListString()const {
		static const WString enums=L"Unknown,false,true";
		return enums;
	};
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFBooleanEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",ValueList";
	};

	/////////////////////////////////////////////////////////////////////////
	vWString JDFBooleanEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFEvaluation::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidValueList(level)) {
			vAtts.push_back(atr_ValueList);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};
	/////////////////////////////////////////////////////////////////////////
	bool JDFBooleanEvaluation::ValidValueList(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_ValueList,ValueListString(),false);
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFBooleanEvaluation::FitsValue(const WString& valueStr) const{

		if (!FitsListType(valueStr))
		{
			return false;
		}
		vWString value = valueStr.Tokenize();

		for (int i=0; i<value.size(); i++)
		{
			if (!FitsValueList(value[i]))
				return false;
		}
		return true; // if we are here a whole 'valueStr' fits
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFBooleanEvaluation::FitsValueList(const WString& value) const{
		
		if (!HasAttribute(atr_ValueList)) {
			return true; 
		}
		vint v=GetValueList();
		
		bool MyValue=value;
		int size = v.size();
		for (int i=0; i<size; i++) {
			if (MyValue==(v[i] != 0))
				return true; // we have found it
		}
		return false;
		
	}

	//////////////////////////////////////////////////////////////////////
	
	bool JDFBooleanEvaluation::FitsListType(const WString& value) const {
		
		vWString vBool = value.Tokenize();
		for (int i=0; i<value.size(); i++)
		{
			if (!vBool[i].isBoolean())
				return false;
		}
				
		JDFBasicPreflightTest::EnumListType listtype = GetBasicPreflightTest().GetListType();
		
		switch (listtype) {
	
			case JDFBasicPreflightTest::ListType_List:
			case JDFBasicPreflightTest::ListType_Span:
			{
				return true;
			}
			case JDFBasicPreflightTest::ListType_UniqueList:
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
			case JDFBasicPreflightTest::ListType_SingleValue:
			case JDFBasicPreflightTest::ListType_Unknown: // default ListType = SingleValue
			{
				return value.isBoolean();
			}
			case JDFBasicPreflightTest::ListType_CompleteList:
			case JDFBasicPreflightTest::ListType_CompleteOrderedList:
			case JDFBasicPreflightTest::ListType_ContainedList:
			case JDFBasicPreflightTest::ListType_OrderedList:
			case JDFBasicPreflightTest::ListType_UniqueOrderedList:
			case JDFBasicPreflightTest::ListType_RangeList:
			case JDFBasicPreflightTest::ListType_OrderedRangeList:
			case JDFBasicPreflightTest::ListType_UniqueRangeList:
			case JDFBasicPreflightTest::ListType_UniqueOrderedRangeList:
			default:
			{
				throw JDFException (L"JDFBooleanState::FitsListType illegal ListType attribute"); 
			}
		}
	}
	
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	vint JDFBooleanEvaluation::GetValueList() const {
		vint v= GetEnumerationsAttribute(atr_ValueList,ValueListString(),WString::emptyStr);
		for (int i=v.size()-1; i>=0; i--) {
			if (v[i]==0){
				v.erase(v.begin()+i);
			}else{
				v.at(i)=v.at(i)-1;
			}
		}
		return v;
	};

	//////////////////////////////////////////////////////////////////////
	void JDFBooleanEvaluation::SetValueList(const vint& value){
		SetEnumerationsAttribute(atr_ValueList,value,ValueListString());

	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}; // namespace JDF
