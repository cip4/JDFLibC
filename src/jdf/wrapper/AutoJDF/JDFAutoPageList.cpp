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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPageList.h"
#include "jdf/wrapper/JDFAssembly.h"
#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFContentList.h"
#include "jdf/wrapper/JDFImageCompressionParams.h"
#include "jdf/wrapper/JDFPageData.h"
#include "jdf/wrapper/JDFScreeningParams.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFElementColorParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPageList : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPageList& JDFAutoPageList::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPageList: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPageList::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPageList::ValidNodeNames()const{
	return L"*:,PageList";
};

bool JDFAutoPageList::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPageList::init(){
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
	WString JDFAutoPageList::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Template,AssemblyID,AssemblyIDs,HasBleeds,IsBlank,IsPrintable,IsTrapped,JobID,PageLabelPrefix,PageLabelSuffix,SourceBleedBox,SourceClipBox,SourceTrimBox");
};

/**
 typesafe validator
*/
	vWString JDFAutoPageList::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTemplate(level)) {
			vAtts.push_back(atr_Template);
			if(++n>=nMax)
				return vAtts;
		};
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
		return vAtts;
	};

/**
* Set attribute Template
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetTemplate(bool value){
	SetAttribute(atr_Template,WString::valueOf(value));
};
/**
* Get bool attribute Template
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPageList::GetTemplate() const {return GetBoolAttribute(atr_Template,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_Template,AttributeType_boolean,false);
	};
/**
* Set attribute AssemblyID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetAssemblyID(const WString& value){
	SetAttribute(atr_AssemblyID,value);
};
/**
* Get string attribute AssemblyID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageList::GetAssemblyID() const {
	return GetAttribute(atr_AssemblyID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidAssemblyID(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyID,AttributeType_string,false);
	};
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPageList::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute HasBleeds
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetHasBleeds(bool value){
	SetAttribute(atr_HasBleeds,WString::valueOf(value));
};
/**
* Get bool attribute HasBleeds
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageList::GetHasBleeds() const {return GetBoolAttribute(atr_HasBleeds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidHasBleeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasBleeds,AttributeType_boolean,false);
	};
/**
* Set attribute IsBlank
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetIsBlank(bool value){
	SetAttribute(atr_IsBlank,WString::valueOf(value));
};
/**
* Get bool attribute IsBlank
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageList::GetIsBlank() const {return GetBoolAttribute(atr_IsBlank,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidIsBlank(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsBlank,AttributeType_boolean,false);
	};
/**
* Set attribute IsPrintable
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetIsPrintable(bool value){
	SetAttribute(atr_IsPrintable,WString::valueOf(value));
};
/**
* Get bool attribute IsPrintable
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageList::GetIsPrintable() const {return GetBoolAttribute(atr_IsPrintable,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidIsPrintable(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsPrintable,AttributeType_boolean,false);
	};
/**
* Set attribute IsTrapped
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetIsTrapped(bool value){
	SetAttribute(atr_IsTrapped,WString::valueOf(value));
};
/**
* Get bool attribute IsTrapped
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPageList::GetIsTrapped() const {return GetBoolAttribute(atr_IsTrapped,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidIsTrapped(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsTrapped,AttributeType_boolean,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageList::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute PageLabelPrefix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetPageLabelPrefix(const WString& value){
	SetAttribute(atr_PageLabelPrefix,value);
};
/**
* Get string attribute PageLabelPrefix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageList::GetPageLabelPrefix() const {
	return GetAttribute(atr_PageLabelPrefix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidPageLabelPrefix(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageLabelPrefix,AttributeType_string,false);
	};
/**
* Set attribute PageLabelSuffix
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetPageLabelSuffix(const WString& value){
	SetAttribute(atr_PageLabelSuffix,value);
};
/**
* Get string attribute PageLabelSuffix
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageList::GetPageLabelSuffix() const {
	return GetAttribute(atr_PageLabelSuffix,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidPageLabelSuffix(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageLabelSuffix,AttributeType_string,false);
	};
/**
* Set attribute SourceBleedBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetSourceBleedBox(const JDFRectangle& value){
	SetAttribute(atr_SourceBleedBox,value);
};
/**
* Get string attribute SourceBleedBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPageList::GetSourceBleedBox() const {
	return GetAttribute(atr_SourceBleedBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidSourceBleedBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceBleedBox,AttributeType_rectangle,false);
	};
/**
* Set attribute SourceClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetSourceClipBox(const JDFRectangle& value){
	SetAttribute(atr_SourceClipBox,value);
};
/**
* Get string attribute SourceClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPageList::GetSourceClipBox() const {
	return GetAttribute(atr_SourceClipBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidSourceClipBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceClipBox,AttributeType_rectangle,false);
	};
/**
* Set attribute SourceTrimBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPageList::SetSourceTrimBox(const JDFRectangle& value){
	SetAttribute(atr_SourceTrimBox,value);
};
/**
* Get string attribute SourceTrimBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPageList::GetSourceTrimBox() const {
	return GetAttribute(atr_SourceTrimBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageList::ValidSourceTrimBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceTrimBox,AttributeType_rectangle,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAssembly JDFAutoPageList::GetAssembly(int iSkip)const{
	JDFAssembly e=GetElement(elm_Assembly,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAssembly JDFAutoPageList::GetCreateAssembly(int iSkip){
	JDFAssembly e=GetCreateElement(elm_Assembly,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAssembly JDFAutoPageList::AppendAssembly(){
	JDFAssembly e=AppendElement(elm_Assembly);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageList::RefAssembly(JDFAssembly& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoPageList::GetColorPool(int iSkip)const{
	JDFColorPool e=GetElement(elm_ColorPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoPageList::GetCreateColorPool(int iSkip){
	JDFColorPool e=GetCreateElement(elm_ColorPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoPageList::AppendColorPool(){
	JDFColorPool e=AppendElement(elm_ColorPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageList::RefColorPool(JDFColorPool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFContentList JDFAutoPageList::GetContentList(int iSkip)const{
	JDFContentList e=GetElement(elm_ContentList,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContentList JDFAutoPageList::GetCreateContentList(int iSkip){
	JDFContentList e=GetCreateElement(elm_ContentList,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContentList JDFAutoPageList::AppendContentList(){
	JDFContentList e=AppendElement(elm_ContentList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageList::RefContentList(JDFContentList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoPageList::GetImageCompressionParams(int iSkip)const{
	JDFImageCompressionParams e=GetElement(elm_ImageCompressionParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoPageList::GetCreateImageCompressionParams(int iSkip){
	JDFImageCompressionParams e=GetCreateElement(elm_ImageCompressionParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoPageList::AppendImageCompressionParams(){
	JDFImageCompressionParams e=AppendElement(elm_ImageCompressionParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageList::RefImageCompressionParams(JDFImageCompressionParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPageData JDFAutoPageList::GetPageData(int iSkip)const{
	JDFPageData e=GetElement(elm_PageData,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageData JDFAutoPageList::GetCreatePageData(int iSkip){
	JDFPageData e=GetCreateElement(elm_PageData,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageData JDFAutoPageList::AppendPageData(){
	JDFPageData e=AppendElement(elm_PageData);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoPageList::GetScreeningParams(int iSkip)const{
	JDFScreeningParams e=GetElement(elm_ScreeningParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoPageList::GetCreateScreeningParams(int iSkip){
	JDFScreeningParams e=GetCreateElement(elm_ScreeningParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoPageList::AppendScreeningParams(){
	JDFScreeningParams e=AppendElement(elm_ScreeningParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageList::RefScreeningParams(JDFScreeningParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoPageList::GetSeparationSpec(int iSkip)const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoPageList::GetCreateSeparationSpec(int iSkip){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoPageList::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageList::RefSeparationSpec(JDFSeparationSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoPageList::GetElementColorParams(int iSkip)const{
	JDFElementColorParams e=GetElement(elm_ElementColorParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoPageList::GetCreateElementColorParams(int iSkip){
	JDFElementColorParams e=GetCreateElement(elm_ElementColorParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoPageList::AppendElementColorParams(){
	JDFElementColorParams e=AppendElement(elm_ElementColorParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageList::RefElementColorParams(JDFElementColorParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPageList::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Assembly);

		for(i=0;i<nElem;i++){
			if (!GetAssembly(i).IsValid(level)) {
				vElem.AppendUnique(elm_Assembly);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ColorPool);

		for(i=0;i<nElem;i++){
			if (!GetColorPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ContentList);

		for(i=0;i<nElem;i++){
			if (!GetContentList(i).IsValid(level)) {
				vElem.AppendUnique(elm_ContentList);
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
		nElem=NumChildElements(elm_PageData);

		for(i=0;i<nElem;i++){
			if (!GetPageData(i).IsValid(level)) {
				vElem.AppendUnique(elm_PageData);
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
		nElem=NumChildElements(elm_ElementColorParams);

		for(i=0;i<nElem;i++){
			if (!GetElementColorParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_ElementColorParams);
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
	WString JDFAutoPageList::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Assembly,ColorPool,ContentList,ImageCompressionParams,PageData,ScreeningParams,SeparationSpec,ElementColorParams";
	};
}; // end namespace JDF
