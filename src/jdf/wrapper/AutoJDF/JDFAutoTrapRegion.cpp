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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTrapRegion.h"
#include "jdf/wrapper/JDFTrappingParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTrapRegion : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTrapRegion& JDFAutoTrapRegion::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTrapRegion: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTrapRegion::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTrapRegion::ValidNodeNames()const{
	return L"*:,TrapRegion";
};

bool JDFAutoTrapRegion::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoTrapRegion::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoTrapRegion::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Pages";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoTrapRegion::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",TrapZone");
};

/**
 typesafe validator
*/
	vWString JDFAutoTrapRegion::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidPages(level)) {
			vAtts.push_back(atr_Pages);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrapZone(level)) {
			vAtts.push_back(atr_TrapZone);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Pages
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoTrapRegion::SetPages(const JDFIntegerRangeList& value){
	SetAttribute(atr_Pages,value.GetString());
};
/**
* Get range attribute Pages
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoTrapRegion::GetPages() const {
	return GetAttribute(atr_Pages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrapRegion::ValidPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_Pages,AttributeType_IntegerRangeList,RequiredLevel(level));
	};
/**
* Set attribute TrapZone
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoTrapRegion::SetTrapZone(const WString& value){
	SetAttribute(atr_TrapZone,value);
};
/**
* Get string attribute TrapZone
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoTrapRegion::GetTrapZone() const {
	return GetAttribute(atr_TrapZone,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTrapRegion::ValidTrapZone(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrapZone,AttributeType_PDFPath,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTrappingParams JDFAutoTrapRegion::GetTrappingParams()const{
	JDFTrappingParams e=GetElement(elm_TrappingParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrappingParams JDFAutoTrapRegion::GetCreateTrappingParams(){
	JDFTrappingParams e=GetCreateElement(elm_TrappingParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTrappingParams JDFAutoTrapRegion::AppendTrappingParams(){
	JDFTrappingParams e=AppendElementN(elm_TrappingParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoTrapRegion::RefTrappingParams(JDFTrappingParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoTrapRegion::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_TrappingParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_TrappingParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTrappingParams().IsValid(level)) {
				vElem.AppendUnique(elm_TrappingParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoTrapRegion::UniqueElements()const{
		return JDFResource::UniqueElements()+L",TrappingParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoTrapRegion::OptionalElements()const{
		return JDFResource::OptionalElements()+L",TrappingParams";
	};
}; // end namespace JDF
