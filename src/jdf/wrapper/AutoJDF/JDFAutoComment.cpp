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

 
#include "jdf/wrapper/AutoJDF/JDFAutoComment.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoComment : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoComment& JDFAutoComment::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoComment: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoComment::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoComment::ValidNodeNames()const{
	return L"*:,Comment";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoComment::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AgentName,AgentVersion,Attribute,Author,Box,ID,Language,Name,Path,TimeStamp");
};

/**
 typesafe validator
*/
	vWString JDFAutoComment::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAgentName(level)) {
			vAtts.push_back(atr_AgentName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAgentVersion(level)) {
			vAtts.push_back(atr_AgentVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAttributeAttribute(level)) {
			vAtts.push_back(atr_Attribute);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAuthor(level)) {
			vAtts.push_back(atr_Author);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBox(level)) {
			vAtts.push_back(atr_Box);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLanguage(level)) {
			vAtts.push_back(atr_Language);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPath(level)) {
			vAtts.push_back(atr_Path);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTimeStamp(level)) {
			vAtts.push_back(atr_TimeStamp);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AgentName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComment::SetAgentName(const WString& value){
	SetAttribute(atr_AgentName,value);
};
/**
* Get string attribute AgentName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComment::GetAgentName() const {
	return GetAttribute(atr_AgentName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidAgentName(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentName,AttributeType_string,false);
	};
/**
* Set attribute AgentVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComment::SetAgentVersion(const WString& value){
	SetAttribute(atr_AgentVersion,value);
};
/**
* Get string attribute AgentVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComment::GetAgentVersion() const {
	return GetAttribute(atr_AgentVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidAgentVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_AgentVersion,AttributeType_string,false);
	};
/**
* Set attribute Attribute
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComment::SetAttributeAttribute(const WString& value){
	SetAttribute(atr_Attribute,value);
};
/**
* Get string attribute Attribute
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComment::GetAttributeAttribute() const {
	return GetAttribute(atr_Attribute,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidAttributeAttribute(EnumValidationLevel level) const {
		return ValidAttribute(atr_Attribute,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Author
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComment::SetAuthor(const WString& value){
	SetAttribute(atr_Author,value);
};
/**
* Get string attribute Author
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComment::GetAuthor() const {
	return GetAttribute(atr_Author,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidAuthor(EnumValidationLevel level) const {
		return ValidAttribute(atr_Author,AttributeType_string,false);
	};
/**
* Set attribute Box
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoComment::SetBox(const JDFRectangle& value){
	SetAttribute(atr_Box,value);
};
/**
* Get string attribute Box
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoComment::GetBox() const {
	return GetAttribute(atr_Box,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_Box,AttributeType_rectangle,false);
	};
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComment::SetID(const WString& value){
	SetAttribute(atr_ID,value);
};
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComment::GetID() const {
	return GetAttribute(atr_ID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,false);
	};
/**
* Set attribute Language
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComment::SetLanguage(const WString& value){
	SetAttribute(atr_Language,value);
};
/**
* Get string attribute Language
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComment::GetLanguage() const {
	return GetAttribute(atr_Language,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidLanguage(EnumValidationLevel level) const {
		return ValidAttribute(atr_Language,AttributeType_language,false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComment::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute ; defaults to Description
*/
	 WString JDFAutoComment::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr,L"Description");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Path
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoComment::SetPath(const WString& value){
	SetAttribute(atr_Path,value);
};
/**
* Get string attribute Path
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoComment::GetPath() const {
	return GetAttribute(atr_Path,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_Path,AttributeType_PDFPath,false);
	};
/**
* Set attribute TimeStamp
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoComment::SetTimeStamp(JDFDate value){
	SetAttribute(atr_TimeStamp,value.DateTimeISO());
};
/**
* Get string attribute TimeStamp
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoComment::GetTimeStamp() const {
	return GetAttribute(atr_TimeStamp,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoComment::ValidTimeStamp(EnumValidationLevel level) const {
		return ValidAttribute(atr_TimeStamp,AttributeType_dateTime,false);
	};
}; // end namespace JDF
