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

#include "PlainHttpsURLConnection.h"

#include "HttpsClient.h"
#include "HttpURLStreamHandler.h"
#include "AuthenticationInfo.h"
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

	PlainHttpsURLConnection::PlainHttpsURLConnection(URL& u, const WString& host, int port) :
PlainHttpURLConnection(u,host,port)
{
}

PlainHttpsURLConnection::PlainHttpsURLConnection(URL& u, HttpURLStreamHandler* handler) :
PlainHttpURLConnection(u,handler)
{
}

void PlainHttpsURLConnection::connect()
{
	if (connected)
		return;

	AuthenticationInfo* serverAuthentication = NULL;
	AuthenticationInfo* proxyAuthentication  = NULL;

	bool requestset = false;
	int redirects = 0;

	MessageHeader backup = requests;

	requests.clear();

	do
	{
		try
		{
			if (url.getProtocol() == "https" && !failedOnce)
			{
				http = HttpsClient::New(url);
			}
			else
			{
				// make sure to construct new connection of first attempt failed
				http = new HttpsClient();
				http->create(url,handler->mProxy,handler->mProxyPort);
			}
			ps = (PrintStream*) http->getOutputStream();
		}
		catch (IOException& e)
		{
			throw e;
		}
		connected = true;
		https =(HttpsClient*) http;

		if (http->isUsingProxy() == true)
		{
			if (!requestset)
			{
				WString connect = WString("CONNECT") + " " + getURL().getHost() + ":443 " + "HTTP/1.0";

				requests.prepend(connect,"");

				AuthenticationInfo* pauth =
					AuthenticationInfo::getProxyAuth(http->getProxyHostUsed(),
					http->getProxyPortUsed());
				if (pauth && pauth->supportsPreemptiveAuthorization())
				{
					requests.setIfNotSet(pauth->getHeaderName(),pauth->getHeaderValue());
				}
				requestset = true;
			}

			http->writeRequests(requests);
			http->parseHTTP(responses);
			inputStream = http->getInputStream();
			int respCode = getResponseCode();
			if (respCode == HTTP_PROXY_AUTH) 
			{
				if (proxyAuthentication != NULL)
				{
					// remove from cache
					proxyAuthentication->removeFromCache();
					delete proxyAuthentication;
					proxyAuthentication=0;
				}
				proxyAuthentication = getHttpProxyAuthentication();
				if (proxyAuthentication != NULL)
				{
					disconnect();
					redirects++;
					continue;
				}

			}
			if (respCode == HTTP_UNAUTHORIZED) 
			{
				if (serverAuthentication != NULL)
				{
					serverAuthentication->removeFromCache();
					delete serverAuthentication;
					serverAuthentication=0;
					// previous authorization failed  - uncache
					// serverAuthentication->removeFromCache
				}
				serverAuthentication = getServerAuthentication();
				if (serverAuthentication != NULL)
				{
					disconnect();
					redirects++;
					continue;
				}
			}
			if (respCode == HTTP_OK || (respCode>= 300 && respCode <=305)) 
			{
				if (proxyAuthentication != NULL) 
				{
					// cache auth info on success
					// t.o.o.
					proxyAuthentication->addToCache();
				}
				if (serverAuthentication != NULL) 
				{
					// cache auth info on success
					// t.o.o.
					serverAuthentication->addToCache();
				}
			}
			https->sslconnect();
			requests = backup;
			responses.clear();
			responseCode = -1;
			return;
		}
		else
			return;
	} while (redirects < maxRedirects);
}

HttpClient* PlainHttpsURLConnection::getProxiedClient (const URL& url, const WString& proxyHost, int proxyPort)
{
	HttpsClient* tmp = new HttpsClient();
	https = tmp;
	tmp->create(url, proxyHost, proxyPort);
	return tmp;
}

HttpClient* PlainHttpsURLConnection::getNewClient (const URL& url)
{
	HttpsClient* tmp = new HttpsClient();
	https = tmp;
	tmp->create(url, "", -1);
	return tmp;
}

} // namespace JDF
