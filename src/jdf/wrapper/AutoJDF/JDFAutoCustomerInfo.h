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

 
#if !defined _JDFAutoCustomerInfo_H_
#define _JDFAutoCustomerInfo_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFCompany;
class JDFContact;
class JDFCustomerMessage;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoCustomerInfo : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoCustomerInfo class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFCustomerInfo should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoCustomerInfo : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoCustomerInfo():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoCustomerInfo(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoCustomerInfo &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoCustomerInfo(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BillingCode
*@param WString value: the value to set the attribute to
*/
	virtual void SetBillingCode(const WString& value);
/**
* Get string attribute BillingCode
* @return WString the vaue of the attribute 
*/
	virtual WString GetBillingCode() const;
/**
* Typesafe attribute validation of BillingCode
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBillingCode(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CustomerID
*@param WString value: the value to set the attribute to
*/
	virtual void SetCustomerID(const WString& value);
/**
* Get string attribute CustomerID
* @return WString the vaue of the attribute 
*/
	virtual WString GetCustomerID() const;
/**
* Typesafe attribute validation of CustomerID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCustomerID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CustomerJobName
*@param WString value: the value to set the attribute to
*/
	virtual void SetCustomerJobName(const WString& value);
/**
* Get string attribute CustomerJobName
* @return WString the vaue of the attribute 
*/
	virtual WString GetCustomerJobName() const;
/**
* Typesafe attribute validation of CustomerJobName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCustomerJobName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CustomerOrderID
*@param WString value: the value to set the attribute to
*/
	virtual void SetCustomerOrderID(const WString& value);
/**
* Get string attribute CustomerOrderID
* @return WString the vaue of the attribute 
*/
	virtual WString GetCustomerOrderID() const;
/**
* Typesafe attribute validation of CustomerOrderID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCustomerOrderID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CustomerProjectID
*@param WString value: the value to set the attribute to
*/
	virtual void SetCustomerProjectID(const WString& value);
/**
* Get string attribute CustomerProjectID
* @return WString the vaue of the attribute 
*/
	virtual WString GetCustomerProjectID() const;
/**
* Typesafe attribute validation of CustomerProjectID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCustomerProjectID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute rRefs
*@param vWString value: the value to set the attribute to
*/
	virtual void SetrRefs(const vWString& value);
/**
* Get string attribute rRefs
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetrRefs() const;
/**
* Typesafe attribute validation of rRefs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidrRefs(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Company
* 
* @param int iSkip number of elements to skip
* @return JDFCompany The element
*/
	JDFCompany GetCreateCompany(int iSkip=0);

/**
* const get element Company
* @param int iSkip number of elements to skip
* @return JDFCompany The element
*/
	JDFCompany GetCompany(int iSkip=0)const;
/**
* Append element Company
 */
	JDFCompany AppendCompany();
/**
* create inter-resource link to refTarget
* @param JDFCompany& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefCompany(JDFCompany& refTarget);

/** Get Element Contact
* 
* @param int iSkip number of elements to skip
* @return JDFContact The element
*/
	JDFContact GetCreateContact(int iSkip=0);

/**
* const get element Contact
* @param int iSkip number of elements to skip
* @return JDFContact The element
*/
	JDFContact GetContact(int iSkip=0)const;
/**
* Append element Contact
 */
	JDFContact AppendContact();
/**
* create inter-resource link to refTarget
* @param JDFContact& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefContact(JDFContact& refTarget);

/** Get Element CustomerMessage
* 
* @param int iSkip number of elements to skip
* @return JDFCustomerMessage The element
*/
	JDFCustomerMessage GetCreateCustomerMessage(int iSkip=0);

/**
* const get element CustomerMessage
* @param int iSkip number of elements to skip
* @return JDFCustomerMessage The element
*/
	JDFCustomerMessage GetCustomerMessage(int iSkip=0)const;
/**
* Append element CustomerMessage
 */
	JDFCustomerMessage AppendCustomerMessage();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoCustomerInfo

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoCustomerInfo_H_
