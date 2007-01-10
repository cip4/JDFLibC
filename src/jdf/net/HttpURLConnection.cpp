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

#include <xercesc/util/XMLUniDefs.hpp>

#include <jdf/io/InputStream.h>
#include <jdf/lang/Integer.h>
#include <jdf/lang/Exception.h>

#include <jdf/net/HttpURLConnection.h>



XERCES_CPP_NAMESPACE_USE

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

	const int HttpURLConnection::HTTP_OK = 200;
	const int HttpURLConnection::HTTP_CREATED = 201;
	const int HttpURLConnection::HTTP_ACCEPTED = 202;
	const int HttpURLConnection::HTTP_NOT_AUTHORITATIVE = 203; 
	const int HttpURLConnection::HTTP_NO_CONTENT = 204;
	const int HttpURLConnection::HTTP_RESET = 205;
	const int HttpURLConnection::HTTP_PARTIAL = 206;
	const int HttpURLConnection::HTTP_MULT_CHOICE = 300;
	const int HttpURLConnection::HTTP_MOVED_PERM = 301;
	const int HttpURLConnection::HTTP_MOVED_TEMP = 302;
	const int HttpURLConnection::HTTP_SEE_OTHER = 303;
	const int HttpURLConnection::HTTP_NOT_MODIFIED = 304;
	const int HttpURLConnection::HTTP_USE_PROXY = 305;
	const int HttpURLConnection::HTTP_BAD_REQUEST = 400;
	const int HttpURLConnection::HTTP_UNAUTHORIZED = 401;
	const int HttpURLConnection::HTTP_PAYMENT_REQUIRED = 402;
	const int HttpURLConnection::HTTP_FORBIDDEN = 403;
	const int HttpURLConnection::HTTP_NOT_FOUND = 404;
	const int HttpURLConnection::HTTP_BAD_METHOD = 405;
	const int HttpURLConnection::HTTP_NOT_ACCEPTABLE = 406;
	const int HttpURLConnection::HTTP_PROXY_AUTH = 407;
	const int HttpURLConnection::HTTP_CLIENT_TIMEOUT = 408;
	const int HttpURLConnection::HTTP_CONFLICT = 409;
	const int HttpURLConnection::HTTP_GONE = 410;
	const int HttpURLConnection::HTTP_LENGTH_REQUIRED = 411;
	const int HttpURLConnection::HTTP_PRECON_FAILED = 412;
	const int HttpURLConnection::HTTP_ENTITY_TOO_LARGE = 413;
	const int HttpURLConnection::HTTP_REQ_TOO_LONG = 414;
	const int HttpURLConnection::HTTP_UNSUPPORTED_TYPE = 415;
	const int HttpURLConnection::HTTP_INTERNAL_ERROR = 500;
	const int HttpURLConnection::HTTP_NOT_IMPLEMENTED = 501;
	const int HttpURLConnection::HTTP_BAD_GATEWAY = 502;
	const int HttpURLConnection::HTTP_UNAVAILABLE = 503;
	const int HttpURLConnection::HTTP_GATEWAY_TIMEOUT = 504;
	const int HttpURLConnection::HTTP_VERSION = 505;

	const char* HttpURLConnection::methods[] = {"GET", "POST", "HEAD", "OPTIONS", "PUT", "DELETE", "TRACE"};
	static const int nrMethods = 7;

	bool HttpURLConnection::followRedirects = true;

	HttpURLConnection::	HttpURLConnection(const URL& u) :
	URLConnection(u)
	{
		method          = "GET";
		responseCode    = -1;
		followRedirects = true;
		instanceFollowRedirects = followRedirects;
	}

	void HttpURLConnection::setFollowRedirects(bool set) 
	{
		followRedirects = set;
	}

	bool HttpURLConnection::getFollowRedirects()
	{
		return followRedirects;
	}

	void HttpURLConnection::setInstanceFollowRedirects(bool followRedirects)
	{
		instanceFollowRedirects = followRedirects;
	}

	bool HttpURLConnection::getInstanceFollowRedirects()
	{
		return instanceFollowRedirects;
	}


	void HttpURLConnection::setRequestMethod(const WString& method)
	{
		if (connected) {
			throw ProtocolException("Can't reset method: already connected");
		}
		// This restriction will prevent people from using this class to 
		// experiment w/ new HTTP methods.  But it should 
		// be placed for security - the request String could be
		// arbitrarily long.

		for (int i = 0; i < nrMethods; i++) 
		{
			if (WString(methods[i]) == method) 
			{
				this->method = method;
				return;
			}
		}
		throw ProtocolException("Invalid HTTP method: " + method);
	}

	WString HttpURLConnection::getRequestMethod()
	{
		return method;
	}

	int HttpURLConnection::getResponseCode()
	{
		if (responseCode != -1) 
		{
			return responseCode;
		}
		// make sure we've gotten the headers
		getInputStream();
		value_pair v = getHeaderField(0);
		WString resp = v.second;

		/* should have no leading/trailing LWS
		* expedite the typical case by assuming it has
		* form "HTTP/1.x <WS> 2XX <mumble>"
		*/
		int ind;
		try 
		{	
			ind = resp.find_first_of(chSpace);
			if (ind != -1)
			{
				while(resp[ind] == chSpace)
					ind++;

				responseCode = Integer::parseInt(resp.substring(ind,ind+3));
				responseMessage = resp.substring(4).trim(); 
			}
			return responseCode;
		}
		catch (Exception& )
		{ 
			return responseCode;
		}
	}

	WString HttpURLConnection::getResponseMessage()
	{
		getResponseCode();
		return responseMessage;
	}

	long HttpURLConnection::getHeaderFieldDate(const WString& name, long Default)
	{
		// not yet implemented
		return 0;
	}



} // namespace JDF
