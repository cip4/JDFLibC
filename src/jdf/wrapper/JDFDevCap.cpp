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

	JDFBooleanState JDFDevCap::GetCreateBooleanState(int iSkip){
		JDFBooleanState e=GetCreateElement(elm_BooleanState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFBooleanState JDFDevCap::AppendBooleanState(){
		JDFBooleanState e=AppendElement(elm_BooleanState);
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

	JDFIntegerState JDFDevCap::GetCreateIntegerState(int iSkip){
		JDFIntegerState e=GetCreateElement(elm_IntegerState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFIntegerState JDFDevCap::AppendIntegerState(){
		JDFIntegerState e=AppendElement(elm_IntegerState);
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

	JDFNumberState JDFDevCap::GetCreateNumberState(int iSkip){
		JDFNumberState e=GetCreateElement(elm_NumberState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFNumberState JDFDevCap::AppendNumberState(){
		JDFNumberState e=AppendElement(elm_NumberState);
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

	JDFEnumerationState JDFDevCap::GetCreateEnumerationState(int iSkip){
		JDFEnumerationState e=GetCreateElement(elm_EnumerationState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFEnumerationState JDFDevCap::AppendEnumerationState(){
		JDFEnumerationState e=AppendElement(elm_EnumerationState);
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

	JDFNameState JDFDevCap::GetCreateNameState(int iSkip){
		JDFNameState e=GetCreateElement(elm_NameState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFNameState JDFDevCap::AppendNameState(){
		JDFNameState e=AppendElement(elm_NameState);
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

	JDFStringState JDFDevCap::GetCreateStringState(int iSkip){
		JDFStringState e=GetCreateElement(elm_StringState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFStringState JDFDevCap::AppendStringState(){
		JDFStringState e=AppendElement(elm_StringState);
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

	JDFXYPairState JDFDevCap::GetCreateXYPairState(int iSkip){
		JDFXYPairState e=GetCreateElement(elm_XYPairState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFXYPairState JDFDevCap::AppendXYPairState(){
		JDFXYPairState e=AppendElement(elm_XYPairState);
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

	JDFShapeState JDFDevCap::GetCreateShapeState(int iSkip){
		JDFShapeState e=GetCreateElement(elm_ShapeState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFShapeState JDFDevCap::AppendShapeState(){
		JDFShapeState e=AppendElement(elm_ShapeState);
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

	JDFMatrixState JDFDevCap::GetCreateMatrixState(int iSkip){
		JDFMatrixState e=GetCreateElement(elm_MatrixState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFMatrixState JDFDevCap::AppendMatrixState(){
		JDFMatrixState e=AppendElement(elm_MatrixState);
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

	JDFDateTimeState JDFDevCap::GetCreateDateTimeState(int iSkip){
		JDFDateTimeState e=GetCreateElement(elm_DateTimeState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFDateTimeState JDFDevCap::AppendDateTimeState(){
		JDFDateTimeState e=AppendElement(elm_DateTimeState);
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

	JDFDurationState JDFDevCap::GetCreateDurationState(int iSkip){
		JDFDurationState e=GetCreateElement(elm_DurationState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFDurationState JDFDevCap::AppendDurationState(){
		JDFDurationState e=AppendElement(elm_DurationState);
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

	JDFPDFPathState JDFDevCap::GetCreatePDFPathState(int iSkip){
		JDFPDFPathState e=GetCreateElement(elm_PDFPathState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFPDFPathState JDFDevCap::AppendPDFPathState(){
		JDFPDFPathState e=AppendElement(elm_PDFPathState);
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

	JDFRectangleState JDFDevCap::GetCreateRectangleState(int iSkip){
		JDFRectangleState e=GetCreateElement(elm_RectangleState,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFRectangleState JDFDevCap::AppendRectangleState(){
		JDFRectangleState e=AppendElement(elm_RectangleState);
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

	vElement JDFDevCap::GetDevCapVector()const
    {
        vElement vDevCap = GetChildElementVector(elm_DevCap);

        if (HasAttribute(atr_DevCapRefs)) 
        {         
            JDFDeviceCap deviceCap = GetDeepParent(elm_DeviceCap);
            JDFDevCapPool devCapPool = deviceCap.GetDevCapPool();
			if (!devCapPool.isNull()) 
            {
                vWString idRefs = GetDevCapRefs();
                for (int i=0; i < idRefs.size(); i++) 
                {
                    mAttribute idMap;
                    idMap.AddPair(atr_ID, idRefs.at(i));
					JDFDevCap devCap = devCapPool.GetChildByTagName(elm_DevCap,WString::emptyStr,0,idMap);
					if (!devCap.isNull())
                    {
                        vDevCap.push_back(devCap);
                    }
                    else
                    {
						throw new JDFException("JDFDevCap::GetDevCapVector: Attribute DevCapRefs refers to the non-existent DevCap");
                    }
                }
            }
            else
            {
				throw new JDFException("JDFDevCap::GetDevCapVector: Attribute DevCapRefs refers to the non-existent DevCapPool");
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
				WString nam = state.GetName();

				int size=vKeys.size();
				for (int i=size-1; i>=0; i--) {  
					WString key = vKeys[i];

					if (nam==key || (key==L"CommentText" && nam.length()==0)) {
						WString value = nam.length()!=0 ? m[key]: m[L"CommentText"];
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

}; // namespace JDF
