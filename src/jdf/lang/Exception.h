/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2005 The International Cooperation for the Integration of 
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

#ifndef I_JDF_LANGEXCEPTION_H
#define I_JDF_LANGEXCEPTION_H

/******************************************************************************
*	Includes
******************************************************************************/ 

#include "JDFToolsDefs.h"
#include "Throwable.h"

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
	* Thrown to indicate that a method has been passed an illegal or inappropriate argument. 
	* @ingroup langexceptions
	*
	* @author nverbove
	*/

	class JDFTOOLS_EXPORT IllegalArgumentException : public RuntimeException
	{
	public:

		/**
		* Constructs an IllegalArgumentException with no detail message.
		*/

		IllegalArgumentException() : RuntimeException() {}

		/**
		* Constructs an IllegalArgumentException with the specified detail message.
		*
		* @param s the detail message.
		*/

		IllegalArgumentException(const WString& s) : RuntimeException(s) {}
		virtual ~IllegalArgumentException() throw(){}

		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::ILLEGALARGUMENTEXCEPTION_NAME; }
	};

	/**
	* Thrown when an application attempts to use <code>null</code> in a case where an object is
	* required. 
	* <p>
	* Applications should throw instances of this class to indicate other illegal uses of 
	* the <code>null</code> object. 
	* @ingroup langexceptions
	*
	* @author nverbove     
	*/

	class JDFTOOLS_EXPORT NullPointerException : public RuntimeException
	{
	public:

		/**
		* Constructs a NullPointerException with no detail message.
		*/

		NullPointerException() : RuntimeException() {}

		/**
		* Constructs a NullPointerException with the specified detail message.
		*
		* @param s the detail message.
		*/

		NullPointerException(const WString& s) : RuntimeException(s) {}
		virtual ~NullPointerException()throw() {}

		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::NULLPOINTEREXCEPTION_NAME; }
	};

	/**
	* Thrown to indicate some unexpected internal error has occurred.
	* @ingroup langexceptions
	*/

	class JDFTOOLS_EXPORT InternalError : public Error
	{
	public:

		/**
		* Constructs a InternalError with no detail message.
		*/

		InternalError() : Error() {}

		/**
		* Constructs a InternalError with the specified detail message.
		*
		* @param s the detail message.
		*/

		InternalError(const WString& s) : Error(s) {}
		virtual ~InternalError()throw() {}

		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::INTERNALERROR_NAME; }
	};


	/**
	* Thrown by JDF classes when failed to allocate an object because it is out of memory,
	* and no more memory could be made available.
	* @ingroup langexceptions
	*
	* @author nverbove     
	*/

	class JDFTOOLS_EXPORT OutOfMemoryError : public Error
	{
	public:

		/**
		* Constructs a OutOfMemoryError with no detail message.
		*/

		OutOfMemoryError() : Error() {}

		/**
		* Constructs a OutOfMemoryError with the specified detail message.
		*
		* @param s the detail message.
		*/

		OutOfMemoryError(const WString& s) : Error(s) {}
		virtual ~OutOfMemoryError()throw() {}

		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::OUTOFMEMORYERROR_NAME; }
	};

	/**
	* Thrown by JDF classes when failed to allocate an object because it is out of memory,
	* and no more memory could be made available.
	* @ingroup langexceptions
	*
	* @author nverbove     
	*/

	class JDFTOOLS_EXPORT IllegalAccessError : public Error
	{
	public:

		/**
		* Constructs a IllegalAccessError with no detail message.
		*/

		IllegalAccessError() : Error() {}

		/**
		* Constructs a IllegalAccessError with the specified detail message.
		*
		* @param s the detail message.
		*/

		IllegalAccessError(const WString& s) : Error(s) {}
		virtual ~IllegalAccessError() throw(){}

		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::ILLEGALACCESSERROR_NAME; }
	};

	/**
	* Signals that a method has been invoked at an illegal or inappropriate time. 
	* In other words, the application is not in an appropriate state for the requested operation. 
	* @ingroup langexceptions
	*
	* @author nverbove    
	*/

	class JDFTOOLS_EXPORT IllegalStateException : public RuntimeException
	{
	public:

		/**
		* Constructs an IllegalStateException with no detail message.
		*/

		IllegalStateException() : RuntimeException() {}

		/**
		* Constructs an IllegalStateException with the specified detail message.
		*
		* @param s the detail message.
		*/

		IllegalStateException(const WString& s) : RuntimeException(s) {}
		virtual ~IllegalStateException()throw() {}

		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::ILLEGALSTATEEXCEPTION_NAME; }
	};

	/**
	* Thrown to indicate that an index of some sort (such as to an array, to a string, or
	* to a vector) is out of range. 
	* <p>
	* Applications can subclass this class to indicate similar exceptions. 
	* @ingroup langexceptions
	*
	* @author nverbove     
	*/

	class JDFTOOLS_EXPORT IndexOutOfBoundsException : public RuntimeException
	{
	public:

		/**
		* Constructs an IndexOutOfBoundsException with no detail message.
		*/

		IndexOutOfBoundsException() : RuntimeException() {}

		/**
		* Constructs an IndexOutOfBoundsException with the specified detail message.
		*
		* @param s the detail message.
		*/

		IndexOutOfBoundsException(const WString& s) : RuntimeException(s) {} 
		virtual ~IndexOutOfBoundsException()throw() {}

		const JDFCh* getType() const { return Unicode::INDEXOUTOFBOUNDSEXCEPTION_NAME; }
	};

	/**
	* Thrown to indicate that an array has been accessed with an illegal index. 
	* The index is either negative or greater than or equal to the size of the array. 
	* @ingroup langexceptions
	*
	* @author nverbove     
	*/

	class JDFTOOLS_EXPORT ArrayIndexOutOfBoundsException : public IndexOutOfBoundsException
	{
	public:

		/**
		* Constructs an ArrayIndexOutOfBoundsException with no detail message.
		*/

		ArrayIndexOutOfBoundsException() : IndexOutOfBoundsException() {}

		/**
		* Constructs an ArrayIndexOutOfBoundsException with the specified detail message.
		*
		* @param s the detail message.
		*/

		ArrayIndexOutOfBoundsException(const WString& s) : IndexOutOfBoundsException(s) {} 
		virtual ~ArrayIndexOutOfBoundsException() throw(){}

		const JDFCh* getType() const { return Unicode::ARRAYINDEXOUTOFBOUNDSEXCEPTION_NAME; }
	};

	/**
	* @ingroup utilexceptions
	*/
	class JDFTOOLS_EXPORT NoSuchElementException : public RuntimeException
	{
	public:

		NoSuchElementException() : RuntimeException() {};
		NoSuchElementException(const WString& s) : RuntimeException(s) {}
		virtual ~NoSuchElementException() throw(){}
		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::NOSUCHELEMENTEXCEPTION_NAME; }
	};

	/**
	* @ingroup utilexceptions
	*/
	class JDFTOOLS_EXPORT PlatformUtilsException : public RuntimeException
	{
	public:

		PlatformUtilsException() : RuntimeException() {};
		PlatformUtilsException(const WString& s) : RuntimeException(s) {}
		virtual ~PlatformUtilsException() throw(){}
		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::PLATFORMUTILSEXCEPTION_NAME; }
	};

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
	* Signals that an I/O exception of some sort has occurred. 
	* This class is the general class of exceptions produced by failed or 
	* interrupted I/O operations. 
	*
	* @author nverbove     
	* @see InputStream
	* @see OutputStream
	* @ingroup ioexceptions
	*/

	class JDFTOOLS_EXPORT IOException : public Exception
	{
	public:

		///////////////////////////////////////////////////////////////////////////
		// Public Constructors
		///////////////////////////////////////////////////////////////////////////

		/**
		* Constructs an IOException with en empty error detail message.
		*/

		IOException(long err = 0) : Exception(err) {}

		/**
		* Constructs an IOException with the specified detail message.
		* The error message string s can later be retrieved by 
		* the <code>Throwable.getMessage()</code> method of class <code>Throwable</code>.
		*/

		IOException(const WString& s,long err = 0)  : Exception(s,err) {}

		virtual ~IOException() throw() {};

		///////////////////////////////////////////////////////////////////////////
		// Public Instance Methods
		///////////////////////////////////////////////////////////////////////////

		/**
		* IOException Identification type.
		* 
		* @return Returns IOException
		*/

		virtual const JDFCh* getType() const { return Unicode::IOEXCEPTION_NAME; }
	};

	/**
	* Signals that an I/O operation has been interrupted. 
	* An <code>InterruptedIOException</code> is thrown to indicate that an input or 
	* output transfer has been terminated because the thread performing it was terminated. 
	* The field <code>bytesTransferred</code> indicates how many bytes were successfully 
	* transferred before the interruption occurred. 
	*
	* @author nverbove   
	* @see InputStream
	* @see OutputStream
	* @ingroup ioexceptions
	*/

	class JDFTOOLS_EXPORT InterruptedIOException : public IOException
	{
	public:

		///////////////////////////////////////////////////////////////////////////
		// Public Constructors
		///////////////////////////////////////////////////////////////////////////

		/**
		* Constructs an IOException with en empty error detail message.
		*/

		InterruptedIOException(long err = 0) : IOException(err) {}

		/**
		* Constructs an IOException with the specified detail message.
		* The error message string s can later be retrieved by 
		* the <code>Throwable.getMessage()</code> method of class <code>Throwable</code>.
		*/

		InterruptedIOException(const WString& s,long err = 0)  : IOException(s,err) {}

		virtual ~InterruptedIOException()throw() {};

		///////////////////////////////////////////////////////////////////////////
		// Public Instance Methods
		///////////////////////////////////////////////////////////////////////////

		/**
		* InterruptedIOException identification type.
		* 
		* @return Returns InterruptedIOException
		*/

		virtual const JDFCh* getType() const { return Unicode::INTERRUPTEDIOEXCEPTION_NAME; }

		/**
		* Reports how many bytes had been transferred as part of the I/O operation before it was interrupted.
		*/

		int bytesTransferred;
	};

	/**
	* @ingroup ioexceptions
	*/
	class JDFTOOLS_EXPORT FileNotFoundException : public IOException
	{
	public:

		FileNotFoundException(long err = 0) : IOException(err) {}
		FileNotFoundException(const WString& s,long err = 0)  : IOException(s,err) {}

		virtual const JDFCh* getType() const { return Unicode::FILENOTFOUNDEXCEPTION_NAME; }
	};

	/**
	* Signals that an end of file or end of stream has been reached unexpectedly during input. 
	* This exception is mainly used by data input streams, which generally expect a 
	* binary file in a specific format, and for which an end of stream is an unusual 
	* condition. Most other input streams return a special value on end of stream. 
	* <p>
	* Note that some input operations react to end-of-file by returning a distinguished
	* value (such as -1) rather than by throwing an exception. 
	*
	* @author nverbove
	* @ingroup ioexceptions
	*/

	class JDFTOOLS_EXPORT EOFException : public IOException
	{
	public:

		/**
		* Constructs an EOFException with en empty error detail message.
		*/

		EOFException(long err = 0) : IOException(err) {}

		/**
		* Constructs an EOFException with the specified detail message.
		* The error message string s can later be retrieved by 
		* the <code>Throwable.getMessage()</code> method of class <code>Throwable</code>.
		*/

		EOFException(const WString& s,long err = 0)  : IOException(s,err) {}

		/**
		* EOFException identification type.
		* 
		* @return Returns EOFException
		*/

		virtual const JDFCh* getType() const { return Unicode::EOFEXCEPTION_NAME; }
	};

	/**
	* This exception is thrown when EOF is reached.
	* @ingroup ioexceptions
	*/
	class JDFTOOLS_EXPORT CEStreamExhausted : public IOException
	{
	public:

		/**
		* Constructs an CEStreamExhausted with en empty error detail message.
		*/

		CEStreamExhausted(long err = 0) : IOException(err) {}

		/**
		* Constructs an CEStreamExhausted with the specified detail message.
		* The error message string s can later be retrieved by 
		* the <code>Throwable.getMessage()</code> method of class <code>Throwable</code>.
		*/

		CEStreamExhausted(const WString& s,long err = 0)  : IOException(s,err) {}

		/**
		* CEStreamExhausted identification type.
		* 
		* @return Returns CEStreamExhausted
		*/

		virtual const JDFCh* getType() const { return Unicode::CESTREAMEXHAUSTED_NAME; }
	};

	/**
	* @ingroup ioexceptions
	*/
	class JDFTOOLS_EXPORT CEFormatException : public IOException
	{
	public:

		/**
		* Constructs an CEFormatException with en empty error detail message.
		*/

		CEFormatException(long err = 0) : IOException(err) {}

		/**
		* Constructs a CEFormatException with the specified detail message.
		* The error message string s can later be retrieved by 
		* the <code>Throwable.getMessage()</code> method of class <code>Throwable</code>.
		*/

		CEFormatException(const WString& s,long err = 0)  : IOException(s,err) {}

		/**
		* CEFormatException identification type.
		* 
		* @return Returns CEFormatException
		*/

		virtual const JDFCh* getType() const { return Unicode::CEFORMATEXCEPTION_NAME; }
	};



	/**
	* @ingroup netexceptions
	*/
	class JDFTOOLS_EXPORT SocketException : public IOException
	{
	public:

		SocketException() : IOException() {}
		SocketException(const WString& s)  : IOException(s) {}

		virtual ~SocketException()throw() {};
		virtual const JDFCh* getType() const { return Unicode::SOCKETEXCEPTION_NAME; }
	};

	/**
	* @ingroup netexceptions
	*/
	class JDFTOOLS_EXPORT PipeException : public IOException
	{
	public:

		PipeException() : IOException() {}
		PipeException(const WString& s)  : IOException(s) {}

		virtual ~PipeException()throw() {};
		virtual const JDFCh* getType() const { return Unicode::PIPEEXCEPTION_NAME; }
	};

	/**
	* @ingroup netexceptions
	*/
	class JDFTOOLS_EXPORT BindException : public SocketException
	{
	public:
		BindException() : SocketException() {}
		BindException(const WString& s)  : SocketException(s) {}

		virtual ~BindException()throw() {};
		virtual const JDFCh* getType() const { return Unicode::BINDEXCEPTION_NAME; }
	};

	/**
	* @ingroup netexceptions
	*/
	class JDFTOOLS_EXPORT ConnectException : public SocketException
	{
	public:
		ConnectException() : SocketException() {}
		ConnectException(const WString& s)  : SocketException(s) {}

		virtual ~ConnectException()throw() {};
		virtual const JDFCh* getType() const { return Unicode::CONNECTEXCEPTION_NAME; }
	};

	/**
	* @ingroup netexceptions
	*/
	class JDFTOOLS_EXPORT NoRouteToHostException : public SocketException
	{
	public:
		NoRouteToHostException() : SocketException() {}
		NoRouteToHostException(const WString& s)  : SocketException(s) {}

		virtual ~NoRouteToHostException()throw() {};
		virtual const JDFCh* getType() const { return Unicode::NOROUTETOHOSTEXCEPTION_NAME; }
	};

	/**
	* @ingroup netexceptions
	*/
	class JDFTOOLS_EXPORT UnknownHostException : public IOException
	{
	public:

		UnknownHostException() : IOException() {}
		UnknownHostException(const WString& s)  : IOException(s) {}

		virtual ~UnknownHostException()throw() {};
		virtual const JDFCh* getType() const { return Unicode::UNKNOWNHOSTEXCEPTION_NAME; }
	};

	/**
	* @ingroup netexceptions
	*/
	class JDFTOOLS_EXPORT MalformedURLException : public IOException
	{
	public:

		/**
		* Constructs anMalformedURLException with the specified detail message.
		* The error message string s can later be retrieved by 
		* the <code>Throwable.getMessage()</code> method of class <code>Throwable</code>.
		*/

		MalformedURLException(const WString& s)  : IOException(s) {}

		virtual ~MalformedURLException()throw() {};

		///////////////////////////////////////////////////////////////////////////
		// Public Instance Methods
		///////////////////////////////////////////////////////////////////////////

		/**
		* MalformedURLException Identification type.
		* 
		* @return Returns MalformedURLException
		*/

		virtual const JDFCh* getType() const { return Unicode::MALFORMEDURLEXCEPTION_NAME; }
	};

	/**
	* This is the generic MessageDigestException
	* @ingroup netexceptions
	*/

	class JDFTOOLS_EXPORT DigestException : public Exception
	{
	public:

		/**
		* Constructs a DigestException with the specified detail message.
		* The error message string s can later be retrieved by 
		* the <code>Throwable.getMessage()</code> method of class <code>Throwable</code>.
		*/

		DigestException(const WString& s)  : Exception(s) {}

		virtual ~DigestException()throw() {};

		///////////////////////////////////////////////////////////////////////////
		// Public Instance Methods
		///////////////////////////////////////////////////////////////////////////

		/**
		* DigestException Identification type.
		* 
		* @return Returns MalformedURLException
		*/

		virtual const JDFCh* getType() const { return Unicode::DIGESTEXCEPTION_NAME; }
	};

	/**
	* Thrown to indicate that there is an error in the underlying protocol, such as a TCP error
	* @ingroup netexceptions
	*/
	class JDFTOOLS_EXPORT ProtocolException : public IOException
	{
	public:

		ProtocolException() : IOException() {}
		ProtocolException(const WString& s)  : IOException(s) {}

		virtual ~ProtocolException()throw() {};
		virtual const JDFCh* getType() const { return Unicode::PROTOCOLEXCEPTION_NAME; }
	};

	/**
	* Thrown to indicate that an unknown service exception has occurred.
	* Either the MIME type returned by a URL connection does not make
	* sense, or the application is attempting to write to a read-only
	* URL connection.
	* @ingroup netexceptions
	*/

	class JDFTOOLS_EXPORT UnknownServiceException : public IOException
	{
	public:

		UnknownServiceException() : IOException() {}
		UnknownServiceException(const WString& s)  : IOException(s) {}

		virtual ~UnknownServiceException()throw() {};
		virtual const JDFCh* getType() const { return Unicode::UNKNOWNSERVICEEXCEPTION_NAME; }
	};


	/******************************************************************************
	*	Classes
	******************************************************************************/ 
	/**
	* The MIMEException Class represents an internal error in the 
	* the MIME API implementation.
	* A MIMEException is thrown when the MIME API detects a MIME API
	* error condition.
	* @ingroup mimeexceptions
	* @author Nico Verboven
	*/

	class JDFTOOLS_EXPORT MIMEException : public Exception
	{
	public:

		/**
		* Constructs an MIMEException with no detail message.
		*/

		MIMEException() : Exception() {};

		/**
		* Constructs an MIMEException with the specified detail message.
		*
		* @param s the detail message.
		*/

		MIMEException(const WString& s) : Exception(s) {}
		virtual ~MIMEException() throw(){}

		/**
		* returns the name of this Throwable object.
		*
		* @return name of this Throwable object.
		*/

		const JDFCh* getType() const { return Unicode::MIMEEXCEPTION_NAME; }
	};

} // namespace JDF

#endif /* I_JDF_LANGEXCEPTION_H */


/* end of file */
