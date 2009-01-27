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

 
#if !defined _JDFAutoMsgFilter_H_
#define _JDFAutoMsgFilter_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFPart;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoMsgFilter : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoMsgFilter class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFMsgFilter should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoMsgFilter : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoMsgFilter():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoMsgFilter(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoMsgFilter &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoMsgFilter(){};
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
* Enumeration for attribute Family
*/

	enum EnumFamily{Family_Unknown,Family_Acknowledge,Family_Response,Family_Signal,Family_All};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute After
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetAfter(JDFDate value=JDFDate());
/**
* Get string attribute After
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetAfter() const;
/**
* Typesafe attribute validation of After
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAfter(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Before
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetBefore(JDFDate value=JDFDate());
/**
* Get string attribute Before
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetBefore() const;
/**
* Typesafe attribute validation of Before
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBefore(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Count
*@param int value: the value to set the attribute to
*/
	virtual void SetCount(int value);
/**
* Get integer attribute Count
* @return int the vaue of the attribute 
*/
	virtual int GetCount() const;
/**
* Typesafe attribute validation of Count
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidCount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeviceID(const WString& value);
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeviceID() const;
/**
* Typesafe attribute validation of DeviceID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeviceID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Family
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& FamilyString();
/**
* Enumeration string for enum value
* @param EnumFamily value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString FamilyString(EnumFamily value);
/**
* Set attribute Family
* @param EnumFamily value the value to set the attribute to
*/
	virtual void SetFamily( EnumFamily value);

/**
* Typesafe enumerated attribute Family
* @return EnumFamilythe enumeration value of the attribute
*/
	virtual EnumFamily GetFamily() const;

/**
* Typesafe attribute validation of Family
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidFamily(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute MessageRefID
*@param WString value: the value to set the attribute to
*/
	virtual void SetMessageRefID(const WString& value);
/**
* Get string attribute MessageRefID
* @return WString the vaue of the attribute 
*/
	virtual WString GetMessageRefID() const;
/**
* Typesafe attribute validation of MessageRefID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMessageRefID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MessageID
*@param WString value: the value to set the attribute to
*/
	virtual void SetMessageID(const WString& value);
/**
* Get string attribute MessageID
* @return WString the vaue of the attribute 
*/
	virtual WString GetMessageID() const;
/**
* Typesafe attribute validation of MessageID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMessageID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MessageType
*@param WString value: the value to set the attribute to
*/
	virtual void SetMessageType(const WString& value);
/**
* Get string attribute MessageType
* @return WString the vaue of the attribute 
*/
	virtual WString GetMessageType() const;
/**
* Typesafe attribute validation of MessageType
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMessageType(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute ReceiverURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetReceiverURL(const WString& value);
/**
* Get string attribute ReceiverURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetReceiverURL() const;
/**
* Typesafe attribute validation of ReceiverURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidReceiverURL(EnumValidationLevel level=ValidationLevel_Complete) const;

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
}; // endJDFAutoMsgFilter

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoMsgFilter_H_
