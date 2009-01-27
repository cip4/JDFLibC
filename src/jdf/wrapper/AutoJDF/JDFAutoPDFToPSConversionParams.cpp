/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPDFToPSConversionParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPDFToPSConversionParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPDFToPSConversionParams& JDFAutoPDFToPSConversionParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPDFToPSConversionParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPDFToPSConversionParams::ValidNodeNames()const{
	return L"*:,PDFToPSConversionParams";
};

bool JDFAutoPDFToPSConversionParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPDFToPSConversionParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPDFToPSConversionParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BinaryOK,CenterCropBox,GeneratePageStreams,IgnoreAnnotForms,IgnoreBG,IgnoreColorSeps,IgnoreDSC,IgnoreExternStreamRef,IgnoreHalftones,IgnoreOverprint,IgnorePageRotation,IgnoreRawData,IgnoreSeparableImagesOnly,IgnoreShowPage,IgnoreTransfers,IgnoreTTFontsFirst,IgnoreUCR,IncludeBaseFonts,IncludeCIDFonts")
	+WString(L",IncludeEmbeddedFonts,IncludeOtherResources,IncludeProcSets,IncludeTrueTypeFonts,IncludeType1Fonts,IncludeType3Fonts,OutputType,PSLevel,Scale,SetPageSize,SetupProcsets,ShrinkToFit,SuppressCenter,SuppressRotate,TTasT42,UseFontAliasNames,IgnoreDeviceExtGState,BoundingBox");
};

/**
 typesafe validator
*/
	vWString JDFAutoPDFToPSConversionParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBinaryOK(level)) {
			vAtts.push_back(atr_BinaryOK);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCenterCropBox(level)) {
			vAtts.push_back(atr_CenterCropBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGeneratePageStreams(level)) {
			vAtts.push_back(atr_GeneratePageStreams);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreAnnotForms(level)) {
			vAtts.push_back(atr_IgnoreAnnotForms);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreBG(level)) {
			vAtts.push_back(atr_IgnoreBG);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreColorSeps(level)) {
			vAtts.push_back(atr_IgnoreColorSeps);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreDSC(level)) {
			vAtts.push_back(atr_IgnoreDSC);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreExternStreamRef(level)) {
			vAtts.push_back(atr_IgnoreExternStreamRef);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreHalftones(level)) {
			vAtts.push_back(atr_IgnoreHalftones);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreOverprint(level)) {
			vAtts.push_back(atr_IgnoreOverprint);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnorePageRotation(level)) {
			vAtts.push_back(atr_IgnorePageRotation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreRawData(level)) {
			vAtts.push_back(atr_IgnoreRawData);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreSeparableImagesOnly(level)) {
			vAtts.push_back(atr_IgnoreSeparableImagesOnly);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreShowPage(level)) {
			vAtts.push_back(atr_IgnoreShowPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreTransfers(level)) {
			vAtts.push_back(atr_IgnoreTransfers);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreTTFontsFirst(level)) {
			vAtts.push_back(atr_IgnoreTTFontsFirst);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreUCR(level)) {
			vAtts.push_back(atr_IgnoreUCR);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeBaseFonts(level)) {
			vAtts.push_back(atr_IncludeBaseFonts);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeCIDFonts(level)) {
			vAtts.push_back(atr_IncludeCIDFonts);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeEmbeddedFonts(level)) {
			vAtts.push_back(atr_IncludeEmbeddedFonts);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeOtherResources(level)) {
			vAtts.push_back(atr_IncludeOtherResources);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeProcSets(level)) {
			vAtts.push_back(atr_IncludeProcSets);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeTrueTypeFonts(level)) {
			vAtts.push_back(atr_IncludeTrueTypeFonts);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeType1Fonts(level)) {
			vAtts.push_back(atr_IncludeType1Fonts);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeType3Fonts(level)) {
			vAtts.push_back(atr_IncludeType3Fonts);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutputType(level)) {
			vAtts.push_back(atr_OutputType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPSLevel(level)) {
			vAtts.push_back(atr_PSLevel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScale(level)) {
			vAtts.push_back(atr_Scale);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetPageSize(level)) {
			vAtts.push_back(atr_SetPageSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetupProcsets(level)) {
			vAtts.push_back(atr_SetupProcsets);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShrinkToFit(level)) {
			vAtts.push_back(atr_ShrinkToFit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSuppressCenter(level)) {
			vAtts.push_back(atr_SuppressCenter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSuppressRotate(level)) {
			vAtts.push_back(atr_SuppressRotate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTTasT42(level)) {
			vAtts.push_back(atr_TTasT42);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUseFontAliasNames(level)) {
			vAtts.push_back(atr_UseFontAliasNames);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreDeviceExtGState(level)) {
			vAtts.push_back(atr_IgnoreDeviceExtGState);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBoundingBox(level)) {
			vAtts.push_back(atr_BoundingBox);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BinaryOK
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetBinaryOK(bool value){
	SetAttribute(atr_BinaryOK,WString::valueOf(value));
};
/**
* Get bool attribute BinaryOK
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFToPSConversionParams::GetBinaryOK() const {return GetBoolAttribute(atr_BinaryOK,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidBinaryOK(EnumValidationLevel level) const {
		return ValidAttribute(atr_BinaryOK,AttributeType_boolean,false);
	};
/**
* Set attribute CenterCropBox
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetCenterCropBox(bool value){
	SetAttribute(atr_CenterCropBox,WString::valueOf(value));
};
/**
* Get bool attribute CenterCropBox
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFToPSConversionParams::GetCenterCropBox() const {return GetBoolAttribute(atr_CenterCropBox,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidCenterCropBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_CenterCropBox,AttributeType_boolean,false);
	};
/**
* Set attribute GeneratePageStreams
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetGeneratePageStreams(bool value){
	SetAttribute(atr_GeneratePageStreams,WString::valueOf(value));
};
/**
* Get bool attribute GeneratePageStreams
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetGeneratePageStreams() const {return GetBoolAttribute(atr_GeneratePageStreams,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidGeneratePageStreams(EnumValidationLevel level) const {
		return ValidAttribute(atr_GeneratePageStreams,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreAnnotForms
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreAnnotForms(bool value){
	SetAttribute(atr_IgnoreAnnotForms,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreAnnotForms
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreAnnotForms() const {return GetBoolAttribute(atr_IgnoreAnnotForms,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreAnnotForms(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreAnnotForms,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreBG
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreBG(bool value){
	SetAttribute(atr_IgnoreBG,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreBG
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreBG() const {return GetBoolAttribute(atr_IgnoreBG,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreBG(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreBG,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreColorSeps
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreColorSeps(bool value){
	SetAttribute(atr_IgnoreColorSeps,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreColorSeps
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreColorSeps() const {return GetBoolAttribute(atr_IgnoreColorSeps,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreColorSeps(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreColorSeps,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreDSC
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreDSC(bool value){
	SetAttribute(atr_IgnoreDSC,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreDSC
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreDSC() const {return GetBoolAttribute(atr_IgnoreDSC,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreDSC(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreDSC,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreExternStreamRef
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreExternStreamRef(bool value){
	SetAttribute(atr_IgnoreExternStreamRef,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreExternStreamRef
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreExternStreamRef() const {return GetBoolAttribute(atr_IgnoreExternStreamRef,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreExternStreamRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreExternStreamRef,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreHalftones
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreHalftones(bool value){
	SetAttribute(atr_IgnoreHalftones,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreHalftones
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreHalftones() const {return GetBoolAttribute(atr_IgnoreHalftones,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreHalftones(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreHalftones,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreOverprint
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreOverprint(bool value){
	SetAttribute(atr_IgnoreOverprint,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreOverprint
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreOverprint() const {return GetBoolAttribute(atr_IgnoreOverprint,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreOverprint(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreOverprint,AttributeType_boolean,false);
	};
/**
* Set attribute IgnorePageRotation
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnorePageRotation(bool value){
	SetAttribute(atr_IgnorePageRotation,WString::valueOf(value));
};
/**
* Get bool attribute IgnorePageRotation
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnorePageRotation() const {return GetBoolAttribute(atr_IgnorePageRotation,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnorePageRotation(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnorePageRotation,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreRawData
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreRawData(bool value){
	SetAttribute(atr_IgnoreRawData,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreRawData
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreRawData() const {return GetBoolAttribute(atr_IgnoreRawData,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreRawData(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreRawData,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreSeparableImagesOnly
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreSeparableImagesOnly(bool value){
	SetAttribute(atr_IgnoreSeparableImagesOnly,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreSeparableImagesOnly
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreSeparableImagesOnly() const {return GetBoolAttribute(atr_IgnoreSeparableImagesOnly,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreSeparableImagesOnly(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreSeparableImagesOnly,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreShowPage
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreShowPage(bool value){
	SetAttribute(atr_IgnoreShowPage,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreShowPage
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreShowPage() const {return GetBoolAttribute(atr_IgnoreShowPage,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreShowPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreShowPage,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreTransfers
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreTransfers(bool value){
	SetAttribute(atr_IgnoreTransfers,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreTransfers
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreTransfers() const {return GetBoolAttribute(atr_IgnoreTransfers,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreTransfers(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreTransfers,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreTTFontsFirst
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreTTFontsFirst(bool value){
	SetAttribute(atr_IgnoreTTFontsFirst,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreTTFontsFirst
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreTTFontsFirst() const {return GetBoolAttribute(atr_IgnoreTTFontsFirst,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreTTFontsFirst(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreTTFontsFirst,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreUCR
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreUCR(bool value){
	SetAttribute(atr_IgnoreUCR,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreUCR
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreUCR() const {return GetBoolAttribute(atr_IgnoreUCR,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreUCR(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreUCR,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::IncludeBaseFontsString(){
		static const WString enums=WString(L"Unknown,IncludeNever,IncludeOncePerDoc,IncludeOncePerPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::IncludeBaseFontsString(EnumIncludeBaseFonts value){
		return IncludeBaseFontsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetIncludeBaseFonts( EnumIncludeBaseFonts value){
	SetEnumAttribute(atr_IncludeBaseFonts,value,IncludeBaseFontsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumIncludeBaseFonts JDFAutoPDFToPSConversionParams:: GetIncludeBaseFonts() const {
	return (EnumIncludeBaseFonts) GetEnumAttribute(atr_IncludeBaseFonts,IncludeBaseFontsString(),WString::emptyStr,IncludeBaseFonts_IncludeNever);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIncludeBaseFonts(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeBaseFonts,IncludeBaseFontsString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::IncludeCIDFontsString(){
		static const WString enums=WString(L"Unknown,IncludeNever,IncludeOncePerDoc,IncludeOncePerPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::IncludeCIDFontsString(EnumIncludeCIDFonts value){
		return IncludeCIDFontsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetIncludeCIDFonts( EnumIncludeCIDFonts value){
	SetEnumAttribute(atr_IncludeCIDFonts,value,IncludeCIDFontsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumIncludeCIDFonts JDFAutoPDFToPSConversionParams:: GetIncludeCIDFonts() const {
	return (EnumIncludeCIDFonts) GetEnumAttribute(atr_IncludeCIDFonts,IncludeCIDFontsString(),WString::emptyStr,IncludeCIDFonts_IncludeOncePerDoc);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIncludeCIDFonts(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeCIDFonts,IncludeCIDFontsString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::IncludeEmbeddedFontsString(){
		static const WString enums=WString(L"Unknown,IncludeNever,IncludeOncePerDoc,IncludeOncePerPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::IncludeEmbeddedFontsString(EnumIncludeEmbeddedFonts value){
		return IncludeEmbeddedFontsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetIncludeEmbeddedFonts( EnumIncludeEmbeddedFonts value){
	SetEnumAttribute(atr_IncludeEmbeddedFonts,value,IncludeEmbeddedFontsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumIncludeEmbeddedFonts JDFAutoPDFToPSConversionParams:: GetIncludeEmbeddedFonts() const {
	return (EnumIncludeEmbeddedFonts) GetEnumAttribute(atr_IncludeEmbeddedFonts,IncludeEmbeddedFontsString(),WString::emptyStr,IncludeEmbeddedFonts_IncludeOncePerDoc);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIncludeEmbeddedFonts(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeEmbeddedFonts,IncludeEmbeddedFontsString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::IncludeOtherResourcesString(){
		static const WString enums=WString(L"Unknown,IncludeNever,IncludeOncePerDoc,IncludeOncePerPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::IncludeOtherResourcesString(EnumIncludeOtherResources value){
		return IncludeOtherResourcesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetIncludeOtherResources( EnumIncludeOtherResources value){
	SetEnumAttribute(atr_IncludeOtherResources,value,IncludeOtherResourcesString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumIncludeOtherResources JDFAutoPDFToPSConversionParams:: GetIncludeOtherResources() const {
	return (EnumIncludeOtherResources) GetEnumAttribute(atr_IncludeOtherResources,IncludeOtherResourcesString(),WString::emptyStr,IncludeOtherResources_IncludeOncePerDoc);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIncludeOtherResources(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeOtherResources,IncludeOtherResourcesString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::IncludeProcSetsString(){
		static const WString enums=WString(L"Unknown,IncludeNever,IncludeOncePerDoc,IncludeOncePerPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::IncludeProcSetsString(EnumIncludeProcSets value){
		return IncludeProcSetsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetIncludeProcSets( EnumIncludeProcSets value){
	SetEnumAttribute(atr_IncludeProcSets,value,IncludeProcSetsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumIncludeProcSets JDFAutoPDFToPSConversionParams:: GetIncludeProcSets() const {
	return (EnumIncludeProcSets) GetEnumAttribute(atr_IncludeProcSets,IncludeProcSetsString(),WString::emptyStr,IncludeProcSets_IncludeOncePerDoc);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIncludeProcSets(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeProcSets,IncludeProcSetsString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::IncludeTrueTypeFontsString(){
		static const WString enums=WString(L"Unknown,IncludeNever,IncludeOncePerDoc,IncludeOncePerPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::IncludeTrueTypeFontsString(EnumIncludeTrueTypeFonts value){
		return IncludeTrueTypeFontsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetIncludeTrueTypeFonts( EnumIncludeTrueTypeFonts value){
	SetEnumAttribute(atr_IncludeTrueTypeFonts,value,IncludeTrueTypeFontsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumIncludeTrueTypeFonts JDFAutoPDFToPSConversionParams:: GetIncludeTrueTypeFonts() const {
	return (EnumIncludeTrueTypeFonts) GetEnumAttribute(atr_IncludeTrueTypeFonts,IncludeTrueTypeFontsString(),WString::emptyStr,IncludeTrueTypeFonts_IncludeOncePerDoc);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIncludeTrueTypeFonts(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeTrueTypeFonts,IncludeTrueTypeFontsString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::IncludeType1FontsString(){
		static const WString enums=WString(L"Unknown,IncludeNever,IncludeOncePerDoc,IncludeOncePerPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::IncludeType1FontsString(EnumIncludeType1Fonts value){
		return IncludeType1FontsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetIncludeType1Fonts( EnumIncludeType1Fonts value){
	SetEnumAttribute(atr_IncludeType1Fonts,value,IncludeType1FontsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumIncludeType1Fonts JDFAutoPDFToPSConversionParams:: GetIncludeType1Fonts() const {
	return (EnumIncludeType1Fonts) GetEnumAttribute(atr_IncludeType1Fonts,IncludeType1FontsString(),WString::emptyStr,IncludeType1Fonts_IncludeOncePerDoc);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIncludeType1Fonts(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeType1Fonts,IncludeType1FontsString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::IncludeType3FontsString(){
		static const WString enums=WString(L"Unknown,IncludeNever,IncludeOncePerDoc,IncludeOncePerPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::IncludeType3FontsString(EnumIncludeType3Fonts value){
		return IncludeType3FontsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetIncludeType3Fonts( EnumIncludeType3Fonts value){
	SetEnumAttribute(atr_IncludeType3Fonts,value,IncludeType3FontsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumIncludeType3Fonts JDFAutoPDFToPSConversionParams:: GetIncludeType3Fonts() const {
	return (EnumIncludeType3Fonts) GetEnumAttribute(atr_IncludeType3Fonts,IncludeType3FontsString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIncludeType3Fonts(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeType3Fonts,IncludeType3FontsString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFToPSConversionParams::OutputTypeString(){
		static const WString enums=WString(L"Unknown,PostScript,EPS");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFToPSConversionParams::OutputTypeString(EnumOutputType value){
		return OutputTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFToPSConversionParams::SetOutputType( EnumOutputType value){
	SetEnumAttribute(atr_OutputType,value,OutputTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFToPSConversionParams::EnumOutputType JDFAutoPDFToPSConversionParams:: GetOutputType() const {
	return (EnumOutputType) GetEnumAttribute(atr_OutputType,OutputTypeString(),WString::emptyStr,OutputType_PostScript);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidOutputType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_OutputType,OutputTypeString(),false);
	};
/**
* Set attribute PSLevel
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetPSLevel(int value){
	SetAttribute(atr_PSLevel,WString::valueOf(value));
};
/**
* Get integer attribute PSLevel
* @return int the vaue of the attribute ; defaults to 2
*/
	 int JDFAutoPDFToPSConversionParams::GetPSLevel() const {
	return GetIntAttribute(atr_PSLevel,WString::emptyStr,2);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidPSLevel(EnumValidationLevel level) const {
		return ValidAttribute(atr_PSLevel,AttributeType_integer,false);
	};
/**
* Set attribute Scale
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetScale(double value){
	SetAttribute(atr_Scale,WString::valueOf(value));
};
/**
* Get double attribute Scale
* @return double the vaue of the attribute ; defaults to 100
*/
	 double JDFAutoPDFToPSConversionParams::GetScale() const {
	return GetRealAttribute(atr_Scale,WString::emptyStr,100);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidScale(EnumValidationLevel level) const {
		return ValidAttribute(atr_Scale,AttributeType_double,false);
	};
/**
* Set attribute SetPageSize
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetSetPageSize(bool value){
	SetAttribute(atr_SetPageSize,WString::valueOf(value));
};
/**
* Get bool attribute SetPageSize
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetSetPageSize() const {return GetBoolAttribute(atr_SetPageSize,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidSetPageSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetPageSize,AttributeType_boolean,false);
	};
/**
* Set attribute SetupProcsets
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetSetupProcsets(bool value){
	SetAttribute(atr_SetupProcsets,WString::valueOf(value));
};
/**
* Get bool attribute SetupProcsets
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFToPSConversionParams::GetSetupProcsets() const {return GetBoolAttribute(atr_SetupProcsets,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidSetupProcsets(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetupProcsets,AttributeType_boolean,false);
	};
/**
* Set attribute ShrinkToFit
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetShrinkToFit(bool value){
	SetAttribute(atr_ShrinkToFit,WString::valueOf(value));
};
/**
* Get bool attribute ShrinkToFit
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetShrinkToFit() const {return GetBoolAttribute(atr_ShrinkToFit,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidShrinkToFit(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShrinkToFit,AttributeType_boolean,false);
	};
/**
* Set attribute SuppressCenter
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetSuppressCenter(bool value){
	SetAttribute(atr_SuppressCenter,WString::valueOf(value));
};
/**
* Get bool attribute SuppressCenter
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetSuppressCenter() const {return GetBoolAttribute(atr_SuppressCenter,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidSuppressCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_SuppressCenter,AttributeType_boolean,false);
	};
/**
* Set attribute SuppressRotate
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetSuppressRotate(bool value){
	SetAttribute(atr_SuppressRotate,WString::valueOf(value));
};
/**
* Get bool attribute SuppressRotate
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetSuppressRotate() const {return GetBoolAttribute(atr_SuppressRotate,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidSuppressRotate(EnumValidationLevel level) const {
		return ValidAttribute(atr_SuppressRotate,AttributeType_boolean,false);
	};
/**
* Set attribute TTasT42
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetTTasT42(bool value){
	SetAttribute(atr_TTasT42,WString::valueOf(value));
};
/**
* Get bool attribute TTasT42
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetTTasT42() const {return GetBoolAttribute(atr_TTasT42,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidTTasT42(EnumValidationLevel level) const {
		return ValidAttribute(atr_TTasT42,AttributeType_boolean,false);
	};
/**
* Set attribute UseFontAliasNames
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetUseFontAliasNames(bool value){
	SetAttribute(atr_UseFontAliasNames,WString::valueOf(value));
};
/**
* Get bool attribute UseFontAliasNames
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFToPSConversionParams::GetUseFontAliasNames() const {return GetBoolAttribute(atr_UseFontAliasNames,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidUseFontAliasNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_UseFontAliasNames,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreDeviceExtGState
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetIgnoreDeviceExtGState(bool value){
	SetAttribute(atr_IgnoreDeviceExtGState,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreDeviceExtGState
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPDFToPSConversionParams::GetIgnoreDeviceExtGState() const {return GetBoolAttribute(atr_IgnoreDeviceExtGState,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidIgnoreDeviceExtGState(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreDeviceExtGState,AttributeType_boolean,false);
	};
/**
* Set attribute BoundingBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPDFToPSConversionParams::SetBoundingBox(const JDFRectangle& value){
	SetAttribute(atr_BoundingBox,value);
};
/**
* Get string attribute BoundingBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPDFToPSConversionParams::GetBoundingBox() const {
	return GetAttribute(atr_BoundingBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFToPSConversionParams::ValidBoundingBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_BoundingBox,AttributeType_rectangle,false);
	};
}; // end namespace JDF
