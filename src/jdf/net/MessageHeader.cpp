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

#include "MessageHeader.h"

#include <jdf/io/PrintStream.h>
#include <jdf/io/InputStream.h>

#include <jdf/lang/WString.h>

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
	
	MessageHeader::MessageHeader()
	{
		grow();
	}
	
	
	MessageHeader::MessageHeader(InputStream& is) 
	{
		parseHeader(is);
	}
	
	MessageHeader::value_pair MessageHeader::findValue(const WString& k)
	{
		int nKeys=mValues.size();

		for (int i = nKeys; --i >= 0;)
		{
			if (k.compareToIgnoreCase(mKeys[i])==0)
				return value_pair(true,mValues[i]);
		}
		return  value_pair(false,WString::emptyStr);
	}
	
	MessageHeader::value_pair MessageHeader::getKey(int n)
	{
		if (n<0 || static_cast<unsigned int>(n) >= mKeys.size())
			return value_pair(false,WString::emptyStr);
		
		return value_pair(true,mKeys[n]);
	}
	
	MessageHeader::value_pair MessageHeader::getValue(int n) 
	{
		if (n < 0 || static_cast<unsigned int>(n) >= mValues.size())
			return value_pair(false,WString::emptyStr);
		
		return value_pair(true,mValues[n]);
	} 
	
	MessageHeader::value_pair MessageHeader::findNextValue(const WString& k, const WString& v)
	{
		bool foundV = false;
		
		int nKeys=mValues.size();
		for (int i = nKeys; --i >= 0;)
		{
			if (k.compareToIgnoreCase(mKeys[i])==0)
				if (foundV)
					return value_pair(true,mValues[i]);
				else if (mValues[i] == v)
					foundV = true;
		}
		return value_pair(false,WString::emptyStr);
	}
	
	void MessageHeader::print(PrintStream& p) 
	{
		int nKeys=mValues.size();
		for (int i = 0; i < nKeys; i++)
		{
			if (mValues[i].length())
				p.print(mKeys[i] + L": " + mValues[i] + L"\r\n");
			else
				p.print(mKeys[i] +"\r\n");
		}
		p.print("\r\n");
		p.flush();
	}
	
	void MessageHeader::add(const WString& k, const WString& v)
	{
		mKeys.push_back(k);
		mValues.push_back(v);
	}
	
	void MessageHeader::prepend(const WString& k, const WString& v)
	{
		// add empty extra slot
		int nKeys=mValues.size();

		mKeys.push_back(WString::emptyStr);
		mValues.push_back(WString::emptyStr);
		
		for (int i = nKeys; i > 0; i--) {
			mKeys[i]   = mKeys[i-1];
			mValues[i] = mValues[i-1];
		}
		//	if (nKeys == 0)
		//	{
		//		mKeys.resize(1);
		//		mValues.resize(1);
		//	}
		mKeys[0]   = k;
		mValues[0] = v;
		nKeys++;
	}
	
	void MessageHeader::set(int i, const WString& k, const WString& v)
	{
		if (i < 0)
			return;
		else if (static_cast<unsigned int>(i) > mKeys.size())
		{
			add(k, v);
		}
		else
		{
			mKeys[i]   = k;
			mValues[i] = v;
		}
	}
	
	void MessageHeader::set(const WString& k, const WString& v)
	{
		int nKeys=mValues.size();
		for (int i = nKeys; --i >= 0;)
		{
			if (k.compareToIgnoreCase(mKeys[i])==0)
			{
				mValues[i] = v;
				return;
			}
		}
		add(k, v);
	}
	
	void MessageHeader::setIfNotSet(const WString& k, const WString& v)
	{
		if (findValue(k).first == false) 
			add(k, v);
	}
	
	void MessageHeader::grow()
	{
	}
	
	void MessageHeader::parseHeader(InputStream& is)
	{
		clear();
		mergeHeader(is);
	}
	
	void MessageHeader::mergeHeader(InputStream& is)
	{
		WString s;
		
		int firstc = is.read();
		while (firstc != '\n' && firstc != '\r' && firstc >= 0) 
		{
			s = WString::emptyStr;
			int len = 0;
			int keyend = -1;
			int c;
			bool inKey = firstc > ' ';
			s.append(1,(char)firstc);
			len++;
			bool endfound = false;
			
			while ((c = is.read()) >= 0) 
			{
				switch (c)
				{
				case ':' : if (inKey && len > 0)
							   keyend = len;
					inKey = false;
					break;
				case '\t': c = ' ';
				case ' ' : inKey = false;
					break;
				case '\r':
				case '\n': firstc = is.read();
					if (c == '\r' && firstc == '\n')
					{
						firstc = is.read();
						if (firstc == '\r')
							firstc = is.read();
					}
					if (firstc == '\n' || firstc == '\r' || firstc > ' ')
					{
						endfound = true;
						break;
					}
					c = ' ';
					break;
				}
				if (endfound)
					break;
				s.append(1,(char) c);
				len++;
			}
			if (!endfound)
				firstc = -1;
			
			while (len > 0 && s[len - 1] <= ' ')
				len--;
			
			WString k;
			
			if (keyend <= 0) 
			{
				k = WString::emptyStr;
				keyend = 0;
			} else 
			{
				k = WString(s,0,keyend);
				if (keyend < len && s[keyend] == ':')
					keyend++;
				while (keyend < len && s[keyend] <= ' ')
					keyend++;
			}
			WString v;
			if (keyend >= len)
				v = WString::emptyStr;
			else
				v = s.substr(keyend,len-keyend);
			add(k, v);
		}
	}
	
	void MessageHeader::clear()
	{
		mKeys.clear();
		mValues.clear();
	}
	
	MessageHeader& MessageHeader::operator=(const MessageHeader& header)
	{
		if (this == &header)
			return *this;

		mKeys.clear();
		mValues.clear();
		
		mKeys.resize(header.mKeys.size());
		mValues.resize(header.mValues.size());
		std::copy(header.mKeys.begin(),header.mKeys.end(),mKeys.begin());
		std::copy(header.mValues.begin(),header.mValues.end(),mValues.begin());
		
		return *this;
	}
	
} // namespace JDF
