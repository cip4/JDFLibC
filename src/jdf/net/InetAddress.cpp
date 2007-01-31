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


/******************************************************************************
*	Includes
******************************************************************************/ 

//#include <jdf/util/PlatformUtils.h>
#ifdef XML_WIN32
#pragma warning( disable : 4786 ) // long debug names from stl
#endif

#include <xercesc/util/XMLUniDefs.hpp>

#include <jdf/lang/Synchronized.h>
#include <jdf/lang/Exception.h>
#include <jdf/net/InetAddressImpl.h>
#include <jdf/util/PlatformUtils.h>

#include <jdf/net/InetAddress.h>


XERCES_CPP_NAMESPACE_USE


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

	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/ 

	InetAddressImpl* InetAddress::impl = 0;
	InetAddress* InetAddress::unknownAddress = 0;
	InetAddress* InetAddress::loopbackHost = 0;
	InetAddress* InetAddress::localHost = 0;

	void InetAddress::setInetAddressImpl(InetAddressImpl* newImpl)
	{
		impl = newImpl;
		unknownAddress = new InetAddress();
		char IP[4];
		IP[0] = 0x7f;
		IP[1] = 0;
		IP[2] = 0;
		IP[3] = 1;
		loopbackHost = new InetAddress("localhost",IP);
		localHost = new InetAddress();
		// find the local host name
		try
		{
			localHost->mHostName = impl->getLocalHostName();
			/*
			We explicitly leave the address of the localhost name uninitialized.
			A DNS lookup here will cause the a machine disconnected from the 
			network to hang.
			Instead we just give the hostname of the local host.
			The native code for this just calls gethostname() which should be 
			pretty innocuous - it shouldn't try to contact a DNS server.
			If any application calls InetAddress::getLocalHost(), we initialize
			the local host's address there if not already initialized
			* Note that for this to work it is also essential that
			* the localHost InetAddress is _NOT_ put into the address cache
			* here in the static initializer (which happens if we call
			* getByName() from the static initializer).  It _IS_ OK
			* to put it in the addressCache after initialization.
			*
			* The unitialized state of the localHost's address is -1,
			* or IP address 255.255.255.255 which we know cannot be
			* a legal host address.
			*/
			localHost->mAddress = -1;
		} 
		catch (Exception&)
		{
			*localHost = *unknownAddress;
		}
	}

	void InetAddress::terminate()
	{
		delete loopbackHost;
		delete localHost;
		delete unknownAddress;
		delete impl;
	}

	InetAddress::InetAddress()
	{
		mFamily  = impl->getInetFamily();
		mAddress = 0;
	}

	InetAddress::InetAddress(const WString& hostName, const char* addr)
	{
		mHostName = hostName;
		mFamily   = impl->getInetFamily();

		// we must be careful here to maintain the network byte order
		// of the address. As it comes, the most significant byte of the
		// address is in addr[0]. It actually doesn;t matter what order they end
		// up in the array as long as it is documented and consistent.

		mAddress = addr[3] & 0xff;
		mAddress |= ((addr[2] << 8)  & 0xff00);
		mAddress |= ((addr[1] << 16)  & 0xff0000);
		mAddress |= ((addr[0] << 24)  & 0xff000000);
	}

	// IP multicast address is a class D address i.e. first four bits of the
	// address are 1110

	bool InetAddress::isMulticastAddress() const
	{
		return ((mAddress & 0xf0000000) == 0xe0000000);
	}

	WString InetAddress::getHostName() 
	{
		if (mHostName.length() == 0)
		{
			// first lookup the hostname
			mHostName = impl->getHostByAddr(mAddress);
			// now get all the IP addresses for this hostname
			// and make sure one of them matches the original IP address
			// we do this to try and prevent spoofing
			std::vector<InetAddress> arr = getAllByName0(mHostName);
			bool ok = false;

			for (unsigned int i=0; !ok && i < arr.size();i++)
			{
				ok = (mAddress == arr[i].mAddress);
			}
			// if it looks a spoof just return the address?
			if (!ok)
			{
				mHostName = getHostAddress();
				return mHostName;
			}
		}
		return mHostName;
	}

	WString InetAddress::getHostAddress() const
	{
		return WString::valueOf((mAddress >> 24) & 0xff) + chPeriod +
			WString::valueOf((mAddress >> 16) & 0xff) + chPeriod +
			WString::valueOf((mAddress >> 8)  & 0xff) + chPeriod +
			WString::valueOf((mAddress >> 0)  & 0xff);		   
	}

	std::vector<unsigned char>  InetAddress::getAddress() const
	{
		std::vector<unsigned char> addr;

		addr.push_back((mAddress >> 24) & 0xff);
		addr.push_back((mAddress >> 16) & 0xff);
		addr.push_back((mAddress >> 8)  & 0xff);
		addr.push_back((mAddress >> 0)  & 0xff);
		return addr;
	}

	WString InetAddress::toString() 
	{
		return this->getHostName() + chForwardSlash + this->getHostAddress();
	}

	static bool isDigit(JDFCh ch)
	{
		return (chDigit_0 <= ch && ch <= chDigit_9);
	}

	InetAddress InetAddress::getByName(const WString& host)
	{
		//	std::cout<<"InetAddress InetAddress::getByName(const WString& host) entered."<<std::endl;
		if (host.length() == 0)
			return *loopbackHost;
		if (!isDigit(host[0]))
		{
			//	std::cout<<"InetAddress InetAddress::getByName(const WString& host) before getAllByName0(host);."<<std::endl;
			std::vector<InetAddress> v = getAllByName0(host);
			return v[0];
		}

		int a=-1,b=-1,c=-1,d=-1;
		//	std::cout<<"InetAddress InetAddress::getByName(const WString& host) before scanf."<<std::endl;
#if defined(swscanf) || defined(WIN32)
		int err = swscanf(host.data(),L"%d.%d.%d.%d",&a,&b,&c,&d);
#else
		int err = sscanf(host.getBytes(),"%d.%d.%d.%d",&a,&b,&c,&d);
#endif
		//std::cout<<"InetAddress InetAddress::getByName(const WString& host) after scanf."<<std::endl;
		if (!err || err == EOF || a==-1 || b==-1 || c==-1 || d==-1)
		{
			std::vector<InetAddress> v = getAllByName0(host);
			return v[0];
		}
		int IP = 0;
		// 160903 RP swapped abcd with dcba 
		IP  = ((d << 0)   & 0xff);
		IP |= ((c << 8)   & 0xff00);
		IP |= ((b << 16)  & 0xff0000);
		IP |= ((a << 24)  & 0xff000000);

		InetAddress in;
		in.mAddress = IP;
		return in;
	}

	std::vector<InetAddress> InetAddress::getAllByName(const WString& hostName)
	{
		if (hostName.length() == 0)
			throw UnknownHostException("InetAddress::getAllByName empty hostName string");

		if (!isDigit(hostName[0]))
		{
			std::vector<InetAddress> ret;
			ret.push_back(getByName(hostName));
			return ret;
		}
		else
			return getAllByName0(hostName);
	}

	std::vector<InetAddress> InetAddress::getAllByName0(const WString& hostName)
	{
		//	printf ("std::vector<InetAddress> InetAddress::getAllByName0(const WString& hostName) entered");
		std::vector<InetAddress> obj;

		// TODO
		// first look in cache
		//
		// if not found lookup in name service

		obj = getAddressFromNameService(hostName);
		if (obj.size())
		{
			if (obj[0] == *unknownAddress)
				throw UnknownHostException(hostName);
		}
		//	printf ("std::vector<InetAddress> InetAddress::getAllByName0(const WString& hostName) leaved.");
		return obj;
	}

	std::vector<InetAddress> InetAddress::getAddressFromNameService(const WString& hostName)
	{
		//	printf("std::vector<InetAddress> InetAddress::getAddressFromNameService(const WString& hostName) entered\n");
		std::vector<std::string> hostAddresses;
		std::vector<InetAddress> ret;

		//	printf("std::vector<InetAddress> InetAddress::getAddressFromNameService(const WString& hostName) before impl->lookupAllHostAddr(hostName);\n");
		hostAddresses = impl->lookupAllHostAddr(hostName);
		//	printf("std::vector<InetAddress> InetAddress::getAddressFromNameService(const WString& hostName) after impl->lookupAllHostAddr(hostName);\n");
		if (hostAddresses.size() == 0)
		{
			ret.push_back(*unknownAddress);
			return ret;
		}
		for (unsigned int i=0;i<hostAddresses.size();i++)
		{
			//		printf("Addr%d: %s\n",i,hostAddresses[i].c_str());
			ret.push_back(InetAddress(hostName,hostAddresses[i].c_str()));
		}
		// add to cache

		return ret;
	}

	InetAddress InetAddress::getLocalHost()
	{
		Synchronized sync(PlatformUtils::gSingletonMutex());

		if (*localHost == *unknownAddress)
			throw UnknownHostException();

		if (localHost->mAddress  == -1)
		{
			*localHost = getAllByName(localHost->mHostName)[0];
		}
		return *localHost;
	}

	InetAddress::InetAddress(const InetAddress& addr)
	{
		mHostName = addr.mHostName;
		mAddress = addr.mAddress;
		mFamily = addr.mFamily;
	}

	InetAddress& InetAddress::operator=(const InetAddress& addr)
	{
		if(&addr == this)
			return *this;

		mHostName = addr.mHostName;
		mAddress = addr.mAddress;
		mFamily = addr.mFamily;
		return *this;
	}

} // namespace JDF

/* end of file */
