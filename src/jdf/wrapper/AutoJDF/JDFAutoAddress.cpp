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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAddress.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAddress : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAddress& JDFAutoAddress::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAddress: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAddress::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAddress::ValidNodeNames()const{
	return L"*:,Address";
};

bool JDFAutoAddress::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoAddress::init(){
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
	WString JDFAutoAddress::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",City,Country,CountryCode,PostBox,PostalCode,Region,Street");
};

/**
 typesafe validator
*/
	vWString JDFAutoAddress::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCity(level)) {
			vAtts.push_back(atr_City);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCountry(level)) {
			vAtts.push_back(atr_Country);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCountryCode(level)) {
			vAtts.push_back(atr_CountryCode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPostBox(level)) {
			vAtts.push_back(atr_PostBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPostalCode(level)) {
			vAtts.push_back(atr_PostalCode);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRegion(level)) {
			vAtts.push_back(atr_Region);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStreet(level)) {
			vAtts.push_back(atr_Street);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute City
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAddress::SetCity(const WString& value){
	SetAttribute(atr_City,value);
};
/**
* Get string attribute City
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAddress::GetCity() const {
	return GetAttribute(atr_City,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAddress::ValidCity(EnumValidationLevel level) const {
		return ValidAttribute(atr_City,AttributeType_string,false);
	};
/**
* Set attribute Country
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAddress::SetCountry(const WString& value){
	SetAttribute(atr_Country,value);
};
/**
* Get string attribute Country
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAddress::GetCountry() const {
	return GetAttribute(atr_Country,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAddress::ValidCountry(EnumValidationLevel level) const {
		return ValidAttribute(atr_Country,AttributeType_string,false);
	};
/**
* Set attribute CountryCode
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAddress::SetCountryCode(const WString& value){
	SetAttribute(atr_CountryCode,value);
};
/**
* Get string attribute CountryCode
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAddress::GetCountryCode() const {
	return GetAttribute(atr_CountryCode,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAddress::ValidCountryCode(EnumValidationLevel level) const {
		return ValidAttribute(atr_CountryCode,AttributeType_string,false);
	};
/**
* Set attribute PostBox
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAddress::SetPostBox(const WString& value){
	SetAttribute(atr_PostBox,value);
};
/**
* Get string attribute PostBox
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAddress::GetPostBox() const {
	return GetAttribute(atr_PostBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAddress::ValidPostBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_PostBox,AttributeType_string,false);
	};
/**
* Set attribute PostalCode
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAddress::SetPostalCode(const WString& value){
	SetAttribute(atr_PostalCode,value);
};
/**
* Get string attribute PostalCode
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAddress::GetPostalCode() const {
	return GetAttribute(atr_PostalCode,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAddress::ValidPostalCode(EnumValidationLevel level) const {
		return ValidAttribute(atr_PostalCode,AttributeType_string,false);
	};
/**
* Set attribute Region
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAddress::SetRegion(const WString& value){
	SetAttribute(atr_Region,value);
};
/**
* Get string attribute Region
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAddress::GetRegion() const {
	return GetAttribute(atr_Region,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAddress::ValidRegion(EnumValidationLevel level) const {
		return ValidAttribute(atr_Region,AttributeType_string,false);
	};
/**
* Set attribute Street
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAddress::SetStreet(const WString& value){
	SetAttribute(atr_Street,value);
};
/**
* Get string attribute Street
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAddress::GetStreet() const {
	return GetAttribute(atr_Street,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAddress::ValidStreet(EnumValidationLevel level) const {
		return ValidAttribute(atr_Street,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFElement JDFAutoAddress::GetExtendedAddress()const{
	JDFElement e=GetElement(elm_ExtendedAddress);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElement JDFAutoAddress::GetCreateExtendedAddress(){
	JDFElement e=GetCreateElement(elm_ExtendedAddress);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElement JDFAutoAddress::AppendExtendedAddress(){
	JDFElement e=AppendElementN(elm_ExtendedAddress,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoAddress::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ExtendedAddress);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ExtendedAddress);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetExtendedAddress().IsValid(level)) {
				vElem.AppendUnique(elm_ExtendedAddress);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoAddress::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ExtendedAddress";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoAddress::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ExtendedAddress";
	};
}; // end namespace JDF
