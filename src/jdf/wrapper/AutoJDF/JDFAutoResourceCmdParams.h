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

 
#if !defined _JDFAutoResourceCmdParams_H_
#define _JDFAutoResourceCmdParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFPart;
class JDFMISDetails;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoResourceCmdParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoResourceCmdParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFResourceCmdParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoResourceCmdParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoResourceCmdParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoResourceCmdParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoResourceCmdParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoResourceCmdParams(){};
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

	enum EnumActivation{Activation_Unknown,Activation_Held,Activation_Active,Activation_TestRun,Activation_TestRunAndGo};
/**
* Enumeration for attribute UpdateMethod
*/

	enum EnumUpdateMethod{UpdateMethod_Unknown,UpdateMethod_Complete,UpdateMethod_Incremental,UpdateMethod_Remove};
/**
* Enumeration for attribute Usage
*/

	enum EnumUsage{Usage_Unknown,Usage_Input,Usage_Output};

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
* Typesafe enumerated attribute Activation; defaults to Active
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
* Set attribute ProductionAmount
*@param double value: the value to set the attribute to
*/
	virtual void SetProductionAmount(double value);
/**
* Get double attribute ProductionAmount
* @return double the vaue of the attribute 
*/
	virtual double GetProductionAmount() const;
/**
* Typesafe attribute validation of ProductionAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidProductionAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute ResourceName
*@param WString value: the value to set the attribute to
*/
	virtual void SetResourceName(const WString& value);
/**
* Get string attribute ResourceName
* @return WString the vaue of the attribute 
*/
	virtual WString GetResourceName() const;
/**
* Typesafe attribute validation of ResourceName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResourceName(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute UpdateIDs
*@param vWString value: the value to set the attribute to
*/
	virtual void SetUpdateIDs(const vWString& value);
/**
* Get string attribute UpdateIDs
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetUpdateIDs() const;
/**
* Typesafe attribute validation of UpdateIDs
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUpdateIDs(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for UpdateMethod
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& UpdateMethodString();
/**
* Enumeration string for enum value
* @param EnumUpdateMethod value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString UpdateMethodString(EnumUpdateMethod value);
/**
* Set attribute UpdateMethod
* @param EnumUpdateMethod value the value to set the attribute to
*/
	virtual void SetUpdateMethod( EnumUpdateMethod value);

/**
* Typesafe enumerated attribute UpdateMethod; defaults to Complete
* @return EnumUpdateMethodthe enumeration value of the attribute
*/
	virtual EnumUpdateMethod GetUpdateMethod() const;

/**
* Typesafe attribute validation of UpdateMethod
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidUpdateMethod(EnumValidationLevel level=ValidationLevel_Complete) const;
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

/**
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoResourceCmdParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoResourceCmdParams_H_
