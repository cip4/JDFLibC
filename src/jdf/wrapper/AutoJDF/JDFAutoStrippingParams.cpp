/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoStrippingParams.h"
#include "jdf/wrapper/JDFBinderySignature.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFExternalImpositionTemplate.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFPosition.h"
#include "jdf/wrapper/JDFStripCellParams.h"
#include "jdf/wrapper/JDFStripMark.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoStrippingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoStrippingParams& JDFAutoStrippingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoStrippingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoStrippingParams::ValidNodeNames()const{
	return L"*:,StrippingParams";
};

bool JDFAutoStrippingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoStrippingParams::init(){
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
	WString JDFAutoStrippingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",AssemblyID,AssemblyIDs,Automated,InnermostShingling,JobID,OutermostShingling,SectionList,SheetNameFormat,SheetNameTemplate,StackDepth,WorkStyle");
};

/**
 typesafe validator
*/
	vWString JDFAutoStrippingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAssemblyID(level)) {
			vAtts.push_back(atr_AssemblyID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAssemblyIDs(level)) {
			vAtts.push_back(atr_AssemblyIDs);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAutomated(level)) {
			vAtts.push_back(atr_Automated);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInnermostShingling(level)) {
			vAtts.push_back(atr_InnermostShingling);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJobID(level)) {
			vAtts.push_back(atr_JobID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOutermostShingling(level)) {
			vAtts.push_back(atr_OutermostShingling);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSectionList(level)) {
			vAtts.push_back(atr_SectionList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetNameFormat(level)) {
			vAtts.push_back(atr_SheetNameFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetNameTemplate(level)) {
			vAtts.push_back(atr_SheetNameTemplate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStackDepth(level)) {
			vAtts.push_back(atr_StackDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkStyle(level)) {
			vAtts.push_back(atr_WorkStyle);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AssemblyID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetAssemblyID(const WString& value){
	SetAttribute(atr_AssemblyID,value);
};
/**
* Get string attribute AssemblyID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStrippingParams::GetAssemblyID() const {
	return GetAttribute(atr_AssemblyID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidAssemblyID(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyID,AttributeType_string,false);
	};
/**
* Set attribute AssemblyIDs
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetAssemblyIDs(const vWString& value){
	SetAttribute(atr_AssemblyIDs,value);
};
/**
* Get string attribute AssemblyIDs
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoStrippingParams::GetAssemblyIDs() const {
	return GetAttribute(atr_AssemblyIDs,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidAssemblyIDs(EnumValidationLevel level) const {
		return ValidAttribute(atr_AssemblyIDs,AttributeType_NMTOKENS,false);
	};
/**
* Set attribute Automated
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetAutomated(bool value){
	SetAttribute(atr_Automated,WString::valueOf(value));
};
/**
* Get bool attribute Automated
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoStrippingParams::GetAutomated() const {return GetBoolAttribute(atr_Automated,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidAutomated(EnumValidationLevel level) const {
		return ValidAttribute(atr_Automated,AttributeType_boolean,false);
	};
/**
* Set attribute InnermostShingling
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetInnermostShingling(double value){
	SetAttribute(atr_InnermostShingling,WString::valueOf(value));
};
/**
* Get double attribute InnermostShingling
* @return double the vaue of the attribute 
*/
	 double JDFAutoStrippingParams::GetInnermostShingling() const {
	return GetRealAttribute(atr_InnermostShingling,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidInnermostShingling(EnumValidationLevel level) const {
		return ValidAttribute(atr_InnermostShingling,AttributeType_double,false);
	};
/**
* Set attribute JobID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetJobID(const WString& value){
	SetAttribute(atr_JobID,value);
};
/**
* Get string attribute JobID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStrippingParams::GetJobID() const {
	return GetAttribute(atr_JobID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidJobID(EnumValidationLevel level) const {
		return ValidAttribute(atr_JobID,AttributeType_shortString,false);
	};
/**
* Set attribute OutermostShingling
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetOutermostShingling(double value){
	SetAttribute(atr_OutermostShingling,WString::valueOf(value));
};
/**
* Get double attribute OutermostShingling
* @return double the vaue of the attribute 
*/
	 double JDFAutoStrippingParams::GetOutermostShingling() const {
	return GetRealAttribute(atr_OutermostShingling,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidOutermostShingling(EnumValidationLevel level) const {
		return ValidAttribute(atr_OutermostShingling,AttributeType_double,false);
	};
/**
* Set attribute SectionList
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetSectionList(const JDFIntegerList& value){
	SetAttribute(atr_SectionList,value.GetString());
};
/**
* Get string attribute SectionList
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoStrippingParams::GetSectionList() const {
	return GetAttribute(atr_SectionList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidSectionList(EnumValidationLevel level) const {
		return ValidAttribute(atr_SectionList,AttributeType_IntegerList,false);
	};
/**
* Set attribute SheetNameFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetSheetNameFormat(const WString& value){
	SetAttribute(atr_SheetNameFormat,value);
};
/**
* Get string attribute SheetNameFormat
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStrippingParams::GetSheetNameFormat() const {
	return GetAttribute(atr_SheetNameFormat,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidSheetNameFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetNameFormat,AttributeType_string,false);
	};
/**
* Set attribute SheetNameTemplate
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetSheetNameTemplate(const WString& value){
	SetAttribute(atr_SheetNameTemplate,value);
};
/**
* Get string attribute SheetNameTemplate
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStrippingParams::GetSheetNameTemplate() const {
	return GetAttribute(atr_SheetNameTemplate,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidSheetNameTemplate(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetNameTemplate,AttributeType_string,false);
	};
/**
* Set attribute StackDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoStrippingParams::SetStackDepth(int value){
	SetAttribute(atr_StackDepth,WString::valueOf(value));
};
/**
* Get integer attribute StackDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoStrippingParams::GetStackDepth() const {
	return GetIntAttribute(atr_StackDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidStackDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_StackDepth,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStrippingParams::WorkStyleString(){
		static const WString enums=WString(L"Unknown,Simplex,Perfecting,WorkAndBack,WorkAndTurn,WorkAndTumble,WorkAndTwist");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStrippingParams::WorkStyleString(EnumWorkStyle value){
		return WorkStyleString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStrippingParams::SetWorkStyle( EnumWorkStyle value){
	SetEnumAttribute(atr_WorkStyle,value,WorkStyleString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStrippingParams::EnumWorkStyle JDFAutoStrippingParams:: GetWorkStyle() const {
	return (EnumWorkStyle) GetEnumAttribute(atr_WorkStyle,WorkStyleString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStrippingParams::ValidWorkStyle(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_WorkStyle,WorkStyleString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBinderySignature JDFAutoStrippingParams::GetBinderySignature(int iSkip)const{
	JDFBinderySignature e=GetElement(elm_BinderySignature,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBinderySignature JDFAutoStrippingParams::GetCreateBinderySignature(int iSkip){
	JDFBinderySignature e=GetCreateElement(elm_BinderySignature,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBinderySignature JDFAutoStrippingParams::AppendBinderySignature(){
	JDFBinderySignature e=AppendElement(elm_BinderySignature);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoStrippingParams::RefBinderySignature(JDFBinderySignature& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoStrippingParams::GetDevice(int iSkip)const{
	JDFDevice e=GetElement(elm_Device,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoStrippingParams::GetCreateDevice(int iSkip){
	JDFDevice e=GetCreateElement(elm_Device,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoStrippingParams::AppendDevice(){
	JDFDevice e=AppendElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoStrippingParams::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFExternalImpositionTemplate JDFAutoStrippingParams::GetExternalImpositionTemplate(int iSkip)const{
	JDFExternalImpositionTemplate e=GetElement(elm_ExternalImpositionTemplate,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFExternalImpositionTemplate JDFAutoStrippingParams::GetCreateExternalImpositionTemplate(int iSkip){
	JDFExternalImpositionTemplate e=GetCreateElement(elm_ExternalImpositionTemplate,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFExternalImpositionTemplate JDFAutoStrippingParams::AppendExternalImpositionTemplate(){
	JDFExternalImpositionTemplate e=AppendElement(elm_ExternalImpositionTemplate);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoStrippingParams::RefExternalImpositionTemplate(JDFExternalImpositionTemplate& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoStrippingParams::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoStrippingParams::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoStrippingParams::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoStrippingParams::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPosition JDFAutoStrippingParams::GetPosition(int iSkip)const{
	JDFPosition e=GetElement(elm_Position,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPosition JDFAutoStrippingParams::GetCreatePosition(int iSkip){
	JDFPosition e=GetCreateElement(elm_Position,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPosition JDFAutoStrippingParams::AppendPosition(){
	JDFPosition e=AppendElement(elm_Position);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripCellParams JDFAutoStrippingParams::GetStripCellParams(int iSkip)const{
	JDFStripCellParams e=GetElement(elm_StripCellParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripCellParams JDFAutoStrippingParams::GetCreateStripCellParams(int iSkip){
	JDFStripCellParams e=GetCreateElement(elm_StripCellParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripCellParams JDFAutoStrippingParams::AppendStripCellParams(){
	JDFStripCellParams e=AppendElement(elm_StripCellParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripMark JDFAutoStrippingParams::GetStripMark(int iSkip)const{
	JDFStripMark e=GetElement(elm_StripMark,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripMark JDFAutoStrippingParams::GetCreateStripMark(int iSkip){
	JDFStripMark e=GetCreateElement(elm_StripMark,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripMark JDFAutoStrippingParams::AppendStripMark(){
	JDFStripMark e=AppendElement(elm_StripMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoStrippingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BinderySignature);

		for(i=0;i<nElem;i++){
			if (!GetBinderySignature(i).IsValid(level)) {
				vElem.AppendUnique(elm_BinderySignature);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Device);

		for(i=0;i<nElem;i++){
			if (!GetDevice(i).IsValid(level)) {
				vElem.AppendUnique(elm_Device);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ExternalImpositionTemplate);

		for(i=0;i<nElem;i++){
			if (!GetExternalImpositionTemplate(i).IsValid(level)) {
				vElem.AppendUnique(elm_ExternalImpositionTemplate);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Media);

		for(i=0;i<nElem;i++){
			if (!GetMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_Media);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Position);

		for(i=0;i<nElem;i++){
			if (!GetPosition(i).IsValid(level)) {
				vElem.AppendUnique(elm_Position);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StripCellParams);

		for(i=0;i<nElem;i++){
			if (!GetStripCellParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_StripCellParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StripMark);

		for(i=0;i<nElem;i++){
			if (!GetStripMark(i).IsValid(level)) {
				vElem.AppendUnique(elm_StripMark);
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
	WString JDFAutoStrippingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",BinderySignature,Device,ExternalImpositionTemplate,Media,Position,StripCellParams,StripMark";
	};
}; // end namespace JDF
