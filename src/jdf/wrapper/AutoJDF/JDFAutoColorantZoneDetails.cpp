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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColorantZoneDetails.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorantZoneDetails : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColorantZoneDetails& JDFAutoColorantZoneDetails::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColorantZoneDetails: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColorantZoneDetails::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColorantZoneDetails::ValidNodeNames()const{
	return L"*:,ColorantZoneDetails";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoColorantZoneDetails::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Colorant";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoColorantZoneDetails::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",StepLimit,TrapColorScaling");
};

/**
 typesafe validator
*/
	vWString JDFAutoColorantZoneDetails::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidColorant(level)) {
			vAtts.push_back(atr_Colorant);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStepLimit(level)) {
			vAtts.push_back(atr_StepLimit);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapColorScaling(level)) {
			vAtts.push_back(atr_TrapColorScaling);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Colorant
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColorantZoneDetails::SetColorant(const WString& value){
	SetAttribute(atr_Colorant,value);
};
/**
* Get string attribute Colorant
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColorantZoneDetails::GetColorant() const {
	return GetAttribute(atr_Colorant,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorantZoneDetails::ValidColorant(EnumValidationLevel level) const {
		return ValidAttribute(atr_Colorant,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute StepLimit
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorantZoneDetails::SetStepLimit(double value){
	SetAttribute(atr_StepLimit,WString::valueOf(value));
};
/**
* Get double attribute StepLimit
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorantZoneDetails::GetStepLimit() const {
	return GetRealAttribute(atr_StepLimit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorantZoneDetails::ValidStepLimit(EnumValidationLevel level) const {
		return ValidAttribute(atr_StepLimit,AttributeType_double,false);
	};
/**
* Set attribute TrapColorScaling
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorantZoneDetails::SetTrapColorScaling(double value){
	SetAttribute(atr_TrapColorScaling,WString::valueOf(value));
};
/**
* Get double attribute TrapColorScaling
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorantZoneDetails::GetTrapColorScaling() const {
	return GetRealAttribute(atr_TrapColorScaling,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorantZoneDetails::ValidTrapColorScaling(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrapColorScaling,AttributeType_double,false);
	};
}; // end namespace JDF
