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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDBSelection.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDBSelection : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDBSelection& JDFAutoDBSelection::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDBSelection: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDBSelection::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDBSelection::ValidNodeNames()const{
	return L"*:,DBSelection";
};

bool JDFAutoDBSelection::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoDBSelection::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoDBSelection::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",DataBase";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDBSelection::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Records,Select");
};

/**
 typesafe validator
*/
	vWString JDFAutoDBSelection::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDataBase(level)) {
			vAtts.push_back(atr_DataBase);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRecords(level)) {
			vAtts.push_back(atr_Records);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSelect(level)) {
			vAtts.push_back(atr_Select);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DataBase
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDBSelection::SetDataBase(const WString& value){
	SetAttribute(atr_DataBase,value);
};
/**
* Get string attribute DataBase
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDBSelection::GetDataBase() const {
	return GetAttribute(atr_DataBase,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDBSelection::ValidDataBase(EnumValidationLevel level) const {
		return ValidAttribute(atr_DataBase,AttributeType_URL,RequiredLevel(level));
	};
/**
* Set attribute Records
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoDBSelection::SetRecords(const JDFIntegerRangeList& value){
	SetAttribute(atr_Records,value.GetString());
};
/**
* Get range attribute Records
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoDBSelection::GetRecords() const {
	return GetAttribute(atr_Records,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDBSelection::ValidRecords(EnumValidationLevel level) const {
		return ValidAttribute(atr_Records,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute Select
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDBSelection::SetSelect(const WString& value){
	SetAttribute(atr_Select,value);
};
/**
* Get string attribute Select
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDBSelection::GetSelect() const {
	return GetAttribute(atr_Select,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDBSelection::ValidSelect(EnumValidationLevel level) const {
		return ValidAttribute(atr_Select,AttributeType_string,false);
	};
}; // end namespace JDF
