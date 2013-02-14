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

/******************************************************************************
*	Includes
******************************************************************************/ 

#include <jdf/lang/Exception.h>

#include <jdf/io/BufferedInputStream.h>


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

	BufferedInputStream::BufferedInputStream(InputStream& in) :
FilterInputStream	(in),
mSize				(2048),
mCount				(0),
mPos				(0)
{
	mMarkPos         = -1;
	mReadAheadLimit = 0;

	mBuf = new char[mSize];
}

BufferedInputStream::BufferedInputStream(InputStream& in, size_t size) :
FilterInputStream	(in),
mSize				(size),
mCount				(0),
mPos				(0)
{
	mMarkPos        = -1;
	mReadAheadLimit =0;

	if (size == 0)
		throw IllegalArgumentException("BufferedInputStream size is zero");

	mBuf = new char[mSize];
}

BufferedInputStream::BufferedInputStream(InputStream* in, size_t size) :
FilterInputStream	(*in),
mSize				(size),
mCount				(0),
mPos				(0)
{
	mMarkPos        = -1;
	mReadAheadLimit =0;
	if (size == 0)
		throw IllegalArgumentException("BufferedInputStream size is zero");

	mBuf = new char[mSize];
}

BufferedInputStream::~BufferedInputStream()
{
	delete[] mBuf;
	mBuf = NULL;
}

void BufferedInputStream::close()
{
	if (mIn)
	{
		mIn->close();
		if(bKillInStream)
		{
			delete(mIn);
		}
		mIn = NULL;
		delete[] mBuf;
		mBuf = NULL;

	}
}

void BufferedInputStream::ensureOpen()
{
	if (mIn == NULL)
		throw IOException("Stream closed");
}

void BufferedInputStream::fill()
{
	if(mMarkPos < 0)
	{
		mPos = 0;
		mMarkPos=0;
	}
	else
	{
		if(mPos >= mSize)
		{
			if(mMarkPos > 0)
			{
				size_t i = mPos - mMarkPos;
				memcpy(mBuf,mBuf+mMarkPos,i);
				mPos     = i;
				mMarkPos = 0;
			}
			else
			{
				if(mSize >= mReadAheadLimit)
				{
					mMarkPos = -1;
					mPos = 0;
				}
				else
				{
					size_t j = mPos * 2;
					if(j > mReadAheadLimit)
						j = mReadAheadLimit;
					char* buf0 = new char[j];
					memcpy(buf0,mBuf,mPos);
					delete[] mBuf;
					mBuf = buf0;
					mSize = j;
				}
			}
		}
	}
	mCount = mPos;

	ssize_t k = mIn->read(mBuf, mSize, mPos, mSize - mPos);
	if(k > 0)
		mCount = k + mPos;
}

int BufferedInputStream::read()
{
	ensureOpen();

	if(mPos >= mCount)
	{
		fill();
		if(mPos >= mCount)
			return -1;
	}
	return (unsigned char) mBuf[mPos++];
}

ssize_t	BufferedInputStream::read(char* cbuf, size_t clen)
{
	return read(cbuf,clen,0,clen);
}

ssize_t	BufferedInputStream::read(char* cbuf, size_t clen, size_t off, size_t len)
{
	ensureOpen();

	if(off < 0 || off > clen || len < 0 || off + len > clen || off + len < 0)
		throw IndexOutOfBoundsException();
	if(len == 0)
		return 0;
	ssize_t k = read1(cbuf, clen,  off, len);
	if(k <= 0)
		return k;
	size_t l=0;
	for(; k < len && mIn->available() > 0; k += l)
	{
		l = read1(cbuf, clen, off + k, len - k);
		if(l <= 0)
			break;
	}
	return k;
}

ssize_t BufferedInputStream::read1(char* cbuf, size_t clen, size_t off, size_t len)
{
	ssize_t avail = mCount - mPos;
	if(avail <= 0)
	{
		// if the requested lengthis larger than the buffer, and if
		// there is no mark/reset activity, do not bother to copy
		// the bytes into the local buffer. In this way buffered stream
		// will cascade harmlessly

		if(len >= mSize && mMarkPos < 0)
			return mIn->read(cbuf,clen, off, len);
		fill();
		avail = mCount - mPos;
		if(avail <= 0)
			return -1;
	}
	ssize_t cnt = avail >= len ? len : avail;
	memcpy(cbuf+off,mBuf+mPos,cnt);
	mPos += cnt;
	return cnt;
}

size_t BufferedInputStream::available()
{
	return (mCount-mPos) + mIn->available();
}

void BufferedInputStream::mark(size_t readAheadLimit)
{
	if (readAheadLimit < 0)
		throw IllegalArgumentException("BufferedInputStream readAheadlimit is negative");

	mReadAheadLimit = readAheadLimit;
	mMarkPos = mPos;
}

bool BufferedInputStream::markSupported()
{
	return true;
}

size_t BufferedInputStream::skip(size_t n)
{
	if(n == 0L)
		return 0L;

	long l1 = mCount - mPos;

	if(l1 <= 0L)
	{
		if(mMarkPos < 0)
			return mIn->skip(n);
		fill();
		l1 = mCount - mPos;
		if(l1 <= 0L)
			return 0L;
	}
	long l2 = l1 >= n ? n : l1;
	mPos += l2;
	return l2;
}

void BufferedInputStream::reset()
{
	ensureOpen();

	if (mMarkPos == -1 && mPos!=0)
		throw IOException("Resetting to invalid mark");
	else if (mMarkPos != -1)
		mPos = mMarkPos;
	else if (mMarkPos == -1)
		mPos = 0;
}


} // namespace JDF

/* end of file */
