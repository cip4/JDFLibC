/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2003 The International Cooperation for the Integration of 
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
// 260102 RP Added AppendXXX and the const GetXXX routines
// 260602 RP removed the typed Get / GetCreate / Append routines
// 051102 RP GetSpans() bug fix 
//
// JDFIntentResource.h: interface for the JDFIntentResource class.
// defines the resource intent subclasses
//
// ////////////////////////////////////////////////////////////////////

#if !defined(_JDFIntentResource_H__INCLUDED_)
#define _JDFIntentResource_H__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFResource.h"
#include "AutoJDF/JDFAutoEnumerationSpan.h"
namespace JDF{
	
/**
mother of all product intent resources
	*/
	class JDF_WRAPPERCORE_EXPORT JDFIntentResource : public JDFResource{
	public:
		
	/**
	* construct destruct 
		*/
		inline JDFIntentResource():JDFResource(){};
		/**
		* copy ctor
		*/
		inline JDFIntentResource(const KElement & other):JDFResource(){
			*this=other;
		};
		/**
		* yactor
		*/
		JDFIntentResource& operator =(const KElement& other);
		
		/**
		* dtor
		*/
		virtual ~JDFIntentResource(){};
		
		/**
		* set all actual values to the preset defined in preferred
		* @param WString key the key of the span resource to modify, if empty do all
		* @return number of elements modified
		*/
		int PreferredToActual(const WString & key=WString::emptyStr);
		/**
		* get a list of all span resources
		* @return vElement all Span elements of this
		*/
		vElement GetSpans()const;

		/** 
		* Typesafe attribute validation of Class
		* @return true if class is valid
		*/
		virtual bool ValidClass(EnumValidationLevel level) const;
		/** 
		* default initialization
		* @return true if successful
		*/
		virtual bool init();
		/**
		* definition of the allowed node names for elements of this type
		* @return vector of valid node names, * if any
		*/
		virtual vWString GetValidNodeNames()const;

		
		
		/**
		* Get a number span
		* @param WString name name of the span element
		* @param bool bCreate if true create a new JDFNumberSpan if it does not yet exist
		* @return JDFNumberSpan the JDFNumberSpan
		*/
		inline JDFNumberSpan GetCreateNumberSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_Number);
		};
		
		/**
		* Get an option (boolean)  span
		* @param WString name name of the span element
		* @param bool bCreate if true create a new JDFNumberSpan if it does not yet exist
		* @return JDFOptionSpan the JDFOptionSpan
		*/
		inline JDFOptionSpan GetCreateOptionSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_Option);
		};
		
		/**
		* Get an integer  span
		* @param WString name name of the span element
		* @param bool bCreate if true create a new JDFNumberSpan if it does not yet exist
		* @return GetIntegerSpan the GetIntegerSpan
		*/
		inline JDFIntegerSpan GetCreateIntegerSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_Integer);
		};
		
		/**
		* Get a namespan
		* @param WString name name of the span element
		* @param bool bCreate if true create a new JDFNumberSpan if it does not yet exist
		* @return JDFNameSpan the JDFNameSpan
		*/
		inline JDFNameSpan GetCreateNameSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_Name);
		};
		
		
		/**
		* Get a string span
		* @param WString name name of the span element
		* @param bool bCreate if true create a new JDFNumberSpan if it does not yet exist
		* @return JDFStringSpan the JDFStringSpan
		*/
		inline JDFStringSpan GetCreateStringSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_String);
		};
		
		/**
		* Get a Duration span
		* @param WString name name of the span element
		* @param bool bCreate if true create a new JDFDurationSpan
		* @return JDFDurationSpan the JDFDurationSpan
		*/
		inline JDFDurationSpan GetCreateCreateDurationSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_Duration);
		};

		/**
		* Get a time span
		* @param WString name name of the span element
		* @param bool bCreate if true create a new GetTimeSpan
		* @return GetTimeSpan the GetTimeSpan
		*/
		inline JDFTimeSpan GetCreateTimeSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_Time);
		};
		
		/**
		* Get a XYPair span
		* @param WString name name of the span element
		* @param bool bCreate if true create a new JDFXYPairSpan
		* @return JDFXYPairSpan the JDFXYPairSpan
		*/
		inline JDFXYPairSpan GetCreateCreateXYPairSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_XYPair);
		};
		
		/**
		* Get a Shape span
		* @param WString name name of the span element
		* @param bool bCreate if true create a new JDFShapeSpan
		* @return JDFShapeSpan the JDFShapeSpan
		*/
		inline JDFShapeSpan GetCreateCreateShapeSpan(const WString & name){
			return GetCreateSpan(name,JDFSpanBase::DataType_Shape);
		};

		
		

		/**
		* Get a number span
		* @param WString name name of the span element
		* @return JDFNumberSpan the JDFNumberSpan
		*/
		inline JDFNumberSpan GetNumberSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_Number);
		};

		/**
		* Get an option (boolean)  span
		* @param WString name name of the span element
		* @return JDFOptionSpan the JDFOptionSpan
		*/
		inline JDFOptionSpan GetOptionSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_Option);
		};

		/**
		* Get an integer  span
		* @param WString name name of the span element
		* @return GetIntegerSpan the GetIntegerSpan
		*/
		inline JDFIntegerSpan GetIntegerSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_Integer);
		};

		/**
		* Get a namespan
		* @param WString name name of the span element
		* @return JDFNameSpan the JDFNameSpan
		*/
		inline JDFNameSpan GetNameSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_Name);
		};

		/**
		* Get a string span
		* @param WString name name of the span element
		* @return JDFStringSpan the JDFStringSpan
		*/
		inline JDFStringSpan GetStringSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_String);
		};

		/**
		* Get a Duration span
		* @param WString name name of the span element
		* @return GetDurationSpan the GetDurationSpan
		*/
		inline JDFDurationSpan GetDurationSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_Duration);
		};
		
		/**
		* Get a time span
		* @param WString name name of the span element
		* @return GetTimeSpan the GetTimeSpan
		*/
		inline JDFTimeSpan GetTimeSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_Time);
		};

		/**
		* Get a XYPair span
		* @param WString name name of the span element
		* @return JDFXYPairSpan the JDFXYPairSpan
		*/
		inline JDFXYPairSpan GetXYPairSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_XYPair);
		};

		/**
		* Get a Shape span
		* @param WString name name of the span element
		* @return JDFShapeSpan the JDFShapeSpan
		*/
		inline JDFShapeSpan GetShapeSpan(const WString & name)const{
			return GetSpan(name,JDFSpanBase::DataType_Shape);
		};



		/**
		* Append a number span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @return JDFNumberSpan the JDFNumberSpan
		*/
		inline JDFNumberSpan AppendNumberSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_Number);
		};

		/**
		* Append an option (boolean)  span
		* @param WString name name of the span element
		* @return JDFOptionSpan the JDFOptionSpan
		*/
		inline JDFOptionSpan AppendOptionSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_Option);
		};

		/**
		* Append an integer   span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @return AppendIntegerSpan the AppendIntegerSpan
		*/
		inline JDFIntegerSpan AppendIntegerSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_Integer);
		};

		/**
		* Append a name span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @return JDFNameSpan the JDFNameSpan
		*/
		inline JDFNameSpan AppendNameSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_Name);
		};

		/**
		* Append a string  span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @return JDFStringSpan the JDFStringSpan
		*/
		inline JDFStringSpan AppendStringSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_String);
		};

		/**
		* Append a Duration  span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @return AppendDurationSpan the AppendDurationSpan
		*/
		inline JDFDurationSpan AppendDurationSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_Duration);
		};
		
		/**
		* Append a time  span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @return AppendTimeSpan the AppendTimeSpan
		*/
		inline JDFTimeSpan AppendTimeSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_Time);
		};

		/**
		* Append a XYPair  span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @return JDFXYPairSpan the JDFXYPairSpan
		*/
		inline JDFXYPairSpan AppendXYPairSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_XYPair);
		};
			
		/**
		* Append a Shape  span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @return JDFShapeSpan the JDFShapeSpan
		*/
		inline JDFShapeSpan AppendShapeSpan(const WString & name){
			return AppendSpan(name,JDFSpanBase::DataType_Shape);
		};

		/**
		* Get a span, create it if it does not exist
		* @param WString name name of the span element
		* @param JDFSpanBase::EnumDataType nType datatype of the new span
		* @return JDFSpanBase the JDFSpanBase
		*/
		JDFSpanBase GetCreateSpan(const WString & name ,JDFSpanBase::EnumDataType nType);

		/**
		* Get a span
		* @param WString name name of the span element
		* @param JDFSpanBase::EnumDataType nType datatype of the new span
		* @return JDFSpanBase the JDFSpanBase
		*/
		JDFSpanBase GetSpan(const WString & name ,JDFSpanBase::EnumDataType nType)const;

		/**
		* Append a   span if it does not yet exist, else return the existing element
		* @param WString name name of the span element
		* @param JDFSpanBase::EnumDataType nType datatype of the new span
		* @return JDFSpanBase the JDFSpanBase
		*/
		JDFSpanBase AppendSpan(const WString & name ,JDFSpanBase::EnumDataType nType);
		
	};
};

#endif // !defined(_JDFIntentResource_H__INCLUDED_)
