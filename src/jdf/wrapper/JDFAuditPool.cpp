/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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
// 040900 RP renamed JDFProcess to JDFNode
// JDFAuditPool.cpp: implementation of the JDFAuditPool class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFAuditPool.h"
#include "JDFAudit.h"
#include "JDFPhaseTime.h"
#include "JDFProcessRun.h"
#include "JDFNode.h"
#include "JDFPart.h"
//#include <iostream>

using namespace std;
namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFAuditPool::IsAbstract()const{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFAuditPool &JDFAuditPool::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFAuditPool: "+other.GetNodeName()); 
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFAuditPool::init(){
		SetAttribute(atr_SpawnID,GetParentJDF().GetAttribute(atr_SpawnID));
		return JDFPool::init();
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFProcessRun JDFAuditPool::AddProcessRun(EnumStatus s,const WString & by,const vmAttribute &vmParts){
		JDFProcessRun pr=AddAudit(JDFAudit::AuditType_ProcessRun,by);
		pr.SetStart();
		pr.SetEnd();
		pr.SetEndStatus(s);
		pr.SetPartMapVector(vmParts);

		return pr;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFAudit JDFAuditPool::AddAudit(JDFAudit::EnumAuditType typ,const WString & by){
		JDFAudit l=AppendElement(JDFAudit::AuditTypeString(typ));
		l.init();
		if(!by.empty()){
			l.SetAuthor(by);
		}
		JDFNode r=GetJDFRoot();
		if(r.HasAttribute(atr_SpawnID)){
			l.SetSpawnID(r.GetSpawnID());
		}
		
		return l;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* Set attribute rRefs
	*@param vWString value: the value to set the attribute to
	*/
	void JDFAuditPool::SetrRefs(vWString value){
		SetAttribute(atr_rRefs,value);
	};
	
	/**
	* Get string attribute rRefs
	* @return vWString the vaue of the attribute 
	*/
	vWString JDFAuditPool::GetrRefs() const {
		return GetAttribute(atr_rRefs);
	};
	
	/**
	* Typesafe attribute validation of rRefs
	* @param EnumValidationLevel level validation level
	* @return bool true if valid
	*/
	bool JDFAuditPool::ValidrRefs(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRefs,AttributeType_Any,false);
	};
	//////////////////////////////////////////////////////////////////////
	
	
	JDFPhaseTime JDFAuditPool::GetLastPhase(){
		return GetPoolChildGeneric(-1,JDFAudit::AuditTypeString(JDFAudit::AuditType_PhaseTime));
	}
	//////////////////////////////////////////////////////////////////////
	
	
	JDFPhaseTime JDFAuditPool::SetPhase(EnumStatus status, const WString & statusDetails, const vmAttribute & vmParts){
		JDFPhaseTime a=GetLastPhase();
		if(a.isNull()) {
			a=AddPhaseTime(status);
		}else if((a.GetStatus()!=status)||(statusDetails!=a.GetStatusDetails())){
			a.SetEnd();
			a=AddPhaseTime(status);
			if(!statusDetails.empty()) 
				a.SetStatusDetails(statusDetails);
		}else{
			// no change but keep stop time
			a.SetEnd();
			return a;
		}
		a.SetPartMapVector(vmParts);
		return a;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFSpawned JDFAuditPool::AddSpawned(JDFNode spawned, const vWString & rRefsRO, const vWString & rRefsRW, const WString & by,const vmAttribute & vmParts){
		JDFSpawned a=AddAudit(JDFAudit::AuditType_Spawned,by);
		a.SetAttribute(atr_jRef,spawned.GetID());
		WString ms;
		if(!rRefsRO.empty()){
			ms.SetvString(rRefsRO);
			a.SetAttribute(atr_rRefsROCopied,ms);
		}
		if(!rRefsRW.empty()){
			ms.SetvString(rRefsRW);
			a.SetAttribute(atr_rRefsRWCopied,ms);
		}
		a.SetPartMapVector(vmParts);
		
		return a;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFMerged JDFAuditPool::AddMerged(JDFNode merged, const vWString & rRefsOverwritten,const WString & by,const vmAttribute &vmParts){
		JDFAudit a=AddAudit(JDFAudit::AuditType_Merged,by);
		a.SetAttribute(atr_jRef,merged.GetID());
		if(!rRefsOverwritten.empty()){
			WString ms;
			ms.SetvString(rRefsOverwritten);
			a.SetAttribute(atr_rRefsOverwritten,ms);
		}
		a.SetPartMapVector(vmParts);
		
		return a;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFAudit JDFAuditPool::GetAudit(int index, JDFAudit::EnumAuditType typ,const mAttribute &mAttributes)const{
		vElement v=GetAudits(typ,mAttributes);
		if(index<0) 
			index=v.size()+index;
		if((index>=v.size())||(index<0)) 
			return JDFAudit();
		
		return v[index];
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFNotification JDFAuditPool::AddNotification(JDFNotification::EnumClass severity,const WString & by,const vmAttribute &vmParts){
		JDFNotification l=AddAudit(JDFAudit::AuditType_Notification,by);
		l.SetClass(severity);
		l.SetPartMapVector(vmParts);
		return l;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFPhaseTime JDFAuditPool::AddPhaseTime(EnumStatus phase,const WString & by,const vmAttribute &vmParts){
		JDFPhaseTime l=AddAudit(JDFAudit::AuditType_PhaseTime,by);
		l.SetStatus(phase);
		l.SetStart();
		l.SetEnd();
		l.SetPartMapVector(vmParts);
		
		return l;
	}
	
	
	//////////////////////////////////////////////////////////////////////
	
	JDFCreated JDFAuditPool::AddCreated(const WString & by, JDFElement createdElem){
		JDFCreated created= AddAudit(JDFAudit::AuditType_Created,by);
		if(createdElem!=0){
			WString id=createdElem.GetID();
			if(id.empty()&&(createdElem.IsResource()||createdElem.IsJDFNode())){
				id=createdElem.AppendAnchor();
				created.Setref(id);
			}
		}
		return created;
	}; 
	
	//////////////////////////////////////////////////////////////////////
	
	JDFModified JDFAuditPool::AddModified(const WString & by, JDFElement modifiedElem){
		JDFModified modified=AddAudit(JDFAudit::AuditType_Modified,by);
		if(modifiedElem!=0){
			WString id=modifiedElem.GetID();
			if(id.empty()&&(modifiedElem.IsResource()||modifiedElem.IsJDFNode())){
				id=modifiedElem.AppendAnchor();
				modified.SetjRef(id);
			}
		}
		return modified;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFResourceAudit JDFAuditPool::AddResourceAudit(const WString & by){
		return AddAudit(JDFAudit::AuditType_ResourceAudit,by);
	};
	
	//////////////////////////////////////////////////////////////////////
	WString JDFAuditPool::OptionalElements()const{
		return JDFPool::OptionalElements()+JDFAudit().AuditTypeString().substr(7);
	};
	
	//////////////////////////////////////////////////////////////////////
	
	vWString JDFAuditPool::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		vWString vAtts;
		int n=0;
		if(!ValidrRefs(level)) {
			vAtts.push_back(atr_rRefs);
			if(++n>=nMax) 
				return vAtts;
		};
		return vAtts;
	};
	
	
	//////////////////////////////////////////////////////////////////////
	
	vWString JDFAuditPool::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFPool::GetInvalidElements(level, bIgnorePrivate, nMax);
		int n=vElem.size();
		if(n>=nMax) 
			return vElem;
		
		nElem=NumChildElements(elm_Created);
		for(i=0;i<nElem;i++){
			JDFCreated child=GetElement(elm_Created,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Created);
				if (++n>=nMax) 
					return vElem;
			};
		}
		
		nElem=NumChildElements(elm_Modified);
		for(i=0;i<nElem;i++){
			JDFModified child=GetElement(elm_Modified,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Modified);
				if (++n>=nMax) return vElem;
			};
		}
		
		nElem=NumChildElements(elm_Spawned);
		for(i=0;i<nElem;i++){
			JDFSpawned child=GetElement(elm_Spawned,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Spawned);
				if (++n>=nMax) 
					return vElem;
			};
		}
		
		nElem=NumChildElements(elm_Merged);
		for(i=0;i<nElem;i++){
			JDFMerged child=GetElement(elm_Merged,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Merged);
				if (++n>=nMax) 
					return vElem;
			};
		}
		
		nElem=NumChildElements(elm_Notification);
		for(i=0;i<nElem;i++){
			JDFNotification child=GetElement(elm_Notification,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Notification);
				if (++n>=nMax) 
					return vElem;
			};
		}
		
		nElem=NumChildElements(elm_PhaseTime);
		for(i=0;i<nElem;i++){
			JDFPhaseTime child=GetElement(elm_PhaseTime,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_PhaseTime);
				if (++n>=nMax) 
					return vElem;
			};
		}
		
		nElem=NumChildElements(elm_ResourceAudit);
		for(i=0;i<nElem;i++){
			JDFResourceAudit child=GetElement(elm_ResourceAudit,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_ResourceAudit);
				if (++n>=nMax)
					return vElem;
			};
		}
		
		nElem=NumChildElements(elm_ProcessRun);
		for(i=0;i<nElem;i++){
			JDFProcessRun child=GetElement(elm_ProcessRun,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_ProcessRun);
				if (++n>=nMax) 
					return vElem;
			};
		}
		
		
		if(level>=ValidationLevel_Complete)vElem.AppendUnique(GetMissingElements(nMax));
		vElem.AppendUnique(GetUnknownElements(bIgnorePrivate,nMax));
		return vElem;
	};
		
	/**
	definition of optional attributes in the JDF namespace
	*/
	WString JDFAuditPool::OptionalAttributes()const{
		return JDFPool::OptionalAttributes()+L",rRefs";
	};
	/**
	* definition of the allowed node names for elements of this type
	* @return comma separated list of valid node names, * if any
	*/
	WString JDFAuditPool::ValidNodeNames()const{
		return elm_AuditPool;
	};
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	
	vElement JDFAuditPool::GetLinkedResources(const mAttribute &mResAtt, bool bFollowRefs)const{
		vWString refs=GetHRefs();
		refs.Unify();
		vElement v;
		for(int i=0;i<refs.size();i++){
			JDFResource r=GetTarget(refs[i]);
			if(r.IncludesAttributes(mResAtt)) {
				v.push_back(r);
				if(bFollowRefs){
					v.AppendUnique(r.GetvHRefRes(bFollowRefs));
				}
			}
		}
		return v;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	
	vElement JDFAuditPool::GetAudits(JDFAudit::EnumAuditType typ,const mAttribute&mAttributes)const{
		WString s=WString::star;
		if (typ!=JDFAudit::AuditType_Unknown)
			s=JDFAudit::AuditTypeString(typ);
		
		vElement v=GetPoolChildren(s);
		for(int i=v.size()-1;i>=0;i--){
			// remove known comments - this would be aught in the next check but we avoid the exception
			if(JDFElement(v[i]).IsComment()){ 
				v.erase(v.begin()+i);
				continue;
			}
			
			// cast to an audit and zapp all non audits
			try{
				JDFAudit a=v[i];
				// filter for attributes if applicable
				if(!a.IncludesAttributes(mAttributes,true)){
					v.erase(v.begin()+i);
					continue;
				}
			}catch (JDFException e){
				v.erase(v.begin()+i);
				continue;
			}
		}
		return v;
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////

	vElement JDFAuditPool::GetPoolChildren(const WString & name, const mAttribute&mAttrib)const{
		return GetPoolChildrenGeneric(name,mAttrib);
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	
	void JDFAuditPool::AppendUnique(const JDFAudit & p){
		JDFPool::AppendUniqueGeneric(p);
	}
	//////////////////////////////////////////////////////////////////////
	
	void JDFAuditPool::AppendUnique(const JDFAuditPool & p){
		vElement v=GetPoolChildren();
		vElement vp=p.GetPoolChildren();
		for(int i=0;i<vp.size();i++){
			if(!v.hasElement(vp[i])) 
				CopyElement(vp[i]);
		}
	}

	//////////////////////////////////////////////////////////////////////
	
	void JDFAuditPool::CleanUpMerge(JDFNode::EnumCleanUpMerge cleanPolicy, const WString& spawnID){
		if(cleanPolicy!=JDFNode::CleanUpMerge_None){
			vElement vMerged;
			vElement vSpawned;
			
			if(spawnID.empty()){
				vMerged=GetAudits(JDFAudit::AuditType_Merged);
				vSpawned=GetAudits(JDFAudit::AuditType_Spawned);
			}else{
				mAttribute mSpawnID;
				mSpawnID.AddPair(atr_MergeID,spawnID);
				JDFAudit a=GetAudit(0,JDFAudit::AuditType_Merged,mSpawnID);
				if(!a.isNull())
					vMerged.push_back(a);
				mSpawnID.clear();
				mSpawnID.AddPair(atr_NewSpawnID,spawnID);
				a=GetAudit(0,JDFAudit::AuditType_Spawned,mSpawnID);
				if(!a.isNull())
					vSpawned.push_back(a);
			}
			
			for(int i=vMerged.size()-1;i>=0;i--){
				JDFMerged merged=vMerged[i];
				WString mergeID=merged.GetMergeID();
				for(int j=vSpawned.size()-1;j>=0;j--){
					JDFSpawned spawned=vSpawned[j];
					if(spawned.GetNewSpawnID()==mergeID){
						
						if(cleanPolicy==JDFNode::CleanUpMerge_RemoveAll){
							spawned.DeleteNode();
							merged.DeleteNode();
							vSpawned.erase(vSpawned.begin()+j);
						}else if(cleanPolicy==JDFNode::CleanUpMerge_RemoverRefs){
							spawned.RemoveAttribute(atr_rRefsRWCopied);
							spawned.RemoveAttribute(atr_rRefsROCopied);
							merged.RemoveAttribute(atr_rRefsOverwritten);							
						}else{
							// never get here
							throw JDFException(L"JDFNode::CleanUpMerge:: illegal cleanPolicy enumeration: "+(int)cleanPolicy);
						}
					}
				}
			}
		}
	}
	
	//////////////////////////////////////////////////////////////////////
}

