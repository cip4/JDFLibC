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

 
#if !defined _JDFAutoExposedMedia_H_
#define _JDFAutoExposedMedia_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFFileSpec;
class JDFMedia;
class JDFPageList;
class JDFScreeningParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoExposedMedia : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoExposedMedia class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFExposedMedia should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoExposedMedia : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoExposedMedia():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoExposedMedia(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoExposedMedia &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoExposedMedia(){};
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
* Enumeration for attribute ColorType
*/

	enum EnumColorType{ColorType_Unknown,ColorType_Color,ColorType_GrayScale,ColorType_Monochrome};
/**
* Enumeration for attribute PlateType
*/

	enum EnumPlateType{PlateType_Unknown,PlateType_Exposed,PlateType_Dummy};
/**
* Enumeration for attribute ProofQuality
*/

	enum EnumProofQuality{ProofQuality_Unknown,ProofQuality_None,ProofQuality_Halftone,ProofQuality_Contone,ProofQuality_Conceptual};
/**
* Enumeration for attribute ProofType
*/

	enum EnumProofType{ProofType_Unknown,ProofType_None,ProofType_Imposition,ProofType_Page};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Polarity
*@param bool value: the value to set the attribute to
*/
	virtual void SetPolarity(bool value);
/**
* Get bool attribute Polarity
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetPolarity() const;
/**
* Typesafe attribute validation of Polarity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPolarity(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute PageListIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetPageListIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute PageListIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetPageListIndex() const;
/**
* Typesafe attribute validation of PageListIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageListIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PlateType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PlateTypeString();
/**
* Enumeration string for enum value
* @param EnumPlateType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PlateTypeString(EnumPlateType value);
/**
* Set attribute PlateType
* @param EnumPlateType value the value to set the attribute to
*/
	virtual void SetPlateType( EnumPlateType value);

/**
* Typesafe enumerated attribute PlateType
* @return EnumPlateTypethe enumeration value of the attribute
*/
	virtual EnumPlateType GetPlateType() const;

/**
* Typesafe attribute validation of PlateType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPlateType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProofName
*@param WString value: the value to set the attribute to
*/
	virtual void SetProofName(const WString& value);
/**
* Get string attribute ProofName
* @return WString the vaue of the attribute 
*/
	virtual WString GetProofName() const;
/**
* Typesafe attribute validation of ProofName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProofName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ProofQuality
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ProofQualityString();
/**
* Enumeration string for enum value
* @param EnumProofQuality value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ProofQualityString(EnumProofQuality value);
/**
* Set attribute ProofQuality
* @param EnumProofQuality value the value to set the attribute to
*/
	virtual void SetProofQuality( EnumProofQuality value);

/**
* Typesafe enumerated attribute ProofQuality
* @return EnumProofQualitythe enumeration value of the attribute
*/
	virtual EnumProofQuality GetProofQuality() const;

/**
* Typesafe attribute validation of ProofQuality
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidProofQuality(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Typesafe enumerated attribute ProofType
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

/** Get Element PageList
* 
* @param int iSkip number of elements to skip
* @return JDFPageList The element
*/
	JDFPageList GetCreatePageList(int iSkip=0);

/**
* const get element PageList
* @param int iSkip number of elements to skip
* @return JDFPageList The element
*/
	JDFPageList GetPageList(int iSkip=0)const;
/**
* Append element PageList
 */
	JDFPageList AppendPageList();
/**
* create inter-resource link to refTarget
* @param JDFPageList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefPageList(JDFPageList& refTarget);

/** Get Element ScreeningParams
* 
* @param int iSkip number of elements to skip
* @return JDFScreeningParams The element
*/
	JDFScreeningParams GetCreateScreeningParams(int iSkip=0);

/**
* const get element ScreeningParams
* @param int iSkip number of elements to skip
* @return JDFScreeningParams The element
*/
	JDFScreeningParams GetScreeningParams(int iSkip=0)const;
/**
* Append element ScreeningParams
 */
	JDFScreeningParams AppendScreeningParams();
/**
* create inter-resource link to refTarget
* @param JDFScreeningParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefScreeningParams(JDFScreeningParams& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoExposedMedia

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoExposedMedia_H_
