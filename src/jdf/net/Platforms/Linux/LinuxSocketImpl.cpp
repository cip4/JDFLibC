/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2004 The International Cooperation for the Integration of 
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
 * copyright (c) 2004, Heidelberger Druckmaschinen AG 
 * copyright (c) 2004, Agfa-Gevaert N.V. 
 *  
 * For more information on The International Cooperation for the 
 * Integration of Processes in  Prepress, Press and Postpress , please see
 * <http://www.cip4.org/>.
 *  
 * 
 */
/******************************************************************************
 *              Copyright 2004 Heidelberger Druckmaschinen AG                 *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *   without the prior written consent of Heidelberger Druckmaschinen AG      *
 *                                                                            *
 ******************************************************************************/

/******************************************************************************
 *  Includes
 ******************************************************************************/ 

#include <netinet/tcp.h>

#include <jdf/lang/Janitor.h>
#include <jdf/net/SocketOptions.h>

#include <jdf/net/Platforms/Linux/LinuxSocketImplInputStream.h>
#include <jdf/net/Platforms/Linux/LinuxSocketImplOutputStream.h>
#include <jdf/net/Platforms/Linux/LinuxSocketInit.h>

#include <jdf/net/Platforms/Linux/LinuxSocketImpl.h>


namespace JDF
{

/******************************************************************************
 *  Implementation
 ******************************************************************************/

LinuxSocketImpl::LinuxSocketImpl() 
    : m_bSocketTimeoutEnabled(false),
      m_pInputStream         (NULL),
      m_iSocketTimeout       (0),
      m_pOutputStream        (NULL)       
{
	// this has to be fixed in SocketImpl
    mPort          = 0;
	mLocalPort     = 0;
	fd			   = INVALID_SOCKET;

    m_pInputStream  = new LinuxSocketImplInputStream(this);
    m_pOutputStream = new LinuxSocketImplOutputStream(this);
}

LinuxSocketImpl::~LinuxSocketImpl()
{
    delete m_pInputStream;  m_pInputStream  = NULL;
    delete m_pOutputStream; m_pOutputStream = NULL;
}

// use 0x00000000 as host for INADDR_ANY
// set port to zero for any port


void LinuxSocketImpl::bind(const InetAddress& host, int port)
{
    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));

    ArrayJanitor<char> hostBytes = host.getHostAddress().getBytes();

    servAddr.sin_family             = AF_INET;
    servAddr.sin_port               = SocketProxy::sysHostToNetworkShort(port);
    servAddr.sin_addr.s_addr        = SocketProxy::sysInetAddr(hostBytes.get());

    if(SocketProxy::sysBind(fd, (const struct sockaddr *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
    {
        throw BindException("Bind on socket failed");
    }

    if (mInetAddress.getHostAddress() == "0.0.0.0")
    {
        mInetAddress = getOption(SocketOptions::SO_BINDADDR_OPT);
    }
    else
        mInetAddress = host;

    if (port == 0)
    {
        sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr));
        int nSockAddrLen = sizeof(sockAddr);
        int result = SocketProxy::sysGetSockName(fd,(sockaddr*)&sockAddr,&nSockAddrLen);
        if (result==0)
        {
            mLocalPort = SocketProxy::sysNetworkToHostShort(sockAddr.sin_port);
        }
    }
    else
        mLocalPort = port;
}


void LinuxSocketImpl::create(bool bStream)
{
    if (bStream)
        fd = SocketProxy::sysSocket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    else
        fd = SocketProxy::sysSocket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (fd == INVALID_SOCKET) 
        throw SocketException("Failed to create socket");
}

void LinuxSocketImpl::connect(const WString& host, int port)
{
    mInetAddress = InetAddress::getByName(host); 

    connect(mInetAddress,port); 
}

void LinuxSocketImpl::connect(const InetAddress& addr, int port)
{
    mInetAddress = addr;

    struct sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));

    ArrayJanitor<char> hostBytes = mInetAddress.getHostAddress().getBytes();

    servAddr.sin_family      = AF_INET;
    servAddr.sin_port        = SocketProxy::sysHostToNetworkShort((u_short)port);
    servAddr.sin_addr.s_addr = SocketProxy::sysInetAddr(hostBytes.get());

    if(SocketProxy::sysConnect(fd, (const struct sockaddr *)&servAddr, sizeof(servAddr)) == SOCKET_ERROR)
    {
        int err = SocketProxy::sysWSAGetLastError();
        
        if (err == EHOSTUNREACH  || err == ENETUNREACH)
            throw NoRouteToHostException("There is no route to the specified host");
        if (err == ETIMEDOUT)
            throw NoRouteToHostException("Host failed to respond on connection attempt");
        else
            throw SocketException("Failed to connect to host");
    }

    mPort = port;

    // for unbound sockets find out the local port
    if (mLocalPort == 0)
    {
        sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr));
        int nSockAddrLen = sizeof(sockAddr);
        int result = SocketProxy::sysGetSockName(fd,(sockaddr*)&sockAddr,&nSockAddrLen);
        if (result==0)
        {
            mLocalPort = SocketProxy::sysNetworkToHostShort(sockAddr.sin_port);
        }
    }
    // mark socket as non-blocking
    unsigned long nonBlocking = 1;
    SocketProxy::sysIoctlSocket(fd, FIONBIO, &nonBlocking);
//  std::cout<<"void LinuxSocketImpl::connect(const InetAddress& addr, int port) leaved."<<std::endl;
}

void LinuxSocketImpl::close()
{
    if (fd != INVALID_SOCKET)
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

void LinuxSocketImpl::listen(int count)
{
    // mark socket as non-blocking
    unsigned long nonBlocking = 1;
    SocketProxy::sysIoctlSocket(fd, FIONBIO, &nonBlocking);

    if (SocketProxy::sysListen(fd,count) == SOCKET_ERROR)
        throw SocketException("Listen on socket failed");
}

SocketImpl* LinuxSocketImpl::accept()
{
    LinuxSocketImpl* s = new LinuxSocketImpl();
    Janitor<LinuxSocketImpl> socketImplJanitor(s);

    // Wait for connection attempt from client

    struct sockaddr_in clientAddr;
    int clientLen = sizeof(clientAddr);

    // wait for accept call 

    doWait(m_iSocketTimeout, WAITFORREAD);

    s->fd  = SocketProxy::sysAccept(fd,(struct sockaddr *) &clientAddr,&clientLen);
    if (s->fd == INVALID_SOCKET) 
    {
        throw SocketException("Accept on socket failed");
    }

    s->mLocalPort      = mLocalPort;

    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));
    int nSockAddrLen = sizeof(sockAddr);

    int result = SocketProxy::sysGetPeerName(s->fd,(sockaddr*)&sockAddr,&nSockAddrLen);
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

int LinuxSocketImpl::available()
{
    unsigned long nrBytesAvailable=0;

    if(SocketProxy::sysIoctlSocket( fd,  FIONREAD, &nrBytesAvailable) == SOCKET_ERROR)
        throw IOException("Failed to read Bytes available on socket");

    return nrBytesAvailable;
}
 
InputStream& LinuxSocketImpl::getInputStream()
{
    if (fd == INVALID_SOCKET)
        throw SocketException("Invalid Socket");

    return *m_InputStream;
}

OutputStream& LinuxSocketImpl::getOutputStream()
{
    if (fd == INVALID_SOCKET)
        throw SocketException("Invalid Socket");

    return *m_pOutputStream;
}

void LinuxSocketImpl::doWait(int millis, SocketWaitCondition cond)
{
    int retval = SocketProxy::sysTimeout(fd,millis,cond);

    // timeout occurred
    if (retval == 0) 
        throw InterruptedIOException("Socket interrupt due to timeout event");

    // a socket error occurred
    if (retval == SOCKET_ERROR)
        throw SocketException("Wait on socket failed");
}

int LinuxSocketImpl::getFileDescriptor()
{
    return fd;
}

SocketOption LinuxSocketImpl::getOption(int optID)
{
    if (optID == SO_TIMEOUT_OPT) // timeout on send/recv
    {
        return (!m_bSocketTimeoutEnabled) ? SocketOption(0) : SocketOption(m_iSocketTimeout);
    }
    else
    if (optID == SO_LINGER_OPT) // linger on close option
    {
        // returns timeout value if enabled (l_onoff != 0)
        // if l_onoff == 0 returns timeout of 0
        struct linger l    = { 0, 0 };
        int           size = sizeof(l);

        if (getsockopt(fd, SOL_SOCKET, SO_LINGER, (char*) &l, &size) == SOCKET_ERROR)
            throw SocketException("Failed to get linger on socket");

        return ((l.l_onoff == 0) ? SocketOption((bool) false) : SocketOption((int) l.l_linger));
    }
    else
    if (optID == SO_ERROR_OPT)
    {
        int so_error = 0;
        int size     = sizeof(so_error);

        if (getsockopt(fd, SOL_SOCKET, SO_ERROR, (char*) &so_error, &size) == SOCKET_ERROR)
            return SocketOption(false);
        
        return ((so_error) ? SocketOption(false) : SocketOption(true));
    }
    else
    if (optID == SO_BINDADDR_OPT)
    {
        sockaddr_in sockAddr;
        memset(&sockAddr, 0, sizeof(sockAddr));
        
        int size = sizeof(sockAddr);

        if (SocketProxy::sysGetSockName(fd, (sockaddr*) &sockAddr, &size) == SOCKET_ERROR)
            throw SocketException("Failed to get Bind Address");

        char*       tmp          = SocketProxy::sysInetNtoa(sockAddr.sin_addr);
        InetAddress localAddress = InetAddress::getByName(WString(tmp));

        return SocketOption(localAddress);
    }
    else
    if (optID == SO_RCVBUF_OPT)
    {
        int bufferSize = 0;
        int size       = sizeof(bufferSize);

        if (getsockopt(fd, SOL_SOCKET, SO_RCVBUF, (char*) &bufferSize, &size) == SOCKET_ERROR)
            throw SocketException("Failed to get Socket ReceiveBufferSize");

        return SocketOption(bufferSize);
    }
    else
    if (optID == SO_SNDBUF_OPT)
    {
        int bufferSize = 0;
        int size       = sizeof(bufferSize);

        if (getsockopt(fd, SOL_SOCKET, SO_SNDBUF,(char *)&bufferSize, &size) == SOCKET_ERROR)
            throw SocketException("Failed to get Socket SendBufferSize");

        return SocketOption(bufferSize);
    }
    else
    if (optID == SO_REUSEADDR_OPT)
    {
        bool reuseAddr = false;
        int  size      = sizeof(reuseAddr);

        if (getsockopt(fd, SOL_SOCKET, SO_REUSEADDR ,(char *)&reuseAddr, &size) == SOCKET_ERROR)
            throw SocketException("Failed to get Socket ReuseAddress");

        return ((reuseAddr == true) ? SocketOption(true) : SocketOption(false));
    }
    else
    if (optID == TCPNODELAY_OPT)
    {
        bool tcpnodelay = false;
        int  size       = sizeof(tcpnodelay);

        if (getsockopt(fd, IPPROTO_TCP, TCP_NODELAY ,(char *)&tcpnodelay,&size) == SOCKET_ERROR)
            throw SocketException("Failed to get Socket TCPNoDelay");

        return ((tcpnodelay == true) ? SocketOption(true) : SocketOption(false));
    }
    
    return SocketOption(false);
}


void LinuxSocketImpl::setOption(int optID, const SocketOption& value)
{
    if (optID == SO_TIMEOUT_OPT)
    {
        if (value.getValueType() == SocketOption::BOOLEANVALUE)
        {
            m_bSocketTimeoutEnabled = (bool) value;
        }
        else
        {
            m_iSocketTimeout         = (int) value;
            m_bSocketTimeoutEnabled  = true;
        }
    }
    else
    if (optID == SO_LINGER_OPT)
    {
        // enable/disable LINGER ?
        if (value.getValueType() == SocketOption::BOOLEANVALUE)
        {
            bool          dontlinger = (((bool) value == true) ? false : true);
            struct linger l          = { 0, 0 };
            int           size       = sizeof(l);
            
            if (getsockopt(fd, SOL_SOCKET,  SO_LINGER, (char*) &l, &size) == SOCKET_ERROR)
                throw SocketException("Failed to get linger on socket");

            l.l_onoff = (int) dontlinger;

            if (setsockopt(fd, SOL_SOCKET, SO_LINGER, (const char*) &l, sizeof(l)) == SOCKET_ERROR)
                throw SocketException("Failed to set linger on socket");
        }

        // enable linger with timeout
        if (value.getValueType() == SocketOption::INTEGERVALUE)
        {
            struct linger l = { 1, (int) value };

            if (setsockopt(fd, SOL_SOCKET, SO_LINGER, (const char*) &l, sizeof(l)) == SOCKET_ERROR)
                throw SocketException("Failed ton set linger on socket");
        }
    }
    else
    if (optID == SO_RCVBUF_OPT)
    {
        int bufferSize = (int) value;

        if (setsockopt(fd, SOL_SOCKET, SO_RCVBUF, (const char*) &bufferSize, sizeof(bufferSize)) == SOCKET_ERROR)
            throw SocketException("Failed to set Socket ReceiveBufferSize");
    }
    else
    if (optID == SO_SNDBUF_OPT)
    {
        int bufferSize = (int) value;

        if (setsockopt(fd, SOL_SOCKET, SO_SNDBUF, (const char*) &bufferSize, sizeof(bufferSize)) == SOCKET_ERROR)
            throw SocketException("Failed to set Socket SendBufferSize");
    }
    else
    if (optID == SO_REUSEADDR_OPT)
    {
        bool reuse = (((bool) value == true) ? true : false);

        if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char*) &reuse, sizeof(reuse)) == SOCKET_ERROR)
            throw SocketException("Failed to set Socket ReuseAddress");
    }
    else
    if (optID == TCPNODELAY_OPT)
    {
        bool tcpnodelay = (((bool) value == true) ? true : false);

        if (setsockopt(fd, IPPROTO_TCP,  TCP_NODELAY, (char *) &tcpnodelay, 1/*sizeof(tcpnodelay)*/) == SOCKET_ERROR)
        {
            switch (errno)
            {
                case EBADF       : printf("EBADF\n");       break;
                case ENOTSOCK    : printf("ENOTSOCK\n");    break;
                case ENOPROTOOPT : printf("ENOPROTOOPT\n"); break;
                case EFAULT      : printf("EFAULT\n");      break;
            }

            throw SocketException("Failed to set Socket TCPNoDelay");
        }
    }
    else
    if (optID == SO_IONBIO_OPT)
    {
        // mark socket as non-blocking
        unsigned long nonBlocking = (((bool) value == true) ? 1 : 0);

        SocketProxy::sysIoctlSocket(fd, FIONBIO, &nonBlocking);
    }
}

} // namespace JDF

/* end of file */
