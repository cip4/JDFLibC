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

 
#include "jdf/wrapper/AutoJDF/JDFAutoQueue.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFQueueEntry.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoQueue : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoQueue& JDFAutoQueue::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoQueue: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoQueue::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoQueue::ValidNodeNames()const{
	return L"*:,Queue";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoQueue::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Status,DeviceID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoQueue::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",QueueSize");
};

/**
 typesafe validator
*/
	vWString JDFAutoQueue::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueSize(level)) {
			vAtts.push_back(atr_QueueSize);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoQueue::StatusString(){
		static const WString enums=WString(L"Unknown,Blocked,Closed,Full,Running,Waiting,Held");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoQueue::StatusString(EnumStatus value){
		return StatusString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueue::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoQueue::EnumStatus JDFAutoQueue:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueue::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),RequiredLevel(level));
	};
/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueue::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueue::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueue::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_shortString,RequiredLevel(level));
	};
/**
* Set attribute QueueSize
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQueue::SetQueueSize(int value){
	SetAttribute(atr_QueueSize,WString::valueOf(value));
};
/**
* Get integer attribute QueueSize
* @return int the vaue of the attribute 
*/
	 int JDFAutoQueue::GetQueueSize() const {
	return GetIntAttribute(atr_QueueSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueue::ValidQueueSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueSize,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDevice JDFAutoQueue::GetDevice(int iSkip)const{
	JDFDevice e=GetElement(elm_Device,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoQueue::GetCreateDevice(int iSkip){
	JDFDevice e=GetCreateElement(elm_Device,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoQueue::AppendDevice(){
	JDFDevice e=AppendElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoQueue::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFQueueEntry JDFAutoQueue::GetQueueEntry(int iSkip)const{
	JDFQueueEntry e=GetElement(elm_QueueEntry,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQueueEntry JDFAutoQueue::GetCreateQueueEntry(int iSkip){
	JDFQueueEntry e=GetCreateElement(elm_QueueEntry,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQueueEntry JDFAutoQueue::AppendQueueEntry(){
	JDFQueueEntry e=AppendElement(elm_QueueEntry);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoQueue::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Device);

		for(i=0;i<nElem;i++){
			if (!GetDevice(i).IsValid(level)) {
				vElem.AppendUnique(elm_Device);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_QueueEntry);

		for(i=0;i<nElem;i++){
			if (!GetQueueEntry(i).IsValid(level)) {
				vElem.AppendUnique(elm_QueueEntry);
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
	WString JDFAutoQueue::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Device,QueueEntry";
	};
}; // end namespace JDF
