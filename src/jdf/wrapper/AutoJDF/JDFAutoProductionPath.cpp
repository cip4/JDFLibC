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

 
#include "jdf/wrapper/AutoJDF/JDFAutoProductionPath.h"
#include "jdf/wrapper/JDFProductionSubPath.h"
#include "jdf/wrapper/JDFProductionSubPath.h"
#include "jdf/wrapper/JDFProductionSubPath.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoProductionPath : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoProductionPath& JDFAutoProductionPath::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoProductionPath: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoProductionPath::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoProductionPath::ValidNodeNames()const{
	return L"*:,ProductionPath";
};

bool JDFAutoProductionPath::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoProductionPath::init(){
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
	WString JDFAutoProductionPath::OptionalAttributes()const{
		return JDFResource::OptionalAttributes()+WString(L",ProductionPathID");
};

/**
 typesafe validator
*/
	vWString JDFAutoProductionPath::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidProductionPathID(level)) {
			vAtts.push_back(atr_ProductionPathID);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute ProductionPathID
*@param WString value: the value to set the attribute to
*/
	 void JDFAutoProductionPath::SetProductionPathID(const WString& value){
	SetAttribute(atr_ProductionPathID,value);
};
/**
* Get string attribute ProductionPathID
* @return WString the vaue of the attribute 
*/
	 WString JDFAutoProductionPath::GetProductionPathID() const {
	return GetAttribute(atr_ProductionPathID,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoProductionPath::ValidProductionPathID(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProductionPathID,AttributeType_string,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFProductionSubPath JDFAutoProductionPath::GetFolderSuperstructureWebPath()const{
	JDFProductionSubPath e=GetElement(elm_FolderSuperstructureWebPath);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFProductionSubPath JDFAutoProductionPath::GetCreateFolderSuperstructureWebPath(){
	JDFProductionSubPath e=GetCreateElement(elm_FolderSuperstructureWebPath);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFProductionSubPath JDFAutoProductionPath::AppendFolderSuperstructureWebPath(){
	JDFProductionSubPath e=AppendElementN(elm_FolderSuperstructureWebPath,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFProductionSubPath JDFAutoProductionPath::GetPostPressComponentPath(int iSkip)const{
	JDFProductionSubPath e=GetElement(elm_PostPressComponentPath,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFProductionSubPath JDFAutoProductionPath::GetCreatePostPressComponentPath(int iSkip){
	JDFProductionSubPath e=GetCreateElement(elm_PostPressComponentPath,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFProductionSubPath JDFAutoProductionPath::AppendPostPressComponentPath(){
	JDFProductionSubPath e=AppendElement(elm_PostPressComponentPath);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFProductionSubPath JDFAutoProductionPath::GetPrintingUnitWebPath(int iSkip)const{
	JDFProductionSubPath e=GetElement(elm_PrintingUnitWebPath,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFProductionSubPath JDFAutoProductionPath::GetCreatePrintingUnitWebPath(int iSkip){
	JDFProductionSubPath e=GetCreateElement(elm_PrintingUnitWebPath,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFProductionSubPath JDFAutoProductionPath::AppendPrintingUnitWebPath(){
	JDFProductionSubPath e=AppendElement(elm_PrintingUnitWebPath);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoProductionPath::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_FolderSuperstructureWebPath);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FolderSuperstructureWebPath);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFolderSuperstructureWebPath().IsValid(level)) {
				vElem.AppendUnique(elm_FolderSuperstructureWebPath);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PostPressComponentPath);

		for(i=0;i<nElem;i++){
			if (!GetPostPressComponentPath(i).IsValid(level)) {
				vElem.AppendUnique(elm_PostPressComponentPath);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PrintingUnitWebPath);

		for(i=0;i<nElem;i++){
			if (!GetPrintingUnitWebPath(i).IsValid(level)) {
				vElem.AppendUnique(elm_PrintingUnitWebPath);
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
	WString JDFAutoProductionPath::UniqueElements()const{
		return JDFResource::UniqueElements()+L",FolderSuperstructureWebPath";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoProductionPath::OptionalElements()const{
		return JDFResource::OptionalElements()+L",FolderSuperstructureWebPath,PostPressComponentPath,PrintingUnitWebPath";
	};
}; // end namespace JDF
