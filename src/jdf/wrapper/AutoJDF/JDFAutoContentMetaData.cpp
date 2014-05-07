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

 
#include "jdf/wrapper/AutoJDF/JDFAutoContentMetaData.h"
#include "jdf/wrapper/JDFContact.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoContentMetaData : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoContentMetaData& JDFAutoContentMetaData::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoContentMetaData: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoContentMetaData::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoContentMetaData::ValidNodeNames()const{
	return L"*:,ContentMetaData";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoContentMetaData::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ISBN10,ISBN13,Title");
};

/**
 typesafe validator
*/
	vWString JDFAutoContentMetaData::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidISBN10(level)) {
			vAtts.push_back(atr_ISBN10);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidISBN13(level)) {
			vAtts.push_back(atr_ISBN13);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTitle(level)) {
			vAtts.push_back(atr_Title);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ISBN10
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentMetaData::SetISBN10(const WString& value){
	SetAttribute(atr_ISBN10,value);
};
/**
* Get string attribute ISBN10
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentMetaData::GetISBN10() const {
	return GetAttribute(atr_ISBN10,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentMetaData::ValidISBN10(EnumValidationLevel level) const {
		return ValidAttribute(atr_ISBN10,AttributeType_string,false);
	};
/**
* Set attribute ISBN13
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentMetaData::SetISBN13(const WString& value){
	SetAttribute(atr_ISBN13,value);
};
/**
* Get string attribute ISBN13
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentMetaData::GetISBN13() const {
	return GetAttribute(atr_ISBN13,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentMetaData::ValidISBN13(EnumValidationLevel level) const {
		return ValidAttribute(atr_ISBN13,AttributeType_string,false);
	};
/**
* Set attribute Title
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoContentMetaData::SetTitle(const WString& value){
	SetAttribute(atr_Title,value);
};
/**
* Get string attribute Title
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoContentMetaData::GetTitle() const {
	return GetAttribute(atr_Title,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoContentMetaData::ValidTitle(EnumValidationLevel level) const {
		return ValidAttribute(atr_Title,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFContact JDFAutoContentMetaData::GetContact(int iSkip)const{
	JDFContact e=GetElement(elm_Contact,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoContentMetaData::GetCreateContact(int iSkip){
	JDFContact e=GetCreateElement(elm_Contact,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFContact JDFAutoContentMetaData::AppendContact(){
	JDFContact e=AppendElement(elm_Contact);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContentMetaData::RefContact(JDFContact& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoContentMetaData::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoContentMetaData::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoContentMetaData::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoContentMetaData::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoContentMetaData::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoContentMetaData::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoContentMetaData::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoContentMetaData::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoContentMetaData::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoContentMetaData::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoContentMetaData::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoContentMetaData::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoContentMetaData::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Contact);

		for(i=0;i<nElem;i++){
			if (!GetContact(i).IsValid(level)) {
				vElem.AppendUnique(elm_Contact);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
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
	WString JDFAutoContentMetaData::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Contact,Employee,Part";
	};
}; // end namespace JDF
