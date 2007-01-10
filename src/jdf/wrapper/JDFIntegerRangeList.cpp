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
// JDFIntegerRangeList.cpp: implementation of the JDFIntegerRangeList class.
//
//////////////////////////////////////////////////////////////////////

#include "JDFRangeList.h"

#include "JDFIntegerRangeList.h"
#include "JDFIntegerRange.h"


#define PBASE ((_IntegerRangeList*)pBase)
#define PBASES(s) ((_IntegerRangeList*)s.pBase)
#define BASES(s) (*((_IntegerRangeList*)s.pBase))

namespace JDF{
	
	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	
	typedef JDFRangeList<int> _IntegerRangeList;

	/**
	* simple template instantiation for names (NMTOKENS)
	*/
	
	//////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList::JDFIntegerRangeList(const JDFIntegerRangeList&rl){
		pBase=new _IntegerRangeList(BASES(rl));
		xDef=rl.xDef;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFIntegerRangeList & JDFIntegerRangeList::operator=(const WString& s){
		*PBASE=s;
		return *this;
	}
	//////////////////////////////////////////////////////////////////////	
	JDFIntegerRangeList& JDFIntegerRangeList::operator =(const JDFIntegerRangeList&rl){
		*PBASE=BASES(rl);
		xDef=rl.xDef;
		return *this;
	};
	
	//////////////////////////////////////////////////////////////////////
	/// create fron string ctor
	JDFIntegerRangeList::JDFIntegerRangeList(const WString& s, int xdef){
		pBase=new _IntegerRangeList(s);
		xDef=xdef;
	};
	
	//////////////////////////////////////////////////////////////////////
	
	bool JDFIntegerRangeList::InRange(int x)const
	{
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			JDFIntegerRange r=PBASE->at(i);
			r.SetDef(xDef);
			if(r.InRange(x)) 
				return true;
		}
		return false;
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFIntegerRangeList::IsPartOfRange(const JDFIntegerRange& x){
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			JDFIntegerRange r=PBASE->at(i);
			r.SetDef(xDef);
			if(r.IsPartOfRange(x)) 
				return true;
		}
		return false;
	}
	
	//////////////////////////////////////////////////////////////////////
	bool JDFIntegerRangeList::IsPartOfRange(const JDFIntegerRangeList& x){
		int sz=x.size();
		for(int i=0;i<sz;i++){
			JDFIntegerRange range=x.at(i);
			range.SetDef(x.GetDef());
			if(!IsPartOfRange(range)) 
				return false;
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	JDFIntegerRangeList::~JDFIntegerRangeList(){
		delete PBASE;
	}
	//////////////////////////////////////////////////////////////////////
	
	int JDFIntegerRangeList::NElements() const{
		int sz=PBASE->size();
		int n=0;
		for(int i=0;i<sz;i++){
			JDFIntegerRange r=PBASE->at(i);
			r.SetDef(xDef);
			n+=r.NElements();
		}
		return n;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	int JDFIntegerRangeList::Element(int i) const{
		if(i<0){
			int n=NElements();
			/// attempt to find position<0
			if(-i>n) 
				throw(JDFException("JDFIntegerRangeList::Element out of range error"));
			return Element(n+i);
		}
		int sz=PBASE->size();
		int n=0;
		for(int j=0;j<sz;j++){
			JDFIntegerRange r=PBASE->at(j);
			r.SetDef(xDef);
			int k=r.NElements();
			if(i>=k){
				// go to next range
				i-=k;
			}else{
				return r.Element(i);
			}
		}
		throw(JDFException("JDFIntegerRangeList::Element out of range error"));
		return 0; // make the compiler happy
	}
	
	//////////////////////////////////////////////////////////////////////
	void JDFIntegerRangeList::Append(int x){
		int rs=PBASE->size();
		if (rs<=0) {
			PBASE->Append(x);
			return;
		}
		JDFIntegerRange r=PBASE->at(rs-1);
		// added to this Range
		if(r.Append(x)){
			PBASE->at(rs-1)=r;
			return;
		}
		// back to defauult
		PBASE->Append(x);
		
	};
	//////////////////////////////////////////////////////////////////////
	void JDFIntegerRangeList::SetDef(const int xdef){
		xDef=xdef;
		
		int sz=PBASE->size();
		for(int i=0;i<sz;i++)
		{
			JDFIntegerRange r=PBASE->at(i);
			r.SetDef(xdef);
		}
	};

	//////////////////////////////////////////////////////////////////////
	int JDFIntegerRangeList::GetDef() const {
		return xDef;
	};
	//////////////////////////////////////////////////////////////////////
	void JDFIntegerRangeList::Append(const IntegerRange& r){
		PBASE->Append(r);
	};

	//////////////////////////////////////////////////////////////////////
	/**
	* Add a Range defined by two ints xMin~xMax
	* @param int xMin the left value of the range to append to the list
	* @param int xMax the right value of the range to append to the list
	*/
	void JDFIntegerRangeList::Append(int xMin, int xMax){
		PBASE->Append(xMin,xMax);
	};
	
	//////////////////////////////////////////////////////////////////////
	
	JDFIntegerRangeList::const_reference JDFIntegerRangeList::at(int i) const{
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFIntegerRangeList operator at(): illegal index");
		// this works because _IntegerRange has the same size and member variable structure as JDFIntegerRange
		JDFIntegerRange& ir= (JDFIntegerRange&) PBASE->at(i);
		ir.SetDef(GetDef());
		return ir;
	}
	//////////////////////////////////////////////////////////////////////
	
	JDFIntegerRangeList::reference JDFIntegerRangeList::at(int i) {
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFIntegerRangeList operator at(): illegal index");
		// this works because _IntegerRange has the same size and member variable structure as JDFIntegerRange
		JDFIntegerRange& ir= (JDFIntegerRange&) PBASE->at(i);
		ir.SetDef(GetDef());
		return ir;
	}
	//////////////////////////////////////////////////////////////////////

	JDFIntegerRangeList::const_reference JDFIntegerRangeList::operator[](int i) const{
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFIntegerRangeList operator []: illegal index");
		// this works because _IntegerRange has the same size and member variable structure as JDFIntegerRange
		JDFIntegerRange& ir= (JDFIntegerRange&) PBASE->at(i);
		ir.SetDef(GetDef());
		return ir;
	}
	//////////////////////////////////////////////////////////////////////
	
	JDFIntegerRangeList::reference JDFIntegerRangeList::operator[](int i) {
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFIntegerRangeList operator []: illegal index");
		// this works because _IntegerRange has the same size and member variable structure as JDFIntegerRange
		JDFIntegerRange& ir= (JDFIntegerRange&) PBASE->at(i);
		ir.SetDef(GetDef());
		return ir;
	}
	//////////////////////////////////////////////////////////////////////
	
	/**
	* number of range elements
	* @return int the number of Ranges in the list
	*/
	int JDFIntegerRangeList::size()const{
		return PBASE->size();
	};
	
	//////////////////////////////////////////////////////////////////////
	
	/**
	* cleanup and empty the internal storage
	*/
	void JDFIntegerRangeList::clear(){
		PBASE->clear();
	};
	
	/**
	* Removes the i-th element of the range list
	* 
	* @param IntegerRange* i: element (range) to remove
	*/
	void JDFIntegerRangeList::erase(int i) {
		PBASE->erase(i);
	};

	/**
	* A random-access iterator that points at the first element 
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return IntegerRange*: random-access iterator
	*/
	JDFIntegerRangeList::iterator JDFIntegerRangeList::begin() {
		// this works because _IntegerRange has the same size and member variable structure as JDFIntegerRange
		JDFIntegerRange& ir= (JDFIntegerRange&) *(PBASE->begin());
		ir.SetDef(GetDef());
		return &ir;
	};

	/**
	* Returns a random-access iterator that points just beyond the end of the sequence
	*
	* @return IntegerRange*: random-access iterator
	*/
	JDFIntegerRangeList::iterator JDFIntegerRangeList::end() {
		// this works because _IntegerRange has the same size and member variable structure as JDFIntegerRange
		JDFIntegerRange& ir= (JDFIntegerRange&) *(PBASE->end());
		ir.SetDef(GetDef());
		return &ir;

	};

	/**
	* A constant random-access iterator that points at the first element
	* of the sequence (or just beyond the end of an empty sequence)
	*
	* @return const IntegerRange*: constant random-access iterator
	*/
	JDFIntegerRangeList::const_iterator JDFIntegerRangeList::begin() const{
		// this works because _IntegerRange has the same size and member variable structure as JDFIntegerRange
		JDFIntegerRange& ir= (JDFIntegerRange&) *(PBASE->begin());
		ir.SetDef(GetDef());
		return &ir;
	};

	/**
	* Returns a constant random-access iterator that points just beyond the end of the sequence
	*
	* @return const IntegerRange*: constant random-access iterator
	*/
	JDFIntegerRangeList::const_iterator JDFIntegerRangeList::end() const{
		// this works because _IntegerRange has the same size and member variable structure as JDFIntegerRange
		JDFIntegerRange& ir= (JDFIntegerRange&) *(PBASE->end());
		ir.SetDef(GetDef());
		return  &ir;
	};

	//////////////////////////////////////////////////////////////////////
	
	WString JDFIntegerRangeList::GetString()const{
		WString s;
		int sz=this->size();
		for(int i=0;i<sz;i++){
			s+=this->operator [](i).GetString();
			if(i<(sz-1)) s+=WString::blank;
		}
		return s;
	};
	
	//////////////////////////////////////////////////////////////////////

	vint JDFIntegerRangeList::ToVInt(int maxelem) const{
		vint vi;
		int n = (NElements()<maxelem)  ? NElements() : maxelem; // maxelem limits NElements in case of INF 
		for (int i=0; i<n; i++) 
		{
			vi.push_back(Element(i));
		}
		return vi;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFIntegerRangeList::IsOrdered() {
		
		int siz=PBASE->size();
		if (siz==0) {
			return false; // attempt to operate on a null element
		}
	
		vWString v;
		for  (int i=0; i<siz; i++)
		{
			JDFIntegerRange r=PBASE->at(i);
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
		int first = v.at(0);
		int last = v.at(n);
	
		for (int j=0; j<n; j++)
		{
			int value (v.at(j));
			int nextvalue (v.at(j+1));
			
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
	bool JDFIntegerRangeList::IsUniqueOrdered() {
		
		int siz=PBASE->size();
		if (siz==0) {
			return false; // attempt to operate on a null element
		}
		
		vWString v;
		for  (int i=0; i<siz; i++)
		{
			JDFIntegerRange r=PBASE->at(i);
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
		int first = v.at(0);
		int last = v.at(n);
	
		if (first==last) {
			return false;
		}
		for (int j=0; j<n; j++)
		{
			int value (v.at(j));
			int nextvalue (v.at(j+1));
			
			if ( ( ((first<last)&&(value<nextvalue))||((first>last)&&(value>nextvalue)) ) == false )
				return false;
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////
	
	bool JDFIntegerRangeList::IsList() {
		
		int sz=PBASE->size();

		for (int i=0; i<sz; i++)
		{
			JDFIntegerRange range = PBASE->at(i);

			if (range.GetLeft()!=range.GetRight())
				return false;
		}
		return true; // if we are here 'this' is a List
	}
	//////////////////////////////////////////////////////////////////////
	
	/**
	* Tests if 'this' has only unique values
	* return bool: true if 'this' is unique
	*/
	bool JDFIntegerRangeList::IsUnique() const{

		int sz=PBASE->size();
		for (int i=0; i<sz; i++)
		{
			JDFIntegerRange range = PBASE->at(i);
			for (int j=0; j<sz; j++)
			{
				if (j!=i)
				{
					JDFIntegerRange other = PBASE->at(j);
					
					if ( ( other.InRange(range.GetLeft()) ) ||( other.InRange(range.GetRight()) ) )
						return false;
				}
			}
		}
		return true;
	}
	//////////////////////////////////////////////////////////////////////
}