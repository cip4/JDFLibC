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

 
#include "jdf/wrapper/AutoJDF/JDFAutoRenderingParams.h"
#include "jdf/wrapper/JDFAutomatedOverPrintParams.h"
#include "jdf/wrapper/JDFObjectResolution.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFTIFFFormatParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRenderingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoRenderingParams& JDFAutoRenderingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoRenderingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoRenderingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoRenderingParams::ValidNodeNames()const{
	return L"*:,RenderingParams";
};

bool JDFAutoRenderingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoRenderingParams::init(){
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
	WString JDFAutoRenderingParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",MimeType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoRenderingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BandHeight,BandOrdering,BandWidth,ColorantDepth,Interleaved");
};

/**
 typesafe validator
*/
	vWString JDFAutoRenderingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMimeType(level)) {
			vAtts.push_back(atr_MimeType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBandHeight(level)) {
			vAtts.push_back(atr_BandHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBandOrdering(level)) {
			vAtts.push_back(atr_BandOrdering);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBandWidth(level)) {
			vAtts.push_back(atr_BandWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorantDepth(level)) {
			vAtts.push_back(atr_ColorantDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInterleaved(level)) {
			vAtts.push_back(atr_Interleaved);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute MimeType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRenderingParams::SetMimeType(const WString& value){
	SetAttribute(atr_MimeType,value);
};
/**
* Get string attribute MimeType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRenderingParams::GetMimeType() const {
	return GetAttribute(atr_MimeType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRenderingParams::ValidMimeType(EnumValidationLevel level) const {
		return ValidAttribute(atr_MimeType,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute BandHeight
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRenderingParams::SetBandHeight(int value){
	SetAttribute(atr_BandHeight,WString::valueOf(value));
};
/**
* Get integer attribute BandHeight
* @return int the vaue of the attribute 
*/
	 int JDFAutoRenderingParams::GetBandHeight() const {
	return GetIntAttribute(atr_BandHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRenderingParams::ValidBandHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_BandHeight,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoRenderingParams::BandOrderingString(){
		static const WString enums=WString(L"Unknown,BandMajor,ColorMajor");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoRenderingParams::BandOrderingString(EnumBandOrdering value){
		return BandOrderingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRenderingParams::SetBandOrdering( EnumBandOrdering value){
	SetEnumAttribute(atr_BandOrdering,value,BandOrderingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRenderingParams::EnumBandOrdering JDFAutoRenderingParams:: GetBandOrdering() const {
	return (EnumBandOrdering) GetEnumAttribute(atr_BandOrdering,BandOrderingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRenderingParams::ValidBandOrdering(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BandOrdering,BandOrderingString(),false);
	};
/**
* Set attribute BandWidth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRenderingParams::SetBandWidth(int value){
	SetAttribute(atr_BandWidth,WString::valueOf(value));
};
/**
* Get integer attribute BandWidth
* @return int the vaue of the attribute 
*/
	 int JDFAutoRenderingParams::GetBandWidth() const {
	return GetIntAttribute(atr_BandWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRenderingParams::ValidBandWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_BandWidth,AttributeType_integer,false);
	};
/**
* Set attribute ColorantDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRenderingParams::SetColorantDepth(int value){
	SetAttribute(atr_ColorantDepth,WString::valueOf(value));
};
/**
* Get integer attribute ColorantDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoRenderingParams::GetColorantDepth() const {
	return GetIntAttribute(atr_ColorantDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRenderingParams::ValidColorantDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorantDepth,AttributeType_integer,false);
	};
/**
* Set attribute Interleaved
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRenderingParams::SetInterleaved(bool value){
	SetAttribute(atr_Interleaved,WString::valueOf(value));
};
/**
* Get bool attribute Interleaved
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoRenderingParams::GetInterleaved() const {return GetBoolAttribute(atr_Interleaved,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRenderingParams::ValidInterleaved(EnumValidationLevel level) const {
		return ValidAttribute(atr_Interleaved,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAutomatedOverPrintParams JDFAutoRenderingParams::GetAutomatedOverPrintParams()const{
	JDFAutomatedOverPrintParams e=GetElement(elm_AutomatedOverPrintParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAutomatedOverPrintParams JDFAutoRenderingParams::GetCreateAutomatedOverPrintParams(){
	JDFAutomatedOverPrintParams e=GetCreateElement(elm_AutomatedOverPrintParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAutomatedOverPrintParams JDFAutoRenderingParams::AppendAutomatedOverPrintParams(){
	JDFAutomatedOverPrintParams e=AppendElementN(elm_AutomatedOverPrintParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObjectResolution JDFAutoRenderingParams::GetObjectResolution(int iSkip)const{
	JDFObjectResolution e=GetElement(elm_ObjectResolution,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObjectResolution JDFAutoRenderingParams::GetCreateObjectResolution(int iSkip){
	JDFObjectResolution e=GetCreateElement(elm_ObjectResolution,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObjectResolution JDFAutoRenderingParams::AppendObjectResolution(){
	JDFObjectResolution e=AppendElement(elm_ObjectResolution);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoRenderingParams::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoRenderingParams::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoRenderingParams::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoRenderingParams::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFTIFFFormatParams JDFAutoRenderingParams::GetTIFFFormatParams()const{
	JDFTIFFFormatParams e=GetElement(elm_TIFFFormatParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTIFFFormatParams JDFAutoRenderingParams::GetCreateTIFFFormatParams(){
	JDFTIFFFormatParams e=GetCreateElement(elm_TIFFFormatParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTIFFFormatParams JDFAutoRenderingParams::AppendTIFFFormatParams(){
	JDFTIFFFormatParams e=AppendElementN(elm_TIFFFormatParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoRenderingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_AutomatedOverPrintParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_AutomatedOverPrintParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAutomatedOverPrintParams().IsValid(level)) {
				vElem.AppendUnique(elm_AutomatedOverPrintParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ObjectResolution);

		for(i=0;i<nElem;i++){
			if (!GetObjectResolution(i).IsValid(level)) {
				vElem.AppendUnique(elm_ObjectResolution);
				if (++n>=nMax)
					return vElem;
				break;
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
		nElem=NumChildElements(elm_TIFFFormatParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TIFFFormatParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTIFFFormatParams().IsValid(level)) {
				vElem.AppendUnique(elm_TIFFFormatParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoRenderingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",AutomatedOverPrintParams,Media,TIFFFormatParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoRenderingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",AutomatedOverPrintParams,ObjectResolution,Media,TIFFFormatParams";
	};
}; // end namespace JDF
