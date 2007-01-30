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

 
#if !defined _JDFAutoDeviceInfo_H_
#define _JDFAutoDeviceInfo_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFDevice;
class JDFEmployee;
class JDFJobPhase;
class JDFModuleStatus;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDeviceInfo : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDeviceInfo class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDeviceInfo should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDeviceInfo : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDeviceInfo():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoDeviceInfo(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDeviceInfo &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDeviceInfo(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid element names
*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

protected:
/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	virtual WString ValidNodeNames()const;
public:

/**
* Checks if the node is abstract, i.e. is not completely described
* utility used by GetUnknownElements, GetUnknownAttributes
* @return boolean: true, if the node is abstract
*/
	virtual bool IsAbstract()const;


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */

/**
* Enumeration for attribute DeviceCondition
*/

	enum EnumDeviceCondition{DeviceCondition_Unknown,DeviceCondition_OK,DeviceCondition_NeedsAttention,DeviceCondition_Failure,DeviceCondition_OffLine};
/**
* Enumeration for attribute DeviceOperationMode
*/

	enum EnumDeviceOperationMode{DeviceOperationMode_Unknown,DeviceOperationMode_Productive,DeviceOperationMode_NonProductive,DeviceOperationMode_Maintenance};
/**
* Enumeration for attribute DeviceStatus
*/

	enum EnumDeviceStatus{DeviceStatus_Unknown,DeviceStatus_Idle,DeviceStatus_Down,DeviceStatus_Setup,DeviceStatus_Running,DeviceStatus_Cleanup,DeviceStatus_Stopped};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute CounterUnit
*@param WString value: the value to set the attribute to
*/
	virtual void SetCounterUnit(const WString& value);
/**
* Get string attribute CounterUnit
* @return WString the vaue of the attribute 
*/
	virtual WString GetCounterUnit() const;
/**
* Typesafe attribute validation of CounterUnit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCounterUnit(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DeviceCondition
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DeviceConditionString();
/**
* Enumeration string for enum value
* @param EnumDeviceCondition value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DeviceConditionString(EnumDeviceCondition value);
/**
* Set attribute DeviceCondition
* @param EnumDeviceCondition value the value to set the attribute to
*/
	virtual void SetDeviceCondition( EnumDeviceCondition value);

/**
* Typesafe enumerated attribute DeviceCondition
* @return EnumDeviceConditionthe enumeration value of the attribute
*/
	virtual EnumDeviceCondition GetDeviceCondition() const;

/**
* Typesafe attribute validation of DeviceCondition
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDeviceCondition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeviceID(const WString& value);
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeviceID() const;
/**
* Typesafe attribute validation of DeviceID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeviceID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DeviceOperationMode
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DeviceOperationModeString();
/**
* Enumeration string for enum value
* @param EnumDeviceOperationMode value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DeviceOperationModeString(EnumDeviceOperationMode value);
/**
* Set attribute DeviceOperationMode
* @param EnumDeviceOperationMode value the value to set the attribute to
*/
	virtual void SetDeviceOperationMode( EnumDeviceOperationMode value);

/**
* Typesafe enumerated attribute DeviceOperationMode
* @return EnumDeviceOperationModethe enumeration value of the attribute
*/
	virtual EnumDeviceOperationMode GetDeviceOperationMode() const;

/**
* Typesafe attribute validation of DeviceOperationMode
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDeviceOperationMode(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DeviceStatus
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DeviceStatusString();
/**
* Enumeration string for enum value
* @param EnumDeviceStatus value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DeviceStatusString(EnumDeviceStatus value);
/**
* Set attribute DeviceStatus
* @param EnumDeviceStatus value the value to set the attribute to
*/
	virtual void SetDeviceStatus( EnumDeviceStatus value);

/**
* Typesafe enumerated attribute DeviceStatus
* @return EnumDeviceStatusthe enumeration value of the attribute
*/
	virtual EnumDeviceStatus GetDeviceStatus() const;

/**
* Typesafe attribute validation of DeviceStatus
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDeviceStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HourCounter
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetHourCounter(JDFDuration value=JDFDuration());
/**
* Get string attribute HourCounter
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetHourCounter() const;
/**
* Typesafe attribute validation of HourCounter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHourCounter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PowerOnTime
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetPowerOnTime(JDFDate value=JDFDate());
/**
* Get string attribute PowerOnTime
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetPowerOnTime() const;
/**
* Typesafe attribute validation of PowerOnTime
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPowerOnTime(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProductionCounter
*@param double value: the value to set the attribute to
*/
	virtual void SetProductionCounter(double value);
/**
* Get double attribute ProductionCounter
* @return double the vaue of the attribute 
*/
	virtual double GetProductionCounter() const;
/**
* Typesafe attribute validation of ProductionCounter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProductionCounter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Speed
*@param double value: the value to set the attribute to
*/
	virtual void SetSpeed(double value);
/**
* Get double attribute Speed
* @return double the vaue of the attribute 
*/
	virtual double GetSpeed() const;
/**
* Typesafe attribute validation of Speed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSpeed(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StatusDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetStatusDetails(const WString& value);
/**
* Get string attribute StatusDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetStatusDetails() const;
/**
* Typesafe attribute validation of StatusDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStatusDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TotalProductionCounter
*@param double value: the value to set the attribute to
*/
	virtual void SetTotalProductionCounter(double value);
/**
* Get double attribute TotalProductionCounter
* @return double the vaue of the attribute 
*/
	virtual double GetTotalProductionCounter() const;
/**
* Typesafe attribute validation of TotalProductionCounter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTotalProductionCounter(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Device
* 
* @return JDFDevice The element
*/
	JDFDevice GetCreateDevice();

/**
* const get element Device
*@return  JDFDevice The element
*/
	JDFDevice GetDevice()const;
/**
* Append element Device
 * 
*/
	JDFDevice AppendDevice();
/**
* create inter-resource link to refTarget
* @param JDFDevice& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDevice(JDFDevice& refTarget);

/** Get Element Employee
* 
* @param int iSkip number of elements to skip
* @return JDFEmployee The element
*/
	JDFEmployee GetCreateEmployee(int iSkip=0);

/**
* const get element Employee
* @param int iSkip number of elements to skip
* @return JDFEmployee The element
*/
	JDFEmployee GetEmployee(int iSkip=0)const;
/**
* Append element Employee
 */
	JDFEmployee AppendEmployee();
/**
* create inter-resource link to refTarget
* @param JDFEmployee& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefEmployee(JDFEmployee& refTarget);

/** Get Element JobPhase
* 
* @param int iSkip number of elements to skip
* @return JDFJobPhase The element
*/
	JDFJobPhase GetCreateJobPhase(int iSkip=0);

/**
* const get element JobPhase
* @param int iSkip number of elements to skip
* @return JDFJobPhase The element
*/
	JDFJobPhase GetJobPhase(int iSkip=0)const;
/**
* Append element JobPhase
 */
	JDFJobPhase AppendJobPhase();

/** Get Element ModuleStatus
* 
* @param int iSkip number of elements to skip
* @return JDFModuleStatus The element
*/
	JDFModuleStatus GetCreateModuleStatus(int iSkip=0);

/**
* const get element ModuleStatus
* @param int iSkip number of elements to skip
* @return JDFModuleStatus The element
*/
	JDFModuleStatus GetModuleStatus(int iSkip=0)const;
/**
* Append element ModuleStatus
 */
	JDFModuleStatus AppendModuleStatus();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDeviceInfo

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDeviceInfo_H_
