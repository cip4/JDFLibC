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

 
#include "jdf/wrapper/AutoJDF/JDFAutoConvertingConfig.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoConvertingConfig : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoConvertingConfig& JDFAutoConvertingConfig::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoConvertingConfig: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoConvertingConfig::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoConvertingConfig::ValidNodeNames()const{
	return L"*:,ConvertingConfig";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoConvertingConfig::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",MarginBottom,MarginLeft,MarginRight,MarginTop,SheetHeight,SheetWidth");
};

/**
 typesafe validator
*/
	vWString JDFAutoConvertingConfig::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMarginBottom(level)) {
			vAtts.push_back(atr_MarginBottom);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarginLeft(level)) {
			vAtts.push_back(atr_MarginLeft);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarginRight(level)) {
			vAtts.push_back(atr_MarginRight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarginTop(level)) {
			vAtts.push_back(atr_MarginTop);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetHeight(level)) {
			vAtts.push_back(atr_SheetHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetWidth(level)) {
			vAtts.push_back(atr_SheetWidth);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute MarginBottom
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConvertingConfig::SetMarginBottom(double value){
	SetAttribute(atr_MarginBottom,WString::valueOf(value));
};
/**
* Get double attribute MarginBottom
* @return double the vaue of the attribute 
*/
	 double JDFAutoConvertingConfig::GetMarginBottom() const {
	return GetRealAttribute(atr_MarginBottom,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConvertingConfig::ValidMarginBottom(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarginBottom,AttributeType_double,false);
	};
/**
* Set attribute MarginLeft
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConvertingConfig::SetMarginLeft(double value){
	SetAttribute(atr_MarginLeft,WString::valueOf(value));
};
/**
* Get double attribute MarginLeft
* @return double the vaue of the attribute 
*/
	 double JDFAutoConvertingConfig::GetMarginLeft() const {
	return GetRealAttribute(atr_MarginLeft,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConvertingConfig::ValidMarginLeft(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarginLeft,AttributeType_double,false);
	};
/**
* Set attribute MarginRight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConvertingConfig::SetMarginRight(double value){
	SetAttribute(atr_MarginRight,WString::valueOf(value));
};
/**
* Get double attribute MarginRight
* @return double the vaue of the attribute 
*/
	 double JDFAutoConvertingConfig::GetMarginRight() const {
	return GetRealAttribute(atr_MarginRight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConvertingConfig::ValidMarginRight(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarginRight,AttributeType_double,false);
	};
/**
* Set attribute MarginTop
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConvertingConfig::SetMarginTop(double value){
	SetAttribute(atr_MarginTop,WString::valueOf(value));
};
/**
* Get double attribute MarginTop
* @return double the vaue of the attribute 
*/
	 double JDFAutoConvertingConfig::GetMarginTop() const {
	return GetRealAttribute(atr_MarginTop,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConvertingConfig::ValidMarginTop(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarginTop,AttributeType_double,false);
	};
/**
* Set attribute SheetHeight
*@param NumberRange value: the value to set the attribute to
*/
	 void JDFAutoConvertingConfig::SetSheetHeight(const NumberRange& value){
	SetAttribute(atr_SheetHeight,value.GetString());
};
/**
* Get range attribute SheetHeight
* @return NumberRange the vaue of the attribute 
*/
	 NumberRange JDFAutoConvertingConfig::GetSheetHeight() const {
	return GetAttribute(atr_SheetHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConvertingConfig::ValidSheetHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetHeight,AttributeType_Any,false);
	};
/**
* Set attribute SheetWidth
*@param NumberRange value: the value to set the attribute to
*/
	 void JDFAutoConvertingConfig::SetSheetWidth(const NumberRange& value){
	SetAttribute(atr_SheetWidth,value.GetString());
};
/**
* Get range attribute SheetWidth
* @return NumberRange the vaue of the attribute 
*/
	 NumberRange JDFAutoConvertingConfig::GetSheetWidth() const {
	return GetAttribute(atr_SheetWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConvertingConfig::ValidSheetWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetWidth,AttributeType_Any,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDevice JDFAutoConvertingConfig::GetDevice(int iSkip)const{
	JDFDevice e=GetElement(elm_Device,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoConvertingConfig::GetCreateDevice(int iSkip){
	JDFDevice e=GetCreateElement(elm_Device,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoConvertingConfig::AppendDevice(){
	JDFDevice e=AppendElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoConvertingConfig::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoConvertingConfig::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Device);

		for(i=0;i<nElem;i++){
			if (!GetDevice(i).IsValid(level)) {
				vElem.AppendUnique(elm_Device);
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
	WString JDFAutoConvertingConfig::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Device";
	};
}; // end namespace JDF
