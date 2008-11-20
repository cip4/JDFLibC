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

 
#if !defined _JDFAutoRingBindingParams_H_
#define _JDFAutoRingBindingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFHoleMakingParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoRingBindingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoRingBindingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFRingBindingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoRingBindingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoRingBindingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoRingBindingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoRingBindingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoRingBindingParams(){};
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
* Enumeration for attribute RingSystem
*/

	enum EnumRingSystem{RingSystem_Unknown,RingSystem_2HoleEuro,RingSystem_3HoleUS,RingSystem_4HoleEuro};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BinderColor
* @param EnumNamedColor value the value to set the attribute to
*/
	virtual void SetBinderColor( EnumNamedColor value);

/**
* Typesafe enumerated attribute BinderColor
* @return EnumBinderColorthe enumeration value of the attribute
*/
	virtual EnumNamedColor GetBinderColor() const;

/**
* Typesafe attribute validation of BinderColor
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBinderColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BinderColorDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetBinderColorDetails(const WString& value);
/**
* Get string attribute BinderColorDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetBinderColorDetails() const;
/**
* Typesafe attribute validation of BinderColorDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBinderColorDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BinderMaterial
*@param WString value: the value to set the attribute to
*/
	virtual void SetBinderMaterial(const WString& value);
/**
* Get string attribute BinderMaterial
* @return WString the vaue of the attribute 
*/
	virtual WString GetBinderMaterial() const;
/**
* Typesafe attribute validation of BinderMaterial
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBinderMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BinderName
*@param WString value: the value to set the attribute to
*/
	virtual void SetBinderName(const WString& value);
/**
* Get string attribute BinderName
* @return WString the vaue of the attribute 
*/
	virtual WString GetBinderName() const;
/**
* Typesafe attribute validation of BinderName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBinderName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RingDiameter
*@param double value: the value to set the attribute to
*/
	virtual void SetRingDiameter(double value);
/**
* Get double attribute RingDiameter
* @return double the vaue of the attribute 
*/
	virtual double GetRingDiameter() const;
/**
* Typesafe attribute validation of RingDiameter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRingDiameter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RingMechanic
*@param bool value: the value to set the attribute to
*/
	virtual void SetRingMechanic(bool value);
/**
* Get bool attribute RingMechanic
* @return bool the vaue of the attribute 
*/
	virtual bool GetRingMechanic() const;
/**
* Typesafe attribute validation of RingMechanic
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRingMechanic(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RingShape
*@param WString value: the value to set the attribute to
*/
	virtual void SetRingShape(const WString& value);
/**
* Get string attribute RingShape
* @return WString the vaue of the attribute 
*/
	virtual WString GetRingShape() const;
/**
* Typesafe attribute validation of RingShape
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRingShape(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for RingSystem
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& RingSystemString();
/**
* Enumeration string for enum value
* @param EnumRingSystem value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString RingSystemString(EnumRingSystem value);
/**
* Set attribute RingSystem
* @param EnumRingSystem value the value to set the attribute to
*/
	virtual void SetRingSystem( EnumRingSystem value);

/**
* Typesafe enumerated attribute RingSystem
* @return EnumRingSystemthe enumeration value of the attribute
*/
	virtual EnumRingSystem GetRingSystem() const;

/**
* Typesafe attribute validation of RingSystem
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidRingSystem(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RivetsExposed
*@param bool value: the value to set the attribute to
*/
	virtual void SetRivetsExposed(bool value);
/**
* Get bool attribute RivetsExposed
* @return bool the vaue of the attribute 
*/
	virtual bool GetRivetsExposed() const;
/**
* Typesafe attribute validation of RivetsExposed
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRivetsExposed(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SpineColor
* @param EnumNamedColor value the value to set the attribute to
*/
	virtual void SetSpineColor( EnumNamedColor value);

/**
* Typesafe enumerated attribute SpineColor
* @return EnumSpineColorthe enumeration value of the attribute
*/
	virtual EnumNamedColor GetSpineColor() const;

/**
* Typesafe attribute validation of SpineColor
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidSpineColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SpineColorDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetSpineColorDetails(const WString& value);
/**
* Get string attribute SpineColorDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetSpineColorDetails() const;
/**
* Typesafe attribute validation of SpineColorDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSpineColorDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SpineWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetSpineWidth(double value);
/**
* Get double attribute SpineWidth
* @return double the vaue of the attribute 
*/
	virtual double GetSpineWidth() const;
/**
* Typesafe attribute validation of SpineWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSpineWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ViewBinder
*@param WString value: the value to set the attribute to
*/
	virtual void SetViewBinder(const WString& value);
/**
* Get string attribute ViewBinder
* @return WString the vaue of the attribute 
*/
	virtual WString GetViewBinder() const;
/**
* Typesafe attribute validation of ViewBinder
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidViewBinder(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element HoleMakingParams
* 
* @return JDFHoleMakingParams The element
*/
	JDFHoleMakingParams GetCreateHoleMakingParams();

/**
* const get element HoleMakingParams
*@return  JDFHoleMakingParams The element
*/
	JDFHoleMakingParams GetHoleMakingParams()const;
/**
* Append element HoleMakingParams
 * 
*/
	JDFHoleMakingParams AppendHoleMakingParams();
/**
* create inter-resource link to refTarget
* @param JDFHoleMakingParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefHoleMakingParams(JDFHoleMakingParams& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoRingBindingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoRingBindingParams_H_
