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

 
#include "jdf/wrapper/AutoJDF/JDFAutoTabs.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoTabs : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoTabs& JDFAutoTabs::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoTabs: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoTabs::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoTabs::ValidNodeNames()const{
	return L"*:,Tabs";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoTabs::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",TabBanks,TabCount,TabsPerBank");
};

/**
 typesafe validator
*/
	vWString JDFAutoTabs::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidTabBanks(level)) {
			vAtts.push_back(atr_TabBanks);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTabCount(level)) {
			vAtts.push_back(atr_TabCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTabsPerBank(level)) {
			vAtts.push_back(atr_TabsPerBank);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute TabBanks
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTabs::SetTabBanks(int value){
	SetAttribute(atr_TabBanks,WString::valueOf(value));
};
/**
* Get integer attribute TabBanks
* @return int the vaue of the attribute ; defaults to 1
*/
	 int JDFAutoTabs::GetTabBanks() const {
	return GetIntAttribute(atr_TabBanks,WString::emptyStr,1);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabs::ValidTabBanks(EnumValidationLevel level) const {
		return ValidAttribute(atr_TabBanks,AttributeType_integer,false);
	};
/**
* Set attribute TabCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTabs::SetTabCount(int value){
	SetAttribute(atr_TabCount,WString::valueOf(value));
};
/**
* Get integer attribute TabCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoTabs::GetTabCount() const {
	return GetIntAttribute(atr_TabCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabs::ValidTabCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_TabCount,AttributeType_integer,false);
	};
/**
* Set attribute TabsPerBank
*@param int value: the value to set the attribute to
*/
	 void JDFAutoTabs::SetTabsPerBank(int value){
	SetAttribute(atr_TabsPerBank,WString::valueOf(value));
};
/**
* Get integer attribute TabsPerBank
* @return int the vaue of the attribute 
*/
	 int JDFAutoTabs::GetTabsPerBank() const {
	return GetIntAttribute(atr_TabsPerBank,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoTabs::ValidTabsPerBank(EnumValidationLevel level) const {
		return ValidAttribute(atr_TabsPerBank,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFStringSpan JDFAutoTabs::GetTabBrand(int iSkip)const{
	JDFStringSpan e=GetElement(elm_TabBrand,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoTabs::GetCreateTabBrand(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_TabBrand,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoTabs::AppendTabBrand(){
	JDFStringSpan e=AppendElement(elm_TabBrand);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoTabs::GetTabExtensionDistance(int iSkip)const{
	JDFNumberSpan e=GetElement(elm_TabExtensionDistance,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoTabs::GetCreateTabExtensionDistance(int iSkip){
	JDFNumberSpan e=GetCreateElement(elm_TabExtensionDistance,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNumberSpan JDFAutoTabs::AppendTabExtensionDistance(){
	JDFNumberSpan e=AppendElement(elm_TabExtensionDistance);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::GetTabExtensionMylar(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_TabExtensionMylar,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::GetCreateTabExtensionMylar(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_TabExtensionMylar,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::AppendTabExtensionMylar(){
	JDFOptionSpan e=AppendElement(elm_TabExtensionMylar);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::GetTabBindMylar(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_TabBindMylar,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::GetCreateTabBindMylar(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_TabBindMylar,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::AppendTabBindMylar(){
	JDFOptionSpan e=AppendElement(elm_TabBindMylar);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::GetTabBodyCopy(int iSkip)const{
	JDFOptionSpan e=GetElement(elm_TabBodyCopy,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::GetCreateTabBodyCopy(int iSkip){
	JDFOptionSpan e=GetCreateElement(elm_TabBodyCopy,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFOptionSpan JDFAutoTabs::AppendTabBodyCopy(){
	JDFOptionSpan e=AppendElement(elm_TabBodyCopy);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoTabs::GetTabMylarColor(int iSkip)const{
	JDFSpanNamedColor e=GetElement(elm_TabMylarColor,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoTabs::GetCreateTabMylarColor(int iSkip){
	JDFSpanNamedColor e=GetCreateElement(elm_TabMylarColor,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanNamedColor JDFAutoTabs::AppendTabMylarColor(){
	JDFSpanNamedColor e=AppendElement(elm_TabMylarColor);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoTabs::GetTabMylarColorDetails(int iSkip)const{
	JDFStringSpan e=GetElement(elm_TabMylarColorDetails,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoTabs::GetCreateTabMylarColorDetails(int iSkip){
	JDFStringSpan e=GetCreateElement(elm_TabMylarColorDetails,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFStringSpan JDFAutoTabs::AppendTabMylarColorDetails(){
	JDFStringSpan e=AppendElement(elm_TabMylarColorDetails);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoTabs::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_TabBrand);

		for(i=0;i<nElem;i++){
			if (!GetTabBrand(i).IsValid(level)) {
				vElem.AppendUnique(elm_TabBrand);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TabExtensionDistance);

		for(i=0;i<nElem;i++){
			if (!GetTabExtensionDistance(i).IsValid(level)) {
				vElem.AppendUnique(elm_TabExtensionDistance);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TabExtensionMylar);

		for(i=0;i<nElem;i++){
			if (!GetTabExtensionMylar(i).IsValid(level)) {
				vElem.AppendUnique(elm_TabExtensionMylar);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TabBindMylar);

		for(i=0;i<nElem;i++){
			if (!GetTabBindMylar(i).IsValid(level)) {
				vElem.AppendUnique(elm_TabBindMylar);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TabBodyCopy);

		for(i=0;i<nElem;i++){
			if (!GetTabBodyCopy(i).IsValid(level)) {
				vElem.AppendUnique(elm_TabBodyCopy);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TabMylarColor);

		for(i=0;i<nElem;i++){
			if (!GetTabMylarColor(i).IsValid(level)) {
				vElem.AppendUnique(elm_TabMylarColor);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_TabMylarColorDetails);

		for(i=0;i<nElem;i++){
			if (!GetTabMylarColorDetails(i).IsValid(level)) {
				vElem.AppendUnique(elm_TabMylarColorDetails);
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
	WString JDFAutoTabs::OptionalElements()const{
		return JDFElement::OptionalElements()+L",TabBrand,TabExtensionDistance,TabExtensionMylar,TabBindMylar,TabBodyCopy,TabMylarColor,TabMylarColorDetails";
	};
}; // end namespace JDF
