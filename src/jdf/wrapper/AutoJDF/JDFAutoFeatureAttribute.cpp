/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFeatureAttribute.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFeatureAttribute : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFeatureAttribute& JDFAutoFeatureAttribute::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFeatureAttribute: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFeatureAttribute::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFeatureAttribute::ValidNodeNames()const{
	return L"*:,FeatureAttribute";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoFeatureAttribute::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CurrentValue,Editable,UserDisplay");
};

/**
 typesafe validator
*/
	vWString JDFAutoFeatureAttribute::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCurrentValue(level)) {
			vAtts.push_back(atr_CurrentValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEditable(level)) {
			vAtts.push_back(atr_Editable);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUserDisplay(level)) {
			vAtts.push_back(atr_UserDisplay);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CurrentValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFeatureAttribute::SetCurrentValue(const WString& value){
	SetAttribute(atr_CurrentValue,value);
};
/**
* Get string attribute CurrentValue
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFeatureAttribute::GetCurrentValue() const {
	return GetAttribute(atr_CurrentValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeatureAttribute::ValidCurrentValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_CurrentValue,AttributeType_string,false);
	};
/**
* Set attribute Editable
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoFeatureAttribute::SetEditable(bool value){
	SetAttribute(atr_Editable,WString::valueOf(value));
};
/**
* Get bool attribute Editable
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoFeatureAttribute::GetEditable() const {return GetBoolAttribute(atr_Editable,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeatureAttribute::ValidEditable(EnumValidationLevel level) const {
		return ValidAttribute(atr_Editable,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFeatureAttribute::UserDisplayString(){
		static const WString enums=WString(L"Unknown,Display,Hide,Dependant");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFeatureAttribute::UserDisplayString(EnumUserDisplay value){
		return UserDisplayString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFeatureAttribute::SetUserDisplay( EnumUserDisplay value){
	SetEnumAttribute(atr_UserDisplay,value,UserDisplayString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFeatureAttribute::EnumUserDisplay JDFAutoFeatureAttribute:: GetUserDisplay() const {
	return (EnumUserDisplay) GetEnumAttribute(atr_UserDisplay,UserDisplayString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeatureAttribute::ValidUserDisplay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_UserDisplay,UserDisplayString(),false);
	};
}; // end namespace JDF
