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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDeviceMark.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDeviceMark : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDeviceMark& JDFAutoDeviceMark::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDeviceMark: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDeviceMark::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDeviceMark::ValidNodeNames()const{
	return L"*:,DeviceMark";
};

bool JDFAutoDeviceMark::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoDeviceMark::init(){
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
	WString JDFAutoDeviceMark::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Font,FontSize,MarkJustification,MarkOffset,MarkOrientation,MarkPosition");
};

/**
 typesafe validator
*/
	vWString JDFAutoDeviceMark::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFont(level)) {
			vAtts.push_back(atr_Font);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFontSize(level)) {
			vAtts.push_back(atr_FontSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkJustification(level)) {
			vAtts.push_back(atr_MarkJustification);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkOffset(level)) {
			vAtts.push_back(atr_MarkOffset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkOrientation(level)) {
			vAtts.push_back(atr_MarkOrientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkPosition(level)) {
			vAtts.push_back(atr_MarkPosition);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Font
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDeviceMark::SetFont(const WString& value){
	SetAttribute(atr_Font,value);
};
/**
* Get string attribute Font
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDeviceMark::GetFont() const {
	return GetAttribute(atr_Font,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceMark::ValidFont(EnumValidationLevel level) const {
		return ValidAttribute(atr_Font,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute FontSize
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDeviceMark::SetFontSize(int value){
	SetAttribute(atr_FontSize,WString::valueOf(value));
};
/**
* Get integer attribute FontSize
* @return int the vaue of the attribute 
*/
	 int JDFAutoDeviceMark::GetFontSize() const {
	return GetIntAttribute(atr_FontSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceMark::ValidFontSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_FontSize,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeviceMark::MarkJustificationString(){
		static const WString enums=WString(L"Unknown,Left,Right,Center");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeviceMark::MarkJustificationString(EnumMarkJustification value){
		return MarkJustificationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceMark::SetMarkJustification( EnumMarkJustification value){
	SetEnumAttribute(atr_MarkJustification,value,MarkJustificationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeviceMark::EnumMarkJustification JDFAutoDeviceMark:: GetMarkJustification() const {
	return (EnumMarkJustification) GetEnumAttribute(atr_MarkJustification,MarkJustificationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceMark::ValidMarkJustification(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MarkJustification,MarkJustificationString(),false);
	};
/**
* Set attribute MarkOffset
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoDeviceMark::SetMarkOffset(const JDFXYPair& value){
	SetAttribute(atr_MarkOffset,value);
};
/**
* Get string attribute MarkOffset
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoDeviceMark::GetMarkOffset() const {
	return GetAttribute(atr_MarkOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceMark::ValidMarkOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarkOffset,AttributeType_XYPair,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceMark::SetMarkOrientation( EnumOrientation value){
	SetEnumAttribute(atr_MarkOrientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeviceMark::EnumOrientation JDFAutoDeviceMark:: GetMarkOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_MarkOrientation,OrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceMark::ValidMarkOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MarkOrientation,OrientationString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDeviceMark::MarkPositionString(){
		static const WString enums=WString(L"Unknown,Top,Bottom,Left,Right");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDeviceMark::MarkPositionString(EnumMarkPosition value){
		return MarkPositionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDeviceMark::SetMarkPosition( EnumMarkPosition value){
	SetEnumAttribute(atr_MarkPosition,value,MarkPositionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDeviceMark::EnumMarkPosition JDFAutoDeviceMark:: GetMarkPosition() const {
	return (EnumMarkPosition) GetEnumAttribute(atr_MarkPosition,MarkPositionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDeviceMark::ValidMarkPosition(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MarkPosition,MarkPositionString(),false);
	};
}; // end namespace JDF
