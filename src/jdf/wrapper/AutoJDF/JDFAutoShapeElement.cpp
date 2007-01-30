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

 
#include "jdf/wrapper/AutoJDF/JDFAutoShapeElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoShapeElement : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoShapeElement& JDFAutoShapeElement::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoShapeElement: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoShapeElement::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoShapeElement::ValidNodeNames()const{
	return L"*:,Shape";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoShapeElement::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ShapeType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoShapeElement::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CutBox,CutOut,CutPath,Material,CutType,ShapeDepth,StationName,TeethPerDimension");
};

/**
 typesafe validator
*/
	vWString JDFAutoShapeElement::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCutBox(level)) {
			vAtts.push_back(atr_CutBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutOut(level)) {
			vAtts.push_back(atr_CutOut);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutPath(level)) {
			vAtts.push_back(atr_CutPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaterial(level)) {
			vAtts.push_back(atr_Material);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutType(level)) {
			vAtts.push_back(atr_CutType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShapeDepth(level)) {
			vAtts.push_back(atr_ShapeDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShapeType(level)) {
			vAtts.push_back(atr_ShapeType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStationName(level)) {
			vAtts.push_back(atr_StationName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTeethPerDimension(level)) {
			vAtts.push_back(atr_TeethPerDimension);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CutBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoShapeElement::SetCutBox(const JDFRectangle& value){
	SetAttribute(atr_CutBox,value);
};
/**
* Get string attribute CutBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoShapeElement::GetCutBox() const {
	return GetAttribute(atr_CutBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidCutBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutBox,AttributeType_rectangle,false);
	};
/**
* Set attribute CutOut
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoShapeElement::SetCutOut(bool value){
	SetAttribute(atr_CutOut,WString::valueOf(value));
};
/**
* Get bool attribute CutOut
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoShapeElement::GetCutOut() const {return GetBoolAttribute(atr_CutOut,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidCutOut(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutOut,AttributeType_boolean,false);
	};
/**
* Set attribute CutPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoShapeElement::SetCutPath(const WString& value){
	SetAttribute(atr_CutPath,value);
};
/**
* Get string attribute CutPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoShapeElement::GetCutPath() const {
	return GetAttribute(atr_CutPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidCutPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutPath,AttributeType_PDFPath,false);
	};
/**
* Set attribute Material
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoShapeElement::SetMaterial(const WString& value){
	SetAttribute(atr_Material,value);
};
/**
* Get string attribute Material
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoShapeElement::GetMaterial() const {
	return GetAttribute(atr_Material,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidMaterial(EnumValidationLevel level) const {
		return ValidAttribute(atr_Material,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoShapeElement::CutTypeString(){
		static const WString enums=WString(L"Unknown,Cut,Perforate");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoShapeElement::CutTypeString(EnumCutType value){
		return CutTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoShapeElement::SetCutType( EnumCutType value){
	SetEnumAttribute(atr_CutType,value,CutTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoShapeElement::EnumCutType JDFAutoShapeElement:: GetCutType() const {
	return (EnumCutType) GetEnumAttribute(atr_CutType,CutTypeString(),WString::emptyStr,CutType_Cut);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidCutType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CutType,CutTypeString(),false);
	};
/**
* Set attribute ShapeDepth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoShapeElement::SetShapeDepth(double value){
	SetAttribute(atr_ShapeDepth,WString::valueOf(value));
};
/**
* Get double attribute ShapeDepth
* @return double the vaue of the attribute 
*/
	 double JDFAutoShapeElement::GetShapeDepth() const {
	return GetRealAttribute(atr_ShapeDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidShapeDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShapeDepth,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoShapeElement::ShapeTypeString(){
		static const WString enums=WString(L"Unknown,Rectangular,Round,Path,RoundedRectangle");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoShapeElement::ShapeTypeString(EnumShapeType value){
		return ShapeTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoShapeElement::SetShapeType( EnumShapeType value){
	SetEnumAttribute(atr_ShapeType,value,ShapeTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoShapeElement::EnumShapeType JDFAutoShapeElement:: GetShapeType() const {
	return (EnumShapeType) GetEnumAttribute(atr_ShapeType,ShapeTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidShapeType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ShapeType,ShapeTypeString(),RequiredLevel(level));
	};
/**
* Set attribute StationName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoShapeElement::SetStationName(const WString& value){
	SetAttribute(atr_StationName,value);
};
/**
* Get string attribute StationName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoShapeElement::GetStationName() const {
	return GetAttribute(atr_StationName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidStationName(EnumValidationLevel level) const {
		return ValidAttribute(atr_StationName,AttributeType_string,false);
	};
/**
* Set attribute TeethPerDimension
*@param double value: the value to set the attribute to
*/
	 void JDFAutoShapeElement::SetTeethPerDimension(double value){
	SetAttribute(atr_TeethPerDimension,WString::valueOf(value));
};
/**
* Get double attribute TeethPerDimension
* @return double the vaue of the attribute 
*/
	 double JDFAutoShapeElement::GetTeethPerDimension() const {
	return GetRealAttribute(atr_TeethPerDimension,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeElement::ValidTeethPerDimension(EnumValidationLevel level) const {
		return ValidAttribute(atr_TeethPerDimension,AttributeType_double,false);
	};
}; // end namespace JDF
