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
// JDFAutoResourceTest.cpp: implements CppUnit tests for JDFAutoResource
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFAutoResourceTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFAutoResourceTest);

const WString sm_dirTestData = L"data/";

void JDFAutoResourceTest::setUp()
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


void JDFAutoResourceTest::testRunList()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode r=d.GetJDFRoot();
		JDFRunList rl=(JDFRunList) r.addResource("RunList", JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);
        JDFInsertSheet is1=rl.AppendInsertSheet();
		is1.SetSheetType(JDFInsertSheet::SheetType_SeparatorSheet);
		is1.SetSheetUsage(JDFInsertSheet::SheetUsage_Slip);
        JDFInsertSheet is2=rl.AppendInsertSheet();
        is2.SetSheetType(JDFInsertSheet::SheetType_SeparatorSheet);
		is2.SetSheetUsage(JDFInsertSheet::SheetUsage_Slip);
		CPPUNIT_ASSERT( is1 != is2 ); // two insert sheets
        
        rl.AppendLayoutElement(); //1
		CPPUNIT_ASSERT( KElement(rl).IsValid() );
        try{
            rl.AppendLayoutElement();
			CPPUNIT_FAIL( "shouldn't go here, only one layoutelement possible" );
        }
        catch(JDFException)
		{
			// expected to throw JDFException
        }
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFAutoResourceTest::testEnumerations()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode r=d.GetJDFRoot();
		JDFColorPool cp=(JDFColorPool) r.addResource("ColorPool", JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);
		JDFColor col=cp.AppendColor();
		col.SetColorName(JDFElement::NamedColor_Red);
		CPPUNIT_ASSERT_EQUAL( JDFElement::NamedColor_Red,col.GetColorName() ); // named color get
		CPPUNIT_ASSERT_EQUAL( (WString)"Red",col.GetAttribute(JDFNode::atr_ColorName) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFAutoResourceTest::testBinderySignature()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		JDFResource bs = n.addResource(JDFNode::elm_BinderySignature, JDFResource::Class_Parameter, JDFResourceLink::Usage_Input); 
		CPPUNIT_ASSERT_EQUAL( JDFResource::Class_Parameter,bs.GetClass() ); // bs class old style
        CPPUNIT_ASSERT (bs.ValidClass() );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFAutoResourceTest::testMediaIntent()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		n.SetType("Product");
        
		JDFMediaIntent mi = (JDFMediaIntent) n.AppendMatchingResource(JDFNode::elm_MediaIntent,JDFNode::ProcessUsage_AnyInput);
        JDFStringSpan sb=mi.AppendStockBrand();
        sb.SetActual("abc foo");
        sb.SetPreferred("abc foo");
		CPPUNIT_ASSERT( sb.IsValid() );
		CPPUNIT_ASSERT_EQUAL( JDFResource::Class_Intent,mi.GetClass() );
		CPPUNIT_ASSERT( mi.ValidClass(JDFElement::ValidationLevel_Complete) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFAutoResourceTest::testDevice()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		n.SetType("Stitching");
		JDFDevice dev=(JDFDevice) n.AppendMatchingResource(JDFNode::elm_Device,JDFNode::ProcessUsage_AnyInput);
		dev.SetStatus(JDFResource::Status_Available,true);
		dev.SetKnownLocalizations(vWString("De", WString::emptyStr) );
        dev.SetSerialNumber("12345");
        dev.SetSecureJMFURL("http://fififi");
        JDFModule m=dev.AppendModule();
		m.SetDescriptiveName("1234");
        JDFIconList il=dev.AppendIconList();
		CPPUNIT_ASSERT( !il.IsValid() ); // empty iconlist
		CPPUNIT_ASSERT( il.IsValid(JDFElement::ValidationLevel_Incomplete) ); // empty iconlist
        JDFIcon ic=il.AppendIcon();
        ic.SetSize(JDFXYPair(200,200));
        ic.SetBitDepth(8);
        JDFFileSpec fs=ic.AppendFileSpec();
        fs.SetURL("file:///this.ico");
        
		CPPUNIT_ASSERT( KElement(ic).IsValid() ); //icon valid
		CPPUNIT_ASSERT( KElement(il).IsValid() ); //iconlist valid
        CPPUNIT_ASSERT( KElement(m).IsValid() );  //mod valid
        CPPUNIT_ASSERT( KElement(dev).IsValid() ); //dev valid
		CPPUNIT_ASSERT( dev.ValidClass(JDFElement::ValidationLevel_Complete) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFAutoResourceTest::testScore()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("CoverApplication");
		JDFCoverApplicationParams cap=(JDFCoverApplicationParams) n.AppendMatchingResource(JDFNode::elm_CoverApplicationParams,JDFNode::ProcessUsage_AnyInput);
        JDFScore score=cap.AppendScore();
        score.SetOffset(1234.5);
		CPPUNIT_ASSERT( KElement(score).IsValid() ); // score 1
		CPPUNIT_ASSERT( KElement(cap).IsValid() );
        // we know that we are incomplete since we have missing resources
		CPPUNIT_ASSERT( KElement(cap).IsValid(JDFElement::ValidationLevel_Incomplete) );
	}
	catch (const JDF::JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
