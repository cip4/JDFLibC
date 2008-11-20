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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMsgFilter.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMsgFilter : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMsgFilter& JDFAutoMsgFilter::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMsgFilter: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMsgFilter::ValidNodeNames()const{
	return L"*:,MsgFilter";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMsgFilter::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",After,Before,Count,DeviceID,Family,JobID,JobPartID,MessageRefID,MessageID,MessageType,QueueEntryID,ReceiverURL");
};

/**
 typesafe validator
*/
	vWString JDFAutoMsgFilter::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAfter(level)) {
			vAtts.push_back(atr_After);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBefore(level)) {
			vAtts.push_back(atr_Before);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCount(level)) {
			vAtts.push_back(atr_Count);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFamily(level)) {
			vAtts.push_back(atr_Family);
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
		if(!ValidMessageRefID(level)) {
			vAtts.push_back(atr_MessageRefID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMessageID(level)) {
			vAtts.push_back(atr_MessageID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMessageType(level)) {
			vAtts.push_back(atr_MessageType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReceiverURL(level)) {
			vAtts.push_back(atr_ReceiverURL);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute After
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetAfter(JDFDate value){
	SetAttribute(atr_After,value.DateTimeISO());
};
/**
* Get string attribute After
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoMsgFilter::GetAfter() const {
	return GetAttribute(atr_After,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidAfter(EnumValidationLevel level) const {
		return ValidAttribute(atr_After,AttributeType_dateTime,false);
	};
/**
* Set attribute Before
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetBefore(JDFDate value){
	SetAttribute(atr_Before,value.DateTimeISO());
};
/**
* Get string attribute Before
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoMsgFilter::GetBefore() const {
	return GetAttribute(atr_Before,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidBefore(EnumValidationLevel level) const {
		return ValidAttribute(atr_Before,AttributeType_dateTime,false);
	};
/**
* Set attribute Count
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetCount(int value){
	SetAttribute(atr_Count,WString::valueOf(value));
};
/**
* Get integer attribute Count
* @return int the vaue of the attribute 
*/
	 int JDFAutoMsgFilter::GetCount() const {
	return GetIntAttribute(atr_Count,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Count,AttributeType_integer,false);
	};
/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMsgFilter::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_shortString,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMsgFilter::FamilyString(){
		static const WString enums=WString(L"Unknown,Acknowledge,Response,Signal,All");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMsgFilter::FamilyString(EnumFamily value){
		return FamilyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMsgFilter::SetFamily( EnumFamily value){
	SetEnumAttribute(atr_Family,value,FamilyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMsgFilter::EnumFamily JDFAutoMsgFilter:: GetFamily() const {
	return (EnumFamily) GetEnumAttribute(atr_Family,FamilyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidFamily(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Family,FamilyString(),false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMsgFilter::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMsgFilter::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute MessageRefID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetMessageRefID(const WString& value){
	SetAttribute(atr_MessageRefID,value);
};
/**
* Get string attribute MessageRefID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMsgFilter::GetMessageRefID() const {
	return GetAttribute(atr_MessageRefID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidMessageRefID(EnumValidationLevel level) const {
		return ValidAttribute(atr_MessageRefID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute MessageID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetMessageID(const WString& value){
	SetAttribute(atr_MessageID,value);
};
/**
* Get string attribute MessageID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMsgFilter::GetMessageID() const {
	return GetAttribute(atr_MessageID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidMessageID(EnumValidationLevel level) const {
		return ValidAttribute(atr_MessageID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute MessageType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetMessageType(const WString& value){
	SetAttribute(atr_MessageType,value);
};
/**
* Get string attribute MessageType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMsgFilter::GetMessageType() const {
	return GetAttribute(atr_MessageType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidMessageType(EnumValidationLevel level) const {
		return ValidAttribute(atr_MessageType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMsgFilter::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute ReceiverURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMsgFilter::SetReceiverURL(const WString& value){
	SetAttribute(atr_ReceiverURL,value);
};
/**
* Get string attribute ReceiverURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMsgFilter::GetReceiverURL() const {
	return GetAttribute(atr_ReceiverURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMsgFilter::ValidReceiverURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReceiverURL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoMsgFilter::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoMsgFilter::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoMsgFilter::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoMsgFilter::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoMsgFilter::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoMsgFilter::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoMsgFilter::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoMsgFilter::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoMsgFilter::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoMsgFilter::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part";
	};
}; // end namespace JDF
