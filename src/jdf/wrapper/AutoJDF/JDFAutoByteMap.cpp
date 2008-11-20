/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoByteMap.h"
#include "jdf/wrapper/JDFBand.h"
#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFPixelColorant.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoByteMap : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoByteMap& JDFAutoByteMap::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoByteMap: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoByteMap::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoByteMap::ValidNodeNames()const{
	return L"*:,ByteMap";
};

bool JDFAutoByteMap::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoByteMap::init(){
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
	WString JDFAutoByteMap::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BandOrdering,ElementType,FrameHeight,FrameWidth,Halftoned,Interleaved,PixelSkip,Resolution");
};

/**
 typesafe validator
*/
	vWString JDFAutoByteMap::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBandOrdering(level)) {
			vAtts.push_back(atr_BandOrdering);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidElementType(level)) {
			vAtts.push_back(atr_ElementType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrameHeight(level)) {
			vAtts.push_back(atr_FrameHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrameWidth(level)) {
			vAtts.push_back(atr_FrameWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHalftoned(level)) {
			vAtts.push_back(atr_Halftoned);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInterleaved(level)) {
			vAtts.push_back(atr_Interleaved);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPixelSkip(level)) {
			vAtts.push_back(atr_PixelSkip);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResolution(level)) {
			vAtts.push_back(atr_Resolution);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoByteMap::BandOrderingString(){
		static const WString enums=WString(L"Unknown,BandMajor,ColorMajor");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoByteMap::BandOrderingString(EnumBandOrdering value){
		return BandOrderingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoByteMap::SetBandOrdering( EnumBandOrdering value){
	SetEnumAttribute(atr_BandOrdering,value,BandOrderingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoByteMap::EnumBandOrdering JDFAutoByteMap:: GetBandOrdering() const {
	return (EnumBandOrdering) GetEnumAttribute(atr_BandOrdering,BandOrderingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoByteMap::ValidBandOrdering(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BandOrdering,BandOrderingString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoByteMap::ElementTypeString(){
		static const WString enums=WString(L"Unknown,Auxiliary,Barcode,Composed,Document,Graphic,IdentificationField,Image,MultiDocument,MultiSet")
	+WString(L",Page,Reservation,Surface,Text,Tile");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoByteMap::ElementTypeString(EnumElementType value){
		return ElementTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoByteMap::SetElementType( EnumElementType value){
	SetEnumAttribute(atr_ElementType,value,ElementTypeString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoByteMap::EnumElementType JDFAutoByteMap:: GetElementType() const {
	return (EnumElementType) GetEnumAttribute(atr_ElementType,ElementTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoByteMap::ValidElementType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ElementType,ElementTypeString(),false,WString::emptyStr,true);
	};
/**
* Set attribute FrameHeight
*@param int value: the value to set the attribute to
*/
	 void JDFAutoByteMap::SetFrameHeight(int value){
	SetAttribute(atr_FrameHeight,WString::valueOf(value));
};
/**
* Get integer attribute FrameHeight
* @return int the vaue of the attribute 
*/
	 int JDFAutoByteMap::GetFrameHeight() const {
	return GetIntAttribute(atr_FrameHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoByteMap::ValidFrameHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrameHeight,AttributeType_integer,false);
	};
/**
* Set attribute FrameWidth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoByteMap::SetFrameWidth(int value){
	SetAttribute(atr_FrameWidth,WString::valueOf(value));
};
/**
* Get integer attribute FrameWidth
* @return int the vaue of the attribute 
*/
	 int JDFAutoByteMap::GetFrameWidth() const {
	return GetIntAttribute(atr_FrameWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoByteMap::ValidFrameWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrameWidth,AttributeType_integer,false);
	};
/**
* Set attribute Halftoned
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoByteMap::SetHalftoned(bool value){
	SetAttribute(atr_Halftoned,WString::valueOf(value));
};
/**
* Get bool attribute Halftoned
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoByteMap::GetHalftoned() const {return GetBoolAttribute(atr_Halftoned,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoByteMap::ValidHalftoned(EnumValidationLevel level) const {
		return ValidAttribute(atr_Halftoned,AttributeType_boolean,false);
	};
/**
* Set attribute Interleaved
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoByteMap::SetInterleaved(bool value){
	SetAttribute(atr_Interleaved,WString::valueOf(value));
};
/**
* Get bool attribute Interleaved
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoByteMap::GetInterleaved() const {return GetBoolAttribute(atr_Interleaved,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoByteMap::ValidInterleaved(EnumValidationLevel level) const {
		return ValidAttribute(atr_Interleaved,AttributeType_boolean,false);
	};
/**
* Set attribute PixelSkip
*@param int value: the value to set the attribute to
*/
	 void JDFAutoByteMap::SetPixelSkip(int value){
	SetAttribute(atr_PixelSkip,WString::valueOf(value));
};
/**
* Get integer attribute PixelSkip
* @return int the vaue of the attribute 
*/
	 int JDFAutoByteMap::GetPixelSkip() const {
	return GetIntAttribute(atr_PixelSkip,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoByteMap::ValidPixelSkip(EnumValidationLevel level) const {
		return ValidAttribute(atr_PixelSkip,AttributeType_integer,false);
	};
/**
* Set attribute Resolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoByteMap::SetResolution(const JDFXYPair& value){
	SetAttribute(atr_Resolution,value);
};
/**
* Get string attribute Resolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoByteMap::GetResolution() const {
	return GetAttribute(atr_Resolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoByteMap::ValidResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_Resolution,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBand JDFAutoByteMap::GetBand(int iSkip)const{
	JDFBand e=GetElement(elm_Band,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBand JDFAutoByteMap::GetCreateBand(int iSkip){
	JDFBand e=GetCreateElement(elm_Band,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBand JDFAutoByteMap::AppendBand(){
	JDFBand e=AppendElement(elm_Band);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoByteMap::GetColorPool()const{
	JDFColorPool e=GetElement(elm_ColorPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoByteMap::GetCreateColorPool(){
	JDFColorPool e=GetCreateElement(elm_ColorPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoByteMap::AppendColorPool(){
	JDFColorPool e=AppendElementN(elm_ColorPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoByteMap::RefColorPool(JDFColorPool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoByteMap::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoByteMap::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoByteMap::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoByteMap::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPixelColorant JDFAutoByteMap::GetPixelColorant(int iSkip)const{
	JDFPixelColorant e=GetElement(elm_PixelColorant,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPixelColorant JDFAutoByteMap::GetCreatePixelColorant(int iSkip){
	JDFPixelColorant e=GetCreateElement(elm_PixelColorant,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPixelColorant JDFAutoByteMap::AppendPixelColorant(){
	JDFPixelColorant e=AppendElement(elm_PixelColorant);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoByteMap::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Band);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_Band);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetBand(i).IsValid(level)) {
				vElem.AppendUnique(elm_Band);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
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
		nElem=NumChildElements(elm_FileSpec);

		for(i=0;i<nElem;i++){
			if (!GetFileSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PixelColorant);

		for(i=0;i<nElem;i++){
			if (!GetPixelColorant(i).IsValid(level)) {
				vElem.AppendUnique(elm_PixelColorant);
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
	WString JDFAutoByteMap::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorPool";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoByteMap::RequiredElements()const{
		return JDFResource::RequiredElements()+L",Band";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoByteMap::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorPool,FileSpec,PixelColorant";
	};
}; // end namespace JDF
