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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created 060502 RP
//
// XMLDocUserData.cpp: implementation of the JDFDoc class.
//
//////////////////////////////////////////////////////////////////////

#include "XMLDocUserData.h"

#include "KElement.h"
#include "JDFException.h"

#include <map>

XERCES_CPP_NAMESPACE_USE

namespace JDF{

	typedef std::map<WString,DOMElement*> targetMap;

	static bool useIDCache=true;
	
	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	
	XMLDocUserData::XMLDocUserData(){
		ClearDirtyIDs();
		mapTarget=new targetMap();
		dirtyPolicy=DirtyPolicy_None;
		useIDCache=true;
	}
	//////////////////////////////////////////////////////////////////////
	XMLDocUserData::~XMLDocUserData(){
		ClearDirtyIDs();
		ClearTargets();
		delete (targetMap*)mapTarget;
	}

	//////////////////////////////////////////////////////////////////////

		/**
		* Set the dirty policy to dirtPol
		*/
	void XMLDocUserData::SetDirtyPolicy(EnumDirtyPolicy dirtPol){
		dirtyPolicy=dirtPol;
	}

	//////////////////////////////////////////////////////////////////////

	const vWString& XMLDocUserData::GetDirtyIDs()const{
		if(!this)
			throw JDFException(L"XMLDocUserData::GetDirtyIDs used on null object");
		if(dirtyPolicy==DirtyPolicy_ID)
			return vDirtyID;
		return vWString::emptyvStr;
	}

	//////////////////////////////////////////////////////////////////////

	const vWString& XMLDocUserData::GetDirtyXPaths()const{
		if(!this)
			throw JDFException(L"XMLDocUserData::GetDirtyXPaths used on null object");
		if(dirtyPolicy==DirtyPolicy_XPath)
			return vDirtyID;
		return vWString::emptyvStr;
	}

	//////////////////////////////////////////////////////////////////////

	void XMLDocUserData::ClearDirtyIDs(){
		if(!this)
			throw JDFException(L"XMLDocUserData::ClearDirtyIDs used on null object");
		vDirtyID.clear();
	};
	
	//////////////////////////////////////////////////////////////////////

	const vWString&  XMLDocUserData::SetDirty(const WString &id){
		if(!this)
			throw JDFException(L"XMLDocUserData::SetDirty used on null object");

		if(dirtyPolicy==DirtyPolicy_ID){
			vDirtyID.AppendUnique(id);
		}

		return vDirtyID;
	}
	//////////////////////////////////////////////////////////////////////

	const vWString&  XMLDocUserData::SetDirty(const KElement *e, bool bAttribute){
		if(!this)
			throw JDFException(L"XMLDocUserData::SetDirty used on null object");

		if(dirtyPolicy==DirtyPolicy_XPath){
			int i=0;

			WString x=e->GetXPath();			
			if(bAttribute)
				x+=L"/@";

			for(i=0;i<vDirtyID.size();i++){
				const WString& s=vDirtyID[i];
				if(s.startsWith(x)){
					if(s==x) // e is already dirty
						return vDirtyID; 
					vDirtyID.erase(vDirtyID.begin()+i);
					i--; // achtung! don't optimize by taking vDirtyID.size() out of the loop
				}else if (x.startsWith(s)){ // we have a dirty parent, do nothing
					return vDirtyID; 
				}else if(x>s){ // keep sorted
					break;
				}
				vDirtyID.insert(vDirtyID.begin()+i,x);
			}
		}else if(dirtyPolicy==DirtyPolicy_ID){
			SetDirty(e->GetInheritedAttribute(KElement::atr_ID));
		}
		return vDirtyID;
	};
	//////////////////////////////////////////////////////////////////////

	bool  XMLDocUserData::IsDirty(const WString &id)const{
		if(!this)
			throw JDFException(L"XMLDocUserData::IsDirty used on null object");
		return vDirtyID.hasString(id);
	}

	//////////////////////////////////////////////////////////////////////

	void XMLDocUserData::SetTarget(const KElement& target, const WString& id){
		if(!this)
			throw JDFException(L"XMLDocUserData::SetTarget used on null object");
		if(id.empty())
			return;

		targetMap*pt=(targetMap*)mapTarget;
		pt->insert(targetMap::value_type(id,target.GetDOMElement()));
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void XMLDocUserData::RemoveTarget(const KElement& target)
	{		
		if(!useIDCache)
			return;

		if(!this)
			throw JDFException(L"XMLDocUserData::RemoveTarget used on null object");
		const WString id=target.GetAttribute(KElement::atr_ID);
		if(id.empty())
			return;

		targetMap*pt=(targetMap*)mapTarget;
		targetMap::iterator it=pt->find(id);
		if(it!=pt->end()){
			pt->erase(it);
		}
	}
	
	//////////////////////////////////////////////////////////////////////

	KElement XMLDocUserData::GetTarget(const WString& id)const{
		if(!useIDCache)
			return KElement::DefKElement;
		if(!this)
			throw JDFException(L"XMLDocUserData::GetTarget used on null object");
		targetMap*pt=(targetMap*)mapTarget;
		targetMap::const_iterator it=pt->find(id);
		if(it!=pt->end())
		{
			KElement e=it->second;
			if(e.GetAttribute(KElement::atr_ID)==id)
				return e;
		}
		return KElement::DefKElement;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void XMLDocUserData::ClearTargets()
	{
		if(!useIDCache)
			return;
		if(!this)
			throw JDFException(L"XMLDocUserData::ClearTargets used on null object");
		targetMap*pt=(targetMap*)mapTarget;
		pt->clear();
	};
	
	//////////////////////////////////////////////////////////////////////

	void XMLDocUserData::setIDCache(bool bCache)
	{
		useIDCache=bCache;
	}

	//////////////////////////////////////////////////////////////////////

	bool XMLDocUserData::getIDCache()
	{
		return useIDCache;
	}

	//////////////////////////////////////////////////////////////////////


	
}
