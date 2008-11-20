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

 
#include "jdf/wrapper/AutoJDF/JDFAutoStitchingParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoStitchingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoStitchingParams& JDFAutoStitchingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoStitchingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoStitchingParams::ValidNodeNames()const{
	return L"*:,StitchingParams";
};

bool JDFAutoStitchingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoStitchingParams::init(){
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
	WString JDFAutoStitchingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",StitchOrigin,Angle,NumberOfStitches,Offset,ReferenceEdge,StapleShape,StitchFromFront,StitchPositions,StitchType,StitchWidth,WireGauge,WireBrand");
};

/**
 typesafe validator
*/
	vWString JDFAutoStitchingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidStitchOrigin(level)) {
			vAtts.push_back(atr_StitchOrigin);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAngle(level)) {
			vAtts.push_back(atr_Angle);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberOfStitches(level)) {
			vAtts.push_back(atr_NumberOfStitches);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOffset(level)) {
			vAtts.push_back(atr_Offset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReferenceEdge(level)) {
			vAtts.push_back(atr_ReferenceEdge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStapleShape(level)) {
			vAtts.push_back(atr_StapleShape);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStitchFromFront(level)) {
			vAtts.push_back(atr_StitchFromFront);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStitchPositions(level)) {
			vAtts.push_back(atr_StitchPositions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStitchType(level)) {
			vAtts.push_back(atr_StitchType);
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

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStitchingParams::StitchOriginString(){
		static const WString enums=WString(L"Unknown,TrimBoxCenter,TrimBoxJogSide,UntrimmedJogSide");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStitchingParams::StitchOriginString(EnumStitchOrigin value){
		return StitchOriginString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStitchingParams::SetStitchOrigin( EnumStitchOrigin value){
	SetEnumAttribute(atr_StitchOrigin,value,StitchOriginString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStitchingParams::EnumStitchOrigin JDFAutoStitchingParams:: GetStitchOrigin() const {
	return (EnumStitchOrigin) GetEnumAttribute(atr_StitchOrigin,StitchOriginString(),WString::emptyStr,StitchOrigin_UntrimmedJogSide);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidStitchOrigin(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StitchOrigin,StitchOriginString(),false);
	};
/**
* Set attribute Angle
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStitchingParams::SetAngle(double value){
	SetAttribute(atr_Angle,WString::valueOf(value));
};
/**
* Get double attribute Angle
* @return double the vaue of the attribute 
*/
	 double JDFAutoStitchingParams::GetAngle() const {
	return GetRealAttribute(atr_Angle,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidAngle(EnumValidationLevel level) const {
		return ValidAttribute(atr_Angle,AttributeType_double,false);
	};
/**
* Set attribute NumberOfStitches
*@param int value: the value to set the attribute to
*/
	 void JDFAutoStitchingParams::SetNumberOfStitches(int value){
	SetAttribute(atr_NumberOfStitches,WString::valueOf(value));
};
/**
* Get integer attribute NumberOfStitches
* @return int the vaue of the attribute 
*/
	 int JDFAutoStitchingParams::GetNumberOfStitches() const {
	return GetIntAttribute(atr_NumberOfStitches,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidNumberOfStitches(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberOfStitches,AttributeType_integer,false);
	};
/**
* Set attribute Offset
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStitchingParams::SetOffset(double value){
	SetAttribute(atr_Offset,WString::valueOf(value));
};
/**
* Get double attribute Offset
* @return double the vaue of the attribute 
*/
	 double JDFAutoStitchingParams::GetOffset() const {
	return GetRealAttribute(atr_Offset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_Offset,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStitchingParams::ReferenceEdgeString(){
		static const WString enums=WString(L"Unknown,Top,Left,Right,Bottom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStitchingParams::ReferenceEdgeString(EnumReferenceEdge value){
		return ReferenceEdgeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStitchingParams::SetReferenceEdge( EnumReferenceEdge value){
	SetEnumAttribute(atr_ReferenceEdge,value,ReferenceEdgeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStitchingParams::EnumReferenceEdge JDFAutoStitchingParams:: GetReferenceEdge() const {
	return (EnumReferenceEdge) GetEnumAttribute(atr_ReferenceEdge,ReferenceEdgeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidReferenceEdge(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ReferenceEdge,ReferenceEdgeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStitchingParams::StapleShapeString(){
		static const WString enums=WString(L"Unknown,Crown,Overlap,Butted,ClinchOut,Eyelet");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStitchingParams::StapleShapeString(EnumStapleShape value){
		return StapleShapeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStitchingParams::SetStapleShape( EnumStapleShape value){
	SetEnumAttribute(atr_StapleShape,value,StapleShapeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStitchingParams::EnumStapleShape JDFAutoStitchingParams:: GetStapleShape() const {
	return (EnumStapleShape) GetEnumAttribute(atr_StapleShape,StapleShapeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidStapleShape(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StapleShape,StapleShapeString(),false);
	};
/**
* Set attribute StitchFromFront
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoStitchingParams::SetStitchFromFront(bool value){
	SetAttribute(atr_StitchFromFront,WString::valueOf(value));
};
/**
* Get bool attribute StitchFromFront
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoStitchingParams::GetStitchFromFront() const {return GetBoolAttribute(atr_StitchFromFront,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidStitchFromFront(EnumValidationLevel level) const {
		return ValidAttribute(atr_StitchFromFront,AttributeType_boolean,false);
	};
/**
* Set attribute StitchPositions
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoStitchingParams::SetStitchPositions(const JDFNumberList& value){
	SetAttribute(atr_StitchPositions,value.GetString());
};
/**
* Get string attribute StitchPositions
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoStitchingParams::GetStitchPositions() const {
	return GetAttribute(atr_StitchPositions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidStitchPositions(EnumValidationLevel level) const {
		return ValidAttribute(atr_StitchPositions,AttributeType_NumberList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStitchingParams::StitchTypeString(){
		static const WString enums=WString(L"Unknown,Saddle,Side,Corner");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStitchingParams::StitchTypeString(EnumStitchType value){
		return StitchTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStitchingParams::SetStitchType( EnumStitchType value){
	SetEnumAttribute(atr_StitchType,value,StitchTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStitchingParams::EnumStitchType JDFAutoStitchingParams:: GetStitchType() const {
	return (EnumStitchType) GetEnumAttribute(atr_StitchType,StitchTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidStitchType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_StitchType,StitchTypeString(),false);
	};
/**
* Set attribute StitchWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStitchingParams::SetStitchWidth(double value){
	SetAttribute(atr_StitchWidth,WString::valueOf(value));
};
/**
* Get double attribute StitchWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoStitchingParams::GetStitchWidth() const {
	return GetRealAttribute(atr_StitchWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidStitchWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_StitchWidth,AttributeType_double,false);
	};
/**
* Set attribute WireGauge
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStitchingParams::SetWireGauge(double value){
	SetAttribute(atr_WireGauge,WString::valueOf(value));
};
/**
* Get double attribute WireGauge
* @return double the vaue of the attribute 
*/
	 double JDFAutoStitchingParams::GetWireGauge() const {
	return GetRealAttribute(atr_WireGauge,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidWireGauge(EnumValidationLevel level) const {
		return ValidAttribute(atr_WireGauge,AttributeType_double,false);
	};
/**
* Set attribute WireBrand
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStitchingParams::SetWireBrand(const WString& value){
	SetAttribute(atr_WireBrand,value);
};
/**
* Get string attribute WireBrand
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStitchingParams::GetWireBrand() const {
	return GetAttribute(atr_WireBrand,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStitchingParams::ValidWireBrand(EnumValidationLevel level) const {
		return ValidAttribute(atr_WireBrand,AttributeType_string,false);
	};
}; // end namespace JDF
