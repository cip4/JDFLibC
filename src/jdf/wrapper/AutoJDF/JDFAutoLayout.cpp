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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLayout.h"
#include "jdf/wrapper/JDFContentObject.h"
#include "jdf/wrapper/JDFInsertSheet.h"
#include "jdf/wrapper/JDFLayerList.h"
#include "jdf/wrapper/JDFMarkObject.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFMediaSource.h"
#include "jdf/wrapper/JDFSignature.h"
#include "jdf/wrapper/JDFTransferCurvePool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLayout : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLayout& JDFAutoLayout::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLayout: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLayout::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLayout::ValidNodeNames()const{
	return L"*:,Layout";
};

bool JDFAutoLayout::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoLayout::init(){
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
	WString JDFAutoLayout::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Automated,LockOrigins,MaxDocOrd,MaxSetOrd,Name,MaxOrd,SourceWorkStyle,SurfaceContentsBox");
};

/**
 typesafe validator
*/
	vWString JDFAutoLayout::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAutomated(level)) {
			vAtts.push_back(atr_Automated);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLockOrigins(level)) {
			vAtts.push_back(atr_LockOrigins);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxDocOrd(level)) {
			vAtts.push_back(atr_MaxDocOrd);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxSetOrd(level)) {
			vAtts.push_back(atr_MaxSetOrd);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxOrd(level)) {
			vAtts.push_back(atr_MaxOrd);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceWorkStyle(level)) {
			vAtts.push_back(atr_SourceWorkStyle);
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
* Set attribute Automated
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayout::SetAutomated(bool value){
	SetAttribute(atr_Automated,WString::valueOf(value));
};
/**
* Get bool attribute Automated
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoLayout::GetAutomated() const {return GetBoolAttribute(atr_Automated,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayout::ValidAutomated(EnumValidationLevel level) const {
		return ValidAttribute(atr_Automated,AttributeType_boolean,false);
	};
/**
* Set attribute LockOrigins
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayout::SetLockOrigins(bool value){
	SetAttribute(atr_LockOrigins,WString::valueOf(value));
};
/**
* Get bool attribute LockOrigins
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoLayout::GetLockOrigins() const {return GetBoolAttribute(atr_LockOrigins,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayout::ValidLockOrigins(EnumValidationLevel level) const {
		return ValidAttribute(atr_LockOrigins,AttributeType_boolean,false);
	};
/**
* Set attribute MaxDocOrd
*@param int value: the value to set the attribute to
*/
	 void JDFAutoLayout::SetMaxDocOrd(int value){
	SetAttribute(atr_MaxDocOrd,WString::valueOf(value));
};
/**
* Get integer attribute MaxDocOrd
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoLayout::GetMaxDocOrd() const {
	return GetIntAttribute(atr_MaxDocOrd,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayout::ValidMaxDocOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxDocOrd,AttributeType_integer,false);
	};
/**
* Set attribute MaxSetOrd
*@param int value: the value to set the attribute to
*/
	 void JDFAutoLayout::SetMaxSetOrd(int value){
	SetAttribute(atr_MaxSetOrd,WString::valueOf(value));
};
/**
* Get integer attribute MaxSetOrd
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoLayout::GetMaxSetOrd() const {
	return GetIntAttribute(atr_MaxSetOrd,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayout::ValidMaxSetOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxSetOrd,AttributeType_integer,false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLayout::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoLayout::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayout::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_string,false);
	};
/**
* Set attribute MaxOrd
*@param int value: the value to set the attribute to
*/
	 void JDFAutoLayout::SetMaxOrd(int value){
	SetAttribute(atr_MaxOrd,WString::valueOf(value));
};
/**
* Get integer attribute MaxOrd
* @return int the vaue of the attribute 
*/
	 int JDFAutoLayout::GetMaxOrd() const {
	return GetIntAttribute(atr_MaxOrd,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayout::ValidMaxOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxOrd,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayout::SourceWorkStyleString(){
		static const WString enums=WString(L"Unknown,Simplex,WorkAndBack,Perfecting,WorkAndTurn,WorkAndTumble,WorkAndTwist");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayout::SourceWorkStyleString(EnumSourceWorkStyle value){
		return SourceWorkStyleString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayout::SetSourceWorkStyle( EnumSourceWorkStyle value){
	SetEnumAttribute(atr_SourceWorkStyle,value,SourceWorkStyleString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayout::EnumSourceWorkStyle JDFAutoLayout:: GetSourceWorkStyle() const {
	return (EnumSourceWorkStyle) GetEnumAttribute(atr_SourceWorkStyle,SourceWorkStyleString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayout::ValidSourceWorkStyle(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SourceWorkStyle,SourceWorkStyleString(),false);
	};
/**
* Set attribute SurfaceContentsBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoLayout::SetSurfaceContentsBox(const JDFRectangle& value){
	SetAttribute(atr_SurfaceContentsBox,value);
};
/**
* Get string attribute SurfaceContentsBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoLayout::GetSurfaceContentsBox() const {
	return GetAttribute(atr_SurfaceContentsBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayout::ValidSurfaceContentsBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SurfaceContentsBox,AttributeType_rectangle,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFContentObject JDFAutoLayout::GetContentObject(int iSkip)const{
	JDFContentObject e=GetElement(elm_ContentObject,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContentObject JDFAutoLayout::GetCreateContentObject(int iSkip){
	JDFContentObject e=GetCreateElement(elm_ContentObject,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContentObject JDFAutoLayout::AppendContentObject(){
	JDFContentObject e=AppendElement(elm_ContentObject);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoLayout::GetInsertSheet(int iSkip)const{
	JDFInsertSheet e=GetElement(elm_InsertSheet,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoLayout::GetCreateInsertSheet(int iSkip){
	JDFInsertSheet e=GetCreateElement(elm_InsertSheet,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoLayout::AppendInsertSheet(){
	JDFInsertSheet e=AppendElement(elm_InsertSheet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayout::RefInsertSheet(JDFInsertSheet& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFLayerList JDFAutoLayout::GetLayerList()const{
	JDFLayerList e=GetElement(elm_LayerList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayerList JDFAutoLayout::GetCreateLayerList(){
	JDFLayerList e=GetCreateElement(elm_LayerList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayerList JDFAutoLayout::AppendLayerList(){
	JDFLayerList e=AppendElementN(elm_LayerList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMarkObject JDFAutoLayout::GetMarkObject(int iSkip)const{
	JDFMarkObject e=GetElement(elm_MarkObject,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMarkObject JDFAutoLayout::GetCreateMarkObject(int iSkip){
	JDFMarkObject e=GetCreateElement(elm_MarkObject,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMarkObject JDFAutoLayout::AppendMarkObject(){
	JDFMarkObject e=AppendElement(elm_MarkObject);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoLayout::GetMedia()const{
	JDFMedia e=GetElement(elm_Media);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoLayout::GetCreateMedia(){
	JDFMedia e=GetCreateElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoLayout::AppendMedia(){
	JDFMedia e=AppendElementN(elm_Media,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayout::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoLayout::GetMediaSource()const{
	JDFMediaSource e=GetElement(elm_MediaSource);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoLayout::GetCreateMediaSource(){
	JDFMediaSource e=GetCreateElement(elm_MediaSource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoLayout::AppendMediaSource(){
	JDFMediaSource e=AppendElementN(elm_MediaSource,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayout::RefMediaSource(JDFMediaSource& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSignature JDFAutoLayout::GetSignature(int iSkip)const{
	JDFSignature e=GetElement(elm_Signature,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSignature JDFAutoLayout::GetCreateSignature(int iSkip){
	JDFSignature e=GetCreateElement(elm_Signature,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSignature JDFAutoLayout::AppendSignature(){
	JDFSignature e=AppendElement(elm_Signature);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurvePool JDFAutoLayout::GetTransferCurvePool()const{
	JDFTransferCurvePool e=GetElement(elm_TransferCurvePool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurvePool JDFAutoLayout::GetCreateTransferCurvePool(){
	JDFTransferCurvePool e=GetCreateElement(elm_TransferCurvePool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTransferCurvePool JDFAutoLayout::AppendTransferCurvePool(){
	JDFTransferCurvePool e=AppendElementN(elm_TransferCurvePool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayout::RefTransferCurvePool(JDFTransferCurvePool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLayout::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ContentObject);

		for(i=0;i<nElem;i++){
			if (!GetContentObject(i).IsValid(level)) {
				vElem.AppendUnique(elm_ContentObject);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_InsertSheet);

		for(i=0;i<nElem;i++){
			if (!GetInsertSheet(i).IsValid(level)) {
				vElem.AppendUnique(elm_InsertSheet);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_LayerList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_LayerList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetLayerList().IsValid(level)) {
				vElem.AppendUnique(elm_LayerList);
				if (++n>=nMax)
					return vElem;
			}
		}
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
		nElem=NumChildElements(elm_Signature);

		for(i=0;i<nElem;i++){
			if (!GetSignature(i).IsValid(level)) {
				vElem.AppendUnique(elm_Signature);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TransferCurvePool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TransferCurvePool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTransferCurvePool().IsValid(level)) {
				vElem.AppendUnique(elm_TransferCurvePool);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoLayout::UniqueElements()const{
		return JDFResource::UniqueElements()+L",LayerList,Media,MediaSource,TransferCurvePool";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoLayout::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ContentObject,InsertSheet,LayerList,MarkObject,Media,MediaSource,Signature,TransferCurvePool";
	};
}; // end namespace JDF
