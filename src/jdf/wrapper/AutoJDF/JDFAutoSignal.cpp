/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSignal.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFNotification.h"
#include "jdf/wrapper/JDFTrigger.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSignal : public JDFMessage

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSignal& JDFAutoSignal::operator=(const KElement& other){
	KElement::operator=(other);
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSignal::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSignal::ValidNodeNames()const{
	return L"*:,Signal";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoSignal::OptionalAttributes()const{
		return JDFMessage::OptionalAttributes()+WString(L",ChannelMode,LastRepeat,refID");
};

/**
 typesafe validator
*/
	vWString JDFAutoSignal::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFMessage::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidChannelMode(level)) {
			vAtts.push_back(atr_ChannelMode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLastRepeat(level)) {
			vAtts.push_back(atr_LastRepeat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidrefID(level)) {
			vAtts.push_back(atr_refID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSignal::ChannelModeString(){
		static const WString enums=WString(L"Unknown,FireAndForget,Reliable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSignal::ChannelModeString(EnumChannelMode value){
		return ChannelModeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSignal::SetChannelMode( EnumChannelMode value){
	SetEnumAttribute(atr_ChannelMode,value,ChannelModeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSignal::EnumChannelMode JDFAutoSignal:: GetChannelMode() const {
	return (EnumChannelMode) GetEnumAttribute(atr_ChannelMode,ChannelModeString(),WString::emptyStr,ChannelMode_FireAndForget);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignal::ValidChannelMode(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ChannelMode,ChannelModeString(),false);
	};
/**
* Set attribute LastRepeat
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoSignal::SetLastRepeat(bool value){
	SetAttribute(atr_LastRepeat,WString::valueOf(value));
};
/**
* Get bool attribute LastRepeat
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoSignal::GetLastRepeat() const {return GetBoolAttribute(atr_LastRepeat,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignal::ValidLastRepeat(EnumValidationLevel level) const {
		return ValidAttribute(atr_LastRepeat,AttributeType_boolean,false);
	};
/**
* Set attribute refID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSignal::SetrefID(const WString& value){
	SetAttribute(atr_refID,value);
};
/**
* Get string attribute refID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSignal::GetrefID() const {
	return GetAttribute(atr_refID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSignal::ValidrefID(EnumValidationLevel level) const {
		return ValidAttribute(atr_refID,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFEmployee JDFAutoSignal::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoSignal::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoSignal::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNotification JDFAutoSignal::GetNotification(int iSkip)const{
	JDFNotification e=GetElement(elm_Notification,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNotification JDFAutoSignal::GetCreateNotification(int iSkip){
	JDFNotification e=GetCreateElement(elm_Notification,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNotification JDFAutoSignal::AppendNotification(){
	JDFNotification e=AppendElement(elm_Notification);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrigger JDFAutoSignal::GetTrigger(int iSkip)const{
	JDFTrigger e=GetElement(elm_Trigger,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrigger JDFAutoSignal::GetCreateTrigger(int iSkip){
	JDFTrigger e=GetCreateElement(elm_Trigger,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrigger JDFAutoSignal::AppendTrigger(){
	JDFTrigger e=AppendElement(elm_Trigger);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoSignal::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFMessage::GetInvalidElements(level, bIgnorePrivate, nMax);
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
		nElem=NumChildElements(elm_Notification);

		for(i=0;i<nElem;i++){
			if (!GetNotification(i).IsValid(level)) {
				vElem.AppendUnique(elm_Notification);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Trigger);

		for(i=0;i<nElem;i++){
			if (!GetTrigger(i).IsValid(level)) {
				vElem.AppendUnique(elm_Trigger);
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
	WString JDFAutoSignal::OptionalElements()const{
		return JDFMessage::OptionalElements()+L",Employee,Notification,Trigger";
	};
}; // end namespace JDF
