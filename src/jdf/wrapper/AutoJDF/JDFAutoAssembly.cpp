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

 
#include "jdf/wrapper/AutoJDF/JDFAutoAssembly.h"
#include "jdf/wrapper/JDFAssemblySection.h"
#include "jdf/wrapper/JDFPageList.h"
#include "jdf/wrapper/JDFPageAssignedList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoAssembly : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoAssembly& JDFAutoAssembly::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoAssembly: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoAssembly::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoAssembly::ValidNodeNames()const{
	return L"*:,Assembly";
};

bool JDFAutoAssembly::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoAssembly::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoAssembly::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",JogSide,Order,BindingSide,AssemblyID,AssemblyIDs,JobID,PhysicalSection");
};

/**
 typesafe validator
*/
	vWString JDFAutoAssembly::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidJogSide(level)) {
			vAtts.push_back(atr_JogSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrder(level)) {
			vAtts.push_back(atr_Order);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBindingSide(level)) {
			vAtts.push_back(atr_BindingSide);
			if(++n>=nMax)
				return vAtts;
		};
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
		if(!ValidPhysicalSection(level)) {
			vAtts.push_back(atr_PhysicalSection);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAssembly::JogSideString(){
		static const WString enums=WString(L"Unknown,Left,Right,Top,Bottom,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAssembly::JogSideString(EnumJogSide value){
		return JogSideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAssembly::SetJogSide( EnumJogSide value){
	SetEnumAttribute(atr_JogSide,value,JogSideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAssembly::EnumJogSide JDFAutoAssembly:: GetJogSide() const {
	return (EnumJogSide) GetEnumAttribute(atr_JogSide,JogSideString(),WString::emptyStr,JogSide_Top);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssembly::ValidJogSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_JogSide,JogSideString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAssembly::OrderString(){
		static const WString enums=WString(L"Unknown,Collecting,Gathering,None,List");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAssembly::OrderString(EnumOrder value){
		return OrderString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAssembly::SetOrder( EnumOrder value){
	SetEnumAttribute(atr_Order,value,OrderString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAssembly::EnumOrder JDFAutoAssembly:: GetOrder() const {
	return (EnumOrder) GetEnumAttribute(atr_Order,OrderString(),WString::emptyStr,Order_Gathering);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssembly::ValidOrder(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Order,OrderString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoAssembly::BindingSideString(){
		static const WString enums=WString(L"Unknown,Left,Right,Top,Bottom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoAssembly::BindingSideString(EnumBindingSide value){
		return BindingSideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoAssembly::SetBindingSide( EnumBindingSide value){
	SetEnumAttribute(atr_BindingSide,value,BindingSideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoAssembly::EnumBindingSide JDFAutoAssembly:: GetBindingSide() const {
	return (EnumBindingSide) GetEnumAttribute(atr_BindingSide,BindingSideString(),WString::emptyStr,BindingSide_Left);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssembly::ValidBindingSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BindingSide,BindingSideString(),false);
	};
/**
* Set attribute AssemblyID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAssembly::SetAssemblyID(const WString& value){
	SetAttribute(atr_AssemblyID,value);
};
/**
* Get string attribute AssemblyID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAssembly::GetAssemblyID() const {
	return GetAttribute(atr_AssemblyID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssembly::ValidAssemblyID(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyID,AttributeType_string,false);
	};
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoAssembly::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoAssembly::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssembly::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoAssembly::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoAssembly::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssembly::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute PhysicalSection
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoAssembly::SetPhysicalSection(const JDFIntegerList& value){
	SetAttribute(atr_PhysicalSection,value.GetString());
};
/**
* Get string attribute PhysicalSection
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoAssembly::GetPhysicalSection() const {
	return GetAttribute(atr_PhysicalSection,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoAssembly::ValidPhysicalSection(EnumValidationLevel level) const {
		return ValidAttribute(atr_PhysicalSection,AttributeType_IntegerList,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAssemblySection JDFAutoAssembly::GetAssemblySection(int iSkip)const{
	JDFAssemblySection e=GetElement(elm_AssemblySection,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAssemblySection JDFAutoAssembly::GetCreateAssemblySection(int iSkip){
	JDFAssemblySection e=GetCreateElement(elm_AssemblySection,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAssemblySection JDFAutoAssembly::AppendAssemblySection(){
	JDFAssemblySection e=AppendElement(elm_AssemblySection);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoAssembly::GetPageList()const{
	JDFPageList e=GetElement(elm_PageList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoAssembly::GetCreatePageList(){
	JDFPageList e=GetCreateElement(elm_PageList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageList JDFAutoAssembly::AppendPageList(){
	JDFPageList e=AppendElementN(elm_PageList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoAssembly::RefPageList(JDFPageList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPageAssignedList JDFAutoAssembly::GetPageAssignedList(int iSkip)const{
	JDFPageAssignedList e=GetElement(elm_PageAssignedList,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageAssignedList JDFAutoAssembly::GetCreatePageAssignedList(int iSkip){
	JDFPageAssignedList e=GetCreateElement(elm_PageAssignedList,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPageAssignedList JDFAutoAssembly::AppendPageAssignedList(){
	JDFPageAssignedList e=AppendElement(elm_PageAssignedList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoAssembly::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_AssemblySection);

		for(i=0;i<nElem;i++){
			if (!GetAssemblySection(i).IsValid(level)) {
				vElem.AppendUnique(elm_AssemblySection);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PageList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PageList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPageList().IsValid(level)) {
				vElem.AppendUnique(elm_PageList);
				if (++n>=nMax)
					return vElem;
			}
		}
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
 definition of required elements in the JDF namespace
*/
	WString JDFAutoAssembly::UniqueElements()const{
		return JDFResource::UniqueElements()+L",PageList";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoAssembly::OptionalElements()const{
		return JDFResource::OptionalElements()+L",AssemblySection,PageList,PageAssignedList";
	};
}; // end namespace JDF
