/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIDPLayout.h"
#include "jdf/wrapper/JDFIDPImageShift.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDPLayout : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIDPLayout& JDFAutoIDPLayout::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIDPLayout: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIDPLayout::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIDPLayout::ValidNodeNames()const{
	return L"*:,IDPLayout";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIDPLayout::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Border,FinishedPageOrientation,ForceFrontSide,NumberUp,PresentationDirection,Rotate,Sides");
};

/**
 typesafe validator
*/
	vWString JDFAutoIDPLayout::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBorder(level)) {
			vAtts.push_back(atr_Border);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFinishedPageOrientation(level)) {
			vAtts.push_back(atr_FinishedPageOrientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidForceFrontSide(level)) {
			vAtts.push_back(atr_ForceFrontSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberUp(level)) {
			vAtts.push_back(atr_NumberUp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPresentationDirection(level)) {
			vAtts.push_back(atr_PresentationDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotate(level)) {
			vAtts.push_back(atr_Rotate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSides(level)) {
			vAtts.push_back(atr_Sides);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Border
*@param double value: the value to set the attribute to
*/
	 void JDFAutoIDPLayout::SetBorder(double value){
	SetAttribute(atr_Border,WString::valueOf(value));
};
/**
* Get double attribute Border
* @return double the vaue of the attribute ; defaults to 0
*/
	 double JDFAutoIDPLayout::GetBorder() const {
	return GetRealAttribute(atr_Border,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPLayout::ValidBorder(EnumValidationLevel level) const {
		return ValidAttribute(atr_Border,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPLayout::FinishedPageOrientationString(){
		static const WString enums=WString(L"Unknown,Portrait,Landscape");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPLayout::FinishedPageOrientationString(EnumFinishedPageOrientation value){
		return FinishedPageOrientationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPLayout::SetFinishedPageOrientation( EnumFinishedPageOrientation value){
	SetEnumAttribute(atr_FinishedPageOrientation,value,FinishedPageOrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPLayout::EnumFinishedPageOrientation JDFAutoIDPLayout:: GetFinishedPageOrientation() const {
	return (EnumFinishedPageOrientation) GetEnumAttribute(atr_FinishedPageOrientation,FinishedPageOrientationString(),WString::emptyStr,FinishedPageOrientation_Portrait);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPLayout::ValidFinishedPageOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FinishedPageOrientation,FinishedPageOrientationString(),false);
	};
/**
* Set attribute ForceFrontSide
*@param NumberRangeList value: the value to set the attribute to
*/
	 void JDFAutoIDPLayout::SetForceFrontSide(const NumberRangeList& value){
	SetAttribute(atr_ForceFrontSide,value.GetString());
};
/**
* Get range attribute ForceFrontSide
* @return NumberRangeList the vaue of the attribute 
*/
	 NumberRangeList JDFAutoIDPLayout::GetForceFrontSide() const {
	return GetAttribute(atr_ForceFrontSide,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPLayout::ValidForceFrontSide(EnumValidationLevel level) const {
		return ValidAttribute(atr_ForceFrontSide,AttributeType_NumberRangeList,false);
	};
/**
* Set attribute NumberUp
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoIDPLayout::SetNumberUp(const JDFXYPair& value){
	SetAttribute(atr_NumberUp,value);
};
/**
* Get string attribute NumberUp
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoIDPLayout::GetNumberUp() const {
	return GetAttribute(atr_NumberUp,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPLayout::ValidNumberUp(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberUp,AttributeType_XYPair,false);
	};
/**
* Set attribute PresentationDirection
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDPLayout::SetPresentationDirection(const WString& value){
	SetAttribute(atr_PresentationDirection,value);
};
/**
* Get string attribute PresentationDirection
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoIDPLayout::GetPresentationDirection() const {
	return GetAttribute(atr_PresentationDirection,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPLayout::ValidPresentationDirection(EnumValidationLevel level) const {
		return ValidAttribute(atr_PresentationDirection,AttributeType_Any,false);
	};
/**
* Set attribute Rotate
*@param double value: the value to set the attribute to
*/
	 void JDFAutoIDPLayout::SetRotate(double value){
	SetAttribute(atr_Rotate,WString::valueOf(value));
};
/**
* Get double attribute Rotate
* @return double the vaue of the attribute ; defaults to 0
*/
	 double JDFAutoIDPLayout::GetRotate() const {
	return GetRealAttribute(atr_Rotate,WString::emptyStr,0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPLayout::ValidRotate(EnumValidationLevel level) const {
		return ValidAttribute(atr_Rotate,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPLayout::SidesString(){
		static const WString enums=WString(L"Unknown,OneSided,TwoSidedLongEdge,TwoSidedShortEdge");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPLayout::SidesString(EnumSides value){
		return SidesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPLayout::SetSides( EnumSides value){
	SetEnumAttribute(atr_Sides,value,SidesString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPLayout::EnumSides JDFAutoIDPLayout:: GetSides() const {
	return (EnumSides) GetEnumAttribute(atr_Sides,SidesString(),WString::emptyStr,Sides_OneSided);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPLayout::ValidSides(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Sides,SidesString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIDPImageShift JDFAutoIDPLayout::GetImageShift(int iSkip)const{
	JDFIDPImageShift e=GetElement(elm_ImageShift,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPImageShift JDFAutoIDPLayout::GetCreateImageShift(int iSkip){
	JDFIDPImageShift e=GetCreateElement(elm_ImageShift,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPImageShift JDFAutoIDPLayout::AppendImageShift(){
	JDFIDPImageShift e=AppendElement(elm_ImageShift);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoIDPLayout::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ImageShift);

		for(i=0;i<nElem;i++){
			if (!GetImageShift(i).IsValid(level)) {
				vElem.AppendUnique(elm_ImageShift);
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
	WString JDFAutoIDPLayout::OptionalElements()const{
		return JDFElement::OptionalElements()+L",ImageShift";
	};
}; // end namespace JDF
