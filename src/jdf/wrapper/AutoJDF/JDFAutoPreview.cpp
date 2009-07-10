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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreview.h"
#include "jdf/wrapper/JDFComment.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreview : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreview& JDFAutoPreview::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreview: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreview::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreview::ValidNodeNames()const{
	return L"*:,Preview";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPreview::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PreviewFileType,PreviewUsage,URL,NoOp,Class,PartUsage,Compensation,CTM,Directory,MimeTypeDetails,BinderySignatureName,BlockName,BundleItemIndex,CellIndex,Condition,DeliveryUnit0,DeliveryUnit1,DeliveryUnit2,DeliveryUnit3")
	+WString(L",DeliveryUnit4,DeliveryUnit5,DeliveryUnit6,DeliveryUnit7,DeliveryUnit8,DeliveryUnit9,DocTags,Edition,EditionVersion,ItemNames,PageNumber,PageTags,PlateLayout,PreflightRule,RunSet,SectionIndex,SetDocIndex,SetRunIndex,SetSheetIndex")
	+WString(L",SetTags,SubRun,WebProduct,WebSetup");
};

/**
 typesafe validator
*/
	vWString JDFAutoPreview::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPreviewFileType(level)) {
			vAtts.push_back(atr_PreviewFileType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreviewUsage(level)) {
			vAtts.push_back(atr_PreviewUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURL(level)) {
			vAtts.push_back(atr_URL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNoOp(level)) {
			vAtts.push_back(atr_NoOp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClass(level)) {
			vAtts.push_back(atr_Class);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPartUsage(level)) {
			vAtts.push_back(atr_PartUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompensation(level)) {
			vAtts.push_back(atr_Compensation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCTM(level)) {
			vAtts.push_back(atr_CTM);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDirectory(level)) {
			vAtts.push_back(atr_Directory);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMimeTypeDetails(level)) {
			vAtts.push_back(atr_MimeTypeDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBinderySignatureName(level)) {
			vAtts.push_back(atr_BinderySignatureName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockName(level)) {
			vAtts.push_back(atr_BlockName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBundleItemIndex(level)) {
			vAtts.push_back(atr_BundleItemIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCellIndex(level)) {
			vAtts.push_back(atr_CellIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCondition(level)) {
			vAtts.push_back(atr_Condition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit0(level)) {
			vAtts.push_back(atr_DeliveryUnit0);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit1(level)) {
			vAtts.push_back(atr_DeliveryUnit1);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit2(level)) {
			vAtts.push_back(atr_DeliveryUnit2);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit3(level)) {
			vAtts.push_back(atr_DeliveryUnit3);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit4(level)) {
			vAtts.push_back(atr_DeliveryUnit4);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit5(level)) {
			vAtts.push_back(atr_DeliveryUnit5);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit6(level)) {
			vAtts.push_back(atr_DeliveryUnit6);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit7(level)) {
			vAtts.push_back(atr_DeliveryUnit7);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit8(level)) {
			vAtts.push_back(atr_DeliveryUnit8);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDeliveryUnit9(level)) {
			vAtts.push_back(atr_DeliveryUnit9);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocTags(level)) {
			vAtts.push_back(atr_DocTags);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEdition(level)) {
			vAtts.push_back(atr_Edition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEditionVersion(level)) {
			vAtts.push_back(atr_EditionVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidItemNames(level)) {
			vAtts.push_back(atr_ItemNames);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageNumber(level)) {
			vAtts.push_back(atr_PageNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageTags(level)) {
			vAtts.push_back(atr_PageTags);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPlateLayout(level)) {
			vAtts.push_back(atr_PlateLayout);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreflightRule(level)) {
			vAtts.push_back(atr_PreflightRule);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunSet(level)) {
			vAtts.push_back(atr_RunSet);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSectionIndex(level)) {
			vAtts.push_back(atr_SectionIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetDocIndex(level)) {
			vAtts.push_back(atr_SetDocIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetRunIndex(level)) {
			vAtts.push_back(atr_SetRunIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetSheetIndex(level)) {
			vAtts.push_back(atr_SetSheetIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetTags(level)) {
			vAtts.push_back(atr_SetTags);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSubRun(level)) {
			vAtts.push_back(atr_SubRun);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWebProduct(level)) {
			vAtts.push_back(atr_WebProduct);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWebSetup(level)) {
			vAtts.push_back(atr_WebSetup);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreview::PreviewFileTypeString(){
		static const WString enums=WString(L"Unknown,PNG,CIP3Multiple,CIP3Single");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreview::PreviewFileTypeString(EnumPreviewFileType value){
		return PreviewFileTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreview::SetPreviewFileType( EnumPreviewFileType value){
	SetEnumAttribute(atr_PreviewFileType,value,PreviewFileTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreview::EnumPreviewFileType JDFAutoPreview:: GetPreviewFileType() const {
	return (EnumPreviewFileType) GetEnumAttribute(atr_PreviewFileType,PreviewFileTypeString(),WString::emptyStr,PreviewFileType_PNG);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPreviewFileType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreviewFileType,PreviewFileTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreview::PreviewUsageString(){
		static const WString enums=WString(L"Unknown,Separation,SeparatedThumbNail,SeparationRaw,ThumbNail,Viewable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreview::PreviewUsageString(EnumPreviewUsage value){
		return PreviewUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreview::SetPreviewUsage( EnumPreviewUsage value){
	SetEnumAttribute(atr_PreviewUsage,value,PreviewUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreview::EnumPreviewUsage JDFAutoPreview:: GetPreviewUsage() const {
	return (EnumPreviewUsage) GetEnumAttribute(atr_PreviewUsage,PreviewUsageString(),WString::emptyStr,PreviewUsage_Separation);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPreviewUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreviewUsage,PreviewUsageString(),false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,false);
	};
/**
* Set attribute NoOp
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetNoOp(bool value){
	SetAttribute(atr_NoOp,WString::valueOf(value));
};
/**
* Get bool attribute NoOp
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPreview::GetNoOp() const {return GetBoolAttribute(atr_NoOp,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidNoOp(EnumValidationLevel level) const {
		return ValidAttribute(atr_NoOp,AttributeType_boolean,false);
	};
/**
* Set attribute Class
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetClass(const WString& value){
	SetAttribute(atr_Class,value);
};
/**
* Get string attribute Class
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetClass() const {
	return GetAttribute(atr_Class,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidClass(EnumValidationLevel level) const {
		return ValidAttribute(atr_Class,AttributeType_Any,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreview::PartUsageString(){
		static const WString enums=WString(L"Unknown,Explicit,Implicit,Sparse");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreview::PartUsageString(EnumPartUsage value){
		return PartUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreview::SetPartUsage( EnumPartUsage value){
	SetEnumAttribute(atr_PartUsage,value,PartUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreview::EnumPartUsage JDFAutoPreview:: GetPartUsage() const {
	return (EnumPartUsage) GetEnumAttribute(atr_PartUsage,PartUsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPartUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PartUsage,PartUsageString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreview::CompensationString(){
		static const WString enums=WString(L"Unknown,None,Film,Plate,Press");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreview::CompensationString(EnumCompensation value){
		return CompensationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreview::SetCompensation( EnumCompensation value){
	SetEnumAttribute(atr_Compensation,value,CompensationString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreview::EnumCompensation JDFAutoPreview:: GetCompensation() const {
	return (EnumCompensation) GetEnumAttribute(atr_Compensation,CompensationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidCompensation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Compensation,CompensationString(),false,WString::emptyStr,true);
	};
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetCTM(const JDFMatrix& value){
	SetAttribute(atr_CTM,value);
};
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoPreview::GetCTM() const {
	return GetAttribute(atr_CTM,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidCTM(EnumValidationLevel level) const {
		return ValidAttribute(atr_CTM,AttributeType_matrix,false);
	};
/**
* Set attribute Directory
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDirectory(const WString& value){
	SetAttribute(atr_Directory,value);
};
/**
* Get string attribute Directory
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDirectory() const {
	return GetAttribute(atr_Directory,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDirectory(EnumValidationLevel level) const {
		return ValidAttribute(atr_Directory,AttributeType_URL,false);
	};
/**
* Set attribute MimeTypeDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetMimeTypeDetails(const WString& value){
	SetAttribute(atr_MimeTypeDetails,value);
};
/**
* Get string attribute MimeTypeDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetMimeTypeDetails() const {
	return GetAttribute(atr_MimeTypeDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidMimeTypeDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_MimeTypeDetails,AttributeType_string,false);
	};
/**
* Set attribute BinderySignatureName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetBinderySignatureName(const WString& value){
	SetAttribute(atr_BinderySignatureName,value);
};
/**
* Get string attribute BinderySignatureName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetBinderySignatureName() const {
	return GetAttribute(atr_BinderySignatureName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidBinderySignatureName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BinderySignatureName,AttributeType_string,false);
	};
/**
* Set attribute BlockName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetBlockName(const WString& value){
	SetAttribute(atr_BlockName,value);
};
/**
* Get string attribute BlockName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetBlockName() const {
	return GetAttribute(atr_BlockName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidBlockName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockName,AttributeType_string,false);
	};
/**
* Set attribute BundleItemIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetBundleItemIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_BundleItemIndex,value.GetString());
};
/**
* Get range attribute BundleItemIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPreview::GetBundleItemIndex() const {
	return GetAttribute(atr_BundleItemIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidBundleItemIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_BundleItemIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute CellIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetCellIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_CellIndex,value.GetString());
};
/**
* Get range attribute CellIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPreview::GetCellIndex() const {
	return GetAttribute(atr_CellIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidCellIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_CellIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute Condition
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetCondition(const WString& value){
	SetAttribute(atr_Condition,value);
};
/**
* Get string attribute Condition
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetCondition() const {
	return GetAttribute(atr_Condition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidCondition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Condition,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit0
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit0(const WString& value){
	SetAttribute(atr_DeliveryUnit0,value);
};
/**
* Get string attribute DeliveryUnit0
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit0() const {
	return GetAttribute(atr_DeliveryUnit0,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit0(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit0,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit1
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit1(const WString& value){
	SetAttribute(atr_DeliveryUnit1,value);
};
/**
* Get string attribute DeliveryUnit1
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit1() const {
	return GetAttribute(atr_DeliveryUnit1,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit1(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit1,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit2
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit2(const WString& value){
	SetAttribute(atr_DeliveryUnit2,value);
};
/**
* Get string attribute DeliveryUnit2
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit2() const {
	return GetAttribute(atr_DeliveryUnit2,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit2(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit2,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit3
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit3(const WString& value){
	SetAttribute(atr_DeliveryUnit3,value);
};
/**
* Get string attribute DeliveryUnit3
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit3() const {
	return GetAttribute(atr_DeliveryUnit3,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit3(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit3,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit4
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit4(const WString& value){
	SetAttribute(atr_DeliveryUnit4,value);
};
/**
* Get string attribute DeliveryUnit4
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit4() const {
	return GetAttribute(atr_DeliveryUnit4,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit4(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit4,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit5
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit5(const WString& value){
	SetAttribute(atr_DeliveryUnit5,value);
};
/**
* Get string attribute DeliveryUnit5
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit5() const {
	return GetAttribute(atr_DeliveryUnit5,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit5(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit5,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit6
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit6(const WString& value){
	SetAttribute(atr_DeliveryUnit6,value);
};
/**
* Get string attribute DeliveryUnit6
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit6() const {
	return GetAttribute(atr_DeliveryUnit6,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit6(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit6,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit7
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit7(const WString& value){
	SetAttribute(atr_DeliveryUnit7,value);
};
/**
* Get string attribute DeliveryUnit7
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit7() const {
	return GetAttribute(atr_DeliveryUnit7,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit7(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit7,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit8
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit8(const WString& value){
	SetAttribute(atr_DeliveryUnit8,value);
};
/**
* Get string attribute DeliveryUnit8
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit8() const {
	return GetAttribute(atr_DeliveryUnit8,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit8(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit8,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit9
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDeliveryUnit9(const WString& value){
	SetAttribute(atr_DeliveryUnit9,value);
};
/**
* Get string attribute DeliveryUnit9
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDeliveryUnit9() const {
	return GetAttribute(atr_DeliveryUnit9,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDeliveryUnit9(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit9,AttributeType_string,false);
	};
/**
* Set attribute DocTags
*@param NameRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDocTags(const NameRangeList& value){
	SetAttribute(atr_DocTags,value.GetString());
};
/**
* Get range attribute DocTags
* @return NameRangeList the vaue of the attribute 
*/
	 NameRangeList JDFAutoPreview::GetDocTags() const {
	return GetAttribute(atr_DocTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDocTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocTags,AttributeType_NameRangeList,false);
	};
/**
* Set attribute Edition
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetEdition(const WString& value){
	SetAttribute(atr_Edition,value);
};
/**
* Get string attribute Edition
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetEdition() const {
	return GetAttribute(atr_Edition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidEdition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Edition,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute EditionVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetEditionVersion(const WString& value){
	SetAttribute(atr_EditionVersion,value);
};
/**
* Get string attribute EditionVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetEditionVersion() const {
	return GetAttribute(atr_EditionVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidEditionVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_EditionVersion,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ItemNames
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetItemNames(const vWString& value){
	SetAttribute(atr_ItemNames,value);
};
/**
* Get string attribute ItemNames
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPreview::GetItemNames() const {
	return GetAttribute(atr_ItemNames,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidItemNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_ItemNames,AttributeType_Any,false);
	};
/**
* Set attribute PageNumber
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetPageNumber(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageNumber,value.GetString());
};
/**
* Get range attribute PageNumber
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPreview::GetPageNumber() const {
	return GetAttribute(atr_PageNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPageNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageNumber,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute PageTags
*@param NameRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetPageTags(const NameRangeList& value){
	SetAttribute(atr_PageTags,value.GetString());
};
/**
* Get range attribute PageTags
* @return NameRangeList the vaue of the attribute 
*/
	 NameRangeList JDFAutoPreview::GetPageTags() const {
	return GetAttribute(atr_PageTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPageTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageTags,AttributeType_NameRangeList,false);
	};
/**
* Set attribute PlateLayout
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetPlateLayout(const WString& value){
	SetAttribute(atr_PlateLayout,value);
};
/**
* Get string attribute PlateLayout
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetPlateLayout() const {
	return GetAttribute(atr_PlateLayout,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPlateLayout(EnumValidationLevel level) const {
		return ValidAttribute(atr_PlateLayout,AttributeType_string,false);
	};
/**
* Set attribute PreflightRule
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetPreflightRule(const WString& value){
	SetAttribute(atr_PreflightRule,value);
};
/**
* Get string attribute PreflightRule
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetPreflightRule() const {
	return GetAttribute(atr_PreflightRule,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPreflightRule(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreflightRule,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute RunSet
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetRunSet(const WString& value){
	SetAttribute(atr_RunSet,value);
};
/**
* Get string attribute RunSet
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetRunSet() const {
	return GetAttribute(atr_RunSet,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidRunSet(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunSet,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute SectionIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetSectionIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SectionIndex,value.GetString());
};
/**
* Get range attribute SectionIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPreview::GetSectionIndex() const {
	return GetAttribute(atr_SectionIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidSectionIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SectionIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SetDocIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetSetDocIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SetDocIndex,value.GetString());
};
/**
* Get range attribute SetDocIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPreview::GetSetDocIndex() const {
	return GetAttribute(atr_SetDocIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidSetDocIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetDocIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SetRunIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetSetRunIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SetRunIndex,value.GetString());
};
/**
* Get range attribute SetRunIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPreview::GetSetRunIndex() const {
	return GetAttribute(atr_SetRunIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidSetRunIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetRunIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SetSheetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetSetSheetIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SetSheetIndex,value.GetString());
};
/**
* Get range attribute SetSheetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPreview::GetSetSheetIndex() const {
	return GetAttribute(atr_SetSheetIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidSetSheetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetSheetIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SetTags
*@param NameRangeList value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetSetTags(const NameRangeList& value){
	SetAttribute(atr_SetTags,value.GetString());
};
/**
* Get range attribute SetTags
* @return NameRangeList the vaue of the attribute 
*/
	 NameRangeList JDFAutoPreview::GetSetTags() const {
	return GetAttribute(atr_SetTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidSetTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetTags,AttributeType_NameRangeList,false);
	};
/**
* Set attribute SubRun
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetSubRun(const WString& value){
	SetAttribute(atr_SubRun,value);
};
/**
* Get string attribute SubRun
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetSubRun() const {
	return GetAttribute(atr_SubRun,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidSubRun(EnumValidationLevel level) const {
		return ValidAttribute(atr_SubRun,AttributeType_string,false);
	};
/**
* Set attribute WebProduct
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetWebProduct(const WString& value){
	SetAttribute(atr_WebProduct,value);
};
/**
* Get string attribute WebProduct
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetWebProduct() const {
	return GetAttribute(atr_WebProduct,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidWebProduct(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebProduct,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute WebSetup
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetWebSetup(const WString& value){
	SetAttribute(atr_WebSetup,value);
};
/**
* Get string attribute WebSetup
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetWebSetup() const {
	return GetAttribute(atr_WebSetup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidWebSetup(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebSetup,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFComment JDFAutoPreview::GetComment(int iSkip)const{
	JDFComment e=GetElement(elm_Comment,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComment JDFAutoPreview::GetCreateComment(int iSkip){
	JDFComment e=GetCreateElement(elm_Comment,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComment JDFAutoPreview::AppendComment(){
	JDFComment e=AppendElement(elm_Comment);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoPreview::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoPreview::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoPreview::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPreview::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreview::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Comment);

		for(i=0;i<nElem;i++){
			if (!GetComment(i).IsValid(level)) {
				vElem.AppendUnique(elm_Comment);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_QualityControlResult);

		for(i=0;i<nElem;i++){
			if (!GetQualityControlResult(i).IsValid(level)) {
				vElem.AppendUnique(elm_QualityControlResult);
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
	WString JDFAutoPreview::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Comment,QualityControlResult";
	};
}; // end namespace JDF
