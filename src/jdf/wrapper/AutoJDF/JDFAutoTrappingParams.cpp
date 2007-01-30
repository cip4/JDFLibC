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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTrappingParams.h"
#include "jdf/wrapper/JDFColorantZoneDetails.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTrappingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTrappingParams& JDFAutoTrappingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTrappingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTrappingParams::ValidNodeNames()const{
	return L"*:,TrappingParams";
};

bool JDFAutoTrappingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoTrappingParams::init(){
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
	WString JDFAutoTrappingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",MinimumBlackWidth,TrapEndStyle,TrapJoinStyle,BlackColorLimit,BlackDensityLimit,BlackWidth,Enabled,HalftoneName,ImageInternalTrapping,ImageResolution,ImageMaskTrapping,ImageToImageTrapping,ImageToObjectTrapping,ImageTrapPlacement,ImageTrapWidth,ImageTrapWidthY,SlidingTrapLimit,StepLimit,TrapColorScaling")
	+WString(L",TrapWidth,TrapWidthY");
};

/**
 typesafe validator
*/
	vWString JDFAutoTrappingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMinimumBlackWidth(level)) {
			vAtts.push_back(atr_MinimumBlackWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapEndStyle(level)) {
			vAtts.push_back(atr_TrapEndStyle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapJoinStyle(level)) {
			vAtts.push_back(atr_TrapJoinStyle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlackColorLimit(level)) {
			vAtts.push_back(atr_BlackColorLimit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlackDensityLimit(level)) {
			vAtts.push_back(atr_BlackDensityLimit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlackWidth(level)) {
			vAtts.push_back(atr_BlackWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEnabled(level)) {
			vAtts.push_back(atr_Enabled);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHalftoneName(level)) {
			vAtts.push_back(atr_HalftoneName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageInternalTrapping(level)) {
			vAtts.push_back(atr_ImageInternalTrapping);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageResolution(level)) {
			vAtts.push_back(atr_ImageResolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageMaskTrapping(level)) {
			vAtts.push_back(atr_ImageMaskTrapping);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageToImageTrapping(level)) {
			vAtts.push_back(atr_ImageToImageTrapping);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageToObjectTrapping(level)) {
			vAtts.push_back(atr_ImageToObjectTrapping);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageTrapPlacement(level)) {
			vAtts.push_back(atr_ImageTrapPlacement);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageTrapWidth(level)) {
			vAtts.push_back(atr_ImageTrapWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageTrapWidthY(level)) {
			vAtts.push_back(atr_ImageTrapWidthY);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSlidingTrapLimit(level)) {
			vAtts.push_back(atr_SlidingTrapLimit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStepLimit(level)) {
			vAtts.push_back(atr_StepLimit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapColorScaling(level)) {
			vAtts.push_back(atr_TrapColorScaling);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapWidth(level)) {
			vAtts.push_back(atr_TrapWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapWidthY(level)) {
			vAtts.push_back(atr_TrapWidthY);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute MinimumBlackWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetMinimumBlackWidth(double value){
	SetAttribute(atr_MinimumBlackWidth,WString::valueOf(value));
};
/**
* Get double attribute MinimumBlackWidth
* @return double the vaue of the attribute ; defaults to 0
*/
	 double JDFAutoTrappingParams::GetMinimumBlackWidth() const {
	return GetRealAttribute(atr_MinimumBlackWidth,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidMinimumBlackWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinimumBlackWidth,AttributeType_double,false);
	};
/**
* Set attribute TrapEndStyle
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetTrapEndStyle(const WString& value){
	SetAttribute(atr_TrapEndStyle,value);
};
/**
* Get string attribute TrapEndStyle
* @return WString the vaue of the attribute ; defaults to Miter
*/
	 WString JDFAutoTrappingParams::GetTrapEndStyle() const {
	return GetAttribute(atr_TrapEndStyle,WString::emptyStr,L"Miter");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidTrapEndStyle(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrapEndStyle,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute TrapJoinStyle
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetTrapJoinStyle(const WString& value){
	SetAttribute(atr_TrapJoinStyle,value);
};
/**
* Get string attribute TrapJoinStyle
* @return WString the vaue of the attribute ; defaults to Miter
*/
	 WString JDFAutoTrappingParams::GetTrapJoinStyle() const {
	return GetAttribute(atr_TrapJoinStyle,WString::emptyStr,L"Miter");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidTrapJoinStyle(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrapJoinStyle,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute BlackColorLimit
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetBlackColorLimit(double value){
	SetAttribute(atr_BlackColorLimit,WString::valueOf(value));
};
/**
* Get double attribute BlackColorLimit
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetBlackColorLimit() const {
	return GetRealAttribute(atr_BlackColorLimit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidBlackColorLimit(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlackColorLimit,AttributeType_double,false);
	};
/**
* Set attribute BlackDensityLimit
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetBlackDensityLimit(double value){
	SetAttribute(atr_BlackDensityLimit,WString::valueOf(value));
};
/**
* Get double attribute BlackDensityLimit
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetBlackDensityLimit() const {
	return GetRealAttribute(atr_BlackDensityLimit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidBlackDensityLimit(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlackDensityLimit,AttributeType_double,false);
	};
/**
* Set attribute BlackWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetBlackWidth(double value){
	SetAttribute(atr_BlackWidth,WString::valueOf(value));
};
/**
* Get double attribute BlackWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetBlackWidth() const {
	return GetRealAttribute(atr_BlackWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidBlackWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlackWidth,AttributeType_double,false);
	};
/**
* Set attribute Enabled
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetEnabled(bool value){
	SetAttribute(atr_Enabled,WString::valueOf(value));
};
/**
* Get bool attribute Enabled
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoTrappingParams::GetEnabled() const {return GetBoolAttribute(atr_Enabled,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidEnabled(EnumValidationLevel level) const {
		return ValidAttribute(atr_Enabled,AttributeType_boolean,false);
	};
/**
* Set attribute HalftoneName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetHalftoneName(const WString& value){
	SetAttribute(atr_HalftoneName,value);
};
/**
* Get string attribute HalftoneName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoTrappingParams::GetHalftoneName() const {
	return GetAttribute(atr_HalftoneName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidHalftoneName(EnumValidationLevel level) const {
		return ValidAttribute(atr_HalftoneName,AttributeType_string,false);
	};
/**
* Set attribute ImageInternalTrapping
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetImageInternalTrapping(bool value){
	SetAttribute(atr_ImageInternalTrapping,WString::valueOf(value));
};
/**
* Get bool attribute ImageInternalTrapping
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoTrappingParams::GetImageInternalTrapping() const {return GetBoolAttribute(atr_ImageInternalTrapping,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidImageInternalTrapping(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageInternalTrapping,AttributeType_boolean,false);
	};
/**
* Set attribute ImageResolution
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetImageResolution(int value){
	SetAttribute(atr_ImageResolution,WString::valueOf(value));
};
/**
* Get integer attribute ImageResolution
* @return int the vaue of the attribute 
*/
	 int JDFAutoTrappingParams::GetImageResolution() const {
	return GetIntAttribute(atr_ImageResolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidImageResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageResolution,AttributeType_integer,false);
	};
/**
* Set attribute ImageMaskTrapping
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetImageMaskTrapping(bool value){
	SetAttribute(atr_ImageMaskTrapping,WString::valueOf(value));
};
/**
* Get bool attribute ImageMaskTrapping
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoTrappingParams::GetImageMaskTrapping() const {return GetBoolAttribute(atr_ImageMaskTrapping,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidImageMaskTrapping(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageMaskTrapping,AttributeType_boolean,false);
	};
/**
* Set attribute ImageToImageTrapping
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetImageToImageTrapping(bool value){
	SetAttribute(atr_ImageToImageTrapping,WString::valueOf(value));
};
/**
* Get bool attribute ImageToImageTrapping
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoTrappingParams::GetImageToImageTrapping() const {return GetBoolAttribute(atr_ImageToImageTrapping,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidImageToImageTrapping(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageToImageTrapping,AttributeType_boolean,false);
	};
/**
* Set attribute ImageToObjectTrapping
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetImageToObjectTrapping(bool value){
	SetAttribute(atr_ImageToObjectTrapping,WString::valueOf(value));
};
/**
* Get bool attribute ImageToObjectTrapping
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoTrappingParams::GetImageToObjectTrapping() const {return GetBoolAttribute(atr_ImageToObjectTrapping,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidImageToObjectTrapping(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageToObjectTrapping,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoTrappingParams::ImageTrapPlacementString(){
		static const WString enums=WString(L"Unknown,Center,Choke,Normal,Spread");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoTrappingParams::ImageTrapPlacementString(EnumImageTrapPlacement value){
		return ImageTrapPlacementString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoTrappingParams::SetImageTrapPlacement( EnumImageTrapPlacement value){
	SetEnumAttribute(atr_ImageTrapPlacement,value,ImageTrapPlacementString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoTrappingParams::EnumImageTrapPlacement JDFAutoTrappingParams:: GetImageTrapPlacement() const {
	return (EnumImageTrapPlacement) GetEnumAttribute(atr_ImageTrapPlacement,ImageTrapPlacementString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidImageTrapPlacement(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ImageTrapPlacement,ImageTrapPlacementString(),false);
	};
/**
* Set attribute ImageTrapWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetImageTrapWidth(double value){
	SetAttribute(atr_ImageTrapWidth,WString::valueOf(value));
};
/**
* Get double attribute ImageTrapWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetImageTrapWidth() const {
	return GetRealAttribute(atr_ImageTrapWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidImageTrapWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageTrapWidth,AttributeType_double,false);
	};
/**
* Set attribute ImageTrapWidthY
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetImageTrapWidthY(double value){
	SetAttribute(atr_ImageTrapWidthY,WString::valueOf(value));
};
/**
* Get double attribute ImageTrapWidthY
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetImageTrapWidthY() const {
	return GetRealAttribute(atr_ImageTrapWidthY,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidImageTrapWidthY(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageTrapWidthY,AttributeType_double,false);
	};
/**
* Set attribute SlidingTrapLimit
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetSlidingTrapLimit(double value){
	SetAttribute(atr_SlidingTrapLimit,WString::valueOf(value));
};
/**
* Get double attribute SlidingTrapLimit
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetSlidingTrapLimit() const {
	return GetRealAttribute(atr_SlidingTrapLimit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidSlidingTrapLimit(EnumValidationLevel level) const {
		return ValidAttribute(atr_SlidingTrapLimit,AttributeType_double,false);
	};
/**
* Set attribute StepLimit
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetStepLimit(double value){
	SetAttribute(atr_StepLimit,WString::valueOf(value));
};
/**
* Get double attribute StepLimit
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetStepLimit() const {
	return GetRealAttribute(atr_StepLimit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidStepLimit(EnumValidationLevel level) const {
		return ValidAttribute(atr_StepLimit,AttributeType_double,false);
	};
/**
* Set attribute TrapColorScaling
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetTrapColorScaling(double value){
	SetAttribute(atr_TrapColorScaling,WString::valueOf(value));
};
/**
* Get double attribute TrapColorScaling
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetTrapColorScaling() const {
	return GetRealAttribute(atr_TrapColorScaling,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidTrapColorScaling(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrapColorScaling,AttributeType_double,false);
	};
/**
* Set attribute TrapWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetTrapWidth(double value){
	SetAttribute(atr_TrapWidth,WString::valueOf(value));
};
/**
* Get double attribute TrapWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetTrapWidth() const {
	return GetRealAttribute(atr_TrapWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidTrapWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrapWidth,AttributeType_double,false);
	};
/**
* Set attribute TrapWidthY
*@param double value: the value to set the attribute to
*/
	 void JDFAutoTrappingParams::SetTrapWidthY(double value){
	SetAttribute(atr_TrapWidthY,WString::valueOf(value));
};
/**
* Get double attribute TrapWidthY
* @return double the vaue of the attribute 
*/
	 double JDFAutoTrappingParams::GetTrapWidthY() const {
	return GetRealAttribute(atr_TrapWidthY,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingParams::ValidTrapWidthY(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrapWidthY,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColorantZoneDetails JDFAutoTrappingParams::GetColorantZoneDetails(int iSkip)const{
	JDFColorantZoneDetails e=GetElement(elm_ColorantZoneDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorantZoneDetails JDFAutoTrappingParams::GetCreateColorantZoneDetails(int iSkip){
	JDFColorantZoneDetails e=GetCreateElement(elm_ColorantZoneDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorantZoneDetails JDFAutoTrappingParams::AppendColorantZoneDetails(){
	JDFColorantZoneDetails e=AppendElement(elm_ColorantZoneDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoTrappingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorantZoneDetails);

		for(i=0;i<nElem;i++){
			if (!GetColorantZoneDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorantZoneDetails);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoTrappingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorantZoneDetails";
	};
}; // end namespace JDF
