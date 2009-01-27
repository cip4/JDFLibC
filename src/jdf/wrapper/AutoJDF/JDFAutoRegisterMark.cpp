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

 
#include "jdf/wrapper/AutoJDF/JDFAutoRegisterMark.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoRegisterMark : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoRegisterMark& JDFAutoRegisterMark::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoRegisterMark: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoRegisterMark::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoRegisterMark::ValidNodeNames()const{
	return L"*:,RegisterMark";
};

bool JDFAutoRegisterMark::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoRegisterMark::init(){
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
	WString JDFAutoRegisterMark::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Center";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoRegisterMark::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",MarkType,MarkUsage,Rotation");
};

/**
 typesafe validator
*/
	vWString JDFAutoRegisterMark::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCenter(level)) {
			vAtts.push_back(atr_Center);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkType(level)) {
			vAtts.push_back(atr_MarkType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidMarkUsage(level)) {
			vAtts.push_back(atr_MarkUsage);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRotation(level)) {
			vAtts.push_back(atr_Rotation);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Center
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoRegisterMark::SetCenter(const JDFXYPair& value){
	SetAttribute(atr_Center,value);
};
/**
* Get string attribute Center
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoRegisterMark::GetCenter() const {
	return GetAttribute(atr_Center,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterMark::ValidCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Center,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute MarkType
*@param vWString value: the value to set the attribute to
*/
	 void JDFAutoRegisterMark::SetMarkType(const vWString& value){
	SetAttribute(atr_MarkType,value);
};
/**
* Get string attribute MarkType
* @return vWString the vaue of the attribute 
*/
	 vWString JDFAutoRegisterMark::GetMarkType() const {
	return GetAttribute(atr_MarkType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterMark::ValidMarkType(EnumValidationLevel level) const {
		return ValidAttribute(atr_MarkType,AttributeType_NMTOKENS,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoRegisterMark::MarkUsageString(){
		static const WString enums=WString(L"Unknown,Color,PaperPath,Tile");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoRegisterMark::MarkUsageString(EnumMarkUsage value){
		return MarkUsageString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoRegisterMark::SetMarkUsage( EnumMarkUsage value){
	SetEnumAttribute(atr_MarkUsage,value,MarkUsageString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoRegisterMark::EnumMarkUsage JDFAutoRegisterMark:: GetMarkUsage() const {
	return (EnumMarkUsage) GetEnumAttribute(atr_MarkUsage,MarkUsageString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterMark::ValidMarkUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MarkUsage,MarkUsageString(),false);
	};
/**
* Set attribute Rotation
*@param double value: the value to set the attribute to
*/
	 void JDFAutoRegisterMark::SetRotation(double value){
	SetAttribute(atr_Rotation,WString::valueOf(value));
};
/**
* Get double attribute Rotation
* @return double the vaue of the attribute 
*/
	 double JDFAutoRegisterMark::GetRotation() const {
	return GetRealAttribute(atr_Rotation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoRegisterMark::ValidRotation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Rotation,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSeparationSpec JDFAutoRegisterMark::GetSeparationSpec(int iSkip)const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoRegisterMark::GetCreateSeparationSpec(int iSkip){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoRegisterMark::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoRegisterMark::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_SeparationSpec);

		for(i=0;i<nElem;i++){
			if (!GetSeparationSpec(i).IsValid(level)) {
				vElem.AppendUnique(elm_SeparationSpec);
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
	WString JDFAutoRegisterMark::OptionalElements()const{
		return JDFResource::OptionalElements()+L",SeparationSpec";
	};
}; // end namespace JDF
