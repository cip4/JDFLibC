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

 
#include "jdf/wrapper/AutoJDF/JDFAutoShapeCuttingParams.h"
#include "jdf/wrapper/JDFDieLayout.h"
#include "jdf/wrapper/JDFShapeElement.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoShapeCuttingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoShapeCuttingParams& JDFAutoShapeCuttingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoShapeCuttingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoShapeCuttingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoShapeCuttingParams::ValidNodeNames()const{
	return L"*:,ShapeCuttingParams";
};

bool JDFAutoShapeCuttingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoShapeCuttingParams::init(){
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
	WString JDFAutoShapeCuttingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DeliveryMode,SheetLay");
};

/**
 typesafe validator
*/
	vWString JDFAutoShapeCuttingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDeliveryMode(level)) {
			vAtts.push_back(atr_DeliveryMode);
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

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoShapeCuttingParams::DeliveryModeString(){
		static const WString enums=WString(L"Unknown,FullSheet,RemoveGripperMargin,SeparateBlanks");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoShapeCuttingParams::DeliveryModeString(EnumDeliveryMode value){
		return DeliveryModeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoShapeCuttingParams::SetDeliveryMode( EnumDeliveryMode value){
	SetEnumAttribute(atr_DeliveryMode,value,DeliveryModeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoShapeCuttingParams::EnumDeliveryMode JDFAutoShapeCuttingParams:: GetDeliveryMode() const {
	return (EnumDeliveryMode) GetEnumAttribute(atr_DeliveryMode,DeliveryModeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeCuttingParams::ValidDeliveryMode(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_DeliveryMode,DeliveryModeString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoShapeCuttingParams::SheetLayString(){
		static const WString enums=WString(L"Unknown,Left,Right,Center");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoShapeCuttingParams::SheetLayString(EnumSheetLay value){
		return SheetLayString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoShapeCuttingParams::SetSheetLay( EnumSheetLay value){
	SetEnumAttribute(atr_SheetLay,value,SheetLayString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoShapeCuttingParams::EnumSheetLay JDFAutoShapeCuttingParams:: GetSheetLay() const {
	return (EnumSheetLay) GetEnumAttribute(atr_SheetLay,SheetLayString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoShapeCuttingParams::ValidSheetLay(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetLay,SheetLayString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFDieLayout JDFAutoShapeCuttingParams::GetDieLayout(int iSkip)const{
	JDFDieLayout e=GetElement(elm_DieLayout,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDieLayout JDFAutoShapeCuttingParams::GetCreateDieLayout(int iSkip){
	JDFDieLayout e=GetCreateElement(elm_DieLayout,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDieLayout JDFAutoShapeCuttingParams::AppendDieLayout(){
	JDFDieLayout e=AppendElement(elm_DieLayout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoShapeCuttingParams::RefDieLayout(JDFDieLayout& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFShapeElement JDFAutoShapeCuttingParams::GetShape(int iSkip)const{
	JDFShapeElement e=GetElement(elm_Shape,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeElement JDFAutoShapeCuttingParams::GetCreateShape(int iSkip){
	JDFShapeElement e=GetCreateElement(elm_Shape,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeElement JDFAutoShapeCuttingParams::AppendShape(){
	JDFShapeElement e=AppendElement(elm_Shape);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoShapeCuttingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_DieLayout);

		for(i=0;i<nElem;i++){
			if (!GetDieLayout(i).IsValid(level)) {
				vElem.AppendUnique(elm_DieLayout);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Shape);

		for(i=0;i<nElem;i++){
			if (!GetShape(i).IsValid(level)) {
				vElem.AppendUnique(elm_Shape);
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
	WString JDFAutoShapeCuttingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",DieLayout,Shape";
	};
}; // end namespace JDF
