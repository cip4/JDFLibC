/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoProcessRun_H_
#define _JDFAutoProcessRun_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFAudit.h"
namespace JDF{
class JDFEmployee;
class JDFPart;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoProcessRun : public JDFAudit

*********************************************************************
*/
/**
* automatically generated header for JDFAutoProcessRun class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFProcessRun should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoProcessRun : public JDFAudit{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoProcessRun():JDFAudit(){};
/**
* copy ctor
*/
	inline JDFAutoProcessRun(const KElement & other):JDFAudit(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoProcessRun &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoProcessRun(){};
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
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute Duration
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetDuration(JDFDuration value=JDFDuration());
/**
* Get string attribute Duration
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetDuration() const;
/**
* Typesafe attribute validation of Duration
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDuration(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute End
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetEnd(JDFDate value=JDFDate());
/**
* Get string attribute End
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetEnd() const;
/**
* Typesafe attribute validation of End
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEnd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute EndStatus
* @param JDFElement::EnumStatus value the value to set the attribute to
*/
	virtual void SetEndStatus( JDFElement::EnumStatus value);

/**
* Typesafe enumerated attribute EndStatus
* @return EnumEndStatusthe enumeration value of the attribute
*/
	virtual JDFElement::EnumStatus GetEndStatus() const;

/**
* Typesafe attribute validation of EndStatus
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidEndStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ReturnTime
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetReturnTime(JDFDate value=JDFDate());
/**
* Get string attribute ReturnTime
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetReturnTime() const;
/**
* Typesafe attribute validation of ReturnTime
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidReturnTime(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Start
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetStart(JDFDate value=JDFDate());
/**
* Get string attribute Start
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetStart() const;
/**
* Typesafe attribute validation of Start
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStart(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SubmissionTime
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetSubmissionTime(JDFDate value=JDFDate());
/**
* Get string attribute SubmissionTime
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetSubmissionTime() const;
/**
* Typesafe attribute validation of SubmissionTime
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSubmissionTime(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Employee
* 
* @param int iSkip number of elements to skip
* @return JDFEmployee The element
*/
	JDFEmployee GetCreateEmployee(int iSkip=0);

/**
* const get element Employee
* @param int iSkip number of elements to skip
* @return JDFEmployee The element
*/
	JDFEmployee GetEmployee(int iSkip=0)const;
/**
* Append element Employee
 */
	JDFEmployee AppendEmployee();
/**
* create inter-resource link to refTarget
* @param JDFEmployee& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefEmployee(JDFEmployee& refTarget);

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
}; // endJDFAutoProcessRun

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoProcessRun_H_
