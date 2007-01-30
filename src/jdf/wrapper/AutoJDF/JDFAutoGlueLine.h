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

 
#if !defined _JDFAutoGlueLine_H_
#define _JDFAutoGlueLine_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoGlueLine : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoGlueLine class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFGlueLine should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoGlueLine : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoGlueLine():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoGlueLine(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoGlueLine &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoGlueLine(){};
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
* Enumeration for attribute GlueType
*/

	enum EnumGlueType{GlueType_Unknown,GlueType_ColdGlue,GlueType_Hotmelt,GlueType_PUR};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AreaGlue
*@param bool value: the value to set the attribute to
*/
	virtual void SetAreaGlue(bool value);
/**
* Get bool attribute AreaGlue
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetAreaGlue() const;
/**
* Typesafe attribute validation of AreaGlue
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAreaGlue(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute GlueLineWidth
*@param double value: the value to set the attribute to
*/
	virtual void SetGlueLineWidth(double value);
/**
* Get double attribute GlueLineWidth
* @return double the vaue of the attribute 
*/
	virtual double GetGlueLineWidth() const;
/**
* Typesafe attribute validation of GlueLineWidth
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGlueLineWidth(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GluingPattern
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetGluingPattern(const JDFXYPair& value);
/**
* Get string attribute GluingPattern
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetGluingPattern() const;
/**
* Typesafe attribute validation of GluingPattern
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGluingPattern(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute RelativeStartPosition
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetRelativeStartPosition(const JDFXYPair& value);
/**
* Get string attribute RelativeStartPosition
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetRelativeStartPosition() const;
/**
* Typesafe attribute validation of RelativeStartPosition
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRelativeStartPosition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RelativeWorkingPath
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetRelativeWorkingPath(const JDFXYPair& value);
/**
* Get string attribute RelativeWorkingPath
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetRelativeWorkingPath() const;
/**
* Typesafe attribute validation of RelativeWorkingPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRelativeWorkingPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute StartPosition
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetStartPosition(const JDFXYPair& value);
/**
* Get string attribute StartPosition
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetStartPosition() const;
/**
* Typesafe attribute validation of StartPosition
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStartPosition(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WorkingPath
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetWorkingPath(const JDFXYPair& value);
/**
* Get string attribute WorkingPath
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetWorkingPath() const;
/**
* Typesafe attribute validation of WorkingPath
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWorkingPath(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoGlueLine

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoGlueLine_H_
