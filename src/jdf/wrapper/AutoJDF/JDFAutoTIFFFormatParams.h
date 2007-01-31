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

 
#if !defined _JDFAutoTIFFFormatParams_H_
#define _JDFAutoTIFFFormatParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFTIFFtag;
class JDFTIFFEmbeddedFile;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoTIFFFormatParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoTIFFFormatParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFTIFFFormatParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoTIFFFormatParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoTIFFFormatParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoTIFFFormatParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoTIFFFormatParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoTIFFFormatParams(){};
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
* Enumeration for attribute ByteOrder
*/

	enum EnumByteOrder{ByteOrder_Unknown,ByteOrder_II,ByteOrder_MM};
/**
* Enumeration for attribute Segmentation
*/

	enum EnumSegmentation{Segmentation_Unknown,Segmentation_SingleStrip,Segmentation_Stripped,Segmentation_Tiled};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for ByteOrder
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ByteOrderString();
/**
* Enumeration string for enum value
* @param EnumByteOrder value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ByteOrderString(EnumByteOrder value);
/**
* Set attribute ByteOrder
* @param EnumByteOrder value the value to set the attribute to
*/
	virtual void SetByteOrder( EnumByteOrder value);

/**
* Typesafe enumerated attribute ByteOrder
* @return EnumByteOrderthe enumeration value of the attribute
*/
	virtual EnumByteOrder GetByteOrder() const;

/**
* Typesafe attribute validation of ByteOrder
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidByteOrder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Interleaving
*@param int value: the value to set the attribute to
*/
	virtual void SetInterleaving(int value);
/**
* Get integer attribute Interleaving
* @return int the vaue of the attribute ; defaults to 1
*/
	virtual int GetInterleaving() const;
/**
* Typesafe attribute validation of Interleaving
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidInterleaving(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WhiteIsZero
*@param bool value: the value to set the attribute to
*/
	virtual void SetWhiteIsZero(bool value);
/**
* Get bool attribute WhiteIsZero
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetWhiteIsZero() const;
/**
* Typesafe attribute validation of WhiteIsZero
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWhiteIsZero(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Segmentation
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SegmentationString();
/**
* Enumeration string for enum value
* @param EnumSegmentation value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SegmentationString(EnumSegmentation value);
/**
* Set attribute Segmentation
* @param EnumSegmentation value the value to set the attribute to
*/
	virtual void SetSegmentation( EnumSegmentation value);

/**
* Typesafe enumerated attribute Segmentation
* @return EnumSegmentationthe enumeration value of the attribute
*/
	virtual EnumSegmentation GetSegmentation() const;

/**
* Typesafe attribute validation of Segmentation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSegmentation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RowsPerStrip
*@param int value: the value to set the attribute to
*/
	virtual void SetRowsPerStrip(int value);
/**
* Get integer attribute RowsPerStrip
* @return int the vaue of the attribute 
*/
	virtual int GetRowsPerStrip() const;
/**
* Typesafe attribute validation of RowsPerStrip
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRowsPerStrip(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TileSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetTileSize(const JDFXYPair& value);
/**
* Get string attribute TileSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetTileSize() const;
/**
* Typesafe attribute validation of TileSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTileSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SeparationNameTag
*@param int value: the value to set the attribute to
*/
	virtual void SetSeparationNameTag(int value);
/**
* Get integer attribute SeparationNameTag
* @return int the vaue of the attribute ; defaults to 270
*/
	virtual int GetSeparationNameTag() const;
/**
* Typesafe attribute validation of SeparationNameTag
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSeparationNameTag(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element TIFFtag
* 
* @param int iSkip number of elements to skip
* @return JDFTIFFtag The element
*/
	JDFTIFFtag GetCreateTIFFtag(int iSkip=0);

/**
* const get element TIFFtag
* @param int iSkip number of elements to skip
* @return JDFTIFFtag The element
*/
	JDFTIFFtag GetTIFFtag(int iSkip=0)const;
/**
* Append element TIFFtag
 */
	JDFTIFFtag AppendTIFFtag();

/** Get Element TIFFEmbeddedFile
* 
* @param int iSkip number of elements to skip
* @return JDFTIFFEmbeddedFile The element
*/
	JDFTIFFEmbeddedFile GetCreateTIFFEmbeddedFile(int iSkip=0);

/**
* const get element TIFFEmbeddedFile
* @param int iSkip number of elements to skip
* @return JDFTIFFEmbeddedFile The element
*/
	JDFTIFFEmbeddedFile GetTIFFEmbeddedFile(int iSkip=0)const;
/**
* Append element TIFFEmbeddedFile
 */
	JDFTIFFEmbeddedFile AppendTIFFEmbeddedFile();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoTIFFFormatParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoTIFFFormatParams_H_
