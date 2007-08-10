/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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
/******************************************************************************
*                     Copyright 1998 Agfa-Gevaert N.V.                       *
*                           All rights reserved                              *
*                                                                            *
* The material contained herein may not be reproduced in whole or in part,   *
*        without the prior written consent of Agfa-Gevaert N.V.              *
*                                                                            *
******************************************************************************/


/******************************************************************************
*	Includes
******************************************************************************/ 


#include "vMapWString.h"
#include <jdf/lang/WString.h>

#include <vector>


#define PBASE ((vMapWStringBase*)pBase)
#define PBASES(s) ((vMapWStringBase*)s.pBase)
#define BASES(s) (*((vMapWStringBase*)s.pBase))
#define IteratorIPos(iter) (PBASE->begin()+iter.iPos)
#define IteratorIPosS(iter) (((vMapWStringBase*)iter.vMapWStringVector)->begin()+iter.iPos)

namespace JDF
{
	
/******************************************************************************
*	Forward declarations
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	typedef std::vector<MapWString> vMapWStringBase;
	
	const vMapWString vMapWString::emptyvMap;
	
	/******************************************************************************
	*	Classes
	******************************************************************************/ 
	
	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 
	
	
	/******************************************************************************
	*	Implementation
	******************************************************************************/ 
	
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	vMapWString::vMapWString(){
		pBase=new vMapWStringBase();
	}
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::vMapWString(const vMapWString&m){
		pBase=new vMapWStringBase(BASES(m));
	};
	
	////////////////////////////////////////////////////////////////////////
	vMapWString &vMapWString::operator =(const vMapWString& other){
		*PBASE=BASES(other);
		return *this;
	};
	////////////////////////////////////////////////////////////////////////
	vMapWString::~vMapWString(){
		delete PBASE;
	};

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	vMapWString::const_reference vMapWString::at(size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vMapWString::const_reference vMapWString::elementAt(size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::reference vMapWString::at(size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vMapWString::reference vMapWString::elementAt(size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::iterator vMapWString::erase(iterator first, iterator last){
		PBASE->erase(IteratorIPos(first),IteratorIPos(last));
		return vMapWStringIterator(pBase,first.iPos);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::iterator vMapWString::erase(iterator it){
		PBASE->erase(IteratorIPos(it));
		return vMapWStringIterator(pBase,it.iPos);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::iterator vMapWString::begin(){
		return vMapWStringIterator(pBase,0);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::const_iterator vMapWString::begin()const{
		return vMapWStringIterator(pBase,0);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::iterator vMapWString::end(){
		return vMapWStringIterator(pBase,PBASE->size());
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::const_iterator vMapWString::end()const{
		return vMapWStringIterator(pBase,PBASE->size());
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::size_type vMapWString::size() const{
		return PBASE->size();
	};
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::push_back(const MapWString& str){
		PBASE->push_back(str);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::const_reference vMapWString::operator[](size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::reference vMapWString::operator[](size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::assign(const_iterator first, const_iterator last){
		PBASE->assign(IteratorIPosS(first), IteratorIPosS(last));
	};
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::assign(size_type n, const MapWString& x){
		PBASE->assign(n,x);
	};
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::iterator vMapWString::insert(iterator it, const MapWString& x ){
		PBASE->insert(IteratorIPos(it), x);
		return vMapWStringIterator(pBase,it.iPos);
	};
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::insert(iterator it, size_type n, const MapWString& x){
		PBASE->insert(IteratorIPos(it), n, x);
	};
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::insert(iterator it, const_iterator first, const_iterator last){
		PBASE->insert(IteratorIPos(it), IteratorIPosS(first), IteratorIPosS(last));
	};
	////////////////////////////////////////////////////////////////////////
	
	bool vMapWString::empty()const{
		return PBASE->empty();
	};
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::clear()const{
		PBASE->clear();
	};
	////////////////////////////////////////////////////////////////////////
	
	
	bool vMapWString::IsEqual(const vMapWString& other)const{
		if (size()!=other.size()) 
			return false;
		vMapWString left=other;
		for(unsigned int i=0;i<size();i++){
			int ix=left.index(at(i));
			if(ix<0) 
				return false;
			left.erase(vMapWStringIterator(pBase,ix));
		}
		return true;
		
	}
	
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::SubMap(const MapWString &other){
		for(int i=size()-1; i>=0; i--){
			if(!at(i).SubMap(other)) 
				PBASE->erase(PBASE->begin()+i);
		}
	}
	
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::OverlapMap(const MapWString &other){
		for(int i=size()-1; i>=0; i--){
			if(!at(i).OverlapMap(other)) 
				PBASE->erase(PBASE->begin()+i);
		}
	}
	////////////////////////////////////////////////////////////////////////
	
	void vMapWString::ReduceKey(const vWString &vKey){
		vMapWString v;
		for(unsigned int i=0; i<size(); i++)
		{
			MapWString m=at(i);
			bool bEmpty=m.empty();
			m.ReduceKey(vKey);
			if(bEmpty || !m.empty())
				v.AppendUnique(m);
		}
		assign(v.begin(),v.end());
	}
	////////////////////////////////////////////////////////////////////////
	
	int vMapWString::index(const MapWString& other)const{ 
		for (unsigned int i=0;i<size();i++){
			if (at(i)==other) 
				return i;
		}
		return -1;
	};
	
	////////////////////////////////////////////////////////////////////////
	int vMapWString::IndexSubMap(const MapWString& other)const{ 
		for (unsigned int i=0;i<size();i++){
			if (at(i).SubMap(other)) 
				return i;
		}
		return -1;
	};
	
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::iterator vMapWString::find( const MapWString & s){
		for (unsigned int i=0; i<size(); i++) {
			if (s==at(i)) 
				return vMapWStringIterator(pBase,i);
		}
		return end();
	}
	
	////////////////////////////////////////////////////////////////////////
	
	vMapWString::const_iterator vMapWString::find( const MapWString & s)const{
		for (unsigned int i=0; i<size(); i++) {
			if (s==at(i)) 
				return vMapWStringIterator(pBase,i);
		}
		return end();
	}
	
	////////////////////////////////////////////////////////////////////////
	void vMapWString::AppendUnique(const vMapWString& v){
		for(unsigned int i=0; i<v.size(); i++) 
			AppendUnique(v.at(i)); 
	}
	
	////////////////////////////////////////////////////////////////////////
	
	bool vMapWString::hasMap(const MapWString &s)const{
		return index(s)>=0;
	}
	////////////////////////////////////////////////////////////////////////
	void vMapWString::AppendUnique(const MapWString& m){ 
		if(!hasMap(m)) 
			push_back(m);
	}
	
	////////////////////////////////////////////////////////////////////////
	bool vMapWString::operator==(const vMapWString&other)const{
		return IsEqual(other);
	}
	////////////////////////////////////////////////////////////////////////

	bool vMapWString::operator!=(const vMapWString&other)const{
		return !IsEqual(other);
	}
	
	////////////////////////////////////////////////////////////////////////

	JDFTOOLS_EXPORT std::ostream& operator<<(std::ostream&s,const vMapWString&t){

		for(unsigned int i=0; i<t.size(); i++){ 
			s<<t.at(i)<<std::endl;
		}
		return s; 
	}

	////////////////////////////////////////////////////////////////////////

	WString vMapWString::toString()
	{
		WString ret;

		for (int i=0;i<(this->size());i++)
		{
			ret += "[";
			ret.append(this->at(i).toString());
			ret += "] ";
		}

		return ret;
	}

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	vMapWStringIterator::vMapWStringIterator(){
		vMapWStringVector=0;
		iPos=0;
	}
	
	////////////////////////////////////////////////////////////////////////
	vMapWStringIterator::vMapWStringIterator(const vMapWStringIterator&other){
		iPos=other.iPos;
		vMapWStringVector=other.vMapWStringVector;
	}

	////////////////////////////////////////////////////////////////////////
	vMapWStringIterator& vMapWStringIterator::operator =(const vMapWStringIterator&other){
		iPos=other.iPos;
		vMapWStringVector=other.vMapWStringVector;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	vMapWStringIterator::vMapWStringIterator(void*p, int ipos){
		if(p){
			vMapWStringBase* v=(vMapWStringBase*)p;
			if(ipos<0)
				ipos=v->size(); // return end
			iPos=ipos;
			vMapWStringVector=p;

		}else{
			vMapWStringVector=0;
			iPos=0;
		}
	};
	////////////////////////////////////////////////////////////////////////

	vMapWStringIterator::~vMapWStringIterator(){
	};

	////////////////////////////////////////////////////////////////////////
	vMapWStringIterator vMapWStringIterator::operator +(int i)const{
		if(vMapWStringVector==0) 
			throw (L"JDFException null vMapWStringIterator");
		vMapWStringIterator it=*this;
		it.iPos+=i;
		return it;
	}
	////////////////////////////////////////////////////////////////////////
	vMapWStringIterator vMapWStringIterator::operator ++(){
		if(vMapWStringVector==0) 
			throw (L"JDFException null vMapWStringIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
	vMapWStringIterator vMapWStringIterator::operator ++(int){
		if(vMapWStringVector==0) 
			throw (L"JDFException null vMapWStringIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
		
	const vMapWStringIterator* vMapWStringIterator::operator->() const{
		return (&*this); 
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vMapWStringIterator::operator!=(const vMapWStringIterator & other) const{
		return (vMapWStringVector!=other.vMapWStringVector)||(iPos!=other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vMapWStringIterator::operator==(const vMapWStringIterator & other) const{
		return (vMapWStringVector==other.vMapWStringVector)&&(iPos==other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vMapWStringIterator::operator>(const vMapWStringIterator & other) const{
		bool result = (vMapWStringVector==other.vMapWStringVector);
		if (result)
			result = (iPos > other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vMapWStringIterator::operator<(const vMapWStringIterator & other) const{
		bool result = (vMapWStringVector==other.vMapWStringVector);
		if (result)
			result = (iPos<other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vMapWStringIterator::operator>=(const vMapWStringIterator & other) const{
		bool result = (vMapWStringVector==other.vMapWStringVector);
		if (result)
			result = (iPos >= other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vMapWStringIterator::operator<=(const vMapWStringIterator & other) const{
		bool result = (vMapWStringVector==other.vMapWStringVector);
		if (result)
			result = (iPos<=other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
			 
} // namespace JDF

