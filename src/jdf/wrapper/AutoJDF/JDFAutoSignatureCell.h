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

 
#if !defined _JDFAutoSignatureCell_H_
#define _JDFAutoSignatureCell_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSignatureCell : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoSignatureCell class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFSignatureCell should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoSignatureCell : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoSignatureCell():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoSignatureCell(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoSignatureCell &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoSignatureCell(){};
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
* Enumeration for attribute BottleAxis
*/

	enum EnumBottleAxis{BottleAxis_Unknown,BottleAxis_SpineHead,BottleAxis_SpineFoot,BottleAxis_FaceHead,BottleAxis_FaceFoot};
/**
* Enumeration for attribute Orientation
*/

	enum EnumOrientation{Orientation_Unknown,Orientation_Up,Orientation_Down,Orientation_Left,Orientation_Right};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BackFacePages
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetBackFacePages(const JDFIntegerList& value);
/**
* Get string attribute BackFacePages
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetBackFacePages() const;
/**
* Typesafe attribute validation of BackFacePages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBackFacePages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BackPages
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetBackPages(const JDFIntegerList& value);
/**
* Get string attribute BackPages
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetBackPages() const;
/**
* Typesafe attribute validation of BackPages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBackPages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BottleAngle
*@param double value: the value to set the attribute to
*/
	virtual void SetBottleAngle(double value);
/**
* Get double attribute BottleAngle
* @return double the vaue of the attribute 
*/
	virtual double GetBottleAngle() const;
/**
* Typesafe attribute validation of BottleAngle
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBottleAngle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BottleAxis
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BottleAxisString();
/**
* Enumeration string for enum value
* @param EnumBottleAxis value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BottleAxisString(EnumBottleAxis value);
/**
* Set attribute BottleAxis
* @param EnumBottleAxis value the value to set the attribute to
*/
	virtual void SetBottleAxis( EnumBottleAxis value);

/**
* Typesafe enumerated attribute BottleAxis
* @return EnumBottleAxisthe enumeration value of the attribute
*/
	virtual EnumBottleAxis GetBottleAxis() const;

/**
* Typesafe attribute validation of BottleAxis
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBottleAxis(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FrontFacePages
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetFrontFacePages(const JDFIntegerList& value);
/**
* Get string attribute FrontFacePages
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetFrontFacePages() const;
/**
* Typesafe attribute validation of FrontFacePages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrontFacePages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FrontPages
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetFrontPages(const JDFIntegerList& value);
/**
* Get string attribute FrontPages
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetFrontPages() const;
/**
* Typesafe attribute validation of FrontPages
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFrontPages(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Orientation
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& OrientationString();
/**
* Enumeration string for enum value
* @param EnumOrientation value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString OrientationString(EnumOrientation value);
/**
* Set attribute Orientation
* @param EnumOrientation value the value to set the attribute to
*/
	virtual void SetOrientation( EnumOrientation value);

/**
* Typesafe enumerated attribute Orientation; defaults to Up
* @return EnumOrientationthe enumeration value of the attribute
*/
	virtual EnumOrientation GetOrientation() const;

/**
* Typesafe attribute validation of Orientation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SectionIndex
*@param int value: the value to set the attribute to
*/
	virtual void SetSectionIndex(int value);
/**
* Get integer attribute SectionIndex
* @return int the vaue of the attribute ; defaults to 0
*/
	virtual int GetSectionIndex() const;
/**
* Typesafe attribute validation of SectionIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSectionIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StationName
*@param WString value: the value to set the attribute to
*/
	virtual void SetStationName(const WString& value);
/**
* Get string attribute StationName
* @return WString the vaue of the attribute ; defaults to 0
*/
	virtual WString GetStationName() const;
/**
* Typesafe attribute validation of StationName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStationName(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoSignatureCell

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoSignatureCell_H_
