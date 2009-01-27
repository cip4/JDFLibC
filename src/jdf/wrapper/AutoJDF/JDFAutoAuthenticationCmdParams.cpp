/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAuthenticationCmdParams.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAuthenticationCmdParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAuthenticationCmdParams& JDFAutoAuthenticationCmdParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAuthenticationCmdParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAuthenticationCmdParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAuthenticationCmdParams::ValidNodeNames()const{
	return L"*:,AuthenticationCmdParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoAuthenticationCmdParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AuthenticationType,Reason,ReasonDetails,URL");
};

/**
 typesafe validator
*/
	vWString JDFAutoAuthenticationCmdParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAuthenticationType(level)) {
			vAtts.push_back(atr_AuthenticationType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReason(level)) {
			vAtts.push_back(atr_Reason);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReasonDetails(level)) {
			vAtts.push_back(atr_ReasonDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURL(level)) {
			vAtts.push_back(atr_URL);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAuthenticationCmdParams::AuthenticationTypeString(){
		static const WString enums=WString(L"Unknown,AsClient,AsServer");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAuthenticationCmdParams::AuthenticationTypeString(EnumAuthenticationType value){
		return AuthenticationTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAuthenticationCmdParams::SetAuthenticationType( EnumAuthenticationType value){
	SetEnumAttribute(atr_AuthenticationType,value,AuthenticationTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAuthenticationCmdParams::EnumAuthenticationType JDFAutoAuthenticationCmdParams:: GetAuthenticationType() const {
	return (EnumAuthenticationType) GetEnumAttribute(atr_AuthenticationType,AuthenticationTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAuthenticationCmdParams::ValidAuthenticationType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_AuthenticationType,AuthenticationTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAuthenticationCmdParams::ReasonString(){
		static const WString enums=WString(L"Unknown,InitiateConnection,ClientCertificateExpired,ServerCertificateExpired,ClientHostnameMismatch,ServerHostnameMismatch,ClientCertificateRevoked,ServerCertificateRevoked,Other");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAuthenticationCmdParams::ReasonString(EnumReason value){
		return ReasonString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAuthenticationCmdParams::SetReason( EnumReason value){
	SetEnumAttribute(atr_Reason,value,ReasonString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAuthenticationCmdParams::EnumReason JDFAutoAuthenticationCmdParams:: GetReason() const {
	return (EnumReason) GetEnumAttribute(atr_Reason,ReasonString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAuthenticationCmdParams::ValidReason(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Reason,ReasonString(),false);
	};
/**
* Set attribute ReasonDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAuthenticationCmdParams::SetReasonDetails(const WString& value){
	SetAttribute(atr_ReasonDetails,value);
};
/**
* Get string attribute ReasonDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAuthenticationCmdParams::GetReasonDetails() const {
	return GetAttribute(atr_ReasonDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAuthenticationCmdParams::ValidReasonDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReasonDetails,AttributeType_string,false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAuthenticationCmdParams::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAuthenticationCmdParams::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAuthenticationCmdParams::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoAuthenticationCmdParams::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoAuthenticationCmdParams::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoAuthenticationCmdParams::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoAuthenticationCmdParams::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoAuthenticationCmdParams::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoAuthenticationCmdParams::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoAuthenticationCmdParams::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoAuthenticationCmdParams::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

JDFElement JDFAutoAuthenticationCmdParams::GetCertificate(int iSkip)const{
	JDFElement e=GetElement(elm_Certificate,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElement JDFAutoAuthenticationCmdParams::GetCreateCertificate(int iSkip){
	JDFElement e=GetCreateElement(elm_Certificate,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElement JDFAutoAuthenticationCmdParams::AppendCertificate(){
	JDFElement e=AppendElement(elm_Certificate);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoAuthenticationCmdParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Certificate);

		for(i=0;i<nElem;i++){
			if (!GetCertificate(i).IsValid(level)) {
				vElem.AppendUnique(elm_Certificate);
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
	WString JDFAutoAuthenticationCmdParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part,Certificate";
	};
}; // end namespace JDF
