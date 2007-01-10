/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  08.07.2002
//
// JDFDeviceCap.h: interface for the JDFDeviceCap class. 
//
//////////////////////////////////////////////////////////////////////

 
#if !defined _JDFDeviceCap_H_
#define _JDFDeviceCap_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "AutoJDF/JDFAutoDeviceCap.h"
#include "JDFDoc.h"
#include "JDFNode.h"
#include "JDFElement.h"
#include "JDFResourceLinkPool.h"
#include "JDFResourcePool.h"
#include "JDFDevCaps.h"
#include "JDFDevCapPool.h"
#include "JDFModulePool.h"
#include "JDFDevCap.h"

namespace JDF{
	class JDFModulePool;
	class JDFDevCapPool;
/*
*********************************************************************
class JDFDeviceCap : public JDFAutoDeviceCap

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFDeviceCap 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFDeviceCap : public JDFAutoDeviceCap{

public:
	

// Constructors / Destructors  


/**
* null ctor
*/
	inline JDFDeviceCap():JDFAutoDeviceCap(){};
/**
* copy ctor
*/
	inline JDFDeviceCap(const KElement & other):JDFAutoDeviceCap(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFDeviceCap &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFDeviceCap(){};


	/**
	* definition of the optional elements in the JDF namespace
	*/
	virtual WString OptionalElements()const;

	/**
	* typesafe validator utility
	* @param EnumValidationLevel level validation level
	* @param bool bIgnorePrivate ignore objects in foreign namespaces
	* @param int nMax size of the returned vector
	* @return vWString vector of invalid element names
	*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		

	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	/** 
	* Gets element DevCapPool
	* @return JDFDevCapPool - the element
	*/
	JDFDevCapPool GetCreateDevCapPool();
	
	/**
	* Gets element DevCapPool
	* @return JDFDevCapPool - the element
	*/
	JDFDevCapPool GetDevCapPool()const;
	
	/**
	* Appends element DevCapPool
	* @return JDFDevCapPool - the element
	*/
	JDFDevCapPool AppendDevCapPool();
	
	/** 
	* Gets element ModulePool
	* @return JDFModulePool - the element
	*/
	JDFModulePool GetCreateModulePool();
	
	/**
	* Gets element ModulePool
	* @return JDFModulePool - the element
	*/
	JDFModulePool GetModulePool()const;
	
	/**
	* Appends element ModulePool
	* @return JDFModulePool - the element
	*/
	JDFModulePool AppendModulePool();
		

	/* ******************************************************
	// Attribute Getter / Setter
	**************************************************************** */

	/**
	* Gets of this string attribute TypeExpression if it exists,
	* otherwise returns the literal string defined in Types
	*
	* @return WString: TypeExpression attribute value
	*/
	WString GetTypeExpression() const;


	/* ******************************************************
	// Implementation of the DeviceCapabilities logic
	**************************************************************** */

	/**
	* Gets of jdfRoot a vector of all executable nodes  
	* (jdf root or children nodes - that this Device may execute)
	*
	* @param JDFNode& jdfRoot: the node we test
	* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists,
	* that are specified for State elements. Will be used in FitsValue method of the State element
	* @param EnumValidationLevel level: validation level
	* @return vElement: vector of executable JDFNodes
	*/
	vElement GetExecutableJDF(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const; 

	/**
	* For the given JDFNode 'jdfRoot' composes a BugReport in XML form. 
    * For 'jdfRoot' and every child rejected Node gives a list of error messages
	*
	* @param JDFNode& jdfRoot: the node we test
	* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists,
	* that are specified for the State elements. (Will be used in fitsValue method of the State element)
	* @param EnumValidationLevel level: validation level
	* @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors
	*/
	XMLDoc GetBadJDFInfo(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const;

private:
	/**
    * Checks if Device can execute the given JDFNode 'jdfRoot'.
    * First validates 'jdfRoot' and checks if its Type/Types attributes  
    * fit the values of DeviceCap/@Types and DeviceCap/@CombinedMethod.
    * If Node is invalid or Type/Types don't fit - doesn't check it more detailed.
    * If Type/Types fit, tests a whole JDFNode - all elements and attributes - to define if Device can accept it.
    * Composes a detailed report in XML form of the found errors if JDFNode was rejected.
    * If XMLDoc equals null - there are no errors and 'jdfRoot' is accepted
    * 
	* @param JDFNode& jdfRoot: the node we test
	* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists,
	* that are specified for the State elements. (Will be used in fitsValue method of the State element)
	* @param EnumValidationLevel level: validation level
    * @return XMLDoc: XMLDoc output of the error messages.
    * If XMLDoc equals null - there are no errors, 'jdfRoot' is accepted
    * 
    * @throws JDFException if DeviceCapabilities file is invalid: illegal value of Types(TypeExpression) attribute
    * (if CombinedMethod is None and Types contains more than 1 process)
    * @throws JDFException if DeviceCapabilities file is invalid: illegal value of CombinedMethod attribute
    */
	XMLDoc Report(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const;

	/**
    * Checks if Device can execute the given Product JDFNode 'jdfRoot' (JDFNode/@Type=Product) .
    * If JDFNode/@Types fits DeviceCap/@Types tests a whole JDFNode and all children Product Nodes 
    * to define if Device can accept it.
    * Composes a detailed report in XML form of the found errors if JDFNode is rejected.   
    *
    * @param JDFNode& jdfRoot: the node we test
    * @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists
    * that are specified for State elements. Will be used in FitsValue method of the State element
    * @param EnumValidationLevel level: validation level
    * 
    * @return XMLDoc: XMLDoc output of the error messages. 
    * If XMLDoc equals null - there are no errors, 'jdfRoot' is accepted
    */
	XMLDoc ProductReport(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const;

	/**
	* Checks if Device can execute the given Combined JDFNode 'jdfRoot' (JDFNode/@Type=Combined).
	* If JDFNode/@Types fits DeviceCap/@Types tests a whole JDFNode - all elements and attributes 
	* to define if Device can accept it.
    * Composes a detailed report in XML form of the found errors if JDFNode is rejected. 
	*
	* @param JDFNode& jdfRoot: the node we test
	* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists,
	* that are specified for the State elements (Will be used in FitsValue method of the State element)
	* @param EnumValidationLevel level: validation level
	* @return XMLDoc: XMLDoc output of the error messages. 
    * If XMLDoc equals null - there are no errors, 'jdfRoot' is accepted 
	*/
	XMLDoc CombinedNodeReport(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const;
	
	/**
	* Checks if Device can execute the given ProcessGroup JDFNode 'jdfRoot' (JDFNode/@Type=ProcessGroup).
	* If JDFNode/@Types fits DeviceCap/@Types tests a whole JDFNode - all elements and attributes 
	* to define if Device can accept it.
    * Composes a detailed report in XML form of the found errors if JDFNode is rejected.  
	*
	* @param JDFNode& jdfRoot: the node we test
	* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists,
	* that are specified for the State elements. (Will be used in FitsValue method of the State element)
	* @param EnumValidationLevel level: validation level
	* @return XMLDoc: XMLDoc output of the error messages. 
    * If XMLDoc equals null - there are no errors, 'jdfRoot' is accepted 
	*/
	XMLDoc ProcessGroupReport(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level) const;
	
	/**
	* Tests JDFNode/@Types (or equivalent of Types in the ProcessGroupNodes - 
	* the concatenated string of all Type attributes in the children Nodes) 
	* to define if it matches DeviceCap/@Types or DeviceCap/@TypeExpression   
	*
	* @param vWstring& typesNode: attribute Types of the tested JDFNode
	* @return bool: true if JDFNode/@Types fits DeviceCap/@Types or @TypeExpression 
	* @throws JDFException if DeviceCap is invalid: both @Types and @TypeExpression are missing
	*/
	bool FitsTypes(const vWString& typesNode) const;


	/**
	* Gets the vector of string Type/Types attribute values of the given JDFNode
	*
	* @param JDFNode jdfRoot: the ProcessGroup JDFNode
	* @return vWString: vector of Type/Types attributes of the tested ProcessGroup JDFNode
	* @throws JDFException if the testen JDFNode has illegal combination of attribute 'Types' and child JDFNodes
	*/
	vWString GetProcessGroupTypeVector(const JDFNode& jdfRoot) const;

	
	/**
	* Tests if there are in the JDFNode any Resources or NodeInfo/CustomerInfo elements 
	* that are not described by DevCaps.
    * If missing DevCaps are found it means that Node has unknown for this Devide resources or elements.
    * Composes a detailed report of the found errors in XML form. If XMLDoc equals null - there are no errors
	* 
	* @param JDFNode jdfRoot: node we test
	* @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors 
	*/
	XMLDoc MissingDevCaps(const JDFNode& jdfRoot)const;

	
	/**
	* For every DevCaps element that DeviceCap consists of, 
	* looks for appropriate elements in JDFNode and tests them.
    * Composes a detailed report of the found errors in XML form. 
    * If XMLDoc equals null - there are no errors 
	* 
	* @param JDFNode& jdfRoot: the node we test
	* @param EnumFitsValue testlists: FitsValue_Allowed or FitsValue_Present testlists,
	* that are specified for the State elements. (Will be used in FitsValue method of the State element)
	* @param EnumValidationLevel level: element validation level
	* @return XMLDoc: XMLDoc output of the error messages. 
    * If XMLDoc equals null - there are no errors, 'jdfRoot' is accepted 
	*/
	XMLDoc DevCapsReport(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level)const;


	/**
    * Tests if there are in the JDFNode any invalid or missing Resources or NodeInfo/CustomerInfo elements. 
	* Composes a detailed report of the found errors in XML form. If XMLDoc equals null - there are no errors
    * 
    * @param JDFNode& jdfRoot: node we test
    * @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors
    * @throws JDFException if DeviceCap is invalid: has a wrong attribute Context value 
    */
	XMLDoc InvalidDevCaps(const JDFNode& jdfRoot, EnumFitsValue testlists, EnumValidationLevel level)const;

	
	/**
	* Tests if the JDFNode fits Actions from ActionPool of this DeviceCap
    * Composes a detailed report of the found errors in XML form. 
	* If XMLDoc equals null - there are no errors 
	*
	* @param JDFNode& jdfRoot: the node we test
	* @return XMLDoc: XMLDoc output of the error messages. If XMLDoc equals null - there are no errors,
	* JDFNode fits ActionPool of this DeviceCap and will be accepted by Device
    * @throws JDFException if DeviceCap is invalid: ActionPool refers to the non-existent TestPool
    * @throws JDFException if DeviceCap is invalid: Action refers to the non-existent Test
	*/
	XMLDoc ActionPoolReport(const JDFNode& jdfRoot) const;

	/**
    * Moves ChildElementVector of the second element into the first
    * 
    * @param KElement moveToElement: the first element - new parent for the children of the second element
    * @param KElement moveFromElement:  the second element - element whose children will be removed
    */
	static void MoveChildElementVector(KElement moveToElement, KElement moveFromElement);
	

}; // endJDFDeviceCap

// ******************************************************
}; // end namespace JDF
#endif //_JDFDeviceCap_H_
