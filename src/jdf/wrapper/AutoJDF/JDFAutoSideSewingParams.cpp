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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSideSewingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSideSewingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSideSewingParams& JDFAutoSideSewingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSideSewingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSideSewingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSideSewingParams::ValidNodeNames()const{
	return L"*:,SideSewingParams";
};

bool JDFAutoSideSewingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoSideSewingParams::init(){
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
	WString JDFAutoSideSewingParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",NumberOfNeedles,Offset";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoSideSewingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",NeedlePositions,SewingPattern,ThreadMaterial,ThreadThickness,ThreadBrand");
};

/**
 typesafe validator
*/
	vWString JDFAutoSideSewingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidNumberOfNeedles(level)) {
			vAtts.push_back(atr_NumberOfNeedles);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOffset(level)) {
			vAtts.push_back(atr_Offset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNeedlePositions(level)) {
			vAtts.push_back(atr_NeedlePositions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSewingPattern(level)) {
			vAtts.push_back(atr_SewingPattern);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadMaterial(level)) {
			vAtts.push_back(atr_ThreadMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadThickness(level)) {
			vAtts.push_back(atr_ThreadThickness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadBrand(level)) {
			vAtts.push_back(atr_ThreadBrand);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute NumberOfNeedles
*@param int value: the value to set the attribute to
*/
	 void JDFAutoSideSewingParams::SetNumberOfNeedles(int value){
	SetAttribute(atr_NumberOfNeedles,WString::valueOf(value));
};
/**
* Get integer attribute NumberOfNeedles
* @return int the vaue of the attribute 
*/
	 int JDFAutoSideSewingParams::GetNumberOfNeedles() const {
	return GetIntAttribute(atr_NumberOfNeedles,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSideSewingParams::ValidNumberOfNeedles(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberOfNeedles,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute Offset
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSideSewingParams::SetOffset(double value){
	SetAttribute(atr_Offset,WString::valueOf(value));
};
/**
* Get double attribute Offset
* @return double the vaue of the attribute 
*/
	 double JDFAutoSideSewingParams::GetOffset() const {
	return GetRealAttribute(atr_Offset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSideSewingParams::ValidOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_Offset,AttributeType_double,RequiredLevel(level));
	};
/**
* Set attribute NeedlePositions
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoSideSewingParams::SetNeedlePositions(const JDFNumberList& value){
	SetAttribute(atr_NeedlePositions,value.GetString());
};
/**
* Get string attribute NeedlePositions
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoSideSewingParams::GetNeedlePositions() const {
	return GetAttribute(atr_NeedlePositions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSideSewingParams::ValidNeedlePositions(EnumValidationLevel level) const {
		return ValidAttribute(atr_NeedlePositions,AttributeType_NumberList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSideSewingParams::SewingPatternString(){
		static const WString enums=WString(L"Unknown,Normal,Staggered,CombinedStaggered");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSideSewingParams::SewingPatternString(EnumSewingPattern value){
		return SewingPatternString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSideSewingParams::SetSewingPattern( EnumSewingPattern value){
	SetEnumAttribute(atr_SewingPattern,value,SewingPatternString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSideSewingParams::EnumSewingPattern JDFAutoSideSewingParams:: GetSewingPattern() const {
	return (EnumSewingPattern) GetEnumAttribute(atr_SewingPattern,SewingPatternString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSideSewingParams::ValidSewingPattern(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SewingPattern,SewingPatternString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSideSewingParams::ThreadMaterialString(){
		static const WString enums=WString(L"Unknown,Cotton,Nylon,Polyester");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSideSewingParams::ThreadMaterialString(EnumThreadMaterial value){
		return ThreadMaterialString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSideSewingParams::SetThreadMaterial( EnumThreadMaterial value){
	SetEnumAttribute(atr_ThreadMaterial,value,ThreadMaterialString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSideSewingParams::EnumThreadMaterial JDFAutoSideSewingParams:: GetThreadMaterial() const {
	return (EnumThreadMaterial) GetEnumAttribute(atr_ThreadMaterial,ThreadMaterialString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSideSewingParams::ValidThreadMaterial(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ThreadMaterial,ThreadMaterialString(),false);
	};
/**
* Set attribute ThreadThickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSideSewingParams::SetThreadThickness(double value){
	SetAttribute(atr_ThreadThickness,WString::valueOf(value));
};
/**
* Get double attribute ThreadThickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoSideSewingParams::GetThreadThickness() const {
	return GetRealAttribute(atr_ThreadThickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSideSewingParams::ValidThreadThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_ThreadThickness,AttributeType_double,false);
	};
/**
* Set attribute ThreadBrand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSideSewingParams::SetThreadBrand(const WString& value){
	SetAttribute(atr_ThreadBrand,value);
};
/**
* Get string attribute ThreadBrand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSideSewingParams::GetThreadBrand() const {
	return GetAttribute(atr_ThreadBrand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSideSewingParams::ValidThreadBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_ThreadBrand,AttributeType_string,false);
	};
}; // end namespace JDF
