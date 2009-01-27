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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLaminatingIntent.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLaminatingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLaminatingIntent& JDFAutoLaminatingIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLaminatingIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLaminatingIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLaminatingIntent::ValidNodeNames()const{
	return L"*:,LaminatingIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoLaminatingIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFOptionSpan JDFAutoLaminatingIntent::GetLaminated()const{
	JDFOptionSpan e=GetElement(elm_Laminated);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoLaminatingIntent::GetCreateLaminated(){
	JDFOptionSpan e=GetCreateElement(elm_Laminated);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoLaminatingIntent::AppendLaminated(){
	JDFOptionSpan e=AppendElementN(elm_Laminated,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTemperature JDFAutoLaminatingIntent::GetTemperature()const{
	JDFSpanTemperature e=GetElement(elm_Temperature);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTemperature JDFAutoLaminatingIntent::GetCreateTemperature(){
	JDFSpanTemperature e=GetCreateElement(elm_Temperature);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTemperature JDFAutoLaminatingIntent::AppendTemperature(){
	JDFSpanTemperature e=AppendElementN(elm_Temperature,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanSurface JDFAutoLaminatingIntent::GetSurface()const{
	JDFSpanSurface e=GetElement(elm_Surface);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanSurface JDFAutoLaminatingIntent::GetCreateSurface(){
	JDFSpanSurface e=GetCreateElement(elm_Surface);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanSurface JDFAutoLaminatingIntent::AppendSurface(){
	JDFSpanSurface e=AppendElementN(elm_Surface,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoLaminatingIntent::GetTexture()const{
	JDFNameSpan e=GetElement(elm_Texture);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoLaminatingIntent::GetCreateTexture(){
	JDFNameSpan e=GetCreateElement(elm_Texture);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoLaminatingIntent::AppendTexture(){
	JDFNameSpan e=AppendElementN(elm_Texture,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoLaminatingIntent::GetThickness()const{
	JDFNumberSpan e=GetElement(elm_Thickness);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoLaminatingIntent::GetCreateThickness(){
	JDFNumberSpan e=GetCreateElement(elm_Thickness);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoLaminatingIntent::AppendThickness(){
	JDFNumberSpan e=AppendElementN(elm_Thickness,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLaminatingIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Laminated);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Laminated);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetLaminated().IsValid(level)) {
				vElem.AppendUnique(elm_Laminated);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Temperature);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_Temperature);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Temperature);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTemperature().IsValid(level)) {
				vElem.AppendUnique(elm_Temperature);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Surface);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Surface);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetSurface().IsValid(level)) {
				vElem.AppendUnique(elm_Surface);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Texture);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Texture);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTexture().IsValid(level)) {
				vElem.AppendUnique(elm_Texture);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Thickness);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Thickness);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetThickness().IsValid(level)) {
				vElem.AppendUnique(elm_Thickness);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoLaminatingIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",Laminated,Temperature,Surface,Texture,Thickness";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoLaminatingIntent::RequiredElements()const{
		return JDFIntentResource::RequiredElements()+L",Temperature";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoLaminatingIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",Laminated,Surface,Texture,Thickness";
	};
}; // end namespace JDF
