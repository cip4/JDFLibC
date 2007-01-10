/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2003 The International Cooperation for the Integration of 
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
 * copyright (c) 1999-2003, Heidelberger Druckmaschinen AG 
 * copyright (c) 1999-2003, Agfa-Gevaert N.V. 
 *  
 * For more information on The International Cooperation for the 
 * Integration of Processes in  Prepress, Press and Postpress , please see
 * <http://www.cip4.org/>.
 *
 *
 */
/******************************************************************************
 *               Copyright 2003 Heidelberger Druckmaschinen AG                *
 *                           All rights reserved                              *
 *                                                                            *
 * The material contained herein may not be reproduced in whole or in part,   *
 *   without the prior written consent of Heidelberger Druckmaschinen AG.     *
 *                                                                            *
 ******************************************************************************/

/*******************************************************************************
 * 
 * Description:
 *
 *
 ******************************************************************************/

#ifndef I_JDF_ISERVERSOCKET_H
#define I_JDF_ISERVERSOCKET_H


/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include <jdf/net/Socket.h>


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
 * This class implements server sockets. A server socket waits for requests
 * to come in over the network. It performs some operation based on that
 * request, and then possibly returns a result to the requester.
 * <p>
 * The actual work of the server socket is performed by an instance of the 
 * SocketImpl class. An application can change the socket factory that creates 
 * the socket implementation to configure itself to create sockets appropriate 
 * to the local firewall.
 * 
 * @author fbarenthien
 * @see ServerSocket#setSocketFactory
 * @ingroup net
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT ServerSocket
{
public:
	/**
	 * Sets the server socket implementation factory for the application. The factory can be specified only once.
	 * 
	 * @exception SocketException if the factory has already been defined.
	 */
	static void setSocketFactory(SocketImplFactory* pFactory); // throw(SocketException);

public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates an unbound server socket.
	 * 
	 * @exception IOException if an I/O error occurs when creating the server socket.
	 */
	ServerSocket(); // throw(IOException)

	/**
	 * Create a ServerSocket with the specified local IP address, port and listen backlog to bind to.
	 * 
	 * @param bindAddr the remote address.
	 * @param port the port number.
	 * @param backlog  The listen backlog length.
	 * 
	 * @exception IOException if an I/O error occurs when creating the server socket.
	 */
	ServerSocket(const InetAddress& bindAddr, int port, int backlog = 50); // throw(IOException)

/*@}*/ 

	virtual ~ServerSocket();

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Listens for a connection to be made to this socket and accepts it.
	 * 
	 * @return returns a new socket.
	 * @exception InterruptedIOException if a timeout was previously set with setSoTimeout and the timeout has been reached.
	 * @exception IOException if an I/O error occurs.
	 */
	Socket* accept(); // throw(InterruptedIOException, IOException)

	/**
	 * Binds the ServerSocket to a specific address (IP address and port number).
	 * 
	 * @param bindAddr the remote address.
	 * @param port the port number.
	 * @param backlog  The listen backlog length.
	 * @exception IOException if an I/O error occurs when creating the server socket.
	 */
	void bind(const InetAddress& bindAddr, int port, int backlog = 50); // throw(IOException)

	/**
	 * Closes this server socket. Any thread currently blocked in accept() will throw a SocketException.
	 * 
	 * @exception IOException if an I/O error occurs when creating the socket.
	 */
	void close(); //throw(IOException)

	/**
	 * Enable/disable SO_TIMEOUT with the specified timeout, in milliseconds.
	 * With this option set to a non-zero timeout, a <code>read()</code> call
	 * on the <code>InputStream</code> associated with this Socket will block for only 
	 * this amount of time. If the timeout expires, an <b>InterruptedIOException</b>
	 * is raised, though the Socket is still valid.
	 * The option <b>must</b> be enabled prior to entering the blocking 
	 * operation to have effect. The timeout <b>must</b> be > 0. 
	 * A timeout of zero is interpreted as an infinite timeout.
	 * 
	 * @param timeout timeout value
	 * @exception SocketException if an error occurs.
	 */
	void setSoTimeout(int timeout); // throw(SocketException)

	/**
	 * Returns setting for SO_TIMEOUT. 0 implies that the option is disabled (i.e., timeout of infinity).
	 * 
	 * @return returns the setting for SO_TIMEOUT.
	 * @exception SocketException if an error occurs.
	 */
	int getSoTimeout(); // throw(SocketException)

	/**
	 * Returns the binding state of the ServerSocket.
	 * 
	 * @return true if the ServerSocket has been succesfully bound to an address.
	 */
	bool isBound(); // throw()

	/**
	 * Returns the closed state of the ServerSocket.
	 * 
	 * @return true if the ServerSocket has been closed.
	 */
	bool isClosed(); // throw()

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Class Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Internal method to get the socket implementation
	 */
	SocketImpl* getImpl();

	/**
	 * Internal method to get the socket implementation
	 */
	void setImpl();

	static void terminate();

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Holds the binding state of the ServerSocket.
	 */
	bool m_bBound;

	/**
	 * Holds the closed state of the ServerSocket.
	 */
	bool m_bClosed;

	/**
	 * Holds the creation state of socket implementation.
	 */
	bool m_bCreated;

	/**
	 * controls access to the ServerSocket.
	 */
	Mutex       m_cs;

	/**
	 * Holds a pointer to the socket implementation.
	 */
	SocketImpl* m_pImpl;

	/**
	 * The socket implementation factory class method for the server sockets.
	 */
	static SocketImplFactory* s_pFactory;

private:

	//
	// Hide copy constructor and assignment operator.
	//
	ServerSocket(const ServerSocket&);
	ServerSocket& operator=(const ServerSocket&);

	friend class PlatformUtils;
};

} // namespace JDF

#endif // I_JDF_ISERVERSOCKET_H

/* end of file
 ******************************************************************************/ 
