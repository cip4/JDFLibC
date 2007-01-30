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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLayoutElement.h"
#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFDependencies.h"
#include "jdf/wrapper/JDFElementColorParams.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFImageCompressionParams.h"
#include "jdf/wrapper/JDFPageList.h"
#include "jdf/wrapper/JDFScreeningParams.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLayoutElement : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLayoutElement& JDFAutoLayoutElement::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLayoutElement: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLayoutElement::ValidNodeNames()const{
	return L"*:,LayoutElement";
};

bool JDFAutoLayoutElement::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoLayoutElement::init(){
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
	WString JDFAutoLayoutElement::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",IgnorePDLCopies,IgnorePDLImposition,ClipPath,ElementType,HasBleeds,IsBlank,IsPrintable,IsTrapped,PageListIndex,SourceBleedBox,SourceClipBox,SourceTrimBox,Template");
};

/**
 typesafe validator
*/
	vWString JDFAutoLayoutElement::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidIgnorePDLCopies(level)) {
			vAtts.push_back(atr_IgnorePDLCopies);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIgnorePDLImposition(level)) {
			vAtts.push_back(atr_IgnorePDLImposition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipPath(level)) {
			vAtts.push_back(atr_ClipPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidElementType(level)) {
			vAtts.push_back(atr_ElementType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHasBleeds(level)) {
			vAtts.push_back(atr_HasBleeds);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsBlank(level)) {
			vAtts.push_back(atr_IsBlank);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsPrintable(level)) {
			vAtts.push_back(atr_IsPrintable);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIsTrapped(level)) {
			vAtts.push_back(atr_IsTrapped);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageListIndex(level)) {
			vAtts.push_back(atr_PageListIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceBleedBox(level)) {
			vAtts.push_back(atr_SourceBleedBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceClipBox(level)) {
			vAtts.push_back(atr_SourceClipBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceTrimBox(level)) {
			vAtts.push_back(atr_SourceTrimBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTemplate(level)) {
			vAtts.push_back(atr_Template);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute IgnorePDLCopies
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetIgnorePDLCopies(bool value){
	SetAttribute(atr_IgnorePDLCopies,WString::valueOf(value));
};
/**
* Get bool attribute IgnorePDLCopies
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoLayoutElement::GetIgnorePDLCopies() const {return GetBoolAttribute(atr_IgnorePDLCopies,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidIgnorePDLCopies(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnorePDLCopies,AttributeType_boolean,false);
	};
/**
* Set attribute IgnorePDLImposition
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetIgnorePDLImposition(bool value){
	SetAttribute(atr_IgnorePDLImposition,WString::valueOf(value));
};
/**
* Get bool attribute IgnorePDLImposition
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoLayoutElement::GetIgnorePDLImposition() const {return GetBoolAttribute(atr_IgnorePDLImposition,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidIgnorePDLImposition(EnumValidationLevel level) const {
		return ValidAttribute(atr_IgnorePDLImposition,AttributeType_boolean,false);
	};
/**
* Set attribute ClipPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetClipPath(const WString& value){
	SetAttribute(atr_ClipPath,value);
};
/**
* Get string attribute ClipPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoLayoutElement::GetClipPath() const {
	return GetAttribute(atr_ClipPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidClipPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipPath,AttributeType_PDFPath,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutElement::ElementTypeString(){
		static const WString enums=WString(L"Unknown,Auxilliary,Barcode,Composed,Document,Graphic,IdentificationField,Image,MultiDocument,MultiSet")
	+WString(L",Page,Reservation,Surface,Text,Tile");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutElement::ElementTypeString(EnumElementType value){
		return ElementTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutElement::SetElementType( EnumElementType value){
	SetEnumAttribute(atr_ElementType,value,ElementTypeString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutElement::EnumElementType JDFAutoLayoutElement:: GetElementType() const {
	return (EnumElementType) GetEnumAttribute(atr_ElementType,ElementTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidElementType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ElementType,ElementTypeString(),false,WString::emptyStr,true);
	};
/**
* Set attribute HasBleeds
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetHasBleeds(bool value){
	SetAttribute(atr_HasBleeds,WString::valueOf(value));
};
/**
* Get bool attribute HasBleeds
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoLayoutElement::GetHasBleeds() const {return GetBoolAttribute(atr_HasBleeds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidHasBleeds(EnumValidationLevel level) const {
		return ValidAttribute(atr_HasBleeds,AttributeType_boolean,false);
	};
/**
* Set attribute IsBlank
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetIsBlank(bool value){
	SetAttribute(atr_IsBlank,WString::valueOf(value));
};
/**
* Get bool attribute IsBlank
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoLayoutElement::GetIsBlank() const {return GetBoolAttribute(atr_IsBlank,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidIsBlank(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsBlank,AttributeType_boolean,false);
	};
/**
* Set attribute IsPrintable
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetIsPrintable(bool value){
	SetAttribute(atr_IsPrintable,WString::valueOf(value));
};
/**
* Get bool attribute IsPrintable
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoLayoutElement::GetIsPrintable() const {return GetBoolAttribute(atr_IsPrintable,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidIsPrintable(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsPrintable,AttributeType_boolean,false);
	};
/**
* Set attribute IsTrapped
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetIsTrapped(bool value){
	SetAttribute(atr_IsTrapped,WString::valueOf(value));
};
/**
* Get bool attribute IsTrapped
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoLayoutElement::GetIsTrapped() const {return GetBoolAttribute(atr_IsTrapped,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidIsTrapped(EnumValidationLevel level) const {
		return ValidAttribute(atr_IsTrapped,AttributeType_boolean,false);
	};
/**
* Set attribute PageListIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetPageListIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageListIndex,value.GetString());
};
/**
* Get range attribute PageListIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoLayoutElement::GetPageListIndex() const {
	return GetAttribute(atr_PageListIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidPageListIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageListIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute SourceBleedBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetSourceBleedBox(const JDFRectangle& value){
	SetAttribute(atr_SourceBleedBox,value);
};
/**
* Get string attribute SourceBleedBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoLayoutElement::GetSourceBleedBox() const {
	return GetAttribute(atr_SourceBleedBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidSourceBleedBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceBleedBox,AttributeType_rectangle,false);
	};
/**
* Set attribute SourceClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetSourceClipBox(const JDFRectangle& value){
	SetAttribute(atr_SourceClipBox,value);
};
/**
* Get string attribute SourceClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoLayoutElement::GetSourceClipBox() const {
	return GetAttribute(atr_SourceClipBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidSourceClipBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceClipBox,AttributeType_rectangle,false);
	};
/**
* Set attribute SourceTrimBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetSourceTrimBox(const JDFRectangle& value){
	SetAttribute(atr_SourceTrimBox,value);
};
/**
* Get string attribute SourceTrimBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoLayoutElement::GetSourceTrimBox() const {
	return GetAttribute(atr_SourceTrimBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidSourceTrimBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceTrimBox,AttributeType_rectangle,false);
	};
/**
* Set attribute Template
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoLayoutElement::SetTemplate(bool value){
	SetAttribute(atr_Template,WString::valueOf(value));
};
/**
* Get bool attribute Template
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoLayoutElement::GetTemplate() const {return GetBoolAttribute(atr_Template,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElement::ValidTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_Template,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColorPool JDFAutoLayoutElement::GetColorPool()const{
	JDFColorPool e=GetElement(elm_ColorPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoLayoutElement::GetCreateColorPool(){
	JDFColorPool e=GetCreateElement(elm_ColorPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoLayoutElement::AppendColorPool(){
	JDFColorPool e=AppendElementN(elm_ColorPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElement::RefColorPool(JDFColorPool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDependencies JDFAutoLayoutElement::GetDependencies()const{
	JDFDependencies e=GetElement(elm_Dependencies);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDependencies JDFAutoLayoutElement::GetCreateDependencies(){
	JDFDependencies e=GetCreateElement(elm_Dependencies);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDependencies JDFAutoLayoutElement::AppendDependencies(){
	JDFDependencies e=AppendElementN(elm_Dependencies,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoLayoutElement::GetElementColorParams()const{
	JDFElementColorParams e=GetElement(elm_ElementColorParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoLayoutElement::GetCreateElementColorParams(){
	JDFElementColorParams e=GetCreateElement(elm_ElementColorParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFElementColorParams JDFAutoLayoutElement::AppendElementColorParams(){
	JDFElementColorParams e=AppendElementN(elm_ElementColorParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElement::RefElementColorParams(JDFElementColorParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoLayoutElement::GetFileSpec()const{
	JDFFileSpec e=GetElement(elm_FileSpec);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoLayoutElement::GetCreateFileSpec(){
	JDFFileSpec e=GetCreateElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoLayoutElement::AppendFileSpec(){
	JDFFileSpec e=AppendElementN(elm_FileSpec,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElement::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoLayoutElement::GetImageCompressionParams()const{
	JDFImageCompressionParams e=GetElement(elm_ImageCompressionParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoLayoutElement::GetCreateImageCompressionParams(){
	JDFImageCompressionParams e=GetCreateElement(elm_ImageCompressionParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageCompressionParams JDFAutoLayoutElement::AppendImageCompressionParams(){
	JDFImageCompressionParams e=AppendElementN(elm_ImageCompressionParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElement::RefImageCompressionParams(JDFImageCompressionParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoLayoutElement::GetPageList()const{
	JDFPageList e=GetElement(elm_PageList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoLayoutElement::GetCreatePageList(){
	JDFPageList e=GetCreateElement(elm_PageList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoLayoutElement::AppendPageList(){
	JDFPageList e=AppendElementN(elm_PageList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElement::RefPageList(JDFPageList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoLayoutElement::GetScreeningParams()const{
	JDFScreeningParams e=GetElement(elm_ScreeningParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoLayoutElement::GetCreateScreeningParams(){
	JDFScreeningParams e=GetCreateElement(elm_ScreeningParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFScreeningParams JDFAutoLayoutElement::AppendScreeningParams(){
	JDFScreeningParams e=AppendElementN(elm_ScreeningParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElement::RefScreeningParams(JDFScreeningParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoLayoutElement::GetSeparationSpec(int iSkip)const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoLayoutElement::GetCreateSeparationSpec(int iSkip){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoLayoutElement::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElement::RefSeparationSpec(JDFSeparationSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLayoutElement::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorPool().IsValid(level)) {
				vElem.AppendUnique(elm_ColorPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Dependencies);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Dependencies);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDependencies().IsValid(level)) {
				vElem.AppendUnique(elm_Dependencies);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ElementColorParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ElementColorParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetElementColorParams().IsValid(level)) {
				vElem.AppendUnique(elm_ElementColorParams);
				if (++n>=nMax)
					return vElem;
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
		nElem=NumChildElements(elm_ImageCompressionParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ImageCompressionParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetImageCompressionParams().IsValid(level)) {
				vElem.AppendUnique(elm_ImageCompressionParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PageList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PageList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPageList().IsValid(level)) {
				vElem.AppendUnique(elm_PageList);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ScreeningParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ScreeningParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetScreeningParams().IsValid(level)) {
				vElem.AppendUnique(elm_ScreeningParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_SeparationSpec);

		for(i=0;i<nElem;i++){
			if (!GetSeparationSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_SeparationSpec);
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
	WString JDFAutoLayoutElement::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorPool,Dependencies,ElementColorParams,FileSpec,ImageCompressionParams,PageList,ScreeningParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoLayoutElement::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorPool,Dependencies,ElementColorParams,FileSpec,ImageCompressionParams,PageList,ScreeningParams,SeparationSpec";
	};
}; // end namespace JDF
