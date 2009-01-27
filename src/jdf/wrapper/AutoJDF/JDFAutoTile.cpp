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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTile.h"
#include "jdf/wrapper/JDFMarkObject.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFMediaSource.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTile : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTile& JDFAutoTile::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTile: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTile::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTile::ValidNodeNames()const{
	return L"*:,Tile";
};

bool JDFAutoTile::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoTile::init(){
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
	WString JDFAutoTile::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",ClipBox,CTM";
};

/**
 typesafe validator
*/
	vWString JDFAutoTile::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidClipBox(level)) {
			vAtts.push_back(atr_ClipBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCTM(level)) {
			vAtts.push_back(atr_CTM);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoTile::SetClipBox(const JDFRectangle& value){
	SetAttribute(atr_ClipBox,value);
};
/**
* Get string attribute ClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoTile::GetClipBox() const {
	return GetAttribute(atr_ClipBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTile::ValidClipBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipBox,AttributeType_rectangle,RequiredLevel(level));
	};
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoTile::SetCTM(const JDFMatrix& value){
	SetAttribute(atr_CTM,value);
};
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoTile::GetCTM() const {
	return GetAttribute(atr_CTM,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTile::ValidCTM(EnumValidationLevel level) const {
		return ValidAttribute(atr_CTM,AttributeType_matrix,RequiredLevel(level));
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFMarkObject JDFAutoTile::GetMarkObject(int iSkip)const{
	JDFMarkObject e=GetElement(elm_MarkObject,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMarkObject JDFAutoTile::GetCreateMarkObject(int iSkip){
	JDFMarkObject e=GetCreateElement(elm_MarkObject,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMarkObject JDFAutoTile::AppendMarkObject(){
	JDFMarkObject e=AppendElement(elm_MarkObject);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoTile::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoTile::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoTile::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoTile::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoTile::GetMediaSource()const{
	JDFMediaSource e=GetElement(elm_MediaSource);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoTile::GetCreateMediaSource(){
	JDFMediaSource e=GetCreateElement(elm_MediaSource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoTile::AppendMediaSource(){
	JDFMediaSource e=AppendElementN(elm_MediaSource,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoTile::RefMediaSource(JDFMediaSource& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoTile::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_MarkObject);

		for(i=0;i<nElem;i++){
			if (!GetMarkObject(i).IsValid(level)) {
				vElem.AppendUnique(elm_MarkObject);
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
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoTile::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Media,MediaSource";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoTile::OptionalElements()const{
		return JDFResource::OptionalElements()+L",MarkObject,Media,MediaSource";
	};
}; // end namespace JDF
