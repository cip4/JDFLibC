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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDeviceCap.h"
#include "jdf/wrapper/JDFActionPool.h"
#include "jdf/wrapper/JDFDevCapPool.h"
#include "jdf/wrapper/JDFDevCaps.h"
#include "jdf/wrapper/JDFDisplayGroupPool.h"
#include "jdf/wrapper/JDFFeaturePool.h"
#include "jdf/wrapper/JDFMacroPool.h"
#include "jdf/wrapper/JDFModulePool.h"
#include "jdf/wrapper/JDFPerformance.h"
#include "jdf/wrapper/JDFTestPool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDeviceCap : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDeviceCap& JDFAutoDeviceCap::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDeviceCap: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDeviceCap::ValidNodeNames()const{
	return L"*:,DeviceCap";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDeviceCap::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CombinedMethod,ExecutionPolicy,GenericAttributes,Lang,OptionalCombinedTypes,Type,TypeExpression,TypeOrder,Types");
};

/**
 typesafe validator
*/
	vWString JDFAutoDeviceCap::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCombinedMethod(level)) {
			vAtts.push_back(atr_CombinedMethod);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidExecutionPolicy(level)) {
			vAtts.push_back(atr_ExecutionPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGenericAttributes(level)) {
			vAtts.push_back(atr_GenericAttributes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLang(level)) {
			vAtts.push_back(atr_Lang);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOptionalCombinedTypes(level)) {
			vAtts.push_back(atr_OptionalCombinedTypes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTypeExpression(level)) {
			vAtts.push_back(atr_TypeExpression);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTypeOrder(level)) {
			vAtts.push_back(atr_TypeOrder);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTypes(level)) {
			vAtts.push_back(atr_Types);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeviceCap::CombinedMethodString(){
		static const WString enums=WString(L"Unknown,Combined,CombinedProcessGroup,GrayBox,ProcessGroup,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeviceCap::CombinedMethodString(EnumCombinedMethod value){
		return CombinedMethodString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoDeviceCap::AddCombinedMethod( EnumCombinedMethod value){
	return AddEnumerationsAttribute(atr_CombinedMethod,value,CombinedMethodString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoDeviceCap::RemoveCombinedMethod( EnumCombinedMethod value){
	return RemoveEnumerationsAttribute(atr_CombinedMethod,value,CombinedMethodString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoDeviceCap::GetCombinedMethod() const {
	return GetEnumerationsAttribute(atr_CombinedMethod,CombinedMethodString(),WString::emptyStr,(unsigned int)CombinedMethod_None);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceCap::SetCombinedMethod( EnumCombinedMethod value){
	SetEnumAttribute(atr_CombinedMethod,value,CombinedMethodString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceCap::SetCombinedMethod( const vint& value){
	SetEnumerationsAttribute(atr_CombinedMethod,value,CombinedMethodString());
};
/**
* Typesafe attribute validation of CombinedMethod
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidCombinedMethod(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_CombinedMethod,CombinedMethodString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeviceCap::ExecutionPolicyString(){
		static const WString enums=WString(L"Unknown,RootNode,FirstFound,AllFound");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeviceCap::ExecutionPolicyString(EnumExecutionPolicy value){
		return ExecutionPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceCap::SetExecutionPolicy( EnumExecutionPolicy value){
	SetEnumAttribute(atr_ExecutionPolicy,value,ExecutionPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeviceCap::EnumExecutionPolicy JDFAutoDeviceCap:: GetExecutionPolicy() const {
	return (EnumExecutionPolicy) GetEnumAttribute(atr_ExecutionPolicy,ExecutionPolicyString(),WString::emptyStr,ExecutionPolicy_AllFound);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidExecutionPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ExecutionPolicy,ExecutionPolicyString(),false);
	};
/**
* Set attribute GenericAttributes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDeviceCap::SetGenericAttributes(const vWString& value){
	SetAttribute(atr_GenericAttributes,value);
};
/**
* Get string attribute GenericAttributes
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDeviceCap::GetGenericAttributes() const {
	return GetAttribute(atr_GenericAttributes,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidGenericAttributes(EnumValidationLevel level) const {
		return ValidAttribute(atr_GenericAttributes,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Lang
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDeviceCap::SetLang(const vWString& value){
	SetAttribute(atr_Lang,value);
};
/**
* Get string attribute Lang
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDeviceCap::GetLang() const {
	return GetAttribute(atr_Lang,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidLang(EnumValidationLevel level) const {
		return ValidAttribute(atr_Lang,AttributeType_languages,false);
	};
/**
* Set attribute OptionalCombinedTypes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDeviceCap::SetOptionalCombinedTypes(const vWString& value){
	SetAttribute(atr_OptionalCombinedTypes,value);
};
/**
* Get string attribute OptionalCombinedTypes
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDeviceCap::GetOptionalCombinedTypes() const {
	return GetAttribute(atr_OptionalCombinedTypes,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidOptionalCombinedTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_OptionalCombinedTypes,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDeviceCap::SetType(const WString& value){
	SetAttribute(atr_Type,value);
};
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDeviceCap::GetType() const {
	return GetAttribute(atr_Type,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidType(EnumValidationLevel level) const {
		return ValidAttribute(atr_Type,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute TypeExpression
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDeviceCap::SetTypeExpression(const WString& value){
	SetAttribute(atr_TypeExpression,value);
};
/**
* Get string attribute TypeExpression
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDeviceCap::GetTypeExpression() const {
	return GetAttribute(atr_TypeExpression,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidTypeExpression(EnumValidationLevel level) const {
		return ValidAttribute(atr_TypeExpression,AttributeType_regExp,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeviceCap::TypeOrderString(){
		static const WString enums=WString(L"Unknown,Fixed,Unordered,Unrestricted");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeviceCap::TypeOrderString(EnumTypeOrder value){
		return TypeOrderString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceCap::SetTypeOrder( EnumTypeOrder value){
	SetEnumAttribute(atr_TypeOrder,value,TypeOrderString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeviceCap::EnumTypeOrder JDFAutoDeviceCap:: GetTypeOrder() const {
	return (EnumTypeOrder) GetEnumAttribute(atr_TypeOrder,TypeOrderString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidTypeOrder(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_TypeOrder,TypeOrderString(),false);
	};
/**
* Set attribute Types
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDeviceCap::SetTypes(const vWString& value){
	SetAttribute(atr_Types,value);
};
/**
* Get string attribute Types
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDeviceCap::GetTypes() const {
	return GetAttribute(atr_Types,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceCap::ValidTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_Types,AttributeType_NMTOKENS,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFActionPool JDFAutoDeviceCap::GetActionPool(int iSkip)const{
	JDFActionPool e=GetElement(elm_ActionPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActionPool JDFAutoDeviceCap::GetCreateActionPool(int iSkip){
	JDFActionPool e=GetCreateElement(elm_ActionPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActionPool JDFAutoDeviceCap::AppendActionPool(){
	JDFActionPool e=AppendElement(elm_ActionPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCapPool JDFAutoDeviceCap::GetDevCapPool(int iSkip)const{
	JDFDevCapPool e=GetElement(elm_DevCapPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCapPool JDFAutoDeviceCap::GetCreateDevCapPool(int iSkip){
	JDFDevCapPool e=GetCreateElement(elm_DevCapPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCapPool JDFAutoDeviceCap::AppendDevCapPool(){
	JDFDevCapPool e=AppendElement(elm_DevCapPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCaps JDFAutoDeviceCap::GetDevCaps(int iSkip)const{
	JDFDevCaps e=GetElement(elm_DevCaps,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCaps JDFAutoDeviceCap::GetCreateDevCaps(int iSkip){
	JDFDevCaps e=GetCreateElement(elm_DevCaps,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCaps JDFAutoDeviceCap::AppendDevCaps(){
	JDFDevCaps e=AppendElement(elm_DevCaps);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisplayGroupPool JDFAutoDeviceCap::GetDisplayGroupPool(int iSkip)const{
	JDFDisplayGroupPool e=GetElement(elm_DisplayGroupPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisplayGroupPool JDFAutoDeviceCap::GetCreateDisplayGroupPool(int iSkip){
	JDFDisplayGroupPool e=GetCreateElement(elm_DisplayGroupPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisplayGroupPool JDFAutoDeviceCap::AppendDisplayGroupPool(){
	JDFDisplayGroupPool e=AppendElement(elm_DisplayGroupPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFeaturePool JDFAutoDeviceCap::GetFeaturePool(int iSkip)const{
	JDFFeaturePool e=GetElement(elm_FeaturePool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFeaturePool JDFAutoDeviceCap::GetCreateFeaturePool(int iSkip){
	JDFFeaturePool e=GetCreateElement(elm_FeaturePool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFeaturePool JDFAutoDeviceCap::AppendFeaturePool(){
	JDFFeaturePool e=AppendElement(elm_FeaturePool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMacroPool JDFAutoDeviceCap::GetMacroPool(int iSkip)const{
	JDFMacroPool e=GetElement(elm_MacroPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMacroPool JDFAutoDeviceCap::GetCreateMacroPool(int iSkip){
	JDFMacroPool e=GetCreateElement(elm_MacroPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMacroPool JDFAutoDeviceCap::AppendMacroPool(){
	JDFMacroPool e=AppendElement(elm_MacroPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePool JDFAutoDeviceCap::GetModulePool(int iSkip)const{
	JDFModulePool e=GetElement(elm_ModulePool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePool JDFAutoDeviceCap::GetCreateModulePool(int iSkip){
	JDFModulePool e=GetCreateElement(elm_ModulePool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePool JDFAutoDeviceCap::AppendModulePool(){
	JDFModulePool e=AppendElement(elm_ModulePool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPerformance JDFAutoDeviceCap::GetPerformance(int iSkip)const{
	JDFPerformance e=GetElement(elm_Performance,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPerformance JDFAutoDeviceCap::GetCreatePerformance(int iSkip){
	JDFPerformance e=GetCreateElement(elm_Performance,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPerformance JDFAutoDeviceCap::AppendPerformance(){
	JDFPerformance e=AppendElement(elm_Performance);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoDeviceCap::GetTestPool(int iSkip)const{
	JDFTestPool e=GetElement(elm_TestPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoDeviceCap::GetCreateTestPool(int iSkip){
	JDFTestPool e=GetCreateElement(elm_TestPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestPool JDFAutoDeviceCap::AppendTestPool(){
	JDFTestPool e=AppendElement(elm_TestPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoDeviceCap::GetBooleanState(int iSkip)const{
	JDFBooleanState e=GetElement(elm_BooleanState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoDeviceCap::GetCreateBooleanState(int iSkip){
	JDFBooleanState e=GetCreateElement(elm_BooleanState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoDeviceCap::AppendBooleanState(){
	JDFBooleanState e=AppendElement(elm_BooleanState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoDeviceCap::GetDateTimeState(int iSkip)const{
	JDFDateTimeState e=GetElement(elm_DateTimeState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoDeviceCap::GetCreateDateTimeState(int iSkip){
	JDFDateTimeState e=GetCreateElement(elm_DateTimeState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoDeviceCap::AppendDateTimeState(){
	JDFDateTimeState e=AppendElement(elm_DateTimeState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoDeviceCap::GetDurationState(int iSkip)const{
	JDFDurationState e=GetElement(elm_DurationState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoDeviceCap::GetCreateDurationState(int iSkip){
	JDFDurationState e=GetCreateElement(elm_DurationState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoDeviceCap::AppendDurationState(){
	JDFDurationState e=AppendElement(elm_DurationState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoDeviceCap::GetEnumerationState(int iSkip)const{
	JDFEnumerationState e=GetElement(elm_EnumerationState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoDeviceCap::GetCreateEnumerationState(int iSkip){
	JDFEnumerationState e=GetCreateElement(elm_EnumerationState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoDeviceCap::AppendEnumerationState(){
	JDFEnumerationState e=AppendElement(elm_EnumerationState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoDeviceCap::GetIntegerState(int iSkip)const{
	JDFIntegerState e=GetElement(elm_IntegerState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoDeviceCap::GetCreateIntegerState(int iSkip){
	JDFIntegerState e=GetCreateElement(elm_IntegerState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoDeviceCap::AppendIntegerState(){
	JDFIntegerState e=AppendElement(elm_IntegerState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoDeviceCap::GetMatrixState(int iSkip)const{
	JDFMatrixState e=GetElement(elm_MatrixState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoDeviceCap::GetCreateMatrixState(int iSkip){
	JDFMatrixState e=GetCreateElement(elm_MatrixState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoDeviceCap::AppendMatrixState(){
	JDFMatrixState e=AppendElement(elm_MatrixState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoDeviceCap::GetNameState(int iSkip)const{
	JDFNameState e=GetElement(elm_NameState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoDeviceCap::GetCreateNameState(int iSkip){
	JDFNameState e=GetCreateElement(elm_NameState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoDeviceCap::AppendNameState(){
	JDFNameState e=AppendElement(elm_NameState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoDeviceCap::GetNumberState(int iSkip)const{
	JDFNumberState e=GetElement(elm_NumberState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoDeviceCap::GetCreateNumberState(int iSkip){
	JDFNumberState e=GetCreateElement(elm_NumberState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoDeviceCap::AppendNumberState(){
	JDFNumberState e=AppendElement(elm_NumberState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoDeviceCap::GetPDFPathState(int iSkip)const{
	JDFPDFPathState e=GetElement(elm_PDFPathState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoDeviceCap::GetCreatePDFPathState(int iSkip){
	JDFPDFPathState e=GetCreateElement(elm_PDFPathState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoDeviceCap::AppendPDFPathState(){
	JDFPDFPathState e=AppendElement(elm_PDFPathState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoDeviceCap::GetRectangleState(int iSkip)const{
	JDFRectangleState e=GetElement(elm_RectangleState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoDeviceCap::GetCreateRectangleState(int iSkip){
	JDFRectangleState e=GetCreateElement(elm_RectangleState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoDeviceCap::AppendRectangleState(){
	JDFRectangleState e=AppendElement(elm_RectangleState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoDeviceCap::GetShapeState(int iSkip)const{
	JDFShapeState e=GetElement(elm_ShapeState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoDeviceCap::GetCreateShapeState(int iSkip){
	JDFShapeState e=GetCreateElement(elm_ShapeState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoDeviceCap::AppendShapeState(){
	JDFShapeState e=AppendElement(elm_ShapeState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoDeviceCap::GetStringState(int iSkip)const{
	JDFStringState e=GetElement(elm_StringState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoDeviceCap::GetCreateStringState(int iSkip){
	JDFStringState e=GetCreateElement(elm_StringState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoDeviceCap::AppendStringState(){
	JDFStringState e=AppendElement(elm_StringState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoDeviceCap::GetXYPairState(int iSkip)const{
	JDFXYPairState e=GetElement(elm_XYPairState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoDeviceCap::GetCreateXYPairState(int iSkip){
	JDFXYPairState e=GetCreateElement(elm_XYPairState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoDeviceCap::AppendXYPairState(){
	JDFXYPairState e=AppendElement(elm_XYPairState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDeviceCap::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ActionPool);

		for(i=0;i<nElem;i++){
			if (!GetActionPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_ActionPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DevCapPool);

		for(i=0;i<nElem;i++){
			if (!GetDevCapPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_DevCapPool);
				if (++n>=nMax)
					return vElem;
				break;
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
		nElem=NumChildElements(elm_DisplayGroupPool);

		for(i=0;i<nElem;i++){
			if (!GetDisplayGroupPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_DisplayGroupPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FeaturePool);

		for(i=0;i<nElem;i++){
			if (!GetFeaturePool(i).IsValid(level)) {
				vElem.AppendUnique(elm_FeaturePool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MacroPool);

		for(i=0;i<nElem;i++){
			if (!GetMacroPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_MacroPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ModulePool);

		for(i=0;i<nElem;i++){
			if (!GetModulePool(i).IsValid(level)) {
				vElem.AppendUnique(elm_ModulePool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Performance);

		for(i=0;i<nElem;i++){
			if (!GetPerformance(i).IsValid(level)) {
				vElem.AppendUnique(elm_Performance);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TestPool);

		for(i=0;i<nElem;i++){
			if (!GetTestPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_TestPool);
				if (++n>=nMax)
					return vElem;
				break;
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
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDeviceCap::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ActionPool,DevCapPool,DevCaps,DisplayGroupPool,FeaturePool,MacroPool,ModulePool,Performance,TestPool,BooleanState,DateTimeState,DurationState,EnumerationState,IntegerState,MatrixState,NameState,NumberState,PDFPathState,RectangleState,ShapeState,StringState,XYPairState";
	};
}; // end namespace JDF
