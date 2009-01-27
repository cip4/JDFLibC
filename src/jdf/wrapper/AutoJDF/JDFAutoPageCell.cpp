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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPageCell.h"
#include "jdf/wrapper/JDFColor.h"
#include "jdf/wrapper/JDFDeviceMark.h"
#include "jdf/wrapper/JDFFitPolicy.h"
#include "jdf/wrapper/JDFImageShift.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPageCell : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPageCell& JDFAutoPageCell::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPageCell: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPageCell::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPageCell::ValidNodeNames()const{
	return L"*:,PageCell";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoPageCell::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Border,ClipBox,MarkList,Rotate,TrimSize");
};

/**
 typesafe validator
*/
	vWString JDFAutoPageCell::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBorder(level)) {
			vAtts.push_back(atr_Border);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidClipBox(level)) {
			vAtts.push_back(atr_ClipBox);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkList(level)) {
			vAtts.push_back(atr_MarkList);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotate(level)) {
			vAtts.push_back(atr_Rotate);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTrimSize(level)) {
			vAtts.push_back(atr_TrimSize);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Border
*@param double value: the value to set the attribute to
*/
	 void JDFAutoPageCell::SetBorder(double value){
	SetAttribute(atr_Border,WString::valueOf(value));
};
/**
* Get double attribute Border
* @return double the vaue of the attribute 
*/
	 double JDFAutoPageCell::GetBorder() const {
	return GetRealAttribute(atr_Border,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageCell::ValidBorder(EnumValidationLevel level) const {
		return ValidAttribute(atr_Border,AttributeType_double,false);
	};
/**
* Set attribute ClipBox
*@param JDFRectangle value: the value to set the attribute to
*/
	 void JDFAutoPageCell::SetClipBox(const JDFRectangle& value){
	SetAttribute(atr_ClipBox,value);
};
/**
* Get string attribute ClipBox
* @return JDFRectangle the vaue of the attribute 
*/
	 JDFRectangle JDFAutoPageCell::GetClipBox() const {
	return GetAttribute(atr_ClipBox,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageCell::ValidClipBox(EnumValidationLevel level) const {
		return ValidAttribute(atr_ClipBox,AttributeType_rectangle,false);
	};
/**
* Set attribute MarkList
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoPageCell::SetMarkList(const vWString& value){
	SetAttribute(atr_MarkList,value);
};
/**
* Get string attribute MarkList
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoPageCell::GetMarkList() const {
	return GetAttribute(atr_MarkList,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageCell::ValidMarkList(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarkList,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoPageCell::RotateString(){
		static const WString enums=WString(L"Unknown,Rotate0,Rotate90,Rotate180,Rotate270");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoPageCell::RotateString(EnumRotate value){
		return RotateString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoPageCell::SetRotate( EnumRotate value){
	SetEnumAttribute(atr_Rotate,value,RotateString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoPageCell::EnumRotate JDFAutoPageCell:: GetRotate() const {
	return (EnumRotate) GetEnumAttribute(atr_Rotate,RotateString(),WString::emptyStr,Rotate_Rotate0);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageCell::ValidRotate(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Rotate,RotateString(),false);
	};
/**
* Set attribute TrimSize
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoPageCell::SetTrimSize(const JDFXYPair& value){
	SetAttribute(atr_TrimSize,value);
};
/**
* Get string attribute TrimSize
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoPageCell::GetTrimSize() const {
	return GetAttribute(atr_TrimSize,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPageCell::ValidTrimSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_TrimSize,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFColor JDFAutoPageCell::GetColor(int iSkip)const{
	JDFColor e=GetElement(elm_Color,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColor JDFAutoPageCell::GetCreateColor(int iSkip){
	JDFColor e=GetCreateElement(elm_Color,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFColor JDFAutoPageCell::AppendColor(){
	JDFColor e=AppendElement(elm_Color);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageCell::RefColor(JDFColor& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoPageCell::GetDeviceMark(int iSkip)const{
	JDFDeviceMark e=GetElement(elm_DeviceMark,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoPageCell::GetCreateDeviceMark(int iSkip){
	JDFDeviceMark e=GetCreateElement(elm_DeviceMark,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDeviceMark JDFAutoPageCell::AppendDeviceMark(){
	JDFDeviceMark e=AppendElement(elm_DeviceMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageCell::RefDeviceMark(JDFDeviceMark& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoPageCell::GetFitPolicy(int iSkip)const{
	JDFFitPolicy e=GetElement(elm_FitPolicy,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoPageCell::GetCreateFitPolicy(int iSkip){
	JDFFitPolicy e=GetCreateElement(elm_FitPolicy,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFitPolicy JDFAutoPageCell::AppendFitPolicy(){
	JDFFitPolicy e=AppendElement(elm_FitPolicy);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPageCell::RefFitPolicy(JDFFitPolicy& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFImageShift JDFAutoPageCell::GetImageShift(int iSkip)const{
	JDFImageShift e=GetElement(elm_ImageShift,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageShift JDFAutoPageCell::GetCreateImageShift(int iSkip){
	JDFImageShift e=GetCreateElement(elm_ImageShift,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFImageShift JDFAutoPageCell::AppendImageShift(){
	JDFImageShift e=AppendElement(elm_ImageShift);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPageCell::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Color);

		for(i=0;i<nElem;i++){
			if (!GetColor(i).IsValid(level)) {
				vElem.AppendUnique(elm_Color);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DeviceMark);

		for(i=0;i<nElem;i++){
			if (!GetDeviceMark(i).IsValid(level)) {
				vElem.AppendUnique(elm_DeviceMark);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FitPolicy);

		for(i=0;i<nElem;i++){
			if (!GetFitPolicy(i).IsValid(level)) {
				vElem.AppendUnique(elm_FitPolicy);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
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
	WString JDFAutoPageCell::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Color,DeviceMark,FitPolicy,ImageShift";
	};
}; // end namespace JDF
