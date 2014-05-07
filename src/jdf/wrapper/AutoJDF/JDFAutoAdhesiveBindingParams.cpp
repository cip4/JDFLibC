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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAdhesiveBindingParams.h"
#include "jdf/wrapper/JDFSpinePreparationParams.h"
#include "jdf/wrapper/JDFGlueApplication.h"
#include "jdf/wrapper/JDFSpineTapingParams.h"
#include "jdf/wrapper/JDFCoverApplicationParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAdhesiveBindingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAdhesiveBindingParams& JDFAutoAdhesiveBindingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAdhesiveBindingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAdhesiveBindingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAdhesiveBindingParams::ValidNodeNames()const{
	return L"*:,AdhesiveBindingParams";
};

bool JDFAutoAdhesiveBindingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoAdhesiveBindingParams::init(){
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
	WString JDFAutoAdhesiveBindingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",PullOutValue,FlexValue");
};

/**
 typesafe validator
*/
	vWString JDFAutoAdhesiveBindingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPullOutValue(level)) {
			vAtts.push_back(atr_PullOutValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFlexValue(level)) {
			vAtts.push_back(atr_FlexValue);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PullOutValue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoAdhesiveBindingParams::SetPullOutValue(double value){
	SetAttribute(atr_PullOutValue,WString::valueOf(value));
};
/**
* Get double attribute PullOutValue
* @return double the vaue of the attribute 
*/
	 double JDFAutoAdhesiveBindingParams::GetPullOutValue() const {
	return GetRealAttribute(atr_PullOutValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdhesiveBindingParams::ValidPullOutValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_PullOutValue,AttributeType_double,false);
	};
/**
* Set attribute FlexValue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoAdhesiveBindingParams::SetFlexValue(double value){
	SetAttribute(atr_FlexValue,WString::valueOf(value));
};
/**
* Get double attribute FlexValue
* @return double the vaue of the attribute 
*/
	 double JDFAutoAdhesiveBindingParams::GetFlexValue() const {
	return GetRealAttribute(atr_FlexValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAdhesiveBindingParams::ValidFlexValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_FlexValue,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpinePreparationParams JDFAutoAdhesiveBindingParams::GetSpinePreparationParams(int iSkip)const{
	JDFSpinePreparationParams e=GetElement(elm_SpinePreparationParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpinePreparationParams JDFAutoAdhesiveBindingParams::GetCreateSpinePreparationParams(int iSkip){
	JDFSpinePreparationParams e=GetCreateElement(elm_SpinePreparationParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpinePreparationParams JDFAutoAdhesiveBindingParams::AppendSpinePreparationParams(){
	JDFSpinePreparationParams e=AppendElement(elm_SpinePreparationParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoAdhesiveBindingParams::RefSpinePreparationParams(JDFSpinePreparationParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFGlueApplication JDFAutoAdhesiveBindingParams::GetGlueApplication(int iSkip)const{
	JDFGlueApplication e=GetElement(elm_GlueApplication,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueApplication JDFAutoAdhesiveBindingParams::GetCreateGlueApplication(int iSkip){
	JDFGlueApplication e=GetCreateElement(elm_GlueApplication,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueApplication JDFAutoAdhesiveBindingParams::AppendGlueApplication(){
	JDFGlueApplication e=AppendElement(elm_GlueApplication);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoAdhesiveBindingParams::RefGlueApplication(JDFGlueApplication& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSpineTapingParams JDFAutoAdhesiveBindingParams::GetSpineTapingParams(int iSkip)const{
	JDFSpineTapingParams e=GetElement(elm_SpineTapingParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpineTapingParams JDFAutoAdhesiveBindingParams::GetCreateSpineTapingParams(int iSkip){
	JDFSpineTapingParams e=GetCreateElement(elm_SpineTapingParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpineTapingParams JDFAutoAdhesiveBindingParams::AppendSpineTapingParams(){
	JDFSpineTapingParams e=AppendElement(elm_SpineTapingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoAdhesiveBindingParams::RefSpineTapingParams(JDFSpineTapingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFCoverApplicationParams JDFAutoAdhesiveBindingParams::GetCoverApplicationParams(int iSkip)const{
	JDFCoverApplicationParams e=GetElement(elm_CoverApplicationParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCoverApplicationParams JDFAutoAdhesiveBindingParams::GetCreateCoverApplicationParams(int iSkip){
	JDFCoverApplicationParams e=GetCreateElement(elm_CoverApplicationParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCoverApplicationParams JDFAutoAdhesiveBindingParams::AppendCoverApplicationParams(){
	JDFCoverApplicationParams e=AppendElement(elm_CoverApplicationParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoAdhesiveBindingParams::RefCoverApplicationParams(JDFCoverApplicationParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoAdhesiveBindingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_SpinePreparationParams);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_SpinePreparationParams);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetSpinePreparationParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpinePreparationParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_GlueApplication);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_GlueApplication);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetGlueApplication(i).IsValid(level)) {
				vElem.AppendUnique(elm_GlueApplication);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineTapingParams);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_SpineTapingParams);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetSpineTapingParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineTapingParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CoverApplicationParams);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_CoverApplicationParams);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetCoverApplicationParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_CoverApplicationParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoAdhesiveBindingParams::RequiredElements()const{
		return JDFResource::RequiredElements()+L",SpinePreparationParams,GlueApplication,SpineTapingParams,CoverApplicationParams";
	};
}; // end namespace JDF
