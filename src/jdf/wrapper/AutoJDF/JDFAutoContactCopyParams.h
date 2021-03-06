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

 
#if !defined _JDFAutoContactCopyParams_H_
#define _JDFAutoContactCopyParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFScreeningParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoContactCopyParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoContactCopyParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFContactCopyParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoContactCopyParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoContactCopyParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoContactCopyParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoContactCopyParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoContactCopyParams(){};
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
* Enumeration for attribute Diffusion
*/

	enum EnumDiffusion{Diffusion_Unknown,Diffusion_On,Diffusion_Off};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ContactScreen
*@param bool value: the value to set the attribute to
*/
	virtual void SetContactScreen(bool value);
/**
* Get bool attribute ContactScreen
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetContactScreen() const;
/**
* Typesafe attribute validation of ContactScreen
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidContactScreen(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PolarityChange
*@param bool value: the value to set the attribute to
*/
	virtual void SetPolarityChange(bool value);
/**
* Get bool attribute PolarityChange
* @return bool the vaue of the attribute ; defaults to true
*/
	virtual bool GetPolarityChange() const;
/**
* Typesafe attribute validation of PolarityChange
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPolarityChange(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RepeatStep
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetRepeatStep(const JDFXYPair& value);
/**
* Get string attribute RepeatStep
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	virtual JDFXYPair GetRepeatStep() const;
/**
* Typesafe attribute validation of RepeatStep
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRepeatStep(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Cycle
*@param int value: the value to set the attribute to
*/
	virtual void SetCycle(int value);
/**
* Get integer attribute Cycle
* @return int the vaue of the attribute 
*/
	virtual int GetCycle() const;
/**
* Typesafe attribute validation of Cycle
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCycle(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Diffusion
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DiffusionString();
/**
* Enumeration string for enum value
* @param EnumDiffusion value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DiffusionString(EnumDiffusion value);
/**
* Set attribute Diffusion
* @param EnumDiffusion value the value to set the attribute to
*/
	virtual void SetDiffusion( EnumDiffusion value);

/**
* Typesafe enumerated attribute Diffusion
* @return EnumDiffusionthe enumeration value of the attribute
*/
	virtual EnumDiffusion GetDiffusion() const;

/**
* Typesafe attribute validation of Diffusion
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDiffusion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Vacuum
*@param double value: the value to set the attribute to
*/
	virtual void SetVacuum(double value);
/**
* Get double attribute Vacuum
* @return double the vaue of the attribute 
*/
	virtual double GetVacuum() const;
/**
* Typesafe attribute validation of Vacuum
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidVacuum(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element ScreeningParams
* 
* @return JDFScreeningParams The element
*/
	JDFScreeningParams GetCreateScreeningParams();

/**
* const get element ScreeningParams
*@return  JDFScreeningParams The element
*/
	JDFScreeningParams GetScreeningParams()const;
/**
* Append element ScreeningParams
 * 
*/
	JDFScreeningParams AppendScreeningParams();
/**
* create inter-resource link to refTarget
* @param JDFScreeningParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefScreeningParams(JDFScreeningParams& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoContactCopyParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoContactCopyParams_H_
