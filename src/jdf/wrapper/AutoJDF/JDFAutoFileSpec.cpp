/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFileSpec.h"
#include "jdf/wrapper/JDFContainer.h"
#include "jdf/wrapper/JDFDisposition.h"
#include "jdf/wrapper/JDFFileAlias.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFileSpec : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFileSpec& JDFAutoFileSpec::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFileSpec: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFileSpec::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFileSpec::ValidNodeNames()const{
	return L"*:,FileSpec";
};

bool JDFAutoFileSpec::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoFileSpec::init(){
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
	WString JDFAutoFileSpec::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Compression,Application,AppOS,AppVersion,CheckSum,Disposition,DocumentNaturalLang,Encoding,FileFormat,FileSize,FileTargetDeviceModel,FileTemplate,FileVersion,MimeType,MimeTypeVersion,OverwritePolicy,OSVersion,PageOrder,Password")
	+WString(L",RequestQuality,ResourceUsage,SearchDepth,UID,URL,UserFileName");
};

/**
 typesafe validator
*/
	vWString JDFAutoFileSpec::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCompression(level)) {
			vAtts.push_back(atr_Compression);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidApplication(level)) {
			vAtts.push_back(atr_Application);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAppOS(level)) {
			vAtts.push_back(atr_AppOS);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAppVersion(level)) {
			vAtts.push_back(atr_AppVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCheckSum(level)) {
			vAtts.push_back(atr_CheckSum);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDisposition(level)) {
			vAtts.push_back(atr_Disposition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocumentNaturalLang(level)) {
			vAtts.push_back(atr_DocumentNaturalLang);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncoding(level)) {
			vAtts.push_back(atr_Encoding);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFileFormat(level)) {
			vAtts.push_back(atr_FileFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFileSize(level)) {
			vAtts.push_back(atr_FileSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFileTargetDeviceModel(level)) {
			vAtts.push_back(atr_FileTargetDeviceModel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFileTemplate(level)) {
			vAtts.push_back(atr_FileTemplate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFileVersion(level)) {
			vAtts.push_back(atr_FileVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMimeType(level)) {
			vAtts.push_back(atr_MimeType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMimeTypeVersion(level)) {
			vAtts.push_back(atr_MimeTypeVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverwritePolicy(level)) {
			vAtts.push_back(atr_OverwritePolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOSVersion(level)) {
			vAtts.push_back(atr_OSVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageOrder(level)) {
			vAtts.push_back(atr_PageOrder);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPassword(level)) {
			vAtts.push_back(atr_Password);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRequestQuality(level)) {
			vAtts.push_back(atr_RequestQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceUsage(level)) {
			vAtts.push_back(atr_ResourceUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSearchDepth(level)) {
			vAtts.push_back(atr_SearchDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUID(level)) {
			vAtts.push_back(atr_UID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURL(level)) {
			vAtts.push_back(atr_URL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUserFileName(level)) {
			vAtts.push_back(atr_UserFileName);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Compression
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetCompression(const WString& value){
	SetAttribute(atr_Compression,value);
};
/**
* Get string attribute Compression
* @return WString the vaue of the attribute ; defaults to None
*/
	 WString JDFAutoFileSpec::GetCompression() const {
	return GetAttribute(atr_Compression,WString::emptyStr,L"None");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidCompression(EnumValidationLevel level) const {
		return ValidAttribute(atr_Compression,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Application
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetApplication(const WString& value){
	SetAttribute(atr_Application,value);
};
/**
* Get string attribute Application
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetApplication() const {
	return GetAttribute(atr_Application,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidApplication(EnumValidationLevel level) const {
		return ValidAttribute(atr_Application,AttributeType_string,false);
	};
/**
* Set attribute AppOS
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetAppOS(const WString& value){
	SetAttribute(atr_AppOS,value);
};
/**
* Get string attribute AppOS
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetAppOS() const {
	return GetAttribute(atr_AppOS,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidAppOS(EnumValidationLevel level) const {
		return ValidAttribute(atr_AppOS,AttributeType_string,false);
	};
/**
* Set attribute AppVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetAppVersion(const WString& value){
	SetAttribute(atr_AppVersion,value);
};
/**
* Get string attribute AppVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetAppVersion() const {
	return GetAttribute(atr_AppVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidAppVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_AppVersion,AttributeType_string,false);
	};
/**
* Set attribute CheckSum
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetCheckSum(const WString& value){
	SetAttribute(atr_CheckSum,value);
};
/**
* Get string attribute CheckSum
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetCheckSum() const {
	return GetAttribute(atr_CheckSum,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidCheckSum(EnumValidationLevel level) const {
		return ValidAttribute(atr_CheckSum,AttributeType_hexBinary,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFileSpec::DispositionString(){
		static const WString enums=WString(L"Unknown,Unlink,Delete,Retain");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFileSpec::DispositionString(EnumDisposition value){
		return DispositionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFileSpec::SetDisposition( EnumDisposition value){
	SetEnumAttribute(atr_Disposition,value,DispositionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFileSpec::EnumDisposition JDFAutoFileSpec:: GetDisposition() const {
	return (EnumDisposition) GetEnumAttribute(atr_Disposition,DispositionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidDisposition(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Disposition,DispositionString(),false);
	};
/**
* Set attribute DocumentNaturalLang
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetDocumentNaturalLang(const WString& value){
	SetAttribute(atr_DocumentNaturalLang,value);
};
/**
* Get string attribute DocumentNaturalLang
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetDocumentNaturalLang() const {
	return GetAttribute(atr_DocumentNaturalLang,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidDocumentNaturalLang(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocumentNaturalLang,AttributeType_language,false);
	};
/**
* Set attribute Encoding
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetEncoding(const WString& value){
	SetAttribute(atr_Encoding,value);
};
/**
* Get string attribute Encoding
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetEncoding() const {
	return GetAttribute(atr_Encoding,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidEncoding(EnumValidationLevel level) const {
		return ValidAttribute(atr_Encoding,AttributeType_string,false);
	};
/**
* Set attribute FileFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetFileFormat(const WString& value){
	SetAttribute(atr_FileFormat,value);
};
/**
* Get string attribute FileFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetFileFormat() const {
	return GetAttribute(atr_FileFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidFileFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_FileFormat,AttributeType_string,false);
	};
/**
* Set attribute FileSize
*@param JDFInt64 value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetFileSize(JDFInt64 value){
	SetAttribute(atr_FileSize,WString::valueOf(value));
};
/**
* Get string attribute FileSize
* @return JDFInt64 the vaue of the attribute 
*/
	 JDFInt64 JDFAutoFileSpec::GetFileSize() const {
	return GetAttribute(atr_FileSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidFileSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_FileSize,AttributeType_integer,false);
	};
/**
* Set attribute FileTargetDeviceModel
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetFileTargetDeviceModel(const WString& value){
	SetAttribute(atr_FileTargetDeviceModel,value);
};
/**
* Get string attribute FileTargetDeviceModel
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetFileTargetDeviceModel() const {
	return GetAttribute(atr_FileTargetDeviceModel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidFileTargetDeviceModel(EnumValidationLevel level) const {
		return ValidAttribute(atr_FileTargetDeviceModel,AttributeType_string,false);
	};
/**
* Set attribute FileTemplate
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetFileTemplate(const WString& value){
	SetAttribute(atr_FileTemplate,value);
};
/**
* Get string attribute FileTemplate
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetFileTemplate() const {
	return GetAttribute(atr_FileTemplate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidFileTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_FileTemplate,AttributeType_string,false);
	};
/**
* Set attribute FileVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetFileVersion(const WString& value){
	SetAttribute(atr_FileVersion,value);
};
/**
* Get string attribute FileVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetFileVersion() const {
	return GetAttribute(atr_FileVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidFileVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_FileVersion,AttributeType_string,false);
	};
/**
* Set attribute MimeType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetMimeType(const WString& value){
	SetAttribute(atr_MimeType,value);
};
/**
* Get string attribute MimeType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetMimeType() const {
	return GetAttribute(atr_MimeType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidMimeType(EnumValidationLevel level) const {
		return ValidAttribute(atr_MimeType,AttributeType_string,false);
	};
/**
* Set attribute MimeTypeVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetMimeTypeVersion(const WString& value){
	SetAttribute(atr_MimeTypeVersion,value);
};
/**
* Get string attribute MimeTypeVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetMimeTypeVersion() const {
	return GetAttribute(atr_MimeTypeVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidMimeTypeVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_MimeTypeVersion,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFileSpec::OverwritePolicyString(){
		static const WString enums=WString(L"Unknown,Overwrite,RenameNew,RenameOld,NewVersion,OperatorIntervention,Abort");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFileSpec::OverwritePolicyString(EnumOverwritePolicy value){
		return OverwritePolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFileSpec::SetOverwritePolicy( EnumOverwritePolicy value){
	SetEnumAttribute(atr_OverwritePolicy,value,OverwritePolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFileSpec::EnumOverwritePolicy JDFAutoFileSpec:: GetOverwritePolicy() const {
	return (EnumOverwritePolicy) GetEnumAttribute(atr_OverwritePolicy,OverwritePolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidOverwritePolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_OverwritePolicy,OverwritePolicyString(),false);
	};
/**
* Set attribute OSVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetOSVersion(const WString& value){
	SetAttribute(atr_OSVersion,value);
};
/**
* Get string attribute OSVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetOSVersion() const {
	return GetAttribute(atr_OSVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidOSVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_OSVersion,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFileSpec::PageOrderString(){
		static const WString enums=WString(L"Unknown,Ascending,Descending");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFileSpec::PageOrderString(EnumPageOrder value){
		return PageOrderString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFileSpec::SetPageOrder( EnumPageOrder value){
	SetEnumAttribute(atr_PageOrder,value,PageOrderString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFileSpec::EnumPageOrder JDFAutoFileSpec:: GetPageOrder() const {
	return (EnumPageOrder) GetEnumAttribute(atr_PageOrder,PageOrderString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidPageOrder(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PageOrder,PageOrderString(),false);
	};
/**
* Set attribute Password
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetPassword(const WString& value){
	SetAttribute(atr_Password,value);
};
/**
* Get string attribute Password
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetPassword() const {
	return GetAttribute(atr_Password,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidPassword(EnumValidationLevel level) const {
		return ValidAttribute(atr_Password,AttributeType_string,false);
	};
/**
* Set attribute RequestQuality
*@param double value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetRequestQuality(double value){
	SetAttribute(atr_RequestQuality,WString::valueOf(value));
};
/**
* Get double attribute RequestQuality
* @return double the vaue of the attribute 
*/
	 double JDFAutoFileSpec::GetRequestQuality() const {
	return GetRealAttribute(atr_RequestQuality,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidRequestQuality(EnumValidationLevel level) const {
		return ValidAttribute(atr_RequestQuality,AttributeType_double,false);
	};
/**
* Set attribute ResourceUsage
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetResourceUsage(const WString& value){
	SetAttribute(atr_ResourceUsage,value);
};
/**
* Get string attribute ResourceUsage
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetResourceUsage() const {
	return GetAttribute(atr_ResourceUsage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidResourceUsage(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceUsage,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute SearchDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetSearchDepth(int value){
	SetAttribute(atr_SearchDepth,WString::valueOf(value));
};
/**
* Get integer attribute SearchDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoFileSpec::GetSearchDepth() const {
	return GetIntAttribute(atr_SearchDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidSearchDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_SearchDepth,AttributeType_integer,false);
	};
/**
* Set attribute UID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetUID(const WString& value){
	SetAttribute(atr_UID,value);
};
/**
* Get string attribute UID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetUID() const {
	return GetAttribute(atr_UID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidUID(EnumValidationLevel level) const {
		return ValidAttribute(atr_UID,AttributeType_string,false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,false);
	};
/**
* Set attribute UserFileName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileSpec::SetUserFileName(const WString& value){
	SetAttribute(atr_UserFileName,value);
};
/**
* Get string attribute UserFileName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileSpec::GetUserFileName() const {
	return GetAttribute(atr_UserFileName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileSpec::ValidUserFileName(EnumValidationLevel level) const {
		return ValidAttribute(atr_UserFileName,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFContainer JDFAutoFileSpec::GetContainer()const{
	JDFContainer e=GetElement(elm_Container);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContainer JDFAutoFileSpec::GetCreateContainer(){
	JDFContainer e=GetCreateElement(elm_Container);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContainer JDFAutoFileSpec::AppendContainer(){
	JDFContainer e=AppendElementN(elm_Container,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoFileSpec::GetDispositionElem()const{
	JDFDisposition e=GetElement(elm_Disposition);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoFileSpec::GetCreateDispositionElem(){
	JDFDisposition e=GetCreateElement(elm_Disposition);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoFileSpec::AppendDispositionElem(){
	JDFDisposition e=AppendElementN(elm_Disposition,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileAlias JDFAutoFileSpec::GetFileAlias(int iSkip)const{
	JDFFileAlias e=GetElement(elm_FileAlias,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileAlias JDFAutoFileSpec::GetCreateFileAlias(int iSkip){
	JDFFileAlias e=GetCreateElement(elm_FileAlias,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileAlias JDFAutoFileSpec::AppendFileAlias(){
	JDFFileAlias e=AppendElement(elm_FileAlias);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoFileSpec::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Container);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Container);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetContainer().IsValid(level)) {
				vElem.AppendUnique(elm_Container);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Disposition);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Disposition);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDispositionElem().IsValid(level)) {
				vElem.AppendUnique(elm_Disposition);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FileAlias);

		for(i=0;i<nElem;i++){
			if (!GetFileAlias(i).IsValid(level)) {
				vElem.AppendUnique(elm_FileAlias);
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
	WString JDFAutoFileSpec::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Container,Disposition";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoFileSpec::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Container,Disposition,FileAlias";
	};
}; // end namespace JDF
