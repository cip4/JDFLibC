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

 
#include "jdf/wrapper/AutoJDF/JDFAutoNodeInfo.h"
#include "jdf/wrapper/JDFBusinessInfo.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFJMF.h"
#include "jdf/wrapper/JDFMISDetails.h"
#include "jdf/wrapper/JDFNotificationFilter.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoNodeInfo : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoNodeInfo& JDFAutoNodeInfo::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoNodeInfo: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoNodeInfo::ValidNodeNames()const{
	return L"*:,NodeInfo";
};

bool JDFAutoNodeInfo::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoNodeInfo::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoNodeInfo::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",CleanupDuration,DueLevel,End,FirstEnd,FirstStart,IPPVersion,JobPriority,LastEnd,LastStart,NaturalLang,MergeTarget,Route,rRefs,SetupDuration,Start,TargetRoute,TotalDuration");
};

/**
 typesafe validator
*/
	vWString JDFAutoNodeInfo::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCleanupDuration(level)) {
			vAtts.push_back(atr_CleanupDuration);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDueLevel(level)) {
			vAtts.push_back(atr_DueLevel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEnd(level)) {
			vAtts.push_back(atr_End);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFirstEnd(level)) {
			vAtts.push_back(atr_FirstEnd);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFirstStart(level)) {
			vAtts.push_back(atr_FirstStart);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIPPVersion(level)) {
			vAtts.push_back(atr_IPPVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobPriority(level)) {
			vAtts.push_back(atr_JobPriority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLastEnd(level)) {
			vAtts.push_back(atr_LastEnd);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLastStart(level)) {
			vAtts.push_back(atr_LastStart);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNaturalLang(level)) {
			vAtts.push_back(atr_NaturalLang);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMergeTarget(level)) {
			vAtts.push_back(atr_MergeTarget);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRoute(level)) {
			vAtts.push_back(atr_Route);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidrRefs(level)) {
			vAtts.push_back(atr_rRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetupDuration(level)) {
			vAtts.push_back(atr_SetupDuration);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStart(level)) {
			vAtts.push_back(atr_Start);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTargetRoute(level)) {
			vAtts.push_back(atr_TargetRoute);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTotalDuration(level)) {
			vAtts.push_back(atr_TotalDuration);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CleanupDuration
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetCleanupDuration(JDFDuration value){
	SetAttribute(atr_CleanupDuration,value.DurationISO());
};
/**
* Get string attribute CleanupDuration
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoNodeInfo::GetCleanupDuration() const {
	return GetAttribute(atr_CleanupDuration,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidCleanupDuration(EnumValidationLevel level) const {
		return ValidAttribute(atr_CleanupDuration,AttributeType_duration,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoNodeInfo::DueLevelString(){
		static const WString enums=WString(L"Unknown,Trivial,Penalty,JobCancelled");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoNodeInfo::DueLevelString(EnumDueLevel value){
		return DueLevelString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoNodeInfo::SetDueLevel( EnumDueLevel value){
	SetEnumAttribute(atr_DueLevel,value,DueLevelString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoNodeInfo::EnumDueLevel JDFAutoNodeInfo:: GetDueLevel() const {
	return (EnumDueLevel) GetEnumAttribute(atr_DueLevel,DueLevelString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidDueLevel(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DueLevel,DueLevelString(),false,WString::emptyStr,true);
	};
/**
* Set attribute End
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetEnd(JDFDate value){
	SetAttribute(atr_End,value.DateTimeISO());
};
/**
* Get string attribute End
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoNodeInfo::GetEnd() const {
	return GetAttribute(atr_End,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidEnd(EnumValidationLevel level) const {
		return ValidAttribute(atr_End,AttributeType_dateTime,false);
	};
/**
* Set attribute FirstEnd
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetFirstEnd(JDFDate value){
	SetAttribute(atr_FirstEnd,value.DateTimeISO());
};
/**
* Get string attribute FirstEnd
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoNodeInfo::GetFirstEnd() const {
	return GetAttribute(atr_FirstEnd,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidFirstEnd(EnumValidationLevel level) const {
		return ValidAttribute(atr_FirstEnd,AttributeType_dateTime,false);
	};
/**
* Set attribute FirstStart
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetFirstStart(JDFDate value){
	SetAttribute(atr_FirstStart,value.DateTimeISO());
};
/**
* Get string attribute FirstStart
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoNodeInfo::GetFirstStart() const {
	return GetAttribute(atr_FirstStart,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidFirstStart(EnumValidationLevel level) const {
		return ValidAttribute(atr_FirstStart,AttributeType_dateTime,false);
	};
/**
* Set attribute IPPVersion
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetIPPVersion(const JDFXYPair& value){
	SetAttribute(atr_IPPVersion,value);
};
/**
* Get string attribute IPPVersion
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoNodeInfo::GetIPPVersion() const {
	return GetAttribute(atr_IPPVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidIPPVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_IPPVersion,AttributeType_XYPair,false);
	};
/**
* Set attribute JobPriority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetJobPriority(int value){
	SetAttribute(atr_JobPriority,WString::valueOf(value));
};
/**
* Get integer attribute JobPriority
* @return int the vaue of the attribute ; defaults to 50
*/
	 int JDFAutoNodeInfo::GetJobPriority() const {
	return GetIntAttribute(atr_JobPriority,WString::emptyStr,50);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidJobPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPriority,AttributeType_integer,false);
	};
/**
* Set attribute LastEnd
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetLastEnd(JDFDate value){
	SetAttribute(atr_LastEnd,value.DateTimeISO());
};
/**
* Get string attribute LastEnd
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoNodeInfo::GetLastEnd() const {
	return GetAttribute(atr_LastEnd,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidLastEnd(EnumValidationLevel level) const {
		return ValidAttribute(atr_LastEnd,AttributeType_dateTime,false);
	};
/**
* Set attribute LastStart
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetLastStart(JDFDate value){
	SetAttribute(atr_LastStart,value.DateTimeISO());
};
/**
* Get string attribute LastStart
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoNodeInfo::GetLastStart() const {
	return GetAttribute(atr_LastStart,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidLastStart(EnumValidationLevel level) const {
		return ValidAttribute(atr_LastStart,AttributeType_dateTime,false);
	};
/**
* Set attribute NaturalLang
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetNaturalLang(const WString& value){
	SetAttribute(atr_NaturalLang,value);
};
/**
* Get string attribute NaturalLang
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNodeInfo::GetNaturalLang() const {
	return GetAttribute(atr_NaturalLang,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidNaturalLang(EnumValidationLevel level) const {
		return ValidAttribute(atr_NaturalLang,AttributeType_language,false);
	};
/**
* Set attribute MergeTarget
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetMergeTarget(bool value){
	SetAttribute(atr_MergeTarget,WString::valueOf(value));
};
/**
* Get bool attribute MergeTarget
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoNodeInfo::GetMergeTarget() const {return GetBoolAttribute(atr_MergeTarget,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidMergeTarget(EnumValidationLevel level) const {
		return ValidAttribute(atr_MergeTarget,AttributeType_boolean,false);
	};
/**
* Set attribute Route
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetRoute(const WString& value){
	SetAttribute(atr_Route,value);
};
/**
* Get string attribute Route
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNodeInfo::GetRoute() const {
	return GetAttribute(atr_Route,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidRoute(EnumValidationLevel level) const {
		return ValidAttribute(atr_Route,AttributeType_URL,false);
	};
/**
* Set attribute rRefs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetrRefs(const vWString& value){
	SetAttribute(atr_rRefs,value);
};
/**
* Get string attribute rRefs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoNodeInfo::GetrRefs() const {
	return GetAttribute(atr_rRefs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidrRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRefs,AttributeType_IDREFS,false);
	};
/**
* Set attribute SetupDuration
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetSetupDuration(JDFDuration value){
	SetAttribute(atr_SetupDuration,value.DurationISO());
};
/**
* Get string attribute SetupDuration
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoNodeInfo::GetSetupDuration() const {
	return GetAttribute(atr_SetupDuration,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidSetupDuration(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetupDuration,AttributeType_duration,false);
	};
/**
* Set attribute Start
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetStart(JDFDate value){
	SetAttribute(atr_Start,value.DateTimeISO());
};
/**
* Get string attribute Start
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoNodeInfo::GetStart() const {
	return GetAttribute(atr_Start,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidStart(EnumValidationLevel level) const {
		return ValidAttribute(atr_Start,AttributeType_dateTime,false);
	};
/**
* Set attribute TargetRoute
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetTargetRoute(const WString& value){
	SetAttribute(atr_TargetRoute,value);
};
/**
* Get string attribute TargetRoute
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNodeInfo::GetTargetRoute() const {
	return GetAttribute(atr_TargetRoute,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidTargetRoute(EnumValidationLevel level) const {
		return ValidAttribute(atr_TargetRoute,AttributeType_URL,false);
	};
/**
* Set attribute TotalDuration
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoNodeInfo::SetTotalDuration(JDFDuration value){
	SetAttribute(atr_TotalDuration,value.DurationISO());
};
/**
* Get string attribute TotalDuration
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoNodeInfo::GetTotalDuration() const {
	return GetAttribute(atr_TotalDuration,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfo::ValidTotalDuration(EnumValidationLevel level) const {
		return ValidAttribute(atr_TotalDuration,AttributeType_duration,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBusinessInfo JDFAutoNodeInfo::GetBusinessInfo(int iSkip)const{
	JDFBusinessInfo e=GetElement(elm_BusinessInfo,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBusinessInfo JDFAutoNodeInfo::GetCreateBusinessInfo(int iSkip){
	JDFBusinessInfo e=GetCreateElement(elm_BusinessInfo,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBusinessInfo JDFAutoNodeInfo::AppendBusinessInfo(){
	JDFBusinessInfo e=AppendElement(elm_BusinessInfo);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoNodeInfo::GetEmployee()const{
	JDFEmployee e=GetElement(elm_Employee);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoNodeInfo::GetCreateEmployee(){
	JDFEmployee e=GetCreateElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoNodeInfo::AppendEmployee(){
	JDFEmployee e=AppendElementN(elm_Employee,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoNodeInfo::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFJMF JDFAutoNodeInfo::GetJMF(int iSkip)const{
	JDFJMF e=GetElement(elm_JMF,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJMF JDFAutoNodeInfo::GetCreateJMF(int iSkip){
	JDFJMF e=GetCreateElement(elm_JMF,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJMF JDFAutoNodeInfo::AppendJMF(){
	JDFJMF e=AppendElement(elm_JMF);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoNodeInfo::GetMISDetails()const{
	JDFMISDetails e=GetElement(elm_MISDetails);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoNodeInfo::GetCreateMISDetails(){
	JDFMISDetails e=GetCreateElement(elm_MISDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoNodeInfo::AppendMISDetails(){
	JDFMISDetails e=AppendElementN(elm_MISDetails,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNotificationFilter JDFAutoNodeInfo::GetNotificationFilter(int iSkip)const{
	JDFNotificationFilter e=GetElement(elm_NotificationFilter,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNotificationFilter JDFAutoNodeInfo::GetCreateNotificationFilter(int iSkip){
	JDFNotificationFilter e=GetCreateElement(elm_NotificationFilter,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNotificationFilter JDFAutoNodeInfo::AppendNotificationFilter(){
	JDFNotificationFilter e=AppendElement(elm_NotificationFilter);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoNodeInfo::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BusinessInfo);

		for(i=0;i<nElem;i++){
			if (!GetBusinessInfo(i).IsValid(level)) {
				vElem.AppendUnique(elm_BusinessInfo);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Employee);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Employee);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetEmployee().IsValid(level)) {
				vElem.AppendUnique(elm_Employee);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_MISDetails);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MISDetails);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMISDetails().IsValid(level)) {
				vElem.AppendUnique(elm_MISDetails);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_NotificationFilter);

		for(i=0;i<nElem;i++){
			if (!GetNotificationFilter(i).IsValid(level)) {
				vElem.AppendUnique(elm_NotificationFilter);
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
	WString JDFAutoNodeInfo::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Employee,MISDetails";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoNodeInfo::OptionalElements()const{
		return JDFResource::OptionalElements()+L",BusinessInfo,Employee,JMF,MISDetails,NotificationFilter";
	};
}; // end namespace JDF
