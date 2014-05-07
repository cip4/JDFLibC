/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoIdentificationField_H_
#define _JDFAutoIdentificationField_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFBarcodeDetails;
class JDFExtraValues;
class JDFMetadataMap;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoIdentificationField : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoIdentificationField class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFIdentificationField should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoIdentificationField : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoIdentificationField():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoIdentificationField(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoIdentificationField &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoIdentificationField(){};
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
* Enumeration for attribute Encoding
*/

	enum EnumEncoding{Encoding_Unknown,Encoding_ASCII,Encoding_Barcode,Encoding_BarCode1D,Encoding_BarCode2D,Encoding_Braille,Encoding_RFID};
/**
* Enumeration for attribute Position
*/

	enum EnumPosition{Position_Unknown,Position_Header,Position_Trailer,Position_Page,Position_Top,Position_Bottom,Position_Left,Position_Right,Position_Front,Position_Back,Position_Any};
/**
* Enumeration for attribute Purpose
*/

	enum EnumPurpose{Purpose_Unknown,Purpose_Verification,Purpose_Separation,Purpose_Label};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for Encoding
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& EncodingString();
/**
* Enumeration string for enum value
* @param EnumEncoding value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString EncodingString(EnumEncoding value);
/**
* Set attribute Encoding
* @param EnumEncoding value the value to set the attribute to
*/
	virtual void SetEncoding( EnumEncoding value);

/**
* Typesafe enumerated attribute Encoding
* @return EnumEncodingthe enumeration value of the attribute
*/
	virtual EnumEncoding GetEncoding() const;

/**
* Typesafe attribute validation of Encoding
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidEncoding(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EncodingDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetEncodingDetails(const WString& value);
/**
* Get string attribute EncodingDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetEncodingDetails() const;
/**
* Typesafe attribute validation of EncodingDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEncodingDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Format
*@param WString value: the value to set the attribute to
*/
	virtual void SetFormat(const WString& value);
/**
* Get string attribute Format
* @return WString the vaue of the attribute 
*/
	virtual WString GetFormat() const;
/**
* Typesafe attribute validation of Format
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Orientation
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetOrientation(const JDFMatrix& value);
/**
* Get string attribute Orientation
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetOrientation() const;
/**
* Typesafe attribute validation of Orientation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Page
*@param int value: the value to set the attribute to
*/
	virtual void SetPage(int value);
/**
* Get integer attribute Page
* @return int the vaue of the attribute 
*/
	virtual int GetPage() const;
/**
* Typesafe attribute validation of Page
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Position
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PositionString();
/**
* Enumeration string for enum value
* @param EnumPosition value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PositionString(EnumPosition value);
/**
* Set attribute Position
* @param EnumPosition value the value to set the attribute to
*/
	virtual void SetPosition( EnumPosition value);

/**
* Typesafe enumerated attribute Position
* @return EnumPositionthe enumeration value of the attribute
*/
	virtual EnumPosition GetPosition() const;

/**
* Typesafe attribute validation of Position
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPosition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Purpose
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PurposeString();
/**
* Enumeration string for enum value
* @param EnumPurpose value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PurposeString(EnumPurpose value);
/**
* Set attribute Purpose
* @param EnumPurpose value the value to set the attribute to
*/
	virtual void SetPurpose( EnumPurpose value);

/**
* Typesafe enumerated attribute Purpose
* @return EnumPurposethe enumeration value of the attribute
*/
	virtual EnumPurpose GetPurpose() const;

/**
* Typesafe attribute validation of Purpose
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPurpose(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PurposeDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetPurposeDetails(const WString& value);
/**
* Get string attribute PurposeDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetPurposeDetails() const;
/**
* Typesafe attribute validation of PurposeDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPurposeDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Value
*@param WString value: the value to set the attribute to
*/
	virtual void SetValue(const WString& value);
/**
* Get string attribute Value
* @return WString the vaue of the attribute 
*/
	virtual WString GetValue() const;
/**
* Typesafe attribute validation of Value
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidValue(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ValueFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetValueFormat(const WString& value);
/**
* Get string attribute ValueFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetValueFormat() const;
/**
* Typesafe attribute validation of ValueFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidValueFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ValueTemplate
*@param WString value: the value to set the attribute to
*/
	virtual void SetValueTemplate(const WString& value);
/**
* Get string attribute ValueTemplate
* @return WString the vaue of the attribute 
*/
	virtual WString GetValueTemplate() const;
/**
* Typesafe attribute validation of ValueTemplate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidValueTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BarcodeDetails
* 
* @return JDFBarcodeDetails The element
*/
	JDFBarcodeDetails GetCreateBarcodeDetails();

/**
* const get element BarcodeDetails
*@return  JDFBarcodeDetails The element
*/
	JDFBarcodeDetails GetBarcodeDetails()const;
/**
* Append element BarcodeDetails
 * 
*/
	JDFBarcodeDetails AppendBarcodeDetails();

/** Get Element ExtraValues
* 
* @return JDFExtraValues The element
*/
	JDFExtraValues GetCreateExtraValues();

/**
* const get element ExtraValues
*@return  JDFExtraValues The element
*/
	JDFExtraValues GetExtraValues()const;
/**
* Append element ExtraValues
 * 
*/
	JDFExtraValues AppendExtraValues();

/** Get Element MetadataMap
* 
* @param int iSkip number of elements to skip
* @return JDFMetadataMap The element
*/
	JDFMetadataMap GetCreateMetadataMap(int iSkip=0);

/**
* const get element MetadataMap
* @param int iSkip number of elements to skip
* @return JDFMetadataMap The element
*/
	JDFMetadataMap GetMetadataMap(int iSkip=0)const;
/**
* Append element MetadataMap
 */
	JDFMetadataMap AppendMetadataMap();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoIdentificationField

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoIdentificationField_H_
