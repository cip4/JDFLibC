/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSubscription.h"
#include "jdf/wrapper/JDFObservationTarget.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSubscription : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSubscription& JDFAutoSubscription::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSubscription: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSubscription::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSubscription::ValidNodeNames()const{
	return L"*:,Subscription";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoSubscription::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ChannelMode,Format,MinDelayTime,RepeatStep,RepeatTime,RetryPolicy,Template,URL");
};

/**
 typesafe validator
*/
	vWString JDFAutoSubscription::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidChannelMode(level)) {
			vAtts.push_back(atr_ChannelMode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFormat(level)) {
			vAtts.push_back(atr_Format);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinDelayTime(level)) {
			vAtts.push_back(atr_MinDelayTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRepeatStep(level)) {
			vAtts.push_back(atr_RepeatStep);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRepeatTime(level)) {
			vAtts.push_back(atr_RepeatTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRetryPolicy(level)) {
			vAtts.push_back(atr_RetryPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTemplate(level)) {
			vAtts.push_back(atr_Template);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURL(level)) {
			vAtts.push_back(atr_URL);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSubscription::ChannelModeString(){
		static const WString enums=WString(L"Unknown,FireAndForget,Reliable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSubscription::ChannelModeString(EnumChannelMode value){
		return ChannelModeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSubscription::SetChannelMode( EnumChannelMode value){
	SetEnumAttribute(atr_ChannelMode,value,ChannelModeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSubscription::EnumChannelMode JDFAutoSubscription:: GetChannelMode() const {
	return (EnumChannelMode) GetEnumAttribute(atr_ChannelMode,ChannelModeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscription::ValidChannelMode(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ChannelMode,ChannelModeString(),false);
	};
/**
* Set attribute Format
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscription::SetFormat(const WString& value){
	SetAttribute(atr_Format,value);
};
/**
* Get string attribute Format
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscription::GetFormat() const {
	return GetAttribute(atr_Format,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscription::ValidFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_Format,AttributeType_string,false);
	};
/**
* Set attribute MinDelayTime
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoSubscription::SetMinDelayTime(JDFDuration value){
	SetAttribute(atr_MinDelayTime,value.DurationISO());
};
/**
* Get string attribute MinDelayTime
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoSubscription::GetMinDelayTime() const {
	return GetAttribute(atr_MinDelayTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscription::ValidMinDelayTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinDelayTime,AttributeType_duration,false);
	};
/**
* Set attribute RepeatStep
*@param int value: the value to set the attribute to
*/
	 void JDFAutoSubscription::SetRepeatStep(int value){
	SetAttribute(atr_RepeatStep,WString::valueOf(value));
};
/**
* Get integer attribute RepeatStep
* @return int the vaue of the attribute 
*/
	 int JDFAutoSubscription::GetRepeatStep() const {
	return GetIntAttribute(atr_RepeatStep,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscription::ValidRepeatStep(EnumValidationLevel level) const {
		return ValidAttribute(atr_RepeatStep,AttributeType_integer,false);
	};
/**
* Set attribute RepeatTime
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSubscription::SetRepeatTime(double value){
	SetAttribute(atr_RepeatTime,WString::valueOf(value));
};
/**
* Get double attribute RepeatTime
* @return double the vaue of the attribute 
*/
	 double JDFAutoSubscription::GetRepeatTime() const {
	return GetRealAttribute(atr_RepeatTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscription::ValidRepeatTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_RepeatTime,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSubscription::RetryPolicyString(){
		static const WString enums=WString(L"Unknown,DiscardAtNextSignal,RetryForever");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSubscription::RetryPolicyString(EnumRetryPolicy value){
		return RetryPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSubscription::SetRetryPolicy( EnumRetryPolicy value){
	SetEnumAttribute(atr_RetryPolicy,value,RetryPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSubscription::EnumRetryPolicy JDFAutoSubscription:: GetRetryPolicy() const {
	return (EnumRetryPolicy) GetEnumAttribute(atr_RetryPolicy,RetryPolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscription::ValidRetryPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_RetryPolicy,RetryPolicyString(),false);
	};
/**
* Set attribute Template
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscription::SetTemplate(const WString& value){
	SetAttribute(atr_Template,value);
};
/**
* Get string attribute Template
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscription::GetTemplate() const {
	return GetAttribute(atr_Template,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscription::ValidTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_Template,AttributeType_string,false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscription::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscription::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscription::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFObservationTarget JDFAutoSubscription::GetObservationTarget(int iSkip)const{
	JDFObservationTarget e=GetElement(elm_ObservationTarget,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObservationTarget JDFAutoSubscription::GetCreateObservationTarget(int iSkip){
	JDFObservationTarget e=GetCreateElement(elm_ObservationTarget,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObservationTarget JDFAutoSubscription::AppendObservationTarget(){
	JDFObservationTarget e=AppendElement(elm_ObservationTarget);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoSubscription::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ObservationTarget);

		for(i=0;i<nElem;i++){
			if (!GetObservationTarget(i).IsValid(level)) {
				vElem.AppendUnique(elm_ObservationTarget);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoSubscription::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ObservationTarget";
	};
}; // end namespace JDF
