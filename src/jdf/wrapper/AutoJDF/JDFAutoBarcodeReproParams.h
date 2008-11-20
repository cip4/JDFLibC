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

 
#if !defined _JDFAutoBarcodeReproParams_H_
#define _JDFAutoBarcodeReproParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFBarcodeCompParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoBarcodeReproParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoBarcodeReproParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFBarcodeReproParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoBarcodeReproParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoBarcodeReproParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoBarcodeReproParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoBarcodeReproParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoBarcodeReproParams(){};
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
* Enumeration for attribute BearerBars
*/

	enum EnumBearerBars{BearerBars_Unknown,BearerBars_None,BearerBars_TopBottom,BearerBars_Box,BearerBars_BoxHMarks};
/**
* Enumeration for attribute Masking
*/

	enum EnumMasking{Masking_Unknown,Masking_None,Masking_WhiteBox};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for BearerBars
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BearerBarsString();
/**
* Enumeration string for enum value
* @param EnumBearerBars value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BearerBarsString(EnumBearerBars value);
/**
* Set attribute BearerBars
* @param EnumBearerBars value the value to set the attribute to
*/
	virtual void SetBearerBars( EnumBearerBars value);

/**
* Typesafe enumerated attribute BearerBars
* @return EnumBearerBarsthe enumeration value of the attribute
*/
	virtual EnumBearerBars GetBearerBars() const;

/**
* Typesafe attribute validation of BearerBars
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBearerBars(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Height
*@param double value: the value to set the attribute to
*/
	virtual void SetHeight(double value);
/**
* Get double attribute Height
* @return double the vaue of the attribute 
*/
	virtual double GetHeight() const;
/**
* Typesafe attribute validation of Height
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Magnification
*@param double value: the value to set the attribute to
*/
	virtual void SetMagnification(double value);
/**
* Get double attribute Magnification
* @return double the vaue of the attribute 
*/
	virtual double GetMagnification() const;
/**
* Typesafe attribute validation of Magnification
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMagnification(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Masking
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MaskingString();
/**
* Enumeration string for enum value
* @param EnumMasking value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MaskingString(EnumMasking value);
/**
* Set attribute Masking
* @param EnumMasking value the value to set the attribute to
*/
	virtual void SetMasking( EnumMasking value);

/**
* Typesafe enumerated attribute Masking
* @return EnumMaskingthe enumeration value of the attribute
*/
	virtual EnumMasking GetMasking() const;

/**
* Typesafe attribute validation of Masking
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMasking(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleHeight
*@param double value: the value to set the attribute to
*/
	virtual void SetModuleHeight(double value);
/**
* Get double attribute ModuleHeight
* @return double the vaue of the attribute 
*/
	virtual double GetModuleHeight() const;
/**
* Typesafe attribute validation of ModuleHeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetModuleWidth(double value);
/**
* Get double attribute ModuleWidth
* @return double the vaue of the attribute 
*/
	virtual double GetModuleWidth() const;
/**
* Typesafe attribute validation of ModuleWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Ratio
*@param double value: the value to set the attribute to
*/
	virtual void SetRatio(double value);
/**
* Get double attribute Ratio
* @return double the vaue of the attribute 
*/
	virtual double GetRatio() const;
/**
* Typesafe attribute validation of Ratio
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRatio(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BarcodeCompParams
* 
* @param int iSkip number of elements to skip
* @return JDFBarcodeCompParams The element
*/
	JDFBarcodeCompParams GetCreateBarcodeCompParams(int iSkip=0);

/**
* const get element BarcodeCompParams
* @param int iSkip number of elements to skip
* @return JDFBarcodeCompParams The element
*/
	JDFBarcodeCompParams GetBarcodeCompParams(int iSkip=0)const;
/**
* Append element BarcodeCompParams
 */
	JDFBarcodeCompParams AppendBarcodeCompParams();
/**
* create inter-resource link to refTarget
* @param JDFBarcodeCompParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefBarcodeCompParams(JDFBarcodeCompParams& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoBarcodeReproParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoBarcodeReproParams_H_
