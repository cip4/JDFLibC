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

 
#if !defined _JDFAutoScanParams_H_
#define _JDFAutoScanParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFFileSpec;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoScanParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoScanParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFScanParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoScanParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoScanParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoScanParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoScanParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoScanParams(){};
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
* Enumeration for attribute OutputColorSpace
*/

	enum EnumOutputColorSpace{OutputColorSpace_Unknown,OutputColorSpace_LAB,OutputColorSpace_RGB,OutputColorSpace_CMYK,OutputColorSpace_GrayScale};
/**
* Enumeration for attribute CompressionFilter
*/

	enum EnumCompressionFilter{CompressionFilter_Unknown,CompressionFilter_CCITTFaxEncode,CompressionFilter_DCTEncode,CompressionFilter_FlateEncode,CompressionFilter_WaveletEncode,CompressionFilter_JBIG2Encode};
/**
* Enumeration for attribute Mounting
*/

	enum EnumMounting{Mounting_Unknown,Mounting_Unfixed,Mounting_Fixed,Mounting_Wet,Mounting_Registered};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BitDepth
*@param int value: the value to set the attribute to
*/
	virtual void SetBitDepth(int value);
/**
* Get integer attribute BitDepth
* @return int the vaue of the attribute 
*/
	virtual int GetBitDepth() const;
/**
* Typesafe attribute validation of BitDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBitDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Magnification
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetMagnification(const JDFXYPair& value);
/**
* Get string attribute Magnification
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	virtual JDFXYPair GetMagnification() const;
/**
* Typesafe attribute validation of Magnification
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMagnification(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for OutputColorSpace
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OutputColorSpaceString();
/**
* Enumeration string for enum value
* @param EnumOutputColorSpace value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OutputColorSpaceString(EnumOutputColorSpace value);
/**
* Set attribute OutputColorSpace
* @param EnumOutputColorSpace value the value to set the attribute to
*/
	virtual void SetOutputColorSpace( EnumOutputColorSpace value);

/**
* Typesafe enumerated attribute OutputColorSpace
* @return EnumOutputColorSpacethe enumeration value of the attribute
*/
	virtual EnumOutputColorSpace GetOutputColorSpace() const;

/**
* Typesafe attribute validation of OutputColorSpace
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOutputColorSpace(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for CompressionFilter
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CompressionFilterString();
/**
* Enumeration string for enum value
* @param EnumCompressionFilter value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CompressionFilterString(EnumCompressionFilter value);
/**
* Set attribute CompressionFilter
* @param EnumCompressionFilter value the value to set the attribute to
*/
	virtual void SetCompressionFilter( EnumCompressionFilter value);

/**
* Typesafe enumerated attribute CompressionFilter
* @return EnumCompressionFilterthe enumeration value of the attribute
*/
	virtual EnumCompressionFilter GetCompressionFilter() const;

/**
* Typesafe attribute validation of CompressionFilter
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCompressionFilter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DCTQuality
*@param double value: the value to set the attribute to
*/
	virtual void SetDCTQuality(double value);
/**
* Get double attribute DCTQuality
* @return double the vaue of the attribute 
*/
	virtual double GetDCTQuality() const;
/**
* Typesafe attribute validation of DCTQuality
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDCTQuality(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute InputBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetInputBox(const JDFRectangle& value);
/**
* Get string attribute InputBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetInputBox() const;
/**
* Typesafe attribute validation of InputBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInputBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MountID
*@param WString value: the value to set the attribute to
*/
	virtual void SetMountID(const WString& value);
/**
* Get string attribute MountID
* @return WString the vaue of the attribute 
*/
	virtual WString GetMountID() const;
/**
* Typesafe attribute validation of MountID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMountID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Mounting
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MountingString();
/**
* Enumeration string for enum value
* @param EnumMounting value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MountingString(EnumMounting value);
/**
* Set attribute Mounting
* @param EnumMounting value the value to set the attribute to
*/
	virtual void SetMounting( EnumMounting value);

/**
* Typesafe enumerated attribute Mounting
* @return EnumMountingthe enumeration value of the attribute
*/
	virtual EnumMounting GetMounting() const;

/**
* Typesafe attribute validation of Mounting
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMounting(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutputResolution
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetOutputResolution(const JDFXYPair& value);
/**
* Get string attribute OutputResolution
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetOutputResolution() const;
/**
* Typesafe attribute validation of OutputResolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutputResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OutputSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetOutputSize(const JDFXYPair& value);
/**
* Get string attribute OutputSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetOutputSize() const;
/**
* Typesafe attribute validation of OutputSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOutputSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SplitDocuments
*@param int value: the value to set the attribute to
*/
	virtual void SetSplitDocuments(int value);
/**
* Get integer attribute SplitDocuments
* @return int the vaue of the attribute 
*/
	virtual int GetSplitDocuments() const;
/**
* Typesafe attribute validation of SplitDocuments
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSplitDocuments(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


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

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoScanParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoScanParams_H_
