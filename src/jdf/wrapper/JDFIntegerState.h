#if !defined(_JDFIntegerState_H__)
#define _JDFIntegerState_H__

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
// JDFIntegerState.h: interface for the JDFIntegerState class.
// defines the IntegerState attributes and subelements
//
// ////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFState.h"
#include "JDFElement.h"
#include "JDFValueLoc.h"


namespace JDF{


	/**
	* State type for integers
	*/
	class _JDFIntegerState : public JDFState<int>
	{
	public:
		inline _JDFIntegerState() : JDFState<int>() { }

		inline int GetDefaultValue() { return JDFState<int>::GetDefaultValue(); }

		inline void SetDefaultValue(int n){ JDFState<int>::SetDefaultValue(n); }

		inline int GetCurrentValue() { return JDFState<int>::GetCurrentValue(); }

		inline void SetCurrentValue(int n) { return JDFState<int>::SetCurrentValue(n); }
	};

	class JDF_WRAPPERCORE_EXPORT JDFIntegerState: public _JDFIntegerState{
	public:
	/** *****************************
	* Construction / Destruction
	******************************************** */
	//@{
		/**
		* Empty constructor
		*/
		inline JDFIntegerState():_JDFIntegerState(){};
		/**
		* Copy constructor
		*/
		inline JDFIntegerState(const KElement & other):_JDFIntegerState(){ *this=other;	};

		/**
		* Equivalence copy constructor
		*/
		JDFIntegerState& operator =(const KElement& other);
		
		/**
		* Destructor
		*/
		virtual ~JDFIntegerState(){};
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
		* Tests, if the defined 'value' matches Allowed test lists or Present test lists,
		* specified for this State
		*
		* @param WString& value: value to test
		* @param EnumFitsValue testlists: test lists, that the value has to match.
		* In this State the test lists are ValueList AND ValueMod. 
		* Choose one of two values: FitsValue_Allowed or FitsValue_Present. Defaults to Allowed
		* @return bool: true, if 'value' matches testlists or if AllowedValueList and AllowedValueMod are not specified
		*/
		bool FitsValue(const WString& value, EnumFitsValue testlists=FitsValue_Allowed) const;


		/* ******************************************************
		// Attribute Getter/ Setter
		**************************************************************** */	
		
		//@{
		/**
		* Gets the value of attribute AllowedValueList
		*
		* @return JDFIntegerRangeList: the attribute value
		*/
		JDFIntegerRangeList GetAllowedValueList()const;

		/**
		* Sets the AllowedValueList attribute
		*
		* @param JDFIntegerRangeList& value: value to set the attribute to
		*/
		void SetAllowedValueList(const JDFIntegerRangeList& value);

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
		* Gets the value of attribute PresentValueList,
		* if not specified the value of AllowedValueList is applied
		*
		* @return JDFIntegerRangeList: the attribute value
		*/
		JDFIntegerRangeList GetPresentValueList()const;

		/**
		* Sets the PresentValueList attribute
		*
		* @param JDFIntegerRangeList& value: value to set the attribute to
		*/
		void SetPresentValueList(const JDFIntegerRangeList& value);

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
		* Gets the value of attribute AllowedValueMod
		*
		* @return JDFXYPair: the attribute value
		*/
		JDFXYPair GetAllowedValueMod()const;

		/**
		* Sets the AllowedValueMod attribute
		*
		* @param JDFXYPair& value: value to set the attribute to
		*/
		void SetAllowedValueMod(const JDFXYPair& value);

		/**
		* Typesafe attribute validation of AllowedValueMod
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedValueMod(EnumValidationLevel level)const;
		//@}

		
		//@{
		/**
		* Gets the value of attribute PresentValueMod
		* if not specified the value of AllowedValueMod is applied
		*
		* @return JDFXYPair: the attribute value
		*/
		JDFXYPair GetPresentValueMod()const;

		/**
		* Sets the PresentValueMod attribute
		*
		* @param JDFXYPair& value: value to set the attribute to
		*/
		void SetPresentValueMod(const JDFXYPair& value);

		/**
		* Typesafe attribute validation of PresentValueMod
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentValueMod(EnumValidationLevel level)const;
		//@}


		//@{
		/**
		* @deprecated Use AllowedValueList
		*/

		/**
		* Gets the value of attribute AllowedValueMax
		*
		* @return int: the attribute value
		*/
		int GetAllowedValueMax() const;
		
		/**
		* Sets the AllowedValueMax attribute
		*
		* @param int value: value to set the attribute to
		*/
		void SetAllowedValueMax(int value);

		/**
		* Typesafe attribute validation of AllowedValueMax
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedValueMax(EnumValidationLevel level)const;
		//@}


		//@{
		/**
		* @deprecated Use AllowedValueList
		*/

		/**
		* Gets the value of attribute AllowedValueMin
		*
		* @return int: the attribute value
		*/
		int GetAllowedValueMin() const;
		
		/**
		* Sets the AllowedValueMin attribute
		*
		* @param int value: value to set the attribute to
		*/
		void SetAllowedValueMin(int value);

		/**
		* Typesafe attribute validation of AllowedValueMin
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedValueMin(EnumValidationLevel level)const;
		//@}
		

		//@{
		/**
		* @deprecated Use PresentValueList
		*/

		/**
		* Gets the value of attribute PresentValueMax,
		* if not specified the value of AllowedValueMax is applied
		*
		* @return int: the attribute value
		*/
		int GetPresentValueMax() const;
		
		/**
		* Sets the PresentValueMax attribute
		*
		* @param int value: value to set the attribute to
		*/
		void SetPresentValueMax(int value);

		/**
		* Typesafe attribute validation of PresentValueMax
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentValueMax(EnumValidationLevel level)const;
		//@}
		

		//@{
		/**
		* @deprecated Use PresentValueList
		*/

		/**
		* Gets the value of attribute PresentValueMin,
		* if not specified the value of AllowedValueMin is applied
		*
		* @return int: the attribute value
		*/
		int GetPresentValueMin() const;
		
		/**
		* Sets the PresentValueMin attribute
		*
		* @param int value: value to set the attribute to
		*/
		void SetPresentValueMin(int value);

		/**
		* Typesafe attribute validation of PresentValueMin
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentValueMin(EnumValidationLevel level)const;
		//@}
		

		//@{
		/**
		* Gets the value of attribute UnitType
		*
		* @return WString: the attribute value
		*/
		WString GetUnitType()const;

		/**
		* Sets the UnitType attribute
		*
		* @param WString& value: value to set the attribute to
		*/
		void SetUnitType(const WString& value);

		/**
		* Typesafe attribute validation of UnitType
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/		
		bool ValidUnitType(EnumValidationLevel level)const;
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
		* @return bool: true, if 'value' matches specified ListType
		*/
		bool FitsListType(const WString& value) const;

		/**
		* Tests, if the defined 'rangelist' matches the AllowedValueList or in the PresentValueList,
		* specified for this State
		*
		* @param JDFIntegerRangeList& rangelist: range list to test
		* @param EnumFitsValue valuelist: Switches between AllowedValueList and PresentValueList.
		* @return bool: true, if 'rangelist' matches the valuelist or if AllowedValueList is not specified
		*/
		bool FitsValueList(const JDFIntegerRangeList& rangelist, EnumFitsValue valuelist) const;

		/**
		* Tests, if the defined 'rangelist' matches the AllowedValueMod or the PresentValueMod,
		* specified for this State
		*
		* @param JDFIntegerRangeList& rangelist: range list to test
		* @param EnumFitsValue valuemod: Switches between AllowedValueMod and PresentValueMod.
		* @return bool: true, if 'rangelist' matches the valuemod or if AllowedValueMod is not specified
		*/
		bool FitsValueMod(const JDFIntegerRangeList& rangelist, EnumFitsValue valuemod) const;

		/**
		* For the case, when ListType=CompleteList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFIntegerRangeList& value: value to test
		* @param JDFIntegerRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches testlist
		*/
		bool FitsCompleteList(const JDFIntegerRangeList& value, const JDFIntegerRangeList& list) const;

		/**
		* For the case, when ListType=CompleteOrderedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFIntegerRangeList& value: value to test
		* @param JDFIntegerRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches testlist
		*/
		bool FitsCompleteOrderedList(const JDFIntegerRangeList& value, const JDFIntegerRangeList& list) const;

		/**
		* For the case, when ListType=ContainedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFIntegerRangeList& value: value to test
		* @param JDFIntegerRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches testlist
		*/
		bool FitsContainedList(const JDFIntegerRangeList& value, const JDFIntegerRangeList& list) const;


	};
	
};


//////////////////////////////////////////////////////////////////////////////////
#endif // !defined(_JDFIntegerState_H__)
