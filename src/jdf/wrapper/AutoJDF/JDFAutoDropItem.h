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

 
#if !defined _JDFAutoDropItem_H_
#define _JDFAutoDropItem_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFComponent;
class JDFExposedMedia;
class JDFInk;
class JDFMedia;
class JDFPallet;
class JDFRegisterRibbon;
class JDFStrap;
class JDFBundle;
class JDFDigitalMedia;
class JDFRollStand;
class JDFTool;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDropItem : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDropItem class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDropItem should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDropItem : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDropItem():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoDropItem(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDropItem &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDropItem(){};
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
* Set attribute ActualAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetActualAmount(int value);
/**
* Get integer attribute ActualAmount
* @return int the vaue of the attribute 
*/
	virtual int GetActualAmount() const;
/**
* Typesafe attribute validation of ActualAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidActualAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ActualTotalAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetActualTotalAmount(int value);
/**
* Get integer attribute ActualTotalAmount
* @return int the vaue of the attribute 
*/
	virtual int GetActualTotalAmount() const;
/**
* Typesafe attribute validation of ActualTotalAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidActualTotalAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute TotalAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetTotalAmount(int value);
/**
* Get integer attribute TotalAmount
* @return int the vaue of the attribute 
*/
	virtual int GetTotalAmount() const;
/**
* Typesafe attribute validation of TotalAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTotalAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TotalDimensions
*@param JDFShape value: the value to set the attribute to
*/
	virtual void SetTotalDimensions(const JDFShape& value);
/**
* Get string attribute TotalDimensions
* @return JDFShape the vaue of the attribute 
*/
	virtual JDFShape GetTotalDimensions() const;
/**
* Typesafe attribute validation of TotalDimensions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTotalDimensions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TotalVolume
*@param double value: the value to set the attribute to
*/
	virtual void SetTotalVolume(double value);
/**
* Get double attribute TotalVolume
* @return double the vaue of the attribute 
*/
	virtual double GetTotalVolume() const;
/**
* Typesafe attribute validation of TotalVolume
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTotalVolume(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TotalWeight
*@param double value: the value to set the attribute to
*/
	virtual void SetTotalWeight(double value);
/**
* Get double attribute TotalWeight
* @return double the vaue of the attribute 
*/
	virtual double GetTotalWeight() const;
/**
* Typesafe attribute validation of TotalWeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTotalWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Unit
*@param WString value: the value to set the attribute to
*/
	virtual void SetUnit(const WString& value);
/**
* Get string attribute Unit
* @return WString the vaue of the attribute 
*/
	virtual WString GetUnit() const;
/**
* Typesafe attribute validation of Unit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUnit(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Component
* 
* @param int iSkip number of elements to skip
* @return JDFComponent The element
*/
	JDFComponent GetCreateComponent(int iSkip=0);

/**
* const get element Component
* @param int iSkip number of elements to skip
* @return JDFComponent The element
*/
	JDFComponent GetComponent(int iSkip=0)const;
/**
* Append element Component
 */
	JDFComponent AppendComponent();
/**
* create inter-resource link to refTarget
* @param JDFComponent& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefComponent(JDFComponent& refTarget);

/** Get Element ExposedMedia
* 
* @param int iSkip number of elements to skip
* @return JDFExposedMedia The element
*/
	JDFExposedMedia GetCreateExposedMedia(int iSkip=0);

/**
* const get element ExposedMedia
* @param int iSkip number of elements to skip
* @return JDFExposedMedia The element
*/
	JDFExposedMedia GetExposedMedia(int iSkip=0)const;
/**
* Append element ExposedMedia
 */
	JDFExposedMedia AppendExposedMedia();
/**
* create inter-resource link to refTarget
* @param JDFExposedMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefExposedMedia(JDFExposedMedia& refTarget);

/** Get Element Ink
* 
* @param int iSkip number of elements to skip
* @return JDFInk The element
*/
	JDFInk GetCreateInk(int iSkip=0);

/**
* const get element Ink
* @param int iSkip number of elements to skip
* @return JDFInk The element
*/
	JDFInk GetInk(int iSkip=0)const;
/**
* Append element Ink
 */
	JDFInk AppendInk();
/**
* create inter-resource link to refTarget
* @param JDFInk& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefInk(JDFInk& refTarget);

/** Get Element Media
* 
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia(int iSkip=0);

/**
* const get element Media
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetMedia(int iSkip=0)const;
/**
* Append element Media
 */
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

/** Get Element Pallet
* 
* @param int iSkip number of elements to skip
* @return JDFPallet The element
*/
	JDFPallet GetCreatePallet(int iSkip=0);

/**
* const get element Pallet
* @param int iSkip number of elements to skip
* @return JDFPallet The element
*/
	JDFPallet GetPallet(int iSkip=0)const;
/**
* Append element Pallet
 */
	JDFPallet AppendPallet();
/**
* create inter-resource link to refTarget
* @param JDFPallet& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefPallet(JDFPallet& refTarget);

/** Get Element RegisterRibbon
* 
* @param int iSkip number of elements to skip
* @return JDFRegisterRibbon The element
*/
	JDFRegisterRibbon GetCreateRegisterRibbon(int iSkip=0);

/**
* const get element RegisterRibbon
* @param int iSkip number of elements to skip
* @return JDFRegisterRibbon The element
*/
	JDFRegisterRibbon GetRegisterRibbon(int iSkip=0)const;
/**
* Append element RegisterRibbon
 */
	JDFRegisterRibbon AppendRegisterRibbon();
/**
* create inter-resource link to refTarget
* @param JDFRegisterRibbon& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRegisterRibbon(JDFRegisterRibbon& refTarget);

/** Get Element Strap
* 
* @param int iSkip number of elements to skip
* @return JDFStrap The element
*/
	JDFStrap GetCreateStrap(int iSkip=0);

/**
* const get element Strap
* @param int iSkip number of elements to skip
* @return JDFStrap The element
*/
	JDFStrap GetStrap(int iSkip=0)const;
/**
* Append element Strap
 */
	JDFStrap AppendStrap();
/**
* create inter-resource link to refTarget
* @param JDFStrap& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefStrap(JDFStrap& refTarget);

/** Get Element Bundle
* 
* @param int iSkip number of elements to skip
* @return JDFBundle The element
*/
	JDFBundle GetCreateBundle(int iSkip=0);

/**
* const get element Bundle
* @param int iSkip number of elements to skip
* @return JDFBundle The element
*/
	JDFBundle GetBundle(int iSkip=0)const;
/**
* Append element Bundle
 */
	JDFBundle AppendBundle();
/**
* create inter-resource link to refTarget
* @param JDFBundle& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefBundle(JDFBundle& refTarget);

/** Get Element DigitalMedia
* 
* @param int iSkip number of elements to skip
* @return JDFDigitalMedia The element
*/
	JDFDigitalMedia GetCreateDigitalMedia(int iSkip=0);

/**
* const get element DigitalMedia
* @param int iSkip number of elements to skip
* @return JDFDigitalMedia The element
*/
	JDFDigitalMedia GetDigitalMedia(int iSkip=0)const;
/**
* Append element DigitalMedia
 */
	JDFDigitalMedia AppendDigitalMedia();
/**
* create inter-resource link to refTarget
* @param JDFDigitalMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDigitalMedia(JDFDigitalMedia& refTarget);

/** Get Element RollStand
* 
* @param int iSkip number of elements to skip
* @return JDFRollStand The element
*/
	JDFRollStand GetCreateRollStand(int iSkip=0);

/**
* const get element RollStand
* @param int iSkip number of elements to skip
* @return JDFRollStand The element
*/
	JDFRollStand GetRollStand(int iSkip=0)const;
/**
* Append element RollStand
 */
	JDFRollStand AppendRollStand();
/**
* create inter-resource link to refTarget
* @param JDFRollStand& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRollStand(JDFRollStand& refTarget);

/** Get Element Tool
* 
* @param int iSkip number of elements to skip
* @return JDFTool The element
*/
	JDFTool GetCreateTool(int iSkip=0);

/**
* const get element Tool
* @param int iSkip number of elements to skip
* @return JDFTool The element
*/
	JDFTool GetTool(int iSkip=0)const;
/**
* Append element Tool
 */
	JDFTool AppendTool();
/**
* create inter-resource link to refTarget
* @param JDFTool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefTool(JDFTool& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDropItem

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDropItem_H_
