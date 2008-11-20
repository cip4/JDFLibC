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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTrappingDetails.h"
#include "jdf/wrapper/JDFTrappingOrder.h"
#include "jdf/wrapper/JDFTrappingParams.h"
#include "jdf/wrapper/JDFObjectResolution.h"
#include "jdf/wrapper/JDFTrapRegion.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTrappingDetails : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTrappingDetails& JDFAutoTrappingDetails::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTrappingDetails: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTrappingDetails::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTrappingDetails::ValidNodeNames()const{
	return L"*:,TrappingDetails";
};

bool JDFAutoTrappingDetails::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoTrappingDetails::init(){
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
	WString JDFAutoTrappingDetails::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DefaultTrapping,IgnoreFileParams,Trapping,TrappingType");
};

/**
 typesafe validator
*/
	vWString JDFAutoTrappingDetails::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDefaultTrapping(level)) {
			vAtts.push_back(atr_DefaultTrapping);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreFileParams(level)) {
			vAtts.push_back(atr_IgnoreFileParams);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapping(level)) {
			vAtts.push_back(atr_Trapping);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrappingType(level)) {
			vAtts.push_back(atr_TrappingType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DefaultTrapping
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTrappingDetails::SetDefaultTrapping(bool value){
	SetAttribute(atr_DefaultTrapping,WString::valueOf(value));
};
/**
* Get bool attribute DefaultTrapping
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoTrappingDetails::GetDefaultTrapping() const {return GetBoolAttribute(atr_DefaultTrapping,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingDetails::ValidDefaultTrapping(EnumValidationLevel level) const {
		return ValidAttribute(atr_DefaultTrapping,AttributeType_boolean,false);
	};
/**
* Set attribute IgnoreFileParams
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTrappingDetails::SetIgnoreFileParams(bool value){
	SetAttribute(atr_IgnoreFileParams,WString::valueOf(value));
};
/**
* Get bool attribute IgnoreFileParams
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoTrappingDetails::GetIgnoreFileParams() const {return GetBoolAttribute(atr_IgnoreFileParams,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingDetails::ValidIgnoreFileParams(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreFileParams,AttributeType_boolean,false);
	};
/**
* Set attribute Trapping
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTrappingDetails::SetTrapping(bool value){
	SetAttribute(atr_Trapping,WString::valueOf(value));
};
/**
* Get bool attribute Trapping
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoTrappingDetails::GetTrapping() const {return GetBoolAttribute(atr_Trapping,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingDetails::ValidTrapping(EnumValidationLevel level) const {
		return ValidAttribute(atr_Trapping,AttributeType_boolean,false);
	};
/**
* Set attribute TrappingType
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTrappingDetails::SetTrappingType(int value){
	SetAttribute(atr_TrappingType,WString::valueOf(value));
};
/**
* Get integer attribute TrappingType
* @return int the vaue of the attribute 
*/
	 int JDFAutoTrappingDetails::GetTrappingType() const {
	return GetIntAttribute(atr_TrappingType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrappingDetails::ValidTrappingType(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrappingType,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTrappingOrder JDFAutoTrappingDetails::GetTrappingOrder()const{
	JDFTrappingOrder e=GetElement(elm_TrappingOrder);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrappingOrder JDFAutoTrappingDetails::GetCreateTrappingOrder(){
	JDFTrappingOrder e=GetCreateElement(elm_TrappingOrder);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrappingOrder JDFAutoTrappingDetails::AppendTrappingOrder(){
	JDFTrappingOrder e=AppendElementN(elm_TrappingOrder,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrappingParams JDFAutoTrappingDetails::GetTrappingParams()const{
	JDFTrappingParams e=GetElement(elm_TrappingParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrappingParams JDFAutoTrappingDetails::GetCreateTrappingParams(){
	JDFTrappingParams e=GetCreateElement(elm_TrappingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrappingParams JDFAutoTrappingDetails::AppendTrappingParams(){
	JDFTrappingParams e=AppendElementN(elm_TrappingParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoTrappingDetails::RefTrappingParams(JDFTrappingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFObjectResolution JDFAutoTrappingDetails::GetObjectResolution(int iSkip)const{
	JDFObjectResolution e=GetElement(elm_ObjectResolution,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObjectResolution JDFAutoTrappingDetails::GetCreateObjectResolution(int iSkip){
	JDFObjectResolution e=GetCreateElement(elm_ObjectResolution,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFObjectResolution JDFAutoTrappingDetails::AppendObjectResolution(){
	JDFObjectResolution e=AppendElement(elm_ObjectResolution);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoTrappingDetails::RefObjectResolution(JDFObjectResolution& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFTrapRegion JDFAutoTrappingDetails::GetTrapRegion(int iSkip)const{
	JDFTrapRegion e=GetElement(elm_TrapRegion,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrapRegion JDFAutoTrappingDetails::GetCreateTrapRegion(int iSkip){
	JDFTrapRegion e=GetCreateElement(elm_TrapRegion,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrapRegion JDFAutoTrappingDetails::AppendTrapRegion(){
	JDFTrapRegion e=AppendElement(elm_TrapRegion);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoTrappingDetails::RefTrapRegion(JDFTrapRegion& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoTrappingDetails::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_TrappingOrder);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TrappingOrder);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTrappingOrder().IsValid(level)) {
				vElem.AppendUnique(elm_TrappingOrder);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_TrappingParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TrappingParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTrappingParams().IsValid(level)) {
				vElem.AppendUnique(elm_TrappingParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ObjectResolution);

		for(i=0;i<nElem;i++){
			if (!GetObjectResolution(i).IsValid(level)) {
				vElem.AppendUnique(elm_ObjectResolution);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TrapRegion);

		for(i=0;i<nElem;i++){
			if (!GetTrapRegion(i).IsValid(level)) {
				vElem.AppendUnique(elm_TrapRegion);
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
	WString JDFAutoTrappingDetails::UniqueElements()const{
		return JDFResource::UniqueElements()+L",TrappingOrder,TrappingParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoTrappingDetails::OptionalElements()const{
		return JDFResource::OptionalElements()+L",TrappingOrder,TrappingParams,ObjectResolution,TrapRegion";
	};
}; // end namespace JDF
