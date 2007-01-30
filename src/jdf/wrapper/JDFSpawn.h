#if !defined _JDFSPAWN_H_
#define _JDFSPAWN_H_

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
//EndCopyRight
// ////////////////////////////////////////////////////////////////////
//
//  Author: Dr. Rainer Prosi (JDFLib-J), ported to JDFLib-C by Niels Boeger
// 
// Revision history:
// created before 31.Aug.2006
// 310806 | NB | ported JDFSpawn from JDFLib-J

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000 

#include "JDFNode.h"

namespace JDF{
	

	/**
	* @author Rainer Prosi
	* This class is used when spawning a JDF node. It summarizes all 
	* spawning routines the had been part of JDF Node
	*/
	class SetWString; 
	class JDF_WRAPPERCORE_EXPORT JDFSpawn{
	public:
		/******************************
		* Construction / Destruction
		*******************************/

		JDFSpawn (JDFNode& n);
		inline ~JDFSpawn() {};
		
		/******************************
		* methods
		*******************************/
		vElement checkSpawnedResources(const vWString& vRWResources,const vmAttribute& vSpawnParts);

		/**
		* spawn a node
		* @return The spawned doc
		*/
		JDFDoc spawn();

		/**
		* spawn a node; url is the file name of the new node,
		* vRWResourceUsage is the vector of Resources Usages
		* (or Names if no usage exists for the process) that are
		* spawned RW, all others are spawned read only;
		* vParts is the vector of part maps that are to be spawned,
		* defaults to no part, i.e. the whole thing
		* 
		* @param parentURL
		* @param spawnURL: URL of the spawned JDF file
		* @param vRWResources: vector of resource names and Usage / ProcessUsage that are spawned as rw <br>
		*       the format is one of:<br>
		*                     ResName:Input<br>
		*                     ResName:Output<br>
		*                     ResName:ProcessUsage<br>
		* @param VJDFAttributeMap vSpawnParts: vector of mAttributes that describe the parts to spawn, only 
		*        valid PartIDKeys are allowed
		* @param bSpawnROPartsOnly if true, only the parts of RO resources that are specified in vParts are 
		*                                  spawned, else the complete resource is spawned
		* @param bCopyNodeInfo copy the NodeInfo elements into the Ancestors
		* @param bCopyCustomerInfo copy the CustomerInfo elements into the Ancestors
		* @param bCopyComments copy the Comment elements into the Ancestors
		* 
		* @return The spawned doc
		* @since 050831 added bCopyComments
		* @ tbd enhance nested spawning of partitioned nodes
		* default: spawn(parentURL, WString::emtpyString, vWString::emptyvStr, vmAttribute::emptyvMap, false, false, false, false)
		*/
		JDFDoc spawn(
			const WString& _parentURL,
			const WString& _spawnURL=WString::emptyStr,
			const vWString& _vRWResources_in=vWString::emptyvStr,
			const vmAttribute& _vSpawnParts=vmAttribute::emptyvMap,
			bool _bSpawnROPartsOnly=false,
			bool _bCopyNodeInfo=false, 
			bool _bCopyCustomerInfo=false,
			bool _bCopyComments=false);

		/**
		* spawn a node in informative mode without modifying the root JDF;
		* @return JDFNode: The spawned node.
		*/
		JDFDoc spawnInformative() const;

		/**
		* spawn a node in informative mode without modifying the root JDF; url is the file name of the new node,
		* the parameters except for the list of rw resources, which are by definition empty, are identical to those of Spawn
		*
		* vRWResourceUsage is the vector of Resources Usages, Resource Names or Resource IDs that are
		* spawned RW, all others are spawned read only;
		* vParts is the vector of part maps that are to be spawned,
		* defaults to no part, i.e. the whole thing
		*
		* @param spawnURL: URL of the spawned JDF file
		* @param vParts: vector of mAttributes that describe the parts to spawn
		* @param bSpawnROPartsOnly if true, only the parts of RO resources that are specified in vParts are spawned, else the complete resource is spawned
		* @param bCopyNodeInfo copy the NodeInfo elements into the Ancestors
		* @param bCopyCustomerInfo copy the CustomerInfo elements into the Ancestors
		* @param bCopyComments copy the Comment elements into the Ancestors
		* @return JDFNode: The spawned node.
		* 
		* @default spawnInformative(parentURL, 
		*                           WString::emptyStr, 
		*                           mAttribute::emptyvMap, 
		*                           false, 
		*                           false, 
		*                           false, 
		*                           false); 
		*
		*/
		JDFDoc spawnInformative(const WString& _parentURL, 
			const WString& _spawnURL=WString::emptyStr, 
			const vmAttribute& _vSpawnParts=vmAttribute::emptyvMap, 
			bool _bSpawnROPartsOnly=false,
			bool _bCopyNodeInfo=false, 
			bool _bCopyCustomerInfo=false,
			bool _bCopyComments=false);

		/**
		* Method unSpawn. undo a spawn, removing any and all bookkeeping of that spawning
		* 
		* @param spawnID spawnID of the spawn to undo
		* @return the fixed unspawned node
		*/
		JDFNode unSpawn(const WString& spawnID);

		/******************************
		* variables
		*******************************/
		/**
		* if true, reduce read only partitions, else retain entire resource
		*/
		bool bSpawnROPartsOnly;
		/**
		* if true, copy node info
		*/
		bool bCopyNodeInfo; 
		/**
		* if true, copy customer info
		*/
		bool bCopyCustomerInfo;
		/**
		* if true, copy comments
		*/
		bool bCopyComments;
		/**
		* if true, ensure sufficient partitioning of rw resources, else do not add missing partitions
		*/
		bool bFixResources;
		WString parentURL;
		WString spawnURL;
		/**
		* list of all resources to copy rw
		*/
		vWString vRWResources_in;
		/**
		* list of partitions to spawn
		*/
		vmAttribute vSpawnParts;
		///**
		//* exception id for multiple merge attempt
		//*/
		//const static int exAlreadyMerged=10001;
		///**
		//* exception id for multiple rw spawns
		//*/
		//const static int exMultiSpawnRW=10002;

	private:
		/******************************
		* methods
		*******************************/
		/**
		* calculate whether a link should be RW or RO
		* 
		* @param    JDFResourceLink li the link to check
		* @param    VString vRWResources the list of resource ids, process usages, usages, names. 
		*           If any match, the referenced resource is considered rw
		* @return   boolean true if rw
		*/
		bool linkFitsRWRes(const JDFResourceLink& li,  const vWString& vRWResources);

		/**
		* calculate whether a link should be RW or RO
		* 
		* @param    JDFResourceLink li the link to check
		* @param    VString vRWResources the list of resource ids, process usages, usages, names. 
		*           If any match, the referenced resource is considered rw
		* @return   boolean true if rw
		*/
		bool resFitsRWRes(const JDFResource& r, const vWString& vRWResources);

		vElement prepareSpawnLinks(const JDFNode& rootOut);

		void setSpawnParent(JDFNode& rootOut, const JDFNode& parent);

		JDFSpawned createSpawnAudit(const JDFNode& rootOut, const WString& spawnID, JDFNode& spawnParentNode);

		/**
		* add any resources that live in ancestor nodes to this node
		* @param  rootOut:
		* @param  spawnAudit:
		* @return int: number of resources added to the spawned node
		*/
		int addSpawnedResources(JDFNode& rootOut, JDFSpawned& spawnAudit);

		/**
		* copies a resource recursively and optionally fixes 
		* status flags and locks in the source resource
		* 
		* @param p              the pool to copy r into 
		* @param r              the resource to copy 
		* @param copyStatus     rw or ro
		* @param vParts         part map vector of the partitions to copy
		* @param spawnID        the spawnID of the spawning that initiated the copy
		* @param resInPool      internal recursion checker 
		* @param vRWResources   write resources
		* 
		* @return VString       vector of resource names that have been copied
		*/
		void copySpawnedResource(JDFResourcePool& p, JDFResource& r, JDFResource::EnumSpawnStatus copyStatus, const vmAttribute& vParts, const WString& spawnID, const vWString& vRWResources, vWString& vRWIDs, vWString& vROIDs, SetWString& allIDsCopied);

		void fixSpawnPartitions(JDFResource& r, const vWString& rootPartIDKeys);

		void finalizeSpawn(const vmAttribute& vLocalSpawnParts, const vElement& outLinks, JDFSpawned& spawnAudit);

		/**
		* unSpawnNode - undo a spawn of a node
		* hier muss noch nachportiert werden - es gibt jetzt in JDFRoot eine Methode
		* gleichen Namens, bei der man komfortabler das undo aufrufen kann.
		* die Methode hier in JDFNode wird dann umbenannt (protected) und aus JDFRoot heraus 
		* aufgerufen.
		*
		* @param WString: strSpawnID  id of the node, which was spawned before
		*
		* @return the fixed unspawned node
		*/
		JDFNode unSpawnNode(const WString& strSpawnID);

		/******************************
		* variables
		*******************************/
		JDFNode node;

	}; // class JDFSpawn
}; // namespace JDF
#endif // _JDFSPAWN_H_
