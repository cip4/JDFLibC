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

 
#include "jdf/wrapper/AutoJDF/JDFAutoHeadBandApplicationParams.h"
#include "jdf/wrapper/JDFGlueLine.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoHeadBandApplicationParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoHeadBandApplicationParams& JDFAutoHeadBandApplicationParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoHeadBandApplicationParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoHeadBandApplicationParams::ValidNodeNames()const{
	return L"*:,HeadBandApplicationParams";
};

bool JDFAutoHeadBandApplicationParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoHeadBandApplicationParams::init(){
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
	WString JDFAutoHeadBandApplicationParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BottomBrand,BottomColor,BottomColorDetails,BottomLength,TopBrand,TopColor,TopColorDetails,TopLength,StripMaterial,Width");
};

/**
 typesafe validator
*/
	vWString JDFAutoHeadBandApplicationParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBottomBrand(level)) {
			vAtts.push_back(atr_BottomBrand);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBottomColor(level)) {
			vAtts.push_back(atr_BottomColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBottomColorDetails(level)) {
			vAtts.push_back(atr_BottomColorDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBottomLength(level)) {
			vAtts.push_back(atr_BottomLength);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTopBrand(level)) {
			vAtts.push_back(atr_TopBrand);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTopColor(level)) {
			vAtts.push_back(atr_TopColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTopColorDetails(level)) {
			vAtts.push_back(atr_TopColorDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTopLength(level)) {
			vAtts.push_back(atr_TopLength);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStripMaterial(level)) {
			vAtts.push_back(atr_StripMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWidth(level)) {
			vAtts.push_back(atr_Width);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BottomBrand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoHeadBandApplicationParams::SetBottomBrand(const WString& value){
	SetAttribute(atr_BottomBrand,value);
};
/**
* Get string attribute BottomBrand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoHeadBandApplicationParams::GetBottomBrand() const {
	return GetAttribute(atr_BottomBrand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidBottomBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_BottomBrand,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoHeadBandApplicationParams::SetBottomColor( EnumNamedColor value){
	SetEnumAttribute(atr_BottomColor,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoHeadBandApplicationParams::EnumNamedColor JDFAutoHeadBandApplicationParams:: GetBottomColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_BottomColor,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidBottomColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BottomColor,NamedColorString(),false);
	};
/**
* Set attribute BottomColorDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoHeadBandApplicationParams::SetBottomColorDetails(const WString& value){
	SetAttribute(atr_BottomColorDetails,value);
};
/**
* Get string attribute BottomColorDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoHeadBandApplicationParams::GetBottomColorDetails() const {
	return GetAttribute(atr_BottomColorDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidBottomColorDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_BottomColorDetails,AttributeType_string,false);
	};
/**
* Set attribute BottomLength
*@param double value: the value to set the attribute to
*/
	 void JDFAutoHeadBandApplicationParams::SetBottomLength(double value){
	SetAttribute(atr_BottomLength,WString::valueOf(value));
};
/**
* Get double attribute BottomLength
* @return double the vaue of the attribute 
*/
	 double JDFAutoHeadBandApplicationParams::GetBottomLength() const {
	return GetRealAttribute(atr_BottomLength,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidBottomLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_BottomLength,AttributeType_double,false);
	};
/**
* Set attribute TopBrand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoHeadBandApplicationParams::SetTopBrand(const WString& value){
	SetAttribute(atr_TopBrand,value);
};
/**
* Get string attribute TopBrand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoHeadBandApplicationParams::GetTopBrand() const {
	return GetAttribute(atr_TopBrand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidTopBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_TopBrand,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoHeadBandApplicationParams::SetTopColor( EnumNamedColor value){
	SetEnumAttribute(atr_TopColor,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoHeadBandApplicationParams::EnumNamedColor JDFAutoHeadBandApplicationParams:: GetTopColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_TopColor,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidTopColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_TopColor,NamedColorString(),false);
	};
/**
* Set attribute TopColorDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoHeadBandApplicationParams::SetTopColorDetails(const WString& value){
	SetAttribute(atr_TopColorDetails,value);
};
/**
* Get string attribute TopColorDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoHeadBandApplicationParams::GetTopColorDetails() const {
	return GetAttribute(atr_TopColorDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidTopColorDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_TopColorDetails,AttributeType_string,false);
	};
/**
* Set attribute TopLength
*@param double value: the value to set the attribute to
*/
	 void JDFAutoHeadBandApplicationParams::SetTopLength(double value){
	SetAttribute(atr_TopLength,WString::valueOf(value));
};
/**
* Get double attribute TopLength
* @return double the vaue of the attribute 
*/
	 double JDFAutoHeadBandApplicationParams::GetTopLength() const {
	return GetRealAttribute(atr_TopLength,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidTopLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_TopLength,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoHeadBandApplicationParams::StripMaterialString(){
		static const WString enums=WString(L"Unknown,Calico,Cardboard,CrepePaper,Gauze,Paper,PaperlinedMules,Tape");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoHeadBandApplicationParams::StripMaterialString(EnumStripMaterial value){
		return StripMaterialString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoHeadBandApplicationParams::SetStripMaterial( EnumStripMaterial value){
	SetEnumAttribute(atr_StripMaterial,value,StripMaterialString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoHeadBandApplicationParams::EnumStripMaterial JDFAutoHeadBandApplicationParams:: GetStripMaterial() const {
	return (EnumStripMaterial) GetEnumAttribute(atr_StripMaterial,StripMaterialString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidStripMaterial(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StripMaterial,StripMaterialString(),false);
	};
/**
* Set attribute Width
*@param double value: the value to set the attribute to
*/
	 void JDFAutoHeadBandApplicationParams::SetWidth(double value){
	SetAttribute(atr_Width,WString::valueOf(value));
};
/**
* Get double attribute Width
* @return double the vaue of the attribute 
*/
	 double JDFAutoHeadBandApplicationParams::GetWidth() const {
	return GetRealAttribute(atr_Width,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHeadBandApplicationParams::ValidWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_Width,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFGlueLine JDFAutoHeadBandApplicationParams::GetGlueLine(int iSkip)const{
	JDFGlueLine e=GetElement(elm_GlueLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoHeadBandApplicationParams::GetCreateGlueLine(int iSkip){
	JDFGlueLine e=GetCreateElement(elm_GlueLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoHeadBandApplicationParams::AppendGlueLine(){
	JDFGlueLine e=AppendElement(elm_GlueLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoHeadBandApplicationParams::RefGlueLine(JDFGlueLine& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoHeadBandApplicationParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_GlueLine);

		for(i=0;i<nElem;i++){
			if (!GetGlueLine(i).IsValid(level)) {
				vElem.AppendUnique(elm_GlueLine);
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
	WString JDFAutoHeadBandApplicationParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",GlueLine";
	};
}; // end namespace JDF
