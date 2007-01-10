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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAncestor.h"
#include "jdf/wrapper/JDFCustomerInfo.h"
#include "jdf/wrapper/JDFNodeInfo.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAncestor : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAncestor& JDFAutoAncestor::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAncestor: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAncestor::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAncestor::ValidNodeNames()const{
	return L"*:,Ancestor";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoAncestor::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",NodeID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoAncestor::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Activation,FileName,ICSVersions,JobID,JobPartID,MaxVersion,ProjectID,RelatedJobID,RelatedJobPartID,SpawnID,Status,StatusDetails,Type,Types,Version");
};

/**
 typesafe validator
*/
	vWString JDFAutoAncestor::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidActivation(level)) {
			vAtts.push_back(atr_Activation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFileName(level)) {
			vAtts.push_back(atr_FileName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidICSVersions(level)) {
			vAtts.push_back(atr_ICSVersions);
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
		if(!ValidMaxVersion(level)) {
			vAtts.push_back(atr_MaxVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNodeID(level)) {
			vAtts.push_back(atr_NodeID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProjectID(level)) {
			vAtts.push_back(atr_ProjectID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelatedJobID(level)) {
			vAtts.push_back(atr_RelatedJobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelatedJobPartID(level)) {
			vAtts.push_back(atr_RelatedJobPartID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpawnID(level)) {
			vAtts.push_back(atr_SpawnID);
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
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTypes(level)) {
			vAtts.push_back(atr_Types);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVersion(level)) {
			vAtts.push_back(atr_Version);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAncestor::ActivationString(){
		static const WString enums=WString(L"Unknown,Inactive,Informative,Held,Active,TestRun,TestRunAndGo");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAncestor::ActivationString(EnumActivation value){
		return ActivationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAncestor::SetActivation( EnumActivation value){
	SetEnumAttribute(atr_Activation,value,ActivationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAncestor::EnumActivation JDFAutoAncestor:: GetActivation() const {
	return (EnumActivation) GetEnumAttribute(atr_Activation,ActivationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidActivation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Activation,ActivationString(),false);
	};
/**
* Set attribute FileName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetFileName(const WString& value){
	SetAttribute(atr_FileName,value);
};
/**
* Get string attribute FileName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetFileName() const {
	return GetAttribute(atr_FileName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidFileName(EnumValidationLevel level) const {
		return ValidAttribute(atr_FileName,AttributeType_URL,false);
	};
/**
* Set attribute ICSVersions
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetICSVersions(const vWString& value){
	SetAttribute(atr_ICSVersions,value);
};
/**
* Get string attribute ICSVersions
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoAncestor::GetICSVersions() const {
	return GetAttribute(atr_ICSVersions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidICSVersions(EnumValidationLevel level) const {
		return ValidAttribute(atr_ICSVersions,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute MaxVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetMaxVersion(const WString& value){
	SetAttribute(atr_MaxVersion,value);
};
/**
* Get string attribute MaxVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetMaxVersion() const {
	return GetAttribute(atr_MaxVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidMaxVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxVersion,AttributeType_Any,false);
	};
/**
* Set attribute NodeID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetNodeID(const WString& value){
	SetAttribute(atr_NodeID,value);
};
/**
* Get string attribute NodeID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetNodeID() const {
	return GetAttribute(atr_NodeID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidNodeID(EnumValidationLevel level) const {
		return ValidAttribute(atr_NodeID,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute ProjectID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetProjectID(const WString& value){
	SetAttribute(atr_ProjectID,value);
};
/**
* Get string attribute ProjectID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetProjectID() const {
	return GetAttribute(atr_ProjectID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidProjectID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProjectID,AttributeType_shortString,false);
	};
/**
* Set attribute RelatedJobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetRelatedJobID(const WString& value){
	SetAttribute(atr_RelatedJobID,value);
};
/**
* Get string attribute RelatedJobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetRelatedJobID() const {
	return GetAttribute(atr_RelatedJobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidRelatedJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelatedJobID,AttributeType_shortString,false);
	};
/**
* Set attribute RelatedJobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetRelatedJobPartID(const WString& value){
	SetAttribute(atr_RelatedJobPartID,value);
};
/**
* Get string attribute RelatedJobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetRelatedJobPartID() const {
	return GetAttribute(atr_RelatedJobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidRelatedJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelatedJobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute SpawnID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetSpawnID(const WString& value){
	SetAttribute(atr_SpawnID,value);
};
/**
* Get string attribute SpawnID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetSpawnID() const {
	return GetAttribute(atr_SpawnID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidSpawnID(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpawnID,AttributeType_shortString,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoAncestor::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAncestor::EnumStatus JDFAutoAncestor:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),false);
	};
/**
* Set attribute StatusDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetStatusDetails(const WString& value){
	SetAttribute(atr_StatusDetails,value);
};
/**
* Get string attribute StatusDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetStatusDetails() const {
	return GetAttribute(atr_StatusDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidStatusDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_StatusDetails,AttributeType_shortString,false);
	};
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetType(const WString& value){
	SetAttribute(atr_Type,value);
};
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetType() const {
	return GetAttribute(atr_Type,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidType(EnumValidationLevel level) const {
		return ValidAttribute(atr_Type,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Types
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetTypes(const vWString& value){
	SetAttribute(atr_Types,value);
};
/**
* Get string attribute Types
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoAncestor::GetTypes() const {
	return GetAttribute(atr_Types,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_Types,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Version
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAncestor::SetVersion(const WString& value){
	SetAttribute(atr_Version,value);
};
/**
* Get string attribute Version
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAncestor::GetVersion() const {
	return GetAttribute(atr_Version,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAncestor::ValidVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_Version,AttributeType_Any,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCustomerInfo JDFAutoAncestor::GetCustomerInfo()const{
	JDFCustomerInfo e=GetElement(elm_CustomerInfo);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCustomerInfo JDFAutoAncestor::GetCreateCustomerInfo(){
	JDFCustomerInfo e=GetCreateElement(elm_CustomerInfo);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCustomerInfo JDFAutoAncestor::AppendCustomerInfo(){
	JDFCustomerInfo e=AppendElementN(elm_CustomerInfo,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNodeInfo JDFAutoAncestor::GetNodeInfo()const{
	JDFNodeInfo e=GetElement(elm_NodeInfo);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNodeInfo JDFAutoAncestor::GetCreateNodeInfo(){
	JDFNodeInfo e=GetCreateElement(elm_NodeInfo);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNodeInfo JDFAutoAncestor::AppendNodeInfo(){
	JDFNodeInfo e=AppendElementN(elm_NodeInfo,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoAncestor::RefNodeInfo(JDFNodeInfo& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoAncestor::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CustomerInfo);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CustomerInfo);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCustomerInfo().IsValid(level)) {
				vElem.AppendUnique(elm_CustomerInfo);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_NodeInfo);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_NodeInfo);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetNodeInfo().IsValid(level)) {
				vElem.AppendUnique(elm_NodeInfo);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoAncestor::UniqueElements()const{
		return JDFElement::UniqueElements()+L",CustomerInfo,NodeInfo";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoAncestor::OptionalElements()const{
		return JDFElement::OptionalElements()+L",CustomerInfo,NodeInfo";
	};
}; // end namespace JDF
