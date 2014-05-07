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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSizeIntent.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSizeIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSizeIntent& JDFAutoSizeIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSizeIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSizeIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSizeIntent::ValidNodeNames()const{
	return L"*:,SizeIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoSizeIntent::OptionalAttributes()const{
		return JDFIntentResource::OptionalAttributes()+WString(L",Type");
};

/**
 typesafe validator
*/
	vWString JDFAutoSizeIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidType(level)) {
			vAtts.push_back(atr_Type);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoSizeIntent::TypeString(){
		static const WString enums=WString(L"Unknown,Folded,Flat");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoSizeIntent::TypeString(EnumType value){
		return TypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoSizeIntent::SetType( EnumType value){
	SetEnumAttribute(atr_Type,value,TypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoSizeIntent::EnumType JDFAutoSizeIntent:: GetType() const {
	return (EnumType) GetEnumAttribute(atr_Type,TypeString(),WString::emptyStr,Type_Folded);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoSizeIntent::ValidType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Type,TypeString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFXYPairSpan JDFAutoSizeIntent::GetDimensions()const{
	JDFXYPairSpan e=GetElement(elm_Dimensions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoSizeIntent::GetCreateDimensions(){
	JDFXYPairSpan e=GetCreateElement(elm_Dimensions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoSizeIntent::AppendDimensions(){
	JDFXYPairSpan e=AppendElementN(elm_Dimensions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoSizeIntent::GetPages()const{
	JDFIntegerSpan e=GetElement(elm_Pages);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoSizeIntent::GetCreatePages(){
	JDFIntegerSpan e=GetCreateElement(elm_Pages);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoSizeIntent::AppendPages(){
	JDFIntegerSpan e=AppendElementN(elm_Pages,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoSizeIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Dimensions);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_Dimensions);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Dimensions);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDimensions().IsValid(level)) {
				vElem.AppendUnique(elm_Dimensions);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Pages);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Pages);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPages().IsValid(level)) {
				vElem.AppendUnique(elm_Pages);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoSizeIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",Dimensions,Pages";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoSizeIntent::RequiredElements()const{
		return JDFIntentResource::RequiredElements()+L",Dimensions";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoSizeIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",Pages";
	};
}; // end namespace JDF
