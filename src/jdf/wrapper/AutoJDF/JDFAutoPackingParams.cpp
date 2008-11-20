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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPackingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPackingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPackingParams& JDFAutoPackingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPackingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPackingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPackingParams::ValidNodeNames()const{
	return L"*:,PackingParams";
};

bool JDFAutoPackingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPackingParams::init(){
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
	WString JDFAutoPackingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",PalletWrapping,WrappingMaterial,BoxedQuantity,BoxShape,CartonQuantity,CartonShape,CartonMaxWeight,CartonStrength,PalletQuantity,PalletSize,PalletMaxHeight,PalletMaxWeight,PalletType,WrappedQuantity");
};

/**
 typesafe validator
*/
	vWString JDFAutoPackingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPalletWrapping(level)) {
			vAtts.push_back(atr_PalletWrapping);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWrappingMaterial(level)) {
			vAtts.push_back(atr_WrappingMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBoxedQuantity(level)) {
			vAtts.push_back(atr_BoxedQuantity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBoxShape(level)) {
			vAtts.push_back(atr_BoxShape);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCartonQuantity(level)) {
			vAtts.push_back(atr_CartonQuantity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCartonShape(level)) {
			vAtts.push_back(atr_CartonShape);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCartonMaxWeight(level)) {
			vAtts.push_back(atr_CartonMaxWeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCartonStrength(level)) {
			vAtts.push_back(atr_CartonStrength);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPalletQuantity(level)) {
			vAtts.push_back(atr_PalletQuantity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPalletSize(level)) {
			vAtts.push_back(atr_PalletSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPalletMaxHeight(level)) {
			vAtts.push_back(atr_PalletMaxHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPalletMaxWeight(level)) {
			vAtts.push_back(atr_PalletMaxWeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPalletType(level)) {
			vAtts.push_back(atr_PalletType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWrappedQuantity(level)) {
			vAtts.push_back(atr_WrappedQuantity);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPackingParams::PalletWrappingString(){
		static const WString enums=WString(L"Unknown,StretchWrap,Banding,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPackingParams::PalletWrappingString(EnumPalletWrapping value){
		return PalletWrappingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPackingParams::SetPalletWrapping( EnumPalletWrapping value){
	SetEnumAttribute(atr_PalletWrapping,value,PalletWrappingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPackingParams::EnumPalletWrapping JDFAutoPackingParams:: GetPalletWrapping() const {
	return (EnumPalletWrapping) GetEnumAttribute(atr_PalletWrapping,PalletWrappingString(),WString::emptyStr,PalletWrapping_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidPalletWrapping(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PalletWrapping,PalletWrappingString(),false);
	};
/**
* Set attribute WrappingMaterial
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetWrappingMaterial(const WString& value){
	SetAttribute(atr_WrappingMaterial,value);
};
/**
* Get string attribute WrappingMaterial
* @return WString the vaue of the attribute ; defaults to None
*/
	 WString JDFAutoPackingParams::GetWrappingMaterial() const {
	return GetAttribute(atr_WrappingMaterial,WString::emptyStr,L"None");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidWrappingMaterial(EnumValidationLevel level) const {
		return ValidAttribute(atr_WrappingMaterial,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute BoxedQuantity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetBoxedQuantity(int value){
	SetAttribute(atr_BoxedQuantity,WString::valueOf(value));
};
/**
* Get integer attribute BoxedQuantity
* @return int the vaue of the attribute 
*/
	 int JDFAutoPackingParams::GetBoxedQuantity() const {
	return GetIntAttribute(atr_BoxedQuantity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidBoxedQuantity(EnumValidationLevel level) const {
		return ValidAttribute(atr_BoxedQuantity,AttributeType_integer,false);
	};
/**
* Set attribute BoxShape
*@param JDFShape value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetBoxShape(const JDFShape& value){
	SetAttribute(atr_BoxShape,value);
};
/**
* Get string attribute BoxShape
* @return JDFShape the vaue of the attribute 
*/
	 JDFShape JDFAutoPackingParams::GetBoxShape() const {
	return GetAttribute(atr_BoxShape,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidBoxShape(EnumValidationLevel level) const {
		return ValidAttribute(atr_BoxShape,AttributeType_shape,false);
	};
/**
* Set attribute CartonQuantity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetCartonQuantity(int value){
	SetAttribute(atr_CartonQuantity,WString::valueOf(value));
};
/**
* Get integer attribute CartonQuantity
* @return int the vaue of the attribute 
*/
	 int JDFAutoPackingParams::GetCartonQuantity() const {
	return GetIntAttribute(atr_CartonQuantity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidCartonQuantity(EnumValidationLevel level) const {
		return ValidAttribute(atr_CartonQuantity,AttributeType_integer,false);
	};
/**
* Set attribute CartonShape
*@param JDFShape value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetCartonShape(const JDFShape& value){
	SetAttribute(atr_CartonShape,value);
};
/**
* Get string attribute CartonShape
* @return JDFShape the vaue of the attribute 
*/
	 JDFShape JDFAutoPackingParams::GetCartonShape() const {
	return GetAttribute(atr_CartonShape,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidCartonShape(EnumValidationLevel level) const {
		return ValidAttribute(atr_CartonShape,AttributeType_shape,false);
	};
/**
* Set attribute CartonMaxWeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetCartonMaxWeight(double value){
	SetAttribute(atr_CartonMaxWeight,WString::valueOf(value));
};
/**
* Get double attribute CartonMaxWeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoPackingParams::GetCartonMaxWeight() const {
	return GetRealAttribute(atr_CartonMaxWeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidCartonMaxWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_CartonMaxWeight,AttributeType_double,false);
	};
/**
* Set attribute CartonStrength
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetCartonStrength(double value){
	SetAttribute(atr_CartonStrength,WString::valueOf(value));
};
/**
* Get double attribute CartonStrength
* @return double the vaue of the attribute 
*/
	 double JDFAutoPackingParams::GetCartonStrength() const {
	return GetRealAttribute(atr_CartonStrength,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidCartonStrength(EnumValidationLevel level) const {
		return ValidAttribute(atr_CartonStrength,AttributeType_double,false);
	};
/**
* Set attribute PalletQuantity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetPalletQuantity(int value){
	SetAttribute(atr_PalletQuantity,WString::valueOf(value));
};
/**
* Get integer attribute PalletQuantity
* @return int the vaue of the attribute 
*/
	 int JDFAutoPackingParams::GetPalletQuantity() const {
	return GetIntAttribute(atr_PalletQuantity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidPalletQuantity(EnumValidationLevel level) const {
		return ValidAttribute(atr_PalletQuantity,AttributeType_integer,false);
	};
/**
* Set attribute PalletSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetPalletSize(const JDFXYPair& value){
	SetAttribute(atr_PalletSize,value);
};
/**
* Get string attribute PalletSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPackingParams::GetPalletSize() const {
	return GetAttribute(atr_PalletSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidPalletSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_PalletSize,AttributeType_XYPair,false);
	};
/**
* Set attribute PalletMaxHeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetPalletMaxHeight(double value){
	SetAttribute(atr_PalletMaxHeight,WString::valueOf(value));
};
/**
* Get double attribute PalletMaxHeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoPackingParams::GetPalletMaxHeight() const {
	return GetRealAttribute(atr_PalletMaxHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidPalletMaxHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_PalletMaxHeight,AttributeType_double,false);
	};
/**
* Set attribute PalletMaxWeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetPalletMaxWeight(double value){
	SetAttribute(atr_PalletMaxWeight,WString::valueOf(value));
};
/**
* Get double attribute PalletMaxWeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoPackingParams::GetPalletMaxWeight() const {
	return GetRealAttribute(atr_PalletMaxWeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidPalletMaxWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_PalletMaxWeight,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPackingParams::PalletTypeString(){
		static const WString enums=WString(L"Unknown,2Way,4Way,Euro");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPackingParams::PalletTypeString(EnumPalletType value){
		return PalletTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPackingParams::SetPalletType( EnumPalletType value){
	SetEnumAttribute(atr_PalletType,value,PalletTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPackingParams::EnumPalletType JDFAutoPackingParams:: GetPalletType() const {
	return (EnumPalletType) GetEnumAttribute(atr_PalletType,PalletTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidPalletType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PalletType,PalletTypeString(),false);
	};
/**
* Set attribute WrappedQuantity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPackingParams::SetWrappedQuantity(int value){
	SetAttribute(atr_WrappedQuantity,WString::valueOf(value));
};
/**
* Get integer attribute WrappedQuantity
* @return int the vaue of the attribute 
*/
	 int JDFAutoPackingParams::GetWrappedQuantity() const {
	return GetIntAttribute(atr_WrappedQuantity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPackingParams::ValidWrappedQuantity(EnumValidationLevel level) const {
		return ValidAttribute(atr_WrappedQuantity,AttributeType_integer,false);
	};
}; // end namespace JDF
