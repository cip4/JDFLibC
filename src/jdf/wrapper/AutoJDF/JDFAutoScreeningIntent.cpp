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

 
#include "jdf/wrapper/AutoJDF/JDFAutoScreeningIntent.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoScreeningIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoScreeningIntent& JDFAutoScreeningIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoScreeningIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoScreeningIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoScreeningIntent::ValidNodeNames()const{
	return L"*:,ScreeningIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoScreeningIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFNumberSpan JDFAutoScreeningIntent::GetDotSize()const{
	JDFNumberSpan e=GetElement(elm_DotSize);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoScreeningIntent::GetCreateDotSize(){
	JDFNumberSpan e=GetCreateElement(elm_DotSize);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoScreeningIntent::AppendDotSize(){
	JDFNumberSpan e=AppendElementN(elm_DotSize,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoScreeningIntent::GetFrequency()const{
	JDFNumberSpan e=GetElement(elm_Frequency);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoScreeningIntent::GetCreateFrequency(){
	JDFNumberSpan e=GetCreateElement(elm_Frequency);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoScreeningIntent::AppendFrequency(){
	JDFNumberSpan e=AppendElementN(elm_Frequency,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanFrequencySelection JDFAutoScreeningIntent::GetFrequencySelection()const{
	JDFSpanFrequencySelection e=GetElement(elm_FrequencySelection);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanFrequencySelection JDFAutoScreeningIntent::GetCreateFrequencySelection(){
	JDFSpanFrequencySelection e=GetCreateElement(elm_FrequencySelection);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanFrequencySelection JDFAutoScreeningIntent::AppendFrequencySelection(){
	JDFSpanFrequencySelection e=AppendElementN(elm_FrequencySelection,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanScreeningType JDFAutoScreeningIntent::GetScreeningType()const{
	JDFSpanScreeningType e=GetElement(elm_ScreeningType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanScreeningType JDFAutoScreeningIntent::GetCreateScreeningType(){
	JDFSpanScreeningType e=GetCreateElement(elm_ScreeningType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanScreeningType JDFAutoScreeningIntent::AppendScreeningType(){
	JDFSpanScreeningType e=AppendElementN(elm_ScreeningType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoScreeningIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_DotSize);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DotSize);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDotSize().IsValid(level)) {
				vElem.AppendUnique(elm_DotSize);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Frequency);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Frequency);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFrequency().IsValid(level)) {
				vElem.AppendUnique(elm_Frequency);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FrequencySelection);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FrequencySelection);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFrequencySelection().IsValid(level)) {
				vElem.AppendUnique(elm_FrequencySelection);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ScreeningType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ScreeningType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetScreeningType().IsValid(level)) {
				vElem.AppendUnique(elm_ScreeningType);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoScreeningIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",DotSize,Frequency,FrequencySelection,ScreeningType";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoScreeningIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",DotSize,Frequency,FrequencySelection,ScreeningType";
	};
}; // end namespace JDF
