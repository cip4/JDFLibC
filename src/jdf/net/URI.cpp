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

#include "jdf/net/URI.h"
#include "jdf/net/URLEncoder.h"
#include "jdf/net/URLDecoder.h"
#include <jdf/lang/Exception.h>
#include <jdf/util/PlatformUtils.h>
#include <jdf/lang/Integer.h>
#include "jdf/net/URL.h"
#include <xercesc/util/XMLUniDefs.hpp>


XERCES_CPP_NAMESPACE_USE

namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 


	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 


	//      Amended by RFC2732
	//      reserved      = ";" | "/" | "?" | ":" | "@" | "&" | "=" | "+" |
	//                      "$" | "," | "[" | "]"
	//
	const JDFCh URI::RESERVED_CHARACTERS[] =
	{
		chSemiColon, chForwardSlash, chQuestion, chColon, chAt,
			chAmpersand, chEqual, chPlus, chDollarSign, chComma, chOpenSquare,
			chCloseSquare, chNull
	};

	//
	//      mark          = "-" | "_" | "." | "!" | "~" | "*" | "'" |
	//                      "(" | ")"
	//
	const JDFCh URI::MARK_CHARACTERS[] =
	{
		chDash, chUnderscore, chPeriod, chBang, chTilde,
			chAsterisk, chSingleQuote, chOpenParen, chCloseParen, chNull
	};


	const JDFCh URI::MARK_OR_RESERVED_CHARACTERS[] =
	{
		chDash, chUnderscore, chPeriod, chBang, chTilde,
			chAsterisk, chSingleQuote, chOpenParen, chCloseParen,
			chSemiColon, chForwardSlash, chQuestion, chColon, chAt,
			chAmpersand, chEqual, chPlus, chDollarSign, chComma, chOpenSquare,
			chCloseSquare, chNull
	};

	//
	//      scheme        = alpha *( alpha | digit | "+" | "-" | "." )
	//
	const JDFCh URI::SCHEME_CHARACTERS[] =
	{
		chPlus, chDash, chPeriod, chNull
	};

	//
	//      userinfo      = *( unreserved | escaped |
	//                         ";" | ":" | "&" | "=" | "+" | "$" | "," )
	//
	const JDFCh URI::USERINFO_CHARACTERS[] =
	{
		chSemiColon, chColon, chAmpersand, chEqual, chPlus,
			chDollarSign, chPeriod, chNull
	};

	//
	//      reg_name     = 1*( unreserved | escaped | "$" | "," |
	//                         ";" | ":" | "@" | "&" | "=" | "+" )
	//
	const JDFCh URI::REG_NAME_CHARACTERS[] =
	{
		chDollarSign, chComma, chSemiColon, chColon, chAt,
			chAmpersand, chEqual, chPlus, chNull
	};

	//      pchar plus ';' and '/'.
	//      pchar         = unreserved | escaped |
	//                      ":" | "@" | "&" | "=" | "+" | "$" | ","
	const JDFCh URI::PATH_CHARACTERS[] =
	{
		chSemiColon, chForwardSlash, chColon, chAt, chAmpersand, 
			chEqual, chPlus, chDollarSign, chComma, chNull
	};

	// ---------------------------------------------------------------------------
	//  Local methods and data
	// ---------------------------------------------------------------------------
	// static const int BUF_LEN = 64;
	// static JDFCh value1[BUF_LEN+1];

	//
	// "Scheme"
	// "SchemeSpecificPart"
	// "Parameters"
	// "UserInfo"
	// "Host"
	// "Port"
	// "Path"
	// "Query"
	// "Fragment"
	//
	static const JDFCh errMsg_SCHEME[] =
	{
		chLatin_S, chLatin_c, chLatin_h, chLatin_e,
			chLatin_m, chLatin_e, chNull
	};

	static const JDFCh errMsg_SCHEMESPART[] =
	{
		chLatin_S, chLatin_c, chLatin_h, chLatin_e, chLatin_m, chLatin_e,
			chLatin_S, chLatin_p, chLatin_e, chLatin_c, chLatin_i, chLatin_f,
			chLatin_i, chLatin_c, chLatin_P, chLatin_a, chLatin_r, chLatin_t,
			chNull
	};

	static const JDFCh errMsg_PARAMS[] =
	{
		chLatin_P, chLatin_a, chLatin_r, chLatin_a, chLatin_m,
			chLatin_e, chLatin_t, chLatin_e, chLatin_r, chLatin_s, chNull
	};

	static const JDFCh errMsg_USERINFO[] =
	{
		chLatin_U, chLatin_s, chLatin_e, chLatin_r,
			chLatin_i, chLatin_n, chLatin_f, chLatin_o, chNull
	};

	static const JDFCh errMsg_HOST[] =
	{
		chLatin_H, chLatin_o, chLatin_s, chLatin_t, chNull
	};

	static const JDFCh errMsg_PORT[] =
	{
		chLatin_P, chLatin_o, chLatin_r, chLatin_t, chNull
	};

	static const JDFCh errMsg_REGNAME[] =
	{
		chLatin_R, chLatin_e, chLatin_g, 
			chLatin_N, chLatin_a, chLatin_m, chLatin_e, chNull
	};

	static const JDFCh errMsg_PATH[] =
	{
		chLatin_P, chLatin_a, chLatin_t, chLatin_h, chNull
	};

	static const JDFCh errMsg_QUERY[] =
	{
		chLatin_Q, chLatin_u, chLatin_e, chLatin_r, chLatin_y, chNull
	};

	static const JDFCh errMsg_FRAGMENT[] =
	{
		chLatin_F, chLatin_r, chLatin_a, chLatin_g,
			chLatin_m, chLatin_e, chLatin_n, chLatin_t, chNull
	};

	//
	//  "//"
	//  "/"
	//  "./"
	//  "/."
	//  "/../"
	//  "/.."
	//
	static const JDFCh DOUBLE_SLASH[] =
	{
		chForwardSlash, chForwardSlash, chNull
	};

	static const JDFCh SINGLE_SLASH[] =
	{
		chForwardSlash, chNull
	};

	static const JDFCh SLASH_DOT_SLASH[] =
	{
		chForwardSlash, chPeriod, chForwardSlash, chNull
	};

	static const JDFCh SLASH_DOT[] =
	{
		chForwardSlash, chPeriod, chNull
	};

	static const JDFCh SLASH_DOTDOT_SLASH[] =
	{
		chForwardSlash, chPeriod, chPeriod, chForwardSlash, chNull
	};

	static const JDFCh SLASH_DOTDOT[] =
	{
		chForwardSlash, chPeriod, chPeriod, chNull
	};

	//
	//  ":/?#"
	//
	// REVISIT: why?
	static const JDFCh SCHEME_SEPARATORS[] =
	{
		chColon, chForwardSlash, chQuestion, chPound, chNull
	};

	//
	//  "?#"
	//
	static const JDFCh PATH_SEPARATORS[] =
	{
		chQuestion, chPound, chNull
	};

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

	URI::URI(const WString& uriSpec) :
		mPort(-1)
		{
			try
			{
				initialize(NULL,uriSpec);
			} 
			catch (...)
			{
				throw MalformedURLException(L"URI error initializing: "+uriSpec);
			}
		}

		URI::URI(const URI& baseURI,const WString& uriSpec) :
		mPort(-1)
		{
			try
			{
				initialize(&baseURI,uriSpec);
			} 
			catch (...)
			{
				throw;
			}
		}

		URI::URI(const URI& uri) :
		mPort(-1)
		{
			initialize(uri);
		}

		URI& URI::operator=(const URI& uri)
		{
			initialize(uri);
			return *this;
		}



		URI::~URI()
		{
		}

		void URI::initialize(const URI& uri)
		{
			mScheme      = uri.mScheme;
			mUserInfo    = uri.mUserInfo;
			mHost        = uri.mHost;
			mPort        = uri.mPort;
			mPath	     = uri.mPath;
			mQueryString = uri.mQueryString;
			mFragment    = uri.mFragment;
			mDecodedUserInfo    = uri.mDecodedUserInfo;
			mDecodedHost        = uri.mDecodedHost;
			mDecodedPath        = uri.mDecodedPath;
			mDecodedQueryString = uri.mDecodedQueryString;
			mDecodedFragment    = uri.mDecodedFragment;
			//	mOpaque		 = uri.mOpaque;
			//	mAbsolute	 = uri.mAbsolute;
		}

		void URI::initialize(const URI* baseURI, const WString& uriSpec)
		{
			WString trimedUriSpec = uriSpec.trim();

			if (!baseURI && trimedUriSpec.length() == 0)
				throw MalformedURLException(JDFStrL("uri spec is empty"));

			if (trimedUriSpec.length() == 0)
			{
				initialize(*baseURI);
				return;
			}

			int index = 0;
			bool foundscheme = false;

			// Check for scheme, which must be before `/'. Also handle names with
			// DOS drive letters ('D:'), so 1-character schemes are not allowed.
			int colonIdx = trimedUriSpec.find_first_of(chColon);
			int slashIdx = trimedUriSpec.find_first_of(chForwardSlash);
			int queryIdx = trimedUriSpec.find_first_of(chQuestion);
			int fragmentIdx = trimedUriSpec.find_first_of(trimedUriSpec, chPound);  //'#'	
			if ((colonIdx < 2)                         ||
				(colonIdx > slashIdx && slashIdx != -1) ||
				(colonIdx > queryIdx && queryIdx != -1) ||
				(colonIdx > slashIdx && slashIdx != -1) )
			{

				// A standalone base is a valid URI according to spec
				if (colonIdx == 0 || (!baseURI && fragmentIdx >0) )
				{
					throw MalformedURLException(JDFStrL("No scheme specified"));
				}
			}
			else
			{
				foundscheme = true;
				initializeScheme(trimedUriSpec);
				index = mScheme.length()+1;
			}

			// It's an error if we stop here
			if (index == trimedUriSpec.length() || (foundscheme == true && (trimedUriSpec[index] == chPound)))
			{
				throw MalformedURLException(JDFStrL("empty URI"));
			}

			// two slashes means generic URI syntax, so we get the authority
			WString authUriSpec;
			authUriSpec = trimedUriSpec.substring(index,trimedUriSpec.length());

			if (((index+1) < trimedUriSpec.length()) &&
				!authUriSpec.startsWith(SINGLE_SLASH) )
			{
				if (baseURI && !baseURI->isAbsolute())
				{
					// Opaque URI
					initializeSchemeSpecificPart(authUriSpec);
					return;
				}
			}

			if (((index+1) < trimedUriSpec.length()) &&
				authUriSpec.startsWith(DOUBLE_SLASH))
			{
				index += 2;
				int startPos = index;

				// get authority - everything up to path, query or fragment
				JDFCh testChar;
				while (index < trimedUriSpec.length())
				{
					testChar = trimedUriSpec[index];
					if (testChar == chForwardSlash ||
						testChar == chQuestion     ||
						testChar == chPound         )
					{
						break;
					}

					index++;
				}

				// if we found authority, parse it out, otherwise we set the
				// host to empty string
				if (index > startPos)
				{
					authUriSpec = trimedUriSpec.substring(startPos,index);
					initializeAuthority(authUriSpec);
				}
				else
				{
					setHost(JDFStrL(""));
				}
			}

			// we need to check if index has exceed the length or not
			if (index >= trimedUriSpec.length())
			{
				return;
			}

			WString pathUriSpec = trimedUriSpec.substring(index,trimedUriSpec.length());

			initializePath(pathUriSpec);

			// Resolve relative URI to base URI - see RFC 2396 Section 5.2
			// In some cases, it might make more sense to throw an exception
			// (when scheme is specified is the string spec and the base URI
			// is also specified, for example), but we're just following the
			// RFC specifications
			if ( baseURI)
			{
				if (baseURI->isOpaque() == true)
					return;
				// check to see if this is the current doc - RFC 2396 5.2 #2
				// note that this is slightly different from the RFC spec in that
				// we don't include the check for query string being null
				// - this handles cases where the urispec is just a query
				// string or a fragment (e.g. "?y" or "#s") -
				// see <http://www.ics.uci.edu/~fielding/url/test1.html> which
				// identified this as a bug in the RFC


				if (mPath.length() == 0 && mScheme.length() == 0 && mHost.length() == 0 && mRegAuth.length() == 0)
				{
					mScheme = baseURI->getScheme();
					mUserInfo = baseURI->getRawUserInfo();
					mHost = baseURI->getRawHost();
					mPort = baseURI->getPort();
					mRegAuth = baseURI->getRawRegBasedAuthority();
					mPath = baseURI->getRawPath();
					if ( mQueryString.length() == 0 )
					{
						mQueryString = baseURI->getRawQuery();
					}
					return;
				}

				// check for scheme - RFC 2396 5.2 #3
				// if we found a scheme, it means absolute URI, so we're done
				if (mScheme.length() == 0)
				{
					mScheme = baseURI->getScheme();
				}
				else
				{
					return;
				}

				// check for authority - RFC 2396 5.2 #4
				// if we found a host, then we've got a network path, so we're done
				if (mHost.length() == 0 && mRegAuth.length() == 0)
				{
					mUserInfo = baseURI->getRawUserInfo();
					mHost = baseURI->getRawHost();
					mPort = baseURI->getPort();
					mRegAuth = baseURI->getRawRegBasedAuthority();
				}
				else
				{
					return;
				}

				// check for absolute path - RFC 2396 5.2 #5
				if (mPath.length() && mPath.startsWith(SINGLE_SLASH))
				{
					return;
				}

				// if we get to this point, we need to resolve relative path
				// RFC 2396 5.2 #6

				WString basePath = baseURI->getRawPath();
				WString path;

				// 6a - get all but the last segment of the base URI path
				if (basePath.length())
				{
					int lastSlash = basePath.find_last_of(chForwardSlash);
					if (lastSlash != -1)
					{
						path = basePath.substring(0,lastSlash+1);
					}
				}


				// 6b - append the relative URI path
				path.append(mPath);

				// 6c - remove all "./" where "." is a complete path segment
				index = -1;
				while ((index = path.indexOf(SLASH_DOT_SLASH)) != -1)
				{
					WString tmp1 = path.substring(0,index);
					WString tmp2 = path.substring(index+2,path.length());
					path = tmp1;
					path.append(tmp2);
				}

				// 6d - remove "." if path ends with "." as a complete path segment
				if (path.endsWith(SLASH_DOT))
				{
					path= path.substring(0,path.length()-1);
				}

				// 6e - remove all "<segment>/../" where "<segment>" is a complete
				// path segment not equal to ".."
				index = -1;
				int segIndex = -1;
				int offset = 1;

				while ((index = path.indexOf(SLASH_DOTDOT_SLASH,offset)) != -1)
				{
					// Undo offset
					//index += offset;

					// Find start of <segment> within substring ending at found point.
					WString tmp1 = path.substring(0, index-1);
					segIndex = tmp1.find_last_of(chForwardSlash);

					// Ensure <segment> exists and != ".."
					if (segIndex != -1                &&
						(path[segIndex+1] != chPeriod ||
						path[segIndex+2] != chPeriod ||
						segIndex + 3 != index))
					{

						WString tmp1 = path.substring(0,segIndex);
						WString tmp2 = path.substring(index+3,path.length());

						path = tmp1;
						path.append(tmp2);

						offset = (segIndex == 0 ? 1 : segIndex);
					}
					else
					{
						offset += 4;
					}
				}// while

				// 6f - remove ending "<segment>/.." where "<segment>" is a
				// complete path segment
				if (path.endsWith(SLASH_DOTDOT))
				{
					// Find start of <segment> within substring ending at found point.
					index = path.length() - 3;
					WString tmp1 = path.substring(0,index-1);	
					segIndex = tmp1.find_last_of(chForwardSlash);

					if (segIndex != -1                &&
						(path[segIndex+1] != chPeriod ||
						path[segIndex+2] != chPeriod ||
						segIndex + 3 != index))
					{
						path  = path.substring(0,segIndex+1);
					}
				}
				mPath = path;
			}
		}

		// scheme = alpha *( alpha | digit | "+" | "-" | "." )
		void URI::initializeScheme(const WString& uriSpec)
		{
			int idx = uriSpec.find_first_of(SCHEME_SEPARATORS);
			if (idx == WString::npos)
			{
				throw MalformedURLException(JDFStrL("no scheme  specified"));
			}
			else
			{
				WString scheme = uriSpec.substring(0,idx);
				setScheme(scheme);
			}
		}

		//
		//  scheme = alpha *( alpha | digit | "+" | "-" | "." )
		//  alphanum = alpha | digit
		//
		bool URI::isConformantSchemeName(const WString& scheme)
		{
			if ( !scheme.length() )
				return false;

			if (!WString::isAlpha(scheme[0]))     // first: alpha
				return false;

			// second onwards: ( alpha | digit | "+" | "-" | "." )
			for (int i=1;i < scheme.length(); i++)
			{
				if ( !WString::isAlphaNum(scheme[i]) &&
					(scheme.find_first_of(SCHEME_CHARACTERS, i) == -1))
					return false;
			}
			return true;
		}

		void URI::setScheme(const WString& newScheme)
		{
			if (!isConformantSchemeName(newScheme))
			{
				throw MalformedURLException(JDFStrL("Uri component is not conformant"));
			}

			mScheme = newScheme.toLowerCase();
		}


		//
		// authority     = server | reg_name
		// server        = [ [ userinfo "@" ] hostport ]
		// hostport      = host [ ":" port ]
		//
		// reg_name      = 1*( unreserved | escaped | "$" | "," |
		//                    ";" | ":" | "@" | "&" | "=" | "+" )
		//
		// userinfo      = *( unreserved | escaped |
		//                 ";" | ":" | "&" | "=" | "+" | "$" | "," )
		//

		void URI::initializeAuthority(const WString& uriSpec)
		{

			int index = 0;
			int start = 0;
			const int end = uriSpec.length();

			//
			// server = [ [ userinfo "@" ] hostport ]
			// userinfo is everything up @,
			//
			WString userinfo;
			index = uriSpec.find_first_of(chAt);

			if ( index != -1)
			{
				userinfo = uriSpec.substring(0,index);
				index++; // skip the @
				start = index;
			}
			else
			{
				// empty userinfo
			}

			//
			// hostport = host [ ":" port ]
			// host is everything up to ':' or up to 
			// and including ']' if followed by ':'.
			//
			WString host;

			// Search for port boundary.
			if (start < end && uriSpec[start] == chOpenSquare)
			{
				index = uriSpec.find_first_of(chCloseSquare,start);
				if (index != -1)
				{
					// skip the ']'
					index = ((start+index+1) < end
						&& uriSpec[start+index+1] == chColon) ? index+1 : -1;
				}
			}
			else
				index = uriSpec.find_first_of(chColon,start);

			if ( index != -1)
			{
				host = uriSpec.substring(start,index);
				index++;  // skip the :
				start =index;
			}
			else
			{
				host = uriSpec.substring(start,end-start);
				start=end;
			}

			// port is everything after ":"

			WString portStr;
			int port = -1;

			if ((host.length()) &&   // non empty host
				(index != -1)                    &&   // ":" found
				(start < end)                     )   // ":" is not the last
			{
				portStr = uriSpec.substring(start,end);

				if (portStr.length())
				{
					try
					{
						port = Integer::parseInt(portStr);
					}
					catch (...)
					{
						throw;
					}
				}
			} // if > 0

			// The order is important, do not change
			if (isValidServerBasedAuthority(host,port,userinfo))
			{
				mHost = host;
				mPort = port;
				mUserInfo = userinfo;
				return;
			}
			// This must be registry based authority or the URI is malformed.
			setRegBasedAuthority(uriSpec);
		}

		void URI::setRegBasedAuthority(const WString& newRegAuth)
		{
			mDecodedRegAuth = JDFStrL("");
			if (newRegAuth.length() == 0)
			{

				mRegAuth == L"";;
				return;
			}
			// reg_name = 1*( unreserved | escaped | "$" | "," | 
			//            ";" | ":" | "@" | "&" | "=" | "+" )
			else if (  !isValidRegistryBasedAuthority(newRegAuth) ) 
			{    
				throw MalformedURLException(JDFStrL("URI component not conformant"));
			}

			mRegAuth = newRegAuth;
			setHost(JDFStrL(""));
		}

		bool URI::isValidServerBasedAuthority(const WString& host,int port, const WString& userinfo)
		{
			// The order is important, do not change
			if (!isWellFormedAddress(host))
				return false;

			// check port number
			if ( (port > 65535) || (port < 0 && port != -1))
				return false;

			// check userinfo
			if (userinfo.length() == 0)
				return true;

			const JDFCh* tmpStr = userinfo.c_str();
			while (*tmpStr)
			{
				if ( isUnreservedCharacter(*tmpStr) ||
					(WString(USERINFO_CHARACTERS).find_first_of(*tmpStr) != -1))
				{
					tmpStr++;
				}
				else if (*tmpStr == chPercent)               // '%'
				{
					if (WString::isHex(*(tmpStr+1)) &&     // 1st hex
						WString::isHex(*(tmpStr+2))  )     // 2nd hex
					{
						tmpStr+=3;
					}
					else
						return false;

				}
				else
					return false;

			} //while

			return true;
		}

		bool URI::isValidRegistryBasedAuthority(const WString& authority)
		{
			// check authority
			if (authority.length() == 0)
				return true;

			const JDFCh* tmpStr = authority.c_str();
			while (*tmpStr)
			{
				if ( isUnreservedCharacter(*tmpStr) ||
					(WString(REG_NAME_CHARACTERS).find_first_of(*tmpStr) != -1))
				{
					tmpStr++;
				}
				else if (*tmpStr == chPercent)               // '%'
				{
					if (WString::isHex(*(tmpStr+1)) &&     // 1st hex
						WString::isHex(*(tmpStr+2))  )     // 2nd hex
					{
						tmpStr+=3;
					}
					else
						return false;

				}
				else
					return false;

			} //while

			return true;
		}

		//
		// uric     = reserved | unreserved | escaped
		// escaped  = "%" hex hex
		// hex      = digit | "A" | "B" | "C" | "D" | "E" | "F" |
		//                    "a" | "b" | "c" | "d" | "e" | "f"
		//
		bool URI::isURIString(const WString& uricString)
		{
			// check authority
			if (uricString.length() == 0)
				return false;

			const JDFCh* tmpStr = uricString.c_str();
			while (*tmpStr)
			{
				if ( isReservedOrUnreservedCharacter(*tmpStr))
				{
					tmpStr++;
				}
				else if (*tmpStr == chPercent)               // '%'
				{
					if (WString::isHex(*(tmpStr+1)) &&     // 1st hex
						WString::isHex(*(tmpStr+2))  )     // 2nd hex
					{
						tmpStr+=3;
					}
					else
						return false;

				}
				else
					return false;

			} //while

			return true;
		}


		//
		//  RFC 2732 amended RFC 2396 by replacing the definition 
		//  of IPv4address with the one defined by RFC 2373.
		//
		//  IPv4address   = 1*3DIGIT "." 1*3DIGIT "." 1*3DIGIT "." 1*3DIGIT
		//
		bool URI::isWellFormedIPv4Address(const JDFCh* const addr, const int length)
		{
			int numDots = 0;
			int numDigits = 0;

			// IPv4address = 1*3DIGIT "." 1*3DIGIT "." 1*3DIGIT "." 1*3DIGIT
			//
			// make sure that
			// 1) we see only digits and dot separators,
			// 2) that any dot separator is preceded and followed by a digit
			// 3) that we find 3 dots
			// 4) that each segment contains 1 to 3 digits.
			// 5) that each segment is not greater than 255.    

			for (int i = 0; i < length; i++)
			{
				if (addr[i] == chPeriod)
				{
					if (((i > 0)  &&
						(!WString::isDigit(addr[i-1]))) ||
						((i + 1 < length) &&
						(!WString::isDigit(addr[i+1])))  )
					{
						return false;
					}
					numDigits = 0;
					if (++numDots > 3)
						return false;
				}
				else if (!WString::isDigit(addr[i]))
				{
					return false;
				}
				// Check that that there are no more than three digits
				// in this segment.
				else if (++numDigits > 3)
				{
					return false;
				}
				// Check that this segment is not greater than 255.
				else if (numDigits == 3)
				{
					JDFCh first = addr[i-2];
					JDFCh second = addr[i-1];
					JDFCh last = addr[i];
					if (!(first < chDigit_2 || 
						(first == chDigit_2 && 
						(second < chDigit_5 || 
						(second == chDigit_5 && last <= chDigit_5)))))
					{
						return false;
					}
				}


			} //for

			return  (numDots == 3);
		}

		//
		//  IPv6reference = "[" IPv6address "]"
		//
		bool URI::isWellFormedIPv6Reference(const JDFCh* const addr, const int length)
		{
			int index = 1;
			int end = length-1;

			// Check if string is a potential match for IPv6reference.
			if (!(length > 2 && addr[0] == chOpenSquare && addr[end] == chCloseSquare))
			{
				return false;
			}

			// Counter for the number of 16-bit sections read in the address.
			int counter = 0;

			// Scan hex sequence before possible '::' or IPv4 address.
			index = scanHexSequence(addr, index, end, counter);
			if (index == -1) 
			{
				return false;
			}
			// Address must contain 128-bits of information.
			else if (index == end) 
			{
				return (counter == 8);
			}

			if (index+1 < end && addr[index] == chColon) 
			{
				if (addr[index+1] == chColon) 
				{
					// '::' represents at least one 16-bit group of zeros.
					if (++counter > 8) 
					{
						return false;
					}
					index += 2;
					// Trailing zeros will fill out the rest of the address.
					if (index == end)
					{
						return true;
					}
				}
				// If the second character wasn't ':', in order to be valid,
				// the remainder of the string must match IPv4Address, 
				// and we must have read exactly 6 16-bit groups.
				else 
				{
					if (counter == 6)
						return isWellFormedIPv4Address(addr+index+1, end-index-1);
					else
						return false;
				}
			}
			else 
			{
				return false;
			}

			// 3. Scan hex sequence after '::'.
			int prevCount = counter;
			index = scanHexSequence(addr, index, end, counter);
			if (index == -1) 
			{
				return false;
			}
			// If this is the end of the address then
			// we've got 128-bits of information.
			else if (index == end) 
			{
				return true;
			}

			// The address ends in an IPv4 address, or it is invalid. 
			// scanHexSequence has already made sure that we have the right number of bits. 
			int shiftCount = (counter > prevCount) ? index+1 : index;
			return isWellFormedIPv4Address(addr + shiftCount, end - shiftCount);
		}


		//
		//  host          = hostname | IPv4address
		//
		//  hostname      = *( domainlabel "." ) toplabel [ "." ]
		//  domainlabel   = alphanum | alphanum *( alphanum | "-" ) alphanum
		//  toplabel      = alpha | alpha *( alphanum | "-" ) alphanum
		//
		//  IPv4address   = 1*digit "." 1*digit "." 1*digit "." 1*digit
		//
		bool URI::isWellFormedAddress(const WString&  addrString)
		{
			if (addrString.empty())
				return false;

			WString tmpAddr = addrString.trim();

			// get address length
			int addrStrLen = tmpAddr.length();
			if (tmpAddr[0] == chOpenSquare)
			{
				return isWellFormedIPv6Reference(tmpAddr.c_str(),addrStrLen);
			}

			//
			// check length
			//
			//
			// the frist letter shall NOT be "." or "-"
			//
			if (tmpAddr[0] == chPeriod ||
				tmpAddr[0] == chDash    )
				return false;

			// rightmost domain label starting with digit indicates IP address
			// since top level domain label can only start with an alpha
			// see RFC 2396 Section 3.2.2
			int lastPeriodPos = tmpAddr.find_last_of(chPeriod);

			// if the string ends with "."
			// get the second last "."
			if (lastPeriodPos + 1 == addrStrLen)
			{
				WString tmp2 = tmpAddr.substring(0,lastPeriodPos);
				lastPeriodPos = tmp2.find_last_of(chPeriod);
				if ( WString::isDigit(tmpAddr[lastPeriodPos + 1]))
					return false;
			}

			if (WString::isDigit(tmpAddr[lastPeriodPos + 1]))
			{
				return isWellFormedIPv4Address(tmpAddr.c_str(), addrStrLen);
			} // end of IPv4address
			else
			{
				//
				//  hostname      = *( domainlabel "." ) toplabel [ "." ]
				//  domainlabel   = alphanum | alphanum *( alphanum | "-" ) alphanum
				//  toplabel      = alpha | alpha *( alphanum | "-" ) alphanum

				// RFC 2396 states that hostnames take the form described in 
				// RFC 1034 (Section 3) and RFC 1123 (Section 2.1). According
				// to RFC 1034, hostnames are limited to 255 characters.
				if (addrStrLen > 255) {
					return false;
				}

				unsigned int labelCharCount = 0;

				//
				// domain labels can contain alphanumerics and '-"
				// but must start and end with an alphanumeric
				for (int i = 0; i < addrStrLen; i++)
				{
					if (tmpAddr[i] == chPeriod)
					{
						if (((i > 0)  &&
							(!WString::isAlphaNum(tmpAddr[i-1]))) ||
							((i + 1 < addrStrLen) &&
							(!WString::isAlphaNum(tmpAddr[i+1])))  )
						{
							return false;
						}
					}
					else if (!WString::isAlphaNum(tmpAddr[i]) &&
						tmpAddr[i] != chDash)
					{
						return false;
					}
					// RFC 1034: Labels must be 63 characters or less.
					else if (++labelCharCount > 63) 
					{
						return false;
					}
				} //for
			}
			return true;
		}

		void URI::setPath(const WString& newPath)
		{
			mDecodedPath = JDFStrL("");
			if (newPath.length() == 0)
			{
				mPath = newPath;
				setQueryString(JDFStrL(""));
				setFragment(JDFStrL(""));
			}
			else
			{
				initializePath(newPath);
			}
		}

		//
		// fragment = *uric
		//
		void URI::setFragment(const WString& newFragment)
		{
			mDecodedFragment = JDFStrL("");
			if (newFragment.length() == 0)
			{
				mFragment = JDFStrL("");
			}
			else if (!isGenericURI())
				throw MalformedURLException(JDFStrL("Uri component for generic URI only"));
			else if (getPath().empty())
				throw MalformedURLException(JDFStrL("Uri component cannot contain fragment with an empty path"));
			else if (!isURIString(newFragment))
				throw MalformedURLException(JDFStrL("Uri fragment contains an invalid char"));
			else
			{
				mFragment = newFragment;
			}
		}

		void URI::setQueryString(const WString& newQueryString)
		{
			mDecodedQueryString = JDFStrL("");
			if (newQueryString.empty())
			{
				mQueryString = JDFStrL("");
			}
			else if (!isGenericURI())
				throw MalformedURLException(JDFStrL("Uri component for generic URI only"));
			else if (getPath().empty())
				throw MalformedURLException(JDFStrL("Uri component cannot contain querystring with an empty path"));
			else if (!isURIString(newQueryString))
				throw MalformedURLException(JDFStrL("Uri query contains an invalid char"));
			else
			{
				mQueryString = newQueryString;
			}
		}

		void URI::setHost(const WString&  newHost)
		{
			mDecodedHost = JDFStrL("");
			if ( newHost.length() == 0)
			{
				mHost = JDFStrL("");
				setUserInfo(JDFStrL(""));
				setPort(-1);
				return;
			}

			if (!isWellFormedAddress(newHost))
			{
				throw MalformedURLException(JDFStrL("URI component not conformant (host)"));
			}

			mHost = newHost;
			setRegBasedAuthority(JDFStrL(""));
		}

		void URI::setPort(int newPort)
		{
			if (newPort >= 0 && newPort <= 65535)
			{
				if (getHost().length()==0)
				{
					throw MalformedURLException(JDFStrL("port without  host specified"));
				}
			}
			else if (newPort != -1)
			{
				throw MalformedURLException(JDFStrL("no valid port"));
			}
			mPort = newPort;
		}

		//
		// server = [ [ userinfo "@" ] hostport ]
		// hostport = host [":" port]
		//
		// setUserInfo(), setHost() and setPort() are closely related
		// three methods, in a word, userinfo and port has dependency
		// on host.
		//
		// if host is not present, userinfo must be null and port = -1
		//
		void URI::setUserInfo(const WString& newUserInfo)
		{
			if ( newUserInfo.length() && getHost().length() == 0)
			{
				throw MalformedURLException(JDFStrL("host cannot be empty when user info is specified"));
			}
			try
			{
				isConformantUserInfo(newUserInfo);
			}
			catch (...)
			{
				throw;
			}
			mDecodedUserInfo = JDFStrL("");
			mUserInfo = newUserInfo;
		}

		//
		// userinfo = *( unreserved | escaped |
		//              ";" | ":" | "&" | "=" | "+" | "$" | "," )
		//
		void URI::isConformantUserInfo(const WString& userInfo)
		{
			if (userInfo.length() == 0 )
				return;

			const JDFCh* tmpStr = userInfo.c_str();
			while (*tmpStr)
			{
				if ( isUnreservedCharacter(*tmpStr) ||
					(WString(USERINFO_CHARACTERS).find_first_of(*tmpStr) != -1))
				{
					tmpStr++;
				}
				else if (*tmpStr == chPercent)               // '%'
				{
					if (WString::isHex(*(tmpStr+1)) &&     // 1st hex
						WString::isHex(*(tmpStr+2))  )     // 2nd hex
					{
						tmpStr+=3;
					}
					else
					{
						throw MalformedURLException(JDFStrL("URI path component invalid escape sequence"));
					}
				}
				else
				{	
					throw MalformedURLException(JDFStrL("URI path component invalid char"));
				}
			} //while

			return;
		}

		void URI::initializeSchemeSpecificPart(const WString&  uriSpec)
		{
			if ( uriSpec.length() == 0 )
			{
				throw MalformedURLException(JDFStrL("uri path component is empty"));
			}

			int index = 0;
			int start = 0;
			int end =uriSpec.length();
			JDFCh testChar;

			// schemespecificpart - everything up to  fragment
			while (index < end)
			{
				testChar = uriSpec[index];
				if (testChar == chPound)
				{
					break;
				}

				// check for valid escape sequence
				if (testChar == chPercent)
				{
					if (index+2 >= end ||
						!WString::isHex(uriSpec[index+1]) ||
						!WString::isHex(uriSpec[index+2]))
					{
						throw MalformedURLException(JDFStrL("URI path component invalid escape sequence"));
					}
				}
				else if (!isReservedCharacter(testChar) &&
					!isUnreservedCharacter(testChar))
				{
					throw MalformedURLException(JDFStrL("URI path component invalid char"));
				}

				index++;
			}//while (index < end)


			mSchemeSpecificPart = uriSpec.substring(start,index);


			// fragment - starts with #
			if (testChar == chPound)
			{
				index++;
				start = index;
				while (index < end)
				{
					testChar = uriSpec[index];

					if (testChar == chPercent)
					{
						if (index+2 >= end ||
							!WString::isHex(uriSpec[index+1]) ||
							!WString::isHex(uriSpec[index+2]))
						{
							throw MalformedURLException(JDFStrL("URI path component invalid escape sequence"));                
						}
					}
					else if (!isReservedCharacter(testChar) &&
						!isUnreservedCharacter(testChar))
					{
						throw MalformedURLException(JDFStrL("URI path component invalid char"));          
					}
					index++;
				}

				//make sure that there is something following the '#'
				if (index > start)
				{
					mFragment = uriSpec.substring(start,index);
				}
				else
				{
					// RFC 2396, 4.0. URI Reference
					// URI-reference = [absoulteURI | relativeURI] [# fragment]
					//
					// RFC 2396, 4.1. Fragment Identifier
					// fragment = *uric
					//
					// empty fragment is valid
					mFragment = JDFStrL("");
				}
			}
		}


		void URI::initializePath(const WString&  uriSpec)
		{
			if ( uriSpec.length() == 0 )
			{
				throw MalformedURLException(JDFStrL("uri path component is empty"));
			}

			int index = 0;
			int start = 0;
			int end =uriSpec.length();
			JDFCh testChar;
			// path - everything up to query string or fragment

			if (start < end)
			{
				// RFC 2732 only allows '[' and ']' to appear in the opaque part.
				if (!mScheme.length() || uriSpec[start] == chForwardSlash)
				{
					// Scan path.
					// abs_path = "/"  path_segments
					// rel_path = rel_segment [ abs_path ]
					while (index < end)
					{
						testChar = uriSpec[index];
						if (testChar == chQuestion || testChar == chPound)
						{
							break;
						}

						// check for valid escape sequence
						if (testChar == chPercent)
						{
							if (index+2 >= end ||
								!WString::isHex(uriSpec[index+1]) ||
								!WString::isHex(uriSpec[index+2]))
							{
								throw MalformedURLException(JDFStrL("URI path component invalid escape sequence"));
							}
						}
						else if (!isUnreservedCharacter(testChar) &&
							!isPathCharacter(testChar))
						{
							throw MalformedURLException(JDFStrL("URI path component invalid char"));
						}

						index++;
					}//while (index < end)
				}
				else 
				{
					// Scan opaque part.
					// opaque_part = uric_no_slash *uric

					while (index < end)
					{
						testChar = uriSpec[index];
						if (testChar == chQuestion || testChar == chPound)
						{
							break;
						}

						// check for valid escape sequence
						if (testChar == chPercent)
						{
							if (index+2 >= end ||
								!WString::isHex(uriSpec[index+1]) ||
								!WString::isHex(uriSpec[index+2]))
							{
								throw MalformedURLException(JDFStrL("URI path component invalid escape sequence"));
							}
						}
						else if (!isReservedOrUnreservedCharacter(testChar) )
						{
							throw MalformedURLException(JDFStrL("URI path component invalid char"));
						}

						index++;
					}//while (index < end)
				}
			}


			mPath = uriSpec.substring(start,index);

			// query - starts with ? and up to fragment or end
			if (testChar == chQuestion)
			{
				index++;
				start = index;
				while (index < end)
				{
					testChar = uriSpec[index];
					if (testChar == chPound)
					{
						break;
					}

					if (testChar == chPercent)
					{
						if (index+2 >= end ||
							!WString::isHex(uriSpec[index+1]) ||
							!WString::isHex(uriSpec[index+2]))
						{
							throw MalformedURLException(JDFStrL("URI path component invalid escape sequence"));
						}
					}
					else if (!isReservedOrUnreservedCharacter(testChar))
					{
						throw MalformedURLException(JDFStrL("URI path component invalid char"));
					}
					index++;
				}

				mQueryString = uriSpec.substring(start,index);
			}

			// fragment - starts with #
			if (testChar == chPound)
			{
				index++;
				start = index;
				while (index < end)
				{
					testChar = uriSpec[index];

					if (testChar == chPercent)
					{
						if (index+2 >= end ||
							!WString::isHex(uriSpec[index+1]) ||
							!WString::isHex(uriSpec[index+2]))
						{
							throw MalformedURLException(JDFStrL("URI path component invalid escape sequence"));                
						}
					}
					else if (!isReservedOrUnreservedCharacter(testChar))
					{
						throw MalformedURLException(JDFStrL("URI path component invalid char"));          
					}
					index++;
				}

				//make sure that there is something following the '#'
				if (index > start)
				{
					mFragment = uriSpec.substring(start,index);
				}
				else
				{
					// RFC 2396, 4.0. URI Reference
					// URI-reference = [absoulteURI | relativeURI] [# fragment]
					//
					// RFC 2396, 4.1. Fragment Identifier
					// fragment = *uric
					//
					// empty fragment is valid
					mFragment = JDFStrL("");
				}
			}
		}

		bool URI::isReservedCharacter(const JDFCh ch)
		{
			for (int i=0;RESERVED_CHARACTERS[i] != chNull;i++)
			{
				if (RESERVED_CHARACTERS[i] == ch)
					return true;
			}
			return false;
		}

		bool URI::isPathCharacter(const JDFCh ch)
		{
			for (int i=0;PATH_CHARACTERS[i] != chNull;i++)
			{
				if (PATH_CHARACTERS[i] == ch)
					return true;
			}
			return false;}


		bool URI::isUnreservedCharacter(const JDFCh ch)
		{
			if ((unsigned int)ch >127) // allow iris
				return true;

			if (WString::isAlphaNum(ch) == true)
				return true;

			for (int i=0;MARK_CHARACTERS[i] != chNull;i++)
			{
				if (MARK_CHARACTERS[i] == ch)
					return true;
			}
			return false;
		}

		bool URI::isReservedOrUnreservedCharacter(const JDFCh ch) 
		{
			if (WString::isAlphaNum(ch) == true)
				return true;

			for (int i=0;MARK_OR_RESERVED_CHARACTERS[i] != chNull;i++)
			{
				if (MARK_OR_RESERVED_CHARACTERS[i] == ch)
					return true;
			}
			return false;
		}

		void URI::buildFullText()
		{
			if (isAbsolute())
			{
				mURIText.append(getScheme());
				mURIText.append(chColon);
				if (!isOpaque())
				{
					mURIText.append(chForwardSlash);
					mURIText.append(chForwardSlash);
				}
			}
			if (isOpaque())
			{
				mURIText.append(getRawSchemeSpecificPart());
			}
			else
			{

				if (mUserInfo.length())
				{
					mURIText.append(getRawUserInfo());
					mURIText.append(chAt);
				}
				if (mHost.length())
				{
					mURIText.append(getRawHost());
					//
					//  If the port is -1, then we don't put it in. Else we need
					//  to because it was explicitly provided.
					//
					if (mPort != -1)
					{
						mURIText.append(chColon);
						mURIText.append(Integer::toString(mPort));
					}
				}
				if (mPath.length())
				{
					mURIText.append(getRawPath());
				}
				if (mQueryString.length())
				{
					mURIText.append(chQuestion);
					mURIText.append(getRawQuery());
				}
			}
			if (mFragment.length())
			{
				mURIText.append(chPound);
				mURIText.append(getRawFragment());
			}
		}

		WString URI::getPath() const
		{
			if (mDecodedPath.empty())
				mDecodedPath = URLDecoder::decode(mPath);
			return mDecodedPath;
		}

		WString URI::getRawPath() const
		{
			return mPath;
		}

		WString URI::getHost() const
		{
			if (mDecodedHost.empty())
				mDecodedHost = URLDecoder::decode(mHost);
			return mDecodedHost;
		}

		WString URI::getRawHost() const
		{
			return mHost;
		}

		WString URI::getUserInfo() const
		{
			if (mDecodedUserInfo.empty())
				mDecodedUserInfo = URLDecoder::decode(mUserInfo);
			return mDecodedUserInfo;
		}

		WString URI::getRawUserInfo() const
		{
			return mUserInfo;
		}

		WString URI::getQuery() const
		{
			if (mDecodedQueryString.empty())
				mDecodedQueryString = URLDecoder::decode(mQueryString);
			return mDecodedQueryString;
		}

		WString URI::getRawQuery() const
		{
			return mQueryString;
		}

		WString URI::getScheme() const
		{
			return mScheme;
		}

		WString URI::getRegBasedAuthority() const
		{
			if (mDecodedRegAuth.empty())
				mDecodedRegAuth = URLDecoder::decode(mRegAuth);
			return mDecodedRegAuth;
		}

		WString URI::getFragment() const
		{
			if (mDecodedFragment.empty())
				mDecodedFragment = URLDecoder::decode(mFragment);
			return mDecodedFragment;
		}

		WString URI::getRawFragment() const
		{
			return mFragment;
		}

		WString URI::getRawSchemeSpecificPart() const
		{
			return mSchemeSpecificPart;
		}

		WString URI::getRawRegBasedAuthority() const
		{
			return mRegAuth;
		}

		WString URI::getSchemeSpecificPart() const
		{
			if (mDecodedSchemeSpecificPart.empty())
				mDecodedSchemeSpecificPart = URLDecoder::decode(mSchemeSpecificPart);
			return mDecodedSchemeSpecificPart;
		}

		bool URI::isOpaque() const
		{
			return !mSchemeSpecificPart.empty();
		}

		bool URI::isAbsolute() const
		{
			return !mScheme.empty();
		}

		bool URI::isGenericURI() const
		{
			return !mHost.empty();
		}

		URL URI::toURL() const
		{
			if (!isAbsolute())
				throw IllegalArgumentException(JDFStrL("URI is not Absolute"));
			return URL(mScheme, (isOpaque() ? getRawSchemeSpecificPart() : JDFStrL("")),
				mUserInfo,mHost,mPort,mPath,mQueryString,mFragment,NULL);
		}

		//
		//  For use with isWellFormedIPv6Reference only.
		//
		int URI::scanHexSequence (const JDFCh* const addr, int index, int end, int& counter)
		{
			JDFCh testChar = chNull;
			int numDigits = 0;
			int start = index;

			// Trying to match the following productions:
			// hexseq = hex4 *( ":" hex4)
			// hex4   = 1*4HEXDIG
			for (; index < end; ++index)
			{
				testChar = addr[index];
				if (testChar == chColon)
				{
					// IPv6 addresses are 128-bit, so there can be at most eight sections.
					if (numDigits > 0 && ++counter > 8)
					{
						return -1;
					}
					// This could be '::'.
					if (numDigits == 0 || ((index+1 < end) && addr[index+1] == chColon))
					{
						return index;
					}
					numDigits = 0;
				}
				// This might be invalid or an IPv4address. If it's potentially an IPv4address,
				// backup to just after the last valid character that matches hexseq.
				else if (!WString::isHex(testChar))
				{
					if (testChar == chPeriod && numDigits < 4 && numDigits > 0 && counter <= 6)
					{
						int back = index - numDigits - 1;
						return (back >= start) ? back : start;
					}
					return -1;
				}
				// There can be at most 4 hex digits per group.
				else if (++numDigits > 4)
				{
					return -1;
				}
			}
			return (numDigits > 0 && ++counter <= 8) ? end : -1;
		}

} // namespace JDF
