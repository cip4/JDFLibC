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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPerson.h"
#include "jdf/wrapper/JDFAddress.h"
#include "jdf/wrapper/JDFComChannel.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPerson : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPerson& JDFAutoPerson::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPerson: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPerson::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPerson::ValidNodeNames()const{
	return L"*:,Person";
};

bool JDFAutoPerson::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPerson::init(){
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
	WString JDFAutoPerson::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",AdditionalNames,FamilyName,FirstName,JobTitle,NamePrefix,NameSuffix");
};

/**
 typesafe validator
*/
	vWString JDFAutoPerson::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAdditionalNames(level)) {
			vAtts.push_back(atr_AdditionalNames);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFamilyName(level)) {
			vAtts.push_back(atr_FamilyName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFirstName(level)) {
			vAtts.push_back(atr_FirstName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobTitle(level)) {
			vAtts.push_back(atr_JobTitle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNamePrefix(level)) {
			vAtts.push_back(atr_NamePrefix);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNameSuffix(level)) {
			vAtts.push_back(atr_NameSuffix);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AdditionalNames
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerson::SetAdditionalNames(const WString& value){
	SetAttribute(atr_AdditionalNames,value);
};
/**
* Get string attribute AdditionalNames
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerson::GetAdditionalNames() const {
	return GetAttribute(atr_AdditionalNames,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerson::ValidAdditionalNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdditionalNames,AttributeType_string,false);
	};
/**
* Set attribute FamilyName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerson::SetFamilyName(const WString& value){
	SetAttribute(atr_FamilyName,value);
};
/**
* Get string attribute FamilyName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerson::GetFamilyName() const {
	return GetAttribute(atr_FamilyName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerson::ValidFamilyName(EnumValidationLevel level) const {
		return ValidAttribute(atr_FamilyName,AttributeType_string,false);
	};
/**
* Set attribute FirstName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerson::SetFirstName(const WString& value){
	SetAttribute(atr_FirstName,value);
};
/**
* Get string attribute FirstName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerson::GetFirstName() const {
	return GetAttribute(atr_FirstName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerson::ValidFirstName(EnumValidationLevel level) const {
		return ValidAttribute(atr_FirstName,AttributeType_string,false);
	};
/**
* Set attribute JobTitle
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerson::SetJobTitle(const WString& value){
	SetAttribute(atr_JobTitle,value);
};
/**
* Get string attribute JobTitle
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerson::GetJobTitle() const {
	return GetAttribute(atr_JobTitle,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerson::ValidJobTitle(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobTitle,AttributeType_string,false);
	};
/**
* Set attribute NamePrefix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerson::SetNamePrefix(const WString& value){
	SetAttribute(atr_NamePrefix,value);
};
/**
* Get string attribute NamePrefix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerson::GetNamePrefix() const {
	return GetAttribute(atr_NamePrefix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerson::ValidNamePrefix(EnumValidationLevel level) const {
		return ValidAttribute(atr_NamePrefix,AttributeType_string,false);
	};
/**
* Set attribute NameSuffix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerson::SetNameSuffix(const WString& value){
	SetAttribute(atr_NameSuffix,value);
};
/**
* Get string attribute NameSuffix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerson::GetNameSuffix() const {
	return GetAttribute(atr_NameSuffix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerson::ValidNameSuffix(EnumValidationLevel level) const {
		return ValidAttribute(atr_NameSuffix,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAddress JDFAutoPerson::GetAddress()const{
	JDFAddress e=GetElement(elm_Address);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAddress JDFAutoPerson::GetCreateAddress(){
	JDFAddress e=GetCreateElement(elm_Address);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAddress JDFAutoPerson::AppendAddress(){
	JDFAddress e=AppendElementN(elm_Address,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPerson::RefAddress(JDFAddress& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFComChannel JDFAutoPerson::GetComChannel(int iSkip)const{
	JDFComChannel e=GetElement(elm_ComChannel,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComChannel JDFAutoPerson::GetCreateComChannel(int iSkip){
	JDFComChannel e=GetCreateElement(elm_ComChannel,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComChannel JDFAutoPerson::AppendComChannel(){
	JDFComChannel e=AppendElement(elm_ComChannel);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPerson::RefComChannel(JDFComChannel& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPerson::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPerson::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Address";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPerson::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Address,ComChannel";
	};
}; // end namespace JDF
