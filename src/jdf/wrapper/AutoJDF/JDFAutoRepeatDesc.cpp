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

 
#include "jdf/wrapper/AutoJDF/JDFAutoRepeatDesc.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRepeatDesc : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoRepeatDesc& JDFAutoRepeatDesc::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoRepeatDesc: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoRepeatDesc::ValidNodeNames()const{
	return L"*:,RepeatDesc";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoRepeatDesc::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AllowedRotate,GutterX,GutterX2,GutterY,GutterY2,LayoutStyle,OrderQuantity,UseBleeds");
};

/**
 typesafe validator
*/
	vWString JDFAutoRepeatDesc::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAllowedRotate(level)) {
			vAtts.push_back(atr_AllowedRotate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGutterX(level)) {
			vAtts.push_back(atr_GutterX);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGutterX2(level)) {
			vAtts.push_back(atr_GutterX2);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGutterY(level)) {
			vAtts.push_back(atr_GutterY);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGutterY2(level)) {
			vAtts.push_back(atr_GutterY2);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayoutStyle(level)) {
			vAtts.push_back(atr_LayoutStyle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrderQuantity(level)) {
			vAtts.push_back(atr_OrderQuantity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUseBleeds(level)) {
			vAtts.push_back(atr_UseBleeds);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoRepeatDesc::AllowedRotateString(){
		static const WString enums=WString(L"Unknown,None,Grain,MinorGrain,CrossGrain");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoRepeatDesc::AllowedRotateString(EnumAllowedRotate value){
		return AllowedRotateString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRepeatDesc::SetAllowedRotate( EnumAllowedRotate value){
	SetEnumAttribute(atr_AllowedRotate,value,AllowedRotateString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRepeatDesc::EnumAllowedRotate JDFAutoRepeatDesc:: GetAllowedRotate() const {
	return (EnumAllowedRotate) GetEnumAttribute(atr_AllowedRotate,AllowedRotateString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::ValidAllowedRotate(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_AllowedRotate,AllowedRotateString(),false);
	};
/**
* Set attribute GutterX
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRepeatDesc::SetGutterX(double value){
	SetAttribute(atr_GutterX,WString::valueOf(value));
};
/**
* Get double attribute GutterX
* @return double the vaue of the attribute 
*/
	 double JDFAutoRepeatDesc::GetGutterX() const {
	return GetRealAttribute(atr_GutterX,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::ValidGutterX(EnumValidationLevel level) const {
		return ValidAttribute(atr_GutterX,AttributeType_double,false);
	};
/**
* Set attribute GutterX2
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRepeatDesc::SetGutterX2(double value){
	SetAttribute(atr_GutterX2,WString::valueOf(value));
};
/**
* Get double attribute GutterX2
* @return double the vaue of the attribute 
*/
	 double JDFAutoRepeatDesc::GetGutterX2() const {
	return GetRealAttribute(atr_GutterX2,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::ValidGutterX2(EnumValidationLevel level) const {
		return ValidAttribute(atr_GutterX2,AttributeType_double,false);
	};
/**
* Set attribute GutterY
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRepeatDesc::SetGutterY(double value){
	SetAttribute(atr_GutterY,WString::valueOf(value));
};
/**
* Get double attribute GutterY
* @return double the vaue of the attribute 
*/
	 double JDFAutoRepeatDesc::GetGutterY() const {
	return GetRealAttribute(atr_GutterY,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::ValidGutterY(EnumValidationLevel level) const {
		return ValidAttribute(atr_GutterY,AttributeType_double,false);
	};
/**
* Set attribute GutterY2
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRepeatDesc::SetGutterY2(double value){
	SetAttribute(atr_GutterY2,WString::valueOf(value));
};
/**
* Get double attribute GutterY2
* @return double the vaue of the attribute 
*/
	 double JDFAutoRepeatDesc::GetGutterY2() const {
	return GetRealAttribute(atr_GutterY2,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::ValidGutterY2(EnumValidationLevel level) const {
		return ValidAttribute(atr_GutterY2,AttributeType_double,false);
	};
/**
* Set attribute LayoutStyle
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoRepeatDesc::SetLayoutStyle(const vWString& value){
	SetAttribute(atr_LayoutStyle,value);
};
/**
* Get string attribute LayoutStyle
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoRepeatDesc::GetLayoutStyle() const {
	return GetAttribute(atr_LayoutStyle,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::ValidLayoutStyle(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayoutStyle,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute OrderQuantity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRepeatDesc::SetOrderQuantity(int value){
	SetAttribute(atr_OrderQuantity,WString::valueOf(value));
};
/**
* Get integer attribute OrderQuantity
* @return int the vaue of the attribute 
*/
	 int JDFAutoRepeatDesc::GetOrderQuantity() const {
	return GetIntAttribute(atr_OrderQuantity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::ValidOrderQuantity(EnumValidationLevel level) const {
		return ValidAttribute(atr_OrderQuantity,AttributeType_integer,false);
	};
/**
* Set attribute UseBleeds
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRepeatDesc::SetUseBleeds(bool value){
	SetAttribute(atr_UseBleeds,WString::valueOf(value));
};
/**
* Get bool attribute UseBleeds
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoRepeatDesc::GetUseBleeds() const {return GetBoolAttribute(atr_UseBleeds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRepeatDesc::ValidUseBleeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_UseBleeds,AttributeType_boolean,false);
	};
}; // end namespace JDF
