/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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

 
#if !defined _JDFAutoJMF_H_
#define _JDFAutoJMF_H_
#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/wrapper/JDFPool.h"
namespace JDF{
class JDFEmployee;
class JDFCommand;
class JDFAcknowledge;
class JDFResponse;
class JDFSignal;
class JDFQuery;
class JDFRegistration;
class JDFRefElement;
/*
*********************************************************************
class JDFAutoJMF : public JDFPool

*********************************************************************
*/
/**
* automatically generated header for JDFAutoJMF class
* 
* Warning! Do not edit! This file may be regenerated
* The child Class: @see JDFJMF should be edited instead
*/
class JDF_WRAPPERCORE_EXPORT JDFAutoJMF : public JDFPool{
public:


// Constructors / Destructors  


protected:
/**
* null ctor
*/
	inline JDFAutoJMF():JDFPool(){};
/**
* copy ctor
*/
	inline JDFAutoJMF(const KElement & other):JDFPool(){
	*this=other;
};
/**
* copy equivalance operator
*/
	JDFAutoJMF &operator =(const KElement& other);
/**
* dtor
*/
	virtual ~JDFAutoJMF(){};
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

/* ******************************************************
// Attribute Getter / Setter
****************************************************** */


/**
 * definition of required attributes in the JDF namespace
*/
	virtual WString RequiredAttributes()const;

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
* Set attribute DeviceID
*@param WString value: the value to set the attribute to
*/
	virtual void SetDeviceID(const WString& value);
/**
* Get string attribute DeviceID
* @return WString the vaue of the attribute 
*/
	virtual WString GetDeviceID() const;
/**
* Typesafe attribute validation of DeviceID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidDeviceID(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ICSVersions
*@param vWString value: the value to set the attribute to
*/
	virtual void SetICSVersions(const vWString& value);
/**
* Get string attribute ICSVersions
* @return vWString the vaue of the attribute 
*/
	virtual vWString GetICSVersions() const;
/**
* Typesafe attribute validation of ICSVersions
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidICSVersions(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute MaxVersion
*@param WString value: the value to set the attribute to
*/
	virtual void SetMaxVersion(const WString& value);
/**
* Get string attribute MaxVersion
* @return WString the vaue of the attribute 
*/
	virtual WString GetMaxVersion() const;
/**
* Typesafe attribute validation of MaxVersion
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidMaxVersion(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute ResponseURL
*@param WString value: the value to set the attribute to
*/
	virtual void SetResponseURL(const WString& value);
/**
* Get string attribute ResponseURL
* @return WString the vaue of the attribute 
*/
	virtual WString GetResponseURL() const;
/**
* Typesafe attribute validation of ResponseURL
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidResponseURL(EnumValidationLevel level=ValidationLevel_Complete) const;
/**
* Set attribute SenderID
*@param WString value: the value to set the attribute to
*/
	virtual void SetSenderID(const WString& value);
/**
* Get string attribute SenderID
* @return WString the vaue of the attribute 
*/
	virtual WString GetSenderID() const;
/**
* Typesafe attribute validation of SenderID
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidSenderID(EnumValidationLevel level=ValidationLevel_Complete) const;
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
/**
* Set attribute Version
*@param WString value: the value to set the attribute to
*/
	virtual void SetVersion(const WString& value);
/**
* Get string attribute Version
* @return WString the vaue of the attribute 
*/
	virtual WString GetVersion() const;
/**
* Typesafe attribute validation of Version
* @param EnumValidationLevel level of attribute validation 
* @return bool true if valid
*/
	virtual bool ValidVersion(EnumValidationLevel level=ValidationLevel_Complete) const;

/* ******************************************************
// Element Getter / Setter
**************************************************************** */


/** Get Element Employee
* 
* @param int iSkip number of elements to skip
* @return JDFEmployee The element
*/
	JDFEmployee GetCreateEmployee(int iSkip=0);

/**
* const get element Employee
* @param int iSkip number of elements to skip
* @return JDFEmployee The element
*/
	JDFEmployee GetEmployee(int iSkip=0)const;
/**
* Append element Employee
 */
	JDFEmployee AppendEmployee();

/** Get Element Command
* 
* @param int iSkip number of elements to skip
* @return JDFCommand The element
*/
	JDFCommand GetCreateCommand(int iSkip=0);

/**
* const get element Command
* @param int iSkip number of elements to skip
* @return JDFCommand The element
*/
	JDFCommand GetCommand(int iSkip=0)const;
/**
* Append element Command
 */
	JDFCommand AppendCommand();

/** Get Element Acknowledge
* 
* @param int iSkip number of elements to skip
* @return JDFAcknowledge The element
*/
	JDFAcknowledge GetCreateAcknowledge(int iSkip=0);

/**
* const get element Acknowledge
* @param int iSkip number of elements to skip
* @return JDFAcknowledge The element
*/
	JDFAcknowledge GetAcknowledge(int iSkip=0)const;
/**
* Append element Acknowledge
 */
	JDFAcknowledge AppendAcknowledge();

/** Get Element Response
* 
* @param int iSkip number of elements to skip
* @return JDFResponse The element
*/
	JDFResponse GetCreateResponse(int iSkip=0);

/**
* const get element Response
* @param int iSkip number of elements to skip
* @return JDFResponse The element
*/
	JDFResponse GetResponse(int iSkip=0)const;
/**
* Append element Response
 */
	JDFResponse AppendResponse();

/** Get Element Signal
* 
* @param int iSkip number of elements to skip
* @return JDFSignal The element
*/
	JDFSignal GetCreateSignal(int iSkip=0);

/**
* const get element Signal
* @param int iSkip number of elements to skip
* @return JDFSignal The element
*/
	JDFSignal GetSignal(int iSkip=0)const;
/**
* Append element Signal
 */
	JDFSignal AppendSignal();

/** Get Element Query
* 
* @param int iSkip number of elements to skip
* @return JDFQuery The element
*/
	JDFQuery GetCreateQuery(int iSkip=0);

/**
* const get element Query
* @param int iSkip number of elements to skip
* @return JDFQuery The element
*/
	JDFQuery GetQuery(int iSkip=0)const;
/**
* Append element Query
 */
	JDFQuery AppendQuery();

/** Get Element Registration
* 
* @param int iSkip number of elements to skip
* @return JDFRegistration The element
*/
	JDFRegistration GetCreateRegistration(int iSkip=0);

/**
* const get element Registration
* @param int iSkip number of elements to skip
* @return JDFRegistration The element
*/
	JDFRegistration GetRegistration(int iSkip=0)const;
/**
* Append element Registration
 */
	JDFRegistration AppendRegistration();

/**
 definition of optional elements in the JDF namespace
*/
	virtual WString OptionalElements()const;
}; // endJDFAutoJMF

// ******************************************************
}; // end namespace JDF
#endif //_JDFAutoJMF_H_
