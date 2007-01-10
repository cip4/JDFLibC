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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPageAssignedList.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPageAssignedList : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPageAssignedList& JDFAutoPageAssignedList::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPageAssignedList: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPageAssignedList::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPageAssignedList::ValidNodeNames()const{
	return L"*:,PageAssignedList";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoPageAssignedList::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",PageListIndex";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPageAssignedList::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",BroadsheetNumber,LogicalPrinterSection,PagePlacementName");
};

/**
 typesafe validator
*/
	vWString JDFAutoPageAssignedList::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBroadsheetNumber(level)) {
			vAtts.push_back(atr_BroadsheetNumber);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLogicalPrinterSection(level)) {
			vAtts.push_back(atr_LogicalPrinterSection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageListIndex(level)) {
			vAtts.push_back(atr_PageListIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPagePlacementName(level)) {
			vAtts.push_back(atr_PagePlacementName);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BroadsheetNumber
*@param int value: the value to set the attribute to
*/
	 void JDFAutoPageAssignedList::SetBroadsheetNumber(int value){
	SetAttribute(atr_BroadsheetNumber,WString::valueOf(value));
};
/**
* Get integer attribute BroadsheetNumber
* @return int the vaue of the attribute 
*/
	 int JDFAutoPageAssignedList::GetBroadsheetNumber() const {
	return GetIntAttribute(atr_BroadsheetNumber,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageAssignedList::ValidBroadsheetNumber(EnumValidationLevel level) const {
		return ValidAttribute(atr_BroadsheetNumber,AttributeType_integer,false);
	};
/**
* Set attribute LogicalPrinterSection
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageAssignedList::SetLogicalPrinterSection(const WString& value){
	SetAttribute(atr_LogicalPrinterSection,value);
};
/**
* Get string attribute LogicalPrinterSection
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageAssignedList::GetLogicalPrinterSection() const {
	return GetAttribute(atr_LogicalPrinterSection,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageAssignedList::ValidLogicalPrinterSection(EnumValidationLevel level) const {
		return ValidAttribute(atr_LogicalPrinterSection,AttributeType_string,false);
	};
/**
* Set attribute PageListIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoPageAssignedList::SetPageListIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageListIndex,value.GetString());
};
/**
* Get range attribute PageListIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoPageAssignedList::GetPageListIndex() const {
	return GetAttribute(atr_PageListIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageAssignedList::ValidPageListIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageListIndex,AttributeType_IntegerRangeList,RequiredLevel(level));
	};
/**
* Set attribute PagePlacementName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPageAssignedList::SetPagePlacementName(const WString& value){
	SetAttribute(atr_PagePlacementName,value);
};
/**
* Get string attribute PagePlacementName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPageAssignedList::GetPagePlacementName() const {
	return GetAttribute(atr_PagePlacementName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageAssignedList::ValidPagePlacementName(EnumValidationLevel level) const {
		return ValidAttribute(atr_PagePlacementName,AttributeType_string,false);
	};
}; // end namespace JDF
