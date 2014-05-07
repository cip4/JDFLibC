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

 
#include "jdf/wrapper/AutoJDF/JDFAutoCylinderLayout.h"
#include "jdf/wrapper/JDFLayout.h"
#include "jdf/wrapper/JDFCylinderPosition.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoCylinderLayout : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoCylinderLayout& JDFAutoCylinderLayout::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoCylinderLayout: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoCylinderLayout::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoCylinderLayout::ValidNodeNames()const{
	return L"*:,CylinderLayout";
};

bool JDFAutoCylinderLayout::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoCylinderLayout::init(){
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
	WString JDFAutoCylinderLayout::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",DeviceID");
};

/**
 typesafe validator
*/
	vWString JDFAutoCylinderLayout::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidDeviceID(level)) {
			vAtts.push_back(atr_DeviceID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoCylinderLayout::SetDeviceID(const WString& value){
	SetAttribute(atr_DeviceID,value);
};
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoCylinderLayout::GetDeviceID() const {
	return GetAttribute(atr_DeviceID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoCylinderLayout::ValidDeviceID(EnumValidationLevel level) const {
		return ValidAttribute(atr_DeviceID,AttributeType_NMTOKEN,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFLayout JDFAutoCylinderLayout::GetLayout()const{
	JDFLayout e=GetElement(elm_Layout);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoCylinderLayout::GetCreateLayout(){
	JDFLayout e=GetCreateElement(elm_Layout);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFLayout JDFAutoCylinderLayout::AppendLayout(){
	JDFLayout e=AppendElementN(elm_Layout,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoCylinderLayout::RefLayout(JDFLayout& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFCylinderPosition JDFAutoCylinderLayout::GetCylinderPosition(int iSkip)const{
	JDFCylinderPosition e=GetElement(elm_CylinderPosition,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCylinderPosition JDFAutoCylinderLayout::GetCreateCylinderPosition(int iSkip){
	JDFCylinderPosition e=GetCreateElement(elm_CylinderPosition,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFCylinderPosition JDFAutoCylinderLayout::AppendCylinderPosition(){
	JDFCylinderPosition e=AppendElement(elm_CylinderPosition);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoCylinderLayout::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Layout);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Layout);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetLayout().IsValid(level)) {
				vElem.AppendUnique(elm_Layout);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_CylinderPosition);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_CylinderPosition);
			if (++n>=nMax)
			return vElem;
		}

		for(i=0;i<nElem;i++){
			if (!GetCylinderPosition(i).IsValid(level)) {
				vElem.AppendUnique(elm_CylinderPosition);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoCylinderLayout::UniqueElements()const{
		return JDFResource::UniqueElements()+L",Layout";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoCylinderLayout::RequiredElements()const{
		return JDFResource::RequiredElements()+L",CylinderPosition";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoCylinderLayout::OptionalElements()const{
		return JDFResource::OptionalElements()+L",Layout";
	};
}; // end namespace JDF
