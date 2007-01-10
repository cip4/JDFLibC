/*
* The CIP4 Software License, Version 0.1
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

#ifndef I_JDF_HASHMAP_H
#define I_JDF_HASHMAP_H

#include "slist.h"

#include <utility>

#ifdef __APPLE_CC__	//AXEL20020906
#include<iterator.h>
#endif

#if ((__GNUC__ >= 3) || defined(__MWERKS__))
namespace std
{
	template <class _Tp, class _Distance>
		struct bidirectional_iterator : public iterator<bidirectional_iterator_tag, _Tp, _Distance, _Tp*, _Tp&> {};
}
#endif

// hash map class
namespace JDF
{
/**
* The Hashmap looks like a stl map but uses hashing internally to maintain
* the map.
* A Hash function is required for the hashing.
* @ingroup util
	*/
	template<class Key, class T, class hashFun>
		class hmap
	{
 public:
	 typedef size_t size_type;
	 typedef std::pair<const Key,T> value_type;
	 
	 // define more readable denominations
	 typedef slist<value_type> list_type;
	 typedef std::vector<list_type*> vector_type;
	 
	 /* The template parameter Key stands for the type of the key; T
	 stands for the class of data associated to a key; and hashFun
	 is the placeholder for the data type of the function objects
	 used for address calculation. Below, a function object for
	 address calculation is proposed, but any other one can be used
	 as well. In analogy to map, value_type is the type of the
	 elements that are stored in an HMap object. value_type is a
	 pair consisting of a constant key and the associated data. */
	 
	 class iterator;
	 // maintain compatibility with the STL:
	 typedef iterator const_iterator;
	 friend class iterator;
	 
	 /* The nested class iterator closely cooperates with HMap, so that
	 both are mutually declared as friend. iterator is only supposed
	 to allow forward traversal and therefore inherits
	 forward_iterator from the standard class. An iterator object
	 allows you to visit all elements of an HMap object one after
	 the other. Neither an order nor a sorting is defined for the
	 elements. The visiting order of the iterator is given by the
	 implicit data structure (see below, operator++()). */
	 
	 class iterator : public
#ifdef __APPLE_CC__	//AXEL20020906
		 bidirectional_iterator<value_type, size_type>
#elif defined(_CPPLIB_VER) && ! defined(STLPORT)  // Native VC7 STL
		 std:: _Bidit<value_type, size_type, value_type, value_type>
#elif (__GNUC__ >= 3)
		 std::bidirectional_iterator
#elif defined(__MWERKS__) || defined(STLPORT)
		 std::bidirectional_iterator<value_type, size_type>
# else
		 std:: _Bidit<value_type, size_type>
#endif
	 {
		 friend class hmap<Key, T, hashFun>;
	 private:
		 typename list_type::iterator current;
		 size_type Address;
		 const vector_type *pVec;
		 
	 public:
		 iterator()
			 : current(list_type::iterator()),
			 pVec(0)
		 {}
		 
		 iterator(typename list_type::iterator LI,
			 size_type A,  const vector_type *C)
			 : current(LI), Address(A), pVec(C)
		 {}
		 
		 /* The following operators allow you to check an HMap iterator
		 in the condition part of if or while as to whether it is at
		 all defined: */
		 
		 operator const void* () const
		 {
			 return pVec;
		 }  
		 
		 bool operator!() const
		 {
			 return pVec == 0;
		 }
		 
		 /* The operator for dereferencing occurs both in the const
		 variation and in the non-const variation. Thus,
		 dereferencing of an undefined iterator is punished with a
		 program abort, which is a clear message to you to check the
		 program that uses the iterator. */
		 
		 const value_type& operator*() const
		 {
			 assert(pVec);
			 return *current;
		 }  
		 
		 value_type& operator*()
		 {
			 assert(pVec);
			 return *current;
		 }
		 
		 /* The non-const variation is required to be able to modify
		 data independently from the key. Modification of the key
		 must be excluded because it requires a new address
		 calculation. Constancy is guaranteed by the const
		 declaration in the type definition of value_type.
		 
		   How does the HMap iterator move from one element to the
		   other with operator++()? First, current is incremented:
         */
		 
		 iterator& operator++()
		 {
			 ++current;
			 
			 /* If after this, current points to a list element, a
             reference to the iterator is returned (see below: return
             *this. Otherwise, the end of the list is reached. */
			 
			 if(current == (*pVec)[Address]->end())
			 {
				 
			 /* At this point, one address after the other is checked
			 in the vector, until either a list entry is found or
			 the end of the vector is reached. In the latter case,
			 the iterator becomes invalid, because it can only move
			 forward. In order to exclude further use, pVec is set
				 to 0: */
				 
				 while(++Address < pVec->size())
					 if((*pVec)[Address])
					 {
						 current = (*pVec)[Address]->begin();
						 break;
					 }
					 
					 if(Address == pVec->size()) // end of vector reached
						 pVec = 0;
			 }
			 return *this;
		 }
		 
		 iterator operator++(int)
		 {
			 iterator temp = *this;
			 operator++();
			 return temp;
		 }
		 
		 /* The last two methods compare two HMap iterators. Two
		 undefined or invalidated iterators are always considered as
equal: */
		 
		 bool operator==(const iterator& x) const
		 {
			 return current == x.current
				 || !pVec && !x.pVec;
		 }  
		 
		 bool operator!=(const iterator& x) const
		 {
			 return !operator==(x);
		 }
    }; // iterator
	
	   /* With this, the nested class iterator is concluded, so
       that now the data and methods of the HMap class can follow:*/
  private:
	  vector_type v;
	  hashFun hf;
	  size_type Count;
	  
	  /* Count is the number of stored pairs of keys and data, v is the
	  vector whose elements are pointers to singly linked lists, and
	  hf is the function object used for calculation of the hash
	  address. */
	  
	  void construct(const hmap& S)
	  {
		  hf = S.hf;
		  v = vector_type(S.v.size(),0);
		  Count = 0;
		  
		  // begin(), end(), insert(): see below
		  iterator t = S.begin();
		  while(t != S.end())
			  insert(*t++);
	  }
	  
	  /* The construct() function is an auxiliary function which is
	  called both in the copy constructor and in the assignment
	  operator. It constructs an HMap object out of another one and
	  has been extracted in order to avoid code duplication in copy
	  constructor and assignment operator. */
	  
  public:
	  iterator begin() const
	  {
		  size_type adr = 0;
		  while(adr < v.size())
		  {
			  if(!v[adr])    // found nothing?
				  adr++;       // continue search
			  else
				  return iterator(v[adr]->begin(), adr, &v);
		  }
		  return iterator();
	  }
	  
	  iterator end() const
	  {
		  return iterator();
	  }
	  
	  hmap(hashFun f = hashFun())
		  : v(f.tableSize(),0), hf(f), Count(0)
	  {}
	  
	  hmap(const hmap& S)
	  {
		  construct(S);
	  }
	  
	  ~hmap()
	  {
		  clear();                       // see below
		  v.clear();
	  }
	  
	  hmap& operator=(const hmap& S)
	  {
		  if(this != &S)
		  {
			  clear();
			  construct(S);
		  }
		  return *this;
	  }
	  
	  /* clear() uses delete to call the destructor of each list
	  referred to by a vector element. Subsequently, the vector
	  element is marked as unoccupied.*/
	  
	  void clear()
	  {
		  for(size_t i = 0; i < v.size(); i++)
			  if(v[i])                   // does list exist?
			  {
				  v[i]->clear();
				  delete v[i];
				  v[i] = 0;
			  }
			  Count = 0;
	  }
	  
	  /* In the following find() and insert() functions, the sought
	  address within the vector v is calculated directly by means of
	  the hash function object. If the vector element contains a
	  pointer to a list, the list is searched in find() by means of
	  the list iterator temp until an element with the correct key is
	  found or the list has been completely processed: */
	  
	  iterator find(const Key& k) const
	  {
		  size_type address = hf(k);     // calculate address
		  
		  
		  if(!v[address])
			  return iterator();          // not existent
		  typename list_type::iterator temp =  v[address]->begin();
		  
		  // find k in the list
		  while(temp != v[address]->end())
			  if((*temp).first == k)
				  return iterator(temp,address,&v); //found
			  else ++temp;
			  
			  return iterator();
	  }
	  
	  /* A map stores pairs of keys and associated data, where the first
	  element (first) is the key and the second element ( second)
	  contains the data. find() returns an iterator which can be
	  interpreted as a pointer to a pair. In order to obtain the data
	  belonging to a key, the index operator can be called with the
	  key as argument: */
	  
	  T& operator[](const Key& k)
	  {
		  iterator _p = insert(value_type(k, T())).first;
		  return ((*_p).second);
	  }
	  
	  /* If the key does not exist, that is, if find() returns an end
	  iterator, a run time error occurs while dereferencing! (See the
	  dereferencing operator).
	  As in the STL, insert() returns a pair whose first part
	  consists of the iterator that points to the found position. The
	  second part indicates whether the insertion has taken place or
	  not. */
	  
	  std::pair<iterator, bool> insert(const value_type& P)
	  {
		  iterator temp = find(P.first);
		  bool inserted = false;
		  
		  if(!temp) // not present
		  {
			  size_type address = hf(P.first);
			  if(!v[address])
				  v[address] = new list_type;
			  v[address]->push_front(P);
			  temp = find(P.first); // redefine temp
			  inserted = true;
			  Count++;
		  }
		  return std::make_pair(temp, inserted);
	  }
	  
	  /* After the insertion, temp is redefined, because the iterator at
	  first does not point to an existing element. The known
	  auxiliary function makepair() generates a pair object to be
	  returned. */
	  
	  void erase(iterator q)
	  { 
	  /* If the iterator is defined at all, the element function
	  erase() of the associated list is called. Subsequently, the
	  list is deleted, provided it is now empty, and the vector
		  element to which the list is attached, is set to 0. */
		  
		  if(q.pVec)             // defined?
		  {
			  v[q.Address]->erase(q.current);
			  
			  if(v[q.Address]->empty())
			  {
				  delete v[q.Address];
				  v[q.Address] = 0;
			  }
			  Count--;
		  }
	  }
	  
	  /* Sometimes, one would probably like to delete all elements of a
	  map that have a given key. In an HMap, this can at most be one
	  element, but in an HMultimap, several elements might be
	  affected. */
	  
	  // suitable for HMap and HMultimap
	  size_type erase(const Key& k)
	  {
		  size_type deleted_elements = 0; // Count
		  // calculate address
		  size_type address = hf(k);
		  if(!v[address])
			  return 0;         // not present
		  
		  typename list_type::iterator temp =  v[address]->begin();
		  
		  /* In the following loop, the list is searched. An iterator
          called pos is used to remember the current position for the
          deletion itself. */
		  
		  while(temp != v[address]->end())
		  {
			  if((*temp).first == k)
			  {
				  typename list_type::iterator pos = temp++;
				  
				  v[address]->erase(pos);
				  // pos is now undefined
				  
				  Count--;
				  deleted_elements++;
			  }
			  else ++temp;
		  }
		  
		  /* The temporary iterator temp is advanced in both branches of
          the if instruction. The operation ++ cannot be extracted in
          order to save the else, because temp would then be identical
          with pos which is undefined after the deletion, and a
          defined ++ operation would no longer be possible. */
		  
		  // delete hash table entry if needed
		  if(v[address]->empty())
		  {
			  delete v[address];
			  v[address] = 0;
		  }
		  return deleted_elements;
	  }
	  
	  /* We present here a couple of very simple methods. As opposed to
	  other containers, max_size() does not indicate the maximum
	  number of elements that can be stored in an HMap container,
	  which is only limited by the capacity of the lists, but the
	  number of available hash table entries. This information is
	  more sensible, because the efficiency of an HMap depends on the
	  occupation range alpha, assuming a good hash function. The
	  occupation rate can easily be determined: alpha =
	  size()/max_size(). */
	  
	  size_type size()     const { return Count;}
	  
	  size_type max_size() const { return v.size();}
	  
	  bool empty()         const { return Count == 0;}
	  
	  void swap(hmap& s)
	  {
		  v.swap(s.v);
		  std::swap(Count, s.Count);
		  std::swap(hf, s.hf);        
	  }
};

}

#endif   // File hmap

