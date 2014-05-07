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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPositionObj.h"
#include "jdf/wrapper/JDFRefAnchor.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPositionObj : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPositionObj& JDFAutoPositionObj::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPositionObj: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPositionObj::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPositionObj::ValidNodeNames()const{
	return L"*:,PositionObj";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPositionObj::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Anchor,CTM,PageRange,PositionPolicy,RelativeSize,RotationPolicy,Size,SizePolicy");
};

/**
 typesafe validator
*/
	vWString JDFAutoPositionObj::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAnchor(level)) {
			vAtts.push_back(atr_Anchor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCTM(level)) {
			vAtts.push_back(atr_CTM);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageRange(level)) {
			vAtts.push_back(atr_PageRange);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPositionPolicy(level)) {
			vAtts.push_back(atr_PositionPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeSize(level)) {
			vAtts.push_back(atr_RelativeSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotationPolicy(level)) {
			vAtts.push_back(atr_RotationPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSize(level)) {
			vAtts.push_back(atr_Size);
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

	const WString& JDFAutoPositionObj::AnchorString(){
		static const WString enums=WString(L"Unknown,TopLeft,TopCenter,TopRight,CenterLeft,Center,CenterRight,BottomLeft,BottomCenter,BottomRight");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPositionObj::AnchorString(EnumAnchor value){
		return AnchorString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPositionObj::SetAnchor( EnumAnchor value){
	SetEnumAttribute(atr_Anchor,value,AnchorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPositionObj::EnumAnchor JDFAutoPositionObj:: GetAnchor() const {
	return (EnumAnchor) GetEnumAttribute(atr_Anchor,AnchorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPositionObj::ValidAnchor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Anchor,AnchorString(),false);
	};
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoPositionObj::SetCTM(const JDFMatrix& value){
	SetAttribute(atr_CTM,value);
};
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoPositionObj::GetCTM() const {
	return GetAttribute(atr_CTM,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPositionObj::ValidCTM(EnumValidationLevel level) const {
		return ValidAttribute(atr_CTM,AttributeType_matrix,false);
	};
/**
* Set attribute PageRange
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPositionObj::SetPageRange(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageRange,value.GetString());
};
/**
* Get range attribute PageRange
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPositionObj::GetPageRange() const {
	return GetAttribute(atr_PageRange,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPositionObj::ValidPageRange(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageRange,AttributeType_IntegerRangeList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPositionObj::PositionPolicyString(){
		static const WString enums=WString(L"Unknown,Exact,Free");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPositionObj::PositionPolicyString(EnumPositionPolicy value){
		return PositionPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPositionObj::SetPositionPolicy( EnumPositionPolicy value){
	SetEnumAttribute(atr_PositionPolicy,value,PositionPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPositionObj::EnumPositionPolicy JDFAutoPositionObj:: GetPositionPolicy() const {
	return (EnumPositionPolicy) GetEnumAttribute(atr_PositionPolicy,PositionPolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPositionObj::ValidPositionPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PositionPolicy,PositionPolicyString(),false);
	};
/**
* Set attribute RelativeSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPositionObj::SetRelativeSize(const JDFXYPair& value){
	SetAttribute(atr_RelativeSize,value);
};
/**
* Get string attribute RelativeSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPositionObj::GetRelativeSize() const {
	return GetAttribute(atr_RelativeSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPositionObj::ValidRelativeSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeSize,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPositionObj::RotationPolicyString(){
		static const WString enums=WString(L"Unknown,Exact,Free");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPositionObj::RotationPolicyString(EnumRotationPolicy value){
		return RotationPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPositionObj::SetRotationPolicy( EnumRotationPolicy value){
	SetEnumAttribute(atr_RotationPolicy,value,RotationPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPositionObj::EnumRotationPolicy JDFAutoPositionObj:: GetRotationPolicy() const {
	return (EnumRotationPolicy) GetEnumAttribute(atr_RotationPolicy,RotationPolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPositionObj::ValidRotationPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_RotationPolicy,RotationPolicyString(),false);
	};
/**
* Set attribute Size
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPositionObj::SetSize(const JDFXYPair& value){
	SetAttribute(atr_Size,value);
};
/**
* Get string attribute Size
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPositionObj::GetSize() const {
	return GetAttribute(atr_Size,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPositionObj::ValidSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_Size,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPositionObj::SizePolicyString(){
		static const WString enums=WString(L"Unknown,Exact,Free");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPositionObj::SizePolicyString(EnumSizePolicy value){
		return SizePolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPositionObj::SetSizePolicy( EnumSizePolicy value){
	SetEnumAttribute(atr_SizePolicy,value,SizePolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPositionObj::EnumSizePolicy JDFAutoPositionObj:: GetSizePolicy() const {
	return (EnumSizePolicy) GetEnumAttribute(atr_SizePolicy,SizePolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPositionObj::ValidSizePolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SizePolicy,SizePolicyString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFRefAnchor JDFAutoPositionObj::GetRefAnchor(int iSkip)const{
	JDFRefAnchor e=GetElement(elm_RefAnchor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRefAnchor JDFAutoPositionObj::GetCreateRefAnchor(int iSkip){
	JDFRefAnchor e=GetCreateElement(elm_RefAnchor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRefAnchor JDFAutoPositionObj::AppendRefAnchor(){
	JDFRefAnchor e=AppendElement(elm_RefAnchor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPositionObj::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_RefAnchor);

		for(i=0;i<nElem;i++){
			if (!GetRefAnchor(i).IsValid(level)) {
				vElem.AppendUnique(elm_RefAnchor);
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
	WString JDFAutoPositionObj::OptionalElements()const{
		return JDFElement::OptionalElements()+L",RefAnchor";
	};
}; // end namespace JDF
