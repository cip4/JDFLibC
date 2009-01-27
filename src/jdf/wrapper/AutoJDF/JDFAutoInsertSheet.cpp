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

 
#include "jdf/wrapper/AutoJDF/JDFAutoInsertSheet.h"
#include "jdf/wrapper/JDFRunList.h"
#include "jdf/wrapper/JDFLayout.h"
#include "jdf/wrapper/JDFSheet.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoInsertSheet : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoInsertSheet& JDFAutoInsertSheet::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoInsertSheet: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoInsertSheet::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoInsertSheet::ValidNodeNames()const{
	return L"*:,InsertSheet";
};

bool JDFAutoInsertSheet::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoInsertSheet::init(){
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
	WString JDFAutoInsertSheet::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",SheetType,SheetUsage";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoInsertSheet::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",IncludeInBundleItem,IsWaste,MarkList,SheetFormat,Usage");
};

/**
 typesafe validator
*/
	vWString JDFAutoInsertSheet::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidSheetType(level)) {
			vAtts.push_back(atr_SheetType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetUsage(level)) {
			vAtts.push_back(atr_SheetUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIncludeInBundleItem(level)) {
			vAtts.push_back(atr_IncludeInBundleItem);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsWaste(level)) {
			vAtts.push_back(atr_IsWaste);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkList(level)) {
			vAtts.push_back(atr_MarkList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetFormat(level)) {
			vAtts.push_back(atr_SheetFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUsage(level)) {
			vAtts.push_back(atr_Usage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInsertSheet::SheetTypeString(){
		static const WString enums=WString(L"Unknown,AccountingSheet,ErrorSheet,FillSheet,InsertSheet,JobSheet,SeparatorSheet");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInsertSheet::SheetTypeString(EnumSheetType value){
		return SheetTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInsertSheet::SetSheetType( EnumSheetType value){
	SetEnumAttribute(atr_SheetType,value,SheetTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInsertSheet::EnumSheetType JDFAutoInsertSheet:: GetSheetType() const {
	return (EnumSheetType) GetEnumAttribute(atr_SheetType,SheetTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertSheet::ValidSheetType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetType,SheetTypeString(),RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInsertSheet::SheetUsageString(){
		static const WString enums=WString(L"Unknown,FillForceBack,FillForceFront,FillSheet,FillSignature,FillSurface,Header,Interleaved,InterleavedBefore,OnError")
	+WString(L",Slip,SlipCopy,Trailer");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInsertSheet::SheetUsageString(EnumSheetUsage value){
		return SheetUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInsertSheet::SetSheetUsage( EnumSheetUsage value){
	SetEnumAttribute(atr_SheetUsage,value,SheetUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInsertSheet::EnumSheetUsage JDFAutoInsertSheet:: GetSheetUsage() const {
	return (EnumSheetUsage) GetEnumAttribute(atr_SheetUsage,SheetUsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertSheet::ValidSheetUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetUsage,SheetUsageString(),RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInsertSheet::IncludeInBundleItemString(){
		static const WString enums=WString(L"Unknown,After,Before,None,New");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInsertSheet::IncludeInBundleItemString(EnumIncludeInBundleItem value){
		return IncludeInBundleItemString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInsertSheet::SetIncludeInBundleItem( EnumIncludeInBundleItem value){
	SetEnumAttribute(atr_IncludeInBundleItem,value,IncludeInBundleItemString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInsertSheet::EnumIncludeInBundleItem JDFAutoInsertSheet:: GetIncludeInBundleItem() const {
	return (EnumIncludeInBundleItem) GetEnumAttribute(atr_IncludeInBundleItem,IncludeInBundleItemString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertSheet::ValidIncludeInBundleItem(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_IncludeInBundleItem,IncludeInBundleItemString(),false);
	};
/**
* Set attribute IsWaste
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoInsertSheet::SetIsWaste(bool value){
	SetAttribute(atr_IsWaste,WString::valueOf(value));
};
/**
* Get bool attribute IsWaste
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoInsertSheet::GetIsWaste() const {return GetBoolAttribute(atr_IsWaste,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertSheet::ValidIsWaste(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsWaste,AttributeType_boolean,false);
	};
/**
* Set attribute MarkList
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoInsertSheet::SetMarkList(const vWString& value){
	SetAttribute(atr_MarkList,value);
};
/**
* Get string attribute MarkList
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoInsertSheet::GetMarkList() const {
	return GetAttribute(atr_MarkList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertSheet::ValidMarkList(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarkList,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute SheetFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoInsertSheet::SetSheetFormat(const WString& value){
	SetAttribute(atr_SheetFormat,value);
};
/**
* Get string attribute SheetFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoInsertSheet::GetSheetFormat() const {
	return GetAttribute(atr_SheetFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertSheet::ValidSheetFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetFormat,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInsertSheet::UsageString(){
		static const WString enums=WString(L"Unknown,FillForceBack,FillForceFront,FillSheet,FillSignature,FillSurface,Header,Interleaved,InterleavedBefore,OnError")
	+WString(L",Slip,SlipCopy,Trailer");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInsertSheet::UsageString(EnumUsage value){
		return UsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInsertSheet::SetUsage( EnumUsage value){
	SetEnumAttribute(atr_Usage,value,UsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInsertSheet::EnumUsage JDFAutoInsertSheet:: GetUsage() const {
	return (EnumUsage) GetEnumAttribute(atr_Usage,UsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertSheet::ValidUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Usage,UsageString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFRunList JDFAutoInsertSheet::GetRunList()const{
	JDFRunList e=GetElement(elm_RunList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoInsertSheet::GetCreateRunList(){
	JDFRunList e=GetCreateElement(elm_RunList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoInsertSheet::AppendRunList(){
	JDFRunList e=AppendElementN(elm_RunList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoInsertSheet::RefRunList(JDFRunList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoInsertSheet::GetLayout()const{
	JDFLayout e=GetElement(elm_Layout);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoInsertSheet::GetCreateLayout(){
	JDFLayout e=GetCreateElement(elm_Layout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoInsertSheet::AppendLayout(){
	JDFLayout e=AppendElementN(elm_Layout,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoInsertSheet::RefLayout(JDFLayout& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSheet JDFAutoInsertSheet::GetSheet()const{
	JDFSheet e=GetElement(elm_Sheet);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSheet JDFAutoInsertSheet::GetCreateSheet(){
	JDFSheet e=GetCreateElement(elm_Sheet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSheet JDFAutoInsertSheet::AppendSheet(){
	JDFSheet e=AppendElementN(elm_Sheet,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoInsertSheet::RefSheet(JDFSheet& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoInsertSheet::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_RunList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_RunList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetRunList().IsValid(level)) {
				vElem.AppendUnique(elm_RunList);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Layout);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Layout);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetLayout().IsValid(level)) {
				vElem.AppendUnique(elm_Layout);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Sheet);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Sheet);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetSheet().IsValid(level)) {
				vElem.AppendUnique(elm_Sheet);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoInsertSheet::UniqueElements()const{
		return JDFResource::UniqueElements()+L",RunList,Layout,Sheet";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoInsertSheet::OptionalElements()const{
		return JDFResource::OptionalElements()+L",RunList,Layout,Sheet";
	};
}; // end namespace JDF
