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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColorSpaceConversionParams.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFColorSpaceConversionOp.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorSpaceConversionParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColorSpaceConversionParams& JDFAutoColorSpaceConversionParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColorSpaceConversionParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColorSpaceConversionParams::ValidNodeNames()const{
	return L"*:,ColorSpaceConversionParams";
};

bool JDFAutoColorSpaceConversionParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoColorSpaceConversionParams::init(){
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
	WString JDFAutoColorSpaceConversionParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ICCProfileUsage,ColorManagementSystem,ConvertDevIndepColors");
};

/**
 typesafe validator
*/
	vWString JDFAutoColorSpaceConversionParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidICCProfileUsage(level)) {
			vAtts.push_back(atr_ICCProfileUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidColorManagementSystem(level)) {
			vAtts.push_back(atr_ColorManagementSystem);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidConvertDevIndepColors(level)) {
			vAtts.push_back(atr_ConvertDevIndepColors);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoColorSpaceConversionParams::ICCProfileUsageString(){
		static const WString enums=WString(L"Unknown,UsePDL,UseSupplied");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoColorSpaceConversionParams::ICCProfileUsageString(EnumICCProfileUsage value){
		return ICCProfileUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoColorSpaceConversionParams::SetICCProfileUsage( EnumICCProfileUsage value){
	SetEnumAttribute(atr_ICCProfileUsage,value,ICCProfileUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoColorSpaceConversionParams::EnumICCProfileUsage JDFAutoColorSpaceConversionParams:: GetICCProfileUsage() const {
	return (EnumICCProfileUsage) GetEnumAttribute(atr_ICCProfileUsage,ICCProfileUsageString(),WString::emptyStr,ICCProfileUsage_UsePDL);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionParams::ValidICCProfileUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ICCProfileUsage,ICCProfileUsageString(),false);
	};
/**
* Set attribute ColorManagementSystem
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColorSpaceConversionParams::SetColorManagementSystem(const WString& value){
	SetAttribute(atr_ColorManagementSystem,value);
};
/**
* Get string attribute ColorManagementSystem
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColorSpaceConversionParams::GetColorManagementSystem() const {
	return GetAttribute(atr_ColorManagementSystem,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionParams::ValidColorManagementSystem(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorManagementSystem,AttributeType_string,false);
	};
/**
* Set attribute ConvertDevIndepColors
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoColorSpaceConversionParams::SetConvertDevIndepColors(bool value){
	SetAttribute(atr_ConvertDevIndepColors,WString::valueOf(value));
};
/**
* Get bool attribute ConvertDevIndepColors
* @return bool the vaue of the attribute 
*/
	 bool JDFAutoColorSpaceConversionParams::GetConvertDevIndepColors() const {return GetBoolAttribute(atr_ConvertDevIndepColors,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorSpaceConversionParams::ValidConvertDevIndepColors(EnumValidationLevel level) const {
		return ValidAttribute(atr_ConvertDevIndepColors,AttributeType_boolean,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFileSpec JDFAutoColorSpaceConversionParams::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColorSpaceConversionParams::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoColorSpaceConversionParams::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorSpaceConversionParams::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceConversionOp JDFAutoColorSpaceConversionParams::GetColorSpaceConversionOp(int iSkip)const{
	JDFColorSpaceConversionOp e=GetElement(elm_ColorSpaceConversionOp,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceConversionOp JDFAutoColorSpaceConversionParams::GetCreateColorSpaceConversionOp(int iSkip){
	JDFColorSpaceConversionOp e=GetCreateElement(elm_ColorSpaceConversionOp,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceConversionOp JDFAutoColorSpaceConversionParams::AppendColorSpaceConversionOp(){
	JDFColorSpaceConversionOp e=AppendElement(elm_ColorSpaceConversionOp);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoColorSpaceConversionParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
		nElem=NumChildElements(elm_ColorSpaceConversionOp);

		for(i=0;i<nElem;i++){
			if (!GetColorSpaceConversionOp(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorSpaceConversionOp);
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
	WString JDFAutoColorSpaceConversionParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",FileSpec,ColorSpaceConversionOp";
	};
}; // end namespace JDF
