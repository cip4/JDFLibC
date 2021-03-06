/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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

#include "Win32SocketImplInputStream.h"

#include "Win32SocketImpl.h"
#include "Win32SocketInit.h"

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

	Win32SocketImplInputStream::Win32SocketImplInputStream(Win32SocketImpl* socketImpl) :
mSocketImpl	(socketImpl)
{
}

Win32SocketImplInputStream::~Win32SocketImplInputStream()
{
}

size_t Win32SocketImplInputStream::available()
{
	return mSocketImpl->available();
}

void Win32SocketImplInputStream::close()
{
	mSocketImpl->close();
}

bool Win32SocketImplInputStream::markSupported()
{
	return false;
}

int Win32SocketImplInputStream::read()
{
	char b;

	int nrBytesReceived;

	mSocketImpl->doWait(mSocketImpl->getOption(SocketOptions::SO_TIMEOUT_OPT), Win32SocketImpl::WAITFORREAD);

	if (available() == 0)
		return -1;

	if ((nrBytesReceived = SocketProxy::sysRecv(mSocketImpl->getFileDescriptor(),&b,1,0)) == SOCKET_ERROR)
		throw IOException("Failed to read from socket");

	if (nrBytesReceived == 0)
		return -1;

	return b;
}

ssize_t Win32SocketImplInputStream::read(char* b, size_t blen)
{
	size_t nrBytesReceived = 0;

	// wait for stuff 
	mSocketImpl->doWait(mSocketImpl->getOption(SocketOptions::SO_TIMEOUT_OPT), Win32SocketImpl::WAITFORREAD);

	// check if bytes are available
	// if socket is closed available == 0
	if (available() == 0)
		return -1;




	// only read if blen not zero and bytes are available
	if (blen)
	{
		if ((nrBytesReceived = SocketProxy::sysRecv(mSocketImpl->getFileDescriptor(),b,blen,0)) == SOCKET_ERROR)
			throw IOException("Failed to read from socket");

		if (nrBytesReceived == 0)
			return -1;
	}
	return nrBytesReceived;
}

ssize_t Win32SocketImplInputStream::read(char* b, size_t blen, size_t offset, size_t len)
{
	return read(b+offset,len);
}

void Win32SocketImplInputStream::reset()
{
}

size_t Win32SocketImplInputStream::skip(size_t n)
{
	return 0;
}

} // namespace JDF


/* end of file */
