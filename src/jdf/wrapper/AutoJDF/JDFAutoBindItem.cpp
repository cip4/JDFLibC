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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBindItem.h"
#include "jdf/wrapper/JDFChannelBinding.h"
#include "jdf/wrapper/JDFCoilBinding.h"
#include "jdf/wrapper/JDFEdgeGluing.h"
#include "jdf/wrapper/JDFHardCoverBinding.h"
#include "jdf/wrapper/JDFPlasticCombBinding.h"
#include "jdf/wrapper/JDFRingBinding.h"
#include "jdf/wrapper/JDFSaddleStitching.h"
#include "jdf/wrapper/JDFSideSewing.h"
#include "jdf/wrapper/JDFSideStitching.h"
#include "jdf/wrapper/JDFSoftCoverBinding.h"
#include "jdf/wrapper/JDFTape.h"
#include "jdf/wrapper/JDFTabs.h"
#include "jdf/wrapper/JDFThreadSealing.h"
#include "jdf/wrapper/JDFThreadSewing.h"
#include "jdf/wrapper/JDFStripBinding.h"
#include "jdf/wrapper/JDFWireCombBinding.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBindItem : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBindItem& JDFAutoBindItem::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBindItem: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBindItem::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBindItem::ValidNodeNames()const{
	return L"*:,BindItem";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoBindItem::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",ParentFolio";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBindItem::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",ChildFolio,Transformation,WrapPages");
};

/**
 typesafe validator
*/
	vWString JDFAutoBindItem::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidChildFolio(level)) {
			vAtts.push_back(atr_ChildFolio);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidParentFolio(level)) {
			vAtts.push_back(atr_ParentFolio);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTransformation(level)) {
			vAtts.push_back(atr_Transformation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWrapPages(level)) {
			vAtts.push_back(atr_WrapPages);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ChildFolio
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoBindItem::SetChildFolio(const JDFXYPair& value){
	SetAttribute(atr_ChildFolio,value);
};
/**
* Get string attribute ChildFolio
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoBindItem::GetChildFolio() const {
	return GetAttribute(atr_ChildFolio,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBindItem::ValidChildFolio(EnumValidationLevel level) const {
		return ValidAttribute(atr_ChildFolio,AttributeType_XYPair,false);
	};
/**
* Set attribute ParentFolio
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoBindItem::SetParentFolio(const JDFXYPair& value){
	SetAttribute(atr_ParentFolio,value);
};
/**
* Get string attribute ParentFolio
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoBindItem::GetParentFolio() const {
	return GetAttribute(atr_ParentFolio,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBindItem::ValidParentFolio(EnumValidationLevel level) const {
		return ValidAttribute(atr_ParentFolio,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute Transformation
*@param JDFMatrix value: the value to set the attribute to
*/
	 void JDFAutoBindItem::SetTransformation(const JDFMatrix& value){
	SetAttribute(atr_Transformation,value);
};
/**
* Get string attribute Transformation
* @return JDFMatrix the vaue of the attribute 
*/
	 JDFMatrix JDFAutoBindItem::GetTransformation() const {
	return GetAttribute(atr_Transformation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBindItem::ValidTransformation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Transformation,AttributeType_matrix,false);
	};
/**
* Set attribute WrapPages
*@param JDFIntegerRangeList value: the value to set the attribute to
*/
	 void JDFAutoBindItem::SetWrapPages(const JDFIntegerRangeList& value){
	SetAttribute(atr_WrapPages,value.GetString());
};
/**
* Get range attribute WrapPages
* @return JDFIntegerRangeList the vaue of the attribute 
*/
	 JDFIntegerRangeList JDFAutoBindItem::GetWrapPages() const {
	return GetAttribute(atr_WrapPages,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBindItem::ValidWrapPages(EnumValidationLevel level) const {
		return ValidAttribute(atr_WrapPages,AttributeType_IntegerRangeList,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpanBindingType JDFAutoBindItem::GetBindingType(int iSkip)const{
	JDFSpanBindingType e=GetElement(elm_BindingType,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingType JDFAutoBindItem::GetCreateBindingType(int iSkip){
	JDFSpanBindingType e=GetCreateElement(elm_BindingType,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingType JDFAutoBindItem::AppendBindingType(){
	JDFSpanBindingType e=AppendElement(elm_BindingType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChannelBinding JDFAutoBindItem::GetChannelBinding(int iSkip)const{
	JDFChannelBinding e=GetElement(elm_ChannelBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChannelBinding JDFAutoBindItem::GetCreateChannelBinding(int iSkip){
	JDFChannelBinding e=GetCreateElement(elm_ChannelBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChannelBinding JDFAutoBindItem::AppendChannelBinding(){
	JDFChannelBinding e=AppendElement(elm_ChannelBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCoilBinding JDFAutoBindItem::GetCoilBinding(int iSkip)const{
	JDFCoilBinding e=GetElement(elm_CoilBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCoilBinding JDFAutoBindItem::GetCreateCoilBinding(int iSkip){
	JDFCoilBinding e=GetCreateElement(elm_CoilBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCoilBinding JDFAutoBindItem::AppendCoilBinding(){
	JDFCoilBinding e=AppendElement(elm_CoilBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEdgeGluing JDFAutoBindItem::GetEdgeGluing(int iSkip)const{
	JDFEdgeGluing e=GetElement(elm_EdgeGluing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEdgeGluing JDFAutoBindItem::GetCreateEdgeGluing(int iSkip){
	JDFEdgeGluing e=GetCreateElement(elm_EdgeGluing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEdgeGluing JDFAutoBindItem::AppendEdgeGluing(){
	JDFEdgeGluing e=AppendElement(elm_EdgeGluing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHardCoverBinding JDFAutoBindItem::GetHardCoverBinding(int iSkip)const{
	JDFHardCoverBinding e=GetElement(elm_HardCoverBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHardCoverBinding JDFAutoBindItem::GetCreateHardCoverBinding(int iSkip){
	JDFHardCoverBinding e=GetCreateElement(elm_HardCoverBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHardCoverBinding JDFAutoBindItem::AppendHardCoverBinding(){
	JDFHardCoverBinding e=AppendElement(elm_HardCoverBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPlasticCombBinding JDFAutoBindItem::GetPlasticCombBinding(int iSkip)const{
	JDFPlasticCombBinding e=GetElement(elm_PlasticCombBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPlasticCombBinding JDFAutoBindItem::GetCreatePlasticCombBinding(int iSkip){
	JDFPlasticCombBinding e=GetCreateElement(elm_PlasticCombBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPlasticCombBinding JDFAutoBindItem::AppendPlasticCombBinding(){
	JDFPlasticCombBinding e=AppendElement(elm_PlasticCombBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRingBinding JDFAutoBindItem::GetRingBinding(int iSkip)const{
	JDFRingBinding e=GetElement(elm_RingBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRingBinding JDFAutoBindItem::GetCreateRingBinding(int iSkip){
	JDFRingBinding e=GetCreateElement(elm_RingBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRingBinding JDFAutoBindItem::AppendRingBinding(){
	JDFRingBinding e=AppendElement(elm_RingBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSaddleStitching JDFAutoBindItem::GetSaddleStitching(int iSkip)const{
	JDFSaddleStitching e=GetElement(elm_SaddleStitching,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSaddleStitching JDFAutoBindItem::GetCreateSaddleStitching(int iSkip){
	JDFSaddleStitching e=GetCreateElement(elm_SaddleStitching,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSaddleStitching JDFAutoBindItem::AppendSaddleStitching(){
	JDFSaddleStitching e=AppendElement(elm_SaddleStitching);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideSewing JDFAutoBindItem::GetSideSewing(int iSkip)const{
	JDFSideSewing e=GetElement(elm_SideSewing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideSewing JDFAutoBindItem::GetCreateSideSewing(int iSkip){
	JDFSideSewing e=GetCreateElement(elm_SideSewing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideSewing JDFAutoBindItem::AppendSideSewing(){
	JDFSideSewing e=AppendElement(elm_SideSewing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideStitching JDFAutoBindItem::GetSideStitching(int iSkip)const{
	JDFSideStitching e=GetElement(elm_SideStitching,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideStitching JDFAutoBindItem::GetCreateSideStitching(int iSkip){
	JDFSideStitching e=GetCreateElement(elm_SideStitching,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideStitching JDFAutoBindItem::AppendSideStitching(){
	JDFSideStitching e=AppendElement(elm_SideStitching);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSoftCoverBinding JDFAutoBindItem::GetSoftCoverBinding(int iSkip)const{
	JDFSoftCoverBinding e=GetElement(elm_SoftCoverBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSoftCoverBinding JDFAutoBindItem::GetCreateSoftCoverBinding(int iSkip){
	JDFSoftCoverBinding e=GetCreateElement(elm_SoftCoverBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSoftCoverBinding JDFAutoBindItem::AppendSoftCoverBinding(){
	JDFSoftCoverBinding e=AppendElement(elm_SoftCoverBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTape JDFAutoBindItem::GetTape(int iSkip)const{
	JDFTape e=GetElement(elm_Tape,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTape JDFAutoBindItem::GetCreateTape(int iSkip){
	JDFTape e=GetCreateElement(elm_Tape,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTape JDFAutoBindItem::AppendTape(){
	JDFTape e=AppendElement(elm_Tape);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTabs JDFAutoBindItem::GetTabs(int iSkip)const{
	JDFTabs e=GetElement(elm_Tabs,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTabs JDFAutoBindItem::GetCreateTabs(int iSkip){
	JDFTabs e=GetCreateElement(elm_Tabs,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTabs JDFAutoBindItem::AppendTabs(){
	JDFTabs e=AppendElement(elm_Tabs);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSealing JDFAutoBindItem::GetThreadSealing(int iSkip)const{
	JDFThreadSealing e=GetElement(elm_ThreadSealing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSealing JDFAutoBindItem::GetCreateThreadSealing(int iSkip){
	JDFThreadSealing e=GetCreateElement(elm_ThreadSealing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSealing JDFAutoBindItem::AppendThreadSealing(){
	JDFThreadSealing e=AppendElement(elm_ThreadSealing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSewing JDFAutoBindItem::GetThreadSewing(int iSkip)const{
	JDFThreadSewing e=GetElement(elm_ThreadSewing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSewing JDFAutoBindItem::GetCreateThreadSewing(int iSkip){
	JDFThreadSewing e=GetCreateElement(elm_ThreadSewing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSewing JDFAutoBindItem::AppendThreadSewing(){
	JDFThreadSewing e=AppendElement(elm_ThreadSewing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripBinding JDFAutoBindItem::GetStripBinding(int iSkip)const{
	JDFStripBinding e=GetElement(elm_StripBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripBinding JDFAutoBindItem::GetCreateStripBinding(int iSkip){
	JDFStripBinding e=GetCreateElement(elm_StripBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripBinding JDFAutoBindItem::AppendStripBinding(){
	JDFStripBinding e=AppendElement(elm_StripBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFWireCombBinding JDFAutoBindItem::GetWireCombBinding(int iSkip)const{
	JDFWireCombBinding e=GetElement(elm_WireCombBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFWireCombBinding JDFAutoBindItem::GetCreateWireCombBinding(int iSkip){
	JDFWireCombBinding e=GetCreateElement(elm_WireCombBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFWireCombBinding JDFAutoBindItem::AppendWireCombBinding(){
	JDFWireCombBinding e=AppendElement(elm_WireCombBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBindItem::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BindingType);

		for(i=0;i<nElem;i++){
			if (!GetBindingType(i).IsValid(level)) {
				vElem.AppendUnique(elm_BindingType);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ChannelBinding);

		for(i=0;i<nElem;i++){
			if (!GetChannelBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_ChannelBinding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CoilBinding);

		for(i=0;i<nElem;i++){
			if (!GetCoilBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_CoilBinding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_EdgeGluing);

		for(i=0;i<nElem;i++){
			if (!GetEdgeGluing(i).IsValid(level)) {
				vElem.AppendUnique(elm_EdgeGluing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_HardCoverBinding);

		for(i=0;i<nElem;i++){
			if (!GetHardCoverBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_HardCoverBinding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PlasticCombBinding);

		for(i=0;i<nElem;i++){
			if (!GetPlasticCombBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_PlasticCombBinding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RingBinding);

		for(i=0;i<nElem;i++){
			if (!GetRingBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_RingBinding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SaddleStitching);

		for(i=0;i<nElem;i++){
			if (!GetSaddleStitching(i).IsValid(level)) {
				vElem.AppendUnique(elm_SaddleStitching);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SideSewing);

		for(i=0;i<nElem;i++){
			if (!GetSideSewing(i).IsValid(level)) {
				vElem.AppendUnique(elm_SideSewing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SideStitching);

		for(i=0;i<nElem;i++){
			if (!GetSideStitching(i).IsValid(level)) {
				vElem.AppendUnique(elm_SideStitching);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SoftCoverBinding);

		for(i=0;i<nElem;i++){
			if (!GetSoftCoverBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_SoftCoverBinding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Tape);

		for(i=0;i<nElem;i++){
			if (!GetTape(i).IsValid(level)) {
				vElem.AppendUnique(elm_Tape);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Tabs);

		for(i=0;i<nElem;i++){
			if (!GetTabs(i).IsValid(level)) {
				vElem.AppendUnique(elm_Tabs);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ThreadSealing);

		for(i=0;i<nElem;i++){
			if (!GetThreadSealing(i).IsValid(level)) {
				vElem.AppendUnique(elm_ThreadSealing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ThreadSewing);

		for(i=0;i<nElem;i++){
			if (!GetThreadSewing(i).IsValid(level)) {
				vElem.AppendUnique(elm_ThreadSewing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StripBinding);

		for(i=0;i<nElem;i++){
			if (!GetStripBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_StripBinding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_WireCombBinding);

		for(i=0;i<nElem;i++){
			if (!GetWireCombBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_WireCombBinding);
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
	WString JDFAutoBindItem::OptionalElements()const{
		return JDFElement::OptionalElements()+L",BindingType,ChannelBinding,CoilBinding,EdgeGluing,HardCoverBinding,PlasticCombBinding,RingBinding,SaddleStitching,SideSewing,SideStitching,SoftCoverBinding,Tape,Tabs,ThreadSealing,ThreadSewing,StripBinding,WireCombBinding";
	};
}; // end namespace JDF
