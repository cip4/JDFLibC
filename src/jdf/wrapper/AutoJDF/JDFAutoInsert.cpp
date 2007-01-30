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

 
#include "jdf/wrapper/AutoJDF/JDFAutoInsert.h"
#include "jdf/wrapper/JDFGlueLine.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoInsert : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoInsert& JDFAutoInsert::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoInsert: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoInsert::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoInsert::ValidNodeNames()const{
	return L"*:,Insert";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoInsert::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Folio";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoInsert::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",SheetOffset,Transformation,WrapPages");
};

/**
 typesafe validator
*/
	vWString JDFAutoInsert::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFolio(level)) {
			vAtts.push_back(atr_Folio);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetOffset(level)) {
			vAtts.push_back(atr_SheetOffset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransformation(level)) {
			vAtts.push_back(atr_Transformation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWrapPages(level)) {
			vAtts.push_back(atr_WrapPages);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Folio
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoInsert::SetFolio(const JDFIntegerRangeList& value){
	SetAttribute(atr_Folio,value.GetString());
};
/**
* Get range attribute Folio
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoInsert::GetFolio() const {
	return GetAttribute(atr_Folio,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsert::ValidFolio(EnumValidationLevel level) const {
		return ValidAttribute(atr_Folio,AttributeType_IntegerRangeList,RequiredLevel(level));
	};
/**
* Set attribute SheetOffset
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoInsert::SetSheetOffset(const JDFXYPair& value){
	SetAttribute(atr_SheetOffset,value);
};
/**
* Get string attribute SheetOffset
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoInsert::GetSheetOffset() const {
	return GetAttribute(atr_SheetOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsert::ValidSheetOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetOffset,AttributeType_XYPair,false);
	};
/**
* Set attribute Transformation
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoInsert::SetTransformation(const JDFMatrix& value){
	SetAttribute(atr_Transformation,value);
};
/**
* Get string attribute Transformation
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoInsert::GetTransformation() const {
	return GetAttribute(atr_Transformation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsert::ValidTransformation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Transformation,AttributeType_matrix,false);
	};
/**
* Set attribute WrapPages
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoInsert::SetWrapPages(const JDFIntegerRangeList& value){
	SetAttribute(atr_WrapPages,value.GetString());
};
/**
* Get range attribute WrapPages
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoInsert::GetWrapPages() const {
	return GetAttribute(atr_WrapPages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsert::ValidWrapPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_WrapPages,AttributeType_IntegerRangeList,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpanGlueType JDFAutoInsert::GetGlueType()const{
	JDFSpanGlueType e=GetElement(elm_GlueType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlueType JDFAutoInsert::GetCreateGlueType(){
	JDFSpanGlueType e=GetCreateElement(elm_GlueType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlueType JDFAutoInsert::AppendGlueType(){
	JDFSpanGlueType e=AppendElementN(elm_GlueType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMethod JDFAutoInsert::GetMethod()const{
	JDFSpanMethod e=GetElement(elm_Method);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMethod JDFAutoInsert::GetCreateMethod(){
	JDFSpanMethod e=GetCreateElement(elm_Method);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMethod JDFAutoInsert::AppendMethod(){
	JDFSpanMethod e=AppendElementN(elm_Method,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoInsert::GetGlueLine(int iSkip)const{
	JDFGlueLine e=GetElement(elm_GlueLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoInsert::GetCreateGlueLine(int iSkip){
	JDFGlueLine e=GetCreateElement(elm_GlueLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoInsert::AppendGlueLine(){
	JDFGlueLine e=AppendElement(elm_GlueLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoInsert::RefGlueLine(JDFGlueLine& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoInsert::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_GlueType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_GlueType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetGlueType().IsValid(level)) {
				vElem.AppendUnique(elm_GlueType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Method);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Method);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMethod().IsValid(level)) {
				vElem.AppendUnique(elm_Method);
				if (++n>=nMax)
					return vElem;
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
 definition of required elements in the JDF namespace
*/
	WString JDFAutoInsert::UniqueElements()const{
		return JDFElement::UniqueElements()+L",GlueType,Method";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoInsert::OptionalElements()const{
		return JDFElement::OptionalElements()+L",GlueType,Method,GlueLine";
	};
}; // end namespace JDF
