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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSheet.h"
#include "jdf/wrapper/JDFInsertSheet.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFMediaSource.h"
#include "jdf/wrapper/JDFSurface.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSheet : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSheet& JDFAutoSheet::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSheet: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSheet::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSheet::ValidNodeNames()const{
	return L"*:,Sheet";
};

bool JDFAutoSheet::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoSheet::init(){
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
	WString JDFAutoSheet::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",LockOrigins,Name,SurfaceContentsBox");
};

/**
 typesafe validator
*/
	vWString JDFAutoSheet::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidLockOrigins(level)) {
			vAtts.push_back(atr_LockOrigins);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSurfaceContentsBox(level)) {
			vAtts.push_back(atr_SurfaceContentsBox);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute LockOrigins
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoSheet::SetLockOrigins(bool value){
	SetAttribute(atr_LockOrigins,WString::valueOf(value));
};
/**
* Get bool attribute LockOrigins
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoSheet::GetLockOrigins() const {return GetBoolAttribute(atr_LockOrigins,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSheet::ValidLockOrigins(EnumValidationLevel level) const {
		return ValidAttribute(atr_LockOrigins,AttributeType_boolean,false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSheet::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSheet::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSheet::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_string,false);
	};
/**
* Set attribute SurfaceContentsBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoSheet::SetSurfaceContentsBox(const JDFRectangle& value){
	SetAttribute(atr_SurfaceContentsBox,value);
};
/**
* Get string attribute SurfaceContentsBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoSheet::GetSurfaceContentsBox() const {
	return GetAttribute(atr_SurfaceContentsBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSheet::ValidSurfaceContentsBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SurfaceContentsBox,AttributeType_rectangle,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFInsertSheet JDFAutoSheet::GetInsertSheet(int iSkip)const{
	JDFInsertSheet e=GetElement(elm_InsertSheet,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoSheet::GetCreateInsertSheet(int iSkip){
	JDFInsertSheet e=GetCreateElement(elm_InsertSheet,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoSheet::AppendInsertSheet(){
	JDFInsertSheet e=AppendElement(elm_InsertSheet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoSheet::RefInsertSheet(JDFInsertSheet& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoSheet::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoSheet::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoSheet::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoSheet::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoSheet::GetMediaSource()const{
	JDFMediaSource e=GetElement(elm_MediaSource);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoSheet::GetCreateMediaSource(){
	JDFMediaSource e=GetCreateElement(elm_MediaSource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoSheet::AppendMediaSource(){
	JDFMediaSource e=AppendElementN(elm_MediaSource,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoSheet::RefMediaSource(JDFMediaSource& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSurface JDFAutoSheet::GetSurface(int iSkip)const{
	JDFSurface e=GetElement(elm_Surface,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSurface JDFAutoSheet::GetCreateSurface(int iSkip){
	JDFSurface e=GetCreateElement(elm_Surface,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSurface JDFAutoSheet::AppendSurface(){
	JDFSurface e=AppendElement(elm_Surface);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoSheet::RefSurface(JDFSurface& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoSheet::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_InsertSheet);

		for(i=0;i<nElem;i++){
			if (!GetInsertSheet(i).IsValid(level)) {
				vElem.AppendUnique(elm_InsertSheet);
				if (++n>=nMax)
					return vElem;
				break;
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
		nElem=NumChildElements(elm_MediaSource);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MediaSource);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMediaSource().IsValid(level)) {
				vElem.AppendUnique(elm_MediaSource);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Surface);

		for(i=0;i<nElem;i++){
			if (!GetSurface(i).IsValid(level)) {
				vElem.AppendUnique(elm_Surface);
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
	WString JDFAutoSheet::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Media,MediaSource";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoSheet::OptionalElements()const{
		return JDFResource::OptionalElements()+L",InsertSheet,Media,MediaSource,Surface";
	};
}; // end namespace JDF
