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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreflightConstraint.h"
#include "jdf/wrapper/JDFPreflightValue.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreflightConstraint : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreflightConstraint& JDFAutoPreflightConstraint::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreflightConstraint: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreflightConstraint::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreflightConstraint::ValidNodeNames()const{
	return L"*:,PreflightConstraint";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPreflightConstraint::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AttemptFixupErrors,AttemptFixupWarnings,Constraint,Status");
};

/**
 typesafe validator
*/
	vWString JDFAutoPreflightConstraint::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAttemptFixupErrors(level)) {
			vAtts.push_back(atr_AttemptFixupErrors);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAttemptFixupWarnings(level)) {
			vAtts.push_back(atr_AttemptFixupWarnings);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidConstraint(level)) {
			vAtts.push_back(atr_Constraint);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AttemptFixupErrors
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPreflightConstraint::SetAttemptFixupErrors(bool value){
	SetAttribute(atr_AttemptFixupErrors,WString::valueOf(value));
};
/**
* Get bool attribute AttemptFixupErrors
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPreflightConstraint::GetAttemptFixupErrors() const {return GetBoolAttribute(atr_AttemptFixupErrors,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightConstraint::ValidAttemptFixupErrors(EnumValidationLevel level) const {
		return ValidAttribute(atr_AttemptFixupErrors,AttributeType_boolean,false);
	};
/**
* Set attribute AttemptFixupWarnings
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPreflightConstraint::SetAttemptFixupWarnings(bool value){
	SetAttribute(atr_AttemptFixupWarnings,WString::valueOf(value));
};
/**
* Get bool attribute AttemptFixupWarnings
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPreflightConstraint::GetAttemptFixupWarnings() const {return GetBoolAttribute(atr_AttemptFixupWarnings,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightConstraint::ValidAttemptFixupWarnings(EnumValidationLevel level) const {
		return ValidAttribute(atr_AttemptFixupWarnings,AttributeType_boolean,false);
	};
/**
* Set attribute Constraint
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreflightConstraint::SetConstraint(const WString& value){
	SetAttribute(atr_Constraint,value);
};
/**
* Get string attribute Constraint
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreflightConstraint::GetConstraint() const {
	return GetAttribute(atr_Constraint,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightConstraint::ValidConstraint(EnumValidationLevel level) const {
		return ValidAttribute(atr_Constraint,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreflightConstraint::StatusString(){
		static const WString enums=WString(L"Unknown,Error,Warning,Ignore,IgnoreValue");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreflightConstraint::StatusString(EnumStatus value){
		return StatusString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreflightConstraint::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreflightConstraint::EnumStatus JDFAutoPreflightConstraint:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightConstraint::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPreflightValue JDFAutoPreflightConstraint::GetConstraintValue(int iSkip)const{
	JDFPreflightValue e=GetElement(elm_ConstraintValue,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightValue JDFAutoPreflightConstraint::GetCreateConstraintValue(int iSkip){
	JDFPreflightValue e=GetCreateElement(elm_ConstraintValue,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightValue JDFAutoPreflightConstraint::AppendConstraintValue(){
	JDFPreflightValue e=AppendElement(elm_ConstraintValue);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreflightConstraint::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ConstraintValue);

		for(i=0;i<nElem;i++){
			if (!GetConstraintValue(i).IsValid(level)) {
				vElem.AppendUnique(elm_ConstraintValue);
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
	WString JDFAutoPreflightConstraint::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ConstraintValue";
	};
}; // end namespace JDF
