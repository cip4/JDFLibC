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

 
#if !defined _JDFAutoPDFXParams_H_
#define _JDFAutoPDFXParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPDFXParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPDFXParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPDFXParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPDFXParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPDFXParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPDFXParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPDFXParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPDFXParams(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

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
* Enumeration for attribute PDFXTrapped
*/

	enum EnumPDFXTrapped{PDFXTrapped_Unknown,PDFXTrapped_True,PDFXTrapped_False};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute PDFX1aCheck
*@param bool value: the value to set the attribute to
*/
	virtual void SetPDFX1aCheck(bool value);
/**
* Get bool attribute PDFX1aCheck
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPDFX1aCheck() const;
/**
* Typesafe attribute validation of PDFX1aCheck
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFX1aCheck(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFX3Check
*@param bool value: the value to set the attribute to
*/
	virtual void SetPDFX3Check(bool value);
/**
* Get bool attribute PDFX3Check
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPDFX3Check() const;
/**
* Typesafe attribute validation of PDFX3Check
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFX3Check(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXBleedBoxToTrimBoxOffset
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetPDFXBleedBoxToTrimBoxOffset(const JDFRectangle& value);
/**
* Get string attribute PDFXBleedBoxToTrimBoxOffset
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetPDFXBleedBoxToTrimBoxOffset() const;
/**
* Typesafe attribute validation of PDFXBleedBoxToTrimBoxOffset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXBleedBoxToTrimBoxOffset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXCompliantPDFOnly
*@param bool value: the value to set the attribute to
*/
	virtual void SetPDFXCompliantPDFOnly(bool value);
/**
* Get bool attribute PDFXCompliantPDFOnly
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPDFXCompliantPDFOnly() const;
/**
* Typesafe attribute validation of PDFXCompliantPDFOnly
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXCompliantPDFOnly(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXOutputCondition
*@param WString value: the value to set the attribute to
*/
	virtual void SetPDFXOutputCondition(const WString& value);
/**
* Get string attribute PDFXOutputCondition
* @return WString the vaue of the attribute 
*/
	virtual WString GetPDFXOutputCondition() const;
/**
* Typesafe attribute validation of PDFXOutputCondition
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXOutputCondition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXOutputIntentProfile
*@param WString value: the value to set the attribute to
*/
	virtual void SetPDFXOutputIntentProfile(const WString& value);
/**
* Get string attribute PDFXOutputIntentProfile
* @return WString the vaue of the attribute 
*/
	virtual WString GetPDFXOutputIntentProfile() const;
/**
* Typesafe attribute validation of PDFXOutputIntentProfile
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXOutputIntentProfile(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXNoTrimBoxError
*@param bool value: the value to set the attribute to
*/
	virtual void SetPDFXNoTrimBoxError(bool value);
/**
* Get bool attribute PDFXNoTrimBoxError
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetPDFXNoTrimBoxError() const;
/**
* Typesafe attribute validation of PDFXNoTrimBoxError
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXNoTrimBoxError(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXRegistryName
*@param WString value: the value to set the attribute to
*/
	virtual void SetPDFXRegistryName(const WString& value);
/**
* Get string attribute PDFXRegistryName
* @return WString the vaue of the attribute 
*/
	virtual WString GetPDFXRegistryName() const;
/**
* Typesafe attribute validation of PDFXRegistryName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXRegistryName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXSetBleedBoxToMediaBox
*@param bool value: the value to set the attribute to
*/
	virtual void SetPDFXSetBleedBoxToMediaBox(bool value);
/**
* Get bool attribute PDFXSetBleedBoxToMediaBox
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetPDFXSetBleedBoxToMediaBox() const;
/**
* Typesafe attribute validation of PDFXSetBleedBoxToMediaBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXSetBleedBoxToMediaBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PDFXTrapped
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PDFXTrappedString();
/**
* Enumeration string for enum value
* @param EnumPDFXTrapped value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PDFXTrappedString(EnumPDFXTrapped value);
/**
* Set attribute PDFXTrapped
* @param EnumPDFXTrapped value the value to set the attribute to
*/
	virtual void SetPDFXTrapped( EnumPDFXTrapped value);

/**
* Typesafe enumerated attribute PDFXTrapped
* @return EnumPDFXTrappedthe enumeration value of the attribute
*/
	virtual EnumPDFXTrapped GetPDFXTrapped() const;

/**
* Typesafe attribute validation of PDFXTrapped
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPDFXTrapped(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PDFXTrimBoxToMediaBoxOffset
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetPDFXTrimBoxToMediaBoxOffset(const JDFRectangle& value);
/**
* Get string attribute PDFXTrimBoxToMediaBoxOffset
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetPDFXTrimBoxToMediaBoxOffset() const;
/**
* Typesafe attribute validation of PDFXTrimBoxToMediaBoxOffset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPDFXTrimBoxToMediaBoxOffset(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoPDFXParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPDFXParams_H_
