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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTIFFFormatParams.h"
#include "jdf/wrapper/JDFTIFFtag.h"
#include "jdf/wrapper/JDFTIFFEmbeddedFile.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTIFFFormatParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTIFFFormatParams& JDFAutoTIFFFormatParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTIFFFormatParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTIFFFormatParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTIFFFormatParams::ValidNodeNames()const{
	return L"*:,TIFFFormatParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoTIFFFormatParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ByteOrder,Interleaving,WhiteIsZero,Segmentation,RowsPerStrip,TileSize,SeparationNameTag");
};

/**
 typesafe validator
*/
	vWString JDFAutoTIFFFormatParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidByteOrder(level)) {
			vAtts.push_back(atr_ByteOrder);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInterleaving(level)) {
			vAtts.push_back(atr_Interleaving);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWhiteIsZero(level)) {
			vAtts.push_back(atr_WhiteIsZero);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSegmentation(level)) {
			vAtts.push_back(atr_Segmentation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRowsPerStrip(level)) {
			vAtts.push_back(atr_RowsPerStrip);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTileSize(level)) {
			vAtts.push_back(atr_TileSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSeparationNameTag(level)) {
			vAtts.push_back(atr_SeparationNameTag);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoTIFFFormatParams::ByteOrderString(){
		static const WString enums=WString(L"Unknown,II,MM");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoTIFFFormatParams::ByteOrderString(EnumByteOrder value){
		return ByteOrderString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoTIFFFormatParams::SetByteOrder( EnumByteOrder value){
	SetEnumAttribute(atr_ByteOrder,value,ByteOrderString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoTIFFFormatParams::EnumByteOrder JDFAutoTIFFFormatParams:: GetByteOrder() const {
	return (EnumByteOrder) GetEnumAttribute(atr_ByteOrder,ByteOrderString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFFormatParams::ValidByteOrder(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ByteOrder,ByteOrderString(),false);
	};
/**
* Set attribute Interleaving
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTIFFFormatParams::SetInterleaving(int value){
	SetAttribute(atr_Interleaving,WString::valueOf(value));
};
/**
* Get integer attribute Interleaving
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoTIFFFormatParams::GetInterleaving() const {
	return GetIntAttribute(atr_Interleaving,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFFormatParams::ValidInterleaving(EnumValidationLevel level) const {
		return ValidAttribute(atr_Interleaving,AttributeType_integer,false);
	};
/**
* Set attribute WhiteIsZero
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoTIFFFormatParams::SetWhiteIsZero(bool value){
	SetAttribute(atr_WhiteIsZero,WString::valueOf(value));
};
/**
* Get bool attribute WhiteIsZero
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoTIFFFormatParams::GetWhiteIsZero() const {return GetBoolAttribute(atr_WhiteIsZero,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFFormatParams::ValidWhiteIsZero(EnumValidationLevel level) const {
		return ValidAttribute(atr_WhiteIsZero,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoTIFFFormatParams::SegmentationString(){
		static const WString enums=WString(L"Unknown,SingleStrip,Stripped,Tiled");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoTIFFFormatParams::SegmentationString(EnumSegmentation value){
		return SegmentationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoTIFFFormatParams::SetSegmentation( EnumSegmentation value){
	SetEnumAttribute(atr_Segmentation,value,SegmentationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoTIFFFormatParams::EnumSegmentation JDFAutoTIFFFormatParams:: GetSegmentation() const {
	return (EnumSegmentation) GetEnumAttribute(atr_Segmentation,SegmentationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFFormatParams::ValidSegmentation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Segmentation,SegmentationString(),false);
	};
/**
* Set attribute RowsPerStrip
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTIFFFormatParams::SetRowsPerStrip(int value){
	SetAttribute(atr_RowsPerStrip,WString::valueOf(value));
};
/**
* Get integer attribute RowsPerStrip
* @return int the vaue of the attribute 
*/
	 int JDFAutoTIFFFormatParams::GetRowsPerStrip() const {
	return GetIntAttribute(atr_RowsPerStrip,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFFormatParams::ValidRowsPerStrip(EnumValidationLevel level) const {
		return ValidAttribute(atr_RowsPerStrip,AttributeType_integer,false);
	};
/**
* Set attribute TileSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoTIFFFormatParams::SetTileSize(const JDFXYPair& value){
	SetAttribute(atr_TileSize,value);
};
/**
* Get string attribute TileSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoTIFFFormatParams::GetTileSize() const {
	return GetAttribute(atr_TileSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFFormatParams::ValidTileSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_TileSize,AttributeType_XYPair,false);
	};
/**
* Set attribute SeparationNameTag
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTIFFFormatParams::SetSeparationNameTag(int value){
	SetAttribute(atr_SeparationNameTag,WString::valueOf(value));
};
/**
* Get integer attribute SeparationNameTag
* @return int the vaue of the attribute ; defaults to 270
*/
	 int JDFAutoTIFFFormatParams::GetSeparationNameTag() const {
	return GetIntAttribute(atr_SeparationNameTag,WString::emptyStr,270);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFFormatParams::ValidSeparationNameTag(EnumValidationLevel level) const {
		return ValidAttribute(atr_SeparationNameTag,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTIFFtag JDFAutoTIFFFormatParams::GetTIFFtag(int iSkip)const{
	JDFTIFFtag e=GetElement(elm_TIFFtag,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTIFFtag JDFAutoTIFFFormatParams::GetCreateTIFFtag(int iSkip){
	JDFTIFFtag e=GetCreateElement(elm_TIFFtag,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTIFFtag JDFAutoTIFFFormatParams::AppendTIFFtag(){
	JDFTIFFtag e=AppendElement(elm_TIFFtag);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTIFFEmbeddedFile JDFAutoTIFFFormatParams::GetTIFFEmbeddedFile(int iSkip)const{
	JDFTIFFEmbeddedFile e=GetElement(elm_TIFFEmbeddedFile,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTIFFEmbeddedFile JDFAutoTIFFFormatParams::GetCreateTIFFEmbeddedFile(int iSkip){
	JDFTIFFEmbeddedFile e=GetCreateElement(elm_TIFFEmbeddedFile,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTIFFEmbeddedFile JDFAutoTIFFFormatParams::AppendTIFFEmbeddedFile(){
	JDFTIFFEmbeddedFile e=AppendElement(elm_TIFFEmbeddedFile);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoTIFFFormatParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_TIFFtag);

		for(i=0;i<nElem;i++){
			if (!GetTIFFtag(i).IsValid(level)) {
				vElem.AppendUnique(elm_TIFFtag);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TIFFEmbeddedFile);

		for(i=0;i<nElem;i++){
			if (!GetTIFFEmbeddedFile(i).IsValid(level)) {
				vElem.AppendUnique(elm_TIFFEmbeddedFile);
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
	WString JDFAutoTIFFFormatParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",TIFFtag,TIFFEmbeddedFile";
	};
}; // end namespace JDF
