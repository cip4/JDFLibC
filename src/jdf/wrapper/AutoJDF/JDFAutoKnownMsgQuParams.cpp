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

 
#include "jdf/wrapper/AutoJDF/JDFAutoKnownMsgQuParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoKnownMsgQuParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoKnownMsgQuParams& JDFAutoKnownMsgQuParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoKnownMsgQuParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoKnownMsgQuParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoKnownMsgQuParams::ValidNodeNames()const{
	return L"*:,KnownMsgQuParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoKnownMsgQuParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Exact,ListCommands,ListQueries,ListRegistrations,ListSignals,Persistent");
};

/**
 typesafe validator
*/
	vWString JDFAutoKnownMsgQuParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidExact(level)) {
			vAtts.push_back(atr_Exact);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidListCommands(level)) {
			vAtts.push_back(atr_ListCommands);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidListQueries(level)) {
			vAtts.push_back(atr_ListQueries);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidListRegistrations(level)) {
			vAtts.push_back(atr_ListRegistrations);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidListSignals(level)) {
			vAtts.push_back(atr_ListSignals);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPersistent(level)) {
			vAtts.push_back(atr_Persistent);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Exact
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoKnownMsgQuParams::SetExact(bool value){
	SetAttribute(atr_Exact,WString::valueOf(value));
};
/**
* Get bool attribute Exact
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoKnownMsgQuParams::GetExact() const {return GetBoolAttribute(atr_Exact,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoKnownMsgQuParams::ValidExact(EnumValidationLevel level) const {
		return ValidAttribute(atr_Exact,AttributeType_boolean,false);
	};
/**
* Set attribute ListCommands
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoKnownMsgQuParams::SetListCommands(bool value){
	SetAttribute(atr_ListCommands,WString::valueOf(value));
};
/**
* Get bool attribute ListCommands
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoKnownMsgQuParams::GetListCommands() const {return GetBoolAttribute(atr_ListCommands,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoKnownMsgQuParams::ValidListCommands(EnumValidationLevel level) const {
		return ValidAttribute(atr_ListCommands,AttributeType_boolean,false);
	};
/**
* Set attribute ListQueries
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoKnownMsgQuParams::SetListQueries(bool value){
	SetAttribute(atr_ListQueries,WString::valueOf(value));
};
/**
* Get bool attribute ListQueries
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoKnownMsgQuParams::GetListQueries() const {return GetBoolAttribute(atr_ListQueries,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoKnownMsgQuParams::ValidListQueries(EnumValidationLevel level) const {
		return ValidAttribute(atr_ListQueries,AttributeType_boolean,false);
	};
/**
* Set attribute ListRegistrations
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoKnownMsgQuParams::SetListRegistrations(bool value){
	SetAttribute(atr_ListRegistrations,WString::valueOf(value));
};
/**
* Get bool attribute ListRegistrations
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoKnownMsgQuParams::GetListRegistrations() const {return GetBoolAttribute(atr_ListRegistrations,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoKnownMsgQuParams::ValidListRegistrations(EnumValidationLevel level) const {
		return ValidAttribute(atr_ListRegistrations,AttributeType_boolean,false);
	};
/**
* Set attribute ListSignals
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoKnownMsgQuParams::SetListSignals(bool value){
	SetAttribute(atr_ListSignals,WString::valueOf(value));
};
/**
* Get bool attribute ListSignals
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoKnownMsgQuParams::GetListSignals() const {return GetBoolAttribute(atr_ListSignals,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoKnownMsgQuParams::ValidListSignals(EnumValidationLevel level) const {
		return ValidAttribute(atr_ListSignals,AttributeType_boolean,false);
	};
/**
* Set attribute Persistent
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoKnownMsgQuParams::SetPersistent(bool value){
	SetAttribute(atr_Persistent,WString::valueOf(value));
};
/**
* Get bool attribute Persistent
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoKnownMsgQuParams::GetPersistent() const {return GetBoolAttribute(atr_Persistent,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoKnownMsgQuParams::ValidPersistent(EnumValidationLevel level) const {
		return ValidAttribute(atr_Persistent,AttributeType_boolean,false);
	};
}; // end namespace JDF
