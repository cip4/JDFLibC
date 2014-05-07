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

 
#if !defined _JDFAutoIDPImageShift_H_
#define _JDFAutoIDPImageShift_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDPImageShift : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoIDPImageShift class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFIDPImageShift should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoIDPImageShift : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoIDPImageShift():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoIDPImageShift(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoIDPImageShift &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoIDPImageShift(){};
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
* Enumeration for attribute PositionX
*/

	enum EnumPositionX{PositionX_Unknown,PositionX_Center,PositionX_Left,PositionX_None,PositionX_Right};
/**
* Enumeration for attribute PositionY
*/

	enum EnumPositionY{PositionY_Unknown,PositionY_Bottom,PositionY_Center,PositionY_None,PositionY_Top};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for PositionX
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PositionXString();
/**
* Enumeration string for enum value
* @param EnumPositionX value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PositionXString(EnumPositionX value);
/**
* Set attribute PositionX
* @param EnumPositionX value the value to set the attribute to
*/
	virtual void SetPositionX( EnumPositionX value);

/**
* Typesafe enumerated attribute PositionX; defaults to None
* @return EnumPositionXthe enumeration value of the attribute
*/
	virtual EnumPositionX GetPositionX() const;

/**
* Typesafe attribute validation of PositionX
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPositionX(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PositionY
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PositionYString();
/**
* Enumeration string for enum value
* @param EnumPositionY value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PositionYString(EnumPositionY value);
/**
* Set attribute PositionY
* @param EnumPositionY value the value to set the attribute to
*/
	virtual void SetPositionY( EnumPositionY value);

/**
* Typesafe enumerated attribute PositionY; defaults to None
* @return EnumPositionYthe enumeration value of the attribute
*/
	virtual EnumPositionY GetPositionY() const;

/**
* Typesafe attribute validation of PositionY
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPositionY(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShiftX
*@param int value: the value to set the attribute to
*/
	virtual void SetShiftX(int value);
/**
* Get integer attribute ShiftX
* @return int the vaue of the attribute 
*/
	virtual int GetShiftX() const;
/**
* Typesafe attribute validation of ShiftX
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShiftX(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShiftY
*@param int value: the value to set the attribute to
*/
	virtual void SetShiftY(int value);
/**
* Get integer attribute ShiftY
* @return int the vaue of the attribute 
*/
	virtual int GetShiftY() const;
/**
* Typesafe attribute validation of ShiftY
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShiftY(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShiftXSide1
*@param int value: the value to set the attribute to
*/
	virtual void SetShiftXSide1(int value);
/**
* Get integer attribute ShiftXSide1
* @return int the vaue of the attribute 
*/
	virtual int GetShiftXSide1() const;
/**
* Typesafe attribute validation of ShiftXSide1
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShiftXSide1(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShiftXSide2
*@param int value: the value to set the attribute to
*/
	virtual void SetShiftXSide2(int value);
/**
* Get integer attribute ShiftXSide2
* @return int the vaue of the attribute 
*/
	virtual int GetShiftXSide2() const;
/**
* Typesafe attribute validation of ShiftXSide2
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShiftXSide2(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShiftYSide1
*@param int value: the value to set the attribute to
*/
	virtual void SetShiftYSide1(int value);
/**
* Get integer attribute ShiftYSide1
* @return int the vaue of the attribute 
*/
	virtual int GetShiftYSide1() const;
/**
* Typesafe attribute validation of ShiftYSide1
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShiftYSide1(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShiftYSide2
*@param int value: the value to set the attribute to
*/
	virtual void SetShiftYSide2(int value);
/**
* Get integer attribute ShiftYSide2
* @return int the vaue of the attribute 
*/
	virtual int GetShiftYSide2() const;
/**
* Typesafe attribute validation of ShiftYSide2
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShiftYSide2(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoIDPImageShift

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoIDPImageShift_H_
