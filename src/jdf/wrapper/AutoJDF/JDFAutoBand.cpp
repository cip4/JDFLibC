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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBand.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBand : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBand& JDFAutoBand::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBand: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBand::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBand::ValidNodeNames()const{
	return L"*:,Band";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBand::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Data,Height,Mask,WasMarked,Width");
};

/**
 typesafe validator
*/
	vWString JDFAutoBand::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidData(level)) {
			vAtts.push_back(atr_Data);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHeight(level)) {
			vAtts.push_back(atr_Height);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMask(level)) {
			vAtts.push_back(atr_Mask);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWasMarked(level)) {
			vAtts.push_back(atr_WasMarked);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWidth(level)) {
			vAtts.push_back(atr_Width);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Data
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBand::SetData(const WString& value){
	SetAttribute(atr_Data,value);
};
/**
* Get string attribute Data
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBand::GetData() const {
	return GetAttribute(atr_Data,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBand::ValidData(EnumValidationLevel level) const {
		return ValidAttribute(atr_Data,AttributeType_URL,false);
	};
/**
* Set attribute Height
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBand::SetHeight(int value){
	SetAttribute(atr_Height,WString::valueOf(value));
};
/**
* Get integer attribute Height
* @return int the vaue of the attribute 
*/
	 int JDFAutoBand::GetHeight() const {
	return GetIntAttribute(atr_Height,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBand::ValidHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_Height,AttributeType_integer,false);
	};
/**
* Set attribute Mask
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBand::SetMask(const WString& value){
	SetAttribute(atr_Mask,value);
};
/**
* Get string attribute Mask
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBand::GetMask() const {
	return GetAttribute(atr_Mask,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBand::ValidMask(EnumValidationLevel level) const {
		return ValidAttribute(atr_Mask,AttributeType_URL,false);
	};
/**
* Set attribute WasMarked
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoBand::SetWasMarked(bool value){
	SetAttribute(atr_WasMarked,WString::valueOf(value));
};
/**
* Get bool attribute WasMarked
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoBand::GetWasMarked() const {return GetBoolAttribute(atr_WasMarked,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBand::ValidWasMarked(EnumValidationLevel level) const {
		return ValidAttribute(atr_WasMarked,AttributeType_boolean,false);
	};
/**
* Set attribute Width
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBand::SetWidth(int value){
	SetAttribute(atr_Width,WString::valueOf(value));
};
/**
* Get integer attribute Width
* @return int the vaue of the attribute 
*/
	 int JDFAutoBand::GetWidth() const {
	return GetIntAttribute(atr_Width,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBand::ValidWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_Width,AttributeType_integer,false);
	};
}; // end namespace JDF
