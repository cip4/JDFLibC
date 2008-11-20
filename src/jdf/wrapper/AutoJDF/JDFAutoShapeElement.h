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

 
#if !defined _JDFAutoShapeElement_H_
#define _JDFAutoShapeElement_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFShapeElement;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoShapeElement : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoShapeElement class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFShapeElement should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoShapeElement : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoShapeElement():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoShapeElement(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoShapeElement &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoShapeElement(){};
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
* Enumeration for attribute CutType
*/

	enum EnumCutType{CutType_Unknown,CutType_Cut,CutType_Perforate};
/**
* Enumeration for attribute ShapeType
*/

	enum EnumShapeType{ShapeType_Unknown,ShapeType_Rectangular,ShapeType_Round,ShapeType_Path,ShapeType_RoundedRectangle};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute LockOrigins
*@param bool value: the value to set the attribute to
*/
	virtual void SetLockOrigins(bool value);
/**
* Get bool attribute LockOrigins
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetLockOrigins() const;
/**
* Typesafe attribute validation of LockOrigins
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLockOrigins(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CutBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetCutBox(const JDFRectangle& value);
/**
* Get string attribute CutBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetCutBox() const;
/**
* Typesafe attribute validation of CutBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCutBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CutOut
*@param bool value: the value to set the attribute to
*/
	virtual void SetCutOut(bool value);
/**
* Get bool attribute CutOut
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetCutOut() const;
/**
* Typesafe attribute validation of CutOut
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCutOut(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CutPath
*@param WString value: the value to set the attribute to
*/
	virtual void SetCutPath(const WString& value);
/**
* Get string attribute CutPath
* @return WString the vaue of the attribute 
*/
	virtual WString GetCutPath() const;
/**
* Typesafe attribute validation of CutPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCutPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for CutType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CutTypeString();
/**
* Enumeration string for enum value
* @param EnumCutType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CutTypeString(EnumCutType value);
/**
* Set attribute CutType
* @param EnumCutType value the value to set the attribute to
*/
	virtual void SetCutType( EnumCutType value);

/**
* Typesafe enumerated attribute CutType
* @return EnumCutTypethe enumeration value of the attribute
*/
	virtual EnumCutType GetCutType() const;

/**
* Typesafe attribute validation of CutType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCutType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DDESCutType
*@param int value: the value to set the attribute to
*/
	virtual void SetDDESCutType(int value);
/**
* Get integer attribute DDESCutType
* @return int the vaue of the attribute ; defaults to 101
*/
	virtual int GetDDESCutType() const;
/**
* Typesafe attribute validation of DDESCutType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDDESCutType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Material
*@param WString value: the value to set the attribute to
*/
	virtual void SetMaterial(const WString& value);
/**
* Get string attribute Material
* @return WString the vaue of the attribute 
*/
	virtual WString GetMaterial() const;
/**
* Typesafe attribute validation of Material
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ShapeDepth
*@param double value: the value to set the attribute to
*/
	virtual void SetShapeDepth(double value);
/**
* Get double attribute ShapeDepth
* @return double the vaue of the attribute 
*/
	virtual double GetShapeDepth() const;
/**
* Typesafe attribute validation of ShapeDepth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShapeDepth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ShapeType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ShapeTypeString();
/**
* Enumeration string for enum value
* @param EnumShapeType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ShapeTypeString(EnumShapeType value);
/**
* Set attribute ShapeType
* @param EnumShapeType value the value to set the attribute to
*/
	virtual void SetShapeType( EnumShapeType value);

/**
* Typesafe enumerated attribute ShapeType
* @return EnumShapeTypethe enumeration value of the attribute
*/
	virtual EnumShapeType GetShapeType() const;

/**
* Typesafe attribute validation of ShapeType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidShapeType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TeethPerDimension
*@param double value: the value to set the attribute to
*/
	virtual void SetTeethPerDimension(double value);
/**
* Get double attribute TeethPerDimension
* @return double the vaue of the attribute 
*/
	virtual double GetTeethPerDimension() const;
/**
* Typesafe attribute validation of TeethPerDimension
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTeethPerDimension(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Shape
* 
* @param int iSkip number of elements to skip
* @return JDFShapeElement The element
*/
	JDFShapeElement GetCreateShape(int iSkip=0);

/**
* const get element Shape
* @param int iSkip number of elements to skip
* @return JDFShapeElement The element
*/
	JDFShapeElement GetShape(int iSkip=0)const;
/**
* Append element Shape
 */
	JDFShapeElement AppendShape();
/**
* create inter-resource link to refTarget
* @param JDFShapeElement& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefShape(JDFShapeElement& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoShapeElement

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoShapeElement_H_
