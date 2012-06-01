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



/*******************************************************************************
* 
* Description:
*
* Revision history
*
* 290502 RP removed inline from peekBytes(), ostream operator <<, vMapWString::index
* 051102 RP Token() gracefully handle index above limit of number of tokens
* 241103 RP added GetKeys, erase(vWString)
* now contains a vector instead of inheriting from stl::map
* 060906 NB added mapWStringIterator::next(), mapWStringIterator::hasNext()
*
*
******************************************************************************/

#ifndef I_JDF_MAPWSTRING_H
#define I_JDF_MAPWSTRING_H

/******************************************************************************
*	Includes
******************************************************************************/ 

#include "JDFToolsDefs.h"

#include <ostream>

namespace JDF
{
	
/******************************************************************************
*	Forward declarations
******************************************************************************/ 
	class WString;
	class vWString;
	class MapWStringIterator;
		
	
	/**
	* additional utility class for a map of WString
	* defines a key value map
	* it is implemented as a vector in order to keep the iterator fast and transparent<br>
	*/
	class JDFTOOLS_EXPORT MapWString {
		
	public: 
		
		
		typedef size_t size_type;
		typedef MapWStringIterator iterator;
		typedef MapWStringIterator const_iterator;
		//		typedef MapWStringIterator& reference;
		//		typedef const MapWStringIterator& const_reference;
		
		
		/**
		* ctor
		*/
		MapWString();
		/**
		* copy ctor
		*/
		MapWString(const MapWString&m);

		/**
		* yactor
		*/
		MapWString& operator =(const MapWString& other);

		/**
		* Constructor for a simple map with one entry that is defined by key and value
		*
		* @param WString key the key to add to the map
		* @param WString value the value to set the map to
		*/
		MapWString(const WString &key, const WString & value);

		/**
		* dtor
		*/
		virtual ~MapWString();

		/**
		* add a key value pair - if key already exists, the prior value is retained
		* @param WString key the key to add to the map
		* @param WString value the value to set the map to
		*/
		void AddPair(const WString &key, const WString & value);
		

		/**
		* appends a key value pair - for performance, no check is made if key already exists
		* may create multi-maps! use with cation
		* @param WString key the key to add to the map
		* @param WString value the value to set the map to
		*/
		void AppendPair(const WString &key, const WString & value);

		/**
		* set a key value pair - if key already exists, the prior value is overwritten
		* @param WString key the key to add to the map
		* @param WString value the value to set the map to
		*/
		void SetPair(const WString &key, const WString & value);
		
		/**
		* set a key value pair - if key already exists, the prior value is overwritten
		* same as setPair - java compatibility
		* @param WString key the key to add to the map
		* @param WString value the value to set the map to
		*/
		void put(const WString &key, const WString & value);

		/** 
		* equivalence operator: all elements are identical. Ordering is not relevant
		* @return bool true if all elements (key value pairs) are identical
		*/
		bool operator ==(const MapWString& other)const;
		
		/**
		* not ==
		* @return bool true if any key-value pair does not match
		*/
		bool operator !=(const MapWString& other)const;
		
		/**
		* @return bool true if all elements in other match elements in this, i.e. if other is a subset of this
		*/		
		bool SubMap(const MapWString &other)const;

		/**
		* returns true if all elements that exist both in this and other match, i.e. if other overlaps this
		* other may be a superset or subset of this
		* @return bool true if this and other have no matching keys with mimatched values
		*/		
		bool OverlapMap(const MapWString &other)const;
		
		/**
		* ors in all all keys of other. Returns an empty map if conflicting keys exist
		* <p> an ored map will contain two keys, in case they are different
		* @param MapWString &other the map to or into this
		* @return MapWString map of all values that are either in this or other
		*/
		MapWString OrMap(const MapWString &other);
		
		/**
		* ands in all matching keys of other. Returns an empty map if conflicting keys exist
		* <p> an anded map will contain zero keys, in case they are different
		* @param MapWString &other the map to and into this
		* @return MapWString map of all values that are both in this and other
		*/
		MapWString AndMap(const MapWString &other);
		
		/**
		* merges in ALL keys of other. Thus other will have precedence in case of conflicting keys. 
		* the result will contain all keys set in this but not set in other in addition to all keys of other
		*
		* @param MapWString &other the map to merge into this
		* @return MapWString map of all values that are both in this and other
		*/
		MapWString MergeMap(const MapWString &other);
		/**
		* reduces the map to contain only the keys in vKey
		* @param vWString vKeys list of keys that shall remain
		*/
		void ReduceKey(const vWString & vKeys);
		
		
		/**
		* get a vector of all keys
		* return vWString list of keys that 
		*/
		vWString GetKeys()const;

        /**
         * get a value for a given key
         * @param WString a valid key
         *
         * @return the value to the given key, "" if not found
         */
        WString GetValue(const WString &key)const;

        /**
         * check if the given key is present in 'this' map
         * @param WString key to check existence
         *
         * @return true if key is found, false if not
         */
        bool HasKey(const WString &key)const;
		
		
        /**
         * get a Key for a given position. Used to iterate quickly over all keys
         * @param uint i the position in the map
         *
         * @return the key to the given position, "" if not found
         */
        WString GetKeyByPos(unsigned int i)const;

        /**
         * get a value for a given position. Used to iterate quickly over all keys
         * @param uint i the position in the map
         *
         * @return the value to the given position, "" if not found
         */
        WString GetValueByPos(unsigned int i)const;

		WString operator [](const WString & key)const;

		/**
		* get a WString representation
		* @return WString
		*/
		WString toString();
			
		
		
		
		const_iterator begin() const;
		iterator begin();
		const_iterator end() const;
		iterator end();
		size_type size() const;
		iterator find(const WString & key);
		const_iterator find(const WString &key)const;
		void clear()const;
		bool empty()const;
		bool isEmpty()const; // java compatibility
		iterator erase(iterator first, iterator last);
		iterator erase(iterator it);
		size_type erase(const WString& key);

		void reserve(size_type len);
		/**
		* remove the pair with the key 
		* @param vWString Key list of keys that shall be removed
		* return  size_type size after removing
		*/
		size_type erase(const vWString & vkeys);

		/**
		* Java compatibility
		*/
		size_type remove(const WString& key);
		
/*
* the empty map
*/		
	static const MapWString emptyMap;
		
	private:
		void * pBase;
		int index(const WString& s)const;
		
	};
	
	/**
	*  stream to ostream operator
	* @param std::ostream&s the ostream
	* @param MapWString&t the string to stream
	* @return ostream& the stream
	*/
	JDFTOOLS_EXPORT std::ostream& operator<<(std::ostream& s,const MapWString& t);
	
	
	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 

	typedef MapWString mAttribute;
	typedef MapWString JDFAttributeMap;  // java compat


/**
* the iterator implements a subset of STL::map::iterator with the notable differences:
*/
	class JDFTOOLS_EXPORT MapWStringIterator{
		friend class MapWString;
	public:
		/**
		* constructor
		*/
		MapWStringIterator();

		/**
		* do not use, this constructo is actually private but must be declared public due to name mangling problems
		*/
		MapWStringIterator(void*p, int ipos);

		/**
		* copy constructor
		*/
		MapWStringIterator(const MapWStringIterator & other);

		/**
		* copy constructor
		*/
		MapWStringIterator& operator =(const MapWStringIterator & other);

		/**
		* reference operator to simplify translation of ->first, ->second to  ->first(), ->second()
		*/
		const MapWStringIterator* operator->()const;

		/**
		* iteration for loops
		*/
		MapWStringIterator operator++();

		/**
		* iteration for loops
		*/
		MapWStringIterator operator++(int);

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator!=(const MapWStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator==(const MapWStringIterator & other) const;

		/**
		* dtor
		*/
		virtual ~MapWStringIterator();
		
		/**
		* get the key of the iterator<br>
		* note that in stl, this was a public member, not a function call
		* @return WString the key
		*/
		const WString& first()const;

		/**
		* get the value of the iterator<br>
		* note that in stl, this was a public member, not a function call
		* @return WString the value
		*/
		const WString& second()const;

		/**
		* check if there is another element after the current one
		* @return bool true, if there is a next element
		*/
		bool hasNext() const;

		/**
		* gets the value of the next element
		* @return WString the value of the next element
		* @throws std::exception if there is no next element
		*/
		WString next();

	private:
		void *mapVector;
		int iPos;
	}; // class MapWStringIterator

	
} // namespace JDF

#endif /* I_JDF_MAPWSTRING_H */
