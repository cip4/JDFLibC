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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPrintConditionColor.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFDeviceNColor.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFTransferCurve.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPrintConditionColor : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPrintConditionColor& JDFAutoPrintConditionColor::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPrintConditionColor: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPrintConditionColor::ValidNodeNames()const{
	return L"*:,PrintConditionColor";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPrintConditionColor::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CMYK,ColorBook,ColorBookEntry,ColorBookPrefix,ColorBookSuffix,Density,Lab,MappingSelection,MediaSide,NeutralDensity,PrintConditionName,sRGB");
};

/**
 typesafe validator
*/
	vWString JDFAutoPrintConditionColor::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
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
		if(!ValidMappingSelection(level)) {
			vAtts.push_back(atr_MappingSelection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaSide(level)) {
			vAtts.push_back(atr_MediaSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNeutralDensity(level)) {
			vAtts.push_back(atr_NeutralDensity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrintConditionName(level)) {
			vAtts.push_back(atr_PrintConditionName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidsRGB(level)) {
			vAtts.push_back(atr_sRGB);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CMYK
*@param JDFCMYKColor value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetCMYK(const JDFCMYKColor& value){
	SetAttribute(atr_CMYK,value);
};
/**
* Get string attribute CMYK
* @return JDFCMYKColor the vaue of the attribute 
*/
	 JDFCMYKColor JDFAutoPrintConditionColor::GetCMYK() const {
	return GetAttribute(atr_CMYK,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidCMYK(EnumValidationLevel level) const {
		return ValidAttribute(atr_CMYK,AttributeType_CMYKColor,false);
	};
/**
* Set attribute ColorBook
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetColorBook(const WString& value){
	SetAttribute(atr_ColorBook,value);
};
/**
* Get string attribute ColorBook
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPrintConditionColor::GetColorBook() const {
	return GetAttribute(atr_ColorBook,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidColorBook(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorBook,AttributeType_string,false);
	};
/**
* Set attribute ColorBookEntry
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetColorBookEntry(const WString& value){
	SetAttribute(atr_ColorBookEntry,value);
};
/**
* Get string attribute ColorBookEntry
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPrintConditionColor::GetColorBookEntry() const {
	return GetAttribute(atr_ColorBookEntry,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidColorBookEntry(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorBookEntry,AttributeType_string,false);
	};
/**
* Set attribute ColorBookPrefix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetColorBookPrefix(const WString& value){
	SetAttribute(atr_ColorBookPrefix,value);
};
/**
* Get string attribute ColorBookPrefix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPrintConditionColor::GetColorBookPrefix() const {
	return GetAttribute(atr_ColorBookPrefix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidColorBookPrefix(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorBookPrefix,AttributeType_string,false);
	};
/**
* Set attribute ColorBookSuffix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetColorBookSuffix(const WString& value){
	SetAttribute(atr_ColorBookSuffix,value);
};
/**
* Get string attribute ColorBookSuffix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPrintConditionColor::GetColorBookSuffix() const {
	return GetAttribute(atr_ColorBookSuffix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidColorBookSuffix(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorBookSuffix,AttributeType_string,false);
	};
/**
* Set attribute Density
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetDensity(double value){
	SetAttribute(atr_Density,WString::valueOf(value));
};
/**
* Get double attribute Density
* @return double the vaue of the attribute 
*/
	 double JDFAutoPrintConditionColor::GetDensity() const {
	return GetRealAttribute(atr_Density,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidDensity(EnumValidationLevel level) const {
		return ValidAttribute(atr_Density,AttributeType_double,false);
	};
/**
* Set attribute Lab
*@param JDFLabColor value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetLab(const JDFLabColor& value){
	SetAttribute(atr_Lab,value);
};
/**
* Get string attribute Lab
* @return JDFLabColor the vaue of the attribute 
*/
	 JDFLabColor JDFAutoPrintConditionColor::GetLab() const {
	return GetAttribute(atr_Lab,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidLab(EnumValidationLevel level) const {
		return ValidAttribute(atr_Lab,AttributeType_LabColor,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPrintConditionColor::MappingSelectionString(){
		static const WString enums=WString(L"Unknown,UsePDLValues,UseLocalPrinterValues,UseProcessColorValues");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPrintConditionColor::MappingSelectionString(EnumMappingSelection value){
		return MappingSelectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPrintConditionColor::SetMappingSelection( EnumMappingSelection value){
	SetEnumAttribute(atr_MappingSelection,value,MappingSelectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPrintConditionColor::EnumMappingSelection JDFAutoPrintConditionColor:: GetMappingSelection() const {
	return (EnumMappingSelection) GetEnumAttribute(atr_MappingSelection,MappingSelectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidMappingSelection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MappingSelection,MappingSelectionString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPrintConditionColor::MediaSideString(){
		static const WString enums=WString(L"Unknown,Front,Back,Both");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPrintConditionColor::MediaSideString(EnumMediaSide value){
		return MediaSideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPrintConditionColor::SetMediaSide( EnumMediaSide value){
	SetEnumAttribute(atr_MediaSide,value,MediaSideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPrintConditionColor::EnumMediaSide JDFAutoPrintConditionColor:: GetMediaSide() const {
	return (EnumMediaSide) GetEnumAttribute(atr_MediaSide,MediaSideString(),WString::emptyStr,MediaSide_Both);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidMediaSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MediaSide,MediaSideString(),false);
	};
/**
* Set attribute NeutralDensity
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetNeutralDensity(double value){
	SetAttribute(atr_NeutralDensity,WString::valueOf(value));
};
/**
* Get double attribute NeutralDensity
* @return double the vaue of the attribute 
*/
	 double JDFAutoPrintConditionColor::GetNeutralDensity() const {
	return GetRealAttribute(atr_NeutralDensity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidNeutralDensity(EnumValidationLevel level) const {
		return ValidAttribute(atr_NeutralDensity,AttributeType_double,false);
	};
/**
* Set attribute PrintConditionName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetPrintConditionName(const WString& value){
	SetAttribute(atr_PrintConditionName,value);
};
/**
* Get string attribute PrintConditionName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPrintConditionColor::GetPrintConditionName() const {
	return GetAttribute(atr_PrintConditionName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidPrintConditionName(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrintConditionName,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute sRGB
*@param JDFRGBColor value: the value to set the attribute to
*/
	 void JDFAutoPrintConditionColor::SetsRGB(const JDFRGBColor& value){
	SetAttribute(atr_sRGB,value);
};
/**
* Get string attribute sRGB
* @return JDFRGBColor the vaue of the attribute 
*/
	 JDFRGBColor JDFAutoPrintConditionColor::GetsRGB() const {
	return GetAttribute(atr_sRGB,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintConditionColor::ValidsRGB(EnumValidationLevel level) const {
		return ValidAttribute(atr_sRGB,AttributeType_RGBColor,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoPrintConditionColor::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoPrintConditionColor::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoPrintConditionColor::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPrintConditionColor::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNColor JDFAutoPrintConditionColor::GetDeviceNColor(int iSkip)const{
	JDFDeviceNColor e=GetElement(elm_DeviceNColor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNColor JDFAutoPrintConditionColor::GetCreateDeviceNColor(int iSkip){
	JDFDeviceNColor e=GetCreateElement(elm_DeviceNColor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNColor JDFAutoPrintConditionColor::AppendDeviceNColor(){
	JDFDeviceNColor e=AppendElement(elm_DeviceNColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoPrintConditionColor::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoPrintConditionColor::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoPrintConditionColor::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPrintConditionColor::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurve JDFAutoPrintConditionColor::GetTransferCurve(int iSkip)const{
	JDFTransferCurve e=GetElement(elm_TransferCurve,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurve JDFAutoPrintConditionColor::GetCreateTransferCurve(int iSkip){
	JDFTransferCurve e=GetCreateElement(elm_TransferCurve,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurve JDFAutoPrintConditionColor::AppendTransferCurve(){
	JDFTransferCurve e=AppendElement(elm_TransferCurve);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPrintConditionColor::RefTransferCurve(JDFTransferCurve& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPrintConditionColor::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
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
		nElem=NumChildElements(elm_Media);

		for(i=0;i<nElem;i++){
			if (!GetMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_Media);
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
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPrintConditionColor::OptionalElements()const{
		return JDFElement::OptionalElements()+L",FileSpec,DeviceNColor,Media,TransferCurve";
	};
}; // end namespace JDF
