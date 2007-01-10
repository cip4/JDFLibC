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

#include <vector>

#include <jdf/lang/WString.h>
#include <jdf/lang/mapWString.h>
#include <jdf/lang/vWString.h>


#define PBASE ((MapWStringBase*)pBase)
#define PBASES(s) ((MapWStringBase*)s.pBase)
#define BASES(s) (*((MapWStringBase*)s.pBase))


namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 


	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 

	/**
	* the empty string WString::emptyStr
	*/
	const MapWString MapWString::emptyMap=MapWString();

	/******************************************************************************
	*	Typedefs
	******************************************************************************/ 
	typedef std::vector<WString> MapWStringBase;


	/******************************************************************************
	*	Classes
	******************************************************************************/ 

	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/ 

	JDFTOOLS_EXPORT std::ostream& operator<<(std::ostream&s,const MapWString&t){
		for(MapWString::const_iterator i=t.begin();i!=t.end();i++){ 
			s<<WString(i->first())<<" "<<WString(i->second())<<std::endl;
		}
		return s; 
	}


	////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	/**
	* ctor
	*/
	MapWString::MapWString(){
		pBase=new MapWStringBase();
	};
	/**
	* copy ctor
	*/
	MapWString::MapWString(const MapWString&m){
		pBase=new MapWStringBase(BASES(m));
	};

	/**
	* Constructor for a simple map with one entry that is defined by key and value
	*
	* @param WString key the key to add to the map
	* @param WString value the value to set the map to
	*/
	MapWString::MapWString(const WString &key, const WString & value){
		pBase=new MapWStringBase();
		AppendPair(key,value);
	}


	/**
	* yactor
	*/
	MapWString& MapWString::operator =(const MapWString& other){
		*PBASE=BASES(other);
		return *this;
	};


	/**
	* dtor
	*/
	MapWString::~MapWString(){
		delete PBASE;
	};








	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////
	MapWString::iterator MapWString::begin(){
		return MapWStringIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	MapWString::const_iterator MapWString::begin()const{
		return MapWStringIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	MapWString::iterator MapWString::end(){
		return MapWStringIterator(pBase,PBASE->size());
	}
	////////////////////////////////////////////////////////////////////////
	MapWString::const_iterator MapWString::end()const{
		return MapWStringIterator(pBase,PBASE->size());
	}

	////////////////////////////////////////////////////////////////////////
	MapWString::size_type MapWString::size() const{
		return PBASE->size()/2;
	}
	////////////////////////////////////////////////////////////////////////

	int MapWString::index(const WString& s)const{
		int siz=PBASE->size();
		for (int i=0;i<siz;i+=2){
			if (!PBASE->at(i).compare(s)) 
				return i;
		}
		return -1;
	};

	////////////////////////////////////////////////////////////////////////
	MapWString::iterator MapWString::find(const WString & key){
		int i=index(key);
		return MapWStringIterator(pBase,i);
	}
	////////////////////////////////////////////////////////////////////////

	MapWString::const_iterator MapWString::find(const WString & key)const{
		int i=index(key);
		return MapWStringIterator(pBase,i);
	}
	////////////////////////////////////////////////////////////////////////

	void MapWString::clear()const{
		PBASE->clear();
	}
	////////////////////////////////////////////////////////////////////////
	bool MapWString::empty()const{
		return PBASE->empty();
	}
	////////////////////////////////////////////////////////////////////////
	bool MapWString::isEmpty()const{
		return PBASE->empty();
	}
	////////////////////////////////////////////////////////////////////////

	WString MapWString::operator [](const WString & key)const{
		int ind = index(key);
		if(ind==-1)
			return WString::emptyStr;
		return PBASE->at(ind+1);	
	}

	////////////////////////////////////////////////////////////////////

	WString MapWString::GetKeyByPos(unsigned int i)const{
		if((2*i+1)>PBASE->size())
			return WString::emptyStr;
		return PBASE->at(2*i);
	}
	////////////////////////////////////////////////////////////////////

	WString MapWString::GetValueByPos(unsigned int i)const{
		if((2*i+1)>PBASE->size())
			return WString::emptyStr;
		return PBASE->at(2*i+1);
	}
	////////////////////////////////////////////////////////////////////////

	MapWString::iterator MapWString::erase(iterator first, iterator last){
		PBASE->erase(PBASE->begin()+(first.iPos),PBASE->begin()+(1+last.iPos));
		return MapWStringIterator(pBase,first.iPos);

	}
	////////////////////////////////////////////////////////////////////////

	MapWString::iterator MapWString::erase(iterator it){
		PBASE->erase(PBASE->begin()+(it.iPos),PBASE->begin()+(2+it.iPos));
		return MapWStringIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////

	MapWString::size_type MapWString::erase(const WString& key){
		int i=index(key);
		if(i>=0){
			PBASE->erase(PBASE->begin()+i,PBASE->begin()+i+2);
			//			std::cout<<*this;
		}else{

		}
		return size();
	}	
	////////////////////////////////////////////////////////////////////////

	MapWString::size_type MapWString::remove(const WString& key){
		return erase(key);
	}	

	////////////////////////////////////////////////////////////////////////
	bool MapWString::operator ==(const MapWString& other)const {
		if (size()!=other.size()) 
			return false;
		for(const_iterator i=begin();i!=end();i++){
			const_iterator i2=other.find(i->first());
			if (i2==other.end()) 
				return false;
			if(i2->second().compare(i->second())) 
				return false;
		}
		return true;
	}

	////////////////////////////////////////////////////////////////////////
	bool MapWString::operator !=(const MapWString& other)const{
		return !(*this==other);
	};

	////////////////////////////////////////////////////////////////////////
	bool MapWString::SubMap(const MapWString& other)const {
		if (size()<other.size()) 
			return false;
		for(const_iterator i=other.begin();i!=other.end();i++){
			const_iterator i2=find(i->first());
			if (i2==end()) 
				return false;
			if(i2->second().compare(i->second())) 
				return false;
		}
		return true;
	}

	////////////////////////////////////////////////////////////////////////

	bool MapWString::OverlapMap(const MapWString& other)const {
		for(const_iterator i=begin();i!=end();i++){
			const_iterator i2=other.find(i->first());
			if (i2==other.end()) 
				continue;
			if(i2->second().compare(i->second())) 
				return false;
		}
		return true;
	}
	////////////////////////////////////////////////////////////////////////

	MapWString MapWString::OrMap(const MapWString& other) {
		MapWString m=*this;
		for(const_iterator i=other.begin();i!=other.end();i++){
			const_iterator i2=find(i->first());
			if (i2==end()) {
				m.AppendPair(i->first(),i->second());
				continue;
			}
			if(i2->second().compare(i->second())){
				m.clear();
				break;
			}
		}
		return *this=m;
	}

	////////////////////////////////////////////////////////////////////////
	MapWString MapWString::AndMap(const MapWString& other) {
		MapWString m;
		for(const_iterator i=begin();i!=end();i++){
			const_iterator i2=other.find(i->first());
			if (i2==other.end()) continue;
			if(i2->second().compare(i->second())) {
				m.clear();
				break;
			}
			m.AppendPair(i2->first(),i2->second());
		}
		return *this=m;
	}

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	MapWString MapWString::MergeMap(const MapWString& other) {
		for(const_iterator i=other.begin();i!=other.end();i++){
			SetPair(i->first(),i->second());
		}
		return *this;
	}

	////////////////////////////////////////////////////////////////////////

	void MapWString::ReduceKey(const vWString & vKeys){
		MapWString m;
		for(unsigned int j=0;j<vKeys.size();j++){
			const_iterator i=find(vKeys[j]);
			if (i!=end()) {
				m.AppendPair(i->first(),i->second());
			}
		}
		*this=m;
	}

	////////////////////////////////////////////////////////////////////////

	void MapWString::AddPair(const WString &key, const WString & value){
		if(HasKey(key))
			return;
		PBASE->push_back(key);
		PBASE->push_back(value);
	};

	////////////////////////////////////////////////////////////////////////

	void MapWString::AppendPair(const WString &key, const WString & value){
		PBASE->push_back(key);
		PBASE->push_back(value);
	};
	////////////////////////////////////////////////////////////////////////

	void MapWString::put(const WString &key, const WString & value){
		SetPair(key,value);
	}
	////////////////////////////////////////////////////////////////////////

	void MapWString::SetPair(const WString &key, const WString & value){
		int siz = PBASE->size();
		for(int i = 0; i < siz; i+=2)
		{
			if(PBASE->at(i).compare(key)==0)
			{
				PBASE->at(i + 1)=value;
				return;
			}
		}
		// found no matching, simply add
		PBASE->push_back(key);
		PBASE->push_back(value);
	};
	////////////////////////////////////////////////////////////////////////


	MapWString::size_type MapWString::erase(const vWString & vkeys){
		int j=size();
		for(unsigned int i=0;i<vkeys.size();i++){
			j=erase(vkeys[i]);
		}
		return j;
	}
	
	////////////////////////////////////////////////////////////////////////

	vWString MapWString::GetKeys()const{
		vWString v;
		int siz=PBASE->size();
		v.reserve(siz/2);
		for (int i=0;i<siz;i+=2){
			v.push_back(PBASE->at(i)); 
		}
		return v;
	}

	////////////////////////////////////////////////////////////////////////

	WString MapWString::GetValue(const WString &key)const
	{
		int siz = PBASE->size();
		for(int i = 0; i < siz; i+=2)
		{
			if(PBASE->at(i).compare(key)==0)
			{
				return PBASE->at(i + 1);
			}
		}
		return WString::emptyStr;
	}

	////////////////////////////////////////////////////////////////////////

	bool MapWString::HasKey(const WString &key)const
	{
		int siz = PBASE->size();
		for (int i = 0; i < siz; i += 2)
		{
			if (PBASE->at(i).compare(key)==0) 
			{
				return true;
			}
		}
		return false;
	}


	////////////////////////////////////////////////////////////////////////
	void MapWString::reserve(size_type len)
	{
		PBASE->reserve(2*len);
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	MapWStringIterator::MapWStringIterator(){
		mapVector=0;
		iPos=0;
	}

	////////////////////////////////////////////////////////////////////////
	MapWStringIterator::MapWStringIterator(const MapWStringIterator&other){
		iPos=other.iPos;
		mapVector=other.mapVector;
	}

	////////////////////////////////////////////////////////////////////////
	MapWStringIterator& MapWStringIterator::operator =(const MapWStringIterator&other){
		iPos=other.iPos;
		mapVector=other.mapVector;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	MapWStringIterator::MapWStringIterator(void*p, int ipos){
		if(p){
			MapWStringBase* v=(MapWStringBase*)p;
			if(ipos<0)
				ipos=v->size(); // return end
			iPos=ipos;
			mapVector=p;

		}else{
			mapVector=0;
			iPos=0;
		}
	};
	////////////////////////////////////////////////////////////////////////

	MapWStringIterator::~MapWStringIterator(){
	};

	////////////////////////////////////////////////////////////////////////
	MapWStringIterator MapWStringIterator::operator ++(){
		if(mapVector==0) 
			throw (L"JDFEXception null MapWStringIterator");
		iPos+=2;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
	MapWStringIterator MapWStringIterator::operator ++(int){
		if(mapVector==0) 
			throw (L"JDFEXception null MapWStringIterator");
		iPos+=2;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	const MapWStringIterator* MapWStringIterator::operator->() const{
		return (&*this); 
	}
	////////////////////////////////////////////////////////////////////////
	bool MapWStringIterator::operator!=(const MapWStringIterator & other) const{
		return (mapVector!=other.mapVector)||(iPos!=other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	bool MapWStringIterator::operator==(const MapWStringIterator & other) const{
		return (mapVector==other.mapVector)&&(iPos==other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	const WString& MapWStringIterator::first()const{
		const MapWStringBase* v=(const MapWStringBase*)mapVector;
		if(static_cast<unsigned int>(iPos) < v->size())
			return v->at(iPos);
		return WString::emptyStr;

	}
	////////////////////////////////////////////////////////////////////////
	const WString& MapWStringIterator::second()const{
		const MapWStringBase* v=(const MapWStringBase*)mapVector;
		if(static_cast<unsigned int>(iPos) < v->size())
			return v->at(iPos+1);
		return WString::emptyStr;

	}
	////////////////////////////////////////////////////////////////////////
	bool MapWStringIterator::hasNext() const
	{
		int siz = (int)( ((MapWStringBase*)mapVector)->size() / 2 );
		int pos = (int)( iPos / 2 );
		if (pos < siz-2)
			return true;
		else 
			return false;
	}
	////////////////////////////////////////////////////////////////////////
	WString MapWStringIterator::next()
	{
		if (hasNext())
		{
			iPos+=2;
			return second();
		}
		//else
		//	throw std::exception("MapWStringIterator: no such element");
		return WString::emptyStr;
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

} // namespace JDF

