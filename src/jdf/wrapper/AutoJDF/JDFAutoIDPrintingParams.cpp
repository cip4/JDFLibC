/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIDPrintingParams.h"
#include "jdf/wrapper/JDFIDPCover.h"
#include "jdf/wrapper/JDFIDPFinishing.h"
#include "jdf/wrapper/JDFIDPLayout.h"
#include "jdf/wrapper/JDFIDPJobSheet.h"
#include "jdf/wrapper/JDFMediaIntent.h"
#include "jdf/wrapper/JDFMediaSource.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDPrintingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIDPrintingParams& JDFAutoIDPrintingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIDPrintingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIDPrintingParams::ValidNodeNames()const{
	return L"*:,IDPrintingParams";
};

bool JDFAutoIDPrintingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoIDPrintingParams::init(){
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
	WString JDFAutoIDPrintingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",AttributesNaturalLang,IDPAttributeFidelity,IPPJobPriority,IPPVersion,OutputBin,PageDelivery,PrintQuality,SheetCollate");
};

/**
 typesafe validator
*/
	vWString JDFAutoIDPrintingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAttributesNaturalLang(level)) {
			vAtts.push_back(atr_AttributesNaturalLang);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIDPAttributeFidelity(level)) {
			vAtts.push_back(atr_IDPAttributeFidelity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIPPJobPriority(level)) {
			vAtts.push_back(atr_IPPJobPriority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIPPVersion(level)) {
			vAtts.push_back(atr_IPPVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutputBin(level)) {
			vAtts.push_back(atr_OutputBin);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageDelivery(level)) {
			vAtts.push_back(atr_PageDelivery);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrintQuality(level)) {
			vAtts.push_back(atr_PrintQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetCollate(level)) {
			vAtts.push_back(atr_SheetCollate);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AttributesNaturalLang
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDPrintingParams::SetAttributesNaturalLang(const WString& value){
	SetAttribute(atr_AttributesNaturalLang,value);
};
/**
* Get string attribute AttributesNaturalLang
* @return WString the vaue of the attribute ; defaults to US
*/
	 WString JDFAutoIDPrintingParams::GetAttributesNaturalLang() const {
	return GetAttribute(atr_AttributesNaturalLang,WString::emptyStr,L"US");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::ValidAttributesNaturalLang(EnumValidationLevel level) const {
		return ValidAttribute(atr_AttributesNaturalLang,AttributeType_language,false);
	};
/**
* Set attribute IDPAttributeFidelity
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoIDPrintingParams::SetIDPAttributeFidelity(bool value){
	SetAttribute(atr_IDPAttributeFidelity,WString::valueOf(value));
};
/**
* Get bool attribute IDPAttributeFidelity
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoIDPrintingParams::GetIDPAttributeFidelity() const {return GetBoolAttribute(atr_IDPAttributeFidelity,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::ValidIDPAttributeFidelity(EnumValidationLevel level) const {
		return ValidAttribute(atr_IDPAttributeFidelity,AttributeType_boolean,false);
	};
/**
* Set attribute IPPJobPriority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIDPrintingParams::SetIPPJobPriority(int value){
	SetAttribute(atr_IPPJobPriority,WString::valueOf(value));
};
/**
* Get integer attribute IPPJobPriority
* @return int the vaue of the attribute ; defaults to 50
*/
	 int JDFAutoIDPrintingParams::GetIPPJobPriority() const {
	return GetIntAttribute(atr_IPPJobPriority,WString::emptyStr,50);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::ValidIPPJobPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_IPPJobPriority,AttributeType_integer,false);
	};
/**
* Set attribute IPPVersion
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoIDPrintingParams::SetIPPVersion(const JDFXYPair& value){
	SetAttribute(atr_IPPVersion,value);
};
/**
* Get string attribute IPPVersion
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoIDPrintingParams::GetIPPVersion() const {
	return GetAttribute(atr_IPPVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::ValidIPPVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_IPPVersion,AttributeType_XYPair,false);
	};
/**
* Set attribute OutputBin
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDPrintingParams::SetOutputBin(const WString& value){
	SetAttribute(atr_OutputBin,value);
};
/**
* Get string attribute OutputBin
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIDPrintingParams::GetOutputBin() const {
	return GetAttribute(atr_OutputBin,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::ValidOutputBin(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutputBin,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPrintingParams::PageDeliveryString(){
		static const WString enums=WString(L"Unknown,SameOrderFaceUp,SameOrderFaceDown,ReverseOrderFaceUp,ReverseOrderFaceDown,SystemSpecified");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPrintingParams::PageDeliveryString(EnumPageDelivery value){
		return PageDeliveryString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPrintingParams::SetPageDelivery( EnumPageDelivery value){
	SetEnumAttribute(atr_PageDelivery,value,PageDeliveryString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPrintingParams::EnumPageDelivery JDFAutoIDPrintingParams:: GetPageDelivery() const {
	return (EnumPageDelivery) GetEnumAttribute(atr_PageDelivery,PageDeliveryString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::ValidPageDelivery(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PageDelivery,PageDeliveryString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPrintingParams::PrintQualityString(){
		static const WString enums=WString(L"Unknown,High,Normal,Draft");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPrintingParams::PrintQualityString(EnumPrintQuality value){
		return PrintQualityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPrintingParams::SetPrintQuality( EnumPrintQuality value){
	SetEnumAttribute(atr_PrintQuality,value,PrintQualityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPrintingParams::EnumPrintQuality JDFAutoIDPrintingParams:: GetPrintQuality() const {
	return (EnumPrintQuality) GetEnumAttribute(atr_PrintQuality,PrintQualityString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::ValidPrintQuality(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PrintQuality,PrintQualityString(),false);
	};
/**
* Set attribute SheetCollate
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoIDPrintingParams::SetSheetCollate(bool value){
	SetAttribute(atr_SheetCollate,WString::valueOf(value));
};
/**
* Get bool attribute SheetCollate
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoIDPrintingParams::GetSheetCollate() const {return GetBoolAttribute(atr_SheetCollate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPrintingParams::ValidSheetCollate(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetCollate,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIDPCover JDFAutoIDPrintingParams::GetCover(int iSkip)const{
	JDFIDPCover e=GetElement(elm_Cover,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPCover JDFAutoIDPrintingParams::GetCreateCover(int iSkip){
	JDFIDPCover e=GetCreateElement(elm_Cover,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPCover JDFAutoIDPrintingParams::AppendCover(){
	JDFIDPCover e=AppendElement(elm_Cover);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFinishing JDFAutoIDPrintingParams::GetIDPFinishing()const{
	JDFIDPFinishing e=GetElement(elm_IDPFinishing);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFinishing JDFAutoIDPrintingParams::GetCreateIDPFinishing(){
	JDFIDPFinishing e=GetCreateElement(elm_IDPFinishing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFinishing JDFAutoIDPrintingParams::AppendIDPFinishing(){
	JDFIDPFinishing e=AppendElementN(elm_IDPFinishing,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPrintingParams::GetIDPLayout()const{
	JDFIDPLayout e=GetElement(elm_IDPLayout);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPrintingParams::GetCreateIDPLayout(){
	JDFIDPLayout e=GetCreateElement(elm_IDPLayout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPrintingParams::AppendIDPLayout(){
	JDFIDPLayout e=AppendElementN(elm_IDPLayout,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPJobSheet JDFAutoIDPrintingParams::GetJobSheet(int iSkip)const{
	JDFIDPJobSheet e=GetElement(elm_JobSheet,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPJobSheet JDFAutoIDPrintingParams::GetCreateJobSheet(int iSkip){
	JDFIDPJobSheet e=GetCreateElement(elm_JobSheet,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPJobSheet JDFAutoIDPrintingParams::AppendJobSheet(){
	JDFIDPJobSheet e=AppendElement(elm_JobSheet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPrintingParams::GetMediaIntent()const{
	JDFMediaIntent e=GetElement(elm_MediaIntent);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPrintingParams::GetCreateMediaIntent(){
	JDFMediaIntent e=GetCreateElement(elm_MediaIntent);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPrintingParams::AppendMediaIntent(){
	JDFMediaIntent e=AppendElementN(elm_MediaIntent,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIDPrintingParams::RefMediaIntent(JDFMediaIntent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPrintingParams::GetMediaSource()const{
	JDFMediaSource e=GetElement(elm_MediaSource);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPrintingParams::GetCreateMediaSource(){
	JDFMediaSource e=GetCreateElement(elm_MediaSource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPrintingParams::AppendMediaSource(){
	JDFMediaSource e=AppendElementN(elm_MediaSource,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIDPrintingParams::RefMediaSource(JDFMediaSource& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoIDPrintingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Cover);

		for(i=0;i<nElem;i++){
			if (!GetCover(i).IsValid(level)) {
				vElem.AppendUnique(elm_Cover);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IDPFinishing);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_IDPFinishing);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetIDPFinishing().IsValid(level)) {
				vElem.AppendUnique(elm_IDPFinishing);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_IDPLayout);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_IDPLayout);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetIDPLayout().IsValid(level)) {
				vElem.AppendUnique(elm_IDPLayout);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_JobSheet);

		for(i=0;i<nElem;i++){
			if (!GetJobSheet(i).IsValid(level)) {
				vElem.AppendUnique(elm_JobSheet);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MediaIntent);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaIntent);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaIntent().IsValid(level)) {
				vElem.AppendUnique(elm_MediaIntent);
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
	WString JDFAutoIDPrintingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",IDPFinishing,IDPLayout,MediaIntent,MediaSource";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoIDPrintingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Cover,IDPFinishing,IDPLayout,JobSheet,MediaIntent,MediaSource";
	};
}; // end namespace JDF
