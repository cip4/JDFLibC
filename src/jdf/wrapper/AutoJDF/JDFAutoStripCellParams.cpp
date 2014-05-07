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

 
#include "jdf/wrapper/AutoJDF/JDFAutoStripCellParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoStripCellParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoStripCellParams& JDFAutoStripCellParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoStripCellParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoStripCellParams::ValidNodeNames()const{
	return L"*:,StripCellParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoStripCellParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",BleedFace,BleedSpine,BleedHead,BleedFoot,TrimFace,Spine,TrimHead,TrimFoot,FrontOverfold,BackOverfold,MillingDepth,CutWidthHead,CutWidthFoot,TrimSize,Creep,Sides,MaskBleed,MaskSeparation,Mask")
	+WString(L"");
};

/**
 typesafe validator
*/
	vWString JDFAutoStripCellParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBleedFace(level)) {
			vAtts.push_back(atr_BleedFace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBleedSpine(level)) {
			vAtts.push_back(atr_BleedSpine);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBleedHead(level)) {
			vAtts.push_back(atr_BleedHead);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBleedFoot(level)) {
			vAtts.push_back(atr_BleedFoot);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimFace(level)) {
			vAtts.push_back(atr_TrimFace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpine(level)) {
			vAtts.push_back(atr_Spine);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimHead(level)) {
			vAtts.push_back(atr_TrimHead);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimFoot(level)) {
			vAtts.push_back(atr_TrimFoot);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontOverfold(level)) {
			vAtts.push_back(atr_FrontOverfold);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBackOverfold(level)) {
			vAtts.push_back(atr_BackOverfold);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMillingDepth(level)) {
			vAtts.push_back(atr_MillingDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutWidthHead(level)) {
			vAtts.push_back(atr_CutWidthHead);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutWidthFoot(level)) {
			vAtts.push_back(atr_CutWidthFoot);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimSize(level)) {
			vAtts.push_back(atr_TrimSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCreep(level)) {
			vAtts.push_back(atr_Creep);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSides(level)) {
			vAtts.push_back(atr_Sides);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaskBleed(level)) {
			vAtts.push_back(atr_MaskBleed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMaskSeparation(level)) {
			vAtts.push_back(atr_MaskSeparation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMask(level)) {
			vAtts.push_back(atr_Mask);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BleedFace
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetBleedFace(double value){
	SetAttribute(atr_BleedFace,WString::valueOf(value));
};
/**
* Get double attribute BleedFace
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetBleedFace() const {
	return GetRealAttribute(atr_BleedFace,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidBleedFace(EnumValidationLevel level) const {
		return ValidAttribute(atr_BleedFace,AttributeType_double,false);
	};
/**
* Set attribute BleedSpine
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetBleedSpine(double value){
	SetAttribute(atr_BleedSpine,WString::valueOf(value));
};
/**
* Get double attribute BleedSpine
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetBleedSpine() const {
	return GetRealAttribute(atr_BleedSpine,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidBleedSpine(EnumValidationLevel level) const {
		return ValidAttribute(atr_BleedSpine,AttributeType_double,false);
	};
/**
* Set attribute BleedHead
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetBleedHead(double value){
	SetAttribute(atr_BleedHead,WString::valueOf(value));
};
/**
* Get double attribute BleedHead
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetBleedHead() const {
	return GetRealAttribute(atr_BleedHead,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidBleedHead(EnumValidationLevel level) const {
		return ValidAttribute(atr_BleedHead,AttributeType_double,false);
	};
/**
* Set attribute BleedFoot
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetBleedFoot(double value){
	SetAttribute(atr_BleedFoot,WString::valueOf(value));
};
/**
* Get double attribute BleedFoot
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetBleedFoot() const {
	return GetRealAttribute(atr_BleedFoot,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidBleedFoot(EnumValidationLevel level) const {
		return ValidAttribute(atr_BleedFoot,AttributeType_double,false);
	};
/**
* Set attribute TrimFace
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetTrimFace(double value){
	SetAttribute(atr_TrimFace,WString::valueOf(value));
};
/**
* Get double attribute TrimFace
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetTrimFace() const {
	return GetRealAttribute(atr_TrimFace,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidTrimFace(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimFace,AttributeType_double,false);
	};
/**
* Set attribute Spine
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetSpine(double value){
	SetAttribute(atr_Spine,WString::valueOf(value));
};
/**
* Get double attribute Spine
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetSpine() const {
	return GetRealAttribute(atr_Spine,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidSpine(EnumValidationLevel level) const {
		return ValidAttribute(atr_Spine,AttributeType_double,false);
	};
/**
* Set attribute TrimHead
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetTrimHead(double value){
	SetAttribute(atr_TrimHead,WString::valueOf(value));
};
/**
* Get double attribute TrimHead
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetTrimHead() const {
	return GetRealAttribute(atr_TrimHead,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidTrimHead(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimHead,AttributeType_double,false);
	};
/**
* Set attribute TrimFoot
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetTrimFoot(double value){
	SetAttribute(atr_TrimFoot,WString::valueOf(value));
};
/**
* Get double attribute TrimFoot
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetTrimFoot() const {
	return GetRealAttribute(atr_TrimFoot,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidTrimFoot(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimFoot,AttributeType_double,false);
	};
/**
* Set attribute FrontOverfold
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetFrontOverfold(double value){
	SetAttribute(atr_FrontOverfold,WString::valueOf(value));
};
/**
* Get double attribute FrontOverfold
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetFrontOverfold() const {
	return GetRealAttribute(atr_FrontOverfold,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidFrontOverfold(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrontOverfold,AttributeType_double,false);
	};
/**
* Set attribute BackOverfold
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetBackOverfold(double value){
	SetAttribute(atr_BackOverfold,WString::valueOf(value));
};
/**
* Get double attribute BackOverfold
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetBackOverfold() const {
	return GetRealAttribute(atr_BackOverfold,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidBackOverfold(EnumValidationLevel level) const {
		return ValidAttribute(atr_BackOverfold,AttributeType_double,false);
	};
/**
* Set attribute MillingDepth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetMillingDepth(double value){
	SetAttribute(atr_MillingDepth,WString::valueOf(value));
};
/**
* Get double attribute MillingDepth
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetMillingDepth() const {
	return GetRealAttribute(atr_MillingDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidMillingDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_MillingDepth,AttributeType_double,false);
	};
/**
* Set attribute CutWidthHead
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetCutWidthHead(double value){
	SetAttribute(atr_CutWidthHead,WString::valueOf(value));
};
/**
* Get double attribute CutWidthHead
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetCutWidthHead() const {
	return GetRealAttribute(atr_CutWidthHead,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidCutWidthHead(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutWidthHead,AttributeType_double,false);
	};
/**
* Set attribute CutWidthFoot
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetCutWidthFoot(double value){
	SetAttribute(atr_CutWidthFoot,WString::valueOf(value));
};
/**
* Get double attribute CutWidthFoot
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetCutWidthFoot() const {
	return GetRealAttribute(atr_CutWidthFoot,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidCutWidthFoot(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutWidthFoot,AttributeType_double,false);
	};
/**
* Set attribute TrimSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetTrimSize(const JDFXYPair& value){
	SetAttribute(atr_TrimSize,value);
};
/**
* Get string attribute TrimSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoStripCellParams::GetTrimSize() const {
	return GetAttribute(atr_TrimSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidTrimSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimSize,AttributeType_XYPair,false);
	};
/**
* Set attribute Creep
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetCreep(const JDFXYPair& value){
	SetAttribute(atr_Creep,value);
};
/**
* Get string attribute Creep
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoStripCellParams::GetCreep() const {
	return GetAttribute(atr_Creep,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidCreep(EnumValidationLevel level) const {
		return ValidAttribute(atr_Creep,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStripCellParams::SidesString(){
		static const WString enums=WString(L"Unknown,OneSided,TwoSidedHeadToHead,TwoSidedHeadToFoot");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStripCellParams::SidesString(EnumSides value){
		return SidesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStripCellParams::SetSides( EnumSides value){
	SetEnumAttribute(atr_Sides,value,SidesString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStripCellParams::EnumSides JDFAutoStripCellParams:: GetSides() const {
	return (EnumSides) GetEnumAttribute(atr_Sides,SidesString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidSides(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Sides,SidesString(),false);
	};
/**
* Set attribute MaskBleed
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetMaskBleed(double value){
	SetAttribute(atr_MaskBleed,WString::valueOf(value));
};
/**
* Get double attribute MaskBleed
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripCellParams::GetMaskBleed() const {
	return GetRealAttribute(atr_MaskBleed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidMaskBleed(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaskBleed,AttributeType_double,false);
	};
/**
* Set attribute MaskSeparation
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStripCellParams::SetMaskSeparation(const WString& value){
	SetAttribute(atr_MaskSeparation,value);
};
/**
* Get string attribute MaskSeparation
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStripCellParams::GetMaskSeparation() const {
	return GetAttribute(atr_MaskSeparation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidMaskSeparation(EnumValidationLevel level) const {
		return ValidAttribute(atr_MaskSeparation,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStripCellParams::MaskString(){
		static const WString enums=WString(L"Unknown,None,TrimBox,BleedBox,SourceTrimBox,SourceBleedBox,PDL,DieCut,DieBleed");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStripCellParams::MaskString(EnumMask value){
		return MaskString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStripCellParams::SetMask( EnumMask value){
	SetEnumAttribute(atr_Mask,value,MaskString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStripCellParams::EnumMask JDFAutoStripCellParams:: GetMask() const {
	return (EnumMask) GetEnumAttribute(atr_Mask,MaskString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripCellParams::ValidMask(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Mask,MaskString(),false);
	};
}; // end namespace JDF
