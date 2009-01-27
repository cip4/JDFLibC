/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoEmboss_H_
#define _JDFAutoEmboss_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFIdentificationField;
class JDFMedia;
class JDFMedia;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoEmboss : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoEmboss class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFEmboss should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoEmboss : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoEmboss():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoEmboss(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoEmboss &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoEmboss(){};
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
* Enumeration for attribute Direction
*/

	enum EnumDirection{Direction_Unknown,Direction_Both,Direction_Flat,Direction_Raised,Direction_Depressed};
/**
* Enumeration for attribute EdgeShape
*/

	enum EnumEdgeShape{EdgeShape_Unknown,EdgeShape_Beveled,EdgeShape_Rounded};
/**
* Enumeration for attribute EmbossingType
*/

	enum EnumEmbossingType{EmbossingType_Unknown,EmbossingType_BlindEmbossing,EmbossingType_Braille,EmbossingType_EmbossedFinish,EmbossingType_FoilEmbossing,EmbossingType_FoilStamping,EmbossingType_RegisteredEmbossing};
/**
* Enumeration for attribute Level
*/

	enum EnumLevel{Level_Unknown,Level_SingleLevel,Level_MultiLevel,Level_Sculpted};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for Direction
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DirectionString();
/**
* Enumeration string for enum value
* @param EnumDirection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DirectionString(EnumDirection value);
/**
* Set attribute Direction
* @param EnumDirection value the value to set the attribute to
*/
	virtual void SetDirection( EnumDirection value);

/**
* Typesafe enumerated attribute Direction
* @return EnumDirectionthe enumeration value of the attribute
*/
	virtual EnumDirection GetDirection() const;

/**
* Typesafe attribute validation of Direction
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EdgeAngle
*@param double value: the value to set the attribute to
*/
	virtual void SetEdgeAngle(double value);
/**
* Get double attribute EdgeAngle
* @return double the vaue of the attribute 
*/
	virtual double GetEdgeAngle() const;
/**
* Typesafe attribute validation of EdgeAngle
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEdgeAngle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for EdgeShape
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& EdgeShapeString();
/**
* Enumeration string for enum value
* @param EnumEdgeShape value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString EdgeShapeString(EnumEdgeShape value);
/**
* Set attribute EdgeShape
* @param EnumEdgeShape value the value to set the attribute to
*/
	virtual void SetEdgeShape( EnumEdgeShape value);

/**
* Typesafe enumerated attribute EdgeShape; defaults to Rounded
* @return EnumEdgeShapethe enumeration value of the attribute
*/
	virtual EnumEdgeShape GetEdgeShape() const;

/**
* Typesafe attribute validation of EdgeShape
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidEdgeShape(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for EmbossingType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& EmbossingTypeString();
/**
* Enumeration string for enum value
* @param EnumEmbossingType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString EmbossingTypeString(EnumEmbossingType value);
/**
* Set attribute EmbossingType
* @param EnumEmbossingType value the value to set the attribute to
*/
	virtual void SetEmbossingType( EnumEmbossingType value);

/**
* Typesafe enumerated attribute EmbossingType
* @return EnumEmbossingTypethe enumeration value of the attribute
*/
	virtual EnumEmbossingType GetEmbossingType() const;

/**
* Typesafe attribute validation of EmbossingType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidEmbossingType(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute ImageSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetImageSize(const JDFXYPair& value);
/**
* Get string attribute ImageSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetImageSize() const;
/**
* Typesafe attribute validation of ImageSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidImageSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Level
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& LevelString();
/**
* Enumeration string for enum value
* @param EnumLevel value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString LevelString(EnumLevel value);
/**
* Set attribute Level
* @param EnumLevel value the value to set the attribute to
*/
	virtual void SetLevel( EnumLevel value);

/**
* Typesafe enumerated attribute Level
* @return EnumLevelthe enumeration value of the attribute
*/
	virtual EnumLevel GetLevel() const;

/**
* Typesafe attribute validation of Level
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Position
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetPosition(const JDFXYPair& value);
/**
* Get string attribute Position
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetPosition() const;
/**
* Typesafe attribute validation of Position
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPosition(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element IdentificationField
* 
* @param int iSkip number of elements to skip
* @return JDFIdentificationField The element
*/
	JDFIdentificationField GetCreateIdentificationField(int iSkip=0);

/**
* const get element IdentificationField
* @param int iSkip number of elements to skip
* @return JDFIdentificationField The element
*/
	JDFIdentificationField GetIdentificationField(int iSkip=0)const;
/**
* Append element IdentificationField
 */
	JDFIdentificationField AppendIdentificationField();
/**
* create inter-resource link to refTarget
* @param JDFIdentificationField& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefIdentificationField(JDFIdentificationField& refTarget);

/** Get Element Media
* 
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetCreateMedia(int iSkip=0);

/**
* const get element Media
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetMedia(int iSkip=0)const;
/**
* Append element Media
 */
	JDFMedia AppendMedia();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefMedia(JDFMedia& refTarget);

/** Get Element Tool
* 
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetCreateTool(int iSkip=0);

/**
* const get element Tool
* @param int iSkip number of elements to skip
* @return JDFMedia The element
*/
	JDFMedia GetTool(int iSkip=0)const;
/**
* Append element Tool
 */
	JDFMedia AppendTool();
/**
* create inter-resource link to refTarget
* @param JDFMedia& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefTool(JDFMedia& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoEmboss

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoEmboss_H_
