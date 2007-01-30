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

 
#include "jdf/wrapper/AutoJDF/JDFAutoStackingParams.h"
#include "jdf/wrapper/JDFDisjointing.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoStackingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoStackingParams& JDFAutoStackingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoStackingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoStackingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoStackingParams::ValidNodeNames()const{
	return L"*:,StackingParams";
};

bool JDFAutoStackingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoStackingParams::init(){
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
	WString JDFAutoStackingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Compensate,LayerAmount,MaxAmount,MinAmount,MaxWeight,Offset,UnderLays,StandardAmount");
};

/**
 typesafe validator
*/
	vWString JDFAutoStackingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCompensate(level)) {
			vAtts.push_back(atr_Compensate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayerAmount(level)) {
			vAtts.push_back(atr_LayerAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxAmount(level)) {
			vAtts.push_back(atr_MaxAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinAmount(level)) {
			vAtts.push_back(atr_MinAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxWeight(level)) {
			vAtts.push_back(atr_MaxWeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOffset(level)) {
			vAtts.push_back(atr_Offset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUnderLays(level)) {
			vAtts.push_back(atr_UnderLays);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStandardAmount(level)) {
			vAtts.push_back(atr_StandardAmount);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Compensate
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoStackingParams::SetCompensate(bool value){
	SetAttribute(atr_Compensate,WString::valueOf(value));
};
/**
* Get bool attribute Compensate
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoStackingParams::GetCompensate() const {return GetBoolAttribute(atr_Compensate,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStackingParams::ValidCompensate(EnumValidationLevel level) const {
		return ValidAttribute(atr_Compensate,AttributeType_boolean,false);
	};
/**
* Set attribute LayerAmount
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoStackingParams::SetLayerAmount(const JDFIntegerList& value){
	SetAttribute(atr_LayerAmount,value.GetString());
};
/**
* Get string attribute LayerAmount
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoStackingParams::GetLayerAmount() const {
	return GetAttribute(atr_LayerAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStackingParams::ValidLayerAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayerAmount,AttributeType_IntegerList,false);
	};
/**
* Set attribute MaxAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoStackingParams::SetMaxAmount(int value){
	SetAttribute(atr_MaxAmount,WString::valueOf(value));
};
/**
* Get integer attribute MaxAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoStackingParams::GetMaxAmount() const {
	return GetIntAttribute(atr_MaxAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStackingParams::ValidMaxAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxAmount,AttributeType_integer,false);
	};
/**
* Set attribute MinAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoStackingParams::SetMinAmount(int value){
	SetAttribute(atr_MinAmount,WString::valueOf(value));
};
/**
* Get integer attribute MinAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoStackingParams::GetMinAmount() const {
	return GetIntAttribute(atr_MinAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStackingParams::ValidMinAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinAmount,AttributeType_integer,false);
	};
/**
* Set attribute MaxWeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStackingParams::SetMaxWeight(double value){
	SetAttribute(atr_MaxWeight,WString::valueOf(value));
};
/**
* Get double attribute MaxWeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoStackingParams::GetMaxWeight() const {
	return GetRealAttribute(atr_MaxWeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStackingParams::ValidMaxWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxWeight,AttributeType_double,false);
	};
/**
* Set attribute Offset
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoStackingParams::SetOffset(bool value){
	SetAttribute(atr_Offset,WString::valueOf(value));
};
/**
* Get bool attribute Offset
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoStackingParams::GetOffset() const {return GetBoolAttribute(atr_Offset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStackingParams::ValidOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_Offset,AttributeType_boolean,false);
	};
/**
* Set attribute UnderLays
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoStackingParams::SetUnderLays(const JDFIntegerList& value){
	SetAttribute(atr_UnderLays,value.GetString());
};
/**
* Get string attribute UnderLays
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoStackingParams::GetUnderLays() const {
	return GetAttribute(atr_UnderLays,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStackingParams::ValidUnderLays(EnumValidationLevel level) const {
		return ValidAttribute(atr_UnderLays,AttributeType_IntegerList,false);
	};
/**
* Set attribute StandardAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoStackingParams::SetStandardAmount(int value){
	SetAttribute(atr_StandardAmount,WString::valueOf(value));
};
/**
* Get integer attribute StandardAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoStackingParams::GetStandardAmount() const {
	return GetIntAttribute(atr_StandardAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStackingParams::ValidStandardAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_StandardAmount,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDisjointing JDFAutoStackingParams::GetDisjointing()const{
	JDFDisjointing e=GetElement(elm_Disjointing);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisjointing JDFAutoStackingParams::GetCreateDisjointing(){
	JDFDisjointing e=GetCreateElement(elm_Disjointing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisjointing JDFAutoStackingParams::AppendDisjointing(){
	JDFDisjointing e=AppendElementN(elm_Disjointing,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoStackingParams::RefDisjointing(JDFDisjointing& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoStackingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Disjointing);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Disjointing);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDisjointing().IsValid(level)) {
				vElem.AppendUnique(elm_Disjointing);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoStackingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Disjointing";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoStackingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Disjointing";
	};
}; // end namespace JDF
