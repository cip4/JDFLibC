/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLayoutElementPart.h"
#include "jdf/wrapper/JDFBarcodeProductionParams.h"
#include "jdf/wrapper/JDFLayoutElement.h"
#include "jdf/wrapper/JDFPositionObj.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLayoutElementPart : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLayoutElementPart& JDFAutoLayoutElementPart::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLayoutElementPart: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLayoutElementPart::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLayoutElementPart::ValidNodeNames()const{
	return L"*:,LayoutElementPart";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoLayoutElementPart::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ID");
};

/**
 typesafe validator
*/
	vWString JDFAutoLayoutElementPart::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoLayoutElementPart::SetID(const WString& value){
	SetAttribute(atr_ID,value);
};
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoLayoutElementPart::GetID() const {
	return GetAttribute(atr_ID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutElementPart::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_ID,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBarcodeProductionParams JDFAutoLayoutElementPart::GetBarcodeProductionParams(int iSkip)const{
	JDFBarcodeProductionParams e=GetElement(elm_BarcodeProductionParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBarcodeProductionParams JDFAutoLayoutElementPart::GetCreateBarcodeProductionParams(int iSkip){
	JDFBarcodeProductionParams e=GetCreateElement(elm_BarcodeProductionParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBarcodeProductionParams JDFAutoLayoutElementPart::AppendBarcodeProductionParams(){
	JDFBarcodeProductionParams e=AppendElement(elm_BarcodeProductionParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoLayoutElementPart::GetLayoutElement(int iSkip)const{
	JDFLayoutElement e=GetElement(elm_LayoutElement,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoLayoutElementPart::GetCreateLayoutElement(int iSkip){
	JDFLayoutElement e=GetCreateElement(elm_LayoutElement,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayoutElement JDFAutoLayoutElementPart::AppendLayoutElement(){
	JDFLayoutElement e=AppendElement(elm_LayoutElement);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutElementPart::RefLayoutElement(JDFLayoutElement& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPositionObj JDFAutoLayoutElementPart::GetPositionObj(int iSkip)const{
	JDFPositionObj e=GetElement(elm_PositionObj,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPositionObj JDFAutoLayoutElementPart::GetCreatePositionObj(int iSkip){
	JDFPositionObj e=GetCreateElement(elm_PositionObj,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPositionObj JDFAutoLayoutElementPart::AppendPositionObj(){
	JDFPositionObj e=AppendElement(elm_PositionObj);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLayoutElementPart::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BarcodeProductionParams);

		for(i=0;i<nElem;i++){
			if (!GetBarcodeProductionParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_BarcodeProductionParams);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_LayoutElement);

		for(i=0;i<nElem;i++){
			if (!GetLayoutElement(i).IsValid(level)) {
				vElem.AppendUnique(elm_LayoutElement);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PositionObj);

		for(i=0;i<nElem;i++){
			if (!GetPositionObj(i).IsValid(level)) {
				vElem.AppendUnique(elm_PositionObj);
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
	WString JDFAutoLayoutElementPart::OptionalElements()const{
		return JDFElement::OptionalElements()+L",BarcodeProductionParams,LayoutElement,PositionObj";
	};
}; // end namespace JDF
