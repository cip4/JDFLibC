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

 
#if !defined _JDFAutoDCTParams_H_
#define _JDFAutoDCTParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDCTParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDCTParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDCTParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDCTParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDCTParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoDCTParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDCTParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDCTParams(){};
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
* Enumeration for attribute SourceCSs
*/

	enum EnumSourceCSs{SourceCSs_Unknown,SourceCSs_CalGray,SourceCSs_CalRGB,SourceCSs_Calibrated,SourceCSs_CIEBased,SourceCSs_CMYK,SourceCSs_DeviceN,SourceCSs_DevIndep,SourceCSs_RGB,SourceCSs_Gray,SourceCSs_ICCBased,SourceCSs_ICCCMYK,SourceCSs_ICCGray,SourceCSs_ICCLAB,SourceCSs_ICCRGB,SourceCSs_Lab,SourceCSs_Separation,SourceCSs_YUV,SourceCSs_All};
/**
* Enumeration for attribute ColorTransform
*/

	enum EnumColorTransform{ColorTransform_Unknown,ColorTransform_YUV,ColorTransform_None,ColorTransform_Automatic};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for SourceCSs
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SourceCSsString();
/**
* Enumeration string for enum value
* @param EnumSourceCSs value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SourceCSsString(EnumSourceCSs value);
/**
* Append value to the attribute SourceCSs
* @param EnumSourceCSs value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddSourceCSs( EnumSourceCSs value);
/**
* Remove value from the attribute SourceCSs
* @param EnumSourceCSs value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveSourceCSs( EnumSourceCSs value);
/**
* Typesafe enumerated attribute SourceCSs
* @return EnumSourceCSsthe enumeration value of the attribute
*/
	virtual vint GetSourceCSs() const;
/**
* Set value of the attribute SourceCSs
* @param EnumSourceCSs value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetSourceCSs( EnumSourceCSs value);
/**
* Set value of the attribute SourceCSs to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetSourceCSs( const vint& value);
/**
* Typesafe attribute validation of SourceCSs
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSourceCSs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HSamples
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetHSamples(const JDFIntegerList& value);
/**
* Get string attribute HSamples
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetHSamples() const;
/**
* Typesafe attribute validation of HSamples
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHSamples(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute VSamples
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetVSamples(const JDFIntegerList& value);
/**
* Get string attribute VSamples
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetVSamples() const;
/**
* Typesafe attribute validation of VSamples
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidVSamples(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute QFactor
*@param double value: the value to set the attribute to
*/
	virtual void SetQFactor(double value);
/**
* Get double attribute QFactor
* @return double the vaue of the attribute ; defaults to 1.0
*/
	virtual double GetQFactor() const;
/**
* Typesafe attribute validation of QFactor
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidQFactor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute QuantTable
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetQuantTable(const JDFNumberList& value);
/**
* Get string attribute QuantTable
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetQuantTable() const;
/**
* Typesafe attribute validation of QuantTable
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidQuantTable(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HuffTable
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetHuffTable(const JDFNumberList& value);
/**
* Get string attribute HuffTable
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetHuffTable() const;
/**
* Typesafe attribute validation of HuffTable
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHuffTable(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ColorTransform
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ColorTransformString();
/**
* Enumeration string for enum value
* @param EnumColorTransform value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ColorTransformString(EnumColorTransform value);
/**
* Set attribute ColorTransform
* @param EnumColorTransform value the value to set the attribute to
*/
	virtual void SetColorTransform( EnumColorTransform value);

/**
* Typesafe enumerated attribute ColorTransform; defaults to Automatic
* @return EnumColorTransformthe enumeration value of the attribute
*/
	virtual EnumColorTransform GetColorTransform() const;

/**
* Typesafe attribute validation of ColorTransform
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidColorTransform(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoDCTParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDCTParams_H_
