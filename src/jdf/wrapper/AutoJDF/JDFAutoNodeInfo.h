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

 
#if !defined _JDFAutoNodeInfo_H_
#define _JDFAutoNodeInfo_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFBusinessInfo;
class JDFEmployee;
class JDFJMF;
class JDFMISDetails;
class JDFNotificationFilter;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoNodeInfo : public JDFResource

*********************************************************************
*/
/**
* automatically generated header for JDFAutoNodeInfo class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFNodeInfo should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoNodeInfo : public JDFResource{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoNodeInfo():JDFResource(){};
/**
* copy ctor
*/
	inline JDFAutoNodeInfo(const KElement & other):JDFResource(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoNodeInfo &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoNodeInfo(){};
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
* Enumeration for attribute DueLevel
*/

	enum EnumDueLevel{DueLevel_Unknown,DueLevel_Trivial,DueLevel_Penalty,DueLevel_JobCancelled};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute JobPriority
*@param int value: the value to set the attribute to
*/
	virtual void SetJobPriority(int value);
/**
* Get integer attribute JobPriority
* @return int the vaue of the attribute ; defaults to 50
*/
	virtual int GetJobPriority() const;
/**
* Typesafe attribute validation of JobPriority
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJobPriority(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute CleanupDuration
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetCleanupDuration(JDFDuration value=JDFDuration());
/**
* Get string attribute CleanupDuration
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetCleanupDuration() const;
/**
* Typesafe attribute validation of CleanupDuration
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCleanupDuration(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for DueLevel
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& DueLevelString();
/**
* Enumeration string for enum value
* @param EnumDueLevel value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString DueLevelString(EnumDueLevel value);
/**
* Set attribute DueLevel
* @param EnumDueLevel value the value to set the attribute to
*/
	virtual void SetDueLevel( EnumDueLevel value);

/**
* Typesafe enumerated attribute DueLevel
* @return EnumDueLevelthe enumeration value of the attribute
*/
	virtual EnumDueLevel GetDueLevel() const;

/**
* Typesafe attribute validation of DueLevel
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidDueLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute FirstEnd
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetFirstEnd(JDFDate value=JDFDate());
/**
* Get string attribute FirstEnd
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetFirstEnd() const;
/**
* Typesafe attribute validation of FirstEnd
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFirstEnd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FirstStart
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetFirstStart(JDFDate value=JDFDate());
/**
* Get string attribute FirstStart
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetFirstStart() const;
/**
* Typesafe attribute validation of FirstStart
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFirstStart(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute IPPVersion
*@param JDFXYPair value: the value to set the attribute to
*/
	virtual void SetIPPVersion(const JDFXYPair& value);
/**
* Get string attribute IPPVersion
* @return JDFXYPair the vaue of the attribute 
*/
	virtual JDFXYPair GetIPPVersion() const;
/**
* Typesafe attribute validation of IPPVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidIPPVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LastEnd
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetLastEnd(JDFDate value=JDFDate());
/**
* Get string attribute LastEnd
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetLastEnd() const;
/**
* Typesafe attribute validation of LastEnd
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLastEnd(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LastStart
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetLastStart(JDFDate value=JDFDate());
/**
* Get string attribute LastStart
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetLastStart() const;
/**
* Typesafe attribute validation of LastStart
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLastStart(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NaturalLang
*@param WString value: the value to set the attribute to
*/
	virtual void SetNaturalLang(const WString& value);
/**
* Get string attribute NaturalLang
* @return WString the vaue of the attribute 
*/
	virtual WString GetNaturalLang() const;
/**
* Typesafe attribute validation of NaturalLang
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNaturalLang(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NodeStatus
* @param JDFElement::EnumStatus value the value to set the attribute to
*/
	virtual void SetNodeStatus( JDFElement::EnumStatus value);

/**
* Typesafe enumerated attribute NodeStatus
* @return EnumNodeStatusthe enumeration value of the attribute
*/
	virtual JDFElement::EnumStatus GetNodeStatus() const;

/**
* Typesafe attribute validation of NodeStatus
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidNodeStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NodeStatusDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetNodeStatusDetails(const WString& value);
/**
* Get string attribute NodeStatusDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetNodeStatusDetails() const;
/**
* Typesafe attribute validation of NodeStatusDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNodeStatusDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MergeTarget
*@param bool value: the value to set the attribute to
*/
	virtual void SetMergeTarget(bool value);
/**
* Get bool attribute MergeTarget
* @return bool the vaue of the attribute 
*/
	virtual bool GetMergeTarget() const;
/**
* Typesafe attribute validation of MergeTarget
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMergeTarget(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Route
*@param WString value: the value to set the attribute to
*/
	virtual void SetRoute(const WString& value);
/**
* Get string attribute Route
* @return WString the vaue of the attribute 
*/
	virtual WString GetRoute() const;
/**
* Typesafe attribute validation of Route
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRoute(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SetupDuration
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetSetupDuration(JDFDuration value=JDFDuration());
/**
* Get string attribute SetupDuration
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetSetupDuration() const;
/**
* Typesafe attribute validation of SetupDuration
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSetupDuration(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute TargetRoute
*@param WString value: the value to set the attribute to
*/
	virtual void SetTargetRoute(const WString& value);
/**
* Get string attribute TargetRoute
* @return WString the vaue of the attribute 
*/
	virtual WString GetTargetRoute() const;
/**
* Typesafe attribute validation of TargetRoute
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTargetRoute(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TotalDuration
*@param JDFDuration value: the value to set the attribute to
*/
	virtual void SetTotalDuration(JDFDuration value=JDFDuration());
/**
* Get string attribute TotalDuration
* @return JDFDuration the vaue of the attribute 
*/
	virtual JDFDuration GetTotalDuration() const;
/**
* Typesafe attribute validation of TotalDuration
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTotalDuration(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element BusinessInfo
* 
* @param int iSkip number of elements to skip
* @return JDFBusinessInfo The element
*/
	JDFBusinessInfo GetCreateBusinessInfo(int iSkip=0);

/**
* const get element BusinessInfo
* @param int iSkip number of elements to skip
* @return JDFBusinessInfo The element
*/
	JDFBusinessInfo GetBusinessInfo(int iSkip=0)const;
/**
* Append element BusinessInfo
 */
	JDFBusinessInfo AppendBusinessInfo();

/** Get Element Employee
* 
* @return JDFEmployee The element
*/
	JDFEmployee GetCreateEmployee();

/**
* const get element Employee
*@return  JDFEmployee The element
*/
	JDFEmployee GetEmployee()const;
/**
* Append element Employee
 * 
*/
	JDFEmployee AppendEmployee();
/**
* create inter-resource link to refTarget
* @param JDFEmployee& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefEmployee(JDFEmployee& refTarget);

/** Get Element JMF
* 
* @param int iSkip number of elements to skip
* @return JDFJMF The element
*/
	JDFJMF GetCreateJMF(int iSkip=0);

/**
* const get element JMF
* @param int iSkip number of elements to skip
* @return JDFJMF The element
*/
	JDFJMF GetJMF(int iSkip=0)const;
/**
* Append element JMF
 */
	JDFJMF AppendJMF();

/** Get Element MISDetails
* 
* @return JDFMISDetails The element
*/
	JDFMISDetails GetCreateMISDetails();

/**
* const get element MISDetails
*@return  JDFMISDetails The element
*/
	JDFMISDetails GetMISDetails()const;
/**
* Append element MISDetails
 * 
*/
	JDFMISDetails AppendMISDetails();

/** Get Element NotificationFilter
* 
* @param int iSkip number of elements to skip
* @return JDFNotificationFilter The element
*/
	JDFNotificationFilter GetCreateNotificationFilter(int iSkip=0);

/**
* const get element NotificationFilter
* @param int iSkip number of elements to skip
* @return JDFNotificationFilter The element
*/
	JDFNotificationFilter GetNotificationFilter(int iSkip=0)const;
/**
* Append element NotificationFilter
 */
	JDFNotificationFilter AppendNotificationFilter();

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoNodeInfo

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoNodeInfo_H_
