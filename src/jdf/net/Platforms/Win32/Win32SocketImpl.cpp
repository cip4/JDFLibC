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

#include "Win32SocketImpl.h"

#include "Win32SocketImplInputStream.h"
#include "Win32SocketImplOutputStream.h"

#include "Win32SocketInit.h"

#include <jdf/lang/Janitor.h>
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


	Win32SocketImpl::Win32SocketImpl() 
	{
		mPort          = 0;
		mLocalPort     = 0;
		fd			   = INVALID_SOCKET;
		mSocketTimeout = 0;
		mSocketTimeoutEnabled = false;

		mInputStream  = new Win32SocketImplInputStream(this);
		mOutputStream = new Win32SocketImplOutputStream(this);
	}

	Win32SocketImpl::~Win32SocketImpl()
	{
		delete mInputStream;
		delete mOutputStream;
	}

	// use 0x00000000 as host for INADDR_ANY
	// set port to zero for any port


	void Win32SocketImpl::bind(const InetAddress& host, int port)
	{
		struct sockaddr_in servAddr;
		memset(&servAddr, 0, sizeof(servAddr));

		char* hostBytes = host.getHostAddress().getBytes();
		ArrayJanitor<char> hostBytesJanitor(hostBytes);

		servAddr.sin_family				= AF_INET;
		servAddr.sin_port				= SocketProxy::sysHostToNetworkShort(port);
		servAddr.sin_addr.s_addr 		= SocketProxy::sysInetAddr(hostBytes);

		if(SocketProxy::sysBind(fd, (const struct sockaddr *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		{
			throw BindException("Bind on socket failed");
		}

		if (mInetAddress.getHostAddress() == JDFStrL("0.0.0.0"))
		{
			mInetAddress = getOption(SocketOptions::SO_BINDADDR_OPT);
		}
		else
			mInetAddress = host;

		if (port == 0)
		{
			SOCKADDR_IN sockAddr;
			memset(&sockAddr, 0, sizeof(sockAddr));
			int nSockAddrLen = sizeof(sockAddr);
			int result = SocketProxy::sysGetSockName(fd,(SOCKADDR*)&sockAddr,&nSockAddrLen);
			if (result==0)
			{
				mLocalPort = SocketProxy::sysNetworkToHostShort(sockAddr.sin_port);
			}
		}
		else
			mLocalPort = port;
	}


	void Win32SocketImpl::create(bool stream)
	{
		if (stream == true)
			fd = SocketProxy::sysSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		else
			fd = SocketProxy::sysSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

		if (fd == INVALID_SOCKET) 
			throw SocketException("Failed to create socket");
	}

	void Win32SocketImpl::connect(const WString& host, int port)
	{
		mInetAddress = InetAddress::getByName(host); 
		connect(mInetAddress,port);	
	}

	void Win32SocketImpl::connect(const InetAddress& addr, int port)
	{
		mInetAddress = addr;

		struct sockaddr_in servAddr;
		memset(&servAddr, 0, sizeof(servAddr));

		char* hostBytes = mInetAddress.getHostAddress().getBytes();
		ArrayJanitor<char> hostBytesJanitor(hostBytes);

		servAddr.sin_family		 = AF_INET;
		servAddr.sin_port		 = SocketProxy::sysHostToNetworkShort((u_short)port);
		servAddr.sin_addr.s_addr = SocketProxy::sysInetAddr(hostBytes);

		if(SocketProxy::sysConnect(fd, (const struct sockaddr *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
		{
			int err = SocketProxy::sysWSAGetLastError();
			if (err == WSAEHOSTUNREACH  || err == WSAENETUNREACH)
				throw NoRouteToHostException("There is no route to the specified host");
			if (err == WSAETIMEDOUT)
				throw NoRouteToHostException("Host failed to respond on connection attempt");
			else
				throw SocketException("Failed to connect to host");
		}

		mPort = port;

		// for unbound sockets find out the local port 
		if (mLocalPort == 0)
		{
			SOCKADDR_IN sockAddr;
			memset(&sockAddr, 0, sizeof(sockAddr));
			int nSockAddrLen = sizeof(sockAddr);
			int result = SocketProxy::sysGetSockName(fd,(SOCKADDR*)&sockAddr,&nSockAddrLen);
			if (result==0)
			{
				mLocalPort = SocketProxy::sysNetworkToHostShort(sockAddr.sin_port);
			}
		}
		// mark socket as non-blocking
		unsigned long nonBlocking = 1;
		SocketProxy::sysIoctlSocket(fd, FIONBIO, &nonBlocking);

	}

	void Win32SocketImpl::close()
	{
		if(fd != INVALID_SOCKET)
		{
			// mark socket as blocking
			unsigned long nonBlocking = 0;
			SocketProxy::sysIoctlSocket(fd, FIONBIO, &nonBlocking);

			if (SocketProxy::sysSocketClose(fd) == SOCKET_ERROR)
			{
				fd = INVALID_SOCKET;
				throw SocketException("Failed to close socket");
			}
		}
		fd = INVALID_SOCKET;
	}

	void Win32SocketImpl::listen(int count)
	{
		// mark socket as non-blocking
		unsigned long nonBlocking = 1;
		SocketProxy::sysIoctlSocket(fd, FIONBIO, &nonBlocking);

		if (SocketProxy::sysListen(fd,count) == SOCKET_ERROR)
			throw SocketException("Listen on socket failed");
	}

	SocketImpl* Win32SocketImpl::accept()
	{
		Win32SocketImpl* s = new Win32SocketImpl();
		Janitor<Win32SocketImpl> socketImplJanitor(s);

		// Wait for connection attempt from client

		struct sockaddr_in clientAddr;
		int clientLen = sizeof(clientAddr);

		// wait for accept call 

		doWait(mSocketTimeout,WAITFORREAD);

		s->fd  = SocketProxy::sysAccept(fd,(struct sockaddr *) &clientAddr,&clientLen);
		if (s->fd == INVALID_SOCKET) 
		{
			throw SocketException("Accept on socket failed");
		}

		s->mLocalPort      = mLocalPort;

		SOCKADDR_IN sockAddr;
		memset(&sockAddr, 0, sizeof(sockAddr));
		int nSockAddrLen = sizeof(sockAddr);

		int result = SocketProxy::sysGetPeerName(s->fd,(SOCKADDR*)&sockAddr,&nSockAddrLen);
		if (result==0)
		{
			s->mPort =  SocketProxy::sysNetworkToHostShort(sockAddr.sin_port);
			char* tmp = SocketProxy::sysInetNtoa(sockAddr.sin_addr);
			s->mInetAddress = InetAddress::getByName(WString(tmp));
		}
		// mark socket as non-blocking
		unsigned long nonBlocking = 1;
		SocketProxy::sysIoctlSocket(fd, FIONBIO, &nonBlocking);
		socketImplJanitor.orphan();
		return s;
	}

	int Win32SocketImpl::available()
	{
		unsigned long nrBytesAvailable=0;

		if(SocketProxy::sysIoctlSocket( fd,  FIONREAD, &nrBytesAvailable) == SOCKET_ERROR)
			throw IOException("Failed to read Bytes available on socket");

		return nrBytesAvailable;
	}

	InputStream& Win32SocketImpl::getInputStream()
	{
		if (fd == INVALID_SOCKET)
			throw SocketException("Invalid Socket");

		return *mInputStream;
	}

	OutputStream& Win32SocketImpl::getOutputStream()
	{
		if (fd == INVALID_SOCKET)
			throw SocketException("Invalid Socket");

		return *mOutputStream;
	}

	void Win32SocketImpl::doWait(int millis, SocketWaitCondition cond)
	{
		int retval = SocketProxy::sysTimeout(fd,millis,cond);

		// timeout occurred
		if (retval == 0) 
			throw InterruptedIOException("Socket interrupt due to timeout event");

		// a socket error occurred
		if (retval == SOCKET_ERROR)
			throw SocketException("Wait on socket failed");
	}

	int	Win32SocketImpl::getFileDescriptor()
	{ 
		return fd; 
	}

	SocketOption Win32SocketImpl::getOption(int optID)
	{
		// timeout on send/recv
		if (optID ==  SO_TIMEOUT_OPT)
		{
			if (mSocketTimeoutEnabled == false)
				return SocketOption(0);
			else
				return SocketOption(mSocketTimeout);
		}

		// linger on close option
		else if (optID ==  SO_LINGER_OPT)
		{
			// returns timeout value if enabled (l_onoff != 0)
			// if l_onoff == 0 returns timeout of 0
			LINGER l = {0,0};

			int size = sizeof(l);
			if (getsockopt(fd, SOL_SOCKET, SO_LINGER,(char FAR*)&l,(int FAR*) &size) == SOCKET_ERROR)
			{
				throw SocketException("Failed to get linger on socket");
			}
			if (l.l_onoff == 0) 
				return SocketOption((bool)false);
			else
				return SocketOption((int)l.l_linger);
		}
		else if (optID == SO_ERROR_OPT)
		{
			int so_error;
			int size = sizeof(so_error);
			if (getsockopt(fd, SOL_SOCKET, SO_ERROR,(char FAR*)&so_error,(int FAR*) &size) == SOCKET_ERROR)
				return SocketOption(false);
			if (so_error)
				return SocketOption(false);
			else
				return SocketOption(true);
		}
		else if (optID == SO_BINDADDR_OPT)
		{
			SOCKADDR_IN sockAddr;
			memset(&sockAddr, 0, sizeof(sockAddr));
			int nSockAddrLen = sizeof(sockAddr);
			int result = SocketProxy::sysGetSockName(fd,(SOCKADDR*)&sockAddr,&nSockAddrLen);
			if (result==SOCKET_ERROR)
				throw SocketException("Failed to get Bind Address");
			else
			{
				char* tmp    = SocketProxy::sysInetNtoa(sockAddr.sin_addr);
				InetAddress localAddress = InetAddress::getByName(WString(tmp));
				return SocketOption(localAddress);
			}
		}
		else if (optID == SO_RCVBUF_OPT)
		{
			int bufferSize;
			int size = sizeof(bufferSize);
			if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF,(char FAR*)&bufferSize,(int FAR*) &size) == SOCKET_ERROR)
			{
				throw SocketException("Failed to get Socket ReceiveBufferSize");
			}
			return SocketOption(bufferSize);
		}
		else if (optID == SO_SNDBUF_OPT)
		{
			int bufferSize;
			int size = sizeof(bufferSize);
			if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF,(char FAR*)&bufferSize,(int FAR*) &size) == SOCKET_ERROR)
			{
				throw SocketException("Failed to get Socket SendBufferSize");
			}
			return SocketOption(bufferSize);
		}
		else if (optID == SO_REUSEADDR_OPT)
		{
			BOOL reuseAddr;
			int size = sizeof(reuseAddr);
			if (getsockopt(fd, SOL_SOCKET, SO_REUSEADDR ,(char FAR*)&reuseAddr,(int FAR*) &size) == SOCKET_ERROR)
			{
				throw SocketException("Failed to get Socket ReuseAddress");
			}
			if (reuseAddr == TRUE)
				return SocketOption(true);
			else
				return SocketOption(false);
		}
		else if (optID == TCPNODELAY_OPT)
		{
			BOOL tcpnodelay;
			int size = sizeof(tcpnodelay);
			if (getsockopt(fd, IPPROTO_TCP, TCP_NODELAY ,(char FAR*)&tcpnodelay,(int FAR*) &size) == SOCKET_ERROR)
			{
				throw SocketException("Failed to get Socket TCPNoDelay");
			}
			if (tcpnodelay == TRUE)
				return SocketOption(true);
			else
				return SocketOption(false);
		}

		return SocketOption(false);
	}

	void Win32SocketImpl::setOption(int optID, const SocketOption& value)
	{
		if (optID ==  SO_TIMEOUT_OPT)
		{
			if (value.getValueType() == SocketOption::BOOLEANVALUE)
			{
				mSocketTimeoutEnabled = (bool) value;
			}
			else
			{
				mSocketTimeout         = (int) value;
				mSocketTimeoutEnabled  = true;
			}
		}
		else if (optID == SO_LINGER_OPT)
		{
			// enable/disable LINGER ?
			if (value.getValueType() == SocketOption::BOOLEANVALUE)
			{
				BOOL dontlinger; 
				if ((bool)value == true) dontlinger = FALSE;
				else dontlinger = TRUE;
				if (setsockopt(fd, SOL_SOCKET, SO_DONTLINGER, (char*)&dontlinger, sizeof(dontlinger)) == SOCKET_ERROR) 
					throw SocketException("Failed to set linger on socket");
			}

			// enable linger with timeout
			if (value.getValueType() == SocketOption::INTEGERVALUE)
			{
				LINGER l = {1,(int) value};
				if (setsockopt(fd, SOL_SOCKET, SO_LINGER, (const char FAR*) &l,  sizeof(l)) == SOCKET_ERROR)
					throw SocketException("Failed ton set linger on socket");
			}
		}
		else if (optID == SO_RCVBUF_OPT)
		{
			int bufferSize = (int) value;
			if (setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char FAR*) &bufferSize,  sizeof(bufferSize)) == SOCKET_ERROR)
				throw SocketException("Failed to set Socket ReceiveBufferSize");
		}
		else if (optID == SO_SNDBUF_OPT)
		{
			int bufferSize = (int) value;
			if (setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (const char FAR*) &bufferSize,  sizeof(bufferSize)) == SOCKET_ERROR)
				throw SocketException("Failed to set Socket SendBufferSize");
		}
		else if (optID == SO_REUSEADDR_OPT)
		{
			BOOL reuse; 
			if ((bool)value == true) reuse = TRUE;
			else reuse = FALSE;
			if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char FAR*) &reuse,  sizeof(reuse)) == SOCKET_ERROR)
				throw SocketException("Failed to set Socket ReuseAddress");
		}
		else if (optID == TCPNODELAY_OPT)
		{
			BOOL tcpnodelay; 
			if ((bool)value == true) tcpnodelay = TRUE;
			else tcpnodelay = FALSE;
			if (setsockopt(fd, IPPROTO_TCP,  TCP_NODELAY, (const char FAR*) &tcpnodelay,  sizeof(tcpnodelay)) == SOCKET_ERROR)
				throw SocketException("Failed to set Socket TCPNoDelay");
		}
		else if (optID == SO_IONBIO_OPT)
		{
			// mark socket as non-blocking
			unsigned long nonBlocking = 1;
			if ((bool)value == true) nonBlocking = 1;
			else nonBlocking = 0;
			SocketProxy::sysIoctlSocket(fd, FIONBIO, &nonBlocking);
		}
	}


} // namespace JDF

/* end of file */
