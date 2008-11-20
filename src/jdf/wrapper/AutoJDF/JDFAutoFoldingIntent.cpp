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

 
#include "jdf/wrapper/AutoJDF/JDFAutoFoldingIntent.h"
#include "jdf/wrapper/JDFFold.h"
#include "jdf/wrapper/JDFRefElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoFoldingIntent : public JDFIntentResource

*********************************************************************
*/
/**
* copy equivalance operator
*/
JDFAutoFoldingIntent& JDFAutoFoldingIntent::operator=(const KElement& other){
	KElement::operator=(other);
	if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFAutoFoldingIntent: "+other.GetNodeName());
	return *this;
};

/////////////////////////////////////////////////////
	bool JDFAutoFoldingIntent::IsAbstract()const{
		return false;
	}

/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	WString JDFAutoFoldingIntent::ValidNodeNames()const{
	return L"*:,FoldingIntent";
};


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 definition of optional attributes in the JDF namespace
*/
	WString JDFAutoFoldingIntent::OptionalAttributes()const{
		return JDFIntentResource::OptionalAttributes()+WString(L",Folds");
};

/**
 typesafe validator
*/
	vWString JDFAutoFoldingIntent::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFIntentResource::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidFolds(level)) {
			vAtts.push_back(atr_Folds);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};

/**
* Set attribute Folds
*@param JDFXYPair value: the value to set the attribute to
*/
	 void JDFAutoFoldingIntent::SetFolds(const JDFXYPair& value){
	SetAttribute(atr_Folds,value);
};
/**
* Get string attribute Folds
* @return JDFXYPair the vaue of the attribute 
*/
	 JDFXYPair JDFAutoFoldingIntent::GetFolds() const {
	return GetAttribute(atr_Folds,WString::emptyStr);
};
/////////////////////////////////////////////////////////////////////////
	bool JDFAutoFoldingIntent::ValidFolds(EnumValidationLevel level) const {
		return ValidAttribute(atr_Folds,AttributeType_XYPair,false);
	};

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


JDFNameSpan JDFAutoFoldingIntent::GetFoldingCatalog()const{
	JDFNameSpan e=GetElement(elm_FoldingCatalog);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoFoldingIntent::GetCreateFoldingCatalog(){
	JDFNameSpan e=GetCreateElement(elm_FoldingCatalog);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFNameSpan JDFAutoFoldingIntent::AppendFoldingCatalog(){
	JDFNameSpan e=AppendElementN(elm_FoldingCatalog,1);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFold JDFAutoFoldingIntent::GetFold(int iSkip)const{
	JDFFold e=GetElement(elm_Fold,WString::emptyStr,iSkip);
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFold JDFAutoFoldingIntent::GetCreateFold(int iSkip){
	JDFFold e=GetCreateElement(elm_Fold,WString::emptyStr,iSkip);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////

JDFFold JDFAutoFoldingIntent::AppendFold(){
	JDFFold e=AppendElement(elm_Fold);
	e.init();
	return e;
};
/////////////////////////////////////////////////////////////////////
// element resource linking 
JDFRefElement JDFAutoFoldingIntent::RefFold(JDFFold& refTarget){
	return RefElement(refTarget);
};
/////////////////////////////////////////////////////////////////////

/**
 typesafe validator
*/
	vWString JDFAutoFoldingIntent::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFIntentResource::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_FoldingCatalog);
		if((level>=ValidationLevel_Complete)&&(nElem<1)) {
		vElem.AppendUnique(elm_FoldingCatalog);
			if (++n>=nMax)
			return vElem;
		}
		if(nElem>1){ //bound error
			vElem.AppendUnique(elm_FoldingCatalog);
			if (++n>=nMax)
				return vElem;
		}else if(nElem==1){
			if(!GetFoldingCatalog().IsValid(level)) {
				vElem.AppendUnique(elm_FoldingCatalog);
				if (++n>=nMax)
					return vElem;
			}
		}
		nElem=NumChildElements(elm_Fold);

		for(i=0;i<nElem;i++){
			if (!GetFold(i).IsValid(level)) {
				vElem.AppendUnique(elm_Fold);
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
	WString JDFAutoFoldingIntent::UniqueElements()const{
		return JDFIntentResource::UniqueElements()+L",FoldingCatalog";
	};

/**
 definition of required elements in the JDF namespace
*/
	WString JDFAutoFoldingIntent::RequiredElements()const{
		return JDFIntentResource::RequiredElements()+L",FoldingCatalog";
	};

/**
 definition of optional elements in the JDF namespace
*/
	WString JDFAutoFoldingIntent::OptionalElements()const{
		return JDFIntentResource::OptionalElements()+L",Fold";
	};
}; // end namespace JDF
