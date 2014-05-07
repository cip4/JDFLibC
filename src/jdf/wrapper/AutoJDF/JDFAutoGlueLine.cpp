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

 
#include "jdf/wrapper/AutoJDF/JDFAutoGlueLine.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoGlueLine : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoGlueLine& JDFAutoGlueLine::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoGlueLine: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoGlueLine::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoGlueLine::ValidNodeNames()const{
	return L"*:,GlueLine";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoGlueLine::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AreaGlue,GlueBrand,GlueLineWidth,GluingPattern,GlueType,MeltingTemperature,RelativeStartPosition,RelativeWorkingPath,StartPosition,WorkingPath");
};

/**
 typesafe validator
*/
	vWString JDFAutoGlueLine::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAreaGlue(level)) {
			vAtts.push_back(atr_AreaGlue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGlueBrand(level)) {
			vAtts.push_back(atr_GlueBrand);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGlueLineWidth(level)) {
			vAtts.push_back(atr_GlueLineWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGluingPattern(level)) {
			vAtts.push_back(atr_GluingPattern);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGlueType(level)) {
			vAtts.push_back(atr_GlueType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMeltingTemperature(level)) {
			vAtts.push_back(atr_MeltingTemperature);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeStartPosition(level)) {
			vAtts.push_back(atr_RelativeStartPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeWorkingPath(level)) {
			vAtts.push_back(atr_RelativeWorkingPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStartPosition(level)) {
			vAtts.push_back(atr_StartPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkingPath(level)) {
			vAtts.push_back(atr_WorkingPath);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AreaGlue
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetAreaGlue(bool value){
	SetAttribute(atr_AreaGlue,WString::valueOf(value));
};
/**
* Get bool attribute AreaGlue
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoGlueLine::GetAreaGlue() const {return GetBoolAttribute(atr_AreaGlue,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidAreaGlue(EnumValidationLevel level) const {
		return ValidAttribute(atr_AreaGlue,AttributeType_boolean,false);
	};
/**
* Set attribute GlueBrand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetGlueBrand(const WString& value){
	SetAttribute(atr_GlueBrand,value);
};
/**
* Get string attribute GlueBrand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoGlueLine::GetGlueBrand() const {
	return GetAttribute(atr_GlueBrand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidGlueBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_GlueBrand,AttributeType_string,false);
	};
/**
* Set attribute GlueLineWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetGlueLineWidth(double value){
	SetAttribute(atr_GlueLineWidth,WString::valueOf(value));
};
/**
* Get double attribute GlueLineWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoGlueLine::GetGlueLineWidth() const {
	return GetRealAttribute(atr_GlueLineWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidGlueLineWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_GlueLineWidth,AttributeType_double,false);
	};
/**
* Set attribute GluingPattern
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetGluingPattern(const JDFXYPair& value){
	SetAttribute(atr_GluingPattern,value);
};
/**
* Get string attribute GluingPattern
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGlueLine::GetGluingPattern() const {
	return GetAttribute(atr_GluingPattern,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidGluingPattern(EnumValidationLevel level) const {
		return ValidAttribute(atr_GluingPattern,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoGlueLine::GlueTypeString(){
		static const WString enums=WString(L"Unknown,ColdGlue,Hotmelt,PUR");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoGlueLine::GlueTypeString(EnumGlueType value){
		return GlueTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoGlueLine::SetGlueType( EnumGlueType value){
	SetEnumAttribute(atr_GlueType,value,GlueTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoGlueLine::EnumGlueType JDFAutoGlueLine:: GetGlueType() const {
	return (EnumGlueType) GetEnumAttribute(atr_GlueType,GlueTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidGlueType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_GlueType,GlueTypeString(),false);
	};
/**
* Set attribute MeltingTemperature
*@param int value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetMeltingTemperature(int value){
	SetAttribute(atr_MeltingTemperature,WString::valueOf(value));
};
/**
* Get integer attribute MeltingTemperature
* @return int the vaue of the attribute 
*/
	 int JDFAutoGlueLine::GetMeltingTemperature() const {
	return GetIntAttribute(atr_MeltingTemperature,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidMeltingTemperature(EnumValidationLevel level) const {
		return ValidAttribute(atr_MeltingTemperature,AttributeType_integer,false);
	};
/**
* Set attribute RelativeStartPosition
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetRelativeStartPosition(const JDFXYPair& value){
	SetAttribute(atr_RelativeStartPosition,value);
};
/**
* Get string attribute RelativeStartPosition
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGlueLine::GetRelativeStartPosition() const {
	return GetAttribute(atr_RelativeStartPosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidRelativeStartPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeStartPosition,AttributeType_XYPair,false);
	};
/**
* Set attribute RelativeWorkingPath
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetRelativeWorkingPath(const JDFXYPair& value){
	SetAttribute(atr_RelativeWorkingPath,value);
};
/**
* Get string attribute RelativeWorkingPath
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGlueLine::GetRelativeWorkingPath() const {
	return GetAttribute(atr_RelativeWorkingPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidRelativeWorkingPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeWorkingPath,AttributeType_XYPair,false);
	};
/**
* Set attribute StartPosition
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetStartPosition(const JDFXYPair& value){
	SetAttribute(atr_StartPosition,value);
};
/**
* Get string attribute StartPosition
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGlueLine::GetStartPosition() const {
	return GetAttribute(atr_StartPosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidStartPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartPosition,AttributeType_XYPair,false);
	};
/**
* Set attribute WorkingPath
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoGlueLine::SetWorkingPath(const JDFXYPair& value){
	SetAttribute(atr_WorkingPath,value);
};
/**
* Get string attribute WorkingPath
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoGlueLine::GetWorkingPath() const {
	return GetAttribute(atr_WorkingPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoGlueLine::ValidWorkingPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_WorkingPath,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFQualityControlResult JDFAutoGlueLine::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoGlueLine::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoGlueLine::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoGlueLine::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoGlueLine::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_QualityControlResult);

		for(i=0;i<nElem;i++){
			if (!GetQualityControlResult(i).IsValid(level)) {
				vElem.AppendUnique(elm_QualityControlResult);
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
	WString JDFAutoGlueLine::OptionalElements()const{
		return JDFElement::OptionalElements()+L",QualityControlResult";
	};
}; // end namespace JDF
