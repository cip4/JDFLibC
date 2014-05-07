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

 
#if !defined _JDFAutoDevice_H_
#define _JDFAutoDevice_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFCostCenter;
class JDFDeviceCap;
class JDFIconList;
class JDFModule;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDevice : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDevice class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDevice should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDevice : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDevice():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoDevice(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDevice &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDevice(){};
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
 * Typesafe attribute validation of Class
* @return true if class is valid
*/
virtual bool ValidClass(EnumValidationLevel level) const;

/** 
 * Typesafe initialization
 * @return true if succcessful
*/
virtual bool init();


/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute DeviceClass
*@param vWString value: the value to set the attribute to
*/
	virtual void SetDeviceClass(const vWString& value);
/**
* Get string attribute DeviceClass
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetDeviceClass() const;
/**
* Typesafe attribute validation of DeviceClass
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeviceClass(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeviceFamily
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeviceFamily(const WString& value);
/**
* Get string attribute DeviceFamily
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeviceFamily() const;
/**
* Typesafe attribute validation of DeviceFamily
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeviceFamily(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute DeviceType
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeviceType(const WString& value);
/**
* Get string attribute DeviceType
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeviceType() const;
/**
* Typesafe attribute validation of DeviceType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeviceType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Directory
*@param WString value: the value to set the attribute to
*/
	virtual void SetDirectory(const WString& value);
/**
* Get string attribute Directory
* @return WString the vaue of the attribute 
*/
	virtual WString GetDirectory() const;
/**
* Typesafe attribute validation of Directory
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDirectory(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FriendlyName
*@param WString value: the value to set the attribute to
*/
	virtual void SetFriendlyName(const WString& value);
/**
* Get string attribute FriendlyName
* @return WString the vaue of the attribute 
*/
	virtual WString GetFriendlyName() const;
/**
* Typesafe attribute validation of FriendlyName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFriendlyName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ICSVersions
*@param vWString value: the value to set the attribute to
*/
	virtual void SetICSVersions(const vWString& value);
/**
* Get string attribute ICSVersions
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetICSVersions() const;
/**
* Typesafe attribute validation of ICSVersions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidICSVersions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JDFErrorURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetJDFErrorURL(const WString& value);
/**
* Get string attribute JDFErrorURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetJDFErrorURL() const;
/**
* Typesafe attribute validation of JDFErrorURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJDFErrorURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JDFInputURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetJDFInputURL(const WString& value);
/**
* Get string attribute JDFInputURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetJDFInputURL() const;
/**
* Typesafe attribute validation of JDFInputURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJDFInputURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JDFOutputURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetJDFOutputURL(const WString& value);
/**
* Get string attribute JDFOutputURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetJDFOutputURL() const;
/**
* Typesafe attribute validation of JDFOutputURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJDFOutputURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JDFVersions
*@param WString value: the value to set the attribute to
*/
	virtual void SetJDFVersions(const WString& value);
/**
* Get string attribute JDFVersions
* @return WString the vaue of the attribute 
*/
	virtual WString GetJDFVersions() const;
/**
* Typesafe attribute validation of JDFVersions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJDFVersions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JMFSenderID
*@param WString value: the value to set the attribute to
*/
	virtual void SetJMFSenderID(const WString& value);
/**
* Get string attribute JMFSenderID
* @return WString the vaue of the attribute 
*/
	virtual WString GetJMFSenderID() const;
/**
* Typesafe attribute validation of JMFSenderID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJMFSenderID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JMFURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetJMFURL(const WString& value);
/**
* Get string attribute JMFURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetJMFURL() const;
/**
* Typesafe attribute validation of JMFURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJMFURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute KnownLocalizations
*@param vWString value: the value to set the attribute to
*/
	virtual void SetKnownLocalizations(const vWString& value);
/**
* Get string attribute KnownLocalizations
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetKnownLocalizations() const;
/**
* Typesafe attribute validation of KnownLocalizations
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidKnownLocalizations(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Manufacturer
*@param WString value: the value to set the attribute to
*/
	virtual void SetManufacturer(const WString& value);
/**
* Get string attribute Manufacturer
* @return WString the vaue of the attribute 
*/
	virtual WString GetManufacturer() const;
/**
* Typesafe attribute validation of Manufacturer
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidManufacturer(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ManufacturerURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetManufacturerURL(const WString& value);
/**
* Get string attribute ManufacturerURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetManufacturerURL() const;
/**
* Typesafe attribute validation of ManufacturerURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidManufacturerURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModelDescription
*@param WString value: the value to set the attribute to
*/
	virtual void SetModelDescription(const WString& value);
/**
* Get string attribute ModelDescription
* @return WString the vaue of the attribute 
*/
	virtual WString GetModelDescription() const;
/**
* Typesafe attribute validation of ModelDescription
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModelDescription(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModelName
*@param WString value: the value to set the attribute to
*/
	virtual void SetModelName(const WString& value);
/**
* Get string attribute ModelName
* @return WString the vaue of the attribute 
*/
	virtual WString GetModelName() const;
/**
* Typesafe attribute validation of ModelName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModelName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModelNumber
*@param WString value: the value to set the attribute to
*/
	virtual void SetModelNumber(const WString& value);
/**
* Get string attribute ModelNumber
* @return WString the vaue of the attribute 
*/
	virtual WString GetModelNumber() const;
/**
* Typesafe attribute validation of ModelNumber
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModelNumber(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModelURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetModelURL(const WString& value);
/**
* Get string attribute ModelURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetModelURL() const;
/**
* Typesafe attribute validation of ModelURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModelURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SerialNumber
*@param WString value: the value to set the attribute to
*/
	virtual void SetSerialNumber(const WString& value);
/**
* Get string attribute SerialNumber
* @return WString the vaue of the attribute 
*/
	virtual WString GetSerialNumber() const;
/**
* Typesafe attribute validation of SerialNumber
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSerialNumber(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PresentationURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetPresentationURL(const WString& value);
/**
* Get string attribute PresentationURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetPresentationURL() const;
/**
* Typesafe attribute validation of PresentationURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPresentationURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SecureJMFURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetSecureJMFURL(const WString& value);
/**
* Get string attribute SecureJMFURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetSecureJMFURL() const;
/**
* Typesafe attribute validation of SecureJMFURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSecureJMFURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UPC
*@param WString value: the value to set the attribute to
*/
	virtual void SetUPC(const WString& value);
/**
* Get string attribute UPC
* @return WString the vaue of the attribute 
*/
	virtual WString GetUPC() const;
/**
* Typesafe attribute validation of UPC
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUPC(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element CostCenter
* 
* @return JDFCostCenter The element
*/
	JDFCostCenter GetCreateCostCenter();

/**
* const get element CostCenter
*@return  JDFCostCenter The element
*/
	JDFCostCenter GetCostCenter()const;
/**
* Append element CostCenter
 * 
*/
	JDFCostCenter AppendCostCenter();

/** Get Element DeviceCap
* 
* @param int iSkip number of elements to skip
* @return JDFDeviceCap The element
*/
	JDFDeviceCap GetCreateDeviceCap(int iSkip=0);

/**
* const get element DeviceCap
* @param int iSkip number of elements to skip
* @return JDFDeviceCap The element
*/
	JDFDeviceCap GetDeviceCap(int iSkip=0)const;
/**
* Append element DeviceCap
 */
	JDFDeviceCap AppendDeviceCap();

/** Get Element IconList
* 
* @return JDFIconList The element
*/
	JDFIconList GetCreateIconList();

/**
* const get element IconList
*@return  JDFIconList The element
*/
	JDFIconList GetIconList()const;
/**
* Append element IconList
 * 
*/
	JDFIconList AppendIconList();

/** Get Element Module
* 
* @param int iSkip number of elements to skip
* @return JDFModule The element
*/
	JDFModule GetCreateModule(int iSkip=0);

/**
* const get element Module
* @param int iSkip number of elements to skip
* @return JDFModule The element
*/
	JDFModule GetModule(int iSkip=0)const;
/**
* Append element Module
 */
	JDFModule AppendModule();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDevice

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDevice_H_
