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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMediaSource.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFComponent.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMediaSource : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMediaSource& JDFAutoMediaSource::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMediaSource: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMediaSource::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMediaSource::ValidNodeNames()const{
	return L"*:,MediaSource";
};

bool JDFAutoMediaSource::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoMediaSource::init(){
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
	WString JDFAutoMediaSource::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ManualFeed,LeadingEdge,MediaLocation,SheetLay");
};

/**
 typesafe validator
*/
	vWString JDFAutoMediaSource::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidManualFeed(level)) {
			vAtts.push_back(atr_ManualFeed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLeadingEdge(level)) {
			vAtts.push_back(atr_LeadingEdge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaLocation(level)) {
			vAtts.push_back(atr_MediaLocation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetLay(level)) {
			vAtts.push_back(atr_SheetLay);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ManualFeed
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMediaSource::SetManualFeed(bool value){
	SetAttribute(atr_ManualFeed,WString::valueOf(value));
};
/**
* Get bool attribute ManualFeed
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMediaSource::GetManualFeed() const {return GetBoolAttribute(atr_ManualFeed,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMediaSource::ValidManualFeed(EnumValidationLevel level) const {
		return ValidAttribute(atr_ManualFeed,AttributeType_boolean,false);
	};
/**
* Set attribute LeadingEdge
*@param double value: the value to set the attribute to
*/
	 void JDFAutoMediaSource::SetLeadingEdge(double value){
	SetAttribute(atr_LeadingEdge,WString::valueOf(value));
};
/**
* Get double attribute LeadingEdge
* @return double the vaue of the attribute 
*/
	 double JDFAutoMediaSource::GetLeadingEdge() const {
	return GetRealAttribute(atr_LeadingEdge,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMediaSource::ValidLeadingEdge(EnumValidationLevel level) const {
		return ValidAttribute(atr_LeadingEdge,AttributeType_double,false);
	};
/**
* Set attribute MediaLocation
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMediaSource::SetMediaLocation(const WString& value){
	SetAttribute(atr_MediaLocation,value);
};
/**
* Get string attribute MediaLocation
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMediaSource::GetMediaLocation() const {
	return GetAttribute(atr_MediaLocation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMediaSource::ValidMediaLocation(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaLocation,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoMediaSource::SheetLayString(){
		static const WString enums=WString(L"Unknown,Left,Right,Center");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoMediaSource::SheetLayString(EnumSheetLay value){
		return SheetLayString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoMediaSource::SetSheetLay( EnumSheetLay value){
	SetEnumAttribute(atr_SheetLay,value,SheetLayString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoMediaSource::EnumSheetLay JDFAutoMediaSource:: GetSheetLay() const {
	return (EnumSheetLay) GetEnumAttribute(atr_SheetLay,SheetLayString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMediaSource::ValidSheetLay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetLay,SheetLayString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFMedia JDFAutoMediaSource::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoMediaSource::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoMediaSource::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMediaSource::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoMediaSource::GetComponent()const{
	JDFComponent e=GetElement(elm_Component);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoMediaSource::GetCreateComponent(){
	JDFComponent e=GetCreateElement(elm_Component);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoMediaSource::AppendComponent(){
	JDFComponent e=AppendElementN(elm_Component,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoMediaSource::RefComponent(JDFComponent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoMediaSource::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
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
		nElem=NumChildElements(elm_Component);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Component);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetComponent().IsValid(level)) {
				vElem.AppendUnique(elm_Component);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoMediaSource::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Media,Component";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoMediaSource::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Media,Component";
	};
}; // end namespace JDF
