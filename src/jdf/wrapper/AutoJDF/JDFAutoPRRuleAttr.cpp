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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPRRuleAttr.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPRRuleAttr : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPRRuleAttr& JDFAutoPRRuleAttr::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPRRuleAttr: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPRRuleAttr::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPRRuleAttr::ValidNodeNames()const{
	return L"*:,PRRuleAttr";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPRRuleAttr::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",GroupBy,ReportAttr,LogErrors,MaxGroups,MaxPerGroup");
};

/**
 typesafe validator
*/
	vWString JDFAutoPRRuleAttr::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidGroupBy(level)) {
			vAtts.push_back(atr_GroupBy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReportAttr(level)) {
			vAtts.push_back(atr_ReportAttr);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLogErrors(level)) {
			vAtts.push_back(atr_LogErrors);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxGroups(level)) {
			vAtts.push_back(atr_MaxGroups);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxPerGroup(level)) {
			vAtts.push_back(atr_MaxPerGroup);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute GroupBy
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPRRuleAttr::SetGroupBy(const vWString& value){
	SetAttribute(atr_GroupBy,value);
};
/**
* Get string attribute GroupBy
* @return vWString the vaue of the attribute ; defaults to Tested
*/
	 vWString JDFAutoPRRuleAttr::GetGroupBy() const {
	return GetAttribute(atr_GroupBy,WString::emptyStr,L"Tested");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRRuleAttr::ValidGroupBy(EnumValidationLevel level) const {
		return ValidAttribute(atr_GroupBy,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute ReportAttr
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPRRuleAttr::SetReportAttr(const vWString& value){
	SetAttribute(atr_ReportAttr,value);
};
/**
* Get string attribute ReportAttr
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPRRuleAttr::GetReportAttr() const {
	return GetAttribute(atr_ReportAttr,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRRuleAttr::ValidReportAttr(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReportAttr,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute LogErrors
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRRuleAttr::SetLogErrors(int value){
	SetAttribute(atr_LogErrors,WString::valueOf(value));
};
/**
* Get integer attribute LogErrors
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRRuleAttr::GetLogErrors() const {
	return GetIntAttribute(atr_LogErrors,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRRuleAttr::ValidLogErrors(EnumValidationLevel level) const {
		return ValidAttribute(atr_LogErrors,AttributeType_integer,false);
	};
/**
* Set attribute MaxGroups
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRRuleAttr::SetMaxGroups(int value){
	SetAttribute(atr_MaxGroups,WString::valueOf(value));
};
/**
* Get integer attribute MaxGroups
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRRuleAttr::GetMaxGroups() const {
	return GetIntAttribute(atr_MaxGroups,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRRuleAttr::ValidMaxGroups(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxGroups,AttributeType_integer,false);
	};
/**
* Set attribute MaxPerGroup
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRRuleAttr::SetMaxPerGroup(int value){
	SetAttribute(atr_MaxPerGroup,WString::valueOf(value));
};
/**
* Get integer attribute MaxPerGroup
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRRuleAttr::GetMaxPerGroup() const {
	return GetIntAttribute(atr_MaxPerGroup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRRuleAttr::ValidMaxPerGroup(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxPerGroup,AttributeType_integer,false);
	};
}; // end namespace JDF
