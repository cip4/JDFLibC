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
// created 05 Oct 2006
//
// JDFRunListTest.cpp: implements CppUnit tests for JDFRunList
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "JDFRunListTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFRunListTest);


void JDFRunListTest::setUp()
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

void JDFRunListTest::testSetPages()
{
	try
	{
        JDFDoc doc = JDFDoc(0);
        JDFNode root = doc.GetJDFRoot();
		JDFRunList rl=(JDFRunList) root.addResource(JDFNode::elm_RunList,JDFResource::Class_Parameter,JDFResourceLink::Usage_Input);
        JDFIntegerRangeList integerRangeList = JDFIntegerRangeList();
		integerRangeList.Append(JDFIntegerRange(0,-1,8));
        rl.SetPages(integerRangeList);
		CPPUNIT_ASSERT_EQUAL( integerRangeList.GetString(),rl.GetPages().GetString() );		
		CPPUNIT_ASSERT_EQUAL( 8, rl.GetNPage() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFRunListTest::testGetMimeType()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		JDFResourcePool resPool = root.GetCreateResourcePool();
		KElement kElem = resPool.AppendResource(JDFNode::elm_RunList, JDFResource::Class_Parameter);
		JDFRunList ruli=(JDFRunList) kElem;
		CPPUNIT_ASSERT( ruli.getMimeType().empty() );
		kElem.SetXPathAttribute("LayoutElement/FileSpec/@MimeType","application/pdf");
		CPPUNIT_ASSERT_EQUAL( (WString)"application/pdf",ruli.getMimeType() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFRunListTest::testGetNPage()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		JDFResourcePool resPool = root.GetCreateResourcePool();
		JDFRunList rl = (JDFRunList)resPool.AppendResource(JDFNode::elm_RunList, JDFResource::Class_Parameter);
		JDFRunList rlp=(JDFRunList)rl.AddPartition(JDFResource::PartIDKey_Run, "r1");
		rlp.SetPages(JDFIntegerRangeList("1 3 5 7"));
		CPPUNIT_ASSERT_EQUAL( 4,rlp.GetNPage() );
		rlp.SetNPage(3);
		CPPUNIT_ASSERT_EQUAL( 3,rlp.GetNPage() );
		JDFRunList rlp2=(JDFRunList)rl.AddPartition(JDFResource::PartIDKey_Run, "r2");
		rlp2.SetPages(JDFIntegerRangeList("0 2 4 6"));
		CPPUNIT_ASSERT_EQUAL( 4,rlp2.GetNPage() );
		rlp2.SetNPage(3);
		CPPUNIT_ASSERT_EQUAL( 3,rlp2.GetNPage() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
