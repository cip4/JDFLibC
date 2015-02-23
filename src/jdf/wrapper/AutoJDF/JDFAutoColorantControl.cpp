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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColorantControl.h"
#include "jdf/wrapper/JDFColorantAlias.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFColorSpaceSubstitute.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFDeviceNSpace.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorantControl : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColorantControl& JDFAutoColorantControl::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColorantControl: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColorantControl::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColorantControl::ValidNodeNames()const{
	return L"*:,ColorantControl";
};

bool JDFAutoColorantControl::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoColorantControl::init(){
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
	WString JDFAutoColorantControl::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ForceSeparations,InternalColorModel,MappingSelection,ProcessColorModel");
};

/**
 typesafe validator
*/
	vWString JDFAutoColorantControl::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidForceSeparations(level)) {
			vAtts.push_back(atr_ForceSeparations);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidInternalColorModel(level)) {
			vAtts.push_back(atr_InternalColorModel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMappingSelection(level)) {
			vAtts.push_back(atr_MappingSelection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProcessColorModel(level)) {
			vAtts.push_back(atr_ProcessColorModel);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ForceSeparations
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoColorantControl::SetForceSeparations(bool value){
	SetAttribute(atr_ForceSeparations,WString::valueOf(value));
};
/**
* Get bool attribute ForceSeparations
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoColorantControl::GetForceSeparations() const {return GetBoolAttribute(atr_ForceSeparations,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorantControl::ValidForceSeparations(EnumValidationLevel level) const {
		return ValidAttribute(atr_ForceSeparations,AttributeType_boolean,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorantControl::InternalColorModelString(){
		static const WString enums=WString(L"Unknown,Basic,Enhanced,Explicit");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorantControl::InternalColorModelString(EnumInternalColorModel value){
		return InternalColorModelString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorantControl::SetInternalColorModel( EnumInternalColorModel value){
	SetEnumAttribute(atr_InternalColorModel,value,InternalColorModelString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorantControl::EnumInternalColorModel JDFAutoColorantControl:: GetInternalColorModel() const {
	return (EnumInternalColorModel) GetEnumAttribute(atr_InternalColorModel,InternalColorModelString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorantControl::ValidInternalColorModel(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_InternalColorModel,InternalColorModelString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorantControl::MappingSelectionString(){
		static const WString enums=WString(L"Unknown,UsePDLValues,UseLocalPrinterValues,UseProcessColorValues");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorantControl::MappingSelectionString(EnumMappingSelection value){
		return MappingSelectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorantControl::SetMappingSelection( EnumMappingSelection value){
	SetEnumAttribute(atr_MappingSelection,value,MappingSelectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorantControl::EnumMappingSelection JDFAutoColorantControl:: GetMappingSelection() const {
	return (EnumMappingSelection) GetEnumAttribute(atr_MappingSelection,MappingSelectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorantControl::ValidMappingSelection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MappingSelection,MappingSelectionString(),false);
	};
/**
* Set attribute ProcessColorModel
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColorantControl::SetProcessColorModel(const WString& value){
	SetAttribute(atr_ProcessColorModel,value);
};
/**
* Get string attribute ProcessColorModel
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColorantControl::GetProcessColorModel() const {
	return GetAttribute(atr_ProcessColorModel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorantControl::ValidProcessColorModel(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProcessColorModel,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColorantAlias JDFAutoColorantControl::GetColorantAlias(int iSkip)const{
	JDFColorantAlias e=GetElement(elm_ColorantAlias,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorantAlias JDFAutoColorantControl::GetCreateColorantAlias(int iSkip){
	JDFColorantAlias e=GetCreateElement(elm_ColorantAlias,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorantAlias JDFAutoColorantControl::AppendColorantAlias(){
	JDFColorantAlias e=AppendElement(elm_ColorantAlias);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorantControl::RefColorantAlias(JDFColorantAlias& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::GetColorantConvertProcess()const{
	JDFSeparationList e=GetElement(elm_ColorantConvertProcess);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::GetCreateColorantConvertProcess(){
	JDFSeparationList e=GetCreateElement(elm_ColorantConvertProcess);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::AppendColorantConvertProcess(){
	JDFSeparationList e=AppendElementN(elm_ColorantConvertProcess,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::GetColorantOrder()const{
	JDFSeparationList e=GetElement(elm_ColorantOrder);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::GetCreateColorantOrder(){
	JDFSeparationList e=GetCreateElement(elm_ColorantOrder);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::AppendColorantOrder(){
	JDFSeparationList e=AppendElementN(elm_ColorantOrder,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::GetColorantParams()const{
	JDFSeparationList e=GetElement(elm_ColorantParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::GetCreateColorantParams(){
	JDFSeparationList e=GetCreateElement(elm_ColorantParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::AppendColorantParams(){
	JDFSeparationList e=AppendElementN(elm_ColorantParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoColorantControl::GetColorPool()const{
	JDFColorPool e=GetElement(elm_ColorPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoColorantControl::GetCreateColorPool(){
	JDFColorPool e=GetCreateElement(elm_ColorPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoColorantControl::AppendColorPool(){
	JDFColorPool e=AppendElementN(elm_ColorPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorantControl::RefColorPool(JDFColorPool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceSubstitute JDFAutoColorantControl::GetColorSpaceSubstitute(int iSkip)const{
	JDFColorSpaceSubstitute e=GetElement(elm_ColorSpaceSubstitute,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceSubstitute JDFAutoColorantControl::GetCreateColorSpaceSubstitute(int iSkip){
	JDFColorSpaceSubstitute e=GetCreateElement(elm_ColorSpaceSubstitute,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceSubstitute JDFAutoColorantControl::AppendColorSpaceSubstitute(){
	JDFColorSpaceSubstitute e=AppendElement(elm_ColorSpaceSubstitute);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::GetDeviceColorantOrder()const{
	JDFSeparationList e=GetElement(elm_DeviceColorantOrder);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::GetCreateDeviceColorantOrder(){
	JDFSeparationList e=GetCreateElement(elm_DeviceColorantOrder);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorantControl::AppendDeviceColorantOrder(){
	JDFSeparationList e=AppendElementN(elm_DeviceColorantOrder,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNSpace JDFAutoColorantControl::GetDeviceNSpace(int iSkip)const{
	JDFDeviceNSpace e=GetElement(elm_DeviceNSpace,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNSpace JDFAutoColorantControl::GetCreateDeviceNSpace(int iSkip){
	JDFDeviceNSpace e=GetCreateElement(elm_DeviceNSpace,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceNSpace JDFAutoColorantControl::AppendDeviceNSpace(){
	JDFDeviceNSpace e=AppendElement(elm_DeviceNSpace);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoColorantControl::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorantAlias);

		for(i=0;i<nElem;i++){
			if (!GetColorantAlias(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorantAlias);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ColorantConvertProcess);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorantConvertProcess);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorantConvertProcess().IsValid(level)) {
				vElem.AppendUnique(elm_ColorantConvertProcess);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorantOrder);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorantOrder);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorantOrder().IsValid(level)) {
				vElem.AppendUnique(elm_ColorantOrder);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorantParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorantParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorantParams().IsValid(level)) {
				vElem.AppendUnique(elm_ColorantParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorPool().IsValid(level)) {
				vElem.AppendUnique(elm_ColorPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorSpaceSubstitute);

		for(i=0;i<nElem;i++){
			if (!GetColorSpaceSubstitute(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorSpaceSubstitute);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DeviceColorantOrder);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DeviceColorantOrder);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDeviceColorantOrder().IsValid(level)) {
				vElem.AppendUnique(elm_DeviceColorantOrder);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_DeviceNSpace);

		for(i=0;i<nElem;i++){
			if (!GetDeviceNSpace(i).IsValid(level)) {
				vElem.AppendUnique(elm_DeviceNSpace);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoColorantControl::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorantConvertProcess,ColorantOrder,ColorantParams,ColorPool,DeviceColorantOrder";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoColorantControl::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorantAlias,ColorantConvertProcess,ColorantOrder,ColorantParams,ColorPool,ColorSpaceSubstitute,DeviceColorantOrder,DeviceNSpace";
	};
}; // end namespace JDF
