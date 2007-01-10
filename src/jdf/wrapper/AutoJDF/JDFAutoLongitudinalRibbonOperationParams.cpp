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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLongitudinalRibbonOperationParams.h"
#include "jdf/wrapper/JDFLongFold.h"
#include "jdf/wrapper/JDFLongGlue.h"
#include "jdf/wrapper/JDFLongPerforate.h"
#include "jdf/wrapper/JDFLongSlit.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLongitudinalRibbonOperationParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLongitudinalRibbonOperationParams& JDFAutoLongitudinalRibbonOperationParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLongitudinalRibbonOperationParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLongitudinalRibbonOperationParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLongitudinalRibbonOperationParams::ValidNodeNames()const{
	return L"*:,LongitudinalRibbonOperationParams";
};

bool JDFAutoLongitudinalRibbonOperationParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoLongitudinalRibbonOperationParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoLongitudinalRibbonOperationParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFLongFold JDFAutoLongitudinalRibbonOperationParams::GetLongFold(int iSkip)const{
	JDFLongFold e=GetElement(elm_LongFold,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongFold JDFAutoLongitudinalRibbonOperationParams::GetCreateLongFold(int iSkip){
	JDFLongFold e=GetCreateElement(elm_LongFold,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongFold JDFAutoLongitudinalRibbonOperationParams::AppendLongFold(){
	JDFLongFold e=AppendElement(elm_LongFold);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongGlue JDFAutoLongitudinalRibbonOperationParams::GetLongGlue(int iSkip)const{
	JDFLongGlue e=GetElement(elm_LongGlue,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongGlue JDFAutoLongitudinalRibbonOperationParams::GetCreateLongGlue(int iSkip){
	JDFLongGlue e=GetCreateElement(elm_LongGlue,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongGlue JDFAutoLongitudinalRibbonOperationParams::AppendLongGlue(){
	JDFLongGlue e=AppendElement(elm_LongGlue);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongPerforate JDFAutoLongitudinalRibbonOperationParams::GetLongPerforate(int iSkip)const{
	JDFLongPerforate e=GetElement(elm_LongPerforate,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongPerforate JDFAutoLongitudinalRibbonOperationParams::GetCreateLongPerforate(int iSkip){
	JDFLongPerforate e=GetCreateElement(elm_LongPerforate,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongPerforate JDFAutoLongitudinalRibbonOperationParams::AppendLongPerforate(){
	JDFLongPerforate e=AppendElement(elm_LongPerforate);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongSlit JDFAutoLongitudinalRibbonOperationParams::GetLongSlit(int iSkip)const{
	JDFLongSlit e=GetElement(elm_LongSlit,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongSlit JDFAutoLongitudinalRibbonOperationParams::GetCreateLongSlit(int iSkip){
	JDFLongSlit e=GetCreateElement(elm_LongSlit,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLongSlit JDFAutoLongitudinalRibbonOperationParams::AppendLongSlit(){
	JDFLongSlit e=AppendElement(elm_LongSlit);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLongitudinalRibbonOperationParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_LongFold);

		for(i=0;i<nElem;i++){
			if (!GetLongFold(i).IsValid(level)) {
				vElem.AppendUnique(elm_LongFold);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_LongGlue);

		for(i=0;i<nElem;i++){
			if (!GetLongGlue(i).IsValid(level)) {
				vElem.AppendUnique(elm_LongGlue);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_LongPerforate);

		for(i=0;i<nElem;i++){
			if (!GetLongPerforate(i).IsValid(level)) {
				vElem.AppendUnique(elm_LongPerforate);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_LongSlit);

		for(i=0;i<nElem;i++){
			if (!GetLongSlit(i).IsValid(level)) {
				vElem.AppendUnique(elm_LongSlit);
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
	WString JDFAutoLongitudinalRibbonOperationParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",LongFold,LongGlue,LongPerforate,LongSlit";
	};
}; // end namespace JDF
