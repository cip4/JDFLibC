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

 
#include "jdf/wrapper/AutoJDF/JDFAutoReturnQueueEntryParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoReturnQueueEntryParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoReturnQueueEntryParams& JDFAutoReturnQueueEntryParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoReturnQueueEntryParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoReturnQueueEntryParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoReturnQueueEntryParams::ValidNodeNames()const{
	return L"*:,ReturnQueueEntryParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoReturnQueueEntryParams::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",QueueEntryID,URL";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoReturnQueueEntryParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Aborted,Completed,Priority");
};

/**
 typesafe validator
*/
	vWString JDFAutoReturnQueueEntryParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAborted(level)) {
			vAtts.push_back(atr_Aborted);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompleted(level)) {
			vAtts.push_back(atr_Completed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPriority(level)) {
			vAtts.push_back(atr_Priority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURL(level)) {
			vAtts.push_back(atr_URL);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Aborted
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoReturnQueueEntryParams::SetAborted(const vWString& value){
	SetAttribute(atr_Aborted,value);
};
/**
* Get string attribute Aborted
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoReturnQueueEntryParams::GetAborted() const {
	return GetAttribute(atr_Aborted,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoReturnQueueEntryParams::ValidAborted(EnumValidationLevel level) const {
		return ValidAttribute(atr_Aborted,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Completed
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoReturnQueueEntryParams::SetCompleted(const vWString& value){
	SetAttribute(atr_Completed,value);
};
/**
* Get string attribute Completed
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoReturnQueueEntryParams::GetCompleted() const {
	return GetAttribute(atr_Completed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoReturnQueueEntryParams::ValidCompleted(EnumValidationLevel level) const {
		return ValidAttribute(atr_Completed,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoReturnQueueEntryParams::SetPriority(int value){
	SetAttribute(atr_Priority,WString::valueOf(value));
};
/**
* Get integer attribute Priority
* @return int the vaue of the attribute 
*/
	 int JDFAutoReturnQueueEntryParams::GetPriority() const {
	return GetIntAttribute(atr_Priority,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoReturnQueueEntryParams::ValidPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_Priority,AttributeType_integer,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoReturnQueueEntryParams::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoReturnQueueEntryParams::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoReturnQueueEntryParams::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,RequiredLevel(level));
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoReturnQueueEntryParams::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoReturnQueueEntryParams::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoReturnQueueEntryParams::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,RequiredLevel(level));
	};
}; // end namespace JDF
