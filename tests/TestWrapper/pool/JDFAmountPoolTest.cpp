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
// JDFAmountPoolTest.cpp: implements CppUnit tests for JDFAmountPool
//
//////////////////////////////////////////////////////////////////////
#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "JDFAmountPoolTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFAmountPoolTest);

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

void JDFAmountPoolTest::setUp()
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

void JDFAmountPoolTest::testReducePartAmounts()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		JDFComponent comp=(JDFComponent) n.addResource("Component", JDFResource::Class_Unknown, JDFResourceLink::Usage_Output);
		JDFAttributeMap map=JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SignatureName),"Sig1");
		JDFResourceLink rl=n.GetLink(comp,false);
		for(int i=0;i<5;i++)
		{
			map.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName), "Sheet"+i);
			comp.GetCreatePartition(map, vWString("SignatureName SheetName"));
			rl.SetAmount(500+i, map);
			JDFAttributeMap map2=JDFAttributeMap(map);
			map2.put("Condition", "Good");
			rl.SetActualAmount(500+i, map2);
			map2.put("Condition", "Waste");
			rl.SetActualAmount(50+i, map2);
		}
		vmAttribute v;
		JDFAttributeMap testMap=JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_Condition),"Good");
		v.push_back(testMap);
		JDFAmountPool ap=rl.GetAmountPool();
		CPPUNIT_ASSERT_EQUAL( 15,ap.NumChildElements(JDFNode::elm_PartAmount) ); // 15 pa entries
		// continue when JDFAmountPool::reducePartAmounts() is implemented
		//ap.reducePartAmounts(v);
		//CPPUNIT_ASSERT_EQUAL( 5,ap.NumChildElements(JDFNode::elm_PartAmount) ); // 5 pa entries
		//testMap.put("SheetName","Sheet3");
		//ap.reducePartAmounts(v);
		//CPPUNIT_ASSERT_EQUAL( 1,ap.NumChildElements(JDFNode::elm_PartAmount) ); // 1 pa entries
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFAmountPoolTest::testVirtualAmounts()
{
	try
	{
		JDFDoc d=JDFDoc(0);
        JDFNode n=d.GetJDFRoot();
		n.SetType(JDFNode::TypeString(JDFNode::Type_ConventionalPrinting));
		JDFComponent comp=(JDFComponent) n.addResource("Component", JDFResource::Class_Unknown, JDFResourceLink::Usage_Output);
		JDFAttributeMap map=JDFAttributeMap(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SignatureName),"Sig1");
		JDFResourceLink rl=n.getLink(comp,JDFResourceLink::Usage_Output);
        for(int i=0;i<5;i++)
        {
			map.put(JDFResource::PartIDKeyString(JDFResource::PartIDKey_SheetName), "Sheet"+i);
            comp.GetCreatePartition(map, vWString("SignatureName SheetName"));
			rl.SetAmount(500+i, map);
            JDFAttributeMap map2=JDFAttributeMap(map);
            map2.put("Condition", "Good");
            rl.SetActualAmount(500+i, map2);
            map2.put("Condition", "Waste");
            rl.SetActualAmount(50+i, map2);

            map2.put("Condition", "Good");
			CPPUNIT_ASSERT_DOUBLES_EQUAL( 500+i,rl.GetActualAmount(map2),0.01 );
            map2.put("Condition", "Waste");
			CPPUNIT_ASSERT_DOUBLES_EQUAL( 50+i,rl.GetActualAmount(map2),0.01 );
        }
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
