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

#include <jdf/lang/WString.h>
#include <jdf/util/myuti.h>

#include <jdf/lang/CharBuffer.h>


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
	
	const size_t CharBuffer::ALLIGNMENTSIZE=1024*64;
	const size_t CharBuffer::INITIALSIZE   =1024*4;
	const int CharBuffer::MAGICNUMBER   = 52000;
	
	CharBuffer::CharBuffer() 
	{
		mBuffer     = new JDFCh[INITIALSIZE];
		mSize       =  0;
		mBufferSize = INITIALSIZE;
	}
	
	CharBuffer::CharBuffer(size_t size)
	{
		size_t allocSize(size*sizeof(JDFCh));
#ifdef PLTF_WIN32
		if (allocSize > MAGICNUMBER)
			allocSize = ((allocSize + ALLIGNMENTSIZE - 1) / ALLIGNMENTSIZE) * ALLIGNMENTSIZE;
#endif
		allocSize   = allocSize/sizeof(JDFCh);
		mBuffer     = new JDFCh[allocSize];
		mBufferSize = allocSize;
		mSize       = 0;
	}
	
	CharBuffer::CharBuffer(const CharBuffer& b)
	{
		size_t allocSize(b.mSize);
		mSize       = b.mSize;
		mBuffer     = new JDFCh[allocSize];
		mBufferSize = allocSize;
		memcpy(mBuffer,b.mBuffer,b.mSize*sizeof(JDFCh));
	}

    CharBuffer& CharBuffer::operator=(const CharBuffer& buf)
    {
		if(this != &buf)
		{
			mSize       = buf.mSize;
			size_t allocSize(buf.mSize);
			mBuffer = new JDFCh[allocSize];
			mBufferSize = allocSize;
			memcpy(mBuffer,buf.mBuffer,buf.mSize);
		}
		return *this;
    }

	
	CharBuffer::CharBuffer(JDFCh* buf, size_t size, bool clone)
	{
		mBuffer     = buf;
		mSize       = size;
		if (clone)
		{
			mBuffer     = new JDFCh[mSize];
			mBufferSize = mSize;
			memcpy(mBuffer,buf,size*sizeof(JDFCh));
		}
		else 
		{
			mBuffer = buf;
			mBufferSize = size;
		}
	}
	
	CharBuffer::~CharBuffer()
	{
		delete[] mBuffer;
	}
	
	void CharBuffer::append(JDFCh* buf, size_t length)
	{
		size_t available = mBufferSize - mSize;
		if (length > available)
			ensureCapacity(length-available);
		
		memcpy(mBuffer+mSize*sizeof(JDFCh), buf, length*sizeof(JDFCh));
		mSize += length;
	}
	
	void CharBuffer::append(const CharBuffer& b)
	{
		append(b.bytes(),b.size());
	}
	
	void CharBuffer::append(const WString& s)
	{
		size_t available = mBufferSize - mSize;
		if (static_cast<int>(s.length()) > available)
			ensureCapacity(s.length()-available);
		
		memcpy(mBuffer+mSize*sizeof(JDFCh), s.data(), s.length()*sizeof(JDFCh));
		mSize += s.length();
	}
	
	void CharBuffer::append(JDFCh c)
	{
		size_t available = mBufferSize - mSize;
		if (!available)
			ensureCapacity(10);
		memcpy(mBuffer+mSize, &c, sizeof(JDFCh));
		mSize += 1;
	}
	
	JDFCh* CharBuffer::bytes() const 
	{
		return mBuffer;
	}
	
	size_t CharBuffer::size() const
	{
		return mSize;
	}
	
	void  CharBuffer::reset()
	{
		mSize = 0;
	}
	
	void CharBuffer::ensureCapacity(size_t length)
	{
		size_t allocSize = std::max(mBufferSize << 1, mBufferSize + length);
		
		JDFCh* pTmp=mBuffer;
		
		mBuffer = new JDFCh[allocSize];
		memcpy (mBuffer,pTmp,mBufferSize * sizeof (JDFCh)); // only copy the old data
		mBufferSize = allocSize;
		
		delete[]pTmp;
	}
	
} // namespace JDF
