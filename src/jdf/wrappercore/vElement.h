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

//EndCopyRight
/*
//
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
//
// 231104 ES added vector iterator implementation - class vElementIterator
// 050906 NB added vElementIterator::hasNext()
//
// vElement.h: interface for the vElement class.
//
//
*/
#ifndef _vElement_H_
#define _vElement_H_

#include <jdf/lang/WString.h>

namespace JDF{

	class vElementIterator;
	class KElement;
	class XMLDoc;
	
	/**
	utility wrapper around stl vector<KElement>
	*/
	class JDF_WRAPPERCORE_EXPORT vElement{
	public:
		typedef  unsigned int size_type;
		typedef vElementIterator iterator;
		typedef vElementIterator const_iterator;
		typedef KElement& reference;
		typedef const KElement& const_reference;

		static const vElement emptyVector;


	public:
	/**
	* null ctor
		*/
		vElement();
		
		/**
		* copy ctor
		*/
		vElement(const vElement&m);
		
		/**
		* yacctor
		*/
		vElement &operator =(const vElement& other);
		
		/**
		* dtor
		*/
		virtual ~vElement();
		
		/**
		* get the index of s in the vector
		* @since 120601 use @see IsEqual instead of @see operator == for comparison
		* @param KElement& s to search
		* @return int the index of s in the vector
		*/
		int index(const KElement& s)const;
		
		/**
		* is s contained in this 
		* @param KElement &s the element to look for
		* @return bool true if s is contained in this
		*/
		bool hasElement(const KElement &s)const;
		
		/**
		* same as set::find
		* @since 120601 use @see IsEqual instead of @see operator == for comparison
		* @param KElement &s the element to look for
		* @return iterator pointing to s or end() if not found
		*/
		iterator find(const KElement & s);
		
		/**
		* same as set::find
		* @param KElement &s the element to look for
		* @return const_iterator pointing to s or end() if not found
		*/
		const_iterator find(const KElement &s)const;
		
		/**
		* append all elements in e but ignore multiple entries
		* @param KElement &e the element to append
		*/
		void AppendUnique(const KElement& e);
		
		/**
		* append a vector but ignore multiple entries
		* @param vElement &v the vector of elements to append
		*/
		void AppendUnique(const vElement& v);
		/**
		* append all elements in e but ignore multiple entries with the same Name
		* @param KElement &e the element to append
		*/
		void AppendUniqueByName(const KElement& e);
		
		/**
		* append a vector but ignore multiple entries with the same Name
		* @param vElement &v the vector of elements to append
		*/
		void AppendUniqueByName(const vElement& v);
		
		/**
		* set the attribute key to the value defined in value in all elements	
		* @param WString& key the attribute name
		* @param WString & value the  value to set
		* @param WString nameSpaceURI: nameSpace of the attribute to set
		*/
		void SetAttributes(const WString &  key, const WString & value, const WString & nameSpaceURI=WString::emptyStr);
		
		/**
		* set the attribute key to the values defined in vValue	
		* @param WString& key the attribute name
		* @param vWString & vValue the vector of values. Note that vValue must have the same @see size() as this
		* @param WString nameSpaceURI: nameSpace of the attribute to set
		*/
		void SetAttributes(const WString &  key, const vWString & vValue, const WString & nameSpaceURI=WString::emptyStr);
		
		/**
		* remove the attribute key 
		* @param WString& key the attribute name
		* @param WString nameSpaceURI: nameSpace of the attribute to set
		*/
		void RemoveAttribute(const WString &  attrib, const WString & nameSpaceURI);

		/**
		* Remove elements listed in v from this
		* @param vElement v list of elements to remove
		*/
		void RemoveElements(const vElement& v);
		
		/**
		* Remove elements listed in v from this
		* @param KElement e elements to remove
		* @param int nMax maximum number of dulicate elements to remove
		*/
		void RemoveElements(const KElement& e, int nMax=0);
		
		/**
		* Gets a list of all element names of 'this'
		*
		* @param bool bLocal: if true, gets the local names, else the qualified names
		* @return vWString: vector of strings, that contains a list of all element names
		* @tbd namespace handling
		*/
		virtual vWString GetElementNameVector(bool bLocal=false)const;

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

		// java compatibility
		void remove(int i);

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
		* Inserts an element with value 'str' at the end of the controlled sequence.
		*
		* @param KElement str: an element to insert
		*/
		void push_back(const KElement& str);

		/**
		* Inserts an element with value 'str' at the end of the controlled sequence.
		* java compatibility routine, same as push_back
		* @param int str:
		*/
		void add(const KElement& str);

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
		* Replaces the sequence controlled by *this with a repetition of n elements of value NULL
		*
		* @param size_type n: number of null elements
		*/
		void assign(size_type n);

		/**
		* reserves space for a total of n elements
		*
		* @param size_type n total number of elements
		*/
		void reserve(size_type n);

		/**
		* Replaces the sequence controlled by *this with a repetition of n elements of value 'x'
		*
		* @param size_type n number of repititions of x
		* @param KElement x
		*/
		void assign(size_type n, const KElement& x);
		
		//@vigo -- dito, to avoid having to include KElement
		iterator insert(iterator it);

		/**
		* Inserts a single element with value 'x' in the controlled sequence
		* in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert 'x' before 
		* @param KElement x: element to insert 
		* @return iterator: an iterator that points to the newly inserted element
		*/
		iterator insert(iterator it, const KElement& x);

		/**
		* Inserts a repetition of 'n' elements of value 'x' in the controlled sequence
		* in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert repetition of elements 'x' before 
		* @param size_type n
		* @param KElement x
		*/
		void insert(iterator it, size_type n, const KElement& x);

		/**
		* Inserts the sequence [first, last] in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert sequence before 
		* @param const_iterator first: first element of sequence to insert
		* @param const_iterator last: last element of sequence to insert
		*/
		void insert(iterator it, const_iterator first, const_iterator last);
		
		/**
		* returns the common ancestor of all entries of this
		*
		* @return KElement the element that is a common ancestor of all vector members
		* @since 050721 
		*/
		KElement GetCommonAncestor()const;

		
		////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////////////////////////////////
		
	private:
		void * pBase;
	};


	/**
	*  stream to ostream operator
	* @param std::ostream&s the ostream
	* @param vElement&t the vElement to stream
	* @return ostream& the stream
	*/
	JDF_WRAPPERCORE_EXPORT std::ostream& operator<<(std::ostream&s,const vElement&t);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	typedef vElement VElement; // java

	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* the iterator implements a subset of STL::vector::iterator with the notable differences:
*/
	class JDF_WRAPPERCORE_EXPORT vElementIterator{
		friend class vElement;
	public:
		/**
		* constructor
		*/
		vElementIterator();

		/**
		* do not use, this constructo is actually private but must be declared public due to name mangling problems
		*/
		vElementIterator(void*p, int ipos);

		/**
		* copy constructor
		*/
		vElementIterator(const vElementIterator & other);
		
		/**
		* dtor
		*/
		virtual ~vElementIterator();


		/**
		* copy constructor
		*/
		vElementIterator& operator =(const vElementIterator & other);

		/**
		* reference operator to simplify translation of ->first, ->second to  ->first(), ->second()
		*/
		const vElementIterator* operator->()const;

		/**
		* operator +
		* @param int i - int value to add
		* @return vElementIterator - the sum of 'this' + 'i'
		*/
		vElementIterator operator +(int i)const;

		/**
		* iteration for loops
		*/
		vElementIterator operator++();

		/**
		* iteration for loops
		*/
		vElementIterator operator++(int);

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator!=(const vElementIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator==(const vElementIterator & other) const;

		/**
		* operator >= 
		* @return bool 
		*/
		bool operator>=(const vElementIterator & other) const;

		/**
		* operator <=
		* @return bool 
		*/
		bool operator<=(const vElementIterator & other) const;

		/**
		* operator >
		* @return bool 
		*/
		bool operator>(const vElementIterator & other) const;

		/**
		* operator <
		* @return bool 
		*/
		bool operator<(const vElementIterator & other) const;
		

		vElement::reference operator *();
		

		vElement::const_reference operator *() const;

		/**
		* check if there is another element after the current one
		* @return bool true, if there is a next element
		*/
		bool hasNext() const;

		/**
		* gets the value of the next element
		* @return KElement the value of the next element
		* @throws std::exception if there is no next element
		*/
		KElement next();

	private:

		void *vElementVector;
		int iPos;
	};

}

#endif // !defined(_vElement_H_)

