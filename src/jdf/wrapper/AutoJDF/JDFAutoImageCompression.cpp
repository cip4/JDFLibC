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

 
#include "jdf/wrapper/AutoJDF/JDFAutoImageCompression.h"
#include "jdf/wrapper/JDFCCITTFaxParams.h"
#include "jdf/wrapper/JDFDCTParams.h"
#include "jdf/wrapper/JDFJBIG2Params.h"
#include "jdf/wrapper/JDFJPEG2000Params.h"
#include "jdf/wrapper/JDFLZWParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoImageCompression : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoImageCompression& JDFAutoImageCompression::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoImageCompression: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoImageCompression::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoImageCompression::ValidNodeNames()const{
	return L"*:,ImageCompression";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoImageCompression::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ImageType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoImageCompression::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AntiAliasImages,AutoFilterImages,ConvertImagesToIndexed,DCTQuality,DownsampleImages,EncodeColorImages,EncodeImages,ImageAutoFilterStrategy,ImageDepth,ImageDownsampleThreshold,ImageDownsampleType,ImageFilter,ImageResolution,JPXQuality");
};

/**
 typesafe validator
*/
	vWString JDFAutoImageCompression::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAntiAliasImages(level)) {
			vAtts.push_back(atr_AntiAliasImages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAutoFilterImages(level)) {
			vAtts.push_back(atr_AutoFilterImages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidConvertImagesToIndexed(level)) {
			vAtts.push_back(atr_ConvertImagesToIndexed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDCTQuality(level)) {
			vAtts.push_back(atr_DCTQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDownsampleImages(level)) {
			vAtts.push_back(atr_DownsampleImages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncodeColorImages(level)) {
			vAtts.push_back(atr_EncodeColorImages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncodeImages(level)) {
			vAtts.push_back(atr_EncodeImages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageAutoFilterStrategy(level)) {
			vAtts.push_back(atr_ImageAutoFilterStrategy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageDepth(level)) {
			vAtts.push_back(atr_ImageDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageDownsampleThreshold(level)) {
			vAtts.push_back(atr_ImageDownsampleThreshold);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageDownsampleType(level)) {
			vAtts.push_back(atr_ImageDownsampleType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageFilter(level)) {
			vAtts.push_back(atr_ImageFilter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageResolution(level)) {
			vAtts.push_back(atr_ImageResolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageType(level)) {
			vAtts.push_back(atr_ImageType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJPXQuality(level)) {
			vAtts.push_back(atr_JPXQuality);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AntiAliasImages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetAntiAliasImages(bool value){
	SetAttribute(atr_AntiAliasImages,WString::valueOf(value));
};
/**
* Get bool attribute AntiAliasImages
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoImageCompression::GetAntiAliasImages() const {return GetBoolAttribute(atr_AntiAliasImages,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidAntiAliasImages(EnumValidationLevel level) const {
		return ValidAttribute(atr_AntiAliasImages,AttributeType_boolean,false);
	};
/**
* Set attribute AutoFilterImages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetAutoFilterImages(bool value){
	SetAttribute(atr_AutoFilterImages,WString::valueOf(value));
};
/**
* Get bool attribute AutoFilterImages
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoImageCompression::GetAutoFilterImages() const {return GetBoolAttribute(atr_AutoFilterImages,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidAutoFilterImages(EnumValidationLevel level) const {
		return ValidAttribute(atr_AutoFilterImages,AttributeType_boolean,false);
	};
/**
* Set attribute ConvertImagesToIndexed
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetConvertImagesToIndexed(bool value){
	SetAttribute(atr_ConvertImagesToIndexed,WString::valueOf(value));
};
/**
* Get bool attribute ConvertImagesToIndexed
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoImageCompression::GetConvertImagesToIndexed() const {return GetBoolAttribute(atr_ConvertImagesToIndexed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidConvertImagesToIndexed(EnumValidationLevel level) const {
		return ValidAttribute(atr_ConvertImagesToIndexed,AttributeType_boolean,false);
	};
/**
* Set attribute DCTQuality
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetDCTQuality(double value){
	SetAttribute(atr_DCTQuality,WString::valueOf(value));
};
/**
* Get double attribute DCTQuality
* @return double the vaue of the attribute ; defaults to 0
*/
	 double JDFAutoImageCompression::GetDCTQuality() const {
	return GetRealAttribute(atr_DCTQuality,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidDCTQuality(EnumValidationLevel level) const {
		return ValidAttribute(atr_DCTQuality,AttributeType_double,false);
	};
/**
* Set attribute DownsampleImages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetDownsampleImages(bool value){
	SetAttribute(atr_DownsampleImages,WString::valueOf(value));
};
/**
* Get bool attribute DownsampleImages
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoImageCompression::GetDownsampleImages() const {return GetBoolAttribute(atr_DownsampleImages,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidDownsampleImages(EnumValidationLevel level) const {
		return ValidAttribute(atr_DownsampleImages,AttributeType_boolean,false);
	};
/**
* Set attribute EncodeColorImages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetEncodeColorImages(bool value){
	SetAttribute(atr_EncodeColorImages,WString::valueOf(value));
};
/**
* Get bool attribute EncodeColorImages
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoImageCompression::GetEncodeColorImages() const {return GetBoolAttribute(atr_EncodeColorImages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidEncodeColorImages(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncodeColorImages,AttributeType_boolean,false);
	};
/**
* Set attribute EncodeImages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetEncodeImages(bool value){
	SetAttribute(atr_EncodeImages,WString::valueOf(value));
};
/**
* Get bool attribute EncodeImages
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoImageCompression::GetEncodeImages() const {return GetBoolAttribute(atr_EncodeImages,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidEncodeImages(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncodeImages,AttributeType_boolean,false);
	};
/**
* Set attribute ImageAutoFilterStrategy
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetImageAutoFilterStrategy(const WString& value){
	SetAttribute(atr_ImageAutoFilterStrategy,value);
};
/**
* Get string attribute ImageAutoFilterStrategy
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoImageCompression::GetImageAutoFilterStrategy() const {
	return GetAttribute(atr_ImageAutoFilterStrategy,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidImageAutoFilterStrategy(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageAutoFilterStrategy,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ImageDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetImageDepth(int value){
	SetAttribute(atr_ImageDepth,WString::valueOf(value));
};
/**
* Get integer attribute ImageDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoImageCompression::GetImageDepth() const {
	return GetIntAttribute(atr_ImageDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidImageDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageDepth,AttributeType_integer,false);
	};
/**
* Set attribute ImageDownsampleThreshold
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetImageDownsampleThreshold(double value){
	SetAttribute(atr_ImageDownsampleThreshold,WString::valueOf(value));
};
/**
* Get double attribute ImageDownsampleThreshold
* @return double the vaue of the attribute ; defaults to 2.0
*/
	 double JDFAutoImageCompression::GetImageDownsampleThreshold() const {
	return GetRealAttribute(atr_ImageDownsampleThreshold,WString::emptyStr,2.0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidImageDownsampleThreshold(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageDownsampleThreshold,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageCompression::ImageDownsampleTypeString(){
		static const WString enums=WString(L"Unknown,Average,Bicubic,Subsample");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageCompression::ImageDownsampleTypeString(EnumImageDownsampleType value){
		return ImageDownsampleTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageCompression::SetImageDownsampleType( EnumImageDownsampleType value){
	SetEnumAttribute(atr_ImageDownsampleType,value,ImageDownsampleTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageCompression::EnumImageDownsampleType JDFAutoImageCompression:: GetImageDownsampleType() const {
	return (EnumImageDownsampleType) GetEnumAttribute(atr_ImageDownsampleType,ImageDownsampleTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidImageDownsampleType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ImageDownsampleType,ImageDownsampleTypeString(),false);
	};
/**
* Set attribute ImageFilter
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetImageFilter(const WString& value){
	SetAttribute(atr_ImageFilter,value);
};
/**
* Get string attribute ImageFilter
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoImageCompression::GetImageFilter() const {
	return GetAttribute(atr_ImageFilter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidImageFilter(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageFilter,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ImageResolution
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetImageResolution(double value){
	SetAttribute(atr_ImageResolution,WString::valueOf(value));
};
/**
* Get double attribute ImageResolution
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageCompression::GetImageResolution() const {
	return GetRealAttribute(atr_ImageResolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidImageResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageResolution,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageCompression::ImageTypeString(){
		static const WString enums=WString(L"Unknown,Color,Grayscale,Monochrome");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageCompression::ImageTypeString(EnumImageType value){
		return ImageTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageCompression::SetImageType( EnumImageType value){
	SetEnumAttribute(atr_ImageType,value,ImageTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageCompression::EnumImageType JDFAutoImageCompression:: GetImageType() const {
	return (EnumImageType) GetEnumAttribute(atr_ImageType,ImageTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidImageType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ImageType,ImageTypeString(),RequiredLevel(level));
	};
/**
* Set attribute JPXQuality
*@param int value: the value to set the attribute to
*/
	 void JDFAutoImageCompression::SetJPXQuality(int value){
	SetAttribute(atr_JPXQuality,WString::valueOf(value));
};
/**
* Get integer attribute JPXQuality
* @return int the vaue of the attribute 
*/
	 int JDFAutoImageCompression::GetJPXQuality() const {
	return GetIntAttribute(atr_JPXQuality,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageCompression::ValidJPXQuality(EnumValidationLevel level) const {
		return ValidAttribute(atr_JPXQuality,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCCITTFaxParams JDFAutoImageCompression::GetCCITTFaxParams(int iSkip)const{
	JDFCCITTFaxParams e=GetElement(elm_CCITTFaxParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCCITTFaxParams JDFAutoImageCompression::GetCreateCCITTFaxParams(int iSkip){
	JDFCCITTFaxParams e=GetCreateElement(elm_CCITTFaxParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCCITTFaxParams JDFAutoImageCompression::AppendCCITTFaxParams(){
	JDFCCITTFaxParams e=AppendElement(elm_CCITTFaxParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDCTParams JDFAutoImageCompression::GetDCTParams(int iSkip)const{
	JDFDCTParams e=GetElement(elm_DCTParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDCTParams JDFAutoImageCompression::GetCreateDCTParams(int iSkip){
	JDFDCTParams e=GetCreateElement(elm_DCTParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDCTParams JDFAutoImageCompression::AppendDCTParams(){
	JDFDCTParams e=AppendElement(elm_DCTParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJBIG2Params JDFAutoImageCompression::GetJBIG2Params(int iSkip)const{
	JDFJBIG2Params e=GetElement(elm_JBIG2Params,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJBIG2Params JDFAutoImageCompression::GetCreateJBIG2Params(int iSkip){
	JDFJBIG2Params e=GetCreateElement(elm_JBIG2Params,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJBIG2Params JDFAutoImageCompression::AppendJBIG2Params(){
	JDFJBIG2Params e=AppendElement(elm_JBIG2Params);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJPEG2000Params JDFAutoImageCompression::GetJPEG2000Params(int iSkip)const{
	JDFJPEG2000Params e=GetElement(elm_JPEG2000Params,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJPEG2000Params JDFAutoImageCompression::GetCreateJPEG2000Params(int iSkip){
	JDFJPEG2000Params e=GetCreateElement(elm_JPEG2000Params,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJPEG2000Params JDFAutoImageCompression::AppendJPEG2000Params(){
	JDFJPEG2000Params e=AppendElement(elm_JPEG2000Params);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLZWParams JDFAutoImageCompression::GetLZWParams(int iSkip)const{
	JDFLZWParams e=GetElement(elm_LZWParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLZWParams JDFAutoImageCompression::GetCreateLZWParams(int iSkip){
	JDFLZWParams e=GetCreateElement(elm_LZWParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLZWParams JDFAutoImageCompression::AppendLZWParams(){
	JDFLZWParams e=AppendElement(elm_LZWParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoImageCompression::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CCITTFaxParams);

		for(i=0;i<nElem;i++){
			if (!GetCCITTFaxParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_CCITTFaxParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DCTParams);

		for(i=0;i<nElem;i++){
			if (!GetDCTParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_DCTParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_JBIG2Params);

		for(i=0;i<nElem;i++){
			if (!GetJBIG2Params(i).IsValid(level)) {
				vElem.AppendUnique(elm_JBIG2Params);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_JPEG2000Params);

		for(i=0;i<nElem;i++){
			if (!GetJPEG2000Params(i).IsValid(level)) {
				vElem.AppendUnique(elm_JPEG2000Params);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_LZWParams);

		for(i=0;i<nElem;i++){
			if (!GetLZWParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_LZWParams);
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
	WString JDFAutoImageCompression::OptionalElements()const{
		return JDFElement::OptionalElements()+L",CCITTFaxParams,DCTParams,JBIG2Params,JPEG2000Params,LZWParams";
	};
}; // end namespace JDF
