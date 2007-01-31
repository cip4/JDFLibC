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

 
#include "jdf/wrapper/AutoJDF/JDFAutoHoleMakingParams.h"
#include "jdf/wrapper/JDFHole.h"
#include "jdf/wrapper/JDFHoleLine.h"
#include "jdf/wrapper/JDFRegisterMark.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoHoleMakingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoHoleMakingParams& JDFAutoHoleMakingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoHoleMakingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoHoleMakingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoHoleMakingParams::ValidNodeNames()const{
	return L"*:,HoleMakingParams";
};

bool JDFAutoHoleMakingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoHoleMakingParams::init(){
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
	WString JDFAutoHoleMakingParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",HoleType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoHoleMakingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",CenterReference,Center,Extent,HoleCount,HoleReferenceEdge,Shape");
};

/**
 typesafe validator
*/
	vWString JDFAutoHoleMakingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCenterReference(level)) {
			vAtts.push_back(atr_CenterReference);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHoleType(level)) {
			vAtts.push_back(atr_HoleType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCenter(level)) {
			vAtts.push_back(atr_Center);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidExtent(level)) {
			vAtts.push_back(atr_Extent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHoleCount(level)) {
			vAtts.push_back(atr_HoleCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHoleReferenceEdge(level)) {
			vAtts.push_back(atr_HoleReferenceEdge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShape(level)) {
			vAtts.push_back(atr_Shape);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoHoleMakingParams::CenterReferenceString(){
		static const WString enums=WString(L"Unknown,TrailingEdge,RegistrationMark");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoHoleMakingParams::CenterReferenceString(EnumCenterReference value){
		return CenterReferenceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoHoleMakingParams::SetCenterReference( EnumCenterReference value){
	SetEnumAttribute(atr_CenterReference,value,CenterReferenceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoHoleMakingParams::EnumCenterReference JDFAutoHoleMakingParams:: GetCenterReference() const {
	return (EnumCenterReference) GetEnumAttribute(atr_CenterReference,CenterReferenceString(),WString::emptyStr,CenterReference_TrailingEdge);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingParams::ValidCenterReference(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CenterReference,CenterReferenceString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoHoleMakingParams::HoleTypeString(){
		static const WString enums=WString(L"Unknown,R2-generic,R2m-DIN,R2m-ISO,R2m-MIB,R2i-US-a,R2i-US-b,R3-generic,R3i-US,R4-generic")
	+WString(L",R4m-DIN-A4,R4m-DIN-A5,R4m-swedish,R4i-US,R5-generic,R5i-US-a,R5i-US-b,R5i-US-c,R6-generic,R6m-4h2s")
	+WString(L",R6m-DIN-A5,R7-generic,R7i-US-a,R7i-US-b,R7i-US-c,R11m-7h4s,P16_9i-rect-0t,P12m-rect-0t,W2_1i-round-0t,W2_1i-square-0t")
	+WString(L",W3_1i-square-0t,C9.5m-round-0t");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoHoleMakingParams::HoleTypeString(EnumHoleType value){
		return HoleTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoHoleMakingParams::AddHoleType( EnumHoleType value){
	return AddEnumerationsAttribute(atr_HoleType,value,HoleTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoHoleMakingParams::RemoveHoleType( EnumHoleType value){
	return RemoveEnumerationsAttribute(atr_HoleType,value,HoleTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoHoleMakingParams::GetHoleType() const {
	return GetEnumerationsAttribute(atr_HoleType,HoleTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoHoleMakingParams::SetHoleType( EnumHoleType value){
	SetEnumAttribute(atr_HoleType,value,HoleTypeString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoHoleMakingParams::SetHoleType( const vint& value){
	SetEnumerationsAttribute(atr_HoleType,value,HoleTypeString());
};
/**
* Typesafe attribute validation of HoleType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingParams::ValidHoleType(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_HoleType,HoleTypeString(),RequiredLevel(level));
	};
/**
* Set attribute Center
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoHoleMakingParams::SetCenter(const JDFXYPair& value){
	SetAttribute(atr_Center,value);
};
/**
* Get string attribute Center
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoHoleMakingParams::GetCenter() const {
	return GetAttribute(atr_Center,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingParams::ValidCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Center,AttributeType_XYPair,false);
	};
/**
* Set attribute Extent
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoHoleMakingParams::SetExtent(const JDFXYPair& value){
	SetAttribute(atr_Extent,value);
};
/**
* Get string attribute Extent
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoHoleMakingParams::GetExtent() const {
	return GetAttribute(atr_Extent,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingParams::ValidExtent(EnumValidationLevel level) const {
		return ValidAttribute(atr_Extent,AttributeType_XYPair,false);
	};
/**
* Set attribute HoleCount
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoHoleMakingParams::SetHoleCount(const JDFIntegerList& value){
	SetAttribute(atr_HoleCount,value.GetString());
};
/**
* Get string attribute HoleCount
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoHoleMakingParams::GetHoleCount() const {
	return GetAttribute(atr_HoleCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingParams::ValidHoleCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_HoleCount,AttributeType_IntegerList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoHoleMakingParams::HoleReferenceEdgeString(){
		static const WString enums=WString(L"Unknown,Left,Right,Top,Bottom,Pattern");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoHoleMakingParams::HoleReferenceEdgeString(EnumHoleReferenceEdge value){
		return HoleReferenceEdgeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoHoleMakingParams::SetHoleReferenceEdge( EnumHoleReferenceEdge value){
	SetEnumAttribute(atr_HoleReferenceEdge,value,HoleReferenceEdgeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoHoleMakingParams::EnumHoleReferenceEdge JDFAutoHoleMakingParams:: GetHoleReferenceEdge() const {
	return (EnumHoleReferenceEdge) GetEnumAttribute(atr_HoleReferenceEdge,HoleReferenceEdgeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingParams::ValidHoleReferenceEdge(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_HoleReferenceEdge,HoleReferenceEdgeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoHoleMakingParams::ShapeString(){
		static const WString enums=WString(L"Unknown,Eliptical,Round,Rectangular");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoHoleMakingParams::ShapeString(EnumShape value){
		return ShapeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoHoleMakingParams::SetShape( EnumShape value){
	SetEnumAttribute(atr_Shape,value,ShapeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoHoleMakingParams::EnumShape JDFAutoHoleMakingParams:: GetShape() const {
	return (EnumShape) GetEnumAttribute(atr_Shape,ShapeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingParams::ValidShape(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Shape,ShapeString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFHole JDFAutoHoleMakingParams::GetHole(int iSkip)const{
	JDFHole e=GetElement(elm_Hole,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHole JDFAutoHoleMakingParams::GetCreateHole(int iSkip){
	JDFHole e=GetCreateElement(elm_Hole,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHole JDFAutoHoleMakingParams::AppendHole(){
	JDFHole e=AppendElement(elm_Hole);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoHoleMakingParams::RefHole(JDFHole& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFHoleLine JDFAutoHoleMakingParams::GetHoleLine(int iSkip)const{
	JDFHoleLine e=GetElement(elm_HoleLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleLine JDFAutoHoleMakingParams::GetCreateHoleLine(int iSkip){
	JDFHoleLine e=GetCreateElement(elm_HoleLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleLine JDFAutoHoleMakingParams::AppendHoleLine(){
	JDFHoleLine e=AppendElement(elm_HoleLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoHoleMakingParams::RefHoleLine(JDFHoleLine& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFRegisterMark JDFAutoHoleMakingParams::GetRegisterMark()const{
	JDFRegisterMark e=GetElement(elm_RegisterMark);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterMark JDFAutoHoleMakingParams::GetCreateRegisterMark(){
	JDFRegisterMark e=GetCreateElement(elm_RegisterMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterMark JDFAutoHoleMakingParams::AppendRegisterMark(){
	JDFRegisterMark e=AppendElementN(elm_RegisterMark,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoHoleMakingParams::RefRegisterMark(JDFRegisterMark& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoHoleMakingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Hole);

		for(i=0;i<nElem;i++){
			if (!GetHole(i).IsValid(level)) {
				vElem.AppendUnique(elm_Hole);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_HoleLine);

		for(i=0;i<nElem;i++){
			if (!GetHoleLine(i).IsValid(level)) {
				vElem.AppendUnique(elm_HoleLine);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RegisterMark);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_RegisterMark);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetRegisterMark().IsValid(level)) {
				vElem.AppendUnique(elm_RegisterMark);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoHoleMakingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",RegisterMark";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoHoleMakingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Hole,HoleLine,RegisterMark";
	};
}; // end namespace JDF
