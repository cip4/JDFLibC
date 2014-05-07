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

 
#if !defined _JDFAutoDropIntent_H_
#define _JDFAutoDropIntent_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFCompany;
class JDFContact;
class JDFDropItemIntent;
class JDFPricing;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDropIntent : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDropIntent class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDropIntent should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDropIntent : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDropIntent():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoDropIntent(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDropIntent &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDropIntent(){};
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
* Set attribute AdditionalAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetAdditionalAmount(int value);
/**
* Get integer attribute AdditionalAmount
* @return int the vaue of the attribute 
*/
	virtual int GetAdditionalAmount() const;
/**
* Typesafe attribute validation of AdditionalAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAdditionalAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BuyerAccount
*@param WString value: the value to set the attribute to
*/
	virtual void SetBuyerAccount(const WString& value);
/**
* Get string attribute BuyerAccount
* @return WString the vaue of the attribute 
*/
	virtual WString GetBuyerAccount() const;
/**
* Typesafe attribute validation of BuyerAccount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBuyerAccount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DropID
*@param WString value: the value to set the attribute to
*/
	virtual void SetDropID(const WString& value);
/**
* Get string attribute DropID
* @return WString the vaue of the attribute 
*/
	virtual WString GetDropID() const;
/**
* Typesafe attribute validation of DropID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDropID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Pickup
*@param bool value: the value to set the attribute to
*/
	virtual void SetPickup(bool value);
/**
* Get bool attribute Pickup
* @return bool the vaue of the attribute 
*/
	virtual bool GetPickup() const;
/**
* Typesafe attribute validation of Pickup
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPickup(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Earliest
* 
* @param int iSkip number of elements to skip
* @return JDFTimeSpan The element
*/
	JDFTimeSpan GetCreateEarliest(int iSkip=0);

/**
* const get element Earliest
* @param int iSkip number of elements to skip
* @return JDFTimeSpan The element
*/
	JDFTimeSpan GetEarliest(int iSkip=0)const;
/**
* Append element Earliest
 */
	JDFTimeSpan AppendEarliest();

/** Get Element EarliestDuration
* 
* @param int iSkip number of elements to skip
* @return JDFDurationSpan The element
*/
	JDFDurationSpan GetCreateEarliestDuration(int iSkip=0);

/**
* const get element EarliestDuration
* @param int iSkip number of elements to skip
* @return JDFDurationSpan The element
*/
	JDFDurationSpan GetEarliestDuration(int iSkip=0)const;
/**
* Append element EarliestDuration
 */
	JDFDurationSpan AppendEarliestDuration();

/** Get Element Method
* 
* @param int iSkip number of elements to skip
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateMethod(int iSkip=0);

/**
* const get element Method
* @param int iSkip number of elements to skip
* @return JDFNameSpan The element
*/
	JDFNameSpan GetMethod(int iSkip=0)const;
/**
* Append element Method
 */
	JDFNameSpan AppendMethod();

/** Get Element Required
* 
* @param int iSkip number of elements to skip
* @return JDFTimeSpan The element
*/
	JDFTimeSpan GetCreateRequired(int iSkip=0);

/**
* const get element Required
* @param int iSkip number of elements to skip
* @return JDFTimeSpan The element
*/
	JDFTimeSpan GetRequired(int iSkip=0)const;
/**
* Append element Required
 */
	JDFTimeSpan AppendRequired();

/** Get Element RequiredDuration
* 
* @param int iSkip number of elements to skip
* @return JDFDurationSpan The element
*/
	JDFDurationSpan GetCreateRequiredDuration(int iSkip=0);

/**
* const get element RequiredDuration
* @param int iSkip number of elements to skip
* @return JDFDurationSpan The element
*/
	JDFDurationSpan GetRequiredDuration(int iSkip=0)const;
/**
* Append element RequiredDuration
 */
	JDFDurationSpan AppendRequiredDuration();

/** Get Element ReturnMethod
* 
* @param int iSkip number of elements to skip
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateReturnMethod(int iSkip=0);

/**
* const get element ReturnMethod
* @param int iSkip number of elements to skip
* @return JDFNameSpan The element
*/
	JDFNameSpan GetReturnMethod(int iSkip=0)const;
/**
* Append element ReturnMethod
 */
	JDFNameSpan AppendReturnMethod();

/** Get Element ServiceLevel
* 
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateServiceLevel(int iSkip=0);

/**
* const get element ServiceLevel
* @param int iSkip number of elements to skip
* @return JDFStringSpan The element
*/
	JDFStringSpan GetServiceLevel(int iSkip=0)const;
/**
* Append element ServiceLevel
 */
	JDFStringSpan AppendServiceLevel();

/** Get Element SurplusHandling
* 
* @param int iSkip number of elements to skip
* @return JDFSpanSurplusHandling The element
*/
	JDFSpanSurplusHandling GetCreateSurplusHandling(int iSkip=0);

/**
* const get element SurplusHandling
* @param int iSkip number of elements to skip
* @return JDFSpanSurplusHandling The element
*/
	JDFSpanSurplusHandling GetSurplusHandling(int iSkip=0)const;
/**
* Append element SurplusHandling
 */
	JDFSpanSurplusHandling AppendSurplusHandling();

/** Get Element Transfer
* 
* @param int iSkip number of elements to skip
* @return JDFSpanTransfer The element
*/
	JDFSpanTransfer GetCreateTransfer(int iSkip=0);

/**
* const get element Transfer
* @param int iSkip number of elements to skip
* @return JDFSpanTransfer The element
*/
	JDFSpanTransfer GetTransfer(int iSkip=0)const;
/**
* Append element Transfer
 */
	JDFSpanTransfer AppendTransfer();

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

/** Get Element DropItemIntent
* 
* @param int iSkip number of elements to skip
* @return JDFDropItemIntent The element
*/
	JDFDropItemIntent GetCreateDropItemIntent(int iSkip=0);

/**
* const get element DropItemIntent
* @param int iSkip number of elements to skip
* @return JDFDropItemIntent The element
*/
	JDFDropItemIntent GetDropItemIntent(int iSkip=0)const;
/**
* Append element DropItemIntent
 */
	JDFDropItemIntent AppendDropItemIntent();

/** Get Element Pricing
* 
* @param int iSkip number of elements to skip
* @return JDFPricing The element
*/
	JDFPricing GetCreatePricing(int iSkip=0);

/**
* const get element Pricing
* @param int iSkip number of elements to skip
* @return JDFPricing The element
*/
	JDFPricing GetPricing(int iSkip=0)const;
/**
* Append element Pricing
 */
	JDFPricing AppendPricing();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDropIntent

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDropIntent_H_
