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
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 141103 RP added string operator =
// 170205 RP added (int) constructor for JDFIntegerList
// 301006 NB fixed JDFIntegerList::GetString(), JDFNumberList::GetString()
//
// JDFRange.h: interface for the JDFRange class.
// used to describe ranges in resources
// RangeType may be int, double or string
//
*/
#if !defined(_JDFNumTypeList_H__)
#define _JDFNumTypeList_H__

#pragma warning( disable : 4786 ) // long debug names from stl


#include "jdf/util/myuti.h"
#include "jdf/lang/vdouble.h"
#include "jdf/lang/vint.h"
#include "jdf/wrappercore/JDFException.h"



#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

namespace JDF{
	
/**
* virtual parent class for fixed n value lists: xypair, rectangle, matrix, xxxColor etc.
* in JDF these are formatted as a ws separated list of values
	*/
	class JDF_WRAPPERCORE_EXPORT JDFNumList : public vdouble{
	public:
		
	/**
	* protected ctor
		*/
		JDFNumList(const WString& s, int siz);
		
		/**
		* empty list initialization
		*/
		JDFNumList(int siz=0);
		
		/**
		*copy ctor
		*/
		JDFNumList(const vdouble&m);
		/**
		*copy ctor
		*/
		JDFNumList(const JDFNumList&m);
		
		/**
		* copy ctor
		*/
		JDFNumList& operator =(const vdouble&m);

		/**
		* copy ctor
		*/
		JDFNumList& operator =(const JDFNumList&m);
		
		/**
		* copy ctor
		*/
		JDFNumList& operator =(const WString&m);

		/**
		dtor
		*/
		virtual ~JDFNumList();
		/**
		* make it pure abstract
		*/
		virtual bool IsValid();
		
	public:
		
	/**
	* scale this by factor
	* @since 150601
	* @param double factor the factor to scale with
		*/
		void Scale(double factor);
		
		/**
		* @since 150601
		* add a linear offset to this
		* @param double offset the factor to scale with
		*/
		void Offset(double offset);
		
		
		/**
		* serialize to a string in the format "a b c d ..."
		* @return a string representation
		*/
		WString GetString() const;
		
		/**
		* serialized as string
		* @return WString a string in the format xmin~xmax
		*/
		operator WString() const;
		
		
	};

	class JDF_WRAPPERCORE_EXPORT JDFNumberList : public JDFNumList{
	public:
		/**
		* string ctor
		*/
		inline JDFNumberList(const WString& s):JDFNumList(s,0){};
		
		/**
		* empty  ctor
		*/
		inline JDFNumberList():JDFNumList(0){};
		/**
		* copy ctor
		*/
		inline JDFNumberList(const vdouble&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFNumberList(const JDFNumberList&m):JDFNumList(){
			*this=m;
		};

		/**
		* copy ctor
		*/
		JDFNumberList& operator =(const vdouble&m);
		/**
		* copy ctor
		*/
		JDFNumberList& operator =(const JDFNumberList&m);

		/**
		* copy ctor
		*/
		JDFNumberList& operator =(const WString&m);

		/**
		* dtor
		*/
		virtual ~JDFNumberList(){};
		/**
		* always true
		*/
		virtual bool IsValid();
	};

/**
* virtual parent class for fixed n value lists: xypair, rectangle, matrix, xxxColor etc.
* in JDF these are formatted as a ws separated list of values
	*/
	class JDF_WRAPPERCORE_EXPORT JDFIntList : public vint{
	public:
		
	/**
	* protected ctor
		*/
		JDFIntList(const WString& s, int siz);
		
		/**
		* empty list initialization
		*/
		JDFIntList(int siz=0);
		
		/**
		*copy ctor
		*/
		JDFIntList(const JDFIntList&m);		
		
		/**
		*copy ctor
		*/
		JDFIntList(const vint&m);
		
		/**
		* copy ctor
		*/
		JDFIntList& operator =(const vint&m);
		/**
		* copy ctor
		*/
		JDFIntList& operator =(const JDFIntList&m);
		/**
		* copy ctor
		*/
		JDFIntList& operator =(const WString&m);

		/**
		dtor
		*/
		virtual ~JDFIntList();
		/**
		* make it pure abstract
		*/
		virtual bool IsValid();
		
	public:
		
	/**
	* scale this by factor
	* @since 150601
	* @param double factor the factor to scale with
		*/
		void Scale(int factor);
		
		/**
		* @since 150601
		* add a linear offset to this
		* @param double offset the factor to scale with
		*/
		void Offset(int offset);
		
		
		/**
		* serialize to a string in the format "a b c d ..."
		* @return a string representation
		*/
		WString GetString() const;
		
		/**
		* serialized as string
		* @return WString a string in the format xmin~xmax
		*/
		operator WString() const;		
	};


	/**
	*  class for arbitrary n value lists: 
	* in JDF these are formatted as a ws separated list of values
	*/
	class JDF_WRAPPERCORE_EXPORT JDFIntegerList : public JDFIntList{
	public:
		/**
		* string ctor
		*/
		inline JDFIntegerList(const WString& s):JDFIntList(s,0){};
		
		/**
		* empty  ctor
		*/
		inline JDFIntegerList():JDFIntList(0){};

		/**
		*  ctor for exactly one int
		*/
		JDFIntegerList(int i);

		/**
		* copy ctor
		*/
		inline JDFIntegerList(const vint&m):JDFIntList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFIntegerList(const JDFIntegerList&m):JDFIntList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		JDFIntegerList& operator =(const JDFIntegerList&m);
		/**
		* copy ctor
		*/
		JDFIntegerList& operator =(const vint&m);
		/**
		* copy ctor
		*/
		JDFIntegerList& operator =(const WString&m);
		/**
		* dtor
		*/
		virtual ~JDFIntegerList(){};
		/**
		* always true
		*/
		virtual bool IsValid();
	};


	/**
	* class for 6 value ctm
	*/
	class JDF_WRAPPERCORE_EXPORT JDFMatrix : public JDFNumList{
	public:
	/**
	* ctor from a string
		*/
		inline JDFMatrix(const WString& s):JDFNumList(s,6){};
		/**
		* matrix ctor from 6 double
		* @param double a 
		* @param double b 
		* @param double c 
		* @param double d 
		* @param double Tx 
		* @param double Zy 
		*/
		JDFMatrix(double a, double b, double c, double d, double Tx, double Ty );
		
		/**
		* empty  ctor
		*/
		inline JDFMatrix():JDFNumList(6){};
		/**
		* copy ctor
		*/
		inline JDFMatrix(const vdouble&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFMatrix(const JDFMatrix&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		JDFMatrix& operator =(const JDFMatrix&m);
		/**
		* copy ctor
		*/
		JDFMatrix& operator =(const vdouble&m);
		/**
		* copy ctor
		*/
		JDFMatrix& operator =(const WString&m);
		/**
		* dtor
		*/
		virtual ~JDFMatrix(){};
		/**
		* default validator
		*/
		virtual bool IsValid();

		/**
		* get a 
		* @return double a 
		*/
		double GetA()const;

		/**
		* get b
		* @return double b 
		*/
		double GetB()const;

		/**
		* get c
		* @return double c 
		*/
		double GetC()const;

		/**
		* get d
		* @return double d 
		*/
		double GetD()const;

		/**
		* get Tx
		* @return double Tx 
		*/
		double GetTx()const;

		/**
		* get Ty
		* @return double Ty 
		*/
		double GetTy()const;

		/**
		* set a
		* @return double a 
		*/
		void SetA (double a);

		/**
		* set b
		* @return double b 
		*/
		void SetB(double b);
		
		/**
		* set c
		* @return double c 
		*/
		void SetC(double c);

		/**
		* set d
		* @return double urx 
		*/
		void SetD(double d);
		
		/**
		* set Tx 
		* @return double Tx 
		*/
		void SetTx(double Tx);

		/**
		* set Ty
		* @return double Ty 
		*/
		void SetTy(double Ty);

		
		/**
		* equality operator
		* @param JDFMatrix & m: the JDFMatrix object to compare to
		* @return bool true if 'this' and 'm' are equal
		*/
		bool operator ==(const JDFMatrix & m)const;

		/**
		* equality operator
		* @param JDFMatrix & m: the JDFMatrix object to compare to
		* @return bool true if 'this' and 'm' are not equal
		*/
		bool operator !=(const JDFMatrix & m)const;

		/**
		* Tests, if the defined 'test' matrix equal 'this' matrix +/- Tolerance
		*
		* @param JDFMatrix& test: the matrix to test
		* @param double nT: negative tolerance
		* @param double pT: positive tolerance
		* @return bool: true if 'this' and 'test' +/- Tolerance are equal
		*/
		bool FitsTolerance(const JDFMatrix& test, double nT=0.000001, double pT=0.000001) const;

	};
	/**
	* class for 4 value rectangle
	*/
	class JDF_WRAPPERCORE_EXPORT JDFRectangle : public JDFNumList{
	public:
	/**
	* ctor from a string
		*/
		inline JDFRectangle(const WString& s):JDFNumList(s,4){};
		/**
		* JDFRectangle ctor from 4 double
		* @param double llx lower left x coordinate 
		* @param double lly lower left y coordinate 
		* @param double urx upper right x coordinate 
		* @param double ury upper right y coordinate 
		*/
		JDFRectangle(double llx, double lly, double urx, double ury);
		
		/**
		* empty  ctor
		*/
		inline JDFRectangle():JDFNumList(4){};
		/**
		* copy ctor
		*/
		inline JDFRectangle(const vdouble&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFRectangle(const JDFRectangle&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		JDFRectangle& operator =(const vdouble&m);
		/**
		* copy ctor
		*/
		JDFRectangle& operator =(const JDFRectangle&m);
		/**
		* copy ctor
		*/
		JDFRectangle& operator =(const WString&m);
		/**
		* dtor
		*/
		virtual ~JDFRectangle(){};
		/**
		* default validator
		*/
		virtual bool IsValid();

		/**
		* get Llx 
		* @return double llx 
		*/
		double GetLlx()const;

		/**
		* get Lly
		* @return double lly 
		*/
		double GetLly()const;

		/**
		* get Urx
		* @return double urx 
		*/
		double GetUrx()const;

		/**
		* get Ury
		* @return double ury 
		*/
		double GetUry()const;

		/**
		* set Llx 
		* @return double llx 
		*/
		void SetLlx(double llx);

		/**
		* set Lly
		* @return double lly 
		*/
		void SetLly(double lly);

		/**
		* set Urx
		* @return double urx 
		*/
		void SetUrx(double urx);

		/**
		* set Ury
		* @return double urx 
		*/
		void SetUry(double urx);
		

		/**
		* equality operator
		* @param JDFRectangle & r: the JDFRectangle object to compare to
		* @return bool true if 'this' and 'r' are equal
		*/
		bool operator ==(const JDFRectangle & r)const;

		/**
		* equality operator
		* @param JDFRectangle & r: the JDFRectangle object to compare to
		* @return bool true if 'this' and 'r' are not equal
		*/
		bool operator !=(const JDFRectangle & r)const;
		
		/**
		* equality operator
		* @param JDFRectangle & r: the JDFRectangle object to compare to
		* @return bool true if 'this' >= 'r'
		*/
		bool operator >=(const JDFRectangle & r)const;
		
		/**
		* equality operator
		* @param JDFRectangle & r: the JDFRectangle object to compare to
		* @return bool true if 'this' <= 'r'
		*/
		bool operator <=(const JDFRectangle & r)const;
		
		/**
		* equality operator
		* @param JDFRectangle & r: the JDFRectangle object to compare to
		* @return bool true if 'this' > 'r'
		*/
		bool operator >(const JDFRectangle & r)const;

		/**
		* equality operator
		* @param JDFRectangle & r: the JDFRectangle object to compare to
		* @return bool true if 'this' < 'r'
		*/
		bool operator <(const JDFRectangle & r)const;
		
	};
	
	/**
	* class for 4 value CMYK Color
	*/
	class JDF_WRAPPERCORE_EXPORT JDFCMYKColor : public JDFNumList{
	public:
		
	/**
	* ctor from a string
		*/
		inline JDFCMYKColor(const WString& s):JDFNumList(s,4){};
		/**
		* empty  ctor
		*/
		inline JDFCMYKColor():JDFNumList(4){};
		/**
		* JDFCMYKColor ctor from 4 double
		* @param double c 
		* @param double m 
		* @param double y 
		* @param double k 
		*/
		JDFCMYKColor(double c, double m, double y, double k);
		/**
		* copy ctor
		*/
		inline JDFCMYKColor(const vdouble&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFCMYKColor(const JDFCMYKColor&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		JDFCMYKColor& operator =(const vdouble&m);
		/**
		* copy ctor
		*/
		JDFCMYKColor& operator =(const JDFCMYKColor&m);
		/**
		* copy ctor
		*/
		JDFCMYKColor& operator =(const WString&m);
		/**
		* dtor
		*/
		virtual ~JDFCMYKColor(){};
		/**
		* default validator
		*/
		virtual bool IsValid();
		
	};
	
	/**
	* class for 3 value shape
	*/
	class JDF_WRAPPERCORE_EXPORT JDFShape : public JDFNumList{
	public:
	/**
	* ctor from a string
		*/
		inline JDFShape(const WString& s):JDFNumList(s,3){};
		/**
		* empty  ctor
		*/
		inline JDFShape():JDFNumList(3){};
		/**
		* JDFShape ctor from 3 double
		* @param double x Width of the shape 
		* @param double y Height of the shape 
		* @param double z Depth of the Shape
		* @tbd what the hell is a b c??
		*/
		JDFShape(double a, double b, double c);
		/**
		* copy ctor
		*/
		inline JDFShape(const vdouble&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFShape(const JDFShape&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		JDFShape& operator =(const vdouble&m);
		/**
		* copy ctor
		*/
		JDFShape& operator =(const JDFShape&m);
		/**
		* copy ctor
		*/
		JDFShape& operator =(const WString&m);
		/**
		* dtor
		*/
		virtual ~JDFShape(){};
		/**
		* default validator
		*/
		virtual bool IsValid();

		/**
		* get A 
		* @return double a 
		*/
		double GetA()const;

		/**
		* get B
		* @return double b 
		*/
		double GetB()const;

		/**
		* get C
		* @return double c 
		*/
		double GetC()const;

		/**
		* set A 
		* @return double a 
		*/
		void SetA(double a);

		/**
		* set B
		* @return double b 
		*/
		void SetB(double b);

		/**
		* set C
		* @return double c 
		*/
		void SetC(double c);
		
		/**
		* equality operator
		* @param JDFShape & abc: the JDFShape object to compare to
		* @return bool true if 'this' and 'abc' are equal
		*/
		bool operator ==(const JDFShape & abc)const;
		
		/**
		* equality operator
		* @param JDFShape & abc: the JDFShape object to compare to
		* @return bool true if 'this' and 'abc' are not equal
		*/
		bool operator !=(const JDFShape & abc)const;
		
		/**
		* equality operator
		* @param JDFShape & abc: the JDFShape object to compare to
		* @return bool true if 'this' >= 'abc'
		*/
		bool operator >=(const JDFShape & abc)const;
		
		/**
		* equality operator
		* @param JDFShape & abc: the JDFShape object to compare to
		* @return bool true if 'this' <= 'abc'
		*/
		bool operator <=(const JDFShape & abc)const;
		
		/**
		* equality operator
		* @param JDFShape & abc: the JDFShape object to compare to
		* @return bool true if 'this' > 'abc'
		*/
		bool operator >(const JDFShape & abc)const;

		/**
		* equality operator
		* @param JDFShape & abc: the JDFShape object to compare to
		* @return bool true if 'this' < 'abc'
		*/
		bool operator <(const JDFShape & abc)const;

	};
	
	/**
	* class for 3 value RGB Color
	*/
	class JDF_WRAPPERCORE_EXPORT JDFRGBColor : public JDFNumList{
	public:
	/**
	* ctor from a string
		*/
		inline JDFRGBColor(const WString& s):JDFNumList(s,3){};
		/**
		* empty  ctor
		*/
		inline JDFRGBColor():JDFNumList(3){};
		/**
		* JDFRGBColor ctor from 3 double
		* @param double r 
		* @param double g 
		* @param double b 
		*/
		JDFRGBColor(double r, double g, double b);
		/**
		* copy ctor
		*/
		inline JDFRGBColor(const vdouble&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFRGBColor(const JDFRGBColor&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		JDFRGBColor& operator =(const vdouble&m);
		/**
		* copy ctor
		*/
		JDFRGBColor& operator =(const JDFRGBColor&m);
		/**
		* copy ctor
		*/
		JDFRGBColor& operator =(const WString&m);
		/**
		* dtor
		*/
		virtual ~JDFRGBColor(){};
		/**
		* default validator
		*/
		virtual bool IsValid();
		
	};
	/**
	* class for 3 value LAB Color
	*/
	class JDF_WRAPPERCORE_EXPORT JDFLabColor : public JDFNumList{
	public:
	/**
	* ctor from a string
		*/
		inline JDFLabColor(const WString& s):JDFNumList(s,3){};
		/**
		* empty  ctor
		*/
		inline JDFLabColor():JDFNumList(3){};
		/**
		* JDFLabColor ctor from 3 double
		* @param double L 
		* @param double a 
		* @param double b 
		*/
		JDFLabColor(double L, double a, double b);
		/**
		* copy ctor
		*/
		inline JDFLabColor(const vdouble&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFLabColor(const JDFLabColor&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		JDFLabColor& operator =(const vdouble&m);
		/**
		* copy ctor
		*/
		JDFLabColor& operator =(const JDFLabColor&m);
		/**
		* copy ctor
		*/
		JDFLabColor& operator =(const WString&m);
		/**
		* dtor
		*/
		virtual ~JDFLabColor(){};
		/**
		* default validator
		*/
		virtual bool IsValid();
		
	};
	
	/**
	* class for 2 value xypair
	*/
	class JDF_WRAPPERCORE_EXPORT JDFXYPair : public JDFNumList{
	public:
	/**
	* ctor from a string
		*/
		inline JDFXYPair(const WString& s):JDFNumList(s,2){};
		/**
		* empty  ctor
		*/
		inline JDFXYPair():JDFNumList(2){};
		/**
		* JDFXYPair ctor from x double
		* @param double x 
		* @param double y 
		*/
		JDFXYPair(double x, double y);
		/**
		* copy ctor
		*/
		inline JDFXYPair(const vdouble&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		inline JDFXYPair(const JDFXYPair&m):JDFNumList(){
			*this=m;
		};
		/**
		* copy ctor
		*/
		JDFXYPair& operator =(const vdouble&m);
		/**
		* copy ctor
		*/
		JDFXYPair& operator =(const JDFXYPair&m);
		/**
		* copy ctor
		*/
		JDFXYPair& operator =(const WString&s);
		/**
		* dtor
		*/
		virtual ~JDFXYPair(){};
		/**
		* default validator
		*/
		virtual bool IsValid();
		/**
		* get X 
		* @return double x 
		*/
		double GetX()const;
		/**
		* get y
		* @return double y 
		*/
		double GetY()const;
		/**
		* set X 
		* @return double x 
		*/
		void SetX(double x);
		/**
		* set y
		* @return double y 
		*/
		void SetY(double y);
		
		/**
		* equality operator
		* @param JDFXYPair xy the pair to compare to
		* @return bool true if both are equal
		*/
		bool operator ==(const JDFXYPair&xy)const;
		/**
		* inequality operator
		* @param JDFXYPair xy the pair to compare to
		* @return bool true if both are not equal
		*/
		bool operator !=(const JDFXYPair&xy)const;
		/**
		* ge operator
		* @param JDFXYPair xy the pair to compare to
		* @return bool true if this >= xy
		*/
		bool operator >=(const JDFXYPair&xy)const;
		/**
		* le operator
		* @param JDFXYPair xy the pair to compare to
		* @return bool true if this <= xy
		*/
		bool operator <=(const JDFXYPair&xy)const;
		/**
		* gt operator
		* @param JDFXYPair xy the pair to compare to
		* @return bool true if this > xy
		*/
		bool operator >(const JDFXYPair&xy)const;
		/**
		* lt operator
		* @param JDFXYPair xy the pair to compare to
		* @return bool true if this < xy
		*/
		bool operator <(const JDFXYPair&xy)const;
	};
	
	
};// namespace JDF
#endif // !defined(_JDFNumTypeList_H__)

