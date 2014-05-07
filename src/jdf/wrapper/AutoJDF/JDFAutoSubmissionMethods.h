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

 
#if !defined _JDFAutoSubmissionMethods_H_
#define _JDFAutoSubmissionMethods_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSubmissionMethods : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoSubmissionMethods class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFSubmissionMethods should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoSubmissionMethods : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoSubmissionMethods():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoSubmissionMethods(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoSubmissionMethods &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoSubmissionMethods(){};
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
* Enumeration for attribute Packaging
*/

	enum EnumPackaging{Packaging_Unknown,Packaging_MIME,Packaging_None};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute File
*@param bool value: the value to set the attribute to
*/
	virtual void SetFile(bool value);
/**
* Get bool attribute File
* @return bool the vaue of the attribute 
*/
	virtual bool GetFile() const;
/**
* Typesafe attribute validation of File
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFile(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HotFolder
*@param WString value: the value to set the attribute to
*/
	virtual void SetHotFolder(const WString& value);
/**
* Get string attribute HotFolder
* @return WString the vaue of the attribute 
*/
	virtual WString GetHotFolder() const;
/**
* Typesafe attribute validation of HotFolder
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHotFolder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HttpGet
*@param bool value: the value to set the attribute to
*/
	virtual void SetHttpGet(bool value);
/**
* Get bool attribute HttpGet
* @return bool the vaue of the attribute 
*/
	virtual bool GetHttpGet() const;
/**
* Typesafe attribute validation of HttpGet
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHttpGet(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Packaging
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PackagingString();
/**
* Enumeration string for enum value
* @param EnumPackaging value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PackagingString(EnumPackaging value);
/**
* Append value to the attribute Packaging
* @param EnumPackaging value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddPackaging( EnumPackaging value);
/**
* Remove value from the attribute Packaging
* @param EnumPackaging value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemovePackaging( EnumPackaging value);
/**
* Typesafe enumerated attribute Packaging
* @return EnumPackagingthe enumeration value of the attribute
*/
	virtual vint GetPackaging() const;
/**
* Set value of the attribute Packaging
* @param EnumPackaging value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetPackaging( EnumPackaging value);
/**
* Set value of the attribute Packaging to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetPackaging( const vint& value);
/**
* Typesafe attribute validation of Packaging
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPackaging(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MIME
*@param bool value: the value to set the attribute to
*/
	virtual void SetMIME(bool value);
/**
* Get bool attribute MIME
* @return bool the vaue of the attribute 
*/
	virtual bool GetMIME() const;
/**
* Typesafe attribute validation of MIME
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMIME(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute URLSchemes
*@param vWString value: the value to set the attribute to
*/
	virtual void SetURLSchemes(const vWString& value);
/**
* Get string attribute URLSchemes
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetURLSchemes() const;
/**
* Typesafe attribute validation of URLSchemes
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidURLSchemes(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoSubmissionMethods

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoSubmissionMethods_H_
