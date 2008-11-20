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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPalletizingParams.h"
#include "jdf/wrapper/JDFBundle.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPalletizingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPalletizingParams& JDFAutoPalletizingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPalletizingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPalletizingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPalletizingParams::ValidNodeNames()const{
	return L"*:,PalletizingParams";
};

bool JDFAutoPalletizingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPalletizingParams::init(){
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
	WString JDFAutoPalletizingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",LayerAmount,MaxHeight,MaxWeight,Overhang,OverhangOffset,Pattern");
};

/**
 typesafe validator
*/
	vWString JDFAutoPalletizingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidLayerAmount(level)) {
			vAtts.push_back(atr_LayerAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxHeight(level)) {
			vAtts.push_back(atr_MaxHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxWeight(level)) {
			vAtts.push_back(atr_MaxWeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverhang(level)) {
			vAtts.push_back(atr_Overhang);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverhangOffset(level)) {
			vAtts.push_back(atr_OverhangOffset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPattern(level)) {
			vAtts.push_back(atr_Pattern);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute LayerAmount
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoPalletizingParams::SetLayerAmount(const JDFIntegerList& value){
	SetAttribute(atr_LayerAmount,value.GetString());
};
/**
* Get string attribute LayerAmount
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoPalletizingParams::GetLayerAmount() const {
	return GetAttribute(atr_LayerAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPalletizingParams::ValidLayerAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayerAmount,AttributeType_IntegerList,false);
	};
/**
* Set attribute MaxHeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPalletizingParams::SetMaxHeight(double value){
	SetAttribute(atr_MaxHeight,WString::valueOf(value));
};
/**
* Get double attribute MaxHeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoPalletizingParams::GetMaxHeight() const {
	return GetRealAttribute(atr_MaxHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPalletizingParams::ValidMaxHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxHeight,AttributeType_double,false);
	};
/**
* Set attribute MaxWeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPalletizingParams::SetMaxWeight(double value){
	SetAttribute(atr_MaxWeight,WString::valueOf(value));
};
/**
* Get double attribute MaxWeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoPalletizingParams::GetMaxWeight() const {
	return GetRealAttribute(atr_MaxWeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPalletizingParams::ValidMaxWeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxWeight,AttributeType_double,false);
	};
/**
* Set attribute Overhang
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPalletizingParams::SetOverhang(const JDFXYPair& value){
	SetAttribute(atr_Overhang,value);
};
/**
* Get string attribute Overhang
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPalletizingParams::GetOverhang() const {
	return GetAttribute(atr_Overhang,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPalletizingParams::ValidOverhang(EnumValidationLevel level) const {
		return ValidAttribute(atr_Overhang,AttributeType_XYPair,false);
	};
/**
* Set attribute OverhangOffset
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPalletizingParams::SetOverhangOffset(const JDFXYPair& value){
	SetAttribute(atr_OverhangOffset,value);
};
/**
* Get string attribute OverhangOffset
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPalletizingParams::GetOverhangOffset() const {
	return GetAttribute(atr_OverhangOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPalletizingParams::ValidOverhangOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_OverhangOffset,AttributeType_XYPair,false);
	};
/**
* Set attribute Pattern
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPalletizingParams::SetPattern(const WString& value){
	SetAttribute(atr_Pattern,value);
};
/**
* Get string attribute Pattern
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPalletizingParams::GetPattern() const {
	return GetAttribute(atr_Pattern,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPalletizingParams::ValidPattern(EnumValidationLevel level) const {
		return ValidAttribute(atr_Pattern,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBundle JDFAutoPalletizingParams::GetBundle(int iSkip)const{
	JDFBundle e=GetElement(elm_Bundle,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBundle JDFAutoPalletizingParams::GetCreateBundle(int iSkip){
	JDFBundle e=GetCreateElement(elm_Bundle,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBundle JDFAutoPalletizingParams::AppendBundle(){
	JDFBundle e=AppendElement(elm_Bundle);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPalletizingParams::RefBundle(JDFBundle& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPalletizingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Bundle);

		for(i=0;i<nElem;i++){
			if (!GetBundle(i).IsValid(level)) {
				vElem.AppendUnique(elm_Bundle);
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
	WString JDFAutoPalletizingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Bundle";
	};
}; // end namespace JDF
