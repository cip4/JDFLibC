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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAction.h"
#include "jdf/wrapper/JDFLoc.h"
#include "jdf/wrapper/JDFPreflightAction.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAction : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAction& JDFAutoAction::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAction: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAction::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAction::ValidNodeNames()const{
	return L"*:,Action";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoAction::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ID,TestRef";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoAction::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Severity");
};

/**
 typesafe validator
*/
	vWString JDFAutoAction::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidSeverity(level)) {
			vAtts.push_back(atr_Severity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTestRef(level)) {
			vAtts.push_back(atr_TestRef);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAction::SeverityString(){
		static const WString enums=WString(L"Unknown,Error,Warning,Information");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAction::SeverityString(EnumSeverity value){
		return SeverityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAction::SetSeverity( EnumSeverity value){
	SetEnumAttribute(atr_Severity,value,SeverityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAction::EnumSeverity JDFAutoAction:: GetSeverity() const {
	return (EnumSeverity) GetEnumAttribute(atr_Severity,SeverityString(),WString::emptyStr,Severity_Error);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAction::ValidSeverity(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Severity,SeverityString(),false);
	};
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAction::SetID(const WString& value){
	SetAttribute(atr_ID,value);
};
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAction::GetID() const {
	return GetAttribute(atr_ID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAction::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,RequiredLevel(level));
	};
/**
* Set attribute TestRef
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAction::SetTestRef(const WString& value){
	SetAttribute(atr_TestRef,value);
};
/**
* Get string attribute TestRef
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAction::GetTestRef() const {
	return GetAttribute(atr_TestRef,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAction::ValidTestRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_TestRef,AttributeType_IDREF,RequiredLevel(level));
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFLoc JDFAutoAction::GetLoc(int iSkip)const{
	JDFLoc e=GetElement(elm_Loc,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoAction::GetCreateLoc(int iSkip){
	JDFLoc e=GetCreateElement(elm_Loc,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoAction::AppendLoc(){
	JDFLoc e=AppendElement(elm_Loc);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightAction JDFAutoAction::GetPreflightAction(int iSkip)const{
	JDFPreflightAction e=GetElement(elm_PreflightAction,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightAction JDFAutoAction::GetCreatePreflightAction(int iSkip){
	JDFPreflightAction e=GetCreateElement(elm_PreflightAction,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightAction JDFAutoAction::AppendPreflightAction(){
	JDFPreflightAction e=AppendElement(elm_PreflightAction);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoAction::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Loc);

		for(i=0;i<nElem;i++){
			if (!GetLoc(i).IsValid(level)) {
				vElem.AppendUnique(elm_Loc);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PreflightAction);

		for(i=0;i<nElem;i++){
			if (!GetPreflightAction(i).IsValid(level)) {
				vElem.AppendUnique(elm_PreflightAction);
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
	WString JDFAutoAction::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Loc,PreflightAction";
	};
}; // end namespace JDF
