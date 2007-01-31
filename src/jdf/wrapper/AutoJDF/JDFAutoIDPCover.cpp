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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIDPCover.h"
#include "jdf/wrapper/JDFIDPFinishing.h"
#include "jdf/wrapper/JDFIDPLayout.h"
#include "jdf/wrapper/JDFMediaIntent.h"
#include "jdf/wrapper/JDFMediaSource.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDPCover : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIDPCover& JDFAutoIDPCover::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIDPCover: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIDPCover::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIDPCover::ValidNodeNames()const{
	return L"*:,Cover";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIDPCover::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",BackSide,CoverType,FrontSide");
};

/**
 typesafe validator
*/
	vWString JDFAutoIDPCover::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBackSide(level)) {
			vAtts.push_back(atr_BackSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCoverType(level)) {
			vAtts.push_back(atr_CoverType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontSide(level)) {
			vAtts.push_back(atr_FrontSide);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BackSide
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoIDPCover::SetBackSide(bool value){
	SetAttribute(atr_BackSide,WString::valueOf(value));
};
/**
* Get bool attribute BackSide
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoIDPCover::GetBackSide() const {return GetBoolAttribute(atr_BackSide,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPCover::ValidBackSide(EnumValidationLevel level) const {
		return ValidAttribute(atr_BackSide,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPCover::CoverTypeString(){
		static const WString enums=WString(L"Unknown,Front,Back");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPCover::CoverTypeString(EnumCoverType value){
		return CoverTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPCover::SetCoverType( EnumCoverType value){
	SetEnumAttribute(atr_CoverType,value,CoverTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPCover::EnumCoverType JDFAutoIDPCover:: GetCoverType() const {
	return (EnumCoverType) GetEnumAttribute(atr_CoverType,CoverTypeString(),WString::emptyStr,CoverType_Front);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPCover::ValidCoverType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CoverType,CoverTypeString(),false);
	};
/**
* Set attribute FrontSide
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoIDPCover::SetFrontSide(bool value){
	SetAttribute(atr_FrontSide,WString::valueOf(value));
};
/**
* Get bool attribute FrontSide
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoIDPCover::GetFrontSide() const {return GetBoolAttribute(atr_FrontSide,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPCover::ValidFrontSide(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrontSide,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIDPFinishing JDFAutoIDPCover::GetIDPFinishing(int iSkip)const{
	JDFIDPFinishing e=GetElement(elm_IDPFinishing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFinishing JDFAutoIDPCover::GetCreateIDPFinishing(int iSkip){
	JDFIDPFinishing e=GetCreateElement(elm_IDPFinishing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFinishing JDFAutoIDPCover::AppendIDPFinishing(){
	JDFIDPFinishing e=AppendElement(elm_IDPFinishing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPCover::GetIDPLayout(int iSkip)const{
	JDFIDPLayout e=GetElement(elm_IDPLayout,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPCover::GetCreateIDPLayout(int iSkip){
	JDFIDPLayout e=GetCreateElement(elm_IDPLayout,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPCover::AppendIDPLayout(){
	JDFIDPLayout e=AppendElement(elm_IDPLayout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPCover::GetMediaIntent(int iSkip)const{
	JDFMediaIntent e=GetElement(elm_MediaIntent,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPCover::GetCreateMediaIntent(int iSkip){
	JDFMediaIntent e=GetCreateElement(elm_MediaIntent,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPCover::AppendMediaIntent(){
	JDFMediaIntent e=AppendElement(elm_MediaIntent);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIDPCover::RefMediaIntent(JDFMediaIntent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPCover::GetMediaSource(int iSkip)const{
	JDFMediaSource e=GetElement(elm_MediaSource,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPCover::GetCreateMediaSource(int iSkip){
	JDFMediaSource e=GetCreateElement(elm_MediaSource,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPCover::AppendMediaSource(){
	JDFMediaSource e=AppendElement(elm_MediaSource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIDPCover::RefMediaSource(JDFMediaSource& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoIDPCover::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_IDPFinishing);

		for(i=0;i<nElem;i++){
			if (!GetIDPFinishing(i).IsValid(level)) {
				vElem.AppendUnique(elm_IDPFinishing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IDPLayout);

		for(i=0;i<nElem;i++){
			if (!GetIDPLayout(i).IsValid(level)) {
				vElem.AppendUnique(elm_IDPLayout);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MediaIntent);

		for(i=0;i<nElem;i++){
			if (!GetMediaIntent(i).IsValid(level)) {
				vElem.AppendUnique(elm_MediaIntent);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MediaSource);

		for(i=0;i<nElem;i++){
			if (!GetMediaSource(i).IsValid(level)) {
				vElem.AppendUnique(elm_MediaSource);
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
	WString JDFAutoIDPCover::OptionalElements()const{
		return JDFElement::OptionalElements()+L",IDPFinishing,IDPLayout,MediaIntent,MediaSource";
	};
}; // end namespace JDF
