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
// Author Niels Boeger
//
// Revision history:
// created 31 Jul 2006
//
// JDFEvaluationTestCase.cpp
//
//////////////////////////////////////////////////////////////////////

#include <jdf/util/PlatformUtils.h>
#include "jdf/wrapper/JDF.h"
#include "jdf/wrapper/JDFDoc.h"
#include "JDFStateBaseTestCase.h"
#include <iostream>

using namespace std;
using namespace JDF;

CPPUNIT_TEST_SUITE_REGISTRATION (JDFStateBaseTestCase);


 
void JDFStateBaseTestCase::setUp()
{
	try	
	{
		JDF::PlatformUtils::Initialize();
	}
	catch (const JDF::Exception& e)	
	{
		e.getMessage();
	}

	dd=JDFDoc(1);
	JDFJMF jmf=((JDFDoc)dd).GetJMFRoot();
	JDFResponse resp=(JDFResponse)jmf.appendMessageElement(JDFMessage::Family_Response, 
		JDFMessage::Type_KnownDevices);
	deviceCap=(JDFDeviceCap)resp.AppendDeviceList().AppendDeviceInfo().AppendDevice().AppendDeviceCap();
}


void JDFStateBaseTestCase::testGetNamePath()
{
	try
	{
		JDFParser p;
		WString strNode =
		                  "<DevCaps Name=\"RenderingParams\" LinkUsage=\"Input\">";
		strNode.append(   "<DevCap>");
		strNode.append(      "<DevCap Name=\"AutomatedOverPrintParams\">");
		   strNode.append(         "<BooleanState Name=\"OverPrintBlackText\" DefaultValue=\"true\" AllowedValueList=\"true false\"/>");
		strNode.append(         "<BooleanState Name=\"OverPrintBlackLineArt\" DefaultValue=\"true\" AllowedValueList=\"true false\"/>");
		strNode.append(      "</DevCap>");
		strNode.append(   "</DevCap>");
		strNode.append("</DevCaps>");

		p.StringParse(strNode, false);
		JDFDoc jdfDoc = p.GetDocument();
		JDFDevCaps devCaps=(JDFDevCaps)jdfDoc.GetRoot();
		JDFBooleanState state=(JDFBooleanState)devCaps.GetChildByTagName(JDFStrings::elm_BooleanState, WString::emptyStr, 0, 
			mAttribute::emptyMap, false, true);
		CPPUNIT_ASSERT_EQUAL( WString("RenderingParams/AutomatedOverPrintParams/@OverPrintBlackText"), WString(state.GetNamePath(true)) );
	}
	catch (const JDFException& e)
	{
		CPPUNIT_FAIL( e.what() );
	}
}


void JDFStateBaseTestCase::testFitsValue_IntegerState()
{
	JDFParser p;
	WString strNode = 
            "<IntegerState Name=\"BitDepth\" DefaultValue=\"1\" AllowedValueList=\"1 8 12\"/>";
	p.StringParse(strNode, false);
	JDFDoc jdfDoc = p.GetDocument();
	JDFIntegerState state=(JDFIntegerState)jdfDoc.GetRoot();
	
	JDFIntegerRangeList list;
	list.Append(JDFIntegerRange(1,12));
	state.SetListType(JDFStateBase::ListType_RangeList);
	CPPUNIT_ASSERT_MESSAGE( "ListType=RangeList", !state.FitsValue(list.GetString(), 
		JDFElement::FitsValue_Allowed) );

	JDFIntegerRangeList list2;
	list2.Append(JDFIntegerRange(1,-2));

	IntegerRangeList allowedVL;
	allowedVL.Append(JDFIntegerRange(1,32));
	state.SetAllowedValueList(allowedVL);
	CPPUNIT_ASSERT_MESSAGE("xDef is wrong", state.FitsValue(list2.GetString(), 
		JDFElement::FitsValue_Allowed));

	list.erase(list.size() - 1);	// erase "1~12"
	list.Append(2);
	list.Append(12);
	list.Append(22);
	state.SetListType(JDFStateBase::ListType_List);
	state.SetAllowedValueMod(JDFXYPair(10,2));
	CPPUNIT_ASSERT_MESSAGE( "ListType=List", state.FitsValue(list.GetString(),
		JDFElement::FitsValue_Allowed) );
}



void JDFStateBaseTestCase::testFitsValue_MatrixState()
{
	JDFDoc jdfDoc(0);
	JDFNode root=jdfDoc.GetRoot();

	if ( !root.isNull() )
	{
		try
		{
			JDFMatrix matrix1("1 0 0 1 3.14 21631.3");
			JDFMatrix matrix2("0 1 1 0 2 21000");

			vint transforms;
			transforms.add(JDFElement::Orientation_Rotate0);
			transforms.add(JDFElement::Orientation_Rotate270);
			transforms.add(JDFElement::Orientation_Flip0);
			JDFRectangle shift("2 4 20000 23000");
			
			WString value1 = "1 0 0 1 3.14 21631.3";

			JDFMatrixState k=(JDFMatrixState)root.AppendElement("MatrixState");
			k.AppendValue();
			k.SetValueAllowedValue(0, matrix2);
			k.AppendValue();
			k.SetValueAllowedValue(1, matrix1);

			cout << endl << "-> Name of state is " << k.GetNodeName() << endl;

			k.SetAllowedTransforms(transforms);
			k.SetAllowedShift(shift);
			k.SetAllowedRotateMod(15);

			k.SetListType(JDFStateBase::ListType_UniqueList);

			CPPUNIT_ASSERT_MESSAGE( "-> Matrix ok", k.FitsValue(value1) );

			WString value="1 2 3 4 5 6 7 8 9 10 11 12 3 4 5 6 7 8";
			vWString vs(value, WString::blank);
			int siz=vs.size();
			if (siz%6 != 0)
				cout << endl << "-> vs is not a matrix" << endl;
			vWString matrixList;
			int i=0;
			WString sb;
			sb.append((WString) vs.elementAt(i));

			while (i+1 < siz)
			{
				do 
				{
					sb.append(WString::blank);
					i++;
					sb.append((WString) vs.elementAt(i));
				}
				while ( (i+1)%6 != 0 );
				matrixList.add(sb);
				if ((i+1)<siz)
                { 
                    i++;
                    sb.erase();
                    sb.append((WString) vs.elementAt(i));
                }
			}
			cout << "-> " << matrixList.GetString() << endl;

			for (int z=0; z<matrixList.size(); z++)
            {
				cout << "-> " << matrixList.elementAt(z) << endl;
            }
			cout << "-> test successfull";
		}
		catch (JDF::Exception e)
		{
			cout  << endl << e.getMessage();
			CPPUNIT_FAIL("error in testFitsValue_MatrixState()");
		}
	}
	else
    {
		CPPUNIT_FAIL ("JDFNode == null, can't start test");
    }
}

/**
* tests defaults and handling of "unbounded"
*/
void JDFStateBaseTestCase::testMaxOccurs()
{
	try
	{
		JDFDevCap dc=(JDFDevCap)deviceCap.AppendDevCaps().AppendDevCap();
		JDFIntegerState is=dc.AppendIntegerState();
		CPPUNIT_ASSERT_EQUAL( 1, is.GetMaxOccurs() );
		is.SetMaxOccurs(WString::pINF);
		CPPUNIT_ASSERT_EQUAL( (int)is.GetAttribute(JDFElement::atr_MaxOccurs),(int)WString::pINF );
		CPPUNIT_ASSERT(	is.GetMaxOccurs()>999 );
		is.SetAttribute(JDFElement::atr_MaxOccurs, "unbounded");
        CPPUNIT_ASSERT(	is.GetMaxOccurs()>999 );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void JDFStateBaseTestCase::testMinOccurs()
{
	try
	{
		JDFDevCap dc=deviceCap.AppendDevCaps().AppendDevCap();
		JDFIntegerState is=dc.AppendIntegerState();
		CPPUNIT_ASSERT_EQUAL( 1,is.GetMinOccurs() );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL(e.what());
	}
}

void JDFStateBaseTestCase::testFixVersion()
{
	try
	{
		JDFDevCap dc=deviceCap.AppendDevCaps().AppendDevCap();
		JDFIntegerState is=dc.AppendIntegerState();
		CPPUNIT_ASSERT( is.GetAttribute(JDFElement::atr_MaxOccurs).empty() );
		is.FixVersion(JDFElement::Version_Unknown);
		CPPUNIT_ASSERT( is.GetAttribute(JDFElement::atr_MaxOccurs).empty() );
		is.SetAttribute(JDFElement::atr_MaxOccurs, "unbounded");
		is.FixVersion(JDFElement::Version_Unknown);
		CPPUNIT_ASSERT_EQUAL( (WString)WString::pINFstr,is.GetAttribute(JDFElement::atr_MaxOccurs) );
		is.SetAttribute(JDFElement::atr_MaxOccurs, "3");
		is.FixVersion(JDFElement::Version_Unknown);
		CPPUNIT_ASSERT_EQUAL( 3,(int)is.GetAttribute(JDFElement::atr_MaxOccurs) );
	}
	catch (JDFException& e)
	{
		CPPUNIT_FAIL(e.what());
	}
}
