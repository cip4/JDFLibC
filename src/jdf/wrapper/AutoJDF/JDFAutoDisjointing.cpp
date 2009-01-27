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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDisjointing.h"
#include "jdf/wrapper/JDFIdentificationField.h"
#include "jdf/wrapper/JDFInsertSheet.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDisjointing : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDisjointing& JDFAutoDisjointing::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDisjointing: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDisjointing::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDisjointing::ValidNodeNames()const{
	return L"*:,Disjointing";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDisjointing::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Number,Offset,OffsetAmount,OffsetDirection,Overfold");
};

/**
 typesafe validator
*/
	vWString JDFAutoDisjointing::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidNumber(level)) {
			vAtts.push_back(atr_Number);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOffset(level)) {
			vAtts.push_back(atr_Offset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOffsetAmount(level)) {
			vAtts.push_back(atr_OffsetAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOffsetDirection(level)) {
			vAtts.push_back(atr_OffsetDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOverfold(level)) {
			vAtts.push_back(atr_Overfold);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Number
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDisjointing::SetNumber(int value){
	SetAttribute(atr_Number,WString::valueOf(value));
};
/**
* Get integer attribute Number
* @return int the vaue of the attribute 
*/
	 int JDFAutoDisjointing::GetNumber() const {
	return GetIntAttribute(atr_Number,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisjointing::ValidNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_Number,AttributeType_integer,false);
	};
/**
* Set attribute Offset
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoDisjointing::SetOffset(const JDFXYPair& value){
	SetAttribute(atr_Offset,value);
};
/**
* Get string attribute Offset
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoDisjointing::GetOffset() const {
	return GetAttribute(atr_Offset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisjointing::ValidOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_Offset,AttributeType_XYPair,false);
	};
/**
* Set attribute OffsetAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDisjointing::SetOffsetAmount(int value){
	SetAttribute(atr_OffsetAmount,WString::valueOf(value));
};
/**
* Get integer attribute OffsetAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoDisjointing::GetOffsetAmount() const {
	return GetIntAttribute(atr_OffsetAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisjointing::ValidOffsetAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_OffsetAmount,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDisjointing::OffsetDirectionString(){
		static const WString enums=WString(L"Unknown,Alternate,Left,None,Right,Straight,SystemSpecified");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDisjointing::OffsetDirectionString(EnumOffsetDirection value){
		return OffsetDirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDisjointing::SetOffsetDirection( EnumOffsetDirection value){
	SetEnumAttribute(atr_OffsetDirection,value,OffsetDirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDisjointing::EnumOffsetDirection JDFAutoDisjointing:: GetOffsetDirection() const {
	return (EnumOffsetDirection) GetEnumAttribute(atr_OffsetDirection,OffsetDirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisjointing::ValidOffsetDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_OffsetDirection,OffsetDirectionString(),false);
	};
/**
* Set attribute Overfold
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDisjointing::SetOverfold(double value){
	SetAttribute(atr_Overfold,WString::valueOf(value));
};
/**
* Get double attribute Overfold
* @return double the vaue of the attribute 
*/
	 double JDFAutoDisjointing::GetOverfold() const {
	return GetRealAttribute(atr_Overfold,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDisjointing::ValidOverfold(EnumValidationLevel level) const {
		return ValidAttribute(atr_Overfold,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIdentificationField JDFAutoDisjointing::GetIdentificationField(int iSkip)const{
	JDFIdentificationField e=GetElement(elm_IdentificationField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIdentificationField JDFAutoDisjointing::GetCreateIdentificationField(int iSkip){
	JDFIdentificationField e=GetCreateElement(elm_IdentificationField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIdentificationField JDFAutoDisjointing::AppendIdentificationField(){
	JDFIdentificationField e=AppendElement(elm_IdentificationField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDisjointing::RefIdentificationField(JDFIdentificationField& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoDisjointing::GetInsertSheet(int iSkip)const{
	JDFInsertSheet e=GetElement(elm_InsertSheet,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoDisjointing::GetCreateInsertSheet(int iSkip){
	JDFInsertSheet e=GetCreateElement(elm_InsertSheet,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertSheet JDFAutoDisjointing::AppendInsertSheet(){
	JDFInsertSheet e=AppendElement(elm_InsertSheet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDisjointing::RefInsertSheet(JDFInsertSheet& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoDisjointing::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoDisjointing::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoDisjointing::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDisjointing::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDisjointing::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_IdentificationField);

		for(i=0;i<nElem;i++){
			if (!GetIdentificationField(i).IsValid(level)) {
				vElem.AppendUnique(elm_IdentificationField);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_InsertSheet);

		for(i=0;i<nElem;i++){
			if (!GetInsertSheet(i).IsValid(level)) {
				vElem.AppendUnique(elm_InsertSheet);
				if (++n>=nMax)
					return vElem;
				break;
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
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDisjointing::OptionalElements()const{
		return JDFElement::OptionalElements()+L",IdentificationField,InsertSheet,QualityControlResult";
	};
}; // end namespace JDF
