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

 
#include "jdf/wrapper/AutoJDF/JDFAutoChannelBindingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoChannelBindingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoChannelBindingParams& JDFAutoChannelBindingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoChannelBindingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoChannelBindingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoChannelBindingParams::ValidNodeNames()const{
	return L"*:,ChannelBindingParams";
};

bool JDFAutoChannelBindingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoChannelBindingParams::init(){
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
	WString JDFAutoChannelBindingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ClampSystem,Brand,ClampColor,ClampD,ClampSize");
};

/**
 typesafe validator
*/
	vWString JDFAutoChannelBindingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidClampSystem(level)) {
			vAtts.push_back(atr_ClampSystem);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBrand(level)) {
			vAtts.push_back(atr_Brand);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClampColor(level)) {
			vAtts.push_back(atr_ClampColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClampD(level)) {
			vAtts.push_back(atr_ClampD);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClampSize(level)) {
			vAtts.push_back(atr_ClampSize);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ClampSystem
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoChannelBindingParams::SetClampSystem(bool value){
	SetAttribute(atr_ClampSystem,WString::valueOf(value));
};
/**
* Get bool attribute ClampSystem
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoChannelBindingParams::GetClampSystem() const {return GetBoolAttribute(atr_ClampSystem,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChannelBindingParams::ValidClampSystem(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClampSystem,AttributeType_boolean,false);
	};
/**
* Set attribute Brand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChannelBindingParams::SetBrand(const WString& value){
	SetAttribute(atr_Brand,value);
};
/**
* Get string attribute Brand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChannelBindingParams::GetBrand() const {
	return GetAttribute(atr_Brand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChannelBindingParams::ValidBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_Brand,AttributeType_string,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoChannelBindingParams::SetClampColor( EnumNamedColor value){
	SetEnumAttribute(atr_ClampColor,value,NamedColorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoChannelBindingParams::EnumNamedColor JDFAutoChannelBindingParams:: GetClampColor() const {
	return (EnumNamedColor) GetEnumAttribute(atr_ClampColor,NamedColorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChannelBindingParams::ValidClampColor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ClampColor,NamedColorString(),false);
	};
/**
* Set attribute ClampD
*@param double value: the value to set the attribute to
*/
	 void JDFAutoChannelBindingParams::SetClampD(double value){
	SetAttribute(atr_ClampD,WString::valueOf(value));
};
/**
* Get double attribute ClampD
* @return double the vaue of the attribute 
*/
	 double JDFAutoChannelBindingParams::GetClampD() const {
	return GetRealAttribute(atr_ClampD,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChannelBindingParams::ValidClampD(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClampD,AttributeType_double,false);
	};
/**
* Set attribute ClampSize
*@param JDFShape value: the value to set the attribute to
*/
	 void JDFAutoChannelBindingParams::SetClampSize(const JDFShape& value){
	SetAttribute(atr_ClampSize,value);
};
/**
* Get string attribute ClampSize
* @return JDFShape the vaue of the attribute 
*/
	 JDFShape JDFAutoChannelBindingParams::GetClampSize() const {
	return GetAttribute(atr_ClampSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChannelBindingParams::ValidClampSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClampSize,AttributeType_shape,false);
	};
}; // end namespace JDF
