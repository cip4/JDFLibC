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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAutomatedOverprintParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAutomatedOverprintParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAutomatedOverprintParams& JDFAutoAutomatedOverprintParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAutomatedOverprintParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAutomatedOverprintParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAutomatedOverprintParams::ValidNodeNames()const{
	return L"*:,AutomatedOverprintParams";
};

bool JDFAutoAutomatedOverprintParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoAutomatedOverprintParams::init(){
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
	WString JDFAutoAutomatedOverprintParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",KnockOutCMYKWhite,OverPrintBlackText,OverPrintBlackLineArt,TextBlackLevel,LineArtBlackLevel,TextSizeThreshold");
};

/**
 typesafe validator
*/
	vWString JDFAutoAutomatedOverprintParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidKnockOutCMYKWhite(level)) {
			vAtts.push_back(atr_KnockOutCMYKWhite);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverPrintBlackText(level)) {
			vAtts.push_back(atr_OverPrintBlackText);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverPrintBlackLineArt(level)) {
			vAtts.push_back(atr_OverPrintBlackLineArt);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTextBlackLevel(level)) {
			vAtts.push_back(atr_TextBlackLevel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLineArtBlackLevel(level)) {
			vAtts.push_back(atr_LineArtBlackLevel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTextSizeThreshold(level)) {
			vAtts.push_back(atr_TextSizeThreshold);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute KnockOutCMYKWhite
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAutomatedOverprintParams::SetKnockOutCMYKWhite(bool value){
	SetAttribute(atr_KnockOutCMYKWhite,WString::valueOf(value));
};
/**
* Get bool attribute KnockOutCMYKWhite
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAutomatedOverprintParams::GetKnockOutCMYKWhite() const {return GetBoolAttribute(atr_KnockOutCMYKWhite,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAutomatedOverprintParams::ValidKnockOutCMYKWhite(EnumValidationLevel level) const {
		return ValidAttribute(atr_KnockOutCMYKWhite,AttributeType_boolean,false);
	};
/**
* Set attribute OverPrintBlackText
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAutomatedOverprintParams::SetOverPrintBlackText(bool value){
	SetAttribute(atr_OverPrintBlackText,WString::valueOf(value));
};
/**
* Get bool attribute OverPrintBlackText
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAutomatedOverprintParams::GetOverPrintBlackText() const {return GetBoolAttribute(atr_OverPrintBlackText,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAutomatedOverprintParams::ValidOverPrintBlackText(EnumValidationLevel level) const {
		return ValidAttribute(atr_OverPrintBlackText,AttributeType_boolean,false);
	};
/**
* Set attribute OverPrintBlackLineArt
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoAutomatedOverprintParams::SetOverPrintBlackLineArt(bool value){
	SetAttribute(atr_OverPrintBlackLineArt,WString::valueOf(value));
};
/**
* Get bool attribute OverPrintBlackLineArt
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoAutomatedOverprintParams::GetOverPrintBlackLineArt() const {return GetBoolAttribute(atr_OverPrintBlackLineArt,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAutomatedOverprintParams::ValidOverPrintBlackLineArt(EnumValidationLevel level) const {
		return ValidAttribute(atr_OverPrintBlackLineArt,AttributeType_boolean,false);
	};
/**
* Set attribute TextBlackLevel
*@param double value: the value to set the attribute to
*/
	 void JDFAutoAutomatedOverprintParams::SetTextBlackLevel(double value){
	SetAttribute(atr_TextBlackLevel,WString::valueOf(value));
};
/**
* Get double attribute TextBlackLevel
* @return double the vaue of the attribute ; defaults to 1
*/
	 double JDFAutoAutomatedOverprintParams::GetTextBlackLevel() const {
	return GetRealAttribute(atr_TextBlackLevel,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAutomatedOverprintParams::ValidTextBlackLevel(EnumValidationLevel level) const {
		return ValidAttribute(atr_TextBlackLevel,AttributeType_double,false);
	};
/**
* Set attribute LineArtBlackLevel
*@param double value: the value to set the attribute to
*/
	 void JDFAutoAutomatedOverprintParams::SetLineArtBlackLevel(double value){
	SetAttribute(atr_LineArtBlackLevel,WString::valueOf(value));
};
/**
* Get double attribute LineArtBlackLevel
* @return double the vaue of the attribute 
*/
	 double JDFAutoAutomatedOverprintParams::GetLineArtBlackLevel() const {
	return GetRealAttribute(atr_LineArtBlackLevel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAutomatedOverprintParams::ValidLineArtBlackLevel(EnumValidationLevel level) const {
		return ValidAttribute(atr_LineArtBlackLevel,AttributeType_double,false);
	};
/**
* Set attribute TextSizeThreshold
*@param int value: the value to set the attribute to
*/
	 void JDFAutoAutomatedOverprintParams::SetTextSizeThreshold(int value){
	SetAttribute(atr_TextSizeThreshold,WString::valueOf(value));
};
/**
* Get integer attribute TextSizeThreshold
* @return int the vaue of the attribute 
*/
	 int JDFAutoAutomatedOverprintParams::GetTextSizeThreshold() const {
	return GetIntAttribute(atr_TextSizeThreshold,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAutomatedOverprintParams::ValidTextSizeThreshold(EnumValidationLevel level) const {
		return ValidAttribute(atr_TextSizeThreshold,AttributeType_integer,false);
	};
}; // end namespace JDF
