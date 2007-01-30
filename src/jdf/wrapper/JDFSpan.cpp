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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
// 120900 RP added JDFIntentBase class
// 151100 rename intent -> span
// 271004 ES modified implementation of all Spans to fit JDFSpecification. 
//		  Attribute Range of all Spans has type defined in JDFSpec and not JDFNameRangeList
//		  JDFEnumerationSpan::GetEnumerationsVString added to convert vint to vWString
//
// JDFSpan.cpp: implementation of the JDFSpan 
// contains specializations of the JDFSpan hierarchy
//
//////////////////////////////////////////////////////////////////////

#include "JDFSpan.h"

using namespace std;
namespace JDF{

	//////////////////////////////////////////////////////////////////////
	JDFSpanBase&JDFSpanBase::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFSpanBase: "+other.GetNodeName()); 
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFSpanBase::PreferredToActual(){
		if(!HasAttribute(atr_Preferred)) 
			return false;
		SetAttribute(atr_Actual,GetAttribute(atr_Preferred));
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	const WString& JDFSpanBase::PriorityString(){
		static const WString enums=L"Unknown,None,Suggested,Required"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////
	WString JDFSpanBase::PriorityString(EnumPriority value){
		return PriorityString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////

	const WString& JDFSpanBase::DataTypeString(){
		static const WString enums=L"Unknown,DurationSpan,IntegerSpan,NumberSpan,OptionSpan,NameSpan,EnumerationSpan,ShapeSpan,StringSpan,TimeSpan,XYPairSpan"; 
		return enums;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFSpanBase::FixVersion(EnumVersion version){
		if(version>=Version_1_2){
			if(HasAttribute(atr_Priority)){
				EnumPriority prio=GetPriority();
				if (prio==Priority_Required){
					SetSettingsPolicy(SettingsPolicy_MustHonor);
				}else{
					SetSettingsPolicy(SettingsPolicy_BestEffort);
				}
				RemoveAttribute(atr_Priority);
			}
		}else{
			EnumSettingsPolicy policy=GetSettingsPolicy();
			if(policy==SettingsPolicy_BestEffort){
				SetPriority(Priority_Required);
			}else{
				SetPriority(Priority_Suggested);
			}
		}
		return JDFElement::FixVersion(version);
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFSpanBase::DataTypeString(EnumDataType value){
		return DataTypeString().Token(value,WString::comma);
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFSpanBase::GetName(){
		return GetLocalName();
	}

	//////////////////////////////////////////////////////////////////////
	WString JDFSpanBase::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+L",Preferred,Actual,Range,OfferRange,Priority";
	};

	//////////////////////////////////////////////////////////////////////
	WString JDFSpanBase::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",DataType";
	};

	//////////////////////////////////////////////////////////////////////
	vWString JDFSpanBase::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=0;
		if(!ValidRange(level)) {
			vAtts.push_back(atr_Range);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidOfferRange(level)) {
			vAtts.push_back(atr_Range);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPreferred(level)) {
			vAtts.push_back(atr_Preferred);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidActual(level)) {
			vAtts.push_back(atr_Actual);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPriority(level)) {
			vAtts.push_back(atr_Priority);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidDataType(level)) {
			vAtts.push_back(atr_DataType);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFSpanBase::ValidPriority(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Priority,PriorityString(),false);
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFSpanBase::ValidDataType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DataType,DataTypeString(),RequiredLevel(level));
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFSpanBase::ValidPreferred(EnumValidationLevel level)const {
		return true;
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFSpanBase::ValidActual(EnumValidationLevel level)const {
		return true;
	};
	//////////////////////////////////////////////////////////////////////	

	bool JDFSpanBase::ValidRange(EnumValidationLevel level)const {
		return true;
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFSpanBase::ValidOfferRange(EnumValidationLevel level)const {
		return true;
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						IntegerSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_Integer);
		return true;
	}
	/////////////////////////////////////////////////////////////////////

	JDFIntegerSpan&JDFIntegerSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFIntegerSpan: "+other.GetNodeName()); 
		return *this;
	}
	//////////////////////////////////////////////////////////////////////

	int JDFIntegerSpan::GetActual() const{
		return GetIntAttribute(atr_Actual,WString::emptyStr);
	}
	//////////////////////////////////////////////////////////////////////

	int JDFIntegerSpan::GetPreferred() const{
		return GetIntAttribute(atr_Preferred,WString::emptyStr);
	}
	/////////////////////////////////////////////////////////////////////

	JDFIntegerRangeList JDFIntegerSpan::GetRange() const{
		return GetAttribute(atr_Range,WString::emptyStr);
	}
	/////////////////////////////////////////////////////////////////////

	JDFIntegerRangeList JDFIntegerSpan::GetOfferRange() const{
		return GetAttribute(atr_OfferRange,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::SetActual(int value){
		SetAttribute(atr_Actual,value);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::SetPreferred(int value){
		SetAttribute(atr_Preferred,value);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::SetRange(const JDFIntegerRangeList& value){
		SetAttribute(atr_Range,value);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::SetOfferRange(const JDFIntegerRangeList& value){
		SetAttribute(atr_OfferRange,value);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerSpan::ValidActual(EnumValidationLevel level)const {
		return ValidAttribute(atr_Actual,AttributeType_integer,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerSpan::ValidPreferred(EnumValidationLevel level)const {
		return ValidAttribute(atr_Preferred,AttributeType_integer,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFIntegerSpan::ValidRange(EnumValidationLevel level)const {
		return ValidAttribute(atr_Range,AttributeType_IntegerRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFIntegerSpan::ValidOfferRange(EnumValidationLevel level)const {
		return ValidAttribute(atr_OfferRange,AttributeType_IntegerRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::AddRange(const JDFIntegerRange& range){
		JDFIntegerRangeList rl=GetRange();
		rl.Append(range);
		SetAttribute(atr_Range,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::AddOfferRange(const JDFIntegerRange& range){
		JDFIntegerRangeList rl=GetOfferRange();
		rl.Append(range);
		SetAttribute(atr_OfferRange,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::AddRange(int xMin, int xMax){
		JDFIntegerRangeList rl=GetRange();
		rl.Append(xMin,xMax);
		SetAttribute(atr_Range,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::AddOfferRange(int xMin, int xMax){
		JDFIntegerRangeList rl=GetOfferRange();
		rl.Append(xMin,xMax);
		SetAttribute(atr_OfferRange,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::AddRange(int x){
		JDFIntegerRangeList rl=GetRange();
		rl.Append(x);
		SetAttribute(atr_Range,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFIntegerSpan::AddOfferRange(int x){
		JDFIntegerRangeList rl=GetRange();
		rl.Append(x);
		SetAttribute(atr_OfferRange,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						NumberSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFNumberSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_Number);
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	JDFNumberSpan& JDFNumberSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFNumberSpan: "+other.GetNodeName()); 
		return *this;
	}
	//////////////////////////////////////////////////////////////////////

	double JDFNumberSpan::GetActual() const{
		return GetRealAttribute(atr_Actual,WString::emptyStr);
	}
	//////////////////////////////////////////////////////////////////////

	double JDFNumberSpan::GetPreferred() const{
		return GetRealAttribute(atr_Preferred,WString::emptyStr);
	}
	//////////////////////////////////////////////////////////////////////

	JDFNumberRangeList JDFNumberSpan::GetRange() const{
		return GetAttribute(atr_Range,WString::emptyStr);
	}
	//////////////////////////////////////////////////////////////////////

	JDFNumberRangeList JDFNumberSpan::GetOfferRange() const{
		return GetAttribute(atr_OfferRange,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::SetActual(double value){
		SetAttribute(atr_Actual,value);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::SetPreferred(double value){
		SetAttribute(atr_Preferred,value);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::SetRange(const JDFNumberRangeList& value){
		SetAttribute(atr_Range,value);
	}

	//////////////////////////////////////////////////////////////////////
	void JDFNumberSpan::SetOfferRange(const JDFNumberRangeList& value){
		SetAttribute(atr_OfferRange,value);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNumberSpan::ValidActual(EnumValidationLevel level)const {
		return ValidAttribute(atr_Actual,AttributeType_double,false);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNumberSpan::ValidPreferred(EnumValidationLevel level)const {
		return ValidAttribute(atr_Preferred,AttributeType_double,false);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNumberSpan::ValidRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_Range,AttributeType_NumberRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFNumberSpan::ValidOfferRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_OfferRange,AttributeType_NumberRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::AddRange(const NumberRange& range){
		JDFNumberRangeList rl=GetRange();
		rl.Append(range);
		SetAttribute(atr_Range,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::AddOfferRange(const NumberRange& range){
		JDFNumberRangeList rl=GetOfferRange();
		rl.Append(range);
		SetAttribute(atr_OfferRange,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::AddRange(double xMin, double xMax){
		JDFNumberRangeList rl=GetRange();
		rl.Append(xMin,xMax);
		SetAttribute(atr_Range,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::AddOfferRange(double xMin, double xMax){
		JDFNumberRangeList rl=GetRange();
		rl.Append(xMin,xMax);
		SetAttribute(atr_OfferRange,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::AddRange(double x){
		JDFNumberRangeList rl=GetRange();
		rl.Append(x);
		SetAttribute(atr_Range,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNumberSpan::AddOfferRange(double x){
		JDFNumberRangeList rl=GetRange();
		rl.Append(x);
		SetAttribute(atr_OfferRange,rl.GetString());
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						OptionSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	bool JDFOptionSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_Option);
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	JDFOptionSpan& JDFOptionSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFOptionSpan: "+other.GetNodeName()); 
		return *this;
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFOptionSpan::GetRange() const{
		return GetAttribute(atr_Range,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFOptionSpan::GetOfferRange() const{
		return GetAttribute(atr_OfferRange,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFOptionSpan::GetActual() const{
		return GetBoolAttribute(atr_Actual,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFOptionSpan::GetPreferred() const{
		return GetBoolAttribute(atr_Preferred,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFOptionSpan::SetActual(bool value){
		SetAttribute(atr_Actual,value);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFOptionSpan::SetPreferred(bool value){
		SetAttribute(atr_Preferred,value);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFOptionSpan::SetRange(const WString& value){
		SetAttribute(atr_Range,value);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFOptionSpan::SetOfferRange(const WString& value){
		SetAttribute(atr_OfferRange,value);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFOptionSpan::ValidActual(EnumValidationLevel level)const {
		return ValidAttribute(atr_Actual,AttributeType_boolean,false);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFOptionSpan::ValidPreferred(EnumValidationLevel level)const {
		return ValidAttribute(atr_Preferred,AttributeType_boolean,false);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFOptionSpan::ValidRange(EnumValidationLevel level)const {
		return ValidAttribute(atr_Range,AttributeType_string,false);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFOptionSpan::ValidOfferRange(EnumValidationLevel level)const {
		return ValidAttribute(atr_OfferRange,AttributeType_string,false);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFOptionSpan::AddRange(bool x){
		WString s=GetRange();
		s += (WString) x;
		SetAttribute(atr_Range,s);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFOptionSpan::AddOfferRange(bool x){
		WString s=GetOfferRange();
		s += (WString) x;
		SetAttribute(atr_OfferRange,s);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						NameSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFNameSpan& JDFNameSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFEnumerationSpan: "+other.GetNodeName()); 
		return *this;
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFNameSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_Name);
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFNameSpan::GetActual() const{
		return GetAttribute(atr_Actual,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFNameSpan::GetPreferred() const{
		return GetAttribute(atr_Preferred,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFNameSpan::GetRange() const{
		return GetAttribute(atr_Range,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFNameSpan::GetOfferRange() const{
		return GetAttribute(atr_OfferRange,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNameSpan::SetActual(const WString& value){
		SetAttribute(atr_Actual,value);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNameSpan::SetPreferred(const WString& value){
		SetAttribute(atr_Preferred,value);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNameSpan::SetRange(const vWString& value){
		SetAttribute(atr_Range,value);
	}

	//////////////////////////////////////////////////////////////////////
	void JDFNameSpan::SetOfferRange(const vWString& value){
		SetAttribute(atr_OfferRange,value);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFNameSpan::ValidActual(EnumValidationLevel level)const {
		return ValidAttribute(atr_Actual,AttributeType_NMTOKEN,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNameSpan::ValidPreferred(EnumValidationLevel level)const {
		return ValidAttribute(atr_Preferred,AttributeType_NMTOKEN,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFNameSpan::ValidRange(EnumValidationLevel level)const {
		return ValidAttribute(atr_Range,AttributeType_NMTOKENS,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFNameSpan::ValidOfferRange(EnumValidationLevel level)const {
		return ValidAttribute(atr_OfferRange,AttributeType_NMTOKENS,false);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFNameSpan::AddRange(const WString& x){
		vWString s=GetRange();
		s.push_back(x);
		SetAttribute(atr_Range,s);
	}

	//////////////////////////////////////////////////////////////////////
	void JDFNameSpan::AddOfferRange(const WString& x){
		vWString s=GetOfferRange();
		s.push_back(x);
		SetAttribute(atr_OfferRange,s);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						EnumerationSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFEnumerationSpan& JDFEnumerationSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFEnumerationSpan: "+other.GetNodeName()); 
		return *this;
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_Enumeration);
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationSpan::ValidPreferred(EnumValidationLevel level)const{
		return ValidEnumAttribute(atr_Preferred,AllowedValues(),false);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationSpan::ValidActual(EnumValidationLevel level)const{
		return ValidEnumAttribute(atr_Actual,AllowedValues(),false);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFEnumerationSpan::ValidRange(EnumValidationLevel level)const{
		return ValidEnumerationsAttribute(atr_Range,AllowedValues(),false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFEnumerationSpan::ValidOfferRange(EnumValidationLevel level)const{
		return ValidEnumerationsAttribute(atr_OfferRange,AllowedValues(),false);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFEnumerationSpan::SetRange(int n){
		SetEnumAttribute(atr_Range,n,AllowedValues());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFEnumerationSpan::SetOfferRange(int n){
		SetEnumAttribute(atr_OfferRange,n,AllowedValues());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFEnumerationSpan::SetRange(vint v){
		SetEnumerationsAttribute(atr_Range,v,AllowedValues());
	};

	//////////////////////////////////////////////////////////////////////
	void JDFEnumerationSpan::SetOfferRange(vint v){
		SetEnumerationsAttribute(atr_OfferRange,v,AllowedValues());
	};

	//////////////////////////////////////////////////////////////////////

	vint JDFEnumerationSpan::GetRange() const{
		return GetEnumerationsAttribute(atr_Range,AllowedValues());
	};

	//////////////////////////////////////////////////////////////////////
	vint JDFEnumerationSpan::GetOfferRange() const{
		return GetEnumerationsAttribute(atr_OfferRange,AllowedValues());
	};

	//////////////////////////////////////////////////////////////////////

	void JDFEnumerationSpan::AddRange(int x){
		vint range = GetRange();
		range.push_back(x); 
		SetEnumAttribute(atr_Range,x,AllowedValues());
	};
	//////////////////////////////////////////////////////////////////////
	void JDFEnumerationSpan::AddOfferRange(int x){
		vint range = GetOfferRange();
		range.push_back(x); 
		SetEnumAttribute(atr_OfferRange,x,AllowedValues());
	};
	//////////////////////////////////////////////////////////////////////

	int JDFEnumerationSpan::GetPreferred() const{
		return GetEnumAttribute(atr_Preferred,AllowedValues());
	}
	//////////////////////////////////////////////////////////////////////

	void JDFEnumerationSpan::SetPreferred(int n){
		SetEnumAttribute(atr_Preferred,n,AllowedValues());
	}
	//////////////////////////////////////////////////////////////////////

	int JDFEnumerationSpan::GetActual() const{
		return GetEnumAttribute(atr_Actual,AllowedValues());
	}
	//////////////////////////////////////////////////////////////////////

	void JDFEnumerationSpan::SetActual(int n){
		SetEnumAttribute(atr_Actual,n,AllowedValues());
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFEnumerationSpan::GetEnumString(int n){
		return AllowedValues().Token(n);
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFEnumerationSpan::GetEnumerationsVString(const vint& v)const{
		vWString s;
		for (int i=0; i < v.size(); i++)
		{
			s.push_back(AllowedValues().Token(v[i]));
		}
		return s;
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						StringSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFStringSpan& JDFStringSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFStringSpan: "+other.GetNodeName()); 
		return *this;
	};
	//////////////////////////////////////////////////////////////////////

	bool JDFStringSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_String);
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFStringSpan::GetActual() const{
		return GetAttribute(atr_Actual,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	WString JDFStringSpan::GetPreferred() const{
		return GetAttribute(atr_Preferred,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	vWString JDFStringSpan::GetRange() const{
		vElement v=GetChildrenByTagName(atr_Range);
		vWString vL;
		for(int i=0; i<v.size(); i++){
			vL.push_back(v[i].GetChildText());
		}
		return vL;
	}

	//////////////////////////////////////////////////////////////////////
	vWString JDFStringSpan::GetOfferRange() const{
		vElement v=GetChildrenByTagName(atr_OfferRange);
		vWString vL;
		for(int i=0; i<v.size(); i++){
			vL.push_back(v[i].GetChildText());
		}
		return vL;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFStringSpan::SetPreferred(const WString& s){
		SetAttribute(atr_Preferred,s);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFStringSpan::SetActual(const WString& s){
		SetAttribute(atr_Actual,s);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFStringSpan::SetRange(const vWString& vs){
		RemoveChildren(atr_Range);
		for(int i=0; i<vs.size(); i++){
			JDFElement e=AppendElement(atr_Range);
			e.AppendText(vs.at(i));
		}
	}

	//////////////////////////////////////////////////////////////////////

	void JDFStringSpan::SetOfferRange(const vWString& vs){
		RemoveChildren(atr_OfferRange);
		for(int i=0; i<vs.size(); i++){
			JDFElement e=AppendElement(atr_Range);
			e.AppendText(vs.at(i));
		}
	}
	//////////////////////////////////////////////////////////////////////

	void JDFStringSpan::AddRange(const WString& x){
		JDFElement e=AppendElement(atr_Range);
		e.AppendText(x);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFStringSpan::AddOfferRange(const WString& x){
		JDFElement e=AppendElement(atr_OfferRange);
		e.AppendText(x);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFStringSpan::ValidRange(EnumValidationLevel level)const{
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFStringSpan::ValidOfferRange(EnumValidationLevel level)const{
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFStringSpan::ValidPreferred(EnumValidationLevel level)const {
		return ValidAttribute(atr_Preferred,AttributeType_string,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFStringSpan::ValidActual(EnumValidationLevel level)const {
		return ValidAttribute(atr_Actual,AttributeType_string,false);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						TimeSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFTimeSpan& JDFTimeSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFTimeSpan: "+other.GetNodeName()); 
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFTimeSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_Time);
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFTimeSpan::SetPreferred(const JDFDate& n){
		SetAttribute(atr_Preferred,n.DateTimeISO());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFTimeSpan::SetActual(const JDFDate& n){
		SetAttribute(atr_Actual,n.DateTimeISO());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFTimeSpan::SetRange(const JDFDateTimeRange& value){
		SetAttribute(atr_Range,value.GetString());
	}

	//////////////////////////////////////////////////////////////////////
	void JDFTimeSpan::SetOfferRange(const JDFDateTimeRange& value){
		SetAttribute(atr_OfferRange,value.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	JDFDate JDFTimeSpan::GetActual() const{
		return GetAttribute(atr_Actual,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	JDFDate JDFTimeSpan::GetPreferred() const{
		return GetAttribute(atr_Preferred,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	JDFDateTimeRange JDFTimeSpan::GetRange() const{
		return GetAttribute(atr_Range,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////
	JDFDateTimeRange JDFTimeSpan::GetOfferRange() const{
		return GetAttribute(atr_OfferRange,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFTimeSpan::ValidPreferred(EnumValidationLevel level) const {
		return ValidAttribute(atr_Preferred,AttributeType_dateTime,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFTimeSpan::ValidActual(EnumValidationLevel level) const {
		return ValidAttribute(atr_Actual,AttributeType_dateTime,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFTimeSpan::ValidRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_Range,AttributeType_DateTimeRange,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFTimeSpan::ValidOfferRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_OfferRange,AttributeType_DateTimeRange,false);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						DurationSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFDurationSpan& JDFDurationSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFDurationSpan: "+other.GetNodeName()); 
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFDurationSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_Duration);
		return true;
	}

	//////////////////////////////////////////////////////////////////////

	void JDFDurationSpan::SetPreferred(const JDFDuration& n){
		SetAttribute(atr_Preferred,n.DurationISO());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFDurationSpan::SetActual(const JDFDuration& n){
		SetAttribute(atr_Actual,n.DurationISO());
	}

	//////////////////////////////////////////////////////////////////////

	void JDFDurationSpan::SetRange(const JDFDurationRange& value){
		SetAttribute(atr_Range,value.GetString());
	}

	//////////////////////////////////////////////////////////////////////
	void JDFDurationSpan::SetOfferRange(const JDFDurationRange& value){
		SetAttribute(atr_OfferRange,value.GetString());
	}

	//////////////////////////////////////////////////////////////////////

	JDFDuration JDFDurationSpan::GetActual() const{
		return GetAttribute(atr_Actual,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	JDFDuration JDFDurationSpan::GetPreferred() const{
		return GetAttribute(atr_Preferred,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	JDFDurationRange JDFDurationSpan::GetRange() const{
		return GetAttribute(atr_Range,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////
	JDFDurationRange JDFDurationSpan::GetOfferRange() const{
		return GetAttribute(atr_OfferRange,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFDurationSpan::ValidPreferred(EnumValidationLevel level) const {
		return ValidAttribute(atr_Preferred,AttributeType_duration,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFDurationSpan::ValidActual(EnumValidationLevel level) const {
		return ValidAttribute(atr_Actual,AttributeType_duration,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFDurationSpan::ValidRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_Range,AttributeType_DurationRange,false);
	}

	//////////////////////////////////////////////////////////////////////

	bool JDFDurationSpan::ValidOfferRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_OfferRange,AttributeType_DurationRange,false);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						XYPairSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFXYPairSpan&JDFXYPairSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFXYPairSpan: "+other.GetNodeName()); 
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_XYPair);
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairSpan::ValidRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_Range,AttributeType_XYPairRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairSpan::ValidOfferRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_OfferRange,AttributeType_XYPairRangeList,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairSpan::ValidActual(EnumValidationLevel level) const {
		return ValidAttribute(atr_Actual,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFXYPairSpan::ValidPreferred(EnumValidationLevel level) const {
		return ValidAttribute(atr_Preferred,AttributeType_XYPair,false);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::SetActual(const JDFXYPair& xy){
		SetAttribute(atr_Actual, xy);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::SetPreferred(const JDFXYPair& xy){
		SetAttribute(atr_Preferred, xy);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::SetActual(double x,double y){
		SetAttribute(atr_Actual,JDFXYPair(x,y));
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::SetPreferred(double x,double y){
		SetAttribute(atr_Preferred,JDFXYPair(x,y));
	};

	//////////////////////////////////////////////////////////////////////

	JDFXYPair JDFXYPairSpan::GetActual() const{
		return GetAttribute(atr_Actual);
	};
	//////////////////////////////////////////////////////////////////////

	JDFXYPair JDFXYPairSpan::GetPreferred () const{
		return GetAttribute(atr_Preferred);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::SetRange(const JDFXYPairRangeList& value){
		SetAttribute(atr_Range,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::SetOfferRange(const JDFXYPairRangeList& value){
		SetAttribute(atr_OfferRange,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFXYPairRangeList JDFXYPairSpan::GetRange() const {
		return GetAttribute(atr_Range);
	};
	//////////////////////////////////////////////////////////////////////

	JDFXYPairRangeList JDFXYPairSpan::GetOfferRange() const {
		return GetAttribute(atr_OfferRange);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::AddRange(const JDFXYPairRange& range){
		JDFXYPairRangeList rl = GetRange();
		rl.Append(range);
		SetRange(rl);
	}
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::AddOfferRange(const JDFXYPairRange& range){
		JDFXYPairRangeList rl = GetOfferRange();
		rl.Append(range);
		SetOfferRange(rl);
	}
	//////////////////////////////////////////////////////////////////////
	void JDFXYPairSpan::AddRange(const JDFXYPair&xy){
		JDFXYPairRangeList rl = GetRange();
		rl.Append(xy);
		SetRange(rl);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFXYPairSpan::AddOfferRange(const JDFXYPair&xy){
		JDFXYPairRangeList rl = GetOfferRange();
		rl.Append(xy);
		SetOfferRange(rl);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::AddRange(const JDFXYPair&xy1,const JDFXYPair&xy2){
		JDFXYPairRangeList rl = GetRange();
		rl.Append(xy1,xy2);
		SetRange(rl);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFXYPairSpan::AddOfferRange(const JDFXYPair&xy1,const JDFXYPair&xy2){
		JDFXYPairRangeList rl = GetOfferRange();
		rl.Append(xy1,xy2);
		SetOfferRange(rl);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::AddRange(double x,double y){
		AddRange(JDFXYPair(x,y));
	};
	//////////////////////////////////////////////////////////////////////


	void JDFXYPairSpan::AddOfferRange(double x,double y){
		AddOfferRange(JDFXYPair(x,y));
	};
	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::AddRange(double x1,double y1,double x2,double y2){
		AddRange(JDFXYPair(x1,y1),JDFXYPair(x2,y2));
	};

	//////////////////////////////////////////////////////////////////////

	void JDFXYPairSpan::AddOfferRange(double x1,double y1,double x2,double y2){
		AddOfferRange(JDFXYPair(x1,y1),JDFXYPair(x2,y2));
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	/* ******************************************************
	//						ShapeSpan
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFShapeSpan& JDFShapeSpan::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFShapeSpan: "+other.GetNodeName()); 
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	bool JDFShapeSpan::init(){
		JDFSpanBase::init();
		SetDataType(DataType_Shape);
		return true;
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFShapeSpan::ValidActual(EnumValidationLevel level) const {
		return ValidAttribute(atr_Actual,AttributeType_shape,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFShapeSpan::ValidPreferred(EnumValidationLevel level) const {
		return ValidAttribute(atr_Preferred,AttributeType_shape,false);
	}
	//////////////////////////////////////////////////////////////////////

	bool JDFShapeSpan::ValidRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_Range,AttributeType_ShapeRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFShapeSpan::ValidOfferRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_OfferRange,AttributeType_ShapeRangeList,false);
	}

	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::SetActual(const JDFShape& xyz){
		SetAttribute(atr_Actual, xyz);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::SetPreferred(const JDFShape& xyz){
		SetAttribute(atr_Preferred, xyz);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::SetActual(double x,double y, double z){
		SetAttribute(atr_Actual,JDFShape(x,y,z));
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::SetPreferred(double x,double y, double z){
		SetAttribute(atr_Preferred,JDFShape(x,y,z));
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::SetRange(const JDFShapeRangeList& value){
		SetAttribute(atr_Range,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////
	void JDFShapeSpan::SetOfferRange(const JDFShapeRangeList& value){
		SetAttribute(atr_OfferRange,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFShape JDFShapeSpan::GetActual() const{
		return GetAttribute(atr_Actual);
	};

	//////////////////////////////////////////////////////////////////////

	JDFShape JDFShapeSpan::GetPreferred () const{
		return GetAttribute(atr_Preferred);
	};

	//////////////////////////////////////////////////////////////////////

	JDFShapeRangeList JDFShapeSpan::GetRange() const {
		return GetAttribute(atr_Range);
	};

	//////////////////////////////////////////////////////////////////////
	JDFShapeRangeList JDFShapeSpan::GetOfferRange() const {
		return GetAttribute(atr_OfferRange);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddRange(const JDFShapeRange& range){
		JDFShapeRangeList rl = GetRange();
		rl.Append(range);
		SetRange(rl);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddOfferRange(const JDFShapeRange& range){
		JDFShapeRangeList rl = GetOfferRange();
		rl.Append(range);
		SetOfferRange(rl);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddRange(const JDFShape& shape){
		JDFShapeRangeList rl = GetRange();
		rl.Append(shape);
		SetRange(rl);
	};
	//////////////////////////////////////////////////////////////////////
	void JDFShapeSpan::AddOfferRange(const JDFShape& shape){
		JDFShapeRangeList rl = GetOfferRange();
		rl.Append(shape);
		SetOfferRange(rl);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddRange(const JDFShape& shape1,const JDFShape& shape2){
		JDFShapeRangeList rl = GetRange();
		rl.Append(shape1,shape2);
		SetRange(rl);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddOfferRange(const JDFShape& shape1,const JDFShape& shape2){
		JDFShapeRangeList rl = GetOfferRange();
		rl.Append(shape1,shape2);
		SetOfferRange(rl);
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddRange(double x,double y,double z){
		AddRange(JDFShape(x,y,z));
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddOfferRange(double x,double y,double z){
		AddOfferRange(JDFShape(x,y,z));
	};
	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddRange(double x1,double y1,double z1,double x2,double y2, double z2){
		AddRange(JDFShape(x1,y1,z1),JDFShape(x2,y2,z2));
	};

	//////////////////////////////////////////////////////////////////////

	void JDFShapeSpan::AddOfferRange(double x1,double y1,double z1,double x2,double y2, double z2){
		AddOfferRange(JDFShape(x1,y1,z1),JDFShape(x2,y2,z2));
	};

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////


}