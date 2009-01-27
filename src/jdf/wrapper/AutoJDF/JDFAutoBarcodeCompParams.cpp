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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBarcodeCompParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBarcodeCompParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBarcodeCompParams& JDFAutoBarcodeCompParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBarcodeCompParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBarcodeCompParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBarcodeCompParams::ValidNodeNames()const{
	return L"*:,BarcodeCompParams";
};

bool JDFAutoBarcodeCompParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoBarcodeCompParams::init(){
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
	WString JDFAutoBarcodeCompParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",CompensationProcess";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBarcodeCompParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",CompensationValue");
};

/**
 typesafe validator
*/
	vWString JDFAutoBarcodeCompParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCompensationProcess(level)) {
			vAtts.push_back(atr_CompensationProcess);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompensationValue(level)) {
			vAtts.push_back(atr_CompensationValue);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBarcodeCompParams::CompensationProcessString(){
		static const WString enums=WString(L"Unknown,Printing,Platemaking");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBarcodeCompParams::CompensationProcessString(EnumCompensationProcess value){
		return CompensationProcessString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBarcodeCompParams::SetCompensationProcess( EnumCompensationProcess value){
	SetEnumAttribute(atr_CompensationProcess,value,CompensationProcessString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBarcodeCompParams::EnumCompensationProcess JDFAutoBarcodeCompParams:: GetCompensationProcess() const {
	return (EnumCompensationProcess) GetEnumAttribute(atr_CompensationProcess,CompensationProcessString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeCompParams::ValidCompensationProcess(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CompensationProcess,CompensationProcessString(),RequiredLevel(level));
	};
/**
* Set attribute CompensationValue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoBarcodeCompParams::SetCompensationValue(double value){
	SetAttribute(atr_CompensationValue,WString::valueOf(value));
};
/**
* Get double attribute CompensationValue
* @return double the vaue of the attribute 
*/
	 double JDFAutoBarcodeCompParams::GetCompensationValue() const {
	return GetRealAttribute(atr_CompensationValue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBarcodeCompParams::ValidCompensationValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_CompensationValue,AttributeType_double,false);
	};
}; // end namespace JDF
