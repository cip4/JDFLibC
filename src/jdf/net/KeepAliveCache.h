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

#ifndef I_JDF_KEEPALIVECACHE_H
#define I_JDF_KEEPALIVECACHE_H

/******************************************************************************
*	Includes
******************************************************************************/ 
#include <jdf/util/PlatformUtils.h>
#include <jdf/net/URL.h>
#include <jdf/lang/Mutex.h>

#include <list>
#include <queue>

namespace JDF
{
	
/******************************************************************************
*	Forward declarations
******************************************************************************/ 

class HttpClient;

/******************************************************************************
*	Defines and constants
******************************************************************************/ 


/******************************************************************************
*	Typedefs
******************************************************************************/ 


/******************************************************************************
*	Classes
******************************************************************************/ 

class KeepAliveKey
{
public:

	KeepAliveKey() { port=-1;}
	KeepAliveKey(const URL& url);
	virtual ~KeepAliveKey();
	bool operator==(const KeepAliveKey& k);

private:
	WString protocol;
	WString host;
	int	    port;
};

class KeepAliveEntry
{

public:

	KeepAliveEntry(HttpClient* hc, unsigned long startTime);
	virtual ~KeepAliveEntry();

	HttpClient* mClient;
	unsigned long mStartTime;
};

class KeepAliveClientList
{
public:

	KeepAliveClientList();
	virtual ~KeepAliveClientList();

	HttpClient* get();
	bool put(HttpClient* hc);
	int size();

	//sleep time in milliseconds before cache clear
	int mNap;

	// #presently checked out clients that we know about
	int mClientsActive;

	std::queue<KeepAliveEntry> mClients;

};

/**
 * A class that implements a cache of idle Http connections for keep-alive
 *
 */
class JDFTOOLS_EXPORT KeepAliveCache 
{

public:

	static const int LIFETIME;

   /* maximum # keep-alive connections to maintain at once
     * This should be 2 by the HTTP spec, but we can hog bandwidth
     * by cranking it up.  It can be reset by setting system property
     * "http.maxConnections".
     */
	static int getMaxConnections();

	void validateCache();
	static void terminate();
	static void validate();

	KeepAliveCache();
	virtual ~KeepAliveCache();
	static KeepAliveCache& getKeepAliveCache();


	bool put(const URL& url,HttpClient* hc);

	HttpClient* get(const URL& url);

private:

	typedef std::pair<KeepAliveKey,KeepAliveClientList > CacheItem;

	std::list<CacheItem> mCache;
	Mutex mCriticalSection;
};

/******************************************************************************
*	Prototypes
******************************************************************************/ 


/******************************************************************************
*	Implementation
******************************************************************************/ 


} // namespace JDF

#endif /* I_JDF_KEEPALIVECACHE_H */

