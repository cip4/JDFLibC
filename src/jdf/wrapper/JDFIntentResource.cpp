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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
//
// JDFIntentResource.cpp: implementation of the JDFIntentResource class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFIntentResource.h" 
#include "JDFSpan.h"

using namespace std;
namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	
	JDFIntentResource& JDFIntentResource::operator =(const KElement& other){
		JDFResource::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFIntentResource: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////

	bool JDFIntentResource::init(){
		bool b=JDFResource::init();
		SetClass(Class_Intent);
		return b;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFSpanBase JDFIntentResource::GetCreateSpan(const WString & name, JDFSpanBase::EnumDataType nType){
		/// note that this is the inherited version from JDFResource!
		JDFSpanBase e=GetCreateElement(name);
		e.SetDataType(nType);
		return e;
	};
	
	//////////////////////////////////////////////////////////////////////

	JDFSpanBase JDFIntentResource::AppendSpan(const WString & name, JDFSpanBase::EnumDataType nType ){
		/// note that this is the inherited version from JDFResource!
		JDFSpanBase e=AppendElement(name,true);
		e.SetDataType(nType);
		return e;		
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFSpanBase JDFIntentResource::GetSpan(const WString & name, JDFSpanBase::EnumDataType nType)const{
		/// note that this is the inherited version from JDFResource!
		JDFSpanBase e=GetElement(name);
		if(!e.isNull()){
			JDFSpanBase::EnumDataType dataType=e.GetDataType();
			if(dataType!=nType)
				throw JDFException(L"JDFIntentResource::GetSpan incompatible datatypes"+e.GetAttribute(atr_DataType));
		}
		return e;
		
	};
	//////////////////////////////////////////////////////////////////////
	
	vElement JDFIntentResource::GetSpans()const{
		vElement v=GetChildElementVector();
		for(int i=v.size()-1;i>=0;i--){
			JDFElement e=v[i];
			if(e.IsComment()) 
				v.erase(v.begin()+i);
		}
		return v;
	}
	//////////////////////////////////////////////////////////////////////
	
	int JDFIntentResource::PreferredToActual(const WString& key){
		int nDone=0;
		if(!IsLeaf()){
			vElement leaves=GetLeaves();
			for(int i=0;i<leaves.size();i++){
				JDFIntentResource ri=leaves[i];
				nDone+=ri.PreferredToActual(key);
			}
			return nDone;
		}
		
		vWString vKeys;
		if(IsWildcard(key.c_str())){
			vElement v=GetChildrenWithAttribute(WString::star,atr_DataType);
			for(int i=0;i<v.size();i++) 
				vKeys.push_back(v[i].GetNodeName());
		}else{
			vKeys.push_back(key);
		}
		
		for(int i=0;i<vKeys.size();i++){
			JDFSpanBase base=GetElement(vKeys[i]);
			if(base.PreferredToActual()) 
				nDone++;
		}
		return nDone;
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFIntentResource::ValidClass(EnumValidationLevel level) const {
		if(!HasAttribute(atr_Class)) 
			return (level<=ValidationLevel_Incomplete)||(level==ValidationLevel_RecursiveIncomplete);
		return GetClass()==Class_Intent;
	};

//////////////////////////////////////////////////////////////////////////////////
vWString JDFIntentResource::GetValidNodeNames()const{
	//  update handling is NOT valid for intent resources!
	return JDFElement::GetValidNodeNames();
};

//////////////////////////////////////////////////////////////////////////////////

}