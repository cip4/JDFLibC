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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPackingIntent.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPackingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPackingIntent& JDFAutoPackingIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPackingIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPackingIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPackingIntent::ValidNodeNames()const{
	return L"*:,PackingIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoPackingIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIntegerSpan JDFAutoPackingIntent::GetBoxedQuantity()const{
	JDFIntegerSpan e=GetElement(elm_BoxedQuantity);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::GetCreateBoxedQuantity(){
	JDFIntegerSpan e=GetCreateElement(elm_BoxedQuantity);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::AppendBoxedQuantity(){
	JDFIntegerSpan e=AppendElementN(elm_BoxedQuantity,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoPackingIntent::GetBoxShape()const{
	JDFShapeSpan e=GetElement(elm_BoxShape);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoPackingIntent::GetCreateBoxShape(){
	JDFShapeSpan e=GetCreateElement(elm_BoxShape);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoPackingIntent::AppendBoxShape(){
	JDFShapeSpan e=AppendElementN(elm_BoxShape,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::GetCartonQuantity()const{
	JDFIntegerSpan e=GetElement(elm_CartonQuantity);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::GetCreateCartonQuantity(){
	JDFIntegerSpan e=GetCreateElement(elm_CartonQuantity);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::AppendCartonQuantity(){
	JDFIntegerSpan e=AppendElementN(elm_CartonQuantity,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoPackingIntent::GetCartonShape()const{
	JDFShapeSpan e=GetElement(elm_CartonShape);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoPackingIntent::GetCreateCartonShape(){
	JDFShapeSpan e=GetCreateElement(elm_CartonShape);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFShapeSpan JDFAutoPackingIntent::AppendCartonShape(){
	JDFShapeSpan e=AppendElementN(elm_CartonShape,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::GetCartonMaxWeight()const{
	JDFNumberSpan e=GetElement(elm_CartonMaxWeight);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::GetCreateCartonMaxWeight(){
	JDFNumberSpan e=GetCreateElement(elm_CartonMaxWeight);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::AppendCartonMaxWeight(){
	JDFNumberSpan e=AppendElementN(elm_CartonMaxWeight,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::GetCartonStrength()const{
	JDFNumberSpan e=GetElement(elm_CartonStrength);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::GetCreateCartonStrength(){
	JDFNumberSpan e=GetCreateElement(elm_CartonStrength);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::AppendCartonStrength(){
	JDFNumberSpan e=AppendElementN(elm_CartonStrength,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetFoldingCatalog()const{
	JDFNameSpan e=GetElement(elm_FoldingCatalog);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetCreateFoldingCatalog(){
	JDFNameSpan e=GetCreateElement(elm_FoldingCatalog);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::AppendFoldingCatalog(){
	JDFNameSpan e=AppendElementN(elm_FoldingCatalog,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetPalletCornerBoards()const{
	JDFNameSpan e=GetElement(elm_PalletCornerBoards);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetCreatePalletCornerBoards(){
	JDFNameSpan e=GetCreateElement(elm_PalletCornerBoards);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::AppendPalletCornerBoards(){
	JDFNameSpan e=AppendElementN(elm_PalletCornerBoards,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::GetPalletQuantity()const{
	JDFIntegerSpan e=GetElement(elm_PalletQuantity);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::GetCreatePalletQuantity(){
	JDFIntegerSpan e=GetCreateElement(elm_PalletQuantity);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::AppendPalletQuantity(){
	JDFIntegerSpan e=AppendElementN(elm_PalletQuantity,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoPackingIntent::GetPalletSize()const{
	JDFXYPairSpan e=GetElement(elm_PalletSize);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoPackingIntent::GetCreatePalletSize(){
	JDFXYPairSpan e=GetCreateElement(elm_PalletSize);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFXYPairSpan JDFAutoPackingIntent::AppendPalletSize(){
	JDFXYPairSpan e=AppendElementN(elm_PalletSize,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::GetPalletMaxHeight()const{
	JDFNumberSpan e=GetElement(elm_PalletMaxHeight);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::GetCreatePalletMaxHeight(){
	JDFNumberSpan e=GetCreateElement(elm_PalletMaxHeight);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::AppendPalletMaxHeight(){
	JDFNumberSpan e=AppendElementN(elm_PalletMaxHeight,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::GetPalletMaxWeight()const{
	JDFNumberSpan e=GetElement(elm_PalletMaxWeight);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::GetCreatePalletMaxWeight(){
	JDFNumberSpan e=GetCreateElement(elm_PalletMaxWeight);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoPackingIntent::AppendPalletMaxWeight(){
	JDFNumberSpan e=AppendElementN(elm_PalletMaxWeight,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetPalletType()const{
	JDFNameSpan e=GetElement(elm_PalletType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetCreatePalletType(){
	JDFNameSpan e=GetCreateElement(elm_PalletType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::AppendPalletType(){
	JDFNameSpan e=AppendElementN(elm_PalletType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetPalletWrapping()const{
	JDFNameSpan e=GetElement(elm_PalletWrapping);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetCreatePalletWrapping(){
	JDFNameSpan e=GetCreateElement(elm_PalletWrapping);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::AppendPalletWrapping(){
	JDFNameSpan e=AppendElementN(elm_PalletWrapping,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::GetWrappedQuantity()const{
	JDFIntegerSpan e=GetElement(elm_WrappedQuantity);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::GetCreateWrappedQuantity(){
	JDFIntegerSpan e=GetCreateElement(elm_WrappedQuantity);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIntegerSpan JDFAutoPackingIntent::AppendWrappedQuantity(){
	JDFIntegerSpan e=AppendElementN(elm_WrappedQuantity,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetWrappingMaterial()const{
	JDFNameSpan e=GetElement(elm_WrappingMaterial);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::GetCreateWrappingMaterial(){
	JDFNameSpan e=GetCreateElement(elm_WrappingMaterial);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoPackingIntent::AppendWrappingMaterial(){
	JDFNameSpan e=AppendElementN(elm_WrappingMaterial,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPackingIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BoxedQuantity);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_BoxedQuantity);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetBoxedQuantity().IsValid(level)) {
				vElem.AppendUnique(elm_BoxedQuantity);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_BoxShape);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_BoxShape);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetBoxShape().IsValid(level)) {
				vElem.AppendUnique(elm_BoxShape);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_CartonQuantity);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CartonQuantity);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCartonQuantity().IsValid(level)) {
				vElem.AppendUnique(elm_CartonQuantity);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_CartonShape);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CartonShape);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCartonShape().IsValid(level)) {
				vElem.AppendUnique(elm_CartonShape);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_CartonMaxWeight);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CartonMaxWeight);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCartonMaxWeight().IsValid(level)) {
				vElem.AppendUnique(elm_CartonMaxWeight);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_CartonStrength);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_CartonStrength);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetCartonStrength().IsValid(level)) {
				vElem.AppendUnique(elm_CartonStrength);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FoldingCatalog);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FoldingCatalog);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFoldingCatalog().IsValid(level)) {
				vElem.AppendUnique(elm_FoldingCatalog);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PalletCornerBoards);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PalletCornerBoards);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPalletCornerBoards().IsValid(level)) {
				vElem.AppendUnique(elm_PalletCornerBoards);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PalletQuantity);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PalletQuantity);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPalletQuantity().IsValid(level)) {
				vElem.AppendUnique(elm_PalletQuantity);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PalletSize);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PalletSize);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPalletSize().IsValid(level)) {
				vElem.AppendUnique(elm_PalletSize);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PalletMaxHeight);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PalletMaxHeight);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPalletMaxHeight().IsValid(level)) {
				vElem.AppendUnique(elm_PalletMaxHeight);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PalletMaxWeight);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PalletMaxWeight);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPalletMaxWeight().IsValid(level)) {
				vElem.AppendUnique(elm_PalletMaxWeight);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PalletType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PalletType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPalletType().IsValid(level)) {
				vElem.AppendUnique(elm_PalletType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PalletWrapping);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PalletWrapping);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPalletWrapping().IsValid(level)) {
				vElem.AppendUnique(elm_PalletWrapping);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_WrappedQuantity);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_WrappedQuantity);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetWrappedQuantity().IsValid(level)) {
				vElem.AppendUnique(elm_WrappedQuantity);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_WrappingMaterial);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_WrappingMaterial);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetWrappingMaterial().IsValid(level)) {
				vElem.AppendUnique(elm_WrappingMaterial);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPackingIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",BoxedQuantity,BoxShape,CartonQuantity,CartonShape,CartonMaxWeight,CartonStrength,FoldingCatalog,PalletCornerBoards,PalletQuantity,PalletSize,PalletMaxHeight,PalletMaxWeight,PalletType,PalletWrapping,WrappedQuantity,WrappingMaterial";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPackingIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",BoxedQuantity,BoxShape,CartonQuantity,CartonShape,CartonMaxWeight,CartonStrength,FoldingCatalog,PalletCornerBoards,PalletQuantity,PalletSize,PalletMaxHeight,PalletMaxWeight,PalletType,PalletWrapping,WrappedQuantity,WrappingMaterial";
	};
}; // end namespace JDF
