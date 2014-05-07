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

 
#if !defined _JDFAutoPageCondition_H_
#define _JDFAutoPageCondition_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFRunList;
class JDFPart;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPageCondition : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPageCondition class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPageCondition should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPageCondition : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPageCondition():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoPageCondition(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPageCondition &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPageCondition(){};
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
* Enumeration for attribute Condition
*/

	enum EnumCondition{Condition_Unknown,Condition_PagePoolStart,Condition_PagePoolListStart,Condition_PagePoolListEnd,Condition_PagePoolEnd};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute RestrictedContentObjects
*@param JDFIntegerList value: the value to set the attribute to
*/
	virtual void SetRestrictedContentObjects(const JDFIntegerList& value);
/**
* Get string attribute RestrictedContentObjects
* @return JDFIntegerList the vaue of the attribute 
*/
	virtual JDFIntegerList GetRestrictedContentObjects() const;
/**
* Typesafe attribute validation of RestrictedContentObjects
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRestrictedContentObjects(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Condition
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ConditionString();
/**
* Enumeration string for enum value
* @param EnumCondition value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ConditionString(EnumCondition value);
/**
* Set attribute Condition
* @param EnumCondition value the value to set the attribute to
*/
	virtual void SetCondition( EnumCondition value);

/**
* Typesafe enumerated attribute Condition
* @return EnumConditionthe enumeration value of the attribute
*/
	virtual EnumCondition GetCondition() const;

/**
* Typesafe attribute validation of Condition
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCondition(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element RunList
* 
* @param int iSkip number of elements to skip
* @return JDFRunList The element
*/
	JDFRunList GetCreateRunList(int iSkip=0);

/**
* const get element RunList
* @param int iSkip number of elements to skip
* @return JDFRunList The element
*/
	JDFRunList GetRunList(int iSkip=0)const;
/**
* Append element RunList
 */
	JDFRunList AppendRunList();
/**
* create inter-resource link to refTarget
* @param JDFRunList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRunList(JDFRunList& refTarget);

/** Get Element Part
* 
* @param int iSkip number of elements to skip
* @return JDFPart The element
*/
	JDFPart GetCreatePart(int iSkip=0);

/**
* const get element Part
* @param int iSkip number of elements to skip
* @return JDFPart The element
*/
	JDFPart GetPart(int iSkip=0)const;
/**
* Append element Part
 */
	JDFPart AppendPart();
//@{
		/**
		* get part map vector
		* @return vector of mAttribute, one for each part
		*/
		vmAttribute GetPartMapVector()const;
		
		        /**
		* set all parts to those define in vParts
		* @param vmAttribute& vParts vector of attribute maps for the parts
		*/
		void SetPartMapVector(const vmAttribute & vParts);
		/**
		* set part to mPart
		* @param mAttribute& mPart attribute map for the part to set
		*/
	void SetPartMap(const mAttribute & mPart);
		/**
		* remove the part defined in mPart
		* @param mAttribute& mPart attribute map for the part to remove
		*/
		void RemovePartMap(const mAttribute & mPart);
		/**
		* check whether the part defined in mPart is included
		* @param mAttribute& mPart attribute map for the part to remove
		* @return bool if the part exists
		*/
		bool HasPartMap(const mAttribute & mPart);
		//@}

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPageCondition

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPageCondition_H_
