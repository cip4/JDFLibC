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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPDFInterpretingParams.h"
#include "jdf/wrapper/JDFOCGControl.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPDFInterpretingParams : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPDFInterpretingParams& JDFAutoPDFInterpretingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPDFInterpretingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPDFInterpretingParams::ValidNodeNames()const{
	return L"*:,PDFInterpretingParams";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPDFInterpretingParams::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",EmitPDFBG,EmitPDFHalftones,EmitPDFTransfers,EmitPDFUCR,HonorPDFOverprint,ICCColorAsDeviceColor,OCGDefault,OCGIntent,OCGProcess,OCGZoom,PrintPDFAnnotations,TransparencyRenderingQuality");
};

/**
 typesafe validator
*/
	vWString JDFAutoPDFInterpretingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidEmitPDFBG(level)) {
			vAtts.push_back(atr_EmitPDFBG);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmitPDFHalftones(level)) {
			vAtts.push_back(atr_EmitPDFHalftones);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmitPDFTransfers(level)) {
			vAtts.push_back(atr_EmitPDFTransfers);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidEmitPDFUCR(level)) {
			vAtts.push_back(atr_EmitPDFUCR);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHonorPDFOverprint(level)) {
			vAtts.push_back(atr_HonorPDFOverprint);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidICCColorAsDeviceColor(level)) {
			vAtts.push_back(atr_ICCColorAsDeviceColor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOCGDefault(level)) {
			vAtts.push_back(atr_OCGDefault);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOCGIntent(level)) {
			vAtts.push_back(atr_OCGIntent);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOCGProcess(level)) {
			vAtts.push_back(atr_OCGProcess);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOCGZoom(level)) {
			vAtts.push_back(atr_OCGZoom);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPrintPDFAnnotations(level)) {
			vAtts.push_back(atr_PrintPDFAnnotations);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransparencyRenderingQuality(level)) {
			vAtts.push_back(atr_TransparencyRenderingQuality);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute EmitPDFBG
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetEmitPDFBG(bool value){
	SetAttribute(atr_EmitPDFBG,WString::valueOf(value));
};
/**
* Get bool attribute EmitPDFBG
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFInterpretingParams::GetEmitPDFBG() const {return GetBoolAttribute(atr_EmitPDFBG,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidEmitPDFBG(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmitPDFBG,AttributeType_boolean,false);
	};
/**
* Set attribute EmitPDFHalftones
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetEmitPDFHalftones(bool value){
	SetAttribute(atr_EmitPDFHalftones,WString::valueOf(value));
};
/**
* Get bool attribute EmitPDFHalftones
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFInterpretingParams::GetEmitPDFHalftones() const {return GetBoolAttribute(atr_EmitPDFHalftones,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidEmitPDFHalftones(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmitPDFHalftones,AttributeType_boolean,false);
	};
/**
* Set attribute EmitPDFTransfers
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetEmitPDFTransfers(bool value){
	SetAttribute(atr_EmitPDFTransfers,WString::valueOf(value));
};
/**
* Get bool attribute EmitPDFTransfers
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFInterpretingParams::GetEmitPDFTransfers() const {return GetBoolAttribute(atr_EmitPDFTransfers,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidEmitPDFTransfers(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmitPDFTransfers,AttributeType_boolean,false);
	};
/**
* Set attribute EmitPDFUCR
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetEmitPDFUCR(bool value){
	SetAttribute(atr_EmitPDFUCR,WString::valueOf(value));
};
/**
* Get bool attribute EmitPDFUCR
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFInterpretingParams::GetEmitPDFUCR() const {return GetBoolAttribute(atr_EmitPDFUCR,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidEmitPDFUCR(EnumValidationLevel level) const {
		return ValidAttribute(atr_EmitPDFUCR,AttributeType_boolean,false);
	};
/**
* Set attribute HonorPDFOverprint
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetHonorPDFOverprint(bool value){
	SetAttribute(atr_HonorPDFOverprint,WString::valueOf(value));
};
/**
* Get bool attribute HonorPDFOverprint
* @return bool the vaue of the attribute ; defaults to true
*/
	 bool JDFAutoPDFInterpretingParams::GetHonorPDFOverprint() const {return GetBoolAttribute(atr_HonorPDFOverprint,WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidHonorPDFOverprint(EnumValidationLevel level) const {
		return ValidAttribute(atr_HonorPDFOverprint,AttributeType_boolean,false);
	};
/**
* Set attribute ICCColorAsDeviceColor
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetICCColorAsDeviceColor(bool value){
	SetAttribute(atr_ICCColorAsDeviceColor,WString::valueOf(value));
};
/**
* Get bool attribute ICCColorAsDeviceColor
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFInterpretingParams::GetICCColorAsDeviceColor() const {return GetBoolAttribute(atr_ICCColorAsDeviceColor,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidICCColorAsDeviceColor(EnumValidationLevel level) const {
		return ValidAttribute(atr_ICCColorAsDeviceColor,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFInterpretingParams::OCGDefaultString(){
		static const WString enums=WString(L"Unknown,Exclude,FromPDF,Include");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFInterpretingParams::OCGDefaultString(EnumOCGDefault value){
		return OCGDefaultString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFInterpretingParams::SetOCGDefault( EnumOCGDefault value){
	SetEnumAttribute(atr_OCGDefault,value,OCGDefaultString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFInterpretingParams::EnumOCGDefault JDFAutoPDFInterpretingParams:: GetOCGDefault() const {
	return (EnumOCGDefault) GetEnumAttribute(atr_OCGDefault,OCGDefaultString(),WString::emptyStr,OCGDefault_FromPDF);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidOCGDefault(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_OCGDefault,OCGDefaultString(),false);
	};
/**
* Set attribute OCGIntent
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetOCGIntent(const WString& value){
	SetAttribute(atr_OCGIntent,value);
};
/**
* Get string attribute OCGIntent
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPDFInterpretingParams::GetOCGIntent() const {
	return GetAttribute(atr_OCGIntent,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidOCGIntent(EnumValidationLevel level) const {
		return ValidAttribute(atr_OCGIntent,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPDFInterpretingParams::OCGProcessString(){
		static const WString enums=WString(L"Unknown,Export,Print,View");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPDFInterpretingParams::OCGProcessString(EnumOCGProcess value){
		return OCGProcessString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPDFInterpretingParams::SetOCGProcess( EnumOCGProcess value){
	SetEnumAttribute(atr_OCGProcess,value,OCGProcessString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPDFInterpretingParams::EnumOCGProcess JDFAutoPDFInterpretingParams:: GetOCGProcess() const {
	return (EnumOCGProcess) GetEnumAttribute(atr_OCGProcess,OCGProcessString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidOCGProcess(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_OCGProcess,OCGProcessString(),false);
	};
/**
* Set attribute OCGZoom
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetOCGZoom(double value){
	SetAttribute(atr_OCGZoom,WString::valueOf(value));
};
/**
* Get double attribute OCGZoom
* @return double the vaue of the attribute ; defaults to 1.0
*/
	 double JDFAutoPDFInterpretingParams::GetOCGZoom() const {
	return GetRealAttribute(atr_OCGZoom,WString::emptyStr,1.0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidOCGZoom(EnumValidationLevel level) const {
		return ValidAttribute(atr_OCGZoom,AttributeType_double,false);
	};
/**
* Set attribute PrintPDFAnnotations
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetPrintPDFAnnotations(bool value){
	SetAttribute(atr_PrintPDFAnnotations,WString::valueOf(value));
};
/**
* Get bool attribute PrintPDFAnnotations
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoPDFInterpretingParams::GetPrintPDFAnnotations() const {return GetBoolAttribute(atr_PrintPDFAnnotations,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidPrintPDFAnnotations(EnumValidationLevel level) const {
		return ValidAttribute(atr_PrintPDFAnnotations,AttributeType_boolean,false);
	};
/**
* Set attribute TransparencyRenderingQuality
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPDFInterpretingParams::SetTransparencyRenderingQuality(double value){
	SetAttribute(atr_TransparencyRenderingQuality,WString::valueOf(value));
};
/**
* Get double attribute TransparencyRenderingQuality
* @return double the vaue of the attribute 
*/
	 double JDFAutoPDFInterpretingParams::GetTransparencyRenderingQuality() const {
	return GetRealAttribute(atr_TransparencyRenderingQuality,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDFInterpretingParams::ValidTransparencyRenderingQuality(EnumValidationLevel level) const {
		return ValidAttribute(atr_TransparencyRenderingQuality,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFOCGControl JDFAutoPDFInterpretingParams::GetOCGControl(int iSkip)const{
	JDFOCGControl e=GetElement(elm_OCGControl,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOCGControl JDFAutoPDFInterpretingParams::GetCreateOCGControl(int iSkip){
	JDFOCGControl e=GetCreateElement(elm_OCGControl,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOCGControl JDFAutoPDFInterpretingParams::AppendOCGControl(){
	JDFOCGControl e=AppendElement(elm_OCGControl);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPDFInterpretingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_OCGControl);

		for(i=0;i<nElem;i++){
			if (!GetOCGControl(i).IsValid(level)) {
				vElem.AppendUnique(elm_OCGControl);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPDFInterpretingParams::OptionalElements()const{
		return JDFElement::OptionalElements()+L",OCGControl";
	};
}; // end namespace JDF
