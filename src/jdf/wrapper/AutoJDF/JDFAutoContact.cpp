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

 
#include "jdf/wrapper/AutoJDF/JDFAutoContact.h"
#include "jdf/wrapper/JDFAddress.h"
#include "jdf/wrapper/JDFComChannel.h"
#include "jdf/wrapper/JDFCompany.h"
#include "jdf/wrapper/JDFPerson.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoContact : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoContact& JDFAutoContact::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoContact: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoContact::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoContact::ValidNodeNames()const{
	return L"*:,Contact";
};

bool JDFAutoContact::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoContact::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoContact::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",ContactTypes";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoContact::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ContactTypeDetails");
};

/**
 typesafe validator
*/
	vWString JDFAutoContact::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidContactTypes(level)) {
			vAtts.push_back(atr_ContactTypes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidContactTypeDetails(level)) {
			vAtts.push_back(atr_ContactTypeDetails);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ContactTypes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoContact::SetContactTypes(const vWString& value){
	SetAttribute(atr_ContactTypes,value);
};
/**
* Get string attribute ContactTypes
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoContact::GetContactTypes() const {
	return GetAttribute(atr_ContactTypes,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContact::ValidContactTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContactTypes,AttributeType_NMTOKENS,RequiredLevel(level));
	};
/**
* Set attribute ContactTypeDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContact::SetContactTypeDetails(const WString& value){
	SetAttribute(atr_ContactTypeDetails,value);
};
/**
* Get string attribute ContactTypeDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContact::GetContactTypeDetails() const {
	return GetAttribute(atr_ContactTypeDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContact::ValidContactTypeDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContactTypeDetails,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAddress JDFAutoContact::GetAddress()const{
	JDFAddress e=GetElement(elm_Address);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAddress JDFAutoContact::GetCreateAddress(){
	JDFAddress e=GetCreateElement(elm_Address);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAddress JDFAutoContact::AppendAddress(){
	JDFAddress e=AppendElementN(elm_Address,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContact::RefAddress(JDFAddress& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFComChannel JDFAutoContact::GetComChannel(int iSkip)const{
	JDFComChannel e=GetElement(elm_ComChannel,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComChannel JDFAutoContact::GetCreateComChannel(int iSkip){
	JDFComChannel e=GetCreateElement(elm_ComChannel,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComChannel JDFAutoContact::AppendComChannel(){
	JDFComChannel e=AppendElement(elm_ComChannel);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContact::RefComChannel(JDFComChannel& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoContact::GetCompany()const{
	JDFCompany e=GetElement(elm_Company);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoContact::GetCreateCompany(){
	JDFCompany e=GetCreateElement(elm_Company);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCompany JDFAutoContact::AppendCompany(){
	JDFCompany e=AppendElementN(elm_Company,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContact::RefCompany(JDFCompany& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPerson JDFAutoContact::GetPerson()const{
	JDFPerson e=GetElement(elm_Person);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPerson JDFAutoContact::GetCreatePerson(){
	JDFPerson e=GetCreateElement(elm_Person);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPerson JDFAutoContact::AppendPerson(){
	JDFPerson e=AppendElementN(elm_Person,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContact::RefPerson(JDFPerson& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoContact::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Address);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Address);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAddress().IsValid(level)) {
				vElem.AppendUnique(elm_Address);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ComChannel);

		for(i=0;i<nElem;i++){
			if (!GetComChannel(i).IsValid(level)) {
				vElem.AppendUnique(elm_ComChannel);
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
		nElem=NumChildElements(elm_Person);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Person);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPerson().IsValid(level)) {
				vElem.AppendUnique(elm_Person);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoContact::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Address,Company,Person";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoContact::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Address,ComChannel,Company,Person";
	};
}; // end namespace JDF
