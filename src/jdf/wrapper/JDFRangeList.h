#if !defined(_JDFRangeList_H__)
#define _JDFRangeList_H__

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
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  26.May.2000
// 180700 RP MyString -> WString : all strings now 16 bit
// 120204 ES added IsPartOfRange() for ranges and lists of ranges
// 040304 ES added IsOrdered(),IsUniqueOrdered(),IsUnique(), IsList()
// 300304 ES added begin(), end(), erase()
//
// JDFRangeList.h: interface for the JDFRangeList class.
// list of range values
//
*/

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "jdf/util/myuti.h"
#include "JDFRange.h"
#include <vector>

namespace JDF{
	
/**
Template that implements lists of JDF ranges " x x~y" for various data types 
Ranges include the end-points
	*/
	
	template<class RangeType> 
		class JDFRangeList{
		/**
		* shorthand typedef for range class template instance
		*/
		typedef JDFRange<RangeType> Range;
		
public:
	
/** 
* constructor that tokenizes a string
	*/
	JDFRangeList(const WString& s=WString::emptyStr){
		SetString(s);
	}
	
	/**
	* copy ctor
	*/
	JDFRangeList(const JDFRangeList<RangeType>&rl){ //SF140102
		rangeList=rl.rangeList;
	}

/** 
* constructor that tokenizes a string
	*/
	JDFRangeList & operator=(const WString& s){
		SetString(s);
		return *this;
	}
	
	/**
	* copy ctor
	*/
	JDFRangeList& operator=(const JDFRangeList<RangeType>&rl){ //SF140102
		rangeList=rl.rangeList;
		return *this;
	}

	/**
	* dtor
	*/
	virtual ~JDFRangeList(){};
	
	/**
	* check whether element 'x' is in the range defined by 'this'
	* @param RangeType x: value to test
	* @return bool: true if 'x' is in the range defined by 'this'
	*/
	bool InRange(RangeType x)const{
		int sz=rangeList.size();
		for(int i=0;i<sz;i++){
			if(rangeList[i].InRange(x))
				return true;
		}
		return false;
	}
	
	/**
	* check whether range 'x' is in the range defined by 'this'
	* @param Range x: range to test
	* @return bool: true if 'x' is in the range defined by 'this'
	*/
	bool IsPartOfRange(Range x)const{
		int sz=rangeList.size();
		for(int i=0;i<sz;i++){
			if(rangeList[i].IsPartOfRange(x)) 
				return true;
		}
		return false;
	}

	/**
	* check whether range list 'x' is in the range list defined by 'this'
	* an empty rangelist is part of anything
	*
	* @param JDFRangeList x: range list to test
	* @return bool: true if range list 'x' is in the range list defined by 'this'
	*/
	bool IsPartOfRange(JDFRangeList x)const{
		int sz=x.size();
		for(int i=0;i<sz;i++){
			if(!IsPartOfRange(x[i])) 
				return false;
		}
		return true;
	}

	/**
	* serialize to string
	* @return WString a list of ranges in the format a b c~d a f~g ...
	*/
	WString GetString()const {
		WString s;
		int sz=rangeList.size();
		for(int i=0;i<sz;i++){
			s+=rangeList[i].GetString();
			if(i<(sz-1)) s+=WString::blank; // NB changed from " " to WString::blank
		}
		return s;
	}
	
	/**
	* deserialize a string
	* Reads the string, which represents ranges of any type,
	* and converts it into real ranges 
	* @param WString& str: string to read
	*/
	void SetString(const WString& str=WString::emptyStr){
		if (str.empty()) 
			return;
		WString zappedWS=str;
		zappedWS.ZappTokenWS("~"); // convert " 1 ~ 3.4 7 ~ 5" to " 1~3.4 7~5"
		vWString vs=zappedWS.Tokenize(" \t");
		rangeList.clear();
		int rangeLength=1;
		int siz=vs.size();
		while(rangeLength<=siz){
			bool ciao=false;
			for(int i=0;i<siz;i++){ 
				int tildeLength=rangeLength;
				WString s=vs[i];
				for(int j=1;j<tildeLength;j++){ 
					if(++i>=siz){
						rangeLength++;
						ciao=true;
						break;
					}							
					s+=WString::blank;
					s+=vs[i];
					if(j==rangeLength-1){
						if(s.find_first_of(WString::tilde)!=WString::npos)
							tildeLength=2*rangeLength-1;
						if (tildeLength>siz)
							throw JDFException("JDFRangeList::SetString: Illegal string " + str);
						
					}
				}
				if(!ciao){
					try{
						rangeList.push_back(Range(s)); // attempt to bild a corresponding Range from a string s
						if(i==siz-1) 
							return; // all is well

					}catch (JDFException){ // if the range is yet not complete - increase rangeLength and try again
						rangeList.clear(); 
						rangeLength++;
						if (rangeLength>siz)
							throw JDFException("JDFRangeList::SetString: Illegal string " + str);
						break;
					}
				}
			}
		}	
		// never got to all is well
		throw JDFException("JDFRangeList::SetString: Illegal string " + str);

	}
	
	/**
	* Add a range r =rMin~rMax
	* @param Range r the range to append to the list
	*/
	void Append(const Range r){
		rangeList.push_back(r);
	};
	
	/**
	* Add a Range defined by two RangeTypes xMin~xMax
	* @param RangeType xMin the left value of the range to append to the list
	* @param RangeType xMax the right value of the range to append to the list
	*/
	void Append(RangeType xMin, RangeType xMax){
		Append(Range(xMin,xMax));
	};
	
	/**
	* Add an individual RangeType element
	* @param RangeType x the left and right value of the range to append to the list
	*/
	void Append(RangeType x){
		Append(Range(x,x));
	};
	
	/**
	* number of range elements
	* @return int the number of Ranges in the list
	*/
	int size()const{
		return rangeList.size();
	};
	
	/**
	* cleanup and empty the internal storge
	*/
	void clear(){
		rangeList.clear();
	};
	
	/**
	* Removes the i-th element of the range list
	* 
	* @param Range* i: element (range) to remove
	* @return Range*: the first element remaining beyond removed element, or end() if no such element exists.
	*/
	void erase(int i) {
		rangeList.erase(rangeList.begin()+i);
	};

	/**
	* A random-access iterator that points at the first element 
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return Range*: random-access iterator
	*/
	Range* begin() {
		return &(*(rangeList.begin()));
	};

	/**
	* Returns a random-access iterator that points just beyond the end of the sequence
	*
	* @return Range*: random-access iterator
	*/
	Range* end() {
		return &(*(rangeList.end()));
	};

	/**
	* A constant random-access iterator that points at the first element
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return const Range*: constant random-access iterator
	*/
	const Range* begin() const{
		return &(*(rangeList.begin()));
	};

	/**
	* Returns a constant random-access iterator that points just beyond the end of the sequence
	*
	* @return const Range*: constant random-access iterator
	*/
	const Range* end() const{
		return &(*(rangeList.end()));
	};

	/**
	* get the nth range element
	* note that this is the n'th range NOT the n'th element
	* @param int i index of the range to retrieve
	* @return the Range at position i
	*/
	Range& operator[](int i){
		if((i<0)||(i>=rangeList.size())) 
			throw JDFException("JDFRangeList operator []: illegal index");
		return rangeList[i];
	}

	/**
	* get the nth range element
	* note that this is the n'th range NOT the n'th element
	* @param int i index of the range to retrieve
	* @return the Range at position i
	*/
	const Range& operator[](int i) const {
		if((i<0)||(i>=rangeList.size())) 
			throw JDFException("JDFRangeList operator []: illegal index");
		return rangeList[i];
	}

	/**
	* get the nth range element
	* note that this is the n'th range NOT the n'th element
	* @param int i index of the range to retrieve
	* @return the Range at position i
	*/
	Range& at(int i) {
		if((i<0)||(i>=rangeList.size())) 
			throw JDFException("JDFRangeList operator at(): illegal index" + i);
		return rangeList.at(i);
	}
	
	/**
	* get the nth range element
	* note that this is the n'th range NOT the n'th element
	* @param int i index of the range to retrieve
	* @return the Range at position i
	*/
	const Range& at(int i) const{
		if((i<0)||(i>=rangeList.size())) 
			throw JDFException("JDFRangeList operator at(): illegal index" + i);
		return rangeList.at(i);
	}

	
	/**
	* Tests if 'this' is OrderedRangeList
	* @return bool: true if 'this' is OrdneredRangeList
	*/
	bool IsOrdered() {
		
		int siz=rangeList.size();
		if (siz==0) {
			return false; // attempt to operate on a null element
		}
		
		vWString v; // vector of ranges
		for  (int i=0; i<siz; i++)
		{
			Range r=rangeList.at(i);
			v.push_back(r.GetLeft());
			if (r.GetLeft()!=r.GetRight()) 
			{
				v.push_back(r.GetRight());
			}
		}
		
		int n=v.size()-1;
		if (n==0) {
			return true; // single value
		}
		RangeType first = v.at(0);
		RangeType last = v.at(n);
	
		for (int j=0; j<n; j++)
		{
			RangeType value (v.at(j));
			RangeType nextvalue (v.at(j+1));
			
			if ( ( ((first==last)&&(value==nextvalue)) || ((first<last)&&(value<=nextvalue)) || ((first>last)&&(value>=nextvalue)) ) == false )
				return false;
		}
		return true; // if we are here - the range list is Ordered
	}
	

	/**
	* Tests if 'this' is UniqueOrdered RangeList
	* @return bool: true if 'this' is UniqueOrdered RangeList
	*/
	bool IsUniqueOrdered() {
		
		int siz=rangeList.size();
		if (siz==0) {
			return false; // attempt to operate on a null element
		}
		
		vWString v;
		for  (int i=0; i<siz; i++)
		{
			Range r=rangeList.at(i);
			v.push_back(r.GetLeft());
			if (r.GetLeft()!=r.GetRight()) 
			{
				v.push_back(r.GetRight());
			}
		}
		
		int n=v.size()-1;
		if (n==0) {
			return true; // single value
		}
		RangeType first = v.at(0);
		RangeType last = v.at(n);
	
		if (first==last) {
			return false;
		}
		for (int j=0; j<n; j++)
		{
			RangeType value (v.at(j));
			RangeType nextvalue (v.at(j+1));
			
			if ( ( ((first<last)&&(value<nextvalue)) || ((first>last)&&(value>nextvalue)) ) == false )
				return false;
		}
		return true; // if we are here - the range list is Ordered
	}

	/**
	* Tests if 'this' has only unique values
	* @return bool: true if 'this' is unique
	*/
	bool IsUnique() const {

		int sz=rangeList.size();
		for (int i=0; i<sz; i++)
		{
			Range range = rangeList.at(i);
			for (int j=0; j<sz; j++)
			{
				if (j!=i)
				{
					Range other = rangeList.at(j);
					// even if one of the range deliminators belongs to any other range - return false (range is not unique)
					if ( ( other.InRange(range.GetLeft()) ) ||( other.InRange(range.GetRight()) ) )
						return false;
				}
			}
		}
		return true;
	}

	/**
	* Tests if 'this' is a List 
	* @return bool: true if 'this' contains no ranges
	*/
	bool IsList() {
		
		int sz=rangeList.size();
		for (int i=0; i<sz; i++)
		{
			Range range = rangeList.at(i);

			if (range.GetLeft()!=range.GetRight())
				return false;
		}
		return true; // if we are here 'this' is a List
	}



protected:
/**
* internal range vector
	*/
	std::vector<Range> rangeList;
};
	
	
	/**
	* class JDFRectangleRangeList - list of rectangle ranges
	*/
	typedef JDFRangeList<JDFRectangle> JDFRectangleRangeList;

	/**
	* class JDFShapeRangeList - list of shape ranges
	*/
	typedef JDFRangeList<JDFShape> JDFShapeRangeList;

};
#endif // !defined(_JDFRangeList_H__)
