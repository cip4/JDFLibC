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

 
#include "jdf/wrapper/AutoJDF/JDFAutoHoleMakingIntent.h"
#include "jdf/wrapper/JDFHoleList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoHoleMakingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoHoleMakingIntent& JDFAutoHoleMakingIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoHoleMakingIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoHoleMakingIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoHoleMakingIntent::ValidNodeNames()const{
	return L"*:,HoleMakingIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoHoleMakingIntent::OptionalAttributes()const{
		return JDFIntentResource::OptionalAttributes()+WString(L",HoleReferenceEdge,Extent");
};

/**
 typesafe validator
*/
	vWString JDFAutoHoleMakingIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidHoleReferenceEdge(level)) {
			vAtts.push_back(atr_HoleReferenceEdge);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidExtent(level)) {
			vAtts.push_back(atr_Extent);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoHoleMakingIntent::HoleReferenceEdgeString(){
		static const WString enums=WString(L"Unknown,Left,Right,Top,Bottom,Pattern");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoHoleMakingIntent::HoleReferenceEdgeString(EnumHoleReferenceEdge value){
		return HoleReferenceEdgeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoHoleMakingIntent::SetHoleReferenceEdge( EnumHoleReferenceEdge value){
	SetEnumAttribute(atr_HoleReferenceEdge,value,HoleReferenceEdgeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoHoleMakingIntent::EnumHoleReferenceEdge JDFAutoHoleMakingIntent:: GetHoleReferenceEdge() const {
	return (EnumHoleReferenceEdge) GetEnumAttribute(atr_HoleReferenceEdge,HoleReferenceEdgeString(),WString::emptyStr,HoleReferenceEdge_Left);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingIntent::ValidHoleReferenceEdge(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_HoleReferenceEdge,HoleReferenceEdgeString(),false);
	};
/**
* Set attribute Extent
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoHoleMakingIntent::SetExtent(const JDFXYPair& value){
	SetAttribute(atr_Extent,value);
};
/**
* Get string attribute Extent
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoHoleMakingIntent::GetExtent() const {
	return GetAttribute(atr_Extent,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoHoleMakingIntent::ValidExtent(EnumValidationLevel level) const {
		return ValidAttribute(atr_Extent,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFStringSpan JDFAutoHoleMakingIntent::GetHoleType()const{
	JDFStringSpan e=GetElement(elm_HoleType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoHoleMakingIntent::GetCreateHoleType(){
	JDFStringSpan e=GetCreateElement(elm_HoleType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoHoleMakingIntent::AppendHoleType(){
	JDFStringSpan e=AppendElementN(elm_HoleType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoHoleMakingIntent::GetHoleList()const{
	JDFHoleList e=GetElement(elm_HoleList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoHoleMakingIntent::GetCreateHoleList(){
	JDFHoleList e=GetCreateElement(elm_HoleList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHoleList JDFAutoHoleMakingIntent::AppendHoleList(){
	JDFHoleList e=AppendElementN(elm_HoleList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoHoleMakingIntent::RefHoleList(JDFHoleList& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoHoleMakingIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_HoleType);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_HoleType);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_HoleType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetHoleType().IsValid(level)) {
				vElem.AppendUnique(elm_HoleType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_HoleList);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_HoleList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetHoleList().IsValid(level)) {
				vElem.AppendUnique(elm_HoleList);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoHoleMakingIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",HoleType,HoleList";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoHoleMakingIntent::RequiredElements()const{
		return JDFIntentResource::RequiredElements()+L",HoleType";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoHoleMakingIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",HoleList";
	};
}; // end namespace JDF
