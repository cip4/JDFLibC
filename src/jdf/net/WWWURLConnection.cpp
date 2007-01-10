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

#include "WWWURLConnection.h"

#include <jdf/lang/Exception.h>

#include <jdf/io/InputStream.h>
#include <jdf/lang/Integer.h>


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

	WWWURLConnection::WWWURLConnection(const URL& u) : URLConnection(u)
	{
		contentLength = -1;
	}

	void WWWURLConnection::setRequestProperty(const WString& key, const WString& value)
	{
		if (connected)
			throw IllegalAccessError("Already connected");
		properties.set(key,value);
	}

	MessageHeader::value_pair WWWURLConnection::getHeaderField(const WString& name)
	{
		try
		{
			getInputStream();
		}
		catch (Exception& )
		{
			return MessageHeader::value_pair(false,"");
		}
		return properties.findValue(name);
	}

	MessageHeader::value_pair WWWURLConnection::getHeaderFieldKey(int n)
	{
		try
		{
			getInputStream();
		}
		catch (Exception& )
		{
			return MessageHeader::value_pair(false,"");
		}
		return properties.getKey(n);
	}

	MessageHeader::value_pair WWWURLConnection::getHeaderField(int n)
	{
		try
		{
			getInputStream();
		}
		catch (Exception& )
		{
			return MessageHeader::value_pair(false,"");
		}
		return properties.getValue(n);
	}

	WString WWWURLConnection::getContentType()
	{
		if (contentType.length() == 0)
			contentType = getHeaderField(JDFStrL("content-type")).second;

		if (contentType.length() == 0)
		{
			WString ct;
			try
			{
				ct = guessContentTypeFromStream(getInputStream());
			} catch (IOException&)
			{
			}
			MessageHeader::value_pair ce = properties.findValue(JDFStrL("content-encoding"));
			if (ct.length()==0)
			{
				MessageHeader::value_pair v = properties.findValue(JDFStrL("content-type"));
				if (v.first)
					ct = v.second;
				else
				{
					if (url.getFile().endsWith(JDFStrL("/")))
						ct = JDFStrL("text/html");
					else
						ct = guessContentTypeFromName(url.getFile());
				}
			}

			/*
			* If the mime header has a Content-encoding field and its
			* value was not one of the values that essentially indicate
			* no encoding, we force the content type to be unknown.	
			*/


			if (ct.length() == 0 || ce.first  && 
				!(  ce.second.compareToIgnoreCase(JDFStrL("7bit"))==0
				||ce.second.compareToIgnoreCase(JDFStrL("8bit"))==0
				||ce.second.compareToIgnoreCase(JDFStrL("binary"))==0) )
			{
				ct = JDFStrL("content/unknown");
				contentType = ct;
			}
		}
		return contentType;
	}

	void WWWURLConnection::setContentType(const WString& type)
	{
		contentType = type;
	}

	int WWWURLConnection::getContentLength()
	{
		try
		{
			getInputStream();
		} catch (Exception&)
		{
			return -1;
		}
		int l = contentLength;
		if (l < 0)
		{
			MessageHeader::value_pair cl = properties.findValue(JDFStrL("content-length"));
			if (cl.first)
			{
				l = Integer::parseInt(cl.second);
				contentLength = l;
			}
		}
		return l;
	}

	void WWWURLConnection::setContentLength(int length)
	{
		contentLength = length;
	}

	bool WWWURLConnection::canCache()
	{
		return url.getFile().find_first_of('?') < 0;
	}

	void WWWURLConnection::close()
	{
	}

} // namespace JDF
