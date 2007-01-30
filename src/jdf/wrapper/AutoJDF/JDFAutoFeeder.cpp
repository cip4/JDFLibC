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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFeeder.h"
#include "jdf/wrapper/JDFComponent.h"
#include "jdf/wrapper/JDFFeederQualityParams.h"
#include "jdf/wrapper/JDFMedia.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFeeder : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFeeder& JDFAutoFeeder::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFeeder: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFeeder::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFeeder::ValidNodeNames()const{
	return L"*:,Feeder";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoFeeder::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",AlternatePositions,Position,FeederSynchronization,FeederType,Loading,Opening");
};

/**
 typesafe validator
*/
	vWString JDFAutoFeeder::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidAlternatePositions(level)) {
			vAtts.push_back(atr_AlternatePositions);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPosition(level)) {
			vAtts.push_back(atr_Position);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFeederSynchronization(level)) {
			vAtts.push_back(atr_FeederSynchronization);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFeederType(level)) {
			vAtts.push_back(atr_FeederType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidLoading(level)) {
			vAtts.push_back(atr_Loading);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidOpening(level)) {
			vAtts.push_back(atr_Opening);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute AlternatePositions
*@param JDFIntegerList value: the value to set the attribute to
*/
	 void JDFAutoFeeder::SetAlternatePositions(const JDFIntegerList& value){
	SetAttribute(atr_AlternatePositions,value.GetString());
};
/**
* Get string attribute AlternatePositions
* @return JDFIntegerList the vaue of the attribute 
*/
	 JDFIntegerList JDFAutoFeeder::GetAlternatePositions() const {
	return GetAttribute(atr_AlternatePositions,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeeder::ValidAlternatePositions(EnumValidationLevel level) const {
		return ValidAttribute(atr_AlternatePositions,AttributeType_IntegerList,false);
	};
/**
* Set attribute Position
*@param int value: the value to set the attribute to
*/
	 void JDFAutoFeeder::SetPosition(int value){
	SetAttribute(atr_Position,WString::valueOf(value));
};
/**
* Get integer attribute Position
* @return int the vaue of the attribute 
*/
	 int JDFAutoFeeder::GetPosition() const {
	return GetIntAttribute(atr_Position,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeeder::ValidPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Position,AttributeType_integer,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFeeder::FeederSynchronizationString(){
		static const WString enums=WString(L"Unknown,Alternate,Backup,Chain,Primary");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFeeder::FeederSynchronizationString(EnumFeederSynchronization value){
		return FeederSynchronizationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFeeder::SetFeederSynchronization( EnumFeederSynchronization value){
	SetEnumAttribute(atr_FeederSynchronization,value,FeederSynchronizationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFeeder::EnumFeederSynchronization JDFAutoFeeder:: GetFeederSynchronization() const {
	return (EnumFeederSynchronization) GetEnumAttribute(atr_FeederSynchronization,FeederSynchronizationString(),WString::emptyStr,FeederSynchronization_Primary);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeeder::ValidFeederSynchronization(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_FeederSynchronization,FeederSynchronizationString(),false);
	};
/**
* Set attribute FeederType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFeeder::SetFeederType(const WString& value){
	SetAttribute(atr_FeederType,value);
};
/**
* Get string attribute FeederType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFeeder::GetFeederType() const {
	return GetAttribute(atr_FeederType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeeder::ValidFeederType(EnumValidationLevel level) const {
		return ValidAttribute(atr_FeederType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute Loading
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoFeeder::SetLoading(const WString& value){
	SetAttribute(atr_Loading,value);
};
/**
* Get string attribute Loading
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoFeeder::GetLoading() const {
	return GetAttribute(atr_Loading,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeeder::ValidLoading(EnumValidationLevel level) const {
		return ValidAttribute(atr_Loading,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoFeeder::OpeningString(){
		static const WString enums=WString(L"Unknown,Back,Front,None,Sucker");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoFeeder::OpeningString(EnumOpening value){
		return OpeningString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoFeeder::SetOpening( EnumOpening value){
	SetEnumAttribute(atr_Opening,value,OpeningString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoFeeder::EnumOpening JDFAutoFeeder:: GetOpening() const {
	return (EnumOpening) GetEnumAttribute(atr_Opening,OpeningString(),WString::emptyStr,Opening_None);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFeeder::ValidOpening(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Opening,OpeningString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFComponent JDFAutoFeeder::GetComponent(int iSkip)const{
	JDFComponent e=GetElement(elm_Component,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoFeeder::GetCreateComponent(int iSkip){
	JDFComponent e=GetCreateElement(elm_Component,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFComponent JDFAutoFeeder::AppendComponent(){
	JDFComponent e=AppendElement(elm_Component);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoFeeder::RefComponent(JDFComponent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFFeederQualityParams JDFAutoFeeder::GetFeederQualityParams(int iSkip)const{
	JDFFeederQualityParams e=GetElement(elm_FeederQualityParams,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFeederQualityParams JDFAutoFeeder::GetCreateFeederQualityParams(int iSkip){
	JDFFeederQualityParams e=GetCreateElement(elm_FeederQualityParams,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFeederQualityParams JDFAutoFeeder::AppendFeederQualityParams(){
	JDFFeederQualityParams e=AppendElement(elm_FeederQualityParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoFeeder::GetMedia(int iSkip)const{
	JDFMedia e=GetElement(elm_Media,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoFeeder::GetCreateMedia(int iSkip){
	JDFMedia e=GetCreateElement(elm_Media,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMedia JDFAutoFeeder::AppendMedia(){
	JDFMedia e=AppendElement(elm_Media);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoFeeder::RefMedia(JDFMedia& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoFeeder::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Component);

		for(i=0;i<nElem;i++){
			if (!GetComponent(i).IsValid(level)) {
				vElem.AppendUnique(elm_Component);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FeederQualityParams);

		for(i=0;i<nElem;i++){
			if (!GetFeederQualityParams(i).IsValid(level)) {
				vElem.AppendUnique(elm_FeederQualityParams);
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
		return vElem;
	};


/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoFeeder::OptionalElements()const{
		return JDFElement::OptionalElements()+L",Component,FeederQualityParams,Media";
	};
}; // end namespace JDF
