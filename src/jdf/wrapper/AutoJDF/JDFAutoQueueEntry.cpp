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

 
#include "jdf/wrapper/AutoJDF/JDFAutoQueueEntry.h"
#include "jdf/wrapper/JDFJobPhase.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFPreview.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoQueueEntry : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoQueueEntry& JDFAutoQueueEntry::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoQueueEntry: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoQueueEntry::ValidNodeNames()const{
	return L"*:,QueueEntry";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoQueueEntry::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",QueueEntryID,Status";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoQueueEntry::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",DeviceID,EndTime,GangName,JobID,JobPartID,Priority,StartTime,SubmissionTime");
};

/**
 typesafe validator
*/
	vWString JDFAutoQueueEntry::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEndTime(level)) {
			vAtts.push_back(atr_EndTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGangName(level)) {
			vAtts.push_back(atr_GangName);
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
		if(!ValidPriority(level)) {
			vAtts.push_back(atr_Priority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStartTime(level)) {
			vAtts.push_back(atr_StartTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSubmissionTime(level)) {
			vAtts.push_back(atr_SubmissionTime);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueEntry::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_shortString,false);
	};
/**
* Set attribute EndTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetEndTime(JDFDate value){
	SetAttribute(atr_EndTime,value.DateTimeISO());
};
/**
* Get string attribute EndTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoQueueEntry::GetEndTime() const {
	return GetAttribute(atr_EndTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidEndTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_EndTime,AttributeType_dateTime,false);
	};
/**
* Set attribute GangName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetGangName(const WString& value){
	SetAttribute(atr_GangName,value);
};
/**
* Get string attribute GangName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueEntry::GetGangName() const {
	return GetAttribute(atr_GangName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidGangName(EnumValidationLevel level) const {
		return ValidAttribute(atr_GangName,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueEntry::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueEntry::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetPriority(int value){
	SetAttribute(atr_Priority,WString::valueOf(value));
};
/**
* Get integer attribute Priority
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoQueueEntry::GetPriority() const {
	return GetIntAttribute(atr_Priority,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_Priority,AttributeType_integer,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueEntry::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoQueueEntry::StatusString(){
		static const WString enums=WString(L"Unknown,Running,Waiting,Held,Removed,Suspended,PendingReturn,Completed,Aborted");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoQueueEntry::StatusString(EnumStatus value){
		return StatusString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueueEntry::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoQueueEntry::EnumStatus JDFAutoQueueEntry:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),RequiredLevel(level));
	};
/**
* Set attribute StartTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetStartTime(JDFDate value){
	SetAttribute(atr_StartTime,value.DateTimeISO());
};
/**
* Get string attribute StartTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoQueueEntry::GetStartTime() const {
	return GetAttribute(atr_StartTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidStartTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartTime,AttributeType_dateTime,false);
	};
/**
* Set attribute SubmissionTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoQueueEntry::SetSubmissionTime(JDFDate value){
	SetAttribute(atr_SubmissionTime,value.DateTimeISO());
};
/**
* Get string attribute SubmissionTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoQueueEntry::GetSubmissionTime() const {
	return GetAttribute(atr_SubmissionTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueEntry::ValidSubmissionTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_SubmissionTime,AttributeType_dateTime,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFJobPhase JDFAutoQueueEntry::GetJobPhase()const{
	JDFJobPhase e=GetElement(elm_JobPhase);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobPhase JDFAutoQueueEntry::GetCreateJobPhase(){
	JDFJobPhase e=GetCreateElement(elm_JobPhase);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobPhase JDFAutoQueueEntry::AppendJobPhase(){
	JDFJobPhase e=AppendElementN(elm_JobPhase,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoQueueEntry::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoQueueEntry::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoQueueEntry::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoQueueEntry::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoQueueEntry::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoQueueEntry::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoQueueEntry::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoQueueEntry::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

JDFPreview JDFAutoQueueEntry::GetPreview(int iSkip)const{
	JDFPreview e=GetElement(elm_Preview,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreview JDFAutoQueueEntry::GetCreatePreview(int iSkip){
	JDFPreview e=GetCreateElement(elm_Preview,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreview JDFAutoQueueEntry::AppendPreview(){
	JDFPreview e=AppendElement(elm_Preview);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoQueueEntry::RefPreview(JDFPreview& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoQueueEntry::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_JobPhase);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_JobPhase);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetJobPhase().IsValid(level)) {
				vElem.AppendUnique(elm_JobPhase);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Preview);

		for(i=0;i<nElem;i++){
			if (!GetPreview(i).IsValid(level)) {
				vElem.AppendUnique(elm_Preview);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoQueueEntry::UniqueElements()const{
		return JDFElement::UniqueElements()+L",JobPhase";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoQueueEntry::OptionalElements()const{
		return JDFElement::OptionalElements()+L",JobPhase,Part,Preview";
	};
}; // end namespace JDF
