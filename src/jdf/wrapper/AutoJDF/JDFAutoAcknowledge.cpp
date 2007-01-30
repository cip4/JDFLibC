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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAcknowledge.h"
#include "jdf/wrapper/JDFNotification.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAcknowledge : public JDFMessage

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAcknowledge& JDFAutoAcknowledge::operator=(const KElement& other){
	KElement::operator=(other);
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAcknowledge::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAcknowledge::ValidNodeNames()const{
	return L"*:,Acknowledge";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoAcknowledge::RequiredAttributes()const{
		return JDFMessage::RequiredAttributes()+L",refID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoAcknowledge::OptionalAttributes()const{
		return JDFMessage::OptionalAttributes()+WString(L",AcknowledgeType,ReturnCode");
};

/**
 typesafe validator
*/
	vWString JDFAutoAcknowledge::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFMessage::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidrefID(level)) {
			vAtts.push_back(atr_refID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAcknowledgeType(level)) {
			vAtts.push_back(atr_AcknowledgeType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReturnCode(level)) {
			vAtts.push_back(atr_ReturnCode);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute refID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAcknowledge::SetrefID(const WString& value){
	SetAttribute(atr_refID,value);
};
/**
* Get string attribute refID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAcknowledge::GetrefID() const {
	return GetAttribute(atr_refID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAcknowledge::ValidrefID(EnumValidationLevel level) const {
		return ValidAttribute(atr_refID,AttributeType_NMTOKEN,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAcknowledge::AcknowledgeTypeString(){
		static const WString enums=WString(L"Unknown,Received,Applied,Completed");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAcknowledge::AcknowledgeTypeString(EnumAcknowledgeType value){
		return AcknowledgeTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoAcknowledge::AddAcknowledgeType( EnumAcknowledgeType value){
	return AddEnumerationsAttribute(atr_AcknowledgeType,value,AcknowledgeTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoAcknowledge::RemoveAcknowledgeType( EnumAcknowledgeType value){
	return RemoveEnumerationsAttribute(atr_AcknowledgeType,value,AcknowledgeTypeString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoAcknowledge::GetAcknowledgeType() const {
	return GetEnumerationsAttribute(atr_AcknowledgeType,AcknowledgeTypeString(),WString::emptyStr,(unsigned int)AcknowledgeType_Completed);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoAcknowledge::SetAcknowledgeType( EnumAcknowledgeType value){
	SetEnumAttribute(atr_AcknowledgeType,value,AcknowledgeTypeString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoAcknowledge::SetAcknowledgeType( const vint& value){
	SetEnumerationsAttribute(atr_AcknowledgeType,value,AcknowledgeTypeString());
};
/**
* Typesafe attribute validation of AcknowledgeType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAcknowledge::ValidAcknowledgeType(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_AcknowledgeType,AcknowledgeTypeString(),false);
	};
/**
* Set attribute ReturnCode
*@param int value: the value to set the attribute to
*/
	 void JDFAutoAcknowledge::SetReturnCode(int value){
	SetAttribute(atr_ReturnCode,WString::valueOf(value));
};
/**
* Get integer attribute ReturnCode
* @return int the vaue of the attribute ; defaults to 0
*/
	 int JDFAutoAcknowledge::GetReturnCode() const {
	return GetIntAttribute(atr_ReturnCode,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAcknowledge::ValidReturnCode(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReturnCode,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFNotification JDFAutoAcknowledge::GetNotification(int iSkip)const{
	JDFNotification e=GetElement(elm_Notification,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNotification JDFAutoAcknowledge::GetCreateNotification(int iSkip){
	JDFNotification e=GetCreateElement(elm_Notification,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNotification JDFAutoAcknowledge::AppendNotification(){
	JDFNotification e=AppendElement(elm_Notification);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoAcknowledge::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFMessage::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Notification);

		for(i=0;i<nElem;i++){
			if (!GetNotification(i).IsValid(level)) {
				vElem.AppendUnique(elm_Notification);
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
	WString JDFAutoAcknowledge::OptionalElements()const{
		return JDFMessage::OptionalElements()+L",Notification";
	};
}; // end namespace JDF
