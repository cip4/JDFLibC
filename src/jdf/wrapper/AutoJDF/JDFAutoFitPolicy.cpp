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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFitPolicy.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFitPolicy : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFitPolicy& JDFAutoFitPolicy::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFitPolicy: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFitPolicy::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFitPolicy::ValidNodeNames()const{
	return L"*:,FitPolicy";
};

bool JDFAutoFitPolicy::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoFitPolicy::init(){
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
	WString JDFAutoFitPolicy::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",GutterPolicy,ClipOffset,MinGutter,RotatePolicy,SizePolicy");
};

/**
 typesafe validator
*/
	vWString JDFAutoFitPolicy::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidGutterPolicy(level)) {
			vAtts.push_back(atr_GutterPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipOffset(level)) {
			vAtts.push_back(atr_ClipOffset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinGutter(level)) {
			vAtts.push_back(atr_MinGutter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotatePolicy(level)) {
			vAtts.push_back(atr_RotatePolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSizePolicy(level)) {
			vAtts.push_back(atr_SizePolicy);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFitPolicy::GutterPolicyString(){
		static const WString enums=WString(L"Unknown,Distribute,Fixed");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFitPolicy::GutterPolicyString(EnumGutterPolicy value){
		return GutterPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFitPolicy::SetGutterPolicy( EnumGutterPolicy value){
	SetEnumAttribute(atr_GutterPolicy,value,GutterPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFitPolicy::EnumGutterPolicy JDFAutoFitPolicy:: GetGutterPolicy() const {
	return (EnumGutterPolicy) GetEnumAttribute(atr_GutterPolicy,GutterPolicyString(),WString::emptyStr,GutterPolicy_Fixed);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFitPolicy::ValidGutterPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_GutterPolicy,GutterPolicyString(),false);
	};
/**
* Set attribute ClipOffset
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoFitPolicy::SetClipOffset(const JDFXYPair& value){
	SetAttribute(atr_ClipOffset,value);
};
/**
* Get string attribute ClipOffset
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoFitPolicy::GetClipOffset() const {
	return GetAttribute(atr_ClipOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFitPolicy::ValidClipOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipOffset,AttributeType_XYPair,false);
	};
/**
* Set attribute MinGutter
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoFitPolicy::SetMinGutter(const JDFXYPair& value){
	SetAttribute(atr_MinGutter,value);
};
/**
* Get string attribute MinGutter
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoFitPolicy::GetMinGutter() const {
	return GetAttribute(atr_MinGutter,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFitPolicy::ValidMinGutter(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinGutter,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFitPolicy::RotatePolicyString(){
		static const WString enums=WString(L"Unknown,NoRotate,RotateOrthogonal,RotateClockwise,RotateCounterClockwise");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFitPolicy::RotatePolicyString(EnumRotatePolicy value){
		return RotatePolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFitPolicy::SetRotatePolicy( EnumRotatePolicy value){
	SetEnumAttribute(atr_RotatePolicy,value,RotatePolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFitPolicy::EnumRotatePolicy JDFAutoFitPolicy:: GetRotatePolicy() const {
	return (EnumRotatePolicy) GetEnumAttribute(atr_RotatePolicy,RotatePolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFitPolicy::ValidRotatePolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_RotatePolicy,RotatePolicyString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFitPolicy::SizePolicyString(){
		static const WString enums=WString(L"Unknown,ClipToMaxPage,Abort,FitToPage,ReduceToFit,Tile");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFitPolicy::SizePolicyString(EnumSizePolicy value){
		return SizePolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFitPolicy::SetSizePolicy( EnumSizePolicy value){
	SetEnumAttribute(atr_SizePolicy,value,SizePolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFitPolicy::EnumSizePolicy JDFAutoFitPolicy:: GetSizePolicy() const {
	return (EnumSizePolicy) GetEnumAttribute(atr_SizePolicy,SizePolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFitPolicy::ValidSizePolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SizePolicy,SizePolicyString(),false);
	};
}; // end namespace JDF
