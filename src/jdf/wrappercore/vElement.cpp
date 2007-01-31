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
// COPYRIGHT Heidelberger Druckmaschinen AG, 1999-2000
//      ALL RIGHTS RESERVED 
//
//  Author: Dr. Rainer Prosi
// 
// Revision history:
// created before 19.Jan.2000
// KElement.cpp: implementation of the KElement class.
// 151101 RP added GetInheritedAttribute, GetInheritedElement, AddNameSpace
//
//////////////////////////////////////////////////////////////////////

#include "vElement.h"

#include "KElement.h"
#include "JDFException.h"

#include<vector>


#define PBASE ((vElementBase*)pBase)
#define PBASES(s) ((vElementBase*)s.pBase)
#define BASES(s) (*((vElementBase*)s.pBase))
#define IteratorIPos(iter) (PBASE->begin()+iter.iPos)
#define IteratorIPosS(iter) (((vElementBase*)iter.vElementVector)->begin()+iter.iPos)

namespace JDF{
	
	typedef std::vector<KElement> vElementBase;
	const vElement vElement::emptyVector=vElement();
	
	//////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	vElement::vElement(){
		pBase=new vElementBase();
	}
	////////////////////////////////////////////////////////////////////////
	
	vElement::vElement(const vElement&m){
		pBase=new vElementBase(BASES(m));
	};
	
	////////////////////////////////////////////////////////////////////////
	vElement &vElement::operator =(const vElement& other){
		*PBASE=BASES(other);
		return *this;
	};
	////////////////////////////////////////////////////////////////////////
	vElement::~vElement(){
		delete PBASE;
	};
	////////////////////////////////////////////////////////////////////////

	vWString vElement::GetElementNameVector(bool bLocal)const{
		vWString v;
		int s=size();
		for(int i=0;i<s;i++) {
			if(bLocal){
				v.push_back(at(i).GetLocalName());				
			}else{
				v.push_back(at(i).GetNodeName());
			}
		}
		return v;
	}
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	vElement::const_reference vElement::at(size_type pos) const{
		return PBASE->at(pos);
	}
	vElement::const_reference vElement::elementAt(size_type pos) const{
		return PBASE->at(pos);
	}
	////////////////////////////////////////////////////////////////////////
	
	vElement::reference vElement::at(size_type pos){
		return PBASE->at(pos);
	}
	vElement::reference vElement::elementAt(size_type pos){
		return PBASE->at(pos);
	}
	////////////////////////////////////////////////////////////////////////
	
	vElement::iterator vElement::erase(iterator first, iterator last){
        PBASE->erase(IteratorIPos(first),IteratorIPos(last));
		return vElementIterator(pBase,first.iPos);
	};
	////////////////////////////////////////////////////////////////////////
	
	vElement::iterator vElement::erase(iterator it){
		PBASE->erase(IteratorIPos(it));
		return vElementIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	vElement::iterator vElement::begin(){
		return vElementIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	vElement::const_iterator vElement::begin()const{
		return vElementIterator(pBase,0);
	}
	////////////////////////////////////////////////////////////////////////
	vElement::iterator vElement::end(){
		return vElementIterator(pBase,PBASE->size());
	}
	////////////////////////////////////////////////////////////////////////
	vElement::const_iterator vElement::end()const{
		return vElementIterator(pBase,PBASE->size());
	}

	////////////////////////////////////////////////////////////////////////
	bool vElement::empty()const{
		return PBASE->empty();
	}
	////////////////////////////////////////////////////////////////////////
	void vElement::clear()const{
		PBASE->clear();
	}
	////////////////////////////////////////////////////////////////////////
	vElement::size_type vElement::size() const{
		return PBASE->size();
	}
	////////////////////////////////////////////////////////////////////////
	void vElement::push_back(const KElement& str){
		PBASE->push_back(str);
	}
	////////////////////////////////////////////////////////////////////////

	void vElement::add(const KElement& str){
		PBASE->push_back(str);
	}

	////////////////////////////////////////////////////////////////////////
	vElement::const_reference vElement::operator[](size_type pos) const{
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	vElement::reference vElement::operator[](size_type pos){
		return PBASE->at(pos);
	};
	////////////////////////////////////////////////////////////////////////
	void vElement::assign(const_iterator first, const_iterator last){
		PBASE->assign(IteratorIPosS(first), IteratorIPosS(last));
	};
	////////////////////////////////////////////////////////////////////////
	//@vigo
	void vElement::assign(size_type n) {
		PBASE->assign(n, KElement::DefKElement);
	}
	////////////////////////////////////////////////////////////////////////
	void vElement::reserve(size_type n) {
		PBASE->reserve(n);
	}
	////////////////////////////////////////////////////////////////////////
	void vElement::assign(size_type n, const KElement& x){
		PBASE->assign(n,x);
	}
	
	////////////////////////////////////////////////////////////////////////
	//@vigo
	vElement::iterator vElement::insert(iterator it) {
		PBASE->insert( IteratorIPos(it), KElement());
		return vElementIterator(pBase,it.iPos);
	}
	
	////////////////////////////////////////////////////////////////////////
	vElement::iterator vElement::insert(iterator it, const KElement& x ){
		PBASE->insert( IteratorIPos(it), x);
		return vElementIterator(pBase,it.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	void vElement::insert(iterator it, size_type n, const KElement& x){
		PBASE->insert(IteratorIPos(it), n, x);
	}
	////////////////////////////////////////////////////////////////////////
	void vElement::insert(iterator it, const_iterator first, const_iterator last){
		PBASE->insert(IteratorIPos(it), IteratorIPosS(first), IteratorIPosS(last));
	}
	////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
		
	void vElement::SetAttributes(const WString & key, const WString & value,const WString & nameSpaceURI){
		for(int i=0;i<size();i++){
			at(i).SetAttribute(key,value,nameSpaceURI);
		}
	}
	//////////////////////////////////////////////////////////////////////
	void vElement::SetAttributes(const WString & key, const vWString & vValue,const WString & nameSpaceURI){
		if(size()!=vValue.size()) 
			throw JDFException(L"vElement::SetAttributes: size mismatch");
		for(int i=0;i<size();i++){
			at(i).SetAttribute(key,vValue[i],nameSpaceURI);
		}
	}
	//////////////////////////////////////////////////////////////////////
	void vElement::RemoveElements(const vElement& v){
		for(int i=size()-1; i>=0; i--){
			if (v.hasElement(at(i))) 
				erase(vElementIterator(pBase,i));
		}
	}
	//////////////////////////////////////////////////////////////////////
	void vElement::RemoveElements(const KElement& e, int nMax){
		int j=0;
		for(int i=size()-1; i>=0; i--){
			if (e==at(i)){
				erase(vElementIterator(pBase,i));
				if(++j==nMax) 
					break;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////
	
	int vElement::index(const KElement& s)const{ 
		for (int i=0; i<size(); i++){
			if (s.IsEqual(at(i))) 
				return i;
		}
		return -1;
	};
	
	//////////////////////////////////////////////////////////////////////
	vElement::iterator vElement::find(const KElement & s){
		for (int i=0; i<size(); i++) {
			if (s.IsEqual(at(i))) 
				return vElementIterator(pBase,i); 
		}
		return end();
	}
	//////////////////////////////////////////////////////////////////////
	
	vElement::const_iterator vElement::find(const KElement & s)const{
		for (int i=0; i<size(); i++) {
			if (s.IsEqual(at(i))) 
				return vElementIterator(pBase,i); 
		}
		
		return end();
	}
	//////////////////////////////////////////////////////////////////////
	
	void vElement::AppendUnique(const KElement& e){ 
		if(!hasElement(e)) 
			push_back(e);
	}
	
	//////////////////////////////////////////////////////////////////////

	void vElement::AppendUniqueByName(const KElement& e){ 
		unsigned int siz=size();
		WString nn=e.GetNodeName();
		for (int i=0; i<siz; i++){
			if (nn==at(i).GetNodeName()) 
				return;
		}
		push_back(e);
	}
	
	//////////////////////////////////////////////////////////////////////
	void vElement::AppendUnique(const vElement& v){
		int sumsiz=PBASE->size()+v.size();
		if(PBASE->capacity()<sumsiz)
			reserve(sumsiz);

		for(int i=0; i<v.size(); i++) 
			AppendUnique(v.at(i)); 
	}
	//////////////////////////////////////////////////////////////////////
	void vElement::AppendUniqueByName(const vElement& v){
		int sumsiz=PBASE->size()+v.size();
		if(PBASE->capacity()<sumsiz)
			reserve(sumsiz);
		for(int i=0; i<v.size(); i++) 
			AppendUniqueByName(v.at(i)); 
	}
	
	//////////////////////////////////////////////////////////////////////

	bool vElement::hasElement(const KElement &s)const{
		return index(s)>=0;
	}
	////////////////////////////////////////////////////////////////////////

	JDF_WRAPPERCORE_EXPORT std::ostream& operator<<(std::ostream&s,const vElement&t){

		for(int i=0; i<t.size(); i++){ 
			s<<t.at(i)<<std::endl;
		}
		return s; 
	}
	////////////////////////////////////////////////////////////////////////

	KElement vElement::GetCommonAncestor()const{
		int siz=size();
		if(siz==0)
			return KElement::DefKElement;

		if(siz==1) // only one - the ancestor is the only entry itself
			return at(0);

		KElement ret=at(0); // could all be the same, therefore do not start with parent node

		// loop down searching for a common ancestor
		while(!ret.isNull()){
			bool bOK=true;
			for(int i=1;i<siz;i++){ // start at 1, since the parents of 0 are ok by definition
				if(!ret.IsAncestor(at(i))){
					bOK=false;
					break;
				}
			}
			if(bOK){ // found the ancestor of all members
				return ret;
			}
			ret=ret.GetParentNode();
		}
		return ret; // if we get here it is null
	}

	////////////////////////////////////////////////////////////////////////
   void vElement::RemoveAttribute(const WString &  attrib, const WString & nameSpaceURI)
    {
		int siz=size();
    	for(int i=0;i<siz;i++){
			at(i).RemoveAttribute(attrib,nameSpaceURI);
    	}
    }

	////////////////////////////////////////////////////////////////////////
	void vElement::remove(int i){
		PBASE->erase(PBASE->begin()+i);
	}


	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////

	vElementIterator::vElementIterator(){
		vElementVector=0;
		iPos=0;
	}
	
	////////////////////////////////////////////////////////////////////////
	vElementIterator::vElementIterator(const vElementIterator&other){
		iPos=other.iPos;
		vElementVector=other.vElementVector;
	}

	////////////////////////////////////////////////////////////////////////
	vElementIterator& vElementIterator::operator =(const vElementIterator&other){
		iPos=other.iPos;
		vElementVector=other.vElementVector;
		return *this;
	}

	////////////////////////////////////////////////////////////////////////
	vElementIterator::vElementIterator(void*p, int ipos){
		if(p){
			vElementBase* v=(vElementBase*)p;
			if(ipos<0)
				ipos=v->size(); // return end
			iPos=ipos;
			vElementVector=p;

		}else{
			vElementVector=0;
			iPos=0;
		}
	};
	////////////////////////////////////////////////////////////////////////

	vElementIterator::~vElementIterator(){
	};

	////////////////////////////////////////////////////////////////////////
	vElementIterator vElementIterator::operator +(int i)const{
		if(vElementVector==0) 
			throw (L"JDFException null vElementIterator");
		vElementIterator it=*this;
		it.iPos+=i;
		return it;
	}
	////////////////////////////////////////////////////////////////////////
	vElementIterator vElementIterator::operator ++(){
		if(vElementVector==0) 
			throw (L"JDFException null vElementIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
	vElementIterator vElementIterator::operator ++(int){
		if(vElementVector==0) 
			throw (L"JDFException null vElementIterator");
		iPos++;
		return *this;
	}
	////////////////////////////////////////////////////////////////////////
		
	const vElementIterator* vElementIterator::operator->() const{
		return (&*this); 
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vElementIterator::operator!=(const vElementIterator & other) const{
		return (vElementVector!=other.vElementVector)||(iPos!=other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vElementIterator::operator==(const vElementIterator & other) const{
		return (vElementVector==other.vElementVector)&&(iPos==other.iPos);
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vElementIterator::operator>(const vElementIterator & other) const{
		bool result = (vElementVector==other.vElementVector);
		if (result)
			result = (iPos > other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vElementIterator::operator<(const vElementIterator & other) const{
		bool result = (vElementVector==other.vElementVector);
		if (result)
			result = (iPos<other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////
	
	bool vElementIterator::operator>=(const vElementIterator & other) const{
		bool result = (vElementVector==other.vElementVector);
		if (result)
			result = (iPos >= other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	
	bool vElementIterator::operator<=(const vElementIterator & other) const{
		bool result = (vElementVector==other.vElementVector);
		if (result)
			result = (iPos<=other.iPos);
		return result;
	}
	////////////////////////////////////////////////////////////////////////	
	vElement::reference vElementIterator::operator *(){
		return ((vElementBase*)vElementVector)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	vElement::const_reference vElementIterator::operator *() const{
		return ((vElementBase*)vElementVector)->at(iPos);
	}
	///////////////////////////////////////////////////////////////////////
	bool vElementIterator::hasNext() const
	{
		int siz = ((vElementBase*)vElementVector)->size();
		if (iPos < siz)
			return true;
		else 
			return false;
	}
	///////////////////////////////////////////////////////////////////////
	KElement vElementIterator::next()
	{
		if (hasNext())
		{
			iPos++;
			return ((vElementBase*)vElementVector)->at(iPos-1);
		}
		else
			throw (L"vElementIterator: no such element");
		return KElement::DefKElement;
	}


}
