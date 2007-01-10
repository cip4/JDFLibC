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

#include "BASE64Decoder.h"

#include "InputStream.h"
#include "OutputStream.h"


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

const char BASE64Decoder::pem_convert_array[] = {
	 -1, -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  62,  -1,  -1,  -1,  63,  52,
	 53,  54,  55,  56,  57,  58,  59,  60,
	 61,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 0,  1,  2,  3,  4,  5,  6,  7,
	 8,  9,  10,  11,  12,  13,  14,  15,
	 16,  17,  18,  19,  20,  21,  22,  23,
	 24,  25,  -1,  -1,  -1,  -1,  -1,  -1,
	 26,  27,  28,  29,  30,  31,  32,  33,
	 34,  35,  36,  37,  38,  39,  40,  41,
	 42,  43,  44,  45,  46,  47,  48,  49,
	 50,  51,  -1,  -1,  -1,  -1,  -1,  -1,

	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,

	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,

	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,

	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
	 -1,  -1,  -1,  -1,  -1,  -1,  -1 };


void BASE64Decoder::decodeAtom(InputStream& inStream, OutputStream& outStream, int rem) 
{
	int	i;
	char	a = -1, b = -1, c = -1, d = -1;

	if (rem < 2) {
	    throw CEFormatException("BASE64Decoder: Not enough bytes for an atom.");
	}
	do 
	{
	    i = inStream.read();
	    if (i == -1) 
			throw CEStreamExhausted();
	} 
	while (i == '\n' || i == '\r');

	decode_buffer[0] = (char) i;

	i = readFully(inStream, decode_buffer,4, 1, rem-1);
	if (i == -1) 
	    throw CEStreamExhausted();

	if (rem > 3 && decode_buffer[3] == '=') 
	    rem = 3;

	if (rem > 2 && decode_buffer[2] == '=') 
	    rem = 2;

	switch (rem) 
	{
	case 4:
	    d = (char) pem_convert_array[decode_buffer[3] & 0xff];
	    // NOBREAK
	case 3:
	    c = (char)pem_convert_array[decode_buffer[2] & 0xff];
	    // NOBREAK
	case 2:
	    b = (char)pem_convert_array[decode_buffer[1] & 0xff];
	    a = (char)pem_convert_array[decode_buffer[0] & 0xff];
	    break;
	}

	switch (rem) 
	{
	case 2:
	    outStream.write( (char)(((a << 2) & 0xfc) | (((b>>4) + (2<<27)) & 3)) );
	    break;
	case 3:
	    outStream.write( (char) (((a << 2) & 0xfc) | (((b>>4) + (2<<27)) & 3)) );
	    outStream.write( (char) (((b << 4) & 0xf0) | (((c>>2) + (2<<29)) & 0xf)) );
	    break;
	case 4:
	    outStream.write( (char) (((a << 2) & 0xfc) | (((b>>4) + (2<<27)) & 3)) );
	    outStream.write( (char) (((b << 4) & 0xf0) | (((c>>2) + (2<<29)) & 0xf)) );
	    outStream.write( (char) (((c << 6) & 0xc0) | (d  & 0x3f)) );
	    break;
	}
	return;
}

} // namespace JDF
