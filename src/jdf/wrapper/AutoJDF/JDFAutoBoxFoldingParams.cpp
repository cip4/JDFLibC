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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBoxFoldingParams.h"
#include "jdf/wrapper/JDFBoxFoldAction.h"
#include "jdf/wrapper/JDFGlueLine.h"
#include "jdf/wrapper/JDFBoxApplication.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBoxFoldingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBoxFoldingParams& JDFAutoBoxFoldingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBoxFoldingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBoxFoldingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBoxFoldingParams::ValidNodeNames()const{
	return L"*:,BoxFoldingParams";
};

bool JDFAutoBoxFoldingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoBoxFoldingParams::init(){
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
	WString JDFAutoBoxFoldingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BlankDimensionsX,BlankDimensionsY,BoxFoldingType");
};

/**
 typesafe validator
*/
	vWString JDFAutoBoxFoldingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBlankDimensionsX(level)) {
			vAtts.push_back(atr_BlankDimensionsX);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlankDimensionsY(level)) {
			vAtts.push_back(atr_BlankDimensionsY);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBoxFoldingType(level)) {
			vAtts.push_back(atr_BoxFoldingType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BlankDimensionsX
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoBoxFoldingParams::SetBlankDimensionsX(const JDFNumberList& value){
	SetAttribute(atr_BlankDimensionsX,value.GetString());
};
/**
* Get string attribute BlankDimensionsX
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoBoxFoldingParams::GetBlankDimensionsX() const {
	return GetAttribute(atr_BlankDimensionsX,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxFoldingParams::ValidBlankDimensionsX(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlankDimensionsX,AttributeType_NumberList,false);
	};
/**
* Set attribute BlankDimensionsY
*@param JDFNumberList value: the value to set the attribute to
*/
	 void JDFAutoBoxFoldingParams::SetBlankDimensionsY(const JDFNumberList& value){
	SetAttribute(atr_BlankDimensionsY,value.GetString());
};
/**
* Get string attribute BlankDimensionsY
* @return JDFNumberList the vaue of the attribute 
*/
	 JDFNumberList JDFAutoBoxFoldingParams::GetBlankDimensionsY() const {
	return GetAttribute(atr_BlankDimensionsY,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxFoldingParams::ValidBlankDimensionsY(EnumValidationLevel level) const {
		return ValidAttribute(atr_BlankDimensionsY,AttributeType_NumberList,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBoxFoldingParams::BoxFoldingTypeString(){
		static const WString enums=WString(L"Unknown,Type00,Type01,Type02,Type03,Type04,Type10,Type11,Type12,Type13")
	+WString(L",Type15,Type20");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBoxFoldingParams::BoxFoldingTypeString(EnumBoxFoldingType value){
		return BoxFoldingTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBoxFoldingParams::SetBoxFoldingType( EnumBoxFoldingType value){
	SetEnumAttribute(atr_BoxFoldingType,value,BoxFoldingTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBoxFoldingParams::EnumBoxFoldingType JDFAutoBoxFoldingParams:: GetBoxFoldingType() const {
	return (EnumBoxFoldingType) GetEnumAttribute(atr_BoxFoldingType,BoxFoldingTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBoxFoldingParams::ValidBoxFoldingType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BoxFoldingType,BoxFoldingTypeString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBoxFoldAction JDFAutoBoxFoldingParams::GetBoxFoldAction(int iSkip)const{
	JDFBoxFoldAction e=GetElement(elm_BoxFoldAction,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBoxFoldAction JDFAutoBoxFoldingParams::GetCreateBoxFoldAction(int iSkip){
	JDFBoxFoldAction e=GetCreateElement(elm_BoxFoldAction,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBoxFoldAction JDFAutoBoxFoldingParams::AppendBoxFoldAction(){
	JDFBoxFoldAction e=AppendElement(elm_BoxFoldAction);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoBoxFoldingParams::GetGlueLine(int iSkip)const{
	JDFGlueLine e=GetElement(elm_GlueLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoBoxFoldingParams::GetCreateGlueLine(int iSkip){
	JDFGlueLine e=GetCreateElement(elm_GlueLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoBoxFoldingParams::AppendGlueLine(){
	JDFGlueLine e=AppendElement(elm_GlueLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoBoxFoldingParams::RefGlueLine(JDFGlueLine& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFBoxApplication JDFAutoBoxFoldingParams::GetBoxApplication(int iSkip)const{
	JDFBoxApplication e=GetElement(elm_BoxApplication,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBoxApplication JDFAutoBoxFoldingParams::GetCreateBoxApplication(int iSkip){
	JDFBoxApplication e=GetCreateElement(elm_BoxApplication,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBoxApplication JDFAutoBoxFoldingParams::AppendBoxApplication(){
	JDFBoxApplication e=AppendElement(elm_BoxApplication);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBoxFoldingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BoxFoldAction);

		for(i=0;i<nElem;i++){
			if (!GetBoxFoldAction(i).IsValid(level)) {
				vElem.AppendUnique(elm_BoxFoldAction);
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
		nElem=NumChildElements(elm_BoxApplication);

		for(i=0;i<nElem;i++){
			if (!GetBoxApplication(i).IsValid(level)) {
				vElem.AppendUnique(elm_BoxApplication);
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
	WString JDFAutoBoxFoldingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",BoxFoldAction,GlueLine,BoxApplication";
	};
}; // end namespace JDF
