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
// JDFPDFPathState.h: interface for the JDFPDFPathState class.
// defines the PDFPathState attributes and subelements
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFPDFPathState_H__)
#define _JDFPDFPathState_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
#include "JDFState.h"
#include "JDFValue.h"
#include "JDFLoc.h"


namespace JDF{

	
	typedef JDFState<WString> _JDFPDFPathState;
	class JDF_WRAPPERCORE_EXPORT JDFPDFPathState: public _JDFPDFPathState{
	public:
	/** *****************************
	* Construction / Destruction
	******************************************** */
	//@{
		/**
		* Empty constructor
		*/
		inline JDFPDFPathState():_JDFPDFPathState(){};
		
		/**
		* Copy constructor
		*/
		inline JDFPDFPathState(const KElement & other):_JDFPDFPathState(){
			*this=other;
		};
		/**
		* Equivalence copy ctor
		*/
		JDFPDFPathState&operator =(const KElement& other);
		
		/**
		* Destructor
		*/
		virtual ~JDFPDFPathState(){};
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
		* @param EnumFitsValue tetlists: test lists, that the value has to match.
		* In this State the test lists are Length, ValueElem. 
		* Choose one of two values: FitsValue_Allowed or FitsValue_Present. Defaults to Allowed
		* @return bool: true, if the value matches all test lists or if Allowed test lists are not specified
		*/
		bool FitsValue(const WString& value, EnumFitsValue testlists=FitsValue_Allowed) const;
		
		/* ******************************************************
		// Attribute Getter/ Setter
		**************************************************************** */	

		//@{
		/**
		* Sets the AllowedLength attribute
		*
		* @param JDFIntegerRange& value: value to set the attribute to
		*/
		void SetAllowedLength(const JDFIntegerRange& value);
	
		/**
		* Gets the value of attribute AllowedLength  
		*
		* @return JDFIntegerRange: the attribute value
		*/
		JDFIntegerRange GetAllowedLength() const ;
		
		/**
		* Typesafe attribute validation of AllowedLength
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidAllowedLength(EnumValidationLevel level) const;
		//@}


		//@{
		/**
		* Sets the PresentLength attribute
		*
		* @param JDFIntegerRange& value: value to set the attribute to
		*/
		void SetPresentLength(const JDFIntegerRange& value);
		
		/**
		* Gets the value of attribute PresentLength, 
		* if not specified the value of AllowedLength is applied
		*
		* @return JDFIntegerRange: the attribute value
		*/
		JDFIntegerRange GetPresentLength() const;

		/**
		* Typesafe attribute validation of PresentLength
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		bool ValidPresentLength(EnumValidationLevel level) const;
		//@}

		/* ******************************************************
		// Element Getter / Setter
		**************************************************************** */
		
		//@{
		/**
		* Gets the iSkip-th element Value
		*
		* @param int iSkip: number of elements to skip
		* @return JDFValue: the matching element
		*/
		JDFValue GetValue(int iSkip=0)const;
		
		/**
		* Appends element Value to the end of 'this'
		*
		* @return JDFValue: newly created Value element
		*/
		JDFValue AppendValue();
		//@}

		
		/* ******************************************************
		// Subelement attribute and element Getter / Setter
		**************************************************************** */

		//@{
		/**
		* Sets the AllowedValue attribute of i-th subelement Value
		*
		* @param int iSkip: the number of Value elements to skip
		* @param WString& value: value to set the attribute to
		*/
		void SetValueAllowedValue(int iSkip, const WString& value);
	
		/**
		* Gets the value of attribute AllowedValue of of i-th subelement Value
		*
		* @param int iSkip: the number of Value elements to skip
		* @return WString: the attribute value
		*/
		WString GetValueAllowedValue(int iSkip=0) const;
		//@}


		//@{
		/**
		* Sets the ValueUsage attribute of i-th subelement Value
		*
		* @param int iSkip: the number of Value elements to skip
		* @param EnumFitsValue value: value to set the attribute to
		*/
		void SetValueValueUsage(int iSkip, EnumFitsValue value);
	
		/**
		* Gets the value of attribute ValueUsage of of i-th subelement Value
		*
		* @param int iSkip: the number of Value elements to skip
		* @return EnumFitsValue: the attribute value
		*/
		EnumFitsValue GetValueValueUsage(int iSkip=0) const;
		//@}


		//@{
		/**
		* Gets the j-th element Loc of the i-th element Value
		*
		* @param int iSkip: number of Value elements to skip ( iSkip=0 - first Value element)
 		* @param int jSkip: number of Loc subelements of i-th Value element to skip, ( jSkip=0 - first Loc element)
		* @return JDFLoc: the matching Loc element
		*/
		JDFLoc GetValueLoc(int iSkip=0, int jSkip=0)const;
		
		/**
		* Appends element Loc to the end of the i-th subelement Value
		*
		* @param int iSkip: number of Value elements to skip ( iSkip=0 - first Value element)
		* @return JDFLoc: newly created Loc element
		*/
		JDFLoc AppendValueLoc(int iSkip=0);
		//@}


private:
		/**
		* Tests, if the defined 'pdfpath' matches AllowedLength or the PresentLength,
		* specified for this State
		*
		* @param WString& pdfpath: pdfpath to test
		* @param EnumFitsValue length: Switches between AllowedLength and PresentLength.
		* @return bool: true, if 'pdfpath' matches length or if AllowedLength is not specified
		*/
		bool FitsLength(const WString& pdfpath, EnumFitsValue length) const;

		/**
		* Tests, if the defined 'pdfpath' matches subelement Value,
		* specified for this State
		*
		* @param WString& pdfpath: pdfpath to test
		* @param EnumFitsValue valueusage: Switches between Allowed and Present configuration in subelement Value.
		* @return bool: true, if 'pdfpath' matches subelement Value 
		*/
		bool FitsValueElem(const WString& pdfpath, EnumFitsValue valueusage ) const;
	};


};


//////////////////////////////////////////////////////////////////////////////////
#endif // !defined(_JDFPDFPathState_H__)
