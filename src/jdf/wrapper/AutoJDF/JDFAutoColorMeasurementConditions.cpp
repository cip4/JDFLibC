/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColorMeasurementConditions.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorMeasurementConditions : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColorMeasurementConditions& JDFAutoColorMeasurementConditions::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColorMeasurementConditions: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColorMeasurementConditions::ValidNodeNames()const{
	return L"*:,ColorMeasurementConditions";
};

bool JDFAutoColorMeasurementConditions::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoColorMeasurementConditions::init(){
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
	WString JDFAutoColorMeasurementConditions::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DensityStandard,Illumination,Observer,Instrumentation,InkState,MeasurementFilter,SampleBacking,WhiteBase");
};

/**
 typesafe validator
*/
	vWString JDFAutoColorMeasurementConditions::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDensityStandard(level)) {
			vAtts.push_back(atr_DensityStandard);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIllumination(level)) {
			vAtts.push_back(atr_Illumination);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidObserver(level)) {
			vAtts.push_back(atr_Observer);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInstrumentation(level)) {
			vAtts.push_back(atr_Instrumentation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInkState(level)) {
			vAtts.push_back(atr_InkState);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMeasurementFilter(level)) {
			vAtts.push_back(atr_MeasurementFilter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSampleBacking(level)) {
			vAtts.push_back(atr_SampleBacking);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWhiteBase(level)) {
			vAtts.push_back(atr_WhiteBase);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorMeasurementConditions::DensityStandardString(){
		static const WString enums=WString(L"Unknown,ANSIA,ANSIE,ANSII,ANSIT,DIN16536,DIN16536NB");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorMeasurementConditions::DensityStandardString(EnumDensityStandard value){
		return DensityStandardString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorMeasurementConditions::SetDensityStandard( EnumDensityStandard value){
	SetEnumAttribute(atr_DensityStandard,value,DensityStandardString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorMeasurementConditions::EnumDensityStandard JDFAutoColorMeasurementConditions:: GetDensityStandard() const {
	return (EnumDensityStandard) GetEnumAttribute(atr_DensityStandard,DensityStandardString(),WString::emptyStr,DensityStandard_ANSIT);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::ValidDensityStandard(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DensityStandard,DensityStandardString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorMeasurementConditions::IlluminationString(){
		static const WString enums=WString(L"Unknown,D50,D65");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorMeasurementConditions::IlluminationString(EnumIllumination value){
		return IlluminationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorMeasurementConditions::SetIllumination( EnumIllumination value){
	SetEnumAttribute(atr_Illumination,value,IlluminationString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorMeasurementConditions::EnumIllumination JDFAutoColorMeasurementConditions:: GetIllumination() const {
	return (EnumIllumination) GetEnumAttribute(atr_Illumination,IlluminationString(),WString::emptyStr,Illumination_D50);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::ValidIllumination(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Illumination,IlluminationString(),false,WString::emptyStr,true);
	};
/**
* Set attribute Observer
*@param int value: the value to set the attribute to
*/
	 void JDFAutoColorMeasurementConditions::SetObserver(int value){
	SetAttribute(atr_Observer,WString::valueOf(value));
};
/**
* Get integer attribute Observer
* @return int the vaue of the attribute ; defaults to 2
*/
	 int JDFAutoColorMeasurementConditions::GetObserver() const {
	return GetIntAttribute(atr_Observer,WString::emptyStr,2);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::ValidObserver(EnumValidationLevel level) const {
		return ValidAttribute(atr_Observer,AttributeType_integer,false);
	};
/**
* Set attribute Instrumentation
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColorMeasurementConditions::SetInstrumentation(const WString& value){
	SetAttribute(atr_Instrumentation,value);
};
/**
* Get string attribute Instrumentation
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColorMeasurementConditions::GetInstrumentation() const {
	return GetAttribute(atr_Instrumentation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::ValidInstrumentation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Instrumentation,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorMeasurementConditions::InkStateString(){
		static const WString enums=WString(L"Unknown,Dry,Wet,NA");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorMeasurementConditions::InkStateString(EnumInkState value){
		return InkStateString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorMeasurementConditions::SetInkState( EnumInkState value){
	SetEnumAttribute(atr_InkState,value,InkStateString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorMeasurementConditions::EnumInkState JDFAutoColorMeasurementConditions:: GetInkState() const {
	return (EnumInkState) GetEnumAttribute(atr_InkState,InkStateString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::ValidInkState(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_InkState,InkStateString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorMeasurementConditions::MeasurementFilterString(){
		static const WString enums=WString(L"Unknown,None,Pol,UV");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorMeasurementConditions::MeasurementFilterString(EnumMeasurementFilter value){
		return MeasurementFilterString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorMeasurementConditions::SetMeasurementFilter( EnumMeasurementFilter value){
	SetEnumAttribute(atr_MeasurementFilter,value,MeasurementFilterString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorMeasurementConditions::EnumMeasurementFilter JDFAutoColorMeasurementConditions:: GetMeasurementFilter() const {
	return (EnumMeasurementFilter) GetEnumAttribute(atr_MeasurementFilter,MeasurementFilterString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::ValidMeasurementFilter(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MeasurementFilter,MeasurementFilterString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorMeasurementConditions::SampleBackingString(){
		static const WString enums=WString(L"Unknown,Black,White,NA");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorMeasurementConditions::SampleBackingString(EnumSampleBacking value){
		return SampleBackingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorMeasurementConditions::SetSampleBacking( EnumSampleBacking value){
	SetEnumAttribute(atr_SampleBacking,value,SampleBackingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorMeasurementConditions::EnumSampleBacking JDFAutoColorMeasurementConditions:: GetSampleBacking() const {
	return (EnumSampleBacking) GetEnumAttribute(atr_SampleBacking,SampleBackingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::ValidSampleBacking(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SampleBacking,SampleBackingString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorMeasurementConditions::WhiteBaseString(){
		static const WString enums=WString(L"Unknown,Absolute,Paper");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorMeasurementConditions::WhiteBaseString(EnumWhiteBase value){
		return WhiteBaseString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorMeasurementConditions::SetWhiteBase( EnumWhiteBase value){
	SetEnumAttribute(atr_WhiteBase,value,WhiteBaseString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorMeasurementConditions::EnumWhiteBase JDFAutoColorMeasurementConditions:: GetWhiteBase() const {
	return (EnumWhiteBase) GetEnumAttribute(atr_WhiteBase,WhiteBaseString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorMeasurementConditions::ValidWhiteBase(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_WhiteBase,WhiteBaseString(),false);
	};
}; // end namespace JDF
