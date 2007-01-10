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

 
#if !defined _JDFAutoAddress_H_
#define _JDFAutoAddress_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFRefElement;
/*
*********************************************************************
class JDFAutoAddress : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoAddress class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFAddress should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoAddress : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoAddress():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoAddress(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoAddress &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoAddress(){};
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
* Set attribute City
*@param WString value: the value to set the attribute to
*/
	virtual void SetCity(const WString& value);
/**
* Get string attribute City
* @return WString the vaue of the attribute 
*/
	virtual WString GetCity() const;
/**
* Typesafe attribute validation of City
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Country
*@param WString value: the value to set the attribute to
*/
	virtual void SetCountry(const WString& value);
/**
* Get string attribute Country
* @return WString the vaue of the attribute 
*/
	virtual WString GetCountry() const;
/**
* Typesafe attribute validation of Country
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCountry(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CountryCode
*@param WString value: the value to set the attribute to
*/
	virtual void SetCountryCode(const WString& value);
/**
* Get string attribute CountryCode
* @return WString the vaue of the attribute 
*/
	virtual WString GetCountryCode() const;
/**
* Typesafe attribute validation of CountryCode
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCountryCode(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PostBox
*@param WString value: the value to set the attribute to
*/
	virtual void SetPostBox(const WString& value);
/**
* Get string attribute PostBox
* @return WString the vaue of the attribute 
*/
	virtual WString GetPostBox() const;
/**
* Typesafe attribute validation of PostBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPostBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PostalCode
*@param WString value: the value to set the attribute to
*/
	virtual void SetPostalCode(const WString& value);
/**
* Get string attribute PostalCode
* @return WString the vaue of the attribute 
*/
	virtual WString GetPostalCode() const;
/**
* Typesafe attribute validation of PostalCode
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPostalCode(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Region
*@param WString value: the value to set the attribute to
*/
	virtual void SetRegion(const WString& value);
/**
* Get string attribute Region
* @return WString the vaue of the attribute 
*/
	virtual WString GetRegion() const;
/**
* Typesafe attribute validation of Region
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRegion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Street
*@param WString value: the value to set the attribute to
*/
	virtual void SetStreet(const WString& value);
/**
* Get string attribute Street
* @return WString the vaue of the attribute 
*/
	virtual WString GetStreet() const;
/**
* Typesafe attribute validation of Street
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStreet(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ExtendedAddress
* 
* @return JDFElement The element
*/
	JDFElement GetCreateExtendedAddress();

/**
* const get element ExtendedAddress
*@return  JDFElement The element
*/
	JDFElement GetExtendedAddress()const;
/**
* Append element ExtendedAddress
 * 
*/
	JDFElement AppendExtendedAddress();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoAddress

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoAddress_H_
