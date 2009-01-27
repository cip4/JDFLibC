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

 
#include "jdf/wrapper/AutoJDF/JDFAutoImageShift.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoImageShift : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoImageShift& JDFAutoImageShift::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoImageShift: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoImageShift::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoImageShift::ValidNodeNames()const{
	return L"*:,ImageShift";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoImageShift::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PositionX,PositionY,ShiftBack,ShiftFront");
};

/**
 typesafe validator
*/
	vWString JDFAutoImageShift::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
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
		if(!ValidShiftBack(level)) {
			vAtts.push_back(atr_ShiftBack);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShiftFront(level)) {
			vAtts.push_back(atr_ShiftFront);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageShift::PositionXString(){
		static const WString enums=WString(L"Unknown,Left,Right,Center,Spine,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageShift::PositionXString(EnumPositionX value){
		return PositionXString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageShift::SetPositionX( EnumPositionX value){
	SetEnumAttribute(atr_PositionX,value,PositionXString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageShift::EnumPositionX JDFAutoImageShift:: GetPositionX() const {
	return (EnumPositionX) GetEnumAttribute(atr_PositionX,PositionXString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageShift::ValidPositionX(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PositionX,PositionXString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoImageShift::PositionYString(){
		static const WString enums=WString(L"Unknown,Bottom,Top,Center,Spine,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoImageShift::PositionYString(EnumPositionY value){
		return PositionYString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoImageShift::SetPositionY( EnumPositionY value){
	SetEnumAttribute(atr_PositionY,value,PositionYString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoImageShift::EnumPositionY JDFAutoImageShift:: GetPositionY() const {
	return (EnumPositionY) GetEnumAttribute(atr_PositionY,PositionYString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageShift::ValidPositionY(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PositionY,PositionYString(),false);
	};
/**
* Set attribute ShiftBack
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoImageShift::SetShiftBack(const JDFXYPair& value){
	SetAttribute(atr_ShiftBack,value);
};
/**
* Get string attribute ShiftBack
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoImageShift::GetShiftBack() const {
	return GetAttribute(atr_ShiftBack,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageShift::ValidShiftBack(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShiftBack,AttributeType_XYPair,false);
	};
/**
* Set attribute ShiftFront
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoImageShift::SetShiftFront(const JDFXYPair& value){
	SetAttribute(atr_ShiftFront,value);
};
/**
* Get string attribute ShiftFront
* @return JDFXYPair the vaue of the attribute ; defaults to 0 0
*/
	 JDFXYPair JDFAutoImageShift::GetShiftFront() const {
	return GetAttribute(atr_ShiftFront,WString::emptyStr,L"0 0");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoImageShift::ValidShiftFront(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShiftFront,AttributeType_XYPair,false);
	};
}; // end namespace JDF
