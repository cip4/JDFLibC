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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCommand.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCommand : public JDFMessage

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCommand& JDFAutoCommand::operator=(const KElement& other){
	KElement::operator=(other);
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCommand::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCommand::ValidNodeNames()const{
	return L"*:,Command";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCommand::OptionalAttributes()const{
		return JDFMessage::OptionalAttributes()+WString(L",AcknowledgeFormat,AcknowledgeTemplate,AcknowledgeURL,AcknowledgeType");
};

/**
 typesafe validator
*/
	vWString JDFAutoCommand::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFMessage::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAcknowledgeFormat(level)) {
			vAtts.push_back(atr_AcknowledgeFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAcknowledgeTemplate(level)) {
			vAtts.push_back(atr_AcknowledgeTemplate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAcknowledgeURL(level)) {
			vAtts.push_back(atr_AcknowledgeURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAcknowledgeType(level)) {
			vAtts.push_back(atr_AcknowledgeType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AcknowledgeFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCommand::SetAcknowledgeFormat(const WString& value){
	SetAttribute(atr_AcknowledgeFormat,value);
};
/**
* Get string attribute AcknowledgeFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCommand::GetAcknowledgeFormat() const {
	return GetAttribute(atr_AcknowledgeFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCommand::ValidAcknowledgeFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_AcknowledgeFormat,AttributeType_string,false);
	};
/**
* Set attribute AcknowledgeTemplate
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCommand::SetAcknowledgeTemplate(const WString& value){
	SetAttribute(atr_AcknowledgeTemplate,value);
};
/**
* Get string attribute AcknowledgeTemplate
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCommand::GetAcknowledgeTemplate() const {
	return GetAttribute(atr_AcknowledgeTemplate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCommand::ValidAcknowledgeTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_AcknowledgeTemplate,AttributeType_string,false);
	};
/**
* Set attribute AcknowledgeURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCommand::SetAcknowledgeURL(const WString& value){
	SetAttribute(atr_AcknowledgeURL,value);
};
/**
* Get string attribute AcknowledgeURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCommand::GetAcknowledgeURL() const {
	return GetAttribute(atr_AcknowledgeURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCommand::ValidAcknowledgeURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_AcknowledgeURL,AttributeType_URL,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCommand::AcknowledgeTypeString(){
		static const WString enums=WString(L"Unknown,Received,Applied,Completed");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCommand::AcknowledgeTypeString(EnumAcknowledgeType value){
		return AcknowledgeTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoCommand::AddAcknowledgeType( EnumAcknowledgeType value){
	return AddEnumerationsAttribute(atr_AcknowledgeType,value,AcknowledgeTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoCommand::RemoveAcknowledgeType( EnumAcknowledgeType value){
	return RemoveEnumerationsAttribute(atr_AcknowledgeType,value,AcknowledgeTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoCommand::GetAcknowledgeType() const {
	return GetEnumerationsAttribute(atr_AcknowledgeType,AcknowledgeTypeString(),WString::emptyStr,(unsigned int)AcknowledgeType_Completed);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoCommand::SetAcknowledgeType( EnumAcknowledgeType value){
	SetEnumAttribute(atr_AcknowledgeType,value,AcknowledgeTypeString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoCommand::SetAcknowledgeType( const vint& value){
	SetEnumerationsAttribute(atr_AcknowledgeType,value,AcknowledgeTypeString());
};
/**
* Typesafe attribute validation of AcknowledgeType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCommand::ValidAcknowledgeType(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_AcknowledgeType,AcknowledgeTypeString(),false);
	};
}; // end namespace JDF
