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

 
#if !defined _JDFxor_H_
#define _JDFxor_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/AutoJDF/JDFAutoxor.h"
namespace JDF{
/*
*********************************************************************
class JDFxor : public JDFAutoxor

*********************************************************************
*/
/**
* Typesafe resource wrapper class JDFxor 
*
* This file is hand edited and will not be regenerated
*/
class JDF_WRAPPERCORE_EXPORT JDFxor : public JDFAutoxor{
public:


// Constructors / Destructors  


/**
* null ctor
*/
	inline JDFxor():JDFAutoxor(){};
/**
* copy ctor
*/
	inline JDFxor(const KElement & other):JDFAutoxor(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFxor &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFxor(){};

	/**
	* Evaluates two or more Term elements (and, or, xor, not, Evaluation, TestRef) to determine if, as a set, 
	* they evaluate to “true” when combined in a boolean “xor” function. 
	* For more than two arguments, exactly one Term must evaluate to “true” for the “xor” to evaluate to “true”.
	*
	* Looks for Evaluations, that “xor” consists of, and tests the status of every Evaluation  
	* till the result of a whole boolean expression will be determinated -  tests if attribute map 'm' has a key,
	* specified by Evaluation/BasicPreflightTest/@Name and if 'm' has such key, checks
	* if its value fits testlists, specified for matching Evaluation (uses FitsValue(value))
	*
	* @param mAttribute& m: key-value pair attribute map
	* @return: true, if boolean “xor” expression evaluates to “true”
	*/
	bool FitsMap(const mAttribute& m);
	
	/**
	* Evaluates two or more Term elements (and, or, xor, not, Evaluation, TestRef) to determine if, as a set, 
	* they evaluate to “true” when combined in a boolean “xor” function.
	*
	* @param JDFNode& jdf: JDFNode we test to know if the Device can accept it 
	* @return: true, if boolean “xor” expression evaluates to “true”
	*/
	bool FitsJDF(const JDFNode& jdf);

	/**
	* Gets of JDFNode a list of attributes tested by this xor
	* Attribute info has a format " XPath=[..], Value=[..] " 
	*
	* @param JDFNode jdf: jdf node to test
	* @return vWString: the list of the attributes, tested by this xor
	*/
	vWString GetTestedAttributesInfo(const JDFNode& jdf);


}; // endJDFxor

// ******************************************************
}; // end namespace JDF
#endif //_JDFxor_H_
