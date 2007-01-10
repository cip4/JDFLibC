/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2004 The doubleernational Cooperation for the doubleegration of 
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
*        The doubleernational Cooperation for the doubleegration of 
*        Processes in  Prepress, Press and Postpress (www.cip4.org)"
*    Alternately, this acknowledgment may appear in the software itself,
*    if and wherever such third-party acknowledgments normally appear.
*
* 4. The names "CIP4" and "The doubleernational Cooperation for the doubleegration of 
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
* DISCLAIMED.  IN NO EVENT SHALL THE doubleERNATIONAL COOPERATION FOR
* THE doubleEGRATION OF PROCESSES IN PREPRESS, PRESS AND POSTPRESS OR
* ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
* USE, DATA, OR PROFITS; OR BUSINESS doubleERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
* SUCH DAMAGE.
* ====================================================================
*
* This software consists of voluntary contributions made by many
* individuals on behalf of the The doubleernational Cooperation for the doubleegration 
* of Processes in Prepress, Press and Postpress and was
* originally based on software 
* copyright (c) 1999-2001, Heidelberger Druckmaschinen AG 
* copyright (c) 1999-2001, Agfa-Gevaert N.V. 
*  
* For more information on The doubleernational Cooperation for the 
* doubleegration of Processes in  Prepress, Press and Postpress , please see
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

#include "vdouble.h"

#include <vector>


#define PBASE ((vdoubleBase*)pBase)
#define PBASES(s) ((vdoubleBase*)s.pBase)
#define BASES(s) (*((vdoubleBase*)s.pBase))
#define IteratorIPos(iter) (PBASE->begin()+iter.iPos)
#define IteratorIPosS(iter) (((vdoubleBase*)iter.vdoubleVector)->begin()+iter.iPos)

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
	typedef std::vector<double> vdoubleBase;
	
	const vdouble vdouble::emptyvdouble;
	
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
	vdouble::vdouble(){
		pBase=new vdoubleBase();
	}
	////////////////////////////////////////////////////////////////////////
	vdouble::vdouble(const vdouble&m){
			pBase=new vdoubleBase(BASES(m));
	};
	////////////////////////////////////////////////////////////////////////
	vdouble::vdouble(double i){
		pBase=new vdoubleBase();
		push_back(i);
	};
	////////////////////////////////////////////////////////////////////////
	//Matt-Start
	vdouble & vdouble::operator=(const vdouble &m){
		if (this == &m)
			return *this;
		delete PBASE;
		if (m.size())
			pBase = new vdoubleBase(BASES(m));
		else
			pBase = new vdoubleBase();
		return *this;
	};
	//Matt-End
	////////////////////////////////////////////////////////////////////////
	vdouble::~vdouble(){
		delete PBASE;
	};
	////////////////////////////////////////////////////////////////////////
	vdouble::iterator vdouble::erase(iterator first, iterator last){
		PBASE->erase(IteratorIPos(first),IteratorIPos(last));
		return vdoubleIterator(pBase,first.iPos);
	};
	////////////////////////////////////////////////////////////////////////
	vdouble::iterator vdouble::erase(iterator it){
		PBASE->erase(IteratorIPos(it));
		return vdoubleIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	vdouble::iterator vdouble::begin(){
		return vdoubleIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	vdouble::const_iterator vdouble::begin()const{
		return vdoubleIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	vdouble::iterator vdouble::end(){
		return vdoubleIterator(pBase,PBASE->size());
	}
	////////////////////////////////////////////////////////////////////////
	vdouble::const_iterator vdouble::end()const{
		return vdoubleIterator(pBase,PBASE->size());
	}
	////////////////////////////////////////////////////////////////////////
	vdouble::size_type vdouble::size() const{
		return PBASE->size();
	}
	////////////////////////////////////////////////////////////////////////
	void vdouble::push_back(double str){
		 PBASE->push_back(str);
	}
	////////////////////////////////////////////////////////////////////////
	vdouble::const_reference vdouble::operator[](size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vdouble::reference vdouble::operator[](size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vdouble::const_reference vdouble::at(size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vdouble::reference vdouble::at(size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	void vdouble::assign(const_iterator first, const_iterator last){
		 PBASE->assign(IteratorIPosS(first), IteratorIPosS(last));
	};
	////////////////////////////////////////////////////////////////////////
	void vdouble::assign(size_type n, double x){
		PBASE->assign(n,x);
	}
	////////////////////////////////////////////////////////////////////////
	vdouble::iterator vdouble::insert(iterator it, const double x ){
		PBASE->insert( IteratorIPos(it), x);
		return vdoubleIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	void vdouble::insert(iterator it, size_type n, const double x){
		 PBASE->insert(IteratorIPos(it), n, x);
	}
	////////////////////////////////////////////////////////////////////////
	void vdouble::insert(iterator it, const_iterator first, const_iterator last){
		  PBASE->insert(IteratorIPos(it), IteratorIPosS(first), IteratorIPosS(last));
	}
	////////////////////////////////////////////////////////////////////////
	bool vdouble::empty()const{
		return PBASE->empty();
	}
	////////////////////////////////////////////////////////////////////////
	void vdouble::clear()const{
		PBASE->clear();
	}	
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	WString vdouble::GetString( const WString& sep, const WString& front , const WString& end)const{
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
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	vdoubleIterator::vdoubleIterator(){
		vdoubleVector=0;
		iPos=0;
	}
	
	////////////////////////////////////////////////////////////////////////
	vdoubleIterator::vdoubleIterator(const vdoubleIterator&other){
		iPos=other.iPos;
		vdoubleVector=other.vdoubleVector;
	}

	////////////////////////////////////////////////////////////////////////
	vdoubleIterator& vdoubleIterator::operator =(const vdoubleIterator&other){
		iPos=other.iPos;
		vdoubleVector=other.vdoubleVector;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	vdoubleIterator::vdoubleIterator(void*p, int ipos){
		if(p){
			vdoubleBase* v=(vdoubleBase*)p;
			if(ipos<0)
				ipos=v->size(); // return end
			iPos=ipos;
			vdoubleVector=p;

		}else{
			vdoubleVector=0;
			iPos=0;
		}
	};
	////////////////////////////////////////////////////////////////////////

	vdoubleIterator::~vdoubleIterator(){
	};

	////////////////////////////////////////////////////////////////////////
	vdoubleIterator vdoubleIterator::operator +(int i)const{
		if(vdoubleVector==0) 
			throw (L"JDFException null vdoubleIterator");
		vdoubleIterator it=*this;
		it.iPos+=i;
		return it;
	}
	////////////////////////////////////////////////////////////////////////
	vdoubleIterator vdoubleIterator::operator ++(){
		if(vdoubleVector==0) 
			throw (L"JDFException null vdoubleIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
	vdoubleIterator vdoubleIterator::operator ++(int){
		if(vdoubleVector==0) 
			throw (L"JDFException null vdoubleIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
		
	const vdoubleIterator* vdoubleIterator::operator->() const{
		return (&*this); 
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vdoubleIterator::operator!=(const vdoubleIterator & other) const{
		return (vdoubleVector!=other.vdoubleVector)||(iPos!=other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vdoubleIterator::operator==(const vdoubleIterator & other) const{
		return (vdoubleVector==other.vdoubleVector)&&(iPos==other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vdoubleIterator::operator>(const vdoubleIterator & other) const{
		bool result = (vdoubleVector==other.vdoubleVector);
		if (result)
			result = (iPos > other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vdoubleIterator::operator<(const vdoubleIterator & other) const{
		bool result = (vdoubleVector==other.vdoubleVector);
		if (result)
			result = (iPos<other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vdoubleIterator::operator>=(const vdoubleIterator & other) const{
		bool result = (vdoubleVector==other.vdoubleVector);
		if (result)
			result = (iPos >= other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vdoubleIterator::operator<=(const vdoubleIterator & other) const{
		bool result = (vdoubleVector==other.vdoubleVector);
		if (result)
			result = (iPos<=other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////

	vdouble::reference vdoubleIterator::operator *(){
		return ((vdoubleBase*)vdoubleVector)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	
	vdouble::const_reference vdoubleIterator::operator *() const{
		return ((vdoubleBase*)vdoubleVector)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////

} // namespace JDF

