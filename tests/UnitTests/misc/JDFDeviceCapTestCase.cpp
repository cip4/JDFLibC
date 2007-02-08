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
// created before 21 Jul 2006
//
// JDFDeviceCapTestCase.cpp: implements CppUnit test cases for JDFDevCap
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFTestPool.h"
#include "jdf/wrapper/JDFActionPool.h"
#include "jdf/wrappercore/vElement.h"
#include "jdf/wrappercore/JDFParser.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFDeviceCapTestCase.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFDeviceCapTestCase);

const WString sm_dirTestTemp = L".\\temp\\";
const WString sm_dirTestData = L"data\\";


void JDFDeviceCapTestCase::setUp()
{
	try	
	{
		JDF::PlatformUtils::Initialize();
	}
	catch (const JDF::Exception& e)	
	{
		e.getMessage();
	}
	doc.SetRoot("DeviceCap", WString::emptyStr);
	
	devicecap = doc.GetRoot();
	devicecap.SetCombinedMethod(JDFAutoDeviceCap::CombinedMethod_None);
	devicecap.SetTypeExpression( "fnarf" );

	JDFDevCapPool dcp = devicecap.AppendDevCapPool();
	JDFDevCaps dcs = devicecap.AppendDevCaps();
	dcs.SetContext(JDFAutoDevCaps::Context_Element);
	dcs.SetName( "AuditPool" );
	dcs.SetRequired(true);
	JDFDevCap dc = dcp.AppendDevCap();
	dc.SetID("dc_AuditPool");
	dcs.SetDevCapRef( "dc_AuditPool" );
	dc=dc.AppendDevCap();
	dc.SetName("Created");
	dc.SetID("dc_Created");

	dcs=devicecap.AppendDevCaps();
	dcs.SetContext(JDFAutoDevCaps::Context_Element);
	dcs.SetName("AncestorPool");
	dc=dcs.AppendDevCap();
	dc.SetID("dc_AncestorPool");
	JDFDevCap dc2=dc.AppendDevCap();
	dc2.SetID("dc_Ancestor");
	dc2.SetName("Ancestor");

	dcs=devicecap.AppendDevCaps();
	dcs.SetContext(JDFAutoDevCaps::Context_Resource);
	dcs.SetName("Layout");
	dcs.SetLinkUsage(JDFAutoDevCaps::LinkUsage_Input);
	dc=dcs.AppendDevCap();
	dc.SetID("dc_Layout");
	dc.SetMinOccurs(1);
	JDFDevCap coDC=dc.AppendDevCap();
	coDC.SetName(JDFStrings::elm_ContentObject);
	coDC.SetMinOccurs(2);
	JDFNumberState st=coDC.AppendNumberState(JDFStrings::atr_CTM);
	st.SetRequired(true);
	st.SetListType(JDFStateBase::ListType_List);
	st.SetMinOccurs(6);
	st.SetMaxOccurs(6);
	st.SetHasDefault(true);
	st.SetAttribute("DefaultValue", "1 0 0 1 1 1");

	dcs=devicecap.AppendDevCaps();
	dcs.SetContext(JDFAutoDevCaps::Context_Link);
	dcs.SetLinkUsage(JDFAutoDevCaps::LinkUsage_Input);
	dcs.SetName("Layout");
	dc=dcs.AppendDevCap();
	dc.SetID("dc_LayoutLink");

	dcs=devicecap.AppendDevCaps();
	dcs.SetContext(JDFAutoDevCaps::Context_Element);
	dcs.SetName("JDF");
	dc=dcp.AppendDevCap();
	dc.SetID("dc_JDF");	
	dcs.SetDevCapRef("dc_JDF");
	/* parsing the file makes debugging in AtomicTest easier*/
	//doc.Write2File(sm_dirTestTemp + "devCapDefaults.jdf");
}

void JDFDeviceCapTestCase::testAction()
{
	XMLDoc d(JDFStrings::elm_DeviceCap);
	JDFDeviceCap dc = d.GetRoot();
	JDFTestPool tp = dc.AppendTestPool();
	
	JDFTest test = tp.appendTest();
	JDFActionPool ap = dc.AppendActionPool();
	JDFAction a = ap.AppendAction();
	a.setTest(test);
	a.getTest();
	CPPUNIT_ASSERT_EQUAL(test, a.getTest());
	CPPUNIT_ASSERT(a.HasAttribute("TestRef"));
}

void JDFDeviceCapTestCase::testGetDevCapsByName()
{
	JDFDevCaps dcs = (JDFDevCaps)devicecap.getDevCapsByName("AuditPool", JDFAutoDevCaps::Context_Unknown, 
		JDFAutoDevCaps::LinkUsage_Unknown, WString::emptyStr, 0);
	CPPUNIT_ASSERT_MESSAGE( "error  in AuditPool test", !dcs.isNull() );
	CPPUNIT_ASSERT_EQUAL( WString("AuditPool"), dcs.GetName() );
	
	dcs=devicecap.getDevCapsByName("Layout", JDFAutoDevCaps::Context_Resource, 
		JDFAutoDevCaps::LinkUsage_Unknown, WString::emptyStr, 0);;
	CPPUNIT_ASSERT_MESSAGE( "error  in dc_Layout test", !dcs.isNull() );
	CPPUNIT_ASSERT_EQUAL( WString("Layout"), dcs.GetName() );
	CPPUNIT_ASSERT_EQUAL( WString("dc_Layout"), dcs.GetDevCap().GetID() );
	
	dcs=devicecap.getDevCapsByName("Layout", JDFAutoDevCaps::Context_Link, 
		JDFAutoDevCaps::LinkUsage_Unknown, WString::emptyStr, 0);
	CPPUNIT_ASSERT_MESSAGE( "error  in dc_LayoutLink test", !dcs.isNull() );
	CPPUNIT_ASSERT_EQUAL( WString("Layout"), dcs.GetName() );
	CPPUNIT_ASSERT_EQUAL( WString("dc_LayoutLink"), dcs.getDevCap().GetID() );

	dcs = devicecap.getDevCapsByName("Layout", JDFAutoDevCaps::Context_Element, 
		JDFAutoDevCaps::LinkUsage_Unknown, WString::emptyStr, 0);
	CPPUNIT_ASSERT( dcs.isNull() );
}

void JDFDeviceCapTestCase::testDevCapsMinOccurs()
{
	JDFDevCaps dcs=devicecap.getDevCapsByName("AuditPool", JDFAutoDevCaps::Context_Unknown, 
		JDFAutoDevCaps::LinkUsage_Unknown, WString::emptyStr, 0);
	CPPUNIT_ASSERT_EQUAL( 1, dcs.getMinOccurs() );
}

void JDFDeviceCapTestCase::testDevCapsMaxOccurs()
{
	JDFDevCaps dcs=devicecap.getDevCapsByName("AuditPool", JDFAutoDevCaps::Context_Unknown, 
		JDFAutoDevCaps::LinkUsage_Unknown, WString::emptyStr, 0);
	CPPUNIT_ASSERT_EQUAL( 1, dcs.getMaxOccurs() );
}

void JDFDeviceCapTestCase::testLogic()
{
	XMLDoc d( JDF::JDFStrings::elm_DeviceCap );
	JDFDeviceCap dc=d.GetRoot();
	dc.AppendDevCapPool();

	JDFTestPool tp=dc.AppendTestPool();
	JDFTest test = tp.appendTest();

	test.AppendElement(JDF::JDFElement::elm_and, WString::emptyStr);
	JDFActionPool ap=dc.AppendActionPool();
	JDFAction a=ap.AppendAction();
	a.setTest(test);
}

void JDFDeviceCapTestCase::testDeviceCapIsValid()
{
	try
	{
		JDFParser p;
		WString docDevCap = "DevCaps_Product_MISPrepress_ICS_Minimal.jdf";
		
		p.Parse( sm_dirTestData + docDevCap, false, false, false, NULL, WString::emptyStr, 0, 42 );
		JDFDoc jmfDevCap = p.GetDocument();
		
		CPPUNIT_ASSERT_MESSAGE( "Parse of file failed", !jmfDevCap.isNull() );

		JDFJMF jmfRoot = JDFJMF();
		if ( !jmfDevCap.isNull() )
		{
			jmfRoot = jmfDevCap.GetJMFRoot();
			CPPUNIT_ASSERT_MESSAGE ("jmfRoot == null, can't start the test", !jmfRoot.isNull() );

			if ( !jmfRoot.isNull() )
			{
				JDFDeviceCap deviceCap = jmfRoot.GetChildByTagName((WString)"DeviceCap", "", 0, JDF::mAttribute::emptyMap, false, true);
				CPPUNIT_ASSERT( deviceCap.IsValid(KElement::ValidationLevel_Incomplete) );
			}
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDeviceCapTestCase::testGetExecutableJDF()
{
	try
	{
		WString docTest = L"MISPrepress_ICS_Minimal.jdf";
		WString docDevCap = L"DevCaps_Product_MISPrepress_ICS_Minimal.jdf";

		// parse input file
		JDFParser p;
		p.Parse( sm_dirTestData+docDevCap, false, false, false, NULL, WString::emptyStr, 0, 42 );
		JDFDoc jmfDevCap = p.GetDocument();
		JDFJMF jmfRoot = JDFJMF();
		CPPUNIT_ASSERT_MESSAGE( "Parse of inFile failed", !jmfDevCap.isNull() );
		if ( !jmfDevCap.isNull() )
		{
			jmfRoot = jmfDevCap.GetJMFRoot();
			CPPUNIT_ASSERT_MESSAGE( "jmfRoot == null, can't start the test", !jmfRoot.isNull() );
			if ( !jmfRoot.isNull() )
			{
				XMLDoc docOutDevCap = jmfRoot.GetOwnerDocument();
				docOutDevCap.Write2File("_" + docTest);
			}
		}

		JDFParser p2;	
		p2.Parse(sm_dirTestData + docTest, false, true, false, NULL, WString::emptyStr, 0, 42);
		JDFDoc jdfTest = p2.GetDocument();
		JDFNode jdfRoot;
		CPPUNIT_ASSERT_MESSAGE( "Parse of inFile failed", !jdfTest.isNull() );
		if ( !jdfTest.isNull() )
		{
			jdfRoot = jdfTest.GetJDFRoot();
			CPPUNIT_ASSERT_MESSAGE( "jdfRoot is null", !jdfRoot.isNull() );
			if ( !jdfRoot.isNull() )
			{
				XMLDoc docOutTest = jdfRoot.GetOwnerDocument();
				docOutTest.Write2File( "_" + docTest );
			}
		}
		if ( !jdfRoot.isNull() )
		{
			JDFDeviceCap deviceCap = jmfRoot.GetChildByTagName((WString)"DeviceCap", "", 0, JDF::mAttribute::emptyMap, false, true);
			JDFElement::EnumFitsValue testLists =JDFElement::FitsValue_Allowed;
			JDFElement::EnumValidationLevel level = KElement::ValidationLevel_Complete;
			VElement vExecNodes = devicecap.GetExecutableJDF(jdfRoot, testLists, level);
			if ( vExecNodes.empty() )
			{
				cout << endl << "(" << docDevCap + ": found no matching JDFNode)";
			}
			else
			{
				for (int n = 0; n < vExecNodes.size(); n++)
				{
					cout << vExecNodes.elementAt(n);
				}
			}

				XMLDoc testResult = deviceCap.GetBadJDFInfo(jdfRoot, testLists, level);
				if ( testResult.isNull() )
				{
					testResult.Write2File(sm_dirTestTemp + L"_BugReport.xml");
				}
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDeviceCapTestCase::testMatchesType()
{
	try
	{
		JDFDoc d(0);
		JDFNode n = d.GetJDFRoot();
		n.SetType("bar");
		CPPUNIT_ASSERT( !devicecap.matchesType(n, true) );
		CPPUNIT_ASSERT( !devicecap.matchesType(n, false) );

		n.SetType("fnarf");
		CPPUNIT_ASSERT( devicecap.matchesType(n, true) );
		CPPUNIT_ASSERT( devicecap.matchesType(n, false) );

		devicecap.SetCombinedMethod(JDFAutoDeviceCap::CombinedMethod_ProcessGroup);
		n.SetType("ProcessGroup");
		JDFNode n2=n.AddJDFNode(JDFNode::Type_Bending);
		n2.SetType("fnarf");
		CPPUNIT_ASSERT( devicecap.matchesType(n, true) );
		CPPUNIT_ASSERT( devicecap.matchesType(n, false) );
		CPPUNIT_ASSERT_MESSAGE( "method pg for local individual process", !devicecap.matchesType(n2, true) );
		CPPUNIT_ASSERT( !devicecap.matchesType(n2, false) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDeviceCapTestCase::testSetDefaultsFromCaps()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType((WString)"fnarf");
		devicecap.setDefaultsFromCaps(n, true);
		CPPUNIT_ASSERT( !n.getLinks((WString)"Layout", JDF::JDFAttributeMap::emptyMap, WString::emptyStr).empty() );
		JDFLayout lo = n.GetResourcePool().GetPoolChild(0, (WString)"Layout", JDFAttributeMap::emptyMap, WString::emptyStr);
		JDFContentObject contentObject=lo.GetContentObject(0);
		CPPUNIT_ASSERT( !contentObject.isNull() );
		CPPUNIT_ASSERT_EQUAL( JDFMatrix((WString)"1 0 0 1 1 1"), contentObject.GetCTM() );
		CPPUNIT_ASSERT( !lo.GetContentObject(1).isNull() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDeviceCapTestCase::testGetNamePathVector()
{
	try
	{
		{
			JDFDevCap dc = (JDFDevCap)devicecap.GetChildWithAttribute(WString::emptyStr, KElementStrings::atr_ID, WString::emptyStr, 
				(WString)"dc_Ancestor", 0, false);
			vWString v=dc.getNamePathVector(true);
			CPPUNIT_ASSERT_EQUAL( 1, (int)v.size() );
			CPPUNIT_ASSERT_EQUAL( (WString)"JDF/AncestorPool/Ancestor",v[0] );
		}

		{
			JDFDevCap dc = (JDFDevCap)devicecap.GetChildWithAttribute(WString::emptyStr, KElementStrings::atr_ID, WString::emptyStr, 
				(WString)"dc_Layout", 0, false);
			vWString v=dc.getNamePathVector(true);
			CPPUNIT_ASSERT_EQUAL( 1, (int)v.size() );
			CPPUNIT_ASSERT_EQUAL( (WString)"Layout",v[0] );
		}

		{
			JDFDevCap dc = (JDFDevCap)devicecap.GetChildWithAttribute(WString::emptyStr, KElementStrings::atr_ID, WString::emptyStr, 
				(WString)"dc_LayoutLink", 0, false);
			vWString v=dc.getNamePathVector(true);
			CPPUNIT_ASSERT_EQUAL( 1, (int)v.size() );
			CPPUNIT_ASSERT_EQUAL( (WString)"LayoutLink",v[0] );
		}

		{
			JDFDevCap dc = (JDFDevCap)devicecap.GetChildWithAttribute(WString::emptyStr, KElementStrings::atr_ID, WString::emptyStr, 
				(WString)"dc_Created", 0, false);
			vWString v=dc.getNamePathVector(true);
			CPPUNIT_ASSERT_EQUAL( 1, (int)v.size() );
			CPPUNIT_ASSERT_EQUAL( (WString)"JDF/AuditPool/Created",v[0] );
		}

		{
			JDFDevCap dc = (JDFDevCap)devicecap.GetChildWithAttribute(WString::emptyStr, KElementStrings::atr_ID, WString::emptyStr, 
				(WString)"dc_JDF", 0, false);
			vWString v=dc.getNamePathVector(true);
			CPPUNIT_ASSERT_EQUAL( 1, (int)v.size() );
			CPPUNIT_ASSERT_EQUAL( (WString)"JDF",v[0] );
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDeviceCapTestCase::testGetCombinedMethod()
{
	try
	{
		XMLDoc d=XMLDoc(JDFNode::elm_DeviceCap);
        JDFDeviceCap dc=(JDFDeviceCap)d.GetRoot();
        vint v;
		v.add(JDFDeviceCap::CombinedMethod_None);
		CPPUNIT_ASSERT_EQUAL( v.GetString(),dc.GetCombinedMethod().GetString() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
