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

 
#include "jdf/wrapper/AutoJDF/JDFAutoInsertingParams.h"
#include "jdf/wrapper/JDFGlueLine.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoInsertingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoInsertingParams& JDFAutoInsertingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoInsertingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoInsertingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoInsertingParams::ValidNodeNames()const{
	return L"*:,InsertingParams";
};

bool JDFAutoInsertingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoInsertingParams::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of required attributes in the JDF namespace
*/
	WString JDFAutoInsertingParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",InsertLocation";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoInsertingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Method,SheetOffset,FinishedPage");
};

/**
 typesafe validator
*/
	vWString JDFAutoInsertingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidInsertLocation(level)) {
			vAtts.push_back(atr_InsertLocation);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMethod(level)) {
			vAtts.push_back(atr_Method);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSheetOffset(level)) {
			vAtts.push_back(atr_SheetOffset);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFinishedPage(level)) {
			vAtts.push_back(atr_FinishedPage);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInsertingParams::InsertLocationString(){
		static const WString enums=WString(L"Unknown,Front,Back,OverfoldLeft,OverfoldRight,Overfold,FinishedPage");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInsertingParams::InsertLocationString(EnumInsertLocation value){
		return InsertLocationString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInsertingParams::SetInsertLocation( EnumInsertLocation value){
	SetEnumAttribute(atr_InsertLocation,value,InsertLocationString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInsertingParams::EnumInsertLocation JDFAutoInsertingParams:: GetInsertLocation() const {
	return (EnumInsertLocation) GetEnumAttribute(atr_InsertLocation,InsertLocationString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertingParams::ValidInsertLocation(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_InsertLocation,InsertLocationString(),RequiredLevel(level));
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoInsertingParams::MethodString(){
		static const WString enums=WString(L"Unknown,BlowIn,BindIn");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoInsertingParams::MethodString(EnumMethod value){
		return MethodString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoInsertingParams::SetMethod( EnumMethod value){
	SetEnumAttribute(atr_Method,value,MethodString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoInsertingParams::EnumMethod JDFAutoInsertingParams:: GetMethod() const {
	return (EnumMethod) GetEnumAttribute(atr_Method,MethodString(),WString::emptyStr,Method_BlowIn);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertingParams::ValidMethod(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Method,MethodString(),false);
	};
/**
* Set attribute SheetOffset
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoInsertingParams::SetSheetOffset(const JDFXYPair& value){
	SetAttribute(atr_SheetOffset,value);
};
/**
* Get string attribute SheetOffset
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoInsertingParams::GetSheetOffset() const {
	return GetAttribute(atr_SheetOffset,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertingParams::ValidSheetOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_SheetOffset,AttributeType_XYPair,false);
	};
/**
* Set attribute FinishedPage
*@param int value: the value to set the attribute to
*/
	 void JDFAutoInsertingParams::SetFinishedPage(int value){
	SetAttribute(atr_FinishedPage,WString::valueOf(value));
};
/**
* Get integer attribute FinishedPage
* @return int the vaue of the attribute 
*/
	 int JDFAutoInsertingParams::GetFinishedPage() const {
	return GetIntAttribute(atr_FinishedPage,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoInsertingParams::ValidFinishedPage(EnumValidationLevel level) const {
		return ValidAttribute(atr_FinishedPage,AttributeType_integer,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFGlueLine JDFAutoInsertingParams::GetGlueLine(int iSkip)const{
	JDFGlueLine e=GetElement(elm_GlueLine,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoInsertingParams::GetCreateGlueLine(int iSkip){
	JDFGlueLine e=GetCreateElement(elm_GlueLine,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoInsertingParams::AppendGlueLine(){
	JDFGlueLine e=AppendElement(elm_GlueLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoInsertingParams::RefGlueLine(JDFGlueLine& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoInsertingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_GlueLine);

		for(i=0;i<nElem;i++){
			if (!GetGlueLine(i).IsValid(level)) {
				vElem.AppendUnique(elm_GlueLine);
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
	WString JDFAutoInsertingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",GlueLine";
	};
}; // end namespace JDF
