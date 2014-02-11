/*
* The CIP4 Software License, Version 1.0
*
*
* Copyright (c) 2001-2008 The International Cooperation for the Integration of 
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


#include <jdf/net/ParseUtil.h>
#include <jdf/lang/Exception.h>
#include <jdf/util/PlatformUtils.h>
#include <jdf/lang/Synchronized.h>
#include <xercesc/util/XMLUniDefs.hpp>


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

	static JDFCh hexArray[] = 
	{
		chDigit_0, chDigit_1, chDigit_2, chDigit_3, chDigit_4, chDigit_5,
			chDigit_6, chDigit_7, chDigit_8, chDigit_9, chLatin_A, chLatin_B,
			chLatin_C, chLatin_D,	chLatin_E, chLatin_F 
	};



	static JDFCh HexCharForDigit(char b)
	{
		return hexArray[b&0xf];
	}

	std::set<JDFCh> ParseUtil::m_encodedPath;

	/******************************************************************************
	*	Classes
	******************************************************************************/ 

	/******************************************************************************
	*	Prototypes
	******************************************************************************/ 


	/******************************************************************************
	*	Implementation
	******************************************************************************/ 


	void ParseUtil::init()
	{
		if (m_encodedPath.empty())
		{
			Synchronized sync(PlatformUtils::gSingletonMutex());

			if (m_encodedPath.empty())
			{
				// Set the bits corresponding to characters that are encoded in the
				// path component of a URI.

				// These characters are reserved in the path segment as described in
				// RFC2396 section 3.3.
				m_encodedPath.insert(chEqual);       // '='
				m_encodedPath.insert(chSemiColon);   // ';'
				m_encodedPath.insert(chQuestion);    // '?'
				m_encodedPath.insert(chForwardSlash);// '/' 

				// These characters are defined as excluded in RFC2396 section 2.4.3
				// and must be escaped if they occur in the data part of a URI.
				m_encodedPath.insert(chPound);      // '#'
				m_encodedPath.insert(chSpace);      // ' '
				m_encodedPath.insert(chOpenAngle);  // '<'
				m_encodedPath.insert(chCloseAngle); // '>'
				m_encodedPath.insert(chPercent);    // '%'
				m_encodedPath.insert(chDoubleQuote);// '"'
				m_encodedPath.insert(chOpenCurly);  // '{'
				m_encodedPath.insert(chCloseCurly); // '}'
				m_encodedPath.insert(chPipe);		// '|'
				m_encodedPath.insert(chBackSlash);	// '\\'
				m_encodedPath.insert(0x5E);			// '^'
				m_encodedPath.insert(chOpenSquare); // '['
				m_encodedPath.insert(chCloseSquare);// ']'
				m_encodedPath.insert(0x60);         //'`'

				// 080407 RP removed        m_encodedPath.insert(chDash);         //'-'
				//			m_encodedPath.insert(chUnderscore);   //'_'
				//			m_encodedPath.insert(chPeriod);       //'.'
				m_encodedPath.insert(chBang);         //'!'
				m_encodedPath.insert(chTilde);        //'~'
				m_encodedPath.insert(chAsterisk);     //'*'
				m_encodedPath.insert(chSingleQuote);  // '
				m_encodedPath.insert(chOpenParen);    // '('
				m_encodedPath.insert(chCloseParen);   // '('
				//			m_encodedPath.insert(chColon);        // ':'
				m_encodedPath.insert(chAt);           // '@'
				m_encodedPath.insert(chAmpersand);    // '&'
				m_encodedPath.insert(chEqual);        // '='
				m_encodedPath.insert(chPlus);         // '+'
				m_encodedPath.insert(chComma);         // ','
				m_encodedPath.insert(chDollarSign);   // '$'


				// US ASCII control characters 00-1F and 7F.
				for (int i=0; i<32; i++)
					m_encodedPath.insert(i);

				m_encodedPath.insert(127);
			}
		}
	}

	void ParseUtil::escape(WString& s, JDFCh c)
	{
		s.append(chPercent);
		char ch = (char)HexCharForDigit((c >> 4) & 0xF);
		s.append(1,ch);
		ch = HexCharForDigit(c & 0xF);
		s.append(1,ch);
	}

	static int hexdigit(JDFCh ch)
	{
		if ((ch >= chLatin_A) && (ch <= chLatin_Z))
			ch += 0x20;

		int tmp;
		if (ch >= chLatin_a)
			tmp = (int) (ch - chLatin_a + 10);
		else
			tmp = (int) (ch - chDigit_0);

		return tmp;
	}


	JDFCh ParseUtil::unescape(WString& s, int i)
	{
		return (hexdigit(s[i+1]) << 4) | hexdigit(s[i+2]);
	}

	WString ParseUtil::encodePath(WString path)
	{
		ParseUtil::init();

		// normalize the file;
		//path = File(path).getPath();
		WString res;
		for (int i=0; i< path.length(); i++)
		{
			JDFCh c = path[i];
			if (c == File::separatorChar())
				res.append(chForwardSlash);
			else
			{
				if (c <= 0x007F)
				{
					if (m_encodedPath.find(c) != m_encodedPath.end() )
						escape(res,c);
					else
						res.append(c);
				}
				else if (c > 0x07FF)
				{
					escape(res,(JDFCh) (0xE0| (( c>>12) & 0x0F)));
					escape(res,(JDFCh) (0x80| (( c>> 6) & 0x3F)));
					escape(res,(JDFCh) (0x80| (( c>> 0) & 0x3F)));
				}
				else 
				{
					escape(res,(JDFCh) (0xC0| (( c>> 6) & 0x1F)));
					escape(res,(JDFCh) (0x80| (( c>> 0) & 0x3F)));
				}
			}
		}
		return res;
	}

	WString ParseUtil::encode(const WString& path)
	{
		ParseUtil::init();

		WString res;
		for (int i=0; i< path.length(); i++)
		{
			JDFCh c = path[i];
			if (c <= 0x007F) // other ASCII
			{
				if (m_encodedPath.find(c) != m_encodedPath.end() )
					escape(res,c);
				else
					res.append(c);
			}
			else if (c > 0x07FF)  // 0x7FF < ch <= 0xFFFF
			{
				// ch: [zzzzyyyy] [yyxxxxxx]
				// out: [1110zzzz] [10yyyyyy] [10xxxxxx]
				escape(res,(JDFCh) (0xE0| (( c>>12) & 0x0F)));
				escape(res,(JDFCh) (0x80| (( c>> 6) & 0x3F)));
				escape(res,(JDFCh) (0x80| (( c>> 0) & 0x3F)));
			}
			else  // non-ASCII <= 0x7FF
			{
				// ch: [00000yyy] [yyxxxxxx]
				// out: [110yyyyy] [10xxxxxx]
				escape(res,(JDFCh) (0xC0| (( c>> 6) & 0x1F)));
				escape(res,(JDFCh) (0x80| (( c>> 0) & 0x3F)));
			}
		}
		return res;
	}


	WString ParseUtil::decode(WString s)
	{
		ParseUtil::init();

		WString res;
		int i=0;
		while (i < s.length())
		{
			JDFCh c = s[i];
			JDFCh c2,c3;
			if (c != chPercent) 
				i++;
			else
			{
				c = unescape(s,i);
				i+=3;
				if (( c & 0x80) != 0)
				{
					switch ( c>>4)
					{
					case 0xC:
					case 0xD: c2 = unescape(s,i);
						i+=3;
						c =(JDFCh)(((c & 0x1f) << 6) | (c2 & 0x3f));
						break;	
					case 0xE:
						c2 = unescape(s, i);
						i += 3;
						c3 = unescape(s, i);
						i += 3;
						c = (JDFCh)(((c & 0x0f) << 12) |
							((c2 & 0x3f) << 6) |
							(c3 & 0x3f));
						break;

					default:
						throw IllegalArgumentException();

					}
				}
			}
			res.append(c);
		}
		return res;
	}

	WString ParseUtil::canonizeString(WString file)
	{
		int i = 0;
		int lim = file.length();

		// remove embedded /../
		while ((i = file.indexOf(JDFStrL("/.."))) >= 0)
		{
			if ((lim = file.find_last_of(chForwardSlash,0)) >= 0)
				file = file.substring(0,lim) + file.substring(i+3);
			else
				file = file.substring(i+3);
		}
		// remove embedded /./
		while ((i= file.indexOf(JDFStrL("/./"))) >= 0)
		{
			file = file.substring(0,i) + file.substring(i+2);
		}
		// remove trailing ..
		while (file.endsWith(JDFStrL("/..")))
		{
			i = file.indexOf(JDFStrL("/.."));
			if ((lim = file.find_last_of(chForwardSlash,i-1)) >= 0)
				file = file.substring(0,lim+1);
			else
				file = file.substring(0,i);
		}
		// remove trailing .
		if (file.endsWith(JDFStrL("/.")))
		{
			file = file.substring(0,file.length()-1);
		}
		return file;
	}

	/*
	URL ParseUtil::fileToURL(File file)
	{
	WString path = file.getPath();
	path = encodePath(path);

	if (!path.endsWith(chForwardSlash) && file.isDirectory())
	path.append(chForwardSlash);

	if (!path.startsWith(JDFStrL("/"))) {
	path = JDFStrL("/") + path;
	}

	return URL(JDFStrL("file"),JDFStrL(""),path);
	}
	*/
	/*
	URL ParseUtil::fileToURL(const File& file)
	{
	}


	File ParseUtil::URLToFile(const WString& url, const WString& baseURL)
	{
	}

	File ParseUtil::fileToUNC(const File& file)
	{
	}
	File ParseUtil::UNCToFile(const File& file)
	{
	}
	*/




	/*
	URL ParseUtil::fileToURL(const File& file)
	{
	}

	URL ParseUtil::fileToURL(const File& file,const URL& base)
	{
	}


	URL ParseUtil::URLToFile(const URL& url,const File& relFileSpec)
	{
	}


	File ParseUtil::fileToUNC(const File& file)
	{
	}
	File ParseUtil::UNCToFile(const File& file)
	{
	}

	*/




} // namespace JDF
