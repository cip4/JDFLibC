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

 
#include "jdf/wrapper/AutoJDF/JDFAutoArtDeliveryIntent.h"
#include "jdf/wrapper/JDFArtDelivery.h"
#include "jdf/wrapper/JDFCompany.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoArtDeliveryIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoArtDeliveryIntent& JDFAutoArtDeliveryIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoArtDeliveryIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoArtDeliveryIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoArtDeliveryIntent::ValidNodeNames()const{
	return L"*:,ArtDeliveryIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoArtDeliveryIntent::OptionalAttributes()const{
		return JDFIntentResource::OptionalAttributes()+WString(L",PreflightStatus,ReturnList");
};

/**
 typesafe validator
*/
	vWString JDFAutoArtDeliveryIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPreflightStatus(level)) {
			vAtts.push_back(atr_PreflightStatus);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReturnList(level)) {
			vAtts.push_back(atr_ReturnList);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoArtDeliveryIntent::PreflightStatusString(){
		static const WString enums=WString(L"Unknown,NotPerformed,WithErrors,WithWarnings,WithoutErrors");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoArtDeliveryIntent::PreflightStatusString(EnumPreflightStatus value){
		return PreflightStatusString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoArtDeliveryIntent::SetPreflightStatus( EnumPreflightStatus value){
	SetEnumAttribute(atr_PreflightStatus,value,PreflightStatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoArtDeliveryIntent::EnumPreflightStatus JDFAutoArtDeliveryIntent:: GetPreflightStatus() const {
	return (EnumPreflightStatus) GetEnumAttribute(atr_PreflightStatus,PreflightStatusString(),WString::emptyStr,PreflightStatus_NotPerformed);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDeliveryIntent::ValidPreflightStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreflightStatus,PreflightStatusString(),false);
	};
/**
* Set attribute ReturnList
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoArtDeliveryIntent::SetReturnList(const vWString& value){
	SetAttribute(atr_ReturnList,value);
};
/**
* Get string attribute ReturnList
* @return vWString the vaue of the attribute ; defaults to None
*/
	 vWString JDFAutoArtDeliveryIntent::GetReturnList() const {
	return GetAttribute(atr_ReturnList,WString::emptyStr,L"None");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDeliveryIntent::ValidReturnList(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReturnList,AttributeType_NMTOKENS,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTimeSpan JDFAutoArtDeliveryIntent::GetArtDeliveryDate()const{
	JDFTimeSpan e=GetElement(elm_ArtDeliveryDate);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoArtDeliveryIntent::GetCreateArtDeliveryDate(){
	JDFTimeSpan e=GetCreateElement(elm_ArtDeliveryDate);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoArtDeliveryIntent::AppendArtDeliveryDate(){
	JDFTimeSpan e=AppendElementN(elm_ArtDeliveryDate,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoArtDeliveryIntent::GetArtDeliveryDuration()const{
	JDFDurationSpan e=GetElement(elm_ArtDeliveryDuration);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoArtDeliveryIntent::GetCreateArtDeliveryDuration(){
	JDFDurationSpan e=GetCreateElement(elm_ArtDeliveryDuration);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoArtDeliveryIntent::AppendArtDeliveryDuration(){
	JDFDurationSpan e=AppendElementN(elm_ArtDeliveryDuration,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanArtHandling JDFAutoArtDeliveryIntent::GetArtHandling()const{
	JDFSpanArtHandling e=GetElement(elm_ArtHandling);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanArtHandling JDFAutoArtDeliveryIntent::GetCreateArtHandling(){
	JDFSpanArtHandling e=GetCreateElement(elm_ArtHandling);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanArtHandling JDFAutoArtDeliveryIntent::AppendArtHandling(){
	JDFSpanArtHandling e=AppendElementN(elm_ArtHandling,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanDeliveryCharge JDFAutoArtDeliveryIntent::GetDeliveryCharge()const{
	JDFSpanDeliveryCharge e=GetElement(elm_DeliveryCharge);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanDeliveryCharge JDFAutoArtDeliveryIntent::GetCreateDeliveryCharge(){
	JDFSpanDeliveryCharge e=GetCreateElement(elm_DeliveryCharge);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanDeliveryCharge JDFAutoArtDeliveryIntent::AppendDeliveryCharge(){
	JDFSpanDeliveryCharge e=AppendElementN(elm_DeliveryCharge,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDeliveryIntent::GetMethod()const{
	JDFNameSpan e=GetElement(elm_Method);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDeliveryIntent::GetCreateMethod(){
	JDFNameSpan e=GetCreateElement(elm_Method);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDeliveryIntent::AppendMethod(){
	JDFNameSpan e=AppendElementN(elm_Method,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDeliveryIntent::GetReturnMethod()const{
	JDFNameSpan e=GetElement(elm_ReturnMethod);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDeliveryIntent::GetCreateReturnMethod(){
	JDFNameSpan e=GetCreateElement(elm_ReturnMethod);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDeliveryIntent::AppendReturnMethod(){
	JDFNameSpan e=AppendElementN(elm_ReturnMethod,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoArtDeliveryIntent::GetServiceLevel()const{
	JDFStringSpan e=GetElement(elm_ServiceLevel);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoArtDeliveryIntent::GetCreateServiceLevel(){
	JDFStringSpan e=GetCreateElement(elm_ServiceLevel);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoArtDeliveryIntent::AppendServiceLevel(){
	JDFStringSpan e=AppendElementN(elm_ServiceLevel,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoArtDeliveryIntent::GetTransfer()const{
	JDFSpanTransfer e=GetElement(elm_Transfer);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoArtDeliveryIntent::GetCreateTransfer(){
	JDFSpanTransfer e=GetCreateElement(elm_Transfer);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoArtDeliveryIntent::AppendTransfer(){
	JDFSpanTransfer e=AppendElementN(elm_Transfer,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFArtDelivery JDFAutoArtDeliveryIntent::GetArtDelivery(int iSkip)const{
	JDFArtDelivery e=GetElement(elm_ArtDelivery,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFArtDelivery JDFAutoArtDeliveryIntent::GetCreateArtDelivery(int iSkip){
	JDFArtDelivery e=GetCreateElement(elm_ArtDelivery,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFArtDelivery JDFAutoArtDeliveryIntent::AppendArtDelivery(){
	JDFArtDelivery e=AppendElement(elm_ArtDelivery);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoArtDeliveryIntent::GetCompany()const{
	JDFCompany e=GetElement(elm_Company);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoArtDeliveryIntent::GetCreateCompany(){
	JDFCompany e=GetCreateElement(elm_Company);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoArtDeliveryIntent::AppendCompany(){
	JDFCompany e=AppendElementN(elm_Company,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDeliveryIntent::RefCompany(JDFCompany& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoArtDeliveryIntent::GetContact(int iSkip)const{
	JDFContact e=GetElement(elm_Contact,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoArtDeliveryIntent::GetCreateContact(int iSkip){
	JDFContact e=GetCreateElement(elm_Contact,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoArtDeliveryIntent::AppendContact(){
	JDFContact e=AppendElement(elm_Contact);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDeliveryIntent::RefContact(JDFContact& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoArtDeliveryIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ArtDeliveryDate);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ArtDeliveryDate);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetArtDeliveryDate().IsValid(level)) {
				vElem.AppendUnique(elm_ArtDeliveryDate);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ArtDeliveryDuration);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ArtDeliveryDuration);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetArtDeliveryDuration().IsValid(level)) {
				vElem.AppendUnique(elm_ArtDeliveryDuration);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ArtHandling);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ArtHandling);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetArtHandling().IsValid(level)) {
				vElem.AppendUnique(elm_ArtHandling);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_DeliveryCharge);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DeliveryCharge);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDeliveryCharge().IsValid(level)) {
				vElem.AppendUnique(elm_DeliveryCharge);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Method);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Method);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMethod().IsValid(level)) {
				vElem.AppendUnique(elm_Method);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ReturnMethod);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ReturnMethod);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetReturnMethod().IsValid(level)) {
				vElem.AppendUnique(elm_ReturnMethod);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ServiceLevel);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ServiceLevel);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetServiceLevel().IsValid(level)) {
				vElem.AppendUnique(elm_ServiceLevel);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Transfer);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Transfer);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTransfer().IsValid(level)) {
				vElem.AppendUnique(elm_Transfer);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ArtDelivery);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_ArtDelivery);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetArtDelivery(i).IsValid(level)) {
				vElem.AppendUnique(elm_ArtDelivery);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
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
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoArtDeliveryIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",ArtDeliveryDate,ArtDeliveryDuration,ArtHandling,DeliveryCharge,Method,ReturnMethod,ServiceLevel,Transfer,Company";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoArtDeliveryIntent::RequiredElements()const{
		return JDFIntentResource::RequiredElements()+L",ArtDelivery";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoArtDeliveryIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",ArtDeliveryDate,ArtDeliveryDuration,ArtHandling,DeliveryCharge,Method,ReturnMethod,ServiceLevel,Transfer,Company,Contact";
	};
}; // end namespace JDF
