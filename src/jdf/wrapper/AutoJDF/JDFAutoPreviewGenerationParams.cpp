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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreviewGenerationParams.h"
#include "jdf/wrapper/JDFImageSetterParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreviewGenerationParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreviewGenerationParams& JDFAutoPreviewGenerationParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreviewGenerationParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreviewGenerationParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreviewGenerationParams::ValidNodeNames()const{
	return L"*:,PreviewGenerationParams";
};

bool JDFAutoPreviewGenerationParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPreviewGenerationParams::init(){
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
	WString JDFAutoPreviewGenerationParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",AspectRatio,PreviewFileType,PreviewUsage,Compensation,Resolution,Size");
};

/**
 typesafe validator
*/
	vWString JDFAutoPreviewGenerationParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAspectRatio(level)) {
			vAtts.push_back(atr_AspectRatio);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreviewFileType(level)) {
			vAtts.push_back(atr_PreviewFileType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreviewUsage(level)) {
			vAtts.push_back(atr_PreviewUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompensation(level)) {
			vAtts.push_back(atr_Compensation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResolution(level)) {
			vAtts.push_back(atr_Resolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSize(level)) {
			vAtts.push_back(atr_Size);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreviewGenerationParams::AspectRatioString(){
		static const WString enums=WString(L"Unknown,Ignore,CenterMax,CenterMin,Crop,Expand");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreviewGenerationParams::AspectRatioString(EnumAspectRatio value){
		return AspectRatioString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreviewGenerationParams::SetAspectRatio( EnumAspectRatio value){
	SetEnumAttribute(atr_AspectRatio,value,AspectRatioString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreviewGenerationParams::EnumAspectRatio JDFAutoPreviewGenerationParams:: GetAspectRatio() const {
	return (EnumAspectRatio) GetEnumAttribute(atr_AspectRatio,AspectRatioString(),WString::emptyStr,AspectRatio_Ignore);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreviewGenerationParams::ValidAspectRatio(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_AspectRatio,AspectRatioString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreviewGenerationParams::PreviewFileTypeString(){
		static const WString enums=WString(L"Unknown,PNG,CIP3Multiple,CIP3Single");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreviewGenerationParams::PreviewFileTypeString(EnumPreviewFileType value){
		return PreviewFileTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreviewGenerationParams::SetPreviewFileType( EnumPreviewFileType value){
	SetEnumAttribute(atr_PreviewFileType,value,PreviewFileTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreviewGenerationParams::EnumPreviewFileType JDFAutoPreviewGenerationParams:: GetPreviewFileType() const {
	return (EnumPreviewFileType) GetEnumAttribute(atr_PreviewFileType,PreviewFileTypeString(),WString::emptyStr,PreviewFileType_PNG);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreviewGenerationParams::ValidPreviewFileType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreviewFileType,PreviewFileTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreviewGenerationParams::PreviewUsageString(){
		static const WString enums=WString(L"Unknown,Separation,SeparatedThumbNail,SeparationRaw,ThumbNail,Viewable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreviewGenerationParams::PreviewUsageString(EnumPreviewUsage value){
		return PreviewUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreviewGenerationParams::SetPreviewUsage( EnumPreviewUsage value){
	SetEnumAttribute(atr_PreviewUsage,value,PreviewUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreviewGenerationParams::EnumPreviewUsage JDFAutoPreviewGenerationParams:: GetPreviewUsage() const {
	return (EnumPreviewUsage) GetEnumAttribute(atr_PreviewUsage,PreviewUsageString(),WString::emptyStr,PreviewUsage_Separation);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreviewGenerationParams::ValidPreviewUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreviewUsage,PreviewUsageString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreviewGenerationParams::CompensationString(){
		static const WString enums=WString(L"Unknown,None,Film,Plate,Press");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreviewGenerationParams::CompensationString(EnumCompensation value){
		return CompensationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreviewGenerationParams::SetCompensation( EnumCompensation value){
	SetEnumAttribute(atr_Compensation,value,CompensationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreviewGenerationParams::EnumCompensation JDFAutoPreviewGenerationParams:: GetCompensation() const {
	return (EnumCompensation) GetEnumAttribute(atr_Compensation,CompensationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreviewGenerationParams::ValidCompensation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Compensation,CompensationString(),false);
	};
/**
* Set attribute Resolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPreviewGenerationParams::SetResolution(const JDFXYPair& value){
	SetAttribute(atr_Resolution,value);
};
/**
* Get string attribute Resolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPreviewGenerationParams::GetResolution() const {
	return GetAttribute(atr_Resolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreviewGenerationParams::ValidResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_Resolution,AttributeType_XYPair,false);
	};
/**
* Set attribute Size
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPreviewGenerationParams::SetSize(const JDFXYPair& value){
	SetAttribute(atr_Size,value);
};
/**
* Get string attribute Size
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPreviewGenerationParams::GetSize() const {
	return GetAttribute(atr_Size,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreviewGenerationParams::ValidSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_Size,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFImageSetterParams JDFAutoPreviewGenerationParams::GetImageSetterParams()const{
	JDFImageSetterParams e=GetElement(elm_ImageSetterParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageSetterParams JDFAutoPreviewGenerationParams::GetCreateImageSetterParams(){
	JDFImageSetterParams e=GetCreateElement(elm_ImageSetterParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageSetterParams JDFAutoPreviewGenerationParams::AppendImageSetterParams(){
	JDFImageSetterParams e=AppendElementN(elm_ImageSetterParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPreviewGenerationParams::RefImageSetterParams(JDFImageSetterParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreviewGenerationParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ImageSetterParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ImageSetterParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetImageSetterParams().IsValid(level)) {
				vElem.AppendUnique(elm_ImageSetterParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPreviewGenerationParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ImageSetterParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPreviewGenerationParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ImageSetterParams";
	};
}; // end namespace JDF
