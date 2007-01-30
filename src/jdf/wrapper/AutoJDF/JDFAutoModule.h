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

 
#if !defined _JDFAutoModule_H_
#define _JDFAutoModule_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoModule : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoModule class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFModule should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoModule : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoModule():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoModule(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoModule &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoModule(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

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
* Set attribute ModuleID
*@param WString value: the value to set the attribute to
*/
	virtual void SetModuleID(const WString& value);
/**
* Get string attribute ModuleID
* @return WString the vaue of the attribute 
*/
	virtual WString GetModuleID() const;
/**
* Typesafe attribute validation of ModuleID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleIndex
*@param int value: the value to set the attribute to
*/
	virtual void SetModuleIndex(int value);
/**
* Get integer attribute ModuleIndex
* @return int the vaue of the attribute 
*/
	virtual int GetModuleIndex() const;
/**
* Typesafe attribute validation of ModuleIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleType
*@param WString value: the value to set the attribute to
*/
	virtual void SetModuleType(const WString& value);
/**
* Get string attribute ModuleType
* @return WString the vaue of the attribute 
*/
	virtual WString GetModuleType() const;
/**
* Typesafe attribute validation of ModuleType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleType(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute SubModuleIndex
*@param int value: the value to set the attribute to
*/
	virtual void SetSubModuleIndex(int value);
/**
* Get integer attribute SubModuleIndex
* @return int the vaue of the attribute 
*/
	virtual int GetSubModuleIndex() const;
/**
* Typesafe attribute validation of SubModuleIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSubModuleIndex(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoModule

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoModule_H_
