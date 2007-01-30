/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001 The International Cooperation for the Integration of 
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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created 110202
// 260602 RP OptionalAttributes() added list of attributes that are NOT inherited from JDFResourceLink
//
// JDFPartAmount.h: interface for the JDFPartAmount class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFPartAmount_H___)
#define _JDFPartAmount_H___

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


#include "JDFResourceLink.h"

namespace JDF{
/**
* defines a PartAmount element in the AmountPool
* since PartAmount massively inherits from resourceLink
*

	*/
	class JDF_WRAPPERCORE_EXPORT JDFPartAmount : public JDFResourceLink{
	public:
		
	/**
	* empty ctor	
		*/
		inline JDFPartAmount():JDFResourceLink(){};
		
		/**
		* copy ctor
		*/
		inline JDFPartAmount(const KElement& other):JDFResourceLink(){
			*this=other;
		};
		
		/**
		* copy equivalance operator
		*/
		JDFPartAmount &operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFPartAmount(){};
		
		/**
		* default validator
		* @param EnumValidationLevel ValidationLevel to validate at
		* @return bool true if valid
		*/
		virtual bool IsValid(EnumValidationLevel level=ValidationLevel_Complete)const;
		/**
		* typesafe validator utility - list of valid node names for this class 
		* @return WString& comma separated list of valid node names
		*/		
		virtual WString ValidNodeNames()const;
		/**
		* Checks if the node is abstract, i.e. is not completely described
		* utility used by GetUnknownElements, GetUnknownAttributes
		* @return boolean: true, if the node is abstract
		*/
		virtual bool IsAbstract()const;

		/**
		* definition of optional attributes in the JDF namespace
		* @return WString Comma separated list of optional attributes
		*/
		virtual WString OptionalAttributes()const;

		/**
		* definition of required attributes in the JDF namespace
		* @return WString Comma separated list of required attributes
		*/
		virtual WString RequiredAttributes()const;

		/**
		* definition of optional elements in the JDF namespace
		* @return WString Comma separated list of required elements
		*/
		virtual WString OptionalElements()const;

		/**
		* definition of required elements in the JDF namespace
		* @return WString Comma separated list of required elements
		*/
		virtual WString RequiredElements()const;
		/**
		* typesafe validator
		* @param EnumValidationLevel level level of validation
		* @param bool bIgnorePrivate should foreign namesoaces be ignored
		* @param in nMax maximum number of invalid elements to return 
		* @return vWString vector of WString names of invaliud elements
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;


		/**
		* Typesafe attribute validation of rRef
		* @return true if rRef is valid
		*/
		bool ValidrRef(EnumValidationLevel level=ValidationLevel_Complete) const;
		/** 
		* Typesafe attribute validation of Usage
		* @return true if Usage is valid
		*/
		bool ValidUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
		/**
		* Typesafe attribute validation of ProcessUsage
		* @return true if ProcessUsage is valid
		*/
		bool ValidProcessUsage(EnumValidationLevel level=ValidationLevel_Complete) const;
		/** 
		* Typesafe attribute validation of rSubRef
		* @return true if rSubRef is valid
		*/
		bool ValidrSubRef(EnumValidationLevel level=ValidationLevel_Complete) const;
		/**
		* Typesafe attribute validation of PipeProtocol
		* @return true if PipeProtocol is valid
		*/
		bool ValidPipeProtocol(EnumValidationLevel level=ValidationLevel_Complete) const;
		/** 
		* Typesafe attribute validation of PipePartIDKeys
		* @return true if PipePartIDKeys is valid
		*/
		bool ValidPipePartIDKeys(EnumValidationLevel level=ValidationLevel_Complete) const;
		/**
		* Typesafe attribute validation of CombinedProcessType
		* @return true if CombinedProcessType is valid
		*/
		bool ValidCombinedProcessType(EnumValidationLevel level=ValidationLevel_Complete) const;
		/** 
		* Typesafe attribute validation of CombinedProcessIndex
		* @return true if CombinedProcessIndex is valid
		*/
		bool ValidCombinedProcessIndex(EnumValidationLevel level=ValidationLevel_Complete) const;

		/**
		* gets part map 
		*
		* @return mAttribute, of the part element
		*/
		mAttribute GetPartMap()const;

	private:
		/**
		* @TBD list of ResourceLink member functions that are invalid for PartAmounts
		*/
		vmAttribute GetPartMapVector()const;
		

	};
};

#endif // !defined(_JDFPartAmount_H___)
