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

#ifndef I_JDF_SOCKETIMPL_H
#define I_JDF_SOCKETIMPL_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include "SocketOptions.h"


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class InputStream;
	class OutputStream;
	class Socket;
	class SSLSocket;
	class ServerSocket;
}
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
 * The abstract class <code>SocketImpl</code> is a common superclass of all classes that actually implement sockets.
 * It is used to create both client and server sockets. 
 * A "plain" socket implements these methods exactly as described, without attempting
 * to go through a firewall or proxy. 
 * @ingroup net
 * @author nverbove  
 * @nosubgrouping 
 */

class JDFTOOLS_EXPORT SocketImpl : public SocketOptions
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	SocketImpl();

/*@}*/ 
#ifdef _WIN32
	virtual ~SocketImpl() = 0 {}

#else
	virtual ~SocketImpl(){};
#endif


	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Returns the address and port of this socket as a String.
	 * 
	 * @return a string representation of this socket.
	 */

	virtual WString toString();

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Returns the number of bytes that can be read from this socket without blocking.
	 * 
	 * @return the number of bytes that can be read from this socket without blocking.
	 * @exception IOException if an I/O error occurs when determining the number of bytes available.
	 */

	virtual int  available() = 0;// throws IOException;

	/**
	 * Closes this socket.
	 * 
	 * @exception if an I/O error occurs when closing this socket.
	 */

	virtual void close() = 0; // throws IOException


	/**
	 * Returns an input stream for this socket.
	 * 
	 * @return an input stream for reading bytes from this socket.
	 * @exception IOException if an I/O error occurs when creating the input stream.
	 */

	virtual InputStream& getInputStream() = 0;

	/**
	 * Returns an output stream for this socket.
	 * 
	 * @return an output stream for writing bytes to this socket.
	 * @exception IOException if an I/O error occurs when creating the output stream.
	 */

	virtual OutputStream& getOutputStream() = 0;

	/**
	 * Accepts a connection.
	 *
	 * @return  the accepted connection   
	 * @exception IOException if an I/O error occurs when accepting the connection.
	 */

	virtual  SocketImpl* accept() = 0 ; // throws IOException;

	/**
	 * Binds this socket to the specified port number on the specified host.
	 * 
	 * @param host the IP address of the remote host.
	 * @param port the port number.
	 * @exception IOException if an I/O error occurs when binding this socket.
	 */

	virtual void bind(const InetAddress& host, int port) = 0; // throws IOException;

	/**
	 * Connects this socket to the specified port on the named host.
	 * 
	 * @param   host the name of the remote host.
	 * @param   port the port number.
	 * @exception IOException if an I/O error occurs when connecting to the remote host.
	 */

	virtual void connect(const WString& host, int port) = 0; // throws IOException

	/**
	 * Connects this socket to the specified port number on the specified host.
	 * 
	 * @param address the IP address of the remote host.
	 * @param port the port number.
	 * @exception IOException if an I/O error occurs when attempting a connection.
	 */

	virtual void connect(const InetAddress& address, int port) = 0; // throws IOException

	/**
	 * Creates either a stream or a datagram socket.
	 * 
	 * @param stream if <code>true</code>, create a stream socket; otherwise, create a datagram socket.
	 * @exception IOException if an I/O error occurs while creating the socket.
	 */

	virtual void create(bool stream) = 0; // throws IOException

	/**
	 * Sets the maximum queue length for incoming connection indications (a request to connect) to the count argument.
	 * If a connection indication arrives when the queue is full, the connection is refused.
	 * 
	 * @param backlog the maximum length of the queue.
	 */

	virtual void listen(int backlog) = 0; // throws IOException

	/**
	 * Returns the value of this socket's address field.
	 * 
	 * @return the value of this socket's address field.
	 * @see InetAddress   
	 */

	/*virtual*/ InetAddress getInetAddress() { return mInetAddress; }

	/**
	 * Returns the value of this socket's localport field.
	 *
	 * @return the value of this socket's localport field.
	 * @see mLocalPort
	 */

	/*virtual*/ int getLocalPort() { return mLocalPort;}

	/**
	 * Returns the value of this socket's port field.
	 *
	 * @return the value of this socket's port field.
	 * @see mPort
	 */

	/*virtual*/ int getPort()	   { return mPort; }

	/**
	 * Returns the value of this socket's fd field.
	 *
	 * @return the value of this socket's fd field.
	 * @see SocketImpl#fd
	 */

	/*virtual*/ int getFileDescriptor()  { return  fd; }

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * The IP address of the remote end of this socket.
	 */

	InetAddress              mInetAddress;

	/**
	 * The local port number to which this socket is connected.
	 */

	int						 mLocalPort;

	/**
	 * The port number on the remote host to which this socket is connected.
	 */

	int						 mPort;

	/**
	 * The file descriptor object for this socket.
	 */

	unsigned int			 fd;

private:

	//
	// Hide copy constructor and assignment operator.
	//
	SocketImpl(const SocketImpl&);
	SocketImpl& operator=(const SocketImpl&);

	friend class Socket;
	friend class SSLSocket;
	friend class ServerSocket;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_SOCKETIMPL_H */


/* end of file */
