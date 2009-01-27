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

 
#include "jdf/wrapper/AutoJDF/JDFAutoLayoutIntent.h"
#include "jdf/wrapper/JDFLayout.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoLayoutIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoLayoutIntent& JDFAutoLayoutIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoLayoutIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoLayoutIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoLayoutIntent::ValidNodeNames()const{
	return L"*:,LayoutIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoLayoutIntent::OptionalAttributes()const{
		return JDFIntentResource::OptionalAttributes()+WString(L",FolioCount,NumberUp,FinishedPageOrientation,RotatePolicy,Sides");
};

/**
 typesafe validator
*/
	vWString JDFAutoLayoutIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFolioCount(level)) {
			vAtts.push_back(atr_FolioCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidNumberUp(level)) {
			vAtts.push_back(atr_NumberUp);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFinishedPageOrientation(level)) {
			vAtts.push_back(atr_FinishedPageOrientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotatePolicy(level)) {
			vAtts.push_back(atr_RotatePolicy);
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

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutIntent::FolioCountString(){
		static const WString enums=WString(L"Unknown,Booklet,Flat");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutIntent::FolioCountString(EnumFolioCount value){
		return FolioCountString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutIntent::SetFolioCount( EnumFolioCount value){
	SetEnumAttribute(atr_FolioCount,value,FolioCountString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutIntent::EnumFolioCount JDFAutoLayoutIntent:: GetFolioCount() const {
	return (EnumFolioCount) GetEnumAttribute(atr_FolioCount,FolioCountString(),WString::emptyStr,FolioCount_Booklet);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutIntent::ValidFolioCount(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FolioCount,FolioCountString(),false);
	};
/**
* Set attribute NumberUp
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoLayoutIntent::SetNumberUp(const JDFXYPair& value){
	SetAttribute(atr_NumberUp,value);
};
/**
* Get string attribute NumberUp
* @return JDFXYPair the vaue of the attribute ; defaults to 1 1
*/
	 JDFXYPair JDFAutoLayoutIntent::GetNumberUp() const {
	return GetAttribute(atr_NumberUp,WString::emptyStr,L"1 1");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutIntent::ValidNumberUp(EnumValidationLevel level) const {
		return ValidAttribute(atr_NumberUp,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutIntent::FinishedPageOrientationString(){
		static const WString enums=WString(L"Unknown,Portrait,Landscape");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutIntent::FinishedPageOrientationString(EnumFinishedPageOrientation value){
		return FinishedPageOrientationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutIntent::SetFinishedPageOrientation( EnumFinishedPageOrientation value){
	SetEnumAttribute(atr_FinishedPageOrientation,value,FinishedPageOrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutIntent::EnumFinishedPageOrientation JDFAutoLayoutIntent:: GetFinishedPageOrientation() const {
	return (EnumFinishedPageOrientation) GetEnumAttribute(atr_FinishedPageOrientation,FinishedPageOrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutIntent::ValidFinishedPageOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FinishedPageOrientation,FinishedPageOrientationString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutIntent::RotatePolicyString(){
		static const WString enums=WString(L"Unknown,NoRotate,RotateOrthogonal,RotateClockwise,RotateCounterClockwise");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutIntent::RotatePolicyString(EnumRotatePolicy value){
		return RotatePolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutIntent::SetRotatePolicy( EnumRotatePolicy value){
	SetEnumAttribute(atr_RotatePolicy,value,RotatePolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutIntent::EnumRotatePolicy JDFAutoLayoutIntent:: GetRotatePolicy() const {
	return (EnumRotatePolicy) GetEnumAttribute(atr_RotatePolicy,RotatePolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutIntent::ValidRotatePolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_RotatePolicy,RotatePolicyString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoLayoutIntent::SidesString(){
		static const WString enums=WString(L"Unknown,OneSided,OneSidedBack,TwoSidedHeadToHead,TwoSidedHeadToFoot");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoLayoutIntent::SidesString(EnumSides value){
		return SidesString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoLayoutIntent::SetSides( EnumSides value){
	SetEnumAttribute(atr_Sides,value,SidesString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoLayoutIntent::EnumSides JDFAutoLayoutIntent:: GetSides() const {
	return (EnumSides) GetEnumAttribute(atr_Sides,SidesString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoLayoutIntent::ValidSides(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Sides,SidesString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFXYPairSpan JDFAutoLayoutIntent::GetDimensions()const{
	JDFXYPairSpan e=GetElement(elm_Dimensions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoLayoutIntent::GetCreateDimensions(){
	JDFXYPairSpan e=GetCreateElement(elm_Dimensions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoLayoutIntent::AppendDimensions(){
	JDFXYPairSpan e=AppendElementN(elm_Dimensions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoLayoutIntent::GetFinishedDimensions()const{
	JDFShapeSpan e=GetElement(elm_FinishedDimensions);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoLayoutIntent::GetCreateFinishedDimensions(){
	JDFShapeSpan e=GetCreateElement(elm_FinishedDimensions);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoLayoutIntent::AppendFinishedDimensions(){
	JDFShapeSpan e=AppendElementN(elm_FinishedDimensions,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanFinishedGrainDirection JDFAutoLayoutIntent::GetFinishedGrainDirection()const{
	JDFSpanFinishedGrainDirection e=GetElement(elm_FinishedGrainDirection);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanFinishedGrainDirection JDFAutoLayoutIntent::GetCreateFinishedGrainDirection(){
	JDFSpanFinishedGrainDirection e=GetCreateElement(elm_FinishedGrainDirection);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanFinishedGrainDirection JDFAutoLayoutIntent::AppendFinishedGrainDirection(){
	JDFSpanFinishedGrainDirection e=AppendElementN(elm_FinishedGrainDirection,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoLayoutIntent::GetPages()const{
	JDFIntegerSpan e=GetElement(elm_Pages);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoLayoutIntent::GetCreatePages(){
	JDFIntegerSpan e=GetCreateElement(elm_Pages);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoLayoutIntent::AppendPages(){
	JDFIntegerSpan e=AppendElementN(elm_Pages,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoLayoutIntent::GetPageVariance()const{
	JDFIntegerSpan e=GetElement(elm_PageVariance);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoLayoutIntent::GetCreatePageVariance(){
	JDFIntegerSpan e=GetCreateElement(elm_PageVariance);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoLayoutIntent::AppendPageVariance(){
	JDFIntegerSpan e=AppendElementN(elm_PageVariance,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoLayoutIntent::GetLayout()const{
	JDFLayout e=GetElement(elm_Layout);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoLayoutIntent::GetCreateLayout(){
	JDFLayout e=GetCreateElement(elm_Layout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoLayoutIntent::AppendLayout(){
	JDFLayout e=AppendElementN(elm_Layout,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoLayoutIntent::RefLayout(JDFLayout& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFSpanSizePolicy JDFAutoLayoutIntent::GetSizePolicy()const{
	JDFSpanSizePolicy e=GetElement(elm_SizePolicy);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanSizePolicy JDFAutoLayoutIntent::GetCreateSizePolicy(){
	JDFSpanSizePolicy e=GetCreateElement(elm_SizePolicy);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanSizePolicy JDFAutoLayoutIntent::AppendSizePolicy(){
	JDFSpanSizePolicy e=AppendElementN(elm_SizePolicy,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoLayoutIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Dimensions);
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
		nElem=NumChildElements(elm_FinishedDimensions);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FinishedDimensions);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFinishedDimensions().IsValid(level)) {
				vElem.AppendUnique(elm_FinishedDimensions);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FinishedGrainDirection);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FinishedGrainDirection);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFinishedGrainDirection().IsValid(level)) {
				vElem.AppendUnique(elm_FinishedGrainDirection);
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
		nElem=NumChildElements(elm_PageVariance);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PageVariance);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPageVariance().IsValid(level)) {
				vElem.AppendUnique(elm_PageVariance);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Layout);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Layout);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetLayout().IsValid(level)) {
				vElem.AppendUnique(elm_Layout);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_SizePolicy);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_SizePolicy);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetSizePolicy().IsValid(level)) {
				vElem.AppendUnique(elm_SizePolicy);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoLayoutIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",Dimensions,FinishedDimensions,FinishedGrainDirection,Pages,PageVariance,Layout,SizePolicy";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoLayoutIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",Dimensions,FinishedDimensions,FinishedGrainDirection,Pages,PageVariance,Layout,SizePolicy";
	};
}; // end namespace JDF
