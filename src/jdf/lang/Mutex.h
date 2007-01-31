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

/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_MUTEX_H
#define I_JDF_MUTEX_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include "JDFToolsDefs.h"

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


/******************************************************************************
 *	Classes
 ******************************************************************************/ 

/**
 * This class can be used to establish a critical section.
 * The <code>Mutex</code> class provides a simple and efficient mechanism to serialize access
 * to a shared resource. Similar in functionality to a binary semaphore.
 * A <code>Mutex</code> is no-reentrant, meaning a thread that owns the mutex cannot lock the
 * mutex again. 
 * <p>
 * You will almost almost always use this class with the <code>Synchronized</code> class
 * to provide locking.
 * <p>
 * The following example demonstrates the use of <code>Mutex</code> to
 * synchronize the methods of a class.
 * <p>
 * @code
 * class Account
 * {
 * public:
 *   bool deduct(float t)
 *   {
 *      Synchronized sync(m);
 *      if (t<=total)
 *      {
 *        total -= t;
 *        return true;
 *      }
 *      return false;
 *   }
 * private:
 *    Mutex m;
 * };
 * @endcode
 * <p>
 * The synchronized object sync take a lock on the mutex and releases it when it is
 * destructed. The deduct method is now synchonized. If we wouldn't lock this 
 * method two different thread could enter the deduct method at 'the same time'.
 * When performing the statement <code>total-=t</code>, a context-switch might happen. 
 * One thread could overwrite the changes to the account status made by another thread.
 * Therefore, we have to make changes to the account status <i>Atomic</i>.
 * @ingroup lang
 * @nosubgrouping
 *
 * @author nverbove  
 * @see Synchronized
 */

class JDFTOOLS_EXPORT Mutex
{
public:

/** 
 * @name Constructors
 */
/*@{*/

 	 /**
 	  * Create a new Mutex object.
 	  */

 	 Mutex();

/*@}*/ 

	~Mutex();

	/**
	 * Lock this Mutex object.
	 * <p>
	 * If the mutex is currently locked by another thread then the thread will be 
	 * suspended until the mutex is unlocked.
	 * If the current owner of the mutex attempts to re-lock the mutex a deadlock will result.
	 * @see Mutex#unlock() 
	 */

	void lock();

	/**
	 * This method is called by the owner of the Mutex to release it. 
	 * <p>
	 * The mutex must be locked and the calling thread must be the one that last locked 
	 * the mutex. If these conditions are not met, undefined behavior will result.
	 * @see Mutex#lock()
	 */

	void unlock();

private:

	//
	// Hide copy constructor and assignment operator.
	//
	Mutex(const Mutex&);
	void operator=(const Mutex&);

	///////////////////////////////////////////////////////////////////////////
	// Private Instance Variables
	///////////////////////////////////////////////////////////////////////////

	void* m_Mutex;
};


/******************************************************************************
*	Prototypes
******************************************************************************/ 

/******************************************************************************
*	Implementation
******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_MUTEX_H */


/* end of file */

