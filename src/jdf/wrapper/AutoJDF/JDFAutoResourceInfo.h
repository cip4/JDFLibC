/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoResourceInfo_H_
#define _JDFAutoResourceInfo_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/JDFResource.h"
namespace JDF{
class JDFAmountPool;
class JDFCostCenter;
class JDFLot;
class JDFMISDetails;
class JDFPart;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoResourceInfo : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoResourceInfo class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFResourceInfo should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoResourceInfo : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoResourceInfo():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoResourceInfo(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoResourceInfo &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoResourceInfo(){};
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
* Enumeration for attribute CommandResult
*/

	enum EnumCommandResult{CommandResult_Unknown,CommandResult_Rejected,CommandResult_Removed,CommandResult_New,CommandResult_Merged,CommandResult_Replaced};
/**
* Enumeration for attribute Level
*/

	enum EnumLevel{Level_Unknown,Level_Empty,Level_Low,Level_OK};
/**
* Enumeration for attribute Usage
*/

	enum EnumUsage{Usage_Unknown,Usage_Input,Usage_Output};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute ActualAmount
*@param double value: the value to set the attribute to
*/
	virtual void SetActualAmount(double value);
/**
* Get double attribute ActualAmount
* @return double the vaue of the attribute 
*/
	virtual double GetActualAmount() const;
/**
* Typesafe attribute validation of ActualAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidActualAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Amount
*@param double value: the value to set the attribute to
*/
	virtual void SetAmount(double value);
/**
* Get double attribute Amount
* @return double the vaue of the attribute 
*/
	virtual double GetAmount() const;
/**
* Typesafe attribute validation of Amount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AvailableAmount
*@param double value: the value to set the attribute to
*/
	virtual void SetAvailableAmount(double value);
/**
* Get double attribute AvailableAmount
* @return double the vaue of the attribute 
*/
	virtual double GetAvailableAmount() const;
/**
* Typesafe attribute validation of AvailableAmount
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAvailableAmount(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for CommandResult
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CommandResultString();
/**
* Enumeration string for enum value
* @param EnumCommandResult value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CommandResultString(EnumCommandResult value);
/**
* Set attribute CommandResult
* @param EnumCommandResult value the value to set the attribute to
*/
	virtual void SetCommandResult( EnumCommandResult value);

/**
* Typesafe enumerated attribute CommandResult
* @return EnumCommandResultthe enumeration value of the attribute
*/
	virtual EnumCommandResult GetCommandResult() const;

/**
* Typesafe attribute validation of CommandResult
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCommandResult(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Level
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& LevelString();
/**
* Enumeration string for enum value
* @param EnumLevel value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString LevelString(EnumLevel value);
/**
* Set attribute Level
* @param EnumLevel value the value to set the attribute to
*/
	virtual void SetLevel( EnumLevel value);

/**
* Typesafe enumerated attribute Level
* @return EnumLevelthe enumeration value of the attribute
*/
	virtual EnumLevel GetLevel() const;

/**
* Typesafe attribute validation of Level
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidLevel(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Location
*@param WString value: the value to set the attribute to
*/
	virtual void SetLocation(const WString& value);
/**
* Get string attribute Location
* @return WString the vaue of the attribute 
*/
	virtual WString GetLocation() const;
/**
* Typesafe attribute validation of Location
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLocation(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute LotControlled
*@param bool value: the value to set the attribute to
*/
	virtual void SetLotControlled(bool value);
/**
* Get bool attribute LotControlled
* @return bool the vaue of the attribute 
*/
	virtual bool GetLotControlled() const;
/**
* Typesafe attribute validation of LotControlled
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLotControlled(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleID
*@param WString value: the value to set the attribute to
*/
	virtual void SetModuleID(const WString& value);
/**
* Get string attribute ModuleID
* @return WString the vaue of the attribute 
*/
	virtual WString GetModuleID() const;
/**
* Typesafe attribute validation of ModuleID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ModuleIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	virtual void SetModuleIndex(const JDFIntegerRangeList& value);
/**
* Get range attribute ModuleIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	virtual JDFIntegerRangeList GetModuleIndex() const;
/**
* Typesafe attribute validation of ModuleIndex
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidModuleIndex(EnumValidationLevel level=ValidationLevel_Complete) const;
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
* Set attribute Status
* @param JDFResource::EnumStatus value the value to set the attribute to
*/
	virtual void SetStatus( JDFResource::EnumStatus value);

/**
* Typesafe enumerated attribute Status
* @return EnumStatusthe enumeration value of the attribute
*/
	virtual JDFResource::EnumStatus GetStatus() const;

/**
* Typesafe attribute validation of Status
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidStatus(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Unit
*@param WString value: the value to set the attribute to
*/
	virtual void SetUnit(const WString& value);
/**
* Get string attribute Unit
* @return WString the vaue of the attribute 
*/
	virtual WString GetUnit() const;
/**
* Typesafe attribute validation of Unit
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidUnit(EnumValidationLevel level=ValidationLevel_Complete) const;
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


/** Get Element AmountPool
* 
* @return JDFAmountPool The element
*/
	JDFAmountPool GetCreateAmountPool();

/**
* const get element AmountPool
*@return  JDFAmountPool The element
*/
	JDFAmountPool GetAmountPool()const;
/**
* Append element AmountPool
 * 
*/
	JDFAmountPool AppendAmountPool();

/** Get Element CostCenter
* 
* @return JDFCostCenter The element
*/
	JDFCostCenter GetCreateCostCenter();

/**
* const get element CostCenter
*@return  JDFCostCenter The element
*/
	JDFCostCenter GetCostCenter()const;
/**
* Append element CostCenter
 * 
*/
	JDFCostCenter AppendCostCenter();

/** Get Element Lot
* 
* @param int iSkip number of elements to skip
* @return JDFLot The element
*/
	JDFLot GetCreateLot(int iSkip=0);

/**
* const get element Lot
* @param int iSkip number of elements to skip
* @return JDFLot The element
*/
	JDFLot GetLot(int iSkip=0)const;
/**
* Append element Lot
 */
	JDFLot AppendLot();

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
 definition of unique elements in the JDF namespace
*/
	virtual WString UniqueElements()const;

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoResourceInfo

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoResourceInfo_H_
