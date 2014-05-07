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

 
#include "jdf/wrapper/AutoJDF/JDFAutoResourceCmdParams.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFMISDetails.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoResourceCmdParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoResourceCmdParams& JDFAutoResourceCmdParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoResourceCmdParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoResourceCmdParams::ValidNodeNames()const{
	return L"*:,ResourceCmdParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoResourceCmdParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Activation,Exact,JobID,JobPartID,ProcessUsage,ProductID,ProductionAmount,QueueEntryID,ResourceName,ResourceID,Status,UpdateIDs,UpdateMethod,Usage");
};

/**
 typesafe validator
*/
	vWString JDFAutoResourceCmdParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidActivation(level)) {
			vAtts.push_back(atr_Activation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidExact(level)) {
			vAtts.push_back(atr_Exact);
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
		if(!ValidProcessUsage(level)) {
			vAtts.push_back(atr_ProcessUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductID(level)) {
			vAtts.push_back(atr_ProductID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductionAmount(level)) {
			vAtts.push_back(atr_ProductionAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceName(level)) {
			vAtts.push_back(atr_ResourceName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceID(level)) {
			vAtts.push_back(atr_ResourceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUpdateIDs(level)) {
			vAtts.push_back(atr_UpdateIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUpdateMethod(level)) {
			vAtts.push_back(atr_UpdateMethod);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUsage(level)) {
			vAtts.push_back(atr_Usage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceCmdParams::ActivationString(){
		static const WString enums=WString(L"Unknown,Held,Active,TestRun,TestRunAndGo");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceCmdParams::ActivationString(EnumActivation value){
		return ActivationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceCmdParams::SetActivation( EnumActivation value){
	SetEnumAttribute(atr_Activation,value,ActivationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceCmdParams::EnumActivation JDFAutoResourceCmdParams:: GetActivation() const {
	return (EnumActivation) GetEnumAttribute(atr_Activation,ActivationString(),WString::emptyStr,Activation_Active);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidActivation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Activation,ActivationString(),false);
	};
/**
* Set attribute Exact
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetExact(bool value){
	SetAttribute(atr_Exact,WString::valueOf(value));
};
/**
* Get bool attribute Exact
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoResourceCmdParams::GetExact() const {return GetBoolAttribute(atr_Exact,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidExact(EnumValidationLevel level) const {
		return ValidAttribute(atr_Exact,AttributeType_boolean,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceCmdParams::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceCmdParams::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute ProcessUsage
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetProcessUsage(const WString& value){
	SetAttribute(atr_ProcessUsage,value);
};
/**
* Get string attribute ProcessUsage
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceCmdParams::GetProcessUsage() const {
	return GetAttribute(atr_ProcessUsage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidProcessUsage(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProcessUsage,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ProductID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetProductID(const WString& value){
	SetAttribute(atr_ProductID,value);
};
/**
* Get string attribute ProductID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceCmdParams::GetProductID() const {
	return GetAttribute(atr_ProductID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidProductID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductID,AttributeType_shortString,false);
	};
/**
* Set attribute ProductionAmount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetProductionAmount(double value){
	SetAttribute(atr_ProductionAmount,WString::valueOf(value));
};
/**
* Get double attribute ProductionAmount
* @return double the vaue of the attribute 
*/
	 double JDFAutoResourceCmdParams::GetProductionAmount() const {
	return GetRealAttribute(atr_ProductionAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidProductionAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductionAmount,AttributeType_double,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceCmdParams::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute ResourceName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetResourceName(const WString& value){
	SetAttribute(atr_ResourceName,value);
};
/**
* Get string attribute ResourceName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceCmdParams::GetResourceName() const {
	return GetAttribute(atr_ResourceName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidResourceName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceName,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ResourceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetResourceID(const WString& value){
	SetAttribute(atr_ResourceID,value);
};
/**
* Get string attribute ResourceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceCmdParams::GetResourceID() const {
	return GetAttribute(atr_ResourceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidResourceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceID,AttributeType_NMTOKEN,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceCmdParams::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceCmdParams::EnumStatus JDFAutoResourceCmdParams:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),false);
	};
/**
* Set attribute UpdateIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoResourceCmdParams::SetUpdateIDs(const vWString& value){
	SetAttribute(atr_UpdateIDs,value);
};
/**
* Get string attribute UpdateIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoResourceCmdParams::GetUpdateIDs() const {
	return GetAttribute(atr_UpdateIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidUpdateIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_UpdateIDs,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceCmdParams::UpdateMethodString(){
		static const WString enums=WString(L"Unknown,Complete,Incremental,Remove");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceCmdParams::UpdateMethodString(EnumUpdateMethod value){
		return UpdateMethodString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceCmdParams::SetUpdateMethod( EnumUpdateMethod value){
	SetEnumAttribute(atr_UpdateMethod,value,UpdateMethodString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceCmdParams::EnumUpdateMethod JDFAutoResourceCmdParams:: GetUpdateMethod() const {
	return (EnumUpdateMethod) GetEnumAttribute(atr_UpdateMethod,UpdateMethodString(),WString::emptyStr,UpdateMethod_Complete);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidUpdateMethod(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_UpdateMethod,UpdateMethodString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceCmdParams::UsageString(){
		static const WString enums=WString(L"Unknown,Input,Output");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceCmdParams::UsageString(EnumUsage value){
		return UsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceCmdParams::SetUsage( EnumUsage value){
	SetEnumAttribute(atr_Usage,value,UsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceCmdParams::EnumUsage JDFAutoResourceCmdParams:: GetUsage() const {
	return (EnumUsage) GetEnumAttribute(atr_Usage,UsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceCmdParams::ValidUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Usage,UsageString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoResourceCmdParams::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceCmdParams::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceCmdParams::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoResourceCmdParams::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceCmdParams::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceCmdParams::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceCmdParams::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoResourceCmdParams::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

JDFMISDetails JDFAutoResourceCmdParams::GetMISDetails()const{
	JDFMISDetails e=GetElement(elm_MISDetails);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourceCmdParams::GetCreateMISDetails(){
	JDFMISDetails e=GetCreateElement(elm_MISDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourceCmdParams::AppendMISDetails(){
	JDFMISDetails e=AppendElementN(elm_MISDetails,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoResourceCmdParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
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
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoResourceCmdParams::UniqueElements()const{
		return JDFElement::UniqueElements()+L",MISDetails";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoResourceCmdParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part,MISDetails";
	};
}; // end namespace JDF
