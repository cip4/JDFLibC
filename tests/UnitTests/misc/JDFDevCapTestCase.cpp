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
// created before 27 Jul 2006
//
// JDFDevCapTestCase.cpp: implements CppUnit test cases for JDFDevCaps
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "JDFDevCapTestCase.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFDevCapTestCase);



void JDFDevCapTestCase::setUp()
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

void JDFDevCapTestCase::testBooleanState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFBooleanState bs = n.AppendElement(JDFElement::elm_BooleanState);
		vint v;
		v.add(1); // 0-Unknown,1-false,2-true

		bs.SetAllowedValueList(v);
		CPPUNIT_ASSERT( bs.FitsValue("false",JDFBooleanState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( !bs.FitsValue("fnarf",JDFBooleanState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( !bs.FitsValue("true",JDFBooleanState::FitsValue_Allowed) );
		v.add(2);
		bs.SetAllowedValueList(v);
		CPPUNIT_ASSERT( bs.FitsValue("true",JDFBooleanState::FitsValue_Allowed) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testIntegerState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFIntegerState is = n.AppendElement(JDFElement::elm_IntegerState);
		JDFIntegerRangeList irl = JDFIntegerRangeList("12~15");
		is.SetAllowedValueList(irl);
		is.SetListType(JDFIntegerState::ListType_RangeList);
		CPPUNIT_ASSERT( is.FitsValue("12~15",JDFIntegerState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( !is.FitsValue("19~33",JDFIntegerState::FitsValue_Allowed) );

		irl = JDFIntegerRangeList("12~15 19~33");
		is.SetAllowedValueList(irl);
		CPPUNIT_ASSERT( is.FitsValue("12~15",JDFIntegerState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( is.FitsValue("19~33",JDFIntegerState::FitsValue_Allowed) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testNumberState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFNumberState ns = n.AppendElement(JDFElement::elm_NumberState);
		JDFNumberRangeList nrl = JDFNumberRangeList("12.45~15.88");
		ns.SetAllowedValueList(nrl);
		ns.SetListType(JDFNumberState::ListType_RangeList);

		CPPUNIT_ASSERT( ns.FitsValue("12.45~15.88", JDFNumberState::FitsValue_Allowed));
		CPPUNIT_ASSERT( ns.FitsValue("12.45~13.0", JDFNumberState::FitsValue_Allowed));
		CPPUNIT_ASSERT( !ns.FitsValue("19.0~33.234", JDFNumberState::FitsValue_Allowed));
		nrl = JDFNumberRangeList("12.45~15.88 19.0~33.234");
		ns.SetAllowedValueList(nrl);
		CPPUNIT_ASSERT( ns.FitsValue("12.45", JDFNumberState::FitsValue_Allowed));
		CPPUNIT_ASSERT( ns.FitsValue("19.0~33.234", JDFNumberState::FitsValue_Allowed));
		CPPUNIT_ASSERT( !ns.FitsValue("16.01", JDFNumberState::FitsValue_Allowed));
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testEnumerationState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFEnumerationState es = n.AppendElement(JDFElement::elm_EnumerationState);
		vWString v;
		v.add("foo");
		v.add("bar");

		es.SetAllowedValueList(v);
		CPPUNIT_ASSERT( es.FitsValue("foo",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( es.FitsValue("bar",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( !es.FitsValue("fnarf",JDFEnumerationState::FitsValue_Allowed) );

		es.SetListType(JDFEnumerationState::ListType_List);
		CPPUNIT_ASSERT( es.FitsValue("foo",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( es.FitsValue("foo bar",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( es.FitsValue("foo bar foo",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( !es.FitsValue("foo bar fnarf",JDFEnumerationState::FitsValue_Allowed) );

		es.SetListType(JDFEnumerationState::ListType_CompleteList);
		CPPUNIT_ASSERT( !es.FitsValue("foo",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( es.FitsValue("foo bar",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( es.FitsValue("bar foo",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( !es.FitsValue("foo bar foo",JDFEnumerationState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( !es.FitsValue("foo bar fnarf",JDFEnumerationState::FitsValue_Allowed) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testNameState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFNameState ns = n.AppendElement(JDFElement::elm_NameState);
		vWString nl;
		nl.add("anna~berta");
		ns.SetAllowedValueList(nl);
		ns.SetListType(JDFNameState::ListType_List); // TODO Type_RangeList -> illegal list type for JDFNameState
		ns.FitsValue("anna~berta", JDFNameState::FitsValue_Allowed);
		CPPUNIT_ASSERT( ns.FitsValue("anna~berta", JDFNameState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( !ns.FitsValue("hans~otto", JDFNameState::FitsValue_Allowed) );
		nl.add("anna~berta hans~otto");
		ns.SetAllowedValueList(nl);
		CPPUNIT_ASSERT( ns.FitsValue("anna~berta", JDFNameState::FitsValue_Allowed) );
		CPPUNIT_ASSERT( ns.FitsValue("hans~otto", JDFNameState::FitsValue_Allowed) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetBooleanState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFBooleanState bs = dc.AppendBooleanState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",bs.GetName() );
		bs=dc.GetBooleanState("bar");
		CPPUNIT_ASSERT( bs.isNull() );
		bs = dc.GetCreateBooleanState("bar");
		CPPUNIT_ASSERT( !bs.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",bs.GetName() );
		bs=dc.GetBooleanState("bar");
		CPPUNIT_ASSERT( !bs.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",bs.GetName() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetIntegerState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFIntegerState is = dc.AppendIntegerState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",is.GetName() );
		is=dc.GetIntegerState("bar");
		CPPUNIT_ASSERT( is.isNull() );
		is=dc.GetCreateIntegerState("bar");
		CPPUNIT_ASSERT( !is.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",is.GetName() );
		is=dc.GetIntegerState("bar");
		CPPUNIT_ASSERT( !is.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",is.GetName() );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetNumberState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFNumberState ns=dc.AppendNumberState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",ns.GetName() );
		ns=dc.GetNumberState("bar");
		CPPUNIT_ASSERT( ns.isNull() );
		ns=dc.GetCreateNumberState("bar");
		CPPUNIT_ASSERT( !ns.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ns.GetName() );
		ns=dc.GetNumberState("bar");
		CPPUNIT_ASSERT( !ns.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ns.GetName() );	
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetEnumerationState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFEnumerationState es=dc.AppendEnumerationState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",es.GetName() );
		es=dc.GetEnumerationState("bar");
		CPPUNIT_ASSERT( es.isNull() );
		es=dc.GetCreateEnumerationState("bar");
		CPPUNIT_ASSERT( !es.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",es.GetName() );
		es=dc.GetEnumerationState("bar");
		CPPUNIT_ASSERT( !es.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",es.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetNameState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFStringState ss=dc.AppendStringState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",ss.GetName() );
		ss=dc.GetStringState("bar");
		CPPUNIT_ASSERT( ss.isNull() );
		ss=dc.GetCreateStringState("bar");
		CPPUNIT_ASSERT( !ss.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ss.GetName() );
		ss=dc.GetStringState("bar");
		CPPUNIT_ASSERT( !ss.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ss.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetXYPairState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFXYPairState xy=dc.AppendXYPairState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",xy.GetName() );
		xy=dc.GetXYPairState("bar");
		CPPUNIT_ASSERT( xy.isNull() );
		xy=dc.GetCreateXYPairState("bar");
		CPPUNIT_ASSERT( !xy.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",xy.GetName() );
		xy=dc.GetXYPairState("bar");
		CPPUNIT_ASSERT( !xy.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",xy.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetShapeState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFShapeState ss=dc.AppendShapeState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",ss.GetName() );
		ss=dc.GetShapeState("bar");
		CPPUNIT_ASSERT( ss.isNull() );
		ss=dc.GetCreateShapeState("bar");
		CPPUNIT_ASSERT( !ss.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ss.GetName() );
		ss=dc.GetShapeState("bar");
		CPPUNIT_ASSERT( !ss.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ss.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetMatrixState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFMatrixState ms=dc.AppendMatrixState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",ms.GetName() );
		ms=dc.GetMatrixState("bar");
		CPPUNIT_ASSERT( ms.isNull() );
		ms=dc.GetCreateMatrixState("bar");
		CPPUNIT_ASSERT( !ms.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ms.GetName() );
		ms=dc.GetMatrixState("bar");
		CPPUNIT_ASSERT( !ms.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ms.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetDateTimeState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFDateTimeState dts=dc.AppendDateTimeState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",dts.GetName() );
		dts=dc.GetDateTimeState("bar");
		CPPUNIT_ASSERT( dts.isNull() );
		dts=dc.GetCreateDateTimeState("bar");
		CPPUNIT_ASSERT( !dts.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",dts.GetName() );
		dts=dc.GetDateTimeState("bar");
		CPPUNIT_ASSERT( !dts.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",dts.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetDurationState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFDurationState ds=dc.AppendDurationState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",ds.GetName() );
		ds=dc.GetDurationState("bar");
		CPPUNIT_ASSERT( ds.isNull() );
		ds=dc.GetCreateDurationState("bar");
		CPPUNIT_ASSERT( !ds.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ds.GetName() );
		ds=dc.GetDurationState("bar");
		CPPUNIT_ASSERT( !ds.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",ds.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetPDFPathState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFPDFPathState pps=dc.AppendPDFPathState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",pps.GetName() );
		pps=dc.GetPDFPathState("bar");
		CPPUNIT_ASSERT( pps.isNull() );
		pps=dc.GetCreatePDFPathState("bar");
		CPPUNIT_ASSERT( !pps.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",pps.GetName() );
		pps=dc.GetPDFPathState("bar");
		CPPUNIT_ASSERT( !pps.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",pps.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}

void JDFDevCapTestCase::testGetRectangleState()
{
	try
	{
		JDFDoc d= JDFDoc(0);
		JDFNode n = d.GetJDFRoot();
		JDFDevCap dc = n.AppendElement(JDFElement::elm_DevCap);
		JDFRectangleState rs=dc.AppendRectangleState("foo");
		CPPUNIT_ASSERT_EQUAL( (WString)"foo",rs.GetName() );
		rs=dc.GetRectangleState("bar");
		CPPUNIT_ASSERT( rs.isNull() );
		rs=dc.GetCreateRectangleState("bar");
		CPPUNIT_ASSERT( !rs.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",rs.GetName() );
		rs=dc.GetRectangleState("bar");
		CPPUNIT_ASSERT( !rs.isNull() );
		CPPUNIT_ASSERT_EQUAL( (WString)"bar",rs.GetName() );
	} 
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}
