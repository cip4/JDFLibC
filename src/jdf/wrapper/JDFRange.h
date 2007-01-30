#if !defined(_JDFRange_H__)
#define _JDFRange_H__

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
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 120204 ES added InRange() for ranges and lists of ranges
//
// JDFRange.h: interface for the JDFRange class.
// used to describe ranges in resources
// RangeType may be int, double, string, xypair, shape or rectangle
//
*/

#include <jdf/lang/vWString.h>
#include <jdf/wrappercore/JDFException.h>
#include <jdf/lang/Exception.h>
#include "JDFNumTypeList.h"


#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

namespace JDF{


	class JDF_WRAPPERCORE_EXPORT JDFRangeBase{

	public:
	/**
	* dtor
		*/
		virtual ~JDFRangeBase();

	protected:		
		JDFRangeBase(){};
		
	};

/**
* Implements JDF ranges "x~y" for various data types  
* Ranges include the end-points
	*/

	template<class RangeType> class JDFRange: public JDFRangeBase{
		
	public:

	/**
	* template range definition
		*/
		typedef JDFRange<RangeType> _rt;
		/**
		* returns true if 'x' is within the range defined by 'this'
		* @param RangeType& x: point that is to be compared with 'this'
		* @return bool: true if 'x' is within the range defined by 'this'
		*/
		virtual bool InRange(const RangeType & x)const{
			return (x>=xMin)&&(x<=xMax);
		}

		/**
		* returns true if range 'x' is within the range defined by 'this'
		* @param JDFRange& x: range that is to be compared with 'this'
		* @return bool: true if 'x' is within the range defined by 'this'
		*/
		virtual bool IsPartOfRange(const JDFRange<RangeType> & x)const{
			return (x.xMin>=xMin)&&(x.xMax<=xMax);
		}

		/** 
		* Construct a range from a string
		* @throws illegal string exception
		*/
		inline JDFRange(const WString& s){
			*this=s;
		}
		/**
		* empty range ctor
		*/
		inline JDFRange(){
			init(RangeType(),RangeType());
		}
		
		/**
		* copy ctor
		*/
		inline JDFRange(const _rt&r){
			init(r.GetLeft(),r.GetRight());
		}
		/**
		* copy ctor
		*/
		inline JDFRange& operator =(RangeType r){
			init(r,r);
			return *this;
		}
		/**
		* copy ctor
		*/
		inline JDFRange& operator =(const _rt&r){
			init(r.GetLeft(),r.GetRight());
			return *this;
		}
		/**
		* yactor
		*/
		inline JDFRange& operator =(const WString& s){
			vWString vs=s.Tokenize(WString::tilde);
			if(vs.size()==1){
				RangeType x=(RangeType)s;
				init(x,x);
			}else if(vs.size()==2){
				WString ms=vs[0];
				RangeType xmin=(RangeType)ms;
				ms=vs[1];
				RangeType xmax=(RangeType)ms;
				init(xmin,xmax);
			}else{
				throw IllegalArgumentException("JDFRange illegal string: "+s);
			}
			return *this;
		}

		/**
		* ctor
		* creates a range of RangeType defined by xmin to xmax
		*/
		inline JDFRange(const RangeType & xmin, const RangeType & xmax){
			init(xmin,xmax);
		}
		/**
		* ctor
		* creates a range of RangeType defined by x
		*/
		inline JDFRange(RangeType x){
			init(x,x);
		}
		/**
		* dtor
		*/
		virtual ~JDFRange(){};
		
		/**
		* serialized as string
		* @return WString a string in the format xmin~xmax
		*/
		WString GetString()const{
			if(xMin==xMax){
				return WString(xMin);
			}else{
				return WString(xMin)+WString(L" ~ ")+WString(xMax);
			}
		}
		/**
		* serialized as string
		* @return WString a string in the format xmin~xmax
		*/
		inline operator WString(){
			return GetString();
		};
		
		/**
		* boolean equivalence
		* @return bool true if the ranges are equivalent
		*/
		virtual bool operator ==(const JDFRange& g)const {
			return (xMin==g.xMin)&&(xMax==g.xMax);
		}

		/**
		* boolean equivalence
		* @return bool true if the ranges are not equivalent
		*/
		virtual bool operator !=(const JDFRange& g)const {
			return (xMin!=g.xMin)||(xMax!=g.xMax);
		}

		/**
		* Get the left of the two range deliminators xmin~xmax
		* @return RangeType the left value
		*/
		virtual RangeType GetLeft() const {
			return xMin;
		};

		/**
		* Set the left of the two range deliminators xmin~xmax
		* @param RangeType& left: the left value
		*/
		virtual void SetLeft(const RangeType& left) {
			xMin=left;
		};

		/**
		* Get the right of the two range deliminators xmin~xmax
		* @return RangeType the right value
		*/
		virtual RangeType GetRight() const {
			return xMax;
		};
		
		/**
		* Set the right of the two range deliminators xmin~xmax
		* @param RangeType& right: the right value
		*/
		virtual void SetRight(const RangeType& right) {
			xMax=right;
		};


	protected:
		
	/**
	* ctor initialization
		*/
		void init(const RangeType & x, const RangeType & y){
			xMin=x;
			xMax=y;
			xDef=RangeType();
		}
		

		/**
		* first, left element
		*/
		RangeType xMin;
		/**
		* second, right element
		*/
		RangeType xMax;
		/**
		* default for negative page numbers - used only for integers but stored here for safe casting
		*/
		RangeType xDef;
	}; // end of class
	
	/**
	* class of range of double
	*/
	typedef JDFRange<double> NumberRange;
	/**
	* class of range of integer
	*/
	typedef JDFRange<int> IntegerRange;
	
	/**
	* class of range of XYPairs
	*/
	typedef JDFRange<JDFXYPair> JDFXYPairRange;
	/**
	* class of range of shapes
	*/
	typedef JDFRange<JDFShape> JDFShapeRange;
	/**
	* class of range of rectangles
	*/
	typedef JDFRange<JDFRectangle> JDFRectangleRange;
	

	// ES 04.11.2004  NameRange class no longer based on template
	// typedef JDFRange<WString> NameRange;  



};// namespace JDF
#endif // !defined(_JDFRange_H__)

