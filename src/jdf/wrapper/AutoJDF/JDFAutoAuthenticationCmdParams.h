/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoAuthenticationCmdParams_H_
#define _JDFAutoAuthenticationCmdParams_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFElement.h"
namespace JDF{
class JDFPart;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoAuthenticationCmdParams : public JDFElement

*********************************************************************
*/
/**
* automatically generated header for JDFAutoAuthenticationCmdParams class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFAuthenticationCmdParams should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoAuthenticationCmdParams : public JDFElement{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoAuthenticationCmdParams():JDFElement(){};
/**
* copy ctor
*/
	inline JDFAutoAuthenticationCmdParams(const KElement & other):JDFElement(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoAuthenticationCmdParams &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoAuthenticationCmdParams(){};
public:

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid attribute names
*/
	virtual vWString GetInvalidAttributes(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999)const;

/**
* typesafe validator utility
* @param EnumValidationLevel level validation level
* @param bool bIgnorePrivate ignore objects in foreign namespaces
* @param int nMax size of the returned vector
* @return vWString vector of invalid element names
*/
	virtual vWString GetInvalidElements(EnumValidationLevel level=ValidationLevel_Complete, bool bIgnorePrivate=true, int nMax=9999999) const;

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
* Enumeration for attribute AuthenticationType
*/

	enum EnumAuthenticationType{AuthenticationType_Unknown,AuthenticationType_AsClient,AuthenticationType_AsServer};
/**
* Enumeration for attribute Reason
*/

	enum EnumReason{Reason_Unknown,Reason_InitiateConnection,Reason_ClientCertificateExpired,Reason_ServerCertificateExpired,Reason_ClientHostnameMismatch,Reason_ServerHostnameMismatch,Reason_ClientCertificateRevoked,Reason_ServerCertificateRevoked,Reason_Other};

/**
 * definition of optional attributes in the JDF namespace
*/
	virtual WString OptionalAttributes()const;

/**
* Enumeration strings for AuthenticationType
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& AuthenticationTypeString();
/**
* Enumeration string for enum value
* @param EnumAuthenticationType value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString AuthenticationTypeString(EnumAuthenticationType value);
/**
* Set attribute AuthenticationType
* @param EnumAuthenticationType value the value to set the attribute to
*/
	virtual void SetAuthenticationType( EnumAuthenticationType value);

/**
* Typesafe enumerated attribute AuthenticationType
* @return EnumAuthenticationTypethe enumeration value of the attribute
*/
	virtual EnumAuthenticationType GetAuthenticationType() const;

/**
* Typesafe attribute validation of AuthenticationType
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidAuthenticationType(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Enumeration strings for Reason
* @return const WString& comma separated list of enumerated string values 
*/
	static const WString& ReasonString();
/**
* Enumeration string for enum value
* @param EnumReason value the enumeration to translate
* @return WString the string representation of the enumeration
*/
	static WString ReasonString(EnumReason value);
/**
* Set attribute Reason
* @param EnumReason value the value to set the attribute to
*/
	virtual void SetReason( EnumReason value);

/**
* Typesafe enumerated attribute Reason
* @return EnumReasonthe enumeration value of the attribute
*/
	virtual EnumReason GetReason() const;

/**
* Typesafe attribute validation of Reason
* @param EnumValidationLevel level element validation level 
* @return bool true if valid
*/
	virtual bool ValidReason(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ReasonDetails
*@param WString value: the value to set the attribute to
*/
	virtual void SetReasonDetails(const WString& value);
/**
* Get string attribute ReasonDetails
* @return WString the vaue of the attribute 
*/
	virtual WString GetReasonDetails() const;
/**
* Typesafe attribute validation of ReasonDetails
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidReasonDetails(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute URL
*@param WString value: the value to set the attribute to
*/
	virtual void SetURL(const WString& value);
/**
* Get string attribute URL
* @return WString the vaue of the attribute 
*/
	virtual WString GetURL() const;
/**
* Typesafe attribute validation of URL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidURL(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Part
* 
* @param int iSkip number of elements to skip
* @return JDFPart The element
*/
	JDFPart GetCreatePart(int iSkip=0);

/**
* const get element Part
* @param int iSkip number of elements to skip
* @return JDFPart The element
*/
	JDFPart GetPart(int iSkip=0)const;
/**
* Append element Part
 */
	JDFPart AppendPart();
//@{
		/**
		* get part map vector
		* @return vector of mAttribute, one for each part
		*/
		vmAttribute GetPartMapVector()const;
		
		        /**
		* set all parts to those define in vParts
		* @param vmAttribute& vParts vector of attribute maps for the parts
		*/
		void SetPartMapVector(const vmAttribute & vParts);
		/**
		* set part to mPart
		* @param mAttribute& mPart attribute map for the part to set
		*/
	void SetPartMap(const mAttribute & mPart);
		/**
		* remove the part defined in mPart
		* @param mAttribute& mPart attribute map for the part to remove
		*/
		void RemovePartMap(const mAttribute & mPart);
		/**
		* check whether the part defined in mPart is included
		* @param mAttribute& mPart attribute map for the part to remove
		* @return bool if the part exists
		*/
		bool HasPartMap(const mAttribute & mPart);
		//@}

/** Get Element Certificate
* 
* @param int iSkip number of elements to skip
* @return JDFElement The element
*/
	JDFElement GetCreateCertificate(int iSkip=0);

/**
* const get element Certificate
* @param int iSkip number of elements to skip
* @return JDFElement The element
*/
	JDFElement GetCertificate(int iSkip=0)const;
/**
* Append element Certificate
 */
	JDFElement AppendCertificate();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoAuthenticationCmdParams

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoAuthenticationCmdParams_H_