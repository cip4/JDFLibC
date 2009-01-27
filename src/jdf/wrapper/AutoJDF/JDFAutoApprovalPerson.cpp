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

 
#include "jdf/wrapper/AutoJDF/JDFAutoApprovalPerson.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoApprovalPerson : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoApprovalPerson& JDFAutoApprovalPerson::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoApprovalPerson: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoApprovalPerson::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoApprovalPerson::ValidNodeNames()const{
	return L"*:,ApprovalPerson";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoApprovalPerson::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Obligated,ApprovalRole,ApprovalRoleDetails");
};

/**
 typesafe validator
*/
	vWString JDFAutoApprovalPerson::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidObligated(level)) {
			vAtts.push_back(atr_Obligated);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidApprovalRole(level)) {
			vAtts.push_back(atr_ApprovalRole);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidApprovalRoleDetails(level)) {
			vAtts.push_back(atr_ApprovalRoleDetails);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Obligated
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoApprovalPerson::SetObligated(bool value){
	SetAttribute(atr_Obligated,WString::valueOf(value));
};
/**
* Get bool attribute Obligated
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoApprovalPerson::GetObligated() const {return GetBoolAttribute(atr_Obligated,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoApprovalPerson::ValidObligated(EnumValidationLevel level) const {
		return ValidAttribute(atr_Obligated,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoApprovalPerson::ApprovalRoleString(){
		static const WString enums=WString(L"Unknown,Approvinator,Group,Informative,Obligated");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoApprovalPerson::ApprovalRoleString(EnumApprovalRole value){
		return ApprovalRoleString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoApprovalPerson::SetApprovalRole( EnumApprovalRole value){
	SetEnumAttribute(atr_ApprovalRole,value,ApprovalRoleString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoApprovalPerson::EnumApprovalRole JDFAutoApprovalPerson:: GetApprovalRole() const {
	return (EnumApprovalRole) GetEnumAttribute(atr_ApprovalRole,ApprovalRoleString(),WString::emptyStr,ApprovalRole_Obligated);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoApprovalPerson::ValidApprovalRole(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ApprovalRole,ApprovalRoleString(),false);
	};
/**
* Set attribute ApprovalRoleDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoApprovalPerson::SetApprovalRoleDetails(const WString& value){
	SetAttribute(atr_ApprovalRoleDetails,value);
};
/**
* Get string attribute ApprovalRoleDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoApprovalPerson::GetApprovalRoleDetails() const {
	return GetAttribute(atr_ApprovalRoleDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoApprovalPerson::ValidApprovalRoleDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_ApprovalRoleDetails,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFContact JDFAutoApprovalPerson::GetContact()const{
	JDFContact e=GetElement(elm_Contact);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoApprovalPerson::GetCreateContact(){
	JDFContact e=GetCreateElement(elm_Contact);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoApprovalPerson::AppendContact(){
	JDFContact e=AppendElementN(elm_Contact,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoApprovalPerson::RefContact(JDFContact& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoApprovalPerson::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Contact);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_Contact);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Contact);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetContact().IsValid(level)) {
				vElem.AppendUnique(elm_Contact);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoApprovalPerson::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Contact";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoApprovalPerson::RequiredElements()const{
		return JDFElement::RequiredElements()+L",Contact";
	};
}; // end namespace JDF
