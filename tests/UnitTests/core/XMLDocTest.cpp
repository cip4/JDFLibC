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
// XMLDocTest: implements CppUnit test cases for XMLDoc
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFSpawn.h"
#include "jdf/wrappercore/XMLDocUserData.h"
#include "XMLDocTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (XMLDocTest);

const WString sm_dirTestData = L"data/";
const WString sm_dirTestTemp = L"temp/";

void XMLDocTest::setUp()
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

void XMLDocTest::testDirtyIDs()
{
	try
	{
		WString xmlFile   = "bookintent.jdf";
		WString outFile   = "spawned.jdf";
		WString strPartID = "4";

		JDFParser p;
		p.Parse(sm_dirTestData + xmlFile,false);;
		JDFDoc jdfDocIn = p.GetDocument();

		CPPUNIT_ASSERT( !jdfDocIn.isNull() );

		XMLDocUserData *xmlUserData = jdfDocIn.GetCreateXMLDocUserData();		
		xmlUserData->SetDirtyPolicy(XMLDocUserData::DirtyPolicy_ID);
		
		JDFNode rootIn = (JDFNode) jdfDocIn.GetRoot();

		JDFNode nodeToSpawn;
		if (strPartID.equals(WString::emptyStr))
		{
			nodeToSpawn = rootIn;
		}
		else
		{
			nodeToSpawn = rootIn.GetJobPart(strPartID);
		}

		if (nodeToSpawn.isNull())
		{
			string eMessage = "No such JobPartID: ";
			eMessage.append(strPartID.GetUTF8Bytes());
			CPPUNIT_FAIL( eMessage );
		}
		else
		{
			vWString vRWResources;
			vRWResources.add("Component");
			vRWResources.add("RunList");

			vmAttribute vSpawnParts;
			JDFSpawn spawn=JDFSpawn(nodeToSpawn);
			
			JDFNode node;
			JDFDoc temp= spawn.spawn(xmlFile,outFile,vRWResources,vSpawnParts,false,false,false,false);
			node = temp.GetJDFRoot();

			// neu gespawntes File rausschreiben
			JDFNode rootOut = node;
			XMLDoc docOut = KElement(rootOut).GetOwnerDocument();
			docOut.Write2File(sm_dirTestTemp + outFile);

			// verändertes Ausgangsfile rausschreiben
			WString strOutXMLFile = "_" + xmlFile;
			rootIn.EraseEmptyNodes(true);
			jdfDocIn.Write2File(sm_dirTestTemp + strOutXMLFile);

			// test, if all changed nodes are in our list
			vWString vstrDirtyIDs = jdfDocIn.GetDirtyIDs();
			CPPUNIT_ASSERT_EQUAL( 4,(int)vstrDirtyIDs.size() );
			CPPUNIT_ASSERT( vstrDirtyIDs.contains("n0014") ); // audit pool was added
			CPPUNIT_ASSERT( vstrDirtyIDs.contains("n0016") ); // status changed: waiting --> spawned
			CPPUNIT_ASSERT( vstrDirtyIDs.contains("r0017") ); // SpawnStatus="SpawnedRW" added
			CPPUNIT_ASSERT( vstrDirtyIDs.contains("r0018") ); // SizeIntent added
		}

		// after use, xmlUserData instance will be deleted by XMLDoc. No manual destruction of xmlUserData is required.
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void XMLDocTest::testEscapeStrings()
{
	try
	{
		XMLDoc d=XMLDoc("foo","www.foo.com");
        KElement e=d.GetRoot();
		e.SetAttribute("bar", "><&'\"");
        WString s;
		d.Write2String(s);
		CPPUNIT_ASSERT( s.indexOf("&lt;")>0 );
        CPPUNIT_ASSERT( s.indexOf("&amp;")>0 );
        CPPUNIT_ASSERT( s.indexOf("&quot;")>0 );
	}
	catch (const JDFException &e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
