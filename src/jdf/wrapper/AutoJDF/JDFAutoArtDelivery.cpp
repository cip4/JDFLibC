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

 
#include "jdf/wrapper/AutoJDF/JDFAutoArtDelivery.h"
#include "jdf/wrapper/JDFCompany.h"
#include "jdf/wrapper/JDFComponent.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFDigitalMedia.h"
#include "jdf/wrapper/JDFExposedMedia.h"
#include "jdf/wrapper/JDFRunList.h"
#include "jdf/wrapper/JDFScanParams.h"
#include "jdf/wrapper/JDFTool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoArtDelivery : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoArtDelivery& JDFAutoArtDelivery::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoArtDelivery: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoArtDelivery::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoArtDelivery::ValidNodeNames()const{
	return L"*:,ArtDelivery";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoArtDelivery::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ArtDeliveryType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoArtDelivery::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Amount,HasBleeds,IsTrapped,PageList,PreflightOutput,PreflightStatus");
};

/**
 typesafe validator
*/
	vWString JDFAutoArtDelivery::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAmount(level)) {
			vAtts.push_back(atr_Amount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidArtDeliveryType(level)) {
			vAtts.push_back(atr_ArtDeliveryType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasBleeds(level)) {
			vAtts.push_back(atr_HasBleeds);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsTrapped(level)) {
			vAtts.push_back(atr_IsTrapped);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageList(level)) {
			vAtts.push_back(atr_PageList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreflightOutput(level)) {
			vAtts.push_back(atr_PreflightOutput);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreflightStatus(level)) {
			vAtts.push_back(atr_PreflightStatus);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Amount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoArtDelivery::SetAmount(int value){
	SetAttribute(atr_Amount,WString::valueOf(value));
};
/**
* Get integer attribute Amount
* @return int the vaue of the attribute 
*/
	 int JDFAutoArtDelivery::GetAmount() const {
	return GetIntAttribute(atr_Amount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDelivery::ValidAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Amount,AttributeType_integer,false);
	};
/**
* Set attribute ArtDeliveryType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoArtDelivery::SetArtDeliveryType(const WString& value){
	SetAttribute(atr_ArtDeliveryType,value);
};
/**
* Get string attribute ArtDeliveryType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoArtDelivery::GetArtDeliveryType() const {
	return GetAttribute(atr_ArtDeliveryType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDelivery::ValidArtDeliveryType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ArtDeliveryType,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute HasBleeds
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoArtDelivery::SetHasBleeds(bool value){
	SetAttribute(atr_HasBleeds,WString::valueOf(value));
};
/**
* Get bool attribute HasBleeds
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoArtDelivery::GetHasBleeds() const {return GetBoolAttribute(atr_HasBleeds,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDelivery::ValidHasBleeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasBleeds,AttributeType_boolean,false);
	};
/**
* Set attribute IsTrapped
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoArtDelivery::SetIsTrapped(bool value){
	SetAttribute(atr_IsTrapped,WString::valueOf(value));
};
/**
* Get bool attribute IsTrapped
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoArtDelivery::GetIsTrapped() const {return GetBoolAttribute(atr_IsTrapped,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDelivery::ValidIsTrapped(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsTrapped,AttributeType_boolean,false);
	};
/**
* Set attribute PageList
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoArtDelivery::SetPageList(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageList,value.GetString());
};
/**
* Get range attribute PageList
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoArtDelivery::GetPageList() const {
	return GetAttribute(atr_PageList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDelivery::ValidPageList(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageList,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute PreflightOutput
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoArtDelivery::SetPreflightOutput(const WString& value){
	SetAttribute(atr_PreflightOutput,value);
};
/**
* Get string attribute PreflightOutput
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoArtDelivery::GetPreflightOutput() const {
	return GetAttribute(atr_PreflightOutput,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDelivery::ValidPreflightOutput(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreflightOutput,AttributeType_URL,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoArtDelivery::PreflightStatusString(){
		static const WString enums=WString(L"Unknown,NotPerformed,WithErrors,WithWarnings,WithoutErrors");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoArtDelivery::PreflightStatusString(EnumPreflightStatus value){
		return PreflightStatusString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoArtDelivery::SetPreflightStatus( EnumPreflightStatus value){
	SetEnumAttribute(atr_PreflightStatus,value,PreflightStatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoArtDelivery::EnumPreflightStatus JDFAutoArtDelivery:: GetPreflightStatus() const {
	return (EnumPreflightStatus) GetEnumAttribute(atr_PreflightStatus,PreflightStatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoArtDelivery::ValidPreflightStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreflightStatus,PreflightStatusString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTimeSpan JDFAutoArtDelivery::GetArtDeliveryDate()const{
	JDFTimeSpan e=GetElement(elm_ArtDeliveryDate);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoArtDelivery::GetCreateArtDeliveryDate(){
	JDFTimeSpan e=GetCreateElement(elm_ArtDeliveryDate);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTimeSpan JDFAutoArtDelivery::AppendArtDeliveryDate(){
	JDFTimeSpan e=AppendElementN(elm_ArtDeliveryDate,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoArtDelivery::GetArtDeliveryDuration()const{
	JDFDurationSpan e=GetElement(elm_ArtDeliveryDuration);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoArtDelivery::GetCreateArtDeliveryDuration(){
	JDFDurationSpan e=GetCreateElement(elm_ArtDeliveryDuration);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationSpan JDFAutoArtDelivery::AppendArtDeliveryDuration(){
	JDFDurationSpan e=AppendElementN(elm_ArtDeliveryDuration,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanArtHandling JDFAutoArtDelivery::GetArtHandling()const{
	JDFSpanArtHandling e=GetElement(elm_ArtHandling);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanArtHandling JDFAutoArtDelivery::GetCreateArtHandling(){
	JDFSpanArtHandling e=GetCreateElement(elm_ArtHandling);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanArtHandling JDFAutoArtDelivery::AppendArtHandling(){
	JDFSpanArtHandling e=AppendElementN(elm_ArtHandling,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanDeliveryCharge JDFAutoArtDelivery::GetDeliveryCharge()const{
	JDFSpanDeliveryCharge e=GetElement(elm_DeliveryCharge);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanDeliveryCharge JDFAutoArtDelivery::GetCreateDeliveryCharge(){
	JDFSpanDeliveryCharge e=GetCreateElement(elm_DeliveryCharge);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanDeliveryCharge JDFAutoArtDelivery::AppendDeliveryCharge(){
	JDFSpanDeliveryCharge e=AppendElementN(elm_DeliveryCharge,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDelivery::GetMethod()const{
	JDFNameSpan e=GetElement(elm_Method);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDelivery::GetCreateMethod(){
	JDFNameSpan e=GetCreateElement(elm_Method);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDelivery::AppendMethod(){
	JDFNameSpan e=AppendElementN(elm_Method,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDelivery::GetReturnMethod()const{
	JDFNameSpan e=GetElement(elm_ReturnMethod);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDelivery::GetCreateReturnMethod(){
	JDFNameSpan e=GetCreateElement(elm_ReturnMethod);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoArtDelivery::AppendReturnMethod(){
	JDFNameSpan e=AppendElementN(elm_ReturnMethod,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoArtDelivery::GetServiceLevel()const{
	JDFStringSpan e=GetElement(elm_ServiceLevel);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoArtDelivery::GetCreateServiceLevel(){
	JDFStringSpan e=GetCreateElement(elm_ServiceLevel);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoArtDelivery::AppendServiceLevel(){
	JDFStringSpan e=AppendElementN(elm_ServiceLevel,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoArtDelivery::GetTransfer()const{
	JDFSpanTransfer e=GetElement(elm_Transfer);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoArtDelivery::GetCreateTransfer(){
	JDFSpanTransfer e=GetCreateElement(elm_Transfer);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTransfer JDFAutoArtDelivery::AppendTransfer(){
	JDFSpanTransfer e=AppendElementN(elm_Transfer,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoArtDelivery::GetCompany()const{
	JDFCompany e=GetElement(elm_Company);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoArtDelivery::GetCreateCompany(){
	JDFCompany e=GetCreateElement(elm_Company);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoArtDelivery::AppendCompany(){
	JDFCompany e=AppendElementN(elm_Company,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDelivery::RefCompany(JDFCompany& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoArtDelivery::GetComponent()const{
	JDFComponent e=GetElement(elm_Component);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoArtDelivery::GetCreateComponent(){
	JDFComponent e=GetCreateElement(elm_Component);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoArtDelivery::AppendComponent(){
	JDFComponent e=AppendElementN(elm_Component,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDelivery::RefComponent(JDFComponent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoArtDelivery::GetContact(int iSkip)const{
	JDFContact e=GetElement(elm_Contact,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoArtDelivery::GetCreateContact(int iSkip){
	JDFContact e=GetCreateElement(elm_Contact,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoArtDelivery::AppendContact(){
	JDFContact e=AppendElement(elm_Contact);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDelivery::RefContact(JDFContact& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDigitalMedia JDFAutoArtDelivery::GetDigitalMedia()const{
	JDFDigitalMedia e=GetElement(elm_DigitalMedia);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDigitalMedia JDFAutoArtDelivery::GetCreateDigitalMedia(){
	JDFDigitalMedia e=GetCreateElement(elm_DigitalMedia);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDigitalMedia JDFAutoArtDelivery::AppendDigitalMedia(){
	JDFDigitalMedia e=AppendElementN(elm_DigitalMedia,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDelivery::RefDigitalMedia(JDFDigitalMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFExposedMedia JDFAutoArtDelivery::GetExposedMedia()const{
	JDFExposedMedia e=GetElement(elm_ExposedMedia);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFExposedMedia JDFAutoArtDelivery::GetCreateExposedMedia(){
	JDFExposedMedia e=GetCreateElement(elm_ExposedMedia);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFExposedMedia JDFAutoArtDelivery::AppendExposedMedia(){
	JDFExposedMedia e=AppendElementN(elm_ExposedMedia,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDelivery::RefExposedMedia(JDFExposedMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoArtDelivery::GetRunList()const{
	JDFRunList e=GetElement(elm_RunList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoArtDelivery::GetCreateRunList(){
	JDFRunList e=GetCreateElement(elm_RunList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoArtDelivery::AppendRunList(){
	JDFRunList e=AppendElementN(elm_RunList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDelivery::RefRunList(JDFRunList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFScanParams JDFAutoArtDelivery::GetScanParams()const{
	JDFScanParams e=GetElement(elm_ScanParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScanParams JDFAutoArtDelivery::GetCreateScanParams(){
	JDFScanParams e=GetCreateElement(elm_ScanParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScanParams JDFAutoArtDelivery::AppendScanParams(){
	JDFScanParams e=AppendElementN(elm_ScanParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDelivery::RefScanParams(JDFScanParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFTool JDFAutoArtDelivery::GetTool()const{
	JDFTool e=GetElement(elm_Tool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTool JDFAutoArtDelivery::GetCreateTool(){
	JDFTool e=GetCreateElement(elm_Tool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTool JDFAutoArtDelivery::AppendTool(){
	JDFTool e=AppendElementN(elm_Tool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoArtDelivery::RefTool(JDFTool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoArtDelivery::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
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
		nElem=NumChildElements(elm_Component);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Component);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetComponent().IsValid(level)) {
				vElem.AppendUnique(elm_Component);
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
		nElem=NumChildElements(elm_DigitalMedia);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DigitalMedia);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDigitalMedia().IsValid(level)) {
				vElem.AppendUnique(elm_DigitalMedia);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ExposedMedia);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ExposedMedia);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetExposedMedia().IsValid(level)) {
				vElem.AppendUnique(elm_ExposedMedia);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_RunList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_RunList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetRunList().IsValid(level)) {
				vElem.AppendUnique(elm_RunList);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ScanParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ScanParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetScanParams().IsValid(level)) {
				vElem.AppendUnique(elm_ScanParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Tool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Tool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTool().IsValid(level)) {
				vElem.AppendUnique(elm_Tool);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoArtDelivery::UniqueElements()const{
		return JDFElement::UniqueElements()+L",ArtDeliveryDate,ArtDeliveryDuration,ArtHandling,DeliveryCharge,Method,ReturnMethod,ServiceLevel,Transfer,Company,Component,DigitalMedia,ExposedMedia,RunList,ScanParams,Tool";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoArtDelivery::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ArtDeliveryDate,ArtDeliveryDuration,ArtHandling,DeliveryCharge,Method,ReturnMethod,ServiceLevel,Transfer,Company,Component,Contact,DigitalMedia,ExposedMedia,RunList,ScanParams,Tool";
	};
}; // end namespace JDF
