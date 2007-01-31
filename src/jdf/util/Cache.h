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

#ifndef I_JDF_CACHE_H
#define I_JDF_CACHE_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>

#include "hmap.h"
#include "hashfun.h"

#include <list>
#include <algorithm>


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

/**
 * The cache class implements a simple caching mechanism with
 * "least recently used" (LRU) replacement. It is useful for cases
 * in which you have some memory to spare and you wish to speed up
 * access to frequently used resources, of which not all will fit into
 * available memory. Thus, you know you have room to store all possible
 * resources in memory, so you want to store some of them. The <code>Cache</code>
 * class helps you to manage the storage in memory of some subset of all
 * possible resources and therefore speed up your resource accesses,
 * <p>
 * The <code>Cache</code> class maintains a list of the last N resources
 * where N is the cache depth. When the N+1th resource is created , the <code>
 * Cache</code> will remove the least recentlt used (LRU) resource of the
 * existing N resources in memory to make room for the new entry.Thus at any time
 * there are a maximum of N resources taking up memory, and they are precisely
 * the last N resources that were needed by the application.
 * <p>
 * The reason for keeping the last N resources in memory is due to a 
 * property of many program known as "temporal locality of reference ". 
 * In plain English, this means that a program tends to use resources that it
 * has already (recently) used. 
 * If, however, the application does not exhibit good temporal locality of 
 * reference, then a cache may be of little or no use. Comparing the number of
 * cache "hits" to the total number of accesses is usually a good benchmark of 
 * the cache's utility. 
 * <p>
 * To use the <code>Cache</code> class you need to provide three things:
 * <ul>
 * <li>A "key class". This key will be used as a label for the resources that you
 * you wish to cache. For example, if the resources we are working with are fonts,
 * the "key label" may be the alphabetic name of the font, such as "MS Sans Serif 10".
 * Your key class needs to have a meaningful equality (==) operator.
 * </li>
 * <li> A "type class:, This is the type of the values in the cache</li>
 * <li> And a hash function. The hash function is used for hashing the keys
 * </ul>
 * @ingroup util
 * @nosubgrouping
 */

template<class K, class T, class hashfun=HashFun<K> >
class Cache
{
public:

/** 
 * @name Constructors
 */
/*@{*/
	Cache(unsigned int depth, hashfun f = hashfun() );
/*@}*/ 
	virtual ~Cache() { clear();}

	T*   load(const K&  key);
    void push(const K& key,T* value);
	T*   get(const K& key);
	T*   remove(const K& key);
	void discard(const K& key);
	//void flush(void);
	unsigned int  depth(void) const;
	void changeDepth(unsigned int depth);

	unsigned int hits(void) const;
	unsigned int misses(void) const;
	unsigned int cachedItems(void) const;
	void clear(void);

protected:

	virtual void discardItem(T* value);
	void discardLRUItem();
	void addCacheItem(const K& key, T* value);
	void markRecentlyUsed(const K& key);

	typedef hmap<K,T*,hashfun > CacheMap;
	CacheMap mDict;
	std::list<typename CacheMap::value_type> mLRUList;
	unsigned int mDepth;
	unsigned int mMisses;
	unsigned int mHits;
};


template <class K, class T>
class keypair
{
public:
	keypair(K k) { key=k;}
	bool operator()(std::pair<K,T*> x) { return x.first == key; }

private:
	K key;
};


template <class K, class T,class hashfun>
Cache<K,T,hashfun>::Cache(unsigned int depth, hashfun f) :
	mDict	(f),
	mDepth	(depth),
	mMisses	(0),
	mHits	(0)
{
}

template <class K, class T,class hashfun>
T* Cache<K,T,hashfun>::load(const K&  key)
{
	// first look for the key in the dictionary.
	// If found, replace the value of the cache with the new value.
	// Otherwise we have to add the new entry to the cahce

	typename CacheMap::iterator it = mDict.find(key);

	if (it != mDict.end())
	{
		mHits++;
		markRecentlyUsed(key);
		return (*it).second;
	}
	else
	{
		mMisses++;
		//get a new item by constructing it as T(key)
		T* value = new T(key);
		// remove the LRU entry from the dictionary if we've exceeded our depth
		if (mLRUList.size() >= mDepth)
		{
			discardLRUItem();
		}
		// add new item to dictionary
		addCacheItem(key,value);
		return value;
	}
}

template <class K, class T,class hashfun>
void Cache<K,T,hashfun>::push(const K& key, T* value)
{
	// first look for the key in the dictionary.
	// If found, replace the value of the cache with the new value.
	// Otherwise we have to add the new entry to the cahce

	typename CacheMap::iterator it = mDict.find(key);

	if (it != mDict.end())
	{
		typename std::list<typename CacheMap::value_type>::iterator it2;
		it2 = std::find_if (mLRUList.begin(), mLRUList.end(), keypair<K,T>(key));

		if (it2 != mLRUList.end())
		{
			discardItem((*it2).second);
			(*it2).second = value; 
			mLRUList.push_back(*it2);
			mLRUList.erase(it2);
		}
		(*it).second = value;
	}
	else
	{
		if (mLRUList.size() >= mDepth)
		{
			discardLRUItem();
		}
		addCacheItem(key,value);
	}
}

template <class K, class T,class hashfun>
T* Cache<K,T,hashfun>::get(const K& key)
{
	// first look for the key in the dictionary.
	// If found, it's a cache hit and we just return
	// the associated resource.

	typename CacheMap::iterator it = mDict.find(key);

	if (it != mDict.end())
	{
		mHits++;
		markRecentlyUsed(key);
		return (*it).second;
	}
	else
	{
		mMisses++;
		return NULL;
	}
}


template <class K, class T,class hashfun>
T* Cache<K,T,hashfun>::remove(const K& key)
{
	typename CacheMap::iterator it = mDict.find(key);

	if (it != mDict.end())
	{
		T* value = (*it).second;
		mDict.erase(it);
		typename std::list<typename CacheMap::value_type>::iterator itlist;
		itlist = std::find_if (mLRUList.begin(), mLRUList.end(), keypair<K,T>(key));
		if (itlist != mLRUList.end())
		{
			mLRUList.erase(itlist);
		}
		return value;
	}
	else
		return NULL;
}

template <class K, class T,class hashfun>
void Cache<K,T,hashfun>::clear(void)
{
	typename CacheMap::iterator it = mDict.begin();
	while (it != mDict.end())
	{
		// delete all values
		T* value = (*it).second;
		delete value;
		it++;
	}
	mDict.clear();
	mLRUList.clear();
}

template <class K, class T,class hashfun>
void Cache<K,T,hashfun>::discard(const K& key)
{
	typename CacheMap::iterator it = mDict.find(key);

	if (it != mDict.end())
	{
		T* value = (*it).second;
		mDict.erase(it);
		typename std::list<typename CacheMap::value_type>::iterator itlist;
		itlist = std::find_if (mLRUList.begin(), mLRUList.end(), keypair<K,T>(key));
		if (itlist != mLRUList.end())
		{
			mLRUList.erase(itlist);
		}
		discardItem(value);
	}
}

template <class K, class T,class hashfun>
void Cache<K,T,hashfun>::addCacheItem(const K& key, T* value)
{
	mDict.insert(typename CacheMap::value_type(key,value));
	mLRUList.push_back(typename CacheMap::value_type(key,value));
}

template <class K, class T,class hashfun>
void Cache<K,T,hashfun>::discardItem(T* value)
{
	delete value;
}

template <class K, class T,class hashfun>
void Cache<K,T,hashfun>::discardLRUItem()
{
	assert(mLRUList.size() != 0);

	typename CacheMap::value_type value = mLRUList.front();
	mLRUList.pop_front();
	mDict.erase(value.first);
	discardItem(value.second);
}

template <class K, class T,class hashfun>
void Cache<K,T,hashfun>::markRecentlyUsed(const K& key)
{
	typename std::list<typename CacheMap::value_type>::iterator it;

	it = std::find_if (mLRUList.begin(), mLRUList.end(), keypair<K,T>(key));

	if (it != mLRUList.end())
	{
		mLRUList.push_back(*it);
		mLRUList.erase(it);
	}
}

template <class K, class T,class hashfun>
unsigned int Cache<K,T,hashfun>::depth(void) const
{
	return mDepth;
}

template <class K, class T,class hashfun>
void Cache<K,T,hashfun>::changeDepth(unsigned int newDepth)
{
	if (newDepth > mDepth)
		mDepth = newDepth;
}

template <class K, class T,class hashfun>
unsigned int Cache<K,T,hashfun>::hits(void) const
{
	return mHits;
}

template <class K, class T,class hashfun>
unsigned int Cache<K,T,hashfun>::misses(void) const
{
	return mMisses;
}

template <class K, class T,class hashfun>
unsigned int Cache<K,T,hashfun>::cachedItems(void) const
{
	return mLRUList.size();
}


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_CACHE_H */

/* end of file */
