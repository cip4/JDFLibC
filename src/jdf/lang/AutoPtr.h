/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
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

#ifndef I_JDF_AUTOPTR_H
#define I_JDF_AUTOPTR_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <xercesc/util/PlatformUtils.hpp>
#include <jdf/lang/JDFToolsDefs.h>


XERCES_CPP_NAMESPACE_USE

namespace JDF
{
/**
 * Helper class for AutoPtr
 *
 * @author nverbove     
 * @internal
 */
template <class T> class AutoEntity
{
public:
	/**
	 * The reference counted object
	 */
	T*	RealPtr;

	/**
	 * The reference count for this object
	 */
	int		RefCount;

	/**
	 * If 1 ownership is set for the AutoPtr.
	 * If 0 the object has been released, and cannot be deallocated anymore.
	 */
	int		Owned;

	AutoEntity() : RealPtr(0), RefCount(1), Owned(1) { }

	~AutoEntity() { if (Owned) delete RealPtr; }
};

class JDFTOOLS_EXPORT AutoPtrAtomicOperation
{
public:

	static int atomicIncrement(int& location);
	static int atomicDecrement(int& location);
    static void* compareAndSwap
    (
                void**      toFill
        , const void* const newValue
        , const void* const toCompare
    );
};

/**
 * AutoPtr's are smart pointers; they use reference counting to ensure that there can be no memory leaks.
 * The cost is pointer reference overhead. 
 * <p>
 * The idea is that each AutoPtr pointing to the same object, 
 * allocated from the heap, points to a reference Counted template 
 * object <code>AutoEntity</code> which contains the pointer and the
 * reference count. 
 * <p>
 * Each copy construction or assignment increments the reference count,
 * each destruction decrements the reference count. When the
 * reference count becomes zero, the reference counted object is deleted.
 * @ingroup lang
 * @nosubgrouping
 *
 * @author nverbove    
 */


/**
 * AutoPtr's are smart pointers; they use reference counting to ensure that there can be no memory leaks.
 * The cost is pointer reference overhead. 
 * <p>
 * The idea is that each AutoPtr pointing to the same object, 
 * allocated from the heap, points to a reference Counted template 
 * object <code>AutoEntity</code> which contains the pointer and the
 * reference count. 
 * <p>
 * Each copy construction or assignment increments the reference count,
 * each destruction decrements the reference count. When the
 * reference count becomes zero, the reference counted object is deleted.
 * @ingroup lang
 * @nosubgrouping
 *
 * @author nverbove    
 */
template<class T> class AutoPtr
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates an AutoPtr object which points to the given object. 
	 * The reference count of this AutoPtr will be set to 1; if the object is not NULL;
	 * By defaault the AutoPtr points to a NULL pointer and the reference count is 0.
	 * 
	 * @param target an heap-allocated object; else NULL
	 */
	AutoPtr(T* target = 0);

	/**
	 * Creates an AutoPtr object which points to the same object as the given AutoPtr.. 
	 * The reference count of the shared object is incremented.
	 * 
	 * @param parent the handle from which to receive the reference-counted object
	 */
	AutoPtr(const AutoPtr<T>& parent);

/*@}*/ 

	/**
	 * Creates an AutoPtr object which points to the given reference-counted object.
	 * First, the AutoPtr will remove its reference from the reference-counted object
	 * it currently points to and delete it if the count becomes zero.
	 * Then it will create a handle to the given reference-counted object
	 * The reference count of the reference-counted object is incremented.
	 *
	 * @param parent the handle from which to receive the reference-counted object
	 */
	AutoPtr<T>&	operator=(const AutoPtr<T>& parent);

	/**
	 * Creates an AutoPtr object which points to the given object.
	 * First, the AutoPtr will remove its reference from the reference-counted object
	 * it currently points to and delete it if the count becomes zero.
	 * Then it will create a handle to the given object.
	 * The reference count of this AutoPtr will be set to 1.
	 *
	 * @param ptr an heap-allocated object.
	 */
	AutoPtr<T>&	operator=(T* ptr);

	/**
	 * Destructs the handle object.
	 * The destructor will remove its reference from the reference-counted object and
	 * delete the object if the reference count drops to 0.
	 */
	~AutoPtr();

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Dereference operator to invoke a method on the referenced object.
	 */
	T*			operator->() const;

	/**
	 * Gets a reference to the referenced object.
	 */

	T&			operator *() const;

	/**
	 * Gets a reference to the object using the array index.
	 * use this when you want to index an array using an AutoPtr.
	 * 
	 * @param x index position in the array
	 */

	T&			operator [](int x) const;

	/**
	 * Determines if the object referenced by the handle is invalid, i.e. that it is nil.
	 *
	 * @return true if the object is not valid, false otherwise
	 */

	bool			operator !() const;

	/**
	 * Determines if the object referenced by the handle is valid, i.e. that it is not nil.
	 *
	 * @return true if the object is valid, false otherwise
	 */

    operator         bool() const;

	bool			operator ==(const T* const ptr) const;
	bool			operator !=(const T* const ptr) const;

	/**
	 * Test whether this <code>AutoPtr</code> references the same reference-counted object as the given <code>AutoPtr</code>.
	 *
	 * @return returns true if rhs references the same object as this, false otherwise.
	 * @param rhs the handle to compare with.
	 */

	bool			operator ==(const AutoPtr<T>& rhs) const;

	/**
	 * Test whether this <code>AutoPtr</code> references another reference-counted object as the given <code>AutoPtr</code>.
	 *
	 * @return returns true if rhs references a different object as this, false otherwise.
	 * @param rhs the handle to compare with
	 */

	bool			operator !=(const AutoPtr<T>& rhs) const;

	/**
	 * Gets a pointer to the referenced object.
	 * The reference count is not decremented.
	 *
	 * @return a reference to the referenced object.
	 */

	T*			get() const;

	/**
	 * If this AutoPtr holds an object, it will be released and the ownership is transfered to the caller.
	 * Any other AutoPtr that references this object cannot delete it anymore. 
	 *
	 * @return the reference counted object.
	 */

	T*			release();

private:

	AutoEntity<T>* SharedItem;
};

/***********************************************
 * implementation
 ***********************************************/

template <class T> T& AutoPtr<T>::operator[](int x) const
{
	return SharedItem->RealPtr[x];
}

template <class T> AutoPtr<T>::AutoPtr(T* ptr) : SharedItem(new AutoEntity<T>)
{
	AutoPtrAtomicOperation::compareAndSwap((void **)&SharedItem->RealPtr, ptr,SharedItem->RealPtr);
}

template <class T> AutoPtr<T>::AutoPtr(const AutoPtr<T>& parent) :
	SharedItem(parent.SharedItem)
{
	atomicIncrement(SharedItem->RefCount);
}

template <class T> AutoPtr<T>::~AutoPtr()
{
	if(!AutoPtrAtomicOperation::atomicDecrement(SharedItem->RefCount))
	{
		delete SharedItem;
		SharedItem = 0;
	}
}

template <class T> AutoPtr<T>& AutoPtr<T>::operator=(const AutoPtr<T>& parent)
{
	if (SharedItem == parent.SharedItem)
		return *this;

	if(!AutoPtrAtomicOperation::atomicDecrement(SharedItem->RefCount))
	{
		delete SharedItem;
		SharedItem = 0;
	}

	AutoPtrAtomicOperation::compareAndSwap((void **)&SharedItem, parent.SharedItem,SharedItem);
	AutoPtrAtomicOperation::atomicIncrement(SharedItem->RefCount);

	return *this;
}

template <class T> AutoPtr<T>& AutoPtr<T>::operator=(T* ptr)
{
	if (SharedItem->RealPtr == ptr)
		return *this;

	if(!AutoPtrAtomicOperation::atomicDecrement(SharedItem->RefCount))
	{
		delete SharedItem;
		SharedItem = 0;
	}

	AutoPtrAtomicOperation::compareAndSwap((void **)&SharedItem, new AutoEntity<T>,SharedItem);
	AutoPtrAtomicOperation::compareAndSwap((void **)&SharedItem->RealPtr, ptr,SharedItem->RealPtr);
	return *this;
}

template <class T> T* AutoPtr<T>::operator ->() const
{
	return SharedItem->RealPtr;
}

template <class T> T* AutoPtr<T>::get() const
{
	return SharedItem->RealPtr;
}

template <class T> bool AutoPtr<T>::operator !() const
{
	return (SharedItem->RealPtr == 0);
}

template <class T> AutoPtr<T>::operator bool() const
{
	return (SharedItem->RealPtr != 0);
}

template <class T> T& AutoPtr<T>::operator*() const
{
	return *SharedItem->RealPtr;
}

template <class T> bool AutoPtr<T>::operator ==(const T* const ptr) const
{
	return (SharedItem->RealPtr == ptr);
}

template <class T> bool AutoPtr<T>::operator !=(const T* const ptr) const
{
	return (SharedItem->RealPtr != ptr);
}

template <class T> bool AutoPtr<T>::operator ==(const AutoPtr<T>& rhs) const
{
	return (SharedItem->RealPtr == rhs.SharedItem->RealPtr);
}

template <class T> bool AutoPtr<T>::operator !=(const AutoPtr<T>& rhs) const
{
	return (SharedItem->RealPtr != rhs.SharedItem->RealPtr);
}

template <class T> T* AutoPtr<T>::release()
{
	int* tmp = &SharedItem->Owned;
	XMLPlatformUtils::compareAndSwap((void **)&tmp, 0,tmp);
	return SharedItem->RealPtr;
}

} // namespace JDF

#endif /* I_JDF_AUTOPTR_H */


/* end of file */

