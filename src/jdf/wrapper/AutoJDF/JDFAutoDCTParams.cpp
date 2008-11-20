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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDCTParams.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDCTParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDCTParams& JDFAutoDCTParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDCTParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDCTParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDCTParams::ValidNodeNames()const{
	return L"*:,DCTParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoDCTParams::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",SourceCSs";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDCTParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",HSamples,VSamples,QFactor,QuantTable,HuffTable,ColorTransform");
};

/**
 typesafe validator
*/
	vWString JDFAutoDCTParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidSourceCSs(level)) {
			vAtts.push_back(atr_SourceCSs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHSamples(level)) {
			vAtts.push_back(atr_HSamples);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVSamples(level)) {
			vAtts.push_back(atr_VSamples);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQFactor(level)) {
			vAtts.push_back(atr_QFactor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidQuantTable(level)) {
			vAtts.push_back(atr_QuantTable);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHuffTable(level)) {
			vAtts.push_back(atr_HuffTable);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorTransform(level)) {
			vAtts.push_back(atr_ColorTransform);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDCTParams::SourceCSsString(){
		static const WString enums=WString(L"Unknown,CalGray,CalRGB,Calibrated,CIEBased,CMYK,DeviceN,DevIndep,RGB,Gray")
	+WString(L",ICCBased,ICCCMYK,ICCGray,ICCLAB,ICCRGB,Lab,Separtation,YUV");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDCTParams::SourceCSsString(EnumSourceCSs value){
		return SourceCSsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoDCTParams::AddSourceCSs( EnumSourceCSs value){
	return AddEnumerationsAttribute(atr_SourceCSs,value,SourceCSsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoDCTParams::RemoveSourceCSs( EnumSourceCSs value){
	return RemoveEnumerationsAttribute(atr_SourceCSs,value,SourceCSsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoDCTParams::GetSourceCSs() const {
	return GetEnumerationsAttribute(atr_SourceCSs,SourceCSsString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoDCTParams::SetSourceCSs( EnumSourceCSs value){
	SetEnumAttribute(atr_SourceCSs,value,SourceCSsString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoDCTParams::SetSourceCSs( const vint& value){
	SetEnumerationsAttribute(atr_SourceCSs,value,SourceCSsString());
};
/**
* Typesafe attribute validation of SourceCSs
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDCTParams::ValidSourceCSs(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_SourceCSs,SourceCSsString(),RequiredLevel(level));
	};
/**
* Set attribute HSamples
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoDCTParams::SetHSamples(const JDFIntegerList& value){
	SetAttribute(atr_HSamples,value.GetString());
};
/**
* Get string attribute HSamples
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoDCTParams::GetHSamples() const {
	return GetAttribute(atr_HSamples,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDCTParams::ValidHSamples(EnumValidationLevel level) const {
		return ValidAttribute(atr_HSamples,AttributeType_IntegerList,false);
	};
/**
* Set attribute VSamples
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoDCTParams::SetVSamples(const JDFIntegerList& value){
	SetAttribute(atr_VSamples,value.GetString());
};
/**
* Get string attribute VSamples
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoDCTParams::GetVSamples() const {
	return GetAttribute(atr_VSamples,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDCTParams::ValidVSamples(EnumValidationLevel level) const {
		return ValidAttribute(atr_VSamples,AttributeType_IntegerList,false);
	};
/**
* Set attribute QFactor
*@param double value: the value to set the attribute to
*/
	 void JDFAutoDCTParams::SetQFactor(double value){
	SetAttribute(atr_QFactor,WString::valueOf(value));
};
/**
* Get double attribute QFactor
* @return double the vaue of the attribute ; defaults to 1.0
*/
	 double JDFAutoDCTParams::GetQFactor() const {
	return GetRealAttribute(atr_QFactor,WString::emptyStr,1.0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDCTParams::ValidQFactor(EnumValidationLevel level) const {
		return ValidAttribute(atr_QFactor,AttributeType_double,false);
	};
/**
* Set attribute QuantTable
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoDCTParams::SetQuantTable(const JDFNumberList& value){
	SetAttribute(atr_QuantTable,value.GetString());
};
/**
* Get string attribute QuantTable
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoDCTParams::GetQuantTable() const {
	return GetAttribute(atr_QuantTable,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDCTParams::ValidQuantTable(EnumValidationLevel level) const {
		return ValidAttribute(atr_QuantTable,AttributeType_NumberList,false);
	};
/**
* Set attribute HuffTable
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoDCTParams::SetHuffTable(const JDFNumberList& value){
	SetAttribute(atr_HuffTable,value.GetString());
};
/**
* Get string attribute HuffTable
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoDCTParams::GetHuffTable() const {
	return GetAttribute(atr_HuffTable,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDCTParams::ValidHuffTable(EnumValidationLevel level) const {
		return ValidAttribute(atr_HuffTable,AttributeType_NumberList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoDCTParams::ColorTransformString(){
		static const WString enums=WString(L"Unknown,YUV,None,Automatic");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoDCTParams::ColorTransformString(EnumColorTransform value){
		return ColorTransformString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoDCTParams::SetColorTransform( EnumColorTransform value){
	SetEnumAttribute(atr_ColorTransform,value,ColorTransformString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoDCTParams::EnumColorTransform JDFAutoDCTParams:: GetColorTransform() const {
	return (EnumColorTransform) GetEnumAttribute(atr_ColorTransform,ColorTransformString(),WString::emptyStr,ColorTransform_Automatic);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDCTParams::ValidColorTransform(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ColorTransform,ColorTransformString(),false);
	};
}; // end namespace JDF
