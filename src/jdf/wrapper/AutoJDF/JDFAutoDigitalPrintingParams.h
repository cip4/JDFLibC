/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoDigitalPrintingParams_H_
#define _JDFAutoDigitalPrintingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFComponent;
class JDFApprovalParams;
class JDFDisjointing;
class JDFInk;
class JDFMedia;
class JDFMediaSource;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDigitalPrintingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDigitalPrintingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDigitalPrintingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDigitalPrintingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDigitalPrintingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoDigitalPrintingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDigitalPrintingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDigitalPrintingParams(){};
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
* Enumeration for attribute Collate
*/

	enum EnumCollate{Collate_Unknown,Collate_None,Collate_Sheet,Collate_SheetAndSet,Collate_SheetSetAndJob,Collate_SystemSpecified};
/**
* Enumeration for attribute PrintQuality
*/

	enum EnumPrintQuality{PrintQuality_Unknown,PrintQuality_High,PrintQuality_Normal,PrintQuality_Draft,PrintQuality_SystemSpecified};
/**
* Enumeration for attribute PageDelivery
*/

	enum EnumPageDelivery{PageDelivery_Unknown,PageDelivery_FanFold,PageDelivery_SameOrderFaceUp,PageDelivery_SameOrderFaceDown,PageDelivery_ReverseOrderFaceUp,PageDelivery_ReverseOrderFaceDown,PageDelivery_SystemSpecified};
/**
* Enumeration for attribute PrintingType
*/

	enum EnumPrintingType{PrintingType_Unknown,PrintingType_SheetFed,PrintingType_WebFed,PrintingType_ContinuousFed,PrintingType_SystemSpecified};
/**
* Enumeration for attribute SheetLay
*/

	enum EnumSheetLay{SheetLay_Unknown,SheetLay_Left,SheetLay_Right,SheetLay_Center,SheetLay_SystemSpecified};
/**
* Enumeration for attribute Sides
*/

	enum EnumSides{Sides_Unknown,Sides_OneSidedBackFlipX,Sides_OneSidedBackFlipY,Sides_OneSidedFront,Sides_TwoSidedFlipX,Sides_TwoSidedFlipY};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute DirectProofAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetDirectProofAmount(int value);
/**
* Get integer attribute DirectProofAmount
* @return int the vaue of the attribute ; defaults to 0
*/
	virtual int GetDirectProofAmount() const;
/**
* Typesafe attribute validation of DirectProofAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDirectProofAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ManualFeed
*@param bool value: the value to set the attribute to
*/
	virtual void SetManualFeed(bool value);
/**
* Get bool attribute ManualFeed
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetManualFeed() const;
/**
* Typesafe attribute validation of ManualFeed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidManualFeed(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Collate
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CollateString();
/**
* Enumeration string for enum value
* @param EnumCollate value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CollateString(EnumCollate value);
/**
* Set attribute Collate
* @param EnumCollate value the value to set the attribute to
*/
	virtual void SetCollate( EnumCollate value);

/**
* Typesafe enumerated attribute Collate
* @return EnumCollatethe enumeration value of the attribute
*/
	virtual EnumCollate GetCollate() const;

/**
* Typesafe attribute validation of Collate
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCollate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutputBin
*@param WString value: the value to set the attribute to
*/
	virtual void SetOutputBin(const WString& value);
/**
* Get string attribute OutputBin
* @return WString the vaue of the attribute 
*/
	virtual WString GetOutputBin() const;
/**
* Typesafe attribute validation of OutputBin
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutputBin(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PrintQuality
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PrintQualityString();
/**
* Enumeration string for enum value
* @param EnumPrintQuality value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PrintQualityString(EnumPrintQuality value);
/**
* Set attribute PrintQuality
* @param EnumPrintQuality value the value to set the attribute to
*/
	virtual void SetPrintQuality( EnumPrintQuality value);

/**
* Typesafe enumerated attribute PrintQuality
* @return EnumPrintQualitythe enumeration value of the attribute
*/
	virtual EnumPrintQuality GetPrintQuality() const;

/**
* Typesafe attribute validation of PrintQuality
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPrintQuality(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NonPrintableMarginBottom
*@param double value: the value to set the attribute to
*/
	virtual void SetNonPrintableMarginBottom(double value);
/**
* Get double attribute NonPrintableMarginBottom
* @return double the vaue of the attribute 
*/
	virtual double GetNonPrintableMarginBottom() const;
/**
* Typesafe attribute validation of NonPrintableMarginBottom
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNonPrintableMarginBottom(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NonPrintableMarginLeft
*@param double value: the value to set the attribute to
*/
	virtual void SetNonPrintableMarginLeft(double value);
/**
* Get double attribute NonPrintableMarginLeft
* @return double the vaue of the attribute 
*/
	virtual double GetNonPrintableMarginLeft() const;
/**
* Typesafe attribute validation of NonPrintableMarginLeft
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNonPrintableMarginLeft(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NonPrintableMarginRight
*@param double value: the value to set the attribute to
*/
	virtual void SetNonPrintableMarginRight(double value);
/**
* Get double attribute NonPrintableMarginRight
* @return double the vaue of the attribute 
*/
	virtual double GetNonPrintableMarginRight() const;
/**
* Typesafe attribute validation of NonPrintableMarginRight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNonPrintableMarginRight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NonPrintableMarginTop
*@param double value: the value to set the attribute to
*/
	virtual void SetNonPrintableMarginTop(double value);
/**
* Get double attribute NonPrintableMarginTop
* @return double the vaue of the attribute 
*/
	virtual double GetNonPrintableMarginTop() const;
/**
* Typesafe attribute validation of NonPrintableMarginTop
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNonPrintableMarginTop(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PageDelivery
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PageDeliveryString();
/**
* Enumeration string for enum value
* @param EnumPageDelivery value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PageDeliveryString(EnumPageDelivery value);
/**
* Set attribute PageDelivery
* @param EnumPageDelivery value the value to set the attribute to
*/
	virtual void SetPageDelivery( EnumPageDelivery value);

/**
* Typesafe enumerated attribute PageDelivery
* @return EnumPageDeliverythe enumeration value of the attribute
*/
	virtual EnumPageDelivery GetPageDelivery() const;

/**
* Typesafe attribute validation of PageDelivery
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPageDelivery(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PrintingType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PrintingTypeString();
/**
* Enumeration string for enum value
* @param EnumPrintingType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PrintingTypeString(EnumPrintingType value);
/**
* Set attribute PrintingType
* @param EnumPrintingType value the value to set the attribute to
*/
	virtual void SetPrintingType( EnumPrintingType value);

/**
* Typesafe enumerated attribute PrintingType
* @return EnumPrintingTypethe enumeration value of the attribute
*/
	virtual EnumPrintingType GetPrintingType() const;

/**
* Typesafe attribute validation of PrintingType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPrintingType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SheetLay
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SheetLayString();
/**
* Enumeration string for enum value
* @param EnumSheetLay value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SheetLayString(EnumSheetLay value);
/**
* Set attribute SheetLay
* @param EnumSheetLay value the value to set the attribute to
*/
	virtual void SetSheetLay( EnumSheetLay value);

/**
* Typesafe enumerated attribute SheetLay
* @return EnumSheetLaythe enumeration value of the attribute
*/
	virtual EnumSheetLay GetSheetLay() const;

/**
* Typesafe attribute validation of SheetLay
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSheetLay(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Sides
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SidesString();
/**
* Enumeration string for enum value
* @param EnumSides value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SidesString(EnumSides value);
/**
* Set attribute Sides
* @param EnumSides value the value to set the attribute to
*/
	virtual void SetSides( EnumSides value);

/**
* Typesafe enumerated attribute Sides
* @return EnumSidesthe enumeration value of the attribute
*/
	virtual EnumSides GetSides() const;

/**
* Typesafe attribute validation of Sides
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSides(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


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

/** Get Element ApprovalParams
* 
* @return JDFApprovalParams The element
*/
	JDFApprovalParams GetCreateApprovalParams();

/**
* const get element ApprovalParams
*@return  JDFApprovalParams The element
*/
	JDFApprovalParams GetApprovalParams()const;
/**
* Append element ApprovalParams
 * 
*/
	JDFApprovalParams AppendApprovalParams();
/**
* create inter-resource link to refTarget
* @param JDFApprovalParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefApprovalParams(JDFApprovalParams& refTarget);

/** Get Element Disjointing
* 
* @return JDFDisjointing The element
*/
	JDFDisjointing GetCreateDisjointing();

/**
* const get element Disjointing
*@return  JDFDisjointing The element
*/
	JDFDisjointing GetDisjointing()const;
/**
* Append element Disjointing
 * 
*/
	JDFDisjointing AppendDisjointing();

/** Get Element Ink
* 
* @return JDFInk The element
*/
	JDFInk GetCreateInk();

/**
* const get element Ink
*@return  JDFInk The element
*/
	JDFInk GetInk()const;
/**
* Append element Ink
 * 
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
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia();

/**
* const get element Media
*@return  JDFMedia The element
*/
	JDFMedia GetMedia()const;
/**
* Append element Media
 * 
*/
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

/** Get Element MediaSource
* 
* @return JDFMediaSource The element
*/
	JDFMediaSource GetCreateMediaSource();

/**
* const get element MediaSource
*@return  JDFMediaSource The element
*/
	JDFMediaSource GetMediaSource()const;
/**
* Append element MediaSource
 * 
*/
	JDFMediaSource AppendMediaSource();
/**
* create inter-resource link to refTarget
* @param JDFMediaSource& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMediaSource(JDFMediaSource& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDigitalPrintingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDigitalPrintingParams_H_
