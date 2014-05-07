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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCreated.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCreated : public JDFAudit

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCreated& JDFAutoCreated::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCreated: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCreated::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCreated::ValidNodeNames()const{
	return L"*:,Created";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCreated::OptionalAttributes()const{
		return JDFAudit::OptionalAttributes()+WString(L",ref,TemplateID,TemplateVersion,XPath");
};

/**
 typesafe validator
*/
	vWString JDFAutoCreated::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFAudit::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!Validref(level)) {
			vAtts.push_back(atr_ref);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTemplateID(level)) {
			vAtts.push_back(atr_TemplateID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTemplateVersion(level)) {
			vAtts.push_back(atr_TemplateVersion);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidXPath(level)) {
			vAtts.push_back(atr_XPath);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ref
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCreated::Setref(const WString& value){
	SetAttribute(atr_ref,value);
};
/**
* Get string attribute ref
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCreated::Getref() const {
	return GetAttribute(atr_ref,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreated::Validref(EnumValidationLevel level) const {
		return ValidAttribute(atr_ref,AttributeType_IDREF,false);
	};
/**
* Set attribute TemplateID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCreated::SetTemplateID(const WString& value){
	SetAttribute(atr_TemplateID,value);
};
/**
* Get string attribute TemplateID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCreated::GetTemplateID() const {
	return GetAttribute(atr_TemplateID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreated::ValidTemplateID(EnumValidationLevel level) const {
		return ValidAttribute(atr_TemplateID,AttributeType_shortString,false);
	};
/**
* Set attribute TemplateVersion
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCreated::SetTemplateVersion(const WString& value){
	SetAttribute(atr_TemplateVersion,value);
};
/**
* Get string attribute TemplateVersion
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCreated::GetTemplateVersion() const {
	return GetAttribute(atr_TemplateVersion,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreated::ValidTemplateVersion(EnumValidationLevel level) const {
		return ValidAttribute(atr_TemplateVersion,AttributeType_string,false);
	};
/**
* Set attribute XPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCreated::SetXPath(const WString& value){
	SetAttribute(atr_XPath,value);
};
/**
* Get string attribute XPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCreated::GetXPath() const {
	return GetAttribute(atr_XPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCreated::ValidXPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_XPath,AttributeType_XPath,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFEmployee JDFAutoCreated::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoCreated::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoCreated::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCreated::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCreated::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFAudit::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Employee);

		for(i=0;i<nElem;i++){
			if (!GetEmployee(i).IsValid(level)) {
				vElem.AppendUnique(elm_Employee);
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
	WString JDFAutoCreated::OptionalElements()const{
		return JDFAudit::OptionalElements()+L",Employee";
	};
}; // end namespace JDF
