/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoQualityControlParams.h"
#include "jdf/wrapper/JDFBindingQualityParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoQualityControlParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoQualityControlParams& JDFAutoQualityControlParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoQualityControlParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoQualityControlParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoQualityControlParams::ValidNodeNames()const{
	return L"*:,QualityControlParams";
};

bool JDFAutoQualityControlParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoQualityControlParams::init(){
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
	WString JDFAutoQualityControlParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",TimeInterval,SampleInterval");
};

/**
 typesafe validator
*/
	vWString JDFAutoQualityControlParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTimeInterval(level)) {
			vAtts.push_back(atr_TimeInterval);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSampleInterval(level)) {
			vAtts.push_back(atr_SampleInterval);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute TimeInterval
*@param JDFDuration value: the value to set the attribute to
*/
	 void JDFAutoQualityControlParams::SetTimeInterval(JDFDuration value){
	SetAttribute(atr_TimeInterval,value.DurationISO());
};
/**
* Get string attribute TimeInterval
* @return JDFDuration the vaue of the attribute 
*/
	 JDFDuration JDFAutoQualityControlParams::GetTimeInterval() const {
	return GetAttribute(atr_TimeInterval,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityControlParams::ValidTimeInterval(EnumValidationLevel level) const {
		return ValidAttribute(atr_TimeInterval,AttributeType_duration,false);
	};
/**
* Set attribute SampleInterval
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQualityControlParams::SetSampleInterval(int value){
	SetAttribute(atr_SampleInterval,WString::valueOf(value));
};
/**
* Get integer attribute SampleInterval
* @return int the vaue of the attribute 
*/
	 int JDFAutoQualityControlParams::GetSampleInterval() const {
	return GetIntAttribute(atr_SampleInterval,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityControlParams::ValidSampleInterval(EnumValidationLevel level) const {
		return ValidAttribute(atr_SampleInterval,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBindingQualityParams JDFAutoQualityControlParams::GetBindingQualityParams()const{
	JDFBindingQualityParams e=GetElement(elm_BindingQualityParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindingQualityParams JDFAutoQualityControlParams::GetCreateBindingQualityParams(){
	JDFBindingQualityParams e=GetCreateElement(elm_BindingQualityParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindingQualityParams JDFAutoQualityControlParams::AppendBindingQualityParams(){
	JDFBindingQualityParams e=AppendElementN(elm_BindingQualityParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoQualityControlParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BindingQualityParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_BindingQualityParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetBindingQualityParams().IsValid(level)) {
				vElem.AppendUnique(elm_BindingQualityParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoQualityControlParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",BindingQualityParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoQualityControlParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",BindingQualityParams";
	};
}; // end namespace JDF
