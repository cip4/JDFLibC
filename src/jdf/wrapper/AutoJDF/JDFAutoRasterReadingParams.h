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

 
#if !defined _JDFAutoRasterReadingParams_H_
#define _JDFAutoRasterReadingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFFitPolicy;
class JDFMedia;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoRasterReadingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoRasterReadingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFRasterReadingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoRasterReadingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoRasterReadingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoRasterReadingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoRasterReadingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoRasterReadingParams(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Center
*@param bool value: the value to set the attribute to
*/
	virtual void SetCenter(bool value);
/**
* Get bool attribute Center
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetCenter() const;
/**
* Typesafe attribute validation of Center
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCenter(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Poster
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetPoster(const JDFXYPair& value);
/**
* Get string attribute Poster
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetPoster() const;
/**
* Typesafe attribute validation of Poster
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPoster(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PosterOverlap
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetPosterOverlap(const JDFXYPair& value);
/**
* Get string attribute PosterOverlap
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetPosterOverlap() const;
/**
* Typesafe attribute validation of PosterOverlap
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPosterOverlap(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Scaling
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetScaling(const JDFXYPair& value);
/**
* Get string attribute Scaling
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetScaling() const;
/**
* Typesafe attribute validation of Scaling
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidScaling(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ScalingOrigin
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetScalingOrigin(const JDFXYPair& value);
/**
* Get string attribute ScalingOrigin
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetScalingOrigin() const;
/**
* Typesafe attribute validation of ScalingOrigin
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidScalingOrigin(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


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

/** Get Element Media
* 
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia(int iSkip=0);

/**
* const get element Media
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetMedia(int iSkip=0)const;
/**
* Append element Media
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
}; // endJDFAutoRasterReadingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoRasterReadingParams_H_
