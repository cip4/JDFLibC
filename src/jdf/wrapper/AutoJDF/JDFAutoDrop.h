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

 
#if !defined _JDFAutoDrop_H_
#define _JDFAutoDrop_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFCompany;
class JDFContact;
class JDFDropItem;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDrop : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDrop class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDrop should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDrop : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDrop():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoDrop(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDrop &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDrop(){};
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
* Enumeration for attribute Transfer
*/

	enum EnumTransfer{Transfer_Unknown,Transfer_BuyerToPrinterDeliver,Transfer_BuyerToPrinterPickup,Transfer_PrinterToBuyerDeliver,Transfer_PrinterToBuyerPickup};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

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
* Set attribute TrackingID
*@param WString value: the value to set the attribute to
*/
	virtual void SetTrackingID(const WString& value);
/**
* Get string attribute TrackingID
* @return WString the vaue of the attribute 
*/
	virtual WString GetTrackingID() const;
/**
* Typesafe attribute validation of TrackingID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrackingID(EnumValidationLevel level=ValidationLevel_Complete) const;
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

/** Get Element DropItem
* 
* @param int iSkip number of elements to skip
* @return JDFDropItem The element
*/
	JDFDropItem GetCreateDropItem(int iSkip=0);

/**
* const get element DropItem
* @param int iSkip number of elements to skip
* @return JDFDropItem The element
*/
	JDFDropItem GetDropItem(int iSkip=0)const;
/**
* Append element DropItem
 */
	JDFDropItem AppendDropItem();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDrop

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDrop_H_
