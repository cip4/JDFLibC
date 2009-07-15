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
#include "Authenticator.h"

#include <jdf/net/KeepAliveCache.h>
#include <jdf/net/HTTPClient.h>
#include <jdf/lang/Integer.h>
#include <jdf/lang/Synchronized.h>


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

const int KeepAliveCache::LIFETIME = 15000;
static KeepAliveCache * theCache=0;

	KeepAliveKey::~KeepAliveKey()
	{}

	KeepAliveEntry::~KeepAliveEntry()
	{}

	KeepAliveClientList::~KeepAliveClientList()
	{}

	KeepAliveCache::~KeepAliveCache()
	{
		std::list<CacheItem>::iterator it = mCache.begin();
		while (it != mCache.end())
		{

			while ((*it).second.size())
			{
				KeepAliveEntry entry =  (*it).second.mClients.front();
				entry.mClient->closeServer();
				delete entry.mClient;
				entry.mClient = NULL;
				(*it).second.mClients.pop();
			}
			it = mCache.erase(it);
		}
	}

	void KeepAliveCache::terminate()
	{
		if(theCache)
		{
			delete(theCache);
		}
		theCache=0;
	}

	KeepAliveCache& KeepAliveCache::getKeepAliveCache()
	{
		if(!theCache)
			theCache=new KeepAliveCache();
		return *theCache;
	}


	KeepAliveEntry::KeepAliveEntry(HttpClient* hc, unsigned long startTime)
{
	mClient = hc;
	mStartTime = startTime;
}


KeepAliveKey::KeepAliveKey(const URL& url)
{
	protocol = url.getProtocol();
	host = url.getHost();
	port = url.getPort();
}

bool KeepAliveKey::operator==(const KeepAliveKey& k)
{
	return host == k.host && protocol == k.protocol && port == k.port;
}


KeepAliveClientList::KeepAliveClientList()
{
	PlatformUtils::value_pair res = PlatformUtils::getProperty("http.keepAliveTimeout");
	if (res.first == false)
		mNap = KeepAliveCache::LIFETIME;
	else
		mNap = Integer::parseInt(res.second);
	mClientsActive = 0;
}


HttpClient* KeepAliveClientList::get()
{
	if (mClients.empty())
		return NULL;

	KeepAliveEntry entry = mClients.front();
	mClients.pop();
	mClientsActive++;
	return entry.mClient;
}

bool KeepAliveClientList::put(HttpClient* hc)
{
	if (mClientsActive + mClients.size() > KeepAliveCache::getMaxConnections())
	{
		return false;
	}
	if (mClientsActive > 0)
		mClientsActive--;
	mClients.push(KeepAliveEntry(hc,PlatformUtils::getCurrentMillis()));
	return true;
}

int KeepAliveClientList::size()
{
	return mClients.size();
}

int KeepAliveCache::getMaxConnections()
{
	PlatformUtils::value_pair res = PlatformUtils::getProperty("http.maxConnections");
	if (res.first == false)
		return 15;
	return Integer::parseInt(res.second);
}


KeepAliveCache::KeepAliveCache()
{
}


bool KeepAliveCache::put(const URL& url, HttpClient* hc)
{
	Synchronized sync(mCriticalSection);

	std::list<CacheItem>::iterator it;
	KeepAliveKey key(url);
	for (it = mCache.begin(); it!= mCache.end(); it++)
	{
		if ((*it).first == key)
		{
			return (*it).second.put(hc);
		}
	}
	CacheItem ci;
	ci.first = key;
	bool res = ci.second.put(hc);
	if (res)
		mCache.push_back(ci);
	return res;
}

HttpClient* KeepAliveCache::get(const URL& url)
{
	Synchronized sync(mCriticalSection);

	std::list<CacheItem>::iterator it;
	KeepAliveKey key(url);

	for (it = mCache.begin(); it!= mCache.end(); it++)
	{
		if ((*it).first == key)
		{
			if ((*it).second.size())
			{
				HttpClient* hc = (*it).second.get();
				if ( (*it).second.size() == 0)
					mCache.erase(it);
				return hc;
			}
			break;
		}
	}
	return 0;
}

void KeepAliveCache::validate()
{
	HttpClient::validateCache();
}

void KeepAliveCache::validateCache()
{
	Synchronized sync(mCriticalSection);

	std::list<CacheItem>::iterator it;

	it = mCache.begin();
	while (it != mCache.end())
	{
		unsigned long currentMillis = PlatformUtils::getCurrentMillis();

		while ((*it).second.size())
		{
			KeepAliveEntry entry =  (*it).second.mClients.front();
			if (currentMillis - entry.mStartTime > (*it).second.mNap)
			{
				entry.mClient->closeServer();
				delete entry.mClient;
				entry.mClient = NULL;
				(*it).second.mClients.pop();
			}
			else 
				break;
		}
		if ((*it).second.size() == 0)
			it = mCache.erase(it);
		else
			it++;
	}
}

} // namespace JDF
