/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

#include "NetworkClient.h"

#include "Socket.h"

#include <jdf/io/BufferedOutputStream.h>
#include <jdf/io/BufferedInputStream.h>
#include <jdf/io/PrintStream.h>
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

NetworkClient::NetworkClient()
{
	serverSocket = NULL;
	serverInput  = NULL;
	serverOutput = NULL;
}

NetworkClient::NetworkClient(const WString& host, int port)
{
	openServer(host, port);
}

void NetworkClient::openServer(const WString& server, int port)
{
	if (serverSocket != NULL)
		closeServer();

	serverSocket = doConnect(server, port);

	// todo delete out
	bufferedOut  = new BufferedOutputStream(serverSocket->getOutputStream());
	serverOutput = new PrintStream(*bufferedOut,true);
	serverInput  = new BufferedInputStream(serverSocket->getInputStream());
}

Socket* NetworkClient::doConnect(const WString& server, int port)
{
//	std::cout<<"Socket* NetworkClient::doConnect(const WString& server, int port) entered."<<server.getBytes()<<" "<<port<<std::endl;
	Socket* s = new Socket();
//	std::cout<<"Socket* NetworkClient::doConnect(const WString& server, int port) after creating socket."<<std::endl;
	JDF::Janitor<Socket> socketJanitor(s);
//	std::cout<<"Socket* NetworkClient::doConnect(const WString& server, int port) before connecting "<<std::endl;
	s->connect(server,port);
//	std::cout<<"Socket* NetworkClient::doConnect(const WString& server, int port) after connecting "<<std::endl;

	socketJanitor.orphan();
	return s;
}

void NetworkClient::closeServer()
{
	if (!serverIsOpen())
		return;

	if (serverInput)
	{
		delete serverInput;
	}
	if (serverOutput)
	{
		delete serverOutput;
		delete bufferedOut; // buffered out
	}

	if (serverSocket)
	{
		serverSocket->close();
		delete serverSocket;
	}

	serverSocket = NULL;
	serverInput  = NULL;
	serverOutput = NULL;
	bufferedOut  = NULL;
}

bool NetworkClient::serverIsOpen()
{
	return serverSocket != NULL;
}

void NetworkClient::setTimeout(int millis)
{
	if (serverIsOpen())
		serverSocket->setSoTimeout(millis);
	else
		throw IOException(L"can't set timeout. socket is not connected");
}

int NetworkClient::getTimeout()
{
	if (serverIsOpen())
		return serverSocket->getSoTimeout();
	else
		throw IOException(L"can't get timeout. socket is not connected");
}

} // namespace JDF
