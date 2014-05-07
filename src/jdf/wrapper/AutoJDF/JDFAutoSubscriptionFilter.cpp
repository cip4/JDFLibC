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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSubscriptionFilter.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSubscriptionFilter : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSubscriptionFilter& JDFAutoSubscriptionFilter::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSubscriptionFilter: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSubscriptionFilter::ValidNodeNames()const{
	return L"*:,SubscriptionFilter";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoSubscriptionFilter::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ChannelID,DeviceID,Families,JobID,JobPartID,MessageTypes,QueueEntryID,URL");
};

/**
 typesafe validator
*/
	vWString JDFAutoSubscriptionFilter::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidChannelID(level)) {
			vAtts.push_back(atr_ChannelID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFamilies(level)) {
			vAtts.push_back(atr_Families);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobPartID(level)) {
			vAtts.push_back(atr_JobPartID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMessageTypes(level)) {
			vAtts.push_back(atr_MessageTypes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
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

/**
* Set attribute ChannelID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscriptionFilter::SetChannelID(const WString& value){
	SetAttribute(atr_ChannelID,value);
};
/**
* Get string attribute ChannelID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscriptionFilter::GetChannelID() const {
	return GetAttribute(atr_ChannelID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::ValidChannelID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ChannelID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscriptionFilter::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscriptionFilter::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_string,false);
	};
/**
* Set attribute Families
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoSubscriptionFilter::SetFamilies(const vWString& value){
	SetAttribute(atr_Families,value);
};
/**
* Get string attribute Families
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoSubscriptionFilter::GetFamilies() const {
	return GetAttribute(atr_Families,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::ValidFamilies(EnumValidationLevel level) const {
		return ValidAttribute(atr_Families,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscriptionFilter::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscriptionFilter::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_string,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscriptionFilter::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscriptionFilter::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_string,false);
	};
/**
* Set attribute MessageTypes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoSubscriptionFilter::SetMessageTypes(const vWString& value){
	SetAttribute(atr_MessageTypes,value);
};
/**
* Get string attribute MessageTypes
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoSubscriptionFilter::GetMessageTypes() const {
	return GetAttribute(atr_MessageTypes,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::ValidMessageTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_MessageTypes,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscriptionFilter::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscriptionFilter::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_string,false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSubscriptionFilter::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSubscriptionFilter::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSubscriptionFilter::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoSubscriptionFilter::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoSubscriptionFilter::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoSubscriptionFilter::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoSubscriptionFilter::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoSubscriptionFilter::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoSubscriptionFilter::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoSubscriptionFilter::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoSubscriptionFilter::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoSubscriptionFilter::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoSubscriptionFilter::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part";
	};
}; // end namespace JDF
