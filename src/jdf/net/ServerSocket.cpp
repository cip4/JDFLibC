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
/**
* ServerSocket.cpp
*
* @author Frank Barenthien
*
* Copyright (C) 2003 Heidelberger Druckmaschinen AG. All Rights Reserved.
*/

#include <assert.h>
#include <xercesc/util/PlatformUtils.hpp>
#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/lang/Synchronized.h>
#include <jdf/lang/Exception.h>
#include <jdf/net/Socket.h>
#include <jdf/net/SocketImplFactory.h>
#include <jdf/net/SocketImpl.h>
#include <jdf/util/RegisterCleanup.h>

#include "ServerSocket.h"

XERCES_CPP_NAMESPACE_USE

namespace JDF
{

	SocketImplFactory* ServerSocket::s_pFactory = NULL;

	static Mutex*          serverSocketMutex        = NULL;
	static RegisterCleanup serverSocketMutexCleanup;

	static Mutex& gServerSocketMutex()
	{
		if (!serverSocketMutex)
		{
			Mutex* tmpMutex = new Mutex;
			if (XMLPlatformUtils::compareAndSwap((void**)&serverSocketMutex, tmpMutex, 0))
			{
				// Some other thread beat us to it, so let's clean up ours.
				delete tmpMutex;
			}
			else
			{
				// This is the real mutex.  Register it for deletion at Termination.
				serverSocketMutexCleanup.registerCleanup(Socket::reinitSocketMutex);
			}

		}
		return *serverSocketMutex;
	}

	void ServerSocket::setSocketFactory(JDF::SocketImplFactory* pFactory)
	{
		Synchronized sync(gServerSocketMutex());

		if (s_pFactory != NULL)
			throw JDF::SocketException("factory already defined");

		s_pFactory = pFactory;
	}


	ServerSocket::ServerSocket()
		: m_bBound  (false),
		m_bClosed (false),
		m_bCreated(false),
		m_pImpl   (NULL)
	{
		setImpl();
	}


	ServerSocket::ServerSocket(const InetAddress& bindAddr, int port, int backlog)
		: m_bBound  (false),
		m_bClosed (false),
		m_bCreated(false),
		m_pImpl   (NULL)
	{
		setImpl();

		if ((port < 0) || (port > 0xFFFF))
			throw IllegalArgumentException("Port value out of range: " + port);

		if (backlog < 1)
			backlog = 50;

		try
		{
			bind(bindAddr, port, backlog);
		}
		catch (const IOException& ex)
		{
			close();
			throw ex;
		}
	}


	ServerSocket::~ServerSocket()
	{
		try
		{
			close();

			delete m_pImpl; m_pImpl = NULL;
		}
		catch (...)
		{
		}
	}


	void ServerSocket::close()
	{
		Synchronized sync(m_cs);

		if (m_bClosed)
			return;

		if (m_bCreated)
			m_pImpl->close();

		m_bClosed = true;
	}


	Socket* ServerSocket::accept()
	{
		return new Socket(getImpl()->accept());
	}


	void ServerSocket::bind(const InetAddress& bindAddr, int port, int backlog)
	{
		if (isClosed())
			throw JDF::SocketException("Socket is closed");

		if (isBound())
			throw JDF::SocketException("Already bound");

		if (backlog < 1)
			backlog = 50;

		try
		{
			getImpl()->bind(bindAddr, port);
			getImpl()->listen(backlog);

			m_bBound = true;
		}
		catch (const IOException& ex)
		{
			m_bBound = false;
			throw ex;
		}
	}


	SocketImpl* ServerSocket::getImpl()
	{
		if (!m_bCreated)
		{
			setImpl();

			try 
			{
				m_pImpl->create(true);
				m_bCreated = true;
			} 
			catch (const IOException& ex)
			{
				throw JDF::SocketException(ex.getMessage());
			}
		}

		return m_pImpl;
	}


	void ServerSocket::setImpl()
	{
		assert(s_pFactory != NULL);

		if (m_pImpl != NULL)
		{
			delete m_pImpl; m_pImpl = NULL;
		}

		m_pImpl = s_pFactory->CreateSocketImpl();
	}


	bool ServerSocket::isBound()
	{
		return m_bBound;
	}


	bool ServerSocket::isClosed()
	{
		Synchronized sync(m_cs);

		return m_bClosed;
	}


	void ServerSocket::terminate()
	{
		Synchronized sync(gServerSocketMutex());

		if (s_pFactory)
		{
			delete s_pFactory; s_pFactory = NULL;
		}
	}

	void ServerSocket::setSoTimeout(int timeout)
	{
		Synchronized sync(m_cs);

		if (timeout < 0) 
			throw IllegalArgumentException("SocketTimeout is negative");

		m_pImpl->setOption(SocketOptions::SO_TIMEOUT_OPT,timeout);
	}

	int ServerSocket::getSoTimeout()
	{
		Synchronized sync(m_cs);

		return m_pImpl->getOption(SocketOptions::SO_TIMEOUT_OPT);
	}

} //namespace JDF

/* end of file
******************************************************************************/
