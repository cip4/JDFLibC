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
// JDFXYPairEvaluation.h: interface for the JDFXYPairEvaluation class.
// defines the XYPairEvaluation attributes and subelements
//
// ////////////////////////////////////////////////////////////////////



#if !defined _JDFXYPairEvaluation_H_
#define _JDFXYPairEvaluation_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFEvaluation.h"

namespace JDF{
/*
*********************************************************************
class JDFXYPairEvaluation : public JDFEvaluation

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFXYPairEvaluation 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFXYPairEvaluation : public JDFEvaluation{
public:

/** *****************************
* Construction / Destruction
******************************************** */  

//@{
/**
* Empty constructor
	*/
	inline JDFXYPairEvaluation():JDFEvaluation(){};
	
	/**
	* Copy constructor
	*/
	inline JDFXYPairEvaluation(const KElement & other):JDFEvaluation(){
		*this=other;
	};
	
	/**
	* Copy equivalance operator
	*/
	JDFXYPairEvaluation &operator =(const KElement& other);
	
	/**
	* Destructor
	*/
	virtual ~JDFXYPairEvaluation(){};
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
	* Gets the value of attribute ValueList
	*
	* @return JDFXYPairRangeList: the attribute value
	*/
	JDFXYPairRangeList GetValueList()const;

	/**
	* Sets the ValueList attribute
	*
	* @param JDFXYPairRangeList& value: value to set the attribute to
	*/
	void SetValueList(const JDFXYPairRangeList& value);

	/**
	* Typesafe attribute validation of ValueList
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	bool ValidValueList(EnumValidationLevel level)const;
	//@}


	//@{
	/**
	* Sets the XYRelation attribute
	*
	* @param EnumXYRelation value: value to set the attribute to
	*/
	void SetXYRelation(EnumXYRelation value);
	
	/**
	* Gets the value of attribute XYRelation
	*
	* @return EnumXYRelation: the attribute value
	*/
	JDFElement::EnumXYRelation GetXYRelation() const;
	
	/**
	* Typesafe attribute validation of XYRelation
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/	
	bool ValidXYRelation(EnumValidationLevel level) const;
	//@}

	
	//@{
	/**
	* Gets the value of attribute Tolerance
	*
	* @return JDFXYPair: the attribute value
	*/
	JDFXYPair GetTolerance()const;

	/**
	* Sets the Tolerance attribute
	*
	* @param JDFXYPair value: value to set the attribute to
	*/
	void SetTolerance(JDFXYPair value);

	/**
	* Typesafe attribute validation of Tolerance
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	bool ValidTolerance(EnumValidationLevel level)const;
	//@}



private:
		
	/**
	* Tests, if the defined 'value' matches BasicPreflightTest/@ListType attribute,
	* specified for this Evaluation
	*
	* @param WString& value: value to test
	* @return bool: true, if 'value' matches specified value of BasicPreflightTest/@ListType
	*/
	bool FitsListType(const WString& value) const;
	
	/**
	* Tests, if the defined 'range' is in the ValueList, specified for this Evaluation
	*
	* @param JDFXYPairRange& range: range to test
	* @return bool: true, if 'range' is in the ValueList or if ValueList is not specified
	*/
	bool FitsValueList(const JDFXYPairRange& range) const;

	/**
	* Tests, if the defined 'xypair' value matches XYRelation, specified for this State
	*
	* @param JDFXYPair& xypair: XYPair value to test
	* @return bool: true, if 'xypair' matches XYRelation or if XYRelation is not specified
	*/
	bool FitsXYRelation(const JDFXYPair& xypair) const;

	/**
	* Tests, if this Evaluation has specified Tolerance that it is not equal "0 0" and
	* expands original range to the range, that fits Tolerance.
	*
	* @param JDFXYPairRangeList& rangeList: original range
	* @return JDFXYPairRangeList: expanded range, if Tolerance="0 0" returns original range
	*/
	JDFXYPairRangeList FitsTolerance (const JDFXYPairRangeList& rangeList) const;




}; // endJDFXYPairEvaluation

// ******************************************************
}; // end namespace JDF
#endif //_JDFXYPairEvaluation_H_
