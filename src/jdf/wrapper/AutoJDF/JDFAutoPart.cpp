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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPart.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPart : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPart& JDFAutoPart::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPart: "+other.GetNodeName());
	return *this;
};

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPart::ValidNodeNames()const{
	return L"*:,Part";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPart::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Sorting,SortAmount,BinderySignatureName,BlockName,BundleItemIndex,CellIndex,Condition,DeliveryUnit0,DeliveryUnit1,DeliveryUnit2,DeliveryUnit3,DeliveryUnit4,DeliveryUnit5,DeliveryUnit6,DeliveryUnit7,DeliveryUnit8,DeliveryUnit9,DocIndex,DocCopies")
	+WString(L",DocRunIndex,DocSheetIndex,FountainNumber,DocTags,Edition,EditionVersion,ItemNames,LayerIDs,Location,Option,PageNumber,PageTags,PartVersion,PlateLayout,PreflightRule,PreviewType,RibbonName,Run,RunIndex")
	+WString(L",RunPage,RunSet,RunTags,SectionIndex,Separation,SetDocIndex,SetRunIndex,SetSheetIndex,SetTags,SetIndex,SheetIndex,SheetName,Side,SignatureName,SubRun,TileID,WebName,WebProduct,WebSetup")
	+WString(L"");
};

/**
 typesafe validator
*/
	vWString JDFAutoPart::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidSorting(level)) {
			vAtts.push_back(atr_Sorting);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSortAmount(level)) {
			vAtts.push_back(atr_SortAmount);
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
		if(!ValidDocIndex(level)) {
			vAtts.push_back(atr_DocIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocCopies(level)) {
			vAtts.push_back(atr_DocCopies);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocRunIndex(level)) {
			vAtts.push_back(atr_DocRunIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDocSheetIndex(level)) {
			vAtts.push_back(atr_DocSheetIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFountainNumber(level)) {
			vAtts.push_back(atr_FountainNumber);
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
		if(!ValidLayerIDs(level)) {
			vAtts.push_back(atr_LayerIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLocation(level)) {
			vAtts.push_back(atr_Location);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOption(level)) {
			vAtts.push_back(atr_Option);
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
		if(!ValidPartVersion(level)) {
			vAtts.push_back(atr_PartVersion);
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
		if(!ValidPreviewType(level)) {
			vAtts.push_back(atr_PreviewType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRibbonName(level)) {
			vAtts.push_back(atr_RibbonName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRun(level)) {
			vAtts.push_back(atr_Run);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunIndex(level)) {
			vAtts.push_back(atr_RunIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunPage(level)) {
			vAtts.push_back(atr_RunPage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunSet(level)) {
			vAtts.push_back(atr_RunSet);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRunTags(level)) {
			vAtts.push_back(atr_RunTags);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSectionIndex(level)) {
			vAtts.push_back(atr_SectionIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSeparation(level)) {
			vAtts.push_back(atr_Separation);
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
		if(!ValidSetIndex(level)) {
			vAtts.push_back(atr_SetIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetIndex(level)) {
			vAtts.push_back(atr_SheetIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetName(level)) {
			vAtts.push_back(atr_SheetName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSide(level)) {
			vAtts.push_back(atr_Side);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSignatureName(level)) {
			vAtts.push_back(atr_SignatureName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSubRun(level)) {
			vAtts.push_back(atr_SubRun);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTileID(level)) {
			vAtts.push_back(atr_TileID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWebName(level)) {
			vAtts.push_back(atr_WebName);
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

/**
* Set attribute Sorting
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSorting(const JDFIntegerRangeList& value){
	SetAttribute(atr_Sorting,value.GetString());
};
/**
* Get range attribute Sorting
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetSorting() const {
	return GetAttribute(atr_Sorting,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSorting(EnumValidationLevel level) const {
		return ValidAttribute(atr_Sorting,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SortAmount
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSortAmount(bool value){
	SetAttribute(atr_SortAmount,WString::valueOf(value));
};
/**
* Get bool attribute SortAmount
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoPart::GetSortAmount() const {return GetBoolAttribute(atr_SortAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSortAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_SortAmount,AttributeType_boolean,false);
	};
/**
* Set attribute BinderySignatureName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetBinderySignatureName(const WString& value){
	SetAttribute(atr_BinderySignatureName,value);
};
/**
* Get string attribute BinderySignatureName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetBinderySignatureName() const {
	return GetAttribute(atr_BinderySignatureName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidBinderySignatureName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BinderySignatureName,AttributeType_string,false);
	};
/**
* Set attribute BlockName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetBlockName(const WString& value){
	SetAttribute(atr_BlockName,value);
};
/**
* Get string attribute BlockName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetBlockName() const {
	return GetAttribute(atr_BlockName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidBlockName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockName,AttributeType_string,false);
	};
/**
* Set attribute BundleItemIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetBundleItemIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_BundleItemIndex,value.GetString());
};
/**
* Get range attribute BundleItemIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetBundleItemIndex() const {
	return GetAttribute(atr_BundleItemIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidBundleItemIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_BundleItemIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute CellIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetCellIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_CellIndex,value.GetString());
};
/**
* Get range attribute CellIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetCellIndex() const {
	return GetAttribute(atr_CellIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidCellIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_CellIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute Condition
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetCondition(const WString& value){
	SetAttribute(atr_Condition,value);
};
/**
* Get string attribute Condition
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetCondition() const {
	return GetAttribute(atr_Condition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidCondition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Condition,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit0
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit0(const WString& value){
	SetAttribute(atr_DeliveryUnit0,value);
};
/**
* Get string attribute DeliveryUnit0
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit0() const {
	return GetAttribute(atr_DeliveryUnit0,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit0(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit0,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit1
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit1(const WString& value){
	SetAttribute(atr_DeliveryUnit1,value);
};
/**
* Get string attribute DeliveryUnit1
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit1() const {
	return GetAttribute(atr_DeliveryUnit1,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit1(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit1,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit2
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit2(const WString& value){
	SetAttribute(atr_DeliveryUnit2,value);
};
/**
* Get string attribute DeliveryUnit2
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit2() const {
	return GetAttribute(atr_DeliveryUnit2,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit2(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit2,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit3
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit3(const WString& value){
	SetAttribute(atr_DeliveryUnit3,value);
};
/**
* Get string attribute DeliveryUnit3
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit3() const {
	return GetAttribute(atr_DeliveryUnit3,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit3(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit3,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit4
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit4(const WString& value){
	SetAttribute(atr_DeliveryUnit4,value);
};
/**
* Get string attribute DeliveryUnit4
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit4() const {
	return GetAttribute(atr_DeliveryUnit4,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit4(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit4,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit5
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit5(const WString& value){
	SetAttribute(atr_DeliveryUnit5,value);
};
/**
* Get string attribute DeliveryUnit5
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit5() const {
	return GetAttribute(atr_DeliveryUnit5,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit5(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit5,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit6
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit6(const WString& value){
	SetAttribute(atr_DeliveryUnit6,value);
};
/**
* Get string attribute DeliveryUnit6
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit6() const {
	return GetAttribute(atr_DeliveryUnit6,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit6(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit6,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit7
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit7(const WString& value){
	SetAttribute(atr_DeliveryUnit7,value);
};
/**
* Get string attribute DeliveryUnit7
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit7() const {
	return GetAttribute(atr_DeliveryUnit7,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit7(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit7,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit8
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit8(const WString& value){
	SetAttribute(atr_DeliveryUnit8,value);
};
/**
* Get string attribute DeliveryUnit8
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit8() const {
	return GetAttribute(atr_DeliveryUnit8,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit8(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit8,AttributeType_string,false);
	};
/**
* Set attribute DeliveryUnit9
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDeliveryUnit9(const WString& value){
	SetAttribute(atr_DeliveryUnit9,value);
};
/**
* Get string attribute DeliveryUnit9
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetDeliveryUnit9() const {
	return GetAttribute(atr_DeliveryUnit9,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDeliveryUnit9(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeliveryUnit9,AttributeType_string,false);
	};
/**
* Set attribute DocIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDocIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_DocIndex,value.GetString());
};
/**
* Get range attribute DocIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetDocIndex() const {
	return GetAttribute(atr_DocIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDocIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute DocCopies
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDocCopies(const JDFIntegerRangeList& value){
	SetAttribute(atr_DocCopies,value.GetString());
};
/**
* Get range attribute DocCopies
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetDocCopies() const {
	return GetAttribute(atr_DocCopies,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDocCopies(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocCopies,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute DocRunIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDocRunIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_DocRunIndex,value.GetString());
};
/**
* Get range attribute DocRunIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetDocRunIndex() const {
	return GetAttribute(atr_DocRunIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDocRunIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocRunIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute DocSheetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDocSheetIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_DocSheetIndex,value.GetString());
};
/**
* Get range attribute DocSheetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetDocSheetIndex() const {
	return GetAttribute(atr_DocSheetIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDocSheetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocSheetIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute FountainNumber
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPart::SetFountainNumber(int value){
	SetAttribute(atr_FountainNumber,WString::valueOf(value));
};
/**
* Get integer attribute FountainNumber
* @return int the vaue of the attribute 
*/
	 int JDFAutoPart::GetFountainNumber() const {
	return GetIntAttribute(atr_FountainNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidFountainNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_FountainNumber,AttributeType_integer,false);
	};
/**
* Set attribute DocTags
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetDocTags(const vWString& value){
	SetAttribute(atr_DocTags,value);
};
/**
* Get string attribute DocTags
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPart::GetDocTags() const {
	return GetAttribute(atr_DocTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidDocTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocTags,AttributeType_Any,false);
	};
/**
* Set attribute Edition
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetEdition(const WString& value){
	SetAttribute(atr_Edition,value);
};
/**
* Get string attribute Edition
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetEdition() const {
	return GetAttribute(atr_Edition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidEdition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Edition,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute EditionVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetEditionVersion(const WString& value){
	SetAttribute(atr_EditionVersion,value);
};
/**
* Get string attribute EditionVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetEditionVersion() const {
	return GetAttribute(atr_EditionVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidEditionVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_EditionVersion,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ItemNames
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetItemNames(const vWString& value){
	SetAttribute(atr_ItemNames,value);
};
/**
* Get string attribute ItemNames
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPart::GetItemNames() const {
	return GetAttribute(atr_ItemNames,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidItemNames(EnumValidationLevel level) const {
		return ValidAttribute(atr_ItemNames,AttributeType_Any,false);
	};
/**
* Set attribute LayerIDs
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetLayerIDs(const JDFIntegerRangeList& value){
	SetAttribute(atr_LayerIDs,value.GetString());
};
/**
* Get range attribute LayerIDs
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetLayerIDs() const {
	return GetAttribute(atr_LayerIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidLayerIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayerIDs,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute Location
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetLocation(const WString& value){
	SetAttribute(atr_Location,value);
};
/**
* Get string attribute Location
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetLocation() const {
	return GetAttribute(atr_Location,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidLocation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Location,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Option
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetOption(const WString& value){
	SetAttribute(atr_Option,value);
};
/**
* Get string attribute Option
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetOption() const {
	return GetAttribute(atr_Option,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidOption(EnumValidationLevel level) const {
		return ValidAttribute(atr_Option,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute PageNumber
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetPageNumber(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageNumber,value.GetString());
};
/**
* Get range attribute PageNumber
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetPageNumber() const {
	return GetAttribute(atr_PageNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidPageNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageNumber,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute PageTags
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetPageTags(const vWString& value){
	SetAttribute(atr_PageTags,value);
};
/**
* Get string attribute PageTags
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPart::GetPageTags() const {
	return GetAttribute(atr_PageTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidPageTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageTags,AttributeType_Any,false);
	};
/**
* Set attribute PartVersion
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetPartVersion(const vWString& value){
	SetAttribute(atr_PartVersion,value);
};
/**
* Get string attribute PartVersion
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPart::GetPartVersion() const {
	return GetAttribute(atr_PartVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidPartVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_PartVersion,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute PlateLayout
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetPlateLayout(const WString& value){
	SetAttribute(atr_PlateLayout,value);
};
/**
* Get string attribute PlateLayout
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetPlateLayout() const {
	return GetAttribute(atr_PlateLayout,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidPlateLayout(EnumValidationLevel level) const {
		return ValidAttribute(atr_PlateLayout,AttributeType_string,false);
	};
/**
* Set attribute PreflightRule
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetPreflightRule(const WString& value){
	SetAttribute(atr_PreflightRule,value);
};
/**
* Get string attribute PreflightRule
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetPreflightRule() const {
	return GetAttribute(atr_PreflightRule,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidPreflightRule(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreflightRule,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPart::PreviewTypeString(){
		static const WString enums=WString(L"Unknown,Separation,SeparatedThumbNail,SeparationRaw,ThumbNail,Viewable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPart::PreviewTypeString(EnumPreviewType value){
		return PreviewTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPart::SetPreviewType( EnumPreviewType value){
	SetEnumAttribute(atr_PreviewType,value,PreviewTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPart::EnumPreviewType JDFAutoPart:: GetPreviewType() const {
	return (EnumPreviewType) GetEnumAttribute(atr_PreviewType,PreviewTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidPreviewType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreviewType,PreviewTypeString(),false);
	};
/**
* Set attribute RibbonName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetRibbonName(const WString& value){
	SetAttribute(atr_RibbonName,value);
};
/**
* Get string attribute RibbonName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetRibbonName() const {
	return GetAttribute(atr_RibbonName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidRibbonName(EnumValidationLevel level) const {
		return ValidAttribute(atr_RibbonName,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Run
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetRun(const WString& value){
	SetAttribute(atr_Run,value);
};
/**
* Get string attribute Run
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetRun() const {
	return GetAttribute(atr_Run,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidRun(EnumValidationLevel level) const {
		return ValidAttribute(atr_Run,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute RunIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetRunIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_RunIndex,value.GetString());
};
/**
* Get range attribute RunIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetRunIndex() const {
	return GetAttribute(atr_RunIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidRunIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute RunPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPart::SetRunPage(int value){
	SetAttribute(atr_RunPage,WString::valueOf(value));
};
/**
* Get integer attribute RunPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoPart::GetRunPage() const {
	return GetIntAttribute(atr_RunPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidRunPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunPage,AttributeType_integer,false);
	};
/**
* Set attribute RunSet
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetRunSet(const WString& value){
	SetAttribute(atr_RunSet,value);
};
/**
* Get string attribute RunSet
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetRunSet() const {
	return GetAttribute(atr_RunSet,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidRunSet(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunSet,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute RunTags
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetRunTags(const vWString& value){
	SetAttribute(atr_RunTags,value);
};
/**
* Get string attribute RunTags
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPart::GetRunTags() const {
	return GetAttribute(atr_RunTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidRunTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_RunTags,AttributeType_Any,false);
	};
/**
* Set attribute SectionIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSectionIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SectionIndex,value.GetString());
};
/**
* Get range attribute SectionIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetSectionIndex() const {
	return GetAttribute(atr_SectionIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSectionIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SectionIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute Separation
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSeparation(const WString& value){
	SetAttribute(atr_Separation,value);
};
/**
* Get string attribute Separation
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetSeparation() const {
	return GetAttribute(atr_Separation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSeparation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Separation,AttributeType_string,false);
	};
/**
* Set attribute SetDocIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSetDocIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SetDocIndex,value.GetString());
};
/**
* Get range attribute SetDocIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetSetDocIndex() const {
	return GetAttribute(atr_SetDocIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSetDocIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetDocIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SetRunIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSetRunIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SetRunIndex,value.GetString());
};
/**
* Get range attribute SetRunIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetSetRunIndex() const {
	return GetAttribute(atr_SetRunIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSetRunIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetRunIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SetSheetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSetSheetIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SetSheetIndex,value.GetString());
};
/**
* Get range attribute SetSheetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetSetSheetIndex() const {
	return GetAttribute(atr_SetSheetIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSetSheetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetSheetIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SetTags
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSetTags(const vWString& value){
	SetAttribute(atr_SetTags,value);
};
/**
* Get string attribute SetTags
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPart::GetSetTags() const {
	return GetAttribute(atr_SetTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSetTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetTags,AttributeType_Any,false);
	};
/**
* Set attribute SetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSetIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SetIndex,value.GetString());
};
/**
* Get range attribute SetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetSetIndex() const {
	return GetAttribute(atr_SetIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SheetIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSheetIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_SheetIndex,value.GetString());
};
/**
* Get range attribute SheetIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPart::GetSheetIndex() const {
	return GetAttribute(atr_SheetIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSheetIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SheetName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSheetName(const WString& value){
	SetAttribute(atr_SheetName,value);
};
/**
* Get string attribute SheetName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetSheetName() const {
	return GetAttribute(atr_SheetName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSheetName(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetName,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPart::SideString(){
		static const WString enums=WString(L"Unknown,Front,Back");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPart::SideString(EnumSide value){
		return SideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPart::SetSide( EnumSide value){
	SetEnumAttribute(atr_Side,value,SideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPart::EnumSide JDFAutoPart:: GetSide() const {
	return (EnumSide) GetEnumAttribute(atr_Side,SideString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Side,SideString(),false);
	};
/**
* Set attribute SignatureName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSignatureName(const WString& value){
	SetAttribute(atr_SignatureName,value);
};
/**
* Get string attribute SignatureName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetSignatureName() const {
	return GetAttribute(atr_SignatureName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSignatureName(EnumValidationLevel level) const {
		return ValidAttribute(atr_SignatureName,AttributeType_string,false);
	};
/**
* Set attribute SubRun
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetSubRun(const WString& value){
	SetAttribute(atr_SubRun,value);
};
/**
* Get string attribute SubRun
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetSubRun() const {
	return GetAttribute(atr_SubRun,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidSubRun(EnumValidationLevel level) const {
		return ValidAttribute(atr_SubRun,AttributeType_string,false);
	};
/**
* Set attribute TileID
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPart::SetTileID(const JDFXYPair& value){
	SetAttribute(atr_TileID,value);
};
/**
* Get string attribute TileID
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPart::GetTileID() const {
	return GetAttribute(atr_TileID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidTileID(EnumValidationLevel level) const {
		return ValidAttribute(atr_TileID,AttributeType_XYPair,false);
	};
/**
* Set attribute WebName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetWebName(const WString& value){
	SetAttribute(atr_WebName,value);
};
/**
* Get string attribute WebName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetWebName() const {
	return GetAttribute(atr_WebName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidWebName(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebName,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute WebProduct
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetWebProduct(const WString& value){
	SetAttribute(atr_WebProduct,value);
};
/**
* Get string attribute WebProduct
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetWebProduct() const {
	return GetAttribute(atr_WebProduct,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidWebProduct(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebProduct,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute WebSetup
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPart::SetWebSetup(const WString& value){
	SetAttribute(atr_WebSetup,value);
};
/**
* Get string attribute WebSetup
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPart::GetWebSetup() const {
	return GetAttribute(atr_WebSetup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPart::ValidWebSetup(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebSetup,AttributeType_NMTOKEN,false);
	};
}; // end namespace JDF
