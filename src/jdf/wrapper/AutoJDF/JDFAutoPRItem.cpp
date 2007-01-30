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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPRItem.h"
#include "jdf/wrapper/JDFPRError.h"
#include "jdf/wrapper/JDFPRGroup.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPRItem : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPRItem& JDFAutoPRItem::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPRItem: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPRItem::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPRItem::ValidNodeNames()const{
	return L"*:,PRItem";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoPRItem::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ActionRef,Occurrences";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPRItem::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",PageSet");
};

/**
 typesafe validator
*/
	vWString JDFAutoPRItem::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidActionRef(level)) {
			vAtts.push_back(atr_ActionRef);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOccurrences(level)) {
			vAtts.push_back(atr_Occurrences);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageSet(level)) {
			vAtts.push_back(atr_PageSet);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ActionRef
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPRItem::SetActionRef(const WString& value){
	SetAttribute(atr_ActionRef,value);
};
/**
* Get string attribute ActionRef
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPRItem::GetActionRef() const {
	return GetAttribute(atr_ActionRef,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRItem::ValidActionRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_ActionRef,AttributeType_IDREF,RequiredLevel(level));
	};
/**
* Set attribute Occurrences
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPRItem::SetOccurrences(int value){
	SetAttribute(atr_Occurrences,WString::valueOf(value));
};
/**
* Get integer attribute Occurrences
* @return int the vaue of the attribute 
*/
	 int JDFAutoPRItem::GetOccurrences() const {
	return GetIntAttribute(atr_Occurrences,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRItem::ValidOccurrences(EnumValidationLevel level) const {
		return ValidAttribute(atr_Occurrences,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute PageSet
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPRItem::SetPageSet(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageSet,value.GetString());
};
/**
* Get range attribute PageSet
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPRItem::GetPageSet() const {
	return GetAttribute(atr_PageSet,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPRItem::ValidPageSet(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageSet,AttributeType_IntegerRangeList,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPRError JDFAutoPRItem::GetPRError(int iSkip)const{
	JDFPRError e=GetElement(elm_PRError,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRError JDFAutoPRItem::GetCreatePRError(int iSkip){
	JDFPRError e=GetCreateElement(elm_PRError,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRError JDFAutoPRItem::AppendPRError(){
	JDFPRError e=AppendElement(elm_PRError);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRGroup JDFAutoPRItem::GetPRGroup(int iSkip)const{
	JDFPRGroup e=GetElement(elm_PRGroup,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRGroup JDFAutoPRItem::GetCreatePRGroup(int iSkip){
	JDFPRGroup e=GetCreateElement(elm_PRGroup,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPRGroup JDFAutoPRItem::AppendPRGroup(){
	JDFPRGroup e=AppendElement(elm_PRGroup);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPRItem::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_PRError);

		for(i=0;i<nElem;i++){
			if (!GetPRError(i).IsValid(level)) {
				vElem.AppendUnique(elm_PRError);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PRGroup);

		for(i=0;i<nElem;i++){
			if (!GetPRGroup(i).IsValid(level)) {
				vElem.AppendUnique(elm_PRGroup);
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
	WString JDFAutoPRItem::OptionalElements()const{
		return JDFElement::OptionalElements()+L",PRError,PRGroup";
	};
}; // end namespace JDF
