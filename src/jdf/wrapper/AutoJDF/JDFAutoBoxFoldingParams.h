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

 
#if !defined _JDFAutoBoxFoldingParams_H_
#define _JDFAutoBoxFoldingParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFBoxFoldAction;
class JDFGlueLine;
class JDFBoxApplication;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoBoxFoldingParams : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoBoxFoldingParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFBoxFoldingParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoBoxFoldingParams : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoBoxFoldingParams():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoBoxFoldingParams(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoBoxFoldingParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoBoxFoldingParams(){};
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
* Enumeration for attribute BoxFoldingType
*/

	enum EnumBoxFoldingType{BoxFoldingType_Unknown,BoxFoldingType_Type00,BoxFoldingType_Type01,BoxFoldingType_Type02,BoxFoldingType_Type03,BoxFoldingType_Type04,BoxFoldingType_Type10,BoxFoldingType_Type11,BoxFoldingType_Type12,BoxFoldingType_Type13,BoxFoldingType_Type15,BoxFoldingType_Type20};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute BlankDimensionsX
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetBlankDimensionsX(const JDFNumberList& value);
/**
* Get string attribute BlankDimensionsX
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetBlankDimensionsX() const;
/**
* Typesafe attribute validation of BlankDimensionsX
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlankDimensionsX(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute BlankDimensionsY
*@param JDFNumberList value: the value to set the attribute to
*/
	virtual void SetBlankDimensionsY(const JDFNumberList& value);
/**
* Get string attribute BlankDimensionsY
* @return JDFNumberList the vaue of the attribute 
*/
	virtual JDFNumberList GetBlankDimensionsY() const;
/**
* Typesafe attribute validation of BlankDimensionsY
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBlankDimensionsY(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for BoxFoldingType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& BoxFoldingTypeString();
/**
* Enumeration string for enum value
* @param EnumBoxFoldingType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString BoxFoldingTypeString(EnumBoxFoldingType value);
/**
* Set attribute BoxFoldingType
* @param EnumBoxFoldingType value the value to set the attribute to
*/
	virtual void SetBoxFoldingType( EnumBoxFoldingType value);

/**
* Typesafe enumerated attribute BoxFoldingType
* @return EnumBoxFoldingTypethe enumeration value of the attribute
*/
	virtual EnumBoxFoldingType GetBoxFoldingType() const;

/**
* Typesafe attribute validation of BoxFoldingType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidBoxFoldingType(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BoxFoldAction
* 
* @param int iSkip number of elements to skip
* @return JDFBoxFoldAction The element
*/
	JDFBoxFoldAction GetCreateBoxFoldAction(int iSkip=0);

/**
* const get element BoxFoldAction
* @param int iSkip number of elements to skip
* @return JDFBoxFoldAction The element
*/
	JDFBoxFoldAction GetBoxFoldAction(int iSkip=0)const;
/**
* Append element BoxFoldAction
 */
	JDFBoxFoldAction AppendBoxFoldAction();

/** Get Element GlueLine
* 
* @param int iSkip number of elements to skip
* @return JDFGlueLine The element
*/
	JDFGlueLine GetCreateGlueLine(int iSkip=0);

/**
* const get element GlueLine
* @param int iSkip number of elements to skip
* @return JDFGlueLine The element
*/
	JDFGlueLine GetGlueLine(int iSkip=0)const;
/**
* Append element GlueLine
 */
	JDFGlueLine AppendGlueLine();
/**
* create inter-resource link to refTarget
* @param JDFGlueLine& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefGlueLine(JDFGlueLine& refTarget);

/** Get Element BoxApplication
* 
* @param int iSkip number of elements to skip
* @return JDFBoxApplication The element
*/
	JDFBoxApplication GetCreateBoxApplication(int iSkip=0);

/**
* const get element BoxApplication
* @param int iSkip number of elements to skip
* @return JDFBoxApplication The element
*/
	JDFBoxApplication GetBoxApplication(int iSkip=0)const;
/**
* Append element BoxApplication
 */
	JDFBoxApplication AppendBoxApplication();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoBoxFoldingParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoBoxFoldingParams_H_
