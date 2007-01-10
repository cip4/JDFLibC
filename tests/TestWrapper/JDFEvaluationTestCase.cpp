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
// JDFEvaluationTestCase.cpp: implements CppUnit tests for JDF data formats
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFEvaluationTestCase.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFEvaluationTestCase);


void JDFEvaluationTestCase::setUp()
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

void JDFEvaluationTestCase::testIntegerEvaluation()
{
	try
	{
		XMLDoc d(JDFStrings::elm_IntegerEvaluation);
		JDFIntegerEvaluation ie=(JDFIntegerEvaluation)d.GetRoot();
		ie.appendValueList(1);
		CPPUNIT_ASSERT_EQUAL( WString("1"), WString(ie.GetAttribute(JDFStrings::atr_ValueList)) );
		ie.appendValueList(3);
		CPPUNIT_ASSERT_EQUAL( WString("1 3"), WString(ie.GetAttribute(JDFStrings::atr_ValueList)) );
		ie.appendValueList(4);
		CPPUNIT_ASSERT_EQUAL( WString("1 3 ~ 4"), WString(ie.GetAttribute(JDFStrings::atr_ValueList)) );
		ie.appendValueList(5);
		CPPUNIT_ASSERT_EQUAL( WString("1 3 ~ 5"), WString(ie.GetAttribute(JDFStrings::atr_ValueList)) );
		ie.appendValueList(WString::pINF);
		
		CPPUNIT_ASSERT_EQUAL( WString("1 3 ~ 5 INF"), ie.GetAttribute(JDFStrings::atr_ValueList) );
		CPPUNIT_ASSERT_EQUAL( JDFIntegerRangeList("1 3 ~ 5 INF").GetString(), ie.GetValueList().GetString() );
	}
	catch (JDF::Exception e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFEvaluationTestCase::testSetTolerance()
{
	try
	{
		XMLDoc d(JDFStrings::elm_XYPairEvaluation);
		JDFXYPairEvaluation ie=(JDFXYPairEvaluation)d.GetRoot();
		ie.SetTolerance( JDFXYPair(1,1) );
		CPPUNIT_ASSERT_EQUAL(WString("1 1"), WString(ie.GetTolerance()));
		ie.SetValueList(JDFXYPairRangeList(JDFXYPair(1.5, 1.5)));
		ie.appendBasicPreflightTest(L"foo");
		CPPUNIT_ASSERT( ie.FitsMap(JDFAttributeMap("foo", "1.2 1.6")) );
	}
	catch (JDF::JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
