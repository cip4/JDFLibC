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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPDLCreationParams.h"
#include "jdf/wrapper/JDFPDFToPSConversionParams.h"
#include "jdf/wrapper/JDFPSToPDFConversionParams.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPDLCreationParams : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPDLCreationParams& JDFAutoPDLCreationParams::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPDLCreationParams: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPDLCreationParams::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPDLCreationParams::ValidNodeNames()const{
	return L"*:,PDLCreationParams";
};

bool JDFAutoPDLCreationParams::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPDLCreationParams::init(){
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
	WString JDFAutoPDLCreationParams::RequiredAttributes()const{
		return JDFResource::RequiredAttributes()+L",MimeType";
};

/**
 typesafe validator
*/
	vWString JDFAutoPDLCreationParams::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidMimeType(level)) {
			vAtts.push_back(atr_MimeType);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute MimeType
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoPDLCreationParams::SetMimeType(const WString& value){
	SetAttribute(atr_MimeType,value);
};
/**
* Get string attribute MimeType
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoPDLCreationParams::GetMimeType() const {
	return GetAttribute(atr_MimeType,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoPDLCreationParams::ValidMimeType(EnumValidationLevel level) const {
		return ValidAttribute(atr_MimeType,AttributeType_string,RequiredLevel(level));
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPDFToPSConversionParams JDFAutoPDLCreationParams::GetPDFToPSConversionParams()const{
	JDFPDFToPSConversionParams e=GetElement(elm_PDFToPSConversionParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFToPSConversionParams JDFAutoPDLCreationParams::GetCreatePDFToPSConversionParams(){
	JDFPDFToPSConversionParams e=GetCreateElement(elm_PDFToPSConversionParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPDFToPSConversionParams JDFAutoPDLCreationParams::AppendPDFToPSConversionParams(){
	JDFPDFToPSConversionParams e=AppendElementN(elm_PDFToPSConversionParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPDLCreationParams::RefPDFToPSConversionParams(JDFPDFToPSConversionParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

JDFPSToPDFConversionParams JDFAutoPDLCreationParams::GetPSToPDFConversionParams()const{
	JDFPSToPDFConversionParams e=GetElement(elm_PSToPDFConversionParams);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPSToPDFConversionParams JDFAutoPDLCreationParams::GetCreatePSToPDFConversionParams(){
	JDFPSToPDFConversionParams e=GetCreateElement(elm_PSToPDFConversionParams);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPSToPDFConversionParams JDFAutoPDLCreationParams::AppendPSToPDFConversionParams(){
	JDFPSToPDFConversionParams e=AppendElementN(elm_PSToPDFConversionParams,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoPDLCreationParams::RefPSToPDFConversionParams(JDFPSToPDFConversionParams& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPDLCreationParams::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_PDFToPSConversionParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PDFToPSConversionParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPDFToPSConversionParams().IsValid(level)) {
				vElem.AppendUnique(elm_PDFToPSConversionParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PSToPDFConversionParams);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PSToPDFConversionParams);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPSToPDFConversionParams().IsValid(level)) {
				vElem.AppendUnique(elm_PSToPDFConversionParams);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPDLCreationParams::UniqueElements()const{
		return JDFResource::UniqueElements()+L",PDFToPSConversionParams,PSToPDFConversionParams";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPDLCreationParams::OptionalElements()const{
		return JDFResource::OptionalElements()+L",PDFToPSConversionParams,PSToPDFConversionParams";
	};
}; // end namespace JDF
