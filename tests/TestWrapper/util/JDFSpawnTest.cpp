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
// Copyright (c) 2001-2004 The International Cooperation for the Integration 
// of Processes in  Prepress, Press and Postpress (CIP4).  All rights reserved.
//
// Author: Niels Boeger
//
// Revision history:
// created 06 Oct 2006
//
// JDFSpawnTest.cpp: implements CppUnit tests for JDFSpawn
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFSpawn.h"
#include "jdf/wrapper/JDFMerge.h"
#include "JDFSpawnTest.h"
#include <iostream>
#include "time.h"

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFSpawnTest);

const WString sm_dirTestData = L"data\\";
const WString sm_dirTestTemp = L"temp\\";

void JDFSpawnTest::setUp()
{
	try	
	{
		JDF::PlatformUtils::Initialize();
	}
	catch (const JDF::Exception& e)	
	{
		e.getMessage();
	}
}

static JDFDoc creatXMDoc()
{
	JDFElement::setDefaultJDFVersion(JDFElement::Version_1_3);
	JDFDoc doc(0);
	JDFNode n=doc.GetJDFRoot();
	n.SetJobPartID("P1");
	n.SetJobID("J1");
	n.SetType("ConventionalPrinting");
	n.AppendElement("NS:Foobar","www.foobar.com");

	JDFComponent comp=(JDFComponent)n.AppendMatchingResource("Component",JDFNode::ProcessUsage_AnyOutput,JDFNode::DefJDFNode);
	JDFExposedMedia xm=(JDFExposedMedia)n.AppendMatchingResource("ExposedMedia",JDFNode::ProcessUsage_Plate,JDFNode::DefJDFNode);
	JDFNodeInfo ni=n.AppendNodeInfo();
	JDFMedia m=xm.AppendMedia();
	m.AppendElement("NS:FoobarMedia","www.foobar.com");

	CPPUNIT_ASSERT_EQUAL( JDFResource::Class_Consumable,m.GetClass() );

	vWString vs;
	vs.add("SignatureName");
	vs.add("SheetName");
	vs.add("Side");

	JDFAttributeMap mPart1("SignatureName","Sig1");
	mPart1.put("SheetName","S1");
	mPart1.put("Side","Front");       
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("Side","Back");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("SheetName","S2");
	mPart1.put("Side","Front");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("Side","Back");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("SignatureName","Sig2");
	mPart1.put("SheetName","S1");
	mPart1.put("Side","Front");       
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);
	comp.AppendElement("foo:bar","www.foobar.com");


	mPart1.put("Side","Back");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("SheetName","S2");
	mPart1.put("Side","Front");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("Side","Back");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);	
	return doc;
}

static WString spawn(WString strXMLFile, WString strSpawnedFile, WString strElementID,vWString vRWResources,vmAttribute vSpawnParts)
{
	WString strSpawnID = WString::emptyStr;
	try
	{		
		// parse input file
		JDFParser p;
		p.Parse(sm_dirTestData+strXMLFile, false);
		JDFDoc jdfDocIn = p.GetDocument();
		CPPUNIT_ASSERT( !jdfDocIn.isNull() );

		// prepare the spawn process
		JDFNode rootIn = (JDFNode) jdfDocIn.GetRoot();

		JDFNode spawnNode;
		if (strElementID.equals(WString::emptyStr))
		{
			spawnNode = rootIn;
		}
		else
		{
			spawnNode = (JDFNode) rootIn.GetTarget(strElementID, JDFElement::atr_ID);
		}
		CPPUNIT_ASSERT( !spawnNode.isNull() );

		JDFDoc docSpawned = JDFDoc(0);
		JDFNode jdfSpawned;// = spawnNode.SpawnInformative(sm_dirTestData+strXMLFile, WString::emptyStr, vmAttribute::emptyvMap,false, true, true, true).GetJDFRoot();
		WString spawnID;//=jdfSpawned.GetSpawnID();

		WString big;
		//jdfDocIn.Write2String(big);
		//CPPUNIT_ASSERT( big.indexOf(spawnID)<0 );

		docSpawned = spawnNode.Spawn(
			sm_dirTestData+strXMLFile, WString::emptyStr, vRWResources, vSpawnParts,false, true, true, true);
		jdfSpawned = docSpawned.GetJDFRoot();
		spawnID=jdfSpawned.GetSpawnID();
		jdfDocIn.Write2String(big);
		CPPUNIT_ASSERT( big.indexOf(spawnID)>=0 );

		// get new spawned file
		JDFNode rootOut = jdfSpawned;
		XMLDoc docOut = rootOut.GetOwnerDocument();
		docOut.Write2File(sm_dirTestTemp + strSpawnedFile);

		// get changed input file
		rootIn.EraseEmptyNodes(true);
		WString strXMLFileModified = "_" + strXMLFile;
		jdfDocIn.Write2File(sm_dirTestTemp + strXMLFileModified);

		strSpawnID = rootOut.GetSpawnID();		
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}

	return strSpawnID;
}

static void unSpawn(WString& strXMLFile, WString& strSpawnID)
{
	try
	{
		WString strXMLFileModified = "_" + strXMLFile;

		JDFParser p;
		p.Parse(sm_dirTestTemp + strXMLFileModified,false);

		JDFDoc doc = p.GetDocument();

		// parse the original file, which is already spawned 
		CPPUNIT_ASSERT( !doc.isNull() );

		JDFNode root = (JDFNode) doc.GetRoot();
		CPPUNIT_ASSERT( !root.isNull() );
		if (!root.isNull())
		{
			root=JDFSpawn(root).unSpawn(strSpawnID);
			CPPUNIT_ASSERT( root.ToString().indexOf(strSpawnID) < 0 );

			// write out the unspawned file
			doc.Write2File(sm_dirTestTemp + "Unspawn_" + strXMLFile);  // Unspawn_bookintent.jdf
		}  
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testCorruptPartitionedSpawn()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode root=d.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_ProcessGroup));
		JDFNode cp=root.AddJDFNode(JDFNode::Type_ConventionalPrinting);
		JDFNode fold=root.AddJDFNode(JDFNode::Type_Folding);
		JDFComponent comp=(JDFComponent) cp.addResource("Component", JDFResource::Class_Quantity, JDFResourceLink::Usage_Output, WString::emptyStr, root);
		JDFAttributeMap cMap;
		cMap.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SignatureName), "Sig1");
		cMap.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName), "S1");
		cMap.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_Condition), "Good");
		comp.GetCreatePartition(cMap, vWString("SignatureName SheetName Condition"," "));
		cMap.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_Condition), "Waste");
		comp.GetCreatePartition(cMap);
		comp.SetStatus(JDFResource::Status_Available, true);
		fold.linkResource(comp, JDFResourceLink::Usage_Input, JDFNode::ProcessUsage_Unknown);

		JDFComponent compOut=(JDFComponent) fold.addResource("Component", JDFResource::Class_Quantity, JDFResourceLink::Usage_Output, WString::emptyStr, root);
		compOut.AddPartition(JDFResource::PartIDKey_Condition, "Good");
		compOut.AddPartition(JDFResource::PartIDKey_Condition, "Waste");
		JDFAttributeMap map;
		map.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SignatureName), "Sig1");
		//      map.put(EnumPartIDKey.SheetName, "Sht1");
		vmAttribute v;
		v.push_back(map);
		vWString vRW=vWString("Output",WString::emptyStr);
		JDFSpawn spawn=JDFSpawn(fold);
		JDFDoc spawned=spawn.spawn(WString::emptyStr, WString::emptyStr, vRW, v, true, true, true, true);

		JDFComponent spCompOut=(JDFComponent) spawned.GetJDFRoot().GetMatchingLink("Component", JDFNode::ProcessUsage_AnyOutput, 0).GetLinkRoot();
		CPPUNIT_ASSERT( spCompOut.IsValid(KElement::ValidationLevel_Incomplete) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testSubsetPartitionedSpawn()
{
	try
	{
		for(int i=0;i<2;i++)
		{
			JDFDoc d=JDFDoc(0);
			JDFNode root=d.GetJDFRoot();
			root.SetType(JDFNode::TypeString(JDFNode::Type_ProcessGroup));
			JDFNode cp=root.AddJDFNode(JDFNode::Type_ConventionalPrinting);
			JDFComponent comp=(JDFComponent) cp.addResource("Component", JDFResource::Class_Quantity, JDFResourceLink::Usage_Output,WString::emptyStr,root);
			JDFAttributeMap cMap;
			cMap.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SignatureName), "Sig1");
			cMap.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName), "S1");
			comp.GetCreatePartition(cMap, vWString("SignatureName SheetName"));
			comp.GetCreatePartition(cMap, vWString::emptyvStr);
			comp.SetStatus(JDFResource::Status_Available, true);

			cMap.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_Side), "Front");
			vmAttribute v;
			v.push_back(cMap);
			vWString vRW=vWString("Output",WString::emptyStr);

			JDFNodeInfo ni=cp.AppendNodeInfo();
			ni.GetCreatePartition(cMap,vWString("SignatureName SheetName Side"));			

			JDFSpawn spawn=JDFSpawn(cp);
			if(i==0)
				spawn.bFixResources=false;
			JDFDoc spawned=spawn.spawn(WString::emptyStr, WString::emptyStr, vRW, v, true, true, true, true);

			JDFComponent spCompOut=(JDFComponent) spawned.GetJDFRoot().GetMatchingLink("Component", JDFNode::ProcessUsage_AnyOutput).GetLinkRoot();
			if(i==0)
				CPPUNIT_ASSERT( spCompOut.GetPartition(cMap, JDFResource::PartUsage_Unknown).isNull() ); // partition structure is zapped
			else
				CPPUNIT_ASSERT( !spCompOut.GetPartition(cMap, JDFResource::PartUsage_Unknown).isNull() ); // partition structure is not zapped
			cMap.remove(JDFResource::PartIDKeyString(JDFResource::PartIDKey_Side));
			CPPUNIT_ASSERT( !spCompOut.GetPartition(cMap, JDFResource::PartUsage_Unknown).isNull() ); // partition structure is zapped
		}
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testSpawnPartMulti()
{
	try
	{
		JDFDoc dRoot=JDFDoc(0);
		JDFNode nRoot=dRoot.GetJDFRoot();
		JDFCustomerInfo ci=nRoot.AppendCustomerInfo();
		ci.SetCustomerProjectID("foo");

		nRoot.SetType("Product");

		JDFDoc d=creatXMDoc();
		JDFNode n=(JDFNode) nRoot.CopyElement(d.GetJDFRoot());
		JDFExposedMedia xm=(JDFExposedMedia) n.GetMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput);
		JDFNode nPS=nRoot.AddJDFNode(JDFNode::Type_ImageSetting);
		nPS.linkResource(xm,false ? JDFResourceLink::Usage_Input : JDFResourceLink::Usage_Output,JDFNode::ProcessUsage_Unknown);
		vWString v;
		v.add(JDFNode::elm_ExposedMedia);
		vmAttribute vMap;
		JDFAttributeMap map;
		map.put("SignatureName","Sig1");
		vMap.push_back(map);

		JDFSpawn spawn=JDFSpawn(nPS);
		JDFDoc spawnedDoc=spawn.spawnInformative(WString::emptyStr,WString::emptyStr,vMap,false, true, true, true);
		JDFNode spawnedPSNodeInfo=spawnedDoc.GetJDFRoot();
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",spawnedPSNodeInfo.GetInheritedCustomerInfo().GetCustomerProjectID() );

		spawn=JDFSpawn(nPS);
		spawnedDoc=spawn.spawn(WString::emptyStr,WString::emptyStr,v,vMap,false,true,true,true);

		JDFNode spawnedPSNode=spawnedDoc.GetJDFRoot();
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",spawnedPSNode.GetInheritedCustomerInfo().GetCustomerProjectID() );

		// this one spawns the component rw
		v.clear();
		v.add(JDFNode::elm_Component);

		spawn=JDFSpawn(n);

		spawnedDoc=spawn.spawn("thisUrl","newURL",v,vmAttribute::emptyvMap,false,true,true,true); 
		JDFNode spawnedNodeAll=spawnedDoc.GetJDFRoot();
		WString spawnID=spawnedNodeAll.GetSpawnID();		
		// merge and immediately respawn the same thing
		JDFMerge merge=JDFMerge(nRoot);
		JDFDoc docMerge=merge.mergeJDF(spawnedNodeAll, WString::emptyStr, JDFNode::CleanUpMerge_RemoveAll,JDFResource::AmountMerge_UpdateLink);
		n=docMerge.GetJDFRoot();
		CPPUNIT_ASSERT( nRoot.ToString().indexOf(spawnID)<0 ); // SpawnID gone

		spawn=JDFSpawn(n);
		spawnedDoc = spawn.spawn("thisUrl","newURL",v,vMap,false,true,true,true); 
		JDFNode spawnedNode=spawnedDoc.GetJDFRoot(); 
		spawnID=spawnedNode.GetSpawnID();
		CPPUNIT_ASSERT( spawnedNode.HasChildElement(JDFNode::elm_AncestorPool) );

		// merge and immediately respawn the same thing
		merge = JDFMerge(n);
		docMerge = merge.mergeJDF(spawnedNode, WString::emptyStr, JDFNode::CleanUpMerge_RemoveAll, JDFResource::AmountMerge_UpdateLink);
		n=docMerge.GetJDFRoot();
		CPPUNIT_ASSERT( nRoot.ToString().indexOf(spawnID) < 0 );
		spawn=JDFSpawn(n);

		spawnedDoc = spawn.spawn("thisUrl","newURL",v,vMap,false,true,true,true);
		spawnedNode = spawnedDoc.GetJDFRoot();
		CPPUNIT_ASSERT( spawnedNode.HasChildElement(JDFNode::elm_AncestorPool) );

		map.put("SheetName","S1");
		spawn=JDFSpawn(spawnedNode);
		spawnedDoc = spawn.spawn("reUrl","renewURL",v,vMap,false,true,true,true);

		JDFNode respawnedNode = spawnedDoc.GetJDFRoot();

		CPPUNIT_ASSERT( spawnedNode.HasChildElement(JDFNode::elm_AncestorPool) );

		xm=(JDFExposedMedia) respawnedNode.GetMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput);
		JDFComponent comp=(JDFComponent) respawnedNode.GetMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
		vWString vSpID=xm.GetSpawnIDs(false);
		CPPUNIT_ASSERT( vSpID.empty() );
		xm=(JDFExposedMedia) xm.GetPartition(map);
		CPPUNIT_ASSERT( xm.GetLocked() );
		comp=(JDFComponent) comp.GetPartition(map);
		CPPUNIT_ASSERT( !comp.GetLocked() );

		map.put("SheetName","S2");
		spawn=JDFSpawn(spawnedNode);
		spawnedDoc = spawn.spawn("reUrl","renewURL",v,vMap,false,true,true,true);
		JDFNode respawnedNode2 = spawnedDoc.GetJDFRoot();
		xm=(JDFExposedMedia) respawnedNode2.GetMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput);
		comp=(JDFComponent) respawnedNode2.GetMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
		vSpID=xm.GetSpawnIDs(false);
		CPPUNIT_ASSERT( vSpID.empty() );  // SpawnIDS
		xm=(JDFExposedMedia) xm.GetPartition(map);
		CPPUNIT_ASSERT( xm.GetLocked() ); // xm rw
		comp=(JDFComponent) comp.GetPartition(map);
		CPPUNIT_ASSERT( !comp.GetLocked() );  // comp rw
		WString spawnID1=spawnedNode.GetSpawnID();
		merge = JDFMerge(spawnedNode);
		docMerge = merge.mergeJDF(respawnedNode2, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_UpdateLink);
		JDFNode testSpawnedNode=docMerge.GetJDFRoot();
		CPPUNIT_ASSERT( spawnedNode.HasChildElement(JDFNode::elm_AncestorPool) ); // AncestorPool after respawn merge
		CPPUNIT_ASSERT_EQUAL( spawnID1,testSpawnedNode.GetSpawnID() ); // spawnID ok
		spawn=JDFSpawn(spawnedNode);
		spawnedDoc = spawn.spawn("reUrl","renewURL",v,vMap,false,true,true,true);
		respawnedNode2 = spawnedDoc.GetJDFRoot();

		// now go backwards!
		JDFMerge(nRoot).mergeJDF(spawnedNode, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_UpdateLink);
		JDFMerge(nRoot).mergeJDF(respawnedNode, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_UpdateLink);
		JDFMerge(nRoot).mergeJDF(respawnedNode2, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_UpdateLink);


		JDFMerge(nRoot).mergeJDF(spawnedPSNode, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_UpdateLink);
		CPPUNIT_ASSERT( nRoot.ToString().indexOf("SpawnIDs") < 0 ); // spawnIDs gone
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testSpawnPart()
{
	try
	{
		JDFDoc d=creatXMDoc();
		JDFNode n=d.GetJDFRoot();
		n.RemoveNodeInfos();
		JDFNodeInfo ni=n.GetCreateNodeInfo();
		CPPUNIT_ASSERT( !ni.isNull() );
		JDFComment comment=n.AppendComment();
		comment.SetText("Comment 1");
		JDFResourceLink l=n.GetMatchingLink(JDFNode::elm_NodeInfo,JDFNode::ProcessUsage_AnyInput);
		l.SetPartition(JDFResource::PartIDKey_SignatureName,"Sig1");
		vWString v;
		v.add(JDFNode::elm_ExposedMedia);
		vmAttribute vMap;
		JDFAttributeMap map;
		map.put("SignatureName","Sig1");
		map.put("SheetName","S1");
		vMap.push_back(map);
		JDFResourceLink xmRL=n.GetMatchingLink(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput,0);
		xmRL.SetAmount(40,map);
		xmRL.SetUsage(JDFResourceLink::Usage_Output);
		xmRL.SetAttribute("foo:bar","a","www.foobar.com");
		JDFSpawn spawn=JDFSpawn(n); // fudge to test output counting
		JDFDoc spawnDoc=spawn.spawn("thisUrl","newURL",v,vMap,false,true,true,true);
		JDFNode spawnedNode=spawnDoc.GetJDFRoot();
		CPPUNIT_ASSERT( spawnedNode.ToString().indexOf(JDFNode::atr_SpawnStatus)<0 ); // no spawnstatus
		JDFResourceLink rl = spawnedNode.GetMatchingLink(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_Any);
		JDFResourceAudit ra=spawnedNode.CloneResourceToModify(rl);
		WString clonedResID=ra.GetOldLink().GetrRef();

		n=d.GetJDFRoot();
		JDFComment comment2=n.AppendComment();
		comment2.SetText("Comment 2 after");
		JDFComment comment3=spawnedNode.AppendComment();
		comment3.SetText("Comment 3 spawned");

		JDFResourceLink xmRLspawn=spawnedNode.GetMatchingLink(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyOutput);
		xmRLspawn.SetActualAmount(42,map);
		CPPUNIT_ASSERT_EQUAL( (WString)"a",xmRLspawn.GetAttribute("bar","www.foobar.com") );
		CPPUNIT_ASSERT_EQUAL( 40.,xmRLspawn.GetAmount(map) ); // amount ok
		CPPUNIT_ASSERT_EQUAL( 42.,xmRLspawn.GetActualAmount(map) ); // act amount ok

		// n is fine up to here, then amount is misplaced
		JDFMerge merge=JDFMerge(n);
		JDFDoc docMerge=merge.mergeJDF(spawnedNode, "merged", JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_UpdateLink);
		JDFNode mergedNode=docMerge.GetJDFRoot();
		xmRL=mergedNode.GetMatchingLink(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyOutput);
		CPPUNIT_ASSERT_EQUAL( 1,(int)mergedNode.GetResourceLinkPool().GetPoolChildren("NodeInfoLink").size() ); // no spurious ni added
		CPPUNIT_ASSERT_EQUAL( 3,(int)mergedNode.GetChildElementVector(JDFNode::elm_Comment,WString::emptyStr, mAttribute::emptyMap,true,99).size() ); // Comment size
		CPPUNIT_ASSERT_EQUAL( 40.,xmRL.GetAmount(map) ); // merged amount ok
		CPPUNIT_ASSERT_EQUAL( 42.,xmRL.GetActualAmount(map) ); // merged act amount
		CPPUNIT_ASSERT_EQUAL( (WString)"a",xmRL.GetAttribute("bar","www.foobar.com") ); // did not overwrite rl attribute

		JDFExposedMedia xm=(JDFExposedMedia) n.GetMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyOutput);
		xm=(JDFExposedMedia) xm.GetPartition(map);
		CPPUNIT_ASSERT_EQUAL( 42.,xm.GetAmount() ); // merged res amount ok
		CPPUNIT_ASSERT_EQUAL( 42.,xm.GetAmountProduced() ); // merged res amountproduced ok

		// test whether anything modified and tracked in a resource audit got correctly merged
		JDFResourceAudit raMerge=(JDFResourceAudit) n.GetAuditPool().GetAudit(0, JDFAudit::AuditType_ResourceAudit);
		CPPUNIT_ASSERT( !raMerge.isNull() ); // res audit merged
		JDFResource rOld=raMerge.GetOldLink().GetTarget();
		CPPUNIT_ASSERT( !rOld.isNull() ); // old res  merged
		CPPUNIT_ASSERT_EQUAL( clonedResID,rOld.GetID() ); // old res ID
		JDFResource rNew=raMerge.GetNewLink().GetTarget();
		CPPUNIT_ASSERT( !rNew.isNull() ); // new res  merged
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testSpawn2()
{
	try
	{
		WString spawnNodeID = "Link08539766_000147";
		WString fileNameIn  = "km2";

		JDFParser p;
		p.Parse(sm_dirTestData+fileNameIn+".jdf",false);
		JDFDoc jdfDocIn = p.GetDocument();
		CPPUNIT_ASSERT_MESSAGE( "parse of input file failed", !jdfDocIn.isNull() );

		// prepare the spawn process
		JDFNode rootIn = (JDFNode) jdfDocIn.GetRoot();

		JDFNode spawnNode;
		if (spawnNodeID == WString::emptyStr)
		{
			spawnNode = rootIn;
		}
		else
		{
			spawnNode = (JDFNode) rootIn.GetTarget(spawnNodeID, JDFNode::atr_ID);
		}
		CPPUNIT_ASSERT( !spawnNode.isNull() );

		JDFSpawn spawn=JDFSpawn(spawnNode);		
		JDFDoc ds = spawn.spawn(sm_dirTestData+fileNameIn+".jdf",WString::emptyStr,vWString::emptyvStr,vmAttribute::emptyvMap,false,true,true,true);
		JDFNode jdfSpawned = ds.GetJDFRoot();

		// veraendertes Ausgangsfile rausschreiben
		rootIn.EraseEmptyNodes(true);
		WString strXMLFileModified = fileNameIn + "_spawnedSource.xml";
		//jdfDocIn.Write2File(sm_dirTestTemp + strXMLFileModified);

		XMLDoc doc2 = KElement(jdfSpawned).GetOwnerDocument();
		WString strXMLFileModified2 = fileNameIn + "_spawnedTarget.xml";
		//doc2.Write2File(sm_dirTestTemp + strXMLFileModified2);
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testSpawn3()
{
	try
	{
		WString fileNameIn = "km2";

		JDFParser p;
		p.Parse(sm_dirTestData+fileNameIn+".jdf",false);
		JDFDoc jdfDocIn = p.GetDocument();

		JDFNode root   = jdfDocIn.GetJDFRoot();
		JDFNode subJob = root.GetJobPart("Qua0"); //Link08539766_000147
		vElement v = subJob.GetChildElementVector("JDF", WString::emptyStr, mAttribute::emptyMap, false, WString::pINF,false);
		vElement v2;
		int nEvent=0;
		int nComment=0;

		// spawn/merge no. 1
		{
			int i = 0;
			JDFNode spawnNode = (JDFNode)v[i];
			spawnNode.GetCreateAuditPool().AddNotification(JDFAutoNotification::Class_Event,"me");
			spawnNode.AppendComment().SetText("Comment"+i);
			JDFSpawn spawn=JDFSpawn(spawnNode);
			JDFDoc spawnDoc = spawn.spawn(sm_dirTestData + fileNameIn + ".jdf",WString::emptyStr,vWString::emptyvStr,vmAttribute::emptyvMap,false,true,true,true);
			JDFNode spawnedNode = spawnDoc.GetRoot();
			v2.add(spawnedNode);
			nEvent+=(int)spawnedNode.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false).size();
			nComment+=spawnedNode.NumChildNodes(8); // 8 -> comment nodes
			JDFNode nodeToMerge = v2[i];
			JDFMerge(root).mergeJDF(nodeToMerge, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_None);
			CPPUNIT_ASSERT_EQUAL( nEvent,(int)root.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false,0).size() );
		}

		// spawn/merge no. 2
		{
			int i = 1;
			JDFNode spawnNode = (JDFNode)v[i];
			spawnNode.GetCreateAuditPool().AddNotification(JDFAutoNotification::Class_Event,"me");
			spawnNode.AppendComment().SetText("Comment"+i);
			JDFSpawn spawn=JDFSpawn(spawnNode);
			JDFDoc spawnDoc = spawn.spawn(sm_dirTestData + fileNameIn + ".jdf",WString::emptyStr,vWString::emptyvStr,vmAttribute::emptyvMap,false,true,true,true);
			JDFNode spawnedNode = spawnDoc.GetRoot();
			v2.add(spawnedNode);
			nEvent+=(int)spawnedNode.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false).size();
			nComment+=spawnedNode.NumChildNodes(8); // 8 -> comment nodes
			JDFNode nodeToMerge = v2[i];
			JDFMerge(root).mergeJDF(nodeToMerge, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_None);
			CPPUNIT_ASSERT_EQUAL( nEvent,(int)root.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false,0).size() );
		}

		// spawn/merge no. 3
		{
			int i = 2;
			JDFNode spawnNode = (JDFNode)v[i];
			spawnNode.GetCreateAuditPool().AddNotification(JDFAutoNotification::Class_Event,"me");
			spawnNode.AppendComment().SetText("Comment"+i);
			JDFSpawn spawn=JDFSpawn(spawnNode);
			JDFDoc spawnDoc = spawn.spawn(sm_dirTestData + fileNameIn + ".jdf",WString::emptyStr,vWString::emptyvStr,vmAttribute::emptyvMap,false,true,true,true);
			JDFNode spawnedNode = spawnDoc.GetRoot();
			v2.add(spawnedNode);
			nEvent+=(int)spawnedNode.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false).size();
			nComment+=spawnedNode.NumChildNodes(8); // 8 -> comment nodes
			JDFNode nodeToMerge = v2[i];
			JDFMerge(root).mergeJDF(nodeToMerge, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_None);
			CPPUNIT_ASSERT_EQUAL( nEvent,(int)root.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false,0).size() );
		}

		// spawn/merge no. 4
		{
			int i = 3;
			JDFNode spawnNode = (JDFNode)v[i];
			spawnNode.GetCreateAuditPool().AddNotification(JDFAutoNotification::Class_Event,"me");
			spawnNode.AppendComment().SetText("Comment"+i);
			JDFSpawn spawn=JDFSpawn(spawnNode);
			JDFDoc spawnDoc = spawn.spawn(sm_dirTestData + fileNameIn + ".jdf",WString::emptyStr,vWString::emptyvStr,vmAttribute::emptyvMap,false,true,true,true);
			JDFNode spawnedNode = spawnDoc.GetRoot();
			v2.add(spawnedNode);
			nEvent+=(int)spawnedNode.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false).size();
			nComment+=spawnedNode.NumChildNodes(8); // 8 -> comment nodes
			JDFNode nodeToMerge = v2[i];
			JDFMerge(root).mergeJDF(nodeToMerge, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_None);
			CPPUNIT_ASSERT_EQUAL( nEvent,(int)root.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false,0).size() );
		}

		// spawn/merge no. 5
		{
			int i = 4;
			JDFNode spawnNode = (JDFNode)v[i];
			spawnNode.GetCreateAuditPool().AddNotification(JDFAutoNotification::Class_Event,"me");
			spawnNode.AppendComment().SetText("Comment"+i);
			JDFSpawn spawn=JDFSpawn(spawnNode);
			JDFDoc spawnDoc = spawn.spawn(sm_dirTestData + fileNameIn + ".jdf",WString::emptyStr,vWString::emptyvStr,vmAttribute::emptyvMap,false,true,true,true);
			JDFNode spawnedNode = spawnDoc.GetRoot();
			v2.add(spawnedNode);
			nEvent+=(int)spawnedNode.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false).size();
			nComment+=spawnedNode.NumChildNodes(8); // 8 -> comment nodes
			JDFNode nodeToMerge = v2[i];
			JDFMerge(root).mergeJDF(nodeToMerge, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_None);
			CPPUNIT_ASSERT_EQUAL( nEvent,(int)root.GetChildrenByTagName("Notification",WString::emptyStr,mAttribute::emptyMap,false,false,0).size() );
		}

		int copyComments=0;
		v = subJob.GetChildElementVector("JDF", WString::emptyStr, mAttribute::emptyMap, false, WString::pINF,false);
		for(int i = 0; i < v.size(); i++)
		{
			JDFNode spawnNode = (JDFNode)v.elementAt(i);
			copyComments+=spawnNode.NumChildNodes(8); // 8 -> comment node
		}
		CPPUNIT_ASSERT_EQUAL( nComment,copyComments );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testSpawnCINI()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		CPPUNIT_ASSERT( n.GetInheritedCustomerInfo().isNull() );
		n.SetType("ProcessGroup");
		n.SetVersion(JDFNode::VersionString(JDFNode::Version_1_2));
		JDFCustomerInfo ci=n.AppendCustomerInfo();
		ci.SetCustomerOrderID("cid");
		CPPUNIT_ASSERT_EQUAL( (WString)"cid",n.GetInheritedCustomerInfo().GetCustomerOrderID() );

		vWString v;
		v.add("Interpreting");
		v.add("Rendering");

		JDFNode n2=n.AddCombined(v);
		JDFSpawn spawn=JDFSpawn(n2);
		JDFDoc spawnedDoc=spawn.spawn("thisFile","spawnFile",vWString::emptyvStr,vmAttribute::emptyvMap,true,true,true,true);
		JDFNode spawnedNode=spawnedDoc.GetJDFRoot();
		ci= spawnedNode.GetInheritedCustomerInfo();
		CPPUNIT_ASSERT( !ci.isNull() );
		CPPUNIT_ASSERT( !n.GetAuditPool().GetAudit(0, JDFAudit::AuditType_Spawned).isNull() );
		WString spawnID = spawnedNode.GetSpawnID();
		CPPUNIT_ASSERT_EQUAL( (WString)"cid",spawnedNode.GetInheritedCustomerInfo().GetCustomerOrderID() );
		JDFAncestor anc=spawnedNode.GetAncestorPool().GetAncestor(0);
		CPPUNIT_ASSERT( anc.GetAttribute("type",JDFNode::atr_xsiURI).empty() ); // no xsi:type

		n=JDFSpawn(n).unSpawn(spawnID);
		CPPUNIT_ASSERT( !n.isNull() );
		CPPUNIT_ASSERT( d.GetJDFRoot().GetAuditPool().GetAudit(0, JDFAudit::AuditType_Spawned).isNull() );

		n.RemoveCustomerInfos();
		n.SetVersion(JDFNode::VersionString(JDFNode::Version_1_3));
		n.AppendCustomerInfo();
		JDFSpawn _spawn=JDFSpawn(n2);
		spawnedDoc=_spawn.spawn("thisFile","spawnFile",vWString::emptyvStr,vmAttribute::emptyvMap,true,true,true,true);
		spawnedNode=spawnedDoc.GetJDFRoot();
		spawnID = spawnedNode.GetSpawnID();

		ci=spawnedNode.GetInheritedCustomerInfo();
		CPPUNIT_ASSERT( !ci.isNull() );

		n2=JDFSpawn(d.GetJDFRoot()).unSpawn(spawnID);
		CPPUNIT_ASSERT( !n2.isNull() );
		CPPUNIT_ASSERT( n2.ToString().indexOf(spawnID) < 0 ); // n2 has no spawnID
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testBigSpawn()
{
	try
	{
		cout << " *warning: this test is slow*";

		WString strJDFName = sm_dirTestData + "000023_Test_PR3.0.jdf";
		JDFParser parser;
		parser.Parse(strJDFName,false);
		JDFDoc jdfDoc = parser.GetDocument();
		double duration = 0.0;

		for (int i=1;i<10;i++)
		{
			vmAttribute vamParts;
			JDFAttributeMap amParts0;
			amParts0.put("Side", "Front");
			amParts0.put("SignatureName", "Sig002");
			amParts0.put("SheetName", "FB 002");
			vamParts.push_back(amParts0);
			JDFAttributeMap amParts1;
			amParts1.put("Side", "Back");
			amParts1.put("SignatureName", "Sig002");
			amParts1.put("SheetName", "FB 002");
			vamParts.push_back(amParts1);
			vWString vsRWResourceIDs;
			vsRWResourceIDs.add("Link84847227_000309");
			vsRWResourceIDs.add("r85326439_027691");
			JDFNode nodeRoot = jdfDoc.GetJDFRoot();
			JDFNode nodeProc = nodeRoot.GetJobPart("IPD0.I");
			JDFSpawn spawn=JDFSpawn(nodeProc);

			clock_t start = clock();
			JDFDoc docSubJDF = spawn.spawn(strJDFName,WString::emptyStr,vsRWResourceIDs,vamParts,true,true,true,true);
			clock_t finish = clock();
			duration += (double)(finish - start) / CLOCKS_PER_SEC;

			JDFNode nodeSubJDF = docSubJDF.GetJDFRoot();
			CPPUNIT_ASSERT( !nodeSubJDF.isNull() );

			if (!nodeSubJDF.isNull())
			{
				nodeSubJDF.GetOwnerDocument().Write2File(sm_dirTestTemp+"bigSub"+WString::valueOf(i)+".jdf");
				if (i==9)
					jdfDoc.Write2File(sm_dirTestTemp+"bigMainPost.jdf"); 
			}
		}
		cout << endl << "time needed for 9 spawns: " << duration << " sec "; 
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testBigMerge()
{
	try
	{
		cout << " *warning: this test is slow (~130 secs)*";

		/* testBigSpawn() is needed for creating the input files for this test only. 
		** These files have been moved to a permanent folder. */
		//testBigSpawn();

		JDFParser parser;
		parser.Parse(sm_dirTestData+"bigMainPost.jdf",false);
		JDFDoc jdfDoc = parser.GetDocument();
		double duration = 0.0;

		for (int i=9;i>0;i--)
		{
			JDFParser parser2;
			parser2.Parse(sm_dirTestData+"bigSub" + WString::valueOf(i) + ".jdf",false);
			JDFDoc jdfDocSub = parser2.GetDocument();
			JDFNode nodeMain=jdfDoc.GetJDFRoot();      
			JDFNode nodeSub=jdfDocSub.GetJDFRoot();
			WString jobPartID = nodeSub.GetJobPartID();

			JDFMerge merge = JDFMerge(nodeMain);
			clock_t start = clock();
			JDFDoc docMerge = merge.mergeJDF(nodeSub, WString::emptyStr, JDFNode::CleanUpMerge_RemoverRefs, JDFResource::AmountMerge_UpdateLink);
			clock_t finish = clock();
			duration += (double)(finish - start) / CLOCKS_PER_SEC;

			JDFNode overWrite=docMerge.GetJDFRoot().GetJobPart(jobPartID);
			JDFAuditPool ap=overWrite.GetAuditPool();
			JDFAudit audit = ap.GetAudit(0, JDFAudit::AuditType_Merged);
			CPPUNIT_ASSERT( !audit.isNull() );
			CPPUNIT_ASSERT( !audit.HasAttribute(JDFNode::atr_SpawnID) );
		}
		cout << endl << "time for 9 merges: " << duration << " sec ";

		jdfDoc.Write2File(sm_dirTestTemp+"BigMerge.jdf");
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testCheckSpawnedResources()
{
	try
	{
		cout << " *warning: this test is slow*";
		WString strJDFName = "000023_Test_PR3.0.jdf";
		WString strJDFPath = sm_dirTestData + strJDFName;
		JDFParser parser;
		parser.Parse(strJDFPath,false);
		JDFDoc jdfDoc = parser.GetDocument();
		vmAttribute vamParts;
		mAttribute amParts0;
		amParts0.put ("Side", "Front");
		amParts0.put ("SignatureName", "Sig002");
		amParts0.put ("SheetName", "FB 002");
		vamParts.push_back(amParts0);

		mAttribute amParts1;
		amParts1.put ("Side", "Back");
		amParts1.put ("SignatureName", "Sig002");
		amParts1.put ("SheetName", "FB 002");
		vamParts.push_back(amParts1);

		vWString vsRWResourceIDs;
		vsRWResourceIDs.add("Link84847227_000309");
		vsRWResourceIDs.add("r85326439_027691");

		JDFNode nodeProc = jdfDoc.GetJDFRoot().GetJobPart("IPD0.I");

		clock_t start = clock();
		vElement vSpawned = nodeProc.CheckSpawnedResources(vsRWResourceIDs, vamParts);
		clock_t finish = clock();
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;
		cout << endl << "time to check spawned resources: " << duration << " sec ";

		CPPUNIT_ASSERT( vSpawned.empty() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testBookIntent()
{
	try
	{
		WString fileNameIn  = "bookintent.jdf";
		WString fileNameOut = "spawned.jdf";
		WString spawnNodeID = "n0016";

		vWString vRWResources;
		vRWResources.add("Component");
		vRWResources.add("RunList");
		vmAttribute vSpawnParts;

		WString strSpawnID = spawn(fileNameIn, fileNameOut, spawnNodeID, vRWResources, vSpawnParts);
		unSpawn(fileNameIn, strSpawnID);   // "Sp7cb:-7fff"
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testPartitionedSpawn()
{
	try
	{
		WString fileNameIn  = "partitionedSource.jdf";
		WString fileNameOut = "partitionedSpawned.jdf";
		WString spawnNodeID = "n0016";

		vWString vRWResources;
		vRWResources.add("Component");
		vRWResources.add("RunList");

		JDFAttributeMap spawnPart;
		vmAttribute vSpawnParts;
		vSpawnParts.push_back(spawnPart);

		WString strSpawnID = spawn(fileNameIn, fileNameOut, spawnNodeID, vRWResources, vSpawnParts);
		unSpawn(fileNameIn, strSpawnID);
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testRef()
{
	try
	{
		WString fileNameIn  = "ref.jdf";
		WString fileNameOut = "spawn.jdf";
		WString spawnNodeID = "n0027";

		vWString vRWResources;
		vRWResources.add("Media");
		vRWResources.add("ExposedMedia");
		vmAttribute vSpawnParts;

		WString strSpawnID = spawn(fileNameIn, fileNameOut, spawnNodeID, vRWResources, vSpawnParts);
		unSpawn(fileNameIn, strSpawnID);  	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testMergeJDF()
{
	try
	{
		// job.jdf subjdf.jdf -o merged.jdf
		WString m_xmlFile1 = "_bookintent.jdf";
		WString m_xmlFile2 = "spawned.jdf";
		WString m_outFile = "merged.jdf";
		JDFDoc m_jdfDoc;
		JDFDoc m_jdfDoc2;

		JDFParser p;
		p.Parse(sm_dirTestData + m_xmlFile1, false);
		m_jdfDoc = p.GetDocument();
		CPPUNIT_ASSERT( !m_jdfDoc.isNull() );

		JDFParser p2;
		p2.Parse(sm_dirTestData + m_xmlFile2,false);
		m_jdfDoc2 = p2.GetDocument();
		CPPUNIT_ASSERT( !m_jdfDoc2.isNull() );

		JDFNode rootMain = (JDFNode) m_jdfDoc.GetRoot();
		JDFNode rootSpawn = (JDFNode) m_jdfDoc2.GetRoot();
		rootSpawn.SetDescriptiveName("fixup");
		WString root2ID = rootSpawn.GetID();
		JDFComment c2 = rootSpawn.AppendComment();
		c2.SetText("Comment 1");

		rootMain.MergeJDF(rootSpawn, sm_dirTestData + m_xmlFile2,
			JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_None);
		JDFNode nodeMerged = rootMain.GetChildJDFNode(root2ID, false);
		CPPUNIT_ASSERT_EQUAL( WString("fixup"),nodeMerged.GetDescriptiveName() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testCleanupMerge()
{
	try
	{
		// for each EnumCleanupMerge value
		for(int i=0;i<3;i++)
		{
			JDFDoc doc=JDFDoc(0);
			JDFNode node=doc.GetJDFRoot();
			node.SetType(JDFNode::TypeString(JDFNode::Type_ProcessGroup));
			JDFNode n2=node.AddJDFNode(JDFNode::Type_AdhesiveBinding);
			JDFResource r=n2.addResource(JDFNode::elm_AdhesiveBinding, JDFResource::Class_Parameter, JDFResourceLink::Usage_Input, WString::emptyStr, node);
			JDFSpawn sp=JDFSpawn(n2);
			JDFDoc spawnDoc = sp.spawn();
			JDFNode spn=spawnDoc.GetJDFRoot();
			JDFSpawned auditSpawn = (JDFSpawned)node.GetAuditPool().GetAudit(0, JDFAudit::AuditType_Spawned);
			CPPUNIT_ASSERT( !auditSpawn.isNull() );
			CPPUNIT_ASSERT( auditSpawn.GetrRefsROCopied().contains(r.GetID()) );
			JDFNode::EnumCleanUpMerge cm;
			switch (i) 
			{
			case JDFNode::CleanUpMerge_None:
				cm = JDFNode::CleanUpMerge_None;
				break;
			case JDFNode::CleanUpMerge_RemoverRefs:
				cm = JDFNode::CleanUpMerge_RemoverRefs;
				break;
			case JDFNode::CleanUpMerge_RemoveAll:
				cm = JDFNode::CleanUpMerge_RemoveAll;
				break;
			}

			JDFMerge m = JDFMerge(node);
			m.mergeJDF(spn, WString::emptyStr, cm, JDFResource::AmountMerge_None);
			JDFSpawned auditSpawn2 = (JDFSpawned)node.GetAuditPool().GetAudit(0, JDFAudit::AuditType_Spawned);
			JDFMerged mergeSpawn2 = (JDFMerged)node.GetAuditPool().GetAudit(0, JDFAudit::AuditType_Merged);

			switch (cm)
			{
			case JDFNode::CleanUpMerge_None:
				CPPUNIT_ASSERT( !auditSpawn2.isNull() );
				CPPUNIT_ASSERT( auditSpawn2.GetrRefsROCopied().contains(r.GetID()) );
				CPPUNIT_ASSERT_EQUAL( auditSpawn.ToString(),auditSpawn2.ToString() );
				CPPUNIT_ASSERT( !mergeSpawn2.isNull() );
				break;
			case JDFNode::CleanUpMerge_RemoverRefs:
				CPPUNIT_ASSERT( !auditSpawn2.isNull() );
				CPPUNIT_ASSERT( auditSpawn2.GetrRefsROCopied().empty() );
				CPPUNIT_ASSERT_EQUAL( auditSpawn.ToString(),auditSpawn2.ToString() );
				CPPUNIT_ASSERT( !mergeSpawn2.isNull() );
				break;
			case JDFNode::CleanUpMerge_RemoveAll:
				CPPUNIT_ASSERT( auditSpawn2.isNull() );
				CPPUNIT_ASSERT( mergeSpawn2.isNull() );
				break;
			}
		}
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testMergeJDF2()
{
	try
	{
		JDFParser p;
		p.Parse(sm_dirTestData+"testMergeJDF2.jdf", false);
		JDFDoc myDoc = p.GetDocument();
		JDFNode root = (JDFNode) myDoc.GetRoot();
		vWString rwResources;

		JDFAttributeMap myMap;

		myMap.put("Type", "Imposition");
		myMap.put("Status", "Waiting");

		vElement elemVec = root.GetChildrenByTagName("JDF", WString::emptyStr, myMap ,false ,true , 0); 
		JDFNode spawnnode = (JDFNode) elemVec.elementAt(0);		

		rwResources.add("Output");

		JDFSpawn spawn(spawnnode);

		JDFDoc spawnDoc = spawn.spawn(sm_dirTestData+"testMergeJDF2.jdf",sm_dirTestTemp+"myTest_spawned.jdf",rwResources,vmAttribute::emptyvMap,false,false,false,false);
		spawnnode = spawnDoc.GetJDFRoot();

		CPPUNIT_ASSERT( myDoc.Write2File(sm_dirTestTemp+"testMergeJDF2_spawned.jdf") );
		JDFMerge myMerge(root);
		JDFMerge(root).mergeJDF(spawnnode, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_None);

		JDFResource myres = (JDFResource)root.GetTarget("Res_Impos_Out_Run_1_3011", JDFNode::atr_ID);
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr,myres.GetAttribute("SpawnIDs", WString::emptyStr,WString::emptyStr) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFSpawnTest::testSpawnNI13()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		CPPUNIT_ASSERT( n.GetInheritedCustomerInfo().isNull() ); // null CID
		n.SetType("ProcessGroup");
        vWString v;
        v.add("Interpreting");
        v.add("Rendering");

        for(int i=0;i<2;i++)
        {
            JDFNode n2=n.AddCombined(v);
            JDFNodeInfo ni=n2.AppendNodeInfo();
            JDFSpawn spawn=JDFSpawn(n2);
			vmAttribute vSpawnParts;
            if(i==1)
            {
				ni.AddPartition(JDFResource::PartIDKey_Run, "r1");
                vSpawnParts=vmAttribute();
				vSpawnParts.push_back(mAttribute("Run","r1"));
            }
			JDFDoc spawnedDoc=spawn.spawn("thisFile","spawnFile",vWString::emptyvStr,vSpawnParts,true,true,true,true);
			JDFNode spawnedNode=spawnedDoc.GetJDFRoot();
            JDFNodeInfo niSpawn= spawnedNode.GetInheritedNodeInfo();
			CPPUNIT_ASSERT( !niSpawn.isNull() ); // ni
			CPPUNIT_ASSERT_EQUAL( 1,spawnedNode.GetResourcePool().NumChildElements(JDFNode::elm_NodeInfo) );
        }

	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}
