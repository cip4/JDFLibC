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
// created 16 Aug 2006
//
// JDFNodeTest.cpp: implements CppUnit tests for JDFNode
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "jdf/wrapper/JDFSpawn.h"
#include "jdf/wrapper/JDFMerge.h"
#include "JDFNodeTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFNodeTest);

const WString sm_dirTestData = L"data/";
const WString sm_dirTestTemp = L"temp/";

void JDFNodeTest::setUp()
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
	try
	{
		WString strSpawnID = WString::emptyStr;

		// parse input file
		JDFParser p;
		p.Parse(sm_dirTestData+strXMLFile, false);
		JDFDoc jdfDocIn = p.GetDocument();
		CPPUNIT_ASSERT( !jdfDocIn.isNull() );

		// prepare the spawn process
		JDFNode rootIn = (JDFNode) jdfDocIn.GetRoot();

		JDFNode spawnNode = JDFNode();
		if (strElementID.equals(WString::emptyStr))
		{
			spawnNode = rootIn;
		}
		else
		{
			spawnNode = (JDFNode) rootIn.GetTarget(strElementID, JDFElement::atr_ID);
		}
		CPPUNIT_ASSERT( !spawnNode.isNull() );

		JDFNode jdfSpawned = spawnNode.SpawnInformative(sm_dirTestData+strXMLFile, WString::emptyStr, vmAttribute::emptyvMap,false, true, true, true).GetJDFRoot();
		WString spawnID=jdfSpawned.GetSpawnID();

		WString big;
		jdfDocIn.Write2String(big);
		CPPUNIT_ASSERT( big.indexOf(spawnID)<0 );

		jdfSpawned = spawnNode.Spawn(
			sm_dirTestData+strXMLFile, WString::emptyStr, vRWResources, vSpawnParts,false, true, true, true).GetJDFRoot();
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

		// Vergleich, ob alles richtig gelaufen ist
		//        compareXMLFiles (strXMLFileModified,    strXMLFileModifiedMaster);
		//        compareXMLFiles (strSpawnedFile+".jdf", strSpawnedFileMaster);

		strSpawnID = rootOut.GetSpawnID();

		return strSpawnID;
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testSetType()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		CPPUNIT_ASSERT_EQUAL( JDFNode::TypeString(JDFNode::Type_ConventionalPrinting),n.GetType() );

		n.SetType("foo:bar");
		CPPUNIT_ASSERT_EQUAL( WString("foo:bar"),n.GetType() );
		CPPUNIT_ASSERT( n.GetAttribute("type",JDFElement::atr_xsiURI, WString::emptyStr).empty() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testLinkResourceNS()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		JDFResource rl= n.addResource("NS:RunList", JDFResource::Class_Parameter, JDFResourceLink::Usage_Unknown, WString::emptyStr, JDFNode::DefJDFNode, "www.ns.com", JDFResource::DefJDFResource);
		CPPUNIT_ASSERT_EQUAL( WString("www.ns.com"),rl.GetNamespaceURI() );
		JDFResourceLink rll=n.LinkResource(rl,true,false);
		CPPUNIT_ASSERT_EQUAL( WString("www.ns.com"),rl.GetNamespaceURI() );
		CPPUNIT_ASSERT( !rll.HasAttribute(JDFStrings::atr_CombinedProcessIndex) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testInsertTypeInTypes()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_Combined));
		n.insertTypeInTypes(JDFNode::Type_Combine,999);
		CPPUNIT_ASSERT_EQUAL( WString("Combine"),n.GetAttribute("Types") );
		n.insertTypeInTypes(JDFNode::Type_Imposition,999);
		CPPUNIT_ASSERT_EQUAL( WString("Combine Imposition"),n.GetAttribute("Types") );
		n.insertTypeInTypes(JDFNode::Type_Stripping,1);
		CPPUNIT_ASSERT_EQUAL( WString("Combine Stripping Imposition"),n.GetAttribute("Types") );
		n.insertTypeInTypes(JDFNode::Type_DigitalDelivery,0);
		CPPUNIT_ASSERT_EQUAL( WString("DigitalDelivery Combine Stripping Imposition"),n.GetAttribute("Types") );
		n.insertTypeInTypes(JDFNode::Type_Imposition,99999);
		CPPUNIT_ASSERT_EQUAL( WString("DigitalDelivery Combine Stripping Imposition Imposition"),n.GetAttribute("Types") );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testLinkNamesCombined()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.setCombined(vWString("Interpreting Trapping Rendering",WString::whiteSpace));
		vWString e=n.LinkNames();
		bool isFound=false;
		for (int i=0;i<e.size();i++)
		{
			if (e[i].find(JDFStrings::elm_CustomerInfo) >= 0)
				isFound = true;
		}
		CPPUNIT_ASSERT_MESSAGE( "e does not contain 'CustomerInfo'", isFound );
		isFound = false;
		for (int i=0;i<e.size();i++)
		{
			if (e[i].find(JDFStrings::elm_RenderingParams) >= 0)
				isFound = true;
		}
		CPPUNIT_ASSERT_MESSAGE( "e does not contain 'RenderingParams'", isFound );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testLinkNamesProduct()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_Product));
		vWString e=n.LinkNames();
		bool isFound=false;
		for (int i=0;i<e.size();i++)
		{
			if (e[i].find(JDFStrings::elm_CustomerInfo) >= 0)
				isFound = true;
		}
		CPPUNIT_ASSERT_MESSAGE( "e does not contain 'CustomerInfo'", isFound );
		isFound = false;
		for (int i=0;i<e.size();i++)
		{
			if (e[i].find(JDFStrings::elm_MediaIntent) >= 0)
				isFound = true;
		}
		CPPUNIT_ASSERT_MESSAGE( "e does not contain 'MediaIntent'", isFound );
		isFound = false;
		for (int i=0;i<e.size();i++)
		{
			if (e[i].find(JDFStrings::elm_Component) >= 0)
				isFound = true;
		}
		CPPUNIT_ASSERT_MESSAGE( "e does not contain 'Component'", isFound );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testLinkResourceSimple()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::Type_Folding);
		JDFResource foPa= n.addResource(JDFStrings::elm_FoldingParams, JDFResource::Class_Unknown, JDFResourceLink::Usage_Input, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		JDFResourceLink rlfoPa=n.getLink(foPa,JDFResourceLink::Usage_Unknown);
		CPPUNIT_ASSERT( !rlfoPa.HasAttribute(JDFStrings::atr_CombinedProcessIndex) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testLinkResourceCombined()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_Combined));
		vWString v=vWString("Folding Cutting Foo:Bar Folding",WString::whiteSpace);
		n.SetTypes(v);
		JDFResource foPa= n.addResource(JDFElement::elm_FoldingParams, JDFResource::Class_Parameter, JDFResourceLink::Usage_Input, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		JDFResourceLink rlfoPa=n.GetLink(foPa);	
		CPPUNIT_ASSERT_EQUAL( WString("0 3"),rlfoPa.GetCombinedProcessIndex().GetString() );
		rlfoPa=n.getLink(foPa,JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT_EQUAL( WString("0 3"),rlfoPa.GetCombinedProcessIndex().GetString() );
		JDFResource cuPa= n.addResource(JDFStrings::elm_CuttingParams, JDFResource::Class_Parameter, JDFResourceLink::Usage_Unknown, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		JDFResourceLink rlCuPa=n.LinkResource(cuPa,true);
		CPPUNIT_ASSERT_EQUAL( WString("1"),rlCuPa.GetCombinedProcessIndex().GetString() );

		JDFResource pePa= n.addResource(JDFStrings::elm_PerforatingParams, JDFResource::Class_Parameter, JDFResourceLink::Usage_Unknown, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		JDFResourceLink rlPePa=n.LinkResource(pePa,true);
		CPPUNIT_ASSERT( rlPePa.GetCombinedProcessIndex().empty() );

		n.insertTypeInTypes(JDFNode::Type_AdhesiveBinding,999);
		CPPUNIT_ASSERT_EQUAL( WString("0 3"),rlfoPa.GetCombinedProcessIndex().GetString() );
		CPPUNIT_ASSERT_EQUAL( WString("1"),rlCuPa.GetCombinedProcessIndex().GetString() );
		v=n.GetTypes();
		CPPUNIT_ASSERT_EQUAL( JDFNode::TypeString(JDFNode::Type_AdhesiveBinding),v.elementAt(4) );
		CPPUNIT_ASSERT_EQUAL( 5,(int)v.size() );

		n.insertTypeInTypes(JDFNode::Type_Bundling,-2);
		CPPUNIT_ASSERT_EQUAL( WString("0 4"),rlfoPa.GetCombinedProcessIndex().GetString() );
		CPPUNIT_ASSERT_EQUAL( WString("1"),rlCuPa.GetCombinedProcessIndex().GetString() );
		v=n.GetTypes();
		CPPUNIT_ASSERT_EQUAL( JDFNode::TypeString(JDFNode::Type_Bundling),v.elementAt(3) );
		CPPUNIT_ASSERT_EQUAL( 6,(int)v.size() );

		n.insertTypeInTypes(JDFNode::Type_BoxPacking,0);
		CPPUNIT_ASSERT_EQUAL( WString("1 5"),rlfoPa.GetCombinedProcessIndex().GetString() );
		CPPUNIT_ASSERT_EQUAL( WString("2"),rlCuPa.GetCombinedProcessIndex().GetString() );
		v=n.GetTypes();
		CPPUNIT_ASSERT_EQUAL( JDFNode::TypeString(JDFNode::Type_BoxPacking),v.elementAt(0) );
		CPPUNIT_ASSERT_EQUAL( JDFNode::TypeString(JDFNode::Type_Folding),v.elementAt(1) );
		CPPUNIT_ASSERT_EQUAL( 7,(int)v.size() );

		JDFResource comp=n.addResource(JDFStrings::elm_Component, JDFResource::Class_Quantity, JDFResourceLink::Usage_Unknown);
		JDFResourceLink rlcomp=n.linkResource(comp,JDFResourceLink::Usage_Output,JDFNode::ProcessUsage_Unknown);//LinkResource(comp,false);
		CPPUNIT_ASSERT_EQUAL( JDFIntegerList("2 6").GetString(),rlcomp.GetCombinedProcessIndex().GetString() );
		
		JDFResource compIn= n.addResource(JDFStrings::elm_Component, JDFResource::Class_Unknown, JDFResourceLink::Usage_Unknown, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		JDFResourceLink rlcompIn=n.LinkResource(compIn,true);
		CPPUNIT_ASSERT_EQUAL( JDFIntegerList("0 4").GetString(),rlcompIn.GetCombinedProcessIndex().GetString() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testAddResource()
{
	try
	{
		JDFDoc doc(0);
		JDFNode mainNode = doc.GetJDFRoot();
		mainNode.SetType("Product");
		JDFComponent myComponent = (JDFComponent)mainNode.addResource(JDFStrings::elm_Component, JDFResource::Class_Quantity, JDFResourceLink::Usage_Output, WString::emptyStr, mainNode, WString::emptyStr, JDFResource::DefJDFResource);
		myComponent.SetDescriptiveName("descriptive_name");
		CPPUNIT_ASSERT( !mainNode.GetMatchingResource(JDFStrings::elm_Component, JDFNode::ProcessUsage_AnyOutput, mAttribute::emptyMap, 0).isNull() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testAddInternalPipe()
{
	try
	{
		JDFDoc doc(0);
		JDFNode mainNode = doc.GetJDFRoot();
		mainNode.SetType("Combined");
		mainNode.SetTypes(vWString("Cutting Folding Folding Inserting",WString::whiteSpace));
		JDFComponent myComponent = (JDFComponent) mainNode.AddInternalPipe(JDFStrings::elm_Component,3,0);
		CPPUNIT_ASSERT( !myComponent.isNull() );
		CPPUNIT_ASSERT_EQUAL( WString("Internal"),myComponent.GetPipeProtocol() );
		vElement vE=myComponent.GetLinks(myComponent.GetLinkString(),WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( 2,(int)vE.size() );
		CPPUNIT_ASSERT_EQUAL( WString("Internal"),((JDFResourceLink)vE.elementAt(0)).GetPipeProtocol() );
		CPPUNIT_ASSERT_EQUAL( WString("Internal"),((JDFResourceLink)vE.elementAt(1)).GetPipeProtocol() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testCloneResourceToModify()
{
	try
	{
		JDFDoc d=creatXMDoc();
		JDFNode n=d.GetJDFRoot();
		JDFResourceLink rl = n.GetMatchingLink(JDFStrings::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput,0);
		JDFAttributeMap m("SignatureName","Sig1");
		rl.SetPartMap(m);
		rl.SetAmount(42.0,m);
		JDFResourceAudit ra=n.CloneResourceToModify(rl); 
		ra.GetNewLink().HasChildElement("Part",WString::emptyStr);
		CPPUNIT_ASSERT( ra.GetNewLink().HasChildElement("Part",WString::emptyStr) );
		CPPUNIT_ASSERT( ra.GetOldLink().HasChildElement("Part",WString::emptyStr) );
		CPPUNIT_ASSERT( ra.GetNewLink().HasChildElement("AmountPool",WString::emptyStr) );
		CPPUNIT_ASSERT( ra.GetOldLink().HasChildElement("AmountPool",WString::emptyStr) );
	}
	catch (const JDF::Exception& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testEraseEmptyAttributes()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		JDFResource r = n.addResource("foo", JDFResource::Class_Unknown, JDFResourceLink::Usage_Unknown);
		r.AppendAttribute("bar", WString::emptyStr);
		n.eraseEmptyAttributes(true);
		CPPUNIT_ASSERT( !n.HasAttribute("bar") );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testEraseEmptyNodes()
{
	try
	{
		// TO DO JDFNode::EraseEmptyNodes() --> known bug
		//JDFDoc d(0);
		//JDFNode n=d.GetJDFRoot();		
		//JDFResource r = n.addResource("foo", JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);
		//n.RemoveResource("foo", 0);
		//n.AppendElementN("snarf", 1);
		//n.EraseEmptyNodes();		
		//CPPUNIT_ASSERT( n.GetResourcePool().isNull() );	
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testResourceAudit()
{
	try
	{
		JDFDoc gd(0);
		JDFNode n=gd.GetJDFRoot();

		JDFRunList rl=(JDFRunList)n.addResource("RunList",JDFResource::Class_Unknown,JDFResourceLink::Usage_Input,WString::emptyStr,JDFNode::DefJDFNode,WString::emptyStr,JDFResource::DefJDFResource);
		n.SetType("Product");
		n.SetStatus(JDFElement::Status_Waiting);
		JDFResourceLink rli=n.getLink(rl,JDFResourceLink::Usage_Input);
		JDFResourceAudit ra=n.CloneResourceToModify(rli);
		// messy comment insertion to test getNewOldLink with Comments
		ra.InsertBefore(JDFStrings::elm_Comment,ra.GetOldLink(),WString::emptyStr);
		ra.AppendComment();
		CPPUNIT_ASSERT_EQUAL( (KElement)ra.GetComment(0),(KElement)ra.GetNewLink().GetNextSiblingElement() );
		CPPUNIT_ASSERT_EQUAL( (KElement)ra.GetOldLink(), (KElement)ra.GetComment(0).GetNextSiblingElement() );
		CPPUNIT_ASSERT_EQUAL( (KElement)ra.GetOldLink().GetNextSiblingElement(),(KElement)ra.GetComment(1) );

		CPPUNIT_ASSERT_EQUAL( 2,ra.NumChildElements("RunListLink",WString::emptyStr) );
		CPPUNIT_ASSERT_EQUAL( 2,n.GetResourcePool().NumChildElements("RunList",WString::emptyStr) );
		CPPUNIT_ASSERT_EQUAL( 1,n.GetResourceLinkPool().NumChildElements("RunListLink",WString::emptyStr) );
		CPPUNIT_ASSERT_EQUAL( ra.GetNewLink().GetrRef(),n.GetResourceLinkPool().GetElement("RunListLink",WString::emptyStr,0).GetAttribute(JDFElement::atr_rRef) );
		CPPUNIT_ASSERT_EQUAL( ra.GetOldLink().GetrRef(),(ra.GetNewLink().GetrRef()+"_old_001") );
		CPPUNIT_ASSERT( (ra.GetOldLink().GetTarget()).GetLocked() ); // old lock
		JDFResourceAudit ra2=n.GetAuditPool().AddResourceAudit("foo");
		ra2.addNewOldLink(true,rl,JDFResourceLink::Usage_Input);
		ra2.AppendComment();
		ra2.addNewOldLink(false,rl,JDFResourceLink::Usage_Input).SetDescriptiveName("foo");
		CPPUNIT_ASSERT_EQUAL( WString("foo"),ra2.GetOldLink().GetDescriptiveName() );
		
		CPPUNIT_ASSERT( ra2.IsValid(KElement::ValidationLevel_Complete) );
		ra2.CopyElement(rl,JDFElement::DefKElement);
		CPPUNIT_ASSERT( !ra2.IsValid(KElement::ValidationLevel_Complete) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testSetPartStatusNull()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		root.SetPartStatus((JDFAttributeMap)mAttribute::emptyMap, JDFNode::Status_Waiting);
		JDFNodeInfo ni=root.GetNodeInfo();
		CPPUNIT_ASSERT( ni.isNull() );
		CPPUNIT_ASSERT( root.GetStatusPool().isNull() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Waiting,root.GetStatus() );

		root.SetVersion(JDFElement::VersionString(JDFElement::Version_1_2));
		root.SetPartStatus((JDFAttributeMap)mAttribute::emptyMap, JDFNode::Status_Completed);
		ni=root.GetNodeInfo();
		CPPUNIT_ASSERT( ni.isNull() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Completed,root.GetStatus() );
		CPPUNIT_ASSERT( root.GetStatusPool().isNull() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testSetPartStatusNotNull()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		mAttribute pm(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"s1");
		root.SetPartStatus(pm, JDFNode::Status_Waiting);
		JDFNodeInfo ni=(JDFNodeInfo) root.GetNodeInfo().GetPartition(pm, JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT( !ni.isNull() );
		CPPUNIT_ASSERT( root.GetStatusPool().isNull() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Part,root.GetStatus() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Waiting,root.GetNodeInfo().GetNodeStatus() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Waiting,ni.GetNodeStatus() );

		root.SetVersion(JDFElement::VersionString(JDFElement::Version_1_2));
		root.SetPartStatus(pm, JDFNode::Status_Completed);
		ni=root.GetNodeInfo();
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Pool,root.GetStatus() );
		CPPUNIT_ASSERT( !root.GetStatusPool().isNull() );
		CPPUNIT_ASSERT( !root.GetStatusPool().GetPartStatus(pm).isNull() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Completed,root.GetStatusPool().GetPartStatus(pm).GetStatus() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testSetPhase()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		root.SetJobID("jID");
		root.SetJobPartID("jpID");
		JDFNodeInfo nodeInfo = root.GetCreateNodeInfo();
		nodeInfo.SetAgentName("myAgent");
		JDFDoc docJMF=root.setPhase(JDFNode::Status_Waiting,"Queued","MyDevice",JDFDeviceInfo::DeviceStatus_Idle,WString::emptyStr,vmAttribute::emptyvMap);
		JDFJMF jmf = docJMF.GetJMFRoot();
		CPPUNIT_ASSERT( !jmf.isNull() );
		CPPUNIT_ASSERT_EQUAL( 1,jmf.NumChildElements(JDFStrings::elm_Signal,WString::emptyStr) );
		JDFAuditPool ap=root.GetAuditPool();
		JDFPhaseTime pt=(JDFPhaseTime) ap.GetAudit(0,JDFAudit::AuditType_PhaseTime,mAttribute::emptyMap);
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Waiting,pt.GetStatus() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Waiting,root.GetPartStatus(mAttribute::emptyMap) );
		mAttribute map("SheetName","S1");
		vmAttribute vMap;
		vMap.AppendUnique(map);
		docJMF.Write2File(sm_dirTestTemp+"queued.jmf");

		docJMF=root.setPhase(JDFNode::Status_Setup,"Setup","MyDevice",JDFDeviceInfo::DeviceStatus_Setup,WString::emptyStr,vMap);
		pt=(JDFPhaseTime) ap.GetAudit(-1,JDFAudit::AuditType_PhaseTime,mAttribute::emptyMap);
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Setup,pt.GetStatus() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_Setup,root.GetPartStatus(map) );
		CPPUNIT_ASSERT_EQUAL( vMap,pt.GetPartMapVector() );
		jmf = docJMF.GetJMFRoot();
		CPPUNIT_ASSERT (!jmf.isNull() );
		CPPUNIT_ASSERT_EQUAL( 2,jmf.NumChildElements(JDFStrings::elm_Signal,WString::emptyStr) );
		docJMF.Write2File(sm_dirTestTemp+"setup.jmf");        

		docJMF=root.setPhase(JDFNode::Status_InProgress,"Run","MyDevice",JDFDeviceInfo::DeviceStatus_Running,WString::emptyStr,vMap);
		pt=(JDFPhaseTime) ap.GetAudit(-1,JDFAudit::AuditType_PhaseTime,mAttribute::emptyMap);
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_InProgress,pt.GetStatus() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_InProgress,root.GetPartStatus(map) );
		CPPUNIT_ASSERT_EQUAL( vMap,pt.GetPartMapVector() );
		jmf = docJMF.GetJMFRoot();
		CPPUNIT_ASSERT( !jmf.isNull() );
		CPPUNIT_ASSERT_EQUAL( 2,jmf.NumChildElements(JDFStrings::elm_Signal,WString::emptyStr) );
		docJMF.Write2File(sm_dirTestTemp+"inprogress.jmf");

		docJMF=root.setPhase(JDFNode::Status_InProgress,"Run","MyDevice",JDFDeviceInfo::DeviceStatus_Running,WString::emptyStr,vMap);
		pt=(JDFPhaseTime) ap.GetAudit(-1,JDFAudit::AuditType_PhaseTime,mAttribute::emptyMap);
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_InProgress,pt.GetStatus() );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Status_InProgress,root.GetPartStatus(map) );
		CPPUNIT_ASSERT_EQUAL( vMap,pt.GetPartMapVector() );
		jmf = docJMF.GetJMFRoot();
		CPPUNIT_ASSERT( !jmf.isNull() );
		CPPUNIT_ASSERT_EQUAL( 1,jmf.NumChildElements(JDFStrings::elm_Signal,WString::emptyStr) );
		docJMF.Write2File(sm_dirTestTemp+"inprogress2.jmf");
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testInit()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode node = doc.GetJDFRoot();
		CPPUNIT_ASSERT( node.GetStatus() != JDFNode::Status_Unknown );
		CPPUNIT_ASSERT( !node.GetID().empty() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testIsValid()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode node = doc.GetJDFRoot();
		node.SetType(JDFNode::TypeString(JDFNode::Type_ProcessGroup));
		CPPUNIT_ASSERT( node.IsValid(JDFNode::ValidationLevel_Complete) );
		node.RemoveAttribute(JDFElement::atr_JobPartID);
		CPPUNIT_ASSERT( node.IsValid(JDFNode::ValidationLevel_Complete) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testIsExecutable()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode node = doc.GetJDFRoot();
		node.SetType("ConventionalPrinting");
		node.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		node.SetStatus(JDFElement::Status_Ready);

		// simple non-partitioned case
		JDFNodeInfo n=node.AppendNodeInfo();
		CPPUNIT_ASSERT( n.HasAttribute(JDFElement::atr_Class) );
		JDFConventionalPrintingParams convPrintParams=(JDFConventionalPrintingParams) node.AppendMatchingResource(JDFElement::elm_ConventionalPrintingParams,JDFNode::ProcessUsage_AnyInput);
		convPrintParams.SetStatus(JDFResource::Status_Available,true);
		JDFComponent outComp= (JDFComponent) node.AppendMatchingResource(JDFElement::elm_Component,JDFNode::ProcessUsage_AnyOutput);
		outComp.SetStatus(JDFResource::Status_Unavailable,true);
		JDFExposedMedia xm= (JDFExposedMedia) node.AppendMatchingResource(JDFElement::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput);
		xm.SetStatus(JDFResource::Status_Unavailable,true);
		JDFMedia media= (JDFMedia) node.AppendMatchingResource(JDFElement::elm_Media,JDFNode::ProcessUsage_AnyInput);
		media.SetStatus(JDFResource::Status_Available,true);
		bool exec=node.IsExecutable(mAttribute::emptyMap,false);
		CPPUNIT_ASSERT( !exec );
		xm.SetStatus(JDFResource::Status_Available,true);
		exec=node.IsExecutable(mAttribute::emptyMap,false);
		CPPUNIT_ASSERT( exec );
		node.SetStatus(JDFElement::Status_Completed);
		exec=node.IsExecutable(mAttribute::emptyMap,false);
		CPPUNIT_ASSERT( !exec );

		// now a partition
		convPrintParams.SetPartUsage(JDFResource::PartUsage_Implicit);
		media.SetPartUsage(JDFResource::PartUsage_Implicit);
		xm=(JDFExposedMedia) xm.AddPartition(JDFResource::PartIDKey_SignatureName,"sig1");
		xm.SetStatus(JDFResource::Status_Unavailable,true);
		exec=node.IsExecutable(mAttribute::emptyMap,false);
		CPPUNIT_ASSERT( !exec );
		xm.SetStatus(JDFResource::Status_Available,true);
		exec=node.IsExecutable(mAttribute::emptyMap,false);
		CPPUNIT_ASSERT( !exec );
		JDFAttributeMap partMap = JDFAttributeMap("SignatureName","sig1");
		node.SetPartStatus(partMap,JDFElement::Status_Waiting);

		outComp.AddPartition(JDFResource::PartIDKey_SignatureName,"sig1");
		exec=node.IsExecutable(partMap,false);
		CPPUNIT_ASSERT( exec );


		// the root is set to completed --> must fail
		exec=node.IsExecutable(mAttribute::emptyMap,false);
		CPPUNIT_ASSERT( !exec );

		// now try a non existing partition - should fail
		partMap.put("SignatureName","sig2");
		exec=node.IsExecutable(partMap,false);

		CPPUNIT_ASSERT( !exec );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetInheritedNodeInfo()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode node = doc.GetJDFRoot();
		JDFNodeInfo n = node.AppendNodeInfo();
		try
		{
			node.AppendNodeInfo();
			CPPUNIT_FAIL( "one NodeInfo is enough" );
		}
		catch (JDFException&)
		{
			// nop
		}
		node.SetType("ProcessGroup");
		JDFNode node2=node.AddProcessGroup();
		JDFNode node3=node2.AddJDFNode(JDFNode::Type_CaseMaking);
		JDFAncestor an=node.AppendAncestorPool().AppendAncestor();
		JDFCustomerInfo ciAN=an.AppendCustomerInfo();
		JDFNodeInfo niAN=an.AppendNodeInfo();
		JDFJMF jmf=niAN.AppendJMF();
		VString vs;
		vs.add("ICS_Foo");
		jmf.SetICSVersions(vs);

		CPPUNIT_ASSERT( node2.GetNodeInfo().isNull() );
		CPPUNIT_ASSERT_EQUAL( n.ToString(),node.GetInheritedNodeInfo().ToString() );
		CPPUNIT_ASSERT_EQUAL( n.ToString(),node2.GetInheritedNodeInfo().ToString() );
		CPPUNIT_ASSERT_EQUAL( n.ToString(),node3.GetInheritedNodeInfo().ToString() );
		CPPUNIT_ASSERT_EQUAL( ciAN.ToString(),node3.GetInheritedCustomerInfo().ToString() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetCreateNodeInfo()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		JDFNodeInfo nodeInfo = root.GetCreateNodeInfo();
		JDFNodeInfo nodeInfo2 = root.GetCreateNodeInfo();
		CPPUNIT_ASSERT_EQUAL( nodeInfo,nodeInfo2 );

		root.SetType(JDFNode::TypeString(JDFNode::Type_Product));

		JDFNode nodeVer3 = root.AddJDFNode(JDFNode::Type_ProcessGroup);
		JDFNode nodeVer1 = root.AddJDFNode(JDFNode::Type_ProcessGroup);

		nodeVer3.SetVersion(JDFElement::VersionString(JDFNode::Version_1_3));
		nodeVer1.SetVersion(JDFElement::VersionString(JDFNode::Version_1_1));

		root.SetVersion(JDFElement::VersionString(JDFNode::Version_1_3)); 
		//append some NodeInfos

		//try to append the other NodeInfo (only 1 is valid)
		nodeVer1.AppendNodeInfo();
		nodeVer3.AppendNodeInfo();
		JDFNode subNodeVer1=nodeVer1.AddJDFNode(JDFNode::Type_Folding);
		JDFNode subNodeVer3=nodeVer3.AddJDFNode(JDFNode::Type_Folding);

		try
		{
			nodeVer1.AppendNodeInfo();
			CPPUNIT_FAIL( "nodeinfo has a cardinality of 1 in v1.1" );
		}
		catch(JDFException&)
		{
			// fine, expected to throw exeption
		}

		try
		{
			nodeVer3.AppendNodeInfo();
			CPPUNIT_FAIL( "nodeinfo has a cardinality of 1 in v1.1" );
		}
		catch(const JDF::JDFException&)
		{
			// fine, expected to throw exeption
		}

		try
		{
			nodeVer3.AppendNodeInfo();
			CPPUNIT_FAIL( "nodeinfo has a cardinality of 1 in v1.1" );
		}
		catch(const JDF::JDFException&)
		{
			// fine, expected to throw exeption
		}

		CPPUNIT_ASSERT( !nodeVer1.GetNodeInfo().isNull() );
		CPPUNIT_ASSERT( !nodeVer3.GetNodeInfo().isNull() );

		CPPUNIT_ASSERT( subNodeVer1.GetNodeInfo().isNull() );
		CPPUNIT_ASSERT( subNodeVer3.GetNodeInfo().isNull() );

		CPPUNIT_ASSERT( !subNodeVer1.GetInheritedNodeInfo().isNull() );
		CPPUNIT_ASSERT( !subNodeVer3.GetInheritedNodeInfo().isNull() );

		//remove them all
		nodeVer3.RemoveNodeInfos();
		CPPUNIT_ASSERT( nodeVer3.GetNodeInfo().isNull() );
		nodeVer1.RemoveNodeInfos();
		CPPUNIT_ASSERT( nodeVer1.GetNodeInfo().isNull() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testCreateNodeInfo()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
        JDFNode node = doc.GetJDFRoot();
        JDFNodeInfo n = node.AppendNodeInfo();
        try
        {
            node.AppendNodeInfo();
			CPPUNIT_FAIL( "one NodeInfo is enough" );
        }
        catch (JDFException&)
        {
            // nop
        }
		CPPUNIT_ASSERT_EQUAL( (WString)"Parameter",n.GetAttribute(JDFNode::atr_Class) );
        JDFCustomerInfo myCustInfo = node.GetCreateCustomerInfo(); 
        JDFContact myContact =myCustInfo.AppendContact();
		CPPUNIT_ASSERT_EQUAL( (WString)"Parameter",myContact.GetAttribute(JDFNode::atr_Class) );
		CPPUNIT_ASSERT(	!node.GetNodeInfo().isNull() );
        node.RemoveNodeInfos();
		CPPUNIT_ASSERT(	node.GetNodeInfo().isNull() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetvJDFNode()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_ProcessGroup));
		JDFNode n1=n.AddProcessGroup(vWString::emptyvStr);
		JDFNode n2=n.AddProcessGroup(vWString::emptyvStr);
		JDFNode n11=n1.AddProcessGroup(vWString::emptyvStr);
		CPPUNIT_ASSERT_EQUAL( 2,(int)n.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,true).size() );
		CPPUNIT_ASSERT_EQUAL( 1,(int)n1.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,true).size() );
		CPPUNIT_ASSERT_EQUAL( 1,(int)n2.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,false).size() );
		CPPUNIT_ASSERT_EQUAL( 2,(int)n1.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,false).size() );
		CPPUNIT_ASSERT_EQUAL( n1.ToString(),n.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,true).elementAt(0).ToString() );
		CPPUNIT_ASSERT_EQUAL( n.ToString(),n.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,false).elementAt(3).ToString() );
		CPPUNIT_ASSERT_EQUAL( n11.ToString(),n1.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,true).elementAt(0).ToString() );
		CPPUNIT_ASSERT_EQUAL( n1.ToString(),n1.GetvJDFNode(WString::emptyStr,JDFNode::Activation_Unknown,false).elementAt(1).ToString() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetPartStatus()
{
	try
	{
		JDFDoc doc=creatXMDoc();
        JDFNode node = doc.GetJDFRoot();
		JDFNodeInfo ni=node.GetNodeInfo();
		CPPUNIT_ASSERT_EQUAL( (WString)"Parameter",ni.GetAttribute(JDFNode::atr_Class) );
		node.SetPartStatus(mAttribute::emptyMap,JDFElement::Status_Waiting);
		CPPUNIT_ASSERT_EQUAL( JDFElement::Status_Waiting,node.GetPartStatus(mAttribute::emptyMap) );
        JDFAttributeMap m=JDFAttributeMap("SignatureName","Sig1");
		node.SetPartStatus(m,JDFElement::Status_Completed);
		CPPUNIT_ASSERT_EQUAL( JDFElement::Status_Completed,node.GetPartStatus(m) );
		CPPUNIT_ASSERT_EQUAL( JDFElement::Status_Unknown,node.GetPartStatus(mAttribute::emptyMap) );
        JDFAttributeMap m3=JDFAttributeMap("SignatureName","Sig2");
		CPPUNIT_ASSERT_EQUAL( JDFElement::Status_Waiting,node.GetPartStatus(m3) );

        m.put("SheetName","S1");
        m.put("Side","Front");  
		node.SetPartStatus(m,JDFElement::Status_Waiting);
		CPPUNIT_ASSERT_EQUAL( JDFElement::Status_Waiting,node.GetPartStatus(m) );

        JDFAttributeMap m2=JDFAttributeMap("SignatureName","Sig1");
		CPPUNIT_ASSERT_EQUAL( JDFElement::Status_Unknown,node.GetPartStatus(m2) );

        JDFAttributeMap m4=JDFAttributeMap("SignatureName","Sig3");
        m4.put("SheetName","S1");
        vmAttribute v;
        v.AppendUnique(m4);
        node.PrepareNodeInfo(v);
		CPPUNIT_ASSERT_EQUAL( JDFElement::Status_Waiting,node.GetPartStatus(m4) );
		CPPUNIT_ASSERT( !ni.GetPartition(m4,JDFResource::PartUsage_Explicit).isNull() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGenericResources()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("ConventionalPrinting");
		JDFDevice dev=(JDFDevice)n.AppendMatchingResource(JDFNode::elm_Device,JDFNode::ProcessUsage_AnyInput);
		dev.SetDeviceID("mydev");
		CPPUNIT_ASSERT( dev.IsValid() );
		JDFModule m=dev.AppendModule();
		m.SetID("Foo");
		JDFEmployee emp=(JDFEmployee) n.AppendMatchingResource(JDFNode::elm_Employee,JDFNode::ProcessUsage_AnyInput);
		emp.SetPersonalID("emp1");
		CPPUNIT_ASSERT( m.IsValid() );
		n.AppendMatchingResource(JDFNode::elm_ConventionalPrintingParams,JDFNode::ProcessUsage_AnyInput);
		n.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
		n.AppendMatchingResource(JDFNode::elm_ExposedMedia,JDFNode::ProcessUsage_Plate);

		CPPUNIT_ASSERT( n.IsValid(KElement::ValidationLevel_Incomplete) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testProductValidation()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("Product");
		JDFDevice dev=(JDFDevice)n.AppendMatchingResource(JDFNode::elm_Device,JDFNode::ProcessUsage_AnyInput);
		dev.SetDeviceID("mydev");
		CPPUNIT_ASSERT( dev.IsValid() );
		JDFModule m=dev.AppendModule();
		m.SetID("Foo");
		JDFEmployee emp=(JDFEmployee) n.AppendMatchingResource(JDFNode::elm_Employee,JDFNode::ProcessUsage_AnyInput);
		emp.SetPersonalID("emp1");
		CPPUNIT_ASSERT( m.IsValid() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGrayBox()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("ProcessGroup");
		VString v;
		v.add("Interpreting");
		v.add("Rendering");
		n.SetTypes(v);
		v=n.GetInsertLinkVector(9999);
		CPPUNIT_ASSERT( v.contains("InterpretingParamsLink:AnyInput") );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testAppendMatchingResourceProduct()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetStatus(JDFElement::Status_Ready);
		n.SetType("Product");
		JDFComponent co=(JDFComponent) n.AppendMatchingResource("Component",JDFNode::ProcessUsage_Cover);
		vint vType;
		vType.add(JDFAutoComponent::ComponentType_FinalProduct);
		vType.add(JDFAutoComponent::ComponentType_Block);
		co.SetComponentType(vType);
		co=(JDFComponent)n.AppendMatchingResource("Component",JDFNode::ProcessUsage_Cover);
		co.SetComponentType(vType);
		co=(JDFComponent)n.AppendMatchingResource("Component",JDFNode::ProcessUsage_AnyOutput);
		co.SetComponentType(vType);
		CPPUNIT_ASSERT( n.IsValid() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetEnumTypes()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root=doc.GetJDFRoot();
		root.SetType("fnarf");
		CPPUNIT_ASSERT( root.getEnumTypes().empty() );

		root.SetType("ProcessGroup");

		root.SetTypes(vWString("InkZoneCalculation ConventionalPrinting"));
		CPPUNIT_ASSERT_EQUAL( (int)JDFNode::Type_InkZoneCalculation,(int)root.getEnumTypes().elementAt(0) );
		CPPUNIT_ASSERT_EQUAL( (int)JDFNode::Type_ConventionalPrinting,(int)root.getEnumTypes().elementAt(1) );
		CPPUNIT_ASSERT_EQUAL( 2,(int)root.getEnumTypes().size() );

		root.SetTypes(vWString("InkZoneCalculation xyz:fnarf ConventionalPrinting"));
		CPPUNIT_ASSERT( root.getEnumTypes().empty() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testAppendMatchingResourcePrivate()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.setCombined(WString("ConventionalPrinting fnarf ConventionalPrinting").Tokenize());
		JDFResource r=n.AppendMatchingResource(JDFNode::elm_ConventionalPrintingParams,JDFNode::ProcessUsage_Any);
		JDFResourceLink rl=n.getLink(r,JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT( !rl.isNull() );
		// the following won't work, you can't append unkown resource types:
		//r=n.AppendMatchingResource("FnarfParams",JDFNode::ProcessUsage_Any);
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testAppendMatchingResource()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.setCombined(WString("ConventionalPrinting ConventionalPrinting").Tokenize());
		JDFResource r=n.AppendMatchingResource(JDFNode::elm_ConventionalPrintingParams,JDFNode::ProcessUsage_Any);
		JDFResourceLink rl=n.getLink(r,JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT( !rl.isNull() );

		r=n.AppendMatchingResource(JDFNode::elm_ConventionalPrintingParams,JDFNode::ProcessUsage_Any);
		CPPUNIT_ASSERT( !r.isNull() );
		rl=n.getLink(r,JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT( !rl.isNull() );
		CPPUNIT_ASSERT_EQUAL( JDFResourceLink::Usage_Input,rl.GetUsage() );

		try
		{
			JDFResource r=n.AppendMatchingResource(JDFNode::elm_ConventionalPrintingParams,JDFNode::ProcessUsage_Any);
			CPPUNIT_FAIL( "exception 3" );
		}
		catch (JDFException&)
		{
			// nop
		}

		r=n.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_Any);
		CPPUNIT_ASSERT( !r.isNull() );
		rl=n.getLink(r,JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT( rl.isNull() );
		rl=n.LinkMatchingResource(r,JDFNode::ProcessUsage_Input);
		CPPUNIT_ASSERT( !rl.isNull() );
		CPPUNIT_ASSERT_EQUAL( JDFResourceLink::Usage_Input,rl.GetUsage() );
		CPPUNIT_ASSERT_EQUAL( (WString)"Input",rl.GetProcessUsage() );

		r=n.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);
		CPPUNIT_ASSERT( !r.isNull() );
		rl=n.getLink(r,JDFResourceLink::Usage_Output);
		CPPUNIT_ASSERT( !rl.isNull() );
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr,rl.GetProcessUsage() );

		n.setCombined(WString("Collecting ConventionalPrinting").Tokenize());
		for(int cLoop=0;cLoop<5;cLoop++)
		{
			r=n.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyInput);
			CPPUNIT_ASSERT( !r.isNull() );
			rl=n.getLink(r,JDFResourceLink::Usage_Input);
			CPPUNIT_ASSERT( !rl.isNull() );
			CPPUNIT_ASSERT_EQUAL( WString::emptyStr,rl.GetProcessUsage() );
		}
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetParentJDF()
{
	try
	{
		{
			JDFDoc d=JDFDoc(0);
			JDFNode n=d.GetJDFRoot();
			CPPUNIT_ASSERT( n.GetParentJDF().isNull() );
			JDFNode n2=(JDFNode)n.AppendElement("JDF");
			CPPUNIT_ASSERT_EQUAL( n,n2.GetParentJDF() );
		}
		{
			XMLDoc d=XMLDoc("ns:foo","ns");
			KElement e=d.GetRoot();
			JDFNode n=(JDFNode)e.AppendElement("JDF");
			CPPUNIT_ASSERT( n.GetParentJDF().isNull() );
			JDFNode n2=(JDFNode)n.AppendElement("JDF");
			CPPUNIT_ASSERT_EQUAL( n,n2.GetParentJDF() );
		} 
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetAllTypes()
{	
	try
	{
		JDFDoc doc(0);
		JDFNode root=doc.GetJDFRoot();
		root.SetType("fnarf");
		CPPUNIT_ASSERT_EQUAL( WString("fnarf"),root.getAllTypes().elementAt(0) );
		CPPUNIT_ASSERT_EQUAL( 1,(int)root.getAllTypes().size() );

		root.SetType("Product");
		CPPUNIT_ASSERT_EQUAL( WString("Product"),root.getAllTypes().elementAt(0) );
		CPPUNIT_ASSERT_EQUAL( 1,(int)root.getAllTypes().size() );

		root.SetType("ProcessGroup");
		CPPUNIT_ASSERT( root.getAllTypes().empty() );

		vWString types;
		types.add("foo");
		types.add("bar");
		root.SetTypes(types);

		CPPUNIT_ASSERT( types.containsAll(root.getAllTypes()) );
		CPPUNIT_ASSERT_EQUAL( types.size(),root.getAllTypes().size() );
		root.RemoveAttribute("Types");

		JDFNode n2 =root.AddCombined(types);
		n2.SetTypes(types);

		CPPUNIT_ASSERT( types.containsAll(root.getAllTypes()) );
		CPPUNIT_ASSERT_EQUAL( types.size(),root.getAllTypes().size() );
		CPPUNIT_ASSERT( types.containsAll(n2.getAllTypes()) );
		CPPUNIT_ASSERT_EQUAL( types.size(),n2.getAllTypes().size() );

		root.AddJDFNode(JDFNode::Type_Unknown);

		CPPUNIT_ASSERT( types.containsAll(n2.getAllTypes()) );
		CPPUNIT_ASSERT_EQUAL( types.size(),n2.getAllTypes().size() );
		types.add(JDFNode::TypeString(JDFNode::Type_Unknown));
		CPPUNIT_ASSERT( types.containsAll(root.getAllTypes()) );
		CPPUNIT_ASSERT_EQUAL( types.size(),root.getAllTypes().size() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetMatchingResource()
{
	try
	{
		JDFParser pars;
		pars.Parse(sm_dirTestData+"testMatchRes.jdf",false);
		JDFDoc doc= pars.GetDocument();
		JDFNode root = doc.GetJDFRoot();
		vElement v = root.GetvJDFNode("ProcessGroup",JDFNode::Activation_Unknown,false);
		JDFNode ppnode;
		for(int i=0;(int)i<v.size();i++)
		{
			JDFNode p=(JDFNode) v.elementAt(i);		
			if (p.GetCategory().equals("ContentCreation")) {
				ppnode=p;
			}
		} 
		CPPUNIT_ASSERT( !ppnode.isNull() );
		CPPUNIT_ASSERT( ppnode.GetTypes().contains(JDFNode::TypeString(JDFNode::Type_LayoutElementProduction)) );
		JDFResource res= ppnode.GetMatchingResource("RunList",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		CPPUNIT_ASSERT_EQUAL( JDFStrings::elm_RunList,res.GetNodeName() );
		res= ppnode.GetMatchingResource("LayoutElementProductionParams",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		CPPUNIT_ASSERT_EQUAL( JDFStrings::elm_LayoutElementProductionParams,res.GetNodeName() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetLinksForType()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();

		root.SetType(JDFNode::TypeString(JDFNode::Type_Combined));
		root.SetTypes(vWString("Cutting Folding Cutting",WString::whiteSpace));

		JDFResource r1=root.addResource("CuttingParams", JDFResource::Class_Parameter, JDFResourceLink::Usage_Input); 
		JDFResourceLink rl1=root.getLink(r1,JDFResourceLink::Usage_Input);
		rl1.SetCombinedProcessIndex(JDFIntegerList(0));

		JDFResource r2=root.addResource("FoldingParams", JDFResource::Class_Parameter, JDFResourceLink::Usage_Input); 
		JDFResourceLink rl2=root.getLink(r2,JDFResourceLink::Usage_Input);
		rl2.SetCombinedProcessIndex(JDFIntegerList(1));

		JDFResource r3=root.addResource("CuttingParams", JDFResource::Class_Parameter, JDFResourceLink::Usage_Input);
		JDFResourceLink rl3=root.getLink(r3,JDFResourceLink::Usage_Input);
		rl3.SetCombinedProcessIndex(JDFIntegerList(2));
		
		JDFResource r4=root.addResource("Component", JDFResource::Class_Quantity, JDFResourceLink::Usage_Output);
		JDFResourceLink rl4=root.getLink(r4,JDFResourceLink::Usage_Output);
		
		vElement ve=root.getLinksForType(JDFNode::Type_Cutting,0);

		CPPUNIT_ASSERT_EQUAL( 1,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl1) );
		CPPUNIT_ASSERT( !ve.hasElement(rl4) );

		ve=root.getLinksForType(JDFNode::Type_Cutting,1);
		CPPUNIT_ASSERT_EQUAL( 2,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl3) );
		CPPUNIT_ASSERT( ve.hasElement(rl4) );

		ve=root.getLinksForType(JDFNode::Type_Cutting,-1);
		CPPUNIT_ASSERT_EQUAL( 3,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl1) );
		CPPUNIT_ASSERT( ve.hasElement(rl3) );
		CPPUNIT_ASSERT( ve.hasElement(rl4) );

		ve=root.getLinksForType(JDFNode::Type_Folding,0);
		CPPUNIT_ASSERT_EQUAL( 1,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl2) );
		CPPUNIT_ASSERT( !ve.hasElement(rl4) );

		ve=root.getLinksForCombinedProcessIndex(0);
		CPPUNIT_ASSERT_EQUAL( 1,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl1) );
		CPPUNIT_ASSERT( !ve.hasElement(rl4) );

		ve=root.getLinksForCombinedProcessIndex(1);
		CPPUNIT_ASSERT_EQUAL( 1,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl2) );
		CPPUNIT_ASSERT( !ve.hasElement(rl4) );

		// now check whether this works with no cpi
		rl4.RemoveAttribute(JDFNode::atr_CombinedProcessIndex);
		ve=root.getLinksForType(JDFNode::Type_Folding,0);
		CPPUNIT_ASSERT_EQUAL( 2,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl2) );
		CPPUNIT_ASSERT( ve.hasElement(rl4) );

		ve=root.getLinksForCombinedProcessIndex(0);
		CPPUNIT_ASSERT_EQUAL( 2,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl1) );
		CPPUNIT_ASSERT( ve.hasElement(rl4) );

		ve=root.getLinksForCombinedProcessIndex(1);
		CPPUNIT_ASSERT_EQUAL( 2,(int)ve.size() );
		CPPUNIT_ASSERT( ve.hasElement(rl2) );
		CPPUNIT_ASSERT( ve.hasElement(rl4) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetMatchingResourceStar()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_Combine));

		for(int i=0;i<5;i++)
		{
			JDFResource res= root.AppendMatchingResource("RunList",JDFNode::ProcessUsage_AnyInput,JDFNode());
			CPPUNIT_ASSERT( !res.isNull() );
			CPPUNIT_ASSERT_EQUAL( JDFStrings::elm_RunList,res.GetNodeName() );
			JDFResource resa= root.GetMatchingResource("RunList",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,i);
			CPPUNIT_ASSERT_EQUAL( res,resa );
			JDFResourceLink rlb= root.GetMatchingLink("RunList",JDFNode::ProcessUsage_AnyInput,i);
			CPPUNIT_ASSERT_EQUAL( res,rlb.GetTarget() );
		}
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetMissingLinks()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		vWString vs=root.GetMissingLinkVector(999);
		CPPUNIT_ASSERT( vs.contains(JDFStrings::elm_ConventionalPrintingParams+"Link:AnyInput") );
		CPPUNIT_ASSERT( vs.contains(JDFStrings::elm_Component+"Link:AnyOutput") );

		vWString vsc;
		vsc.add(JDFNode::TypeString(JDFNode::Type_InkZoneCalculation));
		vsc.add(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		root.setCombined(vsc);		
		vs=root.GetMissingLinkVector(999);
		
		CPPUNIT_ASSERT( vs.contains(JDFStrings::elm_Preview+"Link:AnyInput") );
		CPPUNIT_ASSERT( vs.contains(JDFStrings::elm_ConventionalPrintingParams+"Link:AnyInput") );
		CPPUNIT_ASSERT( vs.contains(JDFStrings::elm_Component+"Link:AnyOutput") );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetMissingLinksProduct()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_Product));
		VString vs=root.GetMissingLinkVector(999);
		CPPUNIT_ASSERT( vs.contains(JDFStrings::elm_Component+"Link:AnyOutput") );

		root.AddJDFNode(JDFNode::Type_ProcessGroup);
		root.AppendMatchingResource("Employee", JDFNode::ProcessUsage_AnyInput, JDFNode::DefJDFNode);
		vs=root.GetMissingLinkVector(999);
		CPPUNIT_ASSERT( vs.contains(JDFStrings::elm_Component+"Link:AnyOutput") );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetUnknownLinks()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		vElement vs=root.getUnknownLinkVector(vWString::emptyvStr,999);
		CPPUNIT_ASSERT( vs.empty() );

		root.addResource(JDFStrings::elm_FoldingParams, JDFResource::Class_Parameter, JDFResourceLink::Usage_Input);//, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);

		vs=root.getUnknownLinkVector(vWString::emptyvStr,999);
		CPPUNIT_ASSERT( ((JDFElement)vs[0]).IsResourceLink() );
		CPPUNIT_ASSERT_EQUAL( (WString)"FoldingParamsLink",JDFResourceLink(vs[0]).GetLocalName() );

		root.addResource("foo:barRes", JDFResource::Class_Parameter, JDFResourceLink::Usage_Input, JDFNode::ProcessUsage_Unknown, JDFNode::DefJDFNode, "www.foo.com", JDFResource::DefJDFResource);

		vs=root.getUnknownLinkVector(vWString::emptyvStr,999);
		CPPUNIT_ASSERT_EQUAL( 2,(int)vs.size() );
		CPPUNIT_ASSERT( JDFElement(vs[0]).IsResourceLink() );
		CPPUNIT_ASSERT_EQUAL( (WString)"FoldingParamsLink",JDFResourceLink(vs[0]).GetLocalName() );
		CPPUNIT_ASSERT_EQUAL( (WString)"foo:barResLink",JDFResourceLink(vs[1]).GetNodeName() );

		vWString vsc;
		vsc.add(JDFNode::TypeString(JDFNode::Type_InkZoneCalculation));
		vsc.add(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		root.setCombined(vsc);
		vs=root.getUnknownLinkVector(vWString::emptyvStr,999);
		CPPUNIT_ASSERT( JDFElement(vs[0]).IsResourceLink() );
		CPPUNIT_ASSERT_EQUAL( (WString)"FoldingParamsLink",JDFResourceLink(vs[0]).GetLocalName() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetActivation()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root=doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_ProcessGroup));
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Active,root.GetActivation(true) );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Active,root.GetActivation(false) ); // defaults to Activaton_Active when attribute not found
		vWString types;
		types.add("foo");
		types.add("bar");

		JDFNode n2 =root.AddCombined(types);
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Active,n2.GetActivation(true) );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Active,n2.GetActivation(false) ); // defaults to Activaton_Active, when attribute not found

		root.SetActivation(JDFNode::Activation_Inactive);
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Inactive,root.GetActivation(true) );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Inactive,root.GetActivation(false) );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Inactive,n2.GetActivation(true) );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Active,n2.GetActivation(false) ); // defaults to Activaton_Active, when attribute not found

		n2.SetActivation(JDFNode::Activation_Active);
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Inactive,n2.GetActivation(true) );
		CPPUNIT_ASSERT_EQUAL( JDFNode::Activation_Active,n2.GetActivation(false) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFNodeTest::testGetLink()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_ImageSetting));
		{
			JDFResource r=root.addResource("foo:res", JDFResource::Class_Parameter, JDFResourceLink::Usage_Input, WString::emptyStr, JDFNode::DefJDFNode, "www.foo.com");
			JDFResourceLink rl=root.GetLink(r);
			CPPUNIT_ASSERT( !rl.isNull() );
		}
		{
			JDFResource r=root.addResource(JDFNode::elm_Media, JDFResource::Class_Quantity, JDFResourceLink::Usage_Input);
			JDFResourceLink rl=root.GetLink(r);
			CPPUNIT_ASSERT( !rl.isNull() );
		}
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
