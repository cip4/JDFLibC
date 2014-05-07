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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCollatingItem.h"
#include "jdf/wrapper/JDFComponent.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCollatingItem : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCollatingItem& JDFAutoCollatingItem::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCollatingItem: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCollatingItem::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCollatingItem::ValidNodeNames()const{
	return L"*:,CollatingItem";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCollatingItem::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Amount,BundleDepth,Orientation,Transformation,TransformationContext");
};

/**
 typesafe validator
*/
	vWString JDFAutoCollatingItem::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAmount(level)) {
			vAtts.push_back(atr_Amount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBundleDepth(level)) {
			vAtts.push_back(atr_BundleDepth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrientation(level)) {
			vAtts.push_back(atr_Orientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransformation(level)) {
			vAtts.push_back(atr_Transformation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransformationContext(level)) {
			vAtts.push_back(atr_TransformationContext);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Amount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoCollatingItem::SetAmount(int value){
	SetAttribute(atr_Amount,WString::valueOf(value));
};
/**
* Get integer attribute Amount
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoCollatingItem::GetAmount() const {
	return GetIntAttribute(atr_Amount,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCollatingItem::ValidAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Amount,AttributeType_integer,false);
	};
/**
* Set attribute BundleDepth
*@param int value: the value to set the attribute to
*/
	 void JDFAutoCollatingItem::SetBundleDepth(int value){
	SetAttribute(atr_BundleDepth,WString::valueOf(value));
};
/**
* Get integer attribute BundleDepth
* @return int the vaue of the attribute 
*/
	 int JDFAutoCollatingItem::GetBundleDepth() const {
	return GetIntAttribute(atr_BundleDepth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCollatingItem::ValidBundleDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_BundleDepth,AttributeType_integer,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoCollatingItem::SetOrientation( EnumOrientation value){
	SetEnumAttribute(atr_Orientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCollatingItem::EnumOrientation JDFAutoCollatingItem:: GetOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_Orientation,OrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCollatingItem::ValidOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Orientation,OrientationString(),false);
	};
/**
* Set attribute Transformation
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoCollatingItem::SetTransformation(const JDFMatrix& value){
	SetAttribute(atr_Transformation,value);
};
/**
* Get string attribute Transformation
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoCollatingItem::GetTransformation() const {
	return GetAttribute(atr_Transformation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCollatingItem::ValidTransformation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Transformation,AttributeType_matrix,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCollatingItem::TransformationContextString(){
		static const WString enums=WString(L"Unknown,StackItem,Component,CollateItem");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCollatingItem::TransformationContextString(EnumTransformationContext value){
		return TransformationContextString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCollatingItem::SetTransformationContext( EnumTransformationContext value){
	SetEnumAttribute(atr_TransformationContext,value,TransformationContextString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCollatingItem::EnumTransformationContext JDFAutoCollatingItem:: GetTransformationContext() const {
	return (EnumTransformationContext) GetEnumAttribute(atr_TransformationContext,TransformationContextString(),WString::emptyStr,TransformationContext_StackItem);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCollatingItem::ValidTransformationContext(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_TransformationContext,TransformationContextString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFComponent JDFAutoCollatingItem::GetComponent(int iSkip)const{
	JDFComponent e=GetElement(elm_Component,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoCollatingItem::GetCreateComponent(int iSkip){
	JDFComponent e=GetCreateElement(elm_Component,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoCollatingItem::AppendComponent(){
	JDFComponent e=AppendElement(elm_Component);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCollatingItem::RefComponent(JDFComponent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoCollatingItem::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoCollatingItem::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoCollatingItem::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCollatingItem::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCollatingItem::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Component);

		for(i=0;i<nElem;i++){
			if (!GetComponent(i).IsValid(level)) {
				vElem.AppendUnique(elm_Component);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Media);

		for(i=0;i<nElem;i++){
			if (!GetMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_Media);
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
	WString JDFAutoCollatingItem::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Component,Media";
	};
}; // end namespace JDF
