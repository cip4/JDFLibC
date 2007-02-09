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
// created before 27 Jul 2006
//
// JDFAuditTestCase.cpp: implements CppUnit test cases for JDFAudit
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "JDFAuditTestCase.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFAuditTestCase);

void JDFAuditTestCase::setUp()
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

void JDFAuditTestCase::testInit()
{
	try
	{
		JDFDoc d(0);	
		JDFNode n=d.GetRoot();
		n.SetType((WString)"ConventionalPrinting");
		JDFAuditPool ap=n.GetAuditPool();
		CPPUNIT_ASSERT( !ap.isNull() );
		JDFCreated crea=(JDFCreated)ap.GetAudit(0, JDFAudit::AuditType_Created, mAttribute::emptyMap);
		CPPUNIT_ASSERT( crea.HasAttribute((WString)"ID", WString::emptyStr, false) );
		n.SetEnumVersion(JDFElement::Version_1_2);
		JDFModified mod=ap.AddModified((WString)"me",n);
		CPPUNIT_ASSERT( !mod.HasAttribute((WString)"me", WString::emptyStr, false) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFAuditTestCase::testFixVersion()
{
	try
	{
		JDFDoc d(0);
		JDFNode n=d.GetRoot();
		n.SetType((WString)"ConventionalPrinting");
		JDFAuditPool ap=n.GetAuditPool();
		CPPUNIT_ASSERT( !ap.isNull() );
		JDFCreated crea=(JDFCreated)ap.GetAudit(0, JDFAudit::AuditType_Created, mAttribute::emptyMap);
		CPPUNIT_ASSERT( crea.HasAttribute((WString)"ID", WString::emptyStr, false) );
		n.FixVersion(JDFElement::Version_1_2);
		CPPUNIT_ASSERT( !crea.HasAttribute((WString)"ID", WString::emptyStr, false) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}


void JDFAuditTestCase::testSetStaticAgentVersion()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("ConventionalPrinting");
		JDFAuditPool ap=n.GetAuditPool();
		CPPUNIT_ASSERT( !ap.isNull() );
		JDFCreated crea=(JDFCreated) ap.GetAudit(0, JDFAudit::AuditType_Created);
		CPPUNIT_ASSERT_EQUAL( JDFAudit::getStaticAgentName(),crea.GetAgentName() );

		// backup StaticAgentName/Version
		WString stdAgentName = JDFAudit::getStaticAgentName();
		WString stdAgentVersion = JDFAudit::getStaticAgentVersion();

		JDFAudit::setStaticAgentName(WString::emptyStr);
		JDFAudit::setStaticAgentVersion(WString::emptyStr);
		d=JDFDoc(0);
		n=d.GetJDFRoot();
		n.SetType("ConventionalPrinting");
		ap=n.GetAuditPool();
		CPPUNIT_ASSERT( !ap.isNull() );
		crea=(JDFCreated) ap.GetAudit(0, JDFAudit::AuditType_Created);
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr,crea.GetAgentName() );
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr,crea.GetAgentVersion() );
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr,crea.GetAuthor() );

		// restore old values for following tests
		JDFAudit::setStaticAgentName(stdAgentName);
		JDFAudit::setStaticAgentVersion(stdAgentVersion);
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFAuditTestCase::testSetStaticAgentName()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();
		
		JDFMedia m = root.addResource(JDFResource::elm_Media, JDFResource::Class_Consumable, JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT( m.HasAttribute(JDFMedia::atr_AgentName) );
		CPPUNIT_ASSERT( m.HasAttribute(JDFMedia::atr_AgentVersion) );
		// backup agent name and version
		const WString origStaticAgentName = m.GetAgentName();
		const WString origStaticAgentVersion = m.GetAgentVersion();

		JDFAudit::setStaticAgentName(WString::emptyStr);
		m = root.addResource(JDFResource::elm_Media, JDFResource::Class_Consumable, JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT( !m.HasAttribute(JDFMedia::atr_AgentName) );
		CPPUNIT_ASSERT( m.HasAttribute(JDFMedia::atr_AgentVersion) );
		m.SetAgentName("me");
		CPPUNIT_ASSERT_EQUAL( (WString)"me",m.GetAgentName() );

		JDFAudit::setStaticAgentName(origStaticAgentName);
		JDFAudit::setStaticAgentVersion(WString::emptyStr);
		m = root.addResource(JDFResource::elm_Media, JDFResource::Class_Consumable, JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT_EQUAL( origStaticAgentName,m.GetAgentName() );
		CPPUNIT_ASSERT( !m.HasAttribute(JDFMedia::atr_AgentVersion) );
		m.SetAgentVersion("v64357");
		CPPUNIT_ASSERT_EQUAL( origStaticAgentName,m.GetAgentName() );
		CPPUNIT_ASSERT_EQUAL( (WString)"v64357",m.GetAgentVersion() );

		// restore original agent name and version
		JDFAudit::setStaticAgentName(origStaticAgentName);
		JDFAudit::setStaticAgentVersion(origStaticAgentVersion);
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
