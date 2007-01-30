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
// JDFShapeEvaluation.cpp: implementation of the JDFShapeEvaluation 
//
//////////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/JDFShapeEvaluation.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"

namespace JDF{
/**
* copy equivalance operator
*/
	JDFShapeEvaluation& JDFShapeEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFShapeEvaluation: "+other.GetNodeName());
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFShapeEvaluation::ValidNodeNames()const{
		return L"*:,ShapeEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFShapeEvaluation::IsAbstract()const{
		return false;
	}
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFShapeEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",Tolerance,ValueList,X,Y,Z";
	};

	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFShapeEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
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
		if(!ValidX(level)) {
			vAtts.push_back(atr_X);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidY(level)) {
			vAtts.push_back(atr_Y);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidZ(level)) {
			vAtts.push_back(atr_Z);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFShapeEvaluation::ValidValueList(EnumValidationLevel level)const{
		return ValidAttribute(atr_ValueList,AttributeType_ShapeRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeEvaluation::ValidX(EnumValidationLevel level)const{
		return ValidAttribute(atr_X,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeEvaluation::ValidY(EnumValidationLevel level)const{
		return ValidAttribute(atr_Y,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeEvaluation::ValidZ(EnumValidationLevel level)const{
		return ValidAttribute(atr_Z,AttributeType_NumberRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFShapeEvaluation::ValidTolerance(EnumValidationLevel level) const {
		return ValidAttribute(atr_Tolerance,AttributeType_XYPair,false);
	}
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	void JDFShapeEvaluation::SetValueList(const JDFShapeRangeList& value){
		SetAttribute(atr_ValueList,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFShapeRangeList JDFShapeEvaluation::GetValueList() const {
		return GetAttribute(atr_ValueList);
	};
	//////////////////////////////////////////////////////////////////////
		
	void JDFShapeEvaluation::SetX(const NumberRangeList& value){
		SetAttribute(atr_X,value);
	};
	//////////////////////////////////////////////////////////////////////

	NumberRangeList JDFShapeEvaluation::GetX() const {
		return GetAttribute(atr_X);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeEvaluation::SetY(const NumberRangeList& value){
		SetAttribute(atr_Y,value);
	};
	//////////////////////////////////////////////////////////////////////

	NumberRangeList JDFShapeEvaluation::GetY() const {
		return GetAttribute(atr_Y);
	};
	//////////////////////////////////////////////////////////////////////
	
	void JDFShapeEvaluation::SetZ(const NumberRangeList& value){
		SetAttribute(atr_Z,value);
	};
	//////////////////////////////////////////////////////////////////////

	NumberRangeList JDFShapeEvaluation::GetZ() const {
		return GetAttribute(atr_Z);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeEvaluation::SetTolerance(const JDFXYPair& value){
		SetAttribute(atr_Tolerance,value);
	}
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFShapeEvaluation::GetTolerance() const {
		return GetAttribute(atr_Tolerance,WString::emptyStr,L"0 0");
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFShapeEvaluation::FitsValue(const WString& value) const{
		
		if (!FitsListType(value))
		{
			return false;
		}
		JDFShapeRangeList rrl(value);
		int siz=rrl.size();

		for (int i=0; i<siz; i++)
		{
			JDFShapeRange range=rrl.at(i);

			if ((FitsValueList(range)&&FitsXYZ(range))==false)
				return false;
		}
		return true;

	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////		
	
	bool JDFShapeEvaluation::FitsListType(const WString& value) const {

		JDFShapeRangeList rangelist;

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
					JDFShape sh(value);
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
				throw JDFException (L"JDFShapeEvaluation::FitsListType illegal ListType attribute"); 
			}

		}
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFShapeEvaluation::FitsValueList(const JDFShapeRange& range) const{
			
		if (!HasAttribute(atr_ValueList)) {
			return true;
		}

		JDFShapeRangeList rangelist=GetValueList();

		if (HasAttribute(atr_Tolerance)) 
			return (FitsTolerance(rangelist).IsPartOfRange(range));
		return rangelist.IsPartOfRange(range);
	}
	//////////////////////////////////////////////////////////////////////
		
	bool JDFShapeEvaluation::FitsXYZ(const JDFShapeRange& range) const{
		
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
			
		x=GetX(); 
		y=GetY();
		z=GetZ();

		if (HasAttribute(atr_Tolerance)) {
			x = FitsXYZTolerance(x);
			y = FitsXYZTolerance(y);
			z = FitsXYZTolerance(z);
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
		return bFit;
	}
	//////////////////////////////////////////////////////////////////////

	JDFShapeRangeList JDFShapeEvaluation::FitsTolerance(const JDFShapeRangeList& origRangeList) const{
		
		double nt = GetTolerance().GetX(); // negative tolerance
		double pt = GetTolerance().GetY(); // positive tolerance
		
		if ((nt==0)&&(pt==0)) {
			return origRangeList;
		}
		
		// expand our original range into the range +/- Tolerance

		JDFShapeRangeList rangeList = origRangeList;

		JDFShapeRangeList tolRangeList;
		
		int size = rangeList.size();
		for (int i=0; i<size; i++) 
		{
			JDFShapeRange range = rangeList[i];

			JDFShape left=range.GetLeft();
			double leftX=left.GetA();
			double leftY=left.GetB();
			double leftZ=left.GetC();
			left.SetA( leftX - nt );
			left.SetB( leftY - nt );
			left.SetC( leftZ - nt );
			
			JDFShape right=range.GetRight();
			double rightX=right.GetA();
			double rightY=right.GetB();
			double rightZ=right.GetC();
			right.SetA( rightX + pt );
			right.SetB( rightY + pt );
			right.SetC( rightZ + pt );
			
			range.SetLeft(left);
			range.SetRight(right);
			
			tolRangeList.Append(range);
		}
		
		return tolRangeList;
	}

	//////////////////////////////////////////////////////////////////////

	NumberRangeList JDFShapeEvaluation::FitsXYZTolerance(const NumberRangeList& origRangeList) const{
		
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
	//////////////////////////////////////////////////////////////////////
}; // namespace JDF
