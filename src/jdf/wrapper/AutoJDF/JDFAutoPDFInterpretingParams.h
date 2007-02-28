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

 
#if !defined _JDFAutoPDFInterpretingParams_H_
#define _JDFAutoPDFInterpretingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFOCGControl;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPDFInterpretingParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPDFInterpretingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPDFInterpretingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPDFInterpretingParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPDFInterpretingParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPDFInterpretingParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPDFInterpretingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPDFInterpretingParams(){};
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
* Enumeration for attribute OCGDefault
*/

	enum EnumOCGDefault{OCGDefault_Unknown,OCGDefault_Exclude,OCGDefault_FromPDF,OCGDefault_Include};
/**
* Enumeration for attribute OCGProcess
*/

	enum EnumOCGProcess{OCGProcess_Unknown,OCGProcess_Export,OCGProcess_Print,OCGProcess_View};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute EmitPDFBG
*@param bool value: the value to set the attribute to
*/
	virtual void SetEmitPDFBG(bool value);
/**
* Get bool attribute EmitPDFBG
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetEmitPDFBG() const;
/**
* Typesafe attribute validation of EmitPDFBG
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEmitPDFBG(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EmitPDFHalftones
*@param bool value: the value to set the attribute to
*/
	virtual void SetEmitPDFHalftones(bool value);
/**
* Get bool attribute EmitPDFHalftones
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetEmitPDFHalftones() const;
/**
* Typesafe attribute validation of EmitPDFHalftones
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEmitPDFHalftones(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EmitPDFTransfers
*@param bool value: the value to set the attribute to
*/
	virtual void SetEmitPDFTransfers(bool value);
/**
* Get bool attribute EmitPDFTransfers
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetEmitPDFTransfers() const;
/**
* Typesafe attribute validation of EmitPDFTransfers
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEmitPDFTransfers(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EmitPDFUCR
*@param bool value: the value to set the attribute to
*/
	virtual void SetEmitPDFUCR(bool value);
/**
* Get bool attribute EmitPDFUCR
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetEmitPDFUCR() const;
/**
* Typesafe attribute validation of EmitPDFUCR
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEmitPDFUCR(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HonorPDFOverprint
*@param bool value: the value to set the attribute to
*/
	virtual void SetHonorPDFOverprint(bool value);
/**
* Get bool attribute HonorPDFOverprint
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetHonorPDFOverprint() const;
/**
* Typesafe attribute validation of HonorPDFOverprint
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHonorPDFOverprint(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ICCColorAsDeviceColor
*@param bool value: the value to set the attribute to
*/
	virtual void SetICCColorAsDeviceColor(bool value);
/**
* Get bool attribute ICCColorAsDeviceColor
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetICCColorAsDeviceColor() const;
/**
* Typesafe attribute validation of ICCColorAsDeviceColor
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidICCColorAsDeviceColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for OCGDefault
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OCGDefaultString();
/**
* Enumeration string for enum value
* @param EnumOCGDefault value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OCGDefaultString(EnumOCGDefault value);
/**
* Set attribute OCGDefault
* @param EnumOCGDefault value the value to set the attribute to
*/
	virtual void SetOCGDefault( EnumOCGDefault value);

/**
* Typesafe enumerated attribute OCGDefault; defaults to FromPDF
* @return EnumOCGDefaultthe enumeration value of the attribute
*/
	virtual EnumOCGDefault GetOCGDefault() const;

/**
* Typesafe attribute validation of OCGDefault
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOCGDefault(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OCGIntent
*@param WString value: the value to set the attribute to
*/
	virtual void SetOCGIntent(const WString& value);
/**
* Get string attribute OCGIntent
* @return WString the vaue of the attribute 
*/
	virtual WString GetOCGIntent() const;
/**
* Typesafe attribute validation of OCGIntent
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOCGIntent(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for OCGProcess
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OCGProcessString();
/**
* Enumeration string for enum value
* @param EnumOCGProcess value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OCGProcessString(EnumOCGProcess value);
/**
* Set attribute OCGProcess
* @param EnumOCGProcess value the value to set the attribute to
*/
	virtual void SetOCGProcess( EnumOCGProcess value);

/**
* Typesafe enumerated attribute OCGProcess
* @return EnumOCGProcessthe enumeration value of the attribute
*/
	virtual EnumOCGProcess GetOCGProcess() const;

/**
* Typesafe attribute validation of OCGProcess
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOCGProcess(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OCGZoom
*@param double value: the value to set the attribute to
*/
	virtual void SetOCGZoom(double value);
/**
* Get double attribute OCGZoom
* @return double the vaue of the attribute ; defaults to 1.0
*/
	virtual double GetOCGZoom() const;
/**
* Typesafe attribute validation of OCGZoom
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOCGZoom(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PrintPDFAnnotations
*@param bool value: the value to set the attribute to
*/
	virtual void SetPrintPDFAnnotations(bool value);
/**
* Get bool attribute PrintPDFAnnotations
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPrintPDFAnnotations() const;
/**
* Typesafe attribute validation of PrintPDFAnnotations
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPrintPDFAnnotations(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PrintTrapAnnotations
*@param bool value: the value to set the attribute to
*/
	virtual void SetPrintTrapAnnotations(bool value);
/**
* Get bool attribute PrintTrapAnnotations
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetPrintTrapAnnotations() const;
/**
* Typesafe attribute validation of PrintTrapAnnotations
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPrintTrapAnnotations(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TransparencyRenderingQuality
*@param double value: the value to set the attribute to
*/
	virtual void SetTransparencyRenderingQuality(double value);
/**
* Get double attribute TransparencyRenderingQuality
* @return double the vaue of the attribute 
*/
	virtual double GetTransparencyRenderingQuality() const;
/**
* Typesafe attribute validation of TransparencyRenderingQuality
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTransparencyRenderingQuality(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element OCGControl
* 
* @param int iSkip number of elements to skip
* @return JDFOCGControl The element
*/
	JDFOCGControl GetCreateOCGControl(int iSkip=0);

/**
* const get element OCGControl
* @param int iSkip number of elements to skip
* @return JDFOCGControl The element
*/
	JDFOCGControl GetOCGControl(int iSkip=0)const;
/**
* Append element OCGControl
 */
	JDFOCGControl AppendOCGControl();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPDFInterpretingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPDFInterpretingParams_H_
