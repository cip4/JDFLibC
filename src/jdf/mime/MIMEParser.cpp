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

#include "MIMEParser.h"

#include <jdf/mime/MIMEBasicPart.h>
#include <jdf/mime/MIMEMessagePart.h>
#include <jdf/mime/MIMEMultiPart.h>
#include <jdf/mime/MIMEMessage.h>
#include <jdf/mime/MIMEMemResourceFactory.h>
#include <jdf/lang/Exception.h>

#include <jdf/net/URLDecoder.h>
#include <jdf/io/ByteArrayInputStream.h>
#include <jdf/io/BASE64Decoder.h>
#include <jdf/io/QPDecoder.h>
#include <jdf/io/BufferedOutputStream.h>

#include <xercesc/util/XMLUniDefs.hpp>
#include <typeinfo> //SF160502 needed by STLPORT, otherwise typeid::operator== is undefined //AXEL20020906


XERCES_CPP_NAMESPACE_USE

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

const int MIMEParser::MIME_INFO_CONTENT_TYPE               = 1;
const int MIMEParser::MIME_INFO_CONTENT_SUBTYPE            = 2;
const int MIMEParser::MIME_INFO_CONTENT_TRANSFER_ENCODING  = 3;
const int MIMEParser::MIME_INFO_CONTENT_DISPOSITION        = 4;
const int MIMEParser::MIME_INFO_CONTENT_ID                 = 5;
const int MIMEParser::MIME_INFO_CONTENT_DESCRIPTION        = 6;
const int MIMEParser::MIME_INFO_CONTENT_BASE               = 7;
const int MIMEParser::MIME_INFO_MIME_VERSION               = 8;
const int MIMEParser::BUFFER_SIZE                          = 2048;
const int MIMEParser::SUBTYPE_RFC822                       = 1;
const int MIMEParser::SUBTYPE_EXTERNAL_BODY                = 2;
const char* MIMEParser::mb_MultiPart   = "Multipart";
const char* MIMEParser::mb_MessagePart = "Message";
const char* MIMEParser::mb_TextPart    = "Text";
const char* MIMEParser::mb_AudioPart   = "Audio";
const char* MIMEParser::mb_VideoPart   = "Video";
const char* MIMEParser::mb_ImagePart   = "Image";
const char* MIMEParser::mb_ApplPart    = "Application";
const char* MIMEParser::CRLF           = "\r\n";
const int MIMEParser::MIME_INFO          = 31;
const int MIMEParser::MIME_HEADER       = 32;
const int MIMEParser::MIME_XHEADER      = 33;
const int MIMEParser::MIME_MESSAGE_DATA  = 34;
const int MIMEParser::MIME_PARAM         = 35;
const int MIMEParser::MIME_BOUNDARY      = 36;
const int MIMEParser::MIME_CRLF          = 37;

const int MIMEParser::MIME_UNINITIALIZED = -88;
const int MIMEParser::MIME_CONTENT_PARSE_ALL = -99;

const int MIMEParser::NSMAIL_ERR_INVALIDPARAM = -1;
const int MIMEParser::NSMAIL_ERR_OUTOFMEMORY = -2;
const int MIMEParser::NSMAIL_OK = 0;

const int MIMEParser::NOT_A_BOUNDARY = 21;
const int MIMEParser::START_BOUNDARY = 22;
const int MIMEParser::END_BOUNDARY   = 23;

LineBufferOutputStream::LineBufferOutputStream(OutputStream* os) :
	nrBytes(0)
{
	mRealOs = os;
	mOs = new BufferedOutputStream(*os,64000);
}

void LineBufferOutputStream::close()
{
	flush();
	mOs->close();
}

void LineBufferOutputStream::flush()
{
	mOs->write(last2Bytes,nrBytes);
	mOs->flush();
	nrBytes = 0;
}

void LineBufferOutputStream::write(char* b, int blen)
{
	if (blen == 0)
		return;
	if (blen == 1)
		write(b[0]);
	else
	{
		if (nrBytes)
			mOs->write(last2Bytes,nrBytes);
		mOs->write(b,blen-2);
		last2Bytes[0] = b[blen-2];
		last2Bytes[1] = b[blen-1];
		nrBytes=2;
	}
}

/**
remove last cr/lf after checking that they werent anythin else 
*/
void LineBufferOutputStream::removeLast2Bytes() 
{
	// RP 060321 maybe the second to last byte was not a cr/lf... 
	if(last2Bytes[0] != 0xa && last2Bytes[0] != 0xd)
		mOs->write(last2Bytes[0]);

	nrBytes = 0;
}

void LineBufferOutputStream::write(char* b, int blen, int off, int len)
{
	write(b+off,len);
}

void LineBufferOutputStream::write(int b)
{
	if (nrBytes == 0)
	{
		last2Bytes[0] = b;
		nrBytes=1;
		return;
	}
	if (nrBytes == 1)
	{
		last2Bytes[1] = b;
		nrBytes = 2;
		return;
	}
	else if (nrBytes == 2)
	{
		mOs->write(last2Bytes[0]);
		last2Bytes[0] = last2Bytes[1];
		last2Bytes[1] = b;
	}

}

class MIMEHelper
{
public:

	static const char* szERROR_BAD_PARAMETER;
	static const char* szERROR_OUT_OF_MEMORY; 
	static const char* szERROR_UNSUPPORTED_PARTIAL_SUBTYPE;
	static const char* szERROR_BAD_EXTERNAL_MESSAGE_PART;
	static const char* szERROR_EMPTY_MESSAGE;
	static const char* szERROR_BAD_MIME_MESSAGE;

	static std::pair<char*,int> decodeBase64LeftOverBytes(int out_bits, int out_byte);

	static std::pair<char*,int> decodeBase64Vector( std::vector<std::string>& v, int nStart, int nEnd, int nMessageLen, int param[] );

	static int hexdigit(char ch);

	/**
	 * QuotedPrintable Decodes data from vector, write decoded data to szOutput
	 *
	 * params :
	 *
	 * @param nStart starting element in vector
	 * @param nEnd ending element in vector
	 * @param v vector
	 * @param szOutput output buffer
	 * @param MaxBufferSize : max buffer size
	 *
	 * return : number of decoded bytes
	 */
	static std::pair<char*,int> decodeQPVectorNew( std::vector<std::string>& v, int nStart, int nEnd, int param[], char* leftOverBytes );

	/**
     * determine if both strings are the same based on the length of the second string
     * case insensitive
	 * @return true if equal
	 */

	static bool bStringEquals(const char* s1, int len1, const char* s2, int len2);
	static bool bStringEquals(const char* s1, int len1, const WString& s2);

private:

	static char base64map[];
	static char Base64DecMap[];
};

const char* MIMEHelper::szERROR_BAD_PARAMETER = "Error: Bad parameter";
const char* MIMEHelper::szERROR_OUT_OF_MEMORY = "Error: Out of memory";
const char* MIMEHelper::szERROR_UNSUPPORTED_PARTIAL_SUBTYPE = "Error: Unsupported Partial SubType";
const char* MIMEHelper::szERROR_BAD_EXTERNAL_MESSAGE_PART = "Error:  No External headers in Message/external-body";
const char* MIMEHelper::szERROR_EMPTY_MESSAGE = "Error: Empty message";
const char* MIMEHelper::szERROR_BAD_MIME_MESSAGE = "Error: Bad mime message";
  
   
char MIMEHelper::base64map[] =
         {//      0   1   2   3   4   5   6   7
                'A','B','C','D','E','F','G','H', // 0
                'I','J','K','L','M','N','O','P', // 1
                'Q','R','S','T','U','V','W','X', // 2
                'Y','Z','a','b','c','d','e','f', // 3
                'g','h','i','j','k','l','m','n', // 4
                'o','p','q','r','s','t','u','v', // 5
                'w','x','y','z','0','1','2','3', // 6
                '4','5','6','7','8','9','+','/'  // 7
         };

//	memset(Base64DecMap,0,128);
//	for ( int idx = 0; idx < 64; idx++ )
//		Base64DecMap[ base64map[idx] ] = (char) idx;
 
char MIMEHelper::Base64DecMap[] =
{
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  62,  0,  0,  0,  63,
	 52,  53,  54,  55,  56,  57,  58,  59,  60,  61,  0,  0,  0,  0,
	 0,  0,  0,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11,  12,
	 13,  14,  15,  16,  17,  18,  19,  20,  21,  22,  23,  24,  25,
	 0,  0,  0,  0,  0,  0,  26,  27,  28,  29,  30,  31,  32,  33,
	 34,  35,  36,  37,  38,  39,  40,  41,  42,  43,  44,  45,  46, 
	 47,  48,  49,  50,  51,  0,  0,  0,  0,  0
};

int MIMEHelper::hexdigit(char ch)
{
	char c = tolower(ch);
	int tmp;
	if ((int) c >= (int)'a')
		tmp = (int) (c - 'a' + 10);
	else
		tmp = (int) (c - '0');

	return tmp;
}

static char toLower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a'-'A';
	else
		return c;
}

std::pair<char*,int> MIMEHelper::decodeBase64LeftOverBytes( int out_bits, int out_byte )
{
	int		mask;
	char*   output = new char[4];
	int     byte_pos = 0;
 
	 /* Handle any bits still in the queue */
	 while (out_bits >= 8)
	 {
		 if (out_bits == 8)
		 {
				 output[byte_pos++] = (char) out_byte;
				 out_byte = 0;
		 }

		 else
		 {
				 mask = out_bits == 8 ? 0xFF : (0xFF << (out_bits - 8));
				 output[byte_pos++] = (char) ( (out_byte & mask) >> (out_bits - 8) );
				 out_byte &= ~mask;
		 }
		 out_bits -= 8;
	 }
	 return std::pair<char*,int>(output,byte_pos);
}

bool MIMEHelper::bStringEquals(const char* s1, int len1, const char* s2, int len2)
{
	char ch;

	if ( s1 != NULL && s2 != NULL )
	{
		if ( len2 > len1 )
			return false;

		for ( int i = 0; i < len2; i++ )
		{
			ch = s2[i];

			// lowercase
			if ( ch >= 97 )
			{
				if ( s1[i] != ch && s1[i] != ( ch - 32 ) )
					return false;
			}
			else if ( s1[i] != ch && s1[i] != ( ch + 32 ) )
				return false;
		}
		return true;
	}
	return false;
}

bool MIMEHelper::bStringEquals(const char* s1, int len1, const WString& s2)
{
	JDFCh ch;
	
	if (s1)
	{
		int len2 = s2.length();
		if ( len2 > len1 )
			return false;
		
		for ( int i = 0; i < len2; i++ )
		{
			ch = s2[i];
			
			// lowercase
			if ( ch >= 97 )
			{
				if ( s1[i] != ch && s1[i] != ( ch - 32 ) )
					return false;
			}
			else if ( s1[i] != ch && s1[i] != ( ch + 32 ) )
				return false;
		}
		
		return true;
	}
	return false;
}


std::pair<char*,int> MIMEHelper::decodeBase64Vector(std::vector<std::string>& v, int nStart, int nEnd, int nMessageLen, int param[] )
{
	int      add_bits;
	unsigned int      out_byte = 0;
	int      out_bits = 0;
	int      byte_pos = 0;
	int      i, j, nLen = 0, nTotalLen = 0;
	char*    szLine;
	char*    output;
	
	// restore previous state
	out_byte = param[0];
	out_bits = param[1];
	
	// invalid range
	if ( nStart == -1 || nEnd == -1 )
		return std::pair<char*,int>(NULL,0);
	
	// get message len
	for ( j = nStart; j <= nEnd; j++ )
	{
		szLine = (char*) v[j].data();
		nTotalLen = nTotalLen +  v[j].length();
	}
	output = new char[ nTotalLen ];
	
	if ( output == NULL )
		throw MIMEException( szERROR_OUT_OF_MEMORY );
	
	// read off data from vector line by line
	for ( j = nStart; j <= nEnd; j++ )
	{
		szLine = (char*) v[j].data();
		nLen = v[j].length();
		
		// process line
		for ( i = 0; i < nLen && szLine[i] != 0; i++ )
		{
				add_bits = (int) Base64DecMap[static_cast<unsigned int>(szLine[i])];
			
			if (add_bits >= 64)
				continue;
			
			out_byte = (out_byte << 6) + add_bits;
			out_bits += 6;
			
			// If the queue has gotten big enough, put into the buffer
			if (out_bits >= 24)
			{
				if ( byte_pos < nTotalLen - 3 )
				{
					output[byte_pos++] = (char) ( (out_byte & 0xFF0000) >> 16 );
					output[byte_pos++] = (char) ( (out_byte & 0x00FF00) >> 8 );
					output[byte_pos++] = (char) ( (out_byte & 0x0000FF) );
					out_bits = 0;
					out_byte = 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	
	// save current state
	param[0] = out_byte;
	param[1] = out_bits;
	param[2] = byte_pos;
	return std::pair<char*,int>(output,byte_pos);
}

std::pair<char*,int> MIMEHelper::decodeQPVectorNew( std::vector<std::string>& v, int nStart, int nEnd, int param[], char* leftOverBytes )
{
	int i = 0, j = 0, ii = 0, nLen = 0, written=0;
	char* line;
	char* buffer;
	char* retbuf;
	char token[3];
	int nNoOfLeftOverBytes;
	int lineLength;
	
	if ( nStart == -1 || nEnd == -1 )
		return std::pair<char*,int>(NULL,0);
	
	nNoOfLeftOverBytes = param[0];
	
	// get message len
	nLen = nNoOfLeftOverBytes;
	for (j = nStart; j <= nEnd; j++)
	{
		nLen += v[j].length();
	}
	
	j = 0;
	buffer = new char[(int) (nLen * 1.1)];
	
	if (buffer == NULL)
		throw MIMEException( szERROR_OUT_OF_MEMORY );
	
	nLen = 0;
	/* get each line */
	for ( ii = nStart; ii <= nEnd; ii++ )
	{
		line = (char*) v[ii].data();
		lineLength = v[ii].length();
		
		if (ii == nStart && nNoOfLeftOverBytes > 0)
		{
			memcpy(buffer,leftOverBytes,nNoOfLeftOverBytes);
			nLen += nNoOfLeftOverBytes;
		}
		
		if (line ==NULL || lineLength == 0)
			continue;
		memcpy(buffer+nLen,line,lineLength);
		nLen += lineLength;
	}
	
	written = 0; i=0;
	int read_offset = 0;
	
	/* first time do it outside the loop */
	while (i < 3 && read_offset < nLen)
	{
		token [i++] =  buffer [read_offset++];
	}
	
	while (read_offset < nLen || i != 0)
	{
		while (i < 3 && read_offset < nLen)
		{
			token [i++] =  buffer [read_offset++];
		}
		
		if (i < 3) /* did not get enough for a token */
		{
			if (i == 2 && token [0] == '\r' && token [1] == '\n')
			{
				buffer[written++] = token[0];
				buffer[written++] = token[1];
				nNoOfLeftOverBytes = 0;
			}
			else
			{
				for (j=0; j < i; j++)
					leftOverBytes [j] = token [j];
				nNoOfLeftOverBytes = i;
			}
			param[0] = nNoOfLeftOverBytes;
			if (written > 0)
			{
				retbuf = new char [written];
				memcpy(retbuf,buffer,written);
				delete buffer;
				buffer=0;
				param[1] = written;
				return std::pair<char*,int>(retbuf,written);
			}
		}
		i = 0;
		if (token[0] == '=')
		{
			char c = (char)0;
			if ((token[1] >= '0' && token[1] <= '9') ||
				(token[1] >= 'A' && token[1] <= 'F') ||
				(token[1] >= 'a' && token[1] <= 'f'))
				c = token[1];
			else if (token[1] == '\r'|| token[1] == '\n')
			{
				/* =\n means ignore the newline. */
				if (token[1] == '\r' && token[2] == '\n')
					;               /* swallow all three chars */
				else
				{
					read_offset--;     /* put the third char back */
				}
				continue;
			}
			else
			{
			/* = followed by something other than hex or newline -
			pass it through unaltered, I guess.
				*/
				if (read_offset > written) { buffer[written++] = token[0]; }
				if (read_offset > written) { buffer[written++] = token[1]; }
				if (read_offset > written) { buffer[written++] = token[2]; }
				continue;
			}
			
			/* Second hex digit */
			if ((token[2] >= '0' && token[2] <= '9') ||
				(token[2] >= 'A' && token[2] <= 'F') ||
				(token[2] >= 'a' && token[2] <= 'f'))
				c = (char) ((hexdigit(c) << 4) | hexdigit(token[2]));
			else
			{
			/* We got =xy where "x" was hex and "y" was not, so
				treat that as a literal "=", x, and y. */
				if (read_offset > written) { buffer[written++] = token[0];}
				if (read_offset > written) { buffer[written++] = token[1];}
				if (read_offset > written) { buffer[written++] = token[2];}
				continue;
			}
			
			buffer[written++] = c;
		}
		else
		{
			buffer[written++] = token[0];
			
			token[0] = token[1];
			token[1] = token[2];
			i = 2;
		}
	}
	
	param[0] = 0; // nothing leftover
	if (written > 0)
	{
		retbuf = new char [written];
		memcpy(retbuf,buffer,written);
		delete buffer;
		buffer=0;
		param[1] = written;
		return std::pair<char*,int>(retbuf,written);
	}
	
	delete buffer;
	buffer=0;
	param[1] = 0;
	return std::pair<char*,int>(NULL,0);
}


MIMEParser::MIMEParser(MIMEResourceFactory* factory, MIMEMessage* m)
{
	if (factory==NULL)
	{
		m_myDelete = true;
		m_Factory  = new MIMEMemResourceFactory();
	}
	else 
	{
		m_myDelete = false;
		m_Factory  = factory;
	}
	m_bDecodedData      = true;
	m_bLocalStorage     = true;
	m_qp                = false;
	m_binary			= false;
	m_readCR            = false;
	m_fSeenBoundary     = false;
	m_fEndMessageHeader = false;
	m_emptyLineNo = 0; //060320 RP
	init(m);
}

MIMEParser::~MIMEParser()
{
	delete m_leftoverBuffer;
	delete m_inputBuffer;
	delete m_QPLeftoverBuffer;
	//delete m_messageByteData;
	if (m_mimeMessage)
		delete m_mimeMessage;
	if (m_myDelete)
		delete m_Factory;
}

void MIMEParser::init(MIMEMessage* m)
{
	m_mimeMessage = (m == NULL) ? new MIMEMessage() : m;
	m_bStartData  = false;
	m_mimeMessage->m_parsedPart = 1;
	m_nMessageType = MIME_UNINITIALIZED;
	m_nCurrentMessageType = MIME_UNINITIALIZED;
	m_currentMessage = NULL;

	m_leftoverBuffer = new char[BUFFER_SIZE];
	m_inputBuffer = new char[BUFFER_SIZE];
	m_leftoverBytes = 0;
	m_out_byte = 0;
	m_out_bits = 0;
	m_currentBasicPart   = NULL;
	m_currentMultiPart   = NULL;
	m_currentMessagePart = NULL;
	m_bParseEntireFile   = false;
	m_currentMimeMessage = m_mimeMessage;
	m_currentParent.push_back(m_mimeMessage);
	m_nextMimeMessage  = NULL;
	m_lastBoundry      = START_BOUNDARY;
	m_QPLeftoverBuffer = new char[2];
	m_QPLeftoverBytes  = 0;
	m_qp     = false;
	m_binary = false;
	m_readCR = false;
	m_headerParent       = m_mimeMessage;
	m_nextHeaderParent   = NULL;
	m_previousHeaderName = "";
	m_messagePartSubType = SUBTYPE_RFC822;
	m_fEndMessageHeader  = false;
	//m_messageByteData = new MIMEByteBuffer();
}

void MIMEParser::reInit(MIMEMessage* m)
{
	if (m_mimeMessage){
		delete m_mimeMessage;
		m_mimeMessage=0;
	}
	// todo 
	// only for callback stuff
}

MIMEMessage* MIMEParser::parseEntireMessage(InputStream& input)
{
	//init(NULL);
	return (MIMEMessage*) parseMimeMessage(input,MIME_CONTENT_PARSE_ALL);
}

void MIMEParser::beginParse()
{
	m_leftoverBytes   = 0;
	m_QPLeftoverBytes = 0;
	m_out_byte        = 0;
	m_out_bits        = 0;
	reInit(NULL);
}

void MIMEParser::parse(InputStream& input)
{
	parseMimeMessage(input,MIME_CONTENT_PARSE_ALL);
}

void MIMEParser::endParse()
{
	decodeDataBuffer();

	//TODO
	// if (m_dataSink)..

	MIMEBodyPart* m = (MIMEBodyPart*) m_currentMessage;
	// take care of of leftover bytres
	if (m_nCurrentMessageType == MIMEMessage::BASICPART)
	{
		MIMEBasicPart* mimeBasicPart = (MIMEBasicPart*) m_currentMessage;

		/* base64 */
		if (mimeBasicPart->getContentEncoding() == MIMEBodyPart::BASE64 && m_out_bits > 0)
		{
			// TODO support for BASE64 decode buffer

			//std::pair<char*,int> decodedBuffer = MIMEHelper::decodeBase64LeftOverBytes(m_out_bits,m_out_byte);			
			//saveBodyData(new ByteBuffer(decodedBuffer.first,decodedBuffer.second),decodedBuffer.second,mimeBasicPart);
			//delete[] decodedBuffer.first;
			//decodedBuffer.first=0;
		}

		// todo
		/// callbackstuff
	}
	else if (m_nCurrentMessageType == MIMEMessage::MULTIPART)
	{
		// todo
		/// callbackstuff
	}
	else if (m_nCurrentMessageType == MIMEMessage::MESSAGEPART)
	{
		// todo
		/// callbackstuff
		std::vector<MIMEMessagePart*>::iterator it = m_msgParts.begin();
		while (it != m_msgParts.end())
		{
			if ((*it) == (MIMEMessagePart*)m)
			{
				it =m_msgParts.erase(it);
			}
			else
				it++;
		}
	}

	// systematically invoke end* callback on all pending parts
	int nCurrentParentType = getCurrentParentType();

	while (nCurrentParentType != MIME_UNINITIALIZED)
	{
		if (nCurrentParentType == MIMEMessage::MULTIPART)
		{
             // ingore. taken care of at END_BOUNDARY!       
		}
		else if (nCurrentParentType == MIMEMessage::MESSAGEPART)
		{
			MIMEMessagePart* msgP = (MIMEMessagePart*) m_currentParent.back();
			MIMEMessagePart::value_pair cst = msgP->getContentSubType();
			if (cst.first && cst.second.equalsIgnoreCase("rfc822"))
			{
				 // todo
				// callback stuff
			}
		}
	}
	// ..
	// todo callback stuff
}

// currently only returns message objects
MIMEMessage* MIMEParser::parseMimeMessage(InputStream& input, int nMessageType)
{
	char ch = 0;
	int type, lineLen, messageLen;
	int i=0,j=0,ii;
	bool lastLine = false;
	bool bMoreData = true;

	type = MIME_HEADER;

	try
	{
		messageLen = input.available();
		for (i=0,j=m_leftoverBytes;bMoreData;)
		{
			lineLen = input.read(m_inputBuffer,BUFFER_SIZE);

			if (lineLen < 0)
				break; //eof

			i = i+lineLen;

			for (ii=0;ii<lineLen;ii++)
			{
				ch = m_inputBuffer[ii];
				//if (ch == -1)
				//	break;
				// eat it
				if (!m_readCR && ch == '\r')
					continue;
				else if (ch == '\n')
				{
					// look for continuation
					if (MIMEHelper::bStringEquals(m_leftoverBuffer,j,"content-",8))
					{
						int jj = j > 0 ? j-1:0;
						char ch2;

						for ( ch2 = (char) m_leftoverBuffer[jj]; jj > 0 && isspace( ch2 ); ch2 = (char) m_leftoverBuffer[--jj] )
                                 ;
 
						// implement look ahead logic
						if ( ( m_inputBuffer[ii+1] == ' ' || m_inputBuffer[ii+1] == '\t' ) &&
							!MIMEHelper::bStringEquals( m_leftoverBuffer,j, "content-transfer-encoding",25 ) )
						{
							m_leftoverBuffer[j++] = ch;
	                        continue;
						}
					}
					if (m_readCR)
						m_leftoverBuffer[j++] = ch;

					type = parseLine(m_leftoverBuffer,j,type,lastLine);
					j=0;
					continue;
				}
				m_leftoverBuffer[j++] = ch;
				if (j == BUFFER_SIZE)
				{
					// over leftoverbuffer is full
					// this shouldn't be a problem if we are in the middle of 
					// reading the data.
					// If we are reading binary data, a line can be larger
					// than 80bytes
					if (m_bStartData)
					{
						type = parseLine(m_leftoverBuffer,j,type,lastLine);
						j=0;
					}
					else
						throw MIMEException("unexpected large input");
				}
			}
		}
	}
	catch (IOException& e)
	{
		// rethrow to a common exception handler
		throw MIMEException(e.getMessage());
	}
	// handle lastline

	// todo dataSink

	if (j != 0)
	{
		type = parseLine(m_leftoverBuffer, j, type, lastLine);
	}
	m_leftoverBytes = j;
	if (m_mimeMessage != NULL)
		checkForEmptyMessages(m_mimeMessage);

	if (m_mimeMessage != NULL)
	{
		decodeDataBuffer();
	}
	// todo 
	// callback stuff
	MIMEMessage* res = m_mimeMessage;
	m_mimeMessage = NULL;
	return res;
}

void MIMEParser::saveBodyData(InputStream* in, MIMEBasicPart* mimeBasicPart)
{
	if (mimeBasicPart == NULL)
		throw MIMEException(MIMEHelper::szERROR_BAD_PARAMETER);

	mimeBasicPart->setBodyData(in,true);
	mimeBasicPart->setDecodedData(true);
}


void MIMEParser::saveBodyData(ByteBuffer* byteBuffer, int len, MIMEBasicPart* mimeBasicPart)
{
	if (byteBuffer == NULL || mimeBasicPart == NULL)
		throw MIMEException(MIMEHelper::szERROR_BAD_PARAMETER);

	if (m_bLocalStorage)
	{
		if (m_bParseEntireFile)
		{
				mimeBasicPart->setBodyData(byteBuffer);
				mimeBasicPart->setMessageDataLen(len);
		}
		else
		{
			ByteBuffer* b = mimeBasicPart->getDataBuf();
			if (b == NULL)
			{
				mimeBasicPart->setBodyData(byteBuffer);
				mimeBasicPart->setMessageDataLen(len);
			}
			else
			{
				b->append(*byteBuffer);
				delete byteBuffer;
				byteBuffer=0;
				mimeBasicPart->setMessageDataLen(mimeBasicPart->getMessageDataLen()+len);
			}
		}
	}
	// todo 
	// if (m_dataSink)
	// else
	mimeBasicPart->setDecodedData(true);
}

void MIMEParser::decodeDataBuffer()
{
	int i;
	int len = 0;
		// bool finished = false;
	mimeInfo mi;
		// MIMEMessagePart* mimeMessagePart = NULL;
	MIMEBasicPart*   mimeBasicPart = NULL;
		// MIMEMultiPart*   mimeMultiPart = NULL;

	ByteBuffer* newBuffer = NULL;
	std::pair<char*,int> decodedBuffer;
//	int param[3];
	bool bDecoded = false;
	int nStart;
	int nEnd;
	decodedBuffer.first = NULL;

	// no decoding

	if (m_nCurrentMessageType != MIMEMessage::BASICPART || m_currentMessage == NULL)
		return;

	mimeBasicPart = (MIMEBasicPart*) m_currentMessage;
	nStart = mimeBasicPart->getStartMessageDataIndex();
	nEnd   = mimeBasicPart->getEndMessageDataIndex();

	if (mimeBasicPart->getDecodedData())
		return;

	// base64
	if (mimeBasicPart->getContentEncoding() == MIMEBodyPart::BASE64 && m_bDecodedData)
	{
		m_ResourceStream->close();
		InputStream* in = m_Resource->getInputStream();
		saveBodyData(in, mimeBasicPart);
		delete m_Resource;
		delete m_ResourceStream;
		m_Resource = NULL;
		m_ResourceStream = NULL;
//		param[0] = m_out_byte;
//		param[1] = m_out_bits;

		/*
		TODO support for BASE64 in ResourceFactory
		BASE64Decoder baseDec;
		ByteArrayInputStream in(m_messageByteData->bytes(),m_messageByteData->size());
		ByteBuffer* byteBuf = baseDec.decodeBuffer(in);
		saveBodyData(byteBuf, byteBuf->size(), mimeBasicPart);
		// reuse bytedata;
		m_messageByteData->setSize(0);
		*/

		bDecoded = true;

	}
	// quoted-printable
	else if (mimeBasicPart->getContentEncoding() == MIMEBodyPart::QP && m_bDecodedData)
	{
		m_ResourceStream->close();
		InputStream* in = m_Resource->getInputStream();
		saveBodyData(in, mimeBasicPart);
		delete m_Resource;
		delete m_ResourceStream;
		m_Resource = NULL;
		m_ResourceStream = NULL;
//		param[0] = m_out_byte;
		/*
		TODO support for QP in ResourceFactory
		QPDecoder qpDec;
		ByteArrayInputStream in(m_messageByteData->bytes(),m_messageByteData->size());
		ByteBuffer* byteBuf = qpDec.decodeBuffer(in);
		saveBodyData(byteBuf, byteBuf->size(), mimeBasicPart);
		*/
		// reuse bytedata;
		bDecoded = true;
	}
	// base64 without decoding
	else if (mimeBasicPart->getContentEncoding() == MIMEBodyPart::BASE64)
	{
		if (nEnd >= nStart && nStart != MIMEBasicPart::UNINITIALIZED)
		{
			// get message size
			for (i = nStart, len = 0; i <= nEnd; i++)
			{
				len = len + m_messageData[i].length() +2; // for crlf
			}
			newBuffer = new ByteBuffer(len);
			if (newBuffer != NULL)
			{
				for (i = nStart;i <= nEnd; i++)
				{
					newBuffer->append(m_messageData[i]);
					newBuffer->append("\r\n",2);
				}
			}
			saveBodyData(newBuffer,len,mimeBasicPart);
		}
	}
	// plain buffer creation
	else
	{
		bool fQP = false;
		if (mimeBasicPart->getContentEncoding() == MIMEBodyPart::QP)
			fQP = true;

		if (nEnd >= nStart && nStart != MIMEBasicPart::UNINITIALIZED)
		{
			m_ResourceStream->removeLast2Bytes();
			m_ResourceStream->close();
			InputStream* in = m_Resource->getInputStream();
			saveBodyData(in, mimeBasicPart);

			/*
			m_messageByteData->setSize(m_messageByteData->size()-2);
			saveBodyData(m_messageByteData,m_messageByteData->size(),mimeBasicPart);
			m_messageByteData = new MIMEByteBuffer();
			*/
			bDecoded = true;
			delete m_ResourceStream;
			delete m_Resource;
			m_Resource = NULL;
			m_ResourceStream = NULL;
		}
	}
	if (bDecoded)
	{
		
		// todo 
		// callback stuff

		//reset
		mimeBasicPart->setStartMessageDataIndex(MIMEBasicPart::UNINITIALIZED);
		mimeBasicPart->setEndMessageDataIndex(MIMEBasicPart::UNINITIALIZED);
	}
}

int MIMEParser::parseLine(char* s, int len, int type, bool lastLine)
{
	int i;
	int type2;
	int nIndex;
	bool finished = false;
	mimeInfo mi;

	MIMEMessagePart* mimeMessagePart = NULL;
	MIMEBasicPart*   mimeBasicPart   = NULL;
	MIMEMultiPart*   mimeMultiPart   = NULL;

	MIMEBodyPart* m = (MIMEBodyPart*) m_currentMessage;

	if (s==NULL)
		throw MIMEException(MIMEHelper::szERROR_BAD_PARAMETER);

	// ignore additional header info

    if ( ( type == MIME_INFO || type == MIME_HEADER || type == MIME_XHEADER )&& ( len > 0 &&( s[0] == '\t' || s[0] == ' ' ) ) )
	{
		if (!(m_nCurrentMessageType == MIMEMessage::BASICPART && m_bStartData == true))
		{
			std::vector<MIMEHeader> h;

			if (typeid(*m_headerParent) == typeid(MIMEBasicPart))
			{
				mimeBasicPart = (MIMEBasicPart*) m_currentMessage;
				mimeBasicPart->addHeader( m_previousHeaderName.c_str(), WString ("\r\n") +  WString(s, len ) );
			}
			else if (typeid(*m_headerParent) == typeid(MIMEMessagePart) )
			{  // Ignore!!

				m_currentMimeMessage->addHeader( m_previousHeaderName.c_str(), WString ("\r\n") +  WString(s, len ) );
			}
			else
			{
				if (m_previousHeaderName.length() == 0) 
				{
					appToLastHdrOnQueue (std::string( s,len)); 
				}
				else
				{
					m_currentMimeMessage->addHeader( m_previousHeaderName.c_str(), WString ("\r\n") +  WString(s, len ) );
				}
			}
			return type;
		}
	}
	/*
	else if (( type == MIME_INFO || type == MIME_HEADER || type == MIME_XHEADER ) ) // && m_dataSink != null) // todo check this
	{
			 // a new header with same name
			 m_previousHeaderName = "";
	 }
	*/

	if ( len == 0 )
	{
		m_emptyLineNo++;
		
		/* end of header callback (only on top level MimeMessage) */
		if (m_emptyLineNo == 1 && m_fEndMessageHeader == false)
		{
			m_fEndMessageHeader = true;
//			if (m_dataSink != null)
//				m_dataSink.endMessageHeader (m_mimeMessage.getUserObject());
		}
	}
	
	if ( len == 0 && !m_bStartData )
	{
		int nCurrentParentType = getCurrentParentType();   
		
		m_readCR = true;
//		if ( m_qp && m_emptyLineNo == 1 )
//			m_readCR = true;
		
//		if (m_binary)
//			m_readCR = true;

		if (m_emptyLineNo >= 2 && !(m_nCurrentMessageType == MIMEMessage::MULTIPART && m_fSeenBoundary==false))
		{
			m_bStartData = true;
		}
		else if (m_emptyLineNo == 1 && nCurrentParentType == MIMEMessage::MULTIPART && m_fSeenBoundary == true)
		{
			if (m_nCurrentMessageType == MIME_UNINITIALIZED)
				m_bStartData = true;               
		}
		else if (m_emptyLineNo > 1 && m_nCurrentMessageType == MIMEMessage::MULTIPART)  
		{
			if (m_fSeenBoundary == true)            
				m_bStartData = true;                    
			else
			{                                               
				mimeMultiPart = (MIMEMultiPart*) m_currentMessage;       
				s[0] = '\r';                                            
				s[1] = '\n';                                            
				mimeMultiPart->addPreamble (s, 2);                       
				return MIME_CRLF;
			}
			
		}                                                          
		
		else if ( m_emptyLineNo == 1 )
		{
			// change mimeMessage parent
			if ( m_nextMimeMessage != NULL )
			{
				// change parent only after first blank line
				m_currentMimeMessage = m_nextMimeMessage;
				m_nextMimeMessage = NULL;
			}
			
			// insert headers from queue
			if ( m_nCurrentMessageType != MIME_UNINITIALIZED && m_headerQueue.size() > 0 )
			{
				if ( m_headerQueue.size() > 0 )
				{
						for ( i = 0; static_cast<unsigned int>(i) < m_headerQueue.size(); i++ )
					{
						mi = (mimeInfo) m_headerQueue[i];
						addHeader( mi.m_name, mi.m_value, false );
					}
					m_headerQueue.clear();
				}
			}
			
			// change header parent
			// todo multipart
			if ( m_nextHeaderParent != NULL && !( typeid(*m_nextHeaderParent) == typeid(MIMEMultiPart)) )
				m_headerParent = m_nextHeaderParent;
		}
	}

	if ( MIMEHelper::bStringEquals( s, len, "content-type",12 ) )
	{
		if (m_emptyLineNo > 0 && m_nCurrentMessageType != MIMEMessage::MESSAGEPART) 
			m_emptyLineNo = 0;                                                      
	}
	
	/* boundary */
	if ( ( type == MIME_INFO || type == MIME_HEADER || type == MIME_XHEADER ) &&
		len == 0 && m_nCurrentMessageType != MIME_UNINITIALIZED && m_messagePartSubType != SUBTYPE_EXTERNAL_BODY )
	{
		if ( m_nCurrentMessageType == MIMEMessage::MESSAGEPART || m_nCurrentMessageType == MIMEMessage::MULTIPART )
		{
			if ( m_emptyLineNo == 1 || m_emptyLineNo == 2 )
				type = MIME_HEADER;
			else
			{
				mi.clear();
				// content type
				mi.m_type = MIME_INFO;
				mi.m_name = "content-type";
				mi.m_value = "text/plain";
				setData( mi );
				parseMimeInfo( mi );
				m_mimeInfo.push_back( mi );
				m_bStartData = true;
				m_fSeenBoundary = false;
				m_Resource = m_Factory->createResource("");
				m_ResourceStream = new LineBufferOutputStream(m_Resource->getOutputStream()); 
			}
		}
		
		else if ( m_nCurrentMessageType == MIMEMessage::BASICPART )
		{
			m_Resource = m_Factory->createResource("");
			m_ResourceStream = new LineBufferOutputStream(m_Resource->getOutputStream()); 

			m_bStartData    = true;
			m_fSeenBoundary = false;
		}
		
		if ( m_emptyLineNo == 1 )
			return type;
	}
	
	if ( !m_bStartData && len == 0 )
	{
		// Add to preamble if multi-part
		if (m_nCurrentMessageType == MIMEMessage::MULTIPART)                 
		{
			m_emptyLineNo = 0;                                      
			mimeMultiPart = (MIMEMultiPart*) m_currentMessage;       
			
			s[0] = '\r';                                            
			s[1] = '\n';                                            
			mimeMultiPart->addPreamble (s, 2);                       
		}
		return MIME_CRLF;
	}
	
	/* -------------------------- identify line ----------------------- */
	type2 = checkForLineType( s, len, m_bStartData );
	
	if (type2 == START_BOUNDARY)
	{
		m_fSeenBoundary = true;
		m_emptyLineNo = 0; 

		if (m_nCurrentMessageType == MIMEMessage::MESSAGEPART && 
			m_messagePartSubType == SUBTYPE_EXTERNAL_BODY)  
			m_bStartData = false;  
	}
	
	// start of simple basicpart message
	if ( type == MIME_CRLF && m_nCurrentMessageType == MIME_UNINITIALIZED && m_lastBoundry == START_BOUNDARY &&
		type2 == MIME_MESSAGE_DATA && ( m_emptyLineNo == 1 || m_emptyLineNo == 2 ) &&
		m_messagePartSubType != SUBTYPE_EXTERNAL_BODY )
	{
		mi.clear();
		
		// content type
		mi.m_type = MIME_INFO;
		mi.m_name = "content-type";
		mi.m_value ="text/plain";
		setData( mi );
		parseMimeInfo( mi );
		m_mimeInfo.push_back( mi );
		m_bStartData = true;
		m_fSeenBoundary = false;
		m_Resource = m_Factory->createResource("");
		m_ResourceStream = new LineBufferOutputStream(m_Resource->getOutputStream()); 

		
		if ( m_emptyLineNo == 1 || m_emptyLineNo == 2 )
		{
			// insert headers from queue
			if ( m_headerQueue.size() > 0 )
			{
				if ( m_nextHeaderParent != NULL )
					m_headerParent = m_nextHeaderParent;
				
					for ( i = 0; static_cast<unsigned int>(i) < m_headerQueue.size(); i++ )
				{
					mi = (mimeInfo) m_headerQueue[i];
					addHeader( mi.m_name, mi.m_value, false );
				}
				m_headerQueue.clear();
			}
			
			// change header parent
			if ( m_nextHeaderParent != NULL)
				m_headerParent = m_nextHeaderParent;
			
			m_emptyLineNo = 0;      // reset for headers
		}
	}
	
	/* start boundary  */
	if ( !m_bStartData && type2 == START_BOUNDARY )
	{
		unwindCurrentParent( s,len, false );
		
		m_out_byte = 0;
		m_out_bits = 0;
		m_leftoverBytes = 0;
		m_QPLeftoverBytes = 0;
		m_emptyLineNo = 0;
		m_nCurrentMessageType = MIME_UNINITIALIZED;
		m_lastBoundry = START_BOUNDARY;
		m_fSeenBoundary = true;
		m_qp = false;
		m_readCR = false;
		m_binary = false;
		m_messagePartSubType = SUBTYPE_RFC822;
		m_nMessageDataIndex = 0;
		return MIME_INFO;
	}
	
	/* end boundary */
	else if ( type2 == END_BOUNDARY || type2 == START_BOUNDARY )
	{
		// todo callback stuff
		
		if ( type2 == END_BOUNDARY )
		{
			unwindCurrentParent( s,len, true );
			m_lastBoundry = END_BOUNDARY;
			m_fSeenBoundary = false;
		}
		else
			m_lastBoundry = START_BOUNDARY;
		
		m_emptyLineNo = 0;
		m_bStartData = false;
		decodeDataBuffer();
		m_nCurrentMessageType = MIME_UNINITIALIZED;
		m_qp = false;
		m_readCR = false;
		m_binary=false;
		m_nMessageDataIndex = 0;
		m_messagePartSubType = SUBTYPE_RFC822;
		return type2;
	}
	
	/* message data    */
	else if ( m_bStartData )
	{
		if (m_nCurrentMessageType == MIME_UNINITIALIZED)        
		{                                                       
			m_Resource = m_Factory->createResource("");
			m_ResourceStream = new LineBufferOutputStream(m_Resource->getOutputStream()); 

			int nCurrentParentType = getCurrentParentType();   
			if (nCurrentParentType == MIMEMessage::MULTIPART)   
			{
				// content type
				mi.m_type = MIME_INFO;                                  
				mi.m_name = "content-type";    
				mi.m_value = "text/plain";     
				setData( mi );                                          
				parseMimeInfo( mi );                                    
				m_mimeInfo.push_back( mi );                            
			}
		}                                                       

		// clone
		//m_messageData.push_back( std::string(s,len) );
		//m_messageByteData->append(s,len);
		m_ResourceStream->write(s,len);
		m_nMessageDataIndex++;
		nIndex = m_nMessageDataIndex-1;

		
		
		if ( m_nCurrentMessageType == MIMEMessage::BASICPART && m_currentMessage != NULL )
		{
			mimeBasicPart = (MIMEBasicPart*) m_currentMessage;
			
			if ( mimeBasicPart->getStartMessageDataIndex() == MIMEBasicPart::UNINITIALIZED )
				mimeBasicPart->setStartMessageDataIndex( nIndex );
			
			mimeBasicPart->setEndMessageDataIndex( nIndex );
			
			if ( lastLine )
			{
				decodeDataBuffer();
				// todo callback				
			}
		}
		return MIME_MESSAGE_DATA;
	}
	
	// add preamble 
	if (m_emptyLineNo> 0 && m_nCurrentMessageType == MIMEMessage::MULTIPART && ! m_fSeenBoundary) 
	{
		mimeMultiPart = (MIMEMultiPart*) m_currentMessage; 
		//s[len] = '\n';                                    
		mimeMultiPart->addPreamble(s, len);            
		return type2;                                     
	}
	
	mi.clear();
	mi.m_type = type2;
	
	bool startQuote = false;
	
	for ( i = 0; i < len && !finished; i++ )
	{
		if ( s[i] == '"' )
			startQuote = startQuote ? false : true;
		
		if ( s[i] == ':' && !startQuote )
		{
			mi.m_name = std::string( s, i );
			
			/* remove junk spaces */
			for ( ++i; i < len && s[i] != 0 && isspace( (char) s[i] ); i++ )
				;
			
			mi.m_value = std::string( s+ i, len - i );
			
			if ( mi.m_type == MIME_INFO )
			{
				setData( mi );
				
				if ( m_messagePartSubType != SUBTYPE_EXTERNAL_BODY )
				{
					parseMimeInfo( mi );
					m_mimeInfo.push_back( mi );
				}
			}
			
			else if ( ( mi.m_type == MIME_XHEADER || mi.m_type == MIME_HEADER ) && m_headerParent != NULL )
			{
				addHeader( mi.m_name, mi.m_value, true );
				m_emptyLineNo = 0;
			}
			
			finished = true;
		}
	}
	
	// add preamble
	if ( !finished && m_nCurrentMessageType == MIMEMessage::MULTIPART )
	{
		m_emptyLineNo = 0; 
		mimeMultiPart = (MIMEMultiPart*) m_currentMessage;
		//s[len] = '\n';
		mimeMultiPart->addPreamble( s);
	}
	
	if ( lastLine )
	{
		decodeDataBuffer();
		//todo callback		
	}
	return type2;
}
 

void MIMEParser::appToLastHdrOnQueue(const std::string& value)
{
      mimeInfo mi;

      int i = m_headerQueue.size();

      if (i > 0)
      {
           mi =  m_headerQueue.back();
           m_headerQueue.pop_back();
		   mi.m_value.append("\r\n");
		   mi.m_value.append(value);
           m_headerQueue.push_back( mi );
      }
}

JDF:: WString getdecodedParam(std::string str)
{
	int idx = str.find_first_of(L'\'');
	std::string charset(str.substr(0,idx));
	int idx2 = str.find_first_of(L'\'',idx+1);
	std::string data = str.substr(idx2+1);
	
	JDF::WString decodedData;
	try
	{
		decodedData.putBytes(data.data(),data.length(),JDF::WString(charset.c_str()));
		std::wstring tmp(decodedData.c_str(),decodedData.length());
	} catch (JDF::IllegalArgumentException&)
	{
		throw JDF::MIMEException (L"bad encoding " + JDF::WString(str.c_str()));
	}
	return decodedData;
	
	return L"";
}
 
 JDF::WString decodeParam(std::string param)
 {
 	JDF::WString res;
 	int pos = param.find("*=");
 	if (pos != -1)
 	{
 		res = param.substr(0,pos).c_str();
 		res += L"=";
 		res += getdecodedParam(param.substr(pos+2));
   	}
   	else 
   		res = param.c_str();
   	return res;
   }

void MIMEParser::addContHeader (MIMEBodyPart* bp, mimeInfo mi)
{
	try
	{
		if (MIMEHelper::bStringEquals(mi.m_name.data(),mi.m_name.length(),"content-description",19))
		{
			bp->setContentDescription (mi.m_value.c_str());
		}
		else if (MIMEHelper::bStringEquals(mi.m_name.data(),mi.m_name.length(),"content-disposition",19))
		{
			int disp = translateDispType (mi.m_value);
			bp->setContentDisposition (disp);
		}
		else if (MIMEHelper::bStringEquals (mi.m_name.data(),mi.m_name.length(), "content-id",10))
		{
			// remove angle brackets , if any
			if ( mi.m_value.length() >= 2 && mi.m_value[0] == '<' && mi.m_value[mi.m_value.length()-1] == '>')
				mi.m_value = mi.m_value.substr(1,mi.m_value.length()-2);
			bp->setContentID (mi.m_value.c_str());
		}
		else if (MIMEHelper::bStringEquals (mi.m_name.data(),mi.m_name.length(), "content-md5",11))
		{
			if (typeid(bp) == typeid(MIMEBasicPart))
				((MIMEBasicPart*)bp)->setContentMD5 (mi.m_value.c_str());
		}
		else if (MIMEHelper::bStringEquals (mi.m_name.data(), mi.m_name.length(), "content-transfer-encoding",25))
		{
			//int encoding = mime_translateMimeEncodingType (mi.m_value);
			//bp->setContentEncoding (encoding);
		}
	}
	catch (Exception&)
	{
		// ignore
	}
}

void MIMEParser::addHeader( const std::string& name, const std::string& value, bool addToQueue ) 
{
	MIMEBasicPart*   mimeBasicPart;
	MIMEMessage*     mimeMessage;
	mimeInfo mi;
	
	if (m_nCurrentMessageType == MIME_UNINITIALIZED && m_headerParent == m_mimeMessage)
	{
		m_mimeMessage->addRHeader( name.c_str(), value.c_str() );
		
		// todo
		// callback stuff
		m_previousHeaderName = name;
		return;
	}
	
	// insert headers from queue, restore header order
	if ( m_nCurrentMessageType != MIME_UNINITIALIZED && addToQueue && m_headerQueue.size() > 0 )
	{
			for ( unsigned int i = 0; i < m_headerQueue.size(); i++ )
		{
			mi = (mimeInfo) m_headerQueue[i];
			addHeader( mi.m_name, mi.m_value, false );
		}
		
		m_headerQueue.clear();
	}
	
	// add to header queue
	if ( m_nCurrentMessageType == MIME_UNINITIALIZED && addToQueue )
	{
		mi.clear();
		mi.m_name = name;
		mi.m_value = value;
		m_headerQueue.push_back( mi );
	}
	
	else if ( typeid(*m_headerParent) == typeid(MIMEMessage) )
	{
		mimeMessage = (MIMEMessage*) m_headerParent;
		mimeMessage->addRHeader( name.c_str(), value.c_str() );
		m_previousHeaderName = name;
	}
	else if ( m_emptyLineNo > 0 || (typeid(*m_headerParent) == typeid(MIMEBasicPart) && m_fSeenBoundary))
	{
		if (typeid(*m_headerParent) ==typeid(MIMEBasicPart) )
		{
			mimeBasicPart = (MIMEBasicPart*) m_headerParent;
			mimeBasicPart->setHeader( name.c_str(), value.c_str() );
			m_previousHeaderName = name;
		}
		else if ( typeid(*m_headerParent) ==typeid(MIMEMessagePart) || typeid(*m_headerParent) ==typeid(MIMEMultiPart) )
		{
			mimeMessage = (MIMEMessage*) m_currentMimeMessage;
			mimeMessage->addRHeader( name.c_str(), value.c_str() );
			m_previousHeaderName = name;
		}
	}
}

void MIMEParser::setData( const mimeInfo& mi ) 
{
	MIMEMessagePart* mimeMessagePart;
	MIMEBasicPart* mimeBasicPart;
	std::vector<std::string> param;
	int contentDisposition;
	MIMEBodyPart* m = (MIMEBodyPart*) m_currentMessage;
	param.reserve(2);
	// make sure we got room for two params
	param.push_back("");
	param.push_back("");
	
	if ( m_messagePartSubType == SUBTYPE_EXTERNAL_BODY && m_nCurrentMessageType == MIMEMessage::MESSAGEPART )
	{
		// add as external body headers
		mimeMessagePart = (MIMEMessagePart*) m_currentMessage;            
		
		if ( m_emptyLineNo >= 1 )                                          
		{                                                                  
			
			mimeMessagePart->setExtBodyHeader (mi.m_name.c_str(), mi.m_value.c_str());    
			m_previousHeaderName =  mi.m_name;                
		}                                                                  
		else                                                               
		{
			addContHeader (mimeMessagePart, mi);                           
		}                                                                  
	}

	/* create message structure */
	else if ( MIMEHelper::bStringEquals(mi.m_name.data(),mi.m_name.length(), "content-type",12 ) )
	{
		newMessageStructure( mi.m_value );
		
		// add from queue
		if ( m_mimeInfoQueue.size() > 0 && m_messagePartSubType != SUBTYPE_EXTERNAL_BODY )
		{
				for ( unsigned int i = 0; i < m_mimeInfoQueue.size(); i++ )
			{
				setData(m_mimeInfoQueue[i] );
			}
			
			m_mimeInfoQueue.clear();
		}
	}
	
	// no structure created yet
	else if ( m_currentMessage == NULL )
		return;
	
	else if ( MIMEHelper::bStringEquals(mi.m_name.data(),mi.m_name.length(), "content-description",19 ) )
	{
		if ( m_nCurrentMessageType == MIME_UNINITIALIZED )
			m_mimeInfoQueue.push_back( mi );
		else
		{
			m->setContentDescription(mi.m_value.c_str());

			// todo callback
		}
	}
	
	else if ( MIMEHelper::bStringEquals(mi.m_name.data(),mi.m_name.length(), "content-disposition",19 ) )
	{
		if ( m_nCurrentMessageType == MIME_UNINITIALIZED )
			m_mimeInfoQueue.push_back(mi);
		else
		{
			contentDisposition = translateDispType( mi.m_value, param );
			
			if ( contentDisposition != NSMAIL_ERR_INVALIDPARAM )
			{
				m->setContentDisposition( contentDisposition );
				
				// todo callback stuff
				if ( param.size() )
				{
					m->setContentDispParams(decodeParam(param[0].c_str()) );
					//todo callback					
				}
			}
		}
	}
	else if ( MIMEHelper::bStringEquals(mi.m_name.data(),mi.m_name.length(), "content-id",10 ) )
	{
		if ( m_nCurrentMessageType == MIME_UNINITIALIZED )
			m_mimeInfoQueue.push_back( mi );
		else
		{
			m->setContentID(mi.m_value.c_str() );
		}
	}
	else if ( MIMEHelper::bStringEquals(mi.m_name.data(),mi.m_name.length(), "content-transfer-encoding",25 ) )
	{
		if ( m_nCurrentMessageType == MIME_UNINITIALIZED )
			m_mimeInfoQueue.push_back( mi );
		else
		{
			if ( typeid(*m_currentMessage) == typeid(MIMEBasicPart) )
			{
				mimeBasicPart = (MIMEBasicPart*) m_currentMessage;
				int encoding;
				
				encoding = mime_translateMimeEncodingType( mi.m_value );
				mimeBasicPart->setContentEncoding( encoding );
				
				if ( encoding == MIMEBodyPart::QP )
					m_qp = true;
			}
			
			else if ( typeid(*m_currentMessage) == typeid(MIMEMessagePart) )
			{
				mimeMessagePart = (MIMEMessagePart*) m_currentMessage;
				int encoding;
				
				encoding = mime_translateMimeEncodingType( mi.m_value );
				mimeMessagePart->setContentEncoding( encoding );
			}
			else if ( typeid(*m_currentMessage) ==typeid(MIMEMultiPart) )
			{
				MIMEMultiPart* mimeMultiPart = (MIMEMultiPart*) m_currentMessage;
				int encoding = mime_translateMimeEncodingType( mi.m_value );
				mimeMultiPart->setContentEncoding( encoding );
			}
		}
	}
	else if ( MIMEHelper::bStringEquals(mi.m_name.data(),mi.m_name.length(), "content-md5",11 ) )	
	{
		if ( m_nCurrentMessageType == MIME_UNINITIALIZED )
			m_mimeInfoQueue.push_back( mi );
		else
		{
			mimeBasicPart = (MIMEBasicPart*) m_currentMessage;
			mimeBasicPart->setContentMD5( mi.m_value.c_str()  );
		}
	}
	else
	{
		if  (m_nCurrentMessageType == MIME_UNINITIALIZED)
			m_mimeInfoQueue.push_back (mi);
		else
		{
			// add unknown tags as header
			addHeader( mi.m_name, mi.m_value, true );
		}
	}
}
	 
void MIMEParser::parseMimeInfo( mimeInfo& mi )
{
	std::string paramName;
	std::string value;
	int offset = 0;
	int len = 0;
	bool beginQuote = false;
	char ch;
	int i;
	int nValueLen;
	
	nValueLen = mi.m_value.length();
	
	/* go through entire line */
	for ( i = 0; i < nValueLen; i++ )
	{
		ch = mi.m_value[i];
		
		/* handle quotes */
		if ( ch == '"' )
			beginQuote = beginQuote ? false : true;
		
		if ( beginQuote )
		{
			len++;
			continue;
		}
		
		/* parse and fill in fields */
		switch ( ch )
		{
		case ';':

			value = mi.m_value.substr(offset,len);
			// trim();
			offset = i + 1;
			mi.m_param.push_back( mimeInfo( MIME_INFO, paramName.data(), value.data() ) );
			value = "";
			paramName = "";
			len = 0;
			break;
			
		case '=':
			paramName = mi.m_value.substr(offset,len);
			// trim();
			offset = i + 1;
			len = 0;
			break;
			
		default:
			len++;
		}
	}
	
	/* add it to internal buffer */
	if ( len > 0 )
	{
		value = mi.m_value.substr(offset,len);
		mi.m_param.push_back( mimeInfo( MIME_INFO, paramName.data(), value.data() ) );
	}
}

const char* MIMEParser::getBytecontType(int nMessageType, int basicPartcontType)
{
	if (nMessageType == MIMEMessage::BASICPART)
	{
		if (basicPartcontType == MIMEBasicPart::TEXT)
			return mb_TextPart;
		else if (basicPartcontType == MIMEBasicPart::AUDIO)
			 return mb_AudioPart;
		else if (basicPartcontType == MIMEBasicPart::VIDEO)
			 return mb_VideoPart;
		else if (basicPartcontType == MIMEBasicPart::IMAGE)
			 return mb_ImagePart;
		else if (basicPartcontType == MIMEBasicPart::APPLICATION)
			 return mb_ApplPart;
	}
	else if (nMessageType == MIMEMessage::MULTIPART)
		 return mb_MultiPart;
	else if (nMessageType == MIMEMessage::MESSAGEPART)
		 return mb_MessagePart;
	return NULL;
}

void MIMEParser::newMessageStructure(const std::string& s )
{
	MIMEMessagePart* mimeMessagePart;
	MIMEBasicPart* mimeBasicPart;
	MIMEMultiPart* mimeMultiPart;
	int nMessageType;
	std::string param[2];
	int contentType;

	nMessageType = nGetMessageType( s, param, contentType );
	
	if (nMessageType == MIMEMessage::BASICPART)
	{
		mimeBasicPart = new MIMEBasicPart();
		
		addMessage( mimeBasicPart, MIMEMessage::BASICPART );
	}
	else if (nMessageType == MIMEMessage::MULTIPART)
	{
		mimeMultiPart = new MIMEMultiPart();
		mimeMultiPart->m_parsedPart=1; 
		addMessage( mimeMultiPart, MIMEMessage::MULTIPART );
		
		// save boundary 
		mimeMultiPart = (MIMEMultiPart*) m_currentMessage;
		WString boundary = parseForBoundary(s.c_str() );
		mimeMultiPart->setBoundary( boundary );
//211102 RP		char* bytes = boundary.getBytes();
	}
	else if (nMessageType == MIMEMessage::MESSAGEPART)
	{
		mimeMessagePart = new MIMEMessagePart();
		
		if ( MIMEHelper::bStringEquals(param[0].data(),param[0].length(), "external-body",13) )
		{
			m_messagePartSubType = SUBTYPE_EXTERNAL_BODY;
		}
		
		// unsupported partial subtype
		else if ( MIMEHelper::bStringEquals(param[0].data(),param[0].length(), "partial",7) )
		{
			throw MIMEException( MIMEHelper::szERROR_UNSUPPORTED_PARTIAL_SUBTYPE );
		}
		
		addMessage( mimeMessagePart, MIMEMessage::MESSAGEPART );
		
		// determine subtype
		if ( MIMEHelper::bStringEquals( param[0].data(),param[0].length(), "rfc822",6 ) )
		{
			m_messagePartSubType = SUBTYPE_RFC822;
			MIMEMessage* m = new MIMEMessage();
			m->m_parsedPart = 1; 
			mimeMessagePart->setMessage( m, false );
			m_nextHeaderParent = m;
			// defered assignment till received first blank line
			m_nextMimeMessage = m;
		}
	}
	
	// initialize structure
	if ( m_currentMessage != NULL )
	{
		MIMEBodyPart* m = (MIMEBodyPart*) m_currentMessage;
		
		if ( param[0].length() )
			m->setContentSubType(param[0].c_str() );
		
		// remove leading CRLF if any
		int offset = 0;
		if (param[1].length())
		{
			while (isspace(param[1][offset]))
				offset++;
		}
		if ( !MIMEHelper::bStringEquals(param[1].data()+offset,param[1].length()-offset,"boundary",8))
		{
			WString cps(param[1].c_str());

			int pos;
			if (!((pos=cps.indexOf("boundary")) > 0))
				m->setContentTypeParams( cps );
			else
			{
				int pos = cps.find_first_of(';');
				m->setContentTypeParams( cps.substring(0,pos-1));
			}
		}
		
		if ( m_nCurrentMessageType == MIMEMessage::BASICPART )
		{
			mimeBasicPart = (MIMEBasicPart*) m_currentMessage;
			mimeBasicPart->setContentType( contentType );
		}
	}
}
 
 
void MIMEParser::addMessage( MIMEComponent* message, int nMessageType )
{
	MIMEMultiPart* multiPart = NULL;
		// MIMEBasicPart* basicPart = NULL;
	MIMEMessagePart* messagePart = NULL;
	
	int nCurrentParentType = getCurrentParentType();
	
	if ( message == NULL )
		throw MIMEException( MIMEHelper::szERROR_BAD_PARAMETER );
	
	// determine current message
	if ( nCurrentParentType == MIMEMessage::BASICPART )
	{
		// can't add messages to a basicpart
		return;
	}
	
	else if ( nCurrentParentType == MIME_UNINITIALIZED )
	{
		if ( nMessageType == MIMEMessage::BASICPART )
		{
			m_mimeMessage->setBody( (MIMEBasicPart*) message, false );
			m_nMessageType = MIMEMessage::BASICPART;
		}
		
		else if ( nMessageType == MIMEMessage::MULTIPART )
		{
			//debug
			//System.out.println( "adding multipart to message" );
			m_mimeMessage->setBody( (MIMEMultiPart*) message, false );
			m_nMessageType = MIMEMessage::MULTIPART;
			m_currentParent.push_back(message);
			m_fSeenBoundary = false;
		}
		
		else if ( nMessageType == MIMEMessage::MESSAGEPART )
		{
			//debug
			//System.out.println( "adding messagepart to message" );
			
			m_mimeMessage->setBody( (MIMEMessagePart*) message, false );
			m_nMessageType = MIMEMessage::MESSAGEPART;
			m_currentParent.push_back( (MIMEMessagePart*) message );
		}
		setCurrentMessage( message, nMessageType );
	}
	
	// add to vector
	else if ( nCurrentParentType == MIMEMessage::MULTIPART && m_currentMessage != NULL )
	{
		multiPart = (MIMEMultiPart*) m_currentParent.back();
		
		if ( nMessageType == MIMEMessage::BASICPART )
		{
			multiPart->addBodyPart( (MIMEBasicPart*) message, false );
		}
		
		else if ( nMessageType == MIMEMessage::MULTIPART )
		{
			multiPart->addBodyPart( (MIMEMultiPart*) message, false );
			m_currentParent.push_back( (MIMEMultiPart*) message );
		}
		
		else if ( nMessageType == MIMEMessage::MESSAGEPART )
		{
			multiPart->addBodyPart( (MIMEMessagePart*) message, false );
			m_currentParent.push_back( (MIMEMessagePart*) message );
		}
		
		setCurrentMessage( message, nMessageType );
	}
	
	else if ( nCurrentParentType == MIMEMessage::MESSAGEPART && m_currentMessage != NULL )
	{
		messagePart = (MIMEMessagePart*) m_currentParent.back();
		
		if ( nMessageType == MIMEMessage::BASICPART )
		{
			messagePart->getMessage( false )->setBody( (MIMEBasicPart*) message, false );
		}
		
		else if ( nMessageType == MIMEMessage::MULTIPART )
		{
			//debug
			//System.out.println( "adding multipart to messagepart" );
			
			messagePart->getMessage( false )->setBody( (MIMEMultiPart*) message, false );
			m_currentParent.push_back( (MIMEMultiPart*) message );
		}
		
		else if ( nMessageType == MIMEMessage::MESSAGEPART )
		{
			//debug
			//System.out.println( "adding messagepart to messagepart" );
			
			messagePart->getMessage( false )->setBody( (MIMEMessagePart*) message, false );
			m_currentParent.push_back( (MIMEMessagePart*) message );
		}
		setCurrentMessage( message, nMessageType );
	}
}
 
  
// helper functions ----------------------------------------
 
int MIMEParser::setCurrentMessage( MIMEComponent* message, int nMessageType )
{
	if ( message == NULL )
		return NSMAIL_ERR_INVALIDPARAM;
	
	m_currentMessage = message;
	m_nCurrentMessageType = nMessageType;
	m_nextHeaderParent = message;
	
	if ( nMessageType == MIMEMessage::BASICPART )
	{
		m_currentBasicPart = (MIMEBasicPart*) message;
		m_currentMultiPart = NULL;
		m_currentMessagePart = NULL;
		
		int nCurrentParentType = getCurrentParentType();
		
		if (nCurrentParentType == MIMEMessage::MULTIPART && m_fSeenBoundary)
		{
			//start following adding headers to this part itself
			m_headerParent = message;
			m_nextHeaderParent = message;
		}
	}
	
	else if ( nMessageType == MIMEMessage::MULTIPART )
	{
		m_currentBasicPart = NULL;
		m_currentMultiPart = (MIMEMultiPart*) message;
		m_currentMessagePart = NULL;
	}
	
	else if ( nMessageType == MIMEMessage::MESSAGEPART )
	{
		m_currentBasicPart = NULL;
		m_currentMultiPart = NULL;
		m_currentMessagePart = (MIMEMessagePart*) message;
	}
	return NSMAIL_OK;
}
 
int MIMEParser::boundaryCheck( char* s, int len )
{
	WString currentBoundary = getCurrentBoundary();
	int boundaryLen = 0;
	
	if (s == NULL)
		return NOT_A_BOUNDARY;

	if ( len > 0 && isspace( (char) s[len-1] ) )
		len--;
	
	if ( len > 0 && isspace( (char) s[len-1] ) )
		len--;
	
	if ( len >= 2 && currentBoundary.length() )
	{
		boundaryLen = currentBoundary.length();

		if ( (len == boundaryLen + 4) &&  s[0] == '-' && s[1] == '-' &&
			s[ boundaryLen + 2 ] == '-' && s[ boundaryLen + 3 ] == '-' 
			&& MIMEHelper::bStringEquals(s+2,len-2,currentBoundary))
		{
			return END_BOUNDARY;
		}
		else if ((len == boundaryLen + 2) && s[0] == '-' && s[1] == '-'
			&& MIMEHelper::bStringEquals(s+2,len-2,currentBoundary))
		{
			return START_BOUNDARY;
		}
	}

	return NOT_A_BOUNDARY;
}


int MIMEParser::checkForLineType( char* s, int len, bool startData )
{
    if ( s == NULL )
		return NSMAIL_ERR_INVALIDPARAM;
	
	if ( startData )
	{
		int type = boundaryCheck(s, len);
		
		if ( type != NOT_A_BOUNDARY )
			return type;
		
		return MIME_HEADER;
	}
	
	else if (MIMEHelper::bStringEquals( s,len, "content-",8 ) )
		return MIME_INFO;
	
	else if ( MIMEHelper::bStringEquals( s, len, "x-",2 ) )
		return MIME_XHEADER;
	
	else if ( len == 0 )
		return MIME_CRLF;
	
	else
	{
		int type = boundaryCheck(s, len);
		
		if ( type != NOT_A_BOUNDARY )
			return type;
		else
		{
			bool seenNonSpace = false;
			
			for ( int i = 0; i < len; i++ )
			{
				if (!isspace ((char) s[i]))
					seenNonSpace = true;
				else if (seenNonSpace && isspace ((char) s[i])) // its not a header! Its MESSAGE_DATA!
				{
					break;
				}
				
				if ( s[i] == ':' )
					return MIME_HEADER;
			}
		}
	}
	
	return MIME_MESSAGE_DATA;
}

 
int MIMEParser::nGetMessageType(const std::string& s, std::string param[], int& contentType )
{
	int i, nStart, nSubtypeStart;
	std::string MessageType;
	int nMessageType = MIME_UNINITIALIZED;
	std::string subtype;
	
	int len = s.length();
	
	/* skip spaces and colons */
	for ( i=0; i < len && s[i] != 0 && (isspace( (char)s[i] ) || s[i] == ':' ); i++ )
		;
	
	/* skip to subtype */
	for ( nStart = i; i < len && s[i] != 0 && s[i] != '/' && s[i] != ';'; i++ )
		;
	
	/* content type */
	MessageType = s.substr(nStart, i - nStart );
	
	/* content subtype */
	if ( i < len && s[i] == '/' )
	{
		for ( nSubtypeStart = ++i; i < len && s[i] != 0 && s[i] != ';' && s[i] != ','; i++ )
			;
		
		/* content subtype */
		subtype = s.substr(nSubtypeStart, i - nSubtypeStart );
	}
	
	param[0] = subtype;
	
	/* skip spaces and colons */
	if ( i < len )
	{
		for ( ; i < len && s[i] != 0 && ( s[i] == ' ' || s[i] == ';'  || s[i] == ',' ); i++ )
			;
	}
	
	param[1] = (i > (int) s.length() ? "" : s.substr( i, s.length()-i )); // trim
	
	/* determine content type */
	if ( MIMEHelper::bStringEquals( (char*)MessageType.data(),MessageType.length(), "text",4 ) )
	{
		nMessageType = MIMEMessage::BASICPART;
		contentType = MIMEBasicPart::TEXT;
	}
	
	else if ( MIMEHelper::bStringEquals( (char*)MessageType.data(),MessageType.length(), "audio",5 ) )
	{
		nMessageType = MIMEMessage::BASICPART;
		contentType = MIMEBasicPart::AUDIO;
	}
	
	else if ( MIMEHelper::bStringEquals( (char*)MessageType.data(),MessageType.length(), "image",5 ) )	
	{
		nMessageType = MIMEMessage::BASICPART;
		contentType = MIMEBasicPart::IMAGE;
	}
	
	else if ( MIMEHelper::bStringEquals( (char*)MessageType.data(),MessageType.length(), "video",5 ) )	
	{
		nMessageType = MIMEMessage::BASICPART;
		contentType = MIMEBasicPart::VIDEO;
	}
	
	else if ( MIMEHelper::bStringEquals( (char*)MessageType.data(),MessageType.length(), "application",11 ) )	
	{
		nMessageType = MIMEMessage::BASICPART;
		contentType = MIMEBasicPart::APPLICATION;
	}
	
	else if ( MIMEHelper::bStringEquals( (char*)MessageType.data(),MessageType.length(), "multipart",9 ) )	
	{
		nMessageType = MIMEMessage::MULTIPART;
		contentType = MIMEBasicPart::TEXT;
	}
	
	else if ( MIMEHelper::bStringEquals( (char*)MessageType.data(),MessageType.length(), "message",7 ) )	
	{
		nMessageType = MIMEMessage::MESSAGEPART;
		contentType= MIMEBasicPart::TEXT;
	}
	
	else
	{
		//nMessageType = MIMEBasicPart.TEXT;
		//contentType[0] = MIMEBasicPart.TEXT;
		throw MIMEException (L"Error: Unknown/Unsupported Content-Type: " + WString (MessageType.c_str()));
	}
	return nMessageType;
}
 
 
 
 
/**
 * Parse an input string for boundary
 * default to "-----" if none is found
 *
 * @param  s input string
 * @return boundary string
 * @exception none
 */
WString MIMEParser::parseForBoundary(const WString& s )
{
	WString boundary;
	int     nLen;
	int     len;
	int     start;
	int     pos;
	bool    bQuotes = false;
	JDFCh   ch;
	
	pos = s.indexOf(JDFStrL("boundary"));

	//pos = s.find_first_of( std::string("boundary")); 
	// does not work only looks at chars in boundary

	len = s.length();
	
	if ( pos == -1 )
		boundary = "-----";
	
	else
	{
		/* skip spaces and colons */
		for ( pos = pos + 9, ch = s[pos];
			 pos < len && ( ch == chSpace || ch == chEqual ); 
			 ch = s[++pos >= len ? 0 : pos] )
			;
		
		if ( ch ==chDoubleQuote )
		{
			bQuotes = true;
			pos++;
		}
		
		start = pos;
		
		for ( nLen = 0, ch = s[pos]; pos < len && ch != chSemiColon; nLen++, ch = s[ ++pos >= len ? 0 : pos] )
		{
			if ( bQuotes && ch == chDoubleQuote )
				break;
		}
		
		boundary = s.substring(start, start + nLen );
	}
	
	return boundary;
}
 
 
 
 
 /**
 * translate encoding type to an integer
 *
 * @param s input string
 * @return encoding type
 * @exception none
 */
int MIMEParser::mime_translateMimeEncodingType(const std::string& s )
{
	if (  MIMEHelper::bStringEquals((char*) s.data(),s.length(), "base64",6 ) )
		return MIMEBodyPart::BASE64;
	
	else if (  MIMEHelper::bStringEquals((char*) s.data(),s.length(), "qp",2 ) || 
			   MIMEHelper::bStringEquals((char*) s.data(),s.length(), "quoted-printable",16 ) )
		return MIMEBodyPart::QP;
	
	else if (  MIMEHelper::bStringEquals((char*) s.data(),s.length(), "7bit",4 ) )
		return MIMEBodyPart::E7BIT;
	
	else if (  MIMEHelper::bStringEquals((char*) s.data(),s.length(), "8bit",4 ) )
		return MIMEBodyPart::E8BIT;
	
	else if (  MIMEHelper::bStringEquals((char*) s.data(),s.length(), "binary",6 ) )
		return MIMEBodyPart::BINARY;
	
	return MIMEBodyPart::E7BIT;
}
 
/**
 * translate disposition type to an integer
 *
 * @author Carson Lee
 * @version %I%, %G%
 *
 * @param  s input string
 * @param param[] return content disposition parameters in param[0]
 * @return <PRE>
 *   NSMAIL_ERR_INVALIDPARAM     if parameters are invalid
 *   MIMEBodyPart.INLINE         disposition type is inline
 *   MIMEBodyPart.ATTACHMENT     disposition type is an attachment</PRE>
 *
* @exception MIMEException
*/

int MIMEParser::translateDispType( const std::string& s, std::vector<std::string>& param)
{
	if ( MIMEHelper::bStringEquals( (char*)s.data(),s.length(), "inline",6 ) )
	{
		if ( s.length() >= 8 )
			param[0]  = s.substr(8 );
		
		return MIMEBodyPart::INLINE;
	}
	else if ( MIMEHelper::bStringEquals( (char*)s.data(),s.length(), "attachment",10 ) )
	{
		if ( s.length() >= 12 )
			param[0] = s.substr(12 );
		
		return MIMEBodyPart::ATTACHMENT;
	}
	else if ( s.length() >= 8 )
		param[0] = s.substr(8 );
	
	return MIMEBodyPart::INLINE;
}
 
// ----------new one 
int MIMEParser::translateDispType (const std::string& s)
{
	if ( MIMEHelper::bStringEquals( (char*)s.data(),s.length(), "inline",6 ) )
		return MIMEBodyPart::INLINE;
	
	if ( MIMEHelper::bStringEquals( (char*)s.data(),s.length(), "attachment",10 ) )
		return MIMEBodyPart::ATTACHMENT;
	
	return MIMEBodyPart::INLINE;
}

int MIMEParser::getCurrentParentType()
{
	if ( m_currentParent.size() > 0 )
	{
		MIMEComponent* o = m_currentParent.back();
		
		if ( o != NULL )
		{
			if ( typeid(*o) == typeid(MIMEBasicPart) )
				return MIMEMessage::BASICPART;

			else if ( typeid(*o) == typeid(MIMEMultiPart) )
				return MIMEMessage::MULTIPART;
			
			else if ( typeid(*o) == typeid(MIMEMessagePart) )
				return MIMEMessage::MESSAGEPART;
		}
	}
	
	return MIME_UNINITIALIZED;
}
 
 
 
 /**
 * get the boundary corresponding to the current multiPart message
 *
 * @param  none
 * @return current boundary string, null if there isn't a current boundary
 * @exception none
 */


WString MIMEParser::getCurrentBoundary()
{
	if ( m_currentParent.size() > 0 )
	{
		for ( int i = m_currentParent.size(); i > 0; i-- )
		{
			MIMEComponent* o = m_currentParent[i - 1];
			
			if ( o != NULL && typeid(*o) == typeid(MIMEMultiPart) )
				return ( (MIMEMultiPart*) o )->getBoundary();
		}
	}
	return "";
}
 
  
 /**
 * get the boundary corresponding to the current multiPart message
 *
 * @author Carson Lee
 * @version %I%, %G%
 *
 * @param  none
 * @return current boundary string, null if there isn't a current boundary
 * @exception none
 */

void MIMEParser::unwindCurrentParent( char* s, int len, bool deleteIt)
{
	
	if ( m_currentParent.size() > 0 )
	{
		WString boundary(s+2, len - 2 );
		
		for ( int i = m_currentParent.size(); i > 0; i-- )
		{
			MIMEComponent* o = m_currentParent[i - 1];
			
			if ( o != NULL && typeid(*o)== typeid(MIMEMultiPart) && boundary.startsWith(((MIMEMultiPart*) o)->getBoundary(),0 ) )
			{
				if ( deleteIt )
				{
					m_currentParent.pop_back();
					
					// reposition to next multipart
					for ( ; m_currentParent.size() > 0; )
					{
						o = m_currentParent.back();
						
						if ( typeid(*o) ==  typeid(MIMEMultiPart) )
							return;
						m_currentParent.pop_back();
					}
				}
				return;
			}
			m_currentParent.pop_back();
		}
	}
}
 
  
void MIMEParser::checkForEmptyMessages( MIMEComponent* o )
{
	if ( o == NULL )
		throw MIMEException( MIMEHelper::szERROR_BAD_PARAMETER );
	
	if ( typeid(*o) == typeid(MIMEMessage ) )
	{
		checkForEmptyMessages( ((MIMEMessage*) o)->getBody(false) );
	}
	
	else if ( typeid(*o) == typeid(MIMEBasicPart) )
	{
		//if ( ((MIMEBasicPart*) o)->getMessageDataLen() == 0 )
		//	throw MIMEException( MIMEHelper::szERROR_EMPTY_MESSAGE );
	}
	else if ( typeid(*o) == typeid(MIMEMultiPart) )
	{
		MIMEMultiPart* m = (MIMEMultiPart*) o;
		int count = m->getBodyPartCount();
		
		for ( int i = 0; i < count; i++ )
		{
			MIMEComponent* part = m->getBodyPart( i, false );
			checkForEmptyMessages( part );
		}
	}
	else if ( typeid(*o) == typeid(MIMEMessagePart) )
	{
		WString cst = (((MIMEMessagePart*)o)->getContentSubType()).second.trim();
		
		if (cst.equalsIgnoreCase("rfc822"))
		{
			MIMEMessage* messagePart = ((MIMEMessagePart*) o)->getMessage();
			checkForEmptyMessages( messagePart );
		}
		else if (cst.equalsIgnoreCase("external-body"))
		{
			std::vector<MIMEHeader> hdrs = ((MIMEMessagePart*)o)->getAllHeaders();
		}
		else if (cst.equalsIgnoreCase("partial"))
		{
			throw MIMEException (MIMEHelper::szERROR_UNSUPPORTED_PARTIAL_SUBTYPE);
		}
		else
			throw MIMEException( MIMEHelper::szERROR_BAD_MIME_MESSAGE);
	}
}
 

} // namespace JDF
