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

 
#if !defined _JDFAutoPrintConditionColor_H_
#define _JDFAutoPrintConditionColor_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFFileSpec;
class JDFDeviceNColor;
class JDFMedia;
class JDFTransferCurve;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPrintConditionColor : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPrintConditionColor class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPrintConditionColor should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPrintConditionColor : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPrintConditionColor():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPrintConditionColor(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPrintConditionColor &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPrintConditionColor(){};
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
* Enumeration for attribute MappingSelection
*/

	enum EnumMappingSelection{MappingSelection_Unknown,MappingSelection_UsePDLValues,MappingSelection_UseLocalPrinterValues,MappingSelection_UseProcessColorValues};
/**
* Enumeration for attribute MediaSide
*/

	enum EnumMediaSide{MediaSide_Unknown,MediaSide_Front,MediaSide_Back,MediaSide_Both};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute CMYK
*@param JDFCMYKColor value: the value to set the attribute to
*/
	virtual void SetCMYK(const JDFCMYKColor& value);
/**
* Get string attribute CMYK
* @return JDFCMYKColor the vaue of the attribute 
*/
	virtual JDFCMYKColor GetCMYK() const;
/**
* Typesafe attribute validation of CMYK
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCMYK(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ColorBook
*@param WString value: the value to set the attribute to
*/
	virtual void SetColorBook(const WString& value);
/**
* Get string attribute ColorBook
* @return WString the vaue of the attribute 
*/
	virtual WString GetColorBook() const;
/**
* Typesafe attribute validation of ColorBook
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidColorBook(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ColorBookEntry
*@param WString value: the value to set the attribute to
*/
	virtual void SetColorBookEntry(const WString& value);
/**
* Get string attribute ColorBookEntry
* @return WString the vaue of the attribute 
*/
	virtual WString GetColorBookEntry() const;
/**
* Typesafe attribute validation of ColorBookEntry
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidColorBookEntry(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ColorBookPrefix
*@param WString value: the value to set the attribute to
*/
	virtual void SetColorBookPrefix(const WString& value);
/**
* Get string attribute ColorBookPrefix
* @return WString the vaue of the attribute 
*/
	virtual WString GetColorBookPrefix() const;
/**
* Typesafe attribute validation of ColorBookPrefix
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidColorBookPrefix(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ColorBookSuffix
*@param WString value: the value to set the attribute to
*/
	virtual void SetColorBookSuffix(const WString& value);
/**
* Get string attribute ColorBookSuffix
* @return WString the vaue of the attribute 
*/
	virtual WString GetColorBookSuffix() const;
/**
* Typesafe attribute validation of ColorBookSuffix
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidColorBookSuffix(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Density
*@param double value: the value to set the attribute to
*/
	virtual void SetDensity(double value);
/**
* Get double attribute Density
* @return double the vaue of the attribute 
*/
	virtual double GetDensity() const;
/**
* Typesafe attribute validation of Density
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDensity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Lab
*@param JDFLabColor value: the value to set the attribute to
*/
	virtual void SetLab(const JDFLabColor& value);
/**
* Get string attribute Lab
* @return JDFLabColor the vaue of the attribute 
*/
	virtual JDFLabColor GetLab() const;
/**
* Typesafe attribute validation of Lab
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLab(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MappingSelection
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MappingSelectionString();
/**
* Enumeration string for enum value
* @param EnumMappingSelection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MappingSelectionString(EnumMappingSelection value);
/**
* Set attribute MappingSelection
* @param EnumMappingSelection value the value to set the attribute to
*/
	virtual void SetMappingSelection( EnumMappingSelection value);

/**
* Typesafe enumerated attribute MappingSelection
* @return EnumMappingSelectionthe enumeration value of the attribute
*/
	virtual EnumMappingSelection GetMappingSelection() const;

/**
* Typesafe attribute validation of MappingSelection
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMappingSelection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MediaSide
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MediaSideString();
/**
* Enumeration string for enum value
* @param EnumMediaSide value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MediaSideString(EnumMediaSide value);
/**
* Set attribute MediaSide
* @param EnumMediaSide value the value to set the attribute to
*/
	virtual void SetMediaSide( EnumMediaSide value);

/**
* Typesafe enumerated attribute MediaSide; defaults to Both
* @return EnumMediaSidethe enumeration value of the attribute
*/
	virtual EnumMediaSide GetMediaSide() const;

/**
* Typesafe attribute validation of MediaSide
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMediaSide(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NeutralDensity
*@param double value: the value to set the attribute to
*/
	virtual void SetNeutralDensity(double value);
/**
* Get double attribute NeutralDensity
* @return double the vaue of the attribute 
*/
	virtual double GetNeutralDensity() const;
/**
* Typesafe attribute validation of NeutralDensity
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNeutralDensity(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PrintConditionName
*@param WString value: the value to set the attribute to
*/
	virtual void SetPrintConditionName(const WString& value);
/**
* Get string attribute PrintConditionName
* @return WString the vaue of the attribute 
*/
	virtual WString GetPrintConditionName() const;
/**
* Typesafe attribute validation of PrintConditionName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPrintConditionName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute sRGB
*@param JDFRGBColor value: the value to set the attribute to
*/
	virtual void SetsRGB(const JDFRGBColor& value);
/**
* Get string attribute sRGB
* @return JDFRGBColor the vaue of the attribute 
*/
	virtual JDFRGBColor GetsRGB() const;
/**
* Typesafe attribute validation of sRGB
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidsRGB(EnumValidationLevel level=ValidationLevel_Complete) const;

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

/** Get Element DeviceNColor
* 
* @param int iSkip number of elements to skip
* @return JDFDeviceNColor The element
*/
	JDFDeviceNColor GetCreateDeviceNColor(int iSkip=0);

/**
* const get element DeviceNColor
* @param int iSkip number of elements to skip
* @return JDFDeviceNColor The element
*/
	JDFDeviceNColor GetDeviceNColor(int iSkip=0)const;
/**
* Append element DeviceNColor
 */
	JDFDeviceNColor AppendDeviceNColor();

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

/** Get Element TransferCurve
* 
* @param int iSkip number of elements to skip
* @return JDFTransferCurve The element
*/
	JDFTransferCurve GetCreateTransferCurve(int iSkip=0);

/**
* const get element TransferCurve
* @param int iSkip number of elements to skip
* @return JDFTransferCurve The element
*/
	JDFTransferCurve GetTransferCurve(int iSkip=0)const;
/**
* Append element TransferCurve
 */
	JDFTransferCurve AppendTransferCurve();
/**
* create inter-resource link to refTarget
* @param JDFTransferCurve& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefTransferCurve(JDFTransferCurve& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPrintConditionColor

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPrintConditionColor_H_
