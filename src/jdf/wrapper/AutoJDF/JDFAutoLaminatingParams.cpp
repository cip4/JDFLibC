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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLaminatingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLaminatingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLaminatingParams& JDFAutoLaminatingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLaminatingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLaminatingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLaminatingParams::ValidNodeNames()const{
	return L"*:,LaminatingParams";
};

bool JDFAutoLaminatingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoLaminatingParams::init(){
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
	WString JDFAutoLaminatingParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",LaminatingBox";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoLaminatingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",AdhesiveType,GapList,HardenerType,LaminatingMethod,NipWidth,Temperature");
};

/**
 typesafe validator
*/
	vWString JDFAutoLaminatingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidLaminatingBox(level)) {
			vAtts.push_back(atr_LaminatingBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdhesiveType(level)) {
			vAtts.push_back(atr_AdhesiveType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGapList(level)) {
			vAtts.push_back(atr_GapList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHardenerType(level)) {
			vAtts.push_back(atr_HardenerType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLaminatingMethod(level)) {
			vAtts.push_back(atr_LaminatingMethod);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNipWidth(level)) {
			vAtts.push_back(atr_NipWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTemperature(level)) {
			vAtts.push_back(atr_Temperature);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute LaminatingBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoLaminatingParams::SetLaminatingBox(const JDFRectangle& value){
	SetAttribute(atr_LaminatingBox,value);
};
/**
* Get string attribute LaminatingBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoLaminatingParams::GetLaminatingBox() const {
	return GetAttribute(atr_LaminatingBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLaminatingParams::ValidLaminatingBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_LaminatingBox,AttributeType_rectangle,RequiredLevel(level));
	};
/**
* Set attribute AdhesiveType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLaminatingParams::SetAdhesiveType(const WString& value){
	SetAttribute(atr_AdhesiveType,value);
};
/**
* Get string attribute AdhesiveType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoLaminatingParams::GetAdhesiveType() const {
	return GetAttribute(atr_AdhesiveType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLaminatingParams::ValidAdhesiveType(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdhesiveType,AttributeType_string,false);
	};
/**
* Set attribute GapList
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoLaminatingParams::SetGapList(const JDFNumberList& value){
	SetAttribute(atr_GapList,value.GetString());
};
/**
* Get string attribute GapList
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoLaminatingParams::GetGapList() const {
	return GetAttribute(atr_GapList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLaminatingParams::ValidGapList(EnumValidationLevel level) const {
		return ValidAttribute(atr_GapList,AttributeType_NumberList,false);
	};
/**
* Set attribute HardenerType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLaminatingParams::SetHardenerType(const WString& value){
	SetAttribute(atr_HardenerType,value);
};
/**
* Get string attribute HardenerType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoLaminatingParams::GetHardenerType() const {
	return GetAttribute(atr_HardenerType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLaminatingParams::ValidHardenerType(EnumValidationLevel level) const {
		return ValidAttribute(atr_HardenerType,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLaminatingParams::LaminatingMethodString(){
		static const WString enums=WString(L"Unknown,CompoundFoil,DispersionGlue,Fusing");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLaminatingParams::LaminatingMethodString(EnumLaminatingMethod value){
		return LaminatingMethodString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLaminatingParams::SetLaminatingMethod( EnumLaminatingMethod value){
	SetEnumAttribute(atr_LaminatingMethod,value,LaminatingMethodString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLaminatingParams::EnumLaminatingMethod JDFAutoLaminatingParams:: GetLaminatingMethod() const {
	return (EnumLaminatingMethod) GetEnumAttribute(atr_LaminatingMethod,LaminatingMethodString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLaminatingParams::ValidLaminatingMethod(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_LaminatingMethod,LaminatingMethodString(),false,WString::emptyStr,true);
	};
/**
* Set attribute NipWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoLaminatingParams::SetNipWidth(double value){
	SetAttribute(atr_NipWidth,WString::valueOf(value));
};
/**
* Get double attribute NipWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoLaminatingParams::GetNipWidth() const {
	return GetRealAttribute(atr_NipWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLaminatingParams::ValidNipWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_NipWidth,AttributeType_double,false);
	};
/**
* Set attribute Temperature
*@param double value: the value to set the attribute to
*/
	 void JDFAutoLaminatingParams::SetTemperature(double value){
	SetAttribute(atr_Temperature,WString::valueOf(value));
};
/**
* Get double attribute Temperature
* @return double the vaue of the attribute 
*/
	 double JDFAutoLaminatingParams::GetTemperature() const {
	return GetRealAttribute(atr_Temperature,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLaminatingParams::ValidTemperature(EnumValidationLevel level) const {
		return ValidAttribute(atr_Temperature,AttributeType_double,false);
	};
}; // end namespace JDF
