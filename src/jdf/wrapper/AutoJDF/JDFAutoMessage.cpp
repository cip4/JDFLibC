/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMessage.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMessage : public JDFMessageElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMessage& JDFAutoMessage::operator=(const KElement& other){
	KElement::operator=(other);
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMessage::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMessage::ValidNodeNames()const{
	return L"*:,Query,Command,Response,Acknowledge,Signal,Registration";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoMessage::RequiredAttributes()const{
		return JDFMessageElement::RequiredAttributes()+L",ID,Type";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMessage::OptionalAttributes()const{
		return JDFMessageElement::OptionalAttributes()+WString(L",AgentName,AgentVersion,ICSVersions,SenderID,Time,Version");
};

/**
 typesafe validator
*/
	vWString JDFAutoMessage::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFMessageElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAgentName(level)) {
			vAtts.push_back(atr_AgentName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAgentVersion(level)) {
			vAtts.push_back(atr_AgentVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidICSVersions(level)) {
			vAtts.push_back(atr_ICSVersions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSenderID(level)) {
			vAtts.push_back(atr_SenderID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTime(level)) {
			vAtts.push_back(atr_Time);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVersion(level)) {
			vAtts.push_back(atr_Version);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AgentName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMessage::SetAgentName(const WString& value){
	SetAttribute(atr_AgentName,value);
};
/**
* Get string attribute AgentName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMessage::GetAgentName() const {
	return GetAttribute(atr_AgentName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessage::ValidAgentName(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentName,AttributeType_string,false);
	};
/**
* Set attribute AgentVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMessage::SetAgentVersion(const WString& value){
	SetAttribute(atr_AgentVersion,value);
};
/**
* Get string attribute AgentVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMessage::GetAgentVersion() const {
	return GetAttribute(atr_AgentVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessage::ValidAgentVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentVersion,AttributeType_string,false);
	};
/**
* Set attribute ICSVersions
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoMessage::SetICSVersions(const vWString& value){
	SetAttribute(atr_ICSVersions,value);
};
/**
* Get string attribute ICSVersions
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoMessage::GetICSVersions() const {
	return GetAttribute(atr_ICSVersions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessage::ValidICSVersions(EnumValidationLevel level) const {
		return ValidAttribute(atr_ICSVersions,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMessage::SetID(const WString& value){
	SetAttribute(atr_ID,value);
};
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMessage::GetID() const {
	return GetAttribute(atr_ID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessage::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,RequiredLevel(level));
	};
/**
* Set attribute SenderID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMessage::SetSenderID(const WString& value){
	SetAttribute(atr_SenderID,value);
};
/**
* Get string attribute SenderID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMessage::GetSenderID() const {
	return GetAttribute(atr_SenderID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessage::ValidSenderID(EnumValidationLevel level) const {
		return ValidAttribute(atr_SenderID,AttributeType_string,false);
	};
/**
* Set attribute Time
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoMessage::SetTime(JDFDate value){
	SetAttribute(atr_Time,value.DateTimeISO());
};
/**
* Get string attribute Time
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoMessage::GetTime() const {
	return GetAttribute(atr_Time,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessage::ValidTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_Time,AttributeType_dateTime,false);
	};
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMessage::SetType(const WString& value){
	SetAttribute(atr_Type,value);
};
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMessage::GetType() const {
	return GetAttribute(atr_Type,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessage::ValidType(EnumValidationLevel level) const {
		return ValidAttribute(atr_Type,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute Version
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMessage::SetVersion(const WString& value){
	SetAttribute(atr_Version,value);
};
/**
* Get string attribute Version
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMessage::GetVersion() const {
	return GetAttribute(atr_Version,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessage::ValidVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_Version,AttributeType_Any,false);
	};
}; // end namespace JDF
