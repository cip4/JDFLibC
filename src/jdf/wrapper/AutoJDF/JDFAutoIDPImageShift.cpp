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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIDPImageShift.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDPImageShift : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIDPImageShift& JDFAutoIDPImageShift::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIDPImageShift: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIDPImageShift::ValidNodeNames()const{
	return L"*:,IDPImageShift";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIDPImageShift::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PositionX,PositionY,ShiftX,ShiftY,ShiftXSide1,ShiftXSide2,ShiftYSide1,ShiftYSide2");
};

/**
 typesafe validator
*/
	vWString JDFAutoIDPImageShift::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPositionX(level)) {
			vAtts.push_back(atr_PositionX);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPositionY(level)) {
			vAtts.push_back(atr_PositionY);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShiftX(level)) {
			vAtts.push_back(atr_ShiftX);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShiftY(level)) {
			vAtts.push_back(atr_ShiftY);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShiftXSide1(level)) {
			vAtts.push_back(atr_ShiftXSide1);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShiftXSide2(level)) {
			vAtts.push_back(atr_ShiftXSide2);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShiftYSide1(level)) {
			vAtts.push_back(atr_ShiftYSide1);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShiftYSide2(level)) {
			vAtts.push_back(atr_ShiftYSide2);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPImageShift::PositionXString(){
		static const WString enums=WString(L"Unknown,Center,Left,None,Right");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPImageShift::PositionXString(EnumPositionX value){
		return PositionXString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPImageShift::SetPositionX( EnumPositionX value){
	SetEnumAttribute(atr_PositionX,value,PositionXString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPImageShift::EnumPositionX JDFAutoIDPImageShift:: GetPositionX() const {
	return (EnumPositionX) GetEnumAttribute(atr_PositionX,PositionXString(),WString::emptyStr,PositionX_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::ValidPositionX(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PositionX,PositionXString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPImageShift::PositionYString(){
		static const WString enums=WString(L"Unknown,Bottom,Center,None,Top");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPImageShift::PositionYString(EnumPositionY value){
		return PositionYString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPImageShift::SetPositionY( EnumPositionY value){
	SetEnumAttribute(atr_PositionY,value,PositionYString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPImageShift::EnumPositionY JDFAutoIDPImageShift:: GetPositionY() const {
	return (EnumPositionY) GetEnumAttribute(atr_PositionY,PositionYString(),WString::emptyStr,PositionY_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::ValidPositionY(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PositionY,PositionYString(),false);
	};
/**
* Set attribute ShiftX
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIDPImageShift::SetShiftX(int value){
	SetAttribute(atr_ShiftX,WString::valueOf(value));
};
/**
* Get integer attribute ShiftX
* @return int the vaue of the attribute 
*/
	 int JDFAutoIDPImageShift::GetShiftX() const {
	return GetIntAttribute(atr_ShiftX,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::ValidShiftX(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShiftX,AttributeType_integer,false);
	};
/**
* Set attribute ShiftY
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIDPImageShift::SetShiftY(int value){
	SetAttribute(atr_ShiftY,WString::valueOf(value));
};
/**
* Get integer attribute ShiftY
* @return int the vaue of the attribute 
*/
	 int JDFAutoIDPImageShift::GetShiftY() const {
	return GetIntAttribute(atr_ShiftY,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::ValidShiftY(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShiftY,AttributeType_integer,false);
	};
/**
* Set attribute ShiftXSide1
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIDPImageShift::SetShiftXSide1(int value){
	SetAttribute(atr_ShiftXSide1,WString::valueOf(value));
};
/**
* Get integer attribute ShiftXSide1
* @return int the vaue of the attribute 
*/
	 int JDFAutoIDPImageShift::GetShiftXSide1() const {
	return GetIntAttribute(atr_ShiftXSide1,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::ValidShiftXSide1(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShiftXSide1,AttributeType_integer,false);
	};
/**
* Set attribute ShiftXSide2
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIDPImageShift::SetShiftXSide2(int value){
	SetAttribute(atr_ShiftXSide2,WString::valueOf(value));
};
/**
* Get integer attribute ShiftXSide2
* @return int the vaue of the attribute 
*/
	 int JDFAutoIDPImageShift::GetShiftXSide2() const {
	return GetIntAttribute(atr_ShiftXSide2,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::ValidShiftXSide2(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShiftXSide2,AttributeType_integer,false);
	};
/**
* Set attribute ShiftYSide1
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIDPImageShift::SetShiftYSide1(int value){
	SetAttribute(atr_ShiftYSide1,WString::valueOf(value));
};
/**
* Get integer attribute ShiftYSide1
* @return int the vaue of the attribute 
*/
	 int JDFAutoIDPImageShift::GetShiftYSide1() const {
	return GetIntAttribute(atr_ShiftYSide1,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::ValidShiftYSide1(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShiftYSide1,AttributeType_integer,false);
	};
/**
* Set attribute ShiftYSide2
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIDPImageShift::SetShiftYSide2(int value){
	SetAttribute(atr_ShiftYSide2,WString::valueOf(value));
};
/**
* Get integer attribute ShiftYSide2
* @return int the vaue of the attribute 
*/
	 int JDFAutoIDPImageShift::GetShiftYSide2() const {
	return GetIntAttribute(atr_ShiftYSide2,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPImageShift::ValidShiftYSide2(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShiftYSide2,AttributeType_integer,false);
	};
}; // end namespace JDF
