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

//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2001
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  17.03.2004
//
// JDFStringEvaluation.cpp: implementation of the JDFStringEvaluation 
//
//////////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/JDFStringEvaluation.h"
#include "xercesc/util/regx/RegularExpression.hpp"

XERCES_CPP_NAMESPACE_USE
using namespace std;
namespace JDF{
/**
* copy equivalance operator
*/
	JDFStringEvaluation& JDFStringEvaluation::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
			throw JDFException(L"Invalid constructor for JDFStringEvaluation: "+other.GetNodeName());
		return *this;
	};

	//////////////////////////////////////////////////////////////////////

	WString JDFStringEvaluation::ValidNodeNames()const{
		return L"*:,StringEvaluation";
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFStringEvaluation::IsAbstract()const{
		return false;
	}
	//////////////////////////////////////////////////////////////////////

	WString JDFStringEvaluation::OptionalElements()const{
		return JDFEvaluation::OptionalElements()+L",Value";
	};

	//////////////////////////////////////////////////////////////////////
	
	vWString JDFStringEvaluation::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFEvaluation::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax)
			 return vElem;
		nElem=NumChildElements(elm_Value);

		for(i=0;i<nElem;i++){
			if (!GetValue(i).IsValid(level)) {
				vElem.AppendUnique(elm_Value);
				if (++n>=nMax)
					return vElem;
				break;
			}
		}
		return vElem;
	};
	/////////////////////////////////////////////////////////////////////////
	
	WString JDFStringEvaluation::OptionalAttributes()const{
		return JDFEvaluation::OptionalAttributes()+L",Length,RegExp";
	};
	/////////////////////////////////////////////////////////////////////////
	
	vWString JDFStringEvaluation::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts=JDFEvaluation::GetInvalidAttributes(level,bIgnorePrivate,nMax);
		int n=vAtts.size();
		if(n>=nMax)
			return vAtts;
		if(!ValidLength(level)) {
			vAtts.push_back(atr_Length);
			if(++n>=nMax)
				return vAtts;
		};
		if(!ValidRegExp(level)) {
			vAtts.push_back(atr_RegExp);
			if(++n>=nMax)
				return vAtts;
		};
		return vAtts;
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	bool JDFStringEvaluation::ValidLength(EnumValidationLevel level) const {
		return ValidAttribute(atr_Length,AttributeType_IntegerRange,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFStringEvaluation::ValidRegExp(EnumValidationLevel level) const {
		return ValidAttribute(atr_RegExp,AttributeType_regExp,false);
	};
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	
	void JDFStringEvaluation::SetLength(const JDFIntegerRange& value){
		SetAttribute(atr_Length,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////

	JDFIntegerRange JDFStringEvaluation::GetLength() const {
		return GetAttribute(atr_Length);
	};
	////////////////////////////////////////////////////////////////////////
	
	void JDFStringEvaluation::SetRegExp(const WString& value){
		SetAttribute(atr_RegExp,value);
	};
	//////////////////////////////////////////////////////////////////////	 
	
	WString JDFStringEvaluation::GetRegExp() const {
		return GetAttribute(atr_RegExp);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	JDFValue JDFStringEvaluation::GetValue(int iSkip)const{
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e;
	};
	/////////////////////////////////////////////////////////////////////

	JDFValue JDFStringEvaluation::AppendValue(){
		JDFValue e=AppendElement(elm_Value);
		e.init();
		return e;
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/* ******************************************************
	// Subelement Getter / Setter
	**************************************************************** */

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	void JDFStringEvaluation::SetValueValue(int iSkip, const WString& value){
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		e.SetValue(value);
	};
	//////////////////////////////////////////////////////////////////////

	WString JDFStringEvaluation::GetValueValue(int iSkip) const {
		JDFValue e=GetElement(elm_Value,WString::emptyStr,iSkip);
		return e.GetValue();
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	bool JDFStringEvaluation::FitsValue(const WString& value) const{

		return (FitsLength(value)&&FitsRegExp(value)&&FitsValueElem(value));

	}
	//////////////////////////////////////////////////////////////////////
	bool JDFStringEvaluation::FitsLength(const WString& str) const{

		if (HasAttribute(atr_Length)) 
		{
			int len=str.length();
			return GetLength().InRange(len);
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFStringEvaluation::FitsRegExp(const WString& str) const{

		if (!HasAttribute(atr_RegExp)) { 
			return true; // if RegExp is not specified return true 
		}
		
		WString rExp = GetRegExp();

		RegularExpression re(rExp.c_str());

		return re.matches(str.c_str()); 

	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFStringEvaluation::FitsValueElem(const WString& str) const{
		
		vElement v=GetChildElementVector(elm_Value);
		int siz=v.size();
		if (siz==0) {
			return true; // Evaluation has no Value elements
		}
		for (int i=0; i<siz; i++)
		{
			JDFValue elm=v[i];
			
			WString value=GetValueValue(i);
			if (!value.compare(str))
				return true; // we have found it
		}
		return false; 
	}
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
}; // namespace JDF
