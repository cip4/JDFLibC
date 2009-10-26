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
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 040302 RP added further Append functions and constructors
// 060302 RP made the constructors based on const input
//
// JDFNameRangeList.h: interface for the JDFNameRangeList class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDFNameRangeList_H__)
#define AFX_JDFNameRangeList_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFNameRange.h"

namespace JDF{

	/**
	* RangeList for names (NMTOKENS)
	*/
	class JDFNmRngLstIterator;                                           // RN20060321
	class JDFNameRangeList;

	class JDF_WRAPPERCORE_EXPORT JDFNameRangeList{

	public:
		typedef JDFNmRngLstIterator iterator;                          // RN20060321
		typedef JDFNmRngLstIterator const_iterator;                    // RN20060321
		typedef JDFNameRange& reference;
		typedef const JDFNameRange& const_reference;


		/** 
		* empty constructor 
		*/
		JDFNameRangeList();

		/**
		* copy ctor
		*/
		JDFNameRangeList(const JDFNameRangeList&rl);

		/**
		* create fron string ctor
		* @param WString s the string to convert
		*/
		JDFNameRangeList(const WString& s);

		/**
		* copy ctor
		*/
		JDFNameRangeList& operator=(const JDFNameRangeList&rl);

		/**
		* copy ctor
		*/
		JDFNameRangeList & operator=(const WString& s);

		/**
		* dtor
		*/
		virtual ~JDFNameRangeList();


		/**
		* serialize to string
		* @return WString a list of ranges in the format a b c~d a f~g ...
		*/
		WString GetString()const;

		/**
		* deserialize a string
		* Reads the string, which represents ranges of any type,
		* and converts it into real ranges 
		* @param WString& str: string to read
		*/
		void SetString(const WString& str=WString::emptyStr);

		/**
		* Is x within this range
		* @param const int x the value to test
		* @return bool true if x is within this range, else false
		*/
		virtual bool InRange(const WString& x);

		/**
		* Is range 'x' within this range
		* @param JDFNameRange x: the range to test
		* @return bool true if range 'x' is within 'this' range, else false
		*/
		bool IsPartOfRange(JDFNameRange& x);

		/**
		* Is range list 'x' within this range list
		* @param JDFNameRangeList x: the range list to test
		* @return bool: true if range list 'x' is within 'this' range list, else false
		*/
		bool IsPartOfRange(JDFNameRangeList& x);


		/**
		* Add a range r =rMin~rMax
		* @param NameRange r the NameRange to append to the list
		*/
		void Append(const JDFNameRange& r);

		/**
		* Add a NameRange defined by two WStrings xMin~xMax
		* @param int xMin the left value of the range to append to the list
		* @param int xMax the right value of the range to append to the list
		*/
		void Append(const WString& xMin, const WString& xMax);

		/**
		* number of range elements
		* @return int the number of Ranges in the list
		*/
		int size()const;

		/**
		* cleanup and empty the internal storge
		*/
		void clear();

		/**
		* Removes the i-th element of the NameRange list
		* 
		* @param iterator i: element (NameRange) to remove
		* @return iterator: the first element remaining beyond removed element, or end() if no such element exists.
		*/
		JDFNameRangeList::iterator erase(iterator i);

		/**
		* A random-access iterator that points at the first element 
		* of the sequence (or just beyond the end of an empty sequence)
		*
		* @return iterator: random-access iterator
		*/
		JDFNameRangeList::iterator begin() ;

		/**
		* Returns a random-access iterator that points just beyond the end of the sequence
		*
		* @return iterator: random-access iterator
		*/
		JDFNameRangeList::iterator end() ;

		/**
		* A constant random-access iterator that points at the first element
		* of the sequence (or just beyond the end of an empty sequence)
		*
		* @return const_iterator: constant random-access iterator
		*/
		JDFNameRangeList::const_iterator begin() const;

		/**
		* Returns a constant random-access iterator that points just beyond the end of the sequence
		*
		* @return const_iterator: constant random-access iterator
		*/
		JDFNameRangeList::const_iterator end() const;

		/**
		* get the nth NameRange element
		* note that this is the n'th NameRange NOT the n'th element
		* @param int i index of the NameRange to retrieve
		* @return reference - the NameRange at position i
		*/
		JDFNameRangeList::reference operator[](int i);

		/**
		* get the nth NameRange element
		* note that this is the n'th NameRange NOT the n'th element
		* @param int i index of the NameRange to retrieve
		* @return const_reference - the NameRange at position i
		*/
		JDFNameRangeList::const_reference operator[](int i) const;

		/**
		* get the nth NameRange element
		* note that this is the n'th NameRange NOT the n'th element
		* @param int i index of the NameRange to retrieve
		* @return reference - the NameRange at position i
		*/
		JDFNameRangeList::reference at(int i);

		/**
		* get the nth NameRange element
		* note that this is the n'th NameRange NOT the n'th element
		* @param int i index of the NameRange to retrieve
		* @return const_reference - the NameRange at position i
		*/
		JDFNameRangeList::const_reference at(int i) const;


	private:

		void *pBase;

	};

#define NameRangeList JDFNameRangeList

	// RN20060321
	/**
	* the iterator implements a subset of STL::vector::iterator with the notable differences:
	*/
	class JDF_WRAPPERCORE_EXPORT JDFNmRngLstIterator{
		friend class JDFNameRangeList;
	public:
		/**
		* constructor
		*/
		JDFNmRngLstIterator();

		/**
		* do not use, this constructo is actually private but must be declared public due to name mangling problems
		*/
		JDFNmRngLstIterator(void*p, int ipos);

		/**
		* copy constructor
		*/
		JDFNmRngLstIterator(const JDFNmRngLstIterator & other);

		/**
		* dtor
		*/
		virtual ~JDFNmRngLstIterator();


		/**
		* copy constructor
		*/
		JDFNmRngLstIterator& operator =(const JDFNmRngLstIterator & other);

		/**
		* reference operator to simplify translation of ->first, ->second to  ->first(), ->second()
		*/
		const JDFNmRngLstIterator* operator->()const;

		/**
		* operator +
		* @param int i - int value to add
		* @return JDFNmRngLstIterator - the sum of 'this' + 'i'
		*/
		JDFNmRngLstIterator operator +(int i)const;

		/**
		* iteration for loops
		*/
		JDFNmRngLstIterator operator++();

		/**
		* iteration for loops
		*/
		JDFNmRngLstIterator operator++(int);

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator!=(const JDFNmRngLstIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator==(const JDFNmRngLstIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator>=(const JDFNmRngLstIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator<=(const JDFNmRngLstIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator>(const JDFNmRngLstIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator<(const JDFNmRngLstIterator & other) const;


		JDFNameRangeList::reference operator *();

		JDFNameRangeList::const_reference operator *() const;


	private:
		void *pJDFNameRange;
		int iPos;
	};
	//////////////////////////////////////////////////////////////////
};
#endif // !defined(AFX_JDFNameRangeList_H__)
