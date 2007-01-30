/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2006 The International Cooperation for the Integration of 
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

#include <jdf/io/InputStream.h>
#include <jdf/lang/Integer.h>
#include <jdf/lang/Synchronized.h>
#include <jdf/mime/FileNameMap.h>
#include <jdf/mime/FileMIMEType.h>
#include <jdf/lang/Exception.h>
#include <jdf/net/URLConnection.h>
#include <jdf/util/Unicode.h>
#include <jdf/util/PlatformUtils.h>


namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 


	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 

	bool URLConnection::defaultAllowUserInteraction = false;
	bool URLConnection::defaultUseCaches = true;

	FileNameMap* URLConnection::fileNameMap = NULL;

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


	// todo throw IllegalAccess Error
	// getDate

	URLConnection::URLConnection(const URL& url) 
	{
		this->url = url;
		connected = false;
		doInput   = true;
		doOutput  = false;
		useCaches = defaultUseCaches;
	}

	URLConnection::~URLConnection()
	{
	}

	void URLConnection::setAllowUserInteraction(bool allowuserinteraction)
	{
		//	if (connected)
		//	    throw IllegalAccessError("Already connected");
		allowUserInteraction = allowuserinteraction;
	}

	bool URLConnection::getAllowUserInteraction()
	{
		return allowUserInteraction;
	}

	WString URLConnection::getContentEncoding()
	{
		value_pair v  = getHeaderField(Unicode::URLCONTENTENCODING);
		return v.second;
	}

	int URLConnection::getContentLength()
	{
		return getHeaderFieldInt(Unicode::URLCONTENTLENGTH, -1);
	}

	WString URLConnection::getContentType()
	{
		value_pair v  = getHeaderField(Unicode::URLCONTENTTYPE);
		return v.second;
	}

	long URLConnection::getDate()
	{
		return 0;
		//	return getHeaderFieldDate("date", 0);
	}

	bool URLConnection::getDefaultAllowUserInteraction()
	{
		return defaultAllowUserInteraction;
	}

	void URLConnection::setDefaultAllowUserInteraction(bool defaultallowuserinteraction)
	{
		defaultAllowUserInteraction = defaultallowuserinteraction;
	}

	bool URLConnection::getDefaultUseCaches()
	{
		return defaultUseCaches;
	}

	void URLConnection::setDefaultUseCaches(bool defaultusecaches)
	{
		defaultUseCaches = defaultusecaches;
	}

	bool URLConnection::getDoInput()
	{
		return doInput;
	}

	bool URLConnection::getDoOutput()
	{
		return doOutput;
	}

	void URLConnection::setDoInput(bool doinput)
	{
		//	if (connected)
		//	    throw new IllegalAccessError("Already connected");
		doInput = doinput;
	}

	void URLConnection::setDoOutput(bool dooutput)
	{
		//	if (connected)
		//	    throw IllegalAccessError("Already connected");
		doOutput = dooutput;
	}

	bool URLConnection::getUseCaches()
	{
		return useCaches;
	}

	URL URLConnection::getURL()
	{
		return url;
	}

	long URLConnection::getLastModified()
	{
		return 0;
	}


	long URLConnection::getExpiration()
	{
		return 0;
		//	return getHeaderFieldDate("expires", 0);
	}

	URLConnection::value_pair URLConnection::getHeaderField(int n)
	{
		return value_pair(false,"");
	}

	URLConnection::value_pair URLConnection::getHeaderField(const WString& name)
	{
		return value_pair(false,"");
	}

	URLConnection::value_pair  URLConnection::getHeaderFieldKey(int n)
	{
		return value_pair(false,"");
	}

	int URLConnection::getHeaderFieldInt(const WString& name, int Default)
	{
		value_pair v = getHeaderField(name);
		if (v.first == false)
			return Default;
		return Integer::parseInt(v.second);
	}

	void URLConnection::setIfModifiedSince(long ifmodifiedsince) 
	{
		//	if (connected)
		//	    throw IllegalAccessError("Already connected");
		ifModifiedSince = ifmodifiedsince;
	} 

	long URLConnection::getIfModifiedSince()
	{
		return ifModifiedSince;
	}


	InputStream& URLConnection::getInputStream()
	{
		throw UnknownServiceException(L"protocol doesn't support input");
	}

	OutputStream& URLConnection::getOutputStream()
	{
		throw UnknownServiceException(L"protocol doesn't support output");
	}

	void URLConnection::setTimeout(int millis)
	{
		throw UnknownServiceException(L"protocol doesn't support setTimeout");

	}
	
	int URLConnection::getTimeout()
	{
		throw UnknownServiceException(L"protocol doesn't support getTimeout");
	}

	WString URLConnection::getRequestProperty(const WString& key)
	{
		//	if (connected)
		//		throw illegalAccessError("Already connected")
		return "";
	}

	void URLConnection::setRequestProperty(const WString& key, const WString& value)
	{
		//	if (connected)
		//	throw illegalAccessError("Already connected")
	}


	WString URLConnection::toString()
	{
		return WString(JDFStrL("URLConnection")) + ":" + url.toString();
	}

	void URLConnection::setUseCaches(bool usecaches)
	{
		//	if (connected)
		//	    throw new IllegalAccessError("Already connected");
		useCaches = usecaches;
	}

	FileNameMap* URLConnection::getFileNameMap()
	{
		return	fileNameMap;
	}

	void URLConnection::setFileNameMap(FileNameMap* map)
	{
		if (fileNameMap != map)
		{
			Synchronized sync(PlatformUtils::gSingletonMutex());
			if (fileNameMap)
				delete fileNameMap;
			fileNameMap = map;
		}
	}

	void URLConnection::terminate()
	{
		delete fileNameMap;
		fileNameMap = NULL;
	}

	WString URLConnection::guessContentTypeFromStream(InputStream& is)
	{
		is.mark(10);
		int c1 = is.read();
		int c2 = is.read();
		int c3 = is.read();
		int c4 = is.read();
		int c5 = is.read();
		int c6 = is.read();
		int c7 = is.read();
		int c8 = is.read();
		is.reset();
		if (c1 == 0xCA && c2 == 0xFE && c3 == 0xBA && c4 == 0xBE)
			return "application/java-vm";
		if (c1 == 0xAC && c2 == 0xED)
			// next two bytes are version number, currently 0x00 0x05
			return "application/x-java-serialized-object";
		if (c1 == 'G' && c2 == 'I' && c3 == 'F' && c4 == '8')
			return "image/gif";
		if (c1 == '#' && c2 == 'd' && c3 == 'e' && c4 == 'f')
			return "image/x-bitmap";
		if (c1 == '!' && c2 == ' ' && c3 == 'X' && c4 == 'P' && c5 == 'M' && c6 == '2')
			return "image/x-pixmap";
		if (c1 == 137 && c2 == 80 && c3 == 78 && 
			c4 == 71 && c5 == 13 && c6 == 10 &&
			c7 == 26 && c8 == 10)
			return "image/png";

		if (c1 == 0x2E && c2 == 0x73 && c3 == 0x6E && c4 == 0x64)
			return "audio/basic";  // .au format, big endian
		if (c1 == 0x64 && c2 == 0x6E && c3 == 0x73 && c4 == 0x2E)
			return "audio/basic";  // .au format, little endian
		if (c1 == '<') {
			if (c2 == '!'
				|| ((c2 == 'h' && (c3 == 't' && c4 == 'm' && c5 == 'l' ||
				c3 == 'e' && c4 == 'a' && c5 == 'd')
				|| c2 == 'b' && c3 == 'o' && c4 == 'd' && c5 == 'y'))
				|| ((c2 == 'H' && (c3 == 'T' && c4 == 'M' && c5 == 'L' ||
				c3 == 'E' && c4 == 'A' && c5 == 'D')
				|| c2 == 'B' && c3 == 'O' && c4 == 'D' && c5 == 'Y')))
				return "text/html";
			if (c2 == '?' && c3 == 'x' && c4 == 'm' && c5 == 'l' && c6 == ' ')
				return "application/xml";
		}

		// big and little endian UTF-16 encodings, with byte order mark
		if (c1 == 0xfe && c2 == 0xff) {
			if (c3 == 0 && c4 == '<' && c5 == 0 && c6 == '?' &&
				c7 == 0 && c8 == 'x')
				return "application/xml";
		}

		if (c1 == 0xff && c2 == 0xfe) {
			if (c3 == '<' && c4 == 0 && c5 == '?' && c6 == 0 &&
				c7 == 'x' && c8 == 0)
				return "application/xml";
		}

		if (c1 == 0xFF && c2 == 0xD8 && c3 == 0xFF && c4 == 0xE0)
			return "image/jpeg";
		if (c1 == 0xFF && c2 == 0xD8 && c3 == 0xFF && c4 == 0xEE)
			return "image/jpg";

		if (c1 == 'R' && c2 == 'I' && c3 == 'F' && c4 == 'F')
			/* I don't know if this is official but evidence
			* suggests that .wav files start with "RIFF" - brown
			*/
			return "audio/x-wav";  

		return "";
	}

	WString URLConnection::guessContentTypeFromName(WString fname) 
	{
		return getFileNameMap()->getContentTypeFor(fname).getContentType();
	}

} // namespace JDF
