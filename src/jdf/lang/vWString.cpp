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



#include "vWString.h"

#include "vint.h"
#include "JDF/lang/SetWString.h"

#include <vector>
#include <algorithm> // for sort

#define PBASE ((vWStringBase*)pBase)
#define PBASES(s) ((vWStringBase*)s.pBase)
#define BASES(s) (*((vWStringBase*)s.pBase))
#define IteratorIPos(iter) (PBASE->begin()+iter.iPos)
#define IteratorIPosS(iter) (((vWStringBase*)iter.vWStringVector)->begin()+iter.iPos)


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
	//typedef std::vector<int> vint;
	typedef std::vector<WString> vWStringBase;

	const vWString vWString::emptyvStr;

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
	vWString::vWString(){
		pBase=new vWStringBase();
		reserve(10);
	}
	////////////////////////////////////////////////////////////////////////

	vWString::vWString(const vWString&m){
		pBase=new vWStringBase(BASES(m));
	};
	////////////////////////////////////////////////////////////////////////
	vWString::vWString(const WString&s, const WString & separator){
		pBase=new vWStringBase();
		reserve(10);
		*this=s.Tokenize(separator);
	};
	////////////////////////////////////////////////////////////////////////
	vWString &vWString::operator =(const vWString& other){
		*PBASE=BASES(other);
		return *this;
	};
	////////////////////////////////////////////////////////////////////////
	vWString::~vWString(){
		delete PBASE;
	};

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	vWString::const_reference vWString::at(size_type pos) const{
		return PBASE->at(pos);
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::reference vWString::at(size_type pos){
		return PBASE->at(pos);
	}
	////////////////////////////////////////////////////////////////////////
	vWString::const_reference vWString::elementAt(size_type pos) const{
		return PBASE->at(pos);
	}
	////////////////////////////////////////////////////////////////////////
	vWString::const_reference vWString::stringAt(size_type pos) const{
		return PBASE->at(pos);
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::reference vWString::elementAt(size_type pos){
		return PBASE->at(pos);
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::reference vWString::stringAt(size_type pos){
		return PBASE->at(pos);
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::iterator vWString::erase(iterator first, iterator last){
		PBASE->erase(IteratorIPos(first),IteratorIPos(last));
		return vWStringIterator(pBase,first.iPos);
	};
	////////////////////////////////////////////////////////////////////////
	
	vWString::iterator vWString::erase(iterator it){
		PBASE->erase(IteratorIPos(it));
		return vWStringIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::iterator vWString::begin(){
		return vWStringIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::const_iterator vWString::begin()const{
		return vWStringIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::iterator vWString::end(){
		return vWStringIterator(pBase,PBASE->size());
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::const_iterator vWString::end()const{
		return vWStringIterator(pBase,PBASE->size());
	}
	////////////////////////////////////////////////////////////////////////
	
	vWString::size_type vWString::size() const{
		return PBASE->size();
	}
	////////////////////////////////////////////////////////////////////////
	
	void vWString::push_back(const WString& str){
		 PBASE->push_back(str);
	}
	////////////////////////////////////////////////////////////////////////
	
	void vWString::add(const WString& str){
		 PBASE->push_back(str);
	}
	////////////////////////////////////////////////////////////////////////
	
	void vWString::pop_back(){
		 PBASE->pop_back();
	}
	////////////////////////////////////////////////////////////////////////
	vWString::const_reference vWString::operator[](size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vWString::reference vWString::operator[](size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	void vWString::assign(const_iterator first, const_iterator last){
		PBASE->assign(IteratorIPosS(first), IteratorIPosS(last));
	};
	////////////////////////////////////////////////////////////////////////
	void vWString::assign(size_type n, const WString& x){
		PBASE->assign(n,x);
	}
	////////////////////////////////////////////////////////////////////////
	void vWString::reserve(size_type n) {
		PBASE->reserve(n);
	}
	////////////////////////////////////////////////////////////////////////
		
	void vWString::insertElementAt(const WString &x ,int beforePos)
	{
		insert(begin()+beforePos,x);
	}

	////////////////////////////////////////////////////////////////////////
	vWString::iterator vWString::insert(iterator it, const WString& x ){
		PBASE->insert( IteratorIPos(it), x);
		return vWStringIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	void vWString::insert(iterator it, size_type n, const WString& x){
		 PBASE->insert(IteratorIPos(it), n, x);
	}
	////////////////////////////////////////////////////////////////////////
	void vWString::insert(iterator it, const_iterator first, const_iterator last){
		 PBASE->insert(IteratorIPos(it), IteratorIPosS(first), IteratorIPosS(last));
	}

	///////////////////////////////////////////////////////////////////////

	void vWString::sort(int first, int last){
		if(last<-1)
			last=(int)PBASE->size()+last;
		
		std::sort(PBASE->begin()+first, last<0 ? PBASE->end() :PBASE->begin()+last);
	}

	////////////////////////////////////////////////////////////////////////
	bool vWString::empty()const{
		return PBASE->empty();
	}
	////////////////////////////////////////////////////////////////////////
	void vWString::clear()const{
		PBASE->clear();
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	void vWString::RemoveStrings(const WString& s, int n){
		for (int i=PBASE->size()-1; i>=0; i--) {
			if (!s.compare(at(i))) {
				PBASE->erase(PBASE->begin()+i);
				if(--n==0) 
					break;
			}
		}
	}

	////////////////////////////////////////////////////////////////////////
	/// remove the last n occurrences of a string
	void vWString::RemoveStrings(const vWString& v, int n){
		for (int i=size()-1;i>=0;i--) {
			if (v.hasString(at(i))) {
				PBASE->erase(PBASE->begin()+i);
				if(--n==0) break;
			}
		}
	}

	////////////////////////////////////////////////////////////////////////
	/// remove the last n occurrences of a string
	bool vWString::containsAll(const vWString& v)const{
		for (int i=v.size()-1;i>=0;i--) {
			if (!hasString(v.at(i))) {
				return false;
			}
		}
		return true;
	}
	////////////////////////////////////////////////////////////////////////
	bool vWString::containsAny(const vWString &other) const
	{
		for (int i=other.size()-1;i>=0;i--) {
			if (hasString(other.at(i))) {
				return true;
			}
		}
		return false;
	}
////////////////////////////////////////////////////////////////////////

	void vWString::addAll(const vWString &v)
	{
		int sumsiz=PBASE->size()+v.size();
		if(PBASE->capacity()<sumsiz)
			reserve(sumsiz);

		for(unsigned int i=0; i<v.size(); i++)
			push_back(v.at(i));

	}
////////////////////////////////////////////////////////////////////////
	/// remove the last n occurrences of a string
	void vWString::Unify()
	{
		SetWString set;
		int siz=size();
		for (int i=0;i<siz;i++)
		{
			const WString& s=at(i);
			if(set.contains(s))
			{
				PBASE->erase(PBASE->begin()+i);
				i--;
				siz--;
			}
			else
			{
				set.add(s);
			}
		}        
	}

	////////////////////////////////////////////////////////////////////////
	int vWString::index(const WString& s, int start)const{
		for (unsigned int i=start;i<size();i++){
			if (!at(i).compare(s)) return i;
		}
		return -1;
	};
	////////////////////////////////////////////////////////////////////////
	vint vWString::multiIndex(const WString& s)const{
		vint vi;
		for (unsigned int i=0;i<size();i++){
			if (!at(i).compare(s)) vi.push_back(i);
		}
		return vi;
	};
	////////////////////////////////////////////////////////////////////////
	/// same as set::find
	vWString::iterator vWString::find(const WString & s){
		for (unsigned int i=0; i<size(); i++) {
			if (!s.compare(at(i))) 
				return vWString::iterator(pBase,i);
		}
		return end();
	}
	////////////////////////////////////////////////////////////////////////
	/// same as set::find
	vWString::const_iterator vWString::find(const WString &s)const{
		for (unsigned int i=0; i<size(); i++) {
			if (!s.compare(at(i))) 
				return vWString::iterator(pBase,i);
		}
		return end();
	}
	////////////////////////////////////////////////////////////////////////
	WString vWString::GetString(const WString& sep,const WString& front, const WString& back)const{
		WString s;
		s.SetvString(*this,sep,front,back);
		return s;
	}

	////////////////////////////////////////////////////////////////////////
	void vWString::AppendUnique(const vWString& v){
		addAll(v);
		Unify();
	}

	////////////////////////////////////////////////////////////////////////
	void vWString::AppendUnique(const WString& v){
		if(!hasString(v))
			push_back(v);
	}

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	vWStringIterator::vWStringIterator(){
		vWStringVector=0;
		iPos=0;
	}
	
	////////////////////////////////////////////////////////////////////////
	vWStringIterator::vWStringIterator(const vWStringIterator&other){
		iPos=other.iPos;
		vWStringVector=other.vWStringVector;
	}

	////////////////////////////////////////////////////////////////////////
	vWStringIterator& vWStringIterator::operator =(const vWStringIterator&other){
		iPos=other.iPos;
		vWStringVector=other.vWStringVector;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	vWStringIterator::vWStringIterator(void*p, int ipos){
		if(p){
			vWStringBase* v=(vWStringBase*)p;
			if(ipos<0)
				ipos=v->size(); // return end
			iPos=ipos;
			vWStringVector=p;

		}else{
			vWStringVector=0;
			iPos=0;
		}
	};
	////////////////////////////////////////////////////////////////////////

	vWStringIterator::~vWStringIterator(){
	};
	////////////////////////////////////////////////////////////////////////
	vWStringIterator vWStringIterator::operator +(int i)const{
		if(vWStringVector==0) 
			throw (L"JDFException null vWStringIterator");
		vWStringIterator it=*this;
		it.iPos+=i;
		return it;
	}

	////////////////////////////////////////////////////////////////////////
	vWStringIterator vWStringIterator::operator ++(){
		if(vWStringVector==0) 
			throw (L"JDFException null vWStringIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
	vWStringIterator vWStringIterator::operator ++(int){
		if(vWStringVector==0) 
			throw (L"JDFException null vWStringIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
		
	const vWStringIterator* vWStringIterator::operator->() const{
		return (&*this); 
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vWStringIterator::operator!=(const vWStringIterator & other) const{
		return (vWStringVector!=other.vWStringVector)||(iPos!=other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vWStringIterator::operator==(const vWStringIterator & other) const{
		return (vWStringVector==other.vWStringVector)&&(iPos==other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vWStringIterator::operator>(const vWStringIterator & other) const{
		bool result = (vWStringVector==other.vWStringVector);
		if (result)
			result = (iPos > other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vWStringIterator::operator<(const vWStringIterator & other) const{
		bool result = (vWStringVector==other.vWStringVector);
		if (result)
			result = (iPos<other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vWStringIterator::operator>=(const vWStringIterator & other) const{
		bool result = (vWStringVector==other.vWStringVector);
		if (result)
			result = (iPos >= other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vWStringIterator::operator<=(const vWStringIterator & other) const{
		bool result = (vWStringVector==other.vWStringVector);
		if (result)
			result = (iPos<=other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	vWString::reference vWStringIterator::operator *(){
		return ((vWStringBase*)vWStringVector)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	vWString::const_reference vWStringIterator::operator *() const{
		return ((vWStringBase*)vWStringVector)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	bool vWStringIterator::hasNext() const
	{
		int siz = ((vWStringBase*)vWStringVector)->size();
		if (iPos < siz)
			return true;
		else 
			return false;
	}
	///////////////////////////////////////////////////////////////////////
	WString vWStringIterator::next()
	{
		if (hasNext())
		{
			iPos++;
			return ((vWStringBase*)vWStringVector)->at(iPos-1);
		}
		else
			throw (L"vWStringIterator: no such element");
		return WString::emptyStr;
	}
	///////////////////////////////////////////////////////////////////////
	WString vWString::toString()
	{
		WString ret;
		for (int i=0;i<this->size();i++)
		{
			ret.append(this->elementAt(i));
			ret += " ";
		}
		return ret;
	}
} // namespace JDF

