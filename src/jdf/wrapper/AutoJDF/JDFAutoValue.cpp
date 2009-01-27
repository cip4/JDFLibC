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

 
#include "jdf/wrapper/AutoJDF/JDFAutoValue.h"
#include "jdf/wrapper/JDFLoc.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoValue : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoValue& JDFAutoValue::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoValue: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoValue::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoValue::ValidNodeNames()const{
	return L"*:,Value";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoValue::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",AllowedValue";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoValue::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PresentValue,ValueUsage");
};

/**
 typesafe validator
*/
	vWString JDFAutoValue::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAllowedValue(level)) {
			vAtts.push_back(atr_AllowedValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPresentValue(level)) {
			vAtts.push_back(atr_PresentValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidValueUsage(level)) {
			vAtts.push_back(atr_ValueUsage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AllowedValue
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoValue::SetAllowedValue(const JDFMatrix& value){
	SetAttribute(atr_AllowedValue,value);
};
/**
* Get string attribute AllowedValue
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoValue::GetAllowedValue() const {
	return GetAttribute(atr_AllowedValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoValue::ValidAllowedValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_AllowedValue,AttributeType_matrix,RequiredLevel(level));
	};
/**
* Set attribute PresentValue
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoValue::SetPresentValue(const JDFMatrix& value){
	SetAttribute(atr_PresentValue,value);
};
/**
* Get string attribute PresentValue
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoValue::GetPresentValue() const {
	return GetAttribute(atr_PresentValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoValue::ValidPresentValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentValue,AttributeType_matrix,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoValue::ValueUsageString(){
		static const WString enums=WString(L"Unknown,Present,Allowed");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoValue::ValueUsageString(EnumValueUsage value){
		return ValueUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoValue::SetValueUsage( EnumValueUsage value){
	SetEnumAttribute(atr_ValueUsage,value,ValueUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoValue::EnumValueUsage JDFAutoValue:: GetValueUsage() const {
	return (EnumValueUsage) GetEnumAttribute(atr_ValueUsage,ValueUsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoValue::ValidValueUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ValueUsage,ValueUsageString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFLoc JDFAutoValue::GetLoc(int iSkip)const{
	JDFLoc e=GetElement(elm_Loc,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoValue::GetCreateLoc(int iSkip){
	JDFLoc e=GetCreateElement(elm_Loc,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoValue::AppendLoc(){
	JDFLoc e=AppendElement(elm_Loc);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoValue::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Loc);

		for(i=0;i<nElem;i++){
			if (!GetLoc(i).IsValid(level)) {
				vElem.AppendUnique(elm_Loc);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoValue::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Loc";
	};
}; // end namespace JDF
