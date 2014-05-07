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

 
#if !defined _JDFAutoQuery_H_
#define _JDFAutoQuery_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFMessage.h"
namespace JDF{
class JDFSubscription;
class JDFEmployee;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoQuery : public JDFMessage

*********************************************************************
*/
/**
* automatically generated header for JDFAutoQuery class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFQuery should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoQuery : public JDFMessage{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoQuery():JDFMessage(){};
/**
* copy ctor
*/
	inline JDFAutoQuery(const KElement & other):JDFMessage(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoQuery &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoQuery(){};
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
* Enumeration for attribute AcknowledgeType
*/

	enum EnumAcknowledgeType{AcknowledgeType_Unknown,AcknowledgeType_Received,AcknowledgeType_Applied,AcknowledgeType_Completed};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AcknowledgeFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetAcknowledgeFormat(const WString& value);
/**
* Get string attribute AcknowledgeFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetAcknowledgeFormat() const;
/**
* Typesafe attribute validation of AcknowledgeFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAcknowledgeFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AcknowledgeTemplate
*@param WString value: the value to set the attribute to
*/
	virtual void SetAcknowledgeTemplate(const WString& value);
/**
* Get string attribute AcknowledgeTemplate
* @return WString the vaue of the attribute 
*/
	virtual WString GetAcknowledgeTemplate() const;
/**
* Typesafe attribute validation of AcknowledgeTemplate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAcknowledgeTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AcknowledgeURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetAcknowledgeURL(const WString& value);
/**
* Get string attribute AcknowledgeURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetAcknowledgeURL() const;
/**
* Typesafe attribute validation of AcknowledgeURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAcknowledgeURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for AcknowledgeType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& AcknowledgeTypeString();
/**
* Enumeration string for enum value
* @param EnumAcknowledgeType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString AcknowledgeTypeString(EnumAcknowledgeType value);
/**
* Append value to the attribute AcknowledgeType
* @param EnumAcknowledgeType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddAcknowledgeType( EnumAcknowledgeType value);
/**
* Remove value from the attribute AcknowledgeType
* @param EnumAcknowledgeType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveAcknowledgeType( EnumAcknowledgeType value);
/**
* Typesafe enumerated attribute AcknowledgeType; defaults to Completed
* @return EnumAcknowledgeTypethe enumeration value of the attribute
*/
	virtual vint GetAcknowledgeType() const;
/**
* Set value of the attribute AcknowledgeType
* @param EnumAcknowledgeType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetAcknowledgeType( EnumAcknowledgeType value);
/**
* Set value of the attribute AcknowledgeType to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetAcknowledgeType( const vint& value);
/**
* Typesafe attribute validation of AcknowledgeType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidAcknowledgeType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Subscription
* 
* @param int iSkip number of elements to skip
* @return JDFSubscription The element
*/
	JDFSubscription GetCreateSubscription(int iSkip=0);

/**
* const get element Subscription
* @param int iSkip number of elements to skip
* @return JDFSubscription The element
*/
	JDFSubscription GetSubscription(int iSkip=0)const;
/**
* Append element Subscription
 */
	JDFSubscription AppendSubscription();

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
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoQuery

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoQuery_H_
