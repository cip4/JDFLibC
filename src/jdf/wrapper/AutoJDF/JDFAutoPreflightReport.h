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

 
#if !defined _JDFAutoPreflightReport_H_
#define _JDFAutoPreflightReport_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFPreflightParams;
class JDFPreflightReportRulePool;
class JDFRunList;
class JDFPRItem;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoPreflightReport : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoPreflightReport class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFPreflightReport should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoPreflightReport : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoPreflightReport():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoPreflightReport(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoPreflightReport &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoPreflightReport(){};
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
 * Typesafe attribute validation of Class
* @return true if class is valid
*/
virtual bool ValidClass(EnumValidationLevel level) const;

/** 
 * Typesafe initialization
 * @return true if succcessful
*/
virtual bool init();

/**
* Enumeration for attribute ErrorState
*/

	enum EnumErrorState{ErrorState_Unknown,ErrorState_TestNotSupported,ErrorState_TestWrongPDL};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ErrorCount
*@param int value: the value to set the attribute to
*/
	virtual void SetErrorCount(int value);
/**
* Get integer attribute ErrorCount
* @return int the vaue of the attribute 
*/
	virtual int GetErrorCount() const;
/**
* Typesafe attribute validation of ErrorCount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidErrorCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute WarningCount
*@param int value: the value to set the attribute to
*/
	virtual void SetWarningCount(int value);
/**
* Get integer attribute WarningCount
* @return int the vaue of the attribute 
*/
	virtual int GetWarningCount() const;
/**
* Typesafe attribute validation of WarningCount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidWarningCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ErrorState
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ErrorStateString();
/**
* Enumeration string for enum value
* @param EnumErrorState value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ErrorStateString(EnumErrorState value);
/**
* Set attribute ErrorState
* @param EnumErrorState value the value to set the attribute to
*/
	virtual void SetErrorState( EnumErrorState value);

/**
* Typesafe enumerated attribute ErrorState
* @return EnumErrorStatethe enumeration value of the attribute
*/
	virtual EnumErrorState GetErrorState() const;

/**
* Typesafe attribute validation of ErrorState
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidErrorState(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element PreflightParams
* 
* @return JDFPreflightParams The element
*/
	JDFPreflightParams GetCreatePreflightParams();

/**
* const get element PreflightParams
*@return  JDFPreflightParams The element
*/
	JDFPreflightParams GetPreflightParams()const;
/**
* Append element PreflightParams
 * 
*/
	JDFPreflightParams AppendPreflightParams();
/**
* create inter-resource link to refTarget
* @param JDFPreflightParams& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefPreflightParams(JDFPreflightParams& refTarget);

/** Get Element PreflightReportRulePool
* 
* @return JDFPreflightReportRulePool The element
*/
	JDFPreflightReportRulePool GetCreatePreflightReportRulePool();

/**
* const get element PreflightReportRulePool
*@return  JDFPreflightReportRulePool The element
*/
	JDFPreflightReportRulePool GetPreflightReportRulePool()const;
/**
* Append element PreflightReportRulePool
 * 
*/
	JDFPreflightReportRulePool AppendPreflightReportRulePool();
/**
* create inter-resource link to refTarget
* @param JDFPreflightReportRulePool& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefPreflightReportRulePool(JDFPreflightReportRulePool& refTarget);

/** Get Element RunList
* 
* @return JDFRunList The element
*/
	JDFRunList GetCreateRunList();

/**
* const get element RunList
*@return  JDFRunList The element
*/
	JDFRunList GetRunList()const;
/**
* Append element RunList
 * 
*/
	JDFRunList AppendRunList();
/**
* create inter-resource link to refTarget
* @param JDFRunList& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefRunList(JDFRunList& refTarget);

/** Get Element PRItem
* 
* @param int iSkip number of elements to skip
* @return JDFPRItem The element
*/
	JDFPRItem GetCreatePRItem(int iSkip=0);

/**
* const get element PRItem
* @param int iSkip number of elements to skip
* @return JDFPRItem The element
*/
	JDFPRItem GetPRItem(int iSkip=0)const;
/**
* Append element PRItem
 */
	JDFPRItem AppendPRItem();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of required elements in the JDF namespace
*/
	virtual WString RequiredElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoPreflightReport

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoPreflightReport_H_
