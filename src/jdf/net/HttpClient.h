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

/*******************************************************************************
* 
* Description:
*
*
******************************************************************************/

#ifndef I_JDF_HTTPCLIENT_H
#define I_JDF_HTTPCLIENT_H

/******************************************************************************
*	Includes
******************************************************************************/ 
#include "NetworkClient.h"

#include "MessageHeader.h"
#include "URL.h"

#include <jdf/util/RegexpPool.h>
#include <jdf/net/KeepAliveCache.h>

// History of changes
// 200802 RP/NV closeServer() bug fix for broken connections

namespace JDF
{
	
/******************************************************************************
*	Forward declarations
	******************************************************************************/ 
	class InputStream;
	class OutputStream;
	class MeteredInputStream;
	
	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Classes
	******************************************************************************/ 
	
	/**
	* NetworkClient for HTTP Procotol
	* @nosubgrouping
	*/
	class JDFTOOLS_EXPORT HttpClient : public NetworkClient
	{
	public:
		
	/** 
	* @name Constructors
		*/
		/*@{*/
		
		HttpClient();
		virtual ~HttpClient();
		/*@}*/ 
		void create(const URL& url, const WString& proxy, int proxyPort, bool proxyDisabled=false);
		
		/**
		* @return true iff http keep alive is set (i.e. enabled).  Defaults
		*		to false if the system property http.keepAlive isn't set.
		*/
		
		static bool getHttpKeepAliveSet();

		/**
		* set the system property to keepalive
		*/
		static void setHttpSystemKeepAlive(bool bKeepalive);
			
		/**
		* We're very particular here about what our InputStream to the server
		* looks like for reasons that are apparent if you can decipher the
		* method parseHTTP().  That's why this method is overidden from the
		* superclass.
		*/
		void openServer(const WString& server, int port);
		
		/**
		* Use only on connections in error. 
		*/
		void closeServer();
		
		/* This class has no public constructor for HTTP.  This method is used to
		* get an HttpClient to the specifed URL.  If there's currently an
		* active HttpClient to that server/port, you'll get that one.
		*/
		
		static HttpClient* New(const URL& url,bool useCache);
		static HttpClient* New(const URL& url);
		static HttpClient* New(const URL& url,WString proxy, int proxyPort, bool useCache);
	
		static void validateCache();

		static void finish(HttpClient* hc);
	
		/**
		* return it to the cache as still usable, if:
		* 1) It's keeping alive, AND
		* 2) It still has some connections left, AND
		* 3) It hasn't had a error (PrintStream.checkError())
		* 4) It hasn't timed out
		*
		* If this client is not keepingAlive, it should have been
		* removed from the cache in the parseHeaders() method.
		*/
		void finished();
		
		InputStream* getInputStream();
		OutputStream* getOutputStream();
		
		WString toString();
		
		virtual WString getURLFile();
		
		void writeRequests(MessageHeader& head);
		
		/** 
		* Parse the first line of the HTTP request.  It usually looks
		* something like: "HTTP/1.0 <number> comment\r\n".
		*/
		
		bool parseHTTP(MessageHeader& responses);
		
		bool isKeepingAlive();
		
		/**
		* @return the proxy host being used for this client, or null
		*		if we're not going through a proxy
		*/
		
		WString getProxyHostUsed();
		
		/**
		* @return the proxy port being used for this client.  Meaningless
		*		if getProxyHostUsed() gives null.
		*/
		virtual int getProxyPortUsed();
		
		bool isUsingProxy() {return usingProxy;}
		
		/**
		* Note: this should be in a subclass
		*/
		
		void SSLConnect();
		
		/** 
		* are we using proxy in this instance?
		*/
		
		bool usingProxy;
		
	protected:
		
		void create(const URL& url, bool proxyDisabled);
		
		/**
		* Return default port number (subclasses may override)
		*/
		
		virtual int getDefaultPort();


	
	private:
		
		void openServer();
		void create(const URL& url);
		//	void privilegedOpenServer(const std::string proxyHost, const int proxyPort);
		//	void superOpenServer(const std::string proxyHost, const int proxyPort);
		//	void privilegedSuperOpenServer(const std::string proxyHost, const int proxyPort);
		bool isLoopback(const WString& host);
		bool parseHTTPHeader(MessageHeader& responses);
		
	protected:
		
		virtual WString getProxyHost();
		virtual int getProxyPort();

		RegexpPool& getDontProxy();

		bool putInKeepAliveCache();
		
		
	protected:
		
	/**
	* All proxying (generic as well as instance specific) may be
	* disabled through use of this flag
		*/
		
		bool proxyDisabled;
		
		/**
		* whether this httpclient comes from the cache
		*/
		
		bool cachedHttpClient;
		
		/**
		* this is a keep-alive connection
		*/
		
		bool keepingAlive;
		
		/**
		* Number of keep-alives left
		*/
		
		int keepAliveConnections;
		
		/**
		* 
		*/
		int keepAliveTimeout;
		
		/**
		* URL being fetched
		*/
		
		URL url;
		
	private:
		
	/**
	* Http requests we send
		*/
		MessageHeader requests;
		
		/**
		* regexp pool of hosts for which we should connect directly, not 
		* proxy these are initialized from a property
		*/
		RegexpPool dontProxy;
		
		/**
		* The string source of don't proxy
		*/
		
		WString dontProxySource;
		
		/**
		* if we've had an io error
		*/
		
		bool failedOnce;
		
		/**
		* target host for this URL
		*/
		
		WString host;
		
		/**
		* target port for this URL
		*/
		
		int port;
		
		WString instProxy;
		int     instProxyPort;
				
		/**
		* Response code for CONTINUE
		*/
		
		static const int HTTP_CONTINUE;
		
		/** 
		* Default port number for http daemons
		*/
		static const int httpPortNumber;
		
		static KeepAliveCache & getKeepAliveCache();
};

/******************************************************************************
*	Prototypes
******************************************************************************/ 


/******************************************************************************
*	Implementation
******************************************************************************/ 


} // namespace JDF

#endif /* I_JDF_HTTPCLIENT_H */
