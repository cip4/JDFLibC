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
// created before 19.Jan.2000
//
// JDFResourceLink.cpp: implementation of the JDFResourceLink class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFResource.h"
#include "JDFResourceLink.h"
#include "JDFPartAmount.h"
#include "JDFResourceLinkPool.h"
#include "JDFResourcePool.h"
#include "JDFPart.h"
#include "JDFAuditPool.h"
#include "JDFAmountPool.h"
#include "JDFFactory.h"
#include "JDFNode.h"
#include "jdf/wrappercore/XMLDoc.h"

using namespace std;
namespace JDF{
	
	//////////////////////////////////////////////////////////////////////
	// Construction/Destruction
	//////////////////////////////////////////////////////////////////////
	
	JDFResourceLink& JDFResourceLink::operator =(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct)) 
			throw JDFException(L"Invalid constructor for JDFResourceLink: "+other.GetNodeName()); 
		return *this;
	};
	
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::IsAbstract()const{
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::init()
	{
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::SetTarget(const JDFResource& partLeaf)
	{
		if(partLeaf.IsResourceElement())
			throw new JDFException("attempting to link to a resource subelement");

		AppendHRef(partLeaf.GetResourceRoot(),atr_rRef);
		if(!partLeaf.IsResourceRoot()){
			RemoveChildren(elm_Part);
			mAttribute mPart=partLeaf.GetPartMap();
			if(!mPart.empty()){
				JDFElement part=AppendPart();
				part.SetAttributes(mPart);
			}
		}
		return true;
	}
	
	
	//////////////////////////////////////////////////////////////////////

	bool JDFResourceLink::HasAmountPoolAttribute(const WString & attrib,const WString & nameSpaceURI, const mAttribute& mPart)const{
		if(mPart.empty()||!HasChildElement(elm_AmountPool)){
			return HasAttribute(attrib,nameSpaceURI);
		}else{
			return GetAmountPool().GetPartAmount(mPart).HasAttribute(attrib,nameSpaceURI);
		}
	}

	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFResourceLink::GetAmountPoolAttribute(const WString & attrib,const WString & nameSpaceURI, const mAttribute& mPart)const{
		if(mPart.empty()||!HasChildElement(elm_AmountPool)){
			return GetAttribute(attrib,nameSpaceURI);
		}
        //want a map but already in a partamount - snafu 
        if(GetLocalName()==elm_PartAmount)
        {
            throw new JDFException(L"JDFResourceLinkPool.getAmountPoolAttribute: calling method on PartAmount object");
        }
        // default to attribute if no amountpool
        JDFAmountPool amountPool = GetAmountPool();
		if (amountPool.isNull())
        {
            return GetAttribute(attrib, nameSpaceURI);
        }
        JDFPartAmount pa = amountPool.GetPartAmount(mPart);
		WString ret = WString::emptyStr;
        if(!pa.isNull())
			ret = pa.GetAttribute(attrib, nameSpaceURI);
		if (ret.empty())
			return GetAttribute(attrib, nameSpaceURI);
		return ret;
		
	}
	//////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetAmountPoolAttribute(const WString & attrib,const WString & value,const WString & nameSpaceURI, const mAttribute& mPart){
		// ideally the method would be hidden in PartAmount
		if(mPart.isEmpty())
		{
			SetAttribute(attrib, value, nameSpaceURI);
			return;
		}
		if(GetLocalName()==elm_PartAmount)
		{
			throw new JDFException(L"JDFResourceLinkPool.setAmountPoolAttribute: calling method on PartAmount object");
		}

		vmAttribute v;
		v.push_back(mPart);
		SetAmountPoolAttribute(attrib, value, nameSpaceURI, v);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetAmountPoolAttribute(const WString & attrib,const WString & value,const WString & nameSpaceURI, const vmAttribute& vPart)
	{
		// ideally the method would be hidden in PartAmount
		if(vPart.empty())
		{
			SetAttribute(attrib, value, nameSpaceURI);
			return;
		}
		RemoveAttribute(attrib, nameSpaceURI); // either in the pool or the link, not both
        JDFAmountPool ap=GetCreateAmountPool();
        JDFPartAmount pa0=JDFPartAmount();
        for(int i=0;i<vPart.size();i++)
        {
            JDFAttributeMap map = vPart[i];
			JDFPartAmount pa=ap.GetPartAmount(map);
			if(!pa.isNull())
            {
                if(!pa0.isNull() && pa!=pa0)
                    throw JDFException("inconsistent partamounts");
                pa0=pa;
            }
        }
        if(pa0.isNull())
			pa0=ap.AppendPartAmount(vPart);
        pa0.SetPartMapVector(vPart);    
		pa0.SetAttribute(attrib, value, nameSpaceURI);
	}

	//////////////////////////////////////////////////////////////////////

	JDFResource JDFResourceLink::GetLinkRoot()const{
		
    	if(GetLocalName()==elm_PartAmount)
			return JDFResource::DefJDFResource;
		JDFResource r=JDFElement::GetLinkRoot();
		if(r.GetNodeName()!=GetLinkedResourceName())
			return JDFResource::DefJDFResource;
		return r;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFResource JDFResourceLink::GetTarget()const{
		vElement v=GetTargetVector();
		return v.GetCommonAncestor();		
	}
	
	//////////////////////////////////////////////////////////////////////
	
	vElement JDFResourceLink::GetTargetVector(int nMax)const{
		vElement v;
		if(throwNull())
			return v;
		
		// split it into leaves 
		// 150802 changed GetResourcePartMapVector to GetPartMapVector
		vmAttribute vmParts=GetPartMapVector();
		return GetMapTargetVector(vmParts,nMax);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	vElement JDFResourceLink::GetMapTargetVector(vmAttribute vmParts, int nMax)const{
		vElement v;
		// get the resource root
		JDFResource resRoot=GetLinkRoot();
		if(resRoot.isNull())
			return v;
		if(nMax==-1) // for the >=
			nMax=0x4000000; // this is easily big enough...

		// get the value of PartUsage
		JDFResource::EnumPartUsage partUsage=resRoot.GetPartUsage();

		// incomplete resources are implied to be implicitly partitioned
		if((partUsage!=JDFResource::PartUsage_Implicit)&&(resRoot.GetStatus()==JDFResource::Status_Incomplete)){
			partUsage=JDFResource::PartUsage_Implicit;
		}

		if(partUsage==JDFResource::PartUsage_Implicit){
			vmParts.ReduceKey(resRoot.GetPartIDKeys());
		}
		
		if(vmParts.empty()){
			v.push_back(resRoot);
		}else{
			for(int i=0;i<vmParts.size();i++){
				vElement vr=resRoot.GetPartitionVector(vmParts[i],partUsage);
				if(!vr.empty()){
					v.insert(v.end(),vr.begin(),vr.end());
					// we have enough!
					if(v.size()>=nMax){
						break;
					}
				}				
			}
		}		
		return v;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::ReduceParts(){
		vmAttribute vParts=GetPartMapVector();
		if(vParts.empty()) // nothing to do
			return;
		
		vmAttribute vReducedParts=GetLinkRoot().ReducePartVector(vParts);
		
		if(vParts!=vReducedParts){
			SetPartMapVector(vReducedParts);
		}
		
	}
	//////////////////////////////////////////////////////////////////////

	void JDFResourceLink::ExpandTarget(bool bForce) const{
		JDFResource r=GetLinkRoot();
		JDFAmountPool ap=GetAmountPool();
		vmAttribute apParts=ap.GetPartMapVector();
		for(int i=0;i<apParts.size();i++)
			r.GetCreatePartition(apParts[i]);

		// also loop over parts for partusage explicit
		if(r.GetPartUsage()==JDFResource::PartUsage_Explicit||bForce){
			apParts=GetPartMapVector();
			for(int i=0;i<apParts.size();i++)
				r.GetCreatePartition(apParts[i]);
		}

	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::IsResourceSelected (const JDFResource &ResourceToCheck)const{
		// For the decision, compare the leaves of the Resource with the Leaves pointed to by the 
		// resource link. If all leaves of the Resource are pointed to by the ResourceLink, then the 
		// ResourceLink selects the Resource (partition). This method checks if the leaves represented by the
		// Resource are a subset of the leaves represented by the ResourceLink
		bool b_ResurceIsSelected = false;
		
		// Get the resource leaves from resource and resource link
		JDF::vElement ResourceLeavesFromResource  = ResourceToCheck.GetLeaves();
		JDF::vElement ResourceLeavesFromLink      = GetTargetVector();
		
		// number of resources found
		const int i_NoResourceLeavesFromResource  = ResourceLeavesFromResource.size();
		const int i_NoResourceLeavesFromLink      = ResourceLeavesFromLink.size();
		
		// compare Resource Vectors if they contain the same Resources (here ResourceLeaves) Ordering
		// of verctors is not important
		// Note: a method vElement::IsSubSet(vElement) would help here; the following is an implementation
		// for this
		
		int i_CurrentLeafFromResource = 0;
		int i_CurrentLeafFromLink = 0;
		
		// look if every Resource leaf from the ResourceLeavesFromResource is in the ResourceLeavesFromLink
		// vector
		bool b_SelectionIsPossible = true;
		while (b_SelectionIsPossible && i_CurrentLeafFromResource < i_NoResourceLeavesFromResource)
		{
			// Get ResourceLeaf from Resource Vector to compare
			JDF::JDFResource currentLeafFromResource = ResourceLeavesFromResource[i_CurrentLeafFromResource];
			
			// compare with ResourceLeaf in ResourceLink vector till the Resource is found
			// iterate the vector with leaves from ResourceLinks
			bool b_ResourceFoundInLink = false;
			while(!b_ResourceFoundInLink && i_CurrentLeafFromLink < i_NoResourceLeavesFromLink)
			{
				JDF::JDFResource currentLeafFromLink = ResourceLeavesFromLink[i_CurrentLeafFromLink];
				b_ResourceFoundInLink = (currentLeafFromResource == currentLeafFromLink);
				i_CurrentLeafFromLink++;
			};
			
			// if value is false, one partition is not selected => whole resource is not selected
			b_SelectionIsPossible = b_ResourceFoundInLink;
			i_CurrentLeafFromResource++;
		}
		
		b_ResurceIsSelected = b_SelectionIsPossible;
		
		return b_ResurceIsSelected;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	vmAttribute JDFResourceLink::GetResourcePartMapVector()const{
		vmAttribute vMap;
		vResource v=GetTargetVector();
		for(int i=0;i<v.size();i++){
			vMap.push_back(JDFResource(v.at(i)).GetPartMap());
		}
		return vMap;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	
	bool JDFResourceLink::IsValid(EnumValidationLevel level)const{
		if(level<=ValidationLevel_Construct) {
			if(level<=ValidationLevel_None) 
				return true;
			
			if(isNull()) 
				return true;
		}
		
		bool b=JDFElement::IsValid(level);
		if(!b) 
			return false;
		WString localName=GetLocalName();
		if(localName.rightStr(4).compare(atr_Link) && (localName!=elm_ResourceInfo)) {
			return false;
		}
		if((level!=ValidationLevel_Complete) && (level!=ValidationLevel_RecursiveComplete) && (level!=ValidationLevel_RecursiveIncomplete))
			return true;
		
		if(!ValidResourcePosition())
			return false;

		vElement vRes=GetTargetVector();
		if(vRes.empty()&&((level==ValidationLevel_Complete)||(level==ValidationLevel_RecursiveComplete))){
			// if any partition points to nirvana and we are validating complete, the entire resource is invalid
			return false;
		}

		for(int iRes=0;iRes<vRes.size();iRes++){
			JDFResource r=vRes.at(iRes);
			// reslinks that point to nothing may be valid
			
			// but they certainly aren't valid if they point to the wrong resource
			if(GetNodeName()!=r.GetLinkString()) 
				return false;
									
			if(level>=ValidationLevel_RecursiveIncomplete){
				EnumValidationLevel valDown=(level==ValidationLevel_RecursiveIncomplete) ? ValidationLevel_Incomplete : ValidationLevel_Complete;
				
				JDFFactory factory(r);
				JDFElement & refR=factory.GetRef();
				if(!refR.IsValid(valDown))
					return false;
			}
		}
		return true;
	}
	///////////////////////////////////////////////////////////////////////

	bool JDFResourceLink::ValidResourcePosition()const
	{
		return JDFElement::ValidResourcePosition(GetLinkRoot());
	}

	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::IsLocal()const{
		JDFElement linkParent=GetParentJDF();
		JDFElement resParent=GetTarget().GetParentJDF();
		return resParent==linkParent;
	}
	//////////////////////////////////////////////////////////////////////
	
	
	vElement JDFResourceLink::GetParts()const{
		return GetChildElementVector(elm_Part);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetPartition(JDFResource::EnumPartIDKey key, const WString& value){
		while(HasChildElement(elm_Part))
			RemoveChild(elm_Part);
		JDFPart part=GetCreatePart();
		part.SetAttribute(JDFResource::PartIDKeyString(key),value);
		
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::IsExecutable(const mAttribute& partMap,bool bCheckChildren)const{
		if(!HasResourcePartMap(partMap)) 
			return false;
		
		vElement leaves;
		
		
		bool bExec=false;
		
		if(bCheckChildren){ // check for all child partitions of a resource and calculate availability from those
			vElement leaves2=GetTargetVector();
			for(int i=0;i<leaves2.size();i++){
				JDFResource p=leaves2.at(i);
				if(p==0) 
					continue;
				vElement targetVector=p.GetLeaves();
				leaves.insert(leaves.end(),targetVector.begin(),targetVector.end());
			}
		}else{ // calculate availability directly
			leaves=GetTargetVector();
		}
		
		for(int i=0;i<leaves.size();i++){
			JDFResource leaf=leaves[i];
			if(!partMap.empty()){
				if(!partMap.OverlapMap(leaf.GetPartMap())) 
					continue;
			}
			JDFResource::EnumStatus status=leaf.GetStatus(true);
			if(status==JDFResource::Status_InUse) 
				return false;
			
			if(GetUsage()==Usage_Input){
				if(GetDraftOK()){
					bExec=((status==JDFResource::Status_Available)||(status==JDFResource::Status_Draft));
				}else{
					bExec =(status==JDFResource::Status_Available);
				}
				if(!bExec){
					// tbd pipe handling
				}
			}else{
				bExec= status>JDFResource::Status_Incomplete;
			}
			// any leaf not executable --> the whole thing is not executable
			if(!bExec) 
				return false;
		}		
		return true;
	}
	
	//////////////////////////////////////////////////////////////////////	
	
	bool JDFResourceLink::HasResourcePartMap(const mAttribute& partMap,bool bCheckResource)const{
		if(throwNull()) 
			return false;
		
		vmAttribute vPart;
		if(bCheckResource){
			vPart=GetResourcePartMapVector();
		}else{
			if(partMap.empty()){ // not checking the reource and checking against the root partmap --> always true
				return true;
			}

			vPart=GetPartMapVector();
		}
		int siz=vPart.size();
        
	        if(partMap.empty() && vPart.empty())
	        {
	            return true;
	        }

		bool bImplicit=GetLinkRoot().GetPartUsage()==JDFResource::PartUsage_Implicit;

		if(bImplicit){
            if (siz == 0){ // the resourcelink has no parts and therefore always points at anything
                return true;
            }

			for(int i=0;i<siz;i++){
				if(vPart[i].OverlapMap(partMap)) 
					return true;
			}
		}else{ // explicit
            if ((siz == 0) && (!bCheckResource)){ // the link has no parts and we don't know the details of the resource --> assume that it fits
                return true;
            }
			for(int i=0;i<siz;i++){
				// RP 050120 swap of vPart[i] and partmap
				if(partMap.SubMap(vPart[i])) 
					return true;
			}
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFResourceLink::GetProcessUsage()const{
		return GetAttribute(atr_ProcessUsage);
	}
	//////////////////////////////////////////////////////////////////////
	WString JDFResourceLink::GetLinkedResourceName()const{
		return GetNodeName().leftStr(-4);
	}
	//////////////////////////////////////////////////////////////////////
	WString JDFResourceLink::GetNamedProcessUsage()const{
		WString s=GetProcessUsage();
		// 030502 RP modified to default tx xxx:Input / xxx:Output respectively
		if(s.empty()) {
			// 200602 RP need the string type - don't cycle to and from enum type...
			s=GetAttribute(atr_Usage);
		}
		s=GetLinkedResourceName()+WString::colon+s;
		return s;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetProcessUsage(const WString &value){
		if (value != "Unknown")
			SetAttribute(atr_ProcessUsage,value);
	};
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::IsPhysical() const{
		if(JDFResource::PhysicalResources().HasToken(GetLinkedResourceName(),WString::comma))
			return true;
		return GetLinkRoot().IsPhysical();
	};
	
	//////////////////////////////////////////////////////////////////////
	
	vWString JDFResourceLink::GetInvalidAttributes(EnumValidationLevel level, bool bIgnorePrivate, int nMax)const {
		
		vWString vAtts=JDFElement::GetInvalidAttributes(level, bIgnorePrivate, nMax);
		
		int n=vAtts.size();
		
		if(n>=nMax) 
			return vAtts;
		
		if(!ValidCombinedProcessType(level)) {
			vAtts.push_back(atr_CombinedProcessType);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidCombinedProcessIndex(level)) {
			vAtts.push_back(atr_CombinedProcessIndex);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidDraftOK(level)) {
			vAtts.push_back(atr_DraftOK);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidMinStatus(level)) {
			vAtts.push_back(atr_MinStatus);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidMinLateStatus(level)) {
			vAtts.push_back(atr_MinLateStatus);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPipeProtocol(level)) {
			vAtts.push_back(atr_PipeProtocol);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidPipeURL(level)) {
			vAtts.push_back(atr_PipeURL);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidProcessUsage(level)) {
			vAtts.push_back(atr_ProcessUsage);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidrRef(level)) {
			vAtts.push_back(atr_rRef);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidrSubRef(level)) {
			vAtts.push_back(atr_rSubRef);
			if(++n>=nMax) 
				return vAtts;
		};
		if(!ValidUsage(level)) {
			vAtts.push_back(atr_Usage);
			if(++n>=nMax) 
				return vAtts;
		};
		
		
		if(IsPhysical() || (GetLocalName()==elm_PartAmount)){
			if(!ValidAmount(level)) {
				vAtts.push_back(atr_Amount);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidMinAmount(level)) {
				vAtts.push_back(atr_MinAmount);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidMaxAmount(level)) {
				vAtts.push_back(atr_MaxAmount);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidActualAmount(level)) {
				vAtts.push_back(atr_ActualAmount);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidPipePause(level)) {
				vAtts.push_back(atr_PipePause);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidPipeResume(level)) {
				vAtts.push_back(atr_PipeResume);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidRemotePipeEndPause(level)) {
				vAtts.push_back(atr_RemotePipeEndPause);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidRemotePipeEndResume(level)) {
				vAtts.push_back(atr_RemotePipeEndResume);
				if(++n>=nMax) 
					return vAtts;
			};
			if(!ValidTransformation(level)) {
				vAtts.push_back(atr_Transformation);
				if(++n>=nMax) 
					return vAtts;
			}
			if(!ValidOrientation(level)) {
				vAtts.push_back(atr_Orientation);
				if(++n>=nMax) 
					return vAtts;
			}
		}
		else if(GetLinkRoot().GetClass()==JDFResource::Class_Implementation || (GetLocalName()==elm_PartAmount))
		{
			if(!ValidDuration(level)) {
				vAtts.push_back(atr_Duration);
				if(++n>=nMax) 
					return vAtts;
			}
			if(!ValidRecommendation(level)) {
				vAtts.push_back(atr_Recommendation);
				if(++n>=nMax) 
					return vAtts;
			}
			if(!ValidStart(level)) {
				vAtts.push_back(atr_Start);
				if(++n>=nMax) 
					return vAtts;
			}
			if(!ValidStartOffset(level)) {
				vAtts.push_back(atr_StartOffset);
				if(++n>=nMax) 
					return vAtts;
			}
		}
		
		return vAtts;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	vWString JDFResourceLink::GetInvalidElements(EnumValidationLevel level, bool bIgnorePrivate, int nMax) const{
		int nElem=0;
		int i=0;
		vWString vElem=JDFElement::GetInvalidElements(level, bIgnorePrivate, nMax);
		
		int n=vElem.size();
		if(n>=nMax) 
			return vElem;
		
		nElem=NumChildElements(elm_Part);
		for(i=0;i<nElem;i++){
			JDFPart child=GetElement(elm_Part,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_Part);
				if (++n>=nMax) 
					return vElem;
			};
		}
		
		nElem=NumChildElements(elm_AmountPool);
		if(nElem>1){
			vElem.push_back(elm_AmountPool);
			if (++n>=nMax) 
				return vElem;
		}
		
		for(i=0;i<nElem;i++){
			JDFAmountPool child=GetElement(elm_AmountPool,WString::emptyStr,i);
			if (!child.IsValid(level)) {
				vElem.push_back(elm_AmountPool);
				if (++n>=nMax) 
					return vElem;
			};
		}
		
		return vElem;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFResourceLinkPool JDFResourceLink::GetPool() const{
		return GetParentNode();
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFResourceLinkPool JDFResourceLink::GetResourceLinkPool() const{
		return GetParentNode();
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFPart JDFResourceLink::AppendPart(){
		JDFPart e=AppendElement(elm_Part);
		e.init();
		return e;
	};
	//////////////////////////////////////////////////////////////////////
	
	JDFPart JDFResourceLink::GetCreatePart(int iSkip){
		JDFPart e=GetCreateElement(elm_Part,WString::emptyStr,iSkip);
		e.init();
		return e;
	};
	
	///////////////////////////////////////////////////////////////////////
	JDFPart JDFResourceLink::GetPart( int iSkip)const{
		return GetElement(elm_Part,WString::emptyStr,iSkip);
	};
	
	///////////////////////////////////////////////////////////////////////
	JDFAmountPool  JDFResourceLink::GetCreateAmountPool (){
		JDFAmountPool  e=GetCreateElement(elm_AmountPool);
		e.init();
		return e;
	};
	/////////////////////////////////////////////////////////////////////
	
	JDFAmountPool  JDFResourceLink::AppendAmountPool (){
		JDFAmountPool  e=GetCreateElement(elm_AmountPool);
		e.init();
		return e;
	};
	
	///////////////////////////////////////////////////////////////////////
	
	JDFAmountPool  JDFResourceLink::GetAmountPool()const {
		return GetElement(elm_AmountPool);
	}
	
	///////////////////////////////////////////////////////////////////////
	
	vmAttribute JDFResourceLink::GetPartMapVector()const{
		return JDFElement::GetPartMapVector();
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetPartMapVector(const vmAttribute & vParts){
		JDFElement::SetPartMapVector(vParts);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetPartMap(const mAttribute & mPart){
		JDFElement::SetPartMap(mPart);
	}
	
	//////////////////////////////////////////////////////////////////////
	void JDFResourceLink::RemovePartMap(const mAttribute & mPart){
		JDFElement::RemovePartMap(mPart);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::HasPartMap(const mAttribute & mPart){
		return JDFElement::HasPartMap(mPart);
	}
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFResourceLink::OptionalAttributes()const{
		
		WString atts=JDFElement::OptionalAttributes()+L",CombinedProcessIndex,CombinedProcessType,DraftOK,MinStatus,MinLateStatus,PipeProtocol,PipeURL,ProcessUsage,rSubRef,PipePartIDKeys";
		
		if(IsPhysical()){
			atts+=",Amount,MinAmount,MaxAmount,ActualAmount,Transformation,Orientation,PipePause,PipeResume,RemotePipeEndPause,RemotePipeEndResume";
		}else if(GetLinkRoot().GetClass()==JDFResource::Class_Implementation){
			atts+=",Recommendation,Start,StartOffset,Duration";
		}
		
		return atts;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFResourceLink::RequiredAttributes()const{
		return JDFElement::RequiredAttributes()+L",rRef,Usage";
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFResourceLink::OptionalElements()const{
		return JDFElement::OptionalElements()+L",AmountPool,Part";
	}
	
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::ValidCombinedProcessIndex(EnumValidationLevel level) const {
		if(!HasAttribute(atr_CombinedProcessIndex))
			return true;
		bool b=ValidAttribute(atr_CombinedProcessIndex,AttributeType_IntegerList,false);
		if(b&&(level==ValidationLevel_Complete)||(level==ValidationLevel_RecursiveComplete)){
			JDFNode n=GetParentJDF();
			if(!n.IsProcessGroup()&&!n.IsCombined()){
				return false;
			}
			int typeSize=n.GetTypes().size();
			vint v=GetCombinedProcessIndex();
			for(int i=0;i<v.size();i++){
				if(i<0||i>=typeSize)
					return false;
			}
		}
		return b;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::ValidCombinedProcessType(EnumValidationLevel level) const {
		return ValidAttribute(atr_CombinedProcessType,AttributeType_NMTOKEN,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidDraftOK(EnumValidationLevel level) const {
		return ValidAttribute(atr_DraftOK,AttributeType_boolean,false);
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::ValidDuration(EnumValidationLevel level) const {
		return ValidAttribute(atr_Duration,AttributeType_duration,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidMinStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MinStatus,JDFResource::StatusString(),false);
	};

	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidMinLateStatus(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_MinLateStatus,JDFResource::StatusString(),false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidPipeProtocol(EnumValidationLevel level) const {
		return ValidAttribute(atr_PipeProtocol,AttributeType_NMTOKEN,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidPipeURL(EnumValidationLevel level) const {
		return ValidAttribute(atr_PipeURL,AttributeType_URL,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidProcessUsage(EnumValidationLevel level) const {
		return ValidAttribute(atr_ProcessUsage,AttributeType_string,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidrRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_rRef,AttributeType_Any,RequiredLevel(level));
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidUsage(EnumValidationLevel level) const {
		return ValidEnumAttribute(atr_Usage,UsageString(),RequiredLevel(level));
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidOrientation(EnumValidationLevel level) const {
		bool b=ValidEnumAttribute(atr_Orientation,OrientationString(),false);
		b=b && ExclusiveOneOfAttribute(ValidationLevel_Incomplete,atr_Orientation,atr_Transformation);
		return b;
	};
	
	/////////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::ValidTransformation(EnumValidationLevel level) const {
		bool b=ValidAttribute(atr_Transformation,AttributeType_matrix,false);
		b=b && ExclusiveOneOfAttribute(ValidationLevel_Incomplete,atr_Orientation,atr_Transformation);
		return b;	
	};
	
	/////////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::ValidrSubRef(EnumValidationLevel level) const {
		return ValidAttribute(atr_rSubRef,AttributeType_Any,false);
	};
	
	/////////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::ValidAmount(EnumValidationLevel level) const {
		if(HasChildElement(elm_AmountPool)&&HasAttribute(atr_Amount))
			return false;

		WString amount=GetAmountPoolAttribute(atr_Amount,WString::emptyStr,mAttribute::emptyMap);
		if(amount.empty())
			return true;

		bool bRet=ValidAttribute(atr_Amount,AttributeType_double,false);
		if(!bRet)
			return false;
		return GetAmount()>=0;
	};
	/////////////////////////////////////////////////////////////////////////

	bool JDFResourceLink::ValidMinAmount(EnumValidationLevel level) const {
		if(HasChildElement(elm_AmountPool)&&HasAttribute(atr_MinAmount))
			return false;

		WString amount=GetAmountPoolAttribute(atr_MinAmount,WString::emptyStr,mAttribute::emptyMap);
		if(amount.empty())
			return true;

		bool bRet=ValidAttribute(atr_MinAmount,AttributeType_double,false);
		if(!bRet)
			return false;
		return GetMinAmount()>=0;
	};
	/////////////////////////////////////////////////////////////////////////

	bool JDFResourceLink::ValidMaxAmount(EnumValidationLevel level) const {
		if(HasChildElement(elm_AmountPool)&&HasAttribute(atr_MaxAmount))
			return false;

		WString amount=GetAmountPoolAttribute(atr_MaxAmount,WString::emptyStr,mAttribute::emptyMap);
		if(amount.empty())
			return true;

		bool bRet=ValidAttribute(atr_MaxAmount,AttributeType_double,false);
		if(!bRet)
			return false;
		return GetMaxAmount()>=0;
	};
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::ValidActualAmount(EnumValidationLevel level) const {
		if(HasChildElement(elm_AmountPool)&&HasAttribute(atr_ActualAmount))
			return false;

		WString amount=GetAmountPoolAttribute(atr_ActualAmount,WString::emptyStr,mAttribute::emptyMap);
		if(amount.empty())
			return true;

		bool bRet=ValidAttribute(atr_ActualAmount,AttributeType_double,false);
		if(!bRet)
			return false;
		return GetActualAmount()>=0;
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidPipePause(EnumValidationLevel level) const {
		return ValidAttribute(atr_PipePause,AttributeType_double,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidPipeResume(EnumValidationLevel level) const {
		return ValidAttribute(atr_PipeResume,AttributeType_double,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidRecommendation(EnumValidationLevel level) const {
		return ValidAttribute(atr_Recommendation,AttributeType_boolean,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidRemotePipeEndPause(EnumValidationLevel level) const {
		return ValidAttribute(atr_RemotePipeEndPause,AttributeType_double,false);
	};
	//////////////////////////////////////////////////////////////////////
	bool JDFResourceLink::ValidRemotePipeEndResume(EnumValidationLevel level) const {
		return ValidAttribute(atr_RemotePipeEndResume,AttributeType_double,false);
	};
	//////////////////////////////////////////////////////////////////////
	
	
	bool JDFResourceLink::ValidStart(EnumValidationLevel level) const {
		return ValidAttribute(atr_Start,AttributeType_dateTime,false);
	};
	//////////////////////////////////////////////////////////////////////
	
	bool JDFResourceLink::ValidStartOffset(EnumValidationLevel level) const {
		return ValidAttribute(atr_StartOffset,AttributeType_duration,false);
	};
	
	//////////////////////////////////////////////////////////////////////
	const WString& JDFResourceLink::UsageString(){
		static const WString enums=L"Unknown,Input,Output"; 
		return enums;
	};
	//////////////////////////////////////////////////////////////////////
	WString JDFResourceLink::UsageString(EnumUsage value){
		return UsageString().Token(value,WString::comma);
	};
	
	
	//////////////////////////////////////////////////////////////////////

	JDFResource::EnumStatus JDFResourceLink::GetStatus()const{
		return GetTarget().GetStatus();
	}
	
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetStatus(JDFResource::EnumStatus s)const{
		vElement targets=GetTargetVector();
		for(int i=0;i<targets.size();i++){
			JDFResource(targets.at(i)).SetStatus(s);
		}
	};
	
	//////////////////////////////////////////////////////////////////////
	void JDFResourceLink::SetUsage(EnumUsage value){
		SetEnumAttribute(atr_Usage,value,UsageString());
	};
	
	//////////////////////////////////////////////////////////////////////
	JDFResourceLink::EnumUsage JDFResourceLink::GetUsage() const {
		return (JDFResourceLink::EnumUsage) GetEnumAttribute(atr_Usage,UsageString());
	};
	//////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetAmount(double value,const mAttribute&mPart){
		SetAmountPoolAttribute(atr_Amount,value,WString::emptyStr,mPart);
	};
	/////////////////////////////////////////////////////////////////////////
	
	double JDFResourceLink::GetAmount(const mAttribute&mPart) const {
		WString w= GetAmountPoolAttribute(atr_Amount,WString::emptyStr,mPart);
		if(w.empty())
		{
			JDFResource target = GetTarget();
			if (!target.isNull())
			{
				target = target.GetPartition(mPart);
				if (!target.isNull())
					return target.GetAmount();
			}
		}
		else
			return (double)w;

		return -1;
	};
	
	//////////////////////////////////////////////////////////////////////

	void JDFResourceLink::SetMinAmount(double value,const mAttribute&mPart){
		SetAmountPoolAttribute(atr_MinAmount,value,WString::emptyStr,mPart);
	};
	/////////////////////////////////////////////////////////////////////////

	double JDFResourceLink::GetMinAmount(const mAttribute&mPart) const {
		if(!HasAmountPoolAttribute(atr_MinAmount,WString::emptyStr,mPart))
			return GetAmount(mPart);

		return GetAmountPoolAttribute(atr_MinAmount,WString::emptyStr,mPart);
	};

	//////////////////////////////////////////////////////////////////////

	void JDFResourceLink::SetMaxAmount(double value,const mAttribute&mPart){
		SetAmountPoolAttribute(atr_MaxAmount,value,WString::emptyStr,mPart);
	};
	/////////////////////////////////////////////////////////////////////////

	double JDFResourceLink::GetMaxAmount(const mAttribute&mPart) const {
		if(!HasAmountPoolAttribute(atr_MaxAmount,WString::emptyStr,mPart))
			return GetAmount(mPart);

		return GetAmountPoolAttribute(atr_MaxAmount,WString::emptyStr,mPart);
	};

	/////////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetActualAmount(double value,const mAttribute&mPart){
		SetAmountPoolAttribute(atr_ActualAmount,value,WString::emptyStr,mPart);
	};
	/////////////////////////////////////////////////////////////////////////
	
	double JDFResourceLink::GetActualAmount(const mAttribute&mPart) const {
		WString w=GetAmountPoolAttribute(atr_ActualAmount,WString::emptyStr,mPart);
		if(w.empty())
			return -1;
		return w;
	};
	
	//////////////////////////////////////////////////////////////////////
	void JDFResourceLink::SetCombinedProcessIndex(const JDFIntegerList& value){
		SetAttribute(atr_CombinedProcessIndex,value.GetString());
	};
	//////////////////////////////////////////////////////////////////////
	JDFIntegerList JDFResourceLink::GetCombinedProcessIndex() const {
		return GetAttribute(atr_CombinedProcessIndex);
		
	};
	//////////////////////////////////////////////////////////////////////

	void JDFResourceLink::SetCombinedProcessType(const WString& value){
		SetAttribute(atr_CombinedProcessType,value);
	}
	
	WString JDFResourceLink::GetCombinedProcessType() const {
		return GetAttribute(atr_CombinedProcessType);
	}

	//////////////////////////////////////////////////////////////////////////////

	void JDFResourceLink::SetDraftOK(bool value){
		EnumVersion eVer = GetEnumVersion(true);
		if(eVer<Version_1_3)
		{
			SetAttribute(atr_DraftOK,value);
		}
        else if(value) // 1.3 DraftOK=true
        {
			SetMinStatus(JDFResource::Status_Draft);
        }
        else // 1.3 DraftOK=false
        {
			SetMinStatus(GetUsage()==Usage_Output ? JDFResource::Status_Unavailable :JDFResource::Status_Available);            
        }
	}
	
	//////////////////////////////////////////////////////////////////////////////

	bool JDFResourceLink::GetDraftOK() const {
		if(HasAttribute(atr_DraftOK)){
			return GetBoolAttribute(atr_DraftOK,WString::emptyStr,false);
		}else{ // try to infer draftok from the JDF 1.3 MinStatus flag
			JDFResource::EnumStatus status=GetMinStatus();
			if(status==JDFResource::Status_Unknown)
				return false;
			return (int)status<=int(JDFResource::Status_Draft);
		}
	}
	//////////////////////////////////////////////////////////////////////////////

	JDFResource::EnumStatus JDFResourceLink::GetMinStatus() const {
		JDFResource::EnumStatus returnEnum;
		if (HasAttribute(atr_MinStatus))
		{
			returnEnum = (JDFResource::EnumStatus)GetEnumAttribute(atr_MinStatus,JDFResource::StatusString());
		}
		else
		{
			if (GetUsage() == Usage_Output)
				returnEnum = JDFResource::Status_Unavailable;
			else if (GetAttribute(atr_DraftOK) == "true")
				returnEnum = JDFResource::Status_Draft;
			else
				returnEnum = JDFResource::Status_Available;
		}

		return returnEnum;
	}
	//////////////////////////////////////////////////////////////////////////////

	JDFResource::EnumStatus JDFResourceLink::GetMinLateStatus() const {
		if(!HasAttribute(atr_MinLateStatus)){
			return GetMinStatus();
		}
		return (JDFResource::EnumStatus) GetEnumAttribute(atr_MinLateStatus,JDFResource::StatusString());
	}
	//////////////////////////////////////////////////////////////////////////////

	void JDFResourceLink::SetMinStatus(JDFResource::EnumStatus value){
		SetEnumAttribute(atr_MinStatus,value,JDFResource::StatusString());
	};

	//////////////////////////////////////////////////////////////////////////////

	void JDFResourceLink::SetMinLateStatus(JDFResource::EnumStatus value){
		SetEnumAttribute(atr_MinLateStatus,value,JDFResource::StatusString());
	};

	//////////////////////////////////////////////////////////////////////////////
	
	void JDFResourceLink::SetDuration(JDFDuration value){
		SetAttribute(atr_Duration,value.DurationISO());
	}
	
	JDFDuration JDFResourceLink::GetDuration() const {
		return GetAttribute(atr_Duration,WString::emptyStr);
	}
	
	void JDFResourceLink::SetPipeProtocol(const WString& value){
		SetAttribute(atr_PipeProtocol,value);
	}
	
	WString JDFResourceLink::GetPipeProtocol() const {
		if (!HasAttribute(atr_PipeProtocol))
			return GetTarget().GetPipeProtocol();
		return GetAttribute(atr_PipeProtocol);
	}
	
	void JDFResourceLink::SetPipeURL(const WString& value){
		SetAttribute(atr_PipeURL,value);
	};
	
	WString JDFResourceLink::GetPipeURL() const {
		if (!HasAttribute(atr_PipeURL))
			return GetTarget().GetPipeURL();
		return GetAttribute(atr_PipeURL);
	};
	
	void JDFResourceLink::SetrRef(const WString& value){
		SetAttribute(atr_rRef,value);
	}
	
	WString JDFResourceLink::GetrRef() const {
		return GetAttribute(atr_rRef);
	}
	
	void JDFResourceLink::SetrSubRef(const WString& value){
		SetAttribute(atr_rSubRef,value);
	}
	
	WString JDFResourceLink::GetrSubRef() const {
		return GetAttribute(atr_rSubRef);
	}
	
			
	void JDFResourceLink::SetTransformation(JDFMatrix value){
		SetAttribute(atr_Transformation,value);
	}
	
	JDFMatrix JDFResourceLink::GetTransformation() const {
		return GetAttribute(atr_Transformation,WString::emptyStr);
	}

	void JDFResourceLink::SetOrientation(JDFElement::EnumOrientation value){
		SetEnumAttribute(atr_Orientation,value,OrientationString());
	};
	
	JDFElement::EnumOrientation JDFResourceLink::GetOrientation() const {
		return (JDFElement::EnumOrientation) GetEnumAttribute(atr_Orientation,OrientationString());
	};

	void JDFResourceLink::SetPipePause(double value){
		SetAttribute(atr_PipePause,value);
	}
	
	double JDFResourceLink::GetPipePause() const {
		return GetRealAttribute(atr_PipePause);
	}

	void JDFResourceLink::SetPipeResume(double value){
		SetAttribute(atr_PipeResume,value);
	}

	double JDFResourceLink::GetPipeResume() const {
		return GetRealAttribute(atr_PipeResume);
	}				
	
	void JDFResourceLink::SetRecommendation(bool value){
		SetAttribute(atr_Recommendation,value);
	}
	
	bool JDFResourceLink::GetRecommendation() const {
		return GetBoolAttribute(atr_Recommendation,WString::emptyStr,false);
	}
			
	void JDFResourceLink::SetRemotePipeEndPause(double value){
		SetAttribute(atr_RemotePipeEndPause,value);
	}

	double JDFResourceLink::GetRemotePipeEndPause() const {
		return GetRealAttribute(atr_RemotePipeEndPause);
	}

	void JDFResourceLink::SetRemotePipeEndResume(double value){
		SetAttribute(atr_RemotePipeEndResume,value);
	}

	double JDFResourceLink::GetRemotePipeEndResume() const {
		return GetRealAttribute(atr_RemotePipeEndResume);
	}

	void JDFResourceLink::SetStart(JDFDate value){
		SetAttribute(atr_Start,value.DateTimeISO());
	}
	
    JDFDate JDFResourceLink::GetStart() const {
		return GetAttribute(atr_Start,WString::emptyStr);
	}

	void JDFResourceLink::SetStartOffset(JDFDuration value){
		SetAttribute(atr_StartOffset,value.DurationISO());
	}

	JDFDuration JDFResourceLink::GetStartOffset() const {
		return GetAttribute(atr_StartOffset,WString::emptyStr);
	}

	//////////////////////////////////////////////////////////////////////////////

	bool JDFResourceLink::FixVersion(EnumVersion version){
		if(version>=Version_1_3){	 
			if(GetBoolAttribute(atr_DraftOK,WString::emptyStr,false)==true){
				SetMinStatus(JDFResource::Status_Draft);
				RemoveAttribute(atr_DraftOK);
			}
		}else{
			if(HasAttribute(atr_MinStatus)){
				if(!HasAttribute(atr_DraftOK)&&(GetEnumAttribute(atr_MinStatus,JDFResource::StatusString())<=(int)JDFResource::Status_Draft)){
					SetDraftOK(true);
				}
				RemoveAttribute(atr_MinLateStatus);
				RemoveAttribute(atr_MinStatus);
			}else if(HasAttribute(atr_MinLateStatus)){
				RemoveAttribute(atr_MinLateStatus);
			}
		}
		return JDFElement::FixVersion(version);
	}

	//////////////////////////////////////////////////////////////////////////////

	bool JDFResourceLink::overlapsResourcePartMap(JDFAttributeMap partMap)
	{
		if (partMap.isEmpty())
        {
            return true; // speed up...
        }
        
		vmAttribute vPart = GetPartMapVector();
        
        int siz = vPart.empty() ? 0 : vPart.size();
        // if no part, any resource that is linked is valid
        if (siz == 0)
        {
            return true;
        }
        
        for (int i = 0; i < siz; i++)
        {
            if (vPart[i].OverlapMap(partMap))
                return true;
        }
        
        return false;
	}
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////
} // ns JDF