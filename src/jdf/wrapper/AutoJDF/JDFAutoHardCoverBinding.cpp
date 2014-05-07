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

 
#include "jdf/wrapper/AutoJDF/JDFAutoHardCoverBinding.h"
#include "jdf/wrapper/JDFRegisterRibbon.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoHardCoverBinding : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoHardCoverBinding& JDFAutoHardCoverBinding::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoHardCoverBinding: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoHardCoverBinding::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoHardCoverBinding::ValidNodeNames()const{
	return L"*:,HardCoverBinding";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoHardCoverBinding::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFOptionSpan JDFAutoHardCoverBinding::GetBlockThreadSewing(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_BlockThreadSewing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateBlockThreadSewing(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_BlockThreadSewing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendBlockThreadSewing(){
	JDFOptionSpan e=AppendElement(elm_BlockThreadSewing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoHardCoverBinding::GetCoverStyle(int iSkip)const{
	JDFNameSpan e=GetElement(elm_CoverStyle,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoHardCoverBinding::GetCreateCoverStyle(int iSkip){
	JDFNameSpan e=GetCreateElement(elm_CoverStyle,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoHardCoverBinding::AppendCoverStyle(){
	JDFNameSpan e=AppendElement(elm_CoverStyle);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetEndSheets(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_EndSheets,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateEndSheets(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_EndSheets,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendEndSheets(){
	JDFOptionSpan e=AppendElement(elm_EndSheets);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetHeadBands(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_HeadBands,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateHeadBands(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_HeadBands,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendHeadBands(){
	JDFOptionSpan e=AppendElement(elm_HeadBands);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoHardCoverBinding::GetHeadBandColor(int iSkip)const{
	JDFSpanNamedColor e=GetElement(elm_HeadBandColor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoHardCoverBinding::GetCreateHeadBandColor(int iSkip){
	JDFSpanNamedColor e=GetCreateElement(elm_HeadBandColor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoHardCoverBinding::AppendHeadBandColor(){
	JDFSpanNamedColor e=AppendElement(elm_HeadBandColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoHardCoverBinding::GetHeadBandColorDetails(int iSkip)const{
	JDFStringSpan e=GetElement(elm_HeadBandColorDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoHardCoverBinding::GetCreateHeadBandColorDetails(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_HeadBandColorDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoHardCoverBinding::AppendHeadBandColorDetails(){
	JDFStringSpan e=AppendElement(elm_HeadBandColorDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanJacket JDFAutoHardCoverBinding::GetJacket(int iSkip)const{
	JDFSpanJacket e=GetElement(elm_Jacket,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanJacket JDFAutoHardCoverBinding::GetCreateJacket(int iSkip){
	JDFSpanJacket e=GetCreateElement(elm_Jacket,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanJacket JDFAutoHardCoverBinding::AppendJacket(){
	JDFSpanJacket e=AppendElement(elm_Jacket);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoHardCoverBinding::GetJacketFoldingWidth(int iSkip)const{
	JDFNumberSpan e=GetElement(elm_JacketFoldingWidth,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoHardCoverBinding::GetCreateJacketFoldingWidth(int iSkip){
	JDFNumberSpan e=GetCreateElement(elm_JacketFoldingWidth,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoHardCoverBinding::AppendJacketFoldingWidth(){
	JDFNumberSpan e=AppendElement(elm_JacketFoldingWidth);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetJapanBind(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_JapanBind,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateJapanBind(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_JapanBind,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendJapanBind(){
	JDFOptionSpan e=AppendElement(elm_JapanBind);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetSpineBrushing(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineBrushing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateSpineBrushing(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineBrushing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendSpineBrushing(){
	JDFOptionSpan e=AppendElement(elm_SpineBrushing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetSpineFiberRoughing(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineFiberRoughing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateSpineFiberRoughing(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineFiberRoughing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendSpineFiberRoughing(){
	JDFOptionSpan e=AppendElement(elm_SpineFiberRoughing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlue JDFAutoHardCoverBinding::GetSpineGlue(int iSkip)const{
	JDFSpanGlue e=GetElement(elm_SpineGlue,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlue JDFAutoHardCoverBinding::GetCreateSpineGlue(int iSkip){
	JDFSpanGlue e=GetCreateElement(elm_SpineGlue,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlue JDFAutoHardCoverBinding::AppendSpineGlue(){
	JDFSpanGlue e=AppendElement(elm_SpineGlue);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetSpineLevelling(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineLevelling,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateSpineLevelling(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineLevelling,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendSpineLevelling(){
	JDFOptionSpan e=AppendElement(elm_SpineLevelling);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetSpineMilling(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineMilling,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateSpineMilling(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineMilling,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendSpineMilling(){
	JDFOptionSpan e=AppendElement(elm_SpineMilling);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetSpineNotching(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineNotching,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateSpineNotching(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineNotching,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendSpineNotching(){
	JDFOptionSpan e=AppendElement(elm_SpineNotching);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetSpineSanding(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineSanding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateSpineSanding(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineSanding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendSpineSanding(){
	JDFOptionSpan e=AppendElement(elm_SpineSanding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetSpineShredding(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineShredding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::GetCreateSpineShredding(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineShredding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoHardCoverBinding::AppendSpineShredding(){
	JDFOptionSpan e=AppendElement(elm_SpineShredding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanStripMaterial JDFAutoHardCoverBinding::GetStripMaterial(int iSkip)const{
	JDFSpanStripMaterial e=GetElement(elm_StripMaterial,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanStripMaterial JDFAutoHardCoverBinding::GetCreateStripMaterial(int iSkip){
	JDFSpanStripMaterial e=GetCreateElement(elm_StripMaterial,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanStripMaterial JDFAutoHardCoverBinding::AppendStripMaterial(){
	JDFSpanStripMaterial e=AppendElement(elm_StripMaterial);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTightBacking JDFAutoHardCoverBinding::GetTightBacking(int iSkip)const{
	JDFSpanTightBacking e=GetElement(elm_TightBacking,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTightBacking JDFAutoHardCoverBinding::GetCreateTightBacking(int iSkip){
	JDFSpanTightBacking e=GetCreateElement(elm_TightBacking,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanTightBacking JDFAutoHardCoverBinding::AppendTightBacking(){
	JDFSpanTightBacking e=AppendElement(elm_TightBacking);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoHardCoverBinding::GetThickness(int iSkip)const{
	JDFNumberSpan e=GetElement(elm_Thickness,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoHardCoverBinding::GetCreateThickness(int iSkip){
	JDFNumberSpan e=GetCreateElement(elm_Thickness,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoHardCoverBinding::AppendThickness(){
	JDFNumberSpan e=AppendElement(elm_Thickness);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterRibbon JDFAutoHardCoverBinding::GetRegisterRibbon(int iSkip)const{
	JDFRegisterRibbon e=GetElement(elm_RegisterRibbon,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterRibbon JDFAutoHardCoverBinding::GetCreateRegisterRibbon(int iSkip){
	JDFRegisterRibbon e=GetCreateElement(elm_RegisterRibbon,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterRibbon JDFAutoHardCoverBinding::AppendRegisterRibbon(){
	JDFRegisterRibbon e=AppendElement(elm_RegisterRibbon);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoHardCoverBinding::RefRegisterRibbon(JDFRegisterRibbon& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoHardCoverBinding::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BlockThreadSewing);

		for(i=0;i<nElem;i++){
			if (!GetBlockThreadSewing(i).IsValid(level)) {
				vElem.AppendUnique(elm_BlockThreadSewing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CoverStyle);

		for(i=0;i<nElem;i++){
			if (!GetCoverStyle(i).IsValid(level)) {
				vElem.AppendUnique(elm_CoverStyle);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_EndSheets);

		for(i=0;i<nElem;i++){
			if (!GetEndSheets(i).IsValid(level)) {
				vElem.AppendUnique(elm_EndSheets);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_HeadBands);

		for(i=0;i<nElem;i++){
			if (!GetHeadBands(i).IsValid(level)) {
				vElem.AppendUnique(elm_HeadBands);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_HeadBandColor);

		for(i=0;i<nElem;i++){
			if (!GetHeadBandColor(i).IsValid(level)) {
				vElem.AppendUnique(elm_HeadBandColor);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_HeadBandColorDetails);

		for(i=0;i<nElem;i++){
			if (!GetHeadBandColorDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_HeadBandColorDetails);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Jacket);

		for(i=0;i<nElem;i++){
			if (!GetJacket(i).IsValid(level)) {
				vElem.AppendUnique(elm_Jacket);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_JacketFoldingWidth);

		for(i=0;i<nElem;i++){
			if (!GetJacketFoldingWidth(i).IsValid(level)) {
				vElem.AppendUnique(elm_JacketFoldingWidth);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_JapanBind);

		for(i=0;i<nElem;i++){
			if (!GetJapanBind(i).IsValid(level)) {
				vElem.AppendUnique(elm_JapanBind);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineBrushing);

		for(i=0;i<nElem;i++){
			if (!GetSpineBrushing(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineBrushing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineFiberRoughing);

		for(i=0;i<nElem;i++){
			if (!GetSpineFiberRoughing(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineFiberRoughing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineGlue);

		for(i=0;i<nElem;i++){
			if (!GetSpineGlue(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineGlue);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineLevelling);

		for(i=0;i<nElem;i++){
			if (!GetSpineLevelling(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineLevelling);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineMilling);

		for(i=0;i<nElem;i++){
			if (!GetSpineMilling(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineMilling);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineNotching);

		for(i=0;i<nElem;i++){
			if (!GetSpineNotching(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineNotching);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineSanding);

		for(i=0;i<nElem;i++){
			if (!GetSpineSanding(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineSanding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_SpineShredding);

		for(i=0;i<nElem;i++){
			if (!GetSpineShredding(i).IsValid(level)) {
				vElem.AppendUnique(elm_SpineShredding);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StripMaterial);

		for(i=0;i<nElem;i++){
			if (!GetStripMaterial(i).IsValid(level)) {
				vElem.AppendUnique(elm_StripMaterial);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TightBacking);

		for(i=0;i<nElem;i++){
			if (!GetTightBacking(i).IsValid(level)) {
				vElem.AppendUnique(elm_TightBacking);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Thickness);

		for(i=0;i<nElem;i++){
			if (!GetThickness(i).IsValid(level)) {
				vElem.AppendUnique(elm_Thickness);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RegisterRibbon);

		for(i=0;i<nElem;i++){
			if (!GetRegisterRibbon(i).IsValid(level)) {
				vElem.AppendUnique(elm_RegisterRibbon);
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
	WString JDFAutoHardCoverBinding::OptionalElements()const{
		return JDFElement::OptionalElements()+L",BlockThreadSewing,CoverStyle,EndSheets,HeadBands,HeadBandColor,HeadBandColorDetails,Jacket,JacketFoldingWidth,JapanBind,SpineBrushing,SpineFiberRoughing,SpineGlue,SpineLevelling,SpineMilling,SpineNotching,SpineSanding,SpineShredding,StripMaterial,TightBacking,Thickness,RegisterRibbon";
	};
}; // end namespace JDF
