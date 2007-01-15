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
// created 12 Aug 2006
//
// JDFLayoutTest.cpp: implements CppUnit tests around JDF 1.2 vs JDF 1.3 layouts
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFLayoutTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFLayoutTest);

const WString sm_dirTestData = L"data\\";

void JDFLayoutTest::setUp()
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

void JDFLayoutTest::testIsNewLayout()
{
	try
	{
		JDFDoc doc=JDFDoc(0);
		JDFNode n=doc.GetJDFRoot();
		n.SetType("Imposition");
		JDFRunList rl=(JDFRunList) n.AppendMatchingResource(JDFNode::elm_RunList,JDFNode::ProcessUsage_AnyInput);

		CPPUNIT_ASSERT_EQUAL( JDFElement::VersionString(JDFElement::Version_1_3),n.GetVersion() );
		JDFLayout lo=(JDFLayout) n.AppendMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		CPPUNIT_ASSERT( JDFLayout::isNewLayout(lo) );
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_2));
		CPPUNIT_ASSERT( !JDFLayout::isNewLayout(lo) );
		lo.AddPartition(JDFResource::PartIDKey_SheetName,"Sheet1");
		CPPUNIT_ASSERT( JDFLayout::isNewLayout(lo) );
		CPPUNIT_ASSERT( !JDFLayout::isNewLayout(rl) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFLayoutTest::testFixFromFlatNewLayout()
{
	try
	{
		JDFDoc doc=JDFDoc(0);
		JDFNode n=doc.GetJDFRoot();
		n.SetType("Imposition");
		JDFRunList rl=(JDFRunList) n.AppendMatchingResource(JDFNode::elm_RunList,JDFNode::ProcessUsage_AnyInput);

		n.SetVersion(JDFNode::VersionString(JDFNode::Version_1_3));
		JDFLayout loNew=(JDFLayout) n.AppendMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		JDFContentObject co1=loNew.AppendContentObject();

		n.FixVersion(JDFElement::Version_1_2);
		JDFLayout lo=(JDFLayout) n.GetMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_Any);
		CPPUNIT_ASSERT( !JDFLayout::isNewLayout(lo) );
		JDFSignature si=lo.GetSignature(0);
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Signature,si.GetLocalName() );
		JDFSheet sh=si.GetSheet(0);
		JDFSurface su=sh.GetSurface();
		CPPUNIT_ASSERT_EQUAL( co1,su.GetContentObject() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFLayoutTest::testFixFromSheetNewLayout()
{
	try
	{
		JDFDoc doc=JDFDoc(0);
		JDFNode n=doc.GetJDFRoot();
		n.SetType("Imposition");
		JDFRunList rl=(JDFRunList) n.AppendMatchingResource(JDFNode::elm_RunList,JDFNode::ProcessUsage_AnyInput);

		n.SetVersion(JDFNode::VersionString(JDFNode::Version_1_3));
		JDFLayout loNew=(JDFLayout) n.AppendMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		loNew=(JDFLayout) loNew.AddPartition(JDFResource::PartIDKey_SignatureName,"sig1");
		loNew=(JDFLayout) loNew.AddPartition(JDFResource::PartIDKey_SheetName,"s1");
		loNew=(JDFLayout) loNew.AddPartition(JDFResource::PartIDKey_Side,"Front");
		JDFContentObject co1=loNew.AppendContentObject();

		n.FixVersion(JDFNode::Version_1_2);
		JDFLayout lo=(JDFLayout) n.GetMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		JDFLayout::isNewLayout(lo);
		CPPUNIT_ASSERT( !JDFLayout::isNewLayout(lo) );
		JDFSignature si=lo.GetSignature();
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Signature,si.GetLocalName() );
		JDFSheet sh=si.GetSheet();
		JDFSurface su=sh.GetSurface();
		CPPUNIT_ASSERT_EQUAL( co1,su.GetContentObject() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFLayoutTest::testFixFromSurfaceNewLayout()
{
	try
	{
		JDFDoc doc=JDFDoc(0);
		JDFNode n=doc.GetJDFRoot();
		n.SetType("Imposition");
		JDFRunList rl=(JDFRunList) n.AppendMatchingResource(JDFNode::elm_RunList,JDFNode::ProcessUsage_AnyInput);

		n.SetVersion(JDFNode::VersionString(JDFNode::Version_1_3));
		JDFLayout loNew=(JDFLayout) n.AppendMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		loNew=(JDFLayout) loNew.AddPartition(JDFResource::PartIDKey_Side,"Back");
		JDFContentObject co1=loNew.AppendContentObject();

		n.FixVersion(JDFNode::Version_1_2);
		
		JDFLayout lo=(JDFLayout) n.GetMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		CPPUNIT_ASSERT( !JDFLayout::isNewLayout(lo) );
		JDFSignature si=lo.GetSignature(0);
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Signature,si.GetLocalName() );
		JDFSheet sh=si.GetSheet(0);
		JDFSurface su=sh.GetSurfaceBySide(JDFAutoPart::Side_Front);
		CPPUNIT_ASSERT( su.isNull() );
		su=sh.GetSurfaceBySide(JDFAutoPart::Side_Back);
		CPPUNIT_ASSERT_EQUAL( co1,su.GetContentObject() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFLayoutTest::testFixVersionProblem()
{
	try
	{
		JDFParser p;
		p.Parse(sm_dirTestData+"FixVersionProblem.jdf",false);
		JDFDoc d=p.GetDocument();
		CPPUNIT_ASSERT_MESSAGE( "FixVersion problem exists", !d.isNull() );
		JDFNode n=d.GetJDFRoot();
		n.FixVersion(JDFNode::Version_1_2);
		JDFLayout lo=(JDFLayout) n.GetResourcePool().GetElement(JDFNode::elm_Layout);
		CPPUNIT_ASSERT_EQUAL( 1,lo.NumChildElements(JDFNode::elm_Signature) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFLayoutTest::testBuildOldLayout()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode n=doc.GetJDFRoot();
		n.SetType("Imposition");
		JDFRunList rl= n.AppendMatchingResource(JDFNode::elm_RunList,JDFNode::ProcessUsage_AnyInput);


		n.SetVersion(JDFNode::VersionString(JDFNode::Version_1_2));
		JDFLayout lo=(JDFLayout) n.AppendMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		CPPUNIT_ASSERT( !JDFLayout::isNewLayout(lo) ); // lo 1.3
		JDFSignature si=lo.AppendSignature();
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Signature,si.GetLocalName() ); // signature name
		CPPUNIT_ASSERT( !si.HasAttribute(JDFNode::atr_Class) );
		si=lo.AppendSignature();
		CPPUNIT_ASSERT_EQUAL( 2,lo.numSignatures() ); // num sigs
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Signature,si.GetLocalName() ); // signature name

		JDFSheet sh=si.AppendSheet();
		sh.MakeRootResource(); // see what happens with refelements
		sh=si.AppendSheet();
		CPPUNIT_ASSERT_EQUAL( 2,si.numSheets() ); // num sheets
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Sheet,sh.GetLocalName() ); // sheet name
		sh=si.GetCreateSheet(4);
		CPPUNIT_ASSERT_EQUAL( 3,si.numSheets()); // num sheets
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Sheet,sh.GetLocalName() ); // sheet name
		sh=si.GetSheet(2);
		CPPUNIT_ASSERT_EQUAL( 3,si.numSheets()); // num sheets
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Sheet,sh.GetLocalName() ); // sheet name

		JDFSurface su=sh.AppendFrontSurface();
		CPPUNIT_ASSERT_EQUAL( 1,sh.numSurfaces()); // num surfaces
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Surface,su.GetLocalName() ); // sheet name
		CPPUNIT_ASSERT( sh.HasFrontSurface() ); // num surfaces
		su.AppendContentObject();
		su.AppendMarkObject();
		su.AppendContentObject();
		su.AppendContentObject();

		su=sh.AppendBackSurface();
		su.MakeRootResource();
		su.AppendContentObject();
		su.AppendMarkObject();
		su.AppendContentObject();
		su.AppendContentObject();
		su.AppendMarkObject();
		CPPUNIT_ASSERT_EQUAL( 2,sh.numSurfaces() ); // num surfaces
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Surface,su.GetLocalName() ); // sheet name
		CPPUNIT_ASSERT( sh.HasBackSurface() ); // has BackSurface

		sh.AppendBackSurface();
		CPPUNIT_ASSERT_EQUAL( 2,sh.numSurfaces() ); // didn't append a third surface

		si=lo.GetCreateSignature(4);
		CPPUNIT_ASSERT_EQUAL( 3,lo.numSignatures() ); // num sigs
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Signature,si.GetLocalName() ); // signature name
		si=lo.GetSignature(2);
		CPPUNIT_ASSERT_EQUAL( 3,lo.numSignatures() ); // num sigs
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Signature,si.GetLocalName() ); // signature name
		si=lo.GetSignature(5);
		CPPUNIT_ASSERT( si.isNull() ); // si null
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFLayoutTest::testBuildNewLayout()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode n=doc.GetJDFRoot();
		n.SetType("Imposition");
		JDFRunList rl= n.AppendMatchingResource(JDFNode::elm_RunList,JDFNode::ProcessUsage_AnyInput);


		JDFLayout lo=n.AppendMatchingResource(JDFNode::elm_Layout,JDFNode::ProcessUsage_AnyInput);
		CPPUNIT_ASSERT( JDFLayout::isNewLayout(lo) ); // lo 1.3
        JDFSignature si=lo.AppendSignature();
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,si.GetLocalName() ); // signature name
		si=lo.AppendSignature();
		CPPUNIT_ASSERT_EQUAL( 2,lo.numSignatures() ); // num sigs
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,si.GetLocalName() ); // signature name
        
        JDFSheet sh=si.AppendSheet();
        sh=si.AppendSheet();
		CPPUNIT_ASSERT_EQUAL( 2,si.numSheets() ); // num sheets
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,sh.GetLocalName() ); // sheet name
        sh=si.GetCreateSheet(4);
		
        CPPUNIT_ASSERT_EQUAL( 3,si.numSheets()); // num sheets		
        CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,sh.GetLocalName() ); // sheet name
        sh=si.GetSheet(2);
        CPPUNIT_ASSERT_EQUAL( 3,si.numSheets()); // num sheets
        CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,sh.GetLocalName()); // sheet name

        JDFSurface su=sh.AppendFrontSurface();
        CPPUNIT_ASSERT_EQUAL( 1,sh.numSurfaces() ); // num surfaces
        CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,su.GetLocalName() ); // sheet name
		CPPUNIT_ASSERT( sh.HasFrontSurface() ); // hasfrontSurface
        
        su=sh.AppendBackSurface();
        CPPUNIT_ASSERT_EQUAL( 2,sh.numSurfaces() );  // num surfaces
		CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,su.GetLocalName() ); // sheet name
        
        sh.AppendBackSurface();       
		CPPUNIT_ASSERT_EQUAL( 2,sh.numSurfaces() ); // did not add another surface
        
        si=lo.GetCreateSignature(4);
        CPPUNIT_ASSERT_EQUAL( 3,lo.numSignatures() ); // num sigs
        CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,si.GetLocalName() ); // signature name
        si=lo.GetSignature(2);
        CPPUNIT_ASSERT_EQUAL( 3,lo.numSignatures() ); // num sigs
        CPPUNIT_ASSERT_EQUAL( JDFNode::elm_Layout,si.GetLocalName() ); // signature name
		si=lo.GetSignature(5);
		CPPUNIT_ASSERT( si.isNull() ); // si is null
		CPPUNIT_ASSERT( lo.IsValid(JDFResource::ValidationLevel_Complete) ); // layout valid
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
