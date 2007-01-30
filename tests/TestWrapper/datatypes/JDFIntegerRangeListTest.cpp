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
// created 17 Oct 2006
//
// JDFIntegerRangeListTest.cpp: implements CppUnit tests for JDFIntegerRangeList
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFIntegerRangeListTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFIntegerRangeListTest);


void JDFIntegerRangeListTest::setUp()
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

void JDFIntegerRangeListTest::testJDFIntegerRangeListString()
{
	try
	{
		JDFIntegerRangeList rangeList = JDFIntegerRangeList(" 0 1 ~ 2 3 ~ 6 INF ");
		CPPUNIT_ASSERT_EQUAL( JDFIntegerRangeList("   1   ").GetString(),JDFIntegerRangeList("1~1").GetString() );
		// rangeList is not empty
		CPPUNIT_ASSERT_EQUAL( 4,rangeList.size() );
		// must be transformed into the string "0 1~2 3~6 INF"
		CPPUNIT_ASSERT_EQUAL( (WString)"0 1 ~ 2 3 ~ 6 INF",rangeList.GetString() ); 
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testJDFIntegerRangeListXDef()
{
	try
	{
		JDFIntegerRange r = JDFIntegerRange(1,2);
		CPPUNIT_ASSERT_EQUAL( 2,r.NElements() );

		JDFIntegerRange r2 = JDFIntegerRange(3,-1,16); // 16 elements element(-1) = 15, range = 3~15
		CPPUNIT_ASSERT_EQUAL( 13,r2.NElements() );

		JDFIntegerRangeList r3 = JDFIntegerRangeList(" 1 ~ 2 3 ~ -1 ", 16);
		CPPUNIT_ASSERT_EQUAL( 15,r3.NElements() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testConstruct()
{
	try
	{
		JDFIntegerRangeList rangeList = JDFIntegerRangeList(WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( 0,rangeList.NElements() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testDef()
{
	try
	{
		// Fehler bei der Behandlung von xDef:
		// Wert wird gesetzt, jedoch ledigl. bei NElements() verwendet.
		// -> kein xDef in JDFRange
		JDFIntegerRangeList rangeList = JDFIntegerRangeList("0 ~-1");
		cout << endl << "RangeList: " << rangeList.GetString();
		rangeList.SetDef(20);
		cout << endl << "RangeList after SetDef(20): " << rangeList.GetString();
		cout << endl;
		CPPUNIT_ASSERT_EQUAL( 20,rangeList.NElements() );

		rangeList = JDFIntegerRangeList("2 ~ -6 -3 -2 -1 ");
		rangeList.SetDef(10);
		WString actual = rangeList.GetString();
		CPPUNIT_ASSERT_EQUAL( (WString)"2 ~ 4 7 8 9",actual );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testGetIntegerList()
{
	cout << " *warning: this test is slow (~20s)* ";
	try
	{
		JDFIntegerRangeList rangeList = JDFIntegerRangeList("0 1~2 3~6 8 ~ 7");
		vint list = rangeList.ToVInt(6010); // default capacity for a vint is 1000, here we need more
		// list must be equal the string "0 1 2 3 4 5 6"
		CPPUNIT_ASSERT_EQUAL( (WString)"0 1 2 3 4 5 6 8 7",list.GetString() );

		// now some performance
		for(int i=0;i<1000;i++)
			rangeList.Append(i*10, i*10+5);

		int n=0;
		for(int i=0;i<rangeList.NElements();i++){
			int j=rangeList.Element(i);
			n+=j;
		}

		list = rangeList.ToVInt(6010); // default capacity for a vint is 1000, here we need more
		int siz = (int)list.size();
		int m=0;
		for(int i=0;i<(int)list.size();i++){
			int j=(int)list[i];
			m+=j;
		}

		CPPUNIT_ASSERT_EQUAL( n,m );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testJDFIntegerRangeList_CopyConstructor()
{
	try
	{
		JDFIntegerRangeList rangeList;
        JDFIntegerRangeList copyRangeList;
        try
        {
            rangeList     = JDFIntegerRangeList("0 4");
            copyRangeList = JDFIntegerRangeList(rangeList);
            copyRangeList.Append(JDFIntegerRange("8~9"));
        }
        catch ( ... )
        {
            CPPUNIT_FAIL( "DataFormatException ?" );
        }
		CPPUNIT_ASSERT_EQUAL_MESSAGE( "original rangeList wrong",(WString)"0 4",rangeList.GetString() );
		CPPUNIT_ASSERT_EQUAL_MESSAGE( "changed copy of rangeList wrong:",(WString)"0 4 8 ~ 9",copyRangeList.GetString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testAppend()
{
	try
	{
		JDFIntegerRangeList rangeList;
		JDFIntegerRangeList copyRangeList;
		try {
			rangeList= JDFIntegerRangeList("0 4~5");
			rangeList.Append(6,7);
			rangeList.Append(JDFIntegerRange(7,8));
			rangeList.Append(JDFIntegerRange("8~9"));
			copyRangeList = JDFIntegerRangeList("0 4~5 6~7 7~8 8~9");
		}
		catch ( ... ) 
		{
			CPPUNIT_FAIL( "DataFormatException ?" );
		}

		CPPUNIT_ASSERT_EQUAL( rangeList.GetString(),copyRangeList.GetString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testIsList()
{
	try
	{
		JDFIntegerRangeList goodRangeList;
        JDFIntegerRangeList badRangeList;
        try {
            goodRangeList= JDFIntegerRangeList("0 4");
            goodRangeList.Append(6, 6);
            goodRangeList.Append(7 ,7);
            
			badRangeList = JDFIntegerRangeList(goodRangeList);
            badRangeList.Append(JDFIntegerRange("8~9"));
        }
        catch ( ... ) 
		{
            CPPUNIT_FAIL( "DataFormatException ?" );
        }

		CPPUNIT_ASSERT( goodRangeList.IsList() );
		CPPUNIT_ASSERT( !badRangeList.IsList() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testIsUnique()
{
	try
	{
		JDFIntegerRangeList rangeList= JDFIntegerRangeList("0 3~5");
		CPPUNIT_ASSERT( rangeList.IsUnique() );
        rangeList.Append(4);
		CPPUNIT_ASSERT( !rangeList.IsUnique() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testIsOrdered_False()
{
	try
	{
		JDFIntegerRangeList rangeList = JDFIntegerRangeList("0~8");
		CPPUNIT_ASSERT( rangeList.IsOrdered() );
        
		rangeList.Append(5);
        rangeList.Append(JDFIntegerRange("6~7"));
        rangeList.Append(9);
		CPPUNIT_ASSERT( !rangeList.IsOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testIsOrdered_Reverse_True()
{
	try
	{
		JDFIntegerRangeList rangeList=JDFIntegerRangeList("21 ~ 10 6");
        rangeList.Append(5);
        rangeList.Append(4,3);

       CPPUNIT_ASSERT( rangeList.IsOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testIsUniqueOrdered_Reverse_False()
{
	try
	{
		JDFIntegerRangeList rangeList=JDFIntegerRangeList("7 4");
        rangeList.Append(10);
        rangeList.Append(3,1);

		CPPUNIT_ASSERT( !rangeList.IsUniqueOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testIsUniqueOrdered_False()
{
	try
	{
		JDFIntegerRangeList rangeList= JDFIntegerRangeList("0 2 4");
        rangeList.Append(6);
        rangeList.Append(JDFIntegerRange("6~8"));
        rangeList.Append(10);

		CPPUNIT_ASSERT( !rangeList.IsUniqueOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testIsUniqueOrdered_True()
{
	try
	{
		JDFIntegerRangeList rangeList= JDFIntegerRangeList("0 2 5");
        rangeList.Append(6,8);
        rangeList.Append(10);

		CPPUNIT_ASSERT( rangeList.IsUniqueOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testJDFIntegerRangeList1()
{
	try
	{
		JDFIntegerRangeList integerRangeList;
        for (int i = 0; i <= 10; i++)
        {
            integerRangeList.Append(i);
        }
        
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 10",integerRangeList.GetString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testJDFIntegerRangeList2()
{
	try
	{
		JDFIntegerRangeList integerRangeList;
        for (int i = 0; i <= 10; i++)
        {
            if(i != 4 && i != 8)
            {
                integerRangeList.Append(i);
            }
        }
        
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 3 5 ~ 7 9 ~ 10",integerRangeList.GetString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testDefaultDef()
{
	try
	{
		// note: initial default def is 0
		JDFIntegerRangeList irl;
		try
        {
            irl=JDFIntegerRangeList("-INF ~ 0 5 ~ -1");			
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor" );
		}
		CPPUNIT_ASSERT( irl.InRange(-99) );
		CPPUNIT_ASSERT( !irl.InRange(99) );
		CPPUNIT_ASSERT( irl.InRange(2) );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testInRange()
{
	try
	{
		JDFIntegerRangeList irl;
		try
		{
			irl=JDFIntegerRangeList("-INF ~ 0 5 ~ INF");
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor" );
		}

		CPPUNIT_ASSERT( irl.InRange(-99) );
		CPPUNIT_ASSERT( irl.InRange(99) );
		CPPUNIT_ASSERT( !irl.InRange(2) );
		
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testInfiniteList()
{
	try
	{
		JDFIntegerRangeList integerRangeList = JDFIntegerRangeList("0~-1",WString::pINF);
		for(int i = 0; i <= 10; i++)
		{
			CPPUNIT_ASSERT( integerRangeList.InRange(i) );
		}
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testgetElementCount()
{
	try
	{
		JDFIntegerRangeList irl=JDFIntegerRangeList("0 ~ 5");
		CPPUNIT_ASSERT_EQUAL( 6,irl.NElements() );
		irl=JDFIntegerRangeList("0 ~ -1");
		CPPUNIT_ASSERT_EQUAL( 0,irl.NElements() );
		irl=JDFIntegerRangeList("0 ~ INF");
		CPPUNIT_ASSERT( irl.NElements()<0 );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeListTest::testgetElement()
{
	try
	{
		JDFIntegerRangeList irl=JDFIntegerRangeList("5 ~ 8");
		CPPUNIT_ASSERT_EQUAL( 6,irl.Element(1) );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}
