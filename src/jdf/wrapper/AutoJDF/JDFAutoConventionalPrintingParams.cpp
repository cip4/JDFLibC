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

 
#include "jdf/wrapper/AutoJDF/JDFAutoConventionalPrintingParams.h"
#include "jdf/wrapper/JDFInk.h"
#include "jdf/wrapper/JDFApprovalParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoConventionalPrintingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoConventionalPrintingParams& JDFAutoConventionalPrintingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoConventionalPrintingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoConventionalPrintingParams::ValidNodeNames()const{
	return L"*:,ConventionalPrintingParams";
};

bool JDFAutoConventionalPrintingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoConventionalPrintingParams::init(){
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
	WString JDFAutoConventionalPrintingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DirectProof,Drying,FirstSurface,FountainSolution,MediaLocation,ModuleAvailableIndex,ModuleDrying,ModuleIndex,NonPrintableMarginBottom,NonPrintableMarginLeft,NonPrintableMarginRight,NonPrintableMarginTop,PerfectingModule,Powder,PrintingType,SheetLay,Speed,WorkStyle");
};

/**
 typesafe validator
*/
	vWString JDFAutoConventionalPrintingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDirectProof(level)) {
			vAtts.push_back(atr_DirectProof);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDrying(level)) {
			vAtts.push_back(atr_Drying);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFirstSurface(level)) {
			vAtts.push_back(atr_FirstSurface);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFountainSolution(level)) {
			vAtts.push_back(atr_FountainSolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaLocation(level)) {
			vAtts.push_back(atr_MediaLocation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleAvailableIndex(level)) {
			vAtts.push_back(atr_ModuleAvailableIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleDrying(level)) {
			vAtts.push_back(atr_ModuleDrying);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleIndex(level)) {
			vAtts.push_back(atr_ModuleIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNonPrintableMarginBottom(level)) {
			vAtts.push_back(atr_NonPrintableMarginBottom);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNonPrintableMarginLeft(level)) {
			vAtts.push_back(atr_NonPrintableMarginLeft);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNonPrintableMarginRight(level)) {
			vAtts.push_back(atr_NonPrintableMarginRight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNonPrintableMarginTop(level)) {
			vAtts.push_back(atr_NonPrintableMarginTop);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPerfectingModule(level)) {
			vAtts.push_back(atr_PerfectingModule);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPowder(level)) {
			vAtts.push_back(atr_Powder);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrintingType(level)) {
			vAtts.push_back(atr_PrintingType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetLay(level)) {
			vAtts.push_back(atr_SheetLay);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpeed(level)) {
			vAtts.push_back(atr_Speed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkStyle(level)) {
			vAtts.push_back(atr_WorkStyle);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DirectProof
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetDirectProof(bool value){
	SetAttribute(atr_DirectProof,WString::valueOf(value));
};
/**
* Get bool attribute DirectProof
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoConventionalPrintingParams::GetDirectProof() const {return GetBoolAttribute(atr_DirectProof,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidDirectProof(EnumValidationLevel level) const {
		return ValidAttribute(atr_DirectProof,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoConventionalPrintingParams::DryingString(){
		static const WString enums=WString(L"Unknown,UV,Heatset,IR,On,Off");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoConventionalPrintingParams::DryingString(EnumDrying value){
		return DryingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoConventionalPrintingParams::SetDrying( EnumDrying value){
	SetEnumAttribute(atr_Drying,value,DryingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoConventionalPrintingParams::EnumDrying JDFAutoConventionalPrintingParams:: GetDrying() const {
	return (EnumDrying) GetEnumAttribute(atr_Drying,DryingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidDrying(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Drying,DryingString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoConventionalPrintingParams::FirstSurfaceString(){
		static const WString enums=WString(L"Unknown,Either,Front,Back");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoConventionalPrintingParams::FirstSurfaceString(EnumFirstSurface value){
		return FirstSurfaceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoConventionalPrintingParams::SetFirstSurface( EnumFirstSurface value){
	SetEnumAttribute(atr_FirstSurface,value,FirstSurfaceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoConventionalPrintingParams::EnumFirstSurface JDFAutoConventionalPrintingParams:: GetFirstSurface() const {
	return (EnumFirstSurface) GetEnumAttribute(atr_FirstSurface,FirstSurfaceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidFirstSurface(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FirstSurface,FirstSurfaceString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoConventionalPrintingParams::FountainSolutionString(){
		static const WString enums=WString(L"Unknown,On,Off");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoConventionalPrintingParams::FountainSolutionString(EnumFountainSolution value){
		return FountainSolutionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoConventionalPrintingParams::SetFountainSolution( EnumFountainSolution value){
	SetEnumAttribute(atr_FountainSolution,value,FountainSolutionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoConventionalPrintingParams::EnumFountainSolution JDFAutoConventionalPrintingParams:: GetFountainSolution() const {
	return (EnumFountainSolution) GetEnumAttribute(atr_FountainSolution,FountainSolutionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidFountainSolution(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FountainSolution,FountainSolutionString(),false);
	};
/**
* Set attribute MediaLocation
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetMediaLocation(const WString& value){
	SetAttribute(atr_MediaLocation,value);
};
/**
* Get string attribute MediaLocation
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoConventionalPrintingParams::GetMediaLocation() const {
	return GetAttribute(atr_MediaLocation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidMediaLocation(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaLocation,AttributeType_string,false);
	};
/**
* Set attribute ModuleAvailableIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetModuleAvailableIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_ModuleAvailableIndex,value.GetString());
};
/**
* Get range attribute ModuleAvailableIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoConventionalPrintingParams::GetModuleAvailableIndex() const {
	return GetAttribute(atr_ModuleAvailableIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidModuleAvailableIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleAvailableIndex,AttributeType_IntegerRangeList,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoConventionalPrintingParams::SetModuleDrying( EnumDrying value){
	SetEnumAttribute(atr_ModuleDrying,value,DryingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoConventionalPrintingParams::EnumDrying JDFAutoConventionalPrintingParams:: GetModuleDrying() const {
	return (EnumDrying) GetEnumAttribute(atr_ModuleDrying,DryingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidModuleDrying(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ModuleDrying,DryingString(),false);
	};
/**
* Set attribute ModuleIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetModuleIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_ModuleIndex,value.GetString());
};
/**
* Get range attribute ModuleIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoConventionalPrintingParams::GetModuleIndex() const {
	return GetAttribute(atr_ModuleIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidModuleIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute NonPrintableMarginBottom
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetNonPrintableMarginBottom(double value){
	SetAttribute(atr_NonPrintableMarginBottom,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginBottom
* @return double the vaue of the attribute 
*/
	 double JDFAutoConventionalPrintingParams::GetNonPrintableMarginBottom() const {
	return GetRealAttribute(atr_NonPrintableMarginBottom,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidNonPrintableMarginBottom(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginBottom,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginLeft
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetNonPrintableMarginLeft(double value){
	SetAttribute(atr_NonPrintableMarginLeft,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginLeft
* @return double the vaue of the attribute 
*/
	 double JDFAutoConventionalPrintingParams::GetNonPrintableMarginLeft() const {
	return GetRealAttribute(atr_NonPrintableMarginLeft,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidNonPrintableMarginLeft(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginLeft,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginRight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetNonPrintableMarginRight(double value){
	SetAttribute(atr_NonPrintableMarginRight,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginRight
* @return double the vaue of the attribute 
*/
	 double JDFAutoConventionalPrintingParams::GetNonPrintableMarginRight() const {
	return GetRealAttribute(atr_NonPrintableMarginRight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidNonPrintableMarginRight(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginRight,AttributeType_double,false);
	};
/**
* Set attribute NonPrintableMarginTop
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetNonPrintableMarginTop(double value){
	SetAttribute(atr_NonPrintableMarginTop,WString::valueOf(value));
};
/**
* Get double attribute NonPrintableMarginTop
* @return double the vaue of the attribute 
*/
	 double JDFAutoConventionalPrintingParams::GetNonPrintableMarginTop() const {
	return GetRealAttribute(atr_NonPrintableMarginTop,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidNonPrintableMarginTop(EnumValidationLevel level) const {
		return ValidAttribute(atr_NonPrintableMarginTop,AttributeType_double,false);
	};
/**
* Set attribute PerfectingModule
*@param int value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetPerfectingModule(int value){
	SetAttribute(atr_PerfectingModule,WString::valueOf(value));
};
/**
* Get integer attribute PerfectingModule
* @return int the vaue of the attribute 
*/
	 int JDFAutoConventionalPrintingParams::GetPerfectingModule() const {
	return GetIntAttribute(atr_PerfectingModule,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidPerfectingModule(EnumValidationLevel level) const {
		return ValidAttribute(atr_PerfectingModule,AttributeType_integer,false);
	};
/**
* Set attribute Powder
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetPowder(double value){
	SetAttribute(atr_Powder,WString::valueOf(value));
};
/**
* Get double attribute Powder
* @return double the vaue of the attribute 
*/
	 double JDFAutoConventionalPrintingParams::GetPowder() const {
	return GetRealAttribute(atr_Powder,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidPowder(EnumValidationLevel level) const {
		return ValidAttribute(atr_Powder,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoConventionalPrintingParams::PrintingTypeString(){
		static const WString enums=WString(L"Unknown,ContinuousFed,SheetFed,WebFed,WebMultiple,WebSingle");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoConventionalPrintingParams::PrintingTypeString(EnumPrintingType value){
		return PrintingTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoConventionalPrintingParams::SetPrintingType( EnumPrintingType value){
	SetEnumAttribute(atr_PrintingType,value,PrintingTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoConventionalPrintingParams::EnumPrintingType JDFAutoConventionalPrintingParams:: GetPrintingType() const {
	return (EnumPrintingType) GetEnumAttribute(atr_PrintingType,PrintingTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidPrintingType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PrintingType,PrintingTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoConventionalPrintingParams::SheetLayString(){
		static const WString enums=WString(L"Unknown,Left,Right,Center");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoConventionalPrintingParams::SheetLayString(EnumSheetLay value){
		return SheetLayString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoConventionalPrintingParams::SetSheetLay( EnumSheetLay value){
	SetEnumAttribute(atr_SheetLay,value,SheetLayString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoConventionalPrintingParams::EnumSheetLay JDFAutoConventionalPrintingParams:: GetSheetLay() const {
	return (EnumSheetLay) GetEnumAttribute(atr_SheetLay,SheetLayString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidSheetLay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetLay,SheetLayString(),false);
	};
/**
* Set attribute Speed
*@param double value: the value to set the attribute to
*/
	 void JDFAutoConventionalPrintingParams::SetSpeed(double value){
	SetAttribute(atr_Speed,WString::valueOf(value));
};
/**
* Get double attribute Speed
* @return double the vaue of the attribute 
*/
	 double JDFAutoConventionalPrintingParams::GetSpeed() const {
	return GetRealAttribute(atr_Speed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidSpeed(EnumValidationLevel level) const {
		return ValidAttribute(atr_Speed,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoConventionalPrintingParams::WorkStyleString(){
		static const WString enums=WString(L"Unknown,Simplex,Perfecting,WorkAndBack,WorkAndTurn,WorkAndTumble,WorkAndTwist");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoConventionalPrintingParams::WorkStyleString(EnumWorkStyle value){
		return WorkStyleString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoConventionalPrintingParams::SetWorkStyle( EnumWorkStyle value){
	SetEnumAttribute(atr_WorkStyle,value,WorkStyleString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoConventionalPrintingParams::EnumWorkStyle JDFAutoConventionalPrintingParams:: GetWorkStyle() const {
	return (EnumWorkStyle) GetEnumAttribute(atr_WorkStyle,WorkStyleString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoConventionalPrintingParams::ValidWorkStyle(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_WorkStyle,WorkStyleString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFInk JDFAutoConventionalPrintingParams::GetInk(int iSkip)const{
	JDFInk e=GetElement(elm_Ink,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInk JDFAutoConventionalPrintingParams::GetCreateInk(int iSkip){
	JDFInk e=GetCreateElement(elm_Ink,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInk JDFAutoConventionalPrintingParams::AppendInk(){
	JDFInk e=AppendElement(elm_Ink);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoConventionalPrintingParams::RefInk(JDFInk& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoConventionalPrintingParams::GetApprovalParams()const{
	JDFApprovalParams e=GetElement(elm_ApprovalParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoConventionalPrintingParams::GetCreateApprovalParams(){
	JDFApprovalParams e=GetCreateElement(elm_ApprovalParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoConventionalPrintingParams::AppendApprovalParams(){
	JDFApprovalParams e=AppendElementN(elm_ApprovalParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoConventionalPrintingParams::RefApprovalParams(JDFApprovalParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoConventionalPrintingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Ink);

		for(i=0;i<nElem;i++){
			if (!GetInk(i).IsValid(level)) {
				vElem.AppendUnique(elm_Ink);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ApprovalParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ApprovalParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetApprovalParams().IsValid(level)) {
				vElem.AppendUnique(elm_ApprovalParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoConventionalPrintingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ApprovalParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoConventionalPrintingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Ink,ApprovalParams";
	};
}; // end namespace JDF
