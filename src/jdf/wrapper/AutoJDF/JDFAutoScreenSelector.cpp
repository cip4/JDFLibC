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

 
#include "jdf/wrapper/AutoJDF/JDFAutoScreenSelector.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoScreenSelector : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoScreenSelector& JDFAutoScreenSelector::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoScreenSelector: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoScreenSelector::ValidNodeNames()const{
	return L"*:,ScreenSelector";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoScreenSelector::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Angle,AngleMap,DotSize,Frequency,ObjectTags,ScreeningFamily,ScreeningType,Separation,SourceFrequency,SourceObjects,SpotFunction");
};

/**
 typesafe validator
*/
	vWString JDFAutoScreenSelector::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAngle(level)) {
			vAtts.push_back(atr_Angle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAngleMap(level)) {
			vAtts.push_back(atr_AngleMap);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDotSize(level)) {
			vAtts.push_back(atr_DotSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrequency(level)) {
			vAtts.push_back(atr_Frequency);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidObjectTags(level)) {
			vAtts.push_back(atr_ObjectTags);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScreeningFamily(level)) {
			vAtts.push_back(atr_ScreeningFamily);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidScreeningType(level)) {
			vAtts.push_back(atr_ScreeningType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSeparation(level)) {
			vAtts.push_back(atr_Separation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceFrequency(level)) {
			vAtts.push_back(atr_SourceFrequency);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceObjects(level)) {
			vAtts.push_back(atr_SourceObjects);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpotFunction(level)) {
			vAtts.push_back(atr_SpotFunction);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Angle
*@param double value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetAngle(double value){
	SetAttribute(atr_Angle,WString::valueOf(value));
};
/**
* Get double attribute Angle
* @return double the vaue of the attribute 
*/
	 double JDFAutoScreenSelector::GetAngle() const {
	return GetRealAttribute(atr_Angle,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidAngle(EnumValidationLevel level) const {
		return ValidAttribute(atr_Angle,AttributeType_double,false);
	};
/**
* Set attribute AngleMap
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetAngleMap(const WString& value){
	SetAttribute(atr_AngleMap,value);
};
/**
* Get string attribute AngleMap
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoScreenSelector::GetAngleMap() const {
	return GetAttribute(atr_AngleMap,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidAngleMap(EnumValidationLevel level) const {
		return ValidAttribute(atr_AngleMap,AttributeType_string,false);
	};
/**
* Set attribute DotSize
*@param double value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetDotSize(double value){
	SetAttribute(atr_DotSize,WString::valueOf(value));
};
/**
* Get double attribute DotSize
* @return double the vaue of the attribute 
*/
	 double JDFAutoScreenSelector::GetDotSize() const {
	return GetRealAttribute(atr_DotSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidDotSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_DotSize,AttributeType_double,false);
	};
/**
* Set attribute Frequency
*@param double value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetFrequency(double value){
	SetAttribute(atr_Frequency,WString::valueOf(value));
};
/**
* Get double attribute Frequency
* @return double the vaue of the attribute 
*/
	 double JDFAutoScreenSelector::GetFrequency() const {
	return GetRealAttribute(atr_Frequency,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidFrequency(EnumValidationLevel level) const {
		return ValidAttribute(atr_Frequency,AttributeType_double,false);
	};
/**
* Set attribute ObjectTags
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetObjectTags(const vWString& value){
	SetAttribute(atr_ObjectTags,value);
};
/**
* Get string attribute ObjectTags
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoScreenSelector::GetObjectTags() const {
	return GetAttribute(atr_ObjectTags,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidObjectTags(EnumValidationLevel level) const {
		return ValidAttribute(atr_ObjectTags,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute ScreeningFamily
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetScreeningFamily(const WString& value){
	SetAttribute(atr_ScreeningFamily,value);
};
/**
* Get string attribute ScreeningFamily
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoScreenSelector::GetScreeningFamily() const {
	return GetAttribute(atr_ScreeningFamily,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidScreeningFamily(EnumValidationLevel level) const {
		return ValidAttribute(atr_ScreeningFamily,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoScreenSelector::ScreeningTypeString(){
		static const WString enums=WString(L"Unknown,AM,FM,Adaptive,ErrorDiffusion,HybridAM-FM,HybridAMline-dot");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoScreenSelector::ScreeningTypeString(EnumScreeningType value){
		return ScreeningTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoScreenSelector::SetScreeningType( EnumScreeningType value){
	SetEnumAttribute(atr_ScreeningType,value,ScreeningTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoScreenSelector::EnumScreeningType JDFAutoScreenSelector:: GetScreeningType() const {
	return (EnumScreeningType) GetEnumAttribute(atr_ScreeningType,ScreeningTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidScreeningType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ScreeningType,ScreeningTypeString(),false);
	};
/**
* Set attribute Separation
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetSeparation(const WString& value){
	SetAttribute(atr_Separation,value);
};
/**
* Get string attribute Separation
* @return WString the vaue of the attribute ; defaults to All
*/
	 WString JDFAutoScreenSelector::GetSeparation() const {
	return GetAttribute(atr_Separation,WString::emptyStr,L"All");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidSeparation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Separation,AttributeType_string,false);
	};
/**
* Set attribute SourceFrequency
*@param NumberRange value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetSourceFrequency(const NumberRange& value){
	SetAttribute(atr_SourceFrequency,value.GetString());
};
/**
* Get range attribute SourceFrequency
* @return NumberRange the vaue of the attribute 
*/
	 NumberRange JDFAutoScreenSelector::GetSourceFrequency() const {
	return GetAttribute(atr_SourceFrequency,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidSourceFrequency(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceFrequency,AttributeType_Any,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoScreenSelector::SourceObjectsString(){
		static const WString enums=WString(L"Unknown,All,ImagePhotographic,ImageScreenShot,Text,LineArt,SmoothShades");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoScreenSelector::SourceObjectsString(EnumSourceObjects value){
		return SourceObjectsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoScreenSelector::AddSourceObjects( EnumSourceObjects value){
	return AddEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoScreenSelector::RemoveSourceObjects( EnumSourceObjects value){
	return RemoveEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoScreenSelector::GetSourceObjects() const {
	return GetEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),WString::emptyStr,(unsigned int)SourceObjects_All);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoScreenSelector::SetSourceObjects( EnumSourceObjects value){
	SetEnumAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoScreenSelector::SetSourceObjects( const vint& value){
	SetEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/**
* Typesafe attribute validation of SourceObjects
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidSourceObjects(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),false);
	};
/**
* Set attribute SpotFunction
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoScreenSelector::SetSpotFunction(const WString& value){
	SetAttribute(atr_SpotFunction,value);
};
/**
* Get string attribute SpotFunction
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoScreenSelector::GetSpotFunction() const {
	return GetAttribute(atr_SpotFunction,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScreenSelector::ValidSpotFunction(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpotFunction,AttributeType_NMTOKEN,false);
	};
}; // end namespace JDF
