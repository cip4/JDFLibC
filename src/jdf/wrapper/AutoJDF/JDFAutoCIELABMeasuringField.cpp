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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCIELABMeasuringField.h"
#include "jdf/wrapper/JDFColorMeasurementConditions.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCIELABMeasuringField : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCIELABMeasuringField& JDFAutoCIELABMeasuringField::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCIELABMeasuringField: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCIELABMeasuringField::ValidNodeNames()const{
	return L"*:,CIELABMeasuringField";
};

bool JDFAutoCIELABMeasuringField::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoCIELABMeasuringField::init(){
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
	WString JDFAutoCIELABMeasuringField::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Center,CIELab";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCIELABMeasuringField::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DensityStandard,Diameter,Light,Observer,Percentages,ScreenRuling,ScreenShape,Setup,Tolerance");
};

/**
 typesafe validator
*/
	vWString JDFAutoCIELABMeasuringField::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCenter(level)) {
			vAtts.push_back(atr_Center);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCIELab(level)) {
			vAtts.push_back(atr_CIELab);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDensityStandard(level)) {
			vAtts.push_back(atr_DensityStandard);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDiameter(level)) {
			vAtts.push_back(atr_Diameter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLight(level)) {
			vAtts.push_back(atr_Light);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidObserver(level)) {
			vAtts.push_back(atr_Observer);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPercentages(level)) {
			vAtts.push_back(atr_Percentages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScreenRuling(level)) {
			vAtts.push_back(atr_ScreenRuling);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScreenShape(level)) {
			vAtts.push_back(atr_ScreenShape);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetup(level)) {
			vAtts.push_back(atr_Setup);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTolerance(level)) {
			vAtts.push_back(atr_Tolerance);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Center
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetCenter(const JDFXYPair& value){
	SetAttribute(atr_Center,value);
};
/**
* Get string attribute Center
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCIELABMeasuringField::GetCenter() const {
	return GetAttribute(atr_Center,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Center,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute CIELab
*@param JDFLabColor value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetCIELab(const JDFLabColor& value){
	SetAttribute(atr_CIELab,value);
};
/**
* Get string attribute CIELab
* @return JDFLabColor the vaue of the attribute 
*/
	 JDFLabColor JDFAutoCIELABMeasuringField::GetCIELab() const {
	return GetAttribute(atr_CIELab,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidCIELab(EnumValidationLevel level) const {
		return ValidAttribute(atr_CIELab,AttributeType_LabColor,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCIELABMeasuringField::DensityStandardString(){
		static const WString enums=WString(L"Unknown,ANSIA,ANSIE,ANSII,ANSIT,DIN16536,DIN16536NB");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCIELABMeasuringField::DensityStandardString(EnumDensityStandard value){
		return DensityStandardString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCIELABMeasuringField::SetDensityStandard( EnumDensityStandard value){
	SetEnumAttribute(atr_DensityStandard,value,DensityStandardString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCIELABMeasuringField::EnumDensityStandard JDFAutoCIELABMeasuringField:: GetDensityStandard() const {
	return (EnumDensityStandard) GetEnumAttribute(atr_DensityStandard,DensityStandardString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidDensityStandard(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DensityStandard,DensityStandardString(),false);
	};
/**
* Set attribute Diameter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetDiameter(double value){
	SetAttribute(atr_Diameter,WString::valueOf(value));
};
/**
* Get double attribute Diameter
* @return double the vaue of the attribute 
*/
	 double JDFAutoCIELABMeasuringField::GetDiameter() const {
	return GetRealAttribute(atr_Diameter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidDiameter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Diameter,AttributeType_double,false);
	};
/**
* Set attribute Light
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetLight(const WString& value){
	SetAttribute(atr_Light,value);
};
/**
* Get string attribute Light
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCIELABMeasuringField::GetLight() const {
	return GetAttribute(atr_Light,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidLight(EnumValidationLevel level) const {
		return ValidAttribute(atr_Light,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Observer
*@param int value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetObserver(int value){
	SetAttribute(atr_Observer,WString::valueOf(value));
};
/**
* Get integer attribute Observer
* @return int the vaue of the attribute 
*/
	 int JDFAutoCIELABMeasuringField::GetObserver() const {
	return GetIntAttribute(atr_Observer,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidObserver(EnumValidationLevel level) const {
		return ValidAttribute(atr_Observer,AttributeType_integer,false);
	};
/**
* Set attribute Percentages
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetPercentages(const JDFNumberList& value){
	SetAttribute(atr_Percentages,value.GetString());
};
/**
* Get string attribute Percentages
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoCIELABMeasuringField::GetPercentages() const {
	return GetAttribute(atr_Percentages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidPercentages(EnumValidationLevel level) const {
		return ValidAttribute(atr_Percentages,AttributeType_NumberList,false);
	};
/**
* Set attribute ScreenRuling
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetScreenRuling(const JDFNumberList& value){
	SetAttribute(atr_ScreenRuling,value.GetString());
};
/**
* Get string attribute ScreenRuling
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoCIELABMeasuringField::GetScreenRuling() const {
	return GetAttribute(atr_ScreenRuling,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidScreenRuling(EnumValidationLevel level) const {
		return ValidAttribute(atr_ScreenRuling,AttributeType_NumberList,false);
	};
/**
* Set attribute ScreenShape
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetScreenShape(const WString& value){
	SetAttribute(atr_ScreenShape,value);
};
/**
* Get string attribute ScreenShape
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCIELABMeasuringField::GetScreenShape() const {
	return GetAttribute(atr_ScreenShape,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidScreenShape(EnumValidationLevel level) const {
		return ValidAttribute(atr_ScreenShape,AttributeType_string,false);
	};
/**
* Set attribute Setup
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetSetup(const WString& value){
	SetAttribute(atr_Setup,value);
};
/**
* Get string attribute Setup
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCIELABMeasuringField::GetSetup() const {
	return GetAttribute(atr_Setup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidSetup(EnumValidationLevel level) const {
		return ValidAttribute(atr_Setup,AttributeType_string,false);
	};
/**
* Set attribute Tolerance
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCIELABMeasuringField::SetTolerance(double value){
	SetAttribute(atr_Tolerance,WString::valueOf(value));
};
/**
* Get double attribute Tolerance
* @return double the vaue of the attribute 
*/
	 double JDFAutoCIELABMeasuringField::GetTolerance() const {
	return GetRealAttribute(atr_Tolerance,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCIELABMeasuringField::ValidTolerance(EnumValidationLevel level) const {
		return ValidAttribute(atr_Tolerance,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColorMeasurementConditions JDFAutoCIELABMeasuringField::GetColorMeasurementConditions()const{
	JDFColorMeasurementConditions e=GetElement(elm_ColorMeasurementConditions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoCIELABMeasuringField::GetCreateColorMeasurementConditions(){
	JDFColorMeasurementConditions e=GetCreateElement(elm_ColorMeasurementConditions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoCIELABMeasuringField::AppendColorMeasurementConditions(){
	JDFColorMeasurementConditions e=AppendElementN(elm_ColorMeasurementConditions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCIELABMeasuringField::RefColorMeasurementConditions(JDFColorMeasurementConditions& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCIELABMeasuringField::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorMeasurementConditions);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorMeasurementConditions);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorMeasurementConditions().IsValid(level)) {
				vElem.AppendUnique(elm_ColorMeasurementConditions);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoCIELABMeasuringField::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorMeasurementConditions";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoCIELABMeasuringField::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorMeasurementConditions";
	};
}; // end namespace JDF
