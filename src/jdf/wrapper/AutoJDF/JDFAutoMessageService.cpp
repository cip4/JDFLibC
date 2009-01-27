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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMessageService.h"
#include "jdf/wrapper/JDFActionPool.h"
#include "jdf/wrapper/JDFDevCapPool.h"
#include "jdf/wrapper/JDFDevCaps.h"
#include "jdf/wrapper/JDFModulePool.h"
#include "jdf/wrapper/JDFTestPool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMessageService : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMessageService& JDFAutoMessageService::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMessageService: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMessageService::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMessageService::ValidNodeNames()const{
	return L"*:,MessageService";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoMessageService::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Type";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMessageService::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Acknowledge,ChannelMode,Command,GenericAttributes,JMFRole,Persistent,Query,Registration,Signal,URLSchemes");
};

/**
 typesafe validator
*/
	vWString JDFAutoMessageService::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAcknowledge(level)) {
			vAtts.push_back(atr_Acknowledge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidChannelMode(level)) {
			vAtts.push_back(atr_ChannelMode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCommand(level)) {
			vAtts.push_back(atr_Command);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGenericAttributes(level)) {
			vAtts.push_back(atr_GenericAttributes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJMFRole(level)) {
			vAtts.push_back(atr_JMFRole);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPersistent(level)) {
			vAtts.push_back(atr_Persistent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQuery(level)) {
			vAtts.push_back(atr_Query);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRegistration(level)) {
			vAtts.push_back(atr_Registration);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSignal(level)) {
			vAtts.push_back(atr_Signal);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURLSchemes(level)) {
			vAtts.push_back(atr_URLSchemes);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Acknowledge
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetAcknowledge(bool value){
	SetAttribute(atr_Acknowledge,WString::valueOf(value));
};
/**
* Get bool attribute Acknowledge
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMessageService::GetAcknowledge() const {return GetBoolAttribute(atr_Acknowledge,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidAcknowledge(EnumValidationLevel level) const {
		return ValidAttribute(atr_Acknowledge,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMessageService::ChannelModeString(){
		static const WString enums=WString(L"Unknown,FireAndForget,Reliable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMessageService::ChannelModeString(EnumChannelMode value){
		return ChannelModeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMessageService::SetChannelMode( EnumChannelMode value){
	SetEnumAttribute(atr_ChannelMode,value,ChannelModeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMessageService::EnumChannelMode JDFAutoMessageService:: GetChannelMode() const {
	return (EnumChannelMode) GetEnumAttribute(atr_ChannelMode,ChannelModeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidChannelMode(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ChannelMode,ChannelModeString(),false);
	};
/**
* Set attribute Command
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetCommand(bool value){
	SetAttribute(atr_Command,WString::valueOf(value));
};
/**
* Get bool attribute Command
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMessageService::GetCommand() const {return GetBoolAttribute(atr_Command,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidCommand(EnumValidationLevel level) const {
		return ValidAttribute(atr_Command,AttributeType_boolean,false);
	};
/**
* Set attribute GenericAttributes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetGenericAttributes(const vWString& value){
	SetAttribute(atr_GenericAttributes,value);
};
/**
* Get string attribute GenericAttributes
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoMessageService::GetGenericAttributes() const {
	return GetAttribute(atr_GenericAttributes,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidGenericAttributes(EnumValidationLevel level) const {
		return ValidAttribute(atr_GenericAttributes,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMessageService::JMFRoleString(){
		static const WString enums=WString(L"Unknown,Receiver,Sender");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMessageService::JMFRoleString(EnumJMFRole value){
		return JMFRoleString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMessageService::SetJMFRole( EnumJMFRole value){
	SetEnumAttribute(atr_JMFRole,value,JMFRoleString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMessageService::EnumJMFRole JDFAutoMessageService:: GetJMFRole() const {
	return (EnumJMFRole) GetEnumAttribute(atr_JMFRole,JMFRoleString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidJMFRole(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_JMFRole,JMFRoleString(),false);
	};
/**
* Set attribute Persistent
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetPersistent(bool value){
	SetAttribute(atr_Persistent,WString::valueOf(value));
};
/**
* Get bool attribute Persistent
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMessageService::GetPersistent() const {return GetBoolAttribute(atr_Persistent,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidPersistent(EnumValidationLevel level) const {
		return ValidAttribute(atr_Persistent,AttributeType_boolean,false);
	};
/**
* Set attribute Query
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetQuery(bool value){
	SetAttribute(atr_Query,WString::valueOf(value));
};
/**
* Get bool attribute Query
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMessageService::GetQuery() const {return GetBoolAttribute(atr_Query,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidQuery(EnumValidationLevel level) const {
		return ValidAttribute(atr_Query,AttributeType_boolean,false);
	};
/**
* Set attribute Registration
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetRegistration(bool value){
	SetAttribute(atr_Registration,WString::valueOf(value));
};
/**
* Get bool attribute Registration
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMessageService::GetRegistration() const {return GetBoolAttribute(atr_Registration,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidRegistration(EnumValidationLevel level) const {
		return ValidAttribute(atr_Registration,AttributeType_boolean,false);
	};
/**
* Set attribute Signal
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetSignal(bool value){
	SetAttribute(atr_Signal,WString::valueOf(value));
};
/**
* Get bool attribute Signal
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMessageService::GetSignal() const {return GetBoolAttribute(atr_Signal,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidSignal(EnumValidationLevel level) const {
		return ValidAttribute(atr_Signal,AttributeType_boolean,false);
	};
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetType(const WString& value){
	SetAttribute(atr_Type,value);
};
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMessageService::GetType() const {
	return GetAttribute(atr_Type,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidType(EnumValidationLevel level) const {
		return ValidAttribute(atr_Type,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute URLSchemes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoMessageService::SetURLSchemes(const vWString& value){
	SetAttribute(atr_URLSchemes,value);
};
/**
* Get string attribute URLSchemes
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoMessageService::GetURLSchemes() const {
	return GetAttribute(atr_URLSchemes,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMessageService::ValidURLSchemes(EnumValidationLevel level) const {
		return ValidAttribute(atr_URLSchemes,AttributeType_NMTOKENS,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFActionPool JDFAutoMessageService::GetActionPool()const{
	JDFActionPool e=GetElement(elm_ActionPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActionPool JDFAutoMessageService::GetCreateActionPool(){
	JDFActionPool e=GetCreateElement(elm_ActionPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActionPool JDFAutoMessageService::AppendActionPool(){
	JDFActionPool e=AppendElementN(elm_ActionPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCapPool JDFAutoMessageService::GetDevCapPool()const{
	JDFDevCapPool e=GetElement(elm_DevCapPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCapPool JDFAutoMessageService::GetCreateDevCapPool(){
	JDFDevCapPool e=GetCreateElement(elm_DevCapPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCapPool JDFAutoMessageService::AppendDevCapPool(){
	JDFDevCapPool e=AppendElementN(elm_DevCapPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCaps JDFAutoMessageService::GetDevCaps(int iSkip)const{
	JDFDevCaps e=GetElement(elm_DevCaps,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCaps JDFAutoMessageService::GetCreateDevCaps(int iSkip){
	JDFDevCaps e=GetCreateElement(elm_DevCaps,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCaps JDFAutoMessageService::AppendDevCaps(){
	JDFDevCaps e=AppendElement(elm_DevCaps);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePool JDFAutoMessageService::GetModulePool()const{
	JDFModulePool e=GetElement(elm_ModulePool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePool JDFAutoMessageService::GetCreateModulePool(){
	JDFModulePool e=GetCreateElement(elm_ModulePool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePool JDFAutoMessageService::AppendModulePool(){
	JDFModulePool e=AppendElementN(elm_ModulePool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoMessageService::GetBooleanState(int iSkip)const{
	JDFBooleanState e=GetElement(elm_BooleanState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoMessageService::GetCreateBooleanState(int iSkip){
	JDFBooleanState e=GetCreateElement(elm_BooleanState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoMessageService::AppendBooleanState(){
	JDFBooleanState e=AppendElement(elm_BooleanState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoMessageService::GetDateTimeState(int iSkip)const{
	JDFDateTimeState e=GetElement(elm_DateTimeState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoMessageService::GetCreateDateTimeState(int iSkip){
	JDFDateTimeState e=GetCreateElement(elm_DateTimeState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoMessageService::AppendDateTimeState(){
	JDFDateTimeState e=AppendElement(elm_DateTimeState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoMessageService::GetDurationState(int iSkip)const{
	JDFDurationState e=GetElement(elm_DurationState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoMessageService::GetCreateDurationState(int iSkip){
	JDFDurationState e=GetCreateElement(elm_DurationState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoMessageService::AppendDurationState(){
	JDFDurationState e=AppendElement(elm_DurationState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoMessageService::GetEnumerationState(int iSkip)const{
	JDFEnumerationState e=GetElement(elm_EnumerationState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoMessageService::GetCreateEnumerationState(int iSkip){
	JDFEnumerationState e=GetCreateElement(elm_EnumerationState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoMessageService::AppendEnumerationState(){
	JDFEnumerationState e=AppendElement(elm_EnumerationState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoMessageService::GetIntegerState(int iSkip)const{
	JDFIntegerState e=GetElement(elm_IntegerState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoMessageService::GetCreateIntegerState(int iSkip){
	JDFIntegerState e=GetCreateElement(elm_IntegerState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoMessageService::AppendIntegerState(){
	JDFIntegerState e=AppendElement(elm_IntegerState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoMessageService::GetMatrixState(int iSkip)const{
	JDFMatrixState e=GetElement(elm_MatrixState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoMessageService::GetCreateMatrixState(int iSkip){
	JDFMatrixState e=GetCreateElement(elm_MatrixState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoMessageService::AppendMatrixState(){
	JDFMatrixState e=AppendElement(elm_MatrixState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoMessageService::GetNameState(int iSkip)const{
	JDFNameState e=GetElement(elm_NameState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoMessageService::GetCreateNameState(int iSkip){
	JDFNameState e=GetCreateElement(elm_NameState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoMessageService::AppendNameState(){
	JDFNameState e=AppendElement(elm_NameState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoMessageService::GetNumberState(int iSkip)const{
	JDFNumberState e=GetElement(elm_NumberState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoMessageService::GetCreateNumberState(int iSkip){
	JDFNumberState e=GetCreateElement(elm_NumberState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoMessageService::AppendNumberState(){
	JDFNumberState e=AppendElement(elm_NumberState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoMessageService::GetPDFPathState(int iSkip)const{
	JDFPDFPathState e=GetElement(elm_PDFPathState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoMessageService::GetCreatePDFPathState(int iSkip){
	JDFPDFPathState e=GetCreateElement(elm_PDFPathState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoMessageService::AppendPDFPathState(){
	JDFPDFPathState e=AppendElement(elm_PDFPathState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoMessageService::GetRectangleState(int iSkip)const{
	JDFRectangleState e=GetElement(elm_RectangleState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoMessageService::GetCreateRectangleState(int iSkip){
	JDFRectangleState e=GetCreateElement(elm_RectangleState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoMessageService::AppendRectangleState(){
	JDFRectangleState e=AppendElement(elm_RectangleState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoMessageService::GetShapeState(int iSkip)const{
	JDFShapeState e=GetElement(elm_ShapeState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoMessageService::GetCreateShapeState(int iSkip){
	JDFShapeState e=GetCreateElement(elm_ShapeState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoMessageService::AppendShapeState(){
	JDFShapeState e=AppendElement(elm_ShapeState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoMessageService::GetStringState(int iSkip)const{
	JDFStringState e=GetElement(elm_StringState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoMessageService::GetCreateStringState(int iSkip){
	JDFStringState e=GetCreateElement(elm_StringState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoMessageService::AppendStringState(){
	JDFStringState e=AppendElement(elm_StringState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoMessageService::GetXYPairState(int iSkip)const{
	JDFXYPairState e=GetElement(elm_XYPairState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoMessageService::GetCreateXYPairState(int iSkip){
	JDFXYPairState e=GetCreateElement(elm_XYPairState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoMessageService::AppendXYPairState(){
	JDFXYPairState e=AppendElement(elm_XYPairState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoMessageService::GetTestPool()const{
	JDFTestPool e=GetElement(elm_TestPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoMessageService::GetCreateTestPool(){
	JDFTestPool e=GetCreateElement(elm_TestPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoMessageService::AppendTestPool(){
	JDFTestPool e=AppendElementN(elm_TestPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoMessageService::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ActionPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ActionPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetActionPool().IsValid(level)) {
				vElem.AppendUnique(elm_ActionPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_DevCapPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DevCapPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDevCapPool().IsValid(level)) {
				vElem.AppendUnique(elm_DevCapPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_DevCaps);

		for(i=0;i<nElem;i++){
			if (!GetDevCaps(i).IsValid(level)) {
				vElem.AppendUnique(elm_DevCaps);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ModulePool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ModulePool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetModulePool().IsValid(level)) {
				vElem.AppendUnique(elm_ModulePool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_BooleanState);

		for(i=0;i<nElem;i++){
			if (!GetBooleanState(i).IsValid(level)) {
				vElem.AppendUnique(elm_BooleanState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DateTimeState);

		for(i=0;i<nElem;i++){
			if (!GetDateTimeState(i).IsValid(level)) {
				vElem.AppendUnique(elm_DateTimeState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DurationState);

		for(i=0;i<nElem;i++){
			if (!GetDurationState(i).IsValid(level)) {
				vElem.AppendUnique(elm_DurationState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_EnumerationState);

		for(i=0;i<nElem;i++){
			if (!GetEnumerationState(i).IsValid(level)) {
				vElem.AppendUnique(elm_EnumerationState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IntegerState);

		for(i=0;i<nElem;i++){
			if (!GetIntegerState(i).IsValid(level)) {
				vElem.AppendUnique(elm_IntegerState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MatrixState);

		for(i=0;i<nElem;i++){
			if (!GetMatrixState(i).IsValid(level)) {
				vElem.AppendUnique(elm_MatrixState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_NameState);

		for(i=0;i<nElem;i++){
			if (!GetNameState(i).IsValid(level)) {
				vElem.AppendUnique(elm_NameState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_NumberState);

		for(i=0;i<nElem;i++){
			if (!GetNumberState(i).IsValid(level)) {
				vElem.AppendUnique(elm_NumberState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PDFPathState);

		for(i=0;i<nElem;i++){
			if (!GetPDFPathState(i).IsValid(level)) {
				vElem.AppendUnique(elm_PDFPathState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RectangleState);

		for(i=0;i<nElem;i++){
			if (!GetRectangleState(i).IsValid(level)) {
				vElem.AppendUnique(elm_RectangleState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ShapeState);

		for(i=0;i<nElem;i++){
			if (!GetShapeState(i).IsValid(level)) {
				vElem.AppendUnique(elm_ShapeState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StringState);

		for(i=0;i<nElem;i++){
			if (!GetStringState(i).IsValid(level)) {
				vElem.AppendUnique(elm_StringState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_XYPairState);

		for(i=0;i<nElem;i++){
			if (!GetXYPairState(i).IsValid(level)) {
				vElem.AppendUnique(elm_XYPairState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TestPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TestPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTestPool().IsValid(level)) {
				vElem.AppendUnique(elm_TestPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoMessageService::UniqueElements()const{
		return JDFElement::UniqueElements()+L",ActionPool,DevCapPool,ModulePool,TestPool";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoMessageService::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ActionPool,DevCapPool,DevCaps,ModulePool,BooleanState,DateTimeState,DurationState,EnumerationState,IntegerState,MatrixState,NameState,NumberState,PDFPathState,RectangleState,ShapeState,StringState,XYPairState,TestPool";
	};
}; // end namespace JDF
