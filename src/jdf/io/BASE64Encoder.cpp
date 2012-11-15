/*
 * The CIP4 Software License, Version 1.0
 *
 *
 * Copyright (c) 2001-2012 The International Cooperation for the Integration of 
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

#include "BASE64Encoder.h"

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

 /** This array maps the characters to their 6 bit values */
char BASE64Encoder::pem_array[] = {
	//       0   1   2   3   4   5   6   7
		'A','B','C','D','E','F','G','H', // 0
		'I','J','K','L','M','N','O','P', // 1
		'Q','R','S','T','U','V','W','X', // 2
		'Y','Z','a','b','c','d','e','f', // 3
		'g','h','i','j','k','l','m','n', // 4
		'o','p','q','r','s','t','u','v', // 5
		'w','x','y','z','0','1','2','3', // 6
		'4','5','6','7','8','9','+','/'  // 7
	};


BASE64Encoder::BASE64Encoder() 
{
}

size_t BASE64Encoder::bytesPerAtom() 
{
	return (3);
}

size_t BASE64Encoder::bytesPerLine() 
{
	return (57);
}

void BASE64Encoder::encodeAtom(OutputStream& outStream, char* data, size_t datalen, size_t offset, size_t len) 
{
	char a, b, c;
	char outBuf[4];
	char* outChar=outBuf;

	if (len == 1) 
	{
	    a = data[offset];
	    b = 0;
	    c = 0;
	    *outChar++ = pem_array[((a>>2) + (2<<29)) & 0x3F];
	    *outChar++ = pem_array[((a << 4) & 0x30) + (((b>>4) + (2<<27)) & 0xf)];
	    *outChar++ = '=';
	    *outChar = '=';
	}
	else if (len == 2) 
	{
	    a = data[offset];
	    b = data[offset+1];
	    c = 0;
	    *outChar++ = pem_array[((a>>2) + (2<<29)) & 0x3F];
	    *outChar++ = pem_array[((a << 4) & 0x30) + (((b>>4) + (2<<27)) & 0xf)];
	    *outChar++ = pem_array[((b << 2) & 0x3c) + (((c>>6) + (2<<25)) & 0x3)];
	    *outChar  = '=';
	}
	else 
	{
	    a = data[offset];
	    b = data[offset+1];
	    c = data[offset+2];
	    *outChar++ = pem_array[((a>>2) + (2<<29)) & 0x3F];
	    *outChar++ = pem_array[((a << 4) & 0x30) + (((b>>4) + (2<<27)) & 0xf)];
	    *outChar++ = pem_array[((b << 2) & 0x3c) + (((c>>6) + (2<<25)) & 0x3)];
	    *outChar  = pem_array[c & 0x3F];
	}
	outStream.write(outBuf,4);
}

} // namespace JDF
