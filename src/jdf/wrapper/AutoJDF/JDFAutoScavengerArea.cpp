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

 
#include "jdf/wrapper/AutoJDF/JDFAutoScavengerArea.h"
#include "jdf/wrapper/JDFSeparationSpec.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoScavengerArea : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoScavengerArea& JDFAutoScavengerArea::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoScavengerArea: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoScavengerArea::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoScavengerArea::ValidNodeNames()const{
	return L"*:,ScavengerArea";
};

bool JDFAutoScavengerArea::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoScavengerArea::init(){
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
	WString JDFAutoScavengerArea::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",Center,Size";
};

/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoScavengerArea::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",Rotation");
};

/**
 typesafe validator
*/
	vWString JDFAutoScavengerArea::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidCenter(level)) {
			vAtts.push_back(atr_Center);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidSize(level)) {
			vAtts.push_back(atr_Size);
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
	 void JDFAutoScavengerArea::SetCenter(const JDFXYPair& value){
	SetAttribute(atr_Center,value);
};
/**
* Get string attribute Center
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoScavengerArea::GetCenter() const {
	return GetAttribute(atr_Center,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScavengerArea::ValidCenter(EnumValidationLevel level) const {
		return ValidAttribute(atr_Center,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute Size
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoScavengerArea::SetSize(const JDFXYPair& value){
	SetAttribute(atr_Size,value);
};
/**
* Get string attribute Size
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoScavengerArea::GetSize() const {
	return GetAttribute(atr_Size,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScavengerArea::ValidSize(EnumValidationLevel level) const {
		return ValidAttribute(atr_Size,AttributeType_XYPair,RequiredLevel(level));
	};
/**
* Set attribute Rotation
*@param double value: the value to set the attribute to
*/
	 void JDFAutoScavengerArea::SetRotation(double value){
	SetAttribute(atr_Rotation,WString::valueOf(value));
};
/**
* Get double attribute Rotation
* @return double the vaue of the attribute 
*/
	 double JDFAutoScavengerArea::GetRotation() const {
	return GetRealAttribute(atr_Rotation,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoScavengerArea::ValidRotation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Rotation,AttributeType_double,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSeparationSpec JDFAutoScavengerArea::GetSeparationSpec(int iSkip)const{
	JDFSeparationSpec e=GetElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoScavengerArea::GetCreateSeparationSpec(int iSkip){
	JDFSeparationSpec e=GetCreateElement(elm_SeparationSpec,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSeparationSpec JDFAutoScavengerArea::AppendSeparationSpec(){
	JDFSeparationSpec e=AppendElement(elm_SeparationSpec);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoScavengerArea::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
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
	WString JDFAutoScavengerArea::OptionalElements()const{
		return JDFResource::OptionalElements()+L",SeparationSpec";
	};
}; // end namespace JDF
