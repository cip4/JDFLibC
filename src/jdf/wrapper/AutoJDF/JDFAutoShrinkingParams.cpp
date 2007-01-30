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

 
#include "jdf/wrapper/AutoJDF/JDFAutoShrinkingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoShrinkingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoShrinkingParams& JDFAutoShrinkingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoShrinkingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoShrinkingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoShrinkingParams::ValidNodeNames()const{
	return L"*:,ShrinkingParams";
};

bool JDFAutoShrinkingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoShrinkingParams::init(){
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
	WString JDFAutoShrinkingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ShrinkingMethod,Duration,Temperature");
};

/**
 typesafe validator
*/
	vWString JDFAutoShrinkingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidShrinkingMethod(level)) {
			vAtts.push_back(atr_ShrinkingMethod);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDuration(level)) {
			vAtts.push_back(atr_Duration);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTemperature(level)) {
			vAtts.push_back(atr_Temperature);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoShrinkingParams::ShrinkingMethodString(){
		static const WString enums=WString(L"Unknown,ShrinkCool,ShrinkHot");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoShrinkingParams::ShrinkingMethodString(EnumShrinkingMethod value){
		return ShrinkingMethodString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoShrinkingParams::SetShrinkingMethod( EnumShrinkingMethod value){
	SetEnumAttribute(atr_ShrinkingMethod,value,ShrinkingMethodString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoShrinkingParams::EnumShrinkingMethod JDFAutoShrinkingParams:: GetShrinkingMethod() const {
	return (EnumShrinkingMethod) GetEnumAttribute(atr_ShrinkingMethod,ShrinkingMethodString(),WString::emptyStr,ShrinkingMethod_ShrinkHot);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShrinkingParams::ValidShrinkingMethod(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ShrinkingMethod,ShrinkingMethodString(),false);
	};
/**
* Set attribute Duration
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoShrinkingParams::SetDuration(JDFDuration value){
	SetAttribute(atr_Duration,value.DurationISO());
};
/**
* Get string attribute Duration
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoShrinkingParams::GetDuration() const {
	return GetAttribute(atr_Duration,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShrinkingParams::ValidDuration(EnumValidationLevel level) const {
		return ValidAttribute(atr_Duration,AttributeType_duration,false);
	};
/**
* Set attribute Temperature
*@param double value: the value to set the attribute to
*/
	 void JDFAutoShrinkingParams::SetTemperature(double value){
	SetAttribute(atr_Temperature,WString::valueOf(value));
};
/**
* Get double attribute Temperature
* @return double the vaue of the attribute 
*/
	 double JDFAutoShrinkingParams::GetTemperature() const {
	return GetRealAttribute(atr_Temperature,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShrinkingParams::ValidTemperature(EnumValidationLevel level) const {
		return ValidAttribute(atr_Temperature,AttributeType_double,false);
	};
}; // end namespace JDF
