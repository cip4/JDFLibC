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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDigitalPrintingParams.h"
#include "jdf/wrapper/JDFComponent.h"
#include "jdf/wrapper/JDFApprovalParams.h"
#include "jdf/wrapper/JDFDisjointing.h"
#include "jdf/wrapper/JDFInk.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFMediaSource.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDigitalPrintingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDigitalPrintingParams& JDFAutoDigitalPrintingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDigitalPrintingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDigitalPrintingParams::ValidNodeNames()const{
	return L"*:,DigitalPrintingParams";
};

bool JDFAutoDigitalPrintingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoDigitalPrintingParams::init(){
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
	WString JDFAutoDigitalPrintingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DirectProofAmount,ManualFeed,Collate,OutputBin,PrintQuality,NonPrintableMarginBottom,NonPrintableMarginLeft,NonPrintableMarginRight,NonPrintableMarginTop,PageDelivery,PrintingType,SheetLay,Sides");
};

/**
 typesafe validator
*/
	vWString JDFAutoDigitalPrintingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDirectProofAmount(level)) {
			vAtts.push_back(atr_DirectProofAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidManualFeed(level)) {
			vAtts.push_back(atr_ManualFeed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCollate(level)) {
			vAtts.push_back(atr_Collate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutputBin(level)) {
			vAtts.push_back(atr_OutputBin);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrintQuality(level)) {
			vAtts.push_back(atr_PrintQuality);
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
		if(!ValidPageDelivery(level)) {
			vAtts.push_back(atr_PageDelivery);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrintingType(level)) {
			vAtts.push_back(atr_PrintingType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetLay(level)) {
			vAtts.push_back(atr_SheetLay);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSides(level)) {
			vAtts.push_back(atr_Sides);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DirectProofAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDigitalPrintingParams::SetDirectProofAmount(int value){
	SetAttribute(atr_DirectProofAmount,WString::valueOf(value));
};
/**
* Get integer attribute DirectProofAmount
* @return int the vaue of the attribute ; defaults to 0
*/
	 int JDFAutoDigitalPrintingParams::GetDirectProofAmount() const {
	return GetIntAttribute(atr_DirectProofAmount,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidDirectProofAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_DirectProofAmount,AttributeType_integer,false);
	};
/**
* Set attribute ManualFeed
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoDigitalPrintingParams::SetManualFeed(bool value){
	SetAttribute(atr_ManualFeed,WString::valueOf(value));
};
/**
* Get bool attribute ManualFeed
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoDigitalPrintingParams::GetManualFeed() const {return GetBoolAttribute(atr_ManualFeed,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidManualFeed(EnumValidationLevel level) const {
		return ValidAttribute(atr_ManualFeed,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDigitalPrintingParams::CollateString(){
		static const WString enums=WString(L"Unknown,None,Sheet,SheetAndSet,SheetSetAndJob,SystemSpecified");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDigitalPrintingParams::CollateString(EnumCollate value){
		return CollateString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDigitalPrintingParams::SetCollate( EnumCollate value){
	SetEnumAttribute(atr_Collate,value,CollateString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDigitalPrintingParams::EnumCollate JDFAutoDigitalPrintingParams:: GetCollate() const {
	return (EnumCollate) GetEnumAttribute(atr_Collate,CollateString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidCollate(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Collate,CollateString(),false);
	};
/**
* Set attribute OutputBin
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDigitalPrintingParams::SetOutputBin(const WString& value){
	SetAttribute(atr_OutputBin,value);
};
/**
* Get string attribute OutputBin
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDigitalPrintingParams::GetOutputBin() const {
	return GetAttribute(atr_OutputBin,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidOutputBin(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutputBin,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDigitalPrintingParams::PrintQualityString(){
		static const WString enums=WString(L"Unknown,High,Normal,Draft,SystemSpecified");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDigitalPrintingParams::PrintQualityString(EnumPrintQuality value){
		return PrintQualityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDigitalPrintingParams::SetPrintQuality( EnumPrintQuality value){
	SetEnumAttribute(atr_PrintQuality,value,PrintQualityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDigitalPrintingParams::EnumPrintQuality JDFAutoDigitalPrintingParams:: GetPrintQuality() const {
	return (EnumPrintQuality) GetEnumAttribute(atr_PrintQuality,PrintQualityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidPrintQuality(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PrintQuality,PrintQualityString(),false);
	};
/**
* Set attribute NonPrintableMarginBottom
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDigitalPrintingParams::SetNonPrintableMarginBottom(double value){
	SetAttribute(atr_NonPrintableMarginBottom,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginBottom
* @return double the vaue of the attribute 
*/
	 double JDFAutoDigitalPrintingParams::GetNonPrintableMarginBottom() const {
	return GetRealAttribute(atr_NonPrintableMarginBottom,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidNonPrintableMarginBottom(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginBottom,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginLeft
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDigitalPrintingParams::SetNonPrintableMarginLeft(double value){
	SetAttribute(atr_NonPrintableMarginLeft,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginLeft
* @return double the vaue of the attribute 
*/
	 double JDFAutoDigitalPrintingParams::GetNonPrintableMarginLeft() const {
	return GetRealAttribute(atr_NonPrintableMarginLeft,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidNonPrintableMarginLeft(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginLeft,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginRight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDigitalPrintingParams::SetNonPrintableMarginRight(double value){
	SetAttribute(atr_NonPrintableMarginRight,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginRight
* @return double the vaue of the attribute 
*/
	 double JDFAutoDigitalPrintingParams::GetNonPrintableMarginRight() const {
	return GetRealAttribute(atr_NonPrintableMarginRight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidNonPrintableMarginRight(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginRight,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginTop
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDigitalPrintingParams::SetNonPrintableMarginTop(double value){
	SetAttribute(atr_NonPrintableMarginTop,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginTop
* @return double the vaue of the attribute 
*/
	 double JDFAutoDigitalPrintingParams::GetNonPrintableMarginTop() const {
	return GetRealAttribute(atr_NonPrintableMarginTop,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidNonPrintableMarginTop(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginTop,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDigitalPrintingParams::PageDeliveryString(){
		static const WString enums=WString(L"Unknown,FanFold,SameOrderFaceUp,SameOrderFaceDown,ReverseOrderFaceUp,ReverseOrderFaceDown,SystemSpecified");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDigitalPrintingParams::PageDeliveryString(EnumPageDelivery value){
		return PageDeliveryString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDigitalPrintingParams::SetPageDelivery( EnumPageDelivery value){
	SetEnumAttribute(atr_PageDelivery,value,PageDeliveryString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDigitalPrintingParams::EnumPageDelivery JDFAutoDigitalPrintingParams:: GetPageDelivery() const {
	return (EnumPageDelivery) GetEnumAttribute(atr_PageDelivery,PageDeliveryString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidPageDelivery(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PageDelivery,PageDeliveryString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDigitalPrintingParams::PrintingTypeString(){
		static const WString enums=WString(L"Unknown,SheetFed,WebFed,ContinuousFed,SystemSpecified");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDigitalPrintingParams::PrintingTypeString(EnumPrintingType value){
		return PrintingTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDigitalPrintingParams::SetPrintingType( EnumPrintingType value){
	SetEnumAttribute(atr_PrintingType,value,PrintingTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDigitalPrintingParams::EnumPrintingType JDFAutoDigitalPrintingParams:: GetPrintingType() const {
	return (EnumPrintingType) GetEnumAttribute(atr_PrintingType,PrintingTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidPrintingType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PrintingType,PrintingTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDigitalPrintingParams::SheetLayString(){
		static const WString enums=WString(L"Unknown,Left,Right,Center,SystemSpecified");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDigitalPrintingParams::SheetLayString(EnumSheetLay value){
		return SheetLayString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDigitalPrintingParams::SetSheetLay( EnumSheetLay value){
	SetEnumAttribute(atr_SheetLay,value,SheetLayString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDigitalPrintingParams::EnumSheetLay JDFAutoDigitalPrintingParams:: GetSheetLay() const {
	return (EnumSheetLay) GetEnumAttribute(atr_SheetLay,SheetLayString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidSheetLay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetLay,SheetLayString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDigitalPrintingParams::SidesString(){
		static const WString enums=WString(L"Unknown,OneSidedBackFlipX,OneSidedBackFlipY,OneSidedFront,TwoSidedFlipX,TwoSidedFlipY");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDigitalPrintingParams::SidesString(EnumSides value){
		return SidesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDigitalPrintingParams::SetSides( EnumSides value){
	SetEnumAttribute(atr_Sides,value,SidesString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDigitalPrintingParams::EnumSides JDFAutoDigitalPrintingParams:: GetSides() const {
	return (EnumSides) GetEnumAttribute(atr_Sides,SidesString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalPrintingParams::ValidSides(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Sides,SidesString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFComponent JDFAutoDigitalPrintingParams::GetComponent()const{
	JDFComponent e=GetElement(elm_Component);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoDigitalPrintingParams::GetCreateComponent(){
	JDFComponent e=GetCreateElement(elm_Component);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoDigitalPrintingParams::AppendComponent(){
	JDFComponent e=AppendElementN(elm_Component,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDigitalPrintingParams::RefComponent(JDFComponent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoDigitalPrintingParams::GetApprovalParams()const{
	JDFApprovalParams e=GetElement(elm_ApprovalParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoDigitalPrintingParams::GetCreateApprovalParams(){
	JDFApprovalParams e=GetCreateElement(elm_ApprovalParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoDigitalPrintingParams::AppendApprovalParams(){
	JDFApprovalParams e=AppendElementN(elm_ApprovalParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDigitalPrintingParams::RefApprovalParams(JDFApprovalParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDisjointing JDFAutoDigitalPrintingParams::GetDisjointing()const{
	JDFDisjointing e=GetElement(elm_Disjointing);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisjointing JDFAutoDigitalPrintingParams::GetCreateDisjointing(){
	JDFDisjointing e=GetCreateElement(elm_Disjointing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisjointing JDFAutoDigitalPrintingParams::AppendDisjointing(){
	JDFDisjointing e=AppendElementN(elm_Disjointing,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDigitalPrintingParams::RefDisjointing(JDFDisjointing& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFInk JDFAutoDigitalPrintingParams::GetInk()const{
	JDFInk e=GetElement(elm_Ink);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInk JDFAutoDigitalPrintingParams::GetCreateInk(){
	JDFInk e=GetCreateElement(elm_Ink);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInk JDFAutoDigitalPrintingParams::AppendInk(){
	JDFInk e=AppendElementN(elm_Ink,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDigitalPrintingParams::RefInk(JDFInk& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDigitalPrintingParams::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDigitalPrintingParams::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDigitalPrintingParams::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDigitalPrintingParams::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoDigitalPrintingParams::GetMediaSource()const{
	JDFMediaSource e=GetElement(elm_MediaSource);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoDigitalPrintingParams::GetCreateMediaSource(){
	JDFMediaSource e=GetCreateElement(elm_MediaSource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoDigitalPrintingParams::AppendMediaSource(){
	JDFMediaSource e=AppendElementN(elm_MediaSource,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDigitalPrintingParams::RefMediaSource(JDFMediaSource& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDigitalPrintingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Component);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Component);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetComponent().IsValid(level)) {
				vElem.AppendUnique(elm_Component);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ApprovalParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ApprovalParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetApprovalParams().IsValid(level)) {
				vElem.AppendUnique(elm_ApprovalParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Disjointing);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Disjointing);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDisjointing().IsValid(level)) {
				vElem.AppendUnique(elm_Disjointing);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Ink);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Ink);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetInk().IsValid(level)) {
				vElem.AppendUnique(elm_Ink);
				if (++n>=nMax)
					return vElem;
			}
		}
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
		nElem=NumChildElements(elm_MediaSource);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaSource);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaSource().IsValid(level)) {
				vElem.AppendUnique(elm_MediaSource);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoDigitalPrintingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Component,ApprovalParams,Disjointing,Ink,Media,MediaSource";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDigitalPrintingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Component,ApprovalParams,Disjointing,Ink,Media,MediaSource";
	};
}; // end namespace JDF
