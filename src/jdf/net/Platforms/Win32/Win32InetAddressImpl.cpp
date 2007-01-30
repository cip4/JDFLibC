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
#include "Win32InetAddressImpl.h"

#include "Win32SocketInit.h"

#include <jdf/lang/WString.h>
#include <jdf/lang/Janitor.h>


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

WString Win32InetAddressImpl::getLocalHostName()
{
	char hname[64];
	hname[0] = 0;

	if(SocketProxy::sysGetHostName((char*)hname, 64) == SOCKET_ERROR)
		return WString(JDFStrL("localhost"));
	return WString(hname);
}

void Win32InetAddressImpl::makeAnyLocalAddress(InetAddress& addr)
{
	setAddress(addr,INADDR_ANY);
	setFamily(addr,AF_INET);
}


/*
 * Find an internet address for a given hostname.  Not this this
 * code only works for addresses of type INET. The translation
 * of %d.%d.%d.%d to an address (int) occurs in InetAddress now, so the
 * String "host" shouldn't *ever* be a %d.%d.%d.%d string
 *
 * This is almost shared code
 */

std::vector<std::string> Win32InetAddressImpl::lookupAllHostAddr(WString hostname)
{
	struct hostent* shostent;
	std::vector<std::string> vector_address;
	
	char* hostBytes = hostname.getBytes();
	ArrayJanitor<char> hostBytesJanitor(hostBytes);

	shostent = SocketProxy::sysGetHostByName(hostBytes); 

	if (shostent == NULL) 
		return vector_address;
		//throw UnknownHostException("Host " + host + " is unknown");

	int addr_pos =0;
	char* paddr = shostent->h_addr_list[addr_pos];
	while(paddr)
	{
		vector_address.push_back(std::string(paddr,shostent->h_length));
		paddr = shostent->h_addr_list[++addr_pos];
	}
	return vector_address;
}

WString Win32InetAddressImpl::getHostByAddr(int addr)
{
	struct sockaddr_in servAddr;

	addr = SocketProxy::sysHostToNetworkLong(addr);
	struct hostent* shostent;
	
	servAddr.sin_addr.s_addr = addr;
	shostent = SocketProxy::sysGetHostByAddress((char*)&servAddr.sin_addr, sizeof(servAddr.sin_addr), AF_INET);

	if (shostent == NULL) 
		return "";

	return WString(shostent->h_name);
}

int Win32InetAddressImpl::getInetFamily()
{
	return AF_INET;
}

} // namespace JDF
