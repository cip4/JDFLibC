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

 
#include "jdf/wrapper/AutoJDF/JDFAutoJobPhase.h"
#include "jdf/wrapper/JDFCostCenter.h"
#include "jdf/wrapper/JDFNode.h"
#include "jdf/wrapper/JDFMISDetails.h"
#include "jdf/wrapper/JDFModuleStatus.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoJobPhase : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoJobPhase& JDFAutoJobPhase::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoJobPhase: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoJobPhase::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoJobPhase::ValidNodeNames()const{
	return L"*:,JobPhase";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoJobPhase::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Status";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoJobPhase::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Activation,Amount,DeadLine,JobID,JobPartID,PercentCompleted,PhaseAmount,PhaseStartTime,PhaseWaste,QueueEntryID,RestTime,Speed,StartTime,StatusDetails,TotalAmount,Waste");
};

/**
 typesafe validator
*/
	vWString JDFAutoJobPhase::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidActivation(level)) {
			vAtts.push_back(atr_Activation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAmount(level)) {
			vAtts.push_back(atr_Amount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeadLine(level)) {
			vAtts.push_back(atr_DeadLine);
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
		if(!ValidPercentCompleted(level)) {
			vAtts.push_back(atr_PercentCompleted);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPhaseAmount(level)) {
			vAtts.push_back(atr_PhaseAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPhaseStartTime(level)) {
			vAtts.push_back(atr_PhaseStartTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPhaseWaste(level)) {
			vAtts.push_back(atr_PhaseWaste);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRestTime(level)) {
			vAtts.push_back(atr_RestTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpeed(level)) {
			vAtts.push_back(atr_Speed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStartTime(level)) {
			vAtts.push_back(atr_StartTime);
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
		if(!ValidTotalAmount(level)) {
			vAtts.push_back(atr_TotalAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWaste(level)) {
			vAtts.push_back(atr_Waste);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoJobPhase::ActivationString(){
		static const WString enums=WString(L"Unknown,Inactive,Informative,Held,Active,TestRun,TestRunAndGo");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoJobPhase::ActivationString(EnumActivation value){
		return ActivationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoJobPhase::SetActivation( EnumActivation value){
	SetEnumAttribute(atr_Activation,value,ActivationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoJobPhase::EnumActivation JDFAutoJobPhase:: GetActivation() const {
	return (EnumActivation) GetEnumAttribute(atr_Activation,ActivationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidActivation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Activation,ActivationString(),false);
	};
/**
* Set attribute Amount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetAmount(double value){
	SetAttribute(atr_Amount,WString::valueOf(value));
};
/**
* Get double attribute Amount
* @return double the vaue of the attribute 
*/
	 double JDFAutoJobPhase::GetAmount() const {
	return GetRealAttribute(atr_Amount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Amount,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoJobPhase::DeadLineString(){
		static const WString enums=WString(L"Unknown,InTime,Warning,Late");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoJobPhase::DeadLineString(EnumDeadLine value){
		return DeadLineString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoJobPhase::SetDeadLine( EnumDeadLine value){
	SetEnumAttribute(atr_DeadLine,value,DeadLineString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoJobPhase::EnumDeadLine JDFAutoJobPhase:: GetDeadLine() const {
	return (EnumDeadLine) GetEnumAttribute(atr_DeadLine,DeadLineString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidDeadLine(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DeadLine,DeadLineString(),false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJobPhase::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJobPhase::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute PercentCompleted
*@param double value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetPercentCompleted(double value){
	SetAttribute(atr_PercentCompleted,WString::valueOf(value));
};
/**
* Get double attribute PercentCompleted
* @return double the vaue of the attribute 
*/
	 double JDFAutoJobPhase::GetPercentCompleted() const {
	return GetRealAttribute(atr_PercentCompleted,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidPercentCompleted(EnumValidationLevel level) const {
		return ValidAttribute(atr_PercentCompleted,AttributeType_double,false);
	};
/**
* Set attribute PhaseAmount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetPhaseAmount(double value){
	SetAttribute(atr_PhaseAmount,WString::valueOf(value));
};
/**
* Get double attribute PhaseAmount
* @return double the vaue of the attribute 
*/
	 double JDFAutoJobPhase::GetPhaseAmount() const {
	return GetRealAttribute(atr_PhaseAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidPhaseAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_PhaseAmount,AttributeType_double,false);
	};
/**
* Set attribute PhaseStartTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetPhaseStartTime(JDFDate value){
	SetAttribute(atr_PhaseStartTime,value.DateTimeISO());
};
/**
* Get string attribute PhaseStartTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoJobPhase::GetPhaseStartTime() const {
	return GetAttribute(atr_PhaseStartTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidPhaseStartTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_PhaseStartTime,AttributeType_dateTime,false);
	};
/**
* Set attribute PhaseWaste
*@param double value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetPhaseWaste(double value){
	SetAttribute(atr_PhaseWaste,WString::valueOf(value));
};
/**
* Get double attribute PhaseWaste
* @return double the vaue of the attribute 
*/
	 double JDFAutoJobPhase::GetPhaseWaste() const {
	return GetRealAttribute(atr_PhaseWaste,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidPhaseWaste(EnumValidationLevel level) const {
		return ValidAttribute(atr_PhaseWaste,AttributeType_double,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJobPhase::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute RestTime
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetRestTime(JDFDuration value){
	SetAttribute(atr_RestTime,value.DurationISO());
};
/**
* Get string attribute RestTime
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoJobPhase::GetRestTime() const {
	return GetAttribute(atr_RestTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidRestTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_RestTime,AttributeType_duration,false);
	};
/**
* Set attribute Speed
*@param double value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetSpeed(double value){
	SetAttribute(atr_Speed,WString::valueOf(value));
};
/**
* Get double attribute Speed
* @return double the vaue of the attribute 
*/
	 double JDFAutoJobPhase::GetSpeed() const {
	return GetRealAttribute(atr_Speed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidSpeed(EnumValidationLevel level) const {
		return ValidAttribute(atr_Speed,AttributeType_double,false);
	};
/**
* Set attribute StartTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetStartTime(JDFDate value){
	SetAttribute(atr_StartTime,value.DateTimeISO());
};
/**
* Get string attribute StartTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoJobPhase::GetStartTime() const {
	return GetAttribute(atr_StartTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidStartTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartTime,AttributeType_dateTime,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoJobPhase::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoJobPhase::EnumStatus JDFAutoJobPhase:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),RequiredLevel(level));
	};
/**
* Set attribute StatusDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetStatusDetails(const WString& value){
	SetAttribute(atr_StatusDetails,value);
};
/**
* Get string attribute StatusDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJobPhase::GetStatusDetails() const {
	return GetAttribute(atr_StatusDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidStatusDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_StatusDetails,AttributeType_shortString,false);
	};
/**
* Set attribute TotalAmount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetTotalAmount(double value){
	SetAttribute(atr_TotalAmount,WString::valueOf(value));
};
/**
* Get double attribute TotalAmount
* @return double the vaue of the attribute 
*/
	 double JDFAutoJobPhase::GetTotalAmount() const {
	return GetRealAttribute(atr_TotalAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidTotalAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_TotalAmount,AttributeType_double,false);
	};
/**
* Set attribute Waste
*@param double value: the value to set the attribute to
*/
	 void JDFAutoJobPhase::SetWaste(double value){
	SetAttribute(atr_Waste,WString::valueOf(value));
};
/**
* Get double attribute Waste
* @return double the vaue of the attribute 
*/
	 double JDFAutoJobPhase::GetWaste() const {
	return GetRealAttribute(atr_Waste,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobPhase::ValidWaste(EnumValidationLevel level) const {
		return ValidAttribute(atr_Waste,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCostCenter JDFAutoJobPhase::GetCostCenter()const{
	JDFCostCenter e=GetElement(elm_CostCenter);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoJobPhase::GetCreateCostCenter(){
	JDFCostCenter e=GetCreateElement(elm_CostCenter);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoJobPhase::AppendCostCenter(){
	JDFCostCenter e=AppendElementN(elm_CostCenter,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoJobPhase::RefCostCenter(JDFCostCenter& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoJobPhase::GetNode()const{
	JDFNode e=GetElement(elm_JDF);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoJobPhase::GetCreateNode(){
	JDFNode e=GetCreateElement(elm_JDF);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoJobPhase::AppendNode(){
	JDFNode e=AppendElementN(elm_JDF,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoJobPhase::GetMISDetails()const{
	JDFMISDetails e=GetElement(elm_MISDetails);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoJobPhase::GetCreateMISDetails(){
	JDFMISDetails e=GetCreateElement(elm_MISDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoJobPhase::AppendMISDetails(){
	JDFMISDetails e=AppendElementN(elm_MISDetails,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoJobPhase::RefMISDetails(JDFMISDetails& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFModuleStatus JDFAutoJobPhase::GetModuleStatus(int iSkip)const{
	JDFModuleStatus e=GetElement(elm_ModuleStatus,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModuleStatus JDFAutoJobPhase::GetCreateModuleStatus(int iSkip){
	JDFModuleStatus e=GetCreateElement(elm_ModuleStatus,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFModuleStatus JDFAutoJobPhase::AppendModuleStatus(){
	JDFModuleStatus e=AppendElement(elm_ModuleStatus);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoJobPhase::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoJobPhase::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoJobPhase::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoJobPhase::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoJobPhase::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoJobPhase::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoJobPhase::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoJobPhase::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoJobPhase::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CostCenter);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CostCenter);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCostCenter().IsValid(level)) {
				vElem.AppendUnique(elm_CostCenter);
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
		nElem=NumChildElements(elm_ModuleStatus);

		for(i=0;i<nElem;i++){
			if (!GetModuleStatus(i).IsValid(level)) {
				vElem.AppendUnique(elm_ModuleStatus);
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
	WString JDFAutoJobPhase::UniqueElements()const{
		return JDFElement::UniqueElements()+L",CostCenter,MISDetails";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoJobPhase::OptionalElements()const{
		return JDFElement::OptionalElements()+L",CostCenter,JDF,MISDetails,ModuleStatus,Part";
	};
}; // end namespace JDF
