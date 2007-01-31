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

 
#include "jdf/wrapper/AutoJDF/JDFAutoModule.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoModule : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoModule& JDFAutoModule::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoModule: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoModule::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoModule::ValidNodeNames()const{
	return L"*:,Module";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoModule::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",DeviceType,Manufacturer,ManufacturerURL,ModelDescription,ModelName,ModelNumber,ModelURL,ModuleID,ModuleIndex,ModuleType,SerialNumber,SubModuleIndex");
};

/**
 typesafe validator
*/
	vWString JDFAutoModule::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDeviceType(level)) {
			vAtts.push_back(atr_DeviceType);
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
		if(!ValidModuleID(level)) {
			vAtts.push_back(atr_ModuleID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleIndex(level)) {
			vAtts.push_back(atr_ModuleIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleType(level)) {
			vAtts.push_back(atr_ModuleType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSerialNumber(level)) {
			vAtts.push_back(atr_SerialNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSubModuleIndex(level)) {
			vAtts.push_back(atr_SubModuleIndex);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DeviceType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetDeviceType(const WString& value){
	SetAttribute(atr_DeviceType,value);
};
/**
* Get string attribute DeviceType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetDeviceType() const {
	return GetAttribute(atr_DeviceType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidDeviceType(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceType,AttributeType_string,false);
	};
/**
* Set attribute Manufacturer
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetManufacturer(const WString& value){
	SetAttribute(atr_Manufacturer,value);
};
/**
* Get string attribute Manufacturer
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetManufacturer() const {
	return GetAttribute(atr_Manufacturer,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidManufacturer(EnumValidationLevel level) const {
		return ValidAttribute(atr_Manufacturer,AttributeType_string,false);
	};
/**
* Set attribute ManufacturerURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetManufacturerURL(const WString& value){
	SetAttribute(atr_ManufacturerURL,value);
};
/**
* Get string attribute ManufacturerURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetManufacturerURL() const {
	return GetAttribute(atr_ManufacturerURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidManufacturerURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_ManufacturerURL,AttributeType_string,false);
	};
/**
* Set attribute ModelDescription
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetModelDescription(const WString& value){
	SetAttribute(atr_ModelDescription,value);
};
/**
* Get string attribute ModelDescription
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetModelDescription() const {
	return GetAttribute(atr_ModelDescription,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidModelDescription(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModelDescription,AttributeType_string,false);
	};
/**
* Set attribute ModelName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetModelName(const WString& value){
	SetAttribute(atr_ModelName,value);
};
/**
* Get string attribute ModelName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetModelName() const {
	return GetAttribute(atr_ModelName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidModelName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModelName,AttributeType_string,false);
	};
/**
* Set attribute ModelNumber
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetModelNumber(const WString& value){
	SetAttribute(atr_ModelNumber,value);
};
/**
* Get string attribute ModelNumber
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetModelNumber() const {
	return GetAttribute(atr_ModelNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidModelNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModelNumber,AttributeType_string,false);
	};
/**
* Set attribute ModelURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetModelURL(const WString& value){
	SetAttribute(atr_ModelURL,value);
};
/**
* Get string attribute ModelURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetModelURL() const {
	return GetAttribute(atr_ModelURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidModelURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModelURL,AttributeType_string,false);
	};
/**
* Set attribute ModuleID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetModuleID(const WString& value){
	SetAttribute(atr_ModuleID,value);
};
/**
* Get string attribute ModuleID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetModuleID() const {
	return GetAttribute(atr_ModuleID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidModuleID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleID,AttributeType_string,false);
	};
/**
* Set attribute ModuleIndex
*@param int value: the value to set the attribute to
*/
	 void JDFAutoModule::SetModuleIndex(int value){
	SetAttribute(atr_ModuleIndex,WString::valueOf(value));
};
/**
* Get integer attribute ModuleIndex
* @return int the vaue of the attribute 
*/
	 int JDFAutoModule::GetModuleIndex() const {
	return GetIntAttribute(atr_ModuleIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidModuleIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleIndex,AttributeType_integer,false);
	};
/**
* Set attribute ModuleType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetModuleType(const WString& value){
	SetAttribute(atr_ModuleType,value);
};
/**
* Get string attribute ModuleType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetModuleType() const {
	return GetAttribute(atr_ModuleType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidModuleType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute SerialNumber
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModule::SetSerialNumber(const WString& value){
	SetAttribute(atr_SerialNumber,value);
};
/**
* Get string attribute SerialNumber
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModule::GetSerialNumber() const {
	return GetAttribute(atr_SerialNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidSerialNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_SerialNumber,AttributeType_string,false);
	};
/**
* Set attribute SubModuleIndex
*@param int value: the value to set the attribute to
*/
	 void JDFAutoModule::SetSubModuleIndex(int value){
	SetAttribute(atr_SubModuleIndex,WString::valueOf(value));
};
/**
* Get integer attribute SubModuleIndex
* @return int the vaue of the attribute 
*/
	 int JDFAutoModule::GetSubModuleIndex() const {
	return GetIntAttribute(atr_SubModuleIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModule::ValidSubModuleIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SubModuleIndex,AttributeType_integer,false);
	};
}; // end namespace JDF
