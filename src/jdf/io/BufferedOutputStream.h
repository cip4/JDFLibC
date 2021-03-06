/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2012 The International Cooperation for the Integration of 
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

#ifndef I_JDF_BUFFEREDOUTPUTSTREAM_H
#define I_JDF_BUFFEREDOUTPUTSTREAM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "FilterOutputStream.h"


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
 * The class implements a buffered output stream. 
 * By setting up such an output stream, an application can write bytes
 * to the underlying output stream without necessarily causing a call 
 * to the underlying system for each byte written. The data is written
 * into an internal buffer, and then written to the underlying stream if 
 * the buffer reaches its capacity, the buffer output stream is closed, 
 * or the buffer output stream is explicitly flushed. 
 *
 * @author nverbove  
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT BufferedOutputStream : public FilterOutputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates a new buffered output stream to write data to the specified
	 * underlying output stream with a default 512-byte buffer size.
	 * 
	 * @param out the underlying output stream.
	 */

	BufferedOutputStream(OutputStream& out);

	/**
	 * Creates a new buffered output stream to write data to the specified 
	 * underlying output stream with the specified buffer size.
	 *
	 * @param out the underlying output stream.
	 * @param size the buffer size.
	 * @exception IllegalArgumentException if size == 0
	 */

	BufferedOutputStream(OutputStream& out, size_t size);

	/**
	 * Creates a new buffered output stream to write data to the specified 
	 * underlying output stream with the specified buffer size.
	 * Ownership of the output stream is passed to this and destruction results in destruction of the passed output stream
	 *
	 * @param out the underlying output stream.
	 * @param size the buffer size.
	 * @exception IllegalArgumentException if size == 0
	 */
	 BufferedOutputStream(OutputStream*out, size_t size=2048);

/*@}*/ 

	/**
	 * Destructs this buffered output stream.
	 */

	virtual ~BufferedOutputStream();

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Flushes this buffered output stream. 
	 * This forces any buffered output bytes to be written out to the 
	 * underlying output stream.
	 * 
	 * @exception IOException if an I/O error occurs.
	 * @see FilterOutputStream#mOut
	 */

	void flush();

	/**
	 * Writes <code>blen</code> bytes to this output stream. 
	 * The <code>write</code> method of <code>BufferedOutputStream</code> calls its <code>write</code> method of 
	 * three arguments with the arguments <code>b</code>, <code>blen</code>, <code>0</code>, and <code>blen</code>.
	 * <p>
	 * Note that this method does not call the one-argument <code>write</code> method 
	 * of its underlying stream with the single argument <code>b</code>.
	 *
	 * @param b the data buffer to be written..
	 * @param blen the number of bytes to write.
	 * @exception IOException if an I/O error occurs.
	 */

	void write(const char* b, size_t blen);

	/**
	 * Writes <code>len</code> bytes from the specified byte array starting at offset
	 * <code>off</code> to this buffered output stream. 
	 * <p>
	 * Ordinarily this method stores bytes from the given array into this 
	 * stream's buffer, flushing the buffer to the underlying output stream
	 * as needed. If the requested length is at least as large as this stream's
	 * buffer, however, then this method will flush the buffer and write 
	 * the bytes directly to the underlying output stream. Thus redundant
	 * <code>BufferedOutputStream</code>s will not copy data unnecessarily.
	 * 
	 * @param b the data buffer to be written.
	 * @param blen the size of the data buffer.
	 * @param off the start offset in the data buffer.
	 * @param len the number of bytes to be written.
	 * @exception IOException if an I/O error occurs.
	 */

	void write(const char* b, size_t blen, size_t off, size_t len);

	/**
	 * Writes the specified byte to this buffered output stream.
	 * 
	 * @param b the byte to be written.
	 * @exception IOException if an I/O error occurs.
	 */

	void write(int b);

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The size of the cache
	 *
	 */

	size_t				mSize;	

	/**
	 * The position of the next free byte in the cache
	 *
	 */

	size_t				mCount; 

	/**
	 * The internal buffer where data is stored
	 */

	char*			mBuf;

	bool bKillOutStream;

private:

	/** 
	 * Flush the internal cache buffer.
	 * The cache buffer is written to the underlying output stream
	 * The <code>flush()</code> of the output stream is also called.
	 */

	void flushBuffer();

	//
	// Hide copy constructor and assignment operator.
	//

	BufferedOutputStream(const BufferedOutputStream&);
	BufferedOutputStream& operator=(const BufferedOutputStream&);
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_BUFFEREDOUTPUTSTREAM_H */


/* end of file */
