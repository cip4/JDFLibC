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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMISDetails.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMISDetails : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMISDetails& JDFAutoMISDetails::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMISDetails: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMISDetails::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMISDetails::ValidNodeNames()const{
	return L"*:,MISDetails";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMISDetails::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CostType,DeviceOperationMode,WorkType,WorkTypeDetails");
};

/**
 typesafe validator
*/
	vWString JDFAutoMISDetails::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCostType(level)) {
			vAtts.push_back(atr_CostType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeviceOperationMode(level)) {
			vAtts.push_back(atr_DeviceOperationMode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkType(level)) {
			vAtts.push_back(atr_WorkType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkTypeDetails(level)) {
			vAtts.push_back(atr_WorkTypeDetails);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMISDetails::CostTypeString(){
		static const WString enums=WString(L"Unknown,Chargeable,NonChargeable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMISDetails::CostTypeString(EnumCostType value){
		return CostTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMISDetails::SetCostType( EnumCostType value){
	SetEnumAttribute(atr_CostType,value,CostTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMISDetails::EnumCostType JDFAutoMISDetails:: GetCostType() const {
	return (EnumCostType) GetEnumAttribute(atr_CostType,CostTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMISDetails::ValidCostType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CostType,CostTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMISDetails::DeviceOperationModeString(){
		static const WString enums=WString(L"Unknown,Productive,NonProductive,Maintenance");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMISDetails::DeviceOperationModeString(EnumDeviceOperationMode value){
		return DeviceOperationModeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMISDetails::SetDeviceOperationMode( EnumDeviceOperationMode value){
	SetEnumAttribute(atr_DeviceOperationMode,value,DeviceOperationModeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMISDetails::EnumDeviceOperationMode JDFAutoMISDetails:: GetDeviceOperationMode() const {
	return (EnumDeviceOperationMode) GetEnumAttribute(atr_DeviceOperationMode,DeviceOperationModeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMISDetails::ValidDeviceOperationMode(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DeviceOperationMode,DeviceOperationModeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMISDetails::WorkTypeString(){
		static const WString enums=WString(L"Unknown,Original,Alteration,Rework");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMISDetails::WorkTypeString(EnumWorkType value){
		return WorkTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMISDetails::SetWorkType( EnumWorkType value){
	SetEnumAttribute(atr_WorkType,value,WorkTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMISDetails::EnumWorkType JDFAutoMISDetails:: GetWorkType() const {
	return (EnumWorkType) GetEnumAttribute(atr_WorkType,WorkTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMISDetails::ValidWorkType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_WorkType,WorkTypeString(),false);
	};
/**
* Set attribute WorkTypeDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMISDetails::SetWorkTypeDetails(const WString& value){
	SetAttribute(atr_WorkTypeDetails,value);
};
/**
* Get string attribute WorkTypeDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMISDetails::GetWorkTypeDetails() const {
	return GetAttribute(atr_WorkTypeDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMISDetails::ValidWorkTypeDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_WorkTypeDetails,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFQualityControlResult JDFAutoMISDetails::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoMISDetails::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoMISDetails::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMISDetails::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoMISDetails::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_QualityControlResult);

		for(i=0;i<nElem;i++){
			if (!GetQualityControlResult(i).IsValid(level)) {
				vElem.AppendUnique(elm_QualityControlResult);
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
	WString JDFAutoMISDetails::OptionalElements()const{
		return JDFElement::OptionalElements()+L",QualityControlResult";
	};
}; // end namespace JDF
