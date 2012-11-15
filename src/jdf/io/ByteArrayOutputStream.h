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

#ifndef I_JDF_BYTEARRAYOUTPUTSTREAM_H
#define I_JDF_BYTEARRAYOUTPUTSTREAM_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "OutputStream.h"


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class ByteBuffer;
	class WString;

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
 * This class implements an output stream in which the data is written into a byte array. 
 * The buffer automatically grows as data is written to it. The data can be retrieved 
 * using toByteArray() and toString(). 
 *
 * @author nverbove    
 * @ingroup io
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT ByteArrayOutputStream : public OutputStream
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates a new byte array output stream. The buffer capacity is initially 32 bytes, 
	 * though its size increases if necessary.
	 */

	ByteArrayOutputStream();

	/**
	 * Creates a new byte array output stream, with a buffer capacity of the specified size, in bytes.
	 * 
	 * @param size the initial size.
	 * @throw IllegalArgumentException if size is zero.
	 */

	ByteArrayOutputStream(size_t size);

/*@}*/ 

	/**
	 * Destruct this byte array output stream.
	 */

	~ByteArrayOutputStream();

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Writes the specified byte to this byte array output stream.
	 * 
	 * @param b the byte to be written.
	 * @exception IOException if an I/O error occurs.
	 */

	void write(int b);

	/**
	 * Writes <code>len</code> bytes from the specified byte array.
	 * 
	 * @param b the data.
	 * @param blen the size of the data.
	 * @exception IOException if an I/O error occurs.
	 */

	void write(const char* b, size_t blen);

	/**
	 * Writes <code>len</code> bytes from the specified byte array starting at offset <code>off</code> to this
	 * byte array output stream.
	 * 
	 * @param b the data.
	 * @param blen the size of the data.
	 * @param off the start offset in the data.
	 * @param len the number of bytes to write.
	 * @exception IOException if an I/O error occurs.
	 */

	void write(const char* b, size_t blen, size_t off, size_t len);

	/**
	 * Writes the complete contents of this byte array output stream to the specified 
	 * output stream argument, as if by calling the output stream's write method using <code.out.write(buf,count, 0, count)</code>.
	 * 
	 * @param out the output stream to which to write the data.
	 * @exception IOException if an I/O error occurs.
	 */

	void writeTo(OutputStream& out);

	/**
	 * Converts the buffer's contents into a string, translating bytes into characters according
	 * to the platform's default character encoding.
	 * 
	 * @return String translated from the buffer's contents
	 */

	WString toString();

	/**
	 * Converts the buffer's contents into a string, translating bytes into characters according
	 * to the specified character encoding.
	 * only UTF-8 and "" are supported momentarily
	 * 
	 * @param enc a character-encoding scheme
	 * @return String translated from the buffer's contents
	 * @throws IllegalArgumentException for unkown ecodings
	 */
	WString toString(const WString& enc);

	/**
	 * Creates a newly allocated byte array.
	 * Its size is the current size of this output stream and the valid contents
	 * of the buffer have been copied into it.
	 * 
	 * @return the current contents of this output stream, as a byte array.
	 * @see ByteArrayOutputStream#size()    
	 */

	ByteBuffer* toByteArray();

	/**
	 * Returns the current size of the buffer.
	 * 
	 * @return the value of the <code>mCount</code> field, which is the number of valid bytes in this output stream.
	 * @see ByteArrayOutputStream#mCount    
	 */

	size_t	 size();

	/**
	 * Closes this output stream and releases any system resources associated 
	 * with this stream. 
	 * A closed stream cannot perform output operations and cannot be reopened. 
	 */

	void close();

	/**
	 * Resets the count field of this byte array output stream to zero,
	 * so that all currently accumulated output in the ouput stream is discarded. 
	 * The output stream can be used again, reusing the already allocated buffer space.
	 * 
	 * @see ByteArrayOutputStream#mCount    
	 */

	void reset();

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Resizes the buffer with the specified <code>count</code> of bytes.
	 * 
	 * @param count bytes to add to the buffer.
	 */

	void resize(int count);

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The buffer where data is stored.
	 */

	ByteBuffer* mBuf;


	/**
	 * The total number of bytes in the buffer.
	 */

	size_t	  mLength;

	/**
	 * The number of valid bytes in the buffer.
	 */

	size_t	  mCount;

	/**
	 * <code>true</code> if this output stream has been closed; <code>false</code> otherwise.
	 */

	bool  mClosed;
};




/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_BYTEARRAYOUTPUTSTREAM_H */


/* end of file */
