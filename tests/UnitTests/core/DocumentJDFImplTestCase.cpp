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
// DocumentJDFImplTestCase.cpp: implements CppUnit tests for JDF element names
//
//////////////////////////////////////////////////////////////////////

#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "DocumentJDFImplTestCase.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (DocumentJDFImplTestCase);


void DocumentJDFImplTestCase::setUp()
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

void DocumentJDFImplTestCase::testContextSensitiveElementNames()
{
	try
	{
        // HoleType, Method, Shape and Surface are context sensitive elements
        // The type casts below should all succeed
		JDFDoc doc(0);
		KElement rootNode = doc.GetRoot();

		JDFStringSpan kelem21 = (JDFStringSpan)rootNode.AppendElement("HoleType");
        kelem21.SetAttribute("Type", "org.cip4.jdflib.span.JDFStringSpan");
        KElement kelem22 = rootNode.AppendElement("RingBinding");
        JDFSpanHoleType kelem23 = (JDFSpanHoleType) kelem22.AppendElement("HoleType");
        kelem23.SetAttribute("Type", "org.cip4.jdflib.span.JDFSpanHoleType");
        
        JDFNameSpan kelem11 = (JDFNameSpan) rootNode.AppendElement("Method");
        kelem11.SetAttribute("Type", "org.cip4.jdflib.span.JDFNameSpan");
        KElement kelem12 = rootNode.AppendElement("InsertingIntent");
        JDFSpanMethod kelem13 = (JDFSpanMethod) kelem12.AppendElement("Method");
        kelem13.SetAttribute("Type", "org.cip4.jdflib.span.JDFSpanMethod");
        
        JDFShapeElement kelem4 = (JDFShapeElement) rootNode.AppendElement("Shape");
        kelem4.SetAttribute("Type", "org.cip4.jdflib.resource.JDFShapeElement");
        KElement kelem5 = rootNode.AppendElement("BookCase");
        JDFSpanShape kelem6 = (JDFSpanShape) kelem5.AppendElement("Shape");
        kelem6.SetAttribute("Type", "org.cip4.jdflib.span.JDFSpanShape");
        
        JDFSurface kelem7 = (JDFSurface) rootNode.AppendElement("Surface");
        kelem7.SetAttribute("Type", "org.cip4.jdflib.resource.process.JDFSurface");
        KElement kelem8 = rootNode.AppendElement("LaminatingIntent");
        JDFSpanSurface kelem9 = (JDFSpanSurface) kelem8.AppendElement("Surface");
        kelem9.SetAttribute("Type", "org.cip4.jdflib.span.JDFSpanSurface");
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
