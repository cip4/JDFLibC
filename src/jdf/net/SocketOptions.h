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

#ifndef I_JDF_SOCKETOPTIONS_H
#define I_JDF_SOCKETOPTIONS_H

/******************************************************************************
 *	Includes
 ******************************************************************************/ 
#include "InetAddress.h"


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
 * Represents an option on a Socket
 *
 * @author nverbove
 * @internal
 * @see SocketOptions
 * @nosubgrouping
 */

class  SocketOption
{
public:

	typedef enum
	{
		BOOLEANVALUE,
		INTEGERVALUE,
		INETADDRESSVALUE
	} ValueType;

public:

/** 
 * @name Constructors
 */
/*@{*/

	SocketOption(bool boolValue);
	SocketOption(int intValue);
	SocketOption(const InetAddress& addressValue);
	SocketOption(const SocketOption&);

/*@}*/ 

	SocketOption& operator=(const SocketOption&);

	operator bool()  const       { return mBoolValue;   }
	operator int()   const       { return mIntValue;    }
	operator InetAddress() const { return mInetAddress; }

	ValueType getValueType() const { return mValueType; }

protected:

	ValueType	mValueType; 

	bool		mBoolValue;
	int			mIntValue;
	InetAddress mInetAddress;
};

/**
 * Interface of methods to get/set socket options.
 * This interface is implemented by: <b>SocketImpl</b> and <b>DatagramSocketImpl</b>. 
 * Subclasses of these should override the methods of this interface in order to support their own options. 
 * <p>
 * The methods and constants which specify options in this interface are for implementation only. 
 * If you're not subclassing SocketImpl or DatagramSocketImpl, <b>you won't use these directly</b>. 
 * There are type-safe methods to get/set each of these options in Socket, ServerSocket, DatagramSocket and MulticastSocket. 
 * <p>
 * A subset of the standard BSD-style socket options are supported in the JDF base classes,
 * <b>PlainSocketImpl</b>. A brief description of each and their use is provided. 
 *
 * @author nverbove 
 * @internal
 */

class JDFTOOLS_EXPORT SocketOptions 
{
public:

	/**
 	 * Set which outgoing interface on which to send multicast packets.
	 * Useful on hosts with multiple network interfaces, where applications
	 * want to use other than the system default. Takes/returns an InetAddress. 
	 * Valid for Multicast: DatagramSocketImpl 
	 *
	 * @see MulticastSocket#setInterface()
	 * @see MulticastSocket#getInterface()
	 */

	static const int IP_MULTICAST_IF_OPT;

	/**
	 * Fetch the local address binding of a socket (this option cannot be "set" only "gotten",
	 * since sockets are bound at creation time, and so the locally bound address
	 * cannot be changed). The default local address of a socket is INADDR_ANY,
	 * meaning any local address on a multi-homed host. 
	 * A multi-homed host can use this option to accept connections to only one of its 
	 * addresses (in the case of a ServerSocket or DatagramSocket), or to specify its return 
	 * address to the peer (for a Socket or DatagramSocket). The parameter of this option is an InetAddress. 
	 * <p>
	 * This option must be specified in the constructor. 
	 * <p>
	 * Valid for: SocketImpl, DatagramSocketImpl 
	 *
	 * @see Socket#getLocalAddress
	 * @see ServerSocket#getInetAddress
	 * @see DatagramSocket#getLocalAddress
	 */

	static const int SO_BINDADDR_OPT;

	/**
	 * Specify a linger-on-close timeout.
	 * This option disables/enables immediate return from a <b>close()</b> of a TCP Socket. 
	 * Enabling this option with a non-zero Integer <i>timeout</i> means that a <b>close()</b> will block 
	 * pending the transmission and acknowledgement of all data written to the peer, 
	 * at which point the socket is closed <i>gracefully</i>. Upon reaching the linger timeout, 
	 * the socket is closed <i>forcefully</i>, with a TCP RST. Enabling the option with a timeout of 
	 * zero does a forceful close immediately. If the specified timeout value exceeds 65,535 it
	 * will be reduced to 65,535. 
	 * Valid only for TCP: SocketImpl.
	 *
	 * @see Socket#setSoLinger()
	 * @see Socket#getSoLinger()
	 */

	static const int SO_LINGER_OPT;

	/**
	 * Set a hint for the size of the underlying buffers used by the platform for incoming network I/O. 
	 * When used in set, this is a suggestion to the kernel from the application about 
	 * the size of buffers to use for the data to be received over the socket. \
	 * When used in get, this must return the size of the buffer actually used by the platform when
	 * receiving in data on this socket.
	 * Valid for all sockets: SocketImpl, DatagramSocketImpl
	 *
	 * @see Socket#setReceiveBufferSize
	 * @see Socket#getReceiveBufferSize
	 * @see DatagramSocket#setReceiveBufferSize
	 * @see DatagramSocket#getReceiveBufferSize
	 */

	static const int SO_RCVBUF_OPT;

	/**
	 * Sets SO_REUSEADDR for a socket.
	 * This is used only for MulticastSockets in JDF, and it is set by default for MulticastSockets. 
	 * Valid for: DatagramSocketImpl.
	 */

	static const int SO_REUSEADDR_OPT;

	/**
	 * Set a hint the size of the underlying buffers used by the platform for outgoing network I/O. 
	 * When used in set, this is a suggestion to the kernel from the application about the size of buffers
	 * to use for the data to be sent over the socket.
	 * When used in get, this must return the size of the buffer actually used by the platform
	 * when sending out data on this socket. 
	 * Valid for all sockets: SocketImpl, DatagramSocketImpl
	 *
	 * @see Socket#getSendBufferSize
	 * @see DatagramSocket#getSendBufferSize
	 */

	static const int SO_SNDBUF_OPT;

	/**
	 * Set a timeout on blocking Socket operations: <p><blockquote><pre>ServerSocket.accept(),SocketInputStream.read(),DatagramSocket.receive()</pre></blockquote><p>
	 * The option must be set prior to entering a blocking operation to take effect. 
	 * If the timeout expires and the operation would continue to block, <b>InterruptedIOException</b> 
	 * is raised. The Socket is not closed in this case. Valid for all sockets: SocketImpl, DatagramSocketImpl
	 *
	 * @see Socket#setSoTimeout()
	 * @see ServerSocket#setSoTimeout()
	 * @see DatagramSocket#setSoTimeout()
	 */

	static const int SO_TIMEOUT_OPT;

	/**
	 * Gets the error status for a socket.
	 * The error status is maintained on a per-Thread basis and returns the completion code
	 * of the last socket call.
	 * 
	 */
	static const int SO_ERROR_OPT;

	/**
	 * Disable Nagle's algorithm for this connection.
	 * Written data to the network is not buffered pending acknowledgement of previously 
	 * written data.
	 * <p>
	 * Setting TCPNODELAY_OPT to true ensures that packets are send  as quickly as possible
	 * regardless of their size. Normally small (one-byte)  packets are combined into larger packets
	 * before being sent. before sending another packet, the local host waits to receive a packet
	 * from the remote system. This is known as Nagle's algorithm. The problem with Nagle's
	 * algorithm is that if the remote system doesn't send something back to the local system
	 * the connection can get stuck. Turning TCPNODELAY_OPT off defeats this buffering scheme,
	 * so that packets are sent as soon as they're ready.
	 *
	 * Valid for TCP only: SocketImpl. 
	 *
	 * @see Socket#setTcpNoDelay()
	 * @see Socket#getTcpNoDelay()
	 */

	static const int TCPNODELAY_OPT;

	/**
	 * Sets FIONBIO for a socket.
	 * This controls whether the socket should be blocking or not.
	 */

	static const int SO_IONBIO_OPT;

	/**
	 * Fetch the value of an option.
	 * Binary options will return bool(true) if enabled, bool(false) if disabled, e.g.: .
	 * <p><blockquote><pre>
	 * SocketImpl s
	 * bool noDelay = s.getOption(SocketOptions::TCP_NODELAY_OPT);
	 * if (noDelay) { // TCP_NODELAY is enabled
	 * ...
	 * }
	 * </pre></blockquote><p>
	 * For options that take a particular type as a parameter,
	 * getOption(int) will return the parameter's value, else it will return bool(false): 
	 * <p><blockquote><pre>
	 * SocketOption opt = s.getOption(SocketOptions::SO_LINGER_OPT);
	 *
	 * cout << "Linger time is 	" << (int) opt;
	 *:</pre></blockquote><p>
	 * @exception SocketException if the socket is closed
	 * @exception SocketException if <i>optID</i> is unknown along the protocol stack (including the SocketImpl)
	 */

	virtual SocketOption getOption(int optID) = 0; // throw SocketException

	/**
	 * Enable/disable the option specified by <i>optID</i>. 
	 * If the option is to be enabled, and it takes an option-specific "value", this is passed in <i>value</i>.
	 * The actual type of value is option-specific, and it is an error to pass something that isn't of the expected type: 
	 * <p><blockquote><pre>
	 * SocketImpl s;
	 *	 ...
	 * s.setOption(SocketOptions::SO_LINGER_OPT, 10);
	 * // OK - set SO_LINGER w/ timeout of 10 sec.
	 * </pre></blockquote><p>
	 * If the requested option is binary, it can be set using this method by bool: 
	 * <p><blockquote><pre>
	 * s.setOption(TCP_NODELAY, true);
	 * // OK - enables TCP_NODELAY, a binary option
	 * </pre></blockquote><p>
	 * Any option can be disabled using this method with a <i>bool(false)</i>: 
	 * <p><blockquote><pre>
	 * s.setOption(TCP_NODELAY, false);
	 * // OK - disables TCP_NODELAY
	 * s.setOption(SO_LINGER, false);
	 * // OK - disables SO_LINGER
	 * </pre></blockquote><p>
	 *
	 * For an option that requires a particular parameter, setting its value to anything other than bool(false) implicitly enables it. 
	 * Throws SocketException if the option is unrecognized, the socket is closed, 
	 * or some low-level error occurred 
	 * 
	 * @param optID identifies the option
	 * @param value the parameter of the socket option
	 * @exception SocketException if the option is unrecognized, the socket is closed, or some low-level error occurred
	 */

	virtual void setOption(int optID, const SocketOption& value) = 0;
};

/******************************************************************************
 *	Prototypes
 ******************************************************************************/ 


/******************************************************************************
 *	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_SOCKETOPTIONS_H */


/* end of file */
