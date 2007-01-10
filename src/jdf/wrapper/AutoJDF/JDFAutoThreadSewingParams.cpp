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

 
#include "jdf/wrapper/AutoJDF/JDFAutoThreadSewingParams.h"
#include "jdf/wrapper/JDFGlueLine.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoThreadSewingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoThreadSewingParams& JDFAutoThreadSewingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoThreadSewingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoThreadSewingParams::ValidNodeNames()const{
	return L"*:,ThreadSewingParams";
};

bool JDFAutoThreadSewingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoThreadSewingParams::init(){
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
	WString JDFAutoThreadSewingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BlindStitch,CastingMaterial,CoreMaterial,GlueLineRefSheets,Offset,NeedlePositions,NumberOfNeedles,Sealing,SewingPattern,ThreadThickness,ThreadBrand");
};

/**
 typesafe validator
*/
	vWString JDFAutoThreadSewingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBlindStitch(level)) {
			vAtts.push_back(atr_BlindStitch);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCastingMaterial(level)) {
			vAtts.push_back(atr_CastingMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCoreMaterial(level)) {
			vAtts.push_back(atr_CoreMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGlueLineRefSheets(level)) {
			vAtts.push_back(atr_GlueLineRefSheets);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOffset(level)) {
			vAtts.push_back(atr_Offset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNeedlePositions(level)) {
			vAtts.push_back(atr_NeedlePositions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberOfNeedles(level)) {
			vAtts.push_back(atr_NumberOfNeedles);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSealing(level)) {
			vAtts.push_back(atr_Sealing);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSewingPattern(level)) {
			vAtts.push_back(atr_SewingPattern);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadThickness(level)) {
			vAtts.push_back(atr_ThreadThickness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadBrand(level)) {
			vAtts.push_back(atr_ThreadBrand);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BlindStitch
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoThreadSewingParams::SetBlindStitch(bool value){
	SetAttribute(atr_BlindStitch,WString::valueOf(value));
};
/**
* Get bool attribute BlindStitch
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoThreadSewingParams::GetBlindStitch() const {return GetBoolAttribute(atr_BlindStitch,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidBlindStitch(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlindStitch,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoThreadSewingParams::CastingMaterialString(){
		static const WString enums=WString(L"Unknown,Cotton,Nylon,Polyester");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoThreadSewingParams::CastingMaterialString(EnumCastingMaterial value){
		return CastingMaterialString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoThreadSewingParams::SetCastingMaterial( EnumCastingMaterial value){
	SetEnumAttribute(atr_CastingMaterial,value,CastingMaterialString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoThreadSewingParams::EnumCastingMaterial JDFAutoThreadSewingParams:: GetCastingMaterial() const {
	return (EnumCastingMaterial) GetEnumAttribute(atr_CastingMaterial,CastingMaterialString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidCastingMaterial(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CastingMaterial,CastingMaterialString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoThreadSewingParams::CoreMaterialString(){
		static const WString enums=WString(L"Unknown,Cotton,Nylon,Polyester");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoThreadSewingParams::CoreMaterialString(EnumCoreMaterial value){
		return CoreMaterialString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoThreadSewingParams::SetCoreMaterial( EnumCoreMaterial value){
	SetEnumAttribute(atr_CoreMaterial,value,CoreMaterialString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoThreadSewingParams::EnumCoreMaterial JDFAutoThreadSewingParams:: GetCoreMaterial() const {
	return (EnumCoreMaterial) GetEnumAttribute(atr_CoreMaterial,CoreMaterialString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidCoreMaterial(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CoreMaterial,CoreMaterialString(),false);
	};
/**
* Set attribute GlueLineRefSheets
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoThreadSewingParams::SetGlueLineRefSheets(const JDFIntegerList& value){
	SetAttribute(atr_GlueLineRefSheets,value.GetString());
};
/**
* Get string attribute GlueLineRefSheets
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoThreadSewingParams::GetGlueLineRefSheets() const {
	return GetAttribute(atr_GlueLineRefSheets,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidGlueLineRefSheets(EnumValidationLevel level) const {
		return ValidAttribute(atr_GlueLineRefSheets,AttributeType_IntegerList,false);
	};
/**
* Set attribute Offset
*@param double value: the value to set the attribute to
*/
	 void JDFAutoThreadSewingParams::SetOffset(double value){
	SetAttribute(atr_Offset,WString::valueOf(value));
};
/**
* Get double attribute Offset
* @return double the vaue of the attribute 
*/
	 double JDFAutoThreadSewingParams::GetOffset() const {
	return GetRealAttribute(atr_Offset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_Offset,AttributeType_double,false);
	};
/**
* Set attribute NeedlePositions
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoThreadSewingParams::SetNeedlePositions(const JDFNumberList& value){
	SetAttribute(atr_NeedlePositions,value.GetString());
};
/**
* Get string attribute NeedlePositions
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoThreadSewingParams::GetNeedlePositions() const {
	return GetAttribute(atr_NeedlePositions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidNeedlePositions(EnumValidationLevel level) const {
		return ValidAttribute(atr_NeedlePositions,AttributeType_NumberList,false);
	};
/**
* Set attribute NumberOfNeedles
*@param int value: the value to set the attribute to
*/
	 void JDFAutoThreadSewingParams::SetNumberOfNeedles(int value){
	SetAttribute(atr_NumberOfNeedles,WString::valueOf(value));
};
/**
* Get integer attribute NumberOfNeedles
* @return int the vaue of the attribute 
*/
	 int JDFAutoThreadSewingParams::GetNumberOfNeedles() const {
	return GetIntAttribute(atr_NumberOfNeedles,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidNumberOfNeedles(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberOfNeedles,AttributeType_integer,false);
	};
/**
* Set attribute Sealing
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoThreadSewingParams::SetSealing(bool value){
	SetAttribute(atr_Sealing,WString::valueOf(value));
};
/**
* Get bool attribute Sealing
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoThreadSewingParams::GetSealing() const {return GetBoolAttribute(atr_Sealing,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidSealing(EnumValidationLevel level) const {
		return ValidAttribute(atr_Sealing,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoThreadSewingParams::SewingPatternString(){
		static const WString enums=WString(L"Unknown,Normal,Staggered,CombinedStaggered,Side");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoThreadSewingParams::SewingPatternString(EnumSewingPattern value){
		return SewingPatternString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoThreadSewingParams::SetSewingPattern( EnumSewingPattern value){
	SetEnumAttribute(atr_SewingPattern,value,SewingPatternString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoThreadSewingParams::EnumSewingPattern JDFAutoThreadSewingParams:: GetSewingPattern() const {
	return (EnumSewingPattern) GetEnumAttribute(atr_SewingPattern,SewingPatternString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidSewingPattern(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SewingPattern,SewingPatternString(),false);
	};
/**
* Set attribute ThreadThickness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoThreadSewingParams::SetThreadThickness(double value){
	SetAttribute(atr_ThreadThickness,WString::valueOf(value));
};
/**
* Get double attribute ThreadThickness
* @return double the vaue of the attribute 
*/
	 double JDFAutoThreadSewingParams::GetThreadThickness() const {
	return GetRealAttribute(atr_ThreadThickness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidThreadThickness(EnumValidationLevel level) const {
		return ValidAttribute(atr_ThreadThickness,AttributeType_double,false);
	};
/**
* Set attribute ThreadBrand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoThreadSewingParams::SetThreadBrand(const WString& value){
	SetAttribute(atr_ThreadBrand,value);
};
/**
* Get string attribute ThreadBrand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoThreadSewingParams::GetThreadBrand() const {
	return GetAttribute(atr_ThreadBrand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSewingParams::ValidThreadBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_ThreadBrand,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFGlueLine JDFAutoThreadSewingParams::GetGlueLine(int iSkip)const{
	JDFGlueLine e=GetElement(elm_GlueLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoThreadSewingParams::GetCreateGlueLine(int iSkip){
	JDFGlueLine e=GetCreateElement(elm_GlueLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoThreadSewingParams::AppendGlueLine(){
	JDFGlueLine e=AppendElement(elm_GlueLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoThreadSewingParams::RefGlueLine(JDFGlueLine& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoThreadSewingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoThreadSewingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",GlueLine";
	};
}; // end namespace JDF
