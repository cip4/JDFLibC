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

 
#if !defined _JDFAutoPDFToPSConversionParams_H_
#define _JDFAutoPDFToPSConversionParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPDFToPSConversionParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPDFToPSConversionParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPDFToPSConversionParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPDFToPSConversionParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPDFToPSConversionParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoPDFToPSConversionParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPDFToPSConversionParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPDFToPSConversionParams(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

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
* Enumeration for attribute IncludeBaseFonts
*/

	enum EnumIncludeBaseFonts{IncludeBaseFonts_Unknown,IncludeBaseFonts_IncludeNever,IncludeBaseFonts_IncludeOncePerDoc,IncludeBaseFonts_IncludeOncePerPage};
/**
* Enumeration for attribute IncludeCIDFonts
*/

	enum EnumIncludeCIDFonts{IncludeCIDFonts_Unknown,IncludeCIDFonts_IncludeNever,IncludeCIDFonts_IncludeOncePerDoc,IncludeCIDFonts_IncludeOncePerPage};
/**
* Enumeration for attribute IncludeEmbeddedFonts
*/

	enum EnumIncludeEmbeddedFonts{IncludeEmbeddedFonts_Unknown,IncludeEmbeddedFonts_IncludeNever,IncludeEmbeddedFonts_IncludeOncePerDoc,IncludeEmbeddedFonts_IncludeOncePerPage};
/**
* Enumeration for attribute IncludeOtherResources
*/

	enum EnumIncludeOtherResources{IncludeOtherResources_Unknown,IncludeOtherResources_IncludeNever,IncludeOtherResources_IncludeOncePerDoc,IncludeOtherResources_IncludeOncePerPage};
/**
* Enumeration for attribute IncludeProcSets
*/

	enum EnumIncludeProcSets{IncludeProcSets_Unknown,IncludeProcSets_IncludeNever,IncludeProcSets_IncludeOncePerDoc,IncludeProcSets_IncludeOncePerPage};
/**
* Enumeration for attribute IncludeTrueTypeFonts
*/

	enum EnumIncludeTrueTypeFonts{IncludeTrueTypeFonts_Unknown,IncludeTrueTypeFonts_IncludeNever,IncludeTrueTypeFonts_IncludeOncePerDoc,IncludeTrueTypeFonts_IncludeOncePerPage};
/**
* Enumeration for attribute IncludeType1Fonts
*/

	enum EnumIncludeType1Fonts{IncludeType1Fonts_Unknown,IncludeType1Fonts_IncludeNever,IncludeType1Fonts_IncludeOncePerDoc,IncludeType1Fonts_IncludeOncePerPage};
/**
* Enumeration for attribute IncludeType3Fonts
*/

	enum EnumIncludeType3Fonts{IncludeType3Fonts_Unknown,IncludeType3Fonts_IncludeNever,IncludeType3Fonts_IncludeOncePerDoc,IncludeType3Fonts_IncludeOncePerPage};
/**
* Enumeration for attribute OutputType
*/

	enum EnumOutputType{OutputType_Unknown,OutputType_PostScript,OutputType_EPS};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BinaryOK
*@param bool value: the value to set the attribute to
*/
	virtual void SetBinaryOK(bool value);
/**
* Get bool attribute BinaryOK
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetBinaryOK() const;
/**
* Typesafe attribute validation of BinaryOK
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBinaryOK(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CenterCropBox
*@param bool value: the value to set the attribute to
*/
	virtual void SetCenterCropBox(bool value);
/**
* Get bool attribute CenterCropBox
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetCenterCropBox() const;
/**
* Typesafe attribute validation of CenterCropBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCenterCropBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GeneratePageStreams
*@param bool value: the value to set the attribute to
*/
	virtual void SetGeneratePageStreams(bool value);
/**
* Get bool attribute GeneratePageStreams
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetGeneratePageStreams() const;
/**
* Typesafe attribute validation of GeneratePageStreams
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGeneratePageStreams(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreAnnotForms
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreAnnotForms(bool value);
/**
* Get bool attribute IgnoreAnnotForms
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreAnnotForms() const;
/**
* Typesafe attribute validation of IgnoreAnnotForms
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreAnnotForms(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreBG
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreBG(bool value);
/**
* Get bool attribute IgnoreBG
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetIgnoreBG() const;
/**
* Typesafe attribute validation of IgnoreBG
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreBG(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreColorSeps
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreColorSeps(bool value);
/**
* Get bool attribute IgnoreColorSeps
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreColorSeps() const;
/**
* Typesafe attribute validation of IgnoreColorSeps
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreColorSeps(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreDSC
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreDSC(bool value);
/**
* Get bool attribute IgnoreDSC
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetIgnoreDSC() const;
/**
* Typesafe attribute validation of IgnoreDSC
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreDSC(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreExternStreamRef
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreExternStreamRef(bool value);
/**
* Get bool attribute IgnoreExternStreamRef
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreExternStreamRef() const;
/**
* Typesafe attribute validation of IgnoreExternStreamRef
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreExternStreamRef(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreHalftones
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreHalftones(bool value);
/**
* Get bool attribute IgnoreHalftones
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreHalftones() const;
/**
* Typesafe attribute validation of IgnoreHalftones
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreHalftones(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreOverprint
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreOverprint(bool value);
/**
* Get bool attribute IgnoreOverprint
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetIgnoreOverprint() const;
/**
* Typesafe attribute validation of IgnoreOverprint
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreOverprint(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnorePageRotation
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnorePageRotation(bool value);
/**
* Get bool attribute IgnorePageRotation
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnorePageRotation() const;
/**
* Typesafe attribute validation of IgnorePageRotation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnorePageRotation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreRawData
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreRawData(bool value);
/**
* Get bool attribute IgnoreRawData
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreRawData() const;
/**
* Typesafe attribute validation of IgnoreRawData
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreRawData(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreSeparableImagesOnly
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreSeparableImagesOnly(bool value);
/**
* Get bool attribute IgnoreSeparableImagesOnly
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreSeparableImagesOnly() const;
/**
* Typesafe attribute validation of IgnoreSeparableImagesOnly
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreSeparableImagesOnly(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreShowPage
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreShowPage(bool value);
/**
* Get bool attribute IgnoreShowPage
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreShowPage() const;
/**
* Typesafe attribute validation of IgnoreShowPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreShowPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreTransfers
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreTransfers(bool value);
/**
* Get bool attribute IgnoreTransfers
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetIgnoreTransfers() const;
/**
* Typesafe attribute validation of IgnoreTransfers
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreTransfers(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreTTFontsFirst
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreTTFontsFirst(bool value);
/**
* Get bool attribute IgnoreTTFontsFirst
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreTTFontsFirst() const;
/**
* Typesafe attribute validation of IgnoreTTFontsFirst
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreTTFontsFirst(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreUCR
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreUCR(bool value);
/**
* Get bool attribute IgnoreUCR
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetIgnoreUCR() const;
/**
* Typesafe attribute validation of IgnoreUCR
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreUCR(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeBaseFonts
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeBaseFontsString();
/**
* Enumeration string for enum value
* @param EnumIncludeBaseFonts value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeBaseFontsString(EnumIncludeBaseFonts value);
/**
* Set attribute IncludeBaseFonts
* @param EnumIncludeBaseFonts value the value to set the attribute to
*/
	virtual void SetIncludeBaseFonts( EnumIncludeBaseFonts value);

/**
* Typesafe enumerated attribute IncludeBaseFonts; defaults to IncludeNever
* @return EnumIncludeBaseFontsthe enumeration value of the attribute
*/
	virtual EnumIncludeBaseFonts GetIncludeBaseFonts() const;

/**
* Typesafe attribute validation of IncludeBaseFonts
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeBaseFonts(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeCIDFonts
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeCIDFontsString();
/**
* Enumeration string for enum value
* @param EnumIncludeCIDFonts value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeCIDFontsString(EnumIncludeCIDFonts value);
/**
* Set attribute IncludeCIDFonts
* @param EnumIncludeCIDFonts value the value to set the attribute to
*/
	virtual void SetIncludeCIDFonts( EnumIncludeCIDFonts value);

/**
* Typesafe enumerated attribute IncludeCIDFonts; defaults to IncludeOncePerDoc
* @return EnumIncludeCIDFontsthe enumeration value of the attribute
*/
	virtual EnumIncludeCIDFonts GetIncludeCIDFonts() const;

/**
* Typesafe attribute validation of IncludeCIDFonts
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeCIDFonts(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeEmbeddedFonts
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeEmbeddedFontsString();
/**
* Enumeration string for enum value
* @param EnumIncludeEmbeddedFonts value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeEmbeddedFontsString(EnumIncludeEmbeddedFonts value);
/**
* Set attribute IncludeEmbeddedFonts
* @param EnumIncludeEmbeddedFonts value the value to set the attribute to
*/
	virtual void SetIncludeEmbeddedFonts( EnumIncludeEmbeddedFonts value);

/**
* Typesafe enumerated attribute IncludeEmbeddedFonts; defaults to IncludeOncePerDoc
* @return EnumIncludeEmbeddedFontsthe enumeration value of the attribute
*/
	virtual EnumIncludeEmbeddedFonts GetIncludeEmbeddedFonts() const;

/**
* Typesafe attribute validation of IncludeEmbeddedFonts
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeEmbeddedFonts(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeOtherResources
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeOtherResourcesString();
/**
* Enumeration string for enum value
* @param EnumIncludeOtherResources value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeOtherResourcesString(EnumIncludeOtherResources value);
/**
* Set attribute IncludeOtherResources
* @param EnumIncludeOtherResources value the value to set the attribute to
*/
	virtual void SetIncludeOtherResources( EnumIncludeOtherResources value);

/**
* Typesafe enumerated attribute IncludeOtherResources; defaults to IncludeOncePerDoc
* @return EnumIncludeOtherResourcesthe enumeration value of the attribute
*/
	virtual EnumIncludeOtherResources GetIncludeOtherResources() const;

/**
* Typesafe attribute validation of IncludeOtherResources
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeOtherResources(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeProcSets
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeProcSetsString();
/**
* Enumeration string for enum value
* @param EnumIncludeProcSets value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeProcSetsString(EnumIncludeProcSets value);
/**
* Set attribute IncludeProcSets
* @param EnumIncludeProcSets value the value to set the attribute to
*/
	virtual void SetIncludeProcSets( EnumIncludeProcSets value);

/**
* Typesafe enumerated attribute IncludeProcSets; defaults to IncludeOncePerDoc
* @return EnumIncludeProcSetsthe enumeration value of the attribute
*/
	virtual EnumIncludeProcSets GetIncludeProcSets() const;

/**
* Typesafe attribute validation of IncludeProcSets
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeProcSets(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeTrueTypeFonts
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeTrueTypeFontsString();
/**
* Enumeration string for enum value
* @param EnumIncludeTrueTypeFonts value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeTrueTypeFontsString(EnumIncludeTrueTypeFonts value);
/**
* Set attribute IncludeTrueTypeFonts
* @param EnumIncludeTrueTypeFonts value the value to set the attribute to
*/
	virtual void SetIncludeTrueTypeFonts( EnumIncludeTrueTypeFonts value);

/**
* Typesafe enumerated attribute IncludeTrueTypeFonts; defaults to IncludeOncePerDoc
* @return EnumIncludeTrueTypeFontsthe enumeration value of the attribute
*/
	virtual EnumIncludeTrueTypeFonts GetIncludeTrueTypeFonts() const;

/**
* Typesafe attribute validation of IncludeTrueTypeFonts
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeTrueTypeFonts(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeType1Fonts
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeType1FontsString();
/**
* Enumeration string for enum value
* @param EnumIncludeType1Fonts value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeType1FontsString(EnumIncludeType1Fonts value);
/**
* Set attribute IncludeType1Fonts
* @param EnumIncludeType1Fonts value the value to set the attribute to
*/
	virtual void SetIncludeType1Fonts( EnumIncludeType1Fonts value);

/**
* Typesafe enumerated attribute IncludeType1Fonts; defaults to IncludeOncePerDoc
* @return EnumIncludeType1Fontsthe enumeration value of the attribute
*/
	virtual EnumIncludeType1Fonts GetIncludeType1Fonts() const;

/**
* Typesafe attribute validation of IncludeType1Fonts
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeType1Fonts(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for IncludeType3Fonts
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& IncludeType3FontsString();
/**
* Enumeration string for enum value
* @param EnumIncludeType3Fonts value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString IncludeType3FontsString(EnumIncludeType3Fonts value);
/**
* Set attribute IncludeType3Fonts
* @param EnumIncludeType3Fonts value the value to set the attribute to
*/
	virtual void SetIncludeType3Fonts( EnumIncludeType3Fonts value);

/**
* Typesafe enumerated attribute IncludeType3Fonts
* @return EnumIncludeType3Fontsthe enumeration value of the attribute
*/
	virtual EnumIncludeType3Fonts GetIncludeType3Fonts() const;

/**
* Typesafe attribute validation of IncludeType3Fonts
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidIncludeType3Fonts(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for OutputType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OutputTypeString();
/**
* Enumeration string for enum value
* @param EnumOutputType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OutputTypeString(EnumOutputType value);
/**
* Set attribute OutputType
* @param EnumOutputType value the value to set the attribute to
*/
	virtual void SetOutputType( EnumOutputType value);

/**
* Typesafe enumerated attribute OutputType; defaults to PostScript
* @return EnumOutputTypethe enumeration value of the attribute
*/
	virtual EnumOutputType GetOutputType() const;

/**
* Typesafe attribute validation of OutputType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOutputType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PSLevel
*@param int value: the value to set the attribute to
*/
	virtual void SetPSLevel(int value);
/**
* Get integer attribute PSLevel
* @return int the vaue of the attribute ; defaults to 2
*/
	virtual int GetPSLevel() const;
/**
* Typesafe attribute validation of PSLevel
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPSLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Scale
*@param double value: the value to set the attribute to
*/
	virtual void SetScale(double value);
/**
* Get double attribute Scale
* @return double the vaue of the attribute ; defaults to 100
*/
	virtual double GetScale() const;
/**
* Typesafe attribute validation of Scale
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidScale(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetPageSize
*@param bool value: the value to set the attribute to
*/
	virtual void SetSetPageSize(bool value);
/**
* Get bool attribute SetPageSize
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetSetPageSize() const;
/**
* Typesafe attribute validation of SetPageSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetPageSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetupProcsets
*@param bool value: the value to set the attribute to
*/
	virtual void SetSetupProcsets(bool value);
/**
* Get bool attribute SetupProcsets
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetSetupProcsets() const;
/**
* Typesafe attribute validation of SetupProcsets
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetupProcsets(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShrinkToFit
*@param bool value: the value to set the attribute to
*/
	virtual void SetShrinkToFit(bool value);
/**
* Get bool attribute ShrinkToFit
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetShrinkToFit() const;
/**
* Typesafe attribute validation of ShrinkToFit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShrinkToFit(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SuppressCenter
*@param bool value: the value to set the attribute to
*/
	virtual void SetSuppressCenter(bool value);
/**
* Get bool attribute SuppressCenter
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetSuppressCenter() const;
/**
* Typesafe attribute validation of SuppressCenter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSuppressCenter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SuppressRotate
*@param bool value: the value to set the attribute to
*/
	virtual void SetSuppressRotate(bool value);
/**
* Get bool attribute SuppressRotate
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetSuppressRotate() const;
/**
* Typesafe attribute validation of SuppressRotate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSuppressRotate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TTasT42
*@param bool value: the value to set the attribute to
*/
	virtual void SetTTasT42(bool value);
/**
* Get bool attribute TTasT42
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetTTasT42() const;
/**
* Typesafe attribute validation of TTasT42
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTTasT42(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UseFontAliasNames
*@param bool value: the value to set the attribute to
*/
	virtual void SetUseFontAliasNames(bool value);
/**
* Get bool attribute UseFontAliasNames
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetUseFontAliasNames() const;
/**
* Typesafe attribute validation of UseFontAliasNames
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUseFontAliasNames(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IgnoreDeviceExtGState
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreDeviceExtGState(bool value);
/**
* Get bool attribute IgnoreDeviceExtGState
* @return bool the vaue of the attribute 
*/
	virtual bool GetIgnoreDeviceExtGState() const;
/**
* Typesafe attribute validation of IgnoreDeviceExtGState
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreDeviceExtGState(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BoundingBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetBoundingBox(const JDFRectangle& value);
/**
* Get string attribute BoundingBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetBoundingBox() const;
/**
* Typesafe attribute validation of BoundingBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBoundingBox(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoPDFToPSConversionParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPDFToPSConversionParams_H_
