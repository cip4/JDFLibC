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


///////////////////////////////////////////////////////////////////

 
#include "jdf/wrapper/JDFor.h"
#include "jdf/wrapper/JDFand.h"
#include "jdf/wrapper/JDFxor.h"
#include "jdf/wrapper/JDFnot.h"
#include "jdf/wrapper/JDFTest.h"
#include "jdf/wrapper/JDFTestRef.h"
#include "jdf/wrapper/JDFTestPool.h"
#include "jdf/wrapper/JDFFactory.h"
#include "jdf/wrapper/JDFEvaluation.h"

namespace JDF{
/**
* copy equivalance operator
*/
	JDFxor& JDFxor::operator=(const KElement& other){
		KElement::operator=(other);
		if(!IsValid(ValidationLevel_Construct))
		throw JDFException(L"Invalid constructor for JDFxor: "+other.GetNodeName());
		return *this;
	};

	/////////////////////////////////////////////////////////////////////////

	bool JDFxor::FitsMap(const mAttribute& m) {
		
		vElement v = GetChildElementVector();
		int siz = v.size();
		int count=0;
		for (int i=0; i<siz; i++)
		{
			JDFElement e=v[i];
			if (e.IsComment())
				continue;

			WString nodeName=e.GetLocalName();

			if (nodeName==elm_or)
			{
				JDFor OR = e;
				if (OR.FitsMap(m))
					count++;
			}	
			else if (nodeName==elm_and)
			{
				JDFand AND = e; 
				if (AND.FitsMap(m))
					count++;
			}	
			else if(nodeName==elm_xor) 
			{
				JDFxor XOR = e; 
				if (XOR.FitsMap(m))
					count++;
			}			
			else if(nodeName==elm_not)
			{
				JDFnot NOT = e; 
				if (NOT.FitsMap(m))
					count++;
			}
			else if (nodeName.endsWith(L"Evaluation"))
			{
				JDFFactory f(e);
				JDFEvaluation& eval=(JDFEvaluation&)f.GetRef();
				if (eval.FitsMap(m))
					count++;
			}
			else if (nodeName==elm_TestRef) 
			{
				JDFTestRef testRef = e;
				JDFTestPool testPool = e.GetDeepParent(elm_TestPool);
				JDFTest testElm = testPool.GetChildWithAttribute(elm_Test,atr_ID,WString::emptyStr,testRef.GetrRef());
				if (testElm.isNull())
					throw JDFException(L"JDFxor::FitsMap testing null element"); 
				if (testElm.FitsMap(m))
					count++;
			}
		}
		return (count==1);
	}

	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	bool JDFxor::FitsJDF(const JDFNode& jdf) {
		
		vElement v = GetChildElementVector();
		int siz = v.size();
		int count=0;
		for (int i=0; i<siz; i++)
		{
			JDFElement e=v[i];
			if (e.IsComment())
				continue;

			WString nodeName=e.GetLocalName();

			if (nodeName==elm_or)
			{
				JDFor OR = e;
				if (OR.FitsJDF(jdf))
					count++;
			}	
			else if (nodeName==elm_and)
			{
				JDFand AND = e; 
				if (AND.FitsJDF(jdf))
					count++;
			}	
			else if(nodeName==elm_xor) 
			{
				JDFxor XOR = e; 
				if (XOR.FitsJDF(jdf))
					count++;
			}			
			else if(nodeName==elm_not)
			{
				JDFnot NOT = e; 
				if (NOT.FitsJDF(jdf))
					count++;
			}
			else if (nodeName.endsWith(L"Evaluation"))
			{
				JDFFactory f(e);
				JDFEvaluation& eval=(JDFEvaluation&)f.GetRef();
				if (eval.FitsJDF(jdf))
					count++;
			}
			else if (nodeName==elm_TestRef) 
			{
				JDFTestRef testRef = e;
				JDFTestPool testPool = e.GetDeepParent(elm_TestPool);
				JDFTest testElm = testPool.GetChildWithAttribute(elm_Test,atr_ID,WString::emptyStr,testRef.GetrRef());
				if (testElm.isNull())
					throw JDFException(L"JDFxor::FitsJDF testing null element"); 
				if (testElm.FitsJDF(jdf))
					count++;
			}
			if (count>1)
				break;
		}
		return (count==1);
	}


	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////

	vWString JDFxor::GetTestedAttributesInfo(const JDFNode& jdf) {
		
		vWString vAttr;
		vElement v = GetChildElementVector();
		int siz = v.size();
		for (int i=0; i<siz; i++)
		{
			JDFElement e=v[i];
			if (e.IsComment())
				continue;

			WString nodeName=e.GetLocalName();

			if (nodeName==elm_or)
			{
				JDFor OR = e;
				vAttr.AppendUnique(OR.GetTestedAttributesInfo(jdf));
				continue;
			}	
			else if (nodeName==elm_and)
			{
				JDFand AND = e; 
				vAttr.AppendUnique(AND.GetTestedAttributesInfo(jdf));
				continue;
			}	
			else if(nodeName==elm_xor) 
			{
				JDFxor XOR = e; 
				vAttr.AppendUnique(XOR.GetTestedAttributesInfo(jdf));
				continue;
			}			
			else if(nodeName==elm_not)
			{
				JDFnot NOT = e; 
				vAttr.AppendUnique(NOT.GetTestedAttributesInfo(jdf));
				continue;
			}
			else if (nodeName.endsWith(L"Evaluation"))
			{
				JDFFactory f(e);
				JDFEvaluation& eval=(JDFEvaluation&)f.GetRef();
				vAttr.AppendUnique(eval.GetTestedAttributesInfo(jdf));
				continue;
			}
			else if (nodeName==elm_TestRef) 
			{
				JDFTestRef testRef = e;
				JDFTestPool testPool = e.GetDeepParent(elm_TestPool);
				JDFTest testElm = testPool.GetChildWithAttribute(elm_Test,atr_ID,WString::emptyStr,testRef.GetrRef());
				if (testElm.isNull())
					throw JDFException(L"JDFxor::GetTestedAttributesInfo attemt to operate on a null element"); 
				vAttr.AppendUnique(testElm.GetTestedAttributesInfo(jdf));
				continue;
			}

		}
		return vAttr;
	}

	/////////////////////////////////////////////////////////////////////////

}; // namespace JDF
