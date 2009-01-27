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

 
#include "jdf/wrapper/AutoJDF/JDFAutoProofItem.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFApprovalParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoProofItem : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoProofItem& JDFAutoProofItem::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoProofItem: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoProofItem::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoProofItem::ValidNodeNames()const{
	return L"*:,ProofItem";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoProofItem::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Contract,PageIndex,ProofName,ProofTarget");
};

/**
 typesafe validator
*/
	vWString JDFAutoProofItem::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidContract(level)) {
			vAtts.push_back(atr_Contract);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPageIndex(level)) {
			vAtts.push_back(atr_PageIndex);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProofName(level)) {
			vAtts.push_back(atr_ProofName);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProofTarget(level)) {
			vAtts.push_back(atr_ProofTarget);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Contract
*@param bool value: the value to set the attribute to
*/
	 void JDFAutoProofItem::SetContract(bool value){
	SetAttribute(atr_Contract,WString::valueOf(value));
};
/**
* Get bool attribute Contract
* @return bool the vaue of the attribute ; defaults to false
*/
	 bool JDFAutoProofItem::GetContract() const {return GetBoolAttribute(atr_Contract,WString::emptyStr,false);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofItem::ValidContract(EnumValidationLevel level) const {
		return ValidAttribute(atr_Contract,AttributeType_boolean,false);
	};
/**
* Set attribute PageIndex
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoProofItem::SetPageIndex(const JDFIntegerRangeList& value){
	SetAttribute(atr_PageIndex,value.GetString());
};
/**
* Get range attribute PageIndex
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoProofItem::GetPageIndex() const {
	return GetAttribute(atr_PageIndex,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofItem::ValidPageIndex(EnumValidationLevel level) const {
		return ValidAttribute(atr_PageIndex,AttributeType_IntegerRangeList,false);
	};
/**
* Set attribute ProofName
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoProofItem::SetProofName(const WString& value){
	SetAttribute(atr_ProofName,value);
};
/**
* Get string attribute ProofName
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoProofItem::GetProofName() const {
	return GetAttribute(atr_ProofName,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofItem::ValidProofName(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProofName,AttributeType_string,false);
	};
/**
* Set attribute ProofTarget
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoProofItem::SetProofTarget(const WString& value){
	SetAttribute(atr_ProofTarget,value);
};
/**
* Get string attribute ProofTarget
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoProofItem::GetProofTarget() const {
	return GetAttribute(atr_ProofTarget,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProofItem::ValidProofTarget(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProofTarget,AttributeType_URL,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIntegerSpan JDFAutoProofItem::GetAmount()const{
	JDFIntegerSpan e=GetElement(elm_Amount);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoProofItem::GetCreateAmount(){
	JDFIntegerSpan e=GetCreateElement(elm_Amount);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoProofItem::AppendAmount(){
	JDFIntegerSpan e=AppendElementN(elm_Amount,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoProofItem::GetBrandName()const{
	JDFStringSpan e=GetElement(elm_BrandName);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoProofItem::GetCreateBrandName(){
	JDFStringSpan e=GetCreateElement(elm_BrandName);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoProofItem::AppendBrandName(){
	JDFStringSpan e=AppendElementN(elm_BrandName,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanColorType JDFAutoProofItem::GetColorType()const{
	JDFSpanColorType e=GetElement(elm_ColorType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanColorType JDFAutoProofItem::GetCreateColorType(){
	JDFSpanColorType e=GetCreateElement(elm_ColorType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanColorType JDFAutoProofItem::AppendColorType(){
	JDFSpanColorType e=AppendElementN(elm_ColorType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoProofItem::GetHalfTone()const{
	JDFOptionSpan e=GetElement(elm_HalfTone);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoProofItem::GetCreateHalfTone(){
	JDFOptionSpan e=GetCreateElement(elm_HalfTone);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoProofItem::AppendHalfTone(){
	JDFOptionSpan e=AppendElementN(elm_HalfTone,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanImageStrategy JDFAutoProofItem::GetImageStrategy()const{
	JDFSpanImageStrategy e=GetElement(elm_ImageStrategy);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanImageStrategy JDFAutoProofItem::GetCreateImageStrategy(){
	JDFSpanImageStrategy e=GetCreateElement(elm_ImageStrategy);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanImageStrategy JDFAutoProofItem::AppendImageStrategy(){
	JDFSpanImageStrategy e=AppendElementN(elm_ImageStrategy,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoProofItem::GetTechnology()const{
	JDFNameSpan e=GetElement(elm_Technology);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoProofItem::GetCreateTechnology(){
	JDFNameSpan e=GetCreateElement(elm_Technology);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoProofItem::AppendTechnology(){
	JDFNameSpan e=AppendElementN(elm_Technology,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanProofType JDFAutoProofItem::GetProofType()const{
	JDFSpanProofType e=GetElement(elm_ProofType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanProofType JDFAutoProofItem::GetCreateProofType(){
	JDFSpanProofType e=GetCreateElement(elm_ProofType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanProofType JDFAutoProofItem::AppendProofType(){
	JDFSpanProofType e=AppendElementN(elm_ProofType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoProofItem::GetSeparationSpec(int iSkip)const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoProofItem::GetCreateSeparationSpec(int iSkip){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoProofItem::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoProofItem::GetApprovalParams()const{
	JDFApprovalParams e=GetElement(elm_ApprovalParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoProofItem::GetCreateApprovalParams(){
	JDFApprovalParams e=GetCreateElement(elm_ApprovalParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFApprovalParams JDFAutoProofItem::AppendApprovalParams(){
	JDFApprovalParams e=AppendElementN(elm_ApprovalParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoProofItem::RefApprovalParams(JDFApprovalParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoProofItem::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Amount);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Amount);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetAmount().IsValid(level)) {
				vElem.AppendUnique(elm_Amount);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_BrandName);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_BrandName);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetBrandName().IsValid(level)) {
				vElem.AppendUnique(elm_BrandName);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ColorType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorType().IsValid(level)) {
				vElem.AppendUnique(elm_ColorType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_HalfTone);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_HalfTone);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetHalfTone().IsValid(level)) {
				vElem.AppendUnique(elm_HalfTone);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ImageStrategy);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ImageStrategy);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetImageStrategy().IsValid(level)) {
				vElem.AppendUnique(elm_ImageStrategy);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Technology);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Technology);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetTechnology().IsValid(level)) {
				vElem.AppendUnique(elm_Technology);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ProofType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ProofType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetProofType().IsValid(level)) {
				vElem.AppendUnique(elm_ProofType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_SeparationSpec);

		for(i=0;i<nElem;i++){
			if (!GetSeparationSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_SeparationSpec);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ApprovalParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ApprovalParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetApprovalParams().IsValid(level)) {
				vElem.AppendUnique(elm_ApprovalParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoProofItem::UniqueElements()const{
		return JDFElement::UniqueElements()+L",Amount,BrandName,ColorType,HalfTone,ImageStrategy,Technology,ProofType,ApprovalParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoProofItem::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Amount,BrandName,ColorType,HalfTone,ImageStrategy,Technology,ProofType,SeparationSpec,ApprovalParams";
	};
}; // end namespace JDF
