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

 
#include "jdf/wrapper/AutoJDF/JDFAutoContactCopyParams.h"
#include "jdf/wrapper/JDFScreeningParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoContactCopyParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoContactCopyParams& JDFAutoContactCopyParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoContactCopyParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoContactCopyParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoContactCopyParams::ValidNodeNames()const{
	return L"*:,ContactCopyParams";
};

bool JDFAutoContactCopyParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoContactCopyParams::init(){
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
	WString JDFAutoContactCopyParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ContactScreen,PolarityChange,RepeatStep,Cycle,Diffusion,Vacuum");
};

/**
 typesafe validator
*/
	vWString JDFAutoContactCopyParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidContactScreen(level)) {
			vAtts.push_back(atr_ContactScreen);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPolarityChange(level)) {
			vAtts.push_back(atr_PolarityChange);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRepeatStep(level)) {
			vAtts.push_back(atr_RepeatStep);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCycle(level)) {
			vAtts.push_back(atr_Cycle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDiffusion(level)) {
			vAtts.push_back(atr_Diffusion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVacuum(level)) {
			vAtts.push_back(atr_Vacuum);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ContactScreen
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoContactCopyParams::SetContactScreen(bool value){
	SetAttribute(atr_ContactScreen,WString::valueOf(value));
};
/**
* Get bool attribute ContactScreen
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoContactCopyParams::GetContactScreen() const {return GetBoolAttribute(atr_ContactScreen,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContactCopyParams::ValidContactScreen(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContactScreen,AttributeType_boolean,false);
	};
/**
* Set attribute PolarityChange
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoContactCopyParams::SetPolarityChange(bool value){
	SetAttribute(atr_PolarityChange,WString::valueOf(value));
};
/**
* Get bool attribute PolarityChange
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoContactCopyParams::GetPolarityChange() const {return GetBoolAttribute(atr_PolarityChange,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContactCopyParams::ValidPolarityChange(EnumValidationLevel level) const {
		return ValidAttribute(atr_PolarityChange,AttributeType_boolean,false);
	};
/**
* Set attribute RepeatStep
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoContactCopyParams::SetRepeatStep(const JDFXYPair& value){
	SetAttribute(atr_RepeatStep,value);
};
/**
* Get string attribute RepeatStep
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	 JDFXYPair JDFAutoContactCopyParams::GetRepeatStep() const {
	return GetAttribute(atr_RepeatStep,WString::emptyStr,L"1 1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContactCopyParams::ValidRepeatStep(EnumValidationLevel level) const {
		return ValidAttribute(atr_RepeatStep,AttributeType_XYPair,false);
	};
/**
* Set attribute Cycle
*@param int value: the value to set the attribute to
*/
	 void JDFAutoContactCopyParams::SetCycle(int value){
	SetAttribute(atr_Cycle,WString::valueOf(value));
};
/**
* Get integer attribute Cycle
* @return int the vaue of the attribute 
*/
	 int JDFAutoContactCopyParams::GetCycle() const {
	return GetIntAttribute(atr_Cycle,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContactCopyParams::ValidCycle(EnumValidationLevel level) const {
		return ValidAttribute(atr_Cycle,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoContactCopyParams::DiffusionString(){
		static const WString enums=WString(L"Unknown,On,Off");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoContactCopyParams::DiffusionString(EnumDiffusion value){
		return DiffusionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoContactCopyParams::SetDiffusion( EnumDiffusion value){
	SetEnumAttribute(atr_Diffusion,value,DiffusionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoContactCopyParams::EnumDiffusion JDFAutoContactCopyParams:: GetDiffusion() const {
	return (EnumDiffusion) GetEnumAttribute(atr_Diffusion,DiffusionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContactCopyParams::ValidDiffusion(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Diffusion,DiffusionString(),false);
	};
/**
* Set attribute Vacuum
*@param double value: the value to set the attribute to
*/
	 void JDFAutoContactCopyParams::SetVacuum(double value){
	SetAttribute(atr_Vacuum,WString::valueOf(value));
};
/**
* Get double attribute Vacuum
* @return double the vaue of the attribute 
*/
	 double JDFAutoContactCopyParams::GetVacuum() const {
	return GetRealAttribute(atr_Vacuum,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContactCopyParams::ValidVacuum(EnumValidationLevel level) const {
		return ValidAttribute(atr_Vacuum,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFScreeningParams JDFAutoContactCopyParams::GetScreeningParams()const{
	JDFScreeningParams e=GetElement(elm_ScreeningParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoContactCopyParams::GetCreateScreeningParams(){
	JDFScreeningParams e=GetCreateElement(elm_ScreeningParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoContactCopyParams::AppendScreeningParams(){
	JDFScreeningParams e=AppendElementN(elm_ScreeningParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContactCopyParams::RefScreeningParams(JDFScreeningParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoContactCopyParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ScreeningParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ScreeningParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetScreeningParams().IsValid(level)) {
				vElem.AppendUnique(elm_ScreeningParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoContactCopyParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ScreeningParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoContactCopyParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ScreeningParams";
	};
}; // end namespace JDF
