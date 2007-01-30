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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPageData.h"
#include "jdf/wrapper/JDFElementColorParams.h"
#include "jdf/wrapper/JDFImageCompressionParams.h"
#include "jdf/wrapper/JDFPageElement.h"
#include "jdf/wrapper/JDFScreeningParams.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPageData : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPageData& JDFAutoPageData::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPageData: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPageData::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPageData::ValidNodeNames()const{
	return L"*:,PageData";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPageData::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AssemblyID,AssemblyIDs,CatalogID,CatalogDetails,FoldOutPages,HasBleeds,IsBlank,IsPrintable,IsTrapped,JobID,PageFormat,PageLabel,PageLabelPrefix,PageLabelSuffix,PageStatus,ProductID,SourceBleedBox,SourceClipBox,SourceTrimBox")
	+WString(L",Template");
};

/**
 typesafe validator
*/
	vWString JDFAutoPageData::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAssemblyID(level)) {
			vAtts.push_back(atr_AssemblyID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAssemblyIDs(level)) {
			vAtts.push_back(atr_AssemblyIDs);
			if(++n>=nMax)
				return vAtts;
		};
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
		if(!ValidFoldOutPages(level)) {
			vAtts.push_back(atr_FoldOutPages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasBleeds(level)) {
			vAtts.push_back(atr_HasBleeds);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsBlank(level)) {
			vAtts.push_back(atr_IsBlank);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsPrintable(level)) {
			vAtts.push_back(atr_IsPrintable);
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
		if(!ValidPageFormat(level)) {
			vAtts.push_back(atr_PageFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageLabel(level)) {
			vAtts.push_back(atr_PageLabel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageLabelPrefix(level)) {
			vAtts.push_back(atr_PageLabelPrefix);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageLabelSuffix(level)) {
			vAtts.push_back(atr_PageLabelSuffix);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageStatus(level)) {
			vAtts.push_back(atr_PageStatus);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductID(level)) {
			vAtts.push_back(atr_ProductID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceBleedBox(level)) {
			vAtts.push_back(atr_SourceBleedBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceClipBox(level)) {
			vAtts.push_back(atr_SourceClipBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceTrimBox(level)) {
			vAtts.push_back(atr_SourceTrimBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTemplate(level)) {
			vAtts.push_back(atr_Template);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AssemblyID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetAssemblyID(const WString& value){
	SetAttribute(atr_AssemblyID,value);
};
/**
* Get string attribute AssemblyID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetAssemblyID() const {
	return GetAttribute(atr_AssemblyID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidAssemblyID(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyID,AttributeType_string,false);
	};
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPageData::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute CatalogID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetCatalogID(const WString& value){
	SetAttribute(atr_CatalogID,value);
};
/**
* Get string attribute CatalogID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetCatalogID() const {
	return GetAttribute(atr_CatalogID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidCatalogID(EnumValidationLevel level) const {
		return ValidAttribute(atr_CatalogID,AttributeType_shortString,false);
	};
/**
* Set attribute CatalogDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetCatalogDetails(const WString& value){
	SetAttribute(atr_CatalogDetails,value);
};
/**
* Get string attribute CatalogDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetCatalogDetails() const {
	return GetAttribute(atr_CatalogDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidCatalogDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_CatalogDetails,AttributeType_string,false);
	};
/**
* Set attribute FoldOutPages
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetFoldOutPages(const JDFIntegerList& value){
	SetAttribute(atr_FoldOutPages,value.GetString());
};
/**
* Get string attribute FoldOutPages
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoPageData::GetFoldOutPages() const {
	return GetAttribute(atr_FoldOutPages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidFoldOutPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_FoldOutPages,AttributeType_IntegerList,false);
	};
/**
* Set attribute HasBleeds
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetHasBleeds(bool value){
	SetAttribute(atr_HasBleeds,WString::valueOf(value));
};
/**
* Get bool attribute HasBleeds
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageData::GetHasBleeds() const {return GetBoolAttribute(atr_HasBleeds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidHasBleeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasBleeds,AttributeType_boolean,false);
	};
/**
* Set attribute IsBlank
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetIsBlank(bool value){
	SetAttribute(atr_IsBlank,WString::valueOf(value));
};
/**
* Get bool attribute IsBlank
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageData::GetIsBlank() const {return GetBoolAttribute(atr_IsBlank,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidIsBlank(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsBlank,AttributeType_boolean,false);
	};
/**
* Set attribute IsPrintable
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetIsPrintable(bool value){
	SetAttribute(atr_IsPrintable,WString::valueOf(value));
};
/**
* Get bool attribute IsPrintable
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageData::GetIsPrintable() const {return GetBoolAttribute(atr_IsPrintable,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidIsPrintable(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsPrintable,AttributeType_boolean,false);
	};
/**
* Set attribute IsTrapped
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetIsTrapped(bool value){
	SetAttribute(atr_IsTrapped,WString::valueOf(value));
};
/**
* Get bool attribute IsTrapped
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageData::GetIsTrapped() const {return GetBoolAttribute(atr_IsTrapped,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidIsTrapped(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsTrapped,AttributeType_boolean,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute PageFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetPageFormat(const WString& value){
	SetAttribute(atr_PageFormat,value);
};
/**
* Get string attribute PageFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetPageFormat() const {
	return GetAttribute(atr_PageFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidPageFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageFormat,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute PageLabel
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetPageLabel(const WString& value){
	SetAttribute(atr_PageLabel,value);
};
/**
* Get string attribute PageLabel
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetPageLabel() const {
	return GetAttribute(atr_PageLabel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidPageLabel(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageLabel,AttributeType_string,false);
	};
/**
* Set attribute PageLabelPrefix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetPageLabelPrefix(const WString& value){
	SetAttribute(atr_PageLabelPrefix,value);
};
/**
* Get string attribute PageLabelPrefix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetPageLabelPrefix() const {
	return GetAttribute(atr_PageLabelPrefix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidPageLabelPrefix(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageLabelPrefix,AttributeType_string,false);
	};
/**
* Set attribute PageLabelSuffix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetPageLabelSuffix(const WString& value){
	SetAttribute(atr_PageLabelSuffix,value);
};
/**
* Get string attribute PageLabelSuffix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetPageLabelSuffix() const {
	return GetAttribute(atr_PageLabelSuffix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidPageLabelSuffix(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageLabelSuffix,AttributeType_string,false);
	};
/**
* Set attribute PageStatus
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetPageStatus(const WString& value){
	SetAttribute(atr_PageStatus,value);
};
/**
* Get string attribute PageStatus
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetPageStatus() const {
	return GetAttribute(atr_PageStatus,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidPageStatus(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageStatus,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ProductID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetProductID(const WString& value){
	SetAttribute(atr_ProductID,value);
};
/**
* Get string attribute ProductID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageData::GetProductID() const {
	return GetAttribute(atr_ProductID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidProductID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductID,AttributeType_shortString,false);
	};
/**
* Set attribute SourceBleedBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetSourceBleedBox(const JDFRectangle& value){
	SetAttribute(atr_SourceBleedBox,value);
};
/**
* Get string attribute SourceBleedBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPageData::GetSourceBleedBox() const {
	return GetAttribute(atr_SourceBleedBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidSourceBleedBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceBleedBox,AttributeType_rectangle,false);
	};
/**
* Set attribute SourceClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetSourceClipBox(const JDFRectangle& value){
	SetAttribute(atr_SourceClipBox,value);
};
/**
* Get string attribute SourceClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPageData::GetSourceClipBox() const {
	return GetAttribute(atr_SourceClipBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidSourceClipBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceClipBox,AttributeType_rectangle,false);
	};
/**
* Set attribute SourceTrimBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetSourceTrimBox(const JDFRectangle& value){
	SetAttribute(atr_SourceTrimBox,value);
};
/**
* Get string attribute SourceTrimBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPageData::GetSourceTrimBox() const {
	return GetAttribute(atr_SourceTrimBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidSourceTrimBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceTrimBox,AttributeType_rectangle,false);
	};
/**
* Set attribute Template
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageData::SetTemplate(bool value){
	SetAttribute(atr_Template,WString::valueOf(value));
};
/**
* Get bool attribute Template
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageData::GetTemplate() const {return GetBoolAttribute(atr_Template,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageData::ValidTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_Template,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFElementColorParams JDFAutoPageData::GetElementColorParams(int iSkip)const{
	JDFElementColorParams e=GetElement(elm_ElementColorParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoPageData::GetCreateElementColorParams(int iSkip){
	JDFElementColorParams e=GetCreateElement(elm_ElementColorParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoPageData::AppendElementColorParams(){
	JDFElementColorParams e=AppendElement(elm_ElementColorParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageData::RefElementColorParams(JDFElementColorParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoPageData::GetImageCompressionParams(int iSkip)const{
	JDFImageCompressionParams e=GetElement(elm_ImageCompressionParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoPageData::GetCreateImageCompressionParams(int iSkip){
	JDFImageCompressionParams e=GetCreateElement(elm_ImageCompressionParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoPageData::AppendImageCompressionParams(){
	JDFImageCompressionParams e=AppendElement(elm_ImageCompressionParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageData::RefImageCompressionParams(JDFImageCompressionParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPageElement JDFAutoPageData::GetPageElement(int iSkip)const{
	JDFPageElement e=GetElement(elm_PageElement,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageElement JDFAutoPageData::GetCreatePageElement(int iSkip){
	JDFPageElement e=GetCreateElement(elm_PageElement,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageElement JDFAutoPageData::AppendPageElement(){
	JDFPageElement e=AppendElement(elm_PageElement);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoPageData::GetScreeningParams(int iSkip)const{
	JDFScreeningParams e=GetElement(elm_ScreeningParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoPageData::GetCreateScreeningParams(int iSkip){
	JDFScreeningParams e=GetCreateElement(elm_ScreeningParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoPageData::AppendScreeningParams(){
	JDFScreeningParams e=AppendElement(elm_ScreeningParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageData::RefScreeningParams(JDFScreeningParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoPageData::GetSeparationSpec(int iSkip)const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoPageData::GetCreateSeparationSpec(int iSkip){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoPageData::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageData::RefSeparationSpec(JDFSeparationSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPageData::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
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
		nElem=NumChildElements(elm_PageElement);

		for(i=0;i<nElem;i++){
			if (!GetPageElement(i).IsValid(level)) {
				vElem.AppendUnique(elm_PageElement);
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
	WString JDFAutoPageData::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ElementColorParams,ImageCompressionParams,PageElement,ScreeningParams,SeparationSpec";
	};
}; // end namespace JDF
