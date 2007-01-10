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

 
#if !defined _JDFAutoDevCaps_H_
#define _JDFAutoDevCaps_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFDevCap;
class JDFLoc;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoDevCaps : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoDevCaps class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFDevCaps should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoDevCaps : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoDevCaps():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoDevCaps(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoDevCaps &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoDevCaps(){};
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
* Enumeration for attribute Availability
*/

	enum EnumAvailability{Availability_Unknown,Availability_Installed,Availability_Module,Availability_NotInstalled,Availability_NotLicensed,Availability_Disabled};
/**
* Enumeration for attribute Context
*/

	enum EnumContext{Context_Unknown,Context_Resource,Context_Link,Context_JMF};
/**
* Enumeration for attribute LinkUsage
*/

	enum EnumLinkUsage{LinkUsage_Unknown,LinkUsage_Input,LinkUsage_Output};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for Availability
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& AvailabilityString();
/**
* Enumeration string for enum value
* @param EnumAvailability value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString AvailabilityString(EnumAvailability value);
/**
* Set attribute Availability
* @param EnumAvailability value the value to set the attribute to
*/
	virtual void SetAvailability( EnumAvailability value);

/**
* Typesafe enumerated attribute Availability; defaults to Installed
* @return EnumAvailabilitythe enumeration value of the attribute
*/
	virtual EnumAvailability GetAvailability() const;

/**
* Typesafe attribute validation of Availability
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidAvailability(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Context
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ContextString();
/**
* Enumeration string for enum value
* @param EnumContext value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ContextString(EnumContext value);
/**
* Set attribute Context
* @param EnumContext value the value to set the attribute to
*/
	virtual void SetContext( EnumContext value);

/**
* Typesafe enumerated attribute Context; defaults to Resource
* @return EnumContextthe enumeration value of the attribute
*/
	virtual EnumContext GetContext() const;

/**
* Typesafe attribute validation of Context
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidContext(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DevCapRef
*@param WString value: the value to set the attribute to
*/
	virtual void SetDevCapRef(const WString& value);
/**
* Get string attribute DevCapRef
* @return WString the vaue of the attribute 
*/
	virtual WString GetDevCapRef() const;
/**
* Typesafe attribute validation of DevCapRef
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDevCapRef(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DevNS
*@param WString value: the value to set the attribute to
*/
	virtual void SetDevNS(const WString& value);
/**
* Get string attribute DevNS
* @return WString the vaue of the attribute ; defaults to http://www.CIP4.org/JDFSchema_1_1
*/
	virtual WString GetDevNS() const;
/**
* Typesafe attribute validation of DevNS
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDevNS(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	virtual void SetID(const WString& value);
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	virtual WString GetID() const;
/**
* Typesafe attribute validation of ID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for LinkUsage
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& LinkUsageString();
/**
* Enumeration string for enum value
* @param EnumLinkUsage value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString LinkUsageString(EnumLinkUsage value);
/**
* Set attribute LinkUsage
* @param EnumLinkUsage value the value to set the attribute to
*/
	virtual void SetLinkUsage( EnumLinkUsage value);

/**
* Typesafe enumerated attribute LinkUsage
* @return EnumLinkUsagethe enumeration value of the attribute
*/
	virtual EnumLinkUsage GetLinkUsage() const;

/**
* Typesafe attribute validation of LinkUsage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidLinkUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleRefs
*@param vWString value: the value to set the attribute to
*/
	virtual void SetModuleRefs(const vWString& value);
/**
* Get string attribute ModuleRefs
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetModuleRefs() const;
/**
* Typesafe attribute validation of ModuleRefs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleRefs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	virtual void SetName(const WString& value);
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	virtual WString GetName() const;
/**
* Typesafe attribute validation of Name
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ProcessUsage
*@param WString value: the value to set the attribute to
*/
	virtual void SetProcessUsage(const WString& value);
/**
* Get string attribute ProcessUsage
* @return WString the vaue of the attribute 
*/
	virtual WString GetProcessUsage() const;
/**
* Typesafe attribute validation of ProcessUsage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProcessUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Required
*@param bool value: the value to set the attribute to
*/
	virtual void SetRequired(bool value);
/**
* Get bool attribute Required
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetRequired() const;
/**
* Typesafe attribute validation of Required
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidRequired(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ResourceUpdate
*@param vWString value: the value to set the attribute to
*/
	virtual void SetResourceUpdate(const vWString& value);
/**
* Get string attribute ResourceUpdate
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetResourceUpdate() const;
/**
* Typesafe attribute validation of ResourceUpdate
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResourceUpdate(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ResourceUsage
*@param WString value: the value to set the attribute to
*/
	virtual void SetResourceUsage(const WString& value);
/**
* Get string attribute ResourceUsage
* @return WString the vaue of the attribute 
*/
	virtual WString GetResourceUsage() const;
/**
* Typesafe attribute validation of ResourceUsage
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResourceUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TypeOccurrenceNum
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetTypeOccurrenceNum(const JDFIntegerRangeList& value);
/**
* Get range attribute TypeOccurrenceNum
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetTypeOccurrenceNum() const;
/**
* Typesafe attribute validation of TypeOccurrenceNum
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTypeOccurrenceNum(EnumValidationLevel level=ValidationLevel_Complete) const;
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

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element DevCap
* 
* @param int iSkip number of elements to skip
* @return JDFDevCap The element
*/
	JDFDevCap GetCreateDevCap(int iSkip=0);

/**
* const get element DevCap
* @param int iSkip number of elements to skip
* @return JDFDevCap The element
*/
	JDFDevCap GetDevCap(int iSkip=0)const;
/**
* Append element DevCap
 */
	JDFDevCap AppendDevCap();

/** Get Element Loc
* 
* @param int iSkip number of elements to skip
* @return JDFLoc The element
*/
	JDFLoc GetCreateLoc(int iSkip=0);

/**
* const get element Loc
* @param int iSkip number of elements to skip
* @return JDFLoc The element
*/
	JDFLoc GetLoc(int iSkip=0)const;
/**
* Append element Loc
 */
	JDFLoc AppendLoc();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoDevCaps

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoDevCaps_H_
