/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoBasicPreflightTest_H_
#define _JDFAutoBasicPreflightTest_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFPreflightArgument;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoBasicPreflightTest : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoBasicPreflightTest class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFBasicPreflightTest should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoBasicPreflightTest : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoBasicPreflightTest():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoBasicPreflightTest(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoBasicPreflightTest &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoBasicPreflightTest(){};
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
* Enumeration for attribute ListType
*/

	enum EnumListType{ListType_Unknown,ListType_CompleteList,ListType_CompleteOrderedList,ListType_ContainedList,ListType_List,ListType_OrderedList,ListType_OrderedRangeList,ListType_Range,ListType_RangeList,ListType_SingleValue,ListType_Span,ListType_UniqueList,ListType_UniqueRangeList,ListType_UniqueOrderedList,ListType_UniqueOrderedRangeList};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Classes
*@param vWString value: the value to set the attribute to
*/
	virtual void SetClasses(const vWString& value);
/**
* Get string attribute Classes
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetClasses() const;
/**
* Typesafe attribute validation of Classes
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClasses(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClassName
*@param WString value: the value to set the attribute to
*/
	virtual void SetClassName(const WString& value);
/**
* Get string attribute ClassName
* @return WString the vaue of the attribute 
*/
	virtual WString GetClassName() const;
/**
* Typesafe attribute validation of ClassName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClassName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DevNS
*@param WString value: the value to set the attribute to
*/
	virtual void SetDevNS(const WString& value);
/**
* Get string attribute DevNS
* @return WString the vaue of the attribute ; defaults to http://www.CIP4.org/JDFSchema_1_1
*/
	virtual WString GetDevNS() const;
/**
* Typesafe attribute validation of DevNS
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDevNS(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ListType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ListTypeString();
/**
* Enumeration string for enum value
* @param EnumListType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ListTypeString(EnumListType value);
/**
* Set attribute ListType
* @param EnumListType value the value to set the attribute to
*/
	virtual void SetListType( EnumListType value);

/**
* Typesafe enumerated attribute ListType; defaults to SingleValue
* @return EnumListTypethe enumeration value of the attribute
*/
	virtual EnumListType GetListType() const;

/**
* Typesafe attribute validation of ListType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidListType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxOccurs
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxOccurs(int value);
/**
* Get integer attribute MaxOccurs
* @return int the vaue of the attribute ; defaults to 1
*/
	virtual int GetMaxOccurs() const;
/**
* Typesafe attribute validation of MaxOccurs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxOccurs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinOccurs
*@param int value: the value to set the attribute to
*/
	virtual void SetMinOccurs(int value);
/**
* Get integer attribute MinOccurs
* @return int the vaue of the attribute ; defaults to 1
*/
	virtual int GetMinOccurs() const;
/**
* Typesafe attribute validation of MinOccurs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinOccurs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	virtual void SetName(const WString& value);
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	virtual WString GetName() const;
/**
* Typesafe attribute validation of Name
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidName(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element PreflightArgument
* 
* @param int iSkip number of elements to skip
* @return JDFPreflightArgument The element
*/
	JDFPreflightArgument GetCreatePreflightArgument(int iSkip=0);

/**
* const get element PreflightArgument
* @param int iSkip number of elements to skip
* @return JDFPreflightArgument The element
*/
	JDFPreflightArgument GetPreflightArgument(int iSkip=0)const;
/**
* Append element PreflightArgument
 */
	JDFPreflightArgument AppendPreflightArgument();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoBasicPreflightTest

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoBasicPreflightTest_H_
