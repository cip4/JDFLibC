#if !defined(_JDFShapeState_H__)
#define _JDFShapeState_H__

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
// JDFShapeState.h: interface for the JDFShapeState class.
// defines the ShapeState attributes and subelements
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

	class _JDFShapeState : public JDFState<JDFShape>
	{
	public:
		inline _JDFShapeState() : JDFState<JDFShape>() { }

		inline JDFShape GetDefaultValue() { return JDFState<JDFShape>::GetDefaultValue(); }

		inline void SetDefaultValue(JDFShape n){ JDFState<JDFShape>::SetDefaultValue(n); }

		inline JDFShape GetCurrentValue() { return JDFState<JDFShape>::GetCurrentValue(); }

		inline void SetCurrentValue(JDFShape n) { return JDFState<JDFShape>::SetCurrentValue(n); }
	};

	class JDF_WRAPPERCORE_EXPORT JDFShapeState: public _JDFShapeState{
	public:
	/** *****************************
	* Construction / Destruction
	******************************************** */
	//@{
		
		/**
		* Empty constructor
		*/
		inline JDFShapeState():_JDFShapeState(){};
		
		/**
		* Copy constructor
		*/
		inline JDFShapeState(const KElement & other):_JDFShapeState(){ *this=other;	};

		/**
		* Equivalence copy constructor
		*/
		JDFShapeState&operator =(const KElement& other);
		
		/**
		* Destructor
		*/
		virtual ~JDFShapeState(){};
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
		* Tests, if the defined value matches Allowed test lists or Present test lists,
		* specified for this State
		*
		* @param WString& value: value to test
		* @param EnumFitsValue testlists: test lists, that the value has to match.
		* In this State the test lists are ValueList, X, Y, Z. 
		* Choose one of two values: FitsValue_Allowed or FitsValue_Present. Defaults to Allowed
		* @return bool: true, if the value matches testlists or if 
		* AllowedValueList, AllowedX, AllowedY and AllowedZ are not specified
		*/
		bool FitsValue(const WString& value, EnumFitsValue testlists=FitsValue_Allowed) const;


		/* ******************************************************
		// Attribute Getter/ Setter
		**************************************************************** */	
		
		//@{
		/**
		* Gets the value of attribute AllowedValueList
		*
		* @return JDFShapeRangeList: the attribute value
		*/
		JDFShapeRangeList GetAllowedValueList()const;

		/**
		* Sets the AllowedValueList attribute
		*
		* @param JDFShapeRangeList& value: value to set the attribute to
		*/
		void SetAllowedValueList(const JDFShapeRangeList& value);

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
		* @return JDFShapeRangeList: the attribute value
		*/
		JDFShapeRangeList GetPresentValueList()const;

		/**
		* Sets the PresentValueList attribute
		*
		* @param JDFShapeRangeList& value: value to set the attribute to
		*/
		void SetPresentValueList(const JDFShapeRangeList& value);

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
		* Gets the value of attribute AllowedX
		*
		* @return NumberRangeList: the attribute value
		*/
		NumberRangeList GetAllowedX()const;

		/**
		* Sets the AllowedX attribute
		*
		* @param NumberRangeList& value: value to set the attribute to
		*/
		void SetAllowedX(const NumberRangeList& value);

		/**
		* Typesafe attribute validation of AllowedX
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedX(EnumValidationLevel level)const;
		//@}

		
		//@{
		/**
		* Gets the value of attribute PresentX,
		* if not specified the value of AllowedX is applied
		*
		* @return NumberRangeList: the attribute value
		*/
		NumberRangeList GetPresentX()const;

		/**
		* Sets the PresentX attribute
		*
		* @param NumberRangeList& value: value to set the attribute to
		*/
		void SetPresentX(const NumberRangeList& value);

		/**
		* Typesafe attribute validation of PresentX
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentX(EnumValidationLevel level)const;
		//@}
		

		//@{
		/**
		* Gets the value of attribute AllowedY
		*
		* @return NumberRangeList: the attribute value
		*/
		NumberRangeList GetAllowedY()const;

		/**
		* Sets the AllowedY attribute
		*
		* @param NumberRangeList& value: value to set the attribute to
		*/
		void SetAllowedY(const NumberRangeList& value);

		/**
		* Typesafe attribute validation of AllowedY
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedY(EnumValidationLevel level)const;
		//@}

		
		//@{
		/**
		* Gets the value of attribute PresentY,
		* if not specified the value of AllowedY is applied
		*
		* @return NumberRangeList: the attribute value
		*/
		NumberRangeList GetPresentY()const;

		/**
		* Sets the PresentY attribute
		*
		* @param NumberRangeList& value: value to set the attribute to
		*/
		void SetPresentY(const NumberRangeList& value);

		/**
		* Typesafe attribute validation of PresentY
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentY(EnumValidationLevel level)const;
		//@}
		

		//@{
		/**
		* Gets the value of attribute AllowedZ
		*
		* @return NumberRangeList: the attribute value
		*/
		NumberRangeList GetAllowedZ()const;

		/**
		* Sets the AllowedZ attribute
		*
		* @param NumberRangeList& value: value to set the attribute to
		*/
		void SetAllowedZ(const NumberRangeList& value);

		/**
		* Typesafe attribute validation of AllowedZ
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedZ(EnumValidationLevel level)const;
		//@}

		
		//@{
		/**
		* Gets the value of attribute PresentZ,
		* if not specified the value of AllowedZ is applied
		*
		* @return NumberRangeList: the attribute value
		*/
		NumberRangeList GetPresentZ()const;

		/**
		* Sets the PresentZ attribute
		*
		* @param NumberRangeList& value: value to set the attribute to
		*/
		void SetPresentZ(const NumberRangeList& value);

		/**
		* Typesafe attribute validation of PresentZ
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentZ(EnumValidationLevel level)const;
		//@}
		

		//@{
		/**
		* @deprecated Use AllowedValueList
		*/

		/**
		* Gets the value of attribute AllowedValueMax
		*
		* @return JDFShape: the attribute value
		*/
		JDFShape GetAllowedValueMax() const;
		
		/**
		* Sets the AllowedValueMax attribute
		*
		* @param JDFShape& value: value to set the attribute to
		*/
		void SetAllowedValueMax(const JDFShape& value);

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
		* @return JDFShape: the attribute value
		*/
		JDFShape GetAllowedValueMin() const;
		
		/**
		* Sets the AllowedValueMin attribute
		*
		* @param JDFShape& value: value to set the attribute to
		*/
		void SetAllowedValueMin(const JDFShape& value);

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
		* @return JDFShape: the attribute value
		*/
		JDFShape GetPresentValueMax() const;
		
		/**
		* Sets the PresentValueMax attribute
		*
		* @param JDFShape& value: value to set the attribute to
		*/
		void SetPresentValueMax(const JDFShape& value);

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
		* @return JDFShape: the attribute value
		*/
		JDFShape GetPresentValueMin() const;
		
		/**
		* Sets the PresentValueMin attribute
		*
		* @param JDFShape& value: value to set the attribute to
		*/
		void SetPresentValueMin(const JDFShape& value);

		/**
		* Typesafe attribute validation of PresentValueMin
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentValueMin(EnumValidationLevel level)const;
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
		* @param const WString& value: value to test
		* @return bool: true, if 'value' matches specified value of ListType
		*/
		bool FitsListType(const WString& value) const;
		
		/**
		* Tests, if the defined 'rangelist' value is in the AllowedValueList or in the PresentValueList,
		* specified for this State
		*
		* @param JDFShapeRangeList rangelist: range list to test
		* @param EnumFitsValue valuelist: Switches between AllowedValueList and PresentValueList.
		* @return bool: true, if the 'rangelist' value is in the valuelist or if AllowedValueList is not specified
		*/
		bool FitsValueList (const JDFShapeRangeList& rangelist, EnumFitsValue valuelist) const;
		
		/**
		* Tests, if the defined 'rangelist' matches the AllowedX, AllowedY, AllowedZ or 
		* the PresentX, PresentY, PresentZ, specified for this State
		*
		* @param JDFShapeRangeList& rangelist: range list to test
		* @param EnumFitsValue xyzlist: Switches between AllowedX, AllowedY, AllowedZ and PresentX, PresentY, PresentZ.
		* @return bool: true, if the 'rangelist' matches xyzlist or if AllowedX, AllowedY, AllowedZ are not specified
		*/
		bool FitsXYZ (const JDFShapeRangeList& rangelist, EnumFitsValue xyzlist) const;

		/**
		* For the case, when ListType=CompleteList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFShapeRangeList& value: value to test
		* @param JDFShapeRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsCompleteList(const JDFShapeRangeList& value, const JDFShapeRangeList& list) const;

		/**
		* For the case, when ListType=CompleteOrderedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFShapeRangeList& value: value to test
		* @param JDFShapeRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsCompleteOrderedList(const JDFShapeRangeList& value, const JDFShapeRangeList& list) const;

		/**
		* For the case, when ListType=ContainedList, tests, if the defined 'value' matches 
		* AllowedValueList or PresentValueList, specified for this State
		*
		* @param JDFShapeRangeList& value: value to test
		* @param JDFShapeRangeList& list: testlist - either AllowedValueList or PresentValueList.
		* @return bool: true, if 'value' matches valuelist
		*/
		bool FitsContainedList(const JDFShapeRangeList& value, const JDFShapeRangeList& list) const;


	};
	
	
};


//////////////////////////////////////////////////////////////////////////////////
#endif // !defined(_JDFShapeState_H__)
