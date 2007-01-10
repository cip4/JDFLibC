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

 
#include "jdf/wrapper/AutoJDF/JDFAutoError.h"
#include "jdf/wrapper/JDFErrorData.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoError : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoError& JDFAutoError::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoError: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoError::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoError::ValidNodeNames()const{
	return L"*:,Error";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoError::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ErrorID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoError::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Resend,ReturnCode");
};

/**
 typesafe validator
*/
	vWString JDFAutoError::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidErrorID(level)) {
			vAtts.push_back(atr_ErrorID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResend(level)) {
			vAtts.push_back(atr_Resend);
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
* Set attribute ErrorID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoError::SetErrorID(const WString& value){
	SetAttribute(atr_ErrorID,value);
};
/**
* Get string attribute ErrorID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoError::GetErrorID() const {
	return GetAttribute(atr_ErrorID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoError::ValidErrorID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ErrorID,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute Resend
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoError::SetResend(const WString& value){
	SetAttribute(atr_Resend,value);
};
/**
* Get string attribute Resend
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoError::GetResend() const {
	return GetAttribute(atr_Resend,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoError::ValidResend(EnumValidationLevel level) const {
		return ValidAttribute(atr_Resend,AttributeType_Any,false);
	};
/**
* Set attribute ReturnCode
*@param int value: the value to set the attribute to
*/
	 void JDFAutoError::SetReturnCode(int value){
	SetAttribute(atr_ReturnCode,WString::valueOf(value));
};
/**
* Get integer attribute ReturnCode
* @return int the vaue of the attribute 
*/
	 int JDFAutoError::GetReturnCode() const {
	return GetIntAttribute(atr_ReturnCode,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoError::ValidReturnCode(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReturnCode,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFErrorData JDFAutoError::GetErrorData(int iSkip)const{
	JDFErrorData e=GetElement(elm_ErrorData,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFErrorData JDFAutoError::GetCreateErrorData(int iSkip){
	JDFErrorData e=GetCreateElement(elm_ErrorData,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFErrorData JDFAutoError::AppendErrorData(){
	JDFErrorData e=AppendElement(elm_ErrorData);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoError::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ErrorData);

		for(i=0;i<nElem;i++){
			if (!GetErrorData(i).IsValid(level)) {
				vElem.AppendUnique(elm_ErrorData);
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
	WString JDFAutoError::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ErrorData";
	};
}; // end namespace JDF
