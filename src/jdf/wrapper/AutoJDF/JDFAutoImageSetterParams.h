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

 
#if !defined _JDFAutoImageSetterParams_H_
#define _JDFAutoImageSetterParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFMedia;
class JDFFitPolicy;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoImageSetterParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoImageSetterParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFImageSetterParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoImageSetterParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoImageSetterParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoImageSetterParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoImageSetterParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoImageSetterParams(){};
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
* Enumeration for attribute MirrorAround
*/

	enum EnumMirrorAround{MirrorAround_Unknown,MirrorAround_None,MirrorAround_FeedDirection,MirrorAround_MediaWidth,MirrorAround_Both};
/**
* Enumeration for attribute Polarity
*/

	enum EnumPolarity{Polarity_Unknown,Polarity_Positive,Polarity_Negative};
/**
* Enumeration for attribute Sides
*/

	enum EnumSides{Sides_Unknown,Sides_OneSidedBackFlipX,Sides_OneSidedBackFlipY,Sides_OneSidedFront,Sides_TwoSidedFlipX,Sides_TwoSidedFlipY};
/**
* Enumeration for attribute CenterAcross
*/

	enum EnumCenterAcross{CenterAcross_Unknown,CenterAcross_None,CenterAcross_FeedDirection,CenterAcross_MediaWidth,CenterAcross_Both};
/**
* Enumeration for attribute SourceWorkStyle
*/

	enum EnumSourceWorkStyle{SourceWorkStyle_Unknown,SourceWorkStyle_Simplex,SourceWorkStyle_Perfecting,SourceWorkStyle_WorkAndBack,SourceWorkStyle_WorkAndTurn,SourceWorkStyle_WorkAndTumble,SourceWorkStyle_WorkAndTwist};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for MirrorAround
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MirrorAroundString();
/**
* Enumeration string for enum value
* @param EnumMirrorAround value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MirrorAroundString(EnumMirrorAround value);
/**
* Set attribute MirrorAround
* @param EnumMirrorAround value the value to set the attribute to
*/
	virtual void SetMirrorAround( EnumMirrorAround value);

/**
* Typesafe enumerated attribute MirrorAround; defaults to None
* @return EnumMirrorAroundthe enumeration value of the attribute
*/
	virtual EnumMirrorAround GetMirrorAround() const;

/**
* Typesafe attribute validation of MirrorAround
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMirrorAround(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Polarity
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PolarityString();
/**
* Enumeration string for enum value
* @param EnumPolarity value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PolarityString(EnumPolarity value);
/**
* Set attribute Polarity
* @param EnumPolarity value the value to set the attribute to
*/
	virtual void SetPolarity( EnumPolarity value);

/**
* Typesafe enumerated attribute Polarity; defaults to Positive
* @return EnumPolaritythe enumeration value of the attribute
*/
	virtual EnumPolarity GetPolarity() const;

/**
* Typesafe attribute validation of Polarity
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPolarity(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Typesafe enumerated attribute Sides; defaults to OneSidedFront
* @return EnumSidesthe enumeration value of the attribute
*/
	virtual EnumSides GetSides() const;

/**
* Typesafe attribute validation of Sides
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSides(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AdvanceDistance
*@param double value: the value to set the attribute to
*/
	virtual void SetAdvanceDistance(double value);
/**
* Get double attribute AdvanceDistance
* @return double the vaue of the attribute 
*/
	virtual double GetAdvanceDistance() const;
/**
* Typesafe attribute validation of AdvanceDistance
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAdvanceDistance(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BurnOutArea
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetBurnOutArea(const JDFXYPair& value);
/**
* Get string attribute BurnOutArea
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetBurnOutArea() const;
/**
* Typesafe attribute validation of BurnOutArea
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBurnOutArea(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for CenterAcross
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CenterAcrossString();
/**
* Enumeration string for enum value
* @param EnumCenterAcross value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CenterAcrossString(EnumCenterAcross value);
/**
* Set attribute CenterAcross
* @param EnumCenterAcross value the value to set the attribute to
*/
	virtual void SetCenterAcross( EnumCenterAcross value);

/**
* Typesafe enumerated attribute CenterAcross
* @return EnumCenterAcrossthe enumeration value of the attribute
*/
	virtual EnumCenterAcross GetCenterAcross() const;

/**
* Typesafe attribute validation of CenterAcross
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCenterAcross(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CutMedia
*@param bool value: the value to set the attribute to
*/
	virtual void SetCutMedia(bool value);
/**
* Get bool attribute CutMedia
* @return bool the vaue of the attribute 
*/
	virtual bool GetCutMedia() const;
/**
* Typesafe attribute validation of CutMedia
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCutMedia(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ManualFeed
*@param bool value: the value to set the attribute to
*/
	virtual void SetManualFeed(bool value);
/**
* Get bool attribute ManualFeed
* @return bool the vaue of the attribute 
*/
	virtual bool GetManualFeed() const;
/**
* Typesafe attribute validation of ManualFeed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidManualFeed(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Punch
*@param bool value: the value to set the attribute to
*/
	virtual void SetPunch(bool value);
/**
* Get bool attribute Punch
* @return bool the vaue of the attribute 
*/
	virtual bool GetPunch() const;
/**
* Typesafe attribute validation of Punch
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPunch(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PunchType
*@param WString value: the value to set the attribute to
*/
	virtual void SetPunchType(const WString& value);
/**
* Get string attribute PunchType
* @return WString the vaue of the attribute 
*/
	virtual WString GetPunchType() const;
/**
* Typesafe attribute validation of PunchType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPunchType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Resolution
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetResolution(const JDFXYPair& value);
/**
* Get string attribute Resolution
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetResolution() const;
/**
* Typesafe attribute validation of Resolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RollCut
*@param double value: the value to set the attribute to
*/
	virtual void SetRollCut(double value);
/**
* Get double attribute RollCut
* @return double the vaue of the attribute 
*/
	virtual double GetRollCut() const;
/**
* Typesafe attribute validation of RollCut
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRollCut(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SourceWorkStyle
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SourceWorkStyleString();
/**
* Enumeration string for enum value
* @param EnumSourceWorkStyle value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SourceWorkStyleString(EnumSourceWorkStyle value);
/**
* Set attribute SourceWorkStyle
* @param EnumSourceWorkStyle value the value to set the attribute to
*/
	virtual void SetSourceWorkStyle( EnumSourceWorkStyle value);

/**
* Typesafe enumerated attribute SourceWorkStyle
* @return EnumSourceWorkStylethe enumeration value of the attribute
*/
	virtual EnumSourceWorkStyle GetSourceWorkStyle() const;

/**
* Typesafe attribute validation of SourceWorkStyle
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSourceWorkStyle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TransferCurve
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetTransferCurve(const JDFNumberList& value);
/**
* Get string attribute TransferCurve
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetTransferCurve() const;
/**
* Typesafe attribute validation of TransferCurve
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTransferCurve(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


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

/** Get Element FitPolicy
* 
* @return JDFFitPolicy The element
*/
	JDFFitPolicy GetCreateFitPolicy();

/**
* const get element FitPolicy
*@return  JDFFitPolicy The element
*/
	JDFFitPolicy GetFitPolicy()const;
/**
* Append element FitPolicy
 * 
*/
	JDFFitPolicy AppendFitPolicy();
/**
* create inter-resource link to refTarget
* @param JDFFitPolicy& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefFitPolicy(JDFFitPolicy& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoImageSetterParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoImageSetterParams_H_
