/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2016 The International Cooperation for the Integration of 
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
 *///EndCopyRight


///////////////////////////////////////////////////////////////////

 
#if !defined _JDFAutoPerson_H_
#define _JDFAutoPerson_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFAddress;
class JDFComChannel;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPerson : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPerson class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPerson should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPerson : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPerson():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoPerson(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPerson &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPerson(){};
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
* Set attribute AdditionalNames
*@param WString value: the value to set the attribute to
*/
	virtual void SetAdditionalNames(const WString& value);
/**
* Get string attribute AdditionalNames
* @return WString the vaue of the attribute 
*/
	virtual WString GetAdditionalNames() const;
/**
* Typesafe attribute validation of AdditionalNames
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAdditionalNames(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FamilyName
*@param WString value: the value to set the attribute to
*/
	virtual void SetFamilyName(const WString& value);
/**
* Get string attribute FamilyName
* @return WString the vaue of the attribute 
*/
	virtual WString GetFamilyName() const;
/**
* Typesafe attribute validation of FamilyName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFamilyName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FirstName
*@param WString value: the value to set the attribute to
*/
	virtual void SetFirstName(const WString& value);
/**
* Get string attribute FirstName
* @return WString the vaue of the attribute 
*/
	virtual WString GetFirstName() const;
/**
* Typesafe attribute validation of FirstName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFirstName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JobTitle
*@param WString value: the value to set the attribute to
*/
	virtual void SetJobTitle(const WString& value);
/**
* Get string attribute JobTitle
* @return WString the vaue of the attribute 
*/
	virtual WString GetJobTitle() const;
/**
* Typesafe attribute validation of JobTitle
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJobTitle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Languages
*@param vWString value: the value to set the attribute to
*/
	virtual void SetLanguages(const vWString& value);
/**
* Get string attribute Languages
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetLanguages() const;
/**
* Typesafe attribute validation of Languages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLanguages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NamePrefix
*@param WString value: the value to set the attribute to
*/
	virtual void SetNamePrefix(const WString& value);
/**
* Get string attribute NamePrefix
* @return WString the vaue of the attribute 
*/
	virtual WString GetNamePrefix() const;
/**
* Typesafe attribute validation of NamePrefix
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNamePrefix(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NameSuffix
*@param WString value: the value to set the attribute to
*/
	virtual void SetNameSuffix(const WString& value);
/**
* Get string attribute NameSuffix
* @return WString the vaue of the attribute 
*/
	virtual WString GetNameSuffix() const;
/**
* Typesafe attribute validation of NameSuffix
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNameSuffix(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Address
* 
* @return JDFAddress The element
*/
	JDFAddress GetCreateAddress();

/**
* const get element Address
*@return  JDFAddress The element
*/
	JDFAddress GetAddress()const;
/**
* Append element Address
 * 
*/
	JDFAddress AppendAddress();
/**
* create inter-resource link to refTarget
* @param JDFAddress& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefAddress(JDFAddress& refTarget);

/** Get Element ComChannel
* 
* @param int iSkip number of elements to skip
* @return JDFComChannel The element
*/
	JDFComChannel GetCreateComChannel(int iSkip=0);

/**
* const get element ComChannel
* @param int iSkip number of elements to skip
* @return JDFComChannel The element
*/
	JDFComChannel GetComChannel(int iSkip=0)const;
/**
* Append element ComChannel
 */
	JDFComChannel AppendComChannel();
/**
* create inter-resource link to refTarget
* @param JDFComChannel& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefComChannel(JDFComChannel& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPerson

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPerson_H_
