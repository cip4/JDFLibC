/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
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
// KElementTest.h: interface for the KElementTest class.
//
///////////////////////////////////////////////////////////////////////

#ifndef KELEMENTTEST_H
#define KELEMENTTEST_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#pragma once

class KElementTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE( KElementTest );
		CPPUNIT_TEST ( testRemoveAttributeStringString );
		CPPUNIT_TEST ( testRenameElement );
		CPPUNIT_TEST ( testReplaceElement );
		CPPUNIT_TEST ( testRemoveEmptyAttributes );
		CPPUNIT_TEST ( testRemoveAttribute );
		CPPUNIT_TEST ( testNameSpace );
		CPPUNIT_TEST ( testNameSpaceInElements );
		CPPUNIT_TEST ( testNameSpace1 );
		CPPUNIT_TEST ( testNameSpaceInAttributes );
		CPPUNIT_TEST ( testGetPrefix );
		CPPUNIT_TEST ( testGetLocalName );
		CPPUNIT_TEST ( testGetCreateElement );
		CPPUNIT_TEST ( testGetMatchesPath );
		CPPUNIT_TEST ( testGetDeepParentChild );
		CPPUNIT_TEST ( testGetDeepParentNotName );
		CPPUNIT_TEST ( testInfinity );
		CPPUNIT_TEST ( testSetAttribute );
		CPPUNIT_TEST ( testCache );
		CPPUNIT_TEST ( testGetChildrenByTagName );
		CPPUNIT_TEST ( testGetChildElementVector );
		CPPUNIT_TEST ( testPushUp );
		CPPUNIT_TEST ( testSetAttribute_NameSpaceHandling );
		CPPUNIT_TEST ( testXMLNameSpace );
		CPPUNIT_TEST ( testAppendAttribute );
		CPPUNIT_TEST ( testTextMethods );
		CPPUNIT_TEST ( testEraseEmptyNodes );
		CPPUNIT_TEST ( testGetChildWithAttribute );
		CPPUNIT_TEST ( testGetDOMAttr );
		CPPUNIT_TEST ( testGetElement );
		CPPUNIT_TEST ( testRemoveFromAttribute );
		CPPUNIT_TEST ( testMoveAttribute );
		CPPUNIT_TEST ( testCopyAttribute );
		CPPUNIT_TEST ( testInsertBefore );
		CPPUNIT_TEST ( testAppendElement );
		CPPUNIT_TEST ( testSetGetXSIType );
		CPPUNIT_TEST ( testSetGetAttribute );
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void testRemoveAttributeStringString();
		void testRenameElement();
		void testReplaceElement();
		void testRemoveEmptyAttributes();
		void testRemoveAttribute();
		void testNameSpace();
		void testNameSpaceInElements();
		void testNameSpace1();
		void testNameSpaceInAttributes();
		void testGetPrefix();
		void testGetLocalName();
		void testGetCreateElement();
		void testGetMatchesPath();
		void testGetDeepParentChild();
		void testGetDeepParentNotName();
		void testInfinity();
		void testSetAttribute();
		void testCache();
		void testGetChildrenByTagName();
		void testGetChildElementVector();
		void testPushUp();
		void testSetAttribute_NameSpaceHandling();
		void testXMLNameSpace();
		void testAppendAttribute();
		void testTextMethods();
		void testEraseEmptyNodes();
		void testGetChildWithAttribute();
		void testGetDOMAttr();
		void testGetElement();
		void testRemoveFromAttribute();
		void testMoveAttribute();
		void testCopyAttribute();
		void testInsertBefore();
		void testAppendElement();
		void testSetGetXSIType();
		void testSetGetAttribute();
};

#endif
