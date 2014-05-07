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

 
#if !defined _JDFAutoStackingParams_H_
#define _JDFAutoStackingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFDisjointing;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoStackingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoStackingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFStackingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoStackingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoStackingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoStackingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoStackingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoStackingParams(){};
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
* Enumeration for attribute PreStackMethod
*/

	enum EnumPreStackMethod{PreStackMethod_Unknown,PreStackMethod_All,PreStackMethod_First,PreStackMethod_None};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BundleDepth
*@param int value: the value to set the attribute to
*/
	virtual void SetBundleDepth(int value);
/**
* Get integer attribute BundleDepth
* @return int the vaue of the attribute ; defaults to 0
*/
	virtual int GetBundleDepth() const;
/**
* Typesafe attribute validation of BundleDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBundleDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Compensate
*@param bool value: the value to set the attribute to
*/
	virtual void SetCompensate(bool value);
/**
* Get bool attribute Compensate
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetCompensate() const;
/**
* Typesafe attribute validation of Compensate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCompensate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LayerAmount
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetLayerAmount(const JDFIntegerList& value);
/**
* Get string attribute LayerAmount
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetLayerAmount() const;
/**
* Typesafe attribute validation of LayerAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayerAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LayerLift
*@param bool value: the value to set the attribute to
*/
	virtual void SetLayerLift(bool value);
/**
* Get bool attribute LayerLift
* @return bool the vaue of the attribute 
*/
	virtual bool GetLayerLift() const;
/**
* Typesafe attribute validation of LayerLift
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayerLift(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LayerCompression
*@param bool value: the value to set the attribute to
*/
	virtual void SetLayerCompression(bool value);
/**
* Get bool attribute LayerCompression
* @return bool the vaue of the attribute 
*/
	virtual bool GetLayerCompression() const;
/**
* Typesafe attribute validation of LayerCompression
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayerCompression(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxAmount(int value);
/**
* Get integer attribute MaxAmount
* @return int the vaue of the attribute 
*/
	virtual int GetMaxAmount() const;
/**
* Typesafe attribute validation of MaxAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxHeight
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxHeight(int value);
/**
* Get integer attribute MaxHeight
* @return int the vaue of the attribute 
*/
	virtual int GetMaxHeight() const;
/**
* Typesafe attribute validation of MaxHeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetMinAmount(int value);
/**
* Get integer attribute MinAmount
* @return int the vaue of the attribute 
*/
	virtual int GetMinAmount() const;
/**
* Typesafe attribute validation of MinAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxWeight
*@param double value: the value to set the attribute to
*/
	virtual void SetMaxWeight(double value);
/**
* Get double attribute MaxWeight
* @return double the vaue of the attribute 
*/
	virtual double GetMaxWeight() const;
/**
* Typesafe attribute validation of MaxWeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxWeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Offset
*@param bool value: the value to set the attribute to
*/
	virtual void SetOffset(bool value);
/**
* Get bool attribute Offset
* @return bool the vaue of the attribute 
*/
	virtual bool GetOffset() const;
/**
* Typesafe attribute validation of Offset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOffset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PreStackAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetPreStackAmount(int value);
/**
* Get integer attribute PreStackAmount
* @return int the vaue of the attribute 
*/
	virtual int GetPreStackAmount() const;
/**
* Typesafe attribute validation of PreStackAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPreStackAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PreStackMethod
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PreStackMethodString();
/**
* Enumeration string for enum value
* @param EnumPreStackMethod value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PreStackMethodString(EnumPreStackMethod value);
/**
* Set attribute PreStackMethod
* @param EnumPreStackMethod value the value to set the attribute to
*/
	virtual void SetPreStackMethod( EnumPreStackMethod value);

/**
* Typesafe enumerated attribute PreStackMethod
* @return EnumPreStackMethodthe enumeration value of the attribute
*/
	virtual EnumPreStackMethod GetPreStackMethod() const;

/**
* Typesafe attribute validation of PreStackMethod
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPreStackMethod(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StackCompression
*@param bool value: the value to set the attribute to
*/
	virtual void SetStackCompression(bool value);
/**
* Get bool attribute StackCompression
* @return bool the vaue of the attribute 
*/
	virtual bool GetStackCompression() const;
/**
* Typesafe attribute validation of StackCompression
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStackCompression(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute UnderLays
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetUnderLays(const JDFIntegerList& value);
/**
* Get string attribute UnderLays
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetUnderLays() const;
/**
* Typesafe attribute validation of UnderLays
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUnderLays(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StandardAmount
*@param int value: the value to set the attribute to
*/
	virtual void SetStandardAmount(int value);
/**
* Get integer attribute StandardAmount
* @return int the vaue of the attribute 
*/
	virtual int GetStandardAmount() const;
/**
* Typesafe attribute validation of StandardAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStandardAmount(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Disjointing
* 
* @return JDFDisjointing The element
*/
	JDFDisjointing GetCreateDisjointing();

/**
* const get element Disjointing
*@return  JDFDisjointing The element
*/
	JDFDisjointing GetDisjointing()const;
/**
* Append element Disjointing
 * 
*/
	JDFDisjointing AppendDisjointing();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoStackingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoStackingParams_H_
