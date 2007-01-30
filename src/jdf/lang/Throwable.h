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

#ifndef I_JDF_THROWABLE_H
#define I_JDF_THROWABLE_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 

#include <jdf/lang/JDFToolsDefs.h>
#include <jdf/lang/WString.h>

#include <jdf/util/Unicode.h>


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
 * The Throwable class is the superclass of all errors and exceptions in JDF. 
 * Only objects that are instances of this class (or of one of its subclasses) are 
 * thrown in JDF. 
 * <p>
 * Instances of two subclasses, Error and Exception, are 
 * conventionally used to indicate that exceptional situations have occurred. 
 * Typically, these instances are freshly created in the context of the exceptional
 * situation.
 * <p>
 * By convention, class Throwable and its subclasses have two constructors,
 * one that takes no arguments and one that takes a WString argument that 
 * can be used to produce an error message. 
 * @ingroup lang
 * @nosubgrouping
 *
 * @author nverbove     
 */


class JDFTOOLS_EXPORT Throwable : public std::exception
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Constructs a new Throwable with an empty error message string. 
	 * Also, the method <code>fillInStackTrace()</code> is called for this object.
	 */

	Throwable() {}

	/**
	 * Constructs a new Throwable with the specified error message.
	 * Also, the method <code>fillInStackTrace()</code> is called for this object.
	 *
	 * @param  message the error message. The error message is saved for later retrieval by the <code>getMessage</code> method.
	 */

	Throwable(const WString& message) : mMessage(message) {}

	/**
	 * Constructs a new Throwable from an existing Throwable object.
	 * The new Throwable is constructed with the error message and stack trace from the existing <code>Throwable</code>.
	 *
	 * @param e the Throwable object that will be copied.  
	 */

	Throwable(const Throwable& e)  : mMessage(e.mMessage) {}

/*@}*/ 

	/**
	 * Assign a Throwable object to this Throwable object.
	 * The assigned throwable will get the error message from the argument Throwable.
	 *
	 * @param e the Throwable Object that will be for assignment.
	 */

    Throwable& operator=(const Throwable& e)
    {
		if(this != &e)
		{
			mMessage = e.mMessage;

		}
		return *this;
    }

	virtual ~Throwable()  throw() {}

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Returns the errort message string of this Throwable object.
	 *
	 * @return the error message string of this Throwable object if it was created with an error message string; or an empty if it was created with no error message.
	 */
	virtual WString getMessage() const { return mMessage; }

	/**
	 * Returns the errort message string of this Throwable object as a char*
	 * note that it is not threadsafe...
	 *
	 * @return the error message string of this Throwable object if it was created with an error message string; or an empty if it was created with no error message.
	 */
	virtual const char* what() const throw();

	/**
	 * Creates a localized description of this Throwable. 
	 * Subclasses may override this method in order to produce a 
	 * locale-specific message. For subclasses that do not override 
	 * this method, the default implementation returns the same result
	 * as <code>getMessage()</code>.
	 */

	virtual WString getLocalizedMessage() const;

	/**
	 * Returns a short description of this throwable object.
	 * If this Throwable object was created
	 * with an error message string, then the result is the concatenation of three 
     * strings: 
	 * <UL>
	 *	<LI>The name of the actual class of this object by calling getType()
	 *	<LI>": " (a colon and a space) 
	 *	<LI>The result of the getMessage()
	 *	method for this object
	 *  </LI>
	 * </UL>
	 * If this Throwable object was created with no error message string,
	 * then the name of the actual class of this object is returned.
	 * 
	 * @return a string representation of this Throwable
	 */

	virtual WString toString() const;

	/**
	 * returns the name of this Throwable object.
	 * Derived classes should overload this method and return their name of the class.
	 *
	 * @return name of this Throwable object.
	 */

	virtual const JDFCh* getType() const { return Unicode::THROWABLE_NAME; }

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The error message associated with this Throwable object.
	 */

	WString mMessage;
};

/**
 * The class Exception and its subclasses are a form of Throwable that indicates
 * conditions that a reasonable application might want to catch. 
 * @ingroup lang
 *
 * @author nverbove    
 */

class JDFTOOLS_EXPORT Exception : public Throwable
{
public:

	Exception(long err = 0) : Throwable(),mError(err) {}
	Exception(const WString& s, long err = 0) : Throwable(s), mError(err) {}

	Exception(const Exception& e) :
		Throwable(e.mMessage),
		mError(e.mError)
	{
	}

	virtual ~Exception() throw() {}

    Exception& operator=(const Exception& e)
    {
		if(this != &e)
		{
			mError   = e.mError;
			mMessage = e.mMessage;
		}
		return *this;
    }

    long getError() const
    {
		return mError;
    }

	virtual const JDFCh* getType() const { return Unicode::EXCEPTION_NAME; }

protected:

    long mError;
};

/**
 * @ingroup lang
 */
class JDFTOOLS_EXPORT Error : public Throwable
{
public:

	/**
	 * Constructs a Error with no detail message.
	 */

	Error(long err =0) : Throwable() { mErrorCode = err; }
	Error(const WString& s, long err = 0)  : Throwable(s) {mErrorCode = err;}

    Error& operator=(const Error& e)
    {
		if(this != &e)
		{
			mMessage    = e.mMessage;
			mErrorCode  = e.mErrorCode;
		}
		return *this;
    }

	virtual ~Error() throw() {}
	virtual const JDFCh* getType() const { return Unicode::ERROR_NAME; }
	virtual long getError() const { return mErrorCode; }

protected:

	int mErrorCode;
};

/**
 * RuntimeException is the superclass of those exceptions
 * that can be thrown during the normal operation.
 * @ingroup lang
 *
 * @author nverbove     
 */

class JDFTOOLS_EXPORT RuntimeException : public Exception
{
public:

	/**
	 * Constructs a RuntimeException with no detail message.
	 */

	RuntimeException() : Exception() {}
	RuntimeException(const WString& s)  : Exception(s) {}

	virtual ~RuntimeException() throw() {}
	virtual const JDFCh* getType() const { return Unicode::RUNTIMEEXCEPTION_NAME; }
};


/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // JDF

#endif /* I_JDF_THROWABLE_H */


/* end of file */
