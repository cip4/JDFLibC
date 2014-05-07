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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDeviceInfo.h"
#include "jdf/wrapper/JDFActivity.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFJobPhase.h"
#include "jdf/wrapper/JDFModuleStatus.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDeviceInfo : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDeviceInfo& JDFAutoDeviceInfo::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDeviceInfo: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDeviceInfo::ValidNodeNames()const{
	return L"*:,DeviceInfo";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoDeviceInfo::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",DeviceStatus";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDeviceInfo::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CounterUnit,DeviceCondition,DeviceID,DeviceOperationMode,HourCounter,IdleStartTime,PowerOnTime,ProductionCounter,Speed,StatusDetails,TotalProductionCounter");
};

/**
 typesafe validator
*/
	vWString JDFAutoDeviceInfo::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCounterUnit(level)) {
			vAtts.push_back(atr_CounterUnit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceCondition(level)) {
			vAtts.push_back(atr_DeviceCondition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceOperationMode(level)) {
			vAtts.push_back(atr_DeviceOperationMode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceStatus(level)) {
			vAtts.push_back(atr_DeviceStatus);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHourCounter(level)) {
			vAtts.push_back(atr_HourCounter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIdleStartTime(level)) {
			vAtts.push_back(atr_IdleStartTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPowerOnTime(level)) {
			vAtts.push_back(atr_PowerOnTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductionCounter(level)) {
			vAtts.push_back(atr_ProductionCounter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpeed(level)) {
			vAtts.push_back(atr_Speed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatusDetails(level)) {
			vAtts.push_back(atr_StatusDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTotalProductionCounter(level)) {
			vAtts.push_back(atr_TotalProductionCounter);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CounterUnit
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetCounterUnit(const WString& value){
	SetAttribute(atr_CounterUnit,value);
};
/**
* Get string attribute CounterUnit
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDeviceInfo::GetCounterUnit() const {
	return GetAttribute(atr_CounterUnit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidCounterUnit(EnumValidationLevel level) const {
		return ValidAttribute(atr_CounterUnit,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeviceInfo::DeviceConditionString(){
		static const WString enums=WString(L"Unknown,OK,NeedsAttention,Failure,OffLine");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeviceInfo::DeviceConditionString(EnumDeviceCondition value){
		return DeviceConditionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceInfo::SetDeviceCondition( EnumDeviceCondition value){
	SetEnumAttribute(atr_DeviceCondition,value,DeviceConditionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeviceInfo::EnumDeviceCondition JDFAutoDeviceInfo:: GetDeviceCondition() const {
	return (EnumDeviceCondition) GetEnumAttribute(atr_DeviceCondition,DeviceConditionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidDeviceCondition(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DeviceCondition,DeviceConditionString(),false);
	};
/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDeviceInfo::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeviceInfo::DeviceOperationModeString(){
		static const WString enums=WString(L"Unknown,Productive,NonProductive,Maintenance");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeviceInfo::DeviceOperationModeString(EnumDeviceOperationMode value){
		return DeviceOperationModeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceInfo::SetDeviceOperationMode( EnumDeviceOperationMode value){
	SetEnumAttribute(atr_DeviceOperationMode,value,DeviceOperationModeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeviceInfo::EnumDeviceOperationMode JDFAutoDeviceInfo:: GetDeviceOperationMode() const {
	return (EnumDeviceOperationMode) GetEnumAttribute(atr_DeviceOperationMode,DeviceOperationModeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidDeviceOperationMode(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DeviceOperationMode,DeviceOperationModeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeviceInfo::DeviceStatusString(){
		static const WString enums=WString(L"Unknown,Idle,Down,Setup,Running,Cleanup,Stopped");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeviceInfo::DeviceStatusString(EnumDeviceStatus value){
		return DeviceStatusString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceInfo::SetDeviceStatus( EnumDeviceStatus value){
	SetEnumAttribute(atr_DeviceStatus,value,DeviceStatusString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeviceInfo::EnumDeviceStatus JDFAutoDeviceInfo:: GetDeviceStatus() const {
	return (EnumDeviceStatus) GetEnumAttribute(atr_DeviceStatus,DeviceStatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidDeviceStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DeviceStatus,DeviceStatusString(),RequiredLevel(level),WString::emptyStr,true);
	};
/**
* Set attribute HourCounter
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetHourCounter(JDFDuration value){
	SetAttribute(atr_HourCounter,value.DurationISO());
};
/**
* Get string attribute HourCounter
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoDeviceInfo::GetHourCounter() const {
	return GetAttribute(atr_HourCounter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidHourCounter(EnumValidationLevel level) const {
		return ValidAttribute(atr_HourCounter,AttributeType_duration,false);
	};
/**
* Set attribute IdleStartTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetIdleStartTime(JDFDate value){
	SetAttribute(atr_IdleStartTime,value.DateTimeISO());
};
/**
* Get string attribute IdleStartTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoDeviceInfo::GetIdleStartTime() const {
	return GetAttribute(atr_IdleStartTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidIdleStartTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_IdleStartTime,AttributeType_dateTime,false);
	};
/**
* Set attribute PowerOnTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetPowerOnTime(JDFDate value){
	SetAttribute(atr_PowerOnTime,value.DateTimeISO());
};
/**
* Get string attribute PowerOnTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoDeviceInfo::GetPowerOnTime() const {
	return GetAttribute(atr_PowerOnTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidPowerOnTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_PowerOnTime,AttributeType_dateTime,false);
	};
/**
* Set attribute ProductionCounter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetProductionCounter(double value){
	SetAttribute(atr_ProductionCounter,WString::valueOf(value));
};
/**
* Get double attribute ProductionCounter
* @return double the vaue of the attribute 
*/
	 double JDFAutoDeviceInfo::GetProductionCounter() const {
	return GetRealAttribute(atr_ProductionCounter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidProductionCounter(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductionCounter,AttributeType_double,false);
	};
/**
* Set attribute Speed
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetSpeed(double value){
	SetAttribute(atr_Speed,WString::valueOf(value));
};
/**
* Get double attribute Speed
* @return double the vaue of the attribute 
*/
	 double JDFAutoDeviceInfo::GetSpeed() const {
	return GetRealAttribute(atr_Speed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidSpeed(EnumValidationLevel level) const {
		return ValidAttribute(atr_Speed,AttributeType_double,false);
	};
/**
* Set attribute StatusDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetStatusDetails(const WString& value){
	SetAttribute(atr_StatusDetails,value);
};
/**
* Get string attribute StatusDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDeviceInfo::GetStatusDetails() const {
	return GetAttribute(atr_StatusDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidStatusDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_StatusDetails,AttributeType_shortString,false);
	};
/**
* Set attribute TotalProductionCounter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDeviceInfo::SetTotalProductionCounter(double value){
	SetAttribute(atr_TotalProductionCounter,WString::valueOf(value));
};
/**
* Get double attribute TotalProductionCounter
* @return double the vaue of the attribute 
*/
	 double JDFAutoDeviceInfo::GetTotalProductionCounter() const {
	return GetRealAttribute(atr_TotalProductionCounter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceInfo::ValidTotalProductionCounter(EnumValidationLevel level) const {
		return ValidAttribute(atr_TotalProductionCounter,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFActivity JDFAutoDeviceInfo::GetActivity(int iSkip)const{
	JDFActivity e=GetElement(elm_Activity,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActivity JDFAutoDeviceInfo::GetCreateActivity(int iSkip){
	JDFActivity e=GetCreateElement(elm_Activity,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActivity JDFAutoDeviceInfo::AppendActivity(){
	JDFActivity e=AppendElement(elm_Activity);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoDeviceInfo::GetDevice()const{
	JDFDevice e=GetElement(elm_Device);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoDeviceInfo::GetCreateDevice(){
	JDFDevice e=GetCreateElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoDeviceInfo::AppendDevice(){
	JDFDevice e=AppendElementN(elm_Device,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDeviceInfo::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoDeviceInfo::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoDeviceInfo::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoDeviceInfo::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDeviceInfo::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFJobPhase JDFAutoDeviceInfo::GetJobPhase(int iSkip)const{
	JDFJobPhase e=GetElement(elm_JobPhase,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobPhase JDFAutoDeviceInfo::GetCreateJobPhase(int iSkip){
	JDFJobPhase e=GetCreateElement(elm_JobPhase,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobPhase JDFAutoDeviceInfo::AppendJobPhase(){
	JDFJobPhase e=AppendElement(elm_JobPhase);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModuleStatus JDFAutoDeviceInfo::GetModuleStatus(int iSkip)const{
	JDFModuleStatus e=GetElement(elm_ModuleStatus,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModuleStatus JDFAutoDeviceInfo::GetCreateModuleStatus(int iSkip){
	JDFModuleStatus e=GetCreateElement(elm_ModuleStatus,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModuleStatus JDFAutoDeviceInfo::AppendModuleStatus(){
	JDFModuleStatus e=AppendElement(elm_ModuleStatus);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDeviceInfo::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Activity);

		for(i=0;i<nElem;i++){
			if (!GetActivity(i).IsValid(level)) {
				vElem.AppendUnique(elm_Activity);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Device);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Device);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDevice().IsValid(level)) {
				vElem.AppendUnique(elm_Device);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Employee);

		for(i=0;i<nElem;i++){
			if (!GetEmployee(i).IsValid(level)) {
				vElem.AppendUnique(elm_Employee);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_JobPhase);

		for(i=0;i<nElem;i++){
			if (!GetJobPhase(i).IsValid(level)) {
				vElem.AppendUnique(elm_JobPhase);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ModuleStatus);

		for(i=0;i<nElem;i++){
			if (!GetModuleStatus(i).IsValid(level)) {
				vElem.AppendUnique(elm_ModuleStatus);
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
	WString JDFAutoDeviceInfo::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Device";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDeviceInfo::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Activity,Device,Employee,JobPhase,ModuleStatus";
	};
}; // end namespace JDF
