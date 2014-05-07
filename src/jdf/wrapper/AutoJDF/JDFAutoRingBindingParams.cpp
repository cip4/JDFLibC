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

 
#include "jdf/wrapper/AutoJDF/JDFAutoRingBindingParams.h"
#include "jdf/wrapper/JDFHoleMakingParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRingBindingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoRingBindingParams& JDFAutoRingBindingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoRingBindingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoRingBindingParams::ValidNodeNames()const{
	return L"*:,RingBindingParams";
};

bool JDFAutoRingBindingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoRingBindingParams::init(){
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
	WString JDFAutoRingBindingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BinderColor,BinderColorDetails,BinderMaterial,BinderName,RingDiameter,RingMechanic,RingShape,RingSystem,RivetsExposed,SpineColor,SpineColorDetails,SpineWidth,ViewBinder");
};

/**
 typesafe validator
*/
	vWString JDFAutoRingBindingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBinderColor(level)) {
			vAtts.push_back(atr_BinderColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBinderColorDetails(level)) {
			vAtts.push_back(atr_BinderColorDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBinderMaterial(level)) {
			vAtts.push_back(atr_BinderMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBinderName(level)) {
			vAtts.push_back(atr_BinderName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRingDiameter(level)) {
			vAtts.push_back(atr_RingDiameter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRingMechanic(level)) {
			vAtts.push_back(atr_RingMechanic);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRingShape(level)) {
			vAtts.push_back(atr_RingShape);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRingSystem(level)) {
			vAtts.push_back(atr_RingSystem);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRivetsExposed(level)) {
			vAtts.push_back(atr_RivetsExposed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpineColor(level)) {
			vAtts.push_back(atr_SpineColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpineColorDetails(level)) {
			vAtts.push_back(atr_SpineColorDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpineWidth(level)) {
			vAtts.push_back(atr_SpineWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidViewBinder(level)) {
			vAtts.push_back(atr_ViewBinder);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRingBindingParams::SetBinderColor( EnumNamedColor value){
	SetEnumAttribute(atr_BinderColor,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRingBindingParams::EnumNamedColor JDFAutoRingBindingParams:: GetBinderColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_BinderColor,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidBinderColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BinderColor,NamedColorString(),false);
	};
/**
* Set attribute BinderColorDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetBinderColorDetails(const WString& value){
	SetAttribute(atr_BinderColorDetails,value);
};
/**
* Get string attribute BinderColorDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRingBindingParams::GetBinderColorDetails() const {
	return GetAttribute(atr_BinderColorDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidBinderColorDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_BinderColorDetails,AttributeType_string,false);
	};
/**
* Set attribute BinderMaterial
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetBinderMaterial(const WString& value){
	SetAttribute(atr_BinderMaterial,value);
};
/**
* Get string attribute BinderMaterial
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRingBindingParams::GetBinderMaterial() const {
	return GetAttribute(atr_BinderMaterial,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidBinderMaterial(EnumValidationLevel level) const {
		return ValidAttribute(atr_BinderMaterial,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute BinderName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetBinderName(const WString& value){
	SetAttribute(atr_BinderName,value);
};
/**
* Get string attribute BinderName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRingBindingParams::GetBinderName() const {
	return GetAttribute(atr_BinderName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidBinderName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BinderName,AttributeType_string,false);
	};
/**
* Set attribute RingDiameter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetRingDiameter(double value){
	SetAttribute(atr_RingDiameter,WString::valueOf(value));
};
/**
* Get double attribute RingDiameter
* @return double the vaue of the attribute 
*/
	 double JDFAutoRingBindingParams::GetRingDiameter() const {
	return GetRealAttribute(atr_RingDiameter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidRingDiameter(EnumValidationLevel level) const {
		return ValidAttribute(atr_RingDiameter,AttributeType_double,false);
	};
/**
* Set attribute RingMechanic
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetRingMechanic(bool value){
	SetAttribute(atr_RingMechanic,WString::valueOf(value));
};
/**
* Get bool attribute RingMechanic
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoRingBindingParams::GetRingMechanic() const {return GetBoolAttribute(atr_RingMechanic,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidRingMechanic(EnumValidationLevel level) const {
		return ValidAttribute(atr_RingMechanic,AttributeType_boolean,false);
	};
/**
* Set attribute RingShape
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetRingShape(const WString& value){
	SetAttribute(atr_RingShape,value);
};
/**
* Get string attribute RingShape
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRingBindingParams::GetRingShape() const {
	return GetAttribute(atr_RingShape,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidRingShape(EnumValidationLevel level) const {
		return ValidAttribute(atr_RingShape,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoRingBindingParams::RingSystemString(){
		static const WString enums=WString(L"Unknown,2HoleEuro,3HoleUS,4HoleEuro");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoRingBindingParams::RingSystemString(EnumRingSystem value){
		return RingSystemString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRingBindingParams::SetRingSystem( EnumRingSystem value){
	SetEnumAttribute(atr_RingSystem,value,RingSystemString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRingBindingParams::EnumRingSystem JDFAutoRingBindingParams:: GetRingSystem() const {
	return (EnumRingSystem) GetEnumAttribute(atr_RingSystem,RingSystemString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidRingSystem(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_RingSystem,RingSystemString(),false);
	};
/**
* Set attribute RivetsExposed
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetRivetsExposed(bool value){
	SetAttribute(atr_RivetsExposed,WString::valueOf(value));
};
/**
* Get bool attribute RivetsExposed
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoRingBindingParams::GetRivetsExposed() const {return GetBoolAttribute(atr_RivetsExposed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidRivetsExposed(EnumValidationLevel level) const {
		return ValidAttribute(atr_RivetsExposed,AttributeType_boolean,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoRingBindingParams::SetSpineColor( EnumNamedColor value){
	SetEnumAttribute(atr_SpineColor,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRingBindingParams::EnumNamedColor JDFAutoRingBindingParams:: GetSpineColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_SpineColor,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidSpineColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SpineColor,NamedColorString(),false);
	};
/**
* Set attribute SpineColorDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetSpineColorDetails(const WString& value){
	SetAttribute(atr_SpineColorDetails,value);
};
/**
* Get string attribute SpineColorDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRingBindingParams::GetSpineColorDetails() const {
	return GetAttribute(atr_SpineColorDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidSpineColorDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpineColorDetails,AttributeType_string,false);
	};
/**
* Set attribute SpineWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetSpineWidth(double value){
	SetAttribute(atr_SpineWidth,WString::valueOf(value));
};
/**
* Get double attribute SpineWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoRingBindingParams::GetSpineWidth() const {
	return GetRealAttribute(atr_SpineWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidSpineWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpineWidth,AttributeType_double,false);
	};
/**
* Set attribute ViewBinder
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRingBindingParams::SetViewBinder(const WString& value){
	SetAttribute(atr_ViewBinder,value);
};
/**
* Get string attribute ViewBinder
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRingBindingParams::GetViewBinder() const {
	return GetAttribute(atr_ViewBinder,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRingBindingParams::ValidViewBinder(EnumValidationLevel level) const {
		return ValidAttribute(atr_ViewBinder,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFHoleMakingParams JDFAutoRingBindingParams::GetHoleMakingParams()const{
	JDFHoleMakingParams e=GetElement(elm_HoleMakingParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleMakingParams JDFAutoRingBindingParams::GetCreateHoleMakingParams(){
	JDFHoleMakingParams e=GetCreateElement(elm_HoleMakingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleMakingParams JDFAutoRingBindingParams::AppendHoleMakingParams(){
	JDFHoleMakingParams e=AppendElementN(elm_HoleMakingParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoRingBindingParams::RefHoleMakingParams(JDFHoleMakingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoRingBindingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoRingBindingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",HoleMakingParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoRingBindingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",HoleMakingParams";
	};
}; // end namespace JDF
