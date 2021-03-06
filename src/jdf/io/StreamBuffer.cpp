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

#include "StreamBuffer.h"

#include "InputStream.h"
#include "OutputStream.h"
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

StreamBuffer::StreamBuffer(InputStream& in, OutputStream& out) :
	mInputStream  (&in),
	mOutputStream (&out)
{
	setg(0, 0, 0);
	setp((char*)pbuf,(char*)pbuf+4096);
}

StreamBuffer::StreamBuffer(InputStream& in) :
	mInputStream  (&in),
	mOutputStream (NULL)
{
	setg(0, 0, 0);
	setp((char*)pbuf,(char*)pbuf+4096);
}

StreamBuffer::StreamBuffer(OutputStream& out) :
	mInputStream  (NULL),
	mOutputStream (&out)
{
	setg(0, 0, 0);
	setp((char*)pbuf,(char*)pbuf+4096);
}

int StreamBuffer::underflow(void)
{
	if (!mInputStream)
	{
		return EOF;
	}

	if (gptr() < egptr())
		return *gptr();

	size_t nrBytesReceived = 0;

	try
	{
		nrBytesReceived = mInputStream->read((char*)gbuf,4096);

		if (nrBytesReceived == -1)
			return EOF;
	} 
	catch (InterruptedIOException&)
	{
		// timeout 
		return 0;
	}
	catch (IOException&)
	{
		return EOF;
	}
	setg((char*)gbuf,(char*)gbuf,(char*)gbuf+nrBytesReceived);
	return *gbuf;
}

int StreamBuffer::overflow(int c)
{
	if (!mOutputStream)
	{
		return EOF; // flag error
	}
	try
	{
		mOutputStream->write(pbase(),pptr()-pbase());
	}
	catch (InterruptedIOException&)
	{
		return 0;
	}
	catch (IOException&)
	{
		return EOF; // an error occurred
	}
	setp((char*)pbuf,(char*)pbuf+4096);
	if(c != EOF) 
		return sputc(c);
	return 0;
}

int StreamBuffer::sync()
{
	setg(0, 0, 0);

	int res = overflow(EOF);
	
	// flush output stram

	try
	{
		mOutputStream->flush();
	}
	catch (InterruptedIOException&)
	{
		return 0;
	} 
	catch (IOException&)
	{
		return EOF;
	}
	return res;
}

} // namespace JDF
