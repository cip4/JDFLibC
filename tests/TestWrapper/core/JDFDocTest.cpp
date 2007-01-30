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
// created 11 Oct 2006
//
// JDFDocTest.cpp: implements CppUnit tests for JDFDoc
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "JDFDocTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFDocTest);

const WString sm_dirTestData = L"data\\";
const WString sm_dirTestTemp = L"temp\\";

void JDFDocTest::setUp()
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

/**
* just a minor test. It only checks the precessgroup count and also the class casts in GetProcessGroups
*/
void JDFDocTest::testRoots()
{
	try
	{
		WString xmlFile = "job.jdf";

        JDFParser p;
		p.Parse(sm_dirTestData+xmlFile,false);
		JDFDoc jdfDoc = p.GetDocument();

		CPPUNIT_ASSERT( !jdfDoc.isNull() );
		CPPUNIT_ASSERT( !jdfDoc.GetJDFRoot().isNull() );
		CPPUNIT_ASSERT( jdfDoc.GetJMFRoot().isNull() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDocTest::testNull()
{
	try
	{		
		JDFDoc doc;
        WString foo="wehflkh";
        JDFParser p;
     
		cout << endl << "parser error is to be expected: ";
		p.StringParse(foo);
		doc=p.GetDocument();
		CPPUNIT_ASSERT( doc.isNull() );
        doc=JDFDoc(0); 
		//CPPUNIT_ASSERT( !doc.getNodeName().isNull() );   // JDFDoc::getNodeName() is missing
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDocTest::testGetContentType()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		CPPUNIT_ASSERT_EQUAL( (WString)"application/vnd.cip4-jdf+xml",d.GetContentType() );
        JDFDoc dm=JDFDoc(1);
		CPPUNIT_ASSERT_EQUAL( (WString)"application/vnd.cip4-jmf+xml",dm.GetContentType() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDocTest::testCorrupt()
{
	try
	{
		JDFDoc doc;
		WString foo="wehflkh";
		JDFParser p;
		cout << endl << "parser error is to be expected: ";
		p.StringParse(foo);
		doc=p.GetDocument();
		CPPUNIT_ASSERT( doc.isNull() );
		foo="<xxx><yyy><zzz></yyy></xxx>";
		cout << endl << "parser error is to be expected: ";
		p.StringParse(foo);
		doc=p.GetDocument();
		CPPUNIT_ASSERT( doc.isNull() );

		p.Parse(sm_dirTestData+"corrupt.jdf",false);
		doc=p.GetDocument();
		CPPUNIT_ASSERT( doc.isNull() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDocTest::testEmptyString()
{
	try
	{
		JDFDoc inMessageDoc = JDFDoc(1);
		JDFJMF jmfIn = inMessageDoc.GetJMFRoot();
        
		jmfIn.appendMessageElement(JDFMessage::Family_Response, JDFMessage::Type_Unknown);
		WString s;
        inMessageDoc.Write2String(s);
		CPPUNIT_ASSERT( !s.empty() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
