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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDevice.h"
#include "jdf/wrapper/JDFCostCenter.h"
#include "jdf/wrapper/JDFDeviceCap.h"
#include "jdf/wrapper/JDFIconList.h"
#include "jdf/wrapper/JDFModule.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDevice : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDevice& JDFAutoDevice::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDevice: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDevice::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDevice::ValidNodeNames()const{
	return L"*:,Device";
};

bool JDFAutoDevice::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Implementation;
};

bool JDFAutoDevice::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Implementation);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDevice::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DeviceFamily,DeviceID,DeviceType,Directory,FriendlyName,ICSVersions,JDFErrorURL,JDFInputURL,JDFOutputURL,JDFVersions,JMFSenderID,JMFURL,KnownLocalizations,Manufacturer,ManufacturerURL,ModelDescription,ModelName,ModelNumber,ModelURL")
	+WString(L",SerialNumber,PresentationURL,SecureJMFURL,UPC");
};

/**
 typesafe validator
*/
	vWString JDFAutoDevice::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDeviceFamily(level)) {
			vAtts.push_back(atr_DeviceFamily);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceType(level)) {
			vAtts.push_back(atr_DeviceType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDirectory(level)) {
			vAtts.push_back(atr_Directory);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFriendlyName(level)) {
			vAtts.push_back(atr_FriendlyName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidICSVersions(level)) {
			vAtts.push_back(atr_ICSVersions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJDFErrorURL(level)) {
			vAtts.push_back(atr_JDFErrorURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJDFInputURL(level)) {
			vAtts.push_back(atr_JDFInputURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJDFOutputURL(level)) {
			vAtts.push_back(atr_JDFOutputURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJDFVersions(level)) {
			vAtts.push_back(atr_JDFVersions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJMFSenderID(level)) {
			vAtts.push_back(atr_JMFSenderID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJMFURL(level)) {
			vAtts.push_back(atr_JMFURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidKnownLocalizations(level)) {
			vAtts.push_back(atr_KnownLocalizations);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidManufacturer(level)) {
			vAtts.push_back(atr_Manufacturer);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidManufacturerURL(level)) {
			vAtts.push_back(atr_ManufacturerURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModelDescription(level)) {
			vAtts.push_back(atr_ModelDescription);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModelName(level)) {
			vAtts.push_back(atr_ModelName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModelNumber(level)) {
			vAtts.push_back(atr_ModelNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModelURL(level)) {
			vAtts.push_back(atr_ModelURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSerialNumber(level)) {
			vAtts.push_back(atr_SerialNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPresentationURL(level)) {
			vAtts.push_back(atr_PresentationURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSecureJMFURL(level)) {
			vAtts.push_back(atr_SecureJMFURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUPC(level)) {
			vAtts.push_back(atr_UPC);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DeviceFamily
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetDeviceFamily(const WString& value){
	SetAttribute(atr_DeviceFamily,value);
};
/**
* Get string attribute DeviceFamily
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetDeviceFamily() const {
	return GetAttribute(atr_DeviceFamily,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidDeviceFamily(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceFamily,AttributeType_string,false);
	};
/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_string,false);
	};
/**
* Set attribute DeviceType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetDeviceType(const WString& value){
	SetAttribute(atr_DeviceType,value);
};
/**
* Get string attribute DeviceType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetDeviceType() const {
	return GetAttribute(atr_DeviceType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidDeviceType(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceType,AttributeType_string,false);
	};
/**
* Set attribute Directory
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetDirectory(const WString& value){
	SetAttribute(atr_Directory,value);
};
/**
* Get string attribute Directory
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetDirectory() const {
	return GetAttribute(atr_Directory,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidDirectory(EnumValidationLevel level) const {
		return ValidAttribute(atr_Directory,AttributeType_URL,false);
	};
/**
* Set attribute FriendlyName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetFriendlyName(const WString& value){
	SetAttribute(atr_FriendlyName,value);
};
/**
* Get string attribute FriendlyName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetFriendlyName() const {
	return GetAttribute(atr_FriendlyName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidFriendlyName(EnumValidationLevel level) const {
		return ValidAttribute(atr_FriendlyName,AttributeType_string,false);
	};
/**
* Set attribute ICSVersions
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetICSVersions(const vWString& value){
	SetAttribute(atr_ICSVersions,value);
};
/**
* Get string attribute ICSVersions
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDevice::GetICSVersions() const {
	return GetAttribute(atr_ICSVersions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidICSVersions(EnumValidationLevel level) const {
		return ValidAttribute(atr_ICSVersions,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute JDFErrorURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetJDFErrorURL(const WString& value){
	SetAttribute(atr_JDFErrorURL,value);
};
/**
* Get string attribute JDFErrorURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetJDFErrorURL() const {
	return GetAttribute(atr_JDFErrorURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidJDFErrorURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_JDFErrorURL,AttributeType_URL,false);
	};
/**
* Set attribute JDFInputURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetJDFInputURL(const WString& value){
	SetAttribute(atr_JDFInputURL,value);
};
/**
* Get string attribute JDFInputURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetJDFInputURL() const {
	return GetAttribute(atr_JDFInputURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidJDFInputURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_JDFInputURL,AttributeType_URL,false);
	};
/**
* Set attribute JDFOutputURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetJDFOutputURL(const WString& value){
	SetAttribute(atr_JDFOutputURL,value);
};
/**
* Get string attribute JDFOutputURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetJDFOutputURL() const {
	return GetAttribute(atr_JDFOutputURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidJDFOutputURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_JDFOutputURL,AttributeType_URL,false);
	};
/**
* Set attribute JDFVersions
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetJDFVersions(const WString& value){
	SetAttribute(atr_JDFVersions,value);
};
/**
* Get string attribute JDFVersions
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetJDFVersions() const {
	return GetAttribute(atr_JDFVersions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidJDFVersions(EnumValidationLevel level) const {
		return ValidAttribute(atr_JDFVersions,AttributeType_Any,false);
	};
/**
* Set attribute JMFSenderID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetJMFSenderID(const WString& value){
	SetAttribute(atr_JMFSenderID,value);
};
/**
* Get string attribute JMFSenderID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetJMFSenderID() const {
	return GetAttribute(atr_JMFSenderID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidJMFSenderID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JMFSenderID,AttributeType_shortString,false);
	};
/**
* Set attribute JMFURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetJMFURL(const WString& value){
	SetAttribute(atr_JMFURL,value);
};
/**
* Get string attribute JMFURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetJMFURL() const {
	return GetAttribute(atr_JMFURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidJMFURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_JMFURL,AttributeType_URL,false);
	};
/**
* Set attribute KnownLocalizations
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetKnownLocalizations(const vWString& value){
	SetAttribute(atr_KnownLocalizations,value);
};
/**
* Get string attribute KnownLocalizations
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDevice::GetKnownLocalizations() const {
	return GetAttribute(atr_KnownLocalizations,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidKnownLocalizations(EnumValidationLevel level) const {
		return ValidAttribute(atr_KnownLocalizations,AttributeType_languages,false);
	};
/**
* Set attribute Manufacturer
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetManufacturer(const WString& value){
	SetAttribute(atr_Manufacturer,value);
};
/**
* Get string attribute Manufacturer
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetManufacturer() const {
	return GetAttribute(atr_Manufacturer,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidManufacturer(EnumValidationLevel level) const {
		return ValidAttribute(atr_Manufacturer,AttributeType_string,false);
	};
/**
* Set attribute ManufacturerURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetManufacturerURL(const WString& value){
	SetAttribute(atr_ManufacturerURL,value);
};
/**
* Get string attribute ManufacturerURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetManufacturerURL() const {
	return GetAttribute(atr_ManufacturerURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidManufacturerURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_ManufacturerURL,AttributeType_string,false);
	};
/**
* Set attribute ModelDescription
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetModelDescription(const WString& value){
	SetAttribute(atr_ModelDescription,value);
};
/**
* Get string attribute ModelDescription
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetModelDescription() const {
	return GetAttribute(atr_ModelDescription,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidModelDescription(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModelDescription,AttributeType_string,false);
	};
/**
* Set attribute ModelName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetModelName(const WString& value){
	SetAttribute(atr_ModelName,value);
};
/**
* Get string attribute ModelName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetModelName() const {
	return GetAttribute(atr_ModelName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidModelName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModelName,AttributeType_string,false);
	};
/**
* Set attribute ModelNumber
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetModelNumber(const WString& value){
	SetAttribute(atr_ModelNumber,value);
};
/**
* Get string attribute ModelNumber
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetModelNumber() const {
	return GetAttribute(atr_ModelNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidModelNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModelNumber,AttributeType_string,false);
	};
/**
* Set attribute ModelURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetModelURL(const WString& value){
	SetAttribute(atr_ModelURL,value);
};
/**
* Get string attribute ModelURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetModelURL() const {
	return GetAttribute(atr_ModelURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidModelURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModelURL,AttributeType_string,false);
	};
/**
* Set attribute SerialNumber
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetSerialNumber(const WString& value){
	SetAttribute(atr_SerialNumber,value);
};
/**
* Get string attribute SerialNumber
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetSerialNumber() const {
	return GetAttribute(atr_SerialNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidSerialNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_SerialNumber,AttributeType_string,false);
	};
/**
* Set attribute PresentationURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetPresentationURL(const WString& value){
	SetAttribute(atr_PresentationURL,value);
};
/**
* Get string attribute PresentationURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetPresentationURL() const {
	return GetAttribute(atr_PresentationURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidPresentationURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentationURL,AttributeType_string,false);
	};
/**
* Set attribute SecureJMFURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetSecureJMFURL(const WString& value){
	SetAttribute(atr_SecureJMFURL,value);
};
/**
* Get string attribute SecureJMFURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetSecureJMFURL() const {
	return GetAttribute(atr_SecureJMFURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidSecureJMFURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_SecureJMFURL,AttributeType_URL,false);
	};
/**
* Set attribute UPC
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevice::SetUPC(const WString& value){
	SetAttribute(atr_UPC,value);
};
/**
* Get string attribute UPC
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevice::GetUPC() const {
	return GetAttribute(atr_UPC,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevice::ValidUPC(EnumValidationLevel level) const {
		return ValidAttribute(atr_UPC,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCostCenter JDFAutoDevice::GetCostCenter(int iSkip)const{
	JDFCostCenter e=GetElement(elm_CostCenter,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoDevice::GetCreateCostCenter(int iSkip){
	JDFCostCenter e=GetCreateElement(elm_CostCenter,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoDevice::AppendCostCenter(){
	JDFCostCenter e=AppendElement(elm_CostCenter);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceCap JDFAutoDevice::GetDeviceCap(int iSkip)const{
	JDFDeviceCap e=GetElement(elm_DeviceCap,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceCap JDFAutoDevice::GetCreateDeviceCap(int iSkip){
	JDFDeviceCap e=GetCreateElement(elm_DeviceCap,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceCap JDFAutoDevice::AppendDeviceCap(){
	JDFDeviceCap e=AppendElement(elm_DeviceCap);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIconList JDFAutoDevice::GetIconList(int iSkip)const{
	JDFIconList e=GetElement(elm_IconList,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIconList JDFAutoDevice::GetCreateIconList(int iSkip){
	JDFIconList e=GetCreateElement(elm_IconList,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIconList JDFAutoDevice::AppendIconList(){
	JDFIconList e=AppendElement(elm_IconList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModule JDFAutoDevice::GetModule(int iSkip)const{
	JDFModule e=GetElement(elm_Module,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModule JDFAutoDevice::GetCreateModule(int iSkip){
	JDFModule e=GetCreateElement(elm_Module,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModule JDFAutoDevice::AppendModule(){
	JDFModule e=AppendElement(elm_Module);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDevice::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CostCenter);

		for(i=0;i<nElem;i++){
			if (!GetCostCenter(i).IsValid(level)) {
				vElem.AppendUnique(elm_CostCenter);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DeviceCap);

		for(i=0;i<nElem;i++){
			if (!GetDeviceCap(i).IsValid(level)) {
				vElem.AppendUnique(elm_DeviceCap);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IconList);

		for(i=0;i<nElem;i++){
			if (!GetIconList(i).IsValid(level)) {
				vElem.AppendUnique(elm_IconList);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Module);

		for(i=0;i<nElem;i++){
			if (!GetModule(i).IsValid(level)) {
				vElem.AppendUnique(elm_Module);
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
	WString JDFAutoDevice::OptionalElements()const{
		return JDFResource::OptionalElements()+L",CostCenter,DeviceCap,IconList,Module";
	};
}; // end namespace JDF
