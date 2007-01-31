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
// JDFMatrixState.cpp: implementation of the JDFMatrixState 
//
//////////////////////////////////////////////////////////////////////

#include "JDFState.h"
#include "JDFDeviceCap.h"
#include "JDFMatrixState.h"
#include <math.h>

using namespace std;
namespace JDF{
	
	const double JDFMatrixState::dt=0.00000001;
	
	//////////////////////////////////////////////////////////////////////
	
	JDFMatrixState& JDFMatrixState::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFMatrixState: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFMatrixState::ValidNodeNames()const{
		return L"*:,MatrixState";
	};
		
	//////////////////////////////////////////////////////////////////////

	WString JDFMatrixState::OptionalElements()const{
		return JDFStateBase::OptionalElements()+L",Value";
	};
	//////////////////////////////////////////////////////////////////////

	vWString JDFMatrixState::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFStateBase::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		
		nElem=NumChildElements(elm_Value);
		for(i=0;i<nElem;i++){
			JDFValue child=GetElement(elm_Value,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Value);
				if (++n>=nMax) return vElem;
				break;
			};
		}
		return vElem;
	};
	
	//////////////////////////////////////////////////////////////////////
	WString JDFMatrixState::OptionalAttributes()const{
		return JDFStateBase::OptionalAttributes()+L",AllowedRotateMod,AllowedShift,AllowedTransforms,PresentRotateMod,PresentShift,PresentTransforms";
	};
	
	//////////////////////////////////////////////////////////////////////

	vWString JDFMatrixState::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFStateBase::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidAllowedRotateMod(level)) {
			vAtts.push_back(atr_AllowedRotateMod);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedShift(level)) {
			vAtts.push_back(atr_AllowedShift);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidAllowedTransforms(level)) {
			vAtts.push_back(atr_AllowedTransforms);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentRotateMod(level)) {
			vAtts.push_back(atr_PresentRotateMod);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentShift(level)) {
			vAtts.push_back(atr_PresentShift);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPresentTransforms(level)) {
			vAtts.push_back(atr_PresentTransforms);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixState::ValidAllowedRotateMod(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedRotateMod,AttributeType_double,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixState::ValidAllowedShift(EnumValidationLevel level)const{
		return ValidAttribute(atr_AllowedShift,AttributeType_rectangle,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixState::ValidAllowedTransforms(EnumValidationLevel level)const{
		return ValidEnumerationsAttribute(atr_AllowedTransforms,JDFElement::OrientationString(),false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixState::ValidPresentRotateMod(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentRotateMod,AttributeType_double,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixState::ValidPresentShift(EnumValidationLevel level)const{
		return ValidAttribute(atr_PresentShift,AttributeType_rectangle,false);
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFMatrixState::ValidPresentTransforms(EnumValidationLevel level)const{
		return ValidEnumerationsAttribute(atr_PresentTransforms,JDFElement::OrientationString(),false);
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixState::FitsValue(const WString& value, EnumFitsValue testlist) const{

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

		if (FitsListType(matrixList))
		{
			for (int k=0; k<matrixList.size(); k++) 
			{
				WString matrix = matrixList[k];
				if ((FitsRotateMod(matrix,testlist)&&FitsShift(matrix,testlist)&&FitsTransforms(matrix,testlist)&&FitsValueElem(matrix,testlist))==false)
					return false;
			}
			return true;	
		}
		return false;
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixState::FitsListType(const vWString& matrixList) const {

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
		
		EnumListType listtype=GetListType();

		switch (listtype) {
	
			case ListType_List:
			{
				return true;
			}
			case ListType_UniqueList:
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
			case ListType_SingleValue:
			case ListType_Unknown: // default ListType = SingleValue
			{
				return (size==1);
			}
			case ListType_CompleteList:
			case ListType_CompleteOrderedList: 
			case ListType_ContainedList:
			case ListType_OrderedList:
			case ListType_UniqueOrderedList:
			case ListType_RangeList:
			case ListType_OrderedRangeList:
			case ListType_UniqueRangeList:
			case ListType_UniqueOrderedRangeList:
			default:
			{
				throw JDFException (L"JDFMatrixState::FitsListType illegal ListType attribute"); 
			}
		}
	}

	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixState::FitsValueElem(const JDFMatrix& matrix, EnumFitsValue valuelist) const{
		
		vElement v=GetChildElementVector(elm_Value);
		int siz=v.size();
		if (siz==0) {
			return true; // State has no Value elements
		}
		for (int i=0; i<siz; i++)
		{
			JDFValue elm=v[i];
			if (elm.HasAttribute(atr_ValueUsage)) 
			{
				EnumFitsValue valueUsage = GetValueValueUsage(i); 
				if (valuelist==valueUsage)
				{
					JDFMatrix value=GetValueAllowedValue(i);
					if (value.FitsTolerance(matrix))
						return true; // we have found it
				}				
			}
			else {
				JDFMatrix value=GetValueAllowedValue(i);
				if (value.FitsTolerance(matrix))
					return true; // we have found it
			}
		}
		return false; 
	}

	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixState::FitsRotateMod(const JDFMatrix& matrix, EnumFitsValue rotatemod) const{
		
		double rm;

		if (rotatemod==FitsValue_Allowed) {
			rm = GetAllowedRotateMod();
		} else {
			rm = GetPresentRotateMod();
		}
		if(!rm) { // if AllowedRotateMod is not specified return true
			return true;
		}
		
		double a = matrix.GetA();
		double b = matrix.GetB();
		double c = matrix.GetC();
		double d = matrix.GetD();

		if ((a*d-b*c)==0)
			return false;

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

		double result = (fi+dt) - (rm * (int) ((fi+dt)/rm) );
		double result180 = (fi+180+dt) - (rm * (int) ((fi+180+dt)/rm) );
		
		return ((fabs(result) <= 2*dt) || (fabs(result180) <= 2*dt) ) ;

	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixState::FitsShift(const JDFMatrix& matrix, EnumFitsValue shift) const{
		
		if (shift==FitsValue_Allowed) {
			if(!HasAttribute(atr_AllowedShift))
				return true;
		} else {
			if(!HasAttribute(atr_AllowedShift)&&!HasAttribute(atr_PresentShift))
				return true;
		}

		JDFRectangle shiftValue;

		if (shift==FitsValue_Allowed) {
			shiftValue = GetAllowedShift();
		} else {
			shiftValue = GetPresentShift();
		}
		
		double minTx = shiftValue.GetLlx();
		double minTy = shiftValue.GetLly();
		double maxTx = shiftValue.GetUrx();
		double maxTy = shiftValue.GetUry();

		double Tx = matrix.GetTx();
		double Ty = matrix.GetTy();

		return ((Tx>=minTx)&&(Tx<=maxTx)&&(Ty>=minTy)&&(Ty<=maxTy));
	}
		
	//////////////////////////////////////////////////////////////////////
	
	bool JDFMatrixState::FitsTransforms(const JDFMatrix& matrix, EnumFitsValue transforms) const{
		
		if (transforms==FitsValue_Allowed) {
			if(!HasAttribute(atr_AllowedTransforms))
				return true;
		} else {
			if(!HasAttribute(atr_AllowedTransforms)&&!HasAttribute(atr_PresentTransforms))
				return true;
		}
		
		double nT = dt; // negative tolerance
		double pT = dt; // positive tolerance

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
		
		vint vTransf;
		if (transforms==FitsValue_Allowed) 
		{
			vTransf = GetAllowedTransforms();
		} else {
			vTransf = GetPresentTransforms();
		}
		int siz=vTransf.size();
		for (int i=0; i<siz; i++)
		{

			EnumOrientation orientation = (EnumOrientation) vTransf[i];

			switch (orientation) {

				case Orientation_Flip0: // a=1 b=0 c=0 d=-1
				{
					if ((a-1<pT)&&(a-1>-nT)&&(b<pT)&&(b>-nT)&&(c<pT)&&(c>-nT)&&(d+1<pT)&&(d+1>-nT)) 
						return true;
					continue;
				}
				case Orientation_Flip90: // a=0 b=-1 c=-1 d=0
				{
					if ((a<pT)&&(a>-nT)&&(b+1<pT)&&(b+1>-nT)&&(c+1<pT)&&(c+1>-nT)&&(d<pT)&&(d>-nT))
						return true;
					continue;
				}
				case Orientation_Flip180: // a=-1 b=0 c=0 d=1
				{
					if ((a+1<pT)&&(a+1>-nT)&&(b<pT)&&(b>-nT)&&(c<pT)&&(c>-nT)&&(d-1<pT)&&(d-1>-nT))
						return true;
					continue;
				}
				case Orientation_Flip270: // a=0 b=1 c=1 d=0
				{
					if ((a<pT)&&(a>-nT)&&(b-1<pT)&&(b-1>-nT)&&(c-1<pT)&&(c-1>-nT)&&(d<pT)&&(d>-nT))
						return true;
					continue;
				}
				case Orientation_Rotate0: // a=1 b=0 c=0 d=1
				{
					if ((a-1<pT)&&(a-1>-nT)&&(b<pT)&&(b>-nT)&&(c<pT)&&(c>-nT)&&(d-1<pT)&&(d-1>-nT))
						return true;
					continue;
				}
				case Orientation_Rotate90: // a=0 b=1 c=-1 d=0
				{
					if ((a<pT)&&(a>-nT)&&(b-1<pT)&&(b-1>-nT)&&(c+1<pT)&&(c+1>-nT)&&(d<pT)&&(d>-nT))
						return true;
					continue;
				} 
				case Orientation_Rotate180: // a=-1 b=0 c=0 d=-1
				{
					if ((a+1<pT)&&(a+1>-nT)&&(b<pT)&&(b>-nT)&&(c<pT)&&(c>-nT)&&(d+1<pT)&&(d+1>-nT))
						return true;
					continue;
				}
				case Orientation_Rotate270: // a=0 b=-1 c=1 d=0
				{
					if ((a<pT)&&(a>-nT)&&(b+1<pT)&&(b+1>-nT)&&(c-1<pT)&&(c-1>-nT)&&(d<pT)&&(d>-nT))
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
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Attribute Getter/ Setter
	**************************************************************** */	
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	void JDFMatrixState::SetAllowedRotateMod(double value){
		SetAttribute(atr_AllowedRotateMod,value);
	};
	///////////////////////////////////////////////////////////////////////
	double JDFMatrixState::GetAllowedRotateMod() const {
		return GetRealAttribute(atr_AllowedRotateMod);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFMatrixState::SetPresentRotateMod(double value){
		SetAttribute(atr_PresentRotateMod,value);
	};
	//////////////////////////////////////////////////////////////////////
	double JDFMatrixState::GetPresentRotateMod() const {
		if (HasAttribute(atr_PresentRotateMod)){
			return GetRealAttribute(atr_PresentRotateMod);
		}
		return GetAllowedRotateMod();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFMatrixState::SetAllowedShift(const JDFRectangle& value){
		SetAttribute(atr_AllowedShift,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFRectangle JDFMatrixState::GetAllowedShift() const {
		return GetAttribute(atr_AllowedShift,WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFMatrixState::SetPresentShift(const JDFRectangle& value){
		SetAttribute(atr_PresentShift,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFRectangle JDFMatrixState::GetPresentShift() const {
		if (HasAttribute(atr_PresentShift)){
			return GetAttribute(atr_PresentShift,WString::emptyStr);
		}
		return GetAllowedShift();
	};
	//////////////////////////////////////////////////////////////////////

	vint JDFMatrixState::GetAllowedTransforms() const {
		return GetEnumerationsAttribute(atr_AllowedTransforms,JDFElement::OrientationString(),WString::emptyStr);
	};
	//////////////////////////////////////////////////////////////////////
	
	void JDFMatrixState::SetAllowedTransforms(const vint& value){
		SetEnumerationsAttribute(atr_AllowedTransforms,value,JDFElement::OrientationString());
	};
	//////////////////////////////////////////////////////////////////////
	
	vint JDFMatrixState::GetPresentTransforms() const {
		if(HasAttribute(atr_PresentTransforms)) {
			return GetEnumerationsAttribute(atr_PresentTransforms,JDFElement::OrientationString(),WString::emptyStr);
		}
		return GetAllowedTransforms();
	};
	//////////////////////////////////////////////////////////////////////
	
	void JDFMatrixState::SetPresentTransforms(const vint& value){
		SetEnumerationsAttribute(atr_PresentTransforms,value,JDFElement::OrientationString());
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValue JDFMatrixState::GetValue(int iSkip)const{
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e;
	};
	
	/////////////////////////////////////////////////////////////////////

	JDFValue JDFMatrixState::AppendValue(){
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

	JDFLoc JDFMatrixState::GetValueLoc(int iSkip, int jSkip)const{
		JDFValue val=GetElement(elm_Value,WString::emptyStr,iSkip);
		JDFLoc loc=val.GetElement(elm_Loc,WString::emptyStr,jSkip);
		return loc;
	};
	/////////////////////////////////////////////////////////////////////

	JDFLoc JDFMatrixState::AppendValueLoc(int iSkip){
		JDFValue val=GetElement(elm_Value,WString::emptyStr,iSkip);
		JDFLoc loc=val.AppendElement(elm_Loc);
		loc.init();
		return loc;
	};
	//////////////////////////////////////////////////////////////////////

	void JDFMatrixState::SetValueAllowedValue(int iSkip, JDFMatrix value){
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		e.SetAllowedValue(value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFMatrix JDFMatrixState::GetValueAllowedValue(int iSkip) const {
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e.GetAllowedValue();
	};
	//////////////////////////////////////////////////////////////////////

	void JDFMatrixState::SetValueValueUsage(int iSkip, EnumFitsValue value){
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		e.SetValueUsage(value);
	};
	//////////////////////////////////////////////////////////////////////

	JDFElement::EnumFitsValue JDFMatrixState::GetValueValueUsage(int iSkip) const {
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e.GetValueUsage();
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
}