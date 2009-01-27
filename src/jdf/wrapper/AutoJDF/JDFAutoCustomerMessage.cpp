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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCustomerMessage.h"
#include "jdf/wrapper/JDFComChannel.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCustomerMessage : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCustomerMessage& JDFAutoCustomerMessage::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCustomerMessage: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCustomerMessage::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCustomerMessage::ValidNodeNames()const{
	return L"*:,CustomerMessage";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoCustomerMessage::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",MessageEvents";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCustomerMessage::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Language,ShowList");
};

/**
 typesafe validator
*/
	vWString JDFAutoCustomerMessage::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidLanguage(level)) {
			vAtts.push_back(atr_Language);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMessageEvents(level)) {
			vAtts.push_back(atr_MessageEvents);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidShowList(level)) {
			vAtts.push_back(atr_ShowList);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Language
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCustomerMessage::SetLanguage(const WString& value){
	SetAttribute(atr_Language,value);
};
/**
* Get string attribute Language
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCustomerMessage::GetLanguage() const {
	return GetAttribute(atr_Language,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCustomerMessage::ValidLanguage(EnumValidationLevel level) const {
		return ValidAttribute(atr_Language,AttributeType_language,false);
	};
/**
* Set attribute MessageEvents
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoCustomerMessage::SetMessageEvents(const vWString& value){
	SetAttribute(atr_MessageEvents,value);
};
/**
* Get string attribute MessageEvents
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoCustomerMessage::GetMessageEvents() const {
	return GetAttribute(atr_MessageEvents,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCustomerMessage::ValidMessageEvents(EnumValidationLevel level) const {
		return ValidAttribute(atr_MessageEvents,AttributeType_NMTOKENS,RequiredLevel(level));
	};
/**
* Set attribute ShowList
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoCustomerMessage::SetShowList(const vWString& value){
	SetAttribute(atr_ShowList,value);
};
/**
* Get string attribute ShowList
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoCustomerMessage::GetShowList() const {
	return GetAttribute(atr_ShowList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCustomerMessage::ValidShowList(EnumValidationLevel level) const {
		return ValidAttribute(atr_ShowList,AttributeType_NMTOKENS,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFComChannel JDFAutoCustomerMessage::GetComChannel(int iSkip)const{
	JDFComChannel e=GetElement(elm_ComChannel,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComChannel JDFAutoCustomerMessage::GetCreateComChannel(int iSkip){
	JDFComChannel e=GetCreateElement(elm_ComChannel,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComChannel JDFAutoCustomerMessage::AppendComChannel(){
	JDFComChannel e=AppendElement(elm_ComChannel);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCustomerMessage::RefComChannel(JDFComChannel& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCustomerMessage::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ComChannel);

		for(i=0;i<nElem;i++){
			if (!GetComChannel(i).IsValid(level)) {
				vElem.AppendUnique(elm_ComChannel);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoCustomerMessage::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ComChannel";
	};
}; // end namespace JDF
