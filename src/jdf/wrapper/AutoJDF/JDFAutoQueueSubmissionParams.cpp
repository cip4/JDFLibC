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

 
#include "jdf/wrapper/AutoJDF/JDFAutoQueueSubmissionParams.h"
#include "jdf/wrapper/JDFDisposition.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoQueueSubmissionParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoQueueSubmissionParams& JDFAutoQueueSubmissionParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoQueueSubmissionParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoQueueSubmissionParams::ValidNodeNames()const{
	return L"*:,QueueSubmissionParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoQueueSubmissionParams::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",URL";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoQueueSubmissionParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",GangName,GangPolicy,Hold,NextQueueEntryID,PrevQueueEntryID,Priority,refID,ReturnJMF,ReturnURL,WatchURL");
};

/**
 typesafe validator
*/
	vWString JDFAutoQueueSubmissionParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidGangName(level)) {
			vAtts.push_back(atr_GangName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidGangPolicy(level)) {
			vAtts.push_back(atr_GangPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHold(level)) {
			vAtts.push_back(atr_Hold);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNextQueueEntryID(level)) {
			vAtts.push_back(atr_NextQueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrevQueueEntryID(level)) {
			vAtts.push_back(atr_PrevQueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPriority(level)) {
			vAtts.push_back(atr_Priority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidrefID(level)) {
			vAtts.push_back(atr_refID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReturnJMF(level)) {
			vAtts.push_back(atr_ReturnJMF);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReturnURL(level)) {
			vAtts.push_back(atr_ReturnURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURL(level)) {
			vAtts.push_back(atr_URL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWatchURL(level)) {
			vAtts.push_back(atr_WatchURL);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute GangName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetGangName(const WString& value){
	SetAttribute(atr_GangName,value);
};
/**
* Get string attribute GangName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueSubmissionParams::GetGangName() const {
	return GetAttribute(atr_GangName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidGangName(EnumValidationLevel level) const {
		return ValidAttribute(atr_GangName,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoQueueSubmissionParams::GangPolicyString(){
		static const WString enums=WString(L"Unknown,Gang,GangAndForce,NoGang");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoQueueSubmissionParams::GangPolicyString(EnumGangPolicy value){
		return GangPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoQueueSubmissionParams::SetGangPolicy( EnumGangPolicy value){
	SetEnumAttribute(atr_GangPolicy,value,GangPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoQueueSubmissionParams::EnumGangPolicy JDFAutoQueueSubmissionParams:: GetGangPolicy() const {
	return (EnumGangPolicy) GetEnumAttribute(atr_GangPolicy,GangPolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidGangPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_GangPolicy,GangPolicyString(),false);
	};
/**
* Set attribute Hold
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetHold(bool value){
	SetAttribute(atr_Hold,WString::valueOf(value));
};
/**
* Get bool attribute Hold
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoQueueSubmissionParams::GetHold() const {return GetBoolAttribute(atr_Hold,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidHold(EnumValidationLevel level) const {
		return ValidAttribute(atr_Hold,AttributeType_boolean,false);
	};
/**
* Set attribute NextQueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetNextQueueEntryID(const WString& value){
	SetAttribute(atr_NextQueueEntryID,value);
};
/**
* Get string attribute NextQueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueSubmissionParams::GetNextQueueEntryID() const {
	return GetAttribute(atr_NextQueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidNextQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_NextQueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute PrevQueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetPrevQueueEntryID(const WString& value){
	SetAttribute(atr_PrevQueueEntryID,value);
};
/**
* Get string attribute PrevQueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueSubmissionParams::GetPrevQueueEntryID() const {
	return GetAttribute(atr_PrevQueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidPrevQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrevQueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetPriority(int value){
	SetAttribute(atr_Priority,WString::valueOf(value));
};
/**
* Get integer attribute Priority
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoQueueSubmissionParams::GetPriority() const {
	return GetIntAttribute(atr_Priority,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_Priority,AttributeType_integer,false);
	};
/**
* Set attribute refID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetrefID(const WString& value){
	SetAttribute(atr_refID,value);
};
/**
* Get string attribute refID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueSubmissionParams::GetrefID() const {
	return GetAttribute(atr_refID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidrefID(EnumValidationLevel level) const {
		return ValidAttribute(atr_refID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ReturnJMF
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetReturnJMF(const WString& value){
	SetAttribute(atr_ReturnJMF,value);
};
/**
* Get string attribute ReturnJMF
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueSubmissionParams::GetReturnJMF() const {
	return GetAttribute(atr_ReturnJMF,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidReturnJMF(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReturnJMF,AttributeType_URL,false);
	};
/**
* Set attribute ReturnURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetReturnURL(const WString& value){
	SetAttribute(atr_ReturnURL,value);
};
/**
* Get string attribute ReturnURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueSubmissionParams::GetReturnURL() const {
	return GetAttribute(atr_ReturnURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidReturnURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReturnURL,AttributeType_URL,false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueSubmissionParams::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,RequiredLevel(level));
	};
/**
* Set attribute WatchURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQueueSubmissionParams::SetWatchURL(const WString& value){
	SetAttribute(atr_WatchURL,value);
};
/**
* Get string attribute WatchURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQueueSubmissionParams::GetWatchURL() const {
	return GetAttribute(atr_WatchURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQueueSubmissionParams::ValidWatchURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_WatchURL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDisposition JDFAutoQueueSubmissionParams::GetDispositionElem()const{
	JDFDisposition e=GetElement(elm_Disposition);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoQueueSubmissionParams::GetCreateDispositionElem(){
	JDFDisposition e=GetCreateElement(elm_Disposition);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoQueueSubmissionParams::AppendDispositionElem(){
	JDFDisposition e=AppendElementN(elm_Disposition,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoQueueSubmissionParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Disposition);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Disposition);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDispositionElem().IsValid(level)) {
				vElem.AppendUnique(elm_Disposition);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoQueueSubmissionParams::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Disposition";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoQueueSubmissionParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Disposition";
	};
}; // end namespace JDF
