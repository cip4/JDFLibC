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
// JDFShapeRangeListTest.cpp: implements CppUnit tests for JDFRectangle/JDFAttributeMap
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFShapeRangeListTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFShapeRangeListTest);


void JDFShapeRangeListTest::setUp()
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

void JDFShapeRangeListTest::testAppendJDFShapeRange()
{
	try
	{
		JDFShapeRangeList rangeList;
		try 
		{
			rangeList = JDFShapeRangeList("0 0 3 1 2 3~4 5 6 4 2 3~4 5 6");
			rangeList.Append(JDFShapeRange("7.5 8.5 9.5"));
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}

		CPPUNIT_ASSERT_EQUAL( (WString)"0 0 3 1 2 3 ~ 4 5 6 4 2 3 ~ 4 5 6 7.5 8.5 9.5",rangeList.GetString() );
		CPPUNIT_ASSERT_EQUAL( 4,rangeList.size() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testSetString()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist = JDFShapeRangeList("1 2 3 ~ 4 5 6   1.55 3.75 5.85");
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}

		// rangeList is not empty
		CPPUNIT_ASSERT_EQUAL( 2,rangelist.size() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testInRange()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist= JDFShapeRangeList("1 2 3 ~ 4 5 6  7 8 9~10 11 12");
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}
		CPPUNIT_ASSERT( rangelist.InRange(JDFShape(3,4,5)) );
		CPPUNIT_ASSERT( rangelist.InRange(JDFShape(4,5,6)) );
		CPPUNIT_ASSERT( !rangelist.InRange(JDFShape(6,7,8)) );
		CPPUNIT_ASSERT( !rangelist.InRange(JDFShape(10,12,12)) );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testIsPartOfRange()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist= JDFShapeRangeList("1 2 3 ~ 4 5 6  7 8 9~10 11 12");
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}
		CPPUNIT_ASSERT( rangelist.IsPartOfRange(JDFShapeRange(JDFShape(3,4,5),JDFShape(4,5,6))) );
		CPPUNIT_ASSERT( rangelist.IsPartOfRange(JDFShapeRange(JDFShape(9,9,9),JDFShape(10,10,10))) );
		CPPUNIT_ASSERT( !rangelist.IsPartOfRange(JDFShapeRange(JDFShape(9,9,9),JDFShape(12,12,12))) );
		CPPUNIT_ASSERT( !rangelist.IsPartOfRange(JDFShapeRange(JDFShape(4,5,6),JDFShape(7,8,9))) );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testIsList_False()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist = JDFShapeRangeList("0 0 4");
			rangelist.Append(JDFShapeRange(JDFShape("0 0 5"),JDFShape("0 0 6")));
			rangelist.Append(JDFShape("0 0 6"));
			rangelist.Append(JDFShape("0 0 7"));
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}

		CPPUNIT_ASSERT( !rangelist.IsList() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testIsUnique_False()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist= JDFShapeRangeList("0 0 4");
			rangelist.Append(JDFShapeRange(JDFShape("0 0 5"),JDFShape("0 0 6")));
			rangelist.Append(JDFShape("0 0 5.5")); // in "0 0 5 ~ 0 0 6"
			rangelist.Append(JDFShape("0 0 7"));
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}

		CPPUNIT_ASSERT( !rangelist.IsUnique() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testIsOrdered_False()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist = JDFShapeRangeList("0 0 4");
			rangelist.Append(JDFShape("0 0 5"));
			rangelist.Append(JDFShapeRange(JDFShape("0 0 5.5"),JDFShape("0 0 6")));
			rangelist.Append(JDFShape("0 0 5"));
			rangelist.Append(JDFShape("0 0 7"));
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}

		CPPUNIT_ASSERT( !rangelist.IsOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testIsOrdered_Reverse_True()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist = JDFShapeRangeList("0 0 7");
			rangelist.Append(JDFShape(0,0,5));
			rangelist.Append(JDFShapeRange("0 0 4~0 0 2"));
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}

		CPPUNIT_ASSERT( rangelist.IsOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testIsUniqueOrdered_Reverse_False()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist = JDFShapeRangeList("0 0 7");
			rangelist.Append(JDFShape("0 0 5"));
			rangelist.Append(JDFShapeRange("0 0 4~0 0 2"));
			rangelist.Append(JDFShape("0 0 5"));
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}

		CPPUNIT_ASSERT( !rangelist.IsUniqueOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void JDFShapeRangeListTest::testIsUniqueOrdered_True()
{
	try
	{
		JDFShapeRangeList rangelist;
		try 
		{
			rangelist = JDFShapeRangeList("0 0 4");
			rangelist.Append(JDFShape("0 0 5"));
			rangelist.Append(JDFShapeRange(JDFShape("0 0 5.5"),JDFShape("0 0 6")));
			rangelist.Append(JDFShape("0 0 7"));
		}
		catch ( ... )
		{
			CPPUNIT_FAIL( "constructor/append failed" );
		}

		CPPUNIT_ASSERT( rangelist.IsUniqueOrdered() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}
