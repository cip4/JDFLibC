/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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

#ifndef I_JDF_BUFFEREDINPUTSTREAM_H
#define I_JDF_BUFFEREDINPUTSTREAM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "FilterInputStream.h"


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
 * A <code>BufferedInputStream</code> adds functionality to another input stream-namely,
 * the ability to buffer the input and to support the <code>mark</code> and <code>reset</code> methods.
 * When the <code>BufferedInputStream</code> is created, an internal buffer
 * array is created. As bytes from the stream are read or skipped, 
 * the internal buffer is refilled as necessary from the contained input 
 * stream, many bytes at a time. The <code>mark</code> operation remembers a point in the
 * input stream and the reset operation causes all the bytes read since 
 * the most recent <code>mark</code> operation to be reread before new bytes
 * are taken from the contained input stream. 
 *
 * @author nverbove     
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT BufferedInputStream : public FilterInputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates a BufferedInputStream and saves its argument, the input stream <code>in</code>,
	 * for later use. An internal buffer array with the default size of 2048 bytes is created
	 * and stored in <code>mBuf</code>.
	 *
	 * @param in the underlying input stream.
	 */

	BufferedInputStream(InputStream& in);

	/**
	 * Creates a <code>BufferedInputStream</code> with the specified buffer size, 
	 * and saves its argument, the input stream <code>mIn</code>, for later use.
	 * An internal buffer array of length <code>size</code> is created and stored in <code>mBuf</code>.
	 * 
	 * @param in the underlying input stream.
	 * @param size the buffer size.
	 * @exception IllegalArgumentException if size == 0
	 */

	BufferedInputStream(InputStream& in, unsigned int size);
	
	/**
	 * Creates a <code>BufferedInputStream</code> with the specified buffer size, 
	 * and saves its argument, the input stream <code>mIn</code>, for later use.
	 * An internal buffer array of length <code>size</code> is created and stored in <code>mBuf</code>.
	 * Ownership of the input stream is passed to this and destruction results in destruction of the passed input stream
	 * 
	 * @param in the underlying input stream.
	 * @param size the buffer size.
	 * @exception IllegalArgumentException if size == 0
	 */
	BufferedInputStream(InputStream* in, unsigned int size=2048);

/*@}*/ 

	/**
	 * Destructs this buffered output stream.
	 */
	
	virtual ~BufferedInputStream();

	/**
	 * Closes this input stream and releases any system resources associated 
	 * with the stream.
	 *
 	 * @exception IOException if an I/O error occurs.
	 */

	void close();

	/**
	 * See the general contract of the <code>read</code> method of <code>InputStream</code>.
	 * 
	 * @return the next byte of data, or <code>-1</code> if the end of the stream is reached.
	 * @exception IOException if an I/O error occurs.
	 * @see FilterInputStream#mIn    
	 */

	int  read();

	/**
	 * Reads bytes from this byte-input stream into the specified byte array, 
	 * starting at the given offset. 
	 * <p>
	 * This method implements the general contract of the corresponding <code>read</code> method of 
	 * the <code>InputStream</code> class. As an additional convenience,
	 * it attempts to read as many bytes as possible by repeatedly invoking 
	 * the <code>read</code> method of the underlying stream. This iterated 
	 * <code>read</code> continues until one of the following conditions becomes true:
	 * <UL>
	 * <LI>The specified number of bytes have been read, 
	 * <LI>The <code>read</code> method of the underlying stream returns <code>-1</code>, indicating end-of-file, or 
	 * <LI>The <code>available</code> method of the underlying stream returns zero, indicating that further input requests would block. 
	 * </UL>
	 * If the first <code>read</code> on the underlying stream returns <code>-1</code> to 
	 * indicate end-of-file then this method returns <code>-1</code>. 
	 * Otherwise this method returns the number of bytes actually read. 
	 * Subclasses of this class are encouraged, but not required, to attempt 
	 * to read as many bytes as possible in the same fashion.
	 * 
	 * @return the number of bytes read, or -1 if the end of the stream has been reached. 
	 * @param b the destination buffer.
	 * @param blen the size of the destination buffer.
	 * @param off offset at which to start storing bytes.
	 * @param len maximum number of bytes to read.
	 * @exception IOException if an I/O error occurs.
	 * @see InputStream#read    
	 */

	int	 read(char* b, int blen, int off, int len);

	/**
	 * Reads bytes from this byte-input stream into the specified byte array, 
	 * This method has the same effect as calling <code>read(b,blen,0,blen)</code>.
	 * 
	 * @return the number of bytes read, or -1 if the end of the stream has been reached. 
	 * @param b the destination buffer.
	 * @param blen the size of the destination buffer.
	 * @exception IOException if an I/O error occurs.
	 */

	int  read(char* b, int blen);

	/**
	 * Returns the number of bytes that can be read from this input stream without blocking. 
	 * The <code>available</code> method of <code>BufferedInputStream</code> returns the sum 
	 * of the the number of bytes remaining to be read in the buffer <code>(mCount - mPos)</code> 
	 * and the result of calling the <code>available</code> method of the
	 * underlying input stream.
	 * 
	 * @return the number of bytes that can be read from this input stream without blocking.
	 * @see FilterInputStream#mIn
	 * @exception IOException if an I/O error occurs.
	 */

	int  available();

	/**
	 * See the general contract of the <code>mark</code> method of <code>InputStream</code>.
	 * 
	 * @param readAheadLimit the maximum limit of bytes that can be read before the mark position becomes invalid.
	 * @see BufferedInputStream#reset
	 * @see InputStream#mark
	 */

	void mark(int readAheadLimit);

	/**
	 * Tests if this input stream supports the <code>mark</code> and <code>reset</code> methods. 
	 * The <code>markSupported</code> method of <code>BufferedInputStream</code> returns <code>true</code>.
	 * 
	 * @return a boolean indicating if this stream type supports the mark and reset methods.
	 * @see InputStream#mark
	 * @see InputStream#reset
	 */

	bool markSupported();

	/**
	 * Skips over and discards <code>n</code> bytes of data from the 
     * input stream. The <code>skip</code> method may, for a variety of 
     * reasons, end up skipping over some smaller number of bytes, 
     * possibly zero. The actual number of bytes skipped is returned. 
     * See the general contract of the <code>skip</code> method of <code>InputStream</code>.
	 * <p>
     * The <code>skip</code> method of <code>BufferedInputStream</code> 
     * compares the number of bytes it has available in its buffer, 
     * <i>k</i>, where <i>k</i>&nbsp;= <code>count&nbsp;- pos</code>, 
     * with <code>n</code>. If <code>n</code>&nbsp;&le;&nbsp;<i>k</i>, 
     * then the <code>pos</code> field is incremented by <code>n</code>. 
     * Otherwise, the <code>pos</code> field is incremented to have the 
     * value <code>count</code>, and the remaining bytes are skipped by 
     * calling the <code>skip</code> method on the underlying input 
     * stream, supplying the argument <code>n&nbsp;-</code>&nbsp;<i>k</i>. 
	 
	 * 
	 * @return the actual number of bytes skipped.
	 * @param n the number of bytes to be skipped.
	 * @exception IOException if an I/O error occurs.
	 */

	long skip(long n);

	/**
	 * See the general contract of the <code>reset</code> method of <code>InputStream</code>. 
	 * If <code>mMark</code> is <code>-1</code> (no mark has been set or the 
	 * mark has been invalidated), an IOException is thrown. 
	 * Otherwise, <code>mPos</code> is set equal to <code>mMark</code>.
	 *  Stream marks are intended to be used in
     * situations where you need to read ahead a little to see what's in
     * the stream. Often this is most easily done by invoking some
     * general parser. If the stream is of the type handled by the
     * parser, it just chugs along happily. If the stream is not of
     * that type, the parser should toss an exception when it fails. If an
     * exception gets tossed within readlimit bytes, the parser will allow the
     * outer code to reset the stream and to try another parser.
	 * 
	 * @exception IOException if this stream has not been marked or if the mark has been invalidated.
	 * @see BufferedInputStream#mark    
	 */

	void reset();

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Fill the interal cache buffer.
	 * 
	 * @return the number of characters put into the buffer, -1 if EOF occurred.
	 * @exception IOException If an I/O error occurs.
	 */

	void fill();

	/**
	 * Fill the buffer <code>cbuf</code> with at most len characters from the underlying
	 * inputstream
	 * 
	 * @return the number of characters put into the buffer, -1 if EOF occurred.
	 * @param buf the buffer to fill.
	 * @param clen the size of the destination buffer
	 * @param off offset at which to start storing bytes.
	 * @param len the maximum number of bytes to read.
	 * @exception IOException If an I/O error occurs.
	 */

	int read1(char* cbuf, int clen, int off, int len);

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The size of the internal buffer.
	 */

	int				mSize;

	/**
	 * The index one greater than the last valid byte in the buffer.
	 */

	int				mCount;

	/** 
     * The internal buffer array where the data is stored.
	 */

	char*			mBuf;

	/**
	 * The current position in the buffer.
	 * If mPos == mCount then no characters are available.
	 */

	int				mPos;

    /**
	 * The value of the <code>pos</code> field at the time the last 
	 * <code>mark</code> method was called.
	 */

	int				mMarkPos;

	/**
	 *  
     * The maximum read ahead allowed after a call to the <code>mark</code> method 
	 * before subsequent calls to the <code>reset</code> method fail.
	 */

	int				mReadAheadLimit;

	bool bKillInStream;

private:

	/**
	 * Validate that the input stream is open for reading, meaning not closed.
	 */

	void ensureOpen();

	//
	// Hide copy constructor and assignment operator.
	//

	BufferedInputStream(const BufferedInputStream&);
	BufferedInputStream& operator=(const BufferedInputStream&);
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_BUFFEREDINPUTSTREAM_H */
