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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBindingIntent.h"
#include "jdf/wrapper/JDFAdhesiveBinding.h"
#include "jdf/wrapper/JDFBindList.h"
#include "jdf/wrapper/JDFBookCase.h"
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
class JDFAutoBindingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBindingIntent& JDFAutoBindingIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBindingIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBindingIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBindingIntent::ValidNodeNames()const{
	return L"*:,BindingIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBindingIntent::OptionalAttributes()const{
		return JDFIntentResource::OptionalAttributes()+WString(L",BindingOrder");
};

/**
 typesafe validator
*/
	vWString JDFAutoBindingIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBindingOrder(level)) {
			vAtts.push_back(atr_BindingOrder);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBindingIntent::BindingOrderString(){
		static const WString enums=WString(L"Unknown,Collecting,Gathering,List,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBindingIntent::BindingOrderString(EnumBindingOrder value){
		return BindingOrderString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBindingIntent::SetBindingOrder( EnumBindingOrder value){
	SetEnumAttribute(atr_BindingOrder,value,BindingOrderString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBindingIntent::EnumBindingOrder JDFAutoBindingIntent:: GetBindingOrder() const {
	return (EnumBindingOrder) GetEnumAttribute(atr_BindingOrder,BindingOrderString(),WString::emptyStr,BindingOrder_Gathering);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBindingIntent::ValidBindingOrder(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BindingOrder,BindingOrderString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpanNamedColor JDFAutoBindingIntent::GetBackCoverColor(int iSkip)const{
	JDFSpanNamedColor e=GetElement(elm_BackCoverColor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoBindingIntent::GetCreateBackCoverColor(int iSkip){
	JDFSpanNamedColor e=GetCreateElement(elm_BackCoverColor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoBindingIntent::AppendBackCoverColor(){
	JDFSpanNamedColor e=AppendElement(elm_BackCoverColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::GetBackCoverColorDetails(int iSkip)const{
	JDFStringSpan e=GetElement(elm_BackCoverColorDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::GetCreateBackCoverColorDetails(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_BackCoverColorDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::AppendBackCoverColorDetails(){
	JDFStringSpan e=AppendElement(elm_BackCoverColorDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingType JDFAutoBindingIntent::GetBindingType(int iSkip)const{
	JDFSpanBindingType e=GetElement(elm_BindingType,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingType JDFAutoBindingIntent::GetCreateBindingType(int iSkip){
	JDFSpanBindingType e=GetCreateElement(elm_BindingType,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingType JDFAutoBindingIntent::AppendBindingType(){
	JDFSpanBindingType e=AppendElement(elm_BindingType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoBindingIntent::GetBindingColor(int iSkip)const{
	JDFSpanNamedColor e=GetElement(elm_BindingColor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoBindingIntent::GetCreateBindingColor(int iSkip){
	JDFSpanNamedColor e=GetCreateElement(elm_BindingColor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoBindingIntent::AppendBindingColor(){
	JDFSpanNamedColor e=AppendElement(elm_BindingColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::GetBindingColorDetails(int iSkip)const{
	JDFStringSpan e=GetElement(elm_BindingColorDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::GetCreateBindingColorDetails(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_BindingColorDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::AppendBindingColorDetails(){
	JDFStringSpan e=AppendElement(elm_BindingColorDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingLength JDFAutoBindingIntent::GetBindingLength(int iSkip)const{
	JDFSpanBindingLength e=GetElement(elm_BindingLength,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingLength JDFAutoBindingIntent::GetCreateBindingLength(int iSkip){
	JDFSpanBindingLength e=GetCreateElement(elm_BindingLength,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingLength JDFAutoBindingIntent::AppendBindingLength(){
	JDFSpanBindingLength e=AppendElement(elm_BindingLength);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingSide JDFAutoBindingIntent::GetBindingSide(int iSkip)const{
	JDFSpanBindingSide e=GetElement(elm_BindingSide,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingSide JDFAutoBindingIntent::GetCreateBindingSide(int iSkip){
	JDFSpanBindingSide e=GetCreateElement(elm_BindingSide,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanBindingSide JDFAutoBindingIntent::AppendBindingSide(){
	JDFSpanBindingSide e=AppendElement(elm_BindingSide);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoBindingIntent::GetCoverColor(int iSkip)const{
	JDFSpanNamedColor e=GetElement(elm_CoverColor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoBindingIntent::GetCreateCoverColor(int iSkip){
	JDFSpanNamedColor e=GetCreateElement(elm_CoverColor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoBindingIntent::AppendCoverColor(){
	JDFSpanNamedColor e=AppendElement(elm_CoverColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::GetCoverColorDetails(int iSkip)const{
	JDFStringSpan e=GetElement(elm_CoverColorDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::GetCreateCoverColorDetails(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_CoverColorDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoBindingIntent::AppendCoverColorDetails(){
	JDFStringSpan e=AppendElement(elm_CoverColorDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAdhesiveBinding JDFAutoBindingIntent::GetAdhesiveBinding(int iSkip)const{
	JDFAdhesiveBinding e=GetElement(elm_AdhesiveBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAdhesiveBinding JDFAutoBindingIntent::GetCreateAdhesiveBinding(int iSkip){
	JDFAdhesiveBinding e=GetCreateElement(elm_AdhesiveBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAdhesiveBinding JDFAutoBindingIntent::AppendAdhesiveBinding(){
	JDFAdhesiveBinding e=AppendElement(elm_AdhesiveBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindList JDFAutoBindingIntent::GetBindList(int iSkip)const{
	JDFBindList e=GetElement(elm_BindList,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindList JDFAutoBindingIntent::GetCreateBindList(int iSkip){
	JDFBindList e=GetCreateElement(elm_BindList,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBindList JDFAutoBindingIntent::AppendBindList(){
	JDFBindList e=AppendElement(elm_BindList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBookCase JDFAutoBindingIntent::GetBookCase(int iSkip)const{
	JDFBookCase e=GetElement(elm_BookCase,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBookCase JDFAutoBindingIntent::GetCreateBookCase(int iSkip){
	JDFBookCase e=GetCreateElement(elm_BookCase,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBookCase JDFAutoBindingIntent::AppendBookCase(){
	JDFBookCase e=AppendElement(elm_BookCase);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChannelBinding JDFAutoBindingIntent::GetChannelBinding(int iSkip)const{
	JDFChannelBinding e=GetElement(elm_ChannelBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChannelBinding JDFAutoBindingIntent::GetCreateChannelBinding(int iSkip){
	JDFChannelBinding e=GetCreateElement(elm_ChannelBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFChannelBinding JDFAutoBindingIntent::AppendChannelBinding(){
	JDFChannelBinding e=AppendElement(elm_ChannelBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCoilBinding JDFAutoBindingIntent::GetCoilBinding(int iSkip)const{
	JDFCoilBinding e=GetElement(elm_CoilBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCoilBinding JDFAutoBindingIntent::GetCreateCoilBinding(int iSkip){
	JDFCoilBinding e=GetCreateElement(elm_CoilBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCoilBinding JDFAutoBindingIntent::AppendCoilBinding(){
	JDFCoilBinding e=AppendElement(elm_CoilBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEdgeGluing JDFAutoBindingIntent::GetEdgeGluing(int iSkip)const{
	JDFEdgeGluing e=GetElement(elm_EdgeGluing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEdgeGluing JDFAutoBindingIntent::GetCreateEdgeGluing(int iSkip){
	JDFEdgeGluing e=GetCreateElement(elm_EdgeGluing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEdgeGluing JDFAutoBindingIntent::AppendEdgeGluing(){
	JDFEdgeGluing e=AppendElement(elm_EdgeGluing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHardCoverBinding JDFAutoBindingIntent::GetHardCoverBinding(int iSkip)const{
	JDFHardCoverBinding e=GetElement(elm_HardCoverBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHardCoverBinding JDFAutoBindingIntent::GetCreateHardCoverBinding(int iSkip){
	JDFHardCoverBinding e=GetCreateElement(elm_HardCoverBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFHardCoverBinding JDFAutoBindingIntent::AppendHardCoverBinding(){
	JDFHardCoverBinding e=AppendElement(elm_HardCoverBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPlasticCombBinding JDFAutoBindingIntent::GetPlasticCombBinding(int iSkip)const{
	JDFPlasticCombBinding e=GetElement(elm_PlasticCombBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPlasticCombBinding JDFAutoBindingIntent::GetCreatePlasticCombBinding(int iSkip){
	JDFPlasticCombBinding e=GetCreateElement(elm_PlasticCombBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPlasticCombBinding JDFAutoBindingIntent::AppendPlasticCombBinding(){
	JDFPlasticCombBinding e=AppendElement(elm_PlasticCombBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRingBinding JDFAutoBindingIntent::GetRingBinding(int iSkip)const{
	JDFRingBinding e=GetElement(elm_RingBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRingBinding JDFAutoBindingIntent::GetCreateRingBinding(int iSkip){
	JDFRingBinding e=GetCreateElement(elm_RingBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRingBinding JDFAutoBindingIntent::AppendRingBinding(){
	JDFRingBinding e=AppendElement(elm_RingBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSaddleStitching JDFAutoBindingIntent::GetSaddleStitching(int iSkip)const{
	JDFSaddleStitching e=GetElement(elm_SaddleStitching,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSaddleStitching JDFAutoBindingIntent::GetCreateSaddleStitching(int iSkip){
	JDFSaddleStitching e=GetCreateElement(elm_SaddleStitching,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSaddleStitching JDFAutoBindingIntent::AppendSaddleStitching(){
	JDFSaddleStitching e=AppendElement(elm_SaddleStitching);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideSewing JDFAutoBindingIntent::GetSideSewing(int iSkip)const{
	JDFSideSewing e=GetElement(elm_SideSewing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideSewing JDFAutoBindingIntent::GetCreateSideSewing(int iSkip){
	JDFSideSewing e=GetCreateElement(elm_SideSewing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideSewing JDFAutoBindingIntent::AppendSideSewing(){
	JDFSideSewing e=AppendElement(elm_SideSewing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideStitching JDFAutoBindingIntent::GetSideStitching(int iSkip)const{
	JDFSideStitching e=GetElement(elm_SideStitching,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideStitching JDFAutoBindingIntent::GetCreateSideStitching(int iSkip){
	JDFSideStitching e=GetCreateElement(elm_SideStitching,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSideStitching JDFAutoBindingIntent::AppendSideStitching(){
	JDFSideStitching e=AppendElement(elm_SideStitching);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSoftCoverBinding JDFAutoBindingIntent::GetSoftCoverBinding(int iSkip)const{
	JDFSoftCoverBinding e=GetElement(elm_SoftCoverBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSoftCoverBinding JDFAutoBindingIntent::GetCreateSoftCoverBinding(int iSkip){
	JDFSoftCoverBinding e=GetCreateElement(elm_SoftCoverBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSoftCoverBinding JDFAutoBindingIntent::AppendSoftCoverBinding(){
	JDFSoftCoverBinding e=AppendElement(elm_SoftCoverBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTape JDFAutoBindingIntent::GetTape(int iSkip)const{
	JDFTape e=GetElement(elm_Tape,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTape JDFAutoBindingIntent::GetCreateTape(int iSkip){
	JDFTape e=GetCreateElement(elm_Tape,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTape JDFAutoBindingIntent::AppendTape(){
	JDFTape e=AppendElement(elm_Tape);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTabs JDFAutoBindingIntent::GetTabs(int iSkip)const{
	JDFTabs e=GetElement(elm_Tabs,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTabs JDFAutoBindingIntent::GetCreateTabs(int iSkip){
	JDFTabs e=GetCreateElement(elm_Tabs,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTabs JDFAutoBindingIntent::AppendTabs(){
	JDFTabs e=AppendElement(elm_Tabs);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSealing JDFAutoBindingIntent::GetThreadSealing(int iSkip)const{
	JDFThreadSealing e=GetElement(elm_ThreadSealing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSealing JDFAutoBindingIntent::GetCreateThreadSealing(int iSkip){
	JDFThreadSealing e=GetCreateElement(elm_ThreadSealing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSealing JDFAutoBindingIntent::AppendThreadSealing(){
	JDFThreadSealing e=AppendElement(elm_ThreadSealing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSewing JDFAutoBindingIntent::GetThreadSewing(int iSkip)const{
	JDFThreadSewing e=GetElement(elm_ThreadSewing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSewing JDFAutoBindingIntent::GetCreateThreadSewing(int iSkip){
	JDFThreadSewing e=GetCreateElement(elm_ThreadSewing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFThreadSewing JDFAutoBindingIntent::AppendThreadSewing(){
	JDFThreadSewing e=AppendElement(elm_ThreadSewing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripBinding JDFAutoBindingIntent::GetStripBinding(int iSkip)const{
	JDFStripBinding e=GetElement(elm_StripBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripBinding JDFAutoBindingIntent::GetCreateStripBinding(int iSkip){
	JDFStripBinding e=GetCreateElement(elm_StripBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStripBinding JDFAutoBindingIntent::AppendStripBinding(){
	JDFStripBinding e=AppendElement(elm_StripBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFWireCombBinding JDFAutoBindingIntent::GetWireCombBinding(int iSkip)const{
	JDFWireCombBinding e=GetElement(elm_WireCombBinding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFWireCombBinding JDFAutoBindingIntent::GetCreateWireCombBinding(int iSkip){
	JDFWireCombBinding e=GetCreateElement(elm_WireCombBinding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFWireCombBinding JDFAutoBindingIntent::AppendWireCombBinding(){
	JDFWireCombBinding e=AppendElement(elm_WireCombBinding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBindingIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BackCoverColor);

		for(i=0;i<nElem;i++){
			if (!GetBackCoverColor(i).IsValid(level)) {
				vElem.AppendUnique(elm_BackCoverColor);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BackCoverColorDetails);

		for(i=0;i<nElem;i++){
			if (!GetBackCoverColorDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_BackCoverColorDetails);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BindingType);

		for(i=0;i<nElem;i++){
			if (!GetBindingType(i).IsValid(level)) {
				vElem.AppendUnique(elm_BindingType);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BindingColor);

		for(i=0;i<nElem;i++){
			if (!GetBindingColor(i).IsValid(level)) {
				vElem.AppendUnique(elm_BindingColor);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BindingColorDetails);

		for(i=0;i<nElem;i++){
			if (!GetBindingColorDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_BindingColorDetails);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BindingLength);

		for(i=0;i<nElem;i++){
			if (!GetBindingLength(i).IsValid(level)) {
				vElem.AppendUnique(elm_BindingLength);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BindingSide);

		for(i=0;i<nElem;i++){
			if (!GetBindingSide(i).IsValid(level)) {
				vElem.AppendUnique(elm_BindingSide);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CoverColor);

		for(i=0;i<nElem;i++){
			if (!GetCoverColor(i).IsValid(level)) {
				vElem.AppendUnique(elm_CoverColor);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CoverColorDetails);

		for(i=0;i<nElem;i++){
			if (!GetCoverColorDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_CoverColorDetails);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_AdhesiveBinding);

		for(i=0;i<nElem;i++){
			if (!GetAdhesiveBinding(i).IsValid(level)) {
				vElem.AppendUnique(elm_AdhesiveBinding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BindList);

		for(i=0;i<nElem;i++){
			if (!GetBindList(i).IsValid(level)) {
				vElem.AppendUnique(elm_BindList);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BookCase);

		for(i=0;i<nElem;i++){
			if (!GetBookCase(i).IsValid(level)) {
				vElem.AppendUnique(elm_BookCase);
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
	WString JDFAutoBindingIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",BackCoverColor,BackCoverColorDetails,BindingType,BindingColor,BindingColorDetails,BindingLength,BindingSide,CoverColor,CoverColorDetails,AdhesiveBinding,BindList,BookCase,ChannelBinding,CoilBinding,EdgeGluing,HardCoverBinding,PlasticCombBinding,RingBinding,SaddleStitching,SideSewing,SideStitching,SoftCoverBinding,Tape,Tabs,ThreadSealing,ThreadSewing,StripBinding,WireCombBinding";
	};
}; // end namespace JDF
