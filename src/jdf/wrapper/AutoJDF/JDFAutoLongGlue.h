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

 
#if !defined _JDFAutoLongGlue_H_
#define _JDFAutoLongGlue_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLongGlue : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoLongGlue class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFLongGlue should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoLongGlue : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoLongGlue():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoLongGlue(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoLongGlue &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoLongGlue(){};
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
* Enumeration for attribute GlueType
*/

	enum EnumGlueType{GlueType_Unknown,GlueType_ColdGlue,GlueType_Hotmelt,GlueType_PUR};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute GlueBrand
*@param WString value: the value to set the attribute to
*/
	virtual void SetGlueBrand(const WString& value);
/**
* Get string attribute GlueBrand
* @return WString the vaue of the attribute 
*/
	virtual WString GetGlueBrand() const;
/**
* Typesafe attribute validation of GlueBrand
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGlueBrand(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for GlueType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& GlueTypeString();
/**
* Enumeration string for enum value
* @param EnumGlueType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString GlueTypeString(EnumGlueType value);
/**
* Set attribute GlueType
* @param EnumGlueType value the value to set the attribute to
*/
	virtual void SetGlueType( EnumGlueType value);

/**
* Typesafe enumerated attribute GlueType
* @return EnumGlueTypethe enumeration value of the attribute
*/
	virtual EnumGlueType GetGlueType() const;

/**
* Typesafe attribute validation of GlueType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidGlueType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LineWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetLineWidth(double value);
/**
* Get double attribute LineWidth
* @return double the vaue of the attribute 
*/
	virtual double GetLineWidth() const;
/**
* Typesafe attribute validation of LineWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLineWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MeltingTemperature
*@param int value: the value to set the attribute to
*/
	virtual void SetMeltingTemperature(int value);
/**
* Get integer attribute MeltingTemperature
* @return int the vaue of the attribute 
*/
	virtual int GetMeltingTemperature() const;
/**
* Typesafe attribute validation of MeltingTemperature
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMeltingTemperature(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WorkingList
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetWorkingList(const JDFNumberList& value);
/**
* Get string attribute WorkingList
* @return JDFNumberList the vaue of the attribute ; defaults to 0 1000000000
*/
	virtual JDFNumberList GetWorkingList() const;
/**
* Typesafe attribute validation of WorkingList
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWorkingList(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute XOffset
*@param double value: the value to set the attribute to
*/
	virtual void SetXOffset(double value);
/**
* Get double attribute XOffset
* @return double the vaue of the attribute 
*/
	virtual double GetXOffset() const;
/**
* Typesafe attribute validation of XOffset
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidXOffset(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoLongGlue

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoLongGlue_H_
