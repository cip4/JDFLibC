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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFeaturePool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFeaturePool : public JDFPool

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFeaturePool& JDFAutoFeaturePool::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFeaturePool: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFeaturePool::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFeaturePool::ValidNodeNames()const{
	return L"*:,FeaturePool";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoFeaturePool::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFPool::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBooleanState JDFAutoFeaturePool::GetBooleanState(int iSkip)const{
	JDFBooleanState e=GetElement(elm_BooleanState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoFeaturePool::GetCreateBooleanState(int iSkip){
	JDFBooleanState e=GetCreateElement(elm_BooleanState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBooleanState JDFAutoFeaturePool::AppendBooleanState(){
	JDFBooleanState e=AppendElement(elm_BooleanState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoFeaturePool::GetDateTimeState(int iSkip)const{
	JDFDateTimeState e=GetElement(elm_DateTimeState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoFeaturePool::GetCreateDateTimeState(int iSkip){
	JDFDateTimeState e=GetCreateElement(elm_DateTimeState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDateTimeState JDFAutoFeaturePool::AppendDateTimeState(){
	JDFDateTimeState e=AppendElement(elm_DateTimeState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoFeaturePool::GetDurationState(int iSkip)const{
	JDFDurationState e=GetElement(elm_DurationState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoFeaturePool::GetCreateDurationState(int iSkip){
	JDFDurationState e=GetCreateElement(elm_DurationState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDurationState JDFAutoFeaturePool::AppendDurationState(){
	JDFDurationState e=AppendElement(elm_DurationState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoFeaturePool::GetEnumerationState(int iSkip)const{
	JDFEnumerationState e=GetElement(elm_EnumerationState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoFeaturePool::GetCreateEnumerationState(int iSkip){
	JDFEnumerationState e=GetCreateElement(elm_EnumerationState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFEnumerationState JDFAutoFeaturePool::AppendEnumerationState(){
	JDFEnumerationState e=AppendElement(elm_EnumerationState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoFeaturePool::GetIntegerState(int iSkip)const{
	JDFIntegerState e=GetElement(elm_IntegerState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoFeaturePool::GetCreateIntegerState(int iSkip){
	JDFIntegerState e=GetCreateElement(elm_IntegerState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerState JDFAutoFeaturePool::AppendIntegerState(){
	JDFIntegerState e=AppendElement(elm_IntegerState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoFeaturePool::GetMatrixState(int iSkip)const{
	JDFMatrixState e=GetElement(elm_MatrixState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoFeaturePool::GetCreateMatrixState(int iSkip){
	JDFMatrixState e=GetCreateElement(elm_MatrixState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMatrixState JDFAutoFeaturePool::AppendMatrixState(){
	JDFMatrixState e=AppendElement(elm_MatrixState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoFeaturePool::GetNameState(int iSkip)const{
	JDFNameState e=GetElement(elm_NameState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoFeaturePool::GetCreateNameState(int iSkip){
	JDFNameState e=GetCreateElement(elm_NameState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameState JDFAutoFeaturePool::AppendNameState(){
	JDFNameState e=AppendElement(elm_NameState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoFeaturePool::GetNumberState(int iSkip)const{
	JDFNumberState e=GetElement(elm_NumberState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoFeaturePool::GetCreateNumberState(int iSkip){
	JDFNumberState e=GetCreateElement(elm_NumberState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberState JDFAutoFeaturePool::AppendNumberState(){
	JDFNumberState e=AppendElement(elm_NumberState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoFeaturePool::GetPDFPathState(int iSkip)const{
	JDFPDFPathState e=GetElement(elm_PDFPathState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoFeaturePool::GetCreatePDFPathState(int iSkip){
	JDFPDFPathState e=GetCreateElement(elm_PDFPathState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFPathState JDFAutoFeaturePool::AppendPDFPathState(){
	JDFPDFPathState e=AppendElement(elm_PDFPathState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoFeaturePool::GetRectangleState(int iSkip)const{
	JDFRectangleState e=GetElement(elm_RectangleState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoFeaturePool::GetCreateRectangleState(int iSkip){
	JDFRectangleState e=GetCreateElement(elm_RectangleState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRectangleState JDFAutoFeaturePool::AppendRectangleState(){
	JDFRectangleState e=AppendElement(elm_RectangleState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoFeaturePool::GetShapeState(int iSkip)const{
	JDFShapeState e=GetElement(elm_ShapeState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoFeaturePool::GetCreateShapeState(int iSkip){
	JDFShapeState e=GetCreateElement(elm_ShapeState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeState JDFAutoFeaturePool::AppendShapeState(){
	JDFShapeState e=AppendElement(elm_ShapeState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoFeaturePool::GetStringState(int iSkip)const{
	JDFStringState e=GetElement(elm_StringState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoFeaturePool::GetCreateStringState(int iSkip){
	JDFStringState e=GetCreateElement(elm_StringState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringState JDFAutoFeaturePool::AppendStringState(){
	JDFStringState e=AppendElement(elm_StringState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoFeaturePool::GetXYPairState(int iSkip)const{
	JDFXYPairState e=GetElement(elm_XYPairState,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoFeaturePool::GetCreateXYPairState(int iSkip){
	JDFXYPairState e=GetCreateElement(elm_XYPairState,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairState JDFAutoFeaturePool::AppendXYPairState(){
	JDFXYPairState e=AppendElement(elm_XYPairState);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoFeaturePool::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFPool::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BooleanState);

		for(i=0;i<nElem;i++){
			if (!GetBooleanState(i).IsValid(level)) {
				vElem.AppendUnique(elm_BooleanState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DateTimeState);

		for(i=0;i<nElem;i++){
			if (!GetDateTimeState(i).IsValid(level)) {
				vElem.AppendUnique(elm_DateTimeState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DurationState);

		for(i=0;i<nElem;i++){
			if (!GetDurationState(i).IsValid(level)) {
				vElem.AppendUnique(elm_DurationState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_EnumerationState);

		for(i=0;i<nElem;i++){
			if (!GetEnumerationState(i).IsValid(level)) {
				vElem.AppendUnique(elm_EnumerationState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IntegerState);

		for(i=0;i<nElem;i++){
			if (!GetIntegerState(i).IsValid(level)) {
				vElem.AppendUnique(elm_IntegerState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MatrixState);

		for(i=0;i<nElem;i++){
			if (!GetMatrixState(i).IsValid(level)) {
				vElem.AppendUnique(elm_MatrixState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_NameState);

		for(i=0;i<nElem;i++){
			if (!GetNameState(i).IsValid(level)) {
				vElem.AppendUnique(elm_NameState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_NumberState);

		for(i=0;i<nElem;i++){
			if (!GetNumberState(i).IsValid(level)) {
				vElem.AppendUnique(elm_NumberState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PDFPathState);

		for(i=0;i<nElem;i++){
			if (!GetPDFPathState(i).IsValid(level)) {
				vElem.AppendUnique(elm_PDFPathState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RectangleState);

		for(i=0;i<nElem;i++){
			if (!GetRectangleState(i).IsValid(level)) {
				vElem.AppendUnique(elm_RectangleState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ShapeState);

		for(i=0;i<nElem;i++){
			if (!GetShapeState(i).IsValid(level)) {
				vElem.AppendUnique(elm_ShapeState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_StringState);

		for(i=0;i<nElem;i++){
			if (!GetStringState(i).IsValid(level)) {
				vElem.AppendUnique(elm_StringState);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_XYPairState);

		for(i=0;i<nElem;i++){
			if (!GetXYPairState(i).IsValid(level)) {
				vElem.AppendUnique(elm_XYPairState);
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
	WString JDFAutoFeaturePool::OptionalElements()const{
		return JDFPool::OptionalElements()+L",BooleanState,DateTimeState,DurationState,EnumerationState,IntegerState,MatrixState,NameState,NumberState,PDFPathState,RectangleState,ShapeState,StringState,XYPairState";
	};
}; // end namespace JDF
