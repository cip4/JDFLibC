/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2013 The International Cooperation for the Integration of 
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

#ifndef I_JDF_CHUNKEDINPUTSTREAM_H
#define I_JDF_CHUNKEDINPUTSTREAM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include <jdf/io/FilterInputStream.h>

#include <string>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class InputStream;
	class MessageHeader;

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
 * An InputStream that implements HTTP/1.1 chunking.
 * <p>
 * This class lets a HTTP connection reads its request data as an HTTP/1.1
 * chunked stream. Chunked stream are a way to send arbitrary-length data without
 * having to know beforehand how much you're going to send. They are introduced
 * by a "Transfer-Encoding: chunked" header, so if such a header appears in an 
 * HTTP request you should use this class to ready any data.
 * <p>
 * The use of a ChunkedInputStream is transparent for users of an HTTP Connection.
 * If an HTTP connection detects that it's request data is chunked encoded, it
 * will automatically create a ChunkedInputStream for it.
 * 
 * rfc2068
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT ChunkedInputStream : public FilterInputStream
{
public:
	
/** 
 * @name Constructors
 */
/*@{*/

	ChunkedInputStream(InputStream* in,MessageHeader& responses);
	~ChunkedInputStream();
/*@}*/ 
	/**
	 * The FilterInputStream implementation of the single-byte read() method 
	 * just reads directly from the underlying stream. We want to go through our 
	 * own read-block method, so we have to override.
	 */
	int read();
	int read(char* b, size_t blen);
	int read(char* b, size_t blen, size_t off, size_t len);
	int getContentLength();

private:

	std::string readLine(bool& eof);

	void startChunk();
	void readFooters();

	char* buf;
	size_t contentLength;
	int chunkCount;
	bool isDone;
	MessageHeader& mResponses;
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_CHUNKEDINPUTSTREAM_H */
