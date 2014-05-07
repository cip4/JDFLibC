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

 
#include "jdf/wrapper/AutoJDF/JDFAutoWireCombBinding.h"
#include "jdf/wrapper/JDFHoleList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoWireCombBinding : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoWireCombBinding& JDFAutoWireCombBinding::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoWireCombBinding: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoWireCombBinding::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoWireCombBinding::ValidNodeNames()const{
	return L"*:,WireCombBinding";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoWireCombBinding::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFStringSpan JDFAutoWireCombBinding::GetWireCombBrand(int iSkip)const{
	JDFStringSpan e=GetElement(elm_WireCombBrand,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoWireCombBinding::GetCreateWireCombBrand(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_WireCombBrand,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoWireCombBinding::AppendWireCombBrand(){
	JDFStringSpan e=AppendElement(elm_WireCombBrand);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanWireCombMaterial JDFAutoWireCombBinding::GetWireCombMaterial(int iSkip)const{
	JDFSpanWireCombMaterial e=GetElement(elm_WireCombMaterial,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanWireCombMaterial JDFAutoWireCombBinding::GetCreateWireCombMaterial(int iSkip){
	JDFSpanWireCombMaterial e=GetCreateElement(elm_WireCombMaterial,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanWireCombMaterial JDFAutoWireCombBinding::AppendWireCombMaterial(){
	JDFSpanWireCombMaterial e=AppendElement(elm_WireCombMaterial);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanWireCombShape JDFAutoWireCombBinding::GetWireCombShape(int iSkip)const{
	JDFSpanWireCombShape e=GetElement(elm_WireCombShape,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanWireCombShape JDFAutoWireCombBinding::GetCreateWireCombShape(int iSkip){
	JDFSpanWireCombShape e=GetCreateElement(elm_WireCombShape,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanWireCombShape JDFAutoWireCombBinding::AppendWireCombShape(){
	JDFSpanWireCombShape e=AppendElement(elm_WireCombShape);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoWireCombBinding::GetHoleList(int iSkip)const{
	JDFHoleList e=GetElement(elm_HoleList,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoWireCombBinding::GetCreateHoleList(int iSkip){
	JDFHoleList e=GetCreateElement(elm_HoleList,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoWireCombBinding::AppendHoleList(){
	JDFHoleList e=AppendElement(elm_HoleList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoWireCombBinding::RefHoleList(JDFHoleList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoWireCombBinding::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_WireCombBrand);

		for(i=0;i<nElem;i++){
			if (!GetWireCombBrand(i).IsValid(level)) {
				vElem.AppendUnique(elm_WireCombBrand);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_WireCombMaterial);

		for(i=0;i<nElem;i++){
			if (!GetWireCombMaterial(i).IsValid(level)) {
				vElem.AppendUnique(elm_WireCombMaterial);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_WireCombShape);

		for(i=0;i<nElem;i++){
			if (!GetWireCombShape(i).IsValid(level)) {
				vElem.AppendUnique(elm_WireCombShape);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_HoleList);

		for(i=0;i<nElem;i++){
			if (!GetHoleList(i).IsValid(level)) {
				vElem.AppendUnique(elm_HoleList);
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
	WString JDFAutoWireCombBinding::OptionalElements()const{
		return JDFElement::OptionalElements()+L",WireCombBrand,WireCombMaterial,WireCombShape,HoleList";
	};
}; // end namespace JDF
