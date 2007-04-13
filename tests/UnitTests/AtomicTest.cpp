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
#include "jdf/wrapper/JDFGeneralID.h"
#include "jdf/wrapper/JDFMerge.h"
#include "jdf/wrapper/JDFSpawn.h"
#include "AtomicTest.h"
#include "time.h"
#include <iostream>

#include "jdf/io/FileSystem.h"
#include "jdf/io/File.h"

using namespace std;
using namespace JDF;

const WString sm_dirTestData = L"data/";
const WString sm_dirTestTemp = L"temp/";

CPPUNIT_TEST_SUITE_REGISTRATION (AtomicTest);

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


// StringUtilTest::testGetBytes()
//FileUtilTest::testExists()
void AtomicTest::testAtomic()
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
		WString spawnID=spawnedNode.GetSpawnID(false);

		JDFExposedMedia xmSpawn= xmRLspawn.GetTarget();
		CPPUNIT_ASSERT(!xmSpawn.isNull());
		CPPUNIT_ASSERT_EQUAL(spawnID, xmSpawn.GetAttribute("SpawnIDs"));
		JDFAttributeMap mapXMSpawn=xmSpawn.GetPartMap();
		JDFExposedMedia xmMain= n.GetMatchingResource("ExposedMedia", JDFNode::ProcessUsage_AnyOutput);
		xmMain=xmMain.GetPartition(mapXMSpawn, false);
		CPPUNIT_ASSERT(!xmMain.isNull());
		CPPUNIT_ASSERT_EQUAL(spawnID, xmMain.GetAttribute("SpawnIDs"));

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
