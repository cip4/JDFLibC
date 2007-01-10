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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCutMark.h"
#include "jdf/wrapper/JDFAssembly.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCutMark : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCutMark& JDFAutoCutMark::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCutMark: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCutMark::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCutMark::ValidNodeNames()const{
	return L"*:,CutMark";
};

bool JDFAutoCutMark::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoCutMark::init(){
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
	WString JDFAutoCutMark::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",MarkType,Position";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCutMark::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Blocks");
};

/**
 typesafe validator
*/
	vWString JDFAutoCutMark::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMarkType(level)) {
			vAtts.push_back(atr_MarkType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidPosition(level)) {
			vAtts.push_back(atr_Position);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidBlocks(level)) {
			vAtts.push_back(atr_Blocks);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCutMark::MarkTypeString(){
		static const WString enums=WString(L"Unknown,CrossCutMark,TopVerticalCutMark,BottomVerticalCutMark,LeftHorizontalCutMark,RightHorizontalCutMark,LowerLeftCutMark,UpperLeftCutMark,LowerRightCutMark,UpperRightCutMark");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCutMark::MarkTypeString(EnumMarkType value){
		return MarkTypeString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCutMark::SetMarkType( EnumMarkType value){
	SetEnumAttribute(atr_MarkType,value,MarkTypeString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCutMark::EnumMarkType JDFAutoCutMark:: GetMarkType() const {
	return (EnumMarkType) GetEnumAttribute(atr_MarkType,MarkTypeString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutMark::ValidMarkType(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MarkType,MarkTypeString(),RequiredLevel(level));
	};
/**
* Set attribute Position
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCutMark::SetPosition(const JDFXYPair& value){
	SetAttribute(atr_Position,value);
};
/**
* Get string attribute Position
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCutMark::GetPosition() const {
	return GetAttribute(atr_Position,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutMark::ValidPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_Position,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute Blocks
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoCutMark::SetBlocks(const vWString& value){
	SetAttribute(atr_Blocks,value);
};
/**
* Get string attribute Blocks
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoCutMark::GetBlocks() const {
	return GetAttribute(atr_Blocks,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCutMark::ValidBlocks(EnumValidationLevel level) const {
		return ValidAttribute(atr_Blocks,AttributeType_NMTOKENS,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFAssembly JDFAutoCutMark::GetAssembly(int iSkip)const{
	JDFAssembly e=GetElement(elm_Assembly,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAssembly JDFAutoCutMark::GetCreateAssembly(int iSkip){
	JDFAssembly e=GetCreateElement(elm_Assembly,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFAssembly JDFAutoCutMark::AppendAssembly(){
	JDFAssembly e=AppendElement(elm_Assembly);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCutMark::RefAssembly(JDFAssembly& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCutMark::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Assembly);

		for(i=0;i<nElem;i++){
			if (!GetAssembly(i).IsValid(level)) {
				vElem.AppendUnique(elm_Assembly);
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
	WString JDFAutoCutMark::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Assembly";
	};
}; // end namespace JDF
