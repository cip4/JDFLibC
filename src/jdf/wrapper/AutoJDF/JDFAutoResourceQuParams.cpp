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

 
#include "jdf/wrapper/AutoJDF/JDFAutoResourceQuParams.h"
#include "jdf/wrapper/JDFPart.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoResourceQuParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoResourceQuParams& JDFAutoResourceQuParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoResourceQuParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoResourceQuParams::ValidNodeNames()const{
	return L"*:,ResourceQuParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoResourceQuParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Classes,Exact,JobID,JobPartID,ProcessUsage,ProductID,QueueEntryID,ResourceID,ResourceName,Usage");
};

/**
 typesafe validator
*/
	vWString JDFAutoResourceQuParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidClasses(level)) {
			vAtts.push_back(atr_Classes);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidExact(level)) {
			vAtts.push_back(atr_Exact);
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
		if(!ValidProcessUsage(level)) {
			vAtts.push_back(atr_ProcessUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProductID(level)) {
			vAtts.push_back(atr_ProductID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQueueEntryID(level)) {
			vAtts.push_back(atr_QueueEntryID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceID(level)) {
			vAtts.push_back(atr_ResourceID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidResourceName(level)) {
			vAtts.push_back(atr_ResourceName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUsage(level)) {
			vAtts.push_back(atr_Usage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceQuParams::ClassesString(){
		static const WString enums=WString(L"Unknown,Consumable,Handling,Implementation,Intent,Parameter,PlaceHolder,Quantity");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceQuParams::ClassesString(EnumClasses value){
		return ClassesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoResourceQuParams::AddClasses( EnumClasses value){
	return AddEnumerationsAttribute(atr_Classes,value,ClassesString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoResourceQuParams::RemoveClasses( EnumClasses value){
	return RemoveEnumerationsAttribute(atr_Classes,value,ClassesString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoResourceQuParams::GetClasses() const {
	return GetEnumerationsAttribute(atr_Classes,ClassesString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceQuParams::SetClasses( EnumClasses value){
	SetEnumAttribute(atr_Classes,value,ClassesString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceQuParams::SetClasses( const vint& value){
	SetEnumerationsAttribute(atr_Classes,value,ClassesString());
};
/**
* Typesafe attribute validation of Classes
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidClasses(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_Classes,ClassesString(),false);
	};
/**
* Set attribute Exact
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoResourceQuParams::SetExact(bool value){
	SetAttribute(atr_Exact,WString::valueOf(value));
};
/**
* Get bool attribute Exact
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoResourceQuParams::GetExact() const {return GetBoolAttribute(atr_Exact,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidExact(EnumValidationLevel level) const {
		return ValidAttribute(atr_Exact,AttributeType_boolean,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceQuParams::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceQuParams::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute JobPartID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceQuParams::SetJobPartID(const WString& value){
	SetAttribute(atr_JobPartID,value);
};
/**
* Get string attribute JobPartID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceQuParams::GetJobPartID() const {
	return GetAttribute(atr_JobPartID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidJobPartID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobPartID,AttributeType_shortString,false);
	};
/**
* Set attribute ProcessUsage
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceQuParams::SetProcessUsage(const WString& value){
	SetAttribute(atr_ProcessUsage,value);
};
/**
* Get string attribute ProcessUsage
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceQuParams::GetProcessUsage() const {
	return GetAttribute(atr_ProcessUsage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidProcessUsage(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProcessUsage,AttributeType_string,false);
	};
/**
* Set attribute ProductID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceQuParams::SetProductID(const WString& value){
	SetAttribute(atr_ProductID,value);
};
/**
* Get string attribute ProductID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceQuParams::GetProductID() const {
	return GetAttribute(atr_ProductID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidProductID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductID,AttributeType_shortString,false);
	};
/**
* Set attribute QueueEntryID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceQuParams::SetQueueEntryID(const WString& value){
	SetAttribute(atr_QueueEntryID,value);
};
/**
* Get string attribute QueueEntryID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceQuParams::GetQueueEntryID() const {
	return GetAttribute(atr_QueueEntryID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidQueueEntryID(EnumValidationLevel level) const {
		return ValidAttribute(atr_QueueEntryID,AttributeType_shortString,false);
	};
/**
* Set attribute ResourceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceQuParams::SetResourceID(const WString& value){
	SetAttribute(atr_ResourceID,value);
};
/**
* Get string attribute ResourceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceQuParams::GetResourceID() const {
	return GetAttribute(atr_ResourceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidResourceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceID,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute ResourceName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoResourceQuParams::SetResourceName(const WString& value){
	SetAttribute(atr_ResourceName,value);
};
/**
* Get string attribute ResourceName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoResourceQuParams::GetResourceName() const {
	return GetAttribute(atr_ResourceName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidResourceName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ResourceName,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoResourceQuParams::UsageString(){
		static const WString enums=WString(L"Unknown,Input,Output");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoResourceQuParams::UsageString(EnumUsage value){
		return UsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoResourceQuParams::SetUsage( EnumUsage value){
	SetEnumAttribute(atr_Usage,value,UsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoResourceQuParams::EnumUsage JDFAutoResourceQuParams:: GetUsage() const {
	return (EnumUsage) GetEnumAttribute(atr_Usage,UsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoResourceQuParams::ValidUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Usage,UsageString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPart JDFAutoResourceQuParams::GetPart(int iSkip)const{
	JDFPart e=GetElement(elm_Part,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceQuParams::GetCreatePart(int iSkip){
	JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPart JDFAutoResourceQuParams::AppendPart(){
	JDFPart e=AppendElement(elm_Part);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

	vmAttribute JDFAutoResourceQuParams::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}

//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceQuParams::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceQuParams::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	void JDFAutoResourceQuParams::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
//////////////////////////////////////////////////////////////////////

	bool JDFAutoResourceQuParams::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}

/**
 typesafe validator
*/
	vWString JDFAutoResourceQuParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoResourceQuParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Part";
	};
}; // end namespace JDF
