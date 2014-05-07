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

 
#include "jdf/wrapper/AutoJDF/JDFAutoEmboss.h"
#include "jdf/wrapper/JDFIdentificationField.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoEmboss : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoEmboss& JDFAutoEmboss::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoEmboss: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoEmboss::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoEmboss::ValidNodeNames()const{
	return L"*:,Emboss";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoEmboss::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Direction,EmbossingType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoEmboss::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",EdgeAngle,EdgeShape,Height,ImageSize,Level,Position");
};

/**
 typesafe validator
*/
	vWString JDFAutoEmboss::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDirection(level)) {
			vAtts.push_back(atr_Direction);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEdgeAngle(level)) {
			vAtts.push_back(atr_EdgeAngle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEdgeShape(level)) {
			vAtts.push_back(atr_EdgeShape);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmbossingType(level)) {
			vAtts.push_back(atr_EmbossingType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHeight(level)) {
			vAtts.push_back(atr_Height);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImageSize(level)) {
			vAtts.push_back(atr_ImageSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLevel(level)) {
			vAtts.push_back(atr_Level);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPosition(level)) {
			vAtts.push_back(atr_Position);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoEmboss::DirectionString(){
		static const WString enums=WString(L"Unknown,Both,Flat,Raised,Depressed");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoEmboss::DirectionString(EnumDirection value){
		return DirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoEmboss::SetDirection( EnumDirection value){
	SetEnumAttribute(atr_Direction,value,DirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoEmboss::EnumDirection JDFAutoEmboss:: GetDirection() const {
	return (EnumDirection) GetEnumAttribute(atr_Direction,DirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmboss::ValidDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Direction,DirectionString(),RequiredLevel(level));
	};
/**
* Set attribute EdgeAngle
*@param double value: the value to set the attribute to
*/
	 void JDFAutoEmboss::SetEdgeAngle(double value){
	SetAttribute(atr_EdgeAngle,WString::valueOf(value));
};
/**
* Get double attribute EdgeAngle
* @return double the vaue of the attribute 
*/
	 double JDFAutoEmboss::GetEdgeAngle() const {
	return GetRealAttribute(atr_EdgeAngle,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmboss::ValidEdgeAngle(EnumValidationLevel level) const {
		return ValidAttribute(atr_EdgeAngle,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoEmboss::EdgeShapeString(){
		static const WString enums=WString(L"Unknown,Beveled,Rounded");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoEmboss::EdgeShapeString(EnumEdgeShape value){
		return EdgeShapeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoEmboss::SetEdgeShape( EnumEdgeShape value){
	SetEnumAttribute(atr_EdgeShape,value,EdgeShapeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoEmboss::EnumEdgeShape JDFAutoEmboss:: GetEdgeShape() const {
	return (EnumEdgeShape) GetEnumAttribute(atr_EdgeShape,EdgeShapeString(),WString::emptyStr,EdgeShape_Rounded);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmboss::ValidEdgeShape(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_EdgeShape,EdgeShapeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoEmboss::EmbossingTypeString(){
		static const WString enums=WString(L"Unknown,BlindEmbossing,Braille,EmbossedFinish,FoilEmbossing,FoilStamping,RegisteredEmbossing");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoEmboss::EmbossingTypeString(EnumEmbossingType value){
		return EmbossingTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoEmboss::SetEmbossingType( EnumEmbossingType value){
	SetEnumAttribute(atr_EmbossingType,value,EmbossingTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoEmboss::EnumEmbossingType JDFAutoEmboss:: GetEmbossingType() const {
	return (EnumEmbossingType) GetEnumAttribute(atr_EmbossingType,EmbossingTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmboss::ValidEmbossingType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_EmbossingType,EmbossingTypeString(),RequiredLevel(level));
	};
/**
* Set attribute Height
*@param double value: the value to set the attribute to
*/
	 void JDFAutoEmboss::SetHeight(double value){
	SetAttribute(atr_Height,WString::valueOf(value));
};
/**
* Get double attribute Height
* @return double the vaue of the attribute 
*/
	 double JDFAutoEmboss::GetHeight() const {
	return GetRealAttribute(atr_Height,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmboss::ValidHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_Height,AttributeType_double,false);
	};
/**
* Set attribute ImageSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoEmboss::SetImageSize(const JDFXYPair& value){
	SetAttribute(atr_ImageSize,value);
};
/**
* Get string attribute ImageSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoEmboss::GetImageSize() const {
	return GetAttribute(atr_ImageSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmboss::ValidImageSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImageSize,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoEmboss::LevelString(){
		static const WString enums=WString(L"Unknown,SingleLevel,MultiLevel,Sculpted");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoEmboss::LevelString(EnumLevel value){
		return LevelString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoEmboss::SetLevel( EnumLevel value){
	SetEnumAttribute(atr_Level,value,LevelString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoEmboss::EnumLevel JDFAutoEmboss:: GetLevel() const {
	return (EnumLevel) GetEnumAttribute(atr_Level,LevelString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmboss::ValidLevel(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Level,LevelString(),false);
	};
/**
* Set attribute Position
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoEmboss::SetPosition(const JDFXYPair& value){
	SetAttribute(atr_Position,value);
};
/**
* Get string attribute Position
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoEmboss::GetPosition() const {
	return GetAttribute(atr_Position,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoEmboss::ValidPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Position,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIdentificationField JDFAutoEmboss::GetIdentificationField(int iSkip)const{
	JDFIdentificationField e=GetElement(elm_IdentificationField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIdentificationField JDFAutoEmboss::GetCreateIdentificationField(int iSkip){
	JDFIdentificationField e=GetCreateElement(elm_IdentificationField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIdentificationField JDFAutoEmboss::AppendIdentificationField(){
	JDFIdentificationField e=AppendElement(elm_IdentificationField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoEmboss::RefIdentificationField(JDFIdentificationField& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoEmboss::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoEmboss::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoEmboss::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoEmboss::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoEmboss::GetTool(int iSkip)const{
	JDFMedia e=GetElement(elm_Tool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoEmboss::GetCreateTool(int iSkip){
	JDFMedia e=GetCreateElement(elm_Tool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoEmboss::AppendTool(){
	JDFMedia e=AppendElement(elm_Tool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoEmboss::RefTool(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoEmboss::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_IdentificationField);

		for(i=0;i<nElem;i++){
			if (!GetIdentificationField(i).IsValid(level)) {
				vElem.AppendUnique(elm_IdentificationField);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Media);

		for(i=0;i<nElem;i++){
			if (!GetMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_Media);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Tool);

		for(i=0;i<nElem;i++){
			if (!GetTool(i).IsValid(level)) {
				vElem.AppendUnique(elm_Tool);
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
	WString JDFAutoEmboss::OptionalElements()const{
		return JDFElement::OptionalElements()+L",IdentificationField,Media,Tool";
	};
}; // end namespace JDF
