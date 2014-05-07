/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2014 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoComment_H_
#define _JDFAutoComment_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
/*
*********************************************************************
class JDFAutoComment : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoComment class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFComment should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoComment : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoComment():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoComment(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoComment &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoComment(){};
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
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Set attribute AgentName
*@param WString value: the value to set the attribute to
*/
	virtual void SetAgentName(const WString& value);
/**
* Get string attribute AgentName
* @return WString the vaue of the attribute 
*/
	virtual WString GetAgentName() const;
/**
* Typesafe attribute validation of AgentName
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAgentName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute AgentVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetAgentVersion(const WString& value);
/**
* Get string attribute AgentVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetAgentVersion() const;
/**
* Typesafe attribute validation of AgentVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAgentVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Attribute
*@param WString value: the value to set the attribute to
*/
	virtual void SetAttributeAttribute(const WString& value);
/**
* Get string attribute Attribute
* @return WString the vaue of the attribute 
*/
	virtual WString GetAttributeAttribute() const;
/**
* Typesafe attribute validation of Attribute
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAttributeAttribute(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Author
*@param WString value: the value to set the attribute to
*/
	virtual void SetAuthor(const WString& value);
/**
* Get string attribute Author
* @return WString the vaue of the attribute 
*/
	virtual WString GetAuthor() const;
/**
* Typesafe attribute validation of Author
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidAuthor(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Box
*@param JDFRectangle value: the value to set the attribute to
*/
	virtual void SetBox(const JDFRectangle& value);
/**
* Get string attribute Box
* @return JDFRectangle the vaue of the attribute 
*/
	virtual JDFRectangle GetBox() const;
/**
* Typesafe attribute validation of Box
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidBox(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ID
*@param WString value: the value to set the attribute to
*/
	virtual void SetID(const WString& value);
/**
* Get string attribute ID
* @return WString the vaue of the attribute 
*/
	virtual WString GetID() const;
/**
* Typesafe attribute validation of ID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Language
*@param WString value: the value to set the attribute to
*/
	virtual void SetLanguage(const WString& value);
/**
* Get string attribute Language
* @return WString the vaue of the attribute 
*/
	virtual WString GetLanguage() const;
/**
* Typesafe attribute validation of Language
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidLanguage(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Name
*@param WString value: the value to set the attribute to
*/
	virtual void SetName(const WString& value);
/**
* Get string attribute Name
* @return WString the vaue of the attribute ; defaults to Description
*/
	virtual WString GetName() const;
/**
* Typesafe attribute validation of Name
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidName(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute Path
*@param WString value: the value to set the attribute to
*/
	virtual void SetPath(const WString& value);
/**
* Get string attribute Path
* @return WString the vaue of the attribute 
*/
	virtual WString GetPath() const;
/**
* Typesafe attribute validation of Path
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidPath(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute TimeStamp
*@param JDFDate value: the value to set the attribute to
*/
	virtual void SetTimeStamp(JDFDate value=JDFDate());
/**
* Get string attribute TimeStamp
* @return JDFDate the vaue of the attribute 
*/
	virtual JDFDate GetTimeStamp() const;
/**
* Typesafe attribute validation of TimeStamp
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidTimeStamp(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */

}; // endJDFAutoComment

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoComment_H_
