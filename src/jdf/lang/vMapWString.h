/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2003 The International Cooperation for the Integration of 
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
* 231104 ES added vector iterator implementation - class vMapWStringIterator
*
******************************************************************************/

#ifndef I_JDF_vMapWString_H
#define I_JDF_vMapWString_H

/******************************************************************************
*	Includes
******************************************************************************/ 

#include <jdf/lang/mapWString.h>


namespace JDF
{
	
/******************************************************************************
*	Forward declarations
	******************************************************************************/ 
	// predefined stl wstring containers
	
	class vMapWStringIterator;
	class WString;
	
	/**
	* utility class to enhance string map  vectors with some set-like features
	*/
	class JDFTOOLS_EXPORT vMapWString {
	public:
		typedef  unsigned int size_type;
		typedef vMapWStringIterator iterator;
		typedef vMapWStringIterator const_iterator;
		typedef MapWString& reference;
		typedef const MapWString& const_reference;
	public:
/*
* the empty map
*/		
	static const vMapWString emptyvMap;
	/**
	* null ctor
		*/
		vMapWString();
		
		/**
		* copy ctor
		*/
		vMapWString(const vMapWString&m);
		
		/**
		* yacctor
		*/
		vMapWString &operator =(const vMapWString& other);
		
		/**
		* dtor
		*/
		~vMapWString();
		
		/**
		* unordered equivalence
		* @param vMapWString other vMapWString to compare to
		* @return bool true if this and other contain the same elements
		*/
		bool IsEqual(const vMapWString& other)const;
		
		/**
		* index of a map
		* @param MapWString other the map that is searched for in this
		* @return true if a map exists in this that is equal to other
		*/
		int index(const MapWString& other)const;
		
		/**
		* index of a map that is a submap
		* @param MapWString other the map that is searched for in this
		* @return true if a map exists in this that is a Superset of other 
		*/
		int IndexSubMap(const MapWString& other)const;

		/// same as set::find
		iterator find( const MapWString & s);
		
		/// same as set::find
		const_iterator find( const MapWString & s)const;

		/// is s a member of this?
		bool hasMap(const MapWString &s)const;

		/// append a string but ignore multiple entries
		void AppendUnique(const MapWString& m);

		/// append a vector but ignore multiple entries
		void AppendUnique(const vMapWString& v);
		/**
		converts to a vector of all submaps if all elements in other match elements in this, i.e. if other is a subset of this
		*/
		void SubMap(const MapWString &other);
		/**
		converts to a vector of all existing elements in other match elements in this, i.e. if other overlaps this
		other may be a superset or subset of this
		*/
		void OverlapMap(const MapWString &other);
		/**
		reduces the vector to a vector of unique masks including only the keys in vKey
		*/
		void ReduceKey(const vWString &vKey);
		
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/**
		* Returns a constant reference to the element of the controlled sequence at position pos
		*
		* @param size_type pos: element index (position)
		* @return const_reference: a reference to the element of the controlled sequence at position pos
		*/
		const_reference at(size_type pos) const;
		const_reference elementAt(size_type pos) const;

		/**
		* Returns a reference to the element of the controlled sequence at position pos
		*
		* @param size_type pos: element index (position)
		* @return reference: a reference to the element of the controlled sequence at position pos
		*/
		reference at(size_type pos);
		reference elementAt(size_type pos);

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
		* element, or end() if no such element exists.
		*/
		iterator erase(iterator it);

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
		* @param MapWString str: an element to insert
		*/
		void push_back(const MapWString& str);

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
		* @param const_iterator first: first element of range to assign
		* @param const_iterator last: last element of range to assign
		*/
		void assign(const_iterator first, const_iterator last);
		
		/**
		* Replaces the sequence controlled by *this with a repetition of n elements of value 'x'
		*
		* @param size_type n
		* @param MapWString x
		*/
		void assign(size_type n, const MapWString& x = MapWString());

		/**
		* Inserts a single element with value 'x' in the controlled sequence
		* in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert 'x' before 
		* @param MapWString x: element to insert , defaults to MapWString()
		* @return iterator: an iterator that points to the newly inserted element
		*/
		iterator insert(iterator it, const MapWString& x =MapWString());

		/**
		* Inserts a repetition of 'n' elements of value 'x' in the controlled sequence
		* in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert repetition of elements 'x' before 
		* @param size_type n
		* @param MapWString x
		*/
		void insert(iterator it, size_type n, const MapWString& x);

		/**
		* Inserts the sequence [first, last] in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert sequence before 
		* @param const_iterator first: first element of sequence to insert
		* @param const_iterator last: last element of sequence to insert
		*/
		void insert(iterator it, const_iterator first, const_iterator last);

		bool empty() const;
		void clear() const;

		bool operator==(const vMapWString&other)const;
		bool operator!=(const vMapWString&other)const;

		/**
		* get a WString representation
		* @return WString
		*/
		WString toString();
		////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////
		
	private:
		void * pBase;
	};
	
	
	/**
	*  stream to ostream operator
	* @param std::ostream&s the ostream
	* @param vMapWString&t the vMapWString to stream
	* @return ostream& the stream
	*/
	JDFTOOLS_EXPORT std::ostream& operator<<(std::ostream&s,const vMapWString&t);
	
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
	class JDFTOOLS_EXPORT vMapWStringIterator{
		friend class vMapWString;
	public:
		/**
		* constructor
		*/
		vMapWStringIterator();

		/**
		* do not use, this constructo is actually private but must be declared public due to name mangling problems
		*/
		vMapWStringIterator(void*p, int ipos);

		/**
		* copy constructor
		*/
		vMapWStringIterator(const vMapWStringIterator & other);
		
		/**
		* dtor
		*/
		virtual ~vMapWStringIterator();


		/**
		* copy constructor
		*/
		vMapWStringIterator& operator =(const vMapWStringIterator & other);

		/**
		* reference operator to simplify translation of ->first, ->second to  ->first(), ->second()
		*/
		const vMapWStringIterator* operator->()const;

		/**
		* operator +
		* @param int i - int value to add
		* @return vMapWStringIterator - the sum of 'this' + 'i'
		*/
		vMapWStringIterator operator +(int i)const;

		/**
		* iteration for loops
		*/
		vMapWStringIterator operator++();

		/**
		* iteration for loops
		*/
		vMapWStringIterator operator++(int);

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator!=(const vMapWStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator==(const vMapWStringIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator>=(const vMapWStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator<=(const vMapWStringIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator>(const vMapWStringIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator<(const vMapWStringIterator & other) const;
		
		
	private:

		void *vMapWStringVector;
		int iPos;

	};
	
} // namespace JDF

#endif /* I_JDF_WSTRING_H */
