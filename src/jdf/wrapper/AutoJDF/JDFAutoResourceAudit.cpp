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

 
#include "jdf/wrapper/AutoJDF/JDFAutoResourceAudit.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFMISDetails.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoResourceAudit : public JDFAudit

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoResourceAudit& JDFAutoResourceAudit::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoResourceAudit: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoResourceAudit::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoResourceAudit::ValidNodeNames()const{
	return L"*:,ResourceAudit";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoResourceAudit::OptionalAttributes()const{
		return JDFAudit::OptionalAttributes()+WString(L",ContentsModified,NodeStatus,Reason");
};

/**
 typesafe validator
*/
	vWString JDFAutoResourceAudit::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFAudit::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidContentsModified(level)) {
			vAtts.push_back(atr_ContentsModified);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNodeStatus(level)) {
			vAtts.push_back(atr_NodeStatus);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReason(level)) {
			vAtts.push_back(atr_Reason);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ContentsModified
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoResourceAudit::SetContentsModified(bool value){
	SetAttribute(atr_ContentsModified,WString::valueOf(value));
};
/**
* Get bool attribute ContentsModified
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoResourceAudit::GetContentsModified() const {return GetBoolAttribute(atr_ContentsModified,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceAudit::ValidContentsModified(EnumValidationLevel level) const {
		return ValidAttribute(atr_ContentsModified,AttributeType_boolean,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceAudit::SetNodeStatus( JDFElement::EnumStatus value){
	SetEnumAttribute(atr_NodeStatus,value,JDFElement::StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFElement::EnumStatus JDFAutoResourceAudit::GetNodeStatus() const {
	return (JDFElement::EnumStatus) GetEnumAttribute(atr_NodeStatus,JDFElement::StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceAudit::ValidNodeStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_NodeStatus,JDFElement::StatusString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceAudit::ReasonString(){
		static const WString enums=WString(L"Unknown,OperatorInput,PlanChange,ProcessResult");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceAudit::ReasonString(EnumReason value){
		return ReasonString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceAudit::SetReason( EnumReason value){
	SetEnumAttribute(atr_Reason,value,ReasonString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceAudit::EnumReason JDFAutoResourceAudit:: GetReason() const {
	return (EnumReason) GetEnumAttribute(atr_Reason,ReasonString(),WString::emptyStr,Reason_ProcessResult);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceAudit::ValidReason(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Reason,ReasonString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFEmployee JDFAutoResourceAudit::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoResourceAudit::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoResourceAudit::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoResourceAudit::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourceAudit::GetMISDetails(int iSkip)const{
	JDFMISDetails e=GetElement(elm_MISDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourceAudit::GetCreateMISDetails(int iSkip){
	JDFMISDetails e=GetCreateElement(elm_MISDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourceAudit::AppendMISDetails(){
	JDFMISDetails e=AppendElement(elm_MISDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceAudit::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceAudit::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceAudit::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoResourceAudit::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceAudit::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceAudit::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceAudit::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoResourceAudit::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoResourceAudit::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
		nElem=NumChildElements(elm_MISDetails);

		for(i=0;i<nElem;i++){
			if (!GetMISDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_MISDetails);
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
	WString JDFAutoResourceAudit::OptionalElements()const{
		return JDFAudit::OptionalElements()+L",Employee,MISDetails,Part";
	};
}; // end namespace JDF
