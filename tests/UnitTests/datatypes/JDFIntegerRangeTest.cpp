/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
// JDFIntegerRangeTest.cpp: implements CppUnit tests for JDFIntegerRange
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFIntegerRangeTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFIntegerRangeTest);


void JDFIntegerRangeTest::setUp()
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

void JDFIntegerRangeTest::testJDFIntegerRangeString()
{
	try
	{
		JDFIntegerRange range;
        try
        {
            range = JDFIntegerRange(" 0 ~ 1 ");
        }
        catch ( ... )
        {
            CPPUNIT_FAIL( "bad constructor from a given string" );
        }
        
        // rangeList is not empty
		CPPUNIT_ASSERT( (int)range.GetString().size()!=0 );
        // must be transformed into the string "0~1"
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 1",range.GetString() ); 
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeTest::testAppend()
{
	try
	{
		JDFIntegerRange range;
		try
		{
			range = JDFIntegerRange(" 0 ~ 1 ");
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "bad constructor from a given string" );
		}

		// rangeList is not empty
		CPPUNIT_ASSERT( (int)range.GetString().size()!=0 );
        // must be transformed into the string "0~1"
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 1",range.GetString() ); 
		CPPUNIT_ASSERT( !range.Append(4) );
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 1",range.GetString() );
		CPPUNIT_ASSERT( !range.Append(-5) );
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 1",range.GetString() );
		CPPUNIT_ASSERT( range.Append(2) );
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 2",range.GetString() );
		CPPUNIT_ASSERT( !range.Append(2) );
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 2",range.GetString() );
		CPPUNIT_ASSERT( !range.Append(1) );
		CPPUNIT_ASSERT_EQUAL( (WString)"0 ~ 2",range.GetString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeTest::testCopyConstructor()
{
	try
	{
        JDFIntegerRange range = JDFIntegerRange(4,-1,8);
        CPPUNIT_ASSERT( range.InRange(4) );
        CPPUNIT_ASSERT( !range.InRange(3));
        CPPUNIT_ASSERT( range.InRange(7));
        CPPUNIT_ASSERT( !range.InRange(8));
        JDFIntegerRange range2 = JDFIntegerRange(range);
        CPPUNIT_ASSERT( range2.InRange(4) );
        CPPUNIT_ASSERT( !range.InRange(3) );
        CPPUNIT_ASSERT( range2.InRange(7) );
        CPPUNIT_ASSERT( !range2.InRange(8) );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFIntegerRangeTest::testDefaultDef()
{
	try
	{
		JDFIntegerRange::setDefaultDef(8);
        JDFIntegerRange range = JDFIntegerRange(4,-1);
        CPPUNIT_ASSERT( range.InRange(4) );
        CPPUNIT_ASSERT( !range.InRange(3));
        CPPUNIT_ASSERT( range.InRange(7));
        CPPUNIT_ASSERT( !range.InRange(8));
		JDFIntegerRange::setDefaultDef(0);
        CPPUNIT_ASSERT( range.InRange(4) );
        CPPUNIT_ASSERT( range.InRange(3));
        CPPUNIT_ASSERT( !range.InRange(7));
        CPPUNIT_ASSERT( !range.InRange(8));
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}
