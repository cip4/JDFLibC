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

 
#include "jdf/wrapper/AutoJDF/JDFAutoInk.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoInk : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoInk& JDFAutoInk::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoInk: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoInk::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoInk::ValidNodeNames()const{
	return L"*:,Ink";
};

bool JDFAutoInk::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Consumable;
};

bool JDFAutoInk::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Consumable);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoInk::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ColorName,Family,InkName,SpecialInk,SpecificYield");
};

/**
 typesafe validator
*/
	vWString JDFAutoInk::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidColorName(level)) {
			vAtts.push_back(atr_ColorName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFamily(level)) {
			vAtts.push_back(atr_Family);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInkName(level)) {
			vAtts.push_back(atr_InkName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpecialInk(level)) {
			vAtts.push_back(atr_SpecialInk);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpecificYield(level)) {
			vAtts.push_back(atr_SpecificYield);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ColorName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoInk::SetColorName(const WString& value){
	SetAttribute(atr_ColorName,value);
};
/**
* Get string attribute ColorName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoInk::GetColorName() const {
	return GetAttribute(atr_ColorName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInk::ValidColorName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorName,AttributeType_string,false);
	};
/**
* Set attribute Family
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoInk::SetFamily(const WString& value){
	SetAttribute(atr_Family,value);
};
/**
* Get string attribute Family
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoInk::GetFamily() const {
	return GetAttribute(atr_Family,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInk::ValidFamily(EnumValidationLevel level) const {
		return ValidAttribute(atr_Family,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute InkName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoInk::SetInkName(const WString& value){
	SetAttribute(atr_InkName,value);
};
/**
* Get string attribute InkName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoInk::GetInkName() const {
	return GetAttribute(atr_InkName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInk::ValidInkName(EnumValidationLevel level) const {
		return ValidAttribute(atr_InkName,AttributeType_string,false);
	};
/**
* Set attribute SpecialInk
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoInk::SetSpecialInk(const WString& value){
	SetAttribute(atr_SpecialInk,value);
};
/**
* Get string attribute SpecialInk
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoInk::GetSpecialInk() const {
	return GetAttribute(atr_SpecialInk,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInk::ValidSpecialInk(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpecialInk,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute SpecificYield
*@param double value: the value to set the attribute to
*/
	 void JDFAutoInk::SetSpecificYield(double value){
	SetAttribute(atr_SpecificYield,WString::valueOf(value));
};
/**
* Get double attribute SpecificYield
* @return double the vaue of the attribute 
*/
	 double JDFAutoInk::GetSpecificYield() const {
	return GetRealAttribute(atr_SpecificYield,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInk::ValidSpecificYield(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpecificYield,AttributeType_double,false);
	};
}; // end namespace JDF
