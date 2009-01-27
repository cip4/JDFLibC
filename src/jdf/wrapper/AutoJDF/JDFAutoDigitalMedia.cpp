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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDigitalMedia.h"
#include "jdf/wrapper/JDFRunList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDigitalMedia : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDigitalMedia& JDFAutoDigitalMedia::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDigitalMedia: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDigitalMedia::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDigitalMedia::ValidNodeNames()const{
	return L"*:,DigitalMedia";
};

bool JDFAutoDigitalMedia::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Handling;
};

bool JDFAutoDigitalMedia::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Handling);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoDigitalMedia::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",MediaType";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDigitalMedia::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Capacity,MediaLabel,MediaTypeDetails");
};

/**
 typesafe validator
*/
	vWString JDFAutoDigitalMedia::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMediaType(level)) {
			vAtts.push_back(atr_MediaType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCapacity(level)) {
			vAtts.push_back(atr_Capacity);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaLabel(level)) {
			vAtts.push_back(atr_MediaLabel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMediaTypeDetails(level)) {
			vAtts.push_back(atr_MediaTypeDetails);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute MediaType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDigitalMedia::SetMediaType(const WString& value){
	SetAttribute(atr_MediaType,value);
};
/**
* Get string attribute MediaType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDigitalMedia::GetMediaType() const {
	return GetAttribute(atr_MediaType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalMedia::ValidMediaType(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaType,AttributeType_NMTOKEN,RequiredLevel(level));
	};
/**
* Set attribute Capacity
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDigitalMedia::SetCapacity(int value){
	SetAttribute(atr_Capacity,WString::valueOf(value));
};
/**
* Get integer attribute Capacity
* @return int the vaue of the attribute 
*/
	 int JDFAutoDigitalMedia::GetCapacity() const {
	return GetIntAttribute(atr_Capacity,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalMedia::ValidCapacity(EnumValidationLevel level) const {
		return ValidAttribute(atr_Capacity,AttributeType_integer,false);
	};
/**
* Set attribute MediaLabel
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDigitalMedia::SetMediaLabel(const WString& value){
	SetAttribute(atr_MediaLabel,value);
};
/**
* Get string attribute MediaLabel
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDigitalMedia::GetMediaLabel() const {
	return GetAttribute(atr_MediaLabel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalMedia::ValidMediaLabel(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaLabel,AttributeType_string,false);
	};
/**
* Set attribute MediaTypeDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDigitalMedia::SetMediaTypeDetails(const WString& value){
	SetAttribute(atr_MediaTypeDetails,value);
};
/**
* Get string attribute MediaTypeDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDigitalMedia::GetMediaTypeDetails() const {
	return GetAttribute(atr_MediaTypeDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDigitalMedia::ValidMediaTypeDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_MediaTypeDetails,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFRunList JDFAutoDigitalMedia::GetRunList()const{
	JDFRunList e=GetElement(elm_RunList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoDigitalMedia::GetCreateRunList(){
	JDFRunList e=GetCreateElement(elm_RunList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRunList JDFAutoDigitalMedia::AppendRunList(){
	JDFRunList e=AppendElementN(elm_RunList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDigitalMedia::RefRunList(JDFRunList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDigitalMedia::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_RunList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_RunList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetRunList().IsValid(level)) {
				vElem.AppendUnique(elm_RunList);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoDigitalMedia::UniqueElements()const{
		return JDFResource::UniqueElements()+L",RunList";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoDigitalMedia::OptionalElements()const{
		return JDFResource::OptionalElements()+L",RunList";
	};
}; // end namespace JDF
