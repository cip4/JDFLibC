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

 
#include "jdf/wrapper/AutoJDF/JDFAutoThreadSealingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoThreadSealingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoThreadSealingParams& JDFAutoThreadSealingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoThreadSealingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoThreadSealingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoThreadSealingParams::ValidNodeNames()const{
	return L"*:,ThreadSealingParams";
};

bool JDFAutoThreadSealingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoThreadSealingParams::init(){
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
	WString JDFAutoThreadSealingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BlindStitch,ThreadMaterial,ThreadPositions,ThreadLength,ThreadStitchWidth,SealingTemperature");
};

/**
 typesafe validator
*/
	vWString JDFAutoThreadSealingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBlindStitch(level)) {
			vAtts.push_back(atr_BlindStitch);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadMaterial(level)) {
			vAtts.push_back(atr_ThreadMaterial);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadPositions(level)) {
			vAtts.push_back(atr_ThreadPositions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadLength(level)) {
			vAtts.push_back(atr_ThreadLength);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidThreadStitchWidth(level)) {
			vAtts.push_back(atr_ThreadStitchWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSealingTemperature(level)) {
			vAtts.push_back(atr_SealingTemperature);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BlindStitch
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoThreadSealingParams::SetBlindStitch(bool value){
	SetAttribute(atr_BlindStitch,WString::valueOf(value));
};
/**
* Get bool attribute BlindStitch
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoThreadSealingParams::GetBlindStitch() const {return GetBoolAttribute(atr_BlindStitch,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSealingParams::ValidBlindStitch(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlindStitch,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoThreadSealingParams::ThreadMaterialString(){
		static const WString enums=WString(L"Unknown,Cotton,Nylon,Polyester");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoThreadSealingParams::ThreadMaterialString(EnumThreadMaterial value){
		return ThreadMaterialString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoThreadSealingParams::SetThreadMaterial( EnumThreadMaterial value){
	SetEnumAttribute(atr_ThreadMaterial,value,ThreadMaterialString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoThreadSealingParams::EnumThreadMaterial JDFAutoThreadSealingParams:: GetThreadMaterial() const {
	return (EnumThreadMaterial) GetEnumAttribute(atr_ThreadMaterial,ThreadMaterialString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSealingParams::ValidThreadMaterial(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ThreadMaterial,ThreadMaterialString(),false);
	};
/**
* Set attribute ThreadPositions
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoThreadSealingParams::SetThreadPositions(const JDFNumberList& value){
	SetAttribute(atr_ThreadPositions,value.GetString());
};
/**
* Get string attribute ThreadPositions
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoThreadSealingParams::GetThreadPositions() const {
	return GetAttribute(atr_ThreadPositions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSealingParams::ValidThreadPositions(EnumValidationLevel level) const {
		return ValidAttribute(atr_ThreadPositions,AttributeType_NumberList,false);
	};
/**
* Set attribute ThreadLength
*@param double value: the value to set the attribute to
*/
	 void JDFAutoThreadSealingParams::SetThreadLength(double value){
	SetAttribute(atr_ThreadLength,WString::valueOf(value));
};
/**
* Get double attribute ThreadLength
* @return double the vaue of the attribute 
*/
	 double JDFAutoThreadSealingParams::GetThreadLength() const {
	return GetRealAttribute(atr_ThreadLength,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSealingParams::ValidThreadLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_ThreadLength,AttributeType_double,false);
	};
/**
* Set attribute ThreadStitchWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoThreadSealingParams::SetThreadStitchWidth(double value){
	SetAttribute(atr_ThreadStitchWidth,WString::valueOf(value));
};
/**
* Get double attribute ThreadStitchWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoThreadSealingParams::GetThreadStitchWidth() const {
	return GetRealAttribute(atr_ThreadStitchWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSealingParams::ValidThreadStitchWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_ThreadStitchWidth,AttributeType_double,false);
	};
/**
* Set attribute SealingTemperature
*@param int value: the value to set the attribute to
*/
	 void JDFAutoThreadSealingParams::SetSealingTemperature(int value){
	SetAttribute(atr_SealingTemperature,WString::valueOf(value));
};
/**
* Get integer attribute SealingTemperature
* @return int the vaue of the attribute 
*/
	 int JDFAutoThreadSealingParams::GetSealingTemperature() const {
	return GetIntAttribute(atr_SealingTemperature,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoThreadSealingParams::ValidSealingTemperature(EnumValidationLevel level) const {
		return ValidAttribute(atr_SealingTemperature,AttributeType_integer,false);
	};
}; // end namespace JDF
