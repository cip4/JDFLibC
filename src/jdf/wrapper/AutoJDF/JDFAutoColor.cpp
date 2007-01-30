/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColor.h"
#include "jdf/wrapper/JDFColorMeasurementConditions.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFDeviceNColor.h"
#include "jdf/wrapper/JDFPrintConditionColor.h"
#include "jdf/wrapper/JDFTransferCurve.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColor : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColor& JDFAutoColor::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColor: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColor::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColor::ValidNodeNames()const{
	return L"*:,Color";
};

bool JDFAutoColor::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoColor::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoColor::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Name";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoColor::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",MappingSelection,CMYK,ColorBook,ColorBookEntry,ColorBookPrefix,ColorBookSuffix,ColorName,ColorType,Density,Lab,MediaType,NeutralDensity,RawName,sRGB,UsePDLAlternateCS");
};

/**
 typesafe validator
*/
	vWString JDFAutoColor::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMappingSelection(level)) {
			vAtts.push_back(atr_MappingSelection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCMYK(level)) {
			vAtts.push_back(atr_CMYK);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorBook(level)) {
			vAtts.push_back(atr_ColorBook);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorBookEntry(level)) {
			vAtts.push_back(atr_ColorBookEntry);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorBookPrefix(level)) {
			vAtts.push_back(atr_ColorBookPrefix);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorBookSuffix(level)) {
			vAtts.push_back(atr_ColorBookSuffix);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorName(level)) {
			vAtts.push_back(atr_ColorName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorType(level)) {
			vAtts.push_back(atr_ColorType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDensity(level)) {
			vAtts.push_back(atr_Density);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLab(level)) {
			vAtts.push_back(atr_Lab);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaType(level)) {
			vAtts.push_back(atr_MediaType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNeutralDensity(level)) {
			vAtts.push_back(atr_NeutralDensity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRawName(level)) {
			vAtts.push_back(atr_RawName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidsRGB(level)) {
			vAtts.push_back(atr_sRGB);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUsePDLAlternateCS(level)) {
			vAtts.push_back(atr_UsePDLAlternateCS);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColor::MappingSelectionString(){
		static const WString enums=WString(L"Unknown,UsePDLValues,UseLocalPrinterValues,UseProcessColorValues");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColor::MappingSelectionString(EnumMappingSelection value){
		return MappingSelectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColor::SetMappingSelection( EnumMappingSelection value){
	SetEnumAttribute(atr_MappingSelection,value,MappingSelectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColor::EnumMappingSelection JDFAutoColor:: GetMappingSelection() const {
	return (EnumMappingSelection) GetEnumAttribute(atr_MappingSelection,MappingSelectionString(),WString::emptyStr,MappingSelection_UsePDLValues);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidMappingSelection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MappingSelection,MappingSelectionString(),false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColor::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColor::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute CMYK
*@param JDFCMYKColor value: the value to set the attribute to
*/
	 void JDFAutoColor::SetCMYK(const JDFCMYKColor& value){
	SetAttribute(atr_CMYK,value);
};
/**
* Get string attribute CMYK
* @return JDFCMYKColor the vaue of the attribute 
*/
	 JDFCMYKColor JDFAutoColor::GetCMYK() const {
	return GetAttribute(atr_CMYK,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidCMYK(EnumValidationLevel level) const {
		return ValidAttribute(atr_CMYK,AttributeType_CMYKColor,false);
	};
/**
* Set attribute ColorBook
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColor::SetColorBook(const WString& value){
	SetAttribute(atr_ColorBook,value);
};
/**
* Get string attribute ColorBook
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColor::GetColorBook() const {
	return GetAttribute(atr_ColorBook,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidColorBook(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorBook,AttributeType_string,false);
	};
/**
* Set attribute ColorBookEntry
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColor::SetColorBookEntry(const WString& value){
	SetAttribute(atr_ColorBookEntry,value);
};
/**
* Get string attribute ColorBookEntry
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColor::GetColorBookEntry() const {
	return GetAttribute(atr_ColorBookEntry,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidColorBookEntry(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorBookEntry,AttributeType_string,false);
	};
/**
* Set attribute ColorBookPrefix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColor::SetColorBookPrefix(const WString& value){
	SetAttribute(atr_ColorBookPrefix,value);
};
/**
* Get string attribute ColorBookPrefix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColor::GetColorBookPrefix() const {
	return GetAttribute(atr_ColorBookPrefix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidColorBookPrefix(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorBookPrefix,AttributeType_string,false);
	};
/**
* Set attribute ColorBookSuffix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColor::SetColorBookSuffix(const WString& value){
	SetAttribute(atr_ColorBookSuffix,value);
};
/**
* Get string attribute ColorBookSuffix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColor::GetColorBookSuffix() const {
	return GetAttribute(atr_ColorBookSuffix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidColorBookSuffix(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorBookSuffix,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoColor::SetColorName( EnumNamedColor value){
	SetEnumAttribute(atr_ColorName,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColor::EnumNamedColor JDFAutoColor:: GetColorName() const {
	return (EnumNamedColor) GetEnumAttribute(atr_ColorName,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidColorName(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ColorName,NamedColorString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColor::ColorTypeString(){
		static const WString enums=WString(L"Unknown,DieLine,Normal,Transparent,Opaque,OpaqueIgnore");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColor::ColorTypeString(EnumColorType value){
		return ColorTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColor::SetColorType( EnumColorType value){
	SetEnumAttribute(atr_ColorType,value,ColorTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColor::EnumColorType JDFAutoColor:: GetColorType() const {
	return (EnumColorType) GetEnumAttribute(atr_ColorType,ColorTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidColorType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ColorType,ColorTypeString(),false);
	};
/**
* Set attribute Density
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColor::SetDensity(double value){
	SetAttribute(atr_Density,WString::valueOf(value));
};
/**
* Get double attribute Density
* @return double the vaue of the attribute 
*/
	 double JDFAutoColor::GetDensity() const {
	return GetRealAttribute(atr_Density,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidDensity(EnumValidationLevel level) const {
		return ValidAttribute(atr_Density,AttributeType_double,false);
	};
/**
* Set attribute Lab
*@param JDFLabColor value: the value to set the attribute to
*/
	 void JDFAutoColor::SetLab(const JDFLabColor& value){
	SetAttribute(atr_Lab,value);
};
/**
* Get string attribute Lab
* @return JDFLabColor the vaue of the attribute 
*/
	 JDFLabColor JDFAutoColor::GetLab() const {
	return GetAttribute(atr_Lab,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidLab(EnumValidationLevel level) const {
		return ValidAttribute(atr_Lab,AttributeType_LabColor,false);
	};
/**
* Set attribute MediaType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColor::SetMediaType(const WString& value){
	SetAttribute(atr_MediaType,value);
};
/**
* Get string attribute MediaType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColor::GetMediaType() const {
	return GetAttribute(atr_MediaType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidMediaType(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaType,AttributeType_string,false);
	};
/**
* Set attribute NeutralDensity
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColor::SetNeutralDensity(double value){
	SetAttribute(atr_NeutralDensity,WString::valueOf(value));
};
/**
* Get double attribute NeutralDensity
* @return double the vaue of the attribute 
*/
	 double JDFAutoColor::GetNeutralDensity() const {
	return GetRealAttribute(atr_NeutralDensity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidNeutralDensity(EnumValidationLevel level) const {
		return ValidAttribute(atr_NeutralDensity,AttributeType_double,false);
	};
/**
* Set attribute RawName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColor::SetRawName(const WString& value){
	SetAttribute(atr_RawName,value);
};
/**
* Get string attribute RawName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColor::GetRawName() const {
	return GetAttribute(atr_RawName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidRawName(EnumValidationLevel level) const {
		return ValidAttribute(atr_RawName,AttributeType_hexBinary,false);
	};
/**
* Set attribute sRGB
*@param JDFRGBColor value: the value to set the attribute to
*/
	 void JDFAutoColor::SetsRGB(const JDFRGBColor& value){
	SetAttribute(atr_sRGB,value);
};
/**
* Get string attribute sRGB
* @return JDFRGBColor the vaue of the attribute 
*/
	 JDFRGBColor JDFAutoColor::GetsRGB() const {
	return GetAttribute(atr_sRGB,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidsRGB(EnumValidationLevel level) const {
		return ValidAttribute(atr_sRGB,AttributeType_RGBColor,false);
	};
/**
* Set attribute UsePDLAlternateCS
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoColor::SetUsePDLAlternateCS(bool value){
	SetAttribute(atr_UsePDLAlternateCS,WString::valueOf(value));
};
/**
* Get bool attribute UsePDLAlternateCS
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoColor::GetUsePDLAlternateCS() const {return GetBoolAttribute(atr_UsePDLAlternateCS,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColor::ValidUsePDLAlternateCS(EnumValidationLevel level) const {
		return ValidAttribute(atr_UsePDLAlternateCS,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColorMeasurementConditions JDFAutoColor::GetColorMeasurementConditions()const{
	JDFColorMeasurementConditions e=GetElement(elm_ColorMeasurementConditions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoColor::GetCreateColorMeasurementConditions(){
	JDFColorMeasurementConditions e=GetCreateElement(elm_ColorMeasurementConditions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoColor::AppendColorMeasurementConditions(){
	JDFColorMeasurementConditions e=AppendElementN(elm_ColorMeasurementConditions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColor::RefColorMeasurementConditions(JDFColorMeasurementConditions& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColor::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColor::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColor::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColor::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNColor JDFAutoColor::GetDeviceNColor(int iSkip)const{
	JDFDeviceNColor e=GetElement(elm_DeviceNColor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNColor JDFAutoColor::GetCreateDeviceNColor(int iSkip){
	JDFDeviceNColor e=GetCreateElement(elm_DeviceNColor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNColor JDFAutoColor::AppendDeviceNColor(){
	JDFDeviceNColor e=AppendElement(elm_DeviceNColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPrintConditionColor JDFAutoColor::GetPrintConditionColor(int iSkip)const{
	JDFPrintConditionColor e=GetElement(elm_PrintConditionColor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPrintConditionColor JDFAutoColor::GetCreatePrintConditionColor(int iSkip){
	JDFPrintConditionColor e=GetCreateElement(elm_PrintConditionColor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPrintConditionColor JDFAutoColor::AppendPrintConditionColor(){
	JDFPrintConditionColor e=AppendElement(elm_PrintConditionColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurve JDFAutoColor::GetTransferCurve(int iSkip)const{
	JDFTransferCurve e=GetElement(elm_TransferCurve,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurve JDFAutoColor::GetCreateTransferCurve(int iSkip){
	JDFTransferCurve e=GetCreateElement(elm_TransferCurve,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurve JDFAutoColor::AppendTransferCurve(){
	JDFTransferCurve e=AppendElement(elm_TransferCurve);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColor::RefTransferCurve(JDFTransferCurve& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoColor::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorMeasurementConditions);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorMeasurementConditions);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorMeasurementConditions().IsValid(level)) {
				vElem.AppendUnique(elm_ColorMeasurementConditions);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FileSpec);

		for(i=0;i<nElem;i++){
			if (!GetFileSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DeviceNColor);

		for(i=0;i<nElem;i++){
			if (!GetDeviceNColor(i).IsValid(level)) {
				vElem.AppendUnique(elm_DeviceNColor);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PrintConditionColor);

		for(i=0;i<nElem;i++){
			if (!GetPrintConditionColor(i).IsValid(level)) {
				vElem.AppendUnique(elm_PrintConditionColor);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TransferCurve);

		for(i=0;i<nElem;i++){
			if (!GetTransferCurve(i).IsValid(level)) {
				vElem.AppendUnique(elm_TransferCurve);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoColor::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorMeasurementConditions";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoColor::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorMeasurementConditions,FileSpec,DeviceNColor,PrintConditionColor,TransferCurve";
	};
}; // end namespace JDF
