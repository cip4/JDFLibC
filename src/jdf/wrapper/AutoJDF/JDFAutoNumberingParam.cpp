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

 
#include "jdf/wrapper/AutoJDF/JDFAutoNumberingParam.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoNumberingParam : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoNumberingParam& JDFAutoNumberingParam::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoNumberingParam: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoNumberingParam::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoNumberingParam::ValidNodeNames()const{
	return L"*:,NumberingParam";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoNumberingParam::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",StartValue,XPosition,YPosition,Orientation,Step");
};

/**
 typesafe validator
*/
	vWString JDFAutoNumberingParam::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidStartValue(level)) {
			vAtts.push_back(atr_StartValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidXPosition(level)) {
			vAtts.push_back(atr_XPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidYPosition(level)) {
			vAtts.push_back(atr_YPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrientation(level)) {
			vAtts.push_back(atr_Orientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStep(level)) {
			vAtts.push_back(atr_Step);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute StartValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNumberingParam::SetStartValue(const WString& value){
	SetAttribute(atr_StartValue,value);
};
/**
* Get string attribute StartValue
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNumberingParam::GetStartValue() const {
	return GetAttribute(atr_StartValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNumberingParam::ValidStartValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartValue,AttributeType_string,false);
	};
/**
* Set attribute XPosition
*@param double value: the value to set the attribute to
*/
	 void JDFAutoNumberingParam::SetXPosition(double value){
	SetAttribute(atr_XPosition,WString::valueOf(value));
};
/**
* Get double attribute XPosition
* @return double the vaue of the attribute 
*/
	 double JDFAutoNumberingParam::GetXPosition() const {
	return GetRealAttribute(atr_XPosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNumberingParam::ValidXPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_XPosition,AttributeType_double,false);
	};
/**
* Set attribute YPosition
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoNumberingParam::SetYPosition(const JDFNumberList& value){
	SetAttribute(atr_YPosition,value.GetString());
};
/**
* Get string attribute YPosition
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoNumberingParam::GetYPosition() const {
	return GetAttribute(atr_YPosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNumberingParam::ValidYPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_YPosition,AttributeType_NumberList,false);
	};
/**
* Set attribute Orientation
*@param double value: the value to set the attribute to
*/
	 void JDFAutoNumberingParam::SetOrientation(double value){
	SetAttribute(atr_Orientation,WString::valueOf(value));
};
/**
* Get double attribute Orientation
* @return double the vaue of the attribute 
*/
	 double JDFAutoNumberingParam::GetOrientation() const {
	return GetRealAttribute(atr_Orientation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNumberingParam::ValidOrientation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Orientation,AttributeType_double,false);
	};
/**
* Set attribute Step
*@param int value: the value to set the attribute to
*/
	 void JDFAutoNumberingParam::SetStep(int value){
	SetAttribute(atr_Step,WString::valueOf(value));
};
/**
* Get integer attribute Step
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoNumberingParam::GetStep() const {
	return GetIntAttribute(atr_Step,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNumberingParam::ValidStep(EnumValidationLevel level) const {
		return ValidAttribute(atr_Step,AttributeType_integer,false);
	};
}; // end namespace JDF
