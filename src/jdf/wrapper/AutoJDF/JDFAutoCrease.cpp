/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCrease.h"
#include "jdf/wrapper/JDFQualityControlResult.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCrease : public JDFElement

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCrease& JDFAutoCrease::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCrease: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCrease::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCrease::ValidNodeNames()const{
	return L"*:,Crease";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoCrease::OptionalAttributes()const{
		return JDFElement::OptionalAttributes()+WString(L",Depth,RelativeStartPosition,RelativeWorkingPath,StartPosition,WorkingPath,WorkingDirection,Travel,RelativeTravel");
};

/**
 typesafe validator
*/
	vWString JDFAutoCrease::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFElement::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDepth(level)) {
			vAtts.push_back(atr_Depth);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeStartPosition(level)) {
			vAtts.push_back(atr_RelativeStartPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeWorkingPath(level)) {
			vAtts.push_back(atr_RelativeWorkingPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidStartPosition(level)) {
			vAtts.push_back(atr_StartPosition);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkingPath(level)) {
			vAtts.push_back(atr_WorkingPath);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidWorkingDirection(level)) {
			vAtts.push_back(atr_WorkingDirection);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidTravel(level)) {
			vAtts.push_back(atr_Travel);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRelativeTravel(level)) {
			vAtts.push_back(atr_RelativeTravel);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Depth
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCrease::SetDepth(double value){
	SetAttribute(atr_Depth,WString::valueOf(value));
};
/**
* Get double attribute Depth
* @return double the vaue of the attribute 
*/
	 double JDFAutoCrease::GetDepth() const {
	return GetRealAttribute(atr_Depth,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCrease::ValidDepth(EnumValidationLevel level) const {
		return ValidAttribute(atr_Depth,AttributeType_double,false);
	};
/**
* Set attribute RelativeStartPosition
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCrease::SetRelativeStartPosition(const JDFXYPair& value){
	SetAttribute(atr_RelativeStartPosition,value);
};
/**
* Get string attribute RelativeStartPosition
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCrease::GetRelativeStartPosition() const {
	return GetAttribute(atr_RelativeStartPosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCrease::ValidRelativeStartPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeStartPosition,AttributeType_XYPair,false);
	};
/**
* Set attribute RelativeWorkingPath
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCrease::SetRelativeWorkingPath(const JDFXYPair& value){
	SetAttribute(atr_RelativeWorkingPath,value);
};
/**
* Get string attribute RelativeWorkingPath
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCrease::GetRelativeWorkingPath() const {
	return GetAttribute(atr_RelativeWorkingPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCrease::ValidRelativeWorkingPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeWorkingPath,AttributeType_XYPair,false);
	};
/**
* Set attribute StartPosition
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCrease::SetStartPosition(const JDFXYPair& value){
	SetAttribute(atr_StartPosition,value);
};
/**
* Get string attribute StartPosition
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCrease::GetStartPosition() const {
	return GetAttribute(atr_StartPosition,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCrease::ValidStartPosition(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartPosition,AttributeType_XYPair,false);
	};
/**
* Set attribute WorkingPath
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoCrease::SetWorkingPath(const JDFXYPair& value){
	SetAttribute(atr_WorkingPath,value);
};
/**
* Get string attribute WorkingPath
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoCrease::GetWorkingPath() const {
	return GetAttribute(atr_WorkingPath,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCrease::ValidWorkingPath(EnumValidationLevel level) const {
		return ValidAttribute(atr_WorkingPath,AttributeType_XYPair,false);
	};
///////////////////////////////////////////////////////////////////////

	const WString& JDFAutoCrease::WorkingDirectionString(){
		static const WString enums=WString(L"Unknown,Top,Bottom");
		return enums;
	};

///////////////////////////////////////////////////////////////////////

	WString JDFAutoCrease::WorkingDirectionString(EnumWorkingDirection value){
		return WorkingDirectionString().Token(value,WString::comma);
	};

/////////////////////////////////////////////////////////////////////////
	void JDFAutoCrease::SetWorkingDirection( EnumWorkingDirection value){
	SetEnumAttribute(atr_WorkingDirection,value,WorkingDirectionString());
};
/////////////////////////////////////////////////////////////////////////
	 JDFAutoCrease::EnumWorkingDirection JDFAutoCrease:: GetWorkingDirection() const {
	return (EnumWorkingDirection) GetEnumAttribute(atr_WorkingDirection,WorkingDirectionString(),WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCrease::ValidWorkingDirection(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_WorkingDirection,WorkingDirectionString(),false);
	};
/**
* Set attribute Travel
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCrease::SetTravel(double value){
	SetAttribute(atr_Travel,WString::valueOf(value));
};
/**
* Get double attribute Travel
* @return double the vaue of the attribute 
*/
	 double JDFAutoCrease::GetTravel() const {
	return GetRealAttribute(atr_Travel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCrease::ValidTravel(EnumValidationLevel level) const {
		return ValidAttribute(atr_Travel,AttributeType_double,false);
	};
/**
* Set attribute RelativeTravel
*@param double value: the value to set the attribute to
*/
	 void JDFAutoCrease::SetRelativeTravel(double value){
	SetAttribute(atr_RelativeTravel,WString::valueOf(value));
};
/**
* Get double attribute RelativeTravel
* @return double the vaue of the attribute 
*/
	 double JDFAutoCrease::GetRelativeTravel() const {
	return GetRealAttribute(atr_RelativeTravel,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCrease::ValidRelativeTravel(EnumValidationLevel level) const {
		return ValidAttribute(atr_RelativeTravel,AttributeType_Any,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFQualityControlResult JDFAutoCrease::GetQualityControlResult(int iSkip)const{
	JDFQualityControlResult e=GetElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoCrease::GetCreateQualityControlResult(int iSkip){
	JDFQualityControlResult e=GetCreateElement(elm_QualityControlResult,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFQualityControlResult JDFAutoCrease::AppendQualityControlResult(){
	JDFQualityControlResult e=AppendElement(elm_QualityControlResult);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCrease::RefQualityControlResult(JDFQualityControlResult& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCrease::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_QualityControlResult);

		for(i=0;i<nElem;i++){
			if (!GetQualityControlResult(i).IsValid(level)) {
				vElem.AppendUnique(elm_QualityControlResult);
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
	WString JDFAutoCrease::OptionalElements()const{
		return JDFElement::OptionalElements()+L",QualityControlResult";
	};
}; // end namespace JDF
