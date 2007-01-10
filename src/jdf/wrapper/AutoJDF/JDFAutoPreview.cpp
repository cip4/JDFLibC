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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreview.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreview : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreview& JDFAutoPreview::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreview: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreview::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreview::ValidNodeNames()const{
	return L"*:,Preview";
};

bool JDFAutoPreview::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPreview::init(){
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
	WString JDFAutoPreview::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",URL";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPreview::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",PreviewFileType,PreviewUsage,Compensation,CTM,Directory");
};

/**
 typesafe validator
*/
	vWString JDFAutoPreview::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPreviewFileType(level)) {
			vAtts.push_back(atr_PreviewFileType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPreviewUsage(level)) {
			vAtts.push_back(atr_PreviewUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidURL(level)) {
			vAtts.push_back(atr_URL);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCompensation(level)) {
			vAtts.push_back(atr_Compensation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCTM(level)) {
			vAtts.push_back(atr_CTM);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDirectory(level)) {
			vAtts.push_back(atr_Directory);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreview::PreviewFileTypeString(){
		static const WString enums=WString(L"Unknown,PNG,CIP3Multiple,CIP3Single");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreview::PreviewFileTypeString(EnumPreviewFileType value){
		return PreviewFileTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreview::SetPreviewFileType( EnumPreviewFileType value){
	SetEnumAttribute(atr_PreviewFileType,value,PreviewFileTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreview::EnumPreviewFileType JDFAutoPreview:: GetPreviewFileType() const {
	return (EnumPreviewFileType) GetEnumAttribute(atr_PreviewFileType,PreviewFileTypeString(),WString::emptyStr,PreviewFileType_PNG);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPreviewFileType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreviewFileType,PreviewFileTypeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreview::PreviewUsageString(){
		static const WString enums=WString(L"Unknown,Separation,SeparatedThumbNail,SeparationRaw,ThumbNail,Viewable");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreview::PreviewUsageString(EnumPreviewUsage value){
		return PreviewUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreview::SetPreviewUsage( EnumPreviewUsage value){
	SetEnumAttribute(atr_PreviewUsage,value,PreviewUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreview::EnumPreviewUsage JDFAutoPreview:: GetPreviewUsage() const {
	return (EnumPreviewUsage) GetEnumAttribute(atr_PreviewUsage,PreviewUsageString(),WString::emptyStr,PreviewUsage_Separation);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidPreviewUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_PreviewUsage,PreviewUsageString(),false);
	};
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetURL(const WString& value){
	SetAttribute(atr_URL,value);
};
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetURL() const {
	return GetAttribute(atr_URL,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_URL,AttributeType_URL,RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPreview::CompensationString(){
		static const WString enums=WString(L"Unknown,None,Film,Plate,Press");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPreview::CompensationString(EnumCompensation value){
		return CompensationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPreview::SetCompensation( EnumCompensation value){
	SetEnumAttribute(atr_Compensation,value,CompensationString(),WString::emptyStr,true);
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPreview::EnumCompensation JDFAutoPreview:: GetCompensation() const {
	return (EnumCompensation) GetEnumAttribute(atr_Compensation,CompensationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidCompensation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Compensation,CompensationString(),false,WString::emptyStr,true);
	};
/**
* Set attribute CTM
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetCTM(const JDFMatrix& value){
	SetAttribute(atr_CTM,value);
};
/**
* Get string attribute CTM
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoPreview::GetCTM() const {
	return GetAttribute(atr_CTM,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidCTM(EnumValidationLevel level) const {
		return ValidAttribute(atr_CTM,AttributeType_matrix,false);
	};
/**
* Set attribute Directory
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPreview::SetDirectory(const WString& value){
	SetAttribute(atr_Directory,value);
};
/**
* Get string attribute Directory
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPreview::GetDirectory() const {
	return GetAttribute(atr_Directory,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPreview::ValidDirectory(EnumValidationLevel level) const {
		return ValidAttribute(atr_Directory,AttributeType_URL,false);
	};
}; // end namespace JDF
