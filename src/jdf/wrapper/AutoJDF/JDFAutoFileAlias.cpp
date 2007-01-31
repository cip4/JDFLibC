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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFileAlias.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFileAlias : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFileAlias& JDFAutoFileAlias::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFileAlias: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFileAlias::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFileAlias::ValidNodeNames()const{
	return L"*:,FileAlias";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoFileAlias::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Alias";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoFileAlias::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Disposition,MimeType,RawAlias,URL");
};

/**
 typesafe validator
*/
	vWString JDFAutoFileAlias::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAlias(level)) {
			vAtts.push_back(atr_Alias);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDisposition(level)) {
			vAtts.push_back(atr_Disposition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMimeType(level)) {
			vAtts.push_back(atr_MimeType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRawAlias(level)) {
			vAtts.push_back(atr_RawAlias);
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
* Set attribute Alias
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileAlias::SetAlias(const WString& value){
	SetAttribute(atr_Alias,value);
};
/**
* Get string attribute Alias
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileAlias::GetAlias() const {
	return GetAttribute(atr_Alias,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileAlias::ValidAlias(EnumValidationLevel level) const {
		return ValidAttribute(atr_Alias,AttributeType_string,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFileAlias::DispositionString(){
		static const WString enums=WString(L"Unknown,Unlink,Delete,Retain");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFileAlias::DispositionString(EnumDisposition value){
		return DispositionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFileAlias::SetDisposition( EnumDisposition value){
	SetEnumAttribute(atr_Disposition,value,DispositionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFileAlias::EnumDisposition JDFAutoFileAlias:: GetDisposition() const {
	return (EnumDisposition) GetEnumAttribute(atr_Disposition,DispositionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileAlias::ValidDisposition(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Disposition,DispositionString(),false);
	};
/**
* Set attribute MimeType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileAlias::SetMimeType(const WString& value){
	SetAttribute(atr_MimeType,value);
};
/**
* Get string attribute MimeType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileAlias::GetMimeType() const {
	return GetAttribute(atr_MimeType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileAlias::ValidMimeType(EnumValidationLevel level) const {
		return ValidAttribute(atr_MimeType,AttributeType_string,false);
	};
/**
* Set attribute RawAlias
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileAlias::SetRawAlias(const WString& value){
	SetAttribute(atr_RawAlias,value);
};
/**
* Get string attribute RawAlias
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileAlias::GetRawAlias() const {
	return GetAttribute(atr_RawAlias,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileAlias::ValidRawAlias(EnumValidationLevel level) const {
		return ValidAttribute(atr_RawAlias,AttributeType_hexBinary,false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFileAlias::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFileAlias::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFileAlias::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoFileAlias::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoFileAlias::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoFileAlias::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoFileAlias::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoFileAlias::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_FileSpec);

		for(i=0;i<nElem;i++){
			if (!GetFileSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
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
	WString JDFAutoFileAlias::OptionalElements()const{
		return JDFElement::OptionalElements()+L",FileSpec";
	};
}; // end namespace JDF
