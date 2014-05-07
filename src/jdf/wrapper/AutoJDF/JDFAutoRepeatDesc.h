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

 
#if !defined _JDFAutoRepeatDesc_H_
#define _JDFAutoRepeatDesc_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRepeatDesc : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoRepeatDesc class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFRepeatDesc should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoRepeatDesc : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoRepeatDesc():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoRepeatDesc(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoRepeatDesc &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoRepeatDesc(){};
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
* Enumeration for attribute AllowedRotate
*/

	enum EnumAllowedRotate{AllowedRotate_Unknown,AllowedRotate_None,AllowedRotate_Grain,AllowedRotate_MinorGrain,AllowedRotate_CrossGrain};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for AllowedRotate
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& AllowedRotateString();
/**
* Enumeration string for enum value
* @param EnumAllowedRotate value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString AllowedRotateString(EnumAllowedRotate value);
/**
* Set attribute AllowedRotate
* @param EnumAllowedRotate value the value to set the attribute to
*/
	virtual void SetAllowedRotate( EnumAllowedRotate value);

/**
* Typesafe enumerated attribute AllowedRotate
* @return EnumAllowedRotatethe enumeration value of the attribute
*/
	virtual EnumAllowedRotate GetAllowedRotate() const;

/**
* Typesafe attribute validation of AllowedRotate
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidAllowedRotate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GutterX
*@param double value: the value to set the attribute to
*/
	virtual void SetGutterX(double value);
/**
* Get double attribute GutterX
* @return double the vaue of the attribute 
*/
	virtual double GetGutterX() const;
/**
* Typesafe attribute validation of GutterX
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGutterX(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GutterX2
*@param double value: the value to set the attribute to
*/
	virtual void SetGutterX2(double value);
/**
* Get double attribute GutterX2
* @return double the vaue of the attribute 
*/
	virtual double GetGutterX2() const;
/**
* Typesafe attribute validation of GutterX2
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGutterX2(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GutterY
*@param double value: the value to set the attribute to
*/
	virtual void SetGutterY(double value);
/**
* Get double attribute GutterY
* @return double the vaue of the attribute 
*/
	virtual double GetGutterY() const;
/**
* Typesafe attribute validation of GutterY
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGutterY(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GutterY2
*@param double value: the value to set the attribute to
*/
	virtual void SetGutterY2(double value);
/**
* Get double attribute GutterY2
* @return double the vaue of the attribute 
*/
	virtual double GetGutterY2() const;
/**
* Typesafe attribute validation of GutterY2
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGutterY2(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LayoutStyle
*@param vWString value: the value to set the attribute to
*/
	virtual void SetLayoutStyle(const vWString& value);
/**
* Get string attribute LayoutStyle
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetLayoutStyle() const;
/**
* Typesafe attribute validation of LayoutStyle
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayoutStyle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OrderQuantity
*@param int value: the value to set the attribute to
*/
	virtual void SetOrderQuantity(int value);
/**
* Get integer attribute OrderQuantity
* @return int the vaue of the attribute 
*/
	virtual int GetOrderQuantity() const;
/**
* Typesafe attribute validation of OrderQuantity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrderQuantity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UseBleeds
*@param bool value: the value to set the attribute to
*/
	virtual void SetUseBleeds(bool value);
/**
* Get bool attribute UseBleeds
* @return bool the vaue of the attribute 
*/
	virtual bool GetUseBleeds() const;
/**
* Typesafe attribute validation of UseBleeds
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUseBleeds(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoRepeatDesc

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoRepeatDesc_H_
