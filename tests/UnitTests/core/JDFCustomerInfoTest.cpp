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
// JDFCustomerInfoTest.cpp: implements CppUnit tests for JDFCustomerInfo
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "JDFCustomerInfoTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFCustomerInfoTest);

const WString sm_dirTestData = L"data/";
const WString sm_dirTestTemp = L"temp/";

static JDFCustomerInfo prepareInfo(JDFDoc doc)
{
	JDFNode n=doc.GetJDFRoot();
	JDFCustomerInfo info = n.AppendCustomerInfo();
	vWString vct;
	vct.add("Customer");
	info.AppendContact().SetContactTypes(vct);
	vct.add("Administrator");
	info.AppendContact().SetContactTypes(vct);
	JDFContact c=info.AppendContact();
	vct.clear();
	vct.add("Delivery");
	c.SetContactTypes(vct);
	c.MakeRootResource();
	vct.add("Customer");
	info.AppendContact().SetContactTypes(vct);
	return info;
}

void JDFCustomerInfoTest::setUp()
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

void JDFCustomerInfoTest::testgetContactVector()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
        JDFCustomerInfo info=prepareInfo(doc);
        
        vElement v;
		info = doc.GetJDFRoot().GetCustomerInfo();
		if ( !info.isNull() )
        {
			v = info.GetChildElementVector(JDFNode::elm_Contact);
			CPPUNIT_ASSERT_EQUAL( 4,(int)v.size() );
        }

        
		v.clear();
		info = doc.GetJDFRoot().GetCustomerInfo();
		if (!info.isNull())
        {
			v = info.GetChildElementVector(JDFNode::elm_Contact);
            CPPUNIT_ASSERT_EQUAL( 4,(int)v.size() );
        }
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFCustomerInfoTest::testGetContactWithContactType()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
        JDFCustomerInfo info=prepareInfo(doc);
        
        JDFContact cc = info.GetContactWithContactType("Customer", 0);
		CPPUNIT_ASSERT( !cc.isNull() );
        cc = info.GetContactWithContactType("Customer", 2);
        CPPUNIT_ASSERT( !cc.isNull() );
        cc = info.GetContactWithContactType("Customer", 1);
        CPPUNIT_ASSERT( !cc.isNull() );
        JDFContact cc2 = info.GetContactWithContactType("Administrator", 0);
        CPPUNIT_ASSERT( !cc.isNull() );
		CPPUNIT_ASSERT_EQUAL( cc,cc2 );
        cc = info.GetContactWithContactType("Delivery", 0);
        CPPUNIT_ASSERT( !cc.isNull() );
        cc = info.GetContactWithContactType("fnarf", 0);
        CPPUNIT_ASSERT( cc.isNull() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFCustomerInfoTest::testGetContactVectorWithContactType()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
        JDFCustomerInfo info=prepareInfo(doc);
        
        vElement v = info.getContactVectorWithContactType("Customer");
		CPPUNIT_ASSERT( !v.empty() );
		CPPUNIT_ASSERT_EQUAL( 3,(int)v.size() );
        v = info.getContactVectorWithContactType("Administrator");
		CPPUNIT_ASSERT_EQUAL( 1,(int)v.size() );
        v = info.getContactVectorWithContactType("beagle");
		CPPUNIT_ASSERT( v.empty() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
