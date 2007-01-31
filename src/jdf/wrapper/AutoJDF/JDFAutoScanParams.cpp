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

 
#include "jdf/wrapper/AutoJDF/JDFAutoScanParams.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoScanParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoScanParams& JDFAutoScanParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoScanParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoScanParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoScanParams::ValidNodeNames()const{
	return L"*:,ScanParams";
};

bool JDFAutoScanParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoScanParams::init(){
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
	WString JDFAutoScanParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",BitDepth,OutputColorSpace";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoScanParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Magnification,CompressionFilter,DCTQuality,InputBox,MountID,Mounting,OutputResolution,OutputSize,SplitDocuments");
};

/**
 typesafe validator
*/
	vWString JDFAutoScanParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBitDepth(level)) {
			vAtts.push_back(atr_BitDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMagnification(level)) {
			vAtts.push_back(atr_Magnification);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutputColorSpace(level)) {
			vAtts.push_back(atr_OutputColorSpace);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompressionFilter(level)) {
			vAtts.push_back(atr_CompressionFilter);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDCTQuality(level)) {
			vAtts.push_back(atr_DCTQuality);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInputBox(level)) {
			vAtts.push_back(atr_InputBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMountID(level)) {
			vAtts.push_back(atr_MountID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMounting(level)) {
			vAtts.push_back(atr_Mounting);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutputResolution(level)) {
			vAtts.push_back(atr_OutputResolution);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutputSize(level)) {
			vAtts.push_back(atr_OutputSize);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSplitDocuments(level)) {
			vAtts.push_back(atr_SplitDocuments);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BitDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoScanParams::SetBitDepth(int value){
	SetAttribute(atr_BitDepth,WString::valueOf(value));
};
/**
* Get integer attribute BitDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoScanParams::GetBitDepth() const {
	return GetIntAttribute(atr_BitDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidBitDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_BitDepth,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute Magnification
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoScanParams::SetMagnification(const JDFXYPair& value){
	SetAttribute(atr_Magnification,value);
};
/**
* Get string attribute Magnification
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	 JDFXYPair JDFAutoScanParams::GetMagnification() const {
	return GetAttribute(atr_Magnification,WString::emptyStr,L"1 1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidMagnification(EnumValidationLevel level) const {
		return ValidAttribute(atr_Magnification,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoScanParams::OutputColorSpaceString(){
		static const WString enums=WString(L"Unknown,LAB,RGB,CMYK,GrayScale");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoScanParams::OutputColorSpaceString(EnumOutputColorSpace value){
		return OutputColorSpaceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoScanParams::SetOutputColorSpace( EnumOutputColorSpace value){
	SetEnumAttribute(atr_OutputColorSpace,value,OutputColorSpaceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoScanParams::EnumOutputColorSpace JDFAutoScanParams:: GetOutputColorSpace() const {
	return (EnumOutputColorSpace) GetEnumAttribute(atr_OutputColorSpace,OutputColorSpaceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidOutputColorSpace(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_OutputColorSpace,OutputColorSpaceString(),RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoScanParams::CompressionFilterString(){
		static const WString enums=WString(L"Unknown,CCITTFaxEncode,DCTEncode,FlateEncode,WaveletEncode,JBIG2Encode");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoScanParams::CompressionFilterString(EnumCompressionFilter value){
		return CompressionFilterString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoScanParams::SetCompressionFilter( EnumCompressionFilter value){
	SetEnumAttribute(atr_CompressionFilter,value,CompressionFilterString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoScanParams::EnumCompressionFilter JDFAutoScanParams:: GetCompressionFilter() const {
	return (EnumCompressionFilter) GetEnumAttribute(atr_CompressionFilter,CompressionFilterString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidCompressionFilter(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_CompressionFilter,CompressionFilterString(),false);
	};
/**
* Set attribute DCTQuality
*@param double value: the value to set the attribute to
*/
	 void JDFAutoScanParams::SetDCTQuality(double value){
	SetAttribute(atr_DCTQuality,WString::valueOf(value));
};
/**
* Get double attribute DCTQuality
* @return double the vaue of the attribute 
*/
	 double JDFAutoScanParams::GetDCTQuality() const {
	return GetRealAttribute(atr_DCTQuality,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidDCTQuality(EnumValidationLevel level) const {
		return ValidAttribute(atr_DCTQuality,AttributeType_double,false);
	};
/**
* Set attribute InputBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoScanParams::SetInputBox(const JDFRectangle& value){
	SetAttribute(atr_InputBox,value);
};
/**
* Get string attribute InputBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoScanParams::GetInputBox() const {
	return GetAttribute(atr_InputBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidInputBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_InputBox,AttributeType_rectangle,false);
	};
/**
* Set attribute MountID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoScanParams::SetMountID(const WString& value){
	SetAttribute(atr_MountID,value);
};
/**
* Get string attribute MountID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoScanParams::GetMountID() const {
	return GetAttribute(atr_MountID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidMountID(EnumValidationLevel level) const {
		return ValidAttribute(atr_MountID,AttributeType_shortString,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoScanParams::MountingString(){
		static const WString enums=WString(L"Unknown,Unfixed,Fixed,Wet,Registered");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoScanParams::MountingString(EnumMounting value){
		return MountingString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoScanParams::SetMounting( EnumMounting value){
	SetEnumAttribute(atr_Mounting,value,MountingString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoScanParams::EnumMounting JDFAutoScanParams:: GetMounting() const {
	return (EnumMounting) GetEnumAttribute(atr_Mounting,MountingString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidMounting(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Mounting,MountingString(),false);
	};
/**
* Set attribute OutputResolution
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoScanParams::SetOutputResolution(const JDFXYPair& value){
	SetAttribute(atr_OutputResolution,value);
};
/**
* Get string attribute OutputResolution
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoScanParams::GetOutputResolution() const {
	return GetAttribute(atr_OutputResolution,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidOutputResolution(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutputResolution,AttributeType_XYPair,false);
	};
/**
* Set attribute OutputSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoScanParams::SetOutputSize(const JDFXYPair& value){
	SetAttribute(atr_OutputSize,value);
};
/**
* Get string attribute OutputSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoScanParams::GetOutputSize() const {
	return GetAttribute(atr_OutputSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidOutputSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutputSize,AttributeType_XYPair,false);
	};
/**
* Set attribute SplitDocuments
*@param int value: the value to set the attribute to
*/
	 void JDFAutoScanParams::SetSplitDocuments(int value){
	SetAttribute(atr_SplitDocuments,WString::valueOf(value));
};
/**
* Get integer attribute SplitDocuments
* @return int the vaue of the attribute 
*/
	 int JDFAutoScanParams::GetSplitDocuments() const {
	return GetIntAttribute(atr_SplitDocuments,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScanParams::ValidSplitDocuments(EnumValidationLevel level) const {
		return ValidAttribute(atr_SplitDocuments,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoScanParams::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoScanParams::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoScanParams::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoScanParams::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoScanParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
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
	WString JDFAutoScanParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",FileSpec";
	};
}; // end namespace JDF
