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
// JDFDateTimeEvaluation.cpp: implementation of the JDFDateTimeEvaluation 
//
//////////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/JDFDateTimeEvaluation.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"

namespace JDF{
/**
* copy equivalance operator
*/
	JDFDateTimeEvaluation& JDFDateTimeEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFDateTimeEvaluation: "+other.GetNodeName());
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFDateTimeEvaluation::ValidNodeNames()const{
		return L"*:,DateTimeEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFDateTimeEvaluation::IsAbstract()const{
		return false;
	}
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFDateTimeEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",ValueDurationList,ValueList";
	};

	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFDateTimeEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFEvaluation::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidValueDurationList(level)) {
			vAtts.push_back(atr_ValueDurationList);
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
	bool JDFDateTimeEvaluation::ValidValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueList,AttributeType_DateTimeRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFDateTimeEvaluation::ValidValueDurationList(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueDurationList,AttributeType_DurationRangeList,false);
	}

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	
	void JDFDateTimeEvaluation::SetValueList(const JDFDateTimeRangeList& value){
		SetAttribute(atr_ValueList,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFDateTimeRangeList JDFDateTimeEvaluation::GetValueList() const {
		return GetAttribute(atr_ValueList);
	};
	/////////////////////////////////////////////////////////////////////////
	
	void JDFDateTimeEvaluation::SetValueDurationList(const JDFDurationRangeList& value){
		SetAttribute(atr_ValueDurationList,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFDurationRangeList JDFDateTimeEvaluation::GetValueDurationList() const {
		return GetAttribute(atr_ValueDurationList);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
		
	bool JDFDateTimeEvaluation::FitsValue(const WString& value) const{
		
		if (!FitsListType(value))
		{
			return false;
		}
		
		vWString strrange=value.Tokenize();
		int sz=strrange.size();

		for (int i=0; i<sz; i++)
		{
			JDFDateTimeRange range=strrange[i];
			if ((FitsValueList(range)&&FitsValueDurationList(range))==false)
				return false;
		}
		return true; // all elements of rangelist fit

	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFDateTimeEvaluation::FitsListType(const WString& value) const {
		
		JDFDateTimeRangeList rangelist;
	
		try {
			 rangelist=value;						
		}catch (IllegalArgumentException e){
			return false;
		}catch (JDFException e){
			return false;
		}
		
		JDFBasicPreflightTest::EnumListType listtype = GetBasicPreflightTest().GetListType();
		
		switch (listtype) {
	
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
				try { 
					JDFDate d(value);
				}catch (IllegalArgumentException e){
					return false;
				}catch (JDFException e){
					return false;
				}
				return true;
			}
			case JDFBasicPreflightTest::ListType_CompleteList:
			case JDFBasicPreflightTest::ListType_CompleteOrderedList:
			case JDFBasicPreflightTest::ListType_ContainedList:
			default:
			{
				throw JDFException (L"JDFDateTimeEvaluation::FitsListType illegal ListType attribute"); 
			}
		}
	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFDateTimeEvaluation::FitsValueList(const JDFDateTimeRange& range) const{
			
		if (HasAttribute(atr_ValueList))
			return GetValueList().IsPartOfRange(range);
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFDateTimeEvaluation::FitsValueDurationList(const JDFDateTimeRange& range) const{
		
		if (HasAttribute(atr_ValueDurationList))
		{
			JDFDuration duration=((double) range.GetRight().GetSecondsSince1970())-((double) range.GetLeft().GetSecondsSince1970());
			return GetValueDurationList().IsPartOfRange(duration);
		}
		return true;
	}
	 	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}; // namespace JDF
