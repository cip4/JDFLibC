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
// created 08 Aug 2006
//
// JDFElementTest.cpp: implements CppUnit tests for JDFElement
//
//////////////////////////////////////////////////////////////////////

#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFElementTest.h"
#include "jdf/io/File.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFElementTest);

const WString sm_dirTestData = L"data\\";
const WString sm_dirTestTemp = L"temp\\";
const WString sm_dirTestSchema = L"schema\\";

void JDFElementTest::setUp()
{
	try	
	{
		JDF::PlatformUtils::Initialize();
	}
	catch (const JDFException& e)	
	{
		cerr << endl << e.what();
	}
}

void JDFElementTest::initializeTest()
{
	try	
	{
		// setup the fixture
		m_jdfDoc = new JDFDoc;
		m_jdfRoot = new JDFNode;
		m_kElement = new KElement;
		m_jdfElement = new JDFElement;
		WString xmlFile = "bookintent.jdf";

		// test jdf functions
		// ==================
		JDFParser p;
		p.Parse(sm_dirTestData+xmlFile,	false);

		*m_jdfDoc = p.GetDocument();

		CPPUNIT_ASSERT( !m_jdfDoc->isNull() );

		*m_jdfRoot = (JDFNode) m_jdfDoc->GetRoot();
		*m_kElement = m_jdfRoot->GetChildByTagName("Dimensions", WString::emptyStr, 0, mAttribute::emptyMap, false, true);
		*m_jdfElement = (JDFElement)*m_kElement;
	}
	catch (const std::exception& e)	
	{
		cerr << endl << e.what();
	}
}

void JDFElementTest::cleanupTest()
{
	delete m_jdfDoc;
	delete m_jdfRoot;
	delete m_kElement;
	delete m_jdfElement;
	m_jdfDoc = NULL;
	m_jdfRoot = NULL;
	m_kElement = NULL;
	m_jdfElement = NULL;
}

void JDFElementTest::testRemoveChild()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("ConventionalPrinting");
		JDFExposedMedia xmpl=(JDFExposedMedia)n.AppendMatchingResource("ExposedMedia",JDFNode::ProcessUsage_Plate,JDFNode::DefJDFNode);
		JDFExposedMedia xmpr=(JDFExposedMedia)n.AppendMatchingResource("ExposedMedia",JDFNode::ProcessUsage_Proof,JDFNode::DefJDFNode);
		JDFMedia m=xmpr.AppendMedia();
		CPPUNIT_ASSERT( !xmpr.GetMedia().isNull() );
		m.SetID("id1");
		KElement t1=n.GetTarget("id1","ID");
		m=(JDFMedia)m.MakeRootResource(WString::emptyStr,JDFElement::DefKElement,true).GetTarget();
		CPPUNIT_ASSERT_EQUAL( t1.ToString(),m.ToString() );
		CPPUNIT_ASSERT( !xmpr.GetMedia().isNull() );
		xmpl.RefElement(m);
		CPPUNIT_ASSERT( !xmpl.GetMedia().isNull() );
		JDFResourcePool rp=n.GetResourcePool();
		CPPUNIT_ASSERT( !rp.GetElement("Media").isNull() );
		xmpl.RemoveChild("Media",WString::emptyStr,0);
		CPPUNIT_ASSERT( xmpl.GetMedia().isNull() );
		CPPUNIT_ASSERT( !rp.GetElement("Media").isNull() );
		xmpr.RemoveChildren("Media",WString::emptyStr);
		CPPUNIT_ASSERT( xmpr.GetMedia().isNull() );
		CPPUNIT_ASSERT( !rp.GetElement("Media").isNull() );
	}
	catch (const JDFException& e)	
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testGetHRefs()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("ConventionalPrinting");
		JDFExposedMedia xmpl=(JDFExposedMedia)n.AppendMatchingResource("ExposedMedia",JDFNode::ProcessUsage_Plate,JDFNode());
		JDFExposedMedia xmpr=(JDFExposedMedia)n.AppendMatchingResource("ExposedMedia",JDFNode::ProcessUsage_Proof,JDFNode());
		JDFMedia m=xmpr.AppendMedia();
		CPPUNIT_ASSERT( !xmpr.GetMedia().isNull() );
		m.SetID("id1");
		KElement t1=n.GetTarget("id1","ID");
		m=(JDFMedia)m.MakeRootResource(WString::emptyStr,JDFElement::DefKElement,true).GetTarget();
		CPPUNIT_ASSERT_EQUAL( t1.ToString(),m.ToString() );
		CPPUNIT_ASSERT( n.GetHRefs(vWString::emptyvStr,true).contains("id1") );
		CPPUNIT_ASSERT( xmpr.GetHRefs(vWString::emptyvStr,true).contains("id1") );
		CPPUNIT_ASSERT( !xmpl.GetHRefs(vWString::emptyvStr,true).contains("id1") );
	}
	catch (const JDFException& e)	
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testDefaultVersion()
{
	try
	{
		JDFDoc doc(0);
		JDFNode n=doc.GetJDFRoot();
		CPPUNIT_ASSERT_EQUAL( JDFElement::Version_1_3,n.GetEnumVersion(true) );
		JDFElement::setDefaultJDFVersion(JDFElement::Version_1_2);
		n.SetType("ProcessGroup");
		CPPUNIT_ASSERT_EQUAL( JDFElement::Version_1_3,n.GetEnumVersion(true) );

		doc=JDFDoc(0);
		n=doc.GetJDFRoot();
		CPPUNIT_ASSERT_EQUAL( JDFElement::Version_1_2,n.GetEnumVersion(true) );
		n.SetType("ProcessGroup");
		CPPUNIT_ASSERT_EQUAL( JDFElement::Version_1_2,n.GetEnumVersion(true) );

		doc=JDFDoc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		CPPUNIT_ASSERT_EQUAL( JDFElement::VersionString(JDFElement::Version_1_2),jmf.GetVersion() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testEvaluateXY()
{
	try
	{
		JDFElement xyR;
		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_eq, 2,2,0,0) );
		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_eq, 1.9,2,0.1,0.1) );
		CPPUNIT_ASSERT( !xyR.XYRelation(JDFElement::XYRelation_eq, 1.9,2,0.0,0.15) );
		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_eq, 1.9,2,0.1,0.0) );

		CPPUNIT_ASSERT( !xyR.XYRelation(JDFElement::XYRelation_ne, 2,2,0,0) );
		CPPUNIT_ASSERT( !xyR.XYRelation(JDFElement::XYRelation_ne, 1.9,2,0.1,0.1) );
		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_ne, 1.9,2,0.0,0.15) );
		CPPUNIT_ASSERT( !xyR.XYRelation(JDFElement::XYRelation_ne, 1.9,2,0.1,0.0) );

		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_gt, 3,2,0,0) );
		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_gt, 1.9,2,0.2,0.2) );
		CPPUNIT_ASSERT( !xyR.XYRelation(JDFElement::XYRelation_gt, 2.00,2,0.0,0.0) );
		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_gt, 1.95,2,0.1,0.0) );

		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_lt, 1.9,2,0.0,0.0) );

		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_le, 1.9,2.0,0.0,0.0) );
		CPPUNIT_ASSERT( xyR.XYRelation(JDFElement::XYRelation_le, 2.0,2,0.0,0.0) );
		CPPUNIT_ASSERT( !xyR.XYRelation(JDFElement::XYRelation_le, 3.0,2,0.0,0.0) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testIncludesMatchingAttribute()
{
	try
	{
		initializeTest();

		CPPUNIT_ASSERT( m_jdfElement->IncludesMatchingAttribute("Range", "600 800", JDFElement::AttributeType_XYPairRangeList) );
		CPPUNIT_ASSERT( !m_jdfElement->IncludesMatchingAttribute("Range", "500 700", JDFElement::AttributeType_XYPairRangeList) );

		JDFDoc d(0);
		JDFElement e=d.GetJDFRoot();
		e.SetAttribute("abc","a b c");
		CPPUNIT_ASSERT( e.IncludesMatchingAttribute("abc","a",JDFElement::AttributeType_NMTOKENS) );
		CPPUNIT_ASSERT( e.IncludesMatchingAttribute("abc","b",JDFElement::AttributeType_NMTOKENS) );
		CPPUNIT_ASSERT( e.IncludesMatchingAttribute("abc","c",JDFElement::AttributeType_NMTOKENS) );
		CPPUNIT_ASSERT( !e.IncludesMatchingAttribute("abc","d",JDFElement::AttributeType_NMTOKENS) );
		e.SetAttribute("intlist","-1 3 5");
		CPPUNIT_ASSERT( e.IncludesMatchingAttribute("intlist","-1",JDFElement::AttributeType_IntegerList) );
		CPPUNIT_ASSERT( e.IncludesMatchingAttribute("intlist","3",JDFElement::AttributeType_IntegerList) );
		CPPUNIT_ASSERT( e.IncludesMatchingAttribute("intlist","5",JDFElement::AttributeType_IntegerList) );
		CPPUNIT_ASSERT( !e.IncludesMatchingAttribute("intlist","4",JDFElement::AttributeType_IntegerList) );
		CPPUNIT_ASSERT( !e.IncludesMatchingAttribute("intlist","8",JDFElement::AttributeType_IntegerList) );

		cleanupTest();
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testGetChildElementVector()
{
	try
	{
		initializeTest();

		vElement velem = m_jdfRoot->GetChildElementVector(WString::star, WString::emptyStr, mAttribute::emptyMap, true, 0, false);
		KElement elem = (KElement)velem.elementAt(0);
		CPPUNIT_ASSERT( 5 == velem.size() );
		CPPUNIT_ASSERT_EQUAL( WString("AuditPool"), elem.GetNodeName() );

		cleanupTest();
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}


void JDFElementTest::testGetParentJDFNode()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("ProcessGroup");
		JDFNode n2=n.AddJDFNode(JDFNode::Type_Scanning);
		CPPUNIT_ASSERT_EQUAL( n,n2.GetParentJDF() );
		CPPUNIT_ASSERT( n.GetParentJDF().isNull() );
		JDFAuditPool ap=n.GetCreateAuditPool();
		CPPUNIT_ASSERT_EQUAL( n,ap.GetParentJDF() );
		ap=n2.GetCreateAuditPool();
		CPPUNIT_ASSERT_EQUAL( n2,ap.GetParentJDF() );
		CPPUNIT_ASSERT_EQUAL( n2,ap.AddCreated("me",n2).GetParentJDF() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
void JDFElementTest::testGetElementByID()
{
	try
	{
		initializeTest();

		KElement kelem = m_jdfRoot->GetChildWithAttribute(WString::star,"ID", WString::star,"n0006", 0, true);
		CPPUNIT_ASSERT( !kelem.isNull() );
		WString strAtrib = kelem.GetAttribute("ID", WString::emptyStr, WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( WString("n0006"),strAtrib );

		kelem = m_jdfRoot->GetTarget("n0006", "ID");
		CPPUNIT_ASSERT( !kelem.isNull() );
		strAtrib = kelem.GetAttribute("ID", WString::emptyStr, WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( WString("n0006"), strAtrib );

		kelem = m_jdfRoot->GetTarget("198", "Preferred");
		CPPUNIT_ASSERT( !kelem.isNull() );
		strAtrib = kelem.GetAttribute("Preferred", WString::emptyStr, WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( WString("198"), strAtrib );

		// GetChildWithAttribute does only find direct children but no deep children
		kelem = m_jdfRoot->GetChildWithAttribute(WString::star,"Preferred", WString::star,"198", 0, true);
		CPPUNIT_ASSERT( kelem.isNull() );

		cleanupTest();
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testInheritedVersionInfo()
{
	try
	{
		JDFDoc doc(0);
		JDFNode node = doc.GetJDFRoot();
		node.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		node.SetType("ProcessGroup");
		node=node.AddJDFNode(JDFNode::Type_Scanning);
		JDFNodeInfo ni=node.AppendNodeInfo();
		CPPUNIT_ASSERT( ni.HasAttribute(JDFStrings::atr_Class) );
		CPPUNIT_ASSERT_EQUAL( JDFElement::VersionString(JDFElement::Version_1_3), ni.GetVersion(true) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testMatchesPath()
{
	try
	{
		JDFDoc doc(0);
		JDFNode node = doc.GetJDFRoot();
		node.SetType("Product");
		node.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		JDFNodeInfo ni=node.AppendNodeInfo();
		ni=(JDFNodeInfo) ni.AddPartition(JDFResource::PartIDKey_Run,"R1");
		JDFContact c=(JDFContact)node.addResource(JDFStrings::elm_Contact, JDFResource::Class_Unknown, JDFResourceLink::Usage_Unknown, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		ni.RefElement(c);
		JDFComChannel cc=(JDFComChannel)node.addResource(JDFStrings::elm_ComChannel, JDFResource::Class_Unknown, JDFResourceLink::Usage_Unknown, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		c.RefElement(cc);
		CPPUNIT_ASSERT_EQUAL( c, ni.GetContact() );
		CPPUNIT_ASSERT( ni.HasChildElement(JDFStrings::elm_Contact,WString::emptyStr) );
		JDFRefElement re=(JDFRefElement)ni.GetElement("ContactRef");          
		CPPUNIT_ASSERT_EQUAL( c.ToString(), re.GetTarget().ToString() );
		CPPUNIT_ASSERT_EQUAL( cc.ToString(), c.GetComChannel(0).ToString() );
		CPPUNIT_ASSERT( c.HasChildElement(JDFStrings::elm_ComChannel, WString::emptyStr) );
		JDFNode n2=node.AddProduct();
		JDFNodeInfo ni2=n2.AppendNodeInfo();
		ni2.RefElement(c);
		cc.matchesPath("ResourcePool/NodeInfo/Contact/ComChannel",true);
		CPPUNIT_ASSERT( c.matchesPath("ResourcePool/NodeInfo/Contact",true) );
		CPPUNIT_ASSERT( cc.matchesPath("ResourcePool/NodeInfo/Contact/ComChannel",true) );
		CPPUNIT_ASSERT( cc.matchesPath("JDF/ResourcePool/NodeInfo/Contact/ComChannel",true) );
		CPPUNIT_ASSERT( cc.matchesPath("/JDF/ResourcePool/NodeInfo/Contact/ComChannel",true) );
		CPPUNIT_ASSERT( cc.matchesPath("JDF/JDF/ResourcePool/NodeInfo/Contact/ComChannel",true) );
		CPPUNIT_ASSERT( cc.matchesPath("/JDF/JDF/ResourcePool/NodeInfo/Contact/ComChannel",true) );
		CPPUNIT_ASSERT( !cc.matchesPath("JDF/JDF/JDF/ResourcePool/NodeInfo/Contact/ComChannel",true) );
		CPPUNIT_ASSERT( !cc.matchesPath("JDF/JDF/JDF/ResourcePool/NodeInfo/Contact/ComChannel",true) );
		CPPUNIT_ASSERT( !c.matchesPath("ResourcePool/NodeInfo/Contact/ComChannel",true) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testRefElement()
{
	try
	{
		JDFDoc doc(0);
		JDFNode node = doc.GetJDFRoot();
		node.SetType("Product");
		node.SetVersion(JDFElement::VersionString(JDFElement::Version_1_2));
		JDFNodeInfo ni=node.AppendNodeInfo();
		ni.AppendElement("foo:bar","www.foo.com"); // want a non jdf ns element to see if any class casts occur
		JDFContact c=(JDFContact)node.addResource(JDFStrings::elm_Contact, JDFResource::Class_Parameter, JDFResourceLink::Usage_Unknown, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		vWString vCTypes;
		vCTypes.add("Customer");
		c.SetContactTypes(vCTypes);

		ni.RefElement(c);
		JDFComChannel cc=(JDFComChannel)node.addResource(JDFStrings::elm_ComChannel, JDFResource::Class_Parameter, JDFResourceLink::Usage_Unknown, WString::emptyStr, JDFNode::DefJDFNode, WString::emptyStr, JDFResource::DefJDFResource);
		c.RefElement(cc);

		CPPUNIT_ASSERT_EQUAL( c.ToString(), ni.GetChildWithMatchingAttribute(JDFStrings::elm_Contact,"ContactTypes",WString::emptyStr,"Customer",0,true,JDFElement::AttributeType_Any).ToString() );
		CPPUNIT_ASSERT_EQUAL( c.ToString(), ni.GetParentJDF().GetChildWithAttribute(JDFStrings::elm_Contact,"ContactTypes",WString::emptyStr,"Customer",0,false).ToString() );

		CPPUNIT_ASSERT_EQUAL( c,ni.GetContact() );
		CPPUNIT_ASSERT( ni.HasChildElement(JDFStrings::elm_Contact, WString::emptyStr) );
		JDFRefElement re=(JDFRefElement)ni.GetElement("ContactRef");
		CPPUNIT_ASSERT_EQUAL( c.ToString(), re.GetTarget().ToString() );
		CPPUNIT_ASSERT_EQUAL( cc.ToString(), c.GetComChannel().ToString() );
		CPPUNIT_ASSERT( c.HasChildElement(JDFStrings::elm_ComChannel, WString::emptyStr) );
		JDFNode n2=node.AddProduct();
		JDFNodeInfo ni2=n2.AppendNodeInfo();
		ni2.RefElement(c);
		CPPUNIT_ASSERT( c.matchesPath("NodeInfo/Contact",true) );
		CPPUNIT_ASSERT( cc.matchesPath("NodeInfo/Contact/ComChannel",true) );  // follow refs in matchespath
		CPPUNIT_ASSERT( !c.matchesPath("NodeInfo/Contact/ComChannel",true) );  // follow refs in matchespath

		CPPUNIT_ASSERT_EQUAL( c,ni2.GetContact() ); // contact 2
		CPPUNIT_ASSERT( ni2.HasChildElement(JDFNode::elm_Contact) );           //has refelement 2
		re=(JDFRefElement)ni2.GetElement("ContactRef");
		CPPUNIT_ASSERT_EQUAL( c.ToString(),re.GetTarget().ToString() );        //refelement ok 2

		ni2.InlineRefElements(WString::emptyStr,WString::emptyStr,true);
		CPPUNIT_ASSERT( ni2.GetElement("ContactRef").isNull() );               // get ref post inline
		CPPUNIT_ASSERT( !node.GetResourcePool().GetElement("Contact").isNull() ); //refElement has been removed
		CPPUNIT_ASSERT( ni2.HasChildElement(JDFNode::elm_Contact) );           // has element 3
		c=ni2.GetContact();
		re=(JDFRefElement)c.GetElement("ComChannelRef");
		CPPUNIT_ASSERT_EQUAL( cc.ToString(),re.GetTarget().ToString() );       // refelement ok 2
		ni2.InlineRefElements();
		CPPUNIT_ASSERT( ni2.GetElement("ComChannelRef").isNull() );            // get ref post inline 2
		CPPUNIT_ASSERT( c.HasChildElement(JDFNode::elm_ComChannel) );          // has element 4

		ni.InlineRefElements(WString::emptyStr,WString::emptyStr,true);
		CPPUNIT_ASSERT( ni.GetElement("ContactRef").isNull() );                // get ref post inline
		CPPUNIT_ASSERT( node.GetResourcePool().GetElement("Contact").isNull() ); //refElement has been removed
		CPPUNIT_ASSERT( ni.HasChildElement(JDFNode::elm_Contact) );            // haselement 3

		c=ni.GetContact();
		c.MakeRootResource();
		re=(JDFRefElement)ni.GetElement("ContactRef");
		re.DeleteRef();
		CPPUNIT_ASSERT( c.GetElement("ContactRef").isNull() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testIsValid()
{
	try
	{
		File testData(sm_dirTestData + "SampleFiles");
		CPPUNIT_ASSERT ( testData.isDirectory() );		
		std::list<JDF::File> fList = testData.listFiles();
		JDFParser p;
		JDFParser p2;
		WString schemaLocation = sm_dirTestSchema + "JDF.xsd";

		typedef list<JDF::File>::const_iterator FI;
		for ( FI i = fList.begin(); i != fList.end(); ++i) 
		{
			const JDF::File& f = *i;
			JDF::File file = f;			
			// skip directories in CVS environments && skip schema files
			if ( !file.isDirectory() && !file.getPath().endsWith(".xsd") )
			{
				cout << endl << "  -> parsing: " + file.getPath();

				p.Parse( file, false );
				JDFDoc jdfDoc = p.GetDocument();
				CPPUNIT_ASSERT( !jdfDoc.isNull() );
				KElement e = jdfDoc.GetRoot();
				CPPUNIT_ASSERT( e.IsValid(KElement::ValidationLevel_RecursiveComplete) );

				// now with schema validation
				p2.Parse( file, false, true, true, NULL, schemaLocation );
				jdfDoc = p2.GetDocument();
				CPPUNIT_ASSERT (!jdfDoc.isNull() );
				e = jdfDoc.GetRoot();
				CPPUNIT_ASSERT( e.IsValid(KElement::ValidationLevel_RecursiveComplete) );
				cout << " (ok)";
			}
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testIsInvalid()
{
	try
	{
		File testData(sm_dirTestData + "BadSampleFiles");
		CPPUNIT_ASSERT ( testData.isDirectory() );		
		std::list<File> fList = testData.listFiles();
		JDFParser p;
		JDFParser p2;
		WString schemaLocation = sm_dirTestSchema + "JDF.xsd";

		typedef list<File>::const_iterator FI;
		for ( FI i = fList.begin(); i != fList.end(); ++i) 
		{			
			const File& f = *i;
			File file = f;
			// skip directories in CVS environments && skip schema files
			if ( !file.isDirectory() && !file.getPath().endsWith(".xsd") )
			{
				cout << endl << "  -> parsing: " + file.getPath();

				p.Parse(file, false);
				JDFDoc jdfDoc = p.GetDocument();
				CPPUNIT_ASSERT( !jdfDoc.isNull() );
				KElement e = jdfDoc.GetRoot();
				CPPUNIT_ASSERT( !e.IsValid(KElement::ValidationLevel_RecursiveComplete) );

				// now with schema validation
				p2.Parse( file, true, true, true, NULL, schemaLocation );
				jdfDoc = p2.GetDocument();
				CPPUNIT_ASSERT (!jdfDoc.isNull() );
				e = jdfDoc.GetRoot();
				CPPUNIT_ASSERT( !e.IsValid(KElement::ValidationLevel_RecursiveComplete) );
			}
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}


void JDFElementTest::testStatusEquals()
{
	// test if the auto classes implement the correct status

	try
	{
		// compare EnumNodeStatus
		JDFAuditPool myAuditPool;

		JDFDoc jdfDoc(0);

		JDFNode jdfRoot = (JDFNode)jdfDoc.GetRoot();
		CPPUNIT_ASSERT( !jdfRoot.isNull() );

		JDFAncestor ancestor = jdfRoot.AppendAncestorPool().AppendAncestor();
		ancestor.SetStatus(JDFElement::Status_Completed);

		myAuditPool = jdfRoot.GetCreateAuditPool();
		JDFPhaseTime phaseTime = myAuditPool.AddPhaseTime(JDFPhaseTime::Status_Completed,WString::emptyStr,vmAttribute::emptyvMap);
		JDFSpawned spawned = myAuditPool.AddSpawned(jdfRoot, vWString::emptyvStr,vWString::emptyvStr,WString::emptyStr,vmAttribute::emptyvMap);
		spawned.SetStatus(JDFElement::Status_Completed);

		CPPUNIT_ASSERT_EQUAL( phaseTime.GetStatus(), spawned.GetStatus() );
		CPPUNIT_ASSERT_EQUAL( ancestor.GetStatus(), spawned.GetStatus() );

		JDFDoc jmfDoc(1);

		JDFJMF jmfRoot = jmfDoc.GetJMFRoot();
		CPPUNIT_ASSERT( !jmfRoot.isNull() );

		JDFAcknowledge acknowledge = jmfRoot.AppendAcknowledge(JDFMessage::Type_Unknown);
		acknowledge.SetType("PipePush");    // Type is required and its existance is validated for messages
		JDFJobPhase jobPhase = acknowledge.AppendJobPhase();
		jobPhase.SetStatus(JDFNode::JDFElement::Status_Completed);

		JDFMessage message = jmfRoot.appendMessageElement(JDFMessage::Family_Command, JDFMessage::Type_Unknown);
		message.SetType("PipePush");    // Type is required and its existance is validated for messages
		JDFPipeParams pipeParams = message.AppendPipeParams();
		pipeParams.SetStatus(JDFElement::Status_Completed);

		CPPUNIT_ASSERT_EQUAL( pipeParams.GetStatus(), jobPhase.GetStatus() );
		CPPUNIT_ASSERT_EQUAL( pipeParams.GetStatus(), spawned.GetStatus() );

		// compare EnumResStatus
		XMLDoc responseDoc(JDFStrings::elm_Response);
		JDFResponse responseRoot = (JDFResponse)responseDoc.GetRoot();
		CPPUNIT_ASSERT( !responseRoot.isNull() );

		responseRoot.SetType(JDFStrings::elm_Resource);
		JDFResourceInfo resInfo = responseRoot.AppendResourceInfo();
		resInfo.SetStatus(JDFResource::Status_Available);

		XMLDoc commandDoc(JDFStrings::elm_Command);
		JDFCommand commandRoot = (JDFCommand) commandDoc.GetRoot();
		CPPUNIT_ASSERT( !commandRoot.isNull() );

		commandRoot.SetType(JDFStrings::elm_Resource);
		JDFResourceCmdParams resCmdParams = commandRoot.AppendResourceCmdParams();

		// check EnumQueueStatus
		XMLDoc queueDoc(JDFStrings::elm_Queue);       
		JDFQueue queueRoot = (JDFQueue) queueDoc.GetRoot();
		CPPUNIT_ASSERT( !queueRoot.isNull() );

		queueRoot.SetStatus(JDFAutoQueue::Status_Running);

		// check EnumQueueEntryStatus
		JDFQueueEntry queueEntry = queueRoot.AppendQueueEntry();
		queueEntry.SetStatus(JDFAutoQueueEntry::Status_Running);
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testAppendElement()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		KElement r=d.GetRoot();
		KElement e=r.AppendElement("e");
		CPPUNIT_ASSERT_EQUAL( JDFElement::GetSchemaURL(1,3),e.GetNamespaceURI() );
		KElement foo=e.AppendElement("pt:foo", "www.pt.com");
		CPPUNIT_ASSERT_EQUAL( (WString)"www.pt.com",foo.GetNamespaceURI() );
		KElement bar=foo.AppendElement("bar");
		CPPUNIT_ASSERT( !foo.GetNamespaceURI().empty() );
		KElement foo2=bar.AppendElement("pt:foo", "www.pt.com");
		CPPUNIT_ASSERT_EQUAL( (WString)"www.pt.com",foo2.GetNamespaceURI() );  
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testIsResourceLinkStatic()
{
	try
	{
		// setup the fixture
        WString xmlFile = "bookintent.jdf";
        
        // test jdf functions
        // ==================
		JDFParser p;
		p.Parse(sm_dirTestData+xmlFile,false);
		JDFDoc jdfDoc = p.GetDocument();
		CPPUNIT_ASSERT( !jdfDoc.isNull() );

		JDFNode root = (JDFNode) jdfDoc.GetRoot();
		JDFElement elem = (JDFElement)root.GetChildByTagName("Dimensions", WString::emptyStr, 0, mAttribute::emptyMap, false, true);

		elem = (JDFElement)root.GetChildByTagName("Dimensions", WString::emptyStr, 0, mAttribute::emptyMap, false, true);
		CPPUNIT_ASSERT( !elem.IsResourceLink() );
		elem = (JDFElement)root.GetChildByTagName("ComponentLink", WString::emptyStr, 0, mAttribute::emptyMap, false, true);
		CPPUNIT_ASSERT( elem.IsResourceLink() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testIsResourceStatic()
{
	try
	{
		// setup the fixture
        WString xmlFile = "bookintent.jdf";
        
        // test jdf functions
        // ==================
		JDFParser p;
		p.Parse(sm_dirTestData+xmlFile,false);
		JDFDoc jdfDoc = p.GetDocument();
		CPPUNIT_ASSERT( !jdfDoc.isNull() );

		JDFNode root = (JDFNode) jdfDoc.GetRoot();
		JDFElement elem = (JDFElement)root.GetChildByTagName("ComponentLink", WString::emptyStr, 0, mAttribute::emptyMap, false, true);
		CPPUNIT_ASSERT( !elem.IsResource() );
        elem = (JDFElement)root.GetChildByTagName("SizeIntent", WString::emptyStr, 0, mAttribute::emptyMap, false, true);
        CPPUNIT_ASSERT( elem.IsResource() );
        elem = (JDFElement)root.GetChildByTagName("Dimensions", WString::emptyStr, 0, mAttribute::emptyMap, false, true);
        CPPUNIT_ASSERT( !elem.IsResource() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFElementTest::testNameSpaceElement()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType("foo:bar");
		root.AddNameSpace("foo", "www.foo.com");
		JDFResource r=root.addResource("foo:res", JDFResource::Class_Parameter, JDFResourceLink::Usage_Input);
		JDFResourceLink rl=root.getLink(r, JDFResourceLink::Usage_Input);
		rl.SetPartMap(JDFAttributeMap("Side","Front"));
		CPPUNIT_ASSERT_EQUAL( -1,rl.ToString().indexOf("xmlns=\"\"") );
		CPPUNIT_ASSERT_EQUAL( -1,rl.GetPart().ToString().indexOf("xmlns=\"\"") );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
