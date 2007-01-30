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

 
#include "jdf/wrapper/AutoJDF/JDFAutoNotificationFilter.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoNotificationFilter : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoNotificationFilter& JDFAutoNotificationFilter::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoNotificationFilter: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoNotificationFilter::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoNotificationFilter::ValidNodeNames()const{
	return L"*:,NotificationFilter";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoNotificationFilter::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",DeviceID,JobID,JobPartID,QueueEntryID,SignalTypes,Types,Classes");
};

/**
 typesafe validator
*/
	vWString JDFAutoNotificationFilter::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
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
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSignalTypes(level)) {
			vAtts.push_back(atr_SignalTypes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTypes(level)) {
			vAtts.push_back(atr_Types);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClasses(level)) {
			vAtts.push_back(atr_Classes);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotificationFilter::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotificationFilter::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotificationFilter::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_shortString,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotificationFilter::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotificationFilter::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotificationFilter::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotificationFilter::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotificationFilter::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotificationFilter::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotificationFilter::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotificationFilter::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotificationFilter::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute SignalTypes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoNotificationFilter::SetSignalTypes(const vWString& value){
	SetAttribute(atr_SignalTypes,value);
};
/**
* Get string attribute SignalTypes
* @return vWString the vaue of the attribute ; defaults to Notification
*/
	 vWString JDFAutoNotificationFilter::GetSignalTypes() const {
	return GetAttribute(atr_SignalTypes,WString::emptyStr,L"Notification");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotificationFilter::ValidSignalTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_SignalTypes,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Types
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoNotificationFilter::SetTypes(const vWString& value){
	SetAttribute(atr_Types,value);
};
/**
* Get string attribute Types
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoNotificationFilter::GetTypes() const {
	return GetAttribute(atr_Types,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotificationFilter::ValidTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_Types,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoNotificationFilter::ClassesString(){
		static const WString enums=WString(L"Unknown,Event,Information,Warning,Error,Fatal");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoNotificationFilter::ClassesString(EnumClasses value){
		return ClassesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoNotificationFilter::AddClasses( EnumClasses value){
	return AddEnumerationsAttribute(atr_Classes,value,ClassesString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoNotificationFilter::RemoveClasses( EnumClasses value){
	return RemoveEnumerationsAttribute(atr_Classes,value,ClassesString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoNotificationFilter::GetClasses() const {
	return GetEnumerationsAttribute(atr_Classes,ClassesString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoNotificationFilter::SetClasses( EnumClasses value){
	SetEnumAttribute(atr_Classes,value,ClassesString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoNotificationFilter::SetClasses( const vint& value){
	SetEnumerationsAttribute(atr_Classes,value,ClassesString());
};
/**
* Typesafe attribute validation of Classes
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotificationFilter::ValidClasses(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_Classes,ClassesString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoNotificationFilter::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoNotificationFilter::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoNotificationFilter::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoNotificationFilter::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoNotificationFilter::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoNotificationFilter::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoNotificationFilter::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoNotificationFilter::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoNotificationFilter::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoNotificationFilter::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part";
	};
}; // end namespace JDF
