/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDevelopingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDevelopingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDevelopingParams& JDFAutoDevelopingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDevelopingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDevelopingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDevelopingParams::ValidNodeNames()const{
	return L"*:,DevelopingParams";
};

bool JDFAutoDevelopingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoDevelopingParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDevelopingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",PreHeatTemp,PreHeatTime,PostBakeTemp,PostBakeTime,PostExposeTime");
};

/**
 typesafe validator
*/
	vWString JDFAutoDevelopingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPreHeatTemp(level)) {
			vAtts.push_back(atr_PreHeatTemp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreHeatTime(level)) {
			vAtts.push_back(atr_PreHeatTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPostBakeTemp(level)) {
			vAtts.push_back(atr_PostBakeTemp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPostBakeTime(level)) {
			vAtts.push_back(atr_PostBakeTime);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPostExposeTime(level)) {
			vAtts.push_back(atr_PostExposeTime);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute PreHeatTemp
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDevelopingParams::SetPreHeatTemp(double value){
	SetAttribute(atr_PreHeatTemp,WString::valueOf(value));
};
/**
* Get double attribute PreHeatTemp
* @return double the vaue of the attribute 
*/
	 double JDFAutoDevelopingParams::GetPreHeatTemp() const {
	return GetRealAttribute(atr_PreHeatTemp,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevelopingParams::ValidPreHeatTemp(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreHeatTemp,AttributeType_double,false);
	};
/**
* Set attribute PreHeatTime
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoDevelopingParams::SetPreHeatTime(JDFDuration value){
	SetAttribute(atr_PreHeatTime,value.DurationISO());
};
/**
* Get string attribute PreHeatTime
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoDevelopingParams::GetPreHeatTime() const {
	return GetAttribute(atr_PreHeatTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevelopingParams::ValidPreHeatTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_PreHeatTime,AttributeType_duration,false);
	};
/**
* Set attribute PostBakeTemp
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDevelopingParams::SetPostBakeTemp(double value){
	SetAttribute(atr_PostBakeTemp,WString::valueOf(value));
};
/**
* Get double attribute PostBakeTemp
* @return double the vaue of the attribute 
*/
	 double JDFAutoDevelopingParams::GetPostBakeTemp() const {
	return GetRealAttribute(atr_PostBakeTemp,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevelopingParams::ValidPostBakeTemp(EnumValidationLevel level) const {
		return ValidAttribute(atr_PostBakeTemp,AttributeType_double,false);
	};
/**
* Set attribute PostBakeTime
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoDevelopingParams::SetPostBakeTime(JDFDuration value){
	SetAttribute(atr_PostBakeTime,value.DurationISO());
};
/**
* Get string attribute PostBakeTime
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoDevelopingParams::GetPostBakeTime() const {
	return GetAttribute(atr_PostBakeTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevelopingParams::ValidPostBakeTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_PostBakeTime,AttributeType_duration,false);
	};
/**
* Set attribute PostExposeTime
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoDevelopingParams::SetPostExposeTime(JDFDuration value){
	SetAttribute(atr_PostExposeTime,value.DurationISO());
};
/**
* Get string attribute PostExposeTime
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoDevelopingParams::GetPostExposeTime() const {
	return GetAttribute(atr_PostExposeTime,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDevelopingParams::ValidPostExposeTime(EnumValidationLevel level) const {
		return ValidAttribute(atr_PostExposeTime,AttributeType_duration,false);
	};
}; // end namespace JDF
