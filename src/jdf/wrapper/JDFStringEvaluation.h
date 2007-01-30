/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  17.03.2004
//
// JDFStringEvaluation.h: interface for the JDFStringEvaluation class.
// defines the StringEvaluation attributes and subelements
//
// ////////////////////////////////////////////////////////////////////

 
#if !defined _JDFStringEvaluation_H_
#define _JDFStringEvaluation_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFEvaluation.h"
#include "jdf/wrapper/JDFValue.h"

namespace JDF{
/*
*********************************************************************
class JDFStringEvaluation : public JDFEvaluation

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFStringEvaluation 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFStringEvaluation : public JDFEvaluation{
public:

/** *****************************
* Construction / Destruction
******************************************** */  

//@{
/**
* Empty constructor
	*/
	inline JDFStringEvaluation():JDFEvaluation(){};
	
	/**
	* Copy constructor
	*/
	inline JDFStringEvaluation(const KElement & other):JDFEvaluation(){
		*this=other;
	};
	
	/**
	* Copy equivalance operator
	*/
	JDFStringEvaluation &operator =(const KElement& other);
	
	/**
	* Destructor
	*/
	virtual ~JDFStringEvaluation(){};
	//@}

	/**
	* definition of optional attributes in the JDF namespace
	*
	* @return WString: list of optional attributes
	*/
	virtual WString OptionalAttributes()const;

	/**
	* typesafe validator
	*
	* @param EnumValidationLevel level: validation level
	* @param bool bIgnorePrivate: if true, do not worry about attributes in other namespaces
	* @param int nMax: maximum size of the returned vector
	* @return vWString: a vector of invalid attribute names
	*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

	/**
	* definition of optional elements in the JDF namespace
	*
	* @return WString: list of optional elements
	*/
	virtual WString OptionalElements()const;
	
	/**
	* typesafe validator
	*
	* @param EnumValidationLevel level: validation level
	* @param bIgnorePrivate: if true, do not worry about elements in other namespaces
	* @param int nMax: maximum size of the returned vector
	* @return vWString: a vector of invalid element names
	*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
	
	/**
	* Checks if the node is abstract, i.e. is not completely described
	* utility used by GetUnknownElements, GetUnknownAttributes
	*
	* @return bool: true, if the node is abstract
	*/
	virtual bool IsAbstract()const;

	/**
	* typesafe validator utility - list of valid node names for this class 
	*
	* @return WString: comma separated list of valid node names
	*/
	virtual WString ValidNodeNames()const;

	/**
	* Tests, if the defined 'value' matches testlists, specified for this Evaluation
	*
	* @param const WString& value: value to test
	* @return bool: true, if 'value' matches testlists or if testlists are not specified
	*/
	bool FitsValue(const WString& value) const;

	
	/* ******************************************************
	// Attribute Getter/ Setter
	**************************************************************** */	
	
	//@{
	/**
	* Sets the Length attribute
	*
	* @param JDFIntegerRange& value: value to set the attribute to
	*/
	void SetLength(const JDFIntegerRange& value);

	/**
	* Gets the value of attribute Length  
	*
	* @return JDFIntegerRange: the attribute value
	*/
	JDFIntegerRange GetLength() const ;
	
	/**
	* Typesafe attribute validation of Length
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	bool ValidLength(EnumValidationLevel level) const;
	//@}

	//@{
	/**
	* Gets the value of attribute RegExp
	*
	* @return WString: the attribute value
	*/
	WString GetRegExp()const;

	/**
	* Sets the RegExp attribute
	*
	* @param WString& value: value to set the attribute to
	*/
	void SetRegExp(const WString & value);

	/**
	* Typesafe attribute validation of RegExp
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	bool ValidRegExp(EnumValidationLevel level) const;
	//@}
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */
	
	//@{
	/**
	* Gets the iSkip-th element Value
	*
	* @param int iSkip: number of elements to skip
	* @return JDFValue: the matching element
	*/
	JDFValue GetValue(int iSkip=0)const;

	/**
	* Appends element Value to the end of 'this'
	*
	* @return JDFValue: newly created Value element
	*/
	JDFValue AppendValue();
	//@}


	/* ******************************************************
	// Subelement attribute and element Getter / Setter
	**************************************************************** */
	
	//@{
	/**
	* Sets the Value attribute of i-th subelement Value
	*
	* @param int iSkip: the number of Value elements to skip
	* @param WString& value: value to set the attribute to
	*/
	void SetValueValue(int iSkip, const WString& value);

	/**
	* Gets the value of attribute Value of of i-th subelement Value
	*
	* @param int iSkip: the number of Value elements to skip
	* @return WString: the attribute value
	*/
	WString GetValueValue(int iSkip=0) const;
	//@}


private:
		
	/**
	* Tests, if the defined string 'str' matchesLength, specified for this Evaluation
	*
	* @param WString& str: string to test
	* @return bool: true, if 'str' matches length or if Length is not specified
	*/
	bool FitsLength(const WString& String) const;

	/**
	* Tests, if the defined string 'str' matches RegExp, specified for this Evaluation
	*
	* @param WString& str: string to test
	* @return bool: true, if 'str' matches RegExp or if RegExp is not specified
	*/
	bool FitsRegExp(const WString& str) const;


	/**
	* Tests, if the defined 'str' value matches any subelement Value, specified for this Evaluation
	*
	* @param WString& str: string to test
	* @return bool: true, if 'str' matches subelement Value 
	*/
	bool FitsValueElem(const WString& str) const;


}; // endJDFStringEvaluation

// ******************************************************
}; // end namespace JDF
#endif //_JDFStringEvaluation_H_
