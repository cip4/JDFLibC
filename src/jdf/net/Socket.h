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

#ifndef I_JDF_SOCKET_H
#define I_JDF_SOCKET_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include <jdf/lang/Mutex.h>


namespace JDF
{

/******************************************************************************
 *	Forward declarations
 ******************************************************************************/ 
	class InetAddress;
	class WString;
	class SocketImplFactory;
	class SocketImpl;
	class OutputStream;
	class InputStream;

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
 * This class implements client sockets (also called just "sockets"). 
 * A socket is an endpoint for communication between two machines. 
 * <p>
 * The actual work of the socket is performed by an instance of the SocketImpl class.
 * An application, by changing the socket factory that creates the socket implementation, 
 * can configure itself to create sockets appropriate to the local firewall. 
 *
 * @author nverbove
 * @see  Socket#setSocketImplFactory(SocketImpl)
 * @ingroup net
 * @nosubgrouping
 */

class JDFTOOLS_EXPORT Socket 
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Creates an unconnected socket, with the system-default type of SocketImpl.
	 */

    Socket();

/*@}*/ 

	virtual ~Socket();

	///////////////////////////////////////////////////////////////////////////
	// Public Instance Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Creates a stream socket and connects it to the specified port number on the named host. 
	 * <p>
	 * If the application has specified a socket factory, that factory's <code>createSocketImpl</code> method
	 * is called to create the actual socket implementation. 
	 * Otherwise a "plain" socket is created. 
	 * 
	 * @param host the host name.
	 * @param port the port number.
	 * @exception IOException if an I/O error occurs when creating the socket.
	 * @exception UnknownHostException if the host could not be found
	 * @see Socket#setSocketImplFactory(SocketImpl)
	 * @see SocketImpl
	 * @see SocketImplFactory#createSocketImpl()
	 */

	virtual void connect(const WString& host, int port); // throws UnknownHostException, IOException

	/**
	 * Creates a stream socket and connects it to the specified port number at the specified IP address.
	 * <p>
	 * If the application has specified a socket factory, that factory's <code>createSocketImpl</code> method
	 * is called to create the actual socket implementation. 
	 * Otherwise a "plain" socket is created. 
	 * 
	 * @param address the IP address
	 * @param port the port number.
	 * @exception IOException if an I/O error occurs when creating the socket.
	 * @see Socket#setSocketImplFactory 
	 * @see SocketImpl
	 * @see SocketImplFactory#createSocketImpl()
	 */

	virtual void connect(const InetAddress& address, int port); // throws IOException

	/**
	 * Creates a socket and connects it to the specified remote host on the specified remote port.
	 * The Socket will also bind() to the local address and port supplied. 
	 * 
	 * @param host the name of the remote host
	 * @param port the remote port
	 * @param localAddr the local address the socket is bound to
	 * @param localPort the local port the socket is bound to
	 * @exception IOException if an I/O error occurs when creating the socket.
 	 */

	virtual void connect(const WString& host, int port, const InetAddress& localAddress, int localPort); // throws IOException

	/**
	 * Creates a socket and connects it to the specified remote address on the specified remote port.
	 * The Socket will also bind() to the local address and port supplied. 
	 * 
	 * @param address the remote address.
	 * @param port the remote port.
	 * @param localAddr the local address the socket is bound to.
	 * @param localPort the local port the socket is bound to.
	 * @exception IOException if an I/O error occurs when creating the socket.
	 */

	virtual void connect(const InetAddress& address, int port, const InetAddress& localAddress, int localPort); // throws IOException

	/**
	 * Returns the address to which the socket is connected.
	 * 
	 * @return the remote IP address to which this socket is connected.
	 */

	virtual InetAddress getInetAddress();

	/**
	 * Gets the local address to which the socket is bound.
	 *
	 * @return the local address
	 */

	virtual InetAddress getLocalAddress();

	/**
	 * Returns the value of this socket's localport field.
	 * 
	 * @return the value of this socket's localport field. 
	 */

	virtual int	getLocalPort();

	/**
	 * Returns the remote port to which this socket is connected.
	 * 
	 * @return the remote port number to which this socket is connected.
	 */

	virtual	int	getPort();

	/**
	 * Closes this socket.
	 * 
	 * @exception IOException if an I/O error occurs when closing this socket.
	 */

	virtual void close(); // throws IOException	

	/**
	 * Converts this socket to a WString.
	 * 
	 * @return a string representation of this socket.
	 */

	virtual WString toString();

	/**
	 * Returns an input stream for this socket.
	 * 
	 * @return an input stream for reading bytes from this socket.
	 * @exception IOException if an I/O error occurs when creating the input stream.
	 */

	virtual InputStream& getInputStream(); // throw IOException

	/**
	 * Returns an output stream for this socket.
	 * 
	 * @return an output stream for writing bytes to this socket.
	 * @exception IOException if an I/O error occurs when creating the output stream.
	 */

	virtual OutputStream& getOutputStream(); // throw IOException

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
	 */

	void setSoTimeout(int timeout); // throw SocketException


	/**
	 * Returns setting for SO_TIMEOUT.
	 * 0 returns implies that the option is disabled (i.e., timeout of infinity).
	 */

	int getSoTimeout(); //throws SocketException

	/**
	 * Enable/disable SO_LINGER with the specified linger time in seconds.
	 * If the specified timeout value exceeds 65,535 it will be reduced to 65,535.
	 * 
	 * @param on whether or not to linger on.
	 * @param linger how to linger for, if on is true.
	 * @exception IllegalArgumentException if the linger value is negative.
	 */

	void setSoLinger(bool on, int linger); // throw SocketException

	/**
	 * Returns setting for SO_LINGER. 
	 * -1 returns implies that the option is disabled.
	 */

	int  getSoLinger(); // throw SocketException;

	/**
	 * Get value of the SO_RCVBUF option for this socket, that is the buffer size used by the platform for input on the this Socket.
	 * 
	 * @return receive buffer size
	 * @see  Socket#setReceiveBufferSize   
	 */

	int getReceiveBufferSize(); // throw SocketException

	/**
	 * Sets the SO_RCVBUF option to the specified value for this Socket. 
	 * The SO_RCVBUF option is used by the platform's networking code as a hint for the
	 * size to use to allocate set the underlying network I/O buffers. 
	 * <p>
	 * Increasing buffer size can increase the performance of network I/O for
	 * high-volume connection, while decreasing it can help reduce the backlog of incoming data.
	 * For UDP, this sets the maximum size of a packet that may be sent on this socket. 
	 * <p>
	 * Because SO_RCVBUF is a hint, applications that want to verify what size the buffers were set 
	 * to should call IllegalArgumentException - if the value is 0 or is negative.
	 * 
	 * @see Socket#getReceiveBufferSize()
	 */

	void setReceiveBufferSize(int size); // throw SocketException

	/**
	 * Get value of the SO_SNDBUF option for this socket, that is the buffer size used by the platform for output on the this Socket.
	 * 
	 * @return send buffer size 
	 * @see Socket#setSendBufferSize(int)    
	 */

	int getSendBufferSize(); // throw SocketException

	/**
	 * Sets the SO_SNDBUF option to the specified value for this Socket. 
	 * The SO_SNDBUF option is used by the platform's networking code as a hint for the size 
	 * to use to allocate set the underlying network I/O buffers.
	 * <p>
	 * Increasing buffer size can increase the performance of network I/O for 
	 * high-volume connection, while decreasing it can help reduce the backlog of 
	 * incoming data. For UDP, this sets the maximum size of a packet that may be
	 * sent on this socket. 
	 * <p>
	 * Because SO_SNDBUF is a hint, applications that want to verify what size the buffers
	 * were set to should call IllegalArgumentException - if the value is 0 or is negative.
	 * 
	 * @see Socket#getSendBufferSize 
	 */

	void setSendBufferSize(int size);// throw SocketException
	
	/**
	 * Enable/disable TCP_NODELAY (disable/enable Nagle's algorithm).
	 * 
	 * @param on if false disable TCP_NODELAY else enable TCP_NODELAY
	 */

	void setTcpNoDelay(bool on); // throw SocketException

	/**
	 * Tests if TCP_NODELAY is enabled.
	 */

	bool getTcpNoDelay();// throw SocketException

	/**
	 * Determines if this socket is in an error state
	 *
	 * @return true if this socket is in an error state, false otherwise
	 */

	bool			operator !();

	/**
	 * Determines if this socket is valid.
	 *
	 * @return true if this socket is valid, false otherwise
	 */

    operator         bool();


	///////////////////////////////////////////////////////////////////////////
	// Public Class Methods
	///////////////////////////////////////////////////////////////////////////

	/**
	 * Sets the client socket implementation factory for the application.
	 * The factory can be specified only once.
	 * <p>
	 * When an application creates a new client socket, the socket implementation factory's
	 * <code>createSocketImpl</code> method is called to create the actual socket implementation. 
	 * 
	 * @param fac the desired factory 
	 * @exception IOException if an I/O error occurs when setting the socket factory.
	 * @exception SocketException if the factory is already defined.
	 * @see SocketImplFactory#createSocketImpl(),     
	 */

	static void setSocketImplFactory(SocketImplFactory* fac); // throws IOException, SocketException

	
	static void reinitSocketMutex();

protected:

	///////////////////////////////////////////////////////////////////////////
	// Protected Constructors
	///////////////////////////////////////////////////////////////////////////

    /**
     * Creates an unconnected Socket with a user-specified SocketImpl. 
	 * The impl parameter is an instance of a SocketImpl 
	 * the subclass wishes to use on the Socket.
     * 
     * @param impl the SocketImpl to use
     */

    Socket(SocketImpl* impl);

	///////////////////////////////////////////////////////////////////////////
	// Protected Instance Variables
	///////////////////////////////////////////////////////////////////////////

    /**
     * The implementation for this socket.
     */

	SocketImpl* mSocketImpl;

    /**
     * Controls access to the Socket
     */

	Mutex		mCriticalSection;


	static void terminate();

	///////////////////////////////////////////////////////////////////////////
	// Protected Class Methods
	///////////////////////////////////////////////////////////////////////////

    /**
     * The socket implementation factory class method for the Sockets.
     */

	static SocketImplFactory* mSocketImplFactory;
	friend class ServerSocket;

private:

	//
	// Hide copy constructor and assignment operator.
	//
	Socket(const Socket&);
	Socket& operator=(const Socket&);

	friend class PlatformUtils;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDFSOCKET_H */


/* end of file */



