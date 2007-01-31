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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSpineTapingParams.h"
#include "jdf/wrapper/JDFGlueApplication.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSpineTapingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSpineTapingParams& JDFAutoSpineTapingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSpineTapingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSpineTapingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSpineTapingParams::ValidNodeNames()const{
	return L"*:,SpineTapingParams";
};

bool JDFAutoSpineTapingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoSpineTapingParams::init(){
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
	WString JDFAutoSpineTapingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",TopExcess,HorizontalExcess,StripBrand,StripColor,StripLength,StripMaterial");
};

/**
 typesafe validator
*/
	vWString JDFAutoSpineTapingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTopExcess(level)) {
			vAtts.push_back(atr_TopExcess);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHorizontalExcess(level)) {
			vAtts.push_back(atr_HorizontalExcess);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStripBrand(level)) {
			vAtts.push_back(atr_StripBrand);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStripColor(level)) {
			vAtts.push_back(atr_StripColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStripLength(level)) {
			vAtts.push_back(atr_StripLength);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStripMaterial(level)) {
			vAtts.push_back(atr_StripMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute TopExcess
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpineTapingParams::SetTopExcess(double value){
	SetAttribute(atr_TopExcess,WString::valueOf(value));
};
/**
* Get double attribute TopExcess
* @return double the vaue of the attribute ; defaults to 0.0
*/
	 double JDFAutoSpineTapingParams::GetTopExcess() const {
	return GetRealAttribute(atr_TopExcess,WString::emptyStr,0.0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpineTapingParams::ValidTopExcess(EnumValidationLevel level) const {
		return ValidAttribute(atr_TopExcess,AttributeType_double,false);
	};
/**
* Set attribute HorizontalExcess
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpineTapingParams::SetHorizontalExcess(double value){
	SetAttribute(atr_HorizontalExcess,WString::valueOf(value));
};
/**
* Get double attribute HorizontalExcess
* @return double the vaue of the attribute 
*/
	 double JDFAutoSpineTapingParams::GetHorizontalExcess() const {
	return GetRealAttribute(atr_HorizontalExcess,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpineTapingParams::ValidHorizontalExcess(EnumValidationLevel level) const {
		return ValidAttribute(atr_HorizontalExcess,AttributeType_double,false);
	};
/**
* Set attribute StripBrand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSpineTapingParams::SetStripBrand(const WString& value){
	SetAttribute(atr_StripBrand,value);
};
/**
* Get string attribute StripBrand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSpineTapingParams::GetStripBrand() const {
	return GetAttribute(atr_StripBrand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpineTapingParams::ValidStripBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_StripBrand,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoSpineTapingParams::SetStripColor( EnumNamedColor value){
	SetEnumAttribute(atr_StripColor,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSpineTapingParams::EnumNamedColor JDFAutoSpineTapingParams:: GetStripColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_StripColor,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpineTapingParams::ValidStripColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StripColor,NamedColorString(),false);
	};
/**
* Set attribute StripLength
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpineTapingParams::SetStripLength(double value){
	SetAttribute(atr_StripLength,WString::valueOf(value));
};
/**
* Get double attribute StripLength
* @return double the vaue of the attribute 
*/
	 double JDFAutoSpineTapingParams::GetStripLength() const {
	return GetRealAttribute(atr_StripLength,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpineTapingParams::ValidStripLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_StripLength,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSpineTapingParams::StripMaterialString(){
		static const WString enums=WString(L"Unknown,Calico,Cardboard,CrepePaper,Gauze,Paper,PaperlinedMules,Tape");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSpineTapingParams::StripMaterialString(EnumStripMaterial value){
		return StripMaterialString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSpineTapingParams::SetStripMaterial( EnumStripMaterial value){
	SetEnumAttribute(atr_StripMaterial,value,StripMaterialString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSpineTapingParams::EnumStripMaterial JDFAutoSpineTapingParams:: GetStripMaterial() const {
	return (EnumStripMaterial) GetEnumAttribute(atr_StripMaterial,StripMaterialString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpineTapingParams::ValidStripMaterial(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StripMaterial,StripMaterialString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFGlueApplication JDFAutoSpineTapingParams::GetGlueApplication(int iSkip)const{
	JDFGlueApplication e=GetElement(elm_GlueApplication,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueApplication JDFAutoSpineTapingParams::GetCreateGlueApplication(int iSkip){
	JDFGlueApplication e=GetCreateElement(elm_GlueApplication,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueApplication JDFAutoSpineTapingParams::AppendGlueApplication(){
	JDFGlueApplication e=AppendElement(elm_GlueApplication);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoSpineTapingParams::RefGlueApplication(JDFGlueApplication& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoSpineTapingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_GlueApplication);

		for(i=0;i<nElem;i++){
			if (!GetGlueApplication(i).IsValid(level)) {
				vElem.AppendUnique(elm_GlueApplication);
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
	WString JDFAutoSpineTapingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",GlueApplication";
	};
}; // end namespace JDF
