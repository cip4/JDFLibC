/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoNotification.h"
#include "jdf/wrapper/JDFCostCenter.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFBarcode.h"
#include "jdf/wrapper/JDFFCNKey.h"
#include "jdf/wrapper/JDFMilestone.h"
#include "jdf/wrapper/JDFSystemTimeSet.h"
#include "jdf/wrapper/JDFCounterReset.h"
#include "jdf/wrapper/JDFError.h"
#include "jdf/wrapper/JDFEvent.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoNotification : public JDFAudit

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoNotification& JDFAutoNotification::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoNotification: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoNotification::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoNotification::ValidNodeNames()const{
	return L"*:,Notification";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoNotification::RequiredAttributes()const{
		return JDFAudit::RequiredAttributes()+L",Class";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoNotification::OptionalAttributes()const{
		return JDFAudit::OptionalAttributes()+WString(L",CombinedProcessIndex,JobID,JobPartID,ModuleID,ModuleIndex,ModuleType,Type");
};

/**
 typesafe validator
*/
	vWString JDFAutoNotification::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFAudit::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidClass(level)) {
			vAtts.push_back(atr_Class);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCombinedProcessIndex(level)) {
			vAtts.push_back(atr_CombinedProcessIndex);
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
		if(!ValidModuleID(level)) {
			vAtts.push_back(atr_ModuleID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleIndex(level)) {
			vAtts.push_back(atr_ModuleIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleType(level)) {
			vAtts.push_back(atr_ModuleType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoNotification::ClassString(){
		static const WString enums=WString(L"Unknown,Event,Information,Warning,Error,Fatal");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoNotification::ClassString(EnumClass value){
		return ClassString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoNotification::SetClass( EnumClass value){
	SetEnumAttribute(atr_Class,value,ClassString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoNotification::EnumClass JDFAutoNotification:: GetClass() const {
	return (EnumClass) GetEnumAttribute(atr_Class,ClassString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotification::ValidClass(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Class,ClassString(),RequiredLevel(level));
	};
/**
* Set attribute CombinedProcessIndex
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoNotification::SetCombinedProcessIndex(const JDFIntegerList& value){
	SetAttribute(atr_CombinedProcessIndex,value.GetString());
};
/**
* Get string attribute CombinedProcessIndex
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoNotification::GetCombinedProcessIndex() const {
	return GetAttribute(atr_CombinedProcessIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotification::ValidCombinedProcessIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_CombinedProcessIndex,AttributeType_IntegerList,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotification::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotification::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotification::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_string,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotification::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotification::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotification::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_string,false);
	};
/**
* Set attribute ModuleID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotification::SetModuleID(const WString& value){
	SetAttribute(atr_ModuleID,value);
};
/**
* Get string attribute ModuleID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotification::GetModuleID() const {
	return GetAttribute(atr_ModuleID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotification::ValidModuleID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleID,AttributeType_string,false);
	};
/**
* Set attribute ModuleIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoNotification::SetModuleIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_ModuleIndex,value.GetString());
};
/**
* Get range attribute ModuleIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoNotification::GetModuleIndex() const {
	return GetAttribute(atr_ModuleIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotification::ValidModuleIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute ModuleType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotification::SetModuleType(const WString& value){
	SetAttribute(atr_ModuleType,value);
};
/**
* Get string attribute ModuleType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotification::GetModuleType() const {
	return GetAttribute(atr_ModuleType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotification::ValidModuleType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNotification::SetType(const WString& value){
	SetAttribute(atr_Type,value);
};
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNotification::GetType() const {
	return GetAttribute(atr_Type,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNotification::ValidType(EnumValidationLevel level) const {
		return ValidAttribute(atr_Type,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCostCenter JDFAutoNotification::GetCostCenter(int iSkip)const{
	JDFCostCenter e=GetElement(elm_CostCenter,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoNotification::GetCreateCostCenter(int iSkip){
	JDFCostCenter e=GetCreateElement(elm_CostCenter,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoNotification::AppendCostCenter(){
	JDFCostCenter e=AppendElement(elm_CostCenter);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoNotification::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoNotification::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoNotification::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoNotification::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFBarcode JDFAutoNotification::GetBarcode(int iSkip)const{
	JDFBarcode e=GetElement(elm_Barcode,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBarcode JDFAutoNotification::GetCreateBarcode(int iSkip){
	JDFBarcode e=GetCreateElement(elm_Barcode,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBarcode JDFAutoNotification::AppendBarcode(){
	JDFBarcode e=AppendElement(elm_Barcode);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFCNKey JDFAutoNotification::GetFCNKey(int iSkip)const{
	JDFFCNKey e=GetElement(elm_FCNKey,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFCNKey JDFAutoNotification::GetCreateFCNKey(int iSkip){
	JDFFCNKey e=GetCreateElement(elm_FCNKey,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFCNKey JDFAutoNotification::AppendFCNKey(){
	JDFFCNKey e=AppendElement(elm_FCNKey);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMilestone JDFAutoNotification::GetMilestone(int iSkip)const{
	JDFMilestone e=GetElement(elm_Milestone,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMilestone JDFAutoNotification::GetCreateMilestone(int iSkip){
	JDFMilestone e=GetCreateElement(elm_Milestone,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMilestone JDFAutoNotification::AppendMilestone(){
	JDFMilestone e=AppendElement(elm_Milestone);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSystemTimeSet JDFAutoNotification::GetSystemTimeSet(int iSkip)const{
	JDFSystemTimeSet e=GetElement(elm_SystemTimeSet,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSystemTimeSet JDFAutoNotification::GetCreateSystemTimeSet(int iSkip){
	JDFSystemTimeSet e=GetCreateElement(elm_SystemTimeSet,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSystemTimeSet JDFAutoNotification::AppendSystemTimeSet(){
	JDFSystemTimeSet e=AppendElement(elm_SystemTimeSet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCounterReset JDFAutoNotification::GetCounterReset(int iSkip)const{
	JDFCounterReset e=GetElement(elm_CounterReset,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCounterReset JDFAutoNotification::GetCreateCounterReset(int iSkip){
	JDFCounterReset e=GetCreateElement(elm_CounterReset,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCounterReset JDFAutoNotification::AppendCounterReset(){
	JDFCounterReset e=AppendElement(elm_CounterReset);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFError JDFAutoNotification::GetError(int iSkip)const{
	JDFError e=GetElement(elm_Error,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFError JDFAutoNotification::GetCreateError(int iSkip){
	JDFError e=GetCreateElement(elm_Error,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFError JDFAutoNotification::AppendError(){
	JDFError e=AppendElement(elm_Error);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEvent JDFAutoNotification::GetEvent(int iSkip)const{
	JDFEvent e=GetElement(elm_Event,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEvent JDFAutoNotification::GetCreateEvent(int iSkip){
	JDFEvent e=GetCreateElement(elm_Event,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEvent JDFAutoNotification::AppendEvent(){
	JDFEvent e=AppendElement(elm_Event);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoNotification::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoNotification::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoNotification::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoNotification::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoNotification::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoNotification::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoNotification::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoNotification::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoNotification::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFAudit::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CostCenter);

		for(i=0;i<nElem;i++){
			if (!GetCostCenter(i).IsValid(level)) {
				vElem.AppendUnique(elm_CostCenter);
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
		nElem=NumChildElements(elm_Barcode);

		for(i=0;i<nElem;i++){
			if (!GetBarcode(i).IsValid(level)) {
				vElem.AppendUnique(elm_Barcode);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FCNKey);

		for(i=0;i<nElem;i++){
			if (!GetFCNKey(i).IsValid(level)) {
				vElem.AppendUnique(elm_FCNKey);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Milestone);

		for(i=0;i<nElem;i++){
			if (!GetMilestone(i).IsValid(level)) {
				vElem.AppendUnique(elm_Milestone);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SystemTimeSet);

		for(i=0;i<nElem;i++){
			if (!GetSystemTimeSet(i).IsValid(level)) {
				vElem.AppendUnique(elm_SystemTimeSet);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CounterReset);

		for(i=0;i<nElem;i++){
			if (!GetCounterReset(i).IsValid(level)) {
				vElem.AppendUnique(elm_CounterReset);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Error);

		for(i=0;i<nElem;i++){
			if (!GetError(i).IsValid(level)) {
				vElem.AppendUnique(elm_Error);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Event);

		for(i=0;i<nElem;i++){
			if (!GetEvent(i).IsValid(level)) {
				vElem.AppendUnique(elm_Event);
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
	WString JDFAutoNotification::OptionalElements()const{
		return JDFAudit::OptionalElements()+L",CostCenter,Employee,Barcode,FCNKey,Milestone,SystemTimeSet,CounterReset,Error,Event,Part";
	};
}; // end namespace JDF
