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

 
#include "jdf/wrapper/AutoJDF/JDFAutoEmbossingItem.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoEmbossingItem : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoEmbossingItem& JDFAutoEmbossingItem::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoEmbossingItem: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoEmbossingItem::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoEmbossingItem::ValidNodeNames()const{
	return L"*:,EmbossingItem";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoEmbossingItem::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpanDirection JDFAutoEmbossingItem::GetDirection()const{
	JDFSpanDirection e=GetElement(elm_Direction);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanDirection JDFAutoEmbossingItem::GetCreateDirection(){
	JDFSpanDirection e=GetCreateElement(elm_Direction);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanDirection JDFAutoEmbossingItem::AppendDirection(){
	JDFSpanDirection e=AppendElementN(elm_Direction,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoEmbossingItem::GetEdgeAngle()const{
	JDFNumberSpan e=GetElement(elm_EdgeAngle);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoEmbossingItem::GetCreateEdgeAngle(){
	JDFNumberSpan e=GetCreateElement(elm_EdgeAngle);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoEmbossingItem::AppendEdgeAngle(){
	JDFNumberSpan e=AppendElementN(elm_EdgeAngle,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanEdgeShape JDFAutoEmbossingItem::GetEdgeShape()const{
	JDFSpanEdgeShape e=GetElement(elm_EdgeShape);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanEdgeShape JDFAutoEmbossingItem::GetCreateEdgeShape(){
	JDFSpanEdgeShape e=GetCreateElement(elm_EdgeShape);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanEdgeShape JDFAutoEmbossingItem::AppendEdgeShape(){
	JDFSpanEdgeShape e=AppendElementN(elm_EdgeShape,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoEmbossingItem::GetEmbossingType()const{
	JDFStringSpan e=GetElement(elm_EmbossingType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoEmbossingItem::GetCreateEmbossingType(){
	JDFStringSpan e=GetCreateElement(elm_EmbossingType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoEmbossingItem::AppendEmbossingType(){
	JDFStringSpan e=AppendElementN(elm_EmbossingType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoEmbossingItem::GetFoilColor()const{
	JDFSpanNamedColor e=GetElement(elm_FoilColor);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoEmbossingItem::GetCreateFoilColor(){
	JDFSpanNamedColor e=GetCreateElement(elm_FoilColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoEmbossingItem::AppendFoilColor(){
	JDFSpanNamedColor e=AppendElementN(elm_FoilColor,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoEmbossingItem::GetHeight()const{
	JDFNumberSpan e=GetElement(elm_Height);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoEmbossingItem::GetCreateHeight(){
	JDFNumberSpan e=GetCreateElement(elm_Height);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoEmbossingItem::AppendHeight(){
	JDFNumberSpan e=AppendElementN(elm_Height,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoEmbossingItem::GetImageSize()const{
	JDFXYPairSpan e=GetElement(elm_ImageSize);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoEmbossingItem::GetCreateImageSize(){
	JDFXYPairSpan e=GetCreateElement(elm_ImageSize);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoEmbossingItem::AppendImageSize(){
	JDFXYPairSpan e=AppendElementN(elm_ImageSize,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanLevel JDFAutoEmbossingItem::GetLevel()const{
	JDFSpanLevel e=GetElement(elm_Level);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanLevel JDFAutoEmbossingItem::GetCreateLevel(){
	JDFSpanLevel e=GetCreateElement(elm_Level);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanLevel JDFAutoEmbossingItem::AppendLevel(){
	JDFSpanLevel e=AppendElementN(elm_Level,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoEmbossingItem::GetPosition()const{
	JDFXYPairSpan e=GetElement(elm_Position);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoEmbossingItem::GetCreatePosition(){
	JDFXYPairSpan e=GetCreateElement(elm_Position);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoEmbossingItem::AppendPosition(){
	JDFXYPairSpan e=AppendElementN(elm_Position,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoEmbossingItem::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Direction);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_Direction);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Direction);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDirection().IsValid(level)) {
				vElem.AppendUnique(elm_Direction);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_EdgeAngle);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_EdgeAngle);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetEdgeAngle().IsValid(level)) {
				vElem.AppendUnique(elm_EdgeAngle);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_EdgeShape);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_EdgeShape);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetEdgeShape().IsValid(level)) {
				vElem.AppendUnique(elm_EdgeShape);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_EmbossingType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_EmbossingType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetEmbossingType().IsValid(level)) {
				vElem.AppendUnique(elm_EmbossingType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FoilColor);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FoilColor);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFoilColor().IsValid(level)) {
				vElem.AppendUnique(elm_FoilColor);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Height);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Height);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetHeight().IsValid(level)) {
				vElem.AppendUnique(elm_Height);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ImageSize);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ImageSize);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetImageSize().IsValid(level)) {
				vElem.AppendUnique(elm_ImageSize);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Level);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Level);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetLevel().IsValid(level)) {
				vElem.AppendUnique(elm_Level);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Position);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Position);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPosition().IsValid(level)) {
				vElem.AppendUnique(elm_Position);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoEmbossingItem::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Direction,EdgeAngle,EdgeShape,EmbossingType,FoilColor,Height,ImageSize,Level,Position";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoEmbossingItem::RequiredElements()const{
		return JDFElement::RequiredElements()+L",Direction";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoEmbossingItem::OptionalElements()const{
		return JDFElement::OptionalElements()+L",EdgeAngle,EdgeShape,EmbossingType,FoilColor,Height,ImageSize,Level,Position";
	};
}; // end namespace JDF
