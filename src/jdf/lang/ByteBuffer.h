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

#ifndef I_JDF_BYTEBUFFER_H
#define I_JDF_BYTEBUFFER_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include "JDFToolsDefs.h"

#include <string>


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
 * This class represent a buffer of bytes.
 * Bytes can be appended to the buffer without worrying about the capacity of the
 * buffer.The ByteBuffer internally manages a buffer of bytes. Bytes can be added
 * to the sequence. If the buffer becomes to small, the ByteBuffer automatically
 * resizes the buffer.
 * @ingroup lang
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT ByteBuffer
{
public:

	/**
	 * The size of the internal buffer will allows be alligned on this boundary
	 * This has internal performance reasons because some systems 
	 * allocate memory on a specific boundary
	 */
	static const size_t ALLIGNMENTSIZE;

	/**
	 * The default initial capacity of the buffer
	 */
	static const size_t INITIALSIZE;

/** 
 * @name Constructors
 */
/*@{*/

	/**
     * Construct a ByteBuffer with the default initial capacity.
     */
	ByteBuffer();

	/**
     * Construct a ByteBuffer of the given capacity.
	 * @param size initial capacity of the ByteBuffer
     */
 	ByteBuffer(size_t size);

	/**
	 * Constructs a new ByteBuffer from a given ByteBuffer
	 * The internal buffer of the given ByteBuffer is copied.
	 * @param b the ByteBuffer to copy
	 */
	ByteBuffer(const ByteBuffer& b);

	/**
	 * Constructs a ByteBuffer with the given buffer
	 * The initial size of the ByteBuffer is given by the <code>size</code> argument.
	 * If <code>clone</code> is <code>true</code> a copy a the given buffer is
	 * is done. If <code>clone</code> is <code>false</code> is, a pointer
	 * to the buffer will be stored, the application may not delete the buffer
	 * when clone is set to false.
	 * @param buf the buffer to use
	 * @param size the size of the buffer
	 * @param clone if true copy the given buffer; else use the buffer 
	 * internally (Transfer Of OwnerShip)
	 */
	ByteBuffer(char* buf, size_t size, bool clone=false);

/*@}*/ 

	/**
	 * Assign the specified array of bytes to this ByteBuffer. 
	 * The ByteBuffer takes ownership of the buffer. 
	 * @param buf array that is the source of characters.
	 */
	ByteBuffer& operator=(char*  buf);
  
	ByteBuffer& operator=(const ByteBuffer& buf);
  	

	/**
	 * Destructs this ByteBuffer.
	 * The internal buffer associated with this CharBuffer is freed.
	 */
	~ByteBuffer();

	/**
	 * This method appends a sequence of bytes represented by the argument <code>buf</code> to this ByteBuffer.
	 * This method will copy <code>length</code> bytes from the given buffer.
	 * This method will not delete the argument buffer.
	 * @param buf the buffer to copy from
	 * @param length the number of bytes to copy
	 */
	void append(const char* buf, size_t length);

	/**
	 * This method appends a sequence of bytes represented by the argument <code>buf</code> to this ByteBuffer.
	 * This method will copy all the bytes from the string argument to this ByteBuffer
	 * @param s the string to copy the bytes from
	 */
	void append(const std::string& s);

	/**
	 * This method appends a ByteBuffer represented by the argument <code>buf</code> to this ByteBuffer.
	 * This method will copy all the bytes from the ByteBuffer argument to this ByteBuffer
	 * @param s the string to copy the bytes from
	 */
	void append(const ByteBuffer& buf);

	/**
	 * This method appends a single byte to this ByteBuffer.
	 * @param c byte to copy
	 */
	void append(char c);

	/**
	 * Returns the internal byte array.
	 * The pointer returned cannot be guaranteed to be the same when the 
	 * internal buffer is modified, for example after an append operation.
	 * Because an append can result is an reallocation of the buffer when
	 * an overflow occurs.
	 * @return the internal byte array.
	 */
	char* bytes() const;

	/**
	 * Returns the size of the internal byte array.
	 * This is the number of bytes stored in the internal byte array
	 * The real length of the buffer might be larger.
	 * @return the size of the internal byte array.
	 */
	size_t   size() const ;

	/**
	 * Empties the internal buffer.
	 * This will make the <code>size()</code> return zero the next time it is called.
	 * The internal buffer is not deleted.
	 */
	void  reset();

	/**
	 * Removes the reference to the internal buffer.
	 * The ByteBuffer will not be the owner of the internal buffer after this
	 * method is called. The caller is responsible for deleting the buffer 
	 * associated with this ByteBuffer.
	 */
	inline void  orphan() {mBuffer = NULL; }

protected:

	static const int	MAGICNUMBER;

	/**
	 * Resizes the internal buffer to hold at least the number of bytes
	 * given by the argument <code>size</code>.
	 */
	void ensureCapacity(size_t size);

	char* mBuffer;
	size_t   mSize;
	size_t   mBufferSize;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

/** @} */

#endif /* I_JDF_BYTEBUFFER_H */
