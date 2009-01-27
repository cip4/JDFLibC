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

 
#if !defined _JDFAutoDeviceMark_H_
#define _JDFAutoDeviceMark_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFBarcodeReproParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDeviceMark : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDeviceMark class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDeviceMark should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDeviceMark : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDeviceMark():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoDeviceMark(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDeviceMark &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDeviceMark(){};
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
* Enumeration for attribute Anchor
*/

	enum EnumAnchor{Anchor_Unknown,Anchor_TopLeft,Anchor_TopCenter,Anchor_TopRight,Anchor_CenterLeft,Anchor_Center,Anchor_CenterRight,Anchor_BottomLeft,Anchor_BottomCenter,Anchor_BottomRight};
/**
* Enumeration for attribute HorizontalFitPolicy
*/

	enum EnumHorizontalFitPolicy{HorizontalFitPolicy_Unknown,HorizontalFitPolicy_NoRepeat,HorizontalFitPolicy_StretchToFit,HorizontalFitPolicy_UndistortedScaleToFit,HorizontalFitPolicy_RepeatToFill,HorizontalFitPolicy_RepeatUnclipped};
/**
* Enumeration for attribute MarkJustification
*/

	enum EnumMarkJustification{MarkJustification_Unknown,MarkJustification_Left,MarkJustification_Right,MarkJustification_Center};
/**
* Enumeration for attribute MarkOrientation
*/

	enum EnumMarkOrientation{MarkOrientation_Unknown,MarkOrientation_Vertical,MarkOrientation_Horizontal};
/**
* Enumeration for attribute MarkPosition
*/

	enum EnumMarkPosition{MarkPosition_Unknown,MarkPosition_Top,MarkPosition_Bottom,MarkPosition_Left,MarkPosition_Right};
/**
* Enumeration for attribute VerticalFitPolicy
*/

	enum EnumVerticalFitPolicy{VerticalFitPolicy_Unknown,VerticalFitPolicy_NoRepeat,VerticalFitPolicy_StretchToFit,VerticalFitPolicy_UndistortedScaleToFit,VerticalFitPolicy_RepeatToFill,VerticalFitPolicy_RepeatUnclipped};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

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
* Set attribute Font
*@param WString value: the value to set the attribute to
*/
	virtual void SetFont(const WString& value);
/**
* Get string attribute Font
* @return WString the vaue of the attribute 
*/
	virtual WString GetFont() const;
/**
* Typesafe attribute validation of Font
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFont(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FontSize
*@param double value: the value to set the attribute to
*/
	virtual void SetFontSize(double value);
/**
* Get double attribute FontSize
* @return double the vaue of the attribute 
*/
	virtual double GetFontSize() const;
/**
* Typesafe attribute validation of FontSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFontSize(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Enumeration strings for MarkJustification
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MarkJustificationString();
/**
* Enumeration string for enum value
* @param EnumMarkJustification value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MarkJustificationString(EnumMarkJustification value);
/**
* Set attribute MarkJustification
* @param EnumMarkJustification value the value to set the attribute to
*/
	virtual void SetMarkJustification( EnumMarkJustification value);

/**
* Typesafe enumerated attribute MarkJustification
* @return EnumMarkJustificationthe enumeration value of the attribute
*/
	virtual EnumMarkJustification GetMarkJustification() const;

/**
* Typesafe attribute validation of MarkJustification
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMarkJustification(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MarkOffset
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetMarkOffset(const JDFXYPair& value);
/**
* Get string attribute MarkOffset
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetMarkOffset() const;
/**
* Typesafe attribute validation of MarkOffset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMarkOffset(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MarkOrientation
* @param EnumOrientation value the value to set the attribute to
*/
	virtual void SetMarkOrientation( EnumOrientation value);

/**
* Typesafe enumerated attribute MarkOrientation
* @return EnumMarkOrientationthe enumeration value of the attribute
*/
	virtual EnumOrientation GetMarkOrientation() const;

/**
* Typesafe attribute validation of MarkOrientation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMarkOrientation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for MarkPosition
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MarkPositionString();
/**
* Enumeration string for enum value
* @param EnumMarkPosition value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MarkPositionString(EnumMarkPosition value);
/**
* Set attribute MarkPosition
* @param EnumMarkPosition value the value to set the attribute to
*/
	virtual void SetMarkPosition( EnumMarkPosition value);

/**
* Typesafe enumerated attribute MarkPosition
* @return EnumMarkPositionthe enumeration value of the attribute
*/
	virtual EnumMarkPosition GetMarkPosition() const;

/**
* Typesafe attribute validation of MarkPosition
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMarkPosition(EnumValidationLevel level=ValidationLevel_Complete) const;
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


/** Get Element BarcodeReproParams
* 
* @param int iSkip number of elements to skip
* @return JDFBarcodeReproParams The element
*/
	JDFBarcodeReproParams GetCreateBarcodeReproParams(int iSkip=0);

/**
* const get element BarcodeReproParams
* @param int iSkip number of elements to skip
* @return JDFBarcodeReproParams The element
*/
	JDFBarcodeReproParams GetBarcodeReproParams(int iSkip=0)const;
/**
* Append element BarcodeReproParams
 */
	JDFBarcodeReproParams AppendBarcodeReproParams();
/**
* create inter-resource link to refTarget
* @param JDFBarcodeReproParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefBarcodeReproParams(JDFBarcodeReproParams& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDeviceMark

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDeviceMark_H_
