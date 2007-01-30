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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFontPolicy.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFontPolicy : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFontPolicy& JDFAutoFontPolicy::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFontPolicy: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFontPolicy::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFontPolicy::ValidNodeNames()const{
	return L"*:,FontPolicy";
};

bool JDFAutoFontPolicy::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoFontPolicy::init(){
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
	WString JDFAutoFontPolicy::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",PreferredFont,UseDefaultFont,UseFontEmulation";
};

/**
 typesafe validator
*/
	vWString JDFAutoFontPolicy::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPreferredFont(level)) {
			vAtts.push_back(atr_PreferredFont);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUseDefaultFont(level)) {
			vAtts.push_back(atr_UseDefaultFont);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUseFontEmulation(level)) {
			vAtts.push_back(atr_UseFontEmulation);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PreferredFont
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFontPolicy::SetPreferredFont(const WString& value){
	SetAttribute(atr_PreferredFont,value);
};
/**
* Get string attribute PreferredFont
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFontPolicy::GetPreferredFont() const {
	return GetAttribute(atr_PreferredFont,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontPolicy::ValidPreferredFont(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreferredFont,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute UseDefaultFont
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoFontPolicy::SetUseDefaultFont(bool value){
	SetAttribute(atr_UseDefaultFont,WString::valueOf(value));
};
/**
* Get bool attribute UseDefaultFont
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoFontPolicy::GetUseDefaultFont() const {return GetBoolAttribute(atr_UseDefaultFont,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontPolicy::ValidUseDefaultFont(EnumValidationLevel level) const {
		return ValidAttribute(atr_UseDefaultFont,AttributeType_boolean,RequiredLevel(level));
	};
/**
* Set attribute UseFontEmulation
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoFontPolicy::SetUseFontEmulation(bool value){
	SetAttribute(atr_UseFontEmulation,WString::valueOf(value));
};
/**
* Get bool attribute UseFontEmulation
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoFontPolicy::GetUseFontEmulation() const {return GetBoolAttribute(atr_UseFontEmulation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFontPolicy::ValidUseFontEmulation(EnumValidationLevel level) const {
		return ValidAttribute(atr_UseFontEmulation,AttributeType_boolean,RequiredLevel(level));
	};
}; // end namespace JDF
