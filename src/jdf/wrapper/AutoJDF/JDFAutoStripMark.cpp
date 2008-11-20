/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoStripMark.h"
#include "jdf/wrapper/JDFPosition.h"
#include "jdf/wrapper/JDFJobField.h"
#include "jdf/wrapper/JDFRefAnchor.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoStripMark : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoStripMark& JDFAutoStripMark::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoStripMark: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoStripMark::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoStripMark::ValidNodeNames()const{
	return L"*:,StripMark";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoStripMark::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AbsoluteHeight,AbsoluteWidth,Anchor,HorizontalFitPolicy,ID,MarkContext,MarkName,MarkSide,Offset,Ord,Orientation,RelativeHeight,RelativeWidth,StripMarkDetails,VerticalFitPolicy");
};

/**
 typesafe validator
*/
	vWString JDFAutoStripMark::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAbsoluteHeight(level)) {
			vAtts.push_back(atr_AbsoluteHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAbsoluteWidth(level)) {
			vAtts.push_back(atr_AbsoluteWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAnchor(level)) {
			vAtts.push_back(atr_Anchor);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHorizontalFitPolicy(level)) {
			vAtts.push_back(atr_HorizontalFitPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidID(level)) {
			vAtts.push_back(atr_ID);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkContext(level)) {
			vAtts.push_back(atr_MarkContext);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkName(level)) {
			vAtts.push_back(atr_MarkName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkSide(level)) {
			vAtts.push_back(atr_MarkSide);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOffset(level)) {
			vAtts.push_back(atr_Offset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrd(level)) {
			vAtts.push_back(atr_Ord);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrientation(level)) {
			vAtts.push_back(atr_Orientation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeHeight(level)) {
			vAtts.push_back(atr_RelativeHeight);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeWidth(level)) {
			vAtts.push_back(atr_RelativeWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStripMarkDetails(level)) {
			vAtts.push_back(atr_StripMarkDetails);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidVerticalFitPolicy(level)) {
			vAtts.push_back(atr_VerticalFitPolicy);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AbsoluteHeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetAbsoluteHeight(double value){
	SetAttribute(atr_AbsoluteHeight,WString::valueOf(value));
};
/**
* Get double attribute AbsoluteHeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripMark::GetAbsoluteHeight() const {
	return GetRealAttribute(atr_AbsoluteHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidAbsoluteHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_AbsoluteHeight,AttributeType_double,false);
	};
/**
* Set attribute AbsoluteWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetAbsoluteWidth(double value){
	SetAttribute(atr_AbsoluteWidth,WString::valueOf(value));
};
/**
* Get double attribute AbsoluteWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripMark::GetAbsoluteWidth() const {
	return GetRealAttribute(atr_AbsoluteWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidAbsoluteWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_AbsoluteWidth,AttributeType_double,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStripMark::AnchorString(){
		static const WString enums=WString(L"Unknown,TopLeft,TopCenter,TopRight,CenterLeft,Center,CenterRight,BottomLeft,BottomCenter,BottomRight");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStripMark::AnchorString(EnumAnchor value){
		return AnchorString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStripMark::SetAnchor( EnumAnchor value){
	SetEnumAttribute(atr_Anchor,value,AnchorString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStripMark::EnumAnchor JDFAutoStripMark:: GetAnchor() const {
	return (EnumAnchor) GetEnumAttribute(atr_Anchor,AnchorString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidAnchor(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Anchor,AnchorString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStripMark::HorizontalFitPolicyString(){
		static const WString enums=WString(L"Unknown,NoRepeat,StretchToFit,UndistortedScaleToFit,RepeatToFill,RepeatUnclipped");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStripMark::HorizontalFitPolicyString(EnumHorizontalFitPolicy value){
		return HorizontalFitPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStripMark::SetHorizontalFitPolicy( EnumHorizontalFitPolicy value){
	SetEnumAttribute(atr_HorizontalFitPolicy,value,HorizontalFitPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStripMark::EnumHorizontalFitPolicy JDFAutoStripMark:: GetHorizontalFitPolicy() const {
	return (EnumHorizontalFitPolicy) GetEnumAttribute(atr_HorizontalFitPolicy,HorizontalFitPolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidHorizontalFitPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_HorizontalFitPolicy,HorizontalFitPolicyString(),false);
	};
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetID(const WString& value){
	SetAttribute(atr_ID,value);
};
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStripMark::GetID() const {
	return GetAttribute(atr_ID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ID,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStripMark::MarkContextString(){
		static const WString enums=WString(L"Unknown,Sheet,BinderySignature,Cell,CellPair");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStripMark::MarkContextString(EnumMarkContext value){
		return MarkContextString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStripMark::SetMarkContext( EnumMarkContext value){
	SetEnumAttribute(atr_MarkContext,value,MarkContextString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStripMark::EnumMarkContext JDFAutoStripMark:: GetMarkContext() const {
	return (EnumMarkContext) GetEnumAttribute(atr_MarkContext,MarkContextString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidMarkContext(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MarkContext,MarkContextString(),false);
	};
/**
* Set attribute MarkName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetMarkName(const WString& value){
	SetAttribute(atr_MarkName,value);
};
/**
* Get string attribute MarkName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStripMark::GetMarkName() const {
	return GetAttribute(atr_MarkName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidMarkName(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarkName,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStripMark::MarkSideString(){
		static const WString enums=WString(L"Unknown,Front,Back,TwoSidedBackToBack,TwoSidedIndependent");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStripMark::MarkSideString(EnumMarkSide value){
		return MarkSideString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStripMark::SetMarkSide( EnumMarkSide value){
	SetEnumAttribute(atr_MarkSide,value,MarkSideString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStripMark::EnumMarkSide JDFAutoStripMark:: GetMarkSide() const {
	return (EnumMarkSide) GetEnumAttribute(atr_MarkSide,MarkSideString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidMarkSide(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MarkSide,MarkSideString(),false);
	};
/**
* Set attribute Offset
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetOffset(const JDFXYPair& value){
	SetAttribute(atr_Offset,value);
};
/**
* Get string attribute Offset
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoStripMark::GetOffset() const {
	return GetAttribute(atr_Offset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_Offset,AttributeType_XYPair,false);
	};
/**
* Set attribute Ord
*@param int value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetOrd(int value){
	SetAttribute(atr_Ord,WString::valueOf(value));
};
/**
* Get integer attribute Ord
* @return int the vaue of the attribute 
*/
	 int JDFAutoStripMark::GetOrd() const {
	return GetIntAttribute(atr_Ord,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidOrd(EnumValidationLevel level) const {
		return ValidAttribute(atr_Ord,AttributeType_integer,false);
	};
/////////////////////////////////////////////////////////////////////////
	void JDFAutoStripMark::SetOrientation( EnumOrientation value){
	SetEnumAttribute(atr_Orientation,value,OrientationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStripMark::EnumOrientation JDFAutoStripMark:: GetOrientation() const {
	return (EnumOrientation) GetEnumAttribute(atr_Orientation,OrientationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidOrientation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Orientation,OrientationString(),false);
	};
/**
* Set attribute RelativeHeight
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetRelativeHeight(double value){
	SetAttribute(atr_RelativeHeight,WString::valueOf(value));
};
/**
* Get double attribute RelativeHeight
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripMark::GetRelativeHeight() const {
	return GetRealAttribute(atr_RelativeHeight,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidRelativeHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeHeight,AttributeType_double,false);
	};
/**
* Set attribute RelativeWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetRelativeWidth(double value){
	SetAttribute(atr_RelativeWidth,WString::valueOf(value));
};
/**
* Get double attribute RelativeWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoStripMark::GetRelativeWidth() const {
	return GetRealAttribute(atr_RelativeWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidRelativeWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeWidth,AttributeType_double,false);
	};
/**
* Set attribute StripMarkDetails
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoStripMark::SetStripMarkDetails(const WString& value){
	SetAttribute(atr_StripMarkDetails,value);
};
/**
* Get string attribute StripMarkDetails
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoStripMark::GetStripMarkDetails() const {
	return GetAttribute(atr_StripMarkDetails,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidStripMarkDetails(EnumValidationLevel level) const {
		return ValidAttribute(atr_StripMarkDetails,AttributeType_string,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoStripMark::VerticalFitPolicyString(){
		static const WString enums=WString(L"Unknown,NoRepeat,StretchToFit,UndistortedScaleToFit,RepeatToFill,RepeatUnclipped");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoStripMark::VerticalFitPolicyString(EnumVerticalFitPolicy value){
		return VerticalFitPolicyString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoStripMark::SetVerticalFitPolicy( EnumVerticalFitPolicy value){
	SetEnumAttribute(atr_VerticalFitPolicy,value,VerticalFitPolicyString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoStripMark::EnumVerticalFitPolicy JDFAutoStripMark:: GetVerticalFitPolicy() const {
	return (EnumVerticalFitPolicy) GetEnumAttribute(atr_VerticalFitPolicy,VerticalFitPolicyString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoStripMark::ValidVerticalFitPolicy(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_VerticalFitPolicy,VerticalFitPolicyString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPosition JDFAutoStripMark::GetPosition(int iSkip)const{
	JDFPosition e=GetElement(elm_Position,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPosition JDFAutoStripMark::GetCreatePosition(int iSkip){
	JDFPosition e=GetCreateElement(elm_Position,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPosition JDFAutoStripMark::AppendPosition(){
	JDFPosition e=AppendElement(elm_Position);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoStripMark::GetJobField(int iSkip)const{
	JDFJobField e=GetElement(elm_JobField,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoStripMark::GetCreateJobField(int iSkip){
	JDFJobField e=GetCreateElement(elm_JobField,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFJobField JDFAutoStripMark::AppendJobField(){
	JDFJobField e=AppendElement(elm_JobField);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoStripMark::RefJobField(JDFJobField& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFRefAnchor JDFAutoStripMark::GetRefAnchor()const{
	JDFRefAnchor e=GetElement(elm_RefAnchor);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRefAnchor JDFAutoStripMark::GetCreateRefAnchor(){
	JDFRefAnchor e=GetCreateElement(elm_RefAnchor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRefAnchor JDFAutoStripMark::AppendRefAnchor(){
	JDFRefAnchor e=AppendElementN(elm_RefAnchor,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoStripMark::RefRefAnchor(JDFRefAnchor& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoStripMark::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Position);

		for(i=0;i<nElem;i++){
			if (!GetPosition(i).IsValid(level)) {
				vElem.AppendUnique(elm_Position);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_JobField);

		for(i=0;i<nElem;i++){
			if (!GetJobField(i).IsValid(level)) {
				vElem.AppendUnique(elm_JobField);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RefAnchor);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_RefAnchor);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetRefAnchor().IsValid(level)) {
				vElem.AppendUnique(elm_RefAnchor);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoStripMark::UniqueElements()const{
		return JDFElement::UniqueElements()+L",RefAnchor";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoStripMark::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Position,JobField,RefAnchor";
	};
}; // end namespace JDF
