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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFontParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFontParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFontParams& JDFAutoFontParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFontParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFontParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFontParams::ValidNodeNames()const{
	return L"*:,FontParams";
};

bool JDFAutoFontParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoFontParams::init(){
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
	WString JDFAutoFontParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",EmbedAllFonts,CannotEmbedFontPolicy,AlwaysEmbed,MaxSubsetPct,NeverEmbed,SubsetFonts");
};

/**
 typesafe validator
*/
	vWString JDFAutoFontParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidEmbedAllFonts(level)) {
			vAtts.push_back(atr_EmbedAllFonts);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCannotEmbedFontPolicy(level)) {
			vAtts.push_back(atr_CannotEmbedFontPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAlwaysEmbed(level)) {
			vAtts.push_back(atr_AlwaysEmbed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxSubsetPct(level)) {
			vAtts.push_back(atr_MaxSubsetPct);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNeverEmbed(level)) {
			vAtts.push_back(atr_NeverEmbed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSubsetFonts(level)) {
			vAtts.push_back(atr_SubsetFonts);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute EmbedAllFonts
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoFontParams::SetEmbedAllFonts(bool value){
	SetAttribute(atr_EmbedAllFonts,WString::valueOf(value));
};
/**
* Get bool attribute EmbedAllFonts
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoFontParams::GetEmbedAllFonts() const {return GetBoolAttribute(atr_EmbedAllFonts,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontParams::ValidEmbedAllFonts(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmbedAllFonts,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFontParams::CannotEmbedFontPolicyString(){
		static const WString enums=WString(L"Unknown,Warning,Error,OK");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFontParams::CannotEmbedFontPolicyString(EnumCannotEmbedFontPolicy value){
		return CannotEmbedFontPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFontParams::SetCannotEmbedFontPolicy( EnumCannotEmbedFontPolicy value){
	SetEnumAttribute(atr_CannotEmbedFontPolicy,value,CannotEmbedFontPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFontParams::EnumCannotEmbedFontPolicy JDFAutoFontParams:: GetCannotEmbedFontPolicy() const {
	return (EnumCannotEmbedFontPolicy) GetEnumAttribute(atr_CannotEmbedFontPolicy,CannotEmbedFontPolicyString(),WString::emptyStr,CannotEmbedFontPolicy_Warning);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontParams::ValidCannotEmbedFontPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CannotEmbedFontPolicy,CannotEmbedFontPolicyString(),false);
	};
/**
* Set attribute AlwaysEmbed
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoFontParams::SetAlwaysEmbed(const vWString& value){
	SetAttribute(atr_AlwaysEmbed,value);
};
/**
* Get string attribute AlwaysEmbed
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoFontParams::GetAlwaysEmbed() const {
	return GetAttribute(atr_AlwaysEmbed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontParams::ValidAlwaysEmbed(EnumValidationLevel level) const {
		return ValidAttribute(atr_AlwaysEmbed,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute MaxSubsetPct
*@param int value: the value to set the attribute to
*/
	 void JDFAutoFontParams::SetMaxSubsetPct(int value){
	SetAttribute(atr_MaxSubsetPct,WString::valueOf(value));
};
/**
* Get integer attribute MaxSubsetPct
* @return int the vaue of the attribute 
*/
	 int JDFAutoFontParams::GetMaxSubsetPct() const {
	return GetIntAttribute(atr_MaxSubsetPct,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontParams::ValidMaxSubsetPct(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxSubsetPct,AttributeType_integer,false);
	};
/**
* Set attribute NeverEmbed
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoFontParams::SetNeverEmbed(const vWString& value){
	SetAttribute(atr_NeverEmbed,value);
};
/**
* Get string attribute NeverEmbed
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoFontParams::GetNeverEmbed() const {
	return GetAttribute(atr_NeverEmbed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontParams::ValidNeverEmbed(EnumValidationLevel level) const {
		return ValidAttribute(atr_NeverEmbed,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute SubsetFonts
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoFontParams::SetSubsetFonts(bool value){
	SetAttribute(atr_SubsetFonts,WString::valueOf(value));
};
/**
* Get bool attribute SubsetFonts
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoFontParams::GetSubsetFonts() const {return GetBoolAttribute(atr_SubsetFonts,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontParams::ValidSubsetFonts(EnumValidationLevel level) const {
		return ValidAttribute(atr_SubsetFonts,AttributeType_boolean,false);
	};
}; // end namespace JDF
