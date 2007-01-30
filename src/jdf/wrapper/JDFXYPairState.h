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
// JDFXYPairState.h: interface for the JDFXYPairState class.
// defines the XYPairState attributes and subelements
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFXYPairState_H__)
#define _JDFXYPairState_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
#include "JDFState.h"
#include "JDFValueLoc.h"

namespace JDF{

	
	typedef JDFState<JDFXYPair> _JDFXYPairState;
	class JDF_WRAPPERCORE_EXPORT JDFXYPairState: public _JDFXYPairState{
	public:
	/** *****************************
	* Construction / Destruction
	******************************************** */
	//@{
		/**
		* Empty constructor
		*/
		inline JDFXYPairState():_JDFXYPairState(){};
		
		/**
		* Copy constructor
		*/
		inline JDFXYPairState(const KElement & other):_JDFXYPairState(){ *this=other; };
		
		/**
		* Equivalence copy constructor
		*/
		JDFXYPairState& operator =(const KElement& other);
		
		/**
		* Destructor
		*/
		virtual ~JDFXYPairState(){};
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
		* @return WString& comma separated list of valid node names
		*/
		virtual WString ValidNodeNames()const;

		/**
		* Tests, if the defined value is in the AllowedValueList or in the PresentValueList,
		* specified for this State
		*
		* @param WString& value: value to test
		* @param EnumFitsValue valuelist: Switches between AllowedValueList and PresentValueList.
		*  Choose one of two values: FitsValue_Allowed and FitsValue_Present. Defaults to Allowed
		* @return bool: true, if the value is in the valuelist or if AllowedValueList is not specified
		*/
		bool FitsValue(const WString& value, EnumFitsValue valuelist=FitsValue_Allowed) const;


		/* ******************************************************
		// Attribute Getter/ Setter
		**************************************************************** */	
		

		//@{
		/**
		* Gets the value of attribute AllowedValueList
		*
		* @return JDFXYPairRangeList: the attribute value
		*/
		JDFXYPairRangeList GetAllowedValueList()const;

		/**
		* Sets the AllowedValueList attribute
		*
		* @param JDFXYPairRangeList& value: value to set the attribute to
		*/
		void SetAllowedValueList(const JDFXYPairRangeList& value);

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
		* @return JDFXYPairRangeList: the attribute value
		*/
		JDFXYPairRangeList GetPresentValueList()const;

		/**
		* Sets the PresentValueList attribute
		*
		* @param JDFXYPairRangeList& value: value to set the attribute to
		*/
		void SetPresentValueList(const JDFXYPairRangeList& value);

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
		* @deprecated Use AllowedValueList
		*/

		/**
		* Gets the value of attribute AllowedValueMax
		*
		* @return JDFXYPair: the attribute value
		*/
		JDFXYPair GetAllowedValueMax()const;

		/**
		* Sets the AllowedValueMax attribute
		*
		* @param JDFXYPair& value: value to set the attribute to
		*/
		void SetAllowedValueMax(const JDFXYPair& value);

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
		* @return JDFXYPair: the attribute value
		*/
		JDFXYPair GetAllowedValueMin() const;
		
		/**
		* Sets the AllowedValueMin attribute
		*
		* @param JDFXYPair& value: value to set the attribute to
		*/
		void SetAllowedValueMin(const JDFXYPair& value);

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
		* @return JDFXYPair: the attribute value
		*/
		JDFXYPair GetPresentValueMax() const;
		
		/**
		* Sets the PresentValueMax attribute
		*
		* @param JDFXYPair& value: value to set the attribute to
		*/
		void SetPresentValueMax(const JDFXYPair& value);

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
		* @return JDFXYPair: the attribute value
		*/
		JDFXYPair GetPresentValueMin() const;
		
		/**
		* set the PresentValueMin attribute
		* @param JDFXYPair& value: value to set the attribute to
		*/
		void SetPresentValueMin(const JDFXYPair& value);

		/**
		* Typesafe attribute validation of PresentValueMin
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentValueMin(EnumValidationLevel level)const;
		//@}

		
		//@{
		/**
		* Sets the AllowedXYRelation attribute
		*
		* @param EnumXYRelation value: value to set the attribute to
		*/
		void SetAllowedXYRelation(EnumXYRelation value);
		
		/**
		* Gets the value of attribute AllowedXYRelation
		*
		* @return EnumXYRelation: the attribute value
		*/
		JDFElement::EnumXYRelation GetAllowedXYRelation() const;
		
		/**
		* Typesafe attribute validation of AllowedXYRelation
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/	
		bool ValidAllowedXYRelation(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Sets the PresentXYRelation attribute
		*
		* @param EnumXYRelation value: value to set the attribute to
		*/
		void SetPresentXYRelation(EnumXYRelation value);
		
		/**
		* Gets the value of attribute PresentXYRelation,
		* if not specified the value of AllowedXYRelation is applied
		*
		* @return EnumXYRelation: the attribute value
		*/
		JDFElement::EnumXYRelation GetPresentXYRelation() const;
		
		/**
		* Typesafe attribute validation of PresentXYRelation
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/	
		bool ValidPresentXYRelation(EnumValidationLevel level) const;
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
		* @param const WString& value: value to test
		* @return bool: true, if 'value' matches specified value of ListType
		*/
		bool FitsListType(const WString& value) const;
		
		/**
		* Tests, if the defined 'rangelist' value is in the AllowedValueList or in the PresentValueList,
		* specified for this State
		*
		* @param JDFXYPairRangeList& rangelist: range list to test
		* @param EnumFitsValue valuelist: Switches between AllowedValueList and PresentValueList.
		* @return: true, if 'rangelist' is in the valuelist or if AllowedValueList is not specified
		*/
		bool FitsValueList(const JDFXYPairRangeList& rangelist, EnumFitsValue valuelist) const;

		/**
		* Tests, if the defined 'xypair' value matches AllowedXYRelation or PresentXYRelation,
		* specified for this State
		*
		* @param JDFXYPair& xypair: xypair to test
		* @param EnumFitsValue hwrelation: Switches between AllowedXYRelation and PresentXYRelation.
		* @return bool: true, if the 'xypair' matches hwrelation or if AllowedXYRelation is not specified
		*/
		bool FitsXYRelation(const JDFXYPair& xypair, EnumFitsValue hwrelation) const;

		/**
		* For the case, when ListType=CompleteList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFXYPairRangeList& value: value to test
		* @param JDFXYPairRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsCompleteList(const JDFXYPairRangeList& value, const JDFXYPairRangeList& list) const;

		/**
		* For the case, when ListType=CompleteOrderedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFXYPairRangeList& value: value to test
		* @param JDFXYPairRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsCompleteOrderedList(const JDFXYPairRangeList& value, const JDFXYPairRangeList& list) const;

		/**
		* For the case, when ListType=ContainedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFXYPairRangeList& value: value to test
		* @param JDFXYPairRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsContainedList(const JDFXYPairRangeList& value, const JDFXYPairRangeList& list) const;
	};

	
};


//////////////////////////////////////////////////////////////////////////////////
#endif // !defined(_JDFXYPairState_H__)
