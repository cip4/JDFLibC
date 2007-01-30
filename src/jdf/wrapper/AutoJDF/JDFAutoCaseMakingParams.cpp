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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCaseMakingParams.h"
#include "jdf/wrapper/JDFGlueLine.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCaseMakingParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCaseMakingParams& JDFAutoCaseMakingParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCaseMakingParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCaseMakingParams::ValidNodeNames()const{
	return L"*:,CaseMakingParams";
};

bool JDFAutoCaseMakingParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoCaseMakingParams::init(){
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
	WString JDFAutoCaseMakingParams::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",BottomFoldIn,CoverWidth,CornerType,FrontFoldIn,TopFoldIn,Height,JointWidth,SpineWidth");
};

/**
 typesafe validator
*/
	vWString JDFAutoCaseMakingParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidBottomFoldIn(level)) {
			vAtts.push_back(atr_BottomFoldIn);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCoverWidth(level)) {
			vAtts.push_back(atr_CoverWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidCornerType(level)) {
			vAtts.push_back(atr_CornerType);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidFrontFoldIn(level)) {
			vAtts.push_back(atr_FrontFoldIn);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTopFoldIn(level)) {
			vAtts.push_back(atr_TopFoldIn);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidHeight(level)) {
			vAtts.push_back(atr_Height);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidJointWidth(level)) {
			vAtts.push_back(atr_JointWidth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSpineWidth(level)) {
			vAtts.push_back(atr_SpineWidth);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute BottomFoldIn
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCaseMakingParams::SetBottomFoldIn(double value){
	SetAttribute(atr_BottomFoldIn,WString::valueOf(value));
};
/**
* Get double attribute BottomFoldIn
* @return double the vaue of the attribute 
*/
	 double JDFAutoCaseMakingParams::GetBottomFoldIn() const {
	return GetRealAttribute(atr_BottomFoldIn,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::ValidBottomFoldIn(EnumValidationLevel level) const {
		return ValidAttribute(atr_BottomFoldIn,AttributeType_double,false);
	};
/**
* Set attribute CoverWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCaseMakingParams::SetCoverWidth(double value){
	SetAttribute(atr_CoverWidth,WString::valueOf(value));
};
/**
* Get double attribute CoverWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoCaseMakingParams::GetCoverWidth() const {
	return GetRealAttribute(atr_CoverWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::ValidCoverWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_CoverWidth,AttributeType_double,false);
	};
/**
* Set attribute CornerType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCaseMakingParams::SetCornerType(const WString& value){
	SetAttribute(atr_CornerType,value);
};
/**
* Get string attribute CornerType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCaseMakingParams::GetCornerType() const {
	return GetAttribute(atr_CornerType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::ValidCornerType(EnumValidationLevel level) const {
		return ValidAttribute(atr_CornerType,AttributeType_NMTOKEN,false);
	};
/**
* Set attribute FrontFoldIn
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCaseMakingParams::SetFrontFoldIn(double value){
	SetAttribute(atr_FrontFoldIn,WString::valueOf(value));
};
/**
* Get double attribute FrontFoldIn
* @return double the vaue of the attribute 
*/
	 double JDFAutoCaseMakingParams::GetFrontFoldIn() const {
	return GetRealAttribute(atr_FrontFoldIn,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::ValidFrontFoldIn(EnumValidationLevel level) const {
		return ValidAttribute(atr_FrontFoldIn,AttributeType_double,false);
	};
/**
* Set attribute TopFoldIn
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCaseMakingParams::SetTopFoldIn(double value){
	SetAttribute(atr_TopFoldIn,WString::valueOf(value));
};
/**
* Get double attribute TopFoldIn
* @return double the vaue of the attribute 
*/
	 double JDFAutoCaseMakingParams::GetTopFoldIn() const {
	return GetRealAttribute(atr_TopFoldIn,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::ValidTopFoldIn(EnumValidationLevel level) const {
		return ValidAttribute(atr_TopFoldIn,AttributeType_double,false);
	};
/**
* Set attribute Height
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCaseMakingParams::SetHeight(double value){
	SetAttribute(atr_Height,WString::valueOf(value));
};
/**
* Get double attribute Height
* @return double the vaue of the attribute 
*/
	 double JDFAutoCaseMakingParams::GetHeight() const {
	return GetRealAttribute(atr_Height,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::ValidHeight(EnumValidationLevel level) const {
		return ValidAttribute(atr_Height,AttributeType_double,false);
	};
/**
* Set attribute JointWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCaseMakingParams::SetJointWidth(double value){
	SetAttribute(atr_JointWidth,WString::valueOf(value));
};
/**
* Get double attribute JointWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoCaseMakingParams::GetJointWidth() const {
	return GetRealAttribute(atr_JointWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::ValidJointWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_JointWidth,AttributeType_double,false);
	};
/**
* Set attribute SpineWidth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCaseMakingParams::SetSpineWidth(double value){
	SetAttribute(atr_SpineWidth,WString::valueOf(value));
};
/**
* Get double attribute SpineWidth
* @return double the vaue of the attribute 
*/
	 double JDFAutoCaseMakingParams::GetSpineWidth() const {
	return GetRealAttribute(atr_SpineWidth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCaseMakingParams::ValidSpineWidth(EnumValidationLevel level) const {
		return ValidAttribute(atr_SpineWidth,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFGlueLine JDFAutoCaseMakingParams::GetGlueLine()const{
	JDFGlueLine e=GetElement(elm_GlueLine);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoCaseMakingParams::GetCreateGlueLine(){
	JDFGlueLine e=GetCreateElement(elm_GlueLine);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFGlueLine JDFAutoCaseMakingParams::AppendGlueLine(){
	JDFGlueLine e=AppendElementN(elm_GlueLine,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCaseMakingParams::RefGlueLine(JDFGlueLine& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCaseMakingParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_GlueLine);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_GlueLine);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetGlueLine().IsValid(level)) {
				vElem.AppendUnique(elm_GlueLine);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoCaseMakingParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",GlueLine";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoCaseMakingParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",GlueLine";
	};
}; // end namespace JDF
