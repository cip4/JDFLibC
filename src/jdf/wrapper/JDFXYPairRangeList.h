/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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
// JDFXYPairRangeList.h: interface for the JDFXYPairRangeList class.
//
// ////////////////////////////////////////////////////////////////////

#if !defined(AFX_JDFXYPairRangeList_H__)
#define AFX_JDFXYPairRangeList_H__

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFRange.h"

namespace JDF{

/**
Ordered list of IntegerRanges
	*/
	class JDF_WRAPPERCORE_EXPORT JDFXYPairRangeList{
	public:
	/**
	* copy ctor
	*/
	JDFXYPairRangeList(const JDFXYPairRangeList&rl);
	
	/**
	* copy ctor
	*/
	JDFXYPairRangeList& operator=(const JDFXYPairRangeList&rl);
	
	/** 
	* constructor that tokenizes a string
	*/
	JDFXYPairRangeList & operator=(const WString& s);
	
	/**
	* create fron string ctor
	* @param WString s the string to convert
	*/
	JDFXYPairRangeList(const WString& s=WString::emptyStr);
	
	/**
	* dtor
	*/
	virtual ~JDFXYPairRangeList();
		
	/**
	* Is x within this range
	* @param const JDFXYPair x the value to test
	* @return bool true if x is within this range, else false
	*/
	virtual bool InRange(const JDFXYPair & x);
	
	/**
	* Is range x within this range
	* @param const JDFXYPairRange x the range to test
	* @return bool true if x is within this range, else false
	*/
	virtual bool IsPartOfRange(const JDFXYPairRange & x);

	/**
	* Is range list 'x' within this range list
	* @param JDFXYPairRangeList x: the range list to test
	* @return bool: true if range list 'x' is within 'this' range list, else false
	*/
	bool IsPartOfRange(const JDFXYPairRangeList& x);

	/** 
	* append an double and concatenate it to the last range, if possible
	* @param JDFXYPair x the JDFXYPair to append to the list
	*/
	virtual void Append(const JDFXYPair & x);
	/**
	* Add a range r =rMin~rMax
	* @param JDFXYPair r the IntegerRange to append to the list
	*/
	virtual void Append(const JDFXYPairRange& r);
	
	/**
	* Add a Range defined by two ints xMin~xMax
	* @param JDFXYPair xMin the left value of the range to append to the list
	* @param JDFXYPair xMax the right value of the range to append to the list
	*/
	virtual void Append(const JDFXYPair & xMin, const JDFXYPair & xMax);
	/**
	* get the nth range element
	* note that this is the n'th range NOT the n'th element
	* @param int i index of the range to retrieve
	* @returm the Range at position i
	*/
	const JDFXYPairRange& at(int i) const;
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
	* @param JDFXYPairRange* i: element (range) to remove
	* @return JDFXYPairRange*: the first element remaining beyond removed element, or end() if no such element exists.
	*/
	void erase(int i) ;

	/**
	* A random-access iterator that points at the first element 
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return JDFXYPairRange*: random-access iterator
	*/
	JDFXYPairRange* begin();

	/**
	* Returns a random-access iterator that points just beyond the end of the sequence
	*
	* @return JDFXYPairRange*: random-access iterator
	*/
	JDFXYPairRange* end();

	/**
	* A constant random-access iterator that points at the first element
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return const JDFXYPairRange*: constant random-access iterator
	*/
	const JDFXYPairRange* begin() const;

	/**
	* Returns a constant random-access iterator that points just beyond the end of the sequence
	*
	* @return const JDFXYPairRange*: constant random-access iterator
	*/
	const JDFXYPairRange* end() const;
	
	/**
	* serialize to string
	* @return WString a list of ranges in the format a b c~d a f~g ...
	*/
	WString GetString()const;
	
	/**
	* Tests if 'this' is Ordered XYPairRangeList
	* return bool: true if 'this' is Ordnered XYPairRangeList
	*/
	bool IsOrdered();

	/**
	* Tests if 'this' is Unique Ordered IntegerRangeList
	* return bool: true if 'this' is Unique Ordnered IntegerRangeList
	*/
	bool IsUniqueOrdered();

	/**
	* Tests if 'this' is a XYPair List
	* return bool: true if 'this' contains no ranges
	*/
	bool IsList();

	/**
	* Tests if 'this' has only unique values
	* return bool: true if 'this' is unique
	*/
	bool IsUnique() const;

	
	private:
		void *pBase;
		
	};
	
};
#endif // !defined(AFX_JDFXYPairRangeList_H__)
