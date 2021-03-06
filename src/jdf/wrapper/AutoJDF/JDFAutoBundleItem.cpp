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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBundleItem.h"
#include "jdf/wrapper/JDFComponent.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBundleItem : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBundleItem& JDFAutoBundleItem::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBundleItem: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBundleItem::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBundleItem::ValidNodeNames()const{
	return L"*:,BundleItem";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoBundleItem::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",Amount";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBundleItem::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ItemName,Orientation,Transformation");
};

/**
 typesafe validator
*/
	vWString JDFAutoBundleItem::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAmount(level)) {
			vAtts.push_back(atr_Amount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidItemName(level)) {
			vAtts.push_back(atr_ItemName);
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
		return vAtts;
	};

/**
* Set attribute Amount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBundleItem::SetAmount(int value){
	SetAttribute(atr_Amount,WString::valueOf(value));
};
/**
* Get integer attribute Amount
* @return int the vaue of the attribute 
*/
	 int JDFAutoBundleItem::GetAmount() const {
	return GetIntAttribute(atr_Amount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBundleItem::ValidAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Amount,AttributeType_integer,RequiredLevel(level));
	};
/**
* Set attribute ItemName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoBundleItem::SetItemName(const WString& value){
	SetAttribute(atr_ItemName,value);
};
/**
* Get string attribute ItemName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoBundleItem::GetItemName() const {
	return GetAttribute(atr_ItemName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBundleItem::ValidItemName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ItemName,AttributeType_NMTOKEN,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoBundleItem::SetOrientation( EnumOrientation value){
	SetEnumAttribute(atr_Orientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBundleItem::EnumOrientation JDFAutoBundleItem:: GetOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_Orientation,OrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBundleItem::ValidOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Orientation,OrientationString(),false);
	};
/**
* Set attribute Transformation
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoBundleItem::SetTransformation(const JDFMatrix& value){
	SetAttribute(atr_Transformation,value);
};
/**
* Get string attribute Transformation
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoBundleItem::GetTransformation() const {
	return GetAttribute(atr_Transformation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBundleItem::ValidTransformation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Transformation,AttributeType_matrix,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFComponent JDFAutoBundleItem::GetComponent()const{
	JDFComponent e=GetElement(elm_Component);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoBundleItem::GetCreateComponent(){
	JDFComponent e=GetCreateElement(elm_Component);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoBundleItem::AppendComponent(){
	JDFComponent e=AppendElementN(elm_Component,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoBundleItem::RefComponent(JDFComponent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBundleItem::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Component);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_Component);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Component);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetComponent().IsValid(level)) {
				vElem.AppendUnique(elm_Component);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoBundleItem::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Component";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoBundleItem::RequiredElements()const{
		return JDFElement::RequiredElements()+L",Component";
	};
}; // end namespace JDF
