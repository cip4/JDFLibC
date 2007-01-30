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
// JDFNameRangeList.cpp: implementation of the JDFNameRangeList class.
//
//////////////////////////////////////////////////////////////////////


#include "JDFNameRangeList.h"
#include "JDFNameRange.h"
#include <vector>

#define PBASE ((vNBase*)pBase)
#define PBASES(s) ((vNBase*)s.pBase)
#define BASES(s) (*((vNBase*)s.pBase))
// RN20060321
#define IteratorIPos(iter) (PBASE->begin()+iter.iPos)
#define IteratorIPosS(iter) (((vNBase*)iter.pJDFNameRange)->begin()+iter.iPos)

/**
* RangeList for names (NMTOKENS)
*/
namespace JDF{
	
	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	
	typedef std::vector<JDFNameRange> vNBase;

	//////////////////////////////////////////////////////////////////////
	
	JDFNameRangeList::JDFNameRangeList() { 

		pBase=new vNBase();
	}

	//////////////////////////////////////////////////////////////////////
	
	JDFNameRangeList::JDFNameRangeList(const WString& s){
		
		pBase = new vNBase();
		SetString(s);
	}

	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList& JDFNameRangeList::operator=(const WString& s){

		SetString(s);
		return *this;
	}
	
	//////////////////////////////////////////////////////////////////////
	
	JDFNameRangeList::JDFNameRangeList(const JDFNameRangeList & rl) { 
		pBase=new vNBase(BASES(rl));
	}
	
	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList& JDFNameRangeList::operator=(const JDFNameRangeList & rl){ 
		
		if (this == &rl)
			return *this;
		if (rl.size())
			*PBASE=(BASES(rl));
		else
			PBASE->clear();
		return *this;
	}

	//////////////////////////////////////////////////////////////////////
	
	JDFNameRangeList::~JDFNameRangeList(){
		delete PBASE;
	};

	//////////////////////////////////////////////////////////////////////
	
	bool JDFNameRangeList::InRange(const WString& x){
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			NameRange r=PBASE->at(i);
			if(r.InRange(x)) 
				return true;
		}
		return false;
	}
	//////////////////////////////////////////////////////////////////////
	bool JDFNameRangeList::IsPartOfRange(JDFNameRange& x){
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			NameRange r=PBASE->at(i);
			if(r.IsPartOfRange(x)) 
				return true;
		}
		return false;
	}

	//////////////////////////////////////////////////////////////////////
	bool JDFNameRangeList::IsPartOfRange(JDFNameRangeList& x){
		int sz=x.size();
		for(int i=0;i<sz;i++){
			NameRange range=x.at(i);
			if(!IsPartOfRange(range)) 
				return false;
		}
		return true;
	}

	//////////////////////////////////////////////////////////////////////
	void JDFNameRangeList::Append(const JDFNameRange& r){
		PBASE->push_back(r);
	};
	
	/**
	* Add a Range defined by two ints xMin~xMax
	* @param int xMin the left value of the range to append to the list
	* @param int xMax the right value of the range to append to the list
	*/
	void JDFNameRangeList::Append(const WString& xMin, const WString& xMax){
		Append(JDFNameRange(xMin,xMax));
	};
	
	/**
	* number of range elements
	* @return int the number of Ranges in the list
	*/
	int JDFNameRangeList::size()const{
		return PBASE->size();
	};
	
	/**
	* cleanup and empty the internal storge
	*/
	void JDFNameRangeList::clear(){
		PBASE->clear();
	};
	
	//////////////////////////////////////////////////////////////////////
	
	WString JDFNameRangeList::GetString()const{
		WString s;
		int sz=PBASE->size();
		for(int i=0;i<sz;i++){
			s+=PBASE->at(i).GetString();
			if(i<(sz-1)) s+=" ";
		}
		return s;
	};
	
	//////////////////////////////////////////////////////////////////////
	void JDFNameRangeList::SetString(const WString& str) {
        if (str.empty()) 
			return;
		WString zappedWS=str;
		zappedWS.ZappTokenWS("~"); // convert " A ~ B C ~ D" to " A~B C~D"
		vWString vs=zappedWS.Tokenize(" \t");
		PBASE->clear();

        for(int i = 0; i < vs.size(); i++)
        {
            WString s = vs[i];
            try 
            {
                NameRange r = NameRange(s); 
                PBASE->push_back(r);
            }
            catch (Exception e)
			{
				throw JDFException("JDFNameRangeList::SetString: Illegal string " + s);
            }
        }
    }


	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList::iterator JDFNameRangeList::erase(iterator i) {
      // RN20060321
      PBASE->erase(IteratorIPos(i));
		return JDFNmRngLstIterator(pBase,i.iPos);
	};

	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList::iterator JDFNameRangeList::begin() {
      // RN20060321
      return JDFNmRngLstIterator(pBase,0);
	};

	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList::iterator JDFNameRangeList::end() {
      // RN20060321
      return JDFNmRngLstIterator(pBase,PBASE->size());
	};

	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList::const_iterator JDFNameRangeList::begin() const{
      // RN20060321
		return JDFNmRngLstIterator(pBase,0);
	};

	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList::const_iterator JDFNameRangeList::end() const{
      // RN20060321
		return JDFNmRngLstIterator(pBase,PBASE->size());
	};

	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList::const_reference JDFNameRangeList::operator[](int i) const{
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFNameRangeList operator []: illegal index");
		return PBASE->at(i);
	}

	//////////////////////////////////////////////////////////////////////

	JDFNameRangeList::reference JDFNameRangeList::operator[](int i){
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFNameRangeList operator []: illegal index");
		return PBASE->at(i);
	}

	//////////////////////////////////////////////////////////////////////
	
	JDFNameRangeList::const_reference JDFNameRangeList::at(int i) const{
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFNameRangeList at(i): illegal index");
		return PBASE->at(i);
	}


	//////////////////////////////////////////////////////////////////////
	
	JDFNameRangeList::reference JDFNameRangeList::at(int i) {
		if((i<0)||(i>=PBASE->size())) 
			throw JDFException("JDFNameRangeList at(i): illegal index");
		return PBASE->at(i);
	}

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
   // RN20060321
	////////////////////////////////////////////////////////////////////////
   // Implementation of JDFNmRngLstIterator
	////////////////////////////////////////////////////////////////////////

	JDFNmRngLstIterator::JDFNmRngLstIterator(){
		pJDFNameRange=0;
		iPos=0;
	}
	
	////////////////////////////////////////////////////////////////////////
	JDFNmRngLstIterator::JDFNmRngLstIterator(const JDFNmRngLstIterator&other){
		iPos=other.iPos;
		pJDFNameRange=other.pJDFNameRange;
	}

	////////////////////////////////////////////////////////////////////////
	JDFNmRngLstIterator& JDFNmRngLstIterator::operator =(const JDFNmRngLstIterator&other){
		iPos=other.iPos;
		pJDFNameRange=other.pJDFNameRange;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	JDFNmRngLstIterator::JDFNmRngLstIterator(void*p, int ipos){
		if(p){
			vNBase* v=(vNBase*)p;
			if(ipos<0)
				ipos=v->size(); // return end
			iPos=ipos;
			pJDFNameRange=p;

		}else{
			pJDFNameRange=0;
			iPos=0;
		}
	};
	////////////////////////////////////////////////////////////////////////

	JDFNmRngLstIterator::~JDFNmRngLstIterator(){
	};

	////////////////////////////////////////////////////////////////////////
	JDFNmRngLstIterator JDFNmRngLstIterator::operator +(int i)const{
		if(pJDFNameRange==0) 
			throw (L"JDFException null JDFNmRngLstIterator");
		JDFNmRngLstIterator it=*this;
		it.iPos+=i;
		return it;
	}
	////////////////////////////////////////////////////////////////////////
	JDFNmRngLstIterator JDFNmRngLstIterator::operator ++(){
		if(pJDFNameRange==0) 
			throw (L"JDFException null JDFNmRngLstIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
	JDFNmRngLstIterator JDFNmRngLstIterator::operator ++(int){
		if(pJDFNameRange==0) 
			throw (L"JDFException null JDFNmRngLstIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
		
	const JDFNmRngLstIterator* JDFNmRngLstIterator::operator->() const{
		return (&*this); 
	}
	////////////////////////////////////////////////////////////////////////
	
	bool JDFNmRngLstIterator::operator!=(const JDFNmRngLstIterator & other) const{
		return (pJDFNameRange!=other.pJDFNameRange)||(iPos!=other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool JDFNmRngLstIterator::operator==(const JDFNmRngLstIterator & other) const{
		return (pJDFNameRange==other.pJDFNameRange)&&(iPos==other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool JDFNmRngLstIterator::operator>(const JDFNmRngLstIterator & other) const{
		bool result = (pJDFNameRange==other.pJDFNameRange);
		if (result)
			result = (iPos > other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool JDFNmRngLstIterator::operator<(const JDFNmRngLstIterator & other) const{
		bool result = (pJDFNameRange==other.pJDFNameRange);
		if (result)
			result = (iPos<other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////
	
	bool JDFNmRngLstIterator::operator>=(const JDFNmRngLstIterator & other) const{
		bool result = (pJDFNameRange==other.pJDFNameRange);
		if (result)
			result = (iPos >= other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool JDFNmRngLstIterator::operator<=(const JDFNmRngLstIterator & other) const{
		bool result = (pJDFNameRange==other.pJDFNameRange);
		if (result)
			result = (iPos<=other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////

	JDFNameRangeList::reference JDFNmRngLstIterator::operator *(){
		return ((vNBase*)pJDFNameRange)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	
	JDFNameRangeList::const_reference JDFNmRngLstIterator::operator *() const{
		return ((vNBase*)pJDFNameRange)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////
}