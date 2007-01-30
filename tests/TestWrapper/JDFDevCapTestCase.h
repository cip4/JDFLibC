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
// created before 27 Jul 2006
//
// JDFDevCapTestCase.h: interface for the JDFDevCapTestCase class.
//
///////////////////////////////////////////////////////////////////////

#ifndef JDFDEVCAPTESTCASE_H
#define JDFDEVCAPTESTCASE_H

#pragma once

#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>


class JDFDevCapTestCase : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE( JDFDevCapTestCase );
		CPPUNIT_TEST ( testBooleanState );
		CPPUNIT_TEST ( testIntegerState );
		CPPUNIT_TEST ( testNumberState );
		CPPUNIT_TEST ( testEnumerationState );
		CPPUNIT_TEST ( testNameState );
		CPPUNIT_TEST ( testGetBooleanState );
		CPPUNIT_TEST ( testGetIntegerState );
		CPPUNIT_TEST ( testGetNumberState );
		CPPUNIT_TEST ( testGetEnumerationState );
		CPPUNIT_TEST ( testGetNameState );
		CPPUNIT_TEST ( testGetXYPairState );
		CPPUNIT_TEST ( testGetShapeState );
		CPPUNIT_TEST ( testGetMatrixState );
		CPPUNIT_TEST ( testGetDateTimeState );
		CPPUNIT_TEST ( testGetDurationState );
		CPPUNIT_TEST ( testGetPDFPathState );
		CPPUNIT_TEST ( testGetRectangleState );
	CPPUNIT_TEST_SUITE_END();


	public:
		void setUp();
		void testBooleanState();
		void testIntegerState();
		void testNumberState();
		void testEnumerationState();
		void testNameState();
		void testGetBooleanState();
		void testGetIntegerState();
		void testGetNumberState();
		void testGetEnumerationState();
		void testGetNameState();
		void testGetXYPairState();
		void testGetShapeState();
		void testGetMatrixState();
		void testGetDateTimeState();
		void testGetDurationState();
		void testGetPDFPathState();
		void testGetRectangleState();
};

#endif
