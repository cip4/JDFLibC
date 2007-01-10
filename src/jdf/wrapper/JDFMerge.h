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
// 310806 | NB | ported JDFMerge from JDFLib-J

#if !defined _JDFMERGE_H_
#define _JDFMERGE_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000 

#include "JDFNode.h"

namespace JDF{
	class JDFMerged;

	/**
	* @author Rainer Prosi
	* This class is used when merging a JDF node it summarizes all 
	* merging routines the had been part of JDF Node
	*/
	class JDF_WRAPPERCORE_EXPORT JDFMerge
	{
	public:
		/******************************
		* Construction / Destruction
		*******************************/
		JDFMerge(const JDFNode& n);
		inline ~JDFMerge() {};

		/******************************
		* methods
		*******************************/
		/**
		* merge a previously spawned JDF into a node that is a child of, or this root <br>
		* note that the return value used to be boolean. The boolean value is now replaced by exceptions. This corresponds to <true> always.
		* <p>
		* default:  mergeJDF(toMerge, WString::emptyStr, 
		*              JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_None)
		*
		* @param JDFNode      toMerge the previously spawned jdf node
		* @param WString      urlMerge the url of the ???
		* @param cleanPolicy  policy how to clean up the spawn and merge audits after merging
		* @param amountPolicy policy how to clean up the Resource amounts after merging
		* @return JDFNode: the merged node in the new document
		* 
		* @throws JDFException if toMerge has already been merged 
		* @throws JDFException if toMerge was not spawned from this
		* @throws JDFException if toMerge has no AncestorPool
		* 
		*/
		JDFDoc mergeJDF(JDFNode& toMerge, const WString& urlMerge=WString::emptyStr, JDFNode::EnumCleanUpMerge cleanPolicy=JDFNode::CleanUpMerge_None, 
			JDFResource::EnumAmountMerge amountPolicy=JDFResource::AmountMerge_None);


	private:
		/******************************
		* methods
		*******************************/
		WString mergeCheckPrespawn(JDFNode& toMerge, const JDFSpawned& spawnAudit, vWString& vsRO, vWString& vsRW);

		static void mergeLocalLinks(const JDFNode& overWriteNode, const JDFNode& toMerge, const vmAttribute& parts);

		/**
		* merge the resource link pools
		* @param overWriteNode
		* @param oMerge the source node of the status pool to merge into this
		* @param parts  the partitions to merge
		*/
		static void mergeResourceLinkPool(const JDFNode& overWriteNode, JDFNode& toMerge, const vmAttribute& parts);

		/**
		* merge the RO resources of the main JDF
		* @param overWriteNode
		* @param toMerge       the source node of the status pool to merge into this
		* @param previousMergeIDs SpawnIDs of previously merged 
		* @param vsRO          Resource IDs of non-local spawned resources 
		* @param spawnID       the original spawnID 
		*/
		static void cleanROResources(JDFNode& overWriteNode,JDFNode& toMerge, const vWString& previousMergeIDs, const vWString& vsRO, const WString& spawnID);

		/**
		* merge the RW resources of the main JDF
		* @param overWriteNode
		* @param toMerge          the source node of the status pool to merge into this
		* @param previousMergeIDs SpawnIDs of previously merged 
		* @param vsRW             Resource IDs of non-local spawned resources 
		* @param spawnID          the original spawnID 
		* @param amountPolicy  
		*/
		static void mergeRWResources(JDFNode& overWriteNode, JDFNode& toMerge, const vWString& previousMergeIDs, const vWString& vsRW, const vWString& spawnID, JDFResource::EnumAmountMerge amountPolicy);

		static void mergeLocalNodes(JDFNode& overWriteNode, JDFNode& toMerge, const vWString& previousMergeIDs, const WString& spawnID, JDFResource::EnumAmountMerge amountPolicy, const vmAttribute& parts);

		static void mergeLocalResource(const vWString& previousMergeIDs, const WString& spawnID, JDFResource::EnumAmountMerge amountPolicy, JDFResourcePool& poolToMerge, JDFResource& res1);

		/**
		* merge the audit pools
		* @param overWriteNode
		* @param JDFNode& toMerge the source node of the audit pool to merge into this
		*/
		static void mergeAuditPool(JDFNode& overWriteNode, JDFNode& toMerge);

		/**
		* merge the status pools
		* @param overWriteNode
		* @param JDFNode& toMerge the source node of the status pool to merge into this
		* @param mAttribute parts the partitions to merge
		*/
		static void mergeStatusPool(JDFNode& overWriteNode, JDFNode& toMerge, const vmAttribute& parts);

		static void mergeComments(JDFNode& overWriteNode, JDFNode& toMerge);

		static JDFMerged mergeMainPools(JDFNode& overWriteNode, JDFNode& toMerge, const vmAttribute& parts, const vWString& vsRW, const vWString& spawnID, const WString& preSpawn, const WString& urlMerge, bool bSnafu);

		static void cleanUpMerge(JDFNode& overWriteNode, JDFNode::EnumCleanUpMerge cleanPolicy, const WString& spawnID, bool bRecurse);

		/******************************
		* variables
		*******************************/
		JDFNode node;
	}; // class JDFMerge
}; // namespace JDF
#endif // _JDFMERGE_H_
