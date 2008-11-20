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

 
#include "jdf/wrapper/AutoJDF/JDFAutoBundle.h"
#include "jdf/wrapper/JDFBundleItem.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoBundle : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoBundle& JDFAutoBundle::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoBundle: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoBundle::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoBundle::ValidNodeNames()const{
	return L"*:,Bundle";
};

bool JDFAutoBundle::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Quantity;
};

bool JDFAutoBundle::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Quantity);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoBundle::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BundleType,FolioCount,ReaderPageCount,TotalAmount");
};

/**
 typesafe validator
*/
	vWString JDFAutoBundle::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBundleType(level)) {
			vAtts.push_back(atr_BundleType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFolioCount(level)) {
			vAtts.push_back(atr_FolioCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidReaderPageCount(level)) {
			vAtts.push_back(atr_ReaderPageCount);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTotalAmount(level)) {
			vAtts.push_back(atr_TotalAmount);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoBundle::BundleTypeString(){
		static const WString enums=WString(L"Unknown,BoundSet,Box,Carton,CollectedStack,CompensatedStack,Pallet,Roll,Sheet,Stack")
	+WString(L",StrappedStack,StrappedCompensatedStack,WrappedBundle");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoBundle::BundleTypeString(EnumBundleType value){
		return BundleTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoBundle::SetBundleType( EnumBundleType value){
	SetEnumAttribute(atr_BundleType,value,BundleTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoBundle::EnumBundleType JDFAutoBundle:: GetBundleType() const {
	return (EnumBundleType) GetEnumAttribute(atr_BundleType,BundleTypeString(),WString::emptyStr,BundleType_Stack);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBundle::ValidBundleType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_BundleType,BundleTypeString(),false);
	};
/**
* Set attribute FolioCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBundle::SetFolioCount(int value){
	SetAttribute(atr_FolioCount,WString::valueOf(value));
};
/**
* Get integer attribute FolioCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoBundle::GetFolioCount() const {
	return GetIntAttribute(atr_FolioCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBundle::ValidFolioCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_FolioCount,AttributeType_integer,false);
	};
/**
* Set attribute ReaderPageCount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBundle::SetReaderPageCount(int value){
	SetAttribute(atr_ReaderPageCount,WString::valueOf(value));
};
/**
* Get integer attribute ReaderPageCount
* @return int the vaue of the attribute 
*/
	 int JDFAutoBundle::GetReaderPageCount() const {
	return GetIntAttribute(atr_ReaderPageCount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBundle::ValidReaderPageCount(EnumValidationLevel level) const {
		return ValidAttribute(atr_ReaderPageCount,AttributeType_integer,false);
	};
/**
* Set attribute TotalAmount
*@param int value: the value to set the attribute to
*/
	 void JDFAutoBundle::SetTotalAmount(int value){
	SetAttribute(atr_TotalAmount,WString::valueOf(value));
};
/**
* Get integer attribute TotalAmount
* @return int the vaue of the attribute 
*/
	 int JDFAutoBundle::GetTotalAmount() const {
	return GetIntAttribute(atr_TotalAmount,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoBundle::ValidTotalAmount(EnumValidationLevel level) const {
		return ValidAttribute(atr_TotalAmount,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFBundleItem JDFAutoBundle::GetBundleItem(int iSkip)const{
	JDFBundleItem e=GetElement(elm_BundleItem,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBundleItem JDFAutoBundle::GetCreateBundleItem(int iSkip){
	JDFBundleItem e=GetCreateElement(elm_BundleItem,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFBundleItem JDFAutoBundle::AppendBundleItem(){
	JDFBundleItem e=AppendElement(elm_BundleItem);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoBundle::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_BundleItem);

		for(i=0;i<nElem;i++){
			if (!GetBundleItem(i).IsValid(level)) {
				vElem.AppendUnique(elm_BundleItem);
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
	WString JDFAutoBundle::OptionalElements()const{
		return JDFResource::OptionalElements()+L",BundleItem";
	};
}; // end namespace JDF
