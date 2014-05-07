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

 
#include "jdf/wrapper/AutoJDF/JDFAutoChangedPath.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoChangedPath : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoChangedPath& JDFAutoChangedPath::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoChangedPath: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoChangedPath::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoChangedPath::ValidNodeNames()const{
	return L"*:,ChangedPath";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoChangedPath::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Path,Modification";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoChangedPath::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",OldValue,NewValue");
};

/**
 typesafe validator
*/
	vWString JDFAutoChangedPath::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPath(level)) {
			vAtts.push_back(atr_Path);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidModification(level)) {
			vAtts.push_back(atr_Modification);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOldValue(level)) {
			vAtts.push_back(atr_OldValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNewValue(level)) {
			vAtts.push_back(atr_NewValue);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Path
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChangedPath::SetPath(const WString& value){
	SetAttribute(atr_Path,value);
};
/**
* Get string attribute Path
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChangedPath::GetPath() const {
	return GetAttribute(atr_Path,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedPath::ValidPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_Path,AttributeType_XPath,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoChangedPath::ModificationString(){
		static const WString enums=WString(L"Unknown,Create,Delete,Modify");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoChangedPath::ModificationString(EnumModification value){
		return ModificationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoChangedPath::SetModification( EnumModification value){
	SetEnumAttribute(atr_Modification,value,ModificationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoChangedPath::EnumModification JDFAutoChangedPath:: GetModification() const {
	return (EnumModification) GetEnumAttribute(atr_Modification,ModificationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedPath::ValidModification(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Modification,ModificationString(),RequiredLevel(level));
	};
/**
* Set attribute OldValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChangedPath::SetOldValue(const WString& value){
	SetAttribute(atr_OldValue,value);
};
/**
* Get string attribute OldValue
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChangedPath::GetOldValue() const {
	return GetAttribute(atr_OldValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedPath::ValidOldValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_OldValue,AttributeType_string,false);
	};
/**
* Set attribute NewValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoChangedPath::SetNewValue(const WString& value){
	SetAttribute(atr_NewValue,value);
};
/**
* Get string attribute NewValue
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoChangedPath::GetNewValue() const {
	return GetAttribute(atr_NewValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoChangedPath::ValidNewValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_NewValue,AttributeType_string,false);
	};
}; // end namespace JDF
