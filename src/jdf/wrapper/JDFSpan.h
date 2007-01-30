/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 110900 RP added template classes JDFSelection and JDFSelectionPool
// 120900 RP added JDFSpanBase class
// 151101 RP modified constructors
// 310502 RP added DurationSpan and ShapeSpan support
// 310502 RP GetName() now calls GetLocalName
// 310502 RP JDFSpanBase::GetInvalidAttributes() modified
// 310502 RP JDFStringSpan::GetRange() modified
// 271004 ES modified implementation of all Spans to fit JDFSpecification Release 1.2. 
//		  Attribute Range of all Spans has type defined in JDFSpec and not JDFNameRangeList
//		  JDFEnumerationSpan::GetEnumerationsVString() added to convert vint to vWString
// 250107 NB removed unreferenced variables
//
// JDFSpan.h: interface for the JDFSpan class.
// defines the generic Span sub-elements
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFSpan_H__)
#define _JDFSpan_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFElement.h"
#include "JDFNameRangeList.h"
#include "JDFIntegerRangeList.h"
#include "JDFNumberRangeList.h"

namespace JDF{
	
/**
* defines the data type independent parts of a ranged Span resource
	*/
	class JDF_WRAPPERCORE_EXPORT JDFSpanBase: public JDFElement{
	public:
	/**
	* null ctor
		*/
		inline JDFSpanBase():JDFElement(){};
		
		/**
		* copy ctor
		*/
		inline JDFSpanBase(const KElement & other):JDFElement(){
			*this=other;
		};
		
		/**
		* yacctor
		*/
		JDFSpanBase&operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFSpanBase(){};
		
		/**
		* priority enumeration 
		*/
		enum EnumPriority{Priority_Unknown,Priority_None,Priority_Suggested,Priority_Required};
		/**
		* Enumeration strings for Priority
		* @return WString comma separated list of valid priorities
		*/
		static const WString& PriorityString();
		
		/**
		* Enumeration string for enum Priority
		*/
		static WString PriorityString(EnumPriority value);
		
		/**
		* Set attribute Priority
		*/
		inline void SetPriority( EnumPriority value){
			SetEnumAttribute(atr_Priority,value,PriorityString());
		};
		
		/**
		* Typesafe enumerated attribute Priority
		*/
		inline EnumPriority GetPriority() const {
			return (EnumPriority) GetEnumAttribute(atr_Priority,PriorityString());
		};
		/** 
		* Typesafe attribute validation of Priority
		*/
		virtual bool ValidPriority(EnumValidationLevel level) const;
		
		/**
		* enum for datatype enumeration 
		*/
		enum EnumDataType{DataType_Unknown,DataType_Duration,DataType_Integer,DataType_Number,DataType_Option,DataType_Name,DataType_Enumeration,DataType_Shape,DataType_String,DataType_Time,DataType_XYPair};
		
		/**
		* Enumeration strings for DataType
		* @return WString comma separated list of valid datatypes
		*/
		static const WString& DataTypeString();
		
		/**
		* Enumeration string for enum value
		*/
		
		static WString DataTypeString(EnumDataType value);
		
		/**
		* Set attribute DataType
		*/
		inline void SetDataType( EnumDataType value){
			SetEnumAttribute(atr_DataType,value,DataTypeString());
		};
		
		/**
		* Typesafe enumerated attribute DataType
		*/
		inline EnumDataType GetDataType() const {
			return (EnumDataType) GetEnumAttribute(atr_DataType,DataTypeString());
		};
		
		/** 
		* Typesafe attribute validation of DataType
		*/
		virtual bool ValidDataType(EnumValidationLevel level) const;
		
		/**
		* Get the name of the Span element
		*/
		WString GetName();
		
		
		/**
		* Is the preferred attribute 
		* @return bool true if an Preferred attribute is valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level)const;
		
		/**
		* Is the Actual attribute 
		* @return bool true if an Actual attribute is valid
		*/
		virtual bool ValidActual(EnumValidationLevel level)const ;
		
		/**
		* Is the Range attribute valid
		* @return bool true if an Range attribute is valid
		*/		
		virtual bool ValidRange(EnumValidationLevel level)const ;
		
		/**
		* Is the OfferRange attribute valid
		* @return bool true if an Range attribute is valid
		*/		
		virtual bool ValidOfferRange(EnumValidationLevel level)const ;
		
		/**
		* Set the Actual value to that of Preferred
		* @return true if successful
		*/		
		bool PreferredToActual();
		
		/**
		* typesafe validator
		* @param EnumValidationLevel level validation level
		* @param bIgnorePrivate if true, do not worry about attributes in other namespaces
		* @param int nMax maximum size of the returned vector
		* @return a vector of invalid attribute names
		*/
		virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;		
		
		/**
		* definition of optional attributes in the JDF namespace
		*/
		virtual WString OptionalAttributes()const;
		
		/**
		* definition of optional attributes in the JDF namespace
		*/
		virtual WString RequiredAttributes()const;

		/**
		* Version fixing routine
		*
		* replace Priority with the appropriate SettingsPolicy
		* if priority=required --> SettingsPolicy=MustHonor, else SettingsPolicy=BestEffort
		* if SettingsPolicy=MustHonor --> priority=required, else priority=suggested
		* @param EnumVersion version: version that the resulting element should correspond to
		* @param bool true if successful
		*/
		virtual bool FixVersion(EnumVersion version);
	};
	
	/* ******************************************************
	//					 JDFNumberSpan
	**************************************************************** */
	/**
	* Span type for numbers
	*/
	class JDF_WRAPPERCORE_EXPORT JDFNumberSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFNumberSpan():JDFSpanBase(){};
		
		/**
		* copy ctor
		*/
		inline JDFNumberSpan(const KElement & other):JDFSpanBase(){
			*this=other;
		};
		
		/**
		* equivalence copy ctor
		*/
		JDFNumberSpan&operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFNumberSpan(){};

		/**
		* set the Actual attribute
		*
		* @param double value - the value to set Actual attribute to
		*/
		virtual void SetActual(double value);

		/**
		* set the Preferred attribute
		*
		* @param double value - the value to set Preferred attribute to
		*/
		virtual void SetPreferred(double value);
		
		/**
		* set the Range attribute
		*
		* @param JDFNumberRangeList& rl - the value to set Range attribute to
		*/
		virtual void SetRange(const JDFNumberRangeList & rl);

		/**
		* set the OfferRange attribute
		*
		* @param JDFNumberRangeList& rl - the value to set Range attribute to
		*/
		virtual void SetOfferRange(const JDFNumberRangeList & rl);

		/**
		* get the Actual attribute
		*
		* @return double - Actual attribute value
		*/
		virtual double GetActual() const;
		
		/**
		* get the Preferred attribute
		*
		* @return double - Preferred attribute value
		*/
		virtual double GetPreferred() const;
		
		/**
		* get the Range attribute
		*
		* @return JDFNumberRangeList - Range attribute value
		*/
		virtual JDFNumberRangeList GetRange() const;
		/**
		* get the OfferRange attribute
		*
		* @return JDFNumberRangeList - OfferRange attribute value
		*/
		virtual JDFNumberRangeList GetOfferRange() const;

		/**
		* add new range element to the Range attribute as a JDFRange
		*
		* @param NumberRange& range - the range element to add
		*/
		virtual void AddRange(const NumberRange& range);
		
		/**
		* add new OfferRange element to the Range attribute as a JDFRange
		*
		* @param NumberRange& range - the range element to add
		*/
		virtual void AddOfferRange(const NumberRange& range);
		

		/**
		* add an element xMin~xMax to the Range attribute as a JDFRange
		*
		* @param double xMin - the left range element
		* @param double xMax - the right range element
		*/
		virtual void AddRange(double xMin, double xMax);

		/**
		* add an element xMin~xMax to the OfferRange attribute as a JDFRange
		*
		* @param double xMin - the left range element
		* @param double xMax - the right range element
		*/
		virtual void AddOfferRange(double xMin, double xMax);

		/**
		* add an element x to the Range attribute
		*
		* @param double x - new range element
		*/
		virtual void AddRange(double x);

		/**
		* add an element x to the OfferRange attribute
		*
		* @param double x - new range element
		*/
		virtual void AddOfferRange(double x);

		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;

		/**
		* default initialization
		*
		* @return true if successful
		*/
		virtual bool init();
	};
	
	
	/* ******************************************************
	//					 JDFIntegerSpan
	**************************************************************** */
	/**
	* Span type for integers
	*/
	class JDF_WRAPPERCORE_EXPORT JDFIntegerSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFIntegerSpan():JDFSpanBase(){};
		/**
		* copy ctor
		*/
		inline JDFIntegerSpan(const KElement & other):JDFSpanBase(other){};
		/**
		* equivalence copy ctor
		*/
		JDFIntegerSpan&operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFIntegerSpan(){};

		/**
		* set the Actual attribute
		*
		* @param int value - the value to set Actual attribute to
		*/
		virtual void SetActual(int value);

		/**
		* set the Preferred attribute
		*
		* @param int value - the value to set Preferred attribute to
		*/
		virtual void SetPreferred(int value);
		
		/**
		* set the Range attribute
		*
		* @param JDFIntegerRangeList& rl - the value to set Range attribute to
		*/
		virtual void SetRange(const JDFIntegerRangeList & rl);

		/**
		* set the OfferRange attribute
		*
		* @param JDFIntegerRangeList& rl - the value to set OfferRange attribute to
		*/
		virtual void SetOfferRange(const JDFIntegerRangeList & rl);

		/**
		* get the Actual attribute
		*
		* @return int - Actual attribute value
		*/
		virtual int GetActual() const;
		
		/**
		* get the Preferred attribute
		*
		* @return int - Preferred attribute value
		*/
		virtual int GetPreferred() const;
		
		/**
		* get the Range attribute
		*
		* @return JDFIntegerRangeList - Range attribute value
		*/
		virtual JDFIntegerRangeList GetRange() const;

		/**
		* get the OfferRange attribute
		*
		* @return JDFIntegerRangeList - OfferRange attribute value
		*/
		virtual JDFIntegerRangeList GetOfferRange() const;

		/**
		* add new range element to the Range attribute as a JDFRange
		*
		* @param JDFIntegerRange& range - the range element to add
		*/
		virtual void AddRange(const JDFIntegerRange& range);
		
		/**
		* add new OfferRange element to the Range attribute as a JDFRange
		*
		* @param JDFIntegerRange& range - the range element to add
		*/
		virtual void AddOfferRange(const JDFIntegerRange& range);
		
		/**
		* add an element xMin~xMax to the Range attribute as a JDFRange
		*
		* @param int xMin - the left range element
		* @param int xMax - the right range element
		*/
		virtual void AddRange(int xMin, int xMax);

		/**
		* add an element xMin~xMax to the OfferRange attribute as a JDFRange
		*
		* @param int xMin - the left range element
		* @param int xMax - the right range element
		*/
		virtual void AddOfferRange(int xMin, int xMax);

		/**
		* add an element x to the Range attribute
		*
		* @param int x - new range element
		*/
		virtual void AddRange(int x);

		/**
		* add an element x to the OfferRange attribute
		*
		* @param int x - new range element
		*/
		virtual void AddOfferRange(int x);

		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;

		/**
		* default initialization
		* @return true if successful
		*/
		virtual bool init();
	};
	
	

	/* ******************************************************
	//					 JDFOptionSpan
	**************************************************************** */
	/**
	* Span type for boolean options
	*/
	class JDF_WRAPPERCORE_EXPORT JDFOptionSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFOptionSpan():JDFSpanBase(){};
		/**
		* copy ctor
		*/
		inline JDFOptionSpan(const KElement & other):JDFSpanBase(){*this=other;};
		/**
		* equivalence copy ctor
		*/
		JDFOptionSpan&operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFOptionSpan(){};

		/**
		* set the Actual attribute
		*
		* @param bool x - value to set the attribute to
		*/
		virtual void SetActual(bool x);
		
		/**
		* set the Preferred attribute
		*
		* @param bool x - value to set the attribute to
		*/
		virtual void SetPreferred(bool x);
		
		/**
		* set the Range attribute
		*
		* @param WString& s - the value to set Range attribute to
		*/
		virtual void SetRange(const WString & s);

		/**
		* set the OfferRange attribute
		*
		* @param WString& s - the value to set OfferRange attribute to
		*/
		virtual void SetOfferRange(const WString & s);

		/**
		* get the Actual attribute
		*
		* @return bool - Actual attribute value
		*/
		virtual bool GetActual() const;
		
		/**
		* get the Preferred attribute
		*
		* @return bool - Preferred attribute value
		*/
		virtual bool GetPreferred() const;
		
		/**
		* get the Range attribute
		*
		* @return WString - Range attribute value
		*/
		virtual WString GetRange() const;

		/**
		* get the OfferRange attribute
		*
		* @return WString - OfferRange attribute value
		*/
		virtual WString GetOfferRange() const;

		/**
		* add an element x to the Range attribute
		*
		* @param bool x - new range element
		*/
		virtual void AddRange(bool x);

		/**
		* add an element x to the OfferRange attribute
		*
		* @param bool x - new range element
		*/
		virtual void AddOfferRange(bool x);

		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const; 

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const; 

		/**
		* default initialization
		* @return true if successful
		*/
		virtual bool init();
	};


	/* ******************************************************
	//					 JDFNameSpan
	**************************************************************** */

	/**
	* Span type for names without whitespace (NMTOKENS)
	*/
	class JDF_WRAPPERCORE_EXPORT JDFNameSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFNameSpan():JDFSpanBase(){};
		/**
		* copy ctor
		*/
		inline JDFNameSpan(const KElement & other):JDFSpanBase(other){};
		/**
		* equivalence copy ctor
		*/
		JDFNameSpan&operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFNameSpan(){};

		/**
		* set the Actual attribute
		*
		* @param WString& s - value to set the attribute to
		*/
		virtual void SetActual(const WString & s);
		
		/**
		* set the Preferred attribute
		*
		* @param WString& s - value to set the attribute to
		*/
		virtual void SetPreferred(const WString & s);
		
		/**
		* set the Range attribute
		*
		* @param vWString& s - NMTOKENS value to set Range attribute to
		*/
		virtual void SetRange(const vWString & s);

		/**
		* set the OfferRange attribute
		*
		* @param vWString& s - NMTOKENS value to set OfferRange attribute to
		*/
		virtual void SetOfferRange(const vWString & s);

		/**
		* get he Actual attribute
		*
		* @return WString - Actual attribute value
		*/
		virtual WString GetActual() const;
		
		/**
		* get the Preferred attribute
		*
		* @return WString - Preferred attribute value
		*/
		virtual WString GetPreferred() const;
		
		/**
		* get the Range attribute
		*
		* @return vWString - Range attribute value
		*/
		virtual vWString GetRange() const;

		/**
		* get the OfferRange attribute
		*
		* @return vWString - OfferRange attribute value
		*/
		virtual vWString GetOfferRange() const;

		/**
		* add an element s to the Range attribute
		*
		* @param WString& s - new range element
		*/
		virtual void AddRange(const WString& s);

		/**
		* add an element s to the OfferRange attribute
		*
		* @param WString& s - new range element
		*/
		virtual void AddOfferRange(const WString& s);

		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;

		/**
		* default initialization
		*
		* @return true if successful
		*/
		virtual bool init();
	};
	

	/* ******************************************************
	//					 JDFStringSpan
	**************************************************************** */
	/**
	* Span of strings. These may include whitespace
	*/
	class JDF_WRAPPERCORE_EXPORT JDFStringSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFStringSpan():JDFSpanBase(){};
		/**
		* copy ctor
		*/
		inline JDFStringSpan(const KElement & other):JDFSpanBase()
		{
			*this=other;
		}
		/**
		* equivalence copy ctor
		*/
		JDFStringSpan& operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFStringSpan(){};
		
		/**
		* set the Actual attribute
		*
		* @param WString& s - value to set the attribute to
		*/
		virtual void SetActual(const WString & s);
		
		/**
		* set the Preferred attribute
		*
		* @param WString& s - value to set the attribute to
		*/
		virtual void SetPreferred(const WString & s);

		/**
		* set the Range text element
		*
		* @param vWString& s - values to set Range text element to
		*/
		virtual void SetRange(const vWString & s);

		/**
		* set the OfferRange text element
		*
		* @param vWString& s - values to set OfferRange text element to
		*/
		virtual void SetOfferRange(const vWString & s);

		/**
		* get he Actual attribute
		*
		* @return WString - Actual attribute value
		*/
		virtual WString GetActual() const;
		
		/**
		* get the Preferred attribute
		*
		* @return WString - Preferred attribute value
		*/
		virtual WString GetPreferred() const;
		
		/**
		* get the Range text element
		*
		* @return vWString - Range text element value as a vector of strings
		*/
		virtual vWString GetRange() const;
		
		/**
		* get the OfferRange text element
		*
		* @return vWString - OfferRange text element value as a vector of strings
		*/
		virtual vWString GetOfferRange() const;

		/**
		* add an element s to the Range text element
		*
		* @param WString& s - range element to add
		*/
		virtual void AddRange(const WString& s);

		/**
		* add an element s to the OfferRange text element
		*
		* @param WString& s - range element to add
		*/
		virtual void AddOfferRange(const WString& s);

		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe validation of Range
		*
		* @param EnumValidationLevel level: validation level  
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;
		
		/**
		* Typesafe validation of OfferRange
		*
		* @param EnumValidationLevel level: validation level  
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;
		
		/**
		* default initialization
		*
		* @return true if successful
		*/
		virtual bool init();
	};
	
	/* ******************************************************
	//					 JDFEnumerationSpan
	**************************************************************** */
	/**
	Span of enumerated values
	*/
	class JDF_WRAPPERCORE_EXPORT JDFEnumerationSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFEnumerationSpan():JDFSpanBase(){};
		/**
		* copy ctor
		*/
		inline JDFEnumerationSpan(const KElement & other):JDFSpanBase(){
			*this=other;
		};
		/**
		* equivalence copy ctor
		*/
		JDFEnumerationSpan& operator =(const KElement& other);
		/**
		* dtor
		*/
		virtual ~JDFEnumerationSpan(){};
		
		/**
		* get the Range attribute
		*
		* @return vint - the enumeration equivalent of the attribute
		*/
		virtual vint GetRange() const;
		
		/**
		* get the OfferRange attribute
		*
		* @return vint - the enumeration equivalent of the attribute
		*/
		virtual vint GetOfferRange() const;
		
		/**
		* set the Range attribute as enumeration (one value)
		*
		* @param int value - the enumeration equivalent of the attribute
		*/
		virtual void SetRange(int value);

		/**
		* set the OfferRange attribute as enumeration (one value)
		*
		* @param int value - the enumeration equivalent of the attribute
		*/
		virtual void SetOfferRange(int value);

		/**
		* set the Range attribute as enumerations
		*
		* @param vint value - the enumeration equivalent of the attribute
		*/
		virtual void SetRange(vint value);

		/**
		* set the OfferRange attribute as enumerations
		*
		* @param vint value - the enumeration equivalent of the attribute
		*/
		virtual void SetOfferRange(vint value);

		/**
		* get the Preferred attribute
		*
		* @return int - the enumeration equivalent of the attribute
		*/
		virtual int GetPreferred() const;

		/**
		* set the Preferred attribute
		*
		* @param int value - the enumeration equivalent of the attribute
		*/
		virtual void SetPreferred(int n);

		/**
		* get the Actual attribute
		*
		* @return int - the Actual attribute value
		*/
		virtual int GetActual() const;

		/**
		* set the Actual attribute
		*
		* @param int value - the enumeration equivalent of the attribute
		*/
		virtual void SetActual(int value);

		/**
		* get the String representation of the Enumeration value
		*
		* @param int value - the enumeration equivalent of the attribute
		* @return WString - string representation of the value
		*/
		virtual WString GetEnumString(int value);

		/**
		* get the vWString representation of the Enumerations value
		*
		* @param vint value - the enumerations equivalent of the attribute
		* @return vWString - vWString representation of the value
		*/
		virtual vWString GetEnumerationsVString(const vint& value)const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;

		/**
		* add an enum value x to the Range 
		*
		* @param int x - enum value to add
		*/
		virtual void AddRange(int x);

		/**
		* add an enum value x to the OfferRange 
		*
		* @param int x - enum value to add
		*/
		virtual void AddOfferRange(int x);

		/**
		* default initialization
		*
		* @return true if successful
		*/
		virtual bool init();

	private:

		/**
		* AllowedValues - will be defined in the every particular EnumerationSpan
		*
		* @return WString - string representation of the allowed values
		*/
		virtual WString AllowedValues()const 
		{
			return WString::emptyStr;
		};
		
	};
	
	/* ******************************************************
	//					 JDFTimeSpan
	**************************************************************** */
	/**
	Span type for time
	*/
	class JDF_WRAPPERCORE_EXPORT JDFTimeSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFTimeSpan():JDFSpanBase(){};
		/**
		* copy ctor
		*/
		inline JDFTimeSpan(const KElement & other):JDFSpanBase(){
			*this=other;
		};
		
		/**
		* equivalence copy ctor
		*/
		JDFTimeSpan& operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFTimeSpan(){};
		
				
		/**
		* set the Preferred attribute
		* 
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate - Preferred attribute value
		*/
		virtual void SetPreferred(const JDFDate& n);
		
		/**
		* set the Actual attribute
		*
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate - Actual attribute value
		*/
		virtual void SetActual(const JDFDate& n);
		
		/**
		* set the Range attribute
		*
		* @param JDFDateTimeRange& rl - the value to set Range attribute to
		*/
		virtual void SetRange(const JDFDateTimeRange& rl);

		/**
		* set the OfferRange attribute
		*
		* @param JDFDateTimeRange& rl - the value to set Range attribute to
		*/
		virtual void SetOfferRange(const JDFDateTimeRange& rl);

		/**
		* get the Actual attribute value 
		*
		* @since 11.11.2004 returns date of type JDFDate instead of MyDate
		* @return JDFDate - value of Actual attribute
		*/
		virtual JDFDate GetActual() const;
		
		/**
		* get the Preferred attribute value 
		*
		* @since 11.11.2004 returns date of type JDFDate instead of MyDate
		* @return JDFDate - value of Preferred attribute
		*/
		virtual JDFDate GetPreferred() const;
		
		/**
		* get the Range attribute
		*
		* @return JDFDateTimeRange - Range attribute value
		*/
		virtual JDFDateTimeRange GetRange() const;
		
		/**
		* get the OfferRange attribute
		*
		* @return JDFDateTimeRange - OfferRange attribute value
		*/
		virtual JDFDateTimeRange GetOfferRange() const;

		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;

		/**
		* default initialization
		* @return true if successful
		*/
		virtual bool init();

	};
	
	/* ******************************************************
	//					 JDFDurationSpan
	**************************************************************** */
	/**
	Span type for duration
	*/
	class JDF_WRAPPERCORE_EXPORT JDFDurationSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFDurationSpan():JDFSpanBase(){};
		
		/**
		* copy ctor
		*/
		inline JDFDurationSpan(const KElement & other):JDFSpanBase(){
			*this=other;
		};
		
		/**
		* equivalence copy ctor
		*/
		JDFDurationSpan& operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFDurationSpan(){};
		
		/**
		* set the Preferred attribute
		*
		* @since 11.11.2004 takes the parameters of type JDFDuration instead of MyDate
		* @param JDFDuration - Preferred attribute value
		*/
		virtual void SetPreferred(const JDFDuration& n);
		
		/**
		* set the Actual attribute
		*
		* @since 11.11.2004 takes the parameters of type JDFDuration instead of MyDate
		* @param JDFDuration - Actual attribute value
		*/
		virtual void SetActual(const JDFDuration& n);
		
		/**
		* set the Range attribute
		*
		* @param JDFDurationRange& rl - the value to set Range attribute to
		*/
		virtual void SetRange(const JDFDurationRange& rl);

		/**
		* set the OfferRange attribute
		*
		* @param JDFDurationRange& rl - the value to set OfferRange attribute to
		*/
		virtual void SetOfferRange(const JDFDurationRange& rl);

		/**
		* get the Actual attribute value 
		*
		* @since 11.11.2004 returns date of type JDFDuration instead of MyDate
		* @return JDFDuration - value of Actual attribute
		*/
		virtual JDFDuration GetActual() const;
		
		/**
		* get the Preferred attribute value 
		*
		* @since 11.11.2004 returns date of type JDFDuration instead of MyDate
		* @return JDFDuration - value of Preferred attribute
		*/
		virtual JDFDuration GetPreferred() const;
		
		/**
		* get the Range attribute
		*
		* @return JDFDurationRange - Range attribute value
		*/
		virtual JDFDurationRange GetRange() const;

		/**
		* get the OfferRange attribute
		*
		* @return JDFDurationRange - OfferRange attribute value
		*/
		virtual JDFDurationRange GetOfferRange() const;

		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;


		/**
		* default initialization
		* @return true if successful
		*/
		virtual bool init();
		
		
	};

	/* ******************************************************
	//					 JDFXYPairSpan
	**************************************************************** */
	/**
	* Span type for XYPairs
	*/
	class JDF_WRAPPERCORE_EXPORT JDFXYPairSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFXYPairSpan():JDFSpanBase(){};
		
		/**
		* copy ctor
		*/
		inline JDFXYPairSpan(const KElement & other):JDFSpanBase(){
			*this=other;
		};
		/**
		* equivalence copy ctor
		*/
		JDFXYPairSpan& operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFXYPairSpan(){};
		
		/**
		* set the Actual attribute
		* defined by the XYPair coordinates x, y
		*
		* @param double x the actual left value
		* @param double y the actual right value
		*/
		virtual void SetActual(double x,double y);

		/**
		* set the Preferred attribute
		* defined by the XYPair coordinates x, y
		*
		* @param double x the preferred left value
		* @param double y the preferred right value
		*/
		virtual void SetPreferred(double x,double y);

		/**
		* set the Actual attribute
		* defined by the XYPair
		*
		* @param JDFXYPair xy - JDFXYPair value to set
		*/
		virtual void SetActual(const JDFXYPair& xy);

		/**
		* set the Preferred attribute
		* defined by the XYPair
		*
		* @param JDFXYPair xy - JDFXYPair value to set
		*/
		virtual void SetPreferred(const JDFXYPair& xy);

		/**
		* set the Range attribute defined by JDFXYPairRangeList 
		*
		* @param JDFXYPairRangeList& rl - value to set Range to
		*/
		virtual void SetRange(const JDFXYPairRangeList& rl);

		/**
		* set the OfferRange attribute defined by JDFXYPairRangeList 
		*
		* @param JDFXYPairRangeList& rl - value to set OfferRange to
		*/
		virtual void SetOfferRange(const JDFXYPairRangeList& rl);

		/**
		* get the Actual attribute value 
		*
		* @return JDFXYPair - value of Actual attribute
		*/
		virtual JDFXYPair GetActual() const;
		
		/**
		* get the Preferred attribute value 
		*
		* @return JDFXYPair - value of Preferred attribute
		*/
		virtual JDFXYPair GetPreferred() const;
		
		/**
		* get the Range attribute value 
		*
		* @param JDFXYPairRangeList - value of Range attribute
		*/
		virtual JDFXYPairRangeList GetRange() const;

		/**
		* get the OfferRange attribute value 
		*
		* @param JDFXYPairRangeList - value of OfferRange attribute
		*/
		virtual JDFXYPairRangeList GetOfferRange() const;

		/**
		* add to the attribute Range new JDFXYPair
		*
		* @param JDFXYPair shape - JDFXYPair value to add
		*/
		virtual void AddRange(const JDFXYPair& xy);
		
		/**
		* add to the attribute OfferRange new JDFXYPair
		*
		* @param JDFXYPair shape - JDFXYPair value to add
		*/
		virtual void AddOfferRange(const JDFXYPair& xy);
		
		/**
		* add to the attribute Range new JDFShapeRange
		* defined by left and right XYPair values
		*
		* @param JDFXYPair& xy1 - the left XYPair
		* @param JDFXYPair& xy2 - the right XYPair
		*/
		virtual void AddRange(const JDFXYPair& xy1,const JDFXYPair& xy2);

		/**
		* add to the attribute OfferRange new JDFShapeRange
		* defined by left and right XYPair values
		*
		* @param JDFXYPair& xy1 - the left XYPair
		* @param JDFXYPair& xy2 - the right XYPair
		*/
		virtual void AddOfferRange(const JDFXYPair& xy1,const JDFXYPair& xy2);

		/**
		* add to the attribute Range new JDFXYPairRange 
		*
		* @param JDFXYPairRange& range - JDFXYPairRange to add
		*/
		virtual void AddRange(const JDFXYPairRange& range);
		
		/**
		* add to the attribute OfferRange new JDFXYPairRange 
		*
		* @param JDFXYPairRange& range - JDFXYPairRange to add
		*/
		virtual void AddOfferRange(const JDFXYPairRange& range);
		
		/**
		* add to the attribute Range new JDFXYPair
		* defined by the XYPair coordinates x, y
		*
		* @param double x - x value
		* @param double y - y value
		*/
		virtual void AddRange(double x,double y);

		/**
		* add to the attribute OfferRange new JDFXYPair
		* defined by the XYPair coordinates x, y
		*
		* @param double x - x value
		* @param double y - y value
		*/
		virtual void AddOfferRange(double x,double y);
		
		/**
		* add to the attribute Range new JDFXYPairRange 
		* defined by the left (x1 y1) and right XYPair coordinates(x2 y2).
		* JDFXYPairRange = x1 y1 ~ x2 y2
		*
		* @param double x1 - left x value
		* @param double y1 - left y value
		* @param double x2 - right x value
		* @param double y2 - right y value
		*/
		virtual void AddRange(double x1,double y1,double x2,double y2);

		/**
		* add to the attribute OfferRange new JDFXYPairRange 
		* defined by the left (x1 y1) and right XYPair coordinates(x2 y2).
		* JDFXYPairRange = x1 y1 ~ x2 y2
		*
		* @param double x1 - left x value
		* @param double y1 - left y value
		* @param double x2 - right x value
		* @param double y2 - right y value
		*/
		virtual void AddOfferRange(double x1,double y1,double x2,double y2);

		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;

		/**
		* default initialization
		*
		* @return true if successful
		*/
		virtual bool init();

	};

	/* ******************************************************
	//					 JDFShapeSpan
	**************************************************************** */
	/**
	* Span type for Shapes
	*/
	class JDF_WRAPPERCORE_EXPORT JDFShapeSpan: public JDFSpanBase{
	public:
	/**
	* null ctor
		*/
		inline JDFShapeSpan():JDFSpanBase(){};
		
		/**
		* copy ctor
		*/
		inline JDFShapeSpan(const KElement & other):JDFSpanBase(){
			*this=other;
		};
		
		/**
		* equivalence copy ctor
		*/
		JDFShapeSpan& operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFShapeSpan(){};
		
		/**
		* set the Actual attribute
		* defined by the Shape
		*
		* @param JDFShape xyz - JDFShape value to set
		*/
		virtual void SetActual(const JDFShape& xyz);

		/**
		* set the Preferred attribute
		* defined by the Shape
		*
		* @param JDFShape xyz - JDFShape value to set
		*/
		virtual void SetPreferred(const JDFShape& xyz);
		
		/**
		* set the Actual attribute
		* defined by the Shape coordinates x, y, z
		*
		* @param double x - the Actual width
		* @param double y - the Actual height
		* @param double z - the Actual depth
		*/
		virtual void SetActual(double x,double y,double z);

		/**
		* set the Preferred attribute,
		* defined by the Shape coordinates x, y, z
		*
		* @param double x - the preferred width
		* @param double y - the preferred height
		* @param double z - the preferred depth
		*/
		virtual void SetPreferred(double x,double y,double z);

		/**
		* set the Range attribute defined by JDFShapeRangeList 
		*
		* @param JDFShapeRangeList& rl - value to set Range to
		*/
		virtual void SetRange(const JDFShapeRangeList& rl);

		/**
		* set the OfferRange attribute defined by JDFShapeRangeList 
		*
		* @param JDFShapeRangeList& rl - value to set OfferRange to
		*/
		virtual void SetOfferRange(const JDFShapeRangeList& rl);

		/**
		* get the Actual attribute value 
		*
		* @return JDFShape - value of Actual attribute
		*/
		virtual JDFShape GetActual() const;
		
		/**
		* get the Preferred attribute value 
		*
		* @return JDFShape - value of Preferred attribute
		*/
		virtual JDFShape GetPreferred() const;
		
		/**
		* get the Range attribute value 
		*
		* @return JDFShapeRangeList - value of Range attribute
		*/
		virtual JDFShapeRangeList GetRange() const;
		
		/**
		* get the OfferRange attribute value 
		*
		* @return JDFShapeRangeList - value of OfferRange attribute
		*/
		virtual JDFShapeRangeList GetOfferRange() const;
		
		/**
		* add  to the attribute Range new JDFShape
		*
		* @param JDFShape shape - JDFShape value to add
		*/
		virtual void AddRange(const JDFShape& shape);
		
		/**
		* add  to the attribute OfferRange new JDFShape
		*
		* @param JDFShape shape - JDFShape value to add
		*/
		virtual void AddOfferRange(const JDFShape& shape);
		
		/**
		* add to the attribute Range new JDFShapeRange 
		* defined by left and right JDFShape values
		*
		* @param JDFShape shape1 - the left Shape
		* @param JDFShape shape2 - the right Shape
		*/
		virtual void AddRange(const JDFShape& shape1,const JDFShape& shape2);
		/**
		* add to the attribute OfferRange new JDFShapeRange 
		* defined by left and right JDFShape values
		*
		* @param JDFShape shape1 - the left Shape
		* @param JDFShape shape2 - the right Shape
		*/
		virtual void AddOfferRange(const JDFShape& shape1,const JDFShape& shape2);
		
		/**
		* add to the attribute Range new JDFShapeRange 
		*
		* @param JDFShapeRange& shape1 - JDFShapeRange to add
		*/
		virtual void AddRange(const JDFShapeRange &range);

		/**
		* add to the attribute OfferRange new JDFShapeRange 
		*
		* @param JDFShapeRange& shape1 - JDFShapeRange to add
		*/
		virtual void AddOfferRange(const JDFShapeRange &range);

		/**
		* add to the attribute Range new JDFShape
		* defined by the Shape coordinates x, y, z
		*
		* @param double x - the width
		* @param double y - the height
		* @param double z - the depth
		*/		
		virtual void AddRange(double x, double y, double z);

		/**
		* add to the attribute OfferRange new JDFShape
		* defined by the Shape coordinates x, y, z
		*
		* @param double x - the width
		* @param double y - the height
		* @param double z - the depth
		*/		
		virtual void AddOfferRange(double x, double y, double z);

		/**
		* add to the attribute Range new JDFShapeRange 
		* defined by the left (x1 y1 z1) and right Shape coordinates(x2 y2 z2).
		* JDFShapeRange = x1 y1 z1 ~ x2 y2 z2
		*
		* @param double x1 the 1. width
		* @param double y1 the 1. height
		* @param double z1 the 1. depth
		* @param double x2 the 2. width
		* @param double y2 the 2. height
		* @param double z2 the 2. depth
		*/
		virtual void AddRange(double x1,double y1,double z1, double x2,double y2, double z2);
		
		/**
		* add to the attribute OfferRange new JDFShapeRange 
		* defined by the left (x1 y1 z1) and right Shape coordinates(x2 y2 z2).
		* JDFShapeRange = x1 y1 z1 ~ x2 y2 z2
		*
		* @param double x1 the 1. width
		* @param double y1 the 1. height
		* @param double z1 the 1. depth
		* @param double x2 the 2. width
		* @param double y2 the 2. height
		* @param double z2 the 2. depth
		*/
		virtual void AddOfferRange(double x1,double y1,double z1, double x2,double y2, double z2);
		
		/**
		* Typesafe attribute validation of Actual
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidActual(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Preferred
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidPreferred(EnumValidationLevel level) const;
		
		/**
		* Typesafe attribute validation of Range
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidRange(EnumValidationLevel level) const;

		/**
		* Typesafe attribute validation of OfferRange
		*
		* @param EnumValidationLevel level: level of attribute validation 
		* @return bool: true if valid
		*/
		virtual bool ValidOfferRange(EnumValidationLevel level) const;

		/**
		* default initialization
		*
		* @return true if successful
		*/
		virtual bool init();
	};
};


//////////////////////////////////////////////////////////////////////////////////
#endif // !defined(_JDFSpan_H__)
