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
// created 10 Aug 2006
//
// JDFNodeTest.h: interface for the JDFNodeTest class.
//
///////////////////////////////////////////////////////////////////////

#ifndef JDFNODETEST_H
#define JDFNODETEST_H

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

#pragma once

class JDFNodeTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE( JDFNodeTest );
		CPPUNIT_TEST( testSetType );
		CPPUNIT_TEST( testLinkResourceNS );
		CPPUNIT_TEST( testInsertTypeInTypes );
		CPPUNIT_TEST( testLinkNamesCombined );
		CPPUNIT_TEST( testLinkNamesProduct );
		CPPUNIT_TEST( testLinkResourceSimple );
		CPPUNIT_TEST( testLinkResourceCombined );
		CPPUNIT_TEST( testAddResource );
		CPPUNIT_TEST( testAddInternalPipe );
		CPPUNIT_TEST( testCloneResourceToModify );
		CPPUNIT_TEST( testEraseEmptyAttributes );
		CPPUNIT_TEST( testEraseEmptyNodes );
		CPPUNIT_TEST( testResourceAudit );
		CPPUNIT_TEST( testSetPartStatusNull );
		CPPUNIT_TEST( testSetPartStatusNotNull );
		CPPUNIT_TEST( testSetPhase );
		CPPUNIT_TEST( testInit );
		CPPUNIT_TEST( testIsValid );
		CPPUNIT_TEST( testIsExecutable );
		CPPUNIT_TEST( testGetInheritedNodeInfo );
		CPPUNIT_TEST( testGetCreateNodeInfo );
		CPPUNIT_TEST( testCreateNodeInfo );
		CPPUNIT_TEST( testGetvJDFNode );
		CPPUNIT_TEST( testGetPartStatus );
		CPPUNIT_TEST( testGenericResources );
		CPPUNIT_TEST( testProductValidation );
		CPPUNIT_TEST( testGrayBox );
		CPPUNIT_TEST( testAppendMatchingResourceProduct );
		CPPUNIT_TEST( testAppendMatchingResourcePrivate );
		CPPUNIT_TEST( testAppendMatchingResource );
		CPPUNIT_TEST( testGetParentJDF );
		CPPUNIT_TEST( testGetEnumTypes );
		CPPUNIT_TEST( testGetAllTypes );
		CPPUNIT_TEST( testGetMatchingResource );
		CPPUNIT_TEST( testGetLinksForType );
		CPPUNIT_TEST( testGetMatchingResourceStar );
		CPPUNIT_TEST( testGetMissingLinks );
		CPPUNIT_TEST( testGetMissingLinksProduct );
		CPPUNIT_TEST( testGetUnknownLinks );
		CPPUNIT_TEST( testGetActivation );
		CPPUNIT_TEST( testGetLink );
	CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void testSetType();
		void testLinkResourceNS();
		void testInsertTypeInTypes();
		void testLinkNamesCombined();
		void testLinkNamesProduct();
		void testLinkResourceSimple();
		void testLinkResourceCombined();
		void testAddResource();
		void testAddInternalPipe();
		void testCloneResourceToModify();
		void testEraseEmptyAttributes();
		void testEraseEmptyNodes();
		void testResourceAudit();
		void testSetPartStatusNull();
		void testSetPartStatusNotNull();
		void testSetPhase();
		void testInit();
		void testIsValid();
		void testIsExecutable();
		void testGetInheritedNodeInfo();
		void testGetCreateNodeInfo();
		void testCreateNodeInfo();
		void testGetvJDFNode();
		void testGetPartStatus();
		void testGenericResources();
		void testProductValidation();
		void testGrayBox();
		void testAppendMatchingResourceProduct();
		void testAppendMatchingResourcePrivate();
		void testAppendMatchingResource();
		void testGetParentJDF();
		void testGetEnumTypes();
		void testGetAllTypes();
		void testGetMatchingResource();
		void testGetLinksForType();
		void testGetMatchingResourceStar();
		void testGetMissingLinks();
		void testGetMissingLinksProduct();
		void testGetUnknownLinks();
		void testGetActivation();
		void testGetLink();
		void testSortChildren();
};

#endif
