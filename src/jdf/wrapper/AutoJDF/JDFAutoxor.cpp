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

 
#include "jdf/wrapper/AutoJDF/JDFAutoxor.h"
#include "jdf/wrapper/JDFTestRef.h"
#include "jdf/wrapper/JDFBooleanEvaluation.h"
#include "jdf/wrapper/JDFDateTimeEvaluation.h"
#include "jdf/wrapper/JDFDurationEvaluation.h"
#include "jdf/wrapper/JDFEnumerationEvaluation.h"
#include "jdf/wrapper/JDFIntegerEvaluation.h"
#include "jdf/wrapper/JDFIsPresentEvaluation.h"
#include "jdf/wrapper/JDFMatrixEvaluation.h"
#include "jdf/wrapper/JDFNameEvaluation.h"
#include "jdf/wrapper/JDFNumberEvaluation.h"
#include "jdf/wrapper/JDFPDFPathEvaluation.h"
#include "jdf/wrapper/JDFRectangleEvaluation.h"
#include "jdf/wrapper/JDFShapeEvaluation.h"
#include "jdf/wrapper/JDFStringEvaluation.h"
#include "jdf/wrapper/JDFXYPairEvaluation.h"
#include "jdf/wrapper/JDFand.h"
#include "jdf/wrapper/JDFor.h"
#include "jdf/wrapper/JDFnot.h"
#include "jdf/wrapper/JDFxor.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoxor : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoxor& JDFAutoxor::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoxor: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoxor::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoxor::ValidNodeNames()const{
	return L"*:,xor";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoxor::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFTestRef JDFAutoxor::GetTestRef(int iSkip)const{
	JDFTestRef e=GetElement(elm_TestRef,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestRef JDFAutoxor::GetCreateTestRef(int iSkip){
	JDFTestRef e=GetCreateElement(elm_TestRef,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTestRef JDFAutoxor::AppendTestRef(){
	JDFTestRef e=AppendElement(elm_TestRef);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanEvaluation JDFAutoxor::GetBooleanEvaluation(int iSkip)const{
	JDFBooleanEvaluation e=GetElement(elm_BooleanEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanEvaluation JDFAutoxor::GetCreateBooleanEvaluation(int iSkip){
	JDFBooleanEvaluation e=GetCreateElement(elm_BooleanEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanEvaluation JDFAutoxor::AppendBooleanEvaluation(){
	JDFBooleanEvaluation e=AppendElement(elm_BooleanEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeEvaluation JDFAutoxor::GetDateTimeEvaluation(int iSkip)const{
	JDFDateTimeEvaluation e=GetElement(elm_DateTimeEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeEvaluation JDFAutoxor::GetCreateDateTimeEvaluation(int iSkip){
	JDFDateTimeEvaluation e=GetCreateElement(elm_DateTimeEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeEvaluation JDFAutoxor::AppendDateTimeEvaluation(){
	JDFDateTimeEvaluation e=AppendElement(elm_DateTimeEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationEvaluation JDFAutoxor::GetDurationEvaluation(int iSkip)const{
	JDFDurationEvaluation e=GetElement(elm_DurationEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationEvaluation JDFAutoxor::GetCreateDurationEvaluation(int iSkip){
	JDFDurationEvaluation e=GetCreateElement(elm_DurationEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationEvaluation JDFAutoxor::AppendDurationEvaluation(){
	JDFDurationEvaluation e=AppendElement(elm_DurationEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationEvaluation JDFAutoxor::GetEnumerationEvaluation(int iSkip)const{
	JDFEnumerationEvaluation e=GetElement(elm_EnumerationEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationEvaluation JDFAutoxor::GetCreateEnumerationEvaluation(int iSkip){
	JDFEnumerationEvaluation e=GetCreateElement(elm_EnumerationEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationEvaluation JDFAutoxor::AppendEnumerationEvaluation(){
	JDFEnumerationEvaluation e=AppendElement(elm_EnumerationEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerEvaluation JDFAutoxor::GetIntegerEvaluation(int iSkip)const{
	JDFIntegerEvaluation e=GetElement(elm_IntegerEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerEvaluation JDFAutoxor::GetCreateIntegerEvaluation(int iSkip){
	JDFIntegerEvaluation e=GetCreateElement(elm_IntegerEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerEvaluation JDFAutoxor::AppendIntegerEvaluation(){
	JDFIntegerEvaluation e=AppendElement(elm_IntegerEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIsPresentEvaluation JDFAutoxor::GetIsPresentEvaluation(int iSkip)const{
	JDFIsPresentEvaluation e=GetElement(elm_IsPresentEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIsPresentEvaluation JDFAutoxor::GetCreateIsPresentEvaluation(int iSkip){
	JDFIsPresentEvaluation e=GetCreateElement(elm_IsPresentEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIsPresentEvaluation JDFAutoxor::AppendIsPresentEvaluation(){
	JDFIsPresentEvaluation e=AppendElement(elm_IsPresentEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixEvaluation JDFAutoxor::GetMatrixEvaluation(int iSkip)const{
	JDFMatrixEvaluation e=GetElement(elm_MatrixEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixEvaluation JDFAutoxor::GetCreateMatrixEvaluation(int iSkip){
	JDFMatrixEvaluation e=GetCreateElement(elm_MatrixEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixEvaluation JDFAutoxor::AppendMatrixEvaluation(){
	JDFMatrixEvaluation e=AppendElement(elm_MatrixEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameEvaluation JDFAutoxor::GetNameEvaluation(int iSkip)const{
	JDFNameEvaluation e=GetElement(elm_NameEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameEvaluation JDFAutoxor::GetCreateNameEvaluation(int iSkip){
	JDFNameEvaluation e=GetCreateElement(elm_NameEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameEvaluation JDFAutoxor::AppendNameEvaluation(){
	JDFNameEvaluation e=AppendElement(elm_NameEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberEvaluation JDFAutoxor::GetNumberEvaluation(int iSkip)const{
	JDFNumberEvaluation e=GetElement(elm_NumberEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberEvaluation JDFAutoxor::GetCreateNumberEvaluation(int iSkip){
	JDFNumberEvaluation e=GetCreateElement(elm_NumberEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberEvaluation JDFAutoxor::AppendNumberEvaluation(){
	JDFNumberEvaluation e=AppendElement(elm_NumberEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathEvaluation JDFAutoxor::GetPDFPathEvaluation(int iSkip)const{
	JDFPDFPathEvaluation e=GetElement(elm_PDFPathEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathEvaluation JDFAutoxor::GetCreatePDFPathEvaluation(int iSkip){
	JDFPDFPathEvaluation e=GetCreateElement(elm_PDFPathEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathEvaluation JDFAutoxor::AppendPDFPathEvaluation(){
	JDFPDFPathEvaluation e=AppendElement(elm_PDFPathEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleEvaluation JDFAutoxor::GetRectangleEvaluation(int iSkip)const{
	JDFRectangleEvaluation e=GetElement(elm_RectangleEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleEvaluation JDFAutoxor::GetCreateRectangleEvaluation(int iSkip){
	JDFRectangleEvaluation e=GetCreateElement(elm_RectangleEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleEvaluation JDFAutoxor::AppendRectangleEvaluation(){
	JDFRectangleEvaluation e=AppendElement(elm_RectangleEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeEvaluation JDFAutoxor::GetShapeEvaluation(int iSkip)const{
	JDFShapeEvaluation e=GetElement(elm_ShapeEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeEvaluation JDFAutoxor::GetCreateShapeEvaluation(int iSkip){
	JDFShapeEvaluation e=GetCreateElement(elm_ShapeEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeEvaluation JDFAutoxor::AppendShapeEvaluation(){
	JDFShapeEvaluation e=AppendElement(elm_ShapeEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringEvaluation JDFAutoxor::GetStringEvaluation(int iSkip)const{
	JDFStringEvaluation e=GetElement(elm_StringEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringEvaluation JDFAutoxor::GetCreateStringEvaluation(int iSkip){
	JDFStringEvaluation e=GetCreateElement(elm_StringEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringEvaluation JDFAutoxor::AppendStringEvaluation(){
	JDFStringEvaluation e=AppendElement(elm_StringEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairEvaluation JDFAutoxor::GetXYPairEvaluation(int iSkip)const{
	JDFXYPairEvaluation e=GetElement(elm_XYPairEvaluation,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairEvaluation JDFAutoxor::GetCreateXYPairEvaluation(int iSkip){
	JDFXYPairEvaluation e=GetCreateElement(elm_XYPairEvaluation,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairEvaluation JDFAutoxor::AppendXYPairEvaluation(){
	JDFXYPairEvaluation e=AppendElement(elm_XYPairEvaluation);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFand JDFAutoxor::Getand(int iSkip)const{
	JDFand e=GetElement(elm_and,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFand JDFAutoxor::GetCreateand(int iSkip){
	JDFand e=GetCreateElement(elm_and,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFand JDFAutoxor::Appendand(){
	JDFand e=AppendElement(elm_and);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFor JDFAutoxor::Getor(int iSkip)const{
	JDFor e=GetElement(elm_or,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFor JDFAutoxor::GetCreateor(int iSkip){
	JDFor e=GetCreateElement(elm_or,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFor JDFAutoxor::Appendor(){
	JDFor e=AppendElement(elm_or);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFnot JDFAutoxor::Getnot(int iSkip)const{
	JDFnot e=GetElement(elm_not,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFnot JDFAutoxor::GetCreatenot(int iSkip){
	JDFnot e=GetCreateElement(elm_not,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFnot JDFAutoxor::Appendnot(){
	JDFnot e=AppendElement(elm_not);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFxor JDFAutoxor::Getxor(int iSkip)const{
	JDFxor e=GetElement(elm_xor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFxor JDFAutoxor::GetCreatexor(int iSkip){
	JDFxor e=GetCreateElement(elm_xor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFxor JDFAutoxor::Appendxor(){
	JDFxor e=AppendElement(elm_xor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoxor::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_TestRef);

		for(i=0;i<nElem;i++){
			if (!GetTestRef(i).IsValid(level)) {
				vElem.AppendUnique(elm_TestRef);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_BooleanEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetBooleanEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_BooleanEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DateTimeEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetDateTimeEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_DateTimeEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DurationEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetDurationEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_DurationEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_EnumerationEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetEnumerationEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_EnumerationEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IntegerEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetIntegerEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_IntegerEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IsPresentEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetIsPresentEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_IsPresentEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MatrixEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetMatrixEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_MatrixEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_NameEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetNameEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_NameEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_NumberEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetNumberEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_NumberEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PDFPathEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetPDFPathEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_PDFPathEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RectangleEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetRectangleEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_RectangleEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ShapeEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetShapeEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_ShapeEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StringEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetStringEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_StringEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_XYPairEvaluation);

		for(i=0;i<nElem;i++){
			if (!GetXYPairEvaluation(i).IsValid(level)) {
				vElem.AppendUnique(elm_XYPairEvaluation);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_and);

		for(i=0;i<nElem;i++){
			if (!Getand(i).IsValid(level)) {
				vElem.AppendUnique(elm_and);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_or);

		for(i=0;i<nElem;i++){
			if (!Getor(i).IsValid(level)) {
				vElem.AppendUnique(elm_or);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_not);

		for(i=0;i<nElem;i++){
			if (!Getnot(i).IsValid(level)) {
				vElem.AppendUnique(elm_not);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_xor);

		for(i=0;i<nElem;i++){
			if (!Getxor(i).IsValid(level)) {
				vElem.AppendUnique(elm_xor);
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
	WString JDFAutoxor::OptionalElements()const{
		return JDFElement::OptionalElements()+L",TestRef,BooleanEvaluation,DateTimeEvaluation,DurationEvaluation,EnumerationEvaluation,IntegerEvaluation,IsPresentEvaluation,MatrixEvaluation,NameEvaluation,NumberEvaluation,PDFPathEvaluation,RectangleEvaluation,ShapeEvaluation,StringEvaluation,XYPairEvaluation,and,or,not";
	};
}; // end namespace JDF
