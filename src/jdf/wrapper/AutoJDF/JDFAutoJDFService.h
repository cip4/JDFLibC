/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoJDFService_H_
#define _JDFAutoJDFService_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoJDFService : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoJDFService class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFJDFService should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoJDFService : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoJDFService():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoJDFService(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoJDFService &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoJDFService(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

protected:
/**
* typesafe validator utility - list of valid node names for this class 
 * @return WString& comma separated list of valid node names
 */

	virtual WString ValidNodeNames()const;
public:

/**
* Checks if the node is abstract, i.e. is not completely described
* utility used by GetUnknownElements, GetUnknownAttributes
* @return boolean: true, if the node is abstract
*/
	virtual bool IsAbstract()const;


/* ******************************************************
// Attribute Getter / Setter
****************************************************** */

/**
* Enumeration for attribute CombinedMethod
*/

	enum EnumCombinedMethod{CombinedMethod_Unknown,CombinedMethod_Combined,CombinedMethod_CombinedProcessGroup,CombinedMethod_GrayBox,CombinedMethod_ProcessGroup,CombinedMethod_None};
/**
* Enumeration for attribute TypeOrder
*/

	enum EnumTypeOrder{TypeOrder_Unknown,TypeOrder_Fixed,TypeOrder_Unordered,TypeOrder_Unrestricted};

/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for CombinedMethod
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& CombinedMethodString();
/**
* Enumeration string for enum value
* @param EnumCombinedMethod value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString CombinedMethodString(EnumCombinedMethod value);
/**
* Set attribute CombinedMethod
* @param EnumCombinedMethod value the value to set the attribute to
*/
	virtual void SetCombinedMethod( EnumCombinedMethod value);

/**
* Typesafe enumerated attribute CombinedMethod
* @return EnumCombinedMethodthe enumeration value of the attribute
*/
	virtual EnumCombinedMethod GetCombinedMethod() const;

/**
* Typesafe attribute validation of CombinedMethod
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidCombinedMethod(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Type
*@param WString value: the value to set the attribute to
*/
	virtual void SetType(const WString& value);
/**
* Get string attribute Type
* @return WString the vaue of the attribute 
*/
	virtual WString GetType() const;
/**
* Typesafe attribute validation of Type
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for TypeOrder
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& TypeOrderString();
/**
* Enumeration string for enum value
* @param EnumTypeOrder value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString TypeOrderString(EnumTypeOrder value);
/**
* Set attribute TypeOrder
* @param EnumTypeOrder value the value to set the attribute to
*/
	virtual void SetTypeOrder( EnumTypeOrder value);

/**
* Typesafe enumerated attribute TypeOrder
* @return EnumTypeOrderthe enumeration value of the attribute
*/
	virtual EnumTypeOrder GetTypeOrder() const;

/**
* Typesafe attribute validation of TypeOrder
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidTypeOrder(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Types
*@param vWString value: the value to set the attribute to
*/
	virtual void SetTypes(const vWString& value);
/**
* Get string attribute Types
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetTypes() const;
/**
* Typesafe attribute validation of Types
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTypes(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoJDFService

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoJDFService_H_
