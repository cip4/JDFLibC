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

#ifndef I_JDF_SSLSOCKET_H
#define I_JDF_SSLSOCKET_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include "Socket.h"

#ifdef JDF_USESSL
#include <openssl/ssl.h>
#endif


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
 * SSLSocket is a class extended by sockets which support the 
 * "Secure Sockets Layer" (SSL) or IETF "Transport Layer Security" (TLS) 
 * protocols. Such sockets are normal stream sockets (java.net.Socket), 
 * but they add a layer of security protections over the underlying network 
 * transport protocol, such as TCP. Those protections include: 
 * <ul>
 * <li><i>Integrity Protection</i>. SSL protects against modification of 
 * messages by an active wiretapper. </li>
 * <li><i>Authentication</i>. In most modes, SSL provides peer authentication.
 * Servers are usually authenticated, and clients may be authenticated as 
 * requested by servers.</li>
 * <li><i>Confidentiality (Privacy Protection)</i>. In most modes,
 * SSL encrypts data being sent between client and server. This protects the 
 * confidentiality of data, so that passive wiretappers won't see sensitive 
 * data such as financial information or personal information of many kinds.</li>
 * </ul>
 * <p>
 * These kinds of protection are specified by a "cipher suite", which is a combination of cryptographic algorithms used by a given SSL connection. For example, how is integrity protection provided (what kind of message digest is used), how and whether the traffic is privacy-protected, 
 * and how authentication keys are exchanged. 
 * <p> 
 * The cipher suite used is established by a negotiation process, 
 * between SSL clients and servers, which is called "handshaking". 
 * The goal of this process is to create or rejoin a "session", which may
 * protect many connections over time.
 * <p><hr>
 * When SSL connections are first set up, no security is provided. However, 
 * security is always provided by the time that application data is sent over
 * the connection. Before sending such data, application programs may then 
 * express preferences for what cipher suites may be used in communication. 
 * SSL code performs a negotiation as part of preparing to send data. 
 * Some cipher suite that is supported by both sides of the SSL connection 
 * will be used. If there is no such suite, no SSL connection will be 
 * established, and no data can be exchanged. 
 * Implementation defaults are required to enable use only of cipher suites 
 * which authenticate servers, and which provide confidentiality. The client 
 * and server must both agree on a common cipher suite in order to communicate. 
 * Only if both explicitly agree to unauthenticated or nonprivate communications
 * will those security protections not exist. 
 * @ingroup net
 * @nosubgrouping
 */
 
class JDFTOOLS_EXPORT SSLSocket : public Socket
{
public:

/** 
 * @name Constructors
 */
/*@{*/

	/**
	 * Constructs an uninitialized, unconnected TCP socket. 
	 */
	SSLSocket();

/*@}*/ 

	/**
	 * Closes this SSL Socket and frees any resources associated
	 * with it
	 */

	~SSLSocket();

	/**
	 * Starts an SSL handshake on this connection
	 */
	void SSLConnect();

	/**
	 * Closes the connection and terminates the SSL session
	 */
	void close();

	/**
	 * Constructs a TCP connection to a named host at a specified port. 
	 * This acts as the SSL client. 
	 * @param host name of the host with which to connect
	 * @param port number of the server's port
	 * @exception IOException if an I/O error occurs when creating the socket.
	 */
	void connect(const WString& host, int port);

	/**
	 * Creates a stream socket and connects it to the specified port number at the specified IP address.
	 * This acts as the SSL client. 
	 * 
	 * @param address the remote server's IP address
	 * @param port the port number.
	 * @exception IOException if an I/O error occurs when creating the socket.
	 */
	void connect(const InetAddress& address, int port);

	/**
	 * Constructs an SSL connection to a named host at a specified port, 
	 * binding the client side of the connection a given address and port. 
	 * This acts as the SSL client. 
	 * @param host name of the host with which to connect
	 * @param port the remote port.
	 * @param localAddr the local address the socket is bound to.
	 * @param localPort the local port the socket is bound to.
	 * @exception IOException if an I/O error occurs when creating the socket.
	 */
	void connect(const WString& host, int port, const InetAddress& localAddress, int localPort); 

	/**
	 * Constructs an SSL connection to a to a server at a specified address and TCP port, 
	 * binding the client side of the connection a given address and port. 
	 * This acts as the SSL client. 
	 * @param address the remote server's IP address
	 * @param port the remote port.
	 * @param localAddr the local address the socket is bound to.
	 * @param localPort the local port the socket is bound to.
	 * @exception IOException if an I/O error occurs when creating the socket.
	 */
	void connect(const InetAddress& address, int port, const InetAddress& localAddress, int localPort);

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
	 * Converts this socket to a WString.
	 * 
	 * @return a string representation of this socket.
	 */

	WString toString();
	
protected:

	/**
	 * Flag identifying if an SSL handshake has been performed on this socket.
	 */
	bool useSSL() { return mUseSSL; }

	OutputStream* mOut;
	InputStream*  mIn;

#ifdef JDF_USESSL
	SSL_CTX* ssl_ctx;
	SSL*	 ssl_con;
#endif
	bool	 mUseSSL;

	friend class SSLSocketInputStream;
	friend class SSLSocketOutputStream;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_SSLSOCKET_H */
