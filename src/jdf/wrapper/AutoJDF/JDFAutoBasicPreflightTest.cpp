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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBasicPreflightTest.h"
#include "jdf/wrapper/JDFPreflightArgument.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBasicPreflightTest : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBasicPreflightTest& JDFAutoBasicPreflightTest::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBasicPreflightTest: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBasicPreflightTest::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBasicPreflightTest::ValidNodeNames()const{
	return L"*:,BasicPreflightTest";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoBasicPreflightTest::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Name";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBasicPreflightTest::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Classes,ClassName,DevNS,ListType,MaxOccurs,MinOccurs");
};

/**
 typesafe validator
*/
	vWString JDFAutoBasicPreflightTest::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidClasses(level)) {
			vAtts.push_back(atr_Classes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClassName(level)) {
			vAtts.push_back(atr_ClassName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDevNS(level)) {
			vAtts.push_back(atr_DevNS);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidListType(level)) {
			vAtts.push_back(atr_ListType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxOccurs(level)) {
			vAtts.push_back(atr_MaxOccurs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinOccurs(level)) {
			vAtts.push_back(atr_MinOccurs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Classes
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoBasicPreflightTest::SetClasses(const vWString& value){
	SetAttribute(atr_Classes,value);
};
/**
* Get string attribute Classes
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoBasicPreflightTest::GetClasses() const {
	return GetAttribute(atr_Classes,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBasicPreflightTest::ValidClasses(EnumValidationLevel level) const {
		return ValidAttribute(atr_Classes,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute ClassName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBasicPreflightTest::SetClassName(const WString& value){
	SetAttribute(atr_ClassName,value);
};
/**
* Get string attribute ClassName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBasicPreflightTest::GetClassName() const {
	return GetAttribute(atr_ClassName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBasicPreflightTest::ValidClassName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClassName,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute DevNS
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBasicPreflightTest::SetDevNS(const WString& value){
	SetAttribute(atr_DevNS,value);
};
/**
* Get string attribute DevNS
* @return WString the vaue of the attribute ; defaults to http://www.CIP4.org/JDFSchema_1_1
*/
	 WString JDFAutoBasicPreflightTest::GetDevNS() const {
	return GetAttribute(atr_DevNS,WString::emptyStr,L"http://www.CIP4.org/JDFSchema_1_1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBasicPreflightTest::ValidDevNS(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevNS,AttributeType_URI,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBasicPreflightTest::ListTypeString(){
		static const WString enums=WString(L"Unknown,CompleteList,CompleteOrderedList,ContainedList,List,OrderedList,OrderedRangeList,Range,RangeList,SingleValue")
	+WString(L",Span,UniqueList,UniqueRangeList,UniqueOrderedList,UniqueOrderedRangeList");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBasicPreflightTest::ListTypeString(EnumListType value){
		return ListTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBasicPreflightTest::SetListType( EnumListType value){
	SetEnumAttribute(atr_ListType,value,ListTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBasicPreflightTest::EnumListType JDFAutoBasicPreflightTest:: GetListType() const {
	return (EnumListType) GetEnumAttribute(atr_ListType,ListTypeString(),WString::emptyStr,ListType_SingleValue);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBasicPreflightTest::ValidListType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ListType,ListTypeString(),false);
	};
/**
* Set attribute MaxOccurs
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBasicPreflightTest::SetMaxOccurs(int value){
	SetAttribute(atr_MaxOccurs,WString::valueOf(value));
};
/**
* Get integer attribute MaxOccurs
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoBasicPreflightTest::GetMaxOccurs() const {
	return GetIntAttribute(atr_MaxOccurs,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBasicPreflightTest::ValidMaxOccurs(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxOccurs,AttributeType_integer,false);
	};
/**
* Set attribute MinOccurs
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBasicPreflightTest::SetMinOccurs(int value){
	SetAttribute(atr_MinOccurs,WString::valueOf(value));
};
/**
* Get integer attribute MinOccurs
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoBasicPreflightTest::GetMinOccurs() const {
	return GetIntAttribute(atr_MinOccurs,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBasicPreflightTest::ValidMinOccurs(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinOccurs,AttributeType_integer,false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBasicPreflightTest::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBasicPreflightTest::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBasicPreflightTest::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_NMTOKEN,RequiredLevel(level));
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPreflightArgument JDFAutoBasicPreflightTest::GetPreflightArgument(int iSkip)const{
	JDFPreflightArgument e=GetElement(elm_PreflightArgument,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightArgument JDFAutoBasicPreflightTest::GetCreatePreflightArgument(int iSkip){
	JDFPreflightArgument e=GetCreateElement(elm_PreflightArgument,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightArgument JDFAutoBasicPreflightTest::AppendPreflightArgument(){
	JDFPreflightArgument e=AppendElement(elm_PreflightArgument);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBasicPreflightTest::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_PreflightArgument);

		for(i=0;i<nElem;i++){
			if (!GetPreflightArgument(i).IsValid(level)) {
				vElem.AppendUnique(elm_PreflightArgument);
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
	WString JDFAutoBasicPreflightTest::OptionalElements()const{
		return JDFElement::OptionalElements()+L",PreflightArgument";
	};
}; // end namespace JDF
