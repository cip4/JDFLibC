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

 
#include "jdf/wrapper/AutoJDF/JDFAutoRasterReadingParams.h"
#include "jdf/wrapper/JDFFitPolicy.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRasterReadingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoRasterReadingParams& JDFAutoRasterReadingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoRasterReadingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoRasterReadingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoRasterReadingParams::ValidNodeNames()const{
	return L"*:,RasterReadingParams";
};

bool JDFAutoRasterReadingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoRasterReadingParams::init(){
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
	WString JDFAutoRasterReadingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Center,MirrorAround,Polarity,Poster,PosterOverlap,Scaling,ScalingOrigin");
};

/**
 typesafe validator
*/
	vWString JDFAutoRasterReadingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
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
	 void JDFAutoRasterReadingParams::SetCenter(bool value){
	SetAttribute(atr_Center,WString::valueOf(value));
};
/**
* Get bool attribute Center
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoRasterReadingParams::GetCenter() const {return GetBoolAttribute(atr_Center,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRasterReadingParams::ValidCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Center,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoRasterReadingParams::MirrorAroundString(){
		static const WString enums=WString(L"Unknown,None,FeedDirection,MediaWidth,Both");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoRasterReadingParams::MirrorAroundString(EnumMirrorAround value){
		return MirrorAroundString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRasterReadingParams::SetMirrorAround( EnumMirrorAround value){
	SetEnumAttribute(atr_MirrorAround,value,MirrorAroundString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRasterReadingParams::EnumMirrorAround JDFAutoRasterReadingParams:: GetMirrorAround() const {
	return (EnumMirrorAround) GetEnumAttribute(atr_MirrorAround,MirrorAroundString(),WString::emptyStr,MirrorAround_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRasterReadingParams::ValidMirrorAround(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MirrorAround,MirrorAroundString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoRasterReadingParams::PolarityString(){
		static const WString enums=WString(L"Unknown,Positive,Negative");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoRasterReadingParams::PolarityString(EnumPolarity value){
		return PolarityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRasterReadingParams::SetPolarity( EnumPolarity value){
	SetEnumAttribute(atr_Polarity,value,PolarityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRasterReadingParams::EnumPolarity JDFAutoRasterReadingParams:: GetPolarity() const {
	return (EnumPolarity) GetEnumAttribute(atr_Polarity,PolarityString(),WString::emptyStr,Polarity_Positive);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRasterReadingParams::ValidPolarity(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Polarity,PolarityString(),false);
	};
/**
* Set attribute Poster
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoRasterReadingParams::SetPoster(const JDFXYPair& value){
	SetAttribute(atr_Poster,value);
};
/**
* Get string attribute Poster
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoRasterReadingParams::GetPoster() const {
	return GetAttribute(atr_Poster,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRasterReadingParams::ValidPoster(EnumValidationLevel level) const {
		return ValidAttribute(atr_Poster,AttributeType_XYPair,false);
	};
/**
* Set attribute PosterOverlap
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoRasterReadingParams::SetPosterOverlap(const JDFXYPair& value){
	SetAttribute(atr_PosterOverlap,value);
};
/**
* Get string attribute PosterOverlap
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoRasterReadingParams::GetPosterOverlap() const {
	return GetAttribute(atr_PosterOverlap,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRasterReadingParams::ValidPosterOverlap(EnumValidationLevel level) const {
		return ValidAttribute(atr_PosterOverlap,AttributeType_XYPair,false);
	};
/**
* Set attribute Scaling
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoRasterReadingParams::SetScaling(const JDFXYPair& value){
	SetAttribute(atr_Scaling,value);
};
/**
* Get string attribute Scaling
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoRasterReadingParams::GetScaling() const {
	return GetAttribute(atr_Scaling,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRasterReadingParams::ValidScaling(EnumValidationLevel level) const {
		return ValidAttribute(atr_Scaling,AttributeType_XYPair,false);
	};
/**
* Set attribute ScalingOrigin
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoRasterReadingParams::SetScalingOrigin(const JDFXYPair& value){
	SetAttribute(atr_ScalingOrigin,value);
};
/**
* Get string attribute ScalingOrigin
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoRasterReadingParams::GetScalingOrigin() const {
	return GetAttribute(atr_ScalingOrigin,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRasterReadingParams::ValidScalingOrigin(EnumValidationLevel level) const {
		return ValidAttribute(atr_ScalingOrigin,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFitPolicy JDFAutoRasterReadingParams::GetFitPolicy()const{
	JDFFitPolicy e=GetElement(elm_FitPolicy);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoRasterReadingParams::GetCreateFitPolicy(){
	JDFFitPolicy e=GetCreateElement(elm_FitPolicy);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoRasterReadingParams::AppendFitPolicy(){
	JDFFitPolicy e=AppendElementN(elm_FitPolicy,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoRasterReadingParams::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoRasterReadingParams::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoRasterReadingParams::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoRasterReadingParams::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoRasterReadingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
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
		nElem=NumChildElements(elm_Media);

		for(i=0;i<nElem;i++){
			if (!GetMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_Media);
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
	WString JDFAutoRasterReadingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",FitPolicy";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoRasterReadingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",FitPolicy,Media";
	};
}; // end namespace JDF
