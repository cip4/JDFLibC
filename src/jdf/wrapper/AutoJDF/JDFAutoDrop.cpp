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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDrop.h"
#include "jdf/wrapper/JDFCompany.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFDropItem.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDrop : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDrop& JDFAutoDrop::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDrop: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDrop::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDrop::ValidNodeNames()const{
	return L"*:,Drop";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDrop::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Earliest,Method,Pickup,Required,ServiceLevel,TrackingID,Transfer");
};

/**
 typesafe validator
*/
	vWString JDFAutoDrop::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
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
		if(!ValidTrackingID(level)) {
			vAtts.push_back(atr_TrackingID);
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
	 void JDFAutoDrop::SetEarliest(JDFDate value){
	SetAttribute(atr_Earliest,value.DateTimeISO());
};
/**
* Get string attribute Earliest
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoDrop::GetEarliest() const {
	return GetAttribute(atr_Earliest,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDrop::ValidEarliest(EnumValidationLevel level) const {
		return ValidAttribute(atr_Earliest,AttributeType_dateTime,false);
	};
/**
* Set attribute Method
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDrop::SetMethod(const WString& value){
	SetAttribute(atr_Method,value);
};
/**
* Get string attribute Method
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDrop::GetMethod() const {
	return GetAttribute(atr_Method,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDrop::ValidMethod(EnumValidationLevel level) const {
		return ValidAttribute(atr_Method,AttributeType_string,false);
	};
/**
* Set attribute Pickup
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoDrop::SetPickup(bool value){
	SetAttribute(atr_Pickup,WString::valueOf(value));
};
/**
* Get bool attribute Pickup
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoDrop::GetPickup() const {return GetBoolAttribute(atr_Pickup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDrop::ValidPickup(EnumValidationLevel level) const {
		return ValidAttribute(atr_Pickup,AttributeType_boolean,false);
	};
/**
* Set attribute Required
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoDrop::SetRequired(JDFDate value){
	SetAttribute(atr_Required,value.DateTimeISO());
};
/**
* Get string attribute Required
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoDrop::GetRequired() const {
	return GetAttribute(atr_Required,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDrop::ValidRequired(EnumValidationLevel level) const {
		return ValidAttribute(atr_Required,AttributeType_dateTime,false);
	};
/**
* Set attribute ServiceLevel
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDrop::SetServiceLevel(const WString& value){
	SetAttribute(atr_ServiceLevel,value);
};
/**
* Get string attribute ServiceLevel
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDrop::GetServiceLevel() const {
	return GetAttribute(atr_ServiceLevel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDrop::ValidServiceLevel(EnumValidationLevel level) const {
		return ValidAttribute(atr_ServiceLevel,AttributeType_string,false);
	};
/**
* Set attribute TrackingID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDrop::SetTrackingID(const WString& value){
	SetAttribute(atr_TrackingID,value);
};
/**
* Get string attribute TrackingID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDrop::GetTrackingID() const {
	return GetAttribute(atr_TrackingID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDrop::ValidTrackingID(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrackingID,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDrop::TransferString(){
		static const WString enums=WString(L"Unknown,BuyerToPrinterDeliver,BuyerToPrinterPickup,PrinterToBuyerDeliver,PrinterToBuyerPickup");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDrop::TransferString(EnumTransfer value){
		return TransferString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDrop::SetTransfer( EnumTransfer value){
	SetEnumAttribute(atr_Transfer,value,TransferString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDrop::EnumTransfer JDFAutoDrop:: GetTransfer() const {
	return (EnumTransfer) GetEnumAttribute(atr_Transfer,TransferString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDrop::ValidTransfer(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Transfer,TransferString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCompany JDFAutoDrop::GetCompany(int iSkip)const{
	JDFCompany e=GetElement(elm_Company,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoDrop::GetCreateCompany(int iSkip){
	JDFCompany e=GetCreateElement(elm_Company,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoDrop::AppendCompany(){
	JDFCompany e=AppendElement(elm_Company);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDrop::RefCompany(JDFCompany& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDrop::GetContact(int iSkip)const{
	JDFContact e=GetElement(elm_Contact,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDrop::GetCreateContact(int iSkip){
	JDFContact e=GetCreateElement(elm_Contact,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoDrop::AppendContact(){
	JDFContact e=AppendElement(elm_Contact);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDrop::RefContact(JDFContact& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDropItem JDFAutoDrop::GetDropItem(int iSkip)const{
	JDFDropItem e=GetElement(elm_DropItem,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDropItem JDFAutoDrop::GetCreateDropItem(int iSkip){
	JDFDropItem e=GetCreateElement(elm_DropItem,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDropItem JDFAutoDrop::AppendDropItem(){
	JDFDropItem e=AppendElement(elm_DropItem);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDrop::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
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
		nElem=NumChildElements(elm_DropItem);

		for(i=0;i<nElem;i++){
			if (!GetDropItem(i).IsValid(level)) {
				vElem.AppendUnique(elm_DropItem);
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
	WString JDFAutoDrop::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Company,Contact,DropItem";
	};
}; // end namespace JDF
