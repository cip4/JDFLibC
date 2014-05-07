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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLogicalStackParams.h"
#include "jdf/wrapper/JDFStack.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLogicalStackParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLogicalStackParams& JDFAutoLogicalStackParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLogicalStackParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLogicalStackParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLogicalStackParams::ValidNodeNames()const{
	return L"*:,LogicalStackParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoLogicalStackParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",MaxStackDepth,Restrictions");
};

/**
 typesafe validator
*/
	vWString JDFAutoLogicalStackParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMaxStackDepth(level)) {
			vAtts.push_back(atr_MaxStackDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRestrictions(level)) {
			vAtts.push_back(atr_Restrictions);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute MaxStackDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoLogicalStackParams::SetMaxStackDepth(int value){
	SetAttribute(atr_MaxStackDepth,WString::valueOf(value));
};
/**
* Get integer attribute MaxStackDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoLogicalStackParams::GetMaxStackDepth() const {
	return GetIntAttribute(atr_MaxStackDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLogicalStackParams::ValidMaxStackDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxStackDepth,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLogicalStackParams::RestrictionsString(){
		static const WString enums=WString(L"Unknown,None,WithinImposedSheetSet,WithinLogicalStack");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLogicalStackParams::RestrictionsString(EnumRestrictions value){
		return RestrictionsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLogicalStackParams::SetRestrictions( EnumRestrictions value){
	SetEnumAttribute(atr_Restrictions,value,RestrictionsString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLogicalStackParams::EnumRestrictions JDFAutoLogicalStackParams:: GetRestrictions() const {
	return (EnumRestrictions) GetEnumAttribute(atr_Restrictions,RestrictionsString(),WString::emptyStr,Restrictions_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLogicalStackParams::ValidRestrictions(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Restrictions,RestrictionsString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFStack JDFAutoLogicalStackParams::GetStack(int iSkip)const{
	JDFStack e=GetElement(elm_Stack,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStack JDFAutoLogicalStackParams::GetCreateStack(int iSkip){
	JDFStack e=GetCreateElement(elm_Stack,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStack JDFAutoLogicalStackParams::AppendStack(){
	JDFStack e=AppendElement(elm_Stack);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLogicalStackParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Stack);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_Stack);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetStack(i).IsValid(level)) {
				vElem.AppendUnique(elm_Stack);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoLogicalStackParams::RequiredElements()const{
		return JDFElement::RequiredElements()+L",Stack";
	};
}; // end namespace JDF
