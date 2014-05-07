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

 
#if !defined _JDFAutoChangedAttribute_H_
#define _JDFAutoChangedAttribute_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoChangedAttribute : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoChangedAttribute class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFChangedAttribute should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoChangedAttribute : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoChangedAttribute():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoChangedAttribute(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoChangedAttribute &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoChangedAttribute(){};
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
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AttributeName
*@param WString value: the value to set the attribute to
*/
	virtual void SetAttributeName(const WString& value);
/**
* Get string attribute AttributeName
* @return WString the vaue of the attribute 
*/
	virtual WString GetAttributeName() const;
/**
* Typesafe attribute validation of AttributeName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAttributeName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ElementID
*@param WString value: the value to set the attribute to
*/
	virtual void SetElementID(const WString& value);
/**
* Get string attribute ElementID
* @return WString the vaue of the attribute 
*/
	virtual WString GetElementID() const;
/**
* Typesafe attribute validation of ElementID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidElementID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ElementType
*@param WString value: the value to set the attribute to
*/
	virtual void SetElementType(const WString& value);
/**
* Get string attribute ElementType
* @return WString the vaue of the attribute 
*/
	virtual WString GetElementType() const;
/**
* Typesafe attribute validation of ElementType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidElementType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OldValue
*@param WString value: the value to set the attribute to
*/
	virtual void SetOldValue(const WString& value);
/**
* Get string attribute OldValue
* @return WString the vaue of the attribute 
*/
	virtual WString GetOldValue() const;
/**
* Typesafe attribute validation of OldValue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOldValue(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NewValue
*@param WString value: the value to set the attribute to
*/
	virtual void SetNewValue(const WString& value);
/**
* Get string attribute NewValue
* @return WString the vaue of the attribute 
*/
	virtual WString GetNewValue() const;
/**
* Typesafe attribute validation of NewValue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNewValue(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoChangedAttribute

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoChangedAttribute_H_
