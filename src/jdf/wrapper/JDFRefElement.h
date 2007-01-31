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


//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi using JDFSchema code generator 
// 
// Warning! very preliminary test version. Interface subject to change without prior notice!
// Revision history:
// created 2001-02-19
//
// 150302 RP modified GetTarget to handle parts
//        RP added part handling
//        RP added OptionalElements
// 260302 RP added InlineRef
// 300402 RP modified GetTarget for parts pointing to elements that are not 
// 290502 RP added DeleteRef 
// 260602 RP added SetPartMap, SetPartMap, SetPartMap
// 050702 RP IsValid() added factory for recursive check; added call to ValidResourcePosition()
// 050702 RP added ValidResourcePosition()
// 260802 RP GetTarget() now returns null for invalid names
// 051102 RP GetLinkRoot() added
// 051102 RP modified GetTarget to use GetLinkRoot
// 051102 RP GetRefNodeName() no longer checks target bur simply name mangles
// 211102 RP InlineRef bug fix
//

#if !defined _JDFRefElement_H_
#define _JDFRefElement_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
namespace JDF{
	class JDFPart;
	
	/**
	*********************************************************************
	class JDFRefElement : public JDFAutoRefElement
	
	  *********************************************************************
	*/
	class JDF_WRAPPERCORE_EXPORT JDFRefElement : public JDFElement{
	public:
		
		
		/// Constructors / Destructors  
		
		
		/**
		* null ctor
		*/
		inline JDFRefElement():JDFElement(){};

		/**
		* copy ctor
		*/
		JDFRefElement(const KElement & other):JDFElement(){
			*this=other;
		};
		
		/**
		* copy equivalance operator
		*/
		JDFRefElement &operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFRefElement(){};
		
		/**
		* validator for ref elements
		*/
		bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;
		
		/**
		* does the resource live in the same node or an ancestor node of the link
		* @return bool true if the linked resource resides in a legal node
		*/
		bool ValidResourcePosition()const;

		/**
		* NodeName of the referenced object
		* @return WString the nodename of the referenced resource
		*/
		WString GetRefNodeName()const;
		
		/**
		* Gets the root resource of the target
		* returns a null JDFElement if it does not exist or the name mangling is illegal
		* @return JDFResource the resource root of the resource referenced by this resource link
		*/
		JDFResource GetLinkRoot()const;

		/**
		* get the referenced target if it is valid<br>
		* returns a null JDFElement if it does not exist or the name mangling is illegal
		* 
		* @return JDFElement the referenced target
		*/
		JDFElement GetTarget()const;
		
		/**
		* inline this refElement by replacing it with a copy of its target
		* @return JDFElement the newly created element
		*/ 
		JDFElement InlineRef();
		
		/**
		* delete this refElement and it's target
		* @param bool bCheckRefCount if true, check that no other element refers to the target before deleting<br>
		*	if bCheckRefCount=false, the target is force deleted
		* @return JDFElement the deleted targeelement
		* @since 290502
		*/ 
		JDFElement DeleteRef(bool bCheckRefCount=true);
				
		/**
		* definition of required attributes in the JDF namespace
		*/
		virtual WString RequiredAttributes()const;
		
		/**
		* definition of optional attributes in the JDF namespace
		*/
		virtual WString OptionalAttributes()const;
		
		/**
		* definition of optional elements in the JDF namespace
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
		
		/**
		* Set attribute rRef
		*@param WString value: the value to set the attribute to
		*/
		inline void SetrRef(WString value){
			SetAttribute(atr_rRef,value);
		};
		
		/**
		* Get string attribute rRef
		* @return WString the vaue of the attribute 
		*/
		inline WString GetrRef() const {
			return GetAttribute(atr_rRef,WString::emptyStr);
		};
		
		/**
		* Typesafe attribute validation of rRef
		* @param EnumValidationLevel level validation level
		* @return bool true if valid
		*/
		virtual bool ValidrRef(EnumValidationLevel level) const;
				
		
		/**
		* Set attribute rSubRef
		*@param WString value: the value to set the attribute to
		*/
		inline void SetrSubRef(WString value){
			SetAttribute(atr_rSubRef,value);
		};
		
		/**
		* Get string attribute rSubRef
		* @return WString the vaue of the attribute 
		*/
		inline WString GetrSubRef() const {
			return GetAttribute(atr_rSubRef,WString::emptyStr);
		};
		
		/**
		* Typesafe attribute validation of rSubRef
		* @param EnumValidationLevel level validation level
		* @return bool true if valid
		*/
		virtual bool ValidrSubRef(EnumValidationLevel level) const;
		
		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;

		/** 
		* Append Element Part
		*/
		JDFPart AppendPart();

		/** 
		* Get Element Part
		* @return JDFPart The element
		*/
		JDFPart GetCreatePart();

		/**
		* const get first Part element 
		*/
		JDFPart GetPart()const;

		
		/**
		* get part map vector
		* @return mAttribute, the part map
		*/
		mAttribute GetPartMap() const;

		/**
		* set all parts to those define in vParts
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
				
	}; // endJDFRefElement
	
	// ******************************************************
}; // end namespace JDF
#endif //_JDFRefElement_H_
