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

 
#if !defined _JDFAutoMedia_H_
#define _JDFAutoMedia_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFColor;
class JDFColorMeasurementConditions;
class JDFMediaLayers;
class JDFHoleList;
class JDFTabDimensions;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoMedia : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoMedia class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFMedia should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoMedia : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoMedia():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoMedia(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoMedia &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoMedia(){};
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
* Enumeration for attribute HoleType
*/

	enum EnumHoleType{HoleType_Unknown,HoleType_None,HoleType_S1_generic,HoleType_S_generic,HoleType_R2_generic,HoleType_R2m_DIN,HoleType_R2m_ISO,HoleType_R2m_MIB,HoleType_R2i_US_a,HoleType_R2i_US_b,HoleType_R3_generic,HoleType_R3i_US,HoleType_R4_generic,HoleType_R4m_DIN_A4,HoleType_R4m_DIN_A5,HoleType_R4m_swedish,HoleType_R4i_US,HoleType_R5_generic,HoleType_R5i_US_a,HoleType_R5i_US_b,HoleType_R5i_US_c,HoleType_R6_generic,HoleType_R6m_4h2s,HoleType_R6m_DIN_A5,HoleType_R7_generic,HoleType_R7i_US_a,HoleType_R7i_US_b,HoleType_R7i_US_c,HoleType_R11m_7h4s,HoleType_P16_9i_rect_0t,HoleType_P12m_rect_0t,HoleType_W2_1i_round_0t,HoleType_W2_1i_square_0t,HoleType_W3_1i_square_0t,HoleType_C9_5m_round_0t,HoleType_Explicit};
/**
* Enumeration for attribute MediaUnit
*/

	enum EnumMediaUnit{MediaUnit_Unknown,MediaUnit_Continuous,MediaUnit_Roll,MediaUnit_Sheet};
/**
* Enumeration for attribute BackCoatings
*/

	enum EnumBackCoatings{BackCoatings_Unknown,BackCoatings_None,BackCoatings_Coated,BackCoatings_Glossy,BackCoatings_HighGloss,BackCoatings_InkJet,BackCoatings_Matte,BackCoatings_Polymer,BackCoatings_Silver,BackCoatings_Satin,BackCoatings_Semigloss};
/**
* Enumeration for attribute FluteDirection
*/

	enum EnumFluteDirection{FluteDirection_Unknown,FluteDirection_LongEdge,FluteDirection_ShortEdge,FluteDirection_XDirection,FluteDirection_YDirection};
/**
* Enumeration for attribute FrontCoatings
*/

	enum EnumFrontCoatings{FrontCoatings_Unknown,FrontCoatings_None,FrontCoatings_Coated,FrontCoatings_Glossy,FrontCoatings_HighGloss,FrontCoatings_InkJet,FrontCoatings_Matte,FrontCoatings_Polymer,FrontCoatings_Silver,FrontCoatings_Satin,FrontCoatings_Semigloss};
/**
* Enumeration for attribute GrainDirection
*/

	enum EnumGrainDirection{GrainDirection_Unknown,GrainDirection_LongEdge,GrainDirection_ShortEdge,GrainDirection_XDirection,GrainDirection_YDirection};
/**
* Enumeration for attribute ImagableSide
*/

	enum EnumImagableSide{ImagableSide_Unknown,ImagableSide_Front,ImagableSide_Back,ImagableSide_Both,ImagableSide_Neither};
/**
* Enumeration for attribute MediaType
*/

	enum EnumMediaType{MediaType_Unknown,MediaType_CorrugatedBoard,MediaType_Disc,MediaType_EndBoard,MediaType_EmbossingFoil,MediaType_Film,MediaType_Foil,MediaType_GravureCylinder,MediaType_ImagingCylinder,MediaType_LaminatingFoil,MediaType_MountingTape,MediaType_Other,MediaType_Paper,MediaType_Plate,MediaType_SelfAdhesive,MediaType_Sleeve,MediaType_ShrinkFoil,MediaType_Transparency};
/**
* Enumeration for attribute Opacity
*/

	enum EnumOpacity{Opacity_Unknown,Opacity_Opaque,Opacity_Translucent,Opacity_Transparent};
/**
* Enumeration for attribute PlateTechnology
*/

	enum EnumPlateTechnology{PlateTechnology_Unknown,PlateTechnology_FlexoAnalogSolvent,PlateTechnology_FlexoAnalogThermal,PlateTechnology_FlexoDigitalSolvent,PlateTechnology_FlexoDigitalThermal,PlateTechnology_FlexoDirectEngraving,PlateTechnology_InkJet,PlateTechnology_Thermal,PlateTechnology_UV,PlateTechnology_Visible};
/**
* Enumeration for attribute Polarity
*/

	enum EnumPolarity{Polarity_Unknown,Polarity_Positive,Polarity_Negative};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for HoleType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& HoleTypeString();
/**
* Enumeration string for enum value
* @param EnumHoleType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString HoleTypeString(EnumHoleType value);
/**
* Append value to the attribute HoleType
* @param EnumHoleType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddHoleType( EnumHoleType value);
/**
* Remove value from the attribute HoleType
* @param EnumHoleType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveHoleType( EnumHoleType value);
/**
* Typesafe enumerated attribute HoleType; defaults to None
* @return EnumHoleTypethe enumeration value of the attribute
*/
	virtual vint GetHoleType() const;
/**
* Set value of the attribute HoleType
* @param EnumHoleType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetHoleType( EnumHoleType value);
/**
* Set value of the attribute HoleType to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetHoleType( const vint& value);
/**
* Typesafe attribute validation of HoleType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidHoleType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MediaUnit
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MediaUnitString();
/**
* Enumeration string for enum value
* @param EnumMediaUnit value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MediaUnitString(EnumMediaUnit value);
/**
* Set attribute MediaUnit
* @param EnumMediaUnit value the value to set the attribute to
*/
	virtual void SetMediaUnit( EnumMediaUnit value);

/**
* Typesafe enumerated attribute MediaUnit; defaults to Sheet
* @return EnumMediaUnitthe enumeration value of the attribute
*/
	virtual EnumMediaUnit GetMediaUnit() const;

/**
* Typesafe attribute validation of MediaUnit
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMediaUnit(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute BackCoatingDetail
*@param WString value: the value to set the attribute to
*/
	virtual void SetBackCoatingDetail(const WString& value);
/**
* Get string attribute BackCoatingDetail
* @return WString the vaue of the attribute 
*/
	virtual WString GetBackCoatingDetail() const;
/**
* Typesafe attribute validation of BackCoatingDetail
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBackCoatingDetail(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BackCoatings
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BackCoatingsString();
/**
* Enumeration string for enum value
* @param EnumBackCoatings value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BackCoatingsString(EnumBackCoatings value);
/**
* Set attribute BackCoatings
* @param EnumBackCoatings value the value to set the attribute to
*/
	virtual void SetBackCoatings( EnumBackCoatings value);

/**
* Typesafe enumerated attribute BackCoatings
* @return EnumBackCoatingsthe enumeration value of the attribute
*/
	virtual EnumBackCoatings GetBackCoatings() const;

/**
* Typesafe attribute validation of BackCoatings
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBackCoatings(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BackGlossValue
*@param double value: the value to set the attribute to
*/
	virtual void SetBackGlossValue(double value);
/**
* Get double attribute BackGlossValue
* @return double the vaue of the attribute 
*/
	virtual double GetBackGlossValue() const;
/**
* Typesafe attribute validation of BackGlossValue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBackGlossValue(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Brightness
*@param double value: the value to set the attribute to
*/
	virtual void SetBrightness(double value);
/**
* Get double attribute Brightness
* @return double the vaue of the attribute 
*/
	virtual double GetBrightness() const;
/**
* Typesafe attribute validation of Brightness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBrightness(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CIETint
*@param double value: the value to set the attribute to
*/
	virtual void SetCIETint(double value);
/**
* Get double attribute CIETint
* @return double the vaue of the attribute 
*/
	virtual double GetCIETint() const;
/**
* Typesafe attribute validation of CIETint
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCIETint(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CIEWhiteness
*@param double value: the value to set the attribute to
*/
	virtual void SetCIEWhiteness(double value);
/**
* Get double attribute CIEWhiteness
* @return double the vaue of the attribute 
*/
	virtual double GetCIEWhiteness() const;
/**
* Typesafe attribute validation of CIEWhiteness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCIEWhiteness(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ColorName
*@param WString value: the value to set the attribute to
*/
	virtual void SetColorName(const WString& value);
/**
* Get string attribute ColorName
* @return WString the vaue of the attribute 
*/
	virtual WString GetColorName() const;
/**
* Typesafe attribute validation of ColorName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidColorName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CoreWeight
*@param double value: the value to set the attribute to
*/
	virtual void SetCoreWeight(double value);
/**
* Get double attribute CoreWeight
* @return double the vaue of the attribute 
*/
	virtual double GetCoreWeight() const;
/**
* Typesafe attribute validation of CoreWeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCoreWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Dimension
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetDimension(const JDFXYPair& value);
/**
* Get string attribute Dimension
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetDimension() const;
/**
* Typesafe attribute validation of Dimension
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDimension(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Flute
*@param WString value: the value to set the attribute to
*/
	virtual void SetFlute(const WString& value);
/**
* Get string attribute Flute
* @return WString the vaue of the attribute 
*/
	virtual WString GetFlute() const;
/**
* Typesafe attribute validation of Flute
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFlute(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for FluteDirection
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FluteDirectionString();
/**
* Enumeration string for enum value
* @param EnumFluteDirection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FluteDirectionString(EnumFluteDirection value);
/**
* Set attribute FluteDirection
* @param EnumFluteDirection value the value to set the attribute to
*/
	virtual void SetFluteDirection( EnumFluteDirection value);

/**
* Typesafe enumerated attribute FluteDirection
* @return EnumFluteDirectionthe enumeration value of the attribute
*/
	virtual EnumFluteDirection GetFluteDirection() const;

/**
* Typesafe attribute validation of FluteDirection
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFluteDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FrontCoatingDetail
*@param WString value: the value to set the attribute to
*/
	virtual void SetFrontCoatingDetail(const WString& value);
/**
* Get string attribute FrontCoatingDetail
* @return WString the vaue of the attribute 
*/
	virtual WString GetFrontCoatingDetail() const;
/**
* Typesafe attribute validation of FrontCoatingDetail
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrontCoatingDetail(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for FrontCoatings
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FrontCoatingsString();
/**
* Enumeration string for enum value
* @param EnumFrontCoatings value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FrontCoatingsString(EnumFrontCoatings value);
/**
* Set attribute FrontCoatings
* @param EnumFrontCoatings value the value to set the attribute to
*/
	virtual void SetFrontCoatings( EnumFrontCoatings value);

/**
* Typesafe enumerated attribute FrontCoatings
* @return EnumFrontCoatingsthe enumeration value of the attribute
*/
	virtual EnumFrontCoatings GetFrontCoatings() const;

/**
* Typesafe attribute validation of FrontCoatings
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFrontCoatings(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FrontGlossValue
*@param double value: the value to set the attribute to
*/
	virtual void SetFrontGlossValue(double value);
/**
* Get double attribute FrontGlossValue
* @return double the vaue of the attribute 
*/
	virtual double GetFrontGlossValue() const;
/**
* Typesafe attribute validation of FrontGlossValue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrontGlossValue(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Grade
*@param int value: the value to set the attribute to
*/
	virtual void SetGrade(int value);
/**
* Get integer attribute Grade
* @return int the vaue of the attribute 
*/
	virtual int GetGrade() const;
/**
* Typesafe attribute validation of Grade
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGrade(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for GrainDirection
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& GrainDirectionString();
/**
* Enumeration string for enum value
* @param EnumGrainDirection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString GrainDirectionString(EnumGrainDirection value);
/**
* Set attribute GrainDirection
* @param EnumGrainDirection value the value to set the attribute to
*/
	virtual void SetGrainDirection( EnumGrainDirection value);

/**
* Typesafe enumerated attribute GrainDirection
* @return EnumGrainDirectionthe enumeration value of the attribute
*/
	virtual EnumGrainDirection GetGrainDirection() const;

/**
* Typesafe attribute validation of GrainDirection
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidGrainDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HoleCount
*@param int value: the value to set the attribute to
*/
	virtual void SetHoleCount(int value);
/**
* Get integer attribute HoleCount
* @return int the vaue of the attribute 
*/
	virtual int GetHoleCount() const;
/**
* Typesafe attribute validation of HoleCount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHoleCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ImagableSide
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ImagableSideString();
/**
* Enumeration string for enum value
* @param EnumImagableSide value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ImagableSideString(EnumImagableSide value);
/**
* Set attribute ImagableSide
* @param EnumImagableSide value the value to set the attribute to
*/
	virtual void SetImagableSide( EnumImagableSide value);

/**
* Typesafe enumerated attribute ImagableSide
* @return EnumImagableSidethe enumeration value of the attribute
*/
	virtual EnumImagableSide GetImagableSide() const;

/**
* Typesafe attribute validation of ImagableSide
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidImagableSide(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute InsideLoss
*@param double value: the value to set the attribute to
*/
	virtual void SetInsideLoss(double value);
/**
* Get double attribute InsideLoss
* @return double the vaue of the attribute 
*/
	virtual double GetInsideLoss() const;
/**
* Typesafe attribute validation of InsideLoss
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInsideLoss(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LabColorValue
*@param JDFLabColor value: the value to set the attribute to
*/
	virtual void SetLabColorValue(const JDFLabColor& value);
/**
* Get string attribute LabColorValue
* @return JDFLabColor the vaue of the attribute 
*/
	virtual JDFLabColor GetLabColorValue() const;
/**
* Typesafe attribute validation of LabColorValue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLabColorValue(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MediaColorName
* @param EnumNamedColor value the value to set the attribute to
*/
	virtual void SetMediaColorName( EnumNamedColor value);

/**
* Typesafe enumerated attribute MediaColorName
* @return EnumMediaColorNamethe enumeration value of the attribute
*/
	virtual EnumNamedColor GetMediaColorName() const;

/**
* Typesafe attribute validation of MediaColorName
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMediaColorName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MediaColorNameDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetMediaColorNameDetails(const WString& value);
/**
* Get string attribute MediaColorNameDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetMediaColorNameDetails() const;
/**
* Typesafe attribute validation of MediaColorNameDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMediaColorNameDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MediaQuality
*@param WString value: the value to set the attribute to
*/
	virtual void SetMediaQuality(const WString& value);
/**
* Get string attribute MediaQuality
* @return WString the vaue of the attribute 
*/
	virtual WString GetMediaQuality() const;
/**
* Typesafe attribute validation of MediaQuality
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMediaQuality(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Enumeration strings for MediaType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MediaTypeString();
/**
* Enumeration string for enum value
* @param EnumMediaType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MediaTypeString(EnumMediaType value);
/**
* Set attribute MediaType
* @param EnumMediaType value the value to set the attribute to
*/
	virtual void SetMediaType( EnumMediaType value);

/**
* Typesafe enumerated attribute MediaType
* @return EnumMediaTypethe enumeration value of the attribute
*/
	virtual EnumMediaType GetMediaType() const;

/**
* Typesafe attribute validation of MediaType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMediaType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MediaTypeDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetMediaTypeDetails(const WString& value);
/**
* Get string attribute MediaTypeDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetMediaTypeDetails() const;
/**
* Typesafe attribute validation of MediaTypeDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMediaTypeDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Opacity
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OpacityString();
/**
* Enumeration string for enum value
* @param EnumOpacity value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OpacityString(EnumOpacity value);
/**
* Set attribute Opacity
* @param EnumOpacity value the value to set the attribute to
*/
	virtual void SetOpacity( EnumOpacity value);

/**
* Typesafe enumerated attribute Opacity
* @return EnumOpacitythe enumeration value of the attribute
*/
	virtual EnumOpacity GetOpacity() const;

/**
* Typesafe attribute validation of Opacity
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOpacity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OpacityLevel
*@param double value: the value to set the attribute to
*/
	virtual void SetOpacityLevel(double value);
/**
* Get double attribute OpacityLevel
* @return double the vaue of the attribute 
*/
	virtual double GetOpacityLevel() const;
/**
* Typesafe attribute validation of OpacityLevel
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOpacityLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OuterCoreDiameter
*@param double value: the value to set the attribute to
*/
	virtual void SetOuterCoreDiameter(double value);
/**
* Get double attribute OuterCoreDiameter
* @return double the vaue of the attribute 
*/
	virtual double GetOuterCoreDiameter() const;
/**
* Typesafe attribute validation of OuterCoreDiameter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOuterCoreDiameter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutsideGain
*@param double value: the value to set the attribute to
*/
	virtual void SetOutsideGain(double value);
/**
* Get double attribute OutsideGain
* @return double the vaue of the attribute 
*/
	virtual double GetOutsideGain() const;
/**
* Typesafe attribute validation of OutsideGain
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutsideGain(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PlateTechnology
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PlateTechnologyString();
/**
* Enumeration string for enum value
* @param EnumPlateTechnology value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PlateTechnologyString(EnumPlateTechnology value);
/**
* Set attribute PlateTechnology
* @param EnumPlateTechnology value the value to set the attribute to
*/
	virtual void SetPlateTechnology( EnumPlateTechnology value);

/**
* Typesafe enumerated attribute PlateTechnology
* @return EnumPlateTechnologythe enumeration value of the attribute
*/
	virtual EnumPlateTechnology GetPlateTechnology() const;

/**
* Typesafe attribute validation of PlateTechnology
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPlateTechnology(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Typesafe enumerated attribute Polarity
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
* Set attribute PrintingTechnology
*@param WString value: the value to set the attribute to
*/
	virtual void SetPrintingTechnology(const WString& value);
/**
* Get string attribute PrintingTechnology
* @return WString the vaue of the attribute 
*/
	virtual WString GetPrintingTechnology() const;
/**
* Typesafe attribute validation of PrintingTechnology
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPrintingTechnology(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Recycled
*@param bool value: the value to set the attribute to
*/
	virtual void SetRecycled(bool value);
/**
* Get bool attribute Recycled
* @return bool the vaue of the attribute 
*/
	virtual bool GetRecycled() const;
/**
* Typesafe attribute validation of Recycled
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRecycled(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RecycledPercentage
*@param double value: the value to set the attribute to
*/
	virtual void SetRecycledPercentage(double value);
/**
* Get double attribute RecycledPercentage
* @return double the vaue of the attribute 
*/
	virtual double GetRecycledPercentage() const;
/**
* Typesafe attribute validation of RecycledPercentage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRecycledPercentage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ReliefThickness
*@param double value: the value to set the attribute to
*/
	virtual void SetReliefThickness(double value);
/**
* Get double attribute ReliefThickness
* @return double the vaue of the attribute 
*/
	virtual double GetReliefThickness() const;
/**
* Typesafe attribute validation of ReliefThickness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidReliefThickness(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RollDiameter
*@param double value: the value to set the attribute to
*/
	virtual void SetRollDiameter(double value);
/**
* Get double attribute RollDiameter
* @return double the vaue of the attribute 
*/
	virtual double GetRollDiameter() const;
/**
* Typesafe attribute validation of RollDiameter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRollDiameter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShrinkIndex
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetShrinkIndex(const JDFXYPair& value);
/**
* Get string attribute ShrinkIndex
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetShrinkIndex() const;
/**
* Typesafe attribute validation of ShrinkIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShrinkIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SleeveInterlock
*@param WString value: the value to set the attribute to
*/
	virtual void SetSleeveInterlock(const WString& value);
/**
* Get string attribute SleeveInterlock
* @return WString the vaue of the attribute 
*/
	virtual WString GetSleeveInterlock() const;
/**
* Typesafe attribute validation of SleeveInterlock
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSleeveInterlock(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StockType
*@param WString value: the value to set the attribute to
*/
	virtual void SetStockType(const WString& value);
/**
* Get string attribute StockType
* @return WString the vaue of the attribute 
*/
	virtual WString GetStockType() const;
/**
* Typesafe attribute validation of StockType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStockType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Texture
*@param WString value: the value to set the attribute to
*/
	virtual void SetTexture(const WString& value);
/**
* Get string attribute Texture
* @return WString the vaue of the attribute 
*/
	virtual WString GetTexture() const;
/**
* Typesafe attribute validation of Texture
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTexture(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Thickness
*@param double value: the value to set the attribute to
*/
	virtual void SetThickness(double value);
/**
* Get double attribute Thickness
* @return double the vaue of the attribute 
*/
	virtual double GetThickness() const;
/**
* Typesafe attribute validation of Thickness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidThickness(EnumValidationLevel level=ValidationLevel_Complete) const;
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
/**
* Set attribute Weight
*@param double value: the value to set the attribute to
*/
	virtual void SetWeight(double value);
/**
* Get double attribute Weight
* @return double the vaue of the attribute 
*/
	virtual double GetWeight() const;
/**
* Typesafe attribute validation of Weight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WrapperWeight
*@param double value: the value to set the attribute to
*/
	virtual void SetWrapperWeight(double value);
/**
* Get double attribute WrapperWeight
* @return double the vaue of the attribute 
*/
	virtual double GetWrapperWeight() const;
/**
* Typesafe attribute validation of WrapperWeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWrapperWeight(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Color
* 
* @param int iSkip number of elements to skip
* @return JDFColor The element
*/
	JDFColor GetCreateColor(int iSkip=0);

/**
* const get element Color
* @param int iSkip number of elements to skip
* @return JDFColor The element
*/
	JDFColor GetColor(int iSkip=0)const;
/**
* Append element Color
 */
	JDFColor AppendColor();
/**
* create inter-resource link to refTarget
* @param JDFColor& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColor(JDFColor& refTarget);

/** Get Element ColorMeasurementConditions
* 
* @param int iSkip number of elements to skip
* @return JDFColorMeasurementConditions The element
*/
	JDFColorMeasurementConditions GetCreateColorMeasurementConditions(int iSkip=0);

/**
* const get element ColorMeasurementConditions
* @param int iSkip number of elements to skip
* @return JDFColorMeasurementConditions The element
*/
	JDFColorMeasurementConditions GetColorMeasurementConditions(int iSkip=0)const;
/**
* Append element ColorMeasurementConditions
 */
	JDFColorMeasurementConditions AppendColorMeasurementConditions();
/**
* create inter-resource link to refTarget
* @param JDFColorMeasurementConditions& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorMeasurementConditions(JDFColorMeasurementConditions& refTarget);

/** Get Element MediaLayers
* 
* @param int iSkip number of elements to skip
* @return JDFMediaLayers The element
*/
	JDFMediaLayers GetCreateMediaLayers(int iSkip=0);

/**
* const get element MediaLayers
* @param int iSkip number of elements to skip
* @return JDFMediaLayers The element
*/
	JDFMediaLayers GetMediaLayers(int iSkip=0)const;
/**
* Append element MediaLayers
 */
	JDFMediaLayers AppendMediaLayers();

/** Get Element HoleList
* 
* @param int iSkip number of elements to skip
* @return JDFHoleList The element
*/
	JDFHoleList GetCreateHoleList(int iSkip=0);

/**
* const get element HoleList
* @param int iSkip number of elements to skip
* @return JDFHoleList The element
*/
	JDFHoleList GetHoleList(int iSkip=0)const;
/**
* Append element HoleList
 */
	JDFHoleList AppendHoleList();
/**
* create inter-resource link to refTarget
* @param JDFHoleList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefHoleList(JDFHoleList& refTarget);

/** Get Element TabDimensions
* 
* @param int iSkip number of elements to skip
* @return JDFTabDimensions The element
*/
	JDFTabDimensions GetCreateTabDimensions(int iSkip=0);

/**
* const get element TabDimensions
* @param int iSkip number of elements to skip
* @return JDFTabDimensions The element
*/
	JDFTabDimensions GetTabDimensions(int iSkip=0)const;
/**
* Append element TabDimensions
 */
	JDFTabDimensions AppendTabDimensions();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoMedia

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoMedia_H_
