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

 
#include "jdf/wrapper/AutoJDF/JDFAutoMerged.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoMerged : public JDFAudit

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoMerged& JDFAutoMerged::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoMerged: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoMerged::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoMerged::ValidNodeNames()const{
	return L"*:,Merged";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoMerged::RequiredAttributes()const{
		return JDFAudit::RequiredAttributes()+L",jRef,MergeID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoMerged::OptionalAttributes()const{
		return JDFAudit::OptionalAttributes()+WString(L",Independent,jRefSource,rRefsOverwritten,URL");
};

/**
 typesafe validator
*/
	vWString JDFAutoMerged::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFAudit::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidIndependent(level)) {
			vAtts.push_back(atr_Independent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidjRef(level)) {
			vAtts.push_back(atr_jRef);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidjRefSource(level)) {
			vAtts.push_back(atr_jRefSource);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMergeID(level)) {
			vAtts.push_back(atr_MergeID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidrRefsOverwritten(level)) {
			vAtts.push_back(atr_rRefsOverwritten);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURL(level)) {
			vAtts.push_back(atr_URL);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Independent
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoMerged::SetIndependent(bool value){
	SetAttribute(atr_Independent,WString::valueOf(value));
};
/**
* Get bool attribute Independent
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoMerged::GetIndependent() const {return GetBoolAttribute(atr_Independent,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMerged::ValidIndependent(EnumValidationLevel level) const {
		return ValidAttribute(atr_Independent,AttributeType_boolean,false);
	};
/**
* Set attribute jRef
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMerged::SetjRef(const WString& value){
	SetAttribute(atr_jRef,value);
};
/**
* Get string attribute jRef
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMerged::GetjRef() const {
	return GetAttribute(atr_jRef,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMerged::ValidjRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_jRef,AttributeType_IDREF,RequiredLevel(level));
	};
/**
* Set attribute jRefSource
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMerged::SetjRefSource(const WString& value){
	SetAttribute(atr_jRefSource,value);
};
/**
* Get string attribute jRefSource
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMerged::GetjRefSource() const {
	return GetAttribute(atr_jRefSource,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMerged::ValidjRefSource(EnumValidationLevel level) const {
		return ValidAttribute(atr_jRefSource,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute MergeID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMerged::SetMergeID(const WString& value){
	SetAttribute(atr_MergeID,value);
};
/**
* Get string attribute MergeID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMerged::GetMergeID() const {
	return GetAttribute(atr_MergeID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMerged::ValidMergeID(EnumValidationLevel level) const {
		return ValidAttribute(atr_MergeID,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute rRefsOverwritten
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoMerged::SetrRefsOverwritten(const vWString& value){
	SetAttribute(atr_rRefsOverwritten,value);
};
/**
* Get string attribute rRefsOverwritten
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoMerged::GetrRefsOverwritten() const {
	return GetAttribute(atr_rRefsOverwritten,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMerged::ValidrRefsOverwritten(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRefsOverwritten,AttributeType_IDREFS,false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoMerged::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoMerged::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoMerged::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFEmployee JDFAutoMerged::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoMerged::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoMerged::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoMerged::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoMerged::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoMerged::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoMerged::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoMerged::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoMerged::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoMerged::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoMerged::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoMerged::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoMerged::OptionalElements()const{
		return JDFAudit::OptionalElements()+L",Employee,Part";
	};
}; // end namespace JDF
