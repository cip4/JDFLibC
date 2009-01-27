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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFoldingParams.h"
#include "jdf/wrapper/JDFFold.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFoldingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFoldingParams& JDFAutoFoldingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFoldingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFoldingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFoldingParams::ValidNodeNames()const{
	return L"*:,FoldingParams";
};

bool JDFAutoFoldingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoFoldingParams::init(){
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
	WString JDFAutoFoldingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",SheetLay,DescriptionType,FoldCatalog,FoldSheetIn");
};

/**
 typesafe validator
*/
	vWString JDFAutoFoldingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidSheetLay(level)) {
			vAtts.push_back(atr_SheetLay);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidDescriptionType(level)) {
			vAtts.push_back(atr_DescriptionType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFoldCatalog(level)) {
			vAtts.push_back(atr_FoldCatalog);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFoldSheetIn(level)) {
			vAtts.push_back(atr_FoldSheetIn);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFoldingParams::SheetLayString(){
		static const WString enums=WString(L"Unknown,Left,Right");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFoldingParams::SheetLayString(EnumSheetLay value){
		return SheetLayString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFoldingParams::SetSheetLay( EnumSheetLay value){
	SetEnumAttribute(atr_SheetLay,value,SheetLayString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFoldingParams::EnumSheetLay JDFAutoFoldingParams:: GetSheetLay() const {
	return (EnumSheetLay) GetEnumAttribute(atr_SheetLay,SheetLayString(),WString::emptyStr,SheetLay_Left);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFoldingParams::ValidSheetLay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetLay,SheetLayString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFoldingParams::DescriptionTypeString(){
		static const WString enums=WString(L"Unknown,FoldProc,FoldCatalog");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFoldingParams::DescriptionTypeString(EnumDescriptionType value){
		return DescriptionTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFoldingParams::SetDescriptionType( EnumDescriptionType value){
	SetEnumAttribute(atr_DescriptionType,value,DescriptionTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFoldingParams::EnumDescriptionType JDFAutoFoldingParams:: GetDescriptionType() const {
	return (EnumDescriptionType) GetEnumAttribute(atr_DescriptionType,DescriptionTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFoldingParams::ValidDescriptionType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DescriptionType,DescriptionTypeString(),false);
	};
/**
* Set attribute FoldCatalog
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFoldingParams::SetFoldCatalog(const WString& value){
	SetAttribute(atr_FoldCatalog,value);
};
/**
* Get string attribute FoldCatalog
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFoldingParams::GetFoldCatalog() const {
	return GetAttribute(atr_FoldCatalog,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFoldingParams::ValidFoldCatalog(EnumValidationLevel level) const {
		return ValidAttribute(atr_FoldCatalog,AttributeType_string,false);
	};
/**
* Set attribute FoldSheetIn
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoFoldingParams::SetFoldSheetIn(const JDFXYPair& value){
	SetAttribute(atr_FoldSheetIn,value);
};
/**
* Get string attribute FoldSheetIn
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoFoldingParams::GetFoldSheetIn() const {
	return GetAttribute(atr_FoldSheetIn,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFoldingParams::ValidFoldSheetIn(EnumValidationLevel level) const {
		return ValidAttribute(atr_FoldSheetIn,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFFold JDFAutoFoldingParams::GetFold(int iSkip)const{
	JDFFold e=GetElement(elm_Fold,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFold JDFAutoFoldingParams::GetCreateFold(int iSkip){
	JDFFold e=GetCreateElement(elm_Fold,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFold JDFAutoFoldingParams::AppendFold(){
	JDFFold e=AppendElement(elm_Fold);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoFoldingParams::RefFold(JDFFold& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoFoldingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Fold);

		for(i=0;i<nElem;i++){
			if (!GetFold(i).IsValid(level)) {
				vElem.AppendUnique(elm_Fold);
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
	WString JDFAutoFoldingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Fold";
	};
}; // end namespace JDF
