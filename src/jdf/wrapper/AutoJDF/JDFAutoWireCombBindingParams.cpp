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

 
#include "jdf/wrapper/AutoJDF/JDFAutoWireCombBindingParams.h"
#include "jdf/wrapper/JDFHoleMakingParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoWireCombBindingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoWireCombBindingParams& JDFAutoWireCombBindingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoWireCombBindingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoWireCombBindingParams::ValidNodeNames()const{
	return L"*:,WireCombBindingParams";
};

bool JDFAutoWireCombBindingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoWireCombBindingParams::init(){
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
	WString JDFAutoWireCombBindingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",FlipBackCover,Shape,Brand,Color,Diameter,Distance,Material,Thickness");
};

/**
 typesafe validator
*/
	vWString JDFAutoWireCombBindingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFlipBackCover(level)) {
			vAtts.push_back(atr_FlipBackCover);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShape(level)) {
			vAtts.push_back(atr_Shape);
			if(++n>=nMax)
				return vAtts;
		};
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
		if(!ValidDistance(level)) {
			vAtts.push_back(atr_Distance);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaterial(level)) {
			vAtts.push_back(atr_Material);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThickness(level)) {
			vAtts.push_back(atr_Thickness);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute FlipBackCover
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoWireCombBindingParams::SetFlipBackCover(bool value){
	SetAttribute(atr_FlipBackCover,WString::valueOf(value));
};
/**
* Get bool attribute FlipBackCover
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoWireCombBindingParams::GetFlipBackCover() const {return GetBoolAttribute(atr_FlipBackCover,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::ValidFlipBackCover(EnumValidationLevel level) const {
		return ValidAttribute(atr_FlipBackCover,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoWireCombBindingParams::ShapeString(){
		static const WString enums=WString(L"Unknown,Single,Twin");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoWireCombBindingParams::ShapeString(EnumShape value){
		return ShapeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoWireCombBindingParams::SetShape( EnumShape value){
	SetEnumAttribute(atr_Shape,value,ShapeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoWireCombBindingParams::EnumShape JDFAutoWireCombBindingParams:: GetShape() const {
	return (EnumShape) GetEnumAttribute(atr_Shape,ShapeString(),WString::emptyStr,Shape_Single);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::ValidShape(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Shape,ShapeString(),false);
	};
/**
* Set attribute Brand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoWireCombBindingParams::SetBrand(const WString& value){
	SetAttribute(atr_Brand,value);
};
/**
* Get string attribute Brand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoWireCombBindingParams::GetBrand() const {
	return GetAttribute(atr_Brand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::ValidBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_Brand,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoWireCombBindingParams::SetColor( EnumNamedColor value){
	SetEnumAttribute(atr_Color,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoWireCombBindingParams::EnumNamedColor JDFAutoWireCombBindingParams:: GetColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_Color,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::ValidColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Color,NamedColorString(),false);
	};
/**
* Set attribute Diameter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoWireCombBindingParams::SetDiameter(double value){
	SetAttribute(atr_Diameter,WString::valueOf(value));
};
/**
* Get double attribute Diameter
* @return double the vaue of the attribute 
*/
	 double JDFAutoWireCombBindingParams::GetDiameter() const {
	return GetRealAttribute(atr_Diameter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::ValidDiameter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Diameter,AttributeType_double,false);
	};
/**
* Set attribute Distance
*@param double value: the value to set the attribute to
*/
	 void JDFAutoWireCombBindingParams::SetDistance(double value){
	SetAttribute(atr_Distance,WString::valueOf(value));
};
/**
* Get double attribute Distance
* @return double the vaue of the attribute 
*/
	 double JDFAutoWireCombBindingParams::GetDistance() const {
	return GetRealAttribute(atr_Distance,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::ValidDistance(EnumValidationLevel level) const {
		return ValidAttribute(atr_Distance,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoWireCombBindingParams::MaterialString(){
		static const WString enums=WString(L"Unknown,LaqueredSteel,TinnedSteel,ZincsSteel");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoWireCombBindingParams::MaterialString(EnumMaterial value){
		return MaterialString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoWireCombBindingParams::SetMaterial( EnumMaterial value){
	SetEnumAttribute(atr_Material,value,MaterialString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoWireCombBindingParams::EnumMaterial JDFAutoWireCombBindingParams:: GetMaterial() const {
	return (EnumMaterial) GetEnumAttribute(atr_Material,MaterialString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::ValidMaterial(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Material,MaterialString(),false);
	};
/**
* Set attribute Thickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoWireCombBindingParams::SetThickness(double value){
	SetAttribute(atr_Thickness,WString::valueOf(value));
};
/**
* Get double attribute Thickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoWireCombBindingParams::GetThickness() const {
	return GetRealAttribute(atr_Thickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoWireCombBindingParams::ValidThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_Thickness,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFHoleMakingParams JDFAutoWireCombBindingParams::GetHoleMakingParams()const{
	JDFHoleMakingParams e=GetElement(elm_HoleMakingParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleMakingParams JDFAutoWireCombBindingParams::GetCreateHoleMakingParams(){
	JDFHoleMakingParams e=GetCreateElement(elm_HoleMakingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleMakingParams JDFAutoWireCombBindingParams::AppendHoleMakingParams(){
	JDFHoleMakingParams e=AppendElementN(elm_HoleMakingParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoWireCombBindingParams::RefHoleMakingParams(JDFHoleMakingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoWireCombBindingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoWireCombBindingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",HoleMakingParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoWireCombBindingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",HoleMakingParams";
	};
}; // end namespace JDF
