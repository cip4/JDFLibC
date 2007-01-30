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

 
#if !defined _JDFAutoxor_H_
#define _JDFAutoxor_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFTestRef;
class JDFBooleanEvaluation;
class JDFDateTimeEvaluation;
class JDFDurationEvaluation;
class JDFEnumerationEvaluation;
class JDFIntegerEvaluation;
class JDFIsPresentEvaluation;
class JDFMatrixEvaluation;
class JDFNameEvaluation;
class JDFNumberEvaluation;
class JDFPDFPathEvaluation;
class JDFRectangleEvaluation;
class JDFShapeEvaluation;
class JDFStringEvaluation;
class JDFXYPairEvaluation;
class JDFand;
class JDFor;
class JDFnot;
class JDFxor;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoxor : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoxor class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFxor should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoxor : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoxor():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoxor(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoxor &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoxor(){};
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


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element TestRef
* 
* @param int iSkip number of elements to skip
* @return JDFTestRef The element
*/
	JDFTestRef GetCreateTestRef(int iSkip=0);

/**
* const get element TestRef
* @param int iSkip number of elements to skip
* @return JDFTestRef The element
*/
	JDFTestRef GetTestRef(int iSkip=0)const;
/**
* Append element TestRef
 */
	JDFTestRef AppendTestRef();

/** Get Element BooleanEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFBooleanEvaluation The element
*/
	JDFBooleanEvaluation GetCreateBooleanEvaluation(int iSkip=0);

/**
* const get element BooleanEvaluation
* @param int iSkip number of elements to skip
* @return JDFBooleanEvaluation The element
*/
	JDFBooleanEvaluation GetBooleanEvaluation(int iSkip=0)const;
/**
* Append element BooleanEvaluation
 */
	JDFBooleanEvaluation AppendBooleanEvaluation();

/** Get Element DateTimeEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFDateTimeEvaluation The element
*/
	JDFDateTimeEvaluation GetCreateDateTimeEvaluation(int iSkip=0);

/**
* const get element DateTimeEvaluation
* @param int iSkip number of elements to skip
* @return JDFDateTimeEvaluation The element
*/
	JDFDateTimeEvaluation GetDateTimeEvaluation(int iSkip=0)const;
/**
* Append element DateTimeEvaluation
 */
	JDFDateTimeEvaluation AppendDateTimeEvaluation();

/** Get Element DurationEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFDurationEvaluation The element
*/
	JDFDurationEvaluation GetCreateDurationEvaluation(int iSkip=0);

/**
* const get element DurationEvaluation
* @param int iSkip number of elements to skip
* @return JDFDurationEvaluation The element
*/
	JDFDurationEvaluation GetDurationEvaluation(int iSkip=0)const;
/**
* Append element DurationEvaluation
 */
	JDFDurationEvaluation AppendDurationEvaluation();

/** Get Element EnumerationEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFEnumerationEvaluation The element
*/
	JDFEnumerationEvaluation GetCreateEnumerationEvaluation(int iSkip=0);

/**
* const get element EnumerationEvaluation
* @param int iSkip number of elements to skip
* @return JDFEnumerationEvaluation The element
*/
	JDFEnumerationEvaluation GetEnumerationEvaluation(int iSkip=0)const;
/**
* Append element EnumerationEvaluation
 */
	JDFEnumerationEvaluation AppendEnumerationEvaluation();

/** Get Element IntegerEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFIntegerEvaluation The element
*/
	JDFIntegerEvaluation GetCreateIntegerEvaluation(int iSkip=0);

/**
* const get element IntegerEvaluation
* @param int iSkip number of elements to skip
* @return JDFIntegerEvaluation The element
*/
	JDFIntegerEvaluation GetIntegerEvaluation(int iSkip=0)const;
/**
* Append element IntegerEvaluation
 */
	JDFIntegerEvaluation AppendIntegerEvaluation();

/** Get Element IsPresentEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFIsPresentEvaluation The element
*/
	JDFIsPresentEvaluation GetCreateIsPresentEvaluation(int iSkip=0);

/**
* const get element IsPresentEvaluation
* @param int iSkip number of elements to skip
* @return JDFIsPresentEvaluation The element
*/
	JDFIsPresentEvaluation GetIsPresentEvaluation(int iSkip=0)const;
/**
* Append element IsPresentEvaluation
 */
	JDFIsPresentEvaluation AppendIsPresentEvaluation();

/** Get Element MatrixEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFMatrixEvaluation The element
*/
	JDFMatrixEvaluation GetCreateMatrixEvaluation(int iSkip=0);

/**
* const get element MatrixEvaluation
* @param int iSkip number of elements to skip
* @return JDFMatrixEvaluation The element
*/
	JDFMatrixEvaluation GetMatrixEvaluation(int iSkip=0)const;
/**
* Append element MatrixEvaluation
 */
	JDFMatrixEvaluation AppendMatrixEvaluation();

/** Get Element NameEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFNameEvaluation The element
*/
	JDFNameEvaluation GetCreateNameEvaluation(int iSkip=0);

/**
* const get element NameEvaluation
* @param int iSkip number of elements to skip
* @return JDFNameEvaluation The element
*/
	JDFNameEvaluation GetNameEvaluation(int iSkip=0)const;
/**
* Append element NameEvaluation
 */
	JDFNameEvaluation AppendNameEvaluation();

/** Get Element NumberEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFNumberEvaluation The element
*/
	JDFNumberEvaluation GetCreateNumberEvaluation(int iSkip=0);

/**
* const get element NumberEvaluation
* @param int iSkip number of elements to skip
* @return JDFNumberEvaluation The element
*/
	JDFNumberEvaluation GetNumberEvaluation(int iSkip=0)const;
/**
* Append element NumberEvaluation
 */
	JDFNumberEvaluation AppendNumberEvaluation();

/** Get Element PDFPathEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFPDFPathEvaluation The element
*/
	JDFPDFPathEvaluation GetCreatePDFPathEvaluation(int iSkip=0);

/**
* const get element PDFPathEvaluation
* @param int iSkip number of elements to skip
* @return JDFPDFPathEvaluation The element
*/
	JDFPDFPathEvaluation GetPDFPathEvaluation(int iSkip=0)const;
/**
* Append element PDFPathEvaluation
 */
	JDFPDFPathEvaluation AppendPDFPathEvaluation();

/** Get Element RectangleEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFRectangleEvaluation The element
*/
	JDFRectangleEvaluation GetCreateRectangleEvaluation(int iSkip=0);

/**
* const get element RectangleEvaluation
* @param int iSkip number of elements to skip
* @return JDFRectangleEvaluation The element
*/
	JDFRectangleEvaluation GetRectangleEvaluation(int iSkip=0)const;
/**
* Append element RectangleEvaluation
 */
	JDFRectangleEvaluation AppendRectangleEvaluation();

/** Get Element ShapeEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFShapeEvaluation The element
*/
	JDFShapeEvaluation GetCreateShapeEvaluation(int iSkip=0);

/**
* const get element ShapeEvaluation
* @param int iSkip number of elements to skip
* @return JDFShapeEvaluation The element
*/
	JDFShapeEvaluation GetShapeEvaluation(int iSkip=0)const;
/**
* Append element ShapeEvaluation
 */
	JDFShapeEvaluation AppendShapeEvaluation();

/** Get Element StringEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFStringEvaluation The element
*/
	JDFStringEvaluation GetCreateStringEvaluation(int iSkip=0);

/**
* const get element StringEvaluation
* @param int iSkip number of elements to skip
* @return JDFStringEvaluation The element
*/
	JDFStringEvaluation GetStringEvaluation(int iSkip=0)const;
/**
* Append element StringEvaluation
 */
	JDFStringEvaluation AppendStringEvaluation();

/** Get Element XYPairEvaluation
* 
* @param int iSkip number of elements to skip
* @return JDFXYPairEvaluation The element
*/
	JDFXYPairEvaluation GetCreateXYPairEvaluation(int iSkip=0);

/**
* const get element XYPairEvaluation
* @param int iSkip number of elements to skip
* @return JDFXYPairEvaluation The element
*/
	JDFXYPairEvaluation GetXYPairEvaluation(int iSkip=0)const;
/**
* Append element XYPairEvaluation
 */
	JDFXYPairEvaluation AppendXYPairEvaluation();

/** Get Element and
* 
* @param int iSkip number of elements to skip
* @return JDFand The element
*/
	JDFand GetCreateand(int iSkip=0);

/**
* const get element and
* @param int iSkip number of elements to skip
* @return JDFand The element
*/
	JDFand Getand(int iSkip=0)const;
/**
* Append element and
 */
	JDFand Appendand();

/** Get Element or
* 
* @param int iSkip number of elements to skip
* @return JDFor The element
*/
	JDFor GetCreateor(int iSkip=0);

/**
* const get element or
* @param int iSkip number of elements to skip
* @return JDFor The element
*/
	JDFor Getor(int iSkip=0)const;
/**
* Append element or
 */
	JDFor Appendor();

/** Get Element not
* 
* @param int iSkip number of elements to skip
* @return JDFnot The element
*/
	JDFnot GetCreatenot(int iSkip=0);

/**
* const get element not
* @param int iSkip number of elements to skip
* @return JDFnot The element
*/
	JDFnot Getnot(int iSkip=0)const;
/**
* Append element not
 */
	JDFnot Appendnot();

/** Get Element xor
* 
* @param int iSkip number of elements to skip
* @return JDFxor The element
*/
	JDFxor GetCreatexor(int iSkip=0);

/**
* const get element xor
* @param int iSkip number of elements to skip
* @return JDFxor The element
*/
	JDFxor Getxor(int iSkip=0)const;
/**
* Append element xor
 */
	JDFxor Appendxor();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoxor

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoxor_H_
