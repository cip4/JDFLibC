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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSaddleStitchingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSaddleStitchingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSaddleStitchingParams& JDFAutoSaddleStitchingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSaddleStitchingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSaddleStitchingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSaddleStitchingParams::ValidNodeNames()const{
	return L"*:,SaddleStitchingParams";
};

bool JDFAutoSaddleStitchingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoSaddleStitchingParams::init(){
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
	WString JDFAutoSaddleStitchingParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",NumberOfStitches";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoSaddleStitchingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",StitchPositions,StapleShape,StitchWidth,WireGauge,WireBrand");
};

/**
 typesafe validator
*/
	vWString JDFAutoSaddleStitchingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidNumberOfStitches(level)) {
			vAtts.push_back(atr_NumberOfStitches);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStitchPositions(level)) {
			vAtts.push_back(atr_StitchPositions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStapleShape(level)) {
			vAtts.push_back(atr_StapleShape);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStitchWidth(level)) {
			vAtts.push_back(atr_StitchWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWireGauge(level)) {
			vAtts.push_back(atr_WireGauge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWireBrand(level)) {
			vAtts.push_back(atr_WireBrand);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute NumberOfStitches
*@param int value: the value to set the attribute to
*/
	 void JDFAutoSaddleStitchingParams::SetNumberOfStitches(int value){
	SetAttribute(atr_NumberOfStitches,WString::valueOf(value));
};
/**
* Get integer attribute NumberOfStitches
* @return int the vaue of the attribute 
*/
	 int JDFAutoSaddleStitchingParams::GetNumberOfStitches() const {
	return GetIntAttribute(atr_NumberOfStitches,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSaddleStitchingParams::ValidNumberOfStitches(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberOfStitches,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute StitchPositions
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoSaddleStitchingParams::SetStitchPositions(const JDFNumberList& value){
	SetAttribute(atr_StitchPositions,value.GetString());
};
/**
* Get string attribute StitchPositions
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoSaddleStitchingParams::GetStitchPositions() const {
	return GetAttribute(atr_StitchPositions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSaddleStitchingParams::ValidStitchPositions(EnumValidationLevel level) const {
		return ValidAttribute(atr_StitchPositions,AttributeType_NumberList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSaddleStitchingParams::StapleShapeString(){
		static const WString enums=WString(L"Unknown,Crown,Overlap,Butted,ClinchOut,Eyelet");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSaddleStitchingParams::StapleShapeString(EnumStapleShape value){
		return StapleShapeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSaddleStitchingParams::SetStapleShape( EnumStapleShape value){
	SetEnumAttribute(atr_StapleShape,value,StapleShapeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSaddleStitchingParams::EnumStapleShape JDFAutoSaddleStitchingParams:: GetStapleShape() const {
	return (EnumStapleShape) GetEnumAttribute(atr_StapleShape,StapleShapeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSaddleStitchingParams::ValidStapleShape(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StapleShape,StapleShapeString(),false);
	};
/**
* Set attribute StitchWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSaddleStitchingParams::SetStitchWidth(double value){
	SetAttribute(atr_StitchWidth,WString::valueOf(value));
};
/**
* Get double attribute StitchWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoSaddleStitchingParams::GetStitchWidth() const {
	return GetRealAttribute(atr_StitchWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSaddleStitchingParams::ValidStitchWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_StitchWidth,AttributeType_double,false);
	};
/**
* Set attribute WireGauge
*@param double value: the value to set the attribute to
*/
	 void JDFAutoSaddleStitchingParams::SetWireGauge(double value){
	SetAttribute(atr_WireGauge,WString::valueOf(value));
};
/**
* Get double attribute WireGauge
* @return double the vaue of the attribute 
*/
	 double JDFAutoSaddleStitchingParams::GetWireGauge() const {
	return GetRealAttribute(atr_WireGauge,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSaddleStitchingParams::ValidWireGauge(EnumValidationLevel level) const {
		return ValidAttribute(atr_WireGauge,AttributeType_double,false);
	};
/**
* Set attribute WireBrand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoSaddleStitchingParams::SetWireBrand(const WString& value){
	SetAttribute(atr_WireBrand,value);
};
/**
* Get string attribute WireBrand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoSaddleStitchingParams::GetWireBrand() const {
	return GetAttribute(atr_WireBrand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSaddleStitchingParams::ValidWireBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_WireBrand,AttributeType_string,false);
	};
}; // end namespace JDF
