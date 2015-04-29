
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

/*******************************************************************************
 *
 * Description:
 *
 * This class initialized the socket library for Windows.
 * IMPORTANT: Whenever possible, we want to use Winsock2 (ws2_32.dll)
 * instead of Winsock (wsock32.dll). Other than the fact that it is
 * newer, less buggy and faster than Winsock, Winsock2 lets us to work
 * around the following problem:
 *
 * Generally speaking, it is important to shutdown a socket before
 * closing it, since failing to do so can sometimes result in a TCP
 * RST (abortive close) which is disturbing to the peer of the connection.
 *
 * The winsock way to shutdown a socket is the berkeley call shutdown(),
 * We do not want to call it on Win95, since it sporadically leads to
 * an OS crash in IFS_MGR.VXD. Complete hull breach. Blue screen. Ugly.
 *
 * So in initialize we look for Winsock 2, and if we find it we
 * assign wsassenddisconnectfn function pointer. When we
 * close, we first check to see if it's bound, and if it is, we cal it.
 * Winsock 2 will always be ther on NT, and we recommand that win95 users
 * install it.
 *
 ******************************************************************************/

#ifndef I_SocketProxy_H
#define I_SocketProxy_H

/******************************************************************************
 *	Includes
 ******************************************************************************/

#include <string>
#define SOCKET_ERROR -1
#define INVALID_SOCKET -1
namespace JDF
{
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <unistd.h>

class SocketProxy
{
public:

	static int sysListen(int fd, long count);
	static int sysConnect(int fd, const struct sockaddr* name, int namelen);
	static int sysAccept(int fd,  struct sockaddr* name, int* namelen);
	static int sysRecvFrom(int fd, char* buf, int nBytes, int flags, struct sockaddr* from, int* fromlen);
	static int sysSendTo(int fd, char* buf, int len, int flags, struct sockaddr* to, int tolen);
	static int sysSend(int fd, char* buf, int nBytes, int flags);
	static int sysRecv(int fd, char* buf, int nBytes, int flags);
	static unsigned short sysNetworkToHostShort(unsigned short networkshort);
	static unsigned short sysHostToNetworkShort(unsigned short hostshort);
	static unsigned long sysNetworkToHostLong(unsigned long networklong);
	static unsigned long sysHostToNetworkLong(unsigned long hostlong);
	static int sysBind(int fd, const struct sockaddr* name, int namelen);
	static struct hostent* sysGetHostByName(const char* hostname);
	static int sysGetHostName(char* hostname,int len);
	static struct hostent* sysGetHostByAddress(char* hostname, int len, int type);
	static int sysGetSockName(int fd, struct sockaddr* name, int* namelen);
	static int sysSocket(int domain, int type, int protocol);
	static int sysSocketClose(int fd);
	static int sysTimeout(int fd, int millis, int condition);
	static int sysIoctlSocket(int fd, long cmd, unsigned long* argp);
	static unsigned long sysInetAddr(const char* addr);
	static int sysGetPeerName(int fd, struct sockaddr* name, int* namelen);
	static char* sysInetNtoa(struct in_addr in);
	static int sysWSAGetLastError();
	//static int merrno;
private:

};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/


/******************************************************************************
 *	Implementation
 ******************************************************************************/

} // namespace JDF

#endif /* I_LinuxSOCKETINIT_H */


/* end of file */
