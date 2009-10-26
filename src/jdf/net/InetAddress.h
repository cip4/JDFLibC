/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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
* 092602 RP removed printf statements
* 
******************************************************************************/

#ifndef I_JDF_INETADDRESS_H
#define I_JDF_INETADDRESS_H

/******************************************************************************
*	Includes
******************************************************************************/ 
#include <jdf/lang/WString.h>

#include <vector>


namespace JDF
{
	
/******************************************************************************
*	Forward declarations
	******************************************************************************/ 
	
	class InetAddressImpl;
	class PlatformUtils;

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
	* This class represents an Internet Protocol (IP) address. 
	* <p>
	* Applications should use the methods <code>getLocalHost</code>, <code>getByName</code>, 
	* or <code>getAllByName</code> to create a new <code>InetAddress</code> instance. 
	*
	* Additional caching of InetAddresses will be added later.
	* @see InetAddressCachePolicy
	* @author nverbove
	* @ingroup net
	* @nosubgrouping
	* @todo implement InetAddress caching using the InetAddressCachePolicy
	*/
	
	class JDFTOOLS_EXPORT InetAddress 
	{
	public:
		
	/** 
	* @name Constructors
		*/
		/*@{*/
		
		/**
		* This creates an empty InetAddress, which is filled in by
		* the accept() method.  This InetAddress, however, is not
		* put in the address cache, since it is not created by name.
		* This isn't a valid InetAddress.
		* Applications should always use the getX methods the construct
		* a valid InetAddress.
		*/
		
		InetAddress();
		
		/*@}*/ 
		
		/**
		* Destruct this Object.
		*/
		
		~InetAddress()  {};
		
		/**
		* Make a copy of an InetAddress.
		*/
		
		InetAddress(const InetAddress&);
		
		///////////////////////////////////////////////////////////////////////////
		// Public Class Methods
		///////////////////////////////////////////////////////////////////////////
		
		/**
		* Determines all the IP addresses of a host, given the host's name.
		* The host name can either be a machine name, such as "java.sun.com", 
		* or a string representing its IP address, such as "206.26.48.100". 
		* 
		* @param host the name of the host.
		* @return an array of all the IP addresses for a given host name.
		* @exception UnknownHostException if no IP address for the host could be found.
		*/
		
		static std::vector<InetAddress> getAllByName(const WString& host);    // throws UnknownHostException
		
																			  /**
																			  * Determines the IP address of a host, given the host's name.
																			  * The host name can either be a machine name, such as "java.sun.com", 
																			  * or a string representing its IP address, such as "206.26.48.100". 
																			  * 
																			  * @param host the name of the host.
																			  * @return an IP address for the given host name.
																			  * @exception UnknownHostException if no IP address for the host could be found.
		*/
		
		static InetAddress         getByName(const WString& host);       // throws UnknownHostException
		
																		 /**
																		 * Returns the local host.
																		 * 
																		 * @return the IP address of the local host.
																		 * @exception UnknownHostException if no IP address for the host could be found.
		*/
		
		static InetAddress         getLocalHost(); // throws UnknownHostException
		
		///////////////////////////////////////////////////////////////////////////
		// Public Instance Methods
		///////////////////////////////////////////////////////////////////////////
		
		/**
		* Returns the fully qualified host name for this address. 
		* If the host is equal to null, then this address refers to any
		* of the local machine's available network addresses.
		* 
		* @return the fully qualified host name for this address.   
		*/
		
		WString        getHostName();
		
		/**
		* Returns the raw IP address of this InetAddress object.
		* The result is in network byte order: the highest order byte of the address is 
		* in getAddress()[0].
		* 
		* @return the raw IP address of this object. 
		*/
		
		std::vector<unsigned char>  getAddress() const;
		
		/**
		* Returns the IP address string "%d.%d.%d.%d".
		* 
		* @return  the raw IP address in a string format.		  
		*/
		
		WString	getHostAddress() const;
		
		/**
		* Converts this IP address to a String.
		* The string has the format hostname/IPAddress
		* 
		* @return a string representation of this IP address.
		*/
		
		WString	toString();
		
		/**
		* Utility routine to check if the InetAddress is a IP multicast address. 
		* IP multicast address is a Class D address i.e first four bits of the address
		* are 1110.
		*/
		
		bool		  isMulticastAddress() const;
		
		static void setInetAddressImpl(InetAddressImpl* impl);
		
		/**
		* Test for equality	
		* 
		*/
		
		int operator == (const InetAddress& T) const
		{ return mAddress == T.mAddress; }
		
		/**
		* Test for inequality	
		* 
		*/
		
		int operator != (const InetAddress& T) const
		{ return mAddress != T.mAddress; }
		
		/**
		* Assign an InetAddress to this object.
		*/
		
		InetAddress& operator=(const InetAddress&);
		
		
private:
	
/** 
* Creates an InetAddress with the specified host name and IP address.
* @param hostName the specified host name
* @param addr the specified IP address. The address is expected in
* network byte order.
* @exception UnknownHostException If the address is unknown.
	*/
	InetAddress(const WString& hostName, const char* addr);
	
	///////////////////////////////////////////////////////////////////////////
	// Private Class Methods
	///////////////////////////////////////////////////////////////////////////
	
	static InetAddress		   getByAddress(const WString& address); // throws UnknownHostException
	
	static std::vector<InetAddress> getAllByName0(const WString& hostName);
	static std::vector<InetAddress> getAddressFromNameService(const WString& hostName);
	
	///////////////////////////////////////////////////////////////////////////
	// Private Instance Variables
	///////////////////////////////////////////////////////////////////////////
	
	WString mHostName;
	
    /*
	* Currently we only deal effectively with 32-bit addresses.
	* However this field can be expanded to be a byte array
	* or a 64-bit quantity without too much effort.
	*/
    int mAddress;
	
	int mFamily;
	
	//	std::vector<unsigned char> mAddress;
	
	friend class InetAddressImpl;
	
	static InetAddressImpl* impl;
	static InetAddress*	    unknownAddress;
	static InetAddress*	    localHost;
	static InetAddress*	    loopbackHost;
	
	static void terminate();
	
	friend class PlatformUtils;
};


/******************************************************************************
*	Prototypes
******************************************************************************/ 


/******************************************************************************
*	Implementation
 ******************************************************************************/ 

} // namespace JDF

#endif /* I_JDF_INETADDRESS_H */


/* end of file */
