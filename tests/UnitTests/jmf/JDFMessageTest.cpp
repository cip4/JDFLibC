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
// created 10 Oct 2006
//
// JDFMessageTest.cpp: implements CppUnit tests for JDFMessage
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFRegistration.h"
#include "JDFMessageTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFMessageTest);


void JDFMessageTest::setUp()
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

void JDFMessageTest::testIsValidMessageElement()
{
	try
	{
        JDFDoc doc = JDFDoc(1);
        JDFJMF jmf=doc.GetJMFRoot();
		JDFSignal sig=(JDFSignal) jmf.appendMessageElement(JDFMessage::Family_Signal,JDFMessage::Type_UpdateJDF);
		CPPUNIT_ASSERT( sig.GetValidElement("UpdateJDFCmdParams").isNull() );
		bool hasFailed = false;
		try
		{
			sig.GetValidElement("ModifyNodeCmdParams");
			hasFailed = true;
		}
		catch ( ... )
		{
			// expected to fail
		}
		CPPUNIT_ASSERT( !hasFailed );


		JDFResponse resp=(JDFResponse) jmf.appendMessageElement(JDFMessage::Family_Response,JDFMessage::Type_RepeatMessages);
		CPPUNIT_ASSERT( resp.GetValidElement(JDFNode::elm_Signal,WString::emptyStr,3).isNull() );
		CPPUNIT_ASSERT( resp.GetValidElement(JDFNode::elm_Registration,WString::emptyStr,3).isNull() );
		try
		{
			resp.GetValidElement(JDFNode::elm_Queue);
			hasFailed = true;
		}
		catch ( ... )
		{
			// expected to fail
		}
		CPPUNIT_ASSERT( !hasFailed );

		JDFRegistration reg=(JDFRegistration) jmf.appendMessageElement(JDFMessage::Family_Registration,JDFMessage::Type_RepeatMessages);
		try
		{
			reg.GetValidElement(JDFNode::elm_Signal,WString::emptyStr,3);
			hasFailed = true;
		}
		catch (JDFException)
		{
			// expected to fail
		}
		CPPUNIT_ASSERT( !hasFailed );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFMessageTest::testAppendValidElement()
{
	try
	{
		JDFDoc doc = JDFDoc(1);
        JDFJMF jmf=doc.GetJMFRoot();
		JDFSignal sig=(JDFSignal) jmf.appendMessageElement(JDFMessage::Family_Signal,JDFMessage::Type_UpdateJDF);
		CPPUNIT_ASSERT( !sig.AppendValidElement("UpdateJDFCmdParams").isNull() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFMessageTest::testSetType()
{
	try
	{
		JDFDoc doc = JDFDoc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		JDFCommand command=(JDFCommand) jmf.appendMessageElement(JDFMessage::Family_Command,JDFMessage::Type_UpdateJDF);
		CPPUNIT_ASSERT_EQUAL( (WString)"CommandUpdateJDF",command.getXSIType() );
		command.SetType("foo:bar");
		CPPUNIT_ASSERT( command.getXSIType().empty() );
		CPPUNIT_ASSERT_EQUAL( (WString)"foo:bar",command.GetType() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
