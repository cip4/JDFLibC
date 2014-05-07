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

 
#if !defined _JDFAutoScreenSelector_H_
#define _JDFAutoScreenSelector_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFQualityControlResult;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoScreenSelector : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoScreenSelector class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFScreenSelector should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoScreenSelector : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoScreenSelector():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoScreenSelector(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoScreenSelector &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoScreenSelector(){};
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
* Enumeration for attribute SourceObjects
*/

	enum EnumSourceObjects{SourceObjects_Unknown,SourceObjects_All,SourceObjects_ImagePhotographic,SourceObjects_ImageScreenShot,SourceObjects_LineArt,SourceObjects_SmoothShades,SourceObjects_Text};
/**
* Enumeration for attribute ScreeningType
*/

	enum EnumScreeningType{ScreeningType_Unknown,ScreeningType_AM,ScreeningType_FM,ScreeningType_Adaptive,ScreeningType_ErrorDiffusion,ScreeningType_HybridAM_FM,ScreeningType_HybridAMline_dot};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Separation
*@param WString value: the value to set the attribute to
*/
	virtual void SetSeparation(const WString& value);
/**
* Get string attribute Separation
* @return WString the vaue of the attribute ; defaults to All
*/
	virtual WString GetSeparation() const;
/**
* Typesafe attribute validation of Separation
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSeparation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SourceObjects
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SourceObjectsString();
/**
* Enumeration string for enum value
* @param EnumSourceObjects value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SourceObjectsString(EnumSourceObjects value);
/**
* Append value to the attribute SourceObjects
* @param EnumSourceObjects value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddSourceObjects( EnumSourceObjects value);
/**
* Remove value from the attribute SourceObjects
* @param EnumSourceObjects value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveSourceObjects( EnumSourceObjects value);
/**
* Typesafe enumerated attribute SourceObjects; defaults to All
* @return EnumSourceObjectsthe enumeration value of the attribute
*/
	virtual vint GetSourceObjects() const;
/**
* Set value of the attribute SourceObjects
* @param EnumSourceObjects value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetSourceObjects( EnumSourceObjects value);
/**
* Set value of the attribute SourceObjects to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetSourceObjects( const vint& value);
/**
* Typesafe attribute validation of SourceObjects
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSourceObjects(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Angle
*@param double value: the value to set the attribute to
*/
	virtual void SetAngle(double value);
/**
* Get double attribute Angle
* @return double the vaue of the attribute 
*/
	virtual double GetAngle() const;
/**
* Typesafe attribute validation of Angle
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAngle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AngleMap
*@param WString value: the value to set the attribute to
*/
	virtual void SetAngleMap(const WString& value);
/**
* Get string attribute AngleMap
* @return WString the vaue of the attribute 
*/
	virtual WString GetAngleMap() const;
/**
* Typesafe attribute validation of AngleMap
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAngleMap(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DotSize
*@param double value: the value to set the attribute to
*/
	virtual void SetDotSize(double value);
/**
* Get double attribute DotSize
* @return double the vaue of the attribute 
*/
	virtual double GetDotSize() const;
/**
* Typesafe attribute validation of DotSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDotSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Frequency
*@param double value: the value to set the attribute to
*/
	virtual void SetFrequency(double value);
/**
* Get double attribute Frequency
* @return double the vaue of the attribute 
*/
	virtual double GetFrequency() const;
/**
* Typesafe attribute validation of Frequency
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrequency(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ObjectTags
*@param vWString value: the value to set the attribute to
*/
	virtual void SetObjectTags(const vWString& value);
/**
* Get string attribute ObjectTags
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetObjectTags() const;
/**
* Typesafe attribute validation of ObjectTags
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidObjectTags(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ScreeningFamily
*@param WString value: the value to set the attribute to
*/
	virtual void SetScreeningFamily(const WString& value);
/**
* Get string attribute ScreeningFamily
* @return WString the vaue of the attribute 
*/
	virtual WString GetScreeningFamily() const;
/**
* Typesafe attribute validation of ScreeningFamily
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidScreeningFamily(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ScreeningType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ScreeningTypeString();
/**
* Enumeration string for enum value
* @param EnumScreeningType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ScreeningTypeString(EnumScreeningType value);
/**
* Set attribute ScreeningType
* @param EnumScreeningType value the value to set the attribute to
*/
	virtual void SetScreeningType( EnumScreeningType value);

/**
* Typesafe enumerated attribute ScreeningType
* @return EnumScreeningTypethe enumeration value of the attribute
*/
	virtual EnumScreeningType GetScreeningType() const;

/**
* Typesafe attribute validation of ScreeningType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidScreeningType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceFrequency
*@param NumberRange value: the value to set the attribute to
*/
	virtual void SetSourceFrequency(const NumberRange& value);
/**
* Get range attribute SourceFrequency
* @return NumberRange the vaue of the attribute 
*/
	virtual NumberRange GetSourceFrequency() const;
/**
* Typesafe attribute validation of SourceFrequency
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceFrequency(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SpotFunction
*@param WString value: the value to set the attribute to
*/
	virtual void SetSpotFunction(const WString& value);
/**
* Get string attribute SpotFunction
* @return WString the vaue of the attribute 
*/
	virtual WString GetSpotFunction() const;
/**
* Typesafe attribute validation of SpotFunction
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSpotFunction(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element QualityControlResult
* 
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetCreateQualityControlResult(int iSkip=0);

/**
* const get element QualityControlResult
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetQualityControlResult(int iSkip=0)const;
/**
* Append element QualityControlResult
 */
	JDFQualityControlResult AppendQualityControlResult();
/**
* create inter-resource link to refTarget
* @param JDFQualityControlResult& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefQualityControlResult(JDFQualityControlResult& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoScreenSelector

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoScreenSelector_H_
