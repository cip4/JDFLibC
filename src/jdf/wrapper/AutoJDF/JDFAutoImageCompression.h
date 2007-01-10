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

 
#if !defined _JDFAutoImageCompression_H_
#define _JDFAutoImageCompression_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFCCITTFaxParams;
class JDFDCTParams;
class JDFJBIG2Params;
class JDFJPEG2000Params;
class JDFLZWParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoImageCompression : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoImageCompression class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFImageCompression should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoImageCompression : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoImageCompression():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoImageCompression(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoImageCompression &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoImageCompression(){};
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
* Enumeration for attribute ImageDownsampleType
*/

	enum EnumImageDownsampleType{ImageDownsampleType_Unknown,ImageDownsampleType_Average,ImageDownsampleType_Bicubic,ImageDownsampleType_Subsample};
/**
* Enumeration for attribute ImageType
*/

	enum EnumImageType{ImageType_Unknown,ImageType_Color,ImageType_Grayscale,ImageType_Monochrome};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AntiAliasImages
*@param bool value: the value to set the attribute to
*/
	virtual void SetAntiAliasImages(bool value);
/**
* Get bool attribute AntiAliasImages
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetAntiAliasImages() const;
/**
* Typesafe attribute validation of AntiAliasImages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAntiAliasImages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AutoFilterImages
*@param bool value: the value to set the attribute to
*/
	virtual void SetAutoFilterImages(bool value);
/**
* Get bool attribute AutoFilterImages
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetAutoFilterImages() const;
/**
* Typesafe attribute validation of AutoFilterImages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAutoFilterImages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ConvertImagesToIndexed
*@param bool value: the value to set the attribute to
*/
	virtual void SetConvertImagesToIndexed(bool value);
/**
* Get bool attribute ConvertImagesToIndexed
* @return bool the vaue of the attribute 
*/
	virtual bool GetConvertImagesToIndexed() const;
/**
* Typesafe attribute validation of ConvertImagesToIndexed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidConvertImagesToIndexed(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DCTQuality
*@param double value: the value to set the attribute to
*/
	virtual void SetDCTQuality(double value);
/**
* Get double attribute DCTQuality
* @return double the vaue of the attribute ; defaults to 0
*/
	virtual double GetDCTQuality() const;
/**
* Typesafe attribute validation of DCTQuality
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDCTQuality(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DownsampleImages
*@param bool value: the value to set the attribute to
*/
	virtual void SetDownsampleImages(bool value);
/**
* Get bool attribute DownsampleImages
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetDownsampleImages() const;
/**
* Typesafe attribute validation of DownsampleImages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDownsampleImages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncodeColorImages
*@param bool value: the value to set the attribute to
*/
	virtual void SetEncodeColorImages(bool value);
/**
* Get bool attribute EncodeColorImages
* @return bool the vaue of the attribute 
*/
	virtual bool GetEncodeColorImages() const;
/**
* Typesafe attribute validation of EncodeColorImages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncodeColorImages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncodeImages
*@param bool value: the value to set the attribute to
*/
	virtual void SetEncodeImages(bool value);
/**
* Get bool attribute EncodeImages
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetEncodeImages() const;
/**
* Typesafe attribute validation of EncodeImages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncodeImages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageAutoFilterStrategy
*@param WString value: the value to set the attribute to
*/
	virtual void SetImageAutoFilterStrategy(const WString& value);
/**
* Get string attribute ImageAutoFilterStrategy
* @return WString the vaue of the attribute 
*/
	virtual WString GetImageAutoFilterStrategy() const;
/**
* Typesafe attribute validation of ImageAutoFilterStrategy
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageAutoFilterStrategy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageDepth
*@param int value: the value to set the attribute to
*/
	virtual void SetImageDepth(int value);
/**
* Get integer attribute ImageDepth
* @return int the vaue of the attribute 
*/
	virtual int GetImageDepth() const;
/**
* Typesafe attribute validation of ImageDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageDownsampleThreshold
*@param double value: the value to set the attribute to
*/
	virtual void SetImageDownsampleThreshold(double value);
/**
* Get double attribute ImageDownsampleThreshold
* @return double the vaue of the attribute ; defaults to 2.0
*/
	virtual double GetImageDownsampleThreshold() const;
/**
* Typesafe attribute validation of ImageDownsampleThreshold
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageDownsampleThreshold(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ImageDownsampleType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ImageDownsampleTypeString();
/**
* Enumeration string for enum value
* @param EnumImageDownsampleType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ImageDownsampleTypeString(EnumImageDownsampleType value);
/**
* Set attribute ImageDownsampleType
* @param EnumImageDownsampleType value the value to set the attribute to
*/
	virtual void SetImageDownsampleType( EnumImageDownsampleType value);

/**
* Typesafe enumerated attribute ImageDownsampleType
* @return EnumImageDownsampleTypethe enumeration value of the attribute
*/
	virtual EnumImageDownsampleType GetImageDownsampleType() const;

/**
* Typesafe attribute validation of ImageDownsampleType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidImageDownsampleType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageFilter
*@param WString value: the value to set the attribute to
*/
	virtual void SetImageFilter(const WString& value);
/**
* Get string attribute ImageFilter
* @return WString the vaue of the attribute 
*/
	virtual WString GetImageFilter() const;
/**
* Typesafe attribute validation of ImageFilter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageFilter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageResolution
*@param double value: the value to set the attribute to
*/
	virtual void SetImageResolution(double value);
/**
* Get double attribute ImageResolution
* @return double the vaue of the attribute 
*/
	virtual double GetImageResolution() const;
/**
* Typesafe attribute validation of ImageResolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ImageType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ImageTypeString();
/**
* Enumeration string for enum value
* @param EnumImageType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ImageTypeString(EnumImageType value);
/**
* Set attribute ImageType
* @param EnumImageType value the value to set the attribute to
*/
	virtual void SetImageType( EnumImageType value);

/**
* Typesafe enumerated attribute ImageType
* @return EnumImageTypethe enumeration value of the attribute
*/
	virtual EnumImageType GetImageType() const;

/**
* Typesafe attribute validation of ImageType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidImageType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JPXQuality
*@param int value: the value to set the attribute to
*/
	virtual void SetJPXQuality(int value);
/**
* Get integer attribute JPXQuality
* @return int the vaue of the attribute 
*/
	virtual int GetJPXQuality() const;
/**
* Typesafe attribute validation of JPXQuality
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJPXQuality(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element CCITTFaxParams
* 
* @param int iSkip number of elements to skip
* @return JDFCCITTFaxParams The element
*/
	JDFCCITTFaxParams GetCreateCCITTFaxParams(int iSkip=0);

/**
* const get element CCITTFaxParams
* @param int iSkip number of elements to skip
* @return JDFCCITTFaxParams The element
*/
	JDFCCITTFaxParams GetCCITTFaxParams(int iSkip=0)const;
/**
* Append element CCITTFaxParams
 */
	JDFCCITTFaxParams AppendCCITTFaxParams();

/** Get Element DCTParams
* 
* @param int iSkip number of elements to skip
* @return JDFDCTParams The element
*/
	JDFDCTParams GetCreateDCTParams(int iSkip=0);

/**
* const get element DCTParams
* @param int iSkip number of elements to skip
* @return JDFDCTParams The element
*/
	JDFDCTParams GetDCTParams(int iSkip=0)const;
/**
* Append element DCTParams
 */
	JDFDCTParams AppendDCTParams();

/** Get Element JBIG2Params
* 
* @param int iSkip number of elements to skip
* @return JDFJBIG2Params The element
*/
	JDFJBIG2Params GetCreateJBIG2Params(int iSkip=0);

/**
* const get element JBIG2Params
* @param int iSkip number of elements to skip
* @return JDFJBIG2Params The element
*/
	JDFJBIG2Params GetJBIG2Params(int iSkip=0)const;
/**
* Append element JBIG2Params
 */
	JDFJBIG2Params AppendJBIG2Params();

/** Get Element JPEG2000Params
* 
* @param int iSkip number of elements to skip
* @return JDFJPEG2000Params The element
*/
	JDFJPEG2000Params GetCreateJPEG2000Params(int iSkip=0);

/**
* const get element JPEG2000Params
* @param int iSkip number of elements to skip
* @return JDFJPEG2000Params The element
*/
	JDFJPEG2000Params GetJPEG2000Params(int iSkip=0)const;
/**
* Append element JPEG2000Params
 */
	JDFJPEG2000Params AppendJPEG2000Params();

/** Get Element LZWParams
* 
* @param int iSkip number of elements to skip
* @return JDFLZWParams The element
*/
	JDFLZWParams GetCreateLZWParams(int iSkip=0);

/**
* const get element LZWParams
* @param int iSkip number of elements to skip
* @return JDFLZWParams The element
*/
	JDFLZWParams GetLZWParams(int iSkip=0)const;
/**
* Append element LZWParams
 */
	JDFLZWParams AppendLZWParams();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoImageCompression

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoImageCompression_H_
