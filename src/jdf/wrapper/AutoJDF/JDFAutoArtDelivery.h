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

 
#if !defined _JDFAutoArtDelivery_H_
#define _JDFAutoArtDelivery_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFCompany;
class JDFComponent;
class JDFContact;
class JDFDigitalMedia;
class JDFExposedMedia;
class JDFRunList;
class JDFScanParams;
class JDFTool;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoArtDelivery : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoArtDelivery class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFArtDelivery should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoArtDelivery : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoArtDelivery():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoArtDelivery(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoArtDelivery &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoArtDelivery(){};
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
* Enumeration for attribute PreflightStatus
*/

	enum EnumPreflightStatus{PreflightStatus_Unknown,PreflightStatus_NotPerformed,PreflightStatus_WithErrors,PreflightStatus_WithWarnings,PreflightStatus_WithoutErrors};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Amount
*@param int value: the value to set the attribute to
*/
	virtual void SetAmount(int value);
/**
* Get integer attribute Amount
* @return int the vaue of the attribute 
*/
	virtual int GetAmount() const;
/**
* Typesafe attribute validation of Amount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ArtDeliveryType
*@param WString value: the value to set the attribute to
*/
	virtual void SetArtDeliveryType(const WString& value);
/**
* Get string attribute ArtDeliveryType
* @return WString the vaue of the attribute 
*/
	virtual WString GetArtDeliveryType() const;
/**
* Typesafe attribute validation of ArtDeliveryType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidArtDeliveryType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasBleeds
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasBleeds(bool value);
/**
* Get bool attribute HasBleeds
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetHasBleeds() const;
/**
* Typesafe attribute validation of HasBleeds
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasBleeds(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IsTrapped
*@param bool value: the value to set the attribute to
*/
	virtual void SetIsTrapped(bool value);
/**
* Get bool attribute IsTrapped
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIsTrapped() const;
/**
* Typesafe attribute validation of IsTrapped
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIsTrapped(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageList
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetPageList(const JDFIntegerRangeList& value);
/**
* Get range attribute PageList
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetPageList() const;
/**
* Typesafe attribute validation of PageList
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreflightOutput
*@param WString value: the value to set the attribute to
*/
	virtual void SetPreflightOutput(const WString& value);
/**
* Get string attribute PreflightOutput
* @return WString the vaue of the attribute 
*/
	virtual WString GetPreflightOutput() const;
/**
* Typesafe attribute validation of PreflightOutput
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreflightOutput(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PreflightStatus
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PreflightStatusString();
/**
* Enumeration string for enum value
* @param EnumPreflightStatus value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PreflightStatusString(EnumPreflightStatus value);
/**
* Set attribute PreflightStatus
* @param EnumPreflightStatus value the value to set the attribute to
*/
	virtual void SetPreflightStatus( EnumPreflightStatus value);

/**
* Typesafe enumerated attribute PreflightStatus
* @return EnumPreflightStatusthe enumeration value of the attribute
*/
	virtual EnumPreflightStatus GetPreflightStatus() const;

/**
* Typesafe attribute validation of PreflightStatus
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPreflightStatus(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ArtDeliveryDate
* 
* @return JDFTimeSpan The element
*/
	JDFTimeSpan GetCreateArtDeliveryDate();

/**
* const get element ArtDeliveryDate
*@return  JDFTimeSpan The element
*/
	JDFTimeSpan GetArtDeliveryDate()const;
/**
* Append element ArtDeliveryDate
 * 
*/
	JDFTimeSpan AppendArtDeliveryDate();

/** Get Element ArtDeliveryDuration
* 
* @return JDFDurationSpan The element
*/
	JDFDurationSpan GetCreateArtDeliveryDuration();

/**
* const get element ArtDeliveryDuration
*@return  JDFDurationSpan The element
*/
	JDFDurationSpan GetArtDeliveryDuration()const;
/**
* Append element ArtDeliveryDuration
 * 
*/
	JDFDurationSpan AppendArtDeliveryDuration();

/** Get Element ArtHandling
* 
* @return JDFSpanArtHandling The element
*/
	JDFSpanArtHandling GetCreateArtHandling();

/**
* const get element ArtHandling
*@return  JDFSpanArtHandling The element
*/
	JDFSpanArtHandling GetArtHandling()const;
/**
* Append element ArtHandling
 * 
*/
	JDFSpanArtHandling AppendArtHandling();

/** Get Element DeliveryCharge
* 
* @return JDFSpanDeliveryCharge The element
*/
	JDFSpanDeliveryCharge GetCreateDeliveryCharge();

/**
* const get element DeliveryCharge
*@return  JDFSpanDeliveryCharge The element
*/
	JDFSpanDeliveryCharge GetDeliveryCharge()const;
/**
* Append element DeliveryCharge
 * 
*/
	JDFSpanDeliveryCharge AppendDeliveryCharge();

/** Get Element Method
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateMethod();

/**
* const get element Method
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetMethod()const;
/**
* Append element Method
 * 
*/
	JDFNameSpan AppendMethod();

/** Get Element ReturnMethod
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateReturnMethod();

/**
* const get element ReturnMethod
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetReturnMethod()const;
/**
* Append element ReturnMethod
 * 
*/
	JDFNameSpan AppendReturnMethod();

/** Get Element ServiceLevel
* 
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateServiceLevel();

/**
* const get element ServiceLevel
*@return  JDFStringSpan The element
*/
	JDFStringSpan GetServiceLevel()const;
/**
* Append element ServiceLevel
 * 
*/
	JDFStringSpan AppendServiceLevel();

/** Get Element Transfer
* 
* @return JDFSpanTransfer The element
*/
	JDFSpanTransfer GetCreateTransfer();

/**
* const get element Transfer
*@return  JDFSpanTransfer The element
*/
	JDFSpanTransfer GetTransfer()const;
/**
* Append element Transfer
 * 
*/
	JDFSpanTransfer AppendTransfer();

/** Get Element Company
* 
* @return JDFCompany The element
*/
	JDFCompany GetCreateCompany();

/**
* const get element Company
*@return  JDFCompany The element
*/
	JDFCompany GetCompany()const;
/**
* Append element Company
 * 
*/
	JDFCompany AppendCompany();
/**
* create inter-resource link to refTarget
* @param JDFCompany& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefCompany(JDFCompany& refTarget);

/** Get Element Component
* 
* @return JDFComponent The element
*/
	JDFComponent GetCreateComponent();

/**
* const get element Component
*@return  JDFComponent The element
*/
	JDFComponent GetComponent()const;
/**
* Append element Component
 * 
*/
	JDFComponent AppendComponent();
/**
* create inter-resource link to refTarget
* @param JDFComponent& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefComponent(JDFComponent& refTarget);

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

/** Get Element DigitalMedia
* 
* @return JDFDigitalMedia The element
*/
	JDFDigitalMedia GetCreateDigitalMedia();

/**
* const get element DigitalMedia
*@return  JDFDigitalMedia The element
*/
	JDFDigitalMedia GetDigitalMedia()const;
/**
* Append element DigitalMedia
 * 
*/
	JDFDigitalMedia AppendDigitalMedia();
/**
* create inter-resource link to refTarget
* @param JDFDigitalMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDigitalMedia(JDFDigitalMedia& refTarget);

/** Get Element ExposedMedia
* 
* @return JDFExposedMedia The element
*/
	JDFExposedMedia GetCreateExposedMedia();

/**
* const get element ExposedMedia
*@return  JDFExposedMedia The element
*/
	JDFExposedMedia GetExposedMedia()const;
/**
* Append element ExposedMedia
 * 
*/
	JDFExposedMedia AppendExposedMedia();
/**
* create inter-resource link to refTarget
* @param JDFExposedMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefExposedMedia(JDFExposedMedia& refTarget);

/** Get Element RunList
* 
* @return JDFRunList The element
*/
	JDFRunList GetCreateRunList();

/**
* const get element RunList
*@return  JDFRunList The element
*/
	JDFRunList GetRunList()const;
/**
* Append element RunList
 * 
*/
	JDFRunList AppendRunList();
/**
* create inter-resource link to refTarget
* @param JDFRunList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRunList(JDFRunList& refTarget);

/** Get Element ScanParams
* 
* @return JDFScanParams The element
*/
	JDFScanParams GetCreateScanParams();

/**
* const get element ScanParams
*@return  JDFScanParams The element
*/
	JDFScanParams GetScanParams()const;
/**
* Append element ScanParams
 * 
*/
	JDFScanParams AppendScanParams();
/**
* create inter-resource link to refTarget
* @param JDFScanParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefScanParams(JDFScanParams& refTarget);

/** Get Element Tool
* 
* @return JDFTool The element
*/
	JDFTool GetCreateTool();

/**
* const get element Tool
*@return  JDFTool The element
*/
	JDFTool GetTool()const;
/**
* Append element Tool
 * 
*/
	JDFTool AppendTool();
/**
* create inter-resource link to refTarget
* @param JDFTool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefTool(JDFTool& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoArtDelivery

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoArtDelivery_H_
