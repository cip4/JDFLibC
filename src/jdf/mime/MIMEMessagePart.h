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

#ifndef I_JDF_MIMEMESSAGEPART_H
#define I_JDF_MIMEMESSAGEPART_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "MIMEBodyPart.h"

#include "MIMEHeader.h"

#include <jdf/util/hmap.h>
#include <jdf/util/hashfun.h>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class MIMEMessage;
	class InputStream;
	class MIMEParser;

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
 * The MIMEMessagePart class implements the MIME MessagePart Content Type.
 * @ingroup mime
 * @nosubgrouping
 */
class JDFTOOLS_EXPORT MIMEMessagePart : public MIMEBodyPart
{
public:

	typedef std::pair<bool,WString> value_pair;

/** 
 * @name Constructors
 */
/*@{*/
	/**
	 * Constructs a MIMEMessagePart object
	 */
	MIMEMessagePart();

	/**
	 * Constructs a MIMEMessagePart object from the given MIMEMessage object.
	 * This constructor will make a clone of the given MIMEMessage object.
	 * @param msg The message that should form the body of this part
	 * @exception MIMEException If msg is NULL.
	 */
	MIMEMessagePart(MIMEMessage* msg);

	MIMEMessagePart(const MIMEMessagePart& part);

/*@}*/
	~MIMEMessagePart();

	/**
	 * Returns Content-Type of this MIME Part. Always returns the string "Message".
	 */
	value_pair getContentType();

	/**
	 * Sets Content-Transfer-Encoding of this MIME Part.
	 * Only BINARY, E7BIT and E8BIT are applicable to MIMEMessagePart.
	 * Additionally, for message/partial and message/external-body, the 
	 * MIME standard requires E7BIT encoding. It is possible to
	 * set encoding prior to setting the contentSubType.
	 * If a different value is specified, no error occurs; instead,
	 * this method will be overridden by the putByteStream() method.
	 * @param encoding Value that represents the encoding
	 * @see MIMEBodyPart#BINARY
	 * @see MIMEBodyPart#E7BIT
	 * @see MIMEBodyPart#E8BIT
	 * @exception MIMEException If the value is not one of BINARY, E7BIT or E8BIT.
	 */
	void setContentEncoding(int encoding);

	/** 
	 * Returns value of Content-Transfer-Encoding of this MIME Part. -1 if none present.
	 * @see MIMEBodyPart#BINARY
	 * @see MIMEBodyPart#E7BIT
	 * @see MIMEBodyPart#E8BIT
	 */
	int getContentEncoding();

	/**
	 * Sets the specified message as the body of this part.
	 * @param msg Message to be set as body of this part.
	 * @param clone If false stores reference to passed object instead of cloning a copy.
	 * @exception MIMEException If already set (or) can not be set.
	 */
	void setMessage(MIMEMessage* msg, bool clone);

	/**
	 * Returns the MIMEMessage that is the Body of this part.
	 * @param clone If false returns reference to the object instead of a cloned copy.
	 * @exception MIMEException If no Message exists in body-data.
	 */
	MIMEMessage* getMessage(bool clone);

	/**
	 * Deletes the MIMEMessage that is the Body of this part.
	 * Noop if no body was ever set.
	 */
	void deleteMessage();

	/**
	 * Sets the Headers associated with External Body, for external-body content-subtypes
	 * only. If already set, these headers are ignored for other subtypes (rfc822 and message-partial).
	 * @param name Name of the header field. Should not include ':'.
	 * @param value Value of the header field to be added.
	 * @exception MIMEException if name if invalid.
	 */
	void setExtBodyHeader(const WString& name, const WString& value);

	/**
	 * Returns the value of the specified header associated with External Body.
	 * Applicable to external-body subtypes only.
	 * Returns false as the first field of the value pair if the header is not
	 * present.
	 * @param name Name of the header field.
	 */
	value_pair getExtBodyHeader(const WString& name);

	/**
	 * Returns all the headers in this Part as an array of Header objects.
	 */
	std::vector<MIMEHeader> getAllHeaders();

	/**
	 * Outputs a byte-stream for this part with its MIME part headers and encoded
	 * body data.
	 * @param os OutputStream to write to
	 * @exception IOException If an IO error occurs.
	 * @exception MIMEException If an error occurs during encoding.
	 */
	void putByteStream(OutputStream& os);

	/**
	 * Clones an instance of this MIMEMessagePart object.
	 */
	MIMEBodyPart* clone();

protected:

	/** 
	 * Sets the specified message as the body of this part.
	 * This method will make a clone of the given MIMEMessage object.
	 * @param msg Message to be set as body of this part.
	 * @exception MIMEException If already set (or) can not be set.
	 */
	void setMessage(MIMEMessage* msg);

	/**
	 * Returns the MIMEMessage that is the Body of this part.
	 * @exception MIMEException If no Message exists in body-data.
	 */
	MIMEMessage* getMessage();

	/**
	 * Sets the message partial. Stores reference to the supplied inputStream.
	 * Does not copy data. The data in partial is copied as is by putByteStream.
	 * To be used with message/partial subtypes only. It is an error to setPartial()
	 * for other subtypes (rfc822 and external body).
	 * @param instream inputStream that supplies the data for this partial.
	 * @exception MIMEException if content-subtype is not partial or if already set.
	 * @see deletePartial
	 */
	void setPartial(InputStream* instream);

	/**
	 * Deletes the message partial data of this part. Ignores if partial was not set.
	 * @see setPartial
	 */
	void deletePartial();

private:

	static const int BINARY;
	static const int E7BIT;
	static const int E8BIT;
	static const int UNINITIALIZED;

	static const JDFCh* m_StringEncoding[];
	static const JDFCh* m_StringDisposition[];
	static const JDFCh* MESSAGE;

	int m_contentTransferEncoding;
	int m_parsedPart;

	// The key to the hashTable below is the name of the header field.
	// To make sure we handle case differences in the header-name, we
	// must convert the header name to lower-case always prior to the
	// hash look-up. The entries added to the hash table are objects of class
	// MIMEHeader

	hmap<WString,MIMEHeader,ElfHash> m_ExtBodyHeadersTable;
	MIMEMessage* m_theMessage;
	InputStream* m_partial;

	friend class MIMEParser;

};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MIMEMESSAGEPART_H */
