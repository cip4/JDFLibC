#if !defined(AFX_JDFIntegerRangeList_H__)
#define AFX_JDFIntegerRangeList_H__

/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
// 300104 ES added ToVInt();
// 120204 ES added IsPartOfRange() for ranges and lists of ranges
// 040304 ES added IsOrdered(),IsUniqueOrdered(),IsUnique(), IsList()
// 300304 ES added begin(), end(), erase()
// 301006 NB fixed JDFIntegerRangeList::setDef()
// 071206 NB fixed GetString(), the shortcut PBASE->GetString() failed for INF
// 250107 NB removed unreferenced variables
//
// JDFIntegerRangeList.h: interface for the JDFIntegerRangeList class.
//
// ////////////////////////////////////////////////////////////////////

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFIntegerRange.h"


namespace JDF{
	
/**
Ordered list of IntegerRanges
	*/
	class JDF_WRAPPERCORE_EXPORT JDFIntegerRangeList{
	public:

		typedef JDFIntegerRange* iterator;
		typedef const JDFIntegerRange* const_iterator;
		typedef JDFIntegerRange& reference;
		typedef const JDFIntegerRange& const_reference;

	/**
	* copy ctor
		*/
		JDFIntegerRangeList(const JDFIntegerRangeList&rl);
		
		/**
		* create fron string ctor
		* @param WString s the string to convert
		* @param int xdef the value that -1 defaults to in this JDFIntegerRangeList
		*/
		JDFIntegerRangeList(const WString& s=WString::emptyStr, int xdef=JDFIntegerRange::getDefaultDef());
		
		/** 
		* constructor that tokenizes a string
		*/
		JDFIntegerRangeList & operator=(const WString& s);
		
		/**
		* dtor
		*/
		virtual ~JDFIntegerRangeList();
		
		/**
		* copy constructor;
		*/
		JDFIntegerRangeList& operator =(const JDFIntegerRangeList&rl);
		
		/**
		* set the default value which is used for negative numbers
		* if xDef==0 (the default) the neg numbers themselves are used
		* @param int xdef one above the value that -1 will represent in this range
		* i.e. the value that -0, were it possible to specify, would represent
		*/
		void SetDef(const int xdef);
		
		/**
		* Get the default value which is used for negative numbers
		* @return int: one above the value that -1 will represent in this range
		* i.e. the value that -0, were it possible to specify, would represent
		*/
		int GetDef() const;

		/**
		* Is x within this range
		* @param int x: the value to test
		* @return bool true if x is within this range, else false
		*/
		bool InRange(int x)const;
		
		/**
		* Is range 'x' within this range
		* @param JDFIntegerRange x: the range to test
		* @return bool true if range 'x' is within 'this' range, else false
		*/
		bool IsPartOfRange(const JDFIntegerRange& x);

		/**
		* Is range list 'x' within this range list
		* @param JDFIntegerRangeList x: the range list to test
		* @return bool: true if range list 'x' is within 'this' range list, else false
		*/
		bool IsPartOfRange(const JDFIntegerRangeList& x);
		
		/**
		* number of elements that this rangelist represents
		* @return int the number of elements represented by this
		*/
		int NElements() const;
		
		/** 
		* value of the ith element in the range
		* Element(2) of 1~3 4 is 3
		* Element(0) of 4 3~1 is 4
		* Element(-2) of 4 3~1 is 2
		* @param int i position within the logical range, negative number count from the back
		* @return value of the logical ith element
		*/
		int Element(int i) const;
		
		/** 
		* append an int and concatenate it to the last range, if possible
		* @param int x the integer to append to the list
		*/
		void Append(int x);
		/**
		* Add a range r =rMin~rMax
		* @param IntegerRange r the IntegerRange to append to the list
		*/
		void Append(const IntegerRange& r);
		
		/**
		* Add a Range defined by two ints xMin~xMax
		* @param int xMin the left value of the range to append to the list
		* @param int xMax the right value of the range to append to the list
		*/
		void Append(int xMin, int xMax);
		/**
		* serialize to string
		* @return WString a list of ranges in the format a b c~d a f~g ...
		*/
		WString GetString()const;
		
		/**
		* get the nth range element
		* note that this is the n'th range NOT the n'th element
		* @param int i index of the range to retrieve
		* @return the Range at position i
		*/
		reference at(int i);

		/**
		* get the nth range element
		* note that this is the n'th range NOT the n'th element
		* @param int i index of the range to retrieve
		* @return the Range at position i
		*/
		const_reference at(int i) const;
		
		/**
		* get the nth range element
		* note that this is the n'th range NOT the n'th element
		* @param int i index of the range to retrieve
		* @return the Range at position i
		*/
		reference operator[](int i);

		/**
		* get the nth range element
		* note that this is the n'th range NOT the n'th element
		* @param int i index of the range to retrieve
		* @return the Range at position i
		*/
		const_reference operator[](int i) const;
		

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
		* Removes the i-th element of the range list
		* 
		* @param IntegerRange* i: element (range) to remove
		*/
		void erase(int i) ;

		/**
		* A random-access iterator that points at the first element 
		* of the sequence (or just beyond the end of an empty sequence)
		*
		* @return IntegerRange*: random-access iterator
		*/
		iterator begin();

		/**
		* Returns a random-access iterator that points just beyond the end of the sequence
		*
		* @return IntegerRange*: random-access iterator
		*/
		iterator end();

		/**
		* A constant random-access iterator that points at the first element
		* of the sequence (or just beyond the end of an empty sequence)
		*
		* @return const IntegerRange*: constant random-access iterator
		*/
		const_iterator begin() const;

		/**
		* Returns a constant random-access iterator that points just beyond the end of the sequence
		*
		* @return const IntegerRange*: constant random-access iterator
		*/
		const_iterator end() const;
	
		/**
		* Converts an IntegerRangeList into vector of integers,
		* that contains all range list elements (NOT Ranges) <br>
		* e.g. list="3~5 8" will be transformed into vector of int, that contains 3,4,5,8
		* the maximum number of elements in a vector, 
		* limits number of vector elements in case of INF, default=1000
		*
		* @return vint: transformed IntegerRangeList into vector of integers
		*/
		vint ToVInt(int maxelem=1000) const;
		

		/**
		* Tests if 'this' is Ordered IntegerRangeList
		* @return bool: true if 'this' is Ordnered IntegerRangeList
		*/
		bool IsOrdered();

		/**
		* Tests if 'this' is Unique Ordered IntegerRangeList
		* @return bool: true if 'this' is Unique Ordnered IntegerRangeList
		*/
		bool IsUniqueOrdered();

		/**
		* Tests if 'this' is a IntegerList
		* @return bool: true if 'this' contains no ranges
		*/
		bool IsList();

		/**
		* Tests if 'this' has only unique values
		* @return bool: true if 'this' is unique
		*/
		bool IsUnique() const;

		
	protected:
		/// default for negative values
		int xDef;
	private:
		void *pBase;
		
	};
}

#define IntegerRangeList JDFIntegerRangeList
#endif // !defined(AFX_JDFIntegerRangeList_H__)
