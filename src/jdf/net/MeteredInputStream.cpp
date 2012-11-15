/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2012The International Cooperation for the Integration of 
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

#include "jdf/net/MeteredInputStream.h"
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

MeteredInputStream::MeteredInputStream(InputStream* in,ProgressEntry* pe) : FilterInputStream(*in),
			te(pe)
{
	mExpected = pe->mNeeded;
	mCount    = 0;
	// 090715 rp - if we expect nothing, we are immediately closed
	mClosed   = mExpected<=0;
	bKillInStream=true;
}

MeteredInputStream::~MeteredInputStream() 
{
	delete te;
}

size_t  MeteredInputStream::available()
{
	return mClosed?0:mIn->available();

}

void MeteredInputStream::close()
{
	if (mClosed)
		return;

	mClosed = true;
}

void MeteredInputStream::mark(size_t readlimit)
{
	if (mClosed)
		return;
	FilterInputStream::mark(readlimit);
}

bool MeteredInputStream::markSupported()
{
	if (mClosed)
		return false;

	return FilterInputStream::markSupported();
}

int  MeteredInputStream::read()
{
	if (mClosed)
		return -1;

	int c = mIn->read();
	if (c != -1)
		justRead(1);
	else 
		close();

	return c;
}

ssize_t  MeteredInputStream::read(char* b, size_t blen)
{
	return read(b, blen,0,blen);
}

ssize_t  MeteredInputStream::read(char* b, size_t blen, size_t off, size_t len)
{
	if (mClosed)
		return -1;

	size_t n = mIn->read(b,blen,off,len);
	justRead(n);
	return n;
}

void MeteredInputStream::reset()
{
	if (mClosed)
		return;

	FilterInputStream::reset();
}

size_t MeteredInputStream::skip(size_t n)
{
	if (mClosed)
		return 0;

	// just skip min(n,num_bytes_left

	size_t min =(n> mExpected-mCount) ? mExpected-mCount : n;
	n = mIn->skip(min);
	return n;
}

void MeteredInputStream::justRead(size_t n)
{
	if (n == -1)
	{
		close();
		return;
	}
	mCount += n;
	if (mCount >= mExpected)
		close();
}

} // namespace JDF
