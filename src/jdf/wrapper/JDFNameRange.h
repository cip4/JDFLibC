/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The International Cooperation for the Integration of 
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
// created  04.November.2004
//
// JDNameRange.h: interface for the JDFNameRange class.
//
*/
#if !defined(_JDFNameRange_H__)
#define _JDFNameRange_H__

#include <jdf/lang/vWString.h>
#include <jdf/wrappercore/JDFException.h>
#include <jdf/lang/Exception.h>

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

namespace JDF{



/**
* Range for names (NMTOKENS)
* Implements Name ranges in form "x ~ y"
	*/
	class JDF_WRAPPERCORE_EXPORT JDFNameRange{
		
	public:

	/**
	* empty range ctor
		*/
		JDFNameRange();
		
		/**
		* copy ctor
		*/
		JDFNameRange(const JDFNameRange&r);
		
		/**
		* copy equivalance operator
		*/
		JDFNameRange& operator =(const JDFNameRange&r);
		
		/** 
		* Construct a range from a string
		* @throws illegal string exception
		*/
		JDFNameRange(const WString& s);
		
		/**
		* copy equivalance operator
		*/
		JDFNameRange& operator =(const WString& s);

		/**
		* ctor
		* creates a DateTime range defined by xmin to xmax
		*/
		JDFNameRange(const WString & xmin, const WString & xmax);


		/**
		* dtor
		*/
		~JDFNameRange();
		
		/**
		* returns true if x is within the range defined by 'this'
		* @param WString& x point that is to be compared with 'this'
		* @return true if x is within the range defined by 'this'
		*/
		bool InRange(const WString & x)const;
		
		/**
		* returns true if range 'x' is within the range defined by 'this'
		* @param JDFNameRange 'x': range that is to be compared with 'this'
		* @return bool: true if range 'x' is within the range defined by 'this'
		*/
		bool IsPartOfRange(const JDFNameRange& x)const;

		/**
		* serialized as string
		* @return WString a string in the format xmin~xmax
		*/
		WString GetString() const;

		/**
		* serialized as string
		* @return WString a string in the format xmin ~ xmax
		*/
		operator WString();
		
		/**
		* boolean equivalence
		* @return bool true if the ranges are equivalent
		*/
		bool operator ==(const JDFNameRange& g)const;

		/**
		* boolean equivalence
		* @return bool true if the ranges are not equivalent
		*/
		bool operator !=(const JDFNameRange& g)const ;

		/**
		* Get the left of the two range deliminators xmin ~ xmax
		* @return WString the left value
		*/
		WString GetLeft() const;

		/**
		* Get the right of the two range deliminators xmin ~ xmax
		* @return WString the right value
		*/
		WString GetRight() const;
		
		/**
		* set the right of the two range deliminators xmin ~ xmax
		* @return WString the right value
		*/
		void SetRight(const WString& right);

		/**
		* Get the left of the two range deliminators xmin ~ xmax
		* @return WString the left value
		*/
		void SetLeft(const WString& left);

	protected:
		
	/**
	* ctor initialization
		*/
		void init(const WString & x, const WString & y){
			xMin=x;
			xMax=y;
		}
				
		/**
		* first, left element
		*/
		WString xMin;

		/**
		* second, right element
		*/
		WString xMax;
		
	}; // end of class

	
#define NameRange JDFNameRange

};// namespace JDF
#endif // !defined(_JDFNameRange_H__)

