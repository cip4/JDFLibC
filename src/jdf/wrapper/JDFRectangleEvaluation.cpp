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
// JDFRectangleEvaluation.cpp: implementation of the JDFRectangleEvaluation 
//
//////////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/JDFRectangleEvaluation.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"

namespace JDF{
/**
* copy equivalance operator
*/
	JDFRectangleEvaluation& JDFRectangleEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFRectangleEvaluation: "+other.GetNodeName());
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFRectangleEvaluation::ValidNodeNames()const{
		return L"*:,RectangleEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFRectangleEvaluation::IsAbstract()const{
		return false;
	}
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFRectangleEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",HWRelation,Tolerance,ValueList";
	};

	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFRectangleEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFEvaluation::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidHWRelation(level)) {
			vAtts.push_back(atr_HWRelation);
			if(++n>=nMax)
				return vAtts;
		};
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
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFRectangleEvaluation::ValidValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueList,AttributeType_RectangleRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFRectangleEvaluation::ValidHWRelation(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueMod,AttributeType_XYRelation,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFRectangleEvaluation::ValidTolerance(EnumValidationLevel level) const {
		return ValidAttribute(atr_Tolerance,AttributeType_XYPair,false);
	}
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	void JDFRectangleEvaluation::SetValueList(const JDFRectangleRangeList& value){
		SetAttribute(atr_ValueList,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFRectangleRangeList JDFRectangleEvaluation::GetValueList() const {
		return GetAttribute(atr_ValueList);
	};
	//////////////////////////////////////////////////////////////////////
	
	void JDFRectangleEvaluation::SetHWRelation(EnumXYRelation value){
		SetEnumAttribute(atr_HWRelation,value,XYRelationString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumXYRelation JDFRectangleEvaluation::GetHWRelation() const {
		return (JDFElement::EnumXYRelation) GetEnumAttribute(atr_HWRelation,XYRelationString());
	};
	//////////////////////////////////////////////////////////////////////
	void JDFRectangleEvaluation::SetTolerance(const JDFXYPair& value){
		SetAttribute(atr_Tolerance,value);
	}
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFRectangleEvaluation::GetTolerance() const {
		return GetAttribute(atr_Tolerance,WString::emptyStr,L"0 0");
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	
	bool JDFRectangleEvaluation::FitsValue(const WString& value) const{
		
		if (!FitsListType(value))
		{
			return false;
		}

		JDFRectangleRangeList rrl(value);

		int siz=rrl.size();
		for (int i=0; i<siz; i++) // For every range, that rangelist consists of,
		{						  // we test both of range deliminators - right and left, if they fit HWRelation
								  // In this case test of deliminators is sufficient for evaluation of the whole range
			JDFRectangleRange range=rrl.at(i);
				
			JDFRectangle left = range.GetLeft();
			JDFRectangle right = range.GetRight();
			
			if (left==right)
			{
				JDFRectangle rectangle=left;
				if ((FitsValueList(rectangle)&&FitsHWRelation(rectangle))==false)
					return false;
			}
			else {
				if ((FitsValueList(range)&&FitsHWRelation(left)&&FitsHWRelation(right))==false)
					return false;
			}
		}
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFRectangleEvaluation::FitsListType(const WString& value) const {

		JDFRectangleRangeList rangelist;

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
					JDFRectangle r(value);
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
				throw JDFException (L"JDFRectangleEvaluation::FitsListType illegal ListType attribute"); 
			}
		}
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFRectangleEvaluation::FitsValueList(const JDFRectangleRange& range) const{
			
		if (!HasAttribute(atr_ValueList))
			return true;
		
		JDFRectangleRangeList rangelist=GetValueList();

		if (HasAttribute(atr_Tolerance)) 
			return (FitsTolerance(rangelist).IsPartOfRange(range));
		return rangelist.IsPartOfRange(range);
	
	}
	//////////////////////////////////////////////////////////////////////
	
	JDFRectangleRangeList JDFRectangleEvaluation::FitsTolerance(const JDFRectangleRangeList& origRangeList) const{
		
		double nt = GetTolerance().GetX(); // negative tolerance
		double pt = GetTolerance().GetY(); // positive tolerance
		
		if ((nt==0)&&(pt==0)) {
			return origRangeList;
		}
		
		// expand our original range into the range +/- Tolerance

		JDFRectangleRangeList rangeList = origRangeList;

		JDFRectangleRangeList tolRangeList;

		int size = rangeList.size();
		for (int i=0; i<size; i++) 
		{
			JDFRectangleRange range = rangeList[i];

			JDFRectangle left=range.GetLeft();
			double leftLlx=left.GetLlx();
			double leftLly=left.GetLly();
			double leftUrx=left.GetUrx();
			double leftUry=left.GetUry();
			left.SetLlx( leftLlx - nt );
			left.SetLly( leftLly - nt );
			left.SetUrx( leftUrx - nt );
			left.SetUry( leftUry - nt );
			
			JDFRectangle right=range.GetRight();
			double rightLlx=right.GetLlx();
			double rightLly=right.GetLly();
			double rightUrx=right.GetUrx();
			double rightUry=right.GetUry();
			right.SetLlx( rightLlx + pt );
			right.SetLly( rightLly + pt );
			right.SetUrx( rightUrx + pt );
			right.SetUry( rightUry + pt );

			range.SetLeft(left);
			range.SetRight(right); 
			
			tolRangeList.Append(range);

		}
		return tolRangeList;
	}
	
	//////////////////////////////////////////////////////////////////////
		
	bool JDFRectangleEvaluation::FitsHWRelation(const JDFRectangle& rect) const{
		
		double width = rect.GetUrx() - rect.GetLlx();
		double height = rect.GetUry() - rect.GetLly();

		if (!HasAttribute(atr_HWRelation))
			return true;
		if (!HasAttribute(atr_Tolerance))
			return XYRelation(GetHWRelation(),width,height);

		double nt = GetTolerance().GetX(); // negative tolerance
		double pt = GetTolerance().GetY(); // positive tolerance

		return XYRelation(GetHWRelation(),width,height,nt,pt);
		
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}; // namespace JDF
