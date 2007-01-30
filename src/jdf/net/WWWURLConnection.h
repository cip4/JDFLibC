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

#ifndef I_JDF_WWWURLCONNECTION_H
#define I_JDF_WWWURLCONNECTION_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include "URLConnection.h"

#include "MessageHeader.h"


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
 * Base class for common URL Connection
 * @nosubgrouping
 */
class JDFTOOLS_EXPORT WWWURLConnection : public URLConnection
{
public:

/** 
 * @name Constructors
 */
/*@{*/
	/**
	 * Create an URLConnection object. These should not be created directly:
	 * instead they should be created by protocol handlers in response to
	 * URL.openConnection
	 * @param u the URL that this connects to.
	 */

	WWWURLConnection(const URL& u);

/*@}*/

	/**
	 * Call this routine to get the property list for this object.
	 * Properties (like content-type) that have explicit getXX() methods
	 * associated with them should be accessed using those methods.
	 */
	
	virtual MessageHeader& getProperties() { return properties; }

	/**
	 * Call this routine to set the property list for this object.
	 */
	virtual void setProperties(const MessageHeader& properties) { this->properties = properties; }

	virtual void setRequestProperty(const WString& key, const WString& value);

	virtual MessageHeader::value_pair getHeaderField(const WString& name);

	/** 
	 * Return the key for the nth header field. 
	 * Return false if there are fewer than n fields. This can be
	 * used to iterate through all the headers in the message.
	 */
	virtual MessageHeader::value_pair getHeaderFieldKey(int n);

	/**
	 * Return the value for the nth header field. 
	 * Return false if there are fewer than n fields. This can be 
	 * used in conjunction with get getHeaderFieldKey to iterate through
	 * all the headers in the message.
	 */
	virtual MessageHeader::value_pair getHeaderField(int n);

	/**
	 * Call this routine to get the content-type associated with this 
	 * object.
	 */
	virtual WString getContentType();

	/** 
	 * Set the content type of this URL to a specific value.
	 * @param type The content type to use. One of the content_*
     *  static variables in this class should be used.
	 */
	virtual void setContentType(const WString& type);

	/** 
	 * Call this routine to get the content-length associated with 
	 * this object.
	 */

	virtual int getContentLength();

	/**
	 * Returns <code>true</code> if the data associated with this
	 * URL can be cached.
	 */
	virtual bool canCache();

	/**
	 * Call this to close the connection and flush any remaining
	 * data.
	 */
	virtual void close();


protected:

	/**
	 * Call this routine to set the content-length associated with 
	 * this object.
	 */
	virtual void setContentLength(int length);


	MessageHeader properties;

private:

	/**
	 * The URL that it is connected to 
	 */

	WString contentType;
	int contentLength;
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_WWWURLCONNECTION_H */
