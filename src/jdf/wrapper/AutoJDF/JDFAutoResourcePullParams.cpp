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

 
#include "jdf/wrapper/AutoJDF/JDFAutoResourcePullParams.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFDisposition.h"
#include "jdf/wrapper/JDFMISDetails.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoResourcePullParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoResourcePullParams& JDFAutoResourcePullParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoResourcePullParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoResourcePullParams::ValidNodeNames()const{
	return L"*:,ResourcePullParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoResourcePullParams::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ResourceID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoResourcePullParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Amount,Hold,NextQueueEntryID,PrevQueueEntryID,JobID,Priority,QueueEntryID,RepeatPolicy,ReturnURL,WatchURL");
};

/**
 typesafe validator
*/
	vWString JDFAutoResourcePullParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAmount(level)) {
			vAtts.push_back(atr_Amount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHold(level)) {
			vAtts.push_back(atr_Hold);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNextQueueEntryID(level)) {
			vAtts.push_back(atr_NextQueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrevQueueEntryID(level)) {
			vAtts.push_back(atr_PrevQueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPriority(level)) {
			vAtts.push_back(atr_Priority);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRepeatPolicy(level)) {
			vAtts.push_back(atr_RepeatPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceID(level)) {
			vAtts.push_back(atr_ResourceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReturnURL(level)) {
			vAtts.push_back(atr_ReturnURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWatchURL(level)) {
			vAtts.push_back(atr_WatchURL);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Amount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetAmount(double value){
	SetAttribute(atr_Amount,WString::valueOf(value));
};
/**
* Get double attribute Amount
* @return double the vaue of the attribute 
*/
	 double JDFAutoResourcePullParams::GetAmount() const {
	return GetRealAttribute(atr_Amount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Amount,AttributeType_double,false);
	};
/**
* Set attribute Hold
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetHold(bool value){
	SetAttribute(atr_Hold,WString::valueOf(value));
};
/**
* Get bool attribute Hold
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoResourcePullParams::GetHold() const {return GetBoolAttribute(atr_Hold,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidHold(EnumValidationLevel level) const {
		return ValidAttribute(atr_Hold,AttributeType_boolean,false);
	};
/**
* Set attribute NextQueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetNextQueueEntryID(const WString& value){
	SetAttribute(atr_NextQueueEntryID,value);
};
/**
* Get string attribute NextQueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourcePullParams::GetNextQueueEntryID() const {
	return GetAttribute(atr_NextQueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidNextQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_NextQueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute PrevQueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetPrevQueueEntryID(const WString& value){
	SetAttribute(atr_PrevQueueEntryID,value);
};
/**
* Get string attribute PrevQueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourcePullParams::GetPrevQueueEntryID() const {
	return GetAttribute(atr_PrevQueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidPrevQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrevQueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourcePullParams::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute Priority
*@param int value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetPriority(int value){
	SetAttribute(atr_Priority,WString::valueOf(value));
};
/**
* Get integer attribute Priority
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoResourcePullParams::GetPriority() const {
	return GetIntAttribute(atr_Priority,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidPriority(EnumValidationLevel level) const {
		return ValidAttribute(atr_Priority,AttributeType_integer,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourcePullParams::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourcePullParams::RepeatPolicyString(){
		static const WString enums=WString(L"Unknown,Complete,CompleteOnly,Fast");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourcePullParams::RepeatPolicyString(EnumRepeatPolicy value){
		return RepeatPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourcePullParams::SetRepeatPolicy( EnumRepeatPolicy value){
	SetEnumAttribute(atr_RepeatPolicy,value,RepeatPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourcePullParams::EnumRepeatPolicy JDFAutoResourcePullParams:: GetRepeatPolicy() const {
	return (EnumRepeatPolicy) GetEnumAttribute(atr_RepeatPolicy,RepeatPolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidRepeatPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_RepeatPolicy,RepeatPolicyString(),false);
	};
/**
* Set attribute ResourceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetResourceID(const WString& value){
	SetAttribute(atr_ResourceID,value);
};
/**
* Get string attribute ResourceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourcePullParams::GetResourceID() const {
	return GetAttribute(atr_ResourceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidResourceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceID,AttributeType_shortString,RequiredLevel(level));
	};
/**
* Set attribute ReturnURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetReturnURL(const WString& value){
	SetAttribute(atr_ReturnURL,value);
};
/**
* Get string attribute ReturnURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourcePullParams::GetReturnURL() const {
	return GetAttribute(atr_ReturnURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidReturnURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReturnURL,AttributeType_URL,false);
	};
/**
* Set attribute WatchURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourcePullParams::SetWatchURL(const WString& value){
	SetAttribute(atr_WatchURL,value);
};
/**
* Get string attribute WatchURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourcePullParams::GetWatchURL() const {
	return GetAttribute(atr_WatchURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourcePullParams::ValidWatchURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_WatchURL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoResourcePullParams::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourcePullParams::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourcePullParams::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoResourcePullParams::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoResourcePullParams::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourcePullParams::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourcePullParams::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoResourcePullParams::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

JDFDisposition JDFAutoResourcePullParams::GetDispositionElem()const{
	JDFDisposition e=GetElement(elm_Disposition);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoResourcePullParams::GetCreateDispositionElem(){
	JDFDisposition e=GetCreateElement(elm_Disposition);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDisposition JDFAutoResourcePullParams::AppendDispositionElem(){
	JDFDisposition e=AppendElementN(elm_Disposition,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourcePullParams::GetMISDetails()const{
	JDFMISDetails e=GetElement(elm_MISDetails);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourcePullParams::GetCreateMISDetails(){
	JDFMISDetails e=GetCreateElement(elm_MISDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMISDetails JDFAutoResourcePullParams::AppendMISDetails(){
	JDFMISDetails e=AppendElementN(elm_MISDetails,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoResourcePullParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Disposition);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Disposition);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDispositionElem().IsValid(level)) {
				vElem.AppendUnique(elm_Disposition);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_MISDetails);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_MISDetails);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMISDetails().IsValid(level)) {
				vElem.AppendUnique(elm_MISDetails);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoResourcePullParams::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Disposition,MISDetails";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoResourcePullParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part,Disposition,MISDetails";
	};
}; // end namespace JDF
