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

 
#if !defined _JDFAutoQueueSubmissionParams_H_
#define _JDFAutoQueueSubmissionParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFDisposition;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoQueueSubmissionParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoQueueSubmissionParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFQueueSubmissionParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoQueueSubmissionParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoQueueSubmissionParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoQueueSubmissionParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoQueueSubmissionParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoQueueSubmissionParams(){};
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
* Enumeration for attribute GangPolicy
*/

	enum EnumGangPolicy{GangPolicy_Unknown,GangPolicy_Gang,GangPolicy_GangAndForce,GangPolicy_NoGang};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute GangName
*@param WString value: the value to set the attribute to
*/
	virtual void SetGangName(const WString& value);
/**
* Get string attribute GangName
* @return WString the vaue of the attribute 
*/
	virtual WString GetGangName() const;
/**
* Typesafe attribute validation of GangName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGangName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for GangPolicy
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& GangPolicyString();
/**
* Enumeration string for enum value
* @param EnumGangPolicy value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString GangPolicyString(EnumGangPolicy value);
/**
* Set attribute GangPolicy
* @param EnumGangPolicy value the value to set the attribute to
*/
	virtual void SetGangPolicy( EnumGangPolicy value);

/**
* Typesafe enumerated attribute GangPolicy
* @return EnumGangPolicythe enumeration value of the attribute
*/
	virtual EnumGangPolicy GetGangPolicy() const;

/**
* Typesafe attribute validation of GangPolicy
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidGangPolicy(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Hold
*@param bool value: the value to set the attribute to
*/
	virtual void SetHold(bool value);
/**
* Get bool attribute Hold
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetHold() const;
/**
* Typesafe attribute validation of Hold
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidHold(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NextQueueEntryID
*@param WString value: the value to set the attribute to
*/
	virtual void SetNextQueueEntryID(const WString& value);
/**
* Get string attribute NextQueueEntryID
* @return WString the vaue of the attribute 
*/
	virtual WString GetNextQueueEntryID() const;
/**
* Typesafe attribute validation of NextQueueEntryID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNextQueueEntryID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute PrevQueueEntryID
*@param WString value: the value to set the attribute to
*/
	virtual void SetPrevQueueEntryID(const WString& value);
/**
* Get string attribute PrevQueueEntryID
* @return WString the vaue of the attribute 
*/
	virtual WString GetPrevQueueEntryID() const;
/**
* Typesafe attribute validation of PrevQueueEntryID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPrevQueueEntryID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	virtual void SetPriority(int value);
/**
* Get integer attribute Priority
* @return int the vaue of the attribute ; defaults to 1
*/
	virtual int GetPriority() const;
/**
* Typesafe attribute validation of Priority
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPriority(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute refID
*@param WString value: the value to set the attribute to
*/
	virtual void SetrefID(const WString& value);
/**
* Get string attribute refID
* @return WString the vaue of the attribute 
*/
	virtual WString GetrefID() const;
/**
* Typesafe attribute validation of refID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidrefID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ReturnJMF
*@param WString value: the value to set the attribute to
*/
	virtual void SetReturnJMF(const WString& value);
/**
* Get string attribute ReturnJMF
* @return WString the vaue of the attribute 
*/
	virtual WString GetReturnJMF() const;
/**
* Typesafe attribute validation of ReturnJMF
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidReturnJMF(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ReturnURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetReturnURL(const WString& value);
/**
* Get string attribute ReturnURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetReturnURL() const;
/**
* Typesafe attribute validation of ReturnURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidReturnURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	virtual void SetURL(const WString& value);
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	virtual WString GetURL() const;
/**
* Typesafe attribute validation of URL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WatchURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetWatchURL(const WString& value);
/**
* Get string attribute WatchURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetWatchURL() const;
/**
* Typesafe attribute validation of WatchURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWatchURL(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Disposition
* 
* @return JDFDisposition The element
*/
	JDFDisposition GetCreateDispositionElem();

/**
* const get element Disposition
*@return  JDFDisposition The element
*/
	JDFDisposition GetDispositionElem()const;
/**
* Append element Disposition
 * 
*/
	JDFDisposition AppendDispositionElem();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoQueueSubmissionParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoQueueSubmissionParams_H_
