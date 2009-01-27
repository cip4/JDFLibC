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

 
#include "jdf/wrapper/AutoJDF/JDFAutoJobField.h"
#include "jdf/wrapper/JDFDeviceMark.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoJobField : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoJobField& JDFAutoJobField::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoJobField: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoJobField::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoJobField::ValidNodeNames()const{
	return L"*:,JobField";
};

bool JDFAutoJobField::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoJobField::init(){
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
	WString JDFAutoJobField::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",ShowList";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoJobField::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",JobFormat,JobTemplate,OperatorText,UserText");
};

/**
 typesafe validator
*/
	vWString JDFAutoJobField::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidShowList(level)) {
			vAtts.push_back(atr_ShowList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobFormat(level)) {
			vAtts.push_back(atr_JobFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobTemplate(level)) {
			vAtts.push_back(atr_JobTemplate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOperatorText(level)) {
			vAtts.push_back(atr_OperatorText);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUserText(level)) {
			vAtts.push_back(atr_UserText);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ShowList
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoJobField::SetShowList(const vWString& value){
	SetAttribute(atr_ShowList,value);
};
/**
* Get string attribute ShowList
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoJobField::GetShowList() const {
	return GetAttribute(atr_ShowList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobField::ValidShowList(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShowList,AttributeType_NMTOKENS,RequiredLevel(level));
	};
/**
* Set attribute JobFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJobField::SetJobFormat(const WString& value){
	SetAttribute(atr_JobFormat,value);
};
/**
* Get string attribute JobFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJobField::GetJobFormat() const {
	return GetAttribute(atr_JobFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobField::ValidJobFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobFormat,AttributeType_string,false);
	};
/**
* Set attribute JobTemplate
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJobField::SetJobTemplate(const WString& value){
	SetAttribute(atr_JobTemplate,value);
};
/**
* Get string attribute JobTemplate
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJobField::GetJobTemplate() const {
	return GetAttribute(atr_JobTemplate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobField::ValidJobTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobTemplate,AttributeType_string,false);
	};
/**
* Set attribute OperatorText
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJobField::SetOperatorText(const WString& value){
	SetAttribute(atr_OperatorText,value);
};
/**
* Get string attribute OperatorText
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJobField::GetOperatorText() const {
	return GetAttribute(atr_OperatorText,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobField::ValidOperatorText(EnumValidationLevel level) const {
		return ValidAttribute(atr_OperatorText,AttributeType_string,false);
	};
/**
* Set attribute UserText
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoJobField::SetUserText(const WString& value){
	SetAttribute(atr_UserText,value);
};
/**
* Get string attribute UserText
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoJobField::GetUserText() const {
	return GetAttribute(atr_UserText,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoJobField::ValidUserText(EnumValidationLevel level) const {
		return ValidAttribute(atr_UserText,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDeviceMark JDFAutoJobField::GetDeviceMark()const{
	JDFDeviceMark e=GetElement(elm_DeviceMark);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoJobField::GetCreateDeviceMark(){
	JDFDeviceMark e=GetCreateElement(elm_DeviceMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoJobField::AppendDeviceMark(){
	JDFDeviceMark e=AppendElementN(elm_DeviceMark,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoJobField::RefDeviceMark(JDFDeviceMark& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoJobField::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_DeviceMark);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DeviceMark);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDeviceMark().IsValid(level)) {
				vElem.AppendUnique(elm_DeviceMark);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoJobField::UniqueElements()const{
		return JDFResource::UniqueElements()+L",DeviceMark";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoJobField::OptionalElements()const{
		return JDFResource::OptionalElements()+L",DeviceMark";
	};
}; // end namespace JDF
