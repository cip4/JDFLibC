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

 
#include "jdf/wrapper/AutoJDF/JDFAutoJMF.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFCommand.h"
#include "jdf/wrapper/JDFAcknowledge.h"
#include "jdf/wrapper/JDFResponse.h"
#include "jdf/wrapper/JDFSignal.h"
#include "jdf/wrapper/JDFQuery.h"
#include "jdf/wrapper/JDFRegistration.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoJMF : public JDFPool

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoJMF& JDFAutoJMF::operator=(const KElement& other){
	KElement::operator=(other);
	return *this;
};

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoJMF::ValidNodeNames()const{
	return L"*:,JMF";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoJMF::RequiredAttributes()const{
		return JDFPool::RequiredAttributes()+L",SenderID,TimeStamp,Version";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoJMF::OptionalAttributes()const{
		return JDFPool::OptionalAttributes()+WString(L",AgentName,AgentVersion,DeviceID,ICSVersions,MaxVersion,ResponseURL");
};

/**
 typesafe validator
*/
	vWString JDFAutoJMF::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFPool::GetInvalidAttributes(level,bIgnorePrivate,nMax);
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
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidICSVersions(level)) {
			vAtts.push_back(atr_ICSVersions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxVersion(level)) {
			vAtts.push_back(atr_MaxVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResponseURL(level)) {
			vAtts.push_back(atr_ResponseURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSenderID(level)) {
			vAtts.push_back(atr_SenderID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTimeStamp(level)) {
			vAtts.push_back(atr_TimeStamp);
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
	 void JDFAutoJMF::SetAgentName(const WString& value){
	SetAttribute(atr_AgentName,value);
};
/**
* Get string attribute AgentName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJMF::GetAgentName() const {
	return GetAttribute(atr_AgentName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidAgentName(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentName,AttributeType_string,false);
	};
/**
* Set attribute AgentVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJMF::SetAgentVersion(const WString& value){
	SetAttribute(atr_AgentVersion,value);
};
/**
* Get string attribute AgentVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJMF::GetAgentVersion() const {
	return GetAttribute(atr_AgentVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidAgentVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentVersion,AttributeType_string,false);
	};
/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJMF::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJMF::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_shortString,false);
	};
/**
* Set attribute ICSVersions
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoJMF::SetICSVersions(const vWString& value){
	SetAttribute(atr_ICSVersions,value);
};
/**
* Get string attribute ICSVersions
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoJMF::GetICSVersions() const {
	return GetAttribute(atr_ICSVersions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidICSVersions(EnumValidationLevel level) const {
		return ValidAttribute(atr_ICSVersions,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute MaxVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJMF::SetMaxVersion(const WString& value){
	SetAttribute(atr_MaxVersion,value);
};
/**
* Get string attribute MaxVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJMF::GetMaxVersion() const {
	return GetAttribute(atr_MaxVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidMaxVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxVersion,AttributeType_Any,false);
	};
/**
* Set attribute ResponseURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJMF::SetResponseURL(const WString& value){
	SetAttribute(atr_ResponseURL,value);
};
/**
* Get string attribute ResponseURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJMF::GetResponseURL() const {
	return GetAttribute(atr_ResponseURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidResponseURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResponseURL,AttributeType_URL,false);
	};
/**
* Set attribute SenderID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJMF::SetSenderID(const WString& value){
	SetAttribute(atr_SenderID,value);
};
/**
* Get string attribute SenderID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJMF::GetSenderID() const {
	return GetAttribute(atr_SenderID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidSenderID(EnumValidationLevel level) const {
		return ValidAttribute(atr_SenderID,AttributeType_shortString,RequiredLevel(level));
	};
/**
* Set attribute TimeStamp
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoJMF::SetTimeStamp(JDFDate value){
	SetAttribute(atr_TimeStamp,value.DateTimeISO());
};
/**
* Get string attribute TimeStamp
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoJMF::GetTimeStamp() const {
	return GetAttribute(atr_TimeStamp,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidTimeStamp(EnumValidationLevel level) const {
		return ValidAttribute(atr_TimeStamp,AttributeType_dateTime,RequiredLevel(level));
	};
/**
* Set attribute Version
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJMF::SetVersion(const WString& value){
	SetAttribute(atr_Version,value);
};
/**
* Get string attribute Version
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJMF::GetVersion() const {
	return GetAttribute(atr_Version,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJMF::ValidVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_Version,AttributeType_Any,RequiredLevel(level));
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFEmployee JDFAutoJMF::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoJMF::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoJMF::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCommand JDFAutoJMF::GetCommand(int iSkip)const{
	JDFCommand e=GetElement(elm_Command,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCommand JDFAutoJMF::GetCreateCommand(int iSkip){
	JDFCommand e=GetCreateElement(elm_Command,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCommand JDFAutoJMF::AppendCommand(){
	JDFCommand e=AppendElement(elm_Command);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAcknowledge JDFAutoJMF::GetAcknowledge(int iSkip)const{
	JDFAcknowledge e=GetElement(elm_Acknowledge,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAcknowledge JDFAutoJMF::GetCreateAcknowledge(int iSkip){
	JDFAcknowledge e=GetCreateElement(elm_Acknowledge,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAcknowledge JDFAutoJMF::AppendAcknowledge(){
	JDFAcknowledge e=AppendElement(elm_Acknowledge);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFResponse JDFAutoJMF::GetResponse(int iSkip)const{
	JDFResponse e=GetElement(elm_Response,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFResponse JDFAutoJMF::GetCreateResponse(int iSkip){
	JDFResponse e=GetCreateElement(elm_Response,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFResponse JDFAutoJMF::AppendResponse(){
	JDFResponse e=AppendElement(elm_Response);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSignal JDFAutoJMF::GetSignal(int iSkip)const{
	JDFSignal e=GetElement(elm_Signal,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSignal JDFAutoJMF::GetCreateSignal(int iSkip){
	JDFSignal e=GetCreateElement(elm_Signal,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSignal JDFAutoJMF::AppendSignal(){
	JDFSignal e=AppendElement(elm_Signal);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQuery JDFAutoJMF::GetQuery(int iSkip)const{
	JDFQuery e=GetElement(elm_Query,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQuery JDFAutoJMF::GetCreateQuery(int iSkip){
	JDFQuery e=GetCreateElement(elm_Query,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQuery JDFAutoJMF::AppendQuery(){
	JDFQuery e=AppendElement(elm_Query);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegistration JDFAutoJMF::GetRegistration(int iSkip)const{
	JDFRegistration e=GetElement(elm_Registration,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegistration JDFAutoJMF::GetCreateRegistration(int iSkip){
	JDFRegistration e=GetCreateElement(elm_Registration,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegistration JDFAutoJMF::AppendRegistration(){
	JDFRegistration e=AppendElement(elm_Registration);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoJMF::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFPool::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Employee);

		for(i=0;i<nElem;i++){
			if (!GetEmployee(i).IsValid(level)) {
				vElem.AppendUnique(elm_Employee);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Command);

		for(i=0;i<nElem;i++){
			if (!GetCommand(i).IsValid(level)) {
				vElem.AppendUnique(elm_Command);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Acknowledge);

		for(i=0;i<nElem;i++){
			if (!GetAcknowledge(i).IsValid(level)) {
				vElem.AppendUnique(elm_Acknowledge);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Response);

		for(i=0;i<nElem;i++){
			if (!GetResponse(i).IsValid(level)) {
				vElem.AppendUnique(elm_Response);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Signal);

		for(i=0;i<nElem;i++){
			if (!GetSignal(i).IsValid(level)) {
				vElem.AppendUnique(elm_Signal);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Query);

		for(i=0;i<nElem;i++){
			if (!GetQuery(i).IsValid(level)) {
				vElem.AppendUnique(elm_Query);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Registration);

		for(i=0;i<nElem;i++){
			if (!GetRegistration(i).IsValid(level)) {
				vElem.AppendUnique(elm_Registration);
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
	WString JDFAutoJMF::OptionalElements()const{
		return JDFPool::OptionalElements()+L",Employee,Command,Acknowledge,Response,Signal,Query,Registration";
	};
}; // end namespace JDF
