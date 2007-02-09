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
// created before 21 Jul 2006
//
// JDFTestCase.cpp: implements CppUnit test cases for JDFDevCap/xxxStates
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdftestcase.h"

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFTestCase);


void JDFTestCase::setUp()
{
	// Initialize the JDFTools system
	try	
	{
		JDF::PlatformUtils::Initialize();
	}
	catch (const JDF::Exception& e)	
	{
		e.getMessage();
		//cout << e.getMessage() << endl;
	}
}


/** test XxxState ***********************************************************/
void JDFTestCase::testBooleanState()
{
	XMLDoc doc("BooleanState");
	JDFBooleanState bs = doc.GetRoot();
	vint values;
	values.add(0);
	bs.SetAllowedValueList(values);
	// TODO compare list type location Java<->C++ (EnumFitsType, ListType)
	CPPUNIT_ASSERT(bs.FitsValue("true", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(bs.FitsValue("false", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!bs.FitsValue("fnarf", JDFElement::FitsValue_Allowed));

	values.clear();
	values.add(1);
	bs.SetAllowedValueList(values);
	CPPUNIT_ASSERT(!bs.FitsValue("true", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(bs.FitsValue("false", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!bs.FitsValue("fnarf", JDFElement::FitsValue_Allowed));

	values.clear();
	values.add(2);
	bs.SetAllowedValueList(values);
	CPPUNIT_ASSERT(bs.FitsValue("true", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!bs.FitsValue("false", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!bs.FitsValue("fnarf", JDFElement::FitsValue_Allowed));
}

void JDFTestCase::testIntegerState()
{
	XMLDoc doc("IntegerState");
	JDFIntegerState is = doc.GetRoot();
	
	JDFIntegerRangeList irl = JDFIntegerRangeList("12~15");
	is.SetAllowedValueList(irl);
	is.SetListType(JDFStateBase::ListType_RangeList);
	CPPUNIT_ASSERT(is.FitsValue("12~15", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!is.FitsValue("19~33", JDFElement::FitsValue_Allowed));

	irl = JDFIntegerRangeList("12~15 19~33");
	is.SetAllowedValueList(irl);
	CPPUNIT_ASSERT(is.FitsValue("12~15", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(is.FitsValue("19~33", JDFElement::FitsValue_Allowed));
}

void JDFTestCase::testNumberState()
{ 
	XMLDoc doc("NumberState");
	JDFNumberState ns = doc.GetRoot();
	
	JDFNumberRangeList nrl = JDFNumberRangeList("12.45~15.88");
	ns.SetAllowedValueList(nrl);
	ns.SetListType(JDFStateBase::ListType_RangeList);
	CPPUNIT_ASSERT(ns.FitsValue("12.45~15.88", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!ns.FitsValue("19.0~33.234", JDFElement::FitsValue_Allowed));

	nrl = JDFNumberRangeList("12.45~15.88 19.0~33.234");
	ns.SetAllowedValueList(nrl);
	CPPUNIT_ASSERT(ns.FitsValue("12.45~15.88", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(ns.FitsValue("19.0~33.234", JDFElement::FitsValue_Allowed));
}

void JDFTestCase::testEnumerationState()
{
	XMLDoc doc("EnumerationState");
	JDFEnumerationState es = doc.GetRoot();
	vWString values;
	values.add("foo");
	values.add("bar");

	es.SetAllowedValueList(values);
	CPPUNIT_ASSERT(es.FitsValue("foo", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(es.FitsValue("bar", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!es.FitsValue("fnarf", JDFElement::FitsValue_Allowed));
	
	es.SetListType(JDF::JDFStateBase::ListType_List);
	CPPUNIT_ASSERT(es.FitsValue("foo", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(es.FitsValue("foo bar", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(es.FitsValue("bar foo", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(es.FitsValue("foo bar foo", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!es.FitsValue("foo bar fnarf", JDFElement::FitsValue_Allowed));

	es.SetListType(JDF::JDFStateBase::ListType_CompleteList);
	CPPUNIT_ASSERT(!es.FitsValue("foo", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(es.FitsValue("foo bar", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(es.FitsValue("bar foo", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!es.FitsValue("foo bar foo", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!es.FitsValue("foo bar fnarf", JDFElement::FitsValue_Allowed));
}
void JDFTestCase::testNameState()
{
	XMLDoc doc("NameState");
	JDFNameState ns = doc.GetRoot();
	vWString values;

	values.add("anna~berta");
	ns.SetAllowedValueList(values);
	CPPUNIT_ASSERT(ns.FitsValue("anna~berta", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(!ns.FitsValue("hans~otto", JDFElement::FitsValue_Allowed));

	values.add("anna~berta hans~otto");
	ns.SetAllowedValueList(values);
	CPPUNIT_ASSERT(ns.FitsValue("anna~berta", JDFElement::FitsValue_Allowed));
	CPPUNIT_ASSERT(ns.FitsValue("hans~otto", JDFElement::FitsValue_Allowed));
}

/*** test getXxxState *******************************************************/
void JDFTestCase::testGetBooleanState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFBooleanState bs = dc.AppendBooleanState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", bs.GetName());
	bs = dc.GetBooleanState( (WString)"bar" );
	CPPUNIT_ASSERT( bs.isNull() );
	bs = dc.GetCreateBooleanState( (WString)"bar" );
	CPPUNIT_ASSERT( !bs.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", bs.GetName());
	bs = dc.GetBooleanState("bar");
	CPPUNIT_ASSERT( !bs.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", bs.GetName());
}

void JDFTestCase::testGetIntegerState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFIntegerState is = dc.AppendIntegerState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", is.GetName());
	is = dc.GetIntegerState( (WString)"bar" );
	CPPUNIT_ASSERT( is.isNull() );
	is = dc.GetCreateIntegerState( (WString)"bar" );
	CPPUNIT_ASSERT( !is.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", is.GetName());
	is = dc.GetIntegerState("bar");
	CPPUNIT_ASSERT( !is.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", is.GetName());
}

void JDFTestCase::testGetNumberState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFNumberState ns = dc.AppendNumberState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", ns.GetName());
	ns = dc.GetNumberState( (WString)"bar" );
	CPPUNIT_ASSERT( ns.isNull() );
	ns = dc.GetCreateNumberState( (WString)"bar" );
	CPPUNIT_ASSERT( !ns.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ns.GetName());
	ns = dc.GetNumberState("bar");
	CPPUNIT_ASSERT( !ns.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ns.GetName());
}

void JDFTestCase::testGetEnumerationState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFEnumerationState es = dc.AppendEnumerationState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", es.GetName());
	es = dc.GetEnumerationState( (WString)"bar" );
	CPPUNIT_ASSERT( es.isNull() );
	es = dc.GetCreateEnumerationState( (WString)"bar" );
	CPPUNIT_ASSERT( !es.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", es.GetName());
	es = dc.GetEnumerationState("bar");
	CPPUNIT_ASSERT( !es.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", es.GetName());
}

void JDFTestCase::testGetNameState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFNameState ns = dc.AppendNameState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", ns.GetName());
	ns = dc.GetNameState( (WString)"bar" );
	CPPUNIT_ASSERT( ns.isNull() );
	ns = dc.GetCreateNameState( (WString)"bar" );
	CPPUNIT_ASSERT( !ns.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ns.GetName());
	ns = dc.GetNameState("bar");
	CPPUNIT_ASSERT( !ns.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ns.GetName());
}

void JDFTestCase::testGetStringState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFStringState ss = dc.AppendStringState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", ss.GetName());
	ss = dc.GetStringState( (WString)"bar" );
	CPPUNIT_ASSERT( ss.isNull() );
	ss = dc.GetCreateStringState( (WString)"bar" );
	CPPUNIT_ASSERT( !ss.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ss.GetName());
	ss = dc.GetStringState("bar");
	CPPUNIT_ASSERT( !ss.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ss.GetName());
}

void JDFTestCase::testGetXYPairState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFXYPairState ps = dc.AppendXYPairState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", ps.GetName());
	ps = dc.GetXYPairState( (WString)"bar" );
	CPPUNIT_ASSERT( ps.isNull() );
	ps = dc.GetCreateXYPairState( (WString)"bar" );
	CPPUNIT_ASSERT( !ps.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ps.GetName());
	ps = dc.GetXYPairState("bar");
	CPPUNIT_ASSERT( !ps.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ps.GetName());
}

void JDFTestCase::testGetShapeState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFShapeState ss = dc.AppendShapeState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", ss.GetName());
	ss = dc.GetShapeState( (WString)"bar" );
	CPPUNIT_ASSERT( ss.isNull() );
	ss = dc.GetCreateShapeState( (WString)"bar" );
	CPPUNIT_ASSERT( !ss.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ss.GetName());
	ss = dc.GetShapeState("bar");
	CPPUNIT_ASSERT( !ss.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ss.GetName());
}

void JDFTestCase::testGetMatrixState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFMatrixState ms = dc.AppendMatrixState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", ms.GetName());
	ms = dc.GetMatrixState( (WString)"bar" );
	CPPUNIT_ASSERT( ms.isNull() );
	ms = dc.GetCreateMatrixState( (WString)"bar" );
	CPPUNIT_ASSERT( !ms.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ms.GetName());
	ms = dc.GetMatrixState("bar");
	CPPUNIT_ASSERT( !ms.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ms.GetName());
}

void JDFTestCase::testGetDateTimeState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFDateTimeState dts = dc.AppendDateTimeState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", dts.GetName());
	dts = dc.GetDateTimeState( (WString)"bar" );
	CPPUNIT_ASSERT( dts.isNull() );
	dts = dc.GetCreateDateTimeState( (WString)"bar" );
	CPPUNIT_ASSERT( !dts.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", dts.GetName());
	dts = dc.GetDateTimeState("bar");
	CPPUNIT_ASSERT( !dts.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", dts.GetName());
}

void JDFTestCase::testGetDurationState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFDurationState ds = dc.AppendDurationState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", ds.GetName());
	ds = dc.GetDurationState( (WString)"bar" );
	CPPUNIT_ASSERT( ds.isNull() );
	ds = dc.GetCreateDurationState( (WString)"bar" );
	CPPUNIT_ASSERT( !ds.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ds.GetName());
	ds = dc.GetDurationState("bar");
	CPPUNIT_ASSERT( !ds.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ds.GetName());
}

void JDFTestCase::testGetPDFPathState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFPDFPathState ps = dc.AppendPDFPathState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", ps.GetName());
	ps = dc.GetPDFPathState( (WString)"bar" );
	CPPUNIT_ASSERT( ps.isNull() );
	ps = dc.GetCreatePDFPathState( (WString)"bar" );
	CPPUNIT_ASSERT( !ps.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ps.GetName());
	ps = dc.GetPDFPathState("bar");
	CPPUNIT_ASSERT( !ps.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", ps.GetName());
}

void JDFTestCase::testGetRectangleState()
{
	XMLDoc doc("DevCap");
	JDFDevCap dc = doc.GetRoot();
	JDFRectangleState rs = dc.AppendRectangleState("foo");
	CPPUNIT_ASSERT_EQUAL((WString)"foo", rs.GetName());
	rs = dc.GetRectangleState( (WString)"bar" );
	CPPUNIT_ASSERT( rs.isNull() );
	rs = dc.GetCreateRectangleState( (WString)"bar" );
	CPPUNIT_ASSERT( !rs.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", rs.GetName());
	rs = dc.GetRectangleState("bar");
	CPPUNIT_ASSERT( !rs.isNull() );
	CPPUNIT_ASSERT_EQUAL((WString)"bar", rs.GetName());
}
