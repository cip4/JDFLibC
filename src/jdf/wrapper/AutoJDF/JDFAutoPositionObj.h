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

 
#if !defined _JDFAutoPositionObj_H_
#define _JDFAutoPositionObj_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFRefAnchor;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPositionObj : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPositionObj class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPositionObj should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPositionObj : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPositionObj():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPositionObj(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPositionObj &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPositionObj(){};
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
* Enumeration for attribute PositionPolicy
*/

	enum EnumPositionPolicy{PositionPolicy_Unknown,PositionPolicy_Exact,PositionPolicy_Free};
/**
* Enumeration for attribute RotationPolicy
*/

	enum EnumRotationPolicy{RotationPolicy_Unknown,RotationPolicy_Exact,RotationPolicy_Free};
/**
* Enumeration for attribute SizePolicy
*/

	enum EnumSizePolicy{SizePolicy_Unknown,SizePolicy_Exact,SizePolicy_Free};

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
* Set attribute PageRange
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetPageRange(const JDFIntegerRangeList& value);
/**
* Get range attribute PageRange
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetPageRange() const;
/**
* Typesafe attribute validation of PageRange
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageRange(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for PositionPolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& PositionPolicyString();
/**
* Enumeration string for enum value
* @param EnumPositionPolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString PositionPolicyString(EnumPositionPolicy value);
/**
* Set attribute PositionPolicy
* @param EnumPositionPolicy value the value to set the attribute to
*/
	virtual void SetPositionPolicy( EnumPositionPolicy value);

/**
* Typesafe enumerated attribute PositionPolicy
* @return EnumPositionPolicythe enumeration value of the attribute
*/
	virtual EnumPositionPolicy GetPositionPolicy() const;

/**
* Typesafe attribute validation of PositionPolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidPositionPolicy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RelativeSize
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetRelativeSize(const JDFXYPair& value);
/**
* Get string attribute RelativeSize
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetRelativeSize() const;
/**
* Typesafe attribute validation of RelativeSize
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRelativeSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for RotationPolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& RotationPolicyString();
/**
* Enumeration string for enum value
* @param EnumRotationPolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString RotationPolicyString(EnumRotationPolicy value);
/**
* Set attribute RotationPolicy
* @param EnumRotationPolicy value the value to set the attribute to
*/
	virtual void SetRotationPolicy( EnumRotationPolicy value);

/**
* Typesafe enumerated attribute RotationPolicy
* @return EnumRotationPolicythe enumeration value of the attribute
*/
	virtual EnumRotationPolicy GetRotationPolicy() const;

/**
* Typesafe attribute validation of RotationPolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidRotationPolicy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Size
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetSize(const JDFXYPair& value);
/**
* Get string attribute Size
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetSize() const;
/**
* Typesafe attribute validation of Size
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSize(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for SizePolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& SizePolicyString();
/**
* Enumeration string for enum value
* @param EnumSizePolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString SizePolicyString(EnumSizePolicy value);
/**
* Set attribute SizePolicy
* @param EnumSizePolicy value the value to set the attribute to
*/
	virtual void SetSizePolicy( EnumSizePolicy value);

/**
* Typesafe enumerated attribute SizePolicy
* @return EnumSizePolicythe enumeration value of the attribute
*/
	virtual EnumSizePolicy GetSizePolicy() const;

/**
* Typesafe attribute validation of SizePolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSizePolicy(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


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

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPositionObj

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPositionObj_H_
