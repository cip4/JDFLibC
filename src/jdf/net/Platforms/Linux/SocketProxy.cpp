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
 *	Includes
 ******************************************************************************/

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <jdf/net/Platforms/Linux/SocketProxy.h>


namespace JDF
{

/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

int SocketProxy::sysListen(int fd, long count)
{
	return listen(fd, count);
}

int SocketProxy::sysConnect(int fd, const struct sockaddr* name, int namelen)
{
	return connect(fd, name, namelen);
}

int SocketProxy::sysAccept(int fd,  struct sockaddr* name, int* namelen)
{
	return accept(fd, name, namelen);
}

int SocketProxy::sysRecvFrom(int fd, char* buf, int nBytes, int flags, struct sockaddr* from, int* fromlen)
{
	return recvfrom(fd, buf, nBytes, flags, from,fromlen);
}

int SocketProxy::sysSendTo(int fd, char* buf, int len, int flags, struct sockaddr* to, int tolen)
{
	return sendto(fd, buf, len, flags, to, tolen);
}

int SocketProxy::sysSend(int fd, char* buf, int nBytes, int flags)
{
	return send(fd, buf, nBytes, flags);
}

int SocketProxy::sysRecv(int fd, char* buf, int nBytes, int flags)
{
	return recv(fd, buf, nBytes, flags);
}

unsigned short SocketProxy::sysNetworkToHostShort(unsigned short networkshort)
{
	return ntohs(networkshort);
}

unsigned long SocketProxy::sysHostToNetworkLong(unsigned long hostlong)
{
	return htonl(hostlong);

}

unsigned long SocketProxy::sysNetworkToHostLong(unsigned long networklong)
{
	return ntohl(networklong);
}

unsigned short SocketProxy::sysHostToNetworkShort(unsigned short hostshort)
{
	return htons(hostshort);
}

int SocketProxy::sysBind(int fd, const struct sockaddr* name, int namelen)
{
	return bind(fd, name, namelen);
}

struct hostent* SocketProxy::sysGetHostByName(const char* hostname)
{
	return gethostbyname(hostname);
}

int SocketProxy::sysGetHostName(char* hostname,int len)
{
	return gethostname(hostname, len);
}

struct hostent* SocketProxy::sysGetHostByAddress(char* hostname, int len, int type)
{
	return gethostbyaddr(hostname, len, type);
}

int SocketProxy::sysGetSockName(int fd, struct sockaddr* name, int* namelen)
{
	return getsockname(fd,name,namelen);
}

int SocketProxy::sysSocket(int domain, int type, int protocol)
{
	return socket(domain,type,protocol);
}

int SocketProxy::sysSocketClose(int fd)
{
    return  close (fd);
}

int SocketProxy::sysTimeout(int fd, int millis, int condition)
{
	fd_set set;
	FD_ZERO(&set);
	FD_SET(fd, &set);

	struct timeval tval;

	// convert from millis to micros
	if (millis < 2000000)
	{
		tval.tv_sec  = 0;
		tval.tv_usec = millis * 1000;
	}
	// convert from millis to secs
	// the rest in micros
	else
	{
		tval.tv_sec  = millis / 1000;
		tval.tv_usec = (millis - tval.tv_sec * 1000) * 1000;
	}

	int retval = 0;

	if (condition == 0) // WAITFORREAD
	{
		if(millis)
			retval = select(0, &set, NULL, NULL, &tval);
		else
			retval = select(0, &set, NULL, NULL, NULL);
	}
	else
    if (condition == 1) // WAITFORWRITE
	{
		if (millis)
			retval = select(0, NULL, &set, NULL, &tval);
		else
			retval = select(0, NULL, &set, NULL, NULL);
	}

    return retval;
}

int  SocketProxy::sysIoctlSocket(int fd, long cmd, unsigned long* argp)
{
	return ioctl(fd,cmd,argp);
}

unsigned long SocketProxy::sysInetAddr(const char* addr)
{
	return (unsigned long) inet_addr(addr);
}

int SocketProxy::sysGetPeerName(int fd, struct sockaddr* name, int* namelen)
{
	return getpeername(fd, name, namelen);
}

char* SocketProxy::sysInetNtoa(struct in_addr in)
{
	return inet_ntoa(in);
}

int SocketProxy::sysWSAGetLastError()
{
	return 0;
}

} // namespace JDF

/* end of file */
