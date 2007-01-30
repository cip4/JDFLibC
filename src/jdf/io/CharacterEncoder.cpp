/*
 * The CIP4 Software License, Version 0.1
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

#include "CharacterEncoder.h"

#include "PrintStream.h"
#include "ByteArrayInputStream.h"
#include "ByteArrayOutputStream.h"

#include <jdf/lang/Exception.h>
#include <jdf/lang/Janitor.h>


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

CharacterEncoder::CharacterEncoder()
{
	pStream = NULL;
}

CharacterEncoder::~CharacterEncoder()
{
	if (pStream)
		delete pStream;
}

void CharacterEncoder::encodeBufferPrefix(OutputStream& aStream) 
{
	if (pStream)
		delete pStream;
	pStream = new PrintStream(aStream);
}

void CharacterEncoder::encodeBufferSuffix(OutputStream& aStream) 
{
}

void CharacterEncoder::encodeLinePrefix(OutputStream& aStream, int aLength)
{
}

void CharacterEncoder::encodeLineSuffix(OutputStream& aStream) 
{
	pStream->println();
}

int CharacterEncoder::readFully(InputStream& in, char* buffer, int len) 
{
	for (int i = 0; i < len; i++) 
	{
		int q = in.read();
		if (q == -1)
			return i;
		buffer[i] = (char)q;
	}
	return len;
}

void CharacterEncoder::encode(InputStream& inStream, OutputStream& outStream) 
{
	int	j;
	int	numBytes;
	int len = bytesPerLine();
	char*	tmpbuffer = new char[len];
	ArrayJanitor<char> tmpbufferJanitor(tmpbuffer);

	encodeBufferPrefix(outStream);
	const int bpa=bytesPerAtom();
	while (true) 
	{
		numBytes = readFully(inStream, tmpbuffer,len);
		if (numBytes == 0) 
		{
			break;
		}
		encodeLinePrefix(outStream, numBytes);
		for (j = 0; j < numBytes; j += bpa) 
		{
			if ((j + bpa) <= numBytes) 
			{
				encodeAtom(outStream, tmpbuffer, numBytes, j, bpa);
			} else 
			{
				encodeAtom(outStream, tmpbuffer, numBytes, j, (numBytes)- j);
			}
		}
		if (numBytes < len) 
		{
			break;
		} 
		else
		{
			encodeLineSuffix(outStream);
		}
	}
	encodeBufferSuffix(outStream);
}

void CharacterEncoder::encode(char* aBuffer, int len, OutputStream& aStream) 
{
	ByteArrayInputStream inStream(aBuffer, len);
	encode(inStream, aStream);
}

WString CharacterEncoder::encode(char* aBuffer, int len) 
{
	ByteArrayOutputStream outStream ;
	ByteArrayInputStream  inStream(aBuffer,len);
	WString retVal;

	try 
	{
		encode(inStream, outStream);
		// explicit ascii->unicode conversion
		//retVal = outStream.toString("8859_1");
		retVal = outStream.toString();
	}
	catch (Exception&) 
	{
		// This should never happen.
		throw Error("CharacterEncoder::encodeBuffer internal error");
	}
	return (retVal);
}

void CharacterEncoder::encodeBuffer(InputStream& inStream, OutputStream& outStream) 
{
	int	j;
	int	numBytes;
	int len = bytesPerLine();
	char*	tmpbuffer = new char[len];
	ArrayJanitor<char> tmpbufferJanitor(tmpbuffer);
	memset(tmpbuffer,0,len);

	encodeBufferPrefix(outStream);
	const int bpa=bytesPerAtom();

	while (true) 
	{
		numBytes = readFully(inStream, tmpbuffer,len);
		if (numBytes == 0) 
		{
			break;
		}
		encodeLinePrefix(outStream, numBytes);
		for (j = 0; j < numBytes; j += bpa) 
		{
			if ((j + bpa) <= numBytes) 
			{
				encodeAtom(outStream, tmpbuffer, numBytes, j, bpa);
			} else 
			{
				encodeAtom(outStream, tmpbuffer, numBytes, j, (numBytes)- j);
			}
		}
		encodeLineSuffix(outStream);
		if (numBytes < len) 
		{
			break;
		} 
	}
	encodeBufferSuffix(outStream);
}

void CharacterEncoder::encodeBuffer(char* aBuffer, int len, OutputStream& aStream) 
{
	ByteArrayInputStream inStream(aBuffer, len);
	encodeBuffer(inStream, aStream);
}

WString CharacterEncoder::encodeBuffer(char* aBuffer, int len) 
{
	ByteArrayOutputStream outStream;
	ByteArrayInputStream  inStream(aBuffer, len);
	try
	{
		encodeBuffer(inStream, outStream);
	}
	catch (Exception&) 
	{
		// This should never happen.
		throw Error("ChracterEncoder::encodeBuffer internal error");
	}
	return (outStream.toString());
}

} // namespace JDF
