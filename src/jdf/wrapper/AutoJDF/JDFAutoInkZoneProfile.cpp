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

 
#include "jdf/wrapper/AutoJDF/JDFAutoInkZoneProfile.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoInkZoneProfile : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoInkZoneProfile& JDFAutoInkZoneProfile::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoInkZoneProfile: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoInkZoneProfile::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoInkZoneProfile::ValidNodeNames()const{
	return L"*:,InkZoneProfile";
};

bool JDFAutoInkZoneProfile::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoInkZoneProfile::init(){
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
	WString JDFAutoInkZoneProfile::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",ZoneSettingsX,ZoneWidth";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoInkZoneProfile::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ZoneHeight,ZoneSettingsY");
};

/**
 typesafe validator
*/
	vWString JDFAutoInkZoneProfile::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidZoneSettingsX(level)) {
			vAtts.push_back(atr_ZoneSettingsX);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidZoneWidth(level)) {
			vAtts.push_back(atr_ZoneWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidZoneHeight(level)) {
			vAtts.push_back(atr_ZoneHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidZoneSettingsY(level)) {
			vAtts.push_back(atr_ZoneSettingsY);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ZoneSettingsX
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoInkZoneProfile::SetZoneSettingsX(const JDFNumberList& value){
	SetAttribute(atr_ZoneSettingsX,value.GetString());
};
/**
* Get string attribute ZoneSettingsX
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoInkZoneProfile::GetZoneSettingsX() const {
	return GetAttribute(atr_ZoneSettingsX,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneProfile::ValidZoneSettingsX(EnumValidationLevel level) const {
		return ValidAttribute(atr_ZoneSettingsX,AttributeType_NumberList,RequiredLevel(level));
	};
/**
* Set attribute ZoneWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoInkZoneProfile::SetZoneWidth(double value){
	SetAttribute(atr_ZoneWidth,WString::valueOf(value));
};
/**
* Get double attribute ZoneWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoInkZoneProfile::GetZoneWidth() const {
	return GetRealAttribute(atr_ZoneWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneProfile::ValidZoneWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_ZoneWidth,AttributeType_double,RequiredLevel(level));
	};
/**
* Set attribute ZoneHeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoInkZoneProfile::SetZoneHeight(double value){
	SetAttribute(atr_ZoneHeight,WString::valueOf(value));
};
/**
* Get double attribute ZoneHeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoInkZoneProfile::GetZoneHeight() const {
	return GetRealAttribute(atr_ZoneHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneProfile::ValidZoneHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_ZoneHeight,AttributeType_double,false);
	};
/**
* Set attribute ZoneSettingsY
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoInkZoneProfile::SetZoneSettingsY(const JDFNumberList& value){
	SetAttribute(atr_ZoneSettingsY,value.GetString());
};
/**
* Get string attribute ZoneSettingsY
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoInkZoneProfile::GetZoneSettingsY() const {
	return GetAttribute(atr_ZoneSettingsY,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInkZoneProfile::ValidZoneSettingsY(EnumValidationLevel level) const {
		return ValidAttribute(atr_ZoneSettingsY,AttributeType_NumberList,false);
	};
}; // end namespace JDF
