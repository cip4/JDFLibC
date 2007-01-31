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

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/Exception.h>

#include <jdf/lang/ByteBuffer.h>

#include <jdf/io/ByteArrayOutputStream.h>


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

ByteArrayOutputStream::ByteArrayOutputStream()
{
	mCount   = 0;
	mLength = 32;
	mBuf    = new ByteBuffer(mLength);
	mClosed = false;
}

ByteArrayOutputStream::ByteArrayOutputStream(unsigned int size)
{
	mCount   = 0;
	mLength = size;
	mClosed = false;

	if (size == 0)
		throw IllegalArgumentException("ByteArrayOutputStream size is zero");

	mBuf    = new ByteBuffer(mLength);
}

ByteArrayOutputStream::~ByteArrayOutputStream()
{
	delete mBuf;
	mBuf=0;
}

void ByteArrayOutputStream::write(int b)
{
//	if (mClosed == true)
//	{
//		throw IOException("CharArrayOutputStream has been closed");
//	}

	mBuf->append(b);
	mCount++;
}

void ByteArrayOutputStream::write(const char* b, int blen)
{
	write(b,blen,0,blen);
}

void ByteArrayOutputStream::write(const char* b, int blen, int off, int len)
{
//	if (mClosed == true)
//	{
//		throw IOException("CharArrayOutputStream has been closed");
//	}

	if (blen < 0 || len < 0 || (off+len) < 0 || (off+len) > blen)
		throw IndexOutOfBoundsException("ByteArrayOutputStream::write one of the arguments in out of bounds");

	if (len==0)
		return;

	mBuf->append(b+off,len);
}

void ByteArrayOutputStream::writeTo(OutputStream& out)
{
	out.write(mBuf->bytes(),mBuf->size(), 0, mBuf->size());
}

WString ByteArrayOutputStream::toString()
{
	return WString(mBuf->bytes(),mBuf->size());
}



WString ByteArrayOutputStream::toString(const WString& enc)
{
	WString ret;
	if(enc==WString::utf8){
		ret.SetUTF8Bytes(mBuf->bytes(),mBuf->size());
	}else if (enc.empty()){
		ret=toString();
	}else{
		throw IllegalArgumentException(L"ByteArrayOutputStream::toString illegal encoding: "+enc);
	}

	return ret;
}


ByteBuffer* ByteArrayOutputStream::toByteArray()
{
	return new ByteBuffer(*mBuf);
}

int ByteArrayOutputStream::size()
{
	return mBuf->size();
}

void ByteArrayOutputStream::close()
{
	mClosed = true;
}

void ByteArrayOutputStream::reset()
{
	mBuf->reset();
}

} // namespace JDF


/* end of file */
