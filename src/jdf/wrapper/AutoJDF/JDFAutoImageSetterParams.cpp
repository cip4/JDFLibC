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

 
#include "jdf/wrapper/AutoJDF/JDFAutoImageSetterParams.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFFitPolicy.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoImageSetterParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoImageSetterParams& JDFAutoImageSetterParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoImageSetterParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoImageSetterParams::ValidNodeNames()const{
	return L"*:,ImageSetterParams";
};

bool JDFAutoImageSetterParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoImageSetterParams::init(){
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
	WString JDFAutoImageSetterParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",MirrorAround,Polarity,Sides,AdvanceDistance,BurnOutArea,CenterAcross,CutMedia,ManualFeed,NonPrintableMarginBottom,NonPrintableMarginLeft,NonPrintableMarginRight,NonPrintableMarginTop,Punch,PunchType,Resolution,RollCut,SourceWorkStyle,TransferCurve");
};

/**
 typesafe validator
*/
	vWString JDFAutoImageSetterParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMirrorAround(level)) {
			vAtts.push_back(atr_MirrorAround);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPolarity(level)) {
			vAtts.push_back(atr_Polarity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSides(level)) {
			vAtts.push_back(atr_Sides);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdvanceDistance(level)) {
			vAtts.push_back(atr_AdvanceDistance);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBurnOutArea(level)) {
			vAtts.push_back(atr_BurnOutArea);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCenterAcross(level)) {
			vAtts.push_back(atr_CenterAcross);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutMedia(level)) {
			vAtts.push_back(atr_CutMedia);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidManualFeed(level)) {
			vAtts.push_back(atr_ManualFeed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNonPrintableMarginBottom(level)) {
			vAtts.push_back(atr_NonPrintableMarginBottom);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNonPrintableMarginLeft(level)) {
			vAtts.push_back(atr_NonPrintableMarginLeft);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNonPrintableMarginRight(level)) {
			vAtts.push_back(atr_NonPrintableMarginRight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNonPrintableMarginTop(level)) {
			vAtts.push_back(atr_NonPrintableMarginTop);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPunch(level)) {
			vAtts.push_back(atr_Punch);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPunchType(level)) {
			vAtts.push_back(atr_PunchType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResolution(level)) {
			vAtts.push_back(atr_Resolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRollCut(level)) {
			vAtts.push_back(atr_RollCut);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceWorkStyle(level)) {
			vAtts.push_back(atr_SourceWorkStyle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransferCurve(level)) {
			vAtts.push_back(atr_TransferCurve);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageSetterParams::MirrorAroundString(){
		static const WString enums=WString(L"Unknown,None,FeedDirection,MediaWidth,Both");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageSetterParams::MirrorAroundString(EnumMirrorAround value){
		return MirrorAroundString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageSetterParams::SetMirrorAround( EnumMirrorAround value){
	SetEnumAttribute(atr_MirrorAround,value,MirrorAroundString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageSetterParams::EnumMirrorAround JDFAutoImageSetterParams:: GetMirrorAround() const {
	return (EnumMirrorAround) GetEnumAttribute(atr_MirrorAround,MirrorAroundString(),WString::emptyStr,MirrorAround_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidMirrorAround(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MirrorAround,MirrorAroundString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageSetterParams::PolarityString(){
		static const WString enums=WString(L"Unknown,Positive,Negative");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageSetterParams::PolarityString(EnumPolarity value){
		return PolarityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageSetterParams::SetPolarity( EnumPolarity value){
	SetEnumAttribute(atr_Polarity,value,PolarityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageSetterParams::EnumPolarity JDFAutoImageSetterParams:: GetPolarity() const {
	return (EnumPolarity) GetEnumAttribute(atr_Polarity,PolarityString(),WString::emptyStr,Polarity_Positive);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidPolarity(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Polarity,PolarityString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageSetterParams::SidesString(){
		static const WString enums=WString(L"Unknown,OneSidedBackFlipX,OneSidedBackFlipY,OneSidedFront,TwoSidedFlipX,TwoSidedFlipY");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageSetterParams::SidesString(EnumSides value){
		return SidesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageSetterParams::SetSides( EnumSides value){
	SetEnumAttribute(atr_Sides,value,SidesString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageSetterParams::EnumSides JDFAutoImageSetterParams:: GetSides() const {
	return (EnumSides) GetEnumAttribute(atr_Sides,SidesString(),WString::emptyStr,Sides_OneSidedFront);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidSides(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Sides,SidesString(),false);
	};
/**
* Set attribute AdvanceDistance
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetAdvanceDistance(double value){
	SetAttribute(atr_AdvanceDistance,WString::valueOf(value));
};
/**
* Get double attribute AdvanceDistance
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageSetterParams::GetAdvanceDistance() const {
	return GetRealAttribute(atr_AdvanceDistance,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidAdvanceDistance(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdvanceDistance,AttributeType_double,false);
	};
/**
* Set attribute BurnOutArea
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetBurnOutArea(const JDFXYPair& value){
	SetAttribute(atr_BurnOutArea,value);
};
/**
* Get string attribute BurnOutArea
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoImageSetterParams::GetBurnOutArea() const {
	return GetAttribute(atr_BurnOutArea,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidBurnOutArea(EnumValidationLevel level) const {
		return ValidAttribute(atr_BurnOutArea,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageSetterParams::CenterAcrossString(){
		static const WString enums=WString(L"Unknown,None,FeedDirection,MediaWidth,Both");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageSetterParams::CenterAcrossString(EnumCenterAcross value){
		return CenterAcrossString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageSetterParams::SetCenterAcross( EnumCenterAcross value){
	SetEnumAttribute(atr_CenterAcross,value,CenterAcrossString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageSetterParams::EnumCenterAcross JDFAutoImageSetterParams:: GetCenterAcross() const {
	return (EnumCenterAcross) GetEnumAttribute(atr_CenterAcross,CenterAcrossString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidCenterAcross(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CenterAcross,CenterAcrossString(),false);
	};
/**
* Set attribute CutMedia
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetCutMedia(bool value){
	SetAttribute(atr_CutMedia,WString::valueOf(value));
};
/**
* Get bool attribute CutMedia
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoImageSetterParams::GetCutMedia() const {return GetBoolAttribute(atr_CutMedia,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidCutMedia(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutMedia,AttributeType_boolean,false);
	};
/**
* Set attribute ManualFeed
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetManualFeed(bool value){
	SetAttribute(atr_ManualFeed,WString::valueOf(value));
};
/**
* Get bool attribute ManualFeed
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoImageSetterParams::GetManualFeed() const {return GetBoolAttribute(atr_ManualFeed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidManualFeed(EnumValidationLevel level) const {
		return ValidAttribute(atr_ManualFeed,AttributeType_boolean,false);
	};
/**
* Set attribute NonPrintableMarginBottom
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetNonPrintableMarginBottom(double value){
	SetAttribute(atr_NonPrintableMarginBottom,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginBottom
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageSetterParams::GetNonPrintableMarginBottom() const {
	return GetRealAttribute(atr_NonPrintableMarginBottom,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidNonPrintableMarginBottom(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginBottom,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginLeft
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetNonPrintableMarginLeft(double value){
	SetAttribute(atr_NonPrintableMarginLeft,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginLeft
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageSetterParams::GetNonPrintableMarginLeft() const {
	return GetRealAttribute(atr_NonPrintableMarginLeft,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidNonPrintableMarginLeft(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginLeft,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginRight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetNonPrintableMarginRight(double value){
	SetAttribute(atr_NonPrintableMarginRight,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginRight
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageSetterParams::GetNonPrintableMarginRight() const {
	return GetRealAttribute(atr_NonPrintableMarginRight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidNonPrintableMarginRight(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginRight,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginTop
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetNonPrintableMarginTop(double value){
	SetAttribute(atr_NonPrintableMarginTop,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginTop
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageSetterParams::GetNonPrintableMarginTop() const {
	return GetRealAttribute(atr_NonPrintableMarginTop,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidNonPrintableMarginTop(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginTop,AttributeType_double,false);
	};
/**
* Set attribute Punch
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetPunch(bool value){
	SetAttribute(atr_Punch,WString::valueOf(value));
};
/**
* Get bool attribute Punch
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoImageSetterParams::GetPunch() const {return GetBoolAttribute(atr_Punch,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidPunch(EnumValidationLevel level) const {
		return ValidAttribute(atr_Punch,AttributeType_boolean,false);
	};
/**
* Set attribute PunchType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetPunchType(const WString& value){
	SetAttribute(atr_PunchType,value);
};
/**
* Get string attribute PunchType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoImageSetterParams::GetPunchType() const {
	return GetAttribute(atr_PunchType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidPunchType(EnumValidationLevel level) const {
		return ValidAttribute(atr_PunchType,AttributeType_string,false);
	};
/**
* Set attribute Resolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetResolution(const JDFXYPair& value){
	SetAttribute(atr_Resolution,value);
};
/**
* Get string attribute Resolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoImageSetterParams::GetResolution() const {
	return GetAttribute(atr_Resolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_Resolution,AttributeType_XYPair,false);
	};
/**
* Set attribute RollCut
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetRollCut(double value){
	SetAttribute(atr_RollCut,WString::valueOf(value));
};
/**
* Get double attribute RollCut
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageSetterParams::GetRollCut() const {
	return GetRealAttribute(atr_RollCut,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidRollCut(EnumValidationLevel level) const {
		return ValidAttribute(atr_RollCut,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageSetterParams::SourceWorkStyleString(){
		static const WString enums=WString(L"Unknown,Simplex,Perfecting,WorkAndBack,WorkAndTurn,WorkAndTumble,WorkAndTwist");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageSetterParams::SourceWorkStyleString(EnumSourceWorkStyle value){
		return SourceWorkStyleString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageSetterParams::SetSourceWorkStyle( EnumSourceWorkStyle value){
	SetEnumAttribute(atr_SourceWorkStyle,value,SourceWorkStyleString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageSetterParams::EnumSourceWorkStyle JDFAutoImageSetterParams:: GetSourceWorkStyle() const {
	return (EnumSourceWorkStyle) GetEnumAttribute(atr_SourceWorkStyle,SourceWorkStyleString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidSourceWorkStyle(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SourceWorkStyle,SourceWorkStyleString(),false);
	};
/**
* Set attribute TransferCurve
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoImageSetterParams::SetTransferCurve(const JDFNumberList& value){
	SetAttribute(atr_TransferCurve,value.GetString());
};
/**
* Get string attribute TransferCurve
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoImageSetterParams::GetTransferCurve() const {
	return GetAttribute(atr_TransferCurve,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageSetterParams::ValidTransferCurve(EnumValidationLevel level) const {
		return ValidAttribute(atr_TransferCurve,AttributeType_TransferFunction,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFMedia JDFAutoImageSetterParams::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoImageSetterParams::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoImageSetterParams::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoImageSetterParams::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoImageSetterParams::GetFitPolicy()const{
	JDFFitPolicy e=GetElement(elm_FitPolicy);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoImageSetterParams::GetCreateFitPolicy(){
	JDFFitPolicy e=GetCreateElement(elm_FitPolicy);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoImageSetterParams::AppendFitPolicy(){
	JDFFitPolicy e=AppendElementN(elm_FitPolicy,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoImageSetterParams::RefFitPolicy(JDFFitPolicy& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoImageSetterParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Media);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Media);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMedia().IsValid(level)) {
				vElem.AppendUnique(elm_Media);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FitPolicy);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FitPolicy);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFitPolicy().IsValid(level)) {
				vElem.AppendUnique(elm_FitPolicy);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoImageSetterParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Media,FitPolicy";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoImageSetterParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Media,FitPolicy";
	};
}; // end namespace JDF
