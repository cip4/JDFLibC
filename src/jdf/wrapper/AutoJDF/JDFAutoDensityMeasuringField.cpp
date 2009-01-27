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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDensityMeasuringField.h"
#include "jdf/wrapper/JDFColorMeasurementConditions.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDensityMeasuringField : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDensityMeasuringField& JDFAutoDensityMeasuringField::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDensityMeasuringField: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDensityMeasuringField::ValidNodeNames()const{
	return L"*:,DensityMeasuringField";
};

bool JDFAutoDensityMeasuringField::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoDensityMeasuringField::init(){
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
	WString JDFAutoDensityMeasuringField::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Center,Density,Diameter,DotGain,Percentage,Screen,ToleranceCyan,ToleranceMagenta,ToleranceYellow,ToleranceBlack,ToleranceDotGain";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDensityMeasuringField::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Setup");
};

/**
 typesafe validator
*/
	vWString JDFAutoDensityMeasuringField::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCenter(level)) {
			vAtts.push_back(atr_Center);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDensity(level)) {
			vAtts.push_back(atr_Density);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDiameter(level)) {
			vAtts.push_back(atr_Diameter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDotGain(level)) {
			vAtts.push_back(atr_DotGain);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPercentage(level)) {
			vAtts.push_back(atr_Percentage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScreen(level)) {
			vAtts.push_back(atr_Screen);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidToleranceCyan(level)) {
			vAtts.push_back(atr_ToleranceCyan);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidToleranceMagenta(level)) {
			vAtts.push_back(atr_ToleranceMagenta);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidToleranceYellow(level)) {
			vAtts.push_back(atr_ToleranceYellow);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidToleranceBlack(level)) {
			vAtts.push_back(atr_ToleranceBlack);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidToleranceDotGain(level)) {
			vAtts.push_back(atr_ToleranceDotGain);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetup(level)) {
			vAtts.push_back(atr_Setup);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Center
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetCenter(const JDFXYPair& value){
	SetAttribute(atr_Center,value);
};
/**
* Get string attribute Center
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoDensityMeasuringField::GetCenter() const {
	return GetAttribute(atr_Center,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Center,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute Density
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetDensity(const JDFNumberList& value){
	SetAttribute(atr_Density,value.GetString());
};
/**
* Get string attribute Density
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoDensityMeasuringField::GetDensity() const {
	return GetAttribute(atr_Density,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidDensity(EnumValidationLevel level) const {
		return ValidAttribute(atr_Density,AttributeType_NumberList,RequiredLevel(level));
	};
/**
* Set attribute Diameter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetDiameter(double value){
	SetAttribute(atr_Diameter,WString::valueOf(value));
};
/**
* Get double attribute Diameter
* @return double the vaue of the attribute 
*/
	 double JDFAutoDensityMeasuringField::GetDiameter() const {
	return GetRealAttribute(atr_Diameter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidDiameter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Diameter,AttributeType_double,RequiredLevel(level));
	};
/**
* Set attribute DotGain
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetDotGain(double value){
	SetAttribute(atr_DotGain,WString::valueOf(value));
};
/**
* Get double attribute DotGain
* @return double the vaue of the attribute 
*/
	 double JDFAutoDensityMeasuringField::GetDotGain() const {
	return GetRealAttribute(atr_DotGain,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidDotGain(EnumValidationLevel level) const {
		return ValidAttribute(atr_DotGain,AttributeType_double,RequiredLevel(level));
	};
/**
* Set attribute Percentage
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetPercentage(double value){
	SetAttribute(atr_Percentage,WString::valueOf(value));
};
/**
* Get double attribute Percentage
* @return double the vaue of the attribute 
*/
	 double JDFAutoDensityMeasuringField::GetPercentage() const {
	return GetRealAttribute(atr_Percentage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidPercentage(EnumValidationLevel level) const {
		return ValidAttribute(atr_Percentage,AttributeType_double,RequiredLevel(level));
	};
/**
* Set attribute Screen
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetScreen(const WString& value){
	SetAttribute(atr_Screen,value);
};
/**
* Get string attribute Screen
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDensityMeasuringField::GetScreen() const {
	return GetAttribute(atr_Screen,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidScreen(EnumValidationLevel level) const {
		return ValidAttribute(atr_Screen,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute ToleranceCyan
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetToleranceCyan(const JDFXYPair& value){
	SetAttribute(atr_ToleranceCyan,value);
};
/**
* Get string attribute ToleranceCyan
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoDensityMeasuringField::GetToleranceCyan() const {
	return GetAttribute(atr_ToleranceCyan,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidToleranceCyan(EnumValidationLevel level) const {
		return ValidAttribute(atr_ToleranceCyan,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute ToleranceMagenta
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetToleranceMagenta(const JDFXYPair& value){
	SetAttribute(atr_ToleranceMagenta,value);
};
/**
* Get string attribute ToleranceMagenta
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoDensityMeasuringField::GetToleranceMagenta() const {
	return GetAttribute(atr_ToleranceMagenta,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidToleranceMagenta(EnumValidationLevel level) const {
		return ValidAttribute(atr_ToleranceMagenta,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute ToleranceYellow
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetToleranceYellow(const JDFXYPair& value){
	SetAttribute(atr_ToleranceYellow,value);
};
/**
* Get string attribute ToleranceYellow
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoDensityMeasuringField::GetToleranceYellow() const {
	return GetAttribute(atr_ToleranceYellow,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidToleranceYellow(EnumValidationLevel level) const {
		return ValidAttribute(atr_ToleranceYellow,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute ToleranceBlack
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetToleranceBlack(const JDFXYPair& value){
	SetAttribute(atr_ToleranceBlack,value);
};
/**
* Get string attribute ToleranceBlack
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoDensityMeasuringField::GetToleranceBlack() const {
	return GetAttribute(atr_ToleranceBlack,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidToleranceBlack(EnumValidationLevel level) const {
		return ValidAttribute(atr_ToleranceBlack,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute ToleranceDotGain
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetToleranceDotGain(const JDFXYPair& value){
	SetAttribute(atr_ToleranceDotGain,value);
};
/**
* Get string attribute ToleranceDotGain
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoDensityMeasuringField::GetToleranceDotGain() const {
	return GetAttribute(atr_ToleranceDotGain,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidToleranceDotGain(EnumValidationLevel level) const {
		return ValidAttribute(atr_ToleranceDotGain,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute Setup
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDensityMeasuringField::SetSetup(const WString& value){
	SetAttribute(atr_Setup,value);
};
/**
* Get string attribute Setup
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDensityMeasuringField::GetSetup() const {
	return GetAttribute(atr_Setup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDensityMeasuringField::ValidSetup(EnumValidationLevel level) const {
		return ValidAttribute(atr_Setup,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColorMeasurementConditions JDFAutoDensityMeasuringField::GetColorMeasurementConditions()const{
	JDFColorMeasurementConditions e=GetElement(elm_ColorMeasurementConditions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoDensityMeasuringField::GetCreateColorMeasurementConditions(){
	JDFColorMeasurementConditions e=GetCreateElement(elm_ColorMeasurementConditions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoDensityMeasuringField::AppendColorMeasurementConditions(){
	JDFColorMeasurementConditions e=AppendElementN(elm_ColorMeasurementConditions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDensityMeasuringField::RefColorMeasurementConditions(JDFColorMeasurementConditions& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDensityMeasuringField::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoDensityMeasuringField::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorMeasurementConditions";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDensityMeasuringField::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorMeasurementConditions";
	};
}; // end namespace JDF
