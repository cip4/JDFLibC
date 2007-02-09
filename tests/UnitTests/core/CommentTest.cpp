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
// created 03 Aug 2006
//
// CommentTest.cpp: implements CppUnit tests for JDF comments
//
//////////////////////////////////////////////////////////////////////

#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "CommentTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (CommentTest);

const WString sm_dirTestTemp = L"temp/";

void CommentTest::setUp()
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

void CommentTest::testInit()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root=(JDFNode)doc.GetRoot();
		JDFComment cRoot=root.AppendComment();
		CPPUNIT_ASSERT( !cRoot.isNull() );

		root.SetVersion(JDFElement::VersionString(JDFElement::Version_1_2));
		JDFAuditPool ap=root.GetCreateAuditPool();
		JDFNotification notif=ap.AddNotification(JDFNotification::Class_Information, "Me");
		JDFComment c = notif.AppendComment();
		c.SetText("This element should have no ID attribute");
		WString id = c.GetAttribute(JDFElement::atr_ID);
		CPPUNIT_ASSERT ( id.empty() );
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void CommentTest::testFormat()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = (JDFNode)doc.GetJDFRoot();
		JDFComment c11 = root.AppendComment();
		WString txt = "This element should have no ID attribute and is a really long line with many many characters.. asfihAFLKFKJGFaufksgUFGagfAFKJSG";
		txt+=txt;
		txt+=txt; // even longer...
		c11.SetText(txt);
		JDFComment c21 = root.AppendComment();
		WString txt2 = "This element \n has \n crlf";
		c21.SetText(txt2);
		CPPUNIT_ASSERT_EQUAL( txt, c11.GetText() );
		CPPUNIT_ASSERT_EQUAL( txt2, c21.GetText() );
		WString commentFile = sm_dirTestTemp + "CommentTest.JDF";
		doc.Write2File(commentFile);
		JDFParser p;
		p.Parse(commentFile, false);
		JDFDoc doc2 = p.GetDocument();
		JDFNode root2 = doc2.GetJDFRoot();
		JDFComment c12 = root2.GetComment(0);
		JDFComment c22 = root2.GetComment(1);
		CPPUNIT_ASSERT_EQUAL( txt, c12.GetText() );
		CPPUNIT_ASSERT_EQUAL( txt2, c22.GetText() );
	}
	catch (std::exception e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
