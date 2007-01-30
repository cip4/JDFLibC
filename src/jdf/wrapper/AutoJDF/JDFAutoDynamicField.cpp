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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDynamicField.h"
#include "jdf/wrapper/JDFDeviceMark.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDynamicField : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDynamicField& JDFAutoDynamicField::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDynamicField: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDynamicField::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDynamicField::ValidNodeNames()const{
	return L"*:,DynamicField";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoDynamicField::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Format,Template";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDynamicField::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",InputField,Ord,OrdExpression,ReplaceField");
};

/**
 typesafe validator
*/
	vWString JDFAutoDynamicField::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFormat(level)) {
			vAtts.push_back(atr_Format);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInputField(level)) {
			vAtts.push_back(atr_InputField);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrd(level)) {
			vAtts.push_back(atr_Ord);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrdExpression(level)) {
			vAtts.push_back(atr_OrdExpression);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReplaceField(level)) {
			vAtts.push_back(atr_ReplaceField);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTemplate(level)) {
			vAtts.push_back(atr_Template);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Format
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDynamicField::SetFormat(const WString& value){
	SetAttribute(atr_Format,value);
};
/**
* Get string attribute Format
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDynamicField::GetFormat() const {
	return GetAttribute(atr_Format,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDynamicField::ValidFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_Format,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute InputField
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDynamicField::SetInputField(const WString& value){
	SetAttribute(atr_InputField,value);
};
/**
* Get string attribute InputField
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDynamicField::GetInputField() const {
	return GetAttribute(atr_InputField,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDynamicField::ValidInputField(EnumValidationLevel level) const {
		return ValidAttribute(atr_InputField,AttributeType_string,false);
	};
/**
* Set attribute Ord
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDynamicField::SetOrd(int value){
	SetAttribute(atr_Ord,WString::valueOf(value));
};
/**
* Get integer attribute Ord
* @return int the vaue of the attribute 
*/
	 int JDFAutoDynamicField::GetOrd() const {
	return GetIntAttribute(atr_Ord,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDynamicField::ValidOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_Ord,AttributeType_integer,false);
	};
/**
* Set attribute OrdExpression
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDynamicField::SetOrdExpression(const WString& value){
	SetAttribute(atr_OrdExpression,value);
};
/**
* Get string attribute OrdExpression
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDynamicField::GetOrdExpression() const {
	return GetAttribute(atr_OrdExpression,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDynamicField::ValidOrdExpression(EnumValidationLevel level) const {
		return ValidAttribute(atr_OrdExpression,AttributeType_string,false);
	};
/**
* Set attribute ReplaceField
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDynamicField::SetReplaceField(const WString& value){
	SetAttribute(atr_ReplaceField,value);
};
/**
* Get string attribute ReplaceField
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDynamicField::GetReplaceField() const {
	return GetAttribute(atr_ReplaceField,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDynamicField::ValidReplaceField(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReplaceField,AttributeType_string,false);
	};
/**
* Set attribute Template
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDynamicField::SetTemplate(const WString& value){
	SetAttribute(atr_Template,value);
};
/**
* Get string attribute Template
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDynamicField::GetTemplate() const {
	return GetAttribute(atr_Template,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDynamicField::ValidTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_Template,AttributeType_string,RequiredLevel(level));
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDeviceMark JDFAutoDynamicField::GetDeviceMark()const{
	JDFDeviceMark e=GetElement(elm_DeviceMark);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoDynamicField::GetCreateDeviceMark(){
	JDFDeviceMark e=GetCreateElement(elm_DeviceMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoDynamicField::AppendDeviceMark(){
	JDFDeviceMark e=AppendElementN(elm_DeviceMark,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDynamicField::RefDeviceMark(JDFDeviceMark& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDynamicField::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
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
	WString JDFAutoDynamicField::UniqueElements()const{
		return JDFElement::UniqueElements()+L",DeviceMark";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDynamicField::OptionalElements()const{
		return JDFElement::OptionalElements()+L",DeviceMark";
	};
}; // end namespace JDF
