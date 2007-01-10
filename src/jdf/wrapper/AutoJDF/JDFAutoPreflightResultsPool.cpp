/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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

 
#include "jdf/wrapper/AutoJDF/JDFAutoPreflightResultsPool.h"
#include "jdf/wrapper/JDFPreflightCommonPool.h"
#include "jdf/wrapper/JDFPreflightCommonPool.h"
#include "jdf/wrapper/JDFPreflightCommonPool.h"
#include "jdf/wrapper/JDFPreflightCommonPool.h"
#include "jdf/wrapper/JDFPreflightCommonPool.h"
#include "jdf/wrapper/JDFPreflightCommonPool.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoPreflightResultsPool : public JDFPool

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoPreflightResultsPool& JDFAutoPreflightResultsPool::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoPreflightResultsPool: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoPreflightResultsPool::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoPreflightResultsPool::ValidNodeNames()const{
	return L"*:,PreflightResultsPool";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoPreflightResultsPool::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFPool::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetColorsResultsPool(int iSkip)const{
	JDFPreflightCommonPool e=GetElement(elm_ColorsResultsPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetCreateColorsResultsPool(int iSkip){
	JDFPreflightCommonPool e=GetCreateElement(elm_ColorsResultsPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::AppendColorsResultsPool(){
	JDFPreflightCommonPool e=AppendElement(elm_ColorsResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetDocumentResultsPool(int iSkip)const{
	JDFPreflightCommonPool e=GetElement(elm_DocumentResultsPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetCreateDocumentResultsPool(int iSkip){
	JDFPreflightCommonPool e=GetCreateElement(elm_DocumentResultsPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::AppendDocumentResultsPool(){
	JDFPreflightCommonPool e=AppendElement(elm_DocumentResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetFontsResultsPool(int iSkip)const{
	JDFPreflightCommonPool e=GetElement(elm_FontsResultsPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetCreateFontsResultsPool(int iSkip){
	JDFPreflightCommonPool e=GetCreateElement(elm_FontsResultsPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::AppendFontsResultsPool(){
	JDFPreflightCommonPool e=AppendElement(elm_FontsResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetFileTypeResultsPool(int iSkip)const{
	JDFPreflightCommonPool e=GetElement(elm_FileTypeResultsPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetCreateFileTypeResultsPool(int iSkip){
	JDFPreflightCommonPool e=GetCreateElement(elm_FileTypeResultsPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::AppendFileTypeResultsPool(){
	JDFPreflightCommonPool e=AppendElement(elm_FileTypeResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetImagesResultsPool(int iSkip)const{
	JDFPreflightCommonPool e=GetElement(elm_ImagesResultsPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetCreateImagesResultsPool(int iSkip){
	JDFPreflightCommonPool e=GetCreateElement(elm_ImagesResultsPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::AppendImagesResultsPool(){
	JDFPreflightCommonPool e=AppendElement(elm_ImagesResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetPagesResultsPool(int iSkip)const{
	JDFPreflightCommonPool e=GetElement(elm_PagesResultsPool,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::GetCreatePagesResultsPool(int iSkip){
	JDFPreflightCommonPool e=GetCreateElement(elm_PagesResultsPool,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFPreflightCommonPool JDFAutoPreflightResultsPool::AppendPagesResultsPool(){
	JDFPreflightCommonPool e=AppendElement(elm_PagesResultsPool);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoPreflightResultsPool::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFPool::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_ColorsResultsPool);

		for(i=0;i<nElem;i++){
			if (!GetColorsResultsPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_ColorsResultsPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_DocumentResultsPool);

		for(i=0;i<nElem;i++){
			if (!GetDocumentResultsPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_DocumentResultsPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FontsResultsPool);

		for(i=0;i<nElem;i++){
			if (!GetFontsResultsPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_FontsResultsPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_FileTypeResultsPool);

		for(i=0;i<nElem;i++){
			if (!GetFileTypeResultsPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_FileTypeResultsPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_ImagesResultsPool);

		for(i=0;i<nElem;i++){
			if (!GetImagesResultsPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_ImagesResultsPool);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		nElem=NumChildElements(elm_PagesResultsPool);

		for(i=0;i<nElem;i++){
			if (!GetPagesResultsPool(i).IsValid(level)) {
				vElem.AppendUnique(elm_PagesResultsPool);
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
	WString JDFAutoPreflightResultsPool::OptionalElements()const{
		return JDFPool::OptionalElements()+L",ColorsResultsPool,DocumentResultsPool,FontsResultsPool,FileTypeResultsPool,ImagesResultsPool,PagesResultsPool";
	};
}; // end namespace JDF
