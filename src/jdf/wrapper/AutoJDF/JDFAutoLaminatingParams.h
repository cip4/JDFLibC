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

 
#if !defined _JDFAutoLaminatingParams_H_
#define _JDFAutoLaminatingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLaminatingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoLaminatingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFLaminatingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoLaminatingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoLaminatingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoLaminatingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoLaminatingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoLaminatingParams(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

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
* Enumeration for attribute LaminatingMethod
*/

	enum EnumLaminatingMethod{LaminatingMethod_Unknown,LaminatingMethod_CompoundFoil,LaminatingMethod_DispersionGlue,LaminatingMethod_Fusing};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute LaminatingBox
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetLaminatingBox(const JDFRectangle& value);
/**
* Get string attribute LaminatingBox
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetLaminatingBox() const;
/**
* Typesafe attribute validation of LaminatingBox
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLaminatingBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AdhesiveType
*@param WString value: the value to set the attribute to
*/
	virtual void SetAdhesiveType(const WString& value);
/**
* Get string attribute AdhesiveType
* @return WString the vaue of the attribute 
*/
	virtual WString GetAdhesiveType() const;
/**
* Typesafe attribute validation of AdhesiveType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAdhesiveType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GapList
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetGapList(const JDFNumberList& value);
/**
* Get string attribute GapList
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetGapList() const;
/**
* Typesafe attribute validation of GapList
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGapList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute HardenerType
*@param WString value: the value to set the attribute to
*/
	virtual void SetHardenerType(const WString& value);
/**
* Get string attribute HardenerType
* @return WString the vaue of the attribute 
*/
	virtual WString GetHardenerType() const;
/**
* Typesafe attribute validation of HardenerType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHardenerType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for LaminatingMethod
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& LaminatingMethodString();
/**
* Enumeration string for enum value
* @param EnumLaminatingMethod value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString LaminatingMethodString(EnumLaminatingMethod value);
/**
* Set attribute LaminatingMethod
* @param EnumLaminatingMethod value the value to set the attribute to
*/
	virtual void SetLaminatingMethod( EnumLaminatingMethod value);

/**
* Typesafe enumerated attribute LaminatingMethod
* @return EnumLaminatingMethodthe enumeration value of the attribute
*/
	virtual EnumLaminatingMethod GetLaminatingMethod() const;

/**
* Typesafe attribute validation of LaminatingMethod
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidLaminatingMethod(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NipWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetNipWidth(double value);
/**
* Get double attribute NipWidth
* @return double the vaue of the attribute 
*/
	virtual double GetNipWidth() const;
/**
* Typesafe attribute validation of NipWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNipWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Temperature
*@param double value: the value to set the attribute to
*/
	virtual void SetTemperature(double value);
/**
* Get double attribute Temperature
* @return double the vaue of the attribute 
*/
	virtual double GetTemperature() const;
/**
* Typesafe attribute validation of Temperature
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTemperature(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoLaminatingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoLaminatingParams_H_
