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

 
#if !defined _JDFAutoColorSpaceConversionOp_H_
#define _JDFAutoColorSpaceConversionOp_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFDeviceNSpace;
class JDFFileSpec;
class JDFSeparationSpec;
class JDFQualityControlResult;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoColorSpaceConversionOp : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoColorSpaceConversionOp class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFColorSpaceConversionOp should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoColorSpaceConversionOp : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoColorSpaceConversionOp():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoColorSpaceConversionOp(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoColorSpaceConversionOp &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoColorSpaceConversionOp(){};
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
* Enumeration for attribute RenderingIntent
*/

	enum EnumRenderingIntent{RenderingIntent_Unknown,RenderingIntent_ColorSpaceDependent,RenderingIntent_Perceptual,RenderingIntent_Saturation,RenderingIntent_RelativeColorimetric,RenderingIntent_AbsoluteColorimetric};
/**
* Enumeration for attribute SourceObjects
*/

	enum EnumSourceObjects{SourceObjects_Unknown,SourceObjects_All,SourceObjects_ImagePhotographic,SourceObjects_ImageScreenShot,SourceObjects_Text,SourceObjects_LineArt,SourceObjects_SmoothShades};
/**
* Enumeration for attribute Operation
*/

	enum EnumOperation{Operation_Unknown,Operation_Convert,Operation_Tag,Operation_Untag,Operation_Retag,Operation_ConvertIgnore};
/**
* Enumeration for attribute SourceCS
*/

	enum EnumSourceCS{SourceCS_Unknown,SourceCS_CalGray,SourceCS_CalRGB,SourceCS_Calibrated,SourceCS_CIEBased,SourceCS_CMYK,SourceCS_DeviceN,SourceCS_DevIndep,SourceCS_RGB,SourceCS_Gray,SourceCS_ICCBased,SourceCS_ICCCMYK,SourceCS_ICCGray,SourceCS_ICCLAB,SourceCS_ICCRGB,SourceCS_Lab,SourceCS_Separtation,SourceCS_YUV,SourceCS_All};
/**
* Enumeration for attribute SourceRenderingIntent
*/

	enum EnumSourceRenderingIntent{SourceRenderingIntent_Unknown,SourceRenderingIntent_ColorSpaceDependent,SourceRenderingIntent_Perceptual,SourceRenderingIntent_Saturation,SourceRenderingIntent_RelativeColorimetric,SourceRenderingIntent_AbsoluteColorimetric};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute IgnoreEmbeddedICC
*@param bool value: the value to set the attribute to
*/
	virtual void SetIgnoreEmbeddedICC(bool value);
/**
* Get bool attribute IgnoreEmbeddedICC
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIgnoreEmbeddedICC() const;
/**
* Typesafe attribute validation of IgnoreEmbeddedICC
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIgnoreEmbeddedICC(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreserveBlack
*@param bool value: the value to set the attribute to
*/
	virtual void SetPreserveBlack(bool value);
/**
* Get bool attribute PreserveBlack
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPreserveBlack() const;
/**
* Typesafe attribute validation of PreserveBlack
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreserveBlack(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for RenderingIntent
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& RenderingIntentString();
/**
* Enumeration string for enum value
* @param EnumRenderingIntent value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString RenderingIntentString(EnumRenderingIntent value);
/**
* Set attribute RenderingIntent
* @param EnumRenderingIntent value the value to set the attribute to
*/
	virtual void SetRenderingIntent( EnumRenderingIntent value);

/**
* Typesafe enumerated attribute RenderingIntent; defaults to ColorSpaceDependent
* @return EnumRenderingIntentthe enumeration value of the attribute
*/
	virtual EnumRenderingIntent GetRenderingIntent() const;

/**
* Typesafe attribute validation of RenderingIntent
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidRenderingIntent(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RGBGray2Black
*@param bool value: the value to set the attribute to
*/
	virtual void SetRGBGray2Black(bool value);
/**
* Get bool attribute RGBGray2Black
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetRGBGray2Black() const;
/**
* Typesafe attribute validation of RGBGray2Black
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRGBGray2Black(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RGBGray2BlackThreshold
*@param double value: the value to set the attribute to
*/
	virtual void SetRGBGray2BlackThreshold(double value);
/**
* Get double attribute RGBGray2BlackThreshold
* @return double the vaue of the attribute ; defaults to 1
*/
	virtual double GetRGBGray2BlackThreshold() const;
/**
* Typesafe attribute validation of RGBGray2BlackThreshold
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRGBGray2BlackThreshold(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SourceObjects
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SourceObjectsString();
/**
* Enumeration string for enum value
* @param EnumSourceObjects value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SourceObjectsString(EnumSourceObjects value);
/**
* Append value to the attribute SourceObjects
* @param EnumSourceObjects value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddSourceObjects( EnumSourceObjects value);
/**
* Remove value from the attribute SourceObjects
* @param EnumSourceObjects value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveSourceObjects( EnumSourceObjects value);
/**
* Typesafe enumerated attribute SourceObjects; defaults to All
* @return EnumSourceObjectsthe enumeration value of the attribute
*/
	virtual vint GetSourceObjects() const;
/**
* Set value of the attribute SourceObjects
* @param EnumSourceObjects value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetSourceObjects( EnumSourceObjects value);
/**
* Set value of the attribute SourceObjects to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetSourceObjects( const vint& value);
/**
* Typesafe attribute validation of SourceObjects
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSourceObjects(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ObjectTags
*@param vWString value: the value to set the attribute to
*/
	virtual void SetObjectTags(const vWString& value);
/**
* Get string attribute ObjectTags
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetObjectTags() const;
/**
* Typesafe attribute validation of ObjectTags
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidObjectTags(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Operation
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OperationString();
/**
* Enumeration string for enum value
* @param EnumOperation value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OperationString(EnumOperation value);
/**
* Set attribute Operation
* @param EnumOperation value the value to set the attribute to
*/
	virtual void SetOperation( EnumOperation value);

/**
* Typesafe enumerated attribute Operation
* @return EnumOperationthe enumeration value of the attribute
*/
	virtual EnumOperation GetOperation() const;

/**
* Typesafe attribute validation of Operation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOperation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SourceCS
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SourceCSString();
/**
* Enumeration string for enum value
* @param EnumSourceCS value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SourceCSString(EnumSourceCS value);
/**
* Set attribute SourceCS
* @param EnumSourceCS value the value to set the attribute to
*/
	virtual void SetSourceCS( EnumSourceCS value);

/**
* Typesafe enumerated attribute SourceCS
* @return EnumSourceCSthe enumeration value of the attribute
*/
	virtual EnumSourceCS GetSourceCS() const;

/**
* Typesafe attribute validation of SourceCS
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSourceCS(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SourceRenderingIntent
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SourceRenderingIntentString();
/**
* Enumeration string for enum value
* @param EnumSourceRenderingIntent value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SourceRenderingIntentString(EnumSourceRenderingIntent value);
/**
* Set attribute SourceRenderingIntent
* @param EnumSourceRenderingIntent value the value to set the attribute to
*/
	virtual void SetSourceRenderingIntent( EnumSourceRenderingIntent value);

/**
* Typesafe enumerated attribute SourceRenderingIntent
* @return EnumSourceRenderingIntentthe enumeration value of the attribute
*/
	virtual EnumSourceRenderingIntent GetSourceRenderingIntent() const;

/**
* Typesafe attribute validation of SourceRenderingIntent
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSourceRenderingIntent(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element DeviceNSpace
* 
* @param int iSkip number of elements to skip
* @return JDFDeviceNSpace The element
*/
	JDFDeviceNSpace GetCreateDeviceNSpace(int iSkip=0);

/**
* const get element DeviceNSpace
* @param int iSkip number of elements to skip
* @return JDFDeviceNSpace The element
*/
	JDFDeviceNSpace GetDeviceNSpace(int iSkip=0)const;
/**
* Append element DeviceNSpace
 */
	JDFDeviceNSpace AppendDeviceNSpace();
/**
* create inter-resource link to refTarget
* @param JDFDeviceNSpace& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDeviceNSpace(JDFDeviceNSpace& refTarget);

/** Get Element FileSpec
* 
* @param int iSkip number of elements to skip
* @return JDFFileSpec The element
*/
	JDFFileSpec GetCreateFileSpec(int iSkip=0);

/**
* const get element FileSpec
* @param int iSkip number of elements to skip
* @return JDFFileSpec The element
*/
	JDFFileSpec GetFileSpec(int iSkip=0)const;
/**
* Append element FileSpec
 */
	JDFFileSpec AppendFileSpec();
/**
* create inter-resource link to refTarget
* @param JDFFileSpec& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefFileSpec(JDFFileSpec& refTarget);

/** Get Element SeparationSpec
* 
* @param int iSkip number of elements to skip
* @return JDFSeparationSpec The element
*/
	JDFSeparationSpec GetCreateSeparationSpec(int iSkip=0);

/**
* const get element SeparationSpec
* @param int iSkip number of elements to skip
* @return JDFSeparationSpec The element
*/
	JDFSeparationSpec GetSeparationSpec(int iSkip=0)const;
/**
* Append element SeparationSpec
 */
	JDFSeparationSpec AppendSeparationSpec();

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
}; // endJDFAutoColorSpaceConversionOp

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoColorSpaceConversionOp_H_
