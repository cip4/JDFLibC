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
// created before 09 Oct 2006
//
// JDFResourceLinkTest.cpp: implements CppUnit test cases for JDFResourceLink
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "JDFResourceLinkTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFResourceLinkTest);

static JDFDoc creatXMDoc()
{
	JDFElement::setDefaultJDFVersion(JDFElement::Version_1_3);
	JDFDoc doc(0);
	JDFNode n=doc.GetJDFRoot();
	n.SetJobPartID("P1");
	n.SetJobID("J1");
	n.SetType("ConventionalPrinting");
	n.AppendElement("NS:Foobar","www.foobar.com");

	JDFComponent comp=(JDFComponent)n.AppendMatchingResource("Component",JDFNode::ProcessUsage_AnyOutput,JDFNode::DefJDFNode);
	JDFExposedMedia xm=(JDFExposedMedia)n.AppendMatchingResource("ExposedMedia",JDFNode::ProcessUsage_Plate,JDFNode::DefJDFNode);
	JDFNodeInfo ni=n.AppendNodeInfo();
	JDFMedia m=xm.AppendMedia();
	m.AppendElement("NS:FoobarMedia","www.foobar.com");

	CPPUNIT_ASSERT_EQUAL( JDFResource::Class_Consumable,m.GetClass() );

	vWString vs;
	vs.add("SignatureName");
	vs.add("SheetName");
	vs.add("Side");

	JDFAttributeMap mPart1("SignatureName","Sig1");
	mPart1.put("SheetName","S1");
	mPart1.put("Side","Front");  
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("Side","Back");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("SheetName","S2");
	mPart1.put("Side","Front");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("Side","Back");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("SignatureName","Sig2");
	mPart1.put("SheetName","S1");
	mPart1.put("Side","Front");       
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);
	comp.AppendElement("foo:bar","www.foobar.com");


	mPart1.put("Side","Back");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("SheetName","S2");
	mPart1.put("Side","Front");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);

	mPart1.put("Side","Back");
	xm.GetCreatePartition(mPart1,vs);
	ni.GetCreatePartition(mPart1,vs);
	comp.GetCreatePartition(mPart1,vs);	
	return doc;
}

void JDFResourceLinkTest::setUp()
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

void JDFResourceLinkTest::testAmount()
{
	try
	{
        JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		n.SetType("ConventionalPrinting");
		JDFMedia m=(JDFMedia)n.addResource(JDFElement::elm_Media, JDFResource::Class_Quantity, JDFResourceLink::Usage_Input);
		JDFResourceLink rl=n.getLink(m, JDFResourceLink::Usage_Input);

		m.SetAmount(42);
		CPPUNIT_ASSERT_EQUAL( (WString)"42",m.GetAttribute(JDFElement::atr_Amount) );
		CPPUNIT_ASSERT_EQUAL( 42.,rl.GetAmount() );
		CPPUNIT_ASSERT_EQUAL( 42.,rl.GetMinAmount() );
		CPPUNIT_ASSERT_EQUAL( 42.,rl.GetMaxAmount() );
        
		rl.SetAmount(44);
		CPPUNIT_ASSERT_EQUAL( (WString)"44",rl.GetAttribute(JDFElement::atr_Amount) );
		CPPUNIT_ASSERT_EQUAL( 44.,rl.GetAmount() );
		CPPUNIT_ASSERT_EQUAL( 44.,rl.GetMinAmount() );
		CPPUNIT_ASSERT_EQUAL( 44.,rl.GetMaxAmount() );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testDraftOK()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		n.SetType("ProcessGroup");
		JDFCustomerInfo ci=(JDFCustomerInfo)n.addResource(JDFNode::elm_CustomerInfo, JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);
		JDFComponent co=(JDFComponent)n.addResource(JDFNode::elm_Component, JDFResource::Class_Quantity, JDFResourceLink::Usage_Output);
		JDFResourceLink rl=n.GetLink(ci);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,rl.GetMinStatus() );
        
		rl.SetDraftOK(true);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Draft,rl.GetMinStatus() ); // draft
		CPPUNIT_ASSERT( !rl.HasAttribute(JDFNode::atr_DraftOK) ); // has no draft
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Draft,rl.GetMinLateStatus() ); // late draft
		CPPUNIT_ASSERT( rl.IsValid() ); // 1.3 valid
        rl.SetDraftOK(false);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,rl.GetMinStatus() ); // draft
        CPPUNIT_ASSERT( !rl.HasAttribute(JDFNode::atr_DraftOK) ); // has no draft
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,rl.GetMinLateStatus() ); // late draft
        CPPUNIT_ASSERT( rl.IsValid() ); // 1.3 valid
		rl.RemoveAttribute(JDFNode::atr_MinStatus);
        
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_2));
		rl.SetDraftOK(true);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Draft,rl.GetMinStatus() ); // draft
		CPPUNIT_ASSERT( rl.HasAttribute(JDFNode::atr_DraftOK) ); // has draft
		CPPUNIT_ASSERT( !rl.HasAttribute(JDFNode::atr_MinStatus) ); // has no MinStatus
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Draft,rl.GetMinLateStatus() ); // late draft
        CPPUNIT_ASSERT( rl.IsValid() ); // 1.2 valid
        rl.SetDraftOK(false);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,rl.GetMinStatus() ); // draft
        CPPUNIT_ASSERT( rl.HasAttribute(JDFNode::atr_DraftOK) ); // has draft
        CPPUNIT_ASSERT( !rl.HasAttribute(JDFNode::atr_MinStatus) ); // has no MinStatus
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Available,rl.GetMinLateStatus() ); // late draft
        CPPUNIT_ASSERT( rl.IsValid() ); // 1.2 valid
        
		rl=n.getLink(co, JDFResourceLink::Usage_Output);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Unavailable,rl.GetMinStatus() );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

/**
* tests whether the convoluted inheritance of partAmount and ResourceLink function correctly
*/
void JDFResourceLinkTest::testPartAmount()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		n.SetType("ConventionalPrinting");
		JDFExposedMedia xm=(JDFExposedMedia)n.addResource(JDFNode::elm_ExposedMedia, JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);
		JDFExposedMedia xm1=(JDFExposedMedia)xm.AddPartition(JDFResource::PartIDKey_SheetName,"Sheet1");
		xm.AddPartition(JDFResource::PartIDKey_SheetName,"Sheet2");
		xm1.SetAmount(1.);
		xm.SetAmount(2.);
		JDFAttributeMap map1=JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"Sheet1"); 
		JDFAttributeMap map2=JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"Sheet2"); 
		
		JDFResourceLink rl=n.GetLink(xm);
		JDFPartAmount pa=rl.GetCreateAmountPool().GetCreatePartAmount(JDFAttributeMap("SheetName","Sheet1"));
		pa.SetDraftOK(true);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Draft,pa.GetMinStatus() ); // draft
		CPPUNIT_ASSERT( !pa.HasAttribute(JDFNode::atr_DraftOK) ); // has no draft
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Draft,pa.GetMinLateStatus() ); // late draft
		pa.RemoveAttribute(JDFNode::atr_MinStatus);
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_2));
		pa.SetDraftOK(true);
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Draft,pa.GetMinStatus() ); // draft
		CPPUNIT_ASSERT( pa.HasAttribute(JDFNode::atr_DraftOK) ); // has draft
		CPPUNIT_ASSERT( !pa.HasAttribute(JDFNode::atr_MinStatus) ); // has no MinStatus
		CPPUNIT_ASSERT_EQUAL( JDFResource::Status_Draft,pa.GetMinLateStatus() ); // late draft
		
		rl.SetMinAmount(42.,map1);
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 42.,rl.GetMinAmount(map1),0. ); // map1 min
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 1.,rl.GetMaxAmount(map1),0. ); // map1 max
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 2.,rl.GetMinAmount(map2),0. ); // last default, map2 min
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 2.,rl.GetMaxAmount(),0. ); // last default, map0 max
		pa.SetAmount(55);
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 55.,pa.GetAmount(),0. ); // pa amount
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testPartAmountVirtual()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		n.SetType("ConventionalPrinting");
		JDFComponent comp=(JDFComponent)n.AppendMatchingResource(JDFNode::elm_Component,JDFNode::ProcessUsage_AnyOutput);

		JDFResourceLink cpLink=n.getLink(comp,JDFResourceLink::Usage_Output);
		JDFAttributeMap mapBad=JDFAttributeMap("Condition","Waste");
		cpLink.SetActualAmount(42,mapBad);
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 42.,cpLink.GetActualAmount(mapBad),0. );
		CPPUNIT_ASSERT( n.IsValid(KElement::ValidationLevel_Incomplete) ); // allow partamounts to non-existing partitions

		cpLink.RemoveChild(JDFNode::elm_AmountPool);
		comp.AddPartition(JDFResource::PartIDKey_SheetName,"Sheet1");
		mapBad.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"Sheet1");
		cpLink.SetActualAmount(42,mapBad);
		CPPUNIT_ASSERT_DOUBLES_EQUAL( 42.,cpLink.GetActualAmount(mapBad),0 );
		CPPUNIT_ASSERT( n.IsValid(KElement::ValidationLevel_Incomplete) ); // allow partamounts to non-existing partitions
		mapBad.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"Sheet2");
		cpLink.GetActualAmount(mapBad);
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -1.,cpLink.GetActualAmount(mapBad),0. ); // GetActualAmount not found
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testSetAmountPoolAttribute()
{
	try
	{
		XMLDoc d=XMLDoc("ResourceLinkPool");
        JDFResourceLinkPool rlp=(JDFResourceLinkPool)d.GetRoot();
		JDFResourceLink foo=(JDFResourceLink) rlp.AppendElement("FooLink");
		foo.SetAmountPoolAttribute("blub", "123", WString::emptyStr, JDFAttributeMap::emptyMap);
		CPPUNIT_ASSERT_EQUAL( (WString)"123",foo.GetAttribute("blub") );
        JDFAttributeMap map = JDFAttributeMap("SheetName","b");
		foo.SetAmountPoolAttribute("blub", "123", WString::emptyStr,map);
		CPPUNIT_ASSERT( foo.GetAttribute("blub").empty() );
		CPPUNIT_ASSERT_EQUAL( (WString)"123",foo.GetAmountPoolAttribute("blub", WString::emptyStr, map) );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testGetTargetVector()
{
	try
	{
		JDFDoc d=creatXMDoc();
        JDFNode n=d.GetJDFRoot();
        JDFAttributeMap mPart=JDFAttributeMap("SignatureName","Sig1");
        mPart.put("SheetName","S1");
		JDFResourceLink rl=n.GetMatchingLink("ExposedMedia",JDFNode::ProcessUsage_Plate,0);
		rl.SetPartMap(mPart);
        vElement v=rl.GetTargetVector(0);
		CPPUNIT_ASSERT_EQUAL( 1,(int)v.size() ); // the target vector is the node with two leaves
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testGetTarget()
{
	try
	{
		JDFDoc d=creatXMDoc();
        JDFNode n=d.GetJDFRoot();
		JDFExposedMedia xm=(JDFExposedMedia)n.GetMatchingResource("ExposedMedia",JDFNode::ProcessUsage_AnyInput);
        JDFAttributeMap mPart=JDFAttributeMap("SignatureName","Sig1");
        mPart.put("SignatureName","S12234");
        mPart.put("SheetName","S12");
        mPart.put("Side","Front");       

        JDFAttributeMap mPart2=JDFAttributeMap("SignatureName","Sig1");
        mPart2.put("SignatureName","Sig1");
        mPart2.put("SheetName","S1");
        mPart2.put("Side","Front");       
		JDFExposedMedia xmPart=(JDFExposedMedia)xm.GetPartition(mPart2);
		CPPUNIT_ASSERT( !xmPart.isNull() );
        
		JDFResourceLink rl=n.GetMatchingLink("ExposedMedia",JDFNode::ProcessUsage_Plate);
 
		rl.SetPartMap(mPart);
		CPPUNIT_ASSERT( rl.GetTarget().isNull() );
		CPPUNIT_ASSERT_EQUAL( 0,(int)rl.GetTargetVector(0).size() );
        
		xm.SetPartUsage(JDFResource::PartUsage_Explicit);
		CPPUNIT_ASSERT( rl.GetTarget().isNull() );
		CPPUNIT_ASSERT_EQUAL( 0,(int)rl.GetTargetVector(0).size() );
        
		xm.SetPartUsage(JDFResource::PartUsage_Implicit);
		CPPUNIT_ASSERT_EQUAL( xm.ToString(),rl.GetTarget().ToString() );
		CPPUNIT_ASSERT_EQUAL( 1,(int)rl.GetTargetVector(0).size() );
        
		xm.SetPartUsage(JDFResource::PartUsage_Sparse);
		CPPUNIT_ASSERT( rl.GetTarget().isNull() );
        CPPUNIT_ASSERT_EQUAL( 0,(int)rl.GetTargetVector(0).size() );
        
		rl.SetPartMap(mPart2);
		xm.RemoveAttribute("PartUsage");
		CPPUNIT_ASSERT_EQUAL( xmPart.ToString(),rl.GetTarget().ToString() );
        CPPUNIT_ASSERT_EQUAL( 1,(int)rl.GetTargetVector(0).size() );
        
		xm.SetPartUsage(JDFResource::PartUsage_Explicit);
        CPPUNIT_ASSERT_EQUAL( xmPart.ToString(),rl.GetTarget().ToString() );
        CPPUNIT_ASSERT_EQUAL( 1,(int)rl.GetTargetVector(0).size() );
        
		xm.SetPartUsage(JDFResource::PartUsage_Implicit);
        CPPUNIT_ASSERT_EQUAL( xmPart.ToString(),rl.GetTarget().ToString() );
        CPPUNIT_ASSERT_EQUAL( 1,(int)rl.GetTargetVector(0).size() );
        
		xm.SetPartUsage(JDFResource::PartUsage_Sparse);
        CPPUNIT_ASSERT_EQUAL( xmPart.ToString(),rl.GetTarget().ToString() );
        CPPUNIT_ASSERT_EQUAL( 1,(int)rl.GetTargetVector(0).size() );
        
        mPart2.put("PartVersion", "Fnarf");
		rl.SetPartMap(mPart2);
		xm.RemoveAttribute("PartUsage");
		CPPUNIT_ASSERT( rl.GetTarget().isNull() );
        CPPUNIT_ASSERT_EQUAL( 0,(int)rl.GetTargetVector(0).size() );
        
		xm.SetPartUsage(JDFResource::PartUsage_Explicit);
		CPPUNIT_ASSERT( rl.GetTarget().isNull() );
        CPPUNIT_ASSERT_EQUAL( 0,(int)rl.GetTargetVector(0).size() );
        
        xm.SetPartUsage(JDFResource::PartUsage_Implicit);
        CPPUNIT_ASSERT_EQUAL( xmPart.ToString(),rl.GetTarget().ToString() );
        CPPUNIT_ASSERT_EQUAL( 1,(int)rl.GetTargetVector(0).size() );

		xm.SetPartUsage(JDFResource::PartUsage_Sparse);
        CPPUNIT_ASSERT_EQUAL( xmPart.ToString(),rl.GetTarget().ToString() );
        CPPUNIT_ASSERT_EQUAL( 1,(int)rl.GetTargetVector(0).size() );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testGetLinkRoot()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType("ProcessGroup");
		JDFNode n2=n.AddJDFNode(JDFNode::Type_ConventionalPrinting);
		JDFCustomerInfo ci=(JDFCustomerInfo)n.addResource(JDFNode::elm_CustomerInfo, JDFResource::Class_Quantity, JDFResourceLink::Usage_Input);
		JDFResourceLink ciLink=n.getLink(ci,JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT_EQUAL( ci.ToString(),ciLink.GetLinkRoot().ToString() ); // getLinkRoot in same node
		CPPUNIT_ASSERT_EQUAL( ci.ToString(),ciLink.GetTarget().ToString() ); // getLinkTarget in same node
		CPPUNIT_ASSERT_EQUAL( ci.ToString(),ciLink.GetTarget().ToString() ); // getTarget in same node
		
		JDFResourceLink ciLink2=n2.linkResource(ci, JDFResourceLink::Usage_Input, JDFNode::ProcessUsage_Unknown);
		CPPUNIT_ASSERT_EQUAL( ci.ToString(),ciLink2.GetLinkRoot().ToString() ); // getLinkRoot in child node
		CPPUNIT_ASSERT_EQUAL( ci.ToString(),ciLink2.GetTarget().ToString() ); // getLinkTarget in child node
		CPPUNIT_ASSERT_EQUAL( ci.ToString(),ciLink2.GetTarget().ToString() ); // getTarget in child node
		
		JDFNodeInfo ni=(JDFNodeInfo)n2.addResource(JDFNode::elm_NodeInfo, JDFResource::Class_Quantity, JDFResourceLink::Usage_Input);
		JDFResourceLink niLink=n2.linkResource(ni,true ? JDFResourceLink::Usage_Input : JDFResourceLink::Usage_Output,JDFNode::ProcessUsage_Unknown);
		CPPUNIT_ASSERT_EQUAL( ni.ToString(),niLink.GetLinkRoot().ToString() ); // getLinkRoot both in child node
		CPPUNIT_ASSERT_EQUAL( ni.ToString(),niLink.GetTarget().ToString() ); // getLinkTarget both in child node
		CPPUNIT_ASSERT_EQUAL( ni.ToString(),niLink.GetTarget().ToString() ); // getTarget both in child node
		
		JDFResourceLink niLink2=(JDFResourceLink)n.GetCreateResourceLinkPool().AppendElement("NodeInfoLink");
		niLink2.SetrRef(ni.GetID());
		CPPUNIT_ASSERT( niLink2.GetLinkRoot().isNull() ); // getLinkRoot illegal in child node
		CPPUNIT_ASSERT( niLink2.GetTarget().isNull() ); // getLinkTarget illegal in child node
		CPPUNIT_ASSERT( niLink2.GetTarget().isNull() ); // getTarget illegal in child node
        
        JDFDoc d22=JDFDoc(0);
        JDFNode n22=d22.GetJDFRoot();
        JDFResourceLinkPool rlp=n22.GetCreateResourceLinkPool();
        bool bCaught=false;
        try
        {
			rlp.linkResource(ni, true?JDFResourceLink::Usage_Input:JDFResourceLink::Usage_Output,JDFNode::ProcessUsage_Unknown);
        }
        catch (JDFException)
        {
             bCaught=true;
        }
		CPPUNIT_ASSERT_MESSAGE( "Resource from other document not linked",bCaught );
		CPPUNIT_ASSERT_MESSAGE( "NI not linked",rlp.GetElement("NodeInfoLink").isNull() );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testSetPartMap()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		n.SetType("ConventionalPrinting");
		JDFExposedMedia xm=(JDFExposedMedia)n.addResource(JDFNode::elm_ExposedMedia, JDFResource::Class_Unknown, JDFResourceLink::Usage_Input);
		xm.AddPartition(JDFResource::PartIDKey_SheetName,"Sheet1");
        xm.AddPartition(JDFResource::PartIDKey_SheetName,"Sheet2");
		JDFAttributeMap map1=JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"Sheet1"); 
        JDFAttributeMap map2=JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName),"Sheet2");
		JDFResourceLink rl=n.getLink(xm,JDFResourceLink::Usage_Input);
        
        vmAttribute v;
		v.push_back(map1);
		v.push_back(map2);
        rl.SetPartMapVector(v); 
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testSetTarget()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		n.SetVersion(JDFElement::VersionString(JDFElement::Version_1_3));
		n.SetType("ConventionalPrinting");
		JDFExposedMedia xm=(JDFExposedMedia)n.addResource(JDFNode::elm_ExposedMedia, JDFResource::Class_Quantity, JDFResourceLink::Usage_Input);
		JDFExposedMedia xm1=(JDFExposedMedia)xm.AddPartition(JDFResource::PartIDKey_SignatureName,"Sig1");
        vmAttribute vSig1;
		vSig1.push_back(xm1.GetPartMap());
        // want a lower leaf partition
		xm1.AddPartition(JDFResource::PartIDKey_SheetName,"Sheet1");
        JDFMedia m=xm.AppendMedia();
		JDFResourceLink rl=n.linkResource(xm, JDFResourceLink::Usage_Input, JDFNode::ProcessUsage_Unknown);
        try
        {
            rl.SetTarget(m);
            CPPUNIT_FAIL( "no link to subelem" );
        }
        catch( ... )
        {
            // nop
        }
        rl.SetTarget(xm1);
		CPPUNIT_ASSERT_EQUAL( vSig1,rl.GetPartMapVector() );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testGetUsage()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
        JDFResourceLinkPool rlp=n.AppendResourceLinkPool();
		JDFResourceLink rl=(JDFResourceLink) rlp.AppendElement("FooLink");
		CPPUNIT_ASSERT_EQUAL( JDFResourceLink::Usage_Unknown,rl.GetUsage() );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testValidName()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		JDFResourceLinkPool rlp=n.AppendResourceLinkPool();
		JDFResourceLink rl=(JDFResourceLink) rlp.AppendElement("FooLink");
		JDFResource rBar=n.addResource("Bar", JDFResource::Class_Parameter,JDFResourceLink::Usage_Input);
		rl.SetrRef(rBar.GetID());
		CPPUNIT_ASSERT( !rl.IsValid() );
		rl=n.GetLink(rBar);
		CPPUNIT_ASSERT( !rl.isNull() );
		CPPUNIT_ASSERT( rl.IsValid() );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFResourceLinkTest::testValidPosition()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_ProcessGroup));
		JDFResource rBar=n.addResource("Bar", JDFResource::Class_Parameter, JDFResourceLink::Usage_Input);
        JDFResourceLink rl=n.GetLink(rBar);
		CPPUNIT_ASSERT( !rl.isNull() );
		CPPUNIT_ASSERT( rl.IsValid() );
		JDFNode n2=n.AddJDFNode(JDFNode::Type_Unknown);
		n2.SetType("Whatever");
        n2.MoveElement(n.GetResourcePool());
		CPPUNIT_ASSERT( !rl.IsValid() );
		CPPUNIT_ASSERT( !rl.ValidResourcePosition() );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
