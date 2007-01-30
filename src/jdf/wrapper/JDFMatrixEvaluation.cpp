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
// JDFMatrixEvaluation.cpp: implementation of the JDFMatrixEvaluation 
//
//////////////////////////////////////////////////////////////////////


 
#include "jdf/wrapper/JDFMatrixEvaluation.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"
#include <math.h>

namespace JDF{
/**
* copy equivalance operator
*/
	const double JDFMatrixEvaluation::dt=0.00000001;

	//////////////////////////////////////////////////////////////////////
	
	JDFMatrixEvaluation& JDFMatrixEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFMatrixEvaluation: "+other.GetNodeName());
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFMatrixEvaluation::ValidNodeNames()const{
		return L"*:,MatrixEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixEvaluation::IsAbstract()const{
		return false;
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFMatrixEvaluation::OptionalElements()const{
		return JDFEvaluation::OptionalElements()+L",Value";
	};

	//////////////////////////////////////////////////////////////////////
	
	vWString JDFMatrixEvaluation::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFEvaluation::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Value);

		for(i=0;i<nElem;i++){
			if (!GetValue(i).IsValid(level)) {
				vElem.AppendUnique(elm_Value);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFMatrixEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",RotateMod,Shift,Tolerance,Transforms";
	};
	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFMatrixEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFEvaluation::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidRotateMod(level)) {
			vAtts.push_back(atr_RotateMod);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShift(level)) {
			vAtts.push_back(atr_Shift);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTolerance(level)) {
			vAtts.push_back(atr_Tolerance);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransforms(level)) {
			vAtts.push_back(atr_Transforms);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixEvaluation::ValidRotateMod(EnumValidationLevel level)const{
		return ValidAttribute(atr_RotateMod,AttributeType_double,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixEvaluation::ValidShift(EnumValidationLevel level)const{
		return ValidAttribute(atr_Shift,AttributeType_rectangle,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixEvaluation::ValidTolerance(EnumValidationLevel level) const {
		return ValidAttribute(atr_Tolerance,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixEvaluation::ValidTransforms(EnumValidationLevel level)const{
		return ValidEnumerationsAttribute(atr_Transforms,JDFElement::OrientationString(),false);
	}

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	
	void JDFMatrixEvaluation::SetRotateMod(double value){
		SetAttribute(atr_RotateMod,value);
	};
	///////////////////////////////////////////////////////////////////////
	double JDFMatrixEvaluation::GetRotateMod() const {
		return GetRealAttribute(atr_RotateMod);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFMatrixEvaluation::SetShift(const JDFRectangle& value){
		SetAttribute(atr_Shift,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////
	JDFRectangle JDFMatrixEvaluation::GetShift() const {
		return GetAttribute(atr_Shift,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFMatrixEvaluation::SetTolerance(JDFXYPair value){
		SetAttribute(atr_Tolerance,value);
	}
	//////////////////////////////////////////////////////////////////////
	JDFXYPair JDFMatrixEvaluation::GetTolerance() const {
		return GetAttribute(atr_Tolerance,WString::emptyStr,L"0 0");
	}
	//////////////////////////////////////////////////////////////////////
	vint JDFMatrixEvaluation::GetTransforms() const {
		return GetEnumerationsAttribute(atr_Transforms,JDFElement::OrientationString(),WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFMatrixEvaluation::SetTransforms(const vint& value){
		SetEnumerationsAttribute(atr_Transforms,value,JDFElement::OrientationString());
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValue JDFMatrixEvaluation::GetValue(int iSkip)const{
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValue JDFMatrixEvaluation::AppendValue(){
		JDFValue e=AppendElement(elm_Value);
		e.init();
		return e;
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Subelement Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFMatrixEvaluation::SetValueValue(int iSkip, JDFMatrix value){
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		e.SetValue(value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFMatrix JDFMatrixEvaluation::GetValueValue(int iSkip) const {
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e.GetValue();
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
		
	bool JDFMatrixEvaluation::FitsValue(const WString& value) const{

		vWString vs=value.Tokenize();
		int siz=vs.size();
		if (siz%6!=0) {
			return false;
		}
		vWString matrixList;
		int i=0;
		WString s=vs[i];
		while ((i+1)<siz)
		{
			do  {
				s+=WString::blank;
				i++;
				s+=vs[i];
			}
			while ((i+1)%6!=0);
			matrixList.push_back(s);
			if ((i+1)<siz)
			{ 
				i++;
				s=vs[i];
			}
		}

		if (!FitsListType(matrixList))
		{
			return false;
		}

		for (int k=0; k<matrixList.size(); k++) 
		{
			WString matrix = matrixList[k];
			if ((FitsRotateMod(matrix)&&FitsShift(matrix)&&FitsTransforms(matrix)&&FitsValueElem(matrix))==false)
				return false;
		}
		return true;	
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFMatrixEvaluation::FitsListType(const vWString& matrixList) const {

		int size = matrixList.size();
		for (int i=0; i<size; i++)
		{
			JDFMatrix matrix; 
			try{
				matrix=matrixList[i];
			}catch (JDFException e){
				return false;
			}catch (IllegalArgumentException ie){
				return false;
			}
		}
		
		JDFBasicPreflightTest::EnumListType listtype = GetBasicPreflightTest().GetListType();

		switch (listtype) {
	
			case JDFBasicPreflightTest::ListType_List:
			{
				return true;
			}
			case JDFBasicPreflightTest::ListType_UniqueList:
			{
				int size=matrixList.size();
				for (int i=0; i<size; i++)
				{
					for (int j=0; j<size; j++)
					{
						if ((j!=i)&&(!matrixList.at(i).compare(matrixList.at(j)))) 
							return false;
					}
				}
				return true;
			}
			case JDFBasicPreflightTest::ListType_SingleValue:
			case JDFBasicPreflightTest::ListType_Unknown: // default ListType = SingleValue
			{
				return (size==1);
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
				throw JDFException (L"JDFMatrixState::FitsListType illegal ListType attribute"); 
			}
		}
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixEvaluation::FitsRotateMod(const JDFMatrix& matrix) const{
		
		if (!HasAttribute(atr_RotateMod)) {
			return true;
		}
		double rm = GetRotateMod();
				
		double a = matrix.GetA();
		double b = matrix.GetB();
		double c = matrix.GetC();
		double d = matrix.GetD();

		if ((a*d-b*c)==0)
			return false;

		double nT; // negative tolerance
		double pT; // positive tolerance

		if (HasAttribute(atr_Tolerance)) {
			nT = GetTolerance().GetX(); 
			pT = GetTolerance().GetY(); 
		} 
		else {
			nT=pT=dt;
		}

		double param = a/sqrt(fabs(a*d-b*c));

		if (((param-dt)>1) || ((param+dt)<-1)) { 
			return false;
		}
		if (param>1) {
			param=param-dt;
		}
		if (param<-1) {
			param=param+dt;
		}

		double fi = acos(param)*180/PI; // 0~180

		double result = (fi+nT) - (rm * (int) ((fi+nT)/rm) );
		double result180 = (fi+180+nT) - (rm * (int) ((fi+180+nT)/rm) );
		
		return ((fabs(result) <= (nT+pT)) || (fabs(result180) <= (nT+pT)) ) ; // (fi+nT)%rm <= (nT+pT)
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixEvaluation::FitsShift(const JDFMatrix& matrix) const{
		
		if (!HasAttribute(atr_Shift)) {
			return true;
		}

		JDFRectangle shift = GetShift();

		double minTx = shift.GetLlx();
		double minTy = shift.GetLly();
		double maxTx = shift.GetUrx();
		double maxTy = shift.GetUry();

		double Tx = matrix.GetTx();
		double Ty = matrix.GetTy();

		if (! HasAttribute(atr_Tolerance)) {
			return ((Tx>=minTx)&&(Tx<=maxTx)&&(Ty>=minTy)&&(Ty<=maxTy));
		}

		double nT = GetTolerance().GetX(); // negative tolerance
		double pT = GetTolerance().GetY(); // positive tolerance

		return ((Tx-nT>=minTx)&&(Tx+pT<=maxTx)&&(Ty-nT>=minTy)&&(Ty+pT<=maxTy));
		
	}
		
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixEvaluation::FitsTransforms(const JDFMatrix& matrix) const{
		
		if (!HasAttribute(atr_Transforms)) {
			return true;
		}

		double nT; // negative tolerance
		double pT; // positive tolerance

		if (HasAttribute(atr_Tolerance)) {
			nT = GetTolerance().GetX(); 
			pT = GetTolerance().GetY();
		}
		else {
			nT = pT = dt; // general tolerance
		}

		double a = matrix.GetA();
		double b = matrix.GetB();
		double c = matrix.GetC();
		double d = matrix.GetD(); 
		
		double det=(a*d-b*c);
		
		if (det==0)
			return false;
		
		a=a/sqrt(fabs(det));
		b=b/sqrt(fabs(det));
		c=c/sqrt(fabs(det));
		d=d/sqrt(fabs(det));
		
		
		vint vTransf = GetTransforms();

		int siz=vTransf.size();
		for (int i=0; i<siz; i++)
		{

			EnumOrientation orientation = (EnumOrientation) vTransf[i];

			switch (orientation) {

				case Orientation_Flip0: // a=1 b=0 c=0 d=-1
				{
					if (((a-1)<pT)&&((a-1)>-nT)&&(b<pT)&&(b>-nT)&&(c<pT)&&(c>-nT)&&((d+1)<pT)&&((d+1)>-nT)) 
						return true;
					continue;
				}
				case Orientation_Flip90: // a=0 b=-1 c=-1 d=0
				{
					if ((a<pT)&&(a>-nT)&&((b+1)<pT)&&((b+1)>-nT)&&((c+1)<pT)&&((c+1)>-nT)&&(d<pT)&&(d>-nT))
						return true;
					continue;
				}
				case Orientation_Flip180: // a=-1 b=0 c=0 d=1
				{
					if (((a+1)<pT)&&((a+1)>-nT)&&(b<pT)&&(b>-nT)&&(c<pT)&&(c>-nT)&&((d-1)<pT)&&((d-1)>-nT))
						return true;
					continue;
				}
				case Orientation_Flip270: // a=0 b=1 c=1 d=0
				{
					if ((a<pT)&&(a>-nT)&&((b-1)<pT)&&((b-1)>-nT)&&((c-1)<pT)&&((c-1)>-nT)&&(d<pT)&&(d>-nT))
						return true;
					continue;
				}
				case Orientation_Rotate0: // a=1 b=0 c=0 d=1
				{
					if (((a-1)<pT)&&((a-1)>-nT)&&(b<pT)&&(b>-nT)&&(c<pT)&&(c>-nT)&&((d-1)<pT)&&((d-1)>-nT))
						return true;
					continue;
				}
				case Orientation_Rotate90: // a=0 b=1 c=-1 d=0
				{
					if ((a<pT)&&(a>-nT)&&((b-1)<pT)&&((b-1)>-nT)&&((c+1)<pT)&&((c+1)>-nT)&&(d<pT)&&(d>-nT))
						return true;
					continue;
				} 
				case Orientation_Rotate180: // a=-1 b=0 c=0 d=-1
				{
					if (((a+1)<pT)&&((a+1)>-nT)&&(b<pT)&&(b>-nT)&&(c<pT)&&(c>-nT)&&((d+1)<pT)&&((d+1)>-nT))
						return true;
					continue;
				}
				case Orientation_Rotate270: // a=0 b=-1 c=1 d=0
				{
					if ((a<pT)&&(a>-nT)&&((b+1)<pT)&&((b+1)>-nT)&&((c-1)<pT)&&((c-1)>-nT)&&(d<pT)&&(d>-nT))
						return true;
					continue;
				}
				case Orientation_Unknown:
				default:
				{
					return true; 
				}
			}
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixEvaluation::FitsValueElem(const JDFMatrix& matrix) const{

		vElement v=GetChildElementVector(elm_Value);
		int siz=v.size();
		if (siz==0) {
			return true; // Evaluation has no Value elements
		}
		for (int i=0; i<siz; i++)
		{
			JDFValue elm=v[i];
			
			JDFMatrix value = GetValueValue(i);

			if (HasAttribute(atr_Tolerance)) 
			{
				double nT = GetTolerance().GetX(); // negative tolerance
				double pT = GetTolerance().GetY(); // positive tolerance

				if (value.FitsTolerance(matrix, nT, pT))
					return true;
			}
			else {
				if (value.FitsTolerance(matrix))
					return true; 
			}
		}
		return false; 
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}; // namespace JDF

