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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPhaseTime.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFActivity.h"
#include "jdf/wrapper/JDFMISDetails.h"
#include "jdf/wrapper/JDFModulePhase.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPhaseTime : public JDFAudit

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPhaseTime& JDFAutoPhaseTime::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPhaseTime: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPhaseTime::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPhaseTime::ValidNodeNames()const{
	return L"*:,PhaseTime";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoPhaseTime::RequiredAttributes()const{
		return JDFAudit::RequiredAttributes()+L",Start,Status";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPhaseTime::OptionalAttributes()const{
		return JDFAudit::OptionalAttributes()+WString(L",End,StatusDetails");
};

/**
 typesafe validator
*/
	vWString JDFAutoPhaseTime::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFAudit::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidEnd(level)) {
			vAtts.push_back(atr_End);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStart(level)) {
			vAtts.push_back(atr_Start);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatusDetails(level)) {
			vAtts.push_back(atr_StatusDetails);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute End
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoPhaseTime::SetEnd(JDFDate value){
	SetAttribute(atr_End,value.DateTimeISO());
};
/**
* Get string attribute End
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoPhaseTime::GetEnd() const {
	return GetAttribute(atr_End,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPhaseTime::ValidEnd(EnumValidationLevel level) const {
		return ValidAttribute(atr_End,AttributeType_dateTime,false);
	};
/**
* Set attribute Start
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoPhaseTime::SetStart(JDFDate value){
	SetAttribute(atr_Start,value.DateTimeISO());
};
/**
* Get string attribute Start
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoPhaseTime::GetStart() const {
	return GetAttribute(atr_Start,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPhaseTime::ValidStart(EnumValidationLevel level) const {
		return ValidAttribute(atr_Start,AttributeType_dateTime,RequiredLevel(level));
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPhaseTime::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPhaseTime::EnumStatus JDFAutoPhaseTime:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPhaseTime::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),RequiredLevel(level));
	};
/**
* Set attribute StatusDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPhaseTime::SetStatusDetails(const WString& value){
	SetAttribute(atr_StatusDetails,value);
};
/**
* Get string attribute StatusDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPhaseTime::GetStatusDetails() const {
	return GetAttribute(atr_StatusDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPhaseTime::ValidStatusDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_StatusDetails,AttributeType_shortString,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDevice JDFAutoPhaseTime::GetDevice(int iSkip)const{
	JDFDevice e=GetElement(elm_Device,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoPhaseTime::GetCreateDevice(int iSkip){
	JDFDevice e=GetCreateElement(elm_Device,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoPhaseTime::AppendDevice(){
	JDFDevice e=AppendElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPhaseTime::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoPhaseTime::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoPhaseTime::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoPhaseTime::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPhaseTime::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFActivity JDFAutoPhaseTime::GetActivity(int iSkip)const{
	JDFActivity e=GetElement(elm_Activity,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActivity JDFAutoPhaseTime::GetCreateActivity(int iSkip){
	JDFActivity e=GetCreateElement(elm_Activity,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFActivity JDFAutoPhaseTime::AppendActivity(){
	JDFActivity e=AppendElement(elm_Activity);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoPhaseTime::GetMISDetails(int iSkip)const{
	JDFMISDetails e=GetElement(elm_MISDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoPhaseTime::GetCreateMISDetails(int iSkip){
	JDFMISDetails e=GetCreateElement(elm_MISDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoPhaseTime::AppendMISDetails(){
	JDFMISDetails e=AppendElement(elm_MISDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePhase JDFAutoPhaseTime::GetModulePhase(int iSkip)const{
	JDFModulePhase e=GetElement(elm_ModulePhase,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePhase JDFAutoPhaseTime::GetCreateModulePhase(int iSkip){
	JDFModulePhase e=GetCreateElement(elm_ModulePhase,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModulePhase JDFAutoPhaseTime::AppendModulePhase(){
	JDFModulePhase e=AppendElement(elm_ModulePhase);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoPhaseTime::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoPhaseTime::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoPhaseTime::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoPhaseTime::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoPhaseTime::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoPhaseTime::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoPhaseTime::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoPhaseTime::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoPhaseTime::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFAudit::GetInvalidElements(level, bIgnorePrivate, nMax);
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
		nElem=NumChildElements(elm_Employee);

		for(i=0;i<nElem;i++){
			if (!GetEmployee(i).IsValid(level)) {
				vElem.AppendUnique(elm_Employee);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Activity);

		for(i=0;i<nElem;i++){
			if (!GetActivity(i).IsValid(level)) {
				vElem.AppendUnique(elm_Activity);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MISDetails);

		for(i=0;i<nElem;i++){
			if (!GetMISDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_MISDetails);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ModulePhase);

		for(i=0;i<nElem;i++){
			if (!GetModulePhase(i).IsValid(level)) {
				vElem.AppendUnique(elm_ModulePhase);
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
	WString JDFAutoPhaseTime::OptionalElements()const{
		return JDFAudit::OptionalElements()+L",Device,Employee,Activity,MISDetails,ModulePhase,Part";
	};
}; // end namespace JDF
