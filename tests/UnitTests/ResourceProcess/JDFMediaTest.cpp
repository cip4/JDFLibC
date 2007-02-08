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
// created 06 Oct 2006
//
// JDFMediaTest.cpp: implements CppUnit tests for JDFMedia
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "JDFMediaTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFMediaTest);


void JDFMediaTest::setUp()
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


void JDFMediaTest::testSetGetDimension()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		JDFResourcePool resPool = root.GetCreateResourcePool();
		JDFMedia media = (JDFMedia)resPool.AppendResource(JDFNode::elm_Media, JDFResource::Class_Consumable);

		media.SetDimensionCM(JDFXYPair(2.54, 2.54));

		JDFXYPair result = media.GetDimension();
		CPPUNIT_ASSERT_EQUAL( result,JDFXYPair(72,72) );

		result = media.GetDimensionCM();
		CPPUNIT_ASSERT_EQUAL( result,JDFXYPair(2.54,2.54) );

		result = media.GetDimensionInch();
		CPPUNIT_ASSERT_EQUAL( result,JDFXYPair(1,1) );


		media.SetDimensionInch(JDFXYPair(1, 1));

		result = media.GetDimension();
		CPPUNIT_ASSERT_EQUAL( result,JDFXYPair(72,72) );

		result = media.GetDimensionCM();
		CPPUNIT_ASSERT_EQUAL( result,JDFXYPair(2.54, 2.54) );

		result = media.GetDimensionInch();
		CPPUNIT_ASSERT_EQUAL( result,JDFXYPair(1,1) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFMediaTest::testHoleType()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		JDFResourcePool resPool = root.GetCreateResourcePool();

		// check HoleType for JDFMedia
		JDFMedia media = (JDFMedia)resPool.AppendResource(JDFNode::elm_Media, JDFResource::Class_Consumable);

		vint v;
		v.add(JDFMedia::HoleType_None);
		v.add(JDFMedia::HoleType_C9_5m_round_0t);
		CPPUNIT_ASSERT_EQUAL( (WString)"C9.5m-round-0t",JDFMedia::HoleTypeString(JDFMedia::HoleType_C9_5m_round_0t) );

		media.SetHoleType(v);
		CPPUNIT_ASSERT_EQUAL( v.GetString(),media.GetHoleType().GetString() );
		CPPUNIT_ASSERT_EQUAL( (int)v[1],(int)media.GetHoleType()[1] );
		CPPUNIT_ASSERT_EQUAL( (WString)"C9.5m-round-0t",
			JDFMedia::HoleTypeString((JDFMedia::EnumHoleType)media.GetHoleType()[1]) );

		// overwrite HoleType low level to check if conversion of DOT and HYPHEN to UNDERSCORE was successful
		media.SetAttribute(JDFNode::atr_HoleType, "C9.5m-round-0t");
		CPPUNIT_ASSERT_EQUAL( JDFMedia::HoleType_C9_5m_round_0t,(JDFMedia::EnumHoleType)media.GetHoleType()[0] );

		// now check the same with JDFHoleMakingParams
		JDFHoleMakingParams holeMakingParams = (JDFHoleMakingParams)resPool.AppendResource(JDFNode::elm_HoleMakingParams, JDFResource::Class_Consumable);

		holeMakingParams.SetHoleType(v);  // TODO Fehler in JDFAutoHoleMakingParams::HoleTypeString() -> enums fehlen
		CPPUNIT_ASSERT_EQUAL( v.GetString(),holeMakingParams.GetHoleType().GetString() );
		CPPUNIT_ASSERT_EQUAL( (int)v[1],(int)holeMakingParams.GetHoleType()[1] );
		CPPUNIT_ASSERT_EQUAL( (WString)"C9.5m-round-0t",
			JDFHoleMakingParams::HoleTypeString((JDFHoleMakingParams::EnumHoleType)holeMakingParams.GetHoleType()[1]) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
