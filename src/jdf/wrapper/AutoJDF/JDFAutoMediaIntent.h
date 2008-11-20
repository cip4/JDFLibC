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

 
#if !defined _JDFAutoMediaIntent_H_
#define _JDFAutoMediaIntent_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFIntentResource.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFMediaLayers;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoMediaIntent : public JDFIntentResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoMediaIntent class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFMediaIntent should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoMediaIntent : public JDFIntentResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoMediaIntent():JDFIntentResource(){};
/**
* copy ctor
*/
	inline JDFAutoMediaIntent(const KElement & other):JDFIntentResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoMediaIntent &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoMediaIntent(){};
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
* Set attribute PrePrinted
*@param bool value: the value to set the attribute to
*/
	virtual void SetPrePrinted(bool value);
/**
* Get bool attribute PrePrinted
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPrePrinted() const;
/**
* Typesafe attribute validation of PrePrinted
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPrePrinted(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MediaSetCount
*@param int value: the value to set the attribute to
*/
	virtual void SetMediaSetCount(int value);
/**
* Get integer attribute MediaSetCount
* @return int the vaue of the attribute 
*/
	virtual int GetMediaSetCount() const;
/**
* Typesafe attribute validation of MediaSetCount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMediaSetCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UserMediaType
*@param WString value: the value to set the attribute to
*/
	virtual void SetUserMediaType(const WString& value);
/**
* Get string attribute UserMediaType
* @return WString the vaue of the attribute 
*/
	virtual WString GetUserMediaType() const;
/**
* Typesafe attribute validation of UserMediaType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUserMediaType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BackCoatings
* 
* @return JDFSpanCoatings The element
*/
	JDFSpanCoatings GetCreateBackCoatings();

/**
* const get element BackCoatings
*@return  JDFSpanCoatings The element
*/
	JDFSpanCoatings GetBackCoatings()const;
/**
* Append element BackCoatings
 * 
*/
	JDFSpanCoatings AppendBackCoatings();

/** Get Element Brightness
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateBrightness();

/**
* const get element Brightness
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetBrightness()const;
/**
* Append element Brightness
 * 
*/
	JDFNumberSpan AppendBrightness();

/** Get Element BuyerSupplied
* 
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateBuyerSupplied();

/**
* const get element BuyerSupplied
*@return  JDFOptionSpan The element
*/
	JDFOptionSpan GetBuyerSupplied()const;
/**
* Append element BuyerSupplied
 * 
*/
	JDFOptionSpan AppendBuyerSupplied();

/** Get Element Dimensions
* 
* @return JDFXYPairSpan The element
*/
	JDFXYPairSpan GetCreateDimensions();

/**
* const get element Dimensions
*@return  JDFXYPairSpan The element
*/
	JDFXYPairSpan GetDimensions()const;
/**
* Append element Dimensions
 * 
*/
	JDFXYPairSpan AppendDimensions();

/** Get Element Flute
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateFlute();

/**
* const get element Flute
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetFlute()const;
/**
* Append element Flute
 * 
*/
	JDFNameSpan AppendFlute();

/** Get Element FluteDirection
* 
* @return JDFSpanFluteDirection The element
*/
	JDFSpanFluteDirection GetCreateFluteDirection();

/**
* const get element FluteDirection
*@return  JDFSpanFluteDirection The element
*/
	JDFSpanFluteDirection GetFluteDirection()const;
/**
* Append element FluteDirection
 * 
*/
	JDFSpanFluteDirection AppendFluteDirection();

/** Get Element FrontCoatings
* 
* @return JDFSpanCoatings The element
*/
	JDFSpanCoatings GetCreateFrontCoatings();

/**
* const get element FrontCoatings
*@return  JDFSpanCoatings The element
*/
	JDFSpanCoatings GetFrontCoatings()const;
/**
* Append element FrontCoatings
 * 
*/
	JDFSpanCoatings AppendFrontCoatings();

/** Get Element Grade
* 
* @return JDFIntegerSpan The element
*/
	JDFIntegerSpan GetCreateGrade();

/**
* const get element Grade
*@return  JDFIntegerSpan The element
*/
	JDFIntegerSpan GetGrade()const;
/**
* Append element Grade
 * 
*/
	JDFIntegerSpan AppendGrade();

/** Get Element GrainDirection
* 
* @return JDFSpanGrainDirection The element
*/
	JDFSpanGrainDirection GetCreateGrainDirection();

/**
* const get element GrainDirection
*@return  JDFSpanGrainDirection The element
*/
	JDFSpanGrainDirection GetGrainDirection()const;
/**
* Append element GrainDirection
 * 
*/
	JDFSpanGrainDirection AppendGrainDirection();

/** Get Element HoleCount
* 
* @return JDFIntegerSpan The element
*/
	JDFIntegerSpan GetCreateHoleCount();

/**
* const get element HoleCount
*@return  JDFIntegerSpan The element
*/
	JDFIntegerSpan GetHoleCount()const;
/**
* Append element HoleCount
 * 
*/
	JDFIntegerSpan AppendHoleCount();

/** Get Element HoleType
* 
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateHoleType();

/**
* const get element HoleType
*@return  JDFStringSpan The element
*/
	JDFStringSpan GetHoleType()const;
/**
* Append element HoleType
 * 
*/
	JDFStringSpan AppendHoleType();

/** Get Element MediaColor
* 
* @return JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetCreateMediaColor();

/**
* const get element MediaColor
*@return  JDFSpanNamedColor The element
*/
	JDFSpanNamedColor GetMediaColor()const;
/**
* Append element MediaColor
 * 
*/
	JDFSpanNamedColor AppendMediaColor();

/** Get Element MediaColorDetails
* 
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateMediaColorDetails();

/**
* const get element MediaColorDetails
*@return  JDFStringSpan The element
*/
	JDFStringSpan GetMediaColorDetails()const;
/**
* Append element MediaColorDetails
 * 
*/
	JDFStringSpan AppendMediaColorDetails();

/** Get Element MediaQuality
* 
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateMediaQuality();

/**
* const get element MediaQuality
*@return  JDFStringSpan The element
*/
	JDFStringSpan GetMediaQuality()const;
/**
* Append element MediaQuality
 * 
*/
	JDFStringSpan AppendMediaQuality();

/** Get Element MediaType
* 
* @return JDFSpanMediaType The element
*/
	JDFSpanMediaType GetCreateMediaType();

/**
* const get element MediaType
*@return  JDFSpanMediaType The element
*/
	JDFSpanMediaType GetMediaType()const;
/**
* Append element MediaType
 * 
*/
	JDFSpanMediaType AppendMediaType();

/** Get Element MediaTypeDetails
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateMediaTypeDetails();

/**
* const get element MediaTypeDetails
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetMediaTypeDetails()const;
/**
* Append element MediaTypeDetails
 * 
*/
	JDFNameSpan AppendMediaTypeDetails();

/** Get Element MediaUnit
* 
* @return JDFSpanMediaUnit The element
*/
	JDFSpanMediaUnit GetCreateMediaUnit();

/**
* const get element MediaUnit
*@return  JDFSpanMediaUnit The element
*/
	JDFSpanMediaUnit GetMediaUnit()const;
/**
* Append element MediaUnit
 * 
*/
	JDFSpanMediaUnit AppendMediaUnit();

/** Get Element Opacity
* 
* @return JDFSpanOpacity The element
*/
	JDFSpanOpacity GetCreateOpacity();

/**
* const get element Opacity
*@return  JDFSpanOpacity The element
*/
	JDFSpanOpacity GetOpacity()const;
/**
* Append element Opacity
 * 
*/
	JDFSpanOpacity AppendOpacity();

/** Get Element OpacityLevel
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateOpacityLevel();

/**
* const get element OpacityLevel
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetOpacityLevel()const;
/**
* Append element OpacityLevel
 * 
*/
	JDFNumberSpan AppendOpacityLevel();

/** Get Element Recycled
* 
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateRecycled();

/**
* const get element Recycled
*@return  JDFOptionSpan The element
*/
	JDFOptionSpan GetRecycled()const;
/**
* Append element Recycled
 * 
*/
	JDFOptionSpan AppendRecycled();

/** Get Element RecycledPercentage
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateRecycledPercentage();

/**
* const get element RecycledPercentage
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetRecycledPercentage()const;
/**
* Append element RecycledPercentage
 * 
*/
	JDFNumberSpan AppendRecycledPercentage();

/** Get Element StockBrand
* 
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateStockBrand();

/**
* const get element StockBrand
*@return  JDFStringSpan The element
*/
	JDFStringSpan GetStockBrand()const;
/**
* Append element StockBrand
 * 
*/
	JDFStringSpan AppendStockBrand();

/** Get Element StockType
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateStockType();

/**
* const get element StockType
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetStockType()const;
/**
* Append element StockType
 * 
*/
	JDFNameSpan AppendStockType();

/** Get Element Texture
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateTexture();

/**
* const get element Texture
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetTexture()const;
/**
* Append element Texture
 * 
*/
	JDFNameSpan AppendTexture();

/** Get Element Thickness
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateThickness();

/**
* const get element Thickness
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetThickness()const;
/**
* Append element Thickness
 * 
*/
	JDFNumberSpan AppendThickness();

/** Get Element USWeight
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateUSWeight();

/**
* const get element USWeight
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetUSWeight()const;
/**
* Append element USWeight
 * 
*/
	JDFNumberSpan AppendUSWeight();

/** Get Element Weight
* 
* @return JDFNumberSpan The element
*/
	JDFNumberSpan GetCreateWeight();

/**
* const get element Weight
*@return  JDFNumberSpan The element
*/
	JDFNumberSpan GetWeight()const;
/**
* Append element Weight
 * 
*/
	JDFNumberSpan AppendWeight();

/** Get Element MediaLayers
* 
* @return JDFMediaLayers The element
*/
	JDFMediaLayers GetCreateMediaLayers();

/**
* const get element MediaLayers
*@return  JDFMediaLayers The element
*/
	JDFMediaLayers GetMediaLayers()const;
/**
* Append element MediaLayers
 * 
*/
	JDFMediaLayers AppendMediaLayers();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoMediaIntent

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoMediaIntent_H_
