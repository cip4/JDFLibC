
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

#include <jdf/net/Platforms/MacOS/SocketProxy.h>



namespace JDF
{

// static int merrno = 0;

int SocketProxy::sysListen(int fd, long count)
{
	int retVal = listen(fd,count);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

int SocketProxy::sysConnect(int fd, const struct sockaddr* name, int namelen)
{
	int retVal = connect(fd,name,namelen);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

int SocketProxy::sysAccept(int fd,  struct sockaddr* name, int* namelen)
{
	int retVal = accept(fd, name, (socklen_t *) namelen);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

int SocketProxy::sysRecvFrom(int fd, char* buf, int nBytes, int flags, struct sockaddr* from, int* fromlen)
{
	int retVal = recvfrom(fd, buf, nBytes, flags, from, (socklen_t *) fromlen);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

int SocketProxy::sysSendTo(int fd, char* buf, int len, int flags, struct sockaddr* to, int tolen)
{
	int retVal = sendto(fd, buf, len, flags, to, tolen);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

int SocketProxy::sysSend(int fd, char* buf, int nBytes, int flags)
{
	int retVal = send(fd, buf, nBytes, flags);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

int SocketProxy::sysRecv(int fd, char* buf, int nBytes, int flags)
{
	int retVal = recv(fd, buf, nBytes, flags);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
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
	int retVal = bind(fd, name, namelen);
	//if ( retVal < 0) merrno = errno;
	return retVal;
}

struct hostent* SocketProxy::sysGetHostByName(const char* hostname)
{
	struct hostent* t =gethostbyname(hostname);
	//SocketProxy::merrno =h_errno;
	return t;
}

int SocketProxy::sysGetHostName(char* hostname,int len)
{
	int retVal = gethostname(hostname, len);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

struct hostent* SocketProxy::sysGetHostByAddress(char* hostname, int len, int type)
{
	struct hostent* t = gethostbyaddr(hostname,len,type);
	//SocketProxy::merrno =h_errno;
	return t;
}

int SocketProxy::sysGetSockName(int fd,  struct sockaddr* name, int* namelen)
{
	int retVal = getsockname(fd, name, (socklen_t *) namelen);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

int SocketProxy::sysSocket(int domain, int type, int protocol)
{
	int retVal = socket(domain,type,protocol);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

/**
 * This function is carefully designed to work around a bug in Windows 95's
 * networking winsock. Please see the header file for a complete description
 * of the problem
 */

int SocketProxy::sysSocketClose(int fd)
{
	if (fd > 0)
	{
		int retVal = close (fd);
		//if ( retVal < 0) SocketProxy::merrno = errno;
		return retVal;
	}
	return 1;
}

int SocketProxy::sysTimeout(int fd,int millis, int condition)
{
	fd_set set;
	FD_ZERO(&set);
	FD_SET(fd, &set);

	struct timeval tval;

	// convert from millis to micros
	if (millis < 2000000)
	{
		tval.tv_sec  = 0;
		tval.tv_usec = millis*1000;
	}
	// convert from millis to secs
	// the rest in micros
	else
	{
		tval.tv_sec  = millis/1000;
		tval.tv_usec = (millis - tval.tv_sec*1000)*1000;
	}

	int retval;

	if(condition == 0) // WAITFORREAD
	{
		if(millis)
			retval = select(0, &set, NULL, NULL, &tval);
		else
			retval = select(0, &set, NULL, NULL, NULL);
	}
	else if (condition == 1) // WAITFORWRITE
	{
		if(millis)
			retval = select(0, NULL, &set, NULL, &tval);
		else
			retval = select(0, NULL, &set, NULL, NULL);
	}
	//if ( retval < 0) SocketProxy::merrno = errno;
	return retval;
}

int  SocketProxy::sysIoctlSocket(int fd, long cmd, unsigned long* argp)
{
	int retVal = ioctl(fd,cmd,argp);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

unsigned long SocketProxy::sysInetAddr(const char* addr)
{
	//TBD:
	//unsigned long (PASCAL FAR* inetaddrfn)(const char FAR*);
	//inetaddrfn = (unsigned long (PASCAL FAR* )(const char FAR*))LinuxSocketInit::sockfnptrs[LinuxSocketInit::FN_INETADDR];
	//return (*inetaddrfn)(addr);
	return (unsigned long)inet_addr(addr);
}

int SocketProxy::sysGetPeerName(int fd, struct sockaddr* name, int* namelen)
{
	int retVal = getpeername(fd, name, (socklen_t *) namelen);
	//if ( retVal < 0) SocketProxy::merrno = errno;
	return retVal;
}

char* SocketProxy::sysInetNtoa(struct in_addr in)
{
	//TBD:
	//char* (PASCAL FAR* inetntoafn)(struct in_addr);
	//inetntoafn = (char* (PASCAL FAR* )(struct in_addr))LinuxSocketInit::sockfnptrs[LinuxSocketInit::FN_INETNTOA];
	//return (*inetntoafn)(in);
	return inet_ntoa(in);
}


int SocketProxy::sysWSAGetLastError()
{
	//return SocketProxy::merrno;
	return 0;
}

} // namespace JDF

/* end of file */

