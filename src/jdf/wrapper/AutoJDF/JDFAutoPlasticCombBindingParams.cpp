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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPlasticCombBindingParams.h"
#include "jdf/wrapper/JDFHoleMakingParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPlasticCombBindingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPlasticCombBindingParams& JDFAutoPlasticCombBindingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPlasticCombBindingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPlasticCombBindingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPlasticCombBindingParams::ValidNodeNames()const{
	return L"*:,PlasticCombBindingParams";
};

bool JDFAutoPlasticCombBindingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPlasticCombBindingParams::init(){
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
	WString JDFAutoPlasticCombBindingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Brand,Color,Diameter,Thickness,Type");
};

/**
 typesafe validator
*/
	vWString JDFAutoPlasticCombBindingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBrand(level)) {
			vAtts.push_back(atr_Brand);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColor(level)) {
			vAtts.push_back(atr_Color);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDiameter(level)) {
			vAtts.push_back(atr_Diameter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThickness(level)) {
			vAtts.push_back(atr_Thickness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Brand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPlasticCombBindingParams::SetBrand(const WString& value){
	SetAttribute(atr_Brand,value);
};
/**
* Get string attribute Brand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPlasticCombBindingParams::GetBrand() const {
	return GetAttribute(atr_Brand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPlasticCombBindingParams::ValidBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_Brand,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPlasticCombBindingParams::SetColor( EnumNamedColor value){
	SetEnumAttribute(atr_Color,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPlasticCombBindingParams::EnumNamedColor JDFAutoPlasticCombBindingParams:: GetColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_Color,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPlasticCombBindingParams::ValidColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Color,NamedColorString(),false);
	};
/**
* Set attribute Diameter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPlasticCombBindingParams::SetDiameter(double value){
	SetAttribute(atr_Diameter,WString::valueOf(value));
};
/**
* Get double attribute Diameter
* @return double the vaue of the attribute 
*/
	 double JDFAutoPlasticCombBindingParams::GetDiameter() const {
	return GetRealAttribute(atr_Diameter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPlasticCombBindingParams::ValidDiameter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Diameter,AttributeType_double,false);
	};
/**
* Set attribute Thickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPlasticCombBindingParams::SetThickness(double value){
	SetAttribute(atr_Thickness,WString::valueOf(value));
};
/**
* Get double attribute Thickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoPlasticCombBindingParams::GetThickness() const {
	return GetRealAttribute(atr_Thickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPlasticCombBindingParams::ValidThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_Thickness,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPlasticCombBindingParams::TypeString(){
		static const WString enums=WString(L"Unknown,R2-generic,R2m-DIN,R2m-ISO,R2m-MIB,R2i-US-a,R2i-US-b,R3-generic,R3i-US,R4-generic")
	+WString(L",R4m-DIN-A4,R4m-DIN-A5,R4m-swedish,R4i-US,R5-generic,R5i-US-a,R5i-US-b,R5i-US-c,R6-generic,R6m-4h2s")
	+WString(L",R6m-DIN-A5,R7-generic,R7i-US-a,R7i-US-b,R7i-US-c,R11m-7h4s,P16_9i-rect-0t,P12m-rect-0t,W2_1i-round-0t,W2_1i-square-0t")
	+WString(L",W3_1i-square-0t,C9.5m-round-0t");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPlasticCombBindingParams::TypeString(EnumType value){
		return TypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPlasticCombBindingParams::SetType( EnumType value){
	SetEnumAttribute(atr_Type,value,TypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPlasticCombBindingParams::EnumType JDFAutoPlasticCombBindingParams:: GetType() const {
	return (EnumType) GetEnumAttribute(atr_Type,TypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPlasticCombBindingParams::ValidType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Type,TypeString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFHoleMakingParams JDFAutoPlasticCombBindingParams::GetHoleMakingParams()const{
	JDFHoleMakingParams e=GetElement(elm_HoleMakingParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleMakingParams JDFAutoPlasticCombBindingParams::GetCreateHoleMakingParams(){
	JDFHoleMakingParams e=GetCreateElement(elm_HoleMakingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleMakingParams JDFAutoPlasticCombBindingParams::AppendHoleMakingParams(){
	JDFHoleMakingParams e=AppendElementN(elm_HoleMakingParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPlasticCombBindingParams::RefHoleMakingParams(JDFHoleMakingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPlasticCombBindingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_HoleMakingParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_HoleMakingParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetHoleMakingParams().IsValid(level)) {
				vElem.AppendUnique(elm_HoleMakingParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPlasticCombBindingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",HoleMakingParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPlasticCombBindingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",HoleMakingParams";
	};
}; // end namespace JDF
