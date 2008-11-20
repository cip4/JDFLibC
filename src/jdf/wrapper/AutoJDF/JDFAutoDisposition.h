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

 
#if !defined _JDFAutoDisposition_H_
#define _JDFAutoDisposition_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFQualityControlResult;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDisposition : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDisposition class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDisposition should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDisposition : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDisposition():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoDisposition(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDisposition &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDisposition(){};
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
* Enumeration for attribute DispositionAction
*/

	enum EnumDispositionAction{DispositionAction_Unknown,DispositionAction_Delete,DispositionAction_Archive};
/**
* Enumeration for attribute DispositionUsage
*/

	enum EnumDispositionUsage{DispositionUsage_Unknown,DispositionUsage_Input,DispositionUsage_Output};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for DispositionAction
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DispositionActionString();
/**
* Enumeration string for enum value
* @param EnumDispositionAction value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DispositionActionString(EnumDispositionAction value);
/**
* Set attribute DispositionAction
* @param EnumDispositionAction value the value to set the attribute to
*/
	virtual void SetDispositionAction( EnumDispositionAction value);

/**
* Typesafe enumerated attribute DispositionAction; defaults to Delete
* @return EnumDispositionActionthe enumeration value of the attribute
*/
	virtual EnumDispositionAction GetDispositionAction() const;

/**
* Typesafe attribute validation of DispositionAction
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDispositionAction(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	virtual void SetPriority(int value);
/**
* Get integer attribute Priority
* @return int the vaue of the attribute ; defaults to 0
*/
	virtual int GetPriority() const;
/**
* Typesafe attribute validation of Priority
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPriority(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DispositionUsage
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DispositionUsageString();
/**
* Enumeration string for enum value
* @param EnumDispositionUsage value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DispositionUsageString(EnumDispositionUsage value);
/**
* Set attribute DispositionUsage
* @param EnumDispositionUsage value the value to set the attribute to
*/
	virtual void SetDispositionUsage( EnumDispositionUsage value);

/**
* Typesafe enumerated attribute DispositionUsage
* @return EnumDispositionUsagethe enumeration value of the attribute
*/
	virtual EnumDispositionUsage GetDispositionUsage() const;

/**
* Typesafe attribute validation of DispositionUsage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDispositionUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ExtraDuration
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetExtraDuration(JDFDuration value=JDFDuration());
/**
* Get string attribute ExtraDuration
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetExtraDuration() const;
/**
* Typesafe attribute validation of ExtraDuration
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidExtraDuration(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MinDuration
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetMinDuration(JDFDuration value=JDFDuration());
/**
* Get string attribute MinDuration
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetMinDuration() const;
/**
* Typesafe attribute validation of MinDuration
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMinDuration(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Until
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetUntil(JDFDate value=JDFDate());
/**
* Get string attribute Until
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetUntil() const;
/**
* Typesafe attribute validation of Until
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUntil(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element QualityControlResult
* 
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetCreateQualityControlResult(int iSkip=0);

/**
* const get element QualityControlResult
* @param int iSkip number of elements to skip
* @return JDFQualityControlResult The element
*/
	JDFQualityControlResult GetQualityControlResult(int iSkip=0)const;
/**
* Append element QualityControlResult
 */
	JDFQualityControlResult AppendQualityControlResult();
/**
* create inter-resource link to refTarget
* @param JDFQualityControlResult& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefQualityControlResult(JDFQualityControlResult& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDisposition

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDisposition_H_
