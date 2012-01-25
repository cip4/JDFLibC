/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2009 The International Cooperation for the Integration of 
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

/******************************************************************************
*	Forward declarations
******************************************************************************/ 

#include "HttpClient.h"

#include "Socket.h"
#include "HeaderParser.h"
#include "ChunkedInputStream.h"
#include <jdf/lang/Exception.h>
#include <jdf/net/KeepAliveInputStream.h>


#include <jdf/net/HttpURLConnection.h>
#include <jdf/io/PrintStream.h>
#include <jdf/io/BufferedInputStream.h>
#include <jdf/io/BufferedOutputStream.h>
#include <jdf/io/ByteArrayOutputStream.h>
#include <jdf/io/PushbackInputStream.h>
#include <jdf/util/StringTokenizer.h>
#include <jdf/util/PlatformUtils.h>
#include <jdf/lang/Integer.h>
#include <jdf/lang/Janitor.h>
#include <jdf/lang/ByteBuffer.h>
#include <iostream>

#include <xercesc/util/XMLUniDefs.hpp>
//#include <jdf/io/Exception.h>

XERCES_CPP_NAMESPACE_USE

namespace JDF
{

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

	const int HttpClient::HTTP_CONTINUE =  100;
	const int HttpClient::httpPortNumber = 80;

	HttpClient::HttpClient()
	{
		failedOnce           = false;
		usingProxy           = false;
		keepingAlive         = false;
		cachedHttpClient	 = false;
		keepAliveConnections = -1;
		keepAliveTimeout     = 0;
		instProxy            = "";
		instProxyPort        = -1;
		bufferedOut          = NULL;
	}

	HttpClient::~HttpClient()
	{
	}
	int HttpClient::getDefaultPort()
	{
		return httpPortNumber;
	}

	WString HttpClient::getProxyHost()
	{
		PlatformUtils::value_pair host = PlatformUtils::getProperty("http.proxyHost");

		if (host.first == false)
			return "";
		else
			return host.second;
	}

	int HttpClient::getProxyPort()
	{
		PlatformUtils::value_pair port = PlatformUtils::getProperty("http.proxyPort");
		//	std::cout<<"int HttpClient::getProxyPort() entered. "<<port.second<<std::endl;
		if (port.first == false)
			return 80;
		return Integer::parseInt(port.second);
	}
	void HttpClient::setHttpSystemKeepAlive(bool bKeepAlive)
	{
		PlatformUtils::setProperty(L"http.keepAlive",bKeepAlive?L"true":L"false");
	}

	bool HttpClient::getHttpKeepAliveSet()
	{
		bool ret = false;
		PlatformUtils::value_pair keepAlive = PlatformUtils::getProperty(L"http.keepAlive");
		if (keepAlive.first)
		{
			if (keepAlive.second == "true")
				ret = true;
			else if (keepAlive.second == "false")
				return false;
		}
		return ret;
	}

	RegexpPool& HttpClient::getDontProxy()
	{
		PlatformUtils::value_pair rawList = PlatformUtils::getProperty("http.nonProxyHosts");


		if (rawList.second == dontProxySource)
			return dontProxy;

		dontProxy.clear();
		if (rawList.second.length())
		{
			StringTokenizer st(rawList.second,";", false);
			while (st.hasMoreTokens())
			{
				dontProxy.add(st.nextToken().toLowerCase());
			}
		}
		dontProxySource = rawList.second;
		return dontProxy;
	}

	void HttpClient::create(const URL& url,  const WString& proxy, int proxyPort, bool proxyDisabled)
	{
		//	std::cout<<"void HttpClient::create(const URL& url,  const WString& proxy, int proxyPort, bool proxyDisabled) entered."<<proxy.getBytes()<<" "<<proxyPort<<std::endl;
		this->proxyDisabled = proxyDisabled;
		if (!proxyDisabled)
		{
			instProxy = proxy;
			instProxyPort = (proxyPort < 0) ? getDefaultPort() : proxyPort;
		}
		// try to set host to "%d.%d.%d.%d" string

		this->host = url.getHost();
		this->url = url;
		port = url.getPort();
		if (port == -1)
			port = getDefaultPort();
		//	std::cout<<"void HttpClient::create(const URL& url,  const WString& proxy, int proxyPort, bool proxyDisabled) before openServer."<<std::endl;
		openServer();
		//	std::cout<<"void HttpClient::create(const URL& url,  const WString& proxy, int proxyPort, bool proxyDisabled) after openServer."<<std::endl;
	}

	void HttpClient::create(const URL& url, bool proxyDisabled)
	{
		create(url,"",-1,proxyDisabled);
	}

	void HttpClient::create(const URL& url)
	{
		create(url,"",-1,false);
	}

	HttpClient* HttpClient::New(const URL& url)
	{
		return New(url,true);
	}

	HttpClient* HttpClient::New(const URL& url,bool useCache)
	{
		return New(url,"",-1,useCache);
	}


	HttpClient* HttpClient::New(const URL& url,WString proxy, int proxyPort, bool useCache)
	{
		if (useCache)
		{
			HttpClient* ret = 0;
			// see if one's already aroun
			ret = getKeepAliveCache().get(url);
			if (ret)
			{
				ret->cachedHttpClient = true;
				ret->url = url;
				return ret;
			}
		}
		HttpClient* ret = new HttpClient();
		Janitor<HttpClient> clientJanitor(ret);
		try
		{
			//		std::cout<<"HttpClient* HttpClient::New(const URL& url) before ret->create(url,false);."<<std::endl;
			ret->create(url,proxy,proxyPort);
			//		std::cout<<"HttpClient* HttpClient::New(const URL& url) after ret->create(url,false);."<<std::endl;
		}
		catch (IOException& e)
		{
			ret->closeServer();
			throw e;
		}
		clientJanitor.orphan();
		//	std::cout<<"HttpClient* HttpClient::New(const URL& url) leaved."<<std::endl;
		return ret;
	}

	void HttpClient::finished()
	{
		keepAliveConnections--;
		if (keepAliveConnections > 0 && keepingAlive && *serverSocket)
		{
			// tbe connection is keepingALive && still valid
			// return it to the cache.
			putInKeepAliveCache();
		}
		else
			closeServer();
	}

	void HttpClient::finish(HttpClient* hc)
	{
		hc->keepAliveConnections--;
		if (hc->keepAliveConnections > 0 && hc->keepingAlive && *(hc->serverSocket))
		{
			// tbe connection is keepingALive && still valid
			// return it to the cache.
			if (hc->putInKeepAliveCache() == false)
			{
				hc->closeServer();
				delete hc;
			}
		}
		else
		{
			hc->closeServer();
			delete hc;
		}
	}

	bool HttpClient::putInKeepAliveCache()
	{
		return getKeepAliveCache().put(url,this);
	}

	void HttpClient::openServer( const WString& server, int port)
	{
		//	std::cout<<"void HttpClient::openServer( const WString& server, int port) entered."<<server.getBytes()<<" "<<port<<std::endl;
		serverSocket = doConnect(server, port);
		//	std::cout<<"void HttpClient::openServer( const WString& server, int port) after doConnect."<<std::endl;
		bufferedOut  = new BufferedOutputStream(serverSocket->getOutputStream());
		serverOutput = new PrintStream(*bufferedOut);
		serverSocket->setTcpNoDelay(true);
		//	std::cout<<"void HttpClient::openServer( const WString& server, int port) leaved."<<std::endl;
	}

	bool HttpClient::isLoopback( const WString& host)
	{
		//	std::cout <<"bool HttpClient::isLoopback( const WString& host) entered with"<<host.getBytes() << std::endl;
		if (host.length() == 0)
			return false;
		//	std::cout <<"bool HttpClient::isLoopback( const WString& host) Marke 1" << std::endl;
		if (host.compareToIgnoreCase("localhost")==0)
			return true;

		//	std::cout <<"bool HttpClient::isLoopback( const WString& host) Marke 2" << std::endl;
		int a=-1,b=-1,c=-1,d=-1;

#if defined(swscanf) || defined(WIN32)
		//	std::cout <<"bool HttpClient::isLoopback( const WString& host) before swscanf" << std::endl;
		int err = swscanf(host.data(),L"%d.%d.%d.%d",&a,&b,&c,&d);
#else
		//	std::cout <<"bool HttpClient::isLoopback( const WString& host) before sscanf" << std::endl;
		char*pc=host.getBytes();
		int err = std::sscanf(pc,"%d.%d.%d.%d",&a,&b,&c,&d);
		delete[]pc;
#endif
		//	std::cout <<"bool HttpClient::isLoopback( const WString& host) after scanf"<<err << std::endl;
		if (!err || err == EOF) return false;
		if (a==-1 || b==-1 || c==-1 || d==-1) return false;
		if (a == 127)
			return true;

		return false;
	}

	void HttpClient::openServer()
	{
		if (keepingAlive) // already opened
			return;

		//	std::cout<<"void HttpClient::openServer() entered."<<std::endl;
		RegexpPool& myDontProxy = getDontProxy();
		//	std::cout<<"void HttpClient::openServer() Marke-2."<<std::endl;
		WString urlHost = url.getHost().toLowerCase();
		//	std::cout<<"void HttpClient::openServer() Marke-1."<<std::endl;
		bool loopback = isLoopback(urlHost);
		//	std::cout<<"void HttpClient::openServer() Marke0."<<std::endl;
		if (url.getProtocol() == "https" || url.getProtocol() == "http")
		{
			if (instProxy.length() && !loopback)
			{
				//			std::cout<<"void HttpClient::openServer() if (instProxy.length() && !loopback) before openServer."<<std::endl;
				openServer(instProxy,instProxyPort);
				//			std::cout<<"void HttpClient::openServer() if (instProxy.length() && !loopback) after openServer."<<std::endl;
				usingProxy = true;
				return;
			}
			//		std::cout<<"void HttpClient::openServer() Marke2."<<std::endl;
			WString proxyHost = getProxyHost();
			if (proxyHost.length() &&
				(!(proxyDisabled || loopback ||
				myDontProxy.match(urlHost) ||
				myDontProxy.match(host))) )
			{
				try
				{
					//				std::cout<<"void HttpClient::openServer() Marke3."<<std::endl;
					int proxyPort = getProxyPort();
					//				std::cout<<"void HttpClient::openServer() Marke4."<<proxyHost<<" "<<proxyPort<<std::endl;
					openServer(proxyHost,proxyPort);
					//				std::cout<<"void HttpClient::openServer() Marke5."<<std::endl;
					instProxy = proxyHost;
					instProxyPort = proxyPort;
					usingProxy = true;
					return;
				} catch (IOException&)
				{
					// try locally
				}
			}
			//		std::cout<<"void HttpClient::openServer() Marke6."<<std::endl;
			openServer(host,port);
			//		std::cout<<"void HttpClient::openServer() Marke7."<<std::endl;
			usingProxy = false;
			return;
		}
	}

	WString HttpClient::getURLFile()
	{
		WString fileName = url.getFile();
		if (fileName.length() == 0)
			fileName == "/";

		WString query = url.getQuery();
		if (query.length())
		{
			fileName.append(chQuestion);
			fileName.append(query);
		}
		WString ref = url.getRef();
		if (ref.length())
		{
			fileName.append(chPound);
			fileName.append(ref);
		}

		if (usingProxy)
		{
			WString result = url.getProtocol() + "://" + url.getHost();
			if (url.getPort() != -1) 
				result += ":" + Integer::toString(url.getPort());
			return result + fileName;
		}
		else
			return fileName;
	}

	void HttpClient::writeRequests(MessageHeader& head)
	{
		requests = head;	
		requests.print(*serverOutput);

		//  debug stuff
		//	ByteArrayOutputStream out;
		//	PrintStream p(out);
		//	requests.print(p);
		//	ByteBuffer* b = out.toByteArray();
		//	std::cout << b->bytes();
	}

	bool HttpClient::parseHTTP(MessageHeader& responses)
	{
		try
		{
			if(serverInput!=0)
				delete serverInput;
			serverInput = &serverSocket->getInputStream();
			serverInput = new BufferedInputStream(*serverInput);
			// the socket owns the original stream
			((BufferedInputStream*)serverInput)->setOwnsMember(false);
			// fix memory leak keep buffered input stream
			// for deleting afterwards
			return parseHTTPHeader(responses);
		}
		catch (IOException& e)
		{
			closeServer();
			if (!failedOnce)
			{
				failedOnce = true;
				openServer();
				writeRequests(requests);
				return parseHTTP(responses);
			}
			else
				throw e;
		}
	}

	void HttpClient::SSLConnect()
	{
	}

	bool HttpClient::parseHTTPHeader(MessageHeader& responses)
	{
		keepAliveConnections = -1;
		keepAliveTimeout     = 0;
		bool ret             = false;
		char b[8];

		try
		{
			int nread = 0;
			serverInput->mark(10);
			while (nread < 8)
			{
				int r = serverInput->read(b,8,nread,8-nread);
				if (r<0)
					break;
				nread += r;
			}
			WString keep;

			ret= b[0]== 'H' && b[1] == 'T' && b[2] == 'T' && 
				b[3] == 'P' && b[4] == '/' && b[5] == '1' && b[6] == '.';
			// this should be a static cast
			serverInput->reset();
			if (ret)// is valid HTTP - response started w/ "HTTP/1."
			{

				responses.parseHeader(*serverInput);

				MessageHeader::value_pair v;
				if (usingProxy)
					v = responses.findValue("Proxy-Connection");

				if (v.first == false)
					v = responses.findValue("Connection");

				if (v.first == true)
				{
					keep = v.second;
					if (keep.toLowerCase() == "keep-alive")
					{
						v = responses.findValue("Keep-Alive");
						if (v.first)
						{
							HeaderParser p(v.second);
							keepAliveConnections = p.findInt("max",5);
							keepAliveTimeout = p.findInt("timeout",5);
						}
					}
				}
				else if (b[7] != '0')
				{
					if (keep.length())
					{
						keepAliveConnections = 1;
					}
					else 
						keepAliveConnections = 2;
				}
			}
			else if (nread != 8)
			{
				if (!failedOnce)
				{
					failedOnce = true;
					closeServer();
					openServer();
					writeRequests(requests);
					return parseHTTP(responses);
				}
				throw SocketException("Unexpected end of file from server");
			}
			else
				responses.set("Content-type", "unknown/unknown");
		}
		catch (IOException&e)
		{
			throw e;
		}
		int code = -1;
		try
		{
			WString resp;
			MessageHeader::value_pair v;
			v = responses.getValue(0);
			if (v.first)
			{
				resp = v.second;
				int ind;
				ind = v.second.find_first_of(' ');
				if (ind != -1)
				{
					while (v.second[ind] == ' ')
						ind++;
					code = Integer::parseInt(resp.substring(ind,ind+3));
				}
			}
		}
		catch (IOException&)
		{
		}
		if (code == HTTP_CONTINUE)
			return parseHTTPHeader(responses);

		MessageHeader::value_pair v;
		int cl = -1;
		try
		{
			v = responses.findValue("Transfer-Encoding");
		} catch (Exception&)
		{
		}
		if (v.first == true  && v.second.compareToIgnoreCase("chunked")==0)
		{
			// set up a chunked input stream
			//180604 RP the following line was commented since rfc2616 explicitly states that 
			//          content-length MUST be ignored in chunked mode
			//responses.set("content-length", Integer::toString(serverInput->available()));


			// the chunk header will be read at the end
			// we do not read all the data here in memory 
			// in order to pass this chunk header
			// the java implementation does this.
			// but this is a considerable memory footprint
			// the ChunkedInputStream will call the responses.mergeheader itself
			serverInput = new ChunkedInputStream(serverInput,responses);
			((ChunkedInputStream*)serverInput)->setOwnsMember(false);
			/*
			* If keep alive not specified then close after the stream
			* has completed.
			*/
			if (keepAliveConnections < 0) 
				keepAliveConnections = 1; 
			keepingAlive = true;
			failedOnce = false;
			// TODO what to do with contentLength
		}
		else
		{
			/* 
			* If it's a keep alive connection then we will keep 
			* (alive if :-
			* 1. content-length is specified, or 
			* 2. "Not-Modified" or "No-Content" responses - RFC 2616 states that  
			*    204 or 304 response must not include a message body. 
			*/
			try
			{
				v = responses.findValue("content-length");
				if (v.first)
					cl = Integer::parseInt(v.second);
			} catch (Exception&)
			{
			}
			if (keepAliveConnections > 1 && 
				(cl >= 0 ||
				code == HttpURLConnection::HTTP_NOT_MODIFIED || 
				code == HttpURLConnection::HTTP_NO_CONTENT)) 
			{ 
				keepingAlive = true;
			} 
			else if (keepingAlive) 
			{
				/* Previously we were keeping alive, and now we're not.  Remove
				* this from the cache (but only here, once) - otherwise we get
				* multiple removes and the cache count gets messed up.
				*/
				keepingAlive=false;
			}
		}
//		090715 RP if keepalive we must have a keepalivestream, even if cl==0, else we run into a blocking socket read
//		120125 RP the above fix was a BAD idea since we never continue reading in chunked mode - undo
		if (cl > 0)
		{

			ProgressEntry *pe=new ProgressEntry();
			pe->update(0,cl);
			if (keepingAlive)
			{
				serverInput = new KeepAliveInputStream(serverInput,pe,this);
				((KeepAliveInputStream*)serverInput)->setOwnsMember(true);
				failedOnce = false;
			}		
			else // 070912 RP use a metered input for non-keepalive and all should be well!
			{
				serverInput = new MeteredInputStream(serverInput,pe);
				((MeteredInputStream*)serverInput)->setOwnsMember(true);
			}

		}
		// todo wrap meteredstream
		return ret;
	}

	InputStream* HttpClient::getInputStream()
	{
		return serverInput;
	}

	OutputStream* HttpClient::getOutputStream()
	{
		return serverOutput;
	}

	WString HttpClient::toString()
	{	
		return WString("HttpClient") + "(" +  url.toString() + ")";
	}

	bool HttpClient::isKeepingAlive()
	{
		return getHttpKeepAliveSet() && keepingAlive;
	}

	void HttpClient::closeServer()
	{
		try
		{
			keepingAlive= false;

			if (serverInput)
			{
				delete serverInput;
				serverInput=0;
			}

			if (serverOutput)
			{
				delete serverOutput;
				serverOutput=0;
				delete bufferedOut; // buffered out
				bufferedOut=0;
			}

			if (serverSocket)
			{
				if (!isKeepingAlive())
				{
					serverSocket->close();
					delete serverSocket;
					serverSocket=0;
				}
			}
			serverSocket = NULL;
			serverInput  = NULL;
			serverOutput = NULL;
			bufferedOut  = NULL;
			serverSocket = NULL;

		} catch(Exception&)	{
			// 080403 RP added cleanup for broken http connection
			serverSocket = NULL;
			serverInput  = NULL;
			serverOutput = NULL;
			bufferedOut  = NULL;
			serverSocket = NULL;
		}
	}

	WString HttpClient::getProxyHostUsed()
	{
		if (!usingProxy)
			return "";
		else
			return instProxy;
	}

	int HttpClient::getProxyPortUsed()
	{
		return instProxyPort;
	}

	void HttpClient::validateCache()
	{
		getKeepAliveCache().validateCache();
	}

	KeepAliveCache & HttpClient::getKeepAliveCache()
	{		
		return KeepAliveCache::getKeepAliveCache();
	}

} // namespace JDF
