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

 
#if !defined _JDFAutoAncestor_H_
#define _JDFAutoAncestor_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFCustomerInfo;
class JDFNodeInfo;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoAncestor : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoAncestor class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFAncestor should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoAncestor : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoAncestor():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoAncestor(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoAncestor &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoAncestor(){};
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
* Enumeration for attribute Activation
*/

	enum EnumActivation{Activation_Unknown,Activation_Inactive,Activation_Informative,Activation_Held,Activation_Active,Activation_TestRun,Activation_TestRunAndGo};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for Activation
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ActivationString();
/**
* Enumeration string for enum value
* @param EnumActivation value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ActivationString(EnumActivation value);
/**
* Set attribute Activation
* @param EnumActivation value the value to set the attribute to
*/
	virtual void SetActivation( EnumActivation value);

/**
* Typesafe enumerated attribute Activation
* @return EnumActivationthe enumeration value of the attribute
*/
	virtual EnumActivation GetActivation() const;

/**
* Typesafe attribute validation of Activation
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidActivation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute FileName
*@param WString value: the value to set the attribute to
*/
	virtual void SetFileName(const WString& value);
/**
* Get string attribute FileName
* @return WString the vaue of the attribute 
*/
	virtual WString GetFileName() const;
/**
* Typesafe attribute validation of FileName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidFileName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ICSVersions
*@param vWString value: the value to set the attribute to
*/
	virtual void SetICSVersions(const vWString& value);
/**
* Get string attribute ICSVersions
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetICSVersions() const;
/**
* Typesafe attribute validation of ICSVersions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidICSVersions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	virtual void SetJobID(const WString& value);
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	virtual WString GetJobID() const;
/**
* Typesafe attribute validation of JobID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJobID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	virtual void SetJobPartID(const WString& value);
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	virtual WString GetJobPartID() const;
/**
* Typesafe attribute validation of JobPartID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidJobPartID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetMaxVersion(const WString& value);
/**
* Get string attribute MaxVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetMaxVersion() const;
/**
* Typesafe attribute validation of MaxVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NodeID
*@param WString value: the value to set the attribute to
*/
	virtual void SetNodeID(const WString& value);
/**
* Get string attribute NodeID
* @return WString the vaue of the attribute 
*/
	virtual WString GetNodeID() const;
/**
* Typesafe attribute validation of NodeID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNodeID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProjectID
*@param WString value: the value to set the attribute to
*/
	virtual void SetProjectID(const WString& value);
/**
* Get string attribute ProjectID
* @return WString the vaue of the attribute 
*/
	virtual WString GetProjectID() const;
/**
* Typesafe attribute validation of ProjectID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProjectID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RelatedJobID
*@param WString value: the value to set the attribute to
*/
	virtual void SetRelatedJobID(const WString& value);
/**
* Get string attribute RelatedJobID
* @return WString the vaue of the attribute 
*/
	virtual WString GetRelatedJobID() const;
/**
* Typesafe attribute validation of RelatedJobID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRelatedJobID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute RelatedJobPartID
*@param WString value: the value to set the attribute to
*/
	virtual void SetRelatedJobPartID(const WString& value);
/**
* Get string attribute RelatedJobPartID
* @return WString the vaue of the attribute 
*/
	virtual WString GetRelatedJobPartID() const;
/**
* Typesafe attribute validation of RelatedJobPartID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRelatedJobPartID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SpawnID
*@param WString value: the value to set the attribute to
*/
	virtual void SetSpawnID(const WString& value);
/**
* Get string attribute SpawnID
* @return WString the vaue of the attribute 
*/
	virtual WString GetSpawnID() const;
/**
* Typesafe attribute validation of SpawnID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSpawnID(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute StatusDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetStatusDetails(const WString& value);
/**
* Get string attribute StatusDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetStatusDetails() const;
/**
* Typesafe attribute validation of StatusDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStatusDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	virtual void SetType(const WString& value);
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	virtual WString GetType() const;
/**
* Typesafe attribute validation of Type
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Types
*@param vWString value: the value to set the attribute to
*/
	virtual void SetTypes(const vWString& value);
/**
* Get string attribute Types
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetTypes() const;
/**
* Typesafe attribute validation of Types
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTypes(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Version
*@param WString value: the value to set the attribute to
*/
	virtual void SetVersion(const WString& value);
/**
* Get string attribute Version
* @return WString the vaue of the attribute 
*/
	virtual WString GetVersion() const;
/**
* Typesafe attribute validation of Version
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidVersion(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element CustomerInfo
* 
* @return JDFCustomerInfo The element
*/
	JDFCustomerInfo GetCreateCustomerInfo();

/**
* const get element CustomerInfo
*@return  JDFCustomerInfo The element
*/
	JDFCustomerInfo GetCustomerInfo()const;
/**
* Append element CustomerInfo
 * 
*/
	JDFCustomerInfo AppendCustomerInfo();

/** Get Element NodeInfo
* 
* @return JDFNodeInfo The element
*/
	JDFNodeInfo GetCreateNodeInfo();

/**
* const get element NodeInfo
*@return  JDFNodeInfo The element
*/
	JDFNodeInfo GetNodeInfo()const;
/**
* Append element NodeInfo
 * 
*/
	JDFNodeInfo AppendNodeInfo();
/**
* create inter-resource link to refTarget
* @param JDFNodeInfo& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefNodeInfo(JDFNodeInfo& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoAncestor

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoAncestor_H_
