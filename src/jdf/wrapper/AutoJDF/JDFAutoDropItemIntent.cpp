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

 
#include "jdf/wrapper/AutoJDF/JDFAutoDropItemIntent.h"
#include "jdf/wrapper/JDFPricing.h"
#include "jdf/wrapper/JDFComponent.h"
#include "jdf/wrapper/JDFExposedMedia.h"
#include "jdf/wrapper/JDFInk.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFPallet.h"
#include "jdf/wrapper/JDFRegisterRibbon.h"
#include "jdf/wrapper/JDFStrap.h"
#include "jdf/wrapper/JDFBundle.h"
#include "jdf/wrapper/JDFDigitalMedia.h"
#include "jdf/wrapper/JDFRollStand.h"
#include "jdf/wrapper/JDFTool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoDropItemIntent : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoDropItemIntent& JDFAutoDropItemIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoDropItemIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoDropItemIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoDropItemIntent::ValidNodeNames()const{
	return L"*:,DropItemIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoDropItemIntent::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AdditionalAmount,Amount,OrderedAmount,Proof,Unit");
};

/**
 typesafe validator
*/
	vWString JDFAutoDropItemIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAdditionalAmount(level)) {
			vAtts.push_back(atr_AdditionalAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidAmount(level)) {
			vAtts.push_back(atr_Amount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOrderedAmount(level)) {
			vAtts.push_back(atr_OrderedAmount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidProof(level)) {
			vAtts.push_back(atr_Proof);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidUnit(level)) {
			vAtts.push_back(atr_Unit);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AdditionalAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDropItemIntent::SetAdditionalAmount(int value){
	SetAttribute(atr_AdditionalAmount,WString::valueOf(value));
};
/**
* Get integer attribute AdditionalAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoDropItemIntent::GetAdditionalAmount() const {
	return GetIntAttribute(atr_AdditionalAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDropItemIntent::ValidAdditionalAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_AdditionalAmount,AttributeType_integer,false);
	};
/**
* Set attribute Amount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDropItemIntent::SetAmount(int value){
	SetAttribute(atr_Amount,WString::valueOf(value));
};
/**
* Get integer attribute Amount
* @return int the vaue of the attribute 
*/
	 int JDFAutoDropItemIntent::GetAmount() const {
	return GetIntAttribute(atr_Amount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDropItemIntent::ValidAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_Amount,AttributeType_integer,false);
	};
/**
* Set attribute OrderedAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoDropItemIntent::SetOrderedAmount(int value){
	SetAttribute(atr_OrderedAmount,WString::valueOf(value));
};
/**
* Get integer attribute OrderedAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoDropItemIntent::GetOrderedAmount() const {
	return GetIntAttribute(atr_OrderedAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDropItemIntent::ValidOrderedAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_OrderedAmount,AttributeType_integer,false);
	};
/**
* Set attribute Proof
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDropItemIntent::SetProof(const WString& value){
	SetAttribute(atr_Proof,value);
};
/**
* Get string attribute Proof
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDropItemIntent::GetProof() const {
	return GetAttribute(atr_Proof,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDropItemIntent::ValidProof(EnumValidationLevel level) const {
		return ValidAttribute(atr_Proof,AttributeType_string,false);
	};
/**
* Set attribute Unit
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoDropItemIntent::SetUnit(const WString& value){
	SetAttribute(atr_Unit,value);
};
/**
* Get string attribute Unit
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoDropItemIntent::GetUnit() const {
	return GetAttribute(atr_Unit,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoDropItemIntent::ValidUnit(EnumValidationLevel level) const {
		return ValidAttribute(atr_Unit,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPricing JDFAutoDropItemIntent::GetPricing(int iSkip)const{
	JDFPricing e=GetElement(elm_Pricing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPricing JDFAutoDropItemIntent::GetCreatePricing(int iSkip){
	JDFPricing e=GetCreateElement(elm_Pricing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPricing JDFAutoDropItemIntent::AppendPricing(){
	JDFPricing e=AppendElement(elm_Pricing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoDropItemIntent::GetComponent(int iSkip)const{
	JDFComponent e=GetElement(elm_Component,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoDropItemIntent::GetCreateComponent(int iSkip){
	JDFComponent e=GetCreateElement(elm_Component,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoDropItemIntent::AppendComponent(){
	JDFComponent e=AppendElement(elm_Component);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefComponent(JDFComponent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFExposedMedia JDFAutoDropItemIntent::GetExposedMedia(int iSkip)const{
	JDFExposedMedia e=GetElement(elm_ExposedMedia,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFExposedMedia JDFAutoDropItemIntent::GetCreateExposedMedia(int iSkip){
	JDFExposedMedia e=GetCreateElement(elm_ExposedMedia,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFExposedMedia JDFAutoDropItemIntent::AppendExposedMedia(){
	JDFExposedMedia e=AppendElement(elm_ExposedMedia);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefExposedMedia(JDFExposedMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFInk JDFAutoDropItemIntent::GetInk(int iSkip)const{
	JDFInk e=GetElement(elm_Ink,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInk JDFAutoDropItemIntent::GetCreateInk(int iSkip){
	JDFInk e=GetCreateElement(elm_Ink,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInk JDFAutoDropItemIntent::AppendInk(){
	JDFInk e=AppendElement(elm_Ink);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefInk(JDFInk& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDropItemIntent::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDropItemIntent::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoDropItemIntent::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPallet JDFAutoDropItemIntent::GetPallet(int iSkip)const{
	JDFPallet e=GetElement(elm_Pallet,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPallet JDFAutoDropItemIntent::GetCreatePallet(int iSkip){
	JDFPallet e=GetCreateElement(elm_Pallet,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPallet JDFAutoDropItemIntent::AppendPallet(){
	JDFPallet e=AppendElement(elm_Pallet);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefPallet(JDFPallet& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFRegisterRibbon JDFAutoDropItemIntent::GetRegisterRibbon(int iSkip)const{
	JDFRegisterRibbon e=GetElement(elm_RegisterRibbon,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterRibbon JDFAutoDropItemIntent::GetCreateRegisterRibbon(int iSkip){
	JDFRegisterRibbon e=GetCreateElement(elm_RegisterRibbon,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRegisterRibbon JDFAutoDropItemIntent::AppendRegisterRibbon(){
	JDFRegisterRibbon e=AppendElement(elm_RegisterRibbon);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefRegisterRibbon(JDFRegisterRibbon& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFStrap JDFAutoDropItemIntent::GetStrap(int iSkip)const{
	JDFStrap e=GetElement(elm_Strap,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStrap JDFAutoDropItemIntent::GetCreateStrap(int iSkip){
	JDFStrap e=GetCreateElement(elm_Strap,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStrap JDFAutoDropItemIntent::AppendStrap(){
	JDFStrap e=AppendElement(elm_Strap);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefStrap(JDFStrap& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFBundle JDFAutoDropItemIntent::GetBundle(int iSkip)const{
	JDFBundle e=GetElement(elm_Bundle,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBundle JDFAutoDropItemIntent::GetCreateBundle(int iSkip){
	JDFBundle e=GetCreateElement(elm_Bundle,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBundle JDFAutoDropItemIntent::AppendBundle(){
	JDFBundle e=AppendElement(elm_Bundle);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefBundle(JDFBundle& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFDigitalMedia JDFAutoDropItemIntent::GetDigitalMedia(int iSkip)const{
	JDFDigitalMedia e=GetElement(elm_DigitalMedia,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDigitalMedia JDFAutoDropItemIntent::GetCreateDigitalMedia(int iSkip){
	JDFDigitalMedia e=GetCreateElement(elm_DigitalMedia,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFDigitalMedia JDFAutoDropItemIntent::AppendDigitalMedia(){
	JDFDigitalMedia e=AppendElement(elm_DigitalMedia);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefDigitalMedia(JDFDigitalMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFRollStand JDFAutoDropItemIntent::GetRollStand(int iSkip)const{
	JDFRollStand e=GetElement(elm_RollStand,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRollStand JDFAutoDropItemIntent::GetCreateRollStand(int iSkip){
	JDFRollStand e=GetCreateElement(elm_RollStand,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFRollStand JDFAutoDropItemIntent::AppendRollStand(){
	JDFRollStand e=AppendElement(elm_RollStand);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefRollStand(JDFRollStand& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFTool JDFAutoDropItemIntent::GetTool(int iSkip)const{
	JDFTool e=GetElement(elm_Tool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTool JDFAutoDropItemIntent::GetCreateTool(int iSkip){
	JDFTool e=GetCreateElement(elm_Tool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFTool JDFAutoDropItemIntent::AppendTool(){
	JDFTool e=AppendElement(elm_Tool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoDropItemIntent::RefTool(JDFTool& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoDropItemIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Pricing);

		for(i=0;i<nElem;i++){
			if (!GetPricing(i).IsValid(level)) {
				vElem.AppendUnique(elm_Pricing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Component);

		for(i=0;i<nElem;i++){
			if (!GetComponent(i).IsValid(level)) {
				vElem.AppendUnique(elm_Component);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ExposedMedia);

		for(i=0;i<nElem;i++){
			if (!GetExposedMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_ExposedMedia);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Ink);

		for(i=0;i<nElem;i++){
			if (!GetInk(i).IsValid(level)) {
				vElem.AppendUnique(elm_Ink);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Media);

		for(i=0;i<nElem;i++){
			if (!GetMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_Media);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Pallet);

		for(i=0;i<nElem;i++){
			if (!GetPallet(i).IsValid(level)) {
				vElem.AppendUnique(elm_Pallet);
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
		nElem=NumChildElements(elm_Strap);

		for(i=0;i<nElem;i++){
			if (!GetStrap(i).IsValid(level)) {
				vElem.AppendUnique(elm_Strap);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Bundle);

		for(i=0;i<nElem;i++){
			if (!GetBundle(i).IsValid(level)) {
				vElem.AppendUnique(elm_Bundle);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DigitalMedia);

		for(i=0;i<nElem;i++){
			if (!GetDigitalMedia(i).IsValid(level)) {
				vElem.AppendUnique(elm_DigitalMedia);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_RollStand);

		for(i=0;i<nElem;i++){
			if (!GetRollStand(i).IsValid(level)) {
				vElem.AppendUnique(elm_RollStand);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_Tool);

		for(i=0;i<nElem;i++){
			if (!GetTool(i).IsValid(level)) {
				vElem.AppendUnique(elm_Tool);
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
	WString JDFAutoDropItemIntent::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Pricing,Component,ExposedMedia,Ink,Media,Pallet,RegisterRibbon,Strap,Bundle,DigitalMedia,RollStand,Tool";
	};
}; // end namespace JDF
