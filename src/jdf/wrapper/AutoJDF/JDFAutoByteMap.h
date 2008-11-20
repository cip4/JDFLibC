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

 
#if !defined _JDFAutoByteMap_H_
#define _JDFAutoByteMap_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFBand;
class JDFColorPool;
class JDFFileSpec;
class JDFPixelColorant;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoByteMap : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoByteMap class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFByteMap should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoByteMap : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoByteMap():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoByteMap(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoByteMap &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoByteMap(){};
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
* Enumeration for attribute BandOrdering
*/

	enum EnumBandOrdering{BandOrdering_Unknown,BandOrdering_BandMajor,BandOrdering_ColorMajor};
/**
* Enumeration for attribute ElementType
*/

	enum EnumElementType{ElementType_Unknown,ElementType_Auxiliary,ElementType_Barcode,ElementType_Composed,ElementType_Document,ElementType_Graphic,ElementType_IdentificationField,ElementType_Image,ElementType_MultiDocument,ElementType_MultiSet,ElementType_Page,ElementType_Reservation,ElementType_Surface,ElementType_Text,ElementType_Tile};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for BandOrdering
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BandOrderingString();
/**
* Enumeration string for enum value
* @param EnumBandOrdering value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BandOrderingString(EnumBandOrdering value);
/**
* Set attribute BandOrdering
* @param EnumBandOrdering value the value to set the attribute to
*/
	virtual void SetBandOrdering( EnumBandOrdering value);

/**
* Typesafe enumerated attribute BandOrdering
* @return EnumBandOrderingthe enumeration value of the attribute
*/
	virtual EnumBandOrdering GetBandOrdering() const;

/**
* Typesafe attribute validation of BandOrdering
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBandOrdering(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ElementType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ElementTypeString();
/**
* Enumeration string for enum value
* @param EnumElementType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ElementTypeString(EnumElementType value);
/**
* Set attribute ElementType
* @param EnumElementType value the value to set the attribute to
*/
	virtual void SetElementType( EnumElementType value);

/**
* Typesafe enumerated attribute ElementType
* @return EnumElementTypethe enumeration value of the attribute
*/
	virtual EnumElementType GetElementType() const;

/**
* Typesafe attribute validation of ElementType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidElementType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FrameHeight
*@param int value: the value to set the attribute to
*/
	virtual void SetFrameHeight(int value);
/**
* Get integer attribute FrameHeight
* @return int the vaue of the attribute 
*/
	virtual int GetFrameHeight() const;
/**
* Typesafe attribute validation of FrameHeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrameHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FrameWidth
*@param int value: the value to set the attribute to
*/
	virtual void SetFrameWidth(int value);
/**
* Get integer attribute FrameWidth
* @return int the vaue of the attribute 
*/
	virtual int GetFrameWidth() const;
/**
* Typesafe attribute validation of FrameWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrameWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Halftoned
*@param bool value: the value to set the attribute to
*/
	virtual void SetHalftoned(bool value);
/**
* Get bool attribute Halftoned
* @return bool the vaue of the attribute 
*/
	virtual bool GetHalftoned() const;
/**
* Typesafe attribute validation of Halftoned
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHalftoned(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Interleaved
*@param bool value: the value to set the attribute to
*/
	virtual void SetInterleaved(bool value);
/**
* Get bool attribute Interleaved
* @return bool the vaue of the attribute 
*/
	virtual bool GetInterleaved() const;
/**
* Typesafe attribute validation of Interleaved
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInterleaved(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PixelSkip
*@param int value: the value to set the attribute to
*/
	virtual void SetPixelSkip(int value);
/**
* Get integer attribute PixelSkip
* @return int the vaue of the attribute 
*/
	virtual int GetPixelSkip() const;
/**
* Typesafe attribute validation of PixelSkip
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPixelSkip(EnumValidationLevel level=ValidationLevel_Complete) const;
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


/** Get Element Band
* 
* @param int iSkip number of elements to skip
* @return JDFBand The element
*/
	JDFBand GetCreateBand(int iSkip=0);

/**
* const get element Band
* @param int iSkip number of elements to skip
* @return JDFBand The element
*/
	JDFBand GetBand(int iSkip=0)const;
/**
* Append element Band
 */
	JDFBand AppendBand();

/** Get Element ColorPool
* 
* @return JDFColorPool The element
*/
	JDFColorPool GetCreateColorPool();

/**
* const get element ColorPool
*@return  JDFColorPool The element
*/
	JDFColorPool GetColorPool()const;
/**
* Append element ColorPool
 * 
*/
	JDFColorPool AppendColorPool();
/**
* create inter-resource link to refTarget
* @param JDFColorPool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorPool(JDFColorPool& refTarget);

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

/** Get Element PixelColorant
* 
* @param int iSkip number of elements to skip
* @return JDFPixelColorant The element
*/
	JDFPixelColorant GetCreatePixelColorant(int iSkip=0);

/**
* const get element PixelColorant
* @param int iSkip number of elements to skip
* @return JDFPixelColorant The element
*/
	JDFPixelColorant GetPixelColorant(int iSkip=0)const;
/**
* Append element PixelColorant
 */
	JDFPixelColorant AppendPixelColorant();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of required elements in the JDF namespace
*/
	virtual WString RequiredElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoByteMap

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoByteMap_H_
