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

 
#include "jdf/wrapper/AutoJDF/JDFAutoQualityMeasurement.h"
#include "jdf/wrapper/JDFBindingQualityMeasurement.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoQualityMeasurement : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoQualityMeasurement& JDFAutoQualityMeasurement::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoQualityMeasurement: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoQualityMeasurement::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoQualityMeasurement::ValidNodeNames()const{
	return L"*:,QualityMeasurement";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoQualityMeasurement::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",End,Failed,Passed,Condition,Start");
};

/**
 typesafe validator
*/
	vWString JDFAutoQualityMeasurement::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidEnd(level)) {
			vAtts.push_back(atr_End);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFailed(level)) {
			vAtts.push_back(atr_Failed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPassed(level)) {
			vAtts.push_back(atr_Passed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCondition(level)) {
			vAtts.push_back(atr_Condition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStart(level)) {
			vAtts.push_back(atr_Start);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute End
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoQualityMeasurement::SetEnd(JDFDate value){
	SetAttribute(atr_End,value.DateTimeISO());
};
/**
* Get string attribute End
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoQualityMeasurement::GetEnd() const {
	return GetAttribute(atr_End,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityMeasurement::ValidEnd(EnumValidationLevel level) const {
		return ValidAttribute(atr_End,AttributeType_dateTime,false);
	};
/**
* Set attribute Failed
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQualityMeasurement::SetFailed(int value){
	SetAttribute(atr_Failed,WString::valueOf(value));
};
/**
* Get integer attribute Failed
* @return int the vaue of the attribute 
*/
	 int JDFAutoQualityMeasurement::GetFailed() const {
	return GetIntAttribute(atr_Failed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityMeasurement::ValidFailed(EnumValidationLevel level) const {
		return ValidAttribute(atr_Failed,AttributeType_integer,false);
	};
/**
* Set attribute Passed
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQualityMeasurement::SetPassed(int value){
	SetAttribute(atr_Passed,WString::valueOf(value));
};
/**
* Get integer attribute Passed
* @return int the vaue of the attribute 
*/
	 int JDFAutoQualityMeasurement::GetPassed() const {
	return GetIntAttribute(atr_Passed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityMeasurement::ValidPassed(EnumValidationLevel level) const {
		return ValidAttribute(atr_Passed,AttributeType_integer,false);
	};
/**
* Set attribute Condition
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoQualityMeasurement::SetCondition(const WString& value){
	SetAttribute(atr_Condition,value);
};
/**
* Get string attribute Condition
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoQualityMeasurement::GetCondition() const {
	return GetAttribute(atr_Condition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityMeasurement::ValidCondition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Condition,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Start
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoQualityMeasurement::SetStart(JDFDate value){
	SetAttribute(atr_Start,value.DateTimeISO());
};
/**
* Get string attribute Start
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoQualityMeasurement::GetStart() const {
	return GetAttribute(atr_Start,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityMeasurement::ValidStart(EnumValidationLevel level) const {
		return ValidAttribute(atr_Start,AttributeType_dateTime,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBindingQualityMeasurement JDFAutoQualityMeasurement::GetBindingQualityMeasurement(int iSkip)const{
	JDFBindingQualityMeasurement e=GetElement(elm_BindingQualityMeasurement,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindingQualityMeasurement JDFAutoQualityMeasurement::GetCreateBindingQualityMeasurement(int iSkip){
	JDFBindingQualityMeasurement e=GetCreateElement(elm_BindingQualityMeasurement,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindingQualityMeasurement JDFAutoQualityMeasurement::AppendBindingQualityMeasurement(){
	JDFBindingQualityMeasurement e=AppendElement(elm_BindingQualityMeasurement);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoQualityMeasurement::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BindingQualityMeasurement);

		for(i=0;i<nElem;i++){
			if (!GetBindingQualityMeasurement(i).IsValid(level)) {
				vElem.AppendUnique(elm_BindingQualityMeasurement);
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
	WString JDFAutoQualityMeasurement::OptionalElements()const{
		return JDFElement::OptionalElements()+L",BindingQualityMeasurement";
	};
}; // end namespace JDF
