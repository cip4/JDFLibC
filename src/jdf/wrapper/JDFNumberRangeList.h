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
// 120204 ES added IsPartOfRange() for ranges and lists of ranges
// 040304 ES added IsOrdered(),IsUniqueOrdered(),IsUnique(), IsList()
// 300304 ES added begin(), end(), erase()
//
// JDFNumberRangeList.h: interface for the JDFNumberRangeList class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDFNumberRangeList_H__)
#define AFX_JDFNumberRangeList_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFRange.h"

namespace JDF{

/**
Ordered list of NumberRanges
	*/
	class JDF_WRAPPERCORE_EXPORT JDFNumberRangeList{
	public:

		typedef NumberRange* iterator;
		typedef const NumberRange* const_iterator;
		typedef NumberRange& reference;
		typedef const NumberRange& const_reference;

	/**
	* copy ctor
	*/
	JDFNumberRangeList(const JDFNumberRangeList&rl);
	
	/**
	* copy ctor
	*/
	JDFNumberRangeList& operator=(const JDFNumberRangeList&rl);
	
	/** 
	* constructor that tokenizes a string
	*/
	JDFNumberRangeList & operator=(const WString& s);
	
	/**
	* create fron string ctor
	* @param WString s the string to convert
	*/
	JDFNumberRangeList(const WString& s=WString::emptyStr);
	
	/**
	* dtor
	*/
	virtual ~JDFNumberRangeList();
		
	/**
	* Is x within this range
	* @param const double x the value to test
	* @return bool true if x is within this range, else false
	*/
	virtual bool InRange(double x);
		
	/**
	* Is range 'x' within this range
	* @param NumberRange x: the range to test
	* @return bool true if range x is within this range, else false
	*/
	bool IsPartOfRange(const NumberRange& x);
		
	/**
	* Is range list 'x' within this range list
	* @param JDFNumberRangeList x: the range list to test
	* @return bool: true if range list 'x' is within 'this' range list, else false
	*/
	bool IsPartOfRange(const JDFNumberRangeList& x);
		
	/** 
	* append an double and concatenate it to the last range, if possible
	* @param double x the double to append to the list
	*/
	virtual void Append(double x);
	/**
	* Add a range r =rMin~rMax
	* @param NumberRange r the NumberRange to append to the list
	*/
	virtual void Append(const NumberRange& r);
	
	/**
	* Add a Range defined by two ints xMin~xMax
	* @param int xMin the left value of the range to append to the list
	* @param int xMax the right value of the range to append to the list
	*/
	virtual void Append(double xMin, double xMax);
	/**
	* get the nth range element
	* note that this is the n'th range NOT the n'th element
	* @param int i index of the range to retrieve
	* @return the Range at position i
	*/
	const_reference at(int i) const;
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
	* @param NumberRange* i: element (range) to remove
	*/
	void erase(int i) ;

	/**
	* A random-access iterator that points at the first element 
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return NumberRange*: random-access iterator
	*/
	iterator begin();

	/**
	* Returns a random-access iterator that points just beyond the end of the sequence
	*
	* @return NumberRange*: random-access iterator
	*/
	iterator end();

	/**
	* A constant random-access iterator that points at the first element
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return const NumberRange*: constant random-access iterator
	*/
	const_iterator begin() const;

	/**
	* Returns a constant random-access iterator that points just beyond the end of the sequence
	*
	* @return const NumberRange*: constant random-access iterator
	*/
	const_iterator end() const;
	
	
	/**
	* serialize to string
	* @return WString a list of ranges in the format a b c~d a f~g ...
	*/
	WString GetString()const;
	
	/**
	* Tests if 'this' is Ordered NumberRangeList
	* @return bool: true if 'this' is Ordnered NumberRangeList
	*/
	bool IsOrdered();

	/**
	* Tests if 'this' is Unique Ordered NumberRangeList
	* @return bool: true if 'this' is Unique Ordnered NumberRangeList
	*/
	bool IsUniqueOrdered();

	/**
	* Tests if 'this' is a NumberList
	* @return bool: true if 'this' contains no ranges
	*/
	bool IsList();

	/**
	* Tests if 'this' has only unique values
	* @return bool: true if 'this' is unique
	*/
	bool IsUnique() const;


private:
		void *pBase;
		
	};
	
#define NumberRangeList JDFNumberRangeList
};
#endif // !defined(AFX_JDFNumberRangeList_H__)
