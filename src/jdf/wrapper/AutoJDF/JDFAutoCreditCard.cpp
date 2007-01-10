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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCreditCard.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCreditCard : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCreditCard& JDFAutoCreditCard::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCreditCard: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCreditCard::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCreditCard::ValidNodeNames()const{
	return L"*:,CreditCard";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoCreditCard::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Expires,Number,Type";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCreditCard::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Authorization,AuthorizationExpires");
};

/**
 typesafe validator
*/
	vWString JDFAutoCreditCard::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAuthorization(level)) {
			vAtts.push_back(atr_Authorization);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAuthorizationExpires(level)) {
			vAtts.push_back(atr_AuthorizationExpires);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidExpires(level)) {
			vAtts.push_back(atr_Expires);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumber(level)) {
			vAtts.push_back(atr_Number);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Authorization
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCreditCard::SetAuthorization(const WString& value){
	SetAttribute(atr_Authorization,value);
};
/**
* Get string attribute Authorization
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCreditCard::GetAuthorization() const {
	return GetAttribute(atr_Authorization,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreditCard::ValidAuthorization(EnumValidationLevel level) const {
		return ValidAttribute(atr_Authorization,AttributeType_string,false);
	};
/**
* Set attribute AuthorizationExpires
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoCreditCard::SetAuthorizationExpires(JDFDate value){
	SetAttribute(atr_AuthorizationExpires,value.DateTimeISO());
};
/**
* Get string attribute AuthorizationExpires
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoCreditCard::GetAuthorizationExpires() const {
	return GetAttribute(atr_AuthorizationExpires,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreditCard::ValidAuthorizationExpires(EnumValidationLevel level) const {
		return ValidAttribute(atr_AuthorizationExpires,AttributeType_Any,false);
	};
/**
* Set attribute Expires
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoCreditCard::SetExpires(JDFDate value){
	SetAttribute(atr_Expires,value.DateTimeISO());
};
/**
* Get string attribute Expires
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoCreditCard::GetExpires() const {
	return GetAttribute(atr_Expires,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreditCard::ValidExpires(EnumValidationLevel level) const {
		return ValidAttribute(atr_Expires,AttributeType_Any,RequiredLevel(level));
	};
/**
* Set attribute Number
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCreditCard::SetNumber(const WString& value){
	SetAttribute(atr_Number,value);
};
/**
* Get string attribute Number
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCreditCard::GetNumber() const {
	return GetAttribute(atr_Number,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreditCard::ValidNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_Number,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCreditCard::SetType(const WString& value){
	SetAttribute(atr_Type,value);
};
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCreditCard::GetType() const {
	return GetAttribute(atr_Type,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreditCard::ValidType(EnumValidationLevel level) const {
		return ValidAttribute(atr_Type,AttributeType_NMTOKEN,RequiredLevel(level));
	};
}; // end namespace JDF
