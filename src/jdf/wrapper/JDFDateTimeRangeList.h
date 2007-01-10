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

//EndCopyRight
/**
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  4.February.2004
// 120204 ES added IsPartOfRange() for ranges and lists of ranges
// 040304 ES added IsOrdered(),IsUniqueOrdered(),IsUnique(), IsList()
// 300304 ES added begin(), end(), erase()
//
// JDFDateTimeRangeList.h: interface for the JDFDateTimeRangeList class.
// list of DateTime range values
//
*/

#if !defined(_JDFDateTimeRangeList_H__)
#define _JDFDateTimeRangeList_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/util/myuti.h"
#include "JDFDateTimeRange.h"
#include "jdf/wrapper/JDFDate.h"

namespace JDF{
	
/**
Template that implements lists of JDF DateTimeRanges in format " x x~y" 
DateTimeRanges include the end-points
	*/
	
	class JDF_WRAPPERCORE_EXPORT JDFDateTimeRangeList{
		
	public:
		typedef JDFDateTimeRange* iterator;
		typedef const JDFDateTimeRange* const_iterator;
		typedef JDFDateTimeRange& reference;
		typedef const JDFDateTimeRange& const_reference;
		
		/** 
		* empty constructor 
		*/
		JDFDateTimeRangeList();
		
		/** 
		* Constructs a range list from a string
		* @param WString& s: string representation of the dateTime range list
		* @throws IllegalArgumentException - if a string has not a valid format
		*/
		JDFDateTimeRangeList(const WString& s);
		
		/** 
		* copy equivalance operator that tokenizes a string
		* @param WString& s: string representation of the dateTime range list
		* @throws IllegalArgumentException - if a string has not a valid format
		*/
		JDFDateTimeRangeList & operator=(const WString& s);
		
		/**
		* copy ctor
		* @param JDFDateTimeRangeList& r: dateTime range list to make a copy of
		*/
		JDFDateTimeRangeList(const JDFDateTimeRangeList & rl); 
		
		/**
		* copy equivalance operator
		* @param JDFDateTimeRangeList& r: dateTime range list to make a copy of
		*/
		JDFDateTimeRangeList& operator=(const JDFDateTimeRangeList & rl); 
		
		/**
		* dtor
		*/
		virtual ~JDFDateTimeRangeList();
		
		/**
		* check whether element 'x' is in the range defined by this
		*
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate& x: value to test
		* @return true if 'x' is in the JDFDateTimeRangeList defined by 'this'
		*/
		bool InRange(const JDFDate& x)const;
		
		/**
		* check whether range 'x' is in the range defined by 'this'
		* @param JDFDateTimeRange& x: range to test
		* @return bool: true if range 'x' is in the range list defined by 'this'
		*/
		bool IsPartOfRange(const JDFDateTimeRange& x)const;
		
		/**
		* check whether range list 'x' is in the range list defined by 'this'
		* @param JDFDateTimeRangeList& x: range list to test
		* @return bool: true if range list 'x' is in the range list defined by 'this'
		*/
		bool IsPartOfRange(const JDFDateTimeRangeList& x)const;
		
		/**
		* serialize to string
		* @return WString a list of DateTimeRanges in the format a b c~d a f~g ...
		*/
		WString GetString() const;
		
		/**
		* deserialize a string
		* @param WString& s: string representation of the duration range list to set
		*/
		void SetString(const WString& s=WString::emptyStr);
		
		/**
		* Add a DateTime range r =rMin~rMax
		* @param DateTimeRange r the DateTime range to append to the list
		*/
		void Append(const JDFDateTimeRange& r);
		
		/**
		* Add a DateTime range defined by two JDFDates xMin~xMax
		*
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate xMin the left value of the DateTime range to append to the list
		* @param JDFDate xMax the right value of the DateTime range to append to the list
		*/
		void Append(const JDFDate& xMin, const JDFDate& xMax);
		
		/**
		* Add an individual JDFDate element
		*
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate x the left and right value of the DateTime range to append to the list
		*/
		void Append(const JDFDate& x);
		
		/**
		* number of DateTime range elements
		* @return int the number of DateTime ranges in the list
		*/
		int size()const;
		
		/**
		* cleanup and empty the internal storge
		*/
		void clear();
		
		/**
		* Removes the i-th element of the range list
		* 
		* @param JDFDateTimeRange* i: element (range) to remove
		*/
		void erase(int i);
		
		/**
		* A random-access iterator that points at the first element 
		* of the sequence (or just beyond the end of an empty sequence)
		*
		* @return JDFDateTimeRange*: random-access iterator
		*/
		iterator begin();
		
		/**
		* Returns a random-access iterator that points just beyond the end of the sequence
		*
		* @return JDFDateTimeRange*: random-access iterator
		*/
		iterator end();
		
		/**
		* A constant random-access iterator that points at the first element
		* of the sequence (or just beyond the end of an empty sequence)
		*
		* @return const JDFDateTimeRange*: constant random-access iterator
		*/
		const_iterator begin() const;
		
		/**
		* Returns a constant random-access iterator that points just beyond the end of the sequence
		*
		* @return const JDFDateTimeRange*: constant random-access iterator
		*/
		const_iterator end() const;
		
		/**
		* get the nth DateTime range element
		* note that this is the n'th DateTimeRange NOT the n'th element
		* @param int i index of the DateTimeRange to retrieve
		* @return const JDFDateTimeRange&: const JDFDateTimeRange at the position i
		*/
		const_reference operator[](int i) const;
		
		/**
		* get the nth DateTime range element
		* note that this is the n'th DateTimeRange NOT the n'th element
		* @param int i index of the DateTimeRange to retrieve
		* @return JDFDateTimeRange&: JDFDateTimeRange at the position i
		*/
		reference operator[](int i);
		
		/**
		* get the nth DateTime range element
		* note that this is the n'th DateTimeRange NOT the n'th element
		* @param int i index of the DateTimeRange to retrieve
		* @return const JDFDateTimeRange&: const JDFDateTimeRange at the position i
		*/
		const_reference at(int i) const;
		
		/**
		* get the nth DateTime range element
		* note that this is the n'th DateTimeRange NOT the n'th element
		* @param int i index of the DateTimeRange to retrieve
		* @return JDFDateTimeRange&: JDFDateTimeRange at the position i
		*/
		reference at(int i);
		
		/**
		* Tests if 'this' is OrderedRangeList
		* @return bool: true if 'this' is OrdneredRangeList
		*/
		bool IsOrdered();
		
		/**
		* Tests if 'this' is UniqueOrderedRangeList
		* @return bool: true if 'this' is UniqueOrderedRangeList
		*/
		bool IsUniqueOrdered();
		/**
		* Tests if 'this' is a List 
		* @return bool: true if 'this' contains no ranges
		*/
		bool IsList();
		
		/**
		* Tests if 'this' has only unique values
		* @return bool: true if 'this' is unique
		*/
		bool IsUnique() const;
		
		
	private:

		void * pBase;

	};

};
#endif // !defined(_JDFDateTimeRangeList_H__)
