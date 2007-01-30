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

 
#include "jdf/wrapper/AutoJDF/JDFAutoStatusQuParams.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoStatusQuParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoStatusQuParams& JDFAutoStatusQuParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoStatusQuParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoStatusQuParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoStatusQuParams::ValidNodeNames()const{
	return L"*:,StatusQuParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoStatusQuParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",DeviceDetails,EmployeeInfo,JobDetails,JobID,JobPartID,QueueEntryID,QueueInfo");
};

/**
 typesafe validator
*/
	vWString JDFAutoStatusQuParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDeviceDetails(level)) {
			vAtts.push_back(atr_DeviceDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmployeeInfo(level)) {
			vAtts.push_back(atr_EmployeeInfo);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobDetails(level)) {
			vAtts.push_back(atr_JobDetails);
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
		if(!ValidQueueInfo(level)) {
			vAtts.push_back(atr_QueueInfo);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStatusQuParams::DeviceDetailsString(){
		static const WString enums=WString(L"Unknown,None,Brief,Modules,Details,Capability,Full");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStatusQuParams::DeviceDetailsString(EnumDeviceDetails value){
		return DeviceDetailsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStatusQuParams::SetDeviceDetails( EnumDeviceDetails value){
	SetEnumAttribute(atr_DeviceDetails,value,DeviceDetailsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStatusQuParams::EnumDeviceDetails JDFAutoStatusQuParams:: GetDeviceDetails() const {
	return (EnumDeviceDetails) GetEnumAttribute(atr_DeviceDetails,DeviceDetailsString(),WString::emptyStr,DeviceDetails_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStatusQuParams::ValidDeviceDetails(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DeviceDetails,DeviceDetailsString(),false);
	};
/**
* Set attribute EmployeeInfo
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoStatusQuParams::SetEmployeeInfo(bool value){
	SetAttribute(atr_EmployeeInfo,WString::valueOf(value));
};
/**
* Get bool attribute EmployeeInfo
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoStatusQuParams::GetEmployeeInfo() const {return GetBoolAttribute(atr_EmployeeInfo,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStatusQuParams::ValidEmployeeInfo(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmployeeInfo,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStatusQuParams::JobDetailsString(){
		static const WString enums=WString(L"Unknown,None,MIS,Brief,Full");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStatusQuParams::JobDetailsString(EnumJobDetails value){
		return JobDetailsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStatusQuParams::SetJobDetails( EnumJobDetails value){
	SetEnumAttribute(atr_JobDetails,value,JobDetailsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStatusQuParams::EnumJobDetails JDFAutoStatusQuParams:: GetJobDetails() const {
	return (EnumJobDetails) GetEnumAttribute(atr_JobDetails,JobDetailsString(),WString::emptyStr,JobDetails_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStatusQuParams::ValidJobDetails(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_JobDetails,JobDetailsString(),false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStatusQuParams::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStatusQuParams::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStatusQuParams::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStatusQuParams::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStatusQuParams::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStatusQuParams::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStatusQuParams::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStatusQuParams::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStatusQuParams::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute QueueInfo
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoStatusQuParams::SetQueueInfo(bool value){
	SetAttribute(atr_QueueInfo,WString::valueOf(value));
};
/**
* Get bool attribute QueueInfo
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoStatusQuParams::GetQueueInfo() const {return GetBoolAttribute(atr_QueueInfo,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStatusQuParams::ValidQueueInfo(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueInfo,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoStatusQuParams::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoStatusQuParams::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoStatusQuParams::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoStatusQuParams::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoStatusQuParams::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoStatusQuParams::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoStatusQuParams::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoStatusQuParams::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoStatusQuParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoStatusQuParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part";
	};
}; // end namespace JDF
