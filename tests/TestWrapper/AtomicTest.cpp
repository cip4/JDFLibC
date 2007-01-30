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
// created 24 Nov 2006
//
// AtomicTest.cpp: this is the place to drop the code you are working on, 
//                 without disturbing 'runAllTests'
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "AtomicTest.h"
#include "time.h"
#include <iostream>

#include "jdf/wrapper/JDFSpawn.h"
#include "jdf/wrapper/JDFMerge.h"

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (AtomicTest);

const WString sm_dirTestData = L"data\\";
const WString sm_dirTestTemp = L"temp\\";

void AtomicTest::setUp()
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




// KElementTest::testSetAttribute_LongAttValue()
void AtomicTest::testAtomic()
{
	try
	{
		JDFDoc d = JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFEnumerationState enumState = JDFEnumerationState();
		enumState = (JDFEnumerationState)n.AppendElement(JDFResource::elm_EnumerationState); 
		enumState.SetName("foo"); 
		enumState.SetHasDefault(true); 
		enumState.SetDefaultValue("bar");
		//enumState.GetDefaultValue();
		WString strN = n.ToString();
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

//// JDFSpawnTest::testSpawnPartMulti()
//void AtomicTest::testAtomic()
//{
//	try
//	{
//
//		JDFDoc dRoot=JDFDoc(0);
//        JDFNode nRoot=dRoot.GetJDFRoot();
//        JDFCustomerInfo ci=nRoot.AppendCustomerInfo();
//        ci.SetCustomerProjectID("foo");
//
//		nRoot.SetType("Product");
//
//        JDFDoc d=creatXMDoc();
//        JDFNode n=(JDFNode) nRoot.CopyElement(d.GetJDFRoot());
//		JDFExposedMedia xm=(JDFExposedMedia) n.GetMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput);
//		JDFNode nPS=nRoot.AddJDFNode(JDFNode::Type_ImageSetting);
//		nPS.linkResource(xm,JDFResourceLink::Usage_Output,JDFNode::ProcessUsage_Unknown);
//        vWString v;
//		v.add(JDFNode::elm_ExposedMedia);		
//        vmAttribute vMap;
//        JDFAttributeMap map;
//        map.put("SignatureName","Sig1");
//		vMap.push_back(map);
//		WString jobPartID = nPS.GetJobPartID();
//        JDFSpawn spawn=JDFSpawn(nPS);		
//		
//		JDFDoc spawnedPSDocInfo=spawn.spawnInformative(WString::emptyStr, WString::emptyStr, vMap, false, true, true, true);
//		JDFNode spawnedPSNodeInfo=spawnedPSDocInfo.GetJDFRoot().GetJobPart(jobPartID);
//		CPPUNIT_ASSERT_EQUAL( (WString)"foo",spawnedPSNodeInfo.GetInheritedCustomerInfo().GetCustomerProjectID() ); // cpi		
//        spawn=JDFSpawn(nPS);
//
//		JDFDoc spawnedPSDoc=spawn.spawn(WString::emptyStr,WString::emptyStr,v,vMap,false,true,true,true);
//		JDFNode spawnedPSNode=spawnedPSDoc.GetJDFRoot();
//		CPPUNIT_ASSERT_EQUAL( (WString)"foo",spawnedPSNode.GetInheritedCustomerInfo().GetCustomerProjectID() ); // cpi
//        // this one spawns the component rw
//		v.clear();
//		v.add(JDFNode::elm_Component);
//		WString jobPartIdN = n.GetJobPartID();
//        spawn=JDFSpawn(n);
//
//		JDFDoc spawnedDocAll=spawn.spawn("thisUrl","newURL",v,vmAttribute::emptyvMap,false,true,true,true); 
//		JDFNode spawnedNodeAll=spawnedDocAll.GetJDFRoot();
//        WString spawnID=spawnedNodeAll.GetSpawnID();
//        // merge and immediately respawn the same thing
//		JDFMerge merge=JDFMerge(n);
//		JDFDoc docMerge = merge.mergeJDF(spawnedNodeAll, WString::emptyStr, JDFNode::CleanUpMerge_RemoveAll, JDFResource::AmountMerge_UpdateLink);
//		n=docMerge.GetJDFRoot().GetJobPart(jobPartIdN);
//		CPPUNIT_ASSERT( nRoot.ToString().indexOf(spawnID)<0 ); // spawnID gone
//		jobPartID = n.GetJobPartID();
//		spawn=JDFSpawn(n);
//
//		JDFDoc spawnedDoc=spawn.spawn("thisUrl","newURL",v,vMap,false,true,true,true); 
//		JDFNode spawnedNode=spawnedDoc.GetJDFRoot().GetJobPart(jobPartID);
//        spawnID=spawnedNode.GetSpawnID(false);
//		CPPUNIT_ASSERT( spawnedNode.HasChildElement(JDFNode::elm_AncestorPool) ); // has AncestorPool
//
//        // merge and immediately respawn the same thing
//		jobPartIdN = n.GetJobPartID();
//		merge=JDFMerge(n);
//		docMerge=merge.mergeJDF(spawnedNode, WString::emptyStr, JDFNode::CleanUpMerge_RemoveAll, JDFResource::AmountMerge_UpdateLink);
//		n=docMerge.GetJDFRoot().GetJobPart(jobPartIdN);
//// fine up to here
//
//		CPPUNIT_ASSERT( nRoot.ToString().indexOf(spawnID)<0 ); // spawnID gone
//        spawn=JDFSpawn(n);
//WString nStr = n.ToString(); // TODO remove after debugging
//		jobPartIdN = n.GetJobPartID();
//		spawnedDoc=spawn.spawn("thisUrl","newURL",v,vMap,false,true,true,true);
//		spawnedNode=spawnedDoc.GetJDFRoot().GetJobPart(jobPartIdN);
//// SpawnedRO statt RW? 
//		CPPUNIT_ASSERT( spawnedNode.HasChildElement(JDFNode::elm_AncestorPool) ); // AncestorPool present after merge
//
//        map.put("SheetName","S1");
//        spawn=JDFSpawn(spawnedNode);
//		//WString jobPartIdSpawnedNode=spawnedNode.GetJobPartID();
//		JDFDoc respawnedDoc=spawn.spawn("reUrl","renewURL",v,vMap,false,true,true,true);
//		JDFNode respawnedNode=respawnedDoc.GetJDFRoot().GetJobPart(jobPartID);
//// ExposedMedia fehlt in respawnedNode
//
//		CPPUNIT_ASSERT( spawnedNode.HasChildElement(JDFNode::elm_AncestorPool) ); // AncestorPool present after respawn
//		xm=(JDFExposedMedia) respawnedNode.GetMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput);
//		JDFComponent comp=(JDFComponent) respawnedNode.GetMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
//        vWString vSpID=xm.GetSpawnIDs(false);
//// assertion
//		WString strNode = xm.ToString(); // TODO remove after debugging
//		CPPUNIT_ASSERT( !vSpID.empty() ); // spawnIDs present
//		xm=(JDFExposedMedia) xm.GetPartition(map);
//		CPPUNIT_ASSERT( xm.GetLocked() ); // xm rw
//		comp=(JDFComponent) comp.GetPartition(map);
//		CPPUNIT_ASSERT( !comp.GetLocked() ); // comp rw
//
//        map.put("SheetName","S2");
//        spawn=JDFSpawn(spawnedNode);
//		JDFDoc respawnedDoc2=spawn.spawn("reUrl","renewURL",v,vMap,false,true,true,true);
//		JDFNode respawnedNode2=respawnedDoc2.GetJDFRoot();
//		xm=(JDFExposedMedia) respawnedNode2.GetMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput);
//		comp=(JDFComponent) respawnedNode2.GetMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
//        vSpID=xm.GetSpawnIDs(false);
//		CPPUNIT_ASSERT( !vSpID.empty() ); // spawnIDs present
//		xm=(JDFExposedMedia) xm.GetPartition(map);       
//
//		CPPUNIT_ASSERT( xm.GetLocked() ); // xm rw
//		comp=(JDFComponent) comp.GetPartition(map);
//		CPPUNIT_ASSERT( !comp.GetLocked() ); // comp rw
//        WString spawnID1=spawnedNode.GetSpawnID(false);
//		JDFMerge merge2 = JDFMerge(spawnedNode);
//		JDFDoc testSpawnedDoc = merge2.mergeJDF(respawnedNode2, WString::emptyStr, JDFNode::CleanUpMerge_None, JDFResource::AmountMerge_UpdateLink);
//		JDFNode testSpawnedNode=testSpawnedDoc.GetJDFRoot();
//		CPPUNIT_ASSERT( spawnedNode.HasChildElement(JDFNode::elm_AncestorPool) ); // AncestorPool after respawn merge
//		CPPUNIT_ASSERT_EQUAL( spawnID1,testSpawnedNode.GetSpawnID() ); // SpawnID ok?
//        spawn=JDFSpawn(spawnedNode);
//		respawnedDoc2 = spawn.spawn("reUrl","renewURL",v,vMap,false,true,true,true);
//		respawnedNode2 = respawnedDoc.GetJDFRoot();
//
//        //// now go backwards!
//        //new JDFMerge(nRoot).mergeJDF(spawnedNode, null, EnumCleanUpMerge.None, EnumAmountMerge.UpdateLink);
//        //new JDFMerge(nRoot).mergeJDF(respawnedNode, null, EnumCleanUpMerge.None, EnumAmountMerge.UpdateLink);
//        //new JDFMerge(nRoot).mergeJDF(respawnedNode2, null, EnumCleanUpMerge.None, EnumAmountMerge.UpdateLink);
//
//
//        //new JDFMerge(nRoot).mergeJDF(spawnedPSNode, null, EnumCleanUpMerge.None, EnumAmountMerge.UpdateLink);
//        //assertTrue("spawnIDs gone",nRoot.toString().indexOf("SpawnIDs")<0);
//	}
//	catch (JDFException& e)
//	{
//		CPPUNIT_FAIL( e.what() );
//	}
//}
