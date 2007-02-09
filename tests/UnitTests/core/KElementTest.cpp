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
// created 03 Aug 2006
//
// KElementTest.cpp: implements CppUnit tests for KElement
//
//////////////////////////////////////////////////////////////////////

#include "jdf/util/PlatformUtils.h"
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "jdf/wrappercore/xmldocuserdata.h"
#include "KElementTest.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (KElementTest);

const WString sm_dirTestData = L"data/";
const WString sm_dirTestTemp = L"temp/";

void KElementTest::setUp()
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

void KElementTest::testRemoveAttributeStringString()
{
	try
	{
		JDFParser p;
		p.Parse(sm_dirTestData+"emptyAuthorAttribute.jdf", false);
		JDFDoc jdfDoc = p.GetDocument();

		JDFNode root   = (JDFNode) jdfDoc.GetRoot();
		KElement kElem = root.GetChildByTagName("Created", WString::emptyStr, 0, mAttribute::emptyMap, false, true);

 		bool before = kElem.HasAttribute("Author");
		CPPUNIT_ASSERT_MESSAGE( "The Attribute 'Author' does not exist", before );

		if (before)
		{
			kElem.RemoveAttribute("Author");
			bool after = kElem.HasAttribute("Author");
			CPPUNIT_ASSERT_MESSAGE("The Attribute 'Author' was not removed", !after);
		}
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testRenameElement()
{
	try
	{
		XMLDoc d("root","www.root.com");
		KElement root=d.GetRoot();
		WString nsUri=root.GetNamespaceURI();
		root.RenameElement("foo", WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( nsUri, root.GetNamespaceURI() );
		CPPUNIT_ASSERT_EQUAL( WString("foo"), root.GetNodeName() );
		root.RenameElement("bar","www.bar.com");
		CPPUNIT_ASSERT_EQUAL( WString("www.bar.com"), root.GetNamespaceURI() );
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testReplaceElement()
{
	try
	{
		XMLDoc d("root","www.root.com");
		XMLDoc d2("root2","www.root2.com");
		KElement e=d.GetRoot();
		KElement ec1=e.AppendElement("c1");
		KElement ec2=e.AppendElement("c2");
		KElement ec4=e.AppendElement("c4");
		KElement ec3=ec1.ReplaceElement(ec2);
		CPPUNIT_ASSERT_EQUAL( ec2, ec3 );
		CPPUNIT_ASSERT_EQUAL( ec3, ec4.GetPreviousSiblingElement() );
		CPPUNIT_ASSERT_EQUAL( ec4, ec3.GetNextSiblingElement() );
		CPPUNIT_ASSERT( ec1.GetNextSiblingElement().isNull() );
		CPPUNIT_ASSERT( ec1.GetPreviousSiblingElement().isNull() );
		CPPUNIT_ASSERT_EQUAL( e, ec2.GetParentNode() );
		CPPUNIT_ASSERT( ec1.GetParentNode().isNull() );

		// now cross document
		KElement e2=d2.GetRoot();
		e2.AppendElement("e22");
		ec1=ec3.ReplaceElement(e2);
		CPPUNIT_ASSERT( ec3.GetParentNode().isNull() );
		CPPUNIT_ASSERT_EQUAL( e, ec1.GetParentNode() );
		CPPUNIT_ASSERT_EQUAL( ec1, ec4.GetPreviousSiblingElement() );
		CPPUNIT_ASSERT_EQUAL( ec4, ec1.GetNextSiblingElement() );
		CPPUNIT_ASSERT_EQUAL( e, ec1.GetParentNode() );
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testRemoveEmptyAttributes()
{
	try
	{
		JDFDoc d(0);
		KElement e=d.GetJDFRoot();

		e.SetAttribute("foo","bar");
		e.SetAttribute("foo2", "");

		CPPUNIT_ASSERT( e.HasAttribute("foo") );
		CPPUNIT_ASSERT( e.HasAttribute("foo2") );

		KElement e2=e.AppendElement("e2");
		e2.SetAttribute("foo","bar");
		e2.SetAttribute("foo2","");

		e.eraseEmptyAttributes(false);
		CPPUNIT_ASSERT( e.HasAttribute("foo") );
		CPPUNIT_ASSERT( !e.HasAttribute("foo2") );
		CPPUNIT_ASSERT( e2.HasAttribute("foo") );
		CPPUNIT_ASSERT( e2.HasAttribute("foo2") );

		e.eraseEmptyAttributes(true);
		CPPUNIT_ASSERT( e.HasAttribute("foo") );
		CPPUNIT_ASSERT( !e.HasAttribute("foo2") );
		CPPUNIT_ASSERT( e2.HasAttribute("foo") );
		CPPUNIT_ASSERT( !e2.HasAttribute("foo2") );
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testRemoveAttribute()
{
	JDFDoc d(0);
	KElement e=d.GetJDFRoot();
	const WString jdfNS = "http://www.CIP4.org/JDFSchema_1_1";

	e.SetAttribute("foo","bar", WString::emptyStr);
	CPPUNIT_ASSERT( e.HasAttribute("foo") );
	CPPUNIT_ASSERT( e.HasAttribute("foo", WString::emptyStr, false) );
	e.RemoveAttribute("foo");
	CPPUNIT_ASSERT( !e.HasAttribute("foo") );
	CPPUNIT_ASSERT( !e.HasAttribute("foo", WString::emptyStr, false) );

	e.SetAttribute("foo", "bar", jdfNS );
	CPPUNIT_ASSERT( e.HasAttribute("foo") );
	CPPUNIT_ASSERT( e.HasAttribute("foo", jdfNS, false ) );
	e.RemoveAttribute("foo", jdfNS);
	CPPUNIT_ASSERT( !e.HasAttribute("foo") );
	CPPUNIT_ASSERT( !e.HasAttribute("foo", jdfNS, false ) );

	e.SetAttribute("JDF:foo", "bar", jdfNS);
	CPPUNIT_ASSERT( e.HasAttribute("JDF:foo") );
	CPPUNIT_ASSERT( e.HasAttribute("foo", jdfNS, false ) );
	
	e.RemoveAttribute("foo", jdfNS);
	CPPUNIT_ASSERT( !e.HasAttribute("JDF:foo") );
	CPPUNIT_ASSERT( !e.HasAttribute("foo", jdfNS, false ) );	
}

void KElementTest::testNameSpace()
{
	JDFDoc doc(0);
	KElement root = doc.GetRoot();

	root.SetAttribute("xmlns","http://www.CIP4.org/JDFSchema_1_1");

	WString docNS    = "http://www.cip4.org/test/";
	WString myPrefix = "MyPrefix";

	root.AddNameSpace(myPrefix, docNS);

	// add an element with a (predefined) prefix and no namespace
	KElement kElem9 = root.AppendElement(
		myPrefix+WString::colon+"MyElementLevel_2", WString::emptyStr);
	CPPUNIT_ASSERT_EQUAL( docNS, kElem9.GetNamespaceURI() );
	CPPUNIT_ASSERT_EQUAL( myPrefix, kElem9.GetPrefix() );

	KElement kElem1 = root.AppendElement(
		"MyElementLevel_1", docNS);
	CPPUNIT_ASSERT_EQUAL( docNS, kElem1.GetNamespaceURI() );

	kElem1.SetAttribute("att1", "attval1", docNS);
	
	// add an element in a namespace
	KElement kElem = root.AppendElement(
		myPrefix+WString::colon+"MyElement", docNS);
	CPPUNIT_ASSERT_EQUAL( docNS, kElem.GetNamespaceURI() );
	CPPUNIT_ASSERT_EQUAL( myPrefix, kElem.GetPrefix() );

	// add an attribute  and its value in a namespace
	kElem.SetAttribute(myPrefix+WString::colon+"MyAttribute", "MyValue", docNS);

	// How to get the element, Version 1
	KElement kElem2 = root.GetElement("MyElement", docNS, 0);

	WString attr = kElem2.GetAttribute("MyAttribute", docNS, "MyDefault");
	CPPUNIT_ASSERT_EQUAL( WString("MyValue"), attr );

	// this is pretty invalid but the ns url takes precedence
	attr = kElem2.GetAttribute(myPrefix+WString::colon+"MyAttribute", docNS, "MyDefault");
	CPPUNIT_ASSERT_EQUAL( WString("MyValue"), attr );

	// this is even more invalid but the ns url takes precedence
	attr = kElem2.GetAttribute("fnarf"+WString::colon+"MyAttribute", docNS, "MyDefault");
	CPPUNIT_ASSERT_EQUAL( WString("MyValue"), attr );


	// How to get the element, Version 2
	KElement kElem3 = root.GetElement(myPrefix+WString::colon+"MyElement", docNS, 0);

	attr = kElem3.GetAttribute("MyAttribute", docNS, "MyDefault");
	CPPUNIT_ASSERT_EQUAL( WString("MyValue"), attr );

	attr = kElem3.GetAttribute(myPrefix+WString::colon+"MyAttribute", docNS, "MyDefault");
	CPPUNIT_ASSERT_EQUAL( WString("MyValue"), attr );

	//doc.Write2File(sm_dirTestTemp+"NameSpace.jdf");
}

void KElementTest::testNameSpaceInElements()
{
	JDFDoc doc(0);
	KElement root = doc.GetRoot();

	WString cip4NameSpaceURI = root.GetNamespaceURI();
	CPPUNIT_ASSERT_EQUAL( WString("http://www.CIP4.org/JDFSchema_1_1"), cip4NameSpaceURI );

	// adding cip4NameSpaceURI a second time as default namespace is ignored (using addNameSpace or setAttribute)
	root.AddNameSpace(WString::emptyStr, cip4NameSpaceURI);
	root.SetAttribute("xmlns", cip4NameSpaceURI);

	// adding cip4NameSpaceURI with different prefixes using addNameSpace is ignored
	WString cip4Prefix1 = "JDF";
	WString cip4Prefix2 = "jdf";
	WString cip4Prefix3 = "JDFS";
	root.AddNameSpace(cip4Prefix1, cip4NameSpaceURI);
	root.AddNameSpace(cip4Prefix2, cip4NameSpaceURI);
	root.AddNameSpace(cip4Prefix3, cip4NameSpaceURI);

	// adding cip4NameSpaceURI with different prefixes using setAttribute is allowed
	root.SetAttribute("xmlns"+WString::colon+cip4Prefix1, cip4NameSpaceURI);
	root.SetAttribute("xmlns"+WString::colon+cip4Prefix2, cip4NameSpaceURI);
	root.SetAttribute("xmlns"+WString::colon+cip4Prefix3, cip4NameSpaceURI);

	// append an element without prefix with null NameSpaceURI or cip4NameSpaceURI
	KElement kElement0 = root.AppendElement("kElement0", WString::emptyStr);
	CPPUNIT_ASSERT_EQUAL( cip4NameSpaceURI, kElement0.GetNamespaceURI() );
	CPPUNIT_ASSERT_EQUAL( WString::emptyStr, kElement0.GetPrefix() );

	KElement kElement1 = root.AppendElement("kElement1", cip4NameSpaceURI);
	CPPUNIT_ASSERT_EQUAL( cip4NameSpaceURI, kElement1.GetNamespaceURI() );
	CPPUNIT_ASSERT_EQUAL( WString::emptyStr, kElement1.GetPrefix() );


	// append an element with prefix with null NameSpaceURI or cip4NameSpaceURI
	KElement kElement2 = root.AppendElement(cip4Prefix1+WString::colon+"kElement2", WString::emptyStr);
	CPPUNIT_ASSERT_EQUAL( cip4NameSpaceURI, kElement2.GetNamespaceURI() );
	CPPUNIT_ASSERT_EQUAL( cip4Prefix1, kElement2.GetPrefix() );

	KElement kElement3 = root.AppendElement(cip4Prefix1+WString::colon+"kElement3", cip4NameSpaceURI);
	CPPUNIT_ASSERT_EQUAL( cip4NameSpaceURI, kElement3.GetNamespaceURI() );
	CPPUNIT_ASSERT_EQUAL( cip4Prefix1, kElement3.GetPrefix() );


	WString jdfDocString = "<JDF ID=\"n051221_021145422_000005\" Version=\"1.3\" ";
	jdfDocString.append(      "xmlns=\"http://www.CIP4.org/JDFSchema_1_1\" ");
	jdfDocString.append(      "xmlns:JDF=\"http://www.CIP4.org/JDFSchema_1_1\" ");
	jdfDocString.append(      "xmlns:JDFS=\"http://www.CIP4.org/JDFSchema_1_1\" ");
	jdfDocString.append(      "xmlns:jdf=\"http://www.CIP4.org/JDFSchema_1_1\">");
	jdfDocString.append(      "<kElement0/>");
	jdfDocString.append(      "<JDF:kElement1/>");
	jdfDocString.append(      "<JDFS:kElement2/>");
	jdfDocString.append(      "<jdf:kElement3/>");
	jdfDocString.append(   "</JDF>");

	JDFParser p;
	p.StringParse(jdfDocString, false);
	JDFDoc jdfDoc = p.GetDocument();
	KElement root1 = jdfDoc.GetRoot();

	// How to get the element, uri = null or cip4NameSpaceURI

	// empty prefix is ok
	KElement kElemGet1 = root1.GetElement("kElement1", WString::emptyStr, 0);
	KElement kElemGet2 = root1.GetElement("kElement1", cip4NameSpaceURI, 0);
	CPPUNIT_ASSERT_EQUAL( kElemGet1, kElemGet2 );

	// correct prefix is ok
	KElement kElemGet3 = root1.GetElement(cip4Prefix1+WString::colon+"kElement1", WString::emptyStr, 0);
	KElement kElemGet4 = root1.GetElement(cip4Prefix1+WString::colon+"kElement1", cip4NameSpaceURI, 0);
	CPPUNIT_ASSERT_EQUAL( kElemGet3, kElemGet4 );
	CPPUNIT_ASSERT_EQUAL( kElemGet2, kElemGet4 );

	// wrong prefix
	KElement kElemGet5 = root1.GetElement(cip4Prefix2+WString::colon+"kElement1", WString::emptyStr, 0);
	KElement kElemGet6 = root1.GetElement(cip4Prefix2+WString::colon+"kElement1", cip4NameSpaceURI, 0);
	CPPUNIT_ASSERT( kElemGet5.isNull() );
	CPPUNIT_ASSERT( kElemGet6.isNull() );
}

void KElementTest::testNameSpace1()
{
	JDFDoc doc(0);
	JDFElement root = (JDFElement)doc.GetRoot();

	WString docNS1 = "www1";
	WString docNS2 = "www2";
	WString myPrefix = "HDM";

	try
	{
		// add an element in a namespace
		KElement kElem1 = root.AppendElement(myPrefix + WString::colon + "Foo_1", docNS1);
		CPPUNIT_ASSERT_EQUAL( docNS1, kElem1.GetNamespaceURI() );
		CPPUNIT_ASSERT_EQUAL( myPrefix, kElem1.GetPrefix() );

		kElem1.SetAttribute(myPrefix + WString::colon + "Foo_1", "attval1", docNS1);
		kElem1.SetAttribute(myPrefix + WString::colon + "Foo_2", "attval2", docNS2);
		CPPUNIT_FAIL( "Called KElement.setAttribute with same prefix but different namespaces ?!" );
	}
	catch (JDFException expected)
	{
		WString partOfErrorMessage = "KElement::SetAttribute:";
		bool errorIsMentioned = bool(expected.getMessage().indexOf(partOfErrorMessage) >= 0);
		WString errorMessage = "didn't catch expected error. Caught error: ";
		errorMessage.append(expected.getMessage());
		
		if (!errorIsMentioned)
			cout << endl <<errorMessage << endl;
		CPPUNIT_ASSERT( errorIsMentioned );
	}
}

void KElementTest::testNameSpaceInAttributes()
{
	JDFDoc doc(0);
	JDFElement root = (JDFElement)doc.GetRoot();
	root.AddNameSpace("foo","www.foo.com");
	CPPUNIT_ASSERT_EQUAL((WString)"www.foo.com", root.GetAttribute("xmlns:foo") );
	KElement child = root.AppendElement("abc");
	child.AddNameSpace("foo","www.foo.com");
	CPPUNIT_ASSERT( !child.HasAttribute("xmlns:foo") );
	child.SetAttribute("foo:bar","a1");
	CPPUNIT_ASSERT_EQUAL( (WString)"a1", child.GetAttribute("foo:bar") );
	child.SetAttribute("foo:bar","a2","www.foo.com");
	child.SetAttribute("foo:barNs","ns","www.foo.com");
	CPPUNIT_ASSERT_EQUAL( (WString)"a2", child.GetAttribute("foo:bar") );
	CPPUNIT_ASSERT_EQUAL( (WString)"a2", child.GetAttribute("bar","www.foo.com",WString::emptyStr) );
	child.SetAttribute("foo:bar","a3");
	CPPUNIT_ASSERT_EQUAL( (WString)"a3", child.GetAttribute("foo:bar") );
	CPPUNIT_ASSERT_EQUAL( (WString)"a3", child.GetAttribute("bar","www.foo.com",WString::emptyStr) );
	child.SetAttribute("bar:bar","b3","www.bar.com");
	CPPUNIT_ASSERT_EQUAL( (WString)"b3", child.GetAttribute("bar:bar") );
	CPPUNIT_ASSERT_EQUAL( (WString)"b3", child.GetAttribute("bar","www.bar.com",WString::emptyStr) );
	child.SetAttribute("bar:bar","b2");
	CPPUNIT_ASSERT_EQUAL( (WString)"b2", child.GetAttribute("bar:bar") );
	// error in Xerces::DOMElement::getAttributeNodeNS(), C++ only
	//CPPUNIT_ASSERT_EQUAL( (WString)"b2", child.GetAttribute("bar","www.bar.com",WString::emptyStr) );
	//child.SetAttribute("bar:bar","b4","www.bar.com");
	//CPPUNIT_ASSERT_EQUAL( (WString)"b4", child.GetAttribute("bar:bar") );
	//CPPUNIT_ASSERT_EQUAL( (WString)"b4", child.GetAttribute("bar","www.bar.com",WString::emptyStr) );
}

void KElementTest::testGetPrefix()
{
	JDFDoc jdfDoc(0);
	JDFNode myRoot = (JDFNode)jdfDoc.GetRoot();
	myRoot.AddNameSpace("foo","www.foo.com");
	KElement e=myRoot.AppendElement("foo:bar", WString::emptyStr);
	CPPUNIT_ASSERT_EQUAL( (WString)"foo", e.GetPrefix() );
	myRoot.RemoveAttribute("xmlns:foo");
	CPPUNIT_ASSERT_EQUAL( (WString)"foo", e.GetPrefix() );
}

void KElementTest::testGetLocalName()
{
	try
	{
		JDFDoc jdfDoc(0);
		JDFNode myRoot = (JDFNode) jdfDoc.GetRoot();
		WString docNS = "http://www.cip4.org/test/";
		WString myPrefix = "MyPrefix";

		// test element with different default namespace
		myRoot.AppendElement("Foo", docNS);
		KElement k = myRoot.GetElement("Foo", WString::emptyStr, 0);
		WString s = k.GetLocalName();
		CPPUNIT_ASSERT_EQUAL( (WString)"Foo",s );

		myRoot.AddNameSpace(myPrefix, docNS);

		// append another element with a prefix, namespace is equal to default namespace
		myRoot.AppendElement(myPrefix+":Faa", WString::emptyStr);
		k = myRoot.GetElement("Faa", WString::emptyStr, 0);
		s = k.GetLocalName();

		CPPUNIT_ASSERT_EQUAL( (WString)"Faa", s );

		jdfDoc.Write2File(sm_dirTestTemp+"GetLocalNameStatic.jdf");
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testGetCreateElement()
{
	try
	{
		JDFDoc doc(0);
		JDFNode root = doc.GetJDFRoot();
		root.SetType(JDFNode::TypeString(JDFNode::Type_Imposition));
		JDFRunList rl = (JDFRunList) root.AppendMatchingResource(JDFStrings::elm_RunList, JDFNode::ProcessUsage_Document, JDFNode());
		rl.AppendLayoutElement();
		JDFRunList leaf = (JDFRunList) rl.GetCreatePartition(JDFResource::PartIDKey_Run, "Run1", 
			vWString(JDFResource::PartIDKeyString(JDFResource::PartIDKey_Run), WString::whiteSpace));

		KElement el1 = rl.GetCreateElement(JDFStrings::elm_LayoutElement, WString::emptyStr, 0);
		KElement el2 = leaf.GetCreateElement(JDFStrings::elm_LayoutElement, WString::emptyStr, 0);
		CPPUNIT_ASSERT( el1 != el2 );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testGetMatchesPath()
{
	XMLDoc d("a", WString::emptyStr);
	KElement r=d.GetRoot();
	KElement b=r.GetCreateXPathElement("b/c/d");
	CPPUNIT_ASSERT( b.matchesPath("d",true) );
	CPPUNIT_ASSERT( b.matchesPath("c/d",true) );
	CPPUNIT_ASSERT( b.matchesPath("/a/b/c/d",true) );
	CPPUNIT_ASSERT( b.matchesPath("a/b/c/d",true) );
	CPPUNIT_ASSERT( !b.matchesPath("a/a/b/c/d",true) );
}


void KElementTest::testGetDeepParentChild()
{
	XMLDoc jdfDoc("Test","www.test.com");
	KElement e = jdfDoc.GetRoot();
	KElement foo = e.AppendElement("foo");
	KElement bar = foo.AppendElement("bar");
	CPPUNIT_ASSERT( bar.GetDeepParentChild("fnarf").isNull() );
	CPPUNIT_ASSERT_EQUAL( foo, bar.GetDeepParentChild("Test") );
	CPPUNIT_ASSERT_EQUAL( bar, bar.GetDeepParentChild("foo") );
	KElement foo2 = e.AppendElement("foo:foo","www.foo.com");
	KElement bar2 = foo2.AppendElement("bar:bar","www.bar.com");
	CPPUNIT_ASSERT_EQUAL( bar2, bar2.GetDeepParentChild("foo:foo") );
	KElement bar3 = bar2.AppendElement("bar:fnarf","www.bar.com");
	CPPUNIT_ASSERT_EQUAL( bar2, bar3.GetDeepParentChild("foo:foo") );
}

void KElementTest::testGetDeepParentNotName()
{
	XMLDoc jdfDoc("Test","www.test.com");
	KElement e = jdfDoc.GetRoot();
	KElement foo = e.AppendElement("foo");
	KElement bar = foo.AppendElement("bar");
	CPPUNIT_ASSERT_EQUAL( foo, bar.GetDeepParentNotName("bar") );
	KElement bar2=bar.AppendElement("bar","www.bar.com");
	CPPUNIT_ASSERT_EQUAL( foo, bar2.GetDeepParentNotName("bar") );
	KElement bar3=(KElement)jdfDoc.CreateElement("bar");
	CPPUNIT_ASSERT( bar3.GetDeepParentNotName("bar").isNull() );
	KElement bar4=(KElement)jdfDoc.CreateElement("bar","www.bar.com");
	CPPUNIT_ASSERT( bar4.GetDeepParentNotName("bar").isNull() );
}

void KElementTest::testInfinity()
{
#ifdef WIN32
	try
	{
		XMLDoc jdfDoc("Test","www.test.com");
		KElement e = jdfDoc.GetRoot();
		e.SetAttribute("inf",WString::pINFstr,WString::emptyStr);
		e.SetAttribute("minf",WString::nINFstr,WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( WString::pINFstr, e.GetAttribute("inf",WString::emptyStr,WString::emptyStr) );
		CPPUNIT_ASSERT_EQUAL( WString::nINFstr, e.GetAttribute("minf",WString::emptyStr,WString::emptyStr) );
		CPPUNIT_ASSERT_EQUAL( INT_MAX, e.GetIntAttribute("inf",WString::emptyStr,0) );
		CPPUNIT_ASSERT_EQUAL( INT_MIN, e.GetIntAttribute("minf",WString::emptyStr,0) );
		// now double
		e.SetAttribute("inf",WString::pDINFstr,WString::emptyStr);
		e.SetAttribute("minf",WString::nDINFstr,WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( WString::pDINFstr, e.GetAttribute("inf",WString::emptyStr,WString::emptyStr) );
		CPPUNIT_ASSERT_EQUAL( WString::nDINFstr, e.GetAttribute("minf",WString::emptyStr,WString::emptyStr) );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( DBL_MAX, e.GetRealAttribute("inf"), 0.0 );
		CPPUNIT_ASSERT_DOUBLES_EQUAL( -DBL_MAX, e.GetRealAttribute("minf"), 0.0 );
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
#else
	CPPUNIT_FAIL ( "this test includes Microsoft specific constants" );
#endif

}

void KElementTest::testSetAttribute()
{
	JDFDoc jdfDoc(0);
	JDFNode root  = (JDFNode) jdfDoc.GetRoot();

	WString nodeName = "Created";
	KElement kElem  = root.GetXPathElement("AuditPool/" + nodeName);
	if ( !kElem.isNull() )
	{
		CPPUNIT_ASSERT_EQUAL( nodeName, kElem.GetNodeName() );
		// does setAttribute really set an empty value?
		kElem.SetAttribute("Author", "");
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr, kElem.GetAttribute("Author", WString::emptyStr, WString::emptyStr) );

		CPPUNIT_ASSERT( kElem.HasAttribute("Author", WString::emptyStr, false) );
		CPPUNIT_ASSERT( !kElem.HasAttribute("NewAttribute", WString::emptyStr, false) );

		kElem.SetAttribute("Author", WString::emptyStr, JDFElement::atr_xmlnsURI);
		kElem.SetAttribute("NewAttribute", WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( WString::emptyStr, kElem.GetAttribute("NewAttribute", WString::emptyStr, WString::emptyStr) );
		kElem.SetAttribute("foo", "הצü\"'");
		CPPUNIT_ASSERT_EQUAL( WString("הצü\"'"), kElem.GetAttribute("foo", WString::emptyStr, WString::emptyStr) );
	}
}

void KElementTest::testCache()
{
	try
	{
		XMLDoc d1("d1",WString::emptyStr);
		XMLDoc d2("d2",WString::emptyStr);
		CPPUNIT_ASSERT( d1.HasXMLDocUserData() );
		CPPUNIT_ASSERT( d2.HasXMLDocUserData() );
		CPPUNIT_ASSERT( (*d1.GetXMLDocUserData()).getIDCache() );
		KElement e1=d1.GetRoot();
		KElement e2=d2.GetRoot();
		for(int i=0;i<4;i++){
			e1.SetXPathAttribute("e2/e3"+WString::valueOf(i)+"/@ID","i1"+WString::valueOf(i));
			e2.SetXPathAttribute("e2/e3"+WString::valueOf(i)+"/@ID","i2"+WString::valueOf(i));            
		}
		KElement e13=e2.GetTarget("i13","ID");
		CPPUNIT_ASSERT( e13.isNull() );
		e13=e1.GetTarget("i13","ID");
		CPPUNIT_ASSERT( !e13.isNull() );
		CPPUNIT_ASSERT_EQUAL( d1.ToString(), e1.GetOwnerDocument().ToString() );
		KElement e23=e2.GetTarget("i23","ID");
		CPPUNIT_ASSERT( !e23.isNull() );
		CPPUNIT_ASSERT_EQUAL( d2.ToString(), e2.GetOwnerDocument().ToString() );
		e1.MoveElement(e23);
		e23=e2.GetTarget("i23","ID");
		CPPUNIT_ASSERT( e23.isNull() );
		e23=e1.GetTarget("i23","ID");
		CPPUNIT_ASSERT( !e23.isNull() );
		CPPUNIT_ASSERT_EQUAL( d1.ToString(), e23.GetOwnerDocument().ToString() );
		e23.DeleteNode();
		e23.GetTarget("i23","ID");
		CPPUNIT_ASSERT( e23.isNull() );

		e23=e2.GetTarget("i22","ID");
		CPPUNIT_ASSERT( !e23.isNull() );
		KElement e24=e23.RenameElement("fnarf",WString::emptyStr);
		CPPUNIT_ASSERT_EQUAL( e23.ToString(), e24.ToString() );
		CPPUNIT_ASSERT_EQUAL( WString("fnarf"), e24.GetNodeName() );
		CPPUNIT_ASSERT_EQUAL( WString("fnarf"), e24.GetLocalName() );
		CPPUNIT_ASSERT_EQUAL( e24, e2.GetTarget("i22","ID") );
	}
	catch (std::exception e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testGetChildrenByTagName()
{
	try
	{
		WString xmlFile = "getChildrenByTagNameTest.jdf";

		JDFParser p;
		p.Parse(sm_dirTestData+xmlFile, false);
		JDFDoc jdfDoc = p.GetDocument();

		JDFNode jdfRoot = (JDFNode) jdfDoc.GetRoot();
		JDFResourcePool jdfPool = jdfRoot.GetResourcePool();
		VElement v = jdfPool.GetChildrenByTagName("RunList", WString::emptyStr, mAttribute::emptyMap, false, true, 0);
		CPPUNIT_ASSERT_EQUAL( 10,(int)v.size() );
		v = jdfPool.GetChildrenByTagName("RunList", WString::emptyStr,mAttribute::emptyMap, false, true, -1);
		CPPUNIT_ASSERT_EQUAL( 10,(int)v.size() );
		v = jdfPool.GetChildrenByTagName("RunList", WString::emptyStr,mAttribute::emptyMap, false, true, 5);
		CPPUNIT_ASSERT_EQUAL( 5,(int)v.size() );
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testGetChildElementVector()
{
	XMLDoc doc("Foo",WString::emptyStr);
	KElement root=doc.GetRoot();
	CPPUNIT_ASSERT_EQUAL( 0, (int)root.GetChildElementVector().size() );
	root.AppendElement("bar:bar","www.bar.com");
	root.AppendElement("bar2");
	CPPUNIT_ASSERT_EQUAL( 2, (int)root.GetChildElementVector().size() );
	CPPUNIT_ASSERT_EQUAL( root.GetElement("bar:bar"), root.GetChildElementVector()[0] );
	CPPUNIT_ASSERT_EQUAL( root.GetElement("bar2"), root.GetChildElementVector()[1] );
}


void KElementTest::testPushUp()
{
	try
	{
		{//defines a logical test block
			//pushup and force parentNode == null
			JDFDoc jdfDoc(0);
			JDFNode root = (JDFNode) jdfDoc.GetRoot();
			KElement e = root;
			for(int i = 0; i < 5; i++)
			{
				e = e.AppendElement("Test" + WString::valueOf(i), WString::emptyStr);
			}
			KElement k = e.PushUp("Foo");
			CPPUNIT_ASSERT ( k.isNull() );
		}
	}
	catch (JDFException e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testSetAttribute_NameSpaceHandling()
{
	JDFDoc jdfDoc(0);
	JDFNode root = (JDFNode) jdfDoc.GetRoot();
	KElement e = root;

	root.SetAttribute("xmlns:Kai", "foo");
	KElement appended = e.AppendElement("Kai:Test1", "foo");
	appended.SetAttribute("Kai:Test1", "1", "foo");
	//no try to change the namespace and append
	e.SetAttribute("xmlns:Kai", "faa");
	appended.SetAttribute("Kai:Test1", "2", WString::emptyStr);
	root.SetAttribute("aa","bb");
	root.SetAttribute("aa","bb",WString::emptyStr);
	CPPUNIT_ASSERT ( root.HasAttribute("aa") );

	KElement c=root.AppendElement("Comment",WString::emptyStr);
	CPPUNIT_ASSERT_EQUAL( root.GetNamespaceURI(), c.GetNamespaceURI() );
	KElement f = root.InsertBefore("fnarf",c,WString::emptyStr);
	CPPUNIT_ASSERT_EQUAL( root.GetNamespaceURI(), f.GetNamespaceURI() );
	CPPUNIT_ASSERT( !f.GetNamespaceURI().empty() );
	CPPUNIT_ASSERT_EQUAL( WString("http://www.CIP4.org/JDFSchema_1_1"), f.GetNamespaceURI() );
	KElement f2 = root.InsertBefore("fnarf:fnarf",c,"www.fnarf");
	CPPUNIT_ASSERT_EQUAL( WString("www.fnarf"), f2.GetNamespaceURI() );

	try
	{
		e.AppendElement("Kai:Test1");
		// assume that the namespace will be added later
	}
	catch(const JDFException&)
	{
		//do nothing
	}

	WString testIt;
	jdfDoc.Write2String(testIt);
	JDFParser p;
	p.StringParse(testIt, false);
	JDFDoc d2=p.GetDocument();
	root = (JDFNode) d2.GetRoot();
	root.SetAttribute("aa","nsns",root.GetNamespaceURI());
	
	CPPUNIT_ASSERT( !root.HasAttribute("ns1:aa") );
	CPPUNIT_ASSERT_EQUAL( WString("nsns"), root.GetAttribute("aa",root.GetNamespaceURI(),WString::emptyStr) );
	root.SetAttribute("bb:aa","nsnt",root.GetNamespaceURI());
	CPPUNIT_ASSERT( root.HasAttribute("aa") );
	CPPUNIT_ASSERT( root.HasAttribute("bb:aa") );
	CPPUNIT_ASSERT_EQUAL( WString("nsnt"), root.GetAttribute("aa",root.GetNamespaceURI(),WString::emptyStr) );
	CPPUNIT_ASSERT_EQUAL( WString("nsnt"), root.GetAttribute("aa",WString::emptyStr,WString::emptyStr) );
}

void KElementTest::testXMLNameSpace()
{
	CPPUNIT_ASSERT( KElement::XMLNSPrefix(WString("abc").c_str()) == WString::emptyStr );
	CPPUNIT_ASSERT( KElement::XMLNSPrefix(WString(":abc").c_str()) == WString::emptyStr );
	CPPUNIT_ASSERT_EQUAL( WString("ns"), KElement::XMLNSPrefix(WString("ns:abc").c_str()) );
	CPPUNIT_ASSERT_EQUAL( WString("abc"), KElement::XMLNSLocalName(WString("ns:abc").c_str()) );
	CPPUNIT_ASSERT( KElement::XMLNSLocalName(WString("abc:").c_str()) == WString::emptyStr );
	CPPUNIT_ASSERT( KElement::XMLNSLocalName(NULL) == WString::emptyStr );
}

void KElementTest::testAppendAttribute()
{
	XMLDoc d("e",WString::emptyStr);
	KElement e=d.GetRoot();
	e.AppendAttribute("at","a",WString::emptyStr,WString::blank,false);
	e.AppendAttribute("at","b",WString::emptyStr,WString::blank,false);
	e.AppendAttribute("at","c",WString::emptyStr,WString::blank,false);
	CPPUNIT_ASSERT_EQUAL( WString("a b c"), e.GetAttribute("at") );
	e.AppendAttribute("at","c",WString::emptyStr,WString::blank,true);
	CPPUNIT_ASSERT_EQUAL( WString("a b c"), e.GetAttribute("at") );
	e.AppendAttribute("at","c",WString::emptyStr,WString::blank,false);
	CPPUNIT_ASSERT_EQUAL( WString("a b c c"), e.GetAttribute("at") );
	e.AppendAttribute("at","a a b c",WString::emptyStr,WString::blank,true);
	CPPUNIT_ASSERT_EQUAL( WString("a b c c a a b c"), e.GetAttribute("at") );
	e.AppendAttribute("ns:key","na","www.ns.com",WString::blank,true);
	CPPUNIT_ASSERT_EQUAL( WString("na"), e.GetAttribute("key","www.ns.com", WString::emptyStr) );
	e.AppendAttribute("ns:key","nb",WString::emptyStr,WString::blank,true);
	CPPUNIT_ASSERT_EQUAL( WString("na nb"), e.GetAttribute("ns:key") );
	// error in Xerces::DOMElement::getAttributeNodeNS(), C++ only
	//e.AppendAttribute("ns:key","nc","www.ns.com",WString::blank,true);
	//
	//CPPUNIT_ASSERT_EQUAL( WString("na nb nc"), e.GetAttribute("key","www.ns.com",WString::emptyStr) );
	//CPPUNIT_ASSERT_EQUAL( WString("na nb nc"), e.GetAttribute("ns:key") );
}

void KElementTest::testTextMethods()
{
	XMLDoc d("doc", WString::emptyStr);
	KElement root = d.GetRoot();
	KElement e1 = root.AppendElement("e1");
	e1.SetAttribute("a", "b");

	e1.SetText("foo");
	CPPUNIT_ASSERT_EQUAL( WString("foo"), e1.GetText() );
	CPPUNIT_ASSERT( e1.HasChildText() );

	e1.SetText("bar");
	CPPUNIT_ASSERT_EQUAL( WString("bar"), e1.GetText() );
	CPPUNIT_ASSERT( e1.HasChildText() );

	e1.RemoveText();
	CPPUNIT_ASSERT_EQUAL( WString::emptyStr, e1.GetText() );
	CPPUNIT_ASSERT( !e1.HasChildText() );

	e1.AppendText("foo");
	CPPUNIT_ASSERT_EQUAL( WString("foo"), e1.GetText() );
	CPPUNIT_ASSERT( e1.HasChildText() );

	e1.AppendText("bar");
	CPPUNIT_ASSERT_EQUAL( WString("foobar"), e1.GetText() );
	CPPUNIT_ASSERT( e1.HasChildText() );
	
	CPPUNIT_ASSERT_EQUAL( 2,e1.getNumChildNodes(3) );
	CPPUNIT_ASSERT_EQUAL( WString("foo"),e1.GetChildText(0) );
	CPPUNIT_ASSERT_EQUAL( WString("bar"),e1.GetChildText(1) );
	CPPUNIT_ASSERT( e1.HasChildText() );

	e1.RemoveChildText(1);
	CPPUNIT_ASSERT_EQUAL( 1,e1.getNumChildNodes(3) );
	CPPUNIT_ASSERT_EQUAL( WString("foo"),e1.GetChildText(0) );
	CPPUNIT_ASSERT( e1.HasChildText() );

	e1.RemoveChildText(0);
	CPPUNIT_ASSERT_EQUAL( 0, e1.getNumChildNodes(3) );
	CPPUNIT_ASSERT_EQUAL( WString::emptyStr, e1.GetChildText(0) );
	CPPUNIT_ASSERT( !e1.HasChildText() );

	e1.RemoveText();
	CPPUNIT_ASSERT( !e1.HasChildText() );
	KElement e2 = root.AppendTextElement("e2", "text");

	CPPUNIT_ASSERT_EQUAL( 1, e2.getNumChildNodes(3) );
	CPPUNIT_ASSERT_EQUAL( WString("text"), e2.GetChildText(0) );
}

void KElementTest::testEraseEmptyNodes()
{
	cout << " (warning: this test is *slow*)";
	try
	{
		JDFParser p;
		WString inFile = sm_dirTestData+"bigWhite.jdf";
		p.Parse(inFile, false);
		JDFDoc  jdfDoc = p.GetDocument();
		int inSize = (int)jdfDoc.ToString().size();
		JDFNode root   = (JDFNode) jdfDoc.GetRoot();
		root.EraseEmptyNodes(true);		
		int outSize = (int)jdfDoc.ToString().size();
		CPPUNIT_ASSERT( inSize > outSize );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testGetChildWithAttribute()
{
	try
	{
		XMLDoc doc=XMLDoc("Foo");
		KElement root=doc.GetRoot();
		CPPUNIT_ASSERT_EQUAL( 0, (int)root.GetChildElementVector().size() );
		root.AppendElement("bar:bar","www.bar.com");
		KElement bar2=root.AppendElement("bar2");
		bar2.SetAttribute("foo", "1");
		KElement bar3=bar2.AppendElement("bar3");
		bar3.SetAttribute("foo", "1");
		bar3.SetAttribute("foo2", "2");
		CPPUNIT_ASSERT_EQUAL( bar3.ToString(),root.GetChildWithAttribute(WString::emptyStr, "foo2", WString::emptyStr, WString::star, 0,false).ToString());
		CPPUNIT_ASSERT_EQUAL( bar2.ToString(),root.GetChildWithAttribute(WString::emptyStr, "foo", WString::emptyStr, WString::star, 0,false).ToString() );
		CPPUNIT_ASSERT_EQUAL( bar3.ToString(),root.GetChildWithAttribute(WString::emptyStr, "foo", WString::emptyStr, WString::star, 1,false).ToString() );
		CPPUNIT_ASSERT_EQUAL( bar2.ToString(),root.GetChildWithAttribute(WString::emptyStr, "foo", WString::emptyStr, WString::star, 0,true).ToString() );
		CPPUNIT_ASSERT_EQUAL( bar2.ToString(),root.GetChildWithAttribute(WString::emptyStr, "foo", WString::emptyStr, "1", 0,true).ToString() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testGetDOMAttr()
{
	// info: JDFNode::GetAttribute() is a wrapper for KElement::GetDOMAttr()
	try
	{
		XMLDoc xd=XMLDoc("a", WString::emptyStr);
		KElement root=xd.GetRoot();
		root.SetAttribute("at","b");
		KElement child=root.AppendElement("child");
		CPPUNIT_ASSERT( child.GetAttribute("at").empty() );
		CPPUNIT_ASSERT( child.GetAttribute("at_notther").empty() );
		CPPUNIT_ASSERT_EQUAL( (WString)"b",root.GetAttribute("at") );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testGetElement()
{
	try
	{
		//XMLDoc d=XMLDoc("root");
		JDFDoc d = JDFDoc(0);
		KElement root=d.GetRoot();
		KElement c1=root.AppendElement("c");
		KElement c2=root.AppendElement("c");
		KElement b1=root.AppendElement("b");
		KElement c3=root.AppendElement("c");
		CPPUNIT_ASSERT_EQUAL( c1,root.GetElement("c") );
		CPPUNIT_ASSERT_EQUAL( b1,root.GetElement("b") );
		CPPUNIT_ASSERT_EQUAL( c1,root.GetElement("c",WString::emptyStr,0) );
		CPPUNIT_ASSERT_EQUAL( b1,root.GetElement("b",WString::emptyStr,-1) );
		CPPUNIT_ASSERT_EQUAL( c1,root.GetElement("c",WString::emptyStr,-3) );
		CPPUNIT_ASSERT_EQUAL( c3,root.GetElement("c",WString::emptyStr,-1) );
		CPPUNIT_ASSERT_EQUAL( c2,root.GetElement("c",WString::emptyStr,1) );
		CPPUNIT_ASSERT_EQUAL( c2,root.GetElement("c",WString::emptyStr,-2) );
		CPPUNIT_ASSERT_EQUAL( c1,root.GetElement(WString::emptyStr,WString::emptyStr,-4) );
		CPPUNIT_ASSERT_EQUAL( b1,root.GetElement(WString::emptyStr,WString::emptyStr,3) );
		CPPUNIT_ASSERT( root.GetElement("c",WString::emptyStr,-4).isNull() );
		CPPUNIT_ASSERT( root.GetElement("c",WString::emptyStr,3).isNull() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testRemoveFromAttribute()
{
	try
	{
		XMLDoc d=XMLDoc("Foo");
		KElement e=d.GetRoot();
		e.SetAttribute("a", "1 b 2");
		e.RemoveFromAttribute("a", "b", WString::emptyStr, WString::blank, 333);
		CPPUNIT_ASSERT_EQUAL( (WString)"1 2",e.GetAttribute("a") );
		e.SetAttribute("a", "c");
		e.RemoveFromAttribute("a", "c", WString::emptyStr, WString::blank, 333);
		CPPUNIT_ASSERT( e.GetAttribute("a").empty() );
		e.RemoveFromAttribute("a", "c", WString::emptyStr, WString::blank, 333);
		CPPUNIT_ASSERT( e.GetAttribute("a").empty() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testMoveAttribute()
{
	try
	{
		XMLDoc doc = XMLDoc("Test","www.test.com");
		KElement root=doc.GetRoot();
		KElement a=root.AppendElement("a");
		KElement b=root.AppendElement("b");
		a.SetAttribute("att", "42");
		b.MoveAttribute("att", a);
		CPPUNIT_ASSERT_EQUAL( (WString)"42",b.GetAttribute("att") );
		CPPUNIT_ASSERT( a.GetAttribute("att").empty() );
		b.MoveAttribute("noThere", a);
		CPPUNIT_ASSERT( b.GetAttribute("noThere").empty() );
		CPPUNIT_ASSERT( a.GetAttribute("noThere").empty() );
		a.SetAttribute("foo", "a");
		b.MoveAttribute("bar", a, "foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"a",b.GetAttribute("bar") );
		CPPUNIT_ASSERT( a.GetAttribute("bar").empty() );
		CPPUNIT_ASSERT( b.GetAttribute("foo").empty() );
		CPPUNIT_ASSERT( a.GetAttribute("foo").empty() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testCopyAttribute()
{
	try
	{
		XMLDoc doc = XMLDoc("Test","www.test.com");
		KElement root=doc.GetRoot();
		KElement a=root.AppendElement("a");
		KElement b=root.AppendElement("b");
		a.SetAttribute("att", "42");
		b.CopyAttribute("att", a);
		CPPUNIT_ASSERT_EQUAL( (WString)"42",a.GetAttribute("att") );
		CPPUNIT_ASSERT_EQUAL( (WString)"42",b.GetAttribute("att") );
		b.CopyAttribute("noThere", a);
		CPPUNIT_ASSERT( b.GetAttribute("noThere").empty() );
		CPPUNIT_ASSERT( a.GetAttribute("noThere").empty() );
		a.SetAttribute("foo", "a");
		b.CopyAttribute("bar", a, "foo");

		CPPUNIT_ASSERT_EQUAL( (WString)"a",b.GetAttribute("bar") );
		CPPUNIT_ASSERT_EQUAL( (WString)"a",a.GetAttribute("foo") );
		CPPUNIT_ASSERT( a.GetAttribute("bar").empty() );
		CPPUNIT_ASSERT( b.GetAttribute("foo").empty() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testInsertBefore()
{
	try
	{
		XMLDoc jdfDoc = XMLDoc("Test","www.test.com");
		KElement e = jdfDoc.GetRoot();
		KElement k1=jdfDoc.CreateElement("second");
		KElement k2=jdfDoc.CreateElement("first");
		KElement k01=e.InsertBefore(k1, KElement::DefKElement);
		KElement k02=e.InsertBefore(k2, k1);
		CPPUNIT_ASSERT_EQUAL( k1,k01 );
		CPPUNIT_ASSERT_EQUAL( k2,k02 );
		CPPUNIT_ASSERT_EQUAL( k1,k2.GetNextSiblingElement() );;
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testAppendElement()
{
	try
	{
		JDFDoc d=JDFDoc(0);
		KElement e=d.GetRoot();
		CPPUNIT_ASSERT( !e.GetNamespaceURI().empty() );
		KElement foo=e.AppendElement("pt:foo", "www.pt.com");
		CPPUNIT_ASSERT_EQUAL( (WString)"www.pt.com",foo.GetNamespaceURI() );
		KElement bar=foo.AppendElement("bar");
		CPPUNIT_ASSERT( !bar.GetNamespaceURI().empty() );
		KElement foo2=bar.AppendElement("pt:foo", "www.pt.com");
		CPPUNIT_ASSERT_EQUAL( (WString)"www.pt.com",foo2.GetNamespaceURI() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testSetGetXSIType()
{
	try
	{
		JDFDoc d = JDFDoc(0);
		JDFNode root = d.GetJDFRoot();
		KElement e = root.AppendElement("foo");
		e.setXSIType("bar");
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",e.getXSIType() );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}

void KElementTest::testSetGetAttribute()
{
	try
	{
		JDFDoc doc = JDFDoc(0);
		JDFNode root = doc.GetJDFRoot();

		JDFMedia m = root.addResource(JDFResource::elm_Media, JDFResource::Class_Consumable, JDFResourceLink::Usage_Input);
		CPPUNIT_ASSERT( !m.HasAttribute(JDFMedia::atr_DescriptiveName) );
		m.SetAttribute(JDFMedia::atr_DescriptiveName, "some name");
		CPPUNIT_ASSERT_EQUAL( (WString)"some name",m.GetAttribute(JDFMedia::atr_DescriptiveName) );

		m.RemoveAttribute(JDFMedia::atr_DescriptiveName);
		CPPUNIT_ASSERT( !m.HasAttribute(JDFMedia::atr_DescriptiveName) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void KElementTest::testSetAttribute_LongAttValue()
{
	try
	{
		JDFDoc jdfDoc = JDFDoc(0);
		JDFNode root  = (JDFNode) jdfDoc.GetRoot();
        WString longString;
        for(int i=0;i<13;i++)
            longString+=longString+"0 123456789abcdefghijklmnopqrstuvwxyz";
		root.SetAttribute("long", longString);
		CPPUNIT_ASSERT_EQUAL( longString,root.GetAttribute("long") );

		jdfDoc.Write2File(sm_dirTestTemp+"longAtt.jdf");
		JDFParser p;
		p.Parse(sm_dirTestTemp+"longAtt.jdf",false);
		jdfDoc=p.GetDocument();
        root=jdfDoc.GetJDFRoot();
        CPPUNIT_ASSERT_EQUAL( longString,root.GetAttribute("long") );
	}
	catch (const JDFException& ex)
	{
		CPPUNIT_FAIL( ex.what() );
	}
}