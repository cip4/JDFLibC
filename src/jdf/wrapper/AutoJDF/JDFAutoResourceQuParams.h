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

 
#if !defined _JDFAutoResourceQuParams_H_
#define _JDFAutoResourceQuParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFPart;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoResourceQuParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoResourceQuParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFResourceQuParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoResourceQuParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoResourceQuParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoResourceQuParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoResourceQuParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoResourceQuParams(){};
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
* Enumeration for attribute Classes
*/

	enum EnumClasses{Classes_Unknown,Classes_Consumable,Classes_Handling,Classes_Implementation,Classes_Intent,Classes_Parameter,Classes_PlaceHolder,Classes_Quantity};
/**
* Enumeration for attribute Context
*/

	enum EnumContext{Context_Unknown,Context_Job,Context_Global};
/**
* Enumeration for attribute LotDetails
*/

	enum EnumLotDetails{LotDetails_Unknown,LotDetails_Brief,LotDetails_Full,LotDetails_Amount};
/**
* Enumeration for attribute ResourceDetails
*/

	enum EnumResourceDetails{ResourceDetails_Unknown,ResourceDetails_Brief,ResourceDetails_Full};
/**
* Enumeration for attribute Usage
*/

	enum EnumUsage{Usage_Unknown,Usage_Input,Usage_Output};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for Classes
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ClassesString();
/**
* Enumeration string for enum value
* @param EnumClasses value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ClassesString(EnumClasses value);
/**
* Append value to the attribute Classes
* @param EnumClasses value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint AddClasses( EnumClasses value);
/**
* Remove value from the attribute Classes
* @param EnumClasses value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual vint RemoveClasses( EnumClasses value);
/**
* Typesafe enumerated attribute Classes
* @return EnumClassesthe enumeration value of the attribute
*/
	virtual vint GetClasses() const;
/**
* Set value of the attribute Classes
* @param EnumClasses value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetClasses( EnumClasses value);
/**
* Set value of the attribute Classes to a list
* @param vint value the value to set the attribute to
* @return vint the vector of enumerations that are set - cast to int
*/
	virtual void SetClasses( const vint& value);
/**
* Typesafe attribute validation of Classes
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidClasses(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Typesafe enumerated attribute Context
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
* Set attribute Exact
*@param bool value: the value to set the attribute to
*/
	virtual void SetExact(bool value);
/**
* Get bool attribute Exact
* @return bool the vaue of the attribute ; defaults to false
*/
	virtual bool GetExact() const;
/**
* Typesafe attribute validation of Exact
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidExact(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Enumeration strings for LotDetails
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& LotDetailsString();
/**
* Enumeration string for enum value
* @param EnumLotDetails value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString LotDetailsString(EnumLotDetails value);
/**
* Set attribute LotDetails
* @param EnumLotDetails value the value to set the attribute to
*/
	virtual void SetLotDetails( EnumLotDetails value);

/**
* Typesafe enumerated attribute LotDetails; defaults to Brief
* @return EnumLotDetailsthe enumeration value of the attribute
*/
	virtual EnumLotDetails GetLotDetails() const;

/**
* Typesafe attribute validation of LotDetails
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidLotDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LotID
*@param WString value: the value to set the attribute to
*/
	virtual void SetLotID(const WString& value);
/**
* Get string attribute LotID
* @return WString the vaue of the attribute 
*/
	virtual WString GetLotID() const;
/**
* Typesafe attribute validation of LotID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLotID(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute ProductID
*@param WString value: the value to set the attribute to
*/
	virtual void SetProductID(const WString& value);
/**
* Get string attribute ProductID
* @return WString the vaue of the attribute 
*/
	virtual WString GetProductID() const;
/**
* Typesafe attribute validation of ProductID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProductID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	virtual void SetQueueEntryID(const WString& value);
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	virtual WString GetQueueEntryID() const;
/**
* Typesafe attribute validation of QueueEntryID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidQueueEntryID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for ResourceDetails
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ResourceDetailsString();
/**
* Enumeration string for enum value
* @param EnumResourceDetails value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ResourceDetailsString(EnumResourceDetails value);
/**
* Set attribute ResourceDetails
* @param EnumResourceDetails value the value to set the attribute to
*/
	virtual void SetResourceDetails( EnumResourceDetails value);

/**
* Typesafe enumerated attribute ResourceDetails; defaults to Full
* @return EnumResourceDetailsthe enumeration value of the attribute
*/
	virtual EnumResourceDetails GetResourceDetails() const;

/**
* Typesafe attribute validation of ResourceDetails
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidResourceDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ResourceID
*@param WString value: the value to set the attribute to
*/
	virtual void SetResourceID(const WString& value);
/**
* Get string attribute ResourceID
* @return WString the vaue of the attribute 
*/
	virtual WString GetResourceID() const;
/**
* Typesafe attribute validation of ResourceID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResourceID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ResourceName
*@param vWString value: the value to set the attribute to
*/
	virtual void SetResourceName(const vWString& value);
/**
* Get string attribute ResourceName
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetResourceName() const;
/**
* Typesafe attribute validation of ResourceName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResourceName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Usage
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& UsageString();
/**
* Enumeration string for enum value
* @param EnumUsage value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString UsageString(EnumUsage value);
/**
* Set attribute Usage
* @param EnumUsage value the value to set the attribute to
*/
	virtual void SetUsage( EnumUsage value);

/**
* Typesafe enumerated attribute Usage
* @return EnumUsagethe enumeration value of the attribute
*/
	virtual EnumUsage GetUsage() const;

/**
* Typesafe attribute validation of Usage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidUsage(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


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
}; // endJDFAutoResourceQuParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoResourceQuParams_H_
