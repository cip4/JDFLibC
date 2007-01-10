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
/*
// ////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  04.February.2004
// 120204 ES added IsPartOfRange() for ranges 
// 300304 ES added operator !=
//
// JDFDateTimeRange.h: interface for the JDFDateTimeRange class.
// used to describe ranges of time points in resources
//
*/
#if !defined(_JDFDateTimeRange_H__)
#define _JDFDateTimeRange_H__

#include <jdf/lang/vWString.h>
#include <jdf/wrappercore/JDFException.h>
#include <jdf/lang/Exception.h>
#include "jdf/wrapper/JDFDate.h"

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

namespace JDF{


/**
* Implements DateTime ranges in form "x ~ y"  
* Ranges include the end-points
	*/
	class JDF_WRAPPERCORE_EXPORT JDFDateTimeRange{
		
	public:

	/**
	* empty range ctor
		*/
		JDFDateTimeRange();
		
		/**
		* copy ctor
		* @param JDFDateTimeRange& r: dateTime range to make a copy of
		*/
		JDFDateTimeRange(const JDFDateTimeRange&r);
		
		/**
		* copy equivalance operator
		* @param JDFDateTimeRange& r: dateTime range to make a copy of
		*/
		JDFDateTimeRange& operator =(const JDFDateTimeRange&r);
		
		/** 
		* Construct a range from a string
		* @param WString& s: string representation of the dateTime range
		* @throws IllegalArgumentException - if a string has not a valid format
		*/
		JDFDateTimeRange(const WString& s);
		
		/**
		* copy equivalance operator
		* @param WString& s: string representation of the dateTime range
		* @throws IllegalArgumentException - if a string has not a valid format
		*/
		JDFDateTimeRange& operator =(const WString& s);

		/**
		* ctor
		* creates a DateTime range defined by xmin and xmax
		*
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate & xmin: left range element
		* @param JDFDate & xmax: right range element
		*/
		JDFDateTimeRange(const JDFDate & xmin, const JDFDate & xmax);

		/**
		* ctor
		* creates a DateTime range defined by a single JDFDate element x
		*
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate & x: single range element
		*/
		JDFDateTimeRange(const JDFDate& x);

		/**
		* copy equivalance operator
		*
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate & x: single range element
		*/
		JDFDateTimeRange& operator =(const JDFDate& x);

		/**
		* dtor
		*/
		~JDFDateTimeRange();
		
		/**
		* returns true if 'x' is within the range defined by 'this'
		*
		* @since 11.11.2004 takes the parameters of type JDFDate instead of MyDate
		* @param JDFDate& x: point that is to be compared with 'this'
		* @return bool: true if 'x' is within the range defined by 'this'
		*/
		bool InRange(const JDFDate & x)const;
		
		/**
		* returns true if range 'x' is within the range defined by 'this'
		* @param JDFDateTimeRange& 'x': range that is to be compared with 'this'
		* @return bool: true if range 'x' is within the range defined by 'this'
		*/
		bool IsPartOfRange(const JDFDateTimeRange& x)const;

		/**
		* serialized as string
		* @return WString - a string in the format xmin~xmax
		*/
		WString GetString() const;

		/**
		* serialized as string
		* @return WString a string in the format xmin ~ xmax
		*/
		operator WString();
		
		/**
		* boolean equivalence
		* @param JDFDateTimeRange& 'r': range that is to be compared with 'this'
		* @return bool: true if the ranges are equivalent
		*/
		bool operator ==(const JDFDateTimeRange& r)const;

		/**
		* boolean equivalence
		* @param JDFDateTimeRange& 'r': range that is to be compared with 'this'
		* @return bool: true if the ranges are not equivalent
		*/
		bool operator !=(const JDFDateTimeRange& r)const ;

		/**
		* Get the left of the two range deliminators xmin ~ xmax
		* @return JDFDate: the left value
		*/
		JDFDate GetLeft() const;

		/**
		* Get the right of the two range deliminators xmin ~ xmax
		* @return JDFDate: the right value
		*/
		JDFDate GetRight() const;
		
	protected:
		
	/**
	* ctor initialization
		*/
		void init(const JDFDate & x, const JDFDate & y){
			xMin=x;
			xMax=y;
		}
				
		/**
		* first, left element
		*/
		JDFDate xMin;

		/**
		* second, right element
		*/
		JDFDate xMax;
		
	}; // end of class
	

};// namespace JDF
#endif // !defined(_JDFDateTimeRange_H__)

