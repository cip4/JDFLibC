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

 
#if !defined _JDFAutoStripMark_H_
#define _JDFAutoStripMark_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFPosition;
class JDFJobField;
class JDFRefAnchor;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoStripMark : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoStripMark class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFStripMark should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoStripMark : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoStripMark():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoStripMark(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoStripMark &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoStripMark(){};
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
* Enumeration for attribute HorizontalFitPolicy
*/

	enum EnumHorizontalFitPolicy{HorizontalFitPolicy_Unknown,HorizontalFitPolicy_NoRepeat,HorizontalFitPolicy_StretchToFit,HorizontalFitPolicy_UndistortedScaleToFit,HorizontalFitPolicy_RepeatToFill,HorizontalFitPolicy_RepeatUnclipped};
/**
* Enumeration for attribute MarkContext
*/

	enum EnumMarkContext{MarkContext_Unknown,MarkContext_Sheet,MarkContext_BinderySignature,MarkContext_Cell,MarkContext_CellPair};
/**
* Enumeration for attribute MarkSide
*/

	enum EnumMarkSide{MarkSide_Unknown,MarkSide_Front,MarkSide_Back,MarkSide_TwoSidedBackToBack,MarkSide_TwoSidedIndependent};
/**
* Enumeration for attribute VerticalFitPolicy
*/

	enum EnumVerticalFitPolicy{VerticalFitPolicy_Unknown,VerticalFitPolicy_NoRepeat,VerticalFitPolicy_StretchToFit,VerticalFitPolicy_UndistortedScaleToFit,VerticalFitPolicy_RepeatToFill,VerticalFitPolicy_RepeatUnclipped};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AbsoluteHeight
*@param double value: the value to set the attribute to
*/
	virtual void SetAbsoluteHeight(double value);
/**
* Get double attribute AbsoluteHeight
* @return double the vaue of the attribute 
*/
	virtual double GetAbsoluteHeight() const;
/**
* Typesafe attribute validation of AbsoluteHeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAbsoluteHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AbsoluteWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetAbsoluteWidth(double value);
/**
* Get double attribute AbsoluteWidth
* @return double the vaue of the attribute 
*/
	virtual double GetAbsoluteWidth() const;
/**
* Typesafe attribute validation of AbsoluteWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAbsoluteWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Enumeration strings for HorizontalFitPolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& HorizontalFitPolicyString();
/**
* Enumeration string for enum value
* @param EnumHorizontalFitPolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString HorizontalFitPolicyString(EnumHorizontalFitPolicy value);
/**
* Set attribute HorizontalFitPolicy
* @param EnumHorizontalFitPolicy value the value to set the attribute to
*/
	virtual void SetHorizontalFitPolicy( EnumHorizontalFitPolicy value);

/**
* Typesafe enumerated attribute HorizontalFitPolicy
* @return EnumHorizontalFitPolicythe enumeration value of the attribute
*/
	virtual EnumHorizontalFitPolicy GetHorizontalFitPolicy() const;

/**
* Typesafe attribute validation of HorizontalFitPolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidHorizontalFitPolicy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	virtual void SetID(const WString& value);
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	virtual WString GetID() const;
/**
* Typesafe attribute validation of ID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MarkContext
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MarkContextString();
/**
* Enumeration string for enum value
* @param EnumMarkContext value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MarkContextString(EnumMarkContext value);
/**
* Set attribute MarkContext
* @param EnumMarkContext value the value to set the attribute to
*/
	virtual void SetMarkContext( EnumMarkContext value);

/**
* Typesafe enumerated attribute MarkContext
* @return EnumMarkContextthe enumeration value of the attribute
*/
	virtual EnumMarkContext GetMarkContext() const;

/**
* Typesafe attribute validation of MarkContext
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMarkContext(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MarkName
*@param WString value: the value to set the attribute to
*/
	virtual void SetMarkName(const WString& value);
/**
* Get string attribute MarkName
* @return WString the vaue of the attribute 
*/
	virtual WString GetMarkName() const;
/**
* Typesafe attribute validation of MarkName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMarkName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MarkSide
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MarkSideString();
/**
* Enumeration string for enum value
* @param EnumMarkSide value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MarkSideString(EnumMarkSide value);
/**
* Set attribute MarkSide
* @param EnumMarkSide value the value to set the attribute to
*/
	virtual void SetMarkSide( EnumMarkSide value);

/**
* Typesafe enumerated attribute MarkSide
* @return EnumMarkSidethe enumeration value of the attribute
*/
	virtual EnumMarkSide GetMarkSide() const;

/**
* Typesafe attribute validation of MarkSide
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMarkSide(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Offset
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetOffset(const JDFXYPair& value);
/**
* Get string attribute Offset
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetOffset() const;
/**
* Typesafe attribute validation of Offset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOffset(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Orientation
* @param EnumOrientation value the value to set the attribute to
*/
	virtual void SetOrientation( EnumOrientation value);

/**
* Typesafe enumerated attribute Orientation
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
* Set attribute RelativeHeight
*@param double value: the value to set the attribute to
*/
	virtual void SetRelativeHeight(double value);
/**
* Get double attribute RelativeHeight
* @return double the vaue of the attribute 
*/
	virtual double GetRelativeHeight() const;
/**
* Typesafe attribute validation of RelativeHeight
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRelativeHeight(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RelativeWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetRelativeWidth(double value);
/**
* Get double attribute RelativeWidth
* @return double the vaue of the attribute 
*/
	virtual double GetRelativeWidth() const;
/**
* Typesafe attribute validation of RelativeWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRelativeWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StripMarkDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetStripMarkDetails(const WString& value);
/**
* Get string attribute StripMarkDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetStripMarkDetails() const;
/**
* Typesafe attribute validation of StripMarkDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStripMarkDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for VerticalFitPolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& VerticalFitPolicyString();
/**
* Enumeration string for enum value
* @param EnumVerticalFitPolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString VerticalFitPolicyString(EnumVerticalFitPolicy value);
/**
* Set attribute VerticalFitPolicy
* @param EnumVerticalFitPolicy value the value to set the attribute to
*/
	virtual void SetVerticalFitPolicy( EnumVerticalFitPolicy value);

/**
* Typesafe enumerated attribute VerticalFitPolicy
* @return EnumVerticalFitPolicythe enumeration value of the attribute
*/
	virtual EnumVerticalFitPolicy GetVerticalFitPolicy() const;

/**
* Typesafe attribute validation of VerticalFitPolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidVerticalFitPolicy(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Position
* 
* @param int iSkip number of elements to skip
* @return JDFPosition The element
*/
	JDFPosition GetCreatePosition(int iSkip=0);

/**
* const get element Position
* @param int iSkip number of elements to skip
* @return JDFPosition The element
*/
	JDFPosition GetPosition(int iSkip=0)const;
/**
* Append element Position
 */
	JDFPosition AppendPosition();

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
/**
* create inter-resource link to refTarget
* @param JDFJobField& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefJobField(JDFJobField& refTarget);

/** Get Element RefAnchor
* 
* @return JDFRefAnchor The element
*/
	JDFRefAnchor GetCreateRefAnchor();

/**
* const get element RefAnchor
*@return  JDFRefAnchor The element
*/
	JDFRefAnchor GetRefAnchor()const;
/**
* Append element RefAnchor
 * 
*/
	JDFRefAnchor AppendRefAnchor();
/**
* create inter-resource link to refTarget
* @param JDFRefAnchor& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRefAnchor(JDFRefAnchor& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoStripMark

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoStripMark_H_
