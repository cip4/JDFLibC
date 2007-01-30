/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2003 The International Cooperation for the Integration of 
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

#include <jdf/util/myuti.h>

#include <jdf/lang/ByteBuffer.h>


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
	
	const int ByteBuffer::ALLIGNMENTSIZE = 1024*64;
	const int ByteBuffer::INITIALSIZE    = 1024*32;
	const int ByteBuffer::MAGICNUMBER    = 52000;
	
	ByteBuffer::ByteBuffer() 
	{
		mBuffer     = new char[INITIALSIZE];
		mSize       =  0;
		mBufferSize = INITIALSIZE;
	}
	
	ByteBuffer::ByteBuffer(int size)
	{
		unsigned long allocSize(size);
		
		mBuffer = new char[allocSize];
		mBufferSize = allocSize;
		mSize = 0;
	}
	
	ByteBuffer::ByteBuffer(const ByteBuffer& b)
	{
		mSize       = b.mSize;
		unsigned long allocSize(b.mSize);
		mBuffer = new char[allocSize];
		mBufferSize = allocSize;
		memcpy(mBuffer,b.mBuffer,b.mSize);
	}
	
	ByteBuffer::ByteBuffer(char* buf, int size, bool clone)
	{
		mBuffer     = buf;
		mSize       = size;
		mBufferSize = size;		
		if (clone)
		{
			mBuffer = new char[size];
			mBufferSize = size;
			memcpy(mBuffer,buf,size);
		}
		else 
		{
			mBuffer = buf;
			mBufferSize = size;
		}
	}
	
	ByteBuffer& ByteBuffer::operator=(char*  buf)
	{
		if (mBuffer)
			delete[] mBuffer;
		mBuffer     = buf;
		mSize       = strlen(buf);
		mBufferSize = mSize;
		return *this;
	}

    ByteBuffer& ByteBuffer::operator=(const ByteBuffer& buf)
    {
		if(this != &buf)
		{
			mSize       = buf.mSize;
			unsigned long allocSize(buf.mSize);
			mBuffer = new char[allocSize];
			mBufferSize = allocSize;
			memcpy(mBuffer,buf.mBuffer,buf.mSize);
		}
		return *this;
    }

	ByteBuffer::~ByteBuffer()
	{
		delete[] mBuffer;
	}
	
	void ByteBuffer::append(char c)
	{
		int available = mBufferSize - mSize;
		if (!available)
			ensureCapacity(10);
		mBuffer[mSize] = c;
		mSize += 1;
	}
	
	void ByteBuffer::append(const char* buf, int length)
	{
		int available = mBufferSize - mSize;
		if (length > available)
			ensureCapacity(length-available);
		
		memcpy(mBuffer+mSize, buf, length);
		mSize += length;
	}
	
	void ByteBuffer::append(const ByteBuffer& b)
	{
		append(b.bytes(),b.size());
	}
	
	void ByteBuffer::append(const std::string& s)
	{
		int available = mBufferSize - mSize;
		if (static_cast<int>(s.length()) > available)
			ensureCapacity(s.length()-available);
		
		memcpy(mBuffer+mSize, s.data(), s.length());
		mSize += s.length();
	}
	
	char* ByteBuffer::bytes() const 
	{
		return mBuffer;
	}
	
	int ByteBuffer::size() const
	{
		return mSize;
	}
	
	void ByteBuffer::reset()
	{
		mSize = 0;
	}
	
	void ByteBuffer::ensureCapacity (int length)
	{
		unsigned long allocSize = std::max (mBufferSize << 1, mBufferSize + length + 1024);
		
		char* pTmp=mBuffer;
		mBuffer = new char[(unsigned long)allocSize];
		memcpy(mBuffer,pTmp,mBufferSize); // only copy the old data
		mBufferSize = allocSize;
		delete[]pTmp;
	}
	
} // namespace JDF
