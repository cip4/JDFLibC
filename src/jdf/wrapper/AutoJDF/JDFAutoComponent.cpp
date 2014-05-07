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

 
#include "jdf/wrapper/AutoJDF/JDFAutoComponent.h"
#include "jdf/wrapper/JDFAssembly.h"
#include "jdf/wrapper/JDFBundle.h"
#include "jdf/wrapper/JDFDisjointing.h"
#include "jdf/wrapper/JDFSheet.h"
#include "jdf/wrapper/JDFLayout.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFPageList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoComponent : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoComponent& JDFAutoComponent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoComponent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoComponent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoComponent::ValidNodeNames()const{
	return L"*:,Component";
};

bool JDFAutoComponent::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Quantity;
};

bool JDFAutoComponent::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Quantity);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoComponent::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",ComponentType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoComponent::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",AssemblyIDs,Automation,CartonTopFlaps,Columns,Dimensions,IsWaste,MaxHeat,Overfold,OverfoldSide,PageListIndex,ProductType,ProductTypeDetails,ReaderPageCount,SheetPart,SourceRibbon,SourceSheet,SourceWeb,SpineThickness,SurfaceCount")
	+WString(L",Transformation,WindingResult");
};

/**
 typesafe validator
*/
	vWString JDFAutoComponent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidComponentType(level)) {
			vAtts.push_back(atr_ComponentType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAssemblyIDs(level)) {
			vAtts.push_back(atr_AssemblyIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAutomation(level)) {
			vAtts.push_back(atr_Automation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCartonTopFlaps(level)) {
			vAtts.push_back(atr_CartonTopFlaps);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColumns(level)) {
			vAtts.push_back(atr_Columns);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDimensions(level)) {
			vAtts.push_back(atr_Dimensions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsWaste(level)) {
			vAtts.push_back(atr_IsWaste);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxHeat(level)) {
			vAtts.push_back(atr_MaxHeat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverfold(level)) {
			vAtts.push_back(atr_Overfold);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverfoldSide(level)) {
			vAtts.push_back(atr_OverfoldSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageListIndex(level)) {
			vAtts.push_back(atr_PageListIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductType(level)) {
			vAtts.push_back(atr_ProductType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductTypeDetails(level)) {
			vAtts.push_back(atr_ProductTypeDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReaderPageCount(level)) {
			vAtts.push_back(atr_ReaderPageCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetPart(level)) {
			vAtts.push_back(atr_SheetPart);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceRibbon(level)) {
			vAtts.push_back(atr_SourceRibbon);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceSheet(level)) {
			vAtts.push_back(atr_SourceSheet);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceWeb(level)) {
			vAtts.push_back(atr_SourceWeb);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpineThickness(level)) {
			vAtts.push_back(atr_SpineThickness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSurfaceCount(level)) {
			vAtts.push_back(atr_SurfaceCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransformation(level)) {
			vAtts.push_back(atr_Transformation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWindingResult(level)) {
			vAtts.push_back(atr_WindingResult);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoComponent::ComponentTypeString(){
		static const WString enums=WString(L"Unknown,Block,Other,Ribbon,Sheet,Web,FinalProduct,PartialProduct,Proof");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoComponent::ComponentTypeString(EnumComponentType value){
		return ComponentTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoComponent::AddComponentType( EnumComponentType value){
	return AddEnumerationsAttribute(atr_ComponentType,value,ComponentTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoComponent::RemoveComponentType( EnumComponentType value){
	return RemoveEnumerationsAttribute(atr_ComponentType,value,ComponentTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoComponent::GetComponentType() const {
	return GetEnumerationsAttribute(atr_ComponentType,ComponentTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoComponent::SetComponentType( EnumComponentType value){
	SetEnumAttribute(atr_ComponentType,value,ComponentTypeString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoComponent::SetComponentType( const vint& value){
	SetEnumerationsAttribute(atr_ComponentType,value,ComponentTypeString());
};
/**
* Typesafe attribute validation of ComponentType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidComponentType(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_ComponentType,ComponentTypeString(),RequiredLevel(level));
	};
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoComponent::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoComponent::AutomationString(){
		static const WString enums=WString(L"Unknown,Static,Dynamic");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoComponent::AutomationString(EnumAutomation value){
		return AutomationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoComponent::SetAutomation( EnumAutomation value){
	SetEnumAttribute(atr_Automation,value,AutomationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoComponent::EnumAutomation JDFAutoComponent:: GetAutomation() const {
	return (EnumAutomation) GetEnumAttribute(atr_Automation,AutomationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidAutomation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Automation,AutomationString(),false);
	};
/**
* Set attribute CartonTopFlaps
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetCartonTopFlaps(const JDFXYPair& value){
	SetAttribute(atr_CartonTopFlaps,value);
};
/**
* Get string attribute CartonTopFlaps
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoComponent::GetCartonTopFlaps() const {
	return GetAttribute(atr_CartonTopFlaps,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidCartonTopFlaps(EnumValidationLevel level) const {
		return ValidAttribute(atr_CartonTopFlaps,AttributeType_XYPair,false);
	};
/**
* Set attribute Columns
*@param int value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetColumns(int value){
	SetAttribute(atr_Columns,WString::valueOf(value));
};
/**
* Get integer attribute Columns
* @return int the vaue of the attribute 
*/
	 int JDFAutoComponent::GetColumns() const {
	return GetIntAttribute(atr_Columns,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidColumns(EnumValidationLevel level) const {
		return ValidAttribute(atr_Columns,AttributeType_integer,false);
	};
/**
* Set attribute Dimensions
*@param JDFShape value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetDimensions(const JDFShape& value){
	SetAttribute(atr_Dimensions,value);
};
/**
* Get string attribute Dimensions
* @return JDFShape the vaue of the attribute 
*/
	 JDFShape JDFAutoComponent::GetDimensions() const {
	return GetAttribute(atr_Dimensions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidDimensions(EnumValidationLevel level) const {
		return ValidAttribute(atr_Dimensions,AttributeType_shape,false);
	};
/**
* Set attribute IsWaste
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetIsWaste(bool value){
	SetAttribute(atr_IsWaste,WString::valueOf(value));
};
/**
* Get bool attribute IsWaste
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoComponent::GetIsWaste() const {return GetBoolAttribute(atr_IsWaste,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidIsWaste(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsWaste,AttributeType_boolean,false);
	};
/**
* Set attribute MaxHeat
*@param double value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetMaxHeat(double value){
	SetAttribute(atr_MaxHeat,WString::valueOf(value));
};
/**
* Get double attribute MaxHeat
* @return double the vaue of the attribute 
*/
	 double JDFAutoComponent::GetMaxHeat() const {
	return GetRealAttribute(atr_MaxHeat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidMaxHeat(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxHeat,AttributeType_double,false);
	};
/**
* Set attribute Overfold
*@param double value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetOverfold(double value){
	SetAttribute(atr_Overfold,WString::valueOf(value));
};
/**
* Get double attribute Overfold
* @return double the vaue of the attribute 
*/
	 double JDFAutoComponent::GetOverfold() const {
	return GetRealAttribute(atr_Overfold,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidOverfold(EnumValidationLevel level) const {
		return ValidAttribute(atr_Overfold,AttributeType_double,false);
	};
/**
* Set attribute OverfoldSide
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetOverfoldSide(const WString& value){
	SetAttribute(atr_OverfoldSide,value);
};
/**
* Get string attribute OverfoldSide
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComponent::GetOverfoldSide() const {
	return GetAttribute(atr_OverfoldSide,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidOverfoldSide(EnumValidationLevel level) const {
		return ValidAttribute(atr_OverfoldSide,AttributeType_Any,false);
	};
/**
* Set attribute PageListIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetPageListIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageListIndex,value.GetString());
};
/**
* Get range attribute PageListIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoComponent::GetPageListIndex() const {
	return GetAttribute(atr_PageListIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidPageListIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageListIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute ProductType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetProductType(const WString& value){
	SetAttribute(atr_ProductType,value);
};
/**
* Get string attribute ProductType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComponent::GetProductType() const {
	return GetAttribute(atr_ProductType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidProductType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ProductTypeDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetProductTypeDetails(const WString& value){
	SetAttribute(atr_ProductTypeDetails,value);
};
/**
* Get string attribute ProductTypeDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComponent::GetProductTypeDetails() const {
	return GetAttribute(atr_ProductTypeDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidProductTypeDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductTypeDetails,AttributeType_string,false);
	};
/**
* Set attribute ReaderPageCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetReaderPageCount(int value){
	SetAttribute(atr_ReaderPageCount,WString::valueOf(value));
};
/**
* Get integer attribute ReaderPageCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoComponent::GetReaderPageCount() const {
	return GetIntAttribute(atr_ReaderPageCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidReaderPageCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReaderPageCount,AttributeType_integer,false);
	};
/**
* Set attribute SheetPart
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetSheetPart(const JDFRectangle& value){
	SetAttribute(atr_SheetPart,value);
};
/**
* Get string attribute SheetPart
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoComponent::GetSheetPart() const {
	return GetAttribute(atr_SheetPart,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidSheetPart(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetPart,AttributeType_rectangle,false);
	};
/**
* Set attribute SourceRibbon
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetSourceRibbon(const WString& value){
	SetAttribute(atr_SourceRibbon,value);
};
/**
* Get string attribute SourceRibbon
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComponent::GetSourceRibbon() const {
	return GetAttribute(atr_SourceRibbon,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidSourceRibbon(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceRibbon,AttributeType_string,false);
	};
/**
* Set attribute SourceSheet
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetSourceSheet(const WString& value){
	SetAttribute(atr_SourceSheet,value);
};
/**
* Get string attribute SourceSheet
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComponent::GetSourceSheet() const {
	return GetAttribute(atr_SourceSheet,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidSourceSheet(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceSheet,AttributeType_string,false);
	};
/**
* Set attribute SourceWeb
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetSourceWeb(const WString& value){
	SetAttribute(atr_SourceWeb,value);
};
/**
* Get string attribute SourceWeb
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComponent::GetSourceWeb() const {
	return GetAttribute(atr_SourceWeb,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidSourceWeb(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceWeb,AttributeType_string,false);
	};
/**
* Set attribute SpineThickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetSpineThickness(double value){
	SetAttribute(atr_SpineThickness,WString::valueOf(value));
};
/**
* Get double attribute SpineThickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoComponent::GetSpineThickness() const {
	return GetRealAttribute(atr_SpineThickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidSpineThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpineThickness,AttributeType_double,false);
	};
/**
* Set attribute SurfaceCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetSurfaceCount(int value){
	SetAttribute(atr_SurfaceCount,WString::valueOf(value));
};
/**
* Get integer attribute SurfaceCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoComponent::GetSurfaceCount() const {
	return GetIntAttribute(atr_SurfaceCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidSurfaceCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_SurfaceCount,AttributeType_integer,false);
	};
/**
* Set attribute Transformation
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetTransformation(const JDFMatrix& value){
	SetAttribute(atr_Transformation,value);
};
/**
* Get string attribute Transformation
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoComponent::GetTransformation() const {
	return GetAttribute(atr_Transformation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidTransformation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Transformation,AttributeType_matrix,false);
	};
/**
* Set attribute WindingResult
*@param int value: the value to set the attribute to
*/
	 void JDFAutoComponent::SetWindingResult(int value){
	SetAttribute(atr_WindingResult,WString::valueOf(value));
};
/**
* Get integer attribute WindingResult
* @return int the vaue of the attribute 
*/
	 int JDFAutoComponent::GetWindingResult() const {
	return GetIntAttribute(atr_WindingResult,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComponent::ValidWindingResult(EnumValidationLevel level) const {
		return ValidAttribute(atr_WindingResult,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAssembly JDFAutoComponent::GetAssembly()const{
	JDFAssembly e=GetElement(elm_Assembly);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAssembly JDFAutoComponent::GetCreateAssembly(){
	JDFAssembly e=GetCreateElement(elm_Assembly);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAssembly JDFAutoComponent::AppendAssembly(){
	JDFAssembly e=AppendElementN(elm_Assembly,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoComponent::RefAssembly(JDFAssembly& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFBundle JDFAutoComponent::GetBundle()const{
	JDFBundle e=GetElement(elm_Bundle);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBundle JDFAutoComponent::GetCreateBundle(){
	JDFBundle e=GetCreateElement(elm_Bundle);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBundle JDFAutoComponent::AppendBundle(){
	JDFBundle e=AppendElementN(elm_Bundle,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoComponent::RefBundle(JDFBundle& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDisjointing JDFAutoComponent::GetDisjointing()const{
	JDFDisjointing e=GetElement(elm_Disjointing);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisjointing JDFAutoComponent::GetCreateDisjointing(){
	JDFDisjointing e=GetCreateElement(elm_Disjointing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisjointing JDFAutoComponent::AppendDisjointing(){
	JDFDisjointing e=AppendElementN(elm_Disjointing,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSheet JDFAutoComponent::GetSheet()const{
	JDFSheet e=GetElement(elm_Sheet);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSheet JDFAutoComponent::GetCreateSheet(){
	JDFSheet e=GetCreateElement(elm_Sheet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSheet JDFAutoComponent::AppendSheet(){
	JDFSheet e=AppendElementN(elm_Sheet,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoComponent::RefSheet(JDFSheet& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoComponent::GetLayout()const{
	JDFLayout e=GetElement(elm_Layout);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoComponent::GetCreateLayout(){
	JDFLayout e=GetCreateElement(elm_Layout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoComponent::AppendLayout(){
	JDFLayout e=AppendElementN(elm_Layout,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoComponent::RefLayout(JDFLayout& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoComponent::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoComponent::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoComponent::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoComponent::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoComponent::GetPageList()const{
	JDFPageList e=GetElement(elm_PageList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoComponent::GetCreatePageList(){
	JDFPageList e=GetCreateElement(elm_PageList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoComponent::AppendPageList(){
	JDFPageList e=AppendElementN(elm_PageList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoComponent::RefPageList(JDFPageList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoComponent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Assembly);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Assembly);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAssembly().IsValid(level)) {
				vElem.AppendUnique(elm_Assembly);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Bundle);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Bundle);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetBundle().IsValid(level)) {
				vElem.AppendUnique(elm_Bundle);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Disjointing);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Disjointing);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDisjointing().IsValid(level)) {
				vElem.AppendUnique(elm_Disjointing);
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
	WString JDFAutoComponent::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Assembly,Bundle,Disjointing,Sheet,Layout,Media,PageList";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoComponent::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Assembly,Bundle,Disjointing,Sheet,Layout,Media,PageList";
	};
}; // end namespace JDF
