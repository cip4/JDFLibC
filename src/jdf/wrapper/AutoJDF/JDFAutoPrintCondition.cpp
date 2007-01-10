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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPrintCondition.h"
#include "jdf/wrapper/JDFColorMeasurementConditions.h"
#include "jdf/wrapper/JDFDevice.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPrintCondition : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPrintCondition& JDFAutoPrintCondition::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPrintCondition: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPrintCondition::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPrintCondition::ValidNodeNames()const{
	return L"*:,PrintCondition";
};

bool JDFAutoPrintCondition::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPrintCondition::init(){
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
	WString JDFAutoPrintCondition::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Name";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPrintCondition::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",AimCurve,Density");
};

/**
 typesafe validator
*/
	vWString JDFAutoPrintCondition::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidName(level)) {
			vAtts.push_back(atr_Name);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAimCurve(level)) {
			vAtts.push_back(atr_AimCurve);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDensity(level)) {
			vAtts.push_back(atr_Density);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPrintCondition::SetName(const WString& value){
	SetAttribute(atr_Name,value);
};
/**
* Get string attribute Name
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPrintCondition::GetName() const {
	return GetAttribute(atr_Name,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintCondition::ValidName(EnumValidationLevel level) const {
		return ValidAttribute(atr_Name,AttributeType_string,RequiredLevel(level));
	};
/**
* Set attribute AimCurve
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoPrintCondition::SetAimCurve(const JDFNumberList& value){
	SetAttribute(atr_AimCurve,value.GetString());
};
/**
* Get string attribute AimCurve
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoPrintCondition::GetAimCurve() const {
	return GetAttribute(atr_AimCurve,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintCondition::ValidAimCurve(EnumValidationLevel level) const {
		return ValidAttribute(atr_AimCurve,AttributeType_TransferFunction,false);
	};
/**
* Set attribute Density
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPrintCondition::SetDensity(double value){
	SetAttribute(atr_Density,WString::valueOf(value));
};
/**
* Get double attribute Density
* @return double the vaue of the attribute 
*/
	 double JDFAutoPrintCondition::GetDensity() const {
	return GetRealAttribute(atr_Density,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPrintCondition::ValidDensity(EnumValidationLevel level) const {
		return ValidAttribute(atr_Density,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColorMeasurementConditions JDFAutoPrintCondition::GetColorMeasurementConditions()const{
	JDFColorMeasurementConditions e=GetElement(elm_ColorMeasurementConditions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoPrintCondition::GetCreateColorMeasurementConditions(){
	JDFColorMeasurementConditions e=GetCreateElement(elm_ColorMeasurementConditions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorMeasurementConditions JDFAutoPrintCondition::AppendColorMeasurementConditions(){
	JDFColorMeasurementConditions e=AppendElementN(elm_ColorMeasurementConditions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPrintCondition::RefColorMeasurementConditions(JDFColorMeasurementConditions& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoPrintCondition::GetDevice()const{
	JDFDevice e=GetElement(elm_Device);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoPrintCondition::GetCreateDevice(){
	JDFDevice e=GetCreateElement(elm_Device);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDevice JDFAutoPrintCondition::AppendDevice(){
	JDFDevice e=AppendElementN(elm_Device,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPrintCondition::RefDevice(JDFDevice& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoPrintCondition::GetFileSpec(int iSkip)const{
	JDFFileSpec e=GetElement(elm_FileSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoPrintCondition::GetCreateFileSpec(int iSkip){
	JDFFileSpec e=GetCreateElement(elm_FileSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoPrintCondition::AppendFileSpec(){
	JDFFileSpec e=AppendElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPrintCondition::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPrintCondition::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorMeasurementConditions);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorMeasurementConditions);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorMeasurementConditions().IsValid(level)) {
				vElem.AppendUnique(elm_ColorMeasurementConditions);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Device);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Device);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDevice().IsValid(level)) {
				vElem.AppendUnique(elm_Device);
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
	WString JDFAutoPrintCondition::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorMeasurementConditions,Device";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPrintCondition::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorMeasurementConditions,Device,FileSpec";
	};
}; // end namespace JDF
