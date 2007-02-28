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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDisposition.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDisposition : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDisposition& JDFAutoDisposition::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDisposition: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDisposition::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDisposition::ValidNodeNames()const{
	return L"*:,Disposition";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDisposition::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",DispositionAction,Priority,DispositionUsage,ExtraDuration,MinDuration,Until");
};

/**
 typesafe validator
*/
	vWString JDFAutoDisposition::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDispositionAction(level)) {
			vAtts.push_back(atr_DispositionAction);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPriority(level)) {
			vAtts.push_back(atr_Priority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDispositionUsage(level)) {
			vAtts.push_back(atr_DispositionUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidExtraDuration(level)) {
			vAtts.push_back(atr_ExtraDuration);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinDuration(level)) {
			vAtts.push_back(atr_MinDuration);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUntil(level)) {
			vAtts.push_back(atr_Until);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDisposition::DispositionActionString(){
		static const WString enums=WString(L"Unknown,Delete,Archive");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDisposition::DispositionActionString(EnumDispositionAction value){
		return DispositionActionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDisposition::SetDispositionAction( EnumDispositionAction value){
	SetEnumAttribute(atr_DispositionAction,value,DispositionActionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDisposition::EnumDispositionAction JDFAutoDisposition:: GetDispositionAction() const {
	return (EnumDispositionAction) GetEnumAttribute(atr_DispositionAction,DispositionActionString(),WString::emptyStr,DispositionAction_Delete);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisposition::ValidDispositionAction(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DispositionAction,DispositionActionString(),false);
	};
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDisposition::SetPriority(int value){
	SetAttribute(atr_Priority,WString::valueOf(value));
};
/**
* Get integer attribute Priority
* @return int the vaue of the attribute ; defaults to 0
*/
	 int JDFAutoDisposition::GetPriority() const {
	return GetIntAttribute(atr_Priority,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisposition::ValidPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_Priority,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDisposition::DispositionUsageString(){
		static const WString enums=WString(L"Unknown,Input,Output");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDisposition::DispositionUsageString(EnumDispositionUsage value){
		return DispositionUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDisposition::SetDispositionUsage( EnumDispositionUsage value){
	SetEnumAttribute(atr_DispositionUsage,value,DispositionUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDisposition::EnumDispositionUsage JDFAutoDisposition:: GetDispositionUsage() const {
	return (EnumDispositionUsage) GetEnumAttribute(atr_DispositionUsage,DispositionUsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisposition::ValidDispositionUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DispositionUsage,DispositionUsageString(),false);
	};
/**
* Set attribute ExtraDuration
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoDisposition::SetExtraDuration(JDFDuration value){
	SetAttribute(atr_ExtraDuration,value.DurationISO());
};
/**
* Get string attribute ExtraDuration
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoDisposition::GetExtraDuration() const {
	return GetAttribute(atr_ExtraDuration,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisposition::ValidExtraDuration(EnumValidationLevel level) const {
		return ValidAttribute(atr_ExtraDuration,AttributeType_duration,false);
	};
/**
* Set attribute MinDuration
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoDisposition::SetMinDuration(JDFDuration value){
	SetAttribute(atr_MinDuration,value.DurationISO());
};
/**
* Get string attribute MinDuration
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoDisposition::GetMinDuration() const {
	return GetAttribute(atr_MinDuration,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisposition::ValidMinDuration(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinDuration,AttributeType_duration,false);
	};
/**
* Set attribute Until
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoDisposition::SetUntil(JDFDate value){
	SetAttribute(atr_Until,value.DateTimeISO());
};
/**
* Get string attribute Until
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoDisposition::GetUntil() const {
	return GetAttribute(atr_Until,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisposition::ValidUntil(EnumValidationLevel level) const {
		return ValidAttribute(atr_Until,AttributeType_dateTime,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFQualityControlResult JDFAutoDisposition::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoDisposition::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoDisposition::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDisposition::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDisposition::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
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
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDisposition::OptionalElements()const{
		return JDFElement::OptionalElements()+L",QualityControlResult";
	};
}; // end namespace JDF
