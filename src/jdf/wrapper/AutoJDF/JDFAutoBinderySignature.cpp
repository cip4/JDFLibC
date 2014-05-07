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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBinderySignature.h"
#include "jdf/wrapper/JDFDieLayout.h"
#include "jdf/wrapper/JDFFold.h"
#include "jdf/wrapper/JDFSignatureCell.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBinderySignature : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBinderySignature& JDFAutoBinderySignature::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBinderySignature: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBinderySignature::ValidNodeNames()const{
	return L"*:,BinderySignature";
};

bool JDFAutoBinderySignature::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoBinderySignature::init(){
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
	WString JDFAutoBinderySignature::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BinderySignatureType,BindingEdge,JogEdge,NumberUp,AlignmentReferenceWeb,BindingOrientation,BleedBottom,BleedLeft,BleedRight,BleedTop,FoldCatalog,FoldLay,OutsideGutter,StaggerColumns,StaggerContinuous,StaggerRows,TrimBottom,TrimLeft,TrimRight")
	+WString(L",TrimTop,WebCellAlignment");
};

/**
 typesafe validator
*/
	vWString JDFAutoBinderySignature::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBinderySignatureType(level)) {
			vAtts.push_back(atr_BinderySignatureType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBindingEdge(level)) {
			vAtts.push_back(atr_BindingEdge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJogEdge(level)) {
			vAtts.push_back(atr_JogEdge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberUp(level)) {
			vAtts.push_back(atr_NumberUp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAlignmentReferenceWeb(level)) {
			vAtts.push_back(atr_AlignmentReferenceWeb);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBindingOrientation(level)) {
			vAtts.push_back(atr_BindingOrientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBleedBottom(level)) {
			vAtts.push_back(atr_BleedBottom);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBleedLeft(level)) {
			vAtts.push_back(atr_BleedLeft);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBleedRight(level)) {
			vAtts.push_back(atr_BleedRight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBleedTop(level)) {
			vAtts.push_back(atr_BleedTop);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFoldCatalog(level)) {
			vAtts.push_back(atr_FoldCatalog);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFoldLay(level)) {
			vAtts.push_back(atr_FoldLay);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutsideGutter(level)) {
			vAtts.push_back(atr_OutsideGutter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStaggerColumns(level)) {
			vAtts.push_back(atr_StaggerColumns);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStaggerContinuous(level)) {
			vAtts.push_back(atr_StaggerContinuous);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStaggerRows(level)) {
			vAtts.push_back(atr_StaggerRows);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimBottom(level)) {
			vAtts.push_back(atr_TrimBottom);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimLeft(level)) {
			vAtts.push_back(atr_TrimLeft);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimRight(level)) {
			vAtts.push_back(atr_TrimRight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimTop(level)) {
			vAtts.push_back(atr_TrimTop);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWebCellAlignment(level)) {
			vAtts.push_back(atr_WebCellAlignment);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBinderySignature::BinderySignatureTypeString(){
		static const WString enums=WString(L"Unknown,Die,Fold,Grid");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBinderySignature::BinderySignatureTypeString(EnumBinderySignatureType value){
		return BinderySignatureTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBinderySignature::SetBinderySignatureType( EnumBinderySignatureType value){
	SetEnumAttribute(atr_BinderySignatureType,value,BinderySignatureTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBinderySignature::EnumBinderySignatureType JDFAutoBinderySignature:: GetBinderySignatureType() const {
	return (EnumBinderySignatureType) GetEnumAttribute(atr_BinderySignatureType,BinderySignatureTypeString(),WString::emptyStr,BinderySignatureType_Fold);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidBinderySignatureType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BinderySignatureType,BinderySignatureTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBinderySignature::BindingEdgeString(){
		static const WString enums=WString(L"Unknown,Left,Right,Top,Bottom,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBinderySignature::BindingEdgeString(EnumBindingEdge value){
		return BindingEdgeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBinderySignature::SetBindingEdge( EnumBindingEdge value){
	SetEnumAttribute(atr_BindingEdge,value,BindingEdgeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBinderySignature::EnumBindingEdge JDFAutoBinderySignature:: GetBindingEdge() const {
	return (EnumBindingEdge) GetEnumAttribute(atr_BindingEdge,BindingEdgeString(),WString::emptyStr,BindingEdge_Left);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidBindingEdge(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BindingEdge,BindingEdgeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBinderySignature::JogEdgeString(){
		static const WString enums=WString(L"Unknown,Left,Right,Top,Bottom,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBinderySignature::JogEdgeString(EnumJogEdge value){
		return JogEdgeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBinderySignature::SetJogEdge( EnumJogEdge value){
	SetEnumAttribute(atr_JogEdge,value,JogEdgeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBinderySignature::EnumJogEdge JDFAutoBinderySignature:: GetJogEdge() const {
	return (EnumJogEdge) GetEnumAttribute(atr_JogEdge,JogEdgeString(),WString::emptyStr,JogEdge_Top);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidJogEdge(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_JogEdge,JogEdgeString(),false);
	};
/**
* Set attribute NumberUp
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetNumberUp(const JDFXYPair& value){
	SetAttribute(atr_NumberUp,value);
};
/**
* Get string attribute NumberUp
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	 JDFXYPair JDFAutoBinderySignature::GetNumberUp() const {
	return GetAttribute(atr_NumberUp,WString::emptyStr,L"1 1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidNumberUp(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberUp,AttributeType_XYPair,false);
	};
/**
* Set attribute AlignmentReferenceWeb
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetAlignmentReferenceWeb(const WString& value){
	SetAttribute(atr_AlignmentReferenceWeb,value);
};
/**
* Get string attribute AlignmentReferenceWeb
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBinderySignature::GetAlignmentReferenceWeb() const {
	return GetAttribute(atr_AlignmentReferenceWeb,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidAlignmentReferenceWeb(EnumValidationLevel level) const {
		return ValidAttribute(atr_AlignmentReferenceWeb,AttributeType_NMTOKEN,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoBinderySignature::SetBindingOrientation( EnumOrientation value){
	SetEnumAttribute(atr_BindingOrientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBinderySignature::EnumOrientation JDFAutoBinderySignature:: GetBindingOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_BindingOrientation,OrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidBindingOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BindingOrientation,OrientationString(),false);
	};
/**
* Set attribute BleedBottom
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetBleedBottom(double value){
	SetAttribute(atr_BleedBottom,WString::valueOf(value));
};
/**
* Get double attribute BleedBottom
* @return double the vaue of the attribute 
*/
	 double JDFAutoBinderySignature::GetBleedBottom() const {
	return GetRealAttribute(atr_BleedBottom,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidBleedBottom(EnumValidationLevel level) const {
		return ValidAttribute(atr_BleedBottom,AttributeType_double,false);
	};
/**
* Set attribute BleedLeft
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetBleedLeft(double value){
	SetAttribute(atr_BleedLeft,WString::valueOf(value));
};
/**
* Get double attribute BleedLeft
* @return double the vaue of the attribute 
*/
	 double JDFAutoBinderySignature::GetBleedLeft() const {
	return GetRealAttribute(atr_BleedLeft,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidBleedLeft(EnumValidationLevel level) const {
		return ValidAttribute(atr_BleedLeft,AttributeType_double,false);
	};
/**
* Set attribute BleedRight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetBleedRight(double value){
	SetAttribute(atr_BleedRight,WString::valueOf(value));
};
/**
* Get double attribute BleedRight
* @return double the vaue of the attribute 
*/
	 double JDFAutoBinderySignature::GetBleedRight() const {
	return GetRealAttribute(atr_BleedRight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidBleedRight(EnumValidationLevel level) const {
		return ValidAttribute(atr_BleedRight,AttributeType_double,false);
	};
/**
* Set attribute BleedTop
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetBleedTop(double value){
	SetAttribute(atr_BleedTop,WString::valueOf(value));
};
/**
* Get double attribute BleedTop
* @return double the vaue of the attribute 
*/
	 double JDFAutoBinderySignature::GetBleedTop() const {
	return GetRealAttribute(atr_BleedTop,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidBleedTop(EnumValidationLevel level) const {
		return ValidAttribute(atr_BleedTop,AttributeType_double,false);
	};
/**
* Set attribute FoldCatalog
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetFoldCatalog(const WString& value){
	SetAttribute(atr_FoldCatalog,value);
};
/**
* Get string attribute FoldCatalog
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBinderySignature::GetFoldCatalog() const {
	return GetAttribute(atr_FoldCatalog,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidFoldCatalog(EnumValidationLevel level) const {
		return ValidAttribute(atr_FoldCatalog,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoBinderySignature::SetFoldLay( EnumOrientation value){
	SetEnumAttribute(atr_FoldLay,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBinderySignature::EnumOrientation JDFAutoBinderySignature:: GetFoldLay() const {
	return (EnumOrientation) GetEnumAttribute(atr_FoldLay,OrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidFoldLay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FoldLay,OrientationString(),false);
	};
/**
* Set attribute OutsideGutter
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetOutsideGutter(bool value){
	SetAttribute(atr_OutsideGutter,WString::valueOf(value));
};
/**
* Get bool attribute OutsideGutter
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoBinderySignature::GetOutsideGutter() const {return GetBoolAttribute(atr_OutsideGutter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidOutsideGutter(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutsideGutter,AttributeType_boolean,false);
	};
/**
* Set attribute StaggerColumns
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetStaggerColumns(const JDFNumberList& value){
	SetAttribute(atr_StaggerColumns,value.GetString());
};
/**
* Get string attribute StaggerColumns
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoBinderySignature::GetStaggerColumns() const {
	return GetAttribute(atr_StaggerColumns,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidStaggerColumns(EnumValidationLevel level) const {
		return ValidAttribute(atr_StaggerColumns,AttributeType_NumberList,false);
	};
/**
* Set attribute StaggerContinuous
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetStaggerContinuous(bool value){
	SetAttribute(atr_StaggerContinuous,WString::valueOf(value));
};
/**
* Get bool attribute StaggerContinuous
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoBinderySignature::GetStaggerContinuous() const {return GetBoolAttribute(atr_StaggerContinuous,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidStaggerContinuous(EnumValidationLevel level) const {
		return ValidAttribute(atr_StaggerContinuous,AttributeType_boolean,false);
	};
/**
* Set attribute StaggerRows
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetStaggerRows(const JDFNumberList& value){
	SetAttribute(atr_StaggerRows,value.GetString());
};
/**
* Get string attribute StaggerRows
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoBinderySignature::GetStaggerRows() const {
	return GetAttribute(atr_StaggerRows,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidStaggerRows(EnumValidationLevel level) const {
		return ValidAttribute(atr_StaggerRows,AttributeType_NumberList,false);
	};
/**
* Set attribute TrimBottom
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetTrimBottom(double value){
	SetAttribute(atr_TrimBottom,WString::valueOf(value));
};
/**
* Get double attribute TrimBottom
* @return double the vaue of the attribute 
*/
	 double JDFAutoBinderySignature::GetTrimBottom() const {
	return GetRealAttribute(atr_TrimBottom,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidTrimBottom(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimBottom,AttributeType_double,false);
	};
/**
* Set attribute TrimLeft
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetTrimLeft(double value){
	SetAttribute(atr_TrimLeft,WString::valueOf(value));
};
/**
* Get double attribute TrimLeft
* @return double the vaue of the attribute 
*/
	 double JDFAutoBinderySignature::GetTrimLeft() const {
	return GetRealAttribute(atr_TrimLeft,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidTrimLeft(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimLeft,AttributeType_double,false);
	};
/**
* Set attribute TrimRight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetTrimRight(double value){
	SetAttribute(atr_TrimRight,WString::valueOf(value));
};
/**
* Get double attribute TrimRight
* @return double the vaue of the attribute 
*/
	 double JDFAutoBinderySignature::GetTrimRight() const {
	return GetRealAttribute(atr_TrimRight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidTrimRight(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimRight,AttributeType_double,false);
	};
/**
* Set attribute TrimTop
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetTrimTop(double value){
	SetAttribute(atr_TrimTop,WString::valueOf(value));
};
/**
* Get double attribute TrimTop
* @return double the vaue of the attribute 
*/
	 double JDFAutoBinderySignature::GetTrimTop() const {
	return GetRealAttribute(atr_TrimTop,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidTrimTop(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimTop,AttributeType_double,false);
	};
/**
* Set attribute WebCellAlignment
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoBinderySignature::SetWebCellAlignment(const JDFXYPair& value){
	SetAttribute(atr_WebCellAlignment,value);
};
/**
* Get string attribute WebCellAlignment
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoBinderySignature::GetWebCellAlignment() const {
	return GetAttribute(atr_WebCellAlignment,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBinderySignature::ValidWebCellAlignment(EnumValidationLevel level) const {
		return ValidAttribute(atr_WebCellAlignment,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDieLayout JDFAutoBinderySignature::GetDieLayout()const{
	JDFDieLayout e=GetElement(elm_DieLayout);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDieLayout JDFAutoBinderySignature::GetCreateDieLayout(){
	JDFDieLayout e=GetCreateElement(elm_DieLayout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDieLayout JDFAutoBinderySignature::AppendDieLayout(){
	JDFDieLayout e=AppendElementN(elm_DieLayout,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoBinderySignature::RefDieLayout(JDFDieLayout& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFold JDFAutoBinderySignature::GetFold(int iSkip)const{
	JDFFold e=GetElement(elm_Fold,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFold JDFAutoBinderySignature::GetCreateFold(int iSkip){
	JDFFold e=GetCreateElement(elm_Fold,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFold JDFAutoBinderySignature::AppendFold(){
	JDFFold e=AppendElement(elm_Fold);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSignatureCell JDFAutoBinderySignature::GetSignatureCell(int iSkip)const{
	JDFSignatureCell e=GetElement(elm_SignatureCell,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSignatureCell JDFAutoBinderySignature::GetCreateSignatureCell(int iSkip){
	JDFSignatureCell e=GetCreateElement(elm_SignatureCell,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSignatureCell JDFAutoBinderySignature::AppendSignatureCell(){
	JDFSignatureCell e=AppendElement(elm_SignatureCell);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBinderySignature::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_DieLayout);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DieLayout);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDieLayout().IsValid(level)) {
				vElem.AppendUnique(elm_DieLayout);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Fold);

		for(i=0;i<nElem;i++){
			if (!GetFold(i).IsValid(level)) {
				vElem.AppendUnique(elm_Fold);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SignatureCell);

		for(i=0;i<nElem;i++){
			if (!GetSignatureCell(i).IsValid(level)) {
				vElem.AppendUnique(elm_SignatureCell);
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
	WString JDFAutoBinderySignature::UniqueElements()const{
		return JDFResource::UniqueElements()+L",DieLayout";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoBinderySignature::OptionalElements()const{
		return JDFResource::OptionalElements()+L",DieLayout,Fold,SignatureCell";
	};
}; // end namespace JDF
