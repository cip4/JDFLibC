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

 
#if !defined _JDFAutoRenderingParams_H_
#define _JDFAutoRenderingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFAutomatedOverPrintParams;
class JDFObjectResolution;
class JDFMedia;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoRenderingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoRenderingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFRenderingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoRenderingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoRenderingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoRenderingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoRenderingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoRenderingParams(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BandHeight
*@param int value: the value to set the attribute to
*/
	virtual void SetBandHeight(int value);
/**
* Get integer attribute BandHeight
* @return int the vaue of the attribute 
*/
	virtual int GetBandHeight() const;
/**
* Typesafe attribute validation of BandHeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBandHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute BandWidth
*@param int value: the value to set the attribute to
*/
	virtual void SetBandWidth(int value);
/**
* Get integer attribute BandWidth
* @return int the vaue of the attribute 
*/
	virtual int GetBandWidth() const;
/**
* Typesafe attribute validation of BandWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBandWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ColorantDepth
*@param int value: the value to set the attribute to
*/
	virtual void SetColorantDepth(int value);
/**
* Get integer attribute ColorantDepth
* @return int the vaue of the attribute 
*/
	virtual int GetColorantDepth() const;
/**
* Typesafe attribute validation of ColorantDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidColorantDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
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

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element AutomatedOverPrintParams
* 
* @return JDFAutomatedOverPrintParams The element
*/
	JDFAutomatedOverPrintParams GetCreateAutomatedOverPrintParams();

/**
* const get element AutomatedOverPrintParams
*@return  JDFAutomatedOverPrintParams The element
*/
	JDFAutomatedOverPrintParams GetAutomatedOverPrintParams()const;
/**
* Append element AutomatedOverPrintParams
 * 
*/
	JDFAutomatedOverPrintParams AppendAutomatedOverPrintParams();
/**
* create inter-resource link to refTarget
* @param JDFAutomatedOverPrintParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefAutomatedOverPrintParams(JDFAutomatedOverPrintParams& refTarget);

/** Get Element ObjectResolution
* 
* @param int iSkip number of elements to skip
* @return JDFObjectResolution The element
*/
	JDFObjectResolution GetCreateObjectResolution(int iSkip=0);

/**
* const get element ObjectResolution
* @param int iSkip number of elements to skip
* @return JDFObjectResolution The element
*/
	JDFObjectResolution GetObjectResolution(int iSkip=0)const;
/**
* Append element ObjectResolution
 */
	JDFObjectResolution AppendObjectResolution();
/**
* create inter-resource link to refTarget
* @param JDFObjectResolution& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefObjectResolution(JDFObjectResolution& refTarget);

/** Get Element Media
* 
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia();

/**
* const get element Media
*@return  JDFMedia The element
*/
	JDFMedia GetMedia()const;
/**
* Append element Media
 * 
*/
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoRenderingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoRenderingParams_H_
