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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSpinePreparationParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSpinePreparationParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSpinePreparationParams& JDFAutoSpinePreparationParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSpinePreparationParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSpinePreparationParams::ValidNodeNames()const{
	return L"*:,SpinePreparationParams";
};

bool JDFAutoSpinePreparationParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoSpinePreparationParams::init(){
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
	WString JDFAutoSpinePreparationParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",StartPosition,FlexValue,MillingDepth,NotchingDepth,NotchingDistance,Operations,PullOutValue,WorkingLength");
};

/**
 typesafe validator
*/
	vWString JDFAutoSpinePreparationParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidStartPosition(level)) {
			vAtts.push_back(atr_StartPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFlexValue(level)) {
			vAtts.push_back(atr_FlexValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMillingDepth(level)) {
			vAtts.push_back(atr_MillingDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNotchingDepth(level)) {
			vAtts.push_back(atr_NotchingDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNotchingDistance(level)) {
			vAtts.push_back(atr_NotchingDistance);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOperations(level)) {
			vAtts.push_back(atr_Operations);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPullOutValue(level)) {
			vAtts.push_back(atr_PullOutValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkingLength(level)) {
			vAtts.push_back(atr_WorkingLength);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute StartPosition
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpinePreparationParams::SetStartPosition(double value){
	SetAttribute(atr_StartPosition,WString::valueOf(value));
};
/**
* Get double attribute StartPosition
* @return double the vaue of the attribute ; defaults to 0
*/
	 double JDFAutoSpinePreparationParams::GetStartPosition() const {
	return GetRealAttribute(atr_StartPosition,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::ValidStartPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartPosition,AttributeType_double,false);
	};
/**
* Set attribute FlexValue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpinePreparationParams::SetFlexValue(double value){
	SetAttribute(atr_FlexValue,WString::valueOf(value));
};
/**
* Get double attribute FlexValue
* @return double the vaue of the attribute 
*/
	 double JDFAutoSpinePreparationParams::GetFlexValue() const {
	return GetRealAttribute(atr_FlexValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::ValidFlexValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_FlexValue,AttributeType_double,false);
	};
/**
* Set attribute MillingDepth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpinePreparationParams::SetMillingDepth(double value){
	SetAttribute(atr_MillingDepth,WString::valueOf(value));
};
/**
* Get double attribute MillingDepth
* @return double the vaue of the attribute 
*/
	 double JDFAutoSpinePreparationParams::GetMillingDepth() const {
	return GetRealAttribute(atr_MillingDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::ValidMillingDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_MillingDepth,AttributeType_double,false);
	};
/**
* Set attribute NotchingDepth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpinePreparationParams::SetNotchingDepth(double value){
	SetAttribute(atr_NotchingDepth,WString::valueOf(value));
};
/**
* Get double attribute NotchingDepth
* @return double the vaue of the attribute 
*/
	 double JDFAutoSpinePreparationParams::GetNotchingDepth() const {
	return GetRealAttribute(atr_NotchingDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::ValidNotchingDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_NotchingDepth,AttributeType_double,false);
	};
/**
* Set attribute NotchingDistance
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpinePreparationParams::SetNotchingDistance(double value){
	SetAttribute(atr_NotchingDistance,WString::valueOf(value));
};
/**
* Get double attribute NotchingDistance
* @return double the vaue of the attribute 
*/
	 double JDFAutoSpinePreparationParams::GetNotchingDistance() const {
	return GetRealAttribute(atr_NotchingDistance,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::ValidNotchingDistance(EnumValidationLevel level) const {
		return ValidAttribute(atr_NotchingDistance,AttributeType_double,false);
	};
/**
* Set attribute Operations
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoSpinePreparationParams::SetOperations(const vWString& value){
	SetAttribute(atr_Operations,value);
};
/**
* Get string attribute Operations
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoSpinePreparationParams::GetOperations() const {
	return GetAttribute(atr_Operations,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::ValidOperations(EnumValidationLevel level) const {
		return ValidAttribute(atr_Operations,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute PullOutValue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpinePreparationParams::SetPullOutValue(double value){
	SetAttribute(atr_PullOutValue,WString::valueOf(value));
};
/**
* Get double attribute PullOutValue
* @return double the vaue of the attribute 
*/
	 double JDFAutoSpinePreparationParams::GetPullOutValue() const {
	return GetRealAttribute(atr_PullOutValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::ValidPullOutValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_PullOutValue,AttributeType_double,false);
	};
/**
* Set attribute WorkingLength
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSpinePreparationParams::SetWorkingLength(double value){
	SetAttribute(atr_WorkingLength,WString::valueOf(value));
};
/**
* Get double attribute WorkingLength
* @return double the vaue of the attribute 
*/
	 double JDFAutoSpinePreparationParams::GetWorkingLength() const {
	return GetRealAttribute(atr_WorkingLength,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpinePreparationParams::ValidWorkingLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_WorkingLength,AttributeType_double,false);
	};
}; // end namespace JDF
