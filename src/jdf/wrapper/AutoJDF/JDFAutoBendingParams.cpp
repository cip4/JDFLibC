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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBendingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBendingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBendingParams& JDFAutoBendingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBendingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBendingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBendingParams::ValidNodeNames()const{
	return L"*:,BendingParams";
};

bool JDFAutoBendingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoBendingParams::init(){
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
	WString JDFAutoBendingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Bend,Punch,PunchType");
};

/**
 typesafe validator
*/
	vWString JDFAutoBendingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBend(level)) {
			vAtts.push_back(atr_Bend);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPunch(level)) {
			vAtts.push_back(atr_Punch);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPunchType(level)) {
			vAtts.push_back(atr_PunchType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Bend
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoBendingParams::SetBend(bool value){
	SetAttribute(atr_Bend,WString::valueOf(value));
};
/**
* Get bool attribute Bend
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoBendingParams::GetBend() const {return GetBoolAttribute(atr_Bend,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBendingParams::ValidBend(EnumValidationLevel level) const {
		return ValidAttribute(atr_Bend,AttributeType_boolean,false);
	};
/**
* Set attribute Punch
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoBendingParams::SetPunch(bool value){
	SetAttribute(atr_Punch,WString::valueOf(value));
};
/**
* Get bool attribute Punch
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoBendingParams::GetPunch() const {return GetBoolAttribute(atr_Punch,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBendingParams::ValidPunch(EnumValidationLevel level) const {
		return ValidAttribute(atr_Punch,AttributeType_boolean,false);
	};
/**
* Set attribute PunchType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBendingParams::SetPunchType(const WString& value){
	SetAttribute(atr_PunchType,value);
};
/**
* Get string attribute PunchType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBendingParams::GetPunchType() const {
	return GetAttribute(atr_PunchType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBendingParams::ValidPunchType(EnumValidationLevel level) const {
		return ValidAttribute(atr_PunchType,AttributeType_string,false);
	};
}; // end namespace JDF
