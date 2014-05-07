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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCuttingParams.h"
#include "jdf/wrapper/JDFCutBlock.h"
#include "jdf/wrapper/JDFCutMark.h"
#include "jdf/wrapper/JDFCut.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCuttingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCuttingParams& JDFAutoCuttingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCuttingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCuttingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCuttingParams::ValidNodeNames()const{
	return L"*:,CuttingParams";
};

bool JDFAutoCuttingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoCuttingParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCuttingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",NUpSeparation,SheetLay");
};

/**
 typesafe validator
*/
	vWString JDFAutoCuttingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidNUpSeparation(level)) {
			vAtts.push_back(atr_NUpSeparation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetLay(level)) {
			vAtts.push_back(atr_SheetLay);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute NUpSeparation
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCuttingParams::SetNUpSeparation(const JDFXYPair& value){
	SetAttribute(atr_NUpSeparation,value);
};
/**
* Get string attribute NUpSeparation
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCuttingParams::GetNUpSeparation() const {
	return GetAttribute(atr_NUpSeparation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCuttingParams::ValidNUpSeparation(EnumValidationLevel level) const {
		return ValidAttribute(atr_NUpSeparation,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCuttingParams::SheetLayString(){
		static const WString enums=WString(L"Unknown,Left,Right");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCuttingParams::SheetLayString(EnumSheetLay value){
		return SheetLayString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCuttingParams::SetSheetLay( EnumSheetLay value){
	SetEnumAttribute(atr_SheetLay,value,SheetLayString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCuttingParams::EnumSheetLay JDFAutoCuttingParams:: GetSheetLay() const {
	return (EnumSheetLay) GetEnumAttribute(atr_SheetLay,SheetLayString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCuttingParams::ValidSheetLay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetLay,SheetLayString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFCutBlock JDFAutoCuttingParams::GetCutBlock(int iSkip)const{
	JDFCutBlock e=GetElement(elm_CutBlock,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCutBlock JDFAutoCuttingParams::GetCreateCutBlock(int iSkip){
	JDFCutBlock e=GetCreateElement(elm_CutBlock,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCutBlock JDFAutoCuttingParams::AppendCutBlock(){
	JDFCutBlock e=AppendElement(elm_CutBlock);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCuttingParams::RefCutBlock(JDFCutBlock& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFCutMark JDFAutoCuttingParams::GetCutMark(int iSkip)const{
	JDFCutMark e=GetElement(elm_CutMark,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCutMark JDFAutoCuttingParams::GetCreateCutMark(int iSkip){
	JDFCutMark e=GetCreateElement(elm_CutMark,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCutMark JDFAutoCuttingParams::AppendCutMark(){
	JDFCutMark e=AppendElement(elm_CutMark);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCuttingParams::RefCutMark(JDFCutMark& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFCut JDFAutoCuttingParams::GetCut(int iSkip)const{
	JDFCut e=GetElement(elm_Cut,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCut JDFAutoCuttingParams::GetCreateCut(int iSkip){
	JDFCut e=GetCreateElement(elm_Cut,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCut JDFAutoCuttingParams::AppendCut(){
	JDFCut e=AppendElement(elm_Cut);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCuttingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_CutBlock);

		for(i=0;i<nElem;i++){
			if (!GetCutBlock(i).IsValid(level)) {
				vElem.AppendUnique(elm_CutBlock);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_CutMark);

		for(i=0;i<nElem;i++){
			if (!GetCutMark(i).IsValid(level)) {
				vElem.AppendUnique(elm_CutMark);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Cut);

		for(i=0;i<nElem;i++){
			if (!GetCut(i).IsValid(level)) {
				vElem.AppendUnique(elm_Cut);
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
	WString JDFAutoCuttingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",CutBlock,CutMark,Cut";
	};
}; // end namespace JDF
