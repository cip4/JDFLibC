/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2010 The International Cooperation for the Integration of 
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

#include "PlainHttpURLConnection.h"

#include "PlainHttpOutputStream.h"
#include "HttpURLStreamHandler.h"
#include "HttpClient.h"
#include "HeaderParser.h"
#include "InetAddress.h"
#include "BasicAuthentication.h"
#include "PasswordAuthentication.h"
#include "DigestAuthentication.h"
#include "Authenticator.h"

#include <jdf/io/PrintStream.h>
#include <jdf/io/InputStream.h>
#include <jdf/lang/Integer.h>
#include <jdf/lang/Exception.h>
#include <jdf/util/PlatformUtils.h>


namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 


	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 


	const char* PlainHttpURLConnection::httpVersion = "HTTP/1.1";
	const char* PlainHttpURLConnection::acceptString = "text/html, image/gif, image/jpeg, *; q=.2, */*; q=.2";
	const int PlainHttpURLConnection::maxRedirects = 5;

	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 


	/******************************************************************************
	*	Classes
	******************************************************************************/ 

	PlainHttpURLConnection::PlainHttpURLConnection(URL& u, HttpURLStreamHandler* handler) :
	HttpURLConnection(u)
	{
		failedOnce      = false;
		setRequests     = false;
		ps              = NULL;
		inputStream     = NULL;
		this->handler   = handler;
		exceptionThrown = false;
		poster          = NULL;
		http            = NULL;
		connectionTimeout=-1;
	}

	PlainHttpURLConnection::PlainHttpURLConnection(URL& u, const WString& host, int port) :
	HttpURLConnection(u)
	{
		failedOnce      = false;
		setRequests     = false;
		ps              = NULL;
		inputStream     = NULL;
		this->handler   = handler;
		exceptionThrown = false;
		poster          = NULL;
		http            = NULL;
		connectionTimeout=-1;
	}

	PlainHttpURLConnection::~PlainHttpURLConnection()
	{
		if (http)
		{
			if (http->isKeepingAlive() == false) // TODO && !finished)
				disconnect();
			else
				HttpClient::finish(http);
		}

		if (poster != NULL)
		{
			delete poster;
			poster = NULL;
		}
	}

	void PlainHttpURLConnection::connect()
	{
		//  std::cout<<"void PlainHttpURLConnection::connect() entered."<<std::endl;
		if (connected)
			return;
		//	std::cout<<"void PlainHttpURLConnection::connect() not connected."<<std::endl;
		try
		{
			if (url.getProtocol() == JDFStrL("http") && !failedOnce)
			{
				//			std::cout<<"void PlainHttpURLConnection::connect() before http = HttpClient::New(url); ."<<std::endl;
				http = HttpClient::New(url);
				//			std::cout<<"void PlainHttpURLConnection::connect() after http = HttpClient::New(url); ."<<std::endl;
			}
			else
			{
				// make sure to construct new connection of first attempt failed
				//			std::cout<<"void PlainHttpURLConnection::connect() before http = new HttpClient();."<<std::endl;
				http = new HttpClient();
				http->create(url,handler->mProxy,handler->mProxyPort);
				//			std::cout<<"void PlainHttpURLConnection::connect() after http = new HttpClient();."<<std::endl;
			}
			ps = (PrintStream*) http->getOutputStream();
		}
		catch (IOException& e)
		{
			throw e;
		}
		connected = true;

		if (connectionTimeout != -1)
		{
			http->setTimeout(connectionTimeout);
		}
		else
		{
			PlatformUtils::value_pair res = PlatformUtils::getProperty("http.connectionTimeout");
			if (res.first == true)
			http->setTimeout(Integer::parseInt(res.second));
		}
	}

	InputStream& PlainHttpURLConnection::getInputStream()
	{
		if (!doInput)
			throw ProtocolException(WString("Cannot read from URLConnection") +
			L"if doInput=false (call setDoInput(true))" );

		return openInputStream();
	}

	InputStream& PlainHttpURLConnection::openInputStream()
	{
		if (!doInput)
			throw ProtocolException(WString("Cannot read from URLConnection") +
			L"if doInput=false (call setDoInput(true))" );

		if (inputStream && !connected && exceptionThrown)
		{
			throw IOException("Exception has been thrown");
		}

		if (inputStream != NULL)
			return *inputStream;

		int redirects = 0;

		AuthenticationInfo* serverAuthentication = NULL;
		AuthenticationInfo* proxyAuthentication  = NULL;

		try
		{
			do
			{
				connect();
				ps = (PrintStream*) http->getOutputStream();
				writeRequests();
				responses.clear();
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
				if (followRedirect())
				{
					/* if we should follow a redirect, then the followRedirects()
					* method will disconnect() and re-connect us to the new
					* location
				 */
					redirects++;
					continue;
				}


				if (respCode >= 400) {
					if (respCode == 404 || respCode == 410) {
						throw  FileNotFoundException(url.toString());
					} 
					else 
					{
						throw IOException(L"Server returned HTTP response code: " + WString::valueOf(respCode) + L" for URL: " +
							url.toString());
					}
				}
				return *inputStream;
			}
			while (redirects < maxRedirects);


			// too many redirects if we got here
			throw ProtocolException("Server redirected too many times ("
				+ Integer::toString(redirects) + ")");
		} 
		catch (IOException& e)
		{
			disconnect();
			exceptionThrown = true;
			throw e;
		}
	}


	OutputStream& PlainHttpURLConnection::getOutputStream()
	{
		//	std::cout<<"OutputStream& PlainHttpURLConnection::getOutputStream() entered."<<std::endl; // TBD: for debugging only.
		try
		{
			if (!doOutput)
			{
				//			std::cout<<"OutputStream& PlainHttpURLConnection::getOutputStream() cannot write to a URLConnection if doOutput=false - call setDoOutput(true)."<<std::endl; // TBD: for debugging only.
				throw ProtocolException("cannot write to a URLConnection if doOutput=false - call setDoOutput(true)");
			}

			if (method == "GET") 
			{
				setRequestMethod("POST");
			}
			if (method != "POST" && method != "PUT" && url.getProtocol() == "http")
			{
				//			std::cout<<"OutputStream& PlainHttpURLConnection::getOutputStream() HTTP method does not support output."<<std::endl; // TBD: for debugging only.
				throw ProtocolException("HTTP method " + method +
					" doesn't support output");
			}

			// if there's already an input stream open, throw an exception
			if (inputStream != NULL) 
			{
				//			std::cout<<"OutputStream& PlainHttpURLConnection::getOutputStream() Cannot write output after reading input."<<std::endl; // TBD: for debugging only.
				throw ProtocolException("Cannot write output after reading input.");
			}

			//		std::cout<<"OutputStream& PlainHttpURLConnection::getOutputStream()before connect."<<std::endl; // TBD: for debugging only.
			connect();

			//	std::cout<<"OutputStream& PlainHttpURLConnection::getOutputStream()after connect."<<std::endl; // TBD: for debugging only.
			if (poster == NULL)
				poster = new PlainHttpOutputStream(this);
			return *poster;
		}
		catch (IOException& e) 
		{
			disconnect();
			throw e;
		}
	}


	/* Tells us whether to follow a redirect.  If so, it
	* closes the connection (break any keep-alive) and
	* resets the url, re-connects, and resets the request
	* property.
	*/

	bool PlainHttpURLConnection::followRedirect()
	{
		if (!getInstanceFollowRedirects()) 
		{
			return false;
		}

		int stat = getResponseCode();
		if (stat < 300 || stat > 305 || stat == HTTP_NOT_MODIFIED) 
		{
			return false;
		}

		URLConnection::value_pair loc = getHeaderField(JDFStrL("Location"));
		if (!loc.first) 
		{ 
			/* this should be present - if not, we have no choice
			* but to go forward w/ the response we got
			*/
			return false;
		}
		disconnect();
		// clear out old response headers!!!!
		responses.clear();
		if (stat == HTTP_USE_PROXY) 
		{
			/* This means we must re-request the resource through the
			* proxy denoted in the "Location:" field of the response.
			* Judging by the spec, the string in the Location header
			* _should_ denote a URL - let's hope for "http://my.proxy.org"
			* Make a new HttpClient to the proxy, using HttpClient's
			* Instance-specific proxy fields, but note we're still fetching
			* the same URL.
			*/
			URL urlp(loc.second);
			delete http;
			http=0;
			setProxiedClient (url, urlp.getHost(), urlp.getPort());
			requests.set(0, method + " " + http->getURLFile()+" "  + 
				httpVersion, "");
			connected = true;
		} 
		else 
		{
			// maintain previous headers, just change the name
			// of the file we're getting

			url = URL(url.toString(), loc.second);

			PlatformUtils::value_pair strictPostRedirect = PlatformUtils::getProperty(JDFStrL("http.strictPostRedirect"));
			bool boolStrictPostRedirect;
			if (strictPostRedirect.first)
			{	
				if (strictPostRedirect.second == JDFStrL("true"))
					boolStrictPostRedirect = true;
				else
					boolStrictPostRedirect = false;
			}
			else
			{
				boolStrictPostRedirect = false;
			}

			if (method == JDFStrL("POST") &&  !boolStrictPostRedirect) 
			{
				/* The HTTP/1.1 spec says that a redirect from a POST 
				* *should not* be immediately turned into a GET, and
				* that some HTTP/1.0 clients incorrectly did this.
				* Correct behavior redirects a POST to another POST.
				* Unfortunately, since most browsers have this incorrect
				* behavior, the web works this way now.  Typical usage
				* seems to be:
				*   POST a login code or passwd to a web page.
				*   after validation, the server redirects to another
				*     (welcome) page
				*   The second request is (erroneously) expected to be GET
			 * 
			 * We will do the incorrect thing (POST-->GET) by default.
			 * We will provide the capability to do the "right" thing
			 * (POST-->POST) by a system property, "http.strictPostRedirect=true"
			 */

				requests.clear();
				setRequests = false;
				setRequestMethod(JDFStrL("GET"));
				delete poster;
				poster = NULL;
				connect();
			} 
			else 
			{
				connect();
				requests.set(0, method + " " + http->getURLFile()+" "  + 
					httpVersion,"");
				requests.set("Host", url.getHost() + ((url.getPort() == -1 || url.getPort() == 80) ?
					"": ":"+ Integer::toString(url.getPort())));
			}
		}
		return true;
	}

	void PlainHttpURLConnection::writeRequests()
	{
		if (!setRequests)
		{
			WString urlFile = http->getURLFile();
			requests.prepend(method + JDFStrL(" ") +urlFile +  JDFStrL(" ") + httpVersion, JDFStrL(""));

			PlatformUtils::value_pair v = PlatformUtils::getProperty("http.agent");
			if (v.first)
				userAgent = v.second;
			else
				userAgent = JDFStrL("Mozilla/4.0 (compatible; MSIE 5.5; Windows NT 4.0)");
			requests.setIfNotSet(L"User-Agent", userAgent);
			int port = url.getPort();
			WString host = url.getHost();
			if (port != -1 && port != 80)
				host += ":" + Integer::toString(port);

			requests.setIfNotSet(JDFStrL("Host"),host);
			requests.setIfNotSet(JDFStrL("Accept"), acceptString);

			// TODO handle keep alive
			// 070911 - remove next 2 code lines
			// the following two lines seem to be in contradiction to the comment and code below
			//if (!failedOnce && http->getHttpKeepAliveSet())
			//	requests.setIfNotSet(JDFStrL("Proxy-Connection"),JDFStrL("keep-alive"));
			//requests.set("Connection","close");

			/* Here, we have to work around an egregious bug in the Netscape
			* proxy (at least in version 2.0p1 and 2.0p1+ by my reckoning):
			* 1) If we're doing a POST
			* 2) And we send "Proxy-Connection: keep-alive"
			* 3) And the server the proxy connects to DOES NOT reply w/ 
			*    "Connection: keep-alive"
			* The proxy will *still* send back with the responses the headers
			* "Connection: keep-alive" and "Proxy-connection: keep-alive",
			* no if's, and's, or but's.
			* Which deceives us, the client, into thinking we have a keep-alive
			* connection with the ultimate server when in fact we do not.
			* The solution, unfortunately, is to never attempt keep-alive
			* when talking to a proxy && (POST || PUT).  I don't want to get 
			* into the game of deciphering which proxy we're talking to. -brown
			*/

			// Try keep-alive only on first attempt
			if (!failedOnce && http->getHttpKeepAliveSet()) 
			{
				if (http->isUsingProxy() && ! (method == JDFStrL("POST")
					|| method == JDFStrL("PUT") )) 
				{
					requests.setIfNotSet(JDFStrL("Proxy-Connection"), JDFStrL("keep-alive"));
				}
				else if (!(http->isUsingProxy())) 
				{
					requests.setIfNotSet(JDFStrL("Connection"), JDFStrL("keep-alive"));//keep-alive");
					//	requests.setIfNotSet(JDFStrL("Connection"), JDFStrL("close"));//keep-alive");
				}
			} else 
			{
				requests.set(JDFStrL("Connection"), JDFStrL("close"));
			}
			// TODO if-modified-since 
			// if needed

			// send any pre-emptive authentication
			if (http->isUsingProxy())
			{
				AuthenticationInfo* pauth =
					AuthenticationInfo::getProxyAuth(http->getProxyHostUsed(),
					http->getProxyPortUsed());
				if (pauth && pauth->supportsPreemptiveAuthorization())
				{
					requests.setIfNotSet(pauth->getHeaderName(),pauth->getHeaderValue());
				}
			}

			if (poster != NULL)
			{				
				if (method != JDFStrL("PUT"))
				{
					WString type(JDFStrL("text/plain"));
					requests.setIfNotSet(JDFStrL("Content-type"),type);
				}
				
				requests.set("Content-Length",Integer::toString(poster->size()));
			}
			setRequests = true;
		}
		http->writeRequests(requests);
		if (poster != NULL)
		{
			poster->writeTo(*ps);
			ps->flush();
		}

		if (ps->checkError())
		{
			//TODO finish this
			disconnect();
			if (failedOnce)
				throw IOException(JDFStrL("Error writing to server"));
			else
				failedOnce = true;
			delete http;
			http=0;
			setNewClient(url);
			ps  = (PrintStream*) http->getOutputStream();
			connected = true;
			responses.clear();
			requests.clear();
			setRequests= false;
			writeRequests();
		}
	}

	void PlainHttpURLConnection::disconnect()
	{
		// TODO
		responseCode = -1;
		if (http != NULL)
		{
			http->closeServer();
			delete http;
			http=0;
			connected = false;
			inputStream   = NULL;
		}
	}

	bool PlainHttpURLConnection::usingProxy()
	{
		if (http != NULL)
			return http->isUsingProxy();
		return false;
	}

	URLConnection::value_pair PlainHttpURLConnection::getHeaderField(int n)
	{
		try
		{
			getInputStream();
		} catch (IOException&)
		{
		}
		return responses.getValue(n);
	}

	URLConnection::value_pair PlainHttpURLConnection::getHeaderField(const WString& name)
	{
		try
		{
			getInputStream();
		} catch (IOException&)
		{
		}
		return responses.findValue(name);
	}

	URLConnection::value_pair PlainHttpURLConnection::getHeaderFieldKey(int n)
	{
		try
		{
			getInputStream();
		} catch (IOException&)
		{
		}
		return responses.getKey(n);
	}

	void PlainHttpURLConnection::setProxiedClient (const URL& url, const WString& proxyHost, int proxyPort)
	{
		setProxiedClient(url,proxyHost,proxyPort,false);
	}

	void PlainHttpURLConnection::setProxiedClient (const URL& url, const WString& proxyHost, int proxyPort, bool useCache)
	{
		http = HttpClient::New(url,proxyHost,proxyPort,useCache);
	}

	void PlainHttpURLConnection::setNewClient (const URL& url)
	{
		setNewClient(url,false);
	}

	void PlainHttpURLConnection::setNewClient (const URL& url, bool useCache)
	{
		http = HttpClient::New(url,useCache);
	}


	void PlainHttpURLConnection::setAuthenticationProperty(const WString& key, const WString& value) 
	{
		requests.set(key, value);
	}


	AuthenticationInfo* PlainHttpURLConnection::getHttpProxyAuthentication()
	{
		AuthenticationInfo* ret = NULL;
		URLConnection::value_pair v = getHeaderField(JDFStrL("Proxy-authenticate"));
		WString host = http->getProxyHostUsed();
		int     port = http->getProxyPortUsed();

		if (host != "" && v.first)
		{
			HeaderParser p(v.second);
			WString scheme = p.findKey(0).second;
			WString realm = p.findValue(JDFStrL("realm")).second;
			ret = AuthenticationInfo::getProxyAuth(host,port,realm);

			InetAddress addr;
			try
			{
				addr = InetAddress::getByName(host);
			}
			catch (UnknownHostException&)
			{
			}
			if (ret == NULL && scheme.compareToIgnoreCase(JDFStrL("basic"))==0)
			{
				PasswordAuthentication* a =
					requestPasswordAuthentication(addr,port,"http",realm,scheme);
				if (a != NULL)
					ret = new BasicAuthentication(true,host,port,realm,a);
				delete a;
				a=0;
			}
			if (ret != NULL)
			{
				if (!ret->setHeaders(this,p)) 
				{
					delete ret;
					ret = NULL;
				}
			}
		}
		return ret;
	}

	AuthenticationInfo* PlainHttpURLConnection::getServerAuthentication()
	{
		AuthenticationInfo* ret = NULL;
		URLConnection::value_pair v = getHeaderField(JDFStrL("WWW-Authenticate"));

		if (v.first)
		{
			HeaderParser p(v.second);
			WString scheme = p.findKey(0).second;
			WString realm = p.findValue("realm").second;
			ret = AuthenticationInfo::getServerAuth(url,realm);


			InetAddress addr;
			try
			{
				addr = InetAddress::getByName(url.getHost());
			}
			catch (UnknownHostException&)
			{
			}
			if (ret == NULL && scheme.compareToIgnoreCase(JDFStrL("basic"))==0)
			{
				PasswordAuthentication* a =
					requestPasswordAuthentication(addr,url.getPort(), url.getProtocol(), realm, scheme);
				if (a != NULL)
					ret = new BasicAuthentication(false,url,realm,a);
				delete a;
				a=0;
			}
			if (ret == NULL && scheme.compareToIgnoreCase(JDFStrL("digest"))==0)
			{
				PasswordAuthentication* a =
					requestPasswordAuthentication(addr,url.getPort(), url.getProtocol(), realm, scheme);
				if (a != NULL)
					ret = new DigestAuthentication(url,realm,scheme,a);
				delete a;
				a=0;
			}
			if (ret != NULL)
			{
				if (!ret->setHeaders(this,p)) 
				{
					delete ret;
					ret = NULL;
				}
			}
		}
		return ret;
	}

	void PlainHttpURLConnection::setRequestProperty(const WString& key, const WString& value)
	{
		if (connected)
			throw IllegalAccessError("Already connected");

		requests.set(key, value);
	}

	PasswordAuthentication* PlainHttpURLConnection::requestPasswordAuthentication(
		InetAddress addr, 
		int port,
		const WString& protocol,
		const WString& prompt,
		const WString& scheme)
	{
		return Authenticator::requestPasswordAuthentication(addr, port, protocol, prompt, scheme);
	}


	void PlainHttpURLConnection::setTimeout(int millis)
	{
		connectionTimeout = millis;

		// if already connected change timeout
		if (http)
			http->setTimeout(millis);
		else
		{
			// cache timeout value until connection is made
		}

	}
	
	int PlainHttpURLConnection::getTimeout()
	{
		if (connectionTimeout)
			return connectionTimeout;
		if (http)
			return http->getTimeout();
		else
			return 0;
	}

	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/ 

} // namespace JDF
