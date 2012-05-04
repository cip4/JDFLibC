/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2012 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColorSpaceConversionOp.h"
#include "jdf/wrapper/JDFDeviceNSpace.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorSpaceConversionOp : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColorSpaceConversionOp& JDFAutoColorSpaceConversionOp::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColorSpaceConversionOp: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColorSpaceConversionOp::ValidNodeNames()const{
	return L"*:,ColorSpaceConversionOp";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoColorSpaceConversionOp::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PreserveBlack,RenderingIntent,RGBGray2Black,RGBGray2BlackThreshold,SourceObjects,IgnoreEmbeddedICC,ObjectTags,Operation,SourceCS,SourceRenderingIntent");
};

/**
 typesafe validator
*/
	vWString JDFAutoColorSpaceConversionOp::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPreserveBlack(level)) {
			vAtts.push_back(atr_PreserveBlack);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRenderingIntent(level)) {
			vAtts.push_back(atr_RenderingIntent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRGBGray2Black(level)) {
			vAtts.push_back(atr_RGBGray2Black);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRGBGray2BlackThreshold(level)) {
			vAtts.push_back(atr_RGBGray2BlackThreshold);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceObjects(level)) {
			vAtts.push_back(atr_SourceObjects);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreEmbeddedICC(level)) {
			vAtts.push_back(atr_IgnoreEmbeddedICC);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidObjectTags(level)) {
			vAtts.push_back(atr_ObjectTags);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOperation(level)) {
			vAtts.push_back(atr_Operation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceCS(level)) {
			vAtts.push_back(atr_SourceCS);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceRenderingIntent(level)) {
			vAtts.push_back(atr_SourceRenderingIntent);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PreserveBlack
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoColorSpaceConversionOp::SetPreserveBlack(bool value){
	SetAttribute(atr_PreserveBlack,WString::valueOf(value));
};
/**
* Get bool attribute PreserveBlack
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoColorSpaceConversionOp::GetPreserveBlack() const {return GetBoolAttribute(atr_PreserveBlack,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidPreserveBlack(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreserveBlack,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorSpaceConversionOp::RenderingIntentString(){
		static const WString enums=WString(L"Unknown,ColorSpaceDependent,Perceptual,Saturation,RelativeColorimetric,AbsoluteColorimetric");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorSpaceConversionOp::RenderingIntentString(EnumRenderingIntent value){
		return RenderingIntentString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorSpaceConversionOp::SetRenderingIntent( EnumRenderingIntent value){
	SetEnumAttribute(atr_RenderingIntent,value,RenderingIntentString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorSpaceConversionOp::EnumRenderingIntent JDFAutoColorSpaceConversionOp:: GetRenderingIntent() const {
	return (EnumRenderingIntent) GetEnumAttribute(atr_RenderingIntent,RenderingIntentString(),WString::emptyStr,RenderingIntent_ColorSpaceDependent);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidRenderingIntent(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_RenderingIntent,RenderingIntentString(),false);
	};
/**
* Set attribute RGBGray2Black
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoColorSpaceConversionOp::SetRGBGray2Black(bool value){
	SetAttribute(atr_RGBGray2Black,WString::valueOf(value));
};
/**
* Get bool attribute RGBGray2Black
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoColorSpaceConversionOp::GetRGBGray2Black() const {return GetBoolAttribute(atr_RGBGray2Black,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidRGBGray2Black(EnumValidationLevel level) const {
		return ValidAttribute(atr_RGBGray2Black,AttributeType_boolean,false);
	};
/**
* Set attribute RGBGray2BlackThreshold
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorSpaceConversionOp::SetRGBGray2BlackThreshold(double value){
	SetAttribute(atr_RGBGray2BlackThreshold,WString::valueOf(value));
};
/**
* Get double attribute RGBGray2BlackThreshold
* @return double the vaue of the attribute ; defaults to 1
*/
	 double JDFAutoColorSpaceConversionOp::GetRGBGray2BlackThreshold() const {
	return GetRealAttribute(atr_RGBGray2BlackThreshold,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidRGBGray2BlackThreshold(EnumValidationLevel level) const {
		return ValidAttribute(atr_RGBGray2BlackThreshold,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorSpaceConversionOp::SourceObjectsString(){
		static const WString enums=WString(L"Unknown,All,ImagePhotographic,ImageScreenShot,Text,LineArt,SmoothShades");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorSpaceConversionOp::SourceObjectsString(EnumSourceObjects value){
		return SourceObjectsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoColorSpaceConversionOp::AddSourceObjects( EnumSourceObjects value){
	return AddEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoColorSpaceConversionOp::RemoveSourceObjects( EnumSourceObjects value){
	return RemoveEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoColorSpaceConversionOp::GetSourceObjects() const {
	return GetEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),WString::emptyStr,(unsigned int)SourceObjects_All);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorSpaceConversionOp::SetSourceObjects( EnumSourceObjects value){
	SetEnumAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorSpaceConversionOp::SetSourceObjects( const vint& value){
	SetEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/**
* Typesafe attribute validation of SourceObjects
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidSourceObjects(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),false);
	};
/**
* Set attribute IgnoreEmbeddedICC
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoColorSpaceConversionOp::SetIgnoreEmbeddedICC(bool value){
	SetAttribute(atr_IgnoreEmbeddedICC,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreEmbeddedICC
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoColorSpaceConversionOp::GetIgnoreEmbeddedICC() const {return GetBoolAttribute(atr_IgnoreEmbeddedICC,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidIgnoreEmbeddedICC(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreEmbeddedICC,AttributeType_boolean,false);
	};
/**
* Set attribute ObjectTags
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoColorSpaceConversionOp::SetObjectTags(const vWString& value){
	SetAttribute(atr_ObjectTags,value);
};
/**
* Get string attribute ObjectTags
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoColorSpaceConversionOp::GetObjectTags() const {
	return GetAttribute(atr_ObjectTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidObjectTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_ObjectTags,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorSpaceConversionOp::OperationString(){
		static const WString enums=WString(L"Unknown,Convert,Tag,Untag,Retag,ConvertIgnore");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorSpaceConversionOp::OperationString(EnumOperation value){
		return OperationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorSpaceConversionOp::SetOperation( EnumOperation value){
	SetEnumAttribute(atr_Operation,value,OperationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorSpaceConversionOp::EnumOperation JDFAutoColorSpaceConversionOp:: GetOperation() const {
	return (EnumOperation) GetEnumAttribute(atr_Operation,OperationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidOperation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Operation,OperationString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorSpaceConversionOp::SourceCSString(){
		static const WString enums=WString(L"Unknown,CalGray,CalRGB,Calibrated,CIEBased,CMYK,DeviceN,DevIndep,RGB,Gray")
	+WString(L",ICCBased,ICCCMYK,ICCGray,ICCLAB,ICCRGB,Lab,Separation,YUV,All");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorSpaceConversionOp::SourceCSString(EnumSourceCS value){
		return SourceCSString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorSpaceConversionOp::SetSourceCS( EnumSourceCS value){
	SetEnumAttribute(atr_SourceCS,value,SourceCSString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorSpaceConversionOp::EnumSourceCS JDFAutoColorSpaceConversionOp:: GetSourceCS() const {
	return (EnumSourceCS) GetEnumAttribute(atr_SourceCS,SourceCSString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidSourceCS(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SourceCS,SourceCSString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorSpaceConversionOp::SourceRenderingIntentString(){
		static const WString enums=WString(L"Unknown,ColorSpaceDependent,Perceptual,Saturation,RelativeColorimetric,AbsoluteColorimetric");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorSpaceConversionOp::SourceRenderingIntentString(EnumSourceRenderingIntent value){
		return SourceRenderingIntentString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorSpaceConversionOp::SetSourceRenderingIntent( EnumSourceRenderingIntent value){
	SetEnumAttribute(atr_SourceRenderingIntent,value,SourceRenderingIntentString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorSpaceConversionOp::EnumSourceRenderingIntent JDFAutoColorSpaceConversionOp:: GetSourceRenderingIntent() const {
	return (EnumSourceRenderingIntent) GetEnumAttribute(atr_SourceRenderingIntent,SourceRenderingIntentString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionOp::ValidSourceRenderingIntent(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SourceRenderingIntent,SourceRenderingIntentString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDeviceNSpace JDFAutoColorSpaceConversionOp::GetDeviceNSpace(int iSkip)const{
	JDFDeviceNSpace e=GetElement(elm_DeviceNSpace,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNSpace JDFAutoColorSpaceConversionOp::GetCreateDeviceNSpace(int iSkip){
	JDFDeviceNSpace e=GetCreateElement(elm_DeviceNSpace,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNSpace JDFAutoColorSpaceConversionOp::AppendDeviceNSpace(){
	JDFDeviceNSpace e=AppendElement(elm_DeviceNSpace);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorSpaceConversionOp::RefDeviceNSpace(JDFDeviceNSpace& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColorSpaceConversionOp::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColorSpaceConversionOp::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColorSpaceConversionOp::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorSpaceConversionOp::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoColorSpaceConversionOp::GetSeparationSpec(int iSkip)const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoColorSpaceConversionOp::GetCreateSeparationSpec(int iSkip){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoColorSpaceConversionOp::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoColorSpaceConversionOp::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoColorSpaceConversionOp::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoColorSpaceConversionOp::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorSpaceConversionOp::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoColorSpaceConversionOp::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_DeviceNSpace);

		for(i=0;i<nElem;i++){
			if (!GetDeviceNSpace(i).IsValid(level)) {
				vElem.AppendUnique(elm_DeviceNSpace);
				if (++n>=nMax)
					return vElem;
				break;
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
		nElem=NumChildElements(elm_SeparationSpec);

		for(i=0;i<nElem;i++){
			if (!GetSeparationSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_SeparationSpec);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_QualityControlResult);

		for(i=0;i<nElem;i++){
			if (!GetQualityControlResult(i).IsValid(level)) {
				vElem.AppendUnique(elm_QualityControlResult);
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
	WString JDFAutoColorSpaceConversionOp::OptionalElements()const{
		return JDFElement::OptionalElements()+L",DeviceNSpace,FileSpec,SeparationSpec,QualityControlResult";
	};
}; // end namespace JDF
