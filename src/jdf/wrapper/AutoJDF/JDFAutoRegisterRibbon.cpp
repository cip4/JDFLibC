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

 
#include "jdf/wrapper/AutoJDF/JDFAutoRegisterRibbon.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRegisterRibbon : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoRegisterRibbon& JDFAutoRegisterRibbon::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoRegisterRibbon: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoRegisterRibbon::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoRegisterRibbon::ValidNodeNames()const{
	return L"*:,RegisterRibbon";
};

bool JDFAutoRegisterRibbon::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Consumable;
};

bool JDFAutoRegisterRibbon::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Consumable);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoRegisterRibbon::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",LengthOverall,VisibleLength";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoRegisterRibbon::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Material,RibbonColor,RibbonEnd");
};

/**
 typesafe validator
*/
	vWString JDFAutoRegisterRibbon::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidLengthOverall(level)) {
			vAtts.push_back(atr_LengthOverall);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVisibleLength(level)) {
			vAtts.push_back(atr_VisibleLength);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaterial(level)) {
			vAtts.push_back(atr_Material);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRibbonColor(level)) {
			vAtts.push_back(atr_RibbonColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRibbonEnd(level)) {
			vAtts.push_back(atr_RibbonEnd);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute LengthOverall
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRegisterRibbon::SetLengthOverall(double value){
	SetAttribute(atr_LengthOverall,WString::valueOf(value));
};
/**
* Get double attribute LengthOverall
* @return double the vaue of the attribute 
*/
	 double JDFAutoRegisterRibbon::GetLengthOverall() const {
	return GetRealAttribute(atr_LengthOverall,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterRibbon::ValidLengthOverall(EnumValidationLevel level) const {
		return ValidAttribute(atr_LengthOverall,AttributeType_double,RequiredLevel(level));
	};
/**
* Set attribute VisibleLength
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRegisterRibbon::SetVisibleLength(double value){
	SetAttribute(atr_VisibleLength,WString::valueOf(value));
};
/**
* Get double attribute VisibleLength
* @return double the vaue of the attribute 
*/
	 double JDFAutoRegisterRibbon::GetVisibleLength() const {
	return GetRealAttribute(atr_VisibleLength,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterRibbon::ValidVisibleLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_VisibleLength,AttributeType_double,RequiredLevel(level));
	};
/**
* Set attribute Material
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRegisterRibbon::SetMaterial(const WString& value){
	SetAttribute(atr_Material,value);
};
/**
* Get string attribute Material
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRegisterRibbon::GetMaterial() const {
	return GetAttribute(atr_Material,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterRibbon::ValidMaterial(EnumValidationLevel level) const {
		return ValidAttribute(atr_Material,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoRegisterRibbon::SetRibbonColor( EnumNamedColor value){
	SetEnumAttribute(atr_RibbonColor,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRegisterRibbon::EnumNamedColor JDFAutoRegisterRibbon:: GetRibbonColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_RibbonColor,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterRibbon::ValidRibbonColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_RibbonColor,NamedColorString(),false);
	};
/**
* Set attribute RibbonEnd
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRegisterRibbon::SetRibbonEnd(const WString& value){
	SetAttribute(atr_RibbonEnd,value);
};
/**
* Get string attribute RibbonEnd
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRegisterRibbon::GetRibbonEnd() const {
	return GetAttribute(atr_RibbonEnd,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterRibbon::ValidRibbonEnd(EnumValidationLevel level) const {
		return ValidAttribute(atr_RibbonEnd,AttributeType_NMTOKEN,false);
	};
}; // end namespace JDF
