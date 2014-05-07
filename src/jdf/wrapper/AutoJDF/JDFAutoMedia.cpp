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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMedia.h"
#include "jdf/wrapper/JDFColor.h"
#include "jdf/wrapper/JDFColorMeasurementConditions.h"
#include "jdf/wrapper/JDFMediaLayers.h"
#include "jdf/wrapper/JDFHoleList.h"
#include "jdf/wrapper/JDFTabDimensions.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMedia : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMedia& JDFAutoMedia::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMedia: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMedia::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMedia::ValidNodeNames()const{
	return L"*:,Media";
};

bool JDFAutoMedia::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Consumable;
};

bool JDFAutoMedia::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Consumable);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMedia::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",HoleType,MediaUnit,PrePrinted,BackBrightness,BackCoatingDetail,BackCoatings,BackGlossValue,Brightness,CIETint,CIEWhiteness,ColorName,CoreWeight,Dimension,Flute,FluteDirection,FrontCoatingDetail,FrontCoatings,FrontGlossValue,Grade")
	+WString(L",GrainDirection,HoleCount,ImagableSide,InsideLoss,ISOPaperSubstrate,LabColorValue,MediaColorName,MediaColorNameDetails,MediaQuality,MediaSetCount,MediaType,MediaTypeDetails,Opacity,OpacityLevel,OuterCoreDiameter,OutsideGain,PlateTechnology,Polarity,PrintingTechnology")
	+WString(L",Recycled,RecycledPercentage,ReliefThickness,RollDiameter,ShrinkIndex,SleeveInterlock,StockType,Texture,Thickness,UserMediaType,Weight,WrapperWeight");
};

/**
 typesafe validator
*/
	vWString JDFAutoMedia::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidHoleType(level)) {
			vAtts.push_back(atr_HoleType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaUnit(level)) {
			vAtts.push_back(atr_MediaUnit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrePrinted(level)) {
			vAtts.push_back(atr_PrePrinted);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBackBrightness(level)) {
			vAtts.push_back(atr_BackBrightness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBackCoatingDetail(level)) {
			vAtts.push_back(atr_BackCoatingDetail);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBackCoatings(level)) {
			vAtts.push_back(atr_BackCoatings);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBackGlossValue(level)) {
			vAtts.push_back(atr_BackGlossValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBrightness(level)) {
			vAtts.push_back(atr_Brightness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCIETint(level)) {
			vAtts.push_back(atr_CIETint);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCIEWhiteness(level)) {
			vAtts.push_back(atr_CIEWhiteness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorName(level)) {
			vAtts.push_back(atr_ColorName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCoreWeight(level)) {
			vAtts.push_back(atr_CoreWeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDimension(level)) {
			vAtts.push_back(atr_Dimension);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFlute(level)) {
			vAtts.push_back(atr_Flute);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFluteDirection(level)) {
			vAtts.push_back(atr_FluteDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontCoatingDetail(level)) {
			vAtts.push_back(atr_FrontCoatingDetail);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontCoatings(level)) {
			vAtts.push_back(atr_FrontCoatings);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontGlossValue(level)) {
			vAtts.push_back(atr_FrontGlossValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGrade(level)) {
			vAtts.push_back(atr_Grade);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGrainDirection(level)) {
			vAtts.push_back(atr_GrainDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHoleCount(level)) {
			vAtts.push_back(atr_HoleCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImagableSide(level)) {
			vAtts.push_back(atr_ImagableSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInsideLoss(level)) {
			vAtts.push_back(atr_InsideLoss);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidISOPaperSubstrate(level)) {
			vAtts.push_back(atr_ISOPaperSubstrate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLabColorValue(level)) {
			vAtts.push_back(atr_LabColorValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaColorName(level)) {
			vAtts.push_back(atr_MediaColorName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaColorNameDetails(level)) {
			vAtts.push_back(atr_MediaColorNameDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaQuality(level)) {
			vAtts.push_back(atr_MediaQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaSetCount(level)) {
			vAtts.push_back(atr_MediaSetCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaType(level)) {
			vAtts.push_back(atr_MediaType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaTypeDetails(level)) {
			vAtts.push_back(atr_MediaTypeDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOpacity(level)) {
			vAtts.push_back(atr_Opacity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOpacityLevel(level)) {
			vAtts.push_back(atr_OpacityLevel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOuterCoreDiameter(level)) {
			vAtts.push_back(atr_OuterCoreDiameter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutsideGain(level)) {
			vAtts.push_back(atr_OutsideGain);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPlateTechnology(level)) {
			vAtts.push_back(atr_PlateTechnology);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPolarity(level)) {
			vAtts.push_back(atr_Polarity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrintingTechnology(level)) {
			vAtts.push_back(atr_PrintingTechnology);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRecycled(level)) {
			vAtts.push_back(atr_Recycled);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRecycledPercentage(level)) {
			vAtts.push_back(atr_RecycledPercentage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReliefThickness(level)) {
			vAtts.push_back(atr_ReliefThickness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRollDiameter(level)) {
			vAtts.push_back(atr_RollDiameter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShrinkIndex(level)) {
			vAtts.push_back(atr_ShrinkIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSleeveInterlock(level)) {
			vAtts.push_back(atr_SleeveInterlock);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStockType(level)) {
			vAtts.push_back(atr_StockType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTexture(level)) {
			vAtts.push_back(atr_Texture);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThickness(level)) {
			vAtts.push_back(atr_Thickness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUserMediaType(level)) {
			vAtts.push_back(atr_UserMediaType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWeight(level)) {
			vAtts.push_back(atr_Weight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWrapperWeight(level)) {
			vAtts.push_back(atr_WrapperWeight);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::HoleTypeString(){
		static const WString enums=WString(L"Unknown,None,S1-generic,S-generic,R2-generic,R2m-DIN,R2m-ISO,R2m-MIB,R2i-US-a,R2i-US-b")
	+WString(L",R3-generic,R3i-US,R4-generic,R4m-DIN-A4,R4m-DIN-A5,R4m-swedish,R4i-US,R5-generic,R5i-US-a,R5i-US-b")
	+WString(L",R5i-US-c,R6-generic,R6m-4h2s,R6m-DIN-A5,R7-generic,R7i-US-a,R7i-US-b,R7i-US-c,R11m-7h4s,P16_9i-rect-0t")
	+WString(L",P12m-rect-0t,W2_1i-round-0t,W2_1i-square-0t,W3_1i-square-0t,C9.5m-round-0t,Explicit");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::HoleTypeString(EnumHoleType value){
		return HoleTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoMedia::AddHoleType( EnumHoleType value){
	return AddEnumerationsAttribute(atr_HoleType,value,HoleTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoMedia::RemoveHoleType( EnumHoleType value){
	return RemoveEnumerationsAttribute(atr_HoleType,value,HoleTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoMedia::GetHoleType() const {
	return GetEnumerationsAttribute(atr_HoleType,HoleTypeString(),WString::emptyStr,(unsigned int)HoleType_None);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetHoleType( EnumHoleType value){
	SetEnumAttribute(atr_HoleType,value,HoleTypeString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetHoleType( const vint& value){
	SetEnumerationsAttribute(atr_HoleType,value,HoleTypeString());
};
/**
* Typesafe attribute validation of HoleType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidHoleType(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_HoleType,HoleTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::MediaUnitString(){
		static const WString enums=WString(L"Unknown,Continuous,Roll,Sheet");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::MediaUnitString(EnumMediaUnit value){
		return MediaUnitString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetMediaUnit( EnumMediaUnit value){
	SetEnumAttribute(atr_MediaUnit,value,MediaUnitString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumMediaUnit JDFAutoMedia:: GetMediaUnit() const {
	return (EnumMediaUnit) GetEnumAttribute(atr_MediaUnit,MediaUnitString(),WString::emptyStr,MediaUnit_Sheet);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidMediaUnit(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MediaUnit,MediaUnitString(),false);
	};
/**
* Set attribute PrePrinted
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetPrePrinted(bool value){
	SetAttribute(atr_PrePrinted,WString::valueOf(value));
};
/**
* Get bool attribute PrePrinted
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMedia::GetPrePrinted() const {return GetBoolAttribute(atr_PrePrinted,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidPrePrinted(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrePrinted,AttributeType_boolean,false);
	};
/**
* Set attribute BackBrightness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetBackBrightness(double value){
	SetAttribute(atr_BackBrightness,WString::valueOf(value));
};
/**
* Get double attribute BackBrightness
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetBackBrightness() const {
	return GetRealAttribute(atr_BackBrightness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidBackBrightness(EnumValidationLevel level) const {
		return ValidAttribute(atr_BackBrightness,AttributeType_double,false);
	};
/**
* Set attribute BackCoatingDetail
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetBackCoatingDetail(const WString& value){
	SetAttribute(atr_BackCoatingDetail,value);
};
/**
* Get string attribute BackCoatingDetail
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetBackCoatingDetail() const {
	return GetAttribute(atr_BackCoatingDetail,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidBackCoatingDetail(EnumValidationLevel level) const {
		return ValidAttribute(atr_BackCoatingDetail,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::BackCoatingsString(){
		static const WString enums=WString(L"Unknown,None,Coated,Glossy,HighGloss,InkJet,Matte,Polymer,Silver,Satin")
	+WString(L",Semigloss");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::BackCoatingsString(EnumBackCoatings value){
		return BackCoatingsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetBackCoatings( EnumBackCoatings value){
	SetEnumAttribute(atr_BackCoatings,value,BackCoatingsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumBackCoatings JDFAutoMedia:: GetBackCoatings() const {
	return (EnumBackCoatings) GetEnumAttribute(atr_BackCoatings,BackCoatingsString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidBackCoatings(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BackCoatings,BackCoatingsString(),false);
	};
/**
* Set attribute BackGlossValue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetBackGlossValue(double value){
	SetAttribute(atr_BackGlossValue,WString::valueOf(value));
};
/**
* Get double attribute BackGlossValue
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetBackGlossValue() const {
	return GetRealAttribute(atr_BackGlossValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidBackGlossValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_BackGlossValue,AttributeType_double,false);
	};
/**
* Set attribute Brightness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetBrightness(double value){
	SetAttribute(atr_Brightness,WString::valueOf(value));
};
/**
* Get double attribute Brightness
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetBrightness() const {
	return GetRealAttribute(atr_Brightness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidBrightness(EnumValidationLevel level) const {
		return ValidAttribute(atr_Brightness,AttributeType_double,false);
	};
/**
* Set attribute CIETint
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetCIETint(double value){
	SetAttribute(atr_CIETint,WString::valueOf(value));
};
/**
* Get double attribute CIETint
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetCIETint() const {
	return GetRealAttribute(atr_CIETint,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidCIETint(EnumValidationLevel level) const {
		return ValidAttribute(atr_CIETint,AttributeType_double,false);
	};
/**
* Set attribute CIEWhiteness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetCIEWhiteness(double value){
	SetAttribute(atr_CIEWhiteness,WString::valueOf(value));
};
/**
* Get double attribute CIEWhiteness
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetCIEWhiteness() const {
	return GetRealAttribute(atr_CIEWhiteness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidCIEWhiteness(EnumValidationLevel level) const {
		return ValidAttribute(atr_CIEWhiteness,AttributeType_double,false);
	};
/**
* Set attribute ColorName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetColorName(const WString& value){
	SetAttribute(atr_ColorName,value);
};
/**
* Get string attribute ColorName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetColorName() const {
	return GetAttribute(atr_ColorName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidColorName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorName,AttributeType_string,false);
	};
/**
* Set attribute CoreWeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetCoreWeight(double value){
	SetAttribute(atr_CoreWeight,WString::valueOf(value));
};
/**
* Get double attribute CoreWeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetCoreWeight() const {
	return GetRealAttribute(atr_CoreWeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidCoreWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_CoreWeight,AttributeType_double,false);
	};
/**
* Set attribute Dimension
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetDimension(const JDFXYPair& value){
	SetAttribute(atr_Dimension,value);
};
/**
* Get string attribute Dimension
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoMedia::GetDimension() const {
	return GetAttribute(atr_Dimension,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidDimension(EnumValidationLevel level) const {
		return ValidAttribute(atr_Dimension,AttributeType_XYPair,false);
	};
/**
* Set attribute Flute
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetFlute(const WString& value){
	SetAttribute(atr_Flute,value);
};
/**
* Get string attribute Flute
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetFlute() const {
	return GetAttribute(atr_Flute,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidFlute(EnumValidationLevel level) const {
		return ValidAttribute(atr_Flute,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::FluteDirectionString(){
		static const WString enums=WString(L"Unknown,LongEdge,ShortEdge,XDirection,YDirection");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::FluteDirectionString(EnumFluteDirection value){
		return FluteDirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetFluteDirection( EnumFluteDirection value){
	SetEnumAttribute(atr_FluteDirection,value,FluteDirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumFluteDirection JDFAutoMedia:: GetFluteDirection() const {
	return (EnumFluteDirection) GetEnumAttribute(atr_FluteDirection,FluteDirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidFluteDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FluteDirection,FluteDirectionString(),false);
	};
/**
* Set attribute FrontCoatingDetail
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetFrontCoatingDetail(const WString& value){
	SetAttribute(atr_FrontCoatingDetail,value);
};
/**
* Get string attribute FrontCoatingDetail
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetFrontCoatingDetail() const {
	return GetAttribute(atr_FrontCoatingDetail,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidFrontCoatingDetail(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrontCoatingDetail,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::FrontCoatingsString(){
		static const WString enums=WString(L"Unknown,None,Coated,Glossy,HighGloss,InkJet,Matte,Polymer,Silver,Satin")
	+WString(L",Semigloss");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::FrontCoatingsString(EnumFrontCoatings value){
		return FrontCoatingsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetFrontCoatings( EnumFrontCoatings value){
	SetEnumAttribute(atr_FrontCoatings,value,FrontCoatingsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumFrontCoatings JDFAutoMedia:: GetFrontCoatings() const {
	return (EnumFrontCoatings) GetEnumAttribute(atr_FrontCoatings,FrontCoatingsString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidFrontCoatings(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FrontCoatings,FrontCoatingsString(),false);
	};
/**
* Set attribute FrontGlossValue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetFrontGlossValue(double value){
	SetAttribute(atr_FrontGlossValue,WString::valueOf(value));
};
/**
* Get double attribute FrontGlossValue
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetFrontGlossValue() const {
	return GetRealAttribute(atr_FrontGlossValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidFrontGlossValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrontGlossValue,AttributeType_double,false);
	};
/**
* Set attribute Grade
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetGrade(int value){
	SetAttribute(atr_Grade,WString::valueOf(value));
};
/**
* Get integer attribute Grade
* @return int the vaue of the attribute 
*/
	 int JDFAutoMedia::GetGrade() const {
	return GetIntAttribute(atr_Grade,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidGrade(EnumValidationLevel level) const {
		return ValidAttribute(atr_Grade,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::GrainDirectionString(){
		static const WString enums=WString(L"Unknown,LongEdge,ShortEdge,XDirection,YDirection");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::GrainDirectionString(EnumGrainDirection value){
		return GrainDirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetGrainDirection( EnumGrainDirection value){
	SetEnumAttribute(atr_GrainDirection,value,GrainDirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumGrainDirection JDFAutoMedia:: GetGrainDirection() const {
	return (EnumGrainDirection) GetEnumAttribute(atr_GrainDirection,GrainDirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidGrainDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_GrainDirection,GrainDirectionString(),false);
	};
/**
* Set attribute HoleCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetHoleCount(int value){
	SetAttribute(atr_HoleCount,WString::valueOf(value));
};
/**
* Get integer attribute HoleCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoMedia::GetHoleCount() const {
	return GetIntAttribute(atr_HoleCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidHoleCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_HoleCount,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::ImagableSideString(){
		static const WString enums=WString(L"Unknown,Front,Back,Both,Neither");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::ImagableSideString(EnumImagableSide value){
		return ImagableSideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetImagableSide( EnumImagableSide value){
	SetEnumAttribute(atr_ImagableSide,value,ImagableSideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumImagableSide JDFAutoMedia:: GetImagableSide() const {
	return (EnumImagableSide) GetEnumAttribute(atr_ImagableSide,ImagableSideString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidImagableSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ImagableSide,ImagableSideString(),false);
	};
/**
* Set attribute InsideLoss
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetInsideLoss(double value){
	SetAttribute(atr_InsideLoss,WString::valueOf(value));
};
/**
* Get double attribute InsideLoss
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetInsideLoss() const {
	return GetRealAttribute(atr_InsideLoss,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidInsideLoss(EnumValidationLevel level) const {
		return ValidAttribute(atr_InsideLoss,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::ISOPaperSubstrateString(){
		static const WString enums=WString(L"Unknown,PS1,PS2,PS3,PS4,PS5,PS6,PS7,PS8");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::ISOPaperSubstrateString(EnumISOPaperSubstrate value){
		return ISOPaperSubstrateString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetISOPaperSubstrate( EnumISOPaperSubstrate value){
	SetEnumAttribute(atr_ISOPaperSubstrate,value,ISOPaperSubstrateString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumISOPaperSubstrate JDFAutoMedia:: GetISOPaperSubstrate() const {
	return (EnumISOPaperSubstrate) GetEnumAttribute(atr_ISOPaperSubstrate,ISOPaperSubstrateString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidISOPaperSubstrate(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ISOPaperSubstrate,ISOPaperSubstrateString(),false);
	};
/**
* Set attribute LabColorValue
*@param JDFLabColor value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetLabColorValue(const JDFLabColor& value){
	SetAttribute(atr_LabColorValue,value);
};
/**
* Get string attribute LabColorValue
* @return JDFLabColor the vaue of the attribute 
*/
	 JDFLabColor JDFAutoMedia::GetLabColorValue() const {
	return GetAttribute(atr_LabColorValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidLabColorValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_LabColorValue,AttributeType_LabColor,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetMediaColorName( EnumNamedColor value){
	SetEnumAttribute(atr_MediaColorName,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumNamedColor JDFAutoMedia:: GetMediaColorName() const {
	return (EnumNamedColor) GetEnumAttribute(atr_MediaColorName,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidMediaColorName(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MediaColorName,NamedColorString(),false);
	};
/**
* Set attribute MediaColorNameDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetMediaColorNameDetails(const WString& value){
	SetAttribute(atr_MediaColorNameDetails,value);
};
/**
* Get string attribute MediaColorNameDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetMediaColorNameDetails() const {
	return GetAttribute(atr_MediaColorNameDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidMediaColorNameDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaColorNameDetails,AttributeType_string,false);
	};
/**
* Set attribute MediaQuality
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetMediaQuality(const WString& value){
	SetAttribute(atr_MediaQuality,value);
};
/**
* Get string attribute MediaQuality
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetMediaQuality() const {
	return GetAttribute(atr_MediaQuality,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidMediaQuality(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaQuality,AttributeType_string,false);
	};
/**
* Set attribute MediaSetCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetMediaSetCount(int value){
	SetAttribute(atr_MediaSetCount,WString::valueOf(value));
};
/**
* Get integer attribute MediaSetCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoMedia::GetMediaSetCount() const {
	return GetIntAttribute(atr_MediaSetCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidMediaSetCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaSetCount,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::MediaTypeString(){
		static const WString enums=WString(L"Unknown,CorrugatedBoard,Disc,EndBoard,EmbossingFoil,Film,Foil,GravureCylinder,ImagingCylinder,LaminatingFoil")
	+WString(L",MountingTape,Other,Paper,Plate,SelfAdhesive,Sleeve,ShrinkFoil,Transparency");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::MediaTypeString(EnumMediaType value){
		return MediaTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetMediaType( EnumMediaType value){
	SetEnumAttribute(atr_MediaType,value,MediaTypeString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumMediaType JDFAutoMedia:: GetMediaType() const {
	return (EnumMediaType) GetEnumAttribute(atr_MediaType,MediaTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidMediaType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MediaType,MediaTypeString(),false,WString::emptyStr,true);
	};
/**
* Set attribute MediaTypeDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetMediaTypeDetails(const WString& value){
	SetAttribute(atr_MediaTypeDetails,value);
};
/**
* Get string attribute MediaTypeDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetMediaTypeDetails() const {
	return GetAttribute(atr_MediaTypeDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidMediaTypeDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaTypeDetails,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::OpacityString(){
		static const WString enums=WString(L"Unknown,Opaque,Translucent,Transparent");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::OpacityString(EnumOpacity value){
		return OpacityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetOpacity( EnumOpacity value){
	SetEnumAttribute(atr_Opacity,value,OpacityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumOpacity JDFAutoMedia:: GetOpacity() const {
	return (EnumOpacity) GetEnumAttribute(atr_Opacity,OpacityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidOpacity(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Opacity,OpacityString(),false);
	};
/**
* Set attribute OpacityLevel
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetOpacityLevel(double value){
	SetAttribute(atr_OpacityLevel,WString::valueOf(value));
};
/**
* Get double attribute OpacityLevel
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetOpacityLevel() const {
	return GetRealAttribute(atr_OpacityLevel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidOpacityLevel(EnumValidationLevel level) const {
		return ValidAttribute(atr_OpacityLevel,AttributeType_double,false);
	};
/**
* Set attribute OuterCoreDiameter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetOuterCoreDiameter(double value){
	SetAttribute(atr_OuterCoreDiameter,WString::valueOf(value));
};
/**
* Get double attribute OuterCoreDiameter
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetOuterCoreDiameter() const {
	return GetRealAttribute(atr_OuterCoreDiameter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidOuterCoreDiameter(EnumValidationLevel level) const {
		return ValidAttribute(atr_OuterCoreDiameter,AttributeType_double,false);
	};
/**
* Set attribute OutsideGain
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetOutsideGain(double value){
	SetAttribute(atr_OutsideGain,WString::valueOf(value));
};
/**
* Get double attribute OutsideGain
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetOutsideGain() const {
	return GetRealAttribute(atr_OutsideGain,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidOutsideGain(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutsideGain,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::PlateTechnologyString(){
		static const WString enums=WString(L"Unknown,FlexoAnalogSolvent,FlexoAnalogThermal,FlexoDigitalSolvent,FlexoDigitalThermal,FlexoDirectEngraving,InkJet,Thermal,UV,Visible");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::PlateTechnologyString(EnumPlateTechnology value){
		return PlateTechnologyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetPlateTechnology( EnumPlateTechnology value){
	SetEnumAttribute(atr_PlateTechnology,value,PlateTechnologyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumPlateTechnology JDFAutoMedia:: GetPlateTechnology() const {
	return (EnumPlateTechnology) GetEnumAttribute(atr_PlateTechnology,PlateTechnologyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidPlateTechnology(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PlateTechnology,PlateTechnologyString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMedia::PolarityString(){
		static const WString enums=WString(L"Unknown,Positive,Negative");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMedia::PolarityString(EnumPolarity value){
		return PolarityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMedia::SetPolarity( EnumPolarity value){
	SetEnumAttribute(atr_Polarity,value,PolarityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMedia::EnumPolarity JDFAutoMedia:: GetPolarity() const {
	return (EnumPolarity) GetEnumAttribute(atr_Polarity,PolarityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidPolarity(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Polarity,PolarityString(),false);
	};
/**
* Set attribute PrintingTechnology
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetPrintingTechnology(const WString& value){
	SetAttribute(atr_PrintingTechnology,value);
};
/**
* Get string attribute PrintingTechnology
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetPrintingTechnology() const {
	return GetAttribute(atr_PrintingTechnology,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidPrintingTechnology(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrintingTechnology,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Recycled
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetRecycled(bool value){
	SetAttribute(atr_Recycled,WString::valueOf(value));
};
/**
* Get bool attribute Recycled
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoMedia::GetRecycled() const {return GetBoolAttribute(atr_Recycled,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidRecycled(EnumValidationLevel level) const {
		return ValidAttribute(atr_Recycled,AttributeType_boolean,false);
	};
/**
* Set attribute RecycledPercentage
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetRecycledPercentage(double value){
	SetAttribute(atr_RecycledPercentage,WString::valueOf(value));
};
/**
* Get double attribute RecycledPercentage
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetRecycledPercentage() const {
	return GetRealAttribute(atr_RecycledPercentage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidRecycledPercentage(EnumValidationLevel level) const {
		return ValidAttribute(atr_RecycledPercentage,AttributeType_double,false);
	};
/**
* Set attribute ReliefThickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetReliefThickness(double value){
	SetAttribute(atr_ReliefThickness,WString::valueOf(value));
};
/**
* Get double attribute ReliefThickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetReliefThickness() const {
	return GetRealAttribute(atr_ReliefThickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidReliefThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReliefThickness,AttributeType_double,false);
	};
/**
* Set attribute RollDiameter
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetRollDiameter(double value){
	SetAttribute(atr_RollDiameter,WString::valueOf(value));
};
/**
* Get double attribute RollDiameter
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetRollDiameter() const {
	return GetRealAttribute(atr_RollDiameter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidRollDiameter(EnumValidationLevel level) const {
		return ValidAttribute(atr_RollDiameter,AttributeType_double,false);
	};
/**
* Set attribute ShrinkIndex
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetShrinkIndex(const JDFXYPair& value){
	SetAttribute(atr_ShrinkIndex,value);
};
/**
* Get string attribute ShrinkIndex
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoMedia::GetShrinkIndex() const {
	return GetAttribute(atr_ShrinkIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidShrinkIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShrinkIndex,AttributeType_XYPair,false);
	};
/**
* Set attribute SleeveInterlock
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetSleeveInterlock(const WString& value){
	SetAttribute(atr_SleeveInterlock,value);
};
/**
* Get string attribute SleeveInterlock
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetSleeveInterlock() const {
	return GetAttribute(atr_SleeveInterlock,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidSleeveInterlock(EnumValidationLevel level) const {
		return ValidAttribute(atr_SleeveInterlock,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute StockType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetStockType(const WString& value){
	SetAttribute(atr_StockType,value);
};
/**
* Get string attribute StockType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetStockType() const {
	return GetAttribute(atr_StockType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidStockType(EnumValidationLevel level) const {
		return ValidAttribute(atr_StockType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Texture
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetTexture(const WString& value){
	SetAttribute(atr_Texture,value);
};
/**
* Get string attribute Texture
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetTexture() const {
	return GetAttribute(atr_Texture,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidTexture(EnumValidationLevel level) const {
		return ValidAttribute(atr_Texture,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Thickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetThickness(double value){
	SetAttribute(atr_Thickness,WString::valueOf(value));
};
/**
* Get double attribute Thickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetThickness() const {
	return GetRealAttribute(atr_Thickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_Thickness,AttributeType_double,false);
	};
/**
* Set attribute UserMediaType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetUserMediaType(const WString& value){
	SetAttribute(atr_UserMediaType,value);
};
/**
* Get string attribute UserMediaType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMedia::GetUserMediaType() const {
	return GetAttribute(atr_UserMediaType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidUserMediaType(EnumValidationLevel level) const {
		return ValidAttribute(atr_UserMediaType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Weight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetWeight(double value){
	SetAttribute(atr_Weight,WString::valueOf(value));
};
/**
* Get double attribute Weight
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetWeight() const {
	return GetRealAttribute(atr_Weight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_Weight,AttributeType_double,false);
	};
/**
* Set attribute WrapperWeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMedia::SetWrapperWeight(double value){
	SetAttribute(atr_WrapperWeight,WString::valueOf(value));
};
/**
* Get double attribute WrapperWeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoMedia::GetWrapperWeight() const {
	return GetRealAttribute(atr_WrapperWeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMedia::ValidWrapperWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_WrapperWeight,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColor JDFAutoMedia::GetColor()const{
	JDFColor e=GetElement(elm_Color);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColor JDFAutoMedia::GetCreateColor(){
	JDFColor e=GetCreateElement(elm_Color);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColor JDFAutoMedia::AppendColor(){
	JDFColor e=AppendElementN(elm_Color,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMedia::RefColor(JDFColor& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoMedia::GetColorMeasurementConditions()const{
	JDFColorMeasurementConditions e=GetElement(elm_ColorMeasurementConditions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoMedia::GetCreateColorMeasurementConditions(){
	JDFColorMeasurementConditions e=GetCreateElement(elm_ColorMeasurementConditions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoMedia::AppendColorMeasurementConditions(){
	JDFColorMeasurementConditions e=AppendElementN(elm_ColorMeasurementConditions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMedia::RefColorMeasurementConditions(JDFColorMeasurementConditions& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMediaLayers JDFAutoMedia::GetMediaLayers()const{
	JDFMediaLayers e=GetElement(elm_MediaLayers);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaLayers JDFAutoMedia::GetCreateMediaLayers(){
	JDFMediaLayers e=GetCreateElement(elm_MediaLayers);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaLayers JDFAutoMedia::AppendMediaLayers(){
	JDFMediaLayers e=AppendElementN(elm_MediaLayers,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoMedia::GetHoleList()const{
	JDFHoleList e=GetElement(elm_HoleList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoMedia::GetCreateHoleList(){
	JDFHoleList e=GetCreateElement(elm_HoleList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoMedia::AppendHoleList(){
	JDFHoleList e=AppendElementN(elm_HoleList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMedia::RefHoleList(JDFHoleList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFTabDimensions JDFAutoMedia::GetTabDimensions(int iSkip)const{
	JDFTabDimensions e=GetElement(elm_TabDimensions,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTabDimensions JDFAutoMedia::GetCreateTabDimensions(int iSkip){
	JDFTabDimensions e=GetCreateElement(elm_TabDimensions,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTabDimensions JDFAutoMedia::AppendTabDimensions(){
	JDFTabDimensions e=AppendElement(elm_TabDimensions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoMedia::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Color);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Color);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColor().IsValid(level)) {
				vElem.AppendUnique(elm_Color);
				if (++n>=nMax)
					return vElem;
			}
		}
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
		nElem=NumChildElements(elm_MediaLayers);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaLayers);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaLayers().IsValid(level)) {
				vElem.AppendUnique(elm_MediaLayers);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_HoleList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_HoleList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetHoleList().IsValid(level)) {
				vElem.AppendUnique(elm_HoleList);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_TabDimensions);

		for(i=0;i<nElem;i++){
			if (!GetTabDimensions(i).IsValid(level)) {
				vElem.AppendUnique(elm_TabDimensions);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoMedia::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Color,ColorMeasurementConditions,MediaLayers,HoleList";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoMedia::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Color,ColorMeasurementConditions,MediaLayers,HoleList,TabDimensions";
	};
}; // end namespace JDF
