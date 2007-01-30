/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2002 The International Cooperation for the Integration of 
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

#include "QPDecoder.h"

#include "QPEncoder.h"
#include "InputStream.h"
#include "OutputStream.h"
#include "PrintStream.h"

#include <string>

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

int QPDecoder::hexchar(int c) 
{
	c = toUpperCase(c);
	for (int i = 0; i < 16; i++)
	{
		if (QPEncoder::basis_hex[i] == c)
			return i;
	}
	return -1;
}

int QPDecoder::toUpperCase(int c)
{
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 'A');
	return c;
}

std::string readLine(InputStream& in,bool& eof)
{
	std::string line("");

	eof = false;

	int c;
	do 
	{
		c = in.read();
		if (c==-1)
		{
			if (line.length() == 0) 
				eof = true;
			return line;
		}
		//bool flag = false;
		//int i = 0;
		if (c == '\n')
			c = in.read();

		while (c!=10 && c!=13)
		{
			if (c == -1)
				return line;
			// 220502 SF added (char) cast
			line.append(1,(char)c);
			c = in.read();
		}
		return line;
	} while(1);
}


ByteBuffer* QPDecoder::decodeBuffer(const WString& inputString)
{
	return CharacterDecoder::decodeBuffer(inputString);
}

ByteBuffer* QPDecoder::decodeBuffer(InputStream& in)
{
	return CharacterDecoder::decodeBuffer(in);
}

void QPDecoder::decodeBuffer(InputStream& in, OutputStream& out)
{
	int c1, c2, linelen;
	std::string s;
	PrintStream ps(out);
	bool eof;
	
	s = readLine(in,eof);

	while (!eof) 
	{
		linelen = s.length();
		
		for (int i = 0; i < linelen; i++) 
		{
			if (s[i] == '=') 
			{
				if (++i >= linelen) 
					break;
				if (s[i] != '\n')
				{  // ignore "soft" line breaks
					c1 = hexchar(s[i]);
					if (++i >= linelen) break;
					c2 = hexchar(s[i]);
					out.write(c1 << 4 | c2);
				}
			} else 
			{
				out.write(s[i]);
			}
		}
		// we rely on PrintStream to create platform-specific newlines:
		if (linelen == 0 || (linelen > 0 && s[linelen - 1] != '='))
			ps.println();
		s = readLine(in,eof);
	}
}

} // namespace JDF
