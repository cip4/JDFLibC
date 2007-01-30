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

 
#if !defined _JDFAutoQueueEntry_H_
#define _JDFAutoQueueEntry_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFJobPhase;
class JDFPart;
class JDFPreview;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoQueueEntry : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoQueueEntry class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFQueueEntry should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoQueueEntry : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoQueueEntry():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoQueueEntry(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoQueueEntry &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoQueueEntry(){};
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
* Enumeration for attribute Status
*/

	enum EnumStatus{Status_Unknown,Status_Running,Status_Waiting,Status_Held,Status_Removed,Status_Suspended,Status_PendingReturn,Status_Completed,Status_Aborted};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

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
* Set attribute EndTime
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetEndTime(JDFDate value=JDFDate());
/**
* Get string attribute EndTime
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetEndTime() const;
/**
* Typesafe attribute validation of EndTime
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidEndTime(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute GangName
*@param WString value: the value to set the attribute to
*/
	virtual void SetGangName(const WString& value);
/**
* Get string attribute GangName
* @return WString the vaue of the attribute 
*/
	virtual WString GetGangName() const;
/**
* Typesafe attribute validation of GangName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidGangName(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	virtual void SetPriority(int value);
/**
* Get integer attribute Priority
* @return int the vaue of the attribute ; defaults to 1
*/
	virtual int GetPriority() const;
/**
* Typesafe attribute validation of Priority
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPriority(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Enumeration strings for Status
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& StatusString();
/**
* Enumeration string for enum value
* @param EnumStatus value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString StatusString(EnumStatus value);
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
* Set attribute StartTime
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetStartTime(JDFDate value=JDFDate());
/**
* Get string attribute StartTime
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetStartTime() const;
/**
* Typesafe attribute validation of StartTime
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidStartTime(EnumValidationLevel level=ValidationLevel_Complete) const;
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


/** Get Element JobPhase
* 
* @return JDFJobPhase The element
*/
	JDFJobPhase GetCreateJobPhase();

/**
* const get element JobPhase
*@return  JDFJobPhase The element
*/
	JDFJobPhase GetJobPhase()const;
/**
* Append element JobPhase
 * 
*/
	JDFJobPhase AppendJobPhase();

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

/** Get Element Preview
* 
* @param int iSkip number of elements to skip
* @return JDFPreview The element
*/
	JDFPreview GetCreatePreview(int iSkip=0);

/**
* const get element Preview
* @param int iSkip number of elements to skip
* @return JDFPreview The element
*/
	JDFPreview GetPreview(int iSkip=0)const;
/**
* Append element Preview
 */
	JDFPreview AppendPreview();
/**
* create inter-resource link to refTarget
* @param JDFPreview& refTarget the element that is referenced
*@return JDFRefElement the referenced element
*/
	JDFRefElement RefPreview(JDFPreview& refTarget);

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoQueueEntry

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoQueueEntry_H_
