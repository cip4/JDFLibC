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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDeliveryParams.h"
#include "jdf/wrapper/JDFCompany.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFDrop.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDeliveryParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDeliveryParams& JDFAutoDeliveryParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDeliveryParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDeliveryParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDeliveryParams::ValidNodeNames()const{
	return L"*:,DeliveryParams";
};

bool JDFAutoDeliveryParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoDeliveryParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDeliveryParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Earliest,Method,Pickup,Required,ServiceLevel,Transfer");
};

/**
 typesafe validator
*/
	vWString JDFAutoDeliveryParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidEarliest(level)) {
			vAtts.push_back(atr_Earliest);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMethod(level)) {
			vAtts.push_back(atr_Method);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPickup(level)) {
			vAtts.push_back(atr_Pickup);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRequired(level)) {
			vAtts.push_back(atr_Required);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidServiceLevel(level)) {
			vAtts.push_back(atr_ServiceLevel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransfer(level)) {
			vAtts.push_back(atr_Transfer);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Earliest
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoDeliveryParams::SetEarliest(JDFDate value){
	SetAttribute(atr_Earliest,value.DateTimeISO());
};
/**
* Get string attribute Earliest
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoDeliveryParams::GetEarliest() const {
	return GetAttribute(atr_Earliest,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeliveryParams::ValidEarliest(EnumValidationLevel level) const {
		return ValidAttribute(atr_Earliest,AttributeType_dateTime,false);
	};
/**
* Set attribute Method
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDeliveryParams::SetMethod(const WString& value){
	SetAttribute(atr_Method,value);
};
/**
* Get string attribute Method
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDeliveryParams::GetMethod() const {
	return GetAttribute(atr_Method,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeliveryParams::ValidMethod(EnumValidationLevel level) const {
		return ValidAttribute(atr_Method,AttributeType_string,false);
	};
/**
* Set attribute Pickup
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoDeliveryParams::SetPickup(bool value){
	SetAttribute(atr_Pickup,WString::valueOf(value));
};
/**
* Get bool attribute Pickup
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoDeliveryParams::GetPickup() const {return GetBoolAttribute(atr_Pickup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeliveryParams::ValidPickup(EnumValidationLevel level) const {
		return ValidAttribute(atr_Pickup,AttributeType_boolean,false);
	};
/**
* Set attribute Required
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoDeliveryParams::SetRequired(JDFDate value){
	SetAttribute(atr_Required,value.DateTimeISO());
};
/**
* Get string attribute Required
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoDeliveryParams::GetRequired() const {
	return GetAttribute(atr_Required,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeliveryParams::ValidRequired(EnumValidationLevel level) const {
		return ValidAttribute(atr_Required,AttributeType_dateTime,false);
	};
/**
* Set attribute ServiceLevel
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDeliveryParams::SetServiceLevel(const WString& value){
	SetAttribute(atr_ServiceLevel,value);
};
/**
* Get string attribute ServiceLevel
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDeliveryParams::GetServiceLevel() const {
	return GetAttribute(atr_ServiceLevel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeliveryParams::ValidServiceLevel(EnumValidationLevel level) const {
		return ValidAttribute(atr_ServiceLevel,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeliveryParams::TransferString(){
		static const WString enums=WString(L"Unknown,BuyerToPrinterDeliver,BuyerToPrinterPickup,PrinterToBuyerDeliver,PrinterToBuyerPickup");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeliveryParams::TransferString(EnumTransfer value){
		return TransferString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeliveryParams::SetTransfer( EnumTransfer value){
	SetEnumAttribute(atr_Transfer,value,TransferString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeliveryParams::EnumTransfer JDFAutoDeliveryParams:: GetTransfer() const {
	return (EnumTransfer) GetEnumAttribute(atr_Transfer,TransferString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeliveryParams::ValidTransfer(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Transfer,TransferString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCompany JDFAutoDeliveryParams::GetCompany(int iSkip)const{
	JDFCompany e=GetElement(elm_Company,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoDeliveryParams::GetCreateCompany(int iSkip){
	JDFCompany e=GetCreateElement(elm_Company,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoDeliveryParams::AppendCompany(){
	JDFCompany e=AppendElement(elm_Company);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDeliveryParams::RefCompany(JDFCompany& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDeliveryParams::GetContact(int iSkip)const{
	JDFContact e=GetElement(elm_Contact,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDeliveryParams::GetCreateContact(int iSkip){
	JDFContact e=GetCreateElement(elm_Contact,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDeliveryParams::AppendContact(){
	JDFContact e=AppendElement(elm_Contact);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDeliveryParams::RefContact(JDFContact& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDrop JDFAutoDeliveryParams::GetDrop(int iSkip)const{
	JDFDrop e=GetElement(elm_Drop,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDrop JDFAutoDeliveryParams::GetCreateDrop(int iSkip){
	JDFDrop e=GetCreateElement(elm_Drop,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDrop JDFAutoDeliveryParams::AppendDrop(){
	JDFDrop e=AppendElement(elm_Drop);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDeliveryParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
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
		nElem=NumChildElements(elm_Drop);

		for(i=0;i<nElem;i++){
			if (!GetDrop(i).IsValid(level)) {
				vElem.AppendUnique(elm_Drop);
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
	WString JDFAutoDeliveryParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Company,Contact,Drop";
	};
}; // end namespace JDF
