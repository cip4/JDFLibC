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

 
#if !defined _JDFAutoProofingParams_H_
#define _JDFAutoProofingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFFileSpec;
class JDFMedia;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoProofingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoProofingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFProofingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoProofingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoProofingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoProofingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoProofingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoProofingParams(){};
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
* Enumeration for attribute ProofRenderingIntent
*/

	enum EnumProofRenderingIntent{ProofRenderingIntent_Unknown,ProofRenderingIntent_Saturation,ProofRenderingIntent_Perceptual,ProofRenderingIntent_RelativeColorimetric,ProofRenderingIntent_AbsoluteColorimetric};
/**
* Enumeration for attribute ProofType
*/

	enum EnumProofType{ProofType_Unknown,ProofType_None,ProofType_Page,ProofType_Imposition};
/**
* Enumeration for attribute ColorType
*/

	enum EnumColorType{ColorType_Unknown,ColorType_Monochrome,ColorType_BasicColor,ColorType_MatchedColor};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute DisplayTraps
*@param bool value: the value to set the attribute to
*/
	virtual void SetDisplayTraps(bool value);
/**
* Get bool attribute DisplayTraps
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetDisplayTraps() const;
/**
* Typesafe attribute validation of DisplayTraps
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDisplayTraps(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HalfTone
*@param bool value: the value to set the attribute to
*/
	virtual void SetHalfTone(bool value);
/**
* Get bool attribute HalfTone
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetHalfTone() const;
/**
* Typesafe attribute validation of HalfTone
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHalfTone(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ImageViewingStrategy
*@param WString value: the value to set the attribute to
*/
	virtual void SetImageViewingStrategy(const WString& value);
/**
* Get string attribute ImageViewingStrategy
* @return WString the vaue of the attribute ; defaults to NoImages
*/
	virtual WString GetImageViewingStrategy() const;
/**
* Typesafe attribute validation of ImageViewingStrategy
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageViewingStrategy(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Enumeration strings for ProofRenderingIntent
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ProofRenderingIntentString();
/**
* Enumeration string for enum value
* @param EnumProofRenderingIntent value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ProofRenderingIntentString(EnumProofRenderingIntent value);
/**
* Set attribute ProofRenderingIntent
* @param EnumProofRenderingIntent value the value to set the attribute to
*/
	virtual void SetProofRenderingIntent( EnumProofRenderingIntent value);

/**
* Typesafe enumerated attribute ProofRenderingIntent; defaults to Perceptual
* @return EnumProofRenderingIntentthe enumeration value of the attribute
*/
	virtual EnumProofRenderingIntent GetProofRenderingIntent() const;

/**
* Typesafe attribute validation of ProofRenderingIntent
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidProofRenderingIntent(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ProofType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ProofTypeString();
/**
* Enumeration string for enum value
* @param EnumProofType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ProofTypeString(EnumProofType value);
/**
* Set attribute ProofType
* @param EnumProofType value the value to set the attribute to
*/
	virtual void SetProofType( EnumProofType value);

/**
* Typesafe enumerated attribute ProofType; defaults to None
* @return EnumProofTypethe enumeration value of the attribute
*/
	virtual EnumProofType GetProofType() const;

/**
* Typesafe attribute validation of ProofType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidProofType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ColorType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ColorTypeString();
/**
* Enumeration string for enum value
* @param EnumColorType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ColorTypeString(EnumColorType value);
/**
* Set attribute ColorType
* @param EnumColorType value the value to set the attribute to
*/
	virtual void SetColorType( EnumColorType value);

/**
* Typesafe enumerated attribute ColorType
* @return EnumColorTypethe enumeration value of the attribute
*/
	virtual EnumColorType GetColorType() const;

/**
* Typesafe attribute validation of ColorType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidColorType(EnumValidationLevel level=ValidationLevel_Complete) const;
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

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element FileSpec
* 
* @return JDFFileSpec The element
*/
	JDFFileSpec GetCreateFileSpec();

/**
* const get element FileSpec
*@return  JDFFileSpec The element
*/
	JDFFileSpec GetFileSpec()const;
/**
* Append element FileSpec
 * 
*/
	JDFFileSpec AppendFileSpec();
/**
* create inter-resource link to refTarget
* @param JDFFileSpec& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefFileSpec(JDFFileSpec& refTarget);

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

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoProofingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoProofingParams_H_
