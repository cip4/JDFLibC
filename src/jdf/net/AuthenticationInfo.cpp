/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
#include "AuthenticationInfo.h"

#include "URL.h"
#include "PlainHttpURLConnection.h"

#include <jdf/util/Cache.h>
#include <jdf/util/RegisterCleanup.h>
#include <jdf/lang/Integer.h>
#include <jdf/lang/Mutex.h>

#include <xercesc/util/PlatformUtils.hpp>


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

const char AuthenticationInfo::SERVER_AUTHENTICATION = 's';
const char AuthenticationInfo::PROXY_AUTHENTICATION = 'p';

typedef Cache<WString,AuthenticationInfo,ElfHash> AuthenticationInfoCache;

static AuthenticationInfoCache* cache = 0;
static RegisterCleanup authenticationInfoCacheCleanup;

static Mutex* authenticationInfoMutex = 0;
static RegisterCleanup authenticationInfoMutexCleanup;


static AuthenticationInfoCache& gAuthenticationInfoCache()
{
    if (!cache)
    {
        AuthenticationInfoCache* tmpCache = new AuthenticationInfoCache(20);
        if (XMLPlatformUtils::compareAndSwap((void**)&cache, tmpCache, 0))
        {
            // Some other thread beat us to it, so let's clean up ours.
            delete tmpCache;
        }
        else
        {
			authenticationInfoCacheCleanup.registerCleanup(AuthenticationInfo::reinitAuthenticationInfoCache);
        }
    }
    return *cache;
}

static Mutex& gAuthenticationInfoCacheMutex()
{
    if (!authenticationInfoMutex)
    {
        Mutex* tmpMutex = new Mutex;
        if (XMLPlatformUtils::compareAndSwap((void**)&authenticationInfoMutex, tmpMutex, 0))
        {
            // Some other thread beat us to it, so let's clean up ours.
            delete tmpMutex;
        }
        else
        {
            // This is the real mutex.  Register it for deletion at Termination.
			authenticationInfoMutexCleanup.registerCleanup(AuthenticationInfo::reinitAuthenticationInfoMutex);
        }
        
    }
    return *authenticationInfoMutex;
}


AuthenticationInfo::AuthenticationInfo(char type, WString host, int port, WString realm)
{
	this->type = type;
	this->host = host;
	this->port = port;
	this->realm = realm;
	this->path = "";
}

AuthenticationInfo::AuthenticationInfo(char type, const URL& url, WString realm) 
{
   	this->type  = type;
	this->host  = url.getHost();
	this->port  = url.getPort();
	this->realm = realm;

	WString urlPath = url.getPath();
	if (urlPath.length() == 0)
	    this->path = urlPath;
	else 
	{
	    // reduce the path to the root of where we think the
	    // authorization begins. This could get shorter as
	    // the url is traversed up following a successful challenge.
	    int sepIndex = urlPath.find_last_of('/');
	    int targetSuffixIndex = urlPath.find_last_of('.');
	    if (sepIndex != -1)
			if (sepIndex < targetSuffixIndex)
				this->path = urlPath.substring(0, sepIndex+1);
			else
				this->path = urlPath;
	    else
			// this should not be possible if the URL is not malformed
			this->path = "";
	}
}

AuthenticationInfo* AuthenticationInfo::getServerAuth(const URL& url)
{
	WString key = WString(SERVER_AUTHENTICATION) + ":" + url.getHost() 
		+ ":" + Integer::toString(url.getPort());
	return getAuth(key, url);
}

AuthenticationInfo* AuthenticationInfo::getServerAuth(const URL& url, WString realm) 
{
	WString key = WString(SERVER_AUTHENTICATION) + ":" + url.getHost() 
		+ ":" + Integer::toString(url.getPort()) + ":" + realm;
	return getAuth(key, url);
}

AuthenticationInfo* AuthenticationInfo::getAuth(WString key, const URL& url) 
{
	Synchronized sync(gAuthenticationInfoCacheMutex());

	AuthenticationInfo* result = (AuthenticationInfo*) gAuthenticationInfoCache().get(key);
	if (result != NULL) 
	{
		WString p = url.getPath();
	    if (result->path.length()) 
		{
			// TO BE Reviewed startsWith
			if (!p.startsWith(result->path) )
			{
			    // This will force a WWW-Authenticate from the server
			    // which can then be used to lookup the correct cached
			    // entry 
				result = NULL;
			}
	    }
	}
	if (result)
		return result->copy();
	else
		return NULL;
}

AuthenticationInfo* AuthenticationInfo::getProxyAuth(WString host, int port)
{
	Synchronized sync(gAuthenticationInfoCacheMutex());

	WString key = WString(PROXY_AUTHENTICATION) + ":" + host + ":" + Integer::toString(port);
	AuthenticationInfo* result = (AuthenticationInfo*) gAuthenticationInfoCache().get(key);
	if (result)
		return result->copy();
	else
		return NULL;
}

AuthenticationInfo* AuthenticationInfo::getProxyAuth(WString host, int port, WString realm) 
{
	Synchronized sync(gAuthenticationInfoCacheMutex());

	WString key = WString(PROXY_AUTHENTICATION) + ":" + host + ":" + Integer::toString(port) + ":" + realm;
	AuthenticationInfo* result = (AuthenticationInfo*) gAuthenticationInfoCache().get(key);
	if (result)
		return result->copy();
	else
		return NULL;
}

void AuthenticationInfo::addToCache()
{
	Synchronized sync(gAuthenticationInfoCacheMutex());

	gAuthenticationInfoCache().push(cacheKey(true), this);
	if (supportsPreemptiveAuthorization()) 
	{
		gAuthenticationInfoCache().push(cacheKey(false), this->copy());
	}
}

void AuthenticationInfo::removeFromCache() 
{
	Synchronized sync(gAuthenticationInfoCacheMutex());

	// we can safely delete it since we are working on a copy
	delete gAuthenticationInfoCache().remove(cacheKey(true));
	if (supportsPreemptiveAuthorization()) 
	{
		delete gAuthenticationInfoCache().remove(cacheKey(false));
	}
}

bool AuthenticationInfo::setHeaders(PlainHttpURLConnection* conn, HeaderParser& p) 
{
	conn->setAuthenticationProperty(getHeaderName(), getHeaderValue());
	return true;
}

WString AuthenticationInfo::cacheKey(bool includeRealm)
{
    // This must be kept in sync with the getXXXAuth() methods in this class.

	if (includeRealm) {
		return WString(type) + ":" + host + ":" + Integer::toString(port) + ":" + realm;
	} else {
		return WString(type) + ":" + host + ":" + Integer::toString(port);
	}
}

void AuthenticationInfo::reinitAuthenticationInfoCache()
{
	delete cache;
	cache = 0;
}
void AuthenticationInfo::reinitAuthenticationInfoMutex()
{
	delete authenticationInfoMutex;
	authenticationInfoMutex = 0;
}



} // namespace JDF
