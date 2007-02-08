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
// created before 21 Jul 2006
//
// JDFDateTimeRangeTest.cpp: implements CppUnit tests for JDFDateTime
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFDateTimeRangeTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFDateTimeRangeTest);


void JDFDateTimeRangeTest::setUp()
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

void JDFDateTimeRangeTest::testJDFDateTimeRange()
{
	try
	{
		JDFDateTimeRange r = JDFDateTimeRange(JDFDate("2004-12-01T09:30:00Z"), 
			JDFDate("2004-12-01T09:35:00Z"));

		JDFDateTimeRange test_r = JDFDateTimeRange("2004-12-01T09:30:00Z ~ 2004-12-01T09:35:00Z");
		CPPUNIT_ASSERT_EQUAL( r.GetString(),test_r.GetString() );

		int duration = (int) ( (test_r.GetRight().GetSecondsSince1970() - test_r.GetLeft().GetSecondsSince1970()) );
		JDFDuration d;
		d.SetDuration(duration);
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
	catch ( ... )
	{
		CPPUNIT_FAIL( "caught non-JDF exception" );
	}
}

void JDFDateTimeRangeTest::testInRange()
{
	try
	{
		JDFDateTimeRangeList rangeList = 
			JDFDateTimeRangeList("2004-11-30T09:30:00Z ~ 2004-12-05T09:00:00Z");

		CPPUNIT_ASSERT( rangeList.InRange(JDFDate("2004-12-05T08:30:00Z")) );
		CPPUNIT_ASSERT( rangeList.InRange(JDFDate("2004-12-05T09:00:00Z")) );
		CPPUNIT_ASSERT( !rangeList.InRange(JDFDate("2004-12-05T09:35:00Z")) );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
	catch ( ... )
	{
		CPPUNIT_FAIL( "caught non-JDF exception" );
	}
}
