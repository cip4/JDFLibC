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

 
#include "jdf/wrapper/AutoJDF/JDFAutoInsertingIntent.h"
#include "jdf/wrapper/JDFInsertList.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoInsertingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoInsertingIntent& JDFAutoInsertingIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoInsertingIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoInsertingIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoInsertingIntent::ValidNodeNames()const{
	return L"*:,InsertingIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 typesafe validator
*/
	vWString JDFAutoInsertingIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		return vAtts;
	};


/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFSpanGlueType JDFAutoInsertingIntent::GetGlueType()const{
	JDFSpanGlueType e=GetElement(elm_GlueType);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlueType JDFAutoInsertingIntent::GetCreateGlueType(){
	JDFSpanGlueType e=GetCreateElement(elm_GlueType);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanGlueType JDFAutoInsertingIntent::AppendGlueType(){
	JDFSpanGlueType e=AppendElementN(elm_GlueType,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertList JDFAutoInsertingIntent::GetInsertList()const{
	JDFInsertList e=GetElement(elm_InsertList);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertList JDFAutoInsertingIntent::GetCreateInsertList(){
	JDFInsertList e=GetCreateElement(elm_InsertList);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFInsertList JDFAutoInsertingIntent::AppendInsertList(){
	JDFInsertList e=AppendElementN(elm_InsertList,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMethod JDFAutoInsertingIntent::GetMethod()const{
	JDFSpanMethod e=GetElement(elm_Method);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMethod JDFAutoInsertingIntent::GetCreateMethod(){
	JDFSpanMethod e=GetCreateElement(elm_Method);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFSpanMethod JDFAutoInsertingIntent::AppendMethod(){
	JDFSpanMethod e=AppendElementN(elm_Method,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoInsertingIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_GlueType);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_GlueType);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetGlueType().IsValid(level)) {
				vElem.AppendUnique(elm_GlueType);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_InsertList);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_InsertList);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_InsertList);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetInsertList().IsValid(level)) {
				vElem.AppendUnique(elm_InsertList);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Method);
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_Method);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetMethod().IsValid(level)) {
				vElem.AppendUnique(elm_Method);
				if (++n>=nMax)
					return vElem;
			}
		}
		return vElem;
	};


/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoInsertingIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",GlueType,InsertList,Method";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoInsertingIntent::RequiredElements()const{
		return JDFIntentResource::RequiredElements()+L",InsertList";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoInsertingIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",GlueType,Method";
	};
}; // end namespace JDF
