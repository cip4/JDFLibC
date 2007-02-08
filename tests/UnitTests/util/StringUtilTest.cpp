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
// created 13 Oct 2006
//
// StringUtilTest.cpp: implements CppUnit tests for JDF::StringUtil/WString
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "StringUtilTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (StringUtilTest);

void StringUtilTest::setUp()
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

void StringUtilTest::testSetHexBinaryBytes()
{
	try
	{
		WString strTestString = "ABCDEFGHIJKLMNOPQESTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ÖÄÜöäü€";
		char* buffer = strTestString.getBytes();
		WString strTemp;
		strTemp.SetHexBinaryBytes(buffer,-1);
		const char* tempBuffer = strTemp.GetHexBinaryBytes();//strTemp.getBytes());
		WString strResultString  = WString(tempBuffer); 
		CPPUNIT_ASSERT_EQUAL_MESSAGE( "Input and Outputstring are not equal",strTestString,strResultString );

		delete buffer;
		buffer = 0;
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testSetUTF8Bytes()
{
	try
	{
		// round trip 1
		WString testString = "ABCDEFGHIJKLMNOPQESTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ÖÄÜöäü€";
		const char* const utfBytes = testString.GetUTF8Bytes();
		int utfBytes_siz = strlen(utfBytes);
		WString temp;
		temp.SetUTF8Bytes(utfBytes,utfBytes_siz);
		CPPUNIT_ASSERT_EQUAL( testString,temp );

		// round trip 2
		WString testString2;
		testString2.SetUTF8Bytes(utfBytes);
		const char* const utfBytes2 = testString2.GetUTF8Bytes();
		CPPUNIT_ASSERT_EQUAL( *utfBytes,*utfBytes2 );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testSetVWString()
{
	try
	{
		vWString v;
		v.add("1");
		v.add("22");
		v.add("333");
		v.add("4444");
		WString s;

		s.SetvString(v);
		CPPUNIT_ASSERT_EQUAL( (WString)"1 22 333 4444",s );
		s.SetvString(v,WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( (WString)"1223334444",s );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testEscape()
{
	try
	{
		WString temp="file://myHost/a/c%20äöü%25&?.txtß€";

		WString actual = temp.Escape(":&?%","%",16,4,0x21,127).UnEscape('%',16,4);
		CPPUNIT_ASSERT_EQUAL( temp,actual );

		temp = "%_ä";
		CPPUNIT_ASSERT_EQUAL( (WString)"%25_%E4",temp.Escape("%","%",16,2,0x21,0x7F) );

		temp = "€";
		const char* bb = temp.GetUTF8Bytes();
		temp.SetRawBytes(bb);
		CPPUNIT_ASSERT_EQUAL( (WString)"%E2%82%AC",temp.Escape(WString::emptyStr,"%",16,2,0x21,0x7F) );
		
		temp = "ß";
		CPPUNIT_ASSERT_EQUAL( (WString)"ß",temp.Escape(WString::emptyStr,"%",16,2) ); 

		temp =  "aäa";
		CPPUNIT_ASSERT_EQUAL( (WString)"a_a",temp.Escape(WString::emptyStr,"_",-1,0,0x21,127) );

		temp = "aä_a";
		CPPUNIT_ASSERT_EQUAL( (WString)"a__a",temp.Escape(WString::emptyStr,"_",-1,0,0x21,127) );

		temp =  "aäa";
		CPPUNIT_ASSERT_EQUAL( (WString)"a_äa",temp.Escape(WString::emptyStr,"_",0,0,0x21,127) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testMatches()
{
	// Note: WString::matches() relies on Xerces. This test runs on Xerces 2.7, 
	//       which has known issues concerning its regex handling.
	try
	{
		CPPUNIT_ASSERT( WString("a bb c").matches("(.+ )*(bb)( .+)*") );
		CPPUNIT_ASSERT( WString("b bb c").matches("(.* )*(bb)( .+)*") );
		CPPUNIT_ASSERT( WString("a bb").matches("(.+ )*(bb)( .+)*") );
		CPPUNIT_ASSERT( WString("bb").matches("(.+ )*(bb)( .+)*") );
		CPPUNIT_ASSERT( !WString(" bb").matches("(.+ )*(bb)( .+)*") );
		CPPUNIT_ASSERT( !WString("bb ").matches("(.+ )*(bb)( .+)*") );
		CPPUNIT_ASSERT( !WString("a").matches("(.+ )*(bb)( .+)*") );
		CPPUNIT_ASSERT( !WString("a c").matches("(.+ )*(bb)( .+)*") );
		CPPUNIT_ASSERT( !WString("a b c").matches("(.+ )*(bb)( .+)*") );
		CPPUNIT_ASSERT( WString("abc").matches("*") ); 
		CPPUNIT_ASSERT( WString("abc").matches(".*") );
		CPPUNIT_ASSERT( WString("abc").matches(".+") );
		CPPUNIT_ASSERT( WString("abc").matches("") );
		CPPUNIT_ASSERT( WString("äbc").matches("...") );
		CPPUNIT_ASSERT( WString("äbc").matches(WString::emptyStr) );
		CPPUNIT_ASSERT( WString("ä").matches("ä?") );
		CPPUNIT_ASSERT( WString(WString::emptyStr).matches("ä?") );
		CPPUNIT_ASSERT( WString("12de").matches(WString::regExp_hexbinary) );
		CPPUNIT_ASSERT( !WString("12d").matches(WString::regExp_hexbinary) );
		CPPUNIT_ASSERT( !WString("12dk").matches(WString::regExp_hexbinary) );
		CPPUNIT_ASSERT( !WString("ö").matches("ä?") );
		CPPUNIT_ASSERT( !WString("abc").matches("..") );
		CPPUNIT_ASSERT( !WString(WString::emptyStr,WString::emptyStr) );
		CPPUNIT_ASSERT( !WString("abc").matches("?") );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	} 
}

void StringUtilTest::testZappTokenWS()
{
	try
	{
		WString s=" 1 2 3~    4";
		s=s.ZappTokenWS(WString::tilde);
		CPPUNIT_ASSERT_EQUAL( (WString)"1 2 3~4",s );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testHasToken()
{
	try
	{
		WString s="1 2 3 3 15 4";
		CPPUNIT_ASSERT( !s.HasToken("0") );
		CPPUNIT_ASSERT( s.HasToken("1") );
		CPPUNIT_ASSERT( !s.HasToken("5") );
		CPPUNIT_ASSERT( s.HasToken("2") );
		CPPUNIT_ASSERT( s.HasToken("4") );
		CPPUNIT_ASSERT( s.HasToken("3") );
		CPPUNIT_ASSERT( s.HasToken("3",WString::whiteSpace,1) );
		CPPUNIT_ASSERT( !s.HasToken("3",WString::whiteSpace,2) );
		CPPUNIT_ASSERT( !s.HasToken("3",WString::whiteSpace,99) );
		s = WString::whiteSpace;
		CPPUNIT_ASSERT( !s.HasToken("0",WString::whiteSpace,0) );
		s = "ab";
		CPPUNIT_ASSERT( !s.HasToken("a",WString::whiteSpace,0) );
		CPPUNIT_ASSERT( !s.HasToken("b",WString::whiteSpace,0) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testToken()
{
	try
	{
		WString s="1 2 3 4";
		CPPUNIT_ASSERT_EQUAL( (WString)"1",s.Token(0) );
		CPPUNIT_ASSERT_EQUAL( (WString)"2",s.Token(1) );
		/*** negative indizes are not (yet) supported ***
		 * CPPUNIT_ASSERT_EQUAL( (WString)"2",s.Token(-3) );
		 * CPPUNIT_ASSERT_EQUAL( (WString)"4",s.Token(-1) );
		 * CPPUNIT_ASSERT_EQUAL( WString::emptyStr,s.Token(4) );
		 * CPPUNIT_ASSERT_EQUAL( WString::emptyStr,s.Token(-5) );
		 */
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testTokenize()
{
	try
	{
		WString s="1 2 3";
		vWString v;
		v.add("1");
		v.add("2");
		v.add("3");

		CPPUNIT_ASSERT_EQUAL( v.GetString(),s.Tokenize().GetString() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testEndsWithIgnoreCase()
{
	try
	{
		WString s="a.ZIP";
		CPPUNIT_ASSERT( s.toLowerCase().endsWith(".zip") );
		CPPUNIT_ASSERT_EQUAL( (WString)"a.ZIP",s );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testToUpperCase()
{
	try
	{
		WString s = "toUpperCase";
		WString res = s.toUpperCase();
		CPPUNIT_ASSERT_EQUAL( (WString)"TOUPPERCASE",res );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void StringUtilTest::testToLowerCase()
{
	try
	{
		WString s = "toLOWERCase";
		WString res = s.toLowerCase();
		CPPUNIT_ASSERT_EQUAL( (WString)"tolowercase",res );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
