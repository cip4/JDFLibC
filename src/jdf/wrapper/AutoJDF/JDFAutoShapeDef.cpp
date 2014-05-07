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

 
#include "jdf/wrapper/AutoJDF/JDFAutoShapeDef.h"
#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFShapeElement.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoShapeDef : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoShapeDef& JDFAutoShapeDef::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoShapeDef: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoShapeDef::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoShapeDef::ValidNodeNames()const{
	return L"*:,ShapeDef";
};

bool JDFAutoShapeDef::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoShapeDef::init(){
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
	WString JDFAutoShapeDef::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",LockOrigins,Area,CutBox,Dimensions,FlatDimensions,FluteDirection,GrainDirection,MediaSide,ResourceWeight");
};

/**
 typesafe validator
*/
	vWString JDFAutoShapeDef::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidLockOrigins(level)) {
			vAtts.push_back(atr_LockOrigins);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidArea(level)) {
			vAtts.push_back(atr_Area);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutBox(level)) {
			vAtts.push_back(atr_CutBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDimensions(level)) {
			vAtts.push_back(atr_Dimensions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFlatDimensions(level)) {
			vAtts.push_back(atr_FlatDimensions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFluteDirection(level)) {
			vAtts.push_back(atr_FluteDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGrainDirection(level)) {
			vAtts.push_back(atr_GrainDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaSide(level)) {
			vAtts.push_back(atr_MediaSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceWeight(level)) {
			vAtts.push_back(atr_ResourceWeight);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute LockOrigins
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoShapeDef::SetLockOrigins(bool value){
	SetAttribute(atr_LockOrigins,WString::valueOf(value));
};
/**
* Get bool attribute LockOrigins
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoShapeDef::GetLockOrigins() const {return GetBoolAttribute(atr_LockOrigins,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidLockOrigins(EnumValidationLevel level) const {
		return ValidAttribute(atr_LockOrigins,AttributeType_boolean,false);
	};
/**
* Set attribute Area
*@param double value: the value to set the attribute to
*/
	 void JDFAutoShapeDef::SetArea(double value){
	SetAttribute(atr_Area,WString::valueOf(value));
};
/**
* Get double attribute Area
* @return double the vaue of the attribute 
*/
	 double JDFAutoShapeDef::GetArea() const {
	return GetRealAttribute(atr_Area,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidArea(EnumValidationLevel level) const {
		return ValidAttribute(atr_Area,AttributeType_double,false);
	};
/**
* Set attribute CutBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoShapeDef::SetCutBox(const JDFRectangle& value){
	SetAttribute(atr_CutBox,value);
};
/**
* Get string attribute CutBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoShapeDef::GetCutBox() const {
	return GetAttribute(atr_CutBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidCutBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutBox,AttributeType_rectangle,false);
	};
/**
* Set attribute Dimensions
*@param JDFShape value: the value to set the attribute to
*/
	 void JDFAutoShapeDef::SetDimensions(const JDFShape& value){
	SetAttribute(atr_Dimensions,value);
};
/**
* Get string attribute Dimensions
* @return JDFShape the vaue of the attribute 
*/
	 JDFShape JDFAutoShapeDef::GetDimensions() const {
	return GetAttribute(atr_Dimensions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidDimensions(EnumValidationLevel level) const {
		return ValidAttribute(atr_Dimensions,AttributeType_shape,false);
	};
/**
* Set attribute FlatDimensions
*@param JDFShape value: the value to set the attribute to
*/
	 void JDFAutoShapeDef::SetFlatDimensions(const JDFShape& value){
	SetAttribute(atr_FlatDimensions,value);
};
/**
* Get string attribute FlatDimensions
* @return JDFShape the vaue of the attribute 
*/
	 JDFShape JDFAutoShapeDef::GetFlatDimensions() const {
	return GetAttribute(atr_FlatDimensions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidFlatDimensions(EnumValidationLevel level) const {
		return ValidAttribute(atr_FlatDimensions,AttributeType_shape,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoShapeDef::FluteDirectionString(){
		static const WString enums=WString(L"Unknown,XDirection,YDirection");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoShapeDef::FluteDirectionString(EnumFluteDirection value){
		return FluteDirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoShapeDef::SetFluteDirection( EnumFluteDirection value){
	SetEnumAttribute(atr_FluteDirection,value,FluteDirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoShapeDef::EnumFluteDirection JDFAutoShapeDef:: GetFluteDirection() const {
	return (EnumFluteDirection) GetEnumAttribute(atr_FluteDirection,FluteDirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidFluteDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FluteDirection,FluteDirectionString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoShapeDef::GrainDirectionString(){
		static const WString enums=WString(L"Unknown,XDirection,YDirection,Both");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoShapeDef::GrainDirectionString(EnumGrainDirection value){
		return GrainDirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoShapeDef::SetGrainDirection( EnumGrainDirection value){
	SetEnumAttribute(atr_GrainDirection,value,GrainDirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoShapeDef::EnumGrainDirection JDFAutoShapeDef:: GetGrainDirection() const {
	return (EnumGrainDirection) GetEnumAttribute(atr_GrainDirection,GrainDirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidGrainDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_GrainDirection,GrainDirectionString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoShapeDef::MediaSideString(){
		static const WString enums=WString(L"Unknown,Front,Back,Both");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoShapeDef::MediaSideString(EnumMediaSide value){
		return MediaSideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoShapeDef::SetMediaSide( EnumMediaSide value){
	SetEnumAttribute(atr_MediaSide,value,MediaSideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoShapeDef::EnumMediaSide JDFAutoShapeDef:: GetMediaSide() const {
	return (EnumMediaSide) GetEnumAttribute(atr_MediaSide,MediaSideString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidMediaSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MediaSide,MediaSideString(),false);
	};
/**
* Set attribute ResourceWeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoShapeDef::SetResourceWeight(double value){
	SetAttribute(atr_ResourceWeight,WString::valueOf(value));
};
/**
* Get double attribute ResourceWeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoShapeDef::GetResourceWeight() const {
	return GetRealAttribute(atr_ResourceWeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeDef::ValidResourceWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceWeight,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColorPool JDFAutoShapeDef::GetColorPool()const{
	JDFColorPool e=GetElement(elm_ColorPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoShapeDef::GetCreateColorPool(){
	JDFColorPool e=GetCreateElement(elm_ColorPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoShapeDef::AppendColorPool(){
	JDFColorPool e=AppendElementN(elm_ColorPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoShapeDef::RefColorPool(JDFColorPool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoShapeDef::GetCutLines()const{
	JDFSeparationList e=GetElement(elm_CutLines);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoShapeDef::GetCreateCutLines(){
	JDFSeparationList e=GetCreateElement(elm_CutLines);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoShapeDef::AppendCutLines(){
	JDFSeparationList e=AppendElementN(elm_CutLines,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoShapeDef::GetFileSpec()const{
	JDFFileSpec e=GetElement(elm_FileSpec);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoShapeDef::GetCreateFileSpec(){
	JDFFileSpec e=GetCreateElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoShapeDef::AppendFileSpec(){
	JDFFileSpec e=AppendElementN(elm_FileSpec,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoShapeDef::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoShapeDef::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoShapeDef::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoShapeDef::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoShapeDef::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFShapeElement JDFAutoShapeDef::GetShape()const{
	JDFShapeElement e=GetElement(elm_Shape);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeElement JDFAutoShapeDef::GetCreateShape(){
	JDFShapeElement e=GetCreateElement(elm_Shape);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeElement JDFAutoShapeDef::AppendShape(){
	JDFShapeElement e=AppendElementN(elm_Shape,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoShapeDef::RefShape(JDFShapeElement& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoShapeDef::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorPool().IsValid(level)) {
				vElem.AppendUnique(elm_ColorPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_CutLines);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CutLines);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCutLines().IsValid(level)) {
				vElem.AppendUnique(elm_CutLines);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FileSpec);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FileSpec);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFileSpec().IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
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
		nElem=NumChildElements(elm_Shape);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Shape);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetShape().IsValid(level)) {
				vElem.AppendUnique(elm_Shape);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoShapeDef::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorPool,CutLines,FileSpec,Media,Shape";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoShapeDef::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorPool,CutLines,FileSpec,Media,Shape";
	};
}; // end namespace JDF
