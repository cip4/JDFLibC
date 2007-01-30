/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
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
/******************************************************************************
 *                     Copyright 1998 Agfa-Gevaert N.V.                       *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *        without the prior written consent of Agfa-Gevaert N.V.              *
 *                                                                            *
 ******************************************************************************/

/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_MIMEHEADER_H
#define I_JDF_MIMEHEADER_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/WString.h>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 


/******************************************************************************
 *	Defines and constants
 ******************************************************************************/ 


/******************************************************************************
 *	Typedefs
 ******************************************************************************/ 


/******************************************************************************
 *	Classes
 ******************************************************************************/ 

/** 
 * The Header class is used to represent the Header of the MIME message.
 * <p>
 * The standard message header fields are defined as static constant attributes 
 * of this class.
 * These keys can be used for adding/getting header key/value pairs in a MIMEMessage.
 * @nosubgrouping
 */
class JDFTOOLS_EXPORT MIMEHeader
{
public:

	/**
	 * Key for header field 'Bcc'.
	 */
	static const JDFCh BCC[];

	/**
	 * Key for header field 'To'.
	 */
	static const JDFCh TO[];

	/**
	 * Key for header field 'Date'.
	 */
	static const JDFCh DATE[];

	/**
	 * Key for header field 'From'.
	 */
	static const JDFCh FROM[];

	/**
	 * Key for header field 'Organization'.
	 */
	static const JDFCh ORGANIZATION[];

	/**
	 * Key for header field 'Priority'.
	 */
	static const JDFCh PRIORITY[];

	/**
	 * Key for header field 'Reply-To'.
	 */
	static const JDFCh REPLY_TO[];

	/**
	 * Key for header field 'Subject'.
	 */
	static const JDFCh SUBJECT[];

public:

/** 
 * @name Constructors
 */
/*@{*/

	MIMEHeader() {}
	/**
	 * Header constructor
	 * Creates a Header object given header name and value strings.
	 * @param name Name of the header
	 * @param value Value of the header
	 */
	MIMEHeader(const WString& name, const WString& value);

	/**
	 * Header constuctor
	 * Creates a Header object given a string in <name>:<value> format.
	 * Any '\r' and '\n' chars at the end of the line are stripped.
	 * All the chars in s must map to ASCII.
	 * @param inStr a sting with header in the form <name>:<value>
	 * @param MIMEException if s is not in the form <name>:<value>
	 */
	MIMEHeader(const WString& s);

	/**
	 * Header constructor
	 * Creates a Header object given a byte array with header in the form
	 * <name>:<value>
	 * Any '\r' and '\n' chars at the end of the line are stripped.
	 * All the chars in line must map to ASCII.
	 * @param line a byte array with header in the form <name>:<value>
	 * @exception MIMEException if line is not in <name>:<value> form.
	 */

	MIMEHeader(char* line, int len);

	MIMEHeader(const MIMEHeader& m);
	MIMEHeader& operator=(const MIMEHeader& m);

/*@}*/
	/**
	 * Returns the name of this header.
	 */
	WString getName() const;

	/**
	 * Returns the value of this header.
	 */
	WString getValue() const;

	/**
	 * Returns the complete header-line in the form <Name>:<Value> with CRLF termination
	 */
	WString getLine() const;

protected:

	/**
	 * Sets the name of this header.
	 * @param name Name of the header to set.
	 */

	void setName(const WString& name);

	/**
	 * Sets the value of this header.
	 * param value Value of the header to set.
	 */
	void setValue(const WString& value);

private:
	
	WString m_headerName;
	WString m_headerValue;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMEHEADER_H */

