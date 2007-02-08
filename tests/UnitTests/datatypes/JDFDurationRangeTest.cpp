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
// created before 17 Oct 2006
//
// JDFDurationRangeTest.cpp: implements CppUnit tests for JDFDuration
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFDurationRangeTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFDurationRangeTest);


void JDFDurationRangeTest::setUp()
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

void JDFDurationRangeTest::testJDFDurationRangeJDFDuration()
{
	try
	{
		JDFDurationRange r, r2;

		try
		{
			r  = JDFDurationRange(JDFDuration("PT5M"), JDFDuration("PT15M"));
			r2 = JDFDurationRange(JDFDuration("PT5M"));
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "bad duration" );
		}
		CPPUNIT_ASSERT_EQUAL( (WString)"PT5M ~ PT15M",r.GetString() );
		CPPUNIT_ASSERT_EQUAL( (WString)"PT5M",r2.GetString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}	
}

void JDFDurationRangeTest::testJDFDurationRangeJDFDurationRange()
{
	try
	{
		JDFDurationRange r, r2;
		try
		{
			r = JDFDurationRange(JDFDuration("PT15M"));
			r2 = JDFDurationRange(r);
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "bad duration/copy constructor" );
		}
		CPPUNIT_ASSERT_EQUAL( r.GetString(),r2.GetString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}	
}

void JDFDurationRangeTest::testJDFDurationRangeString()
{
	try
	{
		JDFDurationRange r;
		try
		{
			r = JDFDurationRange(" PT5M ~ PT15M ");
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "bad duration/constructor" );
		}

		CPPUNIT_ASSERT_EQUAL( (WString)"PT5M ~ PT15M",r.GetString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}	
}

void JDFDurationRangeTest::testInRange()
{
	try
	{
		JDFDurationRangeList rangeList = 
			JDFDurationRangeList("PT5M ~ PT15M  PT1H5M ~ PT1H15M");

		CPPUNIT_ASSERT( rangeList.InRange(JDFDuration("PT15M")) );
		CPPUNIT_ASSERT( rangeList.InRange(JDFDuration("PT1H15M")) );
		CPPUNIT_ASSERT( !rangeList.InRange(JDFDuration("PT1H25M")) );
		CPPUNIT_ASSERT( !rangeList.InRange(JDFDuration("PT55S")) );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
	catch ( ... )
	{
		CPPUNIT_FAIL( "bad duration/constructor" );
	}
}

void JDFDurationRangeTest::testJDFDuration()
{
	// note: JDFLibC is not as restrictive on valid duration strings as JDFLibJ. 
	//       Nevertheless, the calculation of the duration is correct.
	try
	{
		JDFDuration d, d1, d2, d3;     
        JDFDuration p1, p2 ,p3;
        
        try
        {
            d = JDFDuration("PT5M");
        }
        catch ( IllegalArgumentException& ex )
        {
			CPPUNIT_FAIL( ex.what() );
        }
        
        try
        {
            d1 = JDFDuration("PT50M");
        }
        catch ( IllegalArgumentException& ex )
        {
			CPPUNIT_FAIL( ex.what() );
        }
        
        try
        {
            d2 = JDFDuration("P0T5M");
        }
        catch ( IllegalArgumentException& ex )
        {
			CPPUNIT_FAIL( ex.what() );
        }
        
        try
        {
            d3 = JDFDuration("PT5MS");
        }
        catch ( IllegalArgumentException& ex )
        {
			CPPUNIT_FAIL( ex.what() );
        }
        
        try
        {
            p1 = JDFDuration("P1Y2M3DT50M");
        }
        catch ( IllegalArgumentException& ex )
        {
			CPPUNIT_FAIL( ex.what() );
        }
        
        try
        {
            p1 = JDFDuration("P01Y02M03DT50M");
        }
        catch ( IllegalArgumentException& ex )
        {
			CPPUNIT_FAIL( ex.what() );
        }
        
        try
        {
            p2 = JDFDuration("P01Y02M03D");
        }
        catch ( IllegalArgumentException& ex )
        {
			CPPUNIT_FAIL( ex.what() );
        }
        
        try
        {
            p3 = JDFDuration("P1Y2M3DT10H30M");
        }
        catch ( IllegalArgumentException& ex )
        {
			CPPUNIT_FAIL( ex.what() );
        }
        CPPUNIT_ASSERT_EQUAL( 300.,d.getDuration() );
        CPPUNIT_ASSERT_EQUAL( 3000.,d1.getDuration() );
        CPPUNIT_ASSERT_EQUAL( 300.,d2.getDuration() );
        CPPUNIT_ASSERT_EQUAL( 300.,d3.getDuration() );
		CPPUNIT_ASSERT_EQUAL( (WString)"P1Y2M3DT50M",p1.DurationISO() );
		CPPUNIT_ASSERT_EQUAL( (WString)"P1Y2M3D",p2.DurationISO() );
		CPPUNIT_ASSERT_EQUAL( (WString)"P1Y2M3DT10H30M",p3.DurationISO() );
	}
	catch (JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}
