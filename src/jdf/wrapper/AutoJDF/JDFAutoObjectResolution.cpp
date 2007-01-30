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

 
#include "jdf/wrapper/AutoJDF/JDFAutoObjectResolution.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoObjectResolution : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoObjectResolution& JDFAutoObjectResolution::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoObjectResolution: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoObjectResolution::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoObjectResolution::ValidNodeNames()const{
	return L"*:,ObjectResolution";
};

bool JDFAutoObjectResolution::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoObjectResolution::init(){
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
	WString JDFAutoObjectResolution::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Resolution";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoObjectResolution::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",SourceObjects,AntiAliasing");
};

/**
 typesafe validator
*/
	vWString JDFAutoObjectResolution::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidResolution(level)) {
			vAtts.push_back(atr_Resolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSourceObjects(level)) {
			vAtts.push_back(atr_SourceObjects);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAntiAliasing(level)) {
			vAtts.push_back(atr_AntiAliasing);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Resolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoObjectResolution::SetResolution(const JDFXYPair& value){
	SetAttribute(atr_Resolution,value);
};
/**
* Get string attribute Resolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoObjectResolution::GetResolution() const {
	return GetAttribute(atr_Resolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoObjectResolution::ValidResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_Resolution,AttributeType_XYPair,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoObjectResolution::SourceObjectsString(){
		static const WString enums=WString(L"Unknown,All,ImagePhotographic,ImageScreenShot,Text,LineArt,SmoothShades");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoObjectResolution::SourceObjectsString(EnumSourceObjects value){
		return SourceObjectsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoObjectResolution::AddSourceObjects( EnumSourceObjects value){
	return AddEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoObjectResolution::RemoveSourceObjects( EnumSourceObjects value){
	return RemoveEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoObjectResolution::GetSourceObjects() const {
	return GetEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),WString::emptyStr,(unsigned int)SourceObjects_All);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoObjectResolution::SetSourceObjects( EnumSourceObjects value){
	SetEnumAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoObjectResolution::SetSourceObjects( const vint& value){
	SetEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/**
* Typesafe attribute validation of SourceObjects
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoObjectResolution::ValidSourceObjects(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),false);
	};
/**
* Set attribute AntiAliasing
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoObjectResolution::SetAntiAliasing(const WString& value){
	SetAttribute(atr_AntiAliasing,value);
};
/**
* Get string attribute AntiAliasing
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoObjectResolution::GetAntiAliasing() const {
	return GetAttribute(atr_AntiAliasing,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoObjectResolution::ValidAntiAliasing(EnumValidationLevel level) const {
		return ValidAttribute(atr_AntiAliasing,AttributeType_NMTOKEN,false);
	};
}; // end namespace JDF
