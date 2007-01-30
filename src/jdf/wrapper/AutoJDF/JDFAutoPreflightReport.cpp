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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreflightReport.h"
#include "jdf/wrapper/JDFPreflightParams.h"
#include "jdf/wrapper/JDFPreflightReportRulePool.h"
#include "jdf/wrapper/JDFRunList.h"
#include "jdf/wrapper/JDFPRItem.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreflightReport : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreflightReport& JDFAutoPreflightReport::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreflightReport: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreflightReport::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreflightReport::ValidNodeNames()const{
	return L"*:,PreflightReport";
};

bool JDFAutoPreflightReport::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPreflightReport::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoPreflightReport::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",ErrorCount,WarningCount";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPreflightReport::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ErrorState");
};

/**
 typesafe validator
*/
	vWString JDFAutoPreflightReport::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidErrorCount(level)) {
			vAtts.push_back(atr_ErrorCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWarningCount(level)) {
			vAtts.push_back(atr_WarningCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidErrorState(level)) {
			vAtts.push_back(atr_ErrorState);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ErrorCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPreflightReport::SetErrorCount(int value){
	SetAttribute(atr_ErrorCount,WString::valueOf(value));
};
/**
* Get integer attribute ErrorCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoPreflightReport::GetErrorCount() const {
	return GetIntAttribute(atr_ErrorCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightReport::ValidErrorCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_ErrorCount,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute WarningCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPreflightReport::SetWarningCount(int value){
	SetAttribute(atr_WarningCount,WString::valueOf(value));
};
/**
* Get integer attribute WarningCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoPreflightReport::GetWarningCount() const {
	return GetIntAttribute(atr_WarningCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightReport::ValidWarningCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_WarningCount,AttributeType_integer,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreflightReport::ErrorStateString(){
		static const WString enums=WString(L"Unknown,TestNotSupported,TestWrongPDL");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreflightReport::ErrorStateString(EnumErrorState value){
		return ErrorStateString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreflightReport::SetErrorState( EnumErrorState value){
	SetEnumAttribute(atr_ErrorState,value,ErrorStateString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreflightReport::EnumErrorState JDFAutoPreflightReport:: GetErrorState() const {
	return (EnumErrorState) GetEnumAttribute(atr_ErrorState,ErrorStateString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightReport::ValidErrorState(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ErrorState,ErrorStateString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPreflightParams JDFAutoPreflightReport::GetPreflightParams()const{
	JDFPreflightParams e=GetElement(elm_PreflightParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightParams JDFAutoPreflightReport::GetCreatePreflightParams(){
	JDFPreflightParams e=GetCreateElement(elm_PreflightParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightParams JDFAutoPreflightReport::AppendPreflightParams(){
	JDFPreflightParams e=AppendElementN(elm_PreflightParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPreflightReport::RefPreflightParams(JDFPreflightParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPreflightReportRulePool JDFAutoPreflightReport::GetPreflightReportRulePool()const{
	JDFPreflightReportRulePool e=GetElement(elm_PreflightReportRulePool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightReportRulePool JDFAutoPreflightReport::GetCreatePreflightReportRulePool(){
	JDFPreflightReportRulePool e=GetCreateElement(elm_PreflightReportRulePool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightReportRulePool JDFAutoPreflightReport::AppendPreflightReportRulePool(){
	JDFPreflightReportRulePool e=AppendElementN(elm_PreflightReportRulePool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPreflightReport::RefPreflightReportRulePool(JDFPreflightReportRulePool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoPreflightReport::GetRunList()const{
	JDFRunList e=GetElement(elm_RunList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoPreflightReport::GetCreateRunList(){
	JDFRunList e=GetCreateElement(elm_RunList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoPreflightReport::AppendRunList(){
	JDFRunList e=AppendElementN(elm_RunList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPreflightReport::RefRunList(JDFRunList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPRItem JDFAutoPreflightReport::GetPRItem(int iSkip)const{
	JDFPRItem e=GetElement(elm_PRItem,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRItem JDFAutoPreflightReport::GetCreatePRItem(int iSkip){
	JDFPRItem e=GetCreateElement(elm_PRItem,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRItem JDFAutoPreflightReport::AppendPRItem(){
	JDFPRItem e=AppendElement(elm_PRItem);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreflightReport::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_PreflightParams);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_PreflightParams);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PreflightParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPreflightParams().IsValid(level)) {
				vElem.AppendUnique(elm_PreflightParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PreflightReportRulePool);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_PreflightReportRulePool);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PreflightReportRulePool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPreflightReportRulePool().IsValid(level)) {
				vElem.AppendUnique(elm_PreflightReportRulePool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_RunList);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_RunList);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_RunList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetRunList().IsValid(level)) {
				vElem.AppendUnique(elm_RunList);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PRItem);

		for(i=0;i<nElem;i++){
			if (!GetPRItem(i).IsValid(level)) {
				vElem.AppendUnique(elm_PRItem);
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
	WString JDFAutoPreflightReport::UniqueElements()const{
		return JDFResource::UniqueElements()+L",PreflightParams,PreflightReportRulePool,RunList";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPreflightReport::RequiredElements()const{
		return JDFResource::RequiredElements()+L",PreflightParams,PreflightReportRulePool,RunList";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPreflightReport::OptionalElements()const{
		return JDFResource::OptionalElements()+L",PRItem";
	};
}; // end namespace JDF
