/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoVarnishingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoVarnishingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoVarnishingParams& JDFAutoVarnishingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoVarnishingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoVarnishingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoVarnishingParams::ValidNodeNames()const{
	return L"*:,VarnishingParams";
};

bool JDFAutoVarnishingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoVarnishingParams::init(){
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
	WString JDFAutoVarnishingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ModuleIndex,ModuleType,VarnishArea,VarnishMethod");
};

/**
 typesafe validator
*/
	vWString JDFAutoVarnishingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidModuleIndex(level)) {
			vAtts.push_back(atr_ModuleIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleType(level)) {
			vAtts.push_back(atr_ModuleType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVarnishArea(level)) {
			vAtts.push_back(atr_VarnishArea);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVarnishMethod(level)) {
			vAtts.push_back(atr_VarnishMethod);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ModuleIndex
*@param int value: the value to set the attribute to
*/
	 void JDFAutoVarnishingParams::SetModuleIndex(int value){
	SetAttribute(atr_ModuleIndex,WString::valueOf(value));
};
/**
* Get integer attribute ModuleIndex
* @return int the vaue of the attribute 
*/
	 int JDFAutoVarnishingParams::GetModuleIndex() const {
	return GetIntAttribute(atr_ModuleIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoVarnishingParams::ValidModuleIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleIndex,AttributeType_integer,false);
	};
/**
* Set attribute ModuleType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoVarnishingParams::SetModuleType(const WString& value){
	SetAttribute(atr_ModuleType,value);
};
/**
* Get string attribute ModuleType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoVarnishingParams::GetModuleType() const {
	return GetAttribute(atr_ModuleType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoVarnishingParams::ValidModuleType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleType,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoVarnishingParams::VarnishAreaString(){
		static const WString enums=WString(L"Unknown,Full,Spot");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoVarnishingParams::VarnishAreaString(EnumVarnishArea value){
		return VarnishAreaString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoVarnishingParams::SetVarnishArea( EnumVarnishArea value){
	SetEnumAttribute(atr_VarnishArea,value,VarnishAreaString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoVarnishingParams::EnumVarnishArea JDFAutoVarnishingParams:: GetVarnishArea() const {
	return (EnumVarnishArea) GetEnumAttribute(atr_VarnishArea,VarnishAreaString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoVarnishingParams::ValidVarnishArea(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_VarnishArea,VarnishAreaString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoVarnishingParams::VarnishMethodString(){
		static const WString enums=WString(L"Unknown,Blanket,Plate,Method");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoVarnishingParams::VarnishMethodString(EnumVarnishMethod value){
		return VarnishMethodString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoVarnishingParams::SetVarnishMethod( EnumVarnishMethod value){
	SetEnumAttribute(atr_VarnishMethod,value,VarnishMethodString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoVarnishingParams::EnumVarnishMethod JDFAutoVarnishingParams:: GetVarnishMethod() const {
	return (EnumVarnishMethod) GetEnumAttribute(atr_VarnishMethod,VarnishMethodString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoVarnishingParams::ValidVarnishMethod(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_VarnishMethod,VarnishMethodString(),false);
	};
}; // end namespace JDF
