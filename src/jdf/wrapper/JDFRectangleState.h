#if !defined(_JDFRectangleState_H__)
#define _JDFRectangleState_H__

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
// created  28.01.2004
//
// JDFRectangleState.h: interface for the JDFRectangleState class.
// defines the RectangleState attributes and subelements
//
// ////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
#include "JDFState.h"
#include "JDFRangeList.h"
#include "JDFValueLoc.h"



namespace JDF{

	class _JDFRectangleState : public JDFState<JDFRectangle>
	{
	public:
		inline _JDFRectangleState() : JDFState<JDFRectangle>() { }

		inline JDFRectangle GetDefaultValue() { return JDFState<JDFRectangle>::GetDefaultValue(); }

		inline void SetDefaultValue(JDFRectangle n){ JDFState<JDFRectangle>::SetDefaultValue(n); }

		inline JDFRectangle GetCurrentValue() { return JDFState<JDFRectangle>::GetCurrentValue(); }

		inline void SetCurrentValue(JDFRectangle n) { return JDFState<JDFRectangle>::SetCurrentValue(n); }
	};

	class JDF_WRAPPERCORE_EXPORT JDFRectangleState: public _JDFRectangleState{
	public:
	/** *****************************
	* Construction / Destruction
	******************************************** */
	//@{
		/**
		* Empty constructor
		*/
		inline JDFRectangleState():_JDFRectangleState(){};
		
		/**
		* Copy constructor
		*/
		inline JDFRectangleState(const KElement & other):_JDFRectangleState(){ *this=other; };
		
		/**
		* Equivalence copy constructor
		*/
		JDFRectangleState&operator =(const KElement& other);
		
		/**
		* Destructor
		*/
		virtual ~JDFRectangleState(){};
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
		* definition of optional elements in the JDF namespace
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
		* In this State the test lists are ValueList, HWRelation. 
		* Choose one of two values: FitsValue_Allowed or FitsValue_Present. Defaults to Allowed
		* @return bool: true, if the value matches all test lists or if test lists are not specified
		*/
		bool FitsValue(const WString& value, EnumFitsValue tetlists=FitsValue_Allowed) const;

	
		/* ******************************************************
		// Attribute Getter/ Setter
		**************************************************************** */	

		//@{
		/**
		* Sets the AllowedHWRelation attribute
		*
		* @param EnumXYRelation value: value to set the attribute to
		*/
		void SetAllowedHWRelation(EnumXYRelation value);
		
		/**
		* Gets the value of attribute AllowedHWRelation
		*
		* @return EnumXYRelation: the attribute value
		*/
		JDFElement::EnumXYRelation GetAllowedHWRelation() const;
		
		/**
		* Typesafe attribute validation of AllowedHWRelation
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/	
		bool ValidAllowedHWRelation(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Sets the PresentHWRelation attribute
		*
		* @param EnumXYRelation value: value to set the attribute to
		*/
		void SetPresentHWRelation(EnumXYRelation value);
		
		/**
		* Gets the value of attribute PresentHWRelation,
		* if not specified the value of AllowedHWRelation is applied
		*
		* @return EnumXYRelation: the attribute value
		*/
		JDFElement::EnumXYRelation GetPresentHWRelation() const;
		
		/**
		* Typesafe attribute validation of PresentHWRelation
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/	
		bool ValidPresentHWRelation(EnumValidationLevel level) const;
		//@}

		
		//@{
		/**
		* Sets the AllowedValueList attribute
		*
		* @param JDFRectangleRangeList& value: value to set the attribute to
		*/
		void SetAllowedValueList(const JDFRectangleRangeList& value);
		
		/**
		* Gets the value of attribute AllowedValueList
		*
		* @return JDFRectangleRangeList: the attribute value
		*/
		JDFRectangleRangeList GetAllowedValueList() const;
		
		/**
		* Typesafe attribute validation of AllowedValueList
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/	
		bool ValidAllowedValueList(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Sets the PresentValueList attribute
		*
		* @param JDFRectangleRangeList& value: value to set the attribute to
		*/
		void SetPresentValueList(const JDFRectangleRangeList& value);
		
		/**
		* Gets the value of attribute PresentValueList,
		* if not specified the value of AllowedValueList is applied
		*
		* @return JDFRectangleRangeList: the attribute value
		*/
		JDFRectangleRangeList GetPresentValueList() const;
		
		/**
		* Typesafe attribute validation of PresentValueList
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/	
		bool ValidPresentValueList(EnumValidationLevel level) const;
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
		* Tests, if the defined 'rangelist' value is in the AllowedValueList or in the PresentValueList,
		* specified for this State
		*
		* @param JDFRectangleRangeList& rangelist: range list to test
		* @param EnumFitsValue valuelist: Switches between AllowedValueList and PresentValueList.
		* @return bool: true, if 'rangelist' is in the valuelist or if AllowedValueList is not specified
		*/
		bool FitsValueList(const JDFRectangleRangeList& rangelist, EnumFitsValue valuelist) const;

		/**
		* Tests, if the defined 'rect' value matches AllowedHWRelation or PresentHWRelation,
		* specified for this State. 
		*
		* @param JDFRectangle& rect: rectangle value to test
		* @param EnumFitsValue hwrelation: Switches between AllowedHWRelation and PresentHWRelation.
		* @return bool: true, if 'rect' matches hwrelation or if AllowedHWRelation is not specified
		*/
		bool FitsHWRelation(const JDFRectangle& rect, EnumFitsValue hwrelation) const;

		/**
		* For the case, when ListType=CompleteList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFRectangleRangeList value: value to test
		* @param JDFRectangleRangeList list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsCompleteList(const JDFRectangleRangeList& value, const JDFRectangleRangeList& list) const;

		/**
		* For the case, when ListType=CompleteOrderedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFRectangleRangeList value: value to test
		* @param JDFRectangleRangeList list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsCompleteOrderedList(const JDFRectangleRangeList& value, const JDFRectangleRangeList& list) const;

		/**
		* For the case, when ListType=ContainedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFRectangleRangeList value: value to test
		* @param JDFRectangleRangeList list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsContainedList(const JDFRectangleRangeList& value, const JDFRectangleRangeList& list) const;
	};
	
};


//////////////////////////////////////////////////////////////////////////////////
#endif // !defined(_JDFRectangleState_H__)
