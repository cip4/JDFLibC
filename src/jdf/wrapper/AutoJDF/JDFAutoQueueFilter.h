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

 
#if !defined _JDFAutoQueueFilter_H_
#define _JDFAutoQueueFilter_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFQueueEntryDef;
class JDFDevice;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoQueueFilter : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoQueueFilter class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFQueueFilter should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoQueueFilter : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoQueueFilter():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoQueueFilter(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoQueueFilter &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoQueueFilter(){};
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
* Enumeration for attribute QueueEntryDetails
*/

	enum EnumQueueEntryDetails{QueueEntryDetails_Unknown,QueueEntryDetails_None,QueueEntryDetails_Brief,QueueEntryDetails_JobPhase,QueueEntryDetails_JDF,QueueEntryDetails_Full};
/**
* Enumeration for attribute StatusList
*/

	enum EnumStatusList{StatusList_Unknown,StatusList_Running,StatusList_Waiting,StatusList_Held,StatusList_Removed,StatusList_Suspended,StatusList_PendingReturn,StatusList_Completed,StatusList_Aborted};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute GangNames
*@param vWString value: the value to set the attribute to
*/
	virtual void SetGangNames(const vWString& value);
/**
* Get string attribute GangNames
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetGangNames() const;
/**
* Typesafe attribute validation of GangNames
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGangNames(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxEntries
*@param int value: the value to set the attribute to
*/
	virtual void SetMaxEntries(int value);
/**
* Get integer attribute MaxEntries
* @return int the vaue of the attribute 
*/
	virtual int GetMaxEntries() const;
/**
* Typesafe attribute validation of MaxEntries
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxEntries(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute OlderThan
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetOlderThan(JDFDate value=JDFDate());
/**
* Get string attribute OlderThan
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetOlderThan() const;
/**
* Typesafe attribute validation of OlderThan
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidOlderThan(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute NewerThan
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetNewerThan(JDFDate value=JDFDate());
/**
* Get string attribute NewerThan
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetNewerThan() const;
/**
* Typesafe attribute validation of NewerThan
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidNewerThan(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for QueueEntryDetails
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& QueueEntryDetailsString();
/**
* Enumeration string for enum value
* @param EnumQueueEntryDetails value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString QueueEntryDetailsString(EnumQueueEntryDetails value);
/**
* Set attribute QueueEntryDetails
* @param EnumQueueEntryDetails value the value to set the attribute to
*/
	virtual void SetQueueEntryDetails( EnumQueueEntryDetails value);

/**
* Typesafe enumerated attribute QueueEntryDetails; defaults to Brief
* @return EnumQueueEntryDetailsthe enumeration value of the attribute
*/
	virtual EnumQueueEntryDetails GetQueueEntryDetails() const;

/**
* Typesafe attribute validation of QueueEntryDetails
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidQueueEntryDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for StatusList
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StatusListString();
/**
* Enumeration string for enum value
* @param EnumStatusList value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StatusListString(EnumStatusList value);
/**
* Append value to the attribute StatusList
* @param EnumStatusList value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddStatusList( EnumStatusList value);
/**
* Remove value from the attribute StatusList
* @param EnumStatusList value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveStatusList( EnumStatusList value);
/**
* Typesafe enumerated attribute StatusList
* @return EnumStatusListthe enumeration value of the attribute
*/
	virtual vint GetStatusList() const;
/**
* Set value of the attribute StatusList
* @param EnumStatusList value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetStatusList( EnumStatusList value);
/**
* Set value of the attribute StatusList to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetStatusList( const vint& value);
/**
* Typesafe attribute validation of StatusList
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStatusList(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element QueueEntryDef
* 
* @param int iSkip number of elements to skip
* @return JDFQueueEntryDef The element
*/
	JDFQueueEntryDef GetCreateQueueEntryDef(int iSkip=0);

/**
* const get element QueueEntryDef
* @param int iSkip number of elements to skip
* @return JDFQueueEntryDef The element
*/
	JDFQueueEntryDef GetQueueEntryDef(int iSkip=0)const;
/**
* Append element QueueEntryDef
 */
	JDFQueueEntryDef AppendQueueEntryDef();

/** Get Element Device
* 
* @param int iSkip number of elements to skip
* @return JDFDevice The element
*/
	JDFDevice GetCreateDevice(int iSkip=0);

/**
* const get element Device
* @param int iSkip number of elements to skip
* @return JDFDevice The element
*/
	JDFDevice GetDevice(int iSkip=0)const;
/**
* Append element Device
 */
	JDFDevice AppendDevice();
/**
* create inter-resource link to refTarget
* @param JDFDevice& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefDevice(JDFDevice& refTarget);

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoQueueFilter

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoQueueFilter_H_
