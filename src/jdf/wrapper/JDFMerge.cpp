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

#include "JDFMerge.h"
#include "JDFDoc.h"
#include "JDFAncestorPool.h"
#include "JDFSpawned.h"
#include "JDFAncestor.h"
#include "JDFMerged.h"
#include "JDFAuditPool.h"
#include "JDFResourceLinkPool.h"
#include "JDFAmountPool.h"
#include "JDFPartAmount.h"
#include "JDFResourcePool.h"
#include "JDFStatusPool.h"
#include "JDFPartStatus.h"
#include "JDFComment.h"

namespace JDF{
	JDFMerge::JDFMerge(const JDFNode& n)
	{
		node = n;
	}

	JDFDoc JDFMerge::mergeJDF(JDFNode& toMerge, const WString& urlMerge, JDFNode::EnumCleanUpMerge cleanPolicy, JDFResource::EnumAmountMerge amountPolicy)
	{
		if (!toMerge.HasParent(node))
		{
			throw new JDFException("JDFNode.MergeJDF no matching parent found");
		}

		WString idm = toMerge.GetID();
		JDFNode overWriteNode  = (JDFNode) node.GetTarget(idm, JDFNode::atr_ID);

		if ( overWriteNode.isNull() )
		{
			throw new JDFException("JDFNode.MergeJDF no Node with ID: " + idm);
		}

		//tbd multiple ancestor handling
		JDFAncestorPool ancestorPool = toMerge.GetAncestorPool();
		if ( ancestorPool.isNull() )
		{
			throw new JDFException("JDFNode.MergeJDF no Ancestor Pool in Node: " + idm);
		}
		int numAncestors = ancestorPool.NumChildElements(JDFNode::elm_Ancestor, WString::emptyStr);

		if (numAncestors <= 0)
		{
			throw new JDFException("JDFNode.MergeJDF no Ancestors in AncestorPool found. Node: " + idm);
		}

		WString spawnID = WString::emptyStr;
		bool bSnafu = true;
		JDFSpawned spawnAudit;
		vWString previousMergeIDs; // list of merges in the ancestors
		int iFound = 0;

		for (int whereToLook = 1; whereToLook <= numAncestors; whereToLook++)
		{
			// the last ancestor has the id!
			WString idParent = ancestorPool.GetAncestor(numAncestors - whereToLook).GetNodeID();
			KElement k = node.GetTarget(idParent, JDFNode::atr_ID);
			if ( k.isNull() )
			{
				break;
			}

			JDFNode op = (JDFNode)k;
			JDFAuditPool ap = op.GetCreateAuditPool();

			// find all ids of previous merge operations for reverse merge cleanup
			VElement vMergeAudit = ap.GetAudits(JDFAudit::AuditType_Merged, mAttribute::emptyMap);
			for (int nMerged = 0; nMerged < vMergeAudit.size(); nMerged++)
			{
				JDFMerged merged = (JDFMerged)vMergeAudit.elementAt(nMerged);
				previousMergeIDs.AppendUnique(merged.GetMergeID());
			}

			if (iFound != 0) // we've already found a spawned Audit, just looping for previous merges
			{
				continue;
			}

			// get appropriate spawned element
			VElement vSpawnAudit = ap.GetChildrenByTagName(JDFNode::elm_Spawned, WString::emptyStr, JDFAttributeMap(JDFNode::atr_jRef, idm), 
				true, true, 0);
			spawnID = toMerge.GetSpawnID();

			for (int isp = vSpawnAudit.size() - 1; isp >= 0; isp--)
			{ // loop backwards because the latest is assumed correct
				JDFSpawned testSpawn = (JDFSpawned)vSpawnAudit.elementAt(isp);
				if (testSpawn.GetNewSpawnID().equals(spawnID))
				{
					// tbd check for matching merged...
					spawnAudit = testSpawn;
					JDFMerged matchingMerged = 
						(JDFMerged) ap.GetChildWithAttribute(JDFNode::elm_Merged, JDFNode::atr_MergeID, WString::emptyStr, spawnID, 0, true);


					if ( !matchingMerged.isNull() )
					{
						throw JDFException("JDFNode.MergeJDF Spawn Audit already merged, SpawnID: " + spawnID);
					}
					break;
				}
			}
			// found an audit that fits, 
			if (!spawnAudit.isNull())
			{
				iFound = whereToLook;
			}
		}
		
		// if the spawn Audit is not found at the first attempt, something went badly wrong
		// we will insert a error audit later but continue limping along!
		bSnafu = iFound != 1;

		if (spawnAudit.isNull())
		{
			throw JDFException("JDFNode.MergeJDF no matching Spawn Audit, SpawnID: " + spawnID);
		}

		// get parts from audit
		vmAttribute parts = spawnAudit.GetPartMapVector();

		// merge copied readOnly resources
		vWString vsRO = spawnAudit.GetrRefsROCopied();
		vWString vsRW = spawnAudit.GetrRefsRWCopied();

		WString preSpawn = mergeCheckPrespawn(toMerge, spawnAudit, vsRO, vsRW);

		mergeLocalLinks(overWriteNode,toMerge, parts);

		cleanROResources(overWriteNode,toMerge, previousMergeIDs, vsRO, spawnID);
		mergeRWResources(overWriteNode,toMerge, previousMergeIDs, vsRW, spawnID, amountPolicy);

		mergeLocalNodes(overWriteNode,toMerge, previousMergeIDs, spawnID, amountPolicy, parts);
		JDFMerged mergeAudit=mergeMainPools(overWriteNode, toMerge, parts, vsRW, spawnID, preSpawn, urlMerge, bSnafu);
		// an empty spawnID should never happen here, but check just in case
		// since an empty spawnID in CleanUpMerge removes all Spawned audits
		if (!spawnID.empty())
		{
			JDFNode overWriteParent=mergeAudit.GetParentJDF(); // since all links get screwed up, let's relink here
			cleanUpMerge(overWriteParent,cleanPolicy, spawnID, false);
		}

		// now burn it in!
		overWriteNode=(JDFNode)overWriteNode.ReplaceElement(toMerge);
		overWriteNode.EraseEmptyNodes(true);

		return overWriteNode.GetOwnerDocument();
	}

	///////////////////////////////////////////////////////////////////

	WString JDFMerge::mergeCheckPrespawn(JDFNode& toMerge, const JDFSpawned& spawnAudit, vWString& vsRO, vWString& vsRW)
	{
		WString preSpawn = spawnAudit.GetSpawnID();
        // check all recursive previous spawns
        while (!preSpawn.empty())
        {
			JDFMerged preMerge = (JDFMerged)node.GetTarget(preSpawn, JDFNode::atr_MergeID);
			if (!preMerge.isNull())
            {
				JDFSpawned preSpawnAudit = (JDFSpawned)node.GetTarget(preSpawn, JDFNode::atr_NewSpawnID);
				vsRO.AppendUnique(preSpawnAudit.GetrRefsROCopied());
				vsRW.AppendUnique(preSpawnAudit.GetrRefsRWCopied());
				preSpawn = preSpawnAudit.GetSpawnID();
            }
            else
            {
                toMerge.SetSpawnID(preSpawn);
                break;                
            }
        }
        return preSpawn;
	}

	///////////////////////////////////////////////////////////////////

	void JDFMerge::mergeLocalLinks(const JDFNode& overWriteNode, const JDFNode& toMerge, const vmAttribute& parts)
	{
		int numParts = parts.empty() ? 0 : parts.size();
		vElement vn = overWriteNode.GetvJDFNode(WString::emptyStr, JDFNode::Activation_Unknown, false);
		int nod = 0;
		// merge local (internal) partitioned resource links
		for (nod = 0; nod < vn.size(); nod++)
		{
			JDFNode overwriteLocalNode  = (JDFNode)vn.elementAt(nod);
			JDFNode toMergeLocalNode    = toMerge.GetChildJDFNode(overwriteLocalNode.GetID(), false);
			mergeResourceLinkPool(overwriteLocalNode,toMergeLocalNode, parts);
			JDFNode::EnumVersion version = toMergeLocalNode.GetEnumVersion(true);
			if ((version!=JDFNode::Version_Unknown)&&(version >= JDFNode::Version_1_3))
			{
				JDFNode::EnumStatus stat=toMergeLocalNode.GetStatus();
				if (stat!=JDFNode::Status_Unknown && stat!=JDFElement::Status_Part &&
					stat!=JDFElement::Status_Pool && numParts > 0)
				{
					toMergeLocalNode.SetPartStatus(parts,stat);
				}
			}
		}
	}

	///////////////////////////////////////////////////////////////////

	void JDFMerge::mergeResourceLinkPool(const JDFNode& overWriteNode, JDFNode& toMerge, const vmAttribute& parts)
	{
		JDFResourceLinkPool resourceLinkPool = toMerge.GetResourceLinkPool();
		if(!resourceLinkPool.isNull())
		{
			vElement links=resourceLinkPool.GetPoolChildren(WString::emptyStr, mAttribute::emptyMap, WString::emptyStr);
			for(int i=0;i<links.size();i++){
				JDFResourceLink rl=(JDFResourceLink) links.elementAt(i);
				rl.ExpandTarget(false);
			}
		}

		if (!parts.empty())
		{
			JDFResourceLinkPool overWriteRLP = overWriteNode.GetResourceLinkPool();
			JDFResourceLinkPool toMergeRLP = resourceLinkPool;
			vElement overWriteLinks = overWriteRLP.GetPoolChildren(WString::emptyStr, mAttribute::emptyMap, WString::emptyStr);
			vElement toMergeLinks = toMergeRLP.GetPoolChildren(WString::emptyStr, mAttribute::emptyMap, WString::emptyStr);

			for (int rl = 0; rl < toMergeLinks.size(); rl++)
			{
				JDFResourceLink overWriteLink = JDFResourceLink();
				JDFResourceLink toMergeLink = (JDFResourceLink)toMergeLinks.elementAt(rl);
				WString rRef = toMergeLink.GetAttribute(JDFNode::atr_rRef);
				for (int k = 0; k < overWriteLinks.size(); k++)
				{
					if (((JDFResourceLink)overWriteLinks.elementAt(k)).GetAttribute(JDFNode::atr_rRef).equals(rRef))
					{
						overWriteLink = (JDFResourceLink)overWriteLinks.elementAt(k);
						overWriteLinks.remove(k);
						break;
					}
				}

				JDFAmountPool jdfAmountPool = toMergeLink.GetAmountPool();

				if (!overWriteLink.isNull())
				{
					if (toMergeLink.HasChildElement(JDFNode::elm_Part, WString::emptyStr))
					{
						for (int i = 0; i < parts.size(); i++)
						{
							bool hasAP = overWriteLink.HasChildElement(JDFNode::elm_AmountPool, WString::emptyStr);
							JDFAttributeMap mpaMap;
							vElement vPartAmounts;
							if(!jdfAmountPool.isNull())
								vPartAmounts=jdfAmountPool.GetMatchingPartAmountVector(parts[i]);

							if (vPartAmounts.empty())
							{
								mpaMap = toMergeLink.GetAttributeMap();
								// remove generic link stuff
								mpaMap.remove(JDFNode::atr_CombinedProcessIndex);
								mpaMap.remove(JDFNode::atr_CombinedProcessType);
								//tbd opa.RemoveAttribute(atr_PipePartIDKeys);
								mpaMap.remove(JDFNode::atr_PipeProtocol);
								mpaMap.remove(JDFNode::atr_ProcessUsage);
								mpaMap.remove(JDFNode::atr_rRef);
								mpaMap.remove(JDFNode::atr_rSubRef);
								mpaMap.remove(JDFNode::atr_Usage);
								if(!hasAP){
									JDFAttributeMap opaMap=overWriteLink.GetAttributeMap();
									if(opaMap.SubMap(mpaMap))
									{
										mpaMap.clear();
									}
								}
								// only add something if partmap contains real information
								if(hasAP || (!mpaMap.empty()&& mpaMap != parts[i]))
								{
									JDFPartAmount opa=overWriteLink.GetCreateAmountPool().GetCreatePartAmount(parts[i]);
									opa.SetAttributes(mpaMap);
									overWriteLink.RemoveAttributes(mpaMap.GetKeys());
								}                           
							}
							else
							{
								// loop over all fitting part amounts and blast them in
								for(int j=0;j<vPartAmounts.size();j++)
								{
									JDFPartAmount mpa= (JDFPartAmount)vPartAmounts.elementAt(j);                              
									JDFAttributeMap amountMap=mpa.GetAttributeMap();
									JDFAttributeMap partMap=mpa.GetPartMap();
									JDFPartAmount opa=overWriteLink.GetCreateAmountPool().GetCreatePartAmount(partMap);
									opa.SetAttributes(amountMap);
									overWriteLink.RemoveAttributes(amountMap.GetKeys());                                
								}
							}
							if(!mpaMap.empty())
							{
								// dont add ap if mpa link only has copies of the original link
								if(!hasAP)
								{
									mAttribute opaMap = overWriteLink.GetAttributeMap();
									if(opaMap.SubMap(mpaMap))   
									{
										mpaMap.clear();
									}
								}

								// only add something if partmap contains real information
								if((!mpaMap.empty() && mpaMap!=parts[i]))
								{
									JDFPartAmount opa = overWriteLink.GetCreateAmountPool().GetCreatePartAmount(parts[i]);
									opa.SetAttributes(mpaMap);
								}
							}
							// nothing has changed --> leave as is
						}
					}
					else
					{
						// blast the spawned link into the overWritePool completely
						overWriteLink.ReplaceElement(toMergeLink);
					}
				}
			}
			toMergeRLP.DeleteNode();
			toMerge.CopyElement(overWriteRLP, KElement::DefKElement);
		}
	}

	///////////////////////////////////////////////////////////////////

	void JDFMerge::cleanROResources(JDFNode& overWriteNode,JDFNode& toMerge, const vWString& previousMergeIDs, const vWString& vsRO, const WString& spawnID)
	{
		for (int i = 0; i < vsRO.size(); i++)
		{
			JDFResource newRes = toMerge.GetTargetResource((WString)vsRO.elementAt(i));
			JDFResource oldRes = (JDFResource) overWriteNode.GetTarget((WString)vsRO.elementAt(i), JDFNode::atr_ID);

			// merge all potential new spawnIds from toMerge to this
			oldRes.MergeSpawnIDs(newRes, previousMergeIDs);
			vElement oldResLeafsSpawned = oldRes.GetNodesWithSpawnID(spawnID);
			for (int leaf = 0; leaf < oldResLeafsSpawned.size(); leaf++)
			{
				JDFResource leafRes = (JDFResource)oldResLeafsSpawned.elementAt(leaf);
				//  handle multiple spawns (reference count of spawned audits!)
				leafRes.RemoveFromSpawnIDs(spawnID);

				if (!leafRes.HasAttribute(JDFNode::atr_SpawnIDs, WString::emptyStr, false))
				{
					leafRes.RemoveAttribute(JDFNode::atr_SpawnStatus);
				}
			}
			if(!newRes.GetParentJDF().GetID().equals(oldRes.GetParentJDF().GetID()))
			{
				// this has been copied from lower down up and MUST be deleted...
				newRes.DeleteNode();
			}
			else
			{
				// don't use a simple for because deleting a parent may invalidate later resources!
				vElement newResLeafsSpawned = newRes.GetNodesWithSpawnID(spawnID);
				// just in case: if no SpawnID exists assume the whole thing 
				if (newResLeafsSpawned.size() == 0)
				{
					newResLeafsSpawned.add(newRes);
				}
				while (newResLeafsSpawned.size() > 0)
				{
					// use the last because it is potentially the root...
					JDFResource leafRes = (JDFResource)newResLeafsSpawned.elementAt(newResLeafsSpawned.size() - 1);
					bool bZappRoot = leafRes == newRes;
					leafRes.DeleteNode();
					// we killed the root, nothing can be left...
					if (bZappRoot)
					{
						break;
					}
					// regenerate the list
					newResLeafsSpawned = newRes.GetNodesWithSpawnID(spawnID);
				}
			}
		}
	}

	///////////////////////////////////////////////////////////////////

	void JDFMerge::mergeRWResources(JDFNode& overWriteNode, JDFNode& toMerge, const vWString& previousMergeIDs, const vWString& vsRW, const vWString& spawnID, JDFResource::EnumAmountMerge amountPolicy)
	{
		// merge rw resources
		for (int i = 0; i < vsRW.size(); i++)
		{
			JDFResource oldRes = overWriteNode.GetLinkRoot((WString)vsRW.elementAt(i));
			if(oldRes.isNull()) // also check in tree below
			{
				oldRes = overWriteNode.GetTargetResource((WString)vsRW.elementAt(i));
				if(oldRes.isNull()) // also check in entire tree below root
				{
					oldRes = overWriteNode.GetTargetResource((WString)vsRW.elementAt(i));
				}
			}
			if(oldRes.isNull())
			{
				continue;
			}


			JDFResource newRes = toMerge.GetTargetResource((WString)vsRW.elementAt(i));

			// merge all potential new spawnIds from this to toMerge before merging them
			oldRes.MergeSpawnIDs(newRes, previousMergeIDs);
			// do both, since some leaves may be RO
			newRes.MergeSpawnIDs(oldRes, previousMergeIDs);

			try
			{
				// merge the resource from the spawned node into the lower level resourcepool
				oldRes.MergePartition(newRes, spawnID, amountPolicy, false);
			}
			catch (const Exception&)
			{
				throw new JDFException("JDFNode:mergeJDF, error in mergePartition: ID="+oldRes.GetID()+" SpawnID="+spawnID);
			}

			WString oldID        = oldRes.GetID();
			JDFResource myRes   = (JDFResource)overWriteNode.GetTarget(oldID, JDFNode::atr_ID);
			if (myRes.isNull())
			{
				throw new JDFException("JDFNode.mergeJDF: Merged Resource not found! Cant remove SpawnIDs");
			}
			vElement oldResLeafsSpawned = myRes.GetNodesWithSpawnID(spawnID);
			for (int leaf = 0; leaf < oldResLeafsSpawned.size(); leaf++)
			{
				JDFResource leafRes = (JDFResource)oldResLeafsSpawned.elementAt(leaf);
				leafRes.RemoveFromSpawnIDs(spawnID);
				KElement leafElem = leafRes;
				if (!leafElem.HasAttribute(JDFNode::atr_SpawnIDs, WString::emptyStr, false))
				{
					leafRes.RemoveAttribute(JDFNode::atr_SpawnStatus, WString::emptyStr);
					leafRes.RemoveAttribute(JDFNode::atr_Locked, WString::emptyStr);
				}
			}
		}
	}

	///////////////////////////////////////////////////////////////////

	void JDFMerge::mergeLocalNodes(JDFNode& overWriteNode, JDFNode& toMerge, const vWString& previousMergeIDs, const WString& spawnID, JDFResource::EnumAmountMerge amountPolicy, const vmAttribute& parts)
	{
		// merge local (internal) partitioned resources
		vElement vn = overWriteNode.GetvJDFNode(WString::emptyStr, JDFNode::Activation_Unknown, false);
		for (int nod = 0; nod < vn.size(); nod++)
		{
			JDFNode overwriteLocalNode = (JDFNode)vn.elementAt(nod);

			JDFNode toMergeLocalNode = (JDFNode)toMerge.GetTarget(overwriteLocalNode.GetID(), JDFNode::atr_ID);
			JDFResourcePool poolOverWrite = overwriteLocalNode.GetResourcePool();
			JDFResourcePool poolToMerge = toMergeLocalNode.GetResourcePool();

			if (!poolOverWrite.isNull())
			{
				vElement resOverWrite = poolOverWrite.GetPoolChildren(WString::emptyStr, mAttribute::emptyMap, WString::emptyStr);

				int size = resOverWrite.size();
				for (int i = 0; i < size; i++)
				{
					JDFResource res1 = (JDFResource)resOverWrite.elementAt(i);
					mergeLocalResource(previousMergeIDs, spawnID, amountPolicy, poolToMerge, res1);
				}
			}

			//retain all other elements of the original (non spawned) JDF Node if the spawn is partitioned¬
			JDFAncestorPool ancestorPool = toMerge.GetAncestorPool();
			if (!ancestorPool.isNull() && ancestorPool.IsPartitioned())
			{
				vElement localChildren = overwriteLocalNode.GetChildElementVector(WString::star, WString::emptyStr, mAttribute::emptyMap, true, 0, false);

				int siz = localChildren.size();
				for (int i = 0; i < siz; i++)
				{
					KElement e = (KElement) localChildren.elementAt(i);
					// skip all pools
					WString nodeName = e.GetLocalName();
                    if (nodeName.endsWith("Pool"))
                    {
						if (nodeName == JDFNode::elm_ResourceLinkPool)
                        {
                            continue;
                        }
						if (nodeName == JDFNode::elm_ResourcePool)
                        {
                            continue;
                        }
						if (nodeName == JDFNode::elm_AuditPool)
                        {
                            mergeAuditPool(overwriteLocalNode,toMergeLocalNode);
                            continue;
                        }
						if (nodeName == JDFNode::elm_StatusPool)
                        {
                            mergeStatusPool(overwriteLocalNode,toMergeLocalNode,parts);
                            continue;
                        }
						if (nodeName == JDFNode::elm_AncestorPool)
                        {
                            continue;
                        }
                    }

					// 131204 RP also skip all sub-JDF nodes!!!
					if(nodeName == JDFNode::elm_JDF)
					{
						continue;
					}
					//050708 RP special handling for comments
					if(nodeName == JDFNode::elm_Comment){
						mergeComments(overwriteLocalNode,toMergeLocalNode);
						continue;
					}

					toMergeLocalNode.RemoveChildren(nodeName, WString::emptyStr);
					toMergeLocalNode.MoveElement(e, KElement::DefKElement);

					// repeat in case of multiple identical elements (e.g. comments)
					for (int j = i + 1; j < siz; j++)
					{
						JDFElement localChild = (JDFElement) localChildren.elementAt(j);
						if ( !localChild.isNull() )
						{
							if ( localChild.GetNodeName() == nodeName )
							{
								toMergeLocalNode.MoveElement(localChild, KElement::DefKElement);
								localChildren[j] = KElement::DefKElement;
							}
						}
					}
				}
			}
		}
	}

	/////////////////////////////////////////////////////////////////////

	void JDFMerge::mergeLocalResource(const vWString& previousMergeIDs, const WString& spawnID, JDFResource::EnumAmountMerge amountPolicy, JDFResourcePool& poolToMerge, JDFResource& res1)
	{
		WString resID = res1.GetID();
		JDFResource res2 = poolToMerge.GetResourceByID(resID);

		if (!res2.isNull())
		{
			res2.MergeSpawnIDs(res1, previousMergeIDs);
			res1.MergePartition(res2, spawnID, amountPolicy, true); // esp. deletes res2 from toMerge node
		}
		// copy resource from orig to spawned node
		poolToMerge.CopyElement(res1, KElement::DefKElement);
		res1 = poolToMerge.GetResourceByID(resID);
		vElement resLeafsSpawned = res1.GetNodesWithSpawnID(spawnID);
		for (int leaf = 0; leaf < resLeafsSpawned.size(); leaf++)
		{
			JDFResource leafRes = (JDFResource)resLeafsSpawned.elementAt(leaf);
			leafRes.RemoveFromSpawnIDs(spawnID);
			vWString spawnIDs = leafRes.GetSpawnIDs(false);
			spawnIDs.RemoveStrings(previousMergeIDs);
			if(spawnIDs.empty())
			{
				leafRes.RemoveAttribute(JDFNode::atr_SpawnIDs);
				leafRes.RemoveAttribute(JDFNode::atr_SpawnStatus);
				leafRes.RemoveAttribute(JDFNode::atr_Locked);
			}
			else
			{
				leafRes.SetSpawnIDs(spawnIDs);
			}
		}
	}

	/////////////////////////////////////////////////////////////////////

	void JDFMerge::mergeAuditPool(JDFNode& overWriteNode, JDFNode& toMerge)
	{
		// merge audit pool
		JDFAuditPool overWriteAuditPool = overWriteNode.GetAuditPool();
		JDFAuditPool toMergeAuditPool = toMerge.GetAuditPool();

		// the node that is overwritten has an audit pool that must be merged
		if (!overWriteAuditPool.isNull())
		{
			// the overwriting node node is empty, just copy the previous pool
			if (toMergeAuditPool.isNull())
			{
				toMerge.CopyElement(overWriteAuditPool, KElement::DefKElement);
			}
			else
			{
				// must merge the old node into the overwriting node
				overWriteAuditPool.AppendUnique(toMergeAuditPool);
				toMergeAuditPool.ReplaceElement(overWriteAuditPool);
			}
		}
	}

	/////////////////////////////////////////////////////////////////////

	void JDFMerge::mergeStatusPool(JDFNode& overWriteNode, JDFNode& toMerge, const vmAttribute& parts)
	{
		if (toMerge.HasChildElement(JDFNode::elm_StatusPool, WString::emptyStr) || 
			overWriteNode.HasChildElement(JDFNode::elm_StatusPool, WString::emptyStr))
		{
			JDFStatusPool overWriteStatusPool = overWriteNode.GetCreateStatusPool();
			if (overWriteNode.GetStatus() != JDFElement::Status_Pool)
			{
				overWriteStatusPool.SetStatus(overWriteNode.GetStatus());
				overWriteNode.SetStatus(JDFElement::Status_Pool);
			}

			JDFStatusPool toMergeStatusPool = toMerge.GetStatusPool();
			if (toMerge.GetStatus() == JDFElement::Status_Pool)
			{
				for (int i = 0; i < parts.size(); i++)
				{
					int j;
					// clean up the pool to overwrite
					vElement vpso = overWriteStatusPool.GetMatchingPartStatusVector(parts[i]);
					for (j=0;j<vpso.size();j++)
					{
						// remove all matching partstatus elements in case they were expanded in the spawned node
						((JDFPartStatus) vpso.elementAt(j)).DeleteNode(); 
					}

					// extract data from spawned node
					vElement vps=toMergeStatusPool.GetMatchingPartStatusVector(parts[i]);
					for (j=0; j<vps.size(); j++)
					{
						JDFPartStatus ps = (JDFPartStatus) vps.elementAt(j);
						JDFAttributeMap m = ps.GetPartMap();
						overWriteStatusPool.SetStatus(m, ps.GetStatus(), ps.GetStatusDetails());
					}

					//100305 RP the following lines cause problems with nested spawn and therefore are commented out
					//                  final JDFPartStatus ps=overWriteStatusPool.getPartStatus(parts.elementAt(i));
					// just in case someone updated detailed partstatus elements
					//                  if (ps != null && ps.getStatus() == EnumNodeStatus.Spawned)
					//                  ps.deleteNode();
				}
				toMergeStatusPool.ReplaceElement(overWriteStatusPool);
			}
			else
			{
				// this part of the program will probably never be executed, but...
				for (int i = 0; i < parts.size(); i++)
					overWriteStatusPool.SetStatus(parts[i], toMerge.GetStatus(), WString::emptyStr);
				if (!toMergeStatusPool.isNull())
					toMergeStatusPool.DeleteNode();
				toMerge.SetStatus(JDFElement::Status_Pool);
				toMerge.MoveElement(overWriteStatusPool, KElement::DefKElement);
			}
		}
	}

	/////////////////////////////////////////////////////////////////////

	void JDFMerge::mergeComments(JDFNode& overWriteNode, JDFNode& toMerge)
	{
		vElement v=overWriteNode.GetChildElementVector(JDFNode::elm_Comment,WString::emptyStr,mAttribute::emptyMap,false,0,false);
		vElement vToMerge=toMerge.GetChildElementVector(JDFNode::elm_Comment,WString::emptyStr,mAttribute::emptyMap,false,0,false);
		int siz=vToMerge.size(); // size prior to appending
		vToMerge.AppendUnique(v);
		for(int i=siz;i<vToMerge.size();i++){
			toMerge.MoveElement((KElement)vToMerge.elementAt(i),KElement::DefKElement);
		}
	}

	/////////////////////////////////////////////////////////////////////

	JDFMerged JDFMerge::mergeMainPools(JDFNode& overWriteNode, JDFNode& toMerge, const vmAttribute& parts, const vWString& vsRW, const vWString& spawnID, const WString& preSpawn, const WString& urlMerge, bool bSnafu)
	{
		// add the merged audit - maintain sychronicity of spawned and merged
		JDFNode overWriteParent;
		JDFAuditPool ap=toMerge.GetAuditPool();
		JDFSpawned sa;

		if(!ap.isNull())
		{
			sa=(JDFSpawned) ap.GetChildWithAttribute(JDFNode::elm_Spawned,JDFNode::atr_NewSpawnID,WString::emptyStr,spawnID,0,true);
			overWriteParent=overWriteNode;
		}

		if(sa.isNull())
		{
			overWriteParent=overWriteNode.GetParentJDF();
			if(overWriteParent.isNull())
			{
				throw JDFException("mergeMainPools - corrupt audit structure");
			}

			ap=overWriteParent.GetAuditPool();
			if(!ap.isNull())
				sa=(JDFSpawned) ap.GetChildWithAttribute(JDFNode::elm_Spawned,JDFNode::atr_NewSpawnID,WString::emptyStr,spawnID,0,true);
		}

		if(sa.isNull())
		{
			//????
			throw JDFException("mergeMainPools - corrupt audit structure");
		}

		// JDFNode overWriteParent=ap.getParentJDF();
		JDFMerged mergeAudit = (JDFMerged) ap.AddMerged(toMerge,vsRW, WString::emptyStr, parts);

		if (!urlMerge.empty())
		{
			WString url = urlMerge;
			// 300802 RP added check for preexisting file prefix
			if (url.indexOf("://") == -1)
			{
				url = "file://" + url;
			}
			mergeAudit.SetURL(url);
		}
		mergeAudit.SetMergeID(spawnID);

		// if something went wrong, also add a notification
		if (bSnafu)
		{
			JDFNotification notification = ap.AddNotification(JDFNotification::Class_Error, "JDFNode.MergeJDF ", parts);
			notification.SetType("Error");
			notification.AppendComment().AppendText("The Ancestor list was incorrectly ordered for merging in the spawned JDF");
		}

		// cleanup
		toMerge.RemoveChild(JDFNode::elm_AncestorPool, WString::emptyStr, 0);
		if (!parts.empty())
		{
			mergeStatusPool(overWriteNode,toMerge,parts);
			// handle ancestor pools only in partitioned spawns
			JDFAncestorPool ancPool=overWriteParent.GetAncestorPool();
			if(!ancPool.isNull()){
				toMerge.CopyElement(ancPool,KElement::DefKElement);
			}
		}

		WString jid = overWriteParent.GetJobID(true);
		if (toMerge.GetAttribute(JDFNode::atr_JobID, WString::emptyStr, WString::emptyStr) == jid)
		{
			toMerge.RemoveAttribute(JDFNode::atr_JobID, WString::emptyStr);
		}
		if(preSpawn.empty())
		{
			toMerge.RemoveAttribute(JDFNode::atr_SpawnID, WString::emptyStr);
			mergeAudit.RemoveAttribute(JDFNode::atr_SpawnID, WString::emptyStr);
		}
		else
		{
			toMerge.SetSpawnID(preSpawn);
		}
		return mergeAudit;
	}

	/////////////////////////////////////////////////////////////////////

	void JDFMerge::cleanUpMerge(JDFNode& overWriteNode, JDFNode::EnumCleanUpMerge cleanPolicy, const WString& spawnID, bool bRecurse)
	{
		if(cleanPolicy != JDFNode::CleanUpMerge_None)
		{
			if(bRecurse)
			{
				vElement v = overWriteNode.GetvJDFNode(WString::emptyStr, JDFNode::Activation_Unknown, false);
				for(int i = v.size(); i >= 0; i--)
				{
					cleanUpMerge((JDFNode&)v.elementAt(i),cleanPolicy, spawnID, false);
				}

			}
			else
			{
				JDFAuditPool auditPool = overWriteNode.GetAuditPool();
				if (!auditPool.isNull())
					auditPool.CleanUpMerge(cleanPolicy, spawnID);
			}
		}
	}

} // end namespace JDF
