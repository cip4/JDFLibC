/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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


///////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/AutoJDF/JDFAutoDevCap.h"
#include "jdf/wrapper/JDFDevCap.h"
#include "jdf/wrapper/JDFLoc.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDevCap : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDevCap& JDFAutoDevCap::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDevCap: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDevCap::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDevCap::ValidNodeNames()const{
	return L"*:,DevCap";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDevCap::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Availability,DevCapRefs,DevNS,ID,MaxOccurs,MinOccurs,ModuleRefs,Name,ResourceUsage");
};

/**
 typesafe validator
*/
	vWString JDFAutoDevCap::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAvailability(level)) {
			vAtts.push_back(atr_Availability);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDevCapRefs(level)) {
			vAtts.push_back(atr_DevCapRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDevNS(level)) {
			vAtts.push_back(atr_DevNS);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxOccurs(level)) {
			vAtts.push_back(atr_MaxOccurs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinOccurs(level)) {
			vAtts.push_back(atr_MinOccurs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleRefs(level)) {
			vAtts.push_back(atr_ModuleRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceUsage(level)) {
			vAtts.push_back(atr_ResourceUsage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDevCap::AvailabilityString(){
		static const WString enums=WString(L"Unknown,Installed,Module,NotInstalled,NotLicensed,Disabled");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDevCap::AvailabilityString(EnumAvailability value){
		return AvailabilityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDevCap::SetAvailability( EnumAvailability value){
	SetEnumAttribute(atr_Availability,value,AvailabilityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDevCap::EnumAvailability JDFAutoDevCap:: GetAvailability() const {
	return (EnumAvailability) GetEnumAttribute(atr_Availability,AvailabilityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidAvailability(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Availability,AvailabilityString(),false);
	};
/**
* Set attribute DevCapRefs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDevCap::SetDevCapRefs(const vWString& value){
	SetAttribute(atr_DevCapRefs,value);
};
/**
* Get string attribute DevCapRefs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDevCap::GetDevCapRefs() const {
	return GetAttribute(atr_DevCapRefs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidDevCapRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevCapRefs,AttributeType_IDREFS,false);
	};
/**
* Set attribute DevNS
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCap::SetDevNS(const WString& value){
	SetAttribute(atr_DevNS,value);
};
/**
* Get string attribute DevNS
* @return WString the vaue of the attribute ; defaults to http://www.CIP4.org/JDFSchema_1_1
*/
	 WString JDFAutoDevCap::GetDevNS() const {
	return GetAttribute(atr_DevNS,WString::emptyStr,L"http://www.CIP4.org/JDFSchema_1_1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidDevNS(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevNS,AttributeType_URI,false);
	};
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCap::SetID(const WString& value){
	SetAttribute(atr_ID,value);
};
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevCap::GetID() const {
	return GetAttribute(atr_ID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,false);
	};
/**
* Set attribute MaxOccurs
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDevCap::SetMaxOccurs(int value){
	SetAttribute(atr_MaxOccurs,WString::valueOf(value));
};
/**
* Get integer attribute MaxOccurs
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoDevCap::GetMaxOccurs() const {
	return GetIntAttribute(atr_MaxOccurs,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidMaxOccurs(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxOccurs,AttributeType_integer,false);
	};
/**
* Set attribute MinOccurs
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDevCap::SetMinOccurs(int value){
	SetAttribute(atr_MinOccurs,WString::valueOf(value));
};
/**
* Get integer attribute MinOccurs
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoDevCap::GetMinOccurs() const {
	return GetIntAttribute(atr_MinOccurs,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidMinOccurs(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinOccurs,AttributeType_integer,false);
	};
/**
* Set attribute ModuleRefs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDevCap::SetModuleRefs(const vWString& value){
	SetAttribute(atr_ModuleRefs,value);
};
/**
* Get string attribute ModuleRefs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDevCap::GetModuleRefs() const {
	return GetAttribute(atr_ModuleRefs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidModuleRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleRefs,AttributeType_IDREFS,false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCap::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevCap::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ResourceUsage
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCap::SetResourceUsage(const WString& value){
	SetAttribute(atr_ResourceUsage,value);
};
/**
* Get string attribute ResourceUsage
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevCap::GetResourceUsage() const {
	return GetAttribute(atr_ResourceUsage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCap::ValidResourceUsage(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceUsage,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDevCap JDFAutoDevCap::GetDevCap(int iSkip)const{
	JDFDevCap e=GetElement(elm_DevCap,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCap JDFAutoDevCap::GetCreateDevCap(int iSkip){
	JDFDevCap e=GetCreateElement(elm_DevCap,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCap JDFAutoDevCap::AppendDevCap(){
	JDFDevCap e=AppendElement(elm_DevCap);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoDevCap::GetLoc(int iSkip)const{
	JDFLoc e=GetElement(elm_Loc,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoDevCap::GetCreateLoc(int iSkip){
	JDFLoc e=GetCreateElement(elm_Loc,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoDevCap::AppendLoc(){
	JDFLoc e=AppendElement(elm_Loc);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoDevCap::GetBooleanState(int iSkip)const{
	JDFBooleanState e=GetElement(elm_BooleanState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoDevCap::GetCreateBooleanState(int iSkip){
	JDFBooleanState e=GetCreateElement(elm_BooleanState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoDevCap::AppendBooleanState(){
	JDFBooleanState e=AppendElement(elm_BooleanState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoDevCap::GetDateTimeState(int iSkip)const{
	JDFDateTimeState e=GetElement(elm_DateTimeState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoDevCap::GetCreateDateTimeState(int iSkip){
	JDFDateTimeState e=GetCreateElement(elm_DateTimeState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoDevCap::AppendDateTimeState(){
	JDFDateTimeState e=AppendElement(elm_DateTimeState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoDevCap::GetDurationState(int iSkip)const{
	JDFDurationState e=GetElement(elm_DurationState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoDevCap::GetCreateDurationState(int iSkip){
	JDFDurationState e=GetCreateElement(elm_DurationState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoDevCap::AppendDurationState(){
	JDFDurationState e=AppendElement(elm_DurationState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoDevCap::GetEnumerationState(int iSkip)const{
	JDFEnumerationState e=GetElement(elm_EnumerationState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoDevCap::GetCreateEnumerationState(int iSkip){
	JDFEnumerationState e=GetCreateElement(elm_EnumerationState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoDevCap::AppendEnumerationState(){
	JDFEnumerationState e=AppendElement(elm_EnumerationState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoDevCap::GetIntegerState(int iSkip)const{
	JDFIntegerState e=GetElement(elm_IntegerState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoDevCap::GetCreateIntegerState(int iSkip){
	JDFIntegerState e=GetCreateElement(elm_IntegerState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoDevCap::AppendIntegerState(){
	JDFIntegerState e=AppendElement(elm_IntegerState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoDevCap::GetMatrixState(int iSkip)const{
	JDFMatrixState e=GetElement(elm_MatrixState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoDevCap::GetCreateMatrixState(int iSkip){
	JDFMatrixState e=GetCreateElement(elm_MatrixState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoDevCap::AppendMatrixState(){
	JDFMatrixState e=AppendElement(elm_MatrixState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoDevCap::GetNameState(int iSkip)const{
	JDFNameState e=GetElement(elm_NameState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoDevCap::GetCreateNameState(int iSkip){
	JDFNameState e=GetCreateElement(elm_NameState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoDevCap::AppendNameState(){
	JDFNameState e=AppendElement(elm_NameState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoDevCap::GetNumberState(int iSkip)const{
	JDFNumberState e=GetElement(elm_NumberState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoDevCap::GetCreateNumberState(int iSkip){
	JDFNumberState e=GetCreateElement(elm_NumberState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoDevCap::AppendNumberState(){
	JDFNumberState e=AppendElement(elm_NumberState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoDevCap::GetPDFPathState(int iSkip)const{
	JDFPDFPathState e=GetElement(elm_PDFPathState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoDevCap::GetCreatePDFPathState(int iSkip){
	JDFPDFPathState e=GetCreateElement(elm_PDFPathState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoDevCap::AppendPDFPathState(){
	JDFPDFPathState e=AppendElement(elm_PDFPathState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoDevCap::GetRectangleState(int iSkip)const{
	JDFRectangleState e=GetElement(elm_RectangleState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoDevCap::GetCreateRectangleState(int iSkip){
	JDFRectangleState e=GetCreateElement(elm_RectangleState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoDevCap::AppendRectangleState(){
	JDFRectangleState e=AppendElement(elm_RectangleState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoDevCap::GetShapeState(int iSkip)const{
	JDFShapeState e=GetElement(elm_ShapeState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoDevCap::GetCreateShapeState(int iSkip){
	JDFShapeState e=GetCreateElement(elm_ShapeState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoDevCap::AppendShapeState(){
	JDFShapeState e=AppendElement(elm_ShapeState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoDevCap::GetStringState(int iSkip)const{
	JDFStringState e=GetElement(elm_StringState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoDevCap::GetCreateStringState(int iSkip){
	JDFStringState e=GetCreateElement(elm_StringState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoDevCap::AppendStringState(){
	JDFStringState e=AppendElement(elm_StringState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoDevCap::GetXYPairState(int iSkip)const{
	JDFXYPairState e=GetElement(elm_XYPairState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoDevCap::GetCreateXYPairState(int iSkip){
	JDFXYPairState e=GetCreateElement(elm_XYPairState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoDevCap::AppendXYPairState(){
	JDFXYPairState e=AppendElement(elm_XYPairState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDevCap::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDevCap::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Loc,BooleanState,DateTimeState,DurationState,EnumerationState,IntegerState,MatrixState,NameState,NumberState,PDFPathState,RectangleState,ShapeState,StringState,XYPairState";
	};
}; // end namespace JDF
