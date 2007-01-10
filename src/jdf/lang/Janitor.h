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

/************************************************************************
* 
* Revision history:
*
* 010903 FB added conveninence methods get(), release() and operator->()
*
* 
* Description:
*
*
******************************************************************************/

#ifndef I_JDF_JANITOR_H
#define I_JDF_JANITOR_H


/******************************************************************************
*	Includes
******************************************************************************/ 

#include "JDFToolsDefs.h"

namespace JDF
{
/**
* Janitor is a janitorial class that is used to manage scope based allocation 
* of non-array data, i.e. either single fundamental values, objects, or structures.
* The heap janitor will insure that the allocated memory gets freed upon any exit
* from the current scope (either by return or by exception.) 
* <p>
* In order to do the right thing when the destructor is called, Janitor is a 
* template class. This allows it to know the type of the thing to be deleted, 
* which is important if it is an object instead of a fundamental type or structure. 
* <p>
* For array allocations (e.g. arrays of chars, ints, structures, objects, etc...)
* use the ArrayJanitor class. 
* <p>
* Here is a simple example of TJanitor to clean up a locally allocated object. 
* This is not a very good exampe, since the object didn't need to really be 
* dynamically allocated in this simple scenario, but you get the idea. 
* @code
* void Foo::DoSomeWork()
*{
*	  // Allocate a structure
*    MyClass* tmp = new MyClass();
*    //
*    //  Put a janitor on it. Note that it takes a pointer
*    //  because it retains a reference to the object.
*    //
*    Janitor<MyClass> janMyClass(tmp);
*   // Do some work
*    ....
*    //
*    //  Any way we get out of here now, tmp will be
*    //  destructed. This is much nicer than having to do
*    //  try/catch blocks ain't it?
*    //
*}
* @endcode
* @ingroup lang
* @nosubgrouping
* @see ArrayJanitor
	*/
	template <class T>
		class Janitor
	{
public:
/** 
* @name Constructors
	*/
	/*@{*/
	
	/**
	* Create a Janitor for the given object.
	* The Janitor takes ownership for the given object and deletes it when
	* it goes out of scope.
	* @param objToDelete The thing that is to be deleted. It is of type T, which is the template instantiation type. 
	*/
	Janitor(T* const objToDelete) : fData(objToDelete) { }
	/*@}*/ 
	
	/**
	* Deletes the object.
	*/
    ~Janitor() { delete fData; }
	
	/**
	* This method will release the pointer so that the janitor destructor will not
	* delete it. This allows you to use a janitor until you are sure that the 
	* allocated data is in safe hands. Once its safely stored away with someone 
	* who is responsible for it, just call Orphan() to tell the janitor to let 
	* it go. 
	*/
    void orphan() { fData = 0; }
	
	/**
	* Returns a pointer to the object.
	*/
    T* get() const { 
		return fData; 
	}
	
	/**
	* This method will release the pointer, so that the jnitor destructor will not
	* delete it, then returns the stored pointer.
	*/
    T* release() { 
		T* tmpData = fData; 
		fData = 0; 
		return tmpData; 
	}
	
	/**
	* Returns a pointer to the object.
	*/
    T* operator->() const throw() { 
		return get(); 
	}
	
private :
    Janitor();
    Janitor(const Janitor<T>&);
    Janitor& operator=(const Janitor&);
	
	/**
	* This is the pointer to the object or structure that must be
	* destroyed when this object is destroyed.
	*/
    T* fData;
	};
	
	/**
	* ArrayJanitor is a janitorial class that is used to manage scope based allocation of array data.
	* The array janitor will insure that the allocated memory gets freed upon 
	* any exit from the current scope (either by return or by exception.) 
	* <p>
	* In order to do the right thing when the destructor is called, ArrayJanitor is 
	* a template class. This allows it to know the type of the things to be deleted,
	* which is important if it is an array of objects instead of fundamental types or
	* structures. The code generated for each instance is extremely trivial so
	* use them liberally because they are a key to robust applications. 
	* <p>
	* The difference with the Janitor class is that the ArrayJanitor will call the
	* delete[] operator instead of the delete operator on the object.
	* <p>
	* For non-array allocations (e.g. single chars, ints, structures, objects, etc...) 
	* use the Janitor class. 
	* <p>
	* Here is a simple example of ArrayJanitor to clean up a locally allocated object. 
	* @code	
	*void Foo::DoSomeWork()
	*{
	*    // Allocate a temp byte buffer
	*    char* buf = new char[512];
	*    // Put a janitor on it.
	*    ArrayJanitor<char> janBuf(buf);
	*    // Do some work
	*    ....
	*    //
	*    //  Any way we get out of here now, buf will be
	*    //  destructed. This is much nicer than having to do
	*    //  try/catch blocks ain't it?
	*    //
	*}
	* @encode
	* <p>
	* Another scenario is to use a janitor to keep up with a buffer until 
	* initialization is complete and its stored away somewhere safe. 
	* At that point you want the janitor to give up control of the object, which is
	* done by the orphan() method, like this: 
	* @code
	*void Foo::DoSomeWork()
	*{
	*    // Allocate a temp byte buffer
	*    char* buf = new char[512];
	*    // Put a janitor on it.
	*    ArrayJanitor<char> janBuf(buf);
	*    // Do some work
	*    ....
	*    // Looks ok, so store the pointer and let it go
	*    __bufMember = buf;
	*    janBuf.orphan();
	* }
	* @endcode
	* @see Janitor
	*/
	
	template <class T> class ArrayJanitor
	{
public:
/**
*	Creates a ArrayJanitor that takes a pointer to the array allocated. 
* The destructor will delete the array unless it has been released via orphan(). 
* If its an array of objects, then the language will invoke the destructors
* of the objects, which is why its important that this class be a template type. 
*
* @param objToDelete The array that is to be deleted. It is of type T, which is the template instantiation type.  
	*/
    ArrayJanitor(T* const objToDelete) : fData(objToDelete) { }
	
	/**
	* This method will release the array so that the janitor destructor will 
	* not delete it. This allows you to use a janitor until you are sure that
	* the allocated data is in safe hands. Once its safely stored away with 
	* someone who is responsible for it, just call orphan() to tell the janitor 
	* to let it go. 
	*/
    ~ArrayJanitor() { delete[] fData; }
	
	/**
	* Release ownership of the array of objects.
	*/
    void orphan() { fData = 0; }
	
	/**
	* Returns a pointer to the object.
	*/
    T* get() const throw() { 
		return fData; 
	}
	
	/**
	* This method will release the pointer, so that the janitor destructor will not
	* delete it, then returns the stored pointer.
	*/
    T* release() throw() { 
		T* tmpData = fData; 
		fData = 0; 
		return tmpData; 
	}
	
#ifdef WIN32
// disable UDT warning caused template instantiation with simple types
#pragma warning (push)
#pragma warning (disable: 4284)
#endif
	/**
	* Returns a pointer to the object.
	*/
    T* operator->() const throw() { 
		return get(); 
	}
#ifdef WIN32
#pragma warning (pop)
#endif
	
private :
    ArrayJanitor();
    ArrayJanitor(const ArrayJanitor<T>&);
    ArrayJanitor& operator=(const ArrayJanitor&);
	
	/**
	* This is the pointer to the array of objects that must be
	* destroyed when this object is destroyed.
	*/
    T* fData;
	};
	
} // namespace JDF

#endif /* I_JDF_JANITOR_H */

