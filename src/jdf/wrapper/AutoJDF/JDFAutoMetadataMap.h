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

 
#if !defined _JDFAutoMetadataMap_H_
#define _JDFAutoMetadataMap_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFQualityControlResult;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoMetadataMap : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoMetadataMap class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFMetadataMap should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoMetadataMap : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoMetadataMap():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoMetadataMap(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoMetadataMap &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoMetadataMap(){};
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
* Enumeration for attribute Context
*/

	enum EnumContext{Context_Unknown,Context_Set,Context_Document,Context_SubDoc0,Context_SubDoc1,Context_SubDoc2,Context_SubDoc3,Context_SubDoc4,Context_SubDoc5,Context_SubDoc6,Context_SubDoc7,Context_SubDoc8,Context_SubDoc9,Context_PagePool,Context_Page,Context_Object};
/**
* Enumeration for attribute DataType
*/

	enum EnumDataType{DataType_Unknown,DataType_string,DataType_integer,DataType_double,DataType_NMTOKEN,DataType_boolean,DataType_dateTime,DataType_duration,DataType_PartIDKeys};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for Context
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ContextString();
/**
* Enumeration string for enum value
* @param EnumContext value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ContextString(EnumContext value);
/**
* Set attribute Context
* @param EnumContext value the value to set the attribute to
*/
	virtual void SetContext( EnumContext value);

/**
* Typesafe enumerated attribute Context; defaults to PagePool
* @return EnumContextthe enumeration value of the attribute
*/
	virtual EnumContext GetContext() const;

/**
* Typesafe attribute validation of Context
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidContext(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DataType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DataTypeString();
/**
* Enumeration string for enum value
* @param EnumDataType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DataTypeString(EnumDataType value);
/**
* Set attribute DataType
* @param EnumDataType value the value to set the attribute to
*/
	virtual void SetDataType( EnumDataType value);

/**
* Typesafe enumerated attribute DataType
* @return EnumDataTypethe enumeration value of the attribute
*/
	virtual EnumDataType GetDataType() const;

/**
* Typesafe attribute validation of DataType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDataType(EnumValidationLevel level=ValidationLevel_Complete) const;
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
/**
* Set attribute ValueFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetValueFormat(const WString& value);
/**
* Get string attribute ValueFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetValueFormat() const;
/**
* Typesafe attribute validation of ValueFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidValueFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ValueTemplate
*@param WString value: the value to set the attribute to
*/
	virtual void SetValueTemplate(const WString& value);
/**
* Get string attribute ValueTemplate
* @return WString the vaue of the attribute 
*/
	virtual WString GetValueTemplate() const;
/**
* Typesafe attribute validation of ValueTemplate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidValueTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element QualityControlResult
* 
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetCreateQualityControlResult(int iSkip=0);

/**
* const get element QualityControlResult
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetQualityControlResult(int iSkip=0)const;
/**
* Append element QualityControlResult
 */
	JDFQualityControlResult AppendQualityControlResult();
/**
* create inter-resource link to refTarget
* @param JDFQualityControlResult& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefQualityControlResult(JDFQualityControlResult& refTarget);

/**
 definition of required elements in the JDF namespace
*/
	virtual WString RequiredElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoMetadataMap

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoMetadataMap_H_
