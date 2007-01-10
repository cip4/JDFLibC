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

 
#include "jdf/wrapper/AutoJDF/JDFAutoExposedMedia.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFPageList.h"
#include "jdf/wrapper/JDFScreeningParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoExposedMedia : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoExposedMedia& JDFAutoExposedMedia::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoExposedMedia: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoExposedMedia::ValidNodeNames()const{
	return L"*:,ExposedMedia";
};

bool JDFAutoExposedMedia::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Handling;
};

bool JDFAutoExposedMedia::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Handling);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoExposedMedia::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Polarity,ColorType,PageListIndex,PlateType,ProofName,ProofQuality,ProofType,PunchType,Resolution");
};

/**
 typesafe validator
*/
	vWString JDFAutoExposedMedia::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPolarity(level)) {
			vAtts.push_back(atr_Polarity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorType(level)) {
			vAtts.push_back(atr_ColorType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageListIndex(level)) {
			vAtts.push_back(atr_PageListIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPlateType(level)) {
			vAtts.push_back(atr_PlateType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProofName(level)) {
			vAtts.push_back(atr_ProofName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProofQuality(level)) {
			vAtts.push_back(atr_ProofQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProofType(level)) {
			vAtts.push_back(atr_ProofType);
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
		return vAtts;
	};

/**
* Set attribute Polarity
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoExposedMedia::SetPolarity(bool value){
	SetAttribute(atr_Polarity,WString::valueOf(value));
};
/**
* Get bool attribute Polarity
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoExposedMedia::GetPolarity() const {return GetBoolAttribute(atr_Polarity,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidPolarity(EnumValidationLevel level) const {
		return ValidAttribute(atr_Polarity,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoExposedMedia::ColorTypeString(){
		static const WString enums=WString(L"Unknown,Color,GrayScale,Monochrome");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoExposedMedia::ColorTypeString(EnumColorType value){
		return ColorTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoExposedMedia::SetColorType( EnumColorType value){
	SetEnumAttribute(atr_ColorType,value,ColorTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoExposedMedia::EnumColorType JDFAutoExposedMedia:: GetColorType() const {
	return (EnumColorType) GetEnumAttribute(atr_ColorType,ColorTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidColorType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ColorType,ColorTypeString(),false);
	};
/**
* Set attribute PageListIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoExposedMedia::SetPageListIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageListIndex,value.GetString());
};
/**
* Get range attribute PageListIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoExposedMedia::GetPageListIndex() const {
	return GetAttribute(atr_PageListIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidPageListIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageListIndex,AttributeType_IntegerRangeList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoExposedMedia::PlateTypeString(){
		static const WString enums=WString(L"Unknown,Exposed,Dummy");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoExposedMedia::PlateTypeString(EnumPlateType value){
		return PlateTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoExposedMedia::SetPlateType( EnumPlateType value){
	SetEnumAttribute(atr_PlateType,value,PlateTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoExposedMedia::EnumPlateType JDFAutoExposedMedia:: GetPlateType() const {
	return (EnumPlateType) GetEnumAttribute(atr_PlateType,PlateTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidPlateType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PlateType,PlateTypeString(),false);
	};
/**
* Set attribute ProofName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoExposedMedia::SetProofName(const WString& value){
	SetAttribute(atr_ProofName,value);
};
/**
* Get string attribute ProofName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoExposedMedia::GetProofName() const {
	return GetAttribute(atr_ProofName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidProofName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProofName,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoExposedMedia::ProofQualityString(){
		static const WString enums=WString(L"Unknown,None,Halftone,Contone,Conceptual");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoExposedMedia::ProofQualityString(EnumProofQuality value){
		return ProofQualityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoExposedMedia::SetProofQuality( EnumProofQuality value){
	SetEnumAttribute(atr_ProofQuality,value,ProofQualityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoExposedMedia::EnumProofQuality JDFAutoExposedMedia:: GetProofQuality() const {
	return (EnumProofQuality) GetEnumAttribute(atr_ProofQuality,ProofQualityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidProofQuality(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ProofQuality,ProofQualityString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoExposedMedia::ProofTypeString(){
		static const WString enums=WString(L"Unknown,None,Imposition,Page");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoExposedMedia::ProofTypeString(EnumProofType value){
		return ProofTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoExposedMedia::SetProofType( EnumProofType value){
	SetEnumAttribute(atr_ProofType,value,ProofTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoExposedMedia::EnumProofType JDFAutoExposedMedia:: GetProofType() const {
	return (EnumProofType) GetEnumAttribute(atr_ProofType,ProofTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidProofType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ProofType,ProofTypeString(),false);
	};
/**
* Set attribute PunchType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoExposedMedia::SetPunchType(const WString& value){
	SetAttribute(atr_PunchType,value);
};
/**
* Get string attribute PunchType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoExposedMedia::GetPunchType() const {
	return GetAttribute(atr_PunchType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidPunchType(EnumValidationLevel level) const {
		return ValidAttribute(atr_PunchType,AttributeType_string,false);
	};
/**
* Set attribute Resolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoExposedMedia::SetResolution(const JDFXYPair& value){
	SetAttribute(atr_Resolution,value);
};
/**
* Get string attribute Resolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoExposedMedia::GetResolution() const {
	return GetAttribute(atr_Resolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoExposedMedia::ValidResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_Resolution,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoExposedMedia::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoExposedMedia::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoExposedMedia::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoExposedMedia::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoExposedMedia::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoExposedMedia::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoExposedMedia::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoExposedMedia::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoExposedMedia::GetPageList(int iSkip)const{
	JDFPageList e=GetElement(elm_PageList,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoExposedMedia::GetCreatePageList(int iSkip){
	JDFPageList e=GetCreateElement(elm_PageList,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoExposedMedia::AppendPageList(){
	JDFPageList e=AppendElement(elm_PageList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoExposedMedia::RefPageList(JDFPageList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoExposedMedia::GetScreeningParams(int iSkip)const{
	JDFScreeningParams e=GetElement(elm_ScreeningParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoExposedMedia::GetCreateScreeningParams(int iSkip){
	JDFScreeningParams e=GetCreateElement(elm_ScreeningParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoExposedMedia::AppendScreeningParams(){
	JDFScreeningParams e=AppendElement(elm_ScreeningParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoExposedMedia::RefScreeningParams(JDFScreeningParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoExposedMedia::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_FileSpec);

		for(i=0;i<nElem;i++){
			if (!GetFileSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
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
		nElem=NumChildElements(elm_PageList);

		for(i=0;i<nElem;i++){
			if (!GetPageList(i).IsValid(level)) {
				vElem.AppendUnique(elm_PageList);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ScreeningParams);

		for(i=0;i<nElem;i++){
			if (!GetScreeningParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_ScreeningParams);
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
	WString JDFAutoExposedMedia::OptionalElements()const{
		return JDFResource::OptionalElements()+L",FileSpec,Media,PageList,ScreeningParams";
	};
}; // end namespace JDF
