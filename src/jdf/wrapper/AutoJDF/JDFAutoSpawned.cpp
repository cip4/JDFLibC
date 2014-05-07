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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSpawned.h"
#include "jdf/wrapper/JDFEmployee.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSpawned : public JDFAudit

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSpawned& JDFAutoSpawned::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSpawned: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSpawned::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSpawned::ValidNodeNames()const{
	return L"*:,Spawned";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoSpawned::RequiredAttributes()const{
		return JDFAudit::RequiredAttributes()+L",jRef,NewSpawnID";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoSpawned::OptionalAttributes()const{
		return JDFAudit::OptionalAttributes()+WString(L",Independent,jRefDestination,rRefsROCopied,rRefsRWCopied,Status,URL");
};

/**
 typesafe validator
*/
	vWString JDFAutoSpawned::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
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
		if(!ValidjRefDestination(level)) {
			vAtts.push_back(atr_jRefDestination);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNewSpawnID(level)) {
			vAtts.push_back(atr_NewSpawnID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidrRefsROCopied(level)) {
			vAtts.push_back(atr_rRefsROCopied);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidrRefsRWCopied(level)) {
			vAtts.push_back(atr_rRefsRWCopied);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStatus(level)) {
			vAtts.push_back(atr_Status);
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
	 void JDFAutoSpawned::SetIndependent(bool value){
	SetAttribute(atr_Independent,WString::valueOf(value));
};
/**
* Get bool attribute Independent
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoSpawned::GetIndependent() const {return GetBoolAttribute(atr_Independent,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpawned::ValidIndependent(EnumValidationLevel level) const {
		return ValidAttribute(atr_Independent,AttributeType_boolean,false);
	};
/**
* Set attribute jRef
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSpawned::SetjRef(const WString& value){
	SetAttribute(atr_jRef,value);
};
/**
* Get string attribute jRef
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSpawned::GetjRef() const {
	return GetAttribute(atr_jRef,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpawned::ValidjRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_jRef,AttributeType_IDREF,RequiredLevel(level));
	};
/**
* Set attribute jRefDestination
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSpawned::SetjRefDestination(const WString& value){
	SetAttribute(atr_jRefDestination,value);
};
/**
* Get string attribute jRefDestination
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSpawned::GetjRefDestination() const {
	return GetAttribute(atr_jRefDestination,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpawned::ValidjRefDestination(EnumValidationLevel level) const {
		return ValidAttribute(atr_jRefDestination,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute NewSpawnID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSpawned::SetNewSpawnID(const WString& value){
	SetAttribute(atr_NewSpawnID,value);
};
/**
* Get string attribute NewSpawnID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSpawned::GetNewSpawnID() const {
	return GetAttribute(atr_NewSpawnID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpawned::ValidNewSpawnID(EnumValidationLevel level) const {
		return ValidAttribute(atr_NewSpawnID,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute rRefsROCopied
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoSpawned::SetrRefsROCopied(const vWString& value){
	SetAttribute(atr_rRefsROCopied,value);
};
/**
* Get string attribute rRefsROCopied
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoSpawned::GetrRefsROCopied() const {
	return GetAttribute(atr_rRefsROCopied,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpawned::ValidrRefsROCopied(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRefsROCopied,AttributeType_IDREFS,false);
	};
/**
* Set attribute rRefsRWCopied
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoSpawned::SetrRefsRWCopied(const vWString& value){
	SetAttribute(atr_rRefsRWCopied,value);
};
/**
* Get string attribute rRefsRWCopied
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoSpawned::GetrRefsRWCopied() const {
	return GetAttribute(atr_rRefsRWCopied,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpawned::ValidrRefsRWCopied(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRefsRWCopied,AttributeType_IDREFS,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoSpawned::SetStatus( EnumStatus value){
	SetEnumAttribute(atr_Status,value,StatusString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSpawned::EnumStatus JDFAutoSpawned:: GetStatus() const {
	return (EnumStatus) GetEnumAttribute(atr_Status,StatusString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpawned::ValidStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Status,StatusString(),false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSpawned::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSpawned::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSpawned::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFEmployee JDFAutoSpawned::GetEmployee(int iSkip)const{
	JDFEmployee e=GetElement(elm_Employee,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoSpawned::GetCreateEmployee(int iSkip){
	JDFEmployee e=GetCreateElement(elm_Employee,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEmployee JDFAutoSpawned::AppendEmployee(){
	JDFEmployee e=AppendElement(elm_Employee);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoSpawned::RefEmployee(JDFEmployee& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoSpawned::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoSpawned::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoSpawned::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoSpawned::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoSpawned::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoSpawned::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoSpawned::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoSpawned::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoSpawned::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoSpawned::OptionalElements()const{
		return JDFAudit::OptionalElements()+L",Employee,Part";
	};
}; // end namespace JDF
