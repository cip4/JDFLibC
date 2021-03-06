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

 
#if !defined _JDFAutoLayoutElementPart_H_
#define _JDFAutoLayoutElementPart_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFBarcodeProductionParams;
class JDFColorCorrectionParams;
class JDFImageCompressionParams;
class JDFImageEnhancementParams;
class JDFLayoutElement;
class JDFPositionObj;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoLayoutElementPart : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoLayoutElementPart class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFLayoutElementPart should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoLayoutElementPart : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoLayoutElementPart():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoLayoutElementPart(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoLayoutElementPart &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoLayoutElementPart(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	virtual void SetID(const WString& value);
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	virtual WString GetID() const;
/**
* Typesafe attribute validation of ID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidID(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BarcodeProductionParams
* 
* @param int iSkip number of elements to skip
* @return JDFBarcodeProductionParams The element
*/
	JDFBarcodeProductionParams GetCreateBarcodeProductionParams(int iSkip=0);

/**
* const get element BarcodeProductionParams
* @param int iSkip number of elements to skip
* @return JDFBarcodeProductionParams The element
*/
	JDFBarcodeProductionParams GetBarcodeProductionParams(int iSkip=0)const;
/**
* Append element BarcodeProductionParams
 */
	JDFBarcodeProductionParams AppendBarcodeProductionParams();

/** Get Element ColorCorrectionParams
* 
* @param int iSkip number of elements to skip
* @return JDFColorCorrectionParams The element
*/
	JDFColorCorrectionParams GetCreateColorCorrectionParams(int iSkip=0);

/**
* const get element ColorCorrectionParams
* @param int iSkip number of elements to skip
* @return JDFColorCorrectionParams The element
*/
	JDFColorCorrectionParams GetColorCorrectionParams(int iSkip=0)const;
/**
* Append element ColorCorrectionParams
 */
	JDFColorCorrectionParams AppendColorCorrectionParams();
/**
* create inter-resource link to refTarget
* @param JDFColorCorrectionParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorCorrectionParams(JDFColorCorrectionParams& refTarget);

/** Get Element ImageCompressionParams
* 
* @param int iSkip number of elements to skip
* @return JDFImageCompressionParams The element
*/
	JDFImageCompressionParams GetCreateImageCompressionParams(int iSkip=0);

/**
* const get element ImageCompressionParams
* @param int iSkip number of elements to skip
* @return JDFImageCompressionParams The element
*/
	JDFImageCompressionParams GetImageCompressionParams(int iSkip=0)const;
/**
* Append element ImageCompressionParams
 */
	JDFImageCompressionParams AppendImageCompressionParams();
/**
* create inter-resource link to refTarget
* @param JDFImageCompressionParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefImageCompressionParams(JDFImageCompressionParams& refTarget);

/** Get Element ImageEnhancementParams
* 
* @param int iSkip number of elements to skip
* @return JDFImageEnhancementParams The element
*/
	JDFImageEnhancementParams GetCreateImageEnhancementParams(int iSkip=0);

/**
* const get element ImageEnhancementParams
* @param int iSkip number of elements to skip
* @return JDFImageEnhancementParams The element
*/
	JDFImageEnhancementParams GetImageEnhancementParams(int iSkip=0)const;
/**
* Append element ImageEnhancementParams
 */
	JDFImageEnhancementParams AppendImageEnhancementParams();
/**
* create inter-resource link to refTarget
* @param JDFImageEnhancementParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefImageEnhancementParams(JDFImageEnhancementParams& refTarget);

/** Get Element LayoutElement
* 
* @param int iSkip number of elements to skip
* @return JDFLayoutElement The element
*/
	JDFLayoutElement GetCreateLayoutElement(int iSkip=0);

/**
* const get element LayoutElement
* @param int iSkip number of elements to skip
* @return JDFLayoutElement The element
*/
	JDFLayoutElement GetLayoutElement(int iSkip=0)const;
/**
* Append element LayoutElement
 */
	JDFLayoutElement AppendLayoutElement();
/**
* create inter-resource link to refTarget
* @param JDFLayoutElement& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefLayoutElement(JDFLayoutElement& refTarget);

/** Get Element PositionObj
* 
* @param int iSkip number of elements to skip
* @return JDFPositionObj The element
*/
	JDFPositionObj GetCreatePositionObj(int iSkip=0);

/**
* const get element PositionObj
* @param int iSkip number of elements to skip
* @return JDFPositionObj The element
*/
	JDFPositionObj GetPositionObj(int iSkip=0)const;
/**
* Append element PositionObj
 */
	JDFPositionObj AppendPositionObj();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoLayoutElementPart

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoLayoutElementPart_H_
