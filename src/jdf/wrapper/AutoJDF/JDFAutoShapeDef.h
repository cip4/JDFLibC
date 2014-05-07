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

 
#if !defined _JDFAutoShapeDef_H_
#define _JDFAutoShapeDef_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFColorPool;
class JDFSeparationList;
class JDFFileSpec;
class JDFMedia;
class JDFShapeElement;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoShapeDef : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoShapeDef class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFShapeDef should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoShapeDef : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoShapeDef():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoShapeDef(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoShapeDef &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoShapeDef(){};
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
* Enumeration for attribute FluteDirection
*/

	enum EnumFluteDirection{FluteDirection_Unknown,FluteDirection_XDirection,FluteDirection_YDirection};
/**
* Enumeration for attribute GrainDirection
*/

	enum EnumGrainDirection{GrainDirection_Unknown,GrainDirection_XDirection,GrainDirection_YDirection,GrainDirection_Both};
/**
* Enumeration for attribute MediaSide
*/

	enum EnumMediaSide{MediaSide_Unknown,MediaSide_Front,MediaSide_Back,MediaSide_Both};

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
* Set attribute Area
*@param double value: the value to set the attribute to
*/
	virtual void SetArea(double value);
/**
* Get double attribute Area
* @return double the vaue of the attribute 
*/
	virtual double GetArea() const;
/**
* Typesafe attribute validation of Area
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidArea(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Dimensions
*@param JDFShape value: the value to set the attribute to
*/
	virtual void SetDimensions(const JDFShape& value);
/**
* Get string attribute Dimensions
* @return JDFShape the vaue of the attribute 
*/
	virtual JDFShape GetDimensions() const;
/**
* Typesafe attribute validation of Dimensions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDimensions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FlatDimensions
*@param JDFShape value: the value to set the attribute to
*/
	virtual void SetFlatDimensions(const JDFShape& value);
/**
* Get string attribute FlatDimensions
* @return JDFShape the vaue of the attribute 
*/
	virtual JDFShape GetFlatDimensions() const;
/**
* Typesafe attribute validation of FlatDimensions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFlatDimensions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for FluteDirection
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FluteDirectionString();
/**
* Enumeration string for enum value
* @param EnumFluteDirection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FluteDirectionString(EnumFluteDirection value);
/**
* Set attribute FluteDirection
* @param EnumFluteDirection value the value to set the attribute to
*/
	virtual void SetFluteDirection( EnumFluteDirection value);

/**
* Typesafe enumerated attribute FluteDirection
* @return EnumFluteDirectionthe enumeration value of the attribute
*/
	virtual EnumFluteDirection GetFluteDirection() const;

/**
* Typesafe attribute validation of FluteDirection
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFluteDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for GrainDirection
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& GrainDirectionString();
/**
* Enumeration string for enum value
* @param EnumGrainDirection value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString GrainDirectionString(EnumGrainDirection value);
/**
* Set attribute GrainDirection
* @param EnumGrainDirection value the value to set the attribute to
*/
	virtual void SetGrainDirection( EnumGrainDirection value);

/**
* Typesafe enumerated attribute GrainDirection
* @return EnumGrainDirectionthe enumeration value of the attribute
*/
	virtual EnumGrainDirection GetGrainDirection() const;

/**
* Typesafe attribute validation of GrainDirection
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidGrainDirection(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MediaSide
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MediaSideString();
/**
* Enumeration string for enum value
* @param EnumMediaSide value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MediaSideString(EnumMediaSide value);
/**
* Set attribute MediaSide
* @param EnumMediaSide value the value to set the attribute to
*/
	virtual void SetMediaSide( EnumMediaSide value);

/**
* Typesafe enumerated attribute MediaSide
* @return EnumMediaSidethe enumeration value of the attribute
*/
	virtual EnumMediaSide GetMediaSide() const;

/**
* Typesafe attribute validation of MediaSide
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMediaSide(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ResourceWeight
*@param double value: the value to set the attribute to
*/
	virtual void SetResourceWeight(double value);
/**
* Get double attribute ResourceWeight
* @return double the vaue of the attribute 
*/
	virtual double GetResourceWeight() const;
/**
* Typesafe attribute validation of ResourceWeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResourceWeight(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ColorPool
* 
* @return JDFColorPool The element
*/
	JDFColorPool GetCreateColorPool();

/**
* const get element ColorPool
*@return  JDFColorPool The element
*/
	JDFColorPool GetColorPool()const;
/**
* Append element ColorPool
 * 
*/
	JDFColorPool AppendColorPool();
/**
* create inter-resource link to refTarget
* @param JDFColorPool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorPool(JDFColorPool& refTarget);

/** Get Element CutLines
* 
* @return JDFSeparationList The element
*/
	JDFSeparationList GetCreateCutLines();

/**
* const get element CutLines
*@return  JDFSeparationList The element
*/
	JDFSeparationList GetCutLines()const;
/**
* Append element CutLines
 * 
*/
	JDFSeparationList AppendCutLines();

/** Get Element FileSpec
* 
* @return JDFFileSpec The element
*/
	JDFFileSpec GetCreateFileSpec();

/**
* const get element FileSpec
*@return  JDFFileSpec The element
*/
	JDFFileSpec GetFileSpec()const;
/**
* Append element FileSpec
 * 
*/
	JDFFileSpec AppendFileSpec();
/**
* create inter-resource link to refTarget
* @param JDFFileSpec& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefFileSpec(JDFFileSpec& refTarget);

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

/** Get Element Shape
* 
* @return JDFShapeElement The element
*/
	JDFShapeElement GetCreateShape();

/**
* const get element Shape
*@return  JDFShapeElement The element
*/
	JDFShapeElement GetShape()const;
/**
* Append element Shape
 * 
*/
	JDFShapeElement AppendShape();
/**
* create inter-resource link to refTarget
* @param JDFShapeElement& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefShape(JDFShapeElement& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoShapeDef

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoShapeDef_H_
