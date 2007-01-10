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

 
#if !defined _JDFEvaluation_H_
#define _JDFEvaluation_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
#include "jdf/wrapper/JDFBasicPreflightTest.h"

namespace JDF{

class JDFRefElement;
/*
*********************************************************************
class JDFEvaluation : public JDFElement

*********************************************************************
*/

class JDF_WRAPPERCORE_EXPORT JDFEvaluation : public JDFElement{
public:


/** *****************************
* Construction / Destruction
******************************************** */
protected:	
//@{
/**
* Empty constructor
	*/
	inline JDFEvaluation():JDFElement(){};

	/**
	* Copy constructor
	*/
	inline JDFEvaluation(const KElement & other):JDFElement(){
		*this=other;
	};
	/**
	* Equivalence copy constructor
	*/
	JDFEvaluation &operator =(const KElement& other);
	/**
	* Destructor
	*/
	virtual ~JDFEvaluation(){};
	//@}


public:

	/**
	* Checks if the node is abstract, i.e. is not completely described
	* utility used by GetUnknownElements, GetUnknownAttributes
	* @return bool: true, if the node is abstract
	*/
	virtual bool IsAbstract()const;

	/**
	* definition of optional attributes in the JDF namespace
	*
	* @return WString: list of optional attributes
	*/
	virtual WString OptionalAttributes()const;

	/**
	* typesafe validator
	*
	* @param EnumValidationLevel level: validation level
	* @param bool bIgnorePrivate: if true, do not worry about attributes in other namespaces
	* @param int nMax: maximum size of the returned vector
	* @return vWString: a vector of invalid attribute names
	*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

	/**
	* definition of optional elements in the JDF namespace
	*
	* @return WString: list of optional elements
	*/
	virtual WString OptionalElements()const;
	
	/**
	* typesafe validator
	*
	* @param EnumValidationLevel level: validation level
	* @param bool bIgnorePrivate: if true, do not worry about elements in other namespaces
	* @param int nMax: maximum size of the returned vector
	* @return vWString: a vector of invalid element names
	*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

	/**
	* Dependent on context of Evaluation, gets ListType attribute from a corresponding State
	* or BasicPreflightTest element
	*
	* @return JDFBasicPreflightTest::EnumListType - the value of ListType attribute
	*/
	virtual JDFBasicPreflightTest::EnumListType GetListType() const;

	/**
	* Tests, if attribute map 'm' has a key, specified by BasicPreflightTest/@Name and if 'm' has such key
	* checks, if its value fits testlists, specified for matching Evaluation (uses FitsValue(value))
	*
	* @param mAttribute& m: key-value pair attribute map to take value from
	* @return bool: true, if 'm' has a key, specified by BasicPreflightTest/@Name and FitsValue(value) returns true
	*/
	virtual bool FitsMap(const mAttribute & m) const;
	
	/**
	* Tests, if JDFNode jdf can be accepted by the Device
	* tests if the value of resource attribute, decribed with this Evaluation fits Evaluation/@ValueList
	*
	* @param JDFNode jdf: jdf node to test
	* @return bool: true, if 'jdf' can be accepted by the Device
	*/
	virtual bool FitsJDF(const JDFNode& jdf) const;
	
	/**
	* Gets of JDFNode that we test the vector of XPathes to the attributes, described by this Evaluation
	*
	* @param JDFNode jdf: jdf node to test
	* @return vWString: the vector of XPathes to the attributes, described by this Evaluation
	*/
	virtual vWString GetAttributeXPathVector(const JDFNode& jdf) const;

	/**
	* Gets of JDFNode a list of attributes tested by this Evaluation
	* in a format " XPath=[..], Value=[..] "
	*
	* @param JDFNode jdf: jdf node to test
	* @return vWString: the vector of XPathes to the attributes, described by this Evaluation
	*/
	virtual vWString GetTestedAttributesInfo(const JDFNode& jdf) const;

	/**
	* Tests, if the defined value matches testlists, specified for this Evaluation
	*
	* @param const WString& value: value to test
	* @return bool: true, if the value matches testlists or if testlists are not specified
	*/
	virtual bool FitsValue(const WString& value) const=0;


	/* ******************************************************
	// Attribute Getter / Setter
	****************************************************** */

	/**
	* Sets attribute rRef
	*
	* @param WString& value: the value to set the attribute to
	*/
	virtual void SetrRef(const WString& value);

	/**
	* Gets string attribute rRef
	*
	* @return WString: the value of the attribute 
	*/
	virtual WString GetrRef() const;

	/**
	* Typesafe validation of attribute rRef
	*
	* @param EnumValidationLevel level: level of attribute validation 
	* @return bool: true if valid
	*/
	virtual bool ValidrRef(EnumValidationLevel level=ValidationLevel_Complete) const;


	/* ******************************************************
	// Element Getter / Setter
	**************************************************************** */

	//@{
	/** 
	* Gets of 'this' child BasicPreflightTest element, 
	* optionally creates it, if it doesn't exist.
	* 
	* @return JDFBasicPreflightTest: the matching BasicPreflightTest element
	*/
	virtual JDFBasicPreflightTest GetCreateBasicPreflightTest();
	
	/**
	* Gets of 'this' an existing child BasicPreflightTest element  
	*
	* @return JDFBasicPreflightTest: the matching BasicPreflightTest element
	*/
	virtual JDFBasicPreflightTest GetBasicPreflightTest()const;
	
	/**
	* Appends new BasicPreflightTest element to the end of 'this'  
	*
	* @return JDFBasicPreflightTest: newly created child BasicPreflightTest element
	*/
	virtual JDFBasicPreflightTest AppendBasicPreflightTest();
	//@}
		

}; // endJDFEvaluation

// ******************************************************
}; // end namespace JDF
#endif //_JDFEvaluation_H_
