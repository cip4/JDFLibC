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

 
#include "jdf/wrapper/AutoJDF/JDFAutoNodeInfoResp.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFNodeInfo.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoNodeInfoResp : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoNodeInfoResp& JDFAutoNodeInfoResp::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoNodeInfoResp: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoNodeInfoResp::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoNodeInfoResp::ValidNodeNames()const{
	return L"*:,NodeInfoResp";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoNodeInfoResp::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",JobID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoNodeInfoResp::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",JobPartID,QueueEntryID");
};

/**
 typesafe validator
*/
	vWString JDFAutoNodeInfoResp::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
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
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNodeInfoResp::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNodeInfoResp::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfoResp::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,RequiredLevel(level));
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNodeInfoResp::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNodeInfoResp::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfoResp::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNodeInfoResp::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoNodeInfoResp::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNodeInfoResp::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoNodeInfoResp::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoNodeInfoResp::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoNodeInfoResp::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoNodeInfoResp::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoNodeInfoResp::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoNodeInfoResp::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoNodeInfoResp::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoNodeInfoResp::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

JDFNodeInfo JDFAutoNodeInfoResp::GetNodeInfo()const{
	JDFNodeInfo e=GetElement(elm_NodeInfo);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNodeInfo JDFAutoNodeInfoResp::GetCreateNodeInfo(){
	JDFNodeInfo e=GetCreateElement(elm_NodeInfo);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNodeInfo JDFAutoNodeInfoResp::AppendNodeInfo(){
	JDFNodeInfo e=AppendElementN(elm_NodeInfo,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoNodeInfoResp::RefNodeInfo(JDFNodeInfo& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoNodeInfoResp::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_NodeInfo);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_NodeInfo);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetNodeInfo().IsValid(level)) {
				vElem.AppendUnique(elm_NodeInfo);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoNodeInfoResp::UniqueElements()const{
		return JDFElement::UniqueElements()+L",NodeInfo";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoNodeInfoResp::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part,NodeInfo";
	};
}; // end namespace JDF
