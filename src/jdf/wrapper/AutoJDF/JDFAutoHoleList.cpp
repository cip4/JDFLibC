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

 
#include "jdf/wrapper/AutoJDF/JDFAutoHoleList.h"
#include "jdf/wrapper/JDFHole.h"
#include "jdf/wrapper/JDFHoleList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoHoleList : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoHoleList& JDFAutoHoleList::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoHoleList: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoHoleList::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoHoleList::ValidNodeNames()const{
	return L"*:,HoleList";
};

bool JDFAutoHoleList::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoHoleList::init(){
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
	vWString JDFAutoHoleList::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFHole JDFAutoHoleList::GetHole(int iSkip)const{
	JDFHole e=GetElement(elm_Hole,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHole JDFAutoHoleList::GetCreateHole(int iSkip){
	JDFHole e=GetCreateElement(elm_Hole,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHole JDFAutoHoleList::AppendHole(){
	JDFHole e=AppendElement(elm_Hole);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoHoleList::RefHole(JDFHole& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoHoleList::GetHoleLine(int iSkip)const{
	JDFHoleList e=GetElement(elm_HoleLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoHoleList::GetCreateHoleLine(int iSkip){
	JDFHoleList e=GetCreateElement(elm_HoleLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoHoleList::AppendHoleLine(){
	JDFHoleList e=AppendElement(elm_HoleLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoHoleList::RefHoleLine(JDFHoleList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoHoleList::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Hole);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_Hole);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetHole(i).IsValid(level)) {
				vElem.AppendUnique(elm_Hole);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_HoleLine);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_HoleLine);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetHoleLine(i).IsValid(level)) {
				vElem.AppendUnique(elm_HoleLine);
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
	WString JDFAutoHoleList::RequiredElements()const{
		return JDFResource::RequiredElements()+L",Hole,HoleLine";
	};
}; // end namespace JDF
