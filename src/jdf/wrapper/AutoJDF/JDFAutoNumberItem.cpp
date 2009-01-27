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

 
#include "jdf/wrapper/AutoJDF/JDFAutoNumberItem.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoNumberItem : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoNumberItem& JDFAutoNumberItem::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoNumberItem: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoNumberItem::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoNumberItem::ValidNodeNames()const{
	return L"*:,NumberItem";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoNumberItem::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",StartValue,Step");
};

/**
 typesafe validator
*/
	vWString JDFAutoNumberItem::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidStartValue(level)) {
			vAtts.push_back(atr_StartValue);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStep(level)) {
			vAtts.push_back(atr_Step);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute StartValue
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoNumberItem::SetStartValue(const WString& value){
	SetAttribute(atr_StartValue,value);
};
/**
* Get string attribute StartValue
* @return WString the vaue of the attribute ; defaults to 1
*/
	 WString JDFAutoNumberItem::GetStartValue() const {
	return GetAttribute(atr_StartValue,WString::emptyStr,L"1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNumberItem::ValidStartValue(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartValue,AttributeType_string,false);
	};
/**
* Set attribute Step
*@param int value: the value to set the attribute to
*/
	 void JDFAutoNumberItem::SetStep(int value){
	SetAttribute(atr_Step,WString::valueOf(value));
};
/**
* Get integer attribute Step
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoNumberItem::GetStep() const {
	return GetIntAttribute(atr_Step,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoNumberItem::ValidStep(EnumValidationLevel level) const {
		return ValidAttribute(atr_Step,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpanNamedColor JDFAutoNumberItem::GetColorName()const{
	JDFSpanNamedColor e=GetElement(elm_ColorName);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoNumberItem::GetCreateColorName(){
	JDFSpanNamedColor e=GetCreateElement(elm_ColorName);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoNumberItem::AppendColorName(){
	JDFSpanNamedColor e=AppendElementN(elm_ColorName,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoNumberItem::GetColorNameDetails(int iSkip)const{
	JDFStringSpan e=GetElement(elm_ColorNameDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoNumberItem::GetCreateColorNameDetails(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_ColorNameDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoNumberItem::AppendColorNameDetails(){
	JDFStringSpan e=AppendElement(elm_ColorNameDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::GetXPosition()const{
	JDFNumberSpan e=GetElement(elm_XPosition);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::GetCreateXPosition(){
	JDFNumberSpan e=GetCreateElement(elm_XPosition);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::AppendXPosition(){
	JDFNumberSpan e=AppendElementN(elm_XPosition,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::GetYPosition()const{
	JDFNumberSpan e=GetElement(elm_YPosition);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::GetCreateYPosition(){
	JDFNumberSpan e=GetCreateElement(elm_YPosition);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::AppendYPosition(){
	JDFNumberSpan e=AppendElementN(elm_YPosition,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::GetOrientation()const{
	JDFNumberSpan e=GetElement(elm_Orientation);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::GetCreateOrientation(){
	JDFNumberSpan e=GetCreateElement(elm_Orientation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoNumberItem::AppendOrientation(){
	JDFNumberSpan e=AppendElementN(elm_Orientation,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoNumberItem::GetSeparationSpec()const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoNumberItem::GetCreateSeparationSpec(){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoNumberItem::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElementN(elm_SeparationSpec,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoNumberItem::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorName);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorName);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorName().IsValid(level)) {
				vElem.AppendUnique(elm_ColorName);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorNameDetails);

		for(i=0;i<nElem;i++){
			if (!GetColorNameDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorNameDetails);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_XPosition);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_XPosition);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetXPosition().IsValid(level)) {
				vElem.AppendUnique(elm_XPosition);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_YPosition);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_YPosition);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetYPosition().IsValid(level)) {
				vElem.AppendUnique(elm_YPosition);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Orientation);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Orientation);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetOrientation().IsValid(level)) {
				vElem.AppendUnique(elm_Orientation);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_SeparationSpec);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_SeparationSpec);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetSeparationSpec().IsValid(level)) {
				vElem.AppendUnique(elm_SeparationSpec);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoNumberItem::UniqueElements()const{
		return JDFElement::UniqueElements()+L",ColorName,XPosition,YPosition,Orientation,SeparationSpec";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoNumberItem::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ColorName,ColorNameDetails,XPosition,YPosition,Orientation,SeparationSpec";
	};
}; // end namespace JDF
