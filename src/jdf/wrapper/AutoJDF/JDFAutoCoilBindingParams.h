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

 
#if !defined _JDFAutoCoilBindingParams_H_
#define _JDFAutoCoilBindingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFHoleMakingParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoCoilBindingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoCoilBindingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFCoilBindingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoCoilBindingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoCoilBindingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoCoilBindingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoCoilBindingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoCoilBindingParams(){};
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
* Enumeration for attribute Material
*/

	enum EnumMaterial{Material_Unknown,Material_LaqueredSteel,Material_NylonCoatedSteel,Material_PVC,Material_TinnedSteel,Material_ZincsSteel};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Tucked
*@param bool value: the value to set the attribute to
*/
	virtual void SetTucked(bool value);
/**
* Get bool attribute Tucked
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetTucked() const;
/**
* Typesafe attribute validation of Tucked
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTucked(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Brand
*@param WString value: the value to set the attribute to
*/
	virtual void SetBrand(const WString& value);
/**
* Get string attribute Brand
* @return WString the vaue of the attribute 
*/
	virtual WString GetBrand() const;
/**
* Typesafe attribute validation of Brand
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBrand(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Color
* @param EnumNamedColor value the value to set the attribute to
*/
	virtual void SetColor( EnumNamedColor value);

/**
* Typesafe enumerated attribute Color
* @return EnumColorthe enumeration value of the attribute
*/
	virtual EnumNamedColor GetColor() const;

/**
* Typesafe attribute validation of Color
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidColor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Diameter
*@param double value: the value to set the attribute to
*/
	virtual void SetDiameter(double value);
/**
* Get double attribute Diameter
* @return double the vaue of the attribute 
*/
	virtual double GetDiameter() const;
/**
* Typesafe attribute validation of Diameter
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDiameter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Material
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& MaterialString();
/**
* Enumeration string for enum value
* @param EnumMaterial value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString MaterialString(EnumMaterial value);
/**
* Set attribute Material
* @param EnumMaterial value the value to set the attribute to
*/
	virtual void SetMaterial( EnumMaterial value);

/**
* Typesafe enumerated attribute Material
* @return EnumMaterialthe enumeration value of the attribute
*/
	virtual EnumMaterial GetMaterial() const;

/**
* Typesafe attribute validation of Material
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidMaterial(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Shift
*@param double value: the value to set the attribute to
*/
	virtual void SetShift(double value);
/**
* Get double attribute Shift
* @return double the vaue of the attribute 
*/
	virtual double GetShift() const;
/**
* Typesafe attribute validation of Shift
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidShift(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Thickness
*@param double value: the value to set the attribute to
*/
	virtual void SetThickness(double value);
/**
* Get double attribute Thickness
* @return double the vaue of the attribute 
*/
	virtual double GetThickness() const;
/**
* Typesafe attribute validation of Thickness
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidThickness(EnumValidationLevel level=ValidationLevel_Complete) const;

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
}; // endJDFAutoCoilBindingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoCoilBindingParams_H_
