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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreflightReportRulePool.h"
#include "jdf/wrapper/JDFPRRule.h"
#include "jdf/wrapper/JDFPRRuleAttr.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreflightReportRulePool : public JDFPool

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreflightReportRulePool& JDFAutoPreflightReportRulePool::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreflightReportRulePool: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreflightReportRulePool::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreflightReportRulePool::ValidNodeNames()const{
	return L"*:,PreflightReportRulePool";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoPreflightReportRulePool::RequiredAttributes()const{
		return JDFPool::RequiredAttributes()+L",ActionPools";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPreflightReportRulePool::OptionalAttributes()const{
		return JDFPool::OptionalAttributes()+WString(L",MaxOccurrences");
};

/**
 typesafe validator
*/
	vWString JDFAutoPreflightReportRulePool::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFPool::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidActionPools(level)) {
			vAtts.push_back(atr_ActionPools);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxOccurrences(level)) {
			vAtts.push_back(atr_MaxOccurrences);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ActionPools
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPreflightReportRulePool::SetActionPools(const vWString& value){
	SetAttribute(atr_ActionPools,value);
};
/**
* Get string attribute ActionPools
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPreflightReportRulePool::GetActionPools() const {
	return GetAttribute(atr_ActionPools,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightReportRulePool::ValidActionPools(EnumValidationLevel level) const {
		return ValidAttribute(atr_ActionPools,AttributeType_IDREFS,RequiredLevel(level));
	};
/**
* Set attribute MaxOccurrences
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPreflightReportRulePool::SetMaxOccurrences(int value){
	SetAttribute(atr_MaxOccurrences,WString::valueOf(value));
};
/**
* Get integer attribute MaxOccurrences
* @return int the vaue of the attribute 
*/
	 int JDFAutoPreflightReportRulePool::GetMaxOccurrences() const {
	return GetIntAttribute(atr_MaxOccurrences,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreflightReportRulePool::ValidMaxOccurrences(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxOccurrences,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPRRule JDFAutoPreflightReportRulePool::GetPRRule(int iSkip)const{
	JDFPRRule e=GetElement(elm_PRRule,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRRule JDFAutoPreflightReportRulePool::GetCreatePRRule(int iSkip){
	JDFPRRule e=GetCreateElement(elm_PRRule,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRRule JDFAutoPreflightReportRulePool::AppendPRRule(){
	JDFPRRule e=AppendElement(elm_PRRule);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRRuleAttr JDFAutoPreflightReportRulePool::GetPRRuleAttr()const{
	JDFPRRuleAttr e=GetElement(elm_PRRuleAttr);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRRuleAttr JDFAutoPreflightReportRulePool::GetCreatePRRuleAttr(){
	JDFPRRuleAttr e=GetCreateElement(elm_PRRuleAttr);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRRuleAttr JDFAutoPreflightReportRulePool::AppendPRRuleAttr(){
	JDFPRRuleAttr e=AppendElementN(elm_PRRuleAttr,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoPreflightReportRulePool::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoPreflightReportRulePool::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoPreflightReportRulePool::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPreflightReportRulePool::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreflightReportRulePool::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFPool::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_PRRule);

		for(i=0;i<nElem;i++){
			if (!GetPRRule(i).IsValid(level)) {
				vElem.AppendUnique(elm_PRRule);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PRRuleAttr);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PRRuleAttr);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPRRuleAttr().IsValid(level)) {
				vElem.AppendUnique(elm_PRRuleAttr);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_QualityControlResult);

		for(i=0;i<nElem;i++){
			if (!GetQualityControlResult(i).IsValid(level)) {
				vElem.AppendUnique(elm_QualityControlResult);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPreflightReportRulePool::UniqueElements()const{
		return JDFPool::UniqueElements()+L",PRRuleAttr";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPreflightReportRulePool::OptionalElements()const{
		return JDFPool::OptionalElements()+L",PRRule,PRRuleAttr,QualityControlResult";
	};
}; // end namespace JDF
