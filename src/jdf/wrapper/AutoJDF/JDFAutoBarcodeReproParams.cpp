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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBarcodeReproParams.h"
#include "jdf/wrapper/JDFBarcodeCompParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBarcodeReproParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBarcodeReproParams& JDFAutoBarcodeReproParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBarcodeReproParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBarcodeReproParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBarcodeReproParams::ValidNodeNames()const{
	return L"*:,BarcodeReproParams";
};

bool JDFAutoBarcodeReproParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoBarcodeReproParams::init(){
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
	WString JDFAutoBarcodeReproParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BearerBars,Height,Magnification,Masking,ModuleHeight,ModuleWidth,Ratio");
};

/**
 typesafe validator
*/
	vWString JDFAutoBarcodeReproParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBearerBars(level)) {
			vAtts.push_back(atr_BearerBars);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHeight(level)) {
			vAtts.push_back(atr_Height);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMagnification(level)) {
			vAtts.push_back(atr_Magnification);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMasking(level)) {
			vAtts.push_back(atr_Masking);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleHeight(level)) {
			vAtts.push_back(atr_ModuleHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleWidth(level)) {
			vAtts.push_back(atr_ModuleWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRatio(level)) {
			vAtts.push_back(atr_Ratio);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBarcodeReproParams::BearerBarsString(){
		static const WString enums=WString(L"Unknown,None,TopBottom,Box,BoxHMarks");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBarcodeReproParams::BearerBarsString(EnumBearerBars value){
		return BearerBarsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBarcodeReproParams::SetBearerBars( EnumBearerBars value){
	SetEnumAttribute(atr_BearerBars,value,BearerBarsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBarcodeReproParams::EnumBearerBars JDFAutoBarcodeReproParams:: GetBearerBars() const {
	return (EnumBearerBars) GetEnumAttribute(atr_BearerBars,BearerBarsString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeReproParams::ValidBearerBars(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BearerBars,BearerBarsString(),false);
	};
/**
* Set attribute Height
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBarcodeReproParams::SetHeight(double value){
	SetAttribute(atr_Height,WString::valueOf(value));
};
/**
* Get double attribute Height
* @return double the vaue of the attribute 
*/
	 double JDFAutoBarcodeReproParams::GetHeight() const {
	return GetRealAttribute(atr_Height,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeReproParams::ValidHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_Height,AttributeType_double,false);
	};
/**
* Set attribute Magnification
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBarcodeReproParams::SetMagnification(double value){
	SetAttribute(atr_Magnification,WString::valueOf(value));
};
/**
* Get double attribute Magnification
* @return double the vaue of the attribute 
*/
	 double JDFAutoBarcodeReproParams::GetMagnification() const {
	return GetRealAttribute(atr_Magnification,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeReproParams::ValidMagnification(EnumValidationLevel level) const {
		return ValidAttribute(atr_Magnification,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBarcodeReproParams::MaskingString(){
		static const WString enums=WString(L"Unknown,None,WhiteBox");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBarcodeReproParams::MaskingString(EnumMasking value){
		return MaskingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBarcodeReproParams::SetMasking( EnumMasking value){
	SetEnumAttribute(atr_Masking,value,MaskingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBarcodeReproParams::EnumMasking JDFAutoBarcodeReproParams:: GetMasking() const {
	return (EnumMasking) GetEnumAttribute(atr_Masking,MaskingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeReproParams::ValidMasking(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Masking,MaskingString(),false);
	};
/**
* Set attribute ModuleHeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBarcodeReproParams::SetModuleHeight(double value){
	SetAttribute(atr_ModuleHeight,WString::valueOf(value));
};
/**
* Get double attribute ModuleHeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoBarcodeReproParams::GetModuleHeight() const {
	return GetRealAttribute(atr_ModuleHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeReproParams::ValidModuleHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleHeight,AttributeType_double,false);
	};
/**
* Set attribute ModuleWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBarcodeReproParams::SetModuleWidth(double value){
	SetAttribute(atr_ModuleWidth,WString::valueOf(value));
};
/**
* Get double attribute ModuleWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoBarcodeReproParams::GetModuleWidth() const {
	return GetRealAttribute(atr_ModuleWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeReproParams::ValidModuleWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleWidth,AttributeType_double,false);
	};
/**
* Set attribute Ratio
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBarcodeReproParams::SetRatio(double value){
	SetAttribute(atr_Ratio,WString::valueOf(value));
};
/**
* Get double attribute Ratio
* @return double the vaue of the attribute 
*/
	 double JDFAutoBarcodeReproParams::GetRatio() const {
	return GetRealAttribute(atr_Ratio,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeReproParams::ValidRatio(EnumValidationLevel level) const {
		return ValidAttribute(atr_Ratio,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBarcodeCompParams JDFAutoBarcodeReproParams::GetBarcodeCompParams(int iSkip)const{
	JDFBarcodeCompParams e=GetElement(elm_BarcodeCompParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBarcodeCompParams JDFAutoBarcodeReproParams::GetCreateBarcodeCompParams(int iSkip){
	JDFBarcodeCompParams e=GetCreateElement(elm_BarcodeCompParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBarcodeCompParams JDFAutoBarcodeReproParams::AppendBarcodeCompParams(){
	JDFBarcodeCompParams e=AppendElement(elm_BarcodeCompParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoBarcodeReproParams::RefBarcodeCompParams(JDFBarcodeCompParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBarcodeReproParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BarcodeCompParams);

		for(i=0;i<nElem;i++){
			if (!GetBarcodeCompParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_BarcodeCompParams);
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
	WString JDFAutoBarcodeReproParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",BarcodeCompParams";
	};
}; // end namespace JDF
