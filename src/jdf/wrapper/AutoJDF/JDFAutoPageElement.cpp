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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPageElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPageElement : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPageElement& JDFAutoPageElement::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPageElement: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPageElement::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPageElement::ValidNodeNames()const{
	return L"*:,PageElement";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPageElement::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ContentDataRefs,ContentListIndex,ElementPages,ContentType,RelativeBox");
};

/**
 typesafe validator
*/
	vWString JDFAutoPageElement::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidContentDataRefs(level)) {
			vAtts.push_back(atr_ContentDataRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidContentListIndex(level)) {
			vAtts.push_back(atr_ContentListIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidElementPages(level)) {
			vAtts.push_back(atr_ElementPages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidContentType(level)) {
			vAtts.push_back(atr_ContentType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeBox(level)) {
			vAtts.push_back(atr_RelativeBox);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ContentDataRefs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPageElement::SetContentDataRefs(const vWString& value){
	SetAttribute(atr_ContentDataRefs,value);
};
/**
* Get string attribute ContentDataRefs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPageElement::GetContentDataRefs() const {
	return GetAttribute(atr_ContentDataRefs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageElement::ValidContentDataRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContentDataRefs,AttributeType_IDREFS,false);
	};
/**
* Set attribute ContentListIndex
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPageElement::SetContentListIndex(int value){
	SetAttribute(atr_ContentListIndex,WString::valueOf(value));
};
/**
* Get integer attribute ContentListIndex
* @return int the vaue of the attribute 
*/
	 int JDFAutoPageElement::GetContentListIndex() const {
	return GetIntAttribute(atr_ContentListIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageElement::ValidContentListIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContentListIndex,AttributeType_integer,false);
	};
/**
* Set attribute ElementPages
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPageElement::SetElementPages(const JDFIntegerRangeList& value){
	SetAttribute(atr_ElementPages,value.GetString());
};
/**
* Get range attribute ElementPages
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPageElement::GetElementPages() const {
	return GetAttribute(atr_ElementPages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageElement::ValidElementPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_ElementPages,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute ContentType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageElement::SetContentType(const WString& value){
	SetAttribute(atr_ContentType,value);
};
/**
* Get string attribute ContentType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageElement::GetContentType() const {
	return GetAttribute(atr_ContentType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageElement::ValidContentType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContentType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute RelativeBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPageElement::SetRelativeBox(const JDFRectangle& value){
	SetAttribute(atr_RelativeBox,value);
};
/**
* Get string attribute RelativeBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPageElement::GetRelativeBox() const {
	return GetAttribute(atr_RelativeBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageElement::ValidRelativeBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeBox,AttributeType_rectangle,false);
	};
}; // end namespace JDF
