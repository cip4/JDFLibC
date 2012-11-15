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

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#pragma warning( disable : 4786 ) // long debug names from stl

#include "PushbackInputStream.h"

#include <jdf/lang/Exception.h>


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

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

PushbackInputStream::PushbackInputStream(InputStream& in) :
	FilterInputStream(in)
{
	mSize = 1;
	mPos  = mSize;
	if (mSize)
		mBuf  = new char[mSize];
}

PushbackInputStream::PushbackInputStream(InputStream& in, unsigned int size) :
	FilterInputStream(in)
{
	mSize = size;
	mPos  = size;
	if (mSize)
		mBuf  = new char[mSize];
	else
		throw IllegalArgumentException("pushback size of zero is not allowed");
}

PushbackInputStream::~PushbackInputStream()
{
	if (mBuf)
	{
		delete[] mBuf;
		mBuf = NULL;
	}
}

void PushbackInputStream::ensureOpen()
{
	if (mIn == NULL)
		throw IOException("Stream closed");
	else
		return;
}

size_t PushbackInputStream::available()
{
	ensureOpen();

	return ((mSize - mPos) + FilterInputStream::available());
}

void PushbackInputStream::close()
{
	if (mIn == NULL)
		return;
	else
	{
		mIn->close();
		mIn = NULL;
		delete[] mBuf;
		mBuf = NULL;
		return;
	}
}

int  PushbackInputStream::read()
{
	ensureOpen();
	if (mPos < mSize)
		return  (unsigned char) mBuf[mPos++];
	else
		return FilterInputStream::read();
}

ssize_t  PushbackInputStream::read(char* b, size_t blen)
{
	return PushbackInputStream::read(b,blen,0,blen);
}

ssize_t  PushbackInputStream::read(char* b, size_t blen, size_t off, size_t len)
{
	ensureOpen();
	
	if (b == NULL)
		throw NullPointerException();

	if (blen < 0 || len < 0 || (off+len) < 0 || (off+len) > blen)
		throw IndexOutOfBoundsException("PushbackInputStream::read one of the arguments in out of bounds");

	if (len == 0)
		return 0;

	int k = mSize - mPos;

	if (k > 0)
	{
		if (len < k)
			k = len;

		memcpy(b+off,mBuf+mPos,k);
		mPos += k;
		off  += k;
		len  -= k;
	}
	if (len > 0)
	{
		len = FilterInputStream::read(b,blen,off,len);
		if (len == -1)
			return (k != 0 ? k : -1);
		else
			return k + len;
	}
	else
		return k;
}

size_t PushbackInputStream::skip(size_t n)
{
	ensureOpen();
	if (n==0) 
		return 0;

	size_t l = mSize - mPos;

	if (l > 0L)
	{
		if (n < l)
			l = n;
		mPos += l;
		n -= l;
	}
	if (n > 0L)
		l += FilterInputStream::skip(n);
	return l;
}

void PushbackInputStream::unread(char* b, size_t blen, size_t off, size_t len)
{
	ensureOpen();
	if (len > mPos)
		throw IOException("Push back buffer is full");
	else
	{
		mPos -= len;
		memcpy(mBuf+mPos, b+off,len);
	}
}

void PushbackInputStream::unread(char* b, size_t blen)
{
	unread(b,blen,0,blen);
}

void PushbackInputStream::unread(int b)
{
	ensureOpen();
	if (mPos == 0)
		throw IOException("Push back buffer is full");
	else
		mBuf[--mPos] = b;
}

} // namespace JDF

/* end of file */
