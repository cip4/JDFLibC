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

 
#include "jdf/wrapper/AutoJDF/JDFAutoInterpretingParams.h"
#include "jdf/wrapper/JDFObjectResolution.h"
#include "jdf/wrapper/JDFFitPolicy.h"
#include "jdf/wrapper/JDFInterpretingDetails.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFPDFInterpretingParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoInterpretingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoInterpretingParams& JDFAutoInterpretingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoInterpretingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoInterpretingParams::ValidNodeNames()const{
	return L"*:,InterpretingParams";
};

bool JDFAutoInterpretingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoInterpretingParams::init(){
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
	WString JDFAutoInterpretingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Center,MirrorAround,Polarity,PrintQuality,FitToPage,Poster,PosterOverlap,Scaling,ScalingOrigin");
};

/**
 typesafe validator
*/
	vWString JDFAutoInterpretingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCenter(level)) {
			vAtts.push_back(atr_Center);
			if(++n>=nMax)
				return vAtts;
		};
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
		if(!ValidPrintQuality(level)) {
			vAtts.push_back(atr_PrintQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFitToPage(level)) {
			vAtts.push_back(atr_FitToPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPoster(level)) {
			vAtts.push_back(atr_Poster);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPosterOverlap(level)) {
			vAtts.push_back(atr_PosterOverlap);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScaling(level)) {
			vAtts.push_back(atr_Scaling);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScalingOrigin(level)) {
			vAtts.push_back(atr_ScalingOrigin);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Center
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoInterpretingParams::SetCenter(bool value){
	SetAttribute(atr_Center,WString::valueOf(value));
};
/**
* Get bool attribute Center
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoInterpretingParams::GetCenter() const {return GetBoolAttribute(atr_Center,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Center,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInterpretingParams::MirrorAroundString(){
		static const WString enums=WString(L"Unknown,None,FeedDirection,MediaWidth,Both");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInterpretingParams::MirrorAroundString(EnumMirrorAround value){
		return MirrorAroundString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInterpretingParams::SetMirrorAround( EnumMirrorAround value){
	SetEnumAttribute(atr_MirrorAround,value,MirrorAroundString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInterpretingParams::EnumMirrorAround JDFAutoInterpretingParams:: GetMirrorAround() const {
	return (EnumMirrorAround) GetEnumAttribute(atr_MirrorAround,MirrorAroundString(),WString::emptyStr,MirrorAround_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidMirrorAround(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MirrorAround,MirrorAroundString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInterpretingParams::PolarityString(){
		static const WString enums=WString(L"Unknown,Positive,Negative");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInterpretingParams::PolarityString(EnumPolarity value){
		return PolarityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInterpretingParams::SetPolarity( EnumPolarity value){
	SetEnumAttribute(atr_Polarity,value,PolarityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInterpretingParams::EnumPolarity JDFAutoInterpretingParams:: GetPolarity() const {
	return (EnumPolarity) GetEnumAttribute(atr_Polarity,PolarityString(),WString::emptyStr,Polarity_Positive);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidPolarity(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Polarity,PolarityString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInterpretingParams::PrintQualityString(){
		static const WString enums=WString(L"Unknown,High,Normal,Draft");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInterpretingParams::PrintQualityString(EnumPrintQuality value){
		return PrintQualityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInterpretingParams::SetPrintQuality( EnumPrintQuality value){
	SetEnumAttribute(atr_PrintQuality,value,PrintQualityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInterpretingParams::EnumPrintQuality JDFAutoInterpretingParams:: GetPrintQuality() const {
	return (EnumPrintQuality) GetEnumAttribute(atr_PrintQuality,PrintQualityString(),WString::emptyStr,PrintQuality_Normal);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidPrintQuality(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PrintQuality,PrintQualityString(),false);
	};
/**
* Set attribute FitToPage
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoInterpretingParams::SetFitToPage(bool value){
	SetAttribute(atr_FitToPage,WString::valueOf(value));
};
/**
* Get bool attribute FitToPage
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoInterpretingParams::GetFitToPage() const {return GetBoolAttribute(atr_FitToPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidFitToPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_FitToPage,AttributeType_boolean,false);
	};
/**
* Set attribute Poster
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoInterpretingParams::SetPoster(const JDFXYPair& value){
	SetAttribute(atr_Poster,value);
};
/**
* Get string attribute Poster
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoInterpretingParams::GetPoster() const {
	return GetAttribute(atr_Poster,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidPoster(EnumValidationLevel level) const {
		return ValidAttribute(atr_Poster,AttributeType_XYPair,false);
	};
/**
* Set attribute PosterOverlap
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoInterpretingParams::SetPosterOverlap(const JDFXYPair& value){
	SetAttribute(atr_PosterOverlap,value);
};
/**
* Get string attribute PosterOverlap
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoInterpretingParams::GetPosterOverlap() const {
	return GetAttribute(atr_PosterOverlap,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidPosterOverlap(EnumValidationLevel level) const {
		return ValidAttribute(atr_PosterOverlap,AttributeType_XYPair,false);
	};
/**
* Set attribute Scaling
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoInterpretingParams::SetScaling(const JDFXYPair& value){
	SetAttribute(atr_Scaling,value);
};
/**
* Get string attribute Scaling
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoInterpretingParams::GetScaling() const {
	return GetAttribute(atr_Scaling,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidScaling(EnumValidationLevel level) const {
		return ValidAttribute(atr_Scaling,AttributeType_XYPair,false);
	};
/**
* Set attribute ScalingOrigin
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoInterpretingParams::SetScalingOrigin(const JDFXYPair& value){
	SetAttribute(atr_ScalingOrigin,value);
};
/**
* Get string attribute ScalingOrigin
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoInterpretingParams::GetScalingOrigin() const {
	return GetAttribute(atr_ScalingOrigin,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInterpretingParams::ValidScalingOrigin(EnumValidationLevel level) const {
		return ValidAttribute(atr_ScalingOrigin,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFObjectResolution JDFAutoInterpretingParams::GetObjectResolution(int iSkip)const{
	JDFObjectResolution e=GetElement(elm_ObjectResolution,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObjectResolution JDFAutoInterpretingParams::GetCreateObjectResolution(int iSkip){
	JDFObjectResolution e=GetCreateElement(elm_ObjectResolution,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObjectResolution JDFAutoInterpretingParams::AppendObjectResolution(){
	JDFObjectResolution e=AppendElement(elm_ObjectResolution);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoInterpretingParams::GetFitPolicy()const{
	JDFFitPolicy e=GetElement(elm_FitPolicy);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoInterpretingParams::GetCreateFitPolicy(){
	JDFFitPolicy e=GetCreateElement(elm_FitPolicy);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoInterpretingParams::AppendFitPolicy(){
	JDFFitPolicy e=AppendElementN(elm_FitPolicy,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInterpretingDetails JDFAutoInterpretingParams::GetInterpretingDetails(int iSkip)const{
	JDFInterpretingDetails e=GetElement(elm_InterpretingDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInterpretingDetails JDFAutoInterpretingParams::GetCreateInterpretingDetails(int iSkip){
	JDFInterpretingDetails e=GetCreateElement(elm_InterpretingDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInterpretingDetails JDFAutoInterpretingParams::AppendInterpretingDetails(){
	JDFInterpretingDetails e=AppendElement(elm_InterpretingDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoInterpretingParams::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoInterpretingParams::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoInterpretingParams::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoInterpretingParams::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPDFInterpretingParams JDFAutoInterpretingParams::GetPDFInterpretingParams()const{
	JDFPDFInterpretingParams e=GetElement(elm_PDFInterpretingParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFInterpretingParams JDFAutoInterpretingParams::GetCreatePDFInterpretingParams(){
	JDFPDFInterpretingParams e=GetCreateElement(elm_PDFInterpretingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFInterpretingParams JDFAutoInterpretingParams::AppendPDFInterpretingParams(){
	JDFPDFInterpretingParams e=AppendElementN(elm_PDFInterpretingParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoInterpretingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ObjectResolution);

		for(i=0;i<nElem;i++){
			if (!GetObjectResolution(i).IsValid(level)) {
				vElem.AppendUnique(elm_ObjectResolution);
				if (++n>=nMax)
					return vElem;
				break;
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
		nElem=NumChildElements(elm_InterpretingDetails);

		for(i=0;i<nElem;i++){
			if (!GetInterpretingDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_InterpretingDetails);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Media);

		for(i=0;i<nElem;i++){
			if (!GetMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_Media);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PDFInterpretingParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PDFInterpretingParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPDFInterpretingParams().IsValid(level)) {
				vElem.AppendUnique(elm_PDFInterpretingParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoInterpretingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",FitPolicy,PDFInterpretingParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoInterpretingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ObjectResolution,FitPolicy,InterpretingDetails,Media,PDFInterpretingParams";
	};
}; // end namespace JDF
