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

 
#if !defined _JDFAutoHoleMakingParams_H_
#define _JDFAutoHoleMakingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFHole;
class JDFHoleLine;
class JDFRegisterMark;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoHoleMakingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoHoleMakingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFHoleMakingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoHoleMakingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoHoleMakingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoHoleMakingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoHoleMakingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoHoleMakingParams(){};
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
* Enumeration for attribute CenterReference
*/

	enum EnumCenterReference{CenterReference_Unknown,CenterReference_TrailingEdge,CenterReference_RegistrationMark};
/**
* Enumeration for attribute HoleType
*/

	enum EnumHoleType{HoleType_Unknown,HoleType_R2_generic,HoleType_R2m_DIN,HoleType_R2m_ISO,HoleType_R2m_MIB,HoleType_R2i_US_a,HoleType_R2i_US_b,HoleType_R3_generic,HoleType_R3i_US,HoleType_R4_generic,HoleType_R4m_DIN_A4,HoleType_R4m_DIN_A5,HoleType_R4m_swedish,HoleType_R4i_US,HoleType_R5_generic,HoleType_R5i_US_a,HoleType_R5i_US_b,HoleType_R5i_US_c,HoleType_R6_generic,HoleType_R6m_4h2s,HoleType_R6m_DIN_A5,HoleType_R7_generic,HoleType_R7i_US_a,HoleType_R7i_US_b,HoleType_R7i_US_c,HoleType_R11m_7h4s,HoleType_P16_9i_rect_0t,HoleType_P12m_rect_0t,HoleType_W2_1i_round_0t,HoleType_W2_1i_square_0t,HoleType_W3_1i_square_0t,HoleType_C9_5m_round_0t};
/**
* Enumeration for attribute HoleReferenceEdge
*/

	enum EnumHoleReferenceEdge{HoleReferenceEdge_Unknown,HoleReferenceEdge_Left,HoleReferenceEdge_Right,HoleReferenceEdge_Top,HoleReferenceEdge_Bottom,HoleReferenceEdge_Pattern};
/**
* Enumeration for attribute Shape
*/

	enum EnumShape{Shape_Unknown,Shape_Eliptical,Shape_Round,Shape_Rectangular};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for CenterReference
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CenterReferenceString();
/**
* Enumeration string for enum value
* @param EnumCenterReference value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CenterReferenceString(EnumCenterReference value);
/**
* Set attribute CenterReference
* @param EnumCenterReference value the value to set the attribute to
*/
	virtual void SetCenterReference( EnumCenterReference value);

/**
* Typesafe enumerated attribute CenterReference; defaults to TrailingEdge
* @return EnumCenterReferencethe enumeration value of the attribute
*/
	virtual EnumCenterReference GetCenterReference() const;

/**
* Typesafe attribute validation of CenterReference
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCenterReference(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for HoleType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& HoleTypeString();
/**
* Enumeration string for enum value
* @param EnumHoleType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString HoleTypeString(EnumHoleType value);
/**
* Append value to the attribute HoleType
* @param EnumHoleType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddHoleType( EnumHoleType value);
/**
* Remove value from the attribute HoleType
* @param EnumHoleType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveHoleType( EnumHoleType value);
/**
* Typesafe enumerated attribute HoleType
* @return EnumHoleTypethe enumeration value of the attribute
*/
	virtual vint GetHoleType() const;
/**
* Set value of the attribute HoleType
* @param EnumHoleType value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetHoleType( EnumHoleType value);
/**
* Set value of the attribute HoleType to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetHoleType( const vint& value);
/**
* Typesafe attribute validation of HoleType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidHoleType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Center
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetCenter(const JDFXYPair& value);
/**
* Get string attribute Center
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetCenter() const;
/**
* Typesafe attribute validation of Center
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCenter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Extent
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetExtent(const JDFXYPair& value);
/**
* Get string attribute Extent
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetExtent() const;
/**
* Typesafe attribute validation of Extent
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidExtent(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HoleCount
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetHoleCount(const JDFIntegerList& value);
/**
* Get string attribute HoleCount
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetHoleCount() const;
/**
* Typesafe attribute validation of HoleCount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHoleCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for HoleReferenceEdge
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& HoleReferenceEdgeString();
/**
* Enumeration string for enum value
* @param EnumHoleReferenceEdge value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString HoleReferenceEdgeString(EnumHoleReferenceEdge value);
/**
* Set attribute HoleReferenceEdge
* @param EnumHoleReferenceEdge value the value to set the attribute to
*/
	virtual void SetHoleReferenceEdge( EnumHoleReferenceEdge value);

/**
* Typesafe enumerated attribute HoleReferenceEdge
* @return EnumHoleReferenceEdgethe enumeration value of the attribute
*/
	virtual EnumHoleReferenceEdge GetHoleReferenceEdge() const;

/**
* Typesafe attribute validation of HoleReferenceEdge
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidHoleReferenceEdge(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Shape
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ShapeString();
/**
* Enumeration string for enum value
* @param EnumShape value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ShapeString(EnumShape value);
/**
* Set attribute Shape
* @param EnumShape value the value to set the attribute to
*/
	virtual void SetShape( EnumShape value);

/**
* Typesafe enumerated attribute Shape
* @return EnumShapethe enumeration value of the attribute
*/
	virtual EnumShape GetShape() const;

/**
* Typesafe attribute validation of Shape
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidShape(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Hole
* 
* @param int iSkip number of elements to skip
* @return JDFHole The element
*/
	JDFHole GetCreateHole(int iSkip=0);

/**
* const get element Hole
* @param int iSkip number of elements to skip
* @return JDFHole The element
*/
	JDFHole GetHole(int iSkip=0)const;
/**
* Append element Hole
 */
	JDFHole AppendHole();
/**
* create inter-resource link to refTarget
* @param JDFHole& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefHole(JDFHole& refTarget);

/** Get Element HoleLine
* 
* @param int iSkip number of elements to skip
* @return JDFHoleLine The element
*/
	JDFHoleLine GetCreateHoleLine(int iSkip=0);

/**
* const get element HoleLine
* @param int iSkip number of elements to skip
* @return JDFHoleLine The element
*/
	JDFHoleLine GetHoleLine(int iSkip=0)const;
/**
* Append element HoleLine
 */
	JDFHoleLine AppendHoleLine();
/**
* create inter-resource link to refTarget
* @param JDFHoleLine& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefHoleLine(JDFHoleLine& refTarget);

/** Get Element RegisterMark
* 
* @return JDFRegisterMark The element
*/
	JDFRegisterMark GetCreateRegisterMark();

/**
* const get element RegisterMark
*@return  JDFRegisterMark The element
*/
	JDFRegisterMark GetRegisterMark()const;
/**
* Append element RegisterMark
 * 
*/
	JDFRegisterMark AppendRegisterMark();
/**
* create inter-resource link to refTarget
* @param JDFRegisterMark& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRegisterMark(JDFRegisterMark& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoHoleMakingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoHoleMakingParams_H_
