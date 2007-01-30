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
// created 27 Sep 2006
//
// JDFColorantControlTest.cpp: implements CppUnit tests for JDFColorantControl
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "JDFColorantControlTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFColorantControlTest);


void JDFColorantControlTest::setUp()
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

void JDFColorantControlTest::testSeparationList()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		JDFResourcePool resPool = root.GetCreateResourcePool();
		JDFColorantControl cc = (JDFColorantControl)resPool.AppendResource(JDFElement::elm_ColorantControl,JDFResource::Class_Parameter);
		JDFSeparationList co=cc.AppendColorantOrder();
		vWString seps=WString("Cyan Magenta Yellow Black").Tokenize(WString::whiteSpace);
		co.setSeparations(seps);
		CPPUNIT_ASSERT_EQUAL( (WString)seps,(WString)co.GetSeparations() );
		CPPUNIT_ASSERT_EQUAL( (WString)"Cyan",(WString)co.getSeparation(0) );
		co.removeSeparation("Magenta");
		CPPUNIT_ASSERT_EQUAL( (WString)"Cyan",(WString)co.getSeparation(0) );
		CPPUNIT_ASSERT_EQUAL( (WString)"Yellow",(WString)co.getSeparation(1) );
		CPPUNIT_ASSERT_EQUAL( (WString)"Black",(WString)co.getSeparation(2) );
		CPPUNIT_ASSERT( co.getSeparation(3).empty() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFColorantControlTest::testGetSeparations()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		JDFResourcePool resPool = root.GetCreateResourcePool();
		JDFColorantControl cc = (JDFColorantControl) resPool.AppendResource(JDFElement::elm_ColorantControl, JDFResource::Class_Parameter);
		cc.SetProcessColorModel("DeviceCMYK");
		CPPUNIT_ASSERT( cc.GetSeparations().contains("Cyan") );
		cc.AppendColorantParams().appendSeparation("Snarf Blue");
		CPPUNIT_ASSERT( cc.GetSeparations().contains("Snarf Blue") );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFColorantControlTest::testColorantParams()
{
	try
	{
        // Jira EDITOR-58 ColorantParams does not need a SeparationSpec element (optional)
        JDFDoc doc = JDFDoc(0);
		JDFNode elem = doc.GetJDFRoot();
        JDFResourcePool rpool = elem.AppendResourcePool();
        JDFColorantControl colControl = (JDFColorantControl) 
			rpool.AppendResource(JDFElement::elm_ColorantControl, JDFResource::Class_Parameter);
        JDFSeparationList colParams = colControl.AppendColorantParams();
        
		CPPUNIT_ASSERT( colParams.IsValid(KElement::ValidationLevel_RecursiveComplete) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
