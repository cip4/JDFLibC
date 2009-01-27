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

 
#include "jdf/wrapper/AutoJDF/JDFAutoEmployee.h"
#include "jdf/wrapper/JDFCostCenter.h"
#include "jdf/wrapper/JDFPerson.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoEmployee : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoEmployee& JDFAutoEmployee::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoEmployee: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoEmployee::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoEmployee::ValidNodeNames()const{
	return L"*:,Employee";
};

bool JDFAutoEmployee::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Implementation;
};

bool JDFAutoEmployee::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Implementation);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoEmployee::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",PersonalID,Roles,Shift");
};

/**
 typesafe validator
*/
	vWString JDFAutoEmployee::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPersonalID(level)) {
			vAtts.push_back(atr_PersonalID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRoles(level)) {
			vAtts.push_back(atr_Roles);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShift(level)) {
			vAtts.push_back(atr_Shift);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PersonalID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoEmployee::SetPersonalID(const WString& value){
	SetAttribute(atr_PersonalID,value);
};
/**
* Get string attribute PersonalID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoEmployee::GetPersonalID() const {
	return GetAttribute(atr_PersonalID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmployee::ValidPersonalID(EnumValidationLevel level) const {
		return ValidAttribute(atr_PersonalID,AttributeType_shortString,false);
	};
/**
* Set attribute Roles
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoEmployee::SetRoles(const vWString& value){
	SetAttribute(atr_Roles,value);
};
/**
* Get string attribute Roles
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoEmployee::GetRoles() const {
	return GetAttribute(atr_Roles,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmployee::ValidRoles(EnumValidationLevel level) const {
		return ValidAttribute(atr_Roles,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Shift
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoEmployee::SetShift(const WString& value){
	SetAttribute(atr_Shift,value);
};
/**
* Get string attribute Shift
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoEmployee::GetShift() const {
	return GetAttribute(atr_Shift,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmployee::ValidShift(EnumValidationLevel level) const {
		return ValidAttribute(atr_Shift,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCostCenter JDFAutoEmployee::GetCostCenter()const{
	JDFCostCenter e=GetElement(elm_CostCenter);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoEmployee::GetCreateCostCenter(){
	JDFCostCenter e=GetCreateElement(elm_CostCenter);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCostCenter JDFAutoEmployee::AppendCostCenter(){
	JDFCostCenter e=AppendElementN(elm_CostCenter,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPerson JDFAutoEmployee::GetPerson()const{
	JDFPerson e=GetElement(elm_Person);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPerson JDFAutoEmployee::GetCreatePerson(){
	JDFPerson e=GetCreateElement(elm_Person);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPerson JDFAutoEmployee::AppendPerson(){
	JDFPerson e=AppendElementN(elm_Person,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoEmployee::RefPerson(JDFPerson& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoEmployee::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CostCenter);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CostCenter);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCostCenter().IsValid(level)) {
				vElem.AppendUnique(elm_CostCenter);
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
	WString JDFAutoEmployee::UniqueElements()const{
		return JDFResource::UniqueElements()+L",CostCenter,Person";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoEmployee::OptionalElements()const{
		return JDFResource::OptionalElements()+L",CostCenter,Person";
	};
}; // end namespace JDF
