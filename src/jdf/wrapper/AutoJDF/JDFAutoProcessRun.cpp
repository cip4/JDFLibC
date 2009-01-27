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

 
#include "jdf/wrapper/AutoJDF/JDFAutoProcessRun.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoProcessRun : public JDFAudit

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoProcessRun& JDFAutoProcessRun::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoProcessRun: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoProcessRun::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoProcessRun::ValidNodeNames()const{
	return L"*:,ProcessRun";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoProcessRun::RequiredAttributes()const{
		return JDFAudit::RequiredAttributes()+L",End,EndStatus,Start";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoProcessRun::OptionalAttributes()const{
		return JDFAudit::OptionalAttributes()+WString(L",Duration,ReturnTime,SubmissionTime");
};

/**
 typesafe validator
*/
	vWString JDFAutoProcessRun::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFAudit::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDuration(level)) {
			vAtts.push_back(atr_Duration);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEnd(level)) {
			vAtts.push_back(atr_End);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEndStatus(level)) {
			vAtts.push_back(atr_EndStatus);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReturnTime(level)) {
			vAtts.push_back(atr_ReturnTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStart(level)) {
			vAtts.push_back(atr_Start);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSubmissionTime(level)) {
			vAtts.push_back(atr_SubmissionTime);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Duration
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoProcessRun::SetDuration(JDFDuration value){
	SetAttribute(atr_Duration,value.DurationISO());
};
/**
* Get string attribute Duration
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoProcessRun::GetDuration() const {
	return GetAttribute(atr_Duration,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProcessRun::ValidDuration(EnumValidationLevel level) const {
		return ValidAttribute(atr_Duration,AttributeType_duration,false);
	};
/**
* Set attribute End
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoProcessRun::SetEnd(JDFDate value){
	SetAttribute(atr_End,value.DateTimeISO());
};
/**
* Get string attribute End
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoProcessRun::GetEnd() const {
	return GetAttribute(atr_End,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProcessRun::ValidEnd(EnumValidationLevel level) const {
		return ValidAttribute(atr_End,AttributeType_dateTime,RequiredLevel(level));
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoProcessRun::SetEndStatus( JDFElement::EnumStatus value){
	SetEnumAttribute(atr_EndStatus,value,JDFElement::StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFElement::EnumStatus JDFAutoProcessRun::GetEndStatus() const {
	return (JDFElement::EnumStatus) GetEnumAttribute(atr_EndStatus,JDFElement::StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProcessRun::ValidEndStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_EndStatus,JDFElement::StatusString(),RequiredLevel(level));
	};
/**
* Set attribute ReturnTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoProcessRun::SetReturnTime(JDFDate value){
	SetAttribute(atr_ReturnTime,value.DateTimeISO());
};
/**
* Get string attribute ReturnTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoProcessRun::GetReturnTime() const {
	return GetAttribute(atr_ReturnTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProcessRun::ValidReturnTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReturnTime,AttributeType_dateTime,false);
	};
/**
* Set attribute Start
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoProcessRun::SetStart(JDFDate value){
	SetAttribute(atr_Start,value.DateTimeISO());
};
/**
* Get string attribute Start
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoProcessRun::GetStart() const {
	return GetAttribute(atr_Start,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProcessRun::ValidStart(EnumValidationLevel level) const {
		return ValidAttribute(atr_Start,AttributeType_dateTime,RequiredLevel(level));
	};
/**
* Set attribute SubmissionTime
*@param JDFDate value: the value to set the attribute to
*/
	 void JDFAutoProcessRun::SetSubmissionTime(JDFDate value){
	SetAttribute(atr_SubmissionTime,value.DateTimeISO());
};
/**
* Get string attribute SubmissionTime
* @return JDFDate the vaue of the attribute 
*/
	 JDFDate JDFAutoProcessRun::GetSubmissionTime() const {
	return GetAttribute(atr_SubmissionTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProcessRun::ValidSubmissionTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_SubmissionTime,AttributeType_dateTime,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFEmployee JDFAutoProcessRun::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoProcessRun::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoProcessRun::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoProcessRun::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoProcessRun::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoProcessRun::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoProcessRun::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoProcessRun::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoProcessRun::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoProcessRun::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoProcessRun::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoProcessRun::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoProcessRun::OptionalElements()const{
		return JDFAudit::OptionalElements()+L",Employee,Part";
	};
}; // end namespace JDF
