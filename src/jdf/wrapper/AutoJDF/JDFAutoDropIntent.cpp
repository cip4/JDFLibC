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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDropIntent.h"
#include "jdf/wrapper/JDFCompany.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFDropItemIntent.h"
#include "jdf/wrapper/JDFPricing.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDropIntent : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDropIntent& JDFAutoDropIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDropIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDropIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDropIntent::ValidNodeNames()const{
	return L"*:,DropIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDropIntent::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AdditionalAmount,BuyerAccount,Pickup");
};

/**
 typesafe validator
*/
	vWString JDFAutoDropIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAdditionalAmount(level)) {
			vAtts.push_back(atr_AdditionalAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBuyerAccount(level)) {
			vAtts.push_back(atr_BuyerAccount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPickup(level)) {
			vAtts.push_back(atr_Pickup);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AdditionalAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDropIntent::SetAdditionalAmount(int value){
	SetAttribute(atr_AdditionalAmount,WString::valueOf(value));
};
/**
* Get integer attribute AdditionalAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoDropIntent::GetAdditionalAmount() const {
	return GetIntAttribute(atr_AdditionalAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDropIntent::ValidAdditionalAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdditionalAmount,AttributeType_integer,false);
	};
/**
* Set attribute BuyerAccount
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDropIntent::SetBuyerAccount(const WString& value){
	SetAttribute(atr_BuyerAccount,value);
};
/**
* Get string attribute BuyerAccount
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDropIntent::GetBuyerAccount() const {
	return GetAttribute(atr_BuyerAccount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDropIntent::ValidBuyerAccount(EnumValidationLevel level) const {
		return ValidAttribute(atr_BuyerAccount,AttributeType_string,false);
	};
/**
* Set attribute Pickup
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoDropIntent::SetPickup(bool value){
	SetAttribute(atr_Pickup,WString::valueOf(value));
};
/**
* Get bool attribute Pickup
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoDropIntent::GetPickup() const {return GetBoolAttribute(atr_Pickup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDropIntent::ValidPickup(EnumValidationLevel level) const {
		return ValidAttribute(atr_Pickup,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTimeSpan JDFAutoDropIntent::GetEarliest(int iSkip)const{
	JDFTimeSpan e=GetElement(elm_Earliest,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoDropIntent::GetCreateEarliest(int iSkip){
	JDFTimeSpan e=GetCreateElement(elm_Earliest,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoDropIntent::AppendEarliest(){
	JDFTimeSpan e=AppendElement(elm_Earliest);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoDropIntent::GetEarliestDuration(int iSkip)const{
	JDFDurationSpan e=GetElement(elm_EarliestDuration,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoDropIntent::GetCreateEarliestDuration(int iSkip){
	JDFDurationSpan e=GetCreateElement(elm_EarliestDuration,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoDropIntent::AppendEarliestDuration(){
	JDFDurationSpan e=AppendElement(elm_EarliestDuration);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoDropIntent::GetMethod(int iSkip)const{
	JDFNameSpan e=GetElement(elm_Method,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoDropIntent::GetCreateMethod(int iSkip){
	JDFNameSpan e=GetCreateElement(elm_Method,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoDropIntent::AppendMethod(){
	JDFNameSpan e=AppendElement(elm_Method);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoDropIntent::GetRequired(int iSkip)const{
	JDFTimeSpan e=GetElement(elm_Required,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoDropIntent::GetCreateRequired(int iSkip){
	JDFTimeSpan e=GetCreateElement(elm_Required,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoDropIntent::AppendRequired(){
	JDFTimeSpan e=AppendElement(elm_Required);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoDropIntent::GetRequiredDuration(int iSkip)const{
	JDFDurationSpan e=GetElement(elm_RequiredDuration,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoDropIntent::GetCreateRequiredDuration(int iSkip){
	JDFDurationSpan e=GetCreateElement(elm_RequiredDuration,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoDropIntent::AppendRequiredDuration(){
	JDFDurationSpan e=AppendElement(elm_RequiredDuration);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoDropIntent::GetReturnMethod(int iSkip)const{
	JDFNameSpan e=GetElement(elm_ReturnMethod,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoDropIntent::GetCreateReturnMethod(int iSkip){
	JDFNameSpan e=GetCreateElement(elm_ReturnMethod,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoDropIntent::AppendReturnMethod(){
	JDFNameSpan e=AppendElement(elm_ReturnMethod);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoDropIntent::GetServiceLevel(int iSkip)const{
	JDFStringSpan e=GetElement(elm_ServiceLevel,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoDropIntent::GetCreateServiceLevel(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_ServiceLevel,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoDropIntent::AppendServiceLevel(){
	JDFStringSpan e=AppendElement(elm_ServiceLevel);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanSurplusHandling JDFAutoDropIntent::GetSurplusHandling(int iSkip)const{
	JDFSpanSurplusHandling e=GetElement(elm_SurplusHandling,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanSurplusHandling JDFAutoDropIntent::GetCreateSurplusHandling(int iSkip){
	JDFSpanSurplusHandling e=GetCreateElement(elm_SurplusHandling,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanSurplusHandling JDFAutoDropIntent::AppendSurplusHandling(){
	JDFSpanSurplusHandling e=AppendElement(elm_SurplusHandling);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoDropIntent::GetTransfer(int iSkip)const{
	JDFSpanTransfer e=GetElement(elm_Transfer,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoDropIntent::GetCreateTransfer(int iSkip){
	JDFSpanTransfer e=GetCreateElement(elm_Transfer,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoDropIntent::AppendTransfer(){
	JDFSpanTransfer e=AppendElement(elm_Transfer);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoDropIntent::GetCompany(int iSkip)const{
	JDFCompany e=GetElement(elm_Company,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoDropIntent::GetCreateCompany(int iSkip){
	JDFCompany e=GetCreateElement(elm_Company,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoDropIntent::AppendCompany(){
	JDFCompany e=AppendElement(elm_Company);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropIntent::RefCompany(JDFCompany& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDropIntent::GetContact(int iSkip)const{
	JDFContact e=GetElement(elm_Contact,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDropIntent::GetCreateContact(int iSkip){
	JDFContact e=GetCreateElement(elm_Contact,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDropIntent::AppendContact(){
	JDFContact e=AppendElement(elm_Contact);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropIntent::RefContact(JDFContact& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDropItemIntent JDFAutoDropIntent::GetDropItemIntent(int iSkip)const{
	JDFDropItemIntent e=GetElement(elm_DropItemIntent,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDropItemIntent JDFAutoDropIntent::GetCreateDropItemIntent(int iSkip){
	JDFDropItemIntent e=GetCreateElement(elm_DropItemIntent,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDropItemIntent JDFAutoDropIntent::AppendDropItemIntent(){
	JDFDropItemIntent e=AppendElement(elm_DropItemIntent);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPricing JDFAutoDropIntent::GetPricing(int iSkip)const{
	JDFPricing e=GetElement(elm_Pricing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPricing JDFAutoDropIntent::GetCreatePricing(int iSkip){
	JDFPricing e=GetCreateElement(elm_Pricing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPricing JDFAutoDropIntent::AppendPricing(){
	JDFPricing e=AppendElement(elm_Pricing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDropIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Earliest);

		for(i=0;i<nElem;i++){
			if (!GetEarliest(i).IsValid(level)) {
				vElem.AppendUnique(elm_Earliest);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_EarliestDuration);

		for(i=0;i<nElem;i++){
			if (!GetEarliestDuration(i).IsValid(level)) {
				vElem.AppendUnique(elm_EarliestDuration);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Method);

		for(i=0;i<nElem;i++){
			if (!GetMethod(i).IsValid(level)) {
				vElem.AppendUnique(elm_Method);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Required);

		for(i=0;i<nElem;i++){
			if (!GetRequired(i).IsValid(level)) {
				vElem.AppendUnique(elm_Required);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RequiredDuration);

		for(i=0;i<nElem;i++){
			if (!GetRequiredDuration(i).IsValid(level)) {
				vElem.AppendUnique(elm_RequiredDuration);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ReturnMethod);

		for(i=0;i<nElem;i++){
			if (!GetReturnMethod(i).IsValid(level)) {
				vElem.AppendUnique(elm_ReturnMethod);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ServiceLevel);

		for(i=0;i<nElem;i++){
			if (!GetServiceLevel(i).IsValid(level)) {
				vElem.AppendUnique(elm_ServiceLevel);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SurplusHandling);

		for(i=0;i<nElem;i++){
			if (!GetSurplusHandling(i).IsValid(level)) {
				vElem.AppendUnique(elm_SurplusHandling);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Transfer);

		for(i=0;i<nElem;i++){
			if (!GetTransfer(i).IsValid(level)) {
				vElem.AppendUnique(elm_Transfer);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Company);

		for(i=0;i<nElem;i++){
			if (!GetCompany(i).IsValid(level)) {
				vElem.AppendUnique(elm_Company);
				if (++n>=nMax)
					return vElem;
				break;
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
		nElem=NumChildElements(elm_DropItemIntent);

		for(i=0;i<nElem;i++){
			if (!GetDropItemIntent(i).IsValid(level)) {
				vElem.AppendUnique(elm_DropItemIntent);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Pricing);

		for(i=0;i<nElem;i++){
			if (!GetPricing(i).IsValid(level)) {
				vElem.AppendUnique(elm_Pricing);
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
	WString JDFAutoDropIntent::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Earliest,EarliestDuration,Method,Required,RequiredDuration,ReturnMethod,ServiceLevel,SurplusHandling,Transfer,Company,Contact,DropItemIntent,Pricing";
	};
}; // end namespace JDF
