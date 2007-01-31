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
//////////////////////////////////////////////////////////////////////
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created  6.June.2000
//
// JDFXYPairRangeList.cpp: implementation of the JDFXYPairRangeList class.
//
//////////////////////////////////////////////////////////////////////


#include "JDFXYPairRangeList.h"
#include "JDFRangeList.h"
#include "JDFRange.h"
#include "JDFNumTypeList.h"


#define PBASE ((_XYPairRangeList*)pBase)
#define PBASES(s) ((_XYPairRangeList*)s.pBase)
#define BASES(s) (*((_XYPairRangeList*)s.pBase))

namespace JDF{
	
	typedef JDFRangeList<JDFXYPair> _XYPairRangeList;
	/**
	* simple template instantiation for XYPairs
	*/
	
	//////////////////////////////////////////////////////////////////////
	JDFXYPairRangeList::JDFXYPairRangeList(const JDFXYPairRangeList&rl){
		pBase=new _XYPairRangeList(BASES(rl));
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFXYPairRangeList & JDFXYPairRangeList::operator=(const WString& s){
		*PBASE=s;
		return *this;
	}
	//////////////////////////////////////////////////////////////////////
	/**
	* copy ctor
	*/
	JDFXYPairRangeList& JDFXYPairRangeList::operator=(const JDFXYPairRangeList&rl){ 
		*PBASE=BASES(rl);
		return *this;
	}
	//////////////////////////////////////////////////////////////////////
	/// create from string ctor
	JDFXYPairRangeList::JDFXYPairRangeList(const WString& s){
		pBase=new _XYPairRangeList(s);
	};
	
	//////////////////////////////////////////////////////////////////////
	JDFXYPairRangeList::~JDFXYPairRangeList(){
		delete PBASE;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFXYPairRangeList::InRange(const JDFXYPair & xy){
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			JDFXYPairRange r=PBASE->at(i);
			if(r.InRange(xy)) 
				return true;
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFXYPairRangeList::IsPartOfRange(const JDFXYPairRange & xy){
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			JDFXYPairRange r=PBASE->at(i);
			if(r.IsPartOfRange(xy)) 
				return true;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairRangeList::IsPartOfRange(const JDFXYPairRangeList& x){
		int sz=x.size();
		for(int i=0;i<sz;i++){
			JDFXYPairRange range=x.at(i);
			if(!IsPartOfRange(range)) 
				return false;
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	void JDFXYPairRangeList::Append(const JDFXYPair & x){
		PBASE->Append(x);		
	};
	//////////////////////////////////////////////////////////////////////
	void JDFXYPairRangeList::Append(const JDFXYPairRange& r){
		PBASE->Append(r);
	};
	
	/**
	* Add a Range defined by two ints xMin~xMax
	* @param int xMin the left value of the range to append to the list
	* @param int xMax the right value of the range to append to the list
	*/
	void JDFXYPairRangeList::Append(const JDFXYPair& xMin, const JDFXYPair& xMax){
		PBASE->Append(xMin,xMax);
	};
	
	//////////////////////////////////////////////////////////////////////
	
	const JDFXYPairRange& JDFXYPairRangeList::at(int i) const{
		return PBASE->at(i);
	}
	
	/**
	* number of range elements
	* @return int the number of Ranges in the list
	*/
	int JDFXYPairRangeList::size()const{
		return PBASE->size();
	};
	
	/**
	* cleanup and empty the internal storge
	*/
	void JDFXYPairRangeList::clear(){
		PBASE->clear();
	};
	
	/**
	* Removes the i-th element of the range list
	* 
	* @param JDFXYPairRange* i: element (range) to remove
	*/
	void JDFXYPairRangeList::erase(int i) {
		PBASE->erase(i);
	};

	/**
	* A random-access iterator that points at the first element 
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return JDFXYPairRange*: random-access iterator
	*/
	JDFXYPairRange* JDFXYPairRangeList::begin() {
		return PBASE->begin();
	};

	/**
	* Returns a random-access iterator that points just beyond the end of the sequence
	*
	* @return JDFXYPairRange*: random-access iterator
	*/
	JDFXYPairRange* JDFXYPairRangeList::end() {
		return PBASE->end();
	};

	/**
	* A constant random-access iterator that points at the first element
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return const JDFXYPairRange*: constant random-access iterator
	*/
	const JDFXYPairRange* JDFXYPairRangeList::begin() const{
		return PBASE->begin();
	};

	/**
	* Returns a constant random-access iterator that points just beyond the end of the sequence
	*
	* @return const JDFXYPairRange*: constant random-access iterator
	*/
	const JDFXYPairRange* JDFXYPairRangeList::end() const{
		return PBASE->end();
	};

	//////////////////////////////////////////////////////////////////////
	
	WString JDFXYPairRangeList::GetString()const{
		return PBASE->GetString();
	};
	
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	bool JDFXYPairRangeList::IsOrdered() {
		
		int siz=PBASE->size();
		if (siz==0) {
			return false; // attempt to operate on a null element
		}
		
		vWString v;
		for  (int i=0; i<siz; i++)
		{
			JDFXYPairRange r=PBASE->at(i);
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
		JDFXYPair first = v.at(0);
		JDFXYPair last = v.at(n);
	
		for (int j=0; j<n; j++)
		{
			JDFXYPair value (v.at(j));
			JDFXYPair nextvalue (v.at(j+1));
			
			if ( ( ((first==last)&&(value==nextvalue))||((first<last)&&(value<=nextvalue))||((first>last)&&(value>=nextvalue)) ) == false )
				return false;
		}
		return true; // if we are here - the range list is Ordered
	}

	//////////////////////////////////////////////////////////////////////
	/**
	* Tests if 'this' is UniqueOrderedRangeList
	* return bool: true if 'this' is UniqueOrderedRangeList
	*/
	bool JDFXYPairRangeList::IsUniqueOrdered() {
		
		int siz=PBASE->size();
		if (siz==0) {
			return false; // attempt to operate on a null element
		}
	
		vWString v;
		for  (int i=0; i<siz; i++)
		{
			JDFXYPairRange r=PBASE->at(i);
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
		JDFXYPair first = v.at(0);
		JDFXYPair last = v.at(n);
	
		if (first==last) {
			return false;
		}
		for (int j=0; j<n; j++)
		{
			JDFXYPair value (v.at(j));
			JDFXYPair nextvalue (v.at(j+1));
			
			if ( ( ((first<last)&&(value<nextvalue))||((first>last)&&(value>nextvalue)) ) == false )
				return false;
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	bool JDFXYPairRangeList::IsList() {
		
		int sz=PBASE->size();

		for (int i=0; i<sz; i++)
		{
			JDFXYPairRange range = PBASE->at(i);

			if (range.GetLeft()!=range.GetRight())
				return false;
		}
		return true; // if we are here 'this' is a List
	}
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	
	/**
	* Tests if 'this' has only unique values
	* return bool: true if 'this' is unique
	*/
	bool JDFXYPairRangeList::IsUnique() const{

		int sz=PBASE->size();
		for (int i=0; i<sz; i++)
		{
			JDFXYPairRange range = PBASE->at(i);
			for (int j=0; j<sz; j++)
			{
				if (j!=i)
				{
					JDFXYPairRange other = PBASE->at(j);
					
					if ( ( other.InRange(range.GetLeft()) ) ||( other.InRange(range.GetRight()) ) )
						return false;
				}
			}
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////


}