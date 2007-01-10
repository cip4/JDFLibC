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

#include "vint.h"
#include <vector>


#define PBASE ((vIntBase*)pBase)
#define PBASES(s) ((vIntBase*)s.pBase)
#define BASES(s) (*((vIntBase*)s.pBase))
#define IteratorIPos(iter) (PBASE->begin()+iter.iPos)
#define IteratorIPosS(iter) (((vIntBase*)iter.vIntVector)->begin()+iter.iPos)

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
	typedef std::vector<int> vIntBase;
	
	
	/******************************************************************************
	*	Classes
	******************************************************************************/ 
	
	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 
	
	const vint vint::emptyvint;
	
	/******************************************************************************
	*	Implementation
	******************************************************************************/ 
	
	
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	vint::vint(){
		pBase=new vIntBase();
	}
	////////////////////////////////////////////////////////////////////////
	vint::vint(const vint&m){
			pBase=new vIntBase(BASES(m));
	};
	////////////////////////////////////////////////////////////////////////
	vint::vint(int i){
		pBase=new vIntBase();
		push_back(i);
	};
	////////////////////////////////////////////////////////////////////////
	
	vint & vint::operator=(const vint &m){
		if (this == &m)
			return *this;
		delete PBASE;
		if (m.size())
			pBase = new vIntBase(BASES(m));
		else
			pBase = new vIntBase();
		return *this;
	};
	////////////////////////////////////////////////////////////////////////
	vint::~vint(){
		delete PBASE;
	};
	////////////////////////////////////////////////////////////////////////
	vint::iterator vint::erase(iterator first, iterator last){
		PBASE->erase(IteratorIPos(first),IteratorIPos(last));
		return vintIterator(pBase,first.iPos);
	};
	////////////////////////////////////////////////////////////////////////
	vint::iterator vint::erase(iterator it){
		PBASE->erase(IteratorIPos(it));
		return vintIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	vint::iterator vint::begin(){
		return vintIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	vint::const_iterator vint::begin()const{
		return vintIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	vint::iterator vint::end(){
		return vintIterator(pBase,PBASE->size());
	}
	////////////////////////////////////////////////////////////////////////
	vint::const_iterator vint::end()const{
		return vintIterator(pBase,PBASE->size());
	}
	////////////////////////////////////////////////////////////////////////
	vint::size_type vint::size() const{
		return PBASE->size();
	}
	////////////////////////////////////////////////////////////////////////
	void vint::push_back(int str){
		 PBASE->push_back(str);
	}
	////////////////////////////////////////////////////////////////////////
	void vint::add(int str){
		 PBASE->push_back(str);
	}
	////////////////////////////////////////////////////////////////////////
	vint::const_reference vint::operator[](size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vint::reference vint::operator[](size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vint::const_reference vint::at(size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vint::reference vint::at(size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	void vint::assign(const_iterator first, const_iterator last){
		 PBASE->assign(IteratorIPosS(first), IteratorIPosS(last));
	};
	////////////////////////////////////////////////////////////////////////
	void vint::assign(size_type n, int x){
		PBASE->assign(n,x);
	}
	////////////////////////////////////////////////////////////////////////
	vint::iterator vint::insert(iterator it, const int x ){
		PBASE->insert( IteratorIPos(it), x);
		return vintIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	void vint::insert(iterator it, size_type n, const int x){
		 PBASE->insert(IteratorIPos(it), n, x);
	}
	////////////////////////////////////////////////////////////////////////
	void vint::insert(iterator it, const_iterator first, const_iterator last){
		 PBASE->insert(IteratorIPos(it), IteratorIPosS(first), IteratorIPosS(last));
	}
	////////////////////////////////////////////////////////////////////////

	bool vint::empty()const{
		return PBASE->empty();
	}
	////////////////////////////////////////////////////////////////////////
	void vint::clear()const{
		PBASE->clear();
	}
	////////////////////////////////////////////////////////////////////////
	WString vint::GetString( const WString& sep, const WString& front , const WString& end)const{
		WString s=front;
		int siz=size();
		for(int i=0;i<siz;i++){
			if(i) 
				s+=sep;
			s+=WString::valueOf(at(i));
		}
		s+=end;
		return s;
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	int vint::index(int search, int start)const{
		for (unsigned int i=start;i<size();i++){
			if (at(i)==search) 
				return i;
		}
		return -1;
	};
	
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	vintIterator::vintIterator(){
		vIntVector=0;
		iPos=0;
	}
	
	////////////////////////////////////////////////////////////////////////
	vintIterator::vintIterator(const vintIterator&other){
		iPos=other.iPos;
		vIntVector=other.vIntVector;
	}

	////////////////////////////////////////////////////////////////////////
	vintIterator& vintIterator::operator =(const vintIterator&other){
		iPos=other.iPos;
		vIntVector=other.vIntVector;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	vintIterator::vintIterator(void*p, int ipos){
		if(p){
			vIntBase* v=(vIntBase*)p;
			if(ipos<0)
				ipos=v->size(); // return end
			iPos=ipos;
			vIntVector=p;

		}else{
			vIntVector=0;
			iPos=0;
		}
	};
	////////////////////////////////////////////////////////////////////////

	vintIterator::~vintIterator(){
	};

	////////////////////////////////////////////////////////////////////////
	vintIterator vintIterator::operator +(int i)const{
		if(vIntVector==0) 
			throw (L"JDFException null vintIterator");
		vintIterator it=*this;
		it.iPos+=i;
		return it;
	}
	////////////////////////////////////////////////////////////////////////
	vintIterator vintIterator::operator ++(){
		if(vIntVector==0) 
			throw (L"JDFException null vintIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
	vintIterator vintIterator::operator ++(int){
		if(vIntVector==0) 
			throw (L"JDFException null vintIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
		
	const vintIterator* vintIterator::operator->() const{
		return (&*this); 
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vintIterator::operator!=(const vintIterator & other) const{
		return (vIntVector!=other.vIntVector)||(iPos!=other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vintIterator::operator==(const vintIterator & other) const{
		return (vIntVector==other.vIntVector)&&(iPos==other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vintIterator::operator>(const vintIterator & other) const{
		bool result = (vIntVector==other.vIntVector);
		if (result)
			result = (iPos > other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vintIterator::operator<(const vintIterator & other) const{
		bool result = (vIntVector==other.vIntVector);
		if (result)
			result = (iPos<other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vintIterator::operator>=(const vintIterator & other) const{
		bool result = (vIntVector==other.vIntVector);
		if (result)
			result = (iPos >= other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vintIterator::operator<=(const vintIterator & other) const{
		bool result = (vIntVector==other.vIntVector);
		if (result)
			result = (iPos<=other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////

	vint::reference vintIterator::operator *(){
		return ((vIntBase*)vIntVector)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	
	vint::const_reference vintIterator::operator *() const{
		return ((vIntBase*)vIntVector)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////

} // namespace JDF

