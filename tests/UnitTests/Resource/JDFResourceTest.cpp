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
// created 10 Aug 2006
//
// JDFResourceTest.cpp: implements CppUnit tests for JDF Resources
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFGeneralID.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFResourceTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFResourceTest);

const WString sm_dirTestData = L"data/";

void JDFResourceTest::setUp()
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

static JDFDoc creatRLDoc()
{
	JDFDoc doc(0);
	JDFNode n=doc.GetJDFRoot();
	n.SetJobPartID("P1");
	n.SetJobID("J1");
	n.SetType("Interpreting");

	JDFRunList rl=(JDFRunList)n.AppendMatchingResource("RunList",JDFNode::ProcessUsage_AnyInput,JDFNode::DefJDFNode);
	for(int i=1;i<3;i++)
	{
		JDFRunList rlset=(JDFRunList) rl.AddPartition(JDFResource::PartIDKey_RunSet,"Set"+WString::valueOf(i));
		vWString filNames=WString("FCyan.pdf FMagenta.pdf FYellow.pdf FBlack.pdf").Tokenize(WString::whiteSpace);
		vWString sepNames=WString("Cyan Magenta Yellow Black").Tokenize(WString::whiteSpace);
		JDFRunList rlRun=rlset.AddSepRun(filNames,sepNames,0,16,false);
		rlRun.SetRun("Run"+WString::valueOf(i));
		rlRun.SetSorted(true);
		rlRun.AppendElement("foo:bar","www.foobar.com");
	}

	return doc;
}


void JDFResourceTest::testInit()
{
	try
	{
		JDFDoc doc=creatXMDoc();
		JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		CPPUNIT_ASSERT( xm.HasAttribute(JDFStrings::atr_AgentName) ); 
		CPPUNIT_ASSERT( xm.HasAttribute(JDFStrings::atr_AgentVersion) ); 
		
		// backup static agent name
		WString stdAgentName = JDFAudit::getStaticAgentName();
		JDFAudit::setStaticAgentName("foo");
		xm.init(); 
		CPPUNIT_ASSERT_EQUAL( WString("foo"), xm.GetAgentName() );

		// restore values for following tests
		JDFAudit::setStaticAgentName(stdAgentName);
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
void JDFResourceTest::testGetResourceRoot()
{
	try
	{
		XMLDoc jdfDoc(JDFStrings::elm_ColorPool);
		JDFElement root = (JDFElement)jdfDoc.GetRoot();
		JDFResource resource;
		JDFResource resRoot = ((JDFResource)root).GetResourceRoot();;
		CPPUNIT_ASSERT( !resRoot.isNull() );
		resRoot = resource.GetResourceRoot();
		CPPUNIT_ASSERT( resRoot.isNull() );
		resource = (JDFResource) root.AppendElement(JDFElement::elm_Color);

		jdfDoc = XMLDoc(JDFStrings::elm_ResourcePool);
		root = (JDFElement)jdfDoc.GetRoot();
		resource = (JDFResource) root.AppendElement(JDFElement::elm_Color);
		resRoot = resource.GetResourceRoot();
		CPPUNIT_ASSERT_EQUAL( resource,resRoot );

		JDFDoc jdfDoc2(0);
		root = jdfDoc2.GetJDFRoot();
		resource = (JDFResource) root.AppendElement(JDFElement::elm_Color);
		JDFResource elem = (JDFResource) root.AppendElement(JDFElement::elm_NodeInfo);
		try
		{
			resRoot = resource.GetResourceRoot();
			CPPUNIT_FAIL( "JDFResource.GetResourceRoot() ran into the JDF node while searching" );
		}
		catch( ... )
		{
			// this was expected
		}

		resRoot = elem.GetResourceRoot();
		CPPUNIT_ASSERT_EQUAL( elem,resRoot );

		JDFNode rootNode=(JDFNode) root;
		JDFExposedMedia xm=(JDFExposedMedia) rootNode.addResource("ExposedMedia", JDFResource::Class_Unknown, JDFResourceLink::Usage_Input, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		JDFMedia m=xm.AppendMedia();
		CPPUNIT_ASSERT_EQUAL( xm.ToString(),xm.GetResourceRoot().ToString() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}



    void JDFResourceTest::testGeneralID()
    {
        JDFDoc doc=creatXMDoc();
        JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput);
		JDFExposedMedia xm2=(JDFExposedMedia) xm.GetPartition(JDFAttributeMap("SignatureName","Sig1"),JDFResource::PartUsage_Explicit);  
        xm.setGeneralID("foo","bar");
        CPPUNIT_ASSERT_EQUAL(xm.getGeneralID("foo"),WString("bar"));
        CPPUNIT_ASSERT_EQUAL(xm2.getGeneralID("foo"),WString("bar"));
		CPPUNIT_ASSERT_EQUAL(xm.NumChildElements(JDFStrings::elm_GeneralID),1);
        xm.setGeneralID("foo","bar2");
        CPPUNIT_ASSERT_EQUAL(xm.getGeneralID("foo"),WString("bar2"));
        CPPUNIT_ASSERT_EQUAL(xm.NumChildElements(JDFStrings::elm_GeneralID),1);
        CPPUNIT_ASSERT_EQUAL(xm2.NumChildElements(JDFStrings::elm_GeneralID),1);
        xm2.setGeneralID("foo","bar4");
        xm.setGeneralID("foo2","bar3");
        CPPUNIT_ASSERT_EQUAL(xm.getGeneralID("foo"),WString("bar2"));
        CPPUNIT_ASSERT_EQUAL(xm2.getGeneralID("foo"),WString("bar4"));
        CPPUNIT_ASSERT_EQUAL(xm.getGeneralID("foo2"),WString("bar3"));
        CPPUNIT_ASSERT_EQUAL(xm.NumChildElements(JDFStrings::elm_GeneralID),2);
        xm.removeGeneralID("foo");
		CPPUNIT_ASSERT_EQUAL(WString::emptyStr,xm.getGeneralID("foo"));
        CPPUNIT_ASSERT_EQUAL(xm.getGeneralID("foo2"),WString("bar3"));
        CPPUNIT_ASSERT_EQUAL(xm.NumChildElements(JDFStrings::elm_GeneralID),1);  
        xm.setGeneralID("foo3","bar33");
        JDFGeneralID gi=xm.getGeneralID(0);
        CPPUNIT_ASSERT_EQUAL(gi.GetIDUsage(),WString("foo2"));
        xm.removeGeneralID(L"");
        CPPUNIT_ASSERT_EQUAL(xm.NumChildElements(JDFStrings::elm_GeneralID),0);  
    }

void JDFResourceTest::testGetPartMap()
{
	try
	{
		WString strFileName = sm_dirTestData+"partitioned_private_resources.jdf";
		JDFParser p;
		p.Parse(strFileName, false);
		JDFDoc myJDFDoc             = p.GetDocument();
		JDFNode myRoot              = myJDFDoc.GetJDFRoot();
		JDFResourcePool myResPool   = myRoot.GetResourcePool();
		JDFResource myPreview       = (JDFResource)myResPool.GetElement("Preview", WString::emptyStr, 0);
		JDFAttributeMap m;

		m.put("Side", "Front");
		m.put("Separation", "Black");
		m.put("PreviewType", "Separation");

		myPreview = myPreview.GetPartition(m, JDFResource::PartUsage_Explicit);
		vElement vRes = myPreview.GetLeaves(false);

		for (int i = 0; i < vRes.size(); i++)
		{
			JDFAttributeMap myMap = ((JDFResource) vRes.elementAt(i)).GetPartMap(); 
			if (WString("Black").equals(myMap.GetValue("Separation")))
			{				
				CPPUNIT_ASSERT_EQUAL( WString("Front"),myMap.GetValue("Side") );
				CPPUNIT_ASSERT_EQUAL( WString("Separation"),myMap.GetValue("PreviewType") );
				CPPUNIT_ASSERT ( myMap.GetValue("SheetName").startsWith("Sheet ") ); // "Sheet 1" or "Sheet 2"
				CPPUNIT_ASSERT_EQUAL( WString("Black"),myMap.GetValue("Separation") );
			}
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetPartMapVector()
{
	try
	{
		WString strFileName = sm_dirTestData+"partitioned_private_resources.jdf";
		JDFParser p;
		p.Parse(strFileName, false);
		JDFDoc myJDFDoc = p.GetDocument();
		JDFNode myRoot = myJDFDoc.GetJDFRoot();
		JDFResourcePool myResPool = myRoot.GetResourcePool();
		JDFResource myPreview = (JDFResource) myResPool.GetElement("Preview", WString::emptyStr, 0);
		
		vmAttribute vJDFAttrMap = myPreview.GetPartMapVector(false);
		//there must be 12 maps in the map vector
		CPPUNIT_ASSERT_EQUAL( 12,(int)vJDFAttrMap.size() );

		for (int i = 0; i < vJDFAttrMap.size(); i++) 
		{
			mAttribute myMap = vJDFAttrMap[i];
			CPPUNIT_ASSERT( myMap.HasKey("Side") );
			CPPUNIT_ASSERT( myMap.HasKey("PreviewType") );
			CPPUNIT_ASSERT( myMap.HasKey("SheetName") );
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetColorPool()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();

		JDFResourcePool resPool = root.AppendResourcePool();
		JDFColorantControl colControl = (JDFColorantControl)resPool.AppendElement(JDFStrings::elm_ColorantControl, WString::emptyStr);          
		colControl.SetProcessColorModel("DeviceCMY");
		colControl.AppendColorantParams().AppendSeparationSpec().SetName("Spot");

		JDFColorSpaceConversionParams cpp=(JDFColorSpaceConversionParams) root.addResource(JDFStrings::elm_ColorSpaceConversionParams, JDFResource::Class_Unknown, JDFResourceLink::Usage_Input, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		JDFColorSpaceConversionOp cso=cpp.AppendColorSpaceConversionOp();
		cso.AddSourceObjects(JDFAutoColorSpaceConversionOp::SourceObjects_ImagePhotographic);
		cso.AddSourceObjects(JDFAutoColorSpaceConversionOp::SourceObjects_LineArt);

		// GetSeparations
		vWString vSeps=colControl.GetSeparations();		
		CPPUNIT_ASSERT_EQUAL( 4,(int)vSeps.size() );
		CPPUNIT_ASSERT( vSeps.contains("Cyan") );
		CPPUNIT_ASSERT( vSeps.contains("Spot") );
		CPPUNIT_ASSERT( !vSeps.contains("Black") );

		JDFColorPool colorPool = (JDFColorPool)resPool.AppendElement(JDFStrings::elm_ColorPool, WString::emptyStr);
		
		colControl.RefElement(colorPool);
		// now colControl contains the ref element colPoolRef

		JDFColorPool colPool2 = colControl.GetColorPool();

		// assert that we get the true color pool and not the ref element
		CPPUNIT_ASSERT( colorPool == colPool2 );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testPartitionedAttribute()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		JDFExposedMedia xm=(JDFExposedMedia)root.AppendMatchingResource(JDFStrings::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput,JDFNode::DefJDFNode);
		xm.SetResolution(JDFXYPair(300,300));
		xm.SetPolarity(true);
		xm.SetProofType(JDFExposedMedia::ProofType_Page);
		JDFMedia m=xm.AppendMedia();
		m.SetDimension(JDFXYPair(200,300));
		JDFExposedMedia xm2=(JDFExposedMedia) xm.AddPartition(JDFResource::PartIDKey_SheetName,"S1");
		CPPUNIT_ASSERT_EQUAL( 200.0,xm2.GetMedia().GetDimension().GetX() ); // Media inline Dimension
		CPPUNIT_ASSERT_EQUAL( 300.0,xm.GetResolution().GetX() );            // ExposedMedia direct Resolution
		CPPUNIT_ASSERT_EQUAL( 300.0,xm2.GetResolution().GetX() );           // ExposedMedia inherited Resolution
		JDFResource r = m.MakeRootResource(WString::emptyStr,JDFElement::DefKElement,true);
		m = (JDFMedia)r.GetTarget();
		CPPUNIT_ASSERT_EQUAL( 200.0,xm2.GetMedia().GetDimension().GetX() ); // Media referenced Dimension
		JDFRefElement re = (JDFRefElement)xm2.GetElement("MediaRef");
		CPPUNIT_ASSERT( !re.isNull() );
		JDFMedia m2=(JDFMedia) re.GetTarget();
		CPPUNIT_ASSERT_EQUAL( m2,m );
		CPPUNIT_ASSERT( xm2.HasChildElement("Media",WString::emptyStr, false) );
		CPPUNIT_ASSERT( xm2.GetPolarity() );
		CPPUNIT_ASSERT_EQUAL(  JDFExposedMedia::ProofType_Page,xm2.GetProofType() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testPartitionedElement()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		JDFColorantControl cc=(JDFColorantControl)root.AppendMatchingResource(JDFStrings::elm_ColorantControl,JDFNode::ProcessUsage_AnyInput,JDFNode::DefJDFNode);
		cc.SetPartUsage(JDFResource::PartUsage_Implicit);
		vWString seps=WString("Cyan Magenta Yellow Black").Tokenize(WString::whiteSpace);
		cc.AppendColorantOrder().setSeparations(seps);
		JDFColorantControl cc2=(JDFColorantControl) cc.AddPartition(JDFResource::PartIDKey_SheetName,"S1");
		seps.add("smurf blue");
		cc2.AppendColorantOrder().setSeparations(seps);
		JDFColorantControl select=(JDFColorantControl)cc.GetPartition(JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"s0"));
		CPPUNIT_ASSERT_EQUAL( cc,select );
		select=(JDFColorantControl)cc.GetPartition(JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"S1"));
		CPPUNIT_ASSERT_EQUAL( cc2,select );
		seps.add("dragon red");
		cc.AppendDeviceColorantOrder().setSeparations(seps);
		CPPUNIT_ASSERT( select.GetColorantOrder().GetSeparations().contains("smurf blue") );
		CPPUNIT_ASSERT( select.GetDeviceColorantOrder().GetSeparations().contains("dragon red") ); 
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetCreatePartition()
{
	try
	{
		JDFDoc doc(0);
		JDFElement root = doc.GetJDFRoot();
		JDFResourcePool resPool = (JDFResourcePool)root.AppendElement(JDFStrings::elm_ResourcePool, WString::emptyStr);
		JDFResource resPreview = resPool.AppendResource("Preview", JDFResource::Class_Parameter, WString::emptyStr);
		JDFAttributeMap partMap;

		//create 2x PreviewType Partition
		partMap.put("PreviewType", "ThumbNail");
		JDFResource resPreviewType = resPreview.GetCreatePartition(partMap, WString::emptyStr);
		partMap.clear();
		partMap.put("PreviewType", "Viewable");
		resPreview.GetCreatePartition(partMap, WString::emptyStr);

		//create a partition with same name under the existing one (MUST FAIL)
		try
		{
			partMap.clear();
			partMap.put("PreviewType", "SeparatedThumbNail");
			resPreviewType.GetCreatePartition(partMap, WString::emptyStr);
			CPPUNIT_FAIL( "create a partition with same name" );
		}
		catch( ... )
		{
			//expected to fail, do nothing
		}

		//try to create the partition directly 
		//because we create a "SheetName" partition under the "PreviewType="Thumbnail"
		//we dont need to add PreviewType to the partmap
		partMap.clear();
		partMap.put("SheetName", "Cover");
		resPreviewType.GetCreatePartition(partMap, WString::emptyStr);

		//create subpartition under Preview Viewable 
		partMap.clear();
		partMap.put("PreviewType", "Viewable");
		partMap.put("SheetName", "Cover");
		resPreview.GetCreatePartition(partMap, WString::emptyStr);

		//create two new partitions in one (MUST FAIL) 
		try
		{
			partMap.clear();
			partMap.put("PreviewType", "Viewable");
			partMap.put("SheetName", "Cover");
			partMap.put("Side", "Front");
			partMap.put("WebName", "0001");
			resPreview.GetCreatePartition(partMap, WString::emptyStr);
			//failed
			CPPUNIT_FAIL ( "created two new partitions in one" );
		}
		catch( ... )
		{
			//do nothing
		}

		//same as above but this we use the second parameter to create a structure of partitions
		vWString struc;
		struc.add("PreviewType");
		struc.add("SheetName");
		struc.add("Side");
		struc.add("WebName");

		partMap.clear();
		partMap.put("PreviewType", "Viewable");
		partMap.put("SheetName", "Cover");
		partMap.put("Side", "Front");
		partMap.put("WebName", "0001");
		JDFResource resWebName = resPreview.GetCreatePartition(partMap, struc);

		//create a partition while inside a partition
		partMap.clear();
		partMap.put("PreviewType", "Viewable");
		partMap.put("SheetName", "Cover");
		partMap.put("Side", "Front");
		partMap.put("WebName", "0001");
		partMap.put("DocRunIndex", "0001");

		resWebName.GetCreatePartition(partMap, WString::emptyStr);

		//Nächster Test
		partMap.clear();
		partMap.put("PreviewType", "Viewable");
		partMap.put("SheetName", "Cover");
		partMap.put("Side", "Front");
		partMap.put("WebName", "0001");
		partMap.put("DocRunIndex", "0001");

		struc.clear();
		struc.add("PreviewType");
		struc.add("SheetName");
		struc.add("Side");
		struc.add("WebName");
		struc.add("DocRunIndex");

		resWebName.GetCreatePartition(partMap, struc);

		// Nächster Test
		partMap.clear();
		partMap.put("PreviewType", "Viewable");
		partMap.put("SheetName", "Cover");
		partMap.put("Side", "Front");
		partMap.put("WebName", "0001");
		partMap.put("DocRunIndex", "0001");
		partMap.put("CellIndex", "0002");

		struc.clear();
		struc.add("PreviewType");
		struc.add("SheetName");
		struc.add("Side");
		struc.add("WebName");
		struc.add("DocRunIndex");
		struc.add("CellIndex");

		resPreview.GetCreatePartition(partMap, struc);

		// create a partition while inside a partition
		partMap.clear();
		partMap.put("PreviewType", "Viewable");
		partMap.put("SheetName", "Cover");
		partMap.put("Side", "Front");
		partMap.put("WebName", "0001");
		partMap.put("DocRunIndex", "0001");
		partMap.put("CellIndex", "0002");

		JDFResource resCellIndex = resPreview.GetCreatePartition(partMap, WString::emptyStr);

		partMap.clear();
		partMap.put("PreviewType", "Viewable");
		partMap.put("SheetName", "Cover");
		partMap.put("Side", "Front");
		partMap.put("WebName", "0001");
		partMap.put("DocRunIndex", "0001");
		partMap.put("CellIndex", "0002");
		partMap.put("PartVersion", "003");

		resCellIndex.GetCreatePartition(partMap, WString::emptyStr);

		//next test
		JDFResource r = (JDFResource)resPool.GetChildByTagName("Preview",WString::emptyStr, 0, mAttribute::emptyMap, true, true);
		JDFAttributeMap map;
		map.put("PreviewType", "Viewable");
		map.put("SheetName", "Cover");

		JDFResource part1 = r.GetPartition(map, JDFResource::PartUsage_Explicit);
		JDFResource part2 = r.GetCreatePartition(map, WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( part1.ToString(),part2.ToString() );

		map.put("Side", "Front");
		JDFResource part11 = part1.GetPartition(map, JDFResource::PartUsage_Explicit);
		JDFResource part12 = part1.GetCreatePartition(map, WString::emptyStr);

		CPPUNIT_ASSERT_EQUAL( part11.ToString(),part12.ToString() );

		//doc.write2File(sm_dirTestDataTemp+"testGetCreatePartition.jdf", 0, true);
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetPartsPartition()
{
	try
	{
		JDFDoc doc(0);
		JDFNode n=doc.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		JDFExposedMedia xm=(JDFExposedMedia) n.AppendMatchingResource(JDFResource::elm_ExposedMedia,JDFNode::ProcessUsage_AnyInput,JDFNode::DefJDFNode);
		JDFExposedMedia xmp=(JDFExposedMedia) xm.AddPartition(JDFResource::PartIDKey_PartVersion,"DE FR");
		JDFMedia m=(JDFMedia) n.AppendMatchingResource(JDFResource::elm_Media,JDFNode::ProcessUsage_AnyInput,JDFNode::DefJDFNode);
		JDFMedia mp=(JDFMedia) m.AddPartition(JDFResource::PartIDKey_SheetIndex,"1 ~ 3");

		// tests for partition list 
		// DE from DE FR
		mAttribute aTemp(JDFResource::PartIDKeyString(JDFResource::PartIDKey_PartVersion), "DE");
		JDFResource actual = xm.GetPartition(aTemp,JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT_EQUAL( xmp.ToString(),actual.ToString() );
		aTemp = mAttribute(JDFResource::PartIDKeyString(JDFResource::PartIDKey_PartVersion), "GR");
		actual = xm.GetPartition(aTemp,JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT( actual.isNull() );

		// get 2 from 1~3
		aTemp = mAttribute(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetIndex), "2");
		actual = m.GetPartition(aTemp,JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT_EQUAL( mp.ToString(),actual.ToString() );
		aTemp = mAttribute(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetIndex), "42");
		actual = m.GetPartition(aTemp,JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT( actual.isNull() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetPartitionVector()
{
	try
	{
		JDFDoc doc=creatXMDoc();
		JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		xm.SetPartUsage(JDFResource::PartUsage_Implicit);
		JDFAttributeMap m("SignatureName","Sig1");
		m.put("RunIndex","3");
		VElement v=xm.GetPartitionVector(m,JDFResource::PartUsage_Unknown);
		JDFResource r=xm.GetPartition(m,JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT_EQUAL( r,xm.GetPartition(JDFAttributeMap("SignatureName","Sig1"),JDFResource::PartUsage_Unknown) );
		CPPUNIT_ASSERT_EQUAL( 4,(int)v.size() );
		for(int i=0;i<v.size();i++)
		{
			JDFExposedMedia xmp=(JDFExposedMedia) v.elementAt(i);
			CPPUNIT_ASSERT( m.OverlapMap(xmp.GetPartMap()) );
		}
		v=xm.GetPartitionVector(m,JDFResource::PartUsage_Sparse);
		for(int i=0;i<v.size();i++)
		{
			JDFExposedMedia xmp=(JDFExposedMedia) v.elementAt(i);
			CPPUNIT_ASSERT( m.OverlapMap(xmp.GetPartMap()) );
		}
		CPPUNIT_ASSERT_EQUAL( 4,(int)v.size() ); // sparse == 4

		v=xm.GetPartitionVector(m,JDFResource::PartUsage_Explicit);
		CPPUNIT_ASSERT_EQUAL( 0,(int)v.size() ); // explicit == 0

		m.clear();
		m.put("SignatureName","Sig1");
		m.put("SheetName","S3");
		v=xm.GetPartitionVector(m,JDFResource::PartUsage_Explicit);
		CPPUNIT_ASSERT_EQUAL( 0,(int)v.size() ); // explicit == 0
		v=xm.GetPartitionVector(m,JDFResource::PartUsage_Sparse);
		CPPUNIT_ASSERT_EQUAL( 0,(int)v.size() ); // sparse == 0
		v=xm.GetPartitionVector(m,JDFResource::PartUsage_Implicit);
		CPPUNIT_ASSERT_EQUAL( 1,(int)v.size() ); // implicit == 1
		for(int i=0;i<v.size();i++)
		{
			JDFExposedMedia xmp=(JDFExposedMedia) v.elementAt(i);
			CPPUNIT_ASSERT( m.OverlapMap(xmp.GetPartMap()) );
		}        
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetLeaves()
{
	try
	{
        JDFDoc doc=creatXMDoc();
        JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
        
		VElement vL=xm.GetLeaves(false);
		CPPUNIT_ASSERT_EQUAL( 8,(int)vL.size() );
        for(int i=0;i<vL.size();i++)
        {
            JDFExposedMedia xm2=(JDFExposedMedia) vL.elementAt(i);
			CPPUNIT_ASSERT_EQUAL( 3,(int)xm2.GetPartMap().size() );
        }
        
		vL=xm.GetLeaves(true);
		CPPUNIT_ASSERT_EQUAL( 15,(int)vL.size() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testSubElement()
{
	try
	{
		JDFDoc doc=creatXMDoc();
		JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		JDFMedia m=xm.GetMedia();
		CPPUNIT_ASSERT_EQUAL( JDFResource::Class_Consumable,m.GetClass() );
		m.SetBrand("fooBrand");
		xm.IsValid(KElement::ValidationLevel_Complete);
		CPPUNIT_ASSERT( xm.IsValid(KElement::ValidationLevel_Complete) );
		CPPUNIT_ASSERT( m.IsValid(KElement::ValidationLevel_Complete) );
		m.DeleteNode();
		m=xm.AppendMedia();
		m.SetBrand("barBrand");
		CPPUNIT_ASSERT( xm.IsValid(KElement::ValidationLevel_Complete) );
		CPPUNIT_ASSERT( m.IsValid(KElement::ValidationLevel_Complete) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testSetLocked()
{
	try
	{
		JDFDoc doc=creatXMDoc();
		JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		xm.SetLocked(false);
		CPPUNIT_ASSERT( !xm.GetLocked() );
		CPPUNIT_ASSERT( !xm.HasAttribute(JDFStrings::atr_Locked) );
		VElement vL=xm.GetLeaves(false);
        for(int i=0;i<1;i++)
		{
			xm.SetLocked(false);
			JDFExposedMedia xm3=(JDFExposedMedia)vL.elementAt(i);
			JDFExposedMedia xm2=(JDFExposedMedia)xm3.GetParentNode();
			CPPUNIT_ASSERT( !xm2.GetLocked() );
			CPPUNIT_ASSERT( !xm3.GetLocked() );
			CPPUNIT_ASSERT( !xm2.HasAttribute(JDFStrings::atr_Locked) );
			CPPUNIT_ASSERT( !xm3.HasAttribute(JDFStrings::atr_Locked) );
			xm.SetLocked(true);
			CPPUNIT_ASSERT( xm.GetLocked() );
			CPPUNIT_ASSERT( xm2.GetLocked() );
			CPPUNIT_ASSERT( xm3.GetLocked() );
			CPPUNIT_ASSERT( !KElement(xm2).HasAttribute(JDFStrings::atr_Locked) );
			CPPUNIT_ASSERT( !KElement(xm3).HasAttribute(JDFStrings::atr_Locked) );
			xm2.SetLocked(false);
			CPPUNIT_ASSERT( !xm2.GetLocked() );
			CPPUNIT_ASSERT( !xm3.GetLocked() );
			CPPUNIT_ASSERT( KElement(xm2).HasAttribute(JDFStrings::atr_Locked) );
			CPPUNIT_ASSERT( !KElement(xm3).HasAttribute(JDFStrings::atr_Locked) );
			xm3.SetLocked(true);
			CPPUNIT_ASSERT( !xm2.GetLocked() );
			CPPUNIT_ASSERT( xm3.GetLocked() );
			CPPUNIT_ASSERT( KElement(xm2).HasAttribute(JDFStrings::atr_Locked) );
			CPPUNIT_ASSERT( KElement(xm3).HasAttribute(JDFStrings::atr_Locked) );
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testImplicitPartitions()
{
	try
	{
		JDFDoc doc=creatXMDoc();
		JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		CPPUNIT_ASSERT( xm.GetImplicitPartitions().empty() );
		JDFRunList ruli=(JDFRunList) n.addResource(JDFStrings::elm_RunList, JDFResource::Class_Unknown, 
			JDFResourceLink::Usage_Input, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, 
			JDFResource::DefJDFResource);
		JDFCutBlock cb=(JDFCutBlock) n.addResource(JDFStrings::elm_CutBlock, JDFResource::Class_Unknown, 
			JDFResourceLink::Usage_Input, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, 
			JDFResource::DefJDFResource);
		try
		{
			ruli.AddPartition(JDFResource::PartIDKey_RunIndex,"1");
			CPPUNIT_FAIL( "no go here" );
		}
		catch (const JDFException&) {
			// expected to fail
		}
		try
		{
			cb.AddPartition(JDFResource::PartIDKey_BlockName,"1");
			CPPUNIT_FAIL( "no go here" );
		}
		catch (const JDFException&) {
			// expected to fail
		}
		CPPUNIT_ASSERT( !ruli.HasAttribute(JDFStrings::atr_PartIDKeys) );
		CPPUNIT_ASSERT( !cb.HasAttribute(JDFStrings::atr_PartIDKeys) );
		ruli.AddPartition(JDFResource::PartIDKey_SheetName,"S1");
		CPPUNIT_ASSERT_EQUAL( JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),
			ruli.GetAttribute(JDFStrings::atr_PartIDKeys) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testRemoveImplicitPartions()
{
	try
	{
		JDFDoc doc(0);
		JDFNode n=doc.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_Interpreting));
		JDFRunList rul=(JDFRunList) n.AppendMatchingResource(JDFStrings::elm_RunList,JDFNode::ProcessUsage_AnyInput,JDFNode::DefJDFNode);

		// tests for partition list 
		CPPUNIT_ASSERT_EQUAL( rul.ToString(), rul.GetPartition(JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_RunIndex),"2~5"),JDFResource::PartUsage_Unknown).ToString() );
		CPPUNIT_ASSERT( rul.GetPartition(JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_PartVersion),"GR"),JDFResource::PartUsage_Unknown).isNull() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testCollapse()
{
	try
	{
		JDFDoc doc=creatRLDoc();
		JDFNode n=doc.GetJDFRoot();

		JDFDigitalPrintingParams dpp=(JDFDigitalPrintingParams) n.addResource(JDFStrings::elm_DigitalPrintingParams, JDFResource::Class_Unknown, JDFResourceLink::Usage_Input, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		dpp.Collapse(true);
		dpp.Collapse(false);

		JDFRunList rl=(JDFRunList)n.GetMatchingResource("RunList",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		JDFAttributeMap map;
		map.put("RunSet","Set2");
		JDFRunList rlSet=(JDFRunList) rl.GetPartition(map,JDFResource::PartUsage_Unknown);        
		CPPUNIT_ASSERT( !rlSet.isNull() );		
		map.put("Run","Run2");		
		JDFRunList rlRun=(JDFRunList) rl.GetPartition(map,JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT( !rlRun.isNull() );
		map.put("Separation","Cyan");
		JDFRunList rlSep=(JDFRunList) rl.GetPartition(map,JDFResource::PartUsage_Unknown);
		
		CPPUNIT_ASSERT( !rlSep.isNull() );
		CPPUNIT_ASSERT( rlRun.GetIsPage() );
		CPPUNIT_ASSERT( rlRun.GetIsPage() );
		CPPUNIT_ASSERT( !rlSep.GetIsPage() );
		rlRun.Collapse(true);
		CPPUNIT_ASSERT( rlRun.GetIsPage() );
		CPPUNIT_ASSERT( !rlSep.GetIsPage() );
		CPPUNIT_ASSERT( rlSet.GetIsPage() );
		CPPUNIT_ASSERT( rl.GetIsPage() );
		rlRun.Collapse(false);
		CPPUNIT_ASSERT( rlRun.GetIsPage() );
		CPPUNIT_ASSERT( !rlSep.GetIsPage() );
		CPPUNIT_ASSERT( rlSet.GetIsPage() );
		CPPUNIT_ASSERT( rl.GetIsPage() );
		rlRun.SetRunTag("foo");
		rlRun.Expand(true);
		rlRun.Collapse(false);

		CPPUNIT_ASSERT( KElement(rlRun).HasAttribute(JDFStrings::atr_RunTag, WString::emptyStr, false) );
		CPPUNIT_ASSERT( !KElement(rlSep).HasAttribute(JDFStrings::atr_RunTag, WString::emptyStr, false) );
		CPPUNIT_ASSERT( !KElement(rlSet).HasAttribute(JDFStrings::atr_RunTag, WString::emptyStr, false) );
		rlRun.Expand(true);

		rlRun.Collapse(true);
		CPPUNIT_ASSERT( !KElement(rlRun).HasAttribute(JDFStrings::atr_RunTag, WString::emptyStr, false) );
		CPPUNIT_ASSERT( KElement(rlSep).HasAttribute(JDFStrings::atr_RunTag, WString::emptyStr, false) );
		CPPUNIT_ASSERT( !KElement(rlSet).HasAttribute(JDFStrings::atr_RunTag, WString::emptyStr, false) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetElement()
{
	try
	{
		JDFDoc doc=creatXMDoc();
		JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		JDFMedia med=xm.GetMedia();

		JDFAttributeMap mPart("SignatureName","Sig1");
		mPart.put("SheetName","S1");
		mPart.put("Side","Front");       
		JDFExposedMedia xmPart=(JDFExposedMedia)xm.GetPartition(mPart,JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT_EQUAL( med,xm.GetMedia() );
		CPPUNIT_ASSERT_EQUAL( med,xmPart.GetMedia() );
		JDFExposedMedia xmPartSig=(JDFExposedMedia)xm.GetPartition(JDFAttributeMap("SignatureName","Sig1"),JDFResource::PartUsage_Unknown);
		JDFMedia med2=xmPartSig.AppendMedia();
		CPPUNIT_ASSERT_EQUAL( med,xm.GetMedia() );
		CPPUNIT_ASSERT_EQUAL( med2,xmPart.GetMedia() );
		CPPUNIT_ASSERT_EQUAL( med2,xmPartSig.GetMedia() );
		med=(JDFMedia) med.MakeRootResource(WString::emptyStr,JDFElement::DefKElement,true).GetTarget();
		CPPUNIT_ASSERT_EQUAL( med,xm.GetMedia() );
		CPPUNIT_ASSERT_EQUAL( med2,xmPart.GetMedia() );
		CPPUNIT_ASSERT_EQUAL( med2,xmPartSig.GetMedia() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetResStatus()
{
	try
	{
		JDFDoc doc=creatXMDoc();
		JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		JDFAttributeMap mPart("SignatureName","Sig1");
		mPart.put("SheetName","S1");
		mPart.put("Side","Front");       
		JDFExposedMedia xmPart=(JDFExposedMedia)xm.GetPartition(mPart,JDFResource::PartUsage_Unknown);
		xm.SetStatus(JDFResource::Status_Unavailable,false);
		JDFMedia med=xm.GetMedia();
		med.SetStatus(JDFResource::Status_Unavailable,false);
		med.MakeRootResource(WString::emptyStr,JDFElement::DefKElement,true);

		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xmPart.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(true) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xmPart.GetStatus(true) );

		xmPart.SetStatus(JDFResource::Status_Available,false);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xmPart.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(true) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xmPart.GetStatus(true) );

		med.SetStatus(JDFResource::Status_Available,false);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xmPart.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(true) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xmPart.GetStatus(true) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xmPart.GetStatus(true) );

		xmPart.RemoveAttribute(JDFElement::atr_Status);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xmPart.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(true) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xmPart.GetStatus(true) );

		xm.SetStatus(JDFResource::Status_Available,false);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xm.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xmPart.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xm.GetStatus(true) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xmPart.GetStatus(true) );

		med.SetStatus(JDFResource::Status_Unavailable,false);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xm.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,xmPart.GetStatus(false) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xm.GetStatus(true) );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,xmPart.GetStatus(true) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testConsistentPartIDKeys()
{
	try
	{
		JDFDoc doc=creatXMDoc();
		JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput,mAttribute::emptyMap,0);
		JDFAttributeMap mPart("SignatureName","Sig1");
		mPart.put("SheetName","S1");
		mPart.put("Side","Front");       
		JDFExposedMedia xmPart=(JDFExposedMedia)xm.GetPartition(mPart,JDFResource::PartUsage_Unknown);
		CPPUNIT_ASSERT( xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_BinderySignatureName) );
		CPPUNIT_ASSERT( xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_Side) );
		xmPart.RemoveAttribute("Side");
		CPPUNIT_ASSERT( !xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_Side) );
		CPPUNIT_ASSERT( xmPart.GetInvalidAttributes(KElement::ValidationLevel_Complete,false,999).contains("Side") );
		xm.SetAttribute("Side","Front");
		CPPUNIT_ASSERT( !xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_Side) );
		xmPart.SetAttribute("Side","Front");
		CPPUNIT_ASSERT( !xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_Side) );
		xm.RemoveAttribute("Side");
		CPPUNIT_ASSERT( xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_Side) );
		CPPUNIT_ASSERT( xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_SheetName) );
		xmPart.GetParentNode().RemoveAttribute("SheetName");
		CPPUNIT_ASSERT( !xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_SheetName) );
		xmPart.GetParentNode().SetAttribute("SignatureName","foo");
		CPPUNIT_ASSERT( !xmPart.ConsistentPartIDKeys(JDFResource::PartIDKey_SheetName) );
		CPPUNIT_ASSERT( xmPart.GetInvalidAttributes(KElement::ValidationLevel_Complete,false,999).contains("SignatureName"));
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testAddPartition()
{
	try
	{
		JDFDoc doc =JDFDoc(0);
		JDFNode n=doc.GetJDFRoot();
		JDFResource media=n.addResource("Media", JDFResource::Class_Quantity, JDFResourceLink::Usage_Input);

		JDFResource sig=media.AddPartition(JDFResource::PartIDKey_SignatureName, "sig1");
		try
		{
			media.AddPartition(JDFResource::PartIDKey_SheetName, "sh11");
			CPPUNIT_FAIL( "no parallel" );
		}
		catch (JDFException&)
		{
			// nop
		}

		try
		{
			sig.AddPartition(JDFResource::PartIDKey_SignatureName, "sig2");
			CPPUNIT_FAIL( "no existing" );
		}
		catch (JDFException&)
		{
			// nop
		}

		JDFResource sheet=sig.AddPartition(JDFResource::PartIDKey_SheetName, "sh1");
		try
		{
			JDFResource side=sig.AddPartition(JDFResource::PartIDKey_Side, "Front");
			CPPUNIT_FAIL( "no existing other parallel" );
		}
		catch (JDFException&)
		{
			// nop
		}
		try
		{
			sheet.AddPartition(JDFResource::PartIDKey_SignatureName, "Sig3");
			CPPUNIT_FAIL( "no existing lower" );
		}
		catch (JDFException&)
		{
			// nop
		}
		sheet.AddPartition(JDFResource::PartIDKey_Side, "Front");        
		sheet.AddPartition(JDFResource::PartIDKey_Side, "Back");
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testCreatePartitions()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFElement root = doc.GetJDFRoot();
		JDFResourcePool resPool = (JDFResourcePool)root.AppendElement(JDFNode::elm_ResourcePool);
		JDFResource resPreview = resPool.AppendResource("Preview", JDFResource::Class_Parameter);
		mAttribute partMap;
		partMap.put(JDFResource::atr_SignatureName, "Sig1");
		partMap.put(JDFResource::atr_SheetName, "Sheet1");
		partMap.put(JDFResource::atr_PartVersion, "De");
		mAttribute partMap2 = mAttribute(partMap);
		partMap2.put(JDFResource::atr_PartVersion, "En");
		vmAttribute v;
		v.AppendUnique(partMap);
		v.AppendUnique(partMap2);
		vWString vs=vWString("SignatureName SheetName PartVersion");
		vWString vs2=vWString("PartVersion SignatureName SheetName");

		vElement parts=resPreview.CreatePartitions(v, vs);
		CPPUNIT_ASSERT_EQUAL( 2,(int)parts.size() );

		vElement parts2=resPreview.CreatePartitions(v, vs2);
		CPPUNIT_ASSERT_EQUAL( parts.size(),parts2.size() );
		bool areEqual = true;
		for (int i = 0; i < parts.size(); i++)
		{
			if (parts[i] != parts2[i])
			{
				areEqual = false;
				break;
			}
		}
		CPPUNIT_ASSERT( areEqual );

		// next test
		resPreview.DeleteNode();
		resPreview = resPool.AppendResource("Preview", JDFResource::Class_Parameter);

		vs=vWString("SignatureName SheetName");
		vmAttribute vShort;

		mAttribute partMapShort;
		partMapShort.put(JDFResource::atr_SignatureName, "Sig1");
		partMapShort.put(JDFResource::atr_SheetName, "Sheet1");
		vShort.push_back(partMapShort);

		parts=resPreview.CreatePartitions(vShort, vs);
		CPPUNIT_ASSERT_EQUAL( 1,(int)parts.size() );

		parts2=resPreview.CreatePartitions(v, vs2);
		CPPUNIT_ASSERT_EQUAL( 2,(int)parts2.size() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetPartValues()
{
	try
	{
		WString strFileName = sm_dirTestData+"partitioned_private_resources.jdf";
		JDFParser p;
		p.Parse(strFileName, false);

		JDFDoc myJDFDoc           = p.GetDocument();
		JDFNode myRoot            = myJDFDoc.GetJDFRoot();
		JDFResourcePool myResPool = myRoot.GetResourcePool();
		JDFResource myPreview     = (JDFResource) myResPool.GetElement("Preview");
		JDFAttributeMap m;

		m.put("PreviewType", "Separation");

		myPreview = myPreview.GetPartition(m, JDFResource::PartUsage_Explicit);
		vWString vPartValues = myPreview.GetPartValues(JDFResource::PartIDKey_Separation);

		CPPUNIT_ASSERT_EQUAL( (WString)"Cyan",vPartValues[0] );
		CPPUNIT_ASSERT_EQUAL( (WString)"Magenta",vPartValues[1] );
		CPPUNIT_ASSERT_EQUAL( (WString)"Yellow",vPartValues[2] );
		CPPUNIT_ASSERT_EQUAL( (WString)"Black",vPartValues[3] );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testMatchesPart()
{
	try
	{
        CPPUNIT_ASSERT( JDFPart::matchesPart("PartVersion","DE EN FR","DE EN") );
        CPPUNIT_ASSERT( JDFPart::matchesPart("RunIndex","1 ~ 4","2 3") );
        CPPUNIT_ASSERT( JDFPart::matchesPart("RunIndex","1 ~ 3 5 ~ 6","3 5") );
        CPPUNIT_ASSERT( !JDFPart::matchesPart("RunIndex","1 ~ 3 6 ~ 8","3 ~ 6") );
        CPPUNIT_ASSERT( JDFPart::matchesPart("PartVersion","DE EN","DE") );
        CPPUNIT_ASSERT( !JDFPart::matchesPart("PartVersion","DE EN","DEU") );
        CPPUNIT_ASSERT( JDFPart::matchesPart("Run","R1","R1") );
        CPPUNIT_ASSERT( !JDFPart::matchesPart("Run","R1 R2","R1") );
        CPPUNIT_ASSERT( !JDFPart::matchesPart("Run","R2","R1") );
        CPPUNIT_ASSERT( !JDFPart::matchesPart("RunIndex","1 ~ 4","5") );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testOverlapPartMap()
{
	try
	{
		JDFAttributeMap m1=JDFAttributeMap("PartVersion","DE EN");
		m1.put("Run","r2");
		JDFAttributeMap m2=JDFAttributeMap("PartVersion","DE");
		CPPUNIT_ASSERT( JDFPart::overlapPartMap(m1,m2) );
		m2.put("Run","r2");
		CPPUNIT_ASSERT( JDFPart::overlapPartMap(m1,m2) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetLinks()
{
	try
	{
		JDFDoc doc=creatXMDoc();
        JDFNode n=doc.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput);
        JDFMedia m=xm.GetMedia();
		m=(JDFMedia) m.MakeRootResource().GetTarget();
		vElement v=m.GetLinks();
		CPPUNIT_ASSERT_EQUAL( 1,(int)v.size() );
		JDFResourceLink rl=n.linkResource(m,JDFResourceLink::Usage_Input,JDFNode::ProcessUsage_AnyInput);    
		v=m.GetLinks();
        CPPUNIT_ASSERT_EQUAL( 2,(int)v.size() );
		CPPUNIT_ASSERT( v.hasElement(rl) );

	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testGetCreatePartition2()
{
	try
	{
		JDFDoc doc =JDFDoc(0);
		JDFNode n=doc.GetJDFRoot();
		JDFResource media=n.addResource("Media", JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);

		JDFResource sig=media.AddPartition(JDFResource::PartIDKey_SignatureName, "sig1");
		sig=media.AddPartition(JDFResource::PartIDKey_SignatureName, "sig2");
		try
		{
			media.GetCreatePartition(JDFResource::PartIDKey_SheetName, "sh11",vWString("SignatureName SheetName"));
			CPPUNIT_FAIL( "no parallel" );
		}
		catch (JDFException&)
		{
			// expexted to throw exception
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceTest::testAgentNameAgentVersion()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();

		JDFMedia m = root.addResource(JDFResource::elm_Media, JDFResource::Class_Consumable, JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT( m.HasAttribute(JDFMedia::atr_AgentName) );
		CPPUNIT_ASSERT( m.HasAttribute(JDFMedia::atr_AgentVersion) );

		m.SetAgentName(WString::emptyStr);
		CPPUNIT_ASSERT( !m.HasAttribute(JDFMedia::atr_AgentName) );
		CPPUNIT_ASSERT( m.HasAttribute(JDFMedia::atr_AgentVersion) );

		m.SetAgentVersion(WString::emptyStr);
		CPPUNIT_ASSERT( !m.HasAttribute(JDFMedia::atr_AgentName) );
		CPPUNIT_ASSERT( !m.HasAttribute(JDFMedia::atr_AgentVersion) );

		m.SetAgentName("me");
		CPPUNIT_ASSERT_EQUAL( (WString)"me",m.GetAgentName() );
		CPPUNIT_ASSERT( !m.HasAttribute(JDFMedia::atr_AgentVersion) );
		
		m.SetAgentVersion("v64357");
		CPPUNIT_ASSERT_EQUAL( (WString)"me",m.GetAgentName() );
		CPPUNIT_ASSERT_EQUAL( (WString)"v64357",m.GetAgentVersion() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
