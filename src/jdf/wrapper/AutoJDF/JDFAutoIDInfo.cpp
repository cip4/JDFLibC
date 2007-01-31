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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIDInfo.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFNode.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDInfo : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIDInfo& JDFAutoIDInfo::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIDInfo: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIDInfo::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIDInfo::ValidNodeNames()const{
	return L"*:,IDInfo";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIDInfo::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Category,JobID,JobPartID,ParentJobID,ParentJobPartID,Type,Types");
};

/**
 typesafe validator
*/
	vWString JDFAutoIDInfo::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCategory(level)) {
			vAtts.push_back(atr_Category);
			if(++n>=nMax)
				return vAtts;
		};
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
		if(!ValidParentJobID(level)) {
			vAtts.push_back(atr_ParentJobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidParentJobPartID(level)) {
			vAtts.push_back(atr_ParentJobPartID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTypes(level)) {
			vAtts.push_back(atr_Types);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Category
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDInfo::SetCategory(const WString& value){
	SetAttribute(atr_Category,value);
};
/**
* Get string attribute Category
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIDInfo::GetCategory() const {
	return GetAttribute(atr_Category,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDInfo::ValidCategory(EnumValidationLevel level) const {
		return ValidAttribute(atr_Category,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDInfo::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIDInfo::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDInfo::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDInfo::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIDInfo::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDInfo::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute ParentJobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDInfo::SetParentJobID(const WString& value){
	SetAttribute(atr_ParentJobID,value);
};
/**
* Get string attribute ParentJobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIDInfo::GetParentJobID() const {
	return GetAttribute(atr_ParentJobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDInfo::ValidParentJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ParentJobID,AttributeType_string,false);
	};
/**
* Set attribute ParentJobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDInfo::SetParentJobPartID(const WString& value){
	SetAttribute(atr_ParentJobPartID,value);
};
/**
* Get string attribute ParentJobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIDInfo::GetParentJobPartID() const {
	return GetAttribute(atr_ParentJobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDInfo::ValidParentJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ParentJobPartID,AttributeType_string,false);
	};
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDInfo::SetType(const WString& value){
	SetAttribute(atr_Type,value);
};
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIDInfo::GetType() const {
	return GetAttribute(atr_Type,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDInfo::ValidType(EnumValidationLevel level) const {
		return ValidAttribute(atr_Type,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Types
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoIDInfo::SetTypes(const vWString& value){
	SetAttribute(atr_Types,value);
};
/**
* Get string attribute Types
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoIDInfo::GetTypes() const {
	return GetAttribute(atr_Types,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDInfo::ValidTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_Types,AttributeType_NMTOKENS,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDevice JDFAutoIDInfo::GetDevice()const{
	JDFDevice e=GetElement(elm_Device);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoIDInfo::GetCreateDevice(){
	JDFDevice e=GetCreateElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoIDInfo::AppendDevice(){
	JDFDevice e=AppendElementN(elm_Device,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIDInfo::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoIDInfo::GetNode()const{
	JDFNode e=GetElement(elm_JDF);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoIDInfo::GetCreateNode(){
	JDFNode e=GetCreateElement(elm_JDF);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNode JDFAutoIDInfo::AppendNode(){
	JDFNode e=AppendElementN(elm_JDF,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoIDInfo::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Device);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Device);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDevice().IsValid(level)) {
				vElem.AppendUnique(elm_Device);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoIDInfo::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Device";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoIDInfo::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Device,JDF";
	};
}; // end namespace JDF
