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

 
#include "jdf/wrapper/AutoJDF/JDFAutoColorIntent.h"
#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFSeparationList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoColorIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoColorIntent& JDFAutoColorIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoColorIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoColorIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoColorIntent::ValidNodeNames()const{
	return L"*:,ColorIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoColorIntent::OptionalAttributes()const{
		return JDFIntentResource::OptionalAttributes()+WString(L",NumColors");
};

/**
 typesafe validator
*/
	vWString JDFAutoColorIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidNumColors(level)) {
			vAtts.push_back(atr_NumColors);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute NumColors
*@param int value: the value to set the attribute to
*/
	 void JDFAutoColorIntent::SetNumColors(int value){
	SetAttribute(atr_NumColors,WString::valueOf(value));
};
/**
* Get integer attribute NumColors
* @return int the vaue of the attribute 
*/
	 int JDFAutoColorIntent::GetNumColors() const {
	return GetIntAttribute(atr_NumColors,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoColorIntent::ValidNumColors(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumColors,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFStringSpan JDFAutoColorIntent::GetCoatings()const{
	JDFStringSpan e=GetElement(elm_Coatings);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoColorIntent::GetCreateCoatings(){
	JDFStringSpan e=GetCreateElement(elm_Coatings);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoColorIntent::AppendCoatings(){
	JDFStringSpan e=AppendElementN(elm_Coatings,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoColorIntent::GetColorStandard()const{
	JDFNameSpan e=GetElement(elm_ColorStandard);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoColorIntent::GetCreateColorStandard(){
	JDFNameSpan e=GetCreateElement(elm_ColorStandard);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoColorIntent::AppendColorStandard(){
	JDFNameSpan e=AppendElementN(elm_ColorStandard,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoColorIntent::GetColorICCStandard()const{
	JDFStringSpan e=GetElement(elm_ColorICCStandard);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoColorIntent::GetCreateColorICCStandard(){
	JDFStringSpan e=GetCreateElement(elm_ColorICCStandard);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoColorIntent::AppendColorICCStandard(){
	JDFStringSpan e=AppendElementN(elm_ColorICCStandard,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoColorIntent::GetCoverage()const{
	JDFNumberSpan e=GetElement(elm_Coverage);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoColorIntent::GetCreateCoverage(){
	JDFNumberSpan e=GetCreateElement(elm_Coverage);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoColorIntent::AppendCoverage(){
	JDFNumberSpan e=AppendElementN(elm_Coverage,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoColorIntent::GetInkManufacturer()const{
	JDFNameSpan e=GetElement(elm_InkManufacturer);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoColorIntent::GetCreateInkManufacturer(){
	JDFNameSpan e=GetCreateElement(elm_InkManufacturer);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoColorIntent::AppendInkManufacturer(){
	JDFNameSpan e=AppendElementN(elm_InkManufacturer,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoColorIntent::GetColorPool()const{
	JDFColorPool e=GetElement(elm_ColorPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoColorIntent::GetCreateColorPool(){
	JDFColorPool e=GetCreateElement(elm_ColorPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoColorIntent::AppendColorPool(){
	JDFColorPool e=AppendElementN(elm_ColorPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoColorIntent::RefColorPool(JDFColorPool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorIntent::GetColorsUsed()const{
	JDFSeparationList e=GetElement(elm_ColorsUsed);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorIntent::GetCreateColorsUsed(){
	JDFSeparationList e=GetCreateElement(elm_ColorsUsed);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationList JDFAutoColorIntent::AppendColorsUsed(){
	JDFSeparationList e=AppendElementN(elm_ColorsUsed,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoColorIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Coatings);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Coatings);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCoatings().IsValid(level)) {
				vElem.AppendUnique(elm_Coatings);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorStandard);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorStandard);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorStandard().IsValid(level)) {
				vElem.AppendUnique(elm_ColorStandard);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorICCStandard);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorICCStandard);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorICCStandard().IsValid(level)) {
				vElem.AppendUnique(elm_ColorICCStandard);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Coverage);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Coverage);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCoverage().IsValid(level)) {
				vElem.AppendUnique(elm_Coverage);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_InkManufacturer);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_InkManufacturer);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetInkManufacturer().IsValid(level)) {
				vElem.AppendUnique(elm_InkManufacturer);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorPool().IsValid(level)) {
				vElem.AppendUnique(elm_ColorPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorsUsed);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorsUsed);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorsUsed().IsValid(level)) {
				vElem.AppendUnique(elm_ColorsUsed);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoColorIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",Coatings,ColorStandard,ColorICCStandard,Coverage,InkManufacturer,ColorPool,ColorsUsed";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoColorIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",Coatings,ColorStandard,ColorICCStandard,Coverage,InkManufacturer,ColorPool,ColorsUsed";
	};
}; // end namespace JDF
