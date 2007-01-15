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
*    Alternately, this acknowledgment mrSubRefay appear in the software itself,
*    if and wherever such third-party acknowledgments normally appear.
*
* 4. The names "CIP4" and "The International Cooperation for the Integration of
*    Processes in  Prepress, Press and Postpress" must
*    not be used to endorse or promote products derived from this
*    software without prior written permission. For written
*    permission, please contact info@cip4.org.
*
* 5. Products derived from this software may not be called "CIP4",
*    nor may "CIP4" appear in their name, without prior writtenrestartProcesses()
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
* SPECIAL, EXEMPLARY, OR CONSEQUENTIrSubRefAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
* USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
* ====================================================================
*
* For more information on The International Cooperation for the
* Integration of Processes in  Prepress, Press and Postpress , please see
* <http://www.cip4.org/>.
*
*/

#include "JDFSpawn.h"
#include "JDFRefElement.h"
#include "JDFDoc.h"
#include "JDFAuditPool.h"
#include "JDFAncestorPool.h"
#include "JDFResourcePool.h"
#include "JDFResourceLinkPool.h"
#include "JDFAncestor.h"
#include "JDFFactory.h"
#include "jdf/lang/VoidSet.h"
#include "jdf/lang/SetWString.h"

namespace JDF{


	JDFSpawn::JDFSpawn(JDFNode& n)
	{
		bSpawnROPartsOnly=true;
		bCopyNodeInfo=true; 
		bCopyCustomerInfo=true;
		bCopyComments=false;
		bFixResources=true;
		node = n;
	}

	////////////////////////////////////////////////////////////////////////////

	JDFDoc JDFSpawn::spawn()
	{
		// need copy in order to fix up 1.3 NodeInfo spawn
		vWString &vRWResources=vRWResources_in;
		vmAttribute vLocalSpawnParts=vSpawnParts;
		vElement vCheck=node.CheckSpawnedResources(vRWResources,vLocalSpawnParts);
		if(!vCheck.empty()){
			WString IDs=L"JDFNode::Spawn: multiply spawned rw resources:";
			for(int i=0;i<vCheck.size();i++){
				IDs+=WString::blank+JDFResource(vCheck[i]).GetAttribute(JDFNode::atr_ID);
			}
			throw JDFException(IDs);
		}

		//create a new jdf document that contains the node to be spawned
		JDFDoc docOut(0);

		JDFNode rootOut=docOut.GetRoot();
		JDFNode thisRoot=node.GetJDFRoot();

		// merge this node into it
		rootOut.MergeNode(node,false);
		// always give large chunk of unique ids for spawned node so that parallel processed ids do not overlap
		WString spawnID=L"Sp"+JDFNode::UniqueID(-666);
		rootOut.SetSpawnID(spawnID);
		rootOut.SetVersion(node.GetVersion(true));

		static WString nodeInfoNonAncestor=L"NodeInfo:Input"; // named process usage		
		vRWResources.AppendUnique(nodeInfoNonAncestor); // the local nodeinfo MUST always be rw

		// get partitions to spawn
		JDFNode spawnParentNode;
		// we want to spawn a partition
		if (!vLocalSpawnParts.empty()){
			spawnParentNode=node;
			// don't copy the whole history along
			rootOut.GetAuditPool().Flush();
			// The AncestorPool of the original JDF contains the appropriate Part elements
			JDFAncestorPool ancpool = docOut.GetJDFRoot().GetAncestorPool();
			vmAttribute preSpawnedParts;
			if (!ancpool.isNull())
			{
				preSpawnedParts = ancpool.GetPartMapVector();
			}

			// 150102 RP add AncestorPool pre spawn part handling
			if(!preSpawnedParts.empty()){
				// allParts is the vector of all parts that the spawned AncestorPool will contain
				vmAttribute allParts;
				for(int psp=0; psp<preSpawnedParts.size();psp++){
					vmAttribute tmpParts=vLocalSpawnParts;
					tmpParts.OverlapMap(preSpawnedParts[psp]);
					allParts.AppendUnique(tmpParts);
				}
				vLocalSpawnParts=allParts;
			}
			// we arrived at a null vector of parts - that ain't no good
			if (vLocalSpawnParts.empty()){
				throw JDFException("JDFNode:Spawn attempting to spawn incompatible partitions");
			}
			// Spawn a complete node -> no partition handling
		}else{
			spawnParentNode=node.GetParentJDF();
			if(spawnParentNode.isNull()){
				throw JDFException("JDFNode:Spawn cannot spawn unpartitioned root node");
			}
		}

		vElement outLinks = prepareSpawnLinks(rootOut);

		// setup the ancestor nodes
		setSpawnParent(rootOut, spawnParentNode);

		JDFSpawned spawnAudit = createSpawnAudit(rootOut, spawnID, spawnParentNode);

		// find resources that must be copied
		addSpawnedResources(rootOut,spawnAudit);

		finalizeSpawn(vLocalSpawnParts,outLinks,spawnAudit);

		// return the spawned doc
		return docOut;
	}

	////////////////////////////////////////////////////////////////////////////

	JDFDoc JDFSpawn::spawn(
		const WString& _parentURL,
		const WString& _spawnURL,
		const vWString& _vRWResources_in,
		const vmAttribute& _vSpawnParts,
		bool _bSpawnROPartsOnly,
		bool _bCopyNodeInfo, 
		bool _bCopyCustomerInfo,
		bool _bCopyComments)
	{
		bCopyComments=_bCopyComments;
		bCopyCustomerInfo=_bCopyCustomerInfo;
		bCopyNodeInfo=_bCopyNodeInfo;
		bSpawnROPartsOnly=_bSpawnROPartsOnly;
		vSpawnParts=_vSpawnParts;
		vRWResources_in=vWString(_vRWResources_in);
		spawnURL=_spawnURL;
		parentURL=_parentURL;
		return spawn();
	}

	////////////////////////////////////////////////////////////////////////////

	JDFDoc JDFSpawn::spawnInformative() const
	{
		JDFDoc docNew(0);
		JDFNode rootOut=docNew.GetRoot();
		JDFNode thisRoot=node.GetJDFRoot();

		// merge this node into it
		rootOut.MergeNode(thisRoot,false);
		JDFNode copyOfThis=rootOut.GetChildJDFNode(node.GetID(),false);
		docNew=copyOfThis.Spawn(parentURL,spawnURL,vWString::emptyvStr,vSpawnParts,bSpawnROPartsOnly,bCopyNodeInfo,bCopyCustomerInfo,bCopyComments);
		rootOut=docNew.GetRoot();
		rootOut.SetActivation(JDFNode::Activation_Informative);
		return docNew;
	}

	////////////////////////////////////////////////////////////////////////////

	JDFDoc JDFSpawn::spawnInformative(const WString& _parentURL, 
		const WString& _spawnURL, 
		const vmAttribute& _vSpawnParts, 
		bool _bSpawnROPartsOnly,
		bool _bCopyNodeInfo, 
		bool _bCopyCustomerInfo,
		bool _bCopyComments)
	{
		bCopyComments=_bCopyComments;
		bCopyCustomerInfo=_bCopyCustomerInfo;
		bCopyNodeInfo=_bCopyNodeInfo;
		bSpawnROPartsOnly=_bSpawnROPartsOnly;
		vSpawnParts=_vSpawnParts;
		vRWResources_in=vWString::emptyvStr;
		spawnURL=_spawnURL;
		parentURL=_parentURL;
		return spawnInformative();
	}

	////////////////////////////////////////////////////////////////////////////
	vElement JDFSpawn::checkSpawnedResources(const vWString& vRWResources,const vmAttribute& vSpawnParts)
	{
		vElement v;
		// grab the root node and all it's children
		VoidSet vs;
		node.GetAllRefs(&vs,true);
		while(vs.hasNext())
		{
			JDFElement liRoot=(XERCES_CPP_NAMESPACE_QUALIFIER DOMElement*)vs.next();
			JDFResource r;

			bool bResRW=false;
			if(liRoot.IsResourceLink()){
				bResRW=linkFitsRWRes(JDFResourceLink(liRoot),vRWResources);
				if(bResRW){
					JDFResourceLink rl=JDFResourceLink(liRoot);
					JDFResource r=rl.GetTarget();
					vElement vRes;
					if(vSpawnParts.empty()){
						vRes=r.GetLeaves();
					}else{
						for(int i=0;i<vSpawnParts.size();i++){
							vRes.AppendUnique(r.GetPartitionVector(vSpawnParts[i]));
						}
					}
					for(int i=0;i<vRes.size();i++){
						JDFResource rTarget=vRes[i];
						if(rTarget.GetSpawnStatus()==rTarget.SpawnStatus_SpawnedRW)
							v.push_back(rTarget);
					}
				}
			}else if(liRoot.IsRefElement()){
				JDFRefElement re=JDFRefElement(liRoot);
				JDFResource r=re.GetTarget();
				bResRW=resFitsRWRes(r,vRWResources);
				if(bResRW){
					if(r.GetSpawnStatus()==r.SpawnStatus_SpawnedRW)
						v.push_back(r);
				}
			}
		}
		// empty if all is well
		return v;
	}

	////////////////////////////////////////////////////////////////////////////

	bool JDFSpawn::linkFitsRWRes(const JDFResourceLink& li, const vWString& vRWResources)
	{
		bool bResRW=vRWResources.hasString(li.GetNamedProcessUsage());
		// 200602 RP added fix
		if(!bResRW)
			bResRW=vRWResources.hasString(li.GetLinkedResourceName());

		// 230802 RP added check for ID in vRWResources
		if(!bResRW)
			bResRW=vRWResources.hasString(li.GetrRef());

		// 040902 RP added check for Usage in vRWResources
		if(!bResRW)
			bResRW=vRWResources.hasString(li.GetAttribute(JDFStrings::atr_Usage));		
		return bResRW;
	}

	////////////////////////////////////////////////////////////////////////////

	bool JDFSpawn::resFitsRWRes(const JDFResource &r, const vWString& vRWResources)
	{
		bool bResRW=vRWResources.hasString(r.GetLocalName());
		// 200602 RP added fix
		if(!bResRW)
			bResRW=vRWResources.hasString(WString::star);

		// 230802 RP added check for ID in vRWResources
		if(!bResRW)
			bResRW=vRWResources.hasString(r.GetID());

		return bResRW;
	}

	////////////////////////////////////////////////////////////////////////////

	vElement JDFSpawn::prepareSpawnLinks(const JDFNode& rootOut)
	{
		vElement vn = node.GetvJDFNode(WString::emptyStr, JDFNode::Activation_Unknown, false);
		// fill all resources and all links of all children into vResPool and links
		for (int i = 0; i < vn.size(); i++)
		{
			JDFNode vnNode_i = (JDFNode) vn[i];
			vnNode_i.PrepareNodeInfo(vSpawnParts); // make sure we have a nodeinfo in all spawned nodes in case we have to merge stati 
		}

		vn = rootOut.GetvJDFNode(WString::emptyStr, JDFNode::Activation_Unknown, false);
		vElement outLinks;

		// fill all all links of all children of rootOut into vOutRes and outLinks
		for (int i = 0; i < vn.size(); i++)
		{
			JDFNode vnNode_i = (JDFNode) vn[i];
			JDFResourceLinkPool outLinkPool = vnNode_i.GetResourceLinkPool();
			if (!outLinkPool.isNull())
			{
				outLinks.AppendUnique(outLinkPool.GetPoolChildren());
			}
		}
		return outLinks;
	}

	////////////////////////////////////////////////////////////////////////////

	void JDFSpawn::setSpawnParent(JDFNode& rootOut, const JDFNode& parent)
	{
		vWString vs=parent.GetAncestorIDs();
		JDFAncestorPool ancestorPool=parent.GetJDFRoot().GetAncestorPool();
		WString lastAncestorID;

		if(!(parent==node)) // only do this if we are not spawning parallel
		{
			node.RemoveChild(JDFNode::elm_AncestorPool); // just in case
			if(parent.GetJDFRoot().HasChildElement(JDFNode::elm_AncestorPool)){
				ancestorPool=node.CopyElement(ancestorPool);
				int numAncestors=ancestorPool.NumChildElements(JDFNode::elm_Ancestor);
				if(numAncestors>0){
					lastAncestorID=ancestorPool.GetAncestor(numAncestors-1).GetNodeID();
				}
			}
		}
		ancestorPool = rootOut.GetCreateAncestorPool();
		ancestorPool.SetPartMapVector(vSpawnParts);

		// avoid double counting of this node's root element in case of partitioned spawning
		int startAncestorLoop=0;
		if((vs.size()>0)&&(vs[0]==lastAncestorID)){
			startAncestorLoop=1;
		}

		// 010702 RP reversed in GetAncestorIDs: the last in the list is the actual 
		for(int i=startAncestorLoop;i<vs.size();i++)
		{				
			JDFAncestor ancestor=ancestorPool.AppendAncestor();
			ancestor.SetNodeID(vs[i]);
			if(i==0)
			{ // first in list is the parent
				if(!parentURL.empty()) 
					ancestor.SetFileName(parentURL);
			}
		}
		node.SetJobID(parent.GetJobID(true));

		// 180502 RP added line
		ancestorPool.CopyNodeData(parent, bCopyNodeInfo, bCopyCustomerInfo, bCopyComments);
	}

	////////////////////////////////////////////////////////////////////////////

	JDFSpawned JDFSpawn::createSpawnAudit(const JDFNode& rootOut, const WString& spawnID, JDFNode& spawnParentNode)
	{
		// throw in the audits
		JDFAuditPool p = spawnParentNode.GetCreateAuditPool();
		JDFSpawned spawnAudit = p.AddSpawned(rootOut, WString::emptyStr, vWString::emptyvStr, WString::emptyStr, vmAttribute());

		if (!spawnURL.empty())
		{
			if (spawnURL.indexOf("://") == -1)
			{
				spawnAudit.SetURL("file://" + spawnURL);
			}
			else
			{
				spawnAudit.SetURL(spawnURL);
			}
		}
		spawnAudit.SetNewSpawnID(spawnID);
		return spawnAudit;
	}

	////////////////////////////////////////////////////////////////////////////

	int JDFSpawn::addSpawnedResources(JDFNode& rootOut, JDFSpawned& spawnAudit)
	{
		vWString& vRWResources = vRWResources_in;
		int nSpawned=0;
		JDFResourcePool rPool=rootOut.GetCreateResourcePool();

		// must copy the ap to the nood to have a decent hook on ap referenced resources
		JDFAncestorPool ap=rootOut.GetAncestorPool();
		if(!ap.isNull())
			ap = (JDFAncestorPool) node.CopyElement(ap);

		// grab the root node and all it's children
		VoidSet vRootLinks;
		node.GetAllRefs(&vRootLinks,false);  

		WString spawnID=spawnAudit.GetNewSpawnID();
		SetWString allIDsCopied;
		rootOut.getChildAttributeSet(&allIDsCopied, WString::emptyStr, JDFNode::atr_ID, 
			WString::emptyStr, WString::star, false);

		// first check only read only resources, since there may be a collision
		for(int loopRORW=0;loopRORW<2;loopRORW++){
			// loop over all links
			vRootLinks.resetIterator();
			while (vRootLinks.hasNext())
			{
				JDFElement liRoot = (XERCES_CPP_NAMESPACE_QUALIFIER DOMElement*)vRootLinks.next();
				// test for direct children of resourcepool - these will be added later
				if(!liRoot.GetDeepParent(JDFNode::elm_ResourcePool,0).isNull())
					continue;


				JDFResource rRoot;
				bool bResRW=false;
				WString refID = liRoot.GetAttribute(JDFElement::atr_rRef); // must be either refelem or link, therefore will have rref

				if(liRoot.IsResourceLink())
				{
					bResRW=linkFitsRWRes(JDFResourceLink(liRoot),vRWResources);
				}
				else if(liRoot.IsRefElement())
				{
					rRoot=node.GetTarget(refID);
					bResRW=resFitsRWRes(rRoot,vRWResources);
				}

				// do only RO on the first loop and only RW on the second
				if(bResRW!=(loopRORW!=0))
					continue;


				// don't copy if it is already there!
				bool isThereAlready = allIDsCopied.contains(refID);            
				JDFResource::EnumSpawnStatus copyStatus = bResRW ? JDFResource::SpawnStatus_SpawnedRW : JDFResource::SpawnStatus_SpawnedRO;

				if(!isThereAlready)
				{
					if(rRoot.isNull())
						rRoot = (JDFResource)node.GetTarget(refID, JDFNode::atr_ID);

					//  check for null and throw an exception in picky mode
					if(rRoot.isNull())
					{
						continue;
					}

					// copy any missing linked resources, just in case
					// the root is in the original jdf and can be used as a hook to the original document 
					// get a list of all resources referenced by this link
					// always do a copyresource in case some dangling rRefs are waiting

					vWString vvRO;
					vWString vvRW;
					copySpawnedResource(rPool, rRoot, copyStatus, vSpawnParts, spawnID, vRWResources, vvRW, vvRO, allIDsCopied);

					nSpawned += vvRO.size() + vvRW.size();
					vWString rRefsRW=spawnAudit.GetrRefsRWCopied();
					vWString rRefsRO=spawnAudit.GetrRefsROCopied();
					vWStringIterator iterRefs = vvRW.begin();
					while (iterRefs.hasNext()) 
					{
						WString s=iterRefs.next();
						rRefsRW.add(s);
						int ind=rRefsRO.index(s);
						if(ind>=0)
							rRefsRO.RemoveStrings(ind);
					}
					iterRefs = vvRO.begin();
					while (iterRefs.hasNext()) 
					{
						WString s=iterRefs.next();
						rRefsRO.add(s);
					}
					rRefsRO.Unify();
					rRefsRW.Unify();
					spawnAudit.SetrRefsROCopied(rRefsRO);
					spawnAudit.SetrRefsRWCopied(rRefsRW);
				}

				// get the effected resources
				vElement vRes;
				vElement vResRoot;
				if(liRoot.IsResourceLink()){
					vResRoot=JDFResourceLink(liRoot).GetTargetVector();

					// create a temporary dummy copy of the link so that we have a gauranteed copy that behaves the same as the original
					JDFResourceLink dummy=rootOut.GetCreateResourceLinkPool().CopyElement(liRoot);
					vRes=dummy.GetTargetVector();
					dummy.DeleteNode();
				}else if(liRoot.IsRefElement()){
					vResRoot.push_back(JDFRefElement(liRoot).GetTarget());

					// create a temporary dummy copy of the link so that we have a gauranteed copy that behaves the same as the original
					JDFRefElement dummy=rootOut.CopyElement(liRoot);
					vRes.push_back(dummy.GetTarget());
					dummy.DeleteNode();
				}else{
					continue; // snafu - should never get here
				}

				// fixed not to crash with corrupt jdfs. Now just continue and ignore the corrupt resource
				int siz=std::min(vRes.size(),vResRoot.size());
				// loop over all partitions
				for(int resParts=0;resParts<siz;resParts++){
					JDFResource r=vRes[resParts];
					JDFResource rRoot=vResRoot[resParts];

					// make sure that spawned resources are sufficiently partitioned if spawning rw so that no merge conflicts arise
					if (bFixResources && !vSpawnParts.empty() && bResRW)
					{
						vWString rootPartIDKeys = rootOut.GetJDFRoot().GetPartIDKeys(vSpawnParts[0]);
						try
						{
							r.GetResourceRoot().CreatePartitions(vSpawnParts, rootPartIDKeys);
						}
						catch (const JDFException& e)
						{
							fixSpawnPartitions(r, rootPartIDKeys);
						}
					}

					rRoot.SpawnPart(spawnID,copyStatus,vSpawnParts,true);						
					r.SpawnPart(spawnID,copyStatus,vSpawnParts,false);						

					if(vSpawnParts.size()&&(bResRW||bSpawnROPartsOnly)){
						// reduce partitions of all RW resources and of RO resources if requested
						r.ReducePartitions(vSpawnParts);
					}
				}
			}
		}
		// must remove ap after use
		if(!ap.isNull())
			ap.DeleteNode();


		return nSpawned;
	}

	////////////////////////////////////////////////////////////////////////////

	void JDFSpawn::copySpawnedResource(JDFResourcePool& p, JDFResource& r, JDFResource::EnumSpawnStatus copyStatus, const vmAttribute& vParts, const WString& spawnID, const vWString& vRWResources, vWString& vRWIDs, vWString& vROIDs, SetWString& allIDsCopied)
	{
		if (r.throwNull()) {
			return;
		}

		// r is not yet here copy r
		const bool bRW = copyStatus == JDFResource::SpawnStatus_SpawnedRW;
		WString rID = r.GetID();

		if(!allIDsCopied.contains(rID)) 
		{
			JDFResource rNew = (JDFResource)p.CopyElement(r, KElement::DefKElement);
			// if spawning, fix stati and locks

			if((bRW) || bSpawnROPartsOnly)
			{
				rNew.ReducePartitions(vParts);
			}
			r.SpawnPart(spawnID,copyStatus,vParts,true);
			rNew.SpawnPart(spawnID,copyStatus,vParts,false);

			if(bRW)
			{
				vRWIDs.add(rID);
			}
			else
			{
				vROIDs.add(rID);
			}
			allIDsCopied.add(rID);
		}


		vWString vs = r.GetHRefs(vWString::emptyvStr,false);       
		// add recursively copied resource references
		int size = vs.size();
		for(int i = 0; i < size; i++)
		{
			WString id = (WString)vs.elementAt(i);

			// the referenced resource is already in this pool - continue
			if(!allIDsCopied.contains(id))
			{

				// 071101 RP added r is by definition in the original document which also contains the rrefs elements
				JDFResource next = ((JDFNode)r.GetDocRoot()).GetTargetResource(id);

				// and now all those interlinked resources
				if (next.isNull())
				{
					continue;
				}

				// only copy refelements rw if they are explicitly in the list
				if(bRW)
				{
					copyStatus = resFitsRWRes(next,vRWResources) ? 
						JDFResource::SpawnStatus_SpawnedRW : JDFResource::SpawnStatus_SpawnedRO;
				}

				// recurse into refelements
				copySpawnedResource(p, next, copyStatus, vParts, spawnID, vRWResources, vRWIDs, vROIDs,allIDsCopied);
			}
		}      
	}

	////////////////////////////////////////////////////////////////////////////

	void JDFSpawn::fixSpawnPartitions(JDFResource& r, const vWString& rootPartIDKeys)
	{
		vWString oldParts=r.GetPartIDKeys();
		if(oldParts.containsAny(rootPartIDKeys))
		{
			throw new JDFException("fixSpawnPartitions - adding incompatible resources");
		}

		// move away all preexisting partititons and dump them int the new nodes
		VElement ve=r.GetChildElementVector(r.GetNodeName(), r.GetNamespaceURI(), mAttribute(), true, WString::pINF);
		std::vector<KElement> tmp(ve.size());
		for(int i=0;i<ve.size();i++)
			tmp[i]=ve[i].DeleteNode();
		r.RemoveAttribute(JDFNode::atr_PartIDKeys);
		vElement vNew=r.GetResourceRoot().CreatePartitions(vSpawnParts, rootPartIDKeys);

		// copy initial leaves int the newly created stuff
		for(int i=0;i<vNew.size();i++)
			for(int j=0;j<tmp.size();j++)
				vNew[i].CopyElement(tmp[j], KElement::DefKElement);

		// fix partidkeys
		vWString partIDKeys=r.GetPartIDKeys();
		partIDKeys.AppendUnique(oldParts);
		r.setPartIDKeys(partIDKeys);
	}

	////////////////////////////////////////////////////////////////////////////

	void JDFSpawn::finalizeSpawn(const vmAttribute& vLocalSpawnParts, const vElement& outLinks, JDFSpawned& spawnAudit)
	{
		WString spawnID=spawnAudit.GetNewSpawnID();
		// add parts to resource links if necessary
		if (!vLocalSpawnParts.empty())
		{
			for (int i = 0; i < outLinks.size(); i++)
			{
				JDFResourceLink link=outLinks[i];
				JDFResource r = link.GetLinkRoot();

				//2005-03-11 KM if the link is null continue, the JDF ist invalid but in
				//the best case only an audit is missing and the JDF is still operable
				//in the worst caste the spawned JDF is not executable at all
				if(r.isNull())
				{
					continue;
				}

				bool bOldLock=r.GetLocked();
				r.SetLocked(true);
				r.RemoveAttributeFromLeaves(JDFNode::atr_Locked);

				vmAttribute vPartMap=vLocalSpawnParts;

				// 160802 RP leave implied resource link parts if PartUsage=implicit
				if (r.GetPartUsage() != JDFResource::PartUsage_Implicit)
				{
					vWString vPartKeys=r.GetPartIDKeys();
					JDFFactory f(r);
					JDFResource& fRes=(JDFResource&)f.GetRef();
					if(fRes.IsResource()){
						vint vImplicitPartitions=fRes.GetImplicitPartitions();
						for(int ii=0;ii<vImplicitPartitions.size();ii++){
							vPartKeys.push_back(JDFResource::PartIDKeyString((JDFResource::EnumPartIDKey)vImplicitPartitions[ii]));
						}
						vPartMap.ReduceKey(vPartKeys);
					}
				}

				if(!vPartMap.empty()&&!bOldLock)
				{
					vmAttribute vLinkMap=link.GetPartMapVector();
					vmAttribute vNewMap;
					if(vLinkMap.empty()){
						vNewMap=vPartMap;
					}else{
						for(int l=0;l<vLinkMap.size();l++){
							for(int k=0;k<vPartMap.size();k++){
								mAttribute m=vPartMap[k];
								m=m.OrMap(vLinkMap[l]);
								if(!m.empty()){
									vNewMap.AppendUnique(m);
								}
							}

						}
					}
					link.SetPartMapVector(vNewMap);
					vElement vRes=link.GetTargetVector();
					for(int t=0;t<vRes.size();t++){
						JDFResource r=vRes[t];
						r.AppendSpawnIDs(spawnID);
						r.SetLocked(false);
					}
				}
			}
		}

		// add partition information to the audits and StatusPool or NodeInfo
		// 050906 RP move to the back so that it occurs after any global resources have been copied
		if (!vLocalSpawnParts.empty())
		{
			spawnAudit.SetPartMapVector(vLocalSpawnParts);

			JDFNode::EnumStatus partStatus = node.GetPartStatus(vLocalSpawnParts[0]);    
			if(partStatus!=JDFNode::Status_Unknown)
				spawnAudit.SetStatus(partStatus);
			node.SetPartStatus(vLocalSpawnParts, JDFNode::Status_Spawned);
		}
		else // No partitioning - set Audit + Status globally
		{
			spawnAudit.SetStatus(node.GetStatus());
			node.SetStatus(JDFElement::Status_Spawned);
		}
	}

	////////////////////////////////////////////////////////////////////////////

	JDFNode JDFSpawn::unSpawn(const WString& spawnID)
	{
		if(node.throwNull()||spawnID.empty())
			return JDFNode::DefJDFNode;

		mAttribute mapSpawn;
		mapSpawn.AddPair(JDFNode::atr_NewSpawnID,spawnID);
		vElement vElements=node.GetvJDFNode();

		int i;
		// loop over all 
		for(i=0;i<vElements.size();i++){
			JDFNode nodeParent=vElements[i];
			JDFSpawned spawnAudit=nodeParent.GetAuditPool().GetAudit(0,JDFAudit::AuditType_Spawned,mapSpawn);
			// we have a matching spawned audit -> n is the parent node that spawned spawnID
			// let n fix the rest!
			if(!spawnAudit.isNull())
			{
				JDFNode temp = nodeParent;
				temp.UnSpawnNode(spawnID);
				return temp;
			}
		}

		// no node to unspawn exists in any child - too bad...
		return JDFNode::DefJDFNode;
	}

	////////////////////////////////////////////////////////////////////////////

	JDFNode JDFSpawn::unSpawnNode(const WString& spawnID)
	{
		if(node.throwNull()||spawnID.empty())
			return JDFNode::DefJDFNode;

		mAttribute mapSpawn;
		mapSpawn.AddPair(JDFNode::atr_NewSpawnID,spawnID);
		JDFSpawned spawnAudit=node.GetAuditPool().GetAudit(0,JDFAudit::AuditType_Spawned,mapSpawn);

		// loop over all 
		mAttribute mapMerge;
		mapMerge.AddPair(JDFNode::atr_MergeID,spawnID);

		JDFMerged mergedAudit=node.GetAuditPool().GetAudit(0,JDFAudit::AuditType_Merged,mapMerge);
		// cannot undo - it is already merged
		if(!mergedAudit.isNull())
			return JDFNode::DefJDFNode;


		// get parts from audit
		vmAttribute parts=spawnAudit.GetPartMapVector();
		if (parts.size() == 1){
			if (parts[0].empty()){
				parts.clear();
			}
		}

		// loop over all referenced ROCopied resources
		vWString vs=spawnAudit.GetrRefsROCopied();

		int i;
		for(i=0;i<vs.size();i++){
			JDFResource oldRes=node.GetTarget(vs[i]);
			oldRes.UnSpawnPart(spawnID,oldRes.SpawnStatus_SpawnedRO);
		}
		// merge rw resources
		vs=spawnAudit.GetrRefsRWCopied();
		for(i=0;i<vs.size();i++){
			JDFResource oldRes=node.GetTarget(vs[i]);
			oldRes.UnSpawnPart(spawnID,oldRes.SpawnStatus_SpawnedRW);
		}

		JDFNode localNode=node.GetTarget(spawnAudit.GetjRef());
		vElement vn=localNode.GetvJDFNode();

		// loop over all child nodes of the spawned node to be unspawned
		for(int nod=0;nod<vn.size();nod++){
			JDFNode deepNode=vn.at(nod);
			JDFResourcePool resPool = deepNode.GetResourcePool();

			if (resPool.isNull())
				continue;

			vElement vRes = resPool.GetPoolChildren();

			for (i = 0; i < vRes.size(); i++){
				JDFResource res1=vRes[i];
				res1.UnSpawnPart(spawnID,JDFResource::SpawnStatus_SpawnedRW);
			}			
		}

		JDFNode::EnumStatus status=spawnAudit.HasAttribute(JDFNode::atr_Status)?spawnAudit.GetStatus():JDFNode::Status_Waiting;

		if(!parts.empty()){
			if (node.GetStatus() == JDFNode::Status_Pool || node.GetStatus() == JDFNode::Status_Part){
				for(int i=0;i<parts.size();i++){
					if((node.GetPartStatus(parts[i])==JDFNode::Status_Spawned)||(spawnAudit.HasAttribute(JDFNode::atr_Status))){
						// 100602 RP fix
						node.SetPartStatus(parts[i],status);
					}
				}
			}else{
				if((node.GetStatus()==JDFNode::Status_Spawned)||(spawnAudit.HasAttribute(JDFNode::atr_Status)))
					node.SetStatus(status);
			}
		}else{
			// we either must overwrite because it is now definitely not spawned or had an explicit correct status in the spawned audit
			if((localNode.GetStatus()==JDFNode::Status_Spawned)||(spawnAudit.HasAttribute(JDFNode::atr_Status)))
				localNode.SetStatus(status);
		}			
		spawnAudit.DeleteNode();
		return node;
	}
} // namespace JDF
