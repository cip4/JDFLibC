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

 
#if !defined _JDFAutoPRGroupOccurrenceBase_H_
#define _JDFAutoPRGroupOccurrenceBase_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFQualityControlResult;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPRGroupOccurrenceBase : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPRGroupOccurrenceBase class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPRGroupOccurrenceBase should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPRGroupOccurrenceBase : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPRGroupOccurrenceBase():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPRGroupOccurrenceBase(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPRGroupOccurrenceBase &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPRGroupOccurrenceBase(){};
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

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */

/**
* Enumeration for attribute DifferentBoxSize
*/

	enum EnumDifferentBoxSize{DifferentBoxSize_Unknown,DifferentBoxSize_ArtBox,DifferentBoxSize_BleedBox,DifferentBoxSize_CropBox,DifferentBoxSize_MarginsBox,DifferentBoxSize_MediaBox,DifferentBoxSize_SlugBox,DifferentBoxSize_TrimBox};
/**
* Enumeration for attribute PropertyList
*/

	enum EnumPropertyList{PropertyList_Unknown,PropertyList_Annotation,PropertyList_Box,PropertyList_Class,PropertyList_Colorant,PropertyList_Document,PropertyList_Fill,PropertyList_Font,PropertyList_Graphic,PropertyList_Image,PropertyList_Logical,PropertyList_Page,PropertyList_PageBox,PropertyList_PDLObject,PropertyList_Reference,PropertyList_Shading,PropertyList_Stroke,PropertyList_Text,PropertyList_Vector};
/**
* Enumeration for attribute Binding
*/

	enum EnumBinding{Binding_Unknown,Binding_Left,Binding_Right};
/**
* Enumeration for attribute DocumentCompression
*/

	enum EnumDocumentCompression{DocumentCompression_Unknown,DocumentCompression_ASCII85,DocumentCompression_ASCIIHex,DocumentCompression_CCITT,DocumentCompression_JBIG2,DocumentCompression_JPEG,DocumentCompression_JPEG2000,DocumentCompression_LZW,DocumentCompression_None,DocumentCompression_RunLength,DocumentCompression_ZIP};
/**
* Enumeration for attribute DocumentEncoding
*/

	enum EnumDocumentEncoding{DocumentEncoding_Unknown,DocumentEncoding_ASCII,DocumentEncoding_Binary};
/**
* Enumeration for attribute TrappedKey
*/

	enum EnumTrappedKey{TrappedKey_Unknown,TrappedKey_True,TrappedKey_False};
/**
* Enumeration for attribute FillColorType
*/

	enum EnumFillColorType{FillColorType_Unknown,FillColorType_CMYGray,FillColorType_CMYBlack,FillColorType_Other,FillColorType_PureBlack,FillColorType_PureGray,FillColorType_RegistrationBlack,FillColorType_RegistrationGray,FillColorType_RichBlack,FillColorType_White};
/**
* Enumeration for attribute FontType
*/

	enum EnumFontType{FontType_Unknown,FontType_CIDFontType0,FontType_CIDFontType1,FontType_CIDFontType2,FontType_CIDFontType3,FontType_CIDFontType4,FontType_OpenType,FontType_TrueType,FontType_Type0,FontType_Type1,FontType_Type1MultipleMaster,FontType_Type2C,FontType_Type3,FontType_PDFType3,FontType_Type42,FontType_Other};
/**
* Enumeration for attribute AlternateColorSpace
*/

	enum EnumAlternateColorSpace{AlternateColorSpace_Unknown,AlternateColorSpace_CalGray,AlternateColorSpace_CalRGB,AlternateColorSpace_CIEBasedA,AlternateColorSpace_CIEBasedABC,AlternateColorSpace_CIEBasedDEFG,AlternateColorSpace_DeviceCMYK,AlternateColorSpace_DeviceGray,AlternateColorSpace_DeviceN,AlternateColorSpace_DeviceRGB,AlternateColorSpace_ICCBased,AlternateColorSpace_Lab};
/**
* Enumeration for attribute BlackGeneration
*/

	enum EnumBlackGeneration{BlackGeneration_Unknown,BlackGeneration_Identity,BlackGeneration_Custom};
/**
* Enumeration for attribute ColorSpace
*/

	enum EnumColorSpace{ColorSpace_Unknown,ColorSpace_CalGray,ColorSpace_CalRGB,ColorSpace_CIEBasedA,ColorSpace_CIEBasedABC,ColorSpace_CIEBasedDEFG,ColorSpace_DeviceCMYK,ColorSpace_DeviceGray,ColorSpace_DeviceN,ColorSpace_DeviceRGB,ColorSpace_ICCBased,ColorSpace_Lab};
/**
* Enumeration for attribute TransferFunction
*/

	enum EnumTransferFunction{TransferFunction_Unknown,TransferFunction_Identity,TransferFunction_Custom};
/**
* Enumeration for attribute UnderColorRemoval
*/

	enum EnumUnderColorRemoval{UnderColorRemoval_Unknown,UnderColorRemoval_Identity,UnderColorRemoval_Custom};
/**
* Enumeration for attribute CompressionTypes
*/

	enum EnumCompressionTypes{CompressionTypes_Unknown,CompressionTypes_ASCII85,CompressionTypes_ASCIIHex,CompressionTypes_CCITT,CompressionTypes_JBIG2,CompressionTypes_JPEG,CompressionTypes_JPEG2000,CompressionTypes_LZW,CompressionTypes_None,CompressionTypes_RunLength,CompressionTypes_ZIP};
/**
* Enumeration for attribute ImageFlipped
*/

	enum EnumImageFlipped{ImageFlipped_Unknown,ImageFlipped_Horizontal,ImageFlipped_Vertical,ImageFlipped_None};
/**
* Enumeration for attribute ImageMaskType
*/

	enum EnumImageMaskType{ImageMaskType_Unknown,ImageMaskType_NoMask,ImageMaskType_BitmapMask,ImageMaskType_ColorKeyMask};
/**
* Enumeration for attribute PageBoxType
*/

	enum EnumPageBoxType{PageBoxType_Unknown,PageBoxType_ArtBox,PageBoxType_BleedBox,PageBoxType_CropBox,PageBoxType_MarginsBox,PageBoxType_MediaBox,PageBoxType_SlugBox,PageBoxType_TrimBox};
/**
* Enumeration for attribute BlendColorSpace
*/

	enum EnumBlendColorSpace{BlendColorSpace_Unknown,BlendColorSpace_CalGray,BlendColorSpace_CalRGB,BlendColorSpace_CIEBasedA,BlendColorSpace_CIEBasedABC,BlendColorSpace_CIEBasedDEFG,BlendColorSpace_DeviceCMYK,BlendColorSpace_DeviceGray,BlendColorSpace_DeviceN,BlendColorSpace_DeviceRGB,BlendColorSpace_ICCBased,BlendColorSpace_Lab};
/**
* Enumeration for attribute ShadingType
*/

	enum EnumShadingType{ShadingType_Unknown,ShadingType_Smooth,ShadingType_Vector};
/**
* Enumeration for attribute StrokeAlternateColorSpace
*/

	enum EnumStrokeAlternateColorSpace{StrokeAlternateColorSpace_Unknown,StrokeAlternateColorSpace_CalGray,StrokeAlternateColorSpace_CalRGB,StrokeAlternateColorSpace_CIEBasedA,StrokeAlternateColorSpace_CIEBasedABC,StrokeAlternateColorSpace_CIEBasedDEFG,StrokeAlternateColorSpace_DeviceCMYK,StrokeAlternateColorSpace_DeviceGray,StrokeAlternateColorSpace_DeviceN,StrokeAlternateColorSpace_DeviceRGB,StrokeAlternateColorSpace_ICCBased,StrokeAlternateColorSpace_Lab};
/**
* Enumeration for attribute StrokeColorSpace
*/

	enum EnumStrokeColorSpace{StrokeColorSpace_Unknown,StrokeColorSpace_CalGray,StrokeColorSpace_CalRGB,StrokeColorSpace_CIEBasedA,StrokeColorSpace_CIEBasedABC,StrokeColorSpace_CIEBasedDEFG,StrokeColorSpace_DeviceCMYK,StrokeColorSpace_DeviceGray,StrokeColorSpace_DeviceN,StrokeColorSpace_DeviceRGB,StrokeColorSpace_ICCBased,StrokeColorSpace_Lab};
/**
* Enumeration for attribute StrokeColorType
*/

	enum EnumStrokeColorType{StrokeColorType_Unknown,StrokeColorType_CMYGray,StrokeColorType_CMYBlack,StrokeColorType_Other,StrokeColorType_PureBlack,StrokeColorType_PureGray,StrokeColorType_RegistrationBlack,StrokeColorType_RegistrationGray,StrokeColorType_RichBlack,StrokeColorType_White};
/**
* Enumeration for attribute StrokeShadingType
*/

	enum EnumStrokeShadingType{StrokeShadingType_Unknown,StrokeShadingType_Smooth,StrokeShadingType_Vector};
/**
* Enumeration for attribute CharacterProblem
*/

	enum EnumCharacterProblem{CharacterProblem_Unknown,CharacterProblem_Corrupted,CharacterProblem_IncorrectEncoding,CharacterProblem_Missing,CharacterProblem_Others};
/**
* Enumeration for attribute UseArtificialTextEffect
*/

	enum EnumUseArtificialTextEffect{UseArtificialTextEffect_Unknown,UseArtificialTextEffect_Bold,UseArtificialTextEffect_Italic,UseArtificialTextEffect_Outline,UseArtificialTextEffect_Shadow,UseArtificialTextEffect_Underline};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute PageNumber
*@param int value: the value to set the attribute to
*/
	virtual void SetPageNumber(int value);
/**
* Get integer attribute PageNumber
* @return int the vaue of the attribute 
*/
	virtual int GetPageNumber() const;
/**
* Typesafe attribute validation of PageNumber
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageNumber(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AnnotationPrintFlag
*@param bool value: the value to set the attribute to
*/
	virtual void SetAnnotationPrintFlag(bool value);
/**
* Get bool attribute AnnotationPrintFlag
* @return bool the vaue of the attribute 
*/
	virtual bool GetAnnotationPrintFlag() const;
/**
* Typesafe attribute validation of AnnotationPrintFlag
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAnnotationPrintFlag(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AnnotationType
*@param WString value: the value to set the attribute to
*/
	virtual void SetAnnotationType(const WString& value);
/**
* Get string attribute AnnotationType
* @return WString the vaue of the attribute 
*/
	virtual WString GetAnnotationType() const;
/**
* Typesafe attribute validation of AnnotationType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAnnotationType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrapnetAnnotationPDFX
*@param vWString value: the value to set the attribute to
*/
	virtual void SetTrapnetAnnotationPDFX(const vWString& value);
/**
* Get string attribute TrapnetAnnotationPDFX
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetTrapnetAnnotationPDFX() const;
/**
* Typesafe attribute validation of TrapnetAnnotationPDFX
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrapnetAnnotationPDFX(EnumValidationLevel level=ValidationLevel_Complete) const;
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
/**
* Enumeration strings for DifferentBoxSize
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DifferentBoxSizeString();
/**
* Enumeration string for enum value
* @param EnumDifferentBoxSize value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DifferentBoxSizeString(EnumDifferentBoxSize value);
/**
* Set attribute DifferentBoxSize
* @param EnumDifferentBoxSize value the value to set the attribute to
*/
	virtual void SetDifferentBoxSize( EnumDifferentBoxSize value);

/**
* Typesafe enumerated attribute DifferentBoxSize
* @return EnumDifferentBoxSizethe enumeration value of the attribute
*/
	virtual EnumDifferentBoxSize GetDifferentBoxSize() const;

/**
* Typesafe attribute validation of DifferentBoxSize
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDifferentBoxSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute InsideBox
*@param bool value: the value to set the attribute to
*/
	virtual void SetInsideBox(bool value);
/**
* Get bool attribute InsideBox
* @return bool the vaue of the attribute 
*/
	virtual bool GetInsideBox() const;
/**
* Typesafe attribute validation of InsideBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInsideBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutsideBox
*@param bool value: the value to set the attribute to
*/
	virtual void SetOutsideBox(bool value);
/**
* Get bool attribute OutsideBox
* @return bool the vaue of the attribute 
*/
	virtual bool GetOutsideBox() const;
/**
* Typesafe attribute validation of OutsideBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutsideBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClassName
*@param WString value: the value to set the attribute to
*/
	virtual void SetClassName(const WString& value);
/**
* Get string attribute ClassName
* @return WString the vaue of the attribute 
*/
	virtual WString GetClassName() const;
/**
* Typesafe attribute validation of ClassName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClassName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PropertyList
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PropertyListString();
/**
* Enumeration string for enum value
* @param EnumPropertyList value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PropertyListString(EnumPropertyList value);
/**
* Append value to the attribute PropertyList
* @param EnumPropertyList value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddPropertyList( EnumPropertyList value);
/**
* Remove value from the attribute PropertyList
* @param EnumPropertyList value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemovePropertyList( EnumPropertyList value);
/**
* Typesafe enumerated attribute PropertyList
* @return EnumPropertyListthe enumeration value of the attribute
*/
	virtual vint GetPropertyList() const;
/**
* Set value of the attribute PropertyList
* @param EnumPropertyList value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetPropertyList( EnumPropertyList value);
/**
* Set value of the attribute PropertyList to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetPropertyList( const vint& value);
/**
* Typesafe attribute validation of PropertyList
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPropertyList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AliasSeparations
*@param bool value: the value to set the attribute to
*/
	virtual void SetAliasSeparations(bool value);
/**
* Get bool attribute AliasSeparations
* @return bool the vaue of the attribute 
*/
	virtual bool GetAliasSeparations() const;
/**
* Typesafe attribute validation of AliasSeparations
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAliasSeparations(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AmbiguousSeparations
*@param bool value: the value to set the attribute to
*/
	virtual void SetAmbiguousSeparations(bool value);
/**
* Get bool attribute AmbiguousSeparations
* @return bool the vaue of the attribute 
*/
	virtual bool GetAmbiguousSeparations() const;
/**
* Typesafe attribute validation of AmbiguousSeparations
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAmbiguousSeparations(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute InkCoverage
*@param double value: the value to set the attribute to
*/
	virtual void SetInkCoverage(double value);
/**
* Get double attribute InkCoverage
* @return double the vaue of the attribute 
*/
	virtual double GetInkCoverage() const;
/**
* Typesafe attribute validation of InkCoverage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInkCoverage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SeparationList
*@param WString value: the value to set the attribute to
*/
	virtual void SetSeparationList(const WString& value);
/**
* Get string attribute SeparationList
* @return WString the vaue of the attribute 
*/
	virtual WString GetSeparationList() const;
/**
* Typesafe attribute validation of SeparationList
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSeparationList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Author
*@param WString value: the value to set the attribute to
*/
	virtual void SetAuthor(const WString& value);
/**
* Get string attribute Author
* @return WString the vaue of the attribute 
*/
	virtual WString GetAuthor() const;
/**
* Typesafe attribute validation of Author
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAuthor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Binding
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BindingString();
/**
* Enumeration string for enum value
* @param EnumBinding value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BindingString(EnumBinding value);
/**
* Set attribute Binding
* @param EnumBinding value the value to set the attribute to
*/
	virtual void SetBinding( EnumBinding value);

/**
* Typesafe enumerated attribute Binding
* @return EnumBindingthe enumeration value of the attribute
*/
	virtual EnumBinding GetBinding() const;

/**
* Typesafe attribute validation of Binding
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBinding(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CreationDate
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetCreationDate(JDFDate value=JDFDate());
/**
* Get string attribute CreationDate
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetCreationDate() const;
/**
* Typesafe attribute validation of CreationDate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCreationDate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CreationDateInDocument
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetCreationDateInDocument(JDFDate value=JDFDate());
/**
* Get string attribute CreationDateInDocument
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetCreationDateInDocument() const;
/**
* Typesafe attribute validation of CreationDateInDocument
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCreationDateInDocument(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CreationID
*@param WString value: the value to set the attribute to
*/
	virtual void SetCreationID(const WString& value);
/**
* Get string attribute CreationID
* @return WString the vaue of the attribute 
*/
	virtual WString GetCreationID() const;
/**
* Typesafe attribute validation of CreationID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCreationID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Creator
*@param WString value: the value to set the attribute to
*/
	virtual void SetCreator(const WString& value);
/**
* Get string attribute Creator
* @return WString the vaue of the attribute 
*/
	virtual WString GetCreator() const;
/**
* Typesafe attribute validation of Creator
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCreator(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DocumentCompression
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DocumentCompressionString();
/**
* Enumeration string for enum value
* @param EnumDocumentCompression value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DocumentCompressionString(EnumDocumentCompression value);
/**
* Append value to the attribute DocumentCompression
* @param EnumDocumentCompression value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddDocumentCompression( EnumDocumentCompression value);
/**
* Remove value from the attribute DocumentCompression
* @param EnumDocumentCompression value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveDocumentCompression( EnumDocumentCompression value);
/**
* Typesafe enumerated attribute DocumentCompression
* @return EnumDocumentCompressionthe enumeration value of the attribute
*/
	virtual vint GetDocumentCompression() const;
/**
* Set value of the attribute DocumentCompression
* @param EnumDocumentCompression value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetDocumentCompression( EnumDocumentCompression value);
/**
* Set value of the attribute DocumentCompression to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetDocumentCompression( const vint& value);
/**
* Typesafe attribute validation of DocumentCompression
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDocumentCompression(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DocumentCorruption
*@param vWString value: the value to set the attribute to
*/
	virtual void SetDocumentCorruption(const vWString& value);
/**
* Get string attribute DocumentCorruption
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetDocumentCorruption() const;
/**
* Typesafe attribute validation of DocumentCorruption
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocumentCorruption(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DocumentEncoding
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DocumentEncodingString();
/**
* Enumeration string for enum value
* @param EnumDocumentEncoding value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DocumentEncodingString(EnumDocumentEncoding value);
/**
* Set attribute DocumentEncoding
* @param EnumDocumentEncoding value the value to set the attribute to
*/
	virtual void SetDocumentEncoding( EnumDocumentEncoding value);

/**
* Typesafe enumerated attribute DocumentEncoding
* @return EnumDocumentEncodingthe enumeration value of the attribute
*/
	virtual EnumDocumentEncoding GetDocumentEncoding() const;

/**
* Typesafe attribute validation of DocumentEncoding
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDocumentEncoding(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DocumentIsGoodCompression
*@param bool value: the value to set the attribute to
*/
	virtual void SetDocumentIsGoodCompression(bool value);
/**
* Get bool attribute DocumentIsGoodCompression
* @return bool the vaue of the attribute 
*/
	virtual bool GetDocumentIsGoodCompression() const;
/**
* Typesafe attribute validation of DocumentIsGoodCompression
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocumentIsGoodCompression(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncryptedDocument
*@param bool value: the value to set the attribute to
*/
	virtual void SetEncryptedDocument(bool value);
/**
* Get bool attribute EncryptedDocument
* @return bool the vaue of the attribute 
*/
	virtual bool GetEncryptedDocument() const;
/**
* Typesafe attribute validation of EncryptedDocument
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncryptedDocument(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncryptionFilter
*@param WString value: the value to set the attribute to
*/
	virtual void SetEncryptionFilter(const WString& value);
/**
* Get string attribute EncryptionFilter
* @return WString the vaue of the attribute 
*/
	virtual WString GetEncryptionFilter() const;
/**
* Typesafe attribute validation of EncryptionFilter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncryptionFilter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncryptionLength
*@param int value: the value to set the attribute to
*/
	virtual void SetEncryptionLength(int value);
/**
* Get integer attribute EncryptionLength
* @return int the vaue of the attribute 
*/
	virtual int GetEncryptionLength() const;
/**
* Typesafe attribute validation of EncryptionLength
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncryptionLength(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncryptionRestrictions
*@param vWString value: the value to set the attribute to
*/
	virtual void SetEncryptionRestrictions(const vWString& value);
/**
* Get string attribute EncryptionRestrictions
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetEncryptionRestrictions() const;
/**
* Typesafe attribute validation of EncryptionRestrictions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncryptionRestrictions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncryptionSubFilter
*@param WString value: the value to set the attribute to
*/
	virtual void SetEncryptionSubFilter(const WString& value);
/**
* Get string attribute EncryptionSubFilter
* @return WString the vaue of the attribute 
*/
	virtual WString GetEncryptionSubFilter() const;
/**
* Typesafe attribute validation of EncryptionSubFilter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncryptionSubFilter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncryptionV
*@param int value: the value to set the attribute to
*/
	virtual void SetEncryptionV(int value);
/**
* Get integer attribute EncryptionV
* @return int the vaue of the attribute 
*/
	virtual int GetEncryptionV() const;
/**
* Typesafe attribute validation of EncryptionV
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncryptionV(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FileName
*@param WString value: the value to set the attribute to
*/
	virtual void SetFileName(const WString& value);
/**
* Get string attribute FileName
* @return WString the vaue of the attribute 
*/
	virtual WString GetFileName() const;
/**
* Typesafe attribute validation of FileName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFileName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FileSize
*@param int value: the value to set the attribute to
*/
	virtual void SetFileSize(int value);
/**
* Get integer attribute FileSize
* @return int the vaue of the attribute 
*/
	virtual int GetFileSize() const;
/**
* Typesafe attribute validation of FileSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFileSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Keywords
*@param WString value: the value to set the attribute to
*/
	virtual void SetKeywords(const WString& value);
/**
* Get string attribute Keywords
* @return WString the vaue of the attribute 
*/
	virtual WString GetKeywords() const;
/**
* Typesafe attribute validation of Keywords
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidKeywords(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Linearized
*@param bool value: the value to set the attribute to
*/
	virtual void SetLinearized(bool value);
/**
* Get bool attribute Linearized
* @return bool the vaue of the attribute 
*/
	virtual bool GetLinearized() const;
/**
* Typesafe attribute validation of Linearized
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLinearized(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModificationDate
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetModificationDate(JDFDate value=JDFDate());
/**
* Get string attribute ModificationDate
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetModificationDate() const;
/**
* Typesafe attribute validation of ModificationDate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModificationDate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModificationDateInDocument
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetModificationDateInDocument(JDFDate value=JDFDate());
/**
* Get string attribute ModificationDateInDocument
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetModificationDateInDocument() const;
/**
* Typesafe attribute validation of ModificationDateInDocument
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModificationDateInDocument(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModificationID
*@param WString value: the value to set the attribute to
*/
	virtual void SetModificationID(const WString& value);
/**
* Get string attribute ModificationID
* @return WString the vaue of the attribute 
*/
	virtual WString GetModificationID() const;
/**
* Typesafe attribute validation of ModificationID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModificationID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NumberOfPages
*@param int value: the value to set the attribute to
*/
	virtual void SetNumberOfPages(int value);
/**
* Get integer attribute NumberOfPages
* @return int the vaue of the attribute 
*/
	virtual int GetNumberOfPages() const;
/**
* Typesafe attribute validation of NumberOfPages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumberOfPages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutputIntentColorSpace
*@param WString value: the value to set the attribute to
*/
	virtual void SetOutputIntentColorSpace(const WString& value);
/**
* Get string attribute OutputIntentColorSpace
* @return WString the vaue of the attribute ; defaults to None
*/
	virtual WString GetOutputIntentColorSpace() const;
/**
* Typesafe attribute validation of OutputIntentColorSpace
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutputIntentColorSpace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutputIntentStandard
*@param WString value: the value to set the attribute to
*/
	virtual void SetOutputIntentStandard(const WString& value);
/**
* Get string attribute OutputIntentStandard
* @return WString the vaue of the attribute 
*/
	virtual WString GetOutputIntentStandard() const;
/**
* Typesafe attribute validation of OutputIntentStandard
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutputIntentStandard(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PagesHaveSameOrientation
*@param bool value: the value to set the attribute to
*/
	virtual void SetPagesHaveSameOrientation(bool value);
/**
* Get bool attribute PagesHaveSameOrientation
* @return bool the vaue of the attribute 
*/
	virtual bool GetPagesHaveSameOrientation() const;
/**
* Typesafe attribute validation of PagesHaveSameOrientation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPagesHaveSameOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetPDFXVersion(const WString& value);
/**
* Get string attribute PDFXVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetPDFXVersion() const;
/**
* Typesafe attribute validation of PDFXVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DocumentPDLType
*@param WString value: the value to set the attribute to
*/
	virtual void SetDocumentPDLType(const WString& value);
/**
* Get string attribute DocumentPDLType
* @return WString the vaue of the attribute 
*/
	virtual WString GetDocumentPDLType() const;
/**
* Typesafe attribute validation of DocumentPDLType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDocumentPDLType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDLVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetPDLVersion(const WString& value);
/**
* Get string attribute PDLVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetPDLVersion() const;
/**
* Typesafe attribute validation of PDLVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDLVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Producer
*@param WString value: the value to set the attribute to
*/
	virtual void SetProducer(const WString& value);
/**
* Get string attribute Producer
* @return WString the vaue of the attribute 
*/
	virtual WString GetProducer() const;
/**
* Typesafe attribute validation of Producer
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProducer(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SeparationFlag
*@param bool value: the value to set the attribute to
*/
	virtual void SetSeparationFlag(bool value);
/**
* Get bool attribute SeparationFlag
* @return bool the vaue of the attribute 
*/
	virtual bool GetSeparationFlag() const;
/**
* Typesafe attribute validation of SeparationFlag
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSeparationFlag(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Subject
*@param WString value: the value to set the attribute to
*/
	virtual void SetSubject(const WString& value);
/**
* Get string attribute Subject
* @return WString the vaue of the attribute 
*/
	virtual WString GetSubject() const;
/**
* Typesafe attribute validation of Subject
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSubject(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Title
*@param WString value: the value to set the attribute to
*/
	virtual void SetTitle(const WString& value);
/**
* Get string attribute Title
* @return WString the vaue of the attribute 
*/
	virtual WString GetTitle() const;
/**
* Typesafe attribute validation of Title
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTitle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for TrappedKey
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TrappedKeyString();
/**
* Enumeration string for enum value
* @param EnumTrappedKey value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TrappedKeyString(EnumTrappedKey value);
/**
* Set attribute TrappedKey
* @param EnumTrappedKey value the value to set the attribute to
*/
	virtual void SetTrappedKey( EnumTrappedKey value);

/**
* Typesafe enumerated attribute TrappedKey
* @return EnumTrappedKeythe enumeration value of the attribute
*/
	virtual EnumTrappedKey GetTrappedKey() const;

/**
* Typesafe attribute validation of TrappedKey
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidTrappedKey(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FillColorName
*@param WString value: the value to set the attribute to
*/
	virtual void SetFillColorName(const WString& value);
/**
* Get string attribute FillColorName
* @return WString the vaue of the attribute 
*/
	virtual WString GetFillColorName() const;
/**
* Typesafe attribute validation of FillColorName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFillColorName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for FillColorType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FillColorTypeString();
/**
* Enumeration string for enum value
* @param EnumFillColorType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FillColorTypeString(EnumFillColorType value);
/**
* Set attribute FillColorType
* @param EnumFillColorType value the value to set the attribute to
*/
	virtual void SetFillColorType( EnumFillColorType value);

/**
* Typesafe enumerated attribute FillColorType
* @return EnumFillColorTypethe enumeration value of the attribute
*/
	virtual EnumFillColorType GetFillColorType() const;

/**
* Typesafe attribute validation of FillColorType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFillColorType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasFillColor
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasFillColor(bool value);
/**
* Get bool attribute HasFillColor
* @return bool the vaue of the attribute 
*/
	virtual bool GetHasFillColor() const;
/**
* Typesafe attribute validation of HasFillColor
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasFillColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EmbeddingRestrictionFlag
*@param bool value: the value to set the attribute to
*/
	virtual void SetEmbeddingRestrictionFlag(bool value);
/**
* Get bool attribute EmbeddingRestrictionFlag
* @return bool the vaue of the attribute 
*/
	virtual bool GetEmbeddingRestrictionFlag() const;
/**
* Typesafe attribute validation of EmbeddingRestrictionFlag
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEmbeddingRestrictionFlag(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontCorrupted
*@param bool value: the value to set the attribute to
*/
	virtual void SetFontCorrupted(bool value);
/**
* Get bool attribute FontCorrupted
* @return bool the vaue of the attribute 
*/
	virtual bool GetFontCorrupted() const;
/**
* Typesafe attribute validation of FontCorrupted
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontCorrupted(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontCreator
*@param WString value: the value to set the attribute to
*/
	virtual void SetFontCreator(const WString& value);
/**
* Get string attribute FontCreator
* @return WString the vaue of the attribute 
*/
	virtual WString GetFontCreator() const;
/**
* Typesafe attribute validation of FontCreator
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontCreator(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontEmbedded
*@param bool value: the value to set the attribute to
*/
	virtual void SetFontEmbedded(bool value);
/**
* Get bool attribute FontEmbedded
* @return bool the vaue of the attribute 
*/
	virtual bool GetFontEmbedded() const;
/**
* Typesafe attribute validation of FontEmbedded
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontEmbedded(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontIsStandardLatin
*@param bool value: the value to set the attribute to
*/
	virtual void SetFontIsStandardLatin(bool value);
/**
* Get bool attribute FontIsStandardLatin
* @return bool the vaue of the attribute 
*/
	virtual bool GetFontIsStandardLatin() const;
/**
* Typesafe attribute validation of FontIsStandardLatin
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontIsStandardLatin(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontName
*@param WString value: the value to set the attribute to
*/
	virtual void SetFontName(const WString& value);
/**
* Get string attribute FontName
* @return WString the vaue of the attribute 
*/
	virtual WString GetFontName() const;
/**
* Typesafe attribute validation of FontName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontNotUsed
*@param bool value: the value to set the attribute to
*/
	virtual void SetFontNotUsed(bool value);
/**
* Get bool attribute FontNotUsed
* @return bool the vaue of the attribute 
*/
	virtual bool GetFontNotUsed() const;
/**
* Typesafe attribute validation of FontNotUsed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontNotUsed(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontSubset
*@param bool value: the value to set the attribute to
*/
	virtual void SetFontSubset(bool value);
/**
* Get bool attribute FontSubset
* @return bool the vaue of the attribute 
*/
	virtual bool GetFontSubset() const;
/**
* Typesafe attribute validation of FontSubset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontSubset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for FontType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FontTypeString();
/**
* Enumeration string for enum value
* @param EnumFontType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FontTypeString(EnumFontType value);
/**
* Set attribute FontType
* @param EnumFontType value the value to set the attribute to
*/
	virtual void SetFontType( EnumFontType value);

/**
* Typesafe enumerated attribute FontType; defaults to Other
* @return EnumFontTypethe enumeration value of the attribute
*/
	virtual EnumFontType GetFontType() const;

/**
* Typesafe attribute validation of FontType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFontType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontVendor
*@param WString value: the value to set the attribute to
*/
	virtual void SetFontVendor(const WString& value);
/**
* Get string attribute FontVendor
* @return WString the vaue of the attribute 
*/
	virtual WString GetFontVendor() const;
/**
* Typesafe attribute validation of FontVendor
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontVendor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IsFontScreenOnly
*@param bool value: the value to set the attribute to
*/
	virtual void SetIsFontScreenOnly(bool value);
/**
* Get bool attribute IsFontScreenOnly
* @return bool the vaue of the attribute 
*/
	virtual bool GetIsFontScreenOnly() const;
/**
* Typesafe attribute validation of IsFontScreenOnly
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIsFontScreenOnly(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PSFontName
*@param WString value: the value to set the attribute to
*/
	virtual void SetPSFontName(const WString& value);
/**
* Get string attribute PSFontName
* @return WString the vaue of the attribute 
*/
	virtual WString GetPSFontName() const;
/**
* Typesafe attribute validation of PSFontName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPSFontName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AlphaIsShape
*@param bool value: the value to set the attribute to
*/
	virtual void SetAlphaIsShape(bool value);
/**
* Get bool attribute AlphaIsShape
* @return bool the vaue of the attribute 
*/
	virtual bool GetAlphaIsShape() const;
/**
* Typesafe attribute validation of AlphaIsShape
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAlphaIsShape(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for AlternateColorSpace
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& AlternateColorSpaceString();
/**
* Enumeration string for enum value
* @param EnumAlternateColorSpace value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString AlternateColorSpaceString(EnumAlternateColorSpace value);
/**
* Set attribute AlternateColorSpace
* @param EnumAlternateColorSpace value the value to set the attribute to
*/
	virtual void SetAlternateColorSpace( EnumAlternateColorSpace value);

/**
* Typesafe enumerated attribute AlternateColorSpace
* @return EnumAlternateColorSpacethe enumeration value of the attribute
*/
	virtual EnumAlternateColorSpace GetAlternateColorSpace() const;

/**
* Typesafe attribute validation of AlternateColorSpace
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidAlternateColorSpace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BelongsToAnnotation
*@param bool value: the value to set the attribute to
*/
	virtual void SetBelongsToAnnotation(bool value);
/**
* Get bool attribute BelongsToAnnotation
* @return bool the vaue of the attribute 
*/
	virtual bool GetBelongsToAnnotation() const;
/**
* Typesafe attribute validation of BelongsToAnnotation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBelongsToAnnotation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BlackGeneration
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BlackGenerationString();
/**
* Enumeration string for enum value
* @param EnumBlackGeneration value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BlackGenerationString(EnumBlackGeneration value);
/**
* Set attribute BlackGeneration
* @param EnumBlackGeneration value the value to set the attribute to
*/
	virtual void SetBlackGeneration( EnumBlackGeneration value);

/**
* Typesafe enumerated attribute BlackGeneration
* @return EnumBlackGenerationthe enumeration value of the attribute
*/
	virtual EnumBlackGeneration GetBlackGeneration() const;

/**
* Typesafe attribute validation of BlackGeneration
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBlackGeneration(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlendMode
*@param WString value: the value to set the attribute to
*/
	virtual void SetBlendMode(const WString& value);
/**
* Get string attribute BlendMode
* @return WString the vaue of the attribute 
*/
	virtual WString GetBlendMode() const;
/**
* Typesafe attribute validation of BlendMode
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlendMode(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ColorSpace
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ColorSpaceString();
/**
* Enumeration string for enum value
* @param EnumColorSpace value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ColorSpaceString(EnumColorSpace value);
/**
* Set attribute ColorSpace
* @param EnumColorSpace value the value to set the attribute to
*/
	virtual void SetColorSpace( EnumColorSpace value);

/**
* Typesafe enumerated attribute ColorSpace
* @return EnumColorSpacethe enumeration value of the attribute
*/
	virtual EnumColorSpace GetColorSpace() const;

/**
* Typesafe attribute validation of ColorSpace
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidColorSpace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EmbeddedPS
*@param bool value: the value to set the attribute to
*/
	virtual void SetEmbeddedPS(bool value);
/**
* Get bool attribute EmbeddedPS
* @return bool the vaue of the attribute 
*/
	virtual bool GetEmbeddedPS() const;
/**
* Typesafe attribute validation of EmbeddedPS
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEmbeddedPS(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Flatness
*@param double value: the value to set the attribute to
*/
	virtual void SetFlatness(double value);
/**
* Get double attribute Flatness
* @return double the vaue of the attribute 
*/
	virtual double GetFlatness() const;
/**
* Typesafe attribute validation of Flatness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFlatness(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasSoftMask
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasSoftMask(bool value);
/**
* Get bool attribute HasSoftMask
* @return bool the vaue of the attribute 
*/
	virtual bool GetHasSoftMask() const;
/**
* Typesafe attribute validation of HasSoftMask
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasSoftMask(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HalfTone
*@param WString value: the value to set the attribute to
*/
	virtual void SetHalfTone(const WString& value);
/**
* Get string attribute HalfTone
* @return WString the vaue of the attribute 
*/
	virtual WString GetHalfTone() const;
/**
* Typesafe attribute validation of HalfTone
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHalfTone(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HalfTonePhase
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetHalfTonePhase(const JDFXYPair& value);
/**
* Get string attribute HalfTonePhase
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetHalfTonePhase() const;
/**
* Typesafe attribute validation of HalfTonePhase
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHalfTonePhase(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasColorLUT
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasColorLUT(bool value);
/**
* Get bool attribute HasColorLUT
* @return bool the vaue of the attribute 
*/
	virtual bool GetHasColorLUT() const;
/**
* Typesafe attribute validation of HasColorLUT
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasColorLUT(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NumberOfColorsInLUT
*@param int value: the value to set the attribute to
*/
	virtual void SetNumberOfColorsInLUT(int value);
/**
* Get integer attribute NumberOfColorsInLUT
* @return int the vaue of the attribute 
*/
	virtual int GetNumberOfColorsInLUT() const;
/**
* Typesafe attribute validation of NumberOfColorsInLUT
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumberOfColorsInLUT(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OverPrintFlag
*@param bool value: the value to set the attribute to
*/
	virtual void SetOverPrintFlag(bool value);
/**
* Get bool attribute OverPrintFlag
* @return bool the vaue of the attribute 
*/
	virtual bool GetOverPrintFlag() const;
/**
* Typesafe attribute validation of OverPrintFlag
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOverPrintFlag(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OverPrintMode
*@param int value: the value to set the attribute to
*/
	virtual void SetOverPrintMode(int value);
/**
* Get integer attribute OverPrintMode
* @return int the vaue of the attribute 
*/
	virtual int GetOverPrintMode() const;
/**
* Typesafe attribute validation of OverPrintMode
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOverPrintMode(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RenderingIntent
*@param WString value: the value to set the attribute to
*/
	virtual void SetRenderingIntent(const WString& value);
/**
* Get string attribute RenderingIntent
* @return WString the vaue of the attribute 
*/
	virtual WString GetRenderingIntent() const;
/**
* Typesafe attribute validation of RenderingIntent
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRenderingIntent(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Smoothness
*@param double value: the value to set the attribute to
*/
	virtual void SetSmoothness(double value);
/**
* Get double attribute Smoothness
* @return double the vaue of the attribute 
*/
	virtual double GetSmoothness() const;
/**
* Typesafe attribute validation of Smoothness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSmoothness(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for TransferFunction
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TransferFunctionString();
/**
* Enumeration string for enum value
* @param EnumTransferFunction value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TransferFunctionString(EnumTransferFunction value);
/**
* Set attribute TransferFunction
* @param EnumTransferFunction value the value to set the attribute to
*/
	virtual void SetTransferFunction( EnumTransferFunction value);

/**
* Typesafe enumerated attribute TransferFunction
* @return EnumTransferFunctionthe enumeration value of the attribute
*/
	virtual EnumTransferFunction GetTransferFunction() const;

/**
* Typesafe attribute validation of TransferFunction
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidTransferFunction(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TransparencyFlag
*@param bool value: the value to set the attribute to
*/
	virtual void SetTransparencyFlag(bool value);
/**
* Get bool attribute TransparencyFlag
* @return bool the vaue of the attribute 
*/
	virtual bool GetTransparencyFlag() const;
/**
* Typesafe attribute validation of TransparencyFlag
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTransparencyFlag(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for UnderColorRemoval
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& UnderColorRemovalString();
/**
* Enumeration string for enum value
* @param EnumUnderColorRemoval value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString UnderColorRemovalString(EnumUnderColorRemoval value);
/**
* Set attribute UnderColorRemoval
* @param EnumUnderColorRemoval value the value to set the attribute to
*/
	virtual void SetUnderColorRemoval( EnumUnderColorRemoval value);

/**
* Typesafe enumerated attribute UnderColorRemoval
* @return EnumUnderColorRemovalthe enumeration value of the attribute
*/
	virtual EnumUnderColorRemoval GetUnderColorRemoval() const;

/**
* Typesafe attribute validation of UnderColorRemoval
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidUnderColorRemoval(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AlternateImages
*@param vWString value: the value to set the attribute to
*/
	virtual void SetAlternateImages(const vWString& value);
/**
* Get string attribute AlternateImages
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetAlternateImages() const;
/**
* Typesafe attribute validation of AlternateImages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAlternateImages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BitsPerSample
*@param int value: the value to set the attribute to
*/
	virtual void SetBitsPerSample(int value);
/**
* Get integer attribute BitsPerSample
* @return int the vaue of the attribute 
*/
	virtual int GetBitsPerSample() const;
/**
* Typesafe attribute validation of BitsPerSample
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBitsPerSample(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CompressionRatio
*@param double value: the value to set the attribute to
*/
	virtual void SetCompressionRatio(double value);
/**
* Get double attribute CompressionRatio
* @return double the vaue of the attribute 
*/
	virtual double GetCompressionRatio() const;
/**
* Typesafe attribute validation of CompressionRatio
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCompressionRatio(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for CompressionTypes
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CompressionTypesString();
/**
* Enumeration string for enum value
* @param EnumCompressionTypes value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CompressionTypesString(EnumCompressionTypes value);
/**
* Append value to the attribute CompressionTypes
* @param EnumCompressionTypes value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddCompressionTypes( EnumCompressionTypes value);
/**
* Remove value from the attribute CompressionTypes
* @param EnumCompressionTypes value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveCompressionTypes( EnumCompressionTypes value);
/**
* Typesafe enumerated attribute CompressionTypes
* @return EnumCompressionTypesthe enumeration value of the attribute
*/
	virtual vint GetCompressionTypes() const;
/**
* Set value of the attribute CompressionTypes
* @param EnumCompressionTypes value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetCompressionTypes( EnumCompressionTypes value);
/**
* Set value of the attribute CompressionTypes to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetCompressionTypes( const vint& value);
/**
* Typesafe attribute validation of CompressionTypes
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCompressionTypes(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EffectiveResolution
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetEffectiveResolution(const JDFXYPair& value);
/**
* Get string attribute EffectiveResolution
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetEffectiveResolution() const;
/**
* Typesafe attribute validation of EffectiveResolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEffectiveResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EstimatedJPEGQuality
*@param int value: the value to set the attribute to
*/
	virtual void SetEstimatedJPEGQuality(int value);
/**
* Get integer attribute EstimatedJPEGQuality
* @return int the vaue of the attribute 
*/
	virtual int GetEstimatedJPEGQuality() const;
/**
* Typesafe attribute validation of EstimatedJPEGQuality
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEstimatedJPEGQuality(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ImageFlipped
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ImageFlippedString();
/**
* Enumeration string for enum value
* @param EnumImageFlipped value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ImageFlippedString(EnumImageFlipped value);
/**
* Set attribute ImageFlipped
* @param EnumImageFlipped value the value to set the attribute to
*/
	virtual void SetImageFlipped( EnumImageFlipped value);

/**
* Typesafe enumerated attribute ImageFlipped
* @return EnumImageFlippedthe enumeration value of the attribute
*/
	virtual EnumImageFlipped GetImageFlipped() const;

/**
* Typesafe attribute validation of ImageFlipped
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidImageFlipped(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ImageMaskType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ImageMaskTypeString();
/**
* Enumeration string for enum value
* @param EnumImageMaskType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ImageMaskTypeString(EnumImageMaskType value);
/**
* Set attribute ImageMaskType
* @param EnumImageMaskType value the value to set the attribute to
*/
	virtual void SetImageMaskType( EnumImageMaskType value);

/**
* Typesafe enumerated attribute ImageMaskType
* @return EnumImageMaskTypethe enumeration value of the attribute
*/
	virtual EnumImageMaskType GetImageMaskType() const;

/**
* Typesafe attribute validation of ImageMaskType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidImageMaskType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageRotation
*@param int value: the value to set the attribute to
*/
	virtual void SetImageRotation(int value);
/**
* Get integer attribute ImageRotation
* @return int the vaue of the attribute 
*/
	virtual int GetImageRotation() const;
/**
* Typesafe attribute validation of ImageRotation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageRotation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageScalingRatio
*@param double value: the value to set the attribute to
*/
	virtual void SetImageScalingRatio(double value);
/**
* Get double attribute ImageScalingRatio
* @return double the vaue of the attribute 
*/
	virtual double GetImageScalingRatio() const;
/**
* Typesafe attribute validation of ImageScalingRatio
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageScalingRatio(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageSkew
*@param double value: the value to set the attribute to
*/
	virtual void SetImageSkew(double value);
/**
* Get double attribute ImageSkew
* @return double the vaue of the attribute 
*/
	virtual double GetImageSkew() const;
/**
* Typesafe attribute validation of ImageSkew
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageSkew(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OriginalResolution
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetOriginalResolution(const JDFXYPair& value);
/**
* Get string attribute OriginalResolution
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetOriginalResolution() const;
/**
* Typesafe attribute validation of OriginalResolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOriginalResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PixelHeight
*@param int value: the value to set the attribute to
*/
	virtual void SetPixelHeight(int value);
/**
* Get integer attribute PixelHeight
* @return int the vaue of the attribute 
*/
	virtual int GetPixelHeight() const;
/**
* Typesafe attribute validation of PixelHeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPixelHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PixelWidth
*@param int value: the value to set the attribute to
*/
	virtual void SetPixelWidth(int value);
/**
* Get integer attribute PixelWidth
* @return int the vaue of the attribute 
*/
	virtual int GetPixelWidth() const;
/**
* Typesafe attribute validation of PixelWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPixelWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Count
*@param int value: the value to set the attribute to
*/
	virtual void SetCount(int value);
/**
* Get integer attribute Count
* @return int the vaue of the attribute 
*/
	virtual int GetCount() const;
/**
* Typesafe attribute validation of Count
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PageBoxType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PageBoxTypeString();
/**
* Enumeration string for enum value
* @param EnumPageBoxType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PageBoxTypeString(EnumPageBoxType value);
/**
* Set attribute PageBoxType
* @param EnumPageBoxType value the value to set the attribute to
*/
	virtual void SetPageBoxType( EnumPageBoxType value);

/**
* Typesafe enumerated attribute PageBoxType
* @return EnumPageBoxTypethe enumeration value of the attribute
*/
	virtual EnumPageBoxType GetPageBoxType() const;

/**
* Typesafe attribute validation of PageBoxType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPageBoxType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlankPage
*@param bool value: the value to set the attribute to
*/
	virtual void SetBlankPage(bool value);
/**
* Get bool attribute BlankPage
* @return bool the vaue of the attribute 
*/
	virtual bool GetBlankPage() const;
/**
* Typesafe attribute validation of BlankPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlankPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BlendColorSpace
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BlendColorSpaceString();
/**
* Enumeration string for enum value
* @param EnumBlendColorSpace value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BlendColorSpaceString(EnumBlendColorSpace value);
/**
* Set attribute BlendColorSpace
* @param EnumBlendColorSpace value the value to set the attribute to
*/
	virtual void SetBlendColorSpace( EnumBlendColorSpace value);

/**
* Typesafe enumerated attribute BlendColorSpace
* @return EnumBlendColorSpacethe enumeration value of the attribute
*/
	virtual EnumBlendColorSpace GetBlendColorSpace() const;

/**
* Typesafe attribute validation of BlendColorSpace
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBlendColorSpace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageHasUnknownObjects
*@param bool value: the value to set the attribute to
*/
	virtual void SetPageHasUnknownObjects(bool value);
/**
* Get bool attribute PageHasUnknownObjects
* @return bool the vaue of the attribute 
*/
	virtual bool GetPageHasUnknownObjects() const;
/**
* Typesafe attribute validation of PageHasUnknownObjects
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageHasUnknownObjects(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ReversePageNumber
*@param int value: the value to set the attribute to
*/
	virtual void SetReversePageNumber(int value);
/**
* Get integer attribute ReversePageNumber
* @return int the vaue of the attribute 
*/
	virtual int GetReversePageNumber() const;
/**
* Typesafe attribute validation of ReversePageNumber
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidReversePageNumber(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDLType
*@param WString value: the value to set the attribute to
*/
	virtual void SetPDLType(const WString& value);
/**
* Get string attribute PDLType
* @return WString the vaue of the attribute 
*/
	virtual WString GetPDLType() const;
/**
* Typesafe attribute validation of PDLType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDLType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ExternalReferenceMissing
*@param bool value: the value to set the attribute to
*/
	virtual void SetExternalReferenceMissing(bool value);
/**
* Get bool attribute ExternalReferenceMissing
* @return bool the vaue of the attribute 
*/
	virtual bool GetExternalReferenceMissing() const;
/**
* Typesafe attribute validation of ExternalReferenceMissing
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidExternalReferenceMissing(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasExternalReference
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasExternalReference(bool value);
/**
* Get bool attribute HasExternalReference
* @return bool the vaue of the attribute 
*/
	virtual bool GetHasExternalReference() const;
/**
* Typesafe attribute validation of HasExternalReference
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasExternalReference(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasOPI
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasOPI(bool value);
/**
* Get bool attribute HasOPI
* @return bool the vaue of the attribute 
*/
	virtual bool GetHasOPI() const;
/**
* Typesafe attribute validation of HasOPI
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasOPI(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OPIMissing
*@param bool value: the value to set the attribute to
*/
	virtual void SetOPIMissing(bool value);
/**
* Get bool attribute OPIMissing
* @return bool the vaue of the attribute 
*/
	virtual bool GetOPIMissing() const;
/**
* Typesafe attribute validation of OPIMissing
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOPIMissing(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OPIType
*@param WString value: the value to set the attribute to
*/
	virtual void SetOPIType(const WString& value);
/**
* Get string attribute OPIType
* @return WString the vaue of the attribute 
*/
	virtual WString GetOPIType() const;
/**
* Typesafe attribute validation of OPIType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOPIType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OPIVersion
*@param vWString value: the value to set the attribute to
*/
	virtual void SetOPIVersion(const vWString& value);
/**
* Get string attribute OPIVersion
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetOPIVersion() const;
/**
* Typesafe attribute validation of OPIVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOPIVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ShadingType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ShadingTypeString();
/**
* Enumeration string for enum value
* @param EnumShadingType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ShadingTypeString(EnumShadingType value);
/**
* Set attribute ShadingType
* @param EnumShadingType value the value to set the attribute to
*/
	virtual void SetShadingType( EnumShadingType value);

/**
* Typesafe enumerated attribute ShadingType
* @return EnumShadingTypethe enumeration value of the attribute
*/
	virtual EnumShadingType GetShadingType() const;

/**
* Typesafe attribute validation of ShadingType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidShadingType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HasStrokeColor
*@param bool value: the value to set the attribute to
*/
	virtual void SetHasStrokeColor(bool value);
/**
* Get bool attribute HasStrokeColor
* @return bool the vaue of the attribute 
*/
	virtual bool GetHasStrokeColor() const;
/**
* Typesafe attribute validation of HasStrokeColor
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHasStrokeColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for StrokeAlternateColorSpace
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StrokeAlternateColorSpaceString();
/**
* Enumeration string for enum value
* @param EnumStrokeAlternateColorSpace value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StrokeAlternateColorSpaceString(EnumStrokeAlternateColorSpace value);
/**
* Set attribute StrokeAlternateColorSpace
* @param EnumStrokeAlternateColorSpace value the value to set the attribute to
*/
	virtual void SetStrokeAlternateColorSpace( EnumStrokeAlternateColorSpace value);

/**
* Typesafe enumerated attribute StrokeAlternateColorSpace
* @return EnumStrokeAlternateColorSpacethe enumeration value of the attribute
*/
	virtual EnumStrokeAlternateColorSpace GetStrokeAlternateColorSpace() const;

/**
* Typesafe attribute validation of StrokeAlternateColorSpace
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStrokeAlternateColorSpace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StrokeColorName
*@param WString value: the value to set the attribute to
*/
	virtual void SetStrokeColorName(const WString& value);
/**
* Get string attribute StrokeColorName
* @return WString the vaue of the attribute 
*/
	virtual WString GetStrokeColorName() const;
/**
* Typesafe attribute validation of StrokeColorName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStrokeColorName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for StrokeColorSpace
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StrokeColorSpaceString();
/**
* Enumeration string for enum value
* @param EnumStrokeColorSpace value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StrokeColorSpaceString(EnumStrokeColorSpace value);
/**
* Set attribute StrokeColorSpace
* @param EnumStrokeColorSpace value the value to set the attribute to
*/
	virtual void SetStrokeColorSpace( EnumStrokeColorSpace value);

/**
* Typesafe enumerated attribute StrokeColorSpace
* @return EnumStrokeColorSpacethe enumeration value of the attribute
*/
	virtual EnumStrokeColorSpace GetStrokeColorSpace() const;

/**
* Typesafe attribute validation of StrokeColorSpace
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStrokeColorSpace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for StrokeColorType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StrokeColorTypeString();
/**
* Enumeration string for enum value
* @param EnumStrokeColorType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StrokeColorTypeString(EnumStrokeColorType value);
/**
* Set attribute StrokeColorType
* @param EnumStrokeColorType value the value to set the attribute to
*/
	virtual void SetStrokeColorType( EnumStrokeColorType value);

/**
* Typesafe enumerated attribute StrokeColorType
* @return EnumStrokeColorTypethe enumeration value of the attribute
*/
	virtual EnumStrokeColorType GetStrokeColorType() const;

/**
* Typesafe attribute validation of StrokeColorType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStrokeColorType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StrokeOverprintFlag
*@param bool value: the value to set the attribute to
*/
	virtual void SetStrokeOverprintFlag(bool value);
/**
* Get bool attribute StrokeOverprintFlag
* @return bool the vaue of the attribute 
*/
	virtual bool GetStrokeOverprintFlag() const;
/**
* Typesafe attribute validation of StrokeOverprintFlag
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStrokeOverprintFlag(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for StrokeShadingType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StrokeShadingTypeString();
/**
* Enumeration string for enum value
* @param EnumStrokeShadingType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StrokeShadingTypeString(EnumStrokeShadingType value);
/**
* Set attribute StrokeShadingType
* @param EnumStrokeShadingType value the value to set the attribute to
*/
	virtual void SetStrokeShadingType( EnumStrokeShadingType value);

/**
* Typesafe enumerated attribute StrokeShadingType
* @return EnumStrokeShadingTypethe enumeration value of the attribute
*/
	virtual EnumStrokeShadingType GetStrokeShadingType() const;

/**
* Typesafe attribute validation of StrokeShadingType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStrokeShadingType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StrokeThickness
*@param double value: the value to set the attribute to
*/
	virtual void SetStrokeThickness(double value);
/**
* Get double attribute StrokeThickness
* @return double the vaue of the attribute 
*/
	virtual double GetStrokeThickness() const;
/**
* Typesafe attribute validation of StrokeThickness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStrokeThickness(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for CharacterProblem
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CharacterProblemString();
/**
* Enumeration string for enum value
* @param EnumCharacterProblem value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CharacterProblemString(EnumCharacterProblem value);
/**
* Set attribute CharacterProblem
* @param EnumCharacterProblem value the value to set the attribute to
*/
	virtual void SetCharacterProblem( EnumCharacterProblem value);

/**
* Typesafe enumerated attribute CharacterProblem
* @return EnumCharacterProblemthe enumeration value of the attribute
*/
	virtual EnumCharacterProblem GetCharacterProblem() const;

/**
* Typesafe attribute validation of CharacterProblem
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCharacterProblem(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MissingPrinterFont
*@param bool value: the value to set the attribute to
*/
	virtual void SetMissingPrinterFont(bool value);
/**
* Get bool attribute MissingPrinterFont
* @return bool the vaue of the attribute 
*/
	virtual bool GetMissingPrinterFont() const;
/**
* Typesafe attribute validation of MissingPrinterFont
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMissingPrinterFont(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MissingScreenFont
*@param bool value: the value to set the attribute to
*/
	virtual void SetMissingScreenFont(bool value);
/**
* Get bool attribute MissingScreenFont
* @return bool the vaue of the attribute 
*/
	virtual bool GetMissingScreenFont() const;
/**
* Typesafe attribute validation of MissingScreenFont
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMissingScreenFont(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TextSize
*@param double value: the value to set the attribute to
*/
	virtual void SetTextSize(double value);
/**
* Get double attribute TextSize
* @return double the vaue of the attribute 
*/
	virtual double GetTextSize() const;
/**
* Typesafe attribute validation of TextSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTextSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for UseArtificialTextEffect
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& UseArtificialTextEffectString();
/**
* Enumeration string for enum value
* @param EnumUseArtificialTextEffect value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString UseArtificialTextEffectString(EnumUseArtificialTextEffect value);
/**
* Set attribute UseArtificialTextEffect
* @param EnumUseArtificialTextEffect value the value to set the attribute to
*/
	virtual void SetUseArtificialTextEffect( EnumUseArtificialTextEffect value);

/**
* Typesafe enumerated attribute UseArtificialTextEffect
* @return EnumUseArtificialTextEffectthe enumeration value of the attribute
*/
	virtual EnumUseArtificialTextEffect GetUseArtificialTextEffect() const;

/**
* Typesafe attribute validation of UseArtificialTextEffect
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidUseArtificialTextEffect(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NumberOfPathPoints
*@param int value: the value to set the attribute to
*/
	virtual void SetNumberOfPathPoints(int value);
/**
* Get integer attribute NumberOfPathPoints
* @return int the vaue of the attribute 
*/
	virtual int GetNumberOfPathPoints() const;
/**
* Typesafe attribute validation of NumberOfPathPoints
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumberOfPathPoints(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element QualityControlResult
* 
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetCreateQualityControlResult(int iSkip=0);

/**
* const get element QualityControlResult
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetQualityControlResult(int iSkip=0)const;
/**
* Append element QualityControlResult
 */
	JDFQualityControlResult AppendQualityControlResult();
/**
* create inter-resource link to refTarget
* @param JDFQualityControlResult& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefQualityControlResult(JDFQualityControlResult& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPRGroupOccurrenceBase

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPRGroupOccurrenceBase_H_
