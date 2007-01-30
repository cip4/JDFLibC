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

#ifndef I_JDF_PUSHBACKINPUTSTREAM_H
#define I_JDF_PUSHBACKINPUTSTREAM_H

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
 * A <code>PushbackInputStream</code> adds functionality to another input stream, namely 
 * the ability to "push back" or "unread" one byte.
 * This is useful in situations where it is convenient for a fragment of code 
 * to read an indefinite number of data bytes that are delimited by a 
 * particular byte value; after reading the terminating byte,
 * the code fragment can "unread" it, so that the next read operation
 * on the input stream will reread the byte that was pushed back.
 * For example, bytes representing the characters constituting an identifier
 * might be terminated by a byte representing an operator character;
 * a method whose job is to read just an identifier can read until
 * it sees the operator and then push the operator back
 * to be re-read. 
 *
 * @author nverbove     
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT PushbackInputStream : public FilterInputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates a PushbackInputStream and saves its argument, 
	 * the input stream in, for later use. 
	 * Initially, there is no pushed-back byte (the field pushBack is 
	 * initialized to <code>-1</code>).
	 * 
	 * @param in the input stream from which bytes will be read.
	 */

	PushbackInputStream(InputStream& in);

	/**
	 * Creates a PushbackInputStream with a pushback buffer of the specified 
	 * size, and saves its argument, the input stream <code>in</code>, 
	 * for later use. Initially, there is no pushed-back byte 
	 * (the field pushBack is initialized to <code>-1</code>).
	 * 
	 * @param in the input stream from which bytes will be read.
	 * @param size the size of the pushback buffer.
	 * @exception IllegalArgumentException if size is == 0 
	 */

	PushbackInputStream(InputStream& in, unsigned int size);

/*@}*/ 
	~PushbackInputStream();

	/**
	 * Returns the number of bytes that can be read from this input stream 
	 * without blocking. This method calls the <code>available</code> method 
	 * of the underlying input stream; it returns that value plus the number 
	 * of bytes that have been pushed back.
	 * 
	 * @return the number of bytes that can be read from the input stream without blocking.
	 * @exception IOException if an I/O error occurs.
	 * @see FilterInputStream#mIn
     * @see FilterInputStream.available()
	 */

	int  available();

	/**
	 * Closes this input stream and releases any system resources associated
	 * with the stream.
	 * @exception IOException if an I/O error occurs.
	 */

	void close();

	/**
	 * Reads the next byte of data from this input stream.
	 * The value byte is returned as an int in the range <code>0</code> to <code>255</code>.
	 * If no byte is available because the end of the stream has 
	 * been reached, the value <code>-1</code> is returned. 
	 * This method blocks until input data is available, 
	 * the end of the stream is detected, or an exception is thrown. 
	 * <p>
	 * This method returns the most recently pushed-back byte,
	 * if there is one, and otherwise calls the <code>read</code> method of its
	 * underlying input stream and returns whatever value that method returns.
	 * 
	 * @return the next byte of data, or -1 if the end of the stream has been reached.
	 * @exception IOException if an I/O error occurs.
	 * @see InputStream#read()
	 */

	int  read();

	/**
	 * Reads up to <code>blen</code> bytes of data from this input stream into an array of bytes.
	 * This method first reads any pushed-back bytes; after that,
	 * if fewer than <code>blen</code> bytes have been read then it reads from the
	 * underlying input stream. This method blocks until at least <code>1</code> byte of 
	 * input is available.
	 * 
	 * @return the total number of bytes read into the buffer, or <code>-1</code> if there is no more data because the end of the stream has been reached.
	 * @param b the buffer into which the data is read.
	 * @param blen the size of the buffer.
	 * @see FilterInputStream#read(char*,int,int,int)
	 * @exception IOException if an I/O error occurs.	 
	 */

	int  read(char* b, int blen);

	/**
	 * Reads up to <code>len</code> bytes of data from this input stream into an array
	 * of bytes. This method first reads any pushed-back bytes; after that,
	 * if fewer than <code>len</code> bytes have been read then it reads from the
	 * underlying input stream. This method blocks until at least <code>1</code> byte of 
	 * input is available.
	 * 
	 * @return the total number of bytes read into the buffer, or <code>-1</code> if there is no more data because the end of the stream has been reached.
	 * @param b the buffer into which the data is read.
	 * @param blen the size of the buffer
	 * @param the start offset of the data. 
	 * @param the maximum number of bytes read.
	 * @exception IOException if an I/O error occurs.
	 * @see InputStream#read(char*, int, int)    
	 */

	int  read(char* b, int blen, int off, int len);

	/**
	 * Skips over and discards n bytes of data from this input stream. 
	 * The <code>skip</code> method may, for a variety of reasons, end up skipping 
	 * over some smaller number of bytes, possibly zero. If <code>n</code> is negative,
	 * no bytes are skipped. 
	 * <p>
	 * The <code>skip</code> method of <code>PushbackInputStream</code> first
	 * skips over the bytes in the pushback buffer, if any. 
	 * It then calls the <code>skip</code> method of the underlying input stream 
	 * if more bytes need to be skipped. The actual number of bytes skipped 
	 * is returned.
	 * 
	 * @return the actual number of bytes skipped.
	 * @param n the number of bytes to be skipped.
	 * @exception IOException if an I/O error occurs.
	 * @see FilterInputStream#mIn
	 * @see InputStream#skip(long n)
	 */

	long skip(long n);

	/**
	 * Pushes back a portion of an array of bytes by copying it to the 
	 * front of the pushback buffer. After this method returns, 
	 * the next byte to be read will have the value <code>b[off]</code>, 
	 * the byte after that will have the value <code>b[off+1]</code>, and so forth.
	 *
	 * @param b the char array to push back.
	 * @param blen the size of the char array
	 * @param off the start offset of the data.
	 * @param len the number of bytes to push back.
	 * @exception IOException If there is not enough room in the pushback buffer for the specified number of bytes.
	 */

	void unread(char* b, int blen, int off, int len);

	/**
	 * Pushes back an array of bytes by copying it to the 
	 * front of the pushback buffer. After this method returns, 
	 * the next byte to be read will have the value <code>b[0]</code>, 
	 * the byte after that will have the value <code>b[1]</code>, and so forth.
	 *
	 * @param b the char array to push back.
	 * @param blen the size of the char array
	 * @exception IOException If there is not enough room in the pushback buffer for the specified number of bytes.
	 */
	void unread(char* b, int blen);

	/**
	 * Pushes back a byte by copying it to the front of the pushback buffer.
	 * After this method returns, the next byte to be read will have the value
	 * (byte)b.
	 *
	 * @param b the int value whose low-order byte is to be pushed back.
	 * @exception IOException If there is not enough room in the pushback buffer for the byte.
	 */

	void unread(int b);

private:

	/**
	 * Validate that the input stream is open for reading, meaning not closed.
	 */

	void ensureOpen();


	///////////////////////////////////////////////////////////////////////////
	// Private Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The pushback buffer.
	 */

	char* mBuf;

	/**
	 * The position within the pushback buffer from which the next byte will 
	 * be read. When the buffer is empty, <code>pos</code> is equal to <code>mSize</code>; when
	 * the buffer is full, <code>pos</code> is equal to zero.
	 */

	unsigned int  mPos;

	/**
	 * The size of the pushback buffer.
	 */

	unsigned int  mSize;

	//
	// Hide copy constructor and assignment operator.
	//

	PushbackInputStream(const PushbackInputStream&);
	PushbackInputStream& operator=(const PushbackInputStream&);
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF


#endif /* I_JDF_PUSHBACKINPUTSTREAM_H */
