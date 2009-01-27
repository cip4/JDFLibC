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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTIFFtag.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTIFFtag : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTIFFtag& JDFAutoTIFFtag::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTIFFtag: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTIFFtag::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTIFFtag::ValidNodeNames()const{
	return L"*:,TIFFtag";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoTIFFtag::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",TagNumber,TagType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoTIFFtag::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",IntegerValue,NumberValue,StringValue,BinaryValue");
};

/**
 typesafe validator
*/
	vWString JDFAutoTIFFtag::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTagNumber(level)) {
			vAtts.push_back(atr_TagNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTagType(level)) {
			vAtts.push_back(atr_TagType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIntegerValue(level)) {
			vAtts.push_back(atr_IntegerValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberValue(level)) {
			vAtts.push_back(atr_NumberValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStringValue(level)) {
			vAtts.push_back(atr_StringValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBinaryValue(level)) {
			vAtts.push_back(atr_BinaryValue);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute TagNumber
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTIFFtag::SetTagNumber(int value){
	SetAttribute(atr_TagNumber,WString::valueOf(value));
};
/**
* Get integer attribute TagNumber
* @return int the vaue of the attribute 
*/
	 int JDFAutoTIFFtag::GetTagNumber() const {
	return GetIntAttribute(atr_TagNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFtag::ValidTagNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_TagNumber,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute TagType
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTIFFtag::SetTagType(int value){
	SetAttribute(atr_TagType,WString::valueOf(value));
};
/**
* Get integer attribute TagType
* @return int the vaue of the attribute 
*/
	 int JDFAutoTIFFtag::GetTagType() const {
	return GetIntAttribute(atr_TagType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFtag::ValidTagType(EnumValidationLevel level) const {
		return ValidAttribute(atr_TagType,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute IntegerValue
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoTIFFtag::SetIntegerValue(const JDFIntegerList& value){
	SetAttribute(atr_IntegerValue,value.GetString());
};
/**
* Get string attribute IntegerValue
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoTIFFtag::GetIntegerValue() const {
	return GetAttribute(atr_IntegerValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFtag::ValidIntegerValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_IntegerValue,AttributeType_IntegerList,false);
	};
/**
* Set attribute NumberValue
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoTIFFtag::SetNumberValue(const JDFNumberList& value){
	SetAttribute(atr_NumberValue,value.GetString());
};
/**
* Get string attribute NumberValue
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoTIFFtag::GetNumberValue() const {
	return GetAttribute(atr_NumberValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFtag::ValidNumberValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberValue,AttributeType_NumberList,false);
	};
/**
* Set attribute StringValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTIFFtag::SetStringValue(const WString& value){
	SetAttribute(atr_StringValue,value);
};
/**
* Get string attribute StringValue
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoTIFFtag::GetStringValue() const {
	return GetAttribute(atr_StringValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFtag::ValidStringValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_StringValue,AttributeType_string,false);
	};
/**
* Set attribute BinaryValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTIFFtag::SetBinaryValue(const WString& value){
	SetAttribute(atr_BinaryValue,value);
};
/**
* Get string attribute BinaryValue
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoTIFFtag::GetBinaryValue() const {
	return GetAttribute(atr_BinaryValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTIFFtag::ValidBinaryValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_BinaryValue,AttributeType_hexBinary,false);
	};
}; // end namespace JDF
