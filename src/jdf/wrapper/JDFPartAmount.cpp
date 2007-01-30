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
//  Author: Dr. Rainer Prosi
// 
// Revision history:
//
// JDFPartAmount.cpp: implementation of the JDFPartAmount class.
//
//////////////////////////////////////////////////////////////////////
#include "JDFPartAmount.h"

using namespace std;

namespace JDF{
	JDFPartAmount & JDFPartAmount::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFPartAmount: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::IsAbstract()const{
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	WString JDFPartAmount::ValidNodeNames()const{
		return L"*:,PartAmount";
	};
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFPartAmount::IsValid(EnumValidationLevel level)const{
		if(level<=ValidationLevel_Construct) {
			if(level<=ValidationLevel_None) 
				return true;
			if(isNull()) 
				return true;
		}

		bool b=JDFElement::IsValid(level);
		if(!b) 
			return false;
		if(level==ValidationLevel_Construct) 
			return true;
		JDFElement parent=GetParentNode();
		WString parentNodeName=parent.GetNodeName();
		if(parentNodeName!=elm_AmountPool){
			return false;
		}
		return true;
		
	}

	//////////////////////////////////////////////////////////////////////
	
	vWString JDFPartAmount::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax) 
			return vElem;
		nElem=NumChildElements(elm_Part);
		// part is mandatory
		if((nElem>1)||(nElem==0&&RequiredLevel(level))){
			vElem.push_back(elm_Part);
			if (++n>=nMax) 
				return vElem;

		}
		for(i=0;i<nElem;i++){
			JDFPart child=GetElement(elm_Part,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Part);
				if (++n>=nMax) 
					return vElem;
			};
		}
		return vElem;
	};
	
	//////////////////////////////////////////////////////////////////////

	/**
	* definition of optional attributes in the JDF namespace
	* @return WString Comma separated list of optional attributes
	*/
	WString JDFPartAmount::OptionalAttributes()const{
		JDFResourceLink rl=GetParentNode().GetParentNode();
		vWString v=rl.OptionalAttributes();
		
		// remove the illegal optional attributes inherited from ResourceLink
		v.RemoveStrings(atr_CombinedProcessIndex);
		v.RemoveStrings(atr_CombinedProcessType);
		v.RemoveStrings(atr_PipePartIDKeys);
		v.RemoveStrings(atr_PipeProtocol);
		v.RemoveStrings(atr_ProcessUsage);
		v.RemoveStrings(atr_rSubRef);
		return v.GetString(WString::comma);
	};
	
	/**
	* definition of required attributes in the JDF namespace
	* @return WString Comma separated list of optional attributes
	*/
	WString JDFPartAmount::RequiredAttributes()const{
		return JDFElement::RequiredAttributes();
	};

	/**
	* definition of optional elements in the JDF namespace
	* @return WString Comma separated list of required elements
	*/
	WString JDFPartAmount::OptionalElements()const{
		return JDFElement::OptionalElements();
	};
	
	/**
	* definition of required elements in the JDF namespace
	* @return WString Comma separated list of required elements
	*/
	WString JDFPartAmount::RequiredElements()const{
		return JDFElement::RequiredElements()+L",Part";
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::ValidrRef(EnumValidationLevel level) const {
		return !HasAttribute(atr_rRef);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::ValidUsage(EnumValidationLevel level) const {
		return !HasAttribute(atr_Usage);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::ValidProcessUsage(EnumValidationLevel level) const {
		return !HasAttribute(atr_ProcessUsage);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::ValidrSubRef(EnumValidationLevel level) const {
		return !HasAttribute(atr_rSubRef);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::ValidPipeProtocol(EnumValidationLevel level) const {
		return !HasAttribute(atr_PipeProtocol);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::ValidPipePartIDKeys(EnumValidationLevel level) const {
		return !HasAttribute(atr_PipePartIDKeys);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::ValidCombinedProcessType(EnumValidationLevel level) const {
		return !HasAttribute(atr_CombinedProcessType);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFPartAmount::ValidCombinedProcessIndex(EnumValidationLevel level) const {
		return !HasAttribute(atr_CombinedProcessIndex);
	};
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	mAttribute JDFPartAmount::GetPartMap()const{
		return GetElement(elm_Part).GetAttributeMap();
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	// dummy private routine
	vmAttribute JDFPartAmount::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}
	
	
}

//////////////////////////////////////////////////////////////////////

