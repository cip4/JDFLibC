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

 
#if !defined _JDFAutoSpawned_H_
#define _JDFAutoSpawned_H_
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
class JDFAutoSpawned : public JDFAudit

*********************************************************************
*/
/**
* automatically generated header for JDFAutoSpawned class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFSpawned should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoSpawned : public JDFAudit{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoSpawned():JDFAudit(){};
/**
* copy ctor
*/
	inline JDFAutoSpawned(const KElement & other):JDFAudit(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoSpawned &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoSpawned(){};
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
* Set attribute Independent
*@param bool value: the value to set the attribute to
*/
	virtual void SetIndependent(bool value);
/**
* Get bool attribute Independent
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetIndependent() const;
/**
* Typesafe attribute validation of Independent
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIndependent(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute jRef
*@param WString value: the value to set the attribute to
*/
	virtual void SetjRef(const WString& value);
/**
* Get string attribute jRef
* @return WString the vaue of the attribute 
*/
	virtual WString GetjRef() const;
/**
* Typesafe attribute validation of jRef
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidjRef(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute jRefDestination
*@param WString value: the value to set the attribute to
*/
	virtual void SetjRefDestination(const WString& value);
/**
* Get string attribute jRefDestination
* @return WString the vaue of the attribute 
*/
	virtual WString GetjRefDestination() const;
/**
* Typesafe attribute validation of jRefDestination
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidjRefDestination(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NewSpawnID
*@param WString value: the value to set the attribute to
*/
	virtual void SetNewSpawnID(const WString& value);
/**
* Get string attribute NewSpawnID
* @return WString the vaue of the attribute 
*/
	virtual WString GetNewSpawnID() const;
/**
* Typesafe attribute validation of NewSpawnID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNewSpawnID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute rRefsROCopied
*@param vWString value: the value to set the attribute to
*/
	virtual void SetrRefsROCopied(const vWString& value);
/**
* Get string attribute rRefsROCopied
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetrRefsROCopied() const;
/**
* Typesafe attribute validation of rRefsROCopied
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidrRefsROCopied(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute rRefsRWCopied
*@param vWString value: the value to set the attribute to
*/
	virtual void SetrRefsRWCopied(const vWString& value);
/**
* Get string attribute rRefsRWCopied
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetrRefsRWCopied() const;
/**
* Typesafe attribute validation of rRefsRWCopied
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidrRefsRWCopied(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Status
* @param EnumStatus value the value to set the attribute to
*/
	virtual void SetStatus( EnumStatus value);

/**
* Typesafe enumerated attribute Status
* @return EnumStatusthe enumeration value of the attribute
*/
	virtual EnumStatus GetStatus() const;

/**
* Typesafe attribute validation of Status
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
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
}; // endJDFAutoSpawned

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoSpawned_H_
