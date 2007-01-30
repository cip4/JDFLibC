/*
 * The CIP4 Software License, Version 0.1
 *
 *
 * Copyright (c) 2001 The International Cooperation for the Integration of 
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

#include "QPEncoder.h"

#include "PrintStream.h"
#include "InputStream.h"


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

char QPEncoder::hexmap[] = {'0', '1', '2', '3', '4', '5', '6', '7',
							'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
 

char QPEncoder::basis_hex[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
int QPEncoder::index_hex[] = {
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
     0, 1, 2, 3,  4, 5, 6, 7,  8, 9,-1,-1, -1,-1,-1,-1,
    -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,10,11,12, 13,14,15,-1, -1,-1,-1,-1, -1,-1,-1,-1,
    -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1
  };
  
QPEncoder::QPEncoder() 
{
}

//  TODO, for compatibility

int QPEncoder::bytesPerAtom()
{
	return 2;
}

int QPEncoder::bytesPerLine()
{
    return 80;
}

void QPEncoder::encodeAtom(OutputStream& aStream,char* someBytes, int len,
		int anOffset, int aLength)
{
}


void QPEncoder::encodeBuffer(InputStream& input, OutputStream& out)
{

	PrintStream ps(out);
	char current = (char)0;
	char previous = (char)0;
	int read;
	// int written = 0;
	int lastspace = 0;
	int nullCount = 0;
	char l_bufenc[80];
	int linelen=0;

	while (true)
	{
		read = input.read();
		if (read == -1)
		{
			if (linelen >0)
			{
				ps.write(l_bufenc,80,0,linelen);
				ps.println();
			}
			return;
		}
		current = (char) read;
		if (current == 0x00)
		{
			nullCount++;
			previous = current;
			lastspace = 0;
			continue;
		}
		else if (nullCount > 0)
		{
			// write out all the nulls and fall through to process current c
			for (int idx = 1; idx <= nullCount; idx++)
			{
				char tmp = 0x00;
				l_bufenc[linelen++] = '=';
				l_bufenc[linelen++] = (char) hexmap[((tmp>>4) + (2<<27)) & 0xf];
				l_bufenc[linelen++] = (char) hexmap[tmp & 0xf];

				if (linelen > 74)
				{
					ps.write(l_bufenc,80,0,linelen);
					ps.write('=');
					ps.println();
					linelen=0;
				}
			}
			previous = (char) 0;
			nullCount = 0;
		}
		if ((current > ' ') && (current < 0x7f) && (current != '='))
		{
			// Printable chars
			l_bufenc[linelen++] = (char) current;
			lastspace = 0;
			previous = current;
		}
		else if ((current == ' ') || (current == '\t'))
		{
			l_bufenc[linelen++] = (char) current;
			lastspace = 1;
			previous = current;
		}
		else if ((current == '\n') && (previous == '\r'))
		{
			// handled this already.Ignore
			previous = (char) 0;
		}
		else if ((current == '\r') || (current == '\n'))
		{
			// need to emit a soft line break if last char was SPACE/HT or
			// if we have a period on a line by itself
			if ((lastspace == 1) || ((previous == '.') && (linelen == 1)))
			{
				l_bufenc[linelen++] = '=';
				l_bufenc[linelen++] = '\r';
				l_bufenc[linelen++] = '\n';
			}
			l_bufenc[linelen++] = '\r';
			l_bufenc[linelen++] = '\n';
			lastspace = 0;
			ps.write(l_bufenc,80,0,linelen);
			previous = (char)current;
			linelen = 0;
		}
		else if ((current < ' ') || (current == '=') || (current >= 0x7F))
		{
			l_bufenc[linelen++] = '=';
			l_bufenc[linelen++] = (char) hexmap[((current>>4) + (2<<27)) & 0xf];
			l_bufenc[linelen++] = (char) hexmap[(current & 0xf)];
			lastspace = 0;
			previous = current;
		}
		else
		{
			l_bufenc[linelen++] = (char) current;
			lastspace = 0;
			previous = current;
		}
		if (linelen > 74)
		{
			ps.write(l_bufenc,80,0,linelen);
			ps.write('=');
			ps.println();
			linelen=0;
			previous = (char) 0;
		}
	} // while
}

/*
	int c, ct = 0, prevc = 255;

	while ((c = input.read()) > -1) 
	{
		if ((c < 32 && (c != '\n' && c != '\t'))
		  || (c == '=')
		  || (c >= 127)
		  // Following line is to avoid single periods alone on lines,
		  //	 which messes up some dumb smtp implementations, sigh... 
		  || (ct == 0 && c == '.')) 
		{
			out.write('=');
			out.write(basis_hex[c >> 4]);
			out.write(basis_hex[c & 0xF]);
			ct += 3;
			prevc = 'A'; // close enough 
		}
		else if (c == '\n') 
		{
			if (prevc == ' ' || prevc == '\t') 
			{
			  out.write('='); // soft & hard lines 
			  out.write(c);
			}
			out.write(c);
			ct = 0;
			prevc = c;
		} 
		else 
		{
			out.write(c);
			++ct;
			prevc = c;
		}
		if (ct > 72) 
		{
			out.write('=');
			out.write('\n');
			ct = 0;
			prevc = '\n';
		}
	}
	if (ct != 0) 
	{
	  out.write('=');
	  out.write('\n');
	}
}
*/

} // namespace JDF
