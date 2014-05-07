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

 
#include "jdf/wrapper/AutoJDF/JDFAutoChangedAttribute.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoChangedAttribute : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoChangedAttribute& JDFAutoChangedAttribute::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoChangedAttribute: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoChangedAttribute::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoChangedAttribute::ValidNodeNames()const{
	return L"*:,ChangedAttribute";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoChangedAttribute::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",AttributeName,ElementType,OldValue,NewValue";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoChangedAttribute::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ElementID");
};

/**
 typesafe validator
*/
	vWString JDFAutoChangedAttribute::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAttributeName(level)) {
			vAtts.push_back(atr_AttributeName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidElementID(level)) {
			vAtts.push_back(atr_ElementID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidElementType(level)) {
			vAtts.push_back(atr_ElementType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOldValue(level)) {
			vAtts.push_back(atr_OldValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNewValue(level)) {
			vAtts.push_back(atr_NewValue);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AttributeName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChangedAttribute::SetAttributeName(const WString& value){
	SetAttribute(atr_AttributeName,value);
};
/**
* Get string attribute AttributeName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChangedAttribute::GetAttributeName() const {
	return GetAttribute(atr_AttributeName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedAttribute::ValidAttributeName(EnumValidationLevel level) const {
		return ValidAttribute(atr_AttributeName,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute ElementID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChangedAttribute::SetElementID(const WString& value){
	SetAttribute(atr_ElementID,value);
};
/**
* Get string attribute ElementID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChangedAttribute::GetElementID() const {
	return GetAttribute(atr_ElementID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedAttribute::ValidElementID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ElementID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ElementType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChangedAttribute::SetElementType(const WString& value){
	SetAttribute(atr_ElementType,value);
};
/**
* Get string attribute ElementType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChangedAttribute::GetElementType() const {
	return GetAttribute(atr_ElementType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedAttribute::ValidElementType(EnumValidationLevel level) const {
		return ValidAttribute(atr_ElementType,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute OldValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChangedAttribute::SetOldValue(const WString& value){
	SetAttribute(atr_OldValue,value);
};
/**
* Get string attribute OldValue
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChangedAttribute::GetOldValue() const {
	return GetAttribute(atr_OldValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedAttribute::ValidOldValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_OldValue,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute NewValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChangedAttribute::SetNewValue(const WString& value){
	SetAttribute(atr_NewValue,value);
};
/**
* Get string attribute NewValue
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChangedAttribute::GetNewValue() const {
	return GetAttribute(atr_NewValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedAttribute::ValidNewValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_NewValue,AttributeType_string,RequiredLevel(level));
	};
}; // end namespace JDF
