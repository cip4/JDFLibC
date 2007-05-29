/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2007 The International Cooperation for the Integration of 
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

#include "PlatformUtils.h"

#include "hmap.h"
#include "hashfun.h"

#include "RegisterCleanup.h"

#include <jdf/mime/MIMEBodyPart.h>
#include <jdf/mime/MimeTableFileNameMap.h>
#include <jdf/net/Socket.h>
#include <jdf/net/ServerSocket.h>
#include <jdf/net/SocketFactoryService.h>
#include <jdf/net/Authenticator.h>
#include <jdf/net/PlainURLStreamHandlerFactory.h>
#include <jdf/net/URLConnection.h>
#include <jdf/io/File.h>

#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/TransService.hpp>


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

	SocketFactoryService* PlatformUtils::fgSocketFactoryService = NULL;
	FileSystem* PlatformUtils::fs = NULL;

	typedef hmap<WString,WString,ElfHash> Properties;
	typedef hmap<WString,WString,ElfHash>:: iterator  PropertiesIterator;

	static Properties* systemProperties;
	static bool mustDeInitXML=false;
	static int utilsInitialized=0;

	static Mutex* singletonMutex = 0;
	static RegisterCleanup singletonMutexCleanup;


	// ---------------------------------------------------------------------------
	//  Global data
	//
	//	gJDFCleanupList
	//		This is a list of cleanup functions to be called on 
	//		XMLPlatformUtils::Terminate.  Their function is to reset static
	//		data in classes that use it.
	//
	//	gJDFCleanupListMutex
	//		This is a mutex that will be used to synchronise access to the global
	//		static data cleanup list
	// ---------------------------------------------------------------------------
	RegisterCleanup*	gJDFCleanupList = 0;
	Mutex*				gJDFCleanupListMutex = 0;

	void PlatformUtils::Initialize()
	{
		if(utilsInitialized++)
			return;

		//
		//  Call the platform init method, which is implemented in each of the
		//  per-platform implementation cpp files. This one does the very low
		//  level per-platform setup. It cannot use any XML util services at all,
		//  i.e. only native services.
		//
		platformInit();
		void *ppp=XMLPlatformUtils::fgTransService;
		if(ppp==0){
			try{
				XMLPlatformUtils::Initialize();
				mustDeInitXML=true;
			}catch(const XMLException&){
				throw;
			}
		}
		// Create the mutex for the static data cleanup list
		gJDFCleanupListMutex = new Mutex;

		systemProperties = new Properties;

		XMLLCPTranscoder* defXCode = XMLPlatformUtils::fgTransService->makeNewLCPTranscoder();
		if (!defXCode)
			return;
		WString::initString(defXCode);

		// initialize the system properties
		SystemPropertiesInit();

		FileSystem* fs = makeFileSystem();
		File::initFile(fs);

		fgSocketFactoryService = makeSocketFactoryService();
		fgSocketFactoryService->initialize();

		SocketImplFactory* defSocketFactory = fgSocketFactoryService->createSocketImplFactory();
		Socket::setSocketImplFactory(defSocketFactory);

		SocketImplFactory* defServerSocketFactory = fgSocketFactoryService->createSocketImplFactory();
		ServerSocket::setSocketFactory(defServerSocketFactory);

		InetAddressImpl* impl = makeInetAddressImpl();
		InetAddress::setInetAddressImpl(impl);

		URLStreamHandlerFactory*  factory = new PlainURLStreamHandlerFactory();
		FileNameMap* filenameMap = new MimeTableFileNameMap();

		URLConnection::setFileNameMap(filenameMap);
		URL::setURLStreamHandlerFactory(factory);

		MIMEBodyPart::initMIMEBodyPart();

	}

	PlatformUtils::value_pair PlatformUtils::getProperty(const WString& key)
	{
		PropertiesIterator it = systemProperties->find(key);
		if (it != systemProperties->end())
		{
			return value_pair(true,(*it).second);
		}
		else
			return value_pair(false,"");
	}

	PlatformUtils::value_pair PlatformUtils::getProperty(const WString& key, const WString& def)
	{
		PropertiesIterator it = systemProperties->find(key);
		if (it != systemProperties->end())
		{
			return value_pair(true,(*it).second);
		}
		else
			return value_pair(true,def);
	}

	unsigned long PlatformUtils::getCurrentMillis()
	{
		return XMLPlatformUtils::getCurrentMillis();
	}

	void PlatformUtils::setProperty(WString key, WString value)
	{
		(*systemProperties)[key] = value;
	}

	Mutex& PlatformUtils::gSingletonMutex()
	{
		if (!singletonMutex)
		{
			Mutex* tmpMutex = new Mutex;
			if (XMLPlatformUtils::compareAndSwap((void**)&singletonMutex, tmpMutex, 0))
			{
				// Some other thread beat us to it, so let's clean up ours.
				delete tmpMutex;
			}
			else
			{
				singletonMutexCleanup.registerCleanup(PlatformUtils::reinitSingletonMutex);
			}

		}
		return *singletonMutex;
	}

	void PlatformUtils::Terminate()
	{
		if(--utilsInitialized!=0)
			return;

		MIMEBodyPart::terminateMIMEBodyPart();
		fgSocketFactoryService->terminate();

		delete fgSocketFactoryService;
		fgSocketFactoryService=0;

		URL::terminate();
		URLConnection::terminate();
		Authenticator::terminate();

		InetAddress::terminate();

		ServerSocket::terminate();
		Socket::terminate();
		File::terminate();
		delete systemProperties;
		systemProperties=0;

		WString::terminate();

		// Clean up statically allocated, lazily cleaned data in each class
		// that has registered for it.
		// Note that calling doCleanup() also unregisters the cleanup
		// function, so that we are chewing the list down to nothing here
		while (gJDFCleanupList)
			gJDFCleanupList->doCleanup();

		// Clean up the mutex for accessing gXMLCleanupList
		delete gJDFCleanupListMutex;
		gJDFCleanupListMutex = 0;

		//
		//  And do platform termination. This cannot do use any XML services
		//  at all, it can only clean up local stuff. It it reports an error,
		//  it cannot use any XML exception or error reporting services.
		//
		platformTerm();
		if(mustDeInitXML){
			XMLPlatformUtils::Terminate();
			mustDeInitXML=false;
		}

	}

	void PlatformUtils::reinitSingletonMutex()
	{
		delete singletonMutex;
		singletonMutex = 0;
	}

} // namespace JDF



