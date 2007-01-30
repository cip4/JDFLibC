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
// created 10 Aug 2006
//
// JMFTest.cpp: implements CppUnit tests for JMF
//
//////////////////////////////////////////////////////////////////////

#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "jdf/wrapper/JDFRegistration.h"
#include "JMFTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JMFTest);


void JMFTest::setUp()
{
	try	
	{
		PlatformUtils::Initialize();
	}
	catch (const JDF::Exception& e)	
	{
		e.getMessage();
	}
}

void JMFTest::testGetMessageElement()
{
	try
	{
		JDFDoc d(1);
		JDFJMF jmf=d.GetJMFRoot();
		JDFCommand c=(JDFCommand) jmf.appendMessageElement(JDFMessage::Family_Command, JDFMessage::Type_Events );
		CPPUNIT_ASSERT_EQUAL( c.ToString(),jmf.GetMessageElement(JDFMessage::Family_Command,0).ToString() );
		jmf.AppendComment();

		JDFSignal s=(JDFSignal) jmf.appendMessageElement(JDFMessage::Family_Signal, JDFMessage::Type_Events);
		CPPUNIT_ASSERT_EQUAL( s.ToString(),jmf.GetMessageElement(JDFMessage::Family_Signal,0).ToString() );
		CPPUNIT_ASSERT_EQUAL( s.ToString(),jmf.GetMessageElement(JDFMessage::Family_Unknown,1).ToString() );

		JDFSignal s2=(JDFSignal)jmf.appendMessageElement(JDFMessage::Family_Signal, JDFMessage::Type_Status);
		CPPUNIT_ASSERT_EQUAL( s2.ToString(),jmf.GetMessageElement(JDFMessage::Family_Signal,1).ToString() );
		CPPUNIT_ASSERT_EQUAL( s2.ToString(),jmf.GetMessageElement(JDFMessage::Family_Unknown,2).ToString() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JMFTest::testPrivateMessage()
{
	try
	{
		JDFDoc doc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		JDFSignal s=(JDFSignal) jmf.appendMessageElement(JDFMessage::Family_Signal, JDFMessage::Type_Unknown);
		s.SetType("foo:test");
		s.AppendDevice();
		CPPUNIT_ASSERT( !s.GetDevice(0).isNull() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JMFTest::testError()
{
	try
	{
		JDFDoc doc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		JDFResponse r=(JDFResponse) jmf.appendMessageElement(JDFMessage::Family_Response, JDFMessage::Type_Unknown);
		JDFNotification n=r.SetErrorText("blub");
		CPPUNIT_ASSERT_EQUAL( WString("blub"),n.GetComment(0).GetText() );
		CPPUNIT_ASSERT_EQUAL( WString("Error"),n.GetType() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JMFTest::testReturnQueueEntry()
{
	try
	{
		JDFDoc doc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		JDFCommand c=(JDFCommand) jmf.appendMessageElement(JDFMessage::Family_Command, JDFMessage::Type_Unknown);
		c.SetType("ReturnQueueEntry");
		JDFReturnQueueEntryParams rqe=c.AppendReturnQueueEntryParams();
		rqe.SetURL("http://foo.jdf");
		rqe.SetQueueEntryID("dummyID");
		CPPUNIT_ASSERT( rqe.IsValid(KElement::ValidationLevel_Complete) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JMFTest::testJobPhase()
{
	try
	{
		JDFDoc doc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		JDFSignal s=(JDFSignal) jmf.appendMessageElement(JDFMessage::Family_Signal, JDFMessage::Type_Unknown);
		s.SetType("Status");
		JDFStatusQuParams sqp=s.AppendStatusQuParams();
		sqp.SetDeviceDetails(JDFAutoStatusQuParams::DeviceDetails_Brief);
		JDFDeviceInfo di=s.AppendDeviceInfo();
		JDFJobPhase jp=di.AppendJobPhase();
		CPPUNIT_ASSERT_EQUAL( jp.ToString(),di.GetJobPhase(0).ToString() );
		jp=(JDFJobPhase)di.AppendElement("jdf:JobPhase",JDFElement::GetSchemaURL(1,3));
		CPPUNIT_ASSERT_EQUAL( jp.ToString(),di.GetJobPhase(1).ToString() );
		CPPUNIT_ASSERT( di.GetJobPhase(2).isNull() );
		jp.AppendNode();
		CPPUNIT_ASSERT( jp.IsValid(KElement::ValidationLevel_Incomplete) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JMFTest::testDeviceInfo()
{
	try
	{
		JDFDoc doc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		JDFSignal s=(JDFSignal)jmf.appendMessageElement(JDFMessage::Family_Signal, JDFMessage::Type_Unknown);
		s.SetType("Status");
		JDFStatusQuParams sqp=s.AppendStatusQuParams();
		sqp.SetDeviceDetails(JDFAutoStatusQuParams::DeviceDetails_Brief);
		JDFDeviceInfo di=s.AppendDeviceInfo();
		di.SetDeviceStatus(JDFAutoDeviceInfo::DeviceStatus_Unknown);
		JDFJobPhase jp=di.AppendJobPhase();
		CPPUNIT_ASSERT_EQUAL( jp.ToString(),di.GetJobPhase(0).ToString() );
		jp=(JDFJobPhase)di.AppendElement("jdf:JobPhase",JDFElement::GetSchemaURL(1,3));
		CPPUNIT_ASSERT_EQUAL( jp.ToString(),di.GetJobPhase(1).ToString() );
		CPPUNIT_ASSERT( di.GetJobPhase(2).isNull() );
		jp.AppendNode();
		CPPUNIT_ASSERT( jp.IsValid(KElement::ValidationLevel_Incomplete) );
		jp.SetAttribute("Status","fnarf");
		CPPUNIT_ASSERT( !jp.IsValid(KElement::ValidationLevel_Incomplete) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JMFTest::testConvertResponse()
{
	try
	{
		JDFDoc doc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		JDFDoc doc2(1);
		JDFJMF jmf2=doc2.GetJMFRoot();
		JDFSignal s=jmf.AppendSignal(JDFMessage::Type_Unknown);
		JDFResponse r=jmf2.AppendResponse(JDFMessage::Type_Unknown);
		JDF::JDFQuery q=jmf.AppendQuery(JDFMessage::Type_Unknown);
		q.SetType("KnownMessages");
		r.SetQuery(q);
		CPPUNIT_ASSERT_EQUAL( q.GetID(),r.GetrefID() );

		JDFMessageService ms=r.AppendMessageService();
		ms.SetType("KnownMessages");
		s.ConvertResponse(r);
		CPPUNIT_ASSERT_EQUAL( r.GetType(),s.GetType() );
		CPPUNIT_ASSERT( ms.IsEqual(s.GetMessageService(0)) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JMFTest::testMessage()
{
	try
	{
		JDFDoc doc = JDFDoc(1);
		JDFJMF jmf=doc.GetJMFRoot();
		jmf.SetSenderID("Pippi Langstrumpf");

		for (int i=0; i < 7; i++) // JDFMessage::EnumFamily has 7 members
		{
			JDFMessage::EnumFamily f=(JDFMessage::EnumFamily) i;
			if(f==JDFMessage::Family_Unknown)
				continue;
			JDFMessage m=jmf.appendMessageElement(f, JDFMessage::Type_Unknown);
			m.SetType("KnownMessages");

			if (f == JDFMessage::Family_Acknowledge)
			{
				JDFAcknowledge a=(JDFAcknowledge) m;
				a.SetrefID("refID");
			}

			if (f == JDFMessage::Family_Registration)
			{
				JDFRegistration r=(JDFRegistration) m;
				r.AppendSubscription();
			}

			CPPUNIT_ASSERT_EQUAL( 1,(int)jmf.GetMessageVector(f).size() );
			CPPUNIT_ASSERT( jmf.GetMessageElement(f).HasAttribute(JDFNode::atr_xsiType) );
			CPPUNIT_ASSERT_EQUAL( JDFMessage::FamilyString(f).append("KnownMessages"),
				jmf.GetMessageElement(f).GetAttribute(JDFNode::atr_xsiType) );
		}
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
