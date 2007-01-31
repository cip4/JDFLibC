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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreflightProfile.h"
#include "jdf/wrapper/JDFPreflightConstraintsPool.h"
#include "jdf/wrapper/JDFPreflightConstraintsPool.h"
#include "jdf/wrapper/JDFPreflightConstraintsPool.h"
#include "jdf/wrapper/JDFPreflightConstraintsPool.h"
#include "jdf/wrapper/JDFPreflightConstraintsPool.h"
#include "jdf/wrapper/JDFPreflightConstraintsPool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreflightProfile : public JDFResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreflightProfile& JDFAutoPreflightProfile::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreflightProfile: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreflightProfile::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreflightProfile::ValidNodeNames()const{
	return L"*:,PreflightProfile";
};

bool JDFAutoPreflightProfile::ValidClass(EnumValidationLevel level) const {
	if(!HasAttribute(atr_Class))
		return !RequiredLevel(level);
	return GetClass()==Class_Parameter;
};

bool JDFAutoPreflightProfile::init(){
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
	vWString JDFAutoPreflightProfile::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetColorsConstraintsPool()const{
	JDFPreflightConstraintsPool e=GetElement(elm_ColorsConstraintsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetCreateColorsConstraintsPool(){
	JDFPreflightConstraintsPool e=GetCreateElement(elm_ColorsConstraintsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::AppendColorsConstraintsPool(){
	JDFPreflightConstraintsPool e=AppendElementN(elm_ColorsConstraintsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetDocumentConstraintsPool()const{
	JDFPreflightConstraintsPool e=GetElement(elm_DocumentConstraintsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetCreateDocumentConstraintsPool(){
	JDFPreflightConstraintsPool e=GetCreateElement(elm_DocumentConstraintsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::AppendDocumentConstraintsPool(){
	JDFPreflightConstraintsPool e=AppendElementN(elm_DocumentConstraintsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetFontsConstraintsPool()const{
	JDFPreflightConstraintsPool e=GetElement(elm_FontsConstraintsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetCreateFontsConstraintsPool(){
	JDFPreflightConstraintsPool e=GetCreateElement(elm_FontsConstraintsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::AppendFontsConstraintsPool(){
	JDFPreflightConstraintsPool e=AppendElementN(elm_FontsConstraintsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetFileTypeConstraintsPool()const{
	JDFPreflightConstraintsPool e=GetElement(elm_FileTypeConstraintsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetCreateFileTypeConstraintsPool(){
	JDFPreflightConstraintsPool e=GetCreateElement(elm_FileTypeConstraintsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::AppendFileTypeConstraintsPool(){
	JDFPreflightConstraintsPool e=AppendElementN(elm_FileTypeConstraintsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetImagesConstraintsPool()const{
	JDFPreflightConstraintsPool e=GetElement(elm_ImagesConstraintsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetCreateImagesConstraintsPool(){
	JDFPreflightConstraintsPool e=GetCreateElement(elm_ImagesConstraintsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::AppendImagesConstraintsPool(){
	JDFPreflightConstraintsPool e=AppendElementN(elm_ImagesConstraintsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetPagesConstraintsPool()const{
	JDFPreflightConstraintsPool e=GetElement(elm_PagesConstraintsPool);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::GetCreatePagesConstraintsPool(){
	JDFPreflightConstraintsPool e=GetCreateElement(elm_PagesConstraintsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightConstraintsPool JDFAutoPreflightProfile::AppendPagesConstraintsPool(){
	JDFPreflightConstraintsPool e=AppendElementN(elm_PagesConstraintsPool,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreflightProfile::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorsConstraintsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ColorsConstraintsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetColorsConstraintsPool().IsValid(level)) {
				vElem.AppendUnique(elm_ColorsConstraintsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_DocumentConstraintsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_DocumentConstraintsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetDocumentConstraintsPool().IsValid(level)) {
				vElem.AppendUnique(elm_DocumentConstraintsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FontsConstraintsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FontsConstraintsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFontsConstraintsPool().IsValid(level)) {
				vElem.AppendUnique(elm_FontsConstraintsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_FileTypeConstraintsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FileTypeConstraintsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFileTypeConstraintsPool().IsValid(level)) {
				vElem.AppendUnique(elm_FileTypeConstraintsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_ImagesConstraintsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_ImagesConstraintsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetImagesConstraintsPool().IsValid(level)) {
				vElem.AppendUnique(elm_ImagesConstraintsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_PagesConstraintsPool);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_PagesConstraintsPool);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetPagesConstraintsPool().IsValid(level)) {
				vElem.AppendUnique(elm_PagesConstraintsPool);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoPreflightProfile::UniqueElements()const{
		return JDFResource::UniqueElements()+L",ColorsConstraintsPool,DocumentConstraintsPool,FontsConstraintsPool,FileTypeConstraintsPool,ImagesConstraintsPool,PagesConstraintsPool";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoPreflightProfile::OptionalElements()const{
		return JDFResource::OptionalElements()+L",ColorsConstraintsPool,DocumentConstraintsPool,FontsConstraintsPool,FileTypeConstraintsPool,ImagesConstraintsPool,PagesConstraintsPool";
	};
}; // end namespace JDF
