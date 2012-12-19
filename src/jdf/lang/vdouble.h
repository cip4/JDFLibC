/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The doubleernational Cooperation for the doubleegration of 
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
*        The doubleernational Cooperation for the doubleegration of 
*        Processes in  Prepress, Press and Postpress (www.cip4.org)"
*    Alternately, this acknowledgment may appear in the software itself,
*    if and wherever such third-party acknowledgments normally appear.
*
* 4. The names "CIP4" and "The doubleernational Cooperation for the doubleegration of 
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
* DISCLAIMED.  IN NO EVENT SHALL THE doubleERNATIONAL COOPERATION FOR
* THE doubleEGRATION OF PROCESSES IN PREPRESS, PRESS AND POSTPRESS OR
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
* USE, DATA, OR PROFITS; OR BUSINESS doubleERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
* ====================================================================
*
* This software consists of voluntary contributions made by many
* individuals on behalf of the The doubleernational Cooperation for the doubleegration 
* of Processes in Prepress, Press and Postpress and was
* originally based on software 
* copyright (c) 1999-2001, Heidelberger Druckmaschinen AG 
* copyright (c) 1999-2001, Agfa-Gevaert N.V. 
*  
* For more information on The doubleernational Cooperation for the 
* doubleegration of Processes in  Prepress, Press and Postpress , please see
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
* 140104 RP added = operator
* 231104 ES added vector iterator implementation - class vdoubleIterator
*
******************************************************************************/

#ifndef I_JDF_Vdouble_H
#define I_JDF_Vdouble_H

/******************************************************************************
*	Includes
******************************************************************************/ 
#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/lang/WString.h>

namespace JDF
{
	
/******************************************************************************
*	Forward declarations
******************************************************************************/ 
	
	class vdoubleIterator;
	/**
	* additional utility class for a map of WString
	* defines a key value map
	*/
	
	
	/**
	* utility class to enhance string vectors with some set-like features
	*/
	class JDFTOOLS_EXPORT vdouble{
	public:
		typedef ssize_t size_type;
		typedef vdoubleIterator iterator;
		typedef vdoubleIterator const_iterator;
		typedef double& reference;
		typedef const double& const_reference;
		
/*
* the empty vector
*/		
	static const vdouble emptyvdouble;

	public:
	/**
	* Empty constructor
		*/
		vdouble();
		/**
		* Copy constructor
		* @param vdouble&m: object of type vdouble to copy
		*/
		vdouble(const vdouble&m);
		/**
		* Conversion copy constructor
		* @param double i: object of type double to copy
		*/
		vdouble(double i);
		/**
		* Destructor
		*/
		//Matt-Start
		/**
		* Equivalence copy constructor
		*/
		vdouble & operator=(const vdouble &m);
		//Matt-End

		virtual ~vdouble();
		
		/**
		* Returns a constant reference to the element of the controlled sequence at position pos
		*
		* @param size_type pos: element index (position)
		* @return const_reference: a reference to the element of the controlled sequence at position pos
		*/
		const_reference at(size_type pos) const;
		
		/**
		* Returns a reference to the element of the controlled sequence at position pos
		*
		* @param size_type pos: element index (position)
		* @return reference: a reference to the element of the controlled sequence at position pos
		*/
		reference at(size_type pos);

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
		* @param int x
		*/
		void assign(size_type n, double x = 0);

		/**
		* Inserts a single element with value 'x' in the controlled sequence
		* in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert 'x' before 
		* @param int x: element to insert , defaults to 0
		* @return iterator: an iterator that points to the newly inserted element
		*/
		iterator insert(iterator it, const double x =0);

		/**
		* Inserts a repetition of 'n' elements of value 'x' in the controlled sequence
		* in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert repetition of elements 'x' before 
		* @param size_type n
		* @param int x
		*/
		void insert(iterator it, size_type n, double x);
		
		/**
		* Inserts the sequence [first, last] in front of the element pointed to by 'it'
		*
		* @param iterator it: the element to insert sequence before 
		* @param const_iterator first: first element of sequence to insert
		* @param const_iterator last: last element of sequence to insert
		*/
		void insert(iterator it, const_iterator first, const_iterator last);

		
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
		void push_back(const double str);
		
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
		* Returns true for an empty controlled sequence
		*
		* @return bool: true if empty
		*/
		bool empty() const;
		
		/**
		* Cleanup and empty the internal storge
		*/
		void clear() const;	
		
		/**
		* Serialize to a string
		* @param const WString& sep separator between strings
		* @param const WString& front string before the first entry
		* @param const WString& back string after the last entry
		* @return a tokenized string
		*/
		WString GetString(const WString& sep=WString::blank,const WString& front=WString::emptyStr, const WString& back=WString::emptyStr)const;
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
	class JDFTOOLS_EXPORT vdoubleIterator{
		friend class vdouble;
	public:
		/**
		* constructor
		*/
		vdoubleIterator();

		/**
		* do not use, this constructo is actually private but must be declared public due to name mangling problems
		*/
		vdoubleIterator(void*p, int ipos);

		/**
		* copy constructor
		*/
		vdoubleIterator(const vdoubleIterator & other);
		
		/**
		* dtor
		*/
		virtual ~vdoubleIterator();


		/**
		* copy constructor
		*/
		vdoubleIterator& operator =(const vdoubleIterator & other);

		/**
		* reference operator to simplify translation of ->first, ->second to  ->first(), ->second()
		*/
		const vdoubleIterator* operator->()const;

		/**
		* operator +
		* @param int i - int value to add
		* @return vdoubleIterator - the sum of 'this' + 'i'
		*/
		vdoubleIterator operator +(int i)const;

		/**
		* iteration for loops
		*/
		vdoubleIterator operator++();

		/**
		* iteration for loops
		*/
		vdoubleIterator operator++(int);

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator!=(const vdoubleIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator==(const vdoubleIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator>=(const vdoubleIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator<=(const vdoubleIterator & other) const;

		/**
		* inequivalence for loops
		* @return bool 
		*/
		bool operator>(const vdoubleIterator & other) const;

		/**
		* equivalence for loops
		* @return bool 
		*/
		bool operator<(const vdoubleIterator & other) const;
			

		vdouble::reference operator *();

		vdouble::const_reference operator *() const;


	private:

		void *vdoubleVector;
		int iPos;
	};

} // namespace JDF

#endif /* I_JDF_Vdouble_H */

