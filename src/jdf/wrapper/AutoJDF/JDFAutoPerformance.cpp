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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPerformance.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPerformance : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPerformance& JDFAutoPerformance::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPerformance: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPerformance::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPerformance::ValidNodeNames()const{
	return L"*:,Performance";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPerformance::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AverageAmount,AverageCleanup,AverageSetup,MaxAmount,MaxCleanup,MaxSetup,MinAmount,MinCleanup,MinSetup,Name,DevCapsRef,Unit");
};

/**
 typesafe validator
*/
	vWString JDFAutoPerformance::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAverageAmount(level)) {
			vAtts.push_back(atr_AverageAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAverageCleanup(level)) {
			vAtts.push_back(atr_AverageCleanup);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAverageSetup(level)) {
			vAtts.push_back(atr_AverageSetup);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxAmount(level)) {
			vAtts.push_back(atr_MaxAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxCleanup(level)) {
			vAtts.push_back(atr_MaxCleanup);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaxSetup(level)) {
			vAtts.push_back(atr_MaxSetup);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinAmount(level)) {
			vAtts.push_back(atr_MinAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinCleanup(level)) {
			vAtts.push_back(atr_MinCleanup);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMinSetup(level)) {
			vAtts.push_back(atr_MinSetup);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDevCapsRef(level)) {
			vAtts.push_back(atr_DevCapsRef);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUnit(level)) {
			vAtts.push_back(atr_Unit);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AverageAmount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetAverageAmount(double value){
	SetAttribute(atr_AverageAmount,WString::valueOf(value));
};
/**
* Get double attribute AverageAmount
* @return double the vaue of the attribute 
*/
	 double JDFAutoPerformance::GetAverageAmount() const {
	return GetRealAttribute(atr_AverageAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidAverageAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_AverageAmount,AttributeType_double,false);
	};
/**
* Set attribute AverageCleanup
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetAverageCleanup(JDFDuration value){
	SetAttribute(atr_AverageCleanup,value.DurationISO());
};
/**
* Get string attribute AverageCleanup
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoPerformance::GetAverageCleanup() const {
	return GetAttribute(atr_AverageCleanup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidAverageCleanup(EnumValidationLevel level) const {
		return ValidAttribute(atr_AverageCleanup,AttributeType_duration,false);
	};
/**
* Set attribute AverageSetup
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetAverageSetup(JDFDuration value){
	SetAttribute(atr_AverageSetup,value.DurationISO());
};
/**
* Get string attribute AverageSetup
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoPerformance::GetAverageSetup() const {
	return GetAttribute(atr_AverageSetup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidAverageSetup(EnumValidationLevel level) const {
		return ValidAttribute(atr_AverageSetup,AttributeType_duration,false);
	};
/**
* Set attribute MaxAmount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetMaxAmount(double value){
	SetAttribute(atr_MaxAmount,WString::valueOf(value));
};
/**
* Get double attribute MaxAmount
* @return double the vaue of the attribute 
*/
	 double JDFAutoPerformance::GetMaxAmount() const {
	return GetRealAttribute(atr_MaxAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidMaxAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxAmount,AttributeType_double,false);
	};
/**
* Set attribute MaxCleanup
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetMaxCleanup(JDFDuration value){
	SetAttribute(atr_MaxCleanup,value.DurationISO());
};
/**
* Get string attribute MaxCleanup
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoPerformance::GetMaxCleanup() const {
	return GetAttribute(atr_MaxCleanup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidMaxCleanup(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxCleanup,AttributeType_duration,false);
	};
/**
* Set attribute MaxSetup
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetMaxSetup(JDFDuration value){
	SetAttribute(atr_MaxSetup,value.DurationISO());
};
/**
* Get string attribute MaxSetup
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoPerformance::GetMaxSetup() const {
	return GetAttribute(atr_MaxSetup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidMaxSetup(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaxSetup,AttributeType_duration,false);
	};
/**
* Set attribute MinAmount
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetMinAmount(double value){
	SetAttribute(atr_MinAmount,WString::valueOf(value));
};
/**
* Get double attribute MinAmount
* @return double the vaue of the attribute 
*/
	 double JDFAutoPerformance::GetMinAmount() const {
	return GetRealAttribute(atr_MinAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidMinAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinAmount,AttributeType_double,false);
	};
/**
* Set attribute MinCleanup
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetMinCleanup(JDFDuration value){
	SetAttribute(atr_MinCleanup,value.DurationISO());
};
/**
* Get string attribute MinCleanup
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoPerformance::GetMinCleanup() const {
	return GetAttribute(atr_MinCleanup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidMinCleanup(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinCleanup,AttributeType_duration,false);
	};
/**
* Set attribute MinSetup
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetMinSetup(JDFDuration value){
	SetAttribute(atr_MinSetup,value.DurationISO());
};
/**
* Get string attribute MinSetup
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoPerformance::GetMinSetup() const {
	return GetAttribute(atr_MinSetup,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidMinSetup(EnumValidationLevel level) const {
		return ValidAttribute(atr_MinSetup,AttributeType_duration,false);
	};
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerformance::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute DevCapsRef
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetDevCapsRef(const WString& value){
	SetAttribute(atr_DevCapsRef,value);
};
/**
* Get string attribute DevCapsRef
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerformance::GetDevCapsRef() const {
	return GetAttribute(atr_DevCapsRef,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidDevCapsRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_DevCapsRef,AttributeType_IDREF,false);
	};
/**
* Set attribute Unit
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPerformance::SetUnit(const WString& value){
	SetAttribute(atr_Unit,value);
};
/**
* Get string attribute Unit
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPerformance::GetUnit() const {
	return GetAttribute(atr_Unit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPerformance::ValidUnit(EnumValidationLevel level) const {
		return ValidAttribute(atr_Unit,AttributeType_NMTOKEN,false);
	};
}; // end namespace JDF
