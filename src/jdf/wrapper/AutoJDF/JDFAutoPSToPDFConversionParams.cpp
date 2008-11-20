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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPSToPDFConversionParams.h"
#include "jdf/wrapper/JDFAdvancedParams.h"
#include "jdf/wrapper/JDFPDFXParams.h"
#include "jdf/wrapper/JDFThinPDFParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPSToPDFConversionParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPSToPDFConversionParams& JDFAutoPSToPDFConversionParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPSToPDFConversionParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPSToPDFConversionParams::ValidNodeNames()const{
	return L"*:,PSToPDFConversionParams";
};

bool JDFAutoPSToPDFConversionParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPSToPDFConversionParams::init(){
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
	WString JDFAutoPSToPDFConversionParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ASCII85EncodePages,Binding,DetectBlend,DoThumbnails,Optimize,AutoRotatePages,CompressPages,DefaultRenderingIntent,EndPage,ImageMemory,InitialPageSize,InitialResolution,OverPrintMode,PDFVersion,StartPage");
};

/**
 typesafe validator
*/
	vWString JDFAutoPSToPDFConversionParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidASCII85EncodePages(level)) {
			vAtts.push_back(atr_ASCII85EncodePages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBinding(level)) {
			vAtts.push_back(atr_Binding);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDetectBlend(level)) {
			vAtts.push_back(atr_DetectBlend);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDoThumbnails(level)) {
			vAtts.push_back(atr_DoThumbnails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOptimize(level)) {
			vAtts.push_back(atr_Optimize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAutoRotatePages(level)) {
			vAtts.push_back(atr_AutoRotatePages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompressPages(level)) {
			vAtts.push_back(atr_CompressPages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDefaultRenderingIntent(level)) {
			vAtts.push_back(atr_DefaultRenderingIntent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEndPage(level)) {
			vAtts.push_back(atr_EndPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageMemory(level)) {
			vAtts.push_back(atr_ImageMemory);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInitialPageSize(level)) {
			vAtts.push_back(atr_InitialPageSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInitialResolution(level)) {
			vAtts.push_back(atr_InitialResolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverPrintMode(level)) {
			vAtts.push_back(atr_OverPrintMode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFVersion(level)) {
			vAtts.push_back(atr_PDFVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStartPage(level)) {
			vAtts.push_back(atr_StartPage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ASCII85EncodePages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetASCII85EncodePages(bool value){
	SetAttribute(atr_ASCII85EncodePages,WString::valueOf(value));
};
/**
* Get bool attribute ASCII85EncodePages
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPSToPDFConversionParams::GetASCII85EncodePages() const {return GetBoolAttribute(atr_ASCII85EncodePages,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidASCII85EncodePages(EnumValidationLevel level) const {
		return ValidAttribute(atr_ASCII85EncodePages,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPSToPDFConversionParams::BindingString(){
		static const WString enums=WString(L"Unknown,Left,Right");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPSToPDFConversionParams::BindingString(EnumBinding value){
		return BindingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPSToPDFConversionParams::SetBinding( EnumBinding value){
	SetEnumAttribute(atr_Binding,value,BindingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPSToPDFConversionParams::EnumBinding JDFAutoPSToPDFConversionParams:: GetBinding() const {
	return (EnumBinding) GetEnumAttribute(atr_Binding,BindingString(),WString::emptyStr,Binding_Left);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidBinding(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Binding,BindingString(),false);
	};
/**
* Set attribute DetectBlend
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetDetectBlend(bool value){
	SetAttribute(atr_DetectBlend,WString::valueOf(value));
};
/**
* Get bool attribute DetectBlend
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPSToPDFConversionParams::GetDetectBlend() const {return GetBoolAttribute(atr_DetectBlend,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidDetectBlend(EnumValidationLevel level) const {
		return ValidAttribute(atr_DetectBlend,AttributeType_boolean,false);
	};
/**
* Set attribute DoThumbnails
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetDoThumbnails(bool value){
	SetAttribute(atr_DoThumbnails,WString::valueOf(value));
};
/**
* Get bool attribute DoThumbnails
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPSToPDFConversionParams::GetDoThumbnails() const {return GetBoolAttribute(atr_DoThumbnails,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidDoThumbnails(EnumValidationLevel level) const {
		return ValidAttribute(atr_DoThumbnails,AttributeType_boolean,false);
	};
/**
* Set attribute Optimize
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetOptimize(bool value){
	SetAttribute(atr_Optimize,WString::valueOf(value));
};
/**
* Get bool attribute Optimize
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPSToPDFConversionParams::GetOptimize() const {return GetBoolAttribute(atr_Optimize,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidOptimize(EnumValidationLevel level) const {
		return ValidAttribute(atr_Optimize,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPSToPDFConversionParams::AutoRotatePagesString(){
		static const WString enums=WString(L"Unknown,None,All,PageByPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPSToPDFConversionParams::AutoRotatePagesString(EnumAutoRotatePages value){
		return AutoRotatePagesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPSToPDFConversionParams::SetAutoRotatePages( EnumAutoRotatePages value){
	SetEnumAttribute(atr_AutoRotatePages,value,AutoRotatePagesString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPSToPDFConversionParams::EnumAutoRotatePages JDFAutoPSToPDFConversionParams:: GetAutoRotatePages() const {
	return (EnumAutoRotatePages) GetEnumAttribute(atr_AutoRotatePages,AutoRotatePagesString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidAutoRotatePages(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_AutoRotatePages,AutoRotatePagesString(),false);
	};
/**
* Set attribute CompressPages
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetCompressPages(bool value){
	SetAttribute(atr_CompressPages,WString::valueOf(value));
};
/**
* Get bool attribute CompressPages
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPSToPDFConversionParams::GetCompressPages() const {return GetBoolAttribute(atr_CompressPages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidCompressPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_CompressPages,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPSToPDFConversionParams::DefaultRenderingIntentString(){
		static const WString enums=WString(L"Unknown,Default,Perceptual,Saturation,RelativeColorimetric,AbsoluteColorimetric");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPSToPDFConversionParams::DefaultRenderingIntentString(EnumDefaultRenderingIntent value){
		return DefaultRenderingIntentString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPSToPDFConversionParams::SetDefaultRenderingIntent( EnumDefaultRenderingIntent value){
	SetEnumAttribute(atr_DefaultRenderingIntent,value,DefaultRenderingIntentString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPSToPDFConversionParams::EnumDefaultRenderingIntent JDFAutoPSToPDFConversionParams:: GetDefaultRenderingIntent() const {
	return (EnumDefaultRenderingIntent) GetEnumAttribute(atr_DefaultRenderingIntent,DefaultRenderingIntentString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidDefaultRenderingIntent(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DefaultRenderingIntent,DefaultRenderingIntentString(),false);
	};
/**
* Set attribute EndPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetEndPage(int value){
	SetAttribute(atr_EndPage,WString::valueOf(value));
};
/**
* Get integer attribute EndPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoPSToPDFConversionParams::GetEndPage() const {
	return GetIntAttribute(atr_EndPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidEndPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_EndPage,AttributeType_integer,false);
	};
/**
* Set attribute ImageMemory
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetImageMemory(int value){
	SetAttribute(atr_ImageMemory,WString::valueOf(value));
};
/**
* Get integer attribute ImageMemory
* @return int the vaue of the attribute 
*/
	 int JDFAutoPSToPDFConversionParams::GetImageMemory() const {
	return GetIntAttribute(atr_ImageMemory,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidImageMemory(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageMemory,AttributeType_integer,false);
	};
/**
* Set attribute InitialPageSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetInitialPageSize(const JDFXYPair& value){
	SetAttribute(atr_InitialPageSize,value);
};
/**
* Get string attribute InitialPageSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPSToPDFConversionParams::GetInitialPageSize() const {
	return GetAttribute(atr_InitialPageSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidInitialPageSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_InitialPageSize,AttributeType_XYPair,false);
	};
/**
* Set attribute InitialResolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetInitialResolution(const JDFXYPair& value){
	SetAttribute(atr_InitialResolution,value);
};
/**
* Get string attribute InitialResolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPSToPDFConversionParams::GetInitialResolution() const {
	return GetAttribute(atr_InitialResolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidInitialResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_InitialResolution,AttributeType_XYPair,false);
	};
/**
* Set attribute OverPrintMode
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetOverPrintMode(int value){
	SetAttribute(atr_OverPrintMode,WString::valueOf(value));
};
/**
* Get integer attribute OverPrintMode
* @return int the vaue of the attribute 
*/
	 int JDFAutoPSToPDFConversionParams::GetOverPrintMode() const {
	return GetIntAttribute(atr_OverPrintMode,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidOverPrintMode(EnumValidationLevel level) const {
		return ValidAttribute(atr_OverPrintMode,AttributeType_integer,false);
	};
/**
* Set attribute PDFVersion
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetPDFVersion(double value){
	SetAttribute(atr_PDFVersion,WString::valueOf(value));
};
/**
* Get double attribute PDFVersion
* @return double the vaue of the attribute 
*/
	 double JDFAutoPSToPDFConversionParams::GetPDFVersion() const {
	return GetRealAttribute(atr_PDFVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidPDFVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFVersion,AttributeType_double,false);
	};
/**
* Set attribute StartPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPSToPDFConversionParams::SetStartPage(int value){
	SetAttribute(atr_StartPage,WString::valueOf(value));
};
/**
* Get integer attribute StartPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoPSToPDFConversionParams::GetStartPage() const {
	return GetIntAttribute(atr_StartPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPSToPDFConversionParams::ValidStartPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartPage,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAdvancedParams JDFAutoPSToPDFConversionParams::GetAdvancedParams()const{
	JDFAdvancedParams e=GetElement(elm_AdvancedParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAdvancedParams JDFAutoPSToPDFConversionParams::GetCreateAdvancedParams(){
	JDFAdvancedParams e=GetCreateElement(elm_AdvancedParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAdvancedParams JDFAutoPSToPDFConversionParams::AppendAdvancedParams(){
	JDFAdvancedParams e=AppendElementN(elm_AdvancedParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFXParams JDFAutoPSToPDFConversionParams::GetPDFXParams()const{
	JDFPDFXParams e=GetElement(elm_PDFXParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFXParams JDFAutoPSToPDFConversionParams::GetCreatePDFXParams(){
	JDFPDFXParams e=GetCreateElement(elm_PDFXParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFXParams JDFAutoPSToPDFConversionParams::AppendPDFXParams(){
	JDFPDFXParams e=AppendElementN(elm_PDFXParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThinPDFParams JDFAutoPSToPDFConversionParams::GetThinPDFParams()const{
	JDFThinPDFParams e=GetElement(elm_ThinPDFParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThinPDFParams JDFAutoPSToPDFConversionParams::GetCreateThinPDFParams(){
	JDFThinPDFParams e=GetCreateElement(elm_ThinPDFParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThinPDFParams JDFAutoPSToPDFConversionParams::AppendThinPDFParams(){
	JDFThinPDFParams e=AppendElementN(elm_ThinPDFParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPSToPDFConversionParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_AdvancedParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_AdvancedParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAdvancedParams().IsValid(level)) {
				vElem.AppendUnique(elm_AdvancedParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PDFXParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PDFXParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPDFXParams().IsValid(level)) {
				vElem.AppendUnique(elm_PDFXParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ThinPDFParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ThinPDFParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetThinPDFParams().IsValid(level)) {
				vElem.AppendUnique(elm_ThinPDFParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPSToPDFConversionParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",AdvancedParams,PDFXParams,ThinPDFParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPSToPDFConversionParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",AdvancedParams,PDFXParams,ThinPDFParams";
	};
}; // end namespace JDF
