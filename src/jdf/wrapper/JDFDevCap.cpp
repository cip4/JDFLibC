/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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
// created  08.07.2002
//
// JDFDevCap.cpp: implementation of the JDFDevCap 
//
//////////////////////////////////////////////////////////////////////

#include "JDFDevCap.h"
#include "JDFDevCaps.h"
#include "JDFDeviceCap.h"
#include "JDFFactory.h"
#include "JDFBooleanState.h"
#include "JDFDateTimeState.h"
#include "JDFDurationState.h"
#include "JDFEnumerationState.h"
#include "JDFIntegerState.h"
#include "JDFMatrixState.h"
#include "JDFNameState.h"
#include "JDFNumberState.h"
#include "JDFPDFPathState.h"
#include "JDFRectangleState.h"
#include "JDFShapeState.h"
#include "JDFStringState.h"
#include "JDFXYPairState.h"
#include "JDFSpan.h"
#include "JDFComment.h"


#include "JDFState.h"

namespace JDF{
/**
* copy equivalance operator
	*/
	JDFDevCap& JDFDevCap::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFDevCap: "+other.GetNodeName());
		return *this;
	};

/////////////////////////////////////////////////////////////////////

	WString JDFDevCap::GetName() const {

		if (!HasAttribute(atr_Name)) 
		{
			WString parName = GetParentNode().GetLocalName();
			if (parName==elm_DevCaps)
            {
                JDFDevCaps devCaps = GetParentNode();
                return devCaps.GetName();
			}else{
				return WString::emptyStr;
			}
   		}
		else 
		{
			return  JDFAutoDevCap::GetName();
		}

	};

/////////////////////////////////////////////////////////////////////////

	bool JDFDevCap::ValidName(EnumValidationLevel level) const {
		WString parName = GetParentNode().GetLocalName();
		if((parName==L"DevCapPool")||(parName==L"DevCap")){
			return ValidAttribute(atr_Name,AttributeType_NMTOKEN,RequiredLevel(level));
		}else{
			return ValidAttribute(atr_Name,AttributeType_NMTOKEN,false);
		}
	};

	/////////////////////////////////////////////////////////////////////////
	WString JDFDevCap::OptionalAttributes()const{
		return JDFAutoDevCap::OptionalAttributes()+WString(L",DevCapRefs,ID");
	};

	/////////////////////////////////////////////////////////////////////////

	vWString JDFDevCap::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFAutoDevCap::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDevCapRefs(level)) {
			vAtts.push_back(atr_DevCapRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/////////////////////////////////////////////////////////////////////

	WString JDFDevCap::OptionalElements()const{
		return JDFElement::OptionalElements()+L",DevCap,Loc,BooleanState,DateTimeState,DurationState,EnumerationState,IntegerState,MatrixState,NameState,NumberState,PDFPathState,RectangleState,ShapeState,StringState,XYPairState";
	};

/////////////////////////////////////////////////////////////////////

	vWString JDFDevCap::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;

		nElem=NumChildElements(elm_DevCap);

		for(i=0;i<nElem;i++){
			if (!GetDevCap(i).IsValid(level)) {
				vElem.AppendUnique(elm_DevCap);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Loc);

		for(i=0;i<nElem;i++){
			if (!GetLoc(i).IsValid(level)) {
				vElem.AppendUnique(elm_Loc);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BooleanState);

		for(i=0;i<nElem;i++){
			if (!GetBooleanState(i).IsValid(level)) {
				vElem.AppendUnique(elm_BooleanState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DateTimeState);

		for(i=0;i<nElem;i++){
			if (!GetDateTimeState(i).IsValid(level)) {
				vElem.AppendUnique(elm_DateTimeState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DurationState);

		for(i=0;i<nElem;i++){
			if (!GetDurationState(i).IsValid(level)) {
				vElem.AppendUnique(elm_DurationState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_EnumerationState);

		for(i=0;i<nElem;i++){
			if (!GetEnumerationState(i).IsValid(level)) {
				vElem.AppendUnique(elm_EnumerationState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IntegerState);

		for(i=0;i<nElem;i++){
			if (!GetIntegerState(i).IsValid(level)) {
				vElem.AppendUnique(elm_IntegerState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MatrixState);

		for(i=0;i<nElem;i++){
			if (!GetMatrixState(i).IsValid(level)) {
				vElem.AppendUnique(elm_MatrixState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_NameState);

		for(i=0;i<nElem;i++){
			if (!GetNameState(i).IsValid(level)) {
				vElem.AppendUnique(elm_NameState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_NumberState);

		for(i=0;i<nElem;i++){
			if (!GetNumberState(i).IsValid(level)) {
				vElem.AppendUnique(elm_NumberState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PDFPathState);

		for(i=0;i<nElem;i++){
			if (!GetPDFPathState(i).IsValid(level)) {
				vElem.AppendUnique(elm_PDFPathState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RectangleState);

		for(i=0;i<nElem;i++){
			if (!GetRectangleState(i).IsValid(level)) {
				vElem.AppendUnique(elm_RectangleState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ShapeState);

		for(i=0;i<nElem;i++){
			if (!GetShapeState(i).IsValid(level)) {
				vElem.AppendUnique(elm_ShapeState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StringState);

		for(i=0;i<nElem;i++){
			if (!GetStringState(i).IsValid(level)) {
				vElem.AppendUnique(elm_StringState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_XYPairState);

		for(i=0;i<nElem;i++){
			if (!GetXYPairState(i).IsValid(level)) {
				vElem.AppendUnique(elm_XYPairState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		
		return vElem;
	};

	//////////////////////////////////////////////////////////////////////
	void JDFDevCap::SetID(const WString& value){
		SetAttribute(atr_ID,value);
	};
	//////////////////////////////////////////////////////////////////////
	
	WString JDFDevCap::GetID() const {
		return GetAttribute(atr_ID,WString::emptyStr);
	};
    //////////////////////////////////////////////////////////////////////
	
	bool JDFDevCap::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,false);
	};

	//////////////////////////////////////////////////////////////////////
	void JDFDevCap::SetDevCapRefs(const vWString& value){
		SetAttribute(atr_DevCapRefs,value);
	};
	//////////////////////////////////////////////////////////////////////
	
	vWString JDFDevCap::GetDevCapRefs() const {
		return GetAttribute(atr_DevCapRefs,WString::emptyStr);
	};
    //////////////////////////////////////////////////////////////////////
	
	bool JDFDevCap::ValidDevCapRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevCapRefs,AttributeType_IDREFS,false);
	};

	/////////////////////////////////////////////////////////////////////

	JDFDevCap JDFDevCap::GetDevCap(int iSkip)const{
		JDFDevCap e=GetElement(elm_DevCap,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDevCap JDFDevCap::GetCreateDevCap(int iSkip){
		JDFDevCap e=GetCreateElement(elm_DevCap,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFDevCap JDFDevCap::AppendDevCap(){
		JDFDevCap e=AppendElement(elm_DevCap);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFLoc JDFDevCap::GetLoc(int iSkip)const{
		JDFLoc e=GetElement(elm_Loc,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFLoc JDFDevCap::GetCreateLoc(int iSkip){
		JDFLoc e=GetCreateElement(elm_Loc,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFLoc JDFDevCap::AppendLoc(){
		JDFLoc e=AppendElement(elm_Loc);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFBooleanState JDFDevCap::GetBooleanState(int iSkip)const{
		JDFBooleanState e=GetElement(elm_BooleanState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFBooleanState JDFDevCap::GetBooleanState(WString name)
	{
		JDFBooleanState e = GetChildWithAttribute(elm_BooleanState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFBooleanState JDFDevCap::GetCreateBooleanState(int iSkip){
		JDFBooleanState e=GetCreateElement(elm_BooleanState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFBooleanState JDFDevCap::GetCreateBooleanState(WString name){
		JDFBooleanState s = JDFDevCap::GetBooleanState(name);
		if (s==NULL)
			s=JDFDevCap::AppendBooleanState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFBooleanState JDFDevCap::AppendBooleanState(){
		JDFBooleanState e=AppendElement(elm_BooleanState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFBooleanState JDFDevCap::AppendBooleanState(WString name){
		JDFBooleanState e=AppendElement(elm_BooleanState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFIntegerState JDFDevCap::GetIntegerState(int iSkip)const{
		JDFIntegerState e=GetElement(elm_IntegerState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFIntegerState JDFDevCap::GetIntegerState(WString name)
	{
		JDFIntegerState e = GetChildWithAttribute(elm_IntegerState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFIntegerState JDFDevCap::GetCreateIntegerState(int iSkip){
		JDFIntegerState e=GetCreateElement(elm_IntegerState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFIntegerState JDFDevCap::GetCreateIntegerState(WString name){
		JDFIntegerState s = JDFDevCap::GetIntegerState(name);
		if (s==NULL)
			s=JDFDevCap::AppendIntegerState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFIntegerState JDFDevCap::AppendIntegerState(){
		JDFIntegerState e=AppendElement(elm_IntegerState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFIntegerState JDFDevCap::AppendIntegerState(WString name){
		JDFIntegerState e=AppendElement(elm_IntegerState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFNumberState JDFDevCap::GetNumberState(int iSkip)const{
		JDFNumberState e=GetElement(elm_NumberState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFNumberState JDFDevCap::GetNumberState(WString name)
	{
		JDFNumberState e = GetChildWithAttribute(elm_NumberState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFNumberState JDFDevCap::GetCreateNumberState(int iSkip){
		JDFNumberState e=GetCreateElement(elm_NumberState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFNumberState JDFDevCap::GetCreateNumberState(WString name){
		JDFNumberState s = JDFDevCap::GetNumberState(name);
		if (s==NULL)
			s=JDFDevCap::AppendNumberState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFNumberState JDFDevCap::AppendNumberState(){
		JDFNumberState e=AppendElement(elm_NumberState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFNumberState JDFDevCap::AppendNumberState(WString name){
		JDFNumberState e=AppendElement(elm_NumberState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFEnumerationState JDFDevCap::GetEnumerationState(int iSkip)const{
		JDFEnumerationState e=GetElement(elm_EnumerationState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFEnumerationState JDFDevCap::GetEnumerationState(WString name)
	{
		JDFEnumerationState e = GetChildWithAttribute(elm_EnumerationState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFEnumerationState JDFDevCap::GetCreateEnumerationState(int iSkip){
		JDFEnumerationState e=GetCreateElement(elm_EnumerationState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	
	JDFEnumerationState JDFDevCap::GetCreateEnumerationState(WString name){
		JDFEnumerationState s = JDFDevCap::GetEnumerationState(name);
		if (s==NULL)
			s=JDFDevCap::AppendEnumerationState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFEnumerationState JDFDevCap::AppendEnumerationState(){
		JDFEnumerationState e=AppendElement(elm_EnumerationState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFEnumerationState JDFDevCap::AppendEnumerationState(WString name){
		JDFEnumerationState e=AppendElement(elm_EnumerationState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFNameState JDFDevCap::GetNameState(int iSkip)const{
		JDFNameState e=GetElement(elm_NameState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFNameState JDFDevCap::GetNameState(WString name)
	{
		JDFNameState e = GetChildWithAttribute(elm_NameState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFNameState JDFDevCap::GetCreateNameState(int iSkip){
		JDFNameState e=GetCreateElement(elm_NameState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFNameState JDFDevCap::GetCreateNameState(WString name){
		JDFNameState s = JDFDevCap::GetNameState(name);
		if (s==NULL)
			s=JDFDevCap::AppendNameState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFNameState JDFDevCap::AppendNameState(){
		JDFNameState e=AppendElement(elm_NameState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFNameState JDFDevCap::AppendNameState(WString name){
		JDFNameState e=AppendElement(elm_NameState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFStringState JDFDevCap::GetStringState(int iSkip)const{
		JDFStringState e=GetElement(elm_StringState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFStringState JDFDevCap::GetStringState(WString name)
	{
		JDFStringState e = GetChildWithAttribute(elm_StringState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFStringState JDFDevCap::GetCreateStringState(int iSkip){
		JDFStringState e=GetCreateElement(elm_StringState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFStringState JDFDevCap::GetCreateStringState(WString name){
		JDFStringState s = JDFDevCap::GetStringState(name);
		if (s==NULL)
			s=JDFDevCap::AppendStringState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFStringState JDFDevCap::AppendStringState(){
		JDFStringState e=AppendElement(elm_StringState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFStringState JDFDevCap::AppendStringState(WString name){
		JDFStringState e=AppendElement(elm_StringState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFXYPairState JDFDevCap::GetXYPairState(int iSkip)const{
		JDFXYPairState e=GetElement(elm_XYPairState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFXYPairState JDFDevCap::GetXYPairState(WString name)
	{
		JDFXYPairState e = GetChildWithAttribute(elm_XYPairState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFXYPairState JDFDevCap::GetCreateXYPairState(int iSkip){
		JDFXYPairState e=GetCreateElement(elm_XYPairState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFXYPairState JDFDevCap::GetCreateXYPairState(WString name){
		JDFXYPairState s = JDFDevCap::GetXYPairState(name);
		if (s==NULL)
			s=JDFDevCap::AppendXYPairState(name);
		return s;
	};


	/////////////////////////////////////////////////////////////////////

	JDFXYPairState JDFDevCap::AppendXYPairState(){
		JDFXYPairState e=AppendElement(elm_XYPairState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFXYPairState JDFDevCap::AppendXYPairState(WString name){
		JDFXYPairState e=AppendElement(elm_XYPairState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFShapeState JDFDevCap::GetShapeState(int iSkip)const{
		JDFShapeState e=GetElement(elm_ShapeState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFShapeState JDFDevCap::GetShapeState(WString name)
	{
		JDFShapeState e = GetChildWithAttribute(elm_ShapeState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFShapeState JDFDevCap::GetCreateShapeState(int iSkip){
		JDFShapeState e=GetCreateElement(elm_ShapeState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFShapeState JDFDevCap::GetCreateShapeState(WString name){
		JDFShapeState s = JDFDevCap::GetShapeState(name);
		if (s==NULL)
			s=JDFDevCap::AppendShapeState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFShapeState JDFDevCap::AppendShapeState(){
		JDFShapeState e=AppendElement(elm_ShapeState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFShapeState JDFDevCap::AppendShapeState(WString name){
		JDFShapeState e=AppendElement(elm_ShapeState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFMatrixState JDFDevCap::GetMatrixState(int iSkip)const{
		JDFMatrixState e=GetElement(elm_MatrixState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFMatrixState JDFDevCap::GetMatrixState(WString name)
	{
		JDFMatrixState e = GetChildWithAttribute(elm_MatrixState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}


	/////////////////////////////////////////////////////////////////////

	JDFMatrixState JDFDevCap::GetCreateMatrixState(int iSkip){
		JDFMatrixState e=GetCreateElement(elm_MatrixState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFMatrixState JDFDevCap::GetCreateMatrixState(WString name){
		JDFMatrixState s = JDFDevCap::GetMatrixState(name);
		if (s==NULL)
			s=JDFDevCap::AppendMatrixState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFMatrixState JDFDevCap::AppendMatrixState(){
		JDFMatrixState e=AppendElement(elm_MatrixState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFMatrixState JDFDevCap::AppendMatrixState(WString name){
		JDFMatrixState e=AppendElement(elm_MatrixState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFDateTimeState JDFDevCap::GetDateTimeState(int iSkip)const{
		JDFDateTimeState e=GetElement(elm_DateTimeState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDateTimeState JDFDevCap::GetDateTimeState(WString name)
	{
		JDFDateTimeState e = GetChildWithAttribute(elm_DateTimeState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFDateTimeState JDFDevCap::GetCreateDateTimeState(int iSkip){
		JDFDateTimeState e=GetCreateElement(elm_DateTimeState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDateTimeState JDFDevCap::GetCreateDateTimeState(WString name){
		JDFDateTimeState s = JDFDevCap::GetDateTimeState(name);
		if (s==NULL)
			s=JDFDevCap::AppendDateTimeState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDateTimeState JDFDevCap::AppendDateTimeState(){
		JDFDateTimeState e=AppendElement(elm_DateTimeState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDateTimeState JDFDevCap::AppendDateTimeState(WString name){
		JDFDateTimeState e=AppendElement(elm_DateTimeState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFDurationState JDFDevCap::GetDurationState(int iSkip)const{
		JDFDurationState e=GetElement(elm_DurationState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDurationState JDFDevCap::GetDurationState(WString name)
	{
		JDFDurationState e = GetChildWithAttribute(elm_DurationState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFDurationState JDFDevCap::GetCreateDurationState(int iSkip){
		JDFDurationState e=GetCreateElement(elm_DurationState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDurationState JDFDevCap::GetCreateDurationState(WString name){
		JDFDurationState s = JDFDevCap::GetDurationState(name);
		if (s==NULL)
			s=JDFDevCap::AppendDurationState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDurationState JDFDevCap::AppendDurationState(){
		JDFDurationState e=AppendElement(elm_DurationState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFDurationState JDFDevCap::AppendDurationState(WString name){
		JDFDurationState e=AppendElement(elm_DurationState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFPDFPathState JDFDevCap::GetPDFPathState(int iSkip)const{
		JDFPDFPathState e=GetElement(elm_PDFPathState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFPDFPathState JDFDevCap::GetPDFPathState(WString name)
	{
		JDFPDFPathState e = GetChildWithAttribute(elm_PDFPathState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFPDFPathState JDFDevCap::GetCreatePDFPathState(int iSkip){
		JDFPDFPathState e=GetCreateElement(elm_PDFPathState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFPDFPathState JDFDevCap::GetCreatePDFPathState(WString name){
		JDFPDFPathState s = JDFDevCap::GetPDFPathState(name);
		if (s==NULL)
			s=JDFDevCap::AppendPDFPathState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFPDFPathState JDFDevCap::AppendPDFPathState(){
		JDFPDFPathState e=AppendElement(elm_PDFPathState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFPDFPathState JDFDevCap::AppendPDFPathState(WString name){
		JDFPDFPathState e=AppendElement(elm_PDFPathState);
		e.SetName(name);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////

	JDFRectangleState JDFDevCap::GetRectangleState(int iSkip)const{
		JDFRectangleState e=GetElement(elm_RectangleState,WString::emptyStr,iSkip);
		return e;
	};

	/////////////////////////////////////////////////////////////////////
	
	JDFRectangleState JDFDevCap::GetRectangleState(WString name)
	{
		JDFRectangleState e = GetChildWithAttribute(elm_RectangleState, atr_Name, WString::emptyStr,
			name, 0, true);
		return e;
	}

	/////////////////////////////////////////////////////////////////////

	JDFRectangleState JDFDevCap::GetCreateRectangleState(int iSkip){
		JDFRectangleState e=GetCreateElement(elm_RectangleState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFRectangleState JDFDevCap::GetCreateRectangleState(WString name){
		JDFRectangleState s = JDFDevCap::GetRectangleState(name);
		if (s==NULL)
			s=JDFDevCap::AppendRectangleState(name);
		return s;
	};

	/////////////////////////////////////////////////////////////////////

	JDFRectangleState JDFDevCap::AppendRectangleState(){
		JDFRectangleState e=AppendElement(elm_RectangleState);
		e.init();
		return e;
	};

	/////////////////////////////////////////////////////////////////////

	JDFRectangleState JDFDevCap::AppendRectangleState(WString name){
		JDFRectangleState e=AppendElement(elm_RectangleState);
		e.SetName(name);
		e.init();
		return e;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFDevCap::GetNamePath(bool onlyNames)const{
		
		JDFDevCaps devCaps = GetDeepParent(elm_DevCaps); // a parent of DevCap can be also DevCapPool  
		WString myName=GetName();
		
		if (GetParentNode().GetNodeName()==elm_DevCap) { //subsub elem
			JDFDevCap devCap = GetParentNode();
			WString s;
			if (!myName.empty()) {
				s.append(WString::slash+myName);
			}
			return devCap.GetNamePath(onlyNames)+s;
		}
		else if (!devCaps.isNull()) {  
			return devCaps.GetNamePath(onlyNames); // skip first devcap with default name
		}
		else 
			return myName; 
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	VString JDFDevCap::getNamePathVector(bool bRecurse)
	{
		WString result = GetName();
		VString vResult;

		KElement parentNode = GetParentNode();

		WString pnLocalName = parentNode.GetLocalName();
		if (pnLocalName == elm_DevCap)
		{
			//subsub-element, always recurse
			JDFDevCap devCap = (JDFDevCap)parentNode;
			vResult = devCap.getNamePathVector(bRecurse);
		}
		else if (pnLocalName == elm_DevCapPool)
		{
			// if DevCap is located in DevCapPool it is reusable and there are no info from DevCaps(Context_LinkUsage)
			if (bRecurse)
			{
				WString id=GetID();
				if (!id.equals(WString::emptyStr))
				{
					VElement v=parentNode.GetChildrenByTagName(elm_DevCap, WString::emptyStr, mAttribute::emptyMap, false, true, 0);
					JDFDeviceCap deviceCap=(JDFDeviceCap)parentNode.GetParentNode();
					for (int i=0; i<v.size(); i++)
					{
						JDFDevCap dc=(JDFDevCap)v.elementAt(i);
						VString refs=dc.GetDevCapRefs();
						if (refs.contains(id))
						{
							WString dcID=dc.GetID();
							JDFDevCaps dcs=(JDFDevCaps)deviceCap.GetChildWithAttribute(elm_DevCaps, atr_DevCapRef, WString::emptyStr, dcID, 0, true);
							if (!dcs.isNull())
							{
								vResult.AppendUnique(dcs.getNamePathVector());
							}
							else
							{
								vResult.AppendUnique(dc.getNamePathVector(bRecurse));
							}
						}						
					}
					if (vResult.empty())
					{
						JDFDevCaps dcs=(JDFDevCaps)deviceCap.GetChildWithAttribute(elm_DevCaps, atr_DevCapRef, WString::emptyStr, id, 0, true);
						if (!dcs.isNull())
						{
							vResult=dcs.getNamePathVector();
							return vResult;
						}
					}
				}
			}
		}
		else if (pnLocalName == elm_DevCaps)
		{
			// need to add jdf in cas of Context="Element" or Context="JDF"
			JDFDevCaps devCaps = (JDFDevCaps)parentNode;
			vResult=devCaps.getNamePathVector();
			return vResult; //return here directly because the first devCap im the tree repeats the name of the devCaps
		}
		if (vResult.empty())
		{
			vResult.add(result);
		}
		else
		{
			// StringUtil.concatStrings(vResult, "/"+result)
			for (int i=0; i < vResult.size(); i++)
			{
				WString s = vResult.stringAt(i);
				s += WString::slash + result;
				vResult.stringAt(i) = s;
			}
		}
		

		return vResult;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	vElement JDFDevCap::GetDevCapVector(vElement devCaps, bool bDirect)const
    {
       int preFill=0;
	   vElement vDevCap = GetChildElementVector(elm_DevCap);
	   if(!devCaps.empty()){
            preFill=devCaps.size();
            devCaps.AppendUnique(vDevCap);
            vDevCap=devCaps;
        }
        else // first call
        {
            if(bDirect==false)
                vDevCap.AppendUnique(*this);
        }
        
        
		if (HasAttribute(atr_DevCapRefs)) 
        {         
			JDFDeviceCap deviceCap = (JDFDeviceCap) GetDeepParent(elm_DeviceCap, 0);
            JDFDevCapPool devCapPool = deviceCap.GetDevCapPool();
			if (!devCapPool.isNull()) 
            {
                VString idRefs = GetDevCapRefs();
                for (int i=0; i < idRefs.size(); i++) 
                {
                    JDFDevCap devCap = devCapPool.GetDevCap(idRefs.stringAt(i));
					if (!devCap.isNull())
                    {
                        vDevCap.AppendUnique(devCap);
                    }
                    else
                    {
                        throw new JDFException("JDFDevCap.getDevCapVector: Attribute DevCapRefs refers to the non-existent DevCap: "+idRefs.stringAt(i));
                    }
                }
            }
            else
            {
                throw new JDFException("JDFDevCap.getDevCapVector: Attribute DevCapRefs refers to the non-existent DevCapPool");
            }
        }
        if(bDirect==false){
            for(int i=preFill;i<vDevCap.size();i++)
            {
                JDFDevCap dcChild=(JDFDevCap) vDevCap.elementAt(i);
                vDevCap=dcChild.GetDevCapVector(vDevCap,bDirect);
            }
        }
        return vDevCap;
    
    }

	/////////////////////////////////////////////////////////////////////////////////////////////////////

	XMLDoc JDFDevCap::StateReport(vElement vEl, EnumFitsValue testlists, EnumValidationLevel level)const {
	
		XMLDoc testResult = XMLDoc("Temp");
        KElement root = testResult.GetRoot();
        
		// first test if there are any subelements of vEl that are not described by DevCap
        XMLDoc temp = MissingDevCapInfo(vEl);
        if (!temp.isNull()) 
        {
            root.CopyElement(temp.GetRoot());
        }

		for (int n=0; n<vEl.size(); n++) {

			JDFElement e = vEl[n]; // 'e' in DeviceCapabilities is described by this DevCap
            // it contains: (1) description of parts; 
            // (2) description of subelements; 
            // (3) description of attributes
		
			// (1) Test Partition Leaves: 'e' - is a root of partition, its leaves must be described by 'this' DevCap
			if (e.IsResource() && e.KElement::HasAttribute(atr_PartIDKeys)) 
			{
                JDFResource res = e;
				vResource vLeaves = res.GetLeaves(false);
				for (int i=0; i < vLeaves.size(); i++)
                {
                    JDFResource leaf = vLeaves.at(i);
                    vElement vL; //vElement hier has only 1 element - leaf 
                    vL.push_back(leaf);
                    XMLDoc partTestResult = StateReport(vL,testlists,level);
                    if(!partTestResult.isNull()) 
                    {
                        KElement p = root.AppendElement("InvalidPartitionLeaf");
                        WString path = leaf.GetXPath();
                        WString leafPath = path.substring(res.GetXPath().length());
                        p.SetAttribute("LeafXPath",res.GetNodeName()+leafPath);
                        MoveChildElementVector(p,partTestResult.GetRoot());
                    }
                }
            }
                 
            // (2) Test Subelements - described by DevCap that 'this' DevCap consists of
			XMLDoc subelemTestResult = SubelementsTest(e,testlists,level);
			if(!subelemTestResult.isNull()) 
			{
				root.CopyElement(subelemTestResult.GetRoot());
			}

            // (3) Test Attributes, Spans and Comments - described by States
            XMLDoc attrTestResult = SpanAndAttributesTest(e,testlists,level);
            if(!attrTestResult.isNull()) 
            {
                 MoveChildElementVector(root,attrTestResult.GetRoot());
            }
		}

		if (!root.HasChildElements())
            testResult = XMLDoc();

		return testResult;
	}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	XMLDoc JDFDevCap::SubelementsTest(const JDFElement& e, EnumFitsValue testlists, EnumValidationLevel level)const {
	
		XMLDoc testResult = XMLDoc("InvalidSubelements");
        KElement root = testResult.GetRoot();
        
        vElement vDevCap = GetDevCapVector(); // vDevCap - contains DevCap elements of this DevCap

		for (int k=0; k<vDevCap.size(); k++) { // if there are any DevCap subelements in this DavCap
												// the element e has subelements too, and we are going to check them first
			JDFDevCap dc=vDevCap[k];
			WString dcName = dc.GetName();
			// vElem - direct children of the Node. 
            // If 'dcName' is a partition Leaf - gets only children of the Leaf.
			vElement vElem=e.GetChildElementVector(dcName,WString::emptyStr,mAttribute::emptyMap,true,0,true); // follows the refelements
			int size = vElem.size();// amount of direct children of the Node (in case of partitioning - of the Leaf)
			
			// in the case of partitioning size counts the amount of elements 'dcName' in a whole Node = from leaf + from root
			if (e.IsResource()&& !JDFResource(e).IsRootElement()) {
				size = ((JDFResource)e).GetChildElementVector(dcName,WString::emptyStr,mAttribute::emptyMap,true,0,true).size(); 
			}
			
			if( size > dc.GetMaxOccurs() && RequiredLevel(level)) {

				KElement r = root.AppendElement("InvalidSubelement");
                r.SetAttribute("XPath", dc.GetNamePath(true));
                r.SetAttribute("FitsMinMaxOccurs", false);
                r.SetAttribute("AllowedMaxOccurs", dc.GetMaxOccurs()); // MaxOccurs
                r.SetAttribute("FoundElements", vElem.size());
                for (int i=0; i < vElem.size(); i++) 
                {
                    KElement ie = r.AppendElement("InvalidElement");
                    ie.SetAttribute("XPath", vElem.at(i).GetXPath());
                }
			}
			else if( size < dc.GetMinOccurs() && RequiredLevel(level)) {

				KElement r = root.AppendElement("InvalidSubelement");
                r.SetAttribute("XPath", dc.GetNamePath(true));
                r.SetAttribute("FitsMinMaxOccurs", false);
                r.SetAttribute("AllowedMinOccurs", dc.GetMinOccurs()); // MinOccurs
                r.SetAttribute("FoundElements", vElem.size());
                for (int i=0; i < vElem.size(); i++) 
                {
                    KElement ie = r.AppendElement("InvalidElement");
                    ie.SetAttribute("XPath", vElem.at(i).GetXPath());
                }
			}
			else
            {
                XMLDoc recursionResult = dc.StateReport(vElem,testlists,level); 
                if(!recursionResult.isNull()) 
                {
                    KElement r = root.AppendElement("InvalidSubelement");
                    r.SetAttribute("XPath", dc.GetNamePath(true));
                    MoveChildElementVector(r,recursionResult.GetRoot());
                }
            }
		}

		if (!root.HasChildElements() && GetBoolAttribute("FitsMinMaxOccurs",WString::emptyStr, true))
            testResult = XMLDoc();
		
		return testResult;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	XMLDoc JDFDevCap::SpanAndAttributesTest(const JDFElement& e, EnumFitsValue testlists, EnumValidationLevel level)const {
	
		XMLDoc testResult = XMLDoc("Temp");
        KElement root = testResult.GetRoot();
        KElement msp = root.AppendElement("UnknownAttributes");
        KElement map = root.AppendElement("MissingAttributes");
        KElement iap = root.AppendElement("InvalidAttributes");

		vElement vSubElem = GetChildElementVector(); // all subelements of this DevCap
	
		mAttribute am = e.GetAttributeMap(); // only attribute map of 'e'
		mAttribute m = GetSpanAndAttributesMap(e); // get of 'e' as a map of attributes: (1) all attributes, 
                                       //(2) span key-values (in case of intent resource), (3) comments 
		vWString vKeys = m.GetKeys(); //we'll use "keys" to find appropriate State elements in DevCap
					
		for (int j=0; j<vSubElem.size(); j++) { // SubElem can be DevCap, can be Loc, can be any State element
												// here we need only States 
			WString nodeName = vSubElem[j].GetNodeName();

			if (nodeName.endsWith(L"State")) {
				JDFFactory f(vSubElem[j]);
				JDFStateBase& state=(JDFStateBase&)f.GetRef();
				WString name = state.GetName();

				int size=vKeys.size();
				for (int i=size-1; i>=0; i--) {  
					WString key = vKeys[i];

					if (name==key || (key==L"CommentText" && name.length()==0)) {
						WString value = name.length()!=0 ? m[key]: m[L"CommentText"];
						if (!state.FitsValue(value,testlists)) { // The attribute/span was found but it has the wrong value

							KElement r;
                            if (!am.HasKey(key) && key!=L"CommentText") // it is Span but not Attribute
                            {
                                r = iap.AppendElement("InvalidSpan");
                                r.SetAttribute("Message", "Span value doesn't fit this State description");
                            }
                            else if (key==L"CommentText")
                            {
                                r = iap.AppendElement("InvalidComment");
                                r.SetAttribute("Message", "Comment doesn't fit this State description");
                            }
                            else 
                            {
                                r = iap.AppendElement("InvalidAttribute");
                                r.SetAttribute("Message", "Attribute value doesn't fit this State description");
                            }
                            r.SetAttribute("XPath", state.GetNamePath(true));
                            r.SetAttribute("Value", value);
						}
						vKeys.erase(vKeys.begin()+i); // The attribute was found, checked, it's ok, so we don't need it any more in vKeys 
						break; // go to another State
					}
				}
				if ((size==vKeys.size()) && (state.GetRequired()) && RequiredLevel(level)) { 
					// No attribute/span found but state is required 
					if (state.GetListType()==JDFStateBase::ListType_Span) 
                    {
                        KElement me = map.AppendElement("MissingSpan");
                        me.SetAttribute("Message", "Missing Span");
                        me.SetAttribute("XPath", state.GetNamePath(true));
                    }
                    else 
                    {
                        KElement me = map.AppendElement("MissingAttribute");
                        me.SetAttribute("Message", "Missing Attribute");
                        me.SetAttribute("XPath", state.GetNamePath(true));
                    }
				}
			}
		}
		for (int x=0; x<vKeys.size(); x++) { // if there are in vKeys still some attibutes, they must be generic attributes
			WString key = vKeys[x];
			if (!IsGenericAttribute(key)) { // if the rest attributes are not generic -> Node is rejected
				if(!am.HasKey(key) && key!=L"CommentText") 
                {
                    KElement st = msp.AppendElement("UnknownSpan");
                    st.SetAttribute("XPath", GetNamePath(true)+L"/"+key);
                    st.SetAttribute("Message", "No State description for this Span");
                }
                else 
                {
                    KElement st = msp.AppendElement("UnknownAttribute");
                    st.SetAttribute("XPath", GetNamePath(true)+L"/@"+key);
                    st.SetAttribute("Message", "No State description for this Attribute");
                }
			}
		}
	    
        if (!map.HasChildElements())
            root.RemoveChild(map.GetNodeName());
        
        if (!iap.HasChildElements())
            root.RemoveChild(iap.GetNodeName());
        
        if (!msp.HasChildElements())
            root.RemoveChild(msp.GetNodeName());

		if (!root.HasChildElements())
			testResult = XMLDoc();

		return testResult;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	mAttribute JDFDevCap::GetSpanAndAttributesMap(const JDFElement& e) const {	
		
		mAttribute m = e.GetAttributeMap(); // get all attributes of 'e' as a map of attributes
			
		if (e.IsResource())
		{
			JDFResource r = e;
			if (r.GetClass()==JDFResource::Class_Intent)
			{ // if 'e' is an Intent Resource element, spanMap is a map of Span Name-Value pairs
				mAttribute spanMap = GetSpanValueMap(r);
				vWString vSpanMapKeys = spanMap.GetKeys();
				for (int k=0; k < vSpanMapKeys.size(); k++)
				{
					WString spanKey = vSpanMapKeys.at(k);
					m.AddPair(spanKey, spanMap[spanKey]);
				}
			}
		}
		else if (e.IsComment()) 
		{
			JDFComment c = e;
			m.AddPair(L"CommentText", c.GetChildText()) ;
		}

		return m;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////

     mAttribute JDFDevCap::GetSpanValueMap(const JDFResource& r) const {
	    mAttribute map;
        vElement v = r.GetChildElementVector();
        for (int i=0; i < v.size(); i++) {
            JDFElement el = v.at(i);
			if (el.IsSpan())
            {
//              JDFSpanBase span = (JDFSpanBase) el;
//              String value = span.getValue();
                
                WString value = el.HasAttribute(atr_Actual) ? el.GetAttribute(atr_Actual) : el.GetAttribute(atr_Preferred);
                        	   
                if (value.length()==0)
                    value = el.GetAttribute(atr_Range);
                
                map.AddPair(el.GetNodeName(), value);
            }
        }    
        return map;
    }
	
   /////////////////////////////////////////////////////////////////////////////////////////////////////////
	XMLDoc JDFDevCap::MissingDevCapInfo(vElement vElem)const {

		XMLDoc testResult = XMLDoc("UnknownSubelements");
        KElement root = testResult.GetRoot();

		for (int i=0; i<vElem.size(); i++) {

			XMLDoc devCapRecursion = MissingDevCap(vElem[i]);
			if (!devCapRecursion.isNull()){
				MoveChildElementVector(root,devCapRecursion.GetRoot());
			}
		}

		if(!root.HasChildElements())
            testResult = XMLDoc();

		return testResult;

	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	XMLDoc JDFDevCap::MissingDevCap(JDFElement elem)const {

		XMLDoc testResult = XMLDoc("Temp"); // temporary root
        KElement root = testResult.GetRoot();
            
        vElement vDevCap = GetDevCapVector();

		vElement vSubElem = elem.GetChildElementVector(WString::emptyStr,WString::emptyStr,mAttribute::emptyMap,true,0,true);
		for (int i=0; i<vSubElem.size(); i++) {
			JDFElement e= vSubElem[i]; 
			if (e.IsSpan()) {
				continue; // Spans are described as State elements not as DevCap 
			}
			else if (e.IsResource()&& !JDFResource(e).IsRootElement()) {
				continue; // all partition leaves are described inside DevCap for RootElement
			}
			else { 
				WString name = e.GetNodeName();
				bool bFound=false;
				for (int k=0; k < vDevCap.size(); k++) {
					JDFDevCap devCap=vDevCap[k];
					if (devCap.GetName()==name) { // GetName() as default takes the name of a parent DevCaps
						bFound=true;
					}
				}
				if (!bFound) {
					KElement us = root.AppendElement("UnknownSubelement");
                    us.SetAttribute("XPath", GetNamePath(true) + WString::slash + name);
                    us.SetAttribute("Message", "Found no DevCap description for this element");
				}
			}
		}

		if (!root.HasChildElements())
            testResult = XMLDoc();

		return testResult;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////		
			
	bool JDFDevCap::IsGenericAttribute(const WString & key)const {
	
		WString s = GetDeepParent(elm_DeviceCap).GetAttribute(atr_GenericAttributes); // Low level implementation -> performance
		return s.HasToken(key); 
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDevCap::EnumAvailability JDFDevCap::GetAvailability()const {
	
		JDFDevCap::EnumAvailability avail=(JDFDevCap::EnumAvailability) GetEnumAttribute(atr_Availability,JDFDevCap::AvailabilityString());
		if (avail==JDFDevCap::Availability_Unknown){
			WString parName = GetParentNode().GetNodeName();
			if (parName==elm_DevCap) {
				JDFDevCap par=GetParentNode();
				avail=par.GetAvailability();
			}
			else if (parName==elm_DevCaps) { // parent can be also DevCapPool
				JDFDevCaps par=GetParentNode();
				avail=(JDFDevCap::EnumAvailability) par.GetAvailability();
			}
		}
		return avail;
		 
	}
	//////////////////////////////////////////////////////////////////////
	
	void JDFDevCap::MoveChildElementVector(KElement moveToElement, KElement moveFromElement) 
    {
		if (!moveToElement.isNull() && !moveFromElement.isNull())
        {
            vElement v = moveFromElement.GetChildElementVector();
            for (int i = 0; i < v.size(); i++) 
            {
                moveToElement.MoveElement(v.at(i));
            }
        }
        return;
    }
	  /**
      * sets the element and attribute defaults
      * @param element
      * @return
      */
	bool JDFDevCap::setDefaultsFromCaps(KElement element)const
    {
        bool success=false;
		JDFElement j=element;
        if(j.IsResource())
        {
            JDFResource r=element;
            if(!r.IsLeaf())
            {
                vElement vR=r.GetLeaves(false);
                for(int i=0;i<vR.size();i++)
                {
                    success=setDefaultsFromCaps(vR.elementAt(i)) || success;
                }
                return success;
            }
        }
        // default leaf or element case -
		VElement vSubDevCap=GetDevCapVector(vElement::emptyVector,true);
        int i;
        for(i=0;i<vSubDevCap.size();i++)
        {
            JDFDevCap subDevCap=(JDFDevCap) vSubDevCap.elementAt(i);
             int minOccurs = subDevCap.GetMinOccurs();
            VElement subElms=subDevCap.getMatchingElementsFromParent(element);
            if(minOccurs>0)
            {
                int occurs=subElms.size();
                for(int ii=occurs;ii<minOccurs;ii++)
                {
                    
                    KElement newSub=element.AppendElement(subDevCap.GetName(),subDevCap.GetDevNS());
                    subElms.add(newSub);
                    success=true;
                }
            }
            for(int ii=0;ii<subElms.size();ii++)
            {
                success = subDevCap.setDefaultsFromCaps(subElms.elementAt(ii)) || success;
            }            
        }
        // states
        VElement vStates=getStates(true);
        for(i=0;i<vStates.size();i++)
        {
            JDFStateBase state=vStates.elementAt(i);
            success = state.setDefaultsFromCaps(element) || success;
        }

        return false;
    } 
    /**
      * gets the matching elements in node that match this devcap
      * 
      * @param node the node to search in
      * @return VElement the element vector of matching elements, 
      * null if none were found
      */
	vElement JDFDevCap::getMatchingElementsFromParent(const KElement& parent)const
     {
         WString name=GetName();
		 vElement subElems=((JDFElement)parent).GetChildElementVector(name,WString::emptyStr,mAttribute::emptyMap,true,999999,true);
         return subElems;
     }

	     /**
     * return the vector of all states
     * @param bDirect if false, recurse into child elements, else return only direct child states
     * @param id ID attribute of the requested string
     * @return
     */
	 vElement JDFDevCap::getStates(bool bDirect, const WString& id) const
    {
        JDFAttributeMap m;
        if(!id.empty())
        {
            m=JDFAttributeMap(atr_ID,id);
        }
        VElement v;
        if(bDirect==true)
        {
			v=GetChildrenByTagName(WString::emptyStr,WString::emptyStr,m,bDirect,true,0);
            for(int i=v.size()-1;i>=0;i--)
            {
				if(!(v.elementAt(i).GetLocalName().endsWith(L"State")))
                    v.remove(i);
            }
        }
        else
        {
			VElement vdevCap=GetDevCapVector(vElement::emptyVector,false); 
            for(int i=0;i<vdevCap.size();i++)
            {
                JDFDevCap child=(JDFDevCap) vdevCap.elementAt(i);
                v.AppendUnique(child.getStates(true,id));
            }
        } 
        return v;
    }

}; // namespace JDF
