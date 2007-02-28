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


///////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/AutoJDF/JDFAutoUsageCounter.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoUsageCounter : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoUsageCounter& JDFAutoUsageCounter::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoUsageCounter: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoUsageCounter::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoUsageCounter::ValidNodeNames()const{
	return L"*:,UsageCounter";
};

bool JDFAutoUsageCounter::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Consumable;
};

bool JDFAutoUsageCounter::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Consumable);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoUsageCounter::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Scope";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoUsageCounter::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",CounterID,CounterTypes");
};

/**
 typesafe validator
*/
	vWString JDFAutoUsageCounter::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCounterID(level)) {
			vAtts.push_back(atr_CounterID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScope(level)) {
			vAtts.push_back(atr_Scope);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCounterTypes(level)) {
			vAtts.push_back(atr_CounterTypes);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CounterID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoUsageCounter::SetCounterID(const WString& value){
	SetAttribute(atr_CounterID,value);
};
/**
* Get string attribute CounterID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoUsageCounter::GetCounterID() const {
	return GetAttribute(atr_CounterID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoUsageCounter::ValidCounterID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CounterID,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoUsageCounter::ScopeString(){
		static const WString enums=WString(L"Unknown,Lifetime,PowerOn,Job");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoUsageCounter::ScopeString(EnumScope value){
		return ScopeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoUsageCounter::SetScope( EnumScope value){
	SetEnumAttribute(atr_Scope,value,ScopeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoUsageCounter::EnumScope JDFAutoUsageCounter:: GetScope() const {
	return (EnumScope) GetEnumAttribute(atr_Scope,ScopeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoUsageCounter::ValidScope(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Scope,ScopeString(),RequiredLevel(level));
	};
/**
* Set attribute CounterTypes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoUsageCounter::SetCounterTypes(const vWString& value){
	SetAttribute(atr_CounterTypes,value);
};
/**
* Get string attribute CounterTypes
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoUsageCounter::GetCounterTypes() const {
	return GetAttribute(atr_CounterTypes,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoUsageCounter::ValidCounterTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_CounterTypes,AttributeType_NMTOKENS,false);
	};
}; // end namespace JDF
