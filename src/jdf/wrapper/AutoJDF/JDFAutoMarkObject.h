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

 
#if !defined _JDFAutoMarkObject_H_
#define _JDFAutoMarkObject_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFPlacedObject.h"
namespace JDF{
class JDFCIELABMeasuringField;
class JDFColorControlStrip;
class JDFCutMark;
class JDFDensityMeasuringField;
class JDFDeviceMark;
class JDFDynamicField;
class JDFFillMark;
class JDFIdentificationField;
class JDFJobField;
class JDFLayoutElement;
class JDFMarkActivation;
class JDFRefAnchor;
class JDFRegisterMark;
class JDFScavengerArea;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoMarkObject : public JDFPlacedObject

*********************************************************************
*/
/**
* automatically generated header for JDFAutoMarkObject class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFMarkObject should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoMarkObject : public JDFPlacedObject{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoMarkObject():JDFPlacedObject(){};
/**
* copy ctor
*/
	inline JDFAutoMarkObject(const KElement & other):JDFPlacedObject(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoMarkObject &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoMarkObject(){};
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
* Enumeration for attribute Anchor
*/

	enum EnumAnchor{Anchor_Unknown,Anchor_TopLeft,Anchor_TopCenter,Anchor_TopRight,Anchor_CenterLeft,Anchor_Center,Anchor_CenterRight,Anchor_BottomLeft,Anchor_BottomCenter,Anchor_BottomRight};
/**
* Enumeration for attribute Type
*/

	enum EnumType{Type_Unknown,Type_Content,Type_Mark};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ContentRef
*@param WString value: the value to set the attribute to
*/
	virtual void SetContentRef(const WString& value);
/**
* Get string attribute ContentRef
* @return WString the vaue of the attribute 
*/
	virtual WString GetContentRef() const;
/**
* Typesafe attribute validation of ContentRef
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidContentRef(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LayoutElementPageNum
*@param int value: the value to set the attribute to
*/
	virtual void SetLayoutElementPageNum(int value);
/**
* Get integer attribute LayoutElementPageNum
* @return int the vaue of the attribute 
*/
	virtual int GetLayoutElementPageNum() const;
/**
* Typesafe attribute validation of LayoutElementPageNum
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayoutElementPageNum(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Ord
*@param int value: the value to set the attribute to
*/
	virtual void SetOrd(int value);
/**
* Get integer attribute Ord
* @return int the vaue of the attribute 
*/
	virtual int GetOrd() const;
/**
* Typesafe attribute validation of Ord
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Anchor
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& AnchorString();
/**
* Enumeration string for enum value
* @param EnumAnchor value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString AnchorString(EnumAnchor value);
/**
* Set attribute Anchor
* @param EnumAnchor value the value to set the attribute to
*/
	virtual void SetAnchor( EnumAnchor value);

/**
* Typesafe enumerated attribute Anchor
* @return EnumAnchorthe enumeration value of the attribute
*/
	virtual EnumAnchor GetAnchor() const;

/**
* Typesafe attribute validation of Anchor
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidAnchor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	virtual void SetAssemblyIDs(const vWString& value);
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetAssemblyIDs() const;
/**
* Typesafe attribute validation of AssemblyIDs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAssemblyIDs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetClipBox(const JDFRectangle& value);
/**
* Get string attribute ClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetClipBox() const;
/**
* Typesafe attribute validation of ClipBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClipBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClipBoxFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetClipBoxFormat(const WString& value);
/**
* Get string attribute ClipBoxFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetClipBoxFormat() const;
/**
* Typesafe attribute validation of ClipBoxFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClipBoxFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClipBoxTemplate
*@param WString value: the value to set the attribute to
*/
	virtual void SetClipBoxTemplate(const WString& value);
/**
* Get string attribute ClipBoxTemplate
* @return WString the vaue of the attribute 
*/
	virtual WString GetClipBoxTemplate() const;
/**
* Typesafe attribute validation of ClipBoxTemplate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClipBoxTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ClipPath
*@param WString value: the value to set the attribute to
*/
	virtual void SetClipPath(const WString& value);
/**
* Get string attribute ClipPath
* @return WString the vaue of the attribute 
*/
	virtual WString GetClipPath() const;
/**
* Typesafe attribute validation of ClipPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidClipPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CompensationCTMFormat
*@param WString value: the value to set the attribute to
*/
	virtual void SetCompensationCTMFormat(const WString& value);
/**
* Get string attribute CompensationCTMFormat
* @return WString the vaue of the attribute 
*/
	virtual WString GetCompensationCTMFormat() const;
/**
* Typesafe attribute validation of CompensationCTMFormat
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCompensationCTMFormat(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CompensationCTMTemplate
*@param WString value: the value to set the attribute to
*/
	virtual void SetCompensationCTMTemplate(const WString& value);
/**
* Get string attribute CompensationCTMTemplate
* @return WString the vaue of the attribute 
*/
	virtual WString GetCompensationCTMTemplate() const;
/**
* Typesafe attribute validation of CompensationCTMTemplate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCompensationCTMTemplate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetCTM(const JDFMatrix& value);
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetCTM() const;
/**
* Typesafe attribute validation of CTM
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCTM(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HalfTonePhaseOrigin
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetHalfTonePhaseOrigin(const JDFXYPair& value);
/**
* Get string attribute HalfTonePhaseOrigin
* @return JDFXYPair the vaue of the attribute ; defaults to 0 0
*/
	virtual JDFXYPair GetHalfTonePhaseOrigin() const;
/**
* Typesafe attribute validation of HalfTonePhaseOrigin
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHalfTonePhaseOrigin(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LayerID
*@param int value: the value to set the attribute to
*/
	virtual void SetLayerID(int value);
/**
* Get integer attribute LayerID
* @return int the vaue of the attribute 
*/
	virtual int GetLayerID() const;
/**
* Typesafe attribute validation of LayerID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLayerID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LogicalStackOrd
*@param int value: the value to set the attribute to
*/
	virtual void SetLogicalStackOrd(int value);
/**
* Get integer attribute LogicalStackOrd
* @return int the vaue of the attribute 
*/
	virtual int GetLogicalStackOrd() const;
/**
* Typesafe attribute validation of LogicalStackOrd
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLogicalStackOrd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OrdID
*@param int value: the value to set the attribute to
*/
	virtual void SetOrdID(int value);
/**
* Get integer attribute OrdID
* @return int the vaue of the attribute 
*/
	virtual int GetOrdID() const;
/**
* Typesafe attribute validation of OrdID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOrdID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SourceClipPath
*@param WString value: the value to set the attribute to
*/
	virtual void SetSourceClipPath(const WString& value);
/**
* Get string attribute SourceClipPath
* @return WString the vaue of the attribute 
*/
	virtual WString GetSourceClipPath() const;
/**
* Typesafe attribute validation of SourceClipPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSourceClipPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimClipPath
*@param WString value: the value to set the attribute to
*/
	virtual void SetTrimClipPath(const WString& value);
/**
* Get string attribute TrimClipPath
* @return WString the vaue of the attribute 
*/
	virtual WString GetTrimClipPath() const;
/**
* Typesafe attribute validation of TrimClipPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimClipPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimCTM
*@param JDFMatrix value: the value to set the attribute to
*/
	virtual void SetTrimCTM(const JDFMatrix& value);
/**
* Get string attribute TrimCTM
* @return JDFMatrix the vaue of the attribute 
*/
	virtual JDFMatrix GetTrimCTM() const;
/**
* Typesafe attribute validation of TrimCTM
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimCTM(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TrimSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetTrimSize(const JDFXYPair& value);
/**
* Get string attribute TrimSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetTrimSize() const;
/**
* Typesafe attribute validation of TrimSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTrimSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Type
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TypeString();
/**
* Enumeration string for enum value
* @param EnumType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TypeString(EnumType value);
/**
* Set attribute Type
* @param EnumType value the value to set the attribute to
*/
	virtual void SetType( EnumType value);

/**
* Typesafe enumerated attribute Type
* @return EnumTypethe enumeration value of the attribute
*/
	virtual EnumType GetType() const;

/**
* Typesafe attribute validation of Type
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element CIELABMeasuringField
* 
* @param int iSkip number of elements to skip
* @return JDFCIELABMeasuringField The element
*/
	JDFCIELABMeasuringField GetCreateCIELABMeasuringField(int iSkip=0);

/**
* const get element CIELABMeasuringField
* @param int iSkip number of elements to skip
* @return JDFCIELABMeasuringField The element
*/
	JDFCIELABMeasuringField GetCIELABMeasuringField(int iSkip=0)const;
/**
* Append element CIELABMeasuringField
 */
	JDFCIELABMeasuringField AppendCIELABMeasuringField();

/** Get Element ColorControlStrip
* 
* @param int iSkip number of elements to skip
* @return JDFColorControlStrip The element
*/
	JDFColorControlStrip GetCreateColorControlStrip(int iSkip=0);

/**
* const get element ColorControlStrip
* @param int iSkip number of elements to skip
* @return JDFColorControlStrip The element
*/
	JDFColorControlStrip GetColorControlStrip(int iSkip=0)const;
/**
* Append element ColorControlStrip
 */
	JDFColorControlStrip AppendColorControlStrip();
/**
* create inter-resource link to refTarget
* @param JDFColorControlStrip& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefColorControlStrip(JDFColorControlStrip& refTarget);

/** Get Element CutMark
* 
* @param int iSkip number of elements to skip
* @return JDFCutMark The element
*/
	JDFCutMark GetCreateCutMark(int iSkip=0);

/**
* const get element CutMark
* @param int iSkip number of elements to skip
* @return JDFCutMark The element
*/
	JDFCutMark GetCutMark(int iSkip=0)const;
/**
* Append element CutMark
 */
	JDFCutMark AppendCutMark();
/**
* create inter-resource link to refTarget
* @param JDFCutMark& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefCutMark(JDFCutMark& refTarget);

/** Get Element DensityMeasuringField
* 
* @param int iSkip number of elements to skip
* @return JDFDensityMeasuringField The element
*/
	JDFDensityMeasuringField GetCreateDensityMeasuringField(int iSkip=0);

/**
* const get element DensityMeasuringField
* @param int iSkip number of elements to skip
* @return JDFDensityMeasuringField The element
*/
	JDFDensityMeasuringField GetDensityMeasuringField(int iSkip=0)const;
/**
* Append element DensityMeasuringField
 */
	JDFDensityMeasuringField AppendDensityMeasuringField();
/**
* create inter-resource link to refTarget
* @param JDFDensityMeasuringField& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDensityMeasuringField(JDFDensityMeasuringField& refTarget);

/** Get Element DeviceMark
* 
* @return JDFDeviceMark The element
*/
	JDFDeviceMark GetCreateDeviceMark();

/**
* const get element DeviceMark
*@return  JDFDeviceMark The element
*/
	JDFDeviceMark GetDeviceMark()const;
/**
* Append element DeviceMark
 * 
*/
	JDFDeviceMark AppendDeviceMark();

/** Get Element DynamicField
* 
* @param int iSkip number of elements to skip
* @return JDFDynamicField The element
*/
	JDFDynamicField GetCreateDynamicField(int iSkip=0);

/**
* const get element DynamicField
* @param int iSkip number of elements to skip
* @return JDFDynamicField The element
*/
	JDFDynamicField GetDynamicField(int iSkip=0)const;
/**
* Append element DynamicField
 */
	JDFDynamicField AppendDynamicField();

/** Get Element FillMark
* 
* @param int iSkip number of elements to skip
* @return JDFFillMark The element
*/
	JDFFillMark GetCreateFillMark(int iSkip=0);

/**
* const get element FillMark
* @param int iSkip number of elements to skip
* @return JDFFillMark The element
*/
	JDFFillMark GetFillMark(int iSkip=0)const;
/**
* Append element FillMark
 */
	JDFFillMark AppendFillMark();

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

/** Get Element JobField
* 
* @param int iSkip number of elements to skip
* @return JDFJobField The element
*/
	JDFJobField GetCreateJobField(int iSkip=0);

/**
* const get element JobField
* @param int iSkip number of elements to skip
* @return JDFJobField The element
*/
	JDFJobField GetJobField(int iSkip=0)const;
/**
* Append element JobField
 */
	JDFJobField AppendJobField();

/** Get Element LayoutElement
* 
* @return JDFLayoutElement The element
*/
	JDFLayoutElement GetCreateLayoutElement();

/**
* const get element LayoutElement
*@return  JDFLayoutElement The element
*/
	JDFLayoutElement GetLayoutElement()const;
/**
* Append element LayoutElement
 * 
*/
	JDFLayoutElement AppendLayoutElement();
/**
* create inter-resource link to refTarget
* @param JDFLayoutElement& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefLayoutElement(JDFLayoutElement& refTarget);

/** Get Element MarkActivation
* 
* @param int iSkip number of elements to skip
* @return JDFMarkActivation The element
*/
	JDFMarkActivation GetCreateMarkActivation(int iSkip=0);

/**
* const get element MarkActivation
* @param int iSkip number of elements to skip
* @return JDFMarkActivation The element
*/
	JDFMarkActivation GetMarkActivation(int iSkip=0)const;
/**
* Append element MarkActivation
 */
	JDFMarkActivation AppendMarkActivation();

/** Get Element RefAnchor
* 
* @param int iSkip number of elements to skip
* @return JDFRefAnchor The element
*/
	JDFRefAnchor GetCreateRefAnchor(int iSkip=0);

/**
* const get element RefAnchor
* @param int iSkip number of elements to skip
* @return JDFRefAnchor The element
*/
	JDFRefAnchor GetRefAnchor(int iSkip=0)const;
/**
* Append element RefAnchor
 */
	JDFRefAnchor AppendRefAnchor();

/** Get Element RegisterMark
* 
* @param int iSkip number of elements to skip
* @return JDFRegisterMark The element
*/
	JDFRegisterMark GetCreateRegisterMark(int iSkip=0);

/**
* const get element RegisterMark
* @param int iSkip number of elements to skip
* @return JDFRegisterMark The element
*/
	JDFRegisterMark GetRegisterMark(int iSkip=0)const;
/**
* Append element RegisterMark
 */
	JDFRegisterMark AppendRegisterMark();
/**
* create inter-resource link to refTarget
* @param JDFRegisterMark& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRegisterMark(JDFRegisterMark& refTarget);

/** Get Element ScavengerArea
* 
* @param int iSkip number of elements to skip
* @return JDFScavengerArea The element
*/
	JDFScavengerArea GetCreateScavengerArea(int iSkip=0);

/**
* const get element ScavengerArea
* @param int iSkip number of elements to skip
* @return JDFScavengerArea The element
*/
	JDFScavengerArea GetScavengerArea(int iSkip=0)const;
/**
* Append element ScavengerArea
 */
	JDFScavengerArea AppendScavengerArea();
/**
* create inter-resource link to refTarget
* @param JDFScavengerArea& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefScavengerArea(JDFScavengerArea& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoMarkObject

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoMarkObject_H_
