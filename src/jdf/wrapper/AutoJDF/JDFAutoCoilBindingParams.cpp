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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCoilBindingParams.h"
#include "jdf/wrapper/JDFHoleMakingParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCoilBindingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCoilBindingParams& JDFAutoCoilBindingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCoilBindingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCoilBindingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCoilBindingParams::ValidNodeNames()const{
	return L"*:,CoilBindingParams";
};

bool JDFAutoCoilBindingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoCoilBindingParams::init(){
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
	WString JDFAutoCoilBindingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Tucked,Brand,Color,Diameter,Material,Shift,Thickness");
};

/**
 typesafe validator
*/
	vWString JDFAutoCoilBindingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTucked(level)) {
			vAtts.push_back(atr_Tucked);
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
		if(!ValidMaterial(level)) {
			vAtts.push_back(atr_Material);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShift(level)) {
			vAtts.push_back(atr_Shift);
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
* Set attribute Tucked
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoCoilBindingParams::SetTucked(bool value){
	SetAttribute(atr_Tucked,WString::valueOf(value));
};
/**
* Get bool attribute Tucked
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoCoilBindingParams::GetTucked() const {return GetBoolAttribute(atr_Tucked,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCoilBindingParams::ValidTucked(EnumValidationLevel level) const {
		return ValidAttribute(atr_Tucked,AttributeType_boolean,false);
	};
/**
* Set attribute Brand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCoilBindingParams::SetBrand(const WString& value){
	SetAttribute(atr_Brand,value);
};
/**
* Get string attribute Brand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCoilBindingParams::GetBrand() const {
	return GetAttribute(atr_Brand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCoilBindingParams::ValidBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_Brand,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoCoilBindingParams::SetColor( EnumNamedColor value){
	SetEnumAttribute(atr_Color,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCoilBindingParams::EnumNamedColor JDFAutoCoilBindingParams:: GetColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_Color,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCoilBindingParams::ValidColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Color,NamedColorString(),false);
	};
/**
* Set attribute Diameter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCoilBindingParams::SetDiameter(double value){
	SetAttribute(atr_Diameter,WString::valueOf(value));
};
/**
* Get double attribute Diameter
* @return double the vaue of the attribute 
*/
	 double JDFAutoCoilBindingParams::GetDiameter() const {
	return GetRealAttribute(atr_Diameter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCoilBindingParams::ValidDiameter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Diameter,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCoilBindingParams::MaterialString(){
		static const WString enums=WString(L"Unknown,LaqueredSteel,NylonCoatedSteel,PVC,TinnedSteel,ZincsSteel");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCoilBindingParams::MaterialString(EnumMaterial value){
		return MaterialString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCoilBindingParams::SetMaterial( EnumMaterial value){
	SetEnumAttribute(atr_Material,value,MaterialString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCoilBindingParams::EnumMaterial JDFAutoCoilBindingParams:: GetMaterial() const {
	return (EnumMaterial) GetEnumAttribute(atr_Material,MaterialString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCoilBindingParams::ValidMaterial(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Material,MaterialString(),false);
	};
/**
* Set attribute Shift
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCoilBindingParams::SetShift(double value){
	SetAttribute(atr_Shift,WString::valueOf(value));
};
/**
* Get double attribute Shift
* @return double the vaue of the attribute 
*/
	 double JDFAutoCoilBindingParams::GetShift() const {
	return GetRealAttribute(atr_Shift,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCoilBindingParams::ValidShift(EnumValidationLevel level) const {
		return ValidAttribute(atr_Shift,AttributeType_double,false);
	};
/**
* Set attribute Thickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCoilBindingParams::SetThickness(double value){
	SetAttribute(atr_Thickness,WString::valueOf(value));
};
/**
* Get double attribute Thickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoCoilBindingParams::GetThickness() const {
	return GetRealAttribute(atr_Thickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCoilBindingParams::ValidThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_Thickness,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFHoleMakingParams JDFAutoCoilBindingParams::GetHoleMakingParams()const{
	JDFHoleMakingParams e=GetElement(elm_HoleMakingParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleMakingParams JDFAutoCoilBindingParams::GetCreateHoleMakingParams(){
	JDFHoleMakingParams e=GetCreateElement(elm_HoleMakingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleMakingParams JDFAutoCoilBindingParams::AppendHoleMakingParams(){
	JDFHoleMakingParams e=AppendElementN(elm_HoleMakingParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCoilBindingParams::RefHoleMakingParams(JDFHoleMakingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCoilBindingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoCoilBindingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",HoleMakingParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoCoilBindingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",HoleMakingParams";
	};
}; // end namespace JDF
