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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLayoutPreparationParams.h"
#include "jdf/wrapper/JDFImageShift.h"
#include "jdf/wrapper/JDFInsertSheet.h"
#include "jdf/wrapper/JDFDeviceMark.h"
#include "jdf/wrapper/JDFExternalImpositionTemplate.h"
#include "jdf/wrapper/JDFFitPolicy.h"
#include "jdf/wrapper/JDFJobField.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFPageCell.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLayoutPreparationParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLayoutPreparationParams& JDFAutoLayoutPreparationParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLayoutPreparationParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLayoutPreparationParams::ValidNodeNames()const{
	return L"*:,LayoutPreparationParams";
};

bool JDFAutoLayoutPreparationParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoLayoutPreparationParams::init(){
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
	WString JDFAutoLayoutPreparationParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",FinishingOrder,FoldCatalogOrientation,PageDistributionScheme,PageOrder,Rotate,Sides,BindingEdge,BackMarkList,CreepValue,FoldCatalog,FrontMarkList,Gutter,GutterMinimumLimit,HorizontalCreep,ImplicitGutter,ImplicitGutterMinimumLimit,NumberUp,PresentationDirection,StackDepth")
	+WString(L",StepDocs,StepRepeat,SurfaceContentsBox,VerticalCreep");
};

/**
 typesafe validator
*/
	vWString JDFAutoLayoutPreparationParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFinishingOrder(level)) {
			vAtts.push_back(atr_FinishingOrder);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFoldCatalogOrientation(level)) {
			vAtts.push_back(atr_FoldCatalogOrientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageDistributionScheme(level)) {
			vAtts.push_back(atr_PageDistributionScheme);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageOrder(level)) {
			vAtts.push_back(atr_PageOrder);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotate(level)) {
			vAtts.push_back(atr_Rotate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSides(level)) {
			vAtts.push_back(atr_Sides);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBindingEdge(level)) {
			vAtts.push_back(atr_BindingEdge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBackMarkList(level)) {
			vAtts.push_back(atr_BackMarkList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCreepValue(level)) {
			vAtts.push_back(atr_CreepValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFoldCatalog(level)) {
			vAtts.push_back(atr_FoldCatalog);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontMarkList(level)) {
			vAtts.push_back(atr_FrontMarkList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGutter(level)) {
			vAtts.push_back(atr_Gutter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGutterMinimumLimit(level)) {
			vAtts.push_back(atr_GutterMinimumLimit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHorizontalCreep(level)) {
			vAtts.push_back(atr_HorizontalCreep);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImplicitGutter(level)) {
			vAtts.push_back(atr_ImplicitGutter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImplicitGutterMinimumLimit(level)) {
			vAtts.push_back(atr_ImplicitGutterMinimumLimit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberUp(level)) {
			vAtts.push_back(atr_NumberUp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPresentationDirection(level)) {
			vAtts.push_back(atr_PresentationDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStackDepth(level)) {
			vAtts.push_back(atr_StackDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStepDocs(level)) {
			vAtts.push_back(atr_StepDocs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStepRepeat(level)) {
			vAtts.push_back(atr_StepRepeat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSurfaceContentsBox(level)) {
			vAtts.push_back(atr_SurfaceContentsBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVerticalCreep(level)) {
			vAtts.push_back(atr_VerticalCreep);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutPreparationParams::FinishingOrderString(){
		static const WString enums=WString(L"Unknown,FoldGather,FoldCollect,Gather,GatherFold");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutPreparationParams::FinishingOrderString(EnumFinishingOrder value){
		return FinishingOrderString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutPreparationParams::SetFinishingOrder( EnumFinishingOrder value){
	SetEnumAttribute(atr_FinishingOrder,value,FinishingOrderString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutPreparationParams::EnumFinishingOrder JDFAutoLayoutPreparationParams:: GetFinishingOrder() const {
	return (EnumFinishingOrder) GetEnumAttribute(atr_FinishingOrder,FinishingOrderString(),WString::emptyStr,FinishingOrder_GatherFold);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidFinishingOrder(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FinishingOrder,FinishingOrderString(),false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutPreparationParams::SetFoldCatalogOrientation( EnumOrientation value){
	SetEnumAttribute(atr_FoldCatalogOrientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutPreparationParams::EnumOrientation JDFAutoLayoutPreparationParams:: GetFoldCatalogOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_FoldCatalogOrientation,OrientationString(),WString::emptyStr,Orientation_Rotate0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidFoldCatalogOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FoldCatalogOrientation,OrientationString(),false);
	};
/**
* Set attribute PageDistributionScheme
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetPageDistributionScheme(const WString& value){
	SetAttribute(atr_PageDistributionScheme,value);
};
/**
* Get string attribute PageDistributionScheme
* @return WString the vaue of the attribute ; defaults to Sequential
*/
	 WString JDFAutoLayoutPreparationParams::GetPageDistributionScheme() const {
	return GetAttribute(atr_PageDistributionScheme,WString::emptyStr,L"Sequential");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidPageDistributionScheme(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageDistributionScheme,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute PageOrder
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetPageOrder(const WString& value){
	SetAttribute(atr_PageOrder,value);
};
/**
* Get string attribute PageOrder
* @return WString the vaue of the attribute ; defaults to Reader
*/
	 WString JDFAutoLayoutPreparationParams::GetPageOrder() const {
	return GetAttribute(atr_PageOrder,WString::emptyStr,L"Reader");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidPageOrder(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageOrder,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutPreparationParams::RotateString(){
		static const WString enums=WString(L"Unknown,Rotate0,Rotate90,Rotate180,Rotate270");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutPreparationParams::RotateString(EnumRotate value){
		return RotateString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutPreparationParams::SetRotate( EnumRotate value){
	SetEnumAttribute(atr_Rotate,value,RotateString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutPreparationParams::EnumRotate JDFAutoLayoutPreparationParams:: GetRotate() const {
	return (EnumRotate) GetEnumAttribute(atr_Rotate,RotateString(),WString::emptyStr,Rotate_Rotate0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidRotate(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Rotate,RotateString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutPreparationParams::SidesString(){
		static const WString enums=WString(L"Unknown,OneSidedBackFlipX,OneSidedBackFlipY,OneSidedFront,TwoSidedFlipX,TwoSidedFlipY");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutPreparationParams::SidesString(EnumSides value){
		return SidesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutPreparationParams::SetSides( EnumSides value){
	SetEnumAttribute(atr_Sides,value,SidesString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutPreparationParams::EnumSides JDFAutoLayoutPreparationParams:: GetSides() const {
	return (EnumSides) GetEnumAttribute(atr_Sides,SidesString(),WString::emptyStr,Sides_OneSidedFront);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidSides(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Sides,SidesString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutPreparationParams::BindingEdgeString(){
		static const WString enums=WString(L"Unknown,Left,Right,Top,Bottom,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutPreparationParams::BindingEdgeString(EnumBindingEdge value){
		return BindingEdgeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutPreparationParams::SetBindingEdge( EnumBindingEdge value){
	SetEnumAttribute(atr_BindingEdge,value,BindingEdgeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutPreparationParams::EnumBindingEdge JDFAutoLayoutPreparationParams:: GetBindingEdge() const {
	return (EnumBindingEdge) GetEnumAttribute(atr_BindingEdge,BindingEdgeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidBindingEdge(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BindingEdge,BindingEdgeString(),false);
	};
/**
* Set attribute BackMarkList
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetBackMarkList(const vWString& value){
	SetAttribute(atr_BackMarkList,value);
};
/**
* Get string attribute BackMarkList
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoLayoutPreparationParams::GetBackMarkList() const {
	return GetAttribute(atr_BackMarkList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidBackMarkList(EnumValidationLevel level) const {
		return ValidAttribute(atr_BackMarkList,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute CreepValue
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetCreepValue(const JDFXYPair& value){
	SetAttribute(atr_CreepValue,value);
};
/**
* Get string attribute CreepValue
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoLayoutPreparationParams::GetCreepValue() const {
	return GetAttribute(atr_CreepValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidCreepValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_CreepValue,AttributeType_XYPair,false);
	};
/**
* Set attribute FoldCatalog
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetFoldCatalog(const WString& value){
	SetAttribute(atr_FoldCatalog,value);
};
/**
* Get string attribute FoldCatalog
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoLayoutPreparationParams::GetFoldCatalog() const {
	return GetAttribute(atr_FoldCatalog,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidFoldCatalog(EnumValidationLevel level) const {
		return ValidAttribute(atr_FoldCatalog,AttributeType_string,false);
	};
/**
* Set attribute FrontMarkList
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetFrontMarkList(const vWString& value){
	SetAttribute(atr_FrontMarkList,value);
};
/**
* Get string attribute FrontMarkList
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoLayoutPreparationParams::GetFrontMarkList() const {
	return GetAttribute(atr_FrontMarkList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidFrontMarkList(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrontMarkList,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Gutter
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetGutter(const JDFXYPair& value){
	SetAttribute(atr_Gutter,value);
};
/**
* Get string attribute Gutter
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoLayoutPreparationParams::GetGutter() const {
	return GetAttribute(atr_Gutter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidGutter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Gutter,AttributeType_XYPair,false);
	};
/**
* Set attribute GutterMinimumLimit
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetGutterMinimumLimit(const JDFXYPair& value){
	SetAttribute(atr_GutterMinimumLimit,value);
};
/**
* Get string attribute GutterMinimumLimit
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoLayoutPreparationParams::GetGutterMinimumLimit() const {
	return GetAttribute(atr_GutterMinimumLimit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidGutterMinimumLimit(EnumValidationLevel level) const {
		return ValidAttribute(atr_GutterMinimumLimit,AttributeType_XYPair,false);
	};
/**
* Set attribute HorizontalCreep
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetHorizontalCreep(const JDFIntegerList& value){
	SetAttribute(atr_HorizontalCreep,value.GetString());
};
/**
* Get string attribute HorizontalCreep
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoLayoutPreparationParams::GetHorizontalCreep() const {
	return GetAttribute(atr_HorizontalCreep,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidHorizontalCreep(EnumValidationLevel level) const {
		return ValidAttribute(atr_HorizontalCreep,AttributeType_IntegerList,false);
	};
/**
* Set attribute ImplicitGutter
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetImplicitGutter(const JDFXYPair& value){
	SetAttribute(atr_ImplicitGutter,value);
};
/**
* Get string attribute ImplicitGutter
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoLayoutPreparationParams::GetImplicitGutter() const {
	return GetAttribute(atr_ImplicitGutter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidImplicitGutter(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImplicitGutter,AttributeType_XYPair,false);
	};
/**
* Set attribute ImplicitGutterMinimumLimit
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetImplicitGutterMinimumLimit(const JDFXYPair& value){
	SetAttribute(atr_ImplicitGutterMinimumLimit,value);
};
/**
* Get string attribute ImplicitGutterMinimumLimit
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoLayoutPreparationParams::GetImplicitGutterMinimumLimit() const {
	return GetAttribute(atr_ImplicitGutterMinimumLimit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidImplicitGutterMinimumLimit(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImplicitGutterMinimumLimit,AttributeType_XYPair,false);
	};
/**
* Set attribute NumberUp
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetNumberUp(const JDFXYPair& value){
	SetAttribute(atr_NumberUp,value);
};
/**
* Get string attribute NumberUp
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoLayoutPreparationParams::GetNumberUp() const {
	return GetAttribute(atr_NumberUp,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidNumberUp(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberUp,AttributeType_XYPair,false);
	};
/**
* Set attribute PresentationDirection
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetPresentationDirection(const WString& value){
	SetAttribute(atr_PresentationDirection,value);
};
/**
* Get string attribute PresentationDirection
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoLayoutPreparationParams::GetPresentationDirection() const {
	return GetAttribute(atr_PresentationDirection,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidPresentationDirection(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentationDirection,AttributeType_Any,false);
	};
/**
* Set attribute StackDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetStackDepth(int value){
	SetAttribute(atr_StackDepth,WString::valueOf(value));
};
/**
* Get integer attribute StackDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoLayoutPreparationParams::GetStackDepth() const {
	return GetIntAttribute(atr_StackDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidStackDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_StackDepth,AttributeType_integer,false);
	};
/**
* Set attribute StepDocs
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetStepDocs(const JDFXYPair& value){
	SetAttribute(atr_StepDocs,value);
};
/**
* Get string attribute StepDocs
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoLayoutPreparationParams::GetStepDocs() const {
	return GetAttribute(atr_StepDocs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidStepDocs(EnumValidationLevel level) const {
		return ValidAttribute(atr_StepDocs,AttributeType_XYPair,false);
	};
/**
* Set attribute StepRepeat
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetStepRepeat(const JDFIntegerList& value){
	SetAttribute(atr_StepRepeat,value.GetString());
};
/**
* Get string attribute StepRepeat
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoLayoutPreparationParams::GetStepRepeat() const {
	return GetAttribute(atr_StepRepeat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidStepRepeat(EnumValidationLevel level) const {
		return ValidAttribute(atr_StepRepeat,AttributeType_Any,false);
	};
/**
* Set attribute SurfaceContentsBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetSurfaceContentsBox(const JDFRectangle& value){
	SetAttribute(atr_SurfaceContentsBox,value);
};
/**
* Get string attribute SurfaceContentsBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoLayoutPreparationParams::GetSurfaceContentsBox() const {
	return GetAttribute(atr_SurfaceContentsBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidSurfaceContentsBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SurfaceContentsBox,AttributeType_rectangle,false);
	};
/**
* Set attribute VerticalCreep
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoLayoutPreparationParams::SetVerticalCreep(const JDFIntegerList& value){
	SetAttribute(atr_VerticalCreep,value.GetString());
};
/**
* Get string attribute VerticalCreep
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoLayoutPreparationParams::GetVerticalCreep() const {
	return GetAttribute(atr_VerticalCreep,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutPreparationParams::ValidVerticalCreep(EnumValidationLevel level) const {
		return ValidAttribute(atr_VerticalCreep,AttributeType_IntegerList,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFImageShift JDFAutoLayoutPreparationParams::GetImageShift()const{
	JDFImageShift e=GetElement(elm_ImageShift);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageShift JDFAutoLayoutPreparationParams::GetCreateImageShift(){
	JDFImageShift e=GetCreateElement(elm_ImageShift);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageShift JDFAutoLayoutPreparationParams::AppendImageShift(){
	JDFImageShift e=AppendElementN(elm_ImageShift,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoLayoutPreparationParams::GetInsertSheet(int iSkip)const{
	JDFInsertSheet e=GetElement(elm_InsertSheet,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoLayoutPreparationParams::GetCreateInsertSheet(int iSkip){
	JDFInsertSheet e=GetCreateElement(elm_InsertSheet,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoLayoutPreparationParams::AppendInsertSheet(){
	JDFInsertSheet e=AppendElement(elm_InsertSheet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutPreparationParams::RefInsertSheet(JDFInsertSheet& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoLayoutPreparationParams::GetDeviceMark()const{
	JDFDeviceMark e=GetElement(elm_DeviceMark);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoLayoutPreparationParams::GetCreateDeviceMark(){
	JDFDeviceMark e=GetCreateElement(elm_DeviceMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoLayoutPreparationParams::AppendDeviceMark(){
	JDFDeviceMark e=AppendElementN(elm_DeviceMark,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutPreparationParams::RefDeviceMark(JDFDeviceMark& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFExternalImpositionTemplate JDFAutoLayoutPreparationParams::GetExternalImpositionTemplate()const{
	JDFExternalImpositionTemplate e=GetElement(elm_ExternalImpositionTemplate);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFExternalImpositionTemplate JDFAutoLayoutPreparationParams::GetCreateExternalImpositionTemplate(){
	JDFExternalImpositionTemplate e=GetCreateElement(elm_ExternalImpositionTemplate);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFExternalImpositionTemplate JDFAutoLayoutPreparationParams::AppendExternalImpositionTemplate(){
	JDFExternalImpositionTemplate e=AppendElementN(elm_ExternalImpositionTemplate,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutPreparationParams::RefExternalImpositionTemplate(JDFExternalImpositionTemplate& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoLayoutPreparationParams::GetFitPolicy()const{
	JDFFitPolicy e=GetElement(elm_FitPolicy);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoLayoutPreparationParams::GetCreateFitPolicy(){
	JDFFitPolicy e=GetCreateElement(elm_FitPolicy);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoLayoutPreparationParams::AppendFitPolicy(){
	JDFFitPolicy e=AppendElementN(elm_FitPolicy,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutPreparationParams::RefFitPolicy(JDFFitPolicy& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoLayoutPreparationParams::GetJobField(int iSkip)const{
	JDFJobField e=GetElement(elm_JobField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoLayoutPreparationParams::GetCreateJobField(int iSkip){
	JDFJobField e=GetCreateElement(elm_JobField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoLayoutPreparationParams::AppendJobField(){
	JDFJobField e=AppendElement(elm_JobField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutPreparationParams::RefJobField(JDFJobField& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoLayoutPreparationParams::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoLayoutPreparationParams::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoLayoutPreparationParams::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutPreparationParams::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPageCell JDFAutoLayoutPreparationParams::GetPageCell()const{
	JDFPageCell e=GetElement(elm_PageCell);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageCell JDFAutoLayoutPreparationParams::GetCreatePageCell(){
	JDFPageCell e=GetCreateElement(elm_PageCell);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageCell JDFAutoLayoutPreparationParams::AppendPageCell(){
	JDFPageCell e=AppendElementN(elm_PageCell,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLayoutPreparationParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ImageShift);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ImageShift);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetImageShift().IsValid(level)) {
				vElem.AppendUnique(elm_ImageShift);
				if (++n>=nMax)
					return vElem;
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
		nElem=NumChildElements(elm_DeviceMark);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DeviceMark);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDeviceMark().IsValid(level)) {
				vElem.AppendUnique(elm_DeviceMark);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ExternalImpositionTemplate);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ExternalImpositionTemplate);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetExternalImpositionTemplate().IsValid(level)) {
				vElem.AppendUnique(elm_ExternalImpositionTemplate);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FitPolicy);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FitPolicy);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFitPolicy().IsValid(level)) {
				vElem.AppendUnique(elm_FitPolicy);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_JobField);

		for(i=0;i<nElem;i++){
			if (!GetJobField(i).IsValid(level)) {
				vElem.AppendUnique(elm_JobField);
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
		nElem=NumChildElements(elm_PageCell);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PageCell);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPageCell().IsValid(level)) {
				vElem.AppendUnique(elm_PageCell);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoLayoutPreparationParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ImageShift,DeviceMark,ExternalImpositionTemplate,FitPolicy,Media,PageCell";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoLayoutPreparationParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ImageShift,InsertSheet,DeviceMark,ExternalImpositionTemplate,FitPolicy,JobField,Media,PageCell";
	};
}; // end namespace JDF
