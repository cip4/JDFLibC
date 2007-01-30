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

#include "Win32SocketInit.h"


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

int (PASCAL FAR* Win32SocketInit::sockfnptrs[])() = 
			{ NULL, NULL, NULL, NULL, NULL,
			  NULL, NULL, NULL, NULL, NULL,
			  NULL, NULL, NULL, NULL, NULL,
			  NULL, NULL, NULL, NULL, NULL,
			  NULL, NULL, NULL, NULL, NULL,NULL,NULL,NULL,NULL};

const int Win32SocketInit::FN_RECV = 0;
const int Win32SocketInit::FN_SEND = 1;
const int Win32SocketInit::FN_LISTEN = 2;
const int Win32SocketInit::FN_ACCEPT = 3;
const int Win32SocketInit::FN_RECVFROM = 4 ;
const int Win32SocketInit::FN_SENDTO = 5 ;
const int Win32SocketInit::FN_SELECT = 6;
const int Win32SocketInit::FN_CONNECT = 7;
const int Win32SocketInit::FN_CLOSESOCKET = 8;
const int Win32SocketInit::FN_SHUTDOWN = 9;
const int Win32SocketInit::FN_DOSHUTDOWN = 10;
const int Win32SocketInit::FN_GETHOSTBYNAME = 11;
const int Win32SocketInit::FN_HTONS = 12;
const int Win32SocketInit::FN_SOCKET = 13;
const int Win32SocketInit::FN_WSASENDDISCONNECT = 14;
const int Win32SocketInit::FN_IOCTLSOCKET = 15;
const int Win32SocketInit::FN_GETHOSTNAME = 16;
const int Win32SocketInit::FN_GETHOSTBYADDRESS = 17; 
const int Win32SocketInit::FN_NTOHS = 18;
const int Win32SocketInit::FN_BIND = 19;
const int Win32SocketInit::FN_INETADDR = 20;
const int Win32SocketInit::FN_GETSOCKNAME = 21;
const int Win32SocketInit::FN_GETPEERNAME = 22;
const int Win32SocketInit::FN_INETNTOA = 23;
const int Win32SocketInit::FN_GETSOCKOPT = 24;
const int Win32SocketInit::FN_SETSOCKOPT = 25;
const int Win32SocketInit::FN_NTOHL = 26;
const int Win32SocketInit::FN_HTONL = 27;
const int Win32SocketInit::FN_WSAGETLASTERROR= 28;
		  	
typedef int (__stdcall *fnWSAEventSelect)(SOCKET s, HANDLE event,long NetworkEvents);
//extern fnWSAEventSelect WSAES;
fnWSAEventSelect WSAES = NULL;

static Win32SocketInit* sSocketInitImpl = NULL;

bool Win32SocketInit::Initialize()
{
	if (sSocketInitImpl == NULL)
	{
		sSocketInitImpl = new Win32SocketInit();
	}
	return sSocketInitImpl->isStartedUp();
}

void Win32SocketInit::Terminate()
{
	delete sSocketInitImpl;
	sSocketInitImpl = NULL;
}

Win32SocketInit::Win32SocketInit() :
	mStartedUp(false),
	mWinsock2Available(false)
{
	int (PASCAL FAR* WSAStartupPtr)(WORD,LPWSADATA);
	WSADATA wsaData;   
	
	// try to load Winsock2, and if that fails, load Winsock

#ifdef UNICODE
	hWinsock = LoadLibraryW(L"ws2_32.dll");
#else
	hWinsock = LoadLibraryA("ws2_32.dll");
#endif
	if (hWinsock == NULL)
	{
#ifdef UNICODE
		hWinsock = LoadLibraryW(L"wsock32.dll");
#else
		hWinsock = LoadLibraryA("wsock32.dll");
#endif
		mWinsock2Available = false;
	}
	else
		mWinsock2Available = true;

	if (hWinsock == NULL)
		return;

	// if we loaded the dll, we might as well initialize it

	WSAStartupPtr = (int (PASCAL FAR*)(WORD, LPWSADATA)) 
				GetProcAddress(hWinsock, "WSAStartup");

	if (WSAStartupPtr(MAKEWORD(2,0), &wsaData) != 0)
	{
		mStartedUp = false;
		return;
	}
	mStartedUp = true;


	initSockFnTable();

	// initialize factories


	// initialize proxy settings
	// this tries to use the OS defined settings.
//	obtainProxySettings();
}

void Win32SocketInit::initSockFnTable()
{
	sockfnptrs[FN_RECV]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "recv");
	sockfnptrs[FN_SEND]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "send");
	sockfnptrs[FN_LISTEN]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "listen");
	sockfnptrs[FN_ACCEPT]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "accept");
	sockfnptrs[FN_RECVFROM]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "recvfrom");
	sockfnptrs[FN_SENDTO]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "sendto");
	sockfnptrs[FN_SELECT]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "select");
	sockfnptrs[FN_CONNECT]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "connect");
	sockfnptrs[FN_CLOSESOCKET]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "closesocket");
	/* we don't use this */
	sockfnptrs[FN_SHUTDOWN]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "shutdown");
	sockfnptrs[FN_GETHOSTBYNAME]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "gethostbyname");
	sockfnptrs[FN_HTONS]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "htons");
	sockfnptrs[FN_SOCKET]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "socket");

	sockfnptrs[FN_GETHOSTNAME]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "gethostname");
	sockfnptrs[FN_GETHOSTBYADDRESS]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "gethostbyaddr");

	sockfnptrs[FN_NTOHS]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "ntohs");

	sockfnptrs[FN_BIND]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "bind");

	sockfnptrs[FN_INETADDR]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "inet_addr");

	sockfnptrs[FN_GETSOCKNAME]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "getsockname");

	sockfnptrs[FN_GETPEERNAME]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "getpeername");

	sockfnptrs[FN_INETNTOA]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "inet_ntoa");

	sockfnptrs[FN_GETSOCKOPT]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "getsockopt");

	sockfnptrs[FN_SETSOCKOPT]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "setsockopt");

	sockfnptrs[FN_NTOHL]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "ntohl");

	sockfnptrs[FN_HTONL]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "htonl");


	sockfnptrs[FN_WSAGETLASTERROR]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock, "WSAGetLastError");


	/* in winsock 1, this will simply be 0 */
	sockfnptrs[FN_WSASENDDISCONNECT]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock,
						   "WSASendDisconnect");
	sockfnptrs[FN_IOCTLSOCKET]
	    = (int (PASCAL FAR *)())GetProcAddress(hWinsock,
						   "ioctlsocket");
}

Win32SocketInit::~Win32SocketInit()
{
	if(mStartedUp)
	{
		int (PASCAL FAR* WSACleanupPtr)();
		WSACleanupPtr = (int (PASCAL FAR*)()) 
				GetProcAddress(hWinsock, "WSACleanup");

		WSACleanupPtr();
		FreeLibrary(hWinsock);
	}
	mStartedUp = false;
}

bool Win32SocketInit::isStartedUp() const
{
	return mStartedUp;
}

bool Win32SocketInit::isWinsock2Available() const
{
	return mWinsock2Available;
}

std::string Win32SocketInit::convertToRegExpFormat(const std::string&  s)
{
	std::string out;
	for (unsigned int i=0;i<s.length();i++)
	{
		if (s[i] == '.')
			out.append("\\.");
		else if (s[i] == '*')
			out.append(".*");
		else 
			out.append(1,s[i]);
	}
	return out;
}

void Win32SocketInit::obtainProxySettings()
{
/*
#ifdef PLTF_WIN32
	AGS::RegKey ieKey(AGS::RegKey::LOCALMACHINE_ROOT, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\App Paths\\IEXPLORE.EXE");

	try
	{
		AGS::RegQueryInfo info =ieKey.queryInfo();
		AGS::RegKey internetSettings(AGS::RegKey::LOCALMACHINE_ROOT,"SYSTEM\\CurrentControlSet\\Hardware Profiles\\Current\\Software\\Microsoft\\Windows\\CurrentVersion\\Internet Settings");
		int enableProxy = internetSettings.getIntValue("ProxyEnable");
		if (enableProxy)
		{
			std::string proxyServer = internetSettings.getStringValue("ProxyServer");
			std::string proxyPort;
			int pos = proxyServer.find_first_of(':');
			if (pos != -1)
			{
				proxyPort = proxyServer.substr(pos+1);
				proxyServer = proxyServer.substr(0,pos);
			}

			std::string proxyOverride = internetSettings.getStringValue("ProxyOverride");
			AGS::StringTokenizer st(proxyOverride,";", false);
			std::string dontProxyList;
			while (st.hasMoreTokens())
			{
				std::string nextToken = st.nextToken();
				if (nextToken == "<local>")
				{
					try
					{
						AGS::InetAddress addr = AGS::InetAddress::getLocalHost();
						int pos;
						nextToken="";
						if ((pos = addr.getHostName().find_first_of('.')) != -1)
						{
							nextToken = addr.getHostName().substr(0,pos) + ";";
						}
						nextToken.append(convertToRegExpFormat(addr.getHostName()) + ";" + "localhost");
					} 
					catch (AGS::UnknownHostException& e)
					{
						nextToken="localhost";
					}
				}
				if (dontProxyList.length() != 0)
					dontProxyList.append(";");
				dontProxyList.append(convertToRegExpFormat(nextToken));
			}
			AGS::System::setProperty("http.proxyHost",proxyServer);
			AGS::System::setProperty("http.proxyPort",proxyPort);
			AGS::System::setProperty("http.nonProxyHosts",dontProxyList);
		}
	} 
	catch (AGS::RegKeyException& e)
	{
	}
#endif
*/
}


int SocketProxy::sysListen(int fd, long count)
{
	int (PASCAL FAR* listenfn)(int,long);
	listenfn =	(int (PASCAL FAR* )(int,long))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_LISTEN];
	return (*listenfn)(fd, count);
}

int SocketProxy::sysConnect(int fd, const struct sockaddr* name, int namelen)
{
	int (PASCAL FAR* connectfn)(int,const struct sockaddr*,int);
	connectfn =	(int (PASCAL FAR* )(int,const struct sockaddr*, int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_CONNECT];
	return (*connectfn)(fd, name, namelen);
}

int SocketProxy::sysAccept(int fd, const struct sockaddr* name, int* namelen)
{
	int (PASCAL FAR* acceptfn)(int,const struct sockaddr*, int*);
	acceptfn =	(int (PASCAL FAR* )(int,const struct sockaddr*, int*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_ACCEPT];
	return (*acceptfn)(fd, name, namelen);
}

int SocketProxy::sysRecvFrom(int fd, char* buf, int nBytes, int flags, struct sockaddr* from, int* fromlen)
{
	int (PASCAL FAR* recvfromfn)(int,char*, int, int, struct sockaddr*, int*);
	recvfromfn =	(int (PASCAL FAR* )(int, char*, int, int flags, struct sockaddr*, int*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_RECVFROM];
	return (*recvfromfn)(fd, buf, nBytes, flags, from, fromlen);
}

int SocketProxy::sysSendTo(int fd, char* buf, int len, int flags, struct sockaddr* to, int tolen)
{
	int (PASCAL FAR* sendtofn)(int,char*, int, int, struct sockaddr*, int);
	sendtofn =	(int (PASCAL FAR* )(int, char*, int, int, struct sockaddr*, int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_SENDTO];
	return (*sendtofn)(fd, buf, len, flags, to, tolen);
}

int SocketProxy::sysSend(int fd, char* buf, int nBytes, int flags)
{
	int (PASCAL FAR* sendfn)(int,char*, int, int);
	sendfn =	(int (PASCAL FAR* )(int, char*, int, int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_SEND];
	return (*sendfn)(fd, buf, nBytes, flags);
}

int SocketProxy::sysRecv(int fd, char* buf, int nBytes, int flags)
{
	int (PASCAL FAR* recvfn)(int,char*, int, int);
	recvfn =	(int (PASCAL FAR* )(int, char*, int, int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_RECV];
	return (*recvfn)(fd, buf, nBytes, flags);
}

unsigned short SocketProxy::sysNetworkToHostShort(unsigned short networkshort)
{
	int (PASCAL FAR* ntohsfn)(unsigned short);
	ntohsfn =	(int (PASCAL FAR* )(unsigned short))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_NTOHS];
	return (*ntohsfn)(networkshort); 
}

unsigned long SocketProxy::sysHostToNetworkLong(unsigned long hostlong)
{
	int (PASCAL FAR* htonlfn)(unsigned long);
	htonlfn =	(int (PASCAL FAR* )(unsigned long))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_HTONL];
	return (*htonlfn)(hostlong); 

}

unsigned long SocketProxy::sysNetworkToHostLong(unsigned long networklong)
{
	unsigned long (PASCAL FAR* ntohlfn)(unsigned long);
	ntohlfn =	(unsigned long (PASCAL FAR* )(unsigned long))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_NTOHL];
	return (*ntohlfn)(networklong); 
}

unsigned short SocketProxy::sysHostToNetworkShort(unsigned short hostshort)
{
	unsigned short (PASCAL FAR* htonsfn)(unsigned short);
	htonsfn =	(unsigned short (PASCAL FAR* )(unsigned short))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_HTONS];
	return (*htonsfn)(hostshort); 
}

int SocketProxy::sysBind(int fd, const struct sockaddr* name, int namelen)
{
	int (PASCAL FAR* bindfn)(int, const struct sockaddr FAR*, int);
	bindfn =	(int (PASCAL FAR* )(int, const struct sockaddr FAR*,int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_BIND];
	return (*bindfn)(fd, name, namelen);  
}

struct hostent* SocketProxy::sysGetHostByName(const char* hostname)
{
	struct hostent* (PASCAL FAR* gethostbynamefn)(const char*);
	gethostbynamefn =	(struct hostent* (PASCAL FAR* )(const char*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_GETHOSTBYNAME];
	return (*gethostbynamefn)(hostname);
}

int SocketProxy::sysGetHostName(char* hostname,int len)
{
	int (PASCAL FAR* gethostnamefn)(char*,int);
	gethostnamefn =	(int (PASCAL FAR* )(char*,int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_GETHOSTNAME];
	return (*gethostnamefn)(hostname,len); 
}

struct hostent* SocketProxy::sysGetHostByAddress(char* hostname, int len, int type)
{
	struct hostent* (PASCAL FAR* gethostbyaddressfn)(const char*, int len, int type);
	gethostbyaddressfn =	(struct hostent* (PASCAL FAR* )(const char*, int len, int type))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_GETHOSTBYADDRESS];
	return (*gethostbyaddressfn)(hostname,len,type);
}

int SocketProxy::sysGetSockName(int fd, const struct sockaddr* name, int* namelen)
{
	int (PASCAL FAR* getsocknamefn)(int,const struct sockaddr*, int*);
	getsocknamefn =	(int (PASCAL FAR* )(int,const struct sockaddr*, int*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_GETSOCKNAME];
	return (*getsocknamefn)(fd, name, namelen);
}

int SocketProxy::sysSocket(int domain, int type, int protocol)
{
	int (PASCAL FAR* socketfn)(int,int,int);
	socketfn =	(int (PASCAL FAR* )(int,int,int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_SOCKET];
	return (*socketfn)(domain,type,protocol);
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
		int (PASCAL FAR* closesocketfn)(int);
		int (PASCAL FAR* wsasenddisconnectfn)(int,char FAR*);

		closesocketfn = (int (PASCAL FAR* )(int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_CLOSESOCKET];

		if (sSocketInitImpl->isWinsock2Available())
		{
			wsasenddisconnectfn = (int (PASCAL FAR* )(int,char FAR*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_WSASENDDISCONNECT];
			(void) (*wsasenddisconnectfn)(fd,NULL);
		}
		(void) (*closesocketfn)(fd);
	}
	return TRUE;
}

int SocketProxy::sysTimeout(int fd,int millis, int condition)
{
	int (PASCAL FAR* selectfn)(int, fd_set FAR*, fd_set FAR*, fd_set FAR*, const struct timeval FAR*);

	selectfn = (int (PASCAL FAR* )(int, fd_set FAR*, fd_set FAR*, fd_set FAR*, const struct timeval FAR*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_SELECT];

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
			retval = (*selectfn)(0, &set, NULL, NULL, &tval);
		else
			retval = (*selectfn)(0, &set, NULL, NULL, NULL);
	}
	else if (condition == 1) // WAITFORWRITE
	{
		if(millis)
			retval = (*selectfn)(0, NULL, &set, NULL, &tval);
		else
			retval = (*selectfn)(0, NULL, &set, NULL, NULL);
	}
	return retval;
}

int  SocketProxy::sysIoctlSocket(int fd, long cmd, unsigned long* argp)
{
	int (PASCAL FAR* ioctlsocketfn)(int, long, unsigned long FAR*);
	ioctlsocketfn = (int (PASCAL FAR* )(int, long, unsigned long FAR*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_IOCTLSOCKET];
	return (*ioctlsocketfn)(fd,cmd,argp);
}

unsigned long SocketProxy::sysInetAddr(const char* addr)
{
	unsigned long (PASCAL FAR* inetaddrfn)(const char FAR*);
	inetaddrfn = (unsigned long (PASCAL FAR* )(const char FAR*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_INETADDR];
	return (*inetaddrfn)(addr);
}

int SocketProxy::sysGetPeerName(int fd, struct sockaddr* name, int* namelen)
{
	int (PASCAL FAR* getpeernamefn)(int,struct sockaddr*, int*);
	getpeernamefn =	(int (PASCAL FAR* )(int,struct sockaddr*, int*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_GETPEERNAME];
	return (*getpeernamefn)(fd, name, namelen);
}

char* SocketProxy::sysInetNtoa(struct in_addr in)
{
	char* (PASCAL FAR* inetntoafn)(struct in_addr);
	inetntoafn = (char* (PASCAL FAR* )(struct in_addr))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_INETNTOA];
	return (*inetntoafn)(in);
}
/*
int SocketProxy::sysGetSockopt(int fd, int level, int optname, char* optval, int* optlen)
{
	int (PASCAL FAR* getsockoptfn)(int, int, int, char*, int*);
	getsockoptfn =	(int (PASCAL FAR* )(int,int,int, char*,int*))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_GETSOCKOPT];
	return (*getsockoptfn)(fd,level,optname,optval,optlen);
}

int SocketProxy::sysSetSockopt(int fd, int level, int optname, const char* optval, int optlen)
{
	int (PASCAL FAR* setsockoptfn)(int, int, int, const char*, int);
	setsockoptfn =	(int (PASCAL FAR* )(int,int, int,const char*,int))Win32SocketInit::sockfnptrs[Win32SocketInit::FN_SETSOCKOPT];
	return (*setsockoptfn)(fd,level,optname,optval,optlen);
}
*/

int SocketProxy::sysWSAGetLastError()
{
	int (PASCAL FAR* wsagetlasterrorfn)();
	wsagetlasterrorfn = (int (PASCAL FAR* )())Win32SocketInit::sockfnptrs[Win32SocketInit::FN_WSAGETLASTERROR];
	return (*wsagetlasterrorfn)();

}

} // namespace JDF

/* end of file */
