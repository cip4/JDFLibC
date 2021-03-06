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

 
#include "jdf/wrapper/AutoJDF/JDFAutoNumberingIntent.h"
#include "jdf/wrapper/JDFColorPool.h"
#include "jdf/wrapper/JDFNumberItem.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoNumberingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoNumberingIntent& JDFAutoNumberingIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoNumberingIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoNumberingIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoNumberingIntent::ValidNodeNames()const{
	return L"*:,NumberingIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoNumberingIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpanNamedColor JDFAutoNumberingIntent::GetColorName()const{
	JDFSpanNamedColor e=GetElement(elm_ColorName);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoNumberingIntent::GetCreateColorName(){
	JDFSpanNamedColor e=GetCreateElement(elm_ColorName);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoNumberingIntent::AppendColorName(){
	JDFSpanNamedColor e=AppendElementN(elm_ColorName,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoNumberingIntent::GetColorNameDetails(int iSkip)const{
	JDFStringSpan e=GetElement(elm_ColorNameDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoNumberingIntent::GetCreateColorNameDetails(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_ColorNameDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoNumberingIntent::AppendColorNameDetails(){
	JDFStringSpan e=AppendElement(elm_ColorNameDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoNumberingIntent::GetColorPool()const{
	JDFColorPool e=GetElement(elm_ColorPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoNumberingIntent::GetCreateColorPool(){
	JDFColorPool e=GetCreateElement(elm_ColorPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColorPool JDFAutoNumberingIntent::AppendColorPool(){
	JDFColorPool e=AppendElementN(elm_ColorPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoNumberingIntent::RefColorPool(JDFColorPool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFNumberItem JDFAutoNumberingIntent::GetNumberItem(int iSkip)const{
	JDFNumberItem e=GetElement(elm_NumberItem,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberItem JDFAutoNumberingIntent::GetCreateNumberItem(int iSkip){
	JDFNumberItem e=GetCreateElement(elm_NumberItem,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberItem JDFAutoNumberingIntent::AppendNumberItem(){
	JDFNumberItem e=AppendElement(elm_NumberItem);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoNumberingIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
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
		nElem=NumChildElements(elm_NumberItem);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_NumberItem);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetNumberItem(i).IsValid(level)) {
				vElem.AppendUnique(elm_NumberItem);
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
	WString JDFAutoNumberingIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",ColorName,ColorPool";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoNumberingIntent::RequiredElements()const{
		return JDFIntentResource::RequiredElements()+L",NumberItem";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoNumberingIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",ColorName,ColorNameDetails,ColorPool";
	};
}; // end namespace JDF
