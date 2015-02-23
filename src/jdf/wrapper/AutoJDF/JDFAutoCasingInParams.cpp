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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCasingInParams.h"
#include "jdf/wrapper/JDFGlueApplication.h"
#include "jdf/wrapper/JDFGlueLine.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCasingInParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCasingInParams& JDFAutoCasingInParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCasingInParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCasingInParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCasingInParams::ValidNodeNames()const{
	return L"*:,CasingInParams";
};

bool JDFAutoCasingInParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoCasingInParams::init(){
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
	WString JDFAutoCasingInParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",CaseRadius,CoverBoardWidth,SpineBoardWidth");
};

/**
 typesafe validator
*/
	vWString JDFAutoCasingInParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCaseRadius(level)) {
			vAtts.push_back(atr_CaseRadius);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCoverBoardWidth(level)) {
			vAtts.push_back(atr_CoverBoardWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpineBoardWidth(level)) {
			vAtts.push_back(atr_SpineBoardWidth);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CaseRadius
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCasingInParams::SetCaseRadius(double value){
	SetAttribute(atr_CaseRadius,WString::valueOf(value));
};
/**
* Get double attribute CaseRadius
* @return double the vaue of the attribute 
*/
	 double JDFAutoCasingInParams::GetCaseRadius() const {
	return GetRealAttribute(atr_CaseRadius,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCasingInParams::ValidCaseRadius(EnumValidationLevel level) const {
		return ValidAttribute(atr_CaseRadius,AttributeType_double,false);
	};
/**
* Set attribute CoverBoardWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCasingInParams::SetCoverBoardWidth(double value){
	SetAttribute(atr_CoverBoardWidth,WString::valueOf(value));
};
/**
* Get double attribute CoverBoardWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoCasingInParams::GetCoverBoardWidth() const {
	return GetRealAttribute(atr_CoverBoardWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCasingInParams::ValidCoverBoardWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_CoverBoardWidth,AttributeType_double,false);
	};
/**
* Set attribute SpineBoardWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCasingInParams::SetSpineBoardWidth(double value){
	SetAttribute(atr_SpineBoardWidth,WString::valueOf(value));
};
/**
* Get double attribute SpineBoardWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoCasingInParams::GetSpineBoardWidth() const {
	return GetRealAttribute(atr_SpineBoardWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCasingInParams::ValidSpineBoardWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpineBoardWidth,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFGlueApplication JDFAutoCasingInParams::GetGlueApplication(int iSkip)const{
	JDFGlueApplication e=GetElement(elm_GlueApplication,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueApplication JDFAutoCasingInParams::GetCreateGlueApplication(int iSkip){
	JDFGlueApplication e=GetCreateElement(elm_GlueApplication,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueApplication JDFAutoCasingInParams::AppendGlueApplication(){
	JDFGlueApplication e=AppendElement(elm_GlueApplication);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCasingInParams::RefGlueApplication(JDFGlueApplication& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoCasingInParams::GetGlueLine(int iSkip)const{
	JDFGlueLine e=GetElement(elm_GlueLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoCasingInParams::GetCreateGlueLine(int iSkip){
	JDFGlueLine e=GetCreateElement(elm_GlueLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoCasingInParams::AppendGlueLine(){
	JDFGlueLine e=AppendElement(elm_GlueLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCasingInParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_GlueApplication);

		for(i=0;i<nElem;i++){
			if (!GetGlueApplication(i).IsValid(level)) {
				vElem.AppendUnique(elm_GlueApplication);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_GlueLine);

		for(i=0;i<nElem;i++){
			if (!GetGlueLine(i).IsValid(level)) {
				vElem.AppendUnique(elm_GlueLine);
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
	WString JDFAutoCasingInParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",GlueApplication,GlueLine";
	};
}; // end namespace JDF
