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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreflightAnalysis.h"
#include "jdf/wrapper/JDFPreflightResultsPool.h"
#include "jdf/wrapper/JDFPreflightResultsPool.h"
#include "jdf/wrapper/JDFPreflightResultsPool.h"
#include "jdf/wrapper/JDFPreflightResultsPool.h"
#include "jdf/wrapper/JDFPreflightResultsPool.h"
#include "jdf/wrapper/JDFPreflightResultsPool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreflightAnalysis : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreflightAnalysis& JDFAutoPreflightAnalysis::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreflightAnalysis: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreflightAnalysis::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreflightAnalysis::ValidNodeNames()const{
	return L"*:,PreflightAnalysis";
};

bool JDFAutoPreflightAnalysis::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPreflightAnalysis::init(){
	bool bRet=JDFResource::init();
	SetClass(Class_Parameter);
	return bRet;
};

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoPreflightAnalysis::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetColorsResultsPool()const{
	JDFPreflightResultsPool e=GetElement(elm_ColorsResultsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetCreateColorsResultsPool(){
	JDFPreflightResultsPool e=GetCreateElement(elm_ColorsResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::AppendColorsResultsPool(){
	JDFPreflightResultsPool e=AppendElementN(elm_ColorsResultsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetDocumentResultsPool()const{
	JDFPreflightResultsPool e=GetElement(elm_DocumentResultsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetCreateDocumentResultsPool(){
	JDFPreflightResultsPool e=GetCreateElement(elm_DocumentResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::AppendDocumentResultsPool(){
	JDFPreflightResultsPool e=AppendElementN(elm_DocumentResultsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetFontsResultsPool()const{
	JDFPreflightResultsPool e=GetElement(elm_FontsResultsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetCreateFontsResultsPool(){
	JDFPreflightResultsPool e=GetCreateElement(elm_FontsResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::AppendFontsResultsPool(){
	JDFPreflightResultsPool e=AppendElementN(elm_FontsResultsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetFileTypeResultsPool()const{
	JDFPreflightResultsPool e=GetElement(elm_FileTypeResultsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetCreateFileTypeResultsPool(){
	JDFPreflightResultsPool e=GetCreateElement(elm_FileTypeResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::AppendFileTypeResultsPool(){
	JDFPreflightResultsPool e=AppendElementN(elm_FileTypeResultsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetImagesResultsPool()const{
	JDFPreflightResultsPool e=GetElement(elm_ImagesResultsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetCreateImagesResultsPool(){
	JDFPreflightResultsPool e=GetCreateElement(elm_ImagesResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::AppendImagesResultsPool(){
	JDFPreflightResultsPool e=AppendElementN(elm_ImagesResultsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetPagesResultsPool()const{
	JDFPreflightResultsPool e=GetElement(elm_PagesResultsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::GetCreatePagesResultsPool(){
	JDFPreflightResultsPool e=GetCreateElement(elm_PagesResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightResultsPool JDFAutoPreflightAnalysis::AppendPagesResultsPool(){
	JDFPreflightResultsPool e=AppendElementN(elm_PagesResultsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreflightAnalysis::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorsResultsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorsResultsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorsResultsPool().IsValid(level)) {
				vElem.AppendUnique(elm_ColorsResultsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_DocumentResultsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DocumentResultsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDocumentResultsPool().IsValid(level)) {
				vElem.AppendUnique(elm_DocumentResultsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FontsResultsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FontsResultsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFontsResultsPool().IsValid(level)) {
				vElem.AppendUnique(elm_FontsResultsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FileTypeResultsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FileTypeResultsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFileTypeResultsPool().IsValid(level)) {
				vElem.AppendUnique(elm_FileTypeResultsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ImagesResultsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ImagesResultsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetImagesResultsPool().IsValid(level)) {
				vElem.AppendUnique(elm_ImagesResultsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PagesResultsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PagesResultsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPagesResultsPool().IsValid(level)) {
				vElem.AppendUnique(elm_PagesResultsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPreflightAnalysis::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorsResultsPool,DocumentResultsPool,FontsResultsPool,FileTypeResultsPool,ImagesResultsPool,PagesResultsPool";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPreflightAnalysis::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorsResultsPool,DocumentResultsPool,FontsResultsPool,FileTypeResultsPool,ImagesResultsPool,PagesResultsPool";
	};
}; // end namespace JDF
