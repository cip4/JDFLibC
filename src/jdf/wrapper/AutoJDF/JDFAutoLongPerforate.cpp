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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLongPerforate.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLongPerforate : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLongPerforate& JDFAutoLongPerforate::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLongPerforate: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLongPerforate::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLongPerforate::ValidNodeNames()const{
	return L"*:,LongPerforate";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoLongPerforate::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",XOffset";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoLongPerforate::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",TeethPerDimension,WorkingList");
};

/**
 typesafe validator
*/
	vWString JDFAutoLongPerforate::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTeethPerDimension(level)) {
			vAtts.push_back(atr_TeethPerDimension);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkingList(level)) {
			vAtts.push_back(atr_WorkingList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidXOffset(level)) {
			vAtts.push_back(atr_XOffset);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute TeethPerDimension
*@param int value: the value to set the attribute to
*/
	 void JDFAutoLongPerforate::SetTeethPerDimension(int value){
	SetAttribute(atr_TeethPerDimension,WString::valueOf(value));
};
/**
* Get integer attribute TeethPerDimension
* @return int the vaue of the attribute 
*/
	 int JDFAutoLongPerforate::GetTeethPerDimension() const {
	return GetIntAttribute(atr_TeethPerDimension,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLongPerforate::ValidTeethPerDimension(EnumValidationLevel level) const {
		return ValidAttribute(atr_TeethPerDimension,AttributeType_integer,false);
	};
/**
* Set attribute WorkingList
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoLongPerforate::SetWorkingList(const JDFNumberList& value){
	SetAttribute(atr_WorkingList,value.GetString());
};
/**
* Get string attribute WorkingList
* @return JDFNumberList the vaue of the attribute ; defaults to 0 1000000000
*/
	 JDFNumberList JDFAutoLongPerforate::GetWorkingList() const {
	return GetAttribute(atr_WorkingList,WString::emptyStr,L"0 1000000000");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLongPerforate::ValidWorkingList(EnumValidationLevel level) const {
		return ValidAttribute(atr_WorkingList,AttributeType_NumberList,false);
	};
/**
* Set attribute XOffset
*@param double value: the value to set the attribute to
*/
	 void JDFAutoLongPerforate::SetXOffset(double value){
	SetAttribute(atr_XOffset,WString::valueOf(value));
};
/**
* Get double attribute XOffset
* @return double the vaue of the attribute 
*/
	 double JDFAutoLongPerforate::GetXOffset() const {
	return GetRealAttribute(atr_XOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLongPerforate::ValidXOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_XOffset,AttributeType_double,RequiredLevel(level));
	};
}; // end namespace JDF
