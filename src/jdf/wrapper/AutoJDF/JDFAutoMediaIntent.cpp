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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMediaIntent.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMediaIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMediaIntent& JDFAutoMediaIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMediaIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMediaIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMediaIntent::ValidNodeNames()const{
	return L"*:,MediaIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMediaIntent::OptionalAttributes()const{
		return JDFIntentResource::OptionalAttributes()+WString(L",PrePrinted,MediaSetCount,UserMediaType");
};

/**
 typesafe validator
*/
	vWString JDFAutoMediaIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPrePrinted(level)) {
			vAtts.push_back(atr_PrePrinted);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaSetCount(level)) {
			vAtts.push_back(atr_MediaSetCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUserMediaType(level)) {
			vAtts.push_back(atr_UserMediaType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PrePrinted
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMediaIntent::SetPrePrinted(bool value){
	SetAttribute(atr_PrePrinted,WString::valueOf(value));
};
/**
* Get bool attribute PrePrinted
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMediaIntent::GetPrePrinted() const {return GetBoolAttribute(atr_PrePrinted,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMediaIntent::ValidPrePrinted(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrePrinted,AttributeType_boolean,false);
	};
/**
* Set attribute MediaSetCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMediaIntent::SetMediaSetCount(int value){
	SetAttribute(atr_MediaSetCount,WString::valueOf(value));
};
/**
* Get integer attribute MediaSetCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoMediaIntent::GetMediaSetCount() const {
	return GetIntAttribute(atr_MediaSetCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMediaIntent::ValidMediaSetCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaSetCount,AttributeType_integer,false);
	};
/**
* Set attribute UserMediaType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMediaIntent::SetUserMediaType(const WString& value){
	SetAttribute(atr_UserMediaType,value);
};
/**
* Get string attribute UserMediaType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMediaIntent::GetUserMediaType() const {
	return GetAttribute(atr_UserMediaType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMediaIntent::ValidUserMediaType(EnumValidationLevel level) const {
		return ValidAttribute(atr_UserMediaType,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpanCoatings JDFAutoMediaIntent::GetBackCoatings()const{
	JDFSpanCoatings e=GetElement(elm_BackCoatings);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanCoatings JDFAutoMediaIntent::GetCreateBackCoatings(){
	JDFSpanCoatings e=GetCreateElement(elm_BackCoatings);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanCoatings JDFAutoMediaIntent::AppendBackCoatings(){
	JDFSpanCoatings e=AppendElementN(elm_BackCoatings,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetBrightness()const{
	JDFNumberSpan e=GetElement(elm_Brightness);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetCreateBrightness(){
	JDFNumberSpan e=GetCreateElement(elm_Brightness);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::AppendBrightness(){
	JDFNumberSpan e=AppendElementN(elm_Brightness,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoMediaIntent::GetBuyerSupplied()const{
	JDFOptionSpan e=GetElement(elm_BuyerSupplied);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoMediaIntent::GetCreateBuyerSupplied(){
	JDFOptionSpan e=GetCreateElement(elm_BuyerSupplied);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoMediaIntent::AppendBuyerSupplied(){
	JDFOptionSpan e=AppendElementN(elm_BuyerSupplied,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoMediaIntent::GetDimensions()const{
	JDFXYPairSpan e=GetElement(elm_Dimensions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoMediaIntent::GetCreateDimensions(){
	JDFXYPairSpan e=GetCreateElement(elm_Dimensions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoMediaIntent::AppendDimensions(){
	JDFXYPairSpan e=AppendElementN(elm_Dimensions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanCoatings JDFAutoMediaIntent::GetFrontCoatings()const{
	JDFSpanCoatings e=GetElement(elm_FrontCoatings);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanCoatings JDFAutoMediaIntent::GetCreateFrontCoatings(){
	JDFSpanCoatings e=GetCreateElement(elm_FrontCoatings);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanCoatings JDFAutoMediaIntent::AppendFrontCoatings(){
	JDFSpanCoatings e=AppendElementN(elm_FrontCoatings,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoMediaIntent::GetGrade()const{
	JDFIntegerSpan e=GetElement(elm_Grade);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoMediaIntent::GetCreateGrade(){
	JDFIntegerSpan e=GetCreateElement(elm_Grade);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoMediaIntent::AppendGrade(){
	JDFIntegerSpan e=AppendElementN(elm_Grade,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGrainDirection JDFAutoMediaIntent::GetGrainDirection()const{
	JDFSpanGrainDirection e=GetElement(elm_GrainDirection);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGrainDirection JDFAutoMediaIntent::GetCreateGrainDirection(){
	JDFSpanGrainDirection e=GetCreateElement(elm_GrainDirection);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGrainDirection JDFAutoMediaIntent::AppendGrainDirection(){
	JDFSpanGrainDirection e=AppendElementN(elm_GrainDirection,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoMediaIntent::GetHoleCount()const{
	JDFIntegerSpan e=GetElement(elm_HoleCount);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoMediaIntent::GetCreateHoleCount(){
	JDFIntegerSpan e=GetCreateElement(elm_HoleCount);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoMediaIntent::AppendHoleCount(){
	JDFIntegerSpan e=AppendElementN(elm_HoleCount,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::GetHoleType()const{
	JDFStringSpan e=GetElement(elm_HoleType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::GetCreateHoleType(){
	JDFStringSpan e=GetCreateElement(elm_HoleType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::AppendHoleType(){
	JDFStringSpan e=AppendElementN(elm_HoleType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoMediaIntent::GetMediaColor()const{
	JDFSpanNamedColor e=GetElement(elm_MediaColor);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoMediaIntent::GetCreateMediaColor(){
	JDFSpanNamedColor e=GetCreateElement(elm_MediaColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoMediaIntent::AppendMediaColor(){
	JDFSpanNamedColor e=AppendElementN(elm_MediaColor,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::GetMediaColorDetails()const{
	JDFStringSpan e=GetElement(elm_MediaColorDetails);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::GetCreateMediaColorDetails(){
	JDFStringSpan e=GetCreateElement(elm_MediaColorDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::AppendMediaColorDetails(){
	JDFStringSpan e=AppendElementN(elm_MediaColorDetails,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMediaType JDFAutoMediaIntent::GetMediaType()const{
	JDFSpanMediaType e=GetElement(elm_MediaType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMediaType JDFAutoMediaIntent::GetCreateMediaType(){
	JDFSpanMediaType e=GetCreateElement(elm_MediaType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMediaType JDFAutoMediaIntent::AppendMediaType(){
	JDFSpanMediaType e=AppendElementN(elm_MediaType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::GetMediaTypeDetails()const{
	JDFNameSpan e=GetElement(elm_MediaTypeDetails);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::GetCreateMediaTypeDetails(){
	JDFNameSpan e=GetCreateElement(elm_MediaTypeDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::AppendMediaTypeDetails(){
	JDFNameSpan e=AppendElementN(elm_MediaTypeDetails,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMediaUnit JDFAutoMediaIntent::GetMediaUnit()const{
	JDFSpanMediaUnit e=GetElement(elm_MediaUnit);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMediaUnit JDFAutoMediaIntent::GetCreateMediaUnit(){
	JDFSpanMediaUnit e=GetCreateElement(elm_MediaUnit);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMediaUnit JDFAutoMediaIntent::AppendMediaUnit(){
	JDFSpanMediaUnit e=AppendElementN(elm_MediaUnit,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanOpacity JDFAutoMediaIntent::GetOpacity()const{
	JDFSpanOpacity e=GetElement(elm_Opacity);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanOpacity JDFAutoMediaIntent::GetCreateOpacity(){
	JDFSpanOpacity e=GetCreateElement(elm_Opacity);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanOpacity JDFAutoMediaIntent::AppendOpacity(){
	JDFSpanOpacity e=AppendElementN(elm_Opacity,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetOpacityLevel()const{
	JDFNumberSpan e=GetElement(elm_OpacityLevel);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetCreateOpacityLevel(){
	JDFNumberSpan e=GetCreateElement(elm_OpacityLevel);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::AppendOpacityLevel(){
	JDFNumberSpan e=AppendElementN(elm_OpacityLevel,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoMediaIntent::GetRecycled()const{
	JDFOptionSpan e=GetElement(elm_Recycled);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoMediaIntent::GetCreateRecycled(){
	JDFOptionSpan e=GetCreateElement(elm_Recycled);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoMediaIntent::AppendRecycled(){
	JDFOptionSpan e=AppendElementN(elm_Recycled,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetRecycledPercentage()const{
	JDFNumberSpan e=GetElement(elm_RecycledPercentage);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetCreateRecycledPercentage(){
	JDFNumberSpan e=GetCreateElement(elm_RecycledPercentage);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::AppendRecycledPercentage(){
	JDFNumberSpan e=AppendElementN(elm_RecycledPercentage,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::GetStockBrand()const{
	JDFStringSpan e=GetElement(elm_StockBrand);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::GetCreateStockBrand(){
	JDFStringSpan e=GetCreateElement(elm_StockBrand);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoMediaIntent::AppendStockBrand(){
	JDFStringSpan e=AppendElementN(elm_StockBrand,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::GetStockType()const{
	JDFNameSpan e=GetElement(elm_StockType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::GetCreateStockType(){
	JDFNameSpan e=GetCreateElement(elm_StockType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::AppendStockType(){
	JDFNameSpan e=AppendElementN(elm_StockType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::GetTexture()const{
	JDFNameSpan e=GetElement(elm_Texture);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::GetCreateTexture(){
	JDFNameSpan e=GetCreateElement(elm_Texture);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoMediaIntent::AppendTexture(){
	JDFNameSpan e=AppendElementN(elm_Texture,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetThickness()const{
	JDFNumberSpan e=GetElement(elm_Thickness);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetCreateThickness(){
	JDFNumberSpan e=GetCreateElement(elm_Thickness);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::AppendThickness(){
	JDFNumberSpan e=AppendElementN(elm_Thickness,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetUSWeight()const{
	JDFNumberSpan e=GetElement(elm_USWeight);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetCreateUSWeight(){
	JDFNumberSpan e=GetCreateElement(elm_USWeight);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::AppendUSWeight(){
	JDFNumberSpan e=AppendElementN(elm_USWeight,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetWeight()const{
	JDFNumberSpan e=GetElement(elm_Weight);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::GetCreateWeight(){
	JDFNumberSpan e=GetCreateElement(elm_Weight);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoMediaIntent::AppendWeight(){
	JDFNumberSpan e=AppendElementN(elm_Weight,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoMediaIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BackCoatings);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_BackCoatings);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetBackCoatings().IsValid(level)) {
				vElem.AppendUnique(elm_BackCoatings);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Brightness);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Brightness);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetBrightness().IsValid(level)) {
				vElem.AppendUnique(elm_Brightness);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_BuyerSupplied);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_BuyerSupplied);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetBuyerSupplied().IsValid(level)) {
				vElem.AppendUnique(elm_BuyerSupplied);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Dimensions);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Dimensions);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDimensions().IsValid(level)) {
				vElem.AppendUnique(elm_Dimensions);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FrontCoatings);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FrontCoatings);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFrontCoatings().IsValid(level)) {
				vElem.AppendUnique(elm_FrontCoatings);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Grade);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Grade);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetGrade().IsValid(level)) {
				vElem.AppendUnique(elm_Grade);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_GrainDirection);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_GrainDirection);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetGrainDirection().IsValid(level)) {
				vElem.AppendUnique(elm_GrainDirection);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_HoleCount);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_HoleCount);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetHoleCount().IsValid(level)) {
				vElem.AppendUnique(elm_HoleCount);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_HoleType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_HoleType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetHoleType().IsValid(level)) {
				vElem.AppendUnique(elm_HoleType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_MediaColor);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaColor);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaColor().IsValid(level)) {
				vElem.AppendUnique(elm_MediaColor);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_MediaColorDetails);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaColorDetails);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaColorDetails().IsValid(level)) {
				vElem.AppendUnique(elm_MediaColorDetails);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_MediaType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaType().IsValid(level)) {
				vElem.AppendUnique(elm_MediaType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_MediaTypeDetails);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaTypeDetails);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaTypeDetails().IsValid(level)) {
				vElem.AppendUnique(elm_MediaTypeDetails);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_MediaUnit);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaUnit);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaUnit().IsValid(level)) {
				vElem.AppendUnique(elm_MediaUnit);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Opacity);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Opacity);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetOpacity().IsValid(level)) {
				vElem.AppendUnique(elm_Opacity);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_OpacityLevel);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_OpacityLevel);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetOpacityLevel().IsValid(level)) {
				vElem.AppendUnique(elm_OpacityLevel);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Recycled);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Recycled);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetRecycled().IsValid(level)) {
				vElem.AppendUnique(elm_Recycled);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_RecycledPercentage);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_RecycledPercentage);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetRecycledPercentage().IsValid(level)) {
				vElem.AppendUnique(elm_RecycledPercentage);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_StockBrand);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_StockBrand);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetStockBrand().IsValid(level)) {
				vElem.AppendUnique(elm_StockBrand);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_StockType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_StockType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetStockType().IsValid(level)) {
				vElem.AppendUnique(elm_StockType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Texture);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Texture);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTexture().IsValid(level)) {
				vElem.AppendUnique(elm_Texture);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Thickness);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Thickness);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetThickness().IsValid(level)) {
				vElem.AppendUnique(elm_Thickness);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_USWeight);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_USWeight);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetUSWeight().IsValid(level)) {
				vElem.AppendUnique(elm_USWeight);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Weight);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Weight);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetWeight().IsValid(level)) {
				vElem.AppendUnique(elm_Weight);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoMediaIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",BackCoatings,Brightness,BuyerSupplied,Dimensions,FrontCoatings,Grade,GrainDirection,HoleCount,HoleType,MediaColor,MediaColorDetails,MediaType,MediaTypeDetails,MediaUnit,Opacity,OpacityLevel,Recycled,RecycledPercentage,StockBrand,StockType,Texture,Thickness,USWeight,Weight";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoMediaIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",BackCoatings,Brightness,BuyerSupplied,Dimensions,FrontCoatings,Grade,GrainDirection,HoleCount,HoleType,MediaColor,MediaColorDetails,MediaType,MediaTypeDetails,MediaUnit,Opacity,OpacityLevel,Recycled,RecycledPercentage,StockBrand,StockType,Texture,Thickness,USWeight,Weight";
	};
}; // end namespace JDF
