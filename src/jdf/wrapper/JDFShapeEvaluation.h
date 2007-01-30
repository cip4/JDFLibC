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
// JDFShapeEvaluation.h: interface for the JDFShapeEvaluation class.
// defines the ShapeEvaluation attributes and subelements
//
// ////////////////////////////////////////////////////////////////////



#if !defined _JDFShapeEvaluation_H_
#define _JDFShapeEvaluation_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFEvaluation.h"

namespace JDF{
/*
*********************************************************************
class JDFShapeEvaluation : public JDFEvaluation

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFShapeEvaluation 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFShapeEvaluation : public JDFEvaluation{
public:

/** *****************************
* Construction / Destruction
******************************************** */  

//@{
/**
* Empty constructor
	*/
	inline JDFShapeEvaluation():JDFEvaluation(){};
	
	/**
	* Copy constructor
	*/
	inline JDFShapeEvaluation(const KElement & other):JDFEvaluation(){
		*this=other;
	};
	
	/**
	* Copy equivalance operator
	*/
	JDFShapeEvaluation &operator =(const KElement& other);
	
	/**
	* Destructor
	*/
	virtual ~JDFShapeEvaluation(){};
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
	* @return JDFShapeRangeList: the attribute value
	*/
	JDFShapeRangeList GetValueList()const;

	/**
	* Sets the ValueList attribute
	*
	* @param JDFShapeRangeList& value: value to set the attribute to
	*/
	void SetValueList(const JDFShapeRangeList& value);

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
	* Gets the value of attribute X
	*
	* @return NumberRangeList&: the attribute value
	*/
	NumberRangeList GetX()const;

	/**
	* Sets the X attribute
	*
	* @param NumberRangeList& value: value to set the attribute to
	*/
	void SetX(const NumberRangeList& value);

	/**
	* Typesafe attribute validation of X
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	bool ValidX(EnumValidationLevel level)const;
	//@}


	//@{
	/**
	* Gets the value of attribute Y
	*
	* @return NumberRangeList&: the attribute value
	*/
	NumberRangeList GetY()const;

	/**
	* Sets the Y attribute
	*
	* @param NumberRangeList& value: value to set the attribute to
	*/
	void SetY(const NumberRangeList& value);

	/**
	* Typesafe attribute validation of Y
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	bool ValidY(EnumValidationLevel level)const;
	//@}


	//@{
	/**
	* Gets the value of attribute Z
	*
	* @return NumberRangeList&: the attribute value
	*/
	NumberRangeList GetZ()const;

	/**
	* Sets the Z attribute
	*
	* @param NumberRangeList& value: value to set the attribute to
	*/
	void SetZ(const NumberRangeList& value);

	/**
	* Typesafe attribute validation of Z
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	bool ValidZ(EnumValidationLevel level)const;
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
	* @param JDFXYPair& value: value to set the attribute to
	*/
	void SetTolerance(const JDFXYPair& value);

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
	* @param JDFShapeRange& range: range to test
	* @return bool: true, if 'range' is in the ValueList or if ValueList is not specified
	*/
	bool FitsValueList(const JDFShapeRange& range) const;

	/**
	* Tests, if the defined 'range' matches the test lists X, Y, Z, specified for this Evaluation
	*
	* @param JDFShapeRange& range: range to test
	* @return bool: true, if the 'range' matches xyzlist or if X, Y, Z are not specified
	*/
	bool FitsXYZ (const JDFShapeRange& range) const;

	/**
	* Tests, if this Evaluation has specified Tolerance that it is not equal "0 0" and
	* expands original range to the range, that fits Tolerance.
	*
	* @param JDFShapeRangeList& rangeList: original range
	* @return JDFShapeRangeList: expanded range, if Tolerance="0 0" returns original range
	*/
	JDFShapeRangeList FitsTolerance (const JDFShapeRangeList& rangeList) const;

	/**
	* Tests, if this Evaluation has specified Tolerance that it is not equal "0 0" and
	* expands original rangelist to the rangelist, that fits Tolerance.
	*
	* @param NumberRangeList& rangeList: original rangelist
	* @return NumberRangeList: expanded rangelist, if Tolerance="0 0" returns original range
	*/
	NumberRangeList FitsXYZTolerance (const NumberRangeList& rangeList) const;


}; // endJDFShapeEvaluation

// ******************************************************
}; // end namespace JDF
#endif //_JDFShapeEvaluation_H_
