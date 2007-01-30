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
#include "Socket.h"

#include "SocketImplFactory.h"
#include "SocketImpl.h"

#include <jdf/util/RegisterCleanup.h>
#include <jdf/lang/Exception.h>

#include <xercesc/util/PlatformUtils.hpp>


XERCES_CPP_NAMESPACE_USE

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

	SocketImplFactory* Socket::mSocketImplFactory = NULL;

	static Mutex* socketMutex = 0;
	static RegisterCleanup socketMutexCleanup;

	static Mutex& gSocketMutex()
	{
		if (!socketMutex)
		{
			Mutex* tmpMutex = new Mutex;
			if (XMLPlatformUtils::compareAndSwap((void**)&socketMutex, tmpMutex, 0))
			{
				// Some other thread beat us to it, so let's clean up ours.
				delete tmpMutex;
			}
			else
			{
				// This is the real mutex.  Register it for deletion at Termination.
				socketMutexCleanup.registerCleanup(Socket::reinitSocketMutex);
			}

		}
		return *socketMutex;
	}

	Socket::Socket()
	{
		Synchronized sync(gSocketMutex());

		mSocketImpl = mSocketImplFactory->CreateSocketImpl();
	}

	Socket::Socket(SocketImpl* impl)
	{
		mSocketImpl = impl;
	}

	Socket::~Socket()
	{
		try
		{
			close();
		}
		catch (IOException&)
		{
		}

		delete mSocketImpl;
	}

	void Socket::connect(const WString& host, int port)
	{
		if(port < 0 || port > 65535)
			throw IllegalArgumentException("Port value out of range");

		Synchronized sync(mCriticalSection);

		mSocketImpl->create(true);
		mSocketImpl->connect(host,port);
	}

	void Socket::connect(const InetAddress& address, int port)
	{
		Synchronized sync(mCriticalSection);

		mSocketImpl->create(true);
		mSocketImpl->connect(address,port);
	}

	void Socket::connect(const WString& host, int port, const InetAddress& itf, int localPort)
	{
		if(port < 0 || port > 65535)
			throw IllegalArgumentException("Port value out of range");

		if(localPort < 0 || localPort > 65535)
			throw IllegalArgumentException("Port value out of range");

		Synchronized sync(mCriticalSection);

		mSocketImpl->create(true);
		mSocketImpl->bind(itf,localPort);
		mSocketImpl->connect(host,port);
	}

	void Socket::connect(const InetAddress& host, int port, const InetAddress& itf, int localPort)
	{
		Synchronized sync(mCriticalSection);

		mSocketImpl->create(true);
		mSocketImpl->bind(itf,localPort);
		mSocketImpl->connect(host,port);
	}

	void Socket::close()
	{
		mSocketImpl->close();
	}

	InetAddress Socket::getInetAddress()
	{
		return mSocketImpl->getInetAddress();
	}

	InetAddress Socket::getLocalAddress()
	{
		return mSocketImpl->getOption(SocketOptions::SO_BINDADDR_OPT);
	}

	int	Socket::getLocalPort()
	{
		return mSocketImpl->getLocalPort();
	}

	int	Socket::getPort()
	{
		return mSocketImpl->getPort();
	}

	WString Socket::toString()
	{
		return "Socket" + mSocketImpl->toString();
	}

	bool Socket::operator !() 
	{
		Synchronized sync(mCriticalSection);

		return !((bool) mSocketImpl->getOption(SocketOptions::SO_ERROR_OPT));
	}

	Socket::operator bool() 
	{
		Synchronized sync(mCriticalSection);

		return mSocketImpl->getOption(SocketOptions::SO_ERROR_OPT);
	}

	void Socket::setSoTimeout(int timeout)
	{
		Synchronized sync(mCriticalSection);

		if (timeout < 0) 
			throw IllegalArgumentException("SocketTimeout is negative");

		mSocketImpl->setOption(SocketOptions::SO_TIMEOUT_OPT,timeout);
	}

	int Socket::getSoTimeout()
	{
		Synchronized sync(mCriticalSection);

		return mSocketImpl->getOption(SocketOptions::SO_TIMEOUT_OPT);
	}

	void Socket::setSoLinger(bool on, int linger)
	{
		Synchronized sync(mCriticalSection);

		if (linger < 0) 
			throw IllegalArgumentException("linger value is negative");

		if (on == false)
			// disable linger
			mSocketImpl->setOption(SocketOptions::SO_LINGER_OPT,false);
		else
			// enable linger with the sepecified linger time
			mSocketImpl->setOption(SocketOptions::SO_LINGER_OPT,linger);
	}

	int Socket::getSoLinger()
	{
		Synchronized sync(mCriticalSection);

		SocketOption opt = mSocketImpl->getOption(SocketOptions::SO_LINGER_OPT);

		if (opt.getValueType() == SocketOption::BOOLEANVALUE)
		{
			if ((bool)opt == false) return -1;
			//else  we shouldn't come here
		}
		return (int) opt; // assume int value (timeout)
	}

	int Socket::getReceiveBufferSize()
	{
		Synchronized sync(mCriticalSection);

		return mSocketImpl->getOption(SocketOptions::SO_RCVBUF_OPT);
	}

	void Socket::setReceiveBufferSize(int size)
	{
		Synchronized sync(mCriticalSection);

		if (size <= 0)
			throw IllegalArgumentException("ReceiveBufferSize is 0 or negative");

		mSocketImpl->setOption(SocketOptions::SO_RCVBUF_OPT,size);
	}

	int Socket::getSendBufferSize()
	{
		Synchronized sync(mCriticalSection);

		return mSocketImpl->getOption(SocketOptions::SO_SNDBUF_OPT);
	}

	void Socket::setSendBufferSize(int size)
	{
		Synchronized sync(mCriticalSection);

		if (size <= 0)
			throw IllegalArgumentException("SendBufferSize is 0 or negative");

		mSocketImpl->setOption(SocketOptions::SO_SNDBUF_OPT,size);
	}

	bool Socket::getTcpNoDelay()
	{
		Synchronized sync(mCriticalSection);

		return mSocketImpl->getOption(SocketOptions::TCPNODELAY_OPT);
	}

	void Socket::setTcpNoDelay(bool on)
	{
		Synchronized sync(mCriticalSection);

		mSocketImpl->setOption(SocketOptions::TCPNODELAY_OPT, on);
	}

	void Socket::setSocketImplFactory(SocketImplFactory* fac)
	{
		Synchronized sync(gSocketMutex());

		delete mSocketImplFactory;
		mSocketImplFactory  = fac;
	}

	void Socket::terminate()
	{
		Synchronized sync(gSocketMutex());

		if (mSocketImplFactory){
			delete mSocketImplFactory;
			mSocketImplFactory=0;
		}
	}

	InputStream& Socket::getInputStream()
	{
		Synchronized sync(mCriticalSection);

		return mSocketImpl->getInputStream();
	}

	OutputStream& Socket::getOutputStream()
	{
		Synchronized sync(mCriticalSection);

		return mSocketImpl->getOutputStream();
	}

	void Socket::reinitSocketMutex()
	{
		delete socketMutex;
		socketMutex = 0;
	}

} // namespace JDF

/* end of file */
