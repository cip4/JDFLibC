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

 
#include "jdf/wrapper/AutoJDF/JDFAutoContentObject.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoContentObject : public JDFPlacedObject

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoContentObject& JDFAutoContentObject::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoContentObject: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoContentObject::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoContentObject::ValidNodeNames()const{
	return L"*:,ContentObject";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoContentObject::RequiredAttributes()const{
		return JDFPlacedObject::RequiredAttributes()+L",CTM";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoContentObject::OptionalAttributes()const{
		return JDFPlacedObject::OptionalAttributes()+WString(L",DocOrd,Ord,OrdExpression,SetOrd,ClipBox,ClipPath,HalfTonePhaseOrigin,LayerID,OrdID,SourceClipPath,TrimCTM,TrimSize,Type");
};

/**
 typesafe validator
*/
	vWString JDFAutoContentObject::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFPlacedObject::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDocOrd(level)) {
			vAtts.push_back(atr_DocOrd);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrd(level)) {
			vAtts.push_back(atr_Ord);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrdExpression(level)) {
			vAtts.push_back(atr_OrdExpression);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSetOrd(level)) {
			vAtts.push_back(atr_SetOrd);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipBox(level)) {
			vAtts.push_back(atr_ClipBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipPath(level)) {
			vAtts.push_back(atr_ClipPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCTM(level)) {
			vAtts.push_back(atr_CTM);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHalfTonePhaseOrigin(level)) {
			vAtts.push_back(atr_HalfTonePhaseOrigin);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLayerID(level)) {
			vAtts.push_back(atr_LayerID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrdID(level)) {
			vAtts.push_back(atr_OrdID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceClipPath(level)) {
			vAtts.push_back(atr_SourceClipPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimCTM(level)) {
			vAtts.push_back(atr_TrimCTM);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimSize(level)) {
			vAtts.push_back(atr_TrimSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DocOrd
*@param int value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetDocOrd(int value){
	SetAttribute(atr_DocOrd,WString::valueOf(value));
};
/**
* Get integer attribute DocOrd
* @return int the vaue of the attribute 
*/
	 int JDFAutoContentObject::GetDocOrd() const {
	return GetIntAttribute(atr_DocOrd,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidDocOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_DocOrd,AttributeType_integer,false);
	};
/**
* Set attribute Ord
*@param int value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetOrd(int value){
	SetAttribute(atr_Ord,WString::valueOf(value));
};
/**
* Get integer attribute Ord
* @return int the vaue of the attribute 
*/
	 int JDFAutoContentObject::GetOrd() const {
	return GetIntAttribute(atr_Ord,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_Ord,AttributeType_integer,false);
	};
/**
* Set attribute OrdExpression
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetOrdExpression(const WString& value){
	SetAttribute(atr_OrdExpression,value);
};
/**
* Get string attribute OrdExpression
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentObject::GetOrdExpression() const {
	return GetAttribute(atr_OrdExpression,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidOrdExpression(EnumValidationLevel level) const {
		return ValidAttribute(atr_OrdExpression,AttributeType_string,false);
	};
/**
* Set attribute SetOrd
*@param int value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetSetOrd(int value){
	SetAttribute(atr_SetOrd,WString::valueOf(value));
};
/**
* Get integer attribute SetOrd
* @return int the vaue of the attribute 
*/
	 int JDFAutoContentObject::GetSetOrd() const {
	return GetIntAttribute(atr_SetOrd,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidSetOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_SetOrd,AttributeType_integer,false);
	};
/**
* Set attribute ClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetClipBox(const JDFRectangle& value){
	SetAttribute(atr_ClipBox,value);
};
/**
* Get string attribute ClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoContentObject::GetClipBox() const {
	return GetAttribute(atr_ClipBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidClipBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipBox,AttributeType_rectangle,false);
	};
/**
* Set attribute ClipPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetClipPath(const WString& value){
	SetAttribute(atr_ClipPath,value);
};
/**
* Get string attribute ClipPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentObject::GetClipPath() const {
	return GetAttribute(atr_ClipPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidClipPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipPath,AttributeType_PDFPath,false);
	};
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetCTM(const JDFMatrix& value){
	SetAttribute(atr_CTM,value);
};
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoContentObject::GetCTM() const {
	return GetAttribute(atr_CTM,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidCTM(EnumValidationLevel level) const {
		return ValidAttribute(atr_CTM,AttributeType_matrix,RequiredLevel(level));
	};
/**
* Set attribute HalfTonePhaseOrigin
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetHalfTonePhaseOrigin(const JDFXYPair& value){
	SetAttribute(atr_HalfTonePhaseOrigin,value);
};
/**
* Get string attribute HalfTonePhaseOrigin
* @return JDFXYPair the vaue of the attribute ; defaults to 0 0
*/
	 JDFXYPair JDFAutoContentObject::GetHalfTonePhaseOrigin() const {
	return GetAttribute(atr_HalfTonePhaseOrigin,WString::emptyStr,L"0 0");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidHalfTonePhaseOrigin(EnumValidationLevel level) const {
		return ValidAttribute(atr_HalfTonePhaseOrigin,AttributeType_XYPair,false);
	};
/**
* Set attribute LayerID
*@param int value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetLayerID(int value){
	SetAttribute(atr_LayerID,WString::valueOf(value));
};
/**
* Get integer attribute LayerID
* @return int the vaue of the attribute 
*/
	 int JDFAutoContentObject::GetLayerID() const {
	return GetIntAttribute(atr_LayerID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidLayerID(EnumValidationLevel level) const {
		return ValidAttribute(atr_LayerID,AttributeType_integer,false);
	};
/**
* Set attribute OrdID
*@param int value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetOrdID(int value){
	SetAttribute(atr_OrdID,WString::valueOf(value));
};
/**
* Get integer attribute OrdID
* @return int the vaue of the attribute 
*/
	 int JDFAutoContentObject::GetOrdID() const {
	return GetIntAttribute(atr_OrdID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidOrdID(EnumValidationLevel level) const {
		return ValidAttribute(atr_OrdID,AttributeType_integer,false);
	};
/**
* Set attribute SourceClipPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetSourceClipPath(const WString& value){
	SetAttribute(atr_SourceClipPath,value);
};
/**
* Get string attribute SourceClipPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentObject::GetSourceClipPath() const {
	return GetAttribute(atr_SourceClipPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidSourceClipPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_SourceClipPath,AttributeType_PDFPath,false);
	};
/**
* Set attribute TrimCTM
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetTrimCTM(const JDFMatrix& value){
	SetAttribute(atr_TrimCTM,value);
};
/**
* Get string attribute TrimCTM
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoContentObject::GetTrimCTM() const {
	return GetAttribute(atr_TrimCTM,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidTrimCTM(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimCTM,AttributeType_matrix,false);
	};
/**
* Set attribute TrimSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoContentObject::SetTrimSize(const JDFXYPair& value){
	SetAttribute(atr_TrimSize,value);
};
/**
* Get string attribute TrimSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoContentObject::GetTrimSize() const {
	return GetAttribute(atr_TrimSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidTrimSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimSize,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoContentObject::TypeString(){
		static const WString enums=WString(L"Unknown,Content,Mark");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoContentObject::TypeString(EnumType value){
		return TypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoContentObject::SetType( EnumType value){
	SetEnumAttribute(atr_Type,value,TypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoContentObject::EnumType JDFAutoContentObject:: GetType() const {
	return (EnumType) GetEnumAttribute(atr_Type,TypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentObject::ValidType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Type,TypeString(),false);
	};
}; // end namespace JDF
