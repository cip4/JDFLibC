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

 
#include "jdf/wrapper/AutoJDF/JDFAutoRunList.h"
#include "jdf/wrapper/JDFByteMap.h"
#include "jdf/wrapper/JDFDynamicInput.h"
#include "jdf/wrapper/JDFInsertSheet.h"
#include "jdf/wrapper/JDFLayoutElement.h"
#include "jdf/wrapper/JDFInterpretedPDLData.h"
#include "jdf/wrapper/JDFDisposition.h"
#include "jdf/wrapper/JDFPageList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRunList : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoRunList& JDFAutoRunList::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoRunList: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoRunList::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoRunList::ValidNodeNames()const{
	return L"*:,RunList";
};

bool JDFAutoRunList::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoRunList::init(){
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
	WString JDFAutoRunList::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ComponentGranularity,IsPage,PageCopies,SetCopies,Directory,DocNames,Docs,EndOfBundleItem,EndOfDocument,EndOfSet,FirstPage,LogicalPage,NDoc,NPage,NSet,PageListIndex,PageNames,Pages,RunTag")
	+WString(L",SetNames,Sets,SkipPage,Sorted");
};

/**
 typesafe validator
*/
	vWString JDFAutoRunList::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidComponentGranularity(level)) {
			vAtts.push_back(atr_ComponentGranularity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsPage(level)) {
			vAtts.push_back(atr_IsPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageCopies(level)) {
			vAtts.push_back(atr_PageCopies);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetCopies(level)) {
			vAtts.push_back(atr_SetCopies);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDirectory(level)) {
			vAtts.push_back(atr_Directory);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocNames(level)) {
			vAtts.push_back(atr_DocNames);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocs(level)) {
			vAtts.push_back(atr_Docs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEndOfBundleItem(level)) {
			vAtts.push_back(atr_EndOfBundleItem);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEndOfDocument(level)) {
			vAtts.push_back(atr_EndOfDocument);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEndOfSet(level)) {
			vAtts.push_back(atr_EndOfSet);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFirstPage(level)) {
			vAtts.push_back(atr_FirstPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLogicalPage(level)) {
			vAtts.push_back(atr_LogicalPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNDoc(level)) {
			vAtts.push_back(atr_NDoc);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNPage(level)) {
			vAtts.push_back(atr_NPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNSet(level)) {
			vAtts.push_back(atr_NSet);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageListIndex(level)) {
			vAtts.push_back(atr_PageListIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageNames(level)) {
			vAtts.push_back(atr_PageNames);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPages(level)) {
			vAtts.push_back(atr_Pages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunTag(level)) {
			vAtts.push_back(atr_RunTag);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetNames(level)) {
			vAtts.push_back(atr_SetNames);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSets(level)) {
			vAtts.push_back(atr_Sets);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSkipPage(level)) {
			vAtts.push_back(atr_SkipPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSorted(level)) {
			vAtts.push_back(atr_Sorted);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoRunList::ComponentGranularityString(){
		static const WString enums=WString(L"Unknown,Page,Document,Set,All,BundleItem");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoRunList::ComponentGranularityString(EnumComponentGranularity value){
		return ComponentGranularityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRunList::SetComponentGranularity( EnumComponentGranularity value){
	SetEnumAttribute(atr_ComponentGranularity,value,ComponentGranularityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRunList::EnumComponentGranularity JDFAutoRunList:: GetComponentGranularity() const {
	return (EnumComponentGranularity) GetEnumAttribute(atr_ComponentGranularity,ComponentGranularityString(),WString::emptyStr,ComponentGranularity_Document);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidComponentGranularity(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ComponentGranularity,ComponentGranularityString(),false);
	};
/**
* Set attribute IsPage
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetIsPage(bool value){
	SetAttribute(atr_IsPage,WString::valueOf(value));
};
/**
* Get bool attribute IsPage
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoRunList::GetIsPage() const {return GetBoolAttribute(atr_IsPage,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidIsPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsPage,AttributeType_boolean,false);
	};
/**
* Set attribute PageCopies
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetPageCopies(int value){
	SetAttribute(atr_PageCopies,WString::valueOf(value));
};
/**
* Get integer attribute PageCopies
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoRunList::GetPageCopies() const {
	return GetIntAttribute(atr_PageCopies,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidPageCopies(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageCopies,AttributeType_integer,false);
	};
/**
* Set attribute SetCopies
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetSetCopies(int value){
	SetAttribute(atr_SetCopies,WString::valueOf(value));
};
/**
* Get integer attribute SetCopies
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoRunList::GetSetCopies() const {
	return GetIntAttribute(atr_SetCopies,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidSetCopies(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetCopies,AttributeType_integer,false);
	};
/**
* Set attribute Directory
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetDirectory(const WString& value){
	SetAttribute(atr_Directory,value);
};
/**
* Get string attribute Directory
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRunList::GetDirectory() const {
	return GetAttribute(atr_Directory,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidDirectory(EnumValidationLevel level) const {
		return ValidAttribute(atr_Directory,AttributeType_URL,false);
	};
/**
* Set attribute DocNames
*@param NameRangeList value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetDocNames(const NameRangeList& value){
	SetAttribute(atr_DocNames,value.GetString());
};
/**
* Get range attribute DocNames
* @return NameRangeList the vaue of the attribute 
*/
	 NameRangeList JDFAutoRunList::GetDocNames() const {
	return GetAttribute(atr_DocNames,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidDocNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocNames,AttributeType_NameRangeList,false);
	};
/**
* Set attribute Docs
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetDocs(const JDFIntegerRangeList& value){
	SetAttribute(atr_Docs,value.GetString());
};
/**
* Get range attribute Docs
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoRunList::GetDocs() const {
	return GetAttribute(atr_Docs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidDocs(EnumValidationLevel level) const {
		return ValidAttribute(atr_Docs,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute EndOfBundleItem
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetEndOfBundleItem(bool value){
	SetAttribute(atr_EndOfBundleItem,WString::valueOf(value));
};
/**
* Get bool attribute EndOfBundleItem
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoRunList::GetEndOfBundleItem() const {return GetBoolAttribute(atr_EndOfBundleItem,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidEndOfBundleItem(EnumValidationLevel level) const {
		return ValidAttribute(atr_EndOfBundleItem,AttributeType_boolean,false);
	};
/**
* Set attribute EndOfDocument
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetEndOfDocument(bool value){
	SetAttribute(atr_EndOfDocument,WString::valueOf(value));
};
/**
* Get bool attribute EndOfDocument
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoRunList::GetEndOfDocument() const {return GetBoolAttribute(atr_EndOfDocument,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidEndOfDocument(EnumValidationLevel level) const {
		return ValidAttribute(atr_EndOfDocument,AttributeType_boolean,false);
	};
/**
* Set attribute EndOfSet
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetEndOfSet(bool value){
	SetAttribute(atr_EndOfSet,WString::valueOf(value));
};
/**
* Get bool attribute EndOfSet
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoRunList::GetEndOfSet() const {return GetBoolAttribute(atr_EndOfSet,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidEndOfSet(EnumValidationLevel level) const {
		return ValidAttribute(atr_EndOfSet,AttributeType_boolean,false);
	};
/**
* Set attribute FirstPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetFirstPage(int value){
	SetAttribute(atr_FirstPage,WString::valueOf(value));
};
/**
* Get integer attribute FirstPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoRunList::GetFirstPage() const {
	return GetIntAttribute(atr_FirstPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidFirstPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_FirstPage,AttributeType_integer,false);
	};
/**
* Set attribute LogicalPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetLogicalPage(int value){
	SetAttribute(atr_LogicalPage,WString::valueOf(value));
};
/**
* Get integer attribute LogicalPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoRunList::GetLogicalPage() const {
	return GetIntAttribute(atr_LogicalPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidLogicalPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_LogicalPage,AttributeType_integer,false);
	};
/**
* Set attribute NDoc
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetNDoc(int value){
	SetAttribute(atr_NDoc,WString::valueOf(value));
};
/**
* Get integer attribute NDoc
* @return int the vaue of the attribute 
*/
	 int JDFAutoRunList::GetNDoc() const {
	return GetIntAttribute(atr_NDoc,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidNDoc(EnumValidationLevel level) const {
		return ValidAttribute(atr_NDoc,AttributeType_integer,false);
	};
/**
* Set attribute NPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetNPage(int value){
	SetAttribute(atr_NPage,WString::valueOf(value));
};
/**
* Get integer attribute NPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoRunList::GetNPage() const {
	return GetIntAttribute(atr_NPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidNPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_NPage,AttributeType_integer,false);
	};
/**
* Set attribute NSet
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetNSet(int value){
	SetAttribute(atr_NSet,WString::valueOf(value));
};
/**
* Get integer attribute NSet
* @return int the vaue of the attribute 
*/
	 int JDFAutoRunList::GetNSet() const {
	return GetIntAttribute(atr_NSet,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidNSet(EnumValidationLevel level) const {
		return ValidAttribute(atr_NSet,AttributeType_integer,false);
	};
/**
* Set attribute PageListIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetPageListIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageListIndex,value.GetString());
};
/**
* Get range attribute PageListIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoRunList::GetPageListIndex() const {
	return GetAttribute(atr_PageListIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidPageListIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageListIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute PageNames
*@param NameRangeList value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetPageNames(const NameRangeList& value){
	SetAttribute(atr_PageNames,value.GetString());
};
/**
* Get range attribute PageNames
* @return NameRangeList the vaue of the attribute 
*/
	 NameRangeList JDFAutoRunList::GetPageNames() const {
	return GetAttribute(atr_PageNames,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidPageNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageNames,AttributeType_NameRangeList,false);
	};
/**
* Set attribute Pages
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetPages(const JDFIntegerRangeList& value){
	SetAttribute(atr_Pages,value.GetString());
};
/**
* Get range attribute Pages
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoRunList::GetPages() const {
	return GetAttribute(atr_Pages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_Pages,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute RunTag
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetRunTag(const WString& value){
	SetAttribute(atr_RunTag,value);
};
/**
* Get string attribute RunTag
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRunList::GetRunTag() const {
	return GetAttribute(atr_RunTag,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidRunTag(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunTag,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute SetNames
*@param NameRangeList value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetSetNames(const NameRangeList& value){
	SetAttribute(atr_SetNames,value.GetString());
};
/**
* Get range attribute SetNames
* @return NameRangeList the vaue of the attribute 
*/
	 NameRangeList JDFAutoRunList::GetSetNames() const {
	return GetAttribute(atr_SetNames,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidSetNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetNames,AttributeType_NameRangeList,false);
	};
/**
* Set attribute Sets
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetSets(const JDFIntegerRangeList& value){
	SetAttribute(atr_Sets,value.GetString());
};
/**
* Get range attribute Sets
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoRunList::GetSets() const {
	return GetAttribute(atr_Sets,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidSets(EnumValidationLevel level) const {
		return ValidAttribute(atr_Sets,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SkipPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetSkipPage(int value){
	SetAttribute(atr_SkipPage,WString::valueOf(value));
};
/**
* Get integer attribute SkipPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoRunList::GetSkipPage() const {
	return GetIntAttribute(atr_SkipPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidSkipPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_SkipPage,AttributeType_integer,false);
	};
/**
* Set attribute Sorted
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoRunList::SetSorted(bool value){
	SetAttribute(atr_Sorted,WString::valueOf(value));
};
/**
* Get bool attribute Sorted
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoRunList::GetSorted() const {return GetBoolAttribute(atr_Sorted,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRunList::ValidSorted(EnumValidationLevel level) const {
		return ValidAttribute(atr_Sorted,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFByteMap JDFAutoRunList::GetByteMap()const{
	JDFByteMap e=GetElement(elm_ByteMap);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFByteMap JDFAutoRunList::GetCreateByteMap(){
	JDFByteMap e=GetCreateElement(elm_ByteMap);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFByteMap JDFAutoRunList::AppendByteMap(){
	JDFByteMap e=AppendElementN(elm_ByteMap,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoRunList::RefByteMap(JDFByteMap& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDynamicInput JDFAutoRunList::GetDynamicInput(int iSkip)const{
	JDFDynamicInput e=GetElement(elm_DynamicInput,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDynamicInput JDFAutoRunList::GetCreateDynamicInput(int iSkip){
	JDFDynamicInput e=GetCreateElement(elm_DynamicInput,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDynamicInput JDFAutoRunList::AppendDynamicInput(){
	JDFDynamicInput e=AppendElement(elm_DynamicInput);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoRunList::GetInsertSheet(int iSkip)const{
	JDFInsertSheet e=GetElement(elm_InsertSheet,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoRunList::GetCreateInsertSheet(int iSkip){
	JDFInsertSheet e=GetCreateElement(elm_InsertSheet,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoRunList::AppendInsertSheet(){
	JDFInsertSheet e=AppendElement(elm_InsertSheet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoRunList::RefInsertSheet(JDFInsertSheet& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoRunList::GetLayoutElement()const{
	JDFLayoutElement e=GetElement(elm_LayoutElement);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoRunList::GetCreateLayoutElement(){
	JDFLayoutElement e=GetCreateElement(elm_LayoutElement);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoRunList::AppendLayoutElement(){
	JDFLayoutElement e=AppendElementN(elm_LayoutElement,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoRunList::RefLayoutElement(JDFLayoutElement& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFInterpretedPDLData JDFAutoRunList::GetInterpretedPDLData()const{
	JDFInterpretedPDLData e=GetElement(elm_InterpretedPDLData);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInterpretedPDLData JDFAutoRunList::GetCreateInterpretedPDLData(){
	JDFInterpretedPDLData e=GetCreateElement(elm_InterpretedPDLData);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInterpretedPDLData JDFAutoRunList::AppendInterpretedPDLData(){
	JDFInterpretedPDLData e=AppendElementN(elm_InterpretedPDLData,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoRunList::RefInterpretedPDLData(JDFInterpretedPDLData& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoRunList::GetDispositionElem()const{
	JDFDisposition e=GetElement(elm_Disposition);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoRunList::GetCreateDispositionElem(){
	JDFDisposition e=GetCreateElement(elm_Disposition);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoRunList::AppendDispositionElem(){
	JDFDisposition e=AppendElementN(elm_Disposition,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoRunList::GetPageList()const{
	JDFPageList e=GetElement(elm_PageList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoRunList::GetCreatePageList(){
	JDFPageList e=GetCreateElement(elm_PageList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoRunList::AppendPageList(){
	JDFPageList e=AppendElementN(elm_PageList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoRunList::RefPageList(JDFPageList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoRunList::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ByteMap);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ByteMap);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetByteMap().IsValid(level)) {
				vElem.AppendUnique(elm_ByteMap);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_DynamicInput);

		for(i=0;i<nElem;i++){
			if (!GetDynamicInput(i).IsValid(level)) {
				vElem.AppendUnique(elm_DynamicInput);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_InsertSheet);

		for(i=0;i<nElem;i++){
			if (!GetInsertSheet(i).IsValid(level)) {
				vElem.AppendUnique(elm_InsertSheet);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_LayoutElement);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_LayoutElement);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetLayoutElement().IsValid(level)) {
				vElem.AppendUnique(elm_LayoutElement);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_InterpretedPDLData);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_InterpretedPDLData);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetInterpretedPDLData().IsValid(level)) {
				vElem.AppendUnique(elm_InterpretedPDLData);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Disposition);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Disposition);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDispositionElem().IsValid(level)) {
				vElem.AppendUnique(elm_Disposition);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PageList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PageList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPageList().IsValid(level)) {
				vElem.AppendUnique(elm_PageList);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoRunList::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ByteMap,LayoutElement,InterpretedPDLData,Disposition,PageList";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoRunList::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ByteMap,DynamicInput,InsertSheet,LayoutElement,InterpretedPDLData,Disposition,PageList";
	};
}; // end namespace JDF
