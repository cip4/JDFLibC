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

 
#include "jdf/wrapper/AutoJDF/JDFAutoProofingParams.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoProofingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoProofingParams& JDFAutoProofingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoProofingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoProofingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoProofingParams::ValidNodeNames()const{
	return L"*:,ProofingParams";
};

bool JDFAutoProofingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoProofingParams::init(){
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
	WString JDFAutoProofingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DisplayTraps,HalfTone,ImageViewingStrategy,ManualFeed,ProofRenderingIntent,ProofType,ColorType,Resolution");
};

/**
 typesafe validator
*/
	vWString JDFAutoProofingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDisplayTraps(level)) {
			vAtts.push_back(atr_DisplayTraps);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHalfTone(level)) {
			vAtts.push_back(atr_HalfTone);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageViewingStrategy(level)) {
			vAtts.push_back(atr_ImageViewingStrategy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidManualFeed(level)) {
			vAtts.push_back(atr_ManualFeed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProofRenderingIntent(level)) {
			vAtts.push_back(atr_ProofRenderingIntent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProofType(level)) {
			vAtts.push_back(atr_ProofType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorType(level)) {
			vAtts.push_back(atr_ColorType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResolution(level)) {
			vAtts.push_back(atr_Resolution);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DisplayTraps
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoProofingParams::SetDisplayTraps(bool value){
	SetAttribute(atr_DisplayTraps,WString::valueOf(value));
};
/**
* Get bool attribute DisplayTraps
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoProofingParams::GetDisplayTraps() const {return GetBoolAttribute(atr_DisplayTraps,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofingParams::ValidDisplayTraps(EnumValidationLevel level) const {
		return ValidAttribute(atr_DisplayTraps,AttributeType_boolean,false);
	};
/**
* Set attribute HalfTone
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoProofingParams::SetHalfTone(bool value){
	SetAttribute(atr_HalfTone,WString::valueOf(value));
};
/**
* Get bool attribute HalfTone
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoProofingParams::GetHalfTone() const {return GetBoolAttribute(atr_HalfTone,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofingParams::ValidHalfTone(EnumValidationLevel level) const {
		return ValidAttribute(atr_HalfTone,AttributeType_boolean,false);
	};
/**
* Set attribute ImageViewingStrategy
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoProofingParams::SetImageViewingStrategy(const WString& value){
	SetAttribute(atr_ImageViewingStrategy,value);
};
/**
* Get string attribute ImageViewingStrategy
* @return WString the vaue of the attribute ; defaults to NoImages
*/
	 WString JDFAutoProofingParams::GetImageViewingStrategy() const {
	return GetAttribute(atr_ImageViewingStrategy,WString::emptyStr,L"NoImages");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofingParams::ValidImageViewingStrategy(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageViewingStrategy,AttributeType_string,false);
	};
/**
* Set attribute ManualFeed
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoProofingParams::SetManualFeed(bool value){
	SetAttribute(atr_ManualFeed,WString::valueOf(value));
};
/**
* Get bool attribute ManualFeed
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoProofingParams::GetManualFeed() const {return GetBoolAttribute(atr_ManualFeed,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofingParams::ValidManualFeed(EnumValidationLevel level) const {
		return ValidAttribute(atr_ManualFeed,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoProofingParams::ProofRenderingIntentString(){
		static const WString enums=WString(L"Unknown,Saturation,Perceptual,RelativeColorimetric,AbsoluteColorimetric");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoProofingParams::ProofRenderingIntentString(EnumProofRenderingIntent value){
		return ProofRenderingIntentString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoProofingParams::SetProofRenderingIntent( EnumProofRenderingIntent value){
	SetEnumAttribute(atr_ProofRenderingIntent,value,ProofRenderingIntentString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoProofingParams::EnumProofRenderingIntent JDFAutoProofingParams:: GetProofRenderingIntent() const {
	return (EnumProofRenderingIntent) GetEnumAttribute(atr_ProofRenderingIntent,ProofRenderingIntentString(),WString::emptyStr,ProofRenderingIntent_Perceptual);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofingParams::ValidProofRenderingIntent(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ProofRenderingIntent,ProofRenderingIntentString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoProofingParams::ProofTypeString(){
		static const WString enums=WString(L"Unknown,None,Page,Imposition");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoProofingParams::ProofTypeString(EnumProofType value){
		return ProofTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoProofingParams::SetProofType( EnumProofType value){
	SetEnumAttribute(atr_ProofType,value,ProofTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoProofingParams::EnumProofType JDFAutoProofingParams:: GetProofType() const {
	return (EnumProofType) GetEnumAttribute(atr_ProofType,ProofTypeString(),WString::emptyStr,ProofType_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofingParams::ValidProofType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ProofType,ProofTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoProofingParams::ColorTypeString(){
		static const WString enums=WString(L"Unknown,Monochrome,BasicColor,MatchedColor");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoProofingParams::ColorTypeString(EnumColorType value){
		return ColorTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoProofingParams::SetColorType( EnumColorType value){
	SetEnumAttribute(atr_ColorType,value,ColorTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoProofingParams::EnumColorType JDFAutoProofingParams:: GetColorType() const {
	return (EnumColorType) GetEnumAttribute(atr_ColorType,ColorTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofingParams::ValidColorType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ColorType,ColorTypeString(),false);
	};
/**
* Set attribute Resolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoProofingParams::SetResolution(const JDFXYPair& value){
	SetAttribute(atr_Resolution,value);
};
/**
* Get string attribute Resolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoProofingParams::GetResolution() const {
	return GetAttribute(atr_Resolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofingParams::ValidResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_Resolution,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoProofingParams::GetFileSpec()const{
	JDFFileSpec e=GetElement(elm_FileSpec);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoProofingParams::GetCreateFileSpec(){
	JDFFileSpec e=GetCreateElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoProofingParams::AppendFileSpec(){
	JDFFileSpec e=AppendElementN(elm_FileSpec,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoProofingParams::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoProofingParams::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoProofingParams::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoProofingParams::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoProofingParams::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoProofingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_FileSpec);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FileSpec);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFileSpec().IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
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
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoProofingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",FileSpec,Media";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoProofingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",FileSpec,Media";
	};
}; // end namespace JDF
