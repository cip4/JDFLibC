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

 
#if !defined _JDFAutoDeliveryParams_H_
#define _JDFAutoDeliveryParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFCompany;
class JDFContact;
class JDFDrop;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDeliveryParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDeliveryParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDeliveryParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDeliveryParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDeliveryParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoDeliveryParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDeliveryParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDeliveryParams(){};
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
* Enumeration for attribute Transfer
*/

	enum EnumTransfer{Transfer_Unknown,Transfer_BuyerToPrinterDeliver,Transfer_BuyerToPrinterPickup,Transfer_PrinterToBuyerDeliver,Transfer_PrinterToBuyerPickup};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Earliest
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetEarliest(JDFDate value=JDFDate());
/**
* Get string attribute Earliest
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetEarliest() const;
/**
* Typesafe attribute validation of Earliest
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEarliest(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Method
*@param WString value: the value to set the attribute to
*/
	virtual void SetMethod(const WString& value);
/**
* Get string attribute Method
* @return WString the vaue of the attribute 
*/
	virtual WString GetMethod() const;
/**
* Typesafe attribute validation of Method
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMethod(EnumValidationLevel level=ValidationLevel_Complete) const;
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
/**
* Set attribute Required
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetRequired(JDFDate value=JDFDate());
/**
* Get string attribute Required
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetRequired() const;
/**
* Typesafe attribute validation of Required
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRequired(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ServiceLevel
*@param WString value: the value to set the attribute to
*/
	virtual void SetServiceLevel(const WString& value);
/**
* Get string attribute ServiceLevel
* @return WString the vaue of the attribute 
*/
	virtual WString GetServiceLevel() const;
/**
* Typesafe attribute validation of ServiceLevel
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidServiceLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Transfer
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TransferString();
/**
* Enumeration string for enum value
* @param EnumTransfer value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TransferString(EnumTransfer value);
/**
* Set attribute Transfer
* @param EnumTransfer value the value to set the attribute to
*/
	virtual void SetTransfer( EnumTransfer value);

/**
* Typesafe enumerated attribute Transfer
* @return EnumTransferthe enumeration value of the attribute
*/
	virtual EnumTransfer GetTransfer() const;

/**
* Typesafe attribute validation of Transfer
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidTransfer(EnumValidationLevel level=ValidationLevel_Complete) const;

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

/** Get Element Drop
* 
* @param int iSkip number of elements to skip
* @return JDFDrop The element
*/
	JDFDrop GetCreateDrop(int iSkip=0);

/**
* const get element Drop
* @param int iSkip number of elements to skip
* @return JDFDrop The element
*/
	JDFDrop GetDrop(int iSkip=0)const;
/**
* Append element Drop
 */
	JDFDrop AppendDrop();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDeliveryParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDeliveryParams_H_
