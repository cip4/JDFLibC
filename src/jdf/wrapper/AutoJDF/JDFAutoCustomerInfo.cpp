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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCustomerInfo.h"
#include "jdf/wrapper/JDFCompany.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFCustomerMessage.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCustomerInfo : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCustomerInfo& JDFAutoCustomerInfo::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCustomerInfo: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCustomerInfo::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCustomerInfo::ValidNodeNames()const{
	return L"*:,CustomerInfo";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCustomerInfo::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BillingCode,CustomerID,CustomerJobName,CustomerOrderID,CustomerProjectID");
};

/**
 typesafe validator
*/
	vWString JDFAutoCustomerInfo::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBillingCode(level)) {
			vAtts.push_back(atr_BillingCode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCustomerID(level)) {
			vAtts.push_back(atr_CustomerID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCustomerJobName(level)) {
			vAtts.push_back(atr_CustomerJobName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCustomerOrderID(level)) {
			vAtts.push_back(atr_CustomerOrderID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCustomerProjectID(level)) {
			vAtts.push_back(atr_CustomerProjectID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BillingCode
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCustomerInfo::SetBillingCode(const WString& value){
	SetAttribute(atr_BillingCode,value);
};
/**
* Get string attribute BillingCode
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCustomerInfo::GetBillingCode() const {
	return GetAttribute(atr_BillingCode,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCustomerInfo::ValidBillingCode(EnumValidationLevel level) const {
		return ValidAttribute(atr_BillingCode,AttributeType_string,false);
	};
/**
* Set attribute CustomerID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCustomerInfo::SetCustomerID(const WString& value){
	SetAttribute(atr_CustomerID,value);
};
/**
* Get string attribute CustomerID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCustomerInfo::GetCustomerID() const {
	return GetAttribute(atr_CustomerID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCustomerInfo::ValidCustomerID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CustomerID,AttributeType_shortString,false);
	};
/**
* Set attribute CustomerJobName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCustomerInfo::SetCustomerJobName(const WString& value){
	SetAttribute(atr_CustomerJobName,value);
};
/**
* Get string attribute CustomerJobName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCustomerInfo::GetCustomerJobName() const {
	return GetAttribute(atr_CustomerJobName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCustomerInfo::ValidCustomerJobName(EnumValidationLevel level) const {
		return ValidAttribute(atr_CustomerJobName,AttributeType_longString,false);
	};
/**
* Set attribute CustomerOrderID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCustomerInfo::SetCustomerOrderID(const WString& value){
	SetAttribute(atr_CustomerOrderID,value);
};
/**
* Get string attribute CustomerOrderID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCustomerInfo::GetCustomerOrderID() const {
	return GetAttribute(atr_CustomerOrderID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCustomerInfo::ValidCustomerOrderID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CustomerOrderID,AttributeType_shortString,false);
	};
/**
* Set attribute CustomerProjectID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCustomerInfo::SetCustomerProjectID(const WString& value){
	SetAttribute(atr_CustomerProjectID,value);
};
/**
* Get string attribute CustomerProjectID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCustomerInfo::GetCustomerProjectID() const {
	return GetAttribute(atr_CustomerProjectID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCustomerInfo::ValidCustomerProjectID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CustomerProjectID,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCompany JDFAutoCustomerInfo::GetCompany()const{
	JDFCompany e=GetElement(elm_Company);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoCustomerInfo::GetCreateCompany(){
	JDFCompany e=GetCreateElement(elm_Company);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoCustomerInfo::AppendCompany(){
	JDFCompany e=AppendElementN(elm_Company,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCustomerInfo::RefCompany(JDFCompany& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoCustomerInfo::GetContact(int iSkip)const{
	JDFContact e=GetElement(elm_Contact,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoCustomerInfo::GetCreateContact(int iSkip){
	JDFContact e=GetCreateElement(elm_Contact,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoCustomerInfo::AppendContact(){
	JDFContact e=AppendElement(elm_Contact);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCustomerInfo::RefContact(JDFContact& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFCustomerMessage JDFAutoCustomerInfo::GetCustomerMessage(int iSkip)const{
	JDFCustomerMessage e=GetElement(elm_CustomerMessage,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCustomerMessage JDFAutoCustomerInfo::GetCreateCustomerMessage(int iSkip){
	JDFCustomerMessage e=GetCreateElement(elm_CustomerMessage,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCustomerMessage JDFAutoCustomerInfo::AppendCustomerMessage(){
	JDFCustomerMessage e=AppendElement(elm_CustomerMessage);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoCustomerInfo::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoCustomerInfo::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoCustomerInfo::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCustomerInfo::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCustomerInfo::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Company);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Company);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCompany().IsValid(level)) {
				vElem.AppendUnique(elm_Company);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Contact);

		for(i=0;i<nElem;i++){
			if (!GetContact(i).IsValid(level)) {
				vElem.AppendUnique(elm_Contact);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CustomerMessage);

		for(i=0;i<nElem;i++){
			if (!GetCustomerMessage(i).IsValid(level)) {
				vElem.AppendUnique(elm_CustomerMessage);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
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
 definition of required elements in the JDF namespace
*/
	WString JDFAutoCustomerInfo::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Company";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoCustomerInfo::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Company,Contact,CustomerMessage,QualityControlResult";
	};
}; // end namespace JDF
