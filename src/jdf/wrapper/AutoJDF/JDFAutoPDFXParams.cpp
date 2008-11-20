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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPDFXParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPDFXParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPDFXParams& JDFAutoPDFXParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPDFXParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPDFXParams::ValidNodeNames()const{
	return L"*:,PDFXParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPDFXParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PDFX1aCheck,PDFX3Check,PDFXBleedBoxToTrimBoxOffset,PDFXCompliantPDFOnly,PDFXOutputCondition,PDFXOutputIntentProfile,PDFXNoTrimBoxError,PDFXRegistryName,PDFXSetBleedBoxToMediaBox,PDFXTrapped,PDFXTrimBoxToMediaBoxOffset");
};

/**
 typesafe validator
*/
	vWString JDFAutoPDFXParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPDFX1aCheck(level)) {
			vAtts.push_back(atr_PDFX1aCheck);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFX3Check(level)) {
			vAtts.push_back(atr_PDFX3Check);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXBleedBoxToTrimBoxOffset(level)) {
			vAtts.push_back(atr_PDFXBleedBoxToTrimBoxOffset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXCompliantPDFOnly(level)) {
			vAtts.push_back(atr_PDFXCompliantPDFOnly);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXOutputCondition(level)) {
			vAtts.push_back(atr_PDFXOutputCondition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXOutputIntentProfile(level)) {
			vAtts.push_back(atr_PDFXOutputIntentProfile);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXNoTrimBoxError(level)) {
			vAtts.push_back(atr_PDFXNoTrimBoxError);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXRegistryName(level)) {
			vAtts.push_back(atr_PDFXRegistryName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXSetBleedBoxToMediaBox(level)) {
			vAtts.push_back(atr_PDFXSetBleedBoxToMediaBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXTrapped(level)) {
			vAtts.push_back(atr_PDFXTrapped);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPDFXTrimBoxToMediaBoxOffset(level)) {
			vAtts.push_back(atr_PDFXTrimBoxToMediaBoxOffset);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PDFX1aCheck
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFX1aCheck(bool value){
	SetAttribute(atr_PDFX1aCheck,WString::valueOf(value));
};
/**
* Get bool attribute PDFX1aCheck
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFXParams::GetPDFX1aCheck() const {return GetBoolAttribute(atr_PDFX1aCheck,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFX1aCheck(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFX1aCheck,AttributeType_boolean,false);
	};
/**
* Set attribute PDFX3Check
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFX3Check(bool value){
	SetAttribute(atr_PDFX3Check,WString::valueOf(value));
};
/**
* Get bool attribute PDFX3Check
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFXParams::GetPDFX3Check() const {return GetBoolAttribute(atr_PDFX3Check,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFX3Check(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFX3Check,AttributeType_boolean,false);
	};
/**
* Set attribute PDFXBleedBoxToTrimBoxOffset
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFXBleedBoxToTrimBoxOffset(const JDFRectangle& value){
	SetAttribute(atr_PDFXBleedBoxToTrimBoxOffset,value);
};
/**
* Get string attribute PDFXBleedBoxToTrimBoxOffset
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPDFXParams::GetPDFXBleedBoxToTrimBoxOffset() const {
	return GetAttribute(atr_PDFXBleedBoxToTrimBoxOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXBleedBoxToTrimBoxOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXBleedBoxToTrimBoxOffset,AttributeType_rectangle,false);
	};
/**
* Set attribute PDFXCompliantPDFOnly
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFXCompliantPDFOnly(bool value){
	SetAttribute(atr_PDFXCompliantPDFOnly,WString::valueOf(value));
};
/**
* Get bool attribute PDFXCompliantPDFOnly
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFXParams::GetPDFXCompliantPDFOnly() const {return GetBoolAttribute(atr_PDFXCompliantPDFOnly,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXCompliantPDFOnly(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXCompliantPDFOnly,AttributeType_boolean,false);
	};
/**
* Set attribute PDFXOutputCondition
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFXOutputCondition(const WString& value){
	SetAttribute(atr_PDFXOutputCondition,value);
};
/**
* Get string attribute PDFXOutputCondition
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPDFXParams::GetPDFXOutputCondition() const {
	return GetAttribute(atr_PDFXOutputCondition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXOutputCondition(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXOutputCondition,AttributeType_string,false);
	};
/**
* Set attribute PDFXOutputIntentProfile
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFXOutputIntentProfile(const WString& value){
	SetAttribute(atr_PDFXOutputIntentProfile,value);
};
/**
* Get string attribute PDFXOutputIntentProfile
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPDFXParams::GetPDFXOutputIntentProfile() const {
	return GetAttribute(atr_PDFXOutputIntentProfile,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXOutputIntentProfile(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXOutputIntentProfile,AttributeType_string,false);
	};
/**
* Set attribute PDFXNoTrimBoxError
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFXNoTrimBoxError(bool value){
	SetAttribute(atr_PDFXNoTrimBoxError,WString::valueOf(value));
};
/**
* Get bool attribute PDFXNoTrimBoxError
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFXParams::GetPDFXNoTrimBoxError() const {return GetBoolAttribute(atr_PDFXNoTrimBoxError,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXNoTrimBoxError(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXNoTrimBoxError,AttributeType_boolean,false);
	};
/**
* Set attribute PDFXRegistryName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFXRegistryName(const WString& value){
	SetAttribute(atr_PDFXRegistryName,value);
};
/**
* Get string attribute PDFXRegistryName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPDFXParams::GetPDFXRegistryName() const {
	return GetAttribute(atr_PDFXRegistryName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXRegistryName(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXRegistryName,AttributeType_URL,false);
	};
/**
* Set attribute PDFXSetBleedBoxToMediaBox
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFXSetBleedBoxToMediaBox(bool value){
	SetAttribute(atr_PDFXSetBleedBoxToMediaBox,WString::valueOf(value));
};
/**
* Get bool attribute PDFXSetBleedBoxToMediaBox
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFXParams::GetPDFXSetBleedBoxToMediaBox() const {return GetBoolAttribute(atr_PDFXSetBleedBoxToMediaBox,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXSetBleedBoxToMediaBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXSetBleedBoxToMediaBox,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFXParams::PDFXTrappedString(){
		static const WString enums=WString(L"Unknown,True,False");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFXParams::PDFXTrappedString(EnumPDFXTrapped value){
		return PDFXTrappedString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFXParams::SetPDFXTrapped( EnumPDFXTrapped value){
	SetEnumAttribute(atr_PDFXTrapped,value,PDFXTrappedString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFXParams::EnumPDFXTrapped JDFAutoPDFXParams:: GetPDFXTrapped() const {
	return (EnumPDFXTrapped) GetEnumAttribute(atr_PDFXTrapped,PDFXTrappedString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXTrapped(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PDFXTrapped,PDFXTrappedString(),false,WString::emptyStr,true);
	};
/**
* Set attribute PDFXTrimBoxToMediaBoxOffset
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPDFXParams::SetPDFXTrimBoxToMediaBoxOffset(const JDFRectangle& value){
	SetAttribute(atr_PDFXTrimBoxToMediaBoxOffset,value);
};
/**
* Get string attribute PDFXTrimBoxToMediaBoxOffset
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPDFXParams::GetPDFXTrimBoxToMediaBoxOffset() const {
	return GetAttribute(atr_PDFXTrimBoxToMediaBoxOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFXParams::ValidPDFXTrimBoxToMediaBoxOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_PDFXTrimBoxToMediaBoxOffset,AttributeType_rectangle,false);
	};
}; // end namespace JDF
