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

 
#include "jdf/wrapper/AutoJDF/JDFAutoRequestQueueEntryParams.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFQueue.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRequestQueueEntryParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoRequestQueueEntryParams& JDFAutoRequestQueueEntryParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoRequestQueueEntryParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoRequestQueueEntryParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoRequestQueueEntryParams::ValidNodeNames()const{
	return L"*:,RequestQueueEntryParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoRequestQueueEntryParams::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",QueueURL";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoRequestQueueEntryParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",JobID,JobPartID,SubmitPolicy");
};

/**
 typesafe validator
*/
	vWString JDFAutoRequestQueueEntryParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobPartID(level)) {
			vAtts.push_back(atr_JobPartID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueURL(level)) {
			vAtts.push_back(atr_QueueURL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSubmitPolicy(level)) {
			vAtts.push_back(atr_SubmitPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRequestQueueEntryParams::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRequestQueueEntryParams::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRequestQueueEntryParams::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRequestQueueEntryParams::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRequestQueueEntryParams::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRequestQueueEntryParams::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute QueueURL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoRequestQueueEntryParams::SetQueueURL(const WString& value){
	SetAttribute(atr_QueueURL,value);
};
/**
* Get string attribute QueueURL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoRequestQueueEntryParams::GetQueueURL() const {
	return GetAttribute(atr_QueueURL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRequestQueueEntryParams::ValidQueueURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueURL,AttributeType_URL,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoRequestQueueEntryParams::SubmitPolicyString(){
		static const WString enums=WString(L"Unknown,Standard,Late,Force");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoRequestQueueEntryParams::SubmitPolicyString(EnumSubmitPolicy value){
		return SubmitPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRequestQueueEntryParams::SetSubmitPolicy( EnumSubmitPolicy value){
	SetEnumAttribute(atr_SubmitPolicy,value,SubmitPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRequestQueueEntryParams::EnumSubmitPolicy JDFAutoRequestQueueEntryParams:: GetSubmitPolicy() const {
	return (EnumSubmitPolicy) GetEnumAttribute(atr_SubmitPolicy,SubmitPolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRequestQueueEntryParams::ValidSubmitPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SubmitPolicy,SubmitPolicyString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoRequestQueueEntryParams::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoRequestQueueEntryParams::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoRequestQueueEntryParams::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoRequestQueueEntryParams::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoRequestQueueEntryParams::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoRequestQueueEntryParams::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoRequestQueueEntryParams::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoRequestQueueEntryParams::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

JDFQueue JDFAutoRequestQueueEntryParams::GetQueue()const{
	JDFQueue e=GetElement(elm_Queue);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQueue JDFAutoRequestQueueEntryParams::GetCreateQueue(){
	JDFQueue e=GetCreateElement(elm_Queue);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQueue JDFAutoRequestQueueEntryParams::AppendQueue(){
	JDFQueue e=AppendElementN(elm_Queue,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoRequestQueueEntryParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Queue);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Queue);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetQueue().IsValid(level)) {
				vElem.AppendUnique(elm_Queue);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoRequestQueueEntryParams::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Queue";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoRequestQueueEntryParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part,Queue";
	};
}; // end namespace JDF
