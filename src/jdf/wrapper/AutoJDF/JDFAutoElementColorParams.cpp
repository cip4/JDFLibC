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

 
#include "jdf/wrapper/AutoJDF/JDFAutoElementColorParams.h"
#include "jdf/wrapper/JDFAutomatedOverPrintParams.h"
#include "jdf/wrapper/JDFColorantAlias.h"
#include "jdf/wrapper/JDFColorCorrectionOp.h"
#include "jdf/wrapper/JDFColorSpaceConversionOp.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoElementColorParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoElementColorParams& JDFAutoElementColorParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoElementColorParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoElementColorParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoElementColorParams::ValidNodeNames()const{
	return L"*:,ElementColorParams";
};

bool JDFAutoElementColorParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoElementColorParams::init(){
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
	WString JDFAutoElementColorParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ColorManagementSystem,ICCOutputProfileUsage");
};

/**
 typesafe validator
*/
	vWString JDFAutoElementColorParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidColorManagementSystem(level)) {
			vAtts.push_back(atr_ColorManagementSystem);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidICCOutputProfileUsage(level)) {
			vAtts.push_back(atr_ICCOutputProfileUsage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ColorManagementSystem
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoElementColorParams::SetColorManagementSystem(const WString& value){
	SetAttribute(atr_ColorManagementSystem,value);
};
/**
* Get string attribute ColorManagementSystem
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoElementColorParams::GetColorManagementSystem() const {
	return GetAttribute(atr_ColorManagementSystem,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoElementColorParams::ValidColorManagementSystem(EnumValidationLevel level) const {
		return ValidAttribute(atr_ColorManagementSystem,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoElementColorParams::ICCOutputProfileUsageString(){
		static const WString enums=WString(L"Unknown,PDLActual,PDLReference,IgnorePDL");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoElementColorParams::ICCOutputProfileUsageString(EnumICCOutputProfileUsage value){
		return ICCOutputProfileUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoElementColorParams::SetICCOutputProfileUsage( EnumICCOutputProfileUsage value){
	SetEnumAttribute(atr_ICCOutputProfileUsage,value,ICCOutputProfileUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoElementColorParams::EnumICCOutputProfileUsage JDFAutoElementColorParams:: GetICCOutputProfileUsage() const {
	return (EnumICCOutputProfileUsage) GetEnumAttribute(atr_ICCOutputProfileUsage,ICCOutputProfileUsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoElementColorParams::ValidICCOutputProfileUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_ICCOutputProfileUsage,ICCOutputProfileUsageString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAutomatedOverPrintParams JDFAutoElementColorParams::GetAutomatedOverPrintParams()const{
	JDFAutomatedOverPrintParams e=GetElement(elm_AutomatedOverPrintParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAutomatedOverPrintParams JDFAutoElementColorParams::GetCreateAutomatedOverPrintParams(){
	JDFAutomatedOverPrintParams e=GetCreateElement(elm_AutomatedOverPrintParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAutomatedOverPrintParams JDFAutoElementColorParams::AppendAutomatedOverPrintParams(){
	JDFAutomatedOverPrintParams e=AppendElementN(elm_AutomatedOverPrintParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorantAlias JDFAutoElementColorParams::GetColorantAlias(int iSkip)const{
	JDFColorantAlias e=GetElement(elm_ColorantAlias,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorantAlias JDFAutoElementColorParams::GetCreateColorantAlias(int iSkip){
	JDFColorantAlias e=GetCreateElement(elm_ColorantAlias,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorantAlias JDFAutoElementColorParams::AppendColorantAlias(){
	JDFColorantAlias e=AppendElement(elm_ColorantAlias);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoElementColorParams::RefColorantAlias(JDFColorantAlias& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFColorCorrectionOp JDFAutoElementColorParams::GetColorCorrectionOp(int iSkip)const{
	JDFColorCorrectionOp e=GetElement(elm_ColorCorrectionOp,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorCorrectionOp JDFAutoElementColorParams::GetCreateColorCorrectionOp(int iSkip){
	JDFColorCorrectionOp e=GetCreateElement(elm_ColorCorrectionOp,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorCorrectionOp JDFAutoElementColorParams::AppendColorCorrectionOp(){
	JDFColorCorrectionOp e=AppendElement(elm_ColorCorrectionOp);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceConversionOp JDFAutoElementColorParams::GetColorSpaceConversionOp()const{
	JDFColorSpaceConversionOp e=GetElement(elm_ColorSpaceConversionOp);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceConversionOp JDFAutoElementColorParams::GetCreateColorSpaceConversionOp(){
	JDFColorSpaceConversionOp e=GetCreateElement(elm_ColorSpaceConversionOp);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorSpaceConversionOp JDFAutoElementColorParams::AppendColorSpaceConversionOp(){
	JDFColorSpaceConversionOp e=AppendElementN(elm_ColorSpaceConversionOp,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoElementColorParams::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoElementColorParams::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoElementColorParams::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoElementColorParams::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoElementColorParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_AutomatedOverPrintParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_AutomatedOverPrintParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAutomatedOverPrintParams().IsValid(level)) {
				vElem.AppendUnique(elm_AutomatedOverPrintParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorantAlias);

		for(i=0;i<nElem;i++){
			if (!GetColorantAlias(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorantAlias);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ColorCorrectionOp);

		for(i=0;i<nElem;i++){
			if (!GetColorCorrectionOp(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorCorrectionOp);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ColorSpaceConversionOp);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorSpaceConversionOp);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorSpaceConversionOp().IsValid(level)) {
				vElem.AppendUnique(elm_ColorSpaceConversionOp);
				if (++n>=nMax)
					return vElem;
			}
		}
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
 definition of required elements in the JDF namespace
*/
	WString JDFAutoElementColorParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",AutomatedOverPrintParams,ColorSpaceConversionOp";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoElementColorParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",AutomatedOverPrintParams,ColorantAlias,ColorCorrectionOp,ColorSpaceConversionOp,FileSpec";
	};
}; // end namespace JDF
