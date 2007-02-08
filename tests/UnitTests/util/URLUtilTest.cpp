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
// created 01 Nov 2006
//
// URLUtilTest.cpp: implements CppUnit tests for JDF::URL
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/net/URL.h"
#include "URLUtilTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (URLUtilTest);

void URLUtilTest::setUp()
{
	try	
	{
		PlatformUtils::Initialize();
	}
	catch (const Exception& e)	
	{
		e.getMessage();
	}
}

void URLUtilTest::testStringToUrl()
{
	// test whether a string is correctly converted into a URL (via constructor)
	try
	{
		// known bug: in case of a absolute URL on Windows files, a URL::getHost() will not display the colon
		// e.g.: with a given ''URL u = URL("File://c:/foo.txt")'', u.getHost() results in "c", not in "c:".
		// This is a problem on the toString() side, the constructor doing his job correctly.
		JDF::URL u = JDF::URL("File://c:/temp/");
		CPPUNIT_ASSERT_EQUAL( (WString)"/temp/",u.getPath() );

		u = JDF::URL("http://www.foo.com/bar/my.jdf");
		CPPUNIT_ASSERT_EQUAL( (WString)"http",u.getProtocol() );
		CPPUNIT_ASSERT_EQUAL( (WString)"www.foo.com",u.getHost() );
		CPPUNIT_ASSERT_EQUAL( (WString)"/bar/my.jdf",u.getPath() );
		CPPUNIT_ASSERT_EQUAL( (WString)"/bar/my.jdf",u.getFile() );
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr,u.getUser() );
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr,u.getPassword() );
		CPPUNIT_ASSERT_EQUAL( -1,u.getPort() );
		
		u = JDF::URL("http://user:pass@www.foo.com:12345/bar/my.jdf");
		CPPUNIT_ASSERT_EQUAL( (WString)"http",u.getProtocol() );
		CPPUNIT_ASSERT_EQUAL( (WString)"www.foo.com",u.getHost() );
		CPPUNIT_ASSERT_EQUAL( (WString)"/bar/my.jdf",u.getPath() );
		CPPUNIT_ASSERT_EQUAL( (WString)"/bar/my.jdf",u.getFile() );
		CPPUNIT_ASSERT_EQUAL( (WString)"user",u.getUser() );
		CPPUNIT_ASSERT_EQUAL( (WString)"pass",u.getPassword() );
		CPPUNIT_ASSERT_EQUAL( 12345,u.getPort() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void URLUtilTest::testGetRelativeUrl()
{
	try
	{
		// simple relative path
		JDF::URL u = JDF::URL("File://c:/abc/def/ghi");
		CPPUNIT_ASSERT( !u.isRelative() );
		CPPUNIT_ASSERT( u.makeRelativeTo("File://c:/abc/") );
		CPPUNIT_ASSERT( u.isRelative() );
		CPPUNIT_ASSERT_EQUAL( (WString)"./def/ghi",u.toString() );
				
		// now with some longer dirs
		u = JDF::URL("File:/C:/Program Files/Microsoft Visual Studio .NET 2003/SDK/v1.1/Lib");
		CPPUNIT_ASSERT( !u.isRelative() );
		CPPUNIT_ASSERT( u.makeRelativeTo("File:/C:/Program Files/") );
		CPPUNIT_ASSERT( u.isRelative() );
		CPPUNIT_ASSERT_EQUAL( (WString)"./Microsoft Visual Studio .NET 2003/SDK/v1.1/Lib",u.toString() );

		// same host, but different subdirectories
		u = JDF::URL("File:/C:/Program Files/Microsoft Visual Studio .NET 2003/SDK/v1.1/Lib");
		CPPUNIT_ASSERT( !u.isRelative() );
		CPPUNIT_ASSERT( u.makeRelativeTo("File:/C:/Program Files/Microsoft Office/") );
		CPPUNIT_ASSERT( u.isRelative() );
		CPPUNIT_ASSERT_EQUAL( (WString)"./../Microsoft Visual Studio .NET 2003/SDK/v1.1/Lib",u.toString() );

		// different hosts - no relative path is to be created
		u = JDF::URL("File://c:/abc/def/ghi");
		CPPUNIT_ASSERT( !u.makeRelativeTo("File://d:/abc") );
		CPPUNIT_ASSERT( !u.isRelative() );
		
		CPPUNIT_ASSERT_EQUAL( (WString)"/abc/def/ghi",u.getPath() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
