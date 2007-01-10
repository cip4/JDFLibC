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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColorControlStrip.h"
#include "jdf/wrapper/JDFCIELABMeasuringField.h"
#include "jdf/wrapper/JDFDensityMeasuringField.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorControlStrip : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColorControlStrip& JDFAutoColorControlStrip::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColorControlStrip: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColorControlStrip::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColorControlStrip::ValidNodeNames()const{
	return L"*:,ColorControlStrip";
};

bool JDFAutoColorControlStrip::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoColorControlStrip::init(){
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
	WString JDFAutoColorControlStrip::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Center,Size";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoColorControlStrip::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Rotation,StripType");
};

/**
 typesafe validator
*/
	vWString JDFAutoColorControlStrip::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCenter(level)) {
			vAtts.push_back(atr_Center);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSize(level)) {
			vAtts.push_back(atr_Size);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotation(level)) {
			vAtts.push_back(atr_Rotation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStripType(level)) {
			vAtts.push_back(atr_StripType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Center
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoColorControlStrip::SetCenter(const JDFXYPair& value){
	SetAttribute(atr_Center,value);
};
/**
* Get string attribute Center
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoColorControlStrip::GetCenter() const {
	return GetAttribute(atr_Center,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorControlStrip::ValidCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Center,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute Size
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoColorControlStrip::SetSize(const JDFXYPair& value){
	SetAttribute(atr_Size,value);
};
/**
* Get string attribute Size
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoColorControlStrip::GetSize() const {
	return GetAttribute(atr_Size,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorControlStrip::ValidSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_Size,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute Rotation
*@param double value: the value to set the attribute to
*/
	 void JDFAutoColorControlStrip::SetRotation(double value){
	SetAttribute(atr_Rotation,WString::valueOf(value));
};
/**
* Get double attribute Rotation
* @return double the vaue of the attribute 
*/
	 double JDFAutoColorControlStrip::GetRotation() const {
	return GetRealAttribute(atr_Rotation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorControlStrip::ValidRotation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Rotation,AttributeType_double,false);
	};
/**
* Set attribute StripType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoColorControlStrip::SetStripType(const WString& value){
	SetAttribute(atr_StripType,value);
};
/**
* Get string attribute StripType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoColorControlStrip::GetStripType() const {
	return GetAttribute(atr_StripType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorControlStrip::ValidStripType(EnumValidationLevel level) const {
		return ValidAttribute(atr_StripType,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCIELABMeasuringField JDFAutoColorControlStrip::GetCIELABMeasuringField(int iSkip)const{
	JDFCIELABMeasuringField e=GetElement(elm_CIELABMeasuringField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCIELABMeasuringField JDFAutoColorControlStrip::GetCreateCIELABMeasuringField(int iSkip){
	JDFCIELABMeasuringField e=GetCreateElement(elm_CIELABMeasuringField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCIELABMeasuringField JDFAutoColorControlStrip::AppendCIELABMeasuringField(){
	JDFCIELABMeasuringField e=AppendElement(elm_CIELABMeasuringField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorControlStrip::RefCIELABMeasuringField(JDFCIELABMeasuringField& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDensityMeasuringField JDFAutoColorControlStrip::GetDensityMeasuringField(int iSkip)const{
	JDFDensityMeasuringField e=GetElement(elm_DensityMeasuringField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDensityMeasuringField JDFAutoColorControlStrip::GetCreateDensityMeasuringField(int iSkip){
	JDFDensityMeasuringField e=GetCreateElement(elm_DensityMeasuringField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDensityMeasuringField JDFAutoColorControlStrip::AppendDensityMeasuringField(){
	JDFDensityMeasuringField e=AppendElement(elm_DensityMeasuringField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorControlStrip::RefDensityMeasuringField(JDFDensityMeasuringField& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoColorControlStrip::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CIELABMeasuringField);

		for(i=0;i<nElem;i++){
			if (!GetCIELABMeasuringField(i).IsValid(level)) {
				vElem.AppendUnique(elm_CIELABMeasuringField);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DensityMeasuringField);

		for(i=0;i<nElem;i++){
			if (!GetDensityMeasuringField(i).IsValid(level)) {
				vElem.AppendUnique(elm_DensityMeasuringField);
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
	WString JDFAutoColorControlStrip::OptionalElements()const{
		return JDFResource::OptionalElements()+L",CIELABMeasuringField,DensityMeasuringField";
	};
}; // end namespace JDF
