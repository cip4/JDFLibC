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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPosition.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPosition : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPosition& JDFAutoPosition::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPosition: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPosition::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPosition::ValidNodeNames()const{
	return L"*:,Position";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPosition::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AbsoluteBox,BlockName,MarginBottom,MarginTop,MarginLeft,MarginRight,Orientation,RelativeBox");
};

/**
 typesafe validator
*/
	vWString JDFAutoPosition::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAbsoluteBox(level)) {
			vAtts.push_back(atr_AbsoluteBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlockName(level)) {
			vAtts.push_back(atr_BlockName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarginBottom(level)) {
			vAtts.push_back(atr_MarginBottom);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarginTop(level)) {
			vAtts.push_back(atr_MarginTop);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarginLeft(level)) {
			vAtts.push_back(atr_MarginLeft);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarginRight(level)) {
			vAtts.push_back(atr_MarginRight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrientation(level)) {
			vAtts.push_back(atr_Orientation);
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
* Set attribute AbsoluteBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPosition::SetAbsoluteBox(const JDFRectangle& value){
	SetAttribute(atr_AbsoluteBox,value);
};
/**
* Get string attribute AbsoluteBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPosition::GetAbsoluteBox() const {
	return GetAttribute(atr_AbsoluteBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPosition::ValidAbsoluteBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_AbsoluteBox,AttributeType_rectangle,false);
	};
/**
* Set attribute BlockName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPosition::SetBlockName(const WString& value){
	SetAttribute(atr_BlockName,value);
};
/**
* Get string attribute BlockName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPosition::GetBlockName() const {
	return GetAttribute(atr_BlockName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPosition::ValidBlockName(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlockName,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute MarginBottom
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPosition::SetMarginBottom(double value){
	SetAttribute(atr_MarginBottom,WString::valueOf(value));
};
/**
* Get double attribute MarginBottom
* @return double the vaue of the attribute 
*/
	 double JDFAutoPosition::GetMarginBottom() const {
	return GetRealAttribute(atr_MarginBottom,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPosition::ValidMarginBottom(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarginBottom,AttributeType_double,false);
	};
/**
* Set attribute MarginTop
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPosition::SetMarginTop(double value){
	SetAttribute(atr_MarginTop,WString::valueOf(value));
};
/**
* Get double attribute MarginTop
* @return double the vaue of the attribute 
*/
	 double JDFAutoPosition::GetMarginTop() const {
	return GetRealAttribute(atr_MarginTop,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPosition::ValidMarginTop(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarginTop,AttributeType_double,false);
	};
/**
* Set attribute MarginLeft
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPosition::SetMarginLeft(double value){
	SetAttribute(atr_MarginLeft,WString::valueOf(value));
};
/**
* Get double attribute MarginLeft
* @return double the vaue of the attribute 
*/
	 double JDFAutoPosition::GetMarginLeft() const {
	return GetRealAttribute(atr_MarginLeft,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPosition::ValidMarginLeft(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarginLeft,AttributeType_double,false);
	};
/**
* Set attribute MarginRight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPosition::SetMarginRight(double value){
	SetAttribute(atr_MarginRight,WString::valueOf(value));
};
/**
* Get double attribute MarginRight
* @return double the vaue of the attribute 
*/
	 double JDFAutoPosition::GetMarginRight() const {
	return GetRealAttribute(atr_MarginRight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPosition::ValidMarginRight(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarginRight,AttributeType_double,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoPosition::SetOrientation( EnumOrientation value){
	SetEnumAttribute(atr_Orientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPosition::EnumOrientation JDFAutoPosition:: GetOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_Orientation,OrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPosition::ValidOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Orientation,OrientationString(),false);
	};
/**
* Set attribute RelativeBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPosition::SetRelativeBox(const JDFRectangle& value){
	SetAttribute(atr_RelativeBox,value);
};
/**
* Get string attribute RelativeBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPosition::GetRelativeBox() const {
	return GetAttribute(atr_RelativeBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPosition::ValidRelativeBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeBox,AttributeType_rectangle,false);
	};
}; // end namespace JDF
