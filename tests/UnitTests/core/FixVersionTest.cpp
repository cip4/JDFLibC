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
// created 02 Aug 2006
//
// FixVersionTest.cpp: implements CppUnit tests for JDFNode::FixVersion
//
//////////////////////////////////////////////////////////////////////
#pragma once

#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "jdf/wrapper/JDFApprovalDetails.h"
#include "jdf/wrapper/AutoJDF/JDFAutoApprovalDetails.h"
#include "FixVersionTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (FixVersionTest);

void FixVersionTest::setUp()
{
	try	
	{
		JDF::PlatformUtils::Initialize();
	}
	catch (const JDF::Exception& e)	
	{
		e.getMessage();
	}

	mDoc=JDFDoc(0);
	n=(JDFNode)mDoc.GetRoot();
}

void FixVersionTest::testApprovalSuccess()
{
	try
	{		
		n.SetType("Approval");
		JDFApprovalSuccess as=(JDFApprovalSuccess)n.AppendMatchingResource(JDFStrings::elm_ApprovalSuccess, JDFNode::ProcessUsage_AnyOutput);		
		n.SetEnumVersion(JDFNode::Version_1_2);
		as.AppendContact();
		as.AppendFileSpec();
		bool bRet=n.FixVersion(JDFNode::Version_1_3);
		CPPUNIT_ASSERT_MESSAGE( "fix ok", bRet );
		CPPUNIT_ASSERT( !as.GetApprovalDetails(0).isNull() );
		bRet=n.FixVersion(JDFNode::Version_1_2);
		CPPUNIT_ASSERT_MESSAGE( "fix ok", bRet );
		CPPUNIT_ASSERT( as.GetApprovalDetails(0).isNull() );
		bRet=n.FixVersion(JDFNode::Version_1_3);
		CPPUNIT_ASSERT_MESSAGE( "fix ok", bRet );
		as=(JDFApprovalSuccess)n.GetMatchingResource(JDFStrings::elm_ApprovalSuccess, JDFNode::ProcessUsage_AnyOutput);
		JDF::JDFApprovalDetails ad=as.GetApprovalDetails(0);
		ad.SetApprovalState(JDF::JDFAutoApprovalDetails::ApprovalState_Rejected);
		bRet=n.FixVersion(JDFNode::Version_1_2);
		CPPUNIT_ASSERT_MESSAGE( "fix not ok", !bRet );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void FixVersionTest::testRRefs()
{
	JDFResourcePool rp=n.AppendResourcePool();
	rp.SetAttribute(JDFStrings::atr_rRefs,"a b");
	n.FixVersion(JDFElement::Version_Unknown);
	CPPUNIT_ASSERT( !rp.HasAttribute(JDFStrings::atr_rRefs) );
}

void FixVersionTest::testAudit()
{
	JDFAuditPool ap=n.GetAuditPool();
	CPPUNIT_ASSERT( !ap.isNull() );
	JDFCreated crea=(JDFCreated) ap.GetAudit(0,JDFAudit::AuditType_Created);
	WString agent=crea.GetAgentName();
	CPPUNIT_ASSERT( !crea.isNull() );
	CPPUNIT_ASSERT( !agent.empty() );
}

void FixVersionTest::testResourceStatus()
{
	try
	{
		JDFMedia m=(JDFMedia)n.addResource("Media", JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);
		m.SetStatus(JDFResource::Status_Available, true);	
		CPPUNIT_ASSERT_EQUAL ( JDFResource::Status_Available, m.GetStatus(true) );
		CPPUNIT_ASSERT( m.FixVersion(JDFElement::Version_1_1) );
		CPPUNIT_ASSERT_EQUAL ( JDFResource::Status_Available, m.GetStatus(true) );
		CPPUNIT_ASSERT( m.FixVersion(JDFElement::Version_1_3) );
		CPPUNIT_ASSERT_EQUAL ( JDFResource::Status_Available, m.GetStatus(true) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void FixVersionTest::testTool()
{
	JDFTool t=(JDFTool)n.addResource("Tool", JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);
	t.SetStatus( JDFResource::Status_Available );
	t.SetProductID("toolID");
	CPPUNIT_ASSERT( t.FixVersion( JDFElement::Version_1_1) );
	CPPUNIT_ASSERT_EQUAL( WString("toolID"), t.GetToolID() );
	CPPUNIT_ASSERT_EQUAL( WString("toolID"), t.GetProductID() );
	CPPUNIT_ASSERT( t.FixVersion(JDFElement::Version_1_3) );
	CPPUNIT_ASSERT_EQUAL( WString::emptyStr, t.GetToolID() );
	CPPUNIT_ASSERT_EQUAL( WString("toolID"), t.GetProductID() );
}
