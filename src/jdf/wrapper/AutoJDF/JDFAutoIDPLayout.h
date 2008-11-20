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

 
#if !defined _JDFAutoIDPLayout_H_
#define _JDFAutoIDPLayout_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFIDPImageShift;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoIDPLayout : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoIDPLayout class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFIDPLayout should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoIDPLayout : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoIDPLayout():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoIDPLayout(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoIDPLayout &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoIDPLayout(){};
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
* Enumeration for attribute FinishedPageOrientation
*/

	enum EnumFinishedPageOrientation{FinishedPageOrientation_Unknown,FinishedPageOrientation_Portrait,FinishedPageOrientation_Landscape};
/**
* Enumeration for attribute Sides
*/

	enum EnumSides{Sides_Unknown,Sides_OneSided,Sides_TwoSidedLongEdge,Sides_TwoSidedShortEdge};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Border
*@param double value: the value to set the attribute to
*/
	virtual void SetBorder(double value);
/**
* Get double attribute Border
* @return double the vaue of the attribute ; defaults to 0
*/
	virtual double GetBorder() const;
/**
* Typesafe attribute validation of Border
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBorder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for FinishedPageOrientation
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FinishedPageOrientationString();
/**
* Enumeration string for enum value
* @param EnumFinishedPageOrientation value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FinishedPageOrientationString(EnumFinishedPageOrientation value);
/**
* Set attribute FinishedPageOrientation
* @param EnumFinishedPageOrientation value the value to set the attribute to
*/
	virtual void SetFinishedPageOrientation( EnumFinishedPageOrientation value);

/**
* Typesafe enumerated attribute FinishedPageOrientation; defaults to Portrait
* @return EnumFinishedPageOrientationthe enumeration value of the attribute
*/
	virtual EnumFinishedPageOrientation GetFinishedPageOrientation() const;

/**
* Typesafe attribute validation of FinishedPageOrientation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFinishedPageOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ForceFrontSide
*@param NumberRangeList value: the value to set the attribute to
*/
	virtual void SetForceFrontSide(const NumberRangeList& value);
/**
* Get range attribute ForceFrontSide
* @return NumberRangeList the vaue of the attribute 
*/
	virtual NumberRangeList GetForceFrontSide() const;
/**
* Typesafe attribute validation of ForceFrontSide
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidForceFrontSide(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NumberUp
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetNumberUp(const JDFXYPair& value);
/**
* Get string attribute NumberUp
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetNumberUp() const;
/**
* Typesafe attribute validation of NumberUp
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNumberUp(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PresentationDirection
*@param WString value: the value to set the attribute to
*/
	virtual void SetPresentationDirection(const WString& value);
/**
* Get string attribute PresentationDirection
* @return WString the vaue of the attribute 
*/
	virtual WString GetPresentationDirection() const;
/**
* Typesafe attribute validation of PresentationDirection
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPresentationDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Rotate
*@param double value: the value to set the attribute to
*/
	virtual void SetRotate(double value);
/**
* Get double attribute Rotate
* @return double the vaue of the attribute ; defaults to 0
*/
	virtual double GetRotate() const;
/**
* Typesafe attribute validation of Rotate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRotate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Sides
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SidesString();
/**
* Enumeration string for enum value
* @param EnumSides value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SidesString(EnumSides value);
/**
* Set attribute Sides
* @param EnumSides value the value to set the attribute to
*/
	virtual void SetSides( EnumSides value);

/**
* Typesafe enumerated attribute Sides; defaults to OneSided
* @return EnumSidesthe enumeration value of the attribute
*/
	virtual EnumSides GetSides() const;

/**
* Typesafe attribute validation of Sides
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSides(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ImageShift
* 
* @param int iSkip number of elements to skip
* @return JDFIDPImageShift The element
*/
	JDFIDPImageShift GetCreateImageShift(int iSkip=0);

/**
* const get element ImageShift
* @param int iSkip number of elements to skip
* @return JDFIDPImageShift The element
*/
	JDFIDPImageShift GetImageShift(int iSkip=0)const;
/**
* Append element ImageShift
 */
	JDFIDPImageShift AppendImageShift();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoIDPLayout

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoIDPLayout_H_
