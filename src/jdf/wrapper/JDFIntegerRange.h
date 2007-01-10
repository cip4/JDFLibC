#if !defined(AFX_JDFIntegerRange_H__)
#define AFX_JDFIntegerRange_H__

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
/* ****************************************************************
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
// 180700 RP WString -> WString : all strings now 16 bit
// 300104 ES added ToVInt();
// 120204 ES added IsPartOfRange() for ranges 
// 301006 NB fixed JDFIntegerRange::InRange(), JDFIntegerRange::NElements()
// 071206 NB added GetString(), toString()
//
// JDFIntegerRange.h: interface for the JDFIntegerRange class.
//
*****************************************************************/

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "JDFRange.h"

namespace JDF{
	
/**
* Implements JDF ranges "x~y" for integers
* added functionality for 0~-1 type ranges i.e 0 to last
* Ranges include the end-points
	*/
	class JDF_WRAPPERCORE_EXPORT JDFIntegerRange:public IntegerRange{
	public:
	/** 
	* ctor
	* @param WString s the string that represents the IntegerRange 
	* @param xdef the default length of the InteggerRange i.e. the value that -1 represents
		*/
		JDFIntegerRange(const WString& s,int xdef=0):JDFRange<int>(s){
			SetDef(xdef);
		};
		
		/**
		* ctor for one int element
		* @note that is impossible to set xdef in this constructor due zo overloading ambiguity with
		* the constructor for two integers
		* @param int x the value of the range
		*/
		JDFIntegerRange(int x=0):JDFRange<int>(x){};
		
		/**
		* standard range ctor
		* @param int xMin the left value of the range
		* @param int xMax the rightt value of the range
		* @param xdef the default length of the InteggerRange i.e. the value that -1 represents
		*/
		JDFIntegerRange(const int xmin,const int xmax, const int xdef=0);
		
		/**
		* copy ctor
		*/
		JDFIntegerRange(const IntegerRange&r);
		
		/**
		* another copy ctor
		*/
		JDFIntegerRange(const JDFIntegerRange&r);
		
		/**
		* copy ctor
		*/
		inline JDFIntegerRange& operator =(int r);

		/**
		* copy ctor
		*/
		virtual JDFIntegerRange& operator =(const IntegerRange&r);

		/**
		* copy ctor
		*/
		virtual JDFIntegerRange& operator =(const JDFIntegerRange&r);

		/**
		* yactor
		*/
		virtual JDFIntegerRange& operator =(const WString& s);
		
		/**
		* destructor
		*/
		virtual ~JDFIntegerRange(){};
		
		/**
		* Is x within this range
		* @param const int x the value to test
		* @return bool true if x is within this range, else false
		*/
		virtual bool InRange(const int& x) const;
		
		/**
		* Is range 'x' within this range
		* @param JDFIntegerRange x: the range to test
		* @return bool true if range x is within this range, else false
		*/
		virtual bool IsPartOfRange(const JDFIntegerRange x);

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
		virtual int GetDef();
		
		/**
		* number of elements that this range represents
		* @return int the number of elements represented by this
		*/
		virtual int NElements()const;
		
		/** 
		* value of the ith element in the range
		* Element(2) of 1~4 is 3
		* Element(0) of 4~1 is 4
		* Element(-2) of 4~1 is 2
		* @param int i position within the logical range, negative number count from the back
		* @return value of the logical ith element
		*
		*/
		virtual int Element(const int i)const;
		
		/**
		* the value of the left range element
		* this is always the left value, i.e. no chek for min or max is done
		* @return int the left value
		*/
		virtual int GetLeft() const;
		
		/** 
		* the value of the right range element
		* this is always the right value, i.e. no chek for min or max is done
		* @return int the right value
		*/
		virtual int GetRight() const;
		
		/**
		* attempts to append a value to this range, returns true if possible
		*
		* will extend an upward sorted list if x == xRight+1
		* will extend a downward sorted list if x == xRight-1
		* it will neither change ordering by prepending in front of the range nor swallow an element x==xRight
		* @return false if the element is not the next element in the list
		*/
		virtual bool Append(const int x);

		/**
		* Converts an IntegerRange into vector of integers,
		* that contains all range elements <br>
		* e.g. range="3~5" will be transformed into vector of int, that contains 3,4,5
		* @param int maxelem: the maximum number of elements in a vector, 
		* limits number of vector elements in case of INF, default=1000
		*
		* @return vint: transformed Range into vector of integers
		*/
		virtual vint ToVInt(int maxelem=1000) const;

		/**
		* toString
		*
		* @return WString
		*/
		WString toString() const;

		/**
		* GetString
		* overwrites inherited method GetString() <br>
		* deprecated, use toString()
		*
		* @return WString
		*/
		WString GetString() const;



	protected:

		/// standard initialization
		virtual void init(int x, int y, int xdef=0);
	};
}

#endif // !defined(AFX_JDFIntegerRange_H__)
