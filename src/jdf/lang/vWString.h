#ifndef I_JDF_VWSTRING_H
#define I_JDF_VWSTRING_H

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-20!$ The International Cooperation for the Integration of
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
* 041202 RP remove STL from the interface and hide it in pBase
* 231104 ES added vector iterator implementation - class vWStringIterator
* 010906 NB added containsAny()
* 040906 NB added removeAll()
* 050906 NB added vWStringIterator::hasNext(), vWStringIterator::next()
*
******************************************************************************/

/******************************************************************************
*	Includes
******************************************************************************/

#include <jdf/lang/WString.h>

namespace JDF
{

/******************************************************************************
*	Forward declarations
******************************************************************************/
	class vint;
	class vWStringIterator;
	// predefined stl wstring containers
	typedef vWString VString; // java compat


	/**
	* additional utility class for a map of WString
	* defines a key value map
	*/


	/**
	* utility class to enhance string vectors with some set-like features
	*/
	class JDFTOOLS_EXPORT vWString{

	public:
		typedef ssize_t size_type;
		typedef vWStringIterator iterator;
		typedef vWStringIterator const_iterator;
		typedef WString& reference;
		typedef const WString& const_reference;

/*
* the empty vector
*/		
	static const vWString emptyvStr;

	public:
	/**
	* empty constructor
		*/
		vWString();
		/**
		* copy constructor
		* @param vWString&m: object of type vWString to copy
		*/
		vWString(const vWString&m);
		/**
		* yacctor
		*/
		vWString(const WString&s, const WString & separator=WString::whiteSpace);
		/**
		* yactor
		*/
		vWString &operator =(const vWString& other);
		/**
		* destructor
		*/
		virtual ~vWString();

		/**
		* get the index of s in the vector
		* @param WString& s string to find
		* @param int start the start index of the search
		* @return int first index of the string s after start in the vector
		*/
		ssize_t index(const WString& s, size_t start=0)const;

		/**
		* get the indeces of s in the vector
		* @param WString& s string to find
		* @return vint vector of indeces of the string s in the vector
		*/
		vint multiIndex(const WString& s)const;

		/**
		* is s a member of this?
		* @param WString& s string to find
		* @return bool true if s is included in this
		*/
		inline bool hasString(const WString &s)const{
			return index(s)>=0;
		}

		/**
		* is s a member of this?
		* @param WString& s string to find
		* @return bool true if s is included in this
		*/
		inline bool contains(const WString &s)const{
			return index(s)>=0;
		}

		/**
		* does this contain all strings specified in other?
		* @param vWString& other vector of strings to find
		* @return bool true if this contains all elements of other
		*/
		bool containsAll(const vWString &other)const;

		/**
		* does this contain any of the strings specified in other?
		* @param other the vWString of values to test
		* @return true if at least one string of "other" is in this
		*/
		bool containsAny(const vWString &other)const;
		
		/**
		* add all strings specified in other - java compatibility
		* @param vWString& other vector of strings to add
		* 
		*/
		void addAll(const vWString &other);

		/**
		* same as set::find
		*
		* @param WString& s string to find
		* @return iterator position of s in this, end() if s is not contained
		*/
		iterator find(const WString & s);
		/**
		* same as set::find
		*
		* @param WString& s string to find
		* @return const_iterator position of s in this, end() if s is not contained
		*/
		const_iterator find(const WString &s)const;
		/**
		* append a string but ignore multiple entries
		*
		* @param WString& s string to append
		*/
		void AppendUnique(const WString& v);

		/**
		* append a vector of strings but ignore multiple entries
		*
		* @param vWString& v vector of strings to append
		*/
		void AppendUnique(const vWString& v);
		/**
		* serialize to a string
		* @param const WString& sep separator between strings
		* @param const WString& front string before the first entry
		* @param const WString& back string after the last entry
		* @return a tokenized string
		*/
		WString GetString(const WString& sep=WString::blank,const WString& front=WString::emptyStr, const WString& back=WString::emptyStr)const;
		/**
		* remove the last n occurrences of a string
		* @param WString s the string to remove
		* @int n number of strings to remove; -1=all
		*/
		void RemoveStrings(const WString& s, ssize_t n=-1);
		/**
		* remove the last n occurrences of a vector of strings
		* @param WString s the string to remove
		* @int n number of strings to remove; -1=all
		*/
		void RemoveStrings(const vWString& v, ssize_t n=-1);
		/**
		* create a vector with only one occurrence of each string
		*/
		void Unify();


		////////////////////////////////////////////////////////////////////////////////////////////////////
		
		/**
		* Returns a constant reference to the element of the controlled sequence at position pos
		*
		* @param size_type pos: string element index (position)
		* @return const_reference: a constant reference to the element of the controlled sequence at position pos
		*/
		const_reference at(size_type pos) const;
		// java compatibility
		const_reference elementAt(size_type pos) const;
		const_reference stringAt(size_type pos) const;
		
		/**
		* Returns a reference to the element of the controlled sequence at position pos
		*
		* @param size_type pos: element index (position)
		* @return reference: a reference to the element of the controlled sequence at position pos
		*/
		reference at(size_type pos);
		// java compatibility
		reference elementAt(size_type pos);
		reference stringAt(size_type pos);

		/**
		* Removes the elements of the controlled sequence in the range [first, last]
		*
		* @param iterator first: first element of range to remove
		* @param iterator last: last element of range to remove
		* @return iterator: designates the first element remaining beyond any 
		* elements removed, or end() if no such element exists.
		*/
		iterator erase(iterator first, iterator last);

		/**
		* Removes the element of the controlled sequence pointed to by it
		*
		* @param iterator it: element to remove
		* @return iterator: designates the first element remaining beyond removed 
		* string element, or end() if no such element exists.
		*/
		iterator erase(iterator it);
		
		/**
		* Removes the element of the controlled sequence at position pos
		*
		* @param size_t pos: position of element to remove
		* string element, or end() if no such element exists.
		*/
		void remove(const size_t pos);

		/**
		* A constant random-access iterator that points
		* at the first element of the sequence (or just beyond the end of an empty sequence)
		*
		* @return const_iterator: constant random-access iterator
		*/
		const_iterator begin() const;

		/**
		* A random-access iterator that points to the first element 
		* of the sequence (or just beyond the end of an empty sequence)
		*
		* @return iterator: random-access iterator
		*/
		iterator begin();

		/**
		* Returns a constant random-access iterator that points just beyond the end of the sequence
		*
		* @return const_iterator: constant random-access iterator
		*/
		const_iterator end() const;

		/**
		* Returns a random-access iterator that points just beyond the end of the sequence.
		*
		* @return iterator: random-access iterator
		*/
		iterator end();

		/**
		* The length of the controlled sequence 
		*
		* @return size_type: number of elements in the sequence
		*/
		size_type size() const;

		/**
		* Inserts an element with value 'str' at the end of the controlled sequence.
		*
		* @param int str:
		*/
		void push_back(const WString& str);

		/**
		* Inserts an element with value 'str' at the end of the controlled sequence.
		* java compatibility routine, same as push_back
		* @param int str:
		*/
		void add(const WString& str);

		/**
		* Removes the last element of the controlled sequence, which must be non-empty
		*/
		void pop_back();

		/**
		* Overloaded operator [] provides an access to the element of sequence with index = pos
		*
		* @param size_type pos: element index(position)
		* @return const_reference: a constant reference to the element of the controlled sequence at position pos
		*/
		const_reference operator[](size_type pos) const;
		
		/**
		* Overloaded operator [] provides an access to the element of sequence with index = pos
		*
		* @param size_type pos
		* @return reference: a reference to the element of the controlled sequence at position pos
		*/
		reference operator[](size_type pos);

		/**
		* Replaces the sequence controlled by *this with the sequence [first, last]
		*
		* @param const_iterator first: first string element of range to assign
		* @param const_iterator last: last string element of range to assign
		*/
		void assign(const_iterator first, const_iterator last);
		
		/**
		* Replaces the sequence controlled by *this with a repetition of n string elements of value 'x'
		*
		* @param size_type n
		* @param int x: string to insert , defaults to empty string
		*/
		void assign(size_type n, const WString& x = WString());

		/**
		* reserves space for a total of n elements
		*
		* @param size_type n total number of elements
		*/
		void reserve(size_type n);

		/**
		* Inserts a single element with value 'x' in the controlled sequence
		* in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert 'x' before 
		* @param int x: element to insert , defaults to empty string
		* @return iterator: an iterator that points to the newly inserted element
		*/
		iterator insert(iterator it, const WString& x =WString());

		/**
		* Inserts a repetition of 'n' elements of value 'x' in the controlled sequence
		* in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert repetition of elements 'x' before 
		* @param size_type n
		* @param int x
		*/
		void insert(iterator it, size_type n, const WString& x);

		/**
		* Inserts the sequence [first, last] in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert sequence before 
		* @param const_iterator first: first element of sequence to insert
		* @param const_iterator last: last element of sequence to insert
		*/
		void insert(iterator it, const_iterator first, const_iterator last);

		/**
		* Java compatibility
		* insert x before position beforePos
		* @param WString& x the string to insert
		* @param int beforePos the position in front of which to insert
		*/
		void insertElementAt(const WString &x ,size_t beforePos);

		/**
		* Returns true for an empty controlled sequence
		*
		* @return bool: true if empty
		*/
		bool empty() const;
		
		/**
		* Cleanup and empty the internal storage
		*/
		void clear() const;
		
		/**
		* lexical sort of the vector
		* @param int first integer addressing the position of the first element in the range to be sorted. 
		* @param int last integer addressing the position one past the final element in the range to be sorted, last if <0. 	 
		*/
		void sort(size_t first=0, ssize_t last=-1);

		/**
		* get a WString representation
		* @return WString
		*/
		WString toString();

	private:

		void * pBase;
		
};

	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////


	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 

	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* the iterator implements a subset of STL::vector::iterator with the notable differences:
*/
	class JDFTOOLS_EXPORT vWStringIterator{
		friend class vWString;
	public:
		/**
		* constructor
		*/
		vWStringIterator();

		/**
		* do not use, this constructo is actually private but must be declared public due to name mangling problems
		*/
		vWStringIterator(void*p, size_t ipos);

		/**
		* copy constructor
		*/
		vWStringIterator(const vWStringIterator & other);
		
		/**
		* dtor
		*/
		virtual ~vWStringIterator();


		/**
		* copy constructor
		*/
		vWStringIterator& operator =(const vWStringIterator & other);

		/**
		* reference operator to simplify translation of ->first, ->second to  ->first(), ->second()
		*/
		const vWStringIterator* operator->()const;

		/**
		* operator +
		* @param int i - int value to add
		* @return vWStringIterator - the sum of 'this' + 'i'
		*/
		vWStringIterator operator +(size_t i)const;

		/**
		* iteration for loops
		*/
		vWStringIterator operator++();

		/**
		* iteration for loops
		*/
		vWStringIterator operator++(int);

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator!=(const vWStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator==(const vWStringIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator>=(const vWStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator<=(const vWStringIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator>(const vWStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator<(const vWStringIterator & other) const;
		
			
		vWString::reference operator *();
		
		vWString::const_reference operator *() const;

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
		void *vWStringVector;
		size_t iPos;
	};


} // namespace JDF

#endif /* I_JDF_VWSTRING_H */

