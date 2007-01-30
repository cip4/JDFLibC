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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIdentificationField.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIdentificationField : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIdentificationField& JDFAutoIdentificationField::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIdentificationField: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIdentificationField::ValidNodeNames()const{
	return L"*:,IdentificationField";
};

bool JDFAutoIdentificationField::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoIdentificationField::init(){
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
	WString JDFAutoIdentificationField::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Encoding,EncodingDetails";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIdentificationField::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BoundingBox,Format,Orientation,Page,Position,Purpose,PurposeDetails,Value,ValueFormat,ValueTemplate");
};

/**
 typesafe validator
*/
	vWString JDFAutoIdentificationField::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidEncoding(level)) {
			vAtts.push_back(atr_Encoding);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEncodingDetails(level)) {
			vAtts.push_back(atr_EncodingDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBoundingBox(level)) {
			vAtts.push_back(atr_BoundingBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFormat(level)) {
			vAtts.push_back(atr_Format);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrientation(level)) {
			vAtts.push_back(atr_Orientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPage(level)) {
			vAtts.push_back(atr_Page);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPosition(level)) {
			vAtts.push_back(atr_Position);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPurpose(level)) {
			vAtts.push_back(atr_Purpose);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPurposeDetails(level)) {
			vAtts.push_back(atr_PurposeDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValue(level)) {
			vAtts.push_back(atr_Value);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValueFormat(level)) {
			vAtts.push_back(atr_ValueFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValueTemplate(level)) {
			vAtts.push_back(atr_ValueTemplate);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIdentificationField::EncodingString(){
		static const WString enums=WString(L"Unknown,ASCII,Barcode,BarCode1D,BarCode2D,RFID");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIdentificationField::EncodingString(EnumEncoding value){
		return EncodingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIdentificationField::SetEncoding( EnumEncoding value){
	SetEnumAttribute(atr_Encoding,value,EncodingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIdentificationField::EnumEncoding JDFAutoIdentificationField:: GetEncoding() const {
	return (EnumEncoding) GetEnumAttribute(atr_Encoding,EncodingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidEncoding(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Encoding,EncodingString(),RequiredLevel(level));
	};
/**
* Set attribute EncodingDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetEncodingDetails(const WString& value){
	SetAttribute(atr_EncodingDetails,value);
};
/**
* Get string attribute EncodingDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIdentificationField::GetEncodingDetails() const {
	return GetAttribute(atr_EncodingDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidEncodingDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_EncodingDetails,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute BoundingBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetBoundingBox(const JDFRectangle& value){
	SetAttribute(atr_BoundingBox,value);
};
/**
* Get string attribute BoundingBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoIdentificationField::GetBoundingBox() const {
	return GetAttribute(atr_BoundingBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidBoundingBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_BoundingBox,AttributeType_rectangle,false);
	};
/**
* Set attribute Format
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetFormat(const WString& value){
	SetAttribute(atr_Format,value);
};
/**
* Get string attribute Format
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIdentificationField::GetFormat() const {
	return GetAttribute(atr_Format,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_Format,AttributeType_regExp,false);
	};
/**
* Set attribute Orientation
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetOrientation(const JDFMatrix& value){
	SetAttribute(atr_Orientation,value);
};
/**
* Get string attribute Orientation
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoIdentificationField::GetOrientation() const {
	return GetAttribute(atr_Orientation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidOrientation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Orientation,AttributeType_matrix,false);
	};
/**
* Set attribute Page
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetPage(int value){
	SetAttribute(atr_Page,WString::valueOf(value));
};
/**
* Get integer attribute Page
* @return int the vaue of the attribute 
*/
	 int JDFAutoIdentificationField::GetPage() const {
	return GetIntAttribute(atr_Page,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_Page,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIdentificationField::PositionString(){
		static const WString enums=WString(L"Unknown,Header,Trailer,Page,Top,Bottom,Left,Right,Front,Back")
	+WString(L",Any");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIdentificationField::PositionString(EnumPosition value){
		return PositionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIdentificationField::SetPosition( EnumPosition value){
	SetEnumAttribute(atr_Position,value,PositionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIdentificationField::EnumPosition JDFAutoIdentificationField:: GetPosition() const {
	return (EnumPosition) GetEnumAttribute(atr_Position,PositionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidPosition(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Position,PositionString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIdentificationField::PurposeString(){
		static const WString enums=WString(L"Unknown,Verification,Separation,Label");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIdentificationField::PurposeString(EnumPurpose value){
		return PurposeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIdentificationField::SetPurpose( EnumPurpose value){
	SetEnumAttribute(atr_Purpose,value,PurposeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIdentificationField::EnumPurpose JDFAutoIdentificationField:: GetPurpose() const {
	return (EnumPurpose) GetEnumAttribute(atr_Purpose,PurposeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidPurpose(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Purpose,PurposeString(),false);
	};
/**
* Set attribute PurposeDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetPurposeDetails(const WString& value){
	SetAttribute(atr_PurposeDetails,value);
};
/**
* Get string attribute PurposeDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIdentificationField::GetPurposeDetails() const {
	return GetAttribute(atr_PurposeDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidPurposeDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_PurposeDetails,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Value
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetValue(const WString& value){
	SetAttribute(atr_Value,value);
};
/**
* Get string attribute Value
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIdentificationField::GetValue() const {
	return GetAttribute(atr_Value,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_Value,AttributeType_string,false);
	};
/**
* Set attribute ValueFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetValueFormat(const WString& value){
	SetAttribute(atr_ValueFormat,value);
};
/**
* Get string attribute ValueFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIdentificationField::GetValueFormat() const {
	return GetAttribute(atr_ValueFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidValueFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_ValueFormat,AttributeType_string,false);
	};
/**
* Set attribute ValueTemplate
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIdentificationField::SetValueTemplate(const WString& value){
	SetAttribute(atr_ValueTemplate,value);
};
/**
* Get string attribute ValueTemplate
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIdentificationField::GetValueTemplate() const {
	return GetAttribute(atr_ValueTemplate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIdentificationField::ValidValueTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_ValueTemplate,AttributeType_string,false);
	};
}; // end namespace JDF
