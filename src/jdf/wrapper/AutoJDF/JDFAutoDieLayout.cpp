/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDieLayout.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFRuleLength.h"
#include "jdf/wrapper/JDFStation.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDieLayout : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDieLayout& JDFAutoDieLayout::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDieLayout: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDieLayout::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDieLayout::ValidNodeNames()const{
	return L"*:,DieLayout";
};

bool JDFAutoDieLayout::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoDieLayout::init(){
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
	WString JDFAutoDieLayout::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DieSide,MediaSide,Rotated,Waste");
};

/**
 typesafe validator
*/
	vWString JDFAutoDieLayout::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDieSide(level)) {
			vAtts.push_back(atr_DieSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaSide(level)) {
			vAtts.push_back(atr_MediaSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotated(level)) {
			vAtts.push_back(atr_Rotated);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWaste(level)) {
			vAtts.push_back(atr_Waste);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDieLayout::DieSideString(){
		static const WString enums=WString(L"Unknown,Up,Down");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDieLayout::DieSideString(EnumDieSide value){
		return DieSideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDieLayout::SetDieSide( EnumDieSide value){
	SetEnumAttribute(atr_DieSide,value,DieSideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDieLayout::EnumDieSide JDFAutoDieLayout:: GetDieSide() const {
	return (EnumDieSide) GetEnumAttribute(atr_DieSide,DieSideString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDieLayout::ValidDieSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DieSide,DieSideString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDieLayout::MediaSideString(){
		static const WString enums=WString(L"Unknown,Front,Back,Both");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDieLayout::MediaSideString(EnumMediaSide value){
		return MediaSideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDieLayout::SetMediaSide( EnumMediaSide value){
	SetEnumAttribute(atr_MediaSide,value,MediaSideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDieLayout::EnumMediaSide JDFAutoDieLayout:: GetMediaSide() const {
	return (EnumMediaSide) GetEnumAttribute(atr_MediaSide,MediaSideString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDieLayout::ValidMediaSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MediaSide,MediaSideString(),false);
	};
/**
* Set attribute Rotated
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoDieLayout::SetRotated(bool value){
	SetAttribute(atr_Rotated,WString::valueOf(value));
};
/**
* Get bool attribute Rotated
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoDieLayout::GetRotated() const {return GetBoolAttribute(atr_Rotated,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDieLayout::ValidRotated(EnumValidationLevel level) const {
		return ValidAttribute(atr_Rotated,AttributeType_boolean,false);
	};
/**
* Set attribute Waste
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDieLayout::SetWaste(double value){
	SetAttribute(atr_Waste,WString::valueOf(value));
};
/**
* Get double attribute Waste
* @return double the vaue of the attribute 
*/
	 double JDFAutoDieLayout::GetWaste() const {
	return GetRealAttribute(atr_Waste,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDieLayout::ValidWaste(EnumValidationLevel level) const {
		return ValidAttribute(atr_Waste,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDevice JDFAutoDieLayout::GetDevice(int iSkip)const{
	JDFDevice e=GetElement(elm_Device,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoDieLayout::GetCreateDevice(int iSkip){
	JDFDevice e=GetCreateElement(elm_Device,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoDieLayout::AppendDevice(){
	JDFDevice e=AppendElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDieLayout::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoDieLayout::GetFileSpec()const{
	JDFFileSpec e=GetElement(elm_FileSpec);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoDieLayout::GetCreateFileSpec(){
	JDFFileSpec e=GetCreateElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoDieLayout::AppendFileSpec(){
	JDFFileSpec e=AppendElementN(elm_FileSpec,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDieLayout::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDieLayout::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDieLayout::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDieLayout::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDieLayout::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFRuleLength JDFAutoDieLayout::GetRuleLength(int iSkip)const{
	JDFRuleLength e=GetElement(elm_RuleLength,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRuleLength JDFAutoDieLayout::GetCreateRuleLength(int iSkip){
	JDFRuleLength e=GetCreateElement(elm_RuleLength,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRuleLength JDFAutoDieLayout::AppendRuleLength(){
	JDFRuleLength e=AppendElement(elm_RuleLength);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStation JDFAutoDieLayout::GetStation(int iSkip)const{
	JDFStation e=GetElement(elm_Station,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStation JDFAutoDieLayout::GetCreateStation(int iSkip){
	JDFStation e=GetCreateElement(elm_Station,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStation JDFAutoDieLayout::AppendStation(){
	JDFStation e=AppendElement(elm_Station);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDieLayout::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Device);

		for(i=0;i<nElem;i++){
			if (!GetDevice(i).IsValid(level)) {
				vElem.AppendUnique(elm_Device);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FileSpec);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FileSpec);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFileSpec().IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Media);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Media);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMedia().IsValid(level)) {
				vElem.AppendUnique(elm_Media);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_RuleLength);

		for(i=0;i<nElem;i++){
			if (!GetRuleLength(i).IsValid(level)) {
				vElem.AppendUnique(elm_RuleLength);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Station);

		for(i=0;i<nElem;i++){
			if (!GetStation(i).IsValid(level)) {
				vElem.AppendUnique(elm_Station);
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
	WString JDFAutoDieLayout::UniqueElements()const{
		return JDFResource::UniqueElements()+L",FileSpec,Media";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDieLayout::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Device,FileSpec,Media,RuleLength,Station";
	};
}; // end namespace JDF
