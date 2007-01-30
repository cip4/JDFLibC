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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColorCorrectionOp.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorCorrectionOp : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColorCorrectionOp& JDFAutoColorCorrectionOp::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColorCorrectionOp: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColorCorrectionOp::ValidNodeNames()const{
	return L"*:,ColorCorrectionOp";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoColorCorrectionOp::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",SourceObjects,AdjustCyanRed,AdjustMagentaGreen,AdjustYellowBlue,AdjustContrast,AdjustHue,AdjustLightness,AdjustSaturation");
};

/**
 typesafe validator
*/
	vWString JDFAutoColorCorrectionOp::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidSourceObjects(level)) {
			vAtts.push_back(atr_SourceObjects);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdjustCyanRed(level)) {
			vAtts.push_back(atr_AdjustCyanRed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdjustMagentaGreen(level)) {
			vAtts.push_back(atr_AdjustMagentaGreen);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdjustYellowBlue(level)) {
			vAtts.push_back(atr_AdjustYellowBlue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdjustContrast(level)) {
			vAtts.push_back(atr_AdjustContrast);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdjustHue(level)) {
			vAtts.push_back(atr_AdjustHue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdjustLightness(level)) {
			vAtts.push_back(atr_AdjustLightness);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAdjustSaturation(level)) {
			vAtts.push_back(atr_AdjustSaturation);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorCorrectionOp::SourceObjectsString(){
		static const WString enums=WString(L"Unknown,All,ImagePhotographic,ImageScreenShot,Text,LineArt,SmoothShades");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorCorrectionOp::SourceObjectsString(EnumSourceObjects value){
		return SourceObjectsString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	vint JDFAutoColorCorrectionOp::AddSourceObjects( EnumSourceObjects value){
	return AddEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoColorCorrectionOp::RemoveSourceObjects( EnumSourceObjects value){
	return RemoveEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	vint JDFAutoColorCorrectionOp::GetSourceObjects() const {
	return GetEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),WString::emptyStr,(unsigned int)SourceObjects_All);
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorCorrectionOp::SetSourceObjects( EnumSourceObjects value){
	SetEnumAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorCorrectionOp::SetSourceObjects( const vint& value){
	SetEnumerationsAttribute(atr_SourceObjects,value,SourceObjectsString());
};
/**
* Typesafe attribute validation of SourceObjects
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::ValidSourceObjects(EnumValidationLevel level) const {
		return ValidEnumerationsAttribute(atr_SourceObjects,SourceObjectsString(),false);
	};
/**
* Set attribute AdjustCyanRed
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorCorrectionOp::SetAdjustCyanRed(double value){
	SetAttribute(atr_AdjustCyanRed,WString::valueOf(value));
};
/**
* Get double attribute AdjustCyanRed
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorCorrectionOp::GetAdjustCyanRed() const {
	return GetRealAttribute(atr_AdjustCyanRed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::ValidAdjustCyanRed(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdjustCyanRed,AttributeType_double,false);
	};
/**
* Set attribute AdjustMagentaGreen
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorCorrectionOp::SetAdjustMagentaGreen(double value){
	SetAttribute(atr_AdjustMagentaGreen,WString::valueOf(value));
};
/**
* Get double attribute AdjustMagentaGreen
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorCorrectionOp::GetAdjustMagentaGreen() const {
	return GetRealAttribute(atr_AdjustMagentaGreen,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::ValidAdjustMagentaGreen(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdjustMagentaGreen,AttributeType_double,false);
	};
/**
* Set attribute AdjustYellowBlue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorCorrectionOp::SetAdjustYellowBlue(double value){
	SetAttribute(atr_AdjustYellowBlue,WString::valueOf(value));
};
/**
* Get double attribute AdjustYellowBlue
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorCorrectionOp::GetAdjustYellowBlue() const {
	return GetRealAttribute(atr_AdjustYellowBlue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::ValidAdjustYellowBlue(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdjustYellowBlue,AttributeType_double,false);
	};
/**
* Set attribute AdjustContrast
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorCorrectionOp::SetAdjustContrast(double value){
	SetAttribute(atr_AdjustContrast,WString::valueOf(value));
};
/**
* Get double attribute AdjustContrast
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorCorrectionOp::GetAdjustContrast() const {
	return GetRealAttribute(atr_AdjustContrast,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::ValidAdjustContrast(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdjustContrast,AttributeType_double,false);
	};
/**
* Set attribute AdjustHue
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorCorrectionOp::SetAdjustHue(double value){
	SetAttribute(atr_AdjustHue,WString::valueOf(value));
};
/**
* Get double attribute AdjustHue
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorCorrectionOp::GetAdjustHue() const {
	return GetRealAttribute(atr_AdjustHue,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::ValidAdjustHue(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdjustHue,AttributeType_double,false);
	};
/**
* Set attribute AdjustLightness
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorCorrectionOp::SetAdjustLightness(double value){
	SetAttribute(atr_AdjustLightness,WString::valueOf(value));
};
/**
* Get double attribute AdjustLightness
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorCorrectionOp::GetAdjustLightness() const {
	return GetRealAttribute(atr_AdjustLightness,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::ValidAdjustLightness(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdjustLightness,AttributeType_double,false);
	};
/**
* Set attribute AdjustSaturation
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorCorrectionOp::SetAdjustSaturation(double value){
	SetAttribute(atr_AdjustSaturation,WString::valueOf(value));
};
/**
* Get double attribute AdjustSaturation
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorCorrectionOp::GetAdjustSaturation() const {
	return GetRealAttribute(atr_AdjustSaturation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorCorrectionOp::ValidAdjustSaturation(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdjustSaturation,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoColorCorrectionOp::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColorCorrectionOp::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColorCorrectionOp::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorCorrectionOp::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoColorCorrectionOp::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_FileSpec);

		for(i=0;i<nElem;i++){
			if (!GetFileSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
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
	WString JDFAutoColorCorrectionOp::OptionalElements()const{
		return JDFElement::OptionalElements()+L",FileSpec";
	};
}; // end namespace JDF
