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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAssemblySection.h"
#include "jdf/wrapper/JDFPageAssignedList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAssemblySection : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAssemblySection& JDFAutoAssemblySection::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAssemblySection: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAssemblySection::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAssemblySection::ValidNodeNames()const{
	return L"*:,AssemblySection";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoAssemblySection::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AssemblyID,AssemblyIDs,JobID,Order");
};

/**
 typesafe validator
*/
	vWString JDFAutoAssemblySection::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAssemblyID(level)) {
			vAtts.push_back(atr_AssemblyID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAssemblyIDs(level)) {
			vAtts.push_back(atr_AssemblyIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrder(level)) {
			vAtts.push_back(atr_Order);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AssemblyID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAssemblySection::SetAssemblyID(const WString& value){
	SetAttribute(atr_AssemblyID,value);
};
/**
* Get string attribute AssemblyID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAssemblySection::GetAssemblyID() const {
	return GetAttribute(atr_AssemblyID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssemblySection::ValidAssemblyID(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyID,AttributeType_string,false);
	};
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoAssemblySection::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoAssemblySection::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssemblySection::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAssemblySection::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAssemblySection::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssemblySection::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAssemblySection::OrderString(){
		static const WString enums=WString(L"Unknown,Collecting,Gathering");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAssemblySection::OrderString(EnumOrder value){
		return OrderString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAssemblySection::SetOrder( EnumOrder value){
	SetEnumAttribute(atr_Order,value,OrderString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAssemblySection::EnumOrder JDFAutoAssemblySection:: GetOrder() const {
	return (EnumOrder) GetEnumAttribute(atr_Order,OrderString(),WString::emptyStr,Order_Gathering);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssemblySection::ValidOrder(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Order,OrderString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPageAssignedList JDFAutoAssemblySection::GetPageAssignedList(int iSkip)const{
	JDFPageAssignedList e=GetElement(elm_PageAssignedList,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageAssignedList JDFAutoAssemblySection::GetCreatePageAssignedList(int iSkip){
	JDFPageAssignedList e=GetCreateElement(elm_PageAssignedList,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageAssignedList JDFAutoAssemblySection::AppendPageAssignedList(){
	JDFPageAssignedList e=AppendElement(elm_PageAssignedList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoAssemblySection::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_PageAssignedList);

		for(i=0;i<nElem;i++){
			if (!GetPageAssignedList(i).IsValid(level)) {
				vElem.AppendUnique(elm_PageAssignedList);
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
	WString JDFAutoAssemblySection::OptionalElements()const{
		return JDFElement::OptionalElements()+L",PageAssignedList";
	};
}; // end namespace JDF
