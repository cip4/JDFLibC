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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDieLayoutProductionParams.h"
#include "jdf/wrapper/JDFConvertingConfig.h"
#include "jdf/wrapper/JDFRepeatDesc.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDieLayoutProductionParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDieLayoutProductionParams& JDFAutoDieLayoutProductionParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDieLayoutProductionParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDieLayoutProductionParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDieLayoutProductionParams::ValidNodeNames()const{
	return L"*:,DieLayoutProductionParams";
};

bool JDFAutoDieLayoutProductionParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoDieLayoutProductionParams::init(){
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
	WString JDFAutoDieLayoutProductionParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Estimate,Position");
};

/**
 typesafe validator
*/
	vWString JDFAutoDieLayoutProductionParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidEstimate(level)) {
			vAtts.push_back(atr_Estimate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPosition(level)) {
			vAtts.push_back(atr_Position);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Estimate
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoDieLayoutProductionParams::SetEstimate(bool value){
	SetAttribute(atr_Estimate,WString::valueOf(value));
};
/**
* Get bool attribute Estimate
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoDieLayoutProductionParams::GetEstimate() const {return GetBoolAttribute(atr_Estimate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDieLayoutProductionParams::ValidEstimate(EnumValidationLevel level) const {
		return ValidAttribute(atr_Estimate,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDieLayoutProductionParams::PositionString(){
		static const WString enums=WString(L"Unknown,TopLeft,TopCenter,TopRight,CenterLeft,Center,CenterRight,BottomLeft,BottomCenter,BottomRight");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDieLayoutProductionParams::PositionString(EnumPosition value){
		return PositionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDieLayoutProductionParams::SetPosition( EnumPosition value){
	SetEnumAttribute(atr_Position,value,PositionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDieLayoutProductionParams::EnumPosition JDFAutoDieLayoutProductionParams:: GetPosition() const {
	return (EnumPosition) GetEnumAttribute(atr_Position,PositionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDieLayoutProductionParams::ValidPosition(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Position,PositionString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFConvertingConfig JDFAutoDieLayoutProductionParams::GetConvertingConfig(int iSkip)const{
	JDFConvertingConfig e=GetElement(elm_ConvertingConfig,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFConvertingConfig JDFAutoDieLayoutProductionParams::GetCreateConvertingConfig(int iSkip){
	JDFConvertingConfig e=GetCreateElement(elm_ConvertingConfig,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFConvertingConfig JDFAutoDieLayoutProductionParams::AppendConvertingConfig(){
	JDFConvertingConfig e=AppendElement(elm_ConvertingConfig);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRepeatDesc JDFAutoDieLayoutProductionParams::GetRepeatDesc(int iSkip)const{
	JDFRepeatDesc e=GetElement(elm_RepeatDesc,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRepeatDesc JDFAutoDieLayoutProductionParams::GetCreateRepeatDesc(int iSkip){
	JDFRepeatDesc e=GetCreateElement(elm_RepeatDesc,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRepeatDesc JDFAutoDieLayoutProductionParams::AppendRepeatDesc(){
	JDFRepeatDesc e=AppendElement(elm_RepeatDesc);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDieLayoutProductionParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ConvertingConfig);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_ConvertingConfig);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetConvertingConfig(i).IsValid(level)) {
				vElem.AppendUnique(elm_ConvertingConfig);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RepeatDesc);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_RepeatDesc);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetRepeatDesc(i).IsValid(level)) {
				vElem.AppendUnique(elm_RepeatDesc);
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
	WString JDFAutoDieLayoutProductionParams::RequiredElements()const{
		return JDFResource::RequiredElements()+L",ConvertingConfig,RepeatDesc";
	};
}; // end namespace JDF
