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
// JDFDateTest.cpp: implements CppUnit tests for JDFDate
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "JDFDateTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFDateTest);

void JDFDateTest::setUp()
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

void JDFDateTest::testBadDate()
{
	try
	{
		try
		{
			JDFDate date = JDFDate("1999+09-26T11:43:10+03:00");
			CPPUNIT_ASSERT( date != JDFDate(0) ); // fool compiler
			CPPUNIT_FAIL( "shouldn't go here - date exception" );
		}
		catch ( JDF::IllegalArgumentException& )
		{
			// expected to throw exception
		}
		try
		{
			JDFDate date = JDFDate("1999");
			WString strDate = date.DateTimeISO();
			CPPUNIT_ASSERT_EQUAL( (WString)"1999-09-26T11:43:10+03:00",strDate );
			CPPUNIT_FAIL( "shouldn't go here - date exception" );
		}
		catch ( JDF::IllegalArgumentException& )
		{
			// expected to throw exception
		}
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDateTest::testdateTimeISO()
{
	cout << endl << "note: a JDFDate is converted to the local time zone by its constructor. Tests are for GMT +1.";
	JDFDate date = JDFDate();
	WString strDate = date.DateTimeISO();
	try
	{
		// summer
		date = JDFDate("1999-09-26T11:43:10+03:00");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-09-26T09:43:10+01:00",strDate );

		date = JDFDate("1999-09-26T11:43:10-03:00");
		strDate = date.DateTimeISO();		
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-09-26T15:43:10+01:00",strDate );

		// winter
		date = JDFDate("1999-11-26T11:43:10+03:00");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T09:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10-03:00");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T15:43:10+01:00",strDate );

		// note the various A,c zulu etc times below
		date = JDFDate("1999-11-26T11:43:10a");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T11:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10C");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T09:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10Z");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T12:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10i");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T03:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10K");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T02:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10M");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T00:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10N");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T13:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10V");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T21:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10W");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T22:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10Y");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-27T00:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10.123Y");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-27T00:43:10+01:00",strDate );

		date = JDFDate("1999-11-26T11:43:10.12345-03:00");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"1999-11-26T15:43:10+01:00",strDate );

		date = JDFDate("2004-11-26T11:43:10.-03:00");
		strDate = date.DateTimeISO();
		CPPUNIT_ASSERT_EQUAL( (WString)"2004-11-26T15:43:10+01:00",strDate );

	}
	catch ( JDFException& e )
	{
		CPPUNIT_FAIL( e.what() );
	}
	catch ( JDF::IllegalArgumentException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
