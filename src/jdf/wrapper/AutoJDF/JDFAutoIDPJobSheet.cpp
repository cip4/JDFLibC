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

 
#include "jdf/wrapper/AutoJDF/JDFAutoIDPJobSheet.h"
#include "jdf/wrapper/JDFIDPFinishing.h"
#include "jdf/wrapper/JDFIDPLayout.h"
#include "jdf/wrapper/JDFMediaIntent.h"
#include "jdf/wrapper/JDFMediaSource.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoIDPJobSheet : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoIDPJobSheet& JDFAutoIDPJobSheet::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoIDPJobSheet: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoIDPJobSheet::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoIDPJobSheet::ValidNodeNames()const{
	return L"*:,IDPJobSheet";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoIDPJobSheet::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",SheetFormat,SheetOccurence,SheetType");
};

/**
 typesafe validator
*/
	vWString JDFAutoIDPJobSheet::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidSheetFormat(level)) {
			vAtts.push_back(atr_SheetFormat);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetOccurence(level)) {
			vAtts.push_back(atr_SheetOccurence);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetType(level)) {
			vAtts.push_back(atr_SheetType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute SheetFormat
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoIDPJobSheet::SetSheetFormat(const WString& value){
	SetAttribute(atr_SheetFormat,value);
};
/**
* Get string attribute SheetFormat
* @return WString the vaue of the attribute ; defaults to Standard
*/
	 WString JDFAutoIDPJobSheet::GetSheetFormat() const {
	return GetAttribute(atr_SheetFormat,WString::emptyStr,L"Standard");
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPJobSheet::ValidSheetFormat(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetFormat,AttributeType_NMTOKEN,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPJobSheet::SheetOccurenceString(){
		static const WString enums=WString(L"Unknown,Always,End,OnError,Slip,Start,Both,None");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPJobSheet::SheetOccurenceString(EnumSheetOccurence value){
		return SheetOccurenceString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPJobSheet::SetSheetOccurence( EnumSheetOccurence value){
	SetEnumAttribute(atr_SheetOccurence,value,SheetOccurenceString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPJobSheet::EnumSheetOccurence JDFAutoIDPJobSheet:: GetSheetOccurence() const {
	return (EnumSheetOccurence) GetEnumAttribute(atr_SheetOccurence,SheetOccurenceString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPJobSheet::ValidSheetOccurence(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetOccurence,SheetOccurenceString(),false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoIDPJobSheet::SheetTypeString(){
		static const WString enums=WString(L"Unknown,AccountingSheet,ErrorSheet,JobSheet,SeparatorSheet");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoIDPJobSheet::SheetTypeString(EnumSheetType value){
		return SheetTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoIDPJobSheet::SetSheetType( EnumSheetType value){
	SetEnumAttribute(atr_SheetType,value,SheetTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoIDPJobSheet::EnumSheetType JDFAutoIDPJobSheet:: GetSheetType() const {
	return (EnumSheetType) GetEnumAttribute(atr_SheetType,SheetTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoIDPJobSheet::ValidSheetType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_SheetType,SheetTypeString(),false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFIDPFinishing JDFAutoIDPJobSheet::GetIDPFinishing(int iSkip)const{
	JDFIDPFinishing e=GetElement(elm_IDPFinishing,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFinishing JDFAutoIDPJobSheet::GetCreateIDPFinishing(int iSkip){
	JDFIDPFinishing e=GetCreateElement(elm_IDPFinishing,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPFinishing JDFAutoIDPJobSheet::AppendIDPFinishing(){
	JDFIDPFinishing e=AppendElement(elm_IDPFinishing);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPJobSheet::GetIDPLayout(int iSkip)const{
	JDFIDPLayout e=GetElement(elm_IDPLayout,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPJobSheet::GetCreateIDPLayout(int iSkip){
	JDFIDPLayout e=GetCreateElement(elm_IDPLayout,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFIDPLayout JDFAutoIDPJobSheet::AppendIDPLayout(){
	JDFIDPLayout e=AppendElement(elm_IDPLayout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPJobSheet::GetMediaIntent(int iSkip)const{
	JDFMediaIntent e=GetElement(elm_MediaIntent,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPJobSheet::GetCreateMediaIntent(int iSkip){
	JDFMediaIntent e=GetCreateElement(elm_MediaIntent,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaIntent JDFAutoIDPJobSheet::AppendMediaIntent(){
	JDFMediaIntent e=AppendElement(elm_MediaIntent);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIDPJobSheet::RefMediaIntent(JDFMediaIntent& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPJobSheet::GetMediaSource(int iSkip)const{
	JDFMediaSource e=GetElement(elm_MediaSource,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPJobSheet::GetCreateMediaSource(int iSkip){
	JDFMediaSource e=GetCreateElement(elm_MediaSource,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFMediaSource JDFAutoIDPJobSheet::AppendMediaSource(){
	JDFMediaSource e=AppendElement(elm_MediaSource);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoIDPJobSheet::RefMediaSource(JDFMediaSource& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoIDPJobSheet::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_IDPFinishing);

		for(i=0;i<nElem;i++){
			if (!GetIDPFinishing(i).IsValid(level)) {
				vElem.AppendUnique(elm_IDPFinishing);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_IDPLayout);

		for(i=0;i<nElem;i++){
			if (!GetIDPLayout(i).IsValid(level)) {
				vElem.AppendUnique(elm_IDPLayout);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MediaIntent);

		for(i=0;i<nElem;i++){
			if (!GetMediaIntent(i).IsValid(level)) {
				vElem.AppendUnique(elm_MediaIntent);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_MediaSource);

		for(i=0;i<nElem;i++){
			if (!GetMediaSource(i).IsValid(level)) {
				vElem.AppendUnique(elm_MediaSource);
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
	WString JDFAutoIDPJobSheet::OptionalElements()const{
		return JDFElement::OptionalElements()+L",IDPFinishing,IDPLayout,MediaIntent,MediaSource";
	};
}; // end namespace JDF
