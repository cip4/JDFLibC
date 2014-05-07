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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDevCaps.h"
#include "jdf/wrapper/JDFDevCap.h"
#include "jdf/wrapper/JDFLoc.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDevCaps : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDevCaps& JDFAutoDevCaps::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDevCaps: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDevCaps::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDevCaps::ValidNodeNames()const{
	return L"*:,DevCaps";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoDevCaps::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Name";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDevCaps::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Availability,Context,DevCapRef,DevNS,ID,LinkUsage,ModuleRefs,ProcessUsage,Required,ResourceUpdate,ResourceUsage,TypeOccurrenceNum,Types");
};

/**
 typesafe validator
*/
	vWString JDFAutoDevCaps::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAvailability(level)) {
			vAtts.push_back(atr_Availability);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidContext(level)) {
			vAtts.push_back(atr_Context);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDevCapRef(level)) {
			vAtts.push_back(atr_DevCapRef);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDevNS(level)) {
			vAtts.push_back(atr_DevNS);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLinkUsage(level)) {
			vAtts.push_back(atr_LinkUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModuleRefs(level)) {
			vAtts.push_back(atr_ModuleRefs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProcessUsage(level)) {
			vAtts.push_back(atr_ProcessUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRequired(level)) {
			vAtts.push_back(atr_Required);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceUpdate(level)) {
			vAtts.push_back(atr_ResourceUpdate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceUsage(level)) {
			vAtts.push_back(atr_ResourceUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTypeOccurrenceNum(level)) {
			vAtts.push_back(atr_TypeOccurrenceNum);
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

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDevCaps::AvailabilityString(){
		static const WString enums=WString(L"Unknown,Installed,Module,NotInstalled,NotLicensed,Disabled");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDevCaps::AvailabilityString(EnumAvailability value){
		return AvailabilityString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDevCaps::SetAvailability( EnumAvailability value){
	SetEnumAttribute(atr_Availability,value,AvailabilityString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDevCaps::EnumAvailability JDFAutoDevCaps:: GetAvailability() const {
	return (EnumAvailability) GetEnumAttribute(atr_Availability,AvailabilityString(),WString::emptyStr,Availability_Installed);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidAvailability(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Availability,AvailabilityString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDevCaps::ContextString(){
		static const WString enums=WString(L"Unknown,Resource,Link,JMF,Element");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDevCaps::ContextString(EnumContext value){
		return ContextString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDevCaps::SetContext( EnumContext value){
	SetEnumAttribute(atr_Context,value,ContextString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDevCaps::EnumContext JDFAutoDevCaps:: GetContext() const {
	return (EnumContext) GetEnumAttribute(atr_Context,ContextString(),WString::emptyStr,Context_Resource);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidContext(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Context,ContextString(),false);
	};
/**
* Set attribute DevCapRef
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetDevCapRef(const vWString& value){
	SetAttribute(atr_DevCapRef,value);
};
/**
* Get string attribute DevCapRef
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDevCaps::GetDevCapRef() const {
	return GetAttribute(atr_DevCapRef,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidDevCapRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevCapRef,AttributeType_IDREFS,false);
	};
/**
* Set attribute DevNS
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetDevNS(const WString& value){
	SetAttribute(atr_DevNS,value);
};
/**
* Get string attribute DevNS
* @return WString the vaue of the attribute ; defaults to http://www.CIP4.org/JDFSchema_1_1
*/
	 WString JDFAutoDevCaps::GetDevNS() const {
	return GetAttribute(atr_DevNS,WString::emptyStr,L"http://www.CIP4.org/JDFSchema_1_1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidDevNS(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevNS,AttributeType_URI,false);
	};
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetID(const WString& value){
	SetAttribute(atr_ID,value);
};
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevCaps::GetID() const {
	return GetAttribute(atr_ID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDevCaps::LinkUsageString(){
		static const WString enums=WString(L"Unknown,Input,Output");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDevCaps::LinkUsageString(EnumLinkUsage value){
		return LinkUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDevCaps::SetLinkUsage( EnumLinkUsage value){
	SetEnumAttribute(atr_LinkUsage,value,LinkUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDevCaps::EnumLinkUsage JDFAutoDevCaps:: GetLinkUsage() const {
	return (EnumLinkUsage) GetEnumAttribute(atr_LinkUsage,LinkUsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidLinkUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_LinkUsage,LinkUsageString(),false);
	};
/**
* Set attribute ModuleRefs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetModuleRefs(const vWString& value){
	SetAttribute(atr_ModuleRefs,value);
};
/**
* Get string attribute ModuleRefs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDevCaps::GetModuleRefs() const {
	return GetAttribute(atr_ModuleRefs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidModuleRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_ModuleRefs,AttributeType_IDREFS,false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevCaps::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute ProcessUsage
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetProcessUsage(const WString& value){
	SetAttribute(atr_ProcessUsage,value);
};
/**
* Get string attribute ProcessUsage
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevCaps::GetProcessUsage() const {
	return GetAttribute(atr_ProcessUsage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidProcessUsage(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProcessUsage,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Required
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetRequired(bool value){
	SetAttribute(atr_Required,WString::valueOf(value));
};
/**
* Get bool attribute Required
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoDevCaps::GetRequired() const {return GetBoolAttribute(atr_Required,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidRequired(EnumValidationLevel level) const {
		return ValidAttribute(atr_Required,AttributeType_boolean,false);
	};
/**
* Set attribute ResourceUpdate
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetResourceUpdate(const vWString& value){
	SetAttribute(atr_ResourceUpdate,value);
};
/**
* Get string attribute ResourceUpdate
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDevCaps::GetResourceUpdate() const {
	return GetAttribute(atr_ResourceUpdate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidResourceUpdate(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceUpdate,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute ResourceUsage
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetResourceUsage(const WString& value){
	SetAttribute(atr_ResourceUsage,value);
};
/**
* Get string attribute ResourceUsage
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDevCaps::GetResourceUsage() const {
	return GetAttribute(atr_ResourceUsage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidResourceUsage(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceUsage,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute TypeOccurrenceNum
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetTypeOccurrenceNum(const JDFIntegerRangeList& value){
	SetAttribute(atr_TypeOccurrenceNum,value.GetString());
};
/**
* Get range attribute TypeOccurrenceNum
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoDevCaps::GetTypeOccurrenceNum() const {
	return GetAttribute(atr_TypeOccurrenceNum,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidTypeOccurrenceNum(EnumValidationLevel level) const {
		return ValidAttribute(atr_TypeOccurrenceNum,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute Types
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoDevCaps::SetTypes(const vWString& value){
	SetAttribute(atr_Types,value);
};
/**
* Get string attribute Types
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoDevCaps::GetTypes() const {
	return GetAttribute(atr_Types,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevCaps::ValidTypes(EnumValidationLevel level) const {
		return ValidAttribute(atr_Types,AttributeType_NMTOKENS,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDevCap JDFAutoDevCaps::GetDevCap(int iSkip)const{
	JDFDevCap e=GetElement(elm_DevCap,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCap JDFAutoDevCaps::GetCreateDevCap(int iSkip){
	JDFDevCap e=GetCreateElement(elm_DevCap,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevCap JDFAutoDevCaps::AppendDevCap(){
	JDFDevCap e=AppendElement(elm_DevCap);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoDevCaps::GetLoc(int iSkip)const{
	JDFLoc e=GetElement(elm_Loc,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoDevCaps::GetCreateLoc(int iSkip){
	JDFLoc e=GetCreateElement(elm_Loc,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLoc JDFAutoDevCaps::AppendLoc(){
	JDFLoc e=AppendElement(elm_Loc);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDevCaps::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_DevCap);

		for(i=0;i<nElem;i++){
			if (!GetDevCap(i).IsValid(level)) {
				vElem.AppendUnique(elm_DevCap);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Loc);

		for(i=0;i<nElem;i++){
			if (!GetLoc(i).IsValid(level)) {
				vElem.AppendUnique(elm_Loc);
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
	WString JDFAutoDevCaps::OptionalElements()const{
		return JDFElement::OptionalElements()+L",DevCap,Loc";
	};
}; // end namespace JDF
