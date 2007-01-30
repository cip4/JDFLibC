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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIcon.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIcon : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIcon& JDFAutoIcon::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIcon: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIcon::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIcon::ValidNodeNames()const{
	return L"*:,Icon";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoIcon::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Size,BitDepth";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIcon::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",IconUsage");
};

/**
 typesafe validator
*/
	vWString JDFAutoIcon::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidSize(level)) {
			vAtts.push_back(atr_Size);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBitDepth(level)) {
			vAtts.push_back(atr_BitDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidIconUsage(level)) {
			vAtts.push_back(atr_IconUsage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Size
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoIcon::SetSize(const JDFXYPair& value){
	SetAttribute(atr_Size,value);
};
/**
* Get string attribute Size
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoIcon::GetSize() const {
	return GetAttribute(atr_Size,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIcon::ValidSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_Size,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute BitDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoIcon::SetBitDepth(int value){
	SetAttribute(atr_BitDepth,WString::valueOf(value));
};
/**
* Get integer attribute BitDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoIcon::GetBitDepth() const {
	return GetIntAttribute(atr_BitDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIcon::ValidBitDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_BitDepth,AttributeType_integer,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIcon::IconUsageString(){
		static const WString enums=WString(L"Unknown,Idle,Down,Setup,Running,Cleanup,Stopped");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIcon::IconUsageString(EnumIconUsage value){
		return IconUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoIcon::AddIconUsage( EnumIconUsage value){
	return AddEnumerationsAttribute(atr_IconUsage,value,IconUsageString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoIcon::RemoveIconUsage( EnumIconUsage value){
	return RemoveEnumerationsAttribute(atr_IconUsage,value,IconUsageString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoIcon::GetIconUsage() const {
	return GetEnumerationsAttribute(atr_IconUsage,IconUsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoIcon::SetIconUsage( EnumIconUsage value){
	SetEnumAttribute(atr_IconUsage,value,IconUsageString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoIcon::SetIconUsage( const vint& value){
	SetEnumerationsAttribute(atr_IconUsage,value,IconUsageString());
};
/**
* Typesafe attribute validation of IconUsage
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIcon::ValidIconUsage(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_IconUsage,IconUsageString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoIcon::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoIcon::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoIcon::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIcon::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoIcon::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoIcon::OptionalElements()const{
		return JDFElement::OptionalElements()+L",FileSpec";
	};
}; // end namespace JDF
