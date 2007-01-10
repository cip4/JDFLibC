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

 
#if !defined _JDFAutoPSToPDFConversionParams_H_
#define _JDFAutoPSToPDFConversionParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFAdvancedParams;
class JDFPDFXParams;
class JDFThinPDFParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPSToPDFConversionParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPSToPDFConversionParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPSToPDFConversionParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPSToPDFConversionParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPSToPDFConversionParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoPSToPDFConversionParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPSToPDFConversionParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPSToPDFConversionParams(){};
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
* Enumeration for attribute Binding
*/

	enum EnumBinding{Binding_Unknown,Binding_Left,Binding_Right};
/**
* Enumeration for attribute AutoRotatePages
*/

	enum EnumAutoRotatePages{AutoRotatePages_Unknown,AutoRotatePages_None,AutoRotatePages_All,AutoRotatePages_PageByPage};
/**
* Enumeration for attribute DefaultRenderingIntent
*/

	enum EnumDefaultRenderingIntent{DefaultRenderingIntent_Unknown,DefaultRenderingIntent_Default,DefaultRenderingIntent_Perceptual,DefaultRenderingIntent_Saturation,DefaultRenderingIntent_RelativeColorimetric,DefaultRenderingIntent_AbsoluteColorimetric};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ASCII85EncodePages
*@param bool value: the value to set the attribute to
*/
	virtual void SetASCII85EncodePages(bool value);
/**
* Get bool attribute ASCII85EncodePages
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetASCII85EncodePages() const;
/**
* Typesafe attribute validation of ASCII85EncodePages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidASCII85EncodePages(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Typesafe enumerated attribute Binding; defaults to Left
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
* Set attribute DetectBlend
*@param bool value: the value to set the attribute to
*/
	virtual void SetDetectBlend(bool value);
/**
* Get bool attribute DetectBlend
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetDetectBlend() const;
/**
* Typesafe attribute validation of DetectBlend
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDetectBlend(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DoThumbnails
*@param bool value: the value to set the attribute to
*/
	virtual void SetDoThumbnails(bool value);
/**
* Get bool attribute DoThumbnails
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetDoThumbnails() const;
/**
* Typesafe attribute validation of DoThumbnails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDoThumbnails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Optimize
*@param bool value: the value to set the attribute to
*/
	virtual void SetOptimize(bool value);
/**
* Get bool attribute Optimize
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetOptimize() const;
/**
* Typesafe attribute validation of Optimize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOptimize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for AutoRotatePages
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& AutoRotatePagesString();
/**
* Enumeration string for enum value
* @param EnumAutoRotatePages value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString AutoRotatePagesString(EnumAutoRotatePages value);
/**
* Set attribute AutoRotatePages
* @param EnumAutoRotatePages value the value to set the attribute to
*/
	virtual void SetAutoRotatePages( EnumAutoRotatePages value);

/**
* Typesafe enumerated attribute AutoRotatePages
* @return EnumAutoRotatePagesthe enumeration value of the attribute
*/
	virtual EnumAutoRotatePages GetAutoRotatePages() const;

/**
* Typesafe attribute validation of AutoRotatePages
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidAutoRotatePages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CompressPages
*@param bool value: the value to set the attribute to
*/
	virtual void SetCompressPages(bool value);
/**
* Get bool attribute CompressPages
* @return bool the vaue of the attribute 
*/
	virtual bool GetCompressPages() const;
/**
* Typesafe attribute validation of CompressPages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCompressPages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DefaultRenderingIntent
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DefaultRenderingIntentString();
/**
* Enumeration string for enum value
* @param EnumDefaultRenderingIntent value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DefaultRenderingIntentString(EnumDefaultRenderingIntent value);
/**
* Set attribute DefaultRenderingIntent
* @param EnumDefaultRenderingIntent value the value to set the attribute to
*/
	virtual void SetDefaultRenderingIntent( EnumDefaultRenderingIntent value);

/**
* Typesafe enumerated attribute DefaultRenderingIntent
* @return EnumDefaultRenderingIntentthe enumeration value of the attribute
*/
	virtual EnumDefaultRenderingIntent GetDefaultRenderingIntent() const;

/**
* Typesafe attribute validation of DefaultRenderingIntent
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDefaultRenderingIntent(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EndPage
*@param int value: the value to set the attribute to
*/
	virtual void SetEndPage(int value);
/**
* Get integer attribute EndPage
* @return int the vaue of the attribute 
*/
	virtual int GetEndPage() const;
/**
* Typesafe attribute validation of EndPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEndPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageMemory
*@param int value: the value to set the attribute to
*/
	virtual void SetImageMemory(int value);
/**
* Get integer attribute ImageMemory
* @return int the vaue of the attribute 
*/
	virtual int GetImageMemory() const;
/**
* Typesafe attribute validation of ImageMemory
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageMemory(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute InitialPageSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetInitialPageSize(const JDFXYPair& value);
/**
* Get string attribute InitialPageSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetInitialPageSize() const;
/**
* Typesafe attribute validation of InitialPageSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInitialPageSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute InitialResolution
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetInitialResolution(const JDFXYPair& value);
/**
* Get string attribute InitialResolution
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetInitialResolution() const;
/**
* Typesafe attribute validation of InitialResolution
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInitialResolution(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute PDFVersion
*@param double value: the value to set the attribute to
*/
	virtual void SetPDFVersion(double value);
/**
* Get double attribute PDFVersion
* @return double the vaue of the attribute 
*/
	virtual double GetPDFVersion() const;
/**
* Typesafe attribute validation of PDFVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StartPage
*@param int value: the value to set the attribute to
*/
	virtual void SetStartPage(int value);
/**
* Get integer attribute StartPage
* @return int the vaue of the attribute 
*/
	virtual int GetStartPage() const;
/**
* Typesafe attribute validation of StartPage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStartPage(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element AdvancedParams
* 
* @return JDFAdvancedParams The element
*/
	JDFAdvancedParams GetCreateAdvancedParams();

/**
* const get element AdvancedParams
*@return  JDFAdvancedParams The element
*/
	JDFAdvancedParams GetAdvancedParams()const;
/**
* Append element AdvancedParams
 * 
*/
	JDFAdvancedParams AppendAdvancedParams();

/** Get Element PDFXParams
* 
* @return JDFPDFXParams The element
*/
	JDFPDFXParams GetCreatePDFXParams();

/**
* const get element PDFXParams
*@return  JDFPDFXParams The element
*/
	JDFPDFXParams GetPDFXParams()const;
/**
* Append element PDFXParams
 * 
*/
	JDFPDFXParams AppendPDFXParams();

/** Get Element ThinPDFParams
* 
* @return JDFThinPDFParams The element
*/
	JDFThinPDFParams GetCreateThinPDFParams();

/**
* const get element ThinPDFParams
*@return  JDFThinPDFParams The element
*/
	JDFThinPDFParams GetThinPDFParams()const;
/**
* Append element ThinPDFParams
 * 
*/
	JDFThinPDFParams AppendThinPDFParams();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPSToPDFConversionParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPSToPDFConversionParams_H_
