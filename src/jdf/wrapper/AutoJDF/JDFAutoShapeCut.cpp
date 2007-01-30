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

 
#include "jdf/wrapper/AutoJDF/JDFAutoShapeCut.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoShapeCut : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoShapeCut& JDFAutoShapeCut::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoShapeCut: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoShapeCut::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoShapeCut::ValidNodeNames()const{
	return L"*:,ShapeCut";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoShapeCut::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",CutBox,CutOut,CutPath,Pages");
};

/**
 typesafe validator
*/
	vWString JDFAutoShapeCut::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCutBox(level)) {
			vAtts.push_back(atr_CutBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutOut(level)) {
			vAtts.push_back(atr_CutOut);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCutPath(level)) {
			vAtts.push_back(atr_CutPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPages(level)) {
			vAtts.push_back(atr_Pages);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute CutBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoShapeCut::SetCutBox(const JDFRectangle& value){
	SetAttribute(atr_CutBox,value);
};
/**
* Get string attribute CutBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoShapeCut::GetCutBox() const {
	return GetAttribute(atr_CutBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeCut::ValidCutBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutBox,AttributeType_rectangle,false);
	};
/**
* Set attribute CutOut
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoShapeCut::SetCutOut(bool value){
	SetAttribute(atr_CutOut,WString::valueOf(value));
};
/**
* Get bool attribute CutOut
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoShapeCut::GetCutOut() const {return GetBoolAttribute(atr_CutOut,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeCut::ValidCutOut(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutOut,AttributeType_boolean,false);
	};
/**
* Set attribute CutPath
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoShapeCut::SetCutPath(const WString& value){
	SetAttribute(atr_CutPath,value);
};
/**
* Get string attribute CutPath
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoShapeCut::GetCutPath() const {
	return GetAttribute(atr_CutPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeCut::ValidCutPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_CutPath,AttributeType_PDFPath,false);
	};
/**
* Set attribute Pages
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoShapeCut::SetPages(const JDFIntegerRangeList& value){
	SetAttribute(atr_Pages,value.GetString());
};
/**
* Get range attribute Pages
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoShapeCut::GetPages() const {
	return GetAttribute(atr_Pages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeCut::ValidPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_Pages,AttributeType_IntegerRangeList,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFStringSpan JDFAutoShapeCut::GetMaterial()const{
	JDFStringSpan e=GetElement(elm_Material);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoShapeCut::GetCreateMaterial(){
	JDFStringSpan e=GetCreateElement(elm_Material);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoShapeCut::AppendMaterial(){
	JDFStringSpan e=AppendElementN(elm_Material,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanCutType JDFAutoShapeCut::GetCutType()const{
	JDFSpanCutType e=GetElement(elm_CutType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanCutType JDFAutoShapeCut::GetCreateCutType(){
	JDFSpanCutType e=GetCreateElement(elm_CutType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanCutType JDFAutoShapeCut::AppendCutType(){
	JDFSpanCutType e=AppendElementN(elm_CutType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoShapeCut::GetShapeDepth()const{
	JDFNumberSpan e=GetElement(elm_ShapeDepth);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoShapeCut::GetCreateShapeDepth(){
	JDFNumberSpan e=GetCreateElement(elm_ShapeDepth);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoShapeCut::AppendShapeDepth(){
	JDFNumberSpan e=AppendElementN(elm_ShapeDepth,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanShapeType JDFAutoShapeCut::GetShapeType()const{
	JDFSpanShapeType e=GetElement(elm_ShapeType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanShapeType JDFAutoShapeCut::GetCreateShapeType(){
	JDFSpanShapeType e=GetCreateElement(elm_ShapeType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanShapeType JDFAutoShapeCut::AppendShapeType(){
	JDFSpanShapeType e=AppendElementN(elm_ShapeType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoShapeCut::GetTeethPerDimension()const{
	JDFNumberSpan e=GetElement(elm_TeethPerDimension);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoShapeCut::GetCreateTeethPerDimension(){
	JDFNumberSpan e=GetCreateElement(elm_TeethPerDimension);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoShapeCut::AppendTeethPerDimension(){
	JDFNumberSpan e=AppendElementN(elm_TeethPerDimension,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoShapeCut::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Material);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Material);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMaterial().IsValid(level)) {
				vElem.AppendUnique(elm_Material);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_CutType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CutType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCutType().IsValid(level)) {
				vElem.AppendUnique(elm_CutType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ShapeDepth);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ShapeDepth);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetShapeDepth().IsValid(level)) {
				vElem.AppendUnique(elm_ShapeDepth);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ShapeType);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_ShapeType);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ShapeType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetShapeType().IsValid(level)) {
				vElem.AppendUnique(elm_ShapeType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_TeethPerDimension);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TeethPerDimension);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTeethPerDimension().IsValid(level)) {
				vElem.AppendUnique(elm_TeethPerDimension);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoShapeCut::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Material,CutType,ShapeDepth,ShapeType,TeethPerDimension";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoShapeCut::RequiredElements()const{
		return JDFElement::RequiredElements()+L",ShapeType";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoShapeCut::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Material,CutType,ShapeDepth,TeethPerDimension";
	};
}; // end namespace JDF
