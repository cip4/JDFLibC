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

#include "ChunkedInputStream.h"

#include "MessageHeader.h"

#include <jdf/lang/Exception.h>


namespace JDF
{

	/******************************************************************************
	*	Forward declarations
	******************************************************************************/ 


	/******************************************************************************
	*	Defines and constants
	******************************************************************************/ 

#define min(a,b) ((a) < (b) ? (a) : (b))

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

	ChunkedInputStream::ChunkedInputStream(InputStream* in,MessageHeader& responses) : FilterInputStream(*in),
		mResponses(responses)
	{
		contentLength=0;
		chunkCount=0;
		isDone = false;
	}

	ChunkedInputStream::~ChunkedInputStream()
	{
		delete mIn;
	}

	int ChunkedInputStream::read()
	{
		char b;
		if (read(&b,1,0,1) == -1)
			return -1;
		return (int)b;
	}

	int ChunkedInputStream::read(char* b, int blen)
	{
		return FilterInputStream::read(b,blen);
	}

	int ChunkedInputStream::read(char* b, int blen,int off,int len)
	{
		if (chunkCount==0)
		{
			startChunk();
			// encountered terminating 0 chunk size
			// eof
			if (chunkCount==0)
				return -1;
		}
		int toRead = min(chunkCount,len);
		int r= mIn->read(b,blen,off,toRead);
		if (r!= -1)
			chunkCount-=r;
		return r;
	}

	std::string ChunkedInputStream::readLine(bool& eof)
	{
		std::string line("");
		eof = false;
		int c;
		char lastChar = ' ';

		// eat CRLF
		c = mIn->read();
		if (c == '\r')
		{
			c = mIn->read();
			c = mIn->read();
		}
		if (c==-1)
		{
			eof = true;
			return line;
		}
		// read everything until CRLF
		while (1)
		{
			if (c == -1)
			{
				eof=true;
				return line;
			}
			if (c == '\n' && lastChar == '\r') 
			{
				return line;
			}

			if (c != '\n' && c != '\r' && c != ' ')
				line.append((unsigned int)1,(char)c);
			lastChar = c;
			c = mIn->read();
		}
		return line;
	}

	static char toLower(char c)
	{
		if (c >= 'A' && c <= 'Z')
			return c + 'a'-'A';
		else
			return c;
	}

	int hex2dec(const  std::string& s)
	{
		int decValue=0;
		for (unsigned int i=0;i< s.length(); i++)
		{
			char c = tolower(s[i]);
			int tmp;
			if ((int) c >= (int)'a')
				tmp = (int) (c - 'a' + 10);
			else
				tmp = (int) (c - '0');

			decValue = (decValue << 4) + tmp;
		}
		return decValue;
	}


	void ChunkedInputStream::startChunk()
	{
		bool eof;
		std::string line = readLine(eof);
		if (eof)
		{
			throw IOException("Malformed chunk");
		}
		chunkCount    = hex2dec(line);
		contentLength += chunkCount;
		if (chunkCount == 0)
		{
			isDone=true;
			readFooters();
		}
	}

	void ChunkedInputStream::readFooters()
	{
		mResponses.mergeHeader(*mIn);
	}

	int ChunkedInputStream::getContentLength()
	{
		if (!isDone)
			return -1;
		return contentLength;
	}

} // namespace JDF
