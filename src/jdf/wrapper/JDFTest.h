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

 
#if !defined _JDFTest_H_
#define _JDFTest_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/AutoJDF/JDFAutoTest.h"
namespace JDF{
/*
*********************************************************************
class JDFTest : public JDFAutoTest

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFTest 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFTest : public JDFAutoTest{
public:


// Constructors / Destructors  


/**
* null ctor
*/
	inline JDFTest():JDFAutoTest(){};
/**
* copy ctor
*/
	inline JDFTest(const KElement & other):JDFAutoTest(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFTest &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFTest(){};

	/**
	* Evaluates the boolean expression (child Term element) if it fits the attribute map 'm'
	*
	* @param mAttribute& m: key-value pair attribute map
	* @return: true, if the boolean expression (child Term element) evaluates to “true”
	*/
	bool FitsMap(const mAttribute& m);

	/**
	* Evaluates the boolean expression (child Term element) if it fits the JDFNode 'jdf'
	*
	* @param JDFNode& jdf: JDFNode we test to know if the Device can accept it 
	* @return: true, if boolean expression (child Term element) evaluates to “true”
	*/
	bool FitsJDF(const JDFNode& jdf);

	/**
	* Gets of JDFNode a list of attributes tested by this Test
	* Attribute info has a format " XPath=[..], Value=[..] " 
	*
	* @param JDFNode jdf: jdf node to test
	* @return vWString: the list of the attributes, tested by this Test
	*/
	vWString GetTestedAttributesInfo(const JDFNode& jdf);


}; // endJDFTest

// ******************************************************
}; // end namespace JDF
#endif //_JDFTest_H_
