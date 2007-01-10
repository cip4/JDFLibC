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

 
#if !defined _JDFAutoProofItem_H_
#define _JDFAutoProofItem_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
class JDFSeparationSpec;
class JDFApprovalParams;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoProofItem : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoProofItem class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFProofItem should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoProofItem : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoProofItem():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoProofItem(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoProofItem &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoProofItem(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Contract
*@param bool value: the value to set the attribute to
*/
	virtual void SetContract(bool value);
/**
* Get bool attribute Contract
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetContract() const;
/**
* Typesafe attribute validation of Contract
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidContract(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PageIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetPageIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute PageIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetPageIndex() const;
/**
* Typesafe attribute validation of PageIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPageIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProofName
*@param WString value: the value to set the attribute to
*/
	virtual void SetProofName(const WString& value);
/**
* Get string attribute ProofName
* @return WString the vaue of the attribute 
*/
	virtual WString GetProofName() const;
/**
* Typesafe attribute validation of ProofName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProofName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProofTarget
*@param WString value: the value to set the attribute to
*/
	virtual void SetProofTarget(const WString& value);
/**
* Get string attribute ProofTarget
* @return WString the vaue of the attribute 
*/
	virtual WString GetProofTarget() const;
/**
* Typesafe attribute validation of ProofTarget
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProofTarget(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Amount
* 
* @return JDFIntegerSpan The element
*/
	JDFIntegerSpan GetCreateAmount();

/**
* const get element Amount
*@return  JDFIntegerSpan The element
*/
	JDFIntegerSpan GetAmount()const;
/**
* Append element Amount
 * 
*/
	JDFIntegerSpan AppendAmount();

/** Get Element BrandName
* 
* @return JDFStringSpan The element
*/
	JDFStringSpan GetCreateBrandName();

/**
* const get element BrandName
*@return  JDFStringSpan The element
*/
	JDFStringSpan GetBrandName()const;
/**
* Append element BrandName
 * 
*/
	JDFStringSpan AppendBrandName();

/** Get Element ColorType
* 
* @return JDFSpanColorType The element
*/
	JDFSpanColorType GetCreateColorType();

/**
* const get element ColorType
*@return  JDFSpanColorType The element
*/
	JDFSpanColorType GetColorType()const;
/**
* Append element ColorType
 * 
*/
	JDFSpanColorType AppendColorType();

/** Get Element HalfTone
* 
* @return JDFOptionSpan The element
*/
	JDFOptionSpan GetCreateHalfTone();

/**
* const get element HalfTone
*@return  JDFOptionSpan The element
*/
	JDFOptionSpan GetHalfTone()const;
/**
* Append element HalfTone
 * 
*/
	JDFOptionSpan AppendHalfTone();

/** Get Element ImageStrategy
* 
* @return JDFSpanImageStrategy The element
*/
	JDFSpanImageStrategy GetCreateImageStrategy();

/**
* const get element ImageStrategy
*@return  JDFSpanImageStrategy The element
*/
	JDFSpanImageStrategy GetImageStrategy()const;
/**
* Append element ImageStrategy
 * 
*/
	JDFSpanImageStrategy AppendImageStrategy();

/** Get Element Technology
* 
* @return JDFNameSpan The element
*/
	JDFNameSpan GetCreateTechnology();

/**
* const get element Technology
*@return  JDFNameSpan The element
*/
	JDFNameSpan GetTechnology()const;
/**
* Append element Technology
 * 
*/
	JDFNameSpan AppendTechnology();

/** Get Element ProofType
* 
* @return JDFSpanProofType The element
*/
	JDFSpanProofType GetCreateProofType();

/**
* const get element ProofType
*@return  JDFSpanProofType The element
*/
	JDFSpanProofType GetProofType()const;
/**
* Append element ProofType
 * 
*/
	JDFSpanProofType AppendProofType();

/** Get Element SeparationSpec
* 
* @param int iSkip number of elements to skip
* @return JDFSeparationSpec The element
*/
	JDFSeparationSpec GetCreateSeparationSpec(int iSkip=0);

/**
* const get element SeparationSpec
* @param int iSkip number of elements to skip
* @return JDFSeparationSpec The element
*/
	JDFSeparationSpec GetSeparationSpec(int iSkip=0)const;
/**
* Append element SeparationSpec
 */
	JDFSeparationSpec AppendSeparationSpec();
/**
* create inter-resource link to refTarget
* @param JDFSeparationSpec& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefSeparationSpec(JDFSeparationSpec& refTarget);

/** Get Element ApprovalParams
* 
* @return JDFApprovalParams The element
*/
	JDFApprovalParams GetCreateApprovalParams();

/**
* const get element ApprovalParams
*@return  JDFApprovalParams The element
*/
	JDFApprovalParams GetApprovalParams()const;
/**
* Append element ApprovalParams
 * 
*/
	JDFApprovalParams AppendApprovalParams();
/**
* create inter-resource link to refTarget
* @param JDFApprovalParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefApprovalParams(JDFApprovalParams& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoProofItem

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoProofItem_H_
