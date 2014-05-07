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

 
#include "jdf/wrapper/AutoJDF/JDFAutoQualityControlResult.h"
#include "jdf/wrapper/JDFBindingQualityParams.h"
#include "jdf/wrapper/JDFFileSpec.h"
#include "jdf/wrapper/JDFQualityMeasurement.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoQualityControlResult : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoQualityControlResult& JDFAutoQualityControlResult::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoQualityControlResult: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoQualityControlResult::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoQualityControlResult::ValidNodeNames()const{
	return L"*:,QualityControlResult";
};

bool JDFAutoQualityControlResult::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoQualityControlResult::init(){
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
	WString JDFAutoQualityControlResult::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Failed,Passed");
};

/**
 typesafe validator
*/
	vWString JDFAutoQualityControlResult::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFailed(level)) {
			vAtts.push_back(atr_Failed);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPassed(level)) {
			vAtts.push_back(atr_Passed);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Failed
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQualityControlResult::SetFailed(int value){
	SetAttribute(atr_Failed,WString::valueOf(value));
};
/**
* Get integer attribute Failed
* @return int the vaue of the attribute 
*/
	 int JDFAutoQualityControlResult::GetFailed() const {
	return GetIntAttribute(atr_Failed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityControlResult::ValidFailed(EnumValidationLevel level) const {
		return ValidAttribute(atr_Failed,AttributeType_integer,false);
	};
/**
* Set attribute Passed
*@param int value: the value to set the attribute to
*/
	 void JDFAutoQualityControlResult::SetPassed(int value){
	SetAttribute(atr_Passed,WString::valueOf(value));
};
/**
* Get integer attribute Passed
* @return int the vaue of the attribute 
*/
	 int JDFAutoQualityControlResult::GetPassed() const {
	return GetIntAttribute(atr_Passed,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoQualityControlResult::ValidPassed(EnumValidationLevel level) const {
		return ValidAttribute(atr_Passed,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBindingQualityParams JDFAutoQualityControlResult::GetBindingQualityParams()const{
	JDFBindingQualityParams e=GetElement(elm_BindingQualityParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindingQualityParams JDFAutoQualityControlResult::GetCreateBindingQualityParams(){
	JDFBindingQualityParams e=GetCreateElement(elm_BindingQualityParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindingQualityParams JDFAutoQualityControlResult::AppendBindingQualityParams(){
	JDFBindingQualityParams e=AppendElementN(elm_BindingQualityParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoQualityControlResult::GetFileSpec()const{
	JDFFileSpec e=GetElement(elm_FileSpec);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoQualityControlResult::GetCreateFileSpec(){
	JDFFileSpec e=GetCreateElement(elm_FileSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFileSpec JDFAutoQualityControlResult::AppendFileSpec(){
	JDFFileSpec e=AppendElementN(elm_FileSpec,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoQualityControlResult::RefFileSpec(JDFFileSpec& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFQualityMeasurement JDFAutoQualityControlResult::GetQualityMeasurement(int iSkip)const{
	JDFQualityMeasurement e=GetElement(elm_QualityMeasurement,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityMeasurement JDFAutoQualityControlResult::GetCreateQualityMeasurement(int iSkip){
	JDFQualityMeasurement e=GetCreateElement(elm_QualityMeasurement,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityMeasurement JDFAutoQualityControlResult::AppendQualityMeasurement(){
	JDFQualityMeasurement e=AppendElement(elm_QualityMeasurement);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoQualityControlResult::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
		nElem=NumChildElements(elm_FileSpec);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FileSpec);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFileSpec().IsValid(level)) {
				vElem.AppendUnique(elm_FileSpec);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_QualityMeasurement);

		for(i=0;i<nElem;i++){
			if (!GetQualityMeasurement(i).IsValid(level)) {
				vElem.AppendUnique(elm_QualityMeasurement);
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
	WString JDFAutoQualityControlResult::UniqueElements()const{
		return JDFResource::UniqueElements()+L",BindingQualityParams,FileSpec";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoQualityControlResult::OptionalElements()const{
		return JDFResource::OptionalElements()+L",BindingQualityParams,FileSpec,QualityMeasurement";
	};
}; // end namespace JDF
