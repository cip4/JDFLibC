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

 
#include "jdf/wrapper/AutoJDF/JDFAutoContentData.h"
#include "jdf/wrapper/JDFContentMetaData.h"
#include "jdf/wrapper/JDFElementColorParams.h"
#include "jdf/wrapper/JDFImageCompressionParams.h"
#include "jdf/wrapper/JDFScreeningParams.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoContentData : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoContentData& JDFAutoContentData::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoContentData: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoContentData::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoContentData::ValidNodeNames()const{
	return L"*:,ContentData";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoContentData::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CatalogID,CatalogDetails,ContentRefs,ContentType,HasBleeds,ID,IsBlank,IsTrapped,JobID,ProductID");
};

/**
 typesafe validator
*/
	vWString JDFAutoContentData::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCatalogID(level)) {
			vAtts.push_back(atr_CatalogID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCatalogDetails(level)) {
			vAtts.push_back(atr_CatalogDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidContentRefs(level)) {
			vAtts.push_back(atr_ContentRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidContentType(level)) {
			vAtts.push_back(atr_ContentType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasBleeds(level)) {
			vAtts.push_back(atr_HasBleeds);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsBlank(level)) {
			vAtts.push_back(atr_IsBlank);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsTrapped(level)) {
			vAtts.push_back(atr_IsTrapped);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductID(level)) {
			vAtts.push_back(atr_ProductID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CatalogID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetCatalogID(const WString& value){
	SetAttribute(atr_CatalogID,value);
};
/**
* Get string attribute CatalogID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentData::GetCatalogID() const {
	return GetAttribute(atr_CatalogID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidCatalogID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CatalogID,AttributeType_string,false);
	};
/**
* Set attribute CatalogDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetCatalogDetails(const WString& value){
	SetAttribute(atr_CatalogDetails,value);
};
/**
* Get string attribute CatalogDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentData::GetCatalogDetails() const {
	return GetAttribute(atr_CatalogDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidCatalogDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_CatalogDetails,AttributeType_string,false);
	};
/**
* Set attribute ContentRefs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetContentRefs(const vWString& value){
	SetAttribute(atr_ContentRefs,value);
};
/**
* Get string attribute ContentRefs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoContentData::GetContentRefs() const {
	return GetAttribute(atr_ContentRefs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidContentRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContentRefs,AttributeType_IDREFS,false);
	};
/**
* Set attribute ContentType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetContentType(const WString& value){
	SetAttribute(atr_ContentType,value);
};
/**
* Get string attribute ContentType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentData::GetContentType() const {
	return GetAttribute(atr_ContentType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidContentType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContentType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute HasBleeds
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetHasBleeds(bool value){
	SetAttribute(atr_HasBleeds,WString::valueOf(value));
};
/**
* Get bool attribute HasBleeds
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoContentData::GetHasBleeds() const {return GetBoolAttribute(atr_HasBleeds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidHasBleeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasBleeds,AttributeType_boolean,false);
	};
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetID(const WString& value){
	SetAttribute(atr_ID,value);
};
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentData::GetID() const {
	return GetAttribute(atr_ID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,false);
	};
/**
* Set attribute IsBlank
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetIsBlank(bool value){
	SetAttribute(atr_IsBlank,WString::valueOf(value));
};
/**
* Get bool attribute IsBlank
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoContentData::GetIsBlank() const {return GetBoolAttribute(atr_IsBlank,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidIsBlank(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsBlank,AttributeType_boolean,false);
	};
/**
* Set attribute IsTrapped
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetIsTrapped(bool value){
	SetAttribute(atr_IsTrapped,WString::valueOf(value));
};
/**
* Get bool attribute IsTrapped
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoContentData::GetIsTrapped() const {return GetBoolAttribute(atr_IsTrapped,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidIsTrapped(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsTrapped,AttributeType_boolean,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentData::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_string,false);
	};
/**
* Set attribute ProductID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentData::SetProductID(const WString& value){
	SetAttribute(atr_ProductID,value);
};
/**
* Get string attribute ProductID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentData::GetProductID() const {
	return GetAttribute(atr_ProductID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentData::ValidProductID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductID,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFContentMetaData JDFAutoContentData::GetContentMetaData(int iSkip)const{
	JDFContentMetaData e=GetElement(elm_ContentMetaData,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContentMetaData JDFAutoContentData::GetCreateContentMetaData(int iSkip){
	JDFContentMetaData e=GetCreateElement(elm_ContentMetaData,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContentMetaData JDFAutoContentData::AppendContentMetaData(){
	JDFContentMetaData e=AppendElement(elm_ContentMetaData);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoContentData::GetElementColorParams(int iSkip)const{
	JDFElementColorParams e=GetElement(elm_ElementColorParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoContentData::GetCreateElementColorParams(int iSkip){
	JDFElementColorParams e=GetCreateElement(elm_ElementColorParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoContentData::AppendElementColorParams(){
	JDFElementColorParams e=AppendElement(elm_ElementColorParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContentData::RefElementColorParams(JDFElementColorParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoContentData::GetImageCompressionParams(int iSkip)const{
	JDFImageCompressionParams e=GetElement(elm_ImageCompressionParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoContentData::GetCreateImageCompressionParams(int iSkip){
	JDFImageCompressionParams e=GetCreateElement(elm_ImageCompressionParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoContentData::AppendImageCompressionParams(){
	JDFImageCompressionParams e=AppendElement(elm_ImageCompressionParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContentData::RefImageCompressionParams(JDFImageCompressionParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoContentData::GetScreeningParams(int iSkip)const{
	JDFScreeningParams e=GetElement(elm_ScreeningParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoContentData::GetCreateScreeningParams(int iSkip){
	JDFScreeningParams e=GetCreateElement(elm_ScreeningParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoContentData::AppendScreeningParams(){
	JDFScreeningParams e=AppendElement(elm_ScreeningParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContentData::RefScreeningParams(JDFScreeningParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoContentData::GetSeparationSpec(int iSkip)const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoContentData::GetCreateSeparationSpec(int iSkip){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoContentData::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoContentData::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ContentMetaData);

		for(i=0;i<nElem;i++){
			if (!GetContentMetaData(i).IsValid(level)) {
				vElem.AppendUnique(elm_ContentMetaData);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ElementColorParams);

		for(i=0;i<nElem;i++){
			if (!GetElementColorParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_ElementColorParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ImageCompressionParams);

		for(i=0;i<nElem;i++){
			if (!GetImageCompressionParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_ImageCompressionParams);
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
		nElem=NumChildElements(elm_SeparationSpec);

		for(i=0;i<nElem;i++){
			if (!GetSeparationSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_SeparationSpec);
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
	WString JDFAutoContentData::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ContentMetaData,ElementColorParams,ImageCompressionParams,ScreeningParams,SeparationSpec";
	};
}; // end namespace JDF
