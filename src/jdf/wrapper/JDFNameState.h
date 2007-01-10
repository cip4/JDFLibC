/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2004 The International Cooperation for the Integration of 
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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  27.01.04
//
// JDFNameState.h: interface for the JDFNameState class.
// defines the NameState attributes and subelements
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFNameState_H__)
#define _JDFNameState_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
#include "JDFState.h"
#include "JDFValueLoc.h"


namespace JDF{

	/**
	* State type for names without whitespace (NMTOKENS)
	*/
	typedef JDFState<WString> _JDFNameState;
	class JDF_WRAPPERCORE_EXPORT JDFNameState: public _JDFNameState{
	public:
	/** *****************************
	* Construction / Destruction
	******************************************** */
	//@{
		/**
		* Empty constructor
		*/
		inline JDFNameState():_JDFNameState(){};
		
		/**
		* Copy constructor
		*/
		inline JDFNameState(const KElement & other):_JDFNameState(){*this=other;};
		
		/**
		* Equivalence copy constructor
		*/
		JDFNameState&operator =(const KElement& other);
		
		/**
		* Destructor
		*/
		virtual ~JDFNameState(){};
		//@}


		/**
		* definition of optional attributes in the JDF namespace
		*
		* @return WString: list of optional attributes
		*/
		virtual WString OptionalAttributes()const;

		/**
		* typesafe validator
		*
		* @param EnumValidationLevel level: validation level
		* @param bIgnorePrivate: if true, do not worry about attributes in other namespaces
		* @param int nMax: maximum size of the returned vector
		* @return vWString: a vector of invalid attribute names
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;		

		/**
		* definition of optional attributes in the JDF namespace
		*
		* @return WString: list of optional elements
		*/
		virtual WString OptionalElements()const;
		
		/**
		* typesafe validator
		*
		* @param EnumValidationLevel level: validation level
		* @param bIgnorePrivate: if true, do not worry about elements in other namespaces
		* @param int nMax: maximum size of the returned vector
		* @return vWString: a vector of invalid element names
		*/
		virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;
		
		/**
		* typesafe validator utility - list of valid node names for this class 
		*
		* @return WString: comma separated list of valid node names
		*/
		virtual WString ValidNodeNames()const;	
		
		/**
		* Tests, if the defined value matches Allowed test lists or Present test lists,
		* specified for this State
		*
		* @param WString& value: value to test
		* @param EnumFitsValue tetlists: test lists, that the value has to match.
		* In this State the test lists are ValueList, RegExp. 
		* Choose one of two values: FitsValue_Allowed or FitsValue_Present. Defaults to Allowed
		* @return bool: true, if the value matches all test lists or if Allowed test lists are not specified
		*/
		bool FitsValue(const WString& value, EnumFitsValue valuelist=FitsValue_Allowed) const;


		/* ******************************************************
		// Attribute Getter/ Setter
		**************************************************************** */	

		//@{
		/**
		* Gets the value of attribute AllowedValueList
		*
		* @return vWString: the attribute value
		*/
		vWString GetAllowedValueList()const;

		/**
		* Sets the AllowedValueList attribute
		*
		* @param vWString& vs: value to set the attribute to
		*/
		void SetAllowedValueList(const vWString& vs);

		/**
		* Typesafe attribute validation of AllowedValueList
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedValueList(EnumValidationLevel level)const;
		//@}
		
		
		//@{
		/**
		* Gets the value of attribute PresentValueList attribute,
		* if not specified the value of AllowedValueList is applied
		*
		* @return vWString: the attribute value
		*/
		vWString GetPresentValueList()const;

		/**
		* Sets the PresentValueList attribute
		*
		* @param vWString& vs: value to set the attribute to
		*/
		void SetPresentValueList(const vWString& vs);

		/**
		* Typesafe attribute validation of PresentValueList
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentValueList(EnumValidationLevel level)const;
		//@}
		
		
		//@{
		/**
		* Gets the value of attribute AllowedRegExp 
		*
		* @return WString: the attribute value
		*/
		WString GetAllowedRegExp()const;

		/**
		* Sets the AllowedRegExp attribute
		*
		* @param WString& value: value to set the attribute to
		*/
		void SetAllowedRegExp(const WString & value);
		
		/**
		* Typesafe attribute validation of AllowedRegExp
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedRegExp(EnumValidationLevel level)const;
		//@}
		
		
		//@{
		/**
		* Gets the value of attribute PresentRegExp,
		* if not specified the value of AllowedRegExp is applied
		*
		* @return WString: the attribute value
		*/
		WString GetPresentRegExp()const;

		/**
		* Sets the PresentRegExp attribute
		*
		* @param WString& value: value to set the attribute to
		*/
		void SetPresentRegExp(const WString & value);

		/**
		* Typesafe attribute validation of PresentRegExp
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentRegExp(EnumValidationLevel level)const;
		//@}

		
		/* ******************************************************
		// Element Getter / Setter
		**************************************************************** */

		//@{
		/**
		* Gets the iSkip-th element ValueLoc
		*
		* @param int iSkip: number of elements to skip
		* @return JDFValueLoc: the matching element
		*/
		JDFValueLoc GetValueLoc(int iSkip=0)const;
		
		/**
		* Appends element ValueLoc to the end of 'this'
		*
		* @return JDFValueLoc: newly created ValueLoc element
		*/
		JDFValueLoc	AppendValueLoc();
		//@}

private:
		
		/**
		* Tests, if the defined 'value' matches value of ListType attribute,
		* specified for this State
		*
		* @param WString& value: value to test
		* @return bool: true, if 'value' matches specified value of ListType
		*/
		bool FitsListType(const WString& value) const;
		
		/**
		* Tests, if the defined string 'MyValue' matches the AllowedValueList or the PresentValueList,
		* specified for this State
		*
		* @param WString& MyValue: token to test
		* @param EnumFitsValue valuelist: Switches between AllowedValueList and PresentValueList.
		* @return bool: true, if 'MyValue' matches valuelist or if AllowedValueList is not specified
		*/
		bool FitsValueList(const WString& MyValue, EnumFitsValue valuelist) const;

		/**
		* Tests, if the defined string 'MyValue' matches AllowedRegExp or the PresentRegExp,
		* specified for this State
		*
		* @param WString& MyValue: token to test
		* @param EnumFitsValue regexp: Switches between AllowedRegExp and PresentRegExp.
		* @return bool: true, if 'MyValue' matches RegExp or if AllowedRegExp is not specified
		*/
		bool FitsRegExp(const WString& MyValue, EnumFitsValue regexp) const;

		/**
		* For the case, when ListType=CompleteList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param vWString& value: value to test
		* @param vWString& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches testlist
		*/
		bool FitsCompleteList(const vWString& value, const vWString& list) const;

		/**
		* For the case, when ListType=CompleteOrderedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param vWString& value: value to test
		* @param vWString& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches testlist
		*/
		bool FitsCompleteOrderedList(const vWString& value, const vWString& list) const;

		/**
		* For the case, when ListType=ContainedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param vWString& value: value to test
		* @param vWString& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches testlist
		*/
		bool FitsContainedList(const vWString& value, const vWString& list) const;

		/**
		* Tests, if 'value' string has only unique tokens
		*
		* @param vWString& value: value to test
		* @return bool: true, if 'value' has only unique tokens
		*/
		bool IsUnique(const vWString& value) const;

	};

};


//////////////////////////////////////////////////////////////////////////////////
#endif // !defined(_JDFNameState_H__)
