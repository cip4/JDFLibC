/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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
// created before 19.Jan.2000
//
// JDFResourceLinkPool.cpp: implementation of the JDFResourceLinkPool class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFResourceLinkPool.h"
#include "JDFResourceLink.h"
#include "JDFNode.h"
#include "JDFResourcePool.h"
#include "jdf/lang/VoidSet.h"



using namespace std;
namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	
	JDFResourceLinkPool &JDFResourceLinkPool::operator =(const KElement& other){
		JDFPool::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFResourceLinkPool: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLinkPool::IsAbstract()const{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLinkPool::init(){
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	vElement JDFResourceLinkPool::GetLinks(const mAttribute &mLinkAtt)const{
		return GetPoolChildren(WString::emptyStr,mLinkAtt);
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	vElement JDFResourceLinkPool::GetPoolChildren(const WString & name, const mAttribute&mAttrib, const WString& nameSpaceURI)const{
		vElement v=GetPoolChildrenGeneric(name,mAttrib,nameSpaceURI);
		for(int i=v.size()-1;i>=0;i--){
			if(!JDFElement(v[i]).IsResourceLink()){
				v.erase(v.begin()+i);
			}
		}
		return v;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	JDFResourceLink JDFResourceLinkPool::GetPoolChild(int i,const WString & name, const mAttribute&mAttrib, const WString& nameSpaceURI)const{
		vElement v=GetPoolChildren(name,mAttrib,nameSpaceURI);
		if(i<0){
			i=v.size()+i;
			if(i<0)
				return JDFResourceLink();
		}
		if (v.size()<=i) 
			return JDFResourceLink();
		return v[i];
	}
	//////////////////////////////////////////////////////////////////////
	
	vElement JDFResourceLinkPool::GetLinkedResources(const WString & resType,const mAttribute &mLinkAtt,const mAttribute &mResAtt, bool bFollowRefs)const{
		vElement v=GetPoolChildren(WString::emptyStr,mLinkAtt);
		vElement vL;
		WString localResType = resType;

		if (!localResType.empty() && localResType.endsWith(JDFStrings::atr_Link))
			localResType=localResType.substr(0,resType.length()-4); // remove link

		for(int i=0;i<v.size();i++){
			JDFResourceLink l=v[i];
			JDFResource r=l.GetLinkRoot();
			if(!localResType.empty()&&(r.GetResourceType()!=localResType)) continue;
			if(r.IncludesAttributes(mResAtt)) {
				vL.push_back(r);
				if(bFollowRefs){
					vL.AppendUnique(r.GetvHRefRes(bFollowRefs));
				}
			}
		}
		return vL;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	vElement JDFResourceLinkPool::GetInOutLinks(bool bInOut, bool bLink, const WString& resName, const WString& resProcUsage)const{
		return getInOutLinks(bInOut?JDFResourceLink::Usage_Input:JDFResourceLink::Usage_Output, bLink, resName,resProcUsage);
	}
	//////////////////////////////////////////////////////////////////////
	
	vElement JDFResourceLinkPool::getInOutLinks(JDFResourceLink::EnumUsage usage, bool bLink, const WString& resName, const WString& resProcUsage)const{
		WString io=JDFResourceLink::UsageString(usage);
		mAttribute mA(atr_Usage,io);
		vElement v=GetPoolChildren(WString::emptyStr,mA);
		bool bResNameWildCard=IsWildcard(resName.c_str());
		bool bResProcUsageWildcard=IsWildcard(resProcUsage.c_str());
		for(int i=v.size()-1;i>=0;i--){
			JDFElement e=v[i];
			if(!e.IsResourceLink()){
				v.erase(v.begin()+i);
				continue;
			}

			JDFResourceLink li=e;
			if (!bResNameWildCard){
				if(li.GetLinkedResourceName()!=resName){ 
					v.erase(v.begin()+i);
					continue;
				}
			}
			if (!bResProcUsageWildcard){
				if(li.GetProcessUsage()!=resProcUsage){ 
					v.erase(v.begin()+i);
					continue;
				}
			}
		}
		if(!bLink){
			v=ResourceVector(v,resName);
		} 
		return v;
	}
	
	//////////////////////////////////////////////////////////////////////

	vWString JDFResourceLinkPool::GetHRefs(const vWString& vDoneRefs, bool bRecurse)const{
		vWString v1=vDoneRefs;
		vElement vResourceLinks=GetPoolChildren();
		for(int i=0;i<vResourceLinks.size();i++){
			JDFResourceLink rl=vResourceLinks[i];
			if(!v1.hasString(rl.GetrRef())){
				v1.push_back(rl.GetrRef());
				v1.AppendUnique(rl.GetLinkRoot().GetResourceRoot().GetHRefs(v1,bRecurse));
			}
		}
		return v1;
		
	}
	
	//////////////////////////////////////////////////////////////////////

	VoidSet* JDFResourceLinkPool::GetAllRefs(VoidSet* vDoneRefs, bool bRecurse)const{
		vElement vResourceLinks=GetPoolChildren();
		for(int i=0;i<vResourceLinks.size();i++){
			JDFResourceLink rl=vResourceLinks[i];
			if(!vDoneRefs->contains(rl.GetDOMElement())){
				vDoneRefs->add(rl.GetDOMElement());
				rl.GetLinkRoot().GetResourceRoot().GetAllRefs(vDoneRefs,bRecurse);
			}
		}
		return vDoneRefs;
		
	}
	//////////////////////////////////////////////////////////////////////
	
	vElement JDFResourceLinkPool::ResourceVector(const vElement& linkVector, const WString& resType){
		vElement v;
		bool bResTypeWildcard=IsWildcard(resType.c_str());
		for(int i=0;i<linkVector.size();i++){
			JDFResourceLink l=linkVector[i];
			// 120803 rp follow parts of resource links
			if(bResTypeWildcard||(l.GetLinkedResourceName()==resType)){
				vElement vRes=l.GetTargetVector();
				v.insert(v.end(),vRes.begin(),vRes.end());
			}
		}
		return v;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFResourceLink JDFResourceLinkPool::AppendResource(const JDFResource& r, bool input, bool bForce){
		if(!r.IsValid(ValidationLevel_Construct)) 
			return JDFResourceLink();

		JDFResourceLink::EnumUsage eUsage = input ? JDFResourceLink::Usage_Input : JDFResourceLink::Usage_Output;

		WString s=r.GetID();
		mAttribute partMap=r.GetPartMap();

		if((!bForce)&&(!s.empty())){
			vElement nl=GetPoolChildren();
			for(int i=0;i<nl.size();i++){
				JDFResourceLink rl=nl[i];
				// already linked
				if ((rl.GetHRef()==s)&&(rl.GetUsage()==eUsage) &&(rl.GetPartMapVector().hasMap(partMap))) 
					return JDFResourceLink();
			}
		}
		
		JDFResourceLink rl=AppendElement(r.GetLinkString(),r.GetNamespaceURI());
		rl.SetTarget(r);
		rl.SetUsage(eUsage);

		if(!partMap.empty()) 
			rl.SetPartMap(partMap);
		
		// move the resource to the closest common ancestor if it is not already an ancestor of this
		JDFNode n=r.GetParentJDF();
		bool bMove=false;
		while(!n.IsAncestor(*this)){
			n=n.GetParentJDF();
			bMove=true;
		}

		if(bMove){
			n.GetCreateResourcePool().MoveElement(r);
		}
				
		return rl;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	vmAttribute JDFResourceLinkPool::GetPartMapVector(bool bComplete)const{
		vmAttribute vMap;
		if(bComplete){
			vWString vKeys=GetPartIDKeys();
			vWString vValidParts=JDFResource::PartIDKeyString().Tokenize();
			int keySize=vKeys.size();
			vWString* vvValues=new vWString[keySize];
			int*pI=new int[keySize];
			int*pISize=new int[keySize];
			
			for(int i=0;i<keySize;i++){
				int index=vValidParts.index(vKeys[i]);
				if(index<0) // zapp it, it ain't valid
					continue;
				JDFResource::EnumPartIDKey key=(JDFResource::EnumPartIDKey)i;
				vvValues[i]=GetPartValues(key);
				pI[i]=0;
				pISize[i]=vvValues[i].size();
			}
			while(42){
				mAttribute m;
				bool bDone=false;
				for(int i=0;i<keySize;i++) {
					m.AddPair(vKeys[i],vvValues[i][pI[i]]);
				}
				vMap.push_back(m);
				for(int n=0;n<keySize;n++){
					if(++(pI[n])>=pISize[n]){
						pI[n]=0;
						if(n==keySize-1) bDone=true;
					}else{
						break;
					}
					
				}
				if(bDone) break;
			}
			delete[](pI);
			delete[](pISize);
			delete[](vvValues);
		}else{
			vElement links=GetPoolChildren();
			for(int l=0;l<links.size();l++){
				JDFResourceLink link=links[l];
				vmAttribute tempMap=link.GetPartMapVector();
				for(int i=0;i<tempMap.size();i++){
					mAttribute mTmp=tempMap[i];
					bool bFound=false;
					bool bReplace=false;
					for(int j=vMap.size()-1;j>=0;j--){ // backwards because of potential erasing
						if(!bReplace&&(vMap[j].SubMap(mTmp))){
							bFound=true;
							break;
						}
						if(mTmp.SubMap(vMap[j])){
							if(bReplace){
								vMap[j]=mTmp;
							}else{ // already replaced one, clear all other matches
								vMap.erase(vMap.begin()+j);
							}
							bReplace=true;
						}
						
						
					}
					if(!bFound) 
						vMap.push_back(mTmp);				
				}			
			}
		}
		return vMap;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	
	vWString JDFResourceLinkPool::GetPartIDKeys()const{
		vWString vs;
		vElement links=GetPoolChildren();
		for(int i=0;i<links.size();i++){
			JDFResourceLink link=links[i];
			vs.AppendUnique(link.GetLinkRoot().GetPartIDKeys());
		}
		return vs;
	}
	//////////////////////////////////////////////////////////////////////
	
	vWString JDFResourceLinkPool::GetPartValues(JDFResource::EnumPartIDKey key)const{
		vWString vs;
		vElement links=GetPoolChildren();
		for(int i=0;i<links.size();i++){
			JDFResourceLink link=links[i];
			vs.AppendUnique(link.GetLinkRoot().GetPartValues(key));
		}
		return vs;
	}
	//////////////////////////////////////////////////////////////////////
	/// typesafe validator
	bool JDFResourceLinkPool::IsValid(EnumValidationLevel level)const{
		return JDFPool::IsValid(level);
	}
	//////////////////////////////////////////////////////////////////////
	
	WString JDFResourceLinkPool::ValidNodeNames()const{
		return elm_ResourceLinkPool;
	};
	
	
	//////////////////////////////////////////////////////////////////////
	
	vWString JDFResourceLinkPool::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		return JDFPool::GetInvalidAttributes(level,bIgnorePrivate,nMax);
	};
	
	
	//////////////////////////////////////////////////////////////////////

	
	vWString JDFResourceLinkPool::GetUnknownElements(bool bIgnorePrivate,int nMax)const{
		return GetUnknownPoolElements(PoolType_ResourceLinkPool,bIgnorePrivate,nMax);
	};
	

	//////////////////////////////////////////////////////////////////////

	JDFResourceLink JDFResourceLinkPool::linkResource(JDFResource r, JDFResourceLink::EnumUsage usage, JDFNode::EnumProcessUsage processUsage)
	{
		WString s = r.GetID();

		if (s.equals(WString::emptyStr))
			return JDFResourceLink::DefKElement;

		JDFResourceLink rl = (JDFResourceLink) AppendElement(r.GetLinkString(), r.GetNamespaceURI());
		rl.SetTarget(r);
		if (usage!=JDFResourceLink::Usage_Unknown)
		{
			rl.SetUsage(usage);
			rl.SetProcessUsage(JDFNode::ProcessUsageString(processUsage));
		}

		//move the resource to the closest common ancestor if it is not already an ancestor of this
		JDFNode parent=r.GetParentJDF();

		//move the resource to the closest common ancestor if it is not already an ancestor of this
		while (!parent.isNull() && !parent.IsAncestor(*this))
		{
			parent=r.GetParentJDF();
			if(parent.isNull())
				break;
			parent=parent.GetParentJDF();
			if(parent.isNull())
			{
				rl.DeleteNode(); // cleanup
				throw JDFException(L"JDFResourceLink appendResource resource is not in the same document");
			}

			r = (JDFResource)parent.GetCreateResourcePool().MoveElement(r, KElement::DefKElement);
		}  
		return rl;
	}
}