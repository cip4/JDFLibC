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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMarkObject.h"
#include "jdf/wrapper/JDFCIELABMeasuringField.h"
#include "jdf/wrapper/JDFColorControlStrip.h"
#include "jdf/wrapper/JDFCutMark.h"
#include "jdf/wrapper/JDFDensityMeasuringField.h"
#include "jdf/wrapper/JDFDeviceMark.h"
#include "jdf/wrapper/JDFDynamicField.h"
#include "jdf/wrapper/JDFFillMark.h"
#include "jdf/wrapper/JDFIdentificationField.h"
#include "jdf/wrapper/JDFJobField.h"
#include "jdf/wrapper/JDFLayoutElement.h"
#include "jdf/wrapper/JDFMarkActivation.h"
#include "jdf/wrapper/JDFRefAnchor.h"
#include "jdf/wrapper/JDFRegisterMark.h"
#include "jdf/wrapper/JDFScavengerArea.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMarkObject : public JDFPlacedObject

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMarkObject& JDFAutoMarkObject::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMarkObject: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMarkObject::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMarkObject::ValidNodeNames()const{
	return L"*:,MarkObject";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoMarkObject::RequiredAttributes()const{
		return JDFPlacedObject::RequiredAttributes()+L",CTM";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMarkObject::OptionalAttributes()const{
		return JDFPlacedObject::OptionalAttributes()+WString(L",ContentRef,LayoutElementPageNum,Ord,Anchor,AssemblyIDs,ClipBox,ClipBoxFormat,ClipBoxTemplate,ClipPath,CompensationCTMFormat,CompensationCTMTemplate,HalfTonePhaseOrigin,LayerID,LogicalStackOrd,OrdID,SourceClipPath,TrimClipPath,TrimCTM,TrimSize")
	+WString(L",Type");
};

/**
 typesafe validator
*/
	vWString JDFAutoMarkObject::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFPlacedObject::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidContentRef(level)) {
			vAtts.push_back(atr_ContentRef);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayoutElementPageNum(level)) {
			vAtts.push_back(atr_LayoutElementPageNum);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrd(level)) {
			vAtts.push_back(atr_Ord);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAnchor(level)) {
			vAtts.push_back(atr_Anchor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAssemblyIDs(level)) {
			vAtts.push_back(atr_AssemblyIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipBox(level)) {
			vAtts.push_back(atr_ClipBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipBoxFormat(level)) {
			vAtts.push_back(atr_ClipBoxFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipBoxTemplate(level)) {
			vAtts.push_back(atr_ClipBoxTemplate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipPath(level)) {
			vAtts.push_back(atr_ClipPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompensationCTMFormat(level)) {
			vAtts.push_back(atr_CompensationCTMFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompensationCTMTemplate(level)) {
			vAtts.push_back(atr_CompensationCTMTemplate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCTM(level)) {
			vAtts.push_back(atr_CTM);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHalfTonePhaseOrigin(level)) {
			vAtts.push_back(atr_HalfTonePhaseOrigin);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayerID(level)) {
			vAtts.push_back(atr_LayerID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLogicalStackOrd(level)) {
			vAtts.push_back(atr_LogicalStackOrd);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrdID(level)) {
			vAtts.push_back(atr_OrdID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceClipPath(level)) {
			vAtts.push_back(atr_SourceClipPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimClipPath(level)) {
			vAtts.push_back(atr_TrimClipPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimCTM(level)) {
			vAtts.push_back(atr_TrimCTM);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimSize(level)) {
			vAtts.push_back(atr_TrimSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ContentRef
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetContentRef(const WString& value){
	SetAttribute(atr_ContentRef,value);
};
/**
* Get string attribute ContentRef
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMarkObject::GetContentRef() const {
	return GetAttribute(atr_ContentRef,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidContentRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContentRef,AttributeType_IDREF,false);
	};
/**
* Set attribute LayoutElementPageNum
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetLayoutElementPageNum(int value){
	SetAttribute(atr_LayoutElementPageNum,WString::valueOf(value));
};
/**
* Get integer attribute LayoutElementPageNum
* @return int the vaue of the attribute 
*/
	 int JDFAutoMarkObject::GetLayoutElementPageNum() const {
	return GetIntAttribute(atr_LayoutElementPageNum,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidLayoutElementPageNum(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayoutElementPageNum,AttributeType_integer,false);
	};
/**
* Set attribute Ord
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetOrd(int value){
	SetAttribute(atr_Ord,WString::valueOf(value));
};
/**
* Get integer attribute Ord
* @return int the vaue of the attribute 
*/
	 int JDFAutoMarkObject::GetOrd() const {
	return GetIntAttribute(atr_Ord,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_Ord,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMarkObject::AnchorString(){
		static const WString enums=WString(L"Unknown,TopLeft,TopCenter,TopRight,CenterLeft,Center,CenterRight,BottomLeft,BottomCenter,BottomRight");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMarkObject::AnchorString(EnumAnchor value){
		return AnchorString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMarkObject::SetAnchor( EnumAnchor value){
	SetEnumAttribute(atr_Anchor,value,AnchorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMarkObject::EnumAnchor JDFAutoMarkObject:: GetAnchor() const {
	return (EnumAnchor) GetEnumAttribute(atr_Anchor,AnchorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidAnchor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Anchor,AnchorString(),false);
	};
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoMarkObject::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute ClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetClipBox(const JDFRectangle& value){
	SetAttribute(atr_ClipBox,value);
};
/**
* Get string attribute ClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoMarkObject::GetClipBox() const {
	return GetAttribute(atr_ClipBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidClipBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipBox,AttributeType_rectangle,false);
	};
/**
* Set attribute ClipBoxFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetClipBoxFormat(const WString& value){
	SetAttribute(atr_ClipBoxFormat,value);
};
/**
* Get string attribute ClipBoxFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMarkObject::GetClipBoxFormat() const {
	return GetAttribute(atr_ClipBoxFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidClipBoxFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipBoxFormat,AttributeType_string,false);
	};
/**
* Set attribute ClipBoxTemplate
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetClipBoxTemplate(const WString& value){
	SetAttribute(atr_ClipBoxTemplate,value);
};
/**
* Get string attribute ClipBoxTemplate
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMarkObject::GetClipBoxTemplate() const {
	return GetAttribute(atr_ClipBoxTemplate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidClipBoxTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipBoxTemplate,AttributeType_string,false);
	};
/**
* Set attribute ClipPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetClipPath(const WString& value){
	SetAttribute(atr_ClipPath,value);
};
/**
* Get string attribute ClipPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMarkObject::GetClipPath() const {
	return GetAttribute(atr_ClipPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidClipPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipPath,AttributeType_PDFPath,false);
	};
/**
* Set attribute CompensationCTMFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetCompensationCTMFormat(const WString& value){
	SetAttribute(atr_CompensationCTMFormat,value);
};
/**
* Get string attribute CompensationCTMFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMarkObject::GetCompensationCTMFormat() const {
	return GetAttribute(atr_CompensationCTMFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidCompensationCTMFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_CompensationCTMFormat,AttributeType_string,false);
	};
/**
* Set attribute CompensationCTMTemplate
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetCompensationCTMTemplate(const WString& value){
	SetAttribute(atr_CompensationCTMTemplate,value);
};
/**
* Get string attribute CompensationCTMTemplate
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMarkObject::GetCompensationCTMTemplate() const {
	return GetAttribute(atr_CompensationCTMTemplate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidCompensationCTMTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_CompensationCTMTemplate,AttributeType_string,false);
	};
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetCTM(const JDFMatrix& value){
	SetAttribute(atr_CTM,value);
};
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoMarkObject::GetCTM() const {
	return GetAttribute(atr_CTM,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidCTM(EnumValidationLevel level) const {
		return ValidAttribute(atr_CTM,AttributeType_matrix,RequiredLevel(level));
	};
/**
* Set attribute HalfTonePhaseOrigin
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetHalfTonePhaseOrigin(const JDFXYPair& value){
	SetAttribute(atr_HalfTonePhaseOrigin,value);
};
/**
* Get string attribute HalfTonePhaseOrigin
* @return JDFXYPair the vaue of the attribute ; defaults to 0 0
*/
	 JDFXYPair JDFAutoMarkObject::GetHalfTonePhaseOrigin() const {
	return GetAttribute(atr_HalfTonePhaseOrigin,WString::emptyStr,L"0 0");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidHalfTonePhaseOrigin(EnumValidationLevel level) const {
		return ValidAttribute(atr_HalfTonePhaseOrigin,AttributeType_XYPair,false);
	};
/**
* Set attribute LayerID
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetLayerID(int value){
	SetAttribute(atr_LayerID,WString::valueOf(value));
};
/**
* Get integer attribute LayerID
* @return int the vaue of the attribute 
*/
	 int JDFAutoMarkObject::GetLayerID() const {
	return GetIntAttribute(atr_LayerID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidLayerID(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayerID,AttributeType_integer,false);
	};
/**
* Set attribute LogicalStackOrd
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetLogicalStackOrd(int value){
	SetAttribute(atr_LogicalStackOrd,WString::valueOf(value));
};
/**
* Get integer attribute LogicalStackOrd
* @return int the vaue of the attribute 
*/
	 int JDFAutoMarkObject::GetLogicalStackOrd() const {
	return GetIntAttribute(atr_LogicalStackOrd,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidLogicalStackOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_LogicalStackOrd,AttributeType_integer,false);
	};
/**
* Set attribute OrdID
*@param int value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetOrdID(int value){
	SetAttribute(atr_OrdID,WString::valueOf(value));
};
/**
* Get integer attribute OrdID
* @return int the vaue of the attribute 
*/
	 int JDFAutoMarkObject::GetOrdID() const {
	return GetIntAttribute(atr_OrdID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidOrdID(EnumValidationLevel level) const {
		return ValidAttribute(atr_OrdID,AttributeType_integer,false);
	};
/**
* Set attribute SourceClipPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetSourceClipPath(const WString& value){
	SetAttribute(atr_SourceClipPath,value);
};
/**
* Get string attribute SourceClipPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMarkObject::GetSourceClipPath() const {
	return GetAttribute(atr_SourceClipPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidSourceClipPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceClipPath,AttributeType_PDFPath,false);
	};
/**
* Set attribute TrimClipPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetTrimClipPath(const WString& value){
	SetAttribute(atr_TrimClipPath,value);
};
/**
* Get string attribute TrimClipPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMarkObject::GetTrimClipPath() const {
	return GetAttribute(atr_TrimClipPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidTrimClipPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimClipPath,AttributeType_PDFPath,false);
	};
/**
* Set attribute TrimCTM
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetTrimCTM(const JDFMatrix& value){
	SetAttribute(atr_TrimCTM,value);
};
/**
* Get string attribute TrimCTM
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoMarkObject::GetTrimCTM() const {
	return GetAttribute(atr_TrimCTM,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidTrimCTM(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimCTM,AttributeType_matrix,false);
	};
/**
* Set attribute TrimSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoMarkObject::SetTrimSize(const JDFXYPair& value){
	SetAttribute(atr_TrimSize,value);
};
/**
* Get string attribute TrimSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoMarkObject::GetTrimSize() const {
	return GetAttribute(atr_TrimSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidTrimSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimSize,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMarkObject::TypeString(){
		static const WString enums=WString(L"Unknown,Content,Mark");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMarkObject::TypeString(EnumType value){
		return TypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMarkObject::SetType( EnumType value){
	SetEnumAttribute(atr_Type,value,TypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMarkObject::EnumType JDFAutoMarkObject:: GetType() const {
	return (EnumType) GetEnumAttribute(atr_Type,TypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMarkObject::ValidType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Type,TypeString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCIELABMeasuringField JDFAutoMarkObject::GetCIELABMeasuringField(int iSkip)const{
	JDFCIELABMeasuringField e=GetElement(elm_CIELABMeasuringField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCIELABMeasuringField JDFAutoMarkObject::GetCreateCIELABMeasuringField(int iSkip){
	JDFCIELABMeasuringField e=GetCreateElement(elm_CIELABMeasuringField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCIELABMeasuringField JDFAutoMarkObject::AppendCIELABMeasuringField(){
	JDFCIELABMeasuringField e=AppendElement(elm_CIELABMeasuringField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorControlStrip JDFAutoMarkObject::GetColorControlStrip(int iSkip)const{
	JDFColorControlStrip e=GetElement(elm_ColorControlStrip,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorControlStrip JDFAutoMarkObject::GetCreateColorControlStrip(int iSkip){
	JDFColorControlStrip e=GetCreateElement(elm_ColorControlStrip,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorControlStrip JDFAutoMarkObject::AppendColorControlStrip(){
	JDFColorControlStrip e=AppendElement(elm_ColorControlStrip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMarkObject::RefColorControlStrip(JDFColorControlStrip& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFCutMark JDFAutoMarkObject::GetCutMark(int iSkip)const{
	JDFCutMark e=GetElement(elm_CutMark,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCutMark JDFAutoMarkObject::GetCreateCutMark(int iSkip){
	JDFCutMark e=GetCreateElement(elm_CutMark,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCutMark JDFAutoMarkObject::AppendCutMark(){
	JDFCutMark e=AppendElement(elm_CutMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMarkObject::RefCutMark(JDFCutMark& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDensityMeasuringField JDFAutoMarkObject::GetDensityMeasuringField(int iSkip)const{
	JDFDensityMeasuringField e=GetElement(elm_DensityMeasuringField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDensityMeasuringField JDFAutoMarkObject::GetCreateDensityMeasuringField(int iSkip){
	JDFDensityMeasuringField e=GetCreateElement(elm_DensityMeasuringField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDensityMeasuringField JDFAutoMarkObject::AppendDensityMeasuringField(){
	JDFDensityMeasuringField e=AppendElement(elm_DensityMeasuringField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMarkObject::RefDensityMeasuringField(JDFDensityMeasuringField& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoMarkObject::GetDeviceMark()const{
	JDFDeviceMark e=GetElement(elm_DeviceMark);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoMarkObject::GetCreateDeviceMark(){
	JDFDeviceMark e=GetCreateElement(elm_DeviceMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoMarkObject::AppendDeviceMark(){
	JDFDeviceMark e=AppendElementN(elm_DeviceMark,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDynamicField JDFAutoMarkObject::GetDynamicField(int iSkip)const{
	JDFDynamicField e=GetElement(elm_DynamicField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDynamicField JDFAutoMarkObject::GetCreateDynamicField(int iSkip){
	JDFDynamicField e=GetCreateElement(elm_DynamicField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDynamicField JDFAutoMarkObject::AppendDynamicField(){
	JDFDynamicField e=AppendElement(elm_DynamicField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFillMark JDFAutoMarkObject::GetFillMark(int iSkip)const{
	JDFFillMark e=GetElement(elm_FillMark,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFillMark JDFAutoMarkObject::GetCreateFillMark(int iSkip){
	JDFFillMark e=GetCreateElement(elm_FillMark,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFillMark JDFAutoMarkObject::AppendFillMark(){
	JDFFillMark e=AppendElement(elm_FillMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIdentificationField JDFAutoMarkObject::GetIdentificationField(int iSkip)const{
	JDFIdentificationField e=GetElement(elm_IdentificationField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIdentificationField JDFAutoMarkObject::GetCreateIdentificationField(int iSkip){
	JDFIdentificationField e=GetCreateElement(elm_IdentificationField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIdentificationField JDFAutoMarkObject::AppendIdentificationField(){
	JDFIdentificationField e=AppendElement(elm_IdentificationField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMarkObject::RefIdentificationField(JDFIdentificationField& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoMarkObject::GetJobField(int iSkip)const{
	JDFJobField e=GetElement(elm_JobField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoMarkObject::GetCreateJobField(int iSkip){
	JDFJobField e=GetCreateElement(elm_JobField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoMarkObject::AppendJobField(){
	JDFJobField e=AppendElement(elm_JobField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoMarkObject::GetLayoutElement()const{
	JDFLayoutElement e=GetElement(elm_LayoutElement);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoMarkObject::GetCreateLayoutElement(){
	JDFLayoutElement e=GetCreateElement(elm_LayoutElement);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoMarkObject::AppendLayoutElement(){
	JDFLayoutElement e=AppendElementN(elm_LayoutElement,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMarkObject::RefLayoutElement(JDFLayoutElement& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMarkActivation JDFAutoMarkObject::GetMarkActivation(int iSkip)const{
	JDFMarkActivation e=GetElement(elm_MarkActivation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMarkActivation JDFAutoMarkObject::GetCreateMarkActivation(int iSkip){
	JDFMarkActivation e=GetCreateElement(elm_MarkActivation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMarkActivation JDFAutoMarkObject::AppendMarkActivation(){
	JDFMarkActivation e=AppendElement(elm_MarkActivation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRefAnchor JDFAutoMarkObject::GetRefAnchor(int iSkip)const{
	JDFRefAnchor e=GetElement(elm_RefAnchor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRefAnchor JDFAutoMarkObject::GetCreateRefAnchor(int iSkip){
	JDFRefAnchor e=GetCreateElement(elm_RefAnchor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRefAnchor JDFAutoMarkObject::AppendRefAnchor(){
	JDFRefAnchor e=AppendElement(elm_RefAnchor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterMark JDFAutoMarkObject::GetRegisterMark(int iSkip)const{
	JDFRegisterMark e=GetElement(elm_RegisterMark,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterMark JDFAutoMarkObject::GetCreateRegisterMark(int iSkip){
	JDFRegisterMark e=GetCreateElement(elm_RegisterMark,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterMark JDFAutoMarkObject::AppendRegisterMark(){
	JDFRegisterMark e=AppendElement(elm_RegisterMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMarkObject::RefRegisterMark(JDFRegisterMark& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFScavengerArea JDFAutoMarkObject::GetScavengerArea(int iSkip)const{
	JDFScavengerArea e=GetElement(elm_ScavengerArea,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScavengerArea JDFAutoMarkObject::GetCreateScavengerArea(int iSkip){
	JDFScavengerArea e=GetCreateElement(elm_ScavengerArea,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScavengerArea JDFAutoMarkObject::AppendScavengerArea(){
	JDFScavengerArea e=AppendElement(elm_ScavengerArea);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMarkObject::RefScavengerArea(JDFScavengerArea& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoMarkObject::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFPlacedObject::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CIELABMeasuringField);

		for(i=0;i<nElem;i++){
			if (!GetCIELABMeasuringField(i).IsValid(level)) {
				vElem.AppendUnique(elm_CIELABMeasuringField);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ColorControlStrip);

		for(i=0;i<nElem;i++){
			if (!GetColorControlStrip(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorControlStrip);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CutMark);

		for(i=0;i<nElem;i++){
			if (!GetCutMark(i).IsValid(level)) {
				vElem.AppendUnique(elm_CutMark);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DensityMeasuringField);

		for(i=0;i<nElem;i++){
			if (!GetDensityMeasuringField(i).IsValid(level)) {
				vElem.AppendUnique(elm_DensityMeasuringField);
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
		nElem=NumChildElements(elm_DynamicField);

		for(i=0;i<nElem;i++){
			if (!GetDynamicField(i).IsValid(level)) {
				vElem.AppendUnique(elm_DynamicField);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FillMark);

		for(i=0;i<nElem;i++){
			if (!GetFillMark(i).IsValid(level)) {
				vElem.AppendUnique(elm_FillMark);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IdentificationField);

		for(i=0;i<nElem;i++){
			if (!GetIdentificationField(i).IsValid(level)) {
				vElem.AppendUnique(elm_IdentificationField);
				if (++n>=nMax)
					return vElem;
				break;
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
		nElem=NumChildElements(elm_MarkActivation);

		for(i=0;i<nElem;i++){
			if (!GetMarkActivation(i).IsValid(level)) {
				vElem.AppendUnique(elm_MarkActivation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RefAnchor);

		for(i=0;i<nElem;i++){
			if (!GetRefAnchor(i).IsValid(level)) {
				vElem.AppendUnique(elm_RefAnchor);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RegisterMark);

		for(i=0;i<nElem;i++){
			if (!GetRegisterMark(i).IsValid(level)) {
				vElem.AppendUnique(elm_RegisterMark);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ScavengerArea);

		for(i=0;i<nElem;i++){
			if (!GetScavengerArea(i).IsValid(level)) {
				vElem.AppendUnique(elm_ScavengerArea);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoMarkObject::UniqueElements()const{
		return JDFPlacedObject::UniqueElements()+L",DeviceMark,LayoutElement";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoMarkObject::OptionalElements()const{
		return JDFPlacedObject::OptionalElements()+L",CIELABMeasuringField,ColorControlStrip,CutMark,DensityMeasuringField,DeviceMark,DynamicField,FillMark,IdentificationField,JobField,LayoutElement,MarkActivation,RefAnchor,RegisterMark,ScavengerArea";
	};
}; // end namespace JDF
