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

 
#include "jdf/wrapper/AutoJDF/JDFAutoSoftCoverBinding.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoSoftCoverBinding : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoSoftCoverBinding& JDFAutoSoftCoverBinding::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoSoftCoverBinding: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoSoftCoverBinding::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoSoftCoverBinding::ValidNodeNames()const{
	return L"*:,SoftCoverBinding";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoSoftCoverBinding::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFOptionSpan JDFAutoSoftCoverBinding::GetBlockThreadSewing(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_BlockThreadSewing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateBlockThreadSewing(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_BlockThreadSewing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendBlockThreadSewing(){
	JDFOptionSpan e=AppendElement(elm_BlockThreadSewing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetEndSheets(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_EndSheets,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateEndSheets(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_EndSheets,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendEndSheets(){
	JDFOptionSpan e=AppendElement(elm_EndSheets);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoSoftCoverBinding::GetFoldingWidth(int iSkip)const{
	JDFNumberSpan e=GetElement(elm_FoldingWidth,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoSoftCoverBinding::GetCreateFoldingWidth(int iSkip){
	JDFNumberSpan e=GetCreateElement(elm_FoldingWidth,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoSoftCoverBinding::AppendFoldingWidth(){
	JDFNumberSpan e=AppendElement(elm_FoldingWidth);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoSoftCoverBinding::GetFoldingWidthBack(int iSkip)const{
	JDFNumberSpan e=GetElement(elm_FoldingWidthBack,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoSoftCoverBinding::GetCreateFoldingWidthBack(int iSkip){
	JDFNumberSpan e=GetCreateElement(elm_FoldingWidthBack,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoSoftCoverBinding::AppendFoldingWidthBack(){
	JDFNumberSpan e=AppendElement(elm_FoldingWidthBack);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlueProcedure JDFAutoSoftCoverBinding::GetGlueProcedure(int iSkip)const{
	JDFSpanGlueProcedure e=GetElement(elm_GlueProcedure,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlueProcedure JDFAutoSoftCoverBinding::GetCreateGlueProcedure(int iSkip){
	JDFSpanGlueProcedure e=GetCreateElement(elm_GlueProcedure,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlueProcedure JDFAutoSoftCoverBinding::AppendGlueProcedure(){
	JDFSpanGlueProcedure e=AppendElement(elm_GlueProcedure);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanScoring JDFAutoSoftCoverBinding::GetScoring(int iSkip)const{
	JDFSpanScoring e=GetElement(elm_Scoring,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanScoring JDFAutoSoftCoverBinding::GetCreateScoring(int iSkip){
	JDFSpanScoring e=GetCreateElement(elm_Scoring,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanScoring JDFAutoSoftCoverBinding::AppendScoring(){
	JDFSpanScoring e=AppendElement(elm_Scoring);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetSpineBrushing(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineBrushing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateSpineBrushing(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineBrushing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendSpineBrushing(){
	JDFOptionSpan e=AppendElement(elm_SpineBrushing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetSpineFiberRoughing(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineFiberRoughing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateSpineFiberRoughing(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineFiberRoughing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendSpineFiberRoughing(){
	JDFOptionSpan e=AppendElement(elm_SpineFiberRoughing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlue JDFAutoSoftCoverBinding::GetSpineGlue(int iSkip)const{
	JDFSpanGlue e=GetElement(elm_SpineGlue,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlue JDFAutoSoftCoverBinding::GetCreateSpineGlue(int iSkip){
	JDFSpanGlue e=GetCreateElement(elm_SpineGlue,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlue JDFAutoSoftCoverBinding::AppendSpineGlue(){
	JDFSpanGlue e=AppendElement(elm_SpineGlue);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetSpineLevelling(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineLevelling,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateSpineLevelling(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineLevelling,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendSpineLevelling(){
	JDFOptionSpan e=AppendElement(elm_SpineLevelling);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetSpineMilling(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineMilling,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateSpineMilling(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineMilling,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendSpineMilling(){
	JDFOptionSpan e=AppendElement(elm_SpineMilling);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetSpineNotching(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineNotching,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateSpineNotching(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineNotching,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendSpineNotching(){
	JDFOptionSpan e=AppendElement(elm_SpineNotching);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetSpineSanding(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineSanding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateSpineSanding(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineSanding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendSpineSanding(){
	JDFOptionSpan e=AppendElement(elm_SpineSanding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetSpineShredding(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_SpineShredding,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::GetCreateSpineShredding(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_SpineShredding,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoSoftCoverBinding::AppendSpineShredding(){
	JDFOptionSpan e=AppendElement(elm_SpineShredding);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoSoftCoverBinding::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
		nElem=NumChildElements(elm_EndSheets);

		for(i=0;i<nElem;i++){
			if (!GetEndSheets(i).IsValid(level)) {
				vElem.AppendUnique(elm_EndSheets);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FoldingWidth);

		for(i=0;i<nElem;i++){
			if (!GetFoldingWidth(i).IsValid(level)) {
				vElem.AppendUnique(elm_FoldingWidth);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FoldingWidthBack);

		for(i=0;i<nElem;i++){
			if (!GetFoldingWidthBack(i).IsValid(level)) {
				vElem.AppendUnique(elm_FoldingWidthBack);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_GlueProcedure);

		for(i=0;i<nElem;i++){
			if (!GetGlueProcedure(i).IsValid(level)) {
				vElem.AppendUnique(elm_GlueProcedure);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Scoring);

		for(i=0;i<nElem;i++){
			if (!GetScoring(i).IsValid(level)) {
				vElem.AppendUnique(elm_Scoring);
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
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoSoftCoverBinding::OptionalElements()const{
		return JDFElement::OptionalElements()+L",BlockThreadSewing,EndSheets,FoldingWidth,FoldingWidthBack,GlueProcedure,Scoring,SpineBrushing,SpineFiberRoughing,SpineGlue,SpineLevelling,SpineMilling,SpineNotching,SpineSanding,SpineShredding";
	};
}; // end namespace JDF
