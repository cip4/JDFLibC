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

#include "URL.h"

#include "URLStreamHandler.h"
#include "URLStreamHandlerFactory.h"

#include <jdf/lang/Exception.h>

#include <jdf/util/PlatformUtils.h>
#include <jdf/lang/Synchronized.h>
#include <jdf/lang/Integer.h>
#include <jdf/net/URI.h>

#include <xercesc/util/XMLUniDefs.hpp>
#include <string>

XERCES_CPP_NAMESPACE_USE

namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 


	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 

	URLStreamHandlerFactory* URL::mFactory = NULL;

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

	static bool isLetter(JDFCh ch)
	{
		return ( (chLatin_a <= ch && ch <= chLatin_z) ||
			(chLatin_A <= ch && ch <= chLatin_Z) );
	}

	static bool isDigit(JDFCh ch)
	{
		return (chDigit_0 <= ch && ch <= chDigit_9);
	}

	static bool isLetterOrDigit(JDFCh ch)
	{
		return isLetter(ch) || isDigit(ch);
	}


	URL::URL()  :
	mPort (-1)
	{
	}

	URL::URL(const WString& url) :
	mPort(-1)
	{
		try
		{
			setURL(url);
		}
		catch(...)
		{
			//		cleanup();
			throw;
		}

	}

	URL::URL(const WString& baseURL, const WString& relativeURL) :
	mPort(-1)
	{
		try
		{
			setURL(baseURL,relativeURL);
		}
		catch(...)
		{
			throw;
		}
	}

	URL::URL(const URL& baseURL, const WString& relativeURL) :
	mPort(-1)
	{
		try
		{
			setURL(baseURL,relativeURL);
		}
		catch(...)
		{
			throw;
		}
	}



	void URL::setURL(const WString& url)
	{
		parse(url);
	}


	void URL::setURL(const URL& baseURL, const WString& relativeURL)
	{
		// parse our URL string
		parse(relativeURL);
		// If its relative, then conglomerate with the base URL
		if (isRelative())
			conglomerateWithBase(baseURL);
	}

	void URL::setURL(const WString& baseURL, const WString& relativeURL)
	{
		// parse our URL string
		parse(relativeURL);

		//
		//  If its relative and the base is non-null and non-empty, then
		//  parse the base URL string and conglomerate them.
		//
		if (isRelative() && !baseURL.empty() )
		{
			URL basePart(baseURL);
			if (!conglomerateWithBase(basePart))
			{
				//cleanup();
				throw MalformedURLException(JDFStrL("relative URL could not be merged with base"));
			}
		}
	}

	bool URL::isRelative() const
	{
		// If no protocol then relative
		if (mProtocol.empty())
			return true;

		// If no path, or the path is not absolute, then relative
		if (mPath.empty())
			return true;

		if (mPath[0] != chForwardSlash)
			return true;

		return false;
	}

	bool URL::conglomerateWithBase(const URL& baseURL)
	{
		// the base URL cannot be relative

		if (baseURL.isRelative())
			return false;

		//
		//  Check a special case. If all we have is a fragment, then we want
		//  to just take the base host and path, plus our fragment.
		//
		if (mProtocol.empty() 
			&& mHost.empty() && mPath.empty() && mFragment.empty())
		{
			mProtocol = baseURL.mProtocol;
			mPort     = baseURL.mPort;
			mHost     = baseURL.mHost;
			mUser     = baseURL.mUser;
			mPassword = baseURL.mPassword;
			mPath     = baseURL.mPath;
			mFile	  = baseURL.mFile;
			return true;
		}
		//
		//  All we have to do is run up through our fields and, for each one
		//  that we don't have, use the based URL's. Once we hit one field
		//  that we have, we stop.
		//
		if (!mProtocol.empty())
			return true;
		mProtocol = baseURL.mProtocol;

		//
		//  If the protocol is not file, and we either already have our own
		//  host, or the base does not have one, then we are done.
		//
		if (!mProtocol.equalsIgnoreCase(JDFStrL("File")))
		{
			if (!mHost.empty() || baseURL.mHost.empty())
				return true;
		}

		// Replicate all of the hosty stuff if the base has one
		if (!baseURL.mHost.empty())
		{
			mUser     = baseURL.mUser;
			mPassword = baseURL.mPassword;
			mHost     = baseURL.mHost;
			mPort     = baseURL.mPort;
			mFile	  = baseURL.mFile;
		}

		// If we have a path and its absolute, then we are done
		const bool hadPath = !mPath.empty();
		if (hadPath)
		{
			if (mPath[0] == chForwardSlash)
				return true;
		}

		// Its a relative path, so weave them together.
		if (!baseURL.mPath.empty())
		{
			WString temp = PlatformUtils::weavePaths(baseURL.mPath, mPath);
			mPath = temp;
		}

		// If we had any original path, then we are done
		if (hadPath)
			return true;

		// We had no original path, so go on to deal with the query/fragment parts
		if (!mQuery.empty() || baseURL.mQuery.empty())
			return true;
		mQuery = baseURL.mQuery;

		if (!mFragment.empty() || baseURL.mFragment.empty())
			return true;
		mFragment = baseURL.mFragment;
		return true;
	}




	void URL::parse(WString url)
	{
		if (url.length() == 0)
			throw MalformedURLException(JDFStrL("no protocol present"));

		// TODO validate URL;

		//
		//  The first thing we will do is to check for a file name, so that
		//  we don't waste time thinking its a URL. If its in the form x:\
		//  or x:/ and x is an ASCII letter, then assume that's the deal.
		//

		if (url.length() >=2)
		{
			if (((url[0] >= chLatin_A) && (url[0] <= chLatin_Z))
				||  ((url[0] >= chLatin_a) && (url[0] <= chLatin_z)))
			{
				if (url[1] == chColon)
				{
					if ((url[2] == chForwardSlash)
						||  (url[2] == chBackSlash))
					{
						throw MalformedURLException(JDFStrL("no protocol present"));
					}
				}
			}
		}

		int start =0;
		int end = url.length();

		// Run up past any spaces
		while ( (end > 0) && (url[end-1] <= chSpace))
			end--; // eliminate trailing whitespace
		while ((start < end) && (url[start] <= chSpace))
			start++; //eliminate leading whitespace


		// Make sure it wasn't all space
		if (start == end)
			throw MalformedURLException(JDFStrL("no protocol present"));


		//
		//  Ok, the next thing we have to do is to find either a / or : character.
		//  If the : is first, we assume we have a protocol. If the / is first,
		//  then we skip to the host processing.
		//
		static const JDFCh listOne[]    = { chColon, chForwardSlash, chNull };
		static const JDFCh listTwo[]    = { chAt, chNull };
		static const JDFCh listThree[]  = { chColon, chNull };
		static const JDFCh listFour[]   = { chForwardSlash, chNull };
		static const JDFCh listFive[]   = { chPound, chQuestion, chNull };
		static const JDFCh listSix[]    = { chPound, chNull };
		int  ptr1  = url.find_first_of(listOne,start);
		int ptr2;

		// If we found a protocol, then deal with it
		if (ptr1 != -1)
		{
			if (url[ptr1] == chColon)
			{
				mProtocol = WString(url,start,ptr1-start);
				mHandler = getURLStreamHandler(mProtocol);

				if (mHandler.get() == NULL)
					throw MalformedURLException(JDFStrL("Unsupported protocol"));
				// And move our source pointer up past what we've processed
				start = (ptr1 + 1);
			}
		}

		//
		//  Ok, next we need to see if we have any host part. If the next
		//  two characters are //, then we need to check, else move on.
		//
		if ((url[start] == chForwardSlash) && (url[start + 1] == chForwardSlash))
		{
			// Move up past the slashes
			start += 2;

			//
			//  If we aren't at the end of the string, then there has to be a
			//  host part at this point. we will just look for the next / char
			//  or end of string and make all of that the host for now.
			//
			if (start <= end)
			{
				// Search from here for a / character
				ptr1 = url.find_first_of(listFour,start);

				//
				//  If we found something, then the host is between where
				//  we are and what we found. Else the host is the rest of
				//  the content and we are done. If its empty, leave it null.
				//
				if (ptr1 != -1)
				{
					if (ptr1 != start)
					{
						mHost = WString(url,start,ptr1-start);
						start = ptr1;
					}
				}
				else
				{
					mHost = WString(url,start,end-start);
					// Update source pointer to the end
					start =end;
				}
			}
		}
		else
		{
			//
			// http protocol requires two forward slashes
			// we didn't get them, so throw an exception
			//
			//        if (fProtocol == HTTP) {
			//          ThrowXML
			//            (
			//              MalformedURLException
			//            , XMLExcepts::URL_ExpectingTwoSlashes
			//      );
			//        }
		}

		//
		//  If there was a host part, then we have to grovel through it for
		//  all the bits and pieces it can hold.
		//
		if (mHost.length())
		{
			//
			//  Look for a '@' character, which indicates a user name. If we
			//  find one, then everything between the start of the host data
			//  and the character is the user name.
			//
			ptr1 = mHost.find_first_of(listTwo);
			if (ptr1 != -1)
			{
				// Get this info out as the user name
				if (ptr1) 
					mUser = mHost.substring(0,ptr1);
				ptr1++;

				// And now cut these chars from the host string
				mHost = mHost.substring(ptr1,mHost.length());

				// Is there a password inside the user string?
				ptr2 = mUser.find_first_of(listThree);
				if (ptr2 != -1)
				{
					// And copy out the remainder to the password field
					mPassword = mUser.substring(ptr2+1);
					// Remove it from the user name string
					mUser = mUser.substring(0,ptr2);
				}
			}

			//
			//  Ok, so now we are at the actual host name, if any. If we are
			//  not at the end of the host data, then lets see if we have a
			//  port trailing the
			//
			ptr1 =mHost.find_first_of(listThree);
			if (ptr1 != -1)
			{
				// Try to convert it to a numeric port value and store it
				ptr1++;
				mPort = Integer::valueOf(mHost.substring(ptr1)).intValue();
				// Remove it from the host name
				if (ptr1 > 0)
					mHost = mHost.substring(0,ptr1-1);
				else
					mHost = "";
			}

			// If the host ended up empty, then toss is
			if (mHost.empty())
			{
			}
		}

		// If we are at the end, then we are done now
		if (start ==end)
		{
			return;
		}

		//
		//  Next is the path part. It can be absolute, i.e. starting with a
		//  forward slash character, or relative. Its basically everything up
		//  to the end of the string or to any trailing query or fragment.
		//
		ptr1 =url.find_first_of(listFive,start);
		if (ptr1== -1)
		{
			mPath = url.substring(start);
			mFile = mPath;
			return;
		}

		// Everything from where we are to what we found is the path
		if (ptr1 > start)
		{
			mPath = url.substring(start,ptr1);
			mFile = mPath;
			start = ptr1;
		}

		//
		//  If we found a fragment, then it is the rest of the string and we
		//  are done.
		//
		if (url[start] == chPound)
		{
			start++;
			mFragment = url.substring(start);
			return;
		}

		//
		//  The query is either the rest of the string, or up to the fragment
		//  separator.
		//
		start++;
		ptr1 = url.find_first_of(listSix, start);
		if (ptr1 == -1)
		{
			mQuery = url.substring(start);
			return;
		}
		else
		{
			mQuery = url.substring(start,ptr1);
			start = ptr1;

		}

		// If we are not at the end now, then everything else is the fragment
		if ( url[start] == chPound)
		{
			start++;
			mFragment = url.substring(start);
		}
	}



	URL::URL(const URL& url)
	{
		mProtocol	= url.mProtocol;
		mHost		= url.mHost;
		mPort		= url.mPort;
		mQuery		= url.mQuery;
		mAuthority	= url.mAuthority;
		mPath		= url.mPath;
		mUser		= url.mUser;
		mPassword   = url.mPassword;
		mFragment	= url.mFragment;
		mHandler	= url.mHandler;
		mFile       = url.mFile;
	}

	URL& URL::operator=(const URL& url)
	{
		if(&url == this)
			return *this;

		mProtocol	= url.mProtocol;
		mHost		= url.mHost;
		mPort		= url.mPort;
		mFile		= url.mFile;
		mQuery		= url.mQuery;
		mAuthority	= url.mAuthority;
		mPath		= url.mPath;
		mUser		= url.mUser;
		mPassword   = url.mPassword;
		mFragment	= url.mFragment;
		mHandler	= url.mHandler;

		return *this;
	}

	/*



	URL::URL()
	{
	mPort		= -1;
	}



	*/

	URL::URL(WString protocol, WString host, int port, WString file) 
	{
		initialize(protocol,host, port, file, NULL);
	}

	URL::URL(WString protocol, WString host, int port, WString file, URLStreamHandler* handler)
	{
		initialize(protocol, host, port, file, handler);
	}

	URL::URL(WString protocol, WString host, WString file)
	{
		initialize(protocol, host, -1, file, NULL);
	}



	void URL::create(const WString& url)
	{
		setURL(url);
	}

	void URL::create(WString protocol, WString host, int port, WString file)
	{
		initialize(protocol,host, port, file, NULL);
	}

	void URL::create(WString protocol, WString host, int port, WString file, URLStreamHandler* handler)
	{
		initialize(protocol, host, port, file, handler);
	}

	void URL::create(WString protocol, WString host, WString file)
	{
		initialize(protocol, host, -1, file, NULL);
	}

	void URL::initialize(WString protocol, WString host, int port, WString file, URLStreamHandler* handler)
	{
		mProtocol = protocol;
		mHost     = host;
		int ind = file.find_first_of(chPound); // '#'
		if (ind == WString::npos)
		{
			mFile = file;
			mFragment  = "";
		}
		else
		{
			mFile = file.substring(0,ind);
			mFragment  = file.substring(ind+1,file.length());
		}
		int q = file.find_last_of(chQuestion); // '?'
		if (q != WString::npos)
		{
			mQuery = mFile.substring(q+1,mFile.length());
			mPath  = mFile.substring(0,q);
		}
		else
			mPath = mFile;

		if (handler == NULL &&
			(handler = getURLStreamHandler(protocol)) == NULL)
		{
			//		throw MalformedURLException(JDFStrL("unknown protocol") + protocol);
		}

		mHandler = handler;
		mPort    = port;

		if (host.length())
		{
			mAuthority = (port == -1) ? host : host + ":" + WString::valueOf(port);
		}
		parse(toString());
	}

	URL::URL(WString protocol, WString opaquePart, WString userInfo, WString host, int port, WString path, WString query, WString fragment, URLStreamHandler* handler)
	{
		mProtocol = protocol.toLowerCase();
		if (!opaquePart.empty())
		{
			mPath = path;
			mFile = path;
		}
		else
		{
			if (!host.empty())
			{
				mUser = userInfo;
				// Is there a password inside the user string?
				int ptr2 = mUser.find_first_of(chColon);
				if (ptr2 != -1)
				{
					// And copy out the remainder to the password field
					mPassword = mUser.substring(ptr2+1);
					// Remove it from the user name string
					mUser = mUser.substring(0,ptr2);
				}
			}
			mHost =host;
			mPort =port;
			if (port < -1)
				throw  MalformedURLException(JDFStrL("Invalid port number :"));
			mPath = path;
			mQuery = query;
			if (!mQuery.empty())
				mFile = mPath + chQuestion + mQuery;
			else
				mFile = mPath;
		}
		mFragment = fragment;
		if (handler == NULL &&
			(handler = getURLStreamHandler(protocol)) == NULL)
		{
			//		throw MalformedURLException(JDFStrL("unknown protocol") + protocol);
		}
		parse(toString());

	}


	bool URL::isValidProtocol(WString protocol)
	{
		int len = protocol.length();

		if (len < 1)
			return false;
		char c = protocol[0];
		if (!isLetter(c))
			return false;

		for (int i = 1; i < len; i++)
		{
			c = protocol[i];
			if (!isLetterOrDigit(c) && c != chPeriod && c != chPlus && c != chDash)
				return false;
		}
		return true;
	}


	WString URL::getAuthority() const
	{
		WString authority;
		if (mHost.length())
		{
			authority = (mPort == -1) ? mHost : mHost + ":" + WString::valueOf(mPort);
		}
		return authority;
	}

	WString URL::getFile() const
	{
		return mFile;
	}

	WString URL::getHost() const
	{
		return mHost;
	}

	WString URL::getPath() const
	{
		return mPath;
	}

	int URL::getPort() const
	{
		return mPort;
	}

	WString URL::getProtocol() const 
	{
		return mProtocol;
	}

	WString URL::getQuery() const
	{
		return mQuery;
	}

	WString URL::getRef() const
	{
		return mFragment;
	}

	WString URL::getUser() const
	{
		return mUser;
	}

	WString URL::getPassword() const
	{
		return mPassword;
	}

	void URL::setURLStreamHandlerFactory(URLStreamHandlerFactory* fac)
	{
		if (fac != NULL)
		{
			Synchronized sync(PlatformUtils::gSingletonMutex());
			if (mFactory)
				delete mFactory;
			mFactory = fac;
		}
	}

	void URL::terminate()
	{
		delete mFactory;
		mFactory = NULL;
	}

	URLStreamHandler* URL::getURLStreamHandler(WString protocol)
	{
		Synchronized sync(PlatformUtils::gSingletonMutex());

		if (mFactory)
		{
			return mFactory->createURLStreamHandler(protocol);
		}
		else
			return NULL;
	}

	WString URL::toExternalForm() const
	{
		WString URLText;

		if (!mProtocol.empty())
		{
			URLText.append(mProtocol);
			URLText.append(chColon);
			URLText.append(chForwardSlash);
			URLText.append(chForwardSlash);
		}
		if (!mUser.empty())
		{
			URLText.append(mUser);
			if (!mPassword.empty())
			{
				URLText.append(chColon);
				URLText.append(mPassword);
			}
			URLText.append(chAt);
		}
		if (!mHost.empty())
		{
			URLText.append(mHost);
			//
			//  If the port is zero, then we don't put it in. Else we need
			//  to because it was explicitly provided.
			//
			if (mPort>0)
			{
				URLText.append(chColon);
				URLText.append(WString::valueOf(mPort));
			}

		}
		if (!mPath.empty())
		{
			URLText.append(mPath);
		}
		if (!mQuery.empty())
		{
			URLText.append(chQuestion);
			URLText.append(mQuery);
		}
		if (!mFragment.empty())
		{	
			URLText.append(chPound);
			URLText.append(mFragment);
		}
		return URLText;
		//	return mHandler->toExternalForm(*this);
	}

	WString URL::toString() const
	{
		return toExternalForm();
	}

	URLConnection* URL::openConnection()
	{
		return mHandler->openConnection(*this);
	}

	void URL::makeRelativeTo(const WString& baseURL)
	{
		// If this one is not relative, don't bother
		if (!isRelative())
			return;

		URL base(baseURL);
		conglomerateWithBase(base);
	}

	void URL::makeRelativeTo(const URL& baseURL)
	{
		// If this one is not relative, don't bother
		if (!isRelative())
			return;
		conglomerateWithBase(baseURL);
	}

	URI URL::toURI() const
	{
		return URI(toString());
	}



	/*
	WString URL::filenameToURI(WString str)
	{

	// handle platform dependent strings
	str = str.replaceChar(File::separatorChar(), chForwardSlash);

	// Windows fix
	if (str.length() >= 2) {
	if (str[1] == chColon) 
	{
	if (isLetter(str[0]))
	str.insert((WString::size_type)0,1,chForwardSlash);
	}
	}

	// done
	return str;
	}

	URL URL::fileToURL(File file)
	{
	// convert path to URI
	WString path = filenameToURI(file.getCanonicalPath());
	//encode path 
	path = ParseUtil::encodePath(path);

	return URL(JDFStrL("file"),JDFStrL(""),path);
	}
	*/


} // namespace JDF
