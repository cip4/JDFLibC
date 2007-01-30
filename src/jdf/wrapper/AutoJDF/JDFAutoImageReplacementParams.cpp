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

 
#include "jdf/wrapper/AutoJDF/JDFAutoImageReplacementParams.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoImageReplacementParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoImageReplacementParams& JDFAutoImageReplacementParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoImageReplacementParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoImageReplacementParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoImageReplacementParams::ValidNodeNames()const{
	return L"*:,ImageReplacementParams";
};

bool JDFAutoImageReplacementParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoImageReplacementParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoImageReplacementParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",ImageReplacementStrategy";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoImageReplacementParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ImagePreScanStrategy,MaxResolution,MinResolution,ResolutionReductionStrategy,IgnoreExtensions,MaxSearchRecursion");
};

/**
 typesafe validator
*/
	vWString JDFAutoImageReplacementParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidImageReplacementStrategy(level)) {
			vAtts.push_back(atr_ImageReplacementStrategy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidImagePreScanStrategy(level)) {
			vAtts.push_back(atr_ImagePreScanStrategy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxResolution(level)) {
			vAtts.push_back(atr_MaxResolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinResolution(level)) {
			vAtts.push_back(atr_MinResolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResolutionReductionStrategy(level)) {
			vAtts.push_back(atr_ResolutionReductionStrategy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnoreExtensions(level)) {
			vAtts.push_back(atr_IgnoreExtensions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxSearchRecursion(level)) {
			vAtts.push_back(atr_MaxSearchRecursion);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageReplacementParams::ImageReplacementStrategyString(){
		static const WString enums=WString(L"Unknown,Omit,Proxy,Replace,AttemptReplacement");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageReplacementParams::ImageReplacementStrategyString(EnumImageReplacementStrategy value){
		return ImageReplacementStrategyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageReplacementParams::SetImageReplacementStrategy( EnumImageReplacementStrategy value){
	SetEnumAttribute(atr_ImageReplacementStrategy,value,ImageReplacementStrategyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageReplacementParams::EnumImageReplacementStrategy JDFAutoImageReplacementParams:: GetImageReplacementStrategy() const {
	return (EnumImageReplacementStrategy) GetEnumAttribute(atr_ImageReplacementStrategy,ImageReplacementStrategyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageReplacementParams::ValidImageReplacementStrategy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ImageReplacementStrategy,ImageReplacementStrategyString(),RequiredLevel(level));
	};
/**
* Set attribute ImagePreScanStrategy
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoImageReplacementParams::SetImagePreScanStrategy(const WString& value){
	SetAttribute(atr_ImagePreScanStrategy,value);
};
/**
* Get string attribute ImagePreScanStrategy
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoImageReplacementParams::GetImagePreScanStrategy() const {
	return GetAttribute(atr_ImagePreScanStrategy,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageReplacementParams::ValidImagePreScanStrategy(EnumValidationLevel level) const {
		return ValidAttribute(atr_ImagePreScanStrategy,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute MaxResolution
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageReplacementParams::SetMaxResolution(double value){
	SetAttribute(atr_MaxResolution,WString::valueOf(value));
};
/**
* Get double attribute MaxResolution
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageReplacementParams::GetMaxResolution() const {
	return GetRealAttribute(atr_MaxResolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageReplacementParams::ValidMaxResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxResolution,AttributeType_double,false);
	};
/**
* Set attribute MinResolution
*@param double value: the value to set the attribute to
*/
	 void JDFAutoImageReplacementParams::SetMinResolution(double value){
	SetAttribute(atr_MinResolution,WString::valueOf(value));
};
/**
* Get double attribute MinResolution
* @return double the vaue of the attribute 
*/
	 double JDFAutoImageReplacementParams::GetMinResolution() const {
	return GetRealAttribute(atr_MinResolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageReplacementParams::ValidMinResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinResolution,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageReplacementParams::ResolutionReductionStrategyString(){
		static const WString enums=WString(L"Unknown,Downsample,Subsample,Bicubic");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageReplacementParams::ResolutionReductionStrategyString(EnumResolutionReductionStrategy value){
		return ResolutionReductionStrategyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageReplacementParams::SetResolutionReductionStrategy( EnumResolutionReductionStrategy value){
	SetEnumAttribute(atr_ResolutionReductionStrategy,value,ResolutionReductionStrategyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageReplacementParams::EnumResolutionReductionStrategy JDFAutoImageReplacementParams:: GetResolutionReductionStrategy() const {
	return (EnumResolutionReductionStrategy) GetEnumAttribute(atr_ResolutionReductionStrategy,ResolutionReductionStrategyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageReplacementParams::ValidResolutionReductionStrategy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ResolutionReductionStrategy,ResolutionReductionStrategyString(),false);
	};
/**
* Set attribute IgnoreExtensions
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoImageReplacementParams::SetIgnoreExtensions(const vWString& value){
	SetAttribute(atr_IgnoreExtensions,value);
};
/**
* Get string attribute IgnoreExtensions
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoImageReplacementParams::GetIgnoreExtensions() const {
	return GetAttribute(atr_IgnoreExtensions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageReplacementParams::ValidIgnoreExtensions(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnoreExtensions,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute MaxSearchRecursion
*@param int value: the value to set the attribute to
*/
	 void JDFAutoImageReplacementParams::SetMaxSearchRecursion(int value){
	SetAttribute(atr_MaxSearchRecursion,WString::valueOf(value));
};
/**
* Get integer attribute MaxSearchRecursion
* @return int the vaue of the attribute 
*/
	 int JDFAutoImageReplacementParams::GetMaxSearchRecursion() const {
	return GetIntAttribute(atr_MaxSearchRecursion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageReplacementParams::ValidMaxSearchRecursion(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxSearchRecursion,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoImageReplacementParams::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoImageReplacementParams::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoImageReplacementParams::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoImageReplacementParams::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFElement JDFAutoImageReplacementParams::GetSearchPath(int iSkip)const{
	JDFElement e=GetElement(elm_SearchPath,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElement JDFAutoImageReplacementParams::GetCreateSearchPath(int iSkip){
	JDFElement e=GetCreateElement(elm_SearchPath,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElement JDFAutoImageReplacementParams::AppendSearchPath(){
	JDFElement e=AppendElement(elm_SearchPath);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoImageReplacementParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_FileSpec);

		for(i=0;i<nElem;i++){
			if (!GetFileSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SearchPath);

		for(i=0;i<nElem;i++){
			if (!GetSearchPath(i).IsValid(level)) {
				vElem.AppendUnique(elm_SearchPath);
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
	WString JDFAutoImageReplacementParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",FileSpec,SearchPath";
	};
}; // end namespace JDF
