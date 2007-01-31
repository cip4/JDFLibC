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

 
#include "jdf/wrapper/AutoJDF/JDFAutoModuleStatus.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoModuleStatus : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoModuleStatus& JDFAutoModuleStatus::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoModuleStatus: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoModuleStatus::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoModuleStatus::ValidNodeNames()const{
	return L"*:,ModuleStatus";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoModuleStatus::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",DeviceStatus,ModuleIndex,ModuleType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoModuleStatus::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CombinedProcessIndex,ModuleID,StatusDetails");
};

/**
 typesafe validator
*/
	vWString JDFAutoModuleStatus::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCombinedProcessIndex(level)) {
			vAtts.push_back(atr_CombinedProcessIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceStatus(level)) {
			vAtts.push_back(atr_DeviceStatus);
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
		if(!ValidStatusDetails(level)) {
			vAtts.push_back(atr_StatusDetails);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CombinedProcessIndex
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoModuleStatus::SetCombinedProcessIndex(const JDFIntegerList& value){
	SetAttribute(atr_CombinedProcessIndex,value.GetString());
};
/**
* Get string attribute CombinedProcessIndex
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoModuleStatus::GetCombinedProcessIndex() const {
	return GetAttribute(atr_CombinedProcessIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModuleStatus::ValidCombinedProcessIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_CombinedProcessIndex,AttributeType_IntegerList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoModuleStatus::DeviceStatusString(){
		static const WString enums=WString(L"Unknown,Idle,Down,Setup,Running,Cleanup,Stopped");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoModuleStatus::DeviceStatusString(EnumDeviceStatus value){
		return DeviceStatusString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoModuleStatus::SetDeviceStatus( EnumDeviceStatus value){
	SetEnumAttribute(atr_DeviceStatus,value,DeviceStatusString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoModuleStatus::EnumDeviceStatus JDFAutoModuleStatus:: GetDeviceStatus() const {
	return (EnumDeviceStatus) GetEnumAttribute(atr_DeviceStatus,DeviceStatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModuleStatus::ValidDeviceStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DeviceStatus,DeviceStatusString(),RequiredLevel(level),WString::emptyStr,true);
	};
/**
* Set attribute ModuleID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModuleStatus::SetModuleID(const WString& value){
	SetAttribute(atr_ModuleID,value);
};
/**
* Get string attribute ModuleID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModuleStatus::GetModuleID() const {
	return GetAttribute(atr_ModuleID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModuleStatus::ValidModuleID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleID,AttributeType_string,false);
	};
/**
* Set attribute ModuleIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoModuleStatus::SetModuleIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_ModuleIndex,value.GetString());
};
/**
* Get range attribute ModuleIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoModuleStatus::GetModuleIndex() const {
	return GetAttribute(atr_ModuleIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModuleStatus::ValidModuleIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleIndex,AttributeType_IntegerRangeList,RequiredLevel(level));
	};
/**
* Set attribute ModuleType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModuleStatus::SetModuleType(const WString& value){
	SetAttribute(atr_ModuleType,value);
};
/**
* Get string attribute ModuleType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModuleStatus::GetModuleType() const {
	return GetAttribute(atr_ModuleType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModuleStatus::ValidModuleType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleType,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute StatusDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoModuleStatus::SetStatusDetails(const WString& value){
	SetAttribute(atr_StatusDetails,value);
};
/**
* Get string attribute StatusDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoModuleStatus::GetStatusDetails() const {
	return GetAttribute(atr_StatusDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoModuleStatus::ValidStatusDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_StatusDetails,AttributeType_shortString,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFEmployee JDFAutoModuleStatus::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoModuleStatus::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoModuleStatus::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoModuleStatus::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoModuleStatus::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Employee);

		for(i=0;i<nElem;i++){
			if (!GetEmployee(i).IsValid(level)) {
				vElem.AppendUnique(elm_Employee);
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
	WString JDFAutoModuleStatus::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Employee";
	};
}; // end namespace JDF
