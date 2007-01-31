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
/**
//
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Authors: Dr. Rainer Prosi, Elena Skobchenko
// 
// Revision history:
// created  4.February.2004
//
// JDFDurationRangeList.h: interface for the JDFDurationRangeList class.
// list of Duration range values
//
*/

#include "JDFDurationRangeList.h"
#include <vector>


#define PBASE ((vDBase*)pBase)
#define PBASES(s) ((vDBase*)s.pBase)
#define BASES(s) (*((vDBase*)s.pBase))

namespace JDF{

	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	
	typedef std::vector<JDFDurationRange> vDBase;


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

	JDFDurationRangeList::JDFDurationRangeList() { 

		pBase=new vDBase();
	}
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	JDFDurationRangeList::JDFDurationRangeList(const WString& s){
		
		pBase = new vDBase();
		SetString(s);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList& JDFDurationRangeList::operator=(const WString& s){
		
		SetString(s);
		return *this;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	JDFDurationRangeList::JDFDurationRangeList(const JDFDurationRangeList & rl){ 
		pBase=new vDBase(BASES(rl));
	}
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	JDFDurationRangeList& JDFDurationRangeList::operator=(const JDFDurationRangeList & rl){ 
		
		if (this == &rl)
			return *this;
		if (rl.size())
			*PBASE=(BASES(rl));
		else
			PBASE->clear();
		return *this;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::~JDFDurationRangeList(){
		delete PBASE;
	};
	
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	bool JDFDurationRangeList::InRange(const JDFDuration& x)const{
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			if(PBASE->at(i).InRange(x))
				return true;
		}
		return false;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	bool JDFDurationRangeList::IsPartOfRange(const JDFDurationRange& x)const{
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			if(PBASE->at(i).IsPartOfRange(x))
				return true;
		}
		return false;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	bool JDFDurationRangeList::IsPartOfRange(const JDFDurationRangeList& x)const{
		int sz=x.size();
		for(int i=0;i<sz;i++){
			if(!IsPartOfRange(x[i])) 
				return false;
		}
		return true;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////

	WString JDFDurationRangeList::GetString() const{
		WString s;
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			s+=PBASE->at(i).GetString();
			if(i<(sz-1)) s+=" ";
		}
		return s;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	void JDFDurationRangeList::SetString(const WString& s){
		WString zappedWS=s;
		zappedWS.ZappTokenWS("~"); // convert " 1 ~ 3.4 7 ~ 5" to " 1~3.4 7~5"
		vWString vs=zappedWS.Tokenize(" \t");
		PBASE->clear();
		
		for(int i=0;i<vs.size();i++){
			try 
			{
				PBASE->push_back(JDFDurationRange(vs[i]));
			}
			catch (IllegalArgumentException e) {
				throw IllegalArgumentException("JDFDurationRangeList illegal string: "+s);
			}
		}
		
		
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	void JDFDurationRangeList::Append(const JDFDurationRange& r){
		PBASE->push_back(r);
	};
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	void JDFDurationRangeList::Append(const JDFDuration& xMin, const JDFDuration& xMax){
		Append(JDFDurationRange(xMin,xMax));
	};
///////////////////////////////////////////////////////////////////////////////////////////////////	

	void JDFDurationRangeList::Append(const JDFDuration& x){
		Append(JDFDurationRange(x,x));
	};
///////////////////////////////////////////////////////////////////////////////////////////////////	

	int JDFDurationRangeList::size() const{
		return PBASE->size();
	};
///////////////////////////////////////////////////////////////////////////////////////////////////	

	void JDFDurationRangeList::clear(){
		PBASE->clear();
	};
///////////////////////////////////////////////////////////////////////////////////////////////////	
	
	void JDFDurationRangeList::erase(int i)  {
		PBASE->erase(PBASE->begin()+i);
	};
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::iterator JDFDurationRangeList::begin() {
		return &(*(PBASE->begin()));
	};
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::iterator JDFDurationRangeList::end() {
		return &(*(PBASE->end()));
	};
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::const_iterator JDFDurationRangeList::begin() const{
		return &(*(PBASE->begin()));
	};
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::const_iterator JDFDurationRangeList::end() const{
		return &(*(PBASE->end()));
	};
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::reference JDFDurationRangeList::operator[](int i){
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFDurationRangeList operator []: illegal index");
		return PBASE->at(i);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::const_reference JDFDurationRangeList::operator[](int i) const{
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFDurationRangeList operator []: illegal index");
		return PBASE->at(i);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::reference JDFDurationRangeList::at(int i) {
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFDurationRangeList at(i): illegal index");
		return PBASE->at(i);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	JDFDurationRangeList::const_reference JDFDurationRangeList::at(int i) const{
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFDurationRangeList at(i): illegal index");
		return PBASE->at(i);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	bool JDFDurationRangeList::IsOrdered() {
		
		int siz=PBASE->size();
		if (siz==0) {
			return false; // attempt to operate on a null element
		}
	
		vWString v;
		for  (int i=0; i<siz; i++)
		{
			JDFDurationRange r=PBASE->at(i);
			v.push_back(r.GetLeft().DurationISO());
			if (r.GetLeft()!=r.GetRight()) 
			{
				v.push_back(r.GetRight().DurationISO());
			}
		}
		
		int n=v.size()-1;
		if (n==0) {
			return true; // single value
		}
		JDFDuration first = v.at(0);
		JDFDuration last = v.at(n);
	
		for (int j=0; j<n; j++)
		{
			JDFDuration value (v.at(j));
			JDFDuration nextvalue (v.at(j+1));
			
			if ( ( ((first==last)&&(value==nextvalue))||((first<last)&&(value<=nextvalue))||((first>last)&&(value>=nextvalue)) ) == false )
				return false;
		}
		return true; // if we are here - the range list is Ordered
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	bool JDFDurationRangeList::IsUniqueOrdered() {
		
		int siz=PBASE->size();
		if (siz==0) {
			return false; // attempt to operate on a null element
		}
		
		vWString v;
		for  (int i=0; i<siz; i++)
		{
			JDFDurationRange r=PBASE->at(i);
			v.push_back(r.GetLeft().DurationISO());
			if (r.GetLeft()!=r.GetRight()) 
			{
				v.push_back(r.GetRight().DurationISO());
			}
		}
		
		int n=v.size()-1;
		if (n==0) {
			return true; // single value
		}
		JDFDuration first = v.at(0);
		JDFDuration last = v.at(n);
	
		if (first==last) {
			return false;
		}
		for (int j=0; j<n; j++)
		{
			JDFDuration value (v.at(j));
			JDFDuration nextvalue (v.at(j+1));
			
			if ( ( ((first<last)&&(value<nextvalue)) || ((first>last)&&(value>nextvalue)) ) == false )
				return false;
		}
		return true; // if we are here - the range list is Ordered
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	bool JDFDurationRangeList::IsList() {
		
		int sz=PBASE->size();

		for (int i=0; i<sz; i++)
		{
			JDFDurationRange range = PBASE->at(i);

			if (range.GetLeft()!=range.GetRight())
				return false;
		}
		return true; // if we are here 'this' is a List
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
	
	bool JDFDurationRangeList::IsUnique() const {

		int sz=PBASE->size();
		for (int i=0; i<sz; i++)
		{
			JDFDurationRange range = PBASE->at(i);
			for (int j=0; j<sz; j++)
			{
				if (j!=i)
				{
					JDFDurationRange other = PBASE->at(j);
					
					if ( ( other.InRange(range.GetLeft()) ) ||( other.InRange(range.GetRight()) ) )
						return false;
				}
			}
		}
		return true;
	}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

};// namespace JDF

